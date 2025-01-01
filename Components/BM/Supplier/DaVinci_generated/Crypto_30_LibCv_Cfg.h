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
 *            Module: Crypto_30_LibCv
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_LibCv_Cfg.h
 *   Generation Time: 2023-07-17 14:11:52
 *           Project: CBD2000614_Bm - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (CRYPTO_30_LIBCV_CFG_H)
#define CRYPTO_30_LIBCV_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0759 EOF */ /* MD_CSL_18.4 */
#include "Csm_Types.h"
#include "vSecPrim.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef CRYPTO_30_LIBCV_USE_DUMMY_STATEMENT
#define CRYPTO_30_LIBCV_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_LIBCV_DUMMY_STATEMENT
#define CRYPTO_30_LIBCV_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_LIBCV_DUMMY_STATEMENT_CONST
#define CRYPTO_30_LIBCV_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_LIBCV_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CRYPTO_30_LIBCV_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CRYPTO_30_LIBCV_ATOMIC_VARIABLE_ACCESS
#define CRYPTO_30_LIBCV_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CRYPTO_30_LIBCV_PROCESSOR_TC322L
#define CRYPTO_30_LIBCV_PROCESSOR_TC322L
#endif
#ifndef CRYPTO_30_LIBCV_COMP_TASKING
#define CRYPTO_30_LIBCV_COMP_TASKING
#endif
#ifndef CRYPTO_30_LIBCV_GEN_GENERATOR_MSR
#define CRYPTO_30_LIBCV_GEN_GENERATOR_MSR
#endif
#ifndef CRYPTO_30_LIBCV_CPUTYPE_BITORDER_LSB2MSB
#define CRYPTO_30_LIBCV_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_PRECOMPILE
#define CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_LINKTIME
#define CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CRYPTO_30_LIBCV_CONFIGURATION_VARIANT
#define CRYPTO_30_LIBCV_CONFIGURATION_VARIANT CRYPTO_30_LIBCV_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CRYPTO_30_LIBCV_POSTBUILD_VARIANT_SUPPORT
#define CRYPTO_30_LIBCV_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Microsar Define Block for Boolean and Integers */
#define CRYPTO_30_LIBCV_VERSION_INFO_API                                                            STD_OFF 
#define CRYPTO_30_LIBCV_USE_VSTD_LIB                                                                STD_ON 
#define CRYPTO_30_LIBCV_KEY_ELEMENT_DELETE                                                          STD_OFF 
#define CRYPTO_30_LIBCV_ALIGN_KEY_STORAGE                                                           STD_OFF 
#define CRYPTO_30_LIBCV_NV_MENABLE_SET_RAM_BLOCK_STATUS                                             STD_OFF 
#define CRYPTO_30_LIBCV_REDIRECTION                                                                 STD_OFF 
#define CRYPTO_30_LIBCV_DEFAULT_RANDOM_MAX_RETRIES                                                  10u 
#define CRYPTO_30_LIBCV_NUMBER_OF_LONG_TERM_PRIMITIVE_WORKSPACE                                     0u 
#define CRYPTO_30_LIBCV_STRICT_LENGTH_CHECK_FOR_KEY_ELEMENT_GET                                     STD_ON 
#define CRYPTO_30_LIBCV_CMAC_AES_ROUNDKEY_REUSE                                                     STD_OFF 
#define CRYPTO_30_LIBCV_ENABLE_AES192                                                               STD_OFF 
#define CRYPTO_30_LIBCV_ENABLE_AES256                                                               STD_OFF 
#define CRYPTO_30_LIBCV_KEY_GENERATE_MAX_LENGTH                                                     32u 
#define CRYPTO_30_LIBCV_SHE_ENABLE_FID                                                              STD_ON 
#define CRYPTO_30_LIBCV_SHE_ENABLE_COUNTER                                                          STD_ON 
#define CRYPTO_30_LIBCV_SHE_DEBUG_CMD                                                               STD_OFF 
#define CRYPTO_30_LIBCV_SHE_KEY_UPDATE                                                              STD_OFF 
#define CRYPTO_30_LIBCV_NV_MANAGEMENT_DATA_PER_KEY                                                  4u 

/* Symbolic Name Define Block */
#define CryptoConf_CryptoDriverObject_Crypto_30_LibCv                                               0u 
#define CryptoConf_CryptoDriverObject_Crypto_30_LibCv_Aes                                           1u 
#define CryptoConf_CryptoDriverObject_Crypto_30_LibCv_Rng                                           2u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Aead_ChaCha_Key                                 1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_Key                                      1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_Key_She                                  1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_Key_She_Ram                              1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key                          1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Fbl_Signature_Ed25519_Key                       1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Hash_Result                                     1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Password                          1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_SharedValue                         1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Key                                 1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Mac_Key                                         1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Mac_Key_She                                     1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Mac_Key_She_Ram                                 1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Signature_Key                                   1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Mac_Proof                                       2u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Seed                                     3u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128            3u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES256            3u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_HASH_SHA2_512     3u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm                                4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1                   4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128       4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF    4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES256       4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES256Df     4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_HASH_SHA2_512 4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Aead_ChaCha_Nonce                               5u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_IV                                       5u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv                           5u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_Proof                                    6u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Cipher_2NDKey                                   7u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Base                                8u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_PrivKey                             9u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_OwnPubKey                           10u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_ANSIP256R1                12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_NISTP224R1_BD             12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1                 12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_SECP384R1                 12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_SECP521R1                 12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_Spake2Plus_Suite8         12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_Spake2Plus_Suite8_1       12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Algorithm_X25519                    12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Salt                              13u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Iterations_HKDF                   14u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Iterations_PBKDF2                 14u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_ASM_NISTFIPS1864        15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA256        15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_Option1_SHA256     15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118                15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_KDF_X963_SHA256         15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_KDF_X963_SHA512         15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_NIST80056A              15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_PBKDF2_HMAC_SHA1        15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_PBKDF2_HMAC_SHA256      15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_SYM_NIST800108          15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Algorithm_Spake2Plus_P256R1       15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerive_Algorithm                             15u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Seed                                16u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Algorithm                           17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Algorithm_Ansi_Nist_Sec_P256R1      17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519                   17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Algorithm_Nist_Sec_P384R1           17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyGenerate_Algorithm_Symmetric_Generic         17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_Label                             130u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_AdditionalInfo                                  131u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyDerivation_AdditionalInfo                    131u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_Modulus                                     160u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_Pub_Exponent                                161u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_Priv_Exponent                               162u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_Salt                                        163u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_SaltLength                                  164u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_PartnerPubKey                       3003u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_PartnerPubKey_2                     3004u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_Intermediate                        3005u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_NumEcu                              3006u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_EcuId                               3007u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_SCC_Contract_PubKey                             3013u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey                    3014u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_PrivateString                            3015u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_AdditionalInput                          3016u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Nonce                                    3017u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Random_Reseed_Counter                           3018u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_She_Counter                                     3019u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_She_UId                                         3021u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_PrimeP                                      3051u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_PrimeQ                                      3052u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_ExponentDp                                  3053u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_ExponentDq                                  3054u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Rsa_InverseQi                                   3055u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_She_BootProtection                              3056u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_She_DebuggerProtection                          3057u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Label                                           3058u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_W0                                              3084u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_W1                                              3085u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_L                                               3086u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Verification                                    3087u 
#define CryptoConf_CryptoKeyElement_Crypto_30_LibCv_Verification_Result                             3088u 
#define CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Ed25519                                        0u 
#define CryptoConf_CryptoKey_CryptoKey_Fbl_Decrypt_Aes128                                           1u 
#define CryptoConf_CryptoKey_CryptoKey_Fbl_Fips186                                                  2u 
#define CryptoConf_CryptoKey_CryptoKey_Fbl_HashDummy                                                3u 

#define CRYPTO_30_LIBCV_NV_PROCESSING_DEFERRED                                                      0x00u 
#define CRYPTO_30_LIBCV_NV_PROCESSING_IMMEDIATE                                                     0x01u 
#define CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_DETECT                                                 0x00u 
#define CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_NONE                                                   0x01u 

#define CRYPTO_30_LIBCV_RAM_KEY_EXPORT                                                              STD_OFF

#define CRYPTO_30_LIBCVPERSIST_SIZE                                                                 0
#ifndef CRYPTO_30_LIBCV_DEV_ERROR_DETECT
#define CRYPTO_30_LIBCV_DEV_ERROR_DETECT STD_ON
#endif
#ifndef CRYPTO_30_LIBCV_DEV_ERROR_REPORT
#define CRYPTO_30_LIBCV_DEV_ERROR_REPORT STD_ON
#endif

/* The following defines keep the max size of the used key elements. */

/* The following defines give an overview which services are used. */
#define CRYPTO_30_LIBCV_SERVICE_AEADDECRYPT                                                         STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_AEADENCRYPT                                                         STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_CERIFICATE_PARSE                                                    STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_CERTIFICATE_VERIFY                                                  STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_DECRYPT                                                             STD_ON
#define CRYPTO_30_LIBCV_SERVICE_ENCRYPT                                                             STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_HASH                                                                STD_ON
#define CRYPTO_30_LIBCV_SERVICE_KEY_DERIVE                                                          STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_KEY_EXCHANGE_CALC_PUBVAL                                            STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_KEY_EXCHANGE_CALC_SECRET                                            STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_KEY_GENERATE                                                        STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_KEY_SET_VALID                                                       STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_MAC_GENERATE                                                        STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_MAC_VERIFY                                                          STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_RANDOM                                                              STD_ON
#define CRYPTO_30_LIBCV_SERVICE_RANDOM_SEED                                                         STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_SIGNATURE_GENERATE                                                  STD_OFF
#define CRYPTO_30_LIBCV_SERVICE_SIGNATURE_VERIFY                                                    STD_ON
/* The following defines are used for key access rights. */
#define CRYPTO_30_LIBCV_RA_ALLOWED                                                                  0x00u
#define CRYPTO_30_LIBCV_RA_ENCRYPTED                                                                0x01u
#define CRYPTO_30_LIBCV_RA_INTERNAL_COPY                                                            0x02u
#define CRYPTO_30_LIBCV_RA_DENIED                                                                   0x03u
#define CRYPTO_30_LIBCV_WA_ALLOWED                                                                  0x00u
#define CRYPTO_30_LIBCV_WA_ENCRYPTED                                                                0x01u
#define CRYPTO_30_LIBCV_WA_INTERNAL_COPY                                                            0x02u
#define CRYPTO_30_LIBCV_WA_DENIED                                                                   0x03u

/* The following defines represent the configuration of CryptoKeyDeriveAlgorithm. */
#define CRYPTO_30_LIBCV_KEY_DERIVE_ALGORITHM                                                        STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_ASYM_NIST_FIPS_186_4_ERB_ENABLED                                   STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_SYM_NIST_800_108_CNT_MODE_SHA256_ENABLED                           STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_ISO_15118_CERTIFICATE_HANDLING_ENABLED                             STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_NIST_800_56_A_ONE_PASS_C1E1S_SINGLE_STEP_KDF_SHA256_ENABLED        STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_X963_SHA256_ENABLED                                                STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_PBKDF2_HMAC_SHA1_ENABLED                                           STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_PBKDF2_HMAC_SHA256_ENABLED                                         STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_X963_SHA512_ENABLED                                                STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_HKDF_HMAC_SHA256_ENABLED                                           STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_SPAKE2_PLUS_P256R1_ENABLED                                         STD_OFF
#define CRYPTO_30_LIBCV_KDF_ALGO_HKDF_OPTION1_SHA256_ENABLED                                        STD_OFF

/* The following defines represent the configuration of CryptoKeyExchangeAlgorithm. */
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM                                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_X25519_ENABLED                                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_ANSIP256R1_ENABLED                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_SECP256R1_ENABLED                                    STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_SECP384R1_ENABLED                                    STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_SPAKE2_PLUS_CIPHERSUITE_8_ENABLED                    STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_NISTP224R1_BD_ENABLED                                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_ALGORITHM_SECP521R1_ENABLED                                    STD_OFF

/* The following defines represent the configuration of CryptoKeyGenerateAlgorithm. */
#define CRYPTO_30_LIBCV_KEY_GENERATE_ALGORITHM                                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ALGORITHM_SYMMETRIC_GENERIC_ENABLED                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ALGORITHM_ANSI_NIST_SEC_P256R1_ENABLED                         STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ALGORITHM_NIST_SEC_P384R1_ENABLED                              STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ALGORITHM_ED25519_ENABLED                                      STD_OFF

#define CRYPTO_30_LIBCV_VSEC_PRIM_ESLT_LENGTH_32                                                    STD_ON

/* The following defines describes the used primitives. They are set together in the following way:
 * (Service | Family | Mode | Second Family) without prefixed CRYPTO_ALOGFAM and CRYPTO_ALGOMODE.
 * So, a configured encryption service with AES in CBC Mode without secondary family results in 
 * CRYPTO_30_LIBCV_ENCRYPT_AES_ECB_NOT_SET.
 */
#define CRYPTO_30_LIBCV_AEADDECRYPT_AES                                                             STD_OFF
#define CRYPTO_30_LIBCV_AEADDECRYPT_AES_CUSTOM_CCM_NOT_SET                                          STD_OFF
#define CRYPTO_30_LIBCV_AEADDECRYPT_AES_GCM_NOT_SET                                                 STD_OFF
#define CRYPTO_30_LIBCV_AEADDECRYPT_CHACHA                                                          STD_OFF
#define CRYPTO_30_LIBCV_AEADDECRYPT_CHACHA_20ROUNDS_CUSTOM_POLY_1305                                STD_OFF
#define CRYPTO_30_LIBCV_AEADDECRYPT_SECFAM_CUSTOM_POLY_1305                                         STD_OFF
#define CRYPTO_30_LIBCV_AEADDECRYPT_SECFAM_NOT_SET                                                  STD_OFF
#define CRYPTO_30_LIBCV_AEADENCRYPT_AES                                                             STD_OFF
#define CRYPTO_30_LIBCV_AEADENCRYPT_AES_CUSTOM_CCM_NOT_SET                                          STD_OFF
#define CRYPTO_30_LIBCV_AEADENCRYPT_AES_GCM_NOT_SET                                                 STD_OFF
#define CRYPTO_30_LIBCV_AEADENCRYPT_CHACHA                                                          STD_OFF
#define CRYPTO_30_LIBCV_AEADENCRYPT_CHACHA_20ROUNDS_CUSTOM_POLY_1305                                STD_OFF
#define CRYPTO_30_LIBCV_AEADENCRYPT_SECFAM_CUSTOM_POLY_1305                                         STD_OFF
#define CRYPTO_30_LIBCV_AEADENCRYPT_SECFAM_NOT_SET                                                  STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_AES                                                                 STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CBC_CUSTOM_PADDING_PKCS7                                        STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CBC_NOT_SET                                                     STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CBC_PADDING_ONEWITHZEROS                                        STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CBC_PADDING_PKCS7                                               STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_AES_CTR_CUSTOM_PADDING_PKCS7                                        STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CTR_NOT_SET                                                     STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CTR_PADDING_ONEWITHZEROS                                        STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_CTR_PADDING_PKCS7                                               STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_AES_ECB_CUSTOM_PADDING_PKCS7                                        STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_ECB_NOT_SET                                                     STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_ECB_PADDING_ONEWITHZEROS                                        STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_AES_ECB_PADDING_PKCS7                                               STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_RSA                                                                 STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_RSA_CUSTOM_RSAES_OAEP_CRT_SHA1                                      STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_RSA_CUSTOM_RSAES_OAEP_CRT_SHA2_256                                  STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_RSA_RSAES_OAEP_SHA1                                                 STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_RSA_RSAES_OAEP_SHA2_256                                             STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_RSA_RSAES_PKCS1_v1_5_NOT_SET                                        STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_SECFAM_CUSTOM_PADDING_PKCS7                                         STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_SECFAM_NOT_SET                                                      STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_SECFAM_PADDING_ONEWITHZEROS                                         STD_ON
#define CRYPTO_30_LIBCV_DECRYPT_SECFAM_PADDING_PKCS7                                                STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_SECFAM_SHA1                                                         STD_OFF
#define CRYPTO_30_LIBCV_DECRYPT_SECFAM_SHA2_256                                                     STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES                                                                 STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CBC_CUSTOM_PADDING_PKCS7                                        STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CBC_NOT_SET                                                     STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CBC_PADDING_ONEWITHZEROS                                        STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CBC_PADDING_PKCS7                                               STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CTR_CUSTOM_PADDING_PKCS7                                        STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CTR_NOT_SET                                                     STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CTR_PADDING_ONEWITHZEROS                                        STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES_CTR_PADDING_PKCS7                                               STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES_ECB_CUSTOM_PADDING_PKCS7                                        STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES_ECB_NOT_SET                                                     STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES_ECB_PADDING_ONEWITHZEROS                                        STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_AES_ECB_PADDING_PKCS7                                               STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_RSA                                                                 STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_RSA_RSAES_OAEP_SHA1                                                 STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_RSA_RSAES_OAEP_SHA2_256                                             STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_RSA_RSAES_PKCS1_v1_5_NOT_SET                                        STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_SECFAM_CUSTOM_PADDING_PKCS7                                         STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_SECFAM_NOT_SET                                                      STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_SECFAM_PADDING_ONEWITHZEROS                                         STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_SECFAM_PADDING_PKCS7                                                STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_SECFAM_SHA1                                                         STD_OFF
#define CRYPTO_30_LIBCV_ENCRYPT_SECFAM_SHA2_256                                                     STD_OFF
#define CRYPTO_30_LIBCV_HASH_CUSTOM_MD5                                                             STD_OFF
#define CRYPTO_30_LIBCV_HASH_CUSTOM_MD5_NOT_SET_NOT_SET                                             STD_OFF
#define CRYPTO_30_LIBCV_HASH_RIPEMD160                                                              STD_OFF
#define CRYPTO_30_LIBCV_HASH_RIPEMD160_NOT_SET_NOT_SET                                              STD_OFF
#define CRYPTO_30_LIBCV_HASH_SECFAM_NOT_SET                                                         STD_ON
#define CRYPTO_30_LIBCV_HASH_SHA1                                                                   STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA1_NOT_SET_NOT_SET                                                   STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA2_256                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA2_256_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA2_384                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA2_384_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA2_512                                                               STD_ON
#define CRYPTO_30_LIBCV_HASH_SHA2_512_NOT_SET_NOT_SET                                               STD_ON
#define CRYPTO_30_LIBCV_HASH_SHA3_224                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_224_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_256                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_256_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_384                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_384_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_512                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHA3_512_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHAKE128                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHAKE128_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHAKE256                                                               STD_OFF
#define CRYPTO_30_LIBCV_HASH_SHAKE256_NOT_SET_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_FIPS186                                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_FIPS186_NOT_SET_SHA2_256                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_HKDF                                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_HKDF_HMAC_SHA2_256                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_HKDF_NOT_SET_SHA2_256                                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_ISO15118                                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_ISO15118_NOT_SET_NOT_SET                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_SPAKE2_PLUS                                               STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_CUSTOM_SPAKE2_PLUS_CUSTOM_P256R1_NOT_SET                         STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_DH                                                               STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_DH_CUSTOM_P256R1_SHA2_256                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_FIPS186                                                          STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_FIPS186_NOT_SET_SHA2_256                                         STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_KDFX963                                                          STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_KDFX963_NOT_SET_SHA2_256                                         STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_KDFX963_NOT_SET_SHA2_512                                         STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_NOT_SET                                                          STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_NOT_SET_CTR_SHA2_256                                             STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_PBKDF2                                                           STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_PBKDF2_HMAC_SHA1                                                 STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_PBKDF2_HMAC_SHA2_256                                             STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_SECFAM_NOT_SET                                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_SECFAM_SHA1                                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_SECFAM_SHA2_256                                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_DERIVE_SECFAM_SHA2_512                                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCANSI                                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET               STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCSEC                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_ECCSEC_CUSTOM_P521R1_NOT_SET                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_SPAKE2_PLUS                                 STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_SPAKE2_PLUS_CUSTOM_MODE_1_CUSTOM_CIPHER_SUITE_8 STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_SPAKE2_PLUS_NOT_SET_CUSTOM_CIPHER_SUITE_8   STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_X25519                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_CUSTOM_X25519_NOT_SET_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCANSI                                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCANSI_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST                                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST_CUSTOM_P224R1_CUSTOM_BD                    STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST_CUSTOM_P384R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCNIST_CUSTOM_P521R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC                                             STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC_CUSTOM_P224R1_CUSTOM_BD                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC_CUSTOM_P256R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC_CUSTOM_P384R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ECCSEC_CUSTOM_P521R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ED25519                                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_ED25519_NOT_SET_NOT_SET                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_SECFAM_CUSTOM_BD                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_SECFAM_CUSTOM_CIPHER_SUITE_8                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_PUBVAL_SECFAM_NOT_SET                                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCANSI                                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET               STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCSEC                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_ECCSEC_CUSTOM_P521R1_NOT_SET                STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_SPAKE2_PLUS                                 STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_SPAKE2_PLUS_CUSTOM_MODE_1_CUSTOM_CIPHER_SUITE_8 STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_SPAKE2_PLUS_NOT_SET_CUSTOM_CIPHER_SUITE_8   STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_X25519                                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_CUSTOM_X25519_NOT_SET_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCANSI                                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCANSI_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCNIST                                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCNIST_CUSTOM_P224R1_CUSTOM_BD                    STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCNIST_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCNIST_CUSTOM_P384R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCNIST_CUSTOM_P521R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCSEC                                             STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCSEC_CUSTOM_P224R1_CUSTOM_BD                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCSEC_CUSTOM_P256R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCSEC_CUSTOM_P384R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_ECCSEC_CUSTOM_P521R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_SECFAM_CUSTOM_BD                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_SECFAM_CUSTOM_CIPHER_SUITE_8                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_EXCHANGE_CALC_SECRET_SECFAM_NOT_SET                                     STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_CUSTOM_ECCANSI                                                 STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET                           STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_CUSTOM_ECCSEC                                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                            STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCANSI                                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCANSI_CUSTOM_P256R1_NOT_SET                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCNIST                                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCNIST_CUSTOM_P256R1_NOT_SET                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCNIST_CUSTOM_P384R1_NOT_SET                                  STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCSEC                                                         STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCSEC_CUSTOM_P256R1_NOT_SET                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ECCSEC_CUSTOM_P384R1_NOT_SET                                   STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ED25519                                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_ED25519_NOT_SET_NOT_SET                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_NOT_SET                                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_NOT_SET_NOT_SET_NOT_SET                                        STD_OFF
#define CRYPTO_30_LIBCV_KEY_GENERATE_SECFAM_NOT_SET                                                 STD_OFF
#define CRYPTO_30_LIBCV_KEY_SET_VALID_NOT_SET                                                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_SET_VALID_NOT_SET_NOT_SET_NOT_SET                                       STD_OFF
#define CRYPTO_30_LIBCV_KEY_SET_VALID_SECFAM_NOT_SET                                                STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_AES                                                            STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_AES_CMAC_CUSTOM_CMD_GET_ID                                     STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_AES_CMAC_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_AES_GMAC_NOT_SET                                               STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_RIPEMD160                                                      STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_RIPEMD160_HMAC_NOT_SET                                         STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SECFAM_CUSTOM_CMD_GET_ID                                       STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SECFAM_NOT_SET                                                 STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA1                                                           STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA1_HMAC_NOT_SET                                              STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA2_256                                                       STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA2_256_HMAC_NOT_SET                                          STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA2_384                                                       STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SHA2_384_HMAC_NOT_SET                                          STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SIPHASH                                                        STD_OFF
#define CRYPTO_30_LIBCV_MAC_GENERATE_SIPHASH_SIPHASH_2_4_NOT_SET                                    STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_AES                                                              STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_AES_CMAC_NOT_SET                                                 STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_AES_GMAC_NOT_SET                                                 STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_RIPEMD160                                                        STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_RIPEMD160_HMAC_NOT_SET                                           STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SECFAM_NOT_SET                                                   STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA1                                                             STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA1_HMAC_NOT_SET                                                STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA2_256                                                         STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA2_256_HMAC_NOT_SET                                            STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA2_384                                                         STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SHA2_384_HMAC_NOT_SET                                            STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SIPHASH                                                          STD_OFF
#define CRYPTO_30_LIBCV_MAC_VERIFY_SIPHASH_SIPHASH_2_4_NOT_SET                                      STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_DRBG                                                          STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_DRBG_CUSTOM_USE_DF_AES                                        STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_DRBG_NOT_SET_AES                                              STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_DRBG_NOT_SET_SHA2_512                                         STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_FIPS186                                                       STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_FIPS186_NOT_SET_NOT_SET                                       STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_CUSTOM_FIPS186_NOT_SET_SHA1                                          STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_DRBG                                                                 STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_DRBG_CUSTOM_USE_DF_AES                                               STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_DRBG_NOT_SET_AES                                                     STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_DRBG_NOT_SET_SHA2_512                                                STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_FIPS186                                                              STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_FIPS186_NOT_SET_NOT_SET                                              STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_FIPS186_NOT_SET_SHA1                                                 STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_RNG                                                                  STD_ON
#define CRYPTO_30_LIBCV_RANDOM_RNG_CUSTOM_USE_DF_AES                                                STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_RNG_NOT_SET_AES                                                      STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_RNG_NOT_SET_NOT_SET                                                  STD_ON
#define CRYPTO_30_LIBCV_RANDOM_RNG_NOT_SET_SHA1                                                     STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SECFAM_AES                                                           STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SECFAM_NOT_SET                                                       STD_ON
#define CRYPTO_30_LIBCV_RANDOM_SECFAM_SHA1                                                          STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SECFAM_SHA2_512                                                      STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_DRBG                                                     STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_DRBG_CUSTOM_USE_DF_AES                                   STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_DRBG_NOT_SET_AES                                         STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_DRBG_NOT_SET_SHA2_512                                    STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_FIPS186                                                  STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_FIPS186_NOT_SET_NOT_SET                                  STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_CUSTOM_FIPS186_NOT_SET_SHA1                                     STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_DRBG                                                            STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_DRBG_CUSTOM_USE_DF_AES                                          STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_DRBG_NOT_SET_AES                                                STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_DRBG_NOT_SET_SHA2_512                                           STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_FIPS186                                                         STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_FIPS186_NOT_SET_NOT_SET                                         STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_FIPS186_NOT_SET_SHA1                                            STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_RNG                                                             STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_RNG_CUSTOM_USE_DF_AES                                           STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_RNG_NOT_SET_AES                                                 STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_RNG_NOT_SET_NOT_SET                                             STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_RNG_NOT_SET_SHA1                                                STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_SECFAM_AES                                                      STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_SECFAM_NOT_SET                                                  STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_SECFAM_SHA1                                                     STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SEED_SECFAM_SHA2_512                                                 STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCANSI                                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA1                        STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_256                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_384                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_512                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC                                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P160R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA1                         STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_256                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_384                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_512                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA1                         STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_256                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_384                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_512                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCANSI                                                  STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_NOT_SET                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_SHA1                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_SHA2_256                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_SHA2_384                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCANSI_CUSTOM_P256R1_SHA2_512                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST                                                  STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_NOT_SET                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_SHA1                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_SHA2_256                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_SHA2_384                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P256R1_SHA2_512                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_NOT_SET                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_SHA1                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_SHA2_256                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_SHA2_384                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P384R1_SHA2_512                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCNIST_CUSTOM_P521R1_SHA2_512                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC                                                   STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P160R1_NOT_SET                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_NOT_SET                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_SHA1                                STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_SHA2_256                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_SHA2_384                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P256R1_SHA2_512                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_NOT_SET                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_SHA1                                STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_SHA2_256                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_SHA2_384                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P384R1_SHA2_512                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ECCSEC_CUSTOM_P521R1_SHA2_512                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ED25519                                                  STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ED25519_NOT_SET_NOT_SET                                  STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_ED25519_NOT_SET_SHA2_512                                 STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA                                                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_CUSTOM_RSASSA_PKCS1_v1_5_CRT_SHA1                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_CUSTOM_RSASSA_PKCS1_v1_5_CRT_SHA2_256                STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_RSASSA_PKCS1_v1_5_SHA1                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_RSASSA_PKCS1_v1_5_SHA2_256                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_RSASSA_PSS_SHA1                                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_RSA_RSASSA_PSS_SHA2_256                                  STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_SECFAM_NOT_SET                                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_SECFAM_SHA1                                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_SECFAM_SHA2_256                                          STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_SECFAM_SHA2_384                                          STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_GENERATE_SECFAM_SHA2_512                                          STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCANSI                                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_NOT_SET                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA1                          STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_256                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_384                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCANSI_CUSTOM_P256R1_SHA2_512                      STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC                                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P160R1_NOT_SET                        STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_NOT_SET                        STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA1                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_256                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_384                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P256R1_SHA2_512                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_NOT_SET                        STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA1                           STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_256                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_384                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_CUSTOM_ECCSEC_CUSTOM_P384R1_SHA2_512                       STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCANSI                                                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_NOT_SET                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_SHA1                                 STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_SHA2_256                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_SHA2_384                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCANSI_CUSTOM_P256R1_SHA2_512                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST                                                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_NOT_SET                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_SHA1                                 STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_SHA2_256                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_SHA2_384                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P256R1_SHA2_512                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_NOT_SET                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_SHA1                                 STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_SHA2_256                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_SHA2_384                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P384R1_SHA2_512                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCNIST_CUSTOM_P521R1_SHA2_512                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC                                                     STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P160R1_NOT_SET                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_NOT_SET                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_SHA1                                  STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_SHA2_256                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_SHA2_384                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P256R1_SHA2_512                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_NOT_SET                               STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_SHA1                                  STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_SHA2_256                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_SHA2_384                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P384R1_SHA2_512                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ECCSEC_CUSTOM_P521R1_SHA2_512                              STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ED25519                                                    STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ED25519_NOT_SET_NOT_SET                                    STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_ED25519_NOT_SET_SHA2_512                                   STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_RSA                                                        STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_RSA_RSASSA_PKCS1_v1_5_SHA1                                 STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_RSA_RSASSA_PKCS1_v1_5_SHA2_256                             STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_RSA_RSASSA_PSS_SHA1                                        STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_RSA_RSASSA_PSS_SHA2_256                                    STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_SECFAM_NOT_SET                                             STD_ON
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_SECFAM_SHA1                                                STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_SECFAM_SHA2_256                                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_SECFAM_SHA2_384                                            STD_OFF
#define CRYPTO_30_LIBCV_SIGNATURE_VERIFY_SECFAM_SHA2_512                                            STD_ON

#define CRYPTO_30_LIBCV_DEFAULT_RANDOM_SOURCE                                                       STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SOURCE_DRBG_AES                                                      STD_OFF
#define CRYPTO_30_LIBCV_RANDOM_SOURCE_DRBG_HASH                                                     STD_OFF


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_LibCvPCDataSwitches  Crypto_30_LibCv Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305DECRYPT                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AEADChaChaPoly1305Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFAEADCHACHAPOLY1305DECRYPT                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AEADChaChaPoly1305Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305ENCRYPT                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AEADChaChaPoly1305Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFAEADCHACHAPOLY1305ENCRYPT                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AEADChaChaPoly1305Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_AESCCMDECRYPT                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesCcmDecrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFAESCCMDECRYPT                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesCcmDecrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_AESCCMENCRYPT                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesCcmEncrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFAESCCMENCRYPT                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesCcmEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_AESDECRYPT                                                                  STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFAESDECRYPT                                                       STD_ON
#define CRYPTO_30_LIBCV_AESENCRYPT                                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesEncrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFAESENCRYPT                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_AESGCMDECRYPT                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesGcmDecrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFAESGCMDECRYPT                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesGcmDecrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_AESGCMENCRYPT                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesGcmEncrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFAESGCMENCRYPT                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_AesGcmEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ALIGNKEYSTORAGEOFGENERAL                                                    STD_ON
#define CRYPTO_30_LIBCV_BUFFERLENGTH                                                                STD_ON
#define CRYPTO_30_LIBCV_CMACAESGENERATE                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_CmacAesGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFCMACAESGENERATE                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_CmacAesGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_CMACAESROUNDKEYREUSEOFMACPRIMITIVES                                         STD_ON
#define CRYPTO_30_LIBCV_CMACAESVERIFY                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_CmacAesVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFCMACAESVERIFY                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_CmacAesVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_DRBGAES                                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_DRBGAES' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFDRBGAES                                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_DRBGAES.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_DRBGHASHSHA512                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_DRBGHashSha512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFDRBGHASHSHA512                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_DRBGHashSha512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_DEFAULTRANDOMMAXRETRIESOFGENERAL                                            STD_ON
#define CRYPTO_30_LIBCV_DRIVEROBJECTSTATE                                                           STD_ON
#define CRYPTO_30_LIBCV_ECP160GENERATE                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP160Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECP160GENERATE                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP160Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ECP160VERIFY                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP160Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECP160VERIFY                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP160Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ECP256GENERATE                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP256Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECP256GENERATE                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP256Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ECP256VERIFY                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP256Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECP256VERIFY                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP256Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ECP384GENERATE                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP384Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECP384GENERATE                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP384Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ECP384VERIFY                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP384Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECP384VERIFY                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP384Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ECP521GENERATE                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP521Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECP521GENERATE                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP521Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ECP521VERIFY                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP521Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFECP521VERIFY                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_EcP521Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ED25519GENERATE                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Ed25519Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFED25519GENERATE                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Ed25519Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_ED25519VERIFY                                                               STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFED25519VERIFY                                                    STD_ON
#define CRYPTO_30_LIBCV_ENABLEAES192OFCIPHERPRIMITIVES                                              STD_ON
#define CRYPTO_30_LIBCV_ENABLEAES256OFCIPHERPRIMITIVES                                              STD_ON
#define CRYPTO_30_LIBCV_EXPECTEDCOMPATIBILITYVERSION                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_LIBCV_FAMILYTOHASHMAPPING                                                         STD_ON
#define CRYPTO_30_LIBCV_FINALMAGICNUMBER                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_LIBCV_FIPS186                                                                     STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFFIPS186                                                          STD_ON
#define CRYPTO_30_LIBCV_GENERATORCOMPATIBILITYVERSION                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_LIBCV_GMACAESGENERATE                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_GmacAesGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFGMACAESGENERATE                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_GmacAesGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_GMACAESVERIFY                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_GmacAesVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFGMACAESVERIFY                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_GmacAesVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_HASH                                                                        STD_ON
#define CRYPTO_30_LIBCV_WORKSPACEOFHASH                                                             STD_ON
#define CRYPTO_30_LIBCV_HMACRIPEMD160GENERATE                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACRIPEMD160GENERATE                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_HMACRIPEMD160VERIFY                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACRIPEMD160VERIFY                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_HMACSHA1GENERATE                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha1Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA1GENERATE                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha1Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_HMACSHA1VERIFY                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha1Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA1VERIFY                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha1Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_HMACSHA256GENERATE                                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha256Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA256GENERATE                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha256Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_HMACSHA256VERIFY                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha256Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA256VERIFY                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha256Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_HMACSHA384GENERATE                                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha384Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA384GENERATE                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha384Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_HMACSHA384VERIFY                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha384Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFHMACSHA384VERIFY                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_HmacSha384Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_INITDATAHASHCODE                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_LIBCV_INITVALUE                                                                   STD_ON
#define CRYPTO_30_LIBCV_KEY                                                                         STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTSENDIDXOFKEY                                                      STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTSSTARTIDXOFKEY                                                    STD_ON
#define CRYPTO_30_LIBCV_NVBLOCKIDXOFKEY                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Key.NvBlockIdx' Reason: 'the optional indirection is deactivated because NvBlockUsedOfKey is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_NVBLOCKUSEDOFKEY                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_Key.NvBlockUsed' Reason: 'the optional indirection is deactivated because NvBlockUsedOfKey is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHMACSHA256                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEHKDFHMACSHA256                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHASHOPTION1                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEHKDFHASHOPTION1                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVEISO15118                                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveISO15118' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEISO15118                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveISO15118.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVEKDF2HMACSHA1                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEKDF2HMACSHA1                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVEKDF2HMACSHA256                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEKDF2HMACSHA256                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVENIST800108CNT                                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist800108Cnt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVENIST800108CNT                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist800108Cnt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVENIST80056AONEPASS                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist80056AOnePass' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVENIST80056AONEPASS                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist80056AOnePass.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVENISTFIPS186ERB                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNistFips186Erb' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVENISTFIPS186ERB                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNistFips186Erb.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVESPAKE2P                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveSpake2P' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVESPAKE2P                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveSpake2P.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVEX963SHA256                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEX963SHA256                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYDERIVEX963SHA512                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYDERIVEX963SHA512                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYELEMENTDELETEOFGENERAL                                                   STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTINFO                                                              STD_ON
#define CRYPTO_30_LIBCV_IDOFKEYELEMENTINFO                                                          STD_ON
#define CRYPTO_30_LIBCV_INITVALUEENDIDXOFKEYELEMENTINFO                                             STD_ON
#define CRYPTO_30_LIBCV_INITVALUESTARTIDXOFKEYELEMENTINFO                                           STD_ON
#define CRYPTO_30_LIBCV_INITVALUEUSEDOFKEYELEMENTINFO                                               STD_ON
#define CRYPTO_30_LIBCV_LENGTHOFKEYELEMENTINFO                                                      STD_ON
#define CRYPTO_30_LIBCV_MASKEDBITSOFKEYELEMENTINFO                                                  STD_ON
#define CRYPTO_30_LIBCV_ONCEOFKEYELEMENTINFO                                                        STD_ON
#define CRYPTO_30_LIBCV_PARTIALOFKEYELEMENTINFO                                                     STD_ON
#define CRYPTO_30_LIBCV_PERSISTOFKEYELEMENTINFO                                                     STD_ON
#define CRYPTO_30_LIBCV_READOFKEYELEMENTINFO                                                        STD_ON
#define CRYPTO_30_LIBCV_WRITEOFKEYELEMENTINFO                                                       STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTS                                                                 STD_ON
#define CRYPTO_30_LIBCV_IDOFKEYELEMENTS                                                             STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTINFOIDXOFKEYELEMENTS                                              STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEENDIDXOFKEYELEMENTS                                               STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEEXTENSIONIDXOFKEYELEMENTS                                         STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGESTARTIDXOFKEYELEMENTS                                             STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEVALIDIDXOFKEYELEMENTS                                             STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEWRITTENLENGTHENDIDXOFKEYELEMENTS                                  STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEWRITTENLENGTHSTARTIDXOFKEYELEMENTS                                STD_ON
#define CRYPTO_30_LIBCV_KEYGENED25519                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenEd25519' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYGENED25519                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenEd25519.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYGENP256R1                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP256R1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYGENP256R1                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP256R1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYGENP384R1                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP384R1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYGENP384R1                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP384R1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYGENSYMGENERIC                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSymGeneric' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYGENSYMGENERIC                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSymGeneric.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYGENERATEMAXLENGTHOFKEYGENERATEPRIMITIVES                                 STD_ON
#define CRYPTO_30_LIBCV_KEYLOCK                                                                     STD_ON
#define CRYPTO_30_LIBCV_KEYP224R1BDPUBVAL                                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDPubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP224R1BDPUBVAL                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP224R1BDSECRET                                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDSecret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP224R1BDSECRET                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP256R1PUBVAL                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP256R1PUBVAL                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP256R1SECRET                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP256R1SECRET                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP384R1PUBVAL                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP384R1PUBVAL                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP384R1SECRET                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP384R1SECRET                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP521R1PUBVAL                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP521R1PUBVAL                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYP521R1SECRET                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYP521R1SECRET                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSEEDDRBGAES                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGAES' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSEEDDRBGAES                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGAES.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSEEDDRBGHASHSHA512                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGHashSha512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSEEDDRBGHASHSHA512                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGHashSha512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSEEDFIPS186                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySeedFips186' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSEEDFIPS186                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySeedFips186.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSETVALID                                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySetValid' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSETVALID                                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySetValid.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSPAKE2PPUBVAL                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PPubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSPAKE2PPUBVAL                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSPAKE2PSECRET                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PSecret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYSPAKE2PSECRET                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSTORAGE                                                                  STD_ON
#define CRYPTO_30_LIBCV_KEYVALIDITYSETCALLOUTFCTNAMEOFCONFIGURABLECALLOUTS                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyValiditySetCalloutFctNameOfConfigurableCallouts' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_LIBCV_KEYVALUECHANGEDCALLOUTFCTNAMEOFCONFIGURABLECALLOUTS                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyValueChangedCalloutFctNameOfConfigurableCallouts' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_LIBCV_KEYX25519PUBVAL                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYX25519PUBVAL                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYX25519SECRET                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFKEYX25519SECRET                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_LASTJOB                                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_LastJob' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define CRYPTO_30_LIBCV_FAMILYOFLASTJOB                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define CRYPTO_30_LIBCV_KEYIDOFLASTJOB                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define CRYPTO_30_LIBCV_MODEOFLASTJOB                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define CRYPTO_30_LIBCV_LOCK                                                                        STD_ON
#define CRYPTO_30_LIBCV_LONGTERMWS                                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_LONGTERMWSLOCK                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_MD5                                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_MD5' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFMD5                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_MD5.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_MAINFUNCTIONPERIODOFGENERAL                                                 STD_ON
#define CRYPTO_30_LIBCV_NUMBEROFLONGTERMPRIMITIVEWORKSPACEOFGENERAL                                 STD_ON
#define CRYPTO_30_LIBCV_NVBLOCK                                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_NvBlock' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_CONSISTENCYLEVELOFNVBLOCK                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.ConsistencyLevel' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_CRCOFNVBLOCK                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Crc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_DESCRIPTOROFNVBLOCK                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Descriptor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_IDOFNVBLOCK                                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSTORAGEENDIDXOFNVBLOCK                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.KeyStorageEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_KEYSTORAGESTARTIDXOFNVBLOCK                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.KeyStorageStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_LENGTHOFNVBLOCK                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_PROCESSINGOFNVBLOCK                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Processing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_NVMENABLESETRAMBLOCKSTATUSOFGENERAL                                         STD_ON
#define CRYPTO_30_LIBCV_NVMANAGEMENTDATAPERKEYOFNVSTORAGE                                           STD_ON
#define CRYPTO_30_LIBCV_NVWRITEBLOCKFCTNAMEOFNVSTORAGE                                              STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFO                                                                  STD_ON
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AEADChaChaPoly1305DecryptIdx' Reason: 'the optional indirection is deactivated because AEADChaChaPoly1305DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305DECRYPTUSEDOFOBJECTINFO                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AEADChaChaPoly1305DecryptUsed' Reason: 'the optional indirection is deactivated because AEADChaChaPoly1305DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AEADChaChaPoly1305EncryptIdx' Reason: 'the optional indirection is deactivated because AEADChaChaPoly1305EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AEADCHACHAPOLY1305ENCRYPTUSEDOFOBJECTINFO                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AEADChaChaPoly1305EncryptUsed' Reason: 'the optional indirection is deactivated because AEADChaChaPoly1305EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESCCMDECRYPTIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmDecryptIdx' Reason: 'the optional indirection is deactivated because AesCcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESCCMDECRYPTUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmDecryptUsed' Reason: 'the optional indirection is deactivated because AesCcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESCCMENCRYPTIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmEncryptIdx' Reason: 'the optional indirection is deactivated because AesCcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESCCMENCRYPTUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmEncryptUsed' Reason: 'the optional indirection is deactivated because AesCcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESDECRYPTIDXOFOBJECTINFO                                                   STD_ON
#define CRYPTO_30_LIBCV_AESDECRYPTUSEDOFOBJECTINFO                                                  STD_ON
#define CRYPTO_30_LIBCV_AESENCRYPTIDXOFOBJECTINFO                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesEncryptIdx' Reason: 'the optional indirection is deactivated because AesEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESENCRYPTUSEDOFOBJECTINFO                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesEncryptUsed' Reason: 'the optional indirection is deactivated because AesEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESGCMDECRYPTIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesGcmDecryptIdx' Reason: 'the optional indirection is deactivated because AesGcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESGCMDECRYPTUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesGcmDecryptUsed' Reason: 'the optional indirection is deactivated because AesGcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESGCMENCRYPTIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesGcmEncryptIdx' Reason: 'the optional indirection is deactivated because AesGcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_AESGCMENCRYPTUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesGcmEncryptUsed' Reason: 'the optional indirection is deactivated because AesGcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_CMACAESGENERATEIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.CmacAesGenerateIdx' Reason: 'the optional indirection is deactivated because CmacAesGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_CMACAESGENERATEUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.CmacAesGenerateUsed' Reason: 'the optional indirection is deactivated because CmacAesGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_CMACAESVERIFYIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.CmacAesVerifyIdx' Reason: 'the optional indirection is deactivated because CmacAesVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_CMACAESVERIFYUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.CmacAesVerifyUsed' Reason: 'the optional indirection is deactivated because CmacAesVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_DRBGAESIDXOFOBJECTINFO                                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGAESIdx' Reason: 'the optional indirection is deactivated because DRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_DRBGAESUSEDOFOBJECTINFO                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGAESUsed' Reason: 'the optional indirection is deactivated because DRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_DRBGHASHSHA512IDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGHashSha512Idx' Reason: 'the optional indirection is deactivated because DRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_DRBGHASHSHA512USEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGHashSha512Used' Reason: 'the optional indirection is deactivated because DRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP160GENERATEIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160GenerateIdx' Reason: 'the optional indirection is deactivated because EcP160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP160GENERATEUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160GenerateUsed' Reason: 'the optional indirection is deactivated because EcP160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP160VERIFYIDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160VerifyIdx' Reason: 'the optional indirection is deactivated because EcP160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP160VERIFYUSEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160VerifyUsed' Reason: 'the optional indirection is deactivated because EcP160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP256GENERATEIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP256GenerateIdx' Reason: 'the optional indirection is deactivated because EcP256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP256GENERATEUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP256GenerateUsed' Reason: 'the optional indirection is deactivated because EcP256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP256VERIFYIDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP256VerifyIdx' Reason: 'the optional indirection is deactivated because EcP256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP256VERIFYUSEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP256VerifyUsed' Reason: 'the optional indirection is deactivated because EcP256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP384GENERATEIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384GenerateIdx' Reason: 'the optional indirection is deactivated because EcP384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP384GENERATEUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384GenerateUsed' Reason: 'the optional indirection is deactivated because EcP384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP384VERIFYIDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384VerifyIdx' Reason: 'the optional indirection is deactivated because EcP384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP384VERIFYUSEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384VerifyUsed' Reason: 'the optional indirection is deactivated because EcP384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP521GENERATEIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP521GenerateIdx' Reason: 'the optional indirection is deactivated because EcP521GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP521GENERATEUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP521GenerateUsed' Reason: 'the optional indirection is deactivated because EcP521GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP521VERIFYIDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP521VerifyIdx' Reason: 'the optional indirection is deactivated because EcP521VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ECP521VERIFYUSEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP521VerifyUsed' Reason: 'the optional indirection is deactivated because EcP521VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ED25519GENERATEIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed25519GenerateIdx' Reason: 'the optional indirection is deactivated because Ed25519GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ED25519GENERATEUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed25519GenerateUsed' Reason: 'the optional indirection is deactivated because Ed25519GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_ED25519VERIFYIDXOFOBJECTINFO                                                STD_ON
#define CRYPTO_30_LIBCV_ED25519VERIFYUSEDOFOBJECTINFO                                               STD_ON
#define CRYPTO_30_LIBCV_FIPS186IDXOFOBJECTINFO                                                      STD_ON
#define CRYPTO_30_LIBCV_FIPS186USEDOFOBJECTINFO                                                     STD_ON
#define CRYPTO_30_LIBCV_GMACAESGENERATEIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.GmacAesGenerateIdx' Reason: 'the optional indirection is deactivated because GmacAesGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_GMACAESGENERATEUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.GmacAesGenerateUsed' Reason: 'the optional indirection is deactivated because GmacAesGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_GMACAESVERIFYIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.GmacAesVerifyIdx' Reason: 'the optional indirection is deactivated because GmacAesVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_GMACAESVERIFYUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.GmacAesVerifyUsed' Reason: 'the optional indirection is deactivated because GmacAesVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HASHIDXOFOBJECTINFO                                                         STD_ON
#define CRYPTO_30_LIBCV_HASHUSEDOFOBJECTINFO                                                        STD_ON
#define CRYPTO_30_LIBCV_HMACRIPEMD160GENERATEIDXOFOBJECTINFO                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160GenerateIdx' Reason: 'the optional indirection is deactivated because HmacRipeMd160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACRIPEMD160GENERATEUSEDOFOBJECTINFO                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160GenerateUsed' Reason: 'the optional indirection is deactivated because HmacRipeMd160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACRIPEMD160VERIFYIDXOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160VerifyIdx' Reason: 'the optional indirection is deactivated because HmacRipeMd160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACRIPEMD160VERIFYUSEDOFOBJECTINFO                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160VerifyUsed' Reason: 'the optional indirection is deactivated because HmacRipeMd160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA1GENERATEIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha1GenerateIdx' Reason: 'the optional indirection is deactivated because HmacSha1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA1GENERATEUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha1GenerateUsed' Reason: 'the optional indirection is deactivated because HmacSha1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA1VERIFYIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha1VerifyIdx' Reason: 'the optional indirection is deactivated because HmacSha1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA1VERIFYUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha1VerifyUsed' Reason: 'the optional indirection is deactivated because HmacSha1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA256GENERATEIDXOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha256GenerateIdx' Reason: 'the optional indirection is deactivated because HmacSha256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA256GENERATEUSEDOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha256GenerateUsed' Reason: 'the optional indirection is deactivated because HmacSha256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA256VERIFYIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha256VerifyIdx' Reason: 'the optional indirection is deactivated because HmacSha256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA256VERIFYUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha256VerifyUsed' Reason: 'the optional indirection is deactivated because HmacSha256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA384GENERATEIDXOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha384GenerateIdx' Reason: 'the optional indirection is deactivated because HmacSha384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA384GENERATEUSEDOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha384GenerateUsed' Reason: 'the optional indirection is deactivated because HmacSha384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA384VERIFYIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha384VerifyIdx' Reason: 'the optional indirection is deactivated because HmacSha384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_HMACSHA384VERIFYUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha384VerifyUsed' Reason: 'the optional indirection is deactivated because HmacSha384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHMACSHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHMACSHA256USEDOFOBJECTINFO                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHMACSHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHASHOPTION1IDXOFOBJECTINFO                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1Idx' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEHKDFHASHOPTION1USEDOFOBJECTINFO                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1Used' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEISO15118IDXOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveISO15118Idx' Reason: 'the optional indirection is deactivated because KeyDeriveISO15118UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEISO15118USEDOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveISO15118Used' Reason: 'the optional indirection is deactivated because KeyDeriveISO15118UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEKDF2HMACSHA1IDXOFOBJECTINFO                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA1Idx' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEKDF2HMACSHA1USEDOFOBJECTINFO                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA1Used' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEKDF2HMACSHA256IDXOFOBJECTINFO                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEKDF2HMACSHA256USEDOFOBJECTINFO                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVENIST800108CNTIDXOFOBJECTINFO                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist800108CntIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNist800108CntUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVENIST800108CNTUSEDOFOBJECTINFO                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist800108CntUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNist800108CntUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVENIST80056AONEPASSIDXOFOBJECTINFO                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist80056AOnePassIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNist80056AOnePassUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVENIST80056AONEPASSUSEDOFOBJECTINFO                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist80056AOnePassUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNist80056AOnePassUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVENISTFIPS186ERBIDXOFOBJECTINFO                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNistFips186ErbIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNistFips186ErbUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVENISTFIPS186ERBUSEDOFOBJECTINFO                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNistFips186ErbUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNistFips186ErbUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVESPAKE2PIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveSpake2PIdx' Reason: 'the optional indirection is deactivated because KeyDeriveSpake2PUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVESPAKE2PUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveSpake2PUsed' Reason: 'the optional indirection is deactivated because KeyDeriveSpake2PUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEX963SHA256IDXOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEX963SHA256USEDOFOBJECTINFO                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEX963SHA512IDXOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA512Idx' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYDERIVEX963SHA512USEDOFOBJECTINFO                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA512Used' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENED25519IDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenEd25519Idx' Reason: 'the optional indirection is deactivated because KeyGenEd25519UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENED25519USEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenEd25519Used' Reason: 'the optional indirection is deactivated because KeyGenEd25519UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENP256R1IDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP256R1Idx' Reason: 'the optional indirection is deactivated because KeyGenP256R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENP256R1USEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP256R1Used' Reason: 'the optional indirection is deactivated because KeyGenP256R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENP384R1IDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP384R1Idx' Reason: 'the optional indirection is deactivated because KeyGenP384R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENP384R1USEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP384R1Used' Reason: 'the optional indirection is deactivated because KeyGenP384R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENSYMGENERICIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSymGenericIdx' Reason: 'the optional indirection is deactivated because KeyGenSymGenericUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYGENSYMGENERICUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSymGenericUsed' Reason: 'the optional indirection is deactivated because KeyGenSymGenericUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP224R1BDPUBVALIDXOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDPubValIdx' Reason: 'the optional indirection is deactivated because KeyP224R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP224R1BDPUBVALUSEDOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDPubValUsed' Reason: 'the optional indirection is deactivated because KeyP224R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP224R1BDSECRETIDXOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDSecretIdx' Reason: 'the optional indirection is deactivated because KeyP224R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP224R1BDSECRETUSEDOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDSecretUsed' Reason: 'the optional indirection is deactivated because KeyP224R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP256R1PUBVALIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP256R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP256R1PUBVALUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP256R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP256R1SECRETIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP256R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP256R1SECRETUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP256R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP384R1PUBVALIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP384R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP384R1PUBVALUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP384R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP384R1SECRETIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP384R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP384R1SECRETUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP384R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP521R1PUBVALIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP521R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP521R1PUBVALUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP521R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP521R1SECRETIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP521R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYP521R1SECRETUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP521R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSEEDDRBGAESIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGAESIdx' Reason: 'the optional indirection is deactivated because KeySeedDRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSEEDDRBGAESUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGAESUsed' Reason: 'the optional indirection is deactivated because KeySeedDRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSEEDDRBGHASHSHA512IDXOFOBJECTINFO                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGHashSha512Idx' Reason: 'the optional indirection is deactivated because KeySeedDRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSEEDDRBGHASHSHA512USEDOFOBJECTINFO                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGHashSha512Used' Reason: 'the optional indirection is deactivated because KeySeedDRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSEEDFIPS186IDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedFips186Idx' Reason: 'the optional indirection is deactivated because KeySeedFips186UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSEEDFIPS186USEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedFips186Used' Reason: 'the optional indirection is deactivated because KeySeedFips186UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSETVALIDIDXOFOBJECTINFO                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetValidIdx' Reason: 'the optional indirection is deactivated because KeySetValidUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSETVALIDUSEDOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetValidUsed' Reason: 'the optional indirection is deactivated because KeySetValidUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSPAKE2PPUBVALIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PPubValIdx' Reason: 'the optional indirection is deactivated because KeySpake2PPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSPAKE2PPUBVALUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PPubValUsed' Reason: 'the optional indirection is deactivated because KeySpake2PPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSPAKE2PSECRETIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PSecretIdx' Reason: 'the optional indirection is deactivated because KeySpake2PSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYSPAKE2PSECRETUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PSecretUsed' Reason: 'the optional indirection is deactivated because KeySpake2PSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYX25519PUBVALIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519PubValIdx' Reason: 'the optional indirection is deactivated because KeyX25519PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYX25519PUBVALUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519PubValUsed' Reason: 'the optional indirection is deactivated because KeyX25519PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYX25519SECRETIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519SecretIdx' Reason: 'the optional indirection is deactivated because KeyX25519SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_KEYX25519SECRETUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519SecretUsed' Reason: 'the optional indirection is deactivated because KeyX25519SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_MD5IDXOFOBJECTINFO                                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.MD5Idx' Reason: 'the optional indirection is deactivated because MD5UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_MD5USEDOFOBJECTINFO                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.MD5Used' Reason: 'the optional indirection is deactivated because MD5UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_QUEUEIDXOFOBJECTINFO                                                        STD_ON
#define CRYPTO_30_LIBCV_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO                                          STD_ON
#define CRYPTO_30_LIBCV_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO                                        STD_ON
#define CRYPTO_30_LIBCV_RANDOMSEEDBUFFERUSEDOFOBJECTINFO                                            STD_ON
#define CRYPTO_30_LIBCV_RSAOAEPCRTSHA1DECRYPTIDXOFOBJECTINFO                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPCRTSHA1DECRYPTUSEDOFOBJECTINFO                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPCRTSHA256DECRYPTIDXOFOBJECTINFO                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha256DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPCRTSHA256DECRYPTUSEDOFOBJECTINFO                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha256DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA1DECRYPTIDXOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA1DECRYPTUSEDOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA1ENCRYPTIDXOFOBJECTINFO                                           STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1EncryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA1ENCRYPTUSEDOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1EncryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA256DECRYPTIDXOFOBJECTINFO                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA256DECRYPTUSEDOFOBJECTINFO                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA256ENCRYPTIDXOFOBJECTINFO                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256EncryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha256EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA256ENCRYPTUSEDOFOBJECTINFO                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256EncryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha256EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1CRTGENERATEIDXOFOBJECTINFO                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1CrtGenerateIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1CrtGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1CRTGENERATEUSEDOFOBJECTINFO                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1CrtGenerateUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1CrtGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1DECRYPTIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1DECRYPTUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1ENCRYPTIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1EncryptIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1ENCRYPTUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1EncryptUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1GENERATEIDXOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1GenerateIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1GENERATEUSEDOFOBJECTINFO                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1GenerateUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1VERIFYIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1VerifyIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPKCS1VERIFYUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1VerifyUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPSSGENERATEIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssGenerateIdx' Reason: 'the optional indirection is deactivated because RsaPssGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPSSGENERATEUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssGenerateUsed' Reason: 'the optional indirection is deactivated because RsaPssGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPSSVERIFYIDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssVerifyIdx' Reason: 'the optional indirection is deactivated because RsaPssVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_RSAPSSVERIFYUSEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssVerifyUsed' Reason: 'the optional indirection is deactivated because RsaPssVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SHECMDGETIDIDXOFOBJECTINFO                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SheCmdGetIdIdx' Reason: 'the optional indirection is deactivated because SheCmdGetIdUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SHECMDGETIDUSEDOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SheCmdGetIdUsed' Reason: 'the optional indirection is deactivated because SheCmdGetIdUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SIPHASHGENERATEIDXOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashGenerateIdx' Reason: 'the optional indirection is deactivated because SipHashGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SIPHASHGENERATEUSEDOFOBJECTINFO                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashGenerateUsed' Reason: 'the optional indirection is deactivated because SipHashGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SIPHASHVERIFYIDXOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashVerifyIdx' Reason: 'the optional indirection is deactivated because SipHashVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_SIPHASHVERIFYUSEDOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashVerifyUsed' Reason: 'the optional indirection is deactivated because SipHashVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_LIBCV_WORKSPACEADDROFOBJECTINFO                                                   STD_ON
#define CRYPTO_30_LIBCV_WORKSPACELENGTHOFOBJECTINFO                                                 STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFOIND                                                               STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEFCT                                                                STD_ON
#define CRYPTO_30_LIBCV_DISPATCHOFPRIMITIVEFCT                                                      STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFOINDENDIDXOFPRIMITIVEFCT                                           STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT                                         STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFOINDUSEDOFPRIMITIVEFCT                                             STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEINFO                                                               STD_ON
#define CRYPTO_30_LIBCV_COMBINEDOFPRIMITIVEINFO                                                     STD_ON
#define CRYPTO_30_LIBCV_CONTEXTOFPRIMITIVEINFO                                                      STD_ON
#define CRYPTO_30_LIBCV_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO                                          STD_ON
#define CRYPTO_30_LIBCV_MASKEDBITSOFPRIMITIVEINFO                                                   STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEFCTIDXOFPRIMITIVEINFO                                              STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVESERVICEINFO                                                        STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO                                   STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO                                 STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEINFOUSEDOFPRIMITIVESERVICEINFO                                     STD_ON
#define CRYPTO_30_LIBCV_QUEUE                                                                       STD_ON
#define CRYPTO_30_LIBCV_RANDOMSEEDBUFFER                                                            STD_ON
#define CRYPTO_30_LIBCV_REDIRECTIONOFGENERAL                                                        STD_ON
#define CRYPTO_30_LIBCV_RSAOAEPCRTSHA1DECRYPT                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha1Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAOAEPCRTSHA1DECRYPT                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAOAEPCRTSHA256DECRYPT                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha256Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAOAEPCRTSHA256DECRYPT                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha256Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA1DECRYPT                                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAOAEPSHA1DECRYPT                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA1ENCRYPT                                                          STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAOAEPSHA1ENCRYPT                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA256DECRYPT                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAOAEPSHA256DECRYPT                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAOAEPSHA256ENCRYPT                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAOAEPSHA256ENCRYPT                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPKCS1CRTGENERATE                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1CrtGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPKCS1CRTGENERATE                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1CrtGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPKCS1DECRYPT                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPKCS1DECRYPT                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPKCS1ENCRYPT                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPKCS1ENCRYPT                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPKCS1GENERATE                                                            STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPKCS1GENERATE                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPKCS1VERIFY                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPKCS1VERIFY                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPSSGENERATE                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPssGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPSSGENERATE                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPssGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_RSAPSSVERIFY                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPssVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFRSAPSSVERIFY                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_RsaPssVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace' Reason: 'Disable Feature if no Context primitive is used' */
#define CRYPTO_30_LIBCV_LENGTHOFSAVEANDRESTOREWORKSPACE                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define CRYPTO_30_LIBCV_SHECMDGETID                                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SheCmdGetId' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFSHECMDGETID                                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SheCmdGetId.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_SHEDEBUGCMDOFSHEKEYUPDATE                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SheDebugCmdOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_LIBCV_SHEENABLECOUNTEROFSHEKEYUPDATE                                              STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SheEnableCounterOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_LIBCV_SHEENABLEFIDOFSHEKEYUPDATE                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SheEnableFidOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_LIBCV_SHEINFOKEYREFOFSHEKEYUPDATE                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SheInfoKeyRefOfSheKeyUpdate' Reason: 'Reference is not configured!' */
#define CRYPTO_30_LIBCV_SHEKEYS                                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SheKeys' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_SIPHASHGENERATE                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SipHashGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFSIPHASHGENERATE                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SipHashGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_SIPHASHVERIFY                                                               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SipHashVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_LIBCV_WORKSPACEOFSIPHASHVERIFY                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_SipHashVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_LIBCV_SIZEOFAESDECRYPT                                                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFBUFFERLENGTH                                                          STD_ON
#define CRYPTO_30_LIBCV_SIZEOFDRIVEROBJECTSTATE                                                     STD_ON
#define CRYPTO_30_LIBCV_SIZEOFED25519VERIFY                                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFFAMILYTOHASHMAPPING                                                   STD_ON
#define CRYPTO_30_LIBCV_SIZEOFFIPS186                                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHASH                                                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFINITVALUE                                                             STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEY                                                                   STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYELEMENTINFO                                                        STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYELEMENTS                                                           STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYLOCK                                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYSTORAGE                                                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFLOCK                                                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFOBJECTINFO                                                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFOBJECTINFOIND                                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPRIMITIVEFCT                                                          STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPRIMITIVEINFO                                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPRIMITIVESERVICEINFO                                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFQUEUE                                                                 STD_ON
#define CRYPTO_30_LIBCV_SIZEOFRANDOMSEEDBUFFER                                                      STD_ON
#define CRYPTO_30_LIBCV_SIZEOFWRITTENLENGTH                                                         STD_ON
#define CRYPTO_30_LIBCV_STRICTLENGTHCHECKFORKEYELEMENTGETOFGENERAL                                  STD_ON
#define CRYPTO_30_LIBCV_UNIONWS_CRYPTO_30_LIBCV                                                     STD_ON
#define CRYPTO_30_LIBCV_UNIONWS_CRYPTO_30_LIBCV_AES                                                 STD_ON
#define CRYPTO_30_LIBCV_UNIONWS_CRYPTO_30_LIBCV_RNG                                                 STD_ON
#define CRYPTO_30_LIBCV_USEVSTDLIBOFGENERAL                                                         STD_ON
#define CRYPTO_30_LIBCV_VERSIONINFOAPIOFGENERAL                                                     STD_ON
#define CRYPTO_30_LIBCV_WATCHDOGTRIGGERFUNCTIONOFGENERAL                                            STD_ON
#define CRYPTO_30_LIBCV_WRITTENLENGTH                                                               STD_ON
#define CRYPTO_30_LIBCV_PCCONFIG                                                                    STD_ON
#define CRYPTO_30_LIBCV_AESDECRYPTOFPCCONFIG                                                        STD_ON
#define CRYPTO_30_LIBCV_ALIGNKEYSTORAGEOFGENERALOFPCCONFIG                                          STD_ON
#define CRYPTO_30_LIBCV_BUFFERLENGTHOFPCCONFIG                                                      STD_ON
#define CRYPTO_30_LIBCV_CMACAESROUNDKEYREUSEOFMACPRIMITIVESOFPCCONFIG                               STD_ON
#define CRYPTO_30_LIBCV_DEFAULTRANDOMMAXRETRIESOFGENERALOFPCCONFIG                                  STD_ON
#define CRYPTO_30_LIBCV_DRIVEROBJECTSTATEOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_LIBCV_ED25519VERIFYOFPCCONFIG                                                     STD_ON
#define CRYPTO_30_LIBCV_ENABLEAES192OFCIPHERPRIMITIVESOFPCCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_ENABLEAES256OFCIPHERPRIMITIVESOFPCCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                      STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_LIBCV_FAMILYTOHASHMAPPINGOFPCCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_FINALMAGICNUMBEROFPCCONFIG                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_LIBCV_FIPS186OFPCCONFIG                                                           STD_ON
#define CRYPTO_30_LIBCV_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                     STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_LIBCV_HASHOFPCCONFIG                                                              STD_ON
#define CRYPTO_30_LIBCV_INITDATAHASHCODEOFPCCONFIG                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_LIBCV_INITVALUEOFPCCONFIG                                                         STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTDELETEOFGENERALOFPCCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTINFOOFPCCONFIG                                                    STD_ON
#define CRYPTO_30_LIBCV_KEYELEMENTSOFPCCONFIG                                                       STD_ON
#define CRYPTO_30_LIBCV_KEYGENERATEMAXLENGTHOFKEYGENERATEPRIMITIVESOFPCCONFIG                       STD_ON
#define CRYPTO_30_LIBCV_KEYLOCKOFPCCONFIG                                                           STD_ON
#define CRYPTO_30_LIBCV_KEYOFPCCONFIG                                                               STD_ON
#define CRYPTO_30_LIBCV_KEYSTORAGEOFPCCONFIG                                                        STD_ON
#define CRYPTO_30_LIBCV_KEYVALIDITYSETCALLOUTFCTNAMEOFCONFIGURABLECALLOUTSOFPCCONFIG                STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.KeyValiditySetCalloutFctNameOfConfigurableCallouts' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_LIBCV_KEYVALUECHANGEDCALLOUTFCTNAMEOFCONFIGURABLECALLOUTSOFPCCONFIG               STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.KeyValueChangedCalloutFctNameOfConfigurableCallouts' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_LIBCV_LOCKOFPCCONFIG                                                              STD_ON
#define CRYPTO_30_LIBCV_MAINFUNCTIONPERIODOFGENERALOFPCCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_NUMBEROFLONGTERMPRIMITIVEWORKSPACEOFGENERALOFPCCONFIG                       STD_ON
#define CRYPTO_30_LIBCV_NVMENABLESETRAMBLOCKSTATUSOFGENERALOFPCCONFIG                               STD_ON
#define CRYPTO_30_LIBCV_NVMANAGEMENTDATAPERKEYOFNVSTORAGEOFPCCONFIG                                 STD_ON
#define CRYPTO_30_LIBCV_NVWRITEBLOCKFCTNAMEOFNVSTORAGEOFPCCONFIG                                    STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFOINDOFPCCONFIG                                                     STD_ON
#define CRYPTO_30_LIBCV_OBJECTINFOOFPCCONFIG                                                        STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEFCTOFPCCONFIG                                                      STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVEINFOOFPCCONFIG                                                     STD_ON
#define CRYPTO_30_LIBCV_PRIMITIVESERVICEINFOOFPCCONFIG                                              STD_ON
#define CRYPTO_30_LIBCV_QUEUEOFPCCONFIG                                                             STD_ON
#define CRYPTO_30_LIBCV_RANDOMSEEDBUFFEROFPCCONFIG                                                  STD_ON
#define CRYPTO_30_LIBCV_REDIRECTIONOFGENERALOFPCCONFIG                                              STD_ON
#define CRYPTO_30_LIBCV_SHEDEBUGCMDOFSHEKEYUPDATEOFPCCONFIG                                         STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.SheDebugCmdOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_LIBCV_SHEENABLECOUNTEROFSHEKEYUPDATEOFPCCONFIG                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.SheEnableCounterOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_LIBCV_SHEENABLEFIDOFSHEKEYUPDATEOFPCCONFIG                                        STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.SheEnableFidOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_LIBCV_SHEINFOKEYREFOFSHEKEYUPDATEOFPCCONFIG                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.SheInfoKeyRefOfSheKeyUpdate' Reason: 'Reference is not configured!' */
#define CRYPTO_30_LIBCV_SIZEOFAESDECRYPTOFPCCONFIG                                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFBUFFERLENGTHOFPCCONFIG                                                STD_ON
#define CRYPTO_30_LIBCV_SIZEOFDRIVEROBJECTSTATEOFPCCONFIG                                           STD_ON
#define CRYPTO_30_LIBCV_SIZEOFED25519VERIFYOFPCCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFFAMILYTOHASHMAPPINGOFPCCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFFIPS186OFPCCONFIG                                                     STD_ON
#define CRYPTO_30_LIBCV_SIZEOFHASHOFPCCONFIG                                                        STD_ON
#define CRYPTO_30_LIBCV_SIZEOFINITVALUEOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYELEMENTINFOOFPCCONFIG                                              STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYELEMENTSOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYLOCKOFPCCONFIG                                                     STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYOFPCCONFIG                                                         STD_ON
#define CRYPTO_30_LIBCV_SIZEOFKEYSTORAGEOFPCCONFIG                                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFLOCKOFPCCONFIG                                                        STD_ON
#define CRYPTO_30_LIBCV_SIZEOFOBJECTINFOINDOFPCCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFOBJECTINFOOFPCCONFIG                                                  STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPRIMITIVEFCTOFPCCONFIG                                                STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPRIMITIVEINFOOFPCCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_SIZEOFPRIMITIVESERVICEINFOOFPCCONFIG                                        STD_ON
#define CRYPTO_30_LIBCV_SIZEOFQUEUEOFPCCONFIG                                                       STD_ON
#define CRYPTO_30_LIBCV_SIZEOFRANDOMSEEDBUFFEROFPCCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_SIZEOFWRITTENLENGTHOFPCCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_STRICTLENGTHCHECKFORKEYELEMENTGETOFGENERALOFPCCONFIG                        STD_ON
#define CRYPTO_30_LIBCV_UNIONWS_CRYPTO_30_LIBCVOFPCCONFIG                                           STD_ON
#define CRYPTO_30_LIBCV_UNIONWS_CRYPTO_30_LIBCV_AESOFPCCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_UNIONWS_CRYPTO_30_LIBCV_RNGOFPCCONFIG                                       STD_ON
#define CRYPTO_30_LIBCV_USEVSTDLIBOFGENERALOFPCCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_VERSIONINFOAPIOFGENERALOFPCCONFIG                                           STD_ON
#define CRYPTO_30_LIBCV_WATCHDOGTRIGGERFUNCTIONOFGENERALOFPCCONFIG                                  STD_ON
#define CRYPTO_30_LIBCV_WRITTENLENGTHOFPCCONFIG                                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCMinNumericValueDefines  Crypto_30_LibCv Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CRYPTO_30_LIBCV_MIN_BUFFERLENGTH                                                            0u
#define CRYPTO_30_LIBCV_MIN_DRIVEROBJECTSTATE                                                       0u
#define CRYPTO_30_LIBCV_MIN_KEYLOCK                                                                 0u
#define CRYPTO_30_LIBCV_MIN_KEYSTORAGE                                                              0u
#define CRYPTO_30_LIBCV_MIN_KEYIDOFLASTJOB                                                          0u
#define CRYPTO_30_LIBCV_MIN_LOCK                                                                    0u
#define CRYPTO_30_LIBCV_MIN_LONGTERMWSLOCK                                                          0u
#define CRYPTO_30_LIBCV_MIN_RANDOMSEEDBUFFER                                                        0u
#define CRYPTO_30_LIBCV_MIN_LENGTHOFSAVEANDRESTOREWORKSPACE                                         0u
#define CRYPTO_30_LIBCV_MIN_WRITTENLENGTH                                                           0u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCMaxNumericValueDefines  Crypto_30_LibCv Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CRYPTO_30_LIBCV_MAX_BUFFERLENGTH                                                            4294967295u
#define CRYPTO_30_LIBCV_MAX_DRIVEROBJECTSTATE                                                       255u
#define CRYPTO_30_LIBCV_MAX_KEYLOCK                                                                 255u
#define CRYPTO_30_LIBCV_MAX_KEYSTORAGE                                                              255u
#define CRYPTO_30_LIBCV_MAX_KEYIDOFLASTJOB                                                          4294967295u
#define CRYPTO_30_LIBCV_MAX_LOCK                                                                    4294967295u
#define CRYPTO_30_LIBCV_MAX_LONGTERMWSLOCK                                                          4294967295u
#define CRYPTO_30_LIBCV_MAX_RANDOMSEEDBUFFER                                                        255u
#define CRYPTO_30_LIBCV_MAX_LENGTHOFSAVEANDRESTOREWORKSPACE                                         4294967295u
#define CRYPTO_30_LIBCV_MAX_WRITTENLENGTH                                                           4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCNoReferenceDefines  Crypto_30_LibCv No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CRYPTO_30_LIBCV_NO_INITVALUE                                                                255u
#define CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY                                                          255u
#define CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO                                        255u
#define CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO                                 255u
#define CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO                                 255u
#define CRYPTO_30_LIBCV_NO_AESCCMDECRYPTIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_AESCCMENCRYPTIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO                                                255u
#define CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO                                                255u
#define CRYPTO_30_LIBCV_NO_AESGCMDECRYPTIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_AESGCMENCRYPTIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO                                                   255u
#define CRYPTO_30_LIBCV_NO_DRBGHASHSHA512IDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_ECP160GENERATEIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_ECP160VERIFYIDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_ECP256GENERATEIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_ECP256VERIFYIDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_ECP384GENERATEIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_ECP384VERIFYIDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_ECP521GENERATEIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_ECP521VERIFYIDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO                                                   255u
#define CRYPTO_30_LIBCV_NO_GMACAESGENERATEIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_GMACAESVERIFYIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_HASHIDXOFOBJECTINFO                                                      255u
#define CRYPTO_30_LIBCV_NO_HMACRIPEMD160GENERATEIDXOFOBJECTINFO                                     255u
#define CRYPTO_30_LIBCV_NO_HMACRIPEMD160VERIFYIDXOFOBJECTINFO                                       255u
#define CRYPTO_30_LIBCV_NO_HMACSHA1GENERATEIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_HMACSHA1VERIFYIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_HMACSHA256GENERATEIDXOFOBJECTINFO                                        255u
#define CRYPTO_30_LIBCV_NO_HMACSHA256VERIFYIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_HMACSHA384GENERATEIDXOFOBJECTINFO                                        255u
#define CRYPTO_30_LIBCV_NO_HMACSHA384VERIFYIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO                                   255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHASHOPTION1IDXOFOBJECTINFO                                  255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118IDXOFOBJECTINFO                                         255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEKDF2HMACSHA1IDXOFOBJECTINFO                                     255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEKDF2HMACSHA256IDXOFOBJECTINFO                                   255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVENIST800108CNTIDXOFOBJECTINFO                                    255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVENIST80056AONEPASSIDXOFOBJECTINFO                                255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVENISTFIPS186ERBIDXOFOBJECTINFO                                   255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVESPAKE2PIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEX963SHA256IDXOFOBJECTINFO                                       255u
#define CRYPTO_30_LIBCV_NO_KEYDERIVEX963SHA512IDXOFOBJECTINFO                                       255u
#define CRYPTO_30_LIBCV_NO_KEYGENED25519IDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_KEYGENP256R1IDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_KEYGENP384R1IDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_KEYGENSYMGENERICIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_KEYP224R1BDPUBVALIDXOFOBJECTINFO                                         255u
#define CRYPTO_30_LIBCV_NO_KEYP224R1BDSECRETIDXOFOBJECTINFO                                         255u
#define CRYPTO_30_LIBCV_NO_KEYP256R1PUBVALIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYP256R1SECRETIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYP384R1PUBVALIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYP384R1SECRETIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYP521R1PUBVALIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYP521R1SECRETIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYSEEDDRBGAESIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_KEYSEEDDRBGHASHSHA512IDXOFOBJECTINFO                                     255u
#define CRYPTO_30_LIBCV_NO_KEYSEEDFIPS186IDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_KEYSETVALIDIDXOFOBJECTINFO                                               255u
#define CRYPTO_30_LIBCV_NO_KEYSPAKE2PPUBVALIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_KEYSPAKE2PSECRETIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_KEYX25519PUBVALIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_KEYX25519SECRETIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_MD5IDXOFOBJECTINFO                                                       255u
#define CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO                                       255u
#define CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO                                     255u
#define CRYPTO_30_LIBCV_NO_RSAOAEPCRTSHA1DECRYPTIDXOFOBJECTINFO                                     255u
#define CRYPTO_30_LIBCV_NO_RSAOAEPCRTSHA256DECRYPTIDXOFOBJECTINFO                                   255u
#define CRYPTO_30_LIBCV_NO_RSAOAEPSHA1DECRYPTIDXOFOBJECTINFO                                        255u
#define CRYPTO_30_LIBCV_NO_RSAOAEPSHA1ENCRYPTIDXOFOBJECTINFO                                        255u
#define CRYPTO_30_LIBCV_NO_RSAOAEPSHA256DECRYPTIDXOFOBJECTINFO                                      255u
#define CRYPTO_30_LIBCV_NO_RSAOAEPSHA256ENCRYPTIDXOFOBJECTINFO                                      255u
#define CRYPTO_30_LIBCV_NO_RSAPKCS1CRTGENERATEIDXOFOBJECTINFO                                       255u
#define CRYPTO_30_LIBCV_NO_RSAPKCS1DECRYPTIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_RSAPKCS1ENCRYPTIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_RSAPKCS1GENERATEIDXOFOBJECTINFO                                          255u
#define CRYPTO_30_LIBCV_NO_RSAPKCS1VERIFYIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_RSAPSSGENERATEIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_LIBCV_NO_RSAPSSVERIFYIDXOFOBJECTINFO                                              255u
#define CRYPTO_30_LIBCV_NO_SHECMDGETIDIDXOFOBJECTINFO                                               255u
#define CRYPTO_30_LIBCV_NO_SIPHASHGENERATEIDXOFOBJECTINFO                                           255u
#define CRYPTO_30_LIBCV_NO_SIPHASHVERIFYIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_LIBCV_NO_OBJECTINFOINDENDIDXOFPRIMITIVEFCT                                        255u
#define CRYPTO_30_LIBCV_NO_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT                                      255u
#define CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO                                255u
#define CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO                              255u
#define CRYPTO_30_LIBCV_NO_EXPECTEDCOMPATIBILITYVERSION                                             65535u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCMaskedBitDefines  Crypto_30_LibCv Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define CRYPTO_30_LIBCV_ONCEOFKEYELEMENTINFO_MASK                                                   0x04u
#define CRYPTO_30_LIBCV_PARTIALOFKEYELEMENTINFO_MASK                                                0x02u
#define CRYPTO_30_LIBCV_PERSISTOFKEYELEMENTINFO_MASK                                                0x01u
#define CRYPTO_30_LIBCV_CONTEXTOFPRIMITIVEINFO_MASK                                                 0x02u
#define CRYPTO_30_LIBCV_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO_MASK                                     0x01u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCIsReducedToDefineDefines  Crypto_30_LibCv Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAEADCHACHAPOLY1305DECRYPT                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAEADCHACHAPOLY1305ENCRYPT                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAESCCMDECRYPT                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAESCCMENCRYPT                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAESDECRYPT                                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAESENCRYPT                                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAESGCMDECRYPT                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFAESGCMENCRYPT                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFCMACAESGENERATE                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFCMACAESVERIFY                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFDRBGAES                                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFDRBGHASHSHA512                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP160GENERATE                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP160VERIFY                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP256GENERATE                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP256VERIFY                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP384GENERATE                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP384VERIFY                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP521GENERATE                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFECP521VERIFY                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFED25519GENERATE                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFED25519VERIFY                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_FAMILYTOHASHMAPPING                                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFFIPS186                                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFGMACAESGENERATE                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFGMACAESVERIFY                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHASH                                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACRIPEMD160GENERATE                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACRIPEMD160VERIFY                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA1GENERATE                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA1VERIFY                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA256GENERATE                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA256VERIFY                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA384GENERATE                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFHMACSHA384VERIFY                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_INITVALUE                                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYELEMENTSENDIDXOFKEY                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYELEMENTSSTARTIDXOFKEY                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_NVBLOCKIDXOFKEY                                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_NVBLOCKUSEDOFKEY                                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEHKDFHMACSHA256                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEHKDFHASHOPTION1                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEISO15118                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEKDF2HMACSHA1                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEKDF2HMACSHA256                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVENIST800108CNT                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVENIST80056AONEPASS                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVENISTFIPS186ERB                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVESPAKE2P                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEX963SHA256                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYDERIVEX963SHA512                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_IDOFKEYELEMENTINFO                                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_INITVALUEENDIDXOFKEYELEMENTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_INITVALUESTARTIDXOFKEYELEMENTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_INITVALUEUSEDOFKEYELEMENTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_LENGTHOFKEYELEMENTINFO                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_MASKEDBITSOFKEYELEMENTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ONCEOFKEYELEMENTINFO                                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PARTIALOFKEYELEMENTINFO                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PERSISTOFKEYELEMENTINFO                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_READOFKEYELEMENTINFO                                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WRITEOFKEYELEMENTINFO                                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_IDOFKEYELEMENTS                                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYELEMENTINFOIDXOFKEYELEMENTS                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEENDIDXOFKEYELEMENTS                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEEXTENSIONIDXOFKEYELEMENTS                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGESTARTIDXOFKEYELEMENTS                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEVALIDIDXOFKEYELEMENTS                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEWRITTENLENGTHENDIDXOFKEYELEMENTS                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEWRITTENLENGTHSTARTIDXOFKEYELEMENTS                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYGENED25519                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYGENP256R1                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYGENP384R1                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYGENSYMGENERIC                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP224R1BDPUBVAL                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP224R1BDSECRET                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP256R1PUBVAL                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP256R1SECRET                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP384R1PUBVAL                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP384R1SECRET                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP521R1PUBVAL                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYP521R1SECRET                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSEEDDRBGAES                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSEEDDRBGHASHSHA512                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSEEDFIPS186                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSETVALID                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSPAKE2PPUBVAL                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYSPAKE2PSECRET                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYX25519PUBVAL                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFKEYX25519SECRET                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFMD5                                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CONSISTENCYLEVELOFNVBLOCK                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CRCOFNVBLOCK                                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DESCRIPTOROFNVBLOCK                                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_IDOFNVBLOCK                                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEENDIDXOFNVBLOCK                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGESTARTIDXOFNVBLOCK                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_LENGTHOFNVBLOCK                                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PROCESSINGOFNVBLOCK                                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AEADCHACHAPOLY1305DECRYPTUSEDOFOBJECTINFO                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AEADCHACHAPOLY1305ENCRYPTUSEDOFOBJECTINFO                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESCCMDECRYPTIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESCCMDECRYPTUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESCCMENCRYPTIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESCCMENCRYPTUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESDECRYPTIDXOFOBJECTINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESDECRYPTUSEDOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESENCRYPTIDXOFOBJECTINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESENCRYPTUSEDOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESGCMDECRYPTIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESGCMDECRYPTUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESGCMENCRYPTIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESGCMENCRYPTUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CMACAESGENERATEIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CMACAESGENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CMACAESVERIFYIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CMACAESVERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DRBGAESIDXOFOBJECTINFO                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DRBGAESUSEDOFOBJECTINFO                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DRBGHASHSHA512IDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DRBGHASHSHA512USEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP160GENERATEIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP160GENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP160VERIFYIDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP160VERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP256GENERATEIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP256GENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP256VERIFYIDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP256VERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP384GENERATEIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP384GENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP384VERIFYIDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP384VERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP521GENERATEIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP521GENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP521VERIFYIDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ECP521VERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ED25519GENERATEIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ED25519GENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ED25519VERIFYIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_ED25519VERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_FIPS186IDXOFOBJECTINFO                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_FIPS186USEDOFOBJECTINFO                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_GMACAESGENERATEIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_GMACAESGENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_GMACAESVERIFYIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_GMACAESVERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HASHIDXOFOBJECTINFO                                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HASHUSEDOFOBJECTINFO                                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACRIPEMD160GENERATEIDXOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACRIPEMD160GENERATEUSEDOFOBJECTINFO                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACRIPEMD160VERIFYIDXOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACRIPEMD160VERIFYUSEDOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA1GENERATEIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA1GENERATEUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA1VERIFYIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA1VERIFYUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA256GENERATEIDXOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA256GENERATEUSEDOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA256VERIFYIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA256VERIFYUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA384GENERATEIDXOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA384GENERATEUSEDOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA384VERIFYIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HMACSHA384VERIFYUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHMACSHA256USEDOFOBJECTINFO                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHASHOPTION1IDXOFOBJECTINFO                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEHKDFHASHOPTION1USEDOFOBJECTINFO                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEISO15118IDXOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEISO15118USEDOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEKDF2HMACSHA1IDXOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEKDF2HMACSHA1USEDOFOBJECTINFO                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEKDF2HMACSHA256IDXOFOBJECTINFO                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEKDF2HMACSHA256USEDOFOBJECTINFO                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVENIST800108CNTIDXOFOBJECTINFO                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVENIST800108CNTUSEDOFOBJECTINFO                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVENIST80056AONEPASSIDXOFOBJECTINFO                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVENIST80056AONEPASSUSEDOFOBJECTINFO                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVENISTFIPS186ERBIDXOFOBJECTINFO                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVENISTFIPS186ERBUSEDOFOBJECTINFO                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVESPAKE2PIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVESPAKE2PUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEX963SHA256IDXOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEX963SHA256USEDOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEX963SHA512IDXOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYDERIVEX963SHA512USEDOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENED25519IDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENED25519USEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENP256R1IDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENP256R1USEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENP384R1IDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENP384R1USEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENSYMGENERICIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYGENSYMGENERICUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP224R1BDPUBVALIDXOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP224R1BDPUBVALUSEDOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP224R1BDSECRETIDXOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP224R1BDSECRETUSEDOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1PUBVALIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1PUBVALUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1SECRETIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP256R1SECRETUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP384R1PUBVALIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP384R1PUBVALUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP384R1SECRETIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP384R1SECRETUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP521R1PUBVALIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP521R1PUBVALUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP521R1SECRETIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYP521R1SECRETUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSEEDDRBGAESIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSEEDDRBGAESUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSEEDDRBGHASHSHA512IDXOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSEEDDRBGHASHSHA512USEDOFOBJECTINFO                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSEEDFIPS186IDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSEEDFIPS186USEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSETVALIDIDXOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSETVALIDUSEDOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSPAKE2PPUBVALIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSPAKE2PPUBVALUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSPAKE2PSECRETIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYSPAKE2PSECRETUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYX25519PUBVALIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYX25519PUBVALUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYX25519SECRETIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYX25519SECRETUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_MD5IDXOFOBJECTINFO                                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_MD5USEDOFOBJECTINFO                                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_QUEUEIDXOFOBJECTINFO                                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RANDOMSEEDBUFFERUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPCRTSHA1DECRYPTIDXOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPCRTSHA1DECRYPTUSEDOFOBJECTINFO                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPCRTSHA256DECRYPTIDXOFOBJECTINFO                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPCRTSHA256DECRYPTUSEDOFOBJECTINFO                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA1DECRYPTIDXOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA1DECRYPTUSEDOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA1ENCRYPTIDXOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA1ENCRYPTUSEDOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA256DECRYPTIDXOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA256DECRYPTUSEDOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA256ENCRYPTIDXOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAOAEPSHA256ENCRYPTUSEDOFOBJECTINFO                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1CRTGENERATEIDXOFOBJECTINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1CRTGENERATEUSEDOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1DECRYPTIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1DECRYPTUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1ENCRYPTIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1ENCRYPTUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1GENERATEIDXOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1GENERATEUSEDOFOBJECTINFO                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1VERIFYIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPKCS1VERIFYUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPSSGENERATEIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPSSGENERATEUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPSSVERIFYIDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_RSAPSSVERIFYUSEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SHECMDGETIDIDXOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SHECMDGETIDUSEDOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SIPHASHGENERATEIDXOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SIPHASHGENERATEUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SIPHASHVERIFYIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SIPHASHVERIFYUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEADDROFOBJECTINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACELENGTHOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_OBJECTINFOIND                                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DISPATCHOFPRIMITIVEFCT                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_OBJECTINFOINDENDIDXOFPRIMITIVEFCT                                     STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_OBJECTINFOINDUSEDOFPRIMITIVEFCT                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_COMBINEDOFPRIMITIVEINFO                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_CONTEXTOFPRIMITIVEINFO                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_MASKEDBITSOFPRIMITIVEINFO                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVEFCTIDXOFPRIMITIVEINFO                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVEINFOUSEDOFPRIMITIVESERVICEINFO                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAOAEPCRTSHA1DECRYPT                                      STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAOAEPCRTSHA256DECRYPT                                    STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAOAEPSHA1DECRYPT                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAOAEPSHA1ENCRYPT                                         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAOAEPSHA256DECRYPT                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAOAEPSHA256ENCRYPT                                       STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPKCS1CRTGENERATE                                        STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPKCS1DECRYPT                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPKCS1ENCRYPT                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPKCS1GENERATE                                           STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPKCS1VERIFY                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPSSGENERATE                                             STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFRSAPSSVERIFY                                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFSHECMDGETID                                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFSIPHASHGENERATE                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_WORKSPACEOFSIPHASHVERIFY                                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_AESDECRYPTOFPCCONFIG                                                  STD_ON
#define CRYPTO_30_LIBCV_ISDEF_BUFFERLENGTHOFPCCONFIG                                                STD_ON
#define CRYPTO_30_LIBCV_ISDEF_DRIVEROBJECTSTATEOFPCCONFIG                                           STD_ON
#define CRYPTO_30_LIBCV_ISDEF_ED25519VERIFYOFPCCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_FAMILYTOHASHMAPPINGOFPCCONFIG                                         STD_ON
#define CRYPTO_30_LIBCV_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_FIPS186OFPCCONFIG                                                     STD_ON
#define CRYPTO_30_LIBCV_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                               STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_HASHOFPCCONFIG                                                        STD_ON
#define CRYPTO_30_LIBCV_ISDEF_INITDATAHASHCODEOFPCCONFIG                                            STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_INITVALUEOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYELEMENTINFOOFPCCONFIG                                              STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYELEMENTSOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYLOCKOFPCCONFIG                                                     STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYOFPCCONFIG                                                         STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYSTORAGEOFPCCONFIG                                                  STD_ON
#define CRYPTO_30_LIBCV_ISDEF_KEYVALIDITYSETCALLOUTFCTNAMEOFCONFIGURABLECALLOUTSOFPCCONFIG          STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_KEYVALUECHANGEDCALLOUTFCTNAMEOFCONFIGURABLECALLOUTSOFPCCONFIG         STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_LOCKOFPCCONFIG                                                        STD_ON
#define CRYPTO_30_LIBCV_ISDEF_OBJECTINFOINDOFPCCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_ISDEF_OBJECTINFOOFPCCONFIG                                                  STD_ON
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVEFCTOFPCCONFIG                                                STD_ON
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVEINFOOFPCCONFIG                                               STD_ON
#define CRYPTO_30_LIBCV_ISDEF_PRIMITIVESERVICEINFOOFPCCONFIG                                        STD_ON
#define CRYPTO_30_LIBCV_ISDEF_QUEUEOFPCCONFIG                                                       STD_ON
#define CRYPTO_30_LIBCV_ISDEF_RANDOMSEEDBUFFEROFPCCONFIG                                            STD_ON
#define CRYPTO_30_LIBCV_ISDEF_SHEDEBUGCMDOFSHEKEYUPDATEOFPCCONFIG                                   STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SHEENABLECOUNTEROFSHEKEYUPDATEOFPCCONFIG                              STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SHEENABLEFIDOFSHEKEYUPDATEOFPCCONFIG                                  STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_SHEINFOKEYREFOFSHEKEYUPDATEOFPCCONFIG                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_UNIONWS_CRYPTO_30_LIBCVOFPCCONFIG                                     STD_ON
#define CRYPTO_30_LIBCV_ISDEF_UNIONWS_CRYPTO_30_LIBCV_AESOFPCCONFIG                                 STD_ON
#define CRYPTO_30_LIBCV_ISDEF_UNIONWS_CRYPTO_30_LIBCV_RNGOFPCCONFIG                                 STD_ON
#define CRYPTO_30_LIBCV_ISDEF_WRITTENLENGTHOFPCCONFIG                                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCEqualsAlwaysToDefines  Crypto_30_LibCv Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAEADCHACHAPOLY1305DECRYPT                                    
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAEADCHACHAPOLY1305ENCRYPT                                    
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAESCCMDECRYPT                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAESCCMENCRYPT                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAESDECRYPT                                                   
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAESENCRYPT                                                   
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAESGCMDECRYPT                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFAESGCMENCRYPT                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFCMACAESGENERATE                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFCMACAESVERIFY                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFDRBGAES                                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFDRBGHASHSHA512                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP160GENERATE                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP160VERIFY                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP256GENERATE                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP256VERIFY                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP384GENERATE                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP384VERIFY                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP521GENERATE                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFECP521VERIFY                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFED25519GENERATE                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFED25519VERIFY                                                
#define CRYPTO_30_LIBCV_EQ2_FAMILYTOHASHMAPPING                                                     
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFFIPS186                                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFGMACAESGENERATE                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFGMACAESVERIFY                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHASH                                                         
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACRIPEMD160GENERATE                                        
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACRIPEMD160VERIFY                                          
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA1GENERATE                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA1VERIFY                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA256GENERATE                                           
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA256VERIFY                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA384GENERATE                                           
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFHMACSHA384VERIFY                                             
#define CRYPTO_30_LIBCV_EQ2_INITVALUE                                                               
#define CRYPTO_30_LIBCV_EQ2_KEYELEMENTSENDIDXOFKEY                                                  
#define CRYPTO_30_LIBCV_EQ2_KEYELEMENTSSTARTIDXOFKEY                                                
#define CRYPTO_30_LIBCV_EQ2_NVBLOCKIDXOFKEY                                                         
#define CRYPTO_30_LIBCV_EQ2_NVBLOCKUSEDOFKEY                                                        
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEHKDFHMACSHA256                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEHKDFHASHOPTION1                                     
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEISO15118                                            
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEKDF2HMACSHA1                                        
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEKDF2HMACSHA256                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVENIST800108CNT                                       
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVENIST80056AONEPASS                                   
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVENISTFIPS186ERB                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVESPAKE2P                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEX963SHA256                                          
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYDERIVEX963SHA512                                          
#define CRYPTO_30_LIBCV_EQ2_IDOFKEYELEMENTINFO                                                      
#define CRYPTO_30_LIBCV_EQ2_INITVALUEENDIDXOFKEYELEMENTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_INITVALUESTARTIDXOFKEYELEMENTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_INITVALUEUSEDOFKEYELEMENTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_LENGTHOFKEYELEMENTINFO                                                  
#define CRYPTO_30_LIBCV_EQ2_MASKEDBITSOFKEYELEMENTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_ONCEOFKEYELEMENTINFO                                                    
#define CRYPTO_30_LIBCV_EQ2_PARTIALOFKEYELEMENTINFO                                                 
#define CRYPTO_30_LIBCV_EQ2_PERSISTOFKEYELEMENTINFO                                                 
#define CRYPTO_30_LIBCV_EQ2_READOFKEYELEMENTINFO                                                    
#define CRYPTO_30_LIBCV_EQ2_WRITEOFKEYELEMENTINFO                                                   
#define CRYPTO_30_LIBCV_EQ2_IDOFKEYELEMENTS                                                         
#define CRYPTO_30_LIBCV_EQ2_KEYELEMENTINFOIDXOFKEYELEMENTS                                          
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEENDIDXOFKEYELEMENTS                                           
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEEXTENSIONIDXOFKEYELEMENTS                                     
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGESTARTIDXOFKEYELEMENTS                                         
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEVALIDIDXOFKEYELEMENTS                                         
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEWRITTENLENGTHENDIDXOFKEYELEMENTS                              
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEWRITTENLENGTHSTARTIDXOFKEYELEMENTS                            
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYGENED25519                                                
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYGENP256R1                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYGENP384R1                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYGENSYMGENERIC                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP224R1BDPUBVAL                                            
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP224R1BDSECRET                                            
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP256R1PUBVAL                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP256R1SECRET                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP384R1PUBVAL                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP384R1SECRET                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP521R1PUBVAL                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYP521R1SECRET                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSEEDDRBGAES                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSEEDDRBGHASHSHA512                                        
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSEEDFIPS186                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSETVALID                                                  
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSPAKE2PPUBVAL                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYSPAKE2PSECRET                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYX25519PUBVAL                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFKEYX25519SECRET                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFMD5                                                          
#define CRYPTO_30_LIBCV_EQ2_CONSISTENCYLEVELOFNVBLOCK                                               
#define CRYPTO_30_LIBCV_EQ2_CRCOFNVBLOCK                                                            
#define CRYPTO_30_LIBCV_EQ2_DESCRIPTOROFNVBLOCK                                                     
#define CRYPTO_30_LIBCV_EQ2_IDOFNVBLOCK                                                             
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEENDIDXOFNVBLOCK                                               
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGESTARTIDXOFNVBLOCK                                             
#define CRYPTO_30_LIBCV_EQ2_LENGTHOFNVBLOCK                                                         
#define CRYPTO_30_LIBCV_EQ2_PROCESSINGOFNVBLOCK                                                     
#define CRYPTO_30_LIBCV_EQ2_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO                                
#define CRYPTO_30_LIBCV_EQ2_AEADCHACHAPOLY1305DECRYPTUSEDOFOBJECTINFO                               
#define CRYPTO_30_LIBCV_EQ2_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO                                
#define CRYPTO_30_LIBCV_EQ2_AEADCHACHAPOLY1305ENCRYPTUSEDOFOBJECTINFO                               
#define CRYPTO_30_LIBCV_EQ2_AESCCMDECRYPTIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_AESCCMDECRYPTUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_AESCCMENCRYPTIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_AESCCMENCRYPTUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_AESDECRYPTIDXOFOBJECTINFO                                               
#define CRYPTO_30_LIBCV_EQ2_AESDECRYPTUSEDOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_AESENCRYPTIDXOFOBJECTINFO                                               
#define CRYPTO_30_LIBCV_EQ2_AESENCRYPTUSEDOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_AESGCMDECRYPTIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_AESGCMDECRYPTUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_AESGCMENCRYPTIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_AESGCMENCRYPTUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_CMACAESGENERATEIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_CMACAESGENERATEUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_CMACAESVERIFYIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_CMACAESVERIFYUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_DRBGAESIDXOFOBJECTINFO                                                  
#define CRYPTO_30_LIBCV_EQ2_DRBGAESUSEDOFOBJECTINFO                                                 
#define CRYPTO_30_LIBCV_EQ2_DRBGHASHSHA512IDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_DRBGHASHSHA512USEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_ECP160GENERATEIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_ECP160GENERATEUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_ECP160VERIFYIDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_ECP160VERIFYUSEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_ECP256GENERATEIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_ECP256GENERATEUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_ECP256VERIFYIDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_ECP256VERIFYUSEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_ECP384GENERATEIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_ECP384GENERATEUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_ECP384VERIFYIDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_ECP384VERIFYUSEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_ECP521GENERATEIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_ECP521GENERATEUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_ECP521VERIFYIDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_ECP521VERIFYUSEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_ED25519GENERATEIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_ED25519GENERATEUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_ED25519VERIFYIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_ED25519VERIFYUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_FIPS186IDXOFOBJECTINFO                                                  
#define CRYPTO_30_LIBCV_EQ2_FIPS186USEDOFOBJECTINFO                                                 
#define CRYPTO_30_LIBCV_EQ2_GMACAESGENERATEIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_GMACAESGENERATEUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_GMACAESVERIFYIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_GMACAESVERIFYUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_HASHIDXOFOBJECTINFO                                                     
#define CRYPTO_30_LIBCV_EQ2_HASHUSEDOFOBJECTINFO                                                    
#define CRYPTO_30_LIBCV_EQ2_HMACRIPEMD160GENERATEIDXOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_HMACRIPEMD160GENERATEUSEDOFOBJECTINFO                                   
#define CRYPTO_30_LIBCV_EQ2_HMACRIPEMD160VERIFYIDXOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_HMACRIPEMD160VERIFYUSEDOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_HMACSHA1GENERATEIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_HMACSHA1GENERATEUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_HMACSHA1VERIFYIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_HMACSHA1VERIFYUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_HMACSHA256GENERATEIDXOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_HMACSHA256GENERATEUSEDOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_HMACSHA256VERIFYIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_HMACSHA256VERIFYUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_HMACSHA384GENERATEIDXOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_HMACSHA384GENERATEUSEDOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_HMACSHA384VERIFYIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_HMACSHA384VERIFYUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO                                  
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHMACSHA256USEDOFOBJECTINFO                                 
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHASHOPTION1IDXOFOBJECTINFO                                 
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEHKDFHASHOPTION1USEDOFOBJECTINFO                                
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEISO15118IDXOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEISO15118USEDOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEKDF2HMACSHA1IDXOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEKDF2HMACSHA1USEDOFOBJECTINFO                                   
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEKDF2HMACSHA256IDXOFOBJECTINFO                                  
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEKDF2HMACSHA256USEDOFOBJECTINFO                                 
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVENIST800108CNTIDXOFOBJECTINFO                                   
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVENIST800108CNTUSEDOFOBJECTINFO                                  
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVENIST80056AONEPASSIDXOFOBJECTINFO                               
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVENIST80056AONEPASSUSEDOFOBJECTINFO                              
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVENISTFIPS186ERBIDXOFOBJECTINFO                                  
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVENISTFIPS186ERBUSEDOFOBJECTINFO                                 
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVESPAKE2PIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVESPAKE2PUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEX963SHA256IDXOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEX963SHA256USEDOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEX963SHA512IDXOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_KEYDERIVEX963SHA512USEDOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_KEYGENED25519IDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_KEYGENED25519USEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_KEYGENP256R1IDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_KEYGENP256R1USEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_KEYGENP384R1IDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_KEYGENP384R1USEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_KEYGENSYMGENERICIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYGENSYMGENERICUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYP224R1BDPUBVALIDXOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYP224R1BDPUBVALUSEDOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_KEYP224R1BDSECRETIDXOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYP224R1BDSECRETUSEDOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1PUBVALIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1PUBVALUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1SECRETIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYP256R1SECRETUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYP384R1PUBVALIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYP384R1PUBVALUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYP384R1SECRETIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYP384R1SECRETUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYP521R1PUBVALIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYP521R1PUBVALUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYP521R1SECRETIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYP521R1SECRETUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYSEEDDRBGAESIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_KEYSEEDDRBGAESUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYSEEDDRBGHASHSHA512IDXOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_KEYSEEDDRBGHASHSHA512USEDOFOBJECTINFO                                   
#define CRYPTO_30_LIBCV_EQ2_KEYSEEDFIPS186IDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_KEYSEEDFIPS186USEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYSETVALIDIDXOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_KEYSETVALIDUSEDOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_KEYSPAKE2PPUBVALIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYSPAKE2PPUBVALUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYSPAKE2PSECRETIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYSPAKE2PSECRETUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_KEYX25519PUBVALIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYX25519PUBVALUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_KEYX25519SECRETIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_KEYX25519SECRETUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_MD5IDXOFOBJECTINFO                                                      
#define CRYPTO_30_LIBCV_EQ2_MD5USEDOFOBJECTINFO                                                     
#define CRYPTO_30_LIBCV_EQ2_QUEUEIDXOFOBJECTINFO                                                    
#define CRYPTO_30_LIBCV_EQ2_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_RANDOMSEEDBUFFERUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPCRTSHA1DECRYPTIDXOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPCRTSHA1DECRYPTUSEDOFOBJECTINFO                                   
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPCRTSHA256DECRYPTIDXOFOBJECTINFO                                  
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPCRTSHA256DECRYPTUSEDOFOBJECTINFO                                 
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA1DECRYPTIDXOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA1DECRYPTUSEDOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA1ENCRYPTIDXOFOBJECTINFO                                       
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA1ENCRYPTUSEDOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA256DECRYPTIDXOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA256DECRYPTUSEDOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA256ENCRYPTIDXOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_RSAOAEPSHA256ENCRYPTUSEDOFOBJECTINFO                                    
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1CRTGENERATEIDXOFOBJECTINFO                                      
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1CRTGENERATEUSEDOFOBJECTINFO                                     
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1DECRYPTIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1DECRYPTUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1ENCRYPTIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1ENCRYPTUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1GENERATEIDXOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1GENERATEUSEDOFOBJECTINFO                                        
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1VERIFYIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_RSAPKCS1VERIFYUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_RSAPSSGENERATEIDXOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_RSAPSSGENERATEUSEDOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_RSAPSSVERIFYIDXOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_RSAPSSVERIFYUSEDOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_SHECMDGETIDIDXOFOBJECTINFO                                              
#define CRYPTO_30_LIBCV_EQ2_SHECMDGETIDUSEDOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_SIPHASHGENERATEIDXOFOBJECTINFO                                          
#define CRYPTO_30_LIBCV_EQ2_SIPHASHGENERATEUSEDOFOBJECTINFO                                         
#define CRYPTO_30_LIBCV_EQ2_SIPHASHVERIFYIDXOFOBJECTINFO                                            
#define CRYPTO_30_LIBCV_EQ2_SIPHASHVERIFYUSEDOFOBJECTINFO                                           
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEADDROFOBJECTINFO                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACELENGTHOFOBJECTINFO                                             
#define CRYPTO_30_LIBCV_EQ2_OBJECTINFOIND                                                           
#define CRYPTO_30_LIBCV_EQ2_DISPATCHOFPRIMITIVEFCT                                                  
#define CRYPTO_30_LIBCV_EQ2_OBJECTINFOINDENDIDXOFPRIMITIVEFCT                                       
#define CRYPTO_30_LIBCV_EQ2_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT                                     
#define CRYPTO_30_LIBCV_EQ2_OBJECTINFOINDUSEDOFPRIMITIVEFCT                                         
#define CRYPTO_30_LIBCV_EQ2_COMBINEDOFPRIMITIVEINFO                                                 
#define CRYPTO_30_LIBCV_EQ2_CONTEXTOFPRIMITIVEINFO                                                  
#define CRYPTO_30_LIBCV_EQ2_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO                                      
#define CRYPTO_30_LIBCV_EQ2_MASKEDBITSOFPRIMITIVEINFO                                               
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVEFCTIDXOFPRIMITIVEINFO                                          
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO                               
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO                             
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVEINFOUSEDOFPRIMITIVESERVICEINFO                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAOAEPCRTSHA1DECRYPT                                        
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAOAEPCRTSHA256DECRYPT                                      
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAOAEPSHA1DECRYPT                                           
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAOAEPSHA1ENCRYPT                                           
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAOAEPSHA256DECRYPT                                         
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAOAEPSHA256ENCRYPT                                         
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPKCS1CRTGENERATE                                          
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPKCS1DECRYPT                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPKCS1ENCRYPT                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPKCS1GENERATE                                             
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPKCS1VERIFY                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPSSGENERATE                                               
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFRSAPSSVERIFY                                                 
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFSHECMDGETID                                                  
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFSIPHASHGENERATE                                              
#define CRYPTO_30_LIBCV_EQ2_WORKSPACEOFSIPHASHVERIFY                                                
#define CRYPTO_30_LIBCV_EQ2_AESDECRYPTOFPCCONFIG                                                    Crypto_30_LibCv_AesDecrypt
#define CRYPTO_30_LIBCV_EQ2_BUFFERLENGTHOFPCCONFIG                                                  Crypto_30_LibCv_BufferLength
#define CRYPTO_30_LIBCV_EQ2_DRIVEROBJECTSTATEOFPCCONFIG                                             Crypto_30_LibCv_DriverObjectState
#define CRYPTO_30_LIBCV_EQ2_ED25519VERIFYOFPCCONFIG                                                 Crypto_30_LibCv_Ed25519Verify
#define CRYPTO_30_LIBCV_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                  
#define CRYPTO_30_LIBCV_EQ2_FAMILYTOHASHMAPPINGOFPCCONFIG                                           Crypto_30_LibCv_FamilyToHashMapping
#define CRYPTO_30_LIBCV_EQ2_FINALMAGICNUMBEROFPCCONFIG                                              
#define CRYPTO_30_LIBCV_EQ2_FIPS186OFPCCONFIG                                                       Crypto_30_LibCv_Fips186
#define CRYPTO_30_LIBCV_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                 
#define CRYPTO_30_LIBCV_EQ2_HASHOFPCCONFIG                                                          Crypto_30_LibCv_Hash
#define CRYPTO_30_LIBCV_EQ2_INITDATAHASHCODEOFPCCONFIG                                              
#define CRYPTO_30_LIBCV_EQ2_INITVALUEOFPCCONFIG                                                     Crypto_30_LibCv_InitValue
#define CRYPTO_30_LIBCV_EQ2_KEYELEMENTINFOOFPCCONFIG                                                Crypto_30_LibCv_KeyElementInfo
#define CRYPTO_30_LIBCV_EQ2_KEYELEMENTSOFPCCONFIG                                                   Crypto_30_LibCv_KeyElements
#define CRYPTO_30_LIBCV_EQ2_KEYLOCKOFPCCONFIG                                                       Crypto_30_LibCv_KeyLock.raw
#define CRYPTO_30_LIBCV_EQ2_KEYOFPCCONFIG                                                           Crypto_30_LibCv_Key
#define CRYPTO_30_LIBCV_EQ2_KEYSTORAGEOFPCCONFIG                                                    Crypto_30_LibCv_KeyStorage
#define CRYPTO_30_LIBCV_EQ2_KEYVALIDITYSETCALLOUTFCTNAMEOFCONFIGURABLECALLOUTSOFPCCONFIG            
#define CRYPTO_30_LIBCV_EQ2_KEYVALUECHANGEDCALLOUTFCTNAMEOFCONFIGURABLECALLOUTSOFPCCONFIG           
#define CRYPTO_30_LIBCV_EQ2_LOCKOFPCCONFIG                                                          Crypto_30_LibCv_Lock
#define CRYPTO_30_LIBCV_EQ2_OBJECTINFOINDOFPCCONFIG                                                 Crypto_30_LibCv_ObjectInfoInd
#define CRYPTO_30_LIBCV_EQ2_OBJECTINFOOFPCCONFIG                                                    Crypto_30_LibCv_ObjectInfo
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVEFCTOFPCCONFIG                                                  Crypto_30_LibCv_PrimitiveFct
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVEINFOOFPCCONFIG                                                 Crypto_30_LibCv_PrimitiveInfo
#define CRYPTO_30_LIBCV_EQ2_PRIMITIVESERVICEINFOOFPCCONFIG                                          Crypto_30_LibCv_PrimitiveServiceInfo
#define CRYPTO_30_LIBCV_EQ2_QUEUEOFPCCONFIG                                                         Crypto_30_LibCv_Queue.raw
#define CRYPTO_30_LIBCV_EQ2_RANDOMSEEDBUFFEROFPCCONFIG                                              Crypto_30_LibCv_RandomSeedBuffer.raw
#define CRYPTO_30_LIBCV_EQ2_SHEDEBUGCMDOFSHEKEYUPDATEOFPCCONFIG                                     
#define CRYPTO_30_LIBCV_EQ2_SHEENABLECOUNTEROFSHEKEYUPDATEOFPCCONFIG                                
#define CRYPTO_30_LIBCV_EQ2_SHEENABLEFIDOFSHEKEYUPDATEOFPCCONFIG                                    
#define CRYPTO_30_LIBCV_EQ2_SHEINFOKEYREFOFSHEKEYUPDATEOFPCCONFIG                                   
#define CRYPTO_30_LIBCV_EQ2_UNIONWS_CRYPTO_30_LIBCVOFPCCONFIG                                       (&(Crypto_30_LibCv_UnionWS_Crypto_30_LibCv))
#define CRYPTO_30_LIBCV_EQ2_UNIONWS_CRYPTO_30_LIBCV_AESOFPCCONFIG                                   (&(Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes))
#define CRYPTO_30_LIBCV_EQ2_UNIONWS_CRYPTO_30_LIBCV_RNGOFPCCONFIG                                   (&(Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng))
#define CRYPTO_30_LIBCV_EQ2_WRITTENLENGTHOFPCCONFIG                                                 Crypto_30_LibCv_WrittenLength
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCSymbolicInitializationPointers  Crypto_30_LibCv Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Crypto_30_LibCv_Config_Ptr                                                                  NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Crypto_30_LibCv' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCInitializationSymbols  Crypto_30_LibCv Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Crypto_30_LibCv_Config                                                                      NULL_PTR  /**< symbolic identifier which could be used to initialize 'Crypto_30_LibCv */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGeneral  Crypto_30_LibCv General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CRYPTO_30_LIBCV_CHECK_INIT_POINTER                                                          STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CRYPTO_30_LIBCV_FINAL_MAGIC_NUMBER                                                          0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Crypto_30_LibCv */
#define CRYPTO_30_LIBCV_INDIVIDUAL_POSTBUILD                                                        STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Crypto_30_LibCv' is not configured to be postbuild capable. */
#define CRYPTO_30_LIBCV_INIT_DATA                                                                   CRYPTO_30_LIBCV_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CRYPTO_30_LIBCV_INIT_DATA_HASH_CODE                                                         2027971617  /**< the precompile constant to validate the initialization structure at initialization time of Crypto_30_LibCv with a hashcode. The seed value is '0xFF1Eu' */
#define CRYPTO_30_LIBCV_USE_ECUM_BSW_ERROR_HOOK                                                     STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CRYPTO_30_LIBCV_USE_INIT_POINTER                                                            STD_OFF  /**< STD_ON if the init pointer Crypto_30_LibCv shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_LibCvPBDataSwitches  Crypto_30_LibCv Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYPTO_30_LIBCV_PBCONFIG                                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_LIBCV_LTCONFIGIDXOFPBCONFIG                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_LIBCV_PCCONFIGIDXOFPBCONFIG                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPBIsReducedToDefineDefines  Crypto_30_LibCv Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYPTO_30_LIBCV_ISDEF_LTCONFIGIDXOFPBCONFIG                                                 STD_OFF
#define CRYPTO_30_LIBCV_ISDEF_PCCONFIGIDXOFPBCONFIG                                                 STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPBEqualsAlwaysToDefines  Crypto_30_LibCv Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYPTO_30_LIBCV_EQ2_LTCONFIGIDXOFPBCONFIG                                                   
#define CRYPTO_30_LIBCV_EQ2_PCCONFIGIDXOFPBCONFIG                                                   
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
  \defgroup  Crypto_30_LibCvPCGetRootDataMacros  Crypto_30_LibCv Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Crypto_30_LibCv_GetExpectedCompatibilityVersionOfPCConfig()                                   /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_GetFinalMagicNumberOfPCConfig()                                               /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_GetGeneratorCompatibilityVersionOfPCConfig()                                  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_GetInitDataHashCodeOfPCConfig()                                               /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_GetKeyValiditySetCalloutFctNameOfConfigurableCalloutsOfPCConfig()             /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.KeyValiditySetCalloutFctNameOfConfigurableCallouts' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_GetKeyValueChangedCalloutFctNameOfConfigurableCalloutsOfPCConfig()            /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.KeyValueChangedCalloutFctNameOfConfigurableCallouts' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_IsSheDebugCmdOfSheKeyUpdateOfPCConfig()                                       /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.SheDebugCmdOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_IsSheEnableCounterOfSheKeyUpdateOfPCConfig()                                  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.SheEnableCounterOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_IsSheEnableFidOfSheKeyUpdateOfPCConfig()                                      /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.SheEnableFidOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_GetSheInfoKeyRefOfSheKeyUpdateOfPCConfig()                                    /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.SheInfoKeyRefOfSheKeyUpdate' Reason: 'Reference is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGetConstantDuplicatedRootDataMacros  Crypto_30_LibCv Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Crypto_30_LibCv_GetAesDecryptOfPCConfig()                                                   Crypto_30_LibCv_AesDecrypt  /**< the pointer to Crypto_30_LibCv_AesDecrypt */
#define Crypto_30_LibCv_IsAlignKeyStorageOfGeneralOfPCConfig()                                      (((FALSE)) != FALSE)
#define Crypto_30_LibCv_GetBufferLengthOfPCConfig()                                                 Crypto_30_LibCv_BufferLength  /**< the pointer to Crypto_30_LibCv_BufferLength */
#define Crypto_30_LibCv_IsCmacAesRoundkeyReuseOfMacPrimitivesOfPCConfig()                           (((FALSE)) != FALSE)
#define Crypto_30_LibCv_GetDefaultRandomMaxRetriesOfGeneralOfPCConfig()                             10u
#define Crypto_30_LibCv_GetDriverObjectStateOfPCConfig()                                            Crypto_30_LibCv_DriverObjectState  /**< the pointer to Crypto_30_LibCv_DriverObjectState */
#define Crypto_30_LibCv_GetEd25519VerifyOfPCConfig()                                                Crypto_30_LibCv_Ed25519Verify  /**< the pointer to Crypto_30_LibCv_Ed25519Verify */
#define Crypto_30_LibCv_IsEnableAES192OfCipherPrimitivesOfPCConfig()                                (((FALSE)) != FALSE)
#define Crypto_30_LibCv_IsEnableAES256OfCipherPrimitivesOfPCConfig()                                (((FALSE)) != FALSE)
#define Crypto_30_LibCv_GetFamilyToHashMappingOfPCConfig()                                          Crypto_30_LibCv_FamilyToHashMapping  /**< the pointer to Crypto_30_LibCv_FamilyToHashMapping */
#define Crypto_30_LibCv_GetFips186OfPCConfig()                                                      Crypto_30_LibCv_Fips186  /**< the pointer to Crypto_30_LibCv_Fips186 */
#define Crypto_30_LibCv_GetHashOfPCConfig()                                                         Crypto_30_LibCv_Hash  /**< the pointer to Crypto_30_LibCv_Hash */
#define Crypto_30_LibCv_GetInitValueOfPCConfig()                                                    Crypto_30_LibCv_InitValue  /**< the pointer to Crypto_30_LibCv_InitValue */
#define Crypto_30_LibCv_IsKeyElementDeleteOfGeneralOfPCConfig()                                     (((FALSE)) != FALSE)
#define Crypto_30_LibCv_GetKeyElementInfoOfPCConfig()                                               Crypto_30_LibCv_KeyElementInfo  /**< the pointer to Crypto_30_LibCv_KeyElementInfo */
#define Crypto_30_LibCv_GetKeyElementsOfPCConfig()                                                  Crypto_30_LibCv_KeyElements  /**< the pointer to Crypto_30_LibCv_KeyElements */
#define Crypto_30_LibCv_GetKeyGenerateMaxLengthOfKeyGeneratePrimitivesOfPCConfig()                  32u
#define Crypto_30_LibCv_GetKeyLockOfPCConfig()                                                      Crypto_30_LibCv_KeyLock.raw  /**< the pointer to Crypto_30_LibCv_KeyLock */
#define Crypto_30_LibCv_GetKeyOfPCConfig()                                                          Crypto_30_LibCv_Key  /**< the pointer to Crypto_30_LibCv_Key */
#define Crypto_30_LibCv_GetKeyStorageOfPCConfig()                                                   Crypto_30_LibCv_KeyStorage  /**< the pointer to Crypto_30_LibCv_KeyStorage */
#define Crypto_30_LibCv_GetLockOfPCConfig()                                                         Crypto_30_LibCv_Lock  /**< the pointer to Crypto_30_LibCv_Lock */
#define Crypto_30_LibCv_GetMainFunctionPeriodOfGeneralOfPCConfig()                                  1u
#define Crypto_30_LibCv_GetNumberOfLongTermPrimitiveWorkspaceOfGeneralOfPCConfig()                  0u
#define Crypto_30_LibCv_IsNvMEnableSetRamBlockStatusOfGeneralOfPCConfig()                           (((FALSE)) != FALSE)
#define Crypto_30_LibCv_GetNvManagementDataPerKeyOfNvStorageOfPCConfig()                            4u
#define Crypto_30_LibCv_GetNvWriteBlockFctNameOfNvStorageOfPCConfig()                               NvM_WriteBlock
#define Crypto_30_LibCv_GetObjectInfoIndOfPCConfig()                                                Crypto_30_LibCv_ObjectInfoInd  /**< the pointer to Crypto_30_LibCv_ObjectInfoInd */
#define Crypto_30_LibCv_GetObjectInfoOfPCConfig()                                                   Crypto_30_LibCv_ObjectInfo  /**< the pointer to Crypto_30_LibCv_ObjectInfo */
#define Crypto_30_LibCv_GetPrimitiveFctOfPCConfig()                                                 Crypto_30_LibCv_PrimitiveFct  /**< the pointer to Crypto_30_LibCv_PrimitiveFct */
#define Crypto_30_LibCv_GetPrimitiveInfoOfPCConfig()                                                Crypto_30_LibCv_PrimitiveInfo  /**< the pointer to Crypto_30_LibCv_PrimitiveInfo */
#define Crypto_30_LibCv_GetPrimitiveServiceInfoOfPCConfig()                                         Crypto_30_LibCv_PrimitiveServiceInfo  /**< the pointer to Crypto_30_LibCv_PrimitiveServiceInfo */
#define Crypto_30_LibCv_GetQueueOfPCConfig()                                                        Crypto_30_LibCv_Queue.raw  /**< the pointer to Crypto_30_LibCv_Queue */
#define Crypto_30_LibCv_GetRandomSeedBufferOfPCConfig()                                             Crypto_30_LibCv_RandomSeedBuffer.raw  /**< the pointer to Crypto_30_LibCv_RandomSeedBuffer */
#define Crypto_30_LibCv_IsRedirectionOfGeneralOfPCConfig()                                          (((FALSE)) != FALSE)
#define Crypto_30_LibCv_GetSizeOfAesDecryptOfPCConfig()                                             1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_AesDecrypt */
#define Crypto_30_LibCv_GetSizeOfEd25519VerifyOfPCConfig()                                          1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_Ed25519Verify */
#define Crypto_30_LibCv_GetSizeOfFamilyToHashMappingOfPCConfig()                                    8u  /**< the number of accomplishable value elements in Crypto_30_LibCv_FamilyToHashMapping */
#define Crypto_30_LibCv_GetSizeOfFips186OfPCConfig()                                                2u  /**< the number of accomplishable value elements in Crypto_30_LibCv_Fips186 */
#define Crypto_30_LibCv_GetSizeOfHashOfPCConfig()                                                   1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_Hash */
#define Crypto_30_LibCv_GetSizeOfInitValueOfPCConfig()                                              1u  /**< the number of accomplishable value elements in Crypto_30_LibCv_InitValue */
#define Crypto_30_LibCv_GetSizeOfKeyElementInfoOfPCConfig()                                         6u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyElementInfo */
#define Crypto_30_LibCv_GetSizeOfKeyElementsOfPCConfig()                                            6u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyElements */
#define Crypto_30_LibCv_GetSizeOfKeyOfPCConfig()                                                    4u  /**< the number of accomplishable value elements in Crypto_30_LibCv_Key */
#define Crypto_30_LibCv_GetSizeOfKeyStorageOfPCConfig()                                             129u  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyStorage */
#define Crypto_30_LibCv_GetSizeOfObjectInfoIndOfPCConfig()                                          5u  /**< the number of accomplishable value elements in Crypto_30_LibCv_ObjectInfoInd */
#define Crypto_30_LibCv_GetSizeOfObjectInfoOfPCConfig()                                             3u  /**< the number of accomplishable value elements in Crypto_30_LibCv_ObjectInfo */
#define Crypto_30_LibCv_GetSizeOfPrimitiveFctOfPCConfig()                                           4u  /**< the number of accomplishable value elements in Crypto_30_LibCv_PrimitiveFct */
#define Crypto_30_LibCv_GetSizeOfPrimitiveInfoOfPCConfig()                                          13u  /**< the number of accomplishable value elements in Crypto_30_LibCv_PrimitiveInfo */
#define Crypto_30_LibCv_GetSizeOfPrimitiveServiceInfoOfPCConfig()                                   20u  /**< the number of accomplishable value elements in Crypto_30_LibCv_PrimitiveServiceInfo */
#define Crypto_30_LibCv_GetSizeOfQueueOfPCConfig()                                                  3u  /**< the number of accomplishable value elements in Crypto_30_LibCv_Queue */
#define Crypto_30_LibCv_GetSizeOfRandomSeedBufferOfPCConfig()                                       42u  /**< the number of accomplishable value elements in Crypto_30_LibCv_RandomSeedBuffer */
#define Crypto_30_LibCv_IsStrictLengthCheckForKeyElementGetOfGeneralOfPCConfig()                    (((TRUE)) != FALSE)
#define Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCvOfPCConfig()                                      (&(Crypto_30_LibCv_UnionWS_Crypto_30_LibCv))  /**< the pointer to Crypto_30_LibCv_UnionWS_Crypto_30_LibCv */
#define Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_AesOfPCConfig()                                  (&(Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes))  /**< the pointer to Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes */
#define Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_RngOfPCConfig()                                  (&(Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng))  /**< the pointer to Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng */
#define Crypto_30_LibCv_IsUseVStdLibOfGeneralOfPCConfig()                                           (((TRUE)) != FALSE)
#define Crypto_30_LibCv_IsVersionInfoApiOfGeneralOfPCConfig()                                       (((FALSE)) != FALSE)
#define Crypto_30_LibCv_GetWatchdogTriggerFunctionOfGeneralOfPCConfig()                             FblLookForWatchdogVoid
#define Crypto_30_LibCv_GetWrittenLengthOfPCConfig()                                                Crypto_30_LibCv_WrittenLength  /**< the pointer to Crypto_30_LibCv_WrittenLength */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGetDuplicatedRootDataMacros  Crypto_30_LibCv Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Crypto_30_LibCv_GetSizeOfBufferLengthOfPCConfig()                                           Crypto_30_LibCv_GetSizeOfObjectInfoOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_BufferLength */
#define Crypto_30_LibCv_GetSizeOfDriverObjectStateOfPCConfig()                                      Crypto_30_LibCv_GetSizeOfObjectInfoOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_DriverObjectState */
#define Crypto_30_LibCv_GetSizeOfKeyLockOfPCConfig()                                                Crypto_30_LibCv_GetSizeOfKeyOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_KeyLock */
#define Crypto_30_LibCv_GetSizeOfLockOfPCConfig()                                                   Crypto_30_LibCv_GetSizeOfObjectInfoOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_Lock */
#define Crypto_30_LibCv_GetSizeOfWrittenLengthOfPCConfig()                                          Crypto_30_LibCv_GetSizeOfObjectInfoOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_LibCv_WrittenLength */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGetDataMacros  Crypto_30_LibCv Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Crypto_30_LibCv_GetWorkspaceOfAEADChaChaPoly1305Decrypt(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_AEADChaChaPoly1305Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfAEADChaChaPoly1305Encrypt(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_AEADChaChaPoly1305Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfAesCcmDecrypt(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_AesCcmDecrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfAesCcmEncrypt(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_AesCcmEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfAesDecrypt(Index)                                             (Crypto_30_LibCv_GetAesDecryptOfPCConfig()[(Index)].WorkspaceOfAesDecrypt)
#define Crypto_30_LibCv_GetWorkspaceOfAesEncrypt(Index)                                               /**< Deactivateable: 'Crypto_30_LibCv_AesEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfAesGcmDecrypt(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_AesGcmDecrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfAesGcmEncrypt(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_AesGcmEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetBufferLength(Index)                                                      (Crypto_30_LibCv_GetBufferLengthOfPCConfig()[(Index)])
#define Crypto_30_LibCv_GetWorkspaceOfCmacAesGenerate(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_CmacAesGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfCmacAesVerify(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_CmacAesVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfDRBGAES(Index)                                                  /**< Deactivateable: 'Crypto_30_LibCv_DRBGAES.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfDRBGHashSha512(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_DRBGHashSha512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetDriverObjectState(Index)                                                 (Crypto_30_LibCv_GetDriverObjectStateOfPCConfig()[(Index)])
#define Crypto_30_LibCv_GetWorkspaceOfEcP160Generate(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_EcP160Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEcP160Verify(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_EcP160Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEcP256Generate(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_EcP256Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEcP256Verify(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_EcP256Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEcP384Generate(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_EcP384Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEcP384Verify(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_EcP384Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEcP521Generate(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_EcP521Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEcP521Verify(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_EcP521Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEd25519Generate(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_Ed25519Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfEd25519Verify(Index)                                          (Crypto_30_LibCv_GetEd25519VerifyOfPCConfig()[(Index)].WorkspaceOfEd25519Verify)
#define Crypto_30_LibCv_GetFamilyToHashMapping(Index)                                               (Crypto_30_LibCv_GetFamilyToHashMappingOfPCConfig()[(Index)])
#define Crypto_30_LibCv_GetWorkspaceOfFips186(Index)                                                (Crypto_30_LibCv_GetFips186OfPCConfig()[(Index)].WorkspaceOfFips186)
#define Crypto_30_LibCv_GetWorkspaceOfGmacAesGenerate(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_GmacAesGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfGmacAesVerify(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_GmacAesVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfHash(Index)                                                   (Crypto_30_LibCv_GetHashOfPCConfig()[(Index)].WorkspaceOfHash)
#define Crypto_30_LibCv_GetWorkspaceOfHmacRipeMd160Generate(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfHmacRipeMd160Verify(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha1Generate(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_HmacSha1Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha1Verify(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_HmacSha1Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha256Generate(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_HmacSha256Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha256Verify(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_HmacSha256Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha384Generate(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_HmacSha384Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfHmacSha384Verify(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_HmacSha384Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetInitValue(Index)                                                         (Crypto_30_LibCv_GetInitValueOfPCConfig()[(Index)])
#define Crypto_30_LibCv_GetKeyElementsEndIdxOfKey(Index)                                            (Crypto_30_LibCv_GetKeyOfPCConfig()[(Index)].KeyElementsEndIdxOfKey)
#define Crypto_30_LibCv_GetKeyElementsStartIdxOfKey(Index)                                          (Crypto_30_LibCv_GetKeyOfPCConfig()[(Index)].KeyElementsStartIdxOfKey)
#define Crypto_30_LibCv_GetNvBlockIdxOfKey(Index)                                                     /**< Deactivateable: 'Crypto_30_LibCv_Key.NvBlockIdx' Reason: 'the optional indirection is deactivated because NvBlockUsedOfKey is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsNvBlockUsedOfKey(Index)                                                     /**< Deactivateable: 'Crypto_30_LibCv_Key.NvBlockUsed' Reason: 'the optional indirection is deactivated because NvBlockUsedOfKey is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveHKDFHMACSHA256(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveHKDFHashOption1(Index)                                 /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveISO15118(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveISO15118.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveKDF2HMACSHA1(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveKDF2HMACSHA256(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveNist800108Cnt(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist800108Cnt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveNist80056AOnePass(Index)                               /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist80056AOnePass.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveNistFips186Erb(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNistFips186Erb.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveSpake2P(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveSpake2P.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveX963SHA256(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyDeriveX963SHA512(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetIdOfKeyElementInfo(Index)                                                (Crypto_30_LibCv_GetKeyElementInfoOfPCConfig()[(Index)].IdOfKeyElementInfo)
#define Crypto_30_LibCv_GetInitValueEndIdxOfKeyElementInfo(Index)                                   (Crypto_30_LibCv_GetKeyElementInfoOfPCConfig()[(Index)].InitValueEndIdxOfKeyElementInfo)
#define Crypto_30_LibCv_GetInitValueStartIdxOfKeyElementInfo(Index)                                 (Crypto_30_LibCv_GetKeyElementInfoOfPCConfig()[(Index)].InitValueStartIdxOfKeyElementInfo)
#define Crypto_30_LibCv_GetLengthOfKeyElementInfo(Index)                                            (Crypto_30_LibCv_GetKeyElementInfoOfPCConfig()[(Index)].LengthOfKeyElementInfo)
#define Crypto_30_LibCv_GetMaskedBitsOfKeyElementInfo(Index)                                        (Crypto_30_LibCv_GetKeyElementInfoOfPCConfig()[(Index)].MaskedBitsOfKeyElementInfo)
#define Crypto_30_LibCv_GetReadOfKeyElementInfo(Index)                                              (Crypto_30_LibCv_GetKeyElementInfoOfPCConfig()[(Index)].ReadOfKeyElementInfo)
#define Crypto_30_LibCv_GetWriteOfKeyElementInfo(Index)                                             (Crypto_30_LibCv_GetKeyElementInfoOfPCConfig()[(Index)].WriteOfKeyElementInfo)
#define Crypto_30_LibCv_GetIdOfKeyElements(Index)                                                   (Crypto_30_LibCv_GetKeyElementsOfPCConfig()[(Index)].IdOfKeyElements)
#define Crypto_30_LibCv_GetKeyElementInfoIdxOfKeyElements(Index)                                    (Crypto_30_LibCv_GetKeyElementsOfPCConfig()[(Index)].KeyElementInfoIdxOfKeyElements)
#define Crypto_30_LibCv_GetKeyStorageEndIdxOfKeyElements(Index)                                     (Crypto_30_LibCv_GetKeyElementsOfPCConfig()[(Index)].KeyStorageEndIdxOfKeyElements)
#define Crypto_30_LibCv_GetKeyStorageExtensionIdxOfKeyElements(Index)                               (Crypto_30_LibCv_GetKeyElementsOfPCConfig()[(Index)].KeyStorageExtensionIdxOfKeyElements)
#define Crypto_30_LibCv_GetKeyStorageStartIdxOfKeyElements(Index)                                   (Crypto_30_LibCv_GetKeyElementsOfPCConfig()[(Index)].KeyStorageStartIdxOfKeyElements)
#define Crypto_30_LibCv_GetKeyStorageValidIdxOfKeyElements(Index)                                   (Crypto_30_LibCv_GetKeyElementsOfPCConfig()[(Index)].KeyStorageValidIdxOfKeyElements)
#define Crypto_30_LibCv_GetKeyStorageWrittenLengthEndIdxOfKeyElements(Index)                        (Crypto_30_LibCv_GetKeyElementsOfPCConfig()[(Index)].KeyStorageWrittenLengthEndIdxOfKeyElements)
#define Crypto_30_LibCv_GetKeyStorageWrittenLengthStartIdxOfKeyElements(Index)                      (Crypto_30_LibCv_GetKeyElementsOfPCConfig()[(Index)].KeyStorageWrittenLengthStartIdxOfKeyElements)
#define Crypto_30_LibCv_GetWorkspaceOfKeyGenEd25519(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_KeyGenEd25519.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyGenP256R1(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP256R1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyGenP384R1(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP384R1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyGenSymGeneric(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSymGeneric.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetKeyLock(Index)                                                           (Crypto_30_LibCv_GetKeyLockOfPCConfig()[(Index)])
#define Crypto_30_LibCv_GetWorkspaceOfKeyP224R1BDPubVal(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP224R1BDSecret(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP256R1PubVal(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP256R1Secret(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP384R1PubVal(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP384R1Secret(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP521R1PubVal(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyP521R1Secret(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySeedDRBGAES(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGAES.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySeedDRBGHashSha512(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGHashSha512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySeedFips186(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_KeySeedFips186.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySetValid(Index)                                              /**< Deactivateable: 'Crypto_30_LibCv_KeySetValid.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySpake2PPubVal(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeySpake2PSecret(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetKeyStorage(Index)                                                        (Crypto_30_LibCv_GetKeyStorageOfPCConfig()[(Index)])
#define Crypto_30_LibCv_GetWorkspaceOfKeyX25519PubVal(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfKeyX25519Secret(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetFamilyOfLastJob(Index)                                                     /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_GetKeyIdOfLastJob(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_GetModeOfLastJob(Index)                                                       /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_GetLock(Index)                                                              (Crypto_30_LibCv_GetLockOfPCConfig()[(Index)])
#define Crypto_30_LibCv_GetLongTermWs(Index)                                                          /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetLongTermWsLock(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfMD5(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_MD5.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetConsistencyLevelOfNvBlock(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.ConsistencyLevel' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetCrcOfNvBlock(Index)                                                        /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Crc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetDescriptorOfNvBlock(Index)                                                 /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Descriptor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetIdOfNvBlock(Index)                                                         /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetKeyStorageEndIdxOfNvBlock(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.KeyStorageEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetKeyStorageStartIdxOfNvBlock(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.KeyStorageStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetLengthOfNvBlock(Index)                                                     /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetProcessingOfNvBlock(Index)                                                 /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Processing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetAEADChaChaPoly1305DecryptIdxOfObjectInfo(Index)                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AEADChaChaPoly1305DecryptIdx' Reason: 'the optional indirection is deactivated because AEADChaChaPoly1305DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsAEADChaChaPoly1305DecryptUsedOfObjectInfo(Index)                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AEADChaChaPoly1305DecryptUsed' Reason: 'the optional indirection is deactivated because AEADChaChaPoly1305DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetAEADChaChaPoly1305EncryptIdxOfObjectInfo(Index)                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AEADChaChaPoly1305EncryptIdx' Reason: 'the optional indirection is deactivated because AEADChaChaPoly1305EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsAEADChaChaPoly1305EncryptUsedOfObjectInfo(Index)                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AEADChaChaPoly1305EncryptUsed' Reason: 'the optional indirection is deactivated because AEADChaChaPoly1305EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetAesCcmDecryptIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmDecryptIdx' Reason: 'the optional indirection is deactivated because AesCcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsAesCcmDecryptUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmDecryptUsed' Reason: 'the optional indirection is deactivated because AesCcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetAesCcmEncryptIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmEncryptIdx' Reason: 'the optional indirection is deactivated because AesCcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsAesCcmEncryptUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmEncryptUsed' Reason: 'the optional indirection is deactivated because AesCcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetAesDecryptIdxOfObjectInfo(Index)                                         (Crypto_30_LibCv_GetObjectInfoOfPCConfig()[(Index)].AesDecryptIdxOfObjectInfo)
#define Crypto_30_LibCv_GetAesEncryptIdxOfObjectInfo(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesEncryptIdx' Reason: 'the optional indirection is deactivated because AesEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsAesEncryptUsedOfObjectInfo(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesEncryptUsed' Reason: 'the optional indirection is deactivated because AesEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetAesGcmDecryptIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesGcmDecryptIdx' Reason: 'the optional indirection is deactivated because AesGcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsAesGcmDecryptUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesGcmDecryptUsed' Reason: 'the optional indirection is deactivated because AesGcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetAesGcmEncryptIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesGcmEncryptIdx' Reason: 'the optional indirection is deactivated because AesGcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsAesGcmEncryptUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesGcmEncryptUsed' Reason: 'the optional indirection is deactivated because AesGcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetCmacAesGenerateIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.CmacAesGenerateIdx' Reason: 'the optional indirection is deactivated because CmacAesGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsCmacAesGenerateUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.CmacAesGenerateUsed' Reason: 'the optional indirection is deactivated because CmacAesGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetCmacAesVerifyIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.CmacAesVerifyIdx' Reason: 'the optional indirection is deactivated because CmacAesVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsCmacAesVerifyUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.CmacAesVerifyUsed' Reason: 'the optional indirection is deactivated because CmacAesVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetDRBGAESIdxOfObjectInfo(Index)                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGAESIdx' Reason: 'the optional indirection is deactivated because DRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsDRBGAESUsedOfObjectInfo(Index)                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGAESUsed' Reason: 'the optional indirection is deactivated because DRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetDRBGHashSha512IdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGHashSha512Idx' Reason: 'the optional indirection is deactivated because DRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsDRBGHashSha512UsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGHashSha512Used' Reason: 'the optional indirection is deactivated because DRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP160GenerateIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160GenerateIdx' Reason: 'the optional indirection is deactivated because EcP160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcP160GenerateUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160GenerateUsed' Reason: 'the optional indirection is deactivated because EcP160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP160VerifyIdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160VerifyIdx' Reason: 'the optional indirection is deactivated because EcP160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcP160VerifyUsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160VerifyUsed' Reason: 'the optional indirection is deactivated because EcP160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP256GenerateIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP256GenerateIdx' Reason: 'the optional indirection is deactivated because EcP256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcP256GenerateUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP256GenerateUsed' Reason: 'the optional indirection is deactivated because EcP256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP256VerifyIdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP256VerifyIdx' Reason: 'the optional indirection is deactivated because EcP256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcP256VerifyUsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP256VerifyUsed' Reason: 'the optional indirection is deactivated because EcP256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP384GenerateIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384GenerateIdx' Reason: 'the optional indirection is deactivated because EcP384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcP384GenerateUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384GenerateUsed' Reason: 'the optional indirection is deactivated because EcP384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP384VerifyIdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384VerifyIdx' Reason: 'the optional indirection is deactivated because EcP384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcP384VerifyUsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384VerifyUsed' Reason: 'the optional indirection is deactivated because EcP384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP521GenerateIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP521GenerateIdx' Reason: 'the optional indirection is deactivated because EcP521GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcP521GenerateUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP521GenerateUsed' Reason: 'the optional indirection is deactivated because EcP521GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEcP521VerifyIdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP521VerifyIdx' Reason: 'the optional indirection is deactivated because EcP521VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEcP521VerifyUsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP521VerifyUsed' Reason: 'the optional indirection is deactivated because EcP521VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEd25519GenerateIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed25519GenerateIdx' Reason: 'the optional indirection is deactivated because Ed25519GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsEd25519GenerateUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed25519GenerateUsed' Reason: 'the optional indirection is deactivated because Ed25519GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetEd25519VerifyIdxOfObjectInfo(Index)                                      (Crypto_30_LibCv_GetObjectInfoOfPCConfig()[(Index)].Ed25519VerifyIdxOfObjectInfo)
#define Crypto_30_LibCv_GetFips186IdxOfObjectInfo(Index)                                            (Crypto_30_LibCv_GetObjectInfoOfPCConfig()[(Index)].Fips186IdxOfObjectInfo)
#define Crypto_30_LibCv_GetGmacAesGenerateIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.GmacAesGenerateIdx' Reason: 'the optional indirection is deactivated because GmacAesGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsGmacAesGenerateUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.GmacAesGenerateUsed' Reason: 'the optional indirection is deactivated because GmacAesGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetGmacAesVerifyIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.GmacAesVerifyIdx' Reason: 'the optional indirection is deactivated because GmacAesVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsGmacAesVerifyUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.GmacAesVerifyUsed' Reason: 'the optional indirection is deactivated because GmacAesVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetHashIdxOfObjectInfo(Index)                                               (Crypto_30_LibCv_GetObjectInfoOfPCConfig()[(Index)].HashIdxOfObjectInfo)
#define Crypto_30_LibCv_GetHmacRipeMd160GenerateIdxOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160GenerateIdx' Reason: 'the optional indirection is deactivated because HmacRipeMd160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsHmacRipeMd160GenerateUsedOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160GenerateUsed' Reason: 'the optional indirection is deactivated because HmacRipeMd160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetHmacRipeMd160VerifyIdxOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160VerifyIdx' Reason: 'the optional indirection is deactivated because HmacRipeMd160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsHmacRipeMd160VerifyUsedOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160VerifyUsed' Reason: 'the optional indirection is deactivated because HmacRipeMd160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetHmacSha1GenerateIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha1GenerateIdx' Reason: 'the optional indirection is deactivated because HmacSha1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsHmacSha1GenerateUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha1GenerateUsed' Reason: 'the optional indirection is deactivated because HmacSha1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetHmacSha1VerifyIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha1VerifyIdx' Reason: 'the optional indirection is deactivated because HmacSha1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsHmacSha1VerifyUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha1VerifyUsed' Reason: 'the optional indirection is deactivated because HmacSha1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetHmacSha256GenerateIdxOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha256GenerateIdx' Reason: 'the optional indirection is deactivated because HmacSha256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsHmacSha256GenerateUsedOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha256GenerateUsed' Reason: 'the optional indirection is deactivated because HmacSha256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetHmacSha256VerifyIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha256VerifyIdx' Reason: 'the optional indirection is deactivated because HmacSha256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsHmacSha256VerifyUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha256VerifyUsed' Reason: 'the optional indirection is deactivated because HmacSha256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetHmacSha384GenerateIdxOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha384GenerateIdx' Reason: 'the optional indirection is deactivated because HmacSha384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsHmacSha384GenerateUsedOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha384GenerateUsed' Reason: 'the optional indirection is deactivated because HmacSha384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetHmacSha384VerifyIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha384VerifyIdx' Reason: 'the optional indirection is deactivated because HmacSha384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsHmacSha384VerifyUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha384VerifyUsed' Reason: 'the optional indirection is deactivated because HmacSha384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveHKDFHMACSHA256IdxOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHMACSHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveHKDFHMACSHA256UsedOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHMACSHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveHKDFHashOption1IdxOfObjectInfo(Index)                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1Idx' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveHKDFHashOption1UsedOfObjectInfo(Index)                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1Used' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveISO15118IdxOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveISO15118Idx' Reason: 'the optional indirection is deactivated because KeyDeriveISO15118UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveISO15118UsedOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveISO15118Used' Reason: 'the optional indirection is deactivated because KeyDeriveISO15118UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveKDF2HMACSHA1IdxOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA1Idx' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveKDF2HMACSHA1UsedOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA1Used' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveKDF2HMACSHA256IdxOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveKDF2HMACSHA256UsedOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveNist800108CntIdxOfObjectInfo(Index)                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist800108CntIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNist800108CntUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveNist800108CntUsedOfObjectInfo(Index)                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist800108CntUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNist800108CntUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveNist80056AOnePassIdxOfObjectInfo(Index)                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist80056AOnePassIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNist80056AOnePassUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveNist80056AOnePassUsedOfObjectInfo(Index)                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist80056AOnePassUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNist80056AOnePassUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveNistFips186ErbIdxOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNistFips186ErbIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNistFips186ErbUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveNistFips186ErbUsedOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNistFips186ErbUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNistFips186ErbUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveSpake2PIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveSpake2PIdx' Reason: 'the optional indirection is deactivated because KeyDeriveSpake2PUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveSpake2PUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveSpake2PUsed' Reason: 'the optional indirection is deactivated because KeyDeriveSpake2PUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveX963SHA256IdxOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveX963SHA256UsedOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyDeriveX963SHA512IdxOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA512Idx' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyDeriveX963SHA512UsedOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA512Used' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyGenEd25519IdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenEd25519Idx' Reason: 'the optional indirection is deactivated because KeyGenEd25519UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyGenEd25519UsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenEd25519Used' Reason: 'the optional indirection is deactivated because KeyGenEd25519UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyGenP256R1IdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP256R1Idx' Reason: 'the optional indirection is deactivated because KeyGenP256R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyGenP256R1UsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP256R1Used' Reason: 'the optional indirection is deactivated because KeyGenP256R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyGenP384R1IdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP384R1Idx' Reason: 'the optional indirection is deactivated because KeyGenP384R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyGenP384R1UsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP384R1Used' Reason: 'the optional indirection is deactivated because KeyGenP384R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyGenSymGenericIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSymGenericIdx' Reason: 'the optional indirection is deactivated because KeyGenSymGenericUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyGenSymGenericUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSymGenericUsed' Reason: 'the optional indirection is deactivated because KeyGenSymGenericUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP224R1BDPubValIdxOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDPubValIdx' Reason: 'the optional indirection is deactivated because KeyP224R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP224R1BDPubValUsedOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDPubValUsed' Reason: 'the optional indirection is deactivated because KeyP224R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP224R1BDSecretIdxOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDSecretIdx' Reason: 'the optional indirection is deactivated because KeyP224R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP224R1BDSecretUsedOfObjectInfo(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDSecretUsed' Reason: 'the optional indirection is deactivated because KeyP224R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP256R1PubValIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP256R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP256R1PubValUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP256R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP256R1SecretIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP256R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP256R1SecretUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP256R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP384R1PubValIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP384R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP384R1PubValUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP384R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP384R1SecretIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP384R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP384R1SecretUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP384R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP521R1PubValIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP521R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP521R1PubValUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP521R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyP521R1SecretIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP521R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyP521R1SecretUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP521R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySeedDRBGAESIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGAESIdx' Reason: 'the optional indirection is deactivated because KeySeedDRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySeedDRBGAESUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGAESUsed' Reason: 'the optional indirection is deactivated because KeySeedDRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySeedDRBGHashSha512IdxOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGHashSha512Idx' Reason: 'the optional indirection is deactivated because KeySeedDRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySeedDRBGHashSha512UsedOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGHashSha512Used' Reason: 'the optional indirection is deactivated because KeySeedDRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySeedFips186IdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedFips186Idx' Reason: 'the optional indirection is deactivated because KeySeedFips186UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySeedFips186UsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedFips186Used' Reason: 'the optional indirection is deactivated because KeySeedFips186UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySetValidIdxOfObjectInfo(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetValidIdx' Reason: 'the optional indirection is deactivated because KeySetValidUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySetValidUsedOfObjectInfo(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetValidUsed' Reason: 'the optional indirection is deactivated because KeySetValidUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySpake2PPubValIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PPubValIdx' Reason: 'the optional indirection is deactivated because KeySpake2PPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySpake2PPubValUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PPubValUsed' Reason: 'the optional indirection is deactivated because KeySpake2PPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeySpake2PSecretIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PSecretIdx' Reason: 'the optional indirection is deactivated because KeySpake2PSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeySpake2PSecretUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PSecretUsed' Reason: 'the optional indirection is deactivated because KeySpake2PSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyX25519PubValIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519PubValIdx' Reason: 'the optional indirection is deactivated because KeyX25519PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyX25519PubValUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519PubValUsed' Reason: 'the optional indirection is deactivated because KeyX25519PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetKeyX25519SecretIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519SecretIdx' Reason: 'the optional indirection is deactivated because KeyX25519SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsKeyX25519SecretUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519SecretUsed' Reason: 'the optional indirection is deactivated because KeyX25519SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetMD5IdxOfObjectInfo(Index)                                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.MD5Idx' Reason: 'the optional indirection is deactivated because MD5UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsMD5UsedOfObjectInfo(Index)                                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.MD5Used' Reason: 'the optional indirection is deactivated because MD5UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetQueueIdxOfObjectInfo(Index)                                              (Crypto_30_LibCv_GetObjectInfoOfPCConfig()[(Index)].QueueIdxOfObjectInfo)
#define Crypto_30_LibCv_GetRandomSeedBufferEndIdxOfObjectInfo(Index)                                (Crypto_30_LibCv_GetObjectInfoOfPCConfig()[(Index)].RandomSeedBufferEndIdxOfObjectInfo)
#define Crypto_30_LibCv_GetRandomSeedBufferStartIdxOfObjectInfo(Index)                              (Crypto_30_LibCv_GetObjectInfoOfPCConfig()[(Index)].RandomSeedBufferStartIdxOfObjectInfo)
#define Crypto_30_LibCv_GetRsaOaepCrtSha1DecryptIdxOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaOaepCrtSha1DecryptUsedOfObjectInfo(Index)                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaOaepCrtSha256DecryptIdxOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha256DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaOaepCrtSha256DecryptUsedOfObjectInfo(Index)                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha256DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaOaepSha1DecryptIdxOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaOaepSha1DecryptUsedOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaOaepSha1EncryptIdxOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1EncryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaOaepSha1EncryptUsedOfObjectInfo(Index)                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1EncryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaOaepSha256DecryptIdxOfObjectInfo(Index)                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaOaepSha256DecryptUsedOfObjectInfo(Index)                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaOaepSha256EncryptIdxOfObjectInfo(Index)                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256EncryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha256EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaOaepSha256EncryptUsedOfObjectInfo(Index)                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256EncryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha256EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPkcs1CrtGenerateIdxOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1CrtGenerateIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1CrtGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPkcs1CrtGenerateUsedOfObjectInfo(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1CrtGenerateUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1CrtGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPkcs1DecryptIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPkcs1DecryptUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPkcs1EncryptIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1EncryptIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPkcs1EncryptUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1EncryptUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPkcs1GenerateIdxOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1GenerateIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPkcs1GenerateUsedOfObjectInfo(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1GenerateUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPkcs1VerifyIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1VerifyIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPkcs1VerifyUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1VerifyUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPssGenerateIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssGenerateIdx' Reason: 'the optional indirection is deactivated because RsaPssGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPssGenerateUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssGenerateUsed' Reason: 'the optional indirection is deactivated because RsaPssGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetRsaPssVerifyIdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssVerifyIdx' Reason: 'the optional indirection is deactivated because RsaPssVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsRsaPssVerifyUsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssVerifyUsed' Reason: 'the optional indirection is deactivated because RsaPssVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetSheCmdGetIdIdxOfObjectInfo(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SheCmdGetIdIdx' Reason: 'the optional indirection is deactivated because SheCmdGetIdUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsSheCmdGetIdUsedOfObjectInfo(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SheCmdGetIdUsed' Reason: 'the optional indirection is deactivated because SheCmdGetIdUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetSipHashGenerateIdxOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashGenerateIdx' Reason: 'the optional indirection is deactivated because SipHashGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsSipHashGenerateUsedOfObjectInfo(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashGenerateUsed' Reason: 'the optional indirection is deactivated because SipHashGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetSipHashVerifyIdxOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashVerifyIdx' Reason: 'the optional indirection is deactivated because SipHashVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_IsSipHashVerifyUsedOfObjectInfo(Index)                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashVerifyUsed' Reason: 'the optional indirection is deactivated because SipHashVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_GetWorkspaceAddrOfObjectInfo(Index)                                         (Crypto_30_LibCv_GetObjectInfoOfPCConfig()[(Index)].WorkspaceAddrOfObjectInfo)
#define Crypto_30_LibCv_GetWorkspaceLengthOfObjectInfo(Index)                                       (Crypto_30_LibCv_GetObjectInfoOfPCConfig()[(Index)].WorkspaceLengthOfObjectInfo)
#define Crypto_30_LibCv_GetObjectInfoInd(Index)                                                     (Crypto_30_LibCv_GetObjectInfoIndOfPCConfig()[(Index)])
#define Crypto_30_LibCv_GetDispatchOfPrimitiveFct(Index)                                            (Crypto_30_LibCv_GetPrimitiveFctOfPCConfig()[(Index)].DispatchOfPrimitiveFct)
#define Crypto_30_LibCv_GetObjectInfoIndEndIdxOfPrimitiveFct(Index)                                 (Crypto_30_LibCv_GetPrimitiveFctOfPCConfig()[(Index)].ObjectInfoIndEndIdxOfPrimitiveFct)
#define Crypto_30_LibCv_GetObjectInfoIndStartIdxOfPrimitiveFct(Index)                               (Crypto_30_LibCv_GetPrimitiveFctOfPCConfig()[(Index)].ObjectInfoIndStartIdxOfPrimitiveFct)
#define Crypto_30_LibCv_GetCombinedOfPrimitiveInfo(Index)                                           (Crypto_30_LibCv_GetPrimitiveInfoOfPCConfig()[(Index)].CombinedOfPrimitiveInfo)
#define Crypto_30_LibCv_GetMaskedBitsOfPrimitiveInfo(Index)                                         (Crypto_30_LibCv_GetPrimitiveInfoOfPCConfig()[(Index)].MaskedBitsOfPrimitiveInfo)
#define Crypto_30_LibCv_GetPrimitiveFctIdxOfPrimitiveInfo(Index)                                    (Crypto_30_LibCv_GetPrimitiveInfoOfPCConfig()[(Index)].PrimitiveFctIdxOfPrimitiveInfo)
#define Crypto_30_LibCv_GetPrimitiveInfoEndIdxOfPrimitiveServiceInfo(Index)                         (Crypto_30_LibCv_GetPrimitiveServiceInfoOfPCConfig()[(Index)].PrimitiveInfoEndIdxOfPrimitiveServiceInfo)
#define Crypto_30_LibCv_GetPrimitiveInfoStartIdxOfPrimitiveServiceInfo(Index)                       (Crypto_30_LibCv_GetPrimitiveServiceInfoOfPCConfig()[(Index)].PrimitiveInfoStartIdxOfPrimitiveServiceInfo)
#define Crypto_30_LibCv_GetQueue(Index)                                                             (Crypto_30_LibCv_GetQueueOfPCConfig()[(Index)])
#define Crypto_30_LibCv_GetRandomSeedBuffer(Index)                                                  (Crypto_30_LibCv_GetRandomSeedBufferOfPCConfig()[(Index)])
#define Crypto_30_LibCv_GetWorkspaceOfRsaOaepCrtSha1Decrypt(Index)                                    /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaOaepCrtSha256Decrypt(Index)                                  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha256Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaOaepSha1Decrypt(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaOaepSha1Encrypt(Index)                                       /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaOaepSha256Decrypt(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaOaepSha256Encrypt(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPkcs1CrtGenerate(Index)                                      /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1CrtGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPkcs1Decrypt(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPkcs1Encrypt(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPkcs1Generate(Index)                                         /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPkcs1Verify(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPssGenerate(Index)                                           /**< Deactivateable: 'Crypto_30_LibCv_RsaPssGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfRsaPssVerify(Index)                                             /**< Deactivateable: 'Crypto_30_LibCv_RsaPssVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetLengthOfSaveAndRestoreWorkspace(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_GetWorkspaceOfSheCmdGetId(Index)                                              /**< Deactivateable: 'Crypto_30_LibCv_SheCmdGetId.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfSipHashGenerate(Index)                                          /**< Deactivateable: 'Crypto_30_LibCv_SipHashGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetWorkspaceOfSipHashVerify(Index)                                            /**< Deactivateable: 'Crypto_30_LibCv_SipHashVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv()                                                ((*(Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCvOfPCConfig())))
#define Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_Aes()                                            ((*(Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_AesOfPCConfig())))
#define Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_Rng()                                            ((*(Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_RngOfPCConfig())))
#define Crypto_30_LibCv_GetWrittenLength(Index)                                                     (Crypto_30_LibCv_GetWrittenLengthOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGetBitDataMacros  Crypto_30_LibCv Get Bit Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read bitcoded data elements.
  \{
*/ 
#define Crypto_30_LibCv_IsOnceOfKeyElementInfo(Index)                                               (CRYPTO_30_LIBCV_ONCEOFKEYELEMENTINFO_MASK == (Crypto_30_LibCv_GetMaskedBitsOfKeyElementInfo(Index) & CRYPTO_30_LIBCV_ONCEOFKEYELEMENTINFO_MASK))
#define Crypto_30_LibCv_IsPartialOfKeyElementInfo(Index)                                            (CRYPTO_30_LIBCV_PARTIALOFKEYELEMENTINFO_MASK == (Crypto_30_LibCv_GetMaskedBitsOfKeyElementInfo(Index) & CRYPTO_30_LIBCV_PARTIALOFKEYELEMENTINFO_MASK))
#define Crypto_30_LibCv_IsPersistOfKeyElementInfo(Index)                                            (CRYPTO_30_LIBCV_PERSISTOFKEYELEMENTINFO_MASK == (Crypto_30_LibCv_GetMaskedBitsOfKeyElementInfo(Index) & CRYPTO_30_LIBCV_PERSISTOFKEYELEMENTINFO_MASK))
#define Crypto_30_LibCv_IsContextOfPrimitiveInfo(Index)                                             (CRYPTO_30_LIBCV_CONTEXTOFPRIMITIVEINFO_MASK == (Crypto_30_LibCv_GetMaskedBitsOfPrimitiveInfo(Index) & CRYPTO_30_LIBCV_CONTEXTOFPRIMITIVEINFO_MASK))
#define Crypto_30_LibCv_IsDefaultRandomSourceOfPrimitiveInfo(Index)                                 (CRYPTO_30_LIBCV_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO_MASK == (Crypto_30_LibCv_GetMaskedBitsOfPrimitiveInfo(Index) & CRYPTO_30_LIBCV_DEFAULTRANDOMSOURCEOFPRIMITIVEINFO_MASK))
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGetDeduplicatedDataMacros  Crypto_30_LibCv Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Crypto_30_LibCv_IsAlignKeyStorageOfGeneral()                                                Crypto_30_LibCv_IsAlignKeyStorageOfGeneralOfPCConfig()
#define Crypto_30_LibCv_IsCmacAesRoundkeyReuseOfMacPrimitives()                                     Crypto_30_LibCv_IsCmacAesRoundkeyReuseOfMacPrimitivesOfPCConfig()
#define Crypto_30_LibCv_GetDefaultRandomMaxRetriesOfGeneral()                                       Crypto_30_LibCv_GetDefaultRandomMaxRetriesOfGeneralOfPCConfig()
#define Crypto_30_LibCv_IsEnableAES192OfCipherPrimitives()                                          Crypto_30_LibCv_IsEnableAES192OfCipherPrimitivesOfPCConfig()
#define Crypto_30_LibCv_IsEnableAES256OfCipherPrimitives()                                          Crypto_30_LibCv_IsEnableAES256OfCipherPrimitivesOfPCConfig()
#define Crypto_30_LibCv_GetExpectedCompatibilityVersion()                                             /**< Deactivateable: 'Crypto_30_LibCv_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_GetFinalMagicNumber()                                                         /**< Deactivateable: 'Crypto_30_LibCv_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_GetGeneratorCompatibilityVersion()                                            /**< Deactivateable: 'Crypto_30_LibCv_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_GetInitDataHashCode()                                                         /**< Deactivateable: 'Crypto_30_LibCv_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_IsKeyElementDeleteOfGeneral()                                               Crypto_30_LibCv_IsKeyElementDeleteOfGeneralOfPCConfig()
#define Crypto_30_LibCv_IsInitValueUsedOfKeyElementInfo(Index)                                      (((boolean)(Crypto_30_LibCv_GetInitValueStartIdxOfKeyElementInfo(Index) != CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Crypto_30_LibCv_InitValue */
#define Crypto_30_LibCv_GetKeyGenerateMaxLengthOfKeyGeneratePrimitives()                            Crypto_30_LibCv_GetKeyGenerateMaxLengthOfKeyGeneratePrimitivesOfPCConfig()
#define Crypto_30_LibCv_GetKeyValiditySetCalloutFctNameOfConfigurableCallouts()                       /**< Deactivateable: 'Crypto_30_LibCv_KeyValiditySetCalloutFctNameOfConfigurableCallouts' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_GetKeyValueChangedCalloutFctNameOfConfigurableCallouts()                      /**< Deactivateable: 'Crypto_30_LibCv_KeyValueChangedCalloutFctNameOfConfigurableCallouts' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_GetMainFunctionPeriodOfGeneral()                                            Crypto_30_LibCv_GetMainFunctionPeriodOfGeneralOfPCConfig()
#define Crypto_30_LibCv_GetNumberOfLongTermPrimitiveWorkspaceOfGeneral()                            Crypto_30_LibCv_GetNumberOfLongTermPrimitiveWorkspaceOfGeneralOfPCConfig()
#define Crypto_30_LibCv_IsNvMEnableSetRamBlockStatusOfGeneral()                                     Crypto_30_LibCv_IsNvMEnableSetRamBlockStatusOfGeneralOfPCConfig()
#define Crypto_30_LibCv_GetNvManagementDataPerKeyOfNvStorage()                                      Crypto_30_LibCv_GetNvManagementDataPerKeyOfNvStorageOfPCConfig()
#define Crypto_30_LibCv_GetNvWriteBlockFctNameOfNvStorage()                                         Crypto_30_LibCv_GetNvWriteBlockFctNameOfNvStorageOfPCConfig()
#define Crypto_30_LibCv_IsAesDecryptUsedOfObjectInfo(Index)                                         (((boolean)(Crypto_30_LibCv_GetAesDecryptIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_AesDecrypt */
#define Crypto_30_LibCv_IsEd25519VerifyUsedOfObjectInfo(Index)                                      (((boolean)(Crypto_30_LibCv_GetEd25519VerifyIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_Ed25519Verify */
#define Crypto_30_LibCv_IsFips186UsedOfObjectInfo(Index)                                            (((boolean)(Crypto_30_LibCv_GetFips186IdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_Fips186 */
#define Crypto_30_LibCv_IsHashUsedOfObjectInfo(Index)                                               (((boolean)(Crypto_30_LibCv_GetHashIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_HASHIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_LibCv_Hash */
#define Crypto_30_LibCv_IsRandomSeedBufferUsedOfObjectInfo(Index)                                   (((boolean)(Crypto_30_LibCv_GetRandomSeedBufferStartIdxOfObjectInfo(Index) != CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Crypto_30_LibCv_RandomSeedBuffer */
#define Crypto_30_LibCv_IsObjectInfoIndUsedOfPrimitiveFct(Index)                                    (((boolean)(Crypto_30_LibCv_GetObjectInfoIndStartIdxOfPrimitiveFct(Index) != CRYPTO_30_LIBCV_NO_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Crypto_30_LibCv_ObjectInfoInd */
#define Crypto_30_LibCv_IsPrimitiveInfoUsedOfPrimitiveServiceInfo(Index)                            (((boolean)(Crypto_30_LibCv_GetPrimitiveInfoStartIdxOfPrimitiveServiceInfo(Index) != CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Crypto_30_LibCv_PrimitiveInfo */
#define Crypto_30_LibCv_IsRedirectionOfGeneral()                                                    Crypto_30_LibCv_IsRedirectionOfGeneralOfPCConfig()
#define Crypto_30_LibCv_IsSheDebugCmdOfSheKeyUpdate()                                                 /**< Deactivateable: 'Crypto_30_LibCv_SheDebugCmdOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_IsSheEnableCounterOfSheKeyUpdate()                                            /**< Deactivateable: 'Crypto_30_LibCv_SheEnableCounterOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_IsSheEnableFidOfSheKeyUpdate()                                                /**< Deactivateable: 'Crypto_30_LibCv_SheEnableFidOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_GetSheInfoKeyRefOfSheKeyUpdate()                                              /**< Deactivateable: 'Crypto_30_LibCv_SheInfoKeyRefOfSheKeyUpdate' Reason: 'Reference is not configured!' */
#define Crypto_30_LibCv_GetSizeOfAesDecrypt()                                                       Crypto_30_LibCv_GetSizeOfAesDecryptOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfBufferLength()                                                     Crypto_30_LibCv_GetSizeOfBufferLengthOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfDriverObjectState()                                                Crypto_30_LibCv_GetSizeOfDriverObjectStateOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfEd25519Verify()                                                    Crypto_30_LibCv_GetSizeOfEd25519VerifyOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfFamilyToHashMapping()                                              Crypto_30_LibCv_GetSizeOfFamilyToHashMappingOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfFips186()                                                          Crypto_30_LibCv_GetSizeOfFips186OfPCConfig()
#define Crypto_30_LibCv_GetSizeOfHash()                                                             Crypto_30_LibCv_GetSizeOfHashOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfInitValue()                                                        Crypto_30_LibCv_GetSizeOfInitValueOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfKey()                                                              Crypto_30_LibCv_GetSizeOfKeyOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfKeyElementInfo()                                                   Crypto_30_LibCv_GetSizeOfKeyElementInfoOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfKeyElements()                                                      Crypto_30_LibCv_GetSizeOfKeyElementsOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfKeyLock()                                                          Crypto_30_LibCv_GetSizeOfKeyLockOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfKeyStorage()                                                       Crypto_30_LibCv_GetSizeOfKeyStorageOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfLock()                                                             Crypto_30_LibCv_GetSizeOfLockOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfObjectInfo()                                                       Crypto_30_LibCv_GetSizeOfObjectInfoOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfObjectInfoInd()                                                    Crypto_30_LibCv_GetSizeOfObjectInfoIndOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfPrimitiveFct()                                                     Crypto_30_LibCv_GetSizeOfPrimitiveFctOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfPrimitiveInfo()                                                    Crypto_30_LibCv_GetSizeOfPrimitiveInfoOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfPrimitiveServiceInfo()                                             Crypto_30_LibCv_GetSizeOfPrimitiveServiceInfoOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfQueue()                                                            Crypto_30_LibCv_GetSizeOfQueueOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfRandomSeedBuffer()                                                 Crypto_30_LibCv_GetSizeOfRandomSeedBufferOfPCConfig()
#define Crypto_30_LibCv_GetSizeOfWrittenLength()                                                    Crypto_30_LibCv_GetSizeOfWrittenLengthOfPCConfig()
#define Crypto_30_LibCv_IsStrictLengthCheckForKeyElementGetOfGeneral()                              Crypto_30_LibCv_IsStrictLengthCheckForKeyElementGetOfGeneralOfPCConfig()
#define Crypto_30_LibCv_IsUseVStdLibOfGeneral()                                                     Crypto_30_LibCv_IsUseVStdLibOfGeneralOfPCConfig()
#define Crypto_30_LibCv_IsVersionInfoApiOfGeneral()                                                 Crypto_30_LibCv_IsVersionInfoApiOfGeneralOfPCConfig()
#define Crypto_30_LibCv_GetWatchdogTriggerFunctionOfGeneral()                                       Crypto_30_LibCv_GetWatchdogTriggerFunctionOfGeneralOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCSetDataMacros  Crypto_30_LibCv Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Crypto_30_LibCv_SetBufferLength(Index, Value)                                               Crypto_30_LibCv_GetBufferLengthOfPCConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetDriverObjectState(Index, Value)                                          Crypto_30_LibCv_GetDriverObjectStateOfPCConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetKeyLock(Index, Value)                                                    Crypto_30_LibCv_GetKeyLockOfPCConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetKeyStorage(Index, Value)                                                 Crypto_30_LibCv_GetKeyStorageOfPCConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetFamilyOfLastJob(Index, Value)                                              /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_SetKeyIdOfLastJob(Index, Value)                                               /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_SetModeOfLastJob(Index, Value)                                                /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_SetLock(Index, Value)                                                       Crypto_30_LibCv_GetLockOfPCConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetLongTermWs(Index, Value)                                                   /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_SetLongTermWsLock(Index, Value)                                               /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_SetQueue(Index, Value)                                                      Crypto_30_LibCv_GetQueueOfPCConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetRandomSeedBuffer(Index, Value)                                           Crypto_30_LibCv_GetRandomSeedBufferOfPCConfig()[(Index)] = (Value)
#define Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(Index, Value)                              /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_SetUnionWS_Crypto_30_LibCv(Value)                                           (*(Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCvOfPCConfig())) = (Value)
#define Crypto_30_LibCv_SetUnionWS_Crypto_30_LibCv_Aes(Value)                                       (*(Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_AesOfPCConfig())) = (Value)
#define Crypto_30_LibCv_SetUnionWS_Crypto_30_LibCv_Rng(Value)                                       (*(Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_RngOfPCConfig())) = (Value)
#define Crypto_30_LibCv_SetWrittenLength(Index, Value)                                              Crypto_30_LibCv_GetWrittenLengthOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCGetAddressOfDataMacros  Crypto_30_LibCv Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Crypto_30_LibCv_GetAddrInitValue(Index)                                                     (&Crypto_30_LibCv_GetInitValue(Index))
#define Crypto_30_LibCv_GetAddrKeyStorage(Index)                                                    (&Crypto_30_LibCv_GetKeyStorage(Index))
#define Crypto_30_LibCv_GetAddrUnionWS_Crypto_30_LibCv()                                            (&Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv())
#define Crypto_30_LibCv_GetAddrUnionWS_Crypto_30_LibCv_Aes()                                        (&Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_Aes())
#define Crypto_30_LibCv_GetAddrUnionWS_Crypto_30_LibCv_Rng()                                        (&Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_Rng())
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCHasMacros  Crypto_30_LibCv Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Crypto_30_LibCv_HasAEADChaChaPoly1305Decrypt()                                                /**< Deactivateable: 'Crypto_30_LibCv_AEADChaChaPoly1305Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfAEADChaChaPoly1305Decrypt()                                     /**< Deactivateable: 'Crypto_30_LibCv_AEADChaChaPoly1305Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasAEADChaChaPoly1305Encrypt()                                                /**< Deactivateable: 'Crypto_30_LibCv_AEADChaChaPoly1305Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfAEADChaChaPoly1305Encrypt()                                     /**< Deactivateable: 'Crypto_30_LibCv_AEADChaChaPoly1305Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasAesCcmDecrypt()                                                            /**< Deactivateable: 'Crypto_30_LibCv_AesCcmDecrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfAesCcmDecrypt()                                                 /**< Deactivateable: 'Crypto_30_LibCv_AesCcmDecrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasAesCcmEncrypt()                                                            /**< Deactivateable: 'Crypto_30_LibCv_AesCcmEncrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfAesCcmEncrypt()                                                 /**< Deactivateable: 'Crypto_30_LibCv_AesCcmEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasAesDecrypt()                                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfAesDecrypt()                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesEncrypt()                                                               /**< Deactivateable: 'Crypto_30_LibCv_AesEncrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfAesEncrypt()                                                    /**< Deactivateable: 'Crypto_30_LibCv_AesEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasAesGcmDecrypt()                                                            /**< Deactivateable: 'Crypto_30_LibCv_AesGcmDecrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfAesGcmDecrypt()                                                 /**< Deactivateable: 'Crypto_30_LibCv_AesGcmDecrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasAesGcmEncrypt()                                                            /**< Deactivateable: 'Crypto_30_LibCv_AesGcmEncrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfAesGcmEncrypt()                                                 /**< Deactivateable: 'Crypto_30_LibCv_AesGcmEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasAlignKeyStorageOfGeneral()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasBufferLength()                                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasCmacAesGenerate()                                                          /**< Deactivateable: 'Crypto_30_LibCv_CmacAesGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfCmacAesGenerate()                                               /**< Deactivateable: 'Crypto_30_LibCv_CmacAesGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasCmacAesRoundkeyReuseOfMacPrimitives()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasCmacAesVerify()                                                            /**< Deactivateable: 'Crypto_30_LibCv_CmacAesVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfCmacAesVerify()                                                 /**< Deactivateable: 'Crypto_30_LibCv_CmacAesVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasDRBGAES()                                                                  /**< Deactivateable: 'Crypto_30_LibCv_DRBGAES' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfDRBGAES()                                                       /**< Deactivateable: 'Crypto_30_LibCv_DRBGAES.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasDRBGHashSha512()                                                           /**< Deactivateable: 'Crypto_30_LibCv_DRBGHashSha512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfDRBGHashSha512()                                                /**< Deactivateable: 'Crypto_30_LibCv_DRBGHashSha512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasDefaultRandomMaxRetriesOfGeneral()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasDriverObjectState()                                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasEcP160Generate()                                                           /**< Deactivateable: 'Crypto_30_LibCv_EcP160Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcP160Generate()                                                /**< Deactivateable: 'Crypto_30_LibCv_EcP160Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEcP160Verify()                                                             /**< Deactivateable: 'Crypto_30_LibCv_EcP160Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcP160Verify()                                                  /**< Deactivateable: 'Crypto_30_LibCv_EcP160Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEcP256Generate()                                                           /**< Deactivateable: 'Crypto_30_LibCv_EcP256Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcP256Generate()                                                /**< Deactivateable: 'Crypto_30_LibCv_EcP256Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEcP256Verify()                                                             /**< Deactivateable: 'Crypto_30_LibCv_EcP256Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcP256Verify()                                                  /**< Deactivateable: 'Crypto_30_LibCv_EcP256Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEcP384Generate()                                                           /**< Deactivateable: 'Crypto_30_LibCv_EcP384Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcP384Generate()                                                /**< Deactivateable: 'Crypto_30_LibCv_EcP384Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEcP384Verify()                                                             /**< Deactivateable: 'Crypto_30_LibCv_EcP384Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcP384Verify()                                                  /**< Deactivateable: 'Crypto_30_LibCv_EcP384Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEcP521Generate()                                                           /**< Deactivateable: 'Crypto_30_LibCv_EcP521Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcP521Generate()                                                /**< Deactivateable: 'Crypto_30_LibCv_EcP521Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEcP521Verify()                                                             /**< Deactivateable: 'Crypto_30_LibCv_EcP521Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEcP521Verify()                                                  /**< Deactivateable: 'Crypto_30_LibCv_EcP521Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEd25519Generate()                                                          /**< Deactivateable: 'Crypto_30_LibCv_Ed25519Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfEd25519Generate()                                               /**< Deactivateable: 'Crypto_30_LibCv_Ed25519Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasEd25519Verify()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfEd25519Verify()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasEnableAES192OfCipherPrimitives()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasEnableAES256OfCipherPrimitives()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasExpectedCompatibilityVersion()                                             /**< Deactivateable: 'Crypto_30_LibCv_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_HasFamilyToHashMapping()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasFinalMagicNumber()                                                         /**< Deactivateable: 'Crypto_30_LibCv_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_HasFips186()                                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfFips186()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasGeneratorCompatibilityVersion()                                            /**< Deactivateable: 'Crypto_30_LibCv_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_HasGmacAesGenerate()                                                          /**< Deactivateable: 'Crypto_30_LibCv_GmacAesGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfGmacAesGenerate()                                               /**< Deactivateable: 'Crypto_30_LibCv_GmacAesGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasGmacAesVerify()                                                            /**< Deactivateable: 'Crypto_30_LibCv_GmacAesVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfGmacAesVerify()                                                 /**< Deactivateable: 'Crypto_30_LibCv_GmacAesVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasHash()                                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceOfHash()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacRipeMd160Generate()                                                    /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfHmacRipeMd160Generate()                                         /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasHmacRipeMd160Verify()                                                      /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfHmacRipeMd160Verify()                                           /**< Deactivateable: 'Crypto_30_LibCv_HmacRipeMd160Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasHmacSha1Generate()                                                         /**< Deactivateable: 'Crypto_30_LibCv_HmacSha1Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha1Generate()                                              /**< Deactivateable: 'Crypto_30_LibCv_HmacSha1Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasHmacSha1Verify()                                                           /**< Deactivateable: 'Crypto_30_LibCv_HmacSha1Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha1Verify()                                                /**< Deactivateable: 'Crypto_30_LibCv_HmacSha1Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasHmacSha256Generate()                                                       /**< Deactivateable: 'Crypto_30_LibCv_HmacSha256Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha256Generate()                                            /**< Deactivateable: 'Crypto_30_LibCv_HmacSha256Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasHmacSha256Verify()                                                         /**< Deactivateable: 'Crypto_30_LibCv_HmacSha256Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha256Verify()                                              /**< Deactivateable: 'Crypto_30_LibCv_HmacSha256Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasHmacSha384Generate()                                                       /**< Deactivateable: 'Crypto_30_LibCv_HmacSha384Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha384Generate()                                            /**< Deactivateable: 'Crypto_30_LibCv_HmacSha384Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasHmacSha384Verify()                                                         /**< Deactivateable: 'Crypto_30_LibCv_HmacSha384Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfHmacSha384Verify()                                              /**< Deactivateable: 'Crypto_30_LibCv_HmacSha384Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasInitDataHashCode()                                                         /**< Deactivateable: 'Crypto_30_LibCv_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_HasInitValue()                                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasKey()                                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElementsEndIdxOfKey()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElementsStartIdxOfKey()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasNvBlockIdxOfKey()                                                          /**< Deactivateable: 'Crypto_30_LibCv_Key.NvBlockIdx' Reason: 'the optional indirection is deactivated because NvBlockUsedOfKey is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasNvBlockUsedOfKey()                                                         /**< Deactivateable: 'Crypto_30_LibCv_Key.NvBlockUsed' Reason: 'the optional indirection is deactivated because NvBlockUsedOfKey is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveHKDFHMACSHA256()                                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveHKDFHMACSHA256()                                       /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveHKDFHashOption1()                                                 /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveHKDFHashOption1()                                      /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveHKDFHashOption1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveISO15118()                                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveISO15118' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveISO15118()                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveISO15118.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveKDF2HMACSHA1()                                                    /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveKDF2HMACSHA1()                                         /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveKDF2HMACSHA256()                                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveKDF2HMACSHA256()                                       /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveKDF2HMACSHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveNist800108Cnt()                                                   /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist800108Cnt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveNist800108Cnt()                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist800108Cnt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveNist80056AOnePass()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist80056AOnePass' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveNist80056AOnePass()                                    /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNist80056AOnePass.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveNistFips186Erb()                                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNistFips186Erb' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveNistFips186Erb()                                       /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveNistFips186Erb.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveSpake2P()                                                         /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveSpake2P' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveSpake2P()                                              /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveSpake2P.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveX963SHA256()                                                      /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveX963SHA256()                                           /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyDeriveX963SHA512()                                                      /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyDeriveX963SHA512()                                           /**< Deactivateable: 'Crypto_30_LibCv_KeyDeriveX963SHA512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyElementDeleteOfGeneral()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElementInfo()                                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasIdOfKeyElementInfo()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasInitValueEndIdxOfKeyElementInfo()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasInitValueStartIdxOfKeyElementInfo()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasInitValueUsedOfKeyElementInfo()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasLengthOfKeyElementInfo()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasMaskedBitsOfKeyElementInfo()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasOnceOfKeyElementInfo()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasPartialOfKeyElementInfo()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasPersistOfKeyElementInfo()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasReadOfKeyElementInfo()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasWriteOfKeyElementInfo()                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElements()                                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasIdOfKeyElements()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElementInfoIdxOfKeyElements()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageEndIdxOfKeyElements()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageExtensionIdxOfKeyElements()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageStartIdxOfKeyElements()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageValidIdxOfKeyElements()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageWrittenLengthEndIdxOfKeyElements()                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageWrittenLengthStartIdxOfKeyElements()                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyGenEd25519()                                                            /**< Deactivateable: 'Crypto_30_LibCv_KeyGenEd25519' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyGenEd25519()                                                 /**< Deactivateable: 'Crypto_30_LibCv_KeyGenEd25519.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyGenP256R1()                                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP256R1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyGenP256R1()                                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP256R1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyGenP384R1()                                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP384R1' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyGenP384R1()                                                  /**< Deactivateable: 'Crypto_30_LibCv_KeyGenP384R1.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyGenSymGeneric()                                                         /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSymGeneric' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyGenSymGeneric()                                              /**< Deactivateable: 'Crypto_30_LibCv_KeyGenSymGeneric.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyGenerateMaxLengthOfKeyGeneratePrimitives()                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyLock()                                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyP224R1BDPubVal()                                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDPubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP224R1BDPubVal()                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP224R1BDSecret()                                                        /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDSecret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP224R1BDSecret()                                             /**< Deactivateable: 'Crypto_30_LibCv_KeyP224R1BDSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP256R1PubVal()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP256R1PubVal()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP256R1Secret()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP256R1Secret()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyP256R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP384R1PubVal()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP384R1PubVal()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP384R1Secret()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP384R1Secret()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyP384R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP521R1PubVal()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP521R1PubVal()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyP521R1Secret()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyP521R1Secret()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyP521R1Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySeedDRBGAES()                                                           /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGAES' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySeedDRBGAES()                                                /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGAES.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySeedDRBGHashSha512()                                                    /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGHashSha512' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySeedDRBGHashSha512()                                         /**< Deactivateable: 'Crypto_30_LibCv_KeySeedDRBGHashSha512.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySeedFips186()                                                           /**< Deactivateable: 'Crypto_30_LibCv_KeySeedFips186' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySeedFips186()                                                /**< Deactivateable: 'Crypto_30_LibCv_KeySeedFips186.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySetValid()                                                              /**< Deactivateable: 'Crypto_30_LibCv_KeySetValid' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySetValid()                                                   /**< Deactivateable: 'Crypto_30_LibCv_KeySetValid.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySpake2PPubVal()                                                         /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PPubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySpake2PPubVal()                                              /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PPubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeySpake2PSecret()                                                         /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PSecret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeySpake2PSecret()                                              /**< Deactivateable: 'Crypto_30_LibCv_KeySpake2PSecret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyStorage()                                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyValiditySetCalloutFctNameOfConfigurableCallouts()                       /**< Deactivateable: 'Crypto_30_LibCv_KeyValiditySetCalloutFctNameOfConfigurableCallouts' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_HasKeyValueChangedCalloutFctNameOfConfigurableCallouts()                      /**< Deactivateable: 'Crypto_30_LibCv_KeyValueChangedCalloutFctNameOfConfigurableCallouts' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_HasKeyX25519PubVal()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519PubVal' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyX25519PubVal()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519PubVal.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyX25519Secret()                                                          /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519Secret' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfKeyX25519Secret()                                               /**< Deactivateable: 'Crypto_30_LibCv_KeyX25519Secret.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasLastJob()                                                                  /**< Deactivateable: 'Crypto_30_LibCv_LastJob' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_HasFamilyOfLastJob()                                                          /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_HasKeyIdOfLastJob()                                                           /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_HasModeOfLastJob()                                                            /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_HasLock()                                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasLongTermWs()                                                               /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasLongTermWsLock()                                                           /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasMD5()                                                                      /**< Deactivateable: 'Crypto_30_LibCv_MD5' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfMD5()                                                           /**< Deactivateable: 'Crypto_30_LibCv_MD5.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasMainFunctionPeriodOfGeneral()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasNumberOfLongTermPrimitiveWorkspaceOfGeneral()                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasNvBlock()                                                                  /**< Deactivateable: 'Crypto_30_LibCv_NvBlock' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasConsistencyLevelOfNvBlock()                                                /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.ConsistencyLevel' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasCrcOfNvBlock()                                                             /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Crc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasDescriptorOfNvBlock()                                                      /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Descriptor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasIdOfNvBlock()                                                              /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyStorageEndIdxOfNvBlock()                                                /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.KeyStorageEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasKeyStorageStartIdxOfNvBlock()                                              /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.KeyStorageStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasLengthOfNvBlock()                                                          /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasProcessingOfNvBlock()                                                      /**< Deactivateable: 'Crypto_30_LibCv_NvBlock.Processing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasNvMEnableSetRamBlockStatusOfGeneral()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasNvManagementDataPerKeyOfNvStorage()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasNvWriteBlockFctNameOfNvStorage()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfo()                                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasAEADChaChaPoly1305DecryptIdxOfObjectInfo()                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AEADChaChaPoly1305DecryptIdx' Reason: 'the optional indirection is deactivated because AEADChaChaPoly1305DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAEADChaChaPoly1305DecryptUsedOfObjectInfo()                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AEADChaChaPoly1305DecryptUsed' Reason: 'the optional indirection is deactivated because AEADChaChaPoly1305DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAEADChaChaPoly1305EncryptIdxOfObjectInfo()                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AEADChaChaPoly1305EncryptIdx' Reason: 'the optional indirection is deactivated because AEADChaChaPoly1305EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAEADChaChaPoly1305EncryptUsedOfObjectInfo()                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AEADChaChaPoly1305EncryptUsed' Reason: 'the optional indirection is deactivated because AEADChaChaPoly1305EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesCcmDecryptIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmDecryptIdx' Reason: 'the optional indirection is deactivated because AesCcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesCcmDecryptUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmDecryptUsed' Reason: 'the optional indirection is deactivated because AesCcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesCcmEncryptIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmEncryptIdx' Reason: 'the optional indirection is deactivated because AesCcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesCcmEncryptUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesCcmEncryptUsed' Reason: 'the optional indirection is deactivated because AesCcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesDecryptIdxOfObjectInfo()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesDecryptUsedOfObjectInfo()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesEncryptIdxOfObjectInfo()                                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesEncryptIdx' Reason: 'the optional indirection is deactivated because AesEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesEncryptUsedOfObjectInfo()                                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesEncryptUsed' Reason: 'the optional indirection is deactivated because AesEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesGcmDecryptIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesGcmDecryptIdx' Reason: 'the optional indirection is deactivated because AesGcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesGcmDecryptUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesGcmDecryptUsed' Reason: 'the optional indirection is deactivated because AesGcmDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesGcmEncryptIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesGcmEncryptIdx' Reason: 'the optional indirection is deactivated because AesGcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasAesGcmEncryptUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.AesGcmEncryptUsed' Reason: 'the optional indirection is deactivated because AesGcmEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasCmacAesGenerateIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.CmacAesGenerateIdx' Reason: 'the optional indirection is deactivated because CmacAesGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasCmacAesGenerateUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.CmacAesGenerateUsed' Reason: 'the optional indirection is deactivated because CmacAesGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasCmacAesVerifyIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.CmacAesVerifyIdx' Reason: 'the optional indirection is deactivated because CmacAesVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasCmacAesVerifyUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.CmacAesVerifyUsed' Reason: 'the optional indirection is deactivated because CmacAesVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasDRBGAESIdxOfObjectInfo()                                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGAESIdx' Reason: 'the optional indirection is deactivated because DRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasDRBGAESUsedOfObjectInfo()                                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGAESUsed' Reason: 'the optional indirection is deactivated because DRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasDRBGHashSha512IdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGHashSha512Idx' Reason: 'the optional indirection is deactivated because DRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasDRBGHashSha512UsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.DRBGHashSha512Used' Reason: 'the optional indirection is deactivated because DRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP160GenerateIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160GenerateIdx' Reason: 'the optional indirection is deactivated because EcP160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP160GenerateUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160GenerateUsed' Reason: 'the optional indirection is deactivated because EcP160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP160VerifyIdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160VerifyIdx' Reason: 'the optional indirection is deactivated because EcP160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP160VerifyUsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP160VerifyUsed' Reason: 'the optional indirection is deactivated because EcP160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP256GenerateIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP256GenerateIdx' Reason: 'the optional indirection is deactivated because EcP256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP256GenerateUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP256GenerateUsed' Reason: 'the optional indirection is deactivated because EcP256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP256VerifyIdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP256VerifyIdx' Reason: 'the optional indirection is deactivated because EcP256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP256VerifyUsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP256VerifyUsed' Reason: 'the optional indirection is deactivated because EcP256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP384GenerateIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384GenerateIdx' Reason: 'the optional indirection is deactivated because EcP384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP384GenerateUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384GenerateUsed' Reason: 'the optional indirection is deactivated because EcP384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP384VerifyIdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384VerifyIdx' Reason: 'the optional indirection is deactivated because EcP384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP384VerifyUsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP384VerifyUsed' Reason: 'the optional indirection is deactivated because EcP384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP521GenerateIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP521GenerateIdx' Reason: 'the optional indirection is deactivated because EcP521GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP521GenerateUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP521GenerateUsed' Reason: 'the optional indirection is deactivated because EcP521GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP521VerifyIdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP521VerifyIdx' Reason: 'the optional indirection is deactivated because EcP521VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEcP521VerifyUsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.EcP521VerifyUsed' Reason: 'the optional indirection is deactivated because EcP521VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEd25519GenerateIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed25519GenerateIdx' Reason: 'the optional indirection is deactivated because Ed25519GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEd25519GenerateUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.Ed25519GenerateUsed' Reason: 'the optional indirection is deactivated because Ed25519GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasEd25519VerifyIdxOfObjectInfo()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasEd25519VerifyUsedOfObjectInfo()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasFips186IdxOfObjectInfo()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasFips186UsedOfObjectInfo()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasGmacAesGenerateIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.GmacAesGenerateIdx' Reason: 'the optional indirection is deactivated because GmacAesGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasGmacAesGenerateUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.GmacAesGenerateUsed' Reason: 'the optional indirection is deactivated because GmacAesGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasGmacAesVerifyIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.GmacAesVerifyIdx' Reason: 'the optional indirection is deactivated because GmacAesVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasGmacAesVerifyUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.GmacAesVerifyUsed' Reason: 'the optional indirection is deactivated because GmacAesVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHashIdxOfObjectInfo()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasHashUsedOfObjectInfo()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasHmacRipeMd160GenerateIdxOfObjectInfo()                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160GenerateIdx' Reason: 'the optional indirection is deactivated because HmacRipeMd160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacRipeMd160GenerateUsedOfObjectInfo()                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160GenerateUsed' Reason: 'the optional indirection is deactivated because HmacRipeMd160GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacRipeMd160VerifyIdxOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160VerifyIdx' Reason: 'the optional indirection is deactivated because HmacRipeMd160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacRipeMd160VerifyUsedOfObjectInfo()                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacRipeMd160VerifyUsed' Reason: 'the optional indirection is deactivated because HmacRipeMd160VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha1GenerateIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha1GenerateIdx' Reason: 'the optional indirection is deactivated because HmacSha1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha1GenerateUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha1GenerateUsed' Reason: 'the optional indirection is deactivated because HmacSha1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha1VerifyIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha1VerifyIdx' Reason: 'the optional indirection is deactivated because HmacSha1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha1VerifyUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha1VerifyUsed' Reason: 'the optional indirection is deactivated because HmacSha1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha256GenerateIdxOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha256GenerateIdx' Reason: 'the optional indirection is deactivated because HmacSha256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha256GenerateUsedOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha256GenerateUsed' Reason: 'the optional indirection is deactivated because HmacSha256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha256VerifyIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha256VerifyIdx' Reason: 'the optional indirection is deactivated because HmacSha256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha256VerifyUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha256VerifyUsed' Reason: 'the optional indirection is deactivated because HmacSha256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha384GenerateIdxOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha384GenerateIdx' Reason: 'the optional indirection is deactivated because HmacSha384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha384GenerateUsedOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha384GenerateUsed' Reason: 'the optional indirection is deactivated because HmacSha384GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha384VerifyIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha384VerifyIdx' Reason: 'the optional indirection is deactivated because HmacSha384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasHmacSha384VerifyUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.HmacSha384VerifyUsed' Reason: 'the optional indirection is deactivated because HmacSha384VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveHKDFHMACSHA256IdxOfObjectInfo()                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHMACSHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveHKDFHMACSHA256UsedOfObjectInfo()                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHMACSHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveHKDFHashOption1IdxOfObjectInfo()                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1Idx' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveHKDFHashOption1UsedOfObjectInfo()                                 /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveHKDFHashOption1Used' Reason: 'the optional indirection is deactivated because KeyDeriveHKDFHashOption1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveISO15118IdxOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveISO15118Idx' Reason: 'the optional indirection is deactivated because KeyDeriveISO15118UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveISO15118UsedOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveISO15118Used' Reason: 'the optional indirection is deactivated because KeyDeriveISO15118UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveKDF2HMACSHA1IdxOfObjectInfo()                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA1Idx' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveKDF2HMACSHA1UsedOfObjectInfo()                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA1Used' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveKDF2HMACSHA256IdxOfObjectInfo()                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveKDF2HMACSHA256UsedOfObjectInfo()                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveKDF2HMACSHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveKDF2HMACSHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveNist800108CntIdxOfObjectInfo()                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist800108CntIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNist800108CntUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveNist800108CntUsedOfObjectInfo()                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist800108CntUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNist800108CntUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveNist80056AOnePassIdxOfObjectInfo()                                /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist80056AOnePassIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNist80056AOnePassUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveNist80056AOnePassUsedOfObjectInfo()                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNist80056AOnePassUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNist80056AOnePassUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveNistFips186ErbIdxOfObjectInfo()                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNistFips186ErbIdx' Reason: 'the optional indirection is deactivated because KeyDeriveNistFips186ErbUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveNistFips186ErbUsedOfObjectInfo()                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveNistFips186ErbUsed' Reason: 'the optional indirection is deactivated because KeyDeriveNistFips186ErbUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveSpake2PIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveSpake2PIdx' Reason: 'the optional indirection is deactivated because KeyDeriveSpake2PUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveSpake2PUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveSpake2PUsed' Reason: 'the optional indirection is deactivated because KeyDeriveSpake2PUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveX963SHA256IdxOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA256Idx' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveX963SHA256UsedOfObjectInfo()                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA256Used' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveX963SHA512IdxOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA512Idx' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyDeriveX963SHA512UsedOfObjectInfo()                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyDeriveX963SHA512Used' Reason: 'the optional indirection is deactivated because KeyDeriveX963SHA512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenEd25519IdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenEd25519Idx' Reason: 'the optional indirection is deactivated because KeyGenEd25519UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenEd25519UsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenEd25519Used' Reason: 'the optional indirection is deactivated because KeyGenEd25519UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenP256R1IdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP256R1Idx' Reason: 'the optional indirection is deactivated because KeyGenP256R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenP256R1UsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP256R1Used' Reason: 'the optional indirection is deactivated because KeyGenP256R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenP384R1IdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP384R1Idx' Reason: 'the optional indirection is deactivated because KeyGenP384R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenP384R1UsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenP384R1Used' Reason: 'the optional indirection is deactivated because KeyGenP384R1UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenSymGenericIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSymGenericIdx' Reason: 'the optional indirection is deactivated because KeyGenSymGenericUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyGenSymGenericUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyGenSymGenericUsed' Reason: 'the optional indirection is deactivated because KeyGenSymGenericUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP224R1BDPubValIdxOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDPubValIdx' Reason: 'the optional indirection is deactivated because KeyP224R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP224R1BDPubValUsedOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDPubValUsed' Reason: 'the optional indirection is deactivated because KeyP224R1BDPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP224R1BDSecretIdxOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDSecretIdx' Reason: 'the optional indirection is deactivated because KeyP224R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP224R1BDSecretUsedOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP224R1BDSecretUsed' Reason: 'the optional indirection is deactivated because KeyP224R1BDSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP256R1PubValIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP256R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP256R1PubValUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP256R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP256R1SecretIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP256R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP256R1SecretUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP256R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP256R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP384R1PubValIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP384R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP384R1PubValUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP384R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP384R1SecretIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP384R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP384R1SecretUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP384R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP384R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP521R1PubValIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1PubValIdx' Reason: 'the optional indirection is deactivated because KeyP521R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP521R1PubValUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1PubValUsed' Reason: 'the optional indirection is deactivated because KeyP521R1PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP521R1SecretIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1SecretIdx' Reason: 'the optional indirection is deactivated because KeyP521R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyP521R1SecretUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyP521R1SecretUsed' Reason: 'the optional indirection is deactivated because KeyP521R1SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySeedDRBGAESIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGAESIdx' Reason: 'the optional indirection is deactivated because KeySeedDRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySeedDRBGAESUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGAESUsed' Reason: 'the optional indirection is deactivated because KeySeedDRBGAESUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySeedDRBGHashSha512IdxOfObjectInfo()                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGHashSha512Idx' Reason: 'the optional indirection is deactivated because KeySeedDRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySeedDRBGHashSha512UsedOfObjectInfo()                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedDRBGHashSha512Used' Reason: 'the optional indirection is deactivated because KeySeedDRBGHashSha512UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySeedFips186IdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedFips186Idx' Reason: 'the optional indirection is deactivated because KeySeedFips186UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySeedFips186UsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySeedFips186Used' Reason: 'the optional indirection is deactivated because KeySeedFips186UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySetValidIdxOfObjectInfo()                                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetValidIdx' Reason: 'the optional indirection is deactivated because KeySetValidUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySetValidUsedOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySetValidUsed' Reason: 'the optional indirection is deactivated because KeySetValidUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySpake2PPubValIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PPubValIdx' Reason: 'the optional indirection is deactivated because KeySpake2PPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySpake2PPubValUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PPubValUsed' Reason: 'the optional indirection is deactivated because KeySpake2PPubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySpake2PSecretIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PSecretIdx' Reason: 'the optional indirection is deactivated because KeySpake2PSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeySpake2PSecretUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeySpake2PSecretUsed' Reason: 'the optional indirection is deactivated because KeySpake2PSecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyX25519PubValIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519PubValIdx' Reason: 'the optional indirection is deactivated because KeyX25519PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyX25519PubValUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519PubValUsed' Reason: 'the optional indirection is deactivated because KeyX25519PubValUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyX25519SecretIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519SecretIdx' Reason: 'the optional indirection is deactivated because KeyX25519SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasKeyX25519SecretUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.KeyX25519SecretUsed' Reason: 'the optional indirection is deactivated because KeyX25519SecretUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasMD5IdxOfObjectInfo()                                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.MD5Idx' Reason: 'the optional indirection is deactivated because MD5UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasMD5UsedOfObjectInfo()                                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.MD5Used' Reason: 'the optional indirection is deactivated because MD5UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasQueueIdxOfObjectInfo()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasRandomSeedBufferEndIdxOfObjectInfo()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasRandomSeedBufferStartIdxOfObjectInfo()                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasRandomSeedBufferUsedOfObjectInfo()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasRsaOaepCrtSha1DecryptIdxOfObjectInfo()                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepCrtSha1DecryptUsedOfObjectInfo()                                    /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepCrtSha256DecryptIdxOfObjectInfo()                                   /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha256DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepCrtSha256DecryptUsedOfObjectInfo()                                  /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepCrtSha256DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepCrtSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha1DecryptIdxOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha1DecryptUsedOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha1EncryptIdxOfObjectInfo()                                        /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1EncryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha1EncryptUsedOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha1EncryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha256DecryptIdxOfObjectInfo()                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256DecryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha256DecryptUsedOfObjectInfo()                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256DecryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha256DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha256EncryptIdxOfObjectInfo()                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256EncryptIdx' Reason: 'the optional indirection is deactivated because RsaOaepSha256EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaOaepSha256EncryptUsedOfObjectInfo()                                     /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaOaepSha256EncryptUsed' Reason: 'the optional indirection is deactivated because RsaOaepSha256EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1CrtGenerateIdxOfObjectInfo()                                       /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1CrtGenerateIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1CrtGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1CrtGenerateUsedOfObjectInfo()                                      /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1CrtGenerateUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1CrtGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1DecryptIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1DecryptIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1DecryptUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1DecryptUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1DecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1EncryptIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1EncryptIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1EncryptUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1EncryptUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1EncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1GenerateIdxOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1GenerateIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1GenerateUsedOfObjectInfo()                                         /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1GenerateUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1VerifyIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1VerifyIdx' Reason: 'the optional indirection is deactivated because RsaPkcs1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPkcs1VerifyUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPkcs1VerifyUsed' Reason: 'the optional indirection is deactivated because RsaPkcs1VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPssGenerateIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssGenerateIdx' Reason: 'the optional indirection is deactivated because RsaPssGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPssGenerateUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssGenerateUsed' Reason: 'the optional indirection is deactivated because RsaPssGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPssVerifyIdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssVerifyIdx' Reason: 'the optional indirection is deactivated because RsaPssVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasRsaPssVerifyUsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.RsaPssVerifyUsed' Reason: 'the optional indirection is deactivated because RsaPssVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSheCmdGetIdIdxOfObjectInfo()                                               /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SheCmdGetIdIdx' Reason: 'the optional indirection is deactivated because SheCmdGetIdUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSheCmdGetIdUsedOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SheCmdGetIdUsed' Reason: 'the optional indirection is deactivated because SheCmdGetIdUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSipHashGenerateIdxOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashGenerateIdx' Reason: 'the optional indirection is deactivated because SipHashGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSipHashGenerateUsedOfObjectInfo()                                          /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashGenerateUsed' Reason: 'the optional indirection is deactivated because SipHashGenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSipHashVerifyIdxOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashVerifyIdx' Reason: 'the optional indirection is deactivated because SipHashVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasSipHashVerifyUsedOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_LibCv_ObjectInfo.SipHashVerifyUsed' Reason: 'the optional indirection is deactivated because SipHashVerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_LibCv_HasWorkspaceAddrOfObjectInfo()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasWorkspaceLengthOfObjectInfo()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfoInd()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveFct()                                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasDispatchOfPrimitiveFct()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfoIndEndIdxOfPrimitiveFct()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfoIndStartIdxOfPrimitiveFct()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfoIndUsedOfPrimitiveFct()                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveInfo()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasCombinedOfPrimitiveInfo()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasContextOfPrimitiveInfo()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasDefaultRandomSourceOfPrimitiveInfo()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasMaskedBitsOfPrimitiveInfo()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveFctIdxOfPrimitiveInfo()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveServiceInfo()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveInfoEndIdxOfPrimitiveServiceInfo()                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveInfoStartIdxOfPrimitiveServiceInfo()                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveInfoUsedOfPrimitiveServiceInfo()                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasQueue()                                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasRandomSeedBuffer()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasRedirectionOfGeneral()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasRsaOaepCrtSha1Decrypt()                                                    /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha1Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaOaepCrtSha1Decrypt()                                         /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaOaepCrtSha256Decrypt()                                                  /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha256Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaOaepCrtSha256Decrypt()                                       /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepCrtSha256Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaOaepSha1Decrypt()                                                       /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaOaepSha1Decrypt()                                            /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaOaepSha1Encrypt()                                                       /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaOaepSha1Encrypt()                                            /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha1Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaOaepSha256Decrypt()                                                     /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaOaepSha256Decrypt()                                          /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaOaepSha256Encrypt()                                                     /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaOaepSha256Encrypt()                                          /**< Deactivateable: 'Crypto_30_LibCv_RsaOaepSha256Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPkcs1CrtGenerate()                                                      /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1CrtGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPkcs1CrtGenerate()                                           /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1CrtGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPkcs1Decrypt()                                                          /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Decrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPkcs1Decrypt()                                               /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Decrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPkcs1Encrypt()                                                          /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Encrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPkcs1Encrypt()                                               /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Encrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPkcs1Generate()                                                         /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPkcs1Generate()                                              /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPkcs1Verify()                                                           /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPkcs1Verify()                                                /**< Deactivateable: 'Crypto_30_LibCv_RsaPkcs1Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPssGenerate()                                                           /**< Deactivateable: 'Crypto_30_LibCv_RsaPssGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPssGenerate()                                                /**< Deactivateable: 'Crypto_30_LibCv_RsaPssGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasRsaPssVerify()                                                             /**< Deactivateable: 'Crypto_30_LibCv_RsaPssVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfRsaPssVerify()                                                  /**< Deactivateable: 'Crypto_30_LibCv_RsaPssVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasSaveAndRestoreWorkspace()                                                  /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_HasLengthOfSaveAndRestoreWorkspace()                                          /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_HasSheCmdGetId()                                                              /**< Deactivateable: 'Crypto_30_LibCv_SheCmdGetId' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfSheCmdGetId()                                                   /**< Deactivateable: 'Crypto_30_LibCv_SheCmdGetId.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasSheDebugCmdOfSheKeyUpdate()                                                /**< Deactivateable: 'Crypto_30_LibCv_SheDebugCmdOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_HasSheEnableCounterOfSheKeyUpdate()                                           /**< Deactivateable: 'Crypto_30_LibCv_SheEnableCounterOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_HasSheEnableFidOfSheKeyUpdate()                                               /**< Deactivateable: 'Crypto_30_LibCv_SheEnableFidOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_HasSheInfoKeyRefOfSheKeyUpdate()                                              /**< Deactivateable: 'Crypto_30_LibCv_SheInfoKeyRefOfSheKeyUpdate' Reason: 'Reference is not configured!' */
#define Crypto_30_LibCv_HasSheKeys()                                                                  /**< Deactivateable: 'Crypto_30_LibCv_SheKeys' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasSipHashGenerate()                                                          /**< Deactivateable: 'Crypto_30_LibCv_SipHashGenerate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfSipHashGenerate()                                               /**< Deactivateable: 'Crypto_30_LibCv_SipHashGenerate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasSipHashVerify()                                                            /**< Deactivateable: 'Crypto_30_LibCv_SipHashVerify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_LibCv_HasWorkspaceOfSipHashVerify()                                                 /**< Deactivateable: 'Crypto_30_LibCv_SipHashVerify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_HasSizeOfAesDecrypt()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfBufferLength()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfDriverObjectState()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEd25519Verify()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfFamilyToHashMapping()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfFips186()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHash()                                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfInitValue()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKey()                                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyElementInfo()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyElements()                                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyLock()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyStorage()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfLock()                                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfObjectInfo()                                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfObjectInfoInd()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPrimitiveFct()                                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPrimitiveInfo()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPrimitiveServiceInfo()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfQueue()                                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfRandomSeedBuffer()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfWrittenLength()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasStrictLengthCheckForKeyElementGetOfGeneral()                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasUnionWS_Crypto_30_LibCv()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasUnionWS_Crypto_30_LibCv_Aes()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasUnionWS_Crypto_30_LibCv_Rng()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasUseVStdLibOfGeneral()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasVersionInfoApiOfGeneral()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasWatchdogTriggerFunctionOfGeneral()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasWrittenLength()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasPCConfig()                                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasAesDecryptOfPCConfig()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasAlignKeyStorageOfGeneralOfPCConfig()                                     (TRUE != FALSE)
#define Crypto_30_LibCv_HasBufferLengthOfPCConfig()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasCmacAesRoundkeyReuseOfMacPrimitivesOfPCConfig()                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasDefaultRandomMaxRetriesOfGeneralOfPCConfig()                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasDriverObjectStateOfPCConfig()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasEd25519VerifyOfPCConfig()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasEnableAES192OfCipherPrimitivesOfPCConfig()                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasEnableAES256OfCipherPrimitivesOfPCConfig()                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasExpectedCompatibilityVersionOfPCConfig()                                   /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_HasFamilyToHashMappingOfPCConfig()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasFinalMagicNumberOfPCConfig()                                               /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_HasFips186OfPCConfig()                                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasGeneratorCompatibilityVersionOfPCConfig()                                  /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_LibCv_HasHashOfPCConfig()                                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasInitDataHashCodeOfPCConfig()                                               /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_LibCv_HasInitValueOfPCConfig()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElementDeleteOfGeneralOfPCConfig()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElementInfoOfPCConfig()                                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyElementsOfPCConfig()                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyGenerateMaxLengthOfKeyGeneratePrimitivesOfPCConfig()                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyLockOfPCConfig()                                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyOfPCConfig()                                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyStorageOfPCConfig()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasKeyValiditySetCalloutFctNameOfConfigurableCalloutsOfPCConfig()             /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.KeyValiditySetCalloutFctNameOfConfigurableCallouts' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_HasKeyValueChangedCalloutFctNameOfConfigurableCalloutsOfPCConfig()            /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.KeyValueChangedCalloutFctNameOfConfigurableCallouts' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_HasLockOfPCConfig()                                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasMainFunctionPeriodOfGeneralOfPCConfig()                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasNumberOfLongTermPrimitiveWorkspaceOfGeneralOfPCConfig()                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasNvMEnableSetRamBlockStatusOfGeneralOfPCConfig()                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasNvManagementDataPerKeyOfNvStorageOfPCConfig()                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasNvWriteBlockFctNameOfNvStorageOfPCConfig()                               (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfoIndOfPCConfig()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasObjectInfoOfPCConfig()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveFctOfPCConfig()                                                 (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveInfoOfPCConfig()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasPrimitiveServiceInfoOfPCConfig()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasQueueOfPCConfig()                                                        (TRUE != FALSE)
#define Crypto_30_LibCv_HasRandomSeedBufferOfPCConfig()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasRedirectionOfGeneralOfPCConfig()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasSheDebugCmdOfSheKeyUpdateOfPCConfig()                                      /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.SheDebugCmdOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_HasSheEnableCounterOfSheKeyUpdateOfPCConfig()                                 /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.SheEnableCounterOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_HasSheEnableFidOfSheKeyUpdateOfPCConfig()                                     /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.SheEnableFidOfSheKeyUpdate' Reason: 'Parameter is not configured!' */
#define Crypto_30_LibCv_HasSheInfoKeyRefOfSheKeyUpdateOfPCConfig()                                    /**< Deactivateable: 'Crypto_30_LibCv_PCConfig.SheInfoKeyRefOfSheKeyUpdate' Reason: 'Reference is not configured!' */
#define Crypto_30_LibCv_HasSizeOfAesDecryptOfPCConfig()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfBufferLengthOfPCConfig()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfDriverObjectStateOfPCConfig()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfEd25519VerifyOfPCConfig()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfFamilyToHashMappingOfPCConfig()                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfFips186OfPCConfig()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfHashOfPCConfig()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfInitValueOfPCConfig()                                              (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyElementInfoOfPCConfig()                                         (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyElementsOfPCConfig()                                            (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyLockOfPCConfig()                                                (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyOfPCConfig()                                                    (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfKeyStorageOfPCConfig()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfLockOfPCConfig()                                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfObjectInfoIndOfPCConfig()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfObjectInfoOfPCConfig()                                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPrimitiveFctOfPCConfig()                                           (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPrimitiveInfoOfPCConfig()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfPrimitiveServiceInfoOfPCConfig()                                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfQueueOfPCConfig()                                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfRandomSeedBufferOfPCConfig()                                       (TRUE != FALSE)
#define Crypto_30_LibCv_HasSizeOfWrittenLengthOfPCConfig()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasStrictLengthCheckForKeyElementGetOfGeneralOfPCConfig()                   (TRUE != FALSE)
#define Crypto_30_LibCv_HasUnionWS_Crypto_30_LibCvOfPCConfig()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasUnionWS_Crypto_30_LibCv_AesOfPCConfig()                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasUnionWS_Crypto_30_LibCv_RngOfPCConfig()                                  (TRUE != FALSE)
#define Crypto_30_LibCv_HasUseVStdLibOfGeneralOfPCConfig()                                          (TRUE != FALSE)
#define Crypto_30_LibCv_HasVersionInfoApiOfGeneralOfPCConfig()                                      (TRUE != FALSE)
#define Crypto_30_LibCv_HasWatchdogTriggerFunctionOfGeneralOfPCConfig()                             (TRUE != FALSE)
#define Crypto_30_LibCv_HasWrittenLengthOfPCConfig()                                                (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCIncrementDataMacros  Crypto_30_LibCv Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_LibCv_IncBufferLength(Index)                                                      Crypto_30_LibCv_GetBufferLength(Index)++
#define Crypto_30_LibCv_IncDriverObjectState(Index)                                                 Crypto_30_LibCv_GetDriverObjectState(Index)++
#define Crypto_30_LibCv_IncKeyLock(Index)                                                           Crypto_30_LibCv_GetKeyLock(Index)++
#define Crypto_30_LibCv_IncKeyStorage(Index)                                                        Crypto_30_LibCv_GetKeyStorage(Index)++
#define Crypto_30_LibCv_IncFamilyOfLastJob(Index)                                                     /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_IncKeyIdOfLastJob(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_IncModeOfLastJob(Index)                                                       /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_IncLock(Index)                                                              Crypto_30_LibCv_GetLock(Index)++
#define Crypto_30_LibCv_IncLongTermWs(Index)                                                          /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_IncLongTermWsLock(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_IncQueue(Index)                                                             Crypto_30_LibCv_GetQueue(Index)++
#define Crypto_30_LibCv_IncRandomSeedBuffer(Index)                                                  Crypto_30_LibCv_GetRandomSeedBuffer(Index)++
#define Crypto_30_LibCv_IncLengthOfSaveAndRestoreWorkspace(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_IncUnionWS_Crypto_30_LibCv()                                                Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv()++
#define Crypto_30_LibCv_IncUnionWS_Crypto_30_LibCv_Aes()                                            Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_Aes()++
#define Crypto_30_LibCv_IncUnionWS_Crypto_30_LibCv_Rng()                                            Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_Rng()++
#define Crypto_30_LibCv_IncWrittenLength(Index)                                                     Crypto_30_LibCv_GetWrittenLength(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCDecrementDataMacros  Crypto_30_LibCv Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_LibCv_DecBufferLength(Index)                                                      Crypto_30_LibCv_GetBufferLength(Index)--
#define Crypto_30_LibCv_DecDriverObjectState(Index)                                                 Crypto_30_LibCv_GetDriverObjectState(Index)--
#define Crypto_30_LibCv_DecKeyLock(Index)                                                           Crypto_30_LibCv_GetKeyLock(Index)--
#define Crypto_30_LibCv_DecKeyStorage(Index)                                                        Crypto_30_LibCv_GetKeyStorage(Index)--
#define Crypto_30_LibCv_DecFamilyOfLastJob(Index)                                                     /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_DecKeyIdOfLastJob(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_DecModeOfLastJob(Index)                                                       /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_DecLock(Index)                                                              Crypto_30_LibCv_GetLock(Index)--
#define Crypto_30_LibCv_DecLongTermWs(Index)                                                          /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_DecLongTermWsLock(Index)                                                      /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_DecQueue(Index)                                                             Crypto_30_LibCv_GetQueue(Index)--
#define Crypto_30_LibCv_DecRandomSeedBuffer(Index)                                                  Crypto_30_LibCv_GetRandomSeedBuffer(Index)--
#define Crypto_30_LibCv_DecLengthOfSaveAndRestoreWorkspace(Index)                                     /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_DecUnionWS_Crypto_30_LibCv()                                                Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv()--
#define Crypto_30_LibCv_DecUnionWS_Crypto_30_LibCv_Aes()                                            Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_Aes()--
#define Crypto_30_LibCv_DecUnionWS_Crypto_30_LibCv_Rng()                                            Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_Rng()--
#define Crypto_30_LibCv_DecWrittenLength(Index)                                                     Crypto_30_LibCv_GetWrittenLength(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCAddDataMacros  Crypto_30_LibCv Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_LibCv_AddBufferLength(Index, Value)                                               Crypto_30_LibCv_SetBufferLength(Index, (Crypto_30_LibCv_GetBufferLength(Index) + Value))
#define Crypto_30_LibCv_AddDriverObjectState(Index, Value)                                          Crypto_30_LibCv_SetDriverObjectState(Index, (Crypto_30_LibCv_GetDriverObjectState(Index) + Value))
#define Crypto_30_LibCv_AddKeyLock(Index, Value)                                                    Crypto_30_LibCv_SetKeyLock(Index, (Crypto_30_LibCv_GetKeyLock(Index) + Value))
#define Crypto_30_LibCv_AddKeyStorage(Index, Value)                                                 Crypto_30_LibCv_SetKeyStorage(Index, (Crypto_30_LibCv_GetKeyStorage(Index) + Value))
#define Crypto_30_LibCv_AddFamilyOfLastJob(Index, Value)                                              /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_AddKeyIdOfLastJob(Index, Value)                                               /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_AddModeOfLastJob(Index, Value)                                                /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_AddLock(Index, Value)                                                       Crypto_30_LibCv_SetLock(Index, (Crypto_30_LibCv_GetLock(Index) + Value))
#define Crypto_30_LibCv_AddLongTermWs(Index, Value)                                                   /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_AddLongTermWsLock(Index, Value)                                               /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_AddQueue(Index, Value)                                                      Crypto_30_LibCv_SetQueue(Index, (Crypto_30_LibCv_GetQueue(Index) + Value))
#define Crypto_30_LibCv_AddRandomSeedBuffer(Index, Value)                                           Crypto_30_LibCv_SetRandomSeedBuffer(Index, (Crypto_30_LibCv_GetRandomSeedBuffer(Index) + Value))
#define Crypto_30_LibCv_AddLengthOfSaveAndRestoreWorkspace(Index, Value)                              /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_AddUnionWS_Crypto_30_LibCv(Value)                                           Crypto_30_LibCv_SetUnionWS_Crypto_30_LibCv((Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv() + Value))
#define Crypto_30_LibCv_AddUnionWS_Crypto_30_LibCv_Aes(Value)                                       Crypto_30_LibCv_SetUnionWS_Crypto_30_LibCv_Aes((Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_Aes() + Value))
#define Crypto_30_LibCv_AddUnionWS_Crypto_30_LibCv_Rng(Value)                                       Crypto_30_LibCv_SetUnionWS_Crypto_30_LibCv_Rng((Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_Rng() + Value))
#define Crypto_30_LibCv_AddWrittenLength(Index, Value)                                              Crypto_30_LibCv_SetWrittenLength(Index, (Crypto_30_LibCv_GetWrittenLength(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCSubstractDataMacros  Crypto_30_LibCv Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_LibCv_SubBufferLength(Index, Value)                                               Crypto_30_LibCv_SetBufferLength(Index, (Crypto_30_LibCv_GetBufferLength(Index) - Value))
#define Crypto_30_LibCv_SubDriverObjectState(Index, Value)                                          Crypto_30_LibCv_SetDriverObjectState(Index, (Crypto_30_LibCv_GetDriverObjectState(Index) - Value))
#define Crypto_30_LibCv_SubKeyLock(Index, Value)                                                    Crypto_30_LibCv_SetKeyLock(Index, (Crypto_30_LibCv_GetKeyLock(Index) - Value))
#define Crypto_30_LibCv_SubKeyStorage(Index, Value)                                                 Crypto_30_LibCv_SetKeyStorage(Index, (Crypto_30_LibCv_GetKeyStorage(Index) - Value))
#define Crypto_30_LibCv_SubFamilyOfLastJob(Index, Value)                                              /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Family' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_SubKeyIdOfLastJob(Index, Value)                                               /**< Deactivateable: 'Crypto_30_LibCv_LastJob.KeyId' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_SubModeOfLastJob(Index, Value)                                                /**< Deactivateable: 'Crypto_30_LibCv_LastJob.Mode' Reason: '/ActiveEcuC/Crypto/CryptoGeneral/CryptoMacPrimitives[0:CryptoCmacAesRoundkeyReuse] is configured to 'false'' */
#define Crypto_30_LibCv_SubLock(Index, Value)                                                       Crypto_30_LibCv_SetLock(Index, (Crypto_30_LibCv_GetLock(Index) - Value))
#define Crypto_30_LibCv_SubLongTermWs(Index, Value)                                                   /**< Deactivateable: 'Crypto_30_LibCv_LongTermWs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_SubLongTermWsLock(Index, Value)                                               /**< Deactivateable: 'Crypto_30_LibCv_LongTermWsLock' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_LibCv_SubQueue(Index, Value)                                                      Crypto_30_LibCv_SetQueue(Index, (Crypto_30_LibCv_GetQueue(Index) - Value))
#define Crypto_30_LibCv_SubRandomSeedBuffer(Index, Value)                                           Crypto_30_LibCv_SetRandomSeedBuffer(Index, (Crypto_30_LibCv_GetRandomSeedBuffer(Index) - Value))
#define Crypto_30_LibCv_SubLengthOfSaveAndRestoreWorkspace(Index, Value)                              /**< Deactivateable: 'Crypto_30_LibCv_SaveAndRestoreWorkspace.Length' Reason: 'Disable Feature if no Context primitive is used' */
#define Crypto_30_LibCv_SubUnionWS_Crypto_30_LibCv(Value)                                           Crypto_30_LibCv_SetUnionWS_Crypto_30_LibCv((Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv() - Value))
#define Crypto_30_LibCv_SubUnionWS_Crypto_30_LibCv_Aes(Value)                                       Crypto_30_LibCv_SetUnionWS_Crypto_30_LibCv_Aes((Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_Aes() - Value))
#define Crypto_30_LibCv_SubUnionWS_Crypto_30_LibCv_Rng(Value)                                       Crypto_30_LibCv_SetUnionWS_Crypto_30_LibCv_Rng((Crypto_30_LibCv_GetUnionWS_Crypto_30_LibCv_Rng() - Value))
#define Crypto_30_LibCv_SubWrittenLength(Index, Value)                                              Crypto_30_LibCv_SetWrittenLength(Index, (Crypto_30_LibCv_GetWrittenLength(Index) - Value))
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
  \defgroup  Crypto_30_LibCvPBGetRootDataMacros  Crypto_30_LibCv Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Crypto_30_LibCv_GetLTConfigIdxOfPBConfig()                                                    /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_LibCv_GetPCConfigIdxOfPBConfig()                                                    /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPBHasMacros  Crypto_30_LibCv Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Crypto_30_LibCv_HasPBConfig()                                                                 /**< Deactivateable: 'Crypto_30_LibCv_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_LibCv_HasLTConfigIdxOfPBConfig()                                                    /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_LibCv_HasPCConfigIdxOfPBConfig()                                                    /**< Deactivateable: 'Crypto_30_LibCv_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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




/* PRQA S 3453 LOCKMACROS_3453 */  /* MD_CSL_3453 */
#define Crypto_30_LibCv_FreeLock(lockIdx) Crypto_30_LibCv_SetLock((lockIdx), 0xFFFFFFFFUL)
#define Crypto_30_LibCv_IsLockFree(lockIdx) (Crypto_30_LibCv_GetLock((lockIdx))) == 0xFFFFFFFFUL
#define Crypto_30_LibCv_IsLockOccupiedByJob(lockIdx, jobId) (Crypto_30_LibCv_GetLock((lockIdx))) == (jobId)
/* PRQA L:LOCKMACROS_3453 */


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/** Elliptic Curve workspace buffer type */
typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  eslt_WorkSpaceEcP wsEcP;
  vSecPrimType_WorkSpaceHash wsPreHash;
} Crypto_30_LibCv_WorkSpaceEcP;

/** AES workspace union type */
typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  eslt_WorkSpaceAES128 wsAES128;
} Crypto_30_LibCv_WorkSpaceAESSubType;

/** AES workspace struct type */
typedef struct
{
  uint8 mode;
  Crypto_30_LibCv_WorkSpaceAESSubType wsAES;
} Crypto_30_LibCv_WorkSpaceAES;

/** CMAC AES workspace struct type */
typedef struct
{
  uint8 mode;
  eslt_WorkSpaceCMACAES wsCMACAES;
} Crypto_30_LibCv_WorkSpaceCMACAES;

/** KDF ISO15118 workspace buffer type */
typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  eslt_WorkSpaceEcP wsEcP;
  eslt_WorkSpaceSHA256 wsSHA256;
  eslt_WorkSpaceAES128 wsAes;
} Crypto_30_LibCv_WorkSpaceISO15118;

/** RSA PSS workspace struct type */
typedef struct
{
  uint32 saltLength;
  eslt_WorkSpaceRSAPSSver wsRsa;
} Crypto_30_LibCv_WorkSpaceRsaPssVer;

/** RSA Decrypt struct type */
typedef struct
{
  uint8 decryptionMode;
  eslt_WorkSpaceRSAdec wsRsa;
} Crypto_30_LibCv_WorkSpaceRsaDecrypt;


typedef uint8 Crypto_30_LibCv_WorkSpaceKeySetValid; /* No Workspace Required */

typedef uint8 Crypto_30_LibCv_WorkSpaceKeyGenerateSymmetric;  /* No Workspace Required */

typedef P2FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE, Crypto_30_LibCv_DispatchFctPtrType)(uint32 objectId, P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,  Crypto_OperationModeType mode);

typedef P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) Crypto_30_LibCv_SaveAndRestoreWorkspaceAddressType;

typedef P2VAR(Crypto_JobType, TYPEDEF, CRYPTO_30_LIBCV_APPL_VAR) Crypto_30_LibCv_JobPtrType;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  vSecPrimType_WorkSpaceHash Hash;
  eslt_WorkSpaceFIPS186 Fips186;
  eslt_WorkSpaceEd25519 Ed25519Verify;
} Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Type;

typedef struct sCrypto_30_LibCv_WS_Crypto_30_LibCv_Type
{
#if (CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Type primWS;
} Crypto_30_LibCv_WS_Crypto_30_LibCv_Type;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  Crypto_30_LibCv_WorkSpaceAES AesDecrypt;
} Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes_Type;

typedef struct sCrypto_30_LibCv_WS_Crypto_30_LibCv_Aes_Type
{
#if (CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes_Type primWS;
} Crypto_30_LibCv_WS_Crypto_30_LibCv_Aes_Type;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_18.4 */
  eslt_WorkSpaceFIPS186 Fips186;
} Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng_Type;

typedef struct sCrypto_30_LibCv_WS_Crypto_30_LibCv_Rng_Type
{
#if (CRYPTO_30_LIBCV_SAVEANDRESTOREWORKSPACE == STD_ON)
  uint8 settings[8];
#endif
  Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng_Type primWS;
} Crypto_30_LibCv_WS_Crypto_30_LibCv_Rng_Type;

typedef P2VAR(vSecPrimType_WorkSpaceHash, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_vSecPrimType_WorkSpaceHash_PtrType;
typedef P2VAR(eslt_WorkSpaceFIPS186, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceFIPS186_PtrType;
typedef P2VAR(eslt_WorkSpaceEd25519, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_eslt_WorkSpaceEd25519_PtrType;
typedef P2VAR(Crypto_30_LibCv_WorkSpaceAES, CRYPTO_30_LIBCV_CONST, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceAES_PtrType;


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_LibCvPCIterableTypes  Crypto_30_LibCv Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Crypto_30_LibCv_AesDecrypt */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfAesDecrypt() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_AesDecryptIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Ed25519Verify */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfEd25519Verify() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_Ed25519VerifyIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_FamilyToHashMapping */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfFamilyToHashMapping() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_FamilyToHashMappingIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Fips186 */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfFips186() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_Fips186IterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Hash */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfHash() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_HashIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_InitValue */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfInitValue() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_InitValueIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Key */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKey() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_KeyIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyElementInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyElementInfo() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_KeyElementInfoIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyElements */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyElements() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_KeyElementsIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyStorage */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyStorage() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_KeyStorageIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_ObjectInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfObjectInfo() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_ObjectInfoIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_ObjectInfoInd */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfObjectInfoInd() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_ObjectInfoIndIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_PrimitiveFct */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfPrimitiveFct() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_PrimitiveFctIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_PrimitiveInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfPrimitiveInfo() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_PrimitiveInfoIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_PrimitiveServiceInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfPrimitiveServiceInfo() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_PrimitiveServiceInfoIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Queue */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfQueue() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_QueueIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_RandomSeedBuffer */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfRandomSeedBuffer() } \endspec */ 
typedef uint8_least Crypto_30_LibCv_RandomSeedBufferIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCIterableTypesWithSizeRelations  Crypto_30_LibCv Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Crypto_30_LibCv_BufferLength */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfBufferLength() } \endspec */ 
typedef Crypto_30_LibCv_ObjectInfoIterType Crypto_30_LibCv_BufferLengthIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_DriverObjectState */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfDriverObjectState() } \endspec */ 
typedef Crypto_30_LibCv_ObjectInfoIterType Crypto_30_LibCv_DriverObjectStateIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_KeyLock */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyLock() } \endspec */ 
typedef Crypto_30_LibCv_KeyIterType Crypto_30_LibCv_KeyLockIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_Lock */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfLock() } \endspec */ 
typedef Crypto_30_LibCv_ObjectInfoIterType Crypto_30_LibCv_LockIterType;

/**   \brief  type used to iterate Crypto_30_LibCv_WrittenLength */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfWrittenLength() } \endspec */ 
typedef Crypto_30_LibCv_ObjectInfoIterType Crypto_30_LibCv_WrittenLengthIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCValueTypes  Crypto_30_LibCv Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Crypto_30_LibCv_AlignKeyStorageOfGeneral */
typedef boolean Crypto_30_LibCv_AlignKeyStorageOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_BufferLength */
typedef uint32 Crypto_30_LibCv_BufferLengthType;

/**   \brief  value based type definition for Crypto_30_LibCv_CmacAesRoundkeyReuseOfMacPrimitives */
typedef boolean Crypto_30_LibCv_CmacAesRoundkeyReuseOfMacPrimitivesType;

/**   \brief  value based type definition for Crypto_30_LibCv_DefaultRandomMaxRetriesOfGeneral */
typedef uint8 Crypto_30_LibCv_DefaultRandomMaxRetriesOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_DriverObjectState */
typedef uint8 Crypto_30_LibCv_DriverObjectStateType;

/**   \brief  value based type definition for Crypto_30_LibCv_EnableAES192OfCipherPrimitives */
typedef boolean Crypto_30_LibCv_EnableAES192OfCipherPrimitivesType;

/**   \brief  value based type definition for Crypto_30_LibCv_EnableAES256OfCipherPrimitives */
typedef boolean Crypto_30_LibCv_EnableAES256OfCipherPrimitivesType;

/**   \brief  value based type definition for Crypto_30_LibCv_FamilyToHashMapping */
typedef uint8 Crypto_30_LibCv_FamilyToHashMappingType;

/**   \brief  value based type definition for Crypto_30_LibCv_InitValue */
typedef uint8 Crypto_30_LibCv_InitValueType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyElementsEndIdxOfKey */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyElements() } \endspec */ 
typedef uint8 Crypto_30_LibCv_KeyElementsEndIdxOfKeyType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyElementsStartIdxOfKey */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyElements() } \endspec */ 
typedef uint8 Crypto_30_LibCv_KeyElementsStartIdxOfKeyType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyElementDeleteOfGeneral */
typedef boolean Crypto_30_LibCv_KeyElementDeleteOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_IdOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_IdOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_InitValueEndIdxOfKeyElementInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfInitValue() } \endspec */ 
typedef uint8 Crypto_30_LibCv_InitValueEndIdxOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_InitValueStartIdxOfKeyElementInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfInitValue() } \endspec */ 
typedef uint8 Crypto_30_LibCv_InitValueStartIdxOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_InitValueUsedOfKeyElementInfo */
typedef boolean Crypto_30_LibCv_InitValueUsedOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_LengthOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_LengthOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_MaskedBitsOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_MaskedBitsOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_OnceOfKeyElementInfo */
typedef boolean Crypto_30_LibCv_OnceOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PartialOfKeyElementInfo */
typedef boolean Crypto_30_LibCv_PartialOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PersistOfKeyElementInfo */
typedef boolean Crypto_30_LibCv_PersistOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_ReadOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_ReadOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_WriteOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_WriteOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_IdOfKeyElements */
typedef uint8 Crypto_30_LibCv_IdOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyElementInfoIdxOfKeyElements */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyElementInfo() } \endspec */ 
typedef uint8 Crypto_30_LibCv_KeyElementInfoIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageEndIdxOfKeyElements */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyStorage() } \endspec */ 
typedef uint8 Crypto_30_LibCv_KeyStorageEndIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageExtensionIdxOfKeyElements */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyStorage() } \endspec */ 
typedef uint8 Crypto_30_LibCv_KeyStorageExtensionIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageStartIdxOfKeyElements */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyStorage() } \endspec */ 
typedef uint8 Crypto_30_LibCv_KeyStorageStartIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageValidIdxOfKeyElements */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyStorage() } \endspec */ 
typedef uint8 Crypto_30_LibCv_KeyStorageValidIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageWrittenLengthEndIdxOfKeyElements */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyStorage() } \endspec */ 
typedef uint8 Crypto_30_LibCv_KeyStorageWrittenLengthEndIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorageWrittenLengthStartIdxOfKeyElements */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfKeyStorage() } \endspec */ 
typedef uint8 Crypto_30_LibCv_KeyStorageWrittenLengthStartIdxOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyGenerateMaxLengthOfKeyGeneratePrimitives */
typedef uint8 Crypto_30_LibCv_KeyGenerateMaxLengthOfKeyGeneratePrimitivesType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyLock */
typedef uint8 Crypto_30_LibCv_KeyLockType;

/**   \brief  value based type definition for Crypto_30_LibCv_KeyStorage */
typedef uint8 Crypto_30_LibCv_KeyStorageType;

/**   \brief  value based type definition for Crypto_30_LibCv_Lock */
typedef uint32 Crypto_30_LibCv_LockType;

/**   \brief  value based type definition for Crypto_30_LibCv_MainFunctionPeriodOfGeneral */
typedef uint8 Crypto_30_LibCv_MainFunctionPeriodOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_NumberOfLongTermPrimitiveWorkspaceOfGeneral */
typedef uint8 Crypto_30_LibCv_NumberOfLongTermPrimitiveWorkspaceOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_NvMEnableSetRamBlockStatusOfGeneral */
typedef boolean Crypto_30_LibCv_NvMEnableSetRamBlockStatusOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_NvManagementDataPerKeyOfNvStorage */
typedef uint8 Crypto_30_LibCv_NvManagementDataPerKeyOfNvStorageType;

/**   \brief  value based type definition for Crypto_30_LibCv_NvWriteBlockFctNameOfNvStorage */
typedef uint32 Crypto_30_LibCv_NvWriteBlockFctNameOfNvStorageType;

/**   \brief  value based type definition for Crypto_30_LibCv_AesDecryptIdxOfObjectInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfAesDecrypt() } \endspec */ 
typedef uint8 Crypto_30_LibCv_AesDecryptIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_AesDecryptUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_AesDecryptUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_Ed25519VerifyIdxOfObjectInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfEd25519Verify() } \endspec */ 
typedef uint8 Crypto_30_LibCv_Ed25519VerifyIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_Ed25519VerifyUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_Ed25519VerifyUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_Fips186IdxOfObjectInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfFips186() } \endspec */ 
typedef uint8 Crypto_30_LibCv_Fips186IdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_Fips186UsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_Fips186UsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HashIdxOfObjectInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfHash() } \endspec */ 
typedef uint8 Crypto_30_LibCv_HashIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_HashUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_HashUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_QueueIdxOfObjectInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfQueue() } \endspec */ 
typedef uint8 Crypto_30_LibCv_QueueIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_RandomSeedBufferEndIdxOfObjectInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfRandomSeedBuffer() } \endspec */ 
typedef uint8 Crypto_30_LibCv_RandomSeedBufferEndIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_RandomSeedBufferStartIdxOfObjectInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfRandomSeedBuffer() } \endspec */ 
typedef uint8 Crypto_30_LibCv_RandomSeedBufferStartIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_RandomSeedBufferUsedOfObjectInfo */
typedef boolean Crypto_30_LibCv_RandomSeedBufferUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_WorkspaceLengthOfObjectInfo */
typedef uint32 Crypto_30_LibCv_WorkspaceLengthOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_ObjectInfoInd */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfObjectInfo() } \endspec */ 
typedef uint8 Crypto_30_LibCv_ObjectInfoIndType;

/**   \brief  value based type definition for Crypto_30_LibCv_ObjectInfoIndEndIdxOfPrimitiveFct */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfObjectInfoInd() } \endspec */ 
typedef uint8 Crypto_30_LibCv_ObjectInfoIndEndIdxOfPrimitiveFctType;

/**   \brief  value based type definition for Crypto_30_LibCv_ObjectInfoIndStartIdxOfPrimitiveFct */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfObjectInfoInd() } \endspec */ 
typedef uint8 Crypto_30_LibCv_ObjectInfoIndStartIdxOfPrimitiveFctType;

/**   \brief  value based type definition for Crypto_30_LibCv_ObjectInfoIndUsedOfPrimitiveFct */
typedef boolean Crypto_30_LibCv_ObjectInfoIndUsedOfPrimitiveFctType;

/**   \brief  value based type definition for Crypto_30_LibCv_CombinedOfPrimitiveInfo */
typedef uint32 Crypto_30_LibCv_CombinedOfPrimitiveInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_ContextOfPrimitiveInfo */
typedef boolean Crypto_30_LibCv_ContextOfPrimitiveInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_DefaultRandomSourceOfPrimitiveInfo */
typedef boolean Crypto_30_LibCv_DefaultRandomSourceOfPrimitiveInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_MaskedBitsOfPrimitiveInfo */
typedef uint8 Crypto_30_LibCv_MaskedBitsOfPrimitiveInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PrimitiveFctIdxOfPrimitiveInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfPrimitiveFct() } \endspec */ 
typedef uint8 Crypto_30_LibCv_PrimitiveFctIdxOfPrimitiveInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PrimitiveInfoEndIdxOfPrimitiveServiceInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfPrimitiveInfo() } \endspec */ 
typedef uint8 Crypto_30_LibCv_PrimitiveInfoEndIdxOfPrimitiveServiceInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PrimitiveInfoStartIdxOfPrimitiveServiceInfo */
/*! \spec strong type invariant () { self < Crypto_30_LibCv_GetSizeOfPrimitiveInfo() } \endspec */ 
typedef uint8 Crypto_30_LibCv_PrimitiveInfoStartIdxOfPrimitiveServiceInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_PrimitiveInfoUsedOfPrimitiveServiceInfo */
typedef boolean Crypto_30_LibCv_PrimitiveInfoUsedOfPrimitiveServiceInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_RandomSeedBuffer */
typedef uint8 Crypto_30_LibCv_RandomSeedBufferType;

/**   \brief  value based type definition for Crypto_30_LibCv_RedirectionOfGeneral */
typedef boolean Crypto_30_LibCv_RedirectionOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfAesDecrypt */
typedef uint8 Crypto_30_LibCv_SizeOfAesDecryptType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfBufferLength */
typedef uint8 Crypto_30_LibCv_SizeOfBufferLengthType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfDriverObjectState */
typedef uint8 Crypto_30_LibCv_SizeOfDriverObjectStateType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfEd25519Verify */
typedef uint8 Crypto_30_LibCv_SizeOfEd25519VerifyType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfFamilyToHashMapping */
typedef uint8 Crypto_30_LibCv_SizeOfFamilyToHashMappingType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfFips186 */
typedef uint8 Crypto_30_LibCv_SizeOfFips186Type;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfHash */
typedef uint8 Crypto_30_LibCv_SizeOfHashType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfInitValue */
typedef uint8 Crypto_30_LibCv_SizeOfInitValueType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKey */
typedef uint8 Crypto_30_LibCv_SizeOfKeyType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyElementInfo */
typedef uint8 Crypto_30_LibCv_SizeOfKeyElementInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyElements */
typedef uint8 Crypto_30_LibCv_SizeOfKeyElementsType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyLock */
typedef uint8 Crypto_30_LibCv_SizeOfKeyLockType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfKeyStorage */
typedef uint8 Crypto_30_LibCv_SizeOfKeyStorageType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfLock */
typedef uint8 Crypto_30_LibCv_SizeOfLockType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfObjectInfo */
typedef uint8 Crypto_30_LibCv_SizeOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfObjectInfoInd */
typedef uint8 Crypto_30_LibCv_SizeOfObjectInfoIndType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfPrimitiveFct */
typedef uint8 Crypto_30_LibCv_SizeOfPrimitiveFctType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfPrimitiveInfo */
typedef uint8 Crypto_30_LibCv_SizeOfPrimitiveInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfPrimitiveServiceInfo */
typedef uint8 Crypto_30_LibCv_SizeOfPrimitiveServiceInfoType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfQueue */
typedef uint8 Crypto_30_LibCv_SizeOfQueueType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfRandomSeedBuffer */
typedef uint8 Crypto_30_LibCv_SizeOfRandomSeedBufferType;

/**   \brief  value based type definition for Crypto_30_LibCv_SizeOfWrittenLength */
typedef uint8 Crypto_30_LibCv_SizeOfWrittenLengthType;

/**   \brief  value based type definition for Crypto_30_LibCv_StrictLengthCheckForKeyElementGetOfGeneral */
typedef boolean Crypto_30_LibCv_StrictLengthCheckForKeyElementGetOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_UseVStdLibOfGeneral */
typedef boolean Crypto_30_LibCv_UseVStdLibOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_VersionInfoApiOfGeneral */
typedef boolean Crypto_30_LibCv_VersionInfoApiOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_WatchdogTriggerFunctionOfGeneral */
typedef uint32 Crypto_30_LibCv_WatchdogTriggerFunctionOfGeneralType;

/**   \brief  value based type definition for Crypto_30_LibCv_WrittenLength */
typedef uint32 Crypto_30_LibCv_WrittenLengthType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_LibCvPCStructTypes  Crypto_30_LibCv Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Crypto_30_LibCv_AesDecrypt */
typedef struct sCrypto_30_LibCv_AesDecryptType
{
  Crypto_30_LibCv_Crypto_30_LibCv_WorkSpaceAES_PtrType WorkspaceOfAesDecrypt;
} Crypto_30_LibCv_AesDecryptType;

/**   \brief  type used in Crypto_30_LibCv_Ed25519Verify */
typedef struct sCrypto_30_LibCv_Ed25519VerifyType
{
  Crypto_30_LibCv_eslt_WorkSpaceEd25519_PtrType WorkspaceOfEd25519Verify;
} Crypto_30_LibCv_Ed25519VerifyType;

/**   \brief  type used in Crypto_30_LibCv_Fips186 */
typedef struct sCrypto_30_LibCv_Fips186Type
{
  Crypto_30_LibCv_eslt_WorkSpaceFIPS186_PtrType WorkspaceOfFips186;
} Crypto_30_LibCv_Fips186Type;

/**   \brief  type used in Crypto_30_LibCv_Hash */
typedef struct sCrypto_30_LibCv_HashType
{
  Crypto_30_LibCv_vSecPrimType_WorkSpaceHash_PtrType WorkspaceOfHash;
} Crypto_30_LibCv_HashType;

/**   \brief  type used in Crypto_30_LibCv_Key */
/*! 
 * \spec strong type invariant () { 
 *   (self.KeyElementsEndIdxOfKey < Crypto_30_LibCv_GetSizeOfKeyElements()) &&
 *   (self.KeyElementsStartIdxOfKey < Crypto_30_LibCv_GetSizeOfKeyElements())
 * }
 * \endspec 
 */ 
typedef struct sCrypto_30_LibCv_KeyType
{
  Crypto_30_LibCv_KeyElementsEndIdxOfKeyType KeyElementsEndIdxOfKey;  /**< the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements */
  Crypto_30_LibCv_KeyElementsStartIdxOfKeyType KeyElementsStartIdxOfKey;  /**< the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements */
} Crypto_30_LibCv_KeyType;

/**   \brief  type used in Crypto_30_LibCv_KeyElementInfo */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.InitValueStartIdxOfKeyElementInfo != CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO) || (self.InitValueEndIdxOfKeyElementInfo < Crypto_30_LibCv_GetSizeOfInitValue())) &&
 *   (!(self.InitValueStartIdxOfKeyElementInfo != CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO) || (self.InitValueStartIdxOfKeyElementInfo < Crypto_30_LibCv_GetSizeOfInitValue()))
 * }
 * \endspec 
 */ 
typedef struct sCrypto_30_LibCv_KeyElementInfoType
{
  Crypto_30_LibCv_IdOfKeyElementInfoType IdOfKeyElementInfo;
  Crypto_30_LibCv_InitValueEndIdxOfKeyElementInfoType InitValueEndIdxOfKeyElementInfo;  /**< the end index of the 0:n relation pointing to Crypto_30_LibCv_InitValue */
  Crypto_30_LibCv_InitValueStartIdxOfKeyElementInfoType InitValueStartIdxOfKeyElementInfo;  /**< the start index of the 0:n relation pointing to Crypto_30_LibCv_InitValue */
  Crypto_30_LibCv_LengthOfKeyElementInfoType LengthOfKeyElementInfo;
  Crypto_30_LibCv_MaskedBitsOfKeyElementInfoType MaskedBitsOfKeyElementInfo;  /**< contains bitcoded the boolean data of Crypto_30_LibCv_OnceOfKeyElementInfo, Crypto_30_LibCv_PartialOfKeyElementInfo, Crypto_30_LibCv_PersistOfKeyElementInfo */
  Crypto_30_LibCv_ReadOfKeyElementInfoType ReadOfKeyElementInfo;
  Crypto_30_LibCv_WriteOfKeyElementInfoType WriteOfKeyElementInfo;
} Crypto_30_LibCv_KeyElementInfoType;

/**   \brief  type used in Crypto_30_LibCv_KeyElements */
/*! 
 * \spec strong type invariant () { 
 *   (self.KeyElementInfoIdxOfKeyElements < Crypto_30_LibCv_GetSizeOfKeyElementInfo()) &&
 *   (self.KeyStorageEndIdxOfKeyElements < Crypto_30_LibCv_GetSizeOfKeyStorage()) &&
 *   (self.KeyStorageExtensionIdxOfKeyElements < Crypto_30_LibCv_GetSizeOfKeyStorage()) &&
 *   (self.KeyStorageStartIdxOfKeyElements < Crypto_30_LibCv_GetSizeOfKeyStorage()) &&
 *   (self.KeyStorageValidIdxOfKeyElements < Crypto_30_LibCv_GetSizeOfKeyStorage()) &&
 *   (self.KeyStorageWrittenLengthEndIdxOfKeyElements < Crypto_30_LibCv_GetSizeOfKeyStorage()) &&
 *   (self.KeyStorageWrittenLengthStartIdxOfKeyElements < Crypto_30_LibCv_GetSizeOfKeyStorage())
 * }
 * \endspec 
 */ 
typedef struct sCrypto_30_LibCv_KeyElementsType
{
  Crypto_30_LibCv_IdOfKeyElementsType IdOfKeyElements;
  Crypto_30_LibCv_KeyElementInfoIdxOfKeyElementsType KeyElementInfoIdxOfKeyElements;  /**< the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyElementInfo */
  Crypto_30_LibCv_KeyStorageEndIdxOfKeyElementsType KeyStorageEndIdxOfKeyElements;  /**< the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage */
  Crypto_30_LibCv_KeyStorageExtensionIdxOfKeyElementsType KeyStorageExtensionIdxOfKeyElements;  /**< the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyStorage */
  Crypto_30_LibCv_KeyStorageStartIdxOfKeyElementsType KeyStorageStartIdxOfKeyElements;  /**< the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage */
  Crypto_30_LibCv_KeyStorageValidIdxOfKeyElementsType KeyStorageValidIdxOfKeyElements;  /**< the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyStorage */
  Crypto_30_LibCv_KeyStorageWrittenLengthEndIdxOfKeyElementsType KeyStorageWrittenLengthEndIdxOfKeyElements;  /**< the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage */
  Crypto_30_LibCv_KeyStorageWrittenLengthStartIdxOfKeyElementsType KeyStorageWrittenLengthStartIdxOfKeyElements;  /**< the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage */
} Crypto_30_LibCv_KeyElementsType;

/**   \brief  type used in Crypto_30_LibCv_ObjectInfo */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.AesDecryptIdxOfObjectInfo != CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO) || (self.AesDecryptIdxOfObjectInfo < Crypto_30_LibCv_GetSizeOfAesDecrypt())) &&
 *   (!(self.Ed25519VerifyIdxOfObjectInfo != CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO) || (self.Ed25519VerifyIdxOfObjectInfo < Crypto_30_LibCv_GetSizeOfEd25519Verify())) &&
 *   (!(self.Fips186IdxOfObjectInfo != CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO) || (self.Fips186IdxOfObjectInfo < Crypto_30_LibCv_GetSizeOfFips186())) &&
 *   (!(self.HashIdxOfObjectInfo != CRYPTO_30_LIBCV_NO_HASHIDXOFOBJECTINFO) || (self.HashIdxOfObjectInfo < Crypto_30_LibCv_GetSizeOfHash())) &&
 *   (self.QueueIdxOfObjectInfo < Crypto_30_LibCv_GetSizeOfQueue()) &&
 *   (!(self.RandomSeedBufferStartIdxOfObjectInfo != CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO) || (self.RandomSeedBufferEndIdxOfObjectInfo < Crypto_30_LibCv_GetSizeOfRandomSeedBuffer())) &&
 *   (!(self.RandomSeedBufferStartIdxOfObjectInfo != CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO) || (self.RandomSeedBufferStartIdxOfObjectInfo < Crypto_30_LibCv_GetSizeOfRandomSeedBuffer()))
 * }
 * \endspec 
 */ 
typedef struct sCrypto_30_LibCv_ObjectInfoType
{
  Crypto_30_LibCv_WorkspaceLengthOfObjectInfoType WorkspaceLengthOfObjectInfo;  /**< Holds the length of the workspace. */
  Crypto_30_LibCv_AesDecryptIdxOfObjectInfoType AesDecryptIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_AesDecrypt */
  Crypto_30_LibCv_Ed25519VerifyIdxOfObjectInfoType Ed25519VerifyIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_Ed25519Verify */
  Crypto_30_LibCv_Fips186IdxOfObjectInfoType Fips186IdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_Fips186 */
  Crypto_30_LibCv_HashIdxOfObjectInfoType HashIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_LibCv_Hash */
  Crypto_30_LibCv_QueueIdxOfObjectInfoType QueueIdxOfObjectInfo;  /**< the index of the 1:1 relation pointing to Crypto_30_LibCv_Queue */
  Crypto_30_LibCv_RandomSeedBufferEndIdxOfObjectInfoType RandomSeedBufferEndIdxOfObjectInfo;  /**< the end index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer */
  Crypto_30_LibCv_RandomSeedBufferStartIdxOfObjectInfoType RandomSeedBufferStartIdxOfObjectInfo;  /**< the start index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer */
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT)  WorkspaceAddrOfObjectInfo;  /**< Holds the address of the workspace. */
} Crypto_30_LibCv_ObjectInfoType;

/**   \brief  type used in Crypto_30_LibCv_PrimitiveFct */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.ObjectInfoIndStartIdxOfPrimitiveFct != CRYPTO_30_LIBCV_NO_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT) || (self.ObjectInfoIndEndIdxOfPrimitiveFct < Crypto_30_LibCv_GetSizeOfObjectInfoInd())) &&
 *   (!(self.ObjectInfoIndStartIdxOfPrimitiveFct != CRYPTO_30_LIBCV_NO_OBJECTINFOINDSTARTIDXOFPRIMITIVEFCT) || (self.ObjectInfoIndStartIdxOfPrimitiveFct < Crypto_30_LibCv_GetSizeOfObjectInfoInd()))
 * }
 * \endspec 
 */ 
typedef struct sCrypto_30_LibCv_PrimitiveFctType
{
  Crypto_30_LibCv_ObjectInfoIndEndIdxOfPrimitiveFctType ObjectInfoIndEndIdxOfPrimitiveFct;  /**< the end index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd */
  Crypto_30_LibCv_ObjectInfoIndStartIdxOfPrimitiveFctType ObjectInfoIndStartIdxOfPrimitiveFct;  /**< the start index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd */
  Crypto_30_LibCv_DispatchFctPtrType DispatchOfPrimitiveFct;
} Crypto_30_LibCv_PrimitiveFctType;

/**   \brief  type used in Crypto_30_LibCv_PrimitiveInfo */
/*! 
 * \spec strong type invariant () { 
 *   (self.PrimitiveFctIdxOfPrimitiveInfo < Crypto_30_LibCv_GetSizeOfPrimitiveFct())
 * }
 * \endspec 
 */ 
typedef struct sCrypto_30_LibCv_PrimitiveInfoType
{
  Crypto_30_LibCv_CombinedOfPrimitiveInfoType CombinedOfPrimitiveInfo;
  Crypto_30_LibCv_MaskedBitsOfPrimitiveInfoType MaskedBitsOfPrimitiveInfo;  /**< contains bitcoded the boolean data of Crypto_30_LibCv_ContextOfPrimitiveInfo, Crypto_30_LibCv_DefaultRandomSourceOfPrimitiveInfo */
  Crypto_30_LibCv_PrimitiveFctIdxOfPrimitiveInfoType PrimitiveFctIdxOfPrimitiveInfo;  /**< the index of the 1:1 relation pointing to Crypto_30_LibCv_PrimitiveFct */
} Crypto_30_LibCv_PrimitiveInfoType;

/**   \brief  type used in Crypto_30_LibCv_PrimitiveServiceInfo */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.PrimitiveInfoStartIdxOfPrimitiveServiceInfo != CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO) || (self.PrimitiveInfoEndIdxOfPrimitiveServiceInfo < Crypto_30_LibCv_GetSizeOfPrimitiveInfo())) &&
 *   (!(self.PrimitiveInfoStartIdxOfPrimitiveServiceInfo != CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO) || (self.PrimitiveInfoStartIdxOfPrimitiveServiceInfo < Crypto_30_LibCv_GetSizeOfPrimitiveInfo()))
 * }
 * \endspec 
 */ 
typedef struct sCrypto_30_LibCv_PrimitiveServiceInfoType
{
  Crypto_30_LibCv_PrimitiveInfoEndIdxOfPrimitiveServiceInfoType PrimitiveInfoEndIdxOfPrimitiveServiceInfo;  /**< the end index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo */
  Crypto_30_LibCv_PrimitiveInfoStartIdxOfPrimitiveServiceInfoType PrimitiveInfoStartIdxOfPrimitiveServiceInfo;  /**< the start index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo */
} Crypto_30_LibCv_PrimitiveServiceInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCSymbolicStructTypes  Crypto_30_LibCv Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Crypto_30_LibCv_KeyLock */
typedef struct Crypto_30_LibCv_KeyLockStructSTag
{
  Crypto_30_LibCv_KeyLockType CryptoKey_Fbl_Signature_Ed25519;
  Crypto_30_LibCv_KeyLockType CryptoKey_Fbl_Decrypt_Aes128;
  Crypto_30_LibCv_KeyLockType CryptoKey_Fbl_Fips186;
  Crypto_30_LibCv_KeyLockType CryptoKey_Fbl_HashDummy;
} Crypto_30_LibCv_KeyLockStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_LibCv_Queue */
typedef struct Crypto_30_LibCv_QueueStructSTag
{
  Crypto_30_LibCv_JobPtrType Crypto_30_LibCv;
  Crypto_30_LibCv_JobPtrType Crypto_30_LibCv_Aes;
  Crypto_30_LibCv_JobPtrType Crypto_30_LibCv_Rng;
} Crypto_30_LibCv_QueueStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_LibCv_RandomSeedBuffer */
typedef struct Crypto_30_LibCv_RandomSeedBufferStructSTag
{
  Crypto_30_LibCv_RandomSeedBufferType Crypto_30_LibCv[21];
  Crypto_30_LibCv_RandomSeedBufferType Crypto_30_LibCv_Rng[21];
} Crypto_30_LibCv_RandomSeedBufferStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCUnionIndexAndSymbolTypes  Crypto_30_LibCv Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Crypto_30_LibCv_KeyLock in an index and symbol based style. */
typedef union Crypto_30_LibCv_KeyLockUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_LibCv_KeyLockType raw[4];
  Crypto_30_LibCv_KeyLockStructSType str;
} Crypto_30_LibCv_KeyLockUType;

/**   \brief  type to access Crypto_30_LibCv_Queue in an index and symbol based style. */
typedef union Crypto_30_LibCv_QueueUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_LibCv_JobPtrType raw[3];
  Crypto_30_LibCv_QueueStructSType str;
} Crypto_30_LibCv_QueueUType;

/**   \brief  type to access Crypto_30_LibCv_RandomSeedBuffer in an index and symbol based style. */
typedef union Crypto_30_LibCv_RandomSeedBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_LibCv_RandomSeedBufferType raw[42];
  Crypto_30_LibCv_RandomSeedBufferStructSType str;
} Crypto_30_LibCv_RandomSeedBufferUType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCRootPointerTypes  Crypto_30_LibCv Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Crypto_30_LibCv_AesDecrypt */
typedef P2CONST(Crypto_30_LibCv_AesDecryptType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesDecryptPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_BufferLength */
typedef P2VAR(Crypto_30_LibCv_BufferLengthType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_BufferLengthPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_DriverObjectState */
typedef P2VAR(Crypto_30_LibCv_DriverObjectStateType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DriverObjectStatePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Ed25519Verify */
typedef P2CONST(Crypto_30_LibCv_Ed25519VerifyType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Ed25519VerifyPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_FamilyToHashMapping */
typedef P2CONST(Crypto_30_LibCv_FamilyToHashMappingType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_FamilyToHashMappingPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Fips186 */
typedef P2CONST(Crypto_30_LibCv_Fips186Type, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Fips186PtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Hash */
typedef P2CONST(Crypto_30_LibCv_HashType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HashPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_InitValue */
typedef P2CONST(Crypto_30_LibCv_InitValueType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_InitValuePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Key */
typedef P2CONST(Crypto_30_LibCv_KeyType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyElementInfo */
typedef P2CONST(Crypto_30_LibCv_KeyElementInfoType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElementInfoPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyElements */
typedef P2CONST(Crypto_30_LibCv_KeyElementsType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElementsPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyLock */
typedef P2VAR(Crypto_30_LibCv_KeyLockType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyLockPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_KeyStorage */
typedef P2VAR(Crypto_30_LibCv_KeyStorageType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyStoragePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Lock */
typedef P2VAR(Crypto_30_LibCv_LockType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_LockPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_ObjectInfo */
typedef P2CONST(Crypto_30_LibCv_ObjectInfoType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfoPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_ObjectInfoInd */
typedef P2CONST(Crypto_30_LibCv_ObjectInfoIndType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfoIndPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_PrimitiveFct */
typedef P2CONST(Crypto_30_LibCv_PrimitiveFctType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveFctPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_PrimitiveInfo */
typedef P2CONST(Crypto_30_LibCv_PrimitiveInfoType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveInfoPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_PrimitiveServiceInfo */
typedef P2CONST(Crypto_30_LibCv_PrimitiveServiceInfoType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveServiceInfoPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_Queue */
typedef P2VAR(Crypto_30_LibCv_JobPtrType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_QueuePtrType;

/**   \brief  type used to point to Crypto_30_LibCv_RandomSeedBuffer */
typedef P2VAR(Crypto_30_LibCv_RandomSeedBufferType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_RandomSeedBufferPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_UnionWS_Crypto_30_LibCv */
typedef P2VAR(Crypto_30_LibCv_WS_Crypto_30_LibCv_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_Crypto_30_LibCvPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes */
typedef P2VAR(Crypto_30_LibCv_WS_Crypto_30_LibCv_Aes_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_AesPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng */
typedef P2VAR(Crypto_30_LibCv_WS_Crypto_30_LibCv_Rng_Type, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_RngPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_WrittenLength */
typedef P2VAR(Crypto_30_LibCv_WrittenLengthType, TYPEDEF, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_WrittenLengthPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_NvWriteBlockFctNameOfNvStorageOfPCConfig */
typedef P2CONST(Crypto_30_LibCv_NvWriteBlockFctNameOfNvStorageType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_NvWriteBlockFctNameOfNvStorageOfPCConfigPtrType;

/**   \brief  type used to point to Crypto_30_LibCv_WatchdogTriggerFunctionOfGeneralOfPCConfig */
typedef P2CONST(Crypto_30_LibCv_WatchdogTriggerFunctionOfGeneralType, TYPEDEF, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_WatchdogTriggerFunctionOfGeneralOfPCConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_LibCvPCRootValueTypes  Crypto_30_LibCv Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Crypto_30_LibCv_PCConfig */
typedef struct sCrypto_30_LibCv_PCConfigType
{
  uint8 Crypto_30_LibCv_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Crypto_30_LibCv_PCConfigType;

typedef Crypto_30_LibCv_PCConfigType Crypto_30_LibCv_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_LibCvPBValueTypes  Crypto_30_LibCv Value Types (POST_BUILD)
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
  \defgroup  Crypto_30_LibCvPBRootValueTypes  Crypto_30_LibCv Root Value Types (POST_BUILD)
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
  Crypto_30_LibCv_AesDecrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AesDecrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_AesDecryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesDecrypt[1];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Ed25519Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Ed25519Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_Ed25519VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Ed25519Verify[1];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_FamilyToHashMapping
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_FamilyToHashMappingType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_FamilyToHashMapping[8];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Fips186
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Fips186
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_Fips186Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Fips186[2];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Hash
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Hash
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_HashType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Hash[1];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_InitValue
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_InitValueType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_InitValue[1];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Key
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Key
  \details
  Element                Description
  KeyElementsEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements
  KeyElementsStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Key[4];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyElementInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyElementInfo
  \details
  Element              Description
  Id               
  InitValueEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_InitValue
  InitValueStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_InitValue
  Length           
  MaskedBits           contains bitcoded the boolean data of Crypto_30_LibCv_OnceOfKeyElementInfo, Crypto_30_LibCv_PartialOfKeyElementInfo, Crypto_30_LibCv_PersistOfKeyElementInfo
  Read             
  Write            
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyElementInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElementInfo[6];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyElements
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyElements
  \details
  Element                            Description
  Id                             
  KeyElementInfoIdx                  the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyElementInfo
  KeyStorageEndIdx                   the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageExtensionIdx             the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageStartIdx                 the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageValidIdx                 the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageWrittenLengthEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageWrittenLengthStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_KeyElementsType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElements[6];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_ObjectInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_ObjectInfo
  \details
  Element                     Description
  WorkspaceLength             Holds the length of the workspace.
  AesDecryptIdx               the index of the 0:1 relation pointing to Crypto_30_LibCv_AesDecrypt
  Ed25519VerifyIdx            the index of the 0:1 relation pointing to Crypto_30_LibCv_Ed25519Verify
  Fips186Idx                  the index of the 0:1 relation pointing to Crypto_30_LibCv_Fips186
  HashIdx                     the index of the 0:1 relation pointing to Crypto_30_LibCv_Hash
  QueueIdx                    the index of the 1:1 relation pointing to Crypto_30_LibCv_Queue
  RandomSeedBufferEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer
  RandomSeedBufferStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer
  WorkspaceAddr               Holds the address of the workspace.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_ObjectInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfo[3];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_ObjectInfoInd
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_ObjectInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Crypto_30_LibCv_ObjectInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_ObjectInfoIndType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfoInd[5];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveFct
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveFct
  \details
  Element                  Description
  ObjectInfoIndEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd
  ObjectInfoIndStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd
  Dispatch             
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_PrimitiveFctType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveFct[4];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveInfo
  \details
  Element            Description
  Combined       
  MaskedBits         contains bitcoded the boolean data of Crypto_30_LibCv_ContextOfPrimitiveInfo, Crypto_30_LibCv_DefaultRandomSourceOfPrimitiveInfo
  PrimitiveFctIdx    the index of the 1:1 relation pointing to Crypto_30_LibCv_PrimitiveFct
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_PrimitiveInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveInfo[13];
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveServiceInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveServiceInfo
  \details
  Element                  Description
  PrimitiveInfoEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo
  PrimitiveInfoStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_LibCv_PrimitiveServiceInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveServiceInfo[20];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_BufferLength
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_BufferLength
  \brief  Buffer which holds the current seed of the Fips186 algorithm to restore the needed workspace.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_BufferLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_BufferLength[3];
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_DriverObjectState
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_DriverObjectState
  \brief  State of the current workspace usage.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_DriverObjectStateType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DriverObjectState[3];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyLock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyLock
  \brief  Stores locking counter of each key
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_KeyLockUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyLock;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyStorage
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_KeyStorageType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyStorage[129];
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Lock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Lock
  \brief  Id of job that currently occupies the workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_LockType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Lock[3];
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Queue
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Queue
  \brief  Acts as job queue for all driver objects.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_QueueUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Queue;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_RandomSeedBuffer
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_RandomSeedBufferUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_RandomSeedBuffer;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_Crypto_30_LibCv
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_Crypto_30_LibCv
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_WS_Crypto_30_LibCv_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_Crypto_30_LibCv;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Aes.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_WS_Crypto_30_LibCv_Aes_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Rng.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_WS_Crypto_30_LibCv_Rng_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_WrittenLength
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_WrittenLength
  \brief  Holds the length which needs to be written in a next step for some algorithms.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_LibCv_WrittenLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_WrittenLength[3];
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
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





/* Watchdog Function Prototype */
extern FUNC(void, CRYPTO_30_LIBCV_APPL_CODE) FblLookForWatchdogVoid( void );


#if !defined (CRYPTO_30_LIBCV_NOUNIT_CSLUNIT)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

#endif



#endif /* CRYPTO_30_LIBCV_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_LibCv_Cfg.h
 *********************************************************************************************************************/


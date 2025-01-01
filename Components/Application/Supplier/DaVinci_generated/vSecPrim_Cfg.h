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
 *            Module: vSecPrim
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vSecPrim_Cfg.h
 *   Generation Time: 2023-07-10 14:36:09
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (VSECPRIM_CFG_H)
#define VSECPRIM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef VSECPRIM_USE_DUMMY_STATEMENT
#define VSECPRIM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VSECPRIM_DUMMY_STATEMENT
#define VSECPRIM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VSECPRIM_DUMMY_STATEMENT_CONST
#define VSECPRIM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VSECPRIM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define VSECPRIM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef VSECPRIM_ATOMIC_VARIABLE_ACCESS
#define VSECPRIM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef VSECPRIM_PROCESSOR_TC322L
#define VSECPRIM_PROCESSOR_TC322L
#endif
#ifndef VSECPRIM_COMP_TASKING
#define VSECPRIM_COMP_TASKING
#endif
#ifndef VSECPRIM_GEN_GENERATOR_MSR
#define VSECPRIM_GEN_GENERATOR_MSR
#endif
#ifndef VSECPRIM_CPUTYPE_BITORDER_LSB2MSB
#define VSECPRIM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef VSECPRIM_CONFIGURATION_VARIANT_PRECOMPILE
#define VSECPRIM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef VSECPRIM_CONFIGURATION_VARIANT_LINKTIME
#define VSECPRIM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef VSECPRIM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define VSECPRIM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef VSECPRIM_CONFIGURATION_VARIANT
#define VSECPRIM_CONFIGURATION_VARIANT VSECPRIM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef VSECPRIM_POSTBUILD_VARIANT_SUPPORT
#define VSECPRIM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Microsar Define Block for Boolean and Integers */
#define VSECPRIM_SHA1_ENABLED                                                                       STD_OFF 
#define VSECPRIM_RIPEMD160_ENABLED                                                                  STD_OFF 
#define VSECPRIM_SHA2_256_ENABLED                                                                   STD_ON 
#define VSECPRIM_SHA2_512_ENABLED                                                                   STD_ON 
#define VSECPRIM_SHA3_ENABLED                                                                       STD_OFF 
#define VSECPRIM_MD5_ENABLED                                                                        STD_OFF 
#define VSECPRIM_FIPS186_ENABLED                                                                    STD_OFF 
#define VSECPRIM_CTR_DRBG_ENABLED                                                                   STD_OFF 
#define VSECPRIM_HASH_DRBG_ENABLED                                                                  STD_OFF 
#define VSECPRIM_AES128_ENABLED                                                                     STD_OFF 
#define VSECPRIM_AES192_ENABLED                                                                     STD_OFF 
#define VSECPRIM_AES256_ENABLED                                                                     STD_OFF 
#define VSECPRIM_GCM_ENABLED                                                                        STD_OFF 
#define VSECPRIM_AES_CCM_ENABLED                                                                    STD_OFF 
#define VSECPRIM_DES_ENABLED                                                                        STD_OFF 
#define VSECPRIM_RC2_ENABLED                                                                        STD_OFF 
#define VSECPRIM_TDES_ENABLED                                                                       STD_OFF 
#define VSECPRIM_CHA_CHA20_ENABLED                                                                  STD_OFF 
#define VSECPRIM_AEAD_CHA_CHA20_POLY1305_ENABLED                                                    STD_OFF 
#define VSECPRIM_SIP_HASH_ENABLED                                                                   STD_OFF 
#define VSECPRIM_CMAC_ENABLED                                                                       STD_OFF 
#define VSECPRIM_HMAC_SHA1_ENABLED                                                                  STD_OFF 
#define VSECPRIM_HMAC_RMD160_ENABLED                                                                STD_OFF 
#define VSECPRIM_HMAC_SHA2_256_ENABLED                                                              STD_OFF 
#define VSECPRIM_GMAC_ENABLED                                                                       STD_OFF 
#define VSECPRIM_POLY1305_ENABLED                                                                   STD_OFF 
#define VSECPRIM_HMAC_SHA2_384_ENABLED                                                              STD_OFF 
#define VSECPRIM_RSA_PSS_RIPEMD160_ENABLED                                                          STD_OFF 
#define VSECPRIM_RSA_PSS_SHA1_ENABLED                                                               STD_OFF 
#define VSECPRIM_RSA_PSS_SHA2_256_ENABLED                                                           STD_OFF 
#define VSECPRIM_RSA_V15_RIPEMD160_ENABLED                                                          STD_OFF 
#define VSECPRIM_RSA_V15_SHA1_ENABLED                                                               STD_OFF 
#define VSECPRIM_RSA_V15_SHA2_256_ENABLED                                                           STD_OFF 
#define VSECPRIM_ECDSA_25519_ENABLED                                                                STD_OFF 
#define VSECPRIM_ECDSA_GENERIC_ENABLED                                                              STD_OFF 
#define VSECPRIM_ECDH_25519_ENABLED                                                                 STD_ON 
#define VSECPRIM_ECDH_GENERIC_ENABLED                                                               STD_OFF 
#define VSECPRIM_ECBD_GENERIC_ENABLED                                                               STD_OFF 
#define VSECPRIM_SPAKE2_P_ENABLED                                                                   STD_OFF 
#define VSECPRIM_PKCS5_ENABLED                                                                      STD_OFF 
#define VSECPRIM_ANSI_X963_ENABLED                                                                  STD_OFF 
#define VSECPRIM_ANSI_X963_SHA256_ENABLED                                                           STD_OFF 
#define VSECPRIM_PKCS5_HMAC_SHA256_ENABLED                                                          STD_OFF 
#define VSECPRIM_ANSI_X963_SHA512_ENABLED                                                           STD_OFF 
#define VSECPRIM_HKDF_HMAC_SHA256_ENABLED                                                           STD_OFF 
#define VSECPRIM_HKDF_HMAC_SHA384_ENABLED                                                           STD_OFF 
#define VSECPRIM_HKDF_SHA2_256_ONESTEP_ENABLED                                                      STD_OFF 
#define VSECPRIM_RSA_OAEP_SHA1_ENABLED                                                              STD_OFF 
#define VSECPRIM_RSA_OAEP_SHA2_256_ENABLED                                                          STD_OFF 
#define VSECPRIM_RSA_V15_ENABLED                                                                    STD_OFF 
#define VSECPRIM_ECCENABLED                                                                         STD_OFF 
#define VSECPRIM_CLEAR_WORKSPACE_ENABLED                                                            STD_OFF 
#define VSECPRIM_SUPPORT_UINT64                                                                     STD_ON 
#define VSECPRIM_USE_VSTD_LIB                                                                       STD_ON 
#define VSECPRIM_DRBG_RESEED_INTERVAL                                                               4294967295u 
#define VSECPRIM_SPAKE2_P_MAX_AADSIZE                                                               16u 
#define VSECPRIM_SPAKE2_P_PREAMBLE_OKMLENGTH                                                        64u 

#define VSECPRIM_SPEED_UP_LEVEL_0                                                                   0x00u 
#define VSECPRIM_SPEED_UP_LEVEL_1                                                                   0x01u 
#define VSECPRIM_SPEED_UP_LEVEL_2                                                                   0x02u 
#define VSECPRIM_SPEED_UP_LEVEL_3                                                                   0x03u 
#define VSECPRIM_RSA_MAX_KEY_SIZE_1024                                                              0x00u 
#define VSECPRIM_RSA_MAX_KEY_SIZE_1536                                                              0x01u 
#define VSECPRIM_RSA_MAX_KEY_SIZE_2048                                                              0x02u 
#define VSECPRIM_RSA_MAX_KEY_SIZE_3072                                                              0x03u 
#define VSECPRIM_RSA_MAX_KEY_SIZE_4096                                                              0x04u 
#define VSECPRIM_RSA_MAX_KEY_SIZE_512                                                               0x05u 
#define VSECPRIM_ECP_MAX_KEY_SIZE_160                                                               0x00u 
#define VSECPRIM_ECP_MAX_KEY_SIZE_192                                                               0x01u 
#define VSECPRIM_ECP_MAX_KEY_SIZE_224                                                               0x02u 
#define VSECPRIM_ECP_MAX_KEY_SIZE_256                                                               0x03u 
#define VSECPRIM_ECP_MAX_KEY_SIZE_320                                                               0x04u 
#define VSECPRIM_ECP_MAX_KEY_SIZE_384                                                               0x05u 
#define VSECPRIM_ECP_MAX_KEY_SIZE_512                                                               0x06u 
#define VSECPRIM_ECP_MAX_KEY_SIZE_521                                                               0x07u 
#define VSECPRIM_WD_LEVEL_0                                                                         0x00u 
#define VSECPRIM_WD_LEVEL_1                                                                         0x01u 
#define VSECPRIM_WD_LEVEL_2                                                                         0x02u 
#define VSECPRIM_WD_LEVEL_3                                                                         0x03u 
#define VSECPRIM_SIZE_UINT16                                                                        0x00u 
#define VSECPRIM_SIZE_UINT32                                                                        0x01u 
#define VSECPRIM_SECURITY_STRENGTH_112                                                              0x00u 
#define VSECPRIM_SECURITY_STRENGTH_128                                                              0x01u 

#define VSECPRIM_ACT25519UTIL_ENABLED                                                               STD_ON
#define VSECPRIM_ACTAEAD7539_ENABLED                                                                STD_OFF
#define VSECPRIM_ACTAES_ENABLED                                                                     STD_OFF
#define VSECPRIM_ACTBIGNUM_ENABLED                                                                  STD_ON
#define VSECPRIM_ACTBNADD_ENABLED                                                                   STD_ON
#define VSECPRIM_ACTBNDIV2_ENABLED                                                                  STD_OFF
#define VSECPRIM_ACTBNFIELDINVERSION_ENABLED                                                        STD_OFF
#define VSECPRIM_ACTBNMODADD_ENABLED                                                                STD_ON
#define VSECPRIM_ACTBNMODDIV2_ENABLED                                                               STD_OFF
#define VSECPRIM_ACTBNMODEXP_ENABLED                                                                STD_OFF
#define VSECPRIM_ACTBNMODRANDOMIZE_ENABLED                                                          STD_OFF
#define VSECPRIM_ACTBNMODSUB_ENABLED                                                                STD_ON
#define VSECPRIM_ACTBNMONTMUL_ENABLED                                                               STD_OFF
#define VSECPRIM_ACTBNMULT_ENABLED                                                                  STD_ON
#define VSECPRIM_ACTBNODDINVMODBASE_ENABLED                                                         STD_OFF
#define VSECPRIM_ACTBNREDUCE_ENABLED                                                                STD_OFF
#define VSECPRIM_ACTBNSUB_ENABLED                                                                   STD_ON
#define VSECPRIM_ACTCCM_ENABLED                                                                     STD_OFF
#define VSECPRIM_ACTCHACHA20_ENABLED                                                                STD_OFF
#define VSECPRIM_ACTCMACAES_ENABLED                                                                 STD_OFF
#define VSECPRIM_ACTCTRDRBG_ENABLED                                                                 STD_OFF
#define VSECPRIM_ACTDES_ENABLED                                                                     STD_OFF
#define VSECPRIM_ACTECBD_GENERIC_ENABLED                                                            STD_OFF
#define VSECPRIM_ACTECDH_ENABLED                                                                    STD_OFF
#define VSECPRIM_ACTECDSA_ENABLED                                                                   STD_OFF
#define VSECPRIM_ACTECKEY_ENABLED                                                                   STD_OFF
#define VSECPRIM_ACTECLENGTHINFO_ENABLED                                                            STD_OFF
#define VSECPRIM_ACTECPOINT_ENABLED                                                                 STD_OFF
#define VSECPRIM_ACTECTOOLS_ENABLED                                                                 STD_OFF
#define VSECPRIM_ACTED25519_ENABLED                                                                 STD_OFF
#define VSECPRIM_ACTED25519CORE_ENABLED                                                             STD_OFF
#define VSECPRIM_ACTEXTERNRANDOM_ENABLED                                                            STD_ON
#define VSECPRIM_ACTFIPS186_ENABLED                                                                 STD_OFF
#define VSECPRIM_ACTGCM_ENABLED                                                                     STD_OFF
#define VSECPRIM_ACTGHASH_ENABLED                                                                   STD_OFF
#define VSECPRIM_ACTHASHDRBG_ENABLED                                                                STD_OFF
#define VSECPRIM_ACTHASHMAC_ENABLED                                                                 STD_OFF
#define VSECPRIM_ACTHASHMACRMD160_ENABLED                                                           STD_OFF
#define VSECPRIM_ACTHASHMACSHA256_ENABLED                                                           STD_OFF
#define VSECPRIM_ACTHASHMACSHA384_ENABLED                                                           STD_OFF
#define VSECPRIM_ACTHKDFHASHONESTEP_ENABLED                                                         STD_OFF
#define VSECPRIM_ACTHKDFHMACSHA256_ENABLED                                                          STD_OFF
#define VSECPRIM_ACTHKDFHMACSHA384_ENABLED                                                          STD_OFF
#define VSECPRIM_ACTIAES_ENABLED                                                                    STD_OFF
#define VSECPRIM_ACTIECDH_ENABLED                                                                   STD_OFF
#define VSECPRIM_ACTIECDSA_ENABLED                                                                  STD_OFF
#define VSECPRIM_ACTIECKEY_ENABLED                                                                  STD_OFF
#define VSECPRIM_ACTIRSAEXP_ENABLED                                                                 STD_OFF
#define VSECPRIM_ACTIRSAPRIVATE_ENABLED                                                             STD_OFF
#define VSECPRIM_ACTIRSAPRIVATECRT_ENABLED                                                          STD_OFF
#define VSECPRIM_ACTIRSAPUBLIC_ENABLED                                                              STD_OFF
#define VSECPRIM_ACTKDF2HMACSHA1_ENABLED                                                            STD_OFF
#define VSECPRIM_ACTKDF2HMACSHA256_ENABLED                                                          STD_OFF
#define VSECPRIM_ACTKDFX963_ENABLED                                                                 STD_OFF
#define VSECPRIM_ACTKDFX963SHA256_ENABLED                                                           STD_OFF
#define VSECPRIM_ACTKDFX963SHA512_ENABLED                                                           STD_OFF
#define VSECPRIM_ACTKECCAK_ENABLED                                                                  STD_OFF
#define VSECPRIM_ACTMD5_ENABLED                                                                     STD_OFF
#define VSECPRIM_ACTPADDING_ENABLED                                                                 STD_OFF
#define VSECPRIM_ACTPOLY1305_ENABLED                                                                STD_OFF
#define VSECPRIM_ACTRC2_ENABLED                                                                     STD_OFF
#define VSECPRIM_ACTRMD160_ENABLED                                                                  STD_OFF
#define VSECPRIM_ACTSHA_ENABLED                                                                     STD_OFF
#define VSECPRIM_ACTSHA2_32_ENABLED                                                                 STD_ON
#define VSECPRIM_ACTSHA2_64_ENABLED                                                                 STD_ON
#define VSECPRIM_ACTSHA3_ENABLED                                                                    STD_OFF
#define VSECPRIM_ACTSIPHASH_ENABLED                                                                 STD_OFF
#define VSECPRIM_ACTSPAKE2P_ENABLED                                                                 STD_OFF
#define VSECPRIM_ACTTDES_ENABLED                                                                    STD_OFF
#define VSECPRIM_ACTUTILITIES_ENABLED                                                               STD_ON
#define VSECPRIM_ACTX25519_ENABLED                                                                  STD_ON
#define VSECPRIM_ACTX25519CORE_ENABLED                                                              STD_ON
#define VSECPRIM_ESLGETLENGTHECP_ENABLED                                                            STD_OFF
#define VSECPRIM_HASH_ENABLED                                                                       STD_ON


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vSecPrimPCDataSwitches  vSecPrim Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VSECPRIM_ANSI_X963ENABLEDOFKEYDERIVATION                                                    STD_ON
#define VSECPRIM_ANSI_X963_SHA256ENABLEDOFKEYDERIVATION                                             STD_ON
#define VSECPRIM_ANSI_X963_SHA512ENABLEDOFKEYDERIVATION                                             STD_ON
#define VSECPRIM_AEADCHACHA20POLY1305ENABLEDOFCIPHER                                                STD_ON
#define VSECPRIM_AES128ENABLEDOFCIPHER                                                              STD_ON
#define VSECPRIM_AES192ENABLEDOFCIPHER                                                              STD_ON
#define VSECPRIM_AES256ENABLEDOFCIPHER                                                              STD_ON
#define VSECPRIM_AESCCMENABLEDOFCIPHER                                                              STD_ON
#define VSECPRIM_AESSPEEDUPOFOPTIMIZATION                                                           STD_ON
#define VSECPRIM_CTRDRBGAES128SECURITYSTRENGTHOFGENERAL                                             STD_ON
#define VSECPRIM_CHACHA20ENABLEDOFCIPHER                                                            STD_ON
#define VSECPRIM_CHACHA20SPEEDUPOFOPTIMIZATION                                                      STD_ON
#define VSECPRIM_CLEARWORKSPACEENABLEDOFGENERAL                                                     STD_ON
#define VSECPRIM_CMACENABLEDOFMAC                                                                   STD_ON
#define VSECPRIM_CTRDRBGENABLEDOFRANDOMNUMBERGENERATION                                             STD_ON
#define VSECPRIM_DESENABLEDOFCIPHER                                                                 STD_ON
#define VSECPRIM_DRBGRESEEDINTERVALOFGENERAL                                                        STD_ON
#define VSECPRIM_ECBD_GENERICENABLEDOFKEYEXCHANGE                                                   STD_ON
#define VSECPRIM_ECCENABLEDOFKEYGENERATION                                                          STD_ON
#define VSECPRIM_ECDH_25519ENABLEDOFKEYEXCHANGE                                                     STD_ON
#define VSECPRIM_ECDH_GENERICENABLEDOFKEYEXCHANGE                                                   STD_ON
#define VSECPRIM_ECDSA_25519ENABLEDOFSIGNATURE                                                      STD_ON
#define VSECPRIM_ECDSA_GENERICENABLEDOFSIGNATURE                                                    STD_ON
#define VSECPRIM_ECPMAXKEYSIZEOFGENERAL                                                             STD_ON
#define VSECPRIM_EXPECTEDCOMPATIBILITYVERSION                                                       STD_OFF  /**< Deactivateable: 'vSecPrim_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VSECPRIM_FIPS186ENABLEDOFRANDOMNUMBERGENERATION                                             STD_ON
#define VSECPRIM_FINALMAGICNUMBER                                                                   STD_OFF  /**< Deactivateable: 'vSecPrim_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VSECPRIM_GMACENABLEDOFMAC                                                                   STD_ON
#define VSECPRIM_GCMENABLEDOFCIPHER                                                                 STD_ON
#define VSECPRIM_GENERATORCOMPATIBILITYVERSION                                                      STD_OFF  /**< Deactivateable: 'vSecPrim_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VSECPRIM_HKDF_HMAC_SHA256ENABLEDOFKEYDERIVATION                                             STD_ON
#define VSECPRIM_HKDF_HMAC_SHA384ENABLEDOFKEYDERIVATION                                             STD_ON
#define VSECPRIM_HKDF_SHA2_256_ONESTEPENABLEDOFKEYDERIVATION                                        STD_ON
#define VSECPRIM_HMACRMD160ENABLEDOFMAC                                                             STD_ON
#define VSECPRIM_HMACSHA1ENABLEDOFMAC                                                               STD_ON
#define VSECPRIM_HMACSHA2_256ENABLEDOFMAC                                                           STD_ON
#define VSECPRIM_HMACSHA2_384ENABLEDOFMAC                                                           STD_ON
#define VSECPRIM_HASHDRBGENABLEDOFRANDOMNUMBERGENERATION                                            STD_ON
#define VSECPRIM_INITDATAHASHCODE                                                                   STD_OFF  /**< Deactivateable: 'vSecPrim_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VSECPRIM_MD5ENABLEDOFHASH                                                                   STD_ON
#define VSECPRIM_PKCS5ENABLEDOFKEYDERIVATION                                                        STD_ON
#define VSECPRIM_PKCS5HMACSHA256ENABLEDOFKEYDERIVATION                                              STD_ON
#define VSECPRIM_POLY1305ENABLEDOFMAC                                                               STD_ON
#define VSECPRIM_RC2ENABLEDOFCIPHER                                                                 STD_ON
#define VSECPRIM_RIPEMD160ENABLEDOFHASH                                                             STD_ON
#define VSECPRIM_RSAMAXKEYSIZEOFGENERAL                                                             STD_ON
#define VSECPRIM_RSA_OAEP_SHA1ENABLEDOFCIPHER                                                       STD_ON
#define VSECPRIM_RSA_OAEP_SHA2_256ENABLEDOFCIPHER                                                   STD_ON
#define VSECPRIM_RSA_PSS_RIPEMD160ENABLEDOFSIGNATURE                                                STD_ON
#define VSECPRIM_RSA_PSS_SHA1ENABLEDOFSIGNATURE                                                     STD_ON
#define VSECPRIM_RSA_PSS_SHA2_256ENABLEDOFSIGNATURE                                                 STD_ON
#define VSECPRIM_RSA_V15ENABLEDOFCIPHER                                                             STD_ON
#define VSECPRIM_RSA_V15_RIPEMD160ENABLEDOFSIGNATURE                                                STD_ON
#define VSECPRIM_RSA_V15_SHA1ENABLEDOFSIGNATURE                                                     STD_ON
#define VSECPRIM_RSA_V15_SHA2_256ENABLEDOFSIGNATURE                                                 STD_ON
#define VSECPRIM_SHA1ENABLEDOFHASH                                                                  STD_ON
#define VSECPRIM_SHA2_256ENABLEDOFHASH                                                              STD_ON
#define VSECPRIM_SHA2_512ENABLEDOFHASH                                                              STD_ON
#define VSECPRIM_SHA3ENABLEDOFHASH                                                                  STD_ON
#define VSECPRIM_SPAKE2PENABLEDOFKEYEXCHANGE                                                        STD_ON
#define VSECPRIM_SPAKE2PMAXAADSIZEOFGENERAL                                                         STD_ON
#define VSECPRIM_SPAKE2PPREAMBLEOKMLENGTHOFGENERAL                                                  STD_ON
#define VSECPRIM_SHA1SPEEDUPOFOPTIMIZATION                                                          STD_ON
#define VSECPRIM_SHA256SPEEDUPOFOPTIMIZATION                                                        STD_ON
#define VSECPRIM_SHA512SPEEDUPOFOPTIMIZATION                                                        STD_ON
#define VSECPRIM_SIPHASHENABLEDOFMAC                                                                STD_ON
#define VSECPRIM_SIZEOFESLTLENGTHOFGENERAL                                                          STD_ON
#define VSECPRIM_SUPPORTUINT64OFGENERAL                                                             STD_ON
#define VSECPRIM_TDESENABLEDOFCIPHER                                                                STD_ON
#define VSECPRIM_USEVSTDLIBOFGENERAL                                                                STD_ON
#define VSECPRIM_USERCONFIGFILEOFGENERAL                                                            STD_OFF  /**< Deactivateable: 'vSecPrim_UserConfigFileOfGeneral' Reason: 'Parameter is not configured!' */
#define VSECPRIM_WATCHDOGLEVELOFGENERAL                                                             STD_ON
#define VSECPRIM_PCCONFIG                                                                           STD_ON
#define VSECPRIM_ANSI_X963ENABLEDOFKEYDERIVATIONOFPCCONFIG                                          STD_ON
#define VSECPRIM_ANSI_X963_SHA256ENABLEDOFKEYDERIVATIONOFPCCONFIG                                   STD_ON
#define VSECPRIM_ANSI_X963_SHA512ENABLEDOFKEYDERIVATIONOFPCCONFIG                                   STD_ON
#define VSECPRIM_AEADCHACHA20POLY1305ENABLEDOFCIPHEROFPCCONFIG                                      STD_ON
#define VSECPRIM_AES128ENABLEDOFCIPHEROFPCCONFIG                                                    STD_ON
#define VSECPRIM_AES192ENABLEDOFCIPHEROFPCCONFIG                                                    STD_ON
#define VSECPRIM_AES256ENABLEDOFCIPHEROFPCCONFIG                                                    STD_ON
#define VSECPRIM_AESCCMENABLEDOFCIPHEROFPCCONFIG                                                    STD_ON
#define VSECPRIM_AESSPEEDUPOFOPTIMIZATIONOFPCCONFIG                                                 STD_ON
#define VSECPRIM_CTRDRBGAES128SECURITYSTRENGTHOFGENERALOFPCCONFIG                                   STD_ON
#define VSECPRIM_CHACHA20ENABLEDOFCIPHEROFPCCONFIG                                                  STD_ON
#define VSECPRIM_CHACHA20SPEEDUPOFOPTIMIZATIONOFPCCONFIG                                            STD_ON
#define VSECPRIM_CLEARWORKSPACEENABLEDOFGENERALOFPCCONFIG                                           STD_ON
#define VSECPRIM_CMACENABLEDOFMACOFPCCONFIG                                                         STD_ON
#define VSECPRIM_CTRDRBGENABLEDOFRANDOMNUMBERGENERATIONOFPCCONFIG                                   STD_ON
#define VSECPRIM_DESENABLEDOFCIPHEROFPCCONFIG                                                       STD_ON
#define VSECPRIM_DRBGRESEEDINTERVALOFGENERALOFPCCONFIG                                              STD_ON
#define VSECPRIM_ECBD_GENERICENABLEDOFKEYEXCHANGEOFPCCONFIG                                         STD_ON
#define VSECPRIM_ECCENABLEDOFKEYGENERATIONOFPCCONFIG                                                STD_ON
#define VSECPRIM_ECDH_25519ENABLEDOFKEYEXCHANGEOFPCCONFIG                                           STD_ON
#define VSECPRIM_ECDH_GENERICENABLEDOFKEYEXCHANGEOFPCCONFIG                                         STD_ON
#define VSECPRIM_ECDSA_25519ENABLEDOFSIGNATUREOFPCCONFIG                                            STD_ON
#define VSECPRIM_ECDSA_GENERICENABLEDOFSIGNATUREOFPCCONFIG                                          STD_ON
#define VSECPRIM_ECPMAXKEYSIZEOFGENERALOFPCCONFIG                                                   STD_ON
#define VSECPRIM_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                             STD_OFF  /**< Deactivateable: 'vSecPrim_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VSECPRIM_FIPS186ENABLEDOFRANDOMNUMBERGENERATIONOFPCCONFIG                                   STD_ON
#define VSECPRIM_FINALMAGICNUMBEROFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'vSecPrim_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VSECPRIM_GMACENABLEDOFMACOFPCCONFIG                                                         STD_ON
#define VSECPRIM_GCMENABLEDOFCIPHEROFPCCONFIG                                                       STD_ON
#define VSECPRIM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                            STD_OFF  /**< Deactivateable: 'vSecPrim_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VSECPRIM_HKDF_HMAC_SHA256ENABLEDOFKEYDERIVATIONOFPCCONFIG                                   STD_ON
#define VSECPRIM_HKDF_HMAC_SHA384ENABLEDOFKEYDERIVATIONOFPCCONFIG                                   STD_ON
#define VSECPRIM_HKDF_SHA2_256_ONESTEPENABLEDOFKEYDERIVATIONOFPCCONFIG                              STD_ON
#define VSECPRIM_HMACRMD160ENABLEDOFMACOFPCCONFIG                                                   STD_ON
#define VSECPRIM_HMACSHA1ENABLEDOFMACOFPCCONFIG                                                     STD_ON
#define VSECPRIM_HMACSHA2_256ENABLEDOFMACOFPCCONFIG                                                 STD_ON
#define VSECPRIM_HMACSHA2_384ENABLEDOFMACOFPCCONFIG                                                 STD_ON
#define VSECPRIM_HASHDRBGENABLEDOFRANDOMNUMBERGENERATIONOFPCCONFIG                                  STD_ON
#define VSECPRIM_INITDATAHASHCODEOFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'vSecPrim_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VSECPRIM_MD5ENABLEDOFHASHOFPCCONFIG                                                         STD_ON
#define VSECPRIM_PKCS5ENABLEDOFKEYDERIVATIONOFPCCONFIG                                              STD_ON
#define VSECPRIM_PKCS5HMACSHA256ENABLEDOFKEYDERIVATIONOFPCCONFIG                                    STD_ON
#define VSECPRIM_POLY1305ENABLEDOFMACOFPCCONFIG                                                     STD_ON
#define VSECPRIM_RC2ENABLEDOFCIPHEROFPCCONFIG                                                       STD_ON
#define VSECPRIM_RIPEMD160ENABLEDOFHASHOFPCCONFIG                                                   STD_ON
#define VSECPRIM_RSAMAXKEYSIZEOFGENERALOFPCCONFIG                                                   STD_ON
#define VSECPRIM_RSA_OAEP_SHA1ENABLEDOFCIPHEROFPCCONFIG                                             STD_ON
#define VSECPRIM_RSA_OAEP_SHA2_256ENABLEDOFCIPHEROFPCCONFIG                                         STD_ON
#define VSECPRIM_RSA_PSS_RIPEMD160ENABLEDOFSIGNATUREOFPCCONFIG                                      STD_ON
#define VSECPRIM_RSA_PSS_SHA1ENABLEDOFSIGNATUREOFPCCONFIG                                           STD_ON
#define VSECPRIM_RSA_PSS_SHA2_256ENABLEDOFSIGNATUREOFPCCONFIG                                       STD_ON
#define VSECPRIM_RSA_V15ENABLEDOFCIPHEROFPCCONFIG                                                   STD_ON
#define VSECPRIM_RSA_V15_RIPEMD160ENABLEDOFSIGNATUREOFPCCONFIG                                      STD_ON
#define VSECPRIM_RSA_V15_SHA1ENABLEDOFSIGNATUREOFPCCONFIG                                           STD_ON
#define VSECPRIM_RSA_V15_SHA2_256ENABLEDOFSIGNATUREOFPCCONFIG                                       STD_ON
#define VSECPRIM_SHA1ENABLEDOFHASHOFPCCONFIG                                                        STD_ON
#define VSECPRIM_SHA2_256ENABLEDOFHASHOFPCCONFIG                                                    STD_ON
#define VSECPRIM_SHA2_512ENABLEDOFHASHOFPCCONFIG                                                    STD_ON
#define VSECPRIM_SHA3ENABLEDOFHASHOFPCCONFIG                                                        STD_ON
#define VSECPRIM_SPAKE2PENABLEDOFKEYEXCHANGEOFPCCONFIG                                              STD_ON
#define VSECPRIM_SPAKE2PMAXAADSIZEOFGENERALOFPCCONFIG                                               STD_ON
#define VSECPRIM_SPAKE2PPREAMBLEOKMLENGTHOFGENERALOFPCCONFIG                                        STD_ON
#define VSECPRIM_SHA1SPEEDUPOFOPTIMIZATIONOFPCCONFIG                                                STD_ON
#define VSECPRIM_SHA256SPEEDUPOFOPTIMIZATIONOFPCCONFIG                                              STD_ON
#define VSECPRIM_SHA512SPEEDUPOFOPTIMIZATIONOFPCCONFIG                                              STD_ON
#define VSECPRIM_SIPHASHENABLEDOFMACOFPCCONFIG                                                      STD_ON
#define VSECPRIM_SIZEOFESLTLENGTHOFGENERALOFPCCONFIG                                                STD_ON
#define VSECPRIM_SUPPORTUINT64OFGENERALOFPCCONFIG                                                   STD_ON
#define VSECPRIM_TDESENABLEDOFCIPHEROFPCCONFIG                                                      STD_ON
#define VSECPRIM_USEVSTDLIBOFGENERALOFPCCONFIG                                                      STD_ON
#define VSECPRIM_USERCONFIGFILEOFGENERALOFPCCONFIG                                                  STD_OFF  /**< Deactivateable: 'vSecPrim_PCConfig.UserConfigFileOfGeneral' Reason: 'Parameter is not configured!' */
#define VSECPRIM_WATCHDOGLEVELOFGENERALOFPCCONFIG                                                   STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPCNoReferenceDefines  vSecPrim No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define VSECPRIM_NO_EXPECTEDCOMPATIBILITYVERSION                                                    65535u
/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPCIsReducedToDefineDefines  vSecPrim Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VSECPRIM_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                       STD_OFF
#define VSECPRIM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                   STD_OFF
#define VSECPRIM_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                      STD_OFF
#define VSECPRIM_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                   STD_OFF
#define VSECPRIM_ISDEF_USERCONFIGFILEOFGENERALOFPCCONFIG                                            STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPCEqualsAlwaysToDefines  vSecPrim Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VSECPRIM_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                         
#define VSECPRIM_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                     
#define VSECPRIM_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                        
#define VSECPRIM_EQ2_INITDATAHASHCODEOFPCCONFIG                                                     
#define VSECPRIM_EQ2_USERCONFIGFILEOFGENERALOFPCCONFIG                                              
/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPCSymbolicInitializationPointers  vSecPrim Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define vSecPrim_Config_Ptr                                                                         NULL_PTR  /**< symbolic identifier which shall be used to initialize 'vSecPrim' */
/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPCInitializationSymbols  vSecPrim Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define vSecPrim_Config                                                                             NULL_PTR  /**< symbolic identifier which could be used to initialize 'vSecPrim */
/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPCGeneral  vSecPrim General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define VSECPRIM_CHECK_INIT_POINTER                                                                 STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define VSECPRIM_FINAL_MAGIC_NUMBER                                                                 0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of vSecPrim */
#define VSECPRIM_INDIVIDUAL_POSTBUILD                                                               STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'vSecPrim' is not configured to be postbuild capable. */
#define VSECPRIM_INIT_DATA                                                                          VSECPRIM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define VSECPRIM_INIT_DATA_HASH_CODE                                                                116981988  /**< the precompile constant to validate the initialization structure at initialization time of vSecPrim with a hashcode. The seed value is '0xFF1Eu' */
#define VSECPRIM_USE_ECUM_BSW_ERROR_HOOK                                                            STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define VSECPRIM_USE_INIT_POINTER                                                                   STD_OFF  /**< STD_ON if the init pointer vSecPrim shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vSecPrimPBDataSwitches  vSecPrim Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VSECPRIM_PBCONFIG                                                                           STD_OFF  /**< Deactivateable: 'vSecPrim_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VSECPRIM_LTCONFIGIDXOFPBCONFIG                                                              STD_OFF  /**< Deactivateable: 'vSecPrim_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VSECPRIM_PCCONFIGIDXOFPBCONFIG                                                              STD_OFF  /**< Deactivateable: 'vSecPrim_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPBIsReducedToDefineDefines  vSecPrim Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VSECPRIM_ISDEF_LTCONFIGIDXOFPBCONFIG                                                        STD_OFF
#define VSECPRIM_ISDEF_PCCONFIGIDXOFPBCONFIG                                                        STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPBEqualsAlwaysToDefines  vSecPrim Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VSECPRIM_EQ2_LTCONFIGIDXOFPBCONFIG                                                          
#define VSECPRIM_EQ2_PCCONFIGIDXOFPBCONFIG                                                          
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
  \defgroup  vSecPrimPCGetRootDataMacros  vSecPrim Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vSecPrim_GetExpectedCompatibilityVersionOfPCConfig()                                          /**< Deactivateable: 'vSecPrim_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vSecPrim_GetFinalMagicNumberOfPCConfig()                                                      /**< Deactivateable: 'vSecPrim_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vSecPrim_GetGeneratorCompatibilityVersionOfPCConfig()                                         /**< Deactivateable: 'vSecPrim_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vSecPrim_GetInitDataHashCodeOfPCConfig()                                                      /**< Deactivateable: 'vSecPrim_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vSecPrim_GetUserConfigFileOfGeneralOfPCConfig()                                               /**< Deactivateable: 'vSecPrim_PCConfig.UserConfigFileOfGeneral' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPCGetConstantDuplicatedRootDataMacros  vSecPrim Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define vSecPrim_IsANSI_X963EnabledOfKeyDerivationOfPCConfig()                                      (((FALSE)) != FALSE)
#define vSecPrim_IsANSI_X963_SHA256EnabledOfKeyDerivationOfPCConfig()                               (((FALSE)) != FALSE)
#define vSecPrim_IsANSI_X963_SHA512EnabledOfKeyDerivationOfPCConfig()                               (((FALSE)) != FALSE)
#define vSecPrim_IsAeadChaCha20Poly1305EnabledOfCipherOfPCConfig()                                  (((FALSE)) != FALSE)
#define vSecPrim_IsAes128EnabledOfCipherOfPCConfig()                                                (((FALSE)) != FALSE)
#define vSecPrim_IsAes192EnabledOfCipherOfPCConfig()                                                (((FALSE)) != FALSE)
#define vSecPrim_IsAes256EnabledOfCipherOfPCConfig()                                                (((FALSE)) != FALSE)
#define vSecPrim_IsAesCcmEnabledOfCipherOfPCConfig()                                                (((FALSE)) != FALSE)
#define vSecPrim_GetAesSpeedUpOfOptimizationOfPCConfig()                                            VSECPRIM_SPEED_UP_LEVEL_3
#define vSecPrim_GetCTRDRBGAES128SecurityStrengthOfGeneralOfPCConfig()                              VSECPRIM_SECURITY_STRENGTH_128
#define vSecPrim_IsChaCha20EnabledOfCipherOfPCConfig()                                              (((FALSE)) != FALSE)
#define vSecPrim_GetChaCha20SpeedUpOfOptimizationOfPCConfig()                                       VSECPRIM_SPEED_UP_LEVEL_1
#define vSecPrim_IsClearWorkspaceEnabledOfGeneralOfPCConfig()                                       (((FALSE)) != FALSE)
#define vSecPrim_IsCmacEnabledOfMacOfPCConfig()                                                     (((FALSE)) != FALSE)
#define vSecPrim_IsCtrDrbgEnabledOfRandomNumberGenerationOfPCConfig()                               (((FALSE)) != FALSE)
#define vSecPrim_IsDesEnabledOfCipherOfPCConfig()                                                   (((FALSE)) != FALSE)
#define vSecPrim_GetDrbgReseedIntervalOfGeneralOfPCConfig()                                         4294967295u
#define vSecPrim_IsECBD_GenericEnabledOfKeyExchangeOfPCConfig()                                     (((FALSE)) != FALSE)
#define vSecPrim_IsECCEnabledOfKeyGenerationOfPCConfig()                                            (((FALSE)) != FALSE)
#define vSecPrim_IsECDH_25519EnabledOfKeyExchangeOfPCConfig()                                       (((TRUE)) != FALSE)
#define vSecPrim_IsECDH_GenericEnabledOfKeyExchangeOfPCConfig()                                     (((FALSE)) != FALSE)
#define vSecPrim_IsECDSA_25519EnabledOfSignatureOfPCConfig()                                        (((FALSE)) != FALSE)
#define vSecPrim_IsECDSA_GenericEnabledOfSignatureOfPCConfig()                                      (((FALSE)) != FALSE)
#define vSecPrim_GetECPMaxKeySizeOfGeneralOfPCConfig()                                              VSECPRIM_ECP_MAX_KEY_SIZE_256
#define vSecPrim_IsFIPS186EnabledOfRandomNumberGenerationOfPCConfig()                               (((FALSE)) != FALSE)
#define vSecPrim_IsGMacEnabledOfMacOfPCConfig()                                                     (((FALSE)) != FALSE)
#define vSecPrim_IsGcmEnabledOfCipherOfPCConfig()                                                   (((FALSE)) != FALSE)
#define vSecPrim_IsHKDF_HMAC_SHA256EnabledOfKeyDerivationOfPCConfig()                               (((FALSE)) != FALSE)
#define vSecPrim_IsHKDF_HMAC_SHA384EnabledOfKeyDerivationOfPCConfig()                               (((FALSE)) != FALSE)
#define vSecPrim_IsHKDF_SHA2_256_OnestepEnabledOfKeyDerivationOfPCConfig()                          (((FALSE)) != FALSE)
#define vSecPrim_IsHMacRMD160EnabledOfMacOfPCConfig()                                               (((FALSE)) != FALSE)
#define vSecPrim_IsHMacSHA1EnabledOfMacOfPCConfig()                                                 (((FALSE)) != FALSE)
#define vSecPrim_IsHMacSHA2_256EnabledOfMacOfPCConfig()                                             (((FALSE)) != FALSE)
#define vSecPrim_IsHMacSHA2_384EnabledOfMacOfPCConfig()                                             (((FALSE)) != FALSE)
#define vSecPrim_IsHashDrbgEnabledOfRandomNumberGenerationOfPCConfig()                              (((FALSE)) != FALSE)
#define vSecPrim_IsMD5EnabledOfHashOfPCConfig()                                                     (((FALSE)) != FALSE)
#define vSecPrim_IsPKCS5EnabledOfKeyDerivationOfPCConfig()                                          (((FALSE)) != FALSE)
#define vSecPrim_IsPKCS5HMacSHA256EnabledOfKeyDerivationOfPCConfig()                                (((FALSE)) != FALSE)
#define vSecPrim_IsPoly1305EnabledOfMacOfPCConfig()                                                 (((FALSE)) != FALSE)
#define vSecPrim_IsRC2EnabledOfCipherOfPCConfig()                                                   (((FALSE)) != FALSE)
#define vSecPrim_IsRIPEMD160EnabledOfHashOfPCConfig()                                               (((FALSE)) != FALSE)
#define vSecPrim_GetRSAMaxKeySizeOfGeneralOfPCConfig()                                              VSECPRIM_RSA_MAX_KEY_SIZE_2048
#define vSecPrim_IsRSA_OAEP_SHA1EnabledOfCipherOfPCConfig()                                         (((FALSE)) != FALSE)
#define vSecPrim_IsRSA_OAEP_SHA2_256EnabledOfCipherOfPCConfig()                                     (((FALSE)) != FALSE)
#define vSecPrim_IsRSA_PSS_RIPEMD160EnabledOfSignatureOfPCConfig()                                  (((FALSE)) != FALSE)
#define vSecPrim_IsRSA_PSS_SHA1EnabledOfSignatureOfPCConfig()                                       (((FALSE)) != FALSE)
#define vSecPrim_IsRSA_PSS_SHA2_256EnabledOfSignatureOfPCConfig()                                   (((FALSE)) != FALSE)
#define vSecPrim_IsRSA_V15EnabledOfCipherOfPCConfig()                                               (((FALSE)) != FALSE)
#define vSecPrim_IsRSA_V15_RIPEMD160EnabledOfSignatureOfPCConfig()                                  (((FALSE)) != FALSE)
#define vSecPrim_IsRSA_V15_SHA1EnabledOfSignatureOfPCConfig()                                       (((FALSE)) != FALSE)
#define vSecPrim_IsRSA_V15_SHA2_256EnabledOfSignatureOfPCConfig()                                   (((FALSE)) != FALSE)
#define vSecPrim_IsSHA1EnabledOfHashOfPCConfig()                                                    (((FALSE)) != FALSE)
#define vSecPrim_IsSHA2_256EnabledOfHashOfPCConfig()                                                (((TRUE)) != FALSE)
#define vSecPrim_IsSHA2_512EnabledOfHashOfPCConfig()                                                (((TRUE)) != FALSE)
#define vSecPrim_IsSHA3EnabledOfHashOfPCConfig()                                                    (((FALSE)) != FALSE)
#define vSecPrim_IsSPAKE2pEnabledOfKeyExchangeOfPCConfig()                                          (((FALSE)) != FALSE)
#define vSecPrim_GetSPAKE2pMaxAADSizeOfGeneralOfPCConfig()                                          16u
#define vSecPrim_GetSPAKE2pPreambleOKMLengthOfGeneralOfPCConfig()                                   64u
#define vSecPrim_GetSha1SpeedUpOfOptimizationOfPCConfig()                                           VSECPRIM_SPEED_UP_LEVEL_1
#define vSecPrim_GetSha256SpeedUpOfOptimizationOfPCConfig()                                         VSECPRIM_SPEED_UP_LEVEL_0
#define vSecPrim_GetSha512SpeedUpOfOptimizationOfPCConfig()                                         VSECPRIM_SPEED_UP_LEVEL_0
#define vSecPrim_IsSipHashEnabledOfMacOfPCConfig()                                                  (((FALSE)) != FALSE)
#define vSecPrim_GetSizeOfEsltLengthOfGeneralOfPCConfig()                                           VSECPRIM_SIZE_UINT32
#define vSecPrim_IsSupportUInt64OfGeneralOfPCConfig()                                               (((TRUE)) != FALSE)
#define vSecPrim_IsTDesEnabledOfCipherOfPCConfig()                                                  (((FALSE)) != FALSE)
#define vSecPrim_IsUseVstdLibOfGeneralOfPCConfig()                                                  (((TRUE)) != FALSE)
#define vSecPrim_GetWatchdogLevelOfGeneralOfPCConfig()                                              VSECPRIM_WD_LEVEL_0
/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPCGetDeduplicatedDataMacros  vSecPrim Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define vSecPrim_IsANSI_X963EnabledOfKeyDerivation()                                                vSecPrim_IsANSI_X963EnabledOfKeyDerivationOfPCConfig()
#define vSecPrim_IsANSI_X963_SHA256EnabledOfKeyDerivation()                                         vSecPrim_IsANSI_X963_SHA256EnabledOfKeyDerivationOfPCConfig()
#define vSecPrim_IsANSI_X963_SHA512EnabledOfKeyDerivation()                                         vSecPrim_IsANSI_X963_SHA512EnabledOfKeyDerivationOfPCConfig()
#define vSecPrim_IsAeadChaCha20Poly1305EnabledOfCipher()                                            vSecPrim_IsAeadChaCha20Poly1305EnabledOfCipherOfPCConfig()
#define vSecPrim_IsAes128EnabledOfCipher()                                                          vSecPrim_IsAes128EnabledOfCipherOfPCConfig()
#define vSecPrim_IsAes192EnabledOfCipher()                                                          vSecPrim_IsAes192EnabledOfCipherOfPCConfig()
#define vSecPrim_IsAes256EnabledOfCipher()                                                          vSecPrim_IsAes256EnabledOfCipherOfPCConfig()
#define vSecPrim_IsAesCcmEnabledOfCipher()                                                          vSecPrim_IsAesCcmEnabledOfCipherOfPCConfig()
#define vSecPrim_GetAesSpeedUpOfOptimization()                                                      vSecPrim_GetAesSpeedUpOfOptimizationOfPCConfig()
#define vSecPrim_GetCTRDRBGAES128SecurityStrengthOfGeneral()                                        vSecPrim_GetCTRDRBGAES128SecurityStrengthOfGeneralOfPCConfig()
#define vSecPrim_IsChaCha20EnabledOfCipher()                                                        vSecPrim_IsChaCha20EnabledOfCipherOfPCConfig()
#define vSecPrim_GetChaCha20SpeedUpOfOptimization()                                                 vSecPrim_GetChaCha20SpeedUpOfOptimizationOfPCConfig()
#define vSecPrim_IsClearWorkspaceEnabledOfGeneral()                                                 vSecPrim_IsClearWorkspaceEnabledOfGeneralOfPCConfig()
#define vSecPrim_IsCmacEnabledOfMac()                                                               vSecPrim_IsCmacEnabledOfMacOfPCConfig()
#define vSecPrim_IsCtrDrbgEnabledOfRandomNumberGeneration()                                         vSecPrim_IsCtrDrbgEnabledOfRandomNumberGenerationOfPCConfig()
#define vSecPrim_IsDesEnabledOfCipher()                                                             vSecPrim_IsDesEnabledOfCipherOfPCConfig()
#define vSecPrim_GetDrbgReseedIntervalOfGeneral()                                                   vSecPrim_GetDrbgReseedIntervalOfGeneralOfPCConfig()
#define vSecPrim_IsECBD_GenericEnabledOfKeyExchange()                                               vSecPrim_IsECBD_GenericEnabledOfKeyExchangeOfPCConfig()
#define vSecPrim_IsECCEnabledOfKeyGeneration()                                                      vSecPrim_IsECCEnabledOfKeyGenerationOfPCConfig()
#define vSecPrim_IsECDH_25519EnabledOfKeyExchange()                                                 vSecPrim_IsECDH_25519EnabledOfKeyExchangeOfPCConfig()
#define vSecPrim_IsECDH_GenericEnabledOfKeyExchange()                                               vSecPrim_IsECDH_GenericEnabledOfKeyExchangeOfPCConfig()
#define vSecPrim_IsECDSA_25519EnabledOfSignature()                                                  vSecPrim_IsECDSA_25519EnabledOfSignatureOfPCConfig()
#define vSecPrim_IsECDSA_GenericEnabledOfSignature()                                                vSecPrim_IsECDSA_GenericEnabledOfSignatureOfPCConfig()
#define vSecPrim_GetECPMaxKeySizeOfGeneral()                                                        vSecPrim_GetECPMaxKeySizeOfGeneralOfPCConfig()
#define vSecPrim_GetExpectedCompatibilityVersion()                                                    /**< Deactivateable: 'vSecPrim_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vSecPrim_IsFIPS186EnabledOfRandomNumberGeneration()                                         vSecPrim_IsFIPS186EnabledOfRandomNumberGenerationOfPCConfig()
#define vSecPrim_GetFinalMagicNumber()                                                                /**< Deactivateable: 'vSecPrim_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vSecPrim_IsGMacEnabledOfMac()                                                               vSecPrim_IsGMacEnabledOfMacOfPCConfig()
#define vSecPrim_IsGcmEnabledOfCipher()                                                             vSecPrim_IsGcmEnabledOfCipherOfPCConfig()
#define vSecPrim_GetGeneratorCompatibilityVersion()                                                   /**< Deactivateable: 'vSecPrim_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vSecPrim_IsHKDF_HMAC_SHA256EnabledOfKeyDerivation()                                         vSecPrim_IsHKDF_HMAC_SHA256EnabledOfKeyDerivationOfPCConfig()
#define vSecPrim_IsHKDF_HMAC_SHA384EnabledOfKeyDerivation()                                         vSecPrim_IsHKDF_HMAC_SHA384EnabledOfKeyDerivationOfPCConfig()
#define vSecPrim_IsHKDF_SHA2_256_OnestepEnabledOfKeyDerivation()                                    vSecPrim_IsHKDF_SHA2_256_OnestepEnabledOfKeyDerivationOfPCConfig()
#define vSecPrim_IsHMacRMD160EnabledOfMac()                                                         vSecPrim_IsHMacRMD160EnabledOfMacOfPCConfig()
#define vSecPrim_IsHMacSHA1EnabledOfMac()                                                           vSecPrim_IsHMacSHA1EnabledOfMacOfPCConfig()
#define vSecPrim_IsHMacSHA2_256EnabledOfMac()                                                       vSecPrim_IsHMacSHA2_256EnabledOfMacOfPCConfig()
#define vSecPrim_IsHMacSHA2_384EnabledOfMac()                                                       vSecPrim_IsHMacSHA2_384EnabledOfMacOfPCConfig()
#define vSecPrim_IsHashDrbgEnabledOfRandomNumberGeneration()                                        vSecPrim_IsHashDrbgEnabledOfRandomNumberGenerationOfPCConfig()
#define vSecPrim_GetInitDataHashCode()                                                                /**< Deactivateable: 'vSecPrim_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vSecPrim_IsMD5EnabledOfHash()                                                               vSecPrim_IsMD5EnabledOfHashOfPCConfig()
#define vSecPrim_IsPKCS5EnabledOfKeyDerivation()                                                    vSecPrim_IsPKCS5EnabledOfKeyDerivationOfPCConfig()
#define vSecPrim_IsPKCS5HMacSHA256EnabledOfKeyDerivation()                                          vSecPrim_IsPKCS5HMacSHA256EnabledOfKeyDerivationOfPCConfig()
#define vSecPrim_IsPoly1305EnabledOfMac()                                                           vSecPrim_IsPoly1305EnabledOfMacOfPCConfig()
#define vSecPrim_IsRC2EnabledOfCipher()                                                             vSecPrim_IsRC2EnabledOfCipherOfPCConfig()
#define vSecPrim_IsRIPEMD160EnabledOfHash()                                                         vSecPrim_IsRIPEMD160EnabledOfHashOfPCConfig()
#define vSecPrim_GetRSAMaxKeySizeOfGeneral()                                                        vSecPrim_GetRSAMaxKeySizeOfGeneralOfPCConfig()
#define vSecPrim_IsRSA_OAEP_SHA1EnabledOfCipher()                                                   vSecPrim_IsRSA_OAEP_SHA1EnabledOfCipherOfPCConfig()
#define vSecPrim_IsRSA_OAEP_SHA2_256EnabledOfCipher()                                               vSecPrim_IsRSA_OAEP_SHA2_256EnabledOfCipherOfPCConfig()
#define vSecPrim_IsRSA_PSS_RIPEMD160EnabledOfSignature()                                            vSecPrim_IsRSA_PSS_RIPEMD160EnabledOfSignatureOfPCConfig()
#define vSecPrim_IsRSA_PSS_SHA1EnabledOfSignature()                                                 vSecPrim_IsRSA_PSS_SHA1EnabledOfSignatureOfPCConfig()
#define vSecPrim_IsRSA_PSS_SHA2_256EnabledOfSignature()                                             vSecPrim_IsRSA_PSS_SHA2_256EnabledOfSignatureOfPCConfig()
#define vSecPrim_IsRSA_V15EnabledOfCipher()                                                         vSecPrim_IsRSA_V15EnabledOfCipherOfPCConfig()
#define vSecPrim_IsRSA_V15_RIPEMD160EnabledOfSignature()                                            vSecPrim_IsRSA_V15_RIPEMD160EnabledOfSignatureOfPCConfig()
#define vSecPrim_IsRSA_V15_SHA1EnabledOfSignature()                                                 vSecPrim_IsRSA_V15_SHA1EnabledOfSignatureOfPCConfig()
#define vSecPrim_IsRSA_V15_SHA2_256EnabledOfSignature()                                             vSecPrim_IsRSA_V15_SHA2_256EnabledOfSignatureOfPCConfig()
#define vSecPrim_IsSHA1EnabledOfHash()                                                              vSecPrim_IsSHA1EnabledOfHashOfPCConfig()
#define vSecPrim_IsSHA2_256EnabledOfHash()                                                          vSecPrim_IsSHA2_256EnabledOfHashOfPCConfig()
#define vSecPrim_IsSHA2_512EnabledOfHash()                                                          vSecPrim_IsSHA2_512EnabledOfHashOfPCConfig()
#define vSecPrim_IsSHA3EnabledOfHash()                                                              vSecPrim_IsSHA3EnabledOfHashOfPCConfig()
#define vSecPrim_IsSPAKE2pEnabledOfKeyExchange()                                                    vSecPrim_IsSPAKE2pEnabledOfKeyExchangeOfPCConfig()
#define vSecPrim_GetSPAKE2pMaxAADSizeOfGeneral()                                                    vSecPrim_GetSPAKE2pMaxAADSizeOfGeneralOfPCConfig()
#define vSecPrim_GetSPAKE2pPreambleOKMLengthOfGeneral()                                             vSecPrim_GetSPAKE2pPreambleOKMLengthOfGeneralOfPCConfig()
#define vSecPrim_GetSha1SpeedUpOfOptimization()                                                     vSecPrim_GetSha1SpeedUpOfOptimizationOfPCConfig()
#define vSecPrim_GetSha256SpeedUpOfOptimization()                                                   vSecPrim_GetSha256SpeedUpOfOptimizationOfPCConfig()
#define vSecPrim_GetSha512SpeedUpOfOptimization()                                                   vSecPrim_GetSha512SpeedUpOfOptimizationOfPCConfig()
#define vSecPrim_IsSipHashEnabledOfMac()                                                            vSecPrim_IsSipHashEnabledOfMacOfPCConfig()
#define vSecPrim_GetSizeOfEsltLengthOfGeneral()                                                     vSecPrim_GetSizeOfEsltLengthOfGeneralOfPCConfig()
#define vSecPrim_IsSupportUInt64OfGeneral()                                                         vSecPrim_IsSupportUInt64OfGeneralOfPCConfig()
#define vSecPrim_IsTDesEnabledOfCipher()                                                            vSecPrim_IsTDesEnabledOfCipherOfPCConfig()
#define vSecPrim_IsUseVstdLibOfGeneral()                                                            vSecPrim_IsUseVstdLibOfGeneralOfPCConfig()
#define vSecPrim_GetUserConfigFileOfGeneral()                                                         /**< Deactivateable: 'vSecPrim_UserConfigFileOfGeneral' Reason: 'Parameter is not configured!' */
#define vSecPrim_GetWatchdogLevelOfGeneral()                                                        vSecPrim_GetWatchdogLevelOfGeneralOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPCHasMacros  vSecPrim Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vSecPrim_HasANSI_X963EnabledOfKeyDerivation()                                               (TRUE != FALSE)
#define vSecPrim_HasANSI_X963_SHA256EnabledOfKeyDerivation()                                        (TRUE != FALSE)
#define vSecPrim_HasANSI_X963_SHA512EnabledOfKeyDerivation()                                        (TRUE != FALSE)
#define vSecPrim_HasAeadChaCha20Poly1305EnabledOfCipher()                                           (TRUE != FALSE)
#define vSecPrim_HasAes128EnabledOfCipher()                                                         (TRUE != FALSE)
#define vSecPrim_HasAes192EnabledOfCipher()                                                         (TRUE != FALSE)
#define vSecPrim_HasAes256EnabledOfCipher()                                                         (TRUE != FALSE)
#define vSecPrim_HasAesCcmEnabledOfCipher()                                                         (TRUE != FALSE)
#define vSecPrim_HasAesSpeedUpOfOptimization()                                                      (TRUE != FALSE)
#define vSecPrim_HasCTRDRBGAES128SecurityStrengthOfGeneral()                                        (TRUE != FALSE)
#define vSecPrim_HasChaCha20EnabledOfCipher()                                                       (TRUE != FALSE)
#define vSecPrim_HasChaCha20SpeedUpOfOptimization()                                                 (TRUE != FALSE)
#define vSecPrim_HasClearWorkspaceEnabledOfGeneral()                                                (TRUE != FALSE)
#define vSecPrim_HasCmacEnabledOfMac()                                                              (TRUE != FALSE)
#define vSecPrim_HasCtrDrbgEnabledOfRandomNumberGeneration()                                        (TRUE != FALSE)
#define vSecPrim_HasDesEnabledOfCipher()                                                            (TRUE != FALSE)
#define vSecPrim_HasDrbgReseedIntervalOfGeneral()                                                   (TRUE != FALSE)
#define vSecPrim_HasECBD_GenericEnabledOfKeyExchange()                                              (TRUE != FALSE)
#define vSecPrim_HasECCEnabledOfKeyGeneration()                                                     (TRUE != FALSE)
#define vSecPrim_HasECDH_25519EnabledOfKeyExchange()                                                (TRUE != FALSE)
#define vSecPrim_HasECDH_GenericEnabledOfKeyExchange()                                              (TRUE != FALSE)
#define vSecPrim_HasECDSA_25519EnabledOfSignature()                                                 (TRUE != FALSE)
#define vSecPrim_HasECDSA_GenericEnabledOfSignature()                                               (TRUE != FALSE)
#define vSecPrim_HasECPMaxKeySizeOfGeneral()                                                        (TRUE != FALSE)
#define vSecPrim_HasExpectedCompatibilityVersion()                                                    /**< Deactivateable: 'vSecPrim_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vSecPrim_HasFIPS186EnabledOfRandomNumberGeneration()                                        (TRUE != FALSE)
#define vSecPrim_HasFinalMagicNumber()                                                                /**< Deactivateable: 'vSecPrim_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vSecPrim_HasGMacEnabledOfMac()                                                              (TRUE != FALSE)
#define vSecPrim_HasGcmEnabledOfCipher()                                                            (TRUE != FALSE)
#define vSecPrim_HasGeneratorCompatibilityVersion()                                                   /**< Deactivateable: 'vSecPrim_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vSecPrim_HasHKDF_HMAC_SHA256EnabledOfKeyDerivation()                                        (TRUE != FALSE)
#define vSecPrim_HasHKDF_HMAC_SHA384EnabledOfKeyDerivation()                                        (TRUE != FALSE)
#define vSecPrim_HasHKDF_SHA2_256_OnestepEnabledOfKeyDerivation()                                   (TRUE != FALSE)
#define vSecPrim_HasHMacRMD160EnabledOfMac()                                                        (TRUE != FALSE)
#define vSecPrim_HasHMacSHA1EnabledOfMac()                                                          (TRUE != FALSE)
#define vSecPrim_HasHMacSHA2_256EnabledOfMac()                                                      (TRUE != FALSE)
#define vSecPrim_HasHMacSHA2_384EnabledOfMac()                                                      (TRUE != FALSE)
#define vSecPrim_HasHashDrbgEnabledOfRandomNumberGeneration()                                       (TRUE != FALSE)
#define vSecPrim_HasInitDataHashCode()                                                                /**< Deactivateable: 'vSecPrim_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vSecPrim_HasMD5EnabledOfHash()                                                              (TRUE != FALSE)
#define vSecPrim_HasPKCS5EnabledOfKeyDerivation()                                                   (TRUE != FALSE)
#define vSecPrim_HasPKCS5HMacSHA256EnabledOfKeyDerivation()                                         (TRUE != FALSE)
#define vSecPrim_HasPoly1305EnabledOfMac()                                                          (TRUE != FALSE)
#define vSecPrim_HasRC2EnabledOfCipher()                                                            (TRUE != FALSE)
#define vSecPrim_HasRIPEMD160EnabledOfHash()                                                        (TRUE != FALSE)
#define vSecPrim_HasRSAMaxKeySizeOfGeneral()                                                        (TRUE != FALSE)
#define vSecPrim_HasRSA_OAEP_SHA1EnabledOfCipher()                                                  (TRUE != FALSE)
#define vSecPrim_HasRSA_OAEP_SHA2_256EnabledOfCipher()                                              (TRUE != FALSE)
#define vSecPrim_HasRSA_PSS_RIPEMD160EnabledOfSignature()                                           (TRUE != FALSE)
#define vSecPrim_HasRSA_PSS_SHA1EnabledOfSignature()                                                (TRUE != FALSE)
#define vSecPrim_HasRSA_PSS_SHA2_256EnabledOfSignature()                                            (TRUE != FALSE)
#define vSecPrim_HasRSA_V15EnabledOfCipher()                                                        (TRUE != FALSE)
#define vSecPrim_HasRSA_V15_RIPEMD160EnabledOfSignature()                                           (TRUE != FALSE)
#define vSecPrim_HasRSA_V15_SHA1EnabledOfSignature()                                                (TRUE != FALSE)
#define vSecPrim_HasRSA_V15_SHA2_256EnabledOfSignature()                                            (TRUE != FALSE)
#define vSecPrim_HasSHA1EnabledOfHash()                                                             (TRUE != FALSE)
#define vSecPrim_HasSHA2_256EnabledOfHash()                                                         (TRUE != FALSE)
#define vSecPrim_HasSHA2_512EnabledOfHash()                                                         (TRUE != FALSE)
#define vSecPrim_HasSHA3EnabledOfHash()                                                             (TRUE != FALSE)
#define vSecPrim_HasSPAKE2pEnabledOfKeyExchange()                                                   (TRUE != FALSE)
#define vSecPrim_HasSPAKE2pMaxAADSizeOfGeneral()                                                    (TRUE != FALSE)
#define vSecPrim_HasSPAKE2pPreambleOKMLengthOfGeneral()                                             (TRUE != FALSE)
#define vSecPrim_HasSha1SpeedUpOfOptimization()                                                     (TRUE != FALSE)
#define vSecPrim_HasSha256SpeedUpOfOptimization()                                                   (TRUE != FALSE)
#define vSecPrim_HasSha512SpeedUpOfOptimization()                                                   (TRUE != FALSE)
#define vSecPrim_HasSipHashEnabledOfMac()                                                           (TRUE != FALSE)
#define vSecPrim_HasSizeOfEsltLengthOfGeneral()                                                     (TRUE != FALSE)
#define vSecPrim_HasSupportUInt64OfGeneral()                                                        (TRUE != FALSE)
#define vSecPrim_HasTDesEnabledOfCipher()                                                           (TRUE != FALSE)
#define vSecPrim_HasUseVstdLibOfGeneral()                                                           (TRUE != FALSE)
#define vSecPrim_HasUserConfigFileOfGeneral()                                                         /**< Deactivateable: 'vSecPrim_UserConfigFileOfGeneral' Reason: 'Parameter is not configured!' */
#define vSecPrim_HasWatchdogLevelOfGeneral()                                                        (TRUE != FALSE)
#define vSecPrim_HasPCConfig()                                                                      (TRUE != FALSE)
#define vSecPrim_HasANSI_X963EnabledOfKeyDerivationOfPCConfig()                                     (TRUE != FALSE)
#define vSecPrim_HasANSI_X963_SHA256EnabledOfKeyDerivationOfPCConfig()                              (TRUE != FALSE)
#define vSecPrim_HasANSI_X963_SHA512EnabledOfKeyDerivationOfPCConfig()                              (TRUE != FALSE)
#define vSecPrim_HasAeadChaCha20Poly1305EnabledOfCipherOfPCConfig()                                 (TRUE != FALSE)
#define vSecPrim_HasAes128EnabledOfCipherOfPCConfig()                                               (TRUE != FALSE)
#define vSecPrim_HasAes192EnabledOfCipherOfPCConfig()                                               (TRUE != FALSE)
#define vSecPrim_HasAes256EnabledOfCipherOfPCConfig()                                               (TRUE != FALSE)
#define vSecPrim_HasAesCcmEnabledOfCipherOfPCConfig()                                               (TRUE != FALSE)
#define vSecPrim_HasAesSpeedUpOfOptimizationOfPCConfig()                                            (TRUE != FALSE)
#define vSecPrim_HasCTRDRBGAES128SecurityStrengthOfGeneralOfPCConfig()                              (TRUE != FALSE)
#define vSecPrim_HasChaCha20EnabledOfCipherOfPCConfig()                                             (TRUE != FALSE)
#define vSecPrim_HasChaCha20SpeedUpOfOptimizationOfPCConfig()                                       (TRUE != FALSE)
#define vSecPrim_HasClearWorkspaceEnabledOfGeneralOfPCConfig()                                      (TRUE != FALSE)
#define vSecPrim_HasCmacEnabledOfMacOfPCConfig()                                                    (TRUE != FALSE)
#define vSecPrim_HasCtrDrbgEnabledOfRandomNumberGenerationOfPCConfig()                              (TRUE != FALSE)
#define vSecPrim_HasDesEnabledOfCipherOfPCConfig()                                                  (TRUE != FALSE)
#define vSecPrim_HasDrbgReseedIntervalOfGeneralOfPCConfig()                                         (TRUE != FALSE)
#define vSecPrim_HasECBD_GenericEnabledOfKeyExchangeOfPCConfig()                                    (TRUE != FALSE)
#define vSecPrim_HasECCEnabledOfKeyGenerationOfPCConfig()                                           (TRUE != FALSE)
#define vSecPrim_HasECDH_25519EnabledOfKeyExchangeOfPCConfig()                                      (TRUE != FALSE)
#define vSecPrim_HasECDH_GenericEnabledOfKeyExchangeOfPCConfig()                                    (TRUE != FALSE)
#define vSecPrim_HasECDSA_25519EnabledOfSignatureOfPCConfig()                                       (TRUE != FALSE)
#define vSecPrim_HasECDSA_GenericEnabledOfSignatureOfPCConfig()                                     (TRUE != FALSE)
#define vSecPrim_HasECPMaxKeySizeOfGeneralOfPCConfig()                                              (TRUE != FALSE)
#define vSecPrim_HasExpectedCompatibilityVersionOfPCConfig()                                          /**< Deactivateable: 'vSecPrim_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vSecPrim_HasFIPS186EnabledOfRandomNumberGenerationOfPCConfig()                              (TRUE != FALSE)
#define vSecPrim_HasFinalMagicNumberOfPCConfig()                                                      /**< Deactivateable: 'vSecPrim_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vSecPrim_HasGMacEnabledOfMacOfPCConfig()                                                    (TRUE != FALSE)
#define vSecPrim_HasGcmEnabledOfCipherOfPCConfig()                                                  (TRUE != FALSE)
#define vSecPrim_HasGeneratorCompatibilityVersionOfPCConfig()                                         /**< Deactivateable: 'vSecPrim_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vSecPrim_HasHKDF_HMAC_SHA256EnabledOfKeyDerivationOfPCConfig()                              (TRUE != FALSE)
#define vSecPrim_HasHKDF_HMAC_SHA384EnabledOfKeyDerivationOfPCConfig()                              (TRUE != FALSE)
#define vSecPrim_HasHKDF_SHA2_256_OnestepEnabledOfKeyDerivationOfPCConfig()                         (TRUE != FALSE)
#define vSecPrim_HasHMacRMD160EnabledOfMacOfPCConfig()                                              (TRUE != FALSE)
#define vSecPrim_HasHMacSHA1EnabledOfMacOfPCConfig()                                                (TRUE != FALSE)
#define vSecPrim_HasHMacSHA2_256EnabledOfMacOfPCConfig()                                            (TRUE != FALSE)
#define vSecPrim_HasHMacSHA2_384EnabledOfMacOfPCConfig()                                            (TRUE != FALSE)
#define vSecPrim_HasHashDrbgEnabledOfRandomNumberGenerationOfPCConfig()                             (TRUE != FALSE)
#define vSecPrim_HasInitDataHashCodeOfPCConfig()                                                      /**< Deactivateable: 'vSecPrim_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vSecPrim_HasMD5EnabledOfHashOfPCConfig()                                                    (TRUE != FALSE)
#define vSecPrim_HasPKCS5EnabledOfKeyDerivationOfPCConfig()                                         (TRUE != FALSE)
#define vSecPrim_HasPKCS5HMacSHA256EnabledOfKeyDerivationOfPCConfig()                               (TRUE != FALSE)
#define vSecPrim_HasPoly1305EnabledOfMacOfPCConfig()                                                (TRUE != FALSE)
#define vSecPrim_HasRC2EnabledOfCipherOfPCConfig()                                                  (TRUE != FALSE)
#define vSecPrim_HasRIPEMD160EnabledOfHashOfPCConfig()                                              (TRUE != FALSE)
#define vSecPrim_HasRSAMaxKeySizeOfGeneralOfPCConfig()                                              (TRUE != FALSE)
#define vSecPrim_HasRSA_OAEP_SHA1EnabledOfCipherOfPCConfig()                                        (TRUE != FALSE)
#define vSecPrim_HasRSA_OAEP_SHA2_256EnabledOfCipherOfPCConfig()                                    (TRUE != FALSE)
#define vSecPrim_HasRSA_PSS_RIPEMD160EnabledOfSignatureOfPCConfig()                                 (TRUE != FALSE)
#define vSecPrim_HasRSA_PSS_SHA1EnabledOfSignatureOfPCConfig()                                      (TRUE != FALSE)
#define vSecPrim_HasRSA_PSS_SHA2_256EnabledOfSignatureOfPCConfig()                                  (TRUE != FALSE)
#define vSecPrim_HasRSA_V15EnabledOfCipherOfPCConfig()                                              (TRUE != FALSE)
#define vSecPrim_HasRSA_V15_RIPEMD160EnabledOfSignatureOfPCConfig()                                 (TRUE != FALSE)
#define vSecPrim_HasRSA_V15_SHA1EnabledOfSignatureOfPCConfig()                                      (TRUE != FALSE)
#define vSecPrim_HasRSA_V15_SHA2_256EnabledOfSignatureOfPCConfig()                                  (TRUE != FALSE)
#define vSecPrim_HasSHA1EnabledOfHashOfPCConfig()                                                   (TRUE != FALSE)
#define vSecPrim_HasSHA2_256EnabledOfHashOfPCConfig()                                               (TRUE != FALSE)
#define vSecPrim_HasSHA2_512EnabledOfHashOfPCConfig()                                               (TRUE != FALSE)
#define vSecPrim_HasSHA3EnabledOfHashOfPCConfig()                                                   (TRUE != FALSE)
#define vSecPrim_HasSPAKE2pEnabledOfKeyExchangeOfPCConfig()                                         (TRUE != FALSE)
#define vSecPrim_HasSPAKE2pMaxAADSizeOfGeneralOfPCConfig()                                          (TRUE != FALSE)
#define vSecPrim_HasSPAKE2pPreambleOKMLengthOfGeneralOfPCConfig()                                   (TRUE != FALSE)
#define vSecPrim_HasSha1SpeedUpOfOptimizationOfPCConfig()                                           (TRUE != FALSE)
#define vSecPrim_HasSha256SpeedUpOfOptimizationOfPCConfig()                                         (TRUE != FALSE)
#define vSecPrim_HasSha512SpeedUpOfOptimizationOfPCConfig()                                         (TRUE != FALSE)
#define vSecPrim_HasSipHashEnabledOfMacOfPCConfig()                                                 (TRUE != FALSE)
#define vSecPrim_HasSizeOfEsltLengthOfGeneralOfPCConfig()                                           (TRUE != FALSE)
#define vSecPrim_HasSupportUInt64OfGeneralOfPCConfig()                                              (TRUE != FALSE)
#define vSecPrim_HasTDesEnabledOfCipherOfPCConfig()                                                 (TRUE != FALSE)
#define vSecPrim_HasUseVstdLibOfGeneralOfPCConfig()                                                 (TRUE != FALSE)
#define vSecPrim_HasUserConfigFileOfGeneralOfPCConfig()                                               /**< Deactivateable: 'vSecPrim_PCConfig.UserConfigFileOfGeneral' Reason: 'Parameter is not configured!' */
#define vSecPrim_HasWatchdogLevelOfGeneralOfPCConfig()                                              (TRUE != FALSE)
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
  \defgroup  vSecPrimPBGetRootDataMacros  vSecPrim Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vSecPrim_GetLTConfigIdxOfPBConfig()                                                           /**< Deactivateable: 'vSecPrim_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vSecPrim_GetPCConfigIdxOfPBConfig()                                                           /**< Deactivateable: 'vSecPrim_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPBHasMacros  vSecPrim Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vSecPrim_HasPBConfig()                                                                        /**< Deactivateable: 'vSecPrim_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vSecPrim_HasLTConfigIdxOfPBConfig()                                                           /**< Deactivateable: 'vSecPrim_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vSecPrim_HasPCConfigIdxOfPBConfig()                                                           /**< Deactivateable: 'vSecPrim_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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





/****************************************************************************
** Some processors (like C28x) define char as 16-bit value which needs to be
** overwritten than, e.g. by # define actLOW_BYTE(x) ((x) & 0xFFu)
** This is used in
** * actBigNumber.c
** * actDataConversion.c
** * actDataConversion.h
***************************************************************************/
#ifndef actLOW_BYTE
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
# define actLOW_BYTE(x)                                               (x)
#endif


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vSecPrimPCValueTypes  vSecPrim Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for vSecPrim_ANSI_X963EnabledOfKeyDerivation */
typedef boolean vSecPrim_ANSI_X963EnabledOfKeyDerivationType;

/**   \brief  value based type definition for vSecPrim_ANSI_X963_SHA256EnabledOfKeyDerivation */
typedef boolean vSecPrim_ANSI_X963_SHA256EnabledOfKeyDerivationType;

/**   \brief  value based type definition for vSecPrim_ANSI_X963_SHA512EnabledOfKeyDerivation */
typedef boolean vSecPrim_ANSI_X963_SHA512EnabledOfKeyDerivationType;

/**   \brief  value based type definition for vSecPrim_AeadChaCha20Poly1305EnabledOfCipher */
typedef boolean vSecPrim_AeadChaCha20Poly1305EnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_Aes128EnabledOfCipher */
typedef boolean vSecPrim_Aes128EnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_Aes192EnabledOfCipher */
typedef boolean vSecPrim_Aes192EnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_Aes256EnabledOfCipher */
typedef boolean vSecPrim_Aes256EnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_AesCcmEnabledOfCipher */
typedef boolean vSecPrim_AesCcmEnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_AesSpeedUpOfOptimization */
typedef uint8 vSecPrim_AesSpeedUpOfOptimizationType;

/**   \brief  value based type definition for vSecPrim_CTRDRBGAES128SecurityStrengthOfGeneral */
typedef uint8 vSecPrim_CTRDRBGAES128SecurityStrengthOfGeneralType;

/**   \brief  value based type definition for vSecPrim_ChaCha20EnabledOfCipher */
typedef boolean vSecPrim_ChaCha20EnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_ChaCha20SpeedUpOfOptimization */
typedef uint8 vSecPrim_ChaCha20SpeedUpOfOptimizationType;

/**   \brief  value based type definition for vSecPrim_ClearWorkspaceEnabledOfGeneral */
typedef boolean vSecPrim_ClearWorkspaceEnabledOfGeneralType;

/**   \brief  value based type definition for vSecPrim_CmacEnabledOfMac */
typedef boolean vSecPrim_CmacEnabledOfMacType;

/**   \brief  value based type definition for vSecPrim_CtrDrbgEnabledOfRandomNumberGeneration */
typedef boolean vSecPrim_CtrDrbgEnabledOfRandomNumberGenerationType;

/**   \brief  value based type definition for vSecPrim_DesEnabledOfCipher */
typedef boolean vSecPrim_DesEnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_DrbgReseedIntervalOfGeneral */
typedef uint32 vSecPrim_DrbgReseedIntervalOfGeneralType;

/**   \brief  value based type definition for vSecPrim_ECBD_GenericEnabledOfKeyExchange */
typedef boolean vSecPrim_ECBD_GenericEnabledOfKeyExchangeType;

/**   \brief  value based type definition for vSecPrim_ECCEnabledOfKeyGeneration */
typedef boolean vSecPrim_ECCEnabledOfKeyGenerationType;

/**   \brief  value based type definition for vSecPrim_ECDH_25519EnabledOfKeyExchange */
typedef boolean vSecPrim_ECDH_25519EnabledOfKeyExchangeType;

/**   \brief  value based type definition for vSecPrim_ECDH_GenericEnabledOfKeyExchange */
typedef boolean vSecPrim_ECDH_GenericEnabledOfKeyExchangeType;

/**   \brief  value based type definition for vSecPrim_ECDSA_25519EnabledOfSignature */
typedef boolean vSecPrim_ECDSA_25519EnabledOfSignatureType;

/**   \brief  value based type definition for vSecPrim_ECDSA_GenericEnabledOfSignature */
typedef boolean vSecPrim_ECDSA_GenericEnabledOfSignatureType;

/**   \brief  value based type definition for vSecPrim_ECPMaxKeySizeOfGeneral */
typedef uint8 vSecPrim_ECPMaxKeySizeOfGeneralType;

/**   \brief  value based type definition for vSecPrim_FIPS186EnabledOfRandomNumberGeneration */
typedef boolean vSecPrim_FIPS186EnabledOfRandomNumberGenerationType;

/**   \brief  value based type definition for vSecPrim_GMacEnabledOfMac */
typedef boolean vSecPrim_GMacEnabledOfMacType;

/**   \brief  value based type definition for vSecPrim_GcmEnabledOfCipher */
typedef boolean vSecPrim_GcmEnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_HKDF_HMAC_SHA256EnabledOfKeyDerivation */
typedef boolean vSecPrim_HKDF_HMAC_SHA256EnabledOfKeyDerivationType;

/**   \brief  value based type definition for vSecPrim_HKDF_HMAC_SHA384EnabledOfKeyDerivation */
typedef boolean vSecPrim_HKDF_HMAC_SHA384EnabledOfKeyDerivationType;

/**   \brief  value based type definition for vSecPrim_HKDF_SHA2_256_OnestepEnabledOfKeyDerivation */
typedef boolean vSecPrim_HKDF_SHA2_256_OnestepEnabledOfKeyDerivationType;

/**   \brief  value based type definition for vSecPrim_HMacRMD160EnabledOfMac */
typedef boolean vSecPrim_HMacRMD160EnabledOfMacType;

/**   \brief  value based type definition for vSecPrim_HMacSHA1EnabledOfMac */
typedef boolean vSecPrim_HMacSHA1EnabledOfMacType;

/**   \brief  value based type definition for vSecPrim_HMacSHA2_256EnabledOfMac */
typedef boolean vSecPrim_HMacSHA2_256EnabledOfMacType;

/**   \brief  value based type definition for vSecPrim_HMacSHA2_384EnabledOfMac */
typedef boolean vSecPrim_HMacSHA2_384EnabledOfMacType;

/**   \brief  value based type definition for vSecPrim_HashDrbgEnabledOfRandomNumberGeneration */
typedef boolean vSecPrim_HashDrbgEnabledOfRandomNumberGenerationType;

/**   \brief  value based type definition for vSecPrim_MD5EnabledOfHash */
typedef boolean vSecPrim_MD5EnabledOfHashType;

/**   \brief  value based type definition for vSecPrim_PKCS5EnabledOfKeyDerivation */
typedef boolean vSecPrim_PKCS5EnabledOfKeyDerivationType;

/**   \brief  value based type definition for vSecPrim_PKCS5HMacSHA256EnabledOfKeyDerivation */
typedef boolean vSecPrim_PKCS5HMacSHA256EnabledOfKeyDerivationType;

/**   \brief  value based type definition for vSecPrim_Poly1305EnabledOfMac */
typedef boolean vSecPrim_Poly1305EnabledOfMacType;

/**   \brief  value based type definition for vSecPrim_RC2EnabledOfCipher */
typedef boolean vSecPrim_RC2EnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_RIPEMD160EnabledOfHash */
typedef boolean vSecPrim_RIPEMD160EnabledOfHashType;

/**   \brief  value based type definition for vSecPrim_RSAMaxKeySizeOfGeneral */
typedef uint8 vSecPrim_RSAMaxKeySizeOfGeneralType;

/**   \brief  value based type definition for vSecPrim_RSA_OAEP_SHA1EnabledOfCipher */
typedef boolean vSecPrim_RSA_OAEP_SHA1EnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_RSA_OAEP_SHA2_256EnabledOfCipher */
typedef boolean vSecPrim_RSA_OAEP_SHA2_256EnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_RSA_PSS_RIPEMD160EnabledOfSignature */
typedef boolean vSecPrim_RSA_PSS_RIPEMD160EnabledOfSignatureType;

/**   \brief  value based type definition for vSecPrim_RSA_PSS_SHA1EnabledOfSignature */
typedef boolean vSecPrim_RSA_PSS_SHA1EnabledOfSignatureType;

/**   \brief  value based type definition for vSecPrim_RSA_PSS_SHA2_256EnabledOfSignature */
typedef boolean vSecPrim_RSA_PSS_SHA2_256EnabledOfSignatureType;

/**   \brief  value based type definition for vSecPrim_RSA_V15EnabledOfCipher */
typedef boolean vSecPrim_RSA_V15EnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_RSA_V15_RIPEMD160EnabledOfSignature */
typedef boolean vSecPrim_RSA_V15_RIPEMD160EnabledOfSignatureType;

/**   \brief  value based type definition for vSecPrim_RSA_V15_SHA1EnabledOfSignature */
typedef boolean vSecPrim_RSA_V15_SHA1EnabledOfSignatureType;

/**   \brief  value based type definition for vSecPrim_RSA_V15_SHA2_256EnabledOfSignature */
typedef boolean vSecPrim_RSA_V15_SHA2_256EnabledOfSignatureType;

/**   \brief  value based type definition for vSecPrim_SHA1EnabledOfHash */
typedef boolean vSecPrim_SHA1EnabledOfHashType;

/**   \brief  value based type definition for vSecPrim_SHA2_256EnabledOfHash */
typedef boolean vSecPrim_SHA2_256EnabledOfHashType;

/**   \brief  value based type definition for vSecPrim_SHA2_512EnabledOfHash */
typedef boolean vSecPrim_SHA2_512EnabledOfHashType;

/**   \brief  value based type definition for vSecPrim_SHA3EnabledOfHash */
typedef boolean vSecPrim_SHA3EnabledOfHashType;

/**   \brief  value based type definition for vSecPrim_SPAKE2pEnabledOfKeyExchange */
typedef boolean vSecPrim_SPAKE2pEnabledOfKeyExchangeType;

/**   \brief  value based type definition for vSecPrim_SPAKE2pMaxAADSizeOfGeneral */
typedef uint8 vSecPrim_SPAKE2pMaxAADSizeOfGeneralType;

/**   \brief  value based type definition for vSecPrim_SPAKE2pPreambleOKMLengthOfGeneral */
typedef uint8 vSecPrim_SPAKE2pPreambleOKMLengthOfGeneralType;

/**   \brief  value based type definition for vSecPrim_Sha1SpeedUpOfOptimization */
typedef uint8 vSecPrim_Sha1SpeedUpOfOptimizationType;

/**   \brief  value based type definition for vSecPrim_Sha256SpeedUpOfOptimization */
typedef uint8 vSecPrim_Sha256SpeedUpOfOptimizationType;

/**   \brief  value based type definition for vSecPrim_Sha512SpeedUpOfOptimization */
typedef uint8 vSecPrim_Sha512SpeedUpOfOptimizationType;

/**   \brief  value based type definition for vSecPrim_SipHashEnabledOfMac */
typedef boolean vSecPrim_SipHashEnabledOfMacType;

/**   \brief  value based type definition for vSecPrim_SizeOfEsltLengthOfGeneral */
typedef uint8 vSecPrim_SizeOfEsltLengthOfGeneralType;

/**   \brief  value based type definition for vSecPrim_SupportUInt64OfGeneral */
typedef boolean vSecPrim_SupportUInt64OfGeneralType;

/**   \brief  value based type definition for vSecPrim_TDesEnabledOfCipher */
typedef boolean vSecPrim_TDesEnabledOfCipherType;

/**   \brief  value based type definition for vSecPrim_UseVstdLibOfGeneral */
typedef boolean vSecPrim_UseVstdLibOfGeneralType;

/**   \brief  value based type definition for vSecPrim_WatchdogLevelOfGeneral */
typedef uint8 vSecPrim_WatchdogLevelOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vSecPrimPCRootPointerTypes  vSecPrim Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to vSecPrim_AesSpeedUpOfOptimizationOfPCConfig */
typedef P2CONST(vSecPrim_AesSpeedUpOfOptimizationType, TYPEDEF, VSECPRIM_CONST) vSecPrim_AesSpeedUpOfOptimizationOfPCConfigPtrType;

/**   \brief  type used to point to vSecPrim_CTRDRBGAES128SecurityStrengthOfGeneralOfPCConfig */
typedef P2CONST(vSecPrim_CTRDRBGAES128SecurityStrengthOfGeneralType, TYPEDEF, VSECPRIM_CONST) vSecPrim_CTRDRBGAES128SecurityStrengthOfGeneralOfPCConfigPtrType;

/**   \brief  type used to point to vSecPrim_ChaCha20SpeedUpOfOptimizationOfPCConfig */
typedef P2CONST(vSecPrim_ChaCha20SpeedUpOfOptimizationType, TYPEDEF, VSECPRIM_CONST) vSecPrim_ChaCha20SpeedUpOfOptimizationOfPCConfigPtrType;

/**   \brief  type used to point to vSecPrim_ECPMaxKeySizeOfGeneralOfPCConfig */
typedef P2CONST(vSecPrim_ECPMaxKeySizeOfGeneralType, TYPEDEF, VSECPRIM_CONST) vSecPrim_ECPMaxKeySizeOfGeneralOfPCConfigPtrType;

/**   \brief  type used to point to vSecPrim_RSAMaxKeySizeOfGeneralOfPCConfig */
typedef P2CONST(vSecPrim_RSAMaxKeySizeOfGeneralType, TYPEDEF, VSECPRIM_CONST) vSecPrim_RSAMaxKeySizeOfGeneralOfPCConfigPtrType;

/**   \brief  type used to point to vSecPrim_Sha1SpeedUpOfOptimizationOfPCConfig */
typedef P2CONST(vSecPrim_Sha1SpeedUpOfOptimizationType, TYPEDEF, VSECPRIM_CONST) vSecPrim_Sha1SpeedUpOfOptimizationOfPCConfigPtrType;

/**   \brief  type used to point to vSecPrim_Sha256SpeedUpOfOptimizationOfPCConfig */
typedef P2CONST(vSecPrim_Sha256SpeedUpOfOptimizationType, TYPEDEF, VSECPRIM_CONST) vSecPrim_Sha256SpeedUpOfOptimizationOfPCConfigPtrType;

/**   \brief  type used to point to vSecPrim_Sha512SpeedUpOfOptimizationOfPCConfig */
typedef P2CONST(vSecPrim_Sha512SpeedUpOfOptimizationType, TYPEDEF, VSECPRIM_CONST) vSecPrim_Sha512SpeedUpOfOptimizationOfPCConfigPtrType;

/**   \brief  type used to point to vSecPrim_SizeOfEsltLengthOfGeneralOfPCConfig */
typedef P2CONST(vSecPrim_SizeOfEsltLengthOfGeneralType, TYPEDEF, VSECPRIM_CONST) vSecPrim_SizeOfEsltLengthOfGeneralOfPCConfigPtrType;

/**   \brief  type used to point to vSecPrim_WatchdogLevelOfGeneralOfPCConfig */
typedef P2CONST(vSecPrim_WatchdogLevelOfGeneralType, TYPEDEF, VSECPRIM_CONST) vSecPrim_WatchdogLevelOfGeneralOfPCConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  vSecPrimPCRootValueTypes  vSecPrim Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in vSecPrim_PCConfig */
typedef struct svSecPrim_PCConfigType
{
  uint8 vSecPrim_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vSecPrim_PCConfigType;

typedef vSecPrim_PCConfigType vSecPrim_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vSecPrimPBValueTypes  vSecPrim Value Types (POST_BUILD)
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
  \defgroup  vSecPrimPBRootValueTypes  vSecPrim Root Value Types (POST_BUILD)
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






#if !defined (VSECPRIM_NOUNIT_CSLUNIT)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

#endif



#endif /* VSECPRIM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vSecPrim_Cfg.h
 *********************************************************************************************************************/


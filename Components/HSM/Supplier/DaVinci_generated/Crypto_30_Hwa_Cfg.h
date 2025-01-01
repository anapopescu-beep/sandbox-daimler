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
 *            Module: Crypto_30_Hwa
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_Hwa_Cfg.h
 *   Generation Time: 2023-04-04 15:31:22
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined (CRYPTO_30_HWA_CFG_H)
#define CRYPTO_30_HWA_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Csm_Types.h"
#include "Crypto_30_Hwa_Types.h"
/* PRQA S 0759 EOF */ /* MD_MSR_Union */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef CRYPTO_30_HWA_USE_DUMMY_STATEMENT
#define CRYPTO_30_HWA_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_HWA_DUMMY_STATEMENT
#define CRYPTO_30_HWA_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_HWA_DUMMY_STATEMENT_CONST
#define CRYPTO_30_HWA_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_HWA_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CRYPTO_30_HWA_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CRYPTO_30_HWA_ATOMIC_VARIABLE_ACCESS
#define CRYPTO_30_HWA_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CRYPTO_30_HWA_PROCESSOR_TC322L
#define CRYPTO_30_HWA_PROCESSOR_TC322L
#endif
#ifndef CRYPTO_30_HWA_COMP_TASKING
#define CRYPTO_30_HWA_COMP_TASKING
#endif
#ifndef CRYPTO_30_HWA_GEN_GENERATOR_MSR
#define CRYPTO_30_HWA_GEN_GENERATOR_MSR
#endif
#ifndef CRYPTO_30_HWA_CPUTYPE_BITORDER_LSB2MSB
#define CRYPTO_30_HWA_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CRYPTO_30_HWA_CONFIGURATION_VARIANT_PRECOMPILE
#define CRYPTO_30_HWA_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CRYPTO_30_HWA_CONFIGURATION_VARIANT_LINKTIME
#define CRYPTO_30_HWA_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CRYPTO_30_HWA_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CRYPTO_30_HWA_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CRYPTO_30_HWA_CONFIGURATION_VARIANT
#define CRYPTO_30_HWA_CONFIGURATION_VARIANT CRYPTO_30_HWA_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CRYPTO_30_HWA_POSTBUILD_VARIANT_SUPPORT
#define CRYPTO_30_HWA_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#ifdef _MICROSOFT_C_VTT_
#define CRYPTO_30_HWA_USE_VTT STD_ON
#else
#define CRYPTO_30_HWA_USE_VTT STD_OFF
#endif
/* Microsar Define Block for Boolean and Integers */
#define CRYPTO_30_HWA_DEV_ERROR_DETECT                                                              STD_ON 
#define CRYPTO_30_HWA_CLEAR_WORKSPACE_BUFFERS                                                       STD_OFF 
#define CRYPTO_30_HWA_TRNG_PREFETCH_CAPACITY                                                        32u 
#define CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT                                                  STD_OFF 
#define CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE                                                     4096u 
#define CRYPTO_30_HWA_MAX_INPUT_LENGTH                                                              100u 
#define CRYPTO_30_HWA_SIZE_OF_TARGET_KEY_LENGTH                                                     2u 
#define CRYPTO_30_HWA_SIZE_OF_ITERATION_COUNTER                                                     1u 
#define CRYPTO_30_HWA_MAX_OUTPUT_KEY_LENGTH                                                         32u 
#define CRYPTO_30_HWA_ADD_ZERO_OCTET                                                                STD_ON 
#define CRYPTO_30_HWA_KEY_DERIVE                                                                    STD_OFF 
#define CRYPTO_30_HWA_KEY_ELEMENTS                                                                  STD_ON 
#define CRYPTO_30_HWA_KEY_TYPES                                                                     STD_ON 

/* Symbolic Name Define Block */
#define CryptoConf_CryptoDriverObject_vHsm_Hwa_HighPrio                                             0u 
#define CryptoConf_CryptoDriverObject_vHsm_Hwa                                                      1u 
#define CryptoConf_CryptoKey_CryptoKey_Fbl_Fips186                                                  30001u 
#define CryptoConf_CryptoKey_CryptoKey_Fbl_HashDummy                                                30002u 
#define CryptoConf_CryptoKey_RomKey0                                                                30004u 
#define CryptoConf_CryptoKey_vHsm_Hal_Hardware                                                      30005u 


/* The following defines describes the used primitives.
 * They are set together in various permutations consisting of
 * (Service | Family | Mode | Second Family) without prefixed CRYPTO_ALOGFAM and CRYPTO_ALGOMODE.
 * So, a configured encryption service with AES in CBC Mode without secondary family would result in 
 * CRYPTO_30_HWA_ENCRYPT_AES_ECB_NOT_SET or CRYPTO_30_HWA_AES_ECB.
 */
#define CRYPTO_30_HWA_PRIMITIVE_AES                                                                 STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_AES_CBC                                                             STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_AES_CMAC                                                            STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_AES_CTR                                                             STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_AES_CUSTOM                                                          STD_OFF
#define CRYPTO_30_HWA_PRIMITIVE_AES_ECB                                                             STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_AES_GCM                                                             STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV                                                          STD_OFF
#define CRYPTO_30_HWA_PRIMITIVE_ECCANSI                                                             STD_OFF
#define CRYPTO_30_HWA_PRIMITIVE_ECCANSI_NOT_SET                                                     STD_OFF
#define CRYPTO_30_HWA_PRIMITIVE_ECCANSI_P256R1                                                      STD_OFF
#define CRYPTO_30_HWA_PRIMITIVE_ECCNIST                                                             STD_OFF
#define CRYPTO_30_HWA_PRIMITIVE_ECCNIST_NOT_SET                                                     STD_OFF
#define CRYPTO_30_HWA_PRIMITIVE_ECCNIST_P256R1                                                      STD_OFF
#define CRYPTO_30_HWA_PRIMITIVE_ECCSEC                                                              STD_OFF
#define CRYPTO_30_HWA_PRIMITIVE_ECCSEC_NOT_SET                                                      STD_OFF
#define CRYPTO_30_HWA_PRIMITIVE_ECCSEC_P256R1                                                       STD_OFF
#define CRYPTO_30_HWA_PRIMITIVE_ED25519                                                             STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_ED25519_ED25519CTX                                                  STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_ED25519_ED25519PH                                                   STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_ED25519_ED25519PURE                                                 STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_RNG                                                                 STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_RNG_NOT_SET                                                         STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_SHA2_256                                                            STD_OFF
#define CRYPTO_30_HWA_PRIMITIVE_SHA2_256_NOT_SET                                                    STD_OFF

#ifndef CRYPTO_30_HWA_DEV_ERROR_DETECT
#define CRYPTO_30_HWA_DEV_ERROR_DETECT STD_ON
#endif
#ifndef CRYPTO_30_HWA_DEV_ERROR_REPORT
#define CRYPTO_30_HWA_DEV_ERROR_REPORT STD_ON
#endif
#define CRYPTO_30_HWA_SERVICE_MAC_VERIFY                                                            STD_ON
#define CRYPTO_30_HWA_SERVICE_MAC_GENERATE                                                          STD_ON
#define CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY                                                      STD_ON
#define CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE                                                    STD_ON
#define CRYPTO_30_HWA_SERVICE_ENCRYPT                                                               STD_ON
#define CRYPTO_30_HWA_SERVICE_DECRYPT                                                               STD_ON
#define CRYPTO_30_HWA_SERVICE_AEADENCRYPT                                                           STD_ON
#define CRYPTO_30_HWA_SERVICE_AEADDECRYPT                                                           STD_ON
#define CRYPTO_30_HWA_SERVICE_HASH                                                                  STD_OFF
#define CRYPTO_30_HWA_SERVICE_RANDOM                                                                STD_ON
#define CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER                                                          STD_ON

/* Switch for Trng prefetching */
#define CRYPTO_30_HWA_TRNG_PREFETCHING                                                              STD_ON

/* Switch for data slicing */
#define CRYPTO_30_HWA_DATA_SLICING                                                                  STD_ON

/* Trng buffer ceiling */
#if ((CRYPTO_30_HWA_TRNG_PREFETCH_CAPACITY % CRYPTO_30_HWA_TRNG_BLOCK_LENGTH_BYTES) > 0u)
# define CRYPTO_30_HWA_TRNG_PREFETCH_CORRECTION 1u
#else
# define CRYPTO_30_HWA_TRNG_PREFETCH_CORRECTION 0u
#endif
#define CRYPTO_30_HWA_TRNG_PREFETCH_CAPACITY_CEIL              (CRYPTO_30_HWA_TRNG_BLOCK_LENGTH_BYTES * ((CRYPTO_30_HWA_TRNG_PREFETCH_CAPACITY / CRYPTO_30_HWA_TRNG_BLOCK_LENGTH_BYTES) + (CRYPTO_30_HWA_TRNG_PREFETCH_CORRECTION)))

/* Round non preemptive chunk size to AES hardware block size for performance */
#define CRYPTO_30_HWA_DIVIDE_AES_CHUNKSIZE_AND_BLOCKSIZE (CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE / CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES)
#if (CRYPTO_30_HWA_DIVIDE_AES_CHUNKSIZE_AND_BLOCKSIZE > 0u)
# define CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES  CRYPTO_30_HWA_DIVIDE_AES_CHUNKSIZE_AND_BLOCKSIZE
#else
# define CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES  (1u)
#endif

/* Round non preemptive chunk size to TRNG hardware block size for performance */
#define CRYPTO_30_HWA_DIVIDE_TRNG_CHUNKSIZE_AND_BLOCKSIZE (CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE / CRYPTO_30_HWA_TRNG_BLOCK_LENGTH_BYTES)
#if (CRYPTO_30_HWA_DIVIDE_TRNG_CHUNKSIZE_AND_BLOCKSIZE > 0u)
# define CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE_ROUNDED_TRNG  CRYPTO_30_HWA_DIVIDE_TRNG_CHUNKSIZE_AND_BLOCKSIZE
#else
# define CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE_ROUNDED_TRNG  (1u)
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_HwaPCDataSwitches  Crypto_30_Hwa Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYPTO_30_HWA_ADDZEROOCTETOFKEYDERIVE                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_AddZeroOctetOfKeyDerive' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_HWA_AESDECRYPT                                                                    STD_ON
#define CRYPTO_30_HWA_WORKSPACEOFAESDECRYPT                                                         STD_ON
#define CRYPTO_30_HWA_AESENCRYPT                                                                    STD_ON
#define CRYPTO_30_HWA_WORKSPACEOFAESENCRYPT                                                         STD_ON
#define CRYPTO_30_HWA_AESGCMDECRYPT                                                                 STD_ON
#define CRYPTO_30_HWA_WORKSPACEOFAESGCMDECRYPT                                                      STD_ON
#define CRYPTO_30_HWA_AESGCMENCRYPT                                                                 STD_ON
#define CRYPTO_30_HWA_WORKSPACEOFAESGCMENCRYPT                                                      STD_ON
#define CRYPTO_30_HWA_AESGCMSIVDECRYPT                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_AesGcmSivDecrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_HWA_WORKSPACEOFAESGCMSIVDECRYPT                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_AesGcmSivDecrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_HWA_AESGCMSIVENCRYPT                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_AesGcmSivEncrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_HWA_WORKSPACEOFAESGCMSIVENCRYPT                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_AesGcmSivEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_HWA_CLEARWORKSPACEBUFFERSOFGENERAL                                                STD_ON
#define CRYPTO_30_HWA_CMACAESGENERATE                                                               STD_ON
#define CRYPTO_30_HWA_WORKSPACEOFCMACAESGENERATE                                                    STD_ON
#define CRYPTO_30_HWA_CMACAESVERIFY                                                                 STD_ON
#define CRYPTO_30_HWA_WORKSPACEOFCMACAESVERIFY                                                      STD_ON
#define CRYPTO_30_HWA_DEVERRORDETECTOFGENERAL                                                       STD_ON
#define CRYPTO_30_HWA_DRIVEROBJECTOFKEYDERIVE                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_DriverObjectOfKeyDerive' Reason: 'Reference is not configured!' */
#define CRYPTO_30_HWA_DRIVEROBJECTSTATE                                                             STD_ON
#define CRYPTO_30_HWA_ECP256GENERATE                                                                STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_EcP256Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_HWA_WORKSPACEOFECP256GENERATE                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_EcP256Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_HWA_ECP256VERIFY                                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_EcP256Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_HWA_WORKSPACEOFECP256VERIFY                                                       STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_EcP256Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_HWA_ED25519GENERATE                                                               STD_ON
#define CRYPTO_30_HWA_WORKSPACEOFED25519GENERATE                                                    STD_ON
#define CRYPTO_30_HWA_ED25519VERIFY                                                                 STD_ON
#define CRYPTO_30_HWA_WORKSPACEOFED25519VERIFY                                                      STD_ON
#define CRYPTO_30_HWA_EXPECTEDCOMPATIBILITYVERSION                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_HWA_FAMILYTOHASHMAPPING                                                           STD_ON
#define CRYPTO_30_HWA_FINALMAGICNUMBER                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_HWA_GENERATORCOMPATIBILITYVERSION                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_HWA_INITDATAHASHCODE                                                              STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_HWA_KEYMAP                                                                        STD_ON
#define CRYPTO_30_HWA_AGGREGATEDCRYPTOKEYIDOFKEYMAP                                                 STD_ON
#define CRYPTO_30_HWA_KEYIDOFKEYMAP                                                                 STD_ON
#define CRYPTO_30_HWA_LOCK                                                                          STD_ON
#define CRYPTO_30_HWA_MAXINPUTLENGTHOFKEYDERIVE                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_MaxInputLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_HWA_MAXOUTPUTKEYLENGTHOFKEYDERIVE                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_MaxOutputKeyLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_HWA_NONPREEMPTIVECHUNKSIZEOFGENERAL                                               STD_ON
#define CRYPTO_30_HWA_OBJECTINFO                                                                    STD_ON
#define CRYPTO_30_HWA_AESDECRYPTIDXOFOBJECTINFO                                                     STD_ON
#define CRYPTO_30_HWA_AESDECRYPTUSEDOFOBJECTINFO                                                    STD_ON
#define CRYPTO_30_HWA_AESENCRYPTIDXOFOBJECTINFO                                                     STD_ON
#define CRYPTO_30_HWA_AESENCRYPTUSEDOFOBJECTINFO                                                    STD_ON
#define CRYPTO_30_HWA_AESGCMDECRYPTIDXOFOBJECTINFO                                                  STD_ON
#define CRYPTO_30_HWA_AESGCMDECRYPTUSEDOFOBJECTINFO                                                 STD_ON
#define CRYPTO_30_HWA_AESGCMENCRYPTIDXOFOBJECTINFO                                                  STD_ON
#define CRYPTO_30_HWA_AESGCMENCRYPTUSEDOFOBJECTINFO                                                 STD_ON
#define CRYPTO_30_HWA_AESGCMSIVDECRYPTIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.AesGcmSivDecryptIdx' Reason: 'the optional indirection is deactivated because AesGcmSivDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_HWA_AESGCMSIVDECRYPTUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.AesGcmSivDecryptUsed' Reason: 'the optional indirection is deactivated because AesGcmSivDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_HWA_AESGCMSIVENCRYPTIDXOFOBJECTINFO                                               STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.AesGcmSivEncryptIdx' Reason: 'the optional indirection is deactivated because AesGcmSivEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_HWA_AESGCMSIVENCRYPTUSEDOFOBJECTINFO                                              STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.AesGcmSivEncryptUsed' Reason: 'the optional indirection is deactivated because AesGcmSivEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_HWA_CMACAESGENERATEIDXOFOBJECTINFO                                                STD_ON
#define CRYPTO_30_HWA_CMACAESGENERATEUSEDOFOBJECTINFO                                               STD_ON
#define CRYPTO_30_HWA_CMACAESVERIFYIDXOFOBJECTINFO                                                  STD_ON
#define CRYPTO_30_HWA_CMACAESVERIFYUSEDOFOBJECTINFO                                                 STD_ON
#define CRYPTO_30_HWA_ECP256GENERATEIDXOFOBJECTINFO                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.EcP256GenerateIdx' Reason: 'the optional indirection is deactivated because EcP256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_HWA_ECP256GENERATEUSEDOFOBJECTINFO                                                STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.EcP256GenerateUsed' Reason: 'the optional indirection is deactivated because EcP256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_HWA_ECP256VERIFYIDXOFOBJECTINFO                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.EcP256VerifyIdx' Reason: 'the optional indirection is deactivated because EcP256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_HWA_ECP256VERIFYUSEDOFOBJECTINFO                                                  STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.EcP256VerifyUsed' Reason: 'the optional indirection is deactivated because EcP256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_HWA_ED25519GENERATEIDXOFOBJECTINFO                                                STD_ON
#define CRYPTO_30_HWA_ED25519GENERATEUSEDOFOBJECTINFO                                               STD_ON
#define CRYPTO_30_HWA_ED25519VERIFYIDXOFOBJECTINFO                                                  STD_ON
#define CRYPTO_30_HWA_ED25519VERIFYUSEDOFOBJECTINFO                                                 STD_ON
#define CRYPTO_30_HWA_MASKEDBITSOFOBJECTINFO                                                        STD_ON
#define CRYPTO_30_HWA_SHA256IDXOFOBJECTINFO                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.SHA256Idx' Reason: 'the optional indirection is deactivated because SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_HWA_SHA256USEDOFOBJECTINFO                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.SHA256Used' Reason: 'the optional indirection is deactivated because SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CRYPTO_30_HWA_TRNGIDXOFOBJECTINFO                                                           STD_ON
#define CRYPTO_30_HWA_TRNGUSEDOFOBJECTINFO                                                          STD_ON
#define CRYPTO_30_HWA_QUEUE                                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_Queue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_HWA_SHA256                                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_SHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CRYPTO_30_HWA_WORKSPACEOFSHA256                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_SHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CRYPTO_30_HWA_SIZEOFAESDECRYPT                                                              STD_ON
#define CRYPTO_30_HWA_SIZEOFAESENCRYPT                                                              STD_ON
#define CRYPTO_30_HWA_SIZEOFAESGCMDECRYPT                                                           STD_ON
#define CRYPTO_30_HWA_SIZEOFAESGCMENCRYPT                                                           STD_ON
#define CRYPTO_30_HWA_SIZEOFCMACAESGENERATE                                                         STD_ON
#define CRYPTO_30_HWA_SIZEOFCMACAESVERIFY                                                           STD_ON
#define CRYPTO_30_HWA_SIZEOFDRIVEROBJECTSTATE                                                       STD_ON
#define CRYPTO_30_HWA_SIZEOFED25519GENERATE                                                         STD_ON
#define CRYPTO_30_HWA_SIZEOFED25519VERIFY                                                           STD_ON
#define CRYPTO_30_HWA_SIZEOFFAMILYTOHASHMAPPING                                                     STD_ON
#define CRYPTO_30_HWA_SIZEOFITERATIONCOUNTEROFKEYDERIVE                                             STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_SizeOfIterationCounterOfKeyDerive' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_HWA_SIZEOFKEYMAP                                                                  STD_ON
#define CRYPTO_30_HWA_SIZEOFLOCK                                                                    STD_ON
#define CRYPTO_30_HWA_SIZEOFOBJECTINFO                                                              STD_ON
#define CRYPTO_30_HWA_SIZEOFTARGETKEYLENGTHOFKEYDERIVE                                              STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_SizeOfTargetKeyLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_HWA_SIZEOFTRNG                                                                    STD_ON
#define CRYPTO_30_HWA_TRNG                                                                          STD_ON
#define CRYPTO_30_HWA_WORKSPACEOFTRNG                                                               STD_ON
#define CRYPTO_30_HWA_TRNGPREFETCHCAPACITYOFGENERAL                                                 STD_ON
#define CRYPTO_30_HWA_TRNGPREFETCHWITHINTERRUPTOFGENERAL                                            STD_ON
#define CRYPTO_30_HWA_UNIONWS_VHSM_HWA                                                              STD_ON
#define CRYPTO_30_HWA_UNIONWS_VHSM_HWA_HIGHPRIO                                                     STD_ON
#define CRYPTO_30_HWA_PCCONFIG                                                                      STD_ON
#define CRYPTO_30_HWA_ADDZEROOCTETOFKEYDERIVEOFPCCONFIG                                             STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.AddZeroOctetOfKeyDerive' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_HWA_AESDECRYPTOFPCCONFIG                                                          STD_ON
#define CRYPTO_30_HWA_AESENCRYPTOFPCCONFIG                                                          STD_ON
#define CRYPTO_30_HWA_AESGCMDECRYPTOFPCCONFIG                                                       STD_ON
#define CRYPTO_30_HWA_AESGCMENCRYPTOFPCCONFIG                                                       STD_ON
#define CRYPTO_30_HWA_CLEARWORKSPACEBUFFERSOFGENERALOFPCCONFIG                                      STD_ON
#define CRYPTO_30_HWA_CMACAESGENERATEOFPCCONFIG                                                     STD_ON
#define CRYPTO_30_HWA_CMACAESVERIFYOFPCCONFIG                                                       STD_ON
#define CRYPTO_30_HWA_DEVERRORDETECTOFGENERALOFPCCONFIG                                             STD_ON
#define CRYPTO_30_HWA_DRIVEROBJECTOFKEYDERIVEOFPCCONFIG                                             STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.DriverObjectOfKeyDerive' Reason: 'Reference is not configured!' */
#define CRYPTO_30_HWA_DRIVEROBJECTSTATEOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_HWA_ED25519GENERATEOFPCCONFIG                                                     STD_ON
#define CRYPTO_30_HWA_ED25519VERIFYOFPCCONFIG                                                       STD_ON
#define CRYPTO_30_HWA_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                        STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_HWA_FAMILYTOHASHMAPPINGOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_HWA_FINALMAGICNUMBEROFPCCONFIG                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_HWA_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                       STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_HWA_INITDATAHASHCODEOFPCCONFIG                                                    STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_HWA_KEYMAPOFPCCONFIG                                                              STD_ON
#define CRYPTO_30_HWA_LOCKOFPCCONFIG                                                                STD_ON
#define CRYPTO_30_HWA_MAXINPUTLENGTHOFKEYDERIVEOFPCCONFIG                                           STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.MaxInputLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_HWA_MAXOUTPUTKEYLENGTHOFKEYDERIVEOFPCCONFIG                                       STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.MaxOutputKeyLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_HWA_NONPREEMPTIVECHUNKSIZEOFGENERALOFPCCONFIG                                     STD_ON
#define CRYPTO_30_HWA_OBJECTINFOOFPCCONFIG                                                          STD_ON
#define CRYPTO_30_HWA_SIZEOFAESDECRYPTOFPCCONFIG                                                    STD_ON
#define CRYPTO_30_HWA_SIZEOFAESENCRYPTOFPCCONFIG                                                    STD_ON
#define CRYPTO_30_HWA_SIZEOFAESGCMDECRYPTOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_HWA_SIZEOFAESGCMENCRYPTOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_HWA_SIZEOFCMACAESGENERATEOFPCCONFIG                                               STD_ON
#define CRYPTO_30_HWA_SIZEOFCMACAESVERIFYOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_HWA_SIZEOFDRIVEROBJECTSTATEOFPCCONFIG                                             STD_ON
#define CRYPTO_30_HWA_SIZEOFED25519GENERATEOFPCCONFIG                                               STD_ON
#define CRYPTO_30_HWA_SIZEOFED25519VERIFYOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_HWA_SIZEOFFAMILYTOHASHMAPPINGOFPCCONFIG                                           STD_ON
#define CRYPTO_30_HWA_SIZEOFITERATIONCOUNTEROFKEYDERIVEOFPCCONFIG                                   STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.SizeOfIterationCounterOfKeyDerive' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_HWA_SIZEOFKEYMAPOFPCCONFIG                                                        STD_ON
#define CRYPTO_30_HWA_SIZEOFLOCKOFPCCONFIG                                                          STD_ON
#define CRYPTO_30_HWA_SIZEOFOBJECTINFOOFPCCONFIG                                                    STD_ON
#define CRYPTO_30_HWA_SIZEOFTARGETKEYLENGTHOFKEYDERIVEOFPCCONFIG                                    STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.SizeOfTargetKeyLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_HWA_SIZEOFTRNGOFPCCONFIG                                                          STD_ON
#define CRYPTO_30_HWA_TRNGOFPCCONFIG                                                                STD_ON
#define CRYPTO_30_HWA_TRNGPREFETCHCAPACITYOFGENERALOFPCCONFIG                                       STD_ON
#define CRYPTO_30_HWA_TRNGPREFETCHWITHINTERRUPTOFGENERALOFPCCONFIG                                  STD_ON
#define CRYPTO_30_HWA_UNIONWS_VHSM_HWAOFPCCONFIG                                                    STD_ON
#define CRYPTO_30_HWA_UNIONWS_VHSM_HWA_HIGHPRIOOFPCCONFIG                                           STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCMinNumericValueDefines  Crypto_30_Hwa Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CRYPTO_30_HWA_MIN_DRIVEROBJECTSTATE                                                         0u
#define CRYPTO_30_HWA_MIN_LOCK                                                                      0u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCMaxNumericValueDefines  Crypto_30_Hwa Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CRYPTO_30_HWA_MAX_DRIVEROBJECTSTATE                                                         255u
#define CRYPTO_30_HWA_MAX_LOCK                                                                      4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCNoReferenceDefines  Crypto_30_Hwa No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CRYPTO_30_HWA_NO_AESDECRYPTIDXOFOBJECTINFO                                                  255u
#define CRYPTO_30_HWA_NO_AESENCRYPTIDXOFOBJECTINFO                                                  255u
#define CRYPTO_30_HWA_NO_AESGCMDECRYPTIDXOFOBJECTINFO                                               255u
#define CRYPTO_30_HWA_NO_AESGCMENCRYPTIDXOFOBJECTINFO                                               255u
#define CRYPTO_30_HWA_NO_AESGCMSIVDECRYPTIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_HWA_NO_AESGCMSIVENCRYPTIDXOFOBJECTINFO                                            255u
#define CRYPTO_30_HWA_NO_CMACAESGENERATEIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_HWA_NO_CMACAESVERIFYIDXOFOBJECTINFO                                               255u
#define CRYPTO_30_HWA_NO_ECP256GENERATEIDXOFOBJECTINFO                                              255u
#define CRYPTO_30_HWA_NO_ECP256VERIFYIDXOFOBJECTINFO                                                255u
#define CRYPTO_30_HWA_NO_ED25519GENERATEIDXOFOBJECTINFO                                             255u
#define CRYPTO_30_HWA_NO_ED25519VERIFYIDXOFOBJECTINFO                                               255u
#define CRYPTO_30_HWA_NO_SHA256IDXOFOBJECTINFO                                                      255u
#define CRYPTO_30_HWA_NO_TRNGIDXOFOBJECTINFO                                                        255u
#define CRYPTO_30_HWA_NO_EXPECTEDCOMPATIBILITYVERSION                                               65535u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCMaskedBitDefines  Crypto_30_Hwa Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define CRYPTO_30_HWA_AESDECRYPTUSEDOFOBJECTINFO_MASK                                               0x0100u
#define CRYPTO_30_HWA_AESENCRYPTUSEDOFOBJECTINFO_MASK                                               0x0080u
#define CRYPTO_30_HWA_AESGCMDECRYPTUSEDOFOBJECTINFO_MASK                                            0x0040u
#define CRYPTO_30_HWA_AESGCMENCRYPTUSEDOFOBJECTINFO_MASK                                            0x0020u
#define CRYPTO_30_HWA_CMACAESGENERATEUSEDOFOBJECTINFO_MASK                                          0x0010u
#define CRYPTO_30_HWA_CMACAESVERIFYUSEDOFOBJECTINFO_MASK                                            0x0008u
#define CRYPTO_30_HWA_ED25519GENERATEUSEDOFOBJECTINFO_MASK                                          0x0004u
#define CRYPTO_30_HWA_ED25519VERIFYUSEDOFOBJECTINFO_MASK                                            0x0002u
#define CRYPTO_30_HWA_TRNGUSEDOFOBJECTINFO_MASK                                                     0x0001u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCIsReducedToDefineDefines  Crypto_30_Hwa Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFAESDECRYPT                                                   STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFAESENCRYPT                                                   STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFAESGCMDECRYPT                                                STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFAESGCMENCRYPT                                                STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFAESGCMSIVDECRYPT                                             STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFAESGCMSIVENCRYPT                                             STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFCMACAESGENERATE                                              STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFCMACAESVERIFY                                                STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFECP256GENERATE                                               STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFECP256VERIFY                                                 STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFED25519GENERATE                                              STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFED25519VERIFY                                                STD_OFF
#define CRYPTO_30_HWA_ISDEF_FAMILYTOHASHMAPPING                                                     STD_OFF
#define CRYPTO_30_HWA_ISDEF_AGGREGATEDCRYPTOKEYIDOFKEYMAP                                           STD_OFF
#define CRYPTO_30_HWA_ISDEF_KEYIDOFKEYMAP                                                           STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESDECRYPTIDXOFOBJECTINFO                                               STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESDECRYPTUSEDOFOBJECTINFO                                              STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESENCRYPTIDXOFOBJECTINFO                                               STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESENCRYPTUSEDOFOBJECTINFO                                              STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESGCMDECRYPTIDXOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESGCMDECRYPTUSEDOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESGCMENCRYPTIDXOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESGCMENCRYPTUSEDOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESGCMSIVDECRYPTIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESGCMSIVDECRYPTUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESGCMSIVENCRYPTIDXOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESGCMSIVENCRYPTUSEDOFOBJECTINFO                                        STD_OFF
#define CRYPTO_30_HWA_ISDEF_CMACAESGENERATEIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_HWA_ISDEF_CMACAESGENERATEUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_HWA_ISDEF_CMACAESVERIFYIDXOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_HWA_ISDEF_CMACAESVERIFYUSEDOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_HWA_ISDEF_ECP256GENERATEIDXOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_HWA_ISDEF_ECP256GENERATEUSEDOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_HWA_ISDEF_ECP256VERIFYIDXOFOBJECTINFO                                             STD_OFF
#define CRYPTO_30_HWA_ISDEF_ECP256VERIFYUSEDOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_HWA_ISDEF_ED25519GENERATEIDXOFOBJECTINFO                                          STD_OFF
#define CRYPTO_30_HWA_ISDEF_ED25519GENERATEUSEDOFOBJECTINFO                                         STD_OFF
#define CRYPTO_30_HWA_ISDEF_ED25519VERIFYIDXOFOBJECTINFO                                            STD_OFF
#define CRYPTO_30_HWA_ISDEF_ED25519VERIFYUSEDOFOBJECTINFO                                           STD_OFF
#define CRYPTO_30_HWA_ISDEF_MASKEDBITSOFOBJECTINFO                                                  STD_OFF
#define CRYPTO_30_HWA_ISDEF_SHA256IDXOFOBJECTINFO                                                   STD_OFF
#define CRYPTO_30_HWA_ISDEF_SHA256USEDOFOBJECTINFO                                                  STD_OFF
#define CRYPTO_30_HWA_ISDEF_TRNGIDXOFOBJECTINFO                                                     STD_OFF
#define CRYPTO_30_HWA_ISDEF_TRNGUSEDOFOBJECTINFO                                                    STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFSHA256                                                       STD_OFF
#define CRYPTO_30_HWA_ISDEF_WORKSPACEOFTRNG                                                         STD_OFF
#define CRYPTO_30_HWA_ISDEF_ADDZEROOCTETOFKEYDERIVEOFPCCONFIG                                       STD_OFF
#define CRYPTO_30_HWA_ISDEF_AESDECRYPTOFPCCONFIG                                                    STD_ON
#define CRYPTO_30_HWA_ISDEF_AESENCRYPTOFPCCONFIG                                                    STD_ON
#define CRYPTO_30_HWA_ISDEF_AESGCMDECRYPTOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_HWA_ISDEF_AESGCMENCRYPTOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_HWA_ISDEF_CMACAESGENERATEOFPCCONFIG                                               STD_ON
#define CRYPTO_30_HWA_ISDEF_CMACAESVERIFYOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_HWA_ISDEF_DRIVEROBJECTOFKEYDERIVEOFPCCONFIG                                       STD_OFF
#define CRYPTO_30_HWA_ISDEF_DRIVEROBJECTSTATEOFPCCONFIG                                             STD_ON
#define CRYPTO_30_HWA_ISDEF_ED25519GENERATEOFPCCONFIG                                               STD_ON
#define CRYPTO_30_HWA_ISDEF_ED25519VERIFYOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_HWA_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                  STD_OFF
#define CRYPTO_30_HWA_ISDEF_FAMILYTOHASHMAPPINGOFPCCONFIG                                           STD_ON
#define CRYPTO_30_HWA_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                              STD_OFF
#define CRYPTO_30_HWA_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                 STD_OFF
#define CRYPTO_30_HWA_ISDEF_INITDATAHASHCODEOFPCCONFIG                                              STD_OFF
#define CRYPTO_30_HWA_ISDEF_KEYMAPOFPCCONFIG                                                        STD_ON
#define CRYPTO_30_HWA_ISDEF_LOCKOFPCCONFIG                                                          STD_ON
#define CRYPTO_30_HWA_ISDEF_MAXINPUTLENGTHOFKEYDERIVEOFPCCONFIG                                     STD_OFF
#define CRYPTO_30_HWA_ISDEF_MAXOUTPUTKEYLENGTHOFKEYDERIVEOFPCCONFIG                                 STD_OFF
#define CRYPTO_30_HWA_ISDEF_OBJECTINFOOFPCCONFIG                                                    STD_ON
#define CRYPTO_30_HWA_ISDEF_SIZEOFITERATIONCOUNTEROFKEYDERIVEOFPCCONFIG                             STD_OFF
#define CRYPTO_30_HWA_ISDEF_SIZEOFTARGETKEYLENGTHOFKEYDERIVEOFPCCONFIG                              STD_OFF
#define CRYPTO_30_HWA_ISDEF_TRNGOFPCCONFIG                                                          STD_ON
#define CRYPTO_30_HWA_ISDEF_UNIONWS_VHSM_HWAOFPCCONFIG                                              STD_ON
#define CRYPTO_30_HWA_ISDEF_UNIONWS_VHSM_HWA_HIGHPRIOOFPCCONFIG                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCEqualsAlwaysToDefines  Crypto_30_Hwa Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFAESDECRYPT                                                     
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFAESENCRYPT                                                     
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFAESGCMDECRYPT                                                  
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFAESGCMENCRYPT                                                  
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFAESGCMSIVDECRYPT                                               
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFAESGCMSIVENCRYPT                                               
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFCMACAESGENERATE                                                
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFCMACAESVERIFY                                                  
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFECP256GENERATE                                                 
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFECP256VERIFY                                                   
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFED25519GENERATE                                                
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFED25519VERIFY                                                  
#define CRYPTO_30_HWA_EQ2_FAMILYTOHASHMAPPING                                                       
#define CRYPTO_30_HWA_EQ2_AGGREGATEDCRYPTOKEYIDOFKEYMAP                                             
#define CRYPTO_30_HWA_EQ2_KEYIDOFKEYMAP                                                             
#define CRYPTO_30_HWA_EQ2_AESDECRYPTIDXOFOBJECTINFO                                                 
#define CRYPTO_30_HWA_EQ2_AESDECRYPTUSEDOFOBJECTINFO                                                
#define CRYPTO_30_HWA_EQ2_AESENCRYPTIDXOFOBJECTINFO                                                 
#define CRYPTO_30_HWA_EQ2_AESENCRYPTUSEDOFOBJECTINFO                                                
#define CRYPTO_30_HWA_EQ2_AESGCMDECRYPTIDXOFOBJECTINFO                                              
#define CRYPTO_30_HWA_EQ2_AESGCMDECRYPTUSEDOFOBJECTINFO                                             
#define CRYPTO_30_HWA_EQ2_AESGCMENCRYPTIDXOFOBJECTINFO                                              
#define CRYPTO_30_HWA_EQ2_AESGCMENCRYPTUSEDOFOBJECTINFO                                             
#define CRYPTO_30_HWA_EQ2_AESGCMSIVDECRYPTIDXOFOBJECTINFO                                           
#define CRYPTO_30_HWA_EQ2_AESGCMSIVDECRYPTUSEDOFOBJECTINFO                                          
#define CRYPTO_30_HWA_EQ2_AESGCMSIVENCRYPTIDXOFOBJECTINFO                                           
#define CRYPTO_30_HWA_EQ2_AESGCMSIVENCRYPTUSEDOFOBJECTINFO                                          
#define CRYPTO_30_HWA_EQ2_CMACAESGENERATEIDXOFOBJECTINFO                                            
#define CRYPTO_30_HWA_EQ2_CMACAESGENERATEUSEDOFOBJECTINFO                                           
#define CRYPTO_30_HWA_EQ2_CMACAESVERIFYIDXOFOBJECTINFO                                              
#define CRYPTO_30_HWA_EQ2_CMACAESVERIFYUSEDOFOBJECTINFO                                             
#define CRYPTO_30_HWA_EQ2_ECP256GENERATEIDXOFOBJECTINFO                                             
#define CRYPTO_30_HWA_EQ2_ECP256GENERATEUSEDOFOBJECTINFO                                            
#define CRYPTO_30_HWA_EQ2_ECP256VERIFYIDXOFOBJECTINFO                                               
#define CRYPTO_30_HWA_EQ2_ECP256VERIFYUSEDOFOBJECTINFO                                              
#define CRYPTO_30_HWA_EQ2_ED25519GENERATEIDXOFOBJECTINFO                                            
#define CRYPTO_30_HWA_EQ2_ED25519GENERATEUSEDOFOBJECTINFO                                           
#define CRYPTO_30_HWA_EQ2_ED25519VERIFYIDXOFOBJECTINFO                                              
#define CRYPTO_30_HWA_EQ2_ED25519VERIFYUSEDOFOBJECTINFO                                             
#define CRYPTO_30_HWA_EQ2_MASKEDBITSOFOBJECTINFO                                                    
#define CRYPTO_30_HWA_EQ2_SHA256IDXOFOBJECTINFO                                                     
#define CRYPTO_30_HWA_EQ2_SHA256USEDOFOBJECTINFO                                                    
#define CRYPTO_30_HWA_EQ2_TRNGIDXOFOBJECTINFO                                                       
#define CRYPTO_30_HWA_EQ2_TRNGUSEDOFOBJECTINFO                                                      
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFSHA256                                                         
#define CRYPTO_30_HWA_EQ2_WORKSPACEOFTRNG                                                           
#define CRYPTO_30_HWA_EQ2_ADDZEROOCTETOFKEYDERIVEOFPCCONFIG                                         
#define CRYPTO_30_HWA_EQ2_AESDECRYPTOFPCCONFIG                                                      Crypto_30_Hwa_AesDecrypt
#define CRYPTO_30_HWA_EQ2_AESENCRYPTOFPCCONFIG                                                      Crypto_30_Hwa_AesEncrypt
#define CRYPTO_30_HWA_EQ2_AESGCMDECRYPTOFPCCONFIG                                                   Crypto_30_Hwa_AesGcmDecrypt
#define CRYPTO_30_HWA_EQ2_AESGCMENCRYPTOFPCCONFIG                                                   Crypto_30_Hwa_AesGcmEncrypt
#define CRYPTO_30_HWA_EQ2_CMACAESGENERATEOFPCCONFIG                                                 Crypto_30_Hwa_CmacAesGenerate
#define CRYPTO_30_HWA_EQ2_CMACAESVERIFYOFPCCONFIG                                                   Crypto_30_Hwa_CmacAesVerify
#define CRYPTO_30_HWA_EQ2_DRIVEROBJECTOFKEYDERIVEOFPCCONFIG                                         
#define CRYPTO_30_HWA_EQ2_DRIVEROBJECTSTATEOFPCCONFIG                                               Crypto_30_Hwa_DriverObjectState.raw
#define CRYPTO_30_HWA_EQ2_ED25519GENERATEOFPCCONFIG                                                 Crypto_30_Hwa_Ed25519Generate
#define CRYPTO_30_HWA_EQ2_ED25519VERIFYOFPCCONFIG                                                   Crypto_30_Hwa_Ed25519Verify
#define CRYPTO_30_HWA_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                    
#define CRYPTO_30_HWA_EQ2_FAMILYTOHASHMAPPINGOFPCCONFIG                                             Crypto_30_Hwa_FamilyToHashMapping
#define CRYPTO_30_HWA_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                
#define CRYPTO_30_HWA_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                   
#define CRYPTO_30_HWA_EQ2_INITDATAHASHCODEOFPCCONFIG                                                
#define CRYPTO_30_HWA_EQ2_KEYMAPOFPCCONFIG                                                          Crypto_30_Hwa_KeyMap
#define CRYPTO_30_HWA_EQ2_LOCKOFPCCONFIG                                                            Crypto_30_Hwa_Lock.raw
#define CRYPTO_30_HWA_EQ2_MAXINPUTLENGTHOFKEYDERIVEOFPCCONFIG                                       
#define CRYPTO_30_HWA_EQ2_MAXOUTPUTKEYLENGTHOFKEYDERIVEOFPCCONFIG                                   
#define CRYPTO_30_HWA_EQ2_OBJECTINFOOFPCCONFIG                                                      Crypto_30_Hwa_ObjectInfo
#define CRYPTO_30_HWA_EQ2_SIZEOFITERATIONCOUNTEROFKEYDERIVEOFPCCONFIG                               
#define CRYPTO_30_HWA_EQ2_SIZEOFTARGETKEYLENGTHOFKEYDERIVEOFPCCONFIG                                
#define CRYPTO_30_HWA_EQ2_TRNGOFPCCONFIG                                                            Crypto_30_Hwa_Trng
#define CRYPTO_30_HWA_EQ2_UNIONWS_VHSM_HWAOFPCCONFIG                                                (&(Crypto_30_Hwa_UnionWS_vHsm_Hwa))
#define CRYPTO_30_HWA_EQ2_UNIONWS_VHSM_HWA_HIGHPRIOOFPCCONFIG                                       (&(Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio))
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCSymbolicInitializationPointers  Crypto_30_Hwa Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Crypto_30_Hwa_Config_Ptr                                                                    NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Crypto_30_Hwa' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCInitializationSymbols  Crypto_30_Hwa Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Crypto_30_Hwa_Config                                                                        NULL_PTR  /**< symbolic identifier which could be used to initialize 'Crypto_30_Hwa */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCGeneral  Crypto_30_Hwa General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CRYPTO_30_HWA_CHECK_INIT_POINTER                                                            STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CRYPTO_30_HWA_FINAL_MAGIC_NUMBER                                                            0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Crypto_30_Hwa */
#define CRYPTO_30_HWA_INDIVIDUAL_POSTBUILD                                                          STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Crypto_30_Hwa' is not configured to be postbuild capable. */
#define CRYPTO_30_HWA_INIT_DATA                                                                     CRYPTO_30_HWA_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CRYPTO_30_HWA_INIT_DATA_HASH_CODE                                                           271460434  /**< the precompile constant to validate the initialization structure at initialization time of Crypto_30_Hwa with a hashcode. The seed value is '0xFF1Eu' */
#define CRYPTO_30_HWA_USE_ECUM_BSW_ERROR_HOOK                                                       STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CRYPTO_30_HWA_USE_INIT_POINTER                                                              STD_OFF  /**< STD_ON if the init pointer Crypto_30_Hwa shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_HwaPBDataSwitches  Crypto_30_Hwa Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYPTO_30_HWA_PBCONFIG                                                                      STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_HWA_LTCONFIGIDXOFPBCONFIG                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_HWA_PCCONFIGIDXOFPBCONFIG                                                         STD_OFF  /**< Deactivateable: 'Crypto_30_Hwa_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPBIsReducedToDefineDefines  Crypto_30_Hwa Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYPTO_30_HWA_ISDEF_LTCONFIGIDXOFPBCONFIG                                                   STD_OFF
#define CRYPTO_30_HWA_ISDEF_PCCONFIGIDXOFPBCONFIG                                                   STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPBEqualsAlwaysToDefines  Crypto_30_Hwa Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYPTO_30_HWA_EQ2_LTCONFIGIDXOFPBCONFIG                                                     
#define CRYPTO_30_HWA_EQ2_PCCONFIGIDXOFPBCONFIG                                                     
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
  \defgroup  Crypto_30_HwaPCGetRootDataMacros  Crypto_30_Hwa Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Crypto_30_Hwa_IsAddZeroOctetOfKeyDeriveOfPCConfig()                                           /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.AddZeroOctetOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_GetDriverObjectOfKeyDeriveOfPCConfig()                                          /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.DriverObjectOfKeyDerive' Reason: 'Reference is not configured!' */
#define Crypto_30_Hwa_GetExpectedCompatibilityVersionOfPCConfig()                                     /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_Hwa_GetFinalMagicNumberOfPCConfig()                                                 /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_Hwa_GetGeneratorCompatibilityVersionOfPCConfig()                                    /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_Hwa_GetInitDataHashCodeOfPCConfig()                                                 /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_Hwa_GetMaxInputLengthOfKeyDeriveOfPCConfig()                                        /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.MaxInputLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_GetMaxOutputKeyLengthOfKeyDeriveOfPCConfig()                                    /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.MaxOutputKeyLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_GetSizeOfIterationCounterOfKeyDeriveOfPCConfig()                                /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.SizeOfIterationCounterOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_GetSizeOfTargetKeyLengthOfKeyDeriveOfPCConfig()                                 /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.SizeOfTargetKeyLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCGetConstantDuplicatedRootDataMacros  Crypto_30_Hwa Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Crypto_30_Hwa_GetAesDecryptOfPCConfig()                                                     Crypto_30_Hwa_AesDecrypt  /**< the pointer to Crypto_30_Hwa_AesDecrypt */
#define Crypto_30_Hwa_GetAesEncryptOfPCConfig()                                                     Crypto_30_Hwa_AesEncrypt  /**< the pointer to Crypto_30_Hwa_AesEncrypt */
#define Crypto_30_Hwa_GetAesGcmDecryptOfPCConfig()                                                  Crypto_30_Hwa_AesGcmDecrypt  /**< the pointer to Crypto_30_Hwa_AesGcmDecrypt */
#define Crypto_30_Hwa_GetAesGcmEncryptOfPCConfig()                                                  Crypto_30_Hwa_AesGcmEncrypt  /**< the pointer to Crypto_30_Hwa_AesGcmEncrypt */
#define Crypto_30_Hwa_IsClearWorkspaceBuffersOfGeneralOfPCConfig()                                  (((FALSE)) != FALSE)
#define Crypto_30_Hwa_GetCmacAesGenerateOfPCConfig()                                                Crypto_30_Hwa_CmacAesGenerate  /**< the pointer to Crypto_30_Hwa_CmacAesGenerate */
#define Crypto_30_Hwa_GetCmacAesVerifyOfPCConfig()                                                  Crypto_30_Hwa_CmacAesVerify  /**< the pointer to Crypto_30_Hwa_CmacAesVerify */
#define Crypto_30_Hwa_IsDevErrorDetectOfGeneralOfPCConfig()                                         (((TRUE)) != FALSE)
#define Crypto_30_Hwa_GetDriverObjectStateOfPCConfig()                                              Crypto_30_Hwa_DriverObjectState.raw  /**< the pointer to Crypto_30_Hwa_DriverObjectState */
#define Crypto_30_Hwa_GetEd25519GenerateOfPCConfig()                                                Crypto_30_Hwa_Ed25519Generate  /**< the pointer to Crypto_30_Hwa_Ed25519Generate */
#define Crypto_30_Hwa_GetEd25519VerifyOfPCConfig()                                                  Crypto_30_Hwa_Ed25519Verify  /**< the pointer to Crypto_30_Hwa_Ed25519Verify */
#define Crypto_30_Hwa_GetFamilyToHashMappingOfPCConfig()                                            Crypto_30_Hwa_FamilyToHashMapping  /**< the pointer to Crypto_30_Hwa_FamilyToHashMapping */
#define Crypto_30_Hwa_GetKeyMapOfPCConfig()                                                         Crypto_30_Hwa_KeyMap  /**< the pointer to Crypto_30_Hwa_KeyMap */
#define Crypto_30_Hwa_GetLockOfPCConfig()                                                           Crypto_30_Hwa_Lock.raw  /**< the pointer to Crypto_30_Hwa_Lock */
#define Crypto_30_Hwa_GetNonPreemptiveChunkSizeOfGeneralOfPCConfig()                                4096u
#define Crypto_30_Hwa_GetObjectInfoOfPCConfig()                                                     Crypto_30_Hwa_ObjectInfo  /**< the pointer to Crypto_30_Hwa_ObjectInfo */
#define Crypto_30_Hwa_GetSizeOfAesDecryptOfPCConfig()                                               1u  /**< the number of accomplishable value elements in Crypto_30_Hwa_AesDecrypt */
#define Crypto_30_Hwa_GetSizeOfAesEncryptOfPCConfig()                                               1u  /**< the number of accomplishable value elements in Crypto_30_Hwa_AesEncrypt */
#define Crypto_30_Hwa_GetSizeOfAesGcmDecryptOfPCConfig()                                            1u  /**< the number of accomplishable value elements in Crypto_30_Hwa_AesGcmDecrypt */
#define Crypto_30_Hwa_GetSizeOfAesGcmEncryptOfPCConfig()                                            1u  /**< the number of accomplishable value elements in Crypto_30_Hwa_AesGcmEncrypt */
#define Crypto_30_Hwa_GetSizeOfCmacAesGenerateOfPCConfig()                                          2u  /**< the number of accomplishable value elements in Crypto_30_Hwa_CmacAesGenerate */
#define Crypto_30_Hwa_GetSizeOfCmacAesVerifyOfPCConfig()                                            2u  /**< the number of accomplishable value elements in Crypto_30_Hwa_CmacAesVerify */
#define Crypto_30_Hwa_GetSizeOfEd25519GenerateOfPCConfig()                                          1u  /**< the number of accomplishable value elements in Crypto_30_Hwa_Ed25519Generate */
#define Crypto_30_Hwa_GetSizeOfEd25519VerifyOfPCConfig()                                            1u  /**< the number of accomplishable value elements in Crypto_30_Hwa_Ed25519Verify */
#define Crypto_30_Hwa_GetSizeOfFamilyToHashMappingOfPCConfig()                                      8u  /**< the number of accomplishable value elements in Crypto_30_Hwa_FamilyToHashMapping */
#define Crypto_30_Hwa_GetSizeOfKeyMapOfPCConfig()                                                   4u  /**< the number of accomplishable value elements in Crypto_30_Hwa_KeyMap */
#define Crypto_30_Hwa_GetSizeOfObjectInfoOfPCConfig()                                               2u  /**< the number of accomplishable value elements in Crypto_30_Hwa_ObjectInfo */
#define Crypto_30_Hwa_GetSizeOfTrngOfPCConfig()                                                     1u  /**< the number of accomplishable value elements in Crypto_30_Hwa_Trng */
#define Crypto_30_Hwa_GetTrngOfPCConfig()                                                           Crypto_30_Hwa_Trng  /**< the pointer to Crypto_30_Hwa_Trng */
#define Crypto_30_Hwa_GetTrngPrefetchCapacityOfGeneralOfPCConfig()                                  32u
#define Crypto_30_Hwa_IsTrngPrefetchWithInterruptOfGeneralOfPCConfig()                              (((FALSE)) != FALSE)
#define Crypto_30_Hwa_GetUnionWS_vHsm_HwaOfPCConfig()                                               (&(Crypto_30_Hwa_UnionWS_vHsm_Hwa))  /**< the pointer to Crypto_30_Hwa_UnionWS_vHsm_Hwa */
#define Crypto_30_Hwa_GetUnionWS_vHsm_Hwa_HighPrioOfPCConfig()                                      (&(Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio))  /**< the pointer to Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCGetDuplicatedRootDataMacros  Crypto_30_Hwa Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Crypto_30_Hwa_GetSizeOfDriverObjectStateOfPCConfig()                                        Crypto_30_Hwa_GetSizeOfObjectInfoOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_Hwa_DriverObjectState */
#define Crypto_30_Hwa_GetSizeOfLockOfPCConfig()                                                     Crypto_30_Hwa_GetSizeOfObjectInfoOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_Hwa_Lock */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCGetDataMacros  Crypto_30_Hwa Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Crypto_30_Hwa_GetWorkspaceOfAesDecrypt(Index)                                               (Crypto_30_Hwa_GetAesDecryptOfPCConfig()[(Index)].WorkspaceOfAesDecrypt)
#define Crypto_30_Hwa_GetWorkspaceOfAesEncrypt(Index)                                               (Crypto_30_Hwa_GetAesEncryptOfPCConfig()[(Index)].WorkspaceOfAesEncrypt)
#define Crypto_30_Hwa_GetWorkspaceOfAesGcmDecrypt(Index)                                            (Crypto_30_Hwa_GetAesGcmDecryptOfPCConfig()[(Index)].WorkspaceOfAesGcmDecrypt)
#define Crypto_30_Hwa_GetWorkspaceOfAesGcmEncrypt(Index)                                            (Crypto_30_Hwa_GetAesGcmEncryptOfPCConfig()[(Index)].WorkspaceOfAesGcmEncrypt)
#define Crypto_30_Hwa_GetWorkspaceOfAesGcmSivDecrypt(Index)                                           /**< Deactivateable: 'Crypto_30_Hwa_AesGcmSivDecrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_GetWorkspaceOfAesGcmSivEncrypt(Index)                                           /**< Deactivateable: 'Crypto_30_Hwa_AesGcmSivEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_GetWorkspaceOfCmacAesGenerate(Index)                                          (Crypto_30_Hwa_GetCmacAesGenerateOfPCConfig()[(Index)].WorkspaceOfCmacAesGenerate)
#define Crypto_30_Hwa_GetWorkspaceOfCmacAesVerify(Index)                                            (Crypto_30_Hwa_GetCmacAesVerifyOfPCConfig()[(Index)].WorkspaceOfCmacAesVerify)
#define Crypto_30_Hwa_GetDriverObjectState(Index)                                                   (Crypto_30_Hwa_GetDriverObjectStateOfPCConfig()[(Index)])
#define Crypto_30_Hwa_GetWorkspaceOfEcP256Generate(Index)                                             /**< Deactivateable: 'Crypto_30_Hwa_EcP256Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_GetWorkspaceOfEcP256Verify(Index)                                               /**< Deactivateable: 'Crypto_30_Hwa_EcP256Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_GetWorkspaceOfEd25519Generate(Index)                                          (Crypto_30_Hwa_GetEd25519GenerateOfPCConfig()[(Index)].WorkspaceOfEd25519Generate)
#define Crypto_30_Hwa_GetWorkspaceOfEd25519Verify(Index)                                            (Crypto_30_Hwa_GetEd25519VerifyOfPCConfig()[(Index)].WorkspaceOfEd25519Verify)
#define Crypto_30_Hwa_GetFamilyToHashMapping(Index)                                                 (Crypto_30_Hwa_GetFamilyToHashMappingOfPCConfig()[(Index)])
#define Crypto_30_Hwa_GetAggregatedCryptoKeyIdOfKeyMap(Index)                                       (Crypto_30_Hwa_GetKeyMapOfPCConfig()[(Index)].AggregatedCryptoKeyIdOfKeyMap)
#define Crypto_30_Hwa_GetKeyIdOfKeyMap(Index)                                                       (Crypto_30_Hwa_GetKeyMapOfPCConfig()[(Index)].KeyIdOfKeyMap)
#define Crypto_30_Hwa_GetLock(Index)                                                                (Crypto_30_Hwa_GetLockOfPCConfig()[(Index)])
#define Crypto_30_Hwa_GetAesDecryptIdxOfObjectInfo(Index)                                           (Crypto_30_Hwa_GetObjectInfoOfPCConfig()[(Index)].AesDecryptIdxOfObjectInfo)
#define Crypto_30_Hwa_GetAesEncryptIdxOfObjectInfo(Index)                                           (Crypto_30_Hwa_GetObjectInfoOfPCConfig()[(Index)].AesEncryptIdxOfObjectInfo)
#define Crypto_30_Hwa_GetAesGcmDecryptIdxOfObjectInfo(Index)                                        (Crypto_30_Hwa_GetObjectInfoOfPCConfig()[(Index)].AesGcmDecryptIdxOfObjectInfo)
#define Crypto_30_Hwa_GetAesGcmEncryptIdxOfObjectInfo(Index)                                        (Crypto_30_Hwa_GetObjectInfoOfPCConfig()[(Index)].AesGcmEncryptIdxOfObjectInfo)
#define Crypto_30_Hwa_GetAesGcmSivDecryptIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.AesGcmSivDecryptIdx' Reason: 'the optional indirection is deactivated because AesGcmSivDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_IsAesGcmSivDecryptUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.AesGcmSivDecryptUsed' Reason: 'the optional indirection is deactivated because AesGcmSivDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_GetAesGcmSivEncryptIdxOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.AesGcmSivEncryptIdx' Reason: 'the optional indirection is deactivated because AesGcmSivEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_IsAesGcmSivEncryptUsedOfObjectInfo(Index)                                       /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.AesGcmSivEncryptUsed' Reason: 'the optional indirection is deactivated because AesGcmSivEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_GetCmacAesGenerateIdxOfObjectInfo(Index)                                      (Crypto_30_Hwa_GetObjectInfoOfPCConfig()[(Index)].CmacAesGenerateIdxOfObjectInfo)
#define Crypto_30_Hwa_GetCmacAesVerifyIdxOfObjectInfo(Index)                                        (Crypto_30_Hwa_GetObjectInfoOfPCConfig()[(Index)].CmacAesVerifyIdxOfObjectInfo)
#define Crypto_30_Hwa_GetEcP256GenerateIdxOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.EcP256GenerateIdx' Reason: 'the optional indirection is deactivated because EcP256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_IsEcP256GenerateUsedOfObjectInfo(Index)                                         /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.EcP256GenerateUsed' Reason: 'the optional indirection is deactivated because EcP256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_GetEcP256VerifyIdxOfObjectInfo(Index)                                           /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.EcP256VerifyIdx' Reason: 'the optional indirection is deactivated because EcP256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_IsEcP256VerifyUsedOfObjectInfo(Index)                                           /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.EcP256VerifyUsed' Reason: 'the optional indirection is deactivated because EcP256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_GetEd25519GenerateIdxOfObjectInfo(Index)                                      (Crypto_30_Hwa_GetObjectInfoOfPCConfig()[(Index)].Ed25519GenerateIdxOfObjectInfo)
#define Crypto_30_Hwa_GetEd25519VerifyIdxOfObjectInfo(Index)                                        (Crypto_30_Hwa_GetObjectInfoOfPCConfig()[(Index)].Ed25519VerifyIdxOfObjectInfo)
#define Crypto_30_Hwa_GetMaskedBitsOfObjectInfo(Index)                                              (Crypto_30_Hwa_GetObjectInfoOfPCConfig()[(Index)].MaskedBitsOfObjectInfo)
#define Crypto_30_Hwa_GetSHA256IdxOfObjectInfo(Index)                                                 /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.SHA256Idx' Reason: 'the optional indirection is deactivated because SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_IsSHA256UsedOfObjectInfo(Index)                                                 /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.SHA256Used' Reason: 'the optional indirection is deactivated because SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_GetTrngIdxOfObjectInfo(Index)                                                 (Crypto_30_Hwa_GetObjectInfoOfPCConfig()[(Index)].TrngIdxOfObjectInfo)
#define Crypto_30_Hwa_GetQueue(Index)                                                                 /**< Deactivateable: 'Crypto_30_Hwa_Queue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_GetWorkspaceOfSHA256(Index)                                                     /**< Deactivateable: 'Crypto_30_Hwa_SHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_GetWorkspaceOfTrng(Index)                                                     (Crypto_30_Hwa_GetTrngOfPCConfig()[(Index)].WorkspaceOfTrng)
#define Crypto_30_Hwa_GetUnionWS_vHsm_Hwa()                                                         ((*(Crypto_30_Hwa_GetUnionWS_vHsm_HwaOfPCConfig())))
#define Crypto_30_Hwa_GetUnionWS_vHsm_Hwa_HighPrio()                                                ((*(Crypto_30_Hwa_GetUnionWS_vHsm_Hwa_HighPrioOfPCConfig())))
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCGetDeduplicatedDataMacros  Crypto_30_Hwa Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Crypto_30_Hwa_IsAddZeroOctetOfKeyDerive()                                                     /**< Deactivateable: 'Crypto_30_Hwa_AddZeroOctetOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_IsClearWorkspaceBuffersOfGeneral()                                            Crypto_30_Hwa_IsClearWorkspaceBuffersOfGeneralOfPCConfig()
#define Crypto_30_Hwa_IsDevErrorDetectOfGeneral()                                                   Crypto_30_Hwa_IsDevErrorDetectOfGeneralOfPCConfig()
#define Crypto_30_Hwa_GetDriverObjectOfKeyDerive()                                                    /**< Deactivateable: 'Crypto_30_Hwa_DriverObjectOfKeyDerive' Reason: 'Reference is not configured!' */
#define Crypto_30_Hwa_GetExpectedCompatibilityVersion()                                               /**< Deactivateable: 'Crypto_30_Hwa_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_Hwa_GetFinalMagicNumber()                                                           /**< Deactivateable: 'Crypto_30_Hwa_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_Hwa_GetGeneratorCompatibilityVersion()                                              /**< Deactivateable: 'Crypto_30_Hwa_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_Hwa_GetInitDataHashCode()                                                           /**< Deactivateable: 'Crypto_30_Hwa_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_Hwa_GetMaxInputLengthOfKeyDerive()                                                  /**< Deactivateable: 'Crypto_30_Hwa_MaxInputLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_GetMaxOutputKeyLengthOfKeyDerive()                                              /**< Deactivateable: 'Crypto_30_Hwa_MaxOutputKeyLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_GetNonPreemptiveChunkSizeOfGeneral()                                          Crypto_30_Hwa_GetNonPreemptiveChunkSizeOfGeneralOfPCConfig()
#define Crypto_30_Hwa_IsAesDecryptUsedOfObjectInfo(Index)                                           (((boolean)(Crypto_30_Hwa_GetAesDecryptIdxOfObjectInfo(Index) != CRYPTO_30_HWA_NO_AESDECRYPTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_Hwa_AesDecrypt */
#define Crypto_30_Hwa_IsAesEncryptUsedOfObjectInfo(Index)                                           (((boolean)(Crypto_30_Hwa_GetAesEncryptIdxOfObjectInfo(Index) != CRYPTO_30_HWA_NO_AESENCRYPTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_Hwa_AesEncrypt */
#define Crypto_30_Hwa_IsAesGcmDecryptUsedOfObjectInfo(Index)                                        (((boolean)(Crypto_30_Hwa_GetAesGcmDecryptIdxOfObjectInfo(Index) != CRYPTO_30_HWA_NO_AESGCMDECRYPTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_Hwa_AesGcmDecrypt */
#define Crypto_30_Hwa_IsAesGcmEncryptUsedOfObjectInfo(Index)                                        (((boolean)(Crypto_30_Hwa_GetAesGcmEncryptIdxOfObjectInfo(Index) != CRYPTO_30_HWA_NO_AESGCMENCRYPTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_Hwa_AesGcmEncrypt */
#define Crypto_30_Hwa_IsCmacAesGenerateUsedOfObjectInfo(Index)                                      (((boolean)(Crypto_30_Hwa_GetCmacAesGenerateIdxOfObjectInfo(Index) != CRYPTO_30_HWA_NO_CMACAESGENERATEIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_Hwa_CmacAesGenerate */
#define Crypto_30_Hwa_IsCmacAesVerifyUsedOfObjectInfo(Index)                                        (((boolean)(Crypto_30_Hwa_GetCmacAesVerifyIdxOfObjectInfo(Index) != CRYPTO_30_HWA_NO_CMACAESVERIFYIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_Hwa_CmacAesVerify */
#define Crypto_30_Hwa_IsEd25519GenerateUsedOfObjectInfo(Index)                                      (((boolean)(Crypto_30_Hwa_GetEd25519GenerateIdxOfObjectInfo(Index) != CRYPTO_30_HWA_NO_ED25519GENERATEIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_Hwa_Ed25519Generate */
#define Crypto_30_Hwa_IsEd25519VerifyUsedOfObjectInfo(Index)                                        (((boolean)(Crypto_30_Hwa_GetEd25519VerifyIdxOfObjectInfo(Index) != CRYPTO_30_HWA_NO_ED25519VERIFYIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_Hwa_Ed25519Verify */
#define Crypto_30_Hwa_IsTrngUsedOfObjectInfo(Index)                                                 (((boolean)(Crypto_30_Hwa_GetTrngIdxOfObjectInfo(Index) != CRYPTO_30_HWA_NO_TRNGIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_Hwa_Trng */
#define Crypto_30_Hwa_GetSizeOfAesDecrypt()                                                         Crypto_30_Hwa_GetSizeOfAesDecryptOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfAesEncrypt()                                                         Crypto_30_Hwa_GetSizeOfAesEncryptOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfAesGcmDecrypt()                                                      Crypto_30_Hwa_GetSizeOfAesGcmDecryptOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfAesGcmEncrypt()                                                      Crypto_30_Hwa_GetSizeOfAesGcmEncryptOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfCmacAesGenerate()                                                    Crypto_30_Hwa_GetSizeOfCmacAesGenerateOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfCmacAesVerify()                                                      Crypto_30_Hwa_GetSizeOfCmacAesVerifyOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfDriverObjectState()                                                  Crypto_30_Hwa_GetSizeOfDriverObjectStateOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfEd25519Generate()                                                    Crypto_30_Hwa_GetSizeOfEd25519GenerateOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfEd25519Verify()                                                      Crypto_30_Hwa_GetSizeOfEd25519VerifyOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfFamilyToHashMapping()                                                Crypto_30_Hwa_GetSizeOfFamilyToHashMappingOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfIterationCounterOfKeyDerive()                                          /**< Deactivateable: 'Crypto_30_Hwa_SizeOfIterationCounterOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_GetSizeOfKeyMap()                                                             Crypto_30_Hwa_GetSizeOfKeyMapOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfLock()                                                               Crypto_30_Hwa_GetSizeOfLockOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfObjectInfo()                                                         Crypto_30_Hwa_GetSizeOfObjectInfoOfPCConfig()
#define Crypto_30_Hwa_GetSizeOfTargetKeyLengthOfKeyDerive()                                           /**< Deactivateable: 'Crypto_30_Hwa_SizeOfTargetKeyLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_GetSizeOfTrng()                                                               Crypto_30_Hwa_GetSizeOfTrngOfPCConfig()
#define Crypto_30_Hwa_GetTrngPrefetchCapacityOfGeneral()                                            Crypto_30_Hwa_GetTrngPrefetchCapacityOfGeneralOfPCConfig()
#define Crypto_30_Hwa_IsTrngPrefetchWithInterruptOfGeneral()                                        Crypto_30_Hwa_IsTrngPrefetchWithInterruptOfGeneralOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCSetDataMacros  Crypto_30_Hwa Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Crypto_30_Hwa_SetDriverObjectState(Index, Value)                                            Crypto_30_Hwa_GetDriverObjectStateOfPCConfig()[(Index)] = (Value)
#define Crypto_30_Hwa_SetLock(Index, Value)                                                         Crypto_30_Hwa_GetLockOfPCConfig()[(Index)] = (Value)
#define Crypto_30_Hwa_SetQueue(Index, Value)                                                          /**< Deactivateable: 'Crypto_30_Hwa_Queue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_SetUnionWS_vHsm_Hwa(Value)                                                    (*(Crypto_30_Hwa_GetUnionWS_vHsm_HwaOfPCConfig())) = (Value)
#define Crypto_30_Hwa_SetUnionWS_vHsm_Hwa_HighPrio(Value)                                           (*(Crypto_30_Hwa_GetUnionWS_vHsm_Hwa_HighPrioOfPCConfig())) = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCGetAddressOfDataMacros  Crypto_30_Hwa Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Crypto_30_Hwa_GetAddrUnionWS_vHsm_Hwa()                                                     (&Crypto_30_Hwa_GetUnionWS_vHsm_Hwa())
#define Crypto_30_Hwa_GetAddrUnionWS_vHsm_Hwa_HighPrio()                                            (&Crypto_30_Hwa_GetUnionWS_vHsm_Hwa_HighPrio())
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCHasMacros  Crypto_30_Hwa Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Crypto_30_Hwa_HasAddZeroOctetOfKeyDerive()                                                    /**< Deactivateable: 'Crypto_30_Hwa_AddZeroOctetOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_HasAesDecrypt()                                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasWorkspaceOfAesDecrypt()                                                    (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesEncrypt()                                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasWorkspaceOfAesEncrypt()                                                    (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesGcmDecrypt()                                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasWorkspaceOfAesGcmDecrypt()                                                 (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesGcmEncrypt()                                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasWorkspaceOfAesGcmEncrypt()                                                 (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesGcmSivDecrypt()                                                           /**< Deactivateable: 'Crypto_30_Hwa_AesGcmSivDecrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_Hwa_HasWorkspaceOfAesGcmSivDecrypt()                                                /**< Deactivateable: 'Crypto_30_Hwa_AesGcmSivDecrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_HasAesGcmSivEncrypt()                                                           /**< Deactivateable: 'Crypto_30_Hwa_AesGcmSivEncrypt' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_Hwa_HasWorkspaceOfAesGcmSivEncrypt()                                                /**< Deactivateable: 'Crypto_30_Hwa_AesGcmSivEncrypt.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_HasClearWorkspaceBuffersOfGeneral()                                           (TRUE != FALSE)
#define Crypto_30_Hwa_HasCmacAesGenerate()                                                          (TRUE != FALSE)
#define Crypto_30_Hwa_HasWorkspaceOfCmacAesGenerate()                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasCmacAesVerify()                                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasWorkspaceOfCmacAesVerify()                                                 (TRUE != FALSE)
#define Crypto_30_Hwa_HasDevErrorDetectOfGeneral()                                                  (TRUE != FALSE)
#define Crypto_30_Hwa_HasDriverObjectOfKeyDerive()                                                    /**< Deactivateable: 'Crypto_30_Hwa_DriverObjectOfKeyDerive' Reason: 'Reference is not configured!' */
#define Crypto_30_Hwa_HasDriverObjectState()                                                        (TRUE != FALSE)
#define Crypto_30_Hwa_HasEcP256Generate()                                                             /**< Deactivateable: 'Crypto_30_Hwa_EcP256Generate' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_Hwa_HasWorkspaceOfEcP256Generate()                                                  /**< Deactivateable: 'Crypto_30_Hwa_EcP256Generate.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_HasEcP256Verify()                                                               /**< Deactivateable: 'Crypto_30_Hwa_EcP256Verify' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_Hwa_HasWorkspaceOfEcP256Verify()                                                    /**< Deactivateable: 'Crypto_30_Hwa_EcP256Verify.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_HasEd25519Generate()                                                          (TRUE != FALSE)
#define Crypto_30_Hwa_HasWorkspaceOfEd25519Generate()                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasEd25519Verify()                                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasWorkspaceOfEd25519Verify()                                                 (TRUE != FALSE)
#define Crypto_30_Hwa_HasExpectedCompatibilityVersion()                                               /**< Deactivateable: 'Crypto_30_Hwa_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_Hwa_HasFamilyToHashMapping()                                                      (TRUE != FALSE)
#define Crypto_30_Hwa_HasFinalMagicNumber()                                                           /**< Deactivateable: 'Crypto_30_Hwa_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_Hwa_HasGeneratorCompatibilityVersion()                                              /**< Deactivateable: 'Crypto_30_Hwa_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_Hwa_HasInitDataHashCode()                                                           /**< Deactivateable: 'Crypto_30_Hwa_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_Hwa_HasKeyMap()                                                                   (TRUE != FALSE)
#define Crypto_30_Hwa_HasAggregatedCryptoKeyIdOfKeyMap()                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasKeyIdOfKeyMap()                                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasLock()                                                                     (TRUE != FALSE)
#define Crypto_30_Hwa_HasMaxInputLengthOfKeyDerive()                                                  /**< Deactivateable: 'Crypto_30_Hwa_MaxInputLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_HasMaxOutputKeyLengthOfKeyDerive()                                              /**< Deactivateable: 'Crypto_30_Hwa_MaxOutputKeyLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_HasNonPreemptiveChunkSizeOfGeneral()                                          (TRUE != FALSE)
#define Crypto_30_Hwa_HasObjectInfo()                                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesDecryptIdxOfObjectInfo()                                                (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesDecryptUsedOfObjectInfo()                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesEncryptIdxOfObjectInfo()                                                (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesEncryptUsedOfObjectInfo()                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesGcmDecryptIdxOfObjectInfo()                                             (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesGcmDecryptUsedOfObjectInfo()                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesGcmEncryptIdxOfObjectInfo()                                             (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesGcmEncryptUsedOfObjectInfo()                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesGcmSivDecryptIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.AesGcmSivDecryptIdx' Reason: 'the optional indirection is deactivated because AesGcmSivDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_HasAesGcmSivDecryptUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.AesGcmSivDecryptUsed' Reason: 'the optional indirection is deactivated because AesGcmSivDecryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_HasAesGcmSivEncryptIdxOfObjectInfo()                                            /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.AesGcmSivEncryptIdx' Reason: 'the optional indirection is deactivated because AesGcmSivEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_HasAesGcmSivEncryptUsedOfObjectInfo()                                           /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.AesGcmSivEncryptUsed' Reason: 'the optional indirection is deactivated because AesGcmSivEncryptUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_HasCmacAesGenerateIdxOfObjectInfo()                                           (TRUE != FALSE)
#define Crypto_30_Hwa_HasCmacAesGenerateUsedOfObjectInfo()                                          (TRUE != FALSE)
#define Crypto_30_Hwa_HasCmacAesVerifyIdxOfObjectInfo()                                             (TRUE != FALSE)
#define Crypto_30_Hwa_HasCmacAesVerifyUsedOfObjectInfo()                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasEcP256GenerateIdxOfObjectInfo()                                              /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.EcP256GenerateIdx' Reason: 'the optional indirection is deactivated because EcP256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_HasEcP256GenerateUsedOfObjectInfo()                                             /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.EcP256GenerateUsed' Reason: 'the optional indirection is deactivated because EcP256GenerateUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_HasEcP256VerifyIdxOfObjectInfo()                                                /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.EcP256VerifyIdx' Reason: 'the optional indirection is deactivated because EcP256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_HasEcP256VerifyUsedOfObjectInfo()                                               /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.EcP256VerifyUsed' Reason: 'the optional indirection is deactivated because EcP256VerifyUsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_HasEd25519GenerateIdxOfObjectInfo()                                           (TRUE != FALSE)
#define Crypto_30_Hwa_HasEd25519GenerateUsedOfObjectInfo()                                          (TRUE != FALSE)
#define Crypto_30_Hwa_HasEd25519VerifyIdxOfObjectInfo()                                             (TRUE != FALSE)
#define Crypto_30_Hwa_HasEd25519VerifyUsedOfObjectInfo()                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasMaskedBitsOfObjectInfo()                                                   (TRUE != FALSE)
#define Crypto_30_Hwa_HasSHA256IdxOfObjectInfo()                                                      /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.SHA256Idx' Reason: 'the optional indirection is deactivated because SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_HasSHA256UsedOfObjectInfo()                                                     /**< Deactivateable: 'Crypto_30_Hwa_ObjectInfo.SHA256Used' Reason: 'the optional indirection is deactivated because SHA256UsedOfObjectInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Crypto_30_Hwa_HasTrngIdxOfObjectInfo()                                                      (TRUE != FALSE)
#define Crypto_30_Hwa_HasTrngUsedOfObjectInfo()                                                     (TRUE != FALSE)
#define Crypto_30_Hwa_HasQueue()                                                                      /**< Deactivateable: 'Crypto_30_Hwa_Queue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_HasSHA256()                                                                     /**< Deactivateable: 'Crypto_30_Hwa_SHA256' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Crypto_30_Hwa_HasWorkspaceOfSHA256()                                                          /**< Deactivateable: 'Crypto_30_Hwa_SHA256.Workspace' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_HasSizeOfAesDecrypt()                                                         (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfAesEncrypt()                                                         (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfAesGcmDecrypt()                                                      (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfAesGcmEncrypt()                                                      (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfCmacAesGenerate()                                                    (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfCmacAesVerify()                                                      (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfDriverObjectState()                                                  (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfEd25519Generate()                                                    (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfEd25519Verify()                                                      (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfFamilyToHashMapping()                                                (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfIterationCounterOfKeyDerive()                                          /**< Deactivateable: 'Crypto_30_Hwa_SizeOfIterationCounterOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_HasSizeOfKeyMap()                                                             (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfLock()                                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfObjectInfo()                                                         (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfTargetKeyLengthOfKeyDerive()                                           /**< Deactivateable: 'Crypto_30_Hwa_SizeOfTargetKeyLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_HasSizeOfTrng()                                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasTrng()                                                                     (TRUE != FALSE)
#define Crypto_30_Hwa_HasWorkspaceOfTrng()                                                          (TRUE != FALSE)
#define Crypto_30_Hwa_HasTrngPrefetchCapacityOfGeneral()                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasTrngPrefetchWithInterruptOfGeneral()                                       (TRUE != FALSE)
#define Crypto_30_Hwa_HasUnionWS_vHsm_Hwa()                                                         (TRUE != FALSE)
#define Crypto_30_Hwa_HasUnionWS_vHsm_Hwa_HighPrio()                                                (TRUE != FALSE)
#define Crypto_30_Hwa_HasPCConfig()                                                                 (TRUE != FALSE)
#define Crypto_30_Hwa_HasAddZeroOctetOfKeyDeriveOfPCConfig()                                          /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.AddZeroOctetOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_HasAesDecryptOfPCConfig()                                                     (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesEncryptOfPCConfig()                                                     (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesGcmDecryptOfPCConfig()                                                  (TRUE != FALSE)
#define Crypto_30_Hwa_HasAesGcmEncryptOfPCConfig()                                                  (TRUE != FALSE)
#define Crypto_30_Hwa_HasClearWorkspaceBuffersOfGeneralOfPCConfig()                                 (TRUE != FALSE)
#define Crypto_30_Hwa_HasCmacAesGenerateOfPCConfig()                                                (TRUE != FALSE)
#define Crypto_30_Hwa_HasCmacAesVerifyOfPCConfig()                                                  (TRUE != FALSE)
#define Crypto_30_Hwa_HasDevErrorDetectOfGeneralOfPCConfig()                                        (TRUE != FALSE)
#define Crypto_30_Hwa_HasDriverObjectOfKeyDeriveOfPCConfig()                                          /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.DriverObjectOfKeyDerive' Reason: 'Reference is not configured!' */
#define Crypto_30_Hwa_HasDriverObjectStateOfPCConfig()                                              (TRUE != FALSE)
#define Crypto_30_Hwa_HasEd25519GenerateOfPCConfig()                                                (TRUE != FALSE)
#define Crypto_30_Hwa_HasEd25519VerifyOfPCConfig()                                                  (TRUE != FALSE)
#define Crypto_30_Hwa_HasExpectedCompatibilityVersionOfPCConfig()                                     /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_Hwa_HasFamilyToHashMappingOfPCConfig()                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasFinalMagicNumberOfPCConfig()                                                 /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_Hwa_HasGeneratorCompatibilityVersionOfPCConfig()                                    /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_Hwa_HasInitDataHashCodeOfPCConfig()                                                 /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_Hwa_HasKeyMapOfPCConfig()                                                         (TRUE != FALSE)
#define Crypto_30_Hwa_HasLockOfPCConfig()                                                           (TRUE != FALSE)
#define Crypto_30_Hwa_HasMaxInputLengthOfKeyDeriveOfPCConfig()                                        /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.MaxInputLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_HasMaxOutputKeyLengthOfKeyDeriveOfPCConfig()                                    /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.MaxOutputKeyLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_HasNonPreemptiveChunkSizeOfGeneralOfPCConfig()                                (TRUE != FALSE)
#define Crypto_30_Hwa_HasObjectInfoOfPCConfig()                                                     (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfAesDecryptOfPCConfig()                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfAesEncryptOfPCConfig()                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfAesGcmDecryptOfPCConfig()                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfAesGcmEncryptOfPCConfig()                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfCmacAesGenerateOfPCConfig()                                          (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfCmacAesVerifyOfPCConfig()                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfDriverObjectStateOfPCConfig()                                        (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfEd25519GenerateOfPCConfig()                                          (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfEd25519VerifyOfPCConfig()                                            (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfFamilyToHashMappingOfPCConfig()                                      (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfIterationCounterOfKeyDeriveOfPCConfig()                                /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.SizeOfIterationCounterOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_HasSizeOfKeyMapOfPCConfig()                                                   (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfLockOfPCConfig()                                                     (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfObjectInfoOfPCConfig()                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasSizeOfTargetKeyLengthOfKeyDeriveOfPCConfig()                                 /**< Deactivateable: 'Crypto_30_Hwa_PCConfig.SizeOfTargetKeyLengthOfKeyDerive' Reason: 'Parameter is not configured!' */
#define Crypto_30_Hwa_HasSizeOfTrngOfPCConfig()                                                     (TRUE != FALSE)
#define Crypto_30_Hwa_HasTrngOfPCConfig()                                                           (TRUE != FALSE)
#define Crypto_30_Hwa_HasTrngPrefetchCapacityOfGeneralOfPCConfig()                                  (TRUE != FALSE)
#define Crypto_30_Hwa_HasTrngPrefetchWithInterruptOfGeneralOfPCConfig()                             (TRUE != FALSE)
#define Crypto_30_Hwa_HasUnionWS_vHsm_HwaOfPCConfig()                                               (TRUE != FALSE)
#define Crypto_30_Hwa_HasUnionWS_vHsm_Hwa_HighPrioOfPCConfig()                                      (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCIncrementDataMacros  Crypto_30_Hwa Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_Hwa_IncDriverObjectState(Index)                                                   Crypto_30_Hwa_GetDriverObjectState(Index)++
#define Crypto_30_Hwa_IncLock(Index)                                                                Crypto_30_Hwa_GetLock(Index)++
#define Crypto_30_Hwa_IncQueue(Index)                                                                 /**< Deactivateable: 'Crypto_30_Hwa_Queue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_IncUnionWS_vHsm_Hwa()                                                         Crypto_30_Hwa_GetUnionWS_vHsm_Hwa()++
#define Crypto_30_Hwa_IncUnionWS_vHsm_Hwa_HighPrio()                                                Crypto_30_Hwa_GetUnionWS_vHsm_Hwa_HighPrio()++
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCDecrementDataMacros  Crypto_30_Hwa Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_Hwa_DecDriverObjectState(Index)                                                   Crypto_30_Hwa_GetDriverObjectState(Index)--
#define Crypto_30_Hwa_DecLock(Index)                                                                Crypto_30_Hwa_GetLock(Index)--
#define Crypto_30_Hwa_DecQueue(Index)                                                                 /**< Deactivateable: 'Crypto_30_Hwa_Queue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_DecUnionWS_vHsm_Hwa()                                                         Crypto_30_Hwa_GetUnionWS_vHsm_Hwa()--
#define Crypto_30_Hwa_DecUnionWS_vHsm_Hwa_HighPrio()                                                Crypto_30_Hwa_GetUnionWS_vHsm_Hwa_HighPrio()--
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCAddDataMacros  Crypto_30_Hwa Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_Hwa_AddDriverObjectState(Index, Value)                                            Crypto_30_Hwa_SetDriverObjectState(Index, (Crypto_30_Hwa_GetDriverObjectState(Index) + Value))
#define Crypto_30_Hwa_AddLock(Index, Value)                                                         Crypto_30_Hwa_SetLock(Index, (Crypto_30_Hwa_GetLock(Index) + Value))
#define Crypto_30_Hwa_AddQueue(Index, Value)                                                          /**< Deactivateable: 'Crypto_30_Hwa_Queue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_AddUnionWS_vHsm_Hwa(Value)                                                    Crypto_30_Hwa_SetUnionWS_vHsm_Hwa((Crypto_30_Hwa_GetUnionWS_vHsm_Hwa() + Value))
#define Crypto_30_Hwa_AddUnionWS_vHsm_Hwa_HighPrio(Value)                                           Crypto_30_Hwa_SetUnionWS_vHsm_Hwa_HighPrio((Crypto_30_Hwa_GetUnionWS_vHsm_Hwa_HighPrio() + Value))
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCSubstractDataMacros  Crypto_30_Hwa Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_Hwa_SubDriverObjectState(Index, Value)                                            Crypto_30_Hwa_SetDriverObjectState(Index, (Crypto_30_Hwa_GetDriverObjectState(Index) - Value))
#define Crypto_30_Hwa_SubLock(Index, Value)                                                         Crypto_30_Hwa_SetLock(Index, (Crypto_30_Hwa_GetLock(Index) - Value))
#define Crypto_30_Hwa_SubQueue(Index, Value)                                                          /**< Deactivateable: 'Crypto_30_Hwa_Queue' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Crypto_30_Hwa_SubUnionWS_vHsm_Hwa(Value)                                                    Crypto_30_Hwa_SetUnionWS_vHsm_Hwa((Crypto_30_Hwa_GetUnionWS_vHsm_Hwa() - Value))
#define Crypto_30_Hwa_SubUnionWS_vHsm_Hwa_HighPrio(Value)                                           Crypto_30_Hwa_SetUnionWS_vHsm_Hwa_HighPrio((Crypto_30_Hwa_GetUnionWS_vHsm_Hwa_HighPrio() - Value))
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
  \defgroup  Crypto_30_HwaPBGetRootDataMacros  Crypto_30_Hwa Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Crypto_30_Hwa_GetLTConfigIdxOfPBConfig()                                                      /**< Deactivateable: 'Crypto_30_Hwa_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_Hwa_GetPCConfigIdxOfPBConfig()                                                      /**< Deactivateable: 'Crypto_30_Hwa_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPBHasMacros  Crypto_30_Hwa Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Crypto_30_Hwa_HasPBConfig()                                                                   /**< Deactivateable: 'Crypto_30_Hwa_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_Hwa_HasLTConfigIdxOfPBConfig()                                                      /**< Deactivateable: 'Crypto_30_Hwa_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_Hwa_HasPCConfigIdxOfPBConfig()                                                      /**< Deactivateable: 'Crypto_30_Hwa_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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
#define Crypto_30_Hwa_FreeLock(lockIdx) Crypto_30_Hwa_SetLock((lockIdx), 0xFFFFFFFFUL)
#define Crypto_30_Hwa_IsLockFree(lockIdx) (Crypto_30_Hwa_GetLock((lockIdx))) == 0xFFFFFFFFUL
#define Crypto_30_Hwa_IsLockOccupiedByJob(lockIdx, jobId) (Crypto_30_Hwa_GetLock((lockIdx))) == (jobId)
/* PRQA L:LOCKMACROS_3453 */


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef union
{ /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_Hwa_WorkSpaceCMACAES CmacAesGenerate;
  Crypto_30_Hwa_WorkSpaceCMACAES CmacAesVerify;
} Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio_Type;

typedef union
{ /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_Hwa_WorkSpaceAES AesEncrypt;
  Crypto_30_Hwa_WorkSpaceAES AesDecrypt;
  Crypto_30_Hwa_WorkSpaceGCM AesGcmEncrypt;
  Crypto_30_Hwa_WorkSpaceGCM AesGcmDecrypt;
  Crypto_30_Hwa_WorkSpaceCMACAES CmacAesGenerate;
  Crypto_30_Hwa_WorkSpaceCMACAES CmacAesVerify;
  Crypto_30_Hwa_WorkSpaceTRNG Trng;
  Crypto_30_Hwa_WorkSpaceSignature Ed25519Generate;
  Crypto_30_Hwa_WorkSpaceSignature Ed25519Verify;
} Crypto_30_Hwa_UnionWS_vHsm_Hwa_Type;

typedef P2VAR(Crypto_30_Hwa_WorkSpaceCMACAES, CRYPTO_30_HWA_CONST, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_WorkSpaceCMACAES_PtrType;
typedef P2VAR(Crypto_30_Hwa_WorkSpaceAES, CRYPTO_30_HWA_CONST, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_WorkSpaceAES_PtrType;
typedef P2VAR(Crypto_30_Hwa_WorkSpaceGCM, CRYPTO_30_HWA_CONST, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_WorkSpaceGCM_PtrType;
typedef P2VAR(Crypto_30_Hwa_WorkSpaceTRNG, CRYPTO_30_HWA_CONST, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_WorkSpaceTRNG_PtrType;
typedef P2VAR(Crypto_30_Hwa_WorkSpaceSignature, CRYPTO_30_HWA_CONST, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_WorkSpaceSignature_PtrType;
typedef Crypto_JobType* Crypto_30_Hwa_QueueElementType;


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_HwaPCIterableTypes  Crypto_30_Hwa Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Crypto_30_Hwa_AesDecrypt */
typedef uint8_least Crypto_30_Hwa_AesDecryptIterType;

/**   \brief  type used to iterate Crypto_30_Hwa_AesEncrypt */
typedef uint8_least Crypto_30_Hwa_AesEncryptIterType;

/**   \brief  type used to iterate Crypto_30_Hwa_AesGcmDecrypt */
typedef uint8_least Crypto_30_Hwa_AesGcmDecryptIterType;

/**   \brief  type used to iterate Crypto_30_Hwa_AesGcmEncrypt */
typedef uint8_least Crypto_30_Hwa_AesGcmEncryptIterType;

/**   \brief  type used to iterate Crypto_30_Hwa_CmacAesGenerate */
typedef uint8_least Crypto_30_Hwa_CmacAesGenerateIterType;

/**   \brief  type used to iterate Crypto_30_Hwa_CmacAesVerify */
typedef uint8_least Crypto_30_Hwa_CmacAesVerifyIterType;

/**   \brief  type used to iterate Crypto_30_Hwa_Ed25519Generate */
typedef uint8_least Crypto_30_Hwa_Ed25519GenerateIterType;

/**   \brief  type used to iterate Crypto_30_Hwa_Ed25519Verify */
typedef uint8_least Crypto_30_Hwa_Ed25519VerifyIterType;

/**   \brief  type used to iterate Crypto_30_Hwa_FamilyToHashMapping */
typedef uint8_least Crypto_30_Hwa_FamilyToHashMappingIterType;

/**   \brief  type used to iterate Crypto_30_Hwa_KeyMap */
typedef uint8_least Crypto_30_Hwa_KeyMapIterType;

/**   \brief  type used to iterate Crypto_30_Hwa_ObjectInfo */
typedef uint8_least Crypto_30_Hwa_ObjectInfoIterType;

/**   \brief  type used to iterate Crypto_30_Hwa_Trng */
typedef uint8_least Crypto_30_Hwa_TrngIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCIterableTypesWithSizeRelations  Crypto_30_Hwa Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Crypto_30_Hwa_DriverObjectState */
typedef Crypto_30_Hwa_ObjectInfoIterType Crypto_30_Hwa_DriverObjectStateIterType;

/**   \brief  type used to iterate Crypto_30_Hwa_Lock */
typedef Crypto_30_Hwa_ObjectInfoIterType Crypto_30_Hwa_LockIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCValueTypes  Crypto_30_Hwa Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Crypto_30_Hwa_ClearWorkspaceBuffersOfGeneral */
typedef boolean Crypto_30_Hwa_ClearWorkspaceBuffersOfGeneralType;

/**   \brief  value based type definition for Crypto_30_Hwa_DevErrorDetectOfGeneral */
typedef boolean Crypto_30_Hwa_DevErrorDetectOfGeneralType;

/**   \brief  value based type definition for Crypto_30_Hwa_DriverObjectState */
typedef uint8 Crypto_30_Hwa_DriverObjectStateType;

/**   \brief  value based type definition for Crypto_30_Hwa_FamilyToHashMapping */
typedef uint8 Crypto_30_Hwa_FamilyToHashMappingType;

/**   \brief  value based type definition for Crypto_30_Hwa_AggregatedCryptoKeyIdOfKeyMap */
typedef uint32 Crypto_30_Hwa_AggregatedCryptoKeyIdOfKeyMapType;

/**   \brief  value based type definition for Crypto_30_Hwa_KeyIdOfKeyMap */
typedef uint16 Crypto_30_Hwa_KeyIdOfKeyMapType;

/**   \brief  value based type definition for Crypto_30_Hwa_Lock */
typedef uint32 Crypto_30_Hwa_LockType;

/**   \brief  value based type definition for Crypto_30_Hwa_NonPreemptiveChunkSizeOfGeneral */
typedef uint16 Crypto_30_Hwa_NonPreemptiveChunkSizeOfGeneralType;

/**   \brief  value based type definition for Crypto_30_Hwa_AesDecryptIdxOfObjectInfo */
typedef uint8 Crypto_30_Hwa_AesDecryptIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_AesDecryptUsedOfObjectInfo */
typedef boolean Crypto_30_Hwa_AesDecryptUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_AesEncryptIdxOfObjectInfo */
typedef uint8 Crypto_30_Hwa_AesEncryptIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_AesEncryptUsedOfObjectInfo */
typedef boolean Crypto_30_Hwa_AesEncryptUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_AesGcmDecryptIdxOfObjectInfo */
typedef uint8 Crypto_30_Hwa_AesGcmDecryptIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_AesGcmDecryptUsedOfObjectInfo */
typedef boolean Crypto_30_Hwa_AesGcmDecryptUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_AesGcmEncryptIdxOfObjectInfo */
typedef uint8 Crypto_30_Hwa_AesGcmEncryptIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_AesGcmEncryptUsedOfObjectInfo */
typedef boolean Crypto_30_Hwa_AesGcmEncryptUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_CmacAesGenerateIdxOfObjectInfo */
typedef uint8 Crypto_30_Hwa_CmacAesGenerateIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_CmacAesGenerateUsedOfObjectInfo */
typedef boolean Crypto_30_Hwa_CmacAesGenerateUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_CmacAesVerifyIdxOfObjectInfo */
typedef uint8 Crypto_30_Hwa_CmacAesVerifyIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_CmacAesVerifyUsedOfObjectInfo */
typedef boolean Crypto_30_Hwa_CmacAesVerifyUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_Ed25519GenerateIdxOfObjectInfo */
typedef uint8 Crypto_30_Hwa_Ed25519GenerateIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_Ed25519GenerateUsedOfObjectInfo */
typedef boolean Crypto_30_Hwa_Ed25519GenerateUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_Ed25519VerifyIdxOfObjectInfo */
typedef uint8 Crypto_30_Hwa_Ed25519VerifyIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_Ed25519VerifyUsedOfObjectInfo */
typedef boolean Crypto_30_Hwa_Ed25519VerifyUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_MaskedBitsOfObjectInfo */
typedef uint16 Crypto_30_Hwa_MaskedBitsOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_TrngIdxOfObjectInfo */
typedef uint8 Crypto_30_Hwa_TrngIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_TrngUsedOfObjectInfo */
typedef boolean Crypto_30_Hwa_TrngUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfAesDecrypt */
typedef uint8 Crypto_30_Hwa_SizeOfAesDecryptType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfAesEncrypt */
typedef uint8 Crypto_30_Hwa_SizeOfAesEncryptType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfAesGcmDecrypt */
typedef uint8 Crypto_30_Hwa_SizeOfAesGcmDecryptType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfAesGcmEncrypt */
typedef uint8 Crypto_30_Hwa_SizeOfAesGcmEncryptType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfCmacAesGenerate */
typedef uint8 Crypto_30_Hwa_SizeOfCmacAesGenerateType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfCmacAesVerify */
typedef uint8 Crypto_30_Hwa_SizeOfCmacAesVerifyType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfDriverObjectState */
typedef uint8 Crypto_30_Hwa_SizeOfDriverObjectStateType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfEd25519Generate */
typedef uint8 Crypto_30_Hwa_SizeOfEd25519GenerateType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfEd25519Verify */
typedef uint8 Crypto_30_Hwa_SizeOfEd25519VerifyType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfFamilyToHashMapping */
typedef uint8 Crypto_30_Hwa_SizeOfFamilyToHashMappingType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfKeyMap */
typedef uint8 Crypto_30_Hwa_SizeOfKeyMapType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfLock */
typedef uint8 Crypto_30_Hwa_SizeOfLockType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfObjectInfo */
typedef uint8 Crypto_30_Hwa_SizeOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_Hwa_SizeOfTrng */
typedef uint8 Crypto_30_Hwa_SizeOfTrngType;

/**   \brief  value based type definition for Crypto_30_Hwa_TrngPrefetchCapacityOfGeneral */
typedef uint8 Crypto_30_Hwa_TrngPrefetchCapacityOfGeneralType;

/**   \brief  value based type definition for Crypto_30_Hwa_TrngPrefetchWithInterruptOfGeneral */
typedef boolean Crypto_30_Hwa_TrngPrefetchWithInterruptOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_HwaPCStructTypes  Crypto_30_Hwa Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Crypto_30_Hwa_AesDecrypt */
typedef struct sCrypto_30_Hwa_AesDecryptType
{
  Crypto_30_Hwa_WorkSpaceAES_PtrType WorkspaceOfAesDecrypt;
} Crypto_30_Hwa_AesDecryptType;

/**   \brief  type used in Crypto_30_Hwa_AesEncrypt */
typedef struct sCrypto_30_Hwa_AesEncryptType
{
  Crypto_30_Hwa_WorkSpaceAES_PtrType WorkspaceOfAesEncrypt;
} Crypto_30_Hwa_AesEncryptType;

/**   \brief  type used in Crypto_30_Hwa_AesGcmDecrypt */
typedef struct sCrypto_30_Hwa_AesGcmDecryptType
{
  Crypto_30_Hwa_WorkSpaceGCM_PtrType WorkspaceOfAesGcmDecrypt;
} Crypto_30_Hwa_AesGcmDecryptType;

/**   \brief  type used in Crypto_30_Hwa_AesGcmEncrypt */
typedef struct sCrypto_30_Hwa_AesGcmEncryptType
{
  Crypto_30_Hwa_WorkSpaceGCM_PtrType WorkspaceOfAesGcmEncrypt;
} Crypto_30_Hwa_AesGcmEncryptType;

/**   \brief  type used in Crypto_30_Hwa_CmacAesGenerate */
typedef struct sCrypto_30_Hwa_CmacAesGenerateType
{
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType WorkspaceOfCmacAesGenerate;
} Crypto_30_Hwa_CmacAesGenerateType;

/**   \brief  type used in Crypto_30_Hwa_CmacAesVerify */
typedef struct sCrypto_30_Hwa_CmacAesVerifyType
{
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType WorkspaceOfCmacAesVerify;
} Crypto_30_Hwa_CmacAesVerifyType;

/**   \brief  type used in Crypto_30_Hwa_Ed25519Generate */
typedef struct sCrypto_30_Hwa_Ed25519GenerateType
{
  Crypto_30_Hwa_WorkSpaceSignature_PtrType WorkspaceOfEd25519Generate;
} Crypto_30_Hwa_Ed25519GenerateType;

/**   \brief  type used in Crypto_30_Hwa_Ed25519Verify */
typedef struct sCrypto_30_Hwa_Ed25519VerifyType
{
  Crypto_30_Hwa_WorkSpaceSignature_PtrType WorkspaceOfEd25519Verify;
} Crypto_30_Hwa_Ed25519VerifyType;

/**   \brief  type used in Crypto_30_Hwa_KeyMap */
typedef struct sCrypto_30_Hwa_KeyMapType
{
  Crypto_30_Hwa_AggregatedCryptoKeyIdOfKeyMapType AggregatedCryptoKeyIdOfKeyMap;
  Crypto_30_Hwa_KeyIdOfKeyMapType KeyIdOfKeyMap;
} Crypto_30_Hwa_KeyMapType;

/**   \brief  type used in Crypto_30_Hwa_ObjectInfo */
typedef struct sCrypto_30_Hwa_ObjectInfoType
{
  Crypto_30_Hwa_MaskedBitsOfObjectInfoType MaskedBitsOfObjectInfo;  /**< contains bitcoded the boolean data of Crypto_30_Hwa_AesDecryptUsedOfObjectInfo, Crypto_30_Hwa_AesEncryptUsedOfObjectInfo, Crypto_30_Hwa_AesGcmDecryptUsedOfObjectInfo, Crypto_30_Hwa_AesGcmEncryptUsedOfObjectInfo, Crypto_30_Hwa_CmacAesGenerateUsedOfObjectInfo, Crypto_30_Hwa_CmacAesVerifyUsedOfObjectInfo, Crypto_30_Hwa_Ed25519GenerateUsedOfObjectInfo, Crypto_30_Hwa_Ed25519VerifyUsedOfObjectInfo, Crypto_30_Hwa_TrngUsedOfObjectInfo */
  Crypto_30_Hwa_AesDecryptIdxOfObjectInfoType AesDecryptIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_Hwa_AesDecrypt */
  Crypto_30_Hwa_AesEncryptIdxOfObjectInfoType AesEncryptIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_Hwa_AesEncrypt */
  Crypto_30_Hwa_AesGcmDecryptIdxOfObjectInfoType AesGcmDecryptIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_Hwa_AesGcmDecrypt */
  Crypto_30_Hwa_AesGcmEncryptIdxOfObjectInfoType AesGcmEncryptIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_Hwa_AesGcmEncrypt */
  Crypto_30_Hwa_CmacAesGenerateIdxOfObjectInfoType CmacAesGenerateIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_Hwa_CmacAesGenerate */
  Crypto_30_Hwa_CmacAesVerifyIdxOfObjectInfoType CmacAesVerifyIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_Hwa_CmacAesVerify */
  Crypto_30_Hwa_Ed25519GenerateIdxOfObjectInfoType Ed25519GenerateIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_Hwa_Ed25519Generate */
  Crypto_30_Hwa_Ed25519VerifyIdxOfObjectInfoType Ed25519VerifyIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_Hwa_Ed25519Verify */
  Crypto_30_Hwa_TrngIdxOfObjectInfoType TrngIdxOfObjectInfo;  /**< the index of the 0:1 relation pointing to Crypto_30_Hwa_Trng */
} Crypto_30_Hwa_ObjectInfoType;

/**   \brief  type used in Crypto_30_Hwa_Trng */
typedef struct sCrypto_30_Hwa_TrngType
{
  Crypto_30_Hwa_WorkSpaceTRNG_PtrType WorkspaceOfTrng;
} Crypto_30_Hwa_TrngType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCSymbolicStructTypes  Crypto_30_Hwa Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Crypto_30_Hwa_DriverObjectState */
typedef struct Crypto_30_Hwa_DriverObjectStateStructSTag
{
  Crypto_30_Hwa_DriverObjectStateType vHsm_Hwa_HighPrio;
  Crypto_30_Hwa_DriverObjectStateType vHsm_Hwa;
} Crypto_30_Hwa_DriverObjectStateStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_Hwa_Lock */
typedef struct Crypto_30_Hwa_LockStructSTag
{
  Crypto_30_Hwa_LockType vHsm_Hwa_HighPrio;
  Crypto_30_Hwa_LockType vHsm_Hwa;
} Crypto_30_Hwa_LockStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCUnionIndexAndSymbolTypes  Crypto_30_Hwa Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Crypto_30_Hwa_DriverObjectState in an index and symbol based style. */
typedef union Crypto_30_Hwa_DriverObjectStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_Hwa_DriverObjectStateType raw[2];
  Crypto_30_Hwa_DriverObjectStateStructSType str;
} Crypto_30_Hwa_DriverObjectStateUType;

/**   \brief  type to access Crypto_30_Hwa_Lock in an index and symbol based style. */
typedef union Crypto_30_Hwa_LockUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_Hwa_LockType raw[2];
  Crypto_30_Hwa_LockStructSType str;
} Crypto_30_Hwa_LockUType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCRootPointerTypes  Crypto_30_Hwa Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Crypto_30_Hwa_AesDecrypt */
typedef P2CONST(Crypto_30_Hwa_AesDecryptType, TYPEDEF, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_AesDecryptPtrType;

/**   \brief  type used to point to Crypto_30_Hwa_AesEncrypt */
typedef P2CONST(Crypto_30_Hwa_AesEncryptType, TYPEDEF, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_AesEncryptPtrType;

/**   \brief  type used to point to Crypto_30_Hwa_AesGcmDecrypt */
typedef P2CONST(Crypto_30_Hwa_AesGcmDecryptType, TYPEDEF, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_AesGcmDecryptPtrType;

/**   \brief  type used to point to Crypto_30_Hwa_AesGcmEncrypt */
typedef P2CONST(Crypto_30_Hwa_AesGcmEncryptType, TYPEDEF, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_AesGcmEncryptPtrType;

/**   \brief  type used to point to Crypto_30_Hwa_CmacAesGenerate */
typedef P2CONST(Crypto_30_Hwa_CmacAesGenerateType, TYPEDEF, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_CmacAesGeneratePtrType;

/**   \brief  type used to point to Crypto_30_Hwa_CmacAesVerify */
typedef P2CONST(Crypto_30_Hwa_CmacAesVerifyType, TYPEDEF, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_CmacAesVerifyPtrType;

/**   \brief  type used to point to Crypto_30_Hwa_DriverObjectState */
typedef P2VAR(Crypto_30_Hwa_DriverObjectStateType, TYPEDEF, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_DriverObjectStatePtrType;

/**   \brief  type used to point to Crypto_30_Hwa_Ed25519Generate */
typedef P2CONST(Crypto_30_Hwa_Ed25519GenerateType, TYPEDEF, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_Ed25519GeneratePtrType;

/**   \brief  type used to point to Crypto_30_Hwa_Ed25519Verify */
typedef P2CONST(Crypto_30_Hwa_Ed25519VerifyType, TYPEDEF, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_Ed25519VerifyPtrType;

/**   \brief  type used to point to Crypto_30_Hwa_FamilyToHashMapping */
typedef P2CONST(Crypto_30_Hwa_FamilyToHashMappingType, TYPEDEF, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_FamilyToHashMappingPtrType;

/**   \brief  type used to point to Crypto_30_Hwa_KeyMap */
typedef P2CONST(Crypto_30_Hwa_KeyMapType, TYPEDEF, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_KeyMapPtrType;

/**   \brief  type used to point to Crypto_30_Hwa_Lock */
typedef P2VAR(Crypto_30_Hwa_LockType, TYPEDEF, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_LockPtrType;

/**   \brief  type used to point to Crypto_30_Hwa_ObjectInfo */
typedef P2CONST(Crypto_30_Hwa_ObjectInfoType, TYPEDEF, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_ObjectInfoPtrType;

/**   \brief  type used to point to Crypto_30_Hwa_Trng */
typedef P2CONST(Crypto_30_Hwa_TrngType, TYPEDEF, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_TrngPtrType;

/**   \brief  type used to point to Crypto_30_Hwa_UnionWS_vHsm_Hwa */
typedef P2VAR(Crypto_30_Hwa_UnionWS_vHsm_Hwa_Type, TYPEDEF, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_UnionWS_vHsm_HwaPtrType;

/**   \brief  type used to point to Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio */
typedef P2VAR(Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio_Type, TYPEDEF, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrioPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_HwaPCRootValueTypes  Crypto_30_Hwa Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Crypto_30_Hwa_PCConfig */
typedef struct sCrypto_30_Hwa_PCConfigType
{
  uint8 Crypto_30_Hwa_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Crypto_30_Hwa_PCConfigType;

typedef Crypto_30_Hwa_PCConfigType Crypto_30_Hwa_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_HwaPBValueTypes  Crypto_30_Hwa Value Types (POST_BUILD)
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
  \defgroup  Crypto_30_HwaPBRootValueTypes  Crypto_30_Hwa Root Value Types (POST_BUILD)
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
  Crypto_30_Hwa_AesDecrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_AesDecrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_Hwa_AesDecryptType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_AesDecrypt[1];
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_AesEncrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_AesEncrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_Hwa_AesEncryptType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_AesEncrypt[1];
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_AesGcmDecrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_AesGcmDecrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_Hwa_AesGcmDecryptType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_AesGcmDecrypt[1];
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_AesGcmEncrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_AesGcmEncrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_Hwa_AesGcmEncryptType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_AesGcmEncrypt[1];
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_CmacAesGenerate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_CmacAesGenerate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_Hwa_CmacAesGenerateType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_CmacAesGenerate[2];
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_CmacAesVerify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_CmacAesVerify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_Hwa_CmacAesVerifyType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_CmacAesVerify[2];
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_Ed25519Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_Ed25519Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_Hwa_Ed25519GenerateType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_Ed25519Generate[1];
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_Ed25519Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_Ed25519Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_Hwa_Ed25519VerifyType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_Ed25519Verify[1];
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_FamilyToHashMapping
**********************************************************************************************************************/
#define CRYPTO_30_HWA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_Hwa_FamilyToHashMappingType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_FamilyToHashMapping[8];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_HWA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_KeyMap
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_KeyMap
  \brief  Contains keys of Crypto_30_Hwa, accessible by external KeyId reduced by offset of 30000.
  \details
  Element                  Description
  AggregatedCryptoKeyId
  KeyId                
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_Hwa_KeyMapType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_KeyMap[4];
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_ObjectInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_ObjectInfo
  \details
  Element               Description
  MaskedBits            contains bitcoded the boolean data of Crypto_30_Hwa_AesDecryptUsedOfObjectInfo, Crypto_30_Hwa_AesEncryptUsedOfObjectInfo, Crypto_30_Hwa_AesGcmDecryptUsedOfObjectInfo, Crypto_30_Hwa_AesGcmEncryptUsedOfObjectInfo, Crypto_30_Hwa_CmacAesGenerateUsedOfObjectInfo, Crypto_30_Hwa_CmacAesVerifyUsedOfObjectInfo, Crypto_30_Hwa_Ed25519GenerateUsedOfObjectInfo, Crypto_30_Hwa_Ed25519VerifyUsedOfObjectInfo, Crypto_30_Hwa_TrngUsedOfObjectInfo
  AesDecryptIdx         the index of the 0:1 relation pointing to Crypto_30_Hwa_AesDecrypt
  AesEncryptIdx         the index of the 0:1 relation pointing to Crypto_30_Hwa_AesEncrypt
  AesGcmDecryptIdx      the index of the 0:1 relation pointing to Crypto_30_Hwa_AesGcmDecrypt
  AesGcmEncryptIdx      the index of the 0:1 relation pointing to Crypto_30_Hwa_AesGcmEncrypt
  CmacAesGenerateIdx    the index of the 0:1 relation pointing to Crypto_30_Hwa_CmacAesGenerate
  CmacAesVerifyIdx      the index of the 0:1 relation pointing to Crypto_30_Hwa_CmacAesVerify
  Ed25519GenerateIdx    the index of the 0:1 relation pointing to Crypto_30_Hwa_Ed25519Generate
  Ed25519VerifyIdx      the index of the 0:1 relation pointing to Crypto_30_Hwa_Ed25519Verify
  TrngIdx               the index of the 0:1 relation pointing to Crypto_30_Hwa_Trng
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_Hwa_ObjectInfoType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_ObjectInfo[2];
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_Trng
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_Trng
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_Hwa_TrngType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_Trng[1];
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_DriverObjectState
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_DriverObjectState
  \brief  State of the current workspace usage.
*/ 
#define CRYPTO_30_HWA_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_Hwa_DriverObjectStateUType, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_DriverObjectState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_Lock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_Lock
  \brief  Id of job that currently occupies the workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_Hwa_LockUType, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_Lock;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_UnionWS_vHsm_Hwa
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_UnionWS_vHsm_Hwa
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa.
*/ 
#define CRYPTO_30_HWA_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_Hwa_UnionWS_vHsm_Hwa_Type, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_UnionWS_vHsm_Hwa;
#define CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa_HighPrio.
*/ 
#define CRYPTO_30_HWA_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio_Type, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
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
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/








#endif /* CRYPTO_30_HWA_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Cfg.h
 *********************************************************************************************************************/


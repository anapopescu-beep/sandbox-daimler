/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*      \file  Crypto_30_vHsm_Custom.h
 *      \brief  MICROSAR Crypto Driver (Crypto)
 *
 *      \details  Internal header file for custom algorithms
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef CRYPTO_30_VHSM_CUSTOM_H
# define CRYPTO_30_VHSM_CUSTOM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Crypto_30_vHsm_Custom_Generated.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Additional Key Element defines ---------------------------------------------- */

/* AES MAC */
# ifndef CRYPTO_KE_CUSTOM_MAC_AES_ROUNDKEY /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_MAC_AES_ROUNDKEY                           (129u)
# endif

/* Key Derive */
# ifndef CRYPTO_KE_CUSTOM_KEYDERIVATION_LABEL /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_KEYDERIVATION_LABEL                        (130u)
# endif

# ifndef CRYPTO_KE_CUSTOM_KEYDERIVATION_ADDITIONAL_INFO /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_KEYDERIVATION_ADDITIONAL_INFO              (131u)
# endif

# ifndef CRYPTO_KE_CUSTOM_ADDITIONAL_INFO /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_ADDITIONAL_INFO                            (131u)
# endif

/* RSA */
# ifndef CRYPTO_KE_CUSTOM_RSA_MODULUS /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RSA_MODULUS                                (160u)
# endif

# ifndef CRYPTO_KE_CUSTOM_RSA_PUBLIC_EXPONENT /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RSA_PUBLIC_EXPONENT                        (161u)
# endif

# ifndef CRYPTO_KE_CUSTOM_RSA_PRIVATE_EXPONENT /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RSA_PRIVATE_EXPONENT                       (162u)
# endif

# ifndef CRYPTO_KE_CUSTOM_RSA_SALT /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RSA_SALT                                   (163u)
# endif

# ifndef CRYPTO_KE_CUSTOM_RSA_SALT_LENGTH /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RSA_SALT_LENGTH                            (164u)
# endif

/* TLS */
# ifndef CRYPTO_KE_CUSTOM_TLS_CLIENT_HELLO_RANDOM /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_TLS_CLIENT_HELLO_RANDOM                    (3000u)
# endif

# ifndef CRYPTO_KE_CUSTOM_TLS_SERVER_HELLO_RANDOM /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_TLS_SERVER_HELLO_RANDOM                    (3001u)
# endif

# ifndef CRYPTO_KE_CUSTOM_TLS_HMAC_KEY_SIZE /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_TLS_HMAC_KEY_SIZE                          (3002u)
# endif

/* Key Exchange */
# ifndef CRYPTO_KE_CUSTOM_KEYEXCHANGE_PARTNER_PUB_KEY /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_KEYEXCHANGE_PARTNER_PUB_KEY                (3003u)
# endif

/* Smart Charge Communication */
# ifndef CRYPTO_KE_CUSTOM_SCC_CONTRACT_PUBLIC_KEY /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_SCC_CONTRACT_PUBLIC_KEY                    (3013u)
# endif

# ifndef CRYPTO_KE_CUSTOM_SCC_IV_AND_ENCRYPTED_PRIVATE_KEY /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_SCC_IV_AND_ENCRYPTED_PRIVATE_KEY           (3014u)
# endif

/* Random Number Generation */
# ifndef CRYPTO_KE_CUSTOM_RANDOM_PERSONALIZATION_STRING /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RANDOM_PERSONALIZATION_STRING              (3015u)
# endif

# ifndef CRYPTO_KE_CUSTOM_RANDOM_ADDITIONAL_INPUT /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RANDOM_ADDITIONAL_INPUT                    (3016u)
# endif

# ifndef CRYPTO_KE_CUSTOM_RANDOM_NONCE /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RANDOM_NONCE                               (3017u)
# endif

# ifndef CRYPTO_KE_CUSTOM_RANDOM_RESEED_COUNTER /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RANDOM_RESEED_COUNTER                      (3018u)
# endif

/* SHE Key Update */
# ifndef CRYPTO_KE_CUSTOM_SHE_COUNTER /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_SHE_COUNTER                                (3019u)
# endif

# ifndef CRYPTO_KE_CUSTOM_SHE_UID /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_SHE_UID                                    (3021u)
# endif

# ifndef CRYPTO_KE_CUSTOM_SHE_BOOT_PROTECTION /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_SHE_BOOT_PROTECTION                        (3056u)
# endif

# ifndef CRYPTO_KE_CUSTOM_SHE_DEBUGGER_PROTECTION /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_SHE_DEBUGGER_PROTECTION                    (3057u)
# endif

# ifndef CRYPTO_KE_CUSTOM_SHE_DEBUG_CMD /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_SHE_DEBUG_CMD                              (3059u)
# endif

/* RSA CRT */
# ifndef CRYPTO_KE_CUSTOM_RSA_PRIME_P /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RSA_PRIME_P                                (3051u)
# endif

# ifndef CRYPTO_KE_CUSTOM_RSA_PRIME_Q /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RSA_PRIME_Q                                (3052u)
# endif

# ifndef CRYPTO_KE_CUSTOM_RSA_EXPONENT_DP /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RSA_EXPONENT_DP                            (3053u)
# endif

# ifndef CRYPTO_KE_CUSTOM_RSA_EXPONENT_DQ /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RSA_EXPONENT_DQ                            (3054u)
# endif

# ifndef CRYPTO_KE_CUSTOM_RSA_INVERSE_QI /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_RSA_INVERSE_QI                             (3055u)
# endif

# ifndef CRYPTO_KE_CUSTOM_LABEL /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_LABEL                                      (3058u)
# endif

/* Spake2+ */
# ifndef CRYPTO_KE_CUSTOM_W0 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_W0                                         (3084u)
# endif

# ifndef CRYPTO_KE_CUSTOM_W1 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_W1                                         (3085u)
# endif

# ifndef CRYPTO_KE_CUSTOM_L /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_L                                          (3086u)
# endif

# ifndef CRYPTO_KE_CUSTOM_VERIFICATION /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VERIFICATION                               (3087u)
# endif

# ifndef CRYPTO_KE_CUSTOM_VERIFICATION_RESULT /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VERIFICATION_RESULT                        (3088u)
# endif

/* ----- Custom Algorithm Mode Defines ---------------------------------------------- */
/* ECC curve p256r1 */
# ifndef CRYPTO_ALGOMODE_CUSTOM_P256R1  /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOMODE_CUSTOM_P256R1                               (128u)
# endif

/* RSA CRT */
# ifndef CRYPTO_ALGOMODE_CUSTOM_RSASSA_PKCS1_v1_5_CRT /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOMODE_CUSTOM_RSASSA_PKCS1_v1_5_CRT                (129u)
# endif

# ifndef CRYPTO_ALGOMODE_CUSTOM_RSAES_OAEP_CRT /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOMODE_CUSTOM_RSAES_OAEP_CRT                       (132u)
# endif

/* Use Derivation function e.g. for NIST DRBG AES128 */
# ifndef CRYPTO_ALGOMODE_CUSTOM_USE_DF /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOMODE_CUSTOM_USE_DF                               (130u)
# endif

/* ECC curve p384r1 */
# ifndef CRYPTO_ALGOMODE_CUSTOM_P384R1  /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOMODE_CUSTOM_P384R1                               (131u)
# endif

/* ----- Custom Algorithm Family Defines ---------------------------------------------- */
/* Ecc-ANSI conform */
# ifndef CRYPTO_ALGOFAM_CUSTOM_ECCANSI /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_ECCANSI                               (129u)
# endif
/* Ecc-SEC conform */
# ifndef CRYPTO_ALGOFAM_CUSTOM_ECCSEC  /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_ECCSEC                                (130u)
# endif
/* NIST 800-90A DRBG conform */
# ifndef CRYPTO_ALGOFAM_CUSTOM_DRBG /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_DRBG                                  (131u)
# endif
/* FIPS 186.2 conform */
# ifndef CRYPTO_ALGOFAM_CUSTOM_FIPS186  /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_FIPS186                               (132u)
# endif
/* Padding PKCS7 */
# ifndef CRYPTO_ALGOFAM_CUSTOM_PADDING_PKCS7 /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_PADDING_PKCS7                         (133u)
# endif

/* ----- Custom Key Exchange Algorithm Defines ---------------------------------------------- */
/* Exchange algorithm x25519 */
# ifndef CRYPTO_30_LIBCV_KEY_EXCHANGE_X25519 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_KEY_EXCHANGE_X25519                         (0u)
# endif
/* Exchange algorithm ANSI p256r1 */
# ifndef CRYPTO_30_LIBCV_KEY_EXCHANGE_ANSIP256R1 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_KEY_EXCHANGE_ANSIP256R1                     (1u)
# endif

/* Exchange algorithm SEC p256r1 */
# ifndef CRYPTO_30_LIBCV_KEY_EXCHANGE_SECP256R1 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_KEY_EXCHANGE_SECP256R1                      (2u)
# endif
/* Exchange algorithm SEC p384r1 */
# ifndef CRYPTO_30_LIBCV_KEY_EXCHANGE_SECP384R1 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_KEY_EXCHANGE_SECP384R1                      (4u)
# endif

/* ----- Custom Key Derivation Algorithm Defines ---------------------------------------------- */
/* KDF_NIST_800-108 'KDF in Counter Mode' with SHA-256 as PRF */
# ifndef CRYPTO_30_LIBCV_KDF_ALGO_KDF_SYM_NIST_800_108_CNT_MODE_SHA256 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_KDF_ALGO_KDF_SYM_NIST_800_108_CNT_MODE_SHA256 (1u)
# endif

/* NIST.FIPS.186-4 'Key Pair Generation Using Extra Random Bits' with 'KDF in Counter Mode' as RBG */
# ifndef CRYPTO_30_LIBCV_KDF_ALGO_KDF_ASYM_NIST_FIPS_186_4_ERB /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_KDF_ALGO_KDF_ASYM_NIST_FIPS_186_4_ERB       (2u)
# endif

/* NIST.SP.800-56A Single-Step KDF with Option 1: H(x) = hash(x) */
# ifndef CRYPTO_30_LIBCV_KDF_ALGO_KDF_NIST_800_56_A_ONE_PASS_C1E1S_SINGLE_STEP_KDF_SHA256 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_KDF_ALGO_KDF_NIST_800_56_A_ONE_PASS_C1E1S_SINGLE_STEP_KDF_SHA256 (3u)
# endif

/* ISO 15118 install and update certificate. */
# ifndef CRYPTO_30_LIBCV_KDF_ALGO_KDF_ISO_15118_CERTIFICATE_HANDLING /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_KDF_ALGO_KDF_ISO_15118_CERTIFICATE_HANDLING (4u)
# endif

/* KDF X9.63 SHA 1 */
# ifndef CRYPTO_30_LIBCV_KDF_ALGO_KDF_X963_SHA1 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_KDF_ALGO_KDF_X963_SHA1                      (5u)
# endif

/* KDF X9.63 SHA 256 */
# ifndef CRYPTO_30_LIBCV_KDF_ALGO_KDF_X963_SHA256 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_KDF_ALGO_KDF_X963_SHA256                    (6u)
# endif

/* KDF X9.63 SHA 512 */
# ifndef CRYPTO_30_LIBCV_KDF_ALGO_KDF_X963_SHA512 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_KDF_ALGO_KDF_X963_SHA512                    (7u)
# endif

/* ----- Custom Random Seed Algorithm Defines ---------------------------------------------- */
/* Random Seed according to FIPS 186-2 SHA1 */
# ifndef CRYPTO_30_LIBCV_RNG_FIPS_186_2_SHA1 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_RNG_FIPS_186_2_SHA1                         (0u)
# endif
/* Random Seed according to NIST 800-90A CTR_DRBG with AES-128 */
# ifndef CRYPTO_30_LIBCV_RNG_NIST_800_90A_CTR_DRBG_AES128 /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ALGORITHM */
#  define CRYPTO_30_LIBCV_RNG_NIST_800_90A_CTR_DRBG_AES128            (1u)
# endif

# ifndef CRYPTO_ALGOFAM_CUSTOM_SECURE_BOOT /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_SECURE_BOOT                           (160u) /* This define is deprecated */
# endif
# ifndef CRYPTO_ALGOFAM_CUSTOM_VHSM_SECURE_BOOT /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_VHSM_SECURE_BOOT                      (160u)
# endif
# ifndef CRYPTO_ALGOFAM_CUSTOM_SOFTWARE_DOWNLOAD /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_SOFTWARE_DOWNLOAD                     (161u) /* This define is deprecated */
# endif
# ifndef CRYPTO_ALGOFAM_CUSTOM_VHSM_SOFTWARE_DOWNLOAD /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_VHSM_SOFTWARE_DOWNLOAD                (161u)
# endif
# ifndef CRYPTO_ALGOFAM_CUSTOM_VHSM_FIRMWARE_UPDATE /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_VHSM_FIRMWARE_UPDATE                  (163u)
# endif
# ifndef CRYPTO_ALGOFAM_CUSTOM_VHSM_BOOT_UPDATE /* COV_CRYPTO_30_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_VHSM_BOOT_UPDATE                      (164u)
# endif

/* vHsm Core */
# ifndef CRYPTO_KE_CUSTOM_VHSM_VERSION /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_VERSION                               (3020u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_UID /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_UID                                   (3021u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_PERFORM_PERSISTING /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_PERFORM_PERSISTING                    (3022u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_ERRORLOG /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_ERRORLOG                              (3023u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS              (3024u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE                 (3025u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC                 (3026u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SANCTION /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SANCTION             (3027u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_END /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_END                       (3028u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_RESULT /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_RESULT                    (3037u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_FIRMWARE_UPDATE_START_UPDATER /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_FIRMWARE_UPDATE_START_UPDATER         (3038u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_PERFORM_REPERSISTING /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_PERFORM_REPERSISTING                  (3036u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_KEY /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_KEY                  (1u)
# endif

/* vHsm Custom */
# ifndef CRYPTO_KE_CUSTOM_VHSM_BUNDLING_REQ /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_BUNDLING_REQ                          (3029u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_BUNDLING_RESP /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_BUNDLING_RESP                         (3030u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_BUNDLING_COUNTER /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_BUNDLING_COUNTER                      (3031u)
# endif

/* vHsm Hal */
# ifndef CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION                       (3032u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_RESET_VECTORS /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_RESET_VECTORS                         (3033u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_OPTION_BYTES /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_OPTION_BYTES                          (3034u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_UPGP /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_UPGP                                  (3035u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_STATUS_HSM2HOST /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_STATUS_HSM2HOST                       (3090u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_STATUS_HOST2HSM /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_STATUS_HOST2HSM                       (3091u)
# endif

# ifndef CRYPTO_30_VHSM_DATAFLASH_START /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_DATAFLASH_START                              (0u)
# endif
# ifndef CRYPTO_30_VHSM_DATAFLASH_STOP /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_DATAFLASH_STOP                               (1u)
# endif
# ifndef CRYPTO_30_VHSM_CODEFLASH_START /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_CODEFLASH_START                              (2u)
# endif
# ifndef CRYPTO_30_VHSM_CODEFLASH_STOP /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_CODEFLASH_STOP                               (3u)
# endif

# ifndef CRYPTO_30_VHSM_SANCTION_NONE /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_SANCTION_NONE                                (0u)
# endif
# ifndef CRYPTO_30_VHSM_SANCTION_RESET /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_SANCTION_RESET                               (1u)
# endif
# ifndef CRYPTO_30_VHSM_SANCTION_CUSTOM /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_SANCTION_CUSTOM                              (2u)
# endif
# ifndef CRYPTO_30_VHSM_SANCTION_HALT /* COV_CRYPTO_30_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_SANCTION_HALT                                (3u)
# endif

#endif /* CRYPTO_30_VHSM_CUSTOM_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Custom.h
 *********************************************************************************************************************/

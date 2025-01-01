/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*         \file  Crypto_30_Hwa_Custom.h
 *        \brief  vHsm custom extensions
 *
 *      \details  This file defines custom extensions for Autosar parameter
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_HWA_CUSTOM_H)
# define CRYPTO_30_HWA_CUSTOM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Custom Algorithm Family Defines ---------------------------------------------- */
# ifndef CRYPTO_ALGOFAM_CUSTOM_PADDING_PKCS7 /* COV_CRYPTO_30_HWA_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_PADDING_PKCS7                           (133u)
# endif
# ifndef CRYPTO_ALGOFAM_CUSTOM_PADDING_NONE /* COV_CRYPTO_30_HWA_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_PADDING_NONE                            (CRYPTO_ALGOFAM_NOT_SET)
# endif

/* ----- Custom Algorithm Mode Defines ---------------------------------------------- */
# ifndef CRYPTO_ALGOMODE_CUSTOM_AES_GSM_SIV /* COV_CRYPTO_30_HWA_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOMODE_CUSTOM_AES_GSM_SIV                            (173u)
# endif

/* ----- Custom Algorithm Mode Defines ---------------------------------------------- */
# ifndef CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PURE /* COV_CRYPTO_30_HWA_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PURE                     (174u)
# endif

/* ----- Custom Algorithm Mode Defines ---------------------------------------------- */
# ifndef CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_CTX /* COV_CRYPTO_30_HWA_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_CTX                      (175u)
# endif

/* ----- Custom Algorithm Mode Defines ---------------------------------------------- */
# ifndef CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PH /* COV_CRYPTO_30_HWA_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PH                       (176u)
# endif

/* ----- Custom key derivation key element ------------------------------------------- */
# ifndef CRYPTO_KE_CUSTOM_VHSM_KEYDERIVATION_ALGORITHM /* COV_CRYPTO_30_HWA_CUSTOM_ALGORITHM */
#  define CRYPTO_KE_CUSTOM_VHSM_KEYDERIVATION_ALGORITHM                  (CryptoConf_CryptoKeyElement_vHsm_KeyDerivation_Algorithm_NIST800108_CMAC)
# endif

/* Crypto Hwa key derivation key element value */
# ifndef CRYPTO_30_VHSM_ALGO_KDF_NIST_800_108_CMAC /* COV_CRYPTO_30_HWA_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_30_VHSM_ALGO_KDF_NIST_800_108_CMAC                      (8u)
# endif

/* Crypto Hwa key derivation target key element */
# ifndef CRYPTO_30_HWA_KEYDERIVATION_TARGET_ELEMENT /* COV_CRYPTO_30_HWA_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_KEYDERIVATION_TARGET_KEY                             (1u)
# endif

/* Crypto Hwa key derivation context key element */
# ifndef CRYPTO_KE_KEYDERIVATION_CONTEXT /* COV_CRYPTO_30_HWA_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_KEYDERIVATION_CONTEXT                                (CryptoConf_CryptoKeyElement_vHsm_KeyDerivation_Context)
# endif

/* Crypto Hwa key derivation key label element */
# ifndef CRYPTO_KE_KEYDERIVATION_LABEL /* COV_CRYPTO_30_HWA_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_KEYDERIVATION_LABEL                                  (CryptoConf_CryptoKeyElement_vHsm_KeyDerivation_Label)
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# endif /* CRYPTO_30_HWA_CUSTOM_H */
/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Custom.h
 *********************************************************************************************************************/

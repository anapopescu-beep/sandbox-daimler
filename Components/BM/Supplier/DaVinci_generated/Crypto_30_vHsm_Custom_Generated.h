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
 *              File: Crypto_30_vHsm_Custom_Generated.h
 *   Generation Time: 2023-07-17 14:11:53
 *           Project: CBD2000614_Bm - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (CRYPTO_30_VHSM_CUSTOM_GENERATED_H)
#define CRYPTO_30_VHSM_CUSTOM_GENERATED_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ----- Symbolic Name Define Block ---------------------------------------------- */
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_LibCv_P256r1                   128u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_vHsm_Core_ForceSequential      133u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_vHsm_Core_PersistDeferred      152u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_vHsm_Core_Repersist            153u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_Hwa_Ed25519Pure                174u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_Hwa_Ed25519Ctx                 175u
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_Hwa_Ed25519Ph                  176u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_LibCv_PaddingPKCS7           133u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_LibCv_DRBG                   131u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SecureBoot         160u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_FirmwareUpdate     163u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SecureBootUpdate   164u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SoftwareDownload   161u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_Hwa_PaddingPKCS7             133u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SecureBootConfirmation 165u
#define CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_Persistency        192u

/* ----- Custom Algorithm Mode Defines ---------------------------------------------- */
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_LIBCV_P256R1                                          CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_LibCv_P256r1
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_FORCESEQUENTIAL                             CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_vHsm_Core_ForceSequential
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_PERSISTDEFERRED                             CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_vHsm_Core_PersistDeferred
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_REPERSIST                                   CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_vHsm_Core_Repersist
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_HWA_ED25519PURE                                       CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_Hwa_Ed25519Pure
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_HWA_ED25519CTX                                        CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_Hwa_Ed25519Ctx
#define CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_HWA_ED25519PH                                         CryptoConf_CryptoPrimitiveAlgorithmModeCustom_Crypto_30_vHsm_Hwa_Ed25519Ph

/* ----- Custom Algorithm Family Defines ---------------------------------------------- */
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_LIBCV_PADDINGPKCS7                                     CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_LibCv_PaddingPKCS7
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_LIBCV_DRBG                                             CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_LibCv_DRBG
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_SECUREBOOT                                   CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SecureBoot
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_FIRMWAREUPDATE                               CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_FirmwareUpdate
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_SECUREBOOTUPDATE                             CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SecureBootUpdate
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_SOFTWAREDOWNLOAD                             CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SoftwareDownload
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_HWA_PADDINGPKCS7                                       CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_Hwa_PaddingPKCS7
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_SECUREBOOTCONFIRMATION                       CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_SecureBootConfirmation
#define CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_VHSM_CORE_PERSISTENCY                                  CryptoConf_CryptoPrimitiveAlgorithmFamilyCustom_Crypto_30_vHsm_vHsm_Core_Persistency

#endif /* CRYPTO_30_VHSM_CUSTOM_GENERATED_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Custom_Generated.h
 *********************************************************************************************************************/


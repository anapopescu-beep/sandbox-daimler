/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*      \file  vHsm_Core_Custom.h
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

#ifndef VHSM_CORE_CUSTOM_H
# define VHSM_CORE_CUSTOM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vHsm_Core_Custom_Generated.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Additional Key Element defines ---------------------------------------------- */

/* vHsm */
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_KEY /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_KEY                  (1u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_VERSION /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_VERSION                               (3020u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_UID /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_UID                                   (3021u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_PERFORM_PERSISTING /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_PERFORM_PERSISTING                    (3022u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_ERRORLOG /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_ERRORLOG                              (3023u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS              (3024u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE                 (3025u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC                 (3026u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_TAG /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_TAG                  (3026u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SANCTION /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SANCTION             (3027u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_PERFORM_REPERSISTING /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_PERFORM_REPERSISTING                  (3036u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_END /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_END                       (3028u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_RESULT /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_RESULT                    (3037u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_FIRMWARE_UPDATE_START_UPDATER /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_FIRMWARE_UPDATE_START_UPDATER         (3038u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_MODE /* COV_VHSM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_MODE                 (3039u)
# endif

/* ----- Custom Algorithm Family Defines ---------------------------------------------- */

/* vHsm Secure Boot */
# ifndef CRYPTO_ALGOFAM_CUSTOM_VHSM_SECURE_BOOT /* COV_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_VHSM_SECURE_BOOT                      CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_CORE_SECUREBOOT
# endif

/* vHsm Secure Software Download */
# ifndef CRYPTO_ALGOFAM_CUSTOM_VHSM_SOFTWARE_DOWNLOAD /* COV_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_VHSM_SOFTWARE_DOWNLOAD                CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_CORE_SOFTWAREDOWNLOAD
# endif

/* vHsm Firmware update */
# ifndef CRYPTO_ALGOFAM_CUSTOM_VHSM_FIRMWARE_UPDATE /* COV_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_VHSM_FIRMWARE_UPDATE                  CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_CORE_FIRMWAREUPDATE
# endif

/* vHsm Secure Boot Update */
# ifndef CRYPTO_ALGOFAM_CUSTOM_VHSM_SECURE_BOOT_UPDATE /* COV_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_VHSM_SECURE_BOOT_UPDATE               CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_CORE_SECUREBOOTUPDATE
# endif

/* vHsm Secure Boot Confirmation */
# ifndef CRYPTO_ALGOFAM_CUSTOM_VHSM_SECURE_BOOT_CONFIRMATION /* COV_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_VHSM_SECURE_BOOT_CONFIRMATION         CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_CORE_SECUREBOOTCONFIRMATION
# endif

/* vHsm Persisting */
# ifndef CRYPTO_ALGOFAM_CUSTOM_VHSM_PERSISTENCY /* COV_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOFAM_CUSTOM_VHSM_PERSISTENCY                      CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_CORE_PERSISTENCY
# endif
/* ----- Custom Algorithm Mode Defines ---------------------------------------------- */

/* vHsm Secure Boot */
# ifndef CRYPTO_ALGOMODE_CUSTOM_SECURE_BOOT_FORCE_SEQUENTIAL /* COV_VHSM_CUSTOM_ALGORITHM */
#  define CRYPTO_ALGOMODE_CUSTOM_SECURE_BOOT_FORCE_SEQUENTIAL         CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_CORE_FORCESEQUENTIAL
# endif

/* ----- Custom Secure Boot Sanction Defines ---------------------------------------------- */
# ifndef CRYPTO_30_VHSM_SANCTION_NONE /* COV_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_SANCTION_NONE                                (0u)
# endif
# ifndef CRYPTO_30_VHSM_SANCTION_RESET /* COV_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_SANCTION_RESET                               (1u)
# endif
# ifndef CRYPTO_30_VHSM_SANCTION_CUSTOM /* COV_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_SANCTION_CUSTOM                              (2u)
# endif
# ifndef CRYPTO_30_VHSM_SANCTION_HALT /* COV_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_SANCTION_HALT                                (3u)
# endif

/* ----- Custom Secure Boot Mode Defines ---------------------------------------------- */
# ifndef CRYPTO_30_VHSM_MODE_NONE /* COV_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_MODE_NONE                                    (0u)
# endif
# ifndef CRYPTO_30_VHSM_MODE_PARALLEL /* COV_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_MODE_PARALLEL                                (1u)
# endif
# ifndef CRYPTO_30_VHSM_MODE_SEQUENTIAL /* COV_VHSM_CUSTOM_KEY_ELEMENT_VALUE */
#  define CRYPTO_30_VHSM_MODE_SEQUENTIAL                              (2u)
# endif

/* ----- Custom Error Log Defines ---------------------------------------------- */
# define VHSM_LOG_ID_RSTVECT_CHANGE_FAILED                            (0u)
# define VHSM_LOG_ID_WATCHDOG_OCCURED                                 (1u) /* Only for compatibility reasons */
# define VHSM_LOG_ID_WATCHDOG_OCCURRED                                (1u)
# define VHSM_LOG_ID_ECC                                              (2u)
# define VHSM_LOG_ID_RSTVECT_INCONSISTENT                             (3u)
# define VHSM_LOG_ID_DET                                              (4u)
# define VHSM_LOG_ID_STACKPROTECTION                                  (5u)
# define VHSM_LOG_ID_SOFTWARE_RESET_LIMIT_REACHED                     (6u)
# define VHSM_LOG_ID_JOBPROCESSING_ERROR                              (7u)
# define VHSM_LOG_ID_SECURE_BOOT_FAILED                               (8u)

# define VHSM_LOG_DATA_NO_ERROR_DATA                                  (0u)

#endif /* VHSM_CORE_CUSTOM_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Core_Custom.h
 *********************************************************************************************************************/

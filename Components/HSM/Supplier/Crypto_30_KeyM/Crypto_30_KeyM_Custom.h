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
/*      \file  Crypto_30_KeyM_Custom.h
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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#ifndef CRYPTO_30_KEYM_CUSTOM_CUSTOM_H_
# define CRYPTO_30_KEYM_CUSTOM_CUSTOM_H_

/* ----- Additional Key Element defines ---------------------------------------------- */
# define CRYPTO_KE_CUSTOM_VHSM_KEYM_CERTIFICATE                       (3080u)  /* This define is deprecated */
# define CRYPTO_KE_CUSTOM_VHSM_KEYM_CERT_GETSTATUS                    (3081u)  /* This define is deprecated */
# define CRYPTO_KE_CUSTOM_VHSM_KEYM_VERIFY_CERT                       (3082u)  /* This define is deprecated */
# define CRYPTO_KE_CUSTOM_VHSM_KEYM_VERIFY_CERTS                      (3083u)  /* This define is deprecated */

 /* ----- Additional Algorithm families and modes defines ---------------------------------------------- */
# define CRYPTO_ALGOFAM_CUSTOM_VHSM_KEYM                              (170u)   /* This define is deprecated */
# define CRYPTO_ALGOMODE_CUSTOM_INIT_CSR                              (139u)   /* This define is deprecated */
# define CRYPTO_ALGOMODE_CUSTOM_SERVICECERTIFICATE                    (140u)   /* This define is deprecated */
# define CRYPTO_ALGOMODE_CUSTOM_CERTELEMENT_GET                       (141u)   /* This define is deprecated */
# define CRYPTO_ALGOMODE_CUSTOM_CERTELEMENT_GETFIRST                  (142u)   /* This define is deprecated */
# define CRYPTO_ALGOMODE_CUSTOM_CERTELEMENT_GETNEXT                   (143u)   /* This define is deprecated */

#endif /* CRYPTO_30_KEYM_CUSTOM_CUSTOM_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_KeyM_Custom.h
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*      \file  vHsm_Custom_Custom.h
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

#ifndef VHSM_CUSTOM_CUSTOM_H_
# define VHSM_CUSTOM_CUSTOM_H_

/* ----- Additional Key Element defines ---------------------------------------------- */

/* vHsm Bundling Protocol */
# ifndef CRYPTO_KE_CUSTOM_VHSM_BUNDLING_REQ /* COV_VHSM_CUSTOM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_BUNDLING_REQ                        (3029u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_BUNDLING_RESP /* COV_VHSM_CUSTOM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_BUNDLING_RESP                       (3030u)
# endif
# ifndef CRYPTO_KE_CUSTOM_VHSM_BUNDLING_COUNTER /* COV_VHSM_CUSTOM_CUSTOM_KEY_ELEMENTS */
#  define CRYPTO_KE_CUSTOM_VHSM_BUNDLING_COUNTER                    (3031u)
# endif

#endif /* VHSM_CUSTOM_CUSTOM_H_ */
/**********************************************************************************************************************
 *  END OF FILE: vHsm_Custom_Custom.h
 *********************************************************************************************************************/

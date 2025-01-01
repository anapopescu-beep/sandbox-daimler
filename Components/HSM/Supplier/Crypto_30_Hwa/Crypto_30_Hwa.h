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
/*!        \file  Crypto_30_Hwa.h
 *        \brief  vHsm platform hardware abstraction library
 *
 *      \details  The hardware abstraction library for the vHsm.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vHsm_Platform_TC3XX: Information about the platform component which consist of the following files:
 *  - Crypto_30_Hwa_Hw.c
 *  - Crypto_30_Hwa_Hw.h
 *  - Crypto_30_Hwa_Hw_Cfg.h
 *  - Crypto_30_Hwa_Hw_Types.h
 */
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author         Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.01.00   2020-12-11  vismhh         HSM-1287      Add ECC-Signature Verification for Curve Nist-P256R1
    1.03.00   2021-04-23  vismhh         HSM-1289      Add ECC-Signature Generation for Curve NIST-P256R1
 *                        vismhh         HSM-1291      Add EDDSA Signature Verification for Curve ED25519
 *                        vismhh         HSM-1293      Add EDDSA Signature Generation for Curve ED25519
 *                        vismhh         ESCAN00109195 Corrected handling of ECDSA input when length is smaller than 32 bytes
 *                        visdil         ESCAN00109412 Low entropy random number of TRNG is not ignored if interrupt is used
 *                        visfpt         ESCAN00109107 Corrected handling of missing exclusive area 4
 *  1.04.00   2021-07-22  vismhh         HSM-1814      Implement AES-128-GCM with input data not multiple of blocksize
 *                                       ESCAN00109841 Corrected setting of initialization vector for CMAC
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DrvCrypto_Hwa__base: Information about the base component which consist of the following files:
 *  - Crypto_30_Hwa.h
 *  - Crypto_30_Hwa.c
 *  - Crypto_30_Hwa_Aead.c
 *  - Crypto_30_Hwa_Cipher.c
 *  - Crypto_30_Hwa_Crypto.c
 *  - Crypto_30_Hwa_Mac.c
 *  - Crypto_30_Hwa_Custom.h
 *  - Crypto_30_Hwa_Hash.c
 *  - Crypto_30_Hwa_Random.c
 *  - Crypto_30_Hwa_Hw.h
 *  - Crypto_30_Hwa_Public.h
 *  - Crypto_30_Hwa_Private.h
 *  - Crypto_30_Hwa_Types.h
 */
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author         Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.00.00   2020-10-15  visfpt,visdil  HSM-1080      Initial creation. Moved core hardware callouts (from platform base) to another component
 *  1.01.00   2021-03-02  vismhh         HSM-0004      Support signature generation for curve ECC-Nist P256P1
 *                                       HSM-0010      Support signature verification for curve ECC-Nist P256P1
 *                                       HSM-1505      Support algorithm AES GCM SIV
 *  1.01.01   2021-03-26  vismhh         ESCAN00108895 Corrected clearing workspace buffers for AES GCM SIV
 *  1.02.00   2021-04-23  vismhh         ESCAN00109139 Corrected handling of ECDSA input when length is smaller than 32 bytes
 *  1.03.00   2021-05-21  vismhh         HSM-1569      Support signature generation and verification with scheme ED25519
 *  1.04.00   2021-07-22  vismhh         ESCAN00109811 Corrected writing output buffer for AES GCM
 *********************************************************************************************************************/

/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#if !defined (CRYPTO_30_HWA_H)
# define CRYPTO_30_HWA_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Crypto_30_Hwa_Public.h"
# include "SchM_Crypto_30_Hwa.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define CRYPTO_30_HWA_VERSION                                             (0x0104u)
# define CRYPTO_30_HWA_RELEASE_VERSION                                     (0x00u)

/* Component Version Information */
/* No u suffix is used for shift operator because some compilers may have problems */
# define CRYPTO_30_HWA_SW_MAJOR_VERSION                                    (CRYPTO_30_HWA_VERSION >> 8)
# define CRYPTO_30_HWA_SW_MINOR_VERSION                                    (CRYPTO_30_HWA_VERSION & 0x00FFu)
# define CRYPTO_30_HWA_SW_PATCH_VERSION                                    (CRYPTO_30_HWA_RELEASE_VERSION)

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

#endif /* CRYPTO_30_HWA_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa.h
 *********************************************************************************************************************/

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
/*!        \file  vHsm_Hal.h
 *        \brief  The hardware abstraction library for vHsm callouts.
 *
 *      \details  -
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vHsm_Platform_TC3xx: Information about the platform component which consist of the following files:
 *  - vHsm_Hal.c
 *  - vHsm_Hal_Irq.c
 *  - vHsm_Hal.h
 *  - vHsm_Hal_HwCfg.h
 */
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2018-09-21  visjhi  STORYC-5535   Initial cration of vHSM TC3x HAL
 *  02.00.00  2018-10-12  visjhi  ESCAN00100299 vHsm may hang on SHA256 processing
 *                                ESCAN00100200 AES decode error/wrong length using streaming mode
 *  02.00.01  2018-10-16  visjhi                Enable TRNG workaround because LibCv/ESLib relies on it
 *  02.00.02  2018-10-26  visjhi  STORYC-5536   Implement TRNG acceleration
 *  02.01.00  2019-02-12  visjhi  STORYC-7051   Basic TC2xx support without flash
 *                                STORYC-5534   Implement pipelining for AES and AES CMAC
 *  02.01.01  2019-02-28  visjhi  STORYC-7052   Add flash support for TC2xx (Fee and Fls)
 *                                STORYC-7768   Implement RAM loop support
 *  02.02.00  2019-03-21  visjhi  ESCAN00102036 Fix: AES output length too big
 *                                STORYC-7985   Release of component
 *  03.00.00  2019-10-31  vismhh  HSM-510       Enable usage of hardware keys
 *                                HSM-244       Support AES GCM
                                  ESCAN00106182 Fix: endless loop in hash
 *  03.01.00  2020-03-26  visdil  HSM-500       Support AES-CTR
 *                                HSM-37        Support multiple contexts
 *                                HSM-574       Implement prefetching of random numbers
 *                                HSM-675       Provide ISR functions
 *  03.03.00  2020-08-19  visdil  HSM-1143      Update to base 3.3.0
 *  05.00.00  2021-03-09  visebj  HSM-1509      Initial creation after split of Crypto Driver and Hal implementation.
 *                                              Revision History has been cleaned as well.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vHsm_Platform__base: Information about the base component which consist of the following files:
 *  - vHsm_Hal_Public.h
 */
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  05.00.00  2020-09-15  visfpt  HSM-1082      Initial creation after split of Crypto Driver and Hal implementation.
 *                                              Revision History has been cleaned as well.
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
 *
 *
 *
 *
 *
 *
 */

#if !defined (VHSM_HAL_H)
# define VHSM_HAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "vHsm_Hal_Public.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define VHSM_HAL_VERSION                                             (0x0500u)
# define VHSM_HAL_RELEASE_VERSION                                     (0x00u)

/* Component Version Information */
/* No u suffix is used for shift operator because some compilers may have problems */
# define VHSM_HAL_SW_MAJOR_VERSION                                    (VHSM_HAL_VERSION >> 8)
# define VHSM_HAL_SW_MINOR_VERSION                                    (VHSM_HAL_VERSION & 0x00FFu)
# define VHSM_HAL_SW_PATCH_VERSION                                    (VHSM_HAL_RELEASE_VERSION)

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

#endif /* VHSM_HAL_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Hal.h
 *********************************************************************************************************************/

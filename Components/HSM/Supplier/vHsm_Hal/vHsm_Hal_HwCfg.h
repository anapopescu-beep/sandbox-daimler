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
/*!        \file  vHsm_Hal_HwCfg.h
 *        \brief  vHsm hardware abstraction platform configuration
 *
 *      \details  This files defines the configuration of the hardware specific implementation.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_HAL_HWCFG_H)
# define VHSM_HAL_HWCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Enable various callouts for vHsm_Core if required by the hardware platform */
#define VHSM_HAL_CALLOUT_GETCODEFLASHADDRESS                          STD_OFF
#define VHSM_HAL_CALLOUT_PREPAREJOBDATA                               STD_ON
#define VHSM_HAL_CALLOUT_GETIPCADDRESS                                STD_ON
#define VHSM_HAL_CALLOUT_MANAGECODEFLASHACCESS                        STD_OFF
#define VHSM_HAL_CALLOUT_TRIGGERSOFTWARERESET                         STD_ON
#define VHSM_HAL_CALLOUT_DEBUGGERPRESENCE                             STD_ON

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

/**********************************************************************************************************************
 *  vHsm_Hal_PrepareCryptoJobDataWithoutLengths()
 *********************************************************************************************************************/
/*! \brief         Prepare input and output pointers in Crypto job for access from HSM side.
 *  \details       Output length pointers are not remapped in this function.
 *  \pre           -
 *  \param[in,out] jobInputOutput     The jobs primitive input output data.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_PrepareCryptoJobDataWithoutLengths(
  P2VAR(Crypto_JobPrimitiveInputOutputType, AUTOMATIC, VHSM_HAL_APPL_VAR) jobInputOutput);

/**********************************************************************************************************************
 *  vHsm_Hal_PrepareKeyMJobDataWithoutLengths()
 *********************************************************************************************************************/
/*! \brief         Prepare input and output pointers in KeyM job for access from HSM side.
 *  \details       Output length pointers are not remapped in this function.
 *  \pre           -
 *  \param[in,out] jobInputOutput     The jobs primitive input output data.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_PrepareKeyMJobDataWithoutLengths(
  P2VAR(vHsm_KeyM_InputOutputType, AUTOMATIC, VHSM_HAL_APPL_VAR) jobInputOutput);

#endif /* VHSM_HAL_HWCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Hal_HwCfg.h
 *********************************************************************************************************************/

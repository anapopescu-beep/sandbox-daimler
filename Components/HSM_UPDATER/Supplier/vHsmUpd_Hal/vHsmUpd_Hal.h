/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsmUpd_Hal.h
 *        \brief  vHsmUpd_Hal header file
 *
 *      \details  Header file for the vHsmUpd HAL (Hardware Abstraction Layer). Defines the public API.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Tobias Schwindl               virstl        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id                 Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2019-05-15  virstl  STORY-11970               vHsmUpd shall support startup of Host-Cores (TriCore 3xx)
 *            2019-05-20  virstl  STORY-9512                vHsmUpd shall use new memory interface (vMemAccM and vMem)
 *  01.00.01  2019-07-11  virstl  ESCAN00103678             vHsmUpd for Tc3xx blank check does not work as expected
 *                                                          resulting in a dead ECU
 *********************************************************************************************************************/

#if !defined (VHSMUPD_HAL_H)
# define VHSMUPD_HAL_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define VHSMUPD_HAL_SW_MAJOR_VERSION                    (1u)
# define VHSMUPD_HAL_SW_MINOR_VERSION                    (0u)
# define VHSMUPD_HAL_SW_PATCH_VERSION                    (1u)

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  vHsmUpd_Hal_IsBlank()
*********************************************************************************************************************/
/*!
* \brief       Checks if a specified memory page is blank, i.e. the memory driver can program this page.
* \details     -
* \return      TRUE if page is blank, FALSE otherwise.
* \param[in]   uint32 address is the area where to perform the blank check. Always one page is checked.
* \pre         -
* \context     TASK
* \reentrant   FALSE
* \synchronous TRUE
*/
FUNC(boolean, VHSMUPD_HAL_CODE) vHsmUpd_Hal_IsBlank(uint32 address);

#endif /* VHSMUPD_HAL_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Hal.h
 *********************************************************************************************************************/


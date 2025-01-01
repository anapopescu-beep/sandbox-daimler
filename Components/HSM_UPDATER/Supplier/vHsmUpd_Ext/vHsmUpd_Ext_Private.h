/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsmUpd_Ext_Private.h
 *        \brief  vHsmUpd Vector Extension internal function related header file.
 *
 *      \details  This header file defines the internal functions in the vHsmUpd_Ext_Vector extension.
 *
 *********************************************************************************************************************/

#ifndef VHSMUPD_EXT_PRIVATE_H
#define VHSMUPD_EXT_PRIVATE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* Include all module internal header files */
#include "vHsmUpd_Ext_Callout.h"
#include "vHsmUpd_Ext_Common.h"
#include "vHsmUpd_Ext_Crypto.h"
#include "vHsmUpd_Ext_Ipc.h"
#include "vHsmUpd_Ext_MemAb.h"
#include "vHsmUpd_Ext.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Fixed value for address area of host since we always access through direct pointer */
#ifndef VHSMUPD_EXT_ADDRESS_AREA_OF_HOST  /* COV_VHSMUPD_EXT_COMPATIBILITY */
# define VHSMUPD_EXT_ADDRESS_AREA_OF_HOST                                                  0u
#endif

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
 *  GLOBAL FUNCTION PROTOTYPE
 *********************************************************************************************************************/

#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSMUPD_EXT_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_Private.h
 *********************************************************************************************************************/

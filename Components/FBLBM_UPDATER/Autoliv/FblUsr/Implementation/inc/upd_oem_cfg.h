/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         FBL updater callout routines - OEM specific
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
 *                 FBL Updater. These functions may influence the behavior of the updater in principle.
 *                 Therefore, great care must be taken to verify the correctness of the implementation.
 *                 The contents of the originally delivered files are only examples resp. implementation proposals.
 *                 With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                 Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                 admissible by law or statute.
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Marco Riedl                   Rie           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2019-03-13  Rie     ESCAN00102469    Added support for LibNvPattern
 **********************************************************************************************************************/

#ifndef UPD_OEM_CFG_H
#define UPD_OEM_CFG_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Fbl_Cfg.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/*-- Overwrite Callout Functions -------------------------------------------------------------------------------------*/
#define FBL_UPD_CALLOUT_INIT_POWER_ON_OEM          ApplFblUpdOemInit

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
# define FBL_UPD_CALLOUT_CHECK_RESPONSE_PENDING    ApplFblUpdOemCheckResponsePending
# define FBL_UPD_CALLOUT_PREPARE_RESPONSE_PENDING  ApplFblUpdOemPrepareResponsePending

# define FBL_UPD_HOOK_SEND_RESPONSE                FblUpdSendResponse
# define FBL_UPD_ENABLE_HOOK_SEND_RESPONSE
#else
# define FBL_UPD_DISABLE_RESPONSE_PENDING
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */

#define FBL_UPD_HOOK_INVALIDATE_UPDATER            ApplFblUpdOemInvalidateUpdater
#define FBL_UPD_LBT_NR_OF_UPDATER                  FBL_LBT_UPDATER_BLOCK_NUMBER

#endif /* UPD_OEM_CFG_H */

/***********************************************************************************************************************
 *  END OF FILE: UPD_OEM_CFG.H
 **********************************************************************************************************************/

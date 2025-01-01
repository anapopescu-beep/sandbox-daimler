/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         FBL updater callout routines - Platform specific for Tricore Aurix Plus TC3xx
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
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *  Sebastian Loos                Shs           Vector Informatik GmbH
 *  Dan Jiga                      JDn           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2018-06-11  Shs     -                Initial release
 *  02.00.00   2020-04-27  JDn     FBL-1016         Support of vBaseEnv and Bootmanager
 **********************************************************************************************************************/

#ifndef UPD_HW_CFG_H
#define UPD_HW_CFG_H

#include "FblBm_Cfg.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/


/*-- Define Hook Functions -------------------------------------------------------------------------------------------*/
#if defined( FBLBM_ENABLE_STANDALONE_MODE )
#else
# define FBL_UPD_HOOK_PREPARE_ERASE   ApplFblUpdHwSetBmhdToUpdater
# define FBL_UPD_HOOK_FINALIZE_VERIFY ApplFblUpdHwSetBmhdToFbl
#endif /* FBLBM_ENABLE_STANDALONE_MODE */

/*-- Overwrite Callout Functions -------------------------------------------------------------------------------------*/
/** Hardware specific initialization callout */
/* # define FBL_UPD_CALLOUT_INIT_POWER_ON_HW    ApplFblUpdHwInit */
/** Callout to perform reset */
/* # define FBL_UPD_CALLOUT_RESET               ApplFblUpdHwReset */

/*-- Define ----------------------------------------------------------------------------------------------------------*/

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
#else
/** Define content of BMHD: (See Bmhd_ToFbl.c / Bmhd_ToUpdater.c) */
# define FBLUPDAPHW_BMHD_TO_FBL     FblUpdBmhdField_ToFblBlk0
# define FBLUPDAPHW_BMHD_TO_UPDATER FblUpdBmhdField_ToUpdaterBlk0

/** Select UCB_BMHD0 to use */
# define FBLUPDAPHW_BMHD_ORIG (FBLFLIO_UCB00_BMHD0_ORIG)
# define FBLUPDAPHW_BMHD_COPY (FBLFLIO_UCB08_BMHD0_COPY)
/** Select used UCB_BMHD1 */
/* #define FBLUPDAPHW_BMHD_ORIG (FBLFLIO_UCB01_BMHD1_ORIG) */
/* #define FBLUPDAPHW_BMHD_COPY (FBLFLIO_UCB09_BMHD1_COPY) */
/** Select used UCB_BMHD2 */
/* #define FBLUPDAPHW_BMHD_ORIG (FBLFLIO_UCB02_BMHD2_ORIG) */
/* #define FBLUPDAPHW_BMHD_COPY (FBLFLIO_UCB10_BMHD2_COPY) */
/** Select used UCB_BMHD3 */
/* #define FBLUPDAPHW_BMHD_ORIG (FBLFLIO_UCB03_BMHD3_ORIG) */
/* #define FBLUPDAPHW_BMHD_COPY (FBLFLIO_UCB11_BMHD3_COPY) */

/**  Enable writing the BMHD (UCB) to ensure reset-safe operation by defining: */
/* #define FBLUPDAPHW_ENABLE_RESET_SAFETY */

/** After writing a BMHD successfully, set it to CONFIRMED state */
/* #define FBLUPDAPHW_ENABLE_CONFIRME_BMHD */

/** Use Disable Protection sequence to enable write access to (CONFIRMED) BMHDs */
/* #define FBLUPDAPHW_ENABLE_DISABLE_PROTECTION */
#endif /* FBLBM_ENABLE_STANDALONE_MODE */

#endif /* UPD_HW_CFG_H */

/***********************************************************************************************************************
 *  END OF FILE: UPD_HW_CFG.H
 **********************************************************************************************************************/

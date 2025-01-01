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

#ifndef UPD_HW_AP_H
#define UPD_HW_AP_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblUpd_Ap_Tc3xx CQComponent : Implementation */
#define FBLUPD_AP_TC3XX_VERSION            0x0200u
#define FBLUPD_AP_TC3XX_RELEASE_VERSION    0x00u

/* Interface version */
/** Major interface version identifies incompatible changes */
#define FBL_UPD_AP_HW_API_VERSION_MAJOR      0x01u
/** Minor interface version identifies backward compatible changes */
#define FBL_UPD_AP_HW_API_VERSION_MINOR      0x00u
/** Release interface version identifies cosmetic changes */
#define FBL_UPD_AP_HW_API_VERSION_RELEASE    0x00u

/***********************************************************************************************************************
*  INCLUDES
**********************************************************************************************************************/

#include "upd_types.h"
#include "upd_cfg.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define FBLUPDAPHW_ENABLE_DISABLE_PROTECTION
#define FBLUPDAPHW_ENABLE_RESET_SAFETY

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/
void ApplFblUpdHwInit(void);
void ApplFblUpdHwReset(void);

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
#else
tFblResult ApplFblUpdHwSetBmhdToUpdater(void);
tFblResult ApplFblUpdHwSetBmhdToFbl(void);
#endif /* FBLBM_ENABLE_STANDALONE_MODE */

#if defined( FBL_MIO_ENABLE_HOOKS )
void ApplFblPreMemDriver(vuint8 currentDevice, vuint8 currentFunction);
void ApplFblPostMemDriver(vuint8 currentDevice, vuint8 currentFunction);
#endif /* FBL_MIO_ENABLE_HOOKS */

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

#endif /* UPD_HW_AP_H */

/***********************************************************************************************************************
 *  END OF FILE: UDP_HW_AP.H
 **********************************************************************************************************************/

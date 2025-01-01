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

#ifndef UPD_OEM_AP_H
#define UPD_OEM_AP_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblUpd_Ap_Daimler CQComponent : Implementation */
#define FBLUPD_AP_DAIMLER_VERSION             0x0200u
#define FBLUPD_AP_DAIMLER_RELEASE_VERSION     0x00u

/* Interface version */
/** Major interface version identifies incompatible changes */
#define FBL_UPD_AP_OEM_API_VERSION_MAJOR     0x01u
/** Minor interface version identifies backward compatible changes */
#define FBL_UPD_AP_OEM_API_VERSION_MINOR     0x02u
/** Release interface version identifies cosmetic changes */
#define FBL_UPD_AP_OEM_API_VERSION_RELEASE   0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "upd_types.h"
#include "upd_cfg.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define FblRealTimeSupport       FblLookForWatchdog

/** Verification function is not needed in the updater */
#define SecM_Verification        0
#define SecVerification          0
#define SecM_VerifySignature     0
#define SecM_VerifyClassDDD      0

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
/* Reset response flag access macros */  /* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
# define ApplFblReadResetResponseFlag(buffer)      ApplFblNvReadResetResponseFlag(buffer)
# define ApplFblWriteResetResponseFlag(buffer)     ApplFblNvWriteResetResponseFlag(buffer)
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

void ApplFblUpdOemInit(void);
tFblResult ApplFblUpdOemInvalidateUpdater( void );
tFblResult ApplFblUpdOemUpdateMetadata(void);

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
tFblResult ApplFblUpdOemCheckResponsePending( void );
void ApplFblUpdOemPrepareResponsePending(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pResponse);
#  if ( FblCw_GetSizeOfDcmDslConnectionInfo() > 1u )
tFblResult ApplFblWriteDcmDslRxTesterSourceAddr(vuint8* buffer);
tFblResult ApplFblReadDcmDslRxTesterSourceAddr(vuint8* buffer);
#  endif /* ( FblCw_GetSizeOfDcmDslConnectionInfo() > 1u ) */
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */

#endif /* UDP_OEM_AP_H */

/***********************************************************************************************************************
 *  END OF FILE: UDP_OEM_AP.H
 **********************************************************************************************************************/

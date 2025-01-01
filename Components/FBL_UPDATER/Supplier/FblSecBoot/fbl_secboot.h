/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         SecureBoot implementation
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2020-01-07  visrie  FBL-524          Initial release
 *  01.00.01   2020-04-27  visrie  FBL-1773         Added API reference version define
 *  02.00.00   2020-05-19  vistbe  FBL-1016         No changes
 *  02.01.00   2021-01-19  visrie  FBL-2648         No changes
 *                                 FBL-2641         Updated to new API version
 *  02.02.00   2021-09-08  visjdn  FBL-3352         No changes
 **********************************************************************************************************************/

#ifndef FBL_SECBOOT_H
#define FBL_SECBOOT_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblLib_SecBoot_vHsm CQComponent : Implementation */
#define FBLLIB_SECBOOT_VHSM_VERSION           0x0202u
#define FBLLIB_SECBOOT_VHSM_RELEASE_VERSION   0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "FblSb_Cfg.h"
#include "FblBm_Cfg.h"
#include "fbl_secboot_ap.h"
#include "fbl_main_types.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Reference interface version */
/** Major interface version identifies incompatible changes */
#define FBLSB_API_REFERENCE_VERSION_MAJOR    0x02u
/** Minor interface version identifies backward compatible changes */
#define FBLSB_API_REFERENCE_VERSION_MINOR    0x01u
/** Release interface version identifies cosmetic changes */
#define FBLSB_API_REFERENCE_VERSION_RELEASE  0x00u

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

typedef enum
{
   FBLSB_EXT_ERR_CODE_NONE = 0u,
   FBLSB_EXT_ERR_CODE_GENERAL,
   FBLSB_EXT_ERR_CODE_CRC,
   FBLSB_EXT_ERR_CODE_SIGNATURE,
   FBLSB_EXT_ERR_CODE_MEMORY
} tFblSbExtErrCode;

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( FBLSB_ENABLE_COPY_FLASH_DRIVER )
void FblSb_CopyFlashDriver( void );
#endif /* FBLSB_ENABLE_COPY_FLASH_DRIVER */

void FblSb_Init(void);
tFblResult FblSb_VerifyFblLbt(const V_MEMRAM1 tFblHeader V_MEMRAM2 V_MEMRAM3 * fblHeader);
tFblResult FblSb_VerifyHeader(const V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 * bmHdrHeader);
tFblResult FblSb_VerifySegments(const V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 *bmHdrHeader);

tFblResult FblSb_UpdateInitialSegments(void);

#if defined( FBLSB_ENABLE_GENERATE_CMAC )
tFblResult FblSb_UpdateFblMac(V_MEMROM1 tFblHeader V_MEMROM2 V_MEMROM3 * fblHeader);
tFblResult FblSb_UpdateBlockMac(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
   V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList);
#endif /* FBLSB_ENABLE_GENERATE_CMAC */

tFblSbExtErrCode FblSb_GetExtendedErrorCode(void);

#endif /* FBL_SECBOOT_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_SECBOOT.H
 **********************************************************************************************************************/

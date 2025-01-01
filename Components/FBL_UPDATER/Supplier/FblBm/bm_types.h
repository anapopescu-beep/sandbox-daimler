/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Main module of BM
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *  04.00.00   2019-10-10  vistmo  FBL-390          No changes
 *  04.00.01   2019-11-05  visrie  ESCAN00104616    No changes
 *                                 ESCAN00104790    No changes
 *  05.00.00   2019-12-04  visrie  FBL-456          Added support for new FblLibSecBoot interface
 *                                 ESCAN00104644    No changes
 *                                 ESCAN00105176    No changes
 *  05.01.00   2020-01-13  visrie  ESCAN00104481    No changes
 *                                 FBL-953          Reworked handling of AP include files
 *  05.02.00   2020-02-28  vistbe  FBL-949          Split configuration files
 *  06.00.00   2020-04-08  visrie  FBL-1016         No changes
 *  06.00.01   2020-04-08  visrie  ESCAN00106837    No changes
 *  06.00.02   2020-10-28  visrcn  ESCAN00107189    No changes
 *  06.01.00   2021-08-11  visrie  FBL-3394         No changes
 *  06.02.00   2022-02-04  visrie  FBL-4602         No changes
 *  06.02.01   2022-04-06  vismix  ESCAN00111029    No changes
 *  06.03.00   2022-04-08  visrie  FBL-4126         Improve usage for application
 *  06.04.00   2022-04-11  vishor  FBL-4822         No changes
 *  06.04.01   2022-04-28  vismix  ESCAN00111741    No changes
 *  06.05.00   2022-05-06  vishor  FBL-5148         No changes
 *  06.06.00   2022-07-13  vismix  FBL-5391         No changes
 *  06.06.01   2022-08-04  visjns  ESCAN00112070    No changes
 *  06.07.00   2022-11-07  vishor  FBL-4932         No changes
 *  06.08.00   2022-11-30  visrie  FBL-6065         No changes
 **********************************************************************************************************************/

#ifndef BM_TYPES_H
#define BM_TYPES_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Required for FBL base types */
#include "fbl_def.h"
#include "Fbl_Lbt.h"
#include "bm_hdr_types.h"
#include "FblBm_Lcfg.h"
#if defined( FBLBM_ENABLE_HARDWARE_CONFIGURATION )
# include "bm_hw_cfg.h"
#endif
#if defined( FBLBM_ENABLE_OEM_CONFIGURATION )
# include "bm_oem_cfg.h"
#endif
#if defined( FBLBM_ENABLE_GENERIC_CONFIGURATION )
# include "bm_ap_cfg.h"
#endif

#include "bm_shared.h"
#include "bm_types_header.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/** Values for BmHeader */
#define FBLBM_HEADER_MAGIC_VALUE          0x05ECB007u /* Magic word */
#define FBLBM_HEADER_MAJOR_VERSION        0x0001u /* Major version of BmHeader format */
#define FBLBM_HEADER_MINOR_VERSION        0x0000u /* Minor Version of BmHeader format */
#define FBLBM_HEADER_END_MAGIC_VALUE      0xCEC41160u /* Magic word to check for correct padding */

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/** Mandatory blocks information */
typedef struct
{
   tBlockDescriptor logicalBlock;   /**< Pointer to logical block */
   tFblBmHdrHeader  bmHeader;       /**< pointer to bootmanager header structure */
} tFblBmBlockInfo;

/** Error codes */
typedef enum
{
   FBLBM_ERROR_NO_ERROR = 0u,                 /*  0 */
   FBLBM_ERROR_HEADER_READ_FAILED,            /*  1 */
   FBLBM_ERROR_HEADER_MAGIC_FAILED,           /*  2 */
   FBLBM_ERROR_HEADER_VERSION_FAILED,         /*  3 */
   FBLBM_ERROR_HEADER_LENGTH_FAILED,          /*  4 */
   FBLBM_ERROR_VALIDITY_FAILED,               /*  5 */
   FBLBM_ERROR_FBL_BMHEADER_INCORRECT,        /*  6 */
   FBLBM_ERROR_FBL_VERIFICATION_FAILED,       /*  7 */
   FBLBM_ERROR_FBL_FBLHEADER_FAILED,          /*  8 */
   FBLBM_ERROR_KEY_NOT_AVAILABLE,             /*  9 */
   FBLBM_ERROR_UPDATER_SEARCH_INIT_FAILED,    /* 10 */
   FBLBM_ERROR_UPDATER_SEARCH_NEXT_FINISHED,  /* 11 */
   FBLBM_ERROR_UPDATER_HEADER_ADDRESS,        /* 12 */
   FBLBM_ERROR_UPDATER_HEADER_READ_ERROR,     /* 13 */
   FBLBM_ERROR_UPDATER_HEADER_CONSISTENCY,    /* 14 */
   FBLBM_ERROR_UPDATER_HEADER_TYPE,           /* 15 */
   FBLBM_ERROR_UPDATER_BLOCK_VALIDITY,        /* 16 */
   FBLBM_ERROR_UPDATER_HEADER_CMAC_VERIFY,    /* 17 */
   FBLBM_ERROR_UPDATER_VERIFY,                /* 18 */
   FBLBM_ERROR_LBT_POINTER_NULL,              /* 19 */
   FBLBM_ERROR_LBT_TOO_LARGE,                 /* 20 */
   FBLBM_ERROR_LBT_SIZE,                      /* 21 */
   FBLBM_ERROR_LBT_VERIFY,                    /* 22 */
   FBLBM_ERROR_REPROG_LBT_DESCR,              /* 23 */
   FBLBM_ERROR_REPROG_LBT_INVALID,            /* 24 */
   FBLBM_ERROR_REPROG_LBT_BMHEADER_INCORRECT, /* 25 */
   FBLBM_ERROR_REPROG_LBT_VERIFY_HEADER,      /* 26 */
   FBLBM_ERROR_REPROG_LBT_VERIFY_SEGMENTS,    /* 27 */
   FBLBM_ERROR_REPROG_LBT_MAGIC_FLAG,         /* 28 */
   FBLBM_ERROR_REPROG_LBT_BLOCK_COUNT,        /* 29 */
   FBLBM_ERROR_TARGET_LIST_INIT,              /* 30 */
   FBLBM_ERROR_TARGET_INVALID,                /* 31 */
   FBLBM_ERROR_TARGET_NO_VALID_HEADER,        /* 32 */
   FBLBM_ERROR_TARGET_VERIFICATION_FAILED,    /* 33 */
   FBLBM_ERROR_TARGET_INVALID_ADDRESS,        /* 34 */
   FBLBM_ERROR_TARGET_DEP_MANDATORY_MISSING,  /* 35 */
   FBLBM_ERROR_TARGET_DEP_NO_VALID_HEADER,    /* 36 */
   FBLBM_ERROR_TARGET_DEP_VERIFY_FAILED,      /* 37 */
   FBLBM_ERROR_END_OF_MAIN_REACHED,           /* 38 */
   FBLBM_ERROR_AP_CHECK_MAC_READ_FAIL,        /* 39 */
   FBLBM_ERROR_AP_CHECK_MAC_BUF_LENGTH,       /* 40 */
   FBLBM_ERROR_AP_CHECK_MAC_READ_FAIL_LENGTH  /* 41 */
} tFblBmError;

typedef enum
{
   FBLBM_KEY_IS_NOT_AVAILABLE,
   FBLBM_KEY_IS_AVAILABLE
} tFblBmKeyEmptyResult;

typedef enum
{
   FBLBM_MAC_IS_NOT_AVAILABLE,
   FBLBM_MAC_IS_AVAILABLE
} tFblBmMacEmptyResult;

#endif /* __BM_TYPES_H__ */

/***********************************************************************************************************************
 *  END OF FILE: BM_TYPES.H
 **********************************************************************************************************************/

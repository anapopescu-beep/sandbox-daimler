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
 *  04.00.01   2019-11-05  visrie  ESCAN00104616    Fixed include structure
 *                                 ESCAN00104790    Fixed variable types
 *  05.00.00   2019-12-04  visrie  FBL-456          No changes
 *                                 ESCAN00104644    No changes
 *                                 ESCAN00105176    No changes
 *  05.01.00   2020-01-13  visrie  ESCAN00104481    No changes
 *                                 FBL-953          No changes
 *  05.02.00   2020-02-28  vistbe  FBL-949          No changes
 *  06.00.00   2020-04-08  visrie  FBL-1016         No changes
 *  06.00.01   2020-04-08  visrie  ESCAN00106837    No changes
 *  06.00.02   2020-10-28  visrcn  ESCAN00107189    No changes
 *  06.01.00   2021-08-11  visrie  FBL-3394         No changes
 *  06.02.00   2022-02-04  visrie  FBL-4602         No changes
 *  06.02.01   2022-04-06  vismix  ESCAN00111029    No changes
 *  06.03.00   2022-04-08  visrie  FBL-4126         No changes
 *  06.04.00   2022-04-11  vishor  FBL-4822         No changes
 *  06.04.01   2022-04-28  vismix  ESCAN00111741    No changes
 *  06.05.00   2022-05-06  vishor  FBL-5148         No changes
 *  06.06.00   2022-07-13  vismix  FBL-5391         No changes
 *  06.06.01   2022-08-04  visjns  ESCAN00112070    No changes
 *  06.07.00   2022-11-07  vishor  FBL-4932         No changes
 *  06.08.00   2022-11-30  visrie  FBL-6065         No changes
 **********************************************************************************************************************/

#define BM_SHARED_SOURCE

/***********************************************************************************************************************
*  INCLUDES
**********************************************************************************************************************/

#include "fbl_inc.h"
#include "bm_shared.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#if defined( FBLBM_MAIN_ENABLE_MAGICFLAG )
# define FBLBM_MAIN_MAGICFLAG_START_SEC_VAR_NOINIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/** Reprogramming request storage variable */
V_MEMRAM0 volatile V_MEMRAM1 vuint8                      V_MEMRAM2 fblBmMagicFlag[kFblBmNoOfMagicBytes];
# if defined( FBLBM_MAIN_ENABLE_FBLSTART_CHANNEL )
V_MEMRAM0 volatile V_MEMRAM1 vuint8                      V_MEMRAM2 fblBmFblStartChannel;
# endif /* FBLBM_MAIN_ENABLE_FBLSTART_PARAM */
# if defined( FBLBM_MAIN_ENABLE_FBLSTART_PARAM )
V_MEMRAM0 volatile V_MEMRAM1 tFblBmFblStartParameter     V_MEMRAM2 fblBmFblStartParameter;
# endif /* FBLBM_MAIN_ENABLE_FBLSTART_PARAM */
# if defined( FBLBM_MAIN_ENABLE_APPLSTART_PARAM )
V_MEMRAM0 volatile V_MEMRAM1 tFblBmApplStartParameter    V_MEMRAM2 fblBmApplStartParameter;
# endif /* FBLBM_MAIN_ENABLE_APPLSTART_PARAM */
# define FBLBM_MAIN_MAGICFLAG_STOP_SEC_VAR_NOINIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBLBM_MAIN_ENABLE_MAGICFLAG */

/***********************************************************************************************************************
 *  END OF FILE: BM_SHARED.C
 **********************************************************************************************************************/

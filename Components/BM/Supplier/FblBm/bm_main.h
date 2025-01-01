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
 *  04.00.00   2019-10-10  vistmo  FBL-390          Adapt main function interface for vBaseEnv
 *  04.00.01   2019-11-05  visrie  ESCAN00104616    No changes
 *                                 ESCAN00104790    No changes
 *  05.00.00   2019-12-04  visrie  FBL-456          No changes
 *                                 ESCAN00104644    No changes
 *                                 ESCAN00105176    No changes
 *  05.01.00   2020-01-13  visrie  ESCAN00104481    Fixed redeclaration issue
 *                                 FBL-953          Reworked handling of AP include files
 *  05.02.00   2020-02-28  vistbe  FBL-949          No changes
 *  06.00.00   2020-04-08  visrie  FBL-1016         No changes
 *  06.00.01   2020-04-08  visrie  ESCAN00106837    No changes
 *  06.00.02   2020-10-28  visrcn  ESCAN00107189    Compiler error: Wrong definition for FblMain function
 *  06.01.00   2021-08-11  visrie  FBL-3394         Added/adapted MemMap sections
 *  06.02.00   2022-02-04  visrie  FBL-4602         No changes
 *  06.02.01   2022-04-06  vismix  ESCAN00111029    No changes
 *  06.03.00   2022-04-08  visrie  FBL-4126         No changes
 *  06.04.00   2022-04-11  vishor  FBL-4822         Changed external switches to internal switches
 *  06.04.01   2022-04-28  vismix  ESCAN00111741    No changes
 *  06.05.00   2022-05-06  vishor  FBL-5148         No changes
 *  06.06.00   2022-07-13  vismix  FBL-5391         No changes
 *  06.06.01   2022-08-04  visjns  ESCAN00112070    No changes
 *  06.07.00   2022-11-07  vishor  FBL-4932         No changes
 *  06.08.00   2022-11-30  visrie  FBL-6065         Encapsulate FblMain declaration
 **********************************************************************************************************************/

#ifndef BM_MAIN_H
#define BM_MAIN_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblBm_Main CQComponent : Implementation */
#define FBLBM_MAIN_VERSION             0x0608u
#define FBLBM_MAIN_RELEASE_VERSION     0x00u

/* Interface version */
/** Major interface version identifies incompatible changes */
#define FBLBM_API_VERSION_MAJOR        0x03u
/** Minor interface version identifies backward compatible changes */
#define FBLBM_API_VERSION_MINOR        0x00u
/** Release interface version identifies cosmetic changes */
#define FBLBM_API_VERSION_RELEASE      0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "bm_types.h"
#if defined( FBLBM_ENABLE_HARDWARE_CONFIGURATION )
# include "bm_hw_ap.h"
#endif
#if defined( FBLBM_ENABLE_OEM_CONFIGURATION )
# include "bm_oem_ap.h"
#endif
#if defined( FBLBM_ENABLE_GENERIC_CONFIGURATION )
# include "bm_ap.h"
#endif
#include "bm_hdr.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/** Helper macro to get number of array entries */ /* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define FBLBM_ARRAY_SIZE(arr)                            (sizeof(arr) / sizeof((arr)[0u]))

/** Undefined hook function */
#define FBLBM_HOOK_NONE                                  (tFblBmFunc)0

#if defined( FBLBM_ENABLE_STANDALONE_MODE ) && \
    defined( FBLBM_INSTANCE_BOOTMANAGER )
/** Pointer type to byte data in RAM */
typedef V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *        tFblMemRamData;
/** Pointer type to constant byte data in RAM */
typedef const V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *  tFblMemConstRamData;

/** Response pending state (never active) */
# define GetRcrRpInProgress()             ((vuint8)0x00u)

# if defined( FBL_CW_LOCKS_TASKS ) || \
     defined( FBLCW_LOCKS_TASKS )
/***********************************************************************************************************************
*  COM WRAPPER COMPATIBILITY DEFINITIONS
**********************************************************************************************************************/
/* Define interface version for classic FblWrapperCom modules */
#  if !defined( FBL_CW_API_REFERENCE_VERSION_MAJOR )
/** Major interface version identifies incompatible changes */
#   define FBL_CW_API_REFERENCE_VERSION_MAJOR     0x01u
/** Minor interface version identifies backward compatible changes */
#   define FBL_CW_API_REFERENCE_VERSION_MINOR     0x00u
/** Release interface version identifies cosmetic changes */
#   define FBL_CW_API_REFERENCE_VERSION_RELEASE   0x00u
#  endif
#  if !defined( FBL_CW_CFG_PTR )
#   define FBL_CW_CFG_PTR V_NULL
#  endif
# else
#  define FBL_CW_LOCKS_TASKS
#  define FBLCW_LOCKS_TASKS
#  define FblCwIsTimerTaskAllowed()        ((vuint8)0x00u)
#  define FblCwIsStateTaskAllowed()        ((vuint8)0x00u)
#  define FblCwRetransmitRP()
#  define FblCwClrInit()
#  define FblCwTimerTask()
#  define FblCwStateTask()
# endif /* FBL_CW_LOCKS_TASKS || FBLCW_LOCKS_TASKS */
#endif /* FBLBM_ENABLE_STANDALONE_MODE && FBLBM_INSTANCE_BOOTMANAGER */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLBM_HEADER_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMROM0 extern V_MEMROM1 tFblBmHeader V_MEMROM2 FblBmHeader;
#define FBLBM_HEADER_STOP_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLBM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Helper functions */
#if defined( FBLBM_ENABLE_STANDALONE_MODE ) && \
    defined( FBLBM_INSTANCE_BOOTMANAGER )
void FblMemSetInteger( vuintx count, vuint32 input, tFblMemRamData buffer );
vuint32 FblMemGetInteger( vuintx count, tFblMemConstRamData buffer );
#endif /* FBLBM_ENABLE_STANDALONE_MODE && FBLBM_INSTANCE_BOOTMANAGER */

#if defined( FBLBM_INSTANCE_BOOTMANAGER )
void V_API_NEAR FblMain(void); /* PRQA S 5209 */ /* MD_FblBmMain_5209_Main */
#endif /* FBLBM_INSTANCE_BOOTMANAGER */

#define FBLBM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBLBM_MAIN_ENABLE_FBL_START )
# define FBLBM_FBLSTART_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# if defined( FBLBM_MAIN_ENABLE_FBLSTART_PARAM )
void V_CALLBACK_NEAR FblStart( FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE_TYPE_FIRST
   V_MEMRAM1 void V_MEMRAM2 V_MEMRAM3 * pFblStartParam, vuint8 length );
# else
void V_CALLBACK_NEAR FblStart( FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE_TYPE_ONLY );
# endif /* FBL_MAIN_ENABLE_FBLSTART_PARAM */
# define FBLBM_FBLSTART_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBLBM_MAIN_ENABLE_FBL_START */

#if defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT )
# define FBLBM_APPLSTART_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# if defined( FBLBM_MAIN_ENABLE_APPLSTART_PARAM )
void ApplStart( V_MEMRAM1 void V_MEMRAM2 V_MEMRAM3 * pApplStartParam, vuint8 length );
# else
void ApplStart( void );
# endif /* FBLBM_MAIN_ENABLE_FBLSTART_PARAM */
# define FBLBM_APPLSTART_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBLBM_MAIN_ENABLE_STAY_IN_BOOT */

#endif /* BM_MAIN_H */

/***********************************************************************************************************************
 *  END OF FILE: BM_MAIN.H
 **********************************************************************************************************************/

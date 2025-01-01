/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Main module of FBL updater
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
 *  05.00.00   2019-10-10  vistmo  FBL-392          Adapt main function interface for vBaseEnv
 *  06.00.00   2020-04-08  visrie  FBL-1016         No changes
 *  06.00.01   2020-10-28  visrcn  ESCAN00107191    Compiler error: Wrong definition for FblMain function
 *  06.01.00   2022-04-13  vismix  FBL-4854         Added/adapted MemMap sections
 *  06.02.00   2022-05-06  vishor  FBL-5148         No changes
 *  06.03.00   2022-07-06  vismix  FBL-5235         No changes
 **********************************************************************************************************************/

#ifndef UPD_MAIN_H
#define UPD_MAIN_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblUpd_Main CQComponent : Implementation */
#define FBLUPD_MAIN_VERSION            0x0603u
#define FBLUPD_MAIN_RELEASE_VERSION    0x00u

/* Interface version */
/** Major interface version identifies incompatible changes */
#define FBL_UPD_API_VERSION_MAJOR      0x01u
/** Minor interface version identifies backward compatible changes */
#define FBL_UPD_API_VERSION_MINOR      0x02u
/** Release interface version identifies cosmetic changes */
#define FBL_UPD_API_VERSION_RELEASE    0x00u

/***********************************************************************************************************************
*  INCLUDES
**********************************************************************************************************************/

#include "upd_types.h"
#include "upd_cfg.h"

#if defined( FBL_UPD_ENABLE_RESPONSE_PENDING )
# include "fbl_cw.h"
#endif /* FBL_UPD_ENABLE_RESPONSE_PENDING */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Default values for configuration parameters */

/** Limit the number of update attempts in case of failure */
#if defined( FBL_UPD_MAX_RETRIES )
#else
# define FBL_UPD_MAX_RETRIES              3u
#endif /* FBL_UPD_MAX_RETRIES */

/** Buffer size used during write */
#if defined( FBL_UPD_BUFFER_SIZE )
#else
# define FBL_UPD_BUFFER_SIZE              (4096u)
#endif /* FBL_UPD_BUFFER_SIZE */
/** Buffer size used during verify */
#if defined( FBL_UPD_COMPARE_SIZE )
#else
# define FBL_UPD_COMPARE_SIZE             (FBL_UPD_BUFFER_SIZE / 2u)
#endif /* FBL_UPD_COMPARE_SIZE */

/** Maximum number of sub-segments per update segment */
#if defined( FBL_UPD_SEGMENT_COUNT )
#else
# define FBL_UPD_SEGMENT_COUNT               2u
#endif /* FBL_UPD_SEGMENT_COUNT */

/** Watchdog triggered every n-th cycle (has to power of two) */
#if defined( FBL_UPD_WATCHDOG_CYCLE_COUNT )
#else
# define FBL_UPD_WATCHDOG_CYCLE_COUNT        (0x20u)
#endif

/* Communication wrapper stubs */

#if defined( FBL_UPD_ENABLE_RESPONSE_PENDING )
/** Response pending state (always active) */
# define GetRcrRpInProgress()             ((vuint8)0x01u)
#else
/** Response pending state (never active) */
# define GetRcrRpInProgress()             ((vuint8)0x00u)
#endif /* FBL_UPD_ENABLE_RESPONSE_PENDING */
/** Diagnostic buffer state (always locked) */
#define GetDiagBufferLocked()             ((vuint8)0x01u)

#if defined( FBL_UPD_ENABLE_RESPONSE_PENDING )
/* State handling framework for shutdown request */
# define FblSetShutdownRequest()           FblUpdSetFblShutdownRequest()
# define FblUpdSetFblShutdownRequest()     (fblUpdShutdownState = 0x01u)
# define FblUpdClrFblShutdownRequest()     (fblUpdShutdownState = 0x00u)
# define FblUpdGetFblShutdownRequest()     (fblUpdShutdownState == 0x01u)
#endif /* FBL_UPD_ENABLE_RESPONSE_PENDING */

#if defined( FBL_CW_LOCKS_TASKS ) || \
    defined( FBLCW_LOCKS_TASKS )
/***********************************************************************************************************************
*  COM WRAPPER COMPATIBILITY DEFINITIONS
**********************************************************************************************************************/
/* Define interface version for classic FblWrapperCom modules */
# if !defined( FBL_CW_API_REFERENCE_VERSION_MAJOR )
/** Major interface version identifies incompatible changes */
#  define FBL_CW_API_REFERENCE_VERSION_MAJOR     0x01u
/** Minor interface version identifies backward compatible changes */
#  define FBL_CW_API_REFERENCE_VERSION_MINOR     0x00u
/** Release interface version identifies cosmetic changes */
#  define FBL_CW_API_REFERENCE_VERSION_RELEASE   0x00u
# endif
# if !defined( FBL_CW_CFG_PTR )
#  define FBL_CW_CFG_PTR V_NULL
# endif
#else
# define FBL_UPD_STUB_CW_API

# define FBL_CW_LOCKS_TASKS
# define FBLCW_LOCKS_TASKS
# define FblCwIsTimerTaskAllowed()        ((vuint8)0x00u)
# define FblCwIsStateTaskAllowed()        ((vuint8)0x00u)
# define FblCwRetransmitRP()
# define FblCwClrInit()
# define FblCwTimerTask()
# define FblCwStateTask()
# endif /* FBL_CW_LOCKS_TASKS || FBLCW_LOCKS_TASKS */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBL_UPD_MAIN_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_UPD_ENABLE_RESPONSE_PENDING )
V_MEMRAM0 extern V_MEMRAM1 vuint8   V_MEMRAM2 DiagBuffer[FBL_UPD_RESPONSE_PENDING_SIZE];
V_MEMRAM0 extern V_MEMRAM1 vuint8   V_MEMRAM2 fblUpdShutdownState;
#endif /* FBL_UPD_ENABLE_RESPONSE_PENDING */

#define FBL_UPD_MAIN_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( FBL_UPD_ENABLE_RESPONSE_PENDING)
# define FBL_UPD_RAMCODE_START_SEC_CODE
# include "MemMap.h"

void FblDiagTxErrorIndication( vuint8 cwMsgType );
void FblDiagRxIndication( V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagBuffer, tCwDataLengthType rxDataLength );
void FblDiagTxConfirmation( vuint8 cwMsgType );
V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * FblDiagRxGetPhysBuffer( tCwDataLengthType rxDataLength );
V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * FblDiagRxGetFuncBuffer( tCwDataLengthType rxDataLength );
void FblDiagRxStartIndication( void );
void FblDiagRxErrorIndication( void );

# define FBL_UPD_RAMCODE_STOP_SEC_CODE
# include "MemMap.h"
#endif /* FBL_UPD_ENABLE_RESPONSE_PENDING */

#define FBL_UPD_MAIN_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

void V_API_NEAR FblMain( void );  /* PRQA S 5209 */ /* MD_FblUpd_Main_5209 */
void FblMemSetInteger( vuintx count, vuint32 input, tFblMemRamData buffer );
vuint32 FblMemGetInteger( vuintx count, tFblMemConstRamData buffer );

#define FBL_UPD_MAIN_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* UPD_MAIN_H */

/***********************************************************************************************************************
 *  END OF FILE: UPD_MAIN.H
 **********************************************************************************************************************/

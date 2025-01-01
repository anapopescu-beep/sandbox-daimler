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
 *  05.00.00   2019-10-10  vistmo  FBL-392          No changes
 *  06.00.00   2020-04-08  visrie  FBL-1016         No changes
 *  06.00.01   2020-10-28  visrcn  ESCAN00107191    No changes
 *  06.01.00   2022-04-13  vismix  FBL-4854         No changes
 *  06.02.00   2022-05-06  vishor  FBL-5148         No changes
 *  06.03.00   2022-07-06  vismix  FBL-5235         No changes
 **********************************************************************************************************************/

#ifndef UPD_CFG_H
#define UPD_CFG_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "upd_hw_cfg.h"
#include "upd_oem_cfg.h"
#include "upd_ap_cfg.h"

/* Updated bootloader */
/* TODO by customer: Adapt file name to match updated bootloader */
#include "NewFbl.h"

#if defined( FBL_ENABLE_FLASHDRV_ROM )
#else
/* Header file for flashdriver ROM array */
# include "FlashRom.h"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/** Send RCR-RP messages during operation */
#if !defined( FBL_UPD_ENABLE_RESPONSE_PENDING ) && !defined( FBL_UPD_DISABLE_RESPONSE_PENDING )
# define FBL_UPD_ENABLE_RESPONSE_PENDING
#endif
#if defined( FBL_UPD_RESPONSE_PENDING_SIZE )
#else
/** Size of RCR-RP message */
# define FBL_UPD_RESPONSE_PENDING_SIZE       3u
#endif

/** Enabled padding of write buffers to match flash segment size */
#define FBL_UPD_ENABLE_PADDING

/** Limit the number of update attempts in case of failure */
#if defined( FBL_UPD_MAX_RETRIES )
#else
# define FBL_UPD_MAX_RETRIES                 3u
#endif

/** Buffer length used during write */
#if defined( FBL_UPD_BUFFER_SIZE )
#else
# define FBL_UPD_BUFFER_SIZE                 4096u
#endif
/** Buffer length used during verify */
#if defined( FBL_UPD_COMPARE_SIZE )
#else
# define FBL_UPD_COMPARE_SIZE                (FBL_UPD_BUFFER_SIZE / 2u)
#endif

/** Maximum number of sub-segments per update segment */
#if defined( FBL_UPD_SEGMENT_COUNT )
#else
# define FBL_UPD_SEGMENT_COUNT               2u
#endif /* FBL_UPD_SEGMENT_COUNT */

/** Watchdog triggered every n-th cycle (has to power of two) */
#if defined( FBL_UPD_WATCHDOG_CYCLE_COUNT )
#else
# define FBL_UPD_WATCHDOG_CYCLE_COUNT        0x20u
#endif

#endif /* UPD_CFG_H */

/***********************************************************************************************************************
 *  END OF FILE: UPD_CFG.H
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Main module of FBL updater - Type definitions
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

#ifndef UPD_TYPES_H
#define UPD_TYPES_H

/***********************************************************************************************************************
*  INCLUDES
 **********************************************************************************************************************/

/* Required for FBL base types */
#include "fbl_def.h"

#include "fbl_main_types.h"

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/** Pointer type to byte data in RAM */
typedef V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *        tFblMemRamData;
/** Pointer type to constant byte data in RAM */
typedef const V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *  tFblMemConstRamData;

/** Segment information */
typedef struct
{
   tFblAddress    source;     /**< Address of source data (e.g. constant buffer) */
   tFblAddress    target;     /**< Target address */
   tFblLength     length;     /**< Length of segment */
} tFblUpdSegmentInfo;

/** Update hook function pointer */
typedef tFblResult (*tFblUpdFunc)( void );
/** Segment adjustment hook function pointer */
typedef tFblResult (* tFblUpAdjustSegment)( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount );

#endif /* UPD_TYPES_H */

/***********************************************************************************************************************
 *  END OF FILE: UPD_TYPES.H
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Implementation of pattern/mask based non-volatile information storage
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
 *  01.00.00   2017-02-24  visci   -                Initial version
 *  01.01.00   2018-06-15  visci   ESCAN00099699    No changes
 *  01.02.00   2018-09-24  visrr   ESCAN00100837    No changes
 *  01.03.00   2018-12-07  visshs  ESCAN00101559    Added API functions FblNvPattern...SetByBlockDescriptor
 *  01.04.00   2019-01-25  viskjs  ESCAN00101824    Added patterns that can be validated multiple times
 *                                 ESCAN00101823    Added feature to store arbitrary data at end of logical block
 *  01.04.01   2019-03-26  viskjs  ESCAN00102200    No changes
 *                                 ESCAN00102204    No changes
 *                                 ESCAN00102646    No changes
 *  01.04.02   2019-07-22  vistbe  ESCAN00103605    No changes
 *  01.04.03   2020-05-07  visjdn  ESCAN00106002    No changes
 *  01.04.04   2021-03-03  visrie  ESCAN00108616    No changes
 *                                 ESCAN00108753    No changes
 *                                 FBL-3129         Added/adapted MemMap sections
 *                                                  Update to MISRA 2012
 *  01.04.05   2021-03-16  visrie  ESCAN00108859    No changes
 *  01.05.00   2021-06-16  visrie  FBL-3641         No changes
 *  01.06.00   2022-08-11  visjdn  FBL-5687         Return further pattern state information
 **********************************************************************************************************************/

#ifndef FBLLIB_NVPATTERN_H
#define FBLLIB_NVPATTERN_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblLib_NvPattern CQComponent : Implementation */
#define FBLLIB_NVPATTERN_VERSION           0x0106u
#define FBLLIB_NVPATTERN_RELEASE_VERSION   0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_nvpattern_oem.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Set Id of separator item to last item if storing arbitrary values is not enabled */
#if !defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
# define kFblNvPatternId_Separator           kFblNvPatternId_Last
#endif /* FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/** Representation of status of marker/mask */
typedef enum
{
   FBL_NVPATTERN_STATE_NOMEMSEGMENT = 0u, /**< No matching memory segment has been found */
   FBL_NVPATTERN_STATE_READERROR,         /**< Memory area could not be read */
   FBL_NVPATTERN_STATE_ERASED,            /**< Marker/mask area is erased */
   FBL_NVPATTERN_STATE_UNEXPECTEDVALUE,   /**< Unexpected marker/mask value */
   FBL_NVPATTERN_STATE_EXPECTEDVALUE      /**< Expected marker/mask value is set */
} tFblNvPatternItemState;

/** Status of pattern */
typedef struct
{
   tFblNvPatternItemState markerState;
   tFblNvPatternItemState maskState;
} tFblNvPatternState;

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLNVPATTERN_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


tFblNvPatternState FblNvPatternGetPatternState( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * pBlockDescriptor,
                                                       tFblNvPatternId patternId,
                                                       V_MEMRAM1 IO_PositionType V_MEMRAM2 V_MEMRAM3 * pPatternAddress,
                                                       V_MEMRAM1 IO_SizeType V_MEMRAM2 V_MEMRAM3 * pPatternLength );
vsint16 FblNvPatternGetBaseAddr( vuint8 blockNr,
                                 tFblNvPatternId patternId,
                                 V_MEMRAM1 IO_PositionType V_MEMRAM2 V_MEMRAM3 * pPatternAddress,
                                 V_MEMRAM1 IO_SizeType V_MEMRAM2 V_MEMRAM3 * pPatternLength );
vsint16 FblNvPatternGetBaseAddrByBlockDescriptor( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
                                                  tFblNvPatternId patternId,
                                                  V_MEMRAM1 IO_PositionType V_MEMRAM2 V_MEMRAM3 * pPatternAddress,
                                                  V_MEMRAM1 IO_SizeType V_MEMRAM2 V_MEMRAM3 * pPatternLength );
tFblResult FblNvPatternSet( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor, tFblNvPatternId patternId );
tFblResult FblNvPatternSetByBlockDescriptor( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
   tFblNvPatternId patternId );
tFblResult FblNvPatternClr( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor, tFblNvPatternId patternId );
tFblResult FblNvPatternClrByBlockDescriptor( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
   tFblNvPatternId patternId );
tFblResult FblNvPatternGet( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor, tFblNvPatternId patternId );
tFblResult FblNvPatternGetByBlockDescriptor( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
   tFblNvPatternId patternId );

#if defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
tFblResult FblNvPatternGetProperty(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
      tFblNvPatternId propertyId,
      IO_SizeType bufferLength,
      vuint8* pDestBuffer );
tFblResult FblNvPatternGetPropertyByBlockDescriptor(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
      tFblNvPatternId propertyId,
      IO_SizeType bufferLength,
      vuint8* pDestBuffer );
tFblResult FblNvPatternSetProperty(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
      const vuint8* pSrcBuffer,
      tFblNvPatternId propertyId);
tFblResult FblNvPatternSetPropertyByBlockDescriptor(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
      const vuint8* pSrcBuffer,
      tFblNvPatternId propertyId);
#endif /* FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */

#define FBLNVPATTERN_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FBLLIB_NVPATTERN_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_NVPATTERN.H
 **********************************************************************************************************************/

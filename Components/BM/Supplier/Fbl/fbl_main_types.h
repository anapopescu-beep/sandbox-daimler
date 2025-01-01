/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Main module of FBL
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
 *  05.00.00   2019-10-10  vistmo  FBL-388          No changes
 *  05.01.00   2019-11-14  visrcn  FBL-830          No changes
 *  05.01.01   2020-02-27  vistbe  ESCAN00105432    No changes
 *  06.00.00   2020-04-08  visrie  FBL-1016         No changes
 *  06.01.00   2020-04-29  vistmo  FBL-1584         No changes
 *  06.01.01   2020-10-28  visrcn  ESCAN00107190    No changes
 *  06.01.02   2020-11-26  visrcn  ESCAN00107979    No changes
 *  06.02.00   2022-04-08  vishor  FBL-4852         No changes
 *  06.03.00   2022-05-06  vishor  FBL-5148         No changes
 *  06.04.00   2022-07-06  vismix  FBL-5235         No changes
 *  06.05.00   2022-11-30  visrie  FBL-6065         No changes
 **********************************************************************************************************************/

#ifndef FBL_MAIN_TYPES_H
#define FBL_MAIN_TYPES_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "bm_types.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblHeader access
 **********************************************************************************************************************/

/* Define to access the FBL header structure */
#define FblHeaderTable  ((V_MEMROM1_FAR tFblHeader V_MEMROM2_FAR V_MEMROM3 *)(FBL_HEADER_ADDRESS))
#define FblHeaderLocal  ((V_MEMROM1_FAR tFblHeader V_MEMROM2_FAR V_MEMROM3 *)(&FblHeader))

/* Access macros for FblHeader elements for application */
#if defined( FBL_ENABLE_COMMON_DATA )
# define GetFblCommonDataPtr()   (FblHeaderTable->pFblCommonData)
#endif

#define FBL_MAIN_HEADER_MAGIC_FLAG    0x58462918u

/***********************************************************************************************************************
 *  TYPE DEFINITIONS
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_COMMON_DATA )
/** Pointer to shared ROM constants */
typedef V_MEMROM1_FAR void V_MEMROM2_FAR V_MEMROM3 * tFblCommonDataPtr;
#endif /* FBL_ENABLE_COMMON_DATA */

/** Pointer type to logical block table */
typedef V_MEMROM1_FAR tLogicalBlockTable V_MEMROM2_FAR V_MEMROM3 * tFblHeaderLogicalBlockTablePtr;
/** Pointer type to BM header structure */
typedef V_MEMROM1_FAR tFblBmHdrHeader V_MEMROM2_FAR V_MEMROM3 * tFblHeaderBmHeaderPtr;

/** FBL header structure */
typedef struct
{
   vuint32 magicFlag;
   tFblHeaderLogicalBlockTablePtr pLogicalBlockTable;
   tFblLength logicalBlockTableSize;
#if defined( FBL_ENABLE_COMMON_DATA )
   tFblCommonDataPtr pFblCommonData;   /**< Common data structure - OEM dependent */
#endif /* FBL_ENABLE_COMMON_DATA */
   tFblAddress fblStartAddress;
   tFblLength fblLength;
   tFblHeaderBmHeaderPtr bmHeader;
} tFblHeader;

#endif /* FBL_MAIN_TYPES_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_MAIN_TYPES.H
 **********************************************************************************************************************/

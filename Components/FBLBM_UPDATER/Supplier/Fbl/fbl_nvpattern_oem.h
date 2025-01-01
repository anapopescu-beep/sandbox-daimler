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
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  TEMPLATE REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2017-02-24  visci   -                Initial version
 *  01.01.00   2018-06-15  visci   ESCAN00099699    No changes
 *  01.02.00   2018-09-24  visrr   ESCAN00100837    No changes
 *  01.03.00   2018-12-07  visshs  ESCAN00101559    No changes
 *  01.04.00   2019-01-25  viskjs  ESCAN00101824    Added patterns that can be validated multiple times
 *                                 ESCAN00101823    Added feature to store arbitrary values at end of logical block
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
 *  01.05.00   2021-06-16  visrie  FBL-3641         Support OTA use case and user extension
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  10.00.00   2020-10-14  viscb   FBL-2177         DRECU2020-01 adaptions, input verification and encrypted download
 *  10.01.00   2021-01-19  viscb   FBL-2244         DRECU2020-01 adaptions, added support for OTA
 *  10.01.01   2021-02-02  viscb   ESCAN00108445    QM release
 *  10.01.02   2021-04-21  viscb   ESCAN00108537    No changes
 *                                 ESCAN00108093    No changes
 *                                 ESCAN00108139    No changes
 *                                 FBL-3360         Added/adapted MemMap sections
 *  10.01.03   2021-05-28  viscb   ESCAN00109398    No changes
 *                                 ESCAN00109400    No changes
 *  10.01.04   2021-06.07  viscb   ESCAN00109435    No changes
 *                                 ESCAN00109437    No changes
 *  10.02.00   2021-07-09  vishor  FBL-3567         Updated to latest template revision
 *                                 ESCAN00107081    No changes
 *  10.02.01   2021-08-26  visjdn  ESCAN00109069    No changes
 *  10.02.02   2021-10-27  visrie  ESCAN00109153    No changes
 *  10.03.00   2022-03-15  vishor  FBL-4621         No changes
 *                                 ESCAN00110728    No changes
 *                                 ESCAN00110898    No changes
 *                                 ESCAN00110960    No changes
 *                                 ESCAN00111146    No changes
 *                                 ESCAN00111396    No changes
 *  10.04.00   2022-06-01  vishor  FBL-5094         No changes
 *                                 ESCAN00110486    No changes
 *  10.04.01   2022-06-27  vismix  ESCAN00112173    No changes
 *                                 ESCAN00112160    No changes
 *  10.04.02   2022-08-26  vismix  FBL-5754         No changes
 *                                 ESCAN00112447    No changes
 *                                 ESCAN00112459    No changes
 *  10.04.03   2023-01-09  vismix  ESCAN00112744    No changes
 *                                 ESCAN00113013    No changes
 *                                 ESCAN00113078    No changes
 **********************************************************************************************************************/

#ifndef FBLLIB_NVPATTERN_OEM_H
#define FBLLIB_NVPATTERN_OEM_H

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_OTA )
/* Default settings for OTA configuration */

# if !defined ( FBL_NVPATTERN_ACTIVATION_PENDING_NUM )
#  define FBL_NVPATTERN_ACTIVATION_PENDING_NUM 1u
# endif /* !FBL_NVPATTERN_ACTIVATION_PENDING_NUM */

/* Check if multiple validation feature was explicitly enabled externally */
# if !defined( FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION )
/* Enables NvPatterns which can be validated multiple times after erasing a logical block */
#  if ( FBL_NVPATTERN_ACTIVATION_PENDING_NUM > 1u )
#   define FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION
#  else
#   define FBL_NVPATTERN_DISABLE_MULTIPLE_VALIDATION
#  endif /* FBL_NVPATTERN_ACTIVATION_PENDING_NUM > 1u */
# endif /* !FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION */

/* Enables storing arbitrary data at the end of logical blocks */
# define FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES

/* Size of module/partition revisions */
# define FBL_NVPATTERN_REVISION_SIZE              4u
#else
/* Check if multiple validation feature was explicitly enabled externally */
# if !defined( FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION )
/* Disables NvPatterns which can be validated multiple times after erasing a logical block */
#  define FBL_NVPATTERN_DISABLE_MULTIPLE_VALIDATION
# endif /* !FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION */

/* Check if block properties feature was explicitly enabled externally */
# if !defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
/* Disables storing arbitrary data at the end of logical blocks */
#  define FBL_NVPATTERN_DISABLE_BLOCK_PROPERTIES
# endif /* !FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */
#endif /* FBL_ENABLE_OTA */

/* Disable user patterns if they are not explicitly defined */
#if !defined( FBL_NVPATTERN_USER_PATTERN_ID )
# define FBL_NVPATTERN_USER_PATTERN_ID
#endif /* FBL_NVPATTERN_USER_PATTERN_ID */
#if !defined( FBL_NVPATTERN_USER_PATTERN_MULTIPLICITY )
# define FBL_NVPATTERN_USER_PATTERN_MULTIPLICITY
#endif /* FBL_NVPATTERN_USER_PATTERN_MULTIPLICITY */
#if !defined( FBL_NVPATTERN_USER_PROPERTY_ID )
# define FBL_NVPATTERN_USER_PROPERTY_ID
#endif /* FBL_NVPATTERN_USER_PROPERTY_ID */
#if !defined( FBL_NVPATTERN_USER_PROPERTY_ENTRY )
# define FBL_NVPATTERN_USER_PROPERTY_ENTRY
#endif /* FBL_NVPATTERN_USER_PROPERTY_ENTRY */

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/*
 *   This module is used to store NvPatterns and block properties at the end of logical blocks.
 *   Block properties are used to store arbitrary data of the length defined in fblNvPatternElementLength to memory.
 *   Block properties can be written once after erasure of the logical block.
 *   NvPatterns are used to store a boolean value (valid/invalid). They can be set to valid
 *   several times if the respective value in fblNvPatternMultiplicity is set to > 1.
 *
 *   MEMORY LAYOUT:
 *
 *   |--------------------------------| <-- UPPER END of pattern/property area (usually end of logical block)
 *   | kFblNvPatternId_First          | First NvPattern
 *   | ...                            |
 *   | kFblNvPatternId_Final          |
 *   | kFblNvPatternId_Separator      | <-- SEPARATOR between patterns and block properties (do NOT delete this entry)
 *   | kFblNvProperty_First           | First block property
 *   | ...                            |
 *   | kFblNvProperty_Final           |
 *   | kFblNvPatternId_Last           | <-- LOWER END of pattern/property area (do NOT delete this entry)
 *   | <Data of logical block>        |
 *
 *   Note: the actual pattern/block property size is determined by the page size.
 *         All data elements are aligned to multiples of the page size of the respective device!
 */

/* PRQA S 0724 TAG_FblNvPatternOem_0724 */ /* MD_FblNvPatternOem_0724_EnumValNotUnique */
/* Identifiers for patterns and block properties */
typedef enum
{
    kFblNvPatternId_Invalid = 0u /* do NOT change this entry */

   /* ModuleValidity (OTA) and BlockValidity (BM) uses the same value */
   ,kFblNvPatternId_ModuleValidity
   ,kFblNvPatternId_BlockValidity = kFblNvPatternId_ModuleValidity

   /* PartitionValidity (OTA) and ApplValidity (BM) uses the same value */
   ,kFblNvPatternId_PartitionValidity
   ,kFblNvPatternId_ApplValidity = kFblNvPatternId_PartitionValidity

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
   , kFblNvPatternId_ErasedState
#endif

#if defined( FBL_ENABLE_OTA )
   ,kFblNvPatternId_ActivationPending
#endif /* FBL_ENABLE_OTA */

   FBL_NVPATTERN_USER_PATTERN_ID

#if defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
   ,kFblNvPatternId_Separator /* do NOT delete this entry */
# if defined( FBL_ENABLE_OTA )
   ,kFblNvProperty_PartitionRev
   ,kFblNvProperty_ModuleRev
# endif /* FBL_ENABLE_OTA */
   FBL_NVPATTERN_USER_PROPERTY_ID
#endif /* FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */
   ,kFblNvPatternId_Last /* do NOT delete this entry */
} tFblNvPatternId;
/* PRQA L:TAG_FblNvPatternOem_0724 */

#if defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
typedef struct
{
   IO_SizeType length;
   tFblNvPatternId dependentPattern;
} tFblBlockProperty;
#endif /* FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLNVPATTERN_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined ( FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION )
/* PRQA S 3684 1 */ /* MD_FblNvPatternOem_3684 */
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 fblNvPatternMultiplicity[];
#endif /* FBL_NVPATTERN_ENABLE_MULTIPATTERNS */

#if defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
/* PRQA S 3684 1 */ /* MD_FblNvPatternOem_3684 */
V_MEMROM0 extern V_MEMROM1 tFblBlockProperty V_MEMROM2 fblNvBlockProperties[];
#endif /* FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */

#define FBLNVPATTERN_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FBLLIB_NVPATTERN_OEM_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_NVPATTERN_OEM.H
 **********************************************************************************************************************/

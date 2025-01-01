/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the HIS security module - CRC calculation
 *
 *  \description  Offers CRC calculation (CRC-16 / CRC-32 / CRC-64)
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
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#define SEC_CRC_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Security module configuration settings */
#include "Sec_Inc.h"

/* Global type definitions for security module */
#include "Sec_Types.h"

/* Security module interface */
#include "Sec.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* PRQA S 3453 TAG_SecCrc_3453_1 */ /* MD_CBD_19.7 */

/* Large lookup table in RAM */
/** Number of bits used to index entries */
#define CRC_SPEED_OPT_INDEX_BITS    8u
/** Mask for table indices */
#define CRC_SPEED_OPT_INDEX_MASK    0xFFu
/** Size of lookup table */
#define CRC_SPEED_OPT_TABLE_SIZE    256u

/* Small lookup table in ROM */
/** Number of bits used to index entries */
#define CRC_SIZE_OPT_INDEX_BITS    4u
/** Mask for table indices */
#define CRC_SIZE_OPT_INDEX_MASK    0x0Fu
/** Size of lookup table */
#define CRC_SIZE_OPT_TABLE_SIZE    16u

/* Allow override of CRC parameters by configuration (e.g. don't complement CRC value during finalization) */
#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
# if ( SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED )
#  define SEC_CRC_16_INDEX_BITS     CRC_SPEED_OPT_INDEX_BITS
#  define SEC_CRC_16_INDEX_MASK     CRC_SPEED_OPT_INDEX_MASK
#  define SEC_CRC_16_TABLE_SIZE     CRC_SPEED_OPT_TABLE_SIZE
# else /* SEC_CRC_16_OPT == SEC_CRC_SIZE_OPTIMIZED */
#  define SEC_CRC_16_INDEX_BITS     CRC_SIZE_OPT_INDEX_BITS
#  define SEC_CRC_16_INDEX_MASK     CRC_SIZE_OPT_INDEX_MASK
#  define SEC_CRC_16_TABLE_SIZE     CRC_SIZE_OPT_TABLE_SIZE
# endif

/** Value to indicate uninitialized RAM lookup table */
# define SEC_CRC_16_UNINIT_PATTERN  0xA5A5u
/** Magic value to indicate initialized RAM lookup table */
# define SEC_CRC_16_INIT_PATTERN    0xC2C7u
#endif /* SEC_ENABLE_CRC_TYPE_CRC16 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
# if ( SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED )
#  define SEC_CRC_32_INDEX_BITS     CRC_SPEED_OPT_INDEX_BITS
#  define SEC_CRC_32_INDEX_MASK     CRC_SPEED_OPT_INDEX_MASK
#  define SEC_CRC_32_TABLE_SIZE     CRC_SPEED_OPT_TABLE_SIZE
# else /* SEC_CRC_32_OPT == SEC_CRC_SIZE_OPTIMIZED */
#  define SEC_CRC_32_INDEX_BITS     CRC_SIZE_OPT_INDEX_BITS
#  define SEC_CRC_32_INDEX_MASK     CRC_SIZE_OPT_INDEX_MASK
#  define SEC_CRC_32_TABLE_SIZE     CRC_SIZE_OPT_TABLE_SIZE
# endif

/** Value to indicate uninitialized RAM lookup table */
# define SEC_CRC_32_UNINIT_PATTERN  0xA5A5A5A5uL
/** Magic value to indicate initialized RAM lookup table */
# define SEC_CRC_32_INIT_PATTERN    0xC2C3274BuL
#endif /* SEC_ENABLE_CRC_TYPE_CRC32 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
# if ( SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED )
#  define SEC_CRC_64_INDEX_BITS     CRC_SPEED_OPT_INDEX_BITS
#  define SEC_CRC_64_INDEX_MASK     CRC_SPEED_OPT_INDEX_MASK
#  define SEC_CRC_64_TABLE_SIZE     CRC_SPEED_OPT_TABLE_SIZE
# else /* SEC_CRC_64_OPT == SEC_CRC_SIZE_OPTIMIZED */
#  define SEC_CRC_64_INDEX_BITS     CRC_SIZE_OPT_INDEX_BITS
#  define SEC_CRC_64_INDEX_MASK     CRC_SIZE_OPT_INDEX_MASK
#  define SEC_CRC_64_TABLE_SIZE     CRC_SIZE_OPT_TABLE_SIZE
# endif

/** Value to indicate uninitialized RAM lookup table */
# define SEC_CRC_64_UNINIT_PATTERN  { 0xA5A5A5A5uL, 0xA5A5A5A5uL }
/** Magic value to indicate initialized RAM lookup table */
# define SEC_CRC_64_INIT_PATTERN    { 0xC2C6474BuL, 0xC2C6474BuL }
#endif /* SEC_ENABLE_CRC_TYPE_CRC64 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
# if ( SEC_CRC_16_OPT == SEC_CRC_SIZE_OPTIMIZED )
/* Macros for compile-time generation of small lookup table in ROM */
#  if ( SEC_CRC_16_MODE == SEC_CRC_MODE_NON_REFLECTED )
/** Update CRC-16 value according to next input bit */
#   define CRC_16_BIT(in)        (((((in) & 0x7FFFu) << 1u) ^ ((((in) >> 15u) & 0x01u) * SEC_CRC_16_POLYNOMIAL)) & 0xFFFFu)
/** Calculate CRC-16 table entry for given input index */
#   define CRC_16_CALC(in)       CRC_16_NIBBLE(((in) & 0x0Fu) << 12u)
#  else /* SEC_CRC_16_MODE == SEC_CRC_MODE_REFLECTED */
/** Update CRC-16 value according to next input bit */
#   define CRC_16_BIT(in)        ((((in) >> 1u) ^ (((in) & 0x01u) * SEC_CRC_16_POLYNOMIAL)) & 0xFFFFu)
/** Calculate CRC-16 table entry for given input index */
#   define CRC_16_CALC(in)       CRC_16_NIBBLE((in))
#  endif /* SEC_CRC_16_MODE */

/** Calculate entry for CRC-16 calculation table based on 4-bit algorithm */
#  define CRC_16_NIBBLE(in)      (CRC_16_BIT(CRC_16_BIT(CRC_16_BIT(CRC_16_BIT(in)))))

/** Calculate 4 entries CRC-16 of calculation table */
#  define CRC_16_ENTRIES_4(i)    \
   CRC_16_CALC((i)),             \
   CRC_16_CALC((i) + 1u),        \
   CRC_16_CALC((i) + 2u),        \
   CRC_16_CALC((i) + 3u)

/** Calculate 16 entries CRC-16 of calculation table */
#  define CRC_16_ENTRIES_16(i)   \
   CRC_16_ENTRIES_4((i)),        \
   CRC_16_ENTRIES_4((i) + 4u),   \
   CRC_16_ENTRIES_4((i) + 8u),   \
   CRC_16_ENTRIES_4((i) + 12u)
# endif /* SEC_CRC_16_OPT == SEC_CRC_SIZE_OPTIMIZED */
#endif /* SEC_ENABLE_CRC_TYPE_CRC16 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
# if ( SEC_CRC_32_OPT == SEC_CRC_SIZE_OPTIMIZED )
/* Macros for compile-time generation of small lookup table in ROM */
#  if ( SEC_CRC_32_MODE == SEC_CRC_MODE_NON_REFLECTED )
/** Update CRC-32 value according to next input bit */
#   define CRC_32_BIT(in)        ((((in) & 0x7FFFFFFFuL) << 1u) ^ ((((in) >> 31u) & 0x01u) * SEC_CRC_32_POLYNOMIAL))
/** Calculate CRC-32 table entry for given input index */
#   define CRC_32_CALC(in)       CRC_32_NIBBLE(((in) & 0x0Fu) << 28u)
#  else /* SEC_CRC_32_MODE == SEC_CRC_MODE_REFLECTED */
/** Update CRC-32 value according to next input bit */
#   define CRC_32_BIT(in)        (((in) >> 1u) ^ (((in) & 0x01u) * SEC_CRC_32_POLYNOMIAL))
/** Calculate CRC-32 table entry for given input index */
#   define CRC_32_CALC(in)       CRC_32_NIBBLE((in))
#  endif /* SEC_CRC_32_MODE */

/** Calculate entry for CRC-32 calculation table based on 4-bit algorithm */
#  define CRC_32_NIBBLE(in)      (CRC_32_BIT(CRC_32_BIT(CRC_32_BIT(CRC_32_BIT(in)))))

/** Calculate 4 entries of CRC-32 calculation table */
#  define CRC_32_ENTRIES_4(i)    \
   CRC_32_CALC((i)),             \
   CRC_32_CALC((i) + 1u),        \
   CRC_32_CALC((i) + 2u),        \
   CRC_32_CALC((i) + 3u)

/** Calculate 16 entries of CRC-32 calculation table */
#  define CRC_32_ENTRIES_16(i)   \
   CRC_32_ENTRIES_4((i)),        \
   CRC_32_ENTRIES_4((i) + 4u),   \
   CRC_32_ENTRIES_4((i) + 8u),   \
   CRC_32_ENTRIES_4((i) + 12u)
# endif /* SEC_CRC_32_OPT == SEC_CRC_SIZE_OPTIMIZED */
#endif /* SEC_ENABLE_CRC_TYPE_CRC32 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
# if ( SEC_CRC_64_OPT == SEC_CRC_SIZE_OPTIMIZED )
/* Macros for compile-time generation of small lookup table in ROM */
#  if ( SEC_CRC_64_MODE == SEC_CRC_MODE_NON_REFLECTED )
/** Update CRC-64 value according to next input bit */
#   define CRC_64_BIT__(h, l)    (((((h) & 0x7FFFFFFFuL) << 1u) | (((l) >> 31u) & 0x01u)) ^ ((((h) >> 31u) & 0x01u) * SEC_CRC_64_POLYNOMIAL_HIGH)), \
                                 ((((l) & 0x7FFFFFFFuL) << 1u) ^ ((((h) >> 31u) & 0x01u) * SEC_CRC_64_POLYNOMIAL_LOW))
/** Calculate CRC-64 table entry for given input index */
#   define CRC_64_CALC(in)       { CRC_64_NIBBLE((in) << 28u, 0x00u) }
#  else /* SEC_CRC_64_MODE == SEC_CRC_MODE_REFLECTED */
/** Update CRC-64 value according to next input bit */
#   define CRC_64_BIT__(h, l)    (((SecM_Crc64BaseType)(h) >> 1u) ^ (((SecM_Crc64BaseType)(l) & 0x01u) * SEC_CRC_64_POLYNOMIAL_HIGH)), \
                                 ((((SecM_Crc64BaseType)(l) >> 1u) | ((((SecM_Crc64BaseType)h) & 0x01u) << 31u)) ^ (((SecM_Crc64BaseType)(l) & 0x01u) * SEC_CRC_64_POLYNOMIAL_LOW))
/** Calculate CRC-64 table entry for given input index */
#   define CRC_64_CALC(in)       { CRC_64_NIBBLE(0x00u, (in)) }
#  endif /* SEC_CRC_64_MODE */

/** Helper macro to expand comma separated list */
#  define CRC_64_BIT_(p)         CRC_64_BIT__ p    /* PRQA S 3410 */ /* MD_SecCrc_3410 */
/** Helper macro to expand comma separated list */
#  define CRC_64_BIT(p)          CRC_64_BIT_((p))
/** Calculate entry for CRC-64 calculation table based on 4-bit algorithm */
#  define CRC_64_NIBBLE(h, l)    CRC_64_BIT(CRC_64_BIT(CRC_64_BIT(CRC_64_BIT__((h), (l)))))

/** Calculate 4 entries of CRC-64 calculation table */
#  define CRC_64_ENTRIES_4(i)    \
   CRC_64_CALC((i)),             \
   CRC_64_CALC((i) + 1u),        \
   CRC_64_CALC((i) + 2u),        \
   CRC_64_CALC((i) + 3u)

/** Calculate 16 entries of CRC-64 calculation table */
#  define CRC_64_ENTRIES_16(i)   \
   CRC_64_ENTRIES_4((i)),        \
   CRC_64_ENTRIES_4((i) + 4u),   \
   CRC_64_ENTRIES_4((i) + 8u),   \
   CRC_64_ENTRIES_4((i) + 12u)
# endif /* SEC_CRC_64_OPT == SEC_CRC_SIZE_OPTIMIZED */
#endif /* SEC_ENABLE_CRC_TYPE_CRC64 */

/* PRQA L:TAG_SecCrc_3453_1 */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
# if ( SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED )
static void SecM_GenerateLookupCrc16(FL_WDTriggerFctType pWatchdog);
# endif /* SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED */
#endif /* SEC_ENABLE_CRC_TYPE_CRC16 */
#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
# if ( SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED )
static void SecM_GenerateLookupCrc32(FL_WDTriggerFctType pWatchdog);
# endif /* SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED */
#endif /* SEC_ENABLE_CRC_TYPE_CRC32 */
#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
# if ( SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED )
static void SecM_GenerateLookupCrc64(FL_WDTriggerFctType pWatchdog);
# endif /* SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED */
#endif /* SEC_ENABLE_CRC_TYPE_CRC64 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
static void SecM_UpdateCrc16(V_MEMRAM1 SecM_CRC16ParamType V_MEMRAM2 V_MEMRAM2 * pCrcParam);
#endif /* SEC_ENABLE_CRC_TYPE_CRC16 */
#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
static void SecM_UpdateCrc32(V_MEMRAM1 SecM_CRC32ParamType V_MEMRAM2 V_MEMRAM2 * pCrcParam);
#endif /* SEC_ENABLE_CRC_TYPE_CRC32 */
#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
static void SecM_UpdateCrc64(V_MEMRAM1 SecM_CRC64ParamType V_MEMRAM2 V_MEMRAM2 * pCrcParam);
#endif /* SEC_ENABLE_CRC_TYPE_CRC64 */

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/* PRQA S 3218 TAG_SecCrc_3218_1 */ /* MD_SecCrc_3218 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
# if ( SEC_CRC_16_OPT == SEC_CRC_SIZE_OPTIMIZED )
#  define SECM_START_SEC_CONST
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/** CRC-16 calculation table based on 4-bit algorithm */
V_MEMROM0 static V_MEMROM1 SecM_Crc16Type V_MEMROM2 lookupCrc16[SEC_CRC_16_TABLE_SIZE] =
{
   CRC_16_ENTRIES_16(0x00u)
};
#  define SECM_STOP_SEC_CONST
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
# else /* SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED */
#  define SECM_START_SEC_VAR
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/** CRC-16 calculation table based on 8-bit algorithm */
V_MEMRAM0 static V_MEMRAM1 SecM_Crc16Type V_MEMRAM2 lookupCrc16[SEC_CRC_16_TABLE_SIZE + 1u];
#  define SECM_STOP_SEC_VAR
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* SEC_CRC_16_OPT */
#endif /* SEC_ENABLE_CRC_TYPE_CRC16 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
# if ( SEC_CRC_32_OPT == SEC_CRC_SIZE_OPTIMIZED )
/** CRC-32 calculation table based on 4-bit algorithm */
#  define SECM_START_SEC_CONST
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMROM0 static V_MEMROM1 SecM_Crc32Type V_MEMROM2 lookupCrc32[SEC_CRC_32_TABLE_SIZE] =
{
   CRC_32_ENTRIES_16(0x00u)
};
#  define SECM_STOP_SEC_CONST
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
# else /* SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED */
/** CRC-32 calculation table based on 8-bit algorithm */
#  define SECM_START_SEC_VAR
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 static V_MEMRAM1 SecM_Crc32Type V_MEMRAM2 lookupCrc32[SEC_CRC_32_TABLE_SIZE + 1u];
#  define SECM_STOP_SEC_VAR
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* SEC_CRC_32_OPT */
#endif /* SEC_ENABLE_CRC_TYPE_CRC32 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
# if ( SEC_CRC_64_OPT == SEC_CRC_SIZE_OPTIMIZED )
/** CRC-64 calculation table based on 4-bit algorithm */
#  define SECM_START_SEC_CONST
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMROM0 static V_MEMROM1 SecM_Crc64Type V_MEMROM2 lookupCrc64[SEC_CRC_64_TABLE_SIZE] =
{
   CRC_64_ENTRIES_16(0x00u)
};
#  define SECM_STOP_SEC_CONST
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
# else /* SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED */
/** CRC-64 calculation table based on 8-bit algorithm */
#  define SECM_START_SEC_VAR
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 static V_MEMRAM1 SecM_Crc64Type V_MEMRAM2 lookupCrc64[SEC_CRC_64_TABLE_SIZE + 1u];
#  define SECM_STOP_SEC_VAR
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/** Polynomial used for CRC-64 */
#  define SECM_START_SEC_CONST
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMROM0 static V_MEMROM1 SecM_Crc64Type V_MEMROM2 polynomialCrc64 = SEC_CRC_64_POLYNOMIAL;
/** Value to indicate uninitialized RAM lookup table */
V_MEMROM0 static V_MEMROM1 SecM_Crc64Type V_MEMROM2 uninitPatternCrc64 = SEC_CRC_64_UNINIT_PATTERN;
/** Magic value to indicate initialized RAM lookup table */
V_MEMROM0 static V_MEMROM1 SecM_Crc64Type V_MEMROM2 initPatternCrc64 = SEC_CRC_64_INIT_PATTERN;
#  define SECM_STOP_SEC_CONST
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* SEC_CRC_64_OPT */
#endif /* SEC_ENABLE_CRC_TYPE_CRC64 */

#define SECM_START_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
/** Initialization value for CRC */
V_MEMROM0 static V_MEMROM1 SecM_Crc16Type V_MEMROM2 initialValueCrc16 = SEC_CRC_16_INITIAL;
/** Finalization value for CRC */
V_MEMROM0 static V_MEMROM1 SecM_Crc16Type V_MEMROM2 finalValueCrc16 = SEC_CRC_16_FINAL;
#endif /* SEC_ENABLE_CRC_TYPE_CRC16 */
#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
/** Initialization value for CRC */
V_MEMROM0 static V_MEMROM1 SecM_Crc32Type V_MEMROM2 initialValueCrc32 = SEC_CRC_32_INITIAL;
/** Finalization value for CRC */
V_MEMROM0 static V_MEMROM1 SecM_Crc32Type V_MEMROM2 finalValueCrc32 = SEC_CRC_32_FINAL;
#endif /* SEC_ENABLE_CRC_TYPE_CRC32 */
#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
/** Initialization value for CRC */
V_MEMROM0 static V_MEMROM1 SecM_Crc64Type V_MEMROM2 initialValueCrc64 = SEC_CRC_64_INITIAL;
/** Finalization value for CRC */
V_MEMROM0 static V_MEMROM1 SecM_Crc64Type V_MEMROM2 finalValueCrc64 = SEC_CRC_64_FINAL;
#endif /* SEC_ENABLE_CRC_TYPE_CRC64 */
#define SECM_STOP_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA L:TAG_SecCrc_3218_1 */
/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define SECM_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if defined( SEC_ENABLE_SAVE_RESTORE_CRC )
V_MEMRAM0 V_MEMRAM1 SecM_CrcWorkspaceInfoType V_MEMRAM2 SecM_CrcWorkspaceInfo[SEC_CRC_WORKSPACE_SIZE];
#endif /* SEC_ENABLE_SAVE_RESTORE_CRC */

#define SECM_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
# if ( SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED )
/***********************************************************************************************************************
 *  SecM_GenerateLookupCrc16
 **********************************************************************************************************************/
/*! \brief       Generates the CRC-16 lookup table
 *  \param[in]   pWatchdog Pointer to watchdog trigger function
 **********************************************************************************************************************/
static void SecM_GenerateLookupCrc16( FL_WDTriggerFctType pWatchdog )
{
   /* Create CRC table in RAM */
   SecM_ShortFastType   tableIndex;
   SecM_ByteFastType    bitIndex;
   SecM_Crc16Type       crc;

   /* Fill lookup table */
   for (tableIndex = 0u; tableIndex < SEC_CRC_16_TABLE_SIZE; tableIndex++)
   {
      /* Serve watchdog (every n-th cycle) */
      SEC_WATCHDOG_CYCLE_TRIGGER(pWatchdog, tableIndex); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* Start value equals part of table index */
#  if ( SEC_CRC_16_MODE == SEC_CRC_MODE_NON_REFLECTED )
      /* Non-reflected algorithm */
      crc = (SecM_Crc16Type)(tableIndex << (16u - SEC_CRC_16_INDEX_BITS));
#  else /* SEC_CRC_16_MODE == SEC_CRC_MODE_REFLECTED */
      /* Reflected algorithm */
      crc = tableIndex;
#  endif /* SEC_CRC_16_MODE */

      /* Iterate all index bits */
      for (bitIndex = 0u; bitIndex < SEC_CRC_16_INDEX_BITS; bitIndex++)
      {
#  if ( SEC_CRC_16_MODE == SEC_CRC_MODE_NON_REFLECTED )
         /* Non-reflected algorithm takes most significant bit */
         if ((crc & ((SecM_Crc16Type)0x01u << 15u)) != 0x00u)
         {
            crc <<= 1u;
            crc ^= SEC_CRC_16_POLYNOMIAL; /* PRQA S 2985 */ /* MD_SecCrc_2985_RedundantOp */
         }
         else
         {
            crc <<= 1u;
         }
#  else /* SEC_CRC_16_MODE == SEC_CRC_MODE_REFLECTED */
         /* Reflected algorithm takes least significant bit */
         if ((crc & 0x01u) != 0x00u)
         {
            crc >>= 1u;
            crc ^= SEC_CRC_16_POLYNOMIAL; /* PRQA S 2985 */ /* MD_SecCrc_2985_RedundantOp */
         }
         else
         {
            crc >>= 1u;
         }
#  endif /* SEC_CRC_16_MODE */
      }

      /* Store calculated lookup value */
      lookupCrc16[tableIndex] = crc;
   }

   /* Mark table as initialized by setting magic value */
   lookupCrc16[SEC_CRC_16_TABLE_SIZE] = SEC_CRC_16_INIT_PATTERN;
}
# endif /* SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED */
#endif /* SEC_ENABLE_CRC_TYPE_CRC16 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
# if ( SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED )
/***********************************************************************************************************************
 *  SecM_GenerateLookupCrc32
 **********************************************************************************************************************/
/*! \brief       Generates the CRC-32 lookup table
 *  \param[in]   pWatchdog Pointer to watchdog trigger function
 **********************************************************************************************************************/
static void SecM_GenerateLookupCrc32( FL_WDTriggerFctType pWatchdog )
{
   /* Create CRC table in RAM */
   SecM_ShortFastType   tableIndex;
   SecM_ByteFastType    bitIndex;
   SecM_Crc32Type       crc;

   /* Fill lookup table */
   for (tableIndex = 0u; tableIndex < SEC_CRC_32_TABLE_SIZE; tableIndex++)
   {
      /* Serve watchdog (every n-th cycle) */
      SEC_WATCHDOG_CYCLE_TRIGGER(pWatchdog, tableIndex); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* Start value equals part of table index */
#  if ( SEC_CRC_32_MODE == SEC_CRC_MODE_NON_REFLECTED )
      /* Non-reflected algorithm */
      crc = (SecM_Crc32Type)tableIndex << (32u - SEC_CRC_32_INDEX_BITS);
#  else /* SEC_CRC_32_MODE == SEC_CRC_MODE_REFLECTED */
      /* Reflected algorithm */
      crc = tableIndex;
#  endif /* SEC_CRC_32_MODE */

      /* Iterate all index bits */
      for (bitIndex = 0u; bitIndex < SEC_CRC_32_INDEX_BITS; bitIndex++)
      {
#  if ( SEC_CRC_32_MODE == SEC_CRC_MODE_NON_REFLECTED )
         /* Non-reflected algorithm takes most significant bit */
         if ((crc & ((SecM_Crc32Type)0x01u << 31u)) != 0x00u)
         {
            crc <<= 1u;
            crc ^= SEC_CRC_32_POLYNOMIAL; /* PRQA S 2985 */ /* MD_SecCrc_2985_RedundantOp */
         }
         else
         {
            crc <<= 1u;
         }
#  else /* SEC_CRC_32_MODE == SEC_CRC_MODE_REFLECTED */
         /* Reflected algorithm takes least significant bit */
         if ((crc & 0x01u) != 0x00u)
         {
            crc >>= 1u;
            crc ^= SEC_CRC_32_POLYNOMIAL; /* PRQA S 2985 */ /* MD_SecCrc_2985_RedundantOp */
         }
         else
         {
            crc >>= 1u;
         }
#  endif /* SEC_CRC_32_MODE */
      }

      /* Store calculated lookup value */
      lookupCrc32[tableIndex] = crc;
   }

   /* Mark table as initialized by setting magic value */
   lookupCrc32[SEC_CRC_32_TABLE_SIZE] = SEC_CRC_32_INIT_PATTERN;
}
# endif /* SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED */
#endif /* SEC_ENABLE_CRC_TYPE_CRC32 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
# if ( SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED )
/***********************************************************************************************************************
 *  SecM_GenerateLookupCrc64
 **********************************************************************************************************************/
/*! \brief       Generates the CRC-64 lookup table
 *  \param[in]   pWatchdog Pointer to watchdog trigger function
 **********************************************************************************************************************/
static void SecM_GenerateLookupCrc64( FL_WDTriggerFctType pWatchdog )
{
   /* Create CRC table in RAM -> reflected */
   SecM_ShortFastType   tableIndex;
   SecM_ByteFastType    bitIndex;
   SecM_Crc64Type       crc;

   /* Fill lookup table */
   for (tableIndex = 0u; tableIndex < SEC_CRC_64_TABLE_SIZE; tableIndex++)
   {
      /* Serve watchdog (every n-th cycle) */
      SEC_WATCHDOG_CYCLE_TRIGGER(pWatchdog, tableIndex); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* Start value equals part of table index */
#  if ( SEC_CRC_64_MODE == SEC_CRC_MODE_NON_REFLECTED )
      /* Non-reflected algorithm */
      crc.highWord = tableIndex << (32u - SEC_CRC_64_INDEX_BITS);
      crc.lowWord  = 0u;
#  else /* SEC_CRC_64_MODE == SEC_CRC_MODE_REFLECTED */
      /* Reflected algorithm */
      crc.highWord = 0u;
      crc.lowWord  = tableIndex;
#  endif /* SEC_CRC_64_MODE */

      /* Iterate all index bits */
      for (bitIndex = 0u; bitIndex < SEC_CRC_64_INDEX_BITS; bitIndex++)
      {
#  if ( SEC_CRC_64_MODE == SEC_CRC_MODE_NON_REFLECTED )
         /* Non-reflected algorithm takes most significant bit */
         if ((crc.highWord & (0x01u << 31u)) != 0x00u)
         {
            crc.highWord <<= 1u;
            /* Highest bit of low word overflows into high word */
            crc.highWord |= (crc.lowWord >> 31u) & 0x01u;
            crc.highWord ^= polynomialCrc64.highWord; /* PRQA S 2985 */ /* MD_SecCrc_2985_RedundantOp */

            crc.lowWord <<= 1u;
            crc.lowWord ^= polynomialCrc64.lowWord; /* PRQA S 2985 */ /* MD_SecCrc_2985_RedundantOp */
         }
         else
         {
            crc.highWord <<= 1u;
            /* Highest bit of low word overflows into high word */
            crc.highWord |= (crc.lowWord >> 31u) & 0x01u;

            crc.lowWord <<= 1u;
         }
#  else /* SEC_CRC_64_MODE == SEC_CRC_MODE_REFLECTED */
         /* Reflected algorithm takes least significant bit */
         if ((crc.lowWord & 0x01u) != 0x00u)
         {
            crc.lowWord >>= 1u;
            /* Lowest bit of high word overflows into low word */
            crc.lowWord |= (crc.highWord & 0x01u);
            crc.lowWord ^= polynomialCrc64.lowWord; /* PRQA S 2985 */ /* MD_SecCrc_2985_RedundantOp */

            crc.highWord >>= 1u;
            crc.highWord ^= polynomialCrc64.highWord; /* PRQA S 2985 */ /* MD_SecCrc_2985_RedundantOp */
         }
         else
         {
            crc.lowWord  >>= 1u;
            /* Lowest bit of high word overflows into low word */
            crc.lowWord |= (crc.highWord & 0x01u);

            crc.highWord >>= 1u;
         }
#  endif /* SEC_CRC_64_MODE */
      }

      /* Store calculated lookup value */
      lookupCrc64[tableIndex] = crc;
   }

   /* Mark table as initialized by setting magic value */
   lookupCrc64[SEC_CRC_64_TABLE_SIZE] = initPatternCrc64;
}
# endif /* SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED */
#endif /* SEC_ENABLE_CRC_TYPE_CRC64 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
/***********************************************************************************************************************
 *  SecM_UpdateCrc16
 **********************************************************************************************************************/
/*! \brief       Computes the CRC-16 upon the given data buffer
 *  \param[in,out] crcParam Pointer to parameter structure
 **********************************************************************************************************************/
static void SecM_UpdateCrc16(V_MEMRAM1 SecM_CRC16ParamType V_MEMRAM2 V_MEMRAM2 * pCrcParam)
{
   SecM_ShortFastType      tableIndex;    /* Index for CRC table access */
   SecM_LengthFastType     sourceIndex;   /* Index for source data buffer */
   SecM_LengthFastType     byteCount;
   SecM_Crc16Type          tmpCrc;
   SecM_ByteType           currentData;
   FL_WDTriggerFctType     pWatchdog;

   /* Operate on local copy of CRC */
   tmpCrc      = (SecM_Crc16Type)pCrcParam->currentCRC;
   byteCount   = pCrcParam->crcByteCount;
   pWatchdog   = pCrcParam->wdTriggerFct;

   /* Loop all input bytes */
   for (sourceIndex = 0u; sourceIndex < byteCount; sourceIndex++)
   {
      /* Serve watchdog (every n-th cycle) */
      SEC_WATCHDOG_CYCLE_TRIGGER(pWatchdog, sourceIndex); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* Read current data byte */
      currentData = pCrcParam->crcSourceBuffer[sourceIndex];

# if ( SEC_CRC_16_MODE == SEC_CRC_MODE_NON_REFLECTED )
#  if (SEC_CRC_16_OPT == SEC_CRC_SIZE_OPTIMIZED)
      /* Calculate CRC with small table in ROM */
      /* Calculate high-nibble first */ /* PRQA S 2985, 4391 2 */ /* MD_SecCrc_2985_4391 */
      tableIndex = (SecM_ShortFastType)((((SecM_Crc16Type)currentData >> (8u - SEC_CRC_16_INDEX_BITS)) ^ (tmpCrc >> (16u - SEC_CRC_16_INDEX_BITS))) & SEC_CRC_16_INDEX_MASK);
      tmpCrc = (SecM_Crc16Type)((tmpCrc << SEC_CRC_16_INDEX_BITS) ^ lookupCrc16[tableIndex]);
#  endif /* SEC_CRC_16_OPT */

      /* PRQA S 2985, 4391 2 */ /* MD_SecCrc_2985_4391 */
      tableIndex = (SecM_ShortFastType)(((SecM_Crc16Type)currentData ^ (tmpCrc >> (SecM_Crc16Type)(16u - SEC_CRC_16_INDEX_BITS))) & SEC_CRC_16_INDEX_MASK);
      tmpCrc = (SecM_Crc16Type)((tmpCrc << SEC_CRC_16_INDEX_BITS) ^ lookupCrc16[tableIndex]);
# else /* SEC_CRC_16_MODE == SEC_CRC_MODE_REFLECTED */
      /* Reflected */ /* PRQA S 2985, 4391 2 */ /* MD_SecCrc_2985_4391 */
      tableIndex = (SecM_ShortFastType)(((SecM_Crc16Type)currentData ^ tmpCrc) & SEC_CRC_16_INDEX_MASK);
      tmpCrc = (SecM_Crc16Type)((tmpCrc >> SEC_CRC_16_INDEX_BITS) ^ lookupCrc16[tableIndex]);

#  if ( SEC_CRC_16_OPT == SEC_CRC_SIZE_OPTIMIZED )
      /* Calculate CRC with small table in ROM */
      /* Calculate low-nibble */ /* PRQA S 2985, 4391 2 */ /* MD_SecCrc_2985_4391 */
      tableIndex = (SecM_ShortFastType)((((SecM_Crc16Type)currentData >> (8u - SEC_CRC_16_INDEX_BITS)) ^ tmpCrc) & SEC_CRC_16_INDEX_MASK);
      tmpCrc = (SecM_Crc16Type)((tmpCrc >> SEC_CRC_16_INDEX_BITS) ^ lookupCrc16[tableIndex]);
#  endif /* SEC_CRC_16_OPT */
# endif /* SEC_CRC_16_MODE */
   }

   /* Update external CRC value */
   pCrcParam->currentCRC = tmpCrc;
}
#endif /* SEC_ENABLE_CRC_TYPE_CRC16 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
/***********************************************************************************************************************
 *  SecM_UpdateCrc32
 **********************************************************************************************************************/
/*! \brief       Computes the CRC upon the given data buffer
 *  \param[in,out] crcParam Pointer to parameter structure
 **********************************************************************************************************************/
static void SecM_UpdateCrc32( V_MEMRAM1 SecM_CRC32ParamType V_MEMRAM2 V_MEMRAM2 * pCrcParam )
{
   SecM_ShortFastType      tableIndex;    /* Index for CRC table access */
   SecM_LengthFastType     sourceIndex;   /* Index for source data buffer */
   SecM_LengthFastType     byteCount;
   SecM_Crc32Type          tmpCrc;
   SecM_ByteType           currentData;
   FL_WDTriggerFctType     pWatchdog;

   /* Operate on local copy of CRC */
   tmpCrc      = (SecM_Crc32Type)pCrcParam->currentCRC;
   byteCount   = pCrcParam->crcByteCount;
   pWatchdog   = pCrcParam->wdTriggerFct;

   /* Loop all input bytes */
   for (sourceIndex = 0u; sourceIndex < byteCount; sourceIndex++)
   {
      /* Serve watchdog (every n-th cycle) */
      SEC_WATCHDOG_CYCLE_TRIGGER(pWatchdog, sourceIndex); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* Read current data byte */
      currentData = pCrcParam->crcSourceBuffer[sourceIndex];

# if ( SEC_CRC_32_MODE == SEC_CRC_MODE_NON_REFLECTED )
#  if (SEC_CRC_32_OPT == SEC_CRC_SIZE_OPTIMIZED)
      /* Calculate CRC with small table in ROM */
      /* Calculate high-nibble first */ /* PRQA S 2985, 4391 2 */ /* MD_SecCrc_2985_4391 */
      tableIndex  = (SecM_ShortFastType)((((SecM_Crc32Type)currentData >> (8u - SEC_CRC_32_INDEX_BITS)) ^ (tmpCrc >> (32u - SEC_CRC_32_INDEX_BITS))) & SEC_CRC_32_INDEX_MASK);
      tmpCrc      = (SecM_Crc32Type)((tmpCrc << SEC_CRC_32_INDEX_BITS) ^ lookupCrc32[tableIndex]);
#  endif /* SEC_CRC_32_OPT */
      /* PRQA S 2985, 4391 2 */ /* MD_SecCrc_2985_4391 */
      tableIndex  = (SecM_ShortFastType)(((SecM_Crc32Type)currentData ^ (tmpCrc >> (32u - SEC_CRC_32_INDEX_BITS))) & SEC_CRC_32_INDEX_MASK);
      tmpCrc      = (SecM_Crc32Type)((tmpCrc << SEC_CRC_32_INDEX_BITS) ^ lookupCrc32[tableIndex]);
# else /* SEC_CRC_32_MODE == SEC_CRC_MODE_REFLECTED */
      /* Reflected */ /* PRQA S 2985, 4391 2 */ /* MD_SecCrc_2985_4391 */
      tableIndex  = (SecM_ShortFastType)(((SecM_Crc32Type)currentData ^ tmpCrc) & SEC_CRC_32_INDEX_MASK);
      tmpCrc      = (SecM_Crc32Type)((tmpCrc >> SEC_CRC_32_INDEX_BITS) ^ lookupCrc32[tableIndex]);
#  if ( SEC_CRC_32_OPT == SEC_CRC_SIZE_OPTIMIZED )
      /* Calculate CRC with small table in ROM */
      /* Calculate low-nibble */ /* PRQA S 2985, 4391 2 */ /* MD_SecCrc_2985_4391 */
      tableIndex  = (SecM_ShortFastType)((((SecM_Crc32Type)currentData >> (8u - SEC_CRC_32_INDEX_BITS)) ^ tmpCrc) & SEC_CRC_32_INDEX_MASK);
      tmpCrc      = (SecM_Crc32Type)((tmpCrc >> SEC_CRC_32_INDEX_BITS) ^ lookupCrc32[tableIndex]);
#  endif /* SEC_CRC_32_OPT */
# endif /* SEC_CRC_32_MODE */
   }

   /* Update external CRC value */
   pCrcParam->currentCRC = tmpCrc;
}
#endif /* SEC_ENABLE_CRC_TYPE_CRC32 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
/***********************************************************************************************************************
 *  SecM_UpdateCrc64
 **********************************************************************************************************************/
/*! \brief       Computes the CRC upon the given data buffer
 *  \param[in,out] crcParam Pointer to parameter structure
 **********************************************************************************************************************/
static void SecM_UpdateCrc64(V_MEMRAM1 SecM_CRC64ParamType V_MEMRAM2 V_MEMRAM2 * pCrcParam)
{
   SecM_ShortFastType      tableIndex;    /* Index for CRC table access */
   SecM_LengthFastType     sourceIndex;   /* Index for source data buffer */
   SecM_LengthFastType     byteCount;
   SecM_Crc64Type          tmpCrc;
   SecM_ByteType           currentData;
   FL_WDTriggerFctType     pWatchdog;

   /* Operate on local copy of CRC */
   tmpCrc      = pCrcParam->currentCRC;
   byteCount   = pCrcParam->crcByteCount;
   pWatchdog   = pCrcParam->wdTriggerFct;

   /* Loop all input bytes */
   for (sourceIndex = 0u; sourceIndex < byteCount; sourceIndex++)
   {
      /* Serve watchdog (every n-th cycle) */
      SEC_WATCHDOG_CYCLE_TRIGGER(pWatchdog, sourceIndex); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* Read current data byte */
      currentData = pCrcParam->crcSourceBuffer[sourceIndex];

# if ( SEC_CRC_64_MODE == SEC_CRC_MODE_NON_REFLECTED )
      /* Non-reflected */
#  if ( SEC_CRC_64_OPT == SEC_CRC_SIZE_OPTIMIZED )
      /* Calculate CRC with small table in ROM */
      /* Calculate high-nibble first */ /* PRQA S 2985, 4391 3 */ /* MD_SecCrc_2985_4391 */
      tableIndex = (SecM_ShortFastType)((((SecM_Crc64BaseType)currentData >> (8u - SEC_CRC_64_INDEX_BITS)) ^ (tmpCrc.highWord >> (32u - SEC_CRC_64_INDEX_BITS))) & SEC_CRC_64_INDEX_MASK);
      tmpCrc.highWord = (SecM_Crc64BaseType)(((tmpCrc.highWord << SEC_CRC_64_INDEX_BITS) | (tmpCrc.lowWord >> (32u - SEC_CRC_64_INDEX_BITS))) ^ lookupCrc64[tableIndex].highWord);
      tmpCrc.lowWord = (SecM_Crc64BaseType)((tmpCrc.lowWord << SEC_CRC_64_INDEX_BITS) ^ lookupCrc64[tableIndex].lowWord);
#  endif /* SEC_CRC_64_OPT */

       /* PRQA S 2985, 4391 3 */ /* MD_SecCrc_2985_4391 */
      tableIndex = (SecM_ShortFastType)(((SecM_Crc64BaseType)currentData ^ (tmpCrc.highWord >> (32u - SEC_CRC_64_INDEX_BITS))) & SEC_CRC_64_INDEX_MASK);
      tmpCrc.highWord = (SecM_Crc64BaseType)((((tmpCrc.highWord) << SEC_CRC_64_INDEX_BITS) | (tmpCrc.lowWord >> (32u - SEC_CRC_64_INDEX_BITS))) ^ lookupCrc64[tableIndex].highWord);
      tmpCrc.lowWord = (SecM_Crc64BaseType)(((tmpCrc.lowWord) << SEC_CRC_64_INDEX_BITS) ^ lookupCrc64[tableIndex].lowWord);
# else /* SEC_CRC_64_MODE == SEC_CRC_MODE_REFLECTED */
      /* Reflected */ /* PRQA S 2985, 4391 4 */ /* MD_SecCrc_2985_4391 */
      tableIndex = (SecM_ShortFastType)(((SecM_Crc64BaseType)currentData ^ tmpCrc.lowWord) & SEC_CRC_64_INDEX_MASK);
      /* Calculate CRC with large table in RAM */
      tmpCrc.lowWord = (SecM_Crc64BaseType)((((tmpCrc.highWord << (32u - SEC_CRC_64_INDEX_BITS))) | (tmpCrc.lowWord >> SEC_CRC_64_INDEX_BITS)) ^ lookupCrc64[tableIndex].lowWord);
      tmpCrc.highWord = (SecM_Crc64BaseType)((tmpCrc.highWord >> SEC_CRC_64_INDEX_BITS) ^ lookupCrc64[tableIndex].highWord);

#  if ( SEC_CRC_64_OPT == SEC_CRC_SIZE_OPTIMIZED )
      /* Calculate CRC with small table in ROM */
      /* Calculate low-nibble */ /* PRQA S 2985, 4391 3 */ /* MD_SecCrc_2985_4391 */
      tableIndex = (SecM_ShortFastType)((((SecM_Crc64BaseType)currentData >> (8u - SEC_CRC_64_INDEX_BITS)) ^ tmpCrc.lowWord) & SEC_CRC_64_INDEX_MASK);
      tmpCrc.lowWord = (SecM_Crc64BaseType)((((tmpCrc.highWord << (32u - SEC_CRC_64_INDEX_BITS))) | (tmpCrc.lowWord >> SEC_CRC_64_INDEX_BITS)) ^ lookupCrc64[tableIndex].lowWord);
      tmpCrc.highWord = (SecM_Crc64BaseType)((tmpCrc.highWord >> SEC_CRC_64_INDEX_BITS) ^ lookupCrc64[tableIndex].highWord);
#  endif /* SEC_CRC_64_OPT */
# endif /* SEC_CRC_64_MODE */
   }

   /* Update external CRC value */
   pCrcParam->currentCRC = tmpCrc;
}
#endif /* SEC_ENABLE_CRC_TYPE_CRC64 */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  SecM_InitPowerOnCRC
 **********************************************************************************************************************/
/*! \brief         Initialize CRC module
 **********************************************************************************************************************/
void SecM_InitPowerOnCRC( void )
{
#if defined( SEC_ENABLE_SAVE_RESTORE_CRC)
   SecM_ByteFastType i;

   for (i = 0u; i < SEC_CRC_WORKSPACE_SIZE; i++)
   {
      SecM_CrcWorkspaceInfo[i].state = CRC_WORKSPACE_UNDEF;
   }
#endif /* SEC_ENABLE_SAVE_RESTORE_CRC */

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
# if ( SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED )
   /* Mark lookup table as potentially uninitialized */
   lookupCrc16[SEC_CRC_16_TABLE_SIZE] = SEC_CRC_16_UNINIT_PATTERN;
# endif /* SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED */
#endif /* SEC_ENABLE_CRC_TYPE_CRC16 */
#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
# if ( SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED )
   lookupCrc32[SEC_CRC_32_TABLE_SIZE] = SEC_CRC_32_UNINIT_PATTERN;
# endif /* SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED */
#endif /* SEC_ENABLE_CRC_TYPE_CRC32 */
#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
# if ( SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED )
   lookupCrc64[SEC_CRC_64_TABLE_SIZE] = uninitPatternCrc64;
# endif /* SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED */
#endif /* SEC_ENABLE_CRC_TYPE_CRC64 */
}

#if defined( SEC_ENABLE_CRC )
/***********************************************************************************************************************
 *  SecM_ComputeCRC
 **********************************************************************************************************************/
/*! \brief       Function that manages the state of CRC computation
 *  \param[in,out] crcParam Pointer to parameter structure
 *  \return      SECM_OK if operation was successful
 *               SECM_NOT_OK
 **********************************************************************************************************************/
SecM_StatusType SecM_ComputeCRC( V_MEMRAM1 SecM_CRCParamType V_MEMRAM2 V_MEMRAM2 * crcParam )
{
# if ( SEC_CRC_TYPE == SEC_CRC16 )
   return SecM_ComputeCrc16(crcParam);
# elif ( SEC_CRC_TYPE == SEC_CRC32 )
   return SecM_ComputeCrc32(crcParam);
# elif ( SEC_CRC_TYPE == SEC_CRC64 )
   return SecM_ComputeCrc64(crcParam);
# else
   return SECM_NOT_OK;
# endif /* SEC_CRC_TYPE */
}
#endif /* SEC_ENABLE_CRC */

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
/***********************************************************************************************************************
 *  SecM_ComputeCrc16
 **********************************************************************************************************************/
/*! \brief       Function that manages the state of CRC-16 computation
 *  \param[in,out] crcParam Pointer to parameter structure
 *  \return      SECM_OK if operation was successful
 *               SECM_NOT_OK
 **********************************************************************************************************************/
SecM_StatusType SecM_ComputeCrc16(V_MEMRAM1 SecM_CRC16ParamType V_MEMRAM2 V_MEMRAM3 * crcParam)
{
   SecM_StatusType result;
   SecM_Crc16Type  crcTransferred;

   result = SECM_NOT_OK;

   switch (crcParam->crcState)
   {
      case SEC_CRC_INIT:
      {
# if ( SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED )
         /* Check magic value to verify whether lookup table was already initialized */
         if (SEC_CRC_16_INIT_PATTERN != lookupCrc16[SEC_CRC_16_TABLE_SIZE])
         {
            /* Initialize lookup table in RAM */
            SecM_GenerateLookupCrc16(crcParam->wdTriggerFct);
         }
# endif /* SEC_CRC_16_OPT == SEC_CRC_SPEED_OPTIMIZED */

         /* Set initial CRC value */ /* PRQA S 2985 1 */ /* MD_SecCrc_2985_RedundantOp */
         crcParam->currentCRC = initialValueCrc16;

         result = SECM_OK;

         break;
      }
      case SEC_CRC_COMPUTE:
      {
         /* Update CRC using provided data */
         SecM_UpdateCrc16(crcParam);

         result = SECM_OK;

         break;
      }
      case SEC_CRC_FINALIZE:
      {
         /* Complement CRC value */ /* PRQA S 2985 1 */ /* MD_SecCrc_2985_RedundantOp */
         crcParam->currentCRC ^= finalValueCrc16;

         result = SECM_OK;

         break;
      }
      case SEC_CRC_VERIFY:
      {
         if (crcParam->crcByteCount == SEC_SIZE_CHECKSUM_CRC_16)
         {
            /* Convert byte array to big-endian CRC value */
            crcTransferred = (SecM_Crc16Type)SecM_GetInteger(SEC_SIZE_CHECKSUM_CRC_16, crcParam->crcSourceBuffer);

            /* Compare given CRC against calculated one */
            if (crcTransferred == crcParam->currentCRC)
            {
               /* CRC match */
               result = SECM_VER_OK;
            }
            else
            {
               /* CRC mismatch */
               result = SECM_VER_CRC;
            }
         }

         break;
      }
      case SEC_CRC_GET:
      {
         if (crcParam->crcByteCount >= SEC_SIZE_CHECKSUM_CRC_16)
         {
            SecM_SetInteger(SEC_SIZE_CHECKSUM_CRC_16, crcParam->currentCRC, crcParam->crcOutputBuffer);
            /* Overwrite with actual CRC size */
            crcParam->crcByteCount = SEC_SIZE_CHECKSUM_CRC_16;

            result = SECM_OK;
         }

         break;
      }
      default:
      {
         /* Unknown state - result already set */
         break;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_CRC_TYPE_CRC16 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
/***********************************************************************************************************************
 *  SecM_ComputeCrc32
 **********************************************************************************************************************/
/*! \brief       Function that manages the state of CRC-32 computation
 *  \param[in,out] crcParam Pointer to parameter structure
 *  \return      SECM_OK if operation was successful
 *               SECM_NOT_OK
 **********************************************************************************************************************/
SecM_StatusType SecM_ComputeCrc32( V_MEMRAM1 SecM_CRC32ParamType V_MEMRAM2 V_MEMRAM3 * crcParam )
{
   SecM_StatusType result;
   SecM_Crc32Type  crcTransferred;

   result = SECM_NOT_OK;

   switch (crcParam->crcState)
   {
      case SEC_CRC_INIT:
      {
# if ( SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED )
         /* Check magic value to verify whether lookup table was already initialized */
         if (SEC_CRC_32_INIT_PATTERN != lookupCrc32[SEC_CRC_32_TABLE_SIZE])
         {
            /* Initialize lookup table in RAM */
            SecM_GenerateLookupCrc32(crcParam->wdTriggerFct);
         }
# endif /* SEC_CRC_32_OPT == SEC_CRC_SPEED_OPTIMIZED */

         /* Set initial CRC value */ /* PRQA S 2985 1 */ /* MD_SecCrc_2985_RedundantOp */
         crcParam->currentCRC = initialValueCrc32;

         result = SECM_OK;

         break;
      }
      case SEC_CRC_COMPUTE:
      {
         /* Update CRC using provided data */
         SecM_UpdateCrc32(crcParam);

         result = SECM_OK;

         break;
      }
      case SEC_CRC_FINALIZE:
      {
         /* Complement CRC value */ /* PRQA S 2985 1 */ /* MD_SecCrc_2985_RedundantOp */
         crcParam->currentCRC ^= finalValueCrc32;

         result = SECM_OK;

         break;
      }
      case SEC_CRC_VERIFY:
      {
         if (crcParam->crcByteCount == SEC_SIZE_CHECKSUM_CRC_32)
         {
            /* Convert byte array to big-endian CRC value */
            crcTransferred = (SecM_Crc32Type)SecM_GetInteger(SEC_SIZE_CHECKSUM_CRC_32, crcParam->crcSourceBuffer);

            /* Compare given CRC against calculated one */
            if (crcTransferred == crcParam->currentCRC)
            {
               /* CRC match */
               result = SECM_VER_OK;
            }
            else
            {
               /* CRC mismatch */
               result = SECM_VER_CRC;
            }
         }

         break;
      }
      case SEC_CRC_GET:
      {
         if (crcParam->crcByteCount >= SEC_SIZE_CHECKSUM_CRC_32)
         {
            SecM_SetInteger(SEC_SIZE_CHECKSUM_CRC_32, crcParam->currentCRC, crcParam->crcOutputBuffer);
            /* Overwrite with actual CRC size */
            crcParam->crcByteCount = SEC_SIZE_CHECKSUM_CRC_32;

            result = SECM_OK;
         }

         break;
      }
      default:
      {
         /* Unknown state - result already set */
         break;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_CRC_TYPE_CRC32 */

#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
/***********************************************************************************************************************
 *  SecM_ComputeCrc64
 **********************************************************************************************************************/
/*! \brief       Function that manages the state of CRC-64 computation
 *  \param[in,out] crcParam Pointer to parameter structure
 *  \return      SECM_OK if operation was successful
 *               SECM_NOT_OK
 **********************************************************************************************************************/
SecM_StatusType SecM_ComputeCrc64(V_MEMRAM1 SecM_CRC64ParamType V_MEMRAM2 V_MEMRAM3 * crcParam)
{
   SecM_StatusType result;
   SecM_Crc64Type  crcTransferred;

   result = SECM_NOT_OK;

   switch (crcParam->crcState)
   {
      case SEC_CRC_INIT:
      {
# if ( SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED )
         /* Check magic value to verify whether lookup table was already initialized */
         if ((initPatternCrc64.highWord != lookupCrc64[SEC_CRC_64_TABLE_SIZE].highWord)
            || (initPatternCrc64.lowWord != lookupCrc64[SEC_CRC_64_TABLE_SIZE].lowWord))
         {
            /* Initialize lookup table in RAM */
            SecM_GenerateLookupCrc64(crcParam->wdTriggerFct);
         }
# endif /* SEC_CRC_64_OPT == SEC_CRC_SPEED_OPTIMIZED */

         /* Set initial CRC value */ /* PRQA S 2985 1 */ /* MD_SecCrc_2985_RedundantOp */
         crcParam->currentCRC = initialValueCrc64;

         result = SECM_OK;

         break;
      }
      case SEC_CRC_COMPUTE:
      {
         /* Update CRC using provided data */
         SecM_UpdateCrc64(crcParam);

         result = SECM_OK;

         break;
      }
      case SEC_CRC_FINALIZE:
      {
         /* Complement CRC value */ /* PRQA S 2985 2 */ /* MD_SecCrc_2985_RedundantOp */
         crcParam->currentCRC.highWord ^= finalValueCrc64.highWord;
         crcParam->currentCRC.lowWord  ^= finalValueCrc64.lowWord;

         result = SECM_OK;

         break;
      }
      case SEC_CRC_VERIFY:
      {
         if (crcParam->crcByteCount == SEC_SIZE_CHECKSUM_CRC_64)
         {
            /* Convert byte array to big-endian CRC value */
            crcTransferred.highWord = (SecM_Crc64BaseType)SecM_GetInteger(SEC_SIZE_CHECKSUM_CRC_32, crcParam->crcSourceBuffer);
            crcTransferred.lowWord  = (SecM_Crc64BaseType)SecM_GetInteger(SEC_SIZE_CHECKSUM_CRC_32, &crcParam->crcSourceBuffer[SEC_SIZE_CHECKSUM_CRC_32]);

            /* Compare given CRC against calculated one */
            if ( (crcTransferred.highWord == crcParam->currentCRC.highWord)
              || (crcTransferred.lowWord == crcParam->currentCRC.lowWord) )
            {
               /* CRC match */
               result = SECM_VER_OK;
            }
            else
            {
               /* CRC mismatch */
               result = SECM_VER_CRC;
            }
         }

         break;
      }
      case SEC_CRC_GET:
      {
         if (crcParam->crcByteCount >= SEC_SIZE_CHECKSUM_CRC_64)
         {
            SecM_SetInteger(SEC_SIZE_CHECKSUM_CRC_32, crcParam->currentCRC.highWord, crcParam->crcOutputBuffer);
            SecM_SetInteger(SEC_SIZE_CHECKSUM_CRC_32, crcParam->currentCRC.lowWord, &crcParam->crcOutputBuffer[SEC_SIZE_CHECKSUM_CRC_32]);
            /* Overwrite with actual CRC size */
            crcParam->crcByteCount = SEC_SIZE_CHECKSUM_CRC_64;

            result = SECM_OK;
         }

         break;
      }
      default:
      {
         /* Unknown state - result already set */
         break;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_CRC_TYPE_CRC64 */

#if defined( SEC_ENABLE_SAVE_RESTORE_CRC )
/***********************************************************************************************************************
 *  SecM_SaveContextCrc
 **********************************************************************************************************************/
/*! \brief         Save the context of a CRC verification
 *  \param[in]     workspaceIdx  index of the CRC workspace
 *  \param[out]    contextBuffer buffer to save the context to
 *  \param[in,out] contextBufferLengthPtr Length of the provided buffer (output: actual length of saved context)
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_SaveContextCrc(SecM_WordType workspaceIdx, SecM_RamDataType contextBuffer, SecM_RamWordType contextBufferLengthPtr)
{
   SecM_StatusType result = SECM_NOT_OK;
   if (workspaceIdx < SEC_CRC_WORKSPACE_SIZE)
   {
      SecM_CrcWorkspaceInfoType const * localWorkspace = &SecM_CrcWorkspaceInfo[workspaceIdx];
      if (localWorkspace->state == CRC_WORKSPACE_INIT)
      {
         if (*contextBufferLengthPtr >= localWorkspace->workspaceLength)
         {
            /* PRQA S 0306 1 */ /* MD_SecCrc_0306 */
            SecM_CopyBuffer((SecM_ConstRamDataType)localWorkspace->workspacePtr, contextBuffer, (SecM_ShortType)localWorkspace->workspaceLength);
            *contextBufferLengthPtr = localWorkspace->workspaceLength;
            result = SECM_OK;
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_SAVE_RESTORE_CRC */

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_SecCrc_0306:
      Reason:     Buffer is stored as unsigned 32-bit value instead of pointer type for compatibility with other
                  types used in SecMod and must be converted to pointer for the copy buffer function.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation defined.
      Prevention: 32 bit handles all current use-cases. Pay special attention when 64 bit ECUs are introduced.

   MD_SecCrc_2985_RedundantOp:
      Reason:     Some operations are kept into the code, even if redundant and with no effect, for better code
                  understanding and debug improvement.
      Risk:       No risk.
      Prevention: No prevention required.

   MD_SecCrc_2985_4391:
      Reason:     MISRA
      Risk:       No risk.
      Prevention: No prevention required.

   MD_SecCrc_3218:
      Reason:     The configuration constants of this module are kept at a central location for a better overview and
                  maintenance. Scope is larger than required (whole file instead of one function).
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_SecCrc_3410:
      Reason:     Helper macro to expand comma separated list. Parameter cannot be enclosed in parentheses.
      Risk:       No identifiable risk.
      Prevention: No prevention required.
*/

/***********************************************************************************************************************
 *  END OF FILE: SEC_CRC.C
 **********************************************************************************************************************/

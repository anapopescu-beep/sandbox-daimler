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
 *  06.00.00   2020-04-08  visrie  FBL-1016         Support of EcuM functions, support of new FblSb interface
 *  06.00.01   2020-10-28  visrcn  ESCAN00107191    Compiler error: Wrong definition for FblMain function
 *  06.01.00   2022-04-13  vismix  FBL-4854         Add support for new swap API
 *                                                  Added/adapted MemMap sections
 *  06.02.00   2022-05-06  vishor  FBL-5148         Encapsulate call of FblInterruptDisable
 *  06.03.00   2022-07-06  vismix  FBL-5235         Use Pre Timer/Wd init as standard
 **********************************************************************************************************************/

#define UPD_MAIN_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "upd_cfg.h"

#include "upd_main.h"
#include "upd_ap.h"

#include "EcuM.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLUPD_MAIN_VERSION != 0x0603u ) || \
    ( FBLUPD_MAIN_RELEASE_VERSION != 0x00u )
# error "Error in UPD_MAIN.C: Source and Header file are inconsistent!"
#endif

/* Interface version compatibility check: General callouts */
#if defined( FBL_UPD_AP_API_VERSION_MAJOR ) && \
    defined( FBL_UPD_AP_API_VERSION_MINOR )
#else
# error "Error in UPD_MAIN.C: Interface version requirements not defined!"
#endif

#if ( FBL_UPD_AP_API_VERSION_MAJOR != FBL_UPD_API_VERSION_MAJOR) || \
    ( FBL_UPD_AP_API_VERSION_MINOR > FBL_UPD_API_VERSION_MINOR)
# error "Error in UPD_MAIN.C: Interface version compatibility check failed!"
#endif

/* Interface version compatibility check: platform-specific callouts */
#if defined( FBL_UPD_AP_HW_API_VERSION_MAJOR )
# if defined( FBL_UPD_AP_HW_API_VERSION_MINOR )
# else
#  error "Error in UPD_MAIN.C: Interface version requirements not defined!"
# endif

# if ( FBL_UPD_AP_HW_API_VERSION_MAJOR != FBL_UPD_API_VERSION_MAJOR) || \
     ( FBL_UPD_AP_HW_API_VERSION_MINOR > FBL_UPD_API_VERSION_MINOR)
#  error "Error in UPD_MAIN.C: Interface version compatibility check failed!"
# endif
#endif

/* Interface version compatibility check: OEM-specific callouts */
#if defined( FBL_UPD_AP_OEM_API_VERSION_MAJOR )
# if defined( FBL_UPD_AP_OEM_API_VERSION_MINOR )
# else
#  error "Error in UPD_MAIN.C: Interface version requirements not defined!"
# endif

# if ( FBL_UPD_AP_OEM_API_VERSION_MAJOR != FBL_UPD_API_VERSION_MAJOR) || \
    ( FBL_UPD_AP_OEM_API_VERSION_MINOR > FBL_UPD_API_VERSION_MINOR)
#  error "Error in UPD_MAIN.C: Interface version compatibility check failed!"
# endif
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* PRQA S 3453 TAG_FblUpd_Main_3453_1 */ /* MD_MSR_19.7 */

/** Helper macro to get number of array entries */
#define FBL_UPD_ARRAY_SIZE(arr)                            (sizeof(arr) / sizeof((arr)[0u]))
/** Trigger watchdog every n-th cycle */
#define FBL_UPD_TRIGGER_WATCHDOG(cycle)                           \
{                                                                 \
   if (((cycle) & (FBL_UPD_WATCHDOG_CYCLE_COUNT - 1u)) == 0x00u)  \
   {                                                              \
      (void)FblLookForWatchdog();                                 \
   }                                                              \
}  /* PRQA S 3458 */ /* MD_MSR_19.4 */


/** Assertion codes */
#define kFblUpdAssertAddressNotFound                       0x01u
#define kFblUpdAssertInvalidBlockConfig                    0x02u
#define kFblUpdAssertMissingReset                          0x03u
#define kFblUpdAssertFailedUpdate                          0x04u
#define kFblUpdAssertValidityRangeExceedsSegment           0x05u

/** Undefined hook function */
#define FBL_UPD_HOOK_NONE                                  (tFblUpdFunc)0

/*-- Default processing hook functions -------------------------------------------------------------------------------*/

/** Initalization hook */
#if !defined( FBL_UPD_HOOK_INIT )
# define FBL_UPD_HOOK_INIT                                 FBL_UPD_HOOK_NONE
#endif /* FBL_UPD_HOOK_INIT */

/** Send pending response (RCR-RP) */
#if !defined( FBL_UPD_HOOK_SEND_RESPONSE )
# if defined( FBL_UPD_ENABLE_RESPONSE_PENDING )
#  define FBL_UPD_HOOK_SEND_RESPONSE                       FblUpdSendResponse
#  define FBL_UPD_ENABLE_HOOK_SEND_RESPONSE
# else
#  define FBL_UPD_HOOK_SEND_RESPONSE                       FBL_UPD_HOOK_NONE
# endif /* FBL_UPD_ENABLE_RESPONSE_PENDING */
#endif /* FBL_UPD_HOOK_SEND_RESPONSE */

/** Pre-erase hook */
#if !defined( FBL_UPD_HOOK_PREPARE_ERASE )
# if defined( FBL_UPD_VALIDITY_RANGE_ADDR )
#  define FBL_UPD_HOOK_PREPARE_ERASE                       FblUpdPrepareErase
#  define FBL_UPD_ENABLE_HOOK_PREPARE_ERASE
# else
#  define FBL_UPD_HOOK_PREPARE_ERASE                       FBL_UPD_HOOK_NONE
# endif /* FBL_UPD_VALIDITY_RANGE_ADDR */
#endif /* FBL_UPD_HOOK_PREPARE_ERASE */

/** Post-erase hook */
#if !defined( FBL_UPD_HOOK_FINALIZE_ERASE )
# define FBL_UPD_HOOK_FINALIZE_ERASE                       FBL_UPD_HOOK_NONE
#endif /* FBL_UPD_HOOK_FINALIZE_ERASE */

/** Pre-programming hook */
#if !defined( FBL_UPD_HOOK_PREPARE_PROGRAM )
# define FBL_UPD_HOOK_PREPARE_PROGRAM                      FBL_UPD_HOOK_NONE
#endif /* FBL_UPD_HOOK_PREPARE_PROGRAM */

/** Post-programming hook */
#if !defined( FBL_UPD_HOOK_FINALIZE_PROGRAM )
# define FBL_UPD_HOOK_FINALIZE_PROGRAM                     FBL_UPD_HOOK_NONE
#endif /* FBL_UPD_HOOK_FINALIZE_PROGRAM */

/** Post-verification hook */
#if !defined( FBL_UPD_HOOK_FINALIZE_VERIFY )
# if defined( FBL_UPD_VALIDITY_RANGE_ADDR )
#  define FBL_UPD_HOOK_FINALIZE_VERIFY                     FblUpdFinalizeVerify
#  define FBL_UPD_ENABLE_HOOK_FINALIZE_VERIFY
# else
#  define FBL_UPD_HOOK_FINALIZE_VERIFY                     FBL_UPD_HOOK_NONE
# endif /* FBL_UPD_VALIDITY_RANGE_ADDR */
#endif /* FBL_UPD_HOOK_FINALIZE_VERIFY */

/** Updater invalidation hook */
#if !defined( FBL_UPD_HOOK_INVALIDATE_UPDATER )
# define FBL_UPD_HOOK_INVALIDATE_UPDATER                   FBL_UPD_HOOK_NONE
#endif /* FBL_UPD_HOOK_INVALIDATE_UPDATER */

/** Reset hook */
#if !defined( FBL_UPD_HOOK_RESET )
# define FBL_UPD_HOOK_RESET                                FblUpdReset
# define FBL_UPD_ENABLE_HOOK_RESET
#endif /* FBL_UPD_HOOK_RESET */

/*-- Default segment handling hook functions -------------------------------------------------------------------------*/

/** Get segment information */
#if !defined( FBL_UPD_HOOK_GET_SEGMENT )
# define FBL_UPD_HOOK_GET_SEGMENT                          FblUpdGetSegment
# define FBL_UPD_ENABLE_HOOK_GET_SEGMENT
#endif /* FBL_UPD_HOOK_GET_SEGMENT */

/** Adjust segment information for programming and verification */
#if !defined( FBL_UPD_HOOK_ADJUST_SEGMENT_PROGRAM )
# if defined( FBL_UPD_VALIDITY_RANGE_ADDR )
#  define FBL_UPD_HOOK_ADJUST_SEGMENT_PROGRAM              FblUpdAdjustSegmentProgram
#  define FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_PROGRAM
# else
#  define FBL_UPD_HOOK_ADJUST_SEGMENT_PROGRAM              FblUpdAdjustSegmentDummy
#  define FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_DUMMY
# endif /* FBL_UPD_VALIDITY_RANGE_ADDR */
#endif /* FBL_UPD_HOOK_ADJUST_SEGMENT_PROGRAM */

/** Adjust segment information for validity handling */
#if !defined( FBL_UPD_HOOK_ADJUST_SEGMENT_VALIDITY )
# if defined( FBL_UPD_VALIDITY_RANGE_ADDR )
#  define FBL_UPD_HOOK_ADJUST_SEGMENT_VALIDITY             FblUpdAdjustSegmentValidity
#  define FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_VALIDITY
# else
#  define FBL_UPD_HOOK_ADJUST_SEGMENT_VALIDITY             FblUpdAdjustSegmentDummy
#  if !defined( FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_DUMMY )
#   define FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_DUMMY
#  endif /* FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_DUMMY */
# endif /* FBL_UPD_VALIDITY_RANGE_ADDR */
#endif /* FBL_UPD_HOOK_ADJUST_SEGMENT_VALIDITY */

/*-- Further hook functions -------------------------------------------------------------------------------------------*/

/** Erase hook to check memSegment. Return kFblOk: erase shall happen, kFblFailed: erase shall not happen. Type: tFblResult */
#if !defined( FBL_UPD_HOOK_CHECK_MEMSEGMENT_ERASE )
# if defined( FBL_UPD_VALIDITY_RANGE_ADDR )
#  define FBL_UPD_HOOK_CHECK_MEMSEGMENT_ERASE(inSegment)   (((inSegment) == FblMemSegmentNrGet(FBL_UPD_VALIDITY_RANGE_ADDR))? kFblFailed : kFblOk)  /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
#  define FBL_UPD_HOOK_CHECK_MEMSEGMENT_ERASE(inSegment)   kFblOk
# endif /* FBL_UPD_VALIDITY_RANGE_ADDR */
#endif /* FBL_UPD_HOOK_CHECK_MEMSEGMENT_ERASE */

/** Read data from source segment */
#if !defined( FBL_UPD_HOOK_READ_SOURCE_SEGMENT )
# define FBL_UPD_HOOK_READ_SOURCE_SEGMENT(address, buffer, length)   (((length) == FblReadBlock((address), (buffer), (length))) ? kFblOk : kFblFailed)
#endif /* FBL_UPD_HOOK_READ_SOURCE_SEGMENT */

/* PRQA L:TAG_FblUpd_Main_3453_1 */

/***********************************************************************************************************************
*  TYPEDEFS
**********************************************************************************************************************/

/** Function pointer for segment operation */
typedef tFblResult (* tFblUpSegmentOp)( tFblAddress targetAddress, tFblLength length );

#if defined( C_CPUTYPE_32BIT ) || defined( C_CPUTYPE_16BIT )
/** Define a basic data type including buffer alignment to platform requirements */
typedef struct
{
   /** Dummy member to enforce 32-Bit alignment */
   vuint32  alignDummy;
   /** aligned Buffer of configured size */
   vuint8   data[FBL_UPD_BUFFER_SIZE];
}tFblUpdBufferAligned;
#else /* C_CPUTYPE_8BIT */
/** Define a basic data type including buffer alignment to platform requirements */
typedef struct
{
   /** Buffer of configured size, no alignment necessary */
   vuint8   data[FBL_UPD_BUFFER_SIZE];
}tFblUpdBufferAligned;
#endif /* C_CPUTYPE_32BIT || C_CPUTYPE_16BIT */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBL_UPD_MAIN_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_UPD_ENABLE_RESPONSE_PENDING )
/* Satisfy communication wrapper API */
/** Diagnostic buffer for RCR-RP message */ /* PRQA S 1514 1 */ /* MD_FblUpd_Main_1514 */
V_MEMRAM0 V_MEMRAM1 vuint8             V_MEMRAM2 DiagBuffer[FBL_UPD_RESPONSE_PENDING_SIZE];
/** FBL mode */
V_MEMRAM0 V_MEMRAM1_NEAR vuint8        V_MEMRAM2_NEAR fblMode;
/* State flag for shutdown handling */
V_MEMRAM0 V_MEMRAM1 vuint8             V_MEMRAM2 fblUpdShutdownState;
#endif /* FBL_UPD_ENABLE_RESPONSE_PENDING */

#define FBL_UPD_MAIN_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBL_UPD_MAIN_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static tFblResult FblUpdCheckAddressRange( tFblAddress address, tFblAddress rangeStart, tFblLength rangeLength );
static tFblLength FblUpdPadLength( tFblAddress address, tFblLength length );
static tFblLength FblUpdPadBuffer( tFblAddress address, tFblLength length,
   V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * data );

#if defined( FBL_UPD_ENABLE_HOOK_SEND_RESPONSE )
static tFblResult FblUpdSendResponse( void );
#endif /* FBL_UPD_ENABLE_HOOK_PRE_INIT */
#if defined( FBL_UPD_ENABLE_HOOK_PREPARE_ERASE )
static tFblResult FblUpdPrepareErase( void );
#endif /* FBL_UPD_ENABLE_HOOK_PREPARE_ERASE */
#if defined( FBL_UPD_ENABLE_HOOK_FINALIZE_VERIFY )
static tFblResult FblUpdFinalizeVerify( void );
#endif /* FBL_UPD_ENABLE_HOOK_FINALIZE_VERIFY */
#if defined( FBL_UPD_ENABLE_HOOK_RESET )
static tFblResult FblUpdReset( void );
#endif /* FBL_UPD_ENABLE_HOOK_RESET */

#if defined( FBL_UPD_ENABLE_HOOK_GET_SEGMENT )
static tFblResult FblUpdGetSegment( vuintx index, V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegment );
#endif /* FBL_UPD_ENABLE_HOOK_GET_SEGMENT */
#if defined( FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_DUMMY )
static tFblResult FblUpdAdjustSegmentDummy( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount );
#endif /* FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_DUMMY */
#if defined( FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_PROGRAM )
static tFblResult FblUpdAdjustSegmentProgram( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount );
#endif /* FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_PROGRAM */
#if defined( FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_VALIDITY )
static tFblResult FblUpdAdjustSegmentValidity( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount );
#endif /* FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_VALIDITY */
static tFblResult FblUpdSegmentOpProgram( tFblAddress targetAddress, tFblLength length );
static tFblResult FblUpdSegmentOpCompare( tFblAddress targetAddress, tFblLength length );
static tFblResult FblUpdIterateData( tFblUpSegmentOp pOperation, vuintx subIndex, tFblLength loopSize);
static tFblResult FblUpdIterateSegments( tFblUpSegmentOp pOperation, tFblUpAdjustSegment pAdjustSegment, tFblLength loopSize );

#if defined ( FBL_ENABLE_FLASHDRV_ROM )
#else
static void FblUpdCopyFlashDriver( void );
#endif /* FBL_ENABLE_FLASHDRV_ROM */
static void FblUpdInit( void );

static tFblResult FblUpdMioInit( void );
static tFblResult FblUpdErase( void );
static tFblResult FblUpdProgram( void );
static tFblResult FblUpdVerify( void );
#if defined( FBL_UPD_ENABLE_RESPONSE_PENDING )
static tFblResult FblUpdShutdown(void);
#endif /* FBL_UPD_ENABLE_RESPONSE_PENDING */

#define FBL_UPD_MAIN_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

 /* PRQA S 3218 TAG_FblUpd_Main_3218_1 */ /* MD_FblUpd_Main_3218 */

#define FBL_UPD_START_SEC_BUFFER_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/** Buffer used for storage of programming and verifcation data */
V_MEMRAM0 static V_MEMRAM1 tFblUpdBufferAligned V_MEMRAM2 fblUpdBuffer;

#define FBL_UPD_STOP_SEC_BUFFER_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBL_UPD_MAIN_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/** Buffer is split into half to hold verification data */
V_MEMROM0 static V_MEMRAM1 vuint8               V_MEMRAM2 V_MEMRAM3 * V_MEMROM1 V_MEMROM2 fblUpdCompareBuffer = &fblUpdBuffer.data[FBL_UPD_COMPARE_SIZE];
/** Storage space for (sub-)segment information */
V_MEMRAM0 static V_MEMRAM1 tFblUpdSegmentInfo   V_MEMRAM2 fblUpdSegmentList[FBL_UPD_SEGMENT_COUNT];

#define FBL_UPD_MAIN_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBL_UPD_MAIN_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/** Updater function array */
V_MEMROM0 static V_MEMROM1 tFblUpdFunc V_MEMROM2 fblUpdFunctionWalk[] =
{
   FBL_UPD_HOOK_INIT,
   FBL_UPD_HOOK_SEND_RESPONSE,
   FblUpdMioInit,
   FBL_UPD_HOOK_PREPARE_ERASE,
   FblUpdErase,
   FBL_UPD_HOOK_FINALIZE_ERASE,
   FBL_UPD_HOOK_PREPARE_PROGRAM,
   FblUpdProgram,
   FBL_UPD_HOOK_FINALIZE_PROGRAM,
   FblUpdVerify,
   FBL_UPD_HOOK_FINALIZE_VERIFY,
   FBL_UPD_HOOK_INVALIDATE_UPDATER,
#if defined( FBL_UPD_ENABLE_RESPONSE_PENDING )
   FblUpdShutdown,
#endif /* FBL_UPD_ENABLE_RESPONSE_PENDING */
   FBL_UPD_HOOK_RESET
};

/* PRQA L:TAG_FblUpd_Main_3218_1 */

#define FBL_UPD_MAIN_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#define FBL_UPD_MAIN_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*-- Helper functions ------------------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
*  FblUpdCheckAddressRange
***********************************************************************************************************************/
/*! \brief        Check whether an address lies within a specified address range
 *  \param[in]    address Address to be checked
 *  \param[in]    rangeStart Start of range
 *  \param[in]    rangeLength Length of range
 *  \return       Possible return values:
 *                   kFblOk if address lies within range
 *                   kFblFailed otherwise
 ***********************************************************************************************************************/
static tFblResult FblUpdCheckAddressRange( tFblAddress address, tFblAddress rangeStart, tFblLength rangeLength )
{
   tFblResult result;

   result = kFblFailed;

   /* Range check */
   if (  (address >= rangeStart)
      && ((address - rangeStart) < rangeLength) )
   {
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblUpdPadLength
 **********************************************************************************************************************/
/*! \brief        Calculate number of bytes required to pad provided address range to memory segment size
 *  \pre          Complete address range lies within current flash block
 *                memSegment initialized accordingly
 *  \param[in]    address Start address of memory range
 *  \param[in]    length Length of memory range
 *  \return       Number of required padding bytes
 **********************************************************************************************************************/
static tFblLength FblUpdPadLength( tFblAddress address, tFblLength length )
{
   tFblLength  localAddress;
   tFblLength  localLength;
   tFblLength  padLen;
   tFblAddress mask;

   /* Local copy of length */
   localLength = length;
   /* Special handling required for zero length
      Address used directly */
   if (length > 0u)
   {
      localLength--;
   }

   /* Calculate end address */
   localAddress = address + localLength;

   /* Bit mask for memory segment alignment */
   mask = (tFblAddress)(MemDriver_SegmentSize - 1u);

   /* Padding length calculated for end address of data to be padded */
   /* Invert all masked bits */
   padLen = localAddress ^ mask;

   /* Modify padding length for special case (zero length) */
   if (0u == length)
   {
      padLen++;
   }

   /* Apply mask to cut of unnecessary bits (e.g. additional address info, overflow of addition) */
   padLen &= mask;

   return padLen;
}
/***********************************************************************************************************************
 *  FblUpdPadBuffer
 **********************************************************************************************************************/
/*! \brief        Fill up the provided buffer with kFillChar if not aligned to the memory segment size
 *  \pre          Buffer provided has to be large enough to hold added padding bytes
 *                Complete address range lies within current flash block
 *                memSegment initialized accordingly
 *  \param[in]    address Start address of memory range
 *  \param[in]    length Length of memory range
 *  \param[in,out]   data Pointer to last byte of actual data
 *  \return       Number of padded bytes
 **********************************************************************************************************************/
static tFblLength FblUpdPadBuffer( tFblAddress address, tFblLength length,
   V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * data )
{
   V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * padBuffer;
   tFblLength padLen;
   tFblLength idx;

   /* Calculate number of required padding bytes */
   padLen = FblUpdPadLength(address, length);

   /* In case data was already aligned the last buffer byte may be located at the very last memory address
      Prevent address wrap around by relocating buffer not until padding is necessary */
   if (padLen > 0u)
   {
      /* Input buffer points to last byte of actual data */
      padBuffer = &data[1];

      /* Append data to align buffer to segment size */
      for (idx = 0u; idx < padLen; idx++)
      {
         padBuffer[idx] = kFillChar;
      }
   }

   return padLen;
}

/*-- Segment handling  functions -------------------------------------------------------------------------------------*/

#if defined( FBL_UPD_ENABLE_HOOK_GET_SEGMENT )
/***********************************************************************************************************************
 *  FblUpdGetSegment
 **********************************************************************************************************************/
/*! \brief        Get segment of new FBL referenced by given index
 *  \pre          Segment information available in array FblUpdateBlkInfo (generated by HexView)
 *  \param[in]    index Index of referenced segment
 *  \param[out]   pSegment Pointer resulting segment information
 *  \return       Result of operation
 *                   kFblOk when referenced segment is available
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblUpdGetSegment( vuintx index, V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegment )
{
   tFblResult result;

   result = kFblFailed;

   /* Referenced segment available? */
   if (index < FBLUPDATE_NUMBLOCKS)
   {
      /* Copy segment information to provided storage space */
      /* Pass source array address instead of pointer */
      pSegment->source  = (tFblAddress)FblUpdateBlkInfo[index].blockSource;   /* PRQA S 0306 */ /* MD_FblUpd_Main_0306 */
      pSegment->target  = FblUpdateBlkInfo[index].blockAddress;
      pSegment->length  = FblUpdateBlkInfo[index].blockLength;

      result = kFblOk;
   }

   return result;
}
#endif /* FBL_UPD_ENABLE_HOOK_GET_SEGMENT */

#if defined( FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_DUMMY )
/***********************************************************************************************************************
 *  FblUpdAdjustSegmentDummy
 **********************************************************************************************************************/
/*! \brief        Dummy segment adjustment function
 *  \detail       Leave segment information unchanged
 *  \param[in,out]   pSegmentList Pointer to segment list, first entry contains input segment
 *  \param[in,out]   pSegmentCount Input: Size of segment list
 *                      Output: Number of resulting segments
 *  \return       Result of operation
 *                   kFblOk when segment adjustment was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblUpdAdjustSegmentDummy( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount )
{
   /* No adjustment required */
   *pSegmentCount = 1u;

   return kFblOk;
}
#endif /* FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_DUMMY */

#if defined( FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_PROGRAM )
/***********************************************************************************************************************
 *  FblUpdAdjustSegmentProgram
 **********************************************************************************************************************/
/*! \brief        Adjust segments for programming / verification operation
 *  \detail       Skip the area occupied by the validity range
 *                Results in modified single segment when range lies at beginning or end of segment or two split
 *                segments.
 *  \pre          Validity range doesn't cross segment border
 *  \param[in,out]   pSegmentList Pointer to segment list, first entry contains input segment
 *  \param[in,out]   pSegmentCount Input: Size of segment list
 *                      Output: Number of resulting segments
 *  \return       Result of operation
 *                   kFblOk when segment adjustment was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static tFblResult FblUpdAdjustSegmentProgram( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount )
{
   tFblResult  result;
   vuintx      count;
   tFblLength  segLength;
   tFblAddress firstAddr;
   tFblAddress lastAddr;
   tFblAddress sourceAddr;
# if (FBL_UPD_VALIDITY_RANGE_ADDR > 0u)
   tFblAddress targetAddr;
# endif /* FBL_UPD_VALIDITY_RANGE_ADDR > 0u */

   result   = kFblOk;
   count    = *pSegmentCount;

   firstAddr   = pSegmentList[0].target;
   segLength   = pSegmentList[0].length;
   lastAddr    = firstAddr + (segLength - 1u);
   sourceAddr  = pSegmentList[0].source;

   /* Validity range included in current flash block? */
   if (kFblOk == FblUpdCheckAddressRange(FBL_UPD_VALIDITY_RANGE_ADDR, firstAddr, segLength))
   {
      if (count < 2u)
      {
         /* Segment list not large enough to hold potential sub-segments */
         result = kFblFailed;
      }
      else
      {
         /* Assume operation results in single segment */
         count = 1u;

         /* Segment large enough for validity range? */
         assertFbl((segLength >= FBL_UPD_VALIDITY_RANGE_SIZE), kFblUpdAssertValidityRangeExceedsSegment);   /* PRQA S 2214 */ /* MD_FblUpd_Main_2214 */

         if (segLength < FBL_UPD_VALIDITY_RANGE_SIZE)
         {
            /* Segment not large enough for validity range */
            segLength = 0u;
         }
         else
         {
            /* Length of single block is always decreased by size of validity range */
            segLength -= FBL_UPD_VALIDITY_RANGE_SIZE;
         }

         /* Check against empty segment */
         if (0u == segLength)
         {
            /* Segment only relevant for validity information */
            count = 0u;
         }
         /* Check against validity range at beginning of segment */
         else if (FBL_UPD_VALIDITY_RANGE_ADDR == firstAddr)
         {
            firstAddr   += FBL_UPD_VALIDITY_RANGE_SIZE;
            sourceAddr  += FBL_UPD_VALIDITY_RANGE_SIZE;
         }
         /* Check against validity range at end of segment */
         else if ((FBL_UPD_VALIDITY_RANGE_ADDR + (FBL_UPD_VALIDITY_RANGE_SIZE - 1u)) == lastAddr)
         {
            /* First address unchanged, length already decremented above */
         }
         else
         {
# if (FBL_UPD_VALIDITY_RANGE_ADDR > 0u)
            /* Validity range lies within segment*/
            /* Calculate start address of second sub-segment */
            targetAddr = FBL_UPD_VALIDITY_RANGE_ADDR + FBL_UPD_VALIDITY_RANGE_SIZE;

            pSegmentList[1u].target = targetAddr;
            pSegmentList[1u].length = (lastAddr - targetAddr) + 1u;
            pSegmentList[1u].source = sourceAddr + (targetAddr - firstAddr);

            /* First address unchanged */
            segLength = FBL_UPD_VALIDITY_RANGE_ADDR - firstAddr;

            /* Segment split into two sub-segments */
            count = 2u;
# endif /* FBL_UPD_VALIDITY_RANGE_ADDR > 0u */
         }
      }
   }
   else
   {
      /* No adjustment required */
      count = 1u;
   }

   /* Update information of single segment or first sub-segment */
   pSegmentList[0u].source  = sourceAddr;
   pSegmentList[0u].target  = firstAddr;
   pSegmentList[0u].length  = segLength;

   /* Return sub-segment count */
   *pSegmentCount = count;

   return result;
}
#endif /* FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_PROGRAM */

#if defined( FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_VALIDITY )
/***********************************************************************************************************************
 *  FblUpdAdjustSegmentValidity
 **********************************************************************************************************************/
/*! \brief        Adjust segments for validation operation
 *  \detail       Only return a potential validity range lying within the segment bounds
 *                Results in a single segment covering the validity range or an empty segment list
 *  \param[in,out]   pSegmentList Pointer to segment list, first entry contains input segment
 *  \param[in,out]   pSegmentCount Input: Size of segment list
 *                      Output: Number of resulting segments
 *  \return       Result of operation
 *                   kFblOk when segment adjustment was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblUpdAdjustSegmentValidity( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount )
{
   tFblResult  result;
   vuintx      count;
   tFblLength  offset;
   tFblLength  segLength;

   result   = kFblOk;

   /* Validity range included in current segment? */
   if (kFblOk == FblUpdCheckAddressRange(FBL_UPD_VALIDITY_RANGE_ADDR, pSegmentList[0].target, pSegmentList[0].length))
   {
      /* Offset of validity range relative to beginning of segment */
      offset = FBL_UPD_VALIDITY_RANGE_ADDR - pSegmentList[0u].target;
      /* Limit length to minimum of validity range and available data */
      segLength = pSegmentList[0].length - offset;
      if (segLength > FBL_UPD_VALIDITY_RANGE_SIZE)
      {
         segLength = FBL_UPD_VALIDITY_RANGE_SIZE;
      }

      /* Limit segment to validity range */
      pSegmentList[0u].source  += offset;
      pSegmentList[0u].target   = FBL_UPD_VALIDITY_RANGE_ADDR;
      pSegmentList[0u].length   = segLength;

      count = 1u;
   }
   else
   {
      /* Segment not relevant for validity information */
      count = 0u;
   }

   /* Return sub-segment count */
   *pSegmentCount = count;

   return result;
}
#endif /* FBL_UPD_ENABLE_HOOK_ADJUST_SEGMENT_VALIDITY */

/***********************************************************************************************************************
 *  FblUpdSegmentOpProgram
 **********************************************************************************************************************/
/*! \brief        Segment operation: programming of data
 *  \pre          fblUpdBuffer holds data to be programmed
 *  \param[in]    targetAddress Start address where data should be programmed
 *  \param[in]    length Length of data
 *  \return       Result of operation
 *                   kFblOk when programming was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblUpdSegmentOpProgram( tFblAddress targetAddress, tFblLength length )
{
   tFblResult result;
   tFblLength localLength;
#if defined( FBL_UPD_ENABLE_PADDING )
   tFblLength padLen;
#endif /* FBL_UPD_ENABLE_PADDING */

   result = kFblFailed;
   localLength = length;

#if defined( FBL_UPD_ENABLE_PADDING )
   /* Determine length of potential padding to align length to memory segment size */
   padLen = FblUpdPadLength(targetAddress, localLength);

   /* Adding padding must not exceed available buffer */
   if ((localLength + padLen) <= FBL_UPD_BUFFER_SIZE)
   {
      /* Apply buffer padding and adjust total length accordingly */
      (void)FblUpdPadBuffer(targetAddress, localLength, &fblUpdBuffer.data[localLength - 1u]);
      localLength += padLen;
#else
   {
#endif /* FBL_UPD_ENABLE_PADDING */
      /* Pass programming request to memory driver */
      if (kFlashOk == MemDriver_RWriteSync(fblUpdBuffer.data, localLength, targetAddress))
      {
         result = kFblOk;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblUpdSegmentOpCompare
 **********************************************************************************************************************/
/*! \brief        Segment operation: validation of data
 *  \pre          fblUpdBuffer holds data to be compared
 *  \param[in]    targetAddress Start address where data was programmed
 *  \param[in]    length Length of data
 *  \return       Result of operation
 *                   kFblOk when comparision was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblUpdSegmentOpCompare( tFblAddress targetAddress, tFblLength length )
{
   tFblResult  result;
   vuintx      compareIndex;

   result = kFblOk;

   /* Read programmed data into compare buffer */
   if (kFlashOk == MemDriver_RReadSync(fblUpdCompareBuffer, length, targetAddress))
   {
      /* Compare input and programmed data */
      for (compareIndex = 0u; compareIndex < length; compareIndex++)
      {
         FBL_UPD_TRIGGER_WATCHDOG(compareIndex);   /* PRQA S 3109 */ /* MD_FblUpd_Main_3109 */

         if (fblUpdBuffer.data[compareIndex] != fblUpdCompareBuffer[compareIndex])
         {
            /* Comparision failed */
            result = kFblFailed;

            break;
         }
      }
   }
   else
   {
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblUpdIterateData
 **********************************************************************************************************************/
/*! \brief        Iterate over data of a single (sub-)segment and execute segment operation
 *  \pre          Loop size must fit into fblUpdBuffer and/or other buffers used during operation
 *  \param[in]    pOperation Operation to be executed on segment data
 *  \param[in]    pAdjustSegment Segment adjustment function
 *  \param[in]    loopSize Size of data to be handled in a single loop
 *  \return       Result of operation
 *                   kFblOk when comparision was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static tFblResult FblUpdIterateData( tFblUpSegmentOp pOperation, vuintx subIndex, tFblLength loopSize )
{
   tFblResult  result;

   tFblAddress targetAddress;
   tFblAddress sourceAddress;
   tFblLength  remainderLength;
   tFblLength  operationLength;
   tFblLength  flashBlockRemainder;

   result         = kFblOk;

   /* Evaluate segment information */
   sourceAddress   = fblUpdSegmentList[subIndex].source;
   targetAddress   = fblUpdSegmentList[subIndex].target;
   remainderLength = fblUpdSegmentList[subIndex].length;

   /* Iterate over segment data */
   while (remainderLength > 0u)
   {
      /* Evaluate flash block of current target address */
      memSegment = FblMemSegmentNrGet(targetAddress);

      if (memSegment < 0)
      {
         /* Error: No valid flash block found */
         result = kFblFailed;
      }
      else if (0u != (targetAddress & ((tFblAddress)MemDriver_SegmentSize - 1u)))
      {
         /* Error: Address not aligned to memory segment size */
         result = kFblFailed;
      }
      else
      {
         /* Remaining length until end of current flash block */
         flashBlockRemainder = (FlashBlock[memSegment].end - targetAddress) + 1u;
         if (remainderLength < flashBlockRemainder)
         {
            /* Limit to remaining data */
            flashBlockRemainder = remainderLength;
         }

         /* Update remainding data */
         remainderLength -= flashBlockRemainder;

         /* Process data in currently affected flash block */
         while (flashBlockRemainder > 0u)
         {
            /* Only handle limited chunk of data per loop */
            operationLength = loopSize;
            if (flashBlockRemainder < loopSize)
            {
               /* Limit to remaining data */
               operationLength = flashBlockRemainder;
            }

#if defined( FBL_UPD_ENABLE_PADDING )
#else
            if (0u != (operationLength & ((tFblLength)MemDriver_SegmentSize - 1u)))
            {
               /* Error: Length not aligned to memory segment size */
               result = kFblFailed;
            }
            else
#endif /* FBL_UPD_ENABLE_PADDING */
            /* else */ if (kFblOk != FBL_UPD_HOOK_READ_SOURCE_SEGMENT(sourceAddress, fblUpdBuffer.data, operationLength))
            {
               /* Error reading segment data */
               result = kFblFailed;
            }
            else
            {
               /* Perform operation (e.g. programming) on segment data */
               result = pOperation(targetAddress, operationLength);
            }

            /* Advance segment data and target */
            targetAddress        += operationLength;
            sourceAddress        += operationLength;
            flashBlockRemainder  -= operationLength;

            /* Abort iterating over flash block data */
            if (kFblOk != result)
            {
               flashBlockRemainder = 0u;
            }
         }
      }

      /* Abort iterating over segment data */
      if (kFblOk != result)
      {
         remainderLength = 0u;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblUpdIterateSegments
 **********************************************************************************************************************/
/*! \brief        Iterate over segments of new FBL and execute segment operation on data
 *  \pre          Loop size must fit into fblUpdBuffer and/or other buffers used during operation
 *  \param[in]    pOperation Operation to be executed on segment data
 *  \param[in]    pAdjustSegment Segment adjustment function
 *  \param[in]    loopSize Size of data to be handled in a single loop
 *  \return       Result of operation
 *                   kFblOk when comparision was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblUpdIterateSegments( tFblUpSegmentOp pOperation, tFblUpAdjustSegment pAdjustSegment, tFblLength loopSize )
{
   tFblResult  result;
   vuintx      segmentIndex;
   vuintx      subIndex;
   vuintx      subSegments;

   result         = kFblOk;
   segmentIndex   = 0u;

   /* Further segment (referenced by index) available?*/
   while (kFblOk == FBL_UPD_HOOK_GET_SEGMENT(segmentIndex, fblUpdSegmentList))
   {
      /* Preprare index for next cycle */
      segmentIndex++;
      /* Maximum number of sub-segments */
      subSegments = FBL_UPD_ARRAY_SIZE(fblUpdSegmentList);

      /* Adjust segment information */
      if (kFblOk == pAdjustSegment(fblUpdSegmentList, &subSegments))
      {
         /* Adjustment of segment may result in multiple sub-segments (or none at all) */
         for (subIndex = 0u; subIndex < subSegments; subIndex++)
         {
            result = FblUpdIterateData(pOperation, subIndex, loopSize);

            /* Abort iterating sub-segments */
            if (kFblOk != result)
            {
               break;
            }
         }
      }

      /* Abort iterating segments */
      if (kFblOk != result)
      {
         break;
      }
   }

   /* At least one segment must be present, otherwise report failure */
   if (0u == segmentIndex)
   {
      result = kFblFailed;
   }

   return result;
}

/*-- Default hook functions ------------------------------------------------------------------------------------------*/

#if defined( FBL_UPD_ENABLE_HOOK_SEND_RESPONSE )
/***********************************************************************************************************************
 *  FblUpdSendResponse
 **********************************************************************************************************************/
/*! \brief        Send initial response pending (RCR-RP) message
 *  \details      Prepare response buffer and transmit message using communication wrapper
 *  \return       Result of operation
 *                   kFblOk if successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblUpdSendResponse( void )
{
   if (FBL_UPD_CALLOUT_CHECK_RESPONSE_PENDING() == kFblOk)
   {
      /* Activate transceiver */
      FBL_UPD_CALLOUT_ACTIVATE_TRANSCEIVER();
      /* Init ComWrapper */
      FblCwSetTxInit();
      if (kFblOk == FblCwPrepareResponseAddress())
      {
         /* Prepare response pending message in diagnostic buffer */
         FBL_UPD_CALLOUT_PREPARE_RESPONSE_PENDING(DiagBuffer);
         /* Transmit message */
         FblCwTransmitRP(DiagBuffer);
         /* Start P2* timeout for repetition of RCR-RP */
         SetP2Timer(kFblDiagTimeP2Star);
      }
   }

   /* Always return kFblOk even if an error has occurred (e.g. couldn't read response address) */
   return kFblOk;
}
#endif /* FBL_UPD_ENABLE_HOOK_SEND_RESPONSE */

#if defined( FBL_UPD_ENABLE_HOOK_PREPARE_ERASE )
/***********************************************************************************************************************
 *  FblUpdPrepareErase
 **********************************************************************************************************************/
/*! \brief        Erase flash block which includes validity range
 *  \details      First callback function with activated flash driver.
 *                Modification of the flash possible just before the update starts
 *  \pre          Validity range lies within a single flash block
 *  \return       Result of operation
 *                   kFblOk if successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblUpdPrepareErase( void )
{
   tFblResult result;

   result = kFblFailed;

   /* Evaluate flash block which should be erased first */
   memSegment = FblMemSegmentNrGet( FBL_UPD_VALIDITY_RANGE_ADDR );

   if (memSegment >= 0)
   {
      /* Erase flash block containing validity range */
      if (kFlashOk == MemDriver_REraseSync(((FlashBlock[memSegment].end - FlashBlock[memSegment].begin) + 1u), FlashBlock[memSegment].begin))
      {
         result = kFblOk;
      }
   }

   return result;
}
#endif /* FBL_UPD_ENABLE_HOOK_PREPARE_ERASE */

#if defined( FBL_UPD_ENABLE_HOOK_FINALIZE_VERIFY )
/***********************************************************************************************************************
 *  FblUpdFinalizeVerify
 ***********************************************************************************************************************/
/*! \brief        Program validity range when the verification was successful
 *  \details      Additional flash operations possible after code verification (e.g. TriCore: write BMHD)
 *  \return       Result of operation
 *                   kFblOk if successful
 *                   kFblFailed otherwise
 ***********************************************************************************************************************/
static tFblResult FblUpdFinalizeVerify( void )
{
   return FblUpdIterateSegments(FblUpdSegmentOpProgram, FBL_UPD_HOOK_ADJUST_SEGMENT_VALIDITY, FBL_UPD_BUFFER_SIZE);
}
#endif /* FBL_UPD_ENABLE_HOOK_FINALIZE_VERIFY */

/*-- Core functionality ----------------------------------------------------------------------------------------------*/

#if defined ( FBL_ENABLE_FLASHDRV_ROM )
#else
/***********************************************************************************************************************
 *  FblUpdCopyFlashDriver
 ***********************************************************************************************************************/
/*! \brief        Copies the flashdriver from the ROM table into flashCode buffer
 ***********************************************************************************************************************/
static void FblUpdCopyFlashDriver(void)
{
   vuint16 index;

   /* flashCode buffer location must match the flashdriver start address */
# if defined( FLASH_DRIVER_RELOCATABLE )
# else
   if ( (flashCode == (IO_U8 *)FLASHDRV_BLOCK0_ADDRESS) )
# endif /* FLASH_DRIVER_RELOCATABLE */
   {
      /* Copy all flash driver code from ROM into the flashCode buffer */
      for (index = 0u; index < FLASHDRV_BLOCK0_LENGTH; index++)
      {
         FBL_UPD_TRIGGER_WATCHDOG(index);    /* PRQA S 3109 */ /* MD_FblUpd_Main_3109 */
         flashCode[index] = FLASHDRV_DECRYPTDATA(flashDrvBlk0[index]);
      }
   }
}
#endif /* FBL_ENABLE_FLASHDRV_ROM */

/***********************************************************************************************************************
 *  FblUpdInit
 ***********************************************************************************************************************/
/*! \brief     Do initializations after reset
 ***********************************************************************************************************************/
static void FblUpdInit( void )
{
   /* Clear initialized flags */
   ClrWDInit();

   /* Initialize MIO state */
   MemDriver_InitPowerOn(); /* PRQA S 3109 */ /* MD_CBD_14.3 */

   /* Preinitialization step */
   /* Initialize and activate watchdog */
   FblInitWatchdog();
   /* Initialize Timer */
   FblTimerInit();

   /* Initialization callout */
   FBL_UPD_CALLOUT_INIT_POWER_ON();

#if defined( FBL_UPD_ENABLE_RESPONSE_PENDING )
   /* Clear shutdown flag */
   FblUpdClrFblShutdownRequest();
#endif /* FBL_UPD_ENABLE_RESPONSE_PENDING */

   FblLbtInitPowerOn();

#if defined( FBL_ENABLE_HARDWARE_SWAP )
   /* Initialize hardware swap module */
   FblSwapInitPowerOn();
#endif

#if defined( FBLBM_ENABLE_SECURE_BOOT )
   /* Initializes SecureBoot */
   FblSb_Init();
#endif /* FBLBM_ENABLE_SECURE_BOOT */

   EcuM_StartupTwo();
}

/***********************************************************************************************************************
 *  FblUpdMioInit
 ***********************************************************************************************************************/
/*! \brief        Initialize the flash driver(s)
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 ***********************************************************************************************************************/
static tFblResult FblUpdMioInit( void )
{
   tFblResult result;

   result = kFblOk;

#if defined ( FBL_ENABLE_FLASHDRV_ROM )
#else
   FblUpdCopyFlashDriver();
#endif /* FBL_ENABLE_FLASHDRV_ROM */

   /* Enable flash programming voltage (if required) */
   FBL_UPD_CALLOUT_SET_VFP();

   /* Init flash driver */
   if (IO_E_OK != MemDriver_InitSync((void *)0))
   {
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblUpdErase
 ***********************************************************************************************************************/
/*! \brief        Erase the FBL area
 *  \details      Iterates over all update segments and erases all flash blocks that contain new FBL data
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 ***********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static tFblResult FblUpdErase( void )
{
   tFblResult  result;
   vsint16     firstBlock, lastBlock, prevBlock, loopSegment;
   vuintx      segmentIndex;

   /* At least one segment must be present, otherwise report failure */
   result         = kFblFailed;
   segmentIndex   = 0u;
   prevBlock      = -1;

   /* Further segment (referenced by index) available?*/
   while (kFblOk == FBL_UPD_HOOK_GET_SEGMENT(segmentIndex, fblUpdSegmentList))
   {
      /* Prepare index for next cycle */
      segmentIndex++;

      /* Evaluate flash blocks affected by segment */
      firstBlock  = FblMemSegmentNrGet(fblUpdSegmentList->target);
      lastBlock   = FblMemSegmentNrGet(fblUpdSegmentList->target + (fblUpdSegmentList->length - 1u));

      /* Blocks must be ordered */
      assertFbl((firstBlock <= lastBlock), kFblUpdAssertInvalidBlockConfig);  /* PRQA S 2214 */ /* MD_FblUpd_Main_2214 */

      if ((firstBlock < 0) || (lastBlock < 0))
      {
         /* Error: No valid flash block(s) found */
      }
      else
      {
         result = kFblOk;

         /* Only process flash blocks affected by current segment when at least one wasn't handled previously */
         if (lastBlock > prevBlock)
         {
            /* Previous block was already covered, start with following block */
            if (firstBlock <= prevBlock)
            {
               firstBlock = prevBlock + 1;
            }
            prevBlock = lastBlock;

            /* Look for blocks in FblFlashBlockTable (fbl_apfb) */
            for (loopSegment = firstBlock; loopSegment <= lastBlock; loopSegment++)
            {
               memSegment = loopSegment;
               if (kFblOk == FBL_UPD_HOOK_CHECK_MEMSEGMENT_ERASE(memSegment))
               {
                  /* Block belongs to old FBL: erase this flash block completely */
                  if (kFlashOk != MemDriver_REraseSync((FlashBlock[memSegment].end - FlashBlock[memSegment].begin) + 1u,
                           FlashBlock[memSegment].begin))
                  {
                     result = kFblFailed;
                     break;
                  }
               }
            }
         }
      }

      if (kFblOk != result)
      {
         break;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblUpdProgram
 ***********************************************************************************************************************/
/*! \brief        Program the new FBL
 *  \details      Iterates over all update segments and writes the data to the new location
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 ***********************************************************************************************************************/
static tFblResult FblUpdProgram( void )
{
   return FblUpdIterateSegments(FblUpdSegmentOpProgram, FBL_UPD_HOOK_ADJUST_SEGMENT_PROGRAM, FBL_UPD_BUFFER_SIZE);
}

/***********************************************************************************************************************
 *  FblUpdVerify
 ***********************************************************************************************************************/
/*! \brief        Verify the new FBL data
 *  \details      Iterates over all update segments and checks if the data at the new location is correct
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 ***********************************************************************************************************************/
static tFblResult FblUpdVerify( void )
{
   return FblUpdIterateSegments(FblUpdSegmentOpCompare, FBL_UPD_HOOK_ADJUST_SEGMENT_PROGRAM, FBL_UPD_COMPARE_SIZE);
}

#if defined( FBL_UPD_ENABLE_HOOK_RESET )
/***********************************************************************************************************************
 *  FblUpdReset
 ***********************************************************************************************************************/
/*! \brief        Perform reset
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 ***********************************************************************************************************************/
static tFblResult FblUpdReset( void )
{
   /* Reset programming voltage */
   FBL_UPD_CALLOUT_RESET_VFP();
   /* Perform reset */
   FBL_UPD_CALLOUT_RESET();

   /* Should never be reached */
   return kFblFailed;
}
#endif /* FBL_UPD_ENABLE_HOOK_RESET */

#if defined( FBL_UPD_ENABLE_RESPONSE_PENDING )
/***********************************************************************************************************************
 *  FblUpdShutdown
 ***********************************************************************************************************************/
/*! \brief        Perform shutdown
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 ***********************************************************************************************************************/
static tFblResult FblUpdShutdown(void)
{
   /* Stop further RCR-RP transmission */
   ClrP2Timer();

   /* Request shutdown from Com-Wrapper */
   FblCwShutdownRequest(kFblCwResetEcuRegularCase);

   /* PRQA S 2994, 2995, 2996 1 */ /* MD_FblUpd_Main_2994_2995_2996 */
   while (!FblUpdGetFblShutdownRequest())
   {
      (void)FblLookForWatchdog(); /* PRQA S 2880 */ /* MD_MSR_Unreachable */
   }

# if( FBL_CW_API_REFERENCE_VERSION_MAJOR == 0x02u )
   FblCw_Deinit();
# else
   FblCwDeinit();
# endif /* FBL_CW_API_REFERENCE_VERSION_MAJOR */

   /* Always return kFblOk to satisfy API */
   return kFblOk;
}
#endif /* FBL_UPD_ENABLE_RESPONSE_PENDING */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/*-- Communication wrapper stubs -------------------------------------------------------------------------------------*/

#if defined( FBL_UPD_ENABLE_RESPONSE_PENDING)
# define FBL_UPD_RAMCODE_START_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  FblDiagTxErrorIndication
 **********************************************************************************************************************/
/*! \brief        Indicates that an error has occurred during transmission.
 *  \details      Dummy function to satisfy communication wrapper API
 *  \param[in]    cwMsgType Message type of indication
 **********************************************************************************************************************/
void FblDiagTxErrorIndication( vuint8 cwMsgType )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)cwMsgType;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */
}

/***********************************************************************************************************************
 *  FblDiagRxStartIndication
 **********************************************************************************************************************/
/*! \brief        Data reception call-back function to start diagnostic service processing.
 *  \details      Dummy function to satisfy communication wrapper API
 **********************************************************************************************************************/
void FblDiagRxStartIndication( void )
{
}

/***********************************************************************************************************************
 *  FblDiagRxErrorIndication
 **********************************************************************************************************************/
/*! \brief        Indicates that an error has occurred during reception.
 *  \details      Dummy function to satisfy communication wrapper API
 **********************************************************************************************************************/
void FblDiagRxErrorIndication( void )
{
}

/***********************************************************************************************************************
 *  FblDiagRxIndication
 **********************************************************************************************************************/
/*! \brief        Data reception call-back function to start diagnostic service processing.
 *  \details      Dummy function to satisfy communication wrapper API
 *  \param[in]    pbDiagBuffer Pointer to diagnostic buffer
 *  \param[in]    rxDataLength Number of bytes to be received
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblUpdMain_3673 */
void FblDiagRxIndication( V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagBuffer, tCwDataLengthType rxDataLength )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)pbDiagBuffer;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
   (void)rxDataLength;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */
}

/***********************************************************************************************************************
 *  FblDiagTxConfirmation
 **********************************************************************************************************************/
/*! \brief        TP transmission call-back function.
 *  \details      Dummy function to satisfy communication wrapper API
 *  \param[in]    cwMsgType Message type of indication
 **********************************************************************************************************************/
void FblDiagTxConfirmation( vuint8 cwMsgType )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)cwMsgType;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */
}

/***********************************************************************************************************************
 *  FblDiagRxGetPhysBuffer
 **********************************************************************************************************************/
/*! \brief        Diagnostic buffer management function for physical requests.
 *  \details      Dummy function to satisfy communication wrapper API
 *  \param[in]    rxDataLength Number of bytes to be received
 *  \return       Possible return values:
 *                - V_NULL in case no buffer is available
 **********************************************************************************************************************/
V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * FblDiagRxGetPhysBuffer( tCwDataLengthType rxDataLength )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)rxDataLength;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   /* No buffer can be provided, return null pointer */
   return V_NULL;
}

/***********************************************************************************************************************
 *  FblDiagRxGetFuncBuffer
 **********************************************************************************************************************/
/*! \brief        Diagnostic buffer management function for functional requests.
 *  \details      Dummy function to satisfy communication wrapper API
 *  \param[in]    rxDataLength Number of bytes to be received
 *  \return       Possible return values:
 *                - V_NULL in case no buffer is available
 **********************************************************************************************************************/
V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * FblDiagRxGetFuncBuffer( tCwDataLengthType rxDataLength )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)rxDataLength;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   /* No buffer can be provided, return null pointer */
   return V_NULL;
}

# define FBL_UPD_RAMCODE_STOP_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBL_UPD_ENABLE_RESPONSE_PENDING */

/*-- Helper functions ------------------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
 *  FblMemSetInteger
 **********************************************************************************************************************/
/*! \brief      Convert given integer value to big-endian byte array
 *  \param[in]  count Number of relevant bytes
 *  \param[in]  input Input value
 *  \param[out] buffer Pointer to output buffer
 **********************************************************************************************************************/
void FblMemSetInteger( vuintx count, vuint32 input, tFblMemRamData buffer )
{
   vuintx localCount = count;
   vuint32 localInput = input;
   /* Loop relevant bytes */
   while (localCount > 0u)
   {
      localCount--;
      /* Store most significant byte first */
      buffer[localCount] = (vuint8)(localInput & 0xFFu);
      /* Shift in next byte */
      localInput >>= 8u;
   }
}

/***********************************************************************************************************************
 *  FblMemGetInteger
 **********************************************************************************************************************/
/*! \brief      Convert given big-endian byte array to integer value
 *  \param[in]  count Number of relevant bytes
 *  \param[in]  buffer Pointer to input buffer
 *  \return     Integer value
 **********************************************************************************************************************/
vuint32 FblMemGetInteger( vuintx count, tFblMemConstRamData buffer )
{
   vuint32 output;
   vuintx idx;

   output = 0u;
   idx    = 0u;

   /* Loop relevant bytes */
   while (idx < count)
   {
      /* Most significant byte first */
      output <<= 8u;
      /* Add current byte */
      output |= (vuint32)buffer[idx];

      idx++;
   }

   return output;
}

/*-- Main functions --------------------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
 *  FblMain
 **********************************************************************************************************************/
/*! \brief        Initializes the system and runs the update process.
 **********************************************************************************************************************/
/* PRQA S 5209 1 */ /* MD_FblUpd_Main_5209 */
void V_API_NEAR FblMain( void )
{
   vuintx      updateCount;
   vuintx      funcIndex;
   tFblUpdFunc updateFct;
   tFblResult  updateState;


   /* Initialization */
   FblUpdInit();

   updateCount = 0u;

   /* Retry update process in case of failures */
   while (updateCount < FBL_UPD_MAX_RETRIES)
   {
      updateState = kFblOk;

      /* Iterate over update steps */
      for (funcIndex = 0u; funcIndex < FBL_UPD_ARRAY_SIZE(fblUpdFunctionWalk); funcIndex++)
      {
         (void)FblLookForWatchdog();

         updateFct = fblUpdFunctionWalk[funcIndex];

         /* Only run implemented functions */
         if (FBL_UPD_HOOK_NONE != updateFct)
         {
            updateState = updateFct();
         }

         /* Abort and retry in case of failure */
         if (kFblOk != updateState)
         {
            break;
         }
      }

      /* Shouldn't be reached if the update was successful */
      assertFbl((kFblOk == updateState), kFblUpdAssertMissingReset); /* PRQA S 2214 */ /* MD_FblUpd_Main_2214 */

      /* Retry update */
      updateCount++;
   }

   /* Only reached when update wasn't successful */
   assertFbl((kFblOk == updateState), kFblUpdAssertFailedUpdate); /* PRQA S 2214 */ /* MD_FblUpd_Main_2214 */
}

#define FBL_UPD_MAIN_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

#if ( 0u == FBL_UPD_WATCHDOG_CYCLE_COUNT ) || \
    ( (FBL_UPD_WATCHDOG_CYCLE_COUNT & (FBL_UPD_WATCHDOG_CYCLE_COUNT - 1u)) != 0u )
# error "Error in UPD_MAIN.C: Watchdog cycle count has to be a power of two (2^n)!"
#endif

#if defined( FBL_UPD_ENABLE_HOOK_GET_SEGMENT )
# if defined( FBLUPDATE_NUMBLOCKS )
# else
#  error "Error in UPD_MAIN.C: Number of blocks to update (generated by HexView) unknown"
# endif
#endif /* FBL_UPD_ENABLE_HOOK_GET_SEGMENT */

#if defined ( FBL_ENABLE_FLASHDRV_ROM )
#else
# if (FLASH_SIZE < FLASHDRV_BLOCK0_LENGTH)
#  error "Error in UPD_MAIN.C: Flash code does not fit into reserved buffer, check FLASH_SIZE define"
# endif
#endif /* FBL_ENABLE_FLASHDRV_ROM */

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_FblUpd_Main_0306:
      Reason:     Address conversion between integer values and pointers is required to allow for hardware independent
                  configuration and address range checks.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation defined.
      Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                  specific basis.

   MD_FblUpd_Main_1006:
      Reason:     Interrupts are enabled/disabled using assembler code.
      Risk:       The code is not portable for different compilers.
      Prevention: The assembler code provided by each FblHw module has to be tested.

   MD_FblUpd_Main_1514
      Reason:     The variable is used by other modules and can't be declared static.
      Risk:       Name conflicts.
      Prevention: Compile and link of the different variants in the component and integration test.


   MD_FblUpd_Main_2214:
      Reason:     This is an assertion macro used only for debugging in development (FBL_ENABLE_ASSERTION). There should
                  be no need to extend the amount of statements, so the current usage is accepted.
      Risk:       Unintended debugging code behavior could result, through adding further statements,
      Prevention: A comment is in place to avoid that further statements are added to the if condition.

   MD_FblUpd_Main_2994_2995_2996:
      Reason:     Value is constant depending on configuration aspects or platform specific implementation. This leads
                  to constant control expressions, unreachable code or redundant operations.
      Risk:       Wrong or missing functionality.
      Prevention: Code inspection and test of the different variants in the component test.

   MD_FblUpd_Main_3109:
      Reason:     Multi-line macros encapsulated in curly brackets to reduce side-effects. Results in empty statement
                  after the closing bracket.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblUpd_Main_3218:
      Reason:     Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk:       Scope is larger than required (whole file instead of one function). Some other function could access
                  the variable.
      Prevention: Take care that this deviation is used for constant data only (which cannot be modified).

   MD_FblUpdMain_3673:
      Reason:     This is a standard API that should not be changed for compatibility reasons.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblUpd_Main_5209:
      Reason:     The Vector standard API for main function follows ANSI C typical definition of main function
                  returning int.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_UPD_MAIN.C
 **********************************************************************************************************************/

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
 *  01.01.00   2018-06-15  visci   ESCAN00099699    Added support for reprogrammable LBT
 *  01.02.00   2018-09-24  visrr   ESCAN00100837    Added user callout for different erase values in OTA use case
 *  01.03.00   2018-12-07  visshs  ESCAN00101559    Added API functions FblNvPattern...SetByBlockDescriptor
 *  01.04.00   2019-01-25  viskjs  ESCAN00101824    Added patterns that can be validated multiple times
 *                                 ESCAN00101823    Added feature to store arbitrary data at end of logical block
 *  01.04.01   2019-03-26  viskjs  ESCAN00102200    Harmonized return value for Set and ClrPattern
 *                                 ESCAN00102204    Check memory area of block property before writing
 *                                 ESCAN00102646    Storing properties not working for first flash block in flash block
 *  01.04.02   2019-07-22  vistbe  ESCAN00103605    Compiler error: Memory qualifier mismatch for function parameter
 *  01.04.03   2020-05-07  visjdn  ESCAN00106002    Detecting a prensence pattern that is valid only in its first part
 *  01.04.04   2021-03-03  visrie  ESCAN00108616    Presence Pattern is considered valid erased bytes in the beginning
 *                                                   followed by valid bytes
 *                                 ESCAN00108753    Make presence pattern values overwriteable
 *                                 FBL-3129         Added/adapted MemMap sections
 *                                                  Update to MISRA 2012
 *  01.04.05   2021-03-16  visrie  ESCAN00108859    Compiler error: function parameter and the called argument are
 *                                                   incompatible
 *  01.05.00   2021-06-16  visrie  FBL-3641         No changes
 *  01.06.00   2022-08-11  visjdn  FBL-5687         Return further pattern state information
 **********************************************************************************************************************/

#define FBL_NVPATTERN_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "fbl_nvpattern.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLLIB_NVPATTERN_VERSION != 0x0106u ) || \
    ( FBLLIB_NVPATTERN_RELEASE_VERSION != 0x00u )
# error "Error in fbl_nvpattern.c: Source and header file are inconsistent!"
#endif

#if ( FBLLIB_NVPATTERN_VERSION != _FBLLIB_NVPATTERN_VERSION ) || \
    ( FBLLIB_NVPATTERN_RELEASE_VERSION != _FBLLIB_NVPATTERN_RELEASE_VERSION )
# error "Error in fbl_nvpattern.c: Source and v_ver.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Definition of marker/mask values and their size */
#if !defined( kFblNvMarkerValue )
# define kFblNvMarkerValue                      {0x73u, 0x6Au, 0x29u, 0x3Eu}
#endif /* kFblNvMarkerValue */
#if !defined( kFblNvMaskValue )
# define kFblNvMaskValue                        {0x8Cu, 0x95u, 0xD6u, 0xC1u}
#endif /* kFblNvMaskValue */
#if !defined( kFblNvPatternSize )
# define kFblNvPatternSize                      4u
#endif /* kFblNvPatternSize */

/* Macro to calculate the page aligned size to hold a value of size len */
#define PAGE_ALIGN(len, align)                  (((len) + ((align) - 1u)) & ~((align) - 1u))

/* Macro to check if val is a power of two */
#define IS_POWOFTWO(val)                        (((val) & ~((val) - 1u)) == (val))

/* Size of write buffer with enough space to hold one marker/mask value */
#if ( FBL_MAX_SEGMENT_SIZE < kFblNvPatternSize )
# define kFblNvPatternSegmentSize               PAGE_ALIGN(kFblNvPatternSize, FBL_MAX_SEGMENT_SIZE)
#else
# define kFblNvPatternSegmentSize               FBL_MAX_SEGMENT_SIZE
#endif

/* Checks if tFblNvPatternId belongs to a block property or a pattern */
#define IS_VALID_PATTERN_ID(id)                 (((id) > kFblNvPatternId_Invalid)   && ((id) < kFblNvPatternId_Separator))
#define IS_VALID_PROPERTY_ID(id)                (((id) > kFblNvPatternId_Separator) && ((id) < kFblNvPatternId_Last))

/* Parameter value to skip comparison for function FblNvPatternGetPatternItemState */
#define DONT_COMPARE                            (vuint8*)0u

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/** Buffer with alignment to platform requirements */
typedef struct
{
   vuint32  alignDummy; /**< Used to force 4Byte alignment */
   vuint8   data[kFblNvPatternSegmentSize];
} tFblNvPatternAlignedBuffer;

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define FBLNVPATTERN_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 static V_MEMRAM1 tFblNvPatternAlignedBuffer V_MEMRAM2 pageBuffer;
#define FBLNVPATTERN_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLNVPATTERN_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static tFblResult FblNvPatternWritePageAligned( const vuint8* pSrcBuffer, IO_PositionType address, IO_SizeType length );
static tFblNvPatternItemState FblNvPatternGetPatternItemState( IO_PositionType patternAddress, IO_SizeType length, const vuint8* compareValue );

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblNvPatternWritePageAligned
 **********************************************************************************************************************/
/*! \brief         Writes data respecting the page size of the memory device
 *  \pre           GetBaseAddr function has been called first
 *  \param[in]     pSrcBuffer pointer to source data
 *  \param[in]     address target address
 *  \param[in]     length length of data
 **********************************************************************************************************************/
static tFblResult FblNvPatternWritePageAligned( const vuint8* pSrcBuffer, IO_PositionType address, IO_SizeType length )
{
   tFblResult result;
   IO_SizeType i;
   IO_SizeType writeGranularity;
   IO_SizeType actualWriteLength;
   IO_SizeType localLength;
   IO_PositionType offset;

   /* Initialize variables */
   result = kFblOk;
   localLength = length;
   offset = 0u;

   while (localLength > 0u)
   {
      (void)FblRealTimeSupport();

      /* Determine page aligned write length, limit to buffer length */
      if (localLength > kFblNvPatternSegmentSize)
      {
         writeGranularity = kFblNvPatternSegmentSize;
         actualWriteLength = kFblNvPatternSegmentSize;
      }
      else
      {
         writeGranularity = PAGE_ALIGN(localLength, (IO_SizeType)MemDriver_SegmentSize);
         actualWriteLength = localLength;
      }

      /* Fill buffer with payload data */
      for (i = 0u; i < actualWriteLength; i++)
      {
         pageBuffer.data[i] = pSrcBuffer[i + offset];
      }
      /* Pad remaining buffer if necessary */
      if (actualWriteLength < kFblNvPatternSegmentSize)
      {
         for (i = actualWriteLength; i < writeGranularity; i++)
         {
            pageBuffer.data[i] = 0u;
         }
      }

      /* Call MIO to write data */
      if (MemDriver_RWriteSync(pageBuffer.data, writeGranularity, address + offset) != IO_E_OK)
      {
         result = kFblFailed;
         break;
      }

      /* Update variables */
      localLength -= actualWriteLength;
      offset += actualWriteLength;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblNvPatternGetPatternItemState
 **********************************************************************************************************************/
/*! \brief         Reads one marker/mask and returns the state of it
 *  \pre           Global variable memSegment is set to the block where the pattern is stored
 *  \param[in]     patternAddress address of pattern item
 *  \param[in]     length the length of the pattern item to read
 *  \param[in]     compareValue pointer to expected pattern value (return ExpectedValue), 0 if no comparison is needed
 *  \return        The state of the pattern item
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
static tFblNvPatternItemState FblNvPatternGetPatternItemState( IO_PositionType patternAddress, IO_SizeType length, const vuint8* compareValue)
{
   tFblNvPatternItemState itemState;
   vuint8 memErasedValue;
   IO_SizeType currentReadLength;
   IO_SizeType localLength = length;
   IO_PositionType readOffset = 0u;
   vuint32 i;
   vuint32 countExpectedValue = 0u;
   vuint32 countErasedValue = 0u;

   /* Determine memory erased value of used device */
#if defined( FBL_ENABLE_MULTIPLE_MEM_DEVICES )
# if defined( FBL_NVPATTERN_ENABLE_USER_DEFINED_ERASE_VALUE )
   memErasedValue = ApplFblGetErasedValueBySegment(memSegment);
# else
   memErasedValue = memDrvLst[FlashBlock[memSegment].device].erasedValue;
# endif
#else
   memErasedValue = FBL_FLASH_DELETED;
#endif

   while (localLength > 0u)
   {
      /* Limit read length to buffer size */
      if (localLength > kFblNvPatternSegmentSize)
      {
         currentReadLength = kFblNvPatternSegmentSize;
      }
      else
      {
         currentReadLength = localLength;
      }

      /* Read marker/mask */
      switch (MemDriver_RReadSync(pageBuffer.data, currentReadLength, patternAddress + readOffset))
      {
         case IO_E_OK:
         case IO_E_ERASED:
         {
            /* Read successful. Because some drivers don't return IO_E_ERASED,
             * we have to assume that memory is erased if all bytes show the erased value
             * and compare against the erased value later. */
            itemState = FBL_NVPATTERN_STATE_ERASED;
            break;
         }
         default:
         {
            /* Read error */
            itemState = FBL_NVPATTERN_STATE_READERROR;
            assertFbl(0u, kFblSysAssertParameterOutOfRange); /* PRQA S 2741, 4558 */ /* MD_FblNvPattern_Assertion */
            break;
         }
      }

      if (itemState == FBL_NVPATTERN_STATE_ERASED)
      {
         /* Check all bytes of marker/mask */
         for (i = 0u; i < currentReadLength; i++)
         {
            /* Compare one byte of pattern against the expected value/erased value */
            if ((compareValue != DONT_COMPARE) && (pageBuffer.data[i] == compareValue[readOffset + i]))
            {
               countExpectedValue++;
            }
            else if (pageBuffer.data[i] == memErasedValue)
            {
               countErasedValue++;
            }
            else /* (pageBuffer.data[i] != memErasedValue) */
            {
               /* This might happen in case of unintended writes to pattern area */
               itemState = FBL_NVPATTERN_STATE_UNEXPECTEDVALUE;
               assertFbl(0u, kFblSysAssertParameterOutOfRange); /* PRQA S 2741, 4558 */ /* MD_FblNvPattern_Assertion */
            }

            /* In case of an unexpected value break out of the for loop */
            if (itemState == FBL_NVPATTERN_STATE_UNEXPECTEDVALUE)
            {
               break;
            }
         }

         /* Check if there were expected and erased bytes included */
         if (   (countErasedValue != 0u)
             && (countExpectedValue != 0u))
         {
            itemState = FBL_NVPATTERN_STATE_UNEXPECTEDVALUE;
         }
      }

      /* Abort in case of error */
      if ((itemState == FBL_NVPATTERN_STATE_UNEXPECTEDVALUE) || (itemState == FBL_NVPATTERN_STATE_READERROR))
      {
         break;
      }

      /* Update variables */
      localLength -= currentReadLength;
      readOffset += currentReadLength;
   }

   /* Set itemState according to the counts */
   if (length == 0u)
   {
      itemState = FBL_NVPATTERN_STATE_NOMEMSEGMENT;
   }
   else if (countErasedValue == length)
   {
      itemState = FBL_NVPATTERN_STATE_ERASED;
   }
   else if (countExpectedValue == length)
   {
      itemState = FBL_NVPATTERN_STATE_EXPECTEDVALUE;
   }
   else
   {
      /* itemState already set correctly */
   }

   return itemState;
}


/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblNvPatternGetPatternState
 **********************************************************************************************************************/
/*! \brief         Determines the state of one or a set of marker/mask pairs.
 *  \details       Iterates through all sub-patterns in case of multiple validation.
 *                 Returns address and length of pattern which stores the currently relevant state.
 *  \param[in]     pBlockDescriptor descriptor of the logical block which contains the NvPattern
 *  \param[in]     patternId Id of pattern to read
 *  \param[out]    pPatternAddress Pointer to RAM buffer which keeps the pattern base address
 *  \param[out]    pPatternLength Pointer to RAM buffer which keeps the actual write length of the pattern
 *  \return        The state of the (sub) pattern which holds the current state of the pattern
 **********************************************************************************************************************/
tFblNvPatternState FblNvPatternGetPatternState( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * pBlockDescriptor,
                                                       tFblNvPatternId patternId,
                                                       V_MEMRAM1 IO_PositionType V_MEMRAM2 V_MEMRAM3 * pPatternAddress,
                                                       V_MEMRAM1 IO_SizeType V_MEMRAM2 V_MEMRAM3 * pPatternLength )
{
   vuint32              multiplicity;
   tFblNvPatternState   patternState;
   IO_PositionType      patternAddress;
   vuint8               fblMarkerValue[] = kFblNvMarkerValue; /* PRQA S 3678 */ /* MD_FblNvPattern_3678_LocalVariable */
   vuint8               fblMaskValue[] = kFblNvMaskValue; /* PRQA S 3678 */ /* MD_FblNvPattern_3678_LocalVariable */

   /* PRQA S 2742, 2880 2 */ /* MD_FblNvPattern_Assertion */
   assertFblUser(sizeof(fblMarkerValue) == kFblNvPatternSize, kFblSysAssertParameterOutOfRange);
   assertFblUser(sizeof(fblMaskValue) == kFblNvPatternSize, kFblSysAssertParameterOutOfRange);

   /* Initialize variables */
   patternAddress = *pPatternAddress;
   patternState.markerState = FBL_NVPATTERN_STATE_NOMEMSEGMENT;
   patternState.maskState = FBL_NVPATTERN_STATE_NOMEMSEGMENT;
   memSegment = -1;

   /* Get Base Address of pattern if id is valid */
   if (IS_VALID_PATTERN_ID(patternId))
   {
      memSegment = FblNvPatternGetBaseAddrByBlockDescriptor(pBlockDescriptor, patternId, &patternAddress, pPatternLength);
   }

   if (memSegment >= 0)
   {
      /* Determine number of sub-patterns */
#if defined( FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION )
      multiplicity = (vuint32)fblNvPatternMultiplicity[((vuintx)patternId - 1u)];
#else
      multiplicity = 1u;
#endif
   }
   else
   {
      /* No memory segment found, abort */
      multiplicity = 0u;
   }

   /* Go through all configured sub-patterns until we have found the sub-pattern which holds the most recent state */
   while (multiplicity >= 1u)
   {
      /* Poll watchdog function */
      (void)FblRealTimeSupport();

      /* Read marker and mask area */
      patternState.markerState = FblNvPatternGetPatternItemState(patternAddress, kFblNvPatternSize, fblMarkerValue);
      patternState.maskState = FblNvPatternGetPatternItemState((patternAddress + *pPatternLength), kFblNvPatternSize, fblMaskValue);

      if (     ((patternState.markerState == FBL_NVPATTERN_STATE_EXPECTEDVALUE) && (patternState.maskState == FBL_NVPATTERN_STATE_ERASED))
            || ((patternState.markerState == FBL_NVPATTERN_STATE_ERASED)        && (patternState.maskState == FBL_NVPATTERN_STATE_ERASED)))
      {
         /* One pattern item is in erased state, this is the most recent state of the pattern */
         break;
      }

      /* Get base address of next sub-pattern */
      patternAddress += (*pPatternLength * 2u);

      /* Decrement number of sub-patterns to process */
      multiplicity--;
   }

   /* Write current address to passed argument pointer */
   *pPatternAddress = patternAddress;

   return patternState;
}

/***********************************************************************************************************************
 *  FblNvPatternGetBaseAddr
 **********************************************************************************************************************/
/*! \brief         Calculates base address and actual (write) length of pattern and mask
 *  \pre           LBT is present
 *  \param[in]     blockNr Logical block number
 *  \param[in]     patternId ID of the pattern which shall be checked
 *  \param[out]    pPatternAddress Pointer to RAM buffer which keeps the pattern base address
 *  \param[out]    pPatternLength Pointer to RAM buffer which keeps the actual write length of the pattern
 *  \return        memSegment of the pattern location or -1 in case of an error
 **********************************************************************************************************************/
vsint16 FblNvPatternGetBaseAddr( vuint8 blockNr,
                                 tFblNvPatternId patternId,
                                 V_MEMRAM1 IO_PositionType V_MEMRAM2 V_MEMRAM3 * pPatternAddress,
                                 V_MEMRAM1 IO_SizeType V_MEMRAM2 V_MEMRAM3 * pPatternLength )
{
   tBlockDescriptor  blockDescriptor;
   tFblResult        result;

   result = FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor);

   if (result == kFblOk)
   {
      memSegment = FblNvPatternGetBaseAddrByBlockDescriptor(&blockDescriptor, patternId, pPatternAddress, pPatternLength);
   }
   else
   {
      /* Invalid block number passed, signal failure via return value */
      memSegment = -1;
   }

   return memSegment;
}

/***********************************************************************************************************************
 *  FblNvPatternGetBaseAddrByBlockDescriptor
 **********************************************************************************************************************/
/*! \brief         Calculates base address and actual (write) length of an NvPattern or block property element
 *  \param[in]     blockDescriptor Logical block descriptor
 *  \param[in]     patternId ID of the NvPattern or block property for which the base address is requested
 *  \param[out]    pPatternAddress Pointer to RAM buffer to store the base address
 *  \param[out]    pPatternLength Pointer to RAM buffer to store the actual write address of the NvPattern or property
 *  \return        memSegment of the pattern location or -1 in case of an error
 **********************************************************************************************************************/
vsint16 FblNvPatternGetBaseAddrByBlockDescriptor( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
                                                  tFblNvPatternId patternId,
                                                  V_MEMRAM1 IO_PositionType V_MEMRAM2 V_MEMRAM3 * pPatternAddress,
                                                  V_MEMRAM1 IO_SizeType V_MEMRAM2 V_MEMRAM3 * pPatternLength )
{
   IO_PositionType   lastBlockAddress;
   IO_SizeType       patternLength;
   IO_SizeType       offsetLength;
   vuintx            i;
   vuintx            upperBound;

   /* Get address of last byte in block */
   lastBlockAddress = blockDescriptor->blockStartAddress + (blockDescriptor->blockLength - 1u);

   /* Get corresponding memory segment index */
   memSegment = FblMemSegmentNrGet(lastBlockAddress);

   /* Check if a valid memory segment in flash block table was found */
   if (memSegment >= 0)
   {
      /* Segment size must be a power of two */
      assertFbl(IS_POWOFTWO(MemDriver_SegmentSize), kFblSysAssertParameterOutOfRange);

      /* Adjust patternLength to write segment size of device */
      patternLength = PAGE_ALIGN(kFblNvPatternSize, (IO_SizeType)MemDriver_SegmentSize);

      /* Offset from end of logical block to requested NvPattern */
      offsetLength = 0u;

      /* Add size of NvPatterns to offset...
       * Upper bound for loop is either the last NvPattern element if base address of block property has been requested
       * or patternId in case the requested element is a NvPattern */
      upperBound = (patternId > kFblNvPatternId_Separator) ? ((vuintx)kFblNvPatternId_Separator - 1u) : (vuintx)patternId;

      for (i = 0u; i < upperBound; i++)
      {
#if defined( FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION )
         offsetLength += (patternLength * ((IO_SizeType)fblNvPatternMultiplicity[i] * 2u));
#else
         offsetLength += (patternLength * 2u);
#endif /* FBL_NVPATTERN_ENABLE_MULTIPLE_VALIDATION */
      }

      /* ... then add sizes of block property elements */
#if defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
      /* Skip this loop (set upperBound to 0) if the requested Id is not a block property,
       * otherwise subtract kFblNvPatternId_Separator from pattern id to get the index into fblNvPatternElementLength */
      upperBound = (patternId > kFblNvPatternId_Separator) ? ((vuintx)patternId - (vuintx)kFblNvPatternId_Separator) : 0u;

      for (i = 0u; i < upperBound; i++)
      {
         offsetLength += PAGE_ALIGN(fblNvBlockProperties[i].length, (IO_SizeType)MemDriver_SegmentSize);
         patternLength = PAGE_ALIGN(fblNvBlockProperties[i].length, (IO_SizeType)MemDriver_SegmentSize);
      }
#endif /* FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */

      /* Put results into arguments */
      *pPatternLength  = patternLength;
      *pPatternAddress = (lastBlockAddress - offsetLength) + 1u;

      /* Check for range overflow */
      assertFbl(*pPatternAddress >= blockDescriptor->blockStartAddress, kFblSysAssertParameterOutOfRange);

      /* All NvPattern data must be stored in the same memSegment */
      assertFbl(FblMemSegmentNrGet(*pPatternAddress) == memSegment, kFblSysAssertParameterOutOfRange);
   }
   else
   {
      /* No memory segment found, this is a configuration error. */
      assertFbl(0u, kFblSysAssertParameterOutOfRange); /* PRQA S 2741, 4558 */ /* MD_FblNvPattern_Assertion */
   }

   return memSegment;
}

/***********************************************************************************************************************
 *  FblNvPatternSet
 **********************************************************************************************************************/
/*! \brief       Writes the pattern into the flash memory.
 *  \details     The location of the pattern will be taken from the logical block table
 *  \param[in]   blockDescriptor Pointer to the logical block descriptor
 *  \param[in]   patternId ID of the pattern which shall be set
 *  \return      kFblOk: pattern successfully written, kFblFailed: Error writing pattern
 **********************************************************************************************************************/
tFblResult FblNvPatternSet( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor, tFblNvPatternId patternId )
{
   tBlockDescriptor localBlockDescriptor;
   tFblResult result;

   result = FblLbtGetBlockDescriptorByNr(blockDescriptor->blockNr, &localBlockDescriptor);

   if (result == kFblOk)
   {
      result = FblNvPatternSetByBlockDescriptor(&localBlockDescriptor, patternId);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblNvPatternSetByBlockDescriptor
 **********************************************************************************************************************/
/*! \brief       Writes the pattern into the flash memory.
 *  \details     The location of the pattern will be taken from the logical block descriptor.
 *  \param[in]   blockDescriptor Pointer to the logical block descriptor
 *  \param[in]   patternId ID of the pattern which shall be set
 *  \return      kFblOk: pattern successfully written or already set, kFblFailed: Error writing pattern
 **********************************************************************************************************************/
tFblResult FblNvPatternSetByBlockDescriptor( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
                                             tFblNvPatternId patternId )
{
   IO_PositionType               patternAddress;
   IO_SizeType                   patternLength;
   tFblResult                    result;
   tFblNvPatternState            patternState;
   vuint8                        fblMarkerValue[] = kFblNvMarkerValue; /* PRQA S 3678 */ /* MD_FblNvPattern_3678_LocalVariable */

   /* PRQA S 2742, 2880 1 */ /* MD_FblNvPattern_Assertion */
   assertFblUser(sizeof(fblMarkerValue) == kFblNvPatternSize, kFblSysAssertParameterOutOfRange);

   /* Initialize variables */
   result = kFblFailed;

   /* Check state of pattern */
   patternState = FblNvPatternGetPatternState(blockDescriptor, patternId, &patternAddress, &patternLength);

   /* Proceed if marker is blank */
   if (patternState.markerState == FBL_NVPATTERN_STATE_ERASED)
   {
      /* Write pattern */
      if (kFblOk == FblNvPatternWritePageAligned(fblMarkerValue, patternAddress, kFblNvPatternSize))
      {
         /* Verify that pattern is valid now */
         patternState = FblNvPatternGetPatternState(blockDescriptor, patternId, &patternAddress, &patternLength);
         if (patternState.markerState == FBL_NVPATTERN_STATE_EXPECTEDVALUE)
         {
            result = kFblOk;
         }
      }
   }
   else if ((patternState.markerState == FBL_NVPATTERN_STATE_EXPECTEDVALUE) && (patternState.maskState == FBL_NVPATTERN_STATE_ERASED))
   {
      /* Pattern already has expected state */
      result = kFblOk;
   }
   else
   {
      /* For the sake of completeness */
   }

   return result;
}

/***********************************************************************************************************************
 *  FblNvPatternClr
 **********************************************************************************************************************/
/*! \brief       Writes the mask to invalidate the pattern
 *  \details     The location of the pattern will be taken from the logical block table
 *  \param[in]   blockDescriptor Pointer to the logical block descriptor
 *  \param[in]   patternId ID of the pattern which shall be set
 *  \return      kFblOk: Mask for invalidation successfully written, kFblFailed: Error writing invalidation mask
 **********************************************************************************************************************/
tFblResult FblNvPatternClr( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor, tFblNvPatternId patternId )
{
   tBlockDescriptor localBlockDescriptor;
   tFblResult result;

   result = FblLbtGetBlockDescriptorByNr(blockDescriptor->blockNr, &localBlockDescriptor);

   if (result == kFblOk)
   {
      result = FblNvPatternClrByBlockDescriptor(&localBlockDescriptor, patternId);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblNvPatternClrByBlockDescriptor
 **********************************************************************************************************************/
/*! \brief       Writes the mask to invalidate the pattern
 *  \details     The location of the pattern will be taken from the passed logical block descriptor
 *  \param[in]   blockDescriptor Pointer to the logical block descriptor
 *  \param[in]   patternId ID of the pattern which shall be set
 *  \return      kFblOk: Mask for invalidation successfully written, kFblFailed: Error writing invalidation mask
 **********************************************************************************************************************/
tFblResult FblNvPatternClrByBlockDescriptor( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
                                             tFblNvPatternId patternId )
{
   tFblResult                    result;
   IO_PositionType               patternAddress;
   IO_SizeType                   patternLength;
   tFblNvPatternState            patternState;
   vuint8                        fblMaskValue[] = kFblNvMaskValue; /* PRQA S 3678 */ /* MD_FblNvPattern_3678_LocalVariable */

   /* PRQA S 2742, 2880 1 */ /* MD_FblNvPattern_Assertion */
   assertFblUser(sizeof(fblMaskValue) == kFblNvPatternSize, kFblSysAssertParameterOutOfRange);

   /* Check state of pattern */
   patternState = FblNvPatternGetPatternState(blockDescriptor, patternId, &patternAddress, &patternLength);

   /* Only set mask if pattern is set to valid */
   if ((patternState.markerState == FBL_NVPATTERN_STATE_EXPECTEDVALUE) && (patternState.maskState == FBL_NVPATTERN_STATE_ERASED))
   {
      /* Write mask value to flash */
      result = FblNvPatternWritePageAligned(fblMaskValue, (patternAddress + patternLength), kFblNvPatternSize);
   }
   else
   {
      /* Pattern is already in invalid state, do nothing. Illegal states are detected with assertions only. */
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblNvPatternGet
 **********************************************************************************************************************/
/*! \brief       Checks if the pattern state is 'valid' (correct pattern value is set/mask is erased)
 *  \details     The location of the pattern and mask is taken from the logical block table
 *  \param[in]   blockDescriptor Pointer to the logical block descriptor
 *  \param[in]   patternId ID of the pattern which shall be checked
 *  \return      kFblOk:     Pattern is set and mask is erased,
 *               kFblFailed: Pattern is not set or mask not erased
 **********************************************************************************************************************/
tFblResult FblNvPatternGet( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor, tFblNvPatternId patternId )
{
   tBlockDescriptor localBlockDescriptor;
   tFblResult result;

   result = FblLbtGetBlockDescriptorByNr(blockDescriptor->blockNr, &localBlockDescriptor);

   if (result == kFblOk)
   {
      result = FblNvPatternGetByBlockDescriptor(&localBlockDescriptor, patternId);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblNvPatternGetByBlockDescriptor
 **********************************************************************************************************************/
/*! \brief       Checks if the pattern state is 'valid' (correct pattern value is set/mask is erased)
 *  \details     The location of the pattern and mask is taken from the passed logical block descriptor
 *  \param[in]   blockDescriptor Pointer to the logical block descriptor
 *  \param[in]   patternId ID of the pattern which shall be checked
 *  \return      kFblOk:     Pattern is set and mask is erased,
 *               kFblFailed: Pattern is not set or mask not erased
 **********************************************************************************************************************/
tFblResult FblNvPatternGetByBlockDescriptor( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
                                             tFblNvPatternId patternId )
{
   IO_PositionType      patternAddress;
   IO_SizeType          patternLength;
   tFblNvPatternState   patternState;
   tFblResult           result;

   /* Initialize result */
   result = kFblFailed;

   /* Check state of pattern */
   patternState = FblNvPatternGetPatternState(blockDescriptor, patternId, &patternAddress, &patternLength);
   if ((patternState.markerState == FBL_NVPATTERN_STATE_EXPECTEDVALUE) && (patternState.maskState == FBL_NVPATTERN_STATE_ERASED))
   {
      result = kFblOk;
   }

   return result;
}

#if defined( FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES )
/***********************************************************************************************************************
 *  FblNvPatternGetProperty
 **********************************************************************************************************************/
/*! \brief         Reads value of a block property element
 *  \details       Location of the property is taken from the logical block table
 *  \param[in]     blockDescriptor Pointer to the logical block descriptor
 *  \param[in]     propertyId Id of property to read
 *  \param[in]     bufferLength Length of destination buffer
 *  \param[out]    pDestBuffer Pointer to RAM where read property value will be stored
 *  \return        kFblOk: Property successfully read, kFblFailed: Error reading property
 **********************************************************************************************************************/
tFblResult FblNvPatternGetProperty( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
                                      tFblNvPatternId propertyId,
                                      IO_SizeType bufferLength,
                                      vuint8* pDestBuffer )
{
   tBlockDescriptor localBlockDescriptor;
   tFblResult result;

   result = FblLbtGetBlockDescriptorByNr(blockDescriptor->blockNr, &localBlockDescriptor);

   if (result == kFblOk)
   {
      result = FblNvPatternGetPropertyByBlockDescriptor(&localBlockDescriptor, propertyId, bufferLength, pDestBuffer);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblNvPatternGetPropertyByBlockDescriptor
 **********************************************************************************************************************/
/*! \brief         Reads value of an block property element
 *  \details       The location of the block property is taken from the passed logical block descriptor
 *  \param[in]     blockDescriptor Pointer to the logical block descriptor
 *  \param[in]     propertyId Id of the property to read
 *  \param[in]     bufferLength Length of destination buffer
 *  \param[out]    pDestBuffer Pointer to RAM where the read property value will be stored
 *  \return        kFblOk: Property successfully read, kFblFailed: Error reading property
 **********************************************************************************************************************/
tFblResult FblNvPatternGetPropertyByBlockDescriptor( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
                                                       tFblNvPatternId propertyId,
                                                       IO_SizeType bufferLength,
                                                       vuint8* pDestBuffer )
{
   IO_PositionType      propertyAddress;
   IO_SizeType          propertyLength;
   IO_SizeType          sizeToRead;
   tFblNvPatternId      depPattern;
   tFblResult           result;

   result = kFblFailed;
   propertyAddress = 0u;

   /* Check if requested Id is valid */
   if (IS_VALID_PROPERTY_ID(propertyId))
   {
      sizeToRead = fblNvBlockProperties[(vuintx)propertyId - (vuintx)kFblNvPatternId_Separator - 1u].length;
      depPattern = fblNvBlockProperties[(vuintx)propertyId - (vuintx)kFblNvPatternId_Separator - 1u].dependentPattern;

      /* Check if buffer length is sufficient for storing requested data */
      if (sizeToRead <= bufferLength)
      {
         /* If dependent pattern configured, check its validity */
         if (depPattern != kFblNvPatternId_Invalid)
         {
            result = FblNvPatternGetByBlockDescriptor(blockDescriptor, depPattern);
         }
         else
         {
            result = kFblOk;
         }
      }
   }

   if (result == kFblOk)
   {
      /* Get address of property (length is not needed) */
      if (FblNvPatternGetBaseAddrByBlockDescriptor(blockDescriptor, propertyId, &propertyAddress, &propertyLength) >= 0)
      {
         if (MemDriver_RReadSync(pDestBuffer, sizeToRead, propertyAddress) == IO_E_OK)
         {
            result = kFblOk;
         }
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblNvPatternSetProperty
 **********************************************************************************************************************/
/*! \brief         Writes value of a block property
 *  \details       The location of the property is taken from the logical block table
 *  \param[in]     blockDescriptor Pointer to the logical block descriptor
 *  \param[in]     pSrcBuffer Pointer to RAM with the data to write
 *  \param[in]     propertyId Id of the block property to write
 *  \return        kFblOk: Property successfully written, kFblFailed: Error writing property
 **********************************************************************************************************************/
tFblResult FblNvPatternSetProperty( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
                                      const vuint8* pSrcBuffer,
                                      tFblNvPatternId propertyId )
{
   tBlockDescriptor localBlockDescriptor;
   tFblResult result;

   result = FblLbtGetBlockDescriptorByNr(blockDescriptor->blockNr, &localBlockDescriptor);

   if (result == kFblOk)
   {
      result = FblNvPatternSetPropertyByBlockDescriptor(&localBlockDescriptor, pSrcBuffer, propertyId);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblNvPatternSetPropertyByBlockDescriptor
 **********************************************************************************************************************/
/*! \brief         Writes value of a block property
 *  \details       The location of the property is taken from the passed logical block descriptor
 *  \param[in]     blockDescriptor Pointer to the logical block descriptor
 *  \param[in]     pSrcBuffer Pointer to RAM with the data to write
 *  \param[in]     propertyId Id of the property to write
 *  \return        kFblOk: Property successfully written, kFblFailed: Error writing property
 **********************************************************************************************************************/
tFblResult FblNvPatternSetPropertyByBlockDescriptor( const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor,
                                                       const vuint8* pSrcBuffer,
                                                       tFblNvPatternId propertyId )
{
   IO_PositionType         propertyAddress;
   IO_SizeType             propertyLength;
   IO_SizeType             actualPropertyLength;
   tFblResult              result;

   /* Initialize variables */
   result = kFblFailed;
   propertyAddress = 0u;

   /* Check if requested Id is valid */
   if (IS_VALID_PROPERTY_ID(propertyId))
   {
      /* Get address and length of element */
      if (FblNvPatternGetBaseAddrByBlockDescriptor(blockDescriptor, propertyId, &propertyAddress, &propertyLength) >= 0)
      {
         /* Only write block property to memory if it has not been set before */
         actualPropertyLength = fblNvBlockProperties[(vuintx)propertyId - (vuintx)kFblNvPatternId_Separator - 1u].length;
         if (FblNvPatternGetPatternItemState(propertyAddress, actualPropertyLength, DONT_COMPARE) == FBL_NVPATTERN_STATE_ERASED)
         {
            result = FblNvPatternWritePageAligned(pSrcBuffer, propertyAddress, actualPropertyLength);
         }
      }
   }

   return result;
}
#endif /* FBL_NVPATTERN_ENABLE_BLOCK_PROPERTIES */

#define FBLNVPATTERN_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  ERROR CHECKS
 **********************************************************************************************************************/

#if (!IS_POWOFTWO(FBL_MAX_SEGMENT_SIZE))
# error "FBL_MAX_SEGMENT_SIZE must be a power of two."
#endif

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* module specific MISRA deviations:

   MD_FblNvPattern_Assertion:
      Reason: Assertion macros have to be disabled in production code and are used only for development.
      Risk: Assertion code may be enabled in production code unintentionally. If a assertion condition is unexpectedly
            false, the code is active. A problem may occur if the Macro is additionally changed from single statement
            to multiple statement.
      Prevention: Macro is not allowed to be changed without review. Development code is automatically disabled via
                  configuration of project state "Production".

   MD_FblNvPattern_3678_LocalVariable:
      Reason: Local variable/array is not declared as const as some compiler/platforms have issues with that.
      Risk: Content of the variable/array could be modified within the function.
      Prevention: Code is checked for unintended write accesses by code inspection.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_NVPATTERN.C
 **********************************************************************************************************************/

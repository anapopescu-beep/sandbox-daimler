/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Interface layer for accessing the logical block table (LBT)
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
 *  01.00.00   2018-05-24  visci   -                Initial version
 *  01.01.00   2018-11-27  visshs  ESCAN00101459    Add Support for Secure Boot
 *  01.02.00   2019-02-26  visrie  ESCAN00102278    Added additional getter functions
 *  01.02.01   2019-09-05  visrcn  ESCAN00103604    Modified memory qualifiers
 *  01.03.00   2022-03-31  visstn  FBL-4366         Perform MISRA 2012 migration
 *  01.04.00   2022-10-17  visjns  FBL-4925         Change LBT access to use RAM
 **********************************************************************************************************************/

#define FBL_LBT_ACCESS_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLLIB_LBT_VERSION != 0x0104u ) || \
    ( FBLLIB_LBT_RELEASE_VERSION != 0x00u )
# error "Error in fbl_lbt_access.c: Source and header file are inconsistent!"
#endif

#if ( FBLLIB_LBT_VERSION != _FBLLIB_LBT_VERSION ) || \
    ( FBLLIB_LBT_RELEASE_VERSION != _FBLLIB_LBT_RELEASE_VERSION )
# error "Error in fbl_lbt_access.c: Source and v_ver.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Access of LBT in RAM  */
#if defined(FBL_LBT_ENABLE_RAM_BUFFER)
# define FBL_LBT_RAM_BUF_SIZE sizeof(tLogicalBlockTable)
#endif /* FBL_LBT_ENABLE_RAM_BUFFER */

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

#if defined(FBL_LBT_ENABLE_RAM_BUFFER)
typedef const V_MEMRAM1 tLogicalBlockTable V_MEMRAM2 V_MEMRAM3 * tLogicalBlockTableConstPointer;
#endif /* FBL_LBT_ENABLE_RAM_BUFFER */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define FBLLBT_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

V_MEMRAM0 static V_MEMRAM1 tFblLbtBlockNr V_MEMRAM2 fblLbtBlockIteratorNr;
V_MEMRAM0 static V_MEMRAM1 tFblLbtBlockFilter V_MEMRAM2 fblLbtBlockIteratorFilter;
V_MEMRAM0 static V_MEMRAM1 boolean V_MEMRAM2 fblLbtBlockIteratorDone;
#if defined(FBL_LBT_ENABLE_RAM_BUFFER)
V_MEMRAM0 static V_MEMRAM1 tLogicalBlockTable V_MEMRAM2 fblLbtRamBuffer;
V_MEMROM0 static tLogicalBlockTableConstPointer V_MEMROM1 V_MEMROM2 fblLbtActive = &fblLbtRamBuffer;
#else
V_MEMRAM0 static V_MEMROM1 tLogicalBlockTable V_MEMROM2 V_MEMROM3 * V_MEMRAM1 V_MEMRAM2 fblLbtActive;
#endif /* FBL_LBT_ENABLE_RAM_BUFFER */

#define FBLLBT_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLLBT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static boolean FblLbtBlockFilterHit(const V_MEMRAM1 tFblLbtBlockFilter V_MEMRAM2 V_MEMRAM3 * blockFilter,
                                    const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor);
#if defined( FBL_LBT_ENABLE_REPROGRAMMABLE_LBT )
static tFblResult FblLbtBlockCompare(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * block1,
                                     const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * block2);
static tFblResult FblLbtCheckReferences(void);
#endif /* FBL_LBT_ENABLE_REPROGRAMMABLE_LBT */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblLbtBlockFilterHit
 **********************************************************************************************************************/
/*! \brief       Check whether a certain block matches the filter settings
 *  \param[in]   blockFilter Block filter settings
 *  \param[in]   blockDescriptor Structure with block information
 *  \return      Possible return values:
 *               - TRUE if the block matches the filter criteria
 *               - FALSE otherwise
 **********************************************************************************************************************/
static boolean FblLbtBlockFilterHit(const V_MEMRAM1 tFblLbtBlockFilter V_MEMRAM2 V_MEMRAM3 * blockFilter,
                                    const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor)
{
   boolean result;

   /* Default setting: open filter */
   result = TRUE;

   /* Check if mandatory/optional filter is enabled */
   if (blockFilter->mandatoryType.enabled == TRUE)
   {
      /* Check if this is a mandatory block */
      if (blockDescriptor->mandatoryType == TRUE)
      {
         /* Block is mandatory: compare against filter value */
         result = (blockFilter->mandatoryType.value == TRUE) ? TRUE : FALSE;
      }
      else
      {
         /* Block is optional: compare against filter value */
         result = (blockFilter->mandatoryType.value == FALSE) ? TRUE : FALSE;
      }
   }

#if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
   /* Check if block type filter is enabled */
   if (blockFilter->blockType.enabled == TRUE)
   {
      /* AND logic: check if filter is still 'open' */
      if (result == TRUE)
      {
         result = (boolean)((blockDescriptor->blockType == blockFilter->blockType.value) ? TRUE : FALSE);
      }
   }
#endif /* FBL_LBT_ENABLE_BLOCK_TYPE */

   return result;
}

#if defined( FBL_LBT_ENABLE_REPROGRAMMABLE_LBT )
/***********************************************************************************************************************
 *  FblLbtBlockCompare
 **********************************************************************************************************************/
/*! \brief       Compare the parameters of two blocks (member-compare)
 *  \param[in]   block1 Structure with parameters of first block
 *  \param[in]   block2 Structure with parameters of second block
 *  \return      Possible return values:
 *               - kFblOk if the two blocks are equal
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblLbtBlockCompare(const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * block1,
                                     const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * block2)
{
   tFblResult result;

   result = kFblOk;
   if (   (block1->blockNr           != block2->blockNr)
       || (block1->mandatoryType     != block2->mandatoryType)
       || (block1->blockStartAddress != block2->blockStartAddress)
       || (block1->blockLength       != block2->blockLength)
#if defined( FBL_LBT_ENABLE_BLOCK_INDEX )
       || (block1->blockIndex        != block2->blockIndex)
#endif
#if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
       || (block1->blockType         != block2->blockType)
#endif
#if defined( FBL_LBT_ENABLE_HEADER_ADDRESS )
       || (block1->headerAddress     != block2->headerAddress)
#endif
#if defined( FBL_LBT_ENABLE_BM_HEADER_ADDRESS )
       || (block1->bmHeaderAddress   != block2->bmHeaderAddress)
#endif
#if defined( FBL_LBT_ENABLE_MAX_PROG_ATTEMPTS )
       || (block1->maxProgAttempts   != block2->maxProgAttempts)
#endif
#if defined( FBL_LBT_ENABLE_VERIFY_INPUT )
       || (block1->verifyInput       != block2->verifyInput)
#endif
#if defined( FBL_LBT_ENABLE_VERIFY_PROCESSED )
       || (block1->verifyProcessed   != block2->verifyProcessed)
#endif
#if defined( FBL_LBT_ENABLE_VERIFY_PIPELINED )
       || (block1->verifyPipelined   != block2->verifyPipelined)
#endif
#if defined( FBL_LBT_ENABLE_VERIFY_OUTPUT )
       || (block1->verifyOutput      != block2->verifyOutput)
#endif
      )
   {
      /* At least one of the block descriptor parameters doesn't match */
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblLbtCheckReferences
 **********************************************************************************************************************/
/*! \brief       Check if the references which are used in the reprogrammable LBT are valid with the bootloader
 *  \return      Possible return values:
 *               - kFblOk if all references are valid
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblLbtCheckReferences(void)
{
   tFblResult result;
   tFblLbtBlockFilter blockFilter;
   tBlockDescriptor newLbtBlock;
   vuint8 tableIdx;

   result = kFblOk;

   FblLbtBlockFilterInit(&blockFilter);

   newLbtBlock = FblLbtBlockFirst(&blockFilter);
   while ( FblLbtBlockDone() == FALSE )
   {
#if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
      /* Compare actual block type against pre-defined list */
      result = kFblFailed;
      for (tableIdx = 0u; tableIdx < fblLbtBlockTypes.typeCount; tableIdx++)
      {
         if (newLbtBlock.blockType == fblLbtBlockTypes.type[tableIdx])
         {
            result = kFblOk;
            break;
         }
      }
#endif /* FBL_LBT_ENABLE_BLOCK_TYPE */

#if defined( FBL_LBT_ENABLE_VERIFY_INPUT )
      if (result == kFblOk)
      {
         /* Compare actual verification function against pre-defined list */
         result = kFblFailed;
         for (tableIdx = 0u; tableIdx < fblLbtVerificationFunc.funcCount; tableIdx++)
         {
            if (newLbtBlock.verifyInput == fblLbtVerificationFunc.func[tableIdx])
            {
               result = kFblOk;
               break;
            }
         }
      }
#endif /* FBL_LBT_ENABLE_VERIFY_INPUT */
#if defined( FBL_LBT_ENABLE_VERIFY_PROCESSED )
      if (result == kFblOk)
      {
         /* Compare actual verification function against pre-defined list */
         result = kFblFailed;
         for (tableIdx = 0u; tableIdx < fblLbtVerificationFunc.funcCount; tableIdx++)
         {
            if (newLbtBlock.verifyProcessed == fblLbtVerificationFunc.func[tableIdx])
            {
               result = kFblOk;
               break;
            }
         }
      }
#endif /* FBL_LBT_ENABLE_VERIFY_PROCESSED */
#if defined( FBL_LBT_ENABLE_VERIFY_PIPELINED )
      if (result == kFblOk)
      {
         /* Compare actual verification function against pre-defined list */
         result = kFblFailed;
         for (tableIdx = 0u; tableIdx < fblLbtVerificationFunc.funcCount; tableIdx++)
         {
            if (newLbtBlock.verifyPipelined == fblLbtVerificationFunc.func[tableIdx])
            {
               result = kFblOk;
               break;
            }
         }
      }
#endif /* FBL_LBT_ENABLE_VERIFY_PIPELINED */
#if defined( FBL_LBT_ENABLE_VERIFY_OUTPUT )
      if (result == kFblOk)
      {
         /* Compare actual verification function against pre-defined list */
         result = kFblFailed;
         for (tableIdx = 0u; tableIdx < fblLbtVerificationFunc.funcCount; tableIdx++)
         {
            if (newLbtBlock.verifyOutput == fblLbtVerificationFunc.func[tableIdx])
            {
               result = kFblOk;
               break;
            }
         }
      }
#endif /* FBL_LBT_ENABLE_VERIFY_OUTPUT */

      if (result != kFblOk)
      {
         /* Unknown reference used: abort */
         break;
      }

      newLbtBlock = FblLbtBlockNext();
   }

   return result;
}
#endif /* FBL_LBT_ENABLE_REPROGRAMMABLE_LBT */

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblLbtInitPowerOn
 **********************************************************************************************************************/
/*! \brief       Power-on initialization of the LBT access module
 **********************************************************************************************************************/
void FblLbtInitPowerOn(void)
{
#if defined(FBL_LBT_ENABLE_RAM_BUFFER)
   /* Initialize pointer with built-in LBT copied into RAM buffer */ /* PRQA S 0306 1 */ /* MD_FblLib_Lbt_0306 */
   (void)FblReadBlock((tFblAddress)&FblLogicalBlockTable, (vuint8*)&fblLbtRamBuffer, FBL_LBT_RAM_BUF_SIZE);
#else
   /* Initialize pointer with built-in LBT */
   fblLbtActive = &FblLogicalBlockTable;
#endif /* FBL_LBT_ENABLE_RAM_BUFFER */
}

/***********************************************************************************************************************
 *  FblLbtBlockFilterInit
 **********************************************************************************************************************/
/*! \brief       Initialize/reset the block filter structure
 *  \param[out]  blockFilter Structure with block filter parameters
 **********************************************************************************************************************/
void FblLbtBlockFilterInit(V_MEMRAM1 tFblLbtBlockFilter V_MEMRAM2 V_MEMRAM3 * blockFilter)
{
   blockFilter->mandatoryType.enabled = FALSE;
#if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
   blockFilter->blockType.enabled = FALSE;
#endif
}

/***********************************************************************************************************************
 *  FblLbtBlockFilterSetMandatoryType
 **********************************************************************************************************************/
/*! \brief       Set and enable the filter for the mandatory type
 *  \param[out]  blockFilter Structure with block filter parameters
 *  \param[in]   mandatoryType The mandatory type value which shall be filtered (optional/mandatory)
 **********************************************************************************************************************/
void FblLbtBlockFilterSetMandatoryType(V_MEMRAM1 tFblLbtBlockFilter V_MEMRAM2 V_MEMRAM3 * blockFilter,
                                       tFblLbtMandatoryType mandatoryType)
{
   blockFilter->mandatoryType.value = mandatoryType;
   blockFilter->mandatoryType.enabled = TRUE;
}

#if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
/***********************************************************************************************************************
 *  FblLbtBlockFilterSetBlockType
 **********************************************************************************************************************/
/*! \brief       Set and enable the filter for the block type
 *  \param[out]  blockFilter Structure with block filter parameters
 *  \param[in]   blockType The block type value which shall be filtered
 **********************************************************************************************************************/
void FblLbtBlockFilterSetBlockType(V_MEMRAM1 tFblLbtBlockFilter V_MEMRAM2 V_MEMRAM3 * blockFilter,
                                   tFblLbtBlockType blockType)
{
   blockFilter->blockType.value = blockType;
   blockFilter->blockType.enabled = TRUE;
}
#endif /* FBL_LBT_ENABLE_BLOCK_TYPE */

/***********************************************************************************************************************
 *  FblLbtBlockFirst
 **********************************************************************************************************************/
/*! \brief       Initialization/start function of the block iterator
 *  \param[in]   blockFilter Structure with block filter parameters
 *  \return      First block which matches the given filter settings
 **********************************************************************************************************************/
tBlockDescriptor FblLbtBlockFirst(const V_MEMRAM1 tFblLbtBlockFilter V_MEMRAM2 V_MEMRAM3 * blockFilter)
{
   fblLbtBlockIteratorNr = 0u;
   fblLbtBlockIteratorFilter = *blockFilter;
   fblLbtBlockIteratorDone = FALSE;

   return FblLbtBlockNext();
}

/***********************************************************************************************************************
 *  FblLbtBlockNext
 **********************************************************************************************************************/
/*! \brief       Continue/next function of the block iterator
 *  \return      Next block which matches the filter settings which have been passed to FblLbtBlockFirst
 **********************************************************************************************************************/
tBlockDescriptor FblLbtBlockNext(void)
{
   tBlockDescriptor blockDescriptor;
   boolean filterResult;

   /* Initialize block descriptor to avoid compiler warning (invalid descriptor will NOT be used, loop is aborted before) */
   blockDescriptor = FblLogicalBlockTable.logicalBlock[0u];

   filterResult = FALSE;

   while (fblLbtBlockIteratorNr < fblLbtActive->noOfBlocks)
   {
      /* Retrieve next block from LBT */
      blockDescriptor = fblLbtActive->logicalBlock[fblLbtBlockIteratorNr];

      /* Increment iterator */
      fblLbtBlockIteratorNr++;

      /* Test block descriptor against filter settings */
      filterResult = FblLbtBlockFilterHit(&fblLbtBlockIteratorFilter, &blockDescriptor);
      if (filterResult == TRUE)
      {
         /* Current block descriptor matches the filter settings, return to caller */
         break;
      }
   }

   if ((fblLbtBlockIteratorNr >= fblLbtActive->noOfBlocks) && (filterResult == FALSE))
   {
      /* No more blocks found, abort iteration */
      fblLbtBlockIteratorDone = TRUE;
   }

   return blockDescriptor;
}

/***********************************************************************************************************************
 *  FblLbtBlockDone
 **********************************************************************************************************************/
/*! \brief       Implementation of the exit condition of the block iterator
 *  \return      Boolean value which reflects the exit condition
 *               - FALSE: Last block not reached yet
 *               - TRUE : Last block has been reached
 **********************************************************************************************************************/
boolean FblLbtBlockDone(void)
{
   return fblLbtBlockIteratorDone;
}

/***********************************************************************************************************************
 *  FblLbtGetBlockCount
 **********************************************************************************************************************/
/*! \brief       Getter function for the actual block count of the active LBT
 *  \return      Number of blocks in the active LBT
 **********************************************************************************************************************/
tFblLbtBlockCount FblLbtGetBlockCount(void)
{
   return (tFblLbtBlockCount)fblLbtActive->noOfBlocks;
}

/***********************************************************************************************************************
 *  FblLbtGetMagicFlag
 **********************************************************************************************************************/
/*! \brief       Getter function to read the magic flag
 *  \return      Magic flag value
 **********************************************************************************************************************/
tFblLbtMagicFlag FblLbtGetMagicFlag(void)
{
   return (tFblLbtMagicFlag)fblLbtActive->magicFlag;
}

/***********************************************************************************************************************
 *  FblLbtGetBlockNrByAddressLength
 **********************************************************************************************************************/
/*! \brief       Look up and return the block number for a given memory range
 *  \param[in]   address Start address of the memory range
 *  \param[in]   length Length of the memory range
 *  \param[out]  Block number of the respective block (if found)
 *  \return      Possible return values:
 *               - kFblOk if block number could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockNrByAddressLength(tFblAddress address, tFblLength length,
                                           V_MEMRAM1 tFblLbtBlockNr V_MEMRAM2 V_MEMRAM3 * blockNr)
{
   tFblResult result;
   tBlockDescriptor localBlockDescriptor;
   tFblLbtBlockFilter blockFilter;

   result = kFblFailed;

   /* Configure block filter (clear all filter settings) */
   FblLbtBlockFilterInit(&blockFilter);

   localBlockDescriptor = FblLbtBlockFirst(&blockFilter);
   while (FblLbtBlockDone() == FALSE)
   {
      result = FblLbtCheckRangeContained(address, length,
                                         localBlockDescriptor.blockStartAddress,
                                         localBlockDescriptor.blockLength);
      if (result == kFblOk)
      {
         *blockNr = localBlockDescriptor.blockNr;
         break;
      }

      localBlockDescriptor = FblLbtBlockNext();
   }

   return result;
}

/***********************************************************************************************************************
 *  FblLbtGetBlockDescriptorByNr
 **********************************************************************************************************************/
/*! \brief       Look up and return the block descriptor with a certain block number value
 *  \param[in]   blockNr Block number value of the block to be retrieved
 *  \param[out]  blockDescriptor Parameter structure with the information of the respective block
 *  \return      Possible return values:
 *               - kFblOk if descriptor could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockDescriptorByNr(tFblLbtBlockNr blockNr,
                                        V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor)
{
   tFblResult result;

   result = kFblFailed;

   if (blockNr < fblLbtActive->noOfBlocks)
   {
     *blockDescriptor = fblLbtActive->logicalBlock[blockNr];
     result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblLbtGetBlockDescriptorByAddressLength
 **********************************************************************************************************************/
/*! \brief       Look up and return the block descriptor for a given memory range
 *  \param[in]   address Start address of the memory range
 *  \param[in]   length Length of the memory range
 *  \param[out]  blockDescriptor Parameter structure with the information of the respective block
 *  \return      Possible return values:
 *               - kFblOk if block descriptor could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockDescriptorByAddressLength(tFblAddress address, tFblLength length,
                                                   V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor)
{
   tFblResult result;
   tFblLbtBlockNr localBlockNr;

   result = FblLbtGetBlockNrByAddressLength(address, length, &localBlockNr);

   if (result == kFblOk)
   {
      result = FblLbtGetBlockDescriptorByNr(localBlockNr, blockDescriptor);
   }

   return result;
}

#if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
/***********************************************************************************************************************
 *  FblLbtGetBlockDescriptorByType
 **********************************************************************************************************************/
/*! \brief       Look up and return the first block descriptor with a certain block type value
 *  \param[in]   blockType Type value of the block to be retrieved
 *  \param[out]  blockDescriptor Parameter structure with the information of the respective block
 *  \return      Possible return values:
 *               - kFblOk if descriptor could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockDescriptorByType(tFblLbtBlockType blockType,
                                          V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor)
{
   tFblResult result;
   tBlockDescriptor localBlockDescriptor;
   tFblLbtBlockFilter blockFilter;

   result = kFblFailed;

   /* Configure block filter (clear all filter settings) */
   FblLbtBlockFilterInit(&blockFilter);

   localBlockDescriptor = FblLbtBlockFirst(&blockFilter);
   while ( FblLbtBlockDone() == FALSE )
   {
      if (localBlockDescriptor.blockType == blockType)
      {
         *blockDescriptor = localBlockDescriptor;
         result = kFblOk;
         break;
      }

      localBlockDescriptor = FblLbtBlockNext();
   }

   return result;
}
#endif /* FBL_LBT_ENABLE_BLOCK_TYPE */

#if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
/***********************************************************************************************************************
 *  FblLbtGetBlockTypeByNr
 **********************************************************************************************************************/
/*! \brief       Look up and return the block type with a certain block index value
 *  \param[in]   blockNr Block number value of the block to be retrieved
 *  \param[out]  blockType Type of the respective block
 *  \return      Possible return values:
 *               - kFblOk if block type could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockTypeByNr(tFblLbtBlockNr blockNr,
                                  V_MEMRAM1 tFblLbtBlockType V_MEMRAM2 V_MEMRAM3 * blockType)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize block type to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.blockType = 0uL;

   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      *blockType = blockDescriptor.blockType;
      result = kFblOk;
   }

   return result;
}
#endif /* FBL_LBT_ENABLE_BLOCK_TYPE */

#if defined( FBL_LBT_ENABLE_BLOCK_INDEX )
/***********************************************************************************************************************
*  FblLbtGetBlockIndexByNr
**********************************************************************************************************************/
/*! \brief       Look up and return the block index with a certain block index value
*  \param[in]   blockNr Block number value of the block to be retrieved
*  \param[out]  blockIndex Index of the respective block
*  \return      Possible return values:
*               - kFblOk if block type could be retrieved successfully
*               - kFblFailed otherwise
**********************************************************************************************************************/
tFblResult FblLbtGetBlockIndexByNr(tFblLbtBlockNr blockNr, V_MEMRAM1 tFblLbtBlockIndex V_MEMRAM2 V_MEMRAM3 * blockIndex)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize block type to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.blockIndex = 0uL;

   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      *blockIndex = blockDescriptor.blockIndex;
      result = kFblOk;
   }

   return result;
}
#endif /* FBL_LBT_ENABLE_BLOCK_INDEX */

#if defined( FBL_LBT_ENABLE_HEADER_ADDRESS )
/***********************************************************************************************************************
 *  FblLbtGetBlockHeaderAddressByNr
 **********************************************************************************************************************/
/*! \brief       Look up and return the block header address with a certain block index value
 *  \param[in]   blockNr Block number value of the block to be retrieved
 *  \param[out]  blockHeaderAddress Header address of the respective block
 *  \return      Possible return values:
 *               - kFblOk if header address could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockHeaderAddressByNr(tFblLbtBlockNr blockNr,
                                           V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * blockHeaderAddress)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize header address to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.headerAddress = 0uL;

   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      *blockHeaderAddress = blockDescriptor.headerAddress;
      result = kFblOk;
   }

   return result;
}
#endif /* FBL_LBT_ENABLE_BLOCK_HEADER_ADDRESS */

#if defined( FBL_LBT_ENABLE_BM_HEADER_ADDRESS )
/***********************************************************************************************************************
 *  FblLbtGetBlockBmHeaderAddressByNr
 **********************************************************************************************************************/
/*! \brief       Look up and return the bootmanager header address with a certain block index value
 *  \param[in]   blockNr Block number value of the block to be retrieved
 *  \param[out]  bmHeaderAddress BM Header address of the respective block
 *  \return      Possible return values:
 *               - kFblOk if header address could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockBmHeaderAddressByNr(tFblLbtBlockNr blockNr,
                                             V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * bmHeaderAddress)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize BM header address to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.bmHeaderAddress = 0uL;

   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      *bmHeaderAddress = blockDescriptor.bmHeaderAddress;
      result = kFblOk;
   }

   return result;
}
#endif /* FBL_LBT_ENABLE_BM_HEADER_ADDRESS */

#if defined( FBL_LBT_ENABLE_MAX_PROG_ATTEMPTS )
/***********************************************************************************************************************
 *  FblLbtGetBlockMaxProgAttemptsByNr
 **********************************************************************************************************************/
/*! \brief       Look up and return the maximum programming attempts with a certain block index value
 *  \param[in]   blockNr Block number value of the block to be retrieved
 *  \param[out]  maxProgAttempts Maxmimum programming attempts of the respective block
 *  \return      Possible return values:
 *               - kFblOk if maximum programming attempts could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockMaxProgAttemptsByNr(tFblLbtBlockNr blockNr,
                                             V_MEMRAM1 tFblLbtMaxProgAttempts V_MEMRAM2 V_MEMRAM3 * maxProgAttempts)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize maximum programming attempts to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.maxProgAttempts = 0u;

   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      *maxProgAttempts = blockDescriptor.maxProgAttempts;
      result = kFblOk;
   }

   return result;
}
#endif /* FBL_LBT_ENABLE_MAX_PROG_ATTEMPTS */

#if defined( FBL_LBT_ENABLE_VERIFY_INPUT )
/***********************************************************************************************************************
 *  FblLbtGetBlockVerifyInputFuncByNr
 **********************************************************************************************************************/
/*! \brief       Look up and return the verification function
 *  \param[in]   blockNr Block number value of the block to be retrieved
 *  \param[out]  blockVerifyFunc Address of the block specific verification function
 *  \return      Possible return values:
 *               - kFblOk if verification function could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockVerifyInputFuncByNr(tFblLbtBlockNr blockNr,
                                             V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize verify function to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.verifyInput = (tExportFct)0;

   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      *blockVerifyFunc = blockDescriptor.verifyInput;
      result = kFblOk;
   }

   return result;
}
#endif /* FBL_LBT_ENABLE_VERIFY_INPUT */

#if defined( FBL_LBT_ENABLE_VERIFY_PROCESSED )
/***********************************************************************************************************************
 *  FblLbtGetBlockVerifyProcessedFuncByNr
 **********************************************************************************************************************/
/*! \brief       Look up and return the verification function
 *  \param[in]   blockNr Block number value of the block to be retrieved
 *  \param[out]  blockVerifyFunc Address of the block specific verification function
 *  \return      Possible return values:
 *               - kFblOk if verification function could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockVerifyProcessedFuncByNr(tFblLbtBlockNr blockNr,
                                                 V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize verify function to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.verifyProcessed = (tExportFct)0;

   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      *blockVerifyFunc = blockDescriptor.verifyProcessed;
      result = kFblOk;
   }

   return result;
}
#endif /* FBL_LBT_ENABLE_VERIFY_PROCESSED */

#if defined( FBL_LBT_ENABLE_VERIFY_PIPELINED )
/***********************************************************************************************************************
 *  FblLbtGetBlockVerifyPipelinedFuncByNr
 **********************************************************************************************************************/
/*! \brief       Look up and return the verification function
 *  \param[in]   blockNr Block number value of the block to be retrieved
 *  \param[out]  blockVerifyFunc Address of the block specific verification function
 *  \return      Possible return values:
 *               - kFblOk if verification function could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockVerifyPipelinedFuncByNr(tFblLbtBlockNr blockNr,
                                                 V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize verify function to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.verifyPipelined = (tExportFct)0;

   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      *blockVerifyFunc = blockDescriptor.verifyPipelined;
      result = kFblOk;
   }

   return result;
}
#endif /* FBL_LBT_ENABLE_VERIFY_PIPELINED */

#if defined( FBL_LBT_ENABLE_VERIFY_OUTPUT )
/***********************************************************************************************************************
 *  FblLbtGetBlockVerifyOutputFuncByNr
 **********************************************************************************************************************/
/*! \brief       Look up and return the block header address with a certain block index value
 *  \param[in]   blockNr Block number value of the block to be retrieved
 *  \param[out]  blockVerifyFunc Address of the block specific verification function
 *  \return      Possible return values:
 *               - kFblOk if verification function could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockVerifyOutputFuncByNr(tFblLbtBlockNr blockNr,
                                              V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize verify function to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.verifyOutput = (tExportFct)0uL;

   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      *blockVerifyFunc = blockDescriptor.verifyOutput;
      result = kFblOk;
   }

   return result;
}
#endif /* FBL_LBT_ENABLE_VERIFY_OUTPUT */

#if defined( FBL_LBT_ENABLE_BLOCK_INDEX )
/***********************************************************************************************************************
 *  FblLbtGetBlockDescriptorByIndex
 **********************************************************************************************************************/
/*! \brief       Look up and return the block descriptor with a certain block index value
 *  \param[in]   blockIndex Index value of the block to be retrieved
 *  \param[out]  blockDescriptor Parameter structure with the information of the respective block
 *  \return      Possible return values:
 *               - kFblOk if descriptor could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockDescriptorByIndex(tFblLbtBlockIndex blockIndex,
                                           V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor)
{
   tFblResult result;
   tBlockDescriptor localBlockDescriptor;
   tFblLbtBlockFilter blockFilter;

   result = kFblFailed;

   /* Configure block filter (clear all filter settings) */
   FblLbtBlockFilterInit(&blockFilter);

   localBlockDescriptor = FblLbtBlockFirst(&blockFilter);
   while ( FblLbtBlockDone() == FALSE )
   {
      if (localBlockDescriptor.blockIndex == blockIndex)
      {
         *blockDescriptor = localBlockDescriptor;
         result = kFblOk;
         break;
      }

      localBlockDescriptor = FblLbtBlockNext();
   }

   return result;
}

/***********************************************************************************************************************
 *  FblLbtGetBlockNrByIndex
 **********************************************************************************************************************/
/*! \brief       Look up and return the block number with a certain block index value
 *  \param[in]   blockIndex Index value of the block to be retrieved
 *  \param[out]  blockNr Number of the respective block
 *  \return      Possible return values:
 *               - kFblOk if block number could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockNrByIndex(tFblLbtBlockIndex blockIndex,
   V_MEMRAM1 tFblLbtBlockNr V_MEMRAM2 V_MEMRAM3 * blockNr)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize block number to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.blockNr = 0u;

   if (FblLbtGetBlockDescriptorByIndex(blockIndex, &blockDescriptor) == kFblOk)
   {
      *blockNr = blockDescriptor.blockNr;
      result = kFblOk;
   }

   return result;
}

# if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
/***********************************************************************************************************************
 *  FblLbtGetBlockTypeByIndex
 **********************************************************************************************************************/
/*! \brief       Look up and return the block type with a certain block index value
 *  \param[in]   blockIndex Index value of the block to be retrieved
 *  \param[out]  blockType Type of the respective block
 *  \return      Possible return values:
 *               - kFblOk if block type could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockTypeByIndex(tFblLbtBlockIndex blockIndex,
                                     V_MEMRAM1 tFblLbtBlockType V_MEMRAM2 V_MEMRAM3 * blockType)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize block type to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.blockType = 0uL;

   if (FblLbtGetBlockDescriptorByIndex(blockIndex, &blockDescriptor) == kFblOk)
   {
      *blockType = blockDescriptor.blockType;
      result = kFblOk;
   }

   return result;
}
# endif /* FBL_LBT_ENABLE_BLOCK_TYPE */

# if defined( FBL_LBT_ENABLE_HEADER_ADDRESS )
/***********************************************************************************************************************
 *  FblLbtGetBlockHeaderAddressByIndex
 **********************************************************************************************************************/
/*! \brief       Look up and return the block header address with a certain block index value
 *  \param[in]   blockIndex Index value of the block to be retrieved
 *  \param[out]  blockHeaderAddress Header address of the respective block
 *  \return      Possible return values:
 *               - kFblOk if header address could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockHeaderAddressByIndex(tFblLbtBlockIndex blockIndex,
                                              V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * blockHeaderAddress)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize header address to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.headerAddress = 0uL;

   if (FblLbtGetBlockDescriptorByIndex(blockIndex, &blockDescriptor) == kFblOk)
   {
      *blockHeaderAddress = blockDescriptor.headerAddress;
      result = kFblOk;
   }

   return result;
}
# endif /* FBL_LBT_ENABLE_BLOCK_HEADER_ADDRESS */

# if defined( FBL_LBT_ENABLE_BM_HEADER_ADDRESS )
/***********************************************************************************************************************
 *  FblLbtGetBlockBmHeaderAddressByIndex
 **********************************************************************************************************************/
/*! \brief       Look up and return the bootmanager header address with a certain block index value
 *  \param[in]   blockIndex Index value of the block to be retrieved
 *  \param[out]  bmHeaderAddress BM Header address of the respective block
 *  \return      Possible return values:
 *               - kFblOk if header address could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockBmHeaderAddressByIndex(tFblLbtBlockIndex blockIndex,
                                                V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * bmHeaderAddress)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize BM header address to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.bmHeaderAddress = 0uL;

   if (FblLbtGetBlockDescriptorByIndex(blockIndex, &blockDescriptor) == kFblOk)
   {
      *bmHeaderAddress = blockDescriptor.bmHeaderAddress;
      result = kFblOk;
   }

   return result;
}
# endif /* FBL_LBT_ENABLE_BM_HEADER_ADDRESS */

# if defined( FBL_LBT_ENABLE_MAX_PROG_ATTEMPTS )
/***********************************************************************************************************************
 *  FblLbtGetBlockMaxProgAttemptsByIndex
 **********************************************************************************************************************/
/*! \brief       Look up and return the maximum programming attempts with a certain block index value
 *  \param[in]   blockIndex Index value of the block to be retrieved
 *  \param[out]  maxProgAttempts Maxmimum programming attempts of the respective block
 *  \return      Possible return values:
 *               - kFblOk if maximum programming attempts could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockMaxProgAttemptsByIndex(tFblLbtBlockIndex blockIndex,
                                                V_MEMRAM1 tFblLbtMaxProgAttempts V_MEMRAM2 V_MEMRAM3 * maxProgAttempts)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize maximum programming attempts to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.maxProgAttempts = 0u;

   if (FblLbtGetBlockDescriptorByIndex(blockIndex, &blockDescriptor) == kFblOk)
   {
      *maxProgAttempts = blockDescriptor.maxProgAttempts;
      result = kFblOk;
   }

   return result;
}
# endif /* FBL_LBT_ENABLE_MAX_PROG_ATTEMPTS */

# if defined( FBL_LBT_ENABLE_VERIFY_INPUT )
/***********************************************************************************************************************
 *  FblLbtGetBlockVerifyInputFuncByIndex
 **********************************************************************************************************************/
/*! \brief       Look up and return the verification function
 *  \param[in]   blockIndex Index value of the block to be retrieved
 *  \param[out]  blockVerifyFunc Address of the block specific verification function
 *  \return      Possible return values:
 *               - kFblOk if verification function could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockVerifyInputFuncByIndex(tFblLbtBlockIndex blockIndex,
                                                V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize verify function to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.verifyInput = (tExportFct)0;

   if (FblLbtGetBlockDescriptorByIndex(blockIndex, &blockDescriptor) == kFblOk)
   {
      *blockVerifyFunc = blockDescriptor.verifyInput;
      result = kFblOk;
   }

   return result;
}
# endif /* FBL_LBT_ENABLE_VERIFY_INPUT */

# if defined( FBL_LBT_ENABLE_VERIFY_PROCESSED )
/***********************************************************************************************************************
 *  FblLbtGetBlockVerifyProcessedFuncByIndex
 **********************************************************************************************************************/
/*! \brief       Look up and return the verification function
 *  \param[in]   blockIndex Index value of the block to be retrieved
 *  \param[out]  blockVerifyFunc Address of the block specific verification function
 *  \return      Possible return values:
 *               - kFblOk if verification function could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockVerifyProcessedFuncByIndex(tFblLbtBlockIndex blockIndex,
                                                    V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize verify function to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.verifyProcessed = (tExportFct)0;

   if (FblLbtGetBlockDescriptorByIndex(blockIndex, &blockDescriptor) == kFblOk)
   {
      *blockVerifyFunc = blockDescriptor.verifyProcessed;
      result = kFblOk;
   }

   return result;
}
# endif /* FBL_LBT_ENABLE_VERIFY_PROCESSED */

# if defined( FBL_LBT_ENABLE_VERIFY_PIPELINED )
/***********************************************************************************************************************
 *  FblLbtGetBlockVerifyPipelinedFuncByIndex
 **********************************************************************************************************************/
/*! \brief       Look up and return the verification function
 *  \param[in]   blockIndex Index value of the block to be retrieved
 *  \param[out]  blockVerifyFunc Address of the block specific verification function
 *  \return      Possible return values:
 *               - kFblOk if verification function could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockVerifyPipelinedFuncByIndex(tFblLbtBlockIndex blockIndex,
                                                    V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize verify function to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.verifyPipelined = (tExportFct)0;

   if (FblLbtGetBlockDescriptorByIndex(blockIndex, &blockDescriptor) == kFblOk)
   {
      *blockVerifyFunc = blockDescriptor.verifyPipelined;
      result = kFblOk;
   }

   return result;
}
# endif /* FBL_LBT_ENABLE_VERIFY_PIPELINED */

# if defined( FBL_LBT_ENABLE_VERIFY_OUTPUT )
/***********************************************************************************************************************
 *  FblLbtGetBlockVerifyOutputFuncByIndex
 **********************************************************************************************************************/
/*! \brief       Look up and return the block header address with a certain block index value
 *  \param[in]   blockIndex Index value of the block to be retrieved
 *  \param[out]  blockVerifyFunc Address of the block specific verification function
 *  \return      Possible return values:
 *               - kFblOk if verification function could be retrieved successfully
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtGetBlockVerifyOutputFuncByIndex(tFblLbtBlockIndex blockIndex,
                                                 V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc)
{
   tFblResult result;
   tBlockDescriptor blockDescriptor;

   result = kFblFailed;
   /* Initialize verify function to resolve MISRA finding (blockDescriptor is only valid in case 'kFblOk' is returned) */
   blockDescriptor.verifyOutput = (tExportFct)0;

   if (FblLbtGetBlockDescriptorByIndex(blockIndex, &blockDescriptor) == kFblOk)
   {
      *blockVerifyFunc = blockDescriptor.verifyOutput;
      result = kFblOk;
   }

   return result;
}
# endif /* FBL_LBT_ENABLE_VERIFY_OUTPUT */
#endif /* FBL_LBT_ENABLE_BLOCK_INDEX */

/***********************************************************************************************************************
 *  FblLbtCheckAddressRange
 **********************************************************************************************************************/
/*! \brief       Check whether an address lies within a specified address range
 *  \param[in]   address Address to be checked
 *  \param[in]   rangeStart Start of range
 *  \param[in]   rangeLength Length of range
 *  \return      Possible return values:
 *               - kFblOk if address lies within range
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtCheckAddressRange(tFblAddress address, tFblAddress rangeStart, tFblLength rangeLength)
{
   tFblResult result;

   result = kFblFailed;

   if (    (address >= rangeStart)
       && ((address - rangeStart) < rangeLength) )
   {
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblLbtCheckRangeContained
 **********************************************************************************************************************/
/*! \brief       Check whether an address range lies within another specified address range
 *  \param[in]   address Start address of range to be checked
 *  \param[in]   length Length of range to be checked
 *  \param[in]   rangeStart Start of range
 *  \param[in]   rangeLength Length of range
 *  \return      Possible return values:
 *               - kFblOk if range lies within range
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtCheckRangeContained(tFblAddress address, tFblLength length, tFblAddress rangeStart, tFblLength rangeLength)
{
   tFblResult result;

   result = kFblFailed;

   if ((FblLbtCheckAddressRange(address, rangeStart, rangeLength) == kFblOk)
       && (length <= rangeLength)
       && ((address - rangeStart) <= (rangeLength - length)) )
   {
      result = kFblOk;
   }

   return result;
}

#if defined( FBL_LBT_ENABLE_REPROGRAMMABLE_LBT )
/***********************************************************************************************************************
 *  FblLbtCheckConsistency
 **********************************************************************************************************************/
/*! \brief       Check consistency between the LBT which resides in the LBT block and the bootloader
 *  \return      Possible return values:
 *               - kFblOk if the information in the new LBT is consistent with the bootloader
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblLbtCheckConsistency(void)
{
   tFblResult result;
   tFblLbtBlockNr localBlockNr;
   tBlockDescriptor baseBlock;
   tBlockDescriptor newBlock = {0};

   result = kFblOk;

   /* Additional consistency checks should be performed by the generator which might be OEM/configuration specific, e.g.:
    * - SBL and LBT block are unique and of type 'mandatory'
    * - At least one logical block besides SBL/LBT is of type 'mandatory'
    * - Block index of all blocks is unique
    * - The configured logical blocks cover all blocks defined in the FBT
    * - Block header address of all blocks lies inside the respective block area
    * - Block header address has a reasonable distance from the presence pattern area
    */

   /* Temporarily switch to new LBT for consistency checks */
   FblLbtActivateLbtBlock();

   /* Check if block count exceeds built-in maximum value */
   if (fblLbtActive->noOfBlocks > (tFblLbtBlockCount)FBL_LBT_BLOCK_COUNT)
   {
      result = kFblFailed;
   }

   /* Check LBT against built-in FBT */
   if ((result == kFblOk) && (fblLbtActive->magicFlag != FblLogicalBlockTable.magicFlag))
   {
      result = kFblFailed;
   }

   /* Compare fixed blocks in built-in LBT against new LBT */
   if (result == kFblOk)
   {
      for (localBlockNr = 0u; localBlockNr < FblLogicalBlockTable.noOfBlocks; localBlockNr++)
      {
         baseBlock = FblLogicalBlockTable.logicalBlock[localBlockNr];
         result = FblLbtGetBlockDescriptorByNr(localBlockNr, &newBlock);
         if (result == kFblOk)
         {
            result = FblLbtBlockCompare(&baseBlock, &newBlock);
         }
         if (result != kFblOk)
         {
            break;
         }
      }
   }

   /* Check block type and verify functions against built-in values */
   if (result == kFblOk)
   {
      result = FblLbtCheckReferences();
   }

   /* Revert LBT pointer to built-in table */
   FblLbtInitPowerOn();

   return result;
}

/***********************************************************************************************************************
 *  FblLbtActivateLbtBlock
 **********************************************************************************************************************/
/*! \brief       Activate usage of the reprogrammable LBT
 *  \pre         FblLbtCheckConsistency() has been executed with positive result
 **********************************************************************************************************************/
void FblLbtActivateLbtBlock(void)
{
   /* Switch to logical block table in LBT block */
# if defined( FBL_LBT_ENABLE_RAM_BUFFER )
   FblLbtActivateLbtBlockByAddress(FblLogicalBlockTable.logicalBlock[FBL_MTAB_LBT_BLOCK_NUMBER].blockStartAddress);
# else
   /* PRQA S 0306 1 */ /* MD_FblLib_Lbt_0306 */
   fblLbtActive = (V_MEMROM1 tLogicalBlockTable V_MEMROM2 V_MEMROM3 *)FblLogicalBlockTable.logicalBlock[FBL_MTAB_LBT_BLOCK_NUMBER].blockStartAddress;
# endif /* FBL_LBT_ENABLE_RAM_BUFFER */
}
#endif /* FBL_LBT_ENABLE_REPROGRAMMABLE_LBT */

/***********************************************************************************************************************
 *  FblLbtActivateLbtBlockByAddress
 **********************************************************************************************************************/
/*! \brief       Activate usage of the reprogrammable LBT
 *  \details     CAUTION: The function will set the internal LBT pointer without further consistency checks. It's in
 *               the responsibility of the caller to check the LBT consistency before accessing the contained
 *               information!
 *  \param[in]   address Address of the logical block table, which should now be used
 **********************************************************************************************************************/
void FblLbtActivateLbtBlockByAddress(tFblAddress address)
{
   /* Switch to logical block table in LBT block */
#if defined(FBL_LBT_ENABLE_RAM_BUFFER)
   tFblLength readCount = FblReadProm(address, (vuint8*)&fblLbtRamBuffer, FBL_LBT_RAM_BUF_SIZE);
   /* PRQA S 3205 1 */ /* MD_FblLib_Lbt_3205 */
   assertFbl(readCount != FBL_LBT_RAM_BUF_SIZE, kFblSysAssertParameterOutOfRange);
#else
   /* PRQA S 0306 1 */ /* MD_FblLib_Lbt_0306 */
   fblLbtActive = (V_MEMROM1 tLogicalBlockTable V_MEMROM2 V_MEMROM3 *)address;
#endif /* FBL_LBT_ENABLE_RAM_BUFFER */
}
#define FBLLBT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* module specific MISRA deviations:

   MD_FblLib_Lbt_0306:
     Reason:     Address conversion between integer values and pointers is required to allow for hardware independent
                  configuration and address range checks.
     Risk:       The size of integer required to hold the result of a pointer cast is implementation-defined.
     Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                  specific basis. The correctness of the respective implementation is verified by runtime tests.

   MD_FblLib_Lbt_3205:
     Reason:     Depending on the configuration some variables are not referenced by the code. For simplicity the
                  variables are kept.
     Risk:       No identifiable risk.
     Prevention: No prevention required.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_LBT_ACCESS.C
 **********************************************************************************************************************/

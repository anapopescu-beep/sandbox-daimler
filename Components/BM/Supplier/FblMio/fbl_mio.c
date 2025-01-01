/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Memory Driver wrapper functions
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
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#define FBL_MIO_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/
/* Check the version of Msn header file */
#if (  (FBL_MIO_MAJOR_VERSION != (4u)) \
    || (FBL_MIO_MINOR_VERSION != (1u)) \
    || (FBL_MIO_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of fbl_mio.c and fbl_mio.h are inconsistent"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if !defined( FBL_MIO_ENABLE_SEGMENT_CACHING ) || \
    !defined( FBL_MIO_DISABLE_SEGMENT_CACHING )
# define FBL_MIO_ENABLE_SEGMENT_CACHING
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define Mio_MemDriverInit(address)                 (*memDrvLst[i].init)(address)
#define Mio_MemDriverDeinit(address)               (*memDrvLst[i].deinit)(address)

#define Mio_MemFlashBlockDevice()                  (FlashBlock[memSegment].device)

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLMIO_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_MIO_ENABLE_MEM_DRIVER_READY )
V_MEMRAM0 V_MEMRAM1      vuint16             V_MEMRAM2      memDriverReady;
#endif /* FBL_MIO_ENABLE_MEM_DRIVER_READY */
/* Device active status, if currently an erase or programming is active. It contains either the state "Idle" or */
/* the device driver number that is active.  */
V_MEMRAM0 V_MEMRAM1 vuint8                     V_MEMRAM2 memDrvDeviceActive;
V_MEMRAM0 V_MEMRAM1 vuint8                     V_MEMRAM2 memDrvFunctionActive;
V_MEMRAM0 V_MEMRAM1 vMemAccM_AddressAreaIdType V_MEMRAM2 currentAddressArea;

/** Memory segment handle */
V_MEMRAM0 V_MEMRAM1 vsint16                    V_MEMRAM2 memSegment;

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/* FblMemSegmentNrGet caching */
#if defined( FBL_MIO_ENABLE_SEGMENT_CACHING )
V_MEMRAM0 static V_MEMRAM1 vsint16             V_MEMRAM2 cachedSegment;
V_MEMRAM0 static V_MEMRAM1 tFlashBlock         V_MEMRAM2 cachedBlock;
#endif
V_MEMRAM0 static V_MEMRAM1 vsint16             V_MEMRAM2 nextValidSegment;

#define FBLMIO_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLMIO_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

static vMemAccM_JobResultType MemDriver_WhileMemJobPending(vMemAccM_AddressAreaIdType addrArea);

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  MemDriver_WhileMemJobPending
 **********************************************************************************************************************/
/*! \brief      Waits until the job processed by the underlying memory access layer is no longer pending.
 *  \details    This function calls the Main Function(s) of the underlying memory access layer while the job is
 *              pending. For each of these call-to-MainFunction cycles, a user callout for user-specific processing
 *              is called.
 *  \param[in]  addrArea used address area.
 *  \return     Result of job
 **********************************************************************************************************************/
static vMemAccM_JobResultType MemDriver_WhileMemJobPending(vMemAccM_AddressAreaIdType addrArea)
{
   vMemAccM_JobResultType jobResult;

   do
   {
      FblLookForWatchdogVoid();
      vMemAccM_MainFunction();
#if defined( FBL_MIO_ENABLE_USER_MAIN_FUNCTION )
      MemDriver_UserMainFunction();
#endif /* FBL_MIO_ENABLE_USER_MAIN_FUNCTION */
      jobResult = vMemAccM_GetJobResult(addrArea);
   }
   while ( VMEMACCM_JOB_PENDING == jobResult );

   return jobResult;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  MemDriver_InitPowerOn
 **********************************************************************************************************************/
/*! \brief       Initializes the MIO module
 **********************************************************************************************************************/
void MemDriver_InitPowerOn( void )
{
#if defined( FBL_MIO_ENABLE_MEM_DRIVER_READY )
   memDriverReady = 0u;
#endif /* FBL_MIO_ENABLE_MEM_DRIVER_READY */

   memDrvDeviceActive   = kMioDeviceIdle;
   memDrvFunctionActive = kMioFunctionNone;
   currentAddressArea   = 0;

   memSegment           = -1;
   nextValidSegment     = -1;
#if defined( FBL_MIO_ENABLE_SEGMENT_CACHING )
   /* FblMemSegmentNrGet caching - initialize cache with a valid entry */
   cachedSegment        = 0;
   cachedBlock.begin    = FlashBlock[0u].begin;
   cachedBlock.end      = FlashBlock[0u].end;
#endif

#if defined( FBL_MIO_ENABLE_USER_INIT_FUNCTION )
   MemDriver_UserInitFunction();
#endif
}

/***********************************************************************************************************************
 *  FblMemSegmentNrGet
 **********************************************************************************************************************/
/*! \brief       Get the number of the corresponding flash block for the given address
 *  \param[in]   address
 *  \return      Index of flash block; -1, if not found
 **********************************************************************************************************************/
vsint16 FblMemSegmentNrGet( tFblAddress address )
{
   vsint16 segment;
   tFblAddress localAddress;

   /* Initialize variables */
   localAddress = address;

#if defined( FBL_MIO_ENABLE_SEGMENT_CACHING )
   /* Check address against cached range */
   if (   ( localAddress >= cachedBlock.begin )
       && ( localAddress <= cachedBlock.end )
      )
   {
      /* Range matches, finish processing and return cached segment */
      segment = cachedSegment;
   }
   else
   {
      /* Search matching flash block */
      nextValidSegment = 0;
      while (nextValidSegment < (vsint16)kNrOfFlashBlock)
      {
         /* Reduced number of watchdog trigger calls */
         if (((vuint8)nextValidSegment & (vuint8)0x0Fu) == (vuint8)0x00u)
         {
            (void)FblRealTimeSupport();
         }

         /* Found first potential match */
         if (FlashBlock[nextValidSegment].end >= localAddress)
         {
            break;
         }
         /* Prepare next cycle */
         nextValidSegment++;
      }

      /* Valid match found */
      if (nextValidSegment < (vsint16)kNrOfFlashBlock)
      {
         if (localAddress >= FlashBlock[nextValidSegment].begin)
         {
            /* Address lies within block => valid segment */
            segment = nextValidSegment;

            /* Cache current match */
            cachedBlock.begin = FlashBlock[segment].begin;
            cachedBlock.end = FlashBlock[segment].end;
         }
         else
         {
            /* Address lies in front of block => gap detected */
            segment = -1;

            /* Cache current gap */
            if (nextValidSegment <= 0)
            {
               /* First block, gap starts at beginning of address space */
               cachedBlock.begin = 0x00u;
            }
            else
            {
               /* Gap starts after end of previous block */
               cachedBlock.begin = FlashBlock[nextValidSegment - 1].end + 1u;
            }
            /* Gap ends in front of current segment */
            cachedBlock.end = FlashBlock[nextValidSegment].begin - 1u;
         }
      }
      else
      {
         vuint32 lastSegment = (vuint32)kNrOfFlashBlock - 1u;

         /* Address lies behind last block => gap detected */
         segment = -1;

         /* Cache current gap
          * Gap starts after end of previous block */
         cachedBlock.begin = FlashBlock[lastSegment].end + 1u;
         /* Gap ends at end of address space */
         cachedBlock.end = (tFblAddress)(-1); /* PRQA S 2895 */ /* MD_FblMio_2895 */
      }

      /* Cache current segment for next request */
      cachedSegment = segment;
   }
#else
   /* Loop downward through the blocks */
   segment = (vsint16)(kNrOfFlashBlock - 1u);

   while (segment >= 0)
   {
      /* Check if address matches the current block */
      if (  (localAddress >= FlashBlock[segment].begin)
         && (localAddress <= FlashBlock[segment].end) )
      {
         nextValidSegment = segment;
         /* Yes, matches. End loop */
         break;
      }

      /* Reduced number of watchdog trigger calls */
      if (((vuint8)segment & (vuint8)0x0Fu) == (vuint8)0x00u)
      {
         (void)FblRealTimeSupport();
      }

      segment--;
   }
#endif

   return segment;
}

/***********************************************************************************************************************
 *  FblMemGetDeviceByAddr
 **********************************************************************************************************************/
/*! \brief       Retrieves the memory device of a given address.
 *  \param[in]   address Address.
 *  \param[out]  device Memory device driver index.
 *  \return      Possible return values:
 *               - kFblOk if device is valid
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblMemGetDeviceByAddr(tFblAddress address, V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * device)
{
   tFblResult result;
   vsint16 localMemSegment;

   result = kFblFailed;

   localMemSegment = FblMemSegmentNrGet(address);
   if (localMemSegment >= 0)
   {
      *device = FlashBlock[localMemSegment].device;
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblMemGetDeviceByRange
 **********************************************************************************************************************/
/*! \brief       Retrieves the memory device of a given range.
 *  \details     Checks if all memory devices inside the given range correspond to the same memory device.
 *  \param[in]   address Start address of the range.
 *  \param[in]   length Length of the range.
 *  \param[out]  device Memory device driver index.
 *  \return      Possible return values:
 *               - kFblOk if device is valid and all memory devices are the same
 *               - kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblMemGetDeviceByRange(tFblAddress address, tFblLength length, V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * device)
{
   tFblResult result = kFblFailed;
   vuint8 localDevice = 0u;
   vsint16 localMemSegmentStart;
   vsint16 localMemSegmentEnd;
   vsint16 localMemSegment;

   localMemSegmentStart = FblMemSegmentNrGet(address);
   localMemSegmentEnd = FblMemSegmentNrGet(address + (length - 1u));

   if (   (localMemSegmentStart >= 0)
       && (localMemSegmentEnd >= 0)
      )
   {
      result = kFblOk;
      /* Get first memory device */
      localDevice = FlashBlock[localMemSegmentStart].device;

      /* Iterate now over all remaining flash blocks included in the range and check if the memory device changes */
      for (localMemSegment = localMemSegmentStart + 1; localMemSegment <= localMemSegmentEnd; localMemSegment++)
      {
         if (localDevice != FlashBlock[localMemSegment].device)
         {
            /* Failure, memory device is different */
            result = kFblFailed;
            break;
         }
      }
   }

   if (result == kFblOk)
   {
      *device = localDevice;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblReadProm
 **********************************************************************************************************************/
/*! \brief       Read from ROM memory.
 *  \details     Reads data from ROM memory using the read function supplied with the flash driver.
 *  \param[in]   address Memory address to read out (logical address).
 *  \param[out]  buffer Target buffer.
 *  \param[in]   length Number of bytes to be read.
 *  \return      Number of actually copied bytes.
 **********************************************************************************************************************/
tFblLength FblReadProm(tFblAddress address, V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * buffer, tFblLength length)
{
   tFblLength actualReadCount;    /* Actual read bytes */

   (void)FblReadPromExt(address, buffer, length , &actualReadCount);

   return actualReadCount;
}

/***********************************************************************************************************************
 *  FblReadPromExt
 **********************************************************************************************************************/
/*! \brief       Read from ROM memory.
 *  \details     Reads data from ROM memory using the read function supplied with the flash driver.
 *  \param[in]   address Memory address to read out (logical address).
 *  \param[out]  buffer Target buffer.
 *  \param[in]   length Number of bytes to be read.
 *  \param[out]  actualReadCount Number of actually copied bytes
 *  \return      Error code of the read function
 *                IO_E_OK: All bytes could be read
 *                IO_E_ERASED: Read data is erased
 *                IO_E_NOT_OK: Could not read all data
 **********************************************************************************************************************/
IO_ErrorType FblReadPromExt(tFblAddress address, V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * buffer, tFblLength length,
   V_MEMRAM1 tFblLength V_MEMRAM2 V_MEMRAM3 * actualReadCount)
{
   IO_ErrorType result;
   tFblAddress localAddress;
   V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * localBuffer;
   tFblLength localLength;
   tFblLength localActualReadCount;    /* Actual read bytes */
   tFblLength currentReadCount;
   vsint16    nextMemSegment;

   /* Initialize variables */
   localAddress = address;
   localLength = length;
   localBuffer = buffer;
   localActualReadCount = 0u;
   result = IO_E_OK;

   (void)FblRealTimeSupport();

   /* Find start segment */
   memSegment = FblMemSegmentNrGet(localAddress);

   if (memSegment < 0)
   {
      /* Start address does not lie within a valid memory segment
       * Search first segment which overlaps with requested range
       * This allows segmented reading of memory areas which include gaps
       * (e.g. CRC calculation or signature verification) */

      /* nextValidSegment contains first segment behind gap */
      if (nextValidSegment < (vsint16)kNrOfFlashBlock)
      {
         /* Gap detection */
         if (
               (localAddress < FlashBlock[nextValidSegment].begin) &&
               (localLength > (FlashBlock[nextValidSegment].begin - localAddress))
            )
         {
            /* Found first segment which overlaps requested range */
            memSegment = nextValidSegment;

            /* Remove gap from read length */
            localLength -= (FlashBlock[memSegment].begin - localAddress);
            /* Adapt start address to segment start */
            localAddress = FlashBlock[memSegment].begin;
         }
      }
   }

   /* Initialize next memory segment index */
   nextMemSegment = memSegment;

   /* Start segment found, read segment */
   if (memSegment >= 0)
   {
      while (localLength > 0u)
      {
         /* Check if read range crosses Flash block boundary */
         if ((localAddress + (localLength - 1u)) > FlashBlock[memSegment].end)
         {
            currentReadCount = (FlashBlock[memSegment].end - localAddress) + 1u;

            nextMemSegment++;

            if (nextMemSegment < (vsint16)kNrOfFlashBlock)
            {
               localLength = ((FlashBlock[nextMemSegment].begin - localAddress) < localLength)
                  ? (localLength - (FlashBlock[nextMemSegment].begin - localAddress)) : 0u;
            }
            else
            /* Flash block index overflow, exit loop */
            {
               localLength = 0u;
            }
         }
         else
         {
            currentReadCount = localLength;
            localLength = 0u;
         }

         switch (MemDriver_RReadSync(localBuffer, currentReadCount, localAddress))
         {
            case IO_E_ERASED:
            {
               /* Overwrite global result to IO_E_ERASED */
               result = IO_E_ERASED;
            }
            /* Intentional fall through */
            case IO_E_OK: /* PRQA S 2003 */ /* MD_FblMio_2003 */
            {
               memSegment = nextMemSegment;
               localBuffer = (vuint8 *)&localBuffer[currentReadCount];
               localAddress = FlashBlock[memSegment].begin;
               localActualReadCount += currentReadCount;
               break;
            }
            default:
            {
               /* In case of error quit loop */
               localLength = 0u;
               result = IO_E_NOT_OK;
               break;
            }
         }

         (void)FblRealTimeSupport();
      }
   }
   else
   {
      localActualReadCount = 0u;
   }

   *actualReadCount = localActualReadCount;

   return result;
}

/***********************************************************************************************************************
 *  MemDriver_Begin
 **********************************************************************************************************************/
/*! \brief      Performs operations before the memory driver is called.
 *  \param[in]  device        Memory device, which is going to be used.
 *  \param[in]  function      Function of the memory device, which is going to be called.
 *  \param[in]  hookEnabled   Specifies if the hook function ApplFblPreMemDriver should be called.
 **********************************************************************************************************************/
void V_API_NEAR MemDriver_Begin(vuint8 device, vuint8 function, boolean hookEnabled)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
# if defined( FBL_MIO_ENABLE_HOOKS )
# else
   /* Parameters not used: avoid compiler warning */
   (void)hookEnabled;
# endif /* FBL_MIO_ENABLE_HOOKS */
#endif

   memDrvDeviceActive = device;
   memDrvFunctionActive = function;

#if defined( FBL_MIO_ENABLE_HOOKS )
   /* Check if the hook function should be called */
   if (hookEnabled == TRUE)
   {
      ApplFblPreMemDriver(memDrvDeviceActive, memDrvFunctionActive);
   }
#endif /* FBL_MIO_ENABLE_HOOKS */
}

/***********************************************************************************************************************
 *  MemDriver_End
 **********************************************************************************************************************/
/*! \brief      Performs operation after the memory driver has been returned.
 *  \param[in]  hookEnabled   Specifies if the hook function ApplFblPreMemDriver should be called.
 **********************************************************************************************************************/
void V_API_NEAR MemDriver_End(boolean hookEnabled)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
# if defined( FBL_MIO_ENABLE_HOOKS )
# else
   /* Parameters not used: avoid compiler warning */
   (void)hookEnabled;
# endif /* FBL_MIO_ENABLE_HOOKS */
#endif

#if defined( FBL_MIO_ENABLE_HOOKS )
   /* Check if the hook function should be called */
   if (hookEnabled == TRUE)
   {
      ApplFblPostMemDriver(memDrvDeviceActive, memDrvFunctionActive);
   }
#endif /* FBL_MIO_ENABLE_HOOKS */

   memDrvDeviceActive = kMioDeviceIdle;
   memDrvFunctionActive = kMioFunctionNone;
}

/***********************************************************************************************************************
 *  MemDriver_InitSync
 **********************************************************************************************************************/
/*! \brief      Initialize all memory drivers.
 *  \pre        Memory drivers have to be present (e.g. copied to RAM).
 *  \param[in]  address Parameter to be passed to HIS interface flash driver.
 *  \return     Reports if all memory drivers have been initialized successfully.
 **********************************************************************************************************************/
IO_ErrorType MemDriver_InitSync( void * address )
{
   vuint8 i;
   IO_ErrorType result = IO_E_OK;
   IO_ErrorType rc;

#if defined( FBL_MIO_ENABLE_MEM_DRIVER_READY )
   memDriverReady = 0u;

# if defined( FBL_ENABLE_SYSTEM_CHECK )
   /* Check for too many device-drivers */
   if (kNrOfMemDrv > (sizeof(memDriverReady) * 8u))
   {
      result = IO_E_NOT_OK;
   }
   else
# endif
#endif /* FBL_MIO_ENABLE_MEM_DRIVER_READY */
   {
      for (i = 0u; i < kNrOfMemDrv; i++)
      {
         MemDriver_InitBegin(i);
         rc = Mio_MemDriverInit(address);
         MemDriver_InitEnd(i);

#if defined( FBL_MIO_ENABLE_MEM_DRIVER_READY )
         if (rc == IO_E_OK)
         {
            SetMemDriverReady(i);
         }
         else
         {
            if (result == IO_E_OK)
            {
               result = rc;
            }

            ClrMemDriverReady(i);
         }
#else
         if (rc != IO_E_OK)
         {
            result = rc;
            break;
         }
#endif /* FBL_MIO_ENABLE_MEM_DRIVER_READY */
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  MemDriver_DeinitSync
 **********************************************************************************************************************/
/*! \brief      Deinitialize all memory drivers.
 *  \pre        Memory drivers have to be present (e.g. copied to RAM).
 *  \param[in]  address Parameter to be passed to HIS interface flash driver.
 *  \return     The return code shows the success of the deinitialization.
 **********************************************************************************************************************/
IO_ErrorType MemDriver_DeinitSync( void * address )
{
   vuint8 i;
   IO_ErrorType result = IO_E_OK;
#if defined( FBL_MIO_ENABLE_MEM_DRIVER_READY )
   IO_ErrorType rc;
#endif /* FBL_MIO_ENABLE_MEM_DRIVER_READY */

   for (i = 0u; i < kNrOfMemDrv; i++)
   {
#if defined( FBL_MIO_ENABLE_MEM_DRIVER_READY )
      /* Deinit only drivers that have been initialized before */
      if (GetMemDriverReady(i))
      {
         MemDriver_DeinitBegin(i);
         rc = (*memDrvLst[i].deinit)(address);
         MemDriver_DeinitEnd(i);

         if ((rc != IO_E_OK) && (result == IO_E_OK))
         {
            result = rc;
         }
         ClrMemDriverReady(i);
      }
#else
      MemDriver_DeinitBegin(i);
      result = Mio_MemDriverDeinit(address);
      MemDriver_DeinitEnd(i);
      if (result != IO_E_OK)
      {
         break;
      }
#endif /* FBL_MIO_ENABLE_MEM_DRIVER_READY */
   }
   return result;
}

/***********************************************************************************************************************
 *  MemDriver_RWriteAddrAreaSync
 **********************************************************************************************************************/
/*! \brief      Write data to memory
 *  \details    This function selects the memory driver used to program a memory device and
 *              calls the write function of this driver.
 *  \pre        All drivers are initialized, memory to be written is erased (flash memory).
 *  \param[in]  addrArea used address area.
 *  \param[in]  buf Pointer to input data buffer.
 *  \param[in]  len Data length. Has to be aligned to a multiple of the smallest writable data segment.
 *  \param[in]  addr Write target address. Has to be aligned to a write segment start address.
 *  \return     Reports write success or error code.
 **********************************************************************************************************************/
/* PRQA S 3673 1*/ /* MD_MSR_Rule8.13 */
IO_ErrorType MemDriver_RWriteAddrAreaSync(vMemAccM_AddressAreaIdType addrArea, IO_MemPtrType buf, IO_SizeType len, IO_PositionType addr)
{
   IO_ErrorType retVal = IO_E_NOT_OK;

   if ((memSegment >= 0) && (memSegment < (vsint16)kNrOfFlashBlock))
   {
      MemDriver_RWriteBegin(Mio_MemFlashBlockDevice());

      if (E_OK == vMemAccM_Write(addrArea,(vMemAccM_AddressType)addr, buf,(vMemAccM_LengthType)len)) /* PRQA S 0315 */ /* MD_FblMio_Dir1.1_0315_TypedPtrVoidPtr */
      {
         if (VMEMACCM_JOB_OK == MemDriver_WhileMemJobPending(addrArea))
         {
            retVal = IO_E_OK;
         }
      }
#if defined( FBL_MIO_ENABLE_COMPARE_AFTER_WRITE )
      if (IO_E_OK == retVal)
      {
         retVal = IO_E_NOT_OK;
         if (E_OK == vMemAccM_Compare(addrArea,(vMemAccM_AddressType)addr, buf,(vMemAccM_LengthType)len)) /* PRQA S 0315 */ /* MD_FblMio_Dir1.1_0315_TypedPtrVoidPtr */
         {
            if (VMEMACCM_JOB_OK == MemDriver_WhileMemJobPending(addrArea))
            {
               retVal = IO_E_OK;
            }
         }
      }
#endif

      MemDriver_RWriteEnd(Mio_MemFlashBlockDevice());
   }

   return retVal;
}

/***********************************************************************************************************************
 *  MemDriver_REraseAddrAreaSync
 **********************************************************************************************************************/
/*! \brief      Erase area in memory
 *  \details    This function erases an area in memory.
 *  \pre        All drivers are initialized.
 *  \param[in]  addrArea used address area.
 *  \param[in]  len Length of memory to be erased. The length has to be aligned to the length of one or
 *              more erasable sectors of the used memories.
 *  \param[in]  addr Start address of erase area. The start address has to be aligned to the start address
 *              of an erasable area.
 *  \return     Reports erase success or error code.
 **********************************************************************************************************************/
IO_ErrorType MemDriver_REraseAddrAreaSync(vMemAccM_AddressAreaIdType addrArea, IO_SizeType len, IO_PositionType addr )
{
   IO_ErrorType retVal = IO_E_NOT_OK;
   vMemAccM_MemoryInfoType memInfo;
   IO_SizeType localLen;

   localLen = len;

   if ((memSegment >= 0) && (memSegment < (vsint16)kNrOfFlashBlock))
   {
      MemDriver_REraseBegin(Mio_MemFlashBlockDevice());

      if(E_OK == vMemAccM_GetMemoryInfo(addrArea, (vMemAccM_AddressType)addr, (vMemAccM_LengthType)localLen, &memInfo))
      {
         /* Adapt length to the destination sector size */
         if(memInfo.SectorSize > localLen)
         {
            localLen = memInfo.SectorSize;
         }

         if (E_OK == vMemAccM_Erase(addrArea, (vMemAccM_AddressType)addr, (vMemAccM_LengthType)localLen))
         {
            if (VMEMACCM_JOB_OK == MemDriver_WhileMemJobPending(addrArea))
            {
               retVal = IO_E_OK;
            }
         }
      }

      MemDriver_REraseEnd(Mio_MemFlashBlockDevice());
   }

   return retVal;
}

/***********************************************************************************************************************
 *  MemDriver_RReadAddrAreaSync
 **********************************************************************************************************************/
/*! \brief      Read data from memory
 *  \details    This function selects the memory driver used to read a memory device and
 *              calls the read function of this driver.
 *  \pre        All drivers are initialized.
 *  \param[in]  addrArea used address area.
 *  \param[in]  buf Pointer to output data buffer.
 *  \param[in]  len Data length.
 *  \param[in]  addr Read target address.
 *  \return     Reports write success or error code.
 **********************************************************************************************************************/
/* PRQA S 6030, 6050, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
IO_ErrorType MemDriver_RReadAddrAreaSync (vMemAccM_AddressAreaIdType addrArea, IO_MemPtrType buf, IO_SizeType len, IO_PositionType addr)
{
   IO_ErrorType retVal = IO_E_NOT_OK;
   vMemAccM_MemoryInfoType memInfo;
   boolean foundHwId = FALSE;
   boolean isHis = FALSE;
   IO_U32 index;
#if defined( FBL_MIO_ENABLE_USE_IS_BLANK )
   vuint8 erasedValue = 0u;
   vMemAccM_AddressType isBlankAddress;
   vMemAccM_LengthType isBlankLength;
#endif /* FBL_MIO_ENABLE_USE_IS_BLANK */

   if ((memSegment >= 0) && (memSegment < (vsint16)kNrOfFlashBlock))
   {
      MemDriver_RReadBegin(Mio_MemFlashBlockDevice());

      if (E_OK == vMemAccM_GetMemoryInfo(addrArea, (vMemAccM_AddressType)addr, (vMemAccM_LengthType)len, &memInfo))
      {
         for (index = 0; index < FBL_MIO_SIZE_OF_INSTANCE_MAPPING; index++)
         {
            if (FblMemInstanceMapping[index].hwId == memInfo.HwId)
            {
               isHis = FblMemInstanceMapping[index].isHis;
#if defined( FBL_MIO_ENABLE_USE_IS_BLANK )
               erasedValue = FblMemInstanceMapping[index].erasedValue;
#endif /* FBL_MIO_ENABLE_USE_IS_BLANK */
               foundHwId = TRUE;
               break;
            }
         }

         if (foundHwId == TRUE)
         {
            if (isHis == TRUE)
            {
               /* Trigger a new read request in Mem2His module */
               vMem2His_ClrLastMemDriverResult();
            }
#if defined( FBL_MIO_ENABLE_USE_IS_BLANK )
            else
            {
               /* Align address and length to page size */
               isBlankAddress = addr & FblInvert32Bit(memInfo.PageSize - 1u);
               isBlankLength = (addr + (len - 1u)) - isBlankAddress; /* Calculate new blank length based on new aligned blank address */
               isBlankLength = (isBlankLength + (memInfo.PageSize - 1u)) & FblInvert32Bit(memInfo.PageSize - 1u); /* Align blank length to the next page */
               /* Do a blank check */
               if (E_OK == vMemAccM_IsBlank(addrArea, isBlankAddress, isBlankLength))
               {
                  /* Check if blank was successful -> area is erased */
                  if (VMEMACCM_JOB_OK == MemDriver_WhileMemJobPending(addrArea))
                  {
                     /* Fill up buffer with erased value */
                     for (index = 0; index < len; index++)
                     {
                        buf[index] = erasedValue;
                     }
                     retVal = IO_E_ERASED;
                  }
               }
            }

            if (retVal != IO_E_ERASED)
#endif /* FBL_MIO_ENABLE_USE_IS_BLANK */
            {
               if (E_OK == vMemAccM_Read(addrArea, (vMemAccM_AddressType)addr, buf, (vMemAccM_LengthType)len)) /* PRQA S 0315 */ /* MD_FblMio_Dir1.1_0315_TypedPtrVoidPtr */
               {
                  vMemAccM_JobResultType jobResult = MemDriver_WhileMemJobPending(addrArea);

                  if ((jobResult == VMEMACCM_JOB_OK)|| (jobResult == VMEMACCM_READ_CORRECTED_ERRORS))
                  {
                     if (isHis == TRUE)
                     {
                        /* The HIS flash driver has IO_E_ERASED as return value. Since this is a valid return value, which needs to be
                         * distinguished from IO_E_OK (= E_OK) the lower wrapper will simply return OK and here we overwrite the OK by
                         * real value. */
                        retVal = vMem2His_GetLastMemDriverResult();
                     }
                     else
                     {
                        retVal = IO_E_OK;
                     }
                  }
               }
            }
         }
      }

      MemDriver_RReadEnd(Mio_MemFlashBlockDevice());
   }

   return retVal;
}

/***********************************************************************************************************************
 *  MemDriver_GetSegmentSize
 **********************************************************************************************************************/
/*! \brief      Returns page (aka segment) size
 *  \param[in]  addrArea used address area.
 *  \param[in]  len Data length.
 *  \param[in]  addr Read target address.
 *  \return     page size for given area
 **********************************************************************************************************************/
vuint16 MemDriver_GetSegmentSize(vMemAccM_AddressAreaIdType addrArea, IO_SizeType len, IO_PositionType addr)
{
   vMemAccM_MemoryInfoType memInfo;
   Std_ReturnType          intRetVal;
   vuint16                 retSegSize;

   intRetVal = vMemAccM_GetMemoryInfo(addrArea, (vMemAccM_AddressType)addr, (vMemAccM_LengthType)len, &memInfo);
   assertFblGen((intRetVal == E_OK), kFblSysAssertParameterOutOfRange);
   retSegSize = ((vuint16) memInfo.PageSize);

   return retSegSize;
}

/***********************************************************************************************************************
 *  MemDriver_CopyDriver
 **********************************************************************************************************************/
/*! \brief      Decrypts and copies memory driver to designated RAM.
 *  \param[in]  drvBlkInfo Structure with information about the byte array(s) of the memory driver.
 *  \param[in]  numOfBlocks Number of contiguous memory blocks of the whole memory driver.
 *  \param[in]  decryptValue XOR decryption value of the memory driver.
 *  \param[in]  ramBufAddress Physical address of assigned RAM buffer
 *  \param[in]  ramBufSize Size of target RAM buffer
 **********************************************************************************************************************/
void MemDriver_CopyDriver( V_MEMROM1 tFblMioDrvBlkInfo V_MEMROM2 V_MEMROM3 * drvBlkInfo, vuint8 numOfBlocks, vuint8 decryptValue,
                           IO_PositionType ramBufAddress, IO_SizeType ramBufSize )
{
   vuintx               blockIdx;
   vuintx               dataIdx;
   vuint8 *             pRamBufData;
#if defined( FBL_ENABLE_ASSERTION )
   tFblAddress          lastBlkStartAddress;
   tFblLength           lastBlkLength;

   /* Check that driver fits into assigned RAM buffer */
   assertFblInternal((drvBlkInfo[0u].blockAddress >= ramBufAddress), kFblSysAssertParameterOutOfRange);
   lastBlkStartAddress = drvBlkInfo[numOfBlocks - 1u].blockAddress;
   lastBlkLength = drvBlkInfo[numOfBlocks - 1u].blockLength;
   assertFblInternal(((lastBlkStartAddress + (lastBlkLength - 1u)) <= (ramBufAddress + (ramBufSize - 1u))), kFblSysAssertParameterOutOfRange);
#else /* FBL_ENABLE_ASSERTION */
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)ramBufAddress;
   (void)ramBufSize;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */
#endif /* FBL_ENABLE_ASSERTION */

   /* Copy all blocks to RAM */
   for (blockIdx = 0u; blockIdx < numOfBlocks; blockIdx++)
   {
      pRamBufData = (vuint8 *)(drvBlkInfo[blockIdx].blockAddress);   /* PRQA S 0306 */ /* MD_FblMio_0306_CopyEraseDriver */
      /* Copy contiguous block to RAM and XOR with decryption value */
      for (dataIdx = 0u; dataIdx < drvBlkInfo[blockIdx].blockLength; dataIdx++)
      {
         pRamBufData[dataIdx] = drvBlkInfo[blockIdx].blockSource[dataIdx] ^ decryptValue;

         /* Poll watchdog/timed tasks every 256 bytes copied */
         if ((dataIdx & 0xFFu) == 0x00u)
         {
            FblLookForWatchdogVoid();
         }
      }
   }
}

/***********************************************************************************************************************
 *  MemDriver_EraseDriver
 **********************************************************************************************************************/
/*! \brief      Erases memory driver from assigned RAM buffer
 *  \param[in]  ramBufAddress Physical address of assigned RAM buffer
 *  \param[in]  ramBufSize Size of target RAM buffer
 **********************************************************************************************************************/
void MemDriver_EraseDriver(IO_PositionType ramBufAddress, IO_SizeType ramBufSize)
{
   vuintx               dataIdx;
   vuint8 *             pRamBufData;
   vuint8               device;
   vuint8               eraseValue;

   /* Get memory device index of the used RAM buffer */
   if (kFblOk == FblMemGetDeviceByRange(ramBufAddress, ramBufSize, &device))
   {
      eraseValue = memDrvLst[device].erasedValue;
   }
   else
   {
      /* Memory device could not be gotten, assume 0 as erase value */
      eraseValue = 0x00u;
   }

   pRamBufData = (vuint8 *)ramBufAddress; /* PRQA S 0306 */ /* MD_FblMio_0306_CopyEraseDriver */

   for (dataIdx = 0u; dataIdx < ramBufSize; dataIdx++)
   {
      pRamBufData[dataIdx] = eraseValue;

      /* Poll watchdog/timed tasks every 256 bytes copied */
      if ((dataIdx & 0xFFu) == 0x00u)
      {
         FblLookForWatchdogVoid();
      }
   }
}

#define FBLMIO_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:

   MD_FblMio_0306_CopyEraseDriver:
      Reason:     Physical address can only be given to this function as integral type.
      Risk:       Write attempt to invalid address if function is called in wrong context.
      Prevention: Parameter is a configuration-dependent constant. The used configuration should be tested
                  during integration to ensure that the parameter is a valid physical address.

   MD_FblMio_0310_BlkInfo:
      Reason:     Data types are defined exactly the same but have different names.
      Risk:       Change in original data type can lead to incompatibility.
      Prevention: Original data type comes from processed pre-compiled memory driver. During processing it
                  must be ensured that the generated data type matches the typecast.

   MD_FblMio_Dir1.1_0315_TypedPtrVoidPtr:
      Reason:     vMemAccM functions expect untyped void pointers for user buffers.
      Risk:       No risk. Underlying uint8 pointer type is known.
      Prevention: Component tests ensures that the vMemAccM forwards and accesses the RAM buffers correctly.

   MD_FblMio_2003:
      Reason:     Preceding case does not end with a break statement.
      Risk:       No risk.
      Prevention: No prevention required.

  MD_FblMio_2895:
      Reason:     A negative value is casted to an unsigned type.
      Risk:       No risk, as the correct conversion is guaranteed by the C standard.
      Prevention: No prevention required.

*/
/***********************************************************************************************************************
 *  END OF FILE: FBL_MIO.C
 **********************************************************************************************************************/


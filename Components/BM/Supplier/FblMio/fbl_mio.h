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
 *  Version   Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2018-06-21 visrr   -             Initial version
 *  01.00.01   2019-03-27 visrr   ESCAN00102273 MemDriver_SegmentSize now works on different configurations
 *                                              Add MISRA deviations
 *  01.01.00   2019-06-04 visrr   ESCAN00103322 Add support for configurations without RAM device
 *  02.00.00   2019-08-08 visrie  FBL-267       Update to latest FblMio interface
 *                                ESCAN00104023 Fixed flash erase detection handling
 *  03.00.00   2019-12-04 visrie  FBL-456       Added support for flash synchronization
 *                                              Removed single memory driver handling
 *  03.00.01   2020-05-25 visrie  FBL-1883      Update to new MISRA version
 *  03.00.02   2020-09-09 vistmo  ESCAN00106727 Erase request might fail
 *  03.01.00   2020-12-04 visrie  FBL-1280      Support vMem drivers
 *                                ESCAN00108066 Fixed compare after write
 *  04.00.00   2021-08-03 vishor  FBL-2475      Add support for downloadable vMem driver
 *  04.00.01   2022-11-04 vishor  ESCAN00113090 Filter rules updated only
 *  04.01.00   2023-02-08 vistbe  FBL-6007      Add support for memory driver active feature
 **********************************************************************************************************************/

#ifndef FBL_MIO_H
# define FBL_MIO_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

# include "Std_Types.h"
# include "vMemAccM.h"
# include "fbl_mem2His.h"
# include "FblMio_Cfg.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/
/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define FBL_MIO_MAJOR_VERSION                    (4u)
# define FBL_MIO_MINOR_VERSION                    (1u)
# define FBL_MIO_PATCH_VERSION                    (0u)

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

# define MemDriver_SegmentSize                     (MemDriver_GetSegmentSize(currentAddressArea, ((FlashBlock[memSegment].end-FlashBlock[memSegment].begin)+1), FlashBlock[memSegment].begin))

# if defined( FBL_MEMDRV_SEGMENT_SIZE )
#  if ( FLASH_SEGMENT_SIZE > FBL_MEMDRV_SEGMENT_SIZE )
#   define FBL_MAX_SEGMENT_SIZE_MIO                FLASH_SEGMENT_SIZE
#  else
#   define FBL_MAX_SEGMENT_SIZE_MIO                FBL_MEMDRV_SEGMENT_SIZE
#  endif
# else
#  define FBL_MAX_SEGMENT_SIZE_MIO                 FLASH_SEGMENT_SIZE
# endif /* FBL_MEMDRV_SEGMENT_SIZE */

# if defined( FBL_MAX_SEGMENT_SIZE )
#  if ( FBL_MAX_SEGMENT_SIZE_MIO > FBL_MAX_SEGMENT_SIZE )
#   error "Define FBL_MAX_SEGMENT_SIZE from external only with values larger than determined through FblMio."
#  endif
# else
#  define FBL_MAX_SEGMENT_SIZE                     FBL_MAX_SEGMENT_SIZE_MIO
# endif /* FBL_MAX_SEGMENT_SIZE */

/** Device active state */
# define kMioDeviceIdle              0xFFu
# define kMioDeviceInternalFlash     0u

/* Defines to indicate, which function is active */
# define kMioFunctionNone            0u
# define kMioFunctionInit            1u
# define kMioFunctionDeinit          2u
# define kMioFunctionWrite           3u
# define kMioFunctionErase           4u
# define kMioFunctionVerify          5u
# define kMioFunctionRead            6u

# define MemDriver_RWriteSync(a, b, c)     MemDriver_RWriteAddrAreaSync(currentAddressArea, (a), (b), (c))
# define MemDriver_REraseSync(a, b)        MemDriver_REraseAddrAreaSync(currentAddressArea, (a), (b))
# define MemDriver_RReadSync(a, b, c)      MemDriver_RReadAddrAreaSync (currentAddressArea, (a), (b), (c))

# define MemDriver_SetAddressArea(a)       (currentAddressArea = (a))
# define MemDriver_GetAddressArea()        (currentAddressArea)

/* Compatibility defines */
# define MemDriver_InitBegin(a)              MemDriver_Begin((a), kMioFunctionInit, memDrvLst[(a)].initHook)
# define MemDriver_InitEnd(a)                MemDriver_End(memDrvLst[(a)].initHook)
# define MemDriver_REraseBegin(a)            MemDriver_Begin((a), kMioFunctionErase, memDrvLst[(a)].eraseHook)
# define MemDriver_REraseEnd(a)              MemDriver_End(memDrvLst[(a)].eraseHook)
# define MemDriver_RReadBegin(a)             MemDriver_Begin((a), kMioFunctionRead, memDrvLst[(a)].readHook)
# define MemDriver_RReadEnd(a)               MemDriver_End(memDrvLst[(a)].readHook)
# define MemDriver_RWriteBegin(a)            MemDriver_Begin((a), kMioFunctionWrite, memDrvLst[(a)].writeHook)
# define MemDriver_RWriteEnd(a)              MemDriver_End(memDrvLst[(a)].writeHook)
# define MemDriver_VerifyBegin(a)            MemDriver_Begin((a), kMioFunctionVerify, memDrvLst[(a)].verifyHook)
# define MemDriver_VerifyEnd(a)              MemDriver_End(memDrvLst[(a)].verifyHook)
# define MemDriver_DeinitBegin(a)            MemDriver_Begin((a), kMioFunctionDeinit, memDrvLst[(a)].deinitHook)
# define MemDriver_DeinitEnd(a)              MemDriver_End(memDrvLst[(a)].deinitHook)

#if defined( FBL_MIO_ENABLE_MEM_DRIVER_READY )
# define GetMemDriverReady(device)  (0u != (memDriverReady & ((vuint16)((vuint16)1u << (device)))))
# define SetMemDriverReady(device)  (memDriverReady |= (vuint16)((vuint16)1u << (device)))
# define ClrMemDriverReady(device)  (memDriverReady &= FblInvert16Bit((vuint16)1u << (device)))
#endif /* FBL_MIO_ENABLE_MEM_DRIVER_READY */

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/* Data type for byte array(s) of vMem drivers */
typedef struct
{
   tFblAddress       blockAddress;
   tFblLength        blockLength;
   V_MEMROM1  vuint8 V_MEMROM2 V_MEMROM3 *  blockSource;
}tFblMioDrvBlkInfo;

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define FBLMIO_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

void MemDriver_InitPowerOn( void );
IO_ErrorType MemDriver_InitSync( void * address );
IO_ErrorType MemDriver_DeinitSync( void * address );

/* MemDriver general interface */
IO_ErrorType MemDriver_RWriteAddrAreaSync( vMemAccM_AddressAreaIdType addrArea, IO_MemPtrType buf, IO_SizeType len, IO_PositionType addr );
IO_ErrorType MemDriver_REraseAddrAreaSync( vMemAccM_AddressAreaIdType addrArea, IO_SizeType len, IO_PositionType addr );
IO_ErrorType MemDriver_RReadAddrAreaSync( vMemAccM_AddressAreaIdType addrArea, IO_MemPtrType buf, IO_SizeType len, IO_PositionType addr );

vuint16 MemDriver_GetSegmentSize( vMemAccM_AddressAreaIdType addrArea, IO_SizeType len, IO_PositionType addr );

vsint16 FblMemSegmentNrGet( tFblAddress address );
tFblResult FblMemGetDeviceByAddr( tFblAddress address, V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * device );
tFblResult FblMemGetDeviceByRange( tFblAddress address, tFblLength length, V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * device );
tFblLength FblReadProm( tFblAddress address, V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * buffer, tFblLength length );
IO_ErrorType FblReadPromExt( tFblAddress address, V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * buffer, tFblLength length,
   V_MEMRAM1 tFblLength V_MEMRAM2 V_MEMRAM3 * actualReadCount );

void V_API_NEAR MemDriver_Begin( vuint8 device, vuint8 function, boolean hookEnabled );
void V_API_NEAR MemDriver_End( boolean hookEnabled );

void MemDriver_CopyDriver( V_MEMROM1 tFblMioDrvBlkInfo V_MEMROM2 V_MEMROM3 * drvBlkInfo, vuint8 numOfBlocks, vuint8 decryptValue,
                           IO_PositionType ramBufAddress, IO_SizeType ramBufSize );
void MemDriver_EraseDriver(IO_PositionType ramBufAddress, IO_SizeType ramBufSize);

# define FBLMIO_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

# define FBLMIO_START_SEC_VAR
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

V_MEMRAM0 extern V_MEMRAM1 vuint8                     V_MEMRAM2 memDrvDeviceActive;
V_MEMRAM0 extern V_MEMRAM1 vuint8                     V_MEMRAM2 memDrvFunctionActive;
#if defined( FBL_MIO_ENABLE_MEM_DRIVER_READY )
V_MEMRAM0 extern V_MEMRAM1 vuint16                    V_MEMRAM2 memDriverReady;
#endif /* FBL_MIO_ENABLE_MEM_DRIVER_READY */
V_MEMRAM0 extern V_MEMRAM1 vMemAccM_AddressAreaIdType V_MEMRAM2 currentAddressArea;

/** Memory segment handle */
V_MEMRAM0 extern V_MEMRAM1 vsint16                    V_MEMRAM2 memSegment;

# define FBLMIO_STOP_SEC_VAR
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

#if !defined( FBL_ENABLE_MULTIPLE_MEM_DEVICES )
# error "Feature needs to be always enabled."
#endif /* FBL_ENABLE_MULTIPLE_MEM_DEVICES */

#endif /* FBL_MIO_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_MIO.H
 **********************************************************************************************************************/

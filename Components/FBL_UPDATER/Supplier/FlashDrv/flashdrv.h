/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Flash Driver for Infineon TriCore (TC2xx/TC3xx)
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
 *  Version    Date        Author  Change Id          Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2017-01-12  visfr   ESCAN00093234      Support Aurix+ (TC3xx) derivatives
 *  02.01.00   2017-11-10  vapcel  ESCAN00095435      Support clearing ECC errors before verifying data
 *  02.02.00   2018-06-12  visrie  ESCAN00099655      No changes
 *  02.03.00   2018-07-06  visshs  ESCAN00099819      No changes
 *             2018-07-06  visshs  ESCAN00099845      [TC3xx B-Step] Changed FLASHCON2 register layout
 *             2018-07-06  visshs  ESCAN00098948      No changes
 *             2018-07-06  visshs  ESCAN00097719      No changes
 *             2018-07-06  visshs  ESCAN00099920      No changes
 *  02.05.00   2018-07-23  visshs  ESCAN00100136      No changes
 *                         visshs  ESCAN00100118      Removed Beta ESCAN
 *  02.06.00   2018-10-18  visshs  ESCAN00101095      Rework for MISRA 2012
 *                         visshs  ESCAN00101096      Add support for SWAP
 *  02.07.00   2019-01-31  visshs  ESCAN00101954      No changes
 *  02.07.01   2019-03-12  visrr   ESCAN00102457      No changes
 *  02.08.00   2019-04-05  visshs  ESCAN00102794      Added Bad Block Management support
 *                         visshs  ESCAN00102782      No changes
 *  02.08.01   2019-06-12  visshs  ESCAN00103388      No changes
 *  02.08.02   2019-06-12  visshs  ESCAN00103388      Fixed undeclared identifier
 *  02.08.03   2019-09-09  vistbe  ESCAN00104250      No changes
 *             2019-09-17  vistmo  FBL-383            No changes
 *                         vistmo  ESCAN00104337      Fixing if endif block misaligned
 *                         vistmo  ESCAN00104338      No changes
 *  02.08.04   2019-10-08  vistmo  ESCAN00104536      No changes
 *  02.08.05   2019-12-11  vistmo  ESCAN00105120      No changes
 *  02.09.00   2020-10-13  visrcn  ESCAN00106588      TC3xx: If flash is swapped, the verification after write may fail
 *  02.09.01   2022-03-25  visjdn  ESCAN00110854      No changes
 *                                 FBL-4596           Added/adapted MemMap sections
 **********************************************************************************************************************/

 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
#ifndef FBLDRVFLASH_TRICOREAURIXHIS_H
#define FBLDRVFLASH_TRICOREAURIXHIS_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblDrvFlash_TricoreAurixHis CQComponent : Implementation */
#define FBLDRVFLASH_TRICOREAURIXHIS_VERSION           0x0209u
#define FBLDRVFLASH_TRICOREAURIXHIS_RELEASE_VERSION   0x01u

/* Flash driver specific version information */
#define FLASH_DRIVER_VERSION_MCUTYPE      0xA3u       /**< MCU-Type definition for flash interface */
#define FLASH_DRIVER_VERSION_MASKTYPE     0x01u       /**< To be done - Mask type definition       */


#if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
#  define FLASH_DRIVER_VERSION_INTERFACE_REPLACE    0x06u
#else /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
# define FLASH_DRIVER_VERSION_INTERFACE_REPLACE    0x04u
#endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
# define FLASH_DRIVER_VERSION_INTERFACE_FAMILY 0x00u
/** Flash driver interface version          */
# define FLASH_DRIVER_VERSION_INTERFACE (FLASH_DRIVER_VERSION_INTERFACE_FAMILY | FLASH_DRIVER_VERSION_INTERFACE_REPLACE)

#define FLASH_DRIVER_VERSION_MAJOR        (tFlashUint8)(FBLDRVFLASH_TRICOREAURIXHIS_VERSION >> 8u)
#define FLASH_DRIVER_VERSION_MINOR        (tFlashUint8)(FBLDRVFLASH_TRICOREAURIXHIS_VERSION & 0xFFu)
#define FLASH_DRIVER_VERSION_PATCH        (tFlashUint8)(FBLDRVFLASH_TRICOREAURIXHIS_RELEASE_VERSION)

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Flash driver properties */
#define FLASH_SEGMENT_SIZE_PFLASH      0x20u                                  /**< Smallest writeable segment in program flash */
#define FLASH_SEGMENT_SIZE_DFLASH      0x08u                                  /**< Smallest writeable segment in data flash */
#define FLASH_SEGMENT_SIZE             FLASH_SEGMENT_SIZE_PFLASH         /**< Smallest writeable segment (overall) */
#define FLASH_BURST_SIZE_PFLASH        (FLASH_SEGMENT_SIZE_PFLASH * 8u)  /**< Writeable segment for burst mode (program flash) */
#define FLASH_BURST_SIZE_DFLASH        (FLASH_SEGMENT_SIZE_DFLASH * 4u)  /**< Writeable segment for burst mode (data flash) */
#define FBL_FLASH_DELETED              0x00u                                  /**< Erase value of flash memory */
#define FLASH_DRIVER_NOT_RELOCATABLE                                          /**< Flash driver is not relocatable */

/* Function call table offsets */
#define FLASH_DRIVER_HEADER_OFFSET     0x04u                                      /**< Start of function call table */
#define FLASH_DRIVER_INIT_OFFSET       (FLASH_DRIVER_HEADER_OFFSET + 0x00u)  /**< Flash driver init function */
#define FLASH_DRIVER_DEINIT_OFFSET     (FLASH_DRIVER_HEADER_OFFSET + 0x04u)  /**< Flash driver deinit function */
#define FLASH_DRIVER_ERASE_OFFSET      (FLASH_DRIVER_HEADER_OFFSET + 0x08u)  /**< Flash driver erase function */
#define FLASH_DRIVER_WRITE_OFFSET      (FLASH_DRIVER_HEADER_OFFSET + 0x0Cu)  /**< Flash driver write function */
# if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
#  define FLASH_DRIVER_REPLACE_OFFSET    (FLASH_DRIVER_HEADER_OFFSET + 0x10u)  /**< Flash driver replace logical block function */
# endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */

/* Defines to access version and type information */
/* PRQA S 3453 3 */ /* MD_MSR_19.7 */
#define FLASH_DRIVER_MCUTYPE(flashCode)      ((flashCode)[3u])
#define FLASH_DRIVER_MASKTYPE(flashCode)     ((flashCode)[2u])
#define FLASH_DRIVER_INTERFACE(flashCode)    ((flashCode)[0u])

/* Program type */
#define FLASH_PROGRAM_STANDARD         0x00u               /**< Programming of eraseable standard flash block */
#define FLASH_PROGRAM_WOP              0x01u               /**< Programming of WOP flash block */

/* Routine specific error codes */
#define kFlashFctInit                  0x00u               /**< Error during flash initialization */
#define kFlashFctDeinit                0x20u               /**< Error during flash deinit */
#define kFlashFctErase                 0x40u               /**< Error during flash erase */
#define kFlashFctWrite                 0x60u               /**< Error during flash write */
# if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
#  define kFlashFctReplace               0x10u             /**< Error during flash sector replacement */
# endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */

/* Common error codes */
#define kFlashOk                       0x00u               /**< Function call successful */
#define kFlashFailed                   0x01u               /**< Function call failed */
#define kFlashVerify                   0x02u               /**< Verify error */
#define kFlashInvalidParam             0x03u               /**< Invalid parameter */
#define kFlashInvalidAddress           0x04u               /**< Invalid flash address */
#define kFlashInvalidSize              0x05u               /**< Invalid flash size */
#define kFlashCmdBufFull               0x06u               /**< Buffer filling problem */
#define kFlashProtect                  0x07u               /**< Protection error */
#define kFlashAcc                      0x08u               /**< Flash access error */
#define kFlashInvalidVersion           0x09u               /**< Invalid version */
#define kFlashSequence                 0x0Au               /**< Sequence error */
#define kFlashAlreadyWritten           0x0Bu               /**< Flash memory is not erased */

/* Flash init error codes */
#define kFlashInitFailed               (kFlashFctInit | kFlashFailed)           /**< Flash initialization failed */
#define kFlashInitInvalidParam         (kFlashFctInit | kFlashInvalidParam)     /**< Invalid param at flash init */
#define kFlashInitInvalidAddr          (kFlashFctInit | kFlashInvalidAddress)   /**< Invalid address at flash init */
#define kFlashInitInvalidSize          (kFlashFctInit | kFlashInvalidSize)      /**< Invalid init size */
#define kFlashInitInvalidVersion       (kFlashFctInit | kFlashInvalidVersion)   /**< Invalid flash driver version */

/* Flash deinit error codes */
#define kFlashDeinitFailed             (kFlashFctDeinit | kFlashFailed)         /**< Flash deinitialization failed */
#define kFlashDeinitInvalidParam       (kFlashFctDeinit | kFlashInvalidParam)   /**< Invalid deinit parameter */

/* Flash erase error codes */
#define kFlashEraseFailed              (kFlashFctErase | kFlashFailed)          /**< Flash erase failed */
#define kFlashEraseVerify              (kFlashFctErase | kFlashVerify)          /**< Flash erase could not be verified */
#define kFlashEraseInvalidParam        (kFlashFctErase | kFlashInvalidParam)    /**< Invalid erase parameter */
#define kFlashEraseInvalidAddr         (kFlashFctErase | kFlashInvalidAddress)  /**< Invalid erase address */
#define kFlashEraseInvalidSize         (kFlashFctErase | kFlashInvalidSize)     /**< Invalid erase size */
#define kFlashEraseSequence            (kFlashFctErase | kFlashSequence)        /**< Erase sequence error */
#define kFlashEraseAcc                 (kFlashFctErase | kFlashAcc)             /**< Erase access error */
#define kFlashEraseCmdBufFull          (kFlashFctErase | kFlashCmdBufFull)      /**< Erase command buffer full */

/* Flash write error codes */
#define kFlashWriteFailed              (kFlashFctWrite | kFlashFailed)          /**< Flash write failed */
#define kFlashWriteVerify              (kFlashFctWrite | kFlashVerify)          /**< Flash write could not be verified */
#define kFlashWriteInvalidParam        (kFlashFctWrite | kFlashInvalidParam)    /**< Invalid write parameter */
#define kFlashWriteInvalidAddr         (kFlashFctWrite | kFlashInvalidAddress)  /**< Invalid write address */
#define kFlashWriteInvalidSize         (kFlashFctWrite | kFlashInvalidSize)     /**< Invalid write size */
#define kFlashWriteSequence            (kFlashFctWrite | kFlashSequence)        /**< Write sequence error */
#define kFlashWriteAcc                 (kFlashFctWrite | kFlashAcc)             /**< Write access error */
#define kFlashWriteCmdBufFull          (kFlashFctWrite | kFlashCmdBufFull)      /**< Write command buffer full */
#define kFlashWriteAlreadyWritten      (kFlashFctWrite | kFlashAlreadyWritten)  /**< Memory not erased before write */

# if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
#  define kFlashFctReplaceFailed       (kFlashFctReplace | kFlashFailed)        /**< Sector Erase or Replace failed */
# endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */

/* PRQA S 0883 1 */ /* MD_FblFlash_0883 */
/* Flash status register bits - global use */
# define FlashStatusLAllZero  0x00000020uL    /**< ECC status register - Read access all zeros (from last read access) */
# define FlashStatusLBlankD   0x00000100uL    /**< ECC status register - Read access blank digital (from last read access)  */
# define FlashStatusLBlankA   0x00000200uL    /**< ECC status register - Read access blank analog (from last read access)  */
# define FlashStatusAErr1     0x00010000uL    /**< ECC status register - Accumulated read access single bit ECC error */
# define FlashStatusAErr2     0x00020000uL    /**< ECC status register - Accumulated read access double bit ECC error */
# define FlashStatusAErr3     0x00040000uL    /**< ECC status register - Accumulated read access triple bit ECC error */
# define FlashStatusAErrM     0x00080000uL    /**< ECC status register - Accumulated read access multi-bit ECC error */
# define FlashStatusAAllZero  0x00200000uL    /**< ECC status register - Accumulated read access all zeros */
# define FlashStatusAErrAny   0x00800000uL    /**< ECC status register - Accumulated any read access ECC error */
# define FlashStatusABlankD   0x01000000uL    /**< ECC status register - Accumulated read access blank digital */
# define FlashStatusABlankA   0x02000000uL    /**< ECC status register - Accumulated read access blank analog */

/** Flash status register - combined ECC error flags */
# define FlashStatusPFEcc       ( FlashStatusAErr1 | FlashStatusAErr2 | FlashStatusAErrM )
# define FlashStatusDFEcc       ( FlashStatusAErr1 | FlashStatusAErr2 | FlashStatusAErr3 | FlashStatusAErrM )
# define FlashStatusPFZero      ( FlashStatusAAllZero | FlashStatusLAllZero )
# define FlashStatusDFZero      ( FlashStatusABlankD | FlashStatusABlankA | FlashStatusLBlankD | FlashStatusLBlankA )

/** Flash Control bits */
# if defined( FLASH_ENABLE_TC3XX_LEGACY_FLASHCON2_LAYOUT )
#  define FlashControlClearPFEccMask    0x00010000uL   /**< CPUx_FLASHCON2 Flash configuration register 2 - Clear all ECC status register (Mask) */
#  define FlashControlClearPFEccVal     0x00010000uL   /**< CPUx_FLASHCON2 Flash configuration register 2 - Clear all ECC status register (Value) */
# else /* FLASH_ENABLE_TC3XX_LEGACY_FLASHCON2_LAYOUT */
#  define FlashControlClearPFEccMask    0x00030000uL   /**< CPUx_FLASHCON2 Flash configuration register 2 - Clear all ECC status register (Mask) */
#  define FlashControlClearPFEccVal     0x00010000uL   /**< CPUx_FLASHCON2 Flash configuration register 2 - Clear all ECC status register (Value) */
# endif /* FLASH_ENABLE_TC3XX_LEGACY_FLASHCON2_LAYOUT */
# define FlashControlClearDFEccMask    0x00000003uL    /**< DF0 HF_ECCC - Clear all ECC status register (Mask) */
# define FlashControlClearDFEccVal     0x00000003uL    /**< DF0 HF_ECCC - Clear all ECC status register (Value) */

/* Flash control macros */
#define FLASH_UNCACHED_ADDRESS_MASK    0xA0000000uL    /**< Uncached address space mask */
#define FLASH_DFLASH_BASE_ADDRESS      0xAF000000uL    /**< Data flash base address */

/* Temporary data buffer handling */
#define FLASH_SIZE_TEMP_DATA           0x01u           /**< Size of temporary data buffer provided to flash driver */
#define FlashTempTrapBase              0u              /**< Trap base address index in temporary data buffer. */

#define FLASH_REQ_SYSTEM_RESET         0x00000100uL    /**< System Reset Request Trigger Reset Configuration */
#define FLASH_REQ_APPL_SW_RESET        0x00000200uL    /**< SW Reset Request Trigger Reset Configuration */

# if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
#  define kFlashReplace_None            0u             /**< No block replaced */
#  define kFlashReplace_FirstWriteOk    1u             /**< First write to flash was successful (normal) */
#  define kFlashReplace_SecondWriteOk   2u             /**< Repeated write to flash was successful */
#  define kFlashReplace_FirstEraseOk    3u             /**< First erase of flash was successful */
#  define kFlashReplace_SecondEraseOk   4u             /**< Repeated erase of flash was successful */
#  define kFlashReplace_SectorReplaceOk 5u             /**< Sector could not be erased, is replaced now */
#  define kFlashReplace_Failed          6u             /**< Sector has hard fails and can not be replaced */
# endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
# define kFlashReplace_addressMask ((tFlashUint32)((kFlashSectorSize - 1u) ^ ((tFlashUint32)0xFFFFFFFFuL)))

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/* His Standard Flashdrv types */
typedef unsigned long  tFlashData;              /**< Flash data object */
typedef unsigned long  tFlashAddress;           /**< Flash target address type */
typedef unsigned long  tFlashLength;            /**< Flash length type */
typedef unsigned short tFlashErrorCode;         /**< Flash Error Code */

/* Generic Flash basic types */
typedef unsigned char   tFlashUint8;             /**< equivalent to vuint8  */
typedef unsigned short  tFlashUint16;            /**< equivalent to vuint16 */
typedef unsigned long   tFlashUint32;            /**< equivalent to vuint32 */

typedef struct
{
   /* Version information */
   tFlashUint8        patchLevel;                /**< Flash driver patch level */
   tFlashUint8        minorVersion;              /**< Flash driver minor version */
   tFlashUint8        majorVersion;              /**< Flash driver major version */
   tFlashUint8        reserved1;                 /**< Reserved for future use */
   /* Return value/error code */
   tFlashErrorCode    errorCode;                 /**< Flash driver return value/error code */
   /* Erase/write input parameters */
   tFlashUint16       programmingType;           /**< Flash block type to be programmed (standard/WOP) */
   volatile tFlashUint32 * pflashEccStatReg;     /**< Pointer to flash ECC status register */
   tFlashUint32       flashEccStatMask;          /**< Flash ECC status register mask */
   volatile tFlashUint32 * pflashEccControlReg;  /**< Pointer to flash ECC control register */
   tFlashUint32       flashEccControlMask;       /**< Flash ECC control register mask */
   tFlashUint32       flashEccControlValue;      /**< Flash ECC control register Value */
   tFlashAddress      address;                   /**< Logical target address */
   tFlashAddress      verificationAddress;       /**< Modify address based on swap state */
   tFlashLength       writeLength;               /**< Write length in bytes */
   tFlashLength       eraseCount;                /**< Erase sector count */
   tFlashData*        data;                      /**< Pointer to data buffer (read only) */
   /* Pointer to watchdog trigger function */
   tFlashUint8        (* wdTriggerFct)(void);    /**< Pointer to watchdog handling function */
   /* Erase/write output parameters */
   tFlashData         intendedData;              /**< Intended data at error address */
   tFlashData         acutalData;                /**< Actual data at error address */
   tFlashAddress      errorAddress;              /**< Error address */
   /* Global storage of temporary data */
   tFlashUint32*      tempData;                  /**< Storage buffer for temporary data */
# if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
   tFlashUint32       replaceResult;             /**< State of Bad Block Management */
# endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
} tFlashParam;

/** Flash function pointer */
typedef void (* tFlashFct)(tFlashParam * flashParam);

/***********************************************************************************************************************
 *  EXTERNAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/* Flash API functions */
/* Do not use these functions as directly linked functions. Flash driver has to be
   compiled separately. Calls are done by flash call macros defined below.
*/

#define FLASHDRV_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

void ExpFlashInit   ( tFlashParam * flashParam );
void ExpFlashDeinit ( tFlashParam * flashParam );
void ExpFlashErase  ( tFlashParam * flashParam );
void ExpFlashWrite  ( tFlashParam * flashParam );
# if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
void ExpFlashReplace( tFlashParam * flashParam );
# endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */

#define FLASHDRV_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3453 TAG_FlashCallFunctions */ /* MD_MSR_19.7 */

/** Flash write function */
# define FLASH_DRIVER_WRITE(flashCode, flashParam)\
   ((tFlashFct)(*(tFlashUint32 *)&(flashCode)[FLASH_DRIVER_WRITE_OFFSET]))(flashParam)

/** Flash erase function */
# define FLASH_DRIVER_ERASE(flashCode, flashParam)\
   ((tFlashFct)(*(tFlashUint32 *)&(flashCode)[FLASH_DRIVER_ERASE_OFFSET]))(flashParam)

/** Flash init function */
# define FLASH_DRIVER_INIT(flashCode, flashParam)\
   ((tFlashFct)(*(tFlashUint32 *)&(flashCode)[FLASH_DRIVER_INIT_OFFSET]))(flashParam)

/** Flash deinitialization function */
# define FLASH_DRIVER_DEINIT(flashCode,flashParam)\
   ((tFlashFct)(*(tFlashUint32 *)&(flashCode)[FLASH_DRIVER_DEINIT_OFFSET]))(flashParam)
#  if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
#   define FLASH_DRIVER_REPLACE(flashCode,flashParam)\
    ((tFlashFct)(*(tFlashUint32 *)&(flashCode)[FLASH_DRIVER_REPLACE_OFFSET]))(flashParam)
#  endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */

/* PRQA L:TAG_FlashCallFunctions */

#endif /* FBLDRVFLASH_TRICOREAURIXHIS_H */
/***********************************************************************************************************************
 *  END OF FILE: FLASHDRV.H
 **********************************************************************************************************************/

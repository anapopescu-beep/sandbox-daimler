/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Flash Driver Wrapper for Infineon TriCore (TC2xx/TC3xx)
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
 *  Version    Date        Author  Change Id          Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2017-01-12  visfr   ESCAN00093233      Support Aurix+ (TC3xx) derivatives
 *  02.01.00   2017-04-11  visach  ESCAN00094704      No changes
 *  02.02.00   2017-08-07  vapcel  ESCAN00095434      No changes
 *                         visdlm  ESCAN00095909      No changes
 *  02.02.01   2017-11-15  visach  ESCAN00097373      No changes
 *  02.03.00   2018-07-20  visshs  ESCAN00099423      No changes
 *                         visshs  ESCAN00098948      No changes
 *                         visshs  ESCAN00099849      No changes
 *                         visshs  ESCAN00099892      No changes
 *                         visshs  ESCAN00099898      No changes
 *                         visshs  ESCAN00099718      No changes
 *  02.05.00   2018-07-24  visshs  ESCAN00100117      Removed Beta Escan
 *  02.05.01   2018-10-17  visshs  ESCAN00100769      No changes
 *  02.06.00   2018-10-18  visshs  ESCAN00101063      Added support for UCB Read/Erase/Write
 *                         visshs  ESCAN00101093      Add Support for SWAP
 *                         visshs  ESCAN00101091      Rework for MISRA 2012
 *  02.07.00   2018-12-10  visrr   ESCAN00101090      Release SWAP feature
 *  02.07.01   2019-02-01  visshs  ESCAN00101555      No changes
 *                         visshs  ESCAN00101571      No changes
 *                         visshs  ESCAN00101486      No changes
 *  02.08.00   2019-02-02  visrr   ESCAN00101897      [TC3xx] Add disable protection and resume protection support
 *                         visrr   ESCAN00101621      No changes
 *                         visrr   ESCAN00101978      No changes
 *                         visrr   ESCAN00101979      No changes
 *  02.08.01   2019-02-04  visrr   ESCAN00101989      [TC3xx] No changes
 *                         visrr   ESCAN00102009      [TC3xx SWAP] No changes
 *  02.08.02   2019-02-07  visshs  ESCAN00102029      No changes
 *                         visshs  ESCAN00102030      No changes
 *                         visshs  ESCAN00102050      No changes
 *                         visshs  ESCAN00102051      No changes
 *  02.08.03   2019-03-07  visrr   ESCAN00102401      No changes
 *  02.08.04   2019-03-15  vistmo  ESCAN00102392      [TC3xx SWAP] Separating SWAP enabling defines from Main and XD1
 *  02.09.00   2019-05-22  visshs  ESCAN00102860      [TC3xx] Added support for REPLACE_LOGICAL_SECTOR_API
 *                         vistbe  ESCAN00102501      No changes
 *                         visrr   ESCAN00103349      [TC3xx SWAP]  Swapping  shall allways maintain set password
 *                                 ESCAN00103350      [TC3xx SWAP]  SWAP UCB block handling don't follow Infineon sequence
 *  02.10.00   2019-07-04  visdod  ESCAN00103617      No changes
 *  02.10.01   2019-12-13  visrr   ESCAN00105026      No changes
 *                         vistmo  ESCAN00105111      No changes
 *  02.10.02   2020-07-27  visjdn  ESCAN00106075      No changes
 *                         vistmo  ESCAN00106075      No changes
 *  02.11.00   2020-10-12  visrcn  ESCAN00101898      No changes
 *                                 ESCAN00103956      [TC3xx SWAP only]: UCB swap erase UCB block for each swap
 *                                 ESCAN00107693      No changes
 *  02.11.01   2020-12-08  vistmo  ESCAN00107808      No changes
 *                                 ESCAN00107915      No changes
 *  02.11.02   2021-02-26  vishor  ESCAN00105410      No changes
 *                                 FBL-3057           Added/adapted MemMap sections
 *  02.11.03   2021-06-14  visjdn  ESCAN00109220      No changes
 *                                 ESCAN00109221      No changes
 *  02.12.00   2022-11-16  visjdn  FBL-5933           PFLASH Protection functionality implementation
 *  02.12.01   2023-01-10  vismix  ESCAN00113012      No changes
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
#ifndef FBLWRAPPERFLASH_TRICOREAURIXHIS_H
#define FBLWRAPPERFLASH_TRICOREAURIXHIS_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblWrapperFlash_TricoreAurixHis CQComponent : Implementation */
#define FBLWRAPPERFLASH_TRICOREAURIXHIS_VERSION           0x0212u
#define FBLWRAPPERFLASH_TRICOREAURIXHIS_RELEASE_VERSION   0x01u


/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Fbl_Fbt.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
 *
  */

/* May be defined via GENy preconfiguration to override this standard value. */
#  if !defined( FLASH_SIZE )
#   define FLASH_SIZE FLASHDRV_BLOCK0_LENGTH
#  endif

# if defined( FLASH_ENABLE_TRICORE_UCB_ERASE ) || defined( FLASH_ENABLE_TRICORE_UCB_WRITE ) || defined( FLASH_ENABLE_TRICORE_UCB_READ )
/* Definition of UCB blocks */
typedef enum
{
   FBLFLIO_UCB00_BMHD0_ORIG  =  0u,
   FBLFLIO_UCB01_BMHD1_ORIG  =  1u,
   FBLFLIO_UCB02_BMHD2_ORIG  =  2u,
   FBLFLIO_UCB03_BMHD3_ORIG  =  3u,
   FBLFLIO_UCB08_BMHD0_COPY  =  8u,
   FBLFLIO_UCB09_BMHD1_COPY  =  9u,
   FBLFLIO_UCB10_BMHD2_COPY  = 10u,
   FBLFLIO_UCB11_BMHD3_COPY  = 11u,
   FBLFLIO_UCB16_PFLASH_ORIG = 16u,
   FBLFLIO_UCB23_SWAP_ORIG   = 23u,
   FBLFLIO_UCB31_SWAP_COPY   = 31u,
   FBLFLIO_UCB32_OTP0_ORIG   = 32u,
   FBLFLIO_UCB40_OTP0_COPY   = 40u,
   FBLFLIO_UCB0X_NONE = 0xFFu
} tFblWrapperFlash_UcbBlock;

typedef enum
{
   FBLFLIO_UCB_CONFIRMATION_UNLOCKED  = 0u,
   FBLFLIO_UCB_CONFIRMATION_CONFIRMED = 1u,
   FBLFLIO_UCB_CONFIRMATION_ERRORED   = 2u
}tFblWrapperFlash_UcbConfirmation;

#  define FLASH_UCB_BLOCK_LENGTH              0x200u                /**< Length of a UCB Block */
#  define FLASH_UCB_BLOCK_PW_OFFSET(i)        (0x100u + ((i) * 4u)) /**< Offset of PWi in UCB Block */ /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define FLASH_UCB_CONFIRMATION_OFFSET       0x1F0u                /**< Offset of CONFIRMATION in UCB Block */
#  define FLASH_UCB_CONFIRMATION_READ_LENGTH  0x4u                  /**< Length of useful data in CONFIRMATION of UCB Block */
#  define FLASH_UCB_CONFIRMATION_WRITE_LENGTH 0x10u                 /**< Length of write data in CONFIRMATION of UCB Block (Manual: because
                                                                              of ECC 8 Bytes need to be written. The following 8 unused bytes are also written. */
#  define FLASH_UCB_SWAP_ENTRY_LENGTH         0x10u                 /**< Length of a entry in SWAP UCB */
#  define FLASH_UCB_SWAP_NR_OF_ENTRIES        0x10u                 /**< Number of UCB Swap entries */

/* UCB UNLOCKED / CONFIRMED codes */
#  define FLASH_UCB_CONFIRMATION_UNLOCKED_VALUE_UINT32 0x43211234uL
#  define FLASH_UCB_CONFIRMATION_UNLOCKED_VALUE_UINT8  0x34u, 0x12u, 0x21u, 0x43u
#  define FLASH_UCB_CONFIRMATION_CONFIRMED_VALUE_UINT32 0x57B5327FuL
#  define FLASH_UCB_CONFIRMATION_CONFIRMED_VALUE_UINT8  0x7Fu, 0x32u, 0xB5u, 0x57u
# endif /* FLASH_ENABLE_TRICORE_UCB_ERASE || FLASH_ENABLE_TRICORE_UCB_WRITE || FLASH_ENABLE_TRICORE_UCB_READ */

# if defined( FLASH_ENABLE_TRICORE_UCB_DISABLE_PROTECTION )
# define FLASH_DISABLE_PROTECTION_PW_LENGHT 8u
# endif /* FLASH_ENABLE_TRICORE_UCB_DISABLE_PROTECTION */


#if defined( kMioDeviceFlashWop ) && !defined( FLASH_ENABLE_WOP_SUPPORT )
# define FLASH_ENABLE_WOP_SUPPORT
#endif

#if defined( FLASH_ENABLE_TRICORE_SWAP )
# if !defined( FBL_FLASH_ENABLE_DFLASH_ERASED_DETECTION )
#  define FBL_FLASH_ENABLE_DFLASH_ERASED_DETECTION
# endif /* FBL_FLASH_ENABLE_DFLASH_ERASED_DETECTION */
#endif /* FLASH_ENABLE_TRICORE_SWAP */

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLFLIO_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

IO_ErrorType FlashDriver_InitSync ( void * address );
IO_ErrorType FlashDriver_DeinitSync ( void * address );
IO_ErrorType FlashDriver_RWriteSync ( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress);
IO_ErrorType FlashDriver_REraseSync ( IO_SizeType eraseLength, IO_PositionType eraseAddress );
IO_ErrorType FlashDriver_RReadSync ( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress );
IO_U32 FlashDriver_GetVersionOfDriver( void );
# if defined( FLASH_ENABLE_TRICORE_UCB_ERASE )
IO_ErrorType FlashDriver_UcbEraseSync(tFblWrapperFlash_UcbBlock block);
# endif /* FLASH_ENABLE_TRICORE_UCB_ERASE */
# if defined( FLASH_ENABLE_TRICORE_UCB_WRITE )
IO_ErrorType FlashDriver_UcbWriteSync(const IO_MemPtrType writeBuffer, IO_SizeType writeLength, tFblWrapperFlash_UcbBlock block, IO_PositionType writeOffset);
IO_ErrorType FlashDriver_UcbWriteConfirmed(tFblWrapperFlash_UcbBlock ucbBlock, tFblWrapperFlash_UcbConfirmation state);
# endif /* FLASH_ENABLE_TRICORE_UCB_WRITE */
# if defined( FLASH_ENABLE_TRICORE_UCB_READ )
IO_ErrorType FlashDriver_UcbReadSync(IO_MemPtrType readBuffer, IO_SizeType readLength, tFblWrapperFlash_UcbBlock block, IO_PositionType readOffset);
tFblWrapperFlash_UcbConfirmation FlashDriver_UcbReadConfirmation(tFblWrapperFlash_UcbBlock ucbBlock);
# endif /* FLASH_ENABLE_TRICORE_UCB_READ */
void FlashDriver_ResumeProtection( void );
IO_ErrorType FlashDriver_DisableProtection(vuint16 uc, const vuint32 password[8u]);
# if defined( FLASH_ENABLE_TRICORE_UCB_DISABLE_PROTECTION )
IO_ErrorType FlashDriver_UcbDisableProtection(tFblWrapperFlash_UcbBlock block, const vuint32 password[FLASH_DISABLE_PROTECTION_PW_LENGHT]);
# endif /* FLASH_ENABLE_TRICORE_UCB_DISABLE_PROTECTION */


#if defined( FLASH_ENABLE_WOP_SUPPORT )
IO_ErrorType FlashWopDriver_InitSync ( void * address );
IO_ErrorType FlashWopDriver_DeinitSync ( void * address );
IO_ErrorType FlashWopDriver_RWriteSync ( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress );
IO_ErrorType FlashWopDriver_REraseSync ( IO_SizeType eraseLength, IO_PositionType eraseAddress );
IO_ErrorType FlashWopDriver_RReadSync ( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress );
#endif /* FLASH_ENABLE_WOP_SUPPORT */

#if defined( FLASH_ENABLE_TRICORE_SWAP )
# if defined( FLASH_ENABLE_TRICORE_SWAP_ROUTINE )
IO_ErrorType FlashDriver_SwapPartitions( void );
# endif /* FLASH_ENABLE_TRICORE_SWAP_ROUTINE */
/* Configuration check */
# if defined( FLASH_ENABLE_TRICORE_UCB_ERASE )       && \
     defined( FLASH_ENABLE_TRICORE_UCB_WRITE )
# else
#  error "Swap feature requires activated UCB support"
# endif
#endif /* FLASH_ENABLE_TRICORE_SWAP */

#define FBLFLIO_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#  define FBLFLIO_FLASHCODE_START_SEC_VAR
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 extern V_MEMRAM1 vuint8 V_MEMRAM2 flashCode[FLASH_SIZE];
#  define FBLFLIO_FLASHCODE_STOP_SEC_VAR
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

/* Check UCB reading when PFlash protection is enabled */
#if defined( FLASH_ENABLE_PFLASH_PROTECTION )
# if defined( FLASH_ENABLE_TRICORE_UCB_READ ) 
# else
#  error "Wrong configuration for PFlash protection."
# endif
#endif

#endif /* FBLWRAPPERFLASH_TRICOREAURIXHIS_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_FLIO.H
 **********************************************************************************************************************/

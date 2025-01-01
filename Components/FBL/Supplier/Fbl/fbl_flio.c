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
 *  02.01.00   2017-04-11  visach  ESCAN00094704      Rework SFR definitions
 *  02.02.00   2017-08-07  vapcel  ESCAN00095434      Support clearing ECC errors before verifying data
                           visdlm  ESCAN00095909      Replaced define FBL_ENABLE_READ_ERASED_FLASH for Fbl_Hal component
 *  02.02.01   2017-11-15  visach  ESCAN00097373      Fix FlashReg[x] constants
 *  02.03.00   2018-07-20  visshs  ESCAN00099423      ECC status register will not cleared on TC3xx
 *                         visshs  ESCAN00098948      [TC3xx only]: ECC clear doesn't work
 *                         visshs  ESCAN00099849      [TC3xx B-Step] Changed FLASHCON2 register layout
 *                         visshs  ESCAN00099892      [TC3xx] Erased detection fails
 *                         visshs  ESCAN00099898      [TC3xx] Erase fails when > 512kB are deleted at once
 *                         visshs  ESCAN00099718      Compiler error: Function ExpFlashWrite() is not found
 *  02.05.00   2018-07-24  visshs  ESCAN00100117      Removed Beta Escan
 *  02.05.01   2018-10-17  visshs  ESCAN00100769      Read of memory may fail
 *  02.06.00   2018-10-18  visshs  ESCAN00101063      Added support for UCB Read/Erase/Write
 *                         visshs  ESCAN00101093      Add Support for SWAP
 *                         visshs  ESCAN00101091      Rework for MISRA 2012
 *  02.07.00   2018-12-10  visrr   ESCAN00101090      Release SWAP feature
 *  02.07.01   2019-02-01  visshs  ESCAN00101555      Replaced define FBL_ENABLE_READ_ERASED_FLASH for TC3xx use case
 *                         visshs  ESCAN00101571      Removed filter FBL_ENABLE_ASSERTION
                           visshs  ESCAN00101486      Fixed Erased detection (blank check) for TC3xx
 *  02.08.00   2019-02-02  visrr   ESCAN00101897      [TC3xx] Add disable protection and resume protection support
 *                         visrr   ESCAN00101621      [TC3xx SWAP] Bootloader may boot from bad partition
 *                         visrr   ESCAN00101978      [TC3xx SWAP] Blank check will be performed on swapped addresses
 *                         visrr   ESCAN00101979      [TC3xx] Accept read with only correctable ECCs
 *                         visshs  ESCAN00101980      Fixed ECC register access on uncached address read
 *  02.08.01   2019-02-04  visrr   ESCAN00101989      [TC3xx] Added missing return in FlashDriver_DisableProtection
 *                         visrr   ESCAN00102009      [TC3xx SWAP] Fixed Ecc handling
 *  02.08.02   2019-02-07  visshs  ESCAN00102029      [TC3xx] Fixed Erase detection (unaligned adresses)
 *                         visshs  ESCAN00102030      Fixed Compiler error: FlashXD1Driver_VerifyErasedPage()
 *                         visshs  ESCAN00102050      Added MemMap defines for VerifyErasedPage()
 *                         visshs  ESCAN00102051      Enforce alignment for ucb pattern arrays
 *  02.08.03   2019-03-07  visrr   ESCAN00102401      [TC3xx SWAP] Usage of FlashDriver_ActivateSwap locks the device
 *  02.08.04   2019-03-15  vistmo  ESCAN00102392      [TC3xx SWAP] Separating SWAP enabling defines from Main and XD1
 *  02.09.00   2019-05-22  visshs  ESCAN00102860      [TC3xx] Added support for REPLACE_LOGICAL_SECTOR_API
 *                         vistbe  ESCAN00102501      [TC3xx] PMU<x>_ADDRESS incorrect for derivatives with gaps in flash
 *                         visrr   ESCAN00103349      [TC3xx SWAP]  Swapping  shall allways maintain set password
 *                                 ESCAN00103350      [TC3xx SWAP]  SWAP UCB block handling don't follow Infineon sequence
 *  02.10.00   2019-07-04  visdod  ESCAN00103617      [TC3xx SWAP]  Add support for 8.0 MB PFLASH (SAx-TC3xxx-128Fx)
 *  02.10.01   2019-12-13  visrr   ESCAN00105026      [TC3xx SWAP]  Support IO_E_ERASED as return value for UCB password read
 *                         vistmo  ESCAN00105111      [TC3xx SWAP]  Fixed swap function non returning
 *  02.10.02   2020-07-27  visjdn  ESCAN00106075      ECC error bit(s) in FSR left set after call to FlashDriver_RReadSync
 *                         vistmo  ESCAN00106075      ECC error bit(s) in FSR left set after call to FlashDriver_RReadSync
 *  02.11.00   2020-10-12  visrcn  ESCAN00101898      [TC3xx SWAP] BETA version - the BSW module API FlashDriver_ActivateSwap
 *                                                    is in BETA state
 *                                 ESCAN00103956      No changes
 *                                 ESCAN00107693      TC3xx: If flash is swapped, the verification after write may fail
 *  02.11.01   2020-12-08  vistmo  ESCAN00107808      CPU crash occurs in flash driver write verification
 *                                 ESCAN00107915      Write verification fails
 *  02.11.02   2021-02-26  vishor  ESCAN00105410      Missing MemMap functionality for FlashDriver_ReadInternal()
 *                                 FBL-3057           Added/adapted MemMap sections
 *  02.11.03   2021-06-14  visjdn  ESCAN00109220      Flash write fails when SWAP is enabled
 *                                 ESCAN00109221      Flash write fails in case of multi block operation
 *  02.12.00   2022-10-18  visjdn  FBL-5933           PFLASH Protection functionality implementation
 *  02.12.01   2023-01-10  vismix  ESCAN00113012      CPU crash on FlashDriver_VerifyErasedPage
 **********************************************************************************************************************/

#define FBL_FLIO_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

#if defined( FLASH_ENABLE_TRICORE_UCB_DISABLE_PROTECTION ) || \
    defined( FLASH_ENABLE_TRICORE_UCB_ERASE ) || \
    defined( FLASH_ENABLE_TRICORE_UCB_WRITE ) || \
    defined( FLASH_ENABLE_TRICORE_UCB_READ )  || \
    defined( FBL_FLASH_ENABLE_ECC_SAFE_READ )
#include "flash_sfr.h"
#endif
#  include "flashrom.h"          /* Support for flash driver in ROM memory */

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLWRAPPERFLASH_TRICOREAURIXHIS_VERSION != 0x0212u ) || \
    ( FBLWRAPPERFLASH_TRICOREAURIXHIS_RELEASE_VERSION != 0x01u )
# error "Error in fbl_flio.c: Source and header file are inconsistent!"
#endif

#if ( FBLWRAPPERFLASH_TRICOREAURIXHIS_VERSION != _FBLWRAPPERFLASH_HW_VERSION ) || \
    ( FBLWRAPPERFLASH_TRICOREAURIXHIS_RELEASE_VERSION != _FBLWRAPPERFLASH_HW_RELEASE_VERSION )
# error "Error in fbl_flio.c: Source and v_ver.h are inconsistent!"
#endif

#if ( FLASH_DRIVER_VERSION_INTERFACE < 0x04u )
# error "Error in fbl_flio.c: Flash Driver Interface >= 4 required!"
#endif


/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_READ_ERASED_FLASH )
# if !defined( FBL_FLASH_ENABLE_ECC_SAFE_READ ) && \
     !defined( FBL_FLASH_DISABLE_ECC_SAFE_READ )
/** Compatibility define for GENy based bootloaders */
#  define FBL_FLASH_ENABLE_ECC_SAFE_READ
# endif
#endif

#if !defined( FBL_FLASH_SWAP_RETRY_CNT )
# define FBL_FLASH_SWAP_RETRY_CNT   4u
#endif

#define FLASH_SECTOR_SIZE(a)  (sizeof(a) / sizeof((a)[0u]))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/** Last valid element index of the flash structure array */
#define FLASH_STRUCT_LAST_INDEX  ((sizeof(flashStructure) / sizeof((flashStructure)[0u])) - 1u)  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/** Access macro to flash status register and masks within the flash structure array */
# define FLASHSTRUCT_REGS(i)   ((flashStructure[i]).flashRegs) /* PRQA S 3453 */ /* MD_MSR_19.7 */

/* Flash structure setup */
#  define D0_FLASH_PMU_UCB_BLOCKS  0u


/* Configure P-Flash PMU count */
/* Sizes are configured in GENy */
# if( FBL_PF0_SIZE == 0x00u )
#  error "No program flash PMU configured."
# elif( FBL_PF1_SIZE == 0x00u )
#  define P_FLASH_PMU_COUNT  1u
# elif( FBL_PF2_SIZE == 0x00u )
#  define P_FLASH_PMU_COUNT  2u
# elif( FBL_PF3_SIZE == 0x00u )
#  define P_FLASH_PMU_COUNT  3u
# elif( FBL_PF4_SIZE == 0x00u )
#  define P_FLASH_PMU_COUNT  4u
# elif( FBL_PF5_SIZE == 0x00u )
#  define P_FLASH_PMU_COUNT  5u
# else
#  define P_FLASH_PMU_COUNT  6u
# endif

# define D0_FLASH_PMU_COUNT  (1u + D0_FLASH_PMU_UCB_BLOCKS)

/* Configure PMU indices */
# define P_FLASH_START_PMU   0u                                      /**< First PMU in program flash */
# define P_FLASH_END_PMU     (P_FLASH_PMU_COUNT - 1u)                /**< Last PMU in program flash */
# define D0_FLASH_START_PMU  P_FLASH_PMU_COUNT                       /**< First PMU in data 0 flash */
# define D0_FLASH_END_PMU    (P_FLASH_END_PMU + D0_FLASH_PMU_COUNT)  /**< Last PMU in data 0 flash */

/* Physical program flash sector borders */
#  define FBL_PF_BORDER_SECTOR0  1024u
#  define FBL_PF_BORDER_SECTOR1  2048u
#  define FBL_PF_BORDER_SECTOR2  3072u

#define FBL_SECTOR_INDEX_INVALID  0xFFFFFFFFuL
# if defined( FLASH_ENABLE_TRICORE_UCB_ERASE ) || \
     defined( FLASH_ENABLE_TRICORE_UCB_WRITE ) || \
     defined( FLASH_ENABLE_TRICORE_UCB_READ )
#  define FLASH_UCB_ADDRESS(blockIndex) (FLASH_UCB_BASE + (((vuintx) (blockIndex)) * FLASH_UCB_BLOCK_LENGTH)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define FLASH_PFLASH_UCB          0x0010u
# endif /* FLASH_ENABLE_TRICORE_UCB_ERASE || FLASH_ENABLE_TRICORE_UCB_WRITE || FLASH_ENABLE_TRICORE_UCB_READ */
/** Target address for Disable Protection Sequence */
# define DISABLE_PROTECTION_ADDRESS 0x553Cu
# define RESUME_PROTECTION_ADDRESS  0x5554u
# define RESUME_PROTECTION_CMD      0x00F5u
# if defined( FBL_FLASH_ENABLE_ECC_SAFE_READ )
#  define VERIFY_ERASED_PAGE_ADDRESS_STEP_0 0xAA50u
#  define VERIFY_ERASED_PAGE_ADDRESS_STEP_1 0xAA58u
#  define VERIFY_ERASED_PAGE_ADDRESS_STEP_2 0xAAA8u
#  define VERIFY_ERASED_PAGE_VALUE_STEP_1 0x00u
#  define VERIFY_ERASED_PAGE_VALUE_STEP_2 0x80u
#  define VERIFY_ERASED_PAGE_VALUE_STEP_3 0x56u
# endif /* FBL_FLASH_ENABLE_ECC_SAFE_READ */
# if defined( FLASH_ENABLE_TRICORE_SWAP )
#  define FBL_SCU_CHIPID          FBL_IOS(vuint32, FBL_SCU_BASE, 0x140u) /**< Chip Identification Register*/
#  define FLASH_SWAP_CONFIRMED    FLASH_UCB_CONFIRMATION_CONFIRMED_VALUE_UINT32
#   define FLASH_SWAP_MARKERL_OFFSET            0u
#   define FLASH_SWAP_MARKERH_OFFSET            4u
#   define FLASH_SWAP_CONFIRMATIONL_OFFSET      8u
#   define FLASH_SWAP_CONFIRMATIONH_OFFSET     12u
#   define FLASH_OTP_X_PROCONTP_OFFSET      0x1E8u
#   if !defined(TRUE)
#    define TRUE                                1u
#   endif
#   if !defined(FALSE)
#    define FALSE                               0u
#   endif
# endif /* FLASH_ENABLE_TRICORE_SWAP */

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/* Flash structure definition */

/** Describes the structure of one physical flash sector. */
typedef struct
{
   /** Number of logical sectors in this physical sector */
   vuint32 logicalSectorCount;
   /** Pointer to field of logical sectors. This field should include the sizes of all logical sectors. */
   V_MEMROM1 vuint32 V_MEMROM2 V_MEMROM3 * logicalSectors;
} tPhysSector;

/** Describes the structure of the register and masks used in the PFx flash module. */
typedef struct
{
   /** Pointer to the xflash error correction status register */
   volatile V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3 * xfECC;
   /** Bitmask for xflash error correction status information */
   vuint32 maskECC;
   /** Bitmask for xflash all zeros/blank status information */
   vuint32 maskBLANK;
   /** Pointer to error correction control register */
   volatile V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3 * flashControl;
   /** Flash control ECC clear bit mask */
   vuint32 maskFC;
   /** Flash control ECC clear bit value */
   vuint32 valFC;
} tflashRegs;

/** Describes the structure of the PFx flash module. */
typedef struct
{
   /** Start address of flash memory */
   vuint32 startAddress;
   /** End address of flash memory */
   vuint32 endAddress;
   /** Number of included physical sector */
   vuint32 physicalSectorCount;
   /** Pointer to field of included physical sectors */
   V_MEMROM1 tPhysSector V_MEMROM2 V_MEMROM3 * physicalSectors;
   /** Pointer to array of flash register information */
   V_MEMROM1 tflashRegs V_MEMROM2 V_MEMROM3 * flashRegs;
   /** Max. Number of logical sectors which can be erased at once */
   vuint32 maxNumLogSectorsForErase;
} tFlashStructure;

# if defined( FLASH_ENABLE_TRICORE_SWAP )
typedef struct
{
  tFblWrapperFlash_UcbConfirmation  confState;      /**< confirmation state of the UCB block */
  vuint32                           swapIndex;      /**< current valid swap marker and confirmation index */
  vuint32                           swapValue;      /**< value at swapBase(swapIndex), shall be either 0x55 or 0xAA */
  vuint32                           nextIndex;      /**< next valid (erased) Index, where a write is allowed to */
  vuint8                            validEntryCnt;  /**< any value bigger than 1 indicate an unfinished log entry sequence */
} tFlashSwapUcbInfo;

typedef struct
{
   vuint32                          bootSwapValue;  /**< SCU.SWAPCTRL:ADDRCFG based swap value */
   tFblWrapperFlash_UcbBlock        bootUcbBlock;   /**< SWAP_* UCB confirmation based block, which shall hold bootSwapValue in one entry */
   tFlashSwapUcbInfo                swapOrig;       /**< SWAP_ORIG info structure */
   tFlashSwapUcbInfo                swapCopy;       /**< SWAP_COPY info structure */
   vuint8                           blockUpdReq;    /**< Indicates that dual password sequence must be applied */
} tFlashSwapSettings;

typedef struct
{
   vuint32 swapAreaStartAddr;
   vuint32 swapAreaEndAddr;
   vuint32 swapAreaOffset;
} tFlashSwapOffsetConfig;

typedef struct
{
   vuint32                 entryCount;
   const tFlashSwapOffsetConfig* cfgEntry;
} tFlashSwapDeviceConfig;

typedef struct
{
   vuint32                 devIdMask;
   vuint32                 devIdValue;
   const tFlashSwapDeviceConfig* devCfg;
} tFlashSwapDevLookUpTbl;
# endif /* FLASH_ENABLE_TRICORE_SWAP*/

typedef struct
{
   vuint16                 uc;       /**< UC: Identification of the UCBx for which the password checking shall be performed */
   vuint32                 protMask; /**< Bit mask for DMU_HF_PROTECT_* */
} tFlashProtectionMaskLookUpTbl;
/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#  define FBLFLIO_FLASHCODE_START_SEC_VAR
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 flashCode[FLASH_SIZE]; /* PRQA S 3408 */ /* MD_FblFlio_3408 */
#  define FBLFLIO_FLASHCODE_STOP_SEC_VAR
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define FBLFLIO_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

V_MEMRAM0 static V_MEMRAM1 tFlashParam V_MEMRAM2 flashParam;                               /**< Data structure used as interface to flash driver. */
/* PRQA S 3218 1 */ /* MD_FblFlio_3218 */
V_MEMRAM0 static V_MEMRAM1 vuint32 V_MEMRAM2          tempFlashData[FLASH_SIZE_TEMP_DATA]; /**< Place to store temporary data used by flash driver. */

#define FBLFLIO_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLFLIO_START_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Flash setup */
/** Logical sectors of PS0, PS1 and PS2 */
static V_MEMROM0 V_MEMROM1 vuint32 V_MEMROM2 physSector[] =
{
   0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u,
   0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u,
   0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u,
   0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u,
   0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u,
   0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u,
   0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u,
   0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u, 0x4000u
};
#  define PHYSSECTOR_0  physSector
#  define PHYSSECTOR_1  physSector
#  define PHYSSECTOR_2  physSector

/** Max. Number of logical blocks for one erase sequence */
#define P_FLASH_ERASE_SIZE 0x20u


/** Logical sectors of DF0 */
static V_MEMROM0 V_MEMROM1 vuint32 V_MEMROM2 physSector_D0[] =
{
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u,
   0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u, 0x1000u
};

/** Max. Number of logical blocks for one erase sequence */
#define D_FLASH_ERASE_SIZE 0x20u


# if defined( FLASH_ENABLE_TRICORE_SWAP )
/* The following arrays describe the known set of TC3xx swap able flash configurations */
static V_MEMROM0 V_MEMROM1 tFlashSwapOffsetConfig V_MEMROM2 flashSwapCfg_7of16Mb[] =
{
   { 0xA0000000uL, 0xA05FFFFFuL, 0x00600000uL },
   { 0xA0600000uL, 0xA0BFFFFFuL, 0xFFA00000uL }, /* -0x00600000 */
   { 0xA0C00000uL, 0xA0CFFFFFuL, 0x00300000uL },
   { 0xA0F00000uL, 0xA0FFFFFFuL, 0xFFD00000uL }  /* -0x00300000 */
};

static V_MEMROM0 V_MEMROM1 tFlashSwapOffsetConfig V_MEMROM2 flashSwapCfg_4of10Mb[] =
{
   { 0xA0000000uL, 0xA03FFFFFuL, 0x00600000uL },
   { 0xA0600000uL, 0xA09FFFFFuL, 0xFFA00000uL }  /* -0x00600000 */
};

static V_MEMROM0 V_MEMROM1 tFlashSwapOffsetConfig V_MEMROM2 flashSwapCfg_4of8Mb[] =
{
   { 0xA0000000uL, 0xA03FFFFFuL, 0x00600000uL },
   { 0xA0600000uL, 0xA09FFFFFuL, 0xFFA00000uL }  /* -0x00600000 */
};

static V_MEMROM0 V_MEMROM1 tFlashSwapOffsetConfig V_MEMROM2 flashSwapCfg_3of6Mb[] =
{
   { 0xA0000000uL, 0xA02FFFFFuL, 0x00300000uL },
   { 0xA0300000uL, 0xA05FFFFFuL, 0xFFD00000uL }  /* -0x00300000 */
};

static V_MEMROM0 V_MEMROM1 tFlashSwapOffsetConfig V_MEMROM2 flashSwapCfg_2of4Mb[] =
{
   { 0xA0000000uL, 0xA01FFFFFuL, 0x00300000uL },
   { 0xA0300000uL, 0xA04FFFFFuL, 0xFFD00000uL }  /* -0x00300000 */
};
# endif /* FLASH_ENABLE_TRICORE_SWAP */

/* PMU structure - PFlash */
/** PMU structure - PF0 */
static V_MEMROM0 V_MEMROM1 tPhysSector V_MEMROM2 pmuStructure0[] =
{
   { FLASH_SECTOR_SIZE(PHYSSECTOR_0), PHYSSECTOR_0 }
# if( FBL_PF0_SIZE > FBL_PF_BORDER_SECTOR0 )
  ,{ FLASH_SECTOR_SIZE(PHYSSECTOR_1), PHYSSECTOR_1 }
# endif
# if( FBL_PF0_SIZE > FBL_PF_BORDER_SECTOR1 )
  ,{ FLASH_SECTOR_SIZE(PHYSSECTOR_2), PHYSSECTOR_2 }
# endif
# if( FBL_PF0_SIZE > FBL_PF_BORDER_SECTOR2 )
#   error "Size of PF0 is wrong"
# endif
};

/** Flash status/control register and masks - PF0 */
static V_MEMROM0 V_MEMROM1 tflashRegs V_MEMROM2 flashReg0[] =
{
   /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
   { &FBL_PFI_ECCS(0u), FlashStatusPFEcc, FlashStatusPFZero, &FBL_CPU_FLASHCON(0, 2u), FlashControlClearPFEccMask, FlashControlClearPFEccVal }
};

# if( P_FLASH_PMU_COUNT >= 2u )
/** PMU structure - PF1 */
static V_MEMROM0 V_MEMROM1 tPhysSector V_MEMROM2 pmuStructure1[] =
{
   { FLASH_SECTOR_SIZE(PHYSSECTOR_0), PHYSSECTOR_0 }
#  if( FBL_PF1_SIZE > FBL_PF_BORDER_SECTOR0 )
  ,{ FLASH_SECTOR_SIZE(PHYSSECTOR_1), PHYSSECTOR_1 }
#  endif
#  if( FBL_PF1_SIZE > FBL_PF_BORDER_SECTOR1 )
  ,{ FLASH_SECTOR_SIZE(PHYSSECTOR_2), PHYSSECTOR_2 }
#  endif
#  if( FBL_PF1_SIZE > FBL_PF_BORDER_SECTOR2 )
#    error "Size of PF1 is wrong"
#  endif
};

/** Flash status/control register and masks - PF1 */
static V_MEMROM0 V_MEMROM1 tflashRegs V_MEMROM2 flashReg1[] =
{
   /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
   { &FBL_PFI_ECCS(1u), FlashStatusPFEcc, FlashStatusPFZero, &FBL_CPU_FLASHCON(1, 2u), FlashControlClearPFEccMask, FlashControlClearPFEccVal }
};

# endif /* P_FLASH_PMU_COUNT */
# if( P_FLASH_PMU_COUNT >= 3u )
/** PMU structure - PF2 */
static V_MEMROM0 V_MEMROM1 tPhysSector V_MEMROM2 pmuStructure2[] =
{
   { FLASH_SECTOR_SIZE(PHYSSECTOR_0), PHYSSECTOR_0 }
#  if( FBL_PF2_SIZE > FBL_PF_BORDER_SECTOR0 )
  ,{ FLASH_SECTOR_SIZE(PHYSSECTOR_1), PHYSSECTOR_1 }
#  endif
#  if( FBL_PF2_SIZE > FBL_PF_BORDER_SECTOR1 )
  ,{ FLASH_SECTOR_SIZE(PHYSSECTOR_2), PHYSSECTOR_2 }
#  endif
#  if( FBL_PF2_SIZE > FBL_PF_BORDER_SECTOR2 )
#    error "Size of PF2 is wrong"
#  endif
};

/** Flash status/control register and masks - PF2 */
static V_MEMROM0 V_MEMROM1 tflashRegs V_MEMROM2 flashReg2[] =
{
   /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
   { &FBL_PFI_ECCS(2u), FlashStatusPFEcc, FlashStatusPFZero, &FBL_CPU_FLASHCON(2, 2u), FlashControlClearPFEccMask, FlashControlClearPFEccVal }
};

# endif /* P_FLASH_PMU_COUNT */
# if( P_FLASH_PMU_COUNT >= 4u )
/** PMU structure - PF3 */
static V_MEMROM0 V_MEMROM1 tPhysSector V_MEMROM2 pmuStructure3[] =
{
   { FLASH_SECTOR_SIZE(PHYSSECTOR_0), PHYSSECTOR_0 }
#  if( FBL_PF3_SIZE > FBL_PF_BORDER_SECTOR0 )
  ,{ FLASH_SECTOR_SIZE(PHYSSECTOR_1), PHYSSECTOR_1 }
#  endif
#  if( FBL_PF3_SIZE > FBL_PF_BORDER_SECTOR1 )
  ,{ FLASH_SECTOR_SIZE(PHYSSECTOR_2), PHYSSECTOR_2 }
#  endif
#  if( FBL_PF3_SIZE > FBL_PF_BORDER_SECTOR2 )
#    error "Size of PF3 is wrong"
#  endif
};

/** Flash status/control register and masks - PF3 */
static V_MEMROM0 V_MEMROM1 tflashRegs V_MEMROM2 flashReg3[] =
{
   /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
   { &FBL_PFI_ECCS(3u), FlashStatusPFEcc, FlashStatusPFZero, &FBL_CPU_FLASHCON(3, 2u), FlashControlClearPFEccMask, FlashControlClearPFEccVal }
};

# endif /* P_FLASH_PMU_COUNT */
# if( P_FLASH_PMU_COUNT >= 5u )
/** PMU structure - PF4 */
static V_MEMROM0 V_MEMROM1 tPhysSector V_MEMROM2 pmuStructure4[] =
{
     { FLASH_SECTOR_SIZE(PHYSSECTOR_0), PHYSSECTOR_0 }
#  if( FBL_PF4_SIZE > FBL_PF_BORDER_SECTOR0 )
   , { FLASH_SECTOR_SIZE(PHYSSECTOR_1), PHYSSECTOR_1 }
#  endif
#  if( FBL_PF4_SIZE > FBL_PF_BORDER_SECTOR1 )
   , { FLASH_SECTOR_SIZE(PHYSSECTOR_2), PHYSSECTOR_2 }
#  endif
#  if( FBL_PF4_SIZE > FBL_PF_BORDER_SECTOR2 )
#   error "Size of PF4 is wrong"
#  endif
};

/** Flash status/control register and masks - PF4 */
static V_MEMROM0 V_MEMROM1 tflashRegs V_MEMROM2 flashReg4[] =
{
   /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
   { &FBL_PFI_ECCS(4u), FlashStatusPFEcc, FlashStatusPFZero, &FBL_CPU_FLASHCON(4, 2u), FlashControlClearPFEccMask, FlashControlClearPFEccVal }
};

# endif /* P_FLASH_PMU_COUNT */
# if( P_FLASH_PMU_COUNT >= 6u )
/** PMU structure - PF5 */
static V_MEMROM0 V_MEMROM1 tPhysSector V_MEMROM2 pmuStructure5[] =
{
   { FLASH_SECTOR_SIZE(PHYSSECTOR_0), PHYSSECTOR_0 }
#  if( FBL_PF5_SIZE > FBL_PF_BORDER_SECTOR0 )
#   error "Size of PF5 is wrong"
#  endif
};

/** Flash status/control register and masks - PF5 */
static V_MEMROM0 V_MEMROM1 tflashRegs V_MEMROM2 flashReg5[] =
{
   /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
   { &FBL_PFI_ECCS(5u), FlashStatusPFEcc, FlashStatusPFZero, &FBL_CPU_FLASHCON(5, 2u), FlashControlClearPFEccMask, FlashControlClearPFEccVal }
};

# endif /* P_FLASH_PMU_COUNT */

/** PMU structure - DFlash 0 */
static V_MEMROM0 V_MEMROM1 tPhysSector V_MEMROM2 df0Structure[] =
{
    { FLASH_SECTOR_SIZE(physSector_D0), physSector_D0 }
};


/** Flash status/control register and masks - DF0 */
static V_MEMROM0 V_MEMROM1 tflashRegs V_MEMROM2 flashRegDF[] =
{
   /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
   { &FBL_DMU_ECCS(0u), FlashStatusDFEcc, FlashStatusDFZero, &FBL_DMU_ECCC(0u), FlashControlClearDFEccMask, FlashControlClearDFEccVal }
};

/* Calculate start addresses */
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
# define PMU0_ADDRESS 0xA0000000uL
# define PMU1_ADDRESS 0xA0300000uL
# define PMU2_ADDRESS 0xA0600000uL
# define PMU3_ADDRESS 0xA0900000uL
# define PMU4_ADDRESS 0xA0C00000uL
# define PMU5_ADDRESS 0xA0F00000uL

# define FLASH_STRUCT_ECC_CONTROL_PF0  flashReg0
# define FLASH_STRUCT_ECC_CONTROL_PF1  flashReg1
# define FLASH_STRUCT_ECC_CONTROL_PF2  flashReg2
# define FLASH_STRUCT_ECC_CONTROL_PF3  flashReg3
# define FLASH_STRUCT_ECC_CONTROL_PF4  flashReg4
# define FLASH_STRUCT_ECC_CONTROL_PF5  flashReg5
# define FLASH_STRUCT_ECC_CONTROL_DF0  flashRegDF

/** Flash structure */
/* PRQA S 3218 1 */ /* MD_FblFlio_3218 */
static V_MEMROM0 V_MEMROM1 tFlashStructure V_MEMROM2 flashStructure[] =
{
   { PMU0_ADDRESS,   ((PMU0_ADDRESS + (FBL_PF0_SIZE * 1024uL)) - 1u), FLASH_SECTOR_SIZE(pmuStructure0), pmuStructure0, FLASH_STRUCT_ECC_CONTROL_PF0, P_FLASH_ERASE_SIZE } /* PRQA S 0303, 0306 */ /* MD_FblFlio_0303, MD_FblFlio_0306 */
# if( P_FLASH_PMU_COUNT >= 2u )
   , { PMU1_ADDRESS, ((PMU1_ADDRESS + (FBL_PF1_SIZE * 1024uL)) - 1u), FLASH_SECTOR_SIZE(pmuStructure1), pmuStructure1, FLASH_STRUCT_ECC_CONTROL_PF1, P_FLASH_ERASE_SIZE } /* PRQA S 0303, 0306 */ /* MD_FblFlio_0303, MD_FblFlio_0306 */
# endif
# if( P_FLASH_PMU_COUNT >= 3u )
   , { PMU2_ADDRESS, ((PMU2_ADDRESS + (FBL_PF2_SIZE * 1024uL)) - 1u), FLASH_SECTOR_SIZE(pmuStructure2), pmuStructure2, FLASH_STRUCT_ECC_CONTROL_PF2, P_FLASH_ERASE_SIZE } /* PRQA S 0303, 0306 */ /* MD_FblFlio_0303, MD_FblFlio_0306 */
# endif
# if( P_FLASH_PMU_COUNT >= 4u )
   , { PMU3_ADDRESS, ((PMU3_ADDRESS + (FBL_PF3_SIZE * 1024uL)) - 1u), FLASH_SECTOR_SIZE(pmuStructure3), pmuStructure3, FLASH_STRUCT_ECC_CONTROL_PF3, P_FLASH_ERASE_SIZE } /* PRQA S 0303, 0306 */ /* MD_FblFlio_0303, MD_FblFlio_0306 */
# endif
# if( P_FLASH_PMU_COUNT >= 5u )
   , { PMU4_ADDRESS, ((PMU4_ADDRESS + (FBL_PF4_SIZE * 1024uL)) - 1u), FLASH_SECTOR_SIZE(pmuStructure4), pmuStructure4, FLASH_STRUCT_ECC_CONTROL_PF4, P_FLASH_ERASE_SIZE } /* PRQA S 0303, 0306 */ /* MD_FblFlio_0303, MD_FblFlio_0306 */
# endif
# if( P_FLASH_PMU_COUNT >= 6u )
   , { PMU5_ADDRESS, ((PMU5_ADDRESS + (FBL_PF5_SIZE * 1024uL)) - 1u), FLASH_SECTOR_SIZE(pmuStructure5), pmuStructure5, FLASH_STRUCT_ECC_CONTROL_PF5, P_FLASH_ERASE_SIZE } /* PRQA S 0303, 0306 */ /* MD_FblFlio_0303, MD_FblFlio_0306 */
# endif
   ,
   { 0xAF000000uL, 0xAF0FFFFFuL, FLASH_SECTOR_SIZE(df0Structure), df0Structure, FLASH_STRUCT_ECC_CONTROL_DF0, D_FLASH_ERASE_SIZE } /* PRQA S 0303, 0306 */ /* MD_FblFlio_0303, MD_FblFlio_0306 */
};

# if defined( FLASH_ENABLE_TRICORE_UCB_WRITE ) || defined( FLASH_ENABLE_TRICORE_UCB_READ )
static V_MEMROM0 V_MEMROM1 vuint32 V_MEMROM2 ucbUnlockedPattern[FLASH_UCB_CONFIRMATION_WRITE_LENGTH >> 2u] = {FLASH_UCB_CONFIRMATION_UNLOCKED_VALUE_UINT32, 0x00000000u, 0x00000000u, 0x00000000u};
static V_MEMROM0 V_MEMROM1 vuint32 V_MEMROM2 ucbConfirmedPattern[FLASH_UCB_CONFIRMATION_WRITE_LENGTH >> 2u] = {FLASH_UCB_CONFIRMATION_CONFIRMED_VALUE_UINT32, 0x00000000u, 0x00000000u, 0x00000000u};
# endif /* FLASH_ENABLE_TRICORE_UCB_WRITE || FLASH_ENABLE_TRICORE_UCB_READ */

# if defined( FLASH_ENABLE_TRICORE_SWAP )
static V_MEMROM0 V_MEMROM1 tFlashSwapDeviceConfig V_MEMROM2 flashSwap16MBCfg = {(sizeof(flashSwapCfg_7of16Mb)/sizeof(flashSwapCfg_7of16Mb[0u])), flashSwapCfg_7of16Mb};
static V_MEMROM0 V_MEMROM1 tFlashSwapDeviceConfig V_MEMROM2 flashSwap10MBCfg = {(sizeof(flashSwapCfg_4of10Mb)/sizeof(flashSwapCfg_4of10Mb[0u])), flashSwapCfg_4of10Mb};
static V_MEMROM0 V_MEMROM1 tFlashSwapDeviceConfig V_MEMROM2 flashSwap8MBCfg  = {(sizeof(flashSwapCfg_4of8Mb)/sizeof(flashSwapCfg_4of8Mb[0u])), flashSwapCfg_4of8Mb};
static V_MEMROM0 V_MEMROM1 tFlashSwapDeviceConfig V_MEMROM2 flashSwap6MBCfg  = {(sizeof(flashSwapCfg_3of6Mb)/sizeof(flashSwapCfg_3of6Mb[0u])), flashSwapCfg_3of6Mb};
static V_MEMROM0 V_MEMROM1 tFlashSwapDeviceConfig V_MEMROM2 flashSwap4MBCfg  = {(sizeof(flashSwapCfg_2of4Mb)/sizeof(flashSwapCfg_2of4Mb[0u])), flashSwapCfg_2of4Mb};

/* Based on CHIPID value */
/* PRQA S 3218 1 */ /* MD_FblFlio_3218 */
static V_MEMROM0 V_MEMROM1 tFlashSwapDevLookUpTbl V_MEMROM2 flashDevLookUpTbl[] =
{
   {0x0F00F0C0uL, 0x0F009080uL, &flashSwap16MBCfg},   /* FSIZE = 0xF = 16MB, CHID = 0x9 = TC39xx, CHTEC = 0x2 = SAx-TC3xx */
   {0x0F00F0C0uL, 0x0C008080uL, &flashSwap10MBCfg},   /* FSIZE = 0xC = 10MB, CHID = 0x8 = TC38xx, CHTEC = 0x2 = SAx-TC3xx */
   {0x0F00F0C0uL, 0x0B008080uL, &flashSwap8MBCfg},    /* FSIZE = 0xB =  8MB, CHID = 0x8 = TC38xx, CHTEC = 0x2 = SAx-TC3xx */
   {0x0F00F0C0uL, 0x09007080uL, &flashSwap6MBCfg},    /* FSIZE = 0x9 =  6MB, CHID = 0x7 = TC37xx, CHTEC = 0x2 = SAx-TC3xx */
   {0x0F00F0C0uL, 0x09006080uL, &flashSwap4MBCfg},    /* FSIZE = 0x7 =  4MB, CHID = 0x6 = TC36xx, CHTEC = 0x2 = SAx-TC3xx */
   {0x0F00F0C0uL, 0x09005080uL, &flashSwap4MBCfg},    /* FSIZE = 0x7 =  4MB, CHID = 0x5 = TC35xx, CHTEC = 0x2 = SAx-TC3xx */
};
# endif /* FLASH_ENABLE_TRICORE_SWAP */

/* PRQA S 3218 1 */ /* MD_FblFlio_3218 */
static V_MEMROM0 V_MEMROM1 tFlashProtectionMaskLookUpTbl V_MEMROM2 flashProtMaskLookUpTbl[] =
{
   {0x0010u, 0x00000001uL},   /* UCB16: UCB_PFLASH_ORIG and UCB24: UCB_PFLASH_COPY disable global read and write protection for all PFLASHs */
   {0x0011u, 0x00000002uL},   /* UCB17: UCB_DFLASH_ORIG and UCB25: UCB_DFLASH_COPY */
   {0x0012u, 0x00000004uL},   /* UCB18: UCB_DBG_ORIG and UCB26: UCB_DBG_COPY */
   {0x0016u, 0x00000008uL},   /* UCB22: UCB_ECPRIO_ORIG and UCB30: UCB_ECPRIO_COPY */
   {0x0000u, 0x00000010uL},   /* UCB0..3: UCB_BMHDn_ORIG and UCB09..11: UCB_BMHDn_COPY (n=0 - 3) */
   {0x0017u, 0x00000020uL},   /* UCB23: UCB_SWAP_ORIG and UCB31: UCB_SWAP_COPY */
   {0x0020u, 0x00000100uL},   /* UCB16: UCB_PFLASH_ORIG and UCB24: UCB_PFLASH_COPY global read protection and sector specific write protection for PFLASH0 */
   {0x0021u, 0x00000200uL},   /* UCB16: UCB_PFLASH_ORIG and UCB24: UCB_PFLASH_COPY global read protection and sector specific write protection for PFLASH1 */
   {0x0022u, 0x00000400uL},   /* UCB16: UCB_PFLASH_ORIG and UCB24: UCB_PFLASH_COPY global read protection and sector specific write protection for PFLASH2 */
   {0x0023u, 0x00000800uL},   /* UCB16: UCB_PFLASH_ORIG and UCB24: UCB_PFLASH_COPY global read protection and sector specific write protection for PFLASH3 */
   {0x0024u, 0x00001000uL},   /* UCB16: UCB_PFLASH_ORIG and UCB24: UCB_PFLASH_COPY global read protection and sector specific write protection for PFLASH4 */
   {0x0025u, 0x00002000uL},   /* UCB16: UCB_PFLASH_ORIG and UCB24: UCB_PFLASH_COPY global read protection and sector specific write protection for PFLASH5 */
   {0x000Fu, 0x01000000uL}    /* UCB15: UCB_RETEST */
};

#define FBLFLIO_STOP_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLFLIO_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

static IO_ErrorType FlashDriver_CopyDrvToRam( void );
static vuint32 FlashDriver_GetPmuIndex( IO_PositionType address, vuint32 startIndex );
static IO_ErrorType FlashDriver_WriteToFlash ( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress, vuint16 programmingType);

# if ! defined( FLASH_IS_RAM_ADDRESS )
#define FLASH_IS_RAM_ADDRESS(a) ( (((a) < 0x80000000u) || ((a) > 0x8FFFFFFFu)) && (((a) < 0xA0000000u) || ((a) > 0xAFFFFFFFu)) )  /* PRQA S 3453 */ /* MD_MSR_19.7 */
# endif /* FLASH_IS_RAM_ADDRESS */
# if ! defined ( FBL_ENABLE_USR_RREAD_SYNC )
#  define FBLFLIO_STOP_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  define FBLFLIO_RAMCODE_START_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
static IO_ErrorType FlashDriver_ReadInternal(IO_MemPtrType readBuffer, const tflashRegs * regs, vuint32 startAddress, vuint32 length);
#  define FBLFLIO_RAMCODE_STOP_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  define FBLFLIO_START_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* FBL_ENABLE_USR_RREAD_SYNC */

# if defined( FLASH_ENABLE_TRICORE_SWAP )
static IO_ErrorType FlashDriver_GetUcbSwapBlockEntryState(tFblWrapperFlash_UcbBlock block, vuint32 index, vuint32* swapValue);
static void FlashDriver_GetUcbSwapBlockInfo(tFblWrapperFlash_UcbBlock block, tFlashSwapUcbInfo* const blockInfo);
static IO_ErrorType FlashDriver_GetUcbSwapState( tFlashSwapSettings* const swapState);
static IO_ErrorType FlashDriver_DualPasswortSequence(vuint32 newSwapValue, tFblWrapperFlash_UcbBlock referenceBlock, tFlashSwapSettings* const swapState);
static IO_ErrorType FlashDriver_SetUcbSwapEntry(tFblWrapperFlash_UcbBlock ucbBlock, vuint32 startIndex, vuint32 newSwapValue);
static void FlashDriver_UcbSwapCleanUp(tFblWrapperFlash_UcbBlock ucbBlock, vuint32 validIndex);
static IO_PositionType FlashDriver_GetCurrentSwapAddr(IO_PositionType normalAddress);
# endif /* FLASH_ENABLE_TRICORE_SWAP */

# if defined( FBL_FLASH_ENABLE_ECC_SAFE_READ )
#  define FBLFLIO_STOP_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  define FBLFLIO_RAMCODE_START_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
static IO_ErrorType FlashDriver_VerifyErasedPage(vuint32 address);
#  define FBLFLIO_RAMCODE_STOP_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  define FBLFLIO_START_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
static IO_ErrorType FlashDriver_VerifyErased(vuint32 address, vuint32 length);
# endif /* FBL_FLASH_ENABLE_ECC_SAFE_READ */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FlashDriver_CopyDrvToRam
 **********************************************************************************************************************/
/*! \brief       Copies the flash driver from ROM/Flash to RAM.
 *  \return      IO_E_OK.if driver is copied successfully, otherwise IO_E_NOT_OK
 **********************************************************************************************************************/
static IO_ErrorType FlashDriver_CopyDrvToRam( void )
{
   vuint32 index;
   IO_ErrorType returnValue;

   /* Check if address and length is correct */
   if ((flashCode != (IO_U8 *)FLASHDRV_BLOCK0_ADDRESS) || /* PRQA S 0306 */ /* MD_FblFlio_0306 */
       (FLASH_SIZE < ((vuint32 ) FLASHDRV_BLOCK0_LENGTH)))
   {
      returnValue = IO_E_NOT_OK;
   }
   else
   {
      for (index = 0uL; index < ((vuint32)FLASHDRV_BLOCK0_LENGTH); index++)
      {
         if ((index & 0x7FuL) == 0x00uL)
         {
            FblLookForWatchdogVoid();
         }
         flashCode[index] = FLASHDRV_DECRYPTDATA(flashDrvBlk0[index]);
      }
      returnValue = IO_E_OK;
   }

   return returnValue;
}

/***********************************************************************************************************************
 *  FlashDriver_WriteToFlash
 **********************************************************************************************************************/
/*! \brief       Writes data to flash memory.
 *  \details     This function programs flash memory by calling the flash driver routine stored in RAM. Write commands
 *               have to be done either in PFlash or DFlash - no commands which cover both modules are allowed.
 *  \pre         Flash driver is initialized, memory to be programmed is erased.
 *  \param[in]   writeBuffer Pointer to input data buffer.
 *  \param[in]   writeLength Data length. The length has to be aligned to the smallest writeable segment (32 Bytes
 *               in program flash, 8 Bytes in data flash).
 *  \param[in]   writeAddress Write target address (in flash memory). The target address has to be aligned to the
 *               smallest writeable segment (32 Bytes in program flash, 8 Bytes in data flash).
 *  \param[in]   programmingType Selects standard or WOP flash block
 *  \return      Reports write success or error code.
 **********************************************************************************************************************/
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
static IO_ErrorType FlashDriver_WriteToFlash ( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress, vuint16 programmingType)
{
   /* Control variables */
   IO_ErrorType     returnValue;
   vuint32          uncachedWriteAddress;
   vuint32          sectorIndex;
   IO_SizeType      deltaWriteLength;
   IO_SizeType      writeLengthRemaining;
   IO_PositionType  writePos;
# if defined( FLASH_ENABLE_TRICORE_SWAP )
   vuint32          pmu;
   vuint32          swapWriteAddress;
# endif

   /* Initialize variables */
   returnValue = kFlashOk;
   sectorIndex = 0uL;

   /* Move write address to uncached memory area */
   uncachedWriteAddress = writeAddress | FLASH_UNCACHED_ADDRESS_MASK;

   /* Check if PFlash or DFlash are used - alignment requirements differ */
   if ((uncachedWriteAddress & FLASH_DFLASH_BASE_ADDRESS) == FLASH_DFLASH_BASE_ADDRESS)
   {
      /* Check alignment of write address and write length. */
      if ((uncachedWriteAddress & (FLASH_SEGMENT_SIZE_DFLASH - 1uL)) != 0x00uL)
      {
         returnValue = kFlashWriteInvalidAddr;
      }
      else if ((writeLength & (FLASH_SEGMENT_SIZE_DFLASH - 1uL)) != 0x00uL)
      {
         returnValue = kFlashWriteInvalidSize;
      }
      else
      {
         /* Alignment correct - no error processing needed. */
      }
   }
   else
   {
      /* Check alignment of write address and write length. */
      if ((uncachedWriteAddress & (FLASH_SEGMENT_SIZE_PFLASH - 1uL)) != 0x00uL)
      {
         returnValue = kFlashWriteInvalidAddr;
      }
      else if ((writeLength & (FLASH_SEGMENT_SIZE_PFLASH - 1uL)) != 0x00uL)
      {
         returnValue = kFlashWriteInvalidSize;
      }
      else
      {
         /* Alignment correct - no error processing needed. */
      }
   }

   if (returnValue == kFlashOk)
   {
      writePos = 0uL;
      writeLengthRemaining = writeLength;

      do
      {
         sectorIndex = FlashDriver_GetPmuIndex(uncachedWriteAddress, sectorIndex);

         if (FLASH_STRUCT_LAST_INDEX >= sectorIndex)
         {
            /* Check if flash bank switch will happen */
            if ((uncachedWriteAddress + (writeLengthRemaining - 1uL)) > ((flashStructure[sectorIndex]).endAddress))
            {
               deltaWriteLength = (((flashStructure[sectorIndex]).endAddress) + 1uL) - uncachedWriteAddress;
            }
            else
            {
               deltaWriteLength = writeLengthRemaining;
            }
            /* PRQA S 0306, 2214 1 */ /* MD_FblFlio_0306, MD_FblAssert_Assertion */
            assertFblInternal((((vuint32)&(writeBuffer[writePos]) & (sizeof(tFlashData)-1u)) == 0u), kFblSysAssertParameterOutOfRange);

            /* Initialize parameters */
            flashParam.address = (tFlashAddress)uncachedWriteAddress;
            flashParam.writeLength = (tFlashLength)deltaWriteLength;
            flashParam.data = (tFlashData *)&(writeBuffer[writePos]); /* PRQA S 0310, 3305 */ /* MD_FblFlio_0310, MD_FblFlio_3305 */
            flashParam.programmingType = programmingType;

# if defined( FLASH_ENABLE_TRICORE_SWAP )
            swapWriteAddress = FlashDriver_GetCurrentSwapAddr(uncachedWriteAddress);
            pmu = FlashDriver_GetPmuIndex(swapWriteAddress, 0uL);
            if (FBL_SECTOR_INDEX_INVALID == pmu)
            {
               returnValue = IO_E_NOT_OK;
               break;
            }
            flashParam.verificationAddress = (tFlashAddress)swapWriteAddress;
            flashParam.pflashEccStatReg = FLASHSTRUCT_REGS(pmu)->xfECC;  /* Pointer to the ecc register */
            flashParam.flashEccStatMask = FLASHSTRUCT_REGS(pmu)->maskECC;  /* Relevant bitmask for the ecc detection */
# else
            flashParam.verificationAddress = flashParam.address;
            flashParam.pflashEccStatReg = FLASHSTRUCT_REGS(sectorIndex)->xfECC;  /* Pointer to the ecc register */
            flashParam.flashEccStatMask = FLASHSTRUCT_REGS(sectorIndex)->maskECC;  /* Relevant bitmask for the ecc detection */
# endif /* FLASH_ENABLE_TRICORE_SWAP */

            flashParam.pflashEccControlReg = FLASHSTRUCT_REGS(sectorIndex)->flashControl;
            flashParam.flashEccControlMask = FLASHSTRUCT_REGS(sectorIndex)->maskFC;
            flashParam.flashEccControlValue = FLASHSTRUCT_REGS(sectorIndex)->valFC;
            /* Call write routine of flash driver */
            FLASH_DRIVER_WRITE(flashCode, &flashParam); /* PRQA S 0303, 0305, 0310, 3305 */ /* MD_FblFlio_FlashApi */
            returnValue = flashParam.errorCode;
            writeLengthRemaining -= deltaWriteLength;
            uncachedWriteAddress += deltaWriteLength;
            writePos += deltaWriteLength;
         }
         else
         {
            returnValue = kFlashWriteInvalidAddr;
         }
      } while ((writeLengthRemaining > 0uL) && (kFlashOk == returnValue));
   }

   return returnValue;
} /* PRQA S 6030 */ /* MD_MSR_STCYC */

/***********************************************************************************************************************
 *  FlashDriver_GetPmuIndex
 **********************************************************************************************************************/
/*! \brief       Get PMU index of a given address
 *  \param[in]   address Memory address (has to be in flash memory range)
 *  \param[in]   startIndex Index number for checking
 *  \return      Index into pmuStructure, 0xFFFFFFFFuL if address is out of range
 **********************************************************************************************************************/
static vuint32 FlashDriver_GetPmuIndex( IO_PositionType address, vuint32 startIndex )
{
   vuint32 returnValue;
   vuint32 uncachedAddress;
   vuint32 index;

   /* Initialize variables */
   returnValue = FBL_SECTOR_INDEX_INVALID;

   /* Use uncached memory area to determine PMU */
   uncachedAddress = address | FLASH_UNCACHED_ADDRESS_MASK;

   index = startIndex;

   while ((index < FLASH_SECTOR_SIZE(flashStructure)) && (FBL_SECTOR_INDEX_INVALID == returnValue))
   {
      if ((uncachedAddress >= flashStructure[index].startAddress) && (uncachedAddress <= flashStructure[index].endAddress))
      {
         returnValue = index;
      }
      index++;
   }

   return returnValue;
}

# if defined( FLASH_ENABLE_TRICORE_SWAP )
/***********************************************************************************************************************
 *  FlashDriver_GetCurrentSwapAddr
 **********************************************************************************************************************/
/*! \brief          Calculates the equivalent swapped address from normal address
 *  \param[in]      Input Memory address (has to be in flash memory range)
 *  \return         Swapped Memory address
 **********************************************************************************************************************/
static IO_PositionType FlashDriver_GetCurrentSwapAddr( IO_PositionType normalAddress )
{
   vuint32 i;
   IO_PositionType swappedAddress;
   const tFlashSwapDeviceConfig* currentCfg = V_NULL;

   /* Initalize the swapped address */
   swappedAddress = normalAddress;

   /* Check that swap feature is active on the device */
   if((FLASH_DMU_HF_PROCONTP & FLASH_DMU_HF_PROCONTP_SWAPEN) == FLASH_SWAPEN_SOTA_ENABLED) /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
   {
      if(FLASH_SWAP_ADDRCFG_REGION_B == (FLASH_SCU_SWAPCTRL & FLASH_SCU_SWAPCTRL_ADDRCFG)) /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
      {
         /* Get device config */
         for(i = 0u; i < (sizeof(flashDevLookUpTbl)/sizeof(flashDevLookUpTbl[0])); i++)
         {
            if((FBL_SCU_CHIPID & flashDevLookUpTbl[i].devIdMask) == flashDevLookUpTbl[i].devIdValue) /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
            {
               currentCfg = (tFlashSwapDeviceConfig*)flashDevLookUpTbl[i].devCfg; /* PRQA S 0311 */ /* MD_FblFlio_0311 */
               break;
            }
         }
      }
   }

   /* Applying offset */
   if( V_NULL != currentCfg)
   {
      for(i = 0u; i < currentCfg->entryCount; i++)
      {
         if((normalAddress >= currentCfg->cfgEntry[i].swapAreaStartAddr) && (normalAddress <= currentCfg->cfgEntry[i].swapAreaEndAddr))
         {
            swappedAddress += currentCfg->cfgEntry[i].swapAreaOffset;
            break;
         }
      }
   }

   return swappedAddress;
}
# endif /* FLASH_ENABLE_TRICORE_SWAP */

# if defined( FBL_FLASH_ENABLE_ECC_SAFE_READ )
#  define FBLFLIO_STOP_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  define FBLFLIO_RAMCODE_START_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FlashDriver_VerifyErasedPage
 **********************************************************************************************************************/
/*! \brief     Execute the "Verify Erased Page" sequence
 *  \details   Checks if a "page" (= FLASH_SEGMENT_SIZE) of memory is in erased state
 *  \param[in] startAddress
 *  \pre startAddress must be aligned to segment size
 *  \return   IO_E_ERASED  page is erased
 *  \return   IO_E_OK      page is not erased
 *  \return   IO_E_NOT_OK  sequence failed
 **********************************************************************************************************************/
static IO_ErrorType FlashDriver_VerifyErasedPage(vuint32 address)
{
   IO_ErrorType returnValue;
   vuint32 errsr;

   /* Clear EVER and SQER */
   FLASH_DMU_HF_CLRE = (FLASH_DMU_HF_CLRE_CEVER | FLASH_DMU_HF_CLRE_CSQER | FLASH_DMU_HF_CLRE_CPROER); /* PRQA S 0303 */ /* MD_FblFlio_0303 */

   FBL_DSYNC();
   FLASH_COMMAND_CYCLE(VERIFY_ERASED_PAGE_ADDRESS_STEP_0, address); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
   FBL_DSYNC();
   FLASH_COMMAND_CYCLE(VERIFY_ERASED_PAGE_ADDRESS_STEP_1, VERIFY_ERASED_PAGE_VALUE_STEP_1); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
   FBL_DSYNC();
   FLASH_COMMAND_CYCLE(VERIFY_ERASED_PAGE_ADDRESS_STEP_2, VERIFY_ERASED_PAGE_VALUE_STEP_2); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
   FBL_DSYNC();
   FLASH_COMMAND_CYCLE(VERIFY_ERASED_PAGE_ADDRESS_STEP_2, VERIFY_ERASED_PAGE_VALUE_STEP_3); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
   FBL_DSYNC();

   /* Wait until BUSY flag is set */
   /* Please note that in case of debugging this line of code the program will freeze. Please set the breakpoint to the next instruction to solve the problem. */
   while(((FLASH_DMU_HF_STATUS & FLASH_DMU_HF_STATUS_BUSY_FLAGS) == 0u)) /* PRQA S 0303 */ /* MD_FblFlio_0303 */
   {
   }

   /* Wait until BUSY flag is cleared */
   while((FLASH_DMU_HF_STATUS & FLASH_DMU_HF_STATUS_BUSY_FLAGS) != 0u) /* PRQA S 0303 */ /* MD_FblFlio_0303 */
   {
      /* Trigger watchdog */
      FblLookForWatchdogVoid();
   }

   errsr = FLASH_DMU_HF_ERRSR; /* PRQA S 0303 */ /* MD_FblFlio_0303 */

   /*!
    * Internal comment removed.
 *
 *
 *
 *
 *
    */
   if ((errsr & FLASH_DMU_HF_ERRSR_SQER) == FLASH_DMU_HF_ERRSR_SQER)
   {
      /* Sequence Error */
      returnValue = IO_E_NOT_OK;
   }
   else if ((errsr & FLASH_DMU_HF_ERRSR_EVER) == FLASH_DMU_HF_ERRSR_EVER)
   {
      /* Memory is not erased = written */
      returnValue = IO_E_OK;
   }
   /*!
    * Internal comment removed.
 *
 *
 *
 *
    */
   else if ((errsr & FLASH_DMU_HF_ERRSR_PROER) == FLASH_DMU_HF_ERRSR_PROER)
   {
      /* Memory is not erased = written */
      returnValue = IO_E_OK;
   }
   else
   {
      /* Memory is erased */
      returnValue = IO_E_ERASED;
   }

   return returnValue;
}

#  define FBLFLIO_RAMCODE_STOP_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  define FBLFLIO_START_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  FlashDriver_VerifyErased
 **********************************************************************************************************************/
/*! \brief     Evaluate the erased state of
 *  \param[in] startAddress
 *  \param[in] length
 *  \return   IO_E_ERASED  memory is erased
 *  \return   IO_E_OK      memory is not erased
 *  \return   IO_E_NOT_OK  erased / not erased memory mixed OR sequence error
 **********************************************************************************************************************/
static IO_ErrorType FlashDriver_VerifyErased(vuint32 address, vuint32 length)
{
   IO_ErrorType returnValue = IO_E_OK;
   IO_ErrorType firstResult = IO_E_OK;
   vuint32 alignedEndAddress = 0x00000000uL;
   vuint32 alignedAddress = 0x00000000uL;
   vuint32 segmentSize;
   vuint32 addr;

   /* Check if PFlash or DFlash are used - alignment requirements differ */
   if ((address & FLASH_DFLASH_BASE_ADDRESS) == FLASH_DFLASH_BASE_ADDRESS)
   {
      segmentSize = FLASH_SEGMENT_SIZE_DFLASH;
   }
   else
   {
      segmentSize = FLASH_SEGMENT_SIZE_PFLASH;
   }

   if (IO_E_OK == returnValue) /* PRQA S 2991, 2995 */ /* MD_FblFlio_2991_2995_Configuration */
   {
      /* Round address down to next aligned address */
      alignedAddress    = address & FblInvert32Bit(segmentSize - 1u);
      /* Round length up to next aligned address */
      alignedEndAddress = (address + length + segmentSize - 1u) & FblInvert32Bit(segmentSize - 1u);

      /* Trigger watchdog */
      FblLookForWatchdogVoid();

      firstResult = FlashDriver_VerifyErasedPage(alignedAddress);
      returnValue = firstResult;
   }

   if ((IO_E_OK == returnValue) || (IO_E_ERASED == returnValue))
   {
      /* If first part of memory is not erased, expect all memory to be not erased. Or vice versa */
      for (addr = (alignedAddress + segmentSize); addr < alignedEndAddress; addr += segmentSize)
      {
         if ((addr & 0xFFu) == 0u)
         {
            /* Trigger watchdog */
            FblLookForWatchdogVoid();
         }
         if(firstResult != FlashDriver_VerifyErasedPage(addr))
         {
            returnValue = IO_E_NOT_OK;
            break;
         }
      }
   }

   return returnValue;
} /* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */
# endif /* FBL_FLASH_ENABLE_ECC_SAFE_READ */

# if ! defined ( FBL_ENABLE_USR_RREAD_SYNC )
#  define FBLFLIO_STOP_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  define FBLFLIO_RAMCODE_START_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  FlashDriver_ReadInternal
 **********************************************************************************************************************/
/*! \brief         Reads data from flash memory.
 *  \details       This function reads data from flash memory. It will report ECC errors and can be configured to detect
 *                 erased memory. It can only read data from one physical memory at once (e.g. CPUx PFlash).
 *                 NOTE: erased memory is detected by checking for "blank" memory (ECCS.ALL0)
 *  \precondition  If this function shall detect erased memory, it must be executed from RAM, otherwise the code flash
                   access by code execution would alter the result of the blank check.
 *  \param[in] readBuffer   buffer for read data
 *  \param[in] regs         pointer to register set structure
 *  \param[in] startAddress reading starts rom this address
 *  \param[in] length       Number of bytes to read
 *  \return IO_E_OK if read was successful, IO_E_NOT_OK if an ECC error is detected, IO_E_ERASED if area is blank.
 **********************************************************************************************************************/
static IO_ErrorType FlashDriver_ReadInternal(IO_MemPtrType readBuffer, const tflashRegs * regs, vuint32 startAddress, vuint32 length)
{
   IO_ErrorType returnValue;
   volatile vuint32 * ecccReg;
   vuint32 ecccMask;
   vuint32 ecccValue;

   const volatile vuint32 * eccsReg;
   vuint32 eccsMaskEcc;

   tflashRegs localRegs;
#  if defined( FLASH_ENABLE_TRICORE_SWAP )
   vuint32 pmu;
#  endif
   vuint32 uncachedAddress;

   uncachedAddress = startAddress | FLASH_UNCACHED_ADDRESS_MASK;
   localRegs = *regs;

#  if defined ( FBL_FLASH_ENABLE_ECC_SAFE_READ )
#   if defined( FBL_FLASH_ENABLE_DFLASH_ERASED_DETECTION )
#   else /* FBL_FLASH_ENABLE_DFLASH_ERASED_DETECTION */
   if ((uncachedAddress & FLASH_DFLASH_BASE_ADDRESS) == FLASH_DFLASH_BASE_ADDRESS)
   {
      /*!
       * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
       */
      returnValue = IO_E_OK;
   }
   else
#   endif /* FBL_FLASH_ENABLE_DFLASH_ERASED_DETECTION */
   {
      returnValue = FlashDriver_VerifyErased(uncachedAddress, length);
   }

   if(returnValue == IO_E_ERASED)
   {
      /* Memory is erased, do not read and copy data, do not care for ECC */
   }
   else
#  endif /* FBL_FLASH_ENABLE_ECC_SAFE_READ */
   {
      /* returnValue is either already IO_E_OK or IO_E_NOT_OK. IO_E_NOT_OK indicate that VerifyErased function didn't work, e.g. because of partially written/erased memory.
         There is no reason for not continue reading the memory */
      returnValue = IO_E_OK; /* PRQA S 2982 */ /* MD_FblFlio_2982_Configuration */
#  if defined( FLASH_ENABLE_TRICORE_SWAP )
      /* Check if address is in PFLASH address Range */
      if ((uncachedAddress >= flashStructure[P_FLASH_START_PMU].startAddress) && (uncachedAddress <= flashStructure[P_FLASH_END_PMU].endAddress))
      {
         /* Locally swap from original flash addresses to "SWAPed" addresses based on current swap state */
         uncachedAddress = FlashDriver_GetCurrentSwapAddr(uncachedAddress);

         pmu = FlashDriver_GetPmuIndex(uncachedAddress, 0uL);
         if (FBL_SECTOR_INDEX_INVALID == pmu)
         {
            returnValue = IO_E_NOT_OK;
         }
         else
         {
            localRegs.xfECC = FLASHSTRUCT_REGS(pmu)->xfECC;
            localRegs.maskECC = FLASHSTRUCT_REGS(pmu)->maskECC;
         }
      }
      if(returnValue == IO_E_OK)
#  endif /* FLASH_ENABLE_TRICORE_SWAP */
      {
         /* First clear all affected ECC error flags */
         FblHwRegisterUnlock(FBL_WDT_CPU);

         /* Read constants from structure in Flash */
         ecccReg   = localRegs.flashControl;
         ecccMask  = localRegs.maskFC;
         ecccValue = localRegs.valFC;
         eccsReg = localRegs.xfECC;
         eccsMaskEcc = localRegs.maskECC;
#  if defined(FLASH_ENABLE_READ_INGNORING_CORRECTABLE_ECCS)
         eccsMaskEcc &= FblInvert32Bit(FlashStatusAErr1 | FlashStatusAErr2);
#  endif /* FLASH_ENABLE_READ_INGNORING_CORRECTABLE_ECCS */

         (*ecccReg) = ((*ecccReg) & FblInvert32Bit(ecccMask)) | (ecccValue & ecccMask);

         FblHwRegisterLock(FBL_WDT_CPU);

         {
            /* Memory is not erased: Copy data */
            (void)MEMCPY((void *) readBuffer, (void *) uncachedAddress, length); /* PRQA S 0306, 0314, 0326 */ /* MD_FblFlio_0306, MD_FblFlio_0314, MD_FblFlio_0326 */

            if ( ( (*eccsReg) & eccsMaskEcc) != 0uL )
            {
              /* Every ECC error will stop the whole read request and return an error */
              returnValue = IO_E_NOT_OK;
            }
            else
            {
               /* No ECC errors detected */
               returnValue = IO_E_OK;
            }
         }
      }
   }

   return returnValue;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

#  define FBLFLIO_RAMCODE_STOP_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#  define FBLFLIO_START_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* FBL_ENABLE_USR_RREAD_SYNC */

# if defined( FLASH_ENABLE_TRICORE_SWAP )
/***********************************************************************************************************************
 *  FlashDriver_GetUcbSwapBlockEntryState
 **********************************************************************************************************************/
/*! \brief       Get entry state of log entry
 *  \param[in]   block - can be either FBLFLIO_UCB23_SWAP_ORIG or FBLFLIO_UCB31_SWAP_COPY
 *  \param[in]   index - log entry index
 *  \param[out]  swapValue   - will be filled in case of IO_E_OK
 *  \return      IO_E_OK     - Entry is valid
 *               IO_E_NOT_OK - Entry is invalid
 *               IO_E_ERASED - Entry is empty
 **********************************************************************************************************************/
static IO_ErrorType FlashDriver_GetUcbSwapBlockEntryState(tFblWrapperFlash_UcbBlock block, vuint32 index, vuint32* swapValue)
{
   IO_ErrorType retVal;
   vuint32 readBuffer[(FLASH_UCB_SWAP_ENTRY_LENGTH >> 2u)];
   vuint32 markerL, markerH;
   vuint32 confirmationL, confirmationH;

   /* Read current UCB swap entry - Any entry causing read error will be ignored */
   retVal = FlashDriver_UcbReadSync((vuint8*)readBuffer, FLASH_UCB_SWAP_ENTRY_LENGTH, block, (index * FLASH_UCB_SWAP_ENTRY_LENGTH));

   if (retVal == IO_E_OK)
   {
      retVal = IO_E_NOT_OK;

      markerL = readBuffer[(FLASH_SWAP_MARKERL_OFFSET >> 2u)];
      markerH = readBuffer[(FLASH_SWAP_MARKERH_OFFSET >> 2u)];
      confirmationL = readBuffer[(FLASH_SWAP_CONFIRMATIONL_OFFSET >> 2u)];
      confirmationH = readBuffer[(FLASH_SWAP_CONFIRMATIONH_OFFSET >> 2u)];

      /* Check entry validity */
      if ((confirmationH == (FLASH_UCB_ADDRESS(block) + (index * FLASH_UCB_SWAP_ENTRY_LENGTH) + FLASH_SWAP_CONFIRMATIONL_OFFSET)) &&
         (confirmationL == FLASH_SWAP_CONFIRMED) &&
         (markerH == (FLASH_UCB_ADDRESS(block) + (index * FLASH_UCB_SWAP_ENTRY_LENGTH) + FLASH_SWAP_MARKERL_OFFSET)) && /* PRQA S 2985 */ /* MD_FBL_2985_RedundantOperation */
         ((markerL == 0x55uL) || (markerL == 0xAAuL))) /* PRQA S 2985 */ /* MD_FBL_2985_RedundantOperation */
      {
         *swapValue = markerL;
         retVal = IO_E_OK;
      }
   }

   return retVal;
}

/***********************************************************************************************************************
 *  FlashDriver_GetUcbSwapBlockInfo
 **********************************************************************************************************************/
/*! \brief       Reads UCB entries and provide relevant information back to caller
 *  \param[in]   block - can be either FBLFLIO_UCB23_SWAP_ORIG or FBLFLIO_UCB31_SWAP_COPY
 *  \param[out]  provided structure will be filled with information
 **********************************************************************************************************************/
static void FlashDriver_GetUcbSwapBlockInfo(tFblWrapperFlash_UcbBlock block, tFlashSwapUcbInfo* const blockInfo)
{
   vuintx index;
   IO_ErrorType readResult;

   /* Initialize some entries */
   blockInfo->validEntryCnt = 0x00u;
   blockInfo->swapIndex     = 0xFFFFFFFFuL;
   blockInfo->nextIndex     = 0xFFFFFFFFuL;
   blockInfo->swapValue     = 0x00u;

   for (index = 0; index < FLASH_UCB_SWAP_NR_OF_ENTRIES; index++)
   {
      readResult = FlashDriver_GetUcbSwapBlockEntryState(block, index, &blockInfo->swapValue);
      if(IO_E_OK == readResult)
      {
         /* Valid entry found */
         blockInfo->validEntryCnt++;          /* Count valid entries to find possible errors */
         blockInfo->swapIndex = index;        /* Remember latest index */
         blockInfo->nextIndex = 0xFFFFFFFFuL; /* Reset nextIndex to find the next free index after this */
      }

      if ((readResult == IO_E_ERASED) && (blockInfo->nextIndex == 0xFFFFFFFFuL))
      {
         /* First empty entry after swapIndex */
         blockInfo->nextIndex = index;
      }
   }
}

/***********************************************************************************************************************
 *  FlashDriver_GetUcbSwapState
 **********************************************************************************************************************/
/*! \brief       Reads current UCB states and evaluate last valid entry used by next reset
 *  \param[out]  provided structure will be filled with information
 *  \return      IO_E_OK in case of success, IO_E_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
static IO_ErrorType FlashDriver_GetUcbSwapState( tFlashSwapSettings* const swapState)
{
   IO_ErrorType retVal = IO_E_OK;

   /* Set initial values */
   swapState->bootUcbBlock  = FBLFLIO_UCB0X_NONE;
   swapState->bootSwapValue = 0x00u;
   swapState->blockUpdReq   = FALSE;

   /* Check that swap feature is active on the device */
   if ((FLASH_DMU_HF_PROCONTP & FLASH_DMU_HF_PROCONTP_SWAPEN) != FLASH_SWAPEN_SOTA_ENABLED)    /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
   {
     retVal = IO_E_NOT_OK;
   }

   /* Read setting initialized with last system reset */
   if (IO_E_OK == retVal)
   {
     vuint32 currentSwapSetting;

     currentSwapSetting = FLASH_SCU_SWAPCTRL & FLASH_SCU_SWAPCTRL_ADDRCFG;    /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
     switch (currentSwapSetting)
     {
       case 0x01: /* Standard address selection: A active, B inactive */
         swapState->bootSwapValue = 0x00000055u; /* Current value for alternate address mode */
         break;
       case 0x02: /* Alternate address selection: B active, A inactive */
         swapState->bootSwapValue = 0x000000AAu; /* Current value for standard address mode */
         break;
       default:
         retVal = IO_E_NOT_OK;
         break;
     }
   }

   if (IO_E_OK == retVal)
   {
     swapState->swapOrig.confState = FlashDriver_UcbReadConfirmation(FBLFLIO_UCB23_SWAP_ORIG);
     swapState->swapCopy.confState = FlashDriver_UcbReadConfirmation(FBLFLIO_UCB31_SWAP_COPY);

     /* Check which UCB block holds the latest valid information (is chosen by TC3xx boot sequence )*/
     if((swapState->swapOrig.confState == FBLFLIO_UCB_CONFIRMATION_CONFIRMED) || (swapState->swapOrig.confState == FBLFLIO_UCB_CONFIRMATION_UNLOCKED))
     {
       swapState->bootUcbBlock = FBLFLIO_UCB23_SWAP_ORIG;

       if (swapState->swapOrig.confState != swapState->swapCopy.confState)
       {
         /* If SWAP_COPY is not a copy of SWAP_ORIG the dual password sequence was interrupted and needs to be restarted. Treat COPY as ERRORED */
         swapState->swapCopy.confState = FBLFLIO_UCB_CONFIRMATION_ERRORED;
         swapState->blockUpdReq = TRUE;
       }
     }
     else if((swapState->swapCopy.confState == FBLFLIO_UCB_CONFIRMATION_CONFIRMED) || (swapState->swapCopy.confState == FBLFLIO_UCB_CONFIRMATION_UNLOCKED))
     {
       /* ORIG is not valid - take boot settings from COPY and treat ORIG as ERRORED */
       swapState->bootUcbBlock = FBLFLIO_UCB31_SWAP_COPY;
       swapState->swapOrig.confState = FBLFLIO_UCB_CONFIRMATION_ERRORED;
       swapState->blockUpdReq = TRUE;
     }
     else
     {
       /* Reaching this state means that both UCB blocks are ERRORED or ERASED. The device cannot boot in this state. Only reason to get here is that the last SWAP
        * caused dual password sequence, which was interrupted (this explain one UCB block state). In the time between power up and now the 2nd UCB block got an ECC
        * issue and became therefore invalid,too.
        */
       swapState->swapOrig.confState = FBLFLIO_UCB_CONFIRMATION_ERRORED;
       swapState->swapCopy.confState = FBLFLIO_UCB_CONFIRMATION_ERRORED;

       /* We still have the boot swap value here, but the password may got lost */
       retVal = IO_E_NOT_OK;
     }
   }

   /* Get informations from the log entries contained in UCB blocks */
   if ((IO_E_OK == retVal) && (swapState->swapOrig.confState != FBLFLIO_UCB_CONFIRMATION_ERRORED))
   {
     FlashDriver_GetUcbSwapBlockInfo(FBLFLIO_UCB23_SWAP_ORIG, &(swapState->swapOrig));
   }

   if ((IO_E_OK == retVal) && (swapState->swapCopy.confState != FBLFLIO_UCB_CONFIRMATION_ERRORED))
   {
     FlashDriver_GetUcbSwapBlockInfo(FBLFLIO_UCB31_SWAP_COPY, &(swapState->swapCopy));
   }

   return retVal;
}

/***********************************************************************************************************************
 *  FlashDriver_DualPasswortSequence
 **********************************************************************************************************************/
/*! \brief       Execute dual password sequence
 *  \detail      This function either finish an already started dual password sequence or start a new one.
 *               It depends on the reference block. In case of finishing the sequence the newSwapValue parameter will
 *               only be used when no other valid entry can be found.
 *  \param[in]   newSwapValue   - expected swap value
 *  \param[in]   referenceBlock - This block indicates start point of dual password sequence
 *  \param[in]   swapState      - Common swap information
 *  \return      IO_E_OK in case of success, IO_E_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 6010, 6030 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC */
static IO_ErrorType FlashDriver_DualPasswortSequence(vuint32 newSwapValue, tFblWrapperFlash_UcbBlock referenceBlock, tFlashSwapSettings* const swapState)
{
   IO_ErrorType retVal = IO_E_OK;
   vuint32 passwordBackup[8u];
   tFblWrapperFlash_UcbBlock localRefBlock; /**< Used for changing state */

   localRefBlock = referenceBlock;

   if (localRefBlock == FBLFLIO_UCB23_SWAP_ORIG)
   {
      /* Full dual password sequence starts here */
      retVal = FlashDriver_UcbEraseSync(FBLFLIO_UCB31_SWAP_COPY);

      /* 1. Copy password */
      if (retVal == IO_E_OK)
      {
         retVal = FlashDriver_UcbReadSync((vuint8*)passwordBackup, 32u, FBLFLIO_UCB23_SWAP_ORIG, FLASH_UCB_BLOCK_PW_OFFSET(0u));
      }
      /* In case of retVal == IO_E_ERASED: passwordBackup will be initialized with 0x00 by UcbReadSync */
      if ((retVal == IO_E_OK) || (retVal == IO_E_ERASED))
      {
         retVal = FlashDriver_UcbWriteSync((vuint8*)passwordBackup, 32u, FBLFLIO_UCB31_SWAP_COPY, FLASH_UCB_BLOCK_PW_OFFSET(0u));
      }

      /* 2. Set new SwapValue */
      if (retVal == IO_E_OK)
      {
         retVal = FlashDriver_SetUcbSwapEntry(FBLFLIO_UCB31_SWAP_COPY, 0u, newSwapValue);
      }

      /* 3. Write Confirmation */
      if (retVal == IO_E_OK)
      {
         retVal = FlashDriver_UcbWriteConfirmed(FBLFLIO_UCB31_SWAP_COPY, swapState->swapOrig.confState);
      }

      /* 4. Proceed with 2nd part of the sequence */
      if (retVal == IO_E_OK)
      {
         localRefBlock = FBLFLIO_UCB31_SWAP_COPY;
         /* Update swapSate */
         FlashDriver_GetUcbSwapBlockInfo(FBLFLIO_UCB31_SWAP_COPY, &(swapState->swapCopy));
         swapState->swapCopy.confState = swapState->swapOrig.confState;
      }
   }

   if ((retVal == IO_E_OK) && (localRefBlock == FBLFLIO_UCB31_SWAP_COPY))
   {
      /* Continue (possibly interrupted) sequence. Rely on the set value if possible. */
      vuint32 swapValue;

      /* 0. Set swapValue relevant for this action */
      if (swapState->swapCopy.validEntryCnt > 0u)
      {
         swapValue = swapState->swapCopy.swapValue;
      }
      else
      {
         swapValue = newSwapValue;
      }

      retVal = FlashDriver_UcbEraseSync(FBLFLIO_UCB23_SWAP_ORIG);

      /* 1. Copy password */
      if (retVal == IO_E_OK)
      {
         retVal = FlashDriver_UcbReadSync((vuint8*)passwordBackup, 32u, FBLFLIO_UCB31_SWAP_COPY, FLASH_UCB_BLOCK_PW_OFFSET(0u));
      }
      /* In case of retVal == IO_E_ERASED: passwordBackup will be initialized with 0x00 by UcbReadSync */
      if ((retVal == IO_E_OK) || (retVal == IO_E_ERASED))
      {
         retVal = FlashDriver_UcbWriteSync((vuint8*)passwordBackup, 32u, FBLFLIO_UCB23_SWAP_ORIG, FLASH_UCB_BLOCK_PW_OFFSET(0u));
      }

      /* 2. Set new SwapValue */
      if (retVal == IO_E_OK)
      {
         retVal = FlashDriver_SetUcbSwapEntry(FBLFLIO_UCB23_SWAP_ORIG, 0u, swapValue);
      }

      /* 3. Write Confirmation */
      if (retVal == IO_E_OK)
      {
         /* Result will be set outside by reading back and check any value */
         (void)FlashDriver_UcbWriteConfirmed(FBLFLIO_UCB23_SWAP_ORIG, swapState->swapCopy.confState);
      }
   }

   return retVal;

}

/***********************************************************************************************************************
 *  FlashDriver_SetUcbSwapEntry
 **********************************************************************************************************************/
/*! \brief       Write new swap entry value into ucbBlock and invalidate all old entries
 *  \param[in]   ucbBlock
 *  \param[in]   startIndex   - We try to write at this address first
 *  \param[in]   newSwapValue - Value, which shall be written
 *  \return      IO_E_OK      - Successfully finished
 *               IO_E_NOT_OK  - Something went wrong
 **********************************************************************************************************************/
static IO_ErrorType FlashDriver_SetUcbSwapEntry(tFblWrapperFlash_UcbBlock ucbBlock, vuint32 startIndex, vuint32 newSwapValue)
{
   IO_ErrorType retVal;
   vuint32 writeBuffer[2u];
   vuint32 offset;
   vuint32 index = startIndex;

   do
   {
      writeBuffer[0u] = newSwapValue;
      /* Write address of MARKERL */
      offset = (index * FLASH_UCB_SWAP_ENTRY_LENGTH) + FLASH_SWAP_MARKERL_OFFSET; /* PRQA S 2985 */ /* MD_FBL_2985_RedundantOperation */
      writeBuffer[1u] = FLASH_UCB_ADDRESS(ucbBlock) + offset;
      retVal = FlashDriver_UcbWriteSync((IO_MemPtrType)writeBuffer, 8u, ucbBlock, offset);

      if (IO_E_OK == retVal)
      {
         writeBuffer[0u] = FLASH_SWAP_CONFIRMED;
         /* Write Address of CONFIRMATIONL here */
         offset = (index * FLASH_UCB_SWAP_ENTRY_LENGTH) + FLASH_SWAP_CONFIRMATIONL_OFFSET;
         writeBuffer[1u] = FLASH_UCB_ADDRESS(ucbBlock) + offset;
         retVal = FlashDriver_UcbWriteSync((IO_MemPtrType)writeBuffer, 8u, ucbBlock, offset);
      }

      if (retVal != IO_E_OK)
      {
         index++;
      }
  }
  while ((retVal != IO_E_OK) && (index < FLASH_UCB_SWAP_NR_OF_ENTRIES));

  /* Remove any other valid entries - if available */
  FlashDriver_UcbSwapCleanUp(ucbBlock, index);

  return retVal;
}

/***********************************************************************************************************************
 *  FlashDriver_UcbSwapCleanUp
 **********************************************************************************************************************/
/*! \brief       Overwrite all valid entries until given valid one
 *  \param[in]   ucbBlock
 *  \param[in]   validIndex   - Invalidate all entries smaller than this
 **********************************************************************************************************************/
static void FlashDriver_UcbSwapCleanUp(tFblWrapperFlash_UcbBlock ucbBlock, vuint32 validIndex)
{
   if (validIndex > 0u)
   {
      vuint32 i;
      vuint32 dummy;
      vuint32 writeBuffer[2u];
      vuint32 offset;

      for (i = 0u; i < validIndex; i++)
      {
         if (IO_E_OK == FlashDriver_GetUcbSwapBlockEntryState(ucbBlock, i, &dummy))
         {
            /* UCB_SWAP entry is invalidated by over-programming all-1 into CONFIRMATIONL(x-1) (over-programming with all-1 delivers an ECC correct result for UCB and DFLASH) */
            writeBuffer[0u] = 0xFFFFFFFFuL;
            writeBuffer[1u] = 0xFFFFFFFFuL;
            offset = ((i)* FLASH_UCB_SWAP_ENTRY_LENGTH) + FLASH_SWAP_CONFIRMATIONL_OFFSET;
            /* No useful action if writing will fail */
            (void)FlashDriver_UcbWriteSync((IO_MemPtrType)writeBuffer, 8u, ucbBlock, offset);
         }
      }
   }
}
# endif /* FLASH_ENABLE_TRICORE_SWAP */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FlashDriver_InitSync
 **********************************************************************************************************************/
/*! \brief       Initializes the flash driver
 *  \details     This function copies the flash driver to RAM if it is stored in a ROM image and calls the
 *               initialization routine in RAM.
 *  \pre         Flash driver has to be copied to RAM if downloadable flash driver is used.
 *  \param[in]   *address Unused parameter to implement HIS interface.
 *  \return      Reports if initialization was successful or not.
 **********************************************************************************************************************/
IO_ErrorType FlashDriver_InitSync ( void * address ) /* PRQA S 3673 */ /* MD_FblFlio_3673 */
{
   IO_ErrorType returnValue;
#if defined( FLASH_ENABLE_TRICORE_UCB_READ ) && \
    defined( FLASH_ENABLE_PFLASH_PROTECTION )
   vuint32 ucbPassRead[8u];
#endif

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)address; /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   /* Initialize flash parameter structure */
   flashParam.wdTriggerFct = FblLookForWatchdog;
   flashParam.reserved1 = 0x00u;
   flashParam.programmingType = FLASH_PROGRAM_STANDARD;
   flashParam.errorCode = kFlashOk;
   /* Version defines are preset with version of compile time flash driver. */
   flashParam.majorVersion = FLASH_DRIVER_VERSION_MAJOR;
   flashParam.minorVersion = FLASH_DRIVER_VERSION_MINOR;
   flashParam.patchLevel = FLASH_DRIVER_VERSION_PATCH;
   /* Hand over temporary data buffer */
   flashParam.tempData = tempFlashData;

   if (FlashDriver_CopyDrvToRam() != IO_E_OK)
   {
      returnValue = IO_E_NOT_OK;
   }
   else
   {
      /* Verify if flashcode signature is correct */
      if (    (FLASH_DRIVER_MCUTYPE(flashCode)   != FLASH_DRIVER_VERSION_MCUTYPE)
           || (FLASH_DRIVER_MASKTYPE(flashCode)  != FLASH_DRIVER_VERSION_MASKTYPE)
           || (FLASH_DRIVER_INTERFACE(flashCode) != FLASH_DRIVER_VERSION_INTERFACE)
         )
      {
         /* Flash driver signature mismatch, wrong flash driver */
         returnValue = kFlashInitInvalidVersion;
      }
      else
      {
         /* Call init routine of flash driver */
         FLASH_DRIVER_INIT(flashCode, &flashParam);  /* PRQA S 0303, 0305, 0310, 3305 */ /* MD_FblFlio_FlashApi */
         returnValue = flashParam.errorCode;
      }
   }

#if defined( FLASH_ENABLE_TRICORE_UCB_READ ) && \
    defined( FLASH_ENABLE_PFLASH_PROTECTION )
   if (returnValue == IO_E_OK)
   {
      returnValue = FlashDriver_UcbReadSync((vuint8*)ucbPassRead, 32u, FBLFLIO_UCB16_PFLASH_ORIG, FLASH_UCB_BLOCK_PW_OFFSET(0u));
   }

   if (returnValue == IO_E_OK)
   {
      returnValue = FlashDriver_DisableProtection(FLASH_PFLASH_UCB, &ucbPassRead[0u]);
   }
#endif /* FLASH_ENABLE_TC3XX_COMMENT && FLASH_ENABLE_TRICORE_UCB_READ && FLASH_ENABLE_PFLASH_PROTECTION */

   return returnValue;
}

/***********************************************************************************************************************
 *  FlashDriver_DeinitSync
 **********************************************************************************************************************/
/*! \brief       Deinitializes the flash driver
 *  \details     This function calls the deinitialization routine in RAM and removes the flash driver
 *               from the RAM buffer.
 *  \pre         Flash driver is initialized.
 *  \param[in]   *address Unused parameter to implement HIS interface.
 *  \return      Reports if deinitialization was successful or not.
 **********************************************************************************************************************/
IO_ErrorType FlashDriver_DeinitSync ( void * address ) /* PRQA S 3673 */ /* MD_FblFlio_3673 */
{
   vuint32 i;
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)address; /* PRQA S 3112 */ /* MD_MSR_14.2 */
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   /* Call deinit routine of flash driver */
   FLASH_DRIVER_DEINIT(flashCode, &flashParam); /* PRQA S 0303, 0305, 0310, 3305 */ /* MD_FblFlio_FlashApi */

   /* Remove flash code from RAM */
   for (i = 0uL; i < FLASH_SIZE; i++)
   {
      flashCode[i] = 0x00u;

      /* Call FblLookForWatchdog() every 256 Bytes */
      if ((i & 0xFFuL) == 0x00uL)
      {
         (void)FblLookForWatchdog();
      }
   }

#if defined( FLASH_ENABLE_TRICORE_UCB_READ ) && \
    defined( FLASH_ENABLE_PFLASH_PROTECTION )
   FlashDriver_ResumeProtection();
#endif /* FLASH_ENABLE_TC3XX_COMMENT && FLASH_ENABLE_TRICORE_UCB_READ && FLASH_ENABLE_PFLASH_PROTECTION */

   return flashParam.errorCode;
}

/***********************************************************************************************************************
 *  FlashDriver_RWriteSync
 **********************************************************************************************************************/
/*! \brief       Writes data to flash memory.
 *  \details     This function programs flash memory by calling the flash driver routine stored in RAM. Write commands
 *               have to be done either in PFlash or DFlash - no commands which cover both modules are allowed.
 *  \pre         Flash driver is initialized, memory to be programmed is erased.
 *  \param[in]   writeBuffer Pointer to input data buffer.
 *  \param[in]   writeLength Data length. The length has to be aligned to the smallest writeable segment (32 Bytes
 *               in program flash, 8 Bytes in data flash).
 *  \param[in]   writeAddress Write target address (in flash memory). The target address has to be aligned to the
 *               smallest writeable segment (32 Bytes in program flash, 8 Bytes in data flash).
 *  \return      Reports write success or error code.
 **********************************************************************************************************************/
IO_ErrorType FlashDriver_RWriteSync ( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress )
{
   return FlashDriver_WriteToFlash(writeBuffer, writeLength, writeAddress, FLASH_PROGRAM_STANDARD);
}

/***********************************************************************************************************************
 *  FlashDriver_REraseSync
 **********************************************************************************************************************/
/*! \brief       Erases area in flash memory.
 *  \details     This function erases one or more logical sectors in flash memory.
 *  \pre         Flash driver is initialized.
 *  \param[in]   eraseLength Length of memory to be erased. The length has to be aligned to the length
 *               of one or more flash sectors.
 *  \param[in]   eraseAddress Start address of erase area. The start address has to be the start
 *               address of a logical flash sector.
 *  \return      Reports erase success or error code.
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
IO_ErrorType FlashDriver_REraseSync ( IO_SizeType eraseLength, IO_PositionType eraseAddress )
{
   /* Control variables */
   vuint32 pmuPosition, pmuLimit, physBlockPosition, logBlockPosition;
   vuint32 actualErasePosition;
   IO_ErrorType returnValue;
   vuint32 uncachedEraseAddress;

   /* Flash check variables */
   vuint32 addressAligned;
   vuint32 lengthAligned;

   /* Erase block properties */
   vuint32 eraseStartPosition[3u];
   vuint32 eraseCounter;
   vuint32 eraseRange;
   vuint32 maxEraseSize;

   /* Work variables */
   vuint32 currentBlockLength;
   V_MEMRAM0 V_MEMROM1 tPhysSector V_MEMROM2 V_MEMROM3 * V_MEMRAM1 V_MEMRAM2 currentPhysicalSector;

   /* Initialize variables */
   returnValue    = kFlashFailed;
   addressAligned = 0x00uL;
   lengthAligned  = 0x00uL;
   eraseCounter   = 0x00uL;

   /* Move erase address to uncached memory area */
   uncachedEraseAddress = eraseAddress | FLASH_UNCACHED_ADDRESS_MASK;

   /* Check if DFlash or PFlash is used - it is not allowed to access PFlash and DFlash with one command */
   if ((uncachedEraseAddress & FLASH_DFLASH_BASE_ADDRESS) == FLASH_DFLASH_BASE_ADDRESS)
   {
      /* Prepare erase of DFlash */
      pmuPosition = D0_FLASH_START_PMU;
      pmuLimit    = D0_FLASH_END_PMU;
   }
   else
   {
      /* Prepare erase of PFlash */
      pmuPosition = P_FLASH_START_PMU;
      pmuLimit = P_FLASH_END_PMU;
   }

   /* Check for potential data overflow */
   if ((0xFFFFFFFFuL - eraseLength) < uncachedEraseAddress)
   {
      /* Erase area overflows - do not search for erasable blocks */
      pmuPosition = D0_FLASH_END_PMU + 1u;
      pmuLimit    = D0_FLASH_END_PMU;
   }

   /* Cover NVM and DF0 */
   while ((returnValue == kFlashFailed) && (pmuPosition <= pmuLimit))
   {
      physBlockPosition = 0uL;
      actualErasePosition = flashStructure[pmuPosition].startAddress; /* PRQA S 3689 */ /* MD_FblFlio_3689 */

      /* Analyze every PMU */ /* PRQA S 3689 1 */ /* MD_FblFlio_3689 */
      while ((returnValue == kFlashFailed) && (physBlockPosition < flashStructure[pmuPosition].physicalSectorCount))
      {
         logBlockPosition = 0uL;

         /* Analyze every physical sector */ /* PRQA S 3689 1 */ /* MD_FblFlio_3689 */
         currentPhysicalSector = &flashStructure[pmuPosition].physicalSectors[physBlockPosition];
         while ((returnValue == kFlashFailed) && (logBlockPosition < currentPhysicalSector->logicalSectorCount))
         {
            /* Read length of currently processed flash block */
            currentBlockLength = currentPhysicalSector->logicalSectors[logBlockPosition];

            /* Check if length is aligned */
            if ((actualErasePosition + currentBlockLength) == (uncachedEraseAddress + eraseLength))
            {
               /* Length is aligned to flash sector */
               lengthAligned = 0x01uL;
            }
            /* Check if current block should be erased */
            if (actualErasePosition == uncachedEraseAddress)
            {
               /* Erase address is aligned to flash sector */
               addressAligned = 0x01uL;
               /* Store first erase sector */
               eraseStartPosition[0u] = pmuPosition;
               eraseStartPosition[1u] = physBlockPosition;
               eraseStartPosition[2u] = logBlockPosition;
            }

            /* Try next flash block */
            actualErasePosition += currentBlockLength;
            logBlockPosition++;

            /* Count flash blocks to be erased */
            if (addressAligned == 0x01uL)
            {
               eraseCounter++;

               /* Stop loops if flash sectors are identified */
               if (lengthAligned == 0x01uL)
               {
                  returnValue = kFlashOk;
               }
            }
         }

         /* Trigger watchdog */
         (void)FblLookForWatchdog();

         physBlockPosition++;
      }

      pmuPosition++;
   }

   if (returnValue == kFlashOk)
   {
      /* Erase all blocks */
      pmuPosition = eraseStartPosition[0u]; /* PRQA S 3353 */ /* MD_FblFlio_3353 */
      physBlockPosition = eraseStartPosition[1u];
      logBlockPosition = eraseStartPosition[2u];

      while ((eraseCounter != 0uL) && (returnValue == kFlashOk))
      {
         /* Store current physical sector */
         currentPhysicalSector = &flashStructure[pmuPosition].physicalSectors[physBlockPosition];

         if (eraseCounter > (currentPhysicalSector->logicalSectorCount - logBlockPosition))
         {
            /* Erase all remaining blocks in this physical block */
            eraseRange = currentPhysicalSector->logicalSectorCount - logBlockPosition;
         }
         else
         {
            /* Erase all remaining blocks */
            eraseRange = eraseCounter;
         }

         maxEraseSize = flashStructure[pmuPosition].maxNumLogSectorsForErase;

         /* Number of logical Blocks per erase sequence is limited. */
         while ((eraseRange > 0u) && (kFlashOk == returnValue))
         {
            flashParam.address = uncachedEraseAddress;

            if (eraseRange > maxEraseSize)
            {
               flashParam.eraseCount = maxEraseSize;
            }
            else
            {
               flashParam.eraseCount = eraseRange;
            }

            eraseRange -= flashParam.eraseCount;

            /* Call erase routine of flash driver */
            FLASH_DRIVER_ERASE(flashCode, &flashParam); /* PRQA S 0303, 0305, 0310, 3305 */ /* MD_FblFlio_FlashApi */

            /* Store return value from flash driver */
            returnValue = flashParam.errorCode;

            /* Subtract erased blocks, prepare next erase command */
            eraseCounter -= flashParam.eraseCount;
            while (flashParam.eraseCount > 0u)
            {
               /* Prepare next flash block */
               uncachedEraseAddress += currentPhysicalSector->logicalSectors[logBlockPosition];
               logBlockPosition++;
               flashParam.eraseCount--;
            }
         }

         /* Either the end of a physical block is reached or no additional block has to be erased.
            Because of this, the block control variables can be moved to the next block. */
         logBlockPosition = 0uL;
         physBlockPosition++;
         if (flashStructure[pmuPosition].physicalSectorCount == physBlockPosition)
         {
            /* End of PFx reached - next flash module */
            physBlockPosition = 0uL;
            pmuPosition++;
         }
      }
   }
   else
   {
      if (addressAligned == 0x00uL)
      {
         /* Report wrong address alignment */
         returnValue = kFlashEraseInvalidAddr;
      }
      else
      {
         /* Report wrong length alignment */
         returnValue = kFlashEraseInvalidSize;
      }
   }

   return returnValue;
}

#if defined ( FBL_ENABLE_USR_RREAD_SYNC )
#else
/***********************************************************************************************************************
 *  FlashDriver_RReadSync
 **********************************************************************************************************************/
/*! \brief       Reads data from flash memory.
 *  \details     This function reads data from flash memory. It can be configured to report ECC errors to the
 *               calling function.
 *  \pre         ECC trap generation has to be disabled (see MARP and MARD registers).
 *               Error correction is enabled for PFlash and DFlash (this is the default after reset, see
 *               ECCRP0, ECCRP1 and ECCRD registers.
 *  \param[out]  readBuffer Pointer to read target buffer. The buffer size must be at least readLength Bytes.
 *  \param[in]   readLength Size of data to be read.
 *  \param[in]   readAddress Start address of data to be read.
 *  \return      Reports read success (IO_E_OK) or error code (IO_E_NOT_OK/IO_E_ERASED).
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
IO_ErrorType FlashDriver_RReadSync ( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress )
{
   IO_ErrorType returnValue;
   IO_ErrorType internalResult;
   vuint32 length;
   vuint32 pmu;
   vuint32 i;
   vuintx pos;
   IO_PositionType uncachedAddress;
   IO_SizeType remainingLength;

   uncachedAddress = readAddress | FLASH_UNCACHED_ADDRESS_MASK;
   remainingLength = readLength;
   returnValue = IO_E_OK;

   /* We assume that reading '0' bytes is always OK */
   if (remainingLength > 0uL)
   {
      pos = 0u;
      do
      {
         pmu = FlashDriver_GetPmuIndex(uncachedAddress, 0uL);

         if (FBL_SECTOR_INDEX_INVALID == pmu)
         {
            returnValue = IO_E_NOT_OK;
         }
         else
         {
               /* Use uncached memory area to determine PMU */
            if ((uncachedAddress + remainingLength) > flashStructure[pmu].endAddress)
            {
               /* Read until end of physical Block */
               length = (flashStructure[pmu].endAddress - uncachedAddress) + 1u;
            }
            else
            {
               length = remainingLength;
            }

#  if defined ( FBL_FLASH_ENABLE_ECC_SAFE_READ )
            internalResult = FlashDriver_ReadInternal(&readBuffer[pos], FLASHSTRUCT_REGS(pmu), uncachedAddress, length);

            if ((IO_E_ERASED == returnValue) && (IO_E_OK == internalResult))
            {
               /* No ECC error detected but former result was erased: overall result is failed */
               returnValue = IO_E_NOT_OK;
            }
            else
            {
               returnValue = internalResult;
            }
#  else /* FBL_FLASH_ENABLE_ECC_SAFE_READ */
            returnValue = FlashDriver_ReadInternal(&readBuffer[pos], FLASHSTRUCT_REGS(pmu), uncachedAddress, length);
            internalResult = returnValue;
#  endif /* FBL_FLASH_ENABLE_ECC_SAFE_READ */

            if (IO_E_ERASED == internalResult)
            {
               /* Zero bytes read access detected */
               for (i = 0uL; i < length; i++)
               {
                  readBuffer[pos + i] = FBL_FLASH_DELETED;
               }
            }

            /* Next physical Block */
            uncachedAddress += length;
            pos += length;
            remainingLength -= length;
         }
      }
      while ((remainingLength > 0u) && (IO_E_NOT_OK != returnValue));
   }

   return returnValue;
}
#endif /* FBL_ENABLE_USR_RREAD_SYNC */

/***********************************************************************************************************************
 *  FlashDriver_GetVersionOfDriver
 **********************************************************************************************************************/
/*! \brief       Reports the flash driver version.
 *  \details     This function reads the flash driver version and reports it to the application. Depending on the
 *               initialization state of the driver, the following data is reported:
 *               - Flash driver version which was used to build the Bootloader if no driver has been downloaded yet.
 *               - Actual flash driver version if the flash driver has been downloaded.
 *  \return      BCD coded version of flash driver.
 **********************************************************************************************************************/
IO_U32 FlashDriver_GetVersionOfDriver( void )
{
   IO_U32 returnValue;

   /* Check if flash code is present */
   if (    (FLASH_DRIVER_MCUTYPE(flashCode)   != FLASH_DRIVER_VERSION_MCUTYPE)
        || (FLASH_DRIVER_MASKTYPE(flashCode)  != FLASH_DRIVER_VERSION_MASKTYPE)
        || (FLASH_DRIVER_INTERFACE(flashCode) != FLASH_DRIVER_VERSION_INTERFACE)
      )
   {
      /* Flash driver not present or signature mismatch: return built-in version */
      returnValue = (IO_U32)(((IO_U32)FLASH_DRIVER_VERSION_MAJOR << 16u) | \
                             ((IO_U32)FLASH_DRIVER_VERSION_MINOR <<  8u) | \
                             ((IO_U32)FLASH_DRIVER_VERSION_PATCH));
   }
   else
   {
      /* Flash driver is present, return actual version */
      returnValue = (IO_U32)(((IO_U32)flashParam.majorVersion << 16u) | \
                             ((IO_U32)flashParam.minorVersion <<  8u) | \
                             ((IO_U32)flashParam.patchLevel));
   }

   return returnValue;
}

# if defined( FLASH_ENABLE_TRICORE_UCB_ERASE )
/***********************************************************************************************************************
 *  FlashDriver_UcbEraseSync
 **********************************************************************************************************************/
/*! \brief     Erase one UCB Block
 *  \param[in] block Index of UCB block to erase
 *  \return    Reports erase success or error code.
 *  \precondition UCB protection is unlocked (Disable Protection sequence)
 **********************************************************************************************************************/
IO_ErrorType FlashDriver_UcbEraseSync(tFblWrapperFlash_UcbBlock block)
{
   IO_ErrorType returnValue;

   flashParam.address = FLASH_UCB_ADDRESS(block);

   /* Erase one block */
   flashParam.eraseCount = 1u;

   /* Trigger watchdog */
   (void)FblLookForWatchdog();

   /* Call erase routine of flash driver */
   FLASH_DRIVER_ERASE(flashCode, &flashParam); /* PRQA S 0303, 0305, 0310, 3305 */ /* MD_FblFlio_FlashApi */

   /* Store return value from flash driver */
   returnValue = flashParam.errorCode;

   return returnValue;
}
# endif /* FLASH_ENABLE_TRICORE_UCB_ERASE */

# if defined( FLASH_ENABLE_TRICORE_UCB_READ )
/***********************************************************************************************************************
 *  FlashDriver_UcbReadSync
 **********************************************************************************************************************/
/*! \brief     Read data from UCB Block
 *  \param[in] readBuffer Pointer to data buffer.
 *  \param[in] readLength Data length.
 *  \param[in] block Index of UCB block to be read.
 *  \param[in] readOffset read address offset from begin of UCB block
 *  \return    Reports erase success or error code.
 **********************************************************************************************************************/
IO_ErrorType FlashDriver_UcbReadSync(IO_MemPtrType readBuffer, IO_SizeType readLength, tFblWrapperFlash_UcbBlock block, IO_PositionType readOffset)
{
   /* Control variables */
   IO_ErrorType     returnValue;
   IO_PositionType  readAddress;
   vuint32 i;

   /* Initialize variables */
   returnValue = IO_E_OK;
   readAddress = FLASH_UCB_ADDRESS(block) + readOffset;

   /* Check if PFlash or DFlash are used - alignment requirements differ */
   if ((readAddress & FLASH_DFLASH_BASE_ADDRESS) != FLASH_DFLASH_BASE_ADDRESS)
   {
       /* Invalid address */
      returnValue = kFlashWriteInvalidAddr;
   }
   /* Check if correct UCB Block is used */
   else if ((FLASH_UCB_ADDRESS(block) > readAddress) || (FLASH_UCB_ADDRESS(((vuintx)block) + 1u) < (readAddress + readLength)))
   {
      /** Address is outside of selected UCB block */
      returnValue = kFlashWriteInvalidAddr;
   }
   else
   {
      /* Alignment correct - no error processing needed. */
   }

   if (returnValue == IO_E_OK)
   {
        /* We assume that reading '0' bytes is always OK */
        if (readLength > 0uL)
        {

# if defined ( FBL_FLASH_ENABLE_ECC_SAFE_READ )
           returnValue = FlashDriver_ReadInternal(readBuffer, FLASH_STRUCT_ECC_CONTROL_DF0, readAddress, readLength);
# else /* FBL_FLASH_ENABLE_ECC_SAFE_READ */
           returnValue = FlashDriver_ReadInternal(readBuffer, FLASH_STRUCT_ECC_CONTROL_DF0, readAddress, readLength);
# endif /* FBL_FLASH_ENABLE_ECC_SAFE_READ */

           if (IO_E_ERASED == returnValue) /* PRQA S 2992, 2996 */ /* MD_FblFlio_2992_2996_Configuration */
           {
              /* Zero bytes read access detected */
              for (i = 0uL; i < readLength; i++)
              {
                 readBuffer[i] = FBL_FLASH_DELETED;
              }
           }
        }
   }

   return returnValue;
} /* PRQA S 6030 */ /* MD_MSR_STCYC */

/***********************************************************************************************************************
 *  FlashDriver_UcbReadConfirmation
 **********************************************************************************************************************/
/*! \brief       Read CONFIRMATION field of UCB block.
 *  \details     This does NOT check the contents of the HF_CONFIRMx-registers but reads the confirmation field from the
 *               UCB flash. The contents of the registers are updated during startup and do not reflect the current
 *               situation if the UCB content is manipulated after that.
 *  \param[in]   ucbBlock
 *  \return      FBLFLIO_UCB_CONFIRMATION_CONFIRMED UCB is in state Confirmed
                 FBLFLIO_UCB_CONFIRMATION_UNLOCKED  UCB is in state UNLOCKED
                 FBLFLIO_UCB_CONFIRMATION_ERRORED   UCB could not be read or does not contain valid patterns.
  **********************************************************************************************************************/
tFblWrapperFlash_UcbConfirmation FlashDriver_UcbReadConfirmation(tFblWrapperFlash_UcbBlock ucbBlock)
{
   tFblWrapperFlash_UcbConfirmation result;
   IO_ErrorType memResult;
   vuint32 readBuffer[FLASH_UCB_CONFIRMATION_READ_LENGTH >> 2u];
   vuintx i;
   vuintx notUnLocked;

   memResult = FlashDriver_UcbReadSync((vuint8 *)readBuffer, FLASH_UCB_CONFIRMATION_READ_LENGTH, ucbBlock, FLASH_UCB_CONFIRMATION_OFFSET);

   if (IO_E_OK == memResult)
   {
      result = FBLFLIO_UCB_CONFIRMATION_UNLOCKED;
      notUnLocked = 0u;
      for (i = 0u; i < (FLASH_UCB_CONFIRMATION_READ_LENGTH >> 2u); i++)
      {
         if (readBuffer[i] != ucbUnlockedPattern[i])
         {
            /* break if not UNLOCKED */
            notUnLocked = 1u;
            break;
         }
      }

      if (1u == notUnLocked)
      {
         result = FBLFLIO_UCB_CONFIRMATION_CONFIRMED;

         for (i = 0; i < (FLASH_UCB_CONFIRMATION_READ_LENGTH >> 2); i++)
         {
            if (readBuffer[i] != ucbConfirmedPattern[i])
            {
               /* break if not CONFIRMED */
               result = FBLFLIO_UCB_CONFIRMATION_ERRORED;
               break;
            }
         }
      }
   }
   else
   {
      result = FBLFLIO_UCB_CONFIRMATION_ERRORED;
   }

   return result;
}
# endif /* FLASH_ENABLE_TRICORE_UCB_READ */

# if defined( FLASH_ENABLE_TRICORE_UCB_WRITE )
/***********************************************************************************************************************
 *  FlashDriver_UcbWriteSync
 **********************************************************************************************************************/
/*! \brief     Write data in UCB Block
 *  \param[in] writeBuffer Pointer to input data buffer.
 *  \param[in] writeLength Data length. The length has to be aligned to the smallest writeable segment (8 Bytes in data flash).
 *  \param[in] block Index of UCB block to be written.
 *  \param[in] writeOffset Write target address offset from begin of UCB block (in flash memory). The target address has to be aligned to the
 *             smallest writeable segment (8 Bytes in data flash).
  *  \return    Reports erase success or error code.
 **********************************************************************************************************************/
IO_ErrorType FlashDriver_UcbWriteSync(const IO_MemPtrType writeBuffer, IO_SizeType writeLength, tFblWrapperFlash_UcbBlock block, IO_PositionType writeOffset)
{
   /* Control variables */
   IO_ErrorType     returnValue;
   IO_PositionType  writeAddress;

   /* Initialize variables */
   returnValue = kFlashOk;
   writeAddress = FLASH_UCB_ADDRESS(block) + writeOffset; /* PRQA S 3453 */ /* MD_MSR_19.7 */

   /* Check if PFlash or DFlash are used - alignment requirements differ */
   if ((writeAddress & FLASH_DFLASH_BASE_ADDRESS) != FLASH_DFLASH_BASE_ADDRESS)
   {
       /* Invalid address */
      returnValue = kFlashWriteInvalidAddr;
   }
   /* Check alignment of write address and write length. */
   else if ((writeAddress & (FLASH_SEGMENT_SIZE_DFLASH - 1uL)) != 0x00uL)
   {
      returnValue = kFlashWriteInvalidAddr;
   }
   else if ((writeLength & (FLASH_SEGMENT_SIZE_DFLASH - 1uL)) != 0x00uL)
   {
      returnValue = kFlashWriteInvalidSize;
   }
   /* Check if correct UCB Block is used */
   else if ((FLASH_UCB_ADDRESS(block) > writeAddress) || (FLASH_UCB_ADDRESS(((vuintx)block) + 1u) < (writeAddress + writeLength)))
   {
      /** Address is outside of selected UCB block */
      returnValue = kFlashWriteInvalidAddr;
   }
   else
   {
      /* Alignment correct - no error processing needed. */
   }

   if (returnValue == kFlashOk)
   {
      /* PRQA S 0306, 2214 1 */ /* MD_FblFlio_0306, MD_FblAssert_Assertion */
      assertFblInternal((((vuint32)writeBuffer & (sizeof(tFlashData) - 1u)) == 0u), kFblSysAssertParameterOutOfRange);

      /* Initialize parameters */
      flashParam.address = (tFlashAddress)writeAddress;
      flashParam.verificationAddress = flashParam.address;
      flashParam.writeLength = (tFlashLength)writeLength;
      /* PRQA S 2916, 2918 2 */ /* MD_FblFlio_2916_2918 */
      /* PRQA S 0310, 3305 1 */ /* MD_FblFlio_0310, MD_FblFlio_3305 */
      flashParam.data = (tFlashData *)writeBuffer;
      flashParam.programmingType = FLASH_PROGRAM_STANDARD;
      flashParam.pflashEccStatReg = FLASH_STRUCT_ECC_CONTROL_DF0->xfECC;
      flashParam.flashEccStatMask = FLASH_STRUCT_ECC_CONTROL_DF0->maskECC;
      flashParam.pflashEccControlReg = FLASH_STRUCT_ECC_CONTROL_DF0->flashControl;
      flashParam.flashEccControlMask = FLASH_STRUCT_ECC_CONTROL_DF0->maskFC;
      /* Call write routine of flash driver */
      FLASH_DRIVER_WRITE(flashCode, &flashParam); /* PRQA S 0303, 0305, 0310, 3305 */ /* MD_FblFlio_FlashApi */
      returnValue = flashParam.errorCode;
   }

   return returnValue;
} /* PRQA S 6030 */ /* MD_MSR_STCYC */

/***********************************************************************************************************************
 *   FlashDriver_UcbWriteConfirmed
 **********************************************************************************************************************/
/*! \brief       Write CONFIRMATION field in UCB
 *  \param[in]   ucbBlock UCB to be written
 *  \param[in]   state FBLFLIO_UCB UCB_CONFIRMATION_UNLOCKED Write UCB  state := UNLOCKED
 *               state FBLFLIO_UCB UCB_CONFIRMATION_CONFIRMED Write UCB  state := CONFIRMED
 *  \details     Hint: It is allowed to write CONFIRMED over a UNLOCKED value _without_ erasing the UCB.
  **********************************************************************************************************************/
IO_ErrorType FlashDriver_UcbWriteConfirmed(tFblWrapperFlash_UcbBlock ucbBlock, tFblWrapperFlash_UcbConfirmation state)
{
   IO_ErrorType result;


   if (FBLFLIO_UCB_CONFIRMATION_UNLOCKED == state)
   {
      result = FlashDriver_UcbWriteSync((IO_MemPtrType const) ucbUnlockedPattern, FLASH_UCB_CONFIRMATION_WRITE_LENGTH, ucbBlock, FLASH_UCB_CONFIRMATION_OFFSET); /* PRQA S 0311 */ /* MD_FblFlio_0311 */
   }
   else if (FBLFLIO_UCB_CONFIRMATION_CONFIRMED == state)
   {
     result = FlashDriver_UcbWriteSync((IO_MemPtrType const) ucbConfirmedPattern, FLASH_UCB_CONFIRMATION_WRITE_LENGTH, ucbBlock, FLASH_UCB_CONFIRMATION_OFFSET); /* PRQA S 0311 */ /* MD_FblFlio_0311 */
   }
   else
   {
      result = IO_E_NOT_OK;
   }

   return result;
}

# endif /* FLASH_ENABLE_TRICORE_UCB_WRITE */

/***********************************************************************************************************************
 *  FlashDriver_ResumeProtection
 **********************************************************************************************************************/
/*! \brief     Execute Resume Protection Sequence as defined in user manual
 **********************************************************************************************************************/
void FlashDriver_ResumeProtection( void )
{
   FLASH_COMMAND_CYCLE(RESUME_PROTECTION_ADDRESS, RESUME_PROTECTION_CMD); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
   FBL_DSYNC();
}

/***********************************************************************************************************************
 *  FlashDriver_DisableProtection
 **********************************************************************************************************************/
/*! \brief     Execute Disable Protection Sequence as defined in user manual
 *  \param[in] UC: Identification of the UCBx for which the password checking shall be performed
 *  \param[in] password Password for unlock sequence
 *  \pre       COPY and ORIG of UCB block must be in state CONFIRMED
 *  \return    Reports success or error code.
 **********************************************************************************************************************/
IO_ErrorType FlashDriver_DisableProtection(vuint16 uc, const vuint32 password[8u])
{
   IO_ErrorType result;
   vuintx i;
   vuint32 protectRegisterMask = 0x00000000uL;

   result = IO_E_OK;

   if (V_NULL == password) /* PRQA S 2991, 2992, 2995, 2996, 2880 TAG_NullPointerCheck */ /* MD_FblFlio_NullPointerCheck */
   {
      result = IO_E_NOT_OK;
   }

   if (IO_E_OK == result)
   {
      result = IO_E_NOT_OK;

      for (i = 0; i < (sizeof(flashProtMaskLookUpTbl)/sizeof(flashProtMaskLookUpTbl[0])); i++)
      {
         if( flashProtMaskLookUpTbl[i].uc == uc )
         {
            protectRegisterMask = flashProtMaskLookUpTbl[i].protMask;
            result = IO_E_OK;
            break;
         }
      }
   }

   if (IO_E_OK == result)
   {
      /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
      if((FLASH_DMU_HF_PROTECT & protectRegisterMask) == protectRegisterMask)
      {
         /* Protection already disabled */
      }
      else
      {
         /* Trigger watchdog */
         (void)FblLookForWatchdog();

         /* Clear Protection Error Flag */
         FLASH_DMU_HF_CLRE |= FLASH_DMU_HF_CLRE_CPROER; /* PRQA S 0303 */ /* MD_FblFlio_0303 */

         FLASH_COMMAND_CYCLE(DISABLE_PROTECTION_ADDRESS, uc); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
         FBL_DSYNC();
         FLASH_COMMAND_CYCLE(DISABLE_PROTECTION_ADDRESS, password[0u]); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
         FBL_DSYNC();
         FLASH_COMMAND_CYCLE(DISABLE_PROTECTION_ADDRESS, password[1u]); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
         FBL_DSYNC();
         FLASH_COMMAND_CYCLE(DISABLE_PROTECTION_ADDRESS, password[2u]); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
         FBL_DSYNC();
         FLASH_COMMAND_CYCLE(DISABLE_PROTECTION_ADDRESS, password[3u]); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
         FBL_DSYNC();
         FLASH_COMMAND_CYCLE(DISABLE_PROTECTION_ADDRESS, password[4u]); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
         FBL_DSYNC();
         FLASH_COMMAND_CYCLE(DISABLE_PROTECTION_ADDRESS, password[5u]); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
         FBL_DSYNC();
         FLASH_COMMAND_CYCLE(DISABLE_PROTECTION_ADDRESS, password[6u]); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
         FBL_DSYNC();
         FLASH_COMMAND_CYCLE(DISABLE_PROTECTION_ADDRESS, password[7u]); /* PRQA S 0303 */ /* MD_FblFlio_0303 */
         FBL_DSYNC();

         /* Check if Protection is disabled or if error flag is set */
         /* PRQA S 0303 1 */ /* MD_FblFlio_0303 */
         if ( ((FLASH_DMU_HF_PROTECT & protectRegisterMask) == protectRegisterMask) && ((FLASH_DMU_HF_ERRSR & FLASH_DMU_HF_ERRSR_PROER) == 0u))
         {
            /* Sucess */
         }
         else
         {
            /* Fail */
            result = IO_E_NOT_OK;
         }
      }
   }

   return result;
}

# if defined( FLASH_ENABLE_TRICORE_UCB_DISABLE_PROTECTION )
/***********************************************************************************************************************
 *  FlashDriver_UcbDisableProtection
 **********************************************************************************************************************/
/*! \brief     Unlock access on UCB block with the Disable Password Sequence
 *  \details   If the access to the UCB is already unlocked, the sequence qill not be executed and IO_E_OK will be returned.
 *  \param[in] block Index of UCB block to unlock (ORIG and COPY will be unlocked together)
 *  \param[in] password Password for unlock sequence
 *  \pre       COPY and ORIG of UCB block must be in state CONFIRMED
 *  \return    Reports success or error code.
 **********************************************************************************************************************/
IO_ErrorType FlashDriver_UcbDisableProtection(tFblWrapperFlash_UcbBlock block, const vuint32 password[8u])
{
   IO_ErrorType result;
   vuint16 uc;

   uc = 0u;                  /* PRQA S 2982 */ /* MD_FblFlio_2982_CompilerWarning */
   result = IO_E_OK;

   /* PRQA L:TAG_NullPointerCheck */
   switch(block)
   {
      case FBLFLIO_UCB00_BMHD0_ORIG:
      case FBLFLIO_UCB01_BMHD1_ORIG:
      case FBLFLIO_UCB02_BMHD2_ORIG:
      case FBLFLIO_UCB03_BMHD3_ORIG:
      case FBLFLIO_UCB08_BMHD0_COPY:
      case FBLFLIO_UCB09_BMHD1_COPY:
      case FBLFLIO_UCB10_BMHD2_COPY:
      case FBLFLIO_UCB11_BMHD3_COPY:
      {
         uc = 0x0000u;
         break;
      }
      case FBLFLIO_UCB23_SWAP_ORIG:
      case FBLFLIO_UCB31_SWAP_COPY:
      {
         uc = 0x0017u;
         break;
      }
      case FBLFLIO_UCB32_OTP0_ORIG:
      case FBLFLIO_UCB40_OTP0_COPY:
      default:
      {
         result = IO_E_NOT_OK;
         break;
      }
   }

   if (IO_E_OK == result)
   {
      result = FlashDriver_DisableProtection(uc, password);
   }

   return result;
}
# endif /* FLASH_ENABLE_TRICORE_UCB_DISABLE_PROTECTION */

#if defined( FLASH_ENABLE_WOP_SUPPORT )
/***********************************************************************************************************************
 *  FlashWopDriver_InitSync
 **********************************************************************************************************************/
/*! \brief       Initializes the WOP flash driver
 *  \details     This function copies the flash driver to RAM if it is stored in a ROM image and calls the
 *               initialization routine in RAM. The actual initialization is done by FlashDriver_InitSync().
 *  \pre         Flash driver has to be copied to RAM if downloadable flash driver is used.
 *  \param[in]   *address Unused parameter to implement HIS interface.
 *  \return      Reports if initialization was successful or not.
 **********************************************************************************************************************/
IO_ErrorType FlashWopDriver_InitSync ( void * address )
{
   /* Call main initialization function */
   return FlashDriver_InitSync(address);
}

/***********************************************************************************************************************
 *  FlashWopDriver_DeinitSync
 **********************************************************************************************************************/
/*! \brief       De-initialization interface for WOP write driver
 *  \details     This function adds a de-initialization function for the WOP driver interface. No de-initialization
 *               is done here - the actual de-initialization is done in FlashDriver_DeinitSync().
 *  \pre         Flash driver is initialized.
 *  \param[in]   *address Unused parameter to implement HIS interface.
 *  \return      Reports if deinitialization was successful or not.
 **********************************************************************************************************************/
IO_ErrorType FlashWopDriver_DeinitSync ( void * address ) /* PRQA S 3673 */ /* MD_FblFlio_3673 */
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)address; /* PRQA S 3112 */ /* MD_MSR_14.2*/
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   /* No de-initialization done here to avoid double de-initialization */
   return IO_E_OK;
}

/***********************************************************************************************************************
 *  FlashWopDriver_RWriteSync
 **********************************************************************************************************************/
/*! \brief       Writes data to flash memory.
 *  \details     This function programs flash memory by calling the flash driver routine stored in RAM. Write commands
 *               have to be done in PFlash only. WOP configurations of DFlash sectors are not supported.
 *  \pre         Flash driver is initialized, memory to be programmed is erased.
 *  \param[in]   writeBuffer Pointer to input data buffer.
 *  \param[in]   writeLength Data length. The length has to be aligned to the smallest writeable segment (32 Bytes
 *               in program flash, 8 Bytes in data flash).
 *  \param[in]   writeAddress Write target address (in flash memory). The target address has to be aligned to the
 *               smallest writeable segment (32 Bytes in program flash, 8 Bytes in data flash).
 *  \return      Reports write success or error code.
 **********************************************************************************************************************/
IO_ErrorType FlashWopDriver_RWriteSync ( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress )
{
   IO_ErrorType returnValue;

# if defined( FBL_FLASH_ENABLE_ECC_SAFE_READ )
   IO_SizeType readSize;
   IO_SizeType readCounter;
   IO_PositionType readAddress;
   vuint8 readBuffer[FLASH_SEGMENT_SIZE_PFLASH];

   /* Check if memory is earased before write */
   returnValue = IO_E_ERASED;
   readCounter = writeLength;
   readAddress = writeAddress;
   while (readCounter > 0uL)
   {
      readSize = (readCounter > FLASH_SEGMENT_SIZE_PFLASH) ? FLASH_SEGMENT_SIZE_PFLASH : readCounter;
      returnValue = FlashDriver_RReadSync((IO_MemPtrType)readBuffer, readSize, readAddress);

      /* Check has been done by read function itself, no further blank check required. */

      if (returnValue != IO_E_ERASED)
      {
         /* Store error information if an error occurred */
         flashParam.errorAddress = readAddress;
         flashParam.errorCode = kFlashWriteAlreadyWritten;
         break;
      }
      else
      {
         /* Prepare next loop */
         readCounter -= readSize;
         readAddress += readSize;
      }
   }

   if (returnValue == IO_E_ERASED)
# endif /* FBL_FLASH_ENABLE_ECC_SAFE_READ */
   {
      returnValue = FlashDriver_WriteToFlash(writeBuffer, writeLength, writeAddress, FLASH_PROGRAM_WOP);
   }

   return returnValue;
}

/***********************************************************************************************************************
 *  FlashWopDriver_REraseSync
 **********************************************************************************************************************/
/*! \brief       Erase interface for WOP blocks
 *  \details     This function implements an erase interface for WOP blocks. The blocks cannot be erased so
 *
 *  \pre         Flash driver is initialized.
 *  \param[in]   eraseLength Length of memory to be erased. The length has to be aligned to the length
 *               of one or more flash sectors.
 *  \param[in]   eraseAddress Start address of erase area. The start address has to be the start
 *               address of a logical flash sector.
 *  \return      Reports erase success or error code.
 **********************************************************************************************************************/
IO_ErrorType FlashWopDriver_REraseSync ( IO_SizeType eraseLength, IO_PositionType eraseAddress )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   /* PRQA S 3112 2 */ /* MD_MSR_14.2 */
   (void)eraseLength;
   (void)eraseAddress;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   /* Do nothing here - memory has to be erased */
   return IO_E_OK;
}

/***********************************************************************************************************************
 *  FlashWopDriver_RReadSync
 **********************************************************************************************************************/
/*! \brief       Reads data from WOP flash memory.
 *  \details     This function reads data from flash memory. It can be configured to report ECC errors to the
 *               calling function.
 *  \pre         ECC trap generation has to be disabled (see MARP and MARD registers).
 *               Error correction is enabled for PFlash and DFlash (this is the default after reset, see
 *               ECCRP0, ECCRP1 and ECCRD registers.
 *  \param[out]  readBuffer Pointer to read target buffer. The buffer size must be at least readLength Bytes.
 *  \param[in]   readLength Size of data to be read.
 *  \param[in]   readAddress Start address of data to be read.
 *  \return      Reports read success (IO_E_OK) or error code (IO_E_NOT_OK/IO_E_ERASED).
 **********************************************************************************************************************/
IO_ErrorType FlashWopDriver_RReadSync ( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress )
{
   /* No difference regarding read function compared to main function */
   return FlashDriver_RReadSync(readBuffer, readLength, readAddress);
}
#endif /* FLASH_ENABLE_WOP_SUPPORT */

# if defined( FLASH_ENABLE_TRICORE_SWAP )
#  if defined( FLASH_ENABLE_TRICORE_SWAP_ROUTINE )
/***********************************************************************************************************************
 *  FlashDriver_SwapPartitions
 **********************************************************************************************************************/
/*! \brief       Swap partitions on the device.
 *  \pre         Flash driver must be initialized, swap feature must be activated and active
 *  \return      Reports success (IO_E_OK) or error code (i.e. IO_E_NOT_OK)
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
IO_ErrorType FlashDriver_SwapPartitions( void )
{
   IO_ErrorType        retVal = IO_E_OK;     /**< tracks local error state */
   tFlashSwapSettings  ucbSwapState;         /**< Info structure, holding all necessary swap information */
   vuint32             newSwapValue = 0x00000000uL;
   vuint32             retryFailCnt;

   /* Initialize the failure counter */
   retryFailCnt = 0u;

   /* Leave only in case of error or valid and consistent SWAP state */
   while (retVal == IO_E_OK)
   {
      retVal = FlashDriver_GetUcbSwapState(&ucbSwapState);
      FblLookForWatchdogVoid();

      if (IO_E_OK == retVal)
      {
         /* SWAP support is enabled, we have boot swap value and at least one valid UCB block */
         newSwapValue = ucbSwapState.bootSwapValue ^ 0xFFuL;
      }

      if ((IO_E_OK == retVal) && (ucbSwapState.blockUpdReq == FALSE))
      {
         /* Both UCB blocks are valid, no reason found to repair a UCB block. ucbSwapState.bootUcbBlock = ORIG */
         /* Check if the swap request was already correctly set and logs of both UCB blocks are valid */
         if ((ucbSwapState.swapOrig.swapIndex < FLASH_UCB_SWAP_NR_OF_ENTRIES) && /* Valid entry available - swapValue can be evaluated */
             (ucbSwapState.swapCopy.swapIndex < FLASH_UCB_SWAP_NR_OF_ENTRIES) && /* Both UCB blocks need valid log entries */
             (ucbSwapState.swapOrig.swapValue == newSwapValue) &&                /* Both valid UCB log entries need to have same expected value */
             (ucbSwapState.swapCopy.swapValue == newSwapValue) &&
             (ucbSwapState.swapOrig.validEntryCnt == 1u) &&                      /* Log in UCB is only valid if there is just one valid entry */
             (ucbSwapState.swapCopy.validEntryCnt == 1u))
         {
            /* Valid blocks and entries found with new swap value. System Reset required no further actions */
            /*******************************************************************/
            break; /* One and only place to leave the loop with a valid result */
            /*******************************************************************/
         }

         /* Check if any UCB block needs to be updated by dual password sequence */
         if (((ucbSwapState.swapOrig.nextIndex >= FLASH_UCB_SWAP_NR_OF_ENTRIES) && (ucbSwapState.swapOrig.swapValue != newSwapValue)) ||
             ((ucbSwapState.swapCopy.nextIndex >= FLASH_UCB_SWAP_NR_OF_ENTRIES) && (ucbSwapState.swapCopy.swapValue != newSwapValue)))
         {
            /* There is at least one UCB block, which has not already the correct swap value and no remaining log entry to write new value */
            ucbSwapState.blockUpdReq = TRUE; /* Force dual password sequence. */
         }

         /* Remove old but still valid entries for UCB blocks - Results will be seen in next loop */
         if ((ucbSwapState.blockUpdReq == FALSE) && (ucbSwapState.swapOrig.validEntryCnt > 1u))
         {
            FlashDriver_UcbSwapCleanUp(FBLFLIO_UCB23_SWAP_ORIG, ucbSwapState.swapOrig.swapIndex);
         }
         if ((ucbSwapState.blockUpdReq == FALSE) && (ucbSwapState.swapCopy.validEntryCnt > 1u))
         {
            FlashDriver_UcbSwapCleanUp(FBLFLIO_UCB31_SWAP_COPY, ucbSwapState.swapCopy.swapIndex);
         }

         /* Write new values if not already set - Results will be seen in next loop */
         /* First set value in COPY and then in ORIG, analogous to dual password sequence:
          * So when we boot next time after any interruption from new value, we can be sure that
          * this value is present in COPY, too
          */
         if ((ucbSwapState.blockUpdReq == FALSE) && (ucbSwapState.swapCopy.swapValue != newSwapValue))
         {
            if (IO_E_OK != FlashDriver_SetUcbSwapEntry(FBLFLIO_UCB31_SWAP_COPY, ucbSwapState.swapCopy.nextIndex, newSwapValue))
            {
               continue; /* Re evaluate state in next loop cycle */
            }
         }
         if ((ucbSwapState.blockUpdReq == FALSE) && (ucbSwapState.swapOrig.swapValue != newSwapValue))
         {
           /* Result will be automatically updated by next loop cycle */
           (void)FlashDriver_SetUcbSwapEntry(FBLFLIO_UCB23_SWAP_ORIG, ucbSwapState.swapOrig.nextIndex, newSwapValue);
         }
      }

      if ((IO_E_OK == retVal) && (ucbSwapState.blockUpdReq == TRUE))
      {
         /* Dual password sequence must be executed. Result of this operation will be evaluated in next loop by reading written data. */
         if (FlashDriver_DualPasswortSequence(newSwapValue, ucbSwapState.bootUcbBlock, &ucbSwapState) != IO_E_OK)
         {
            retryFailCnt++;
         }
         else
         {
            retryFailCnt = 0u;
         }
      }

      if (retryFailCnt >= FBL_FLASH_SWAP_RETRY_CNT)
      {
         /* Maximum number of retries achived. The device has an hardware failure */
         retVal = IO_E_NOT_OK;
      }
   }

   return retVal;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
#  endif  /* FLASH_ENABLE_TRICORE_SWAP_ROUTINE */
# endif /* FLASH_ENABLE_TRICORE_SWAP */

#define FBLFLIO_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Module specific MISRA deviations:

   MD_FblFlio_0303:
      Reason:     [I] Cast between a pointer to volatile object and an integral type.
      Risk:       No identifiable risk as casts are used to define SFRs here.
      Prevention: No prevention defined.
   MD_FblFlio_0306:
      Reason:     [I] Cast between a pointer to object and an integral type. This is mostly caused by address information
                  which is handed over as an integral type and has to be converted to a pointer type to be used.
      Risk:       Data loss because of cast.
      Prevention: Code inspection has to ensure no data is lost.
   MD_FblFlio_0311:
      Reason:     Cast from const pointer to const to a const pointer. This is mostly caused by pointers to constants located
                  in ROM. The functions consuming the provided data can also handle data in RAM and therefore the parameter
                  can not be restricted to a const pointer to const.
      Risk:       Access error because of cast.
      Prevention: Code inspection has to ensure that no write access on const data occurs.
   MD_FblFlio_0314:
      Reason:     [I] Cast from a pointer to object type to a pointer to void. This is mostly caused by address information
                  which is handed over as an integral type and has to be converted to a pointer type to be used.
      Risk:       Data loss because of cast.
      Prevention: Code inspection has to ensure no data is lost.
   MD_FblFlio_0326:
      Reason:     [I] Cast between a pointer to object and an integral type. This is mostly caused by address information
                  which is handed over as an integral type and has to be converted to a pointer type to be used.
      Risk:       Data loss because of cast.
      Prevention: Code inspection has to ensure no data is lost.
   MD_FblFlio_0310:
      Reason:     Casting to different object pointer type.
      Risk:       Cast discards address information used by pointer.
      Prevention: Assertion and calling functions have to ensure correct alignment.
   MD_FblFlio_2982_CompilerWarning:
      Reason: The assignment is redundant  and could be omitted. But some compilers do not detect this and warn for a uninitialized variable.
      Risk: No identifiable risk.
      Prevention: No prevention required.
   MD_FblFlio_2982_Configuration:
      Reason: Depending on the configuration it might be that this assignment is redundant.
      Risk: No identifiable risk.
      Prevention: No prevention required
   MD_FblFlio_2991_2995_Configuration:
      Reason: Depending on the configuration it might be that this controlling expression is always true
      Risk: No identifiable risk.
      Prevention: No prevention required
   MD_FblFlio_2992_2996_Configuration:
      Reason: Depending on the configuration it might be that this controlling expression is always false
      Risk: No identifiable risk.
      Prevention: No prevention required
   MD_FblFlio_2916_2918:
      Reason:     The object is referenced only within the correct lifetime.
      Risk:       Illegal pointer access.
      Prevention: Code inspection has to verify the correct pointer access.
   MD_FblFlio_3218:
      Reason:     The address of this array is passed in and used inside flash driver. There are some doubts if the compiler
                  generated address can be inappropriate to access the array when being declared as function static array within
                  FlashDriver_InitSync.
      Risk:       No identifiable risk.
      Prevention: No prevention required.
   MD_FblFlio_3305:
      Reason:     Pointer cast to stricter alignment.
      Risk:       Cast discards address information used by pointer.
      Prevention: Assertion and calling functions have to ensure correct alignment.
   MD_FblFlio_3353:
      Reason:     The variable '' is possibly unset at this point.
      Risk:       Uninitialized variable which includes random values is used.
      Prevention: Code inspection has to verify that the variable is initialized every time it is used.
   MD_FblFlio_3408:
      Reason:     Variable has external linkage but is being defined without any previous declaration.
      Risk:       No risk.
      Prevention: No prevention required as Variable is only used locally.
   MD_FblFlio_3673:
      Reason:     The object addressed by the pointer parameter 'address' is not modified and so the
                  pointer could be of type 'pointer to const'. The interface format is implemented following
                  a standard interface definition which may be missing const qualifiers for some implementation.
      Risk:       No identifiable risk.
      Prevention: No prevention required.
   MD_FblFlio_3689:
      Reason:     [U] Indexing array with value that will apparently be out of bounds. Variable used to access array
                  will be set to invalid value on purpose if a pre-check fails.
      Risk:       Error condition isn't checked and invalid array access is done.
      Prevention: Implement array index check before array access.
   MD_FblFlio_FlashApi:
      Reason:     Vector standard API to get flash function pointers in order to execute flash routines (init, write, erase, deinit)
                  All functions are executed in uniform way.
      Risk:       Reduced readability, might not work on all platforms.
      Prevention: Code reviews and testing that flash programming gets executed (trivial).
   MD_FblAssert_Assertion:
      Reason:     This is an assertion macro used only for debugging in development (FBL_ENABLE_ASSERTION). There should
                  be no need to extend the amount of statements, so the current usage is accepted.
      Risk:       Unintended debugging code behavior could result, through adding further statements,
      Prevention: A comment is in place to avoid that further statements are added to the if condition.
   MD_FblFlio_NullPointerCheck:
      Reason:     The pointer can be pointing to the NULL address, even MISRA neglect this.
      Risk:       No Risk
      Prevention: No prevention necessary
   MD_FBL_2985_RedundantOperation:
      Reason:     QAC misinterprets the code which actually has side effects.
      Risk:       No identifiable risk
      Prevention: No prevention required.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_FLIO.C
 **********************************************************************************************************************/

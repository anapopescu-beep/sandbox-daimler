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
 *  02.02.00   2018-06-12  visrie  ESCAN00099655      Added support for DiabData compiler
 *  02.03.00   2018-07-06  visshs  ESCAN00099819      Added support for disabling Write Verification
 *             2018-07-06  visshs  ESCAN00099845      [TC3xx B-Step] Changed FLASHCON2 register layout
 *             2018-07-06  visshs  ESCAN00098948      [TC3xx only]: ECC clear doesn't
 *             2018-07-06  visshs  ESCAN00097719      Write access to undocumented register bit
 *             2018-07-06  visshs  ESCAN00099920      Export Command Sequence makro to upper layer
 *  02.05.00   2018-07-23  visshs  ESCAN00100136      Flash Burst Write Fails with Sequence Error
 *                         visshs  ESCAN00100118      Removed Beta ESCAN
 *  02.06.00   2018-10-18  visshs  ESCAN00101095      Rework for MISRA 2012
 *                         visshs  ESCAN00101096      Add support for SWAP
 *  02.07.00   2019-01-31  visshs  ESCAN00101954      No changes
 *  02.07.01   2019-03-12  visrr   ESCAN00102457      Corrected FLASH_REQ_APPL_SW_RESET for XDx variants
 *  02.08.00   2019-04-05  visshs  ESCAN00102794      Added Bad Block Management support
 *                         visshs  ESCAN00102782      Reworked status register flag abstraction
 *  02.08.01   2019-06-12  visshs  ESCAN00103405      No changes
 *  02.08.02   2019-06-12  visshs  ESCAN00103388      Fixed undeclared identifier
 *  02.08.03   2019-09-09  vistbe  ESCAN00104250      No changes
 *             2019-09-17  vistmo  FBL-383            Added support for Green Hills compiler
 *                         vistmo  ESCAN00104337      No changes
 *                         vistmo  ESCAN00104338      Fixing compiler warnings
 *  02.08.04   2019-10-08  vistmo  ESCAN00104536      Fixed missing XD token
 *  02.08.05   2019-12-11  vistmo  ESCAN00105120      Wrong bad block replacement on data flash
 *  02.09.00   2020-10-13  visrcn  ESCAN00106588      TC3xx: If flash is swapped, the verification after write may fail
 *  02.09.01   2022-03-25  visjdn  ESCAN00110854      TC3xx: The trap handler is called continuously
 *                                 FBL-4596           Added/adapted MemMap sections
 **********************************************************************************************************************/

#define FLASHDRV_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "flashdrv.h"
#include "flash_sfr.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ((FBLDRVFLASH_TRICOREAURIXHIS_VERSION != 0x0209u) || \
     (FBLDRVFLASH_TRICOREAURIXHIS_RELEASE_VERSION != 0x01u))
# error "Error in flashdrv.c: Source and header file versions are inconsistent!!"
#endif
#if ((FBLDRVFLASH_TRICOREAURIXHIS_SFR_VERSION != 0x0209u) || \
     (FBLDRVFLASH_TRICOREAURIXHIS_SFR_RELEASE_VERSION != 0x01u))
# error "Error in flashdrv.c: Source and SFR definition file versions are inconsistent!!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Flash control macros */
/*!
 * Internal comment removed.
 *
 *
 */
/** Programming command macro. */ /* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define COMMAND_CYCLE(addr, data)      FLASH_COMMAND_CYCLE(addr, data)
/* Reset to read mode */
#define ResetToReadAddr                0x5554u                 /**< Address offset for Reset To Read command. */
#define ResetToReadVal                 0xF0u                   /**< Reset To Read command value. */
/* Clear status */
#define ClearStatusAddr                0x5554u                 /**< Address offset for Clear Status command. */
#define ClearStatusVal                 0xFAu                   /**< Clear status command value. */
/* Enter page mode */
#define EnterPageModeAddr              0x5554u                 /**< Address offset for Enter Page Mode command. */
#define EnterPageModePFlash            0x50u                   /**< Enter Page Mode - PFlash command value. */
#define EnterPageModeDFlash            0x5Du                   /**< Enter Page Mode - DFlash command value. */
/* Load page */
#define LoadPageAddr                   0x55F0u                 /**< Address offset for Load Page command. */
/* Write page / erase sector */
#define ProgStep1Addr                  0xAA50u                 /**< Address offset for prog command - step 1. */
#define ProgStep2Addr                  0xAA58u                 /**< Address offset for prog command - step 2. */
#define ProgStep3Addr                  0xAAA8u                 /**< Address offset for prog command - step 3.*/
#define ProgStep4Addr                  0xAAA8u                 /**< Address offset for prog command - step 4. */
#define WriteStep2Val                  0x00u                   /**< Write - Step 2 command value. */
#define WriteStep3Val                  0xA0u                   /**< Write - Step 3 command value. */
#define WritePageStep4Val              0xAAu                   /**< Write Page - Step 4 command value. */
# define WriteWopStep4Val               0xA8u                   /**< Write Page Once - Step 4 command value. */
# define WriteBurstStep4Val             0xA6u                   /**< Write Burst - Step 4 command value. */
# define ReplaceStep2Val                0x00u                   /**< Replace logical sector - step 2 command value */
# define ReplaceStep3Val                0xA0u                   /**< Replace logical sector - step 3 command value */
# define ReplaceStep4Val                0xACu                   /**< Replace logical sector - step 4 command value */
#define EraseStep3Val                  0x80u                   /**< Erase - Step 3 command value. */
#define EraseStep4Val                  0x50u                   /**< Erase - Step 4 command value. */
#define EraseVerifyStep3Val            0x80u                   /**< Erase verify - Step 3 command value. */
#define EraseVerifyStep4Val            0x5Fu                   /**< Erase verify - Step 4 command value. */

/* Flash status register bits */
# define FlashStatusD0Busy              0x00000001uL            /**< Flash status register - DF0 busy flag */
# define FlashStatusD1Busy              0x00000002uL            /**< Flash status register - DF1 busy flag */
# define FlashStatusP0Busy              0x00000004uL            /**< Flash status register - PF0 busy flag */
# define FlashStatusP1Busy              0x00000008uL            /**< Flash status register - PF1 busy flag */
# define FlashStatusP2Busy              0x00000010uL            /**< Flash status register - PF2 busy flag */
# define FlashStatusP3Busy              0x00000020uL            /**< Flash status register - PF3 busy flag */
# define FlashStatusP4Busy              0x00000040uL            /**< Flash status register - PF4 busy flag */
# define FlashStatusP5Busy              0x00000080uL            /**< Flash status register - PF5 busy flag */

# define FlashStatusProg                0x00000001uL            /**< Flash operation register - Programming state bit */
# define FlashStatusErase               0x00000002uL            /**< Flash operation register - Erase state bit */

# define FlashStatusPfPage              0x00200000uL            /**< Flash status register - PFlash in page mode */
# define FlashStatusDfPage              0x00100000uL            /**< Flash status register - DFlash in page mode */

# define FlashStatusOper                FLASH_DMU_HF_ERRSR_OPER /**< Error status register - Flash operation error */
# define FlashStatusSqer                FLASH_DMU_HF_ERRSR_SQER /**< Error status register - Command sequence error */
# define FlashStatusProer               FLASH_DMU_HF_ERRSR_PROER/**< Error status register - Protection error */
# if defined( FlashStatusPver )
/* Program verify error flag already defined */
# else
#  define FlashStatusPver               0x00000008uL            /**< Error status register - Program verify error */
# endif
# if defined( FlashStatusEver )
/* Erase verify flag already defined */
# else
#  define FlashStatusEver               FLASH_DMU_HF_ERRSR_EVER /**< Error status register - Erase verify error */
# endif
# define FlashStatusAder                0x00000020uL            /**< Error status register - SRI bus address ECC error */
# define FlashStatusOrier               0x00000040uL            /**< Error status register - Original error (uncorrectable ECC error) */

/** Flash status register - combined busy flags */
# define FlashStatusBusy       ( FlashStatusD0Busy | FlashStatusD1Busy | FlashStatusP0Busy | FlashStatusP1Busy | FlashStatusP2Busy | FlashStatusP3Busy | FlashStatusP4Busy | FlashStatusP5Busy )
/** Flash status register - combined program/erase error flags */
# define FlashStatusProgError  ( FlashStatusOper | FlashStatusSqer | FlashStatusProer | FlashStatusPver | FlashStatusEver )

# define FlashGetStatusProg()      ((FLASH_DMU_HF_OPERATION & FlashStatusProg) == FlashStatusProg)
# define FlashGetStatusErase()     ((FLASH_DMU_HF_OPERATION & FlashStatusErase) == FlashStatusErase)
# define FlashGetStatusSqer()      ((FLASH_DMU_HF_ERRSR & FlashStatusSqer) == FlashStatusSqer)
# define FlashGetStatusProer()     ((FLASH_DMU_HF_ERRSR & FlashStatusProer) == FlashStatusProer)
# define FlashGetStatusEver()      ((FLASH_DMU_HF_ERRSR & FlashStatusEver) == FlashStatusEver)
# define FlashGetStatusPver()      ((FLASH_DMU_HF_ERRSR & FlashStatusPver) == FlashStatusPver)
# define FlashGetStatusOper()      ((FLASH_DMU_HF_ERRSR & FlashStatusOper) == FlashStatusOper)
# define FlashGetStatusProgError() ((FLASH_DMU_HF_ERRSR & FlashStatusProgError) != 0x00uL)
# define FlashGetStatusBusy()      ((FLASH_DMU_HF_STATUS & FlashStatusBusy) != 0x00uL)
# define FlashGetStatusPfPage()    ((FLASH_DMU_HF_STATUS & FlashStatusPfPage) == FlashStatusPfPage)
# define FlashGetStatusDfPage()    ((FLASH_DMU_HF_STATUS & FlashStatusDfPage) == FlashStatusDfPage)

/* Enable application reset - system reset does not initialize flash firmware after reset */
# define FlashSetResetReason()     FLASH_SCU_RSTCON |= FLASH_REQ_SYSTEM_RESET

/** Invalid burst mode size - used for WOP flash */
#define kFlashInvalidBurstSize   0xFFFFFFFFuL

# define kFlashSectorSize 0x4000uL

/* Trap handling */
#  define FLASH_MMU_TRAP                0u
#  define FLASH_PROT_TRAP               1u
#  define FLASH_INST_TRAP               2u
#  define FLASH_CONT_TRAP               3u
#  define FLASH_BUS_TRAP                4u
#  define FLASH_ASS_TRAP                5u
#  define FLASH_SYS_TRAP                6u
#  define FLASH_NMI_TRAP                7u

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#  define TRAP_PREFIX( class )          __trap( class )

/* Compiler intrinsic abstraction */ /* PRQA S 3453 TAG_CompilerIntrinsicMacros */ /* MD_MSR_FctLikeMacro */
# define FLASH_ISYNC()              __isync()
# define FLASH_DSYNC()              __dsync()
# define FLASH_MFCR(regaddr)        __mfcr(regaddr)
# define FLASH_MTCR(regaddr, val)   __mtcr((regaddr), (val))
/* PRQA L:TAG_CompilerIntrinsicMacros */

/* Addidtional DSYNC in COMMAND sequence for TC3XX required */
# define CONDITIONAL_DSYNC() FLASH_DSYNC()

#if defined( FLASH_ENABLE_WRITE_VERIFICATION ) || defined( FLASH_DISABLE_WRITE_VERIFICATION )
#else /* FLASH_ENABLE_WRITE_VERIFICATION */
/* Enable FLASH_ENABLE_WRITE_VERIFICATION per default */
# define FLASH_ENABLE_WRITE_VERIFICATION
#endif /* FLASH_ENABLE_WRITE_VERIFICATION */

/***********************************************************************************************************************
 *  REGISTER UNLOCK SPECIFIC DEFINES
 **********************************************************************************************************************/
#define FLASH_POS_WDT_CON0_ENDINIT            0u    /**< Offset of ENDINIT in WDTxCON0 */
#define FLASH_POS_WDT_CON0_LCK                1u    /**< Offset of LCK in WDTxCON0 */
#define FLASH_POS_WDT_CON0_PW                 2u    /**< Offset of PW in WDTxCON0 */
#define FLASH_POS_WDT_CON0_REL                16u   /**< Offset of REL in WDTxCON0 */

/** Mask for all bits in 32 bit register */
#define FLASH_MASK_WDT_ALL                    0xFFFFFFFFuL
/** Mask for ENDINIT in WDTxCON0 */
#define FLASH_MASK_WDT_CON0_ENDINIT           (0x1uL << FLASH_POS_WDT_CON0_ENDINIT)
/** Mask for LCK in WDTxCON0 */
#define FLASH_MASK_WDT_CON0_LCK               (0x1uL << FLASH_POS_WDT_CON0_LCK)
/** Inverted mask for LCK / ENDINIT in WDTxCON0 */
#define FLASH_INV_MASK_WDT_CON0_LCK_ENDINIT   ((FLASH_MASK_WDT_CON0_LCK | FLASH_MASK_WDT_CON0_ENDINIT) ^ FLASH_MASK_WDT_ALL)
/** Mask for PW in WDTxCON0 */
#define FLASH_MASK_WDT_CON0_PW                (0x3FFFuL << FLASH_POS_WDT_CON0_PW)
/** Mask for LSB of PW in WDTxCON0 */
#define FLASH_MASK_WDT_CON0_PW_2              (0x1uL << FLASH_POS_WDT_CON0_PW)
/** Inverted mask for PW in WDTxCON0 */
#define FLASH_INV_MASK_WDT_CON0_PW            (FLASH_MASK_WDT_CON0_PW ^ FLASH_MASK_WDT_ALL)
/** Mask for inverting bits [7:2] of PW in WDTxCON0 */
#define FLASH_XOR_MASK_WDT_CON0_PW            (0x003FuL << FLASH_POS_WDT_CON0_PW)
/** Mask for REL in WDTxCON0 */
#define FLASH_MASK_WDT_CON0_REL               (0xFFFFuL << FLASH_POS_WDT_CON0_REL)
/** Inverted mask for REL in WDTxCON0 */
#define FLASH_INV_MASK_WDT_CON0_REL           (FLASH_MASK_WDT_CON0_REL ^ FLASH_MASK_WDT_ALL)

#define FLASH_POS_WDT_SR_PAS                  7u    /**< Offset of PAS in WDTxSR */
#define FLASH_POS_WDT_SR_TCS                  8u    /**< Offset of TCS in WDTxCON0 */
#define FLASH_POS_WDT_SR_TIM                  16u   /**< Offset of TIM in WDTxCON0 */

/** Mask for PAS in WDTxSR */
#define FLASH_MASK_WDT_SR_PAS                 (0x1uL << FLASH_POS_WDT_SR_PAS)
/** Mask for TCS in WDTxSR */
#define FLASH_MASK_WDT_SR_TCS                 (0x1uL << FLASH_POS_WDT_SR_TCS)
/** Mask for TIM in WDTxSR */
#define FLASH_MASK_WDT_SR_TIM                 (0xFFFFuL << FLASH_POS_WDT_SR_TIM)

/** Unlocked state of ENDINIT in WDTxCON0 */
#define FLASH_VAL_WDT_CON0_ENDINIT_UNLOCK     (0x0uL << FLASH_POS_WDT_CON0_ENDINIT)
/** Locked state of ENDINIT in WDTxCON0 */
#define FLASH_VAL_WDT_CON0_ENDINIT_LOCK       (0x1uL << FLASH_POS_WDT_CON0_ENDINIT)
/** Unlocked state of LCK in WDTxCON0 */
#define FLASH_VAL_WDT_CON0_LCK_UNLOCK         (0x0uL << FLASH_POS_WDT_CON0_LCK)
/** Locked state of LCK in WDTxCON0 */
#define FLASH_VAL_WDT_CON0_LCK_LOCK           (0x1uL << FLASH_POS_WDT_CON0_LCK)

/** SWRSTCON Software Reset Request */
#define FLASH_VAL_SWRSTCON_RES_REQ            0x00000002uL

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/** Flash driver header */
typedef struct
{
   tFlashUint8  version;           /**< Version of downloaded flash driver             */
   tFlashUint8  reserved;          /**< Reserved for future use                        */
   tFlashUint8  maskType;          /**< Flash cell mask type                           */
   tFlashUint8  CPUType;           /**< Micro controller type                          */
   tFlashFct    flashInitFct;      /**< Function pointer to init function              */
   tFlashFct    flashDeinitFct;    /**< Function pointer to deinit function            */
   tFlashFct    flashEraseFct;     /**< Function pointer to erase function             */
   tFlashFct    flashWriteFct;     /**< Function pointer to write function             */
#  if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
   tFlashFct    flashReplaceFct;   /**< Function pointer to replace bad block function */
#  endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
} tFlashHeader; /* PRQA S 3448 */ /* MD_FblFlash_3448 */

/** Watchdog register set */
typedef struct
{
   volatile tFlashUint32 * con0;  /**< WDTxCON0 register */
   volatile tFlashUint32 * sr;    /**< WDTxSR register */
} tflashWdtRegisters;

/** Control handling of different protection levels */
typedef enum
{
   FLASH_WDT_SYSTEM,   /**< Lock/unlock system/safety level */
   FLASH_WDT_CPU       /**< Lock/unlock CPU specific level */
} tFlashWdtType;

/** Polling callback routine type */
typedef  tFlashUint8 (* twdTriggerFct)(void);

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define FLASHDRV_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

static void FlashResetToReadMode( void );
static void FlashClearStatusCommand( void );
static inline void FlashFlushWriteBuffers( void );
static tFlashErrorCode FlashStatusPolling( twdTriggerFct pollingFct );

static tFlashErrorCode FlashRegisterGetRegisters( tFlashWdtType wdtType, tflashWdtRegisters * wdtRegisters );
static tFlashUint32 FlashRegisterPasswordAccess( tflashWdtRegisters * wdtRegisters );
static void FlashRegisterModifyAccess( tflashWdtRegisters * wdtRegisters, tFlashUint32 regValue, tFlashUint32 lockBit );
static void FlashRegisterUnlock( tFlashWdtType wdtType );
static void FlashRegisterLock( tFlashWdtType wdtType );
static tFlashErrorCode FlashEraseSequence( twdTriggerFct pollingFct,  tFlashAddress address, tFlashLength eraseCount );
static tFlashErrorCode FlashVerifyErasedSectorRangeSequence( twdTriggerFct pollingFct,  tFlashAddress address, tFlashLength eraseCount );
static tFlashErrorCode FlashPageModeSequence( tFlashUint32 flashPageCommand );
static tFlashErrorCode FlashWriteSequence(twdTriggerFct pollingFct, tFlashAddress address, tFlashUint32 flashWriteSize, tFlashUint32 flashWriteCommand, const tFlashData * data);
# if defined( FLASH_ENABLE_BAD_BLOCK_MGMT )
static void FlashReplaceLogicalSectorSequence( tFlashParam * flashParam );
static void FlashEraseInternal( tFlashParam * flashParam );
# endif /* FLASH_ENABLE_BAD_BLOCK_MGMT */
static void FlashRedirectTraps( tFlashParam * flashParam );
static void FlashRestoreTraps( const tFlashParam * flashParam );
static void FlashTrapError( void );
/* PRQA S 3447 8 */ /* MD_FblFlash_1752_3447_Traptable */
void TRAP_PREFIX( FLASH_MMU_TRAP ) FlashTrapMMU( void );
void TRAP_PREFIX( FLASH_PROT_TRAP ) FlashTrapProtection( void );
void TRAP_PREFIX( FLASH_INST_TRAP ) FlashTrapInstruction( void );
void TRAP_PREFIX( FLASH_CONT_TRAP ) FlashTrapContext( void );
void TRAP_PREFIX( FLASH_BUS_TRAP ) FlashTrapBus( void );
void TRAP_PREFIX( FLASH_ASS_TRAP ) FlashTrapAssertion( void );
void TRAP_PREFIX( FLASH_SYS_TRAP ) FlashTrapSystem( void );
void TRAP_PREFIX( FLASH_NMI_TRAP ) FlashTrapNMI( void );


#define FLASHDRV_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define FLASHDRV_START_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* PRQA S 3218 1 */ /* MD_FblFlash_3218 */
static const tflashWdtRegisters flashWdtRegAddrs[] =
{
    { &FLASH_SCU_WDTCPUCON0(0u), &FLASH_SCU_WDTCPUSR(0u) } /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   ,{ &FLASH_SCU_WDTCPUCON0(1u), &FLASH_SCU_WDTCPUSR(1u) } /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   ,{ &FLASH_SCU_WDTCPUCON0(2u), &FLASH_SCU_WDTCPUSR(2u) } /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   ,{ &FLASH_SCU_WDTCPUCON0(3u), &FLASH_SCU_WDTCPUSR(3u) } /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   ,{ &FLASH_SCU_WDTCPUCON0(4u), &FLASH_SCU_WDTCPUSR(4u) } /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   ,{ &FLASH_SCU_WDTCPUCON0(5u), &FLASH_SCU_WDTCPUSR(5u) } /* PRQA S 0303 */ /* MD_FblFlash_0303 */
};
#define FLASHDRV_STOP_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/* Do not optimize structure */
/* PRQA S 3116 1 */ /* MD_MSR_3.4 */
#  pragma pack 0

# define FLASHDRV_FLASHHEADER_START_SEC_CONST
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/** Flash Driver header */
const tFlashHeader flashHeader = /* PRQA S 3408 */ /* MD_FblFlash_3408 */
{
   FLASH_DRIVER_VERSION_INTERFACE,
   0x00u,
   FLASH_DRIVER_VERSION_MASKTYPE,
   FLASH_DRIVER_VERSION_MCUTYPE,
   &ExpFlashInit,
   &ExpFlashDeinit,
   &ExpFlashErase,
   &ExpFlashWrite
# if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
   ,
   &ExpFlashReplace
# endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
};

# define FLASHDRV_FLASHHEADER_STOP_SEC_CONST
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/** Address of trap table (TC0) */ /* PRQA S 1752, 3447 1 */ /* MD_FblFlash_1752_3447_Traptable */
extern void * _lc_u_trap_tab_tc0;

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FlashResetToReadMode
 **********************************************************************************************************************/
/*! \brief         Resets flash states to read mode.
 *  \details       Switch flash back to read mode, reset flash status register.
 *  \pre           Flash driver present in RAM.
 **********************************************************************************************************************/
#define FLASHDRV_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
static void FlashResetToReadMode( void )
{
   /* Reset flash module to read mode. */
   CONDITIONAL_DSYNC();
   COMMAND_CYCLE(ResetToReadAddr, ResetToReadVal); /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   CONDITIONAL_DSYNC();
   /* Clear status. */
   FlashClearStatusCommand(); /* PRQA S 2987 */ /* MD_Flash_HardwareRelatedFunction */
}

/***********************************************************************************************************************
 *  FlashClearStatusCommand
 **********************************************************************************************************************/
/*! \brief         Clears error flags in flash module.
 *  \details       The error flags in Flash status register are cleared. Additionally, the write status bits
 *                 (PROG, ERASE) are cleared, if Flash is not busy.
 *  \pre           Flash driver present in RAM, Flash in read mode.
 **********************************************************************************************************************/
static void FlashClearStatusCommand( void )
{
   /* Clear flash status. */
   CONDITIONAL_DSYNC();
   COMMAND_CYCLE(ClearStatusAddr, ClearStatusVal); /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   CONDITIONAL_DSYNC();
}

/***********************************************************************************************************************
 *  FlashFlushWriteBuffers
 **********************************************************************************************************************/
/*! \brief         Flush flash write buffer.
 **********************************************************************************************************************/
/* PRQA S 3006, 3219 1 */ /* MD_FblFlash_3006, MD_MSR_14.1 */
static inline void FlashFlushWriteBuffers( void )
{
   volatile tFlashUint32 dummy; /* PRQA S 3203 */ /* MD_FblFlash_3203 */

   /* Perform dummy read of PMU module identification register
      to flush the flash write buffer. */
   dummy = FLASH_FLASH0_ID; /* PRQA S 0303 */ /* MD_FblFlash_0303 */

   /* PRQA S 1006 3 */ /* MD_MSR_1.1 */
   __asm("nop");
   __asm("nop");
   __asm("nop");
}

/***********************************************************************************************************************
 *  FlashStatusPolling
 **********************************************************************************************************************/
/*! \brief         Polls status of erase or write command.
 *  \details       This function polls the state of a write or erase commands.
 *  \pre           Flash driver present in RAM, Flash in read mode.
 *  \param[in] pollingFct function pointer which is called during busy wait loop, e. g. to maintain the watchdog.
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static tFlashErrorCode FlashStatusPolling( twdTriggerFct pollingFct )
{
   tFlashErrorCode result;

   result = kFlashOk;

   /* Wait until an error occurs or program/erase command is accepted */ /* PRQA S 0303 1 */ /* MD_FblFlash_0303 */
   while ( (! FlashGetStatusProg()) && (! FlashGetStatusErase()) && (! FlashGetStatusProgError()))
   {
      ;
   }

   /* Check for errors */
   /* PRQA S 0303 1 */ /* MD_FblFlash_0303 */
   if (FlashGetStatusSqer())
   {
      result = kFlashSequence;
   }
   /* PRQA S 0303 1 */ /* MD_FblFlash_0303 */
   else if (FlashGetStatusProer())
   {
      result = kFlashProtect;
   }
   /* PRQA S 0303 1 */ /* MD_FblFlash_0303 */
   else if (FlashGetStatusEver())
   {
      result = kFlashVerify;
   }
   else
   {
      /* Wait for busy bits to be reset */ /* PRQA S 0303 1 */ /* MD_FblFlash_0303 */
      while (FlashGetStatusBusy() && (result == kFlashOk))
      {
         /* Trigger watchdog */
         (void)(* pollingFct)();

         /* PRQA S 0303 1 */ /* MD_FblFlash_0303 */
         if (FlashGetStatusProgError())
         {
            result = kFlashFailed;
         }
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FlashRegisterGetRegisters
 **********************************************************************************************************************/
/*! \brief       Determine affected watchdog register set (safety or specific CPU core)
 *  \details     Aurix differentiates safety and CPU watchdogs. A CPU watchdog may only be changed by its corresponding
 *               CPU, hence core ID is evaluated at run-time.
 *  \param[in]   wdtType FLASH_WDT_SYSTEM: System unlock, FLASH_WDT_CPU: CPU core unlock
 *  \param[out]  wdtRegisters Watchdog register set
 *  \return      Result of operation
 *  \retval      kFlashOk  Valid register set found
 *  \retval      kFlashFailed  No valid register set found
 **********************************************************************************************************************/
static tFlashErrorCode FlashRegisterGetRegisters( tFlashWdtType wdtType, tflashWdtRegisters * wdtRegisters )
{
   tFlashErrorCode   result;
   tFlashUint32      codeId;

   /* Assume valid register set */
   result = kFlashOk;

   switch (wdtType)
   {
      /* Safety watchdog */
      case FLASH_WDT_SYSTEM:
      {
         /* PRQA S 0303 2 */ /* MD_FblFlash_0303 */
         wdtRegisters->con0 = &FLASH_SCU_WDTSCON0;
         wdtRegisters->sr = &FLASH_SCU_WDTSSR;

         break;
      }
      /* CPU core specific watchdog */
      case FLASH_WDT_CPU:
      {
         /* Read core ID from SFR */
         codeId = FLASH_MFCR(FLASH_CORE_ID) & 0x07uL;

         if (codeId < (sizeof(flashWdtRegAddrs) / sizeof(tflashWdtRegisters)))
         {
            wdtRegisters->con0 = (flashWdtRegAddrs[codeId]).con0;
            wdtRegisters->sr = (flashWdtRegAddrs[codeId]).sr;
         }
         else
         {
            result = kFlashFailed;
         }

         break;
      }
      default: /* PRQA S 2018 */ /* MD_FblFlash_2018 */
      {
         result = kFlashFailed;

         break;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FlashRegisterPasswordAccess
 **********************************************************************************************************************/
/*! \brief       Password access to unlock watchdog registers.
 *  \param[in]   wdtRegisters Affected watchdog register set (safety or specific CPU core)
 *  \return      Current value of WDTxCON0 register, including updated password
 **********************************************************************************************************************/
static tFlashUint32 FlashRegisterPasswordAccess( tflashWdtRegisters * wdtRegisters ) /* PRQA S 3673 */ /* MD_FblFlash_3673_3678 */
{
   tFlashUint32   wdtcon0;
   tFlashUint32   wdtsr;
   tFlashUint32   wdtcon0Value;
   tFlashUint32   prevPass;
   tFlashUint32   currentPass;

   /* Get values of affected watchdog registers */
   wdtcon0  = *(wdtRegisters->con0);
   wdtsr    = *(wdtRegisters->sr);

   /* Previous password value, bits [7:2] are inverted on read */
   prevPass = (wdtcon0 & FLASH_MASK_WDT_CON0_PW) ^ FLASH_XOR_MASK_WDT_CON0_PW;

   /* Evaluate password auto-sequence status flag */
   if (0u == (wdtsr & FLASH_MASK_WDT_SR_PAS))
   {
      /* Static password, use unmodified value */
      currentPass = prevPass;
   }
   else
   {
      /* Automatic password sequencing, next password follows a pseudo-random sequence
         based upon a 14-bit Fibonacci LFSR with characteristic polynomial x^14 + x^13 + x^12 +x^2 + 1 */
      currentPass  = (prevPass << 1u) & FLASH_MASK_WDT_CON0_PW;
      currentPass |= ((prevPass >> 13u) ^ (prevPass >> 12u) ^ (prevPass >> 11u) ^ (prevPass >> 1u)) & FLASH_MASK_WDT_CON0_PW_2;
   }

   /* Set updated value of password
      Additionally unlock control access, but lock end-of-initialization bit */
   wdtcon0  &= (FLASH_INV_MASK_WDT_CON0_PW & FLASH_INV_MASK_WDT_CON0_LCK_ENDINIT);
   wdtcon0  |= (currentPass | FLASH_VAL_WDT_CON0_LCK_UNLOCK | FLASH_VAL_WDT_CON0_ENDINIT_LOCK); /* PRQA S 2985 */ /* MD_Flash_SfrRead */

   /* Return current value, including updated password */
   wdtcon0Value = wdtcon0;

   /* Evaluate timer check status flag */
   if (0u != (wdtsr & FLASH_MASK_WDT_SR_TCS))
   {
      /* Re-evaluate status register for current counter value */
      wdtsr    = *(wdtRegisters->sr);

      /* Set reload value to inverted counter value
         This satisfies the requirement to write an inverted estimate of the counter */
      wdtcon0 &= FLASH_INV_MASK_WDT_CON0_REL;
      wdtcon0 |= (wdtsr ^ FLASH_MASK_WDT_SR_TIM) & FLASH_MASK_WDT_SR_TIM;
   }

   /* Password access to WDTxCON0 */
   *(wdtRegisters->con0) = wdtcon0;

   return wdtcon0Value;
}

/***********************************************************************************************************************
 *  FlashRegisterModifyAccess
 **********************************************************************************************************************/
/*! \brief       Modify access to previously unlocked watchdog registers.
 *  \pre         Watchdog register must be unlocked using FlashRegisterPasswordAccess
 *  \param[in]   wdtRegisters Affected watchdog register set (safety or specific CPU core)
 *  \param[in]   regValue Desired value of WDTxCON0 register (value of ENDINIT and LCK are not relevant)
 *  \param[in]   lockBit Desired value of WDTxCON0.ENDINIT status bit (FLASH_VAL_WDT_CON0_ENDINIT_UNLOCK or FLASH_VAL_WDT_CON0_ENDINIT_LOCK)
 **********************************************************************************************************************/
static void FlashRegisterModifyAccess( tflashWdtRegisters * wdtRegisters, tFlashUint32 regValue, tFlashUint32 lockBit ) /* PRQA S 3673 */ /* MD_FblFlash_3673_3678 */
{
   tFlashUint32 wdtcon0;
   tFlashUint32 lockBitMasked;

   /* Ensure parameter only covers ENDINIT bit */
   lockBitMasked = lockBit  & FLASH_MASK_WDT_CON0_ENDINIT;
   /* Set end-of-initialization bit to desired value
      Additionally lock control access again */
   wdtcon0  = (regValue & FLASH_INV_MASK_WDT_CON0_LCK_ENDINIT) | lockBitMasked | FLASH_VAL_WDT_CON0_LCK_LOCK;

   /* Modify access to WDTxCON0 */
   *(wdtRegisters->con0) = wdtcon0;

   /* Read back ENDINIT, until cleared/set */
   while (lockBitMasked != ((*(wdtRegisters->con0)) & FLASH_MASK_WDT_CON0_ENDINIT))
   {
      ;
   }
}

/***********************************************************************************************************************
 *  FlashRegisterUnlock
 **********************************************************************************************************************/
/*! \brief       Unlock register access to protected registers.
 *  \details     Aurix differentiates safety and CPU watchdogs. A CPU watchdog may only be changed by its corresponding
 *               CPU, hence core ID is evaluated at run-time.
 *  \param[in]   wdtType FLASH_WDT_SYSTEM: System unlock,FLASH_WDT_CPU0 - 2/5: CPU core unlock
 **********************************************************************************************************************/
static void FlashRegisterUnlock( tFlashWdtType wdtType )
{
   tFlashUint32         wdtcon0;
   tflashWdtRegisters   wdtRegisters;

   /* Determine affected watchdog register set */
   if (kFlashOk == FlashRegisterGetRegisters(wdtType, &wdtRegisters))
   {
      /* Unlock access to watchdog registers, using password */
      wdtcon0  = FlashRegisterPasswordAccess(&wdtRegisters);

      /* Unlock register access to protected registers */
      FlashRegisterModifyAccess(&wdtRegisters, wdtcon0, FLASH_VAL_WDT_CON0_ENDINIT_UNLOCK);
   }
}

/***********************************************************************************************************************
 *  FlashRegisterLock
 **********************************************************************************************************************/
/*! \brief       Lock register access to protected registers.
 *  \details     Aurix differentiates safety and CPU watchdogs. A CPU watchdog may only be changed by its corresponding
 *               CPU, hence core ID is evaluated at run-time.
 *  \param[in]   wdtType FLASH_WDT_SYSTEM: System unlock, FLASH_WDT_CPU: CPU core unlock
 **********************************************************************************************************************/
static void FlashRegisterLock( tFlashWdtType wdtType )
{
   tFlashUint32         wdtcon0;
   tflashWdtRegisters   wdtRegisters;

   /* Determine affected watchdog register set */
   if (kFlashOk == FlashRegisterGetRegisters(wdtType, &wdtRegisters))
   {
      /* Unlock access to watchdog registers, using password */
      wdtcon0  = FlashRegisterPasswordAccess(&wdtRegisters);

      /* Lock register access to protected registers */
      FlashRegisterModifyAccess(&wdtRegisters, wdtcon0, FLASH_VAL_WDT_CON0_ENDINIT_LOCK);
   }
}

/***********************************************************************************************************************
 *  FlashEraseSequence
 **********************************************************************************************************************/
/*! \brief     Executes the Erase Logical Sector Range sequence
 *  \details   Erases eraseCount "logical sectors" starting from address. Wait until erasing finishes and call
 *             polling routine handed over in pollingFct.
 *  \param[in] pollingFct Polling routine to be called during busy-wait-loop until erase process of the hardware
 *             finishes.
 *  \param[in] address    Where to start erase. Must be aligned to a logical sector border
 *  \param[in] eraseCount Number of consecutive logical sectors to be erased.
 *  \return    See FlashStatusPolling() description
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
static tFlashErrorCode FlashEraseSequence( twdTriggerFct pollingFct, tFlashAddress address, tFlashLength eraseCount )
{
   tFlashErrorCode result;

   /* Erase all pending error flags */
   FlashClearStatusCommand(); /* PRQA S 2987 */ /* MD_Flash_HardwareRelatedFunction */

   /* Unlock endinit for PFlash */
   FlashRegisterUnlock( FLASH_WDT_SYSTEM );

   /* Erase sector */
   CONDITIONAL_DSYNC();
   COMMAND_CYCLE(ProgStep1Addr, address);               /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   CONDITIONAL_DSYNC();
   COMMAND_CYCLE(ProgStep2Addr, (eraseCount & 0xFFu));  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   CONDITIONAL_DSYNC();
   COMMAND_CYCLE(ProgStep3Addr, EraseStep3Val);         /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   CONDITIONAL_DSYNC();
   COMMAND_CYCLE(ProgStep4Addr, EraseStep4Val);         /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   FLASH_DSYNC();

   /* Lock endinit for PFlash */
   FlashRegisterLock( FLASH_WDT_SYSTEM );

   /* Poll erase status */
   result = FlashStatusPolling( pollingFct );

   return result;
}

/***********************************************************************************************************************
 *  FlashVerifyErasedSectorRangeSequence
 **********************************************************************************************************************/
/*! \brief     Executes the Verify Erased Logical Sector Range sequence
 *  \details   Verifies that eraseCount "logical sectors" starting from address are successfully erased
 *  \param[in] pollingFct Polling routine to be called during busy-wait-loop until sequence is processed by the hardware
 *  \param[in] address    Where to start verification. Must be aligned to a logical sector border
 *  \param[in] eraseCount Number of consecutive logical sectors to be verified.
 *  \return    See FlashStatusPolling() description
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
static tFlashErrorCode FlashVerifyErasedSectorRangeSequence( twdTriggerFct pollingFct,  tFlashAddress address, tFlashLength eraseCount )
{
   tFlashErrorCode result;

   /* Erase all pending error flags */
   FlashClearStatusCommand(); /* PRQA S 2987 */ /* MD_Flash_HardwareRelatedFunction */

   /* Verify if sector is erased */
   CONDITIONAL_DSYNC();
   COMMAND_CYCLE(ProgStep1Addr, address);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   CONDITIONAL_DSYNC();
   COMMAND_CYCLE(ProgStep2Addr, (eraseCount & 0xFFu));  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   CONDITIONAL_DSYNC();
   COMMAND_CYCLE(ProgStep3Addr, EraseVerifyStep3Val);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   CONDITIONAL_DSYNC();
   COMMAND_CYCLE(ProgStep4Addr, EraseVerifyStep4Val);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   FLASH_DSYNC();

   /* Poll verify status */
   result = FlashStatusPolling(pollingFct);

   return result;
}

/***********************************************************************************************************************
 *  FlashPageModeSequence
 **********************************************************************************************************************/
/*! \brief     Executes the Enter Page Mode sequence
 *  \details   Switches the flash to the desired access mode
 *  \param[in] flashPageCommand    EnterPageModePFlash (0x50u) or
 *                                 EnterPageModeDFlash (0x5Du ). Selects PFLASH or DFLASH access.
 *  \return    kFlashOk       success.
 *  \return    kFlashWriteAcc Sequence failed.
 **********************************************************************************************************************/
   /*!
 * Internal comment removed.
 *
 *
 */
static tFlashErrorCode FlashPageModeSequence( tFlashUint32 flashPageCommand )
{
   tFlashErrorCode result;

   result = kFlashOk;

   /* Unlock endinit for PFlash */
   FlashRegisterUnlock( FLASH_WDT_SYSTEM );
   /* Enter page mode */
   CONDITIONAL_DSYNC();
   COMMAND_CYCLE(EnterPageModeAddr, flashPageCommand);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   FLASH_DSYNC();
   /* Lock endinit for PFlash */
   FlashRegisterLock( FLASH_WDT_SYSTEM );

   /* Check if page mode has been reached */ /* PRQA S 0303 1 */ /* MD_FblFlash_0303 */
   while ((! FlashGetStatusPfPage()) && (! FlashGetStatusDfPage()) )
   {
      /* PRQA S 0303 1 */ /* MD_FblFlash_0303 */
      if (FlashGetStatusOper() || FlashGetStatusSqer())
      {
         /* Error occurred, leave flash write routine */
         result = kFlashWriteAcc;
         break;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FlashWriteSequence
 **********************************************************************************************************************/
/*! \brief     Executes a write sequence to the flash.
 *  \details
 *  \param[in] pollingFct polling routine to be called during busy-wait-loop until sequence is processed by the hardware
 *  \param[in] address    where to start writing. Must be aligned to FLASH_SEGMENT_SIZE
 *  \param[in] flashWriteSize    Number of Bytes to write. Must be aligned to FLASH_SEGMENT_SIZE
 *  \param[in] flashWriteCommand Selects write mode (Page, Burst, WOP)
 *  \param[in] data              Pointer to a buffer of write data
 *  \return    kFlashWriteCmdBufFull If the cmd buffer overflows
 *  \return    See FlashStatusPolling() for other return values
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
static tFlashErrorCode FlashWriteSequence(twdTriggerFct pollingFct, tFlashAddress address, tFlashUint32 flashWriteSize, tFlashUint32 flashWriteCommand, const tFlashData * data)
{
   tFlashErrorCode result;
   tFlashUint32 i;

   /* Unlock endinit for PFlash */
   FlashRegisterUnlock( FLASH_WDT_SYSTEM );
   /* Load data - depends on flash write size */
   for (i = 0u; i < (flashWriteSize / 4u); i++)
   {
      /* Load data - address differs for every second word */
      CONDITIONAL_DSYNC();
      COMMAND_CYCLE(LoadPageAddr + ((i & 1u) * 4u), data[i]);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
      CONDITIONAL_DSYNC();
   }

   /* Check for sequence error during load data */
   if (FlashGetStatusSqer()) /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   {
      /* Lock endinit for PFlash */
      FlashRegisterLock( FLASH_WDT_SYSTEM );

      /* Sequence error during buffer fill. */
      result = kFlashWriteCmdBufFull;
   }
   else
   {
      /* Write data (page or burst) */
      CONDITIONAL_DSYNC();
      COMMAND_CYCLE(ProgStep1Addr, address);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
      CONDITIONAL_DSYNC();
      COMMAND_CYCLE(ProgStep2Addr, WriteStep2Val);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
      CONDITIONAL_DSYNC();
      COMMAND_CYCLE(ProgStep3Addr, WriteStep3Val);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
      CONDITIONAL_DSYNC();
      COMMAND_CYCLE(ProgStep4Addr, flashWriteCommand);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
      FLASH_DSYNC();

      /* Lock endinit for PFlash */
      FlashRegisterLock( FLASH_WDT_SYSTEM );

      /* Poll write status */
      result = FlashStatusPolling( pollingFct );
   }

   return result;
}

# if defined( FLASH_ENABLE_BAD_BLOCK_MGMT )
/***********************************************************************************************************************
 *  FlashReplaceLogicalSector
 **********************************************************************************************************************/
/*! \brief     Executes the Replace Logical Sector sequence
 *  \details   Replaces a logical sector by a redundant sector. This can fail if no redundant sector for this address is
 *             available.
 *  \param[in,out] flashParam Pointer to flash parameter structure
 *  \return    See FlashStatusPolling() description
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
static void FlashReplaceLogicalSectorSequence( tFlashParam * flashParam  )
{
   {
      /* Erase all pending error flags */
      FlashClearStatusCommand(); /* PRQA S 2987 */ /* MD_Flash_HardwareRelatedFunction */

      /* Unlock endinit for PFlash */
      FlashRegisterUnlock( FLASH_WDT_SYSTEM );

      /* Replace Logical Sector */
      CONDITIONAL_DSYNC();
      COMMAND_CYCLE(ProgStep1Addr, flashParam->errorAddress);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
      CONDITIONAL_DSYNC();
      COMMAND_CYCLE(ProgStep2Addr, ReplaceStep2Val);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
      CONDITIONAL_DSYNC();
      COMMAND_CYCLE(ProgStep3Addr, ReplaceStep3Val);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
      CONDITIONAL_DSYNC();
      COMMAND_CYCLE(ProgStep4Addr, ReplaceStep4Val);  /* PRQA S 0303 */ /* MD_FblFlash_0303 */
      FLASH_DSYNC();

      /* Lock endinit for PFlash */
      FlashRegisterLock( FLASH_WDT_SYSTEM );

      /* Poll status */
      flashParam->errorCode = FlashStatusPolling( flashParam->wdTriggerFct );
   }
}

/***********************************************************************************************************************
 *  FlashEraseInternal
 **********************************************************************************************************************/
/*! \brief     Erase and follow Bad-Block-Management sequence.
 *  \details   Erases eraseCount logical sectors. If this fails (EVER==1), it retries to erase. If erase fails again,
 *             the defective logical sector is replaced.
 *  \param[in,out] flashParam Pointer to flash parameter structure
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static void FlashEraseInternal( tFlashParam * flashParam )
{
   tFlashUint32 eraseSectorIdx;

#  if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
   flashParam->replaceResult = kFlashReplace_None;
#  endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
   flashParam->errorAddress = flashParam->address;

   flashParam->errorCode = FlashEraseSequence(flashParam->wdTriggerFct, flashParam->errorAddress, flashParam->eraseCount);
   if (FlashGetStatusEver()) /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   {
      /* Erase each logical sector individually */
      for(eraseSectorIdx = 0; eraseSectorIdx < flashParam->eraseCount; eraseSectorIdx++)
      {
         flashParam->errorCode = FlashEraseSequence(flashParam->wdTriggerFct, flashParam->errorAddress, 1u);

         if (FlashGetStatusEver()) /* PRQA S 0303 */ /* MD_FblFlash_0303 */
         {
            if ((flashParam->errorAddress & FLASH_DFLASH_BASE_ADDRESS) != FLASH_DFLASH_BASE_ADDRESS)
            {
               /* Erroneous sector found in Program Flash, replace it */
               FlashReplaceLogicalSectorSequence(flashParam);

               if (flashParam->errorCode != kFlashOk)
               {
#  if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
                  /* Replace sector failed, abort */
                  flashParam->errorCode |= kFlashFctReplace;
                  flashParam->replaceResult = kFlashReplace_Failed;
#  else /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
                  flashParam->errorCode |= kFlashFctErase;
#  endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
                  break;
               }
               else
               {
                  /* The replaced block can now be used - Infineon states that erasing is not necessary.
                   * Continue erasing of remaining blocks.
                   */
#  if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
                  flashParam->replaceResult = kFlashReplace_SectorReplaceOk;
#  endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
               }
            }
            else
            {
               /* Block replacement is not supported for data flash */
               flashParam->errorCode |= kFlashFctErase;
#  if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
               flashParam->replaceResult = kFlashReplace_None;
#  endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
            }
         }

         flashParam->errorAddress += kFlashSectorSize;
      }
         /* If second erase worked, do not report an error */

#  if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
      if (flashParam->replaceResult == kFlashReplace_None)
      {
         flashParam->replaceResult = kFlashReplace_SecondEraseOk;
      }
#  endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */

   }
#  if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
   else
   {
      flashParam->replaceResult = kFlashReplace_FirstEraseOk;
   }
#  endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
}
# endif /* FLASH_ENABLE_BAD_BLOCK_MGMT */

/***********************************************************************************************************************
 *  FlashRedirectTraps
 **********************************************************************************************************************/
/*! \brief         Redirect traps to flash driver trap table in RAM.
 *  \pre           Flash driver present in RAM.
 *  \param[in,out] flashParam Pointer to flash parameter structure
 **********************************************************************************************************************/
static void FlashRedirectTraps( tFlashParam * flashParam ) /* PRQA S 3673 */ /* MD_FblFlash_3673_3678 */
{
   FlashRegisterUnlock( FLASH_WDT_CPU );

   /* Save trap base register */
   flashParam->tempData[FlashTempTrapBase] = FLASH_MFCR(FLASH_BTV);
   /* Set redirected trap base register */ /* PRQA S 0306 1 */ /* MD_FblFlash_0306_Traptable */
   FLASH_MTCR(FLASH_BTV, (tFlashUint32)&_lc_u_trap_tab_tc0);

   FlashRegisterLock(FLASH_WDT_CPU);
}

/***********************************************************************************************************************
 *  FlashRestoreTraps
 **********************************************************************************************************************/
/*! \brief         Restore trap handling to previous trap table.
 *  \pre           Flash driver present in RAM, FlashRedirectTraps() has to be called.
 *  \param[in]     flashParam Pointer to flash parameter structure
 **********************************************************************************************************************/
static void FlashRestoreTraps( const tFlashParam * flashParam )
{
   FlashRegisterUnlock( FLASH_WDT_CPU );

   /* Restore trap base register */
   FLASH_MTCR(FLASH_BTV, flashParam->tempData[FlashTempTrapBase]);

   FlashRegisterLock(FLASH_WDT_CPU); /* PRQA S 2987 */ /* MD_Flash_HardwareRelatedFunction */
}

/***********************************************************************************************************************
 *  TRAP HANDLING
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FlashTrapError
 **********************************************************************************************************************/
/*! \brief         Generic trap error handling.
 *  \details       This function handles traps which occurred during erase or write operations
 *  \pre           Traps redirected to flash driver trap handling.
 **********************************************************************************************************************/
static void FlashTrapError( void )
{
   /* Await end of pending flash operations */
   /* Check if erase or programming status bits are set */ /* PRQA S 0303 1 */ /* MD_FblFlash_0303 */
   if (FlashGetStatusProg() || FlashGetStatusErase())
   {
      /* Wait for busy bits to be reset */ /* PRQA S 0303 1 */ /* MD_FblFlash_0303 */
      while(FlashGetStatusBusy())
      {
         ;
      }
   }
   FlashResetToReadMode(); /* PRQA S 2987 */ /* MD_Flash_HardwareRelatedFunction */
   FlashRegisterUnlock(FLASH_WDT_SYSTEM);
   FlashRegisterUnlock(FLASH_WDT_CPU);
   FlashSetResetReason(); /* PRQA S 0303 */ /* MD_FblFlash_0303 */
   /* Toggle software reset by writing reset request register */ /* PRQA S 0303 1 */ /* MD_FblFlash_0303 */
   FLASH_SCU_SWRSTCON |= FLASH_VAL_SWRSTCON_RES_REQ;
   FlashRegisterLock(FLASH_WDT_SYSTEM);
   FlashRegisterLock(FLASH_WDT_CPU);

   /* Wait until reset is executed. */
   while (1)
   {
      ;
   }
}

/***********************************************************************************************************************
 *  FlashTrapMMU
 **********************************************************************************************************************/
/*! \brief         MMU error trap function.
 *  \pre           Traps redirected to flash driver trap handling.
 **********************************************************************************************************************/
void TRAP_PREFIX( FLASH_MMU_TRAP ) FlashTrapMMU( void )
{
   /* Redirect to generic trap handling */
   FlashFlushWriteBuffers();
   FlashTrapError();
}

/***********************************************************************************************************************
 *  FlashTrapProtection
 **********************************************************************************************************************/
/*! \brief         Protection error trap function.
 *  \pre           Traps redirected to flash driver trap handling.
 **********************************************************************************************************************/
void TRAP_PREFIX( FLASH_PROT_TRAP ) FlashTrapProtection( void )
{
   /* Redirect to generic trap handling */
   FlashFlushWriteBuffers();
   FlashTrapError();
}

/***********************************************************************************************************************
 *  FlashTrapInstruction
 **********************************************************************************************************************/
/*! \brief         Instruction error trap function.
 *  \pre           Traps redirected to flash driver trap handling.
 **********************************************************************************************************************/
void TRAP_PREFIX( FLASH_INST_TRAP ) FlashTrapInstruction( void )
{
   /* Redirect to generic trap handling */
   FlashFlushWriteBuffers();
   FlashTrapError();
}

/***********************************************************************************************************************
 *  FlashTrapContext
 **********************************************************************************************************************/
/*! \brief         Context error trap function.
 *  \pre           Traps redirected to flash driver trap handling.
 **********************************************************************************************************************/
void TRAP_PREFIX( FLASH_CONT_TRAP ) FlashTrapContext( void )
{
   /* Redirect to generic trap handling */
   FlashFlushWriteBuffers();
   FlashTrapError();
}

/***********************************************************************************************************************
 *  FlashTrapBus
 **********************************************************************************************************************/
/*! \brief         Bus error trap function.
 *  \pre           Traps redirected to flash driver trap handling.
 **********************************************************************************************************************/
void TRAP_PREFIX( FLASH_BUS_TRAP ) FlashTrapBus( void )
{
   /* Redirect to generic trap handling */
   FlashFlushWriteBuffers();
   FlashTrapError();
}

/***********************************************************************************************************************
 *  FlashTrapAssertion
 **********************************************************************************************************************/
/*! \brief         Assertion trap function.
 *  \pre           Traps redirected to flash driver trap handling.
 **********************************************************************************************************************/
void TRAP_PREFIX( FLASH_ASS_TRAP ) FlashTrapAssertion( void )
{
   /* Redirect to generic trap handling */
   FlashFlushWriteBuffers();
   FlashTrapError();
}

/***********************************************************************************************************************
 *  FlashTrapSystem
 **********************************************************************************************************************/
/*! \brief         System trap function.
 *  \pre           Traps redirected to flash driver trap handling.
 **********************************************************************************************************************/
void TRAP_PREFIX( FLASH_SYS_TRAP ) FlashTrapSystem( void )
{
   /* Redirect to generic trap handling */
   FlashFlushWriteBuffers();
   FlashTrapError();
}

/***********************************************************************************************************************
 *  FlashTrapNMI
 **********************************************************************************************************************/
/*! \brief         NMI trap function.
 *  \pre           Traps redirected to flash driver trap handling.
 **********************************************************************************************************************/
void TRAP_PREFIX( FLASH_NMI_TRAP ) FlashTrapNMI( void )
{
   /* Redirect to generic trap handling */
   FlashFlushWriteBuffers();
   FlashTrapError();
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ExpFlashInit
 **********************************************************************************************************************/
/*! \brief         Flash driver initialization
 *  \details       This function initializes the flash driver after download.
 *  \pre           Flash driver present in RAM.
 *  \param[in,out] flashParam Pointer to flash parameter structure
 **********************************************************************************************************************/
void ExpFlashInit ( tFlashParam * flashParam )
{
   /* Report version of downloaded flash driver to Bootloader */
   flashParam->majorVersion = FLASH_DRIVER_VERSION_MAJOR;
   flashParam->minorVersion = FLASH_DRIVER_VERSION_MINOR;
   flashParam->patchLevel = FLASH_DRIVER_VERSION_PATCH;

   FlashResetToReadMode(); /* PRQA S 2987 */ /* MD_Flash_HardwareRelatedFunction */

   flashParam->errorCode = kFlashOk;
}

/***********************************************************************************************************************
 *  ExpFlashDeinit
 **********************************************************************************************************************/
/*! \brief         Flash driver deinitialization
 *  \details       This function deinitializes the flash driver after download.
 *  \pre           Flash driver initialized.
 *  \param[in,out] flashParam Pointer to flash parameter structure
 **********************************************************************************************************************/
void ExpFlashDeinit ( tFlashParam * flashParam )
{
   flashParam->errorCode = kFlashOk;
}

/***********************************************************************************************************************
 *  ExpFlashErase
 **********************************************************************************************************************/
/*! \brief         Flash driver erase function.
 *  \details       This function erases a given flash area.
 *  \pre           Flash driver initialized.
 *  \param[in,out] flashParam Pointer to flash parameter structure
 **********************************************************************************************************************/
void ExpFlashErase ( tFlashParam * flashParam )
{
   /* Redirect traps */
   FlashRedirectTraps( flashParam );

   /* Initialize error address */
   flashParam->errorAddress = flashParam->address; /* PRQA S 2982 */ /* MD_FblFlash_2982_2983_RedundantAssignment */

#if defined( FLASH_ENABLE_BAD_BLOCK_MGMT )
   FlashEraseInternal(flashParam);
#else /* FLASH_ENABLE_TC3XX_COMMENT && NXT_ENABLE_BAD_BLOCK_MGMT */
   flashParam->errorCode = FlashEraseSequence(flashParam->wdTriggerFct, flashParam->address, flashParam->eraseCount);
#endif /* FLASH_ENABLE_TC3XX_COMMENT && NXT_ENABLE_BAD_BLOCK_MGMT */
   /* Check for error state */
   if (flashParam->errorCode == kFlashOk)
   {
      flashParam->errorCode = FlashVerifyErasedSectorRangeSequence(flashParam->wdTriggerFct, flashParam->address, flashParam->eraseCount);
   }

   /* Erase all pending error flags */
   FlashClearStatusCommand(); /* PRQA S 2987 */ /* MD_Flash_HardwareRelatedFunction */

   /* Add erase marker to error code */
   if (flashParam->errorCode != kFlashOk)
   {
      flashParam->errorCode |= kFlashFctErase;
   }

   /* Restore traps to default value */
   FlashRestoreTraps( flashParam );
}

/***********************************************************************************************************************
 *  ExpFlashWrite
 **********************************************************************************************************************/
/*! \brief         Flash driver write function
 *  \details       This function writes data to flash memory.
 *  \pre           Flash driver initialized, write area has to be erased.
 *  \param[in,out] flashParam Pointer to flash parameter structure
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
void ExpFlashWrite ( tFlashParam * flashParam )
{
   tFlashUint32 flashPageSize;
   tFlashUint32 flashBurstSize;
   tFlashUint32 flashWriteSize;
   tFlashUint32 flashPageCommand;
   tFlashUint32 flashWriteCommand;
   tFlashData * localData; /* PRQA S 3678 */ /* MD_FblFlash_3673_3678 */
   tFlashData * compareData; /* PRQA S 3678 */ /* MD_FblFlash_3673_3678 */
   tFlashUint32 flashIndex;
   tFlashLength actualLength;
   tFlashUint32 eccsMask;
   volatile tFlashUint32 * eccsReg; /* PRQA S 3678 */ /* MD_FblFlash_3673_3678 */
   volatile tFlashUint32 * ecccReg;
   tFlashUint32 ecccMask;
   tFlashUint32 ecccValue;

   /* Initialize variables. */
   localData = flashParam->data;
   flashIndex = 0uL;
   flashWriteCommand = 0uL; /* PRQA S 2982 */ /* MD_FblFlash_2982_2983_RedundantAssignment */
   flashWriteSize = 0uL; /* PRQA S 2982 */ /* MD_FblFlash_2982_2983_RedundantAssignment */
   actualLength = flashParam->writeLength;

   /* Load current flash position into error address. */
   flashParam->errorAddress = flashParam->address;
   flashParam->errorCode = kFlashOk;
# if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
   flashParam->replaceResult = kFlashReplace_None;
# endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */

   /* Redirect traps */
   FlashRedirectTraps( flashParam );
   /* Erase all pending error flags */
   FlashClearStatusCommand(); /* PRQA S 2987 */ /* MD_Flash_HardwareRelatedFunction */

   /* Check if standard flash or WOP flash is used */
   if (flashParam->programmingType == FLASH_PROGRAM_WOP)
   {
      /* Prepare flash segment size */
      flashPageSize = FLASH_SEGMENT_SIZE_PFLASH;
      flashPageCommand = EnterPageModePFlash;
      /* Set page mode for WOP programming */
      flashWriteCommand = WriteWopStep4Val;
      flashWriteSize = flashPageSize;
      /* Initialize all variables, even when not used */
      flashBurstSize = 0u;       /* PRQA S 2983 */ /* MD_FblFlash_2982_2983_RedundantAssignment */
   }
   /* Check if PFlash or DFlash should be used */
   else if ((flashParam->address & FLASH_DFLASH_BASE_ADDRESS) == FLASH_DFLASH_BASE_ADDRESS)
   {
      /* Prepare flash segment sizes */
      flashPageSize = FLASH_SEGMENT_SIZE_DFLASH;
      flashBurstSize = FLASH_BURST_SIZE_DFLASH;
      flashPageCommand = EnterPageModeDFlash;
   }
   else
   {
      /* Prepare flash segment sizes */
      flashPageSize = FLASH_SEGMENT_SIZE_PFLASH;
      flashBurstSize = FLASH_BURST_SIZE_PFLASH;
      flashPageCommand = EnterPageModePFlash;
   }

   /* Trigger watchdog */
   (void)(* flashParam->wdTriggerFct)();

   while ((actualLength != 0u) && (flashParam->errorCode == kFlashOk))
   {
      flashParam->errorCode = FlashPageModeSequence( flashPageCommand );

      if (flashParam->errorCode == kFlashOk)
      {
         if (flashParam->programmingType != FLASH_PROGRAM_WOP)
         {
            /* Check if burst mode can be used - faster flash writes supported */
            if ((actualLength >= flashBurstSize) && ((flashParam->errorAddress & (flashBurstSize - 1u)) == 0x00uL))
            {
               /* Set burst mode */
               flashWriteCommand = WriteBurstStep4Val;
               flashWriteSize = flashBurstSize;
            }
            else
            {
               /* Set page mode */
               flashWriteCommand =  WritePageStep4Val;
               flashWriteSize = flashPageSize;
            }
         }

         flashParam->errorCode = FlashWriteSequence(flashParam->wdTriggerFct, flashParam->errorAddress, flashWriteSize, flashWriteCommand, &localData[flashIndex]);

# if defined( FLASH_ENABLE_BAD_BLOCK_MGMT )
/*!
 * Internal comment removed.
 *
 *
 */
         if (FlashGetStatusPver()) /* PRQA S 0303 */ /* MD_FblFlash_0303 */
         {
            /* Erase all pending error flags */
            FlashClearStatusCommand(); /* PRQA S 2987 */ /* MD_Flash_HardwareRelatedFunction */
            /* Retry write */
            flashParam->errorCode = FlashWriteSequence(flashParam->wdTriggerFct, flashParam->errorAddress, flashWriteSize, flashWriteCommand, &localData[flashIndex]);

            /* Write failed again? */
            if (FlashGetStatusPver()) /* PRQA S 0303 */ /* MD_FblFlash_0303 */
            {
               /* Erase sector and abort download. (If erasing fails, Block will be replaced) */
               flashParam->address = flashParam->errorAddress & kFlashReplace_addressMask;
               flashParam->eraseCount = 1u;

               FlashEraseInternal(flashParam);

#  if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
               if (kFlashOk != flashParam->errorCode)
               {
                  /* Block could not be erased nor replaced */
                  flashParam->errorCode = kFlashFctReplaceFailed;
               }
               else
#  endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
               {
                  /* Abort download here - it needs to be restarted */
                  flashParam->errorCode = kFlashWriteFailed;
               }
            }
#  if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
            else
            {
               flashParam->replaceResult = kFlashReplace_SecondWriteOk;
            }
#  endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
         }
#  if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
         else
         {
            if(kFlashReplace_None == flashParam->replaceResult)
            {
               flashParam->replaceResult = kFlashReplace_FirstWriteOk;
            }
         }
#  endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */
# endif /* FLASH_ENABLE_BAD_BLOCK_MGMT */

         if (flashParam->errorCode != kFlashOk)
         {
            flashParam->errorCode |= kFlashFctWrite;
         }
         else
         {
            /* Process length and address data */
            actualLength -= flashWriteSize;
            flashParam->errorAddress += flashWriteSize;
            flashIndex += flashWriteSize / 4u;
         }
      }
   }

   FlashResetToReadMode(); /* PRQA S 2987 */ /* MD_Flash_HardwareRelatedFunction */

   ecccReg   = flashParam->pflashEccControlReg;
   ecccMask  = flashParam->flashEccControlMask;
   ecccValue = flashParam->flashEccControlValue;

   /* Clear ECC error flags before data verification */
   FlashRegisterUnlock( FLASH_WDT_CPU );
   (*ecccReg) = ((*ecccReg) & (~ecccMask)) | (ecccValue & ecccMask);
   FlashRegisterLock( FLASH_WDT_CPU );

#if defined( FLASH_ENABLE_WRITE_VERIFICATION )
   /* Verify written data */
   if (flashParam->errorCode == kFlashOk)
   {
      /* Preset variables for write verification */
      actualLength = flashParam->writeLength / 4u; /* Comparison is done word-based */
      flashIndex = 0u;
      compareData = (tFlashData *)flashParam->verificationAddress; /* PRQA S 0306 */ /* MD_FblFlash_0306 */
      localData = flashParam->data;
      flashParam->errorAddress = flashParam->address;

      eccsReg  = flashParam->pflashEccStatReg;  /* Pointer to the ecc register */
      eccsMask = flashParam->flashEccStatMask;  /* Relevant bitmask for the ecc detection */

      while (flashIndex < actualLength)
      {
         /* Trigger watchdog every 256 Bytes */
         if ((flashIndex & 0x3FuL) == 0x00u)
         {
            (void)(* flashParam->wdTriggerFct)();
         }

         /* PRQA S 0303 1 */ /* MD_FblFlash_0303 */
         if ( (compareData[flashIndex] == localData[flashIndex]) && (((*eccsReg) & eccsMask) == 0x00uL) )
         {
            /* Next 4 Bytes */
            flashIndex++;
            flashParam->errorAddress += 4u;
         }
         else
         {
            /* Set error code - verification failed */
            /* Please note: If intended data == actualData, it is most likely a ECC error */
            flashParam->acutalData = compareData[flashIndex];
            flashParam->intendedData = localData[flashIndex];
            flashParam->errorCode = kFlashWriteVerify;

            /* Clear flash status */
            FlashClearStatusCommand(); /* PRQA S 2987 */ /* MD_Flash_HardwareRelatedFunction */

            /* Leave verify loop after an error occurred */
            break;
         }
      }
   }
#endif /* FLASH_ENABLE_WRITE_VERIFICATION */

   /* Restore traps to default value */
   FlashRestoreTraps( flashParam );
}

# if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
/***********************************************************************************************************************
 *  ExpFlashReplace
 **********************************************************************************************************************/
/*! \brief         Flash driver replace logical sector function
 *  \details       Triggers the Replace Logical Sector sequence
 *  \pre           Flash driver initialized
 *  \param[in,out] flashParam Pointer to flash parameter structure
 **********************************************************************************************************************/
void ExpFlashReplace ( tFlashParam * flashParam )
{
   /* Initialize error address */
   flashParam->errorAddress = flashParam->address;

   FlashReplaceLogicalSectorSequence(flashParam);

   /* Add erase marker to error code */
   if (flashParam->errorCode != kFlashOk)
   {
      flashParam->errorCode |= kFlashFctReplace;
   }
}
# endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */

#define FLASHDRV_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Module specific MISRA deviations:

   MD_FblFlash_0286:
      Reason:     [I] String literal contains character which is not a member of the basic source character
                  set. Characters used in this assembler string are processed correctly by assembler.
      Risk:       No risk.
      Prevention: No prevention defined.

   MD_FblFlash_0303:
      Reason:     [I] Cast between a pointer to volatile object and an integral type.
      Risk:       No identifiable risk as casts are used to define SFRs here.
      Prevention: No prevention defined.

   MD_FblFlash_0305_Traptable:
      Reason:     [I] Cast between a pointer to function and an integral type. The address is handed
                  over by an integral type because of the address of the trap table must be stored in a
                  hardware register.
      Risk:       Data has to be processed and cannot be converted correctly by a simple cast.
      Prevention: Code inspection has to ensure cast is correct.

   MD_FblFlash_0306_Traptable:
      Reason:     [I] Cast between a pointer to object and an integral type. The address is handed
                  over by an integral type because of the address of the trap table must be stored in a
                  hardware register.
      Risk:       Data has to be processed and cannot be converted correctly by a simple cast.
      Prevention: Code inspection has to ensure cast is correct.

   MD_FblFlash_0306:
      Reason:     [I] Cast between a pointer to object and an integral type. The address is handed
                  over by an integral type because of the FblWrapperFlash/FblDrvFlash interface definition.
      Risk:       Data has to be processed and cannot be converted correctly by a simple cast.
      Prevention: Code inspection has to ensure cast is correct.

   MD_FblFlash_0341:
      Reason:     "Rule 0341: K&R compilers do not support the ISO stringify operator '#'."
                  This Bootloader requires C90 and C90 supports ## operators.
      Risk:       No risk.
      Prevention: No prevention defined.

   MD_FblFlash_0428_Traptable:
      Reason:     We do not intend a function call of TriCore_trap_table(), rather we are getting the address
                  of the function. Parenthesis are not included by design.
      Risk:       No risk
      Prevention: No prevention defined.

   MD_FblFlash_0554_Traptable:
      Reason:     [C] 'static TriCore_trap_table()' is used but no definition has been given. The function
                  is implemented as assembler function and the interface definition is needed to reference
                  the function in C code.
      Risk:       No risk
      Prevention: No prevention defined.

   MD_FblFlash_0883:
      Reason:     QAC does not recognize #elif statements and concludes that the header file is not protected against
                  repeated inclusion.
      Risk:       The repeated inclusion protection is missing.
      Prevention: Correctness of repeated inclusion protection has to be verified by code inspection.

   MD_FblFlash_2018:
      Reason:     Default label of switch/case is unreachable. The default label is inserted
                  to define a valid reaction in case the function is called with invalid parameter
                  values.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblFlash_2071:
      Reason:     This language extension is supported by the GNU compiler
      Risk:       Other compiler than GNU selected.
      Prevention: Code inspection has to insure that this language extension is used only with the GNU compiler.

   MD_FblFlash_2982_2983_RedundantAssignment:
      Reason:     Some assignment are kept, even if redundant, for preventing compiler warnings
      Risk:       The assignment can unintentionally compromise the functionality behavior.
      Prevention: Check that every added assignment is not compromising the code behavior.

   MD_FblFlash_3006:
      Reason:     Assembly language shall be encapsulated and isolated.
      Risk:       Side effects of assembly statements disturb C code.
      Prevention: Code inspection has to ensure there are no side effects.

   MD_FblFlash_3203:
      Reason:     Variable is set but never used. This is caused by hardware requirements which
                  define a read access to a register to trigger a certain behavior.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblFlash_3218:
      Reason:     Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk:       Scope is larger than required (whole file instead of one function). Some other function could access the variable.
      Prevention: Take care that this deviation is used for constant data only (which cannot be modified).

   MD_FblFlash_3408:
      Reason:     Variable has external linkage but is being defined without any previous declaration.
      Risk:       No risk.
      Prevention: No prevention required as Variable is only used locally.

   MD_FblFlash_1752_3447_Traptable:
      Reason:     'Function' has external linkage but this declaration is not in a header file. The trap
                  handling functions are not defined to the header file because the interface is known to
                  the compiler/linker and the header file couldn't be included in the handling code.
      Risk:       Calling modules assume different function interfaces that the actually declared ones.
      Prevention: Check if function interfaces are correct during code inspection.

   MD_FblFlash_3448:
      Reason:     Declaration of typedef is not in a header file although it is used in a definition or
                  declaration with external linkage.
      Risk:       No risk.
      Prevention: Typedef is only used locally.

   MD_FblFlash_3673_3678:
      Reason:     The object referenced/addressed is not modified and could be declared of type 'const'.
                  The interface format is implemented following a standard interface definition which
                  may be missing const qualifiers for some implementation.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_Flash_HardwareRelatedFunction
      Reason:     QAC considers the calls to this hardware related functions as redundant.
      Risk:       Unexpected side effects of hardware-related functions may occur
      Prevention: Code inspection has to ensure there are no side effects.

   MD_Flash_SfrRead
      Reason:     Reading from an SFR does not return always the same value despite this is not recognized by QAC.
      Risk:       No risk.
      Prevention: No prevention required.

*/

/***********************************************************************************************************************
 *  END OF FILE: FLASHDRV.C
 **********************************************************************************************************************/

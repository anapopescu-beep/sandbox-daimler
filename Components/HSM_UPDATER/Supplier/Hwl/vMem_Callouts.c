
#include "Std_Types.h"
#include "vMem_30_Tc3xxInf01_Callout.h"

#ifdef _GNU_C_TRICORE_
# include <machine/intrinsics.h>
#endif

/* Common error codes */
#define kFlashOk                       0x00u               /**< Function call successful */
#define kFlashFailed                   0x01u               /**< Function call failed */

/***********************************************************************************************************************
*  REGISTER UNLOCK SPECIFIC DEFINES
**********************************************************************************************************************/
# define FLASH_POS_WDT_CON0_ENDINIT            0u    /**< Offset of ENDINIT in WDTxCON0 */
# define FLASH_POS_WDT_CON0_LCK                1u    /**< Offset of LCK in WDTxCON0 */
# define FLASH_POS_WDT_CON0_PW                 2u    /**< Offset of PW in WDTxCON0 */
# define FLASH_POS_WDT_CON0_REL                16u   /**< Offset of REL in WDTxCON0 */

/** Mask for all bits in 32 bit register */
# define FLASH_MASK_WDT_ALL                    0xFFFFFFFFul
/** Mask for ENDINIT in WDTxCON0 */
# define FLASH_MASK_WDT_CON0_ENDINIT           (0x1ul << FLASH_POS_WDT_CON0_ENDINIT)
/** Mask for LCK in WDTxCON0 */
# define FLASH_MASK_WDT_CON0_LCK               (0x1ul << FLASH_POS_WDT_CON0_LCK)
/** Inverted mask for LCK / ENDINIT in WDTxCON0 */
# define FLASH_INV_MASK_WDT_CON0_LCK_ENDINIT   ((FLASH_MASK_WDT_CON0_LCK | FLASH_MASK_WDT_CON0_ENDINIT) ^ FLASH_MASK_WDT_ALL)
/** Mask for PW in WDTxCON0 */
# define FLASH_MASK_WDT_CON0_PW                (0x3FFFul << FLASH_POS_WDT_CON0_PW)
/** Mask for LSB of PW in WDTxCON0 */
# define FLASH_MASK_WDT_CON0_PW_2              (0x1ul << FLASH_POS_WDT_CON0_PW)
/** Inverted mask for PW in WDTxCON0 */
# define FLASH_INV_MASK_WDT_CON0_PW            (FLASH_MASK_WDT_CON0_PW ^ FLASH_MASK_WDT_ALL)
/** Mask for inverting bits [7:2] of PW in WDTxCON0 */
# define FLASH_XOR_MASK_WDT_CON0_PW            (0x003Ful << FLASH_POS_WDT_CON0_PW)
/** Mask for REL in WDTxCON0 */
# define FLASH_MASK_WDT_CON0_REL               (0xFFFFul << FLASH_POS_WDT_CON0_REL)
/** Inverted mask for REL in WDTxCON0 */
# define FLASH_INV_MASK_WDT_CON0_REL           (FLASH_MASK_WDT_CON0_REL ^ FLASH_MASK_WDT_ALL)

# define FLASH_POS_WDT_SR_PAS                  7u    /**< Offset of PAS in WDTxSR */
# define FLASH_POS_WDT_SR_TCS                  8u    /**< Offset of TCS in WDTxCON0 */
# define FLASH_POS_WDT_SR_TIM                  16u   /**< Offset of TIM in WDTxCON0 */

/** Mask for PAS in WDTxSR */
# define FLASH_MASK_WDT_SR_PAS                 (0x1ul << FLASH_POS_WDT_SR_PAS)
/** Mask for TCS in WDTxSR */
# define FLASH_MASK_WDT_SR_TCS                 (0x1ul << FLASH_POS_WDT_SR_TCS)
/** Mask for TIM in WDTxSR */
# define FLASH_MASK_WDT_SR_TIM                 (0xFFFFul << FLASH_POS_WDT_SR_TIM)

/** Unlocked state of ENDINIT in WDTxCON0 */
# define FLASH_VAL_WDT_CON0_ENDINIT_UNLOCK     (0x0ul << FLASH_POS_WDT_CON0_ENDINIT)
/** Locked state of ENDINIT in WDTxCON0 */
# define FLASH_VAL_WDT_CON0_ENDINIT_LOCK       (0x1ul << FLASH_POS_WDT_CON0_ENDINIT)
/** Unlocked state of LCK in WDTxCON0 */
# define FLASH_VAL_WDT_CON0_LCK_UNLOCK         (0x0ul << FLASH_POS_WDT_CON0_LCK)
/** Locked state of LCK in WDTxCON0 */
# define FLASH_VAL_WDT_CON0_LCK_LOCK           (0x1ul << FLASH_POS_WDT_CON0_LCK)

# define FLASH_CORE_ID     0xFE1C   /**< Core Identification Register */
# define FLASH_BTV         0xFE24   /**< Base Trap Vector Table Pointer */

# if !defined( FLASH_IOS )
#  define FLASH_IOS(type, base, offset) (*((volatile type *)((base)+(offset))))
# endif

/* PRQA S 0883 1 */ /* MD_FblFlash_0883 */
/* Base addresses */
#  define FLASH_PFI_BASE      0xA8080000ul
#  define FLASH_SCU_BASE      0xF0036000ul
#  define FLASH_PMU_FSI_BASE  0xF8030000ul
#  define FLASH_DMU_CMD_BASE  0xF8040000ul

#  define FLASH_DMU_HF_STATUS      FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0010ul)  /**< Flash Status Register (DMU_HF_STATUS) */
#  define FLASH_DMU_HF_OPERATION   FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0018ul)  /**< Flash Operation Register (DMU_HF_OPERATION) */
#  define FLASH_DMU_HF_CONTROL     FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0014ul)  /**< Flash Control Register (DMU_HF_CONTROL) */
#  define FLASH_DMU_HF_ERRSR       FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0034ul)  /**< Flash Control Register (DMU_HF_ERRSR) */

#  define FLASH_DF0_ECCS           FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0044ul)  /**< DF0 ECC Status Register */

#  define FLASH_PFI_ECCS(n)        FLASH_IOS(tFlashUint32, FLASH_PFI_BASE, ((n) * 0x00300000ul) + 0x0020ul)  /**< PFn ECC Status Register */

#  define FLASH_FLASH0_ID          FLASH_IOS(tFlashUint32, FLASH_PMU_FSI_BASE, 0x8508ul)  /**< Flash Module Identification Register (PMU_ID) */

#  define FLASH_SCU_WDTCPUCON0(n)  FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, ((n) * 0x000Cul) + 0x024Cul)  /**< CPUn WDT control register 0 */

#  define FLASH_SCU_WDTSCON0       FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x02A8ul)  /**< System WDT control register 0 */
#  define FLASH_SCU_WDTSCON1       FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x02ACul)  /**< System WDT Control Register 1 */

#  define FLASH_SCU_WDTSSR         FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x02B0ul)  /**< CPU System WDT Status Register */
#  define FLASH_SCU_WDTCPUSR(n)    FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, ((n) * 0x000Cul) + 0x0254ul)  /**< CPUn WDT Status Register */

#  define FLASH_SCU_RSTCON         FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x0058ul)  /**< Reset Configuration Register */

#  define FLASH_SCU_STSTAT         FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x00C0ul)  /**< Start-up Status Register */

#  define FLASH_SCU_SWRSTCON       FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x0060ul)  /**< Software Reset Configuration Register */



/* His Standard Flashdrv types */
typedef unsigned long  tFlashData;              /**< Flash data object */
typedef unsigned long  tFlashAddress;           /**< Flash target address type */
typedef unsigned long  tFlashLength;            /**< Flash length type */
typedef unsigned short tFlashErrorCode;         /**< Flash Error Code */

/* Generic Flash basic types */
typedef unsigned char   tFlashUint8;             /**< equivalent to vuint8  */
typedef unsigned short  tFlashUint16;            /**< equivalent to vuint16 */
typedef unsigned long   tFlashUint32;            /**< equivalent to vuint32 */


/** Watchdog register set */
typedef struct
{
  volatile tFlashUint32 * con0;  /**< WDTxCON0 register */
  volatile tFlashUint32 * sr;    /**< WDTxSR register */
} tflashWdtRegisters;



static const tflashWdtRegisters flashWdtRegAddrs[] =
{
  { &FLASH_SCU_WDTCPUCON0(0), &FLASH_SCU_WDTCPUSR(0) } /* PRQA S 0303 */ /* MD_FblFlash_0303 */
  , { &FLASH_SCU_WDTCPUCON0(1), &FLASH_SCU_WDTCPUSR(1) } /* PRQA S 0303 */ /* MD_FblFlash_0303 */
  , { &FLASH_SCU_WDTCPUCON0(2), &FLASH_SCU_WDTCPUSR(2) } /* PRQA S 0303 */ /* MD_FblFlash_0303 */
  , { &FLASH_SCU_WDTCPUCON0(3), &FLASH_SCU_WDTCPUSR(3) } /* PRQA S 0303 */ /* MD_FblFlash_0303 */
  , { &FLASH_SCU_WDTCPUCON0(4), &FLASH_SCU_WDTCPUSR(4) } /* PRQA S 0303 */ /* MD_FblFlash_0303 */
  , { &FLASH_SCU_WDTCPUCON0(5), &FLASH_SCU_WDTCPUSR(5) } /* PRQA S 0303 */ /* MD_FblFlash_0303 */
};






# define VMEM_30_TC3XXINF01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
static tFlashErrorCode FlashRegisterGetRegisters(vMem_30_Tc3xxInf01_LockLevelType wdtType, tflashWdtRegisters * wdtRegisters)
{
  tFlashErrorCode   result;
  tFlashUint32      codeId;

  /* Assume valid register set */
  result = kFlashOk;

  switch (wdtType)
  {
    /* Safety watchdog */
  case VMEM_30_TC3XXINF01_SYSTEM:
  {
    /* PRQA S 0303 2 */ /* MD_FblFlash_0303 */
    wdtRegisters->con0 = &FLASH_SCU_WDTSCON0;
    wdtRegisters->sr = &FLASH_SCU_WDTSSR;

    break;
  }
  /* Case for CPU not used by vMem on HSM */
#if 0
  /* CPU core specific watchdog */
  case VMEM_30_TC3XXINF01_CPU:
  {
    /* Read core ID from SFR */
    codeId = __mfcr(FLASH_CORE_ID) & 0x07ul;

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
#endif
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
static tFlashUint32 FlashRegisterPasswordAccess(tflashWdtRegisters * wdtRegisters)
{
  tFlashUint32   wdtcon0;
  tFlashUint32   wdtsr;
  tFlashUint32   wdtcon0Value;
  tFlashUint32   prevPass;
  tFlashUint32   currentPass;

  /* Get values of affected watchdog registers */
  wdtcon0 = *(wdtRegisters->con0);
  wdtsr = *(wdtRegisters->sr);

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
    currentPass = (prevPass << 1u) & FLASH_MASK_WDT_CON0_PW;
    currentPass |= ((prevPass >> 13u) ^ (prevPass >> 12u) ^ (prevPass >> 11u) ^ (prevPass >> 1u)) & FLASH_MASK_WDT_CON0_PW_2;
  }

  /* Set updated value of password
  Additionally unlock control access, but lock end-of-initialization bit */
  wdtcon0 &= (FLASH_INV_MASK_WDT_CON0_PW & FLASH_INV_MASK_WDT_CON0_LCK_ENDINIT);
  wdtcon0 |= (currentPass | FLASH_VAL_WDT_CON0_LCK_UNLOCK | FLASH_VAL_WDT_CON0_ENDINIT_LOCK);

  /* Return current value, including updated password */
  wdtcon0Value = wdtcon0;

  /* Evaluate timer check status flag */
  if (0u != (wdtsr & FLASH_MASK_WDT_SR_TCS))
  {
    /* Re-evaluate status register for current counter value */
    wdtsr = *(wdtRegisters->sr);

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
static void FlashRegisterModifyAccess(tflashWdtRegisters * wdtRegisters, tFlashUint32 regValue, tFlashUint32 lockBit)
{
  tFlashUint32 wdtcon0;

  /* Ensure parameter only covers ENDINIT bit */
  lockBit &= FLASH_MASK_WDT_CON0_ENDINIT;
  /* Set end-of-initialization bit to desired value
  Additionally lock control access again */
  wdtcon0 = (regValue & FLASH_INV_MASK_WDT_CON0_LCK_ENDINIT) | lockBit | FLASH_VAL_WDT_CON0_LCK_LOCK;

  /* Modify access to WDTxCON0 */
  *(wdtRegisters->con0) = wdtcon0;

  /* Read back ENDINIT, until cleared/set */
  while (lockBit != ((*(wdtRegisters->con0)) & FLASH_MASK_WDT_CON0_ENDINIT))
  {
    ;
  }
}



void vMem_30_Tc3xxInf01_Unlock(vMem_30_Tc3xxInf01_LockLevelType lvl)
{
  tFlashUint32         wdtcon0;
  tflashWdtRegisters   wdtRegisters;

  /* Determine affected watchdog register set */
  if (kFlashOk == FlashRegisterGetRegisters(lvl, &wdtRegisters))
  {
    /* Unlock access to watchdog registers, using password */
    wdtcon0 = FlashRegisterPasswordAccess(&wdtRegisters);

    /* Unlock register access to protected registers */
    FlashRegisterModifyAccess(&wdtRegisters, wdtcon0, FLASH_VAL_WDT_CON0_ENDINIT_UNLOCK);
  }

}

void vMem_30_Tc3xxInf01_Lock(vMem_30_Tc3xxInf01_LockLevelType lvl)
{
  tFlashUint32         wdtcon0;
  tflashWdtRegisters   wdtRegisters;

  /* Determine affected watchdog register set */
  if (kFlashOk == FlashRegisterGetRegisters(lvl, &wdtRegisters))
  {
    /* Unlock access to watchdog registers, using password */
    wdtcon0 = FlashRegisterPasswordAccess(&wdtRegisters);

    /* Lock register access to protected registers */
    FlashRegisterModifyAccess(&wdtRegisters, wdtcon0, FLASH_VAL_WDT_CON0_ENDINIT_LOCK);
  }
}


# define VMEM_30_TC3XXINF01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
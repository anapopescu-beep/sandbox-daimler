/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Register definitions for Infineon TriCore (TC2xx/TC3xx) flash driver
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
 *  02.01.00   2017-11-10  vapcel  ESCAN00095435      No changes
 *  02.02.00   2018-06-12  visrie  ESCAN00099655      No changes
 *  02.03.00   2018-07-06  visshs  ESCAN00099819      No changes
 *             2018-07-06  visshs  ESCAN00099845      No changes
 *             2018-07-06  visshs  ESCAN00098948      No changes
 *             2018-07-06  visshs  ESCAN00097719      No changes
 *             2018-07-06  visshs  ESCAN00099920      Export Command Sequence makro to upper layer
 *  02.05.00   2018-07-23  visshs  ESCAN00100136      No changes
 *                         visshs  ESCAN00100118      Removed Beta ESCAN
 *  02.06.00   2018-10-18  visshs  ESCAN00101095      Rework for MISRA 2012
 *                         visshs  ESCAN00101096      Add support for SWAP
 *  02.07.00   2019-01-31  visshs  ESCAN00101954      Add bitmasks for ERRSR.EVER, CLRE.CSQER, CLRE.CEVER
 *  02.07.01   2019-03-12  visrr   ESCAN00102457      No changes
 *  02.08.00   2019-04-05  visshs  ESCAN00102794      No changes
 *                         visshs  ESCAN00102782      No changes
 *  02.08.01   2019-06-12  visshs  ESCAN00103405      Fixed XD-ification of tFlashUint32
 *  02.08.02   2019-06-12  visshs  ESCAN00103388      No changes
 *  02.08.03   2019-09-09  vistbe  ESCAN00104250      Compiler error: Source and SFR file versions are inconsistent
 *             2019-09-17  vistmo  FBL-383            Added support for Green Hills compiler
 *                         vistmo  ESCAN00104337      No changes
 *                         vistmo  ESCAN00104338      No changes
 *  02.08.04   2019-10-08  vistmo  ESCAN00104536      No changes
 *  02.08.05   2019-12-11  vistmo  ESCAN00105120      No changes
 *  02.09.00   2020-10-13  visrcn  ESCAN00106588      No changes
 *  02.09.01   2022-03-25  visjdn  ESCAN00110854      No changes
 *                                 FBL-4596           No changes
 **********************************************************************************************************************/

#ifndef FBLDRVFLASH_SFR_TRICOREAURIXHIS_H
#define FBLDRVFLASH_SFR_TRICOREAURIXHIS_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#define FBLDRVFLASH_TRICOREAURIXHIS_SFR_VERSION          0x0209u
#define FBLDRVFLASH_TRICOREAURIXHIS_SFR_RELEASE_VERSION  0x01u

/* PRQA S 0750 TAG_FlashSfr_750 */ /* MD_MSR_18.4 */
/* PRQA S 5013 TAG_FlashSfr_5013 */ /* MD_FlashSfr_5013 */
/* PRQA S 3453 TAG_FlashSfr_3453 */ /* MD_MSR_19.7 */
/***********************************************************************************************************************
 *  TYPEDEFS AND DEFINES
 **********************************************************************************************************************/

# define FLASH_CORE_ID     0xFE1Cu   /**< Core Identification Register */
# define FLASH_BTV         0xFE24u   /**< Base Trap Vector Table Pointer */

# if !defined( FLASH_IOS )
#  define FLASH_IOS(type, base, offset) (*((volatile type *)((base)+(offset))))
# endif

/* Flash control macros */
#define FLASH_PROG_BASE_ADDR           0xAF000000uL            /**< Base address for all flash programming commands. */
/** Programming command macro. */ /* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define FLASH_COMMAND_CYCLE(addr, data) *((volatile tFlashAddress *)(FLASH_PROG_BASE_ADDR | (addr))) = ((tFlashAddress) (data))

/* PRQA S 0883 1 */ /* MD_FblFlash_0883 */
/* Base addresses */
#  define FLASH_PFI_BASE      0xA8080000uL
#  define FLASH_SCU_BASE      0xF0036000uL
#  define FLASH_PMU_FSI_BASE  0xF8030000uL
#  define FLASH_DMU_CMD_BASE  0xF8040000uL
#  define FLASH_UCB_BASE      0xAF400000uL


#  define FLASH_DMU_HF_STATUS      FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0010uL)  /**< Flash Status Register (DMU_HF_STATUS) */
#  define FLASH_DMU_HF_STATUS_BUSY_FLAGS  0x000000FFu                                          /**< Flash Status Register BBUSY flags (DMU_HF_STATUS.xyBUSY) */
#  define FLASH_DMU_HF_CONTROL     FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0014uL)  /**< Flash Control Register (DMU_HF_CONTROL) */
#  define FLASH_DMU_HF_OPERATION   FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0018uL)  /**< Flash Operation Register (DMU_HF_OPERATION) */
#  define FLASH_DMU_HF_PROTECT     FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x001CuL)  /**< Flash Protection Status Register (DMU_HF_PROTECT) */
#  define FLASH_DMU_HF_PROTECT_PRODISBMHD 0x00000010u                                          /**< UCB_BMHD Protection Disabled (DMU_HF_PROTECT.PRODISBMHD) */
#  define FLASH_DMU_HF_PROTECT_PRODISSWAP 0x00000020u                                          /**< UCB_SWAP Protection Disabled (DMU_HF_PROTECT.PRODISSWAP) */
#  define FLASH_DMU_HF_CONFIRM0    FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0020uL)  /**< Flash Confirm Status Register (DMU_HF_CONFIRM0) */
#  define FLASH_DMU_HF_CONFIRM1    FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0024uL)  /**< Flash Confirm Status Register 1 (DMU_HF_CONFIRM1) */
#  define FLASH_DMU_HF_CONFIRM2    FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0028uL)  /**< Flash Confirm Status Register 2 (DMU_HF_CONFIRM2) */
#  define FLASH_DMU_HF_ERRSR       FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0034uL)  /**< Flash Control Register (DMU_HF_ERRSR) */
#  define FLASH_DMU_HF_ERRSR_OPER         0x00000001uL                                         /**< Error status register - Flash operation error (DMU_HF_ERRSR.OPER) */
#  define FLASH_DMU_HF_ERRSR_SQER         0x00000002uL                                         /**< Error status register - Command sequence error (DMU_HF_ERRSR.SQER) */
#  define FLASH_DMU_HF_ERRSR_PROER        0x00000004uL                                         /**< Error status register - Protection Error (DMU_HF_ERRSR.PROER) */
#  define FLASH_DMU_HF_ERRSR_EVER         0x00000010uL                                         /**< Error status register - Erase Verify Error (DMU_HF_ERRSR.EVER) */
#  define FLASH_DMU_HF_PROCONTP    FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0084uL)  /**< Flash Control Register (DMU_HF_ERRSR) */
#  define FLASH_DMU_HF_CLRE        FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0038uL)  /**< Clear Error Register (DMU_HF_CLRE) */
#  define FLASH_DMU_HF_CLRE_CSQER         0x00000002uL                                         /**< Clear Error Register - Clear Command Sequence Error (DMU_HF_CLRE.CSQER) */
#  define FLASH_DMU_HF_CLRE_CPROER        0x00000004uL                                         /**< Clear Error Register - Clear Protection Error (DMU_HF_CLRE.CPROER) */
#  define FLASH_DMU_HF_CLRE_CEVER         0x00000010uL                                         /**< Clear Error Register - Clear Erase Verify Error (DMU_HF_CLRE.CEVER) */
#  define FLASH_DF0_ECCS           FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0044uL)  /**< DF0 ECC Status Register */
#  define FLASH_DMU_HF_PROCONTP    FLASH_IOS(tFlashUint32, FLASH_DMU_CMD_BASE, 0x0084uL)  /**< Flash Control Register (DMU_HF_ERRSR) */
#  define FLASH_DMU_HF_PROCONTP_SWAPEN    0x00030000uL                                         /**< Mask for SWAPEN bits of HF_PROCONTP register */
#  define FLASH_SWAPEN_SOTA_ENABLED       0x00030000uL                                         /**< Value for HF_PROCONTP.SWAPEN: SOTA_ENABLED */

#  define FLASH_PFI_ECCS(n)        FLASH_IOS(tFlashUint32, FLASH_PFI_BASE, ((n) * 0x00300000uL) + 0x0020uL)  /**< PFn ECC Status Register */

#  define FLASH_FLASH0_ID          FLASH_IOS(tFlashUint32, FLASH_PMU_FSI_BASE, 0x8508uL)  /**< Flash Module Identification Register (PMU_ID) */

#  define FLASH_SCU_WDTCPUCON0(n)  FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, ((n) * 0x000CuL) + 0x024CuL)  /**< CPUn WDT control register 0 */

#  define FLASH_SCU_WDTSCON0       FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x02A8uL)      /**< System WDT control register 0 */
#  define FLASH_SCU_WDTSCON1       FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x02ACuL)      /**< System WDT Control Register 1 */

#  define FLASH_SCU_WDTSSR         FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x02B0uL)      /**< CPU System WDT Status Register */
#  define FLASH_SCU_WDTCPUSR(n)    FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, ((n) * 0x000CuL) + 0x0254uL)  /**< CPUn WDT Status Register */

#  define FLASH_SCU_RSTCON         FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x0058uL)      /**< Reset Configuration Register */

#  define FLASH_SCU_STSTAT         FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x00C0uL)      /**< Start-up Status Register */

#  define FLASH_SCU_SWRSTCON       FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x0060uL)      /**< Software Reset Configuration Register */
#  define FLASH_SCU_SWAPCTRL       FLASH_IOS(tFlashUint32, FLASH_SCU_BASE, 0x014CuL)      /**< Swap Control Register */
#  define FLASH_SCU_SWAPCTRL_ADDRCFG      0x00000003uL                                         /**< Mask for ADDRCFG bits of SWAPCTRL register */
#  define FLASH_SWAP_ADDRCFG_REGION_A     0x00000001uL                                         /**< Value for SWAPCTRL_ADDRCFG: Address Region A active (B inactive) */
#  define FLASH_SWAP_ADDRCFG_REGION_B     0x00000002uL                                         /**< Value for SWAPCTRL_ADDRCFG: Address Region B active (A inactive) */


#  if defined( FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API )
/*!
 * Internal comment removed.
 *
 *
 */
#   define FLASH_UCB_REDSEC_BASE              (FLASH_UCB_BASE + 0x1800uL)
#   define FLASH_UCB_REDSECPL( p, s )         FLASH_IOS(tFlashUint32, FLASH_UCB_REDSEC_BASE, ((p) * 0x40u + (s) * 8u + 0x00u))
#   define FLASH_UCB_REDSECPL_ADDR( p, s )    (FLASH_UCB_REDSECPL( (p), (s) ) & 0x3Fu)
#   define FLASH_UCB_REDSECPL_IS_USED( p, s ) ((FLASH_UCB_REDSECPL( (p), (s) ) & (1u << 14u)) == (1u << 14u))
#   define FLASH_UCB_REDSECPL_IS_FAIL( p, s ) ((FLASH_UCB_REDSECPL( (p), (s) ) & (1u << 15u)) == (1u << 15u))
#   define FLASH_UCB_REDSECPH( p, s )         FLASH_IOS(tFlashUint32, FLASH_UCB_REDSEC_BASE, ((p) * 0x40u + (s) * 8u + 0x04u))
#   define FLASH_UCB_REDSECPH_FLAGS( p, s )   (FLASH_UCB_REDSECPH( (p), (s) ) >> 24u)
#   define FLASH_UCB_REDSECPH_FLAGS_TEST      0x00u
#   define FLASH_UCB_REDSECPH_FLAGS_RLS       0xFFu
#   define FLASH_UCB_REDSECDL0( s )           FLASH_IOS(tFlashUint32, FLASH_UCB_REDSEC_BASE, ((s) * 8u + 0x180u))
#   define FLASH_UCB_REDSECDH0( s )           FLASH_IOS(tFlashUint32, FLASH_UCB_REDSEC_BASE, ((s) * 8u + 0x184u))
#   define FLASH_UCB_REDSECDL1( s )           FLASH_IOS(tFlashUint32, FLASH_UCB_REDSEC_BASE, ((s) * 8u + 0x1C0u))
#   define FLASH_UCB_REDSECDH1( s )           FLASH_IOS(tFlashUint32, FLASH_UCB_REDSEC_BASE, ((s) * 8u + 0x1C4u))
#  endif /* FLASH_ENABLE_REPLACE_LOGICAL_SECTOR_API */

/* PRQA L:TAG_FlashSfr_750 */
/* PRQA L:TAG_FlashSfr_5013 */
/* PRQA L:TAG_FlashSfr_3453 */
/*****************************************************************************/

/* Module specific MISRA deviations:

   MD_FlashSfr_5013:
     Reason: Taken directly from hardware-dependent compiler manufacturer
             provided definition, which is using basic types. This is considered
             more secure and allows for easier comparison to updated version.
     Risk: Compiler manufacturer provided types produce wrong register access.
     Prevention: -

*/

#endif /* FBLDRVFLASH_SFR_TRICOREAURIXHIS_H */
/***********************************************************************************************************************
 *  END OF FILE: FLASH_SFR.H
 **********************************************************************************************************************/

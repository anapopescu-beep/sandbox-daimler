/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Register definitions for Infineon Aurix+ (TC3xx)
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
 *  01.11.00   2017-10-19  visach  ESCAN00093985    No changes
 *                                 ESCAN00094027    Support Aurix+
 *                         viskjs  ESCAN00096812    No changes
 *  01.11.01   2017-11-15  visach  ESCAN00097217    Fixed SFR gap between CPU4 and CPU5 FLASHCON address range
 *  01.12.00   2017-12-01  visach  ESCAN00097588    No changes
 *  01.12.01   2018-05-04  visrie  ESCAN00099314    No changes
 *  01.13.00   2018-05-02  vaddod  ESCAN00099284    No changes
 *             2018-06-14  visshs  ESCAN00099682    Add TC3XX register PCSR and PLL register flag constants
 *                                 ESCAN00099686    No changes
 *  01.14.00   2018-07-03  visach  ESCAN00099883    No changes
 *  01.15.00   2018-08-10  vistmo  ESCAN00100358    No changes
 *  01.15.01   2018-10-05  visach  ESCAN00100708    No changes
 *  01.15.02   2018-10-17  vistmo  ESCAN00101054    No changes
 *  01.16.00   2019-01-31  vistmo  ESCAN00101956    No changes
 *                                 ESCAN00101982    Adapting to MISRA 2012
 *  01.17.00   2019-04-01  vistmo  ESCAN00102706    No changes
 *                                 ESCAN00102853    No changes
 *  01.18.00   2019-06-25  vistmo  ESCAN00103504    No changes
 *  01.19.00   2019-08-22  vistmo  FBL-383          No changes
 *  01.19.01   2019-10-22  vistmo  ESCAN00103561    No changes
 *  01.20.00   2019-12-13  vistmo  FBL-777          No changes
 *  01.21.00   2020-04-28  vistmo  FBL-1734         No changes
 *  01.22.00   2020-05-29  vistmo  FBL-1869         No changes
 *  01.23.00   2020-08-12  visjdn  FBL-1947         No changes
 *  01.23.01   2020-09-01  visjdn  ESCAN00107257    No changes
 *  01.24.00   2020-10-02  visrcn  FBL-2511         No changes
 *  01.25.00   2020-11-05  vistmo  FBL-2336         No changes
 *  01.26.00   2020-11-10  visjdn  FBL-2311         No changes
 *                                 FBL-2665         No changes
 *  01.26.01   2021-03-22  visjdn  ESCAN00108454    No changes
 *  01.27.00   2021-07-22  visrie  FBL-3688         No changes
 *  01.28.00   2021-09-21  visjdn  FBL-3844         No changes
 *  01.29.00   2022-03-04  vishor  FBL-4692         No changes
 *                                 ESCAN00110852    No changes
 *                                 ESCAN00111409    No changes
 *  01.30.00   2022-05-10  vishor  FBL-4246         No changes
 *  01.31.00   2022-05-17  visjdn  FBL-5159         No changes
 *  01.32.00   2022-05-31  visjdn  FBL-4938         No changes
 *  01.32.01   2022-08-04  visrie  ESCAN00112517    No changes
 *  01.32.02   2022-08-05  visjdn  ESCAN00112523    No changes
 *  01.33.00   2022-08-09  visjdn  FBL-4709         No changes
 **********************************************************************************************************************/

#ifndef FBL_SFR_AURIXPLUS_H
#define FBL_SFR_AURIXPLUS_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if defined( FBL_SFR_BASE_ADRESSES_PRECONFIGURED )
#else
# error "Error in fbl_sfr.h: Please add base addresses for your derivative to the .pcu file."
#endif /* FBL_SFR_BASE_ADRESSES_PRECONFIGURED */

/* PRQA S 3453 TAG_SfrDefinitionMacros */ /* MD_MSR_19.7 */


#if !defined( FBL_IOS )
# define FBL_IOS(type, base, offset) (*((volatile type *)((base) + (offset))))
#endif



#define FBL_CORE_ID           0xFE1Cu      /**< Core Identification Register */
#define FBL_ICR               0xFE2Cu      /**< Interrupt Control Register */
#define FBL_CPU_DATR          0x9018u      /**< Data Asynchronous Trap Register */

/* Port handling registers */
#define FBL_PORT_OUT(x)          FBL_IOS(vuint32, FBL_PORT_BASE, 0x00u + ((x) * 0x100u))                       /**< Port x output register */
#define FBL_PORT_IOCR0(x)        FBL_IOS(vuint32, FBL_PORT_BASE, 0x10u + ((x) * 0x100u))                       /**< Port x input/output control register 0 */
#define FBL_PORT_IOCR4(x)        FBL_IOS(vuint32, FBL_PORT_BASE, 0x14u + ((x) * 0x100u))                       /**< Port x input/output control register 4  */
#define FBL_PORT_IOCR8(x)        FBL_IOS(vuint32, FBL_PORT_BASE, 0x18u + ((x) * 0x100u))                       /**< Port x input/output control register 8  */
#define FBL_PORT_IOCR12(x)       FBL_IOS(vuint32, FBL_PORT_BASE, 0x1Cu + ((x) * 0x100u))                       /**< Port x input/output control register 12  */
#define FBL_PORT_IN(x)           FBL_IOS(vuint32, FBL_PORT_BASE, 0x24u + ((x) * 0x100u))                       /**< Port x input register */
#define FBL_PORT_PDR(x, y)       FBL_IOS(vuint32, FBL_PORT_BASE, 0x40u + ((x) * 0x100u) + ((y) * 0x04u))       /**< Port x pad driver mode register y */
#define FBL_PORT_PCSR(x)         FBL_IOS(vuint32, FBL_PORT_BASE, 0x64u + ((x) * 0x100u))                       /**< Port x pin controller select Register */
#define FBL_PORT_ACCEN(x, y)     FBL_IOS(vuint32, FBL_PORT_BASE, 0xFCu + ((x) * 0x100u) - ((y) * 0x04u))       /**< Port x access enable register y */

/* System Timer registers */
#define FBL_STM_CLC(x)           FBL_IOS(vuint32, FBL_STM_BASE, 0x00u + ((x) * 0x100u))                        /**< STM x clock control register, safety/cpu protected */
#define FBL_STM_TIM(x, y)        FBL_IOS(vuint32, FBL_STM_BASE, 0x10u + ((x) * 0x100u) + ((y) * 0x04u))        /**< STM x timer y register, read only */
#define FBL_STM_CAP(x)           FBL_IOS(vuint32, FBL_STM_BASE, 0x2Cu + ((x) * 0x100u))                        /**< STM x timer capture register, read only */
#define FBL_STM_CMP(x, y)        FBL_IOS(vuint32, FBL_STM_BASE, 0x30u + ((x) * 0x100u) + ((y) * 0x04u))        /**< STM x compare register y */
#define FBL_STM_CMCON(x)         FBL_IOS(vuint32, FBL_STM_BASE, 0x38u + ((x) * 0x100u))                        /**< STM x compare match control register */
#define FBL_STM_ICR(x)           FBL_IOS(vuint32, FBL_STM_BASE, 0x3Cu + ((x) * 0x100u))                        /**< STM x interrupt control register */
#define FBL_STM_ISCR(x)          FBL_IOS(vuint32, FBL_STM_BASE, 0x40u + ((x) * 0x100u))                        /**< STM x interrupt set/clear register */

#define FBL_STM_ICR_CMP0IR       0x00000002u    /**< Compare register 0 interrupt request flag */
#define FBL_STM_ISCR_CMP0IRR     0x00000001u    /**< Reset Compare register 0 interrupt flag */

/* Program Flash Interface registers */
#define FBL_PFI_ECCR(x)          FBL_IOS(vuint32, FBL_PFI_BASE, 0x00u + ((x) * 0x300000u))                     /**< PFI x ECC read register, read only */
#define FBL_PFI_ECCS(x)          FBL_IOS(vuint32, FBL_PFI_BASE, 0x20u + ((x) * 0x300000u))                     /**< PFI x ECC status register, read only */

/* Data Flash Interface registers */
#define FBL_DMU_ECCR(x)          FBL_IOS(vuint32, FBL_DMU_BASE, 0x40u + ((x) * 0x200000u))                     /**< DF x ECC read register, read only */
#define FBL_DMU_ECCS(x)          FBL_IOS(vuint32, FBL_DMU_BASE, 0x44u + ((x) * 0x200000u))                     /**< DF x ECC status register, read only */
#define FBL_DMU_ECCC(x)          FBL_IOS(vuint32, FBL_DMU_BASE, 0x48u + ((x) * 0x200000u))                     /**< DF x ECC control register, safety/cpu protected */

#define FBL_DMU_ECCC_TRAPDIS     0xC0000000u    /**< TRAPDIS bit in ECCC registers - disable ECC traps */

/* CPU Flash Configuration registers */ /** CPU x flash configuration register y, CPU protected */
#define FBL_CPU_FLASHCON(x, y)   FBL_IOS(vuint32, FBL_CPUSFR_BASE, (0x1100u + ((FBL_CPU##x##_OFFSET_FLASHCON0) + ((y) * 0x04u))))      /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#define FBL_CPU0_OFFSET_FLASHCON0 0x00000000u
#define FBL_CPU1_OFFSET_FLASHCON0 0x00020000u
#define FBL_CPU2_OFFSET_FLASHCON0 0x00040000u
#define FBL_CPU3_OFFSET_FLASHCON0 0x00060000u
#define FBL_CPU4_OFFSET_FLASHCON0 0x00080000u
#define FBL_CPU5_OFFSET_FLASHCON0 0x000C0000u

#define FBL_FLASHCON1_MASKUECC   0x00010000u    /**< MASKUECC bit in FLASHCON1 registers */

/* System Control Unit Reset control registers */
#define FBL_SCU_RSTCON           FBL_IOS(vuint32, FBL_SCU_BASE, 0x58u)                                         /**< Reset control register, safety protected */
#define FBL_SCU_RSTSTAT          FBL_IOS(vuint32, FBL_SCU_BASE, 0x50u)                                         /**< Reset status register, read only */
#define FBL_SCU_SWRSTCON         FBL_IOS(vuint32, FBL_SCU_BASE, 0x60u)                                         /**< Software reset configuration register, safety/cpu protected */

/* System Control Unit Watchdog control registers */
#define FBL_SCU_WDTCPUCON(x, y)  FBL_IOS(vuint32, FBL_SCU_BASE, 0x24Cu + ((x) * 0x0Cu) + ((y) * 0x04u))        /**< CPU x watchdog control register y, only writeable from specific CPU */
#define FBL_SCU_WDTCPUSR(x)      FBL_IOS(vuint32, FBL_SCU_BASE, 0x254u + ((x) * 0x0Cu))                        /**< CPU x watchdog status register, read only */
#define FBL_SCU_WDTSYSCON(y)     FBL_IOS(vuint32, FBL_SCU_BASE, 0x2A8u + ((y) * 0x04u))                        /**< System watchdog control register y, system protected */
#define FBL_SCU_WDTSYSSR         FBL_IOS(vuint32, FBL_SCU_BASE, 0x2B0u)                                        /**< System watchdog status register, read only */

/* System Control Unit Clock control registers */
#define FBL_SCU_OSCCON           FBL_IOS(vuint32, FBL_SCU_BASE, 0x10u)                                         /**< CCU oscillator circuit contorl register */
#define FBL_SCU_CCUCON(x)        FBL_SCU_CCUCON##x       /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */         /**< CCU x clock control registers */
#define FBL_SCU_CCUCON0          FBL_IOS(vuint32, FBL_SCU_BASE, 0x30u)
#define FBL_SCU_CCUCON1          FBL_IOS(vuint32, FBL_SCU_BASE, 0x34u)
#define FBL_SCU_CCUCON2          FBL_IOS(vuint32, FBL_SCU_BASE, 0x40u)
#define FBL_SCU_CCUCON6          FBL_IOS(vuint32, FBL_SCU_BASE, 0x80u)
#define FBL_SCU_CCUCON7          FBL_IOS(vuint32, FBL_SCU_BASE, 0x84u)
#define FBL_SCU_CCUCON8          FBL_IOS(vuint32, FBL_SCU_BASE, 0x88u)
#define FBL_SCU_CCUCON9          FBL_IOS(vuint32, FBL_SCU_BASE, 0x8Cu)
#define FBL_SCU_CCUCON10         FBL_IOS(vuint32, FBL_SCU_BASE, 0x90u)
#define FBL_SCU_CCUCON11         FBL_IOS(vuint32, FBL_SCU_BASE, 0x94u)

#define FBL_SCU_OSCRES           0x00000004u       /**< Oscillator watchdog reset */
#define FBL_SCU_PLLHV            0x00000100u       /**< Oscillator for PLL Valid High Status */
#define FBL_SCU_PLLLV            0x00000002u       /**< Oscillator for PLL Valid Low Status */
#define FBL_SCU_LCK              0x00000004u       /**< System PLL lock status */
#define FBL_SCU_PLL_RESLD        0x00040000u       /**< SYSPLLCON0, PERPLLCON0 RESLD */
#define FBL_SCU_PLL_K2RDY        0x00000020u       /**< SYSPLLSTAT, PERPLLSTAT K2RDY*/
#define FBL_SCU_PLL_K3RDY        0x00000010u       /**< PERPLLSTAT K2RDY*/
#define FBL_SCU_CCUCON_LCK       0x80000000u       /**< CCUCON LCK Bit */

/* System Control Unit PLL control registers */
#define FBL_SCU_SYSPLLSTAT       FBL_IOS(vuint32, FBL_SCU_BASE, 0x14u)                                         /**< System PLL Status register */
#define FBL_SCU_SYSPLLCON(x)     FBL_IOS(vuint32, FBL_SCU_BASE, 0x18u + ((x) * 0x04u))                         /**< System PLL Configuration x register */
#define FBL_SCU_PERPLLSTAT       FBL_IOS(vuint32, FBL_SCU_BASE, 0x24u)                                         /**< Peripheral PLL Status register */
#define FBL_SCU_PERPLLCON(x)     FBL_IOS(vuint32, FBL_SCU_BASE, 0x28u + ((x) * 0x04u))                         /**< Peripheral PLL Configuration x register */

/* System Control Unit Trap control registers */
#define FBL_SCU_TRAPSTAT         FBL_IOS(vuint32, FBL_SCU_BASE, 0x124u)                                        /**< Trap Status register */
#define FBL_SCU_TRAPCLR          FBL_IOS(vuint32, FBL_SCU_BASE, 0x12Cu)                                        /**< Trap Clear register */
#define FBL_SCU_TRAPDIS(x)       FBL_SCU_TRAPDIS##x      /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */         /**< Trap Disable x register */
#define FBL_SCU_TRAPDIS0         FBL_IOS(vuint32, FBL_SCU_BASE, 0x130u)
#define FBL_SCU_TRAPDIS1         FBL_IOS(vuint32, FBL_SCU_BASE, 0x120u)

/* Data Memory Unit control registers */
#define FBL_DMU_HF_PWAIT         FBL_IOS(vuint32, FBL_DMU_BASE, 0x68u)                                         /**< PFLASH Wait Cycle register */

/* General Purpose Timer Unit (GPT12) */
#define FBL_GPT12_CLC(x)         FBL_IOS(vuint32, FBL_GPT12_BASE, 0x00u + ((x) * 0x100u))

/* PRQA L:TAG_SfrDefinitionMacros */

#endif /* FBL_SFR_AURIXPLUS */

/***********************************************************************************************************************
 *  END OF FILE: FBL_SFR.H
 **********************************************************************************************************************/

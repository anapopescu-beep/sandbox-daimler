/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file  File:  BrsHw.c
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsHw for platform Infineon Aurix/AurixPlus
 *     Template:  This file is reviewed according to Brs_Template@Implementation[1.02.01]
 *
 *  \brief Description:  This is the hardware specific code file for Vector Basic Runtime System (BRS).
 *
 *  \attention Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to BrsHw.h.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

#define _BRSHW_C_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "BrsHw.h"

#if !defined (BRS_ENABLE_FBL_SUPPORT)
  #include "Os.h"
#endif

#include "BrsMain.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if (BRSHW_VERSION != 0x0104u)
  #error "Header and source file are inconsistent!"
#endif
#if (BRSHW_BUGFIX_VERSION != 0x00u)
  #error "Different versions of bugfix in Header and Source used!"
#endif

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/
#if defined (BRS_COMP_TASKING) 

#else
  #error "Unknown compiler specified!"
#endif

/**********************************************************************************************************************
 *  DEFINITION + MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONST VARIABLES
 *********************************************************************************************************************/
/*
 * Description: These constants are used to propagate the Versions over
 *              module boundaries.The version numbers are BCD coded. E.g. a sub
 *              version of 23 is coded with 0x23, a bug fix version of 9 is
 *              coded 0x09.
 */
uint8 const kBrsHwMainVersion   = (uint8)(BRSHW_VERSION >> 8);
uint8 const kBrsHwSubVersion    = (uint8)(BRSHW_VERSION & 0xFF);
uint8 const kBrsHwBugfixVersion = (uint8)(BRSHW_BUGFIX_VERSION);

#if defined (BRS_WATCHDOG_GROUP_A)
const uint32 kBrsWdtCon0Addresses[4] = {
  BRS_SFR_WDTCPU0CON0_ADDRESS,
  BRS_SFR_WDTCPU1CON0_ADDRESS,
  BRS_SFR_WDTCPU2CON0_ADDRESS,
  BRS_SFR_WDTSCON0_ADDRESS
};

#elif defined (BRS_WATCHDOG_GROUP_B)
const uint32 kBrsWdtCon0Addresses[8] = {
  BRS_SFR_WDTCPU0CON0_ADDRESS,
  BRS_SFR_WDTCPU1CON0_ADDRESS,
  BRS_SFR_WDTCPU2CON0_ADDRESS,
  BRS_SFR_WDTCPU3CON0_ADDRESS,
  BRS_SFR_WDTCPU4CON0_ADDRESS,
  0,  /* core ID 5 is not a valid core ID */
  BRS_SFR_WDTCPU5CON0_ADDRESS,
  BRS_SFR_WDTSCON0_ADDRESS
};
#endif
 
/**********************************************************************************************************************
 *  LOCAL VARIABLES AND LOCAL HW REGISTERS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CONTROLLER CONFIGURATION REGISTERS
 *********************************************************************************************************************/
#if defined (BRS_PLL_GROUP_A)
/*******************************************************************************
  PLL  GROUP  CONFIG
*******************************************************************************/
#define BRS_PLLCLC        BRSHW_IOS(uint32, 0xF0000040) /* original name: PLL_CLC */
#define BRS_VCO_BYPASS    0x00000020
#define BRS_OSC_DISC      0x01000000
#define BRS_PLL_LOCK      0x00000001
#define BRS_PLL_LOCK_RES  0x00000002
#define BRS_CLOCK_MASK    0x007FFFC4

/*******************************************************************************
  SYSTEM  CONTROL  UNIT  SCU
*******************************************************************************/
#define BRS_SCU_BASE  0xF0036000

#define BRS_SCU_OSCCON       BRSHW_IOS(uint32, BRS_SCU_BASE + 0x10)  /* OSCCON  OSC Control Register; Safety Endinit Protected */
#define BRS_SCU_PLLCON0      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x18)  /* PLLCON0 PLL Configuration 0 Register; Safety Endinit Protected */
#define BRS_SCU_PLLCON1      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x1C)  /* PLLCON1 PLL Configuration 1 Register; Safety Endinit Protected */
#define BRS_SCU_PLLCON2      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x20)  /* PLLCON2 PLL Configuration 2 Register; Safety Endinit Protected */
#define BRS_SCU_PLLSTAT      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x14)  /* PLLSTAT PLL Status Register */

#define BRS_SCU_CCUCON0      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x30)  /* CCUCON0 CCU Control Register 0; Safety Endinit Protected */
#define BRS_SCU_CCUCON1      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x34)  /* CCUCON1 CCU Control Register 1; Safety Endinit Protected */
#define BRS_SCU_CCUCON5      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x4C)  /* CCUCON5 CCU Control Register 5; Safety Endinit Protected */
#define BRS_SCU_CCUCON6      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x80)  /* CCUCON6 CCU Control Register 6; Safety Endinit Protected */
#define BRS_SCU_CCUCON7      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x84)  /* CCUCON7 CCU Control Register 7; Safety Endinit Protected */
#define BRS_SCU_CCUCON8      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x88)  /* CCUCON8 CCU Control Register 8; Safety Endinit Protected */

#define BRS_SCU_PLLERAYCON0  BRSHW_IOS(uint32, BRS_SCU_BASE + 0x28)  /* PLL_ERAY Configuration 0 Register; Safety Endinit Protected */
#define BRS_SCU_PLLERAYCON1  BRSHW_IOS(uint32, BRS_SCU_BASE + 0x2C)  /* PLL_ERAY Configuration 1 Register; Safety Endinit Protected */
#define BRS_SCU_PLLERAYSTAT  BRSHW_IOS(uint32, BRS_SCU_BASE + 0x24)  /* PLL_ERAY Status Register */

#define BRS_RSTSTAT          BRSHW_IOS(uint32, BRS_SCU_BASE + 0x50)  /* Reset Status Register */ 
#define BRS_SWRSTCON         BRSHW_IOS(uint32, BRS_SCU_BASE + 0x60)  /* Software Reset Configuration Register; Safety Endinit Protected */
#define BRS_SCU_TRAPCLR      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x12C) /* Trap Clear Register */
#define BRS_SCU_TRAPDIS      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x130) /* Trap Disable Register; Endinit Protected */

/*******************************************************************************
  GENERAL PURPOSE TIMER CLOCK CONTROL REGISTER
*******************************************************************************/
#define BRS_GPT120_BASE  0xF0002E00
#define BRS_GPT120_CLC       BRSHW_IOS(uint32, BRS_GPT120_BASE)

#elif defined (BRS_PLL_GROUP_B) || defined (BRS_PLL_GROUP_C)
/*******************************************************************************
  SYSTEM  CONTROL  UNIT  SCU
*******************************************************************************/
#define BRS_SCU_BASE  0xF0036000

#define BRS_SCU_OSCCON       BRSHW_IOS(uint32, BRS_SCU_BASE + 0x10)  /* OSCCON  OSC Control Register */
#define BRS_SCU_SYSPLLCON0   BRSHW_IOS(uint32, BRS_SCU_BASE + 0x18)  /* SYSPLLCON0 System PLL Configuration 0 Register */
#define BRS_SCU_SYSPLLCON1   BRSHW_IOS(uint32, BRS_SCU_BASE + 0x1C)  /* SYSPLLCON1 System PLL Configuration 1 Register */
#define BRS_SCU_SYSPLLCON2   BRSHW_IOS(uint32, BRS_SCU_BASE + 0x20)  /* SYSPLLCON2 System PLL Configuration 2 Register */
#define BRS_SCU_SYSPLLSTAT   BRSHW_IOS(uint32, BRS_SCU_BASE + 0x14)  /* SYSPLLSTAT System PLL Status Register */

#define BRS_SCU_CCUCON0      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x30)  /* CCUCON0 CCU Control Register  0 */
#define BRS_SCU_CCUCON1      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x34)  /* CCUCON1 CCU Control Register  1 */

#define BRS_SCU_CCUCON2      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x40)  /* CCUCON2 CCU Control Register  2 */
#define BRS_SCU_CCUCON5      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x4C)  /* CCUCON5 CCU Control Register  5 */
#define BRS_SCU_CCUCON6      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x80)  /* CCUCON6 CCU Control Register  6 */
#define BRS_SCU_CCUCON7      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x84)  /* CCUCON7 CCU Control Register  7 */
#define BRS_SCU_CCUCON8      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x88)  /* CCUCON8 CCU Control Register  8 */
#define BRS_SCU_CCUCON9      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x8C)  /* CCUCON8 CCU Control Register  9 */
#define BRS_SCU_CCUCON10     BRSHW_IOS(uint32, BRS_SCU_BASE + 0x90)  /* CCUCON8 CCU Control Register 10 */
#define BRS_SCU_CCUCON11     BRSHW_IOS(uint32, BRS_SCU_BASE + 0x94)  /* CCUCON8 CCU Control Register 11 */

#define BRS_SCU_PERPLLCON0   BRSHW_IOS(uint32, BRS_SCU_BASE + 0x28)  /* PERPLLCON0 Peripheral PLL Configuration 0 Register */
#define BRS_SCU_PERPLLCON1   BRSHW_IOS(uint32, BRS_SCU_BASE + 0x2C)  /* PERPLLCON1 Peripheral PLL Configuration 1 Register */
#define BRS_SCU_PERPLLSTAT   BRSHW_IOS(uint32, BRS_SCU_BASE + 0x24)  /* PERPLLSTAT Peripheral PLL Status Register */

#define BRS_RSTSTAT          BRSHW_IOS(uint32, BRS_SCU_BASE + 0x50)  /* Reset Status Register */ 
#define BRS_SWRSTCON         BRSHW_IOS(uint32, BRS_SCU_BASE + 0x60)  /*Software Reset Configuration Register */

#define BRS_SCU_TRAPCLR      BRSHW_IOS(uint32, BRS_SCU_BASE + 0x12C) /* Trap Clear Register */
#define BRS_SCU_TRAPDIS0     BRSHW_IOS(uint32, BRS_SCU_BASE + 0x130) /* Trap Disable Register 0 */
#define BRS_SCU_TRAPDIS1     BRSHW_IOS(uint32, BRS_SCU_BASE + 0x120) /* Trap Disable Register 1 */

/*******************************************************************************
  GENERAL PURPOSE TIMER CLOCK CONTROL REGISTER
*******************************************************************************/
#define BRS_GPT120_BASE  0xF0001800
#define BRS_GPT120_CLC       BRSHW_IOS(uint32, BRS_GPT120_BASE)
#endif /*BRS_PLL_GROUP_X*/

/*******************************************************************************
  INTERRUPT  GROUP  CONFIG
*******************************************************************************/
#define BRS_INTERRUPT_IR_BASE  0xF0037000                        /* Interrupt base Adresse */
#define BRS_INT_SRC_BASE        (BRS_INTERRUPT_IR_BASE + 0x1000)  /* Interrupt base source adresse */

/* Defining some interrupt masks */
#define BRS_INT_SRC_SRE_MASK    0x00000400
#define BRS_INT_SRC_SETR_MASK   0x04000000

#define BRS_INT_SRC(x)          BRSHW_IOS(uint32, BRS_INT_SRC_BASE + x) /* Interrupt Router SRC Registers */

#if defined (BRS_ENABLE_FBL_SUPPORT)
/*******************************************************************************
  FLASH  GROUP  CONFIG
*******************************************************************************/

#define BRS_CPUSFR_BASE  0xF8800000u
#define BRS_DMU_BASE     0xF8040000u

#define BRS_CPU0_OFFSET_FLASHCON0  0x00000000u
#define BRS_CPU1_OFFSET_FLASHCON0  0x00020000u
#define BRS_CPU2_OFFSET_FLASHCON0  0x00040000u
#define BRS_CPU3_OFFSET_FLASHCON0  0x00060000u
#define BRS_CPU4_OFFSET_FLASHCON0  0x00080000u
#define BRS_CPU5_OFFSET_FLASHCON0  0x000C0000u

/* CPU Flash Configuration registers */ /** CPU x flash configuration register y, CPU protected */
#define BRS_CPU_FLASHCON(x, y)    BRSHW_IOS(uint32, BRS_CPUSFR_BASE + 0x1100u + BRS_CPU##x##_OFFSET_FLASHCON0 + ((y) * 0x04u))

#define BRS_DMU_ECCC(x)           BRSHW_IOS(uint32, BRS_DMU_BASE + 0x48u + ((x) * 0x200000u))  /**< DF x ECC control register, safety/cpu protected */

#define BRS_FLASHCON1_MASKUECC  0x00010000u  /* MASKUECC bit in FLASHCON1 registers */
#define BRS_DMU_ECCC_TRAPDIS    0xC0000000u  /* TRAPDIS bit in ECCC registers - disable ECC traps */

#endif /*BRS_ENABLE_FBL_SUPPORT*/

/**********************************************************************************************************************
 *  LOCAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONST VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  PROTOTYPES OF GLOBAL FUNCTIONS
 *********************************************************************************************************************/
extern void BrsMain_SoftwareResetECU_Hook(void);

/**********************************************************************************************************************
 *  PROTOTYPES OF LOCAL FUNCTIONS
 *********************************************************************************************************************/
#if defined (BRS_ENABLE_CAN_SUPPORT)      || \
    defined (BRS_ENABLE_LIN_SUPPORT)      || \
    defined (BRS_ENABLE_FLEXRAY_SUPPORT)  || \
    defined (BRS_ENABLE_ETHERNET_SUPPORT)
void Appl_UnlockInit(void);
void Appl_UnlockEndinit(void);
void Appl_LockInit(void);
void Appl_LockEndinit(void);
#endif

#if defined (BRS_ENABLE_CAN_SUPPORT)
void ApplCanWaitSetMCR(void);
#endif

#if defined (BRS_ENABLE_FLEXRAY_SUPPORT)
Std_ReturnType BrsHwErayPllInitPowerOn(void);
Std_ReturnType BrsHwErayPllWaitVcoLock(void);
#endif

/**********************************************************************************************************************
 *  FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#if defined (BRS_ENABLE_WATCHDOG)
/*****************************************************************************/
/* @brief      This function must be used to initialize the Watchdog.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 *****************************************************************************/
void BrsHwWatchdogInitPowerOn(void)
{
  BrsHwUnlockInitInline(BrsHw_GetCore());
  BRS_SFR_WDTCPU0CON1 |= 0x8;
  BrsHwLockInitInline(BrsHw_GetCore());
  
  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  BRS_SFR_WDTSCON1 |= 0x8;
  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
}
#endif /*BRS_ENABLE_WATCHDOG*/

#if defined (BRS_ENABLE_PLLCLOCKS)
/*****************************************************************************/
/**
 * @brief      This function must be used to initialize the PLL.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 */
/*****************************************************************************/
void BrsPllInit(void)
{
# if (BRS_TIMEBASE_CLOCK > BRS_CPU_MAX_FREQUENCY)
  #error "The selected derivative does not support frequencies above BRS_CPU_MAX_FREQUENCY (please find the defined value inside vBrsCfg.h)."
# endif

#if defined (BRS_PLL_GROUP_A)
  uint32 pllfreq;
  /*CPU DIVIDER VALUES*/
  uint32 cpu0div, cpu1div, cpu2div;
  /*PERIPHERAL DIVIDER VALUES*/
  uint32 stmdivider, spbdivider, candivider, linfdivider, linsdivider, baud1divider, baud2divider, sridivider, gtmdivider, ethdivider, eraydivider;

  /* fvco has to be in the range 400...800MHZ */
  /* fpll = fosc*(N_DIVIDER/(P_DIVIDER*K2_DIVIDER)) */

  /*Divider values for fpll and fpllERAY*/
  #define P_DIVIDER 0x1  /*P_DIVIDER = 2*/
  #define K2_DIVIDER 0x3 /*K2_DIVIDER = 4*/

  /*fpll = 200MHZ fix*/
# if (BRS_OSC_CLK == 40)
  #define N_DIVIDER 0x27 /*N_DIVIDER = 40*/
# elif (BRS_OSC_CLK == 20)
  #define N_DIVIDER 0x4F /*N_DIVIDER = 80*/
# elif (BRS_OSC_CLK == 16)
  #define N_DIVIDER 0x63/*N_DIVIDER = 100*/

# else
  #error "Actual BRS implementation supports oscillator frequencies of 40, 20 and 16 MHz only"
# endif /*BRS_OSC_CLK*/

  /*check vco range*/
# if( (BRS_OSC_CLK*(N_DIVIDER+0x1))/(P_DIVIDER+0x1) < 400 || (BRS_OSC_CLK*(N_DIVIDER+0x1))/(P_DIVIDER+0x1) > 800)
  #error "fvco must be greater than 400MHZ and less than 800MHZ."
# endif

# if defined (BRS_DERIVATIVE_TC29x) /* Errata:PLL_TC.005 */
  #define nop10() nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  uint32 errataPllStableDelay = 0;
  BRS_SCU_CCUCON0 &= ~0x30000000; /* switch system clock to back-up clock - should be used as default anyway */
  BRS_SCU_CCUCON0 |=  0x30000000; /* request update */
  BRS_SCU_PLLCON0 &= ~0x00010000; /* set PLL to power saving mode */

  /* Wait 10us:
     - Back-up clock should be 100 MHz: 1us = 1.000 nops -> 10us = 10.000 nops */
  for(errataPllStableDelay = 0; errataPllStableDelay < 1000; errataPllStableDelay++)
    nop10();
  BRS_SCU_PLLCON0 |=  0x00010000; /* set PLL to power saving mode */
# endif /*BRS_DERIVATIVE_TC29x*/

  pllfreq= BRS_OSC_CLK *(N_DIVIDER+0x1)/((K2_DIVIDER+0x1)*(P_DIVIDER+0x1)); /*pllfreq = 200MHZ*/

# if (BRS_TIMEBASE_CLOCK == 50 || BRS_TIMEBASE_CLOCK == 75 || BRS_TIMEBASE_CLOCK == 100 || BRS_TIMEBASE_CLOCK == 125 || BRS_TIMEBASE_CLOCK == 150 || BRS_TIMEBASE_CLOCK == 175 || BRS_TIMEBASE_CLOCK == 200)
  cpu0div = 64 - ((BRS_TIMEBASE_CLOCK*64)/pllfreq);
  cpu1div = 64 - ((BRS_TIMEBASE_CLOCK*64)/pllfreq);
  cpu2div = 64 - ((BRS_TIMEBASE_CLOCK*64)/pllfreq);
# else
  #error "The selected CPU frequency is not yet supported (please choose 25, 50, 75, 100, 125, 150, 175 or 200MHZ)."
# endif

  /*Set peripheral, system timer and SPB bus clock divider values*/
  stmdivider = pllfreq/25;   /*stmdivider for fstm = 25MHZ;*/
  spbdivider = pllfreq/50;   /*spbdivider for fspb = 50MHZ*/
  candivider = pllfreq/25;   /*candivider for fcan = 25MHZ*/
  linfdivider = pllfreq/25;  /*linfdivider for flinf = 25MHZ*/
  linsdivider = pllfreq/25;  /*linsdivider for flins = 25MHZ*/
  baud1divider = pllfreq/25; /*baud1divider for fbaud1 = 25MHZ*/
  baud2divider = pllfreq/25; /*baud2divider for fbaud2 = 25MHZ*/
  sridivider = 0x1;          /*sridivider for fsri = BRS_TIMEBASE_CLOCK*/
  gtmdivider = pllfreq/25;   /*gtmdivider for fgtm = 25MHZ*/

# if defined (BRS_ENABLE_FLEXRAY_SUPPORT)
  eraydivider = 0x1;         /*eraydivider for feray = 80MHZ*/
# else
  eraydivider = 0x0;         /* no ERAYPLL */
# endif

# if defined (BRS_ENABLE_ETHERNET_SUPPORT)
  ethdivider = 0x1;
# else
  ethdivider = 0x0;
# endif

  /*Configuration of PLL and PLLERAY starts here*/
  BrsHwUnlockInitInline(BrsHw_GetCore());
  BRS_GPT120_CLC = 0x0;
  BRS_SCU_TRAPDIS |= 0x3E0; /* Traps can not be generated for PLLs and Clocksystem */
  BrsHwLockInitInline(BrsHw_GetCore());

  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  /*Frist: Select prescaler mode*/
  /*Prescaler mode for pll*/
  BRS_SCU_PLLCON0 = BRS_SCU_PLLCON0
                  | (0x1 << 0)  /*VCOBYP=1    ---> Prescaler mode*/
                  | (0x1 << 4); /*SETFINDIS=1 ---> oscillator clock disconnect to PLL*/

  while((BRS_SCU_CCUCON1 & 0x80000000) == 0x80000000); /* wait until the lock of CCUCON1 is not set */
  BRS_SCU_CCUCON1 = (BRS_SCU_CCUCON1 & 0x0FFFFFFF)
                  | (0x1 << 28); /* pll and pll_ERAY clock source = fosc0 (fxtal1) */

  /* Write CCUCON1 with all values */ 
  while((BRS_SCU_CCUCON1 & 0x80000000) == 0x80000000); /* wait until the lock of CCUCON1 is not set */
  BRS_SCU_CCUCON1 =  (BRS_SCU_CCUCON1 & 0x30000000)
                  |  (candivider  << 0)   /*fcan = fpll/candivider*/
                  |  (eraydivider << 4)   /*fERAY = fplleray/eraydivider*/
                  |  (stmdivider  << 8)   /*fstm = fpll/stmdivider*/ /*fstm = system timer clock*/
                  |  (gtmdivider  << 12)  /*fgtm = fpll/gtmdivider*/
                  |  (ethdivider  << 16)  /*feth*/
                  |  (linfdivider << 20)  /*fasclinf = fpll/linfdivider*/
                  |  (linsdivider << 24); /*fasclins = fpll/linsdivider*/

  /*Write CCUCON0 with all values*/
  while((BRS_SCU_CCUCON0 & 0x80000000) == 0x80000000); /* wait until the lock of CCUCON0 is not set */
  BRS_SCU_CCUCON0 = (BRS_SCU_CCUCON0 & 0x0FFFFFFF)
                  | (0x1 << 28); /* Choose fpll as clock source, fpll=fsource */

  while((BRS_SCU_CCUCON0 & 0x80000000) == 0x80000000); /* wait until the lock of CCUCON0 is not set */
  BRS_SCU_CCUCON0 = (BRS_SCU_CCUCON0 & 0x30000000)
                  | (baud1divider << 0)   /*fbaud1 = fpll/baud1divider*/ /*Not available for TC22X and TC23X*/
                  | (baud2divider << 4)   /*fbaud2 = fpll/baud2divider*/
                  | (sridivider   << 8)   /*fsri = fpll/sridivider*/
                  | (spbdivider   << 16)  /*fspb = fpll/spbdivider*/ /*fspb = general purpose timer clock*/
                  | (0x2          << 20)  /*ffsi2= fsri/2*/
                  | (0x2          << 24)  /*ffsi =fsri/2*/
                  | (0x1          << 30); /*update CCUCON0, CCUCON1*/

  while((BRS_SCU_CCUCON5 & 0x80000000) == 0x80000000); /* wait until the lock of CCUCON5 is not set */
  BRS_SCU_CCUCON5 = (0x40000040); /* fmax = fsource and update CCUCON5 */

  BRS_SCU_CCUCON6 = cpu0div; /*fcpu0 = fsri*/
  BRS_SCU_CCUCON7 = cpu1div; /*fcpu1 = fsri*/
  BRS_SCU_CCUCON8 = cpu2div; /*fcpu2 = fsri*/

# if (BRS_OSC_CLK == 40)
  BRS_SCU_OSCCON = 0x00000000   /*clear reg.*/
                 | (0x2 << 3)   /*gain control from 4MHZ to 20MHZ*/
                 | (0xF << 16); /*crystalfreq(40MHZ) / 15+1 = 2,5MHZ ---> OSCVAL = 40MHZ/2.5MHZ*/

# elif (BRS_OSC_CLK == 20)
  BRS_SCU_OSCCON = 0x00000000   /*clear reg.*/
                 | (0x2 << 3)   /*gain control from 4MHZ to 20MHZ*/
                 | (0x7 << 16); /*crystalfreq(20MHZ) / 7+1 = 2,5MHZ ---> OSCVAL = 20MHZ/2.5MHZ*/

# elif (BRS_OSC_CLK == 16)
  BRS_SCU_OSCCON = 0x00000000   /*clear reg.*/
                 | (0x2 << 3)   /*gain control from 4MHZ to 20MHZ*/
                 | (0x5 << 16); /*crystalfreq(16MHZ) / 5+1 = 2,67MHZ ---> OSCVAL = 16MHZ/2.5MHZ*/
# endif /*BRS_OSC_CLK*/

  /* Set n and p dividers for pll */
  BRS_SCU_PLLCON0 = (BRS_SCU_PLLCON0 & 0xF0FF01FF)
                  | (N_DIVIDER << 9)    /* Set N-Divider */
                  | (P_DIVIDER  << 24); /* Set P-Divider */

  /* Set k2 divider for pll */
  BRS_SCU_PLLCON1  = (BRS_SCU_PLLCON1 & 0xFFFFFFC0)
                   | K2_DIVIDER; /* K2-Divider */

  while((BRS_SCU_PLLSTAT & 0x00000020) != 0x00000020); /* K2RDY == 1 ? */

  BRS_SCU_PLLCON0 |= 0x00000040; /* In case of a PLL loss-of-lock bit PLLSTAT.FINDIS is cleared */

  while((BRS_SCU_OSCCON & 0x00000102) != 0x00000102); /* check if the OSC frequency is usable */

  /* Second: Select normal mode for pll and for pllERAY */
  BRS_SCU_PLLCON0 |= 0x00000020; /* CLRFINDIS=1 ---> oscillator clock is connected to pll */
  BRS_SCU_PLLCON0 |= 0x00040000; /* RESLD = 1   ---> restart lock detection */
  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  /* wait for lock */
  while((BRS_SCU_PLLSTAT & 0x00000004) != 0x00000004); /* VCOLOCK == 1 ?*/

  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  BRS_SCU_PLLCON0 &= 0xFFFFFFFE; /* VCOBYP=0 ---> select normal mode */

# if defined (BRS_ENABLE_FLEXRAY_SUPPORT)
  /*Configuration of PLLERAY starts here*/
  BrsHwErayPllInitPowerOn();
# endif

  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  /* clear only pending traps related to PLLs and Clocksystem */
  BRS_SCU_TRAPCLR = 0x3E0;
  BrsHwUnlockInitInline(BrsHw_GetCore());

  /*enable all Traps again*/
  BRS_SCU_TRAPDIS = BRS_SCU_TRAPDIS & ~0x3E0;
  BrsHwLockInitInline(BrsHw_GetCore());
#endif /*BRS_PLL_GROUP_A*/

#if defined (BRS_PLL_GROUP_B) || defined (BRS_PLL_GROUP_C)
  uint32 ulIdx;

# if (BRS_OSC_CLK==20) || (BRS_OSC_CLK==25) || (BRS_OSC_CLK==40)
# else
  #error "Actual BRS implementation supports oscillator frequency of 20,25MHz and 40MHz"
# endif /*BRS_OSC_CLK*/

  /* actual peripheral frequencies for OSC = 20MHz or [25MHz]
  System PLL DCO: 600 MHz  [600 MHz]
  fPLL0:          300 MHz  [300 MHz]
  fPLL1:          320 MHz  [160 MHz]
  fPLL2:          200 MHz  [200 MHz]
  FSI_clock:      100 MHz  [100 MHz]
  FSI2_clock:     300 MHz  [300 MHz]
  GTM_clock:      200 MHz  [200 MHz]
  STM_clock:      100 MHz  [100 MHz]
  SRI_clock:      300 MHz  [300 MHz]
  SPB_clock:      100 MHz  [100 MHz](System Peripheral Bus)
  GPT12_clock:    100 MHz  [100 MHz]
  BBB_clock:      150 MHz  [150 MHz]
  REFCLK1:       12.5 MHz [12.5 MHz]
  HSCT_clock:     320 MHz [not USED]
  EBU_clock:      160 MHz  [160 MHz]
  QSPI_clock:     200 MHz  [200 MHz]
  ADC_clock:      160 MHz  [160 MHz]
  I2C_clock:     66.6 MHz [66.6 MHz]
  MCAN_clock:      80 MHz   [80 MHz]
  ERAY_clock:      80 MHz   [80 MHz]
  ASCLINF_clock:  200 MHz  [200 MHz]
  ASCLINS_clock:   80 MHz   [80 MHz]
  MSC_clock:      200 MHz  [200 MHz]  
  */

  /*Configuration of PLL starts here*/
  BrsHwUnlockInitInline(BrsHw_GetCore());
  BRS_GPT120_CLC = 0x0;
  BRS_SCU_TRAPDIS0 |= 0x0F0F0F0F; /* Traps can not be generated for PLLs and Clocksystem */
  BRS_SCU_TRAPDIS1 |= 0x0F0F;
  BrsHwLockInitInline(BrsHw_GetCore());

  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  /* *** Step 1: setup osc control *** */

# if (BRS_OSC_CLK==20)
  #define OSCVAL 3  /*fOSCREF = 20 MHz = OSCCON.OSCVAL + 1 + 16 MHz -> OSCVAL = 3 */
# elif (BRS_OSC_CLK==25)
  #define OSCVAL 8  /*fOSCREF = 25 MHz = OSCCON.OSCVAL + 1 + 16 MHz -> OSCVAL = 8 */
# elif (BRS_OSC_CLK==40)
  #define OSCVAL 23 /*fOSCREF = 40 MHz = OSCCON.OSCVAL + 1 + 16 MHz -> OSCVAL = 23 */
# endif

  BRS_SCU_OSCCON = 0x00000000      /* mode = 0 -> External Crystal Mode. The oscillator Power-Saving Mode is not entered. */
                 | (0x3 << 3)      /* gain control */
                 | (OSCVAL << 16); /* fOSCREF = OSCCON.OSCVAL + 1 + 16 MHz */

  BRS_SCU_OSCCON |= (0x1 << 2);    /* OSCRES -> reset OSC watchdog with new settings */
  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  while((BRS_SCU_OSCCON & 0x00000102) != 0x00000102); /* wait until PLLLV and PLLHV are set */

  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  /* *** Step 2: Initialize the PLLs to target fDCO and fPLLx frequency *** */
  /* set SYSPLLCON0.INSEL = 0x01 -> fOSC is used as clock source */
  BRS_SCU_SYSPLLCON0 &= ~(0x3 << 30);
  BRS_SCU_SYSPLLCON0 |= (0x1 << 30);

# if (BRS_OSC_CLK==20)
  #define PllNdiv 0x1D   /* NDIV = 0x1D = 29 */
# elif (BRS_OSC_CLK==25)
  #define PllNdiv 0x17   /* NDIV = 0x17 = 23 */
# elif (BRS_OSC_CLK==40)
  #define PllNdiv 0xE   /* NDIV = 0xE = 14 */
# endif  

  /* fDCO = ((NDIV+1)* fOSC) */
  /* fPll= fDCO /((PDIV+1)*(K2DIV+1)) */
  
  /* SysPll fDCO = 600MHz, fPLL0 = 100MHz */
  BRS_SCU_SYSPLLCON0 = 0x00000000  /* PDIV = 0, PLLPWD = 0, MODEN = 0 */
                     | (0x1 << 30) /* fOSC used as clock source*/
                     | (0x1 << 16) /* System PLL power saving mode set to normal behavior */
                     | (PllNdiv << 9); /*Ndiv depening on fOSC*/
                     
  /* K2DIV = 5 -> K2 divider = 6 */
  BRS_SCU_SYSPLLCON1 = 0x00000005;

# if (BRS_OSC_CLK==20)
  #define PerPllNdiv 0x1F /* NDIV = 0x1F = 31 */
  #define DIVBY 0         /* DIVBY = 0  */
# elif (BRS_OSC_CLK==25)
  #define PerPllNdiv 0x1F /* NDIV = 0x1F = 31 */
  #define DIVBY 1         /* DIVBY = 1  */
# elif (BRS_OSC_CLK==40)
  #define PerPllNdiv 0xF /* NDIV = 0xF = 16 */
  #define DIVBY 1        /* DIVBY = 1  */
# endif
  
  /* PerPll fDCO = 640MHz; fPLL1 = 320MHz; f PLL2 = 200MHz */
  /* NDIV = 0x1F = 31, PDIV = 0, PLLPWD = 0, MODEN = 0, DIVBY = 0 */
  BRS_SCU_PERPLLCON0 =  0x00000000 /* PDIV = 0, PLLPWD = 0, MODEN = 0 */
                     | (0x1 << 16) /* System PLL power saving mode set to normal behavior */
                     | (PerPllNdiv << 9)
                     | (DIVBY << 0); /* DIVBY depends on fOSC*/

  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  for (ulIdx=0; ulIdx < 10000; ulIdx++) nop(); /* yes this needs so much time!!!; geth: reduced wait time by factor of 100 (1M to 10K)*/

  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

# if (BRS_OSC_CLK==20)
  #define K3div 0x1     /* K3DIV = 1 -> K3 divider = 2 */
  #define K2div 0x1     /* K2DIV = 1 --> K2 divider 2 */
# elif (BRS_OSC_CLK==25)
  #define K3div 0x1     /* K3DIV = 1 -> K3 divider = 2 */
  #define K2div 0x4     /* K2DIV = 4 --> K2 divider 5 */
# elif (BRS_OSC_CLK==40)
  #define K3div 0x1     /* K3DIV = 1 -> K3 divider = 2 */
  #define K2div 0x1     /* K2DIV = 1 --> K2 divider 2 */
# endif

  BRS_SCU_PERPLLCON1 = 0x00000000
                     | (K3div << 8)  /* K3DIV */
                     | (K2div << 0); /* K2DIV */

  /* *** Step 3: Wait for PLL lock to be set *** */
  /* Restart DCO lock detection */
  BRS_SCU_SYSPLLCON0 |= 0x00040000;

  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  /* Wait for PLL lock */
  while((BRS_SCU_SYSPLLSTAT & 0x4) == 0);

  /* *** Step 4: Configure CCUCON0, and CCUCON1 to first target setting *** */
  while((BRS_SCU_CCUCON0 & 0x80000000) != 0); /* Wait for CCUCON0 unlocked */

  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  BRS_SCU_CCUCON0 = 0x47230113;
  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  while((BRS_SCU_CCUCON0 & 0x80000000) != 0); /* Wait until change is executed */
  while((BRS_SCU_CCUCON1 & 0x80000000) != 0); /* Wait for CCUCON1 unlocked */

  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

# if (BRS_OSC_CLK==20)
  BRS_SCU_CCUCON1 = 0x21210012;
# elif (BRS_OSC_CLK==25)
  BRS_SCU_CCUCON1 = 0x21210092;
# elif (BRS_OSC_CLK==40)
  BRS_SCU_CCUCON1 = 0x21210012; /*divider disabled for fpll1 fpll1= fsource1, fMCAN=fsource1/2*/
# endif

  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  while((BRS_SCU_CCUCON1 & 0x80000000) != 0); /* Wait until change is executed */
  while((BRS_SCU_CCUCON2 & 0x80000000) != 0); /* Wait for CCUCON2 unlocked */

  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  BRS_SCU_CCUCON2 = 0x02001201; /*additional set ERAYPERON*/
  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  while((BRS_SCU_CCUCON2 & 0x80000000) != 0); /* Wait until change is executed */

  /* *** Step 5: Switch CCU input clock fSOURCE0 to PLL via CCUCON0.CLKSEL *** */
  while((BRS_SCU_CCUCON0 & 0x80000000) != 0); /* Wait for CCUCON0 unlocked */

  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  BRS_SCU_CCUCON0 = 0x57230113;
  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  while((BRS_SCU_CCUCON0 & 0x80000000) != 0); /* Wait until change is executed */

  /* *** Step 6: fPLL has to be increased step by step to target frequency *** */
  /* K2DIV = 3 -> K2 divider = 4 */
  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  BRS_SCU_SYSPLLCON1 = 0x00000003;
  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  BRS_SCU_SYSPLLCON1 = 0x00000002;
  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  BRS_SCU_SYSPLLCON1 = 0x00000001;
  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

# if !defined (BRS_PLL_GROUP_C)
  while((BRS_SCU_CCUCON5 & 0x80000000) != 0); /* Wait for CCUCON5 unlocked - additionally added (GETH)*/

  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  BRS_SCU_CCUCON5 = (BRS_SCU_CCUCON5 | 0x01);
  BRS_SCU_CCUCON5 = (BRS_SCU_CCUCON5 | 0x01 << 30u);
  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
# endif /*!BRS_PLL_GROUP_C*/

  BrsHwUnlockInitInline(BrsHw_GetCore());
  /* clear only pending traps related to PLLs and Clocksystem */
  BRS_SCU_TRAPCLR = 0xF;

  /* enable all Traps again - except for ESR1T for all cores*/
  /* The ESR1 Pin on 2nd Gen TC3xx Triboards is pulled to high level via pull-up resistor which triggers an non-maskable Interrupt*/
  BRS_SCU_TRAPDIS0 = 0xF2F2F2F2;
  BRS_SCU_TRAPDIS1 = 0xF2F2;

  BrsHwLockInitInline(BrsHw_GetCore());
#endif /*BRS_PLL_GROUP_B||BRS_PLL_GROUP_C*/
}

# if defined (BRS_PLL_GROUP_A)
#  if defined (BRS_ENABLE_FLEXRAY_SUPPORT)
/* function to initialize ERAY PLL */
Std_ReturnType BrsHwErayPllInitPowerOn(void)
{
  Std_ReturnType ErrorFlag;
  volatile uint32 PllStableDelay;
  uint8 PllNdiv;
  uint8 PllK2div;
  uint8 PllK3div;
  uint8 PllPdiv;

  /*Store PLL Divider values in local variables*/
# if (BRS_OSC_CLK == 40)
  PllNdiv = 0x7; /* 8 - 1*/
  PllK2div = 0x3; /* 4 - 1*/
  PllK3div = 0x3; /* 4 - 1*/
  PllPdiv =  0x0; /* 1 - 1*/

# elif (BRS_OSC_CLK == 20)
  PllNdiv = 0xF; /* 16 - 1*/
  PllK2div = 0x3; /* 4 - 1*/
  PllK3div = 0x3; /* 4 - 1*/
  PllPdiv =  0x0; /* 1 - 1*/

# elif (BRS_OSC_CLK == 16)
  PllNdiv = 0x13; /* 20 - 1*/
  PllK2div = 0x3; /* 4 - 1*/
  PllK3div = 0x3; /* 4 - 1*/
  PllPdiv =  0x0; /* 1 - 1*/
# endif /*BRS_OSC_CLK*/

  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  /* Enter Prescalar mode */
  /* Update K and N dividers */
  BRS_SCU_PLLERAYCON1 = (BRS_SCU_PLLERAYCON1 & 0xFF80FFFF); /* Clear K1DIV. K1DIV = 1 */

  BRS_SCU_PLLERAYCON0 = (BRS_SCU_PLLERAYCON0 & 0xFFFFFFEE)
                      | (0x1 << 0)    /* VCOBYP = 1 */
                      | (0x1 << 4);   /* SETFINDIS = 1 */

  BRS_SCU_PLLERAYCON1 = (BRS_SCU_PLLERAYCON1 & 0xFFFFF080)
                      | (PllK2div << 0)   /* K2DIV */
                      | (PllK3div << 8);  /* K3DIV */

  BRS_SCU_PLLERAYCON0 = (BRS_SCU_PLLERAYCON0 & 0xF0FFC1FF)
                      | (PllNdiv << 9)     /* NDIV */
                      | (PllPdiv << 24);   /* PDIV */

  /* Enter normal mode */
  BRS_SCU_PLLERAYCON0 = (BRS_SCU_PLLERAYCON0 & 0xFFFEFF9F)
                      | (0x1 << 5)     /* CLRFINDIS=1 */
                      | (0x1 << 6)     /* OSCDISCDIS=1 */
                      | (0x0 << 16);   /* PLLPWD=0 */

  /*
    RESLD = 1     ==> Restart VCO lock detection
    CLRFINDIS = 1 ==> Connect OSC to PLL
    PLLPWD = 1    ==> PLL Power Saving Mode : Normal behaviour
    NDIV = FR_17_ERAY_PLL_NDIV (Pre-compile parameter)
  */

  BRS_SCU_PLLERAYCON0 = (BRS_SCU_PLLERAYCON0 & 0xFFFEFFFF)
                      | (0x1 << 16);   /*PLLPWD = 1*/

  for(PllStableDelay=0U;PllStableDelay < 100 ;PllStableDelay++)
  {}/*Errata*/

  BRS_SCU_PLLERAYCON0 = (BRS_SCU_PLLERAYCON0 & 0xFFFBFFFF)
              | (0x1 << 18);   /* RESLD = 1 */

  /* Set the ENDINIT bit in the WDT_CON0 register again
  to enable the write-protection and to prevent a time-out */
  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

  /* Wait for ERAY PLL VCO locking */
  ErrorFlag = BrsHwErayPllWaitVcoLock();

  /*By Pass VCO only if PLL is locked*/
  if(ErrorFlag == E_OK)
  {
    /* Clear the ENDINIT bit in the WDT_CON0 register in order
    to disable the write-protection for registers protected
    via the EndInit feature */
    BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

    /*Bypass VCO*/
    /* Distribute the clock */
    BRS_SCU_PLLERAYCON0 = (BRS_SCU_PLLERAYCON0 & 0xFFFFFFBE)
                        | (0x0 << 0)     /*VCOBYP = 0*/
                        | (0x0 << 6);    /*OSCDISCDIS = 0*/

    /* Set the ENDINIT bit in the WDT_CON0 register again
    to enable the write-protection and to prevent a time-out */
    BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  }
  return(ErrorFlag);
}

Std_ReturnType BrsHwErayPllWaitVcoLock(void)
{
  Std_ReturnType ErrorFlag;
  uint32 TimeOutCount;

  ErrorFlag = E_OK;
  TimeOutCount = ((uint32)0x000001FFU);
  do
  {
    TimeOutCount-- ;
  } while (((BRS_SCU_PLLERAYSTAT & 0x00000004) != 0x00000004) && (TimeOutCount > 0U)) ;

  if (TimeOutCount == 0U)
  {
    ErrorFlag = E_NOT_OK;
  }

  return(ErrorFlag);
}
#  endif /*BRS_ENABLE_FLEXRAY_SUPPORT*/
# endif /*BRS_PLL_GROUP_A*/
#endif /*BRS_ENABLE_PLLCLOCKS*/

/*****************************************************************************/
/* @brief      Disable the global system interrupt.
 * @pre        Must be the first function call in main@BrsMain
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main@BrsMain at power on initialization
 *****************************************************************************/
void BrsHwDisableInterruptAtPowerOn(void)
{
#if defined (BRS_COMP_TASKING) 
  __disable();
#endif /*BRS_COMP_x*/
}

/*****************************************************************************/
/* @brief      Restart ECU (issue a software reset or jump to startup code)
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from e.g. ECU state handling
 *****************************************************************************/
void BrsHwSoftwareResetECU(void)
{
  BrsMain_SoftwareResetECU_Hook();

#if !defined (BRS_ENABLE_FBL_SUPPORT) /* FBL is always running in polling mode with interrupts disabled */
  DisableAllInterrupts();
#endif

#if defined (BRS_RESET_GROUP_A)
  BrsHwUnlockInitInline(BRS_SAFETY_WATCHDOG_INDEX);
  BRS_SWRSTCON |= 0x00000002;
  BrsHwLockInitInline(BRS_SAFETY_WATCHDOG_INDEX);

#elif defined (BRS_RESET_GROUP_B)
  BrsHwUnlockInitInline(BrsHw_GetCore());
  BRS_SWRSTCON |= 0x00000002;
  BrsHwLockInitInline(BrsHw_GetCore());
#endif

  while (1)
  {
    /* Wait until reset/watchdog reset occurs */
  }
}

/*****************************************************************************/
/* @brief      Get reset reason
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     Reset reason
 * @context    Function is called from BrsMainStartup to determine if reset
 *             was triggered through software call (BrsHwSoftwareResetECU()).
 *****************************************************************************/
brsHw_ResetReasonType BrsHwGetResetReason(void)
{
  if((BRS_RSTSTAT & 0x10) == 0x10)
  {
    return BRSHW_RESET_SW;
  }
  else
  {
    return BRSHW_RESET_OTHER;
  }
}

/*****************************************************************************/
/* @brief      This API is used for the BRS time measurement support to get a
 *             default time value for all measurements with this platform to
 *             be able to compare time measurements on different dates based
 *             on this time result.
 * @pre        Should be called with interrupts global disabled
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from e.g. component testsuits for calibration
 *****************************************************************************/
void BrsHwTime100NOP(void)
{
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();

  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
  nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop(); nop();
}

/*****************************************************************************/
/* @brief      This API is used to read the core ID of the actual running core
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     Core ID of the actual running core
 * @context    Function is e.g. called from main@BrsMain, to only call HW-init
 *             code once, on the boot core.
 *             In MultiCore setups, additional BRSHW_INIT_CORE_ID must be
 *             declared inside BrsHw.h, to configure the proper core ID value
 *             of that boot core.
 *****************************************************************************/
uint32 BrsHw_GetCore(void)
{
  return BRS_MOVE_FROM_CSFR(BRS_CORE_ID_REGISTER);
}

/*****************************************************************************/
/* @brief      This API is used to enable an interrupt source in the core
 *             interrupt controller.
 * @pre        -
 * @param[in]  Source to be enabled.
 * @param[in]  Priority level to be set.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_EnableInterrupt(uint32 Source, uint8 Priority)
{
  /* #10 Enable the given interrupt source in its SRC register. */
  BRS_INT_SRC(Source) |= BRS_INT_SRC_SRE_MASK;
  BRS_INT_SRC(Source) |= Priority;
}

/*****************************************************************************/
/* @brief      This API is used to disable an interrupt source in the core
 *             interrupt controller.
 * @pre        -
 * @param[in]  Source to be disabled.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_DisableInterrupt(uint32 Source)
{
  /* #10 Disable the given interrupt source in its SRC register. */
  BRS_INT_SRC(Source) &= ~BRS_INT_SRC_SRE_MASK;
}

/*****************************************************************************/
/* @brief      This API is used to trigger the given software interrupt source.
 * @pre        -
 * @param[in]  Source to be triggered.
 *             Some derivatives only support few software triggerable sources,
 *             check for their validity.
 * @param[out] -
 * @return     -
 * @context    Function is called from HlpTest and other test environments.
 *****************************************************************************/
void BrsHw_TriggerSoftwareInterrupt(uint32 Source)
{
  BRS_INT_SRC(Source) |= BRS_INT_SRC_SETR_MASK;
}

#if defined (BRS_ENABLE_FBL_SUPPORT)
/*****************************************************************************/
/* @brief      This API is used to disable the flash ECC error reporting,
 *             if this is necessary on the platform to grant access to it.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from FBL boot code, before flash is accessed.
 *****************************************************************************/
void BrsHwDisableEccErrorReporting(void)
{
  /* Disable uncorrectable bit error traps */
  BrsHwUnlockInitInline(BrsHw_GetCore());

  /* Mask PFLASH uncorrectable ECC bit error */
  BRS_CPU_FLASHCON(0, 1u) = BRS_FLASHCON1_MASKUECC;       /* CPU0_FLASHCON1 MASKUECC=1 (ECC error disabled) */
#if (BRS_CPU_CORE_AMOUNT > 1)
  BRS_CPU_FLASHCON(1, 1u) = BRS_FLASHCON1_MASKUECC;       /* CPU1_FLASHCON1 MASKUECC=1 (ECC error disabled) */
#endif
#if (BRS_CPU_CORE_AMOUNT > 2)
  BRS_CPU_FLASHCON(2, 1u) = BRS_FLASHCON1_MASKUECC;       /* CPU2_FLASHCON1 MASKUECC=1 (ECC error disabled) */
#endif
#if (BRS_CPU_CORE_AMOUNT > 3)
  BRS_CPU_FLASHCON(3, 1u) = BRS_FLASHCON1_MASKUECC;       /* CPU3_FLASHCON1 MASKUECC=1 (ECC error disabled) */
#endif
#if (BRS_CPU_CORE_AMOUNT > 5)
  BRS_CPU_FLASHCON(4, 1u) = BRS_FLASHCON1_MASKUECC;       /* CPU4_FLASHCON1 MASKUECC=1 (ECC error disabled) */
  BRS_CPU_FLASHCON(5, 1u) = BRS_FLASHCON1_MASKUECC;       /* CPU5_FLASHCON1 MASKUECC=1 (ECC error disabled) */
#endif

  /* For DF0 and DF1 (when DF1 is configured as not HSM_exclusive), the uncorrectable ECC error trap is disabled. */
  BRS_DMU_ECCC(0) = BRS_DMU_ECCC_TRAPDIS; /* DMU_HF_ECCC TRAPDIS = ECC error trap is disabled */
  /* If DF1 is configured as HSM_exclusive then the uncorrectable ECC error trap is disabled. */
  /* BRS_DMU_ECCC(1) = BRS_DMU_ECCC_TRAPDIS; */ /* DMU_SF_ECCC TRAPDIS = ECC error trap is disabled */

  BrsHwLockInitInline(BrsHw_GetCore());

}
#endif /*BRS_ENABLE_FBL_SUPPORT*/

/* DrvCan/DrvLin/DrvFr/DrvEth application callback functions for access protection of critical registers */
/* As different driver versions use different callback names, they are duplicated. */
#if defined (BRS_ENABLE_CAN_SUPPORT)      || \
    defined (BRS_ENABLE_LIN_SUPPORT)      || \
    defined (BRS_ENABLE_FLEXRAY_SUPPORT)  || \
    defined (BRS_ENABLE_ETHERNET_SUPPORT)
void Appl_UnlockInit(void)
{
  BrsHwUnlockInitInline(BrsHw_GetCore());
}

void Appl_UnlockEndinit(void)
{
  BrsHwUnlockInitInline(BrsHw_GetCore());
}

void Appl_LockInit(void)
{
  BrsHwLockInitInline(BrsHw_GetCore());
}

void Appl_LockEndinit(void)
{
  BrsHwLockInitInline(BrsHw_GetCore());
}
#endif /*BRS_ENABLE_CAN_SUPPORT || BRS_ENABLE_LIN_SUPPORT || BRS_ENABLE_FLEXRAY_SUPPORT || BRS_ENABLE_ETHERNET_SUPPORT*/

/* DrvCan Application function for wait mechanism */
#if defined (BRS_ENABLE_CAN_SUPPORT)
void ApplCanWaitSetMCR(void)
{
  uint32 i;
  for (i=0; i<10000; i++)
  {
    nop();
  }
}
#endif /*BRS_ENABLE_CAN_SUPPORT*/


#if defined (BRS_ENABLE_FLEXRAY_SUPPORT)
/*****************************************************************************/
/* @brief      Callback from communication stack. Init E-RAY RAM to avoid ECC errors
 * @pre        
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called Fr_InitMemory(). It is just an empty function
 *             because the RAM init is already done during startup.
 *****************************************************************************/
void Appl_TricoreAurixInit(void)
{
   /* Callback from communication stack. Init E-RAY RAM to avoid ECC errors
      -> Already done in startup! */
}
#endif /*BRS_ENABLE_FLEXRAY_SUPPORT*/


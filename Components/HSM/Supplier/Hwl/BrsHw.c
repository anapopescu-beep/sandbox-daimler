
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  BrsHw.c
      Project:  Vector Basic Runtime System
       Module:  BrsHw of HSM Core for platform Infineon Aurix/AurixPlus
     Template:  This file is reviewed according to Brs_Template@Implementation_HSM[1.00.00]

  \brief Description:  This is the hardware specific code file for Vector Basic Runtime System (BRS).

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
 ----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
  ----------------------------  ------------  -------------------------------------------------------------------------
  Sascha Mauser                 vismaa       Vector Informatik GmbH
  Lukas Rohrwild                virrlu       Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
  --------  ----------  ------  ---------------------------------------------------------------------------------------
  01.00.00  2020-05-18  vismaa  New branch for vBaseEnv 2.0, based on zBrs_Aurix_HSM 1.01.01
  01.00.01  2020-06-24  virrlu  Added GHS support
  01.01.00  2020-10-27  visto   update to new template
  01.02.00  2021-05-05  vishci  rename BRS_COMP_HIGHTEC to BRS_COMP_GCCHIGHTEC
  01.03.00  2021-07-07  visto   version change due to change filter rules change in ALM
**********************************************************************************************************************/

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
  INCLUDES
**********************************************************************************************************************/
#include "BrsHw.h"

#if !defined (BRS_ENABLE_FBL_SUPPORT)
  #include "Os.h"
#endif

#include "BrsMain.h"

/*
 * Description: The BrsMainStartup header provides all the necessary structs of
 *              RAM areas, necessary for RAM initialization.
 */
#include "BrsMainStartup.h"

/**********************************************************************************************************************
  VERSION CHECK
**********************************************************************************************************************/
#if (BRSHW_VERSION != 0x0103u)
  #error "Header and source file are inconsistent!"
#endif
#if (BRSHW_BUGFIX_VERSION != 0x00u)
  #error "Different versions of bugfix in Header and Source used!"
#endif

/**********************************************************************************************************************
  CONFIGURATION CHECK
**********************************************************************************************************************/
#if defined (BRS_COMP_TASKING) 
#else
  #error "Unknown compiler specified!"
#endif

#if defined (BRS_ENABLE_PORT)                  || \
    defined (BRS_ENABLE_SAFECTXSUPPORT)        || \
    defined (BRS_ENABLE_OS_MULTICORESUPPORT)   || \
    defined (BRS_ENABLE_SUPPORT_LEDS)          || \
    defined (BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN) || \
    defined (BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN)
  #error "Configured Feature(s) not supported by this implementation for a dedicated HSM Core UseCase!"
#endif

/**********************************************************************************************************************
  DEFINITION + MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL CONST VARIABLES
**********************************************************************************************************************/
/*
 * Description: These constants are used to propagate the Versions over
 *              module boundaries.The version numbers are BCD coded. E.g. a sub
 *              version of 23 is coded with 0x23, a bug fix version of 9 is
 *              coded 0x09.
 */
uint8 const kBrsHwMainVersion   = (uint8)(BRSHW_VERSION >> 8);
uint8 const kBrsHwSubVersion    = (uint8)(BRSHW_VERSION & 0xFF);
uint8 const kBrsHwBugfixVersion = (uint8)(BRSHW_BUGFIX_VERSION);

/**********************************************************************************************************************
  LOCAL VARIABLES AND LOCAL HW REGISTERS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONTROLLER CONFIGURATION REGISTERS
**********************************************************************************************************************/
#if defined (BRS_ENABLE_PLLCLOCKS)
  /* HSM Bridge module - interconnection between HSM subsystem and host system. */
  #define HSM_BRIDGE_BASE      0xF0040000UL
  #define CLKCTRL              BRSHW_IOS(uint32, HSM_BRIDGE_BASE + 0x40UL)  /* CLKCTRL register address */
  #define CLKCTRL_CLKDIV0      0x00UL                                       /* Clock divider value for maximum HSM cpu frequency */

  /* Cache module registers */
  #define HSM_CACHE_BASE       0xE008A000UL
  #define CACHE_CTRL           BRSHW_IOS(uint32, HSM_CACHE_BASE + 0x04UL)  /* Cache control register */
  #define CACHE_CTRL_DAPCA_EN  0x00UL                                      /* Enable cache parallel access bit mask */
#endif /*BRS_ENABLE_PLLCLOCKS*/

/* Reset Controller Registers */
#define SCU_BASE             0xF0036000UL
#define SCU_RSTSTAT          BRSHW_IOS(uint32, SCU_BASE + 0x50UL)  /* Reset status register */
#define SW_RESET_MASK        0x08000000UL                          /* Software reset bit mask */

/**********************************************************************************************************************
  LOCAL VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL CONST VARIABLES
**********************************************************************************************************************/

/**********************************************************************************************************************
  PROTOTYPES OF LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  FUNCTION DEFINITIONS
**********************************************************************************************************************/

#if defined (BRS_ENABLE_WATCHDOG)
/*****************************************************************************/
/**
 * @brief      This function must be used to initialize the Watchdog.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from BrsMainInit() at power on initialization
 */
/*****************************************************************************/
void BrsHwWatchdogInitPowerOn(void)
{
  /* Nothing to be done here. Watchdog deactivated after reset automatically. */
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
void BrsHwPllInitPowerOn(void)
{
  /* Set HSM to maximum clock speed. */
  CLKCTRL = (uint32)CLKCTRL_CLKDIV0;

  /* Enable parallel cache access. */
  CACHE_CTRL = (uint32)CACHE_CTRL_DAPCA_EN;
}
#endif /*BRS_ENABLE_PLLCLOCKS*/

/* BrsHwDisableInterruptAtPowerOn() is part of ArmCommon */

/* BrsHwSoftwareResetECU() is part of ArmCommon */

/*****************************************************************************/
/**
 * @brief      Get reset reason
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     Reset reason 
 * @context    Function is called from BrsMainStartup to determine if reset
 *             was triggered through software call (BrsHwSoftwareResetECU()).
 */
/*****************************************************************************/
brsHw_ResetReasonType BrsHwGetResetReason(void)
{
  if((SCU_RSTSTAT & SW_RESET_MASK) == 1)
  {
    return BRSHW_RESET_SW;
  }
  else
  {
    return BRSHW_RESET_OTHER;
  }
}

/* BrsHwTime100NOP() is part of ArmCommon */

/*****************************************************************************/
/**
 * @brief      This API is used to read the core ID of the actual running core
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     Core ID of the actual running core
 * @context    Function is e.g. called from main@BrsMain, to only call HW-init
 *             code once, on the boot core.
 *             In MultiCore setups, additional BRSHW_INIT_CORE_ID must be
 *             declared inside BrsHw.h, to configure the proper core ID value
 *             of that boot core.
 */
/*****************************************************************************/
uint32 BrsHw_GetCore(void)
{
  /* only SingleCore supported up to now */
  return 0u;
}

/*****************************************************************************/
/* BrsHw_EnableInterrupt() is part of ArmCommon */

/* BrsHw_DisableInterrupt() is part of ArmCommon */

/* BrsHw_TriggerSoftwareInterrupt() is part of ArmCommon */

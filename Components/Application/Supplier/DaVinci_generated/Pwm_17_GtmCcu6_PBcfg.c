/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2021)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Pwm_17_GtmCcu6_PBcfg.c                                        **
**                                                                            **
**  VERSION   : 19.0.0                                                        **
**                                                                            **
**  DATE, TIME: 2023-07-11, 10:53:39              !!!IGNORE-LINE!!!           **
**                                                                            **
**  GENERATOR : Build b191017-0938                !!!IGNORE-LINE!!!           **
**                                                                            **
**  BSW MODULE DECRIPTION : Pwm.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Pwm configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR Specification of Pwm Driver                    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include module header File */
#include "Pwm_17_GtmCcu6.h"
#include "Mcu_17_TimerIp.h"



/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*
Configuration:
PWM Channel Configuration:
Elements / Attributes
1. Notification function pointer (if required)
2. Shift Value, only for PWM_FIXED_PERIOD_SHIFTED Class
   Input a value between 0 and 0x8000.
3. Default Duty Cycle ( duty cycle value between
   0 and 0x8000)
4. Pwm_Period:
   Enter in ticks
   PWM070: All time units should be in ticks.
5. Pwm_ConfigChannel:
   Go in the following parameter order
   a) Reference to Channel Number, for a Shifted, Center Aligned and
   Zero Shifted channel, a reference must be given. For a variable
   and Fixed Period channel class, reference should not be given.
   Reference should be given in the form of channel number index.
   b) Channel Class
      Possible Options: PWM_FIXED_PERIOD, PWM_FIXED_PERIOD_SHIFTED,
      PWM_FIXED_PERIOD_CENTER_ALIGNED, PWM_VARIABLE_PERIOD
   c) Channel Idle State:
      Possible Options: PWM_LOW, PWM_HIGH
      Output line goes into Idle state either after Pwm_SetOutputtoIdle
      or Pwm_DeInit.
   d) Channel Polarity:
      Possible Options: PWM_LOW, PWM_HIGH
      Initial Polarity state of the channel.
   e) GTM timer Configuration:
      Select timer reference :TOM/ATOM.
      Clockselect.
 */
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*
Function Like Macro:Pwm_lConfigChannel
Macro that packs the PWM Channel Information.
Input Parameters:
DsadcNotif: The notification flag to enable GTM interrupts to trigger DSADC
ShiftReset: Shifted channel is reset by itself or by other channel
ChannelClass : Channel Class
ChannelCoherency : Channel Coherency
IdleState : Idle State
Polarity : Channel Polarity
AssignedHwUnit : Hardware Unit Used
*/
/*MISRA2012_RULE_4_9_JUSTIFICATION: Function like macro is used to reduce the
memory usage */
#define Pwm_lConfigChannel(DsadcNotif,                   \
                           ShiftReset,                   \
                           ChannelClass,                 \
                           ChannelCoherency,             \
                           IdleState,                    \
                           Polarity)                     \
              ((uint16)( ((DsadcNotif) << 6U)          |   \
                         ((ShiftReset) << 5U)          |   \
                         ((ChannelClass) << 3U)        |   \
                         ((ChannelCoherency) << 2U)    |   \
                         ((IdleState) << 1U)           |   \
                         ((Polarity))                       \
                       ))
/******************************************************************************/
/******************************************************************************/
  
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
before MemMap inclusion. It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
  
static const uint8 Pwm_ChannelIndexMap [2] =
{
  0x0U,
  0x1U,
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
/* Loop for all the cores */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
        
static const Mcu_17_Gtm_TomAtomChConfigType Pwm_kChannelConfigGtm_Core0[1] = 
{
  {
    MCU_GTM_TIMER_TOM, /* Timer Type (TOM/ATOM)*/
    /* Bit[15:8] - Module number Bit[7:0] - Channel number*/
    0x8U,
    0x80000800U, /* Channel Control Register*/
    0x7d0U, /* CN0 in ticks */
    0x7d0U, /* CM0 in ticks */
    0x0U, /* CM1 in ticks */
    0x7d0U, /* SR0 in ticks */
    0x0U, /* SR1 in ticks */
    0x80U /* Period,Duty Interrupt and mode*/
  },
};
static const Mcu_17_Ccu6_TimerConfigType Pwm_kChannelConfigCcu6_Core0[1] = 
{
  {
    0x20000U, /* Ccu6 Timer ID */
    /* T12 - [2-0] - Timer T12 Input Clock Select
    [3]   - Timer T12 Prescaler Bit
    [7]   - T12 Operating Mode
    T13 - [10-8] - Timer T13 Input Clock Select
    [11]   - Timer T13 Prescaler Bit */
    0x1U,
    /* T12 - [1-0]  - Timer T12 modulation enable
    T13 - [2]   - Enable Compare Timer T13 output CC63*/
    0x1U,
    /* T12 - [1-0] - Compare outputs passive state level
    T13 - [2]   - Passive state level of output COUT63*/
    0x1U,
    0x0U, /* T12/T13 counter value */
    0x7d0U, /* Period */
    0x0U, /* Duty */
    0x1U, /* Compare mode */
    0x0U, /* Port in select */
    0x0U, /* Interrupt enable */
    0xaU /* Interrupt node Select */
  },
};
      
static const Pwm_17_GtmCcu6_ChannelConfigType Pwm_kChannelConfigurationCore0[] =
{
/*******************************************************************************
*  Channel Number        : 0
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_HB_P_PwmChannel
*  Channel Class         : PWM_FIXED_PERIOD
*******************************************************************************/
  {
    0, /* Pwm logical channel ID */
    1, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      0U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD,/* Channel Class */
      PWM_17_GTMCCU6_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_HIGH  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x7d0, /* Default Period */
    (uint32)0x0, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    (const void*)&Pwm_kChannelConfigCcu6_Core0[0]
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
  },
/*******************************************************************************
*  Channel Number        : 1
*  Channel Symbolic Name : Pwm_17_GtmCcu6Conf_PwmChannel_HB_N_PwmChannel
*  Channel Class         : PWM_FIXED_PERIOD
*******************************************************************************/
  {
    1, /* Pwm logical channel ID */
    0, /* Timer used GTM:0/CCU6:1 */
    Pwm_lConfigChannel(
      0U,/* The notification flag to enable GTM interrupts to trigger DSADC */
      0U,/* Channel reset from other channel or not*/
      PWM_17_GTMCCU6_FIXED_PERIOD,/* Channel Class */
      PWM_17_GTMCCU6_NON_COHERENT,/* Coherency */
      PWM_17_GTMCCU6_LOW, /* channel Idle state */
      PWM_17_GTMCCU6_HIGH  /* channel polarity */
    ),
    (Pwm_17_GtmCcu6_PeriodType)0x7d0, /* Default Period */
    (uint32)0x0, /* Default Duty Cycle */
    (uint32)0x0, /* Shift Value */
    (const void*)&Pwm_kChannelConfigGtm_Core0[0]
    /* MISRA2012_RULE_11_3_JUSTIFICATION: SFR access. No side effects foreseen
    * by violating this MISRA rule. */
  },
};
      
static const Pwm_17_GtmCcu6_CoreConfigType Pwm_CoreConfigCore0 =
{ 
  (Pwm_17_GtmCcu6_ChannelType)2U,
  (const Pwm_17_GtmCcu6_ChannelConfigType*)&Pwm_kChannelConfigurationCore0[0]
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"

const Pwm_17_GtmCcu6_ConfigType Pwm_17_GtmCcu6_Config =
{
  {

    /* MISRA2012_RULE_11_8_JUSTIFICATION: This typecast is in-line with the data type of the structure member PwmCoreAdd, MISRA is reported becasue of structure Pwm_CoreConfigCore,
    which is defined as constant to be allocated in Read only memory, Hence no side effects foreseen by violating this MISRA rule */

    (Pwm_17_GtmCcu6_CoreConfigType*)&Pwm_CoreConfigCore0
    /* MISRA2012_RULE_11_8_JUSTIFICATION: This typecast is in-line with the data type of the structure member PwmCoreAdd, MISRA is reported becasue of structure Pwm_CoreConfigCore,
    which is defined as constant to be allocated in Read only memory, Hence no side effects foreseen by violating this MISRA rule */

  },
  /* MISRA2012_RULE_11_8_JUSTIFICATION: This typecast is in-line with the data type of structure member PwmChannelIdxmapPtr, MISRA is reported becasue of data type Pwm_ChannelIndexMap,
  which is defined as constant to be allocated in Read only memory, Hence no side effects foreseen by violating this MISRA rule */
  (uint8*)&Pwm_ChannelIndexMap,
  { 
    0xff00ffffU,
    0xffffffffU
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration of notification function 
before MemMap inclusion It complies to Autosar guidelines. */
#include "Pwm_17_GtmCcu6_MemMap.h"

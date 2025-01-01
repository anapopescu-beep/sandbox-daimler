/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2020)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Hsm_TimSer.c                                               **
**                                                                            **
**  VERSION      : 1.0.0                                                      **
**                                                                            **
**  DATE         : 2020-03-31                                                 **
**                                                                            **
**  VARIANT      : Variant PC                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : HSM Timer library source file                              **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : Yes                                              **
**                                                                            **
*******************************************************************************/
/* Timer register file inclusion */
#include "Platform_Types.h"
#include "Std_Types.h"
#include "IfxHsm.h"
#include "Hsm_TimSer.h"

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/* This variable holds the resolution of the TIM0 HSM timer */
static uint16 HsmTimerResolution;

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define TIM0_100MHZ_RES   (uint16)10
#define TIM0_RELOAD_VAL   (uint16)0
/*******************************************************************************
**                                                                            **
** Syntax           : uint16 Timer_DelayTickResolution(void)                  **
**                                                                            **
** Description      : The interface is used by applications to retrieve in    **
**                    nanoseconds the resolution of the delay tick(TIM0 timer)**
**                                                                            **
** Service ID       :                                                         **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Resolution of TIM0 timer delay tick in nanoseconds      **
**                                                                            **
*******************************************************************************/
uint16 Timer_DelayTickResolution(void)
{
   return HsmTimerResolution;
}

/*******************************************************************************                                                                  **
** Syntax           : uint16 Timer_DelayGetTick(void)                         **
**                                                                            **
** Description      : This interface is used by applications to retrieve the  **
**                    latest tick count of the underlying TIM0 timer. The     **
**                    latest tick count in HSM_TIM0 is returned by this       **
**                    interface. There are two uses of this interface.        **
**                    Applications can retrieve a base tick count, add the    **
**                    desired delay to the base tick count and arrive at a    **
**                    terminal tick count. Applications can also then         **
**                    periodically invoke this interface to determine if the  **
**                    underlying timer has counted up to the terminal tick    **
**                    count.                                                  **
**                                                                            **
** Service ID       :                                                         **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Latest 16 bit counter value of TIM0 HSM timer           **
**                                                                            **
**                                                                            **
*******************************************************************************/
uint16 Timer_DelayGetTick(void)
{
  uint16 CurrentTicks;
  CurrentTicks = HSM_TIM->TIM_CNT0; /* counter value */
  return CurrentTicks;
}

/*******************************************************************************
**                                                                            **
** Syntax           : void Timer_Init(void)                                   **
**                                                                            **
** Description      : The interface is used to initialize the TIM0 HSM timer  **
**                                                                            **
** Service ID       :                                                         **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/
void Timer_Init(void)
{

  HSM_BRIDGE->CLKCTRL = CLKCTRL_CLKDIV_DIV1;
  /*clear the overflow and TR bits of timer 0 */ 
  HSM_TIM->TIM_CTRL = TIM_CTRL_UNLOCK_TF0_Msk; //0x0004; 
  /* Prescaler set as 1 for timer0
   * HSM runs with maximum frequency 100Mhz*/
  HSM_TIM->TIM_CFG = TIM_CFG_TPR_DIS0_Msk;
  /* Enable Timer 0 */
  HSM_TIM->TIM_CTRL = TIM_CTRL_TR0_Msk;
  /* Reload value is 0 */
  HSM_TIM->TIM_RLD0 = TIM0_RELOAD_VAL;
  /* The HSM frequency is running at 100Mhz */
  HsmTimerResolution = TIM0_100MHZ_RES;

}


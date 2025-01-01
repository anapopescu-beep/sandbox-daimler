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
**  FILENAME     : Hsm_TimSer.h                                               **
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
**  DESCRIPTION  : HSM Timer library header definition file                   **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : Yes                                              **
**                                                                            **
*******************************************************************************/
#ifndef  HSM_TIMSER_H
#define  HSM_TIMSER_H


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
extern uint16 Timer_DelayTickResolution(void);

/*******************************************************************************
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
extern uint16 Timer_DelayGetTick(void);

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
extern void Timer_Init(void);

#endif


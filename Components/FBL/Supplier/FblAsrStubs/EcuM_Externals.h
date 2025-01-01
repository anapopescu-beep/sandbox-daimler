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
**  FILENAME     : EcuM_Externals.h                                           **
**                                                                            **
**  VERSION      : 3.0.0                                                      **
**                                                                            **
**  DATE         : 2020-09-28                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This file provides ECUM callback/callout declarations      **
**                 This file is for Evaluation Purpose Only                   **
**                                                                            **
**  SPECIFICATION(S) : Specification of ECUM Driver, AUTOSAR Release 4.4.0    **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/

#ifndef ECUMEXTERNALS_H
#define ECUMEXTERNALS_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/* Wake Up Related APIs. Used in Gpt,Icu Drivers */

extern void EcuM_CheckWakeup
(
  EcuM_WakeupSourceType wakeupSource
);
#endif   /* #ifndef ECUMEXTERNALS_H  */

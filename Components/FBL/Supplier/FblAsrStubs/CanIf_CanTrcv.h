/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2020)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : CanIf_CanTrcv.h                                             **
**                                                                           **
**  VERSION    : 1.0.0                                                       **
**                                                                           **
**  DATE       : 2020-09-30                                                  **
**                                                                           **
**  VARIANT    : NA                                                          **
**                                                                           **
**  PLATFORM   : Infineon AURIX2G                                            **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file exports CAN Interface functions.                **
**                 This file is for Evaluation Purpose Only                  **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
#ifndef CANIF_CANTRCV_H
#define CANIF_CANTRCV_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/

#include "CanIf.h"
#ifdef APP_SW
#if (APP_SW == DEMO_APP)
#include "DemoApp_Cfg.h"
#endif /* #if (APP_SW == DEMO_APP) */
#endif /* #ifdef APP_SW */

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/
/* Declaration of CanIf_ConfirmPnAvailability */
extern void CanIf_ConfirmPnAvailability(uint8 TransceiverId );

/* Declaration of CanIf_CheckTrcvWakeFlagIndication */
extern void CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId);

/* Declaration of CanIf_TrcvModeIndication */
extern void CanIf_TrcvModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);

/* Declaration of CanIf_ClearTrcvWufFlagIndication */
extern void CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId);
/******************************************************************************
**                      Global Inline Function Definitions                   **
******************************************************************************/
#endif
/*END OF  CANIF_CANTRCV_H */

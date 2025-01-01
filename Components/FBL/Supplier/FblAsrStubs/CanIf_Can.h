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
**  FILENAME   : CanIf_Can.h                                                 **
**                                                                           **
**  VERSION    : 1.0.0                                                       **
**                                                                           **
**  DATE       : 2020-10-23                                                  **
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
**                  This file is for Evaluation Purpose Only                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
#ifndef CANIF_CAN_H
#define CANIF_CAN_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/

#include "CanIf.h"
#ifdef APP_SW
#if (APP_SW == DEMO_APP)
#include "DemoApp_Cfg.h"
#endif /* #if (APP_SW == DEMO_APP) */
#endif /* #ifdef APP_SW */

#ifdef CAN_DEMO_EN
#if (CAN_DEMO_EN == STD_ON)
#include "Can_17_McmCan.h"
#endif
#endif /* #ifdef CAN_DEMO_EN */

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/

#define CAN_17_MCMCAN_START_SEC_CODE_QM_GLOBAL
#include "Can_17_McmCan_MemMap.h"

  /* Declaration of CanIf_ControllerModeIndication */
extern void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode);

/* Declaration of CanIf_TxConfirmation */
extern void CanIf_TxConfirmation(PduIdType CanTxPduId);

/* Declaration of CanIf_RxIndication */
extern void CanIf_RxIndication(const Can_HwType *Mailbox, const PduInfoType *PduInfoPtr);

/* Declaration of CanIf_CurrentIcomConfiguration */
extern void CanIf_CurrentIcomConfiguration(uint8 ControllerId, IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error);

/* Declaration of CanIf_ControllerBusOff */
extern void CanIf_ControllerBusOff( uint8 ControllerId);

#define CAN_17_MCMCAN_STOP_SEC_CODE_QM_GLOBAL
#include "Can_17_McmCan_MemMap.h"

#endif /* #if (CAN_DEMO_EN == STD_ON) */


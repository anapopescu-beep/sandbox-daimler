/**************************************************************************** **
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
**  FILENAME    : QsM_Cbk.h                                                   **
**                                                                            **
**  VERSION     : 1.0.0                                                       **
**                                                                            **
**  DATE        : 2020-04-17                                                  **
**                                                                            **
**  VARIANT     : NA                                                          **
**                                                                            **
**  PLATFORM    : Infineon AURIX2G                                            **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION  : This file exports funtionality of QsM call back            **
**                 functionality                                              **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/
#ifndef  QSM_CBK_H
#define  QSM_CBK_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Function Like Macro Definitions                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
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

/*******************************************************************************
** Syntax : void QsM_JobEndNotification(void)                                 **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Function to be used by the underlying memory abstraction to  **
**               signal end of Qs job without error.                          **
*******************************************************************************/

void QsM_JobEndNotification(void);

/*******************************************************************************
** Syntax : void QsM_JobErrorNotification(void)                               **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Function to be used by the underlying memory abstraction to  **
**               signal end of Qs job with error.                             **
*******************************************************************************/

void QsM_JobErrorNotification(void);

/*******************************************************************************
** Syntax : void QsM_IllegalStateNotification(void)                           **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Function to be used by the underlying memory abstraction to  **
**               signal illegal state.                                        **
*******************************************************************************/

void QsM_IllegalStateNotification(void);

/*******************************************************************************
** Syntax : void QsM_HardenErrorNotification(void)                            **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Function to be used by the underlying memory abstraction to  **
**               signal end of QS hardening job with error.                   **
*******************************************************************************/

void QsM_HardenErrorNotification(void);

#endif /* QSM_CBK_H */

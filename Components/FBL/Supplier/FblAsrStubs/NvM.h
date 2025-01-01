#ifndef  NVM_H /* SWS_NvM_00551 { */
#define  NVM_H
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
**  FILENAME    : NvM.h                                                       **
**                                                                            **
**  VERSION     : 1.0.0                                                       **
**                                                                            **
**  DATE        : 2020-10-24                                                  **
**                                                                            **
**  VARIANT     : NA                                                          **
**                                                                            **
**  PLATFORM    : Infineon AURIX2G                                            **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION  : Header file containing call back definitions of Nvm module **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_NVRAMManager, AUTOSAR Release 4.4.0        **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/

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
** Syntax : void NvM_JobEndNotification(void)                                 **
**                                                                            **
** Service ID: 0x11                                                           **
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
**               signal end of job without error.                             **
*******************************************************************************/
/* SWS_NvM_00462 */
void NvM_JobEndNotification(void);

/*******************************************************************************
** Syntax : void NvM_JobErrorNotification(void)                               **
**                                                                            **
** Service ID: 0x12                                                           **
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
**               signal end of job with error.                                **
*******************************************************************************/
/* SWS_NvM_00463 */
void NvM_JobErrorNotification(void);

#endif  /* } NVM_CBK_H */

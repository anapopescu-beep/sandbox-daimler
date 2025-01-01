/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2017)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Mcal_SafetyError.h                                         **
**                                                                            **
**  VERSION      : 1.0.0                                                      **
**                                                                            **
**  DATE         : 2017-11-02                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Safety Error Roporting header definition file              **
**                                                                            **
**  SPECIFICATION(S) : Safety requirements.                                   **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/
#ifndef _MCAL_SAFETY_ERROR_H
#define _MCAL_SAFETY_ERROR_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#if (APP_SW == TEST_APP)
#include "Test_Mcal_SafetyError.h"
#endif /*#if (APP_SW == TEST_APP)*/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define MCAL_SAFETY_ERROR_RELEASE_MAJOR_VERSION 4U
#define MCAL_SAFETY_ERROR_RELEASE_MINOR_VERSION 2U

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
extern void Mcal_ReportSafetyError(uint16 ModuleId, uint8 InstanceId, \
                                   uint8 ApiId, uint8 ErrorId);

#endif /* End of _MCAL_SAFETY_ERROR_H */


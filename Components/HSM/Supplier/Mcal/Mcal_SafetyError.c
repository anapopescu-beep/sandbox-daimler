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
**  FILENAME     : Mcal_SafetyError.c                                         **
**                                                                            **
**  VERSION      : 1.0.0                                                      **
**                                                                            **
**  DATE         : 2020-04-17                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Safety Error Roporting source file                         **
**                                                                            **
**  SPECIFICATION(S) : For safe operation                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal_SafetyError.h"
#if (APP_SW == DEMO_APP)
#include "TestHsm_Print.h"
#endif /*#if (APP_SW == DEMO_APP)*/
#if (APP_SW == TEST_APP)
#include "Test_Mcal_SafetyError.h"
#endif /*#if (APP_SW == TEST_APP)*/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Syntax         : void Mcal_ReportSafetyError(uint16 ModuleId,              **
**                                       uint8 InstanceId,                    **
**                                       uint8 ApiId,                         **
**                                       uint8 ErrorId)                       **
**                                                                            **
** Description    : This is only a function stub for Eg Application           **
**                                                                            **
** Service ID:    : NA                                                        **
**                                                                            **
** Sync/Async:    : Synchronous                                               **
**                                                                            **
** Reentrancy:    : Non Reentrant                                             **
**                                                                            **
** Parameters(in) : ModuleId, InstanceId, InstanceId, ErrorId                 **
**                                                                            **
** Parameters(out): None                                                      **
**                                                                            **
** Return value   : void                                                      **
**                                                                            **
*******************************************************************************/
void Mcal_ReportSafetyError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
  #if (APP_SW == DEMO_APP)
  print_f("\n SAFETY ERROR OCCURED \n ");
  print_f("ModuleId:%d, InstanceId: %d, ApiId:%d, ErrorId:%d"
          , ModuleId, InstanceId, ApiId, ErrorId);
  #endif /* #if (APP_SW == DEMO_APP) */

  #if (APP_SW == TEST_APP)
  Test_Mcal_ReportSafetyError(ModuleId, InstanceId, ApiId, ErrorId);
  #endif /*#if (APP_SW == TEST_APP)*/
}

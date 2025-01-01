/********************************************************************************************************************** 
 *  COPYRIGHT 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  Copyright (c) 2020 by Mercedes Benz AG - Alle Rechte vorbehalten -  All rights reserved. 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  EXAMPLE CODE ONLY 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW 
 *  configuration. The Example Code has not passed any quality control measures and may be incomplete. The 
 *  Example Code is neither intended nor qualified for use in series production. The Example Code as well 
 *  as any of its modifications and/or implementations must be tested with diligent care and must comply 
 *  with all quality requirements which are necessary according to the state of the art before their use. 
 * 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  FILE DESCRIPTION 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  File: Compiler_Cfg.h 
 *  Description: Sample implementation of the RealTarget-variant.
 *                 
 *********************************************************************************************************************/

#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define AUTOSAR_COMSTACKDATA

#define MSR_REGSPACE  REGSPACE

/* Configurable memory class for pointers to registers (e.g. static volatile CONSTP2VAR(uint16, PWM_CONST, REGSPACE)). */
#define REGSPACE


/* due to compatibility to ASR 2.1 */
#define _STATIC_   STATIC
#define _INLINE_   INLINE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Compiler_Cfg_MSR4_MBP.h"
#include "Compiler_Cfg_MSR4_MCP.h"
#include "Compiler_Cfg_MSR4_MEP.h"
#include "Compiler_Cfg_MSR4_MOP_Daimler.h"
#include "Compiler_Cfg_MSR4_MPP_Aurix_2G_TC3xx_Tasking.h"

/* erase value is set to "0x00" since we have the same value for vMemAccM_ReadBlank and vMemAccM_Read */
#define VMEMACCM_ERASEVALUE 0x00
#define Sbc_SpiDataType    Spi_DataBufferType
#define APP_SW 3

 /**********************************************************************************************************************
 *  Workaround
 *********************************************************************************************************************/




#endif /* COMPILER_CFG_H */

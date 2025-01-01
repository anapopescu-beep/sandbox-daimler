
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  BrsHwIntTb.c
      Project:  Vector Basic Runtime System
       Module:  BrsHw for platform Infineon Aurix/AurixPlus

  \brief Description:  This is the hardware specific code file for Vector Basic Runtime System (BRS).

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

/**********************************************************************************************************************
*  EXAMPLE CODE ONLY
*  -------------------------------------------------------------------------------------------------------------------
*  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
*  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
*  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
*  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
*  according to the state of the art before their use.
*********************************************************************************************************************/

#define _BRSHWINTTB_C_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "BrsHw.h"

void BrsTrapHandler_MMU(void)
{
  /* if you are stuck here, check D15 for the TIN value */
  while(1);
}
void BrsTrapHandler_InternalProtection(void)
{
  /* if you are stuck here, check D15 for the TIN value */
  while(1);
}
void BrsTrapHandler_InstructionError(void)
{
  /* if you are stuck here, check D15 for the TIN value */
  while(1);
}
void BrsTrapHandler_ContextManagement(void)
{
  /* if you are stuck here, check D15 for the TIN value */
  while(1);
}
void BrsTrapHandler_SysBusPeripheralError(void)
{
  /* if you are stuck here, check D15 for the TIN value */
  while(1);
}
void BrsTrapHandler_Assertion(void)
{
  /* if you are stuck here, check D15 for the TIN value */
  while(1);
}
void BrsTrapHandler_SysCall(void)
{
  /* if you are stuck here, check D15 for the TIN value */
  while(1);
}
void BrsTrapHandler_NMI(void)
{
  /* if you are stuck here, check D15 for the TIN value */
  while(1);
}

__asm (".SDECL \".text.brsExcVect\",code,PROTECT");
__asm (".SECT  \".text.brsExcVect\"");

__asm (".GLOBAL BrsHw_TrapTable");
__asm ("BrsHw_TrapTable:");

/* MMU Traps */
__asm(".align 32"); /* make sure the handler is aligned properly */
__asm("j BrsTrapHandler_MMU"); /* jump to handler */
__asm("rfe"); /* return to normal execution (in case the handler returns */

/* Internal Protection Traps */
__asm(".align 32"); /* make sure the handler is aligned properly */
__asm("j BrsTrapHandler_InternalProtection"); /* jump to handler */
__asm("rfe"); /* return to normal execution (in case the handler returns */

/* Instruction Error Traps */
__asm(".align 32"); /* make sure the handler is aligned properly */
__asm("j BrsTrapHandler_InstructionError"); /* jump to handler */
__asm("rfe"); /* return to normal execution (in case the handler returns */

/* Context Management Traps */
__asm(".align 32"); /* make sure the handler is aligned properly */
__asm("j BrsTrapHandler_ContextManagement"); /* jump to handler */
__asm("rfe"); /* return to normal execution (in case the handler returns */

/* System Bus and Peripheral Error Traps */
__asm(".align 32"); /* make sure the handler is aligned properly */
__asm("j BrsTrapHandler_SysBusPeripheralError"); /* jump to handler */
__asm("rfe"); /* return to normal execution (in case the handler returns */

/* Assertion Traps */
__asm(".align 32"); /* make sure the handler is aligned properly */
__asm("j BrsTrapHandler_Assertion"); /* jump to handler */
__asm("rfe"); /* return to normal execution (in case the handler returns */

/* System Call Trap */
__asm(".align 32"); /* make sure the handler is aligned properly */
__asm("j BrsTrapHandler_SysCall"); /* jump to handler */
__asm("rfe"); /* return to normal execution (in case the handler returns */

/* Non Maskable Interrupt Traps */
__asm(".align 32"); /* make sure the handler is aligned properly */
__asm("j BrsTrapHandler_NMI"); /* jump to handler */
__asm("rfe"); /* return to normal execution (in case the handler returns */


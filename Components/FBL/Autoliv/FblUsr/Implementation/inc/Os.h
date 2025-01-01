
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
  \file  File:  Os.h
      Project:  Vector Basic Runtime System
       Module:  BrsMain

  \brief Description:  FBL OS template header for usage of MSR4 modules, always expecting it

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

/**********************************************************************************************************************
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
  --------  ----------  ------  ---------------------------------------------------------------------------------------
  01.00.00  2020-09-18  visbwa  Initial creation for FBL @ vBaseEnv w/o real OS
  01.00.01  2020-11-02  virjas  Add ISR macro to support MCAL components that define ISRs
  01.00.02  2020-11-06  visbwa  Fix ESCAN00107785: added include of Std_Types.h to solve compiler errors (missing
                                uint32), removed AUTHOR IDENTITY
**********************************************************************************************************************/

#ifndef _OS_H_
#define _OS_H_

/* Necessary for type uint32, used for TickType. Some Fbl modules don't include BrsHw.h or Std_Types.h before they include the SchM headers */
#include "Std_Types.h"

/*! Macro OS_MS2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* OS application modes */
# define OSDEFAULTAPPMODE     ((AppModeType)1)

#define ResumeAllInterrupts()
#define SuspendAllInterrupts()
#define StartOS(x)

#if defined (BRS_COMP_TASKING)
	#define DisableAllInterrupts()  __disable()
	#define EnableAllInterrupts()   __enable()
#else
	#define DisableAllInterrupts()  
	#define EnableAllInterrupts()   
#endif

/***********************************************************************************************************************
 *  TYPEDEFS
#define ISR(IsrName)  void Os_Fbl_Isr_##IsrName(void)
 **********************************************************************************************************************/
typedef uint32 TickType;
typedef uint8 AppModeType;


#endif /* OS_H */

/***********************************************************************************************************************
 *  END OF FILE: OS.H
 **********************************************************************************************************************/

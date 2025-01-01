/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief Os ASR4 stub for flash bootloader
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#ifndef OS_H
#define OS_H

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
 **********************************************************************************************************************/
typedef uint32 TickType;
typedef uint8 AppModeType;


#endif /* OS_H */

/***********************************************************************************************************************
 *  END OF FILE: OS.H
 **********************************************************************************************************************/

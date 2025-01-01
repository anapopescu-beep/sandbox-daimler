
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
  \file  File:  BrsHwBMHD.c
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

#define _BRSHWBMHD_C_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "BrsHw.h"

# if defined (BRS_COMP_TASKING)
#pragma protect
# endif
/* Boot Mode Headers - use boot from internal flash              */
/* At least 1 of these headers has to be present on the hardware */
/* TODO: Check if this configuration suits your setup.           */

/* this file is only required in BootManager */

/*+++++++++++++++++++++++++++++++++++++Attention!++++++++++++++++++++++++++++++++++++++++++++++++++++++
++ If you have to adjust the bmiField you have to change the bmi header value and CRC calculation.    +
++ Otherwise you could be locked out of your device! Read the manual for more information.            +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#if defined (BRS_COMP_TASKING)
#pragma section farrom "BMHD0"
#endif

#if defined (BRS_COMP_TASKING)
#pragma section farrom restore
#endif

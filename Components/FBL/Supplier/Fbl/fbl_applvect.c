/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application vectortable for Infineon TriCore.
 *                 This file is usually compiled and linked with
 *                 the bootloader and is located  O U T S I D E  the
 *                 protected area of the FBL. So it could be
 *                 compiled, linked and downloaded with the
 *                 application after adapting the interrupt
 *                 entry poits to the application interrupt vectors.
 *                 The application service routines are still interrupts!!
 *
 *                 This file must be compiled and linked in the bootloader
 *                 and the application to the
 *                 S A M E  M E M O R Y   L O C A T I O N !!!!
 *
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *
 *  \par Note
 *  \verbatim
 *  Please note, that this file contains example source code used by the Flash Bootloader.
 *  This code may influence the behaviour of the bootloader in principle. Therefore, great care must be taken to verify
 *  the correctness of the implementation.
 *
 *  The contents of the originally delivered files are only examples resp. implementation proposals.
 *  With regard to the fact that these functions are meant for demonstration purposes only, Vector Informatik's
 *  liability shall be expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Marco Wierer                  WM            Vector Informatik GmbH
 *  Andre Caspari                 Ci            Vector Informatik GmbH
 *  Achim Strobelt                Ach           Vector Informatik GmbH
 *  Johannes Krimmel              Kjs           Vector Informatik GmbH
 *  Andreas Wenckebach            AWh           Vector Informatik GmbH
 *  Daniel Moessner               DlM           Vector Informatik GmbH
 *  Matteo Trovo                  TMo           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2005-03-30  WM                       Initial version
 *  01.01.00   2007-10-10  Ci      ESCAN00022471    Added support for GNU compiler
 *  01.02.00   2013-01-25  Ach     ESCAN00064396    Support TriCore Aurix
 *                                 ESCAN00062912    Adapted comments to use Doxygen
 *  01.03.00   2013-12-02  Kjs     ESCAN00072404    Rework pragmas for HighTec/GNU compilers
 *  01.03.00   2013-12-10  Kjs     ESCAN00072544    Harmonized entry point label
 *  01.04.00   2014-01-13  Kjs     ESCAN00072921    Fixed entry point label for TASKING
 *  01.05.00   2014-03-14  Kjs     ESCAN00073200    Removed pragma section commands
 *  01.06.00   2015-07-22  AWh     ESCAN00084145    Beautification
 *  01.07.00   2017-08-03  DlM     ESCAN00096173    Include FblHal_Cfg.h for Cfg5 based configurations
 *  01.07.01   2020-06-08  TMo     ESCAN00106544    Fixed wrong start symbol for Tasking compiler and TC3xx
 **********************************************************************************************************************/
 
 /***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
 
#include "v_cfg.h"
#if defined( V_GEN_GENERATOR_MSR )
# include "FblHal_Cfg.h"
#endif /* V_GEN_GENRATOR_MSR */
#include "v_def.h"
#include "applvect.h"

/***********************************************************************************************************************
 *   VERSION
 **********************************************************************************************************************/

#if ( FBLVTABAPPL_TRICORE_VERSION != 0x0107 )
# error "Error in APPLVECT.C: Source and header file are inconsistent!"
#endif
#if ( FBLVTABAPPL_TRICORE_RELEASE_VERSION != 0x01 )
# error "Error in APPLVECT.C: Source and header file are inconsistent!"
#endif

# define RESETVECT _START

extern void RESETVECT( void ); /* PRQA S 3447 */ /* MD_TricoreApplVect_3447 */

#define FBL_APPLVECT_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
V_MEMROM0 V_MEMROM1 vuint32 V_MEMROM2 ApplIntJmpTable[APPLVECT_TABLE_SIZE] = {(vuint32)RESETVECT, APPLVECT_FROM_BOOT}; /* PRQA S 0305, 0685, 0428 */ /* MD_TricoreApplVect_JmpTable */
#define FBL_APPLVECT_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*****************************************************************************/

/* module specific MISRA deviations:

   MD_TricoreApplVect_3447:
     Reason: The function is declared in the startup code.
     Risk: Prototypes could be unmatched.
     Prevention: no prevention required.

   MD_TricoreApplVect_JmpTable:
     Reason: Casting to integral type in order to allow storage in of entry address in ApplIntJmpTable.
     Risk: Creates non portable software.
     Prevention: This is only used in hw-dependent file here.

*/

/***********************************************************************************************************************
 *  END OF FILE: APPLVECT.C
 **********************************************************************************************************************/

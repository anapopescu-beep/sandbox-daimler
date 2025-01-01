/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) provided
by the component ATM, part of the package <Package name>.
These are globally visible.  
This file is intended to be included in a package header file; 
all components should include the package header file instead of this file.

Current revision: $Revision: 1.1.1.2.2.1 $
Checked in:       $Date: 2022/07/12 09:24:15CEST $

*************************************************************************/

#ifndef I_ATM_PUBLIC
#define I_ATM_PUBLIC 1

#include "Std_Types.h"
#include "ATM_cfg_public.h"

/*************************************************************************
Declaration of constants                                             
**************************************************************************/

/*************************************************************************
Declaration of macros                                                
**************************************************************************/

/*************************************************************************
Declaration of macros                                                
**************************************************************************/

/*************************************************************************
Declaration of types
*************************************************************************/

/*************************************************************************
 Declaration of constants
*************************************************************************/

/*************************************************************************
Declaration of functions
**************************************************************************/

#define ATM_AC_AutoTestManager_START_SEC_CODE
#include "ATM_AC_AutoTestManager_MemMap.h"

/* Initialization function*/


/* Shutdown function*/
extern void ATM_Shutdown(void);

#define ATM_AC_AutoTestManager_STOP_SEC_CODE
#include "ATM_AC_AutoTestManager_MemMap.h"

#endif /* I_ATM_PUBLIC */

/* end of file */

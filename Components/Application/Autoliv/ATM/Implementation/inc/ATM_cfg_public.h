/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) configurable
in the package ATM.
This file is to be included only by this component.

Current revision: $Revision: !
Checked in:       $Date: 2023/10/13 08:28:23CEST $

*************************************************************************/

#ifndef I_ATM_PUBLIC_CFG
#define I_ATM_PUBLIC_CFG 1

/*************************************************************************
inclusion of the ATM header to have the autotest IDs 
**************************************************************************/
#include "Std_Types.h"

/*************************************************************************
Inclusion of the headers needed to interface with the modules        
that implement autotests                                             
**************************************************************************/

/*************************************************************************
Declaration of macros
*************************************************************************/

/*************************************************************************
 Definition of the autotest IDs, usable by the application to use the ATM API
 **************************************************************************/
/* Label: COD_ATM_00008 */
/* This list may not be a bijection with ERG */
/* Therefor the corresponding ERG fault identifier is stored */
/* inside auto tests configuration array */


/* BE CAREFUL: when adding a new auto test identifier DO NOT FORGET TO UPDATE the constants below */
#define KU8_NB_OF_STARTUP_CYCLIC_ELTS                    ((uint8)6)
#define KU8_NB_OF_RUNNING_CYCLIC_ELTS                    ((uint8)51)

/* Number of startup auto tests */
#define ATM_KU8_NB_OF_STARTUP_AUTO_TESTS                 ((uint8) 16)


#endif /* I_ATM_CONFIG */

/* end of file */

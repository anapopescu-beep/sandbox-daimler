/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) configurable
in the package ATM.
This file is to be included only by this component.

Current revision: $Revision: !
Checked in:       $Date: 2024/02/05 07:38:25CET $

*************************************************************************/

#ifndef I_ATM_PRIVATE_CFG
#define I_ATM_PRIVATE_CFG 1

/*************************************************************************
inclusion of the ATM header to have the autotest IDs 
**************************************************************************/
#include "Std_Types.h"
#include "ATM_cfg_public.h"

/*************************************************************************
Inclusion of the headers needed to interface with the modules        
that implement autotests                                             
**************************************************************************/

/*************************************************************************
Declaration of macros
*************************************************************************/
/* Maximum period in main function occurrences (2ms) = 100s */
#define KU16_CFG_MAX_TASK                    ((uint16)5)
#define KU16_CFG_MAX_DECADE                  ((uint16)60000)

/* Indexes in the atm_au8InhibitingModes array */
#define  KU8_MODES_______________INHIB    ((uint8)0)
#define  KU8_MODES________VOLTAG_INHIB    ((uint8)1)
#define  KU8_MODES_BELTFN_VOLTAG_INHIB    ((uint8)2)
#define  KU8_MODES_BELTFN________INHIB    ((uint8)3)
#define  KU8_MODES_ENABLE_____IGNITION    ((uint8)4)
#define  KU8_MODES_ENABLE__________API    ((uint8)5)
#define  KU8_MODES_ENABLE_CodingBLTHov    ((uint8)6)


#define  KU8_NUMBER_OF_INHIBITING_MODES          ((uint8)7)

#endif /* I_ATM_CONFIG */

/* end of file */

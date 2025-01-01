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

Current revision: $Revision: 1.1.1.3.2.1 $
Checked in:       $Date: 2022/07/12 09:24:15CEST $

*************************************************************************/

#ifndef I_ATM_PRIVATE
#define I_ATM_PRIVATE 1

#include "Std_Types.h"
#include "ATM_cfg_private.h"


/*************************************************************************
Declaration of constants                                             
**************************************************************************/

/*************************************************************************
Declaration of macros                                                
**************************************************************************/

/*************************************************************************
These macros are to be used in the ATM configuration file. They describe
the type of an autotest
**************************************************************************/ 
#define KU8_AUTO_TEST_CONFIG_NO_TYPE               ((uint8)(0x00))
#define KU8_AUTO_TEST_CONFIG_TYPE_PERIODIC         ((uint8)(0x01))
#define KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_ABORT   ((uint8)(0x02)) /* execution frozen if NOK */
#define KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_RETRY   ((uint8)(0x04)) /* execution until OK */
#define KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT         ((uint8)(0x08)) /* execution until OK or NOK */
#define KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_DECIDED ((uint8)(0x10)) /* Retry until different from NOT DECIDED */
/*************************************************************************
Declaration of macros                                                
**************************************************************************/

/*************************************************************************
Declaration of types
*************************************************************************/

/*************************************************************************
Label:
Object: This structure describes the constant data of an autotest :
 - Pointer to function callback
 - Type (KU8_AUTO_TEST_CONFIG_TYPE_PERIODIC, ATM_KU8_CONFIG_TYPE_ON_DEMAND, or
     KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT)
 - Period and offset (to access with the appropriate macros)
 - Running context mask
Unit: None.
**************************************************************************/
typedef struct
{
   /* Pointer to auto test callback */
   u8TestResultType (*pfAutotestCallback)(void);

   /* ERH AEC identifier */
   u8AecIdentifierType u8AecIdentifier;

   /* Inhibiting modes combination index */
   uint8 u8InhibIndex;

} stAutoTestConfigurationType ;

typedef struct
{
   /* offset (in number of ATM execution occurrences) */
   uint16 u16Period;

   /* offset (in number of ATM execution occurrences) */
   uint8 u8Offset;

   /* Test Index */
   uint8 u8TestIndex;

} stCyclicListEltType;

typedef struct
{
   /* Period (in number of ATM execution occurrences) */
   uint16 u16StepPeriod;

   /* Auto test type */
   uint8 u8Type;

   /* Test Index */
   uint8 u8TestIndex;

} stStartupEltType;
/* [COVERS: DSG_ATM_00014 , DSG_ATE_00035] */

/*************************************************************************
 Declaration of constants
*************************************************************************/

/*************************************************************************
Label: COD_ATM_00012
Object: This table contains the 
Type: stAutoTestConfigurationType 
Unit: None
Range : None
**************************************************************************/
#define ATM_AC_AutoTestManager_START_SEC_CONST_UNSPECIFIED
#include "ATM_AC_AutoTestManager_MemMap.h"
extern const u32ModeMaskType cau32InhibitingModes[KU8_NUMBER_OF_INHIBITING_MODES];
extern const stAutoTestConfigurationType castATMConfig[ATM_KU8_NB_OF_AUTOTEST];
extern const stStartupEltType castStartupSequentialList[ATM_KU8_NB_OF_STARTUP_AUTO_TESTS];
extern const stCyclicListEltType castStartupCyclicList[KU8_NB_OF_STARTUP_CYCLIC_ELTS];
extern const stCyclicListEltType castRunningCyclicList[KU8_NB_OF_RUNNING_CYCLIC_ELTS];
#define ATM_AC_AutoTestManager_STOP_SEC_CONST_UNSPECIFIED
#include "ATM_AC_AutoTestManager_MemMap.h"
/* [COVERS: DSG_ATM_00014] */

/*************************************************************************
Declaration of private functions
**************************************************************************/
#define ATM_AC_AutoTestManager_START_SEC_CODE
#include "ATM_AC_AutoTestManager_MemMap.h"
/* List of functions to be filled with specific process */
void  Cfg_SpecificFunction_Init_ATM(void);
void  Cfg_SpecificFunction_Shutdown_ATM(void);
void  Cfg_SpecificFunction_StartMain_ATM(void);
void  Cfg_SpecificFunction_EndMain_ATM(void);
#define ATM_AC_AutoTestManager_STOP_SEC_CODE
#include "ATM_AC_AutoTestManager_MemMap.h"

#endif /* I_ATM_PUBLIC */

/* end of file */

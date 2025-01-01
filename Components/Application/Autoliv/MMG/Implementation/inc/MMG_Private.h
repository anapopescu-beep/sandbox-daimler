/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) provided
by the component MMG.
These are globally visible.  
This file is intended to be included in a package header file; 
all components should include the package header file instead of this file.

Current revision: $Revision: 1.1.7.17 $
Checked in:       $Date: 2024/02/05 07:50:41CET $

*************************************************************************/

#ifndef MMG_Private_H
#define MMG_Private_H 1

#include "Std_Types.h"
#include "Nvp_Generated.h"

/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 * 		Indicates the index value corresponding to the MMG cycle modes which needs delay in table astDelayAfterCycleThrsandModes
 */
#define MMG_KU8_CYCLE_MODE_DELAY_INDEX          ((uint8)0)
/**
 * \brief
 * 		Indicates the index value corresponding to the MMG cycle modes which needs delay in table astDelayAfterCycleThrsandModes
 */
#define MMG_KU8_CYCLE_MODE_DELAY_UV_INDEX       ((uint8)1)
/**
 * \brief
 * 		Indicates the index value corresponding to the MMG cycle modes which needs delay in table astDelayAfterCycleThrsandModes
 */
#define MMG_KU8_NUMBER_OF_CYCLES_MODES_DELAYS   ((uint8)2)

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

/**
 * \brief
 * This macro is used in the MMG module to clear a running context
 * in the bitfield. Complement has to be updated at every write access.
 * The context shall never be written directly not using these macros,
   because it would corrupt the complement protection
 */
#define M_SET_MODE_MASK_OFF(mask) \
   U32_BIT_CLEAR (MMG_u32ModesStatus, (mask)); \
   U32_BIT_SET   (MMG_u32ModesStatusComplement, (mask))

/**
 * \brief
 * This macro is used in the MMG module to set a running context
 * in the bitfield. Complement has to be updated at every write access.
 * The context shall never be written directly not using these macros,
   because it would corrupt the complement protection
 */
#define M_SET_MODE_MASK_ON(mask) \
   U32_BIT_SET   (MMG_u32ModesStatus, (mask)); \
   U32_BIT_CLEAR (MMG_u32ModesStatusComplement, (mask))


/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/*!
 *  \brief Pointer to function callback
 *
 */
typedef void (* tSystemContextCallbackFct)  (void);

/*!
 *  \brief This structure describes the constant data of a system context
 *
 */
typedef struct
{
   tSystemContextCallbackFct pfModeCallback;
} MMG_stModeConfigurationType;

/*************************************************************************
Label:
Object: This structure contains the information needed to manage delays
for cycle activation MMG modes
Unit: None.
**************************************************************************/
/*!
 *  \brief This structure contains the information needed to manage delays
 *  for cycle activation MMG modes
 */
typedef struct
{
   uint16 u16DelayThrs;
   uint32 u32AssociatedMode;
} MMG_stModeDelayType;

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

#define MMG_AC_ModeManagement_START_SEC_VAR_32
#include "MMG_AC_ModeManagement_MemMap.h"

extern uint32 MMG_u32ModesStatus;
extern uint32 MMG_u32ModesStatusComplement;

extern boolean MMG_bVoltageStatusIsOk;
extern boolean MMG_bInternalStatusIsOk;
extern boolean MMG_bExtendedVoltageStatusIsOk;

#define MMG_AC_ModeManagement_STOP_SEC_VAR_32
#include "MMG_AC_ModeManagement_MemMap.h"

#define MMG_AC_ModeManagement_START_SEC_VAR_INIT_16
#include "MMG_AC_ModeManagement_MemMap.h"

extern uint16 MMG_u16MaxDelayAfterCycleActivation;

#define MMG_AC_ModeManagement_STOP_SEC_VAR_INIT_16
#include "MMG_AC_ModeManagement_MemMap.h"

#define MMG_AC_ModeManagement_START_SEC_VAR_INIT_UNSPECIFIED
#include "MMG_AC_ModeManagement_MemMap.h"

extern MMG_stModeDelayType MMG_astDelayAfterCycleThrsandModes[MMG_KU8_NUMBER_OF_CYCLES_MODES_DELAYS];

#define MMG_AC_ModeManagement_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MMG_AC_ModeManagement_MemMap.h"

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
#define MMG_AC_ModeManagement_START_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"

extern void mmg_PreSafe_Init(void);
extern void mmg_ManageModeDelays_ExecutedCycle(void);
extern void mmg_UpdateModeStatus_CriticalAutotestsNok(void);
extern void mmg_UpdateModeStatus_PowerVoltageUnstable(void);
extern void mmg_UpdateModeStatus_ExecutedCycleDelay(void);
extern void mmg_UpdateModeStatus_ExecutedCycle(void);
extern void mmg_UpdateModeStatus_ExecutedTensioningCycle(void);
extern void mmg_UpdateModeStatus_Cranking(void);
extern void mmg_UpdateModeStatus_NoHallEffectSensor(void);
extern void mmg_AvailabilityDataStatus(void);
extern void mmg_UpdateModeStatus_DefaultValues(void);
extern void mmg_UpdateModeStatus_PowerSupply_AllCycles(void);
extern void mmg_UpdateModeStatus_EcuDefective_AllCycles(void);
extern void mmg_UpdateModeStatus_EOLComfort_BSR(void);
extern void mmg_UpdateModeStatus_Temperature_EOL_KL30_TensioningCycles(void);
extern void mmg_UpdateModeStatus_EOL_LowForce_TensioningCycles(void);
extern void mmg_UpdateModeStatus_SignalReleaseInhibition(void);
extern void mmg_CheckIgnitionON(void);
extern void mmg_CheckCodingOfAPI(void);
extern void mmg_CheckBeltHandover(void);


#define MMG_AC_ModeManagement_STOP_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"

#endif   /* MMG_Private_H */ 

/******************************************************************************
End Of File
*****************************************************************************/

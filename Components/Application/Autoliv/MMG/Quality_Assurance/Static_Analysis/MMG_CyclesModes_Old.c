/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

 *******************************************************************************
C-File Template Version:
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
 ******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.2.16 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/MMG/Quality_Assurance/Static_Analysis/project.pj $
 */
/* PRQA S 0288 -- */

/**
 *  @defgroup MMG_CyclesModes.c MMG
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */
/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "common.h"
#include "Rte_MMG_AC_ModeManagement.h"
#include "MMG_Private.h"
#include "Nvp_Generated.h"
#include "Nvp_Cfg.h"
/******************************************************************************
MODULE DEFINES
 ******************************************************************************/

/**
 * \brief
 * 		Pre tensioning level 7 cycle
 */
#define MMG_KU8_CFG_LAST_PRE_TENSIONING_CYCLE     KU8_BELT_FUNCTION_17
/**
 * \brief
 * 		Belt Slack Reduction cycle
 */
#define MMG_KU8_CFG_BSR1_TENSIONING_CYCLE         KU8_BELT_FUNCTION_26
/**
 * \brief
 * 		Belt Slack Reduction cycle
 */
#define MMG_KU8_CFG_BSR3_TENSIONING_CYCLE         KU8_BELT_FUNCTION_28
/**
 * \brief
 * 		Haptic Warning 0 cycle
 */
#define MMG_KU8_CFG_HAPTIC_WARNING_10_CYCLE       KU8_BELT_FUNCTION_18
/**
 * \brief
 * 		 Haptic Warning 1 cycle
 */
#define MMG_KU8_CFG_HAPTIC_WARNING_41_CYCLE       KU8_BELT_FUNCTION_25
/**
 * \brief
 * 		 Production 0 cycle
 */
#define MMG_KU8_CFG_PRODUCTION_0_CYCLE            KU8_BELT_FUNCTION_33
/**
 * \brief
 * 		 Production 1 cycle
 */
#define MMG_KU8_CFG_PRODUCTION_1_CYCLE            KU8_BELT_FUNCTION_34
/**
 * \brief
 * 		 Init value of delay for MMG_KU32_MASK_BELTFUNCTIONS_DELAY
 * 		 and MMG_KU32_MASK_BELTFUNCTIONS_DELAY_UV modes
 */
#define MMG_KU16_TIMEOUT_INIT_VALUE ((uint16) 0xFFFF)

/**
 * \brief
 * 		 Number of Aecs which are able to inhibit and abort TENSIONING cycles
 */
#define MMG_KU8_NB_OF_INHIB_AEC_FOR_TENS_CYCLES            ((uint8) 3)
/**
 * \brief
 * 		 Index for High Temperature Autotest result
 */
#define MMG_KU8_IDX_TEMPERATURE_HIGH                       ((uint8) 0)
/**
 * \brief
 * 		 Index for Implausible Buckle Autotest result
 */
#define MMG_KU8_IDX_IMPL_BUCKLE_TENS                       ((uint8) 1)
/**
 * \brief
 * 		 Index for Timeout Buckle Autotest result
 */
#define MMG_KU8_IDX_TIMOEUT_BUCKLEK_TENS                   ((uint8) 2)


/*************************************************************************
Declaration of constants
 *************************************************************************/

/*************************************************************************
Declaration of types
 *************************************************************************/

/*************************************************************************
LOCAL variables declaration
 *************************************************************************/
/*************************************************************************
LOCAL variables declaration
 *************************************************************************/
#define MMG_AC_ModeManagement_START_SEC_VAR_INIT_16
#include "MMG_AC_ModeManagement_MemMap.h"
/**
 * \brief
 *		Variable which will be loaded, during MMG_Init, with the maximal value of delays configured in NVP
 * \remarks
 *		None.
 */
uint16 MMG_u16MaxDelayAfterCycleActivation = KU16_ZERO;
/**
 * \brief
 *		Counter to manage timeout for "Executed cycle" mode
 * \remarks
 *		None.
 */
static uint16 MMG_u16DelayToClearModeAfterCycle = MMG_KU16_TIMEOUT_INIT_VALUE;
/**
 * \brief
 *		Defined macro from C file.
 * \remarks
 *		None.
 */
#define MMG_AC_ModeManagement_STOP_SEC_VAR_INIT_16
#include "MMG_AC_ModeManagement_MemMap.h"

#define MMG_AC_ModeManagement_START_SEC_VAR_INIT_UNSPECIFIED
#include "MMG_AC_ModeManagement_MemMap.h"

/* Table defining delays associated to cycle execution MMG modes */  
MMG_stModeDelayType MMG_astDelayAfterCycleThrsandModes[MMG_KU8_NUMBER_OF_CYCLES_MODES_DELAYS] =
{                                                                                                      \
		{MMG_KU16_TIMEOUT_INIT_VALUE, MMG_KU32_MASK_BELTFUNCTIONS_DELAY},                                   \
		{MMG_KU16_TIMEOUT_INIT_VALUE, MMG_KU32_MASK_BELTFUNCTIONS_DELAY_UV},                                \
};

#define MMG_AC_ModeManagement_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MMG_AC_ModeManagement_MemMap.h"

/**************************************************************************
Private Functions: 
 **************************************************************************/

#define MMG_AC_ModeManagement_START_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"

/**
 * \brief
 *	    This is the executing mode function in charge of manages the �executed cycle with delay� modes.
 *
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void mmg_UpdateModeStatus_ExecutedCycleDelay(void)
{
	uint8 mmg_u8Index = KU8_ZERO;

	/* Check for all delays if timeout is reached */
	for(mmg_u8Index = KU8_ZERO; mmg_u8Index < MMG_KU8_NUMBER_OF_CYCLES_MODES_DELAYS; mmg_u8Index++)
	{
		/* If counter is below the threshold */
		/* [COVERS: DSG_MMG_0019] */
		if(MMG_u16DelayToClearModeAfterCycle <= MMG_astDelayAfterCycleThrsandModes[mmg_u8Index].u16DelayThrs)
		{
			/* Delay has elapse, deactivate the corresponding MMG mode */
			M_SET_MODE_MASK_OFF  (MMG_astDelayAfterCycleThrsandModes[mmg_u8Index].u32AssociatedMode);
		}
		else
		{
			/* Delay has not elapsed, activate the corresponding MMG mode */
			M_SET_MODE_MASK_ON  (MMG_astDelayAfterCycleThrsandModes[mmg_u8Index].u32AssociatedMode);
		}
	}
}


/**
 * \brief
 *	    This is the function in charge of managing the timers for the Executed Cycle modes.
 *
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void mmg_ManageModeDelays_ExecutedCycle(void)
{
	/* Current executed cycle */
	uint8 mmg_u8ExecutedCycle;
	uint32 mmg_u32ResetCauseMask;

	/* Reset cause */
	uint32 mmg_u32ResetCause = KU8_ZERO;

	/* Current pyro activation status */
	b8PyroActivationStatusType mmg_pb8PyroActivationStatus;

	/* Last interrupted cycle information */
	u8CycleNumberType mmg_u8LastInterruptedCycle = KU8_NO_CYCLE;

	/* Read reset cause */
	/* [COVERS: DSG_MMG_0043] */
	(void)Rte_Call_pclResetCause_GetResetCause(&mmg_u32ResetCause);

	/* Get current executed cycle */
	/* [COVERS: DSG_MMG_0044] */
	(void)Rte_Read_prrExecutedCycle_u8CycleNumber(&mmg_u8ExecutedCycle);

	/* Get current pyro activation status */
	/* [COVERS: DSG_MMG_0045] */
	(void)Rte_Call_pclPyroDevice_GetPyroActivationStatus(&mmg_pb8PyroActivationStatus);

	/* Get last interrupted cycle information */
	(void)Rte_Call_pclSystemContextManagement_GetLastTensionningState(&mmg_u8LastInterruptedCycle);

	/* Check if it is the first execution of this function */
	if(MMG_KU16_TIMEOUT_INIT_VALUE == MMG_u16DelayToClearModeAfterCycle)
	{
		/* Fill the mask with the "cold reset" causes */
		mmg_u32ResetCauseMask = KU32_POWER_ON_RESET_MASK | KU32_SW_RESET_MASK | KU32_WAKE_UP_EVENT_MASK;

		/* Check if reset cause is not a cold reset */
		if ( (KU32_ZERO == (mmg_u32ResetCause & mmg_u32ResetCauseMask       ))  ||
				(KU32_ZERO != (mmg_u32ResetCause & KU32_BATTERY_LOSS_MASK  ))
		)
		{
			/* If a cycle was interrupted by reset */
			if(KU8_NO_CYCLE != mmg_u8LastInterruptedCycle)
			{
				/* Initialize delay to NVP timeout */
				MMG_u16DelayToClearModeAfterCycle = MMG_u16MaxDelayAfterCycleActivation;
			}
			else
			{
				/* Reset delay */
				MMG_u16DelayToClearModeAfterCycle = KU16_ZERO;
			}
		}
		else
		{
			/* Reset delay */
			MMG_u16DelayToClearModeAfterCycle = KU16_ZERO;
		}
	}

	/* Check either if any cycle is currently executed */
	/* or if pyro is currently activated */
	else if ( (KU8_NO_CYCLE != mmg_u8ExecutedCycle) || (KB8_PYRO_DEVICE_ACTIVATED == mmg_pb8PyroActivationStatus))
	{
		/* Set delay to reactivate mode */
		MMG_u16DelayToClearModeAfterCycle = MMG_u16MaxDelayAfterCycleActivation;
	}

	/* No cycle is running -> check if the delay has expired */
	else if(KU8_ZERO != MMG_u16DelayToClearModeAfterCycle)
	{
		/* Delay has not expired -> decrement counter */
		MMG_u16DelayToClearModeAfterCycle--;
	}

	else
	{
		/* Delay has expired -> do nothing as counter has already reached zero */
	}
}

/**
 * \brief
 *	    This is the executing mode function in charge of manages the �executed cycle� mode.
 *
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void mmg_UpdateModeStatus_ExecutedCycle(void)
{
	/* Current executed cycle */
	uint8 mmg_u8ExecutedCycle;

	/* Current pyro activation status */
	b8PyroActivationStatusType mmg_pb8PyroActivationStatus;

	/* Get current executed cycle */
	/* [COVERS: DSG_MMG_0020,DSG_MMG_0036] */
	(void)Rte_Read_prrExecutedCycle_u8CycleNumber(&mmg_u8ExecutedCycle);

	/* Get current pyro activation status */
	/* [COVERS: DSG_MMG_0020, DSG_MMG_0038] */
	(void)Rte_Call_pclPyroDevice_GetPyroActivationStatus(&mmg_pb8PyroActivationStatus);

	/* Check either if any cycle is currently executed */
	/* or if pyro is currently activated */
	if ( (KU8_NO_CYCLE != mmg_u8ExecutedCycle) || (KB8_PYRO_DEVICE_ACTIVATED == mmg_pb8PyroActivationStatus))
	{
		/* Mode is set */
		M_SET_MODE_MASK_ON  (MMG_KU32_MASK_BELTFUNCTIONS);
	}
	else
	{
		/* Mode is cleared */
		M_SET_MODE_MASK_OFF   (MMG_KU32_MASK_BELTFUNCTIONS);
	}
}

/**
 * \brief
 *	    This is the executing mode function in charge of manages the �executed tensioning cycle� mode.
 *
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void mmg_UpdateModeStatus_ExecutedTensioningCycle(void)
{
	/* Current executed cycle */
	uint8 mmg_u8ExecutedCycle = KU8_NO_CYCLE;

	/* Get current executed cycle */
	/* [COVERS: DSG_MMG_0037] */
	(void)Rte_Read_prrExecutedCycle_u8CycleNumber(&mmg_u8ExecutedCycle);

	/* Check if a tensioning cycle is currently executed */
	/* Check if either PRE or BSR or BPA or HWA or PRO is currently executed */
	if (    (mmg_u8ExecutedCycle <= MMG_KU8_CFG_LAST_PRE_TENSIONING_CYCLE)
			|| ( (MMG_KU8_CFG_BSR1_TENSIONING_CYCLE <= mmg_u8ExecutedCycle) && (MMG_KU8_CFG_BSR3_TENSIONING_CYCLE >= mmg_u8ExecutedCycle))
			|| ( (MMG_KU8_CFG_HAPTIC_WARNING_10_CYCLE <= mmg_u8ExecutedCycle) && (MMG_KU8_CFG_HAPTIC_WARNING_41_CYCLE >= mmg_u8ExecutedCycle))
			|| ((MMG_KU8_CFG_PRODUCTION_0_CYCLE == mmg_u8ExecutedCycle) || (MMG_KU8_CFG_PRODUCTION_1_CYCLE == mmg_u8ExecutedCycle))
	)
	{
		/* A tensioning cycle is being executed */
		M_SET_MODE_MASK_ON  (MMG_KU32_MASK_TENSIONING);
	}
	else
	{
		/* NO tensioning cycle is being executed */
		M_SET_MODE_MASK_OFF   (MMG_KU32_MASK_TENSIONING);
	}
}

/**
 * \brief
 *	    This is the executing mode function in charge of manages the inhibition of all cycles by Power supply
 *
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void mmg_UpdateModeStatus_PowerSupply_AllCycles(void)
{
	uint8 u8ModeStatusIsOk;
	uint16 u16Voltage = KU16_MAX;

	/* Initialize status */
	u8ModeStatusIsOk = KU8_TRUE;

	/* Get instant voltage status */
	(void)Rte_Call_pclKL30_Get(&u16Voltage);

	/* Verify normal voltage range */
	/* [COVERS: DSG_MMG_0022] */
	if( (NVP_stVehicleEquipmentData.Undervoltage >= u16Voltage ) ||
			(NVP_stVehicleEquipmentData.Overvoltage <= u16Voltage) )
	{
		u8ModeStatusIsOk = KU8_FALSE;
	}
	else
	{
		/* Do nothing */
		/* As Context status has been initialized to TRUE at start of function */
	}


	/* Check local context status */
	if(KU8_TRUE == u8ModeStatusIsOk)
	{
		M_SET_MODE_MASK_OFF (MMG_KU32_MASK_AEC_INHIB_ALL_CYCLES);
	}
	else
	{
		/* Outside range*/
		M_SET_MODE_MASK_ON  (MMG_KU32_MASK_AEC_INHIB_ALL_CYCLES);
	}
}
/**
 * \brief
 *	    This is the executing mode function in charge of inhibitiing release profile by customer signals
 *
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void mmg_UpdateModeStatus_SignalReleaseInhibition(void)
{
	uint8 u8SignalReleaseInhibition = KU8_FALSE;
	/* [COVERS: DSG_MMG_0122] */
	(void)Rte_Read_prrCustomerSpecific_b8SignalRelInhibition(&u8SignalReleaseInhibition);

	/* Check local context status */
	if(KU8_TRUE == u8SignalReleaseInhibition)
	{   /* [COVERS: DSG_MMG_0113] */
		M_SET_MODE_MASK_ON (MMG_KU32_MASK_SIGNAL_RELEASE_INHIBITION);
	}
	else
	{
		/* Outside range*/
		M_SET_MODE_MASK_OFF  (MMG_KU32_MASK_SIGNAL_RELEASE_INHIBITION);
	}
}
/**
 * \brief
 *	    This is the executing mode function in charge of manages the inhibition of all cycles by ECU defective
 *
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void mmg_UpdateModeStatus_EcuDefective_AllCycles(void)
{
	uint8 u8ModeStatusIsOk;
	uint32 u32AecStatus_ECUDefective = KU32_ZERO;
	uint32 u32AECGroupStatus;

	/* Current pyro activation status */
	b8PyroActivationStatusType pb8PyroActivationStatus = KB8_PYRO_DEVICE_NOT_ACTIVATED;

	/* Initialize status */
	u8ModeStatusIsOk = KU8_TRUE;

	/* Get AEC group status */
	/* [COVERS: DSG_MMG_0023, DSG_MMG_0024] */
	(void)Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);

	/* Get current pyro activation status */
	/* [COVERS: DSG_MMG_0023] */
	(void)Rte_Call_pclPyroDevice_GetPyroActivationStatus(&pb8PyroActivationStatus);

	/* Get EOL defective aec status */
	u32AecStatus_ECUDefective = (u32AECGroupStatus & (KU32_AEC_GROUP_MASK_HARDWARE | KU32_AEC_GROUP_MASK_MOTOR));

	/* Check if AEC is currently qualified */
	if( (KU32_ZERO != u32AecStatus_ECUDefective) || (KB8_PYRO_DEVICE_ACTIVATED == pb8PyroActivationStatus) )
	{
		/* If Auto Test is failed, remember the context becomes Nok */
		u8ModeStatusIsOk = KU8_FALSE;
	}
	else
	{
		/* Do nothing */
		/* As Context status has been initialized to TRUE at start of function */
	}


	/* Check local context status */
	if(KU8_TRUE == u8ModeStatusIsOk)
	{
		/* No DTC is qualified => no inhibition */
		M_SET_MODE_MASK_OFF (MMG_KU32_MASK_AEC_ECU_DEFECT_ALL_CYCLES);
	}
	else
	{
		/* At least one DTC is qualified => inhibition*/
		M_SET_MODE_MASK_ON  (MMG_KU32_MASK_AEC_ECU_DEFECT_ALL_CYCLES);
	}
}

/**
 * \brief
 *	    This is the executing mode function in charge of manages the inhibition of BSR by EOL Comfort
 *
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void mmg_UpdateModeStatus_EOLComfort_BSR(void)
{
	uint8 u8ModeStatusIsOk;
	uint32 u32AecStatus_EOLComfort = KU32_ZERO;
	uint32 u32AECGroupStatus;

	/* Initialize status */
	u8ModeStatusIsOk = KU8_TRUE;

	/* Get AEC Group status from ERH */
	(void)Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);

	/* Get EOL comfort aec status */
	u32AecStatus_EOLComfort = (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT);

	/* Check if AEC is currently qualified */
	/* [COVERS: DSG_MMG_0032] */
	if(KU32_ZERO != u32AecStatus_EOLComfort)
	{
		/* If AEC is qualified, remember the context becomes Nok */
		u8ModeStatusIsOk = KU8_FALSE;
	}
	else
	{
		/* Do nothing */
		/* As Context status has been initialized to TRUE at start of function */
	}

	/* Check local context status */
	if(KU8_TRUE == u8ModeStatusIsOk)
	{
		/* No DTC is qualified => no inhibition */
		M_SET_MODE_MASK_OFF (MMG_KU32_MASK_EOL_COMFORT);
	}
	else
	{
		/* At least one DTC is qualified => inhibition*/
		M_SET_MODE_MASK_ON  (MMG_KU32_MASK_EOL_COMFORT);
	}
}
/**
 * \brief
 *	    This is the executing mode function in charge of manages the inhibition of tensioning cycles by
 *        -Temperature high
 *        -EOL Low and High
 *        -KL30 OV and UV
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
/* [COVERS: DSG_MMG_0114] */
void mmg_UpdateModeStatus_EOL_LowForce_TensioningCycles(void)
{
	uint8 u8ModeStatusIsOk;
	uint32 u32AECGroupStatus;

	/* Initialize status */
	u8ModeStatusIsOk = KU8_TRUE;

	if (KU8_TRUE == u8ModeStatusIsOk)
	{
		/* Get AEC Group status from ERH */
		(void)Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);

		if( KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_LOW_HIGH) )
		{
			/* If AEC is qualified, remember the context becomes Nok */
			u8ModeStatusIsOk = KU8_FALSE;
		}
	}

	/* Check local context status */
	if(KU8_TRUE == u8ModeStatusIsOk)
	{
		/* No DTC is qualified => no inhibition */
		M_SET_MODE_MASK_OFF (MMG_KU32_MASK_EOL_LOW_FORCE);
	}
	else
	{
		/* At least one DTC is qualified => inhibition*/
		M_SET_MODE_MASK_ON  (MMG_KU32_MASK_EOL_LOW_FORCE);
	}
}
/**
 * \brief
 *	    This is the executing mode function in charge of manages the inhibition of tensioning cycles by 
 *        -Temperature high 
 *        -EOL Low and High 
 *        -KL30 OV and UV
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
/* [COVERS: DSG_MMG_0040] */
void mmg_UpdateModeStatus_Temperature_EOL_KL30_TensioningCycles(void)
{
	uint8 u8ModeStatusIsOk;
	uint32 u32AecStatus_TensioningCycles[MMG_KU8_NB_OF_INHIB_AEC_FOR_TENS_CYCLES];
	uint32 u32AECGroupStatus;
	uint16 u16Voltage;

	/* Initialize status */
	u8ModeStatusIsOk = KU8_TRUE;

	/* Get AEC Group status from ERH */
	(void)Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);

	/* Get Temperature high aec status */
	u32AecStatus_TensioningCycles[MMG_KU8_IDX_TEMPERATURE_HIGH] = (u32AECGroupStatus & KU32_AEC_GROUP_MASK_SELF_PROTECTION);
	/* Get implausible buckle aec status */
	u32AecStatus_TensioningCycles[MMG_KU8_IDX_IMPL_BUCKLE_TENS] = (u32AECGroupStatus & KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_BUCKLE_ORC);
	/* Get timeout buckle status */
	u32AecStatus_TensioningCycles[MMG_KU8_IDX_TIMOEUT_BUCKLEK_TENS] = (u32AECGroupStatus & KU32_AEC_GROUP_MASK_TIMEOUT_BUCKLE);

	/* Get instant voltage status */
	(void)Rte_Call_pclKL30_Get(&u16Voltage);

	/* Check if AEC is currently qualified */
	/* [COVERS: DSG_MMG_0025, DSG_MMG_0026, DSG_MMG_0027, DSG_MMG_0028, DSG_MMG_0029, DSG_MMG_0030, DSG_MMG_0031] */
	if( (u32AecStatus_TensioningCycles[MMG_KU8_IDX_TEMPERATURE_HIGH] != KU32_ZERO) ||
			(u32AecStatus_TensioningCycles[MMG_KU8_IDX_IMPL_BUCKLE_TENS] != KU32_ZERO)     ||
			(u32AecStatus_TensioningCycles[MMG_KU8_IDX_TIMOEUT_BUCKLEK_TENS] != KU32_ZERO)  ||
			(NVP_stVehicleEquipmentData.UndervoltageAbort >= u16Voltage) ||
			(NVP_stVehicleEquipmentData.OvervoltageAbort <= u16Voltage)  )
	{
		/* If AEC is qualified, remember the context becomes Nok */
		u8ModeStatusIsOk = KU8_FALSE;
	}
	else
	{
		/* Do nothing */
		/* As Context status has been initialized to TRUE at start of function */
	}

	/* Check local context status */
	if(KU8_TRUE == u8ModeStatusIsOk)
	{
		/* No DTC is qualified => no inhibition */
		M_SET_MODE_MASK_OFF (MMG_KU32_MASK_AEC_INHIB_TENSIONING_CYCLES);
	}
	else
	{
		/* At least one DTC is qualified => inhibition*/
		M_SET_MODE_MASK_ON  (MMG_KU32_MASK_AEC_INHIB_TENSIONING_CYCLES);
	}
}

#define MMG_AC_ModeManagement_STOP_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"
/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/

/******************************************************************************
End Of File
 *****************************************************************************/

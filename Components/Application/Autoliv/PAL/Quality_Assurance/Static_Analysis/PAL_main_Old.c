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
$Revision: 1.1.2.8 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/PAL/Quality_Assurance/Static_Analysis/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup PAL_main.c PAL
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_PAL_AC_PowerAbstractionLayer.h"
#include "common.h"
#include "PAL_private.h"
#include "PAL_public.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_START_SEC_VAR_8
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"

/* QAC_WARNING S 2022 1 */ /* Initialized by PAL_Init */
/**
 * \brief
 *		Global data used to set the state machine status for the PAL component
* \remarks
 *		None.
 */
static uint8       PAL_u8RequestedMode;
/**
 * \brief
 *		Global data used to know the state machine status for the PAL component
* \remarks
 *		None.
 */
uint8    PAL_u8ModeState;
/**
 * \brief
 *		Timer used to set the state machine status for the PAL component
* \remarks
 *		None.
 */
uint8    PAL_u8FreeWheelingTimer;

/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_STOP_SEC_VAR_8
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_START_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"
/**
 * \brief
 *	    Init function function for the PAL component
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
void PAL_Init ( void )
{
   /* State machine initialization
    * By default after a reset : the power stage shall be checked
    * */
   /* [COVERS: DSG_PAL_0001] */
   PAL_u8ModeState = PAL_KU8_DIAGNOSTIC_MODE_STATE;
   /* [COVERS: DSG_PAL_0002] */
   PAL_u8RequestedMode = PAL_KU8_INIT_MODE_STATE;
   /* [COVERS: DSG_PAL_0003] */
   PAL_u8FreeWheelingTimer = PAL_CFG_FREEWHEELING_TIME;

   /* Execute Configuration part of the initialization */
   /* [COVERS: DSG_PAL_0004] */
   pal_Cfg_Init ();

   /* [COVERS: DSG_PAL_0005] */
   Rte_Call_pclPwmServices_EnablePWM(PWM_KU8_CH_ID_HB_P);
   Rte_Call_pclPwmServices_EnablePWM(PWM_KU8_CH_ID_HB_N);
}

/**
 * \brief
 *	    Periodic main function for the PAL component
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
/* [COVERS: DSG_PAL_0006] */
void PAL_runMainFunction ( void )
{
	boolean pal_bModeStatus;

	/* Update the free wheeling counter */
	if ( PAL_CFG_PERIODIC_FCT_CALL <= PAL_u8FreeWheelingTimer )
	{
		PAL_u8FreeWheelingTimer -= PAL_CFG_PERIODIC_FCT_CALL;
	}
	else
	{
		PAL_u8FreeWheelingTimer = KU8_ZERO;
	}

	/* Check if a change mode request has been received from another SW/C */
	if ( 0u != PAL_u8RequestedMode )
	{
		/* Apply the new mode directly */
		PAL_u8ModeState = PAL_u8RequestedMode;
		/* Reset the request bitfield */
		PAL_u8RequestedMode = KU8_ZERO;
	}
	else
	{
		/* No mode request received */
	}


	/* Check running mode for PAL SW/C */
	switch (PAL_u8ModeState)
	{
	case PAL_KU8_DIAGNOSTIC_MODE_STATE:
		/* Startup state that shall be used to check the HW components before
		 * giving the control to the Belt functions
		 * Especially Unit tests on Mosfets / Caps : OCAT / Boost / High Side Switch
		 * */
		Rte_Call_pclModeManagement_CheckModeStatus(MMG_KU32_MASK_CRITICAL_AT_NOK, &pal_bModeStatus);

		if (KU8_MODE_STATUS_OFF == pal_bModeStatus)
		{
			/* Allow belt function activation since critical autotests are passed */
			/* [COVERS: DSG_PAL_0007] */
			PAL_u8ModeState = PAL_KU8_IDLE_MODE_STATE;
		}
		else
		{
			/* Critical auto test not yet performed or failed */
		}

		break;
	case PAL_KU8_IDLE_MODE_STATE:
		/* Normal state entered in case of all HW critical auto tests have
		 * successed
		 * In this state the motor is not activated : the motor is not turning
		 * Auto test based on voltage on motor connectors can be executed
		 * */
		if ( KU8_ZERO != PAL_u8FreeWheelingTimer )
		{
			/* a Motor activation order has been received since the last function call */
			/* [COVERS: DSG_PAL_0008] */
			PAL_u8ModeState = PAL_KU8_ACTIVATION_MODE_STATE;
		}
		else
		{
			/* Refresh the disable pin for power stage */
			PAL_DisablePowerStage();
		}
		break;
	case PAL_KU8_ACTIVATION_MODE_STATE:
		/* State active in case of all critical auto tests have been passed
		 * And a motor activation has been received from belt function stack.
		 * All auto test controlling the motor command consign and feedback can be
		 * executed
		 * */
		if ( KU8_ZERO == PAL_u8FreeWheelingTimer )
		{
			/* No Motor activation order has been received since PAL_CFG_FREEWHEELING_TIME ms */
			/* [COVERS: DSG_PAL_0009] */
			PAL_u8ModeState = PAL_KU8_IDLE_MODE_STATE;
			PAL_DisablePowerStage();
		}
		else
		{
			/* Nothing to do */
		}
		break;
	case PAL_KU8_OFF_MODE_STATE:
		/* State active in case of Shut down request or in case of critical auto test
		 * have failed during startup phase
		 * No ways to return from this test without a reset and a new MCU startup.
		 * */
		/* [COVERS: DSG_PAL_0010] */
		break;
	default:
		/* Should never occur
		 * By default : apply the same strategy as for PAL_KU8_OFF_MODE_STATE
		 * */
		break;
	}

}
/**
 * \brief
 *		Defined macro from C file.
 */
#define PAL_AC_PowerAbstractionLayer_STOP_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"

/* QAC_WARNING S 3417 -- */ /* QAC warning due to comma operator into RTE macro */
/* QAC_WARNING S 3426 -- */ /* QAC does not recognize RTE macros */

/******************************************************************************
End Of File
*****************************************************************************/


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
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.5.2.57 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/CIL/Implementation/src/project.pj $
 */

/**
 *  This is a new created group, this will create a new man3 file with 
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file. 
 */

/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "Rte_CIL_AC_CommunicationInteractionLayer.h"
#include "Appl_Cbk.h"
#include "Cdd_MBBL_EcuStatHandler.h"
#include "Nvp_Cfg.h"
#include "CIL.h"

/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
/**
 * \brief
 * 		RBTM Tgl signal Toggle zero value
 */
#define KB_CIL_RBTM_TGL_SIGNAL_TGL_ZERO         ((boolean) 0x00)
/**
 * \brief
 * 		RBTM Tgl signal Toggle one value
 */
#define KB_CIL_RBTM_TGL_SIGNAL_TGL_ONE          ((boolean) 0x01)
/**
 * \brief
 * 		Macro used for bit clearing inhibition status
 */
#define CIL_SET_FCT_COND_MASK_OFF(mask)           U16_BIT_CLEAR(cil_u16Fct_Precond, (mask))
/**
 * \brief
 * 		Macro used for bit setting inhibition status
 */
#define CIL_SET_FCT_COND_MASK_ON(mask)            U16_BIT_SET(cil_u16Fct_Precond, (mask))
/**
 * \brief
 * 		Index of inhibit because of DTC for PRE-safe cycles
 */
#define KU8_CIL_InhibitionAfterORC            (1024u)
/**
 * \brief
 * 		Index of inhibit because of Impact X or Y signals
 */
#define KU8_CIL_InhibitionOfImpactX             (256u)
/**
 * \brief
 * 		Macro used for setting hardware failure DTCs
 */
#define CIL_KU32_AEC_MASK_HW_FAILURE                (KU32_AEC_GROUP_MASK_HARDWARE | KU32_AEC_GROUP_MASK_MOTOR)
/**
 * \brief
 * 		Macro used for setting DTCs with active warning indicator
 */
#define CIL_KU32_AEC_MASK_WARNING_INDICATOR         (KU32_AEC_GROUP_MASK_HARDWARE | KU32_AEC_GROUP_MASK_MOTOR | KU32_AEC_GROUP_MASK_EOL_LOW_HIGH | KU32_AEC_GROUP_MASK_SELF_PROTECTION | KU32_AEC_GROUP_MASK_NVM | KU32_AEC_GROUP_MASK_STEERING_CONFIG | KU32_AEC_GROUP_MASK_TIMEOUT_PRESAFE | KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_PRESAFE | KU32_AEC_GROUP_MASK_TIMEOUT_BUCKLE | KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_BUCKLE_ORC | KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_IGNITION)

#define KU32_CIL_ALLPROFILES           (67108863u)
#define CIL_KU8_PRECOND_MASK_BIT0           ((uint8) 0x01)
#define CIL_KU8_PRECOND_MASK_BIT2           ((uint8) 0x04)
#define CIL_KU8_PRECOND_MASK_BIT3           ((uint8) 0x08)
#define CIL_KU8_PRECOND_MASK_BIT4           ((uint8) 0x10)
#define CIL_KU8_PRECOND_MASK_BIT5           ((uint8) 0x20)
#define CIL_KU8_PRECOND_MASK_BIT6           ((uint8) 0x40)
/******************************************************************************
MODULE TYPES
 ******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 ******************************************************************************/

/******************************************************************************
DEFINITION OF GLOBAL VARIABLES
 ******************************************************************************/
/**
 * \brief
 *		This variable is used to store CAN signal RBTM_FL_Tgl_Rq_ST3 or signal RBTM_FR_Tgl_Rq_ST3
 * \remarks
 *		None.
 */
DC_BOOL CIL_bRBTMTgl = KB_CIL_RBTM_TGL_SIGNAL_TGL_ZERO;
/**
 * \brief
 *		This variable is used to store CAN signal Active level
 * \remarks
 *		None.
 */
/* [COVERS: DSG_CIL_0137] */
c06_RBTM_Lvl_Stat CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_SNA;
/**
 * \brief
 *		This variable is used to store CAN signal Active Client
 * \remarks
 *		None.
 */
/* [COVERS: DSG_CIL_0072, DSG_CIL_0074] */
c04_RBTM_ActvClient CIL_u8Actv_Client = I_C04_RBTM_ACTVCLIENT_SNA;
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 ******************************************************************************/
/**
 * \brief
 *		This variable is used to store CAN signal Fct preconditions
 * \remarks
 *		None.
 */
/* [COVERS: DSG_CIL_0132] */
LOCAL c10_RBTM_Fct_Precond cil_u16Fct_Precond = KU16_ZERO;
/**
 * \brief
 *		This variable is used to store CAN signal RBTM_FL_Disp_Rq_ST3 or signal RBTM_FR_Disp_Rq_ST3
 * \remarks
 *		None.
 */
LOCAL c02_Presf_Disp_Rq cil_u8RBTMDisp = I_C02_PRESF_DISP_RQ_IDLE;
/**
 * \brief
 *		This variable is used to store the release status
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8ReleaseHappens = KU8_FALSE;

/**
 * \brief
 *		This variable is used to store the tensioning status
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8TensioningStarted2 = KU8_FALSE;

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
/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_START_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/**
 * \brief
 *     Function used to write the Presafe Display signal
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
LOCAL void cil_ManagePresfDisplay(void)
{
	uint8 u8PresafeDisplay = KU8_FALSE;
	uint32 u32AECGroupStatus;

	Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);

	(void)Rte_Read_prrPresafeDisplay_b8TriggerPreSafeRequestStatus(&u8PresafeDisplay);

	/* [COVERS: DSG_CIL_0286] */
    if (KU8_ZERO == NVP_stVehicleEquipmentData.DisplayMsgActivation)
	{
		/* [COVERS: DSG_CIL_0285] */
	    if((KU8_TRUE == u8PresafeDisplay)||(KU32_ZERO != (u32AECGroupStatus & CIL_KU32_AEC_MASK_WARNING_INDICATOR)))
		{
			cil_u8RBTMDisp = I_C02_PRESF_DISP_RQ_SRV_DISP_RQ;
		}
		else
		{
			/* [COVERS: DSG_CIL_0024] */
			cil_u8RBTMDisp = I_C02_PRESF_DISP_RQ_IDLE;
		}
	}
	else
	{
		cil_u8RBTMDisp = I_C02_PRESF_DISP_RQ_IDLE;
	}

	/* Send the output signals value depending on the side allocation */
	if(KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION)
	{
		/* Write RBTM_FL_Disp_Rq_ST3 signal for left side */
		/* [COVERS: DSG_CIL_0012, DSG_CIL_0022] */
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3(cil_u8RBTMDisp);
	}
	else if(KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)
	{
		/* Write RBTM_FR_Disp_Rq_ST3 signal for right side */
		/* [COVERS: DSG_CIL_0013, DSG_CIL_0023] */
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3(cil_u8RBTMDisp);
	}
	else
	{
		/* Should not be reached */
	}
}
/**
 * \brief
 *     Function used to write the Fct Precondition signal
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/

/* [COVERS: DSG_CIL_0124] */
LOCAL void cil_ManageFctPrecondSignal(void)
{
	boolean bPrecondBitSix = B_FALSE;
	uint32 u32AECGroupStatus = KU16_ZERO;
	uint16 u16Voltage = KU16_MAX;
	(void)Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);

	/*bit0*/
	if (I_C02_BCKL_SW_STAT_OK == Rte_IrvRead_CIL_runAppliToCAN_u8BuckleStatus())
	{
		CIL_SET_FCT_COND_MASK_OFF(c10_RBTM_Fct_Precond_Seatbelt_not_buckled_BflMask);
	}
	else
	{
		/* [COVERS: DSG_CIL_0133]*/
		CIL_SET_FCT_COND_MASK_ON(c10_RBTM_Fct_Precond_Seatbelt_not_buckled_BflMask);
	}

	/* bit1 */
	/* [COVERS: DSG_CIL_0265] */
	/*bit 1 will always be zero. */

	/* bit 2 */
	if (KU32_ZERO != (u32AECGroupStatus&KU32_AEC_GROUP_MASK_SELF_PROTECTION))
	{
		/* [COVERS: DSG_CIL_0134] */
		CIL_SET_FCT_COND_MASK_ON(c10_RBTM_Fct_Precond_Overtemperature_BflMask);
	}
	else
	{
		CIL_SET_FCT_COND_MASK_OFF(c10_RBTM_Fct_Precond_Overtemperature_BflMask);
	}

	/* bit 3*/
	/* [COVERS: DSG_CIL_0198] */
    if (KU32_ZERO != (u32AECGroupStatus & CIL_KU32_AEC_MASK_HW_FAILURE))
	{
		CIL_SET_FCT_COND_MASK_ON (c10_RBTM_Fct_Precond_Internal_failure_BflMask);
	}
	else
	{
		CIL_SET_FCT_COND_MASK_OFF (c10_RBTM_Fct_Precond_Internal_failure_BflMask);
	}

    /* bit 4*/
	/* Get instant voltage status */
    Rte_Call_pclKL30_V_Get(&u16Voltage);
	if( (KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_OVER_VO_TENS)) ||
			(KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_UNDER_VO_TENS)) ||
			(NVP_stVehicleEquipmentData.Undervoltage >= u16Voltage ) ||
					(NVP_stVehicleEquipmentData.Overvoltage <= u16Voltage))
	{
		/* [COVERS: DSG_CIL_0138] */
		CIL_SET_FCT_COND_MASK_ON(c10_RBTM_Fct_Precond_Under_overvoltage_BflMask);
	}
	else
	{
		CIL_SET_FCT_COND_MASK_OFF(c10_RBTM_Fct_Precond_Under_overvoltage_BflMask);
	}

	/* bit 5 */
	if( (KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_TIMEOUT_BUCKLE)) ||
			(KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_BUCKLE_ORC)) ||
			(KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_API)) ||
			(KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_TIMEOUT_API)) ||
			(I_C02_BCKL_SW_STAT_SNA == cil_u8BcklSwStatSignal) ||
			(I_C02_BCKL_SW_STAT_FLT == cil_u8BcklSwStatSignal) ||
			(I_C06_RBTM_LVL_RQ_SNA == cil_stAPIInterface.RBTMFL_SP_Lvl_Rq_ST35) ||
			(I_C06_RBTM_LVL_RQ_SNA == cil_stAPIInterface.RBTMFR_SP_Lvl_Rq_ST35))
	{
		/* [COVERS: DSG_CIL_0149] */
		CIL_SET_FCT_COND_MASK_ON(c10_RBTM_Fct_Precond_Communication_error_BflMask);
	}
	else
	{
		CIL_SET_FCT_COND_MASK_OFF(c10_RBTM_Fct_Precond_Communication_error_BflMask);
	}

	/* bit 6 */
	if( (KU8_TRUE == Rte_IrvRead_CIL_runAppliToCAN_u8FctPrecond_ProfileNotImplemented())||
			(KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_LOW_HIGH))  )
	{
		/* [COVERS: DSG_CIL_0150] */
		CIL_SET_FCT_COND_MASK_ON(c10_RBTM_Fct_Precond_Profile_not_available_BflMask);
	}
	else if ( (KU8_NO_CYCLE != cil_u8APIActivationRequest) && (I_C06_RBTM_LVL_STAT_NONE != CIL_u8Actv_Lvl) )
	{/* [COVERS: DSG_CIL_0290] */
		if ( (KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) || (KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_MAX))
			|| (KU8_ZERO != NVP_stVehicleEquipmentData.APIActivation) || (KU32_ZERO != (NVP_stVehicleEquipmentData.PreSafeCycleActivation & KU32_CIL_ALLPROFILES)) )
		{
			CIL_SET_FCT_COND_MASK_ON(c10_RBTM_Fct_Precond_Profile_not_available_BflMask);

		}
		else
		{
			CIL_SET_FCT_COND_MASK_OFF(c10_RBTM_Fct_Precond_Profile_not_available_BflMask);
		}
	}
	else
	{
		CIL_SET_FCT_COND_MASK_OFF(c10_RBTM_Fct_Precond_Profile_not_available_BflMask);
	}

	/* bit 7 */

	/* [COVERS: DSG_CIL_0289] */


	if(KU8_NO_CYCLE != cil_u8APIActivationRequest)
	{
		if  ( (I_C06_RBTM_LVL_STAT_REJECTED == CIL_u8Actv_Lvl) ||
			   (I_C04_RBTM_ACTVCLIENT_SERVICE_PROVIDER != CIL_stManagedCycle.u8RequestSource) )
		{
			if( (CIL_KU8_PRECOND_MASK_BIT0 == (CIL_KU8_PRECOND_MASK_BIT0 & cil_u16Fct_Precond)) || (CIL_KU8_PRECOND_MASK_BIT2 == (CIL_KU8_PRECOND_MASK_BIT2 & cil_u16Fct_Precond)) ||
					(CIL_KU8_PRECOND_MASK_BIT3 ==(CIL_KU8_PRECOND_MASK_BIT3 & cil_u16Fct_Precond)) || (CIL_KU8_PRECOND_MASK_BIT4 ==(CIL_KU8_PRECOND_MASK_BIT4 & cil_u16Fct_Precond))
					||(CIL_KU8_PRECOND_MASK_BIT5 ==(CIL_KU8_PRECOND_MASK_BIT5 & cil_u16Fct_Precond))||(CIL_KU8_PRECOND_MASK_BIT6 ==(CIL_KU8_PRECOND_MASK_BIT6 & cil_u16Fct_Precond)) )
			{
				CIL_SET_FCT_COND_MASK_OFF(c10_RBTM_Fct_Precond_Other_BflMask);
			}
			else
			{
				CIL_SET_FCT_COND_MASK_ON(c10_RBTM_Fct_Precond_Other_BflMask);
			}
		}
		else
		{
			CIL_SET_FCT_COND_MASK_OFF(c10_RBTM_Fct_Precond_Other_BflMask);
		}
	}

	else
	{
		CIL_SET_FCT_COND_MASK_OFF(c10_RBTM_Fct_Precond_Other_BflMask);
	}

	/* Send the output signals value depending on the side allocation */
	if(KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION)
	{
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35(cil_u16Fct_Precond);
	}
	else if(KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)
	{
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35(cil_u16Fct_Precond);
	}
	else
	{
		/* Should not be reached */
	}
}

/**
 * \brief
 *     Function used to write the Active client request source signal
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
/* [COVERS: DSG_CIL_0076] */
LOCAL void cil_ManageActiveClientRequestSource(const uint8 u8ExecutedCycle,const uint8 u8SelectedCycle)
{
	uint8 u8DiagRequestedCycle = KU8_NO_CYCLE;

	Rte_Call_pclDiagRequestCycle_GetDiagRequestCycle(&u8DiagRequestedCycle);

	/* Manage output signal Active CLient - Request Source */
	if (I_C04_RBTM_ACTVCLIENT_NONE == Rte_IrvRead_CIL_runAppliToCAN_u8RequestSource())
	{
		/* [COVERS: DSG_CIL_0076] */
		if( (KU8_NO_CYCLE != u8DiagRequestedCycle) && ( (u8DiagRequestedCycle == u8ExecutedCycle) || (u8DiagRequestedCycle == u8SelectedCycle)) )
		{
			CIL_u8Actv_Client = I_C04_RBTM_ACTVCLIENT_OTHER;
		}
		else if (KU8_CIL_BSR_CYCLE == u8SelectedCycle)
		{
			/* [COVERS: DSG_CIL_0076] */
			CIL_u8Actv_Client = I_C04_RBTM_ACTVCLIENT_BELTSLACK_REDUCTION;
		}
		else if(KU8_CIL_SMO_CYCLE == u8ExecutedCycle)
		{
			/* Nothing to do */
		}

		else if ((KU8_TRUE == cil_u8TensioningStarted2) && (KU8_FALSE == cil_u8ReleaseHappens))
		{
			/* nothing to do */
		}
		else if (KU8_NO_CYCLE != u8ExecutedCycle)
		{
			/* [COVERS: DSG_CIL_0076] */
			CIL_u8Actv_Client = I_C04_RBTM_ACTVCLIENT_OTHER;
		}
		else
		{
			/* [COVERS: DSG_CIL_0073] */
			CIL_u8Actv_Client = I_C04_RBTM_ACTVCLIENT_NONE;
		}
	}
	else
	{
		if( (KU8_CIL_BSR_CYCLE == u8SelectedCycle) && (I_C04_RBTM_ACTVCLIENT_SERVICE_PROVIDER!=Rte_IrvRead_CIL_runAppliToCAN_u8RequestSource()) )
		{
			/* [COVERS: DSG_CIL_0076] */
			CIL_u8Actv_Client = I_C04_RBTM_ACTVCLIENT_BELTSLACK_REDUCTION;
		}
		else
		{
			/* [COVERS: DSG_CIL_0076] */
			CIL_u8Actv_Client = Rte_IrvRead_CIL_runAppliToCAN_u8RequestSource();
		}
	}

	if (I_C06_RBTM_LVL_STAT_NONE == CIL_u8Actv_Lvl)
	{
		CIL_u8Actv_Client = I_C04_RBTM_ACTVCLIENT_NONE;
	}
	/* Send the output signals value depending on the side allocation */
	if(KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION)
	{
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35(CIL_u8Actv_Client);
	}
	else if(KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)
	{
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35(CIL_u8Actv_Client);
	}
	else
	{
		/* Should not be reached */
	}
}
/**
 * \brief
 *     Function used to write Active level signal 
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
LOCAL void cil_ManageActiveLevelSignal(const uint8 u8ExecutedCycle,const uint8 u8SelectedCycle)
{
	/* Can be treated separately than case for executed cycle ? yes */
	const uint8 u8StatusRejected = Rte_IrvRead_CIL_runAppliToCAN_u8ActvLvlSignal();

	switch (u8ExecutedCycle)
	{

	case KU8_NO_CYCLE:
		if (I_C06_RBTM_LVL_STAT_REJECTED == u8StatusRejected)
		{
			/* [COVERS: DSG_CIL_0145, DSG_CIL_0146, DSG_CIL_0147] */
			CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_REJECTED;
		}
		else if( ((KU8_CIL_SMO_CYCLE == u8SelectedCycle) ||
				(KU8_CIL_BSR_CYCLE == u8SelectedCycle)  ||
				(KU8_CIL_HWA10_CYCLE == u8SelectedCycle) ||
				(KU8_CIL_HWA11_CYCLE == u8SelectedCycle) ) ||
				((KU8_TRUE == cil_u8TensioningStarted2) && (KU8_FALSE == cil_u8ReleaseHappens) &&
						(KU16_ZERO == (CIL_u16InhibitionStatus & KU8_CIL_InhibitionAfterORC)) && (KU16_ZERO == (CIL_u16InhibitionStatus & KU8_CIL_InhibitionOfImpactX))))
		{
			/* Nothing to do -> profile process ongoing till release is finished */
		}
		else if((KU8_TRUE == cil_u8PRESAFERequest) || (KU8_TRUE == cil_u8APIRequest) )
		{
			CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_REJECTED;
		}
		else
		{
			CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_NONE;
		}
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_1:
		/* [COVERS: DSG_CIL_0141] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE1;
		break;
	case KU8_CIL_HWA10_CYCLE: // HWA1-0
	case KU8_CIL_HWA11_CYCLE: // HWA1-1
		/* [COVERS: DSG_CIL_0140] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE2;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_2:
		/* [COVERS: DSG_CIL_0142] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE3;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_3:
		/* [COVERS: DSG_CIL_0143] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE4;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_4:
		/* [COVERS: DSG_CIL_0144] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE5;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_5:
		/* [COVERS: DSG_CIL_0185] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE6;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_6:
		/* [COVERS: DSG_CIL_0186] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE7;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_7:
		/* [COVERS: DSG_CIL_0187] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE8;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_8:
		/* [COVERS: DSG_CIL_0188] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE9;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_9:
		/* [COVERS: DSG_CIL_0189] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE10;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_10:
		/* [COVERS: DSG_CIL_0190] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE11;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_11:
		/* [COVERS: DSG_CIL_0191] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE12;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_12:
		/* [COVERS: DSG_CIL_0192] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE13;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_13:
		/* [COVERS: DSG_CIL_0193] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE14;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_14:
		/* [COVERS: DSG_CIL_0194] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE15;
		break;
	case KU8_CIL_HWA20_CYCLE:
	case KU8_CIL_HWA21_CYCLE:
		/* [COVERS: DSG_CIL_0256] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE16;
		break;
	case KU8_CIL_HWA30_CYCLE:
	case KU8_CIL_HWA31_CYCLE:
		/* [COVERS: DSG_CIL_0257] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE17;
		break;
	case KU8_CIL_HWA40_CYCLE:
	case KU8_CIL_HWA41_CYCLE:
		/* [COVERS: DSG_CIL_0258] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE18;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_BSR_1:
		/* [COVERS: DSG_CIL_0139] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_RQ_PROFILE19;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_BSR_2:
		/* [COVERS: DSG_CIL_0259] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_RQ_PROFILE20;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_BSR_3:
		/* [COVERS: DSG_CIL_0260] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_RQ_PROFILE21;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_15:
		/* [COVERS: DSG_CIL_0151] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE22;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_16:
		/* [COVERS: DSG_CIL_0195] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE23;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_17:
		/* [COVERS: DSG_CIL_0196] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE24;
		break;
	case KU8_PRECRASH_SEVERITY_LEVEL_18:
		/* [COVERS: DSG_CIL_0197] */
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_PROFILE25;
		break;
	case KU8_CIL_SMO_CYCLE:
		if( I_C06_RBTM_LVL_STAT_REJECTED == u8StatusRejected )
		{
			CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_REJECTED;
		}
		break;
	default:
		CIL_u8Actv_Lvl = I_C06_RBTM_LVL_STAT_NONE;
		break;
	}

	/* Send the output signals value depending on the side allocation */
	if(KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION)
	{
		/* [COVERS: DSG_CIL_0135] */
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35(CIL_u8Actv_Lvl);
	}
	else if(KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)
	{
		/* [COVERS: DSG_CIL_0136] */
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35(CIL_u8Actv_Lvl);
	}
	else
	{
		/* Should not be reached */
	}
}

/**
 * \brief
 *     Function used to update the output signals
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
LOCAL void cil_ManageOutputSignals(void)
{
	/* Send the output signals value depending on the side allocation */
	if(KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION)
	{
		/* Write RBTM_FL_Tgl_Rq_ST3 signal for left side */
		/* [COVERS: DSG_CIL_0012, DSG_CIL_0122, DSG_CIL_0025, DSG_CIL_0027] */
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_RBTM_FL_Tgl_ST3_RBTM_FL_Tgl_ST3(CIL_bRBTMTgl);
		/* Write BltSlckDec_Md_FL_Stat_ST3 signal for left side */
		/* [COVERS: DSG_CIL_0014, DSG_CIL_0028] */
		/* [COVERS: DSG_CIL_0255; DSG_CIL_0261; DSG_CIL_0262] */
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3(NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8BeltSlkDecMode);
		/* Write signals for left side */
		/* [COVERS: DSG_CIL_0310] */
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3(NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8PSCurveConfig);
	}
	else if(KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)
	{
		/* Write RBTM_FR_Tgl_Rq_ST3 signal for right side */
		/* [COVERS: DSG_CIL_0013, DSG_CIL_0123, DSG_CIL_0026, DSG_CIL_0028] */
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTM_FR_Tgl_ST3_RBTM_FR_Tgl_ST3(CIL_bRBTMTgl);
		/* Write BltSlckDec_Md_FR_Stat_ST3 signal for right side */
		/* [COVERS: DSG_CIL_0015, DSG_CIL_0029] */
		/* [COVERS: DSG_CIL_0255; DSG_CIL_0261; DSG_CIL_0262] */
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3(NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8BeltSlkDecMode);
		/* Write signals for right side */
		/* [COVERS: DSG_CIL_0310] */
		(void)Rte_Write_CIL_AC_CommunicationInteractionLayer_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3(NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8PSCurveConfig);
	}
	else
	{
		/* QAC */
	}
}

/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_START_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/**
 * \brief
 *     CIL periodic main function used to update transmitted frames signals values
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_runAppliToCAN(void)
{

	uint8 u8ExecutedCycle = KU8_NO_PRECRASH_REQUEST;
	uint8 u8SelectedCycle = KU8_NO_CYCLE;

	/* [COVERS: DSG_CIL_0018] */
	(void)Rte_Read_prrCycleNumber_u8CycleNumber(&u8ExecutedCycle);
	(void)Rte_Read_prrSelectedCycle_u8CycleNumber(&u8SelectedCycle);

	/* Compute flag for entire process profile % release */
	if(     (KU8_CIL_SMO_CYCLE != u8ExecutedCycle) &&
			(KU8_NO_CYCLE != u8ExecutedCycle ) &&
			(KU8_CIL_PAT_CYCLE != u8ExecutedCycle) )
	{
		cil_u8TensioningStarted2 = KU8_TRUE;
		cil_u8ReleaseHappens = KU8_FALSE;
	}
	else if( (KU8_CIL_SMO_CYCLE == u8ExecutedCycle) && (KU8_TRUE == cil_u8TensioningStarted2))
	{
		cil_u8ReleaseHappens = KU8_TRUE;
		cil_u8TensioningStarted2 = KU8_FALSE;
	}
	else
	{
		/* Nothing to do */
	}

	/*Compute Active Level signal */
	cil_ManageActiveLevelSignal(u8ExecutedCycle,u8SelectedCycle);
	/* Manage output signal Active Client - Request Source */
	cil_ManageActiveClientRequestSource(u8ExecutedCycle,u8SelectedCycle);
	/* Manage signal FCT PRECOND */
	cil_ManageFctPrecondSignal();
	/* Manage signal Presf Displa */
	cil_ManagePresfDisplay();
	/* Manage in-out signals */
	cil_ManageOutputSignals();


}
#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/******************************************************************************
End Of File
 *****************************************************************************/

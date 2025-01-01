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
$Revision: 1.1.7.55 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/MMG/Implementation/src/project.pj $
 */
/* PRQA S 0288 -- */

/**
 *  @defgroup MMG.c MMG
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */
/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "Rte_MMG_AC_ModeManagement.h"
#include "common.h"
#include "MMG_Private.h"
#include "Nvp_Generated.h"
#include "Nvp_Cfg.h"

/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
 /**
 * \brief
 *	   Invalid order step
 * \remarks
 *		None.
 */
#define MMG_STEPS_ORDER_TYPE_MASK      KU8_SEVEN
/**
 * \brief
 *	   Initial values for all modes
 * \remarks
 *		None.
 */
#define MMG_U32_INITIAL_VALUES_FOR_ALL_MODES    \
		(   MMG_KU32_MASK_CRITICAL_AT_NOK             \
				| MMG_KU32_MASK_AEC_INHIB_ALL_CYCLES        \
				| MMG_KU32_MASK_AEC_INHIB_TENSIONING_CYCLES \
		)
 /**
 * \brief
 *	   Maximum index from NVP_au8StepsDefinitions
 * \remarks
 *		None.
 */
#define MMG_MAX_INDEX_STEPS           ((uint16)(KU8_NB_OF_BELT_STEPS*KU8_NVP_BLOCK_STEP_SIZE))

#define BOOL_MMG_SET_EMABLE_CONDITION       (1u)
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
 * \remarks
 *		None.
 */
#define MMG_AC_ModeManagement_START_SEC_VAR_INIT_8
#include "MMG_AC_ModeManagement_MemMap.h"
/**
 * \brief
 *	    To detect if MMG component has been initialized
 * \remarks
 *		None.
 */
static boolean MMG_b8MMGHAsBeenInitialized = B_FALSE;
/**
 * \brief
 *		Defined macro from C file.
 * \remarks
 *		None.
 */
#define MMG_AC_ModeManagement_START_SEC_VAR_32
#include "MMG_AC_ModeManagement_MemMap.h"

/**
 * \brief
 *		Variable is used to set a running context
 * \remarks
 *		None.
 */
uint32 MMG_u32ModesStatus;
/**
 * \brief
 *		Variable is used for processing information when set a running context
 * \remarks
 *		None.
 */
uint32 MMG_u32ModesStatusComplement;
/**
 * \brief
 *		Variable is used to set a running context
 * \remarks
 *		None.
 */
uint32 MMG_u8EnableCondStatus;
#define MMG_AC_ModeManagement_STOP_SEC_VAR_32
#include "MMG_AC_ModeManagement_MemMap.h"
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
#define MMG_AC_ModeManagement_START_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"

/**
 * \brief
 *		This function is in charge of verifying if cycle has valid steps.
 * \param
 * 		[IN] uint16 : Step0 from cycle that will be verified
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		boolean : valid or not 
 */
/* [COVERS: DSG_MMG_0014] */
LOCAL boolean mmg_CheckIfCycleStepIsvalid(const uint16 u16Step0)
{
	uint16 u16Step0Index0;
	boolean b8Ret = B_TRUE;
	/* No Step configured */
	/* [COVERS: DSG_MMG_0122; DSG_MMG_0123; DSG_MMG_0124; DSG_MMG_0127] */
	if ( KU8_MAX == NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[u16Step0])
	{
		b8Ret = B_FALSE;
	}
	else
	{
		u16Step0Index0 = (uint16)(((uint16)KU8_NVP_BLOCK_STEP_SIZE)*((uint16)NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[u16Step0]));
		/* [COVERS: DSG_MMG_0015] */
		/* Check step range */
		if (MMG_MAX_INDEX_STEPS < u16Step0Index0)
		{
			b8Ret = B_FALSE;
		}
		/* Check steps duration validity */
		else if( ( (NVP_BLOCK_ID_STEP_0_RamBlockData.NVP_au8StepsDefinitions[u16Step0Index0] == KU8_ZERO) && (NVP_BLOCK_ID_STEP_0_RamBlockData.NVP_au8StepsDefinitions[u16Step0Index0 + KU8_ONE] == KU8_ZERO) ) ||
				( (NVP_BLOCK_ID_STEP_0_RamBlockData.NVP_au8StepsDefinitions[u16Step0Index0] == KU8_MAX) && (NVP_BLOCK_ID_STEP_0_RamBlockData.NVP_au8StepsDefinitions[u16Step0Index0 + KU8_ONE] == KU8_MAX) )  )
		{
			b8Ret = B_FALSE;
		}
		/* Check step order type.
		 * Valid range:  0x00: PWM order ;
		 *               0x01: Current order ;
		 *               0x02: Velocity Control order type;
		 *               0x03: Velocity Control + backup PWM order type;
		 *               0x04: Voltage order type;
		 *               0x05: Velocity Control + backup Current order type;
		 *               0x06: Velocity Control + backup Voltage order type
		 * Invalid range: 0x07: Invalid order type               */
		/* [COVERS: DSG_MMG_0126] */
		else if ( KU8_SEVEN == (NVP_BLOCK_ID_STEP_0_RamBlockData.NVP_au8StepsDefinitions[u16Step0Index0 + KU8_THREE] & MMG_STEPS_ORDER_TYPE_MASK ))
		{
			b8Ret = B_FALSE;
		}
		else
		{
			/* At least one step is valid - Nothing to do */
		}
	}
	return b8Ret;
}

/**
 * \brief
 *		Function will check which cycle is valid from the available ones
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
LOCAL void mmg_CheckCycleEnable(void)
{
	/* [COVERS: DSG_MMG_0042; DSG_MMG_0125] */

	/* Cycle 0 */
	if ( ( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_00 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_00 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_00 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle0_b8CycleValidity(B_TRUE);
	}
	/* Cycle 1  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_01 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_01 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_01 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle1_b8CycleValidity(B_TRUE);
	}
	/* Cycle 2  */
	if( ( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_02 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_02 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_02 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle2_b8CycleValidity(B_TRUE);
	}
	/* Cycle 3  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_03 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_03 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_03 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle3_b8CycleValidity(B_TRUE);
	}
	/* Cycle 4 */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_04 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_04 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_04 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle4_b8CycleValidity(B_TRUE);
	}
	/* Cycle 5  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_05 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_05 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_05 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle5_b8CycleValidity(B_TRUE);
	}
	/* Cycle 6  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_06 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_06 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_06 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle6_b8CycleValidity(B_TRUE);
	}
	/* Cycle 7  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_07 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_07 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_07 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle7_b8CycleValidity(B_TRUE);
	}
	/* Cycle 8 */
	if( ( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_08 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_08 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_08 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle8_b8CycleValidity(B_TRUE);
	}
	/* Cycle 9  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_09 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_09 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_09 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle9_b8CycleValidity(B_TRUE);
	}
	/* Cycle 10  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_10 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_10 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_10 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle10_b8CycleValidity(B_TRUE);
	}
	/* Cycle 11  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_11 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_11 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_11 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle11_b8CycleValidity(B_TRUE);
	}
	/* Cycle 12 */
	if(( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_12 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_12 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_12 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle12_b8CycleValidity(B_TRUE);
	}
	/* Cycle 13  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_13 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_13 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_13 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle13_b8CycleValidity(B_TRUE);
	}
	/* Cycle 14  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_14 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_14 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_14 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle14_b8CycleValidity(B_TRUE);
	}
	/* Cycle 15  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_15 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_15 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_15 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle15_b8CycleValidity(B_TRUE);
	}
	/* Cycle 16  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_16 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_16 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_16 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle16_b8CycleValidity(B_TRUE);
	}
	/* Cycle 17  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_17 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_17 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_17 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle17_b8CycleValidity(B_TRUE);
	}
	/* Cycle 18  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_18 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_18 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_18 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle18_b8CycleValidity(B_TRUE);
	}
	/* Cycle 19  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_19 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_19 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_19 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle19_b8CycleValidity(B_TRUE);
	}
	/* Cycle 20  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_20 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_20 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_20 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle20_b8CycleValidity(B_TRUE);
	}
	/* Cycle 21  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_21 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_21 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_21 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle21_b8CycleValidity(B_TRUE);
	}
	/* Cycle 22  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_22 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_22 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_22 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle22_b8CycleValidity(B_TRUE);
	}
	/* Cycle 23  */
	if( ( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_23 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_23 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_23 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle23_b8CycleValidity(B_TRUE);
	}
	/* Cycle 24  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_24 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_24 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_24 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle24_b8CycleValidity(B_TRUE);
	}
	/* Cycle 25  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_25 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_25 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_25 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle25_b8CycleValidity(B_TRUE);
	}
	/* Cycle 26  */
	if (( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_26 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_26 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_26 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle26_b8CycleValidity(B_TRUE);
	}
	/* Cycle 27  */
	if ( ( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_27 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_27 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_27 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle27_b8CycleValidity(B_TRUE);
	}
	/* Cycle 28  */
	if( ( B_TRUE == mmg_CheckIfCycleStepIsvalid((uint16)((KU8_BELT_FUNCTION_28 * KU8_NVP_CYCLE_SIZE)+ KU8_NVP_START_CYCLES))) &&
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)(KU8_BELT_FUNCTION_28 * KU8_NVP_CYCLE_SIZE)] ) && /* Week is invalid */
			(KU8_MAX != NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(uint16)((KU8_BELT_FUNCTION_28 * KU8_NVP_CYCLE_SIZE) + KU8_ONE)] )) /* Year is invalid */
	{
		(void)Rte_Write_psrEnableCycle28_b8CycleValidity(B_TRUE);
	}
}
/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/
/**
 * \brief
 *      Function is in charge of initialization driver’s variables and parameters
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
FUNC(void, MMG_AC_ModeManagement_CODE) MMG_Init(void)
		{
	uint8 mmg_u8Index = KU8_ZERO;

	/* The contexts are first set to NOK to ensure context and
      complement will be equal to each other at the end of this 
      function*/
	MMG_u32ModesStatus = MMG_U32_INITIAL_VALUES_FOR_ALL_MODES;

	/* The complement has to be initialized so that MMG_u32ModesStatus
         Bitwise XOR MMG_u32ModesStatusComplement is equal to 0x0000 */
	MMG_u32ModesStatusComplement = U32_COMPLEMENT(MMG_u32ModesStatus);


	/* Load delay configured in NVP */
	MMG_astDelayAfterCycleThrsandModes[MMG_KU8_CYCLE_MODE_DELAY_INDEX].u16DelayThrs = NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16DelayAfterCycleExecutionOrPOR;
	MMG_astDelayAfterCycleThrsandModes[MMG_KU8_CYCLE_MODE_DELAY_UV_INDEX].u16DelayThrs = NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16DelayAfterCycleExecutionOrPOR_UV;

	/* Search for maximal delay timer */
	for(mmg_u8Index = KU8_ZERO; mmg_u8Index < MMG_KU8_NUMBER_OF_CYCLES_MODES_DELAYS; mmg_u8Index++)
	{
		if(MMG_astDelayAfterCycleThrsandModes[mmg_u8Index].u16DelayThrs >= MMG_u16MaxDelayAfterCycleActivation)
		{
			MMG_u16MaxDelayAfterCycleActivation = MMG_astDelayAfterCycleThrsandModes[mmg_u8Index].u16DelayThrs;
		}
		else
		{
			/* Do not update index for max delay timer */
		}
	}

	/* Configure thresholds for timers used by MMG cycles modes */
	for(mmg_u8Index = KU8_ZERO; mmg_u8Index < MMG_KU8_NUMBER_OF_CYCLES_MODES_DELAYS; mmg_u8Index++)
	{
		MMG_astDelayAfterCycleThrsandModes[mmg_u8Index].u16DelayThrs = MMG_u16MaxDelayAfterCycleActivation - MMG_astDelayAfterCycleThrsandModes[mmg_u8Index].u16DelayThrs;
	}

	mmg_PreSafe_Init();

	mmg_CheckCycleEnable();
	/* [COVERS: DSG_MMG_0016] */
	MMG_b8MMGHAsBeenInitialized = B_TRUE;
		}

/**
 * \brief
 *		This is the MMG main function that refreshes the status of every modes each time it is called. *
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
FUNC(void, MMG_AC_ModeManagement_CODE) MMG_runUpdateModeStatus(void)
		{
	/* Check MMG component is initialized */
	if(B_TRUE == MMG_b8MMGHAsBeenInitialized)
	{
		/* MMG_KU32_MASK_CRITICAL_AT_NOK */
		/* [COVERS: DSG_MMG_0001] */
		mmg_UpdateModeStatus_CriticalAutotestsNok();

		/* MMG_KU32_MASK_POWER_VOLTAGE_UNSTABLE */
		/* [COVERS: DSG_MMG_0002] */
		mmg_UpdateModeStatus_PowerVoltageUnstable();
		/* MMG_KU32_MASK_NO_BELTFUNCTIONS_DELAY */
		/* [COVERS: DSG_MMG_0003] */
		mmg_UpdateModeStatus_ExecutedCycleDelay();

		/* MMG_KU32_MASK_NO_BELTFUNCTIONS */
		/* [COVERS: DSG_MMG_0004] */
		mmg_UpdateModeStatus_ExecutedCycle();

		/* MMG_KU32_MASK_NO_TENSIONING */
		/* [COVERS: DSG_MMG_0005] */
		mmg_UpdateModeStatus_ExecutedTensioningCycle();


		/* MMG_KU32_MASK_NO_HALL_EFFECT_SENSOR */
		/* [COVERS: DSG_MMG_0007] */
		mmg_UpdateModeStatus_NoHallEffectSensor();

		/* MMG_KU32_MASK_AEC_INHIB_ALL_CYCLES */
		/* [COVERS: DSG_MMG_0008] */
		mmg_UpdateModeStatus_PowerSupply_AllCycles();

		/* MMG_KU32_MASK_AEC_ECU_DEFECT_ALL_CYCLES */
		/* [COVERS: DSG_MMG_0009] */
		mmg_UpdateModeStatus_EcuDefective_AllCycles();

		/* MMG_KU32_MASK_AEC_INHIB_TENSIONING_CYCLES */
		/* [COVERS: DSG_MMG_0011] */
		mmg_UpdateModeStatus_Temperature_EOL_KL30_TensioningCycles();

		/* MMG_KU32_MASK_EOL_COMFORT */
		/* [COVERS: DSG_MMG_0010] */
		mmg_UpdateModeStatus_EOLComfort_BSR();

		/* MMG_KU32_MASK_EOL_LOW_FORCE */
		/* [COVERS: DSG_MMG_0112] */
		mmg_UpdateModeStatus_EOL_LowForce_TensioningCycles();

		/* MMG_KU32_MASK_SIGNAL_RELEASE_INHIBITION */
		/* [COVERS: DSG_MMG_] */
		mmg_UpdateModeStatus_SignalReleaseInhibition();

		/* KU8_MMG_IgnitionON */
		/* [COVERS: DSG_MMG_0128] */
		mmg_CheckIgnitionON();

		/* KU8_MMG_CodingAPI */
		/* [COVERS: DSG_MMG_0129] */
		mmg_CheckCodingOfAPI();

		/* KU8_MMG_CodingRBTMFL */
		/* [COVERS: DSG_MMG_0130, DSG_MMG_0131] */
		mmg_CheckBeltHandover();

		/* Set ECU power Up enable condition*/
		(void)Rte_Call_pclEnableCondition5_SetEnableCondition(BOOL_MMG_SET_EMABLE_CONDITION);
	}
	else
	{
		/* Do nothing as MMG component is not yet initialized */
	}
	/* [COVERS: DSG_MMG_0041] */
	mmg_AvailabilityDataStatus();
		}

/**
 * \brief
 *		This is the MMG function that handles all the timers needed by the MMG modes.
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
/* [COVERS: DSG_MMG_0012] */
FUNC(void, MMG_AC_ModeManagement_CODE) MMG_runManageModeDelays(void)
{
	/* Check MMG component is initialized */
	if(B_TRUE == MMG_b8MMGHAsBeenInitialized)
	{
		/* Manage delays for "Executed cycle" mode */
		mmg_ManageModeDelays_ExecutedCycle();

	}
	else
	{
		/* Do nothing as MMG component is not yet initialized */
	}
}

/**
 * \brief
 *		This is the mode checking service. It indicates whether all the required modes are activated.
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
/* [COVERS: DSG_MMG_0013] */
FUNC(void, MMG_AC_ModeManagement_CODE) MMG_runCheckModeStatus(u32ModeMaskType u32ModesToCheck, P2VAR(u8ModeStatusType, AUTOMATIC, RTE_MMG_AC_MODEMANAGEMENT_APPL_VAR) bModeStatus) /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
		{
	/* Check MMG component is initialized */
	if(B_TRUE == MMG_b8MMGHAsBeenInitialized)
	{
		/* Check there is no RAM corruption using bitwise XOR */
		if (KU32_MAX != (MMG_u32ModesStatus ^ MMG_u32ModesStatusComplement))
		{
			/* The RAM is corrupted */
			/* A RAM default error could be notified to DEM here */
			/* Wait for next call to MMG_Mainfunction to have a coherence between RC and its XOR value */
			/* In the meantime, do a reset */
			MMG_u32ModesStatus = MMG_U32_INITIAL_VALUES_FOR_ALL_MODES;
			MMG_u32ModesStatusComplement = U32_COMPLEMENT(MMG_u32ModesStatus);

			/* Returned status is null */
			(*bModeStatus) = KU8_ZERO;
		}
		else
		{
			/* Check a system context is asked */
			/* Check at least one mode is ON (a mode is ON when the situation is detected) */
			if ((KU32_MASK_NO_MODE != u32ModesToCheck) && (KU32_ZERO != (MMG_u32ModesStatus & u32ModesToCheck)))
			{
				/* then return B_TRUE */
				(*bModeStatus) = KU8_MODE_STATUS_ON;
			}
			else
			{
				/* else return B_FALSE */
				(*bModeStatus) = KU8_MODE_STATUS_OFF;
			}
		}
	}
	else
	{
		/* MMG component is not yet initialized */
		/* Returned status is null */
		(*bModeStatus) = KU8_ZERO;
	}
		}

/**
 * \brief
 *		The function checks if a specific NVM block needs written and send a request write for the specific block
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
FUNC(void, MMG_AC_ModeManagement_CODE) MMG_runUpdateNVMBlocks(void) 
		{
	uint8 u8BlockStatus = KU8_FALSE;
	uint8 u8RecorderUpdateStatus = KU8_FALSE;
	NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
	/* [COVERS: DSG_MMG_0117] */
	if(KU8_ONE == Rte_IsUpdated_prrExecutionCountersBlockStatus_b8NVMBlockStatus())
	{	/* [COVERS: DSG_MMG_0115] */
		(void)Rte_Call_pclNvmServicesExecutionCounters_GetErrorStatus(&errorStatus);
		if (NVM_REQ_PENDING != errorStatus)
		{	/* [COVERS: DSG_MMG_0116] */
			Rte_Call_pclNvmServicesExecutionCounters_WriteBlock(&NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData);
			Rte_Read_prrExecutionCountersBlockStatus_b8NVMBlockStatus(&u8BlockStatus);
		}
	}
	/* [COVERS: DSG_MMG_0118] */
	if(KU8_ONE == Rte_IsUpdated_prrCANInputBlockStatus_b8NVMBlockStatus())
	{	/* [COVERS: DSG_MMG_0115] */
		(void)Rte_Call_pclNvmServicesCANInputSignals_GetErrorStatus(&errorStatus);
		if (NVM_REQ_PENDING != errorStatus)
		{	/* [COVERS: DSG_MMG_0116] */
			Rte_Call_pclNvmServicesCANInputSignals_WriteBlock(&NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData);
			Rte_Read_prrCANInputBlockStatus_b8NVMBlockStatus(&u8BlockStatus);
		}
	}
	/* [COVERS: DSG_MMG_0119] */
	if(KU8_ONE == Rte_IsUpdated_prrAECsBlockStatus_b8NVMBlockStatus())
	{	/* [COVERS: DSG_MMG_0115] */
		(void)Rte_Call_pclNvmServicesAECStatus_GetErrorStatus(&errorStatus);
		if(NVM_REQ_PENDING != errorStatus)
		{	/* [COVERS: DSG_MMG_0116] */
			Rte_Call_pclNvmServicesAECStatus_WriteBlock(&NVP_BLOCK_ID_AEC_STATUS_RamBlockData);
			Rte_Read_prrAECsBlockStatus_b8NVMBlockStatus(&u8BlockStatus);
		}
	}
	/* [COVERS: DSG_MMG_0120] */
	u8RecorderUpdateStatus = Rte_IrvRead_MMG_runUpdateNVMBlocks_b8PreSafeRecorder1Update();
	if(KU8_TRUE == u8RecorderUpdateStatus)
	{	/* [COVERS: DSG_MMG_0115] */
		(void)Rte_Call_pclNvmServicesRecorder1_GetErrorStatus(&errorStatus);
		if (NVM_REQ_PENDING != errorStatus)
		{
			/* [COVERS: DSG_MMG_0116] */
			Rte_Call_pclNvmServicesRecorder1_WriteBlock(&NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData);
			Rte_Call_pclNvmServicesRecorderID_WriteBlock(&NVP_BLOCK_ID_PRE_SAFE_RECORDER_ID_RamBlockData);
		}
	}

	u8RecorderUpdateStatus = Rte_IrvRead_MMG_runUpdateNVMBlocks_b8PreSafeRecorder2Update();
	if(KU8_TRUE == u8RecorderUpdateStatus)
	{	/* [COVERS: DSG_MMG_0121] */
		(void)Rte_Call_pclNvmServicesRecorder2_GetErrorStatus(&errorStatus);
		if (NVM_REQ_PENDING != errorStatus)
		{
			/* [COVERS: DSG_MMG_0116] */
			Rte_Call_pclNvmServicesRecorder2_WriteBlock(&NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData);
			Rte_Call_pclNvmServicesRecorderID_WriteBlock(&NVP_BLOCK_ID_PRE_SAFE_RECORDER_ID_RamBlockData);
		}
	}

		}
#define MMG_AC_ModeManagement_STOP_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"
/******************************************************************************
End Of File
 *****************************************************************************/

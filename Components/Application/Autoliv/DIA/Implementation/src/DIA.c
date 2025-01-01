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
$Revision: 1.1.11.14 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup TEMPLATE_FILES_Group_Example Group_Example_Name_In_Document
 *  This is a new created group, this will create a new man3 file with 
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file. 
 */
 
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_DIA_AC_DiagOnCAN.h"
#include "DIA.h"
#include "Nvp_Generated.h"
#include "vstdlib.h"
#include "common.h"
#include "Nvp_Cfg.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/

#define DIA_TASK_CYCLICALITY        50u
#define DIA_FACTOR_SECONDS_TO_MS    1000u
#define DIA_PROG_PRECOND_UNDERVOLTAGE 9000u

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/**
 * \brief
 *		Defined macro from C file.
 */
#define DIA_AC_DiagOnCAN_START_SEC_VAR_UNSPECIFIED
#include <DIA_AC_DiagOnCAN_MemMap.h>

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/**
 * \brief
 *    This variable is used for holding the data of Bckl Sw Stat CAN signal
 * \remarks
 *    None.
 */
c02_Bckl_Sw_Stat dia_u8BcklSwStatSignal = I_C02_BCKL_SW_STAT_SNA;

/**
 * \brief
 *    This holdes the buckle frame status
 * \remarks
 *    None.
 */
REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt stBckl_Sw_Fx_Stat = {KU8_ZERO, I_C02_BCKL_SW_STAT_SNA, I_C02_BCKL_SW_STAT_SNA, KU16_ZERO, KU8_ZERO};

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
/**
 * \brief
 *		This variable should be in upper defined group.
 * \remarks
 *		This is a example of remark of a variable.
 */

/**
 * \brief
 *		Defined macro from C file.
 */
#define DIA_AC_DiagOnCAN_STOP_SEC_VAR_UNSPECIFIED
#include <DIA_AC_DiagOnCAN_MemMap.h>

st_TensioningCycleStarted  DIA_stTensioningCycleStarted;

uint16 DIA_u16TriggerPreSafeCounter = KU16_ZERO;
uint8 DIA_u8TriggerPreSafeRequest = KU8_ROUTINE_NOT_SUPPORTED;

uint8 DIA_u8ProgrammingPreconditionsList[4];
uint8 DIA_u8ActiveProgrammingPreconditions;

/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		Defined macro from C file.
 */
#define DIA_AC_DiagOnCAN_START_SEC_CONST_UNSPECIFIED
#include <DIA_AC_DiagOnCAN_MemMap.h>
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		This variable should be in upper defined group.
 * \remarks
 *		This is a example of remark of a variable.
 */

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/
/**
 * \brief
 *		This is a example of description of a variable.
 * \remarks
 *		This variable should not be in upper defined group.
 */

/**
 * \brief
 *		Defined macro from C file.
 */
#define DIA_AC_DiagOnCAN_STOP_SEC_CONST_UNSPECIFIED
#include <DIA_AC_DiagOnCAN_MemMap.h>
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
#define DIA_AC_DiagOnCAN_START_SEC_CODE
#include "DIA_AC_DiagOnCAN_MemMap.h"

/**
* \brief
*     Checks programming conditions
* \param
*     None
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     None
**/
/* [COVERS: DSG_DIA_MMA_0282] */
Std_ReturnType DIA_runCheckProgrammingPreconditions(void)
{
	
	static REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19 stImpact3 = {0};
	uint16 u16BatteryVoltage;
	static c12_km_p_h_0_409k4_0k1 u16NewVehicleSpeed, u16OldVehicleSpeed;
	uint8 u8PrecondList[4], u8ActivePrecond = 0, u8CurrentCycleExecutedByBFE = KU8_NO_CYCLE;
	Std_ReturnType u8ProgrammingPossible = E_OK;

   (void)Rte_Call_pclKL30_V_Get(&u16BatteryVoltage);
   Rte_Read_IF_VehSpd_Disp_ST3_VehSpd_Disp_ST3(&u16NewVehicleSpeed);
   Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8CurrentCycleExecutedByBFE);

	/*Since if value is one time TRUE, if received TRUE once, never check for signal again during curent driving cycle*/
   if (FALSE == stImpact3.Impact_X_ST3)
   {
	   Rte_Read_DIA_AC_DiagOnCAN_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3(&stImpact3);
   }

   /*If u16NewBatteryVoltage is SNA, last Vehicle Speed shall be used*/
   if (I_C12_KM_P_H_0_409K4_0K1_SNA == u16NewVehicleSpeed)
   {
	   /*Do nothing*/
   }
   else
   {
	   u16OldVehicleSpeed = u16NewVehicleSpeed;
   }

   if (TRUE == stImpact3.Impact_X_ST3)
   {
	   u8PrecondList[u8ActivePrecond] = PROG_PRECOND_CRASH;
	   u8ActivePrecond++;
	   u8ProgrammingPossible = E_NOT_OK;
   }

   if (0 < u16OldVehicleSpeed)
   {
	   u8PrecondList[u8ActivePrecond] = PROG_PRECOND_VEHICLE_SPEED;
	   u8ActivePrecond++;
	   u8ProgrammingPossible = E_NOT_OK;
   }

   if (DIA_PROG_PRECOND_UNDERVOLTAGE >= u16BatteryVoltage)
   {
	   u8PrecondList[u8ActivePrecond] = PROG_PRECOND_LOW_BATTERY_VOLTAGE;
	   u8ActivePrecond++;
	   u8ProgrammingPossible = E_NOT_OK;
   }
   if(KU8_NO_CYCLE != u8CurrentCycleExecutedByBFE)
   {
	   u8PrecondList[u8ActivePrecond] = PROG_PRECOND_CONTROL_ACTIVE;
	   u8ActivePrecond++;
	   u8ProgrammingPossible = E_NOT_OK;
   }

   VStdMemCpy(DIA_u8ProgrammingPreconditionsList, u8PrecondList, DIA_u8ActiveProgrammingPreconditions);
   DIA_u8ActiveProgrammingPreconditions = u8ActivePrecond;

   return u8ProgrammingPossible;
}

/**
* \brief
*     Clears the requested cycle
* \param
*     None
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     None
**/
/* [COVERS: DSG_DIA_MMA_0217] */
void DIA_runClearDiagRequestCycle(void)
{
   /* Update Requested Cycle and its complement */
   Rte_IrvWrite_DIA_runClearDiagRequestCycle_u8DiagRequestedCycle(KU8_NO_CYCLE);
}

/**
* \brief
*     Clears the requested cycle
* \param
*     Out u8DiagRequestCycle - send the requested cycle though app
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     None
**/
/* [COVERS: DSG_DIA_MMA_0218] */
void DIA_runGetDiagRequestCycle(u8CycleNumberType * u8DiagRequestCycle)
{
   ( *u8DiagRequestCycle) = Rte_IrvRead_DIA_runGetDiagRequestCycle_u8DiagRequestedCycle();
}

/**
* \brief
*     Clears the requested cycle
* \param
*     Out u8DiagRequestCycle - send the requested cycle though app
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     None
**/
/* [COVERS: DSG_DIA_MMA_0219] */
FUNC(void, DIA_AC_DiagOnCAN_CODE) DIA_cyclicProcessingTask(void)
		{
	static uint32 u32Duration;
	uint8 u8currentExecutedCycle;

	(void) Rte_Read_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3(&stBckl_Sw_Fx_Stat);

	if(KU8_DIA_ECU_SIDE_FRONT_LEFT == KU8_DIA_ECU_LOCATION)
	{
		/* Buckle signal */
		if (KU8_ONE == NVP_stVehicleEquipmentData.VehicleSteeringConfig) /* Left hand drive vehicle */
		{

			dia_u8BcklSwStatSignal = stBckl_Sw_Fx_Stat.Bckl_Sw_D_Stat_ST3;
		}
		else if (KU8_ZERO == NVP_stVehicleEquipmentData.VehicleSteeringConfig) /* Right hand drive vehicle */
		{
			dia_u8BcklSwStatSignal = stBckl_Sw_Fx_Stat.Bckl_Sw_FP_Stat_ST3;
		}
		else
		{
			/* Not possible */
		}
	}

	else if(KU8_DIA_ECU_SIDE_FRONT_RIGHT == KU8_DIA_ECU_LOCATION)
	{
		/* Buckle signal */
		if (KU8_ONE == NVP_stVehicleEquipmentData.VehicleSteeringConfig) /* Left hand drive vehicle */
		{

			dia_u8BcklSwStatSignal = stBckl_Sw_Fx_Stat.Bckl_Sw_FP_Stat_ST3;
		}

		else if (KU8_ZERO == NVP_stVehicleEquipmentData.VehicleSteeringConfig) /* Right hand drive vehicle */
		{

			dia_u8BcklSwStatSignal = stBckl_Sw_Fx_Stat.Bckl_Sw_D_Stat_ST3;
		}
		else
		{
			/* Not possible */
		}
	}
	else
	{
		/* QAC */
	}

	switch (DIA_stTensioningCycleStarted.routineStatus)
	{
	case TENSIONING_ROUTINE_NOT_RUNNING:
		break;

	case TENSIONING_ROUTINE_STARTED:
		u32Duration = DIA_FACTOR_SECONDS_TO_MS * DIA_stTensioningCycleStarted.timeToRun;
		DIA_stTensioningCycleStarted.routineStatus = TENSIONING_ROUTINE_DEBOUNCING;
		break;

	case TENSIONING_ROUTINE_DEBOUNCING:
		if (DIA_TASK_CYCLICALITY <= u32Duration)
		{
			u32Duration = u32Duration - DIA_TASK_CYCLICALITY;
			/* Check if HWA phase 1 is received in order to trigger following cycle, after first phase*/
			switch (DIA_stTensioningCycleStarted.requestedCycle)
			{
			case KU8_BELT_FUNCTION_18:
				Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8currentExecutedCycle);
				if (KU8_NO_CYCLE == u8currentExecutedCycle)
				{
					Rte_IrvWrite_DIA_cyclicProcessingTask_u8DiagRequestedCycle(KU8_BELT_FUNCTION_19);
				}
				else
				{
					/* do nothing */
				}
				break;
			case KU8_BELT_FUNCTION_20:
				Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8currentExecutedCycle);
				if (KU8_NO_CYCLE == u8currentExecutedCycle)
				{
					Rte_IrvWrite_DIA_cyclicProcessingTask_u8DiagRequestedCycle(KU8_BELT_FUNCTION_21);
				}
				else
				{
					/* do nothing */
				}
				break;
			case KU8_BELT_FUNCTION_22:
				Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8currentExecutedCycle);
				if (KU8_NO_CYCLE == u8currentExecutedCycle)
				{
					Rte_IrvWrite_DIA_cyclicProcessingTask_u8DiagRequestedCycle(KU8_BELT_FUNCTION_23);
				}
				else
				{
					/* do nothing */
				}
				break;
			case KU8_BELT_FUNCTION_24:
				Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8currentExecutedCycle);
				if (KU8_NO_CYCLE == u8currentExecutedCycle)
				{
					Rte_IrvWrite_DIA_cyclicProcessingTask_u8DiagRequestedCycle(KU8_BELT_FUNCTION_25);
				}
				else
				{
					/* do nothing */
				}
				break;

			default:
				break;
			}
		}
		else
		{
			DIA_stTensioningCycleStarted.routineStatus = TENSIONING_ROUTINE_STOP;
		}
		break;

	case TENSIONING_ROUTINE_STOP:
		DIA_stTensioningCycleStarted.routineStatus = TENSIONING_ROUTINE_NOT_RUNNING;
		Rte_IrvWrite_DIA_cyclicProcessingTask_u8DiagRequestedCycle(KU8_NO_CYCLE);
		break;

	case TENSIONING_ROUTINE_STOPPED:
		DIA_stTensioningCycleStarted.routineStatus = TENSIONING_ROUTINE_NOT_RUNNING;
		u32Duration = KU8_ZERO;
		break;

	default:
		break;
	}

	if(KU8_TRIGGER_PRESAFE_ROUTINE_STARTED == DIA_u8TriggerPreSafeRequest)
	{
		if(DIA_u16TriggerPreSafeCounter <= KU16_PRESAFE_TRIGGER_COUNTER)
		{
			DIA_u16TriggerPreSafeCounter++;
			Rte_Write_psePresafeDisplay_b8TriggerPreSafeRequestStatus(KU8_TRUE);
			dia_u8RequestResult0302 = KU8_ROUTINE_IN_PROGRESS;
		}
		else
		{
			DIA_u8TriggerPreSafeRequest = KU8_TRIGGER_PRESAFE_ROUTINE_STOPED;
			DIA_u16TriggerPreSafeCounter = KU16_ZERO;
			Rte_Write_psePresafeDisplay_b8TriggerPreSafeRequestStatus(KU8_FALSE);
			dia_u8RequestResult0302 = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
		}

	}
	else
	{
		/* do nothing */
	}

	/*Cyclically check for programming preconditions*/
	DIA_runCheckProgrammingPreconditions();
}

#define DIA_AC_DiagOnCAN_STOP_SEC_CODE
#include "DIA_AC_DiagOnCAN_MemMap.h"



/******************************************************************************
 Evolution of the component

 created by : T. DEMIREL

 $Log: DIA.c  $
 Revision 1.1.11.14 2024/02/01 13:24:01CET Madalina Serban (madalina.serban) 
 Fixed always in progress issue
 Revision 1.1.11.13 2024/01/28 18:31:58EET Tudor Gligor (tudor.gligor) 
 Update code traceability for DIA Design R8.1
 Revision 1.1.11.12 2024/01/05 14:12:41EET Emanuel Jivan (emanuel.jivan) 
 Implemented Check Programming Preconditions, including during programming session request.
 Revision 1.1.11.11 2023/11/03 11:41:51EET Madalina Serban (madalina.serban) 
 Routine 0302 fixed
 Revision 1.1.11.10 2023/10/23 11:07:32EEST Madalina Serban (madalina.serban) 
 HWA 2,3,4 fix
 Revision 1.1.11.9 2023/07/24 10:07:11EEST Madalina Serban (madalina.serban) 
 Fixes after review
 Revision 1.1.11.8 2023/02/21 13:59:51EET Tudor Gligor (tudor.gligor) 
 Update DIA & DIA_WriteDataByIdentifier with Design traceability after Code Review
 Revision 1.1.11.7 2023/02/01 10:41:23EET Madalina Serban (madalina.serban) 
 Implementation for Presafe display request
 Revision 1.1.11.6 2022/11/04 11:39:56EET Tudor Gligor (tudor.gligor) 
 Update DIA.c after QAC Analysis
 Revision 1.1.11.5 2022/11/03 12:11:15EET Mirela Obada (mirela.obada) 
 Add implementation for Trigger Presafe Request(0302) and Availability Data Read (0142)
 Revision 1.1.11.4 2022/09/06 17:28:10EEST Tudor Gligor (tudor.gligor) 
 [SRC] Code Update for QAC fixes - DIA
 Revision 1.1.11.3 2022/08/09 13:10:26EEST Emanuel Jivan (emanuel.jivan) 
 Implemented RID 0329 and 0330; added 50ms cyclic task.
 Revision 1.1.11.2 2022/07/06 18:06:27EEST Andreea Negrea (andreea.negrea) 
 Initial revision
 Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj
 Revision 1.4.1.2 2022/01/07 15:24:12EET Andreea Negrea (andreea.negrea) 
 Initial revision
 Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj
 Revision 1.1 2021/11/01 10:25:52EET Andreea Negrea (andreea.negrea) 
 First revision
 
******************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/

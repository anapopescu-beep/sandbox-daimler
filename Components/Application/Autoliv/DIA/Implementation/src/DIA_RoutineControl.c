/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------
DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

 **************************************************************************

COMPONENT MCU_Registers

Current revision: $Revision: 1.10.1.9 $
Checked in:       $Date: 2024/01/28 17:31:58CET $

 **************************************************************************

Overview of the component :

------------------------------------------------------------------------

Design document:

 *************************************************************************/

/*************************************************************************
Packages inclusion
 *************************************************************************/
#include "Rte_DIA_AC_DiagOnCAN.h"
#include "DIA.h"
#include "Nvp_Generated.h"
#include "vstdlib.h"
#include "common.h"
/*************************************************************************
Intra-package inclusions
 *************************************************************************/

/*************************************************************************
Private inclusion
 *************************************************************************/

/*************************************************************************
Declaration of macros
 *************************************************************************/

/*************************************************************************
Declaration of types
 *************************************************************************/

/*************************************************************************
LOCAL variables declaration
 *************************************************************************/
#define DIA_AC_DiagOnCAN_START_SEC_VAR_INIT_8
#include "DIA_AC_DiagOnCAN_MemMap.h"

/**
 * \brief
 * 		Request result status for RID F703
 */
LOCAL uint8 dia_u8RequestResultF703 = KU8_ROUTINE_NOT_SUPPORTED;

#define DIA_AC_DiagOnCAN_STOP_SEC_VAR_INIT_8
#include "DIA_AC_DiagOnCAN_MemMap.h"

/*************************************************************************
LOCAL constant data declaration
 **************************************************************************/

/*************************************************************************
EXPORTED variables declaration
 *************************************************************************/

/*************************************************************************
EXPORTED constant data declaration
 **************************************************************************/

/**************************************************************************
Private Functions
 **************************************************************************/
#define DIA_AC_DiagOnCAN_START_SEC_CODE
#include "DIA_AC_DiagOnCAN_MemMap.h"

#define DIA_AC_DiagOnCAN_STOP_SEC_CODE
#include "DIA_AC_DiagOnCAN_MemMap.h"

/**************************************************************************
Exported Functions
 **************************************************************************/
#define DIA_AC_DiagOnCAN_START_SEC_CODE
#include "DIA_AC_DiagOnCAN_MemMap.h"

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Cycle - Cycle to start tensioning cycle
 *     OpStatus - Operation status
 *     RoutineInfo - status of routine
 *     ErrorCode - error of negative response
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0037, DSG_DIA_MMA_0195, DSG_DIA_MMA_0196]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runRidF703_CycleExecutionStart(Dcm_StartDataIn_Routine_Cycle_Execution_Start_CycleType Cycle, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Cycle_Execution_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = RTE_E_OK;
   
   static uint8 dia_u8StartCyclePendingCounter = KU8_ZERO;

   /* Get the cycle to execute */
   const uint8 u8CycleToExecute = Cycle;

   /* Local variable used to retrieve the executed cycle */
   uint8 u8CurrentCycleExecutedByBFE = KU8_NO_CYCLE;

   /* Check if we reached the maximum number of call */
   if (KU8_START_CYCLE_MAXIMUM_TRY > dia_u8StartCyclePendingCounter)
   {
      /* Check if the requested cycle is running */
      Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8CurrentCycleExecutedByBFE);

      if ((u8CycleToExecute == u8CurrentCycleExecutedByBFE) && (u8CycleToExecute != KU8_NO_CYCLE))
      {
         /* Terminate the service */
         *routineInfo = KU8_ROUTINE_IN_PROGRESS;
         ret = RTE_E_OK;
         dia_u8StartCyclePendingCounter = KU8_ZERO;
         dia_u8RequestResultF703 = KU8_ROUTINE_IN_PROGRESS;
      }
      else
      {
         /* First call of the start function, check if the cycle is supported and send the request */
         if (KU8_ZERO == dia_u8StartCyclePendingCounter)
         {
            /* Check if requested cycle is supported */
            if ((KU8_NB_MAX_CYCLES - KU8_ONE) < u8CycleToExecute)
            {
               /* The requested cycle is not supported. Return NOK and set the dedicated NRC */
               *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
               ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK;
               dia_u8StartCyclePendingCounter = KU8_ZERO;
            }
            else
            {
               /* The requested cycle is supported. So execute the cycle */
               Rte_IrvWrite_DIA_runRidF703_CycleExecutionStart_u8DiagRequestedCycle(u8CycleToExecute);
               /* QAC_WARNING S 4570 1 */ /* The operand of this ~ operator has an 'essential type' which is narrower than type 'int'. */

               /* Prepare the next function call */
               OpStatus = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_DCM_E_PENDING;
               dia_u8StartCyclePendingCounter += KU8_ONE;
               ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_DCM_E_PENDING;
               dia_u8RequestResultF703 = KU8_ROUTINE_IN_PROGRESS;
            }
         }
         else
         { /* Cycle request currently handled */
            /* The maximum number of call is not reached, prepare the next call*/
            OpStatus = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_DCM_E_PENDING;
            dia_u8StartCyclePendingCounter += KU8_ONE;
            ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_DCM_E_PENDING;
         }
      }
   }
   else
   {
      /* The requested cycle cannot be started. Return NOK and set the dedicated NRC */
      dia_u8StartCyclePendingCounter = KU8_ZERO;

      /* Update Requested Cycle and its complement */
      Rte_IrvWrite_DIA_runRidF703_CycleExecutionStart_u8DiagRequestedCycle(KU8_NO_CYCLE);

      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK;
   }

   return (ret);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     OpStatus - Operation status
 *     RoutineInfo - status of routine
 *     ErrorCode - error of negative response
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0038]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runRidF703_CycleExecutionStop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Cycle_Execution_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = RTE_E_OK;

   /* Local variable used to retrieve the executed cycle */
   uint8 u8CurrentCycleExecutedByBFE = KU8_NO_CYCLE;

   /* Local variable used to retrieve the Diag requested cycle */
   u8CycleNumberType u8DiagRequestedCycle = KU8_NO_CYCLE;

   /* Read the current executed cycle */
   Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8CurrentCycleExecutedByBFE);

   /* Read the current requested cycle */
   u8DiagRequestedCycle = Rte_IrvRead_DIA_runRidF703_CycleExecutionStop_u8DiagRequestedCycle();

   /* Check if the requested cycle is running */
   /* Or if no Start routine was executed */
   if ((KU8_NO_CYCLE == u8CurrentCycleExecutedByBFE) ||
       (KU8_NO_CYCLE == u8DiagRequestedCycle))
   {
	   if (KU8_ROUTINE_SUCCESSFULLY_COMPLETED == dia_u8RequestResultF703)
	        {
	           *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
	           ret = RTE_E_OK;
	        }
	        else if (KU8_ROUTINE_STOPPED_WITHOUT_RESULTS == dia_u8RequestResultF703)
	        {
	           *routineInfo = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
	           ret = RTE_E_OK;
	        }
	        else if (KU8_ROUTINE_IN_PROGRESS == dia_u8RequestResultF703)
	        {
	        	dia_u8RequestResultF703 = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
	           /* Cycle stopped, the routine info byte (fifth byte) should be equal to 0xFF */
	           *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
	        }
	        else
	        {
	           *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
	           ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK;
	        }
   }
   else
   {
      /* Update Requested Cycle and its complement */
      Rte_IrvWrite_DIA_runRidF703_CycleExecutionStop_u8DiagRequestedCycle(KU8_NO_CYCLE);


      /* Cycle stopped, the routine info byte (fifth byte) should be equal to 0xFF */
      *routineInfo = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;

      dia_u8RequestResultF703 = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
   }

   return (ret);
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     OpStatus - Operation status
 *     RoutineInfo - status of routine
 *     Executed_Cycle - Executed cycle
 *     ErrorCode - error of negative response
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS:  DSG_DIA_MMA_0286]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runRidF703_CycleExecutionRequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Cycle_Execution_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_RequestDataOut_Routine_Cycle_Execution_Start_Executed_CycleType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Executed_Cycle, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = RTE_E_OK;
   /* Local variable used to retrieve the executed cycle */
   uint8 u8CurrentCycleExecutedByBFE = KU8_NO_CYCLE;
   uint8 u8DiagRequestedCycle = KU8_NO_CYCLE;

   /* Get the executed cycle number */
   Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(&u8CurrentCycleExecutedByBFE);
   u8DiagRequestedCycle = Rte_IrvRead_DIA_runRidF703_CycleExecutionRequestResults_u8DiagRequestedCycle();

   if ((u8DiagRequestedCycle == u8CurrentCycleExecutedByBFE) && (KU8_NO_CYCLE != u8CurrentCycleExecutedByBFE))
   {
      *routineInfo = KU8_ROUTINE_IN_PROGRESS;
      *(Executed_Cycle) = u8CurrentCycleExecutedByBFE;
      ret = RTE_E_OK;
   }
   else
   {
      if (KU8_ROUTINE_SUCCESSFULLY_COMPLETED == dia_u8RequestResultF703)
      {
    	 *(Executed_Cycle) = u8CurrentCycleExecutedByBFE;
         *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;
         ret = RTE_E_OK;
      }
      else if (KU8_ROUTINE_STOPPED_WITHOUT_RESULTS == dia_u8RequestResultF703)
      {
         *routineInfo = KU8_ROUTINE_STOPPED_WITHOUT_RESULTS;
         ret = RTE_E_OK;
      }
      else if (KU8_ROUTINE_IN_PROGRESS == dia_u8RequestResultF703)
      {
    	 *(Executed_Cycle) = u8CurrentCycleExecutedByBFE;
         *routineInfo = KU8_ROUTINE_IN_PROGRESS;
         ret = RTE_E_OK;
      }
      else
      {
         ret = RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK;
         *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
   }
   return (ret);
}

#define DIA_AC_DiagOnCAN_STOP_SEC_CODE
#include "DIA_AC_DiagOnCAN_MemMap.h"

/* QAC_WARNING S 3227 -- */
/* QAC_WARNING S 3417 -- */ /* QAC warning due to comma operator into RTE macro */
/* QAC_WARNING S 3426 -- */ /* QAC does not recognize RTE macros */
/*************************************************************************
 Evolution of the component

 created by : T. DEMIREL

 $Log: DIA_RoutineControl.c  $
 Revision 1.10.1.9 2024/01/28 17:31:58CET Tudor Gligor (tudor.gligor) 
 Update code traceability for DIA Design R8.1
 Revision 1.10.1.8 2024/01/05 14:12:40EET Emanuel Jivan (emanuel.jivan) 
 Implemented Check Programming Preconditions, including during programming session request.
 Revision 1.10.1.7 2023/06/07 10:05:42EEST Madalina Serban (madalina.serban) 
 F703 routine update
 Revision 1.10.1.6 2023/02/22 18:16:22EET Tudor Gligor (tudor.gligor) 
 Update Design traceability in the code for R5.0 Release for DIA Component
 Revision 1.10.1.5 2022/09/06 17:28:10EEST Tudor Gligor (tudor.gligor) 
 [SRC] Code Update for QAC fixes - DIA
 Revision 1.10.1.4 2022/07/15 13:44:10EEST Emanuel Jivan (emanuel.jivan) 
 Removed pragma.
 Revision 1.10.1.3 2022/07/14 17:19:00EEST Emanuel Jivan (emanuel.jivan) 
 Fixed 22 FE00, and F703 can now do pending.
 Revision 1.10.1.2 2022/07/12 11:40:31EEST Emanuel Jivan (emanuel.jivan) 
 Initial revision
 Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj
 Revision 1.1.1.26.2.42 2022/05/30 08:49:12EEST David Puscasu (david.puscasu)
 [SRC][TR6] DemIf & DIA update logical block name

 *************************************************************************/

/* end of file */

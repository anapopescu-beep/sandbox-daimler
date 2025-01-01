/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Cdd_MBBL_ResetExecutor.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Cdd_MBBL_ResetExecutor>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDD_MBBL_RESETEXECUTOR_H
# define RTE_CDD_MBBL_RESETEXECUTOR_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Cdd_MBBL_ResetExecutor_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(BswM_ESH_KillAllRun, RTE_VAR_NOINIT) Rte_Cdd_MBBL_ResetExecutor_Request_ESH_KillAllRunRequest_requestedMode;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/


# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Request_ESH_KillAllRunRequest_requestedMode Rte_Write_Cdd_MBBL_ResetExecutor_Request_ESH_KillAllRunRequest_requestedMode
#  define Rte_Write_Cdd_MBBL_ResetExecutor_Request_ESH_KillAllRunRequest_requestedMode(data) (Rte_Cdd_MBBL_ResetExecutor_Request_ESH_KillAllRunRequest_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ECUM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_ECUM_APPL_CODE) EcuM_SelectShutdownTarget(EcuM_StateType targetState, EcuM_ModeType resetSleepMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ECUM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_EcuM_ShutdownTarget_SelectShutdownTarget EcuM_SelectShutdownTarget

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_EA_IllegalMcuResetReturn() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) (optimized, tasks cannot interrupt each other) */

#  define Rte_Exit_EA_IllegalMcuResetReturn() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) (optimized, tasks cannot interrupt each other)*/


# endif /* !defined(RTE_CORE) */


# define Cdd_MBBL_ResetExecutor_START_SEC_CODE
# include "Cdd_MBBL_ResetExecutor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Cdd_MBBL_ResetExecutor_Init Cdd_MBBL_ResetExecutor_Init
#  define RTE_RUNNABLE_Pp_ResetExecution_HardReset Pp_ResetExecution_HardReset
#  define RTE_RUNNABLE_Pp_ResetExecution_SoftReset Pp_ResetExecution_SoftReset
# endif

FUNC(void, Cdd_MBBL_ResetExecutor_CODE) Cdd_MBBL_ResetExecutor_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_MBBL_ResetExecutor_CODE) Pp_ResetExecution_HardReset(boolean prepareWatchdog); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Cdd_MBBL_ResetExecutor_CODE) Pp_ResetExecution_SoftReset(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Cdd_MBBL_ResetExecutor_STOP_SEC_CODE
# include "Cdd_MBBL_ResetExecutor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_EcuM_ShutdownTarget_E_NOT_OK (1U)

#  define RTE_E_Pi_ResetExecution_EXECUTION_FAILED (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDD_MBBL_RESETEXECUTOR_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/

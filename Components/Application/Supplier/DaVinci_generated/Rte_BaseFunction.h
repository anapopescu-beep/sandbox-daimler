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
 *             File:  Rte_BaseFunction.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <BaseFunction>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_BASEFUNCTION_H
# define RTE_BASEFUNCTION_H

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

# include "Rte_BaseFunction_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_P_Awake_Diag_Actv_RBTM_FL_ST3_Awake_Diag_Actv_RBTM_FL_ST3 (FALSE)
#  define Rte_InitValue_P_Awake_Ignition_On_RBTM_FL_ST3_Awake_Ignition_On_RBTM_FL_ST3 (FALSE)
#  define Rte_InitValue_P_Awake_NwStart_RBTM_FL_ST3_Awake_NwStart_RBTM_FL_ST3 (FALSE)
#  define Rte_InitValue_P_ECU_Id_RBTM_FL_ST3_ECU_Id_RBTM_FL_ST3 (420U)
#  define Rte_InitValue_P_WakeupRsn_RBTM_FL_ST3_WakeupRsn_RBTM_FL_ST3 (1023U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint16, RTE_VAR_NOINIT) Rte_Irv_BaseFunction_NmTimer;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BaseFunction_P_Awake_Diag_Actv_RBTM_FL_ST3_Awake_Diag_Actv_RBTM_FL_ST3(DC_BOOL data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BaseFunction_P_Awake_Ignition_On_RBTM_FL_ST3_Awake_Ignition_On_RBTM_FL_ST3(DC_BOOL data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BaseFunction_P_Awake_NwStart_RBTM_FL_ST3_Awake_NwStart_RBTM_FL_ST3(DC_BOOL data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BaseFunction_P_ECU_Id_RBTM_FL_ST3_ECU_Id_RBTM_FL_ST3(c12_0_4094_1_SNA data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BaseFunction_P_WakeupRsn_RBTM_FL_ST3_WakeupRsn_RBTM_FL_ST3(c10_WakeupRsn_ST3 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_Awake_Diag_Actv_RBTM_FL_ST3_Awake_Diag_Actv_RBTM_FL_ST3 Rte_Write_BaseFunction_P_Awake_Diag_Actv_RBTM_FL_ST3_Awake_Diag_Actv_RBTM_FL_ST3
#  define Rte_Write_P_Awake_Ignition_On_RBTM_FL_ST3_Awake_Ignition_On_RBTM_FL_ST3 Rte_Write_BaseFunction_P_Awake_Ignition_On_RBTM_FL_ST3_Awake_Ignition_On_RBTM_FL_ST3
#  define Rte_Write_P_Awake_NwStart_RBTM_FL_ST3_Awake_NwStart_RBTM_FL_ST3 Rte_Write_BaseFunction_P_Awake_NwStart_RBTM_FL_ST3_Awake_NwStart_RBTM_FL_ST3
#  define Rte_Write_P_ECU_Id_RBTM_FL_ST3_ECU_Id_RBTM_FL_ST3 Rte_Write_BaseFunction_P_ECU_Id_RBTM_FL_ST3_ECU_Id_RBTM_FL_ST3
#  define Rte_Write_P_WakeupRsn_RBTM_FL_ST3_WakeupRsn_RBTM_FL_ST3 Rte_Write_BaseFunction_P_WakeupRsn_RBTM_FL_ST3_WakeupRsn_RBTM_FL_ST3


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_COMM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_RequestComMode(ComM_UserHandleType parg0, ComM_ModeType ComMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NM_ComM_UserRequest_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)0, arg1))
#  define Rte_Call_PNC_ComM_UserRequest_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)1, arg1))

/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BaseFunction_Init_NmTimer() \
  Rte_Irv_BaseFunction_NmTimer
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_BaseFunction_Init_NmTimer(data) \
  (Rte_Irv_BaseFunction_NmTimer = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_BaseFunction_Main_NmTimer() \
  Rte_Irv_BaseFunction_NmTimer
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_BaseFunction_Main_NmTimer(data) \
  (Rte_Irv_BaseFunction_NmTimer = (data))
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define BaseFunction_START_SEC_CODE
# include "BaseFunction_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BaseFunction_Init BaseFunction_Init
#  define RTE_RUNNABLE_BaseFunction_Main BaseFunction_Main
# endif

FUNC(void, BaseFunction_CODE) BaseFunction_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, BaseFunction_CODE) BaseFunction_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define BaseFunction_STOP_SEC_CODE
# include "BaseFunction_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComM_UserRequest_E_MODE_LIMITATION (2U)

#  define RTE_E_ComM_UserRequest_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_BASEFUNCTION_H */

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

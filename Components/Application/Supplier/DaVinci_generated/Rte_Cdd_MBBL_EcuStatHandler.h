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
 *             File:  Rte_Cdd_MBBL_EcuStatHandler.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Cdd_MBBL_EcuStatHandler>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDD_MBBL_ECUSTATHANDLER_H
# define RTE_CDD_MBBL_ECUSTATHANDLER_H

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

# include "Rte_Cdd_MBBL_EcuStatHandler_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_Awake_Diag_Actv_Awake_Diag_Actv_RBTM_FL_ST3 (FALSE)
#  define Rte_InitValue_Pp_Awake_Diag_Actv_R_Awake_Diag_Actv_RBTM_FR_ST3 (FALSE)
#  define Rte_InitValue_Pp_Awake_Ignition_On_Awake_Ignition_On_RBTM_FL_ST3 (FALSE)
#  define Rte_InitValue_Pp_Awake_Ignition_On_R_Awake_Ignition_On_RBTM_FR_ST3 (FALSE)
#  define Rte_InitValue_Pp_Awake_NwStart_Cluster_Awake_NwStart_RBTM_FL_ST3 (FALSE)
#  define Rte_InitValue_Pp_Awake_NwStart_Cluster_R_Awake_NwStart_RBTM_FR_ST3 (FALSE)
#  define Rte_InitValue_Pp_WakeupRsn_WakeupRsn_RBTM_FL_ST3 (1023U)
#  define Rte_InitValue_Pp_WakeupRsn_R_WakeupRsn_RBTM_FR_ST3 (1023U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3(P2VAR(REC_Ign_Stat_Pr5_ST3, AUTOMATIC, RTE_CDD_MBBL_ECUSTATHANDLER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_Diag_Actv_Awake_Diag_Actv_RBTM_FL_ST3(DC_BOOL data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_Diag_Actv_R_Awake_Diag_Actv_RBTM_FR_ST3(DC_BOOL data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_Ignition_On_Awake_Ignition_On_RBTM_FL_ST3(DC_BOOL data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_Ignition_On_R_Awake_Ignition_On_RBTM_FR_ST3(DC_BOOL data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_NwStart_Cluster_Awake_NwStart_RBTM_FL_ST3(DC_BOOL data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_NwStart_Cluster_R_Awake_NwStart_RBTM_FR_ST3(DC_BOOL data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_WakeupRsn_WakeupRsn_RBTM_FL_ST3(c10_WakeupRsn_ST3 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_WakeupRsn_R_WakeupRsn_RBTM_FR_ST3(c10_WakeupRsn_ST3 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(uint8, RTE_CODE) Rte_Mode_Cdd_MBBL_EcuStatHandler_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void);

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Pp_Ign_Stat_Ign_Stat_Pr5_ST3 Rte_Read_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Awake_Diag_Actv_Awake_Diag_Actv_RBTM_FL_ST3 Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_Diag_Actv_Awake_Diag_Actv_RBTM_FL_ST3
#  define Rte_Write_Pp_Awake_Diag_Actv_R_Awake_Diag_Actv_RBTM_FR_ST3 Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_Diag_Actv_R_Awake_Diag_Actv_RBTM_FR_ST3
#  define Rte_Write_Pp_Awake_Ignition_On_Awake_Ignition_On_RBTM_FL_ST3 Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_Ignition_On_Awake_Ignition_On_RBTM_FL_ST3
#  define Rte_Write_Pp_Awake_Ignition_On_R_Awake_Ignition_On_RBTM_FR_ST3 Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_Ignition_On_R_Awake_Ignition_On_RBTM_FR_ST3
#  define Rte_Write_Pp_Awake_NwStart_Cluster_Awake_NwStart_RBTM_FL_ST3 Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_NwStart_Cluster_Awake_NwStart_RBTM_FL_ST3
#  define Rte_Write_Pp_Awake_NwStart_Cluster_R_Awake_NwStart_RBTM_FR_ST3 Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_NwStart_Cluster_R_Awake_NwStart_RBTM_FR_ST3
#  define Rte_Write_Pp_WakeupRsn_WakeupRsn_RBTM_FL_ST3 Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_WakeupRsn_WakeupRsn_RBTM_FL_ST3
#  define Rte_Write_Pp_WakeupRsn_R_WakeupRsn_RBTM_FR_ST3 Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_WakeupRsn_R_WakeupRsn_RBTM_FR_ST3


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl Rte_Mode_Cdd_MBBL_EcuStatHandler_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl


/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Cdd_MBBL_EcuStatHandler_NetworkRepeatMessageState;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_NetworkRepeatMessageState() \
  (&Rte_Cdd_MBBL_EcuStatHandler_NetworkRepeatMessageState)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Cdd_MBBL_EcuStatHandler_START_SEC_CODE
# include "Cdd_MBBL_EcuStatHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Cdd_MBBL_EcuStatHandler_Init Cdd_MBBL_EcuStatHandler_Init
#  define RTE_RUNNABLE_DiagSessionChange_EnterExtendedSession DiagSessionChange_EnterExtendedSession
#  define RTE_RUNNABLE_DiagSessionChange_ExitExtendedSession DiagSessionChange_ExitExtendedSession
#  define RTE_RUNNABLE_NmStateChange NmStateChange
# endif

FUNC(void, Cdd_MBBL_EcuStatHandler_CODE) Cdd_MBBL_EcuStatHandler_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_MBBL_EcuStatHandler_CODE) DiagSessionChange_EnterExtendedSession(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_MBBL_EcuStatHandler_CODE) DiagSessionChange_ExitExtendedSession(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Cdd_MBBL_EcuStatHandler_CODE) NmStateChange(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define Cdd_MBBL_EcuStatHandler_STOP_SEC_CODE
# include "Cdd_MBBL_EcuStatHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDD_MBBL_ECUSTATHANDLER_H */

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

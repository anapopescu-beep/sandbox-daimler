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
 *             File:  Rte_Ct_MBBL_ResetPreconditionChecker.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ct_MBBL_ResetPreconditionChecker>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CT_MBBL_RESETPRECONDITIONCHECKER_H
# define RTE_CT_MBBL_RESETPRECONDITIONCHECKER_H

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

# include "Rte_Ct_MBBL_ResetPreconditionChecker_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_VehSpd8_Pr5_ST3_VehSpd8_Pr5_ST3 Rte_Read_Ct_MBBL_ResetPreconditionChecker_R_VehSpd8_Pr5_ST3_VehSpd8_Pr5_ST3

#  define Rte_Read_Ct_MBBL_ResetPreconditionChecker_R_VehSpd8_Pr5_ST3_VehSpd8_Pr5_ST3(data) (*(data) = Rte_XDIS_dj45cy8ua216iwtra2tj416zq_REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4, ((Std_ReturnType)RTE_E_UNCONNECTED))


# endif /* !defined(RTE_CORE) */


# define Ct_MBBL_ResetPreconditionChecker_START_SEC_CODE
# include "Ct_MBBL_ResetPreconditionChecker_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ct_MBBL_ResetPreconditionChecker_Init Ct_MBBL_ResetPreconditionChecker_Init
#  define RTE_RUNNABLE_Pp_MBBL_BootloaderPreconditions_CheckConditions Pp_MBBL_BootloaderPreconditions_CheckConditions
#  define RTE_RUNNABLE_Pp_MBBL_ResetPreconditions_CheckConditions Pp_MBBL_ResetPreconditions_CheckConditions
# endif

FUNC(void, Ct_MBBL_ResetPreconditionChecker_CODE) Ct_MBBL_ResetPreconditionChecker_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_ResetPreconditionChecker_CODE) Pp_MBBL_BootloaderPreconditions_CheckConditions(P2VAR(boolean, AUTOMATIC, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_VAR) resetAllowed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ct_MBBL_ResetPreconditionChecker_CODE) Pp_MBBL_ResetPreconditions_CheckConditions(P2VAR(boolean, AUTOMATIC, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_VAR) resetAllowed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Ct_MBBL_ResetPreconditionChecker_STOP_SEC_CODE
# include "Ct_MBBL_ResetPreconditionChecker_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CT_MBBL_RESETPRECONDITIONCHECKER_H */

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

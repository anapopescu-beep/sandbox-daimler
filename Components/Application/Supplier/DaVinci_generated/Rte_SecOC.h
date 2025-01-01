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
 *             File:  Rte_SecOC.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <SecOC>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SECOC_H
# define RTE_SECOC_H

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

# include "Rte_SecOC_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SecOC_VerificationStatus_verificationStatus(P2CONST(SecOC_VerificationStatusType, AUTOMATIC, RTE_SECOC_APPL_DATA) data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_VerificationStatus_verificationStatus Rte_Write_SecOC_VerificationStatus_verificationStatus


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_SSA_FVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_FVM_APPL_CODE) Ssa_FvM_GetRxFreshness(uint16 freshnessValueId, P2CONST(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_DATA) truncatedFreshnessValue, uint32 truncatedFreshnessValueLength, uint16 authVerifyAttempts, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValue, P2VAR(uint32, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValueLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_FVM_APPL_CODE) Ssa_FvM_GetRxFreshness(uint16 freshnessValueId, P2CONST(freshnessValueType, AUTOMATIC, RTE_SSA_FVM_APPL_DATA) truncatedFreshnessValue, uint32 truncatedFreshnessValueLength, uint16 authVerifyAttempts, P2VAR(freshnessValueType, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValue, P2VAR(uint32, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValueLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_FVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_FailedSecOcMacVerification(P2CONST(SecOC_VerificationStatusType, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) verificationStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_FreshnessManagement_GetRxFreshness Ssa_FvM_GetRxFreshness
#  define Rte_Call_VerificationStatusNotification_VerifyStatus Ssa_SecLog_LogEvent_FailedSecOcMacVerification

# endif /* !defined(RTE_CORE) */


# define SecOC_START_SEC_CODE
# include "SecOC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_SecOC_MainFunctionRx SecOC_MainFunctionRx
#  define RTE_RUNNABLE_SecOC_MainFunctionTx SecOC_MainFunctionTx
#  define RTE_RUNNABLE_VerifyStatusOverride SecOC_VerifyStatusOverride
# endif

FUNC(void, SecOC_CODE) SecOC_MainFunctionRx(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SecOC_CODE) SecOC_MainFunctionTx(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, SecOC_CODE) SecOC_VerifyStatusOverride(uint16 freshnessValueID, uint8 overrideStatus, uint8 numberOfMessagesToOverride); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define SecOC_STOP_SEC_CODE
# include "SecOC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SecOC_FreshnessManagement_E_BUSY (2U)

#  define RTE_E_SecOC_FreshnessManagement_E_NOT_OK (1U)

#  define RTE_E_SecOC_FreshnessManagement_E_OK (0U)

#  define RTE_E_SecOC_VerifyStatusConfiguration_E_NOT_OK (1U)

#  define RTE_E_SecOC_VerifyStatusConfiguration_E_OK (0U)

#  define RTE_E_VerificationStatusIndication_E_NOT_OK (1U)

#  define RTE_E_VerificationStatusIndication_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SECOC_H */

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

   MD_Rte_1330:  MISRA rule: Rule8.3
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
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

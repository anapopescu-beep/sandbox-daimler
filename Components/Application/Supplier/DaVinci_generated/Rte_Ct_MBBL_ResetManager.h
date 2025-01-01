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
 *             File:  Rte_Ct_MBBL_ResetManager.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ct_MBBL_ResetManager>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CT_MBBL_RESETMANAGER_H
# define RTE_CT_MBBL_RESETMANAGER_H

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

# include "Rte_Ct_MBBL_ResetManager_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(uint8, RTE_CODE) Rte_Mode_Ct_MBBL_ResetManager_Pp_DcmEcuReset_DcmEcuReset(P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_VAR) previousMode, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_VAR) nextMode);

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_Pp_DcmEcuReset_DcmEcuReset Rte_Mode_Ct_MBBL_ResetManager_Pp_DcmEcuReset_DcmEcuReset


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CDD_MBBL_RESETEXECUTOR_APPL_CODE) Pp_ResetExecution_HardReset(boolean prepareWatchdog); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CDD_MBBL_RESETEXECUTOR_APPL_CODE) Pp_ResetExecution_SoftReset(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_MBBL_RESETEXECUTOR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE) Pp_MBBL_BootloaderPreconditions_CheckConditions(P2VAR(boolean, AUTOMATIC, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_VAR) resetAllowed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE) Pp_MBBL_ResetPreconditions_CheckConditions(P2VAR(boolean, AUTOMATIC, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_VAR) resetAllowed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_Pp_MBBL_ApplicationShutdown_ShutdownAppl_HardReset() (RTE_E_UNCONNECTED)
#  define Rte_Call_Pp_MBBL_ApplicationShutdown_ShutdownAppl_SoftReset() (RTE_E_UNCONNECTED)
#  define Rte_Call_Pp_MBBL_BootloaderPreconditions_CheckConditions(arg1, arg2) (Pp_MBBL_BootloaderPreconditions_CheckConditions(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_Pp_MBBL_ResetPreconditions_CheckConditions(arg1, arg2) (Pp_MBBL_ResetPreconditions_CheckConditions(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_Pp_ResetExecution_HardReset(arg1) (Pp_ResetExecution_HardReset(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_Pp_ResetExecution_SoftReset Pp_ResetExecution_SoftReset

# endif /* !defined(RTE_CORE) */


# define Ct_MBBL_ResetManager_START_SEC_CODE
# include "Ct_MBBL_ResetManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ct_MBBL_ResetManager_Init Ct_MBBL_ResetManager_Init
#  define RTE_RUNNABLE_DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation
#  define RTE_RUNNABLE_DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication
#  define RTE_RUNNABLE_ResetServiceExecution ResetServiceExecution
# endif

FUNC(void, Ct_MBBL_ResetManager_CODE) Ct_MBBL_ResetManager_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ct_MBBL_ResetManager_CODE) DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_ResetManager_CODE) DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_ResetManager_CODE) DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication(uint8 SID, P2CONST(Dcm_Data4095ByteType, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, Ct_MBBL_ResetManager_CODE) ResetServiceExecution(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define Ct_MBBL_ResetManager_STOP_SEC_CODE
# include "Ct_MBBL_ResetManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_Pi_ResetExecution_EXECUTION_FAILED (1U)

#  define RTE_E_ServiceRequestNotification_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED (8U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CT_MBBL_RESETMANAGER_H */

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

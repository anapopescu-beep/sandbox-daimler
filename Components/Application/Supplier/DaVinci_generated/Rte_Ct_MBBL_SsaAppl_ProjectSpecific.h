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
 *             File:  Rte_Ct_MBBL_SsaAppl_ProjectSpecific.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ct_MBBL_SsaAppl_ProjectSpecific>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_H
# define RTE_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_H

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

# include "Rte_Ct_MBBL_SsaAppl_ProjectSpecific_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_SSA_PROCCTRL_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_SecurityAccess_CompareKey(uint8 secLevel, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) key, Dcm_OpStatusType opStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_SecurityAccess_CompareKey(uint8 secLevel, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) key, Dcm_OpStatusType opStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_SecurityAccess_GetSeed(uint8 secLevel, Dcm_OpStatusType opStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_SecurityAccess_GetSeed(uint8 secLevel, Dcm_OpStatusType opStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_PROCCTRL_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_P_ICS_SecAccess_ST3_CompareKey Ssa_ProcCtrl_SecurityAccess_CompareKey
#  define Rte_Call_P_ICS_SecAccess_ST3_GetSeed Ssa_ProcCtrl_SecurityAccess_GetSeed

# endif /* !defined(RTE_CORE) */


# define Ct_MBBL_SsaAppl_ProjectSpecific_START_SEC_CODE
# include "Ct_MBBL_SsaAppl_ProjectSpecific_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ct_MBBL_SsaAppl_ProjectSpecific_Init Ct_MBBL_SsaAppl_ProjectSpecific_Init
#  define RTE_RUNNABLE_SecurityAccess_Level_11_CompareKey SecurityAccess_Level_11_CompareKey
#  define RTE_RUNNABLE_SecurityAccess_Level_11_GetSeed SecurityAccess_Level_11_GetSeed
#  define RTE_RUNNABLE_SecurityAccess_Level_3_CompareKey SecurityAccess_Level_3_CompareKey
#  define RTE_RUNNABLE_SecurityAccess_Level_3_GetSeed SecurityAccess_Level_3_GetSeed
#  define RTE_RUNNABLE_SecurityAccess_Level_5F_CompareKey SecurityAccess_Level_5F_CompareKey
#  define RTE_RUNNABLE_SecurityAccess_Level_5F_GetSeed SecurityAccess_Level_5F_GetSeed
#  define RTE_RUNNABLE_SecurityAccess_SAR_Read_CompareKey SecurityAccess_SAR_Read_CompareKey
#  define RTE_RUNNABLE_SecurityAccess_SAR_Read_GetSeed SecurityAccess_SAR_Read_GetSeed
#  define RTE_RUNNABLE_SecurityAccess_SAR_Remove_CompareKey SecurityAccess_SAR_Remove_CompareKey
#  define RTE_RUNNABLE_SecurityAccess_SAR_Remove_GetSeed SecurityAccess_SAR_Remove_GetSeed
# endif

FUNC(void, Ct_MBBL_SsaAppl_ProjectSpecific_CODE) Ct_MBBL_SsaAppl_ProjectSpecific_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_ProjectSpecific_CODE) SecurityAccess_Level_11_CompareKey(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_ProjectSpecific_CODE) SecurityAccess_Level_11_GetSeed(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_ProjectSpecific_CODE) SecurityAccess_Level_3_CompareKey(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_ProjectSpecific_CODE) SecurityAccess_Level_3_GetSeed(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_ProjectSpecific_CODE) SecurityAccess_Level_5F_CompareKey(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_ProjectSpecific_CODE) SecurityAccess_Level_5F_GetSeed(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_ProjectSpecific_CODE) SecurityAccess_SAR_Read_CompareKey(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_ProjectSpecific_CODE) SecurityAccess_SAR_Read_GetSeed(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_ProjectSpecific_CODE) SecurityAccess_SAR_Remove_CompareKey(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_ProjectSpecific_CODE) SecurityAccess_SAR_Remove_GetSeed(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define Ct_MBBL_SsaAppl_ProjectSpecific_STOP_SEC_CODE
# include "Ct_MBBL_SsaAppl_ProjectSpecific_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK (1U)

#  define RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING (10U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CT_MBBL_SSAAPPL_PROJECTSPECIFIC_H */

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

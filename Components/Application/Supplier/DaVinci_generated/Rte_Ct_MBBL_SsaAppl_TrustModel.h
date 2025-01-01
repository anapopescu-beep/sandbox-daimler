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
 *             File:  Rte_Ct_MBBL_SsaAppl_TrustModel.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ct_MBBL_SsaAppl_TrustModel>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_H
# define RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_H

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

# include "Rte_Ct_MBBL_SsaAppl_TrustModel_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGFUNCTION_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data48ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DIAGFUNCTION_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_TIMEM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_RealTime_Compare(P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t1, TimeM_CompareOperatorType compareOp, P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t2, P2VAR(boolean, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_RealTime_Get(P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) realTime); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_RealTime_Set(P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) realTime, TimeM_RealTimeChangeReasonType changeReason); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_TIMEM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead
#  define Rte_Call_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData
#  define Rte_Call_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength
#  define Rte_Call_TimeM_RealTime_Compare Ssa_TimeM_RealTime_Compare
#  define Rte_Call_TimeM_RealTime_Get Ssa_TimeM_RealTime_Get
#  define Rte_Call_TimeM_RealTime_Set Ssa_TimeM_RealTime_Set

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_TrustModel_Pim_RealTime_Unix;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_Pim_RealTime_Unix() \
  (&Rte_Ct_MBBL_SsaAppl_TrustModel_Pim_RealTime_Unix)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Ct_MBBL_SsaAppl_TrustModel_START_SEC_CODE
# include "Ct_MBBL_SsaAppl_TrustModel_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ct_MBBL_SsaAppl_TrustModel_Init Ct_MBBL_SsaAppl_TrustModel_Init
#  define RTE_RUNNABLE_Ssa_KeyM_GeCurrentTime Ssa_KeyM_GeCurrentTime
#  define RTE_RUNNABLE_Ssa_onVedocInformation_called Ssa_onVedocInformation_called
# endif

FUNC(void, Ct_MBBL_SsaAppl_TrustModel_CODE) Ct_MBBL_SsaAppl_TrustModel_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_TrustModel_CODE) Ssa_KeyM_GeCurrentTime(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_TrustModel_CODE) Ssa_onVedocInformation_called(P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR) data, P2VAR(uint16, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR) dataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_TrustModel_CODE) Ssa_onVedocInformation_called(P2VAR(Ssa_Data64ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR) data, P2VAR(uint16, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR) dataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define Ct_MBBL_SsaAppl_TrustModel_STOP_SEC_CODE
# include "Ct_MBBL_SsaAppl_TrustModel_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_E_NOT_OK (1U)

#  define RTE_E_Ssa_VeDocRelevantInfo_E_NOT_OK (1U)

#  define RTE_E_TimeM_RealTime_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_H */

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

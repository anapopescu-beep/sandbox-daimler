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
 *             File:  Rte_Ct_ResourceMeasurement.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ct_ResourceMeasurement>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CT_RESOURCEMEASUREMENT_H
# define RTE_CT_RESOURCEMEASUREMENT_H

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

# include "Rte_Ct_ResourceMeasurement_Type.h"
# include "Rte_DataHandleType.h"


# define Ct_ResourceMeasurement_START_SEC_CODE
# include "Ct_ResourceMeasurement_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DataServices_CPU_Load_Read_CPU_load_histograms_ConditionCheckRead DataServices_CPU_Load_Read_CPU_load_histograms_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_CPU_Load_Read_CPU_load_histograms_ReadData DataServices_CPU_Load_Read_CPU_load_histograms_ReadData
#  define RTE_RUNNABLE_DataServices_CPU_Load_Read_CPU_load_histograms_ReadDataLength DataServices_CPU_Load_Read_CPU_load_histograms_ReadDataLength
#  define RTE_RUNNABLE_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ConditionCheckRead DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData
#  define RTE_RUNNABLE_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadDataLength DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadDataLength
#  define RTE_RUNNABLE_DataServices_Stack_Load_Read_Maximum_ConditionCheckRead DataServices_Stack_Load_Read_Maximum_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Stack_Load_Read_Maximum_ReadData DataServices_Stack_Load_Read_Maximum_ReadData
#  define RTE_RUNNABLE_DataServices_Stack_Load_Read_Maximum_ReadDataLength DataServices_Stack_Load_Read_Maximum_ReadDataLength
#  define RTE_RUNNABLE_DataServices_Task_Response_Time_Read_Task_histograms_ConditionCheckRead DataServices_Task_Response_Time_Read_Task_histograms_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Task_Response_Time_Read_Task_histograms_ReadData DataServices_Task_Response_Time_Read_Task_histograms_ReadData
#  define RTE_RUNNABLE_DataServices_Task_Response_Time_Read_Task_histograms_ReadDataLength DataServices_Task_Response_Time_Read_Task_histograms_ReadDataLength
#  define RTE_RUNNABLE_RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_Start RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_Start
# endif

FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_CPU_Load_Read_CPU_load_histograms_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_CPU_Load_Read_CPU_load_histograms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_CPU_Load_Read_CPU_load_histograms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3060ByteType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_CPU_Load_Read_CPU_load_histograms_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1275ByteType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Stack_Load_Read_Maximum_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Stack_Load_Read_Maximum_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Stack_Load_Read_Maximum_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data510ByteType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Stack_Load_Read_Maximum_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Task_Response_Time_Read_Task_histograms_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Task_Response_Time_Read_Task_histograms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Task_Response_Time_Read_Task_histograms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4080ByteType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) DataServices_Task_Response_Time_Read_Task_histograms_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ct_ResourceMeasurement_CODE) RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Ct_ResourceMeasurement_STOP_SEC_CODE
# include "Ct_ResourceMeasurement_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DataServices_CPU_Load_Read_CPU_load_histograms_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CPU_Load_Read_CPU_load_histograms_E_NOT_OK (1U)

#  define RTE_E_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_E_NOT_OK (1U)

#  define RTE_E_DataServices_Stack_Load_Read_Maximum_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Stack_Load_Read_Maximum_E_NOT_OK (1U)

#  define RTE_E_DataServices_Task_Response_Time_Read_Task_histograms_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Task_Response_Time_Read_Task_histograms_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CT_RESOURCEMEASUREMENT_H */

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

*/

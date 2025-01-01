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
 *             File:  Rte_DiagFunction.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <DiagFunction>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DIAGFUNCTION_H
# define RTE_DIAGFUNCTION_H

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

# include "Rte_DiagFunction_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

#  include "Com.h"


/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(UInt8, RTE_VAR_NOINIT) Rte_EOL_ObsolescenceDataBlockNumber_BlockNumber;
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_MMG_AvailabilityDataHandler_AvailabilityDataCategory;
extern VAR(c02_Off_On, RTE_VAR_NOINIT) Rte_CIL_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3;
extern VAR(c02_Off_Stage1_Stage2, RTE_VAR_NOINIT) Rte_CIL_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3;
extern VAR(c02_Off_Stage1_Stage2, RTE_VAR_NOINIT) Rte_CIL_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3;
extern VAR(uint8, RTE_VAR_NOINIT) Rte_ERH_psrSnapshotData_u8SnapshotAecId;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_R_AvailabilityDataHandler_AvailabilityDataCategory (0U)
#  define Rte_InitValue_R_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3 (3U)
#  define Rte_InitValue_R_DidA_ExtTest_Pres_ST3_DidA_ExtTest_Pres_ST3 (3U)
#  define Rte_InitValue_R_PN14_ProdMd_Stat_ST3_PN14_ProdMd_Stat_ST3 (7U)
#  define Rte_InitValue_R_PN14_SupBat_Volt_ST3_PN14_SupBat_Volt_ST3 (1023U)
#  define Rte_InitValue_R_PN14_TransMd_Stat_ST3_PN14_TransMd_Stat_ST3 (3U)
#  define Rte_InitValue_prrSnapshotData_u8SnapshotAecId (255U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3(P2VAR(REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DiagFunction_R_Sec_Event_ST3_Data(P2VAR(c08_UInt_SNA_na, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DiagFunction_R_Sec_Event_ST3_Data(P2VAR(ARR_08_UInt_noSNA_7, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DiagFunction_P_ROE_ROE_XX_ST3(P2CONST(REC_ROE_XX_ST3_dgfi1nrxtb0voy6rb7ybeonmv, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(uint8, RTE_CODE) Rte_Mode_DiagFunction_CommunicationModeMSI_Mode(P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) previousMode, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) nextMode);


# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ObsolescenceDataBlockNumber_BlockNumber Rte_Read_DiagFunction_ObsolescenceDataBlockNumber_BlockNumber
#  define Rte_Read_DiagFunction_ObsolescenceDataBlockNumber_BlockNumber(data) (*(data) = Rte_EOL_ObsolescenceDataBlockNumber_BlockNumber, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_R_AvailabilityDataHandler_AvailabilityDataCategory Rte_Read_DiagFunction_R_AvailabilityDataHandler_AvailabilityDataCategory
#  define Rte_Read_DiagFunction_R_AvailabilityDataHandler_AvailabilityDataCategory(data) (*(data) = Rte_MMG_AvailabilityDataHandler_AvailabilityDataCategory, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_R_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3 Rte_Read_DiagFunction_R_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3
#  define Rte_Read_DiagFunction_R_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3(data) (*(data) = Rte_CIL_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3 Rte_Read_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3
#  define Rte_Read_R_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3 Rte_Read_DiagFunction_R_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3
#  define Rte_Read_DiagFunction_R_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3(data) (*(data) = Rte_CIL_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_R_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3 Rte_Read_DiagFunction_R_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3
#  define Rte_Read_DiagFunction_R_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3(data) (*(data) = Rte_CIL_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_R_Sec_Event_ST3_Data Rte_Read_DiagFunction_R_Sec_Event_ST3_Data
#  define Rte_Read_prrSnapshotData_u8SnapshotAecId Rte_Read_DiagFunction_prrSnapshotData_u8SnapshotAecId
#  define Rte_Read_DiagFunction_prrSnapshotData_u8SnapshotAecId(data) (*(data) = Rte_ERH_psrSnapshotData_u8SnapshotAecId, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_ROE_ROE_XX_ST3 Rte_Write_DiagFunction_P_ROE_ROE_XX_ST3


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_CommunicationModeMSI_Mode Rte_Mode_DiagFunction_CommunicationModeMSI_Mode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DCM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SesCtrlType); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DCM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE) EOL_Get_Obsolescence_Data(P2CONST(Impl_Obsolescense_Data, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_DATA) pObsData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetDataIndex(NvM_BlockIdType parg0, uint8 DataIndex); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE) RCM_runGetTestResult(P2VAR(u8WdgTestResultType, AUTOMATIC, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_VAR) pu8WdgTestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE) RCM_runLaunchExtWdgTest(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE) StbM_GetCurrentTime(StbM_SynchronizedTimeBaseType parg0, P2VAR(StbM_TimeStampType, AUTOMATIC, RTE_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_VAR) timeStampPtr, P2VAR(StbM_UserDataType, AUTOMATIC, RTE_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_VAR) userDataPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_STBM_OSAPPLICATION_TRUSTED_CORE0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DCMServices_GetSesCtrlType Dcm_GetSesCtrlType
#  define Rte_Call_GlobalTime_Slave_GTD_BODY3_0_14e64f11_GetCurrentTime(arg1, arg2) (StbM_GetCurrentTime((StbM_SynchronizedTimeBaseType)0, arg1, arg2))
#  define Rte_Call_If_Obsolescence_Data_Get_Data(arg1) (EOL_Get_Obsolescence_Data(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_NvMService_CSR_Supplier_Signature_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)101, arg1))
#  define Rte_Call_NvMService_CSR_Supplier_Signature_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)101, arg1))
#  define Rte_Call_NvMService_CSR_Supplier_Signature_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)101, arg1))
#  define Rte_Call_NvMService_Execution_Counters_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)39, arg1))
#  define Rte_Call_NvMService_Execution_Counters_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)39, arg1))
#  define Rte_Call_NvMService_FblMetaData_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)33, arg1))
#  define Rte_Call_NvMService_FblMetaData_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)33, arg1))
#  define Rte_Call_NvMService_FblMetaData_SetDataIndex(arg1) (NvM_SetDataIndex((NvM_BlockIdType)33, arg1))
#  define Rte_Call_NvMService_HW_Partnumber_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)102, arg1))
#  define Rte_Call_NvMService_HW_Partnumber_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)102, arg1))
#  define Rte_Call_NvMService_Measurement_Frame_12_Config_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)41, arg1))
#  define Rte_Call_NvMService_Measurement_Frame_12_Config_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)41, arg1))
#  define Rte_Call_NvMService_Pre_Safe_Recorder_1_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)71, arg1))
#  define Rte_Call_NvMService_Pre_Safe_Recorder_1_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)71, arg1))
#  define Rte_Call_NvMService_Pre_Safe_Recorder_2_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)74, arg1))
#  define Rte_Call_NvMService_Pre_Safe_Recorder_2_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)74, arg1))
#  define Rte_Call_NvMService_System_Context_0_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)77, arg1))
#  define Rte_Call_NvMService_System_Context_0_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)77, arg1))
#  define Rte_Call_NvMService_System_Context_1_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)78, arg1))
#  define Rte_Call_NvMService_System_Context_1_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)78, arg1))
#  define Rte_Call_NvMService_System_Context_2_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)79, arg1))
#  define Rte_Call_NvMService_System_Context_2_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)79, arg1))
#  define Rte_Call_NvMService_Tests_Param_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)40, arg1))
#  define Rte_Call_NvMService_Tests_Param_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)40, arg1))
#  define Rte_Call_NvMService_Warm_Reset_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)70, arg1))
#  define Rte_Call_NvMService_Warm_Reset_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)70, arg1))
#  define Rte_Call_pclExtWdgTest_GetWdgTestResult(arg1) (RCM_runGetTestResult(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclExtWdgTest_LaunchWdgTest() (RCM_runLaunchExtWdgTest(), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_DiagFunction_ExclusiveArea() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_DiagFunction_ExclusiveArea() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dcm_Data4092ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagFunction_CustomerSettings;
extern VAR(Dcm_Data12ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagFunction_DiagnosticTraceMemory;
extern VAR(Dcm_Data1ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagFunction_ISO_15675_2_BlockSize;
extern VAR(Dcm_Data1ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagFunction_ISO_15675_2_STmin;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_CustomerSettings() (&((*RtePim_CustomerSettings())[0]))
#  else
#   define Rte_Pim_CustomerSettings() RtePim_CustomerSettings()
#  endif
#  define RtePim_CustomerSettings() \
  (&Rte_DiagFunction_CustomerSettings)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DiagnosticTraceMemory() (&((*RtePim_DiagnosticTraceMemory())[0]))
#  else
#   define Rte_Pim_DiagnosticTraceMemory() RtePim_DiagnosticTraceMemory()
#  endif
#  define RtePim_DiagnosticTraceMemory() \
  (&Rte_DiagFunction_DiagnosticTraceMemory)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_ISO_15675_2_BlockSize() (&((*RtePim_ISO_15675_2_BlockSize())[0]))
#  else
#   define Rte_Pim_ISO_15675_2_BlockSize() RtePim_ISO_15675_2_BlockSize()
#  endif
#  define RtePim_ISO_15675_2_BlockSize() \
  (&Rte_DiagFunction_ISO_15675_2_BlockSize)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_ISO_15675_2_STmin() (&((*RtePim_ISO_15675_2_STmin())[0]))
#  else
#   define Rte_Pim_ISO_15675_2_STmin() RtePim_ISO_15675_2_STmin()
#  endif
#  define RtePim_ISO_15675_2_STmin() \
  (&Rte_DiagFunction_ISO_15675_2_STmin)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define DiagFunction_START_SEC_CODE
# include "DiagFunction_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DataServices_ActiveDiagnosticInformation_Read_Identification_ConditionCheckRead DataServices_ActiveDiagnosticInformation_Read_Identification_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData
#  define RTE_RUNNABLE_DataServices_ActiveDiagnosticInformation_Read_Session_ConditionCheckRead DataServices_ActiveDiagnosticInformation_Read_Session_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_ActiveDiagnosticInformation_Read_Session_ReadData DataServices_ActiveDiagnosticInformation_Read_Session_ReadData
#  define RTE_RUNNABLE_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ConditionCheckRead DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ReadData DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ReadData
#  define RTE_RUNNABLE_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_WriteData DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_WriteData
#  define RTE_RUNNABLE_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ConditionCheckRead DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ReadData DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ReadData
#  define RTE_RUNNABLE_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_WriteData DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_WriteData
#  define RTE_RUNNABLE_DataServices_BSR_Counter_read_Read_BSR_Counter_ConditionCheckRead DataServices_BSR_Counter_read_Read_BSR_Counter_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData
#  define RTE_RUNNABLE_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ConditionCheckRead DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData
#  define RTE_RUNNABLE_DataServices_BootSoftwareVersion_Read_Boot_SW_week_ConditionCheckRead DataServices_BootSoftwareVersion_Read_Boot_SW_week_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData
#  define RTE_RUNNABLE_DataServices_BootSoftwareVersion_Read_Boot_SW_year_ConditionCheckRead DataServices_BootSoftwareVersion_Read_Boot_SW_year_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData
#  define RTE_RUNNABLE_DataServices_Current_Operating_Time_Read_Current_Operating_Time_ConditionCheckRead DataServices_Current_Operating_Time_Read_Current_Operating_Time_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData
#  define RTE_RUNNABLE_DataServices_Current_Operating_Time_Read_Operating_Time_Status_ConditionCheckRead DataServices_Current_Operating_Time_Read_Operating_Time_Status_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData
#  define RTE_RUNNABLE_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ConditionCheckRead DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData
#  define RTE_RUNNABLE_DataServices_Customer_Settings_Read_PS_Curve_Stat_ConditionCheckRead DataServices_Customer_Settings_Read_PS_Curve_Stat_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData
#  define RTE_RUNNABLE_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ConditionCheckRead DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData
#  define RTE_RUNNABLE_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ConditionCheckRead DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData
#  define RTE_RUNNABLE_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ConditionCheckRead DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData
#  define RTE_RUNNABLE_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ConditionCheckRead DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData
#  define RTE_RUNNABLE_DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ConditionCheckRead DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData
#  define RTE_RUNNABLE_DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ConditionCheckRead DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData
#  define RTE_RUNNABLE_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ConditionCheckRead DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData
#  define RTE_RUNNABLE_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ConditionCheckRead DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData
#  define RTE_RUNNABLE_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ConditionCheckRead DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData
#  define RTE_RUNNABLE_DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ConditionCheckRead DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData
#  define RTE_RUNNABLE_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ConditionCheckRead DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData
#  define RTE_RUNNABLE_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData
#  define RTE_RUNNABLE_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData
#  define RTE_RUNNABLE_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength
#  define RTE_RUNNABLE_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ConditionCheckRead DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData
#  define RTE_RUNNABLE_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadDataLength DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadDataLength
#  define RTE_RUNNABLE_DataServices_Global_Time_Sync_Measured_Values_ConditionCheckRead DataServices_Global_Time_Sync_Measured_Values_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Global_Time_Sync_Measured_Values_ReadData DataServices_Global_Time_Sync_Measured_Values_ReadData
#  define RTE_RUNNABLE_DataServices_Global_Time_Sync_Measured_Values_ReadDataLength DataServices_Global_Time_Sync_Measured_Values_ReadDataLength
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData
#  define RTE_RUNNABLE_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData
#  define RTE_RUNNABLE_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ConditionCheckRead DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData
#  define RTE_RUNNABLE_DataServices_HardwareVersion_Read_HW_patch_level_ConditionCheckRead DataServices_HardwareVersion_Read_HW_patch_level_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_HardwareVersion_Read_HW_patch_level_ReadData DataServices_HardwareVersion_Read_HW_patch_level_ReadData
#  define RTE_RUNNABLE_DataServices_HardwareVersion_Read_HW_week_ConditionCheckRead DataServices_HardwareVersion_Read_HW_week_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_HardwareVersion_Read_HW_week_ReadData DataServices_HardwareVersion_Read_HW_week_ReadData
#  define RTE_RUNNABLE_DataServices_HardwareVersion_Read_HW_year_ConditionCheckRead DataServices_HardwareVersion_Read_HW_year_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_HardwareVersion_Read_HW_year_ReadData DataServices_HardwareVersion_Read_HW_year_ReadData
#  define RTE_RUNNABLE_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ConditionCheckRead DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData
#  define RTE_RUNNABLE_DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ConditionCheckRead DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadData DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadData
#  define RTE_RUNNABLE_DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadDataLength DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadDataLength
#  define RTE_RUNNABLE_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ConditionCheckRead DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData
#  define RTE_RUNNABLE_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadDataLength DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadDataLength
#  define RTE_RUNNABLE_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ConditionCheckRead DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData
#  define RTE_RUNNABLE_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadDataLength DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadDataLength
#  define RTE_RUNNABLE_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData
#  define RTE_RUNNABLE_DataServices_PreCheckProgrammingDependencies_Start DataServices_PreCheckProgrammingDependencies_Start
#  define RTE_RUNNABLE_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ConditionCheckRead DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData
#  define RTE_RUNNABLE_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadDataLength DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadDataLength
#  define RTE_RUNNABLE_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ConditionCheckRead DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData
#  define RTE_RUNNABLE_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadDataLength DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadDataLength
#  define RTE_RUNNABLE_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ConditionCheckRead DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData
#  define RTE_RUNNABLE_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadDataLength DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadDataLength
#  define RTE_RUNNABLE_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ConditionCheckRead DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData
#  define RTE_RUNNABLE_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadDataLength DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadDataLength
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData
#  define RTE_RUNNABLE_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ConditionCheckRead DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData
#  define RTE_RUNNABLE_DataServices_Synchronize_to_Non_volatile_Memory_Start DataServices_Synchronize_to_Non_volatile_Memory_Start
#  define RTE_RUNNABLE_DataServices_System_Time_read_Read_System_time_ConditionCheckRead DataServices_System_Time_read_Read_System_time_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_System_Time_read_Read_System_time_ReadData DataServices_System_Time_read_Read_System_time_ReadData
#  define RTE_RUNNABLE_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ConditionCheckRead DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData
#  define RTE_RUNNABLE_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadDataLength DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadDataLength
#  define RTE_RUNNABLE_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData
#  define RTE_RUNNABLE_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ConditionCheckRead DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData
#  define RTE_RUNNABLE_DiagFunction_Init DiagFunction_Init
#  define RTE_RUNNABLE_DiagFunction_MainFunction DiagFunction_MainFunction
#  define RTE_RUNNABLE_DiagFunction_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_SyncTimeRecordBlock DiagFunction_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_SyncTimeRecordBlock
#  define RTE_RUNNABLE_DiagFunction_runReadGlobalTime DiagFunction_runReadGlobalTime
#  define RTE_RUNNABLE_RoELight_DTCStatusChanged_Callback RoELight_DTCStatusChanged_Callback
#  define RTE_RUNNABLE_RoELite_AvailabilityDataHandler RoELite_AvailabilityDataHandler
#  define RTE_RUNNABLE_RoELite_ObsolescenceDataHandler RoELite_ObsolescenceDataHandler
#  define RTE_RUNNABLE_RoELite_SecureEventNotification RoELite_SecureEventNotification
#  define RTE_RUNNABLE_RoutineServices_Routine_Erase_All_Start RoutineServices_Routine_Erase_All_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_Force_External_WDG_Start RoutineServices_Routine_Force_External_WDG_Start
#  define RTE_RUNNABLE_Snapshot_DataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution Snapshot_DataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution
#  define RTE_RUNNABLE_Snapshot_DataServices_Data_DID_0x133_Current_Operating_Time Snapshot_DataServices_Data_DID_0x133_Current_Operating_Time
#  define RTE_RUNNABLE_Snapshot_DataServices_Data_DID_0xfd05_Root_Causes Snapshot_DataServices_Data_DID_0xfd05_Root_Causes
#  define RTE_RUNNABLE_Synchronize_to_Non_volatile_Memory_RequestResults Synchronize_to_Non_volatile_Memory_RequestResults
#  define RTE_RUNNABLE_Synchronize_to_Non_volatile_Memory_Stop Synchronize_to_Non_volatile_Memory_Stop
# endif

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ActiveDiagnosticInformation_Read_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ActiveDiagnosticInformation_Read_Session_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ActiveDiagnosticInformation_Read_Session_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ActiveDiagnosticInformation_Read_Session_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BSR_Counter_read_Read_BSR_Counter_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Current_Operating_Time_Read_Current_Operating_Time_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Current_Operating_Time_Read_Operating_Time_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Customer_Settings_Read_PS_Curve_Stat_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data30ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData(P2CONST(Dcm_Data12ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data48ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1000ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Global_Time_Sync_Measured_Values_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Global_Time_Sync_Measured_Values_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Global_Time_Sync_Measured_Values_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2613ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Global_Time_Sync_Measured_Values_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData(P2CONST(Dcm_Data10ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1270ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data381ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data8ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData(P2CONST(Dcm_Data8ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PreCheckProgrammingDependencies_Start(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Pre_Check_Informations, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Dependencies_Verification_Check_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PreCheckProgrammingDependencies_Start(P2CONST(Dcm_StartFlexibleInArrayData_Routine_PreCheckProgrammingDependencies_Start_Pre_Check_InformationsType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Pre_Check_Informations, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Dependencies_Verification_Check_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2540ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data508ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data254ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data381ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data20ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Synchronize_to_Non_volatile_Memory_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_System_Time_read_Read_System_time_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_System_Time_read_Read_System_time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_System_Time_read_Read_System_time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data258ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData(P2CONST(Dcm_Data258ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, DiagFunction_CODE) DiagFunction_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, DiagFunction_CODE) DiagFunction_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, DiagFunction_CODE) DiagFunction_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_SyncTimeRecordBlock(P2CONST(StbM_SyncRecordTableBlockType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) syncRecordTableBlock); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DiagFunction_CODE) DiagFunction_runReadGlobalTime(P2VAR(stAbsoluteSystemTimeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) pstAbsoluteSystemTime); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) RoELight_DTCStatusChanged_Callback(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DiagFunction_CODE) RoELite_AvailabilityDataHandler(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, DiagFunction_CODE) RoELite_ObsolescenceDataHandler(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, DiagFunction_CODE) RoELite_SecureEventNotification(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, DiagFunction_CODE) RoutineServices_Routine_Erase_All_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Erase_All_Start_StatusType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Status, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) RoutineServices_Routine_Force_External_WDG_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Status, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) Snapshot_DataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) Snapshot_DataServices_Data_DID_0x133_Current_Operating_Time(P2VAR(DataPrimitiveType_uint32, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) Snapshot_DataServices_Data_DID_0xfd05_Root_Causes(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) Synchronize_to_Non_volatile_Memory_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DiagFunction_CODE) Synchronize_to_Non_volatile_Memory_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define DiagFunction_STOP_SEC_CODE
# include "DiagFunction_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CSDataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x133_Current_Operating_Time_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0xfd05_Root_Causes_E_NOT_OK (1U)

#  define RTE_E_CallbackDTCStatusChange_E_NOT_OK (1U)

#  define RTE_E_DCMServices_E_OK (0U)

#  define RTE_E_DataServices_ActiveDiagnosticInformation_Read_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ActiveDiagnosticInformation_Read_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_ActiveDiagnosticInformation_Read_Session_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ActiveDiagnosticInformation_Read_Session_E_NOT_OK (1U)

#  define RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_E_NOT_OK (1U)

#  define RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_E_NOT_OK (1U)

#  define RTE_E_DataServices_BSR_Counter_read_Read_BSR_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_BSR_Counter_read_Read_BSR_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_E_NOT_OK (1U)

#  define RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_week_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_week_E_NOT_OK (1U)

#  define RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_year_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_year_E_NOT_OK (1U)

#  define RTE_E_DataServices_Current_Operating_Time_Read_Current_Operating_Time_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Current_Operating_Time_Read_Current_Operating_Time_E_NOT_OK (1U)

#  define RTE_E_DataServices_Current_Operating_Time_Read_Operating_Time_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Current_Operating_Time_Read_Operating_Time_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_E_NOT_OK (1U)

#  define RTE_E_DataServices_Customer_Settings_Read_PS_Curve_Stat_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Customer_Settings_Read_PS_Curve_Stat_E_NOT_OK (1U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_E_NOT_OK (1U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_E_NOT_OK (1U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_E_NOT_OK (1U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_E_NOT_OK (1U)

#  define RTE_E_DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_Diagnostic_Extract_Version_Read_DDM_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Diagnostic_Extract_Version_Read_DDM_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_E_NOT_OK (1U)

#  define RTE_E_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_E_NOT_OK (1U)

#  define RTE_E_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_E_NOT_OK (1U)

#  define RTE_E_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_E_NOT_OK (1U)

#  define RTE_E_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_E_NOT_OK (1U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_E_NOT_OK (1U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_E_NOT_OK (1U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_E_NOT_OK (1U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_E_NOT_OK (1U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_E_NOT_OK (1U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_E_NOT_OK (1U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_E_NOT_OK (1U)

#  define RTE_E_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_HardwareVersion_Read_HW_patch_level_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HardwareVersion_Read_HW_patch_level_E_NOT_OK (1U)

#  define RTE_E_DataServices_HardwareVersion_Read_HW_week_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HardwareVersion_Read_HW_week_E_NOT_OK (1U)

#  define RTE_E_DataServices_HardwareVersion_Read_HW_year_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HardwareVersion_Read_HW_year_E_NOT_OK (1U)

#  define RTE_E_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_E_NOT_OK (1U)

#  define RTE_E_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_E_NOT_OK (1U)

#  define RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_E_NOT_OK (1U)

#  define RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_E_NOT_OK (1U)

#  define RTE_E_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_E_NOT_OK (1U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_E_NOT_OK (1U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_E_NOT_OK (1U)

#  define RTE_E_DataServices_System_Time_read_Read_System_time_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_System_Time_read_Read_System_time_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_E_NOT_OK (1U)

#  define RTE_E_GlobalTime_Slave_GTD_BODY3_0_14e64f11_E_NOT_OK (1U)

#  define RTE_E_GlobalTime_Slave_GTD_BODY3_0_14e64f11_E_OK (0U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Erase_All_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Erase_All_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Erase_All_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Force_External_WDG_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Force_External_WDG_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Force_External_WDG_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_PreCheckProgrammingDependencies_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_PreCheckProgrammingDependencies_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_PreCheckProgrammingDependencies_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_E_NOT_OK (1U)

#  define RTE_E_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_E_NOT_OK (1U)

#  define RTE_E_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_DIAGFUNCTION_H */

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

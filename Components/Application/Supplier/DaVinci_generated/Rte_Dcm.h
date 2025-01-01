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
 *             File:  Rte_Dcm.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Dcm>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DCM_H
# define RTE_DCM_H

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

# include "Rte_Dcm_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6(Dcm_CommunicationModeType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727(Dcm_CommunicationModeType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmModeRapidPowerShutDown_DcmModeRapidPowerShutDown(Dcm_ModeRapidPowerShutDownType nextMode);
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmModeRapidPowerShutDown_DcmModeRapidPowerShutDown(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6 Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6
#  define Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727 Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727
#  define Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting
#  define Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl
#  define Rte_Switch_DcmEcuReset_DcmEcuReset Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset
#  define Rte_Switch_DcmModeRapidPowerShutDown_DcmModeRapidPowerShutDown Rte_Switch_Dcm_DcmModeRapidPowerShutDown_DcmModeRapidPowerShutDown


/**********************************************************************************************************************
 * Rte_Feedback_<p>_<m> (mode switch acknowledge)
 *********************************************************************************************************************/
#  define Rte_SwitchAck_DcmEcuReset_DcmEcuReset Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset
#  define Rte_SwitchAck_DcmModeRapidPowerShutDown_DcmModeRapidPowerShutDown Rte_SwitchAck_Dcm_DcmModeRapidPowerShutDown_DcmModeRapidPowerShutDown


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CT_MBBL_RESETMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CT_MBBL_RESETMANAGER_APPL_CODE) DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_RESETMANAGER_APPL_CODE) DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_RESETMANAGER_APPL_CODE) DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication(uint8 SID, P2CONST(Dcm_Data4095ByteType, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_CT_MBBL_RESETMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data320ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Calibration_Identifications_CAL_ID_Write_CombinedDataElement_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Calibration_Identifications_CAL_ID_Write_CombinedDataElement_WriteData(P2CONST(Dcm_Data320ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_DID_0131_SAR_Data_Storage_Status_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1073ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_WriteData(P2CONST(Dcm_Data1073ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data144ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_WriteData(P2CONST(Dcm_Data144ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data233ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Tensioning_Cycle_BSR_CombinedSignal_WriteData(P2CONST(Dcm_Data233ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData(P2CONST(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_CODING_APPL_CODE) DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_CT_MBBL_SSAAPPL_CODING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_CPU_Load_Read_CPU_load_histograms_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_CPU_Load_Read_CPU_load_histograms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_CPU_Load_Read_CPU_load_histograms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3060ByteType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_CPU_Load_Read_CPU_load_histograms_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1275ByteType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_Stack_Load_Read_Maximum_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_Stack_Load_Read_Maximum_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_Stack_Load_Read_Maximum_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data510ByteType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_Stack_Load_Read_Maximum_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_Task_Response_Time_Read_Task_histograms_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_Task_Response_Time_Read_Task_histograms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_Task_Response_Time_Read_Task_histograms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4080ByteType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) DataServices_Task_Response_Time_Read_Task_histograms_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CT_RESOURCEMEASUREMENT_APPL_CODE) RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_RESOURCEMEASUREMENT_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CT_RESOURCEMEASUREMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DIA_AC_DIAGONCAN_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFE00_AECStatusConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFE00_AECStatusRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFE00_AECStatusRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data240ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFE00_AECStatusReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0142_AvailabilityDataConditionsCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0142_AvailabilityDataRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0142_AvailabilityDataRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_CANoutput1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_CANoutput1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_CANoutput1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD10_CycleConfigurationRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD10_CycleConfigurationRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data420ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD10_CycleConfigurationWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD10_CycleConfigurationWrite(P2CONST(Dcm_Data420ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidF18C_EcuSerialNumberConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidF18C_EcuSerialNumberRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidF18C_EcuSerialNumberRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data33ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidF18C_EcuSerialNumberReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD2F_EcuLocationRead(Dcm_OpStatusType_1 OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD2F_EcuLocationRead(Dcm_OpStatusType_1 OpStatus, P2VAR(Dcm_DataDID_FD2F_EcuLocationData_ArrayType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD2F_EcuLocationWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType_1 OpStatus, P2VAR(Dcm_NegativeResponseCodeType_1, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD2F_EcuLocationWrite(P2CONST(Dcm_DataDID_FD2F_EcuLocationData_ArrayType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType_1 OpStatus, P2VAR(Dcm_NegativeResponseCodeType_1, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD03_ECUTraceabilityNumberConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD03_ECUTraceabilityNumberRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD03_ECUTraceabilityNumberRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD03_ECUTraceabilityNumberWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD03_ECUTraceabilityNumberWrite(P2CONST(Dcm_Data12ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD03_PCBAProgrammedPartNumberConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD03_PCBAProgrammedPartNumberRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD03_PCBAProgrammedPartNumberRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD03_PCBAProgrammedPartNumberWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD03_PCBAProgrammedPartNumberWrite(P2CONST(Dcm_Data10ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD31_HBCalibrationWriteConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD31_HBCalibrationRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD31_HBCalibrationRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data40ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD31_HBCalibrationWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD31_HBCalibrationWrite(P2CONST(Dcm_Data40ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0220_HW_input_Read_Voltage_KL30t_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0220_HW_input_Read_Voltage_KL30t_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0220_HW_input_Read_Voltage_KL30t_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0220_HW_input_Read_Voltage_Motor_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0220_HW_input_Read_Voltage_Motor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0220_HW_input_Read_Voltage_Motor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_patch_level(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_patch_level(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_week(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_week(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_year(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_year(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD09_LastWarmReseConditionChecktRead_LastDetectedWarmResetCause(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD09_LastWarmResetRead_LastDetectedWarmResetCause(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD09_LastWarmResetRead_LastDetectedWarmResetCause(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD09_LastWarmResetConditionCheckRead_ResetCauseCounter(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD09_LastWarmResetRead_ResetCauseCounter(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD09_LastWarmResetRead_ResetCauseCounter(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFDFF_MeasurementFrameBlock12ConfigConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFDFF_MeasurementFrameBlock12ConfigRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFDFF_MeasurementFrameBlock12ConfigRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data5ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFDFF_MeasurementFrameBlock12ConfigWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFDFF_MeasurementFrameBlock12ConfigWrite(P2CONST(Dcm_Data5ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFEFF_MeasuruementFrameConfigurationConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFEFF_MeasuruementFrameConfigurationRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFEFF_MeasuruementFrameConfigurationRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFEFF_MeasuruementFrameConfigurationWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFEFF_MeasuruementFrameConfigurationWrite(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0241_PRE_SAFE_Recorder_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0241_PRE_SAFE_Recorder_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0241_PRE_SAFE_Recorder_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data22ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0241_PRE_SAFE_Recorder_1_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0241_PRE_SAFE_Recorder_1_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0241_PRE_SAFE_Recorder_1_WriteData(P2CONST(Dcm_Data22ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0242_PRE_SAFE_Recorder_2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0242_PRE_SAFE_Recorder_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0242_PRE_SAFE_Recorder_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data22ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0242_PRE_SAFE_Recorder_2_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0242_PRE_SAFE_Recorder_2_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0242_PRE_SAFE_Recorder_2_WriteData(P2CONST(Dcm_Data22ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD08_ResetCauseManagementConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD08_ResetCauseManagementRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD08_ResetCauseManagementRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD01_SWVersionConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD01_SWVersionRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD01_SWVersionRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0340_UniqueSeatbeltSerialNumberConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0340_UniqueSeatbeltSerialNumberRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0340_UniqueSeatbeltSerialNumberRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data28ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0340_UniqueSeatbeltSerialNumberWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDid0340_UniqueSeatbeltSerialNumberWrite(P2CONST(Dcm_Data28ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD2A_StepsLibraryRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD2A_StepsLibraryRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1160ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD2A_StepsLibraryWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD2A_StepsLibraryWrite(P2CONST(Dcm_Data1160ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data30ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData(P2CONST(Dcm_Data30ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRid0203_CheckProgrammingPreconditionsStart(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_Number_of_Unfulfilled_PreconditionsType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Number_of_Unfulfilled_Preconditions, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) List_of_Preconditions, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRid0203_CheckProgrammingPreconditionsStart(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_Number_of_Unfulfilled_PreconditionsType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Number_of_Unfulfilled_Preconditions, P2VAR(Dcm_StartFlexibleOutArrayData_Routine_Check_Reprogramming_Preconditions_Start_List_of_PreconditionsType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) List_of_Preconditions, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRidF703_CycleExecutionRequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Cycle_Execution_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_RequestDataOut_Routine_Cycle_Execution_Start_Executed_CycleType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Executed_Cycle, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRidF703_CycleExecutionStart(Dcm_StartDataIn_Routine_Cycle_Execution_Start_CycleType Cycle, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Cycle_Execution_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRidF703_CycleExecutionStop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Cycle_Execution_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRid0329_TriggerBSRRequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Trigger_BSR_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_RequestDataOut_Routine_Trigger_BSR_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRid0329_TriggerBSRStart(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Trigger_BSR_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Trigger_BSR_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRid0329_TriggerBSRStop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Trigger_BSR_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRid0302_TriggerPresafeDisplayRequestRequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRid0302_TriggerPresafeDisplayRequestStart(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRid0302_TriggerPresafeDisplayRequestStop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRid0330_TriggerTensioningCycleRequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRid0330_TriggerTensioningCycleStart(Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_Type_of_tensioning_cycleType Type_of_tensioning_cycle, Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_PreSafe_DurationType PreSafe_Duration, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runRid0330_TriggerTensioningCycleStop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DIA_AC_DIAGONCAN_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DIAGFUNCTION_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ActiveDiagnosticInformation_Read_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ActiveDiagnosticInformation_Read_Session_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ActiveDiagnosticInformation_Read_Session_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ActiveDiagnosticInformation_Read_Session_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_BSR_Counter_read_Read_BSR_Counter_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Current_Operating_Time_Read_Current_Operating_Time_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Current_Operating_Time_Read_Operating_Time_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Customer_Settings_Read_PS_Curve_Stat_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data30ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData(P2CONST(Dcm_Data12ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data48ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1000ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Global_Time_Sync_Measured_Values_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Global_Time_Sync_Measured_Values_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Global_Time_Sync_Measured_Values_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2613ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Global_Time_Sync_Measured_Values_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData(P2CONST(Dcm_Data10ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HardwareVersion_Read_HW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HardwareVersion_Read_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HardwareVersion_Read_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HardwareVersion_Read_HW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HardwareVersion_Read_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HardwareVersion_Read_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HardwareVersion_Read_HW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HardwareVersion_Read_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_HardwareVersion_Read_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1270ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data381ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data8ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData(P2CONST(Dcm_Data8ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2540ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data508ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data254ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data381ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data20ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_System_Time_read_Read_System_time_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_System_Time_read_Read_System_time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_System_Time_read_Read_System_time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data258ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData(P2CONST(Dcm_Data258ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) RoutineServices_Routine_Erase_All_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Erase_All_Start_StatusType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Status, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) RoutineServices_Routine_Force_External_WDG_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Status, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_PreCheckProgrammingDependencies_Start(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Pre_Check_Informations, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Dependencies_Verification_Check_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_PreCheckProgrammingDependencies_Start(P2CONST(Dcm_StartFlexibleInArrayData_Routine_PreCheckProgrammingDependencies_Start_Pre_Check_InformationsType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Pre_Check_Informations, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Dependencies_Verification_Check_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) Synchronize_to_Non_volatile_Memory_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) DataServices_Synchronize_to_Non_volatile_Memory_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) Synchronize_to_Non_volatile_Memory_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DIAGFUNCTION_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_CODING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_0197_Precompile_switch_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_VINDataIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_VINDataIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_VINDataIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data17ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_VINDataIdentifier_WriteData(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_VINDataIdentifier_WriteData(P2CONST(Dcm_Data17ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_ServiceRequestNotification_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_ServiceRequestNotification_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_ServiceRequestNotification_Indication(uint8 SID, P2CONST(Dcm_SsaDslBufferType, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_CODING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_KEYM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data20ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_Backend_CA_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4092ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Get_Certificate_Entry_Start(uint8 Certificate_Identification_In, uint8 In_Certificate_Entry_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Certificate_identification_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Out_Certificate_Entry_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Certificate_Content_Out, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Get_Certificate_Entry_Start(uint8 Certificate_Identification_In, uint8 In_Certificate_Entry_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Certificate_identification_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Out_Certificate_Entry_Out, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Certificate_Content_Out, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_KEYM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_PROCCTRL_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4092ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1024ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4092ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4008ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester(uint8 Configuration, uint8 Task, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Challenge_Certificate_Proof_of_Ownership, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Authentication_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester(uint8 Configuration, uint8 Task, P2CONST(Dcm_Data4004ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Challenge_Certificate_Proof_of_Ownership, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, P2VAR(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Authentication_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(Dcm_Data18ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Enhance_Access_Rights(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Enhanced_Rights_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Enhance_Access_Rights(P2CONST(Dcm_Data2002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Enhanced_Rights_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Evaluate_Data_Verification_Certificate(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Verification_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Evaluate_Data_Verification_Certificate(P2CONST(Dcm_Data2002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Verification_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Certificates(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Certificates(P2CONST(Dcm_Data4008ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Trust_Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates(P2CONST(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Trust_Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) signature_new_Root_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) signature_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate(P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) signature_new_Root_In, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) signature_In, P2CONST(Dcm_Data2004ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Reset_VIN_Values(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Nonce, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Nonce, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) CSR_Signature_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Trust_Model_ECU_CSR_Out, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) CSR_Signature_Out, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Trust_Model_ECU_CSR_Out, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Date_and_Time_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_Offset_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Encrypted_Nonce_and_Shared_Secret_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_VSM_Public_Key_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution(P2CONST(Dcm_Data7ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Date_and_Time_In, P2CONST(Dcm_Data5ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_In, P2CONST(Dcm_Data5ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_Offset_In, P2CONST(Dcm_Data80ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Encrypted_Nonce_and_Shared_Secret_In, P2CONST(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_VSM_Public_Key_In, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In, P2CONST(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Verify_Signature(uint8 Data_to_be_checked, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Signature_Value, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Verify_Signature(uint8 Data_to_be_checked, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Signature_Value, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_PROCCTRL_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_RIGHTSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Post_Production_Flag_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Start(uint8 In_Post_Production_Flag_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Out_Post_Production_Flag_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Stop(uint8 In_Post_Production_Flag_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Out_Post_Production_Flag_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_ServiceRequestNotification_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_ServiceRequestNotification_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_ServiceRequestNotification_Indication(uint8 SID, P2CONST(Dcm_SsaDslBufferType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_RIGHTSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_TIMEM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data5ByteType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_DataServices_DID_018A_TickCount_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data6ByteType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) ErrorCode); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_TIMEM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DataServices_AEC_Status_Read_AEC_Status_ConditionCheckRead DIA_runDidFE00_AECStatusConditionCheckRead
#  define Rte_Call_DataServices_AEC_Status_Read_AEC_Status_ReadData DIA_runDidFE00_AECStatusRead
#  define Rte_Call_DataServices_AEC_Status_Read_AEC_Status_ReadDataLength DIA_runDidFE00_AECStatusReadDataLength
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Hash_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ConditionCheckRead
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Hash_ReadData Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ReadData
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Major_ReadData Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ReadData
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Minor_ReadData Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ReadData
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Patch_ReadData Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ReadData
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Generation_Time_GTC_ReadData Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ReadData
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Hash_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ConditionCheckRead
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Hash_ReadData Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ReadData
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Major_ReadData Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ReadData
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Minor_ReadData Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ReadData
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Patch_ReadData Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ReadData
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Generation_Time_GTC_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ConditionCheckRead
#  define Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Generation_Time_GTC_ReadData Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ReadData
#  define Rte_Call_DataServices_ActiveDiagnosticInformation_Read_Identification_ConditionCheckRead DataServices_ActiveDiagnosticInformation_Read_Identification_ConditionCheckRead
#  define Rte_Call_DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData
#  define Rte_Call_DataServices_ActiveDiagnosticInformation_Read_Session_ConditionCheckRead DataServices_ActiveDiagnosticInformation_Read_Session_ConditionCheckRead
#  define Rte_Call_DataServices_ActiveDiagnosticInformation_Read_Session_ReadData DataServices_ActiveDiagnosticInformation_Read_Session_ReadData
#  define Rte_Call_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_ConditionCheckRead DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ConditionCheckRead
#  define Rte_Call_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_ReadData DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ReadData
#  define Rte_Call_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_WriteData DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_WriteData
#  define Rte_Call_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_ConditionCheckRead DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ConditionCheckRead
#  define Rte_Call_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_ReadData DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ReadData
#  define Rte_Call_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_WriteData DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_WriteData
#  define Rte_Call_DataServices_Availability_Data_Read_Availability_Data_PRE_SAFE_haptic_warning_ConditionCheckRead DIA_runDid0142_AvailabilityDataConditionsCheckRead
#  define Rte_Call_DataServices_Availability_Data_Read_Availability_Data_PRE_SAFE_haptic_warning_ReadData DIA_runDid0142_AvailabilityDataRead
#  define Rte_Call_DataServices_BSR_Counter_read_Read_BSR_Counter_ConditionCheckRead DataServices_BSR_Counter_read_Read_BSR_Counter_ConditionCheckRead
#  define Rte_Call_DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData
#  define Rte_Call_DataServices_Backend_CA_Certificate_Identification_Read_Backend_CA_SubjectKeyIdentifier_ConditionCheckRead Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ConditionCheckRead
#  define Rte_Call_DataServices_Backend_CA_Certificate_Identification_Read_Backend_CA_SubjectKeyIdentifier_ReadData Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ReadData
#  define Rte_Call_DataServices_Backend_CA_Certificate_Read_Backend_CA_Certificate_ConditionCheckRead Ssa_KeyM_DataServices_Backend_CA_Certificate_ConditionCheckRead
#  define Rte_Call_DataServices_Backend_CA_Certificate_Read_Backend_CA_Certificate_ReadData Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadData
#  define Rte_Call_DataServices_Backend_CA_Certificate_Read_Backend_CA_Certificate_ReadDataLength Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadDataLength
#  define Rte_Call_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ConditionCheckRead DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ConditionCheckRead
#  define Rte_Call_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData
#  define Rte_Call_DataServices_BootSoftwareVersion_Read_Boot_SW_week_ConditionCheckRead DataServices_BootSoftwareVersion_Read_Boot_SW_week_ConditionCheckRead
#  define Rte_Call_DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData
#  define Rte_Call_DataServices_BootSoftwareVersion_Read_Boot_SW_year_ConditionCheckRead DataServices_BootSoftwareVersion_Read_Boot_SW_year_ConditionCheckRead
#  define Rte_Call_DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_1_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_1_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ReadData
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_2_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_2_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ReadData
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_3_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_3_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ReadData
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_4_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_4_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ReadData
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_5_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_5_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ReadData
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_6_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_6_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ReadData
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_7_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_7_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ReadData
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_8_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_8_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ReadData
#  define Rte_Call_DataServices_CAN_input_Read_Supply_battery_voltage_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_input_Read_Supply_battery_voltage_ReadData DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ReadData
#  define Rte_Call_DataServices_CAN_output_Read_CANoutput1_ConditionCheckRead DIA_runDid0210_CAN_output_Read_CANoutput1_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_output_Read_CANoutput1_ReadData DIA_runDid0210_CAN_output_Read_CANoutput1_ReadData
#  define Rte_Call_DataServices_CAN_output_Read_PS_Curve_XX_Stat_ST3_ConditionCheckRead DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_output_Read_PS_Curve_XX_Stat_ST3_ReadData DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ReadData
#  define Rte_Call_DataServices_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ConditionCheckRead DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ReadData DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ReadData
#  define Rte_Call_DataServices_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ConditionCheckRead DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ReadData DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ReadData
#  define Rte_Call_DataServices_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ConditionCheckRead DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ConditionCheckRead
#  define Rte_Call_DataServices_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ReadData DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ReadData
#  define Rte_Call_DataServices_CPU_Load_Read_CPU_load_histograms_ConditionCheckRead DataServices_CPU_Load_Read_CPU_load_histograms_ConditionCheckRead
#  define Rte_Call_DataServices_CPU_Load_Read_CPU_load_histograms_ReadData DataServices_CPU_Load_Read_CPU_load_histograms_ReadData
#  define Rte_Call_DataServices_CPU_Load_Read_CPU_load_histograms_ReadDataLength DataServices_CPU_Load_Read_CPU_load_histograms_ReadDataLength
#  define Rte_Call_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_ConditionCheckRead DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ConditionCheckRead
#  define Rte_Call_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_ReadData DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadData
#  define Rte_Call_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_ReadDataLength DataServices_Calibration_Identifications_CAL_ID_Read_CombinedDataElement_ReadDataLength
#  define Rte_Call_DataServices_Calibration_Identifications_CAL_ID_Write_Calibration_Identification_WriteData DataServices_Calibration_Identifications_CAL_ID_Write_CombinedDataElement_WriteData
#  define Rte_Call_DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items_WriteData DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items
#  define Rte_Call_DataServices_Current_Operating_Time_Read_Current_Operating_Time_ConditionCheckRead DataServices_Current_Operating_Time_Read_Current_Operating_Time_ConditionCheckRead
#  define Rte_Call_DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData
#  define Rte_Call_DataServices_Current_Operating_Time_Read_Operating_Time_Status_ConditionCheckRead DataServices_Current_Operating_Time_Read_Operating_Time_Status_ConditionCheckRead
#  define Rte_Call_DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData
#  define Rte_Call_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ConditionCheckRead DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ConditionCheckRead
#  define Rte_Call_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData
#  define Rte_Call_DataServices_Customer_Settings_Read_PS_Curve_Stat_ConditionCheckRead DataServices_Customer_Settings_Read_PS_Curve_Stat_ConditionCheckRead
#  define Rte_Call_DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData
#  define Rte_Call_DataServices_Cycle_configuration_Read_Cycles_ReadData DIA_runDidFD10_CycleConfigurationRead
#  define Rte_Call_DataServices_Cycle_configuration_Read_Cycles_WriteData DIA_runDidFD10_CycleConfigurationWrite
#  define Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ConditionCheckRead DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ConditionCheckRead
#  define Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData
#  define Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ConditionCheckRead DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ConditionCheckRead
#  define Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData
#  define Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ConditionCheckRead DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ConditionCheckRead
#  define Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData
#  define Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ConditionCheckRead DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ConditionCheckRead
#  define Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData
#  define Rte_Call_DataServices_DID_0131_SAR_Data_Storage_Status_ConditionCheckRead DataServices_DID_0131_SAR_Data_Storage_Status_ConditionCheckRead
#  define Rte_Call_DataServices_DID_0131_SAR_Data_Storage_Status_ReadData DataServices_DID_0131_SAR_Data_Storage_Status_ReadData
#  define Rte_Call_DataServices_DID_0131_SAR_Data_Storage_Status_WriteData DataServices_DID_0131_SAR_Data_Storage_Status_WriteData
#  define Rte_Call_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_ConditionCheckRead Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_ConditionCheckRead
#  define Rte_Call_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_ReadData Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_ReadData
#  define Rte_Call_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_WriteData Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_WriteData
#  define Rte_Call_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_ConditionCheckRead Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_ConditionCheckRead
#  define Rte_Call_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_ReadData Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_ReadData
#  define Rte_Call_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_WriteData Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_WriteData
#  define Rte_Call_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_ConditionCheckRead Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ConditionCheckRead
#  define Rte_Call_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_ReadData Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData
#  define Rte_Call_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_ConditionCheckRead Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ConditionCheckRead
#  define Rte_Call_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_ReadData Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData
#  define Rte_Call_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_ReadDataLength Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadDataLength
#  define Rte_Call_DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ConditionCheckRead DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ConditionCheckRead
#  define Rte_Call_DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData
#  define Rte_Call_DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ConditionCheckRead DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ConditionCheckRead
#  define Rte_Call_DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData
#  define Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ConditionCheckRead DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ConditionCheckRead
#  define Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData
#  define Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ConditionCheckRead DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ConditionCheckRead
#  define Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData
#  define Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ConditionCheckRead DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ConditionCheckRead
#  define Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData
#  define Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ConditionCheckRead DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ConditionCheckRead
#  define Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData
#  define Rte_Call_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ConditionCheckRead DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ConditionCheckRead
#  define Rte_Call_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData
#  define Rte_Call_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData
#  define Rte_Call_DataServices_Diagnostic_User_Role_Read_Cebas_UserRole_ConditionCheckRead Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ConditionCheckRead
#  define Rte_Call_DataServices_Diagnostic_User_Role_Read_Cebas_UserRole_ReadData Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData
#  define Rte_Call_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead
#  define Rte_Call_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData
#  define Rte_Call_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength
#  define Rte_Call_DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_ConditionCheckRead DIA_runDidF18C_EcuSerialNumberConditionCheckRead
#  define Rte_Call_DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_ReadData DIA_runDidF18C_EcuSerialNumberRead
#  define Rte_Call_DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_ReadDataLength DIA_runDidF18C_EcuSerialNumberReadDataLength
#  define Rte_Call_DataServices_ECU_Location_Read_Side_Allocation_ReadData DIA_runDidFD2F_EcuLocationRead
#  define Rte_Call_DataServices_ECU_Location_Read_Side_Allocation_WriteData DIA_runDidFD2F_EcuLocationWrite
#  define Rte_Call_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ConditionCheckRead DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ConditionCheckRead
#  define Rte_Call_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData
#  define Rte_Call_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadDataLength DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadDataLength
#  define Rte_Call_DataServices_ECU_serial_number_Read_ECU_traceability_number_ConditionCheckRead DIA_runDidFD03_ECUTraceabilityNumberConditionCheckRead
#  define Rte_Call_DataServices_ECU_serial_number_Read_ECU_traceability_number_ReadData DIA_runDidFD03_ECUTraceabilityNumberRead
#  define Rte_Call_DataServices_ECU_serial_number_Read_ECU_traceability_number_WriteData DIA_runDidFD03_ECUTraceabilityNumberWrite
#  define Rte_Call_DataServices_ECU_serial_number_Read_PCBA_Programmed_Part_number_ConditionCheckRead DIA_runDidFD03_PCBAProgrammedPartNumberConditionCheckRead
#  define Rte_Call_DataServices_ECU_serial_number_Read_PCBA_Programmed_Part_number_ReadData DIA_runDidFD03_PCBAProgrammedPartNumberRead
#  define Rte_Call_DataServices_ECU_serial_number_Read_PCBA_Programmed_Part_number_WriteData DIA_runDidFD03_PCBAProgrammedPartNumberWrite
#  define Rte_Call_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_ConditionCheckRead DataServices_Global_Time_Sync_Measured_Values_ConditionCheckRead
#  define Rte_Call_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_ReadData DataServices_Global_Time_Sync_Measured_Values_ReadData
#  define Rte_Call_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_ReadDataLength DataServices_Global_Time_Sync_Measured_Values_ReadDataLength
#  define Rte_Call_DataServices_HB_Calibration_Read_CombinedSignal_ConditionCheckRead DIA_runDidFD31_HBCalibrationWriteConditionCheckRead
#  define Rte_Call_DataServices_HB_Calibration_Read_CombinedSignal_ReadData DIA_runDidFD31_HBCalibrationRead
#  define Rte_Call_DataServices_HB_Calibration_Read_CombinedSignal_WriteData DIA_runDidFD31_HBCalibrationWrite
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ConditionCheckRead
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ConditionCheckRead
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ConditionCheckRead
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ConditionCheckRead
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ConditionCheckRead
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ConditionCheckRead
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ConditionCheckRead DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ConditionCheckRead
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData
#  define Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData
#  define Rte_Call_DataServices_HW_input_Read_Voltage_KL30t_ConditionCheckRead DIA_runDid0220_HW_input_Read_Voltage_KL30t_ConditionCheckRead
#  define Rte_Call_DataServices_HW_input_Read_Voltage_KL30t_ReadData DIA_runDid0220_HW_input_Read_Voltage_KL30t_ReadData
#  define Rte_Call_DataServices_HW_input_Read_Voltage_Motor_ConditionCheckRead DIA_runDid0220_HW_input_Read_Voltage_Motor_ConditionCheckRead
#  define Rte_Call_DataServices_HW_input_Read_Voltage_Motor_ReadData DIA_runDid0220_HW_input_Read_Voltage_Motor_ReadData
#  define Rte_Call_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ConditionCheckRead DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ConditionCheckRead
#  define Rte_Call_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData
#  define Rte_Call_DataServices_HardwareVersion_Read_HW_patch_level_ConditionCheckRead DataServices_HardwareVersion_Read_HW_patch_level_ConditionCheckRead
#  define Rte_Call_DataServices_HardwareVersion_Read_HW_patch_level_ReadData DataServices_HardwareVersion_Read_HW_patch_level_ReadData
#  define Rte_Call_DataServices_HardwareVersion_Read_HW_week_ConditionCheckRead DataServices_HardwareVersion_Read_HW_week_ConditionCheckRead
#  define Rte_Call_DataServices_HardwareVersion_Read_HW_week_ReadData DataServices_HardwareVersion_Read_HW_week_ReadData
#  define Rte_Call_DataServices_HardwareVersion_Read_HW_year_ConditionCheckRead DataServices_HardwareVersion_Read_HW_year_ConditionCheckRead
#  define Rte_Call_DataServices_HardwareVersion_Read_HW_year_ReadData DataServices_HardwareVersion_Read_HW_year_ReadData
#  define Rte_Call_DataServices_Hardware_Version_Information_Write_HW_patch_level_WriteData DIA_runDidFD50_Hardware_Version_Information_Write_HW_patch_level
#  define Rte_Call_DataServices_Hardware_Version_Information_Write_HW_week_WriteData DIA_runDidFD50_Hardware_Version_Information_Write_HW_week
#  define Rte_Call_DataServices_Hardware_Version_Information_Write_HW_year_WriteData DIA_runDidFD50_Hardware_Version_Information_Write_HW_year
#  define Rte_Call_DataServices_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ConditionCheckRead DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ConditionCheckRead
#  define Rte_Call_DataServices_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ReadData DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ReadData
#  define Rte_Call_DataServices_Internal_ECU_information_Read_ECU_Temperature_ConditionCheckRead DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ConditionCheckRead
#  define Rte_Call_DataServices_Internal_ECU_information_Read_ECU_Temperature_ReadData DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ReadData
#  define Rte_Call_DataServices_Internal_ECU_information_Read_MOTOR_Current_ConditionCheckRead DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ConditionCheckRead
#  define Rte_Call_DataServices_Internal_ECU_information_Read_MOTOR_Current_ReadData DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ReadData
#  define Rte_Call_DataServices_Last_Warm_Reset_Parameters_Read_Last_Detected_Warm_Reset_Cause_ConditionCheckRead DIA_runDidFD09_LastWarmReseConditionChecktRead_LastDetectedWarmResetCause
#  define Rte_Call_DataServices_Last_Warm_Reset_Parameters_Read_Last_Detected_Warm_Reset_Cause_ReadData DIA_runDidFD09_LastWarmResetRead_LastDetectedWarmResetCause
#  define Rte_Call_DataServices_Last_Warm_Reset_Parameters_Read_Reset_Cause_Counter_ConditionCheckRead DIA_runDidFD09_LastWarmResetConditionCheckRead_ResetCauseCounter
#  define Rte_Call_DataServices_Last_Warm_Reset_Parameters_Read_Reset_Cause_Counter_ReadData DIA_runDidFD09_LastWarmResetRead_ResetCauseCounter
#  define Rte_Call_DataServices_Measurement_Frame_Block_12_Config_Read_CombinedSignal_ConditionCheckRead DIA_runDidFDFF_MeasurementFrameBlock12ConfigConditionCheckRead
#  define Rte_Call_DataServices_Measurement_Frame_Block_12_Config_Read_CombinedSignal_ReadData DIA_runDidFDFF_MeasurementFrameBlock12ConfigRead
#  define Rte_Call_DataServices_Measurement_Frame_Block_12_Config_Read_CombinedSignal_WriteData DIA_runDidFDFF_MeasurementFrameBlock12ConfigWrite
#  define Rte_Call_DataServices_Measurement_Frames_Configuration_Read_CombinedSignal_ConditionCheckRead DIA_runDidFEFF_MeasuruementFrameConfigurationConditionCheckRead
#  define Rte_Call_DataServices_Measurement_Frames_Configuration_Read_CombinedSignal_ReadData DIA_runDidFEFF_MeasuruementFrameConfigurationRead
#  define Rte_Call_DataServices_Measurement_Frames_Configuration_Read_CombinedSignal_WriteData DIA_runDidFEFF_MeasuruementFrameConfigurationWrite
#  define Rte_Call_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ConditionCheckRead DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ConditionCheckRead
#  define Rte_Call_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData
#  define Rte_Call_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadDataLength DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadDataLength
#  define Rte_Call_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ConditionCheckRead DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ConditionCheckRead
#  define Rte_Call_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData
#  define Rte_Call_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_ConditionCheckRead DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ConditionCheckRead
#  define Rte_Call_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_ReadData DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadData
#  define Rte_Call_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_ReadDataLength DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadDataLength
#  define Rte_Call_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ConditionCheckRead DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ConditionCheckRead
#  define Rte_Call_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData
#  define Rte_Call_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadDataLength DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadDataLength
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Current_Value_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_ConditionCheckRead
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Current_Value_ReadData DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_Read
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Green_to_Yellow_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_ConditionCheckRead
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Green_to_Yellow_ReadData DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_Read
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Yellow_to_Red_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_ConditionCheckRead
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Yellow_to_Red_ReadData DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_Read
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Current_Value_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_ConditionCheckRead
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Current_Value_ReadData DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_Read
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Green_to_Yellow_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_ConditionCheckRead
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Green_to_Yellow_ReadData DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_Read
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Yellow_to_Red_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_ConditionCheckRead
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Yellow_to_Red_ReadData DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_Read
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ConditionCheckRead
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ReadData DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_Read
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Green_to_Yellow_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_ConditionCheckRead
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Green_to_Yellow_ReadData DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_Read
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Yellow_to_Red_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_ConditionCheckRead
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Yellow_to_Red_ReadData DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_Read
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Current_Value_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_ConditionCheckRead
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Current_Value_ReadData DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_Read
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Green_to_Yellow_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_ConditionCheckRead
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Green_to_Yellow_ReadData DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_Read
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Yellow_to_Red_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_ConditionCheckRead
#  define Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Yellow_to_Red_ReadData DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_Read
#  define Rte_Call_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ConditionCheckRead DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ConditionCheckRead
#  define Rte_Call_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData
#  define Rte_Call_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadDataLength DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadDataLength
#  define Rte_Call_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData
#  define Rte_Call_DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_ConditionCheckRead DIA_runDid0241_PRE_SAFE_Recorder_1_ConditionCheckRead
#  define Rte_Call_DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_ReadData DIA_runDid0241_PRE_SAFE_Recorder_1_ReadData
#  define Rte_Call_DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_ReadDataLength DIA_runDid0241_PRE_SAFE_Recorder_1_ReadDataLength
#  define Rte_Call_DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_WriteData DIA_runDid0241_PRE_SAFE_Recorder_1_WriteData
#  define Rte_Call_DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_ConditionCheckRead DIA_runDid0242_PRE_SAFE_Recorder_2_ConditionCheckRead
#  define Rte_Call_DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_ReadData DIA_runDid0242_PRE_SAFE_Recorder_2_ReadData
#  define Rte_Call_DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_ReadDataLength DIA_runDid0242_PRE_SAFE_Recorder_2_ReadDataLength
#  define Rte_Call_DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_WriteData DIA_runDid0242_PRE_SAFE_Recorder_2_WriteData
#  define Rte_Call_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_ConditionCheckRead DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ConditionCheckRead
#  define Rte_Call_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_ReadData DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_ReadData
#  define Rte_Call_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_WriteData DataServices_PreSafe_Cycles_Level_1_8_CombinedSignal_WriteData
#  define Rte_Call_DataServices_RandomNumber_Read_Generated_Random_Number_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead
#  define Rte_Call_DataServices_RandomNumber_Read_Generated_Random_Number_ReadData Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData
#  define Rte_Call_DataServices_RandomNumber_Read_Generated_Random_Number_Result_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead
#  define Rte_Call_DataServices_RandomNumber_Read_Generated_Random_Number_Result_ReadData Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData
#  define Rte_Call_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ConditionCheckRead DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ConditionCheckRead
#  define Rte_Call_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData
#  define Rte_Call_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadDataLength DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadDataLength
#  define Rte_Call_DataServices_Real_Time_Offset_Read_Real_Time_Offset_ConditionCheckRead Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ConditionCheckRead
#  define Rte_Call_DataServices_Real_Time_Offset_Read_Real_Time_Offset_ReadData Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData
#  define Rte_Call_DataServices_Real_Time_Offset_Read_TickCount_ConditionCheckRead Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ConditionCheckRead
#  define Rte_Call_DataServices_Real_Time_Offset_Read_TickCount_ReadData Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData
#  define Rte_Call_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_ConditionCheckRead DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ConditionCheckRead
#  define Rte_Call_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_ReadData DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData
#  define Rte_Call_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_WriteData DataServices_Release_Cycles_BSR_and_PreSafe_CombinedSignal_ReadData_WriteData
#  define Rte_Call_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ConditionCheckRead DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ConditionCheckRead
#  define Rte_Call_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData
#  define Rte_Call_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadDataLength DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadDataLength
#  define Rte_Call_DataServices_Reset_Cause_Management_Read_Reset_Cause_ConditionCheckRead DIA_runDidFD08_ResetCauseManagementConditionCheckRead
#  define Rte_Call_DataServices_Reset_Cause_Management_Read_Reset_Cause_ReadData DIA_runDidFD08_ResetCauseManagementRead
#  define Rte_Call_DataServices_Root_CA_Certificate_Read_Root_CA_Certificate_ConditionCheckRead Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ConditionCheckRead
#  define Rte_Call_DataServices_Root_CA_Certificate_Read_Root_CA_Certificate_ReadData Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadData
#  define Rte_Call_DataServices_Root_CA_Certificate_Read_Root_CA_Certificate_ReadDataLength Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadDataLength
#  define Rte_Call_DataServices_SSA_Version_Information_Read_SSA_Major_Version_ConditionCheckRead Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ConditionCheckRead
#  define Rte_Call_DataServices_SSA_Version_Information_Read_SSA_Major_Version_ReadData Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ReadData
#  define Rte_Call_DataServices_SSA_Version_Information_Read_SSA_Minor_Version_ConditionCheckRead Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ConditionCheckRead
#  define Rte_Call_DataServices_SSA_Version_Information_Read_SSA_Minor_Version_ReadData Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ReadData
#  define Rte_Call_DataServices_SSA_Version_Information_Read_SSA_Patch_Level_ConditionCheckRead Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ConditionCheckRead
#  define Rte_Call_DataServices_SSA_Version_Information_Read_SSA_Patch_Level_ReadData Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ReadData
#  define Rte_Call_DataServices_SW_Version_Read_SW_Version_ConditionCheckRead DIA_runDidFD01_SWVersionConditionCheckRead
#  define Rte_Call_DataServices_SW_Version_Read_SW_Version_ReadData DIA_runDidFD01_SWVersionRead
#  define Rte_Call_DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_ConditionCheckRead DIA_runDid0340_UniqueSeatbeltSerialNumberConditionCheckRead
#  define Rte_Call_DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_ReadData DIA_runDid0340_UniqueSeatbeltSerialNumberRead
#  define Rte_Call_DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_WriteData DIA_runDid0340_UniqueSeatbeltSerialNumberWrite
#  define Rte_Call_DataServices_SecOC_Local_TickCount_Read_TickCount_ConditionCheckRead Ssa_TimeM_DataServices_DID_018A_TickCount_ConditionCheckRead
#  define Rte_Call_DataServices_SecOC_Local_TickCount_Read_TickCount_ReadData Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData
#  define Rte_Call_DataServices_SecOC_PDU_Data_IDs_and_Key_CMACs_Read_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead
#  define Rte_Call_DataServices_SecOC_PDU_Data_IDs_and_Key_CMACs_Read_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData
#  define Rte_Call_DataServices_SecOC_PDU_Data_IDs_and_Key_CMACs_Read_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength
#  define Rte_Call_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_ConditionCheckRead Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ConditionCheckRead
#  define Rte_Call_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_ReadData Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadData
#  define Rte_Call_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_ReadDataLength Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadDataLength
#  define Rte_Call_DataServices_SecOC_Vehicle_Shared_Secret_Hash_Read_SecOC_Vehicle_Shared_Secret_Hash_ConditionCheckRead Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ConditionCheckRead
#  define Rte_Call_DataServices_SecOC_Vehicle_Shared_Secret_Hash_Read_SecOC_Vehicle_Shared_Secret_Hash_ReadData Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ReadData
#  define Rte_Call_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead
#  define Rte_Call_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData
#  define Rte_Call_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ConditionCheckRead Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead
#  define Rte_Call_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ReadData Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadData
#  define Rte_Call_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ReadDataLength Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength
#  define Rte_Call_DataServices_Security_Event_Log_Read_Security_Event_Log_ConditionCheckRead Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ConditionCheckRead
#  define Rte_Call_DataServices_Security_Event_Log_Read_Security_Event_Log_ReadData Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadData
#  define Rte_Call_DataServices_Security_Event_Log_Read_Security_Event_Log_ReadDataLength Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadDataLength
#  define Rte_Call_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ConditionCheckRead DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ConditionCheckRead
#  define Rte_Call_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData
#  define Rte_Call_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadDataLength DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadDataLength
#  define Rte_Call_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ConditionCheckRead DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ConditionCheckRead
#  define Rte_Call_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData
#  define Rte_Call_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadDataLength DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadDataLength
#  define Rte_Call_DataServices_Stack_Load_Read_Maximum_ConditionCheckRead DataServices_Stack_Load_Read_Maximum_ConditionCheckRead
#  define Rte_Call_DataServices_Stack_Load_Read_Maximum_ReadData DataServices_Stack_Load_Read_Maximum_ReadData
#  define Rte_Call_DataServices_Stack_Load_Read_Maximum_ReadDataLength DataServices_Stack_Load_Read_Maximum_ReadDataLength
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ConditionCheckRead
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ConditionCheckRead
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ConditionCheckRead
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ConditionCheckRead
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ConditionCheckRead
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ConditionCheckRead
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ConditionCheckRead DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ConditionCheckRead
#  define Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData
#  define Rte_Call_DataServices_Status_SSA_Pre_Compile_Switches_Read_Precompile_switch_ConditionCheckRead Ssa_Coding_DataServices_DID_0197_Precompile_switch_ConditionCheckRead
#  define Rte_Call_DataServices_Status_SSA_Pre_Compile_Switches_Read_Precompile_switch_ReadData Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData
#  define Rte_Call_DataServices_Steps_library_Read_Steps_ReadData DIA_runDidFD2A_StepsLibraryRead
#  define Rte_Call_DataServices_Steps_library_Read_Steps_WriteData DIA_runDidFD2A_StepsLibraryWrite
#  define Rte_Call_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ConditionCheckRead DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ConditionCheckRead
#  define Rte_Call_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData
#  define Rte_Call_DataServices_System_Time_read_Read_System_time_ConditionCheckRead DataServices_System_Time_read_Read_System_time_ConditionCheckRead
#  define Rte_Call_DataServices_System_Time_read_Read_System_time_ReadData DataServices_System_Time_read_Read_System_time_ReadData
#  define Rte_Call_DataServices_Task_Response_Time_Read_Task_histograms_ConditionCheckRead DataServices_Task_Response_Time_Read_Task_histograms_ConditionCheckRead
#  define Rte_Call_DataServices_Task_Response_Time_Read_Task_histograms_ReadData DataServices_Task_Response_Time_Read_Task_histograms_ReadData
#  define Rte_Call_DataServices_Task_Response_Time_Read_Task_histograms_ReadDataLength DataServices_Task_Response_Time_Read_Task_histograms_ReadDataLength
#  define Rte_Call_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ConditionCheckRead DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ConditionCheckRead
#  define Rte_Call_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ReadData DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ReadData
#  define Rte_Call_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData
#  define Rte_Call_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_ConditionCheckRead DataServices_Tensioning_Cycle_BSR_CombinedSignal_ConditionCheckRead
#  define Rte_Call_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_ReadData DataServices_Tensioning_Cycle_BSR_CombinedSignal_ReadData
#  define Rte_Call_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_WriteData DataServices_Tensioning_Cycle_BSR_CombinedSignal_WriteData
#  define Rte_Call_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ConditionCheckRead DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ConditionCheckRead
#  define Rte_Call_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData
#  define Rte_Call_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadDataLength DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadDataLength
#  define Rte_Call_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData
#  define Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Certificates_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead
#  define Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Certificates_ReadData Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData
#  define Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Certificates_ReadDataLength Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength
#  define Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Data_Signature_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead
#  define Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Data_Signature_ReadData Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData
#  define Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead
#  define Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Ephemeral_ECU_Public_Key_ReadData Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData
#  define Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Nonce_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead
#  define Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Nonce_ReadData Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData
#  define Rte_Call_DataServices_Trust_Model_Root_Replacement_Key_Read_Root_Replacement_Key_ConditionCheckRead Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ConditionCheckRead
#  define Rte_Call_DataServices_Trust_Model_Root_Replacement_Key_Read_Root_Replacement_Key_ReadData Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ReadData
#  define Rte_Call_DataServices_Trust_model_Backend_CA_certificate_Read_Trust_model_Backend_CA_certificate_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead
#  define Rte_Call_DataServices_Trust_model_Backend_CA_certificate_Read_Trust_model_Backend_CA_certificate_ReadData Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData
#  define Rte_Call_DataServices_Trust_model_Backend_CA_certificate_Read_Trust_model_Backend_CA_certificate_ReadDataLength Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength
#  define Rte_Call_DataServices_Trust_model_ECU_CSR_Read_Trust_model_ECU_CSR_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead
#  define Rte_Call_DataServices_Trust_model_ECU_CSR_Read_Trust_model_ECU_CSR_ReadData Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData
#  define Rte_Call_DataServices_Trust_model_ECU_CSR_Read_Trust_model_ECU_CSR_ReadDataLength Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength
#  define Rte_Call_DataServices_Trust_model_ECU_certificate_Read_Trust_model_ECU_Certificate_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead
#  define Rte_Call_DataServices_Trust_model_ECU_certificate_Read_Trust_model_ECU_Certificate_ReadData Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData
#  define Rte_Call_DataServices_Trust_model_ECU_certificate_Read_Trust_model_ECU_Certificate_ReadDataLength Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength
#  define Rte_Call_DataServices_Trust_model_Intermediate_CA_certificate_Read_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead
#  define Rte_Call_DataServices_Trust_model_Intermediate_CA_certificate_Read_Trust_model_Intermediate_CA_Certificate_ReadData Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData
#  define Rte_Call_DataServices_Trust_model_Intermediate_CA_certificate_Read_Trust_model_Intermediate_CA_Certificate_ReadDataLength Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength
#  define Rte_Call_DataServices_Trust_model_Root_CA_certificate_Read_Trust_model_Root_CA_certificate_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead
#  define Rte_Call_DataServices_Trust_model_Root_CA_certificate_Read_Trust_model_Root_CA_certificate_ReadData Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData
#  define Rte_Call_DataServices_Trust_model_Root_CA_certificate_Read_Trust_model_Root_CA_certificate_ReadDataLength Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength
#  define Rte_Call_DataServices_Trust_model_full_chain_of_trust_certificates_Read_Trust_model_certificates_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead
#  define Rte_Call_DataServices_Trust_model_full_chain_of_trust_certificates_Read_Trust_model_certificates_ReadData Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData
#  define Rte_Call_DataServices_Trust_model_full_chain_of_trust_certificates_Read_Trust_model_certificates_ReadDataLength Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadDataLength
#  define Rte_Call_DataServices_VINDataIdentifier_Read_VINDataIdentifier_ConditionCheckRead Ssa_Coding_DataServices_VINDataIdentifier_ConditionCheckRead
#  define Rte_Call_DataServices_VINDataIdentifier_Read_VINDataIdentifier_ReadData Ssa_Coding_DataServices_VINDataIdentifier_ReadData
#  define Rte_Call_DataServices_VINDataIdentifier_Read_VINDataIdentifier_WriteData Ssa_Coding_DataServices_VINDataIdentifier_WriteData
#  define Rte_Call_DataServices_VIN_Status_Read_VIN_Lock_Status_ConditionCheckRead Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ConditionCheckRead
#  define Rte_Call_DataServices_VIN_Status_Read_VIN_Lock_Status_ReadData Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData
#  define Rte_Call_DataServices_VIN_Status_Read_VIN_Status_ConditionCheckRead Ssa_Coding_DataServices_DID_018E_VIN_Status_ConditionCheckRead
#  define Rte_Call_DataServices_VIN_Status_Read_VIN_Status_ReadData Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_1_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Equipment_1_ConditionCheckRead
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_2_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Equipment_2_ConditionCheckRead
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_3_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Equipment_3_ConditionCheckRead
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_4_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Equipment_4_ConditionCheckRead
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_5_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Equipment_5_ConditionCheckRead
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_6_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Equipment_6_ConditionCheckRead
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ConditionCheckRead
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_ReadData DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_ReadData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_WriteData DataServices_Vehicle_Equipment_Read_Uberspannungsabbruchschwelle_WriteData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ConditionCheckRead
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_ReadData DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_ReadData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_WriteData DataServices_Vehicle_Equipment_Read_Uberspannungsbereichsschwelle_WriteData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ConditionCheckRead
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ConditionCheckRead DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ConditionCheckRead
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData
#  define Rte_Call_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData
#  define Rte_Call_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ConditionCheckRead DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ConditionCheckRead
#  define Rte_Call_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData
#  define Rte_Call_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ConditionCheckRead DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ConditionCheckRead
#  define Rte_Call_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ReadData DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ReadData
#  define Rte_Call_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData
#  define Rte_Call_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ConditionCheckRead DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ConditionCheckRead
#  define Rte_Call_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData
#  define Rte_Call_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData
#  define Rte_Call_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ConditionCheckRead DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ConditionCheckRead
#  define Rte_Call_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData
#  define Rte_Call_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData
#  define Rte_Call_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start_Start Ssa_ProcCtrl_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester
#  define Rte_Call_RoutineServices_Routine_Certificate_Self_Check_Start_Start Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check
#  define Rte_Call_RoutineServices_Routine_Check_Reprogramming_Preconditions_Start_Start DIA_runRid0203_CheckProgrammingPreconditionsStart
#  define Rte_Call_RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_Start RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_Start
#  define Rte_Call_RoutineServices_Routine_Cycle_Execution_Start_RequestResults DIA_runRidF703_CycleExecutionRequestResults
#  define Rte_Call_RoutineServices_Routine_Cycle_Execution_Start_Start DIA_runRidF703_CycleExecutionStart
#  define Rte_Call_RoutineServices_Routine_Cycle_Execution_Start_Stop DIA_runRidF703_CycleExecutionStop
#  define Rte_Call_RoutineServices_Routine_Enhance_Access_Rights_Start_Start Ssa_ProcCtrl_RoutineServices_Routine_Enhance_Access_Rights
#  define Rte_Call_RoutineServices_Routine_Erase_All_Start_Start RoutineServices_Routine_Erase_All_Start
#  define Rte_Call_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start_Start Ssa_ProcCtrl_RoutineServices_Routine_Evaluate_Data_Verification_Certificate
#  define Rte_Call_RoutineServices_Routine_Force_External_WDG_Start_Start RoutineServices_Routine_Force_External_WDG_Start
#  define Rte_Call_RoutineServices_Routine_Get_Certificate_Entry_Start_Start Ssa_KeyM_RoutineServices_Get_Certificate_Entry_Start
#  define Rte_Call_RoutineServices_Routine_PreCheckProgrammingDependencies_Start_Start DataServices_PreCheckProgrammingDependencies_Start
#  define Rte_Call_RoutineServices_Routine_Replace_Certificates_Start_Start Ssa_ProcCtrl_RoutineServices_Routine_Replace_Certificates
#  define Rte_Call_RoutineServices_Routine_Replace_Trust_model_Certificates_Start_Start Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates
#  define Rte_Call_RoutineServices_Routine_Replace_Trust_model_Root_Certificate_Start_Start Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate
#  define Rte_Call_RoutineServices_Routine_Reset_VINDataIdentifier_Start_Start Ssa_ProcCtrl_RoutineServices_Routine_Reset_VIN_Values
#  define Rte_Call_RoutineServices_Routine_Status_of_Post_Production_Flag_Start_RequestResults Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_RequestResults
#  define Rte_Call_RoutineServices_Routine_Status_of_Post_Production_Flag_Start_Start Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Start
#  define Rte_Call_RoutineServices_Routine_Status_of_Post_Production_Flag_Start_Stop Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Stop
#  define Rte_Call_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start_Start Ssa_ProcCtrl_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time
#  define Rte_Call_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_RequestResults Synchronize_to_Non_volatile_Memory_RequestResults
#  define Rte_Call_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_Start DataServices_Synchronize_to_Non_volatile_Memory_Start
#  define Rte_Call_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_Stop Synchronize_to_Non_volatile_Memory_Stop
#  define Rte_Call_RoutineServices_Routine_Trigger_BSR_Start_RequestResults DIA_runRid0329_TriggerBSRRequestResults
#  define Rte_Call_RoutineServices_Routine_Trigger_BSR_Start_Start DIA_runRid0329_TriggerBSRStart
#  define Rte_Call_RoutineServices_Routine_Trigger_BSR_Start_Stop DIA_runRid0329_TriggerBSRStop
#  define Rte_Call_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_RequestResults DIA_runRid0302_TriggerPresafeDisplayRequestRequestResults
#  define Rte_Call_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_Start DIA_runRid0302_TriggerPresafeDisplayRequestStart
#  define Rte_Call_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_Stop DIA_runRid0302_TriggerPresafeDisplayRequestStop
#  define Rte_Call_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_RequestResults DIA_runRid0330_TriggerTensioningCycleRequestResults
#  define Rte_Call_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_Start DIA_runRid0330_TriggerTensioningCycleStart
#  define Rte_Call_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_Stop DIA_runRid0330_TriggerTensioningCycleStop
#  define Rte_Call_RoutineServices_Routine_Trust_Model_Generate_Key_Pair_Start_Start Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair
#  define Rte_Call_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Start Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution
#  define Rte_Call_RoutineServices_Routine_Verify_Signature_Start_Start Ssa_ProcCtrl_RoutineServices_Routine_Verify_Signature
#  define Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_Coding_Confirmation Ssa_Coding_ServiceRequestNotification_Confirmation
#  define Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_Coding_Indication Ssa_Coding_ServiceRequestNotification_Indication
#  define Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation
#  define Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication
#  define Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_RightsM_Confirmation Ssa_RightsM_ServiceRequestNotification_Confirmation
#  define Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_RightsM_Indication Ssa_RightsM_ServiceRequestNotification_Indication

# endif /* !defined(RTE_CORE) */


# define Dcm_START_SEC_CODE
# include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Dcm_MainFunction Dcm_MainFunction
#  define RTE_RUNNABLE_GetActiveProtocol Dcm_GetActiveProtocol
#  define RTE_RUNNABLE_GetRequestKind Dcm_GetRequestKind
#  define RTE_RUNNABLE_GetSesCtrlType Dcm_GetSesCtrlType
#  define RTE_RUNNABLE_ResetToDefaultSession Dcm_ResetToDefaultSession
#  define RTE_RUNNABLE_SetActiveDiagnostic Dcm_SetActiveDiagnostic
# endif

FUNC(void, Dcm_CODE) Dcm_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType, AUTOMATIC, RTE_DCM_APPL_VAR) ActiveProtocol); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetRequestKind(uint16 TesterSourceAddress, P2VAR(Dcm_RequestKindType, AUTOMATIC, RTE_DCM_APPL_VAR) RequestKind); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SesCtrlType); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_ResetToDefaultSession(void); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Dcm_CODE) Dcm_SetActiveDiagnostic(boolean active); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Dcm_STOP_SEC_CODE
# include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DCMServices_E_NOT_OK (1U)

#  define RTE_E_DCMServices_E_OK (0U)

#  define RTE_E_DataServices_AEC_Status_Read_AEC_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_AEC_Status_Read_AEC_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_Basic_ACL_Hash_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_Basic_ACL_Hash_E_NOT_OK (1U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Major_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Major_E_NOT_OK (1U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Minor_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Minor_E_NOT_OK (1U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Patch_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Patch_E_NOT_OK (1U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Generation_Time_GTC_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Generation_Time_GTC_E_NOT_OK (1U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Hash_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Hash_E_NOT_OK (1U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Major_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Major_E_NOT_OK (1U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Minor_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Minor_E_NOT_OK (1U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Patch_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Patch_E_NOT_OK (1U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Generation_Time_GTC_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Generation_Time_GTC_E_NOT_OK (1U)

#  define RTE_E_DataServices_ActiveDiagnosticInformation_Read_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ActiveDiagnosticInformation_Read_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_ActiveDiagnosticInformation_Read_Session_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ActiveDiagnosticInformation_Read_Session_E_NOT_OK (1U)

#  define RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_E_NOT_OK (1U)

#  define RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_E_NOT_OK (1U)

#  define RTE_E_DataServices_Availability_Data_Read_Availability_Data_PRE_SAFE_haptic_warning_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Availability_Data_Read_Availability_Data_PRE_SAFE_haptic_warning_E_NOT_OK (1U)

#  define RTE_E_DataServices_BSR_Counter_read_Read_BSR_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_BSR_Counter_read_Read_BSR_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Backend_CA_Certificate_Identification_Read_Backend_CA_SubjectKeyIdentifier_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Backend_CA_Certificate_Identification_Read_Backend_CA_SubjectKeyIdentifier_E_NOT_OK (1U)

#  define RTE_E_DataServices_Backend_CA_Certificate_Read_Backend_CA_Certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Backend_CA_Certificate_Read_Backend_CA_Certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_E_NOT_OK (1U)

#  define RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_week_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_week_E_NOT_OK (1U)

#  define RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_year_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_year_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_1_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_2_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_2_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_3_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_3_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_4_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_4_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_5_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_5_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_6_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_6_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_7_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_7_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_8_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_8_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Supply_battery_voltage_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Supply_battery_voltage_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_output_Read_CANoutput1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_output_Read_CANoutput1_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_output_Read_PS_Curve_XX_Stat_ST3_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_output_Read_PS_Curve_XX_Stat_ST3_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_E_NOT_OK (1U)

#  define RTE_E_DataServices_CPU_Load_Read_CPU_load_histograms_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CPU_Load_Read_CPU_load_histograms_E_NOT_OK (1U)

#  define RTE_E_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Calibration_Identifications_CAL_ID_Write_Calibration_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Calibration_Identifications_CAL_ID_Write_Calibration_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items_E_NOT_OK (1U)

#  define RTE_E_DataServices_Current_Operating_Time_Read_Current_Operating_Time_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Current_Operating_Time_Read_Current_Operating_Time_E_NOT_OK (1U)

#  define RTE_E_DataServices_Current_Operating_Time_Read_Operating_Time_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Current_Operating_Time_Read_Operating_Time_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_E_NOT_OK (1U)

#  define RTE_E_DataServices_Customer_Settings_Read_PS_Curve_Stat_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Customer_Settings_Read_PS_Curve_Stat_E_NOT_OK (1U)

#  define RTE_E_DataServices_Cycle_configuration_Read_Cycles_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Cycle_configuration_Read_Cycles_E_NOT_OK (1U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_E_NOT_OK (1U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_E_NOT_OK (1U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_E_NOT_OK (1U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0131_SAR_Data_Storage_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0131_SAR_Data_Storage_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_E_NOT_OK (1U)

#  define RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_E_NOT_OK (1U)

#  define RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK (1U)

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

#  define RTE_E_DataServices_Diagnostic_User_Role_Read_Cebas_UserRole_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Diagnostic_User_Role_Read_Cebas_UserRole_E_NOT_OK (1U)

#  define RTE_E_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_E_NOT_OK (1U)

#  define RTE_E_DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_ECU_Location_Read_Side_Allocation_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ECU_Location_Read_Side_Allocation_E_NOT_OK (1U)

#  define RTE_E_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_E_NOT_OK (1U)

#  define RTE_E_DataServices_ECU_serial_number_Read_ECU_traceability_number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ECU_serial_number_Read_ECU_traceability_number_E_NOT_OK (1U)

#  define RTE_E_DataServices_ECU_serial_number_Read_PCBA_Programmed_Part_number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ECU_serial_number_Read_PCBA_Programmed_Part_number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_E_NOT_OK (1U)

#  define RTE_E_DataServices_HB_Calibration_Read_CombinedSignal_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HB_Calibration_Read_CombinedSignal_E_NOT_OK (1U)

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

#  define RTE_E_DataServices_HW_input_Read_Voltage_KL30t_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HW_input_Read_Voltage_KL30t_E_NOT_OK (1U)

#  define RTE_E_DataServices_HW_input_Read_Voltage_Motor_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HW_input_Read_Voltage_Motor_E_NOT_OK (1U)

#  define RTE_E_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_HardwareVersion_Read_HW_patch_level_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HardwareVersion_Read_HW_patch_level_E_NOT_OK (1U)

#  define RTE_E_DataServices_HardwareVersion_Read_HW_week_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HardwareVersion_Read_HW_week_E_NOT_OK (1U)

#  define RTE_E_DataServices_HardwareVersion_Read_HW_year_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HardwareVersion_Read_HW_year_E_NOT_OK (1U)

#  define RTE_E_DataServices_Hardware_Version_Information_Write_HW_patch_level_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Hardware_Version_Information_Write_HW_patch_level_E_NOT_OK (1U)

#  define RTE_E_DataServices_Hardware_Version_Information_Write_HW_week_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Hardware_Version_Information_Write_HW_week_E_NOT_OK (1U)

#  define RTE_E_DataServices_Hardware_Version_Information_Write_HW_year_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Hardware_Version_Information_Write_HW_year_E_NOT_OK (1U)

#  define RTE_E_DataServices_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_E_NOT_OK (1U)

#  define RTE_E_DataServices_Internal_ECU_information_Read_ECU_Temperature_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Internal_ECU_information_Read_ECU_Temperature_E_NOT_OK (1U)

#  define RTE_E_DataServices_Internal_ECU_information_Read_MOTOR_Current_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Internal_ECU_information_Read_MOTOR_Current_E_NOT_OK (1U)

#  define RTE_E_DataServices_Last_Warm_Reset_Parameters_Read_Last_Detected_Warm_Reset_Cause_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Last_Warm_Reset_Parameters_Read_Last_Detected_Warm_Reset_Cause_E_NOT_OK (1U)

#  define RTE_E_DataServices_Last_Warm_Reset_Parameters_Read_Reset_Cause_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Last_Warm_Reset_Parameters_Read_Reset_Cause_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Measurement_Frame_Block_12_Config_Read_CombinedSignal_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Measurement_Frame_Block_12_Config_Read_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_DataServices_Measurement_Frames_Configuration_Read_CombinedSignal_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Measurement_Frames_Configuration_Read_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_E_NOT_OK (1U)

#  define RTE_E_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_E_NOT_OK (1U)

#  define RTE_E_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Current_Value_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Current_Value_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Green_to_Yellow_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Green_to_Yellow_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Yellow_to_Red_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Yellow_to_Red_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Current_Value_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Current_Value_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Green_to_Yellow_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Green_to_Yellow_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Yellow_to_Red_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Yellow_to_Red_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Green_to_Yellow_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Green_to_Yellow_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Yellow_to_Red_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Yellow_to_Red_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Current_Value_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Current_Value_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Green_to_Yellow_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Green_to_Yellow_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Yellow_to_Red_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Yellow_to_Red_E_NOT_OK (1U)

#  define RTE_E_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_E_NOT_OK (1U)

#  define RTE_E_DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_E_NOT_OK (1U)

#  define RTE_E_DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_E_NOT_OK (1U)

#  define RTE_E_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_DataServices_RandomNumber_Read_Generated_Random_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_RandomNumber_Read_Generated_Random_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_RandomNumber_Read_Generated_Random_Number_Result_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_RandomNumber_Read_Generated_Random_Number_Result_E_NOT_OK (1U)

#  define RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_E_NOT_OK (1U)

#  define RTE_E_DataServices_Real_Time_Offset_Read_Real_Time_Offset_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Real_Time_Offset_Read_Real_Time_Offset_E_NOT_OK (1U)

#  define RTE_E_DataServices_Real_Time_Offset_Read_TickCount_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Real_Time_Offset_Read_TickCount_E_NOT_OK (1U)

#  define RTE_E_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_E_NOT_OK (1U)

#  define RTE_E_DataServices_Reset_Cause_Management_Read_Reset_Cause_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Reset_Cause_Management_Read_Reset_Cause_E_NOT_OK (1U)

#  define RTE_E_DataServices_Root_CA_Certificate_Read_Root_CA_Certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Root_CA_Certificate_Read_Root_CA_Certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_SSA_Version_Information_Read_SSA_Major_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SSA_Version_Information_Read_SSA_Major_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_SSA_Version_Information_Read_SSA_Minor_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SSA_Version_Information_Read_SSA_Minor_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_SSA_Version_Information_Read_SSA_Patch_Level_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SSA_Version_Information_Read_SSA_Patch_Level_E_NOT_OK (1U)

#  define RTE_E_DataServices_SW_Version_Read_SW_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SW_Version_Read_SW_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_E_NOT_OK (1U)

#  define RTE_E_DataServices_SecOC_Local_TickCount_Read_TickCount_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SecOC_Local_TickCount_Read_TickCount_E_NOT_OK (1U)

#  define RTE_E_DataServices_SecOC_PDU_Data_IDs_and_Key_CMACs_Read_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SecOC_PDU_Data_IDs_and_Key_CMACs_Read_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK (1U)

#  define RTE_E_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_E_NOT_OK (1U)

#  define RTE_E_DataServices_SecOC_Vehicle_Shared_Secret_Hash_Read_SecOC_Vehicle_Shared_Secret_Hash_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SecOC_Vehicle_Shared_Secret_Hash_Read_SecOC_Vehicle_Shared_Secret_Hash_E_NOT_OK (1U)

#  define RTE_E_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_E_NOT_OK (1U)

#  define RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK (1U)

#  define RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_E_NOT_OK (1U)

#  define RTE_E_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Stack_Load_Read_Maximum_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Stack_Load_Read_Maximum_E_NOT_OK (1U)

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

#  define RTE_E_DataServices_Status_SSA_Pre_Compile_Switches_Read_Precompile_switch_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Status_SSA_Pre_Compile_Switches_Read_Precompile_switch_E_NOT_OK (1U)

#  define RTE_E_DataServices_Steps_library_Read_Steps_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Steps_library_Read_Steps_E_NOT_OK (1U)

#  define RTE_E_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_E_NOT_OK (1U)

#  define RTE_E_DataServices_System_Time_read_Read_System_time_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_System_Time_read_Read_System_time_E_NOT_OK (1U)

#  define RTE_E_DataServices_Task_Response_Time_Read_Task_histograms_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Task_Response_Time_Read_Task_histograms_E_NOT_OK (1U)

#  define RTE_E_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_E_NOT_OK (1U)

#  define RTE_E_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Certificates_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Certificates_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Data_Signature_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Data_Signature_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Ephemeral_ECU_Public_Key_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Ephemeral_ECU_Public_Key_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Nonce_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Nonce_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_Model_Root_Replacement_Key_Read_Root_Replacement_Key_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_Model_Root_Replacement_Key_Read_Root_Replacement_Key_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_model_Backend_CA_certificate_Read_Trust_model_Backend_CA_certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_model_Backend_CA_certificate_Read_Trust_model_Backend_CA_certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_model_ECU_CSR_Read_Trust_model_ECU_CSR_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_model_ECU_CSR_Read_Trust_model_ECU_CSR_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_model_ECU_certificate_Read_Trust_model_ECU_Certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_model_ECU_certificate_Read_Trust_model_ECU_Certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_model_Intermediate_CA_certificate_Read_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_model_Intermediate_CA_certificate_Read_Trust_model_Intermediate_CA_Certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_model_Root_CA_certificate_Read_Trust_model_Root_CA_certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_model_Root_CA_certificate_Read_Trust_model_Root_CA_certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_Trust_model_full_chain_of_trust_certificates_Read_Trust_model_certificates_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Trust_model_full_chain_of_trust_certificates_Read_Trust_model_certificates_E_NOT_OK (1U)

#  define RTE_E_DataServices_VINDataIdentifier_Read_VINDataIdentifier_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_VINDataIdentifier_Read_VINDataIdentifier_E_NOT_OK (1U)

#  define RTE_E_DataServices_VIN_Status_Read_VIN_Lock_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_VIN_Status_Read_VIN_Lock_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_VIN_Status_Read_VIN_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_VIN_Status_Read_VIN_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_1_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_2_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_2_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_3_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_3_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_4_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_4_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_5_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_5_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_6_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Equipment_6_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_E_NOT_OK (1U)

#  define RTE_E_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_E_NOT_OK (1U)

#  define RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_E_NOT_OK (1U)

#  define RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Certificate_Self_Check_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Certificate_Self_Check_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Certificate_Self_Check_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Check_Reprogramming_Preconditions_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Check_Reprogramming_Preconditions_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Check_Reprogramming_Preconditions_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Cycle_Execution_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Cycle_Execution_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Enhance_Access_Rights_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Enhance_Access_Rights_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Enhance_Access_Rights_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Erase_All_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Erase_All_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Erase_All_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Force_External_WDG_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Force_External_WDG_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Force_External_WDG_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Get_Certificate_Entry_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Get_Certificate_Entry_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Get_Certificate_Entry_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_PreCheckProgrammingDependencies_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_PreCheckProgrammingDependencies_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_PreCheckProgrammingDependencies_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Replace_Certificates_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Replace_Certificates_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Replace_Certificates_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Replace_Trust_model_Certificates_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Replace_Trust_model_Certificates_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Replace_Trust_model_Certificates_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Replace_Trust_model_Root_Certificate_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Replace_Trust_model_Root_Certificate_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Replace_Trust_model_Root_Certificate_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Reset_VINDataIdentifier_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Reset_VINDataIdentifier_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Reset_VINDataIdentifier_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Status_of_Post_Production_Flag_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Status_of_Post_Production_Flag_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Status_of_Post_Production_Flag_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Trigger_BSR_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Trigger_BSR_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Trigger_BSR_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Trust_Model_Generate_Key_Pair_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Trust_Model_Generate_Key_Pair_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Trust_Model_Generate_Key_Pair_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Verify_Signature_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Verify_Signature_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Verify_Signature_Start_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED (8U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_DCM_H */

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

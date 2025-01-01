/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version:
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.3.10.18.1.11 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup TEMPLATE_FILES_Group_Example Group_Example_Name_In_Document
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_DIA_AC_DiagOnCAN.h"
#include "DIA.h"
#include "Nvp_Generated.h"
#include "vstdlib.h"
#include "common.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
#define DIA_FD10_CYCLES_SIZE sizeof(NVP_BLOCK_ID_CYCLE_0_StorageType)
#define DIA_FD2A_STEPS_SIZE sizeof(NVP_BLOCK_ID_STEP_0_StorageType)

#define DIA_RAM_ADDRESS_START 0x70000000u
#define DIA_RAM_ADDRESS_END 0x70017F00u
#define DIA_WRITEBYMEM_LENGTH_MAX 0x07u

#define KU8_TWENTYFOUR 0x18u
#define KU8_EIGHTS     0x08u

#define DIA_TEMPERATURE_SENSOR_OFFSET_POINT_SIZE 1u
#define DIA_VELOCITY_PID_PARAM_SIZE 30u
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/**
 * \brief
 *		Defined macro from C file.
 */
#define DIA_AC_DiagOnCAN_START_SEC_VAR_UNSPECIFIED
#include <DIA_AC_DiagOnCAN_MemMap.h>
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/**
 * \brief
 * 		Flag to describe the NvM Queue Status for the large DIDs
 */
static boolean DIA_bIsNvmQueued = B_FALSE;

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
/**
 * \brief
 *		This variable should be in upper defined group.
 * \remarks
 *		This is a example of remark of a variable.
 */

/**
 * \brief
 *		Defined macro from C file.
 */
#define DIA_AC_DiagOnCAN_STOP_SEC_VAR_UNSPECIFIED
#include <DIA_AC_DiagOnCAN_MemMap.h>

/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		Defined macro from C file.
 */
#define DIA_AC_DiagOnCAN_START_SEC_CONST_UNSPECIFIED
#include <DIA_AC_DiagOnCAN_MemMap.h>
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		This variable should be in upper defined group.
 * \remarks
 *		This is a example of remark of a variable.
 */

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/
/**
 * \brief
 *		This is a example of description of a variable.
 * \remarks
 *		This variable should not be in upper defined group.
 */

/**
 * \brief
 *		Defined macro from C file.
 */
#define DIA_AC_DiagOnCAN_STOP_SEC_CONST_UNSPECIFIED
#include <DIA_AC_DiagOnCAN_MemMap.h>
/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define DIA_AC_DiagOnCAN_START_SEC_CODE
#include "DIA_AC_DiagOnCAN_MemMap.h"

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0013, DSG_DIA_MMA_0023, DSG_DIA_MMA_0269]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD03_ECUTraceabilityNumberWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType_1 OpStatus, P2VAR(Dcm_NegativeResponseCodeType_1, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
 
   if (B_FALSE == DIA_bIsNvmQueued)
   {
      VStdMemCpy(&NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData, Data, sizeof(NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData));

      ret = Rte_Call_NvMService_NVP_BLOCK_ID_AEE_TRACEABILITY_WriteBlock(Data);

      DIA_bIsNvmQueued = B_TRUE;
   }
   
   (void)Rte_Call_NvMService_NVP_BLOCK_ID_AEE_TRACEABILITY_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_ECU_serial_number_Read_ECU_traceability_number_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_ECU_serial_number_Read_ECU_traceability_number_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;

      *ErrorCode = DCM_E_POSITIVERESPONSE;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0269]
 **/
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE)
DIA_runDidFD03_PCBAProgrammedPartNumberWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
 
   if (B_FALSE == DIA_bIsNvmQueued)
   {
      VStdMemCpy(&NVP_BLOCK_ID_PCBA_PPN_RamBlockData, Data, sizeof(NVP_BLOCK_ID_PCBA_PPN_RamBlockData));

      ret = Rte_Call_NvMService_NVP_BLOCK_ID_PCBA_PPN_WriteBlock(Data);

      DIA_bIsNvmQueued = B_TRUE;
   }
   
   (void)Rte_Call_NvMService_NVP_BLOCK_ID_PCBA_PPN_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_ECU_serial_number_Read_PCBA_Programmed_Part_number_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_ECU_serial_number_Read_PCBA_Programmed_Part_number_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;

      *ErrorCode = DCM_E_POSITIVERESPONSE;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0008, DSG_DIA_MMA_0018, DSG_DIA_MMA_0227]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD2F_EcuLocationWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType_1 OpStatus, P2VAR(Dcm_NegativeResponseCodeType_1, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
 
   if (B_FALSE == DIA_bIsNvmQueued)
   {
      NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation = Data[0u];

      ret = Rte_Call_NvMService_NVP_BLOCK_ID_ECU_LOCATION_WriteBlock(&NVP_BLOCK_ID_ECU_LOCATION_RamBlockData);

      DIA_bIsNvmQueued = B_TRUE;
   }

   (void)Rte_Call_NvMService_NVP_BLOCK_ID_ECU_LOCATION_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_DID_FD2F_EcuLocationData_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_DID_FD2F_EcuLocationData_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;

      *ErrorCode = DCM_E_POSITIVERESPONSE;
   }
   
   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0010, DSG_DIA_MMA_0020, DSG_DIA_MMA_0030 ]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD10_CycleConfigurationWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
 
   if (B_FALSE == DIA_bIsNvmQueued)
   {
      VStdMemCpy(&NVP_BLOCK_ID_CYCLE_0_RamBlockData, Data, DIA_FD10_CYCLES_SIZE);

      ret = Rte_Call_NvMService_NVP_BLOCK_ID_CYCLE_WriteBlock(Data);

      DIA_bIsNvmQueued = B_TRUE;
   }

   (void)Rte_Call_NvMService_NVP_BLOCK_ID_CYCLE_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_Cycle_configuration_Read_Cycles_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_Cycle_configuration_Read_Cycles_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;

      *ErrorCode = DCM_E_POSITIVERESPONSE;
   }
   
   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0012, DSG_DIA_MMA_0022, DSG_DIA_MMA_0032 ]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD2A_StepsLibraryWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
 
   if (B_FALSE == DIA_bIsNvmQueued)
   {
      VStdMemCpy(&NVP_BLOCK_ID_STEP_0_RamBlockData, Data, DIA_FD2A_STEPS_SIZE);

      ret = Rte_Call_NvMService_NVP_BLOCK_ID_STEP_WriteBlock(Data);

      DIA_bIsNvmQueued = B_TRUE;
   }

   (void)Rte_Call_NvMService_NVP_BLOCK_ID_STEP_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_Steps_library_Read_Steps_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_Steps_library_Read_Steps_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;

      *ErrorCode = DCM_E_POSITIVERESPONSE;
   }
   
   return ret;
}

/**
 * \brief
 *     Function used to update block configuration of measurement frame
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 * \exception
 *     None
 * \pre
 *     DIA_runDidFEFF_MeasuruementFrameConfigurationWrite_Timing - needs to be ran previously
 * \post
 *     None
 * \return
 *     Status of the NVP write
 *   [COVERS: DSG_DIA_MMA_0106]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFEFF_MeasuruementFrameConfigurationWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
 
   if (B_FALSE == DIA_bIsNvmQueued)
   {
      if (NULL_PTR != Data)
      {
         VStdMemCpy(&NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_RamBlockData, Data, sizeof(NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_RamBlockData));

         ret = Rte_Call_NvMService_NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_WriteBlock(&NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_RamBlockData);

         *ErrorCode = DCM_E_POSITIVERESPONSE;
      }
      else
      {
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }

      DIA_bIsNvmQueued = B_TRUE;
   }

   (void)Rte_Call_NvMService_NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_Measurement_Frames_Configuration_Read_CombinedSignal_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_Measurement_Frames_Configuration_Read_CombinedSignal_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;
   }
   
   return ret;

}

/**
 * \brief
 *     Function used to update block configuration of measurement block 12
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *
 * \return
 *     E_OK
 *   [COVERS: DSG_DIA_MMA_0107, DSG_DIA_MMA_0184, DSG_DIA_MMA_0185]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFDFF_MeasurementFrameBlock12ConfigWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
   uint32 u32ramAddress = KU8_ZERO;
   uint8 u8sizeToWrite = KU8_ZERO;

   if (B_FALSE == DIA_bIsNvmQueued)
   {
      if (NULL_PTR != Data)
      {
         u32ramAddress = (uint32)(((uint32)Data[KU8_ZERO]) << KU8_TWENTYFOUR);
         u32ramAddress |= (uint32)(((uint32)Data[KU8_ONE]) << KU8_SIXTEEN);
         u32ramAddress |= (uint32)(((uint32)Data[KU8_TWO]) << KU8_EIGHT);
         u32ramAddress |= (uint32)((uint32)Data[KU8_THREE]);

         u8sizeToWrite = *(Data + KU8_FOUR);
         if ((DIA_RAM_ADDRESS_START <= (u32ramAddress)) && (DIA_RAM_ADDRESS_END >= (u32ramAddress + u8sizeToWrite)))
         {
            if (DIA_WRITEBYMEM_LENGTH_MAX >= u8sizeToWrite)
            {
               VStdMemCpy(&NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData, Data, sizeof(NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData));

               ret = Rte_Call_NvMService_NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_WriteBlock(&NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData);

               *ErrorCode = DCM_E_POSITIVERESPONSE;
            }
            else
            {
               *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
         }
         else
         {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
         }
      }
      else
      {
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }

      DIA_bIsNvmQueued = B_TRUE;
   }

   (void)Rte_Call_NvMService_NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_Measurement_Frame_Block_12_Config_Read_CombinedSignal_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_Measurement_Frame_Block_12_Config_Read_CombinedSignal_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;
   }
   
   return ret;
}

/**
 * \brief
 *     Function used to update block HB calibration
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 *     ErrorCode - Error code
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *
 * \return
 *     E_OK
 *   [COVERS: DSG_DIA_MMA_0098, DSG_DIA_MMA_0228, DSG_DIA_MMA_0229]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD31_HBCalibrationWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;

   if (B_FALSE == DIA_bIsNvmQueued)
   {
      if (NULL_PTR != Data)
      {
         VStdMemCpy(&NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData, Data, sizeof(NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData));

         ret = Rte_Call_NvMService_NVP_BLOCK_ID_HB_CALIBRATION_WriteBlock(&NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData);

         *ErrorCode = DCM_E_POSITIVERESPONSE;
      }
      else
      {
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }

      DIA_bIsNvmQueued = B_TRUE;
   }
   
   (void)Rte_Call_NvMService_NVP_BLOCK_ID_HB_CALIBRATION_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_HB_Calibration_Read_CombinedSignal_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_HB_Calibration_Read_CombinedSignal_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;
   }
   
   return ret;
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DIA_runDidFD50_Hardware_Version_Information_Write_HW_patch_level
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Hardware_Version_Information_Write_HW_patch_level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DIA_runDidFD50_Hardware_Version_Information_Write_HW_patch_level(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Hardware_Version_Information_Write_HW_patch_level_DCM_E_PENDING
 *   RTE_E_DataServices_Hardware_Version_Information_Write_HW_patch_level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DIA_runDidFD50_Hardware_Version_Information_Write_HW_patch_level_doc
 *********************************************************************************************************************/
/**
* \brief
*     RID FD50
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
*     ErrorCode - Error Code
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0264]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_patch_level(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DIA_runDidFD50_Hardware_Version_Information_Write_HW_patch_level (returns application error)
 *********************************************************************************************************************/
   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
 
   if (B_FALSE == DIA_bIsNvmQueued)
   {
      NVP_BLOCK_ID_HW_VERSION_RamBlockData.NVP_au8HwVersion[2] = Data[0];

      Rte_Call_NvMService_NVP_BLOCK_ID_HW_VERSION_SetRamBlockStatus(TRUE);

      DIA_bIsNvmQueued = B_TRUE;
   }
   
   (void)Rte_Call_NvMService_NVP_BLOCK_ID_HW_VERSION_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_Hardware_Version_Information_Write_HW_patch_level_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_Hardware_Version_Information_Write_HW_patch_level_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;

      *ErrorCode = DCM_E_POSITIVERESPONSE;
   }
   
   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DIA_runDidFD50_Hardware_Version_Information_Write_HW_week
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Hardware_Version_Information_Write_HW_week>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DIA_runDidFD50_Hardware_Version_Information_Write_HW_week(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Hardware_Version_Information_Write_HW_week_DCM_E_PENDING
 *   RTE_E_DataServices_Hardware_Version_Information_Write_HW_week_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DIA_runDidFD50_Hardware_Version_Information_Write_HW_week_doc
 *********************************************************************************************************************/
/**
* \brief
*     RID FD50
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
*     ErrorCode - Error Code
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0264]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_week(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DIA_runDidFD50_Hardware_Version_Information_Write_HW_week (returns application error)
 *********************************************************************************************************************/
   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
 
   if (B_FALSE == DIA_bIsNvmQueued)
   {
      NVP_BLOCK_ID_HW_VERSION_RamBlockData.NVP_au8HwVersion[1] = Data[0];

      Rte_Call_NvMService_NVP_BLOCK_ID_HW_VERSION_SetRamBlockStatus(TRUE);

      DIA_bIsNvmQueued = B_TRUE;
   }

   (void)Rte_Call_NvMService_NVP_BLOCK_ID_HW_VERSION_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_Hardware_Version_Information_Write_HW_week_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_Hardware_Version_Information_Write_HW_week_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;

      *ErrorCode = DCM_E_POSITIVERESPONSE;
   }
   
   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DIA_runDidFD50_Hardware_Version_Information_Write_HW_year
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Hardware_Version_Information_Write_HW_year>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DIA_runDidFD50_Hardware_Version_Information_Write_HW_year(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Hardware_Version_Information_Write_HW_year_DCM_E_PENDING
 *   RTE_E_DataServices_Hardware_Version_Information_Write_HW_year_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DIA_runDidFD50_Hardware_Version_Information_Write_HW_year_doc
 *********************************************************************************************************************/
/**
* \brief
*     RID FD50
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
*     ErrorCode - Error Code
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0264]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_year(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
* Symbol: DIA_runDidFD50_Hardware_Version_Information_Write_HW_year (returns application error)
*********************************************************************************************************************/
   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
 
   if (B_FALSE == DIA_bIsNvmQueued)
   {
      NVP_BLOCK_ID_HW_VERSION_RamBlockData.NVP_au8HwVersion[0] = Data[0];

      Rte_Call_NvMService_NVP_BLOCK_ID_HW_VERSION_SetRamBlockStatus(TRUE);

      DIA_bIsNvmQueued = B_TRUE;
   }
   
   (void)Rte_Call_NvMService_NVP_BLOCK_ID_HW_VERSION_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_Hardware_Version_Information_Write_HW_year_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_Hardware_Version_Information_Write_HW_year_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;

      *ErrorCode = DCM_E_POSITIVERESPONSE;
   }
   
   return ret;

/**********************************************************************************************************************
* DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
*********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_DCM_E_PENDING
 *   RTE_E_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID FD30
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
*     ErrorCode - Error Code
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0290]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData (returns application error)
 *********************************************************************************************************************/

   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
 
   if (B_FALSE == DIA_bIsNvmQueued)
   {
      VStdMemCpy(&NVP_BLOCK_TEMP_SENSOR_TABLE_RamBlockData.NVP_s8TempOffsetChamberNTC, Data, DIA_TEMPERATURE_SENSOR_OFFSET_POINT_SIZE);

      ret = Rte_Call_NvMService_NVP_BLOCK_TEMP_SENSOR_TABLE_WriteBlock(Data);

      DIA_bIsNvmQueued = B_TRUE;
   }
   
   (void)Rte_Call_NvMService_NVP_BLOCK_TEMP_SENSOR_TABLE_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;

      *ErrorCode = DCM_E_POSITIVERESPONSE;
   }

   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_VELOCITY_PID_PARAM_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_VELOCITY_PID_PARAM_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_NVP_BLOCK_ID_VELOCITY_PID_PARAM_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data30ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_DCM_E_PENDING
 *   RTE_E_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID FDDF
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
*     ErrorCode - Error Code
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0288]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData (returns application error)
 *********************************************************************************************************************/
   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
 
   if (B_FALSE == DIA_bIsNvmQueued)
   {
      VStdMemCpy(&NVP_BLOCK_ID_VELOCITY_PID_PARAM_RamBlockData, Data, DIA_VELOCITY_PID_PARAM_SIZE);

      ret = Rte_Call_NvMService_NVP_BLOCK_ID_VELOCITY_PID_PARAM_WriteBlock(Data);

      DIA_bIsNvmQueued = B_TRUE;
   }
   
   (void)Rte_Call_NvMService_NVP_BLOCK_ID_VELOCITY_PID_PARAM_GetErrorStatus(&errorStatus);

   if (NVM_REQ_PENDING == errorStatus)
   {
      ret = RTE_E_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_DCM_E_PENDING;

      OpStatus = RTE_E_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_DCM_E_PENDING;
   }
   else
   {
      DIA_bIsNvmQueued = B_FALSE;

      ret = RTE_E_OK;

      OpStatus = RTE_E_OK;

      *ErrorCode = DCM_E_POSITIVERESPONSE;
   }

   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#define DIA_AC_DiagOnCAN_STOP_SEC_CODE
#include "DIA_AC_DiagOnCAN_MemMap.h"

/******************************************************************************
 Evolution of the component

 created by : T. DEMIREL

 $Log: DIA_WriteDataByIdentifier.c  $
 Revision 1.3.10.18.1.11 2024/04/01 14:19:58CEST Tudor Gligor (tudor.gligor) 
 Update DIA Design for R9.0 Release:
 Update new names for the R9.0 DIDs & RIDs  after their implementation inside the Design Document
 Code traceability for R9.0 new Diagnostic DIDs & RIDs
 Revision 1.3.10.18.1.10 2024/02/28 10:45:56EET Tudor Gligor (tudor.gligor) 
 Implement 31 01 F782 Erase All Start Routine for ALV Blocks (w/o SSA managed blocks)
 Revision 1.3.10.18.1.9 2024/02/19 16:43:53EET Tudor Gligor (tudor.gligor) 
 Implement 2nd part of ECU_serial_number(FD03)= PCBA Programmed Part Number:
 NvP Block + Fee & NvM Block + DCM Config & DIA code
 Also the KeyM Revert back to 4.5.3
 Revision 1.3.10.18.1.8 2024/02/19 14:20:51EET Tudor Gligor (tudor.gligor) 
 Implement Velocity PI Regulation Coefficient (FDDF) inside DIA_ReadDID & DIA_WriteDID
 Revision 1.3.10.18.1.7 2024/02/13 15:59:41CET Tudor Gligor (tudor.gligor) 
 Implement Temperature Sensor Calibration Point (FD30) inside DIA_ReadDID & DIA_WriteDID
 Revision 1.3.10.18.1.6 2024/01/29 10:54:37EET Tudor Gligor (tudor.gligor) 
 Add missing DIA Design Traceability for R8.1 Release
 Revision 1.3.10.18.1.5 2024/01/18 10:17:12EET Tudor Gligor (tudor.gligor) 
 Update Design Traceability for DIA R8.1 Release
 Revision 1.3.10.18.1.4 2023/12/22 08:45:11EET Roberto Cristoi (roberto.cristoi) 
 Implemented FD03; part number dummy for now
 Revision 1.3.10.18.1.3 2023/11/01 11:51:13EET Tudor Gligor (tudor.gligor) 
 Update file after Review
 Revision 1.3.10.18.1.2 2023/10/23 18:23:07EEST Tudor Gligor (tudor.gligor) 
 Implement a mechanism for the Large DIDs to throw DCM Pending whenever the NvM is in NvM Pending State.
 Revision 1.3.10.18.1.1 2023/08/28 10:27:25EEST Tudor Gligor (tudor.gligor) 
 CDD Integration 06.08.08.160 & ECU Individual ACL (Variant Coding Issue)
 Revision 1.3.10.18 2023/05/11 10:40:07EEST Tudor Gligor (tudor.gligor) 
 Update DIA Design Document, DIA Code Design Traceability & DIA Design Configurator Traceability
 Revision 1.3.10.17 2023/05/05 14:21:12EEST Emanuel Jivan (emanuel.jivan) 
 Implemented FD50, write HW Version, and F150 now reads from Nvm.
 Revision 1.3.10.16 2023/05/04 13:41:31EEST Tudor Gligor (tudor.gligor) 
 Minor QAC fixes for DIA - R6.0
 Revision 1.3.10.15 2023/04/10 11:52:38EEST Tudor Gligor (tudor.gligor) 
 Update Source Files related to the 05.07.02 CDD Integration
 Revision 1.3.10.14 2023/02/22 18:16:22EET Tudor Gligor (tudor.gligor) 
 Update Design traceability in the code for R5.0 Release for DIA Component
 Revision 1.3.10.13 2023/02/21 13:59:51EET Tudor Gligor (tudor.gligor) 
 Update DIA & DIA_WriteDataByIdentifier with Design traceability after Code Review
 Revision 1.3.10.12 2022/09/06 17:28:10EEST Tudor Gligor (tudor.gligor) 
 [SRC] Code Update for QAC fixes - DIA
 Revision 1.3.10.11 2022/07/13 18:01:57EEST Emanuel Jivan (emanuel.jivan) 
 Implemented services 23/3D and corrected 2E FDFF.
 Revision 1.3.10.10 2022/07/12 13:55:13EEST Emanuel Jivan (emanuel.jivan)
 DV UDS update.
 Revision 1.3.10.9 2022/06/15 09:27:27EEST Emanuel Jivan (emanuel.jivan)
 Traceability update.
 Revision 1.3.10.8 2022/05/30 17:23:40EEST Mihai Ianos (mihai.ianos)
 Updated write services for Measurement Frame config write
 Revision 1.3.10.7 2022/05/26 11:53:33EEST Emanuel Jivan (emanuel.jivan)
 Updated FD2A and FD10, to take and write size of NVP blocks instead of fixed size; Added FEFF write runnables.
 Revision 1.3.10.6 2022/03/25 15:06:55EET Emanuel Jivan (emanuel.jivan)
 Updated code template, added tracebility in code and fixed tracebility in design.
 Revision 1.3.10.5 2022/01/21 10:17:27EET Emanuel Jivan (emanuel.jivan)
 Added write to RAM block where missing from write frunctions.
 Revision 1.3.10.4 2022/01/20 09:55:27EET Emanuel Jivan (emanuel.jivan)
 Added FD10 and FD2A for service 0x22 and 0x2E.
 Revision 1.3.10.3 2022/01/19 10:45:23EET Roberto Cristoi (roberto.cristoi)
 New DCM Session added: 0x7E-Development-- can be accessed via authentication with Production user role
 The following dids have been added (can be accessed only when in Development session(0x7E):
 -ECU_Location-> Read/Write implemented
 -Seatbelt_assy_serial_number
 -ECU_serial_number
 -Cycle_configuration
 -Steps library
 Revision 1.3.10.2 2022/01/07 15:27:48EET Andreea Negrea (andreea.negrea)
 Initial revision
 Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj
 Revision 1.1.1.37.2.43.1.3 2021/07/02 14:36:33EEST Dan Dustinta (dan.dustinta)
 First revision
******************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/

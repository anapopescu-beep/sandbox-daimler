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
$Revision: 1.7.2.15 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DIA/Quality_Assurance/Static_Analysis/project.pj $
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
#define DIA_FD09_WARM_RESET_SIZE 4u
#define DIA_DIAG_BUFFER_SIZE 8195u
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
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		This is a example of description of a variable.
 * \remarks
 *		This is a example of remark of a variable.
 */

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
/* Set the SW version */
LOCAL const uint8 cau8SWVersion[KU8_SW_VERSION_LENGTH] = "ER01860H.P91";

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
*     RID FD03
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0268]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD03_ECUTraceabilityNumberConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* \brief
*     DID FD03
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0268]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD03_ECUTraceabilityNumberRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData, sizeof(NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData));

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* \brief
*     DID FD03
* \param
*     ErrorCode - Negative response code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0268]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD03_PCBAProgrammedPartNumberConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* \brief
*     DID FD03
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0268]
**/
FUNC(Std_ReturnType, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runDidFD03_PCBAProgrammedPartNumberRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_PCBA_PPN_RamBlockData, sizeof(NVP_BLOCK_ID_PCBA_PPN_RamBlockData));

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Returns ECU location.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0007, DSG_DIA_MMA_0017 ]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD2F_EcuLocationRead(Dcm_OpStatusType_1 OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      Data[0] = NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation;

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0009, DSG_DIA_MMA_0019, DSG_DIA_MMA_0029 ]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD10_CycleConfigurationRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_CYCLE_0_RamBlockData, DIA_FD10_CYCLES_SIZE);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0011, DSG_DIA_MMA_0021, DSG_DIA_MMA_0031 ]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD2A_StepsLibraryRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_STEP_0_RamBlockData, DIA_FD2A_STEPS_SIZE);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0094]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD09_LastWarmReseConditionChecktRead_LastDetectedWarmResetCause(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0095]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD09_LastWarmResetConditionCheckRead_ResetCauseCounter(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR)  ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0092, DSG_DIA_MMA_0172, DSG_DIA_MMA_0173]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD09_LastWarmResetRead_LastDetectedWarmResetCause(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_WARM_RESET_RamBlockData.NVP_u32WarmResetCause, DIA_FD09_WARM_RESET_SIZE);
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Here write function descriptions.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0093, DSG_DIA_MMA_0174, DSG_DIA_MMA_0175]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD09_LastWarmResetRead_ResetCauseCounter(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      /* Fill-in the response data bytes */
      if (KU8_MAX != NVP_BLOCK_ID_WARM_RESET_RamBlockData.NVP_u32WarmResetCounter)
      {
         VStdMemCpy(Data, &NVP_BLOCK_ID_WARM_RESET_RamBlockData.NVP_u32WarmResetCounter, DIA_FD09_WARM_RESET_SIZE);
      }
      else
      {
         /* set counter message to zero in case counter is on initial position */
         *Data = KU8_ZERO;
      }

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Precheck for measurement frame block config
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     E_OK/E_NOT_OK
 *   [COVERS: DSG_DIA_MMA_0103]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFEFF_MeasuruementFrameConfigurationConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Function used to write the current measurement frame block config to DCM service
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     E_OK/E_NOT_OK
 *   [COVERS: DSG_DIA_MMA_0102, DSG_DIA_MMA_0180, DSG_DIA_MMA_0181]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFEFF_MeasuruementFrameConfigurationRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_RamBlockData, sizeof(NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_RamBlockData));

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Returns last detected warm reset.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0090, DSG_DIA_MMA_0170, DSG_DIA_MMA_0171]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD08_ResetCauseManagementRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;
   uint32 u32WarmResetCause;
   
   Rte_Call_icsResetCause_GetResetCause(&u32WarmResetCause);

   if (NULL_PTR != Data)
   {
      /* if POR flag is set, send POR message */
      if (KU32_ZERO != (KU32_POWER_ON_RESET_MASK & u32WarmResetCause))
      {
         *Data = KU8_RESET_CAUSE_POR;
      }
      else if (KU32_ZERO != (KU32_BATTERY_LOSS_MASK & u32WarmResetCause))
      {
         *Data = KU8_RESET_CAUSE_LOW_VOLTAGE;
      }
      else
      {
         /* conditions mutually exclusive in RCM */
         /*QAC_WARNING S 3605 ++*/ /* switch variable is not integer allowed by current standard */
         switch (u32WarmResetCause)
         {
         case KU32_CRYSTAL_FAILURE_MASK:
            *Data = KU8_WARM_RESET_CAUSE_CRYSTAL;
            break;
         case KU32_PLL_FAILURE_MASK:
            *Data = KU8_WARM_RESET_CAUSE_PLL;
            break;
         case KU32_INTERNAL_WDG_MASK:
            *Data = KU8_WARM_RESET_CAUSE_WD;
            break;
         case KU32_SW_INTERNAL_WDG_MASK:
            *Data = KU8_RESET_CAUSE_INTERNAL_WATCHDOG;
            break;
         case KU32_SW_RESET_MASK:
            *Data = KU8_RESET_CAUSE_RESET_BY_DIAG;
            break;
         case KU32_BTLD_RESET_MASK:
            *Data = KU8_RESET_CAUSE_BTLD;
            break;
         case KU32_ECC_RAM_MASK:
            *Data = KU8_RESET_CAUSE_RAM_ECC;
            break;
         case KU32_ECC_PFLASH_MASK:
            *Data = KU8_RESET_CAUSE_PFLASH_ECC;
            break;
         case KU32_OS_EXCEPTION_MASK:
            *Data = KU8_RESET_CAUSE_OS_EXCEPTION;
            break;
         case KU32_INVALID_INTERRUPT_MASK:
            *Data = KU8_RESET_CAUSE_INVALID_INT;
            break;
         case KU32_WAKE_UP_EVENT_MASK:
            *Data = KU8_RESET_CAUSE_WAKEUP;
            break;
         case KU32_SW_WDG_TEST_MASK:
            *Data = KU8_RESET_CAUSE_WD_TEST;
            break;
         case KU32_ECC_UNIDENTIFIED_MASK:
            *Data = KU8_RESET_CAUSE_UNIDENTIFIED_ECC;
            break;
         case KU32_STACK_OVERFLOW_MASK:
            *Data = KU8_RESET_CAUSE_STACK_OVERFLOW;
            break;
         case KU32_RAM_DATA_CORRUPTED:
            *Data = KU8_RESET_CAUSE_RAM_DATA_CORRUPTED;
            break;
         case KU32_ECC_E2P_MASK:
            *Data = KU8_RESET_CAUSE_E2P_ECC;
            break;
         case KU32_EXTERNAL_WDG_MASK:
            *Data = KU8_RESET_CAUSE_EXTERNAL_WATCHDOG;
            break;
         case KU32_RESET_CAUSE_UNKNOWN:
         default:
            *Data = KU8_WARM_RESET_CAUSE_UNKNOWN;
            break;
         }
      }

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0091]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD08_ResetCauseManagementConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Returns HB calibration.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0096, DSG_DIA_MMA_0176, DSG_DIA_MMA_0177]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD31_HBCalibrationRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData, sizeof(NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData));

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0097]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFD31_HBCalibrationWriteConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Returns value of measurement frame block 12 NVM block.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0104, DSG_DIA_MMA_0182, DSG_DIA_MMA_0183]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFDFF_MeasurementFrameBlock12ConfigRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData, sizeof(NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData));

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0105]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFDFF_MeasurementFrameBlock12ConfigConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Returns status of every AEC.
 * \param
 *     Data - Pointer to diagnostic data buffer
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0099, DSG_DIA_MMA_0178]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFE00_AECStatusRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;
   uint16 u16EventID;
   uint16 u16DataIndex;
   volatile uint8 u8EventID;

   if (NULL_PTR != Data)
   {
      /* Parse all AEC IDs and read its status */
      for (u16EventID = KU8_ONE; u16EventID <= (KU8_DIA_NUMBER_OF_AEC + KU8_ONE); u16EventID++)
      {
         u8EventID = (uint8)u16EventID;
         u16DataIndex = (uint8)(u16EventID * KU8_THREE) - KU8_THREE;

         if (DIA_DIAG_BUFFER_SIZE > u16DataIndex)
         {
            *(Data + u16DataIndex) = u8EventID;
            *(Data + u16DataIndex + KU8_ONE) = KU8_ZERO;
            Rte_Call_pclAecStatus_GetAecStatus(u16EventID, (Data + (u16EventID * KU16_THREE) - KU16_ONE));
         }
         else
         {
            //do nothing
         }
      }
      /* positive response since last AEC was processed */
      OpStatus = RTE_E_OK;
      ret = RTE_E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
 * \brief
 *     Determines length of data response for AEC status.
 * \param
 *     DataLength - Pointer to diagnostic data response length
 *     OpStatus - Operation status
 * \exception
 *     Here write function exceptions.
 * \pre
 *     Here write function pre conditions.
 * \post
 *     Here write function post conditions.
 * \return
 *     Standard return type
 *   [COVERS: DSG_DIA_MMA_0100, DSG_DIA_MMA_0179]
 **/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFE00_AECStatusReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != DataLength)
   {
      *DataLength = KU8_DIA_NUMBER_OF_AEC * KU8_THREE;

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0101]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE)
DIA_runDidFE00_AECStatusConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD01_SWVersionConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0224, DSG_DIA_MMA_0225]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD01_SWVersionRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data)
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, cau8SWVersion, KU8_SW_VERSION_LENGTH);
      
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0289]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{

   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;

}

/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0289]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{

   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_TEMP_SENSOR_TABLE_RamBlockData.NVP_s8TempOffsetChamberNTC, DIA_TEMPERATURE_SENSOR_OFFSET_POINT_SIZE);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;

}

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Negative response code 
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0287]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != ErrorCode)
   {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;

}

/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0287]
**/
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_VELOCITY_PID_PARAM_RamBlockData, DIA_VELOCITY_PID_PARAM_SIZE);

      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;
}


#define DIA_AC_DiagOnCAN_STOP_SEC_CODE
#include "DIA_AC_DiagOnCAN_MemMap.h"

/******************************************************************************
 Evolution of the component

 created by : T. DEMIREL

 $Log: DIA_ReadDataByIdentifier_Old.c  $
 Revision 1.7.2.15 2024/04/08 14:04:39CEST Tudor Gligor (tudor.gligor) 
 Update QAC for DIA Component after traceability updates for R9.0
 Revision 1.4.1.24.1.22 2024/04/01 15:19:58EEST Tudor Gligor (tudor.gligor) 
 Update DIA Design for R9.0 Release:
 Update new names for the R9.0 DIDs & RIDs  after their implementation inside the Design Document
 Code traceability for R9.0 new Diagnostic DIDs & RIDs
 Revision 1.4.1.24.1.21 2024/03/27 09:23:00EET Emanuel Jivan (emanuel.jivan) 
 Versioning update for ER01860H.P91.
 Revision 1.4.1.24.1.20 2024/02/19 16:43:53EET Tudor Gligor (tudor.gligor) 
 Implement 2nd part of ECU_serial_number(FD03)= PCBA Programmed Part Number:
 NvP Block + Fee & NvM Block + DCM Config & DIA code
 Also the KeyM Revert back to 4.5.3
 Revision 1.4.1.24.1.19 2024/02/19 14:20:51EET Tudor Gligor (tudor.gligor) 
 Implement Velocity PI Regulation Coefficient (FDDF) inside DIA_ReadDID & DIA_WriteDID
 Revision 1.4.1.24.1.18 2024/02/13 15:59:41CET Tudor Gligor (tudor.gligor) 
 Implement Temperature Sensor Calibration Point (FD30) inside DIA_ReadDID & DIA_WriteDID
 Revision 1.4.1.24.1.17 2024/02/08 14:00:33EET Roberto Cristoi (roberto.cristoi) 
 interal sw version 
 ER01861H.P90
 Revision 1.4.1.24.1.16 2024/02/08 12:09:14EET Tudor Gligor (tudor.gligor) 
 Replace FD09 NvMBlock Range Check instead of KU32_MAX to KU8_MAX that was causing AdjustSecTickCount issue
 Revision 1.4.1.24.1.15 2024/02/07 10:50:40EET Roberto Cristoi (roberto.cristoi) 
 R09.0 versioning
 Revision 1.4.1.24.1.14 2024/01/30 11:19:46EET Tudor Gligor (tudor.gligor) 
 FD09 Hotfix: 
 Replaced uint32 cast with VStdMemCpy(Data, WarmResetCounter or WarmResetCause, 4u)
 Set Counter Message to 0 was replaced with uint8
 Revision 1.4.1.24.1.13 2024/01/18 10:17:12EET Tudor Gligor (tudor.gligor) 
 Update Design Traceability for DIA R8.1 Release
 Revision 1.4.1.24.1.12 2024/01/10 12:53:56EET Mirela Obada (mirela.obada) 
 Versioning update 8.1
 Revision 1.4.1.24.1.11 2024/01/09 15:03:04EET Roberto Cristoi (roberto.cristoi) 
 R08.1 versioning
 Revision 1.4.1.24.1.10 2023/12/22 08:45:11EET Roberto Cristoi (roberto.cristoi) 
 Implemented FD03; part number dummy for now
 Revision 1.4.1.24.1.9 2023/12/07 13:18:34EET Roberto Cristoi (roberto.cristoi) 
 ER01861H.P82 versioning
 Revision 1.4.1.24.1.8 2023/11/24 10:35:17EET Tudor Gligor (tudor.gligor) 
 Update R8.0 Patch 1 =  ER01860H.P82 Versioning
 Revision 1.4.1.24.1.7 2023/11/15 13:32:55EET Mihai Ianos (mihai.ianos) 
 Updated internal SW version to P81
 Revision 1.4.1.24.1.6 2023/11/09 16:08:49EET Mirela Obada (mirela.obada) 
 Update for R08.0 release
 Revision 1.4.1.24.1.5 2023/10/06 14:10:57EEST Mirela Obada (mirela.obada) 
 Update software version for R07.2
 Revision 1.4.1.24.1.4 2023/10/05 09:59:37EEST Razvan Badiu (razvan.badiu) 
 read reset reason from RCM
 Revision 1.4.1.24.1.3 2023/09/25 16:22:54EEST Mirela Obada (mirela.obada) 
 Update sw and customer version for P72
 Revision 1.4.1.24.1.2 2023/08/28 10:27:23EEST Tudor Gligor (tudor.gligor) 
 CDD Integration 06.08.08.160 & ECU Individual ACL (Variant Coding Issue)
 Revision 1.4.1.24.1.1 2023/08/22 13:01:05EEST Tudor Gligor (tudor.gligor) 
 Revert CDD Integration 06.08.08
 Revision 1.4.1.24 2023/06/15 09:28:20EEST Andreea Negrea (andreea.negrea) 
 Sw versioning update for R6.1
 Revision 1.4.1.23 2023/05/15 16:28:42EEST Stefan Dominte (stefan.dominte) 
  Versioning update files for R06.0 patch 1 release
 Revision 1.4.1.22 2023/04/28 14:11:14EEST Roberto Cristoi (roberto.cristoi) 
 Versioning update R06.0
 Revision 1.4.1.21 2023/03/08 15:43:00EET Roberto Cristoi (roberto.cristoi) 
 SW versioning update R05.1
 Revision 1.4.1.20 2023/02/24 10:35:43EET Tudor Gligor (tudor.gligor) 
 Update DIA Design with R5.0 Content by removing 2x BSW Routines and adding them inside DCM ARXML (trace towards Architecture) & traceability issues
 Revision 1.4.1.19 2023/02/22 18:16:22EET Tudor Gligor (tudor.gligor) 
 Update Design traceability in the code for R5.0 Release for DIA Component
 Revision 1.4.1.18 2023/02/06 09:38:13EET Roberto Cristoi (roberto.cristoi) 
 Updated internal version to ER01860H.P51
 Revision 1.4.1.17 2023/02/01 14:54:50EET Andreea Negrea (andreea.negrea) 
 Update internal SW version
 Revision 1.4.1.16 2023/01/11 10:00:12EET Emanuel Jivan (emanuel.jivan) 
 Fixed 22 FD01 returning NOT_OK.
 Revision 1.4.1.15 2023/01/10 11:44:53EET Emanuel Jivan (emanuel.jivan) 
 Updated diagnostics with V060 config, modified 0241 and 0200 format and added 22 FD01.
 Revision 1.4.1.14 2022/09/06 17:28:10EEST Tudor Gligor (tudor.gligor) 
 [SRC] Code Update for QAC fixes - DIA
 Revision 1.4.1.13 2022/07/15 11:13:55EEST Emanuel Jivan (emanuel.jivan) 
 Fixed 22 FD09.
 Revision 1.4.1.12 2022/07/14 17:19:00EEST Emanuel Jivan (emanuel.jivan) 
 Fixed 22 FE00, and F703 can now do pending.
 Revision 1.4.1.11 2022/07/12 13:55:12EEST Emanuel Jivan (emanuel.jivan)
 DV UDS update.
 Revision 1.4.1.10 2022/06/15 09:27:28EEST Emanuel Jivan (emanuel.jivan)
 Traceability update.
 Revision 1.4.1.9 2022/05/30 17:23:20EEST Mihai Ianos (mihai.ianos)
 Updated read services for Measurement Frame
 Revision 1.4.1.8 2022/05/30 13:26:59EEST Septimiu Vintila (septimiu.vintila)
 Reset Cause & Counter added.
 Revision 1.4.1.7 2022/05/26 11:53:32EEST Emanuel Jivan (emanuel.jivan)
 Updated FD2A and FD10, to take and write size of NVP blocks instead of fixed size;
 Revision 1.4.1.6 2022/03/25 15:06:55EET Emanuel Jivan (emanuel.jivan)
 Updated code template, added tracebility in code and fixed tracebility in design.
 Revision 1.4.1.5 2022/01/21 10:16:56EET Emanuel Jivan (emanuel.jivan)
 Removed FD8B.
 Revision 1.4.1.4 2022/01/20 09:55:27EET Emanuel Jivan (emanuel.jivan)
 Added FD10 and FD2A for service 0x22 and 0x2E.
 Revision 1.4.1.3 2022/01/19 10:45:23EET Roberto Cristoi (roberto.cristoi)
 New DCM Session added: 0x7E-Development-- can be accessed via authentication with Production user role
 The following dids have been added (can be accessed only when in Development session(0x7E):
 -ECU_Location-> Read/Write implemented
 -Seatbelt_assy_serial_number
 -ECU_serial_number
 -Cycle_configuration
 -Steps library
 Revision 1.4.1.2 2022/01/07 15:24:12EET Andreea Negrea (andreea.negrea)
 Initial revision
 Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj
 Revision 1.1 2021/11/01 10:25:52EET Andreea Negrea (andreea.negrea)
 First revision

******************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/

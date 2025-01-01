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
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.3.2.18 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/CIL/Implementation/src/project.pj $
 */

/**
 *  @defgroup TEMPLATE_FILES_Group_Example Group_Example_Name_In_Document
 *  This is a new created group, this will create a new man3 file with 
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file. 
 */

/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "Rte_CIL_AC_CommunicationInteractionLayer.h"
#include "Nvp_Generated.h"
#include "Nvp_Cfg.h"
#include "config.h"

#include "CIL.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/* All block identifiers constants and associated bit fields for measurement frames */
/**
 * \brief
 * 		Measure frame block id 01 for sending mask.
 */
#define CU8_BLOCK_ID_01                ((uint8)1)
/**
 * \brief
 * 		Block to send id mask 01.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_01   ((uint32)0x00000001)

/**
 * \brief
 * 		Measure frame block id 02 for sending mask.
 */
#define CU8_BLOCK_ID_02                ((uint8)2)
/**
 * \brief
 * 		Block to send id mask 02.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_02   ((uint32)0x00000002)

/**
 * \brief
 * 		Measure frame block id 03 for sending mask.
 */
#define CU8_BLOCK_ID_03                ((uint8)3)
/**
 * \brief
 * 		Block to send id mask 03.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_03   ((uint32)0x00000004)

/**
 * \brief
 * 		Measure frame block id 04 for sending mask.
 */
#define CU8_BLOCK_ID_04                ((uint8)4)
/**
 * \brief
 * 		Block to send id mask 04.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_04   ((uint32)0x00000008)

/**
 * \brief
 * 		Measure frame block id 05 for sending mask.
 */
#define CU8_BLOCK_ID_05                ((uint8)5)
/**
 * \brief
 * 		Block to send id mask 05.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_05   ((uint32)0x00000010)

/**
 * \brief
 * 		Measure frame block id 06 for sending mask.
 */
#define CU8_BLOCK_ID_06                ((uint8)6)
/**
 * \brief
 * 		Block to send id mask 06.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_06   ((uint32)0x00000020)

/**
 * \brief
 * 		Measure frame block id 07 for sending mask.
 */
#define CU8_BLOCK_ID_07                ((uint8)7)
/**
 * \brief
 * 		Block to send id mask 07.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_07   ((uint32)0x00000040)

/**
 * \brief
 * 		Measure frame block id 08 for sending mask.
 */
#define CU8_BLOCK_ID_08                ((uint8)8)
/**
 * \brief
 * 		Block to send id mask 08.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_08   ((uint32)0x00000080)

/**
 * \brief
 * 		Measure frame block id 09 for sending mask.
 */
#define CU8_BLOCK_ID_09                ((uint8)9)
/**
 * \brief
 * 		Block to send id mask 09.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_09   ((uint32)0x00000100)

/**
 * \brief
 * 		Measure frame block id 10 for sending mask.
 */
#define CU8_BLOCK_ID_10                ((uint8)10)
/**
 * \brief
 * 		Block to send id mask 10.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_10   ((uint32)0x00000200)

/**
 * \brief
 * 		Measure frame block id 11 for sending mask.
 */
#define CU8_BLOCK_ID_11                ((uint8)11)
/**
 * \brief
 * 		Block to send id mask 11.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_11   ((uint32)0x00000400)

/**
 * \brief
 * 		Measure frame block id 12 for sending mask.
 */
#define CU8_BLOCK_ID_12                ((uint8)12)
/**
 * \brief
 * 		Block to send id mask 12.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_12   ((uint32)0x00000800)

/**
 * \brief
 * 		Measure frame block id 13 for sending mask.
 */
#define CU8_BLOCK_ID_13                ((uint8)13)
/**
 * \brief
 * 		Block to send id mask 13.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_13   ((uint32)0x00001000)

/**
 * \brief
 * 		Measure frame block id 14 for sending mask.
 */
#define CU8_BLOCK_ID_14                ((uint8)14)
/**
 * \brief
 * 		Block to send id mask 14.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_14   ((uint32)0x00002000)

/**
 * \brief
 * 		Measure frame block id 15 for sending mask.
 */
#define CU8_BLOCK_ID_15                ((uint8)15)
/**
 * \brief
 * 		Block to send id mask 15.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_15   ((uint32)0x00004000)

/**
 * \brief
 * 		Measure frame block id 16 for sending mask.
 */
#define CU8_BLOCK_ID_16                ((uint8)16)
/**
 * \brief
 * 		Block to send id mask 16.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_16   ((uint32)0x00008000)

/**
 * \brief
 * 		Measure frame block id 17 for sending mask.
 */
#define CU8_BLOCK_ID_17                ((uint8)17)
/**
 * \brief
 * 		Block to send id mask 17.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_17   ((uint32)0x00010000)

/**
 * \brief
 * 		Measure frame block id 18 for sending mask.
 */
#define CU8_BLOCK_ID_18                ((uint8)18)
/**
 * \brief
 * 		Block to send id mask 18.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_18   ((uint32)0x00020000)

/**
 * \brief
 * 		Measure frame block id 20 for sending mask.
 */
#define CU8_BLOCK_ID_20                ((uint8)20)
/**
 * \brief
 * 		Block to send id mask 20.
 */
#define U32_BLOCK_TO_SEND_ID_MASK_20   ((uint32)0x00080000)

/**
 * \brief
 * 		Value for cycle position in stepcycle.
 */
#define CIL_CYCLE_POSITION_IN_STEPCYCLE_0                 ((uint8)0x03)

/**
 * \brief
 * 		Number of transmitted blocks.
 */
#define KU8_CIL_MF_NB_OF_BLOCKS                         ((uint8) 20)

/**
 * \brief
 * 		Selected bloks to send for next frame transmission
 */
#define KU8_INDEX_0_IN_SELECTED_BLOCKS_ARRAY            ((uint8) 0)
/**
 * \brief
 * 		Selected bloks to send for next frame transmission
 */
#define KU8_INDEX_1_IN_SELECTED_BLOCKS_ARRAY            ((uint8) 1)
/**
 * \brief
 * 		Selected bloks to send for next frame transmission
 */
#define KU8_INDEX_2_IN_SELECTED_BLOCKS_ARRAY            ((uint8) 2)

/**
 * \brief
 * 		Right shift order applyed on the signed 16 bits PWM order
 * value, to divide it by 64 regarding the CAN signal scale.
 */
#define KU8_DIVIDE_BY_64_RIGHT_SHIFT  ((uint8)6)

/**
 * \brief
 * 		Voltage scaling define
 */
#define KU16_25500_MV            ((uint16) 0x639C)
/**
 * \brief
 * 		Voltage scaling define
 */
#define KU16_CONVERT_MV_TO_DV    ((uint16) 0x0064)
/**
 * \brief
 * 		Constant needed to validate the measurement block 12
 */
#define KU8_BLOCK12_MIN_SIZE                    ((uint8)      1)
/**
 * \brief
 * 		Constant needed to validate the measurement block 12
 */
#define KU8_BLOCK12_MAX_SIZE                    ((uint8)      7)

/**
 * \brief
 * 		Constant needed to validate the measurement block 12
 */
#define KU16_BLOCK12_RAM_LOW_BOUNDARY           ((uint16)0x1000)
/**
 * \brief
 * 		Constant needed to validate the measurement block 12
 */
#define KU16_BLOCK1RAM_HIGH_BOUNDARY          ((uint16)0x3FFF)

/*************************************************************************
**                        Addressing space macros                       **
**   (shall not be modified without considering application linkage)    **
**************************************************************************/
/**
 * \brief
 * 		Constant for NVFLEX RAM start address
 */
#define KU32_NVFLEX_RAM_START_ADDR        ((uint32) 0x70017500)
/**
 * \brief
 * 		Constant for NVFLEX RAM end address
 */
#define KU32_NVFLEX_RAM_END_ADDR          ((uint32) 0x70017F00)
/**
 * \brief
 * 		Constant for RAM start address
 */
#define KU32_RAM_START_ADDR               ((uint32) 0x70000000)
/**
 * \brief
 * 		Constant for RAM end address
 */
#define KU32_RAM_END_ADDR                 ((uint32) 0x70017500) 
 /**
  * \brief
  *		Macro which computes a bit mask from a measurement frame's block number.
  */
#define U32_BLOCK_MASK(u8BlockId)  ( (uint32)( ((uint32)(0x00000001uL))<<((uint8)((u8BlockId)-1u))))

 /**
  * \brief
  *		Macro which computes a bit mask to select the next measurement frame's block number
  */
#define NEXT_BLOCK(u32BlockMask) ((uint32)((u32BlockMask)<<1u))
/******************************************************************************
MODULE TYPES
******************************************************************************/
typedef void (*pfCILBlockFunction_Type)(void);
/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_START_SEC_CONST_UNSPECIFIED
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		Function pointer relative to MF blocks   
 * \remarks
 *		List of pointers to all Blocks encoding functions for MF
 */
LOCAL const pfCILBlockFunction_Type cil_capfCILBlocksEncodFunc[KU8_CIL_MF_NB_OF_BLOCKS] =
{
   &cil_Update_07Cx_Block01_InfosToSend,
   &cil_Update_07Cx_Block02_InfosToSend,
   &cil_Update_07Cx_Block03_InfosToSend,
   &cil_Update_07Cx_Block04_InfosToSend,
   &cil_Update_07Cx_Block05_InfosToSend,
   &cil_Update_07Cx_Block06_InfosToSend,
   &cil_Update_07Cx_Block07_InfosToSend,
   &cil_Update_07Cx_Block08_InfosToSend,
   &cil_Update_07Cx_Block09_InfosToSend,
   &cil_Update_07Cx_Block10_InfosToSend,
   &cil_Update_07Cx_Block11_InfosToSend,
   &cil_Update_07Cx_Block12_InfosToSend,
   &cil_Update_07Cx_Block13_InfosToSend,
   &cil_Update_07Cx_Block14_InfosToSend,
   &cil_Update_07Cx_Block15_InfosToSend,
   &cil_Update_07Cx_Block16_InfosToSend,
   &cil_Update_07Cx_Block17_InfosToSend,
   &cil_Update_07Cx_Block18_InfosToSend,
   &cil_Update_07Cx_IncorrectBlock_InfosToSend,
   &cil_Update_07Cx_Block20_InfosToSend,
   };
/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CONST_UNSPECIFIED
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_START_SEC_VAR_INIT_32
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		Mask value for next block   
 * \remarks
 *		None
 */
LOCAL uint32 cil_u32MeasureNextBlockToSendMask = U32_BLOCK_MASK(CU8_BLOCK_ID_20);
/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_VAR_INIT_32
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_START_SEC_VAR_INIT_8
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		Value for next block to send
 * \remarks
 *		None
 */
LOCAL uint8 cil_u8MeasureNextBlockToSend = CU8_BLOCK_ID_20;
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		Value for periodicity for MF
 * \remarks
 *		None
 */

LOCAL uint8 cil_u8MFPeriodCounter = KU8_ZERO;
/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_VAR_INIT_8
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_START_SEC_VAR_UNSPECIFIED
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		Variable for MF content
 * \remarks
 *		None
 */
LOCAL REC_Meas_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv cil_stMeasurementFrameContent = {KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO};
/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_VAR_UNSPECIFIED
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_START_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/**
* \brief
*     This function fill the CAN buffer for measurement frame sent
        0x18E1A490 and 0x18E1A590 identifiers), when the block number to send is 01.
* \param
*     none
* \exception
*     none
* \pre
*     none
* \post
*     none
* \return
*     void
**/
/* [COVERS: DSG_CIL_0079] */
LOCAL void cil_Update_07Cx_Block01_InfosToSend(void)
{
   /* Received data before multiplexing */
   uint8 u8CurrentCycle;
   uint8 u8CurrentStep;
   uint16 u16MotorCurrentTensRaw;
   uint16 u16MotorCurrentRelRaw;

   /* Adaptation of separated variables */
   uint8 u8MotorCurrentTensRawMSB;
   uint8 u8MotorCurrentTensRawLSB;
   uint8 u8MotorCurrentRelRawMSB;
   uint8 u8MotorCurrentRelRawLSB;

   /******************************************/
   /* Read infos from application components */
   /******************************************/
   Rte_Read_prrCycleNumber_u8CycleNumber(&u8CurrentCycle);

   /* [COVERS: DSG_CIL_0119] */
   Rte_Read_prrStepNumber_u8StepNumber(&u8CurrentStep);

   Rte_Call_pclMotor_Ip_raw_raw_Get(&u16MotorCurrentTensRaw);
   /* ADC signals are coded on 12 bits, expected right-handed */
   u8MotorCurrentTensRawMSB = (uint8)U16_GET_HIGH_BYTE(u16MotorCurrentTensRaw);
   u8MotorCurrentTensRawLSB = (uint8)U16_GET_LOW_BYTE(u16MotorCurrentTensRaw);

   Rte_Call_pclMotor_In_raw_raw_Get(&u16MotorCurrentRelRaw);
   /* ADC signals are coded on 12 bits, expected right-handed */
   u8MotorCurrentRelRawMSB = (uint8)U16_GET_HIGH_BYTE(u16MotorCurrentRelRaw);
   u8MotorCurrentRelRawLSB = (uint8)U16_GET_LOW_BYTE(u16MotorCurrentRelRaw);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID             */
   /* Byte1 : CurrentCycle         */
   /* Byte2 : CurrentStep          */
   /* Byte3 : KU8_MAX              */
   /* Byte4 : TensMotorCurrent MSB */
   /* Byte5 : TensMotorCurrent LSB */
   /* Byte6 : RelMotorCurrent  MSB */
   /* Byte7 : RelMotorCurrent  LSB */
   
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_01;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = u8CurrentCycle;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8CurrentStep;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = u8MotorCurrentTensRawMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = u8MotorCurrentTensRawLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = u8MotorCurrentRelRawMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = u8MotorCurrentRelRawLSB;
}


/**
* \brief
*     This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 02.
* \param
*     none
* \exception
*     none
* \pre
*     none
* \post
*     none
* \return
*     void
**/
/* [COVERS: DSG_CIL_0080] */
LOCAL void cil_Update_07Cx_Block02_InfosToSend(void)
{
   /* Received data before multiplexing */
   uint16 u16ScaledKL30Voltage;
   sint32 s32ScaledMotorCurrent;
   uint32 u32AbsScaledMotorCurrent;
   uint16 u16AbsScaledMotorCurrentSat;

   /* Adaptation of separated variables */
   uint8 u8ScaledKL30VoltageMSB;
   uint8 u8ScaledKL30VoltageLSB;
   uint8 u8ScaledMotorCurrentMSB;
   uint8 u8ScaledMotorCurrentLSB;

   /******************************************/
   /* Read infos from application components */
   /******************************************/
   /* [COVERS: DSG_CIL_0116, DSG_CIL_0112] */
   Rte_Call_pclKL30_V_Get(&u16ScaledKL30Voltage);
   u8ScaledKL30VoltageMSB = (uint8)U16_GET_HIGH_BYTE(u16ScaledKL30Voltage);
   u8ScaledKL30VoltageLSB = (uint8)U16_GET_LOW_BYTE(u16ScaledKL30Voltage);

   Rte_Call_pclMotor_I_Get_mA(&s32ScaledMotorCurrent);
   u32AbsScaledMotorCurrent = U32_GET_ABSOLUTE_VALUE_FROM_S32(s32ScaledMotorCurrent); /* QAC_WARNING S 3491 */ /* Macro with operator */
   u16AbsScaledMotorCurrentSat = U16_GET_SATURATED_VALUE_FROM_U32(u32AbsScaledMotorCurrent); /* QAC_WARNING S 3491 */ /* Macro with operator */
   u8ScaledMotorCurrentMSB = (uint8)U16_GET_HIGH_BYTE(u16AbsScaledMotorCurrentSat);
   u8ScaledMotorCurrentLSB = (uint8)U16_GET_LOW_BYTE(u16AbsScaledMotorCurrentSat);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID             */
   /* Byte1 : Scaled KL30 MSB      */
   /* Byte2 : Scaled KL30 LSB      */
   /* Byte3 : Scaled KL30BG MSB    */
   /* Byte4 : Scaled KL30BG LSB    */
   /* Byte5 : IMotor s16 MSB       */
   /* Byte6 : IMotor s16 LSB       */
   /* Byte7 : KU8_MAX              */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_02;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = u8ScaledKL30VoltageMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8ScaledKL30VoltageLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = u8ScaledMotorCurrentMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = u8ScaledMotorCurrentLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = KU8_MAX;
}


/**
* \brief
*     This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 03.
* \param
*     none
* \exception
*     none
* \pre
*     none
* \post
*     none
* \return
*     void
**/
/* [COVERS: DSG_CIL_0081] */
LOCAL void cil_Update_07Cx_Block03_InfosToSend(void)
{
   /* Received data before multiplexing */
   uint16 u16MotorPlus;
   uint16 u16MotorMinus;
   uint16 u16Temperature;

   /* Adaptation of separated variables */
   uint8 u8MotorPlusMSB;
   uint8 u8MotorPlusLSB;
   uint8 u8MotorMinusMSB;
   uint8 u8MotorMinusLSB;
   uint8 u8TemperatureMSB;
   uint8 u8TemperatureLSB;

   /******************************************/
   /* Read infos from application components */
   /******************************************/
   /* [COVERS: DSG_CIL_0098] */
   Rte_Call_pclMotor_Vp_Get(&u16MotorPlus);
   u8MotorPlusMSB = (uint8)U16_GET_HIGH_BYTE(u16MotorPlus);
   u8MotorPlusLSB = (uint8)U16_GET_LOW_BYTE(u16MotorPlus);

   /* [COVERS: DSG_CIL_0099] */
   Rte_Call_pclMotor_Vn_Get(&u16MotorMinus);
   u8MotorMinusMSB = (uint8)U16_GET_HIGH_BYTE(u16MotorMinus);
   u8MotorMinusLSB = (uint8)U16_GET_LOW_BYTE(u16MotorMinus);

   Rte_Call_pclECU_T_GetFiltered(&u16Temperature);
   u8TemperatureMSB = (uint8)U16_GET_HIGH_BYTE(u16Temperature);
   u8TemperatureLSB = (uint8)U16_GET_LOW_BYTE(u16Temperature);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID                 */
   /* Byte1 : PreCrashSevLevel         */
   /* Byte2 : Vplus_filtered MSB       */
   /* Byte3 : Vplus_filtered LSB       */
   /* Byte4 : Vminus_filtered MSB      */
   /* Byte5 : Vminus_filtered LSB      */
   /* Byte6 : Temperature_filtered MSB */
   /* Byte7 : Temperature_filtered LSB */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_03;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = KU8_MAX;//CIL_u8ActivationRequest
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8MotorPlusMSB;//ASM_U8_MOTOR_PLUS_VOLTAGE_FILTERED_10MS_MV(MSB)
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = u8MotorPlusLSB;//ASM_U8_MOTOR_PLUS_VOLTAGE_FILTERED_10MS_MV(LSB)
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = u8MotorMinusMSB;//ASM_U8_MOTOR_MINUS_VOLTAGE_FILTERED_10MS_MV(MSB)
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = u8MotorMinusLSB;//ASM_U8_MOTOR_MINUS_VOLTAGE_FILTERED_10MS_MV(LSB)
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = u8TemperatureMSB;//SBC_Temperature_filtered(MSB)
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = u8TemperatureLSB;//SBC_Temperature_filtered(LSB)
}


/**
* \brief
*     This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 04.
* \param
*     none
* \exception
*     none
* \pre
*     none
* \post
*     none
* \return
*     void
**/
/* [COVERS: DSG_CIL_0082] */
LOCAL void cil_Update_07Cx_Block04_InfosToSend(void)
{
   /******************************************/
   /* Read infos from application components */
   /******************************************/

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID                      */
   /* Byte1 : KU8_MAX                       */
   /* Byte2 : KU8_MAX                       */
   /* Byte3 : KU8_MAX                       */
   /* Byte4 : KU8_MAX                       */
   /* Byte5 : KU8_MAX                       */
   /* Byte6 : KU8_MAX                       */
   /* Byte7 : KU8_MAX                       */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_04;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = KU8_MAX;
}


/**
* \brief
*     This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 05.
* \param
*     none
* \exception
*     none
* \pre
*     none
* \post
*     none
* \return
*     void
**/
/* [COVERS: DSG_CIL_0083] */
LOCAL void cil_Update_07Cx_Block05_InfosToSend(void)
{
   /* Received data before multiplexing */
   uint32 u32AbsScaledMotorCurrent;
   sint32 s32ScaledMotorCurrent;
   uint16 u16AbsScaledMotorCurrentSat;
   sint16 s16PWMDutyCycle;
   sint16 s16BobbinPosition;
   uint16 u16MotorPlus;
   uint16 u16MotorMinus;

   /* Adaptation of separated variables */
   uint8 u8PWMDutyCycle;
   uint8 u8ScaledMotorCurrentMSB;
   uint8 u8ScaledMotorCurrentLSB;
   uint8 u8BobbinPositionMSB;
   uint8 u8BobbinPositionLSB;
   uint8 u8MotorPlus;
   uint8 u8MotorMinus;


   /******************************************/
   /* Read infos from application components */
   /******************************************/
   Rte_Call_pclMotor_P_GetPowerOrder(&s16PWMDutyCycle);
   /* value recovered is within range [-6400;6400] */
   /* -> Divise by 64 to get range [-100;100]  */
   if (s16PWMDutyCycle<0)
   {
      /* QAC_WARNING S 4394 1 */ /* A composite expression of 'essentially unsigned' type (unsigned short) is being cast to a different type category, 'signed'. */
      s16PWMDutyCycle = -((sint16)(((uint16)(-s16PWMDutyCycle))>>KU8_DIVIDE_BY_64_RIGHT_SHIFT ));
   }
   else
   {
      /* QAC_WARNING S 4394 1 */ /* A composite expression of 'essentially unsigned' type (unsigned short) is being cast to a different type category, 'signed'. */
      s16PWMDutyCycle = (sint16)(((uint16)s16PWMDutyCycle)>>KU8_DIVIDE_BY_64_RIGHT_SHIFT);
   }
   /* Ensure there is no overflow before casting to 8bit format */
   if (s16PWMDutyCycle > KS16_MAX_S8)
   {
      s16PWMDutyCycle = KS16_MAX_S8;
   }
   else if (s16PWMDutyCycle < KS16_MIN_S8)
   {
      s16PWMDutyCycle = KS16_MIN_S8;
   }
   else
   {
      /* Do nothing: s16PWMOrder shall be unchanged. */
   }
   u8PWMDutyCycle = (uint8) s16PWMDutyCycle;

   Rte_Call_pclMotor_I_Get_mA(&s32ScaledMotorCurrent);
   u32AbsScaledMotorCurrent = U32_GET_ABSOLUTE_VALUE_FROM_S32(s32ScaledMotorCurrent); /* QAC_WARNING S 3491 */ /* Macro with operator */
   /* Clamp to 65535 to be sent on 2 bytes only */
   u16AbsScaledMotorCurrentSat = U16_GET_SATURATED_VALUE_FROM_U32(u32AbsScaledMotorCurrent); /* QAC_WARNING S 3491 */ /* Macro with operator */
   u8ScaledMotorCurrentMSB = (uint8)U16_GET_HIGH_BYTE(u16AbsScaledMotorCurrentSat);
   u8ScaledMotorCurrentLSB = (uint8)U16_GET_LOW_BYTE(u16AbsScaledMotorCurrentSat);

   /* [COVERS: DSG_CIL_0113] */
   Rte_Call_pclMotor_Vp_Get(&u16MotorPlus);
   /* Vp shall be clamped at 25.5V */
   if (u16MotorPlus > KU16_25500_MV)
   {
      u16MotorPlus = KU16_25500_MV;
   }
   else
   {
      /* Do nothing: u16MotorPlus shall be unchanged. */
   }

   /* Convert mV in dV */
   u8MotorPlus = (uint8)(u16MotorPlus / KU16_CONVERT_MV_TO_DV);

   /* [COVERS: DSG_CIL_0114] */
   Rte_Call_pclMotor_Vn_Get(&u16MotorMinus);
   /* Vp shall be clamped at 25.5V */
   if (u16MotorMinus > KU16_25500_MV)
   {
      u16MotorMinus = KU16_25500_MV;
   }
   else
   {
      /* Do nothing: u16MotorMinus shall be unchanged. */
   }

   /* Convert mV in dV */
   u8MotorMinus = (uint8)(u16MotorMinus / KU16_CONVERT_MV_TO_DV);

   // Rte_Call_pclBelt_D_GetFromT0_deg(&s16BobbinPosition);
   u8BobbinPositionMSB = (uint8)U16_GET_HIGH_BYTE((uint16)s16BobbinPosition);
   u8BobbinPositionLSB = (uint8)U16_GET_LOW_BYTE((uint16)s16BobbinPosition);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID                      */
   /* Byte1 : MotorPowerOrder LSB           */
   /* Byte2 : Abs(IMotor) LSB H             */
   /* Byte3 : Abs(IMotor) LSB L             */
   /* Byte4 : MotorPlusTerminalVoltage LSB  */
   /* Byte5 : MotorMinusTerminalVoltage LSB */
   /* Byte6 : BobinePosition_deg MSB        */
   /* Byte7 : BobinePosition_deg LSB        */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_05;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = u8PWMDutyCycle;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8ScaledMotorCurrentMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = u8ScaledMotorCurrentLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = u8MotorPlus;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = u8MotorMinus;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = u8BobbinPositionMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = u8BobbinPositionLSB;
}


/**
* \brief
*     This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 06.
* \param
*     none
* \exception
*     none
* \pre
*     none
* \post
*     none
* \return
*     void
**/
/* [COVERS: DSG_CIL_0084] */
LOCAL void cil_Update_07Cx_Block06_InfosToSend(void)
{
   /* Received data before multiplexing */
   sint32 s32BobbinSpeed;
   uint8 u8HESTestResult;
   sint16 s16BobbinPosition;

   /* Adaptation of separated variables */
   uint8 u8BobbinSpeedHMSB;
   uint8 u8BobbinSpeedLMSB;
   uint8 u8BobbinSpeedHLSB;
   uint8 u8BobbinSpeedLLSB;
   uint8 u8BobbinPositionMSB;
   uint8 u8BobbinPositionLSB;

   /******************************************/
   /* Read infos from application components */
   /******************************************/
   Rte_Call_pclBelt_S_GetSpeed_deg_s(&s32BobbinSpeed);
   u8BobbinSpeedHMSB = U32_GET_HIGH_BYTE((uint32)s32BobbinSpeed);
   u8BobbinSpeedLMSB = U32_GET_HIGH_MIDDLE_BYTE((uint32)s32BobbinSpeed);
   u8BobbinSpeedHLSB = U32_GET_LOW_MIDDLE_BYTE((uint32)s32BobbinSpeed);
   u8BobbinSpeedLLSB = U32_GET_LOW_BYTE((uint32)s32BobbinSpeed);

   /* [COVERS: DSG_CIL_0104] */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_HALL_EFFECT_SENSORS,&u8HESTestResult);

   if (KU8_ATM_TEST_OK == u8HESTestResult)
   {
      /* Test succeeded */
      u8HESTestResult = KU8_TRUE;
   }
   else if (KU8_ATM_TEST_NOK == u8HESTestResult)
   {
      /* Test failed */
      u8HESTestResult = KU8_FALSE;
   }
   else
   {
      /* Test not performed yet */
      u8HESTestResult = KU8_MAX;
   }

   Rte_Call_pclBelt_D_GetFromT0_deg(&s16BobbinPosition);
   u8BobbinPositionMSB = (uint8)U16_GET_HIGH_BYTE((uint16)s16BobbinPosition);
   u8BobbinPositionLSB = (uint8)U16_GET_LOW_BYTE((uint16)s16BobbinPosition);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID               */
   /* Byte1 : BeltSpeedmm MSB_H      */
   /* Byte2 : BeltSpeedmm MSB_L      */
   /* Byte3 : BeltSpeedmm LSB_H      */
   /* Byte4 : BeltSpeedmm LSB_L      */
   /* Byte5 : RotationTestStatus     */
   /* Byte6 : BobbinPosition_deg MSB */
   /* Byte7 : BobbinPosition_deg LSB */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_06;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = u8BobbinSpeedHMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8BobbinSpeedLMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = u8BobbinSpeedHLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = u8BobbinSpeedLLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = u8HESTestResult;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = u8BobbinPositionMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = u8BobbinPositionLSB;
}


/**
* \brief
*     This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 07.
* \param
*     none
* \exception
*     none
* \pre
*     none
* \post
*     none
* \return
*     void
**/
/* [COVERS: DSG_CIL_0085] */
LOCAL void cil_Update_07Cx_Block07_InfosToSend(void)
{
   /* Received data before multiplexing */
   s16InternalTemperature_deg_Type s16Temperature_Deg;
   uint16 u16HBSAVoltageRaw;
   uint16 u16HBSBVoltageRaw;

   /* Adaptation of separated variables */
   uint8 u8TemperatureMSB;
   uint8 u8TemperatureLSB;
   uint8 u8HBSAVoltageRawMSB;
   uint8 u8HBSAVoltageRawLSB;
   uint8 u8HBSBVoltageRawMSB;
   uint8 u8HBSBVoltageRawLSB;

   /******************************************/
   /* Read infos from application components */
   /******************************************/
   /* [COVERS: DSG_CIL_0115] */
   Rte_Call_pclECU_T_GetFiltered_deg(&s16Temperature_Deg);
   u8TemperatureMSB = (uint8)U16_GET_HIGH_BYTE((uint16)s16Temperature_Deg);
   u8TemperatureLSB = (uint8)U16_GET_LOW_BYTE((uint16)s16Temperature_Deg);

   Rte_Call_pclHBS_A_V_raw_Get(&u16HBSAVoltageRaw);
   /* ADC signals are coded on 10 bits, expected right-handed */
   u8HBSAVoltageRawMSB = (uint8)U16_GET_HIGH_BYTE(u16HBSAVoltageRaw);
   u8HBSAVoltageRawLSB = (uint8)U16_GET_LOW_BYTE(u16HBSAVoltageRaw);

   Rte_Call_pclHBS_B_V_raw_Get(&u16HBSBVoltageRaw);
   /* ADC signals are coded on 10 bits, expected right-handed */
   u8HBSBVoltageRawMSB = (uint8)U16_GET_HIGH_BYTE(u16HBSBVoltageRaw);
   u8HBSBVoltageRawLSB = (uint8)U16_GET_LOW_BYTE(u16HBSBVoltageRaw);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID                       */
   /* Byte1 : Temperature_filtered_100ms MSB */
   /* Byte2 : Temperature_filtered_100ms LSB */
   /* Byte3 : HES_A_LEVEL MSB                */
   /* Byte4 : HES_A_LEVEL LSB                */
   /* Byte5 : HES_B_LEVEL MSB                */
   /* Byte6 : HES_B_LEVEL LSB                */
   /* Byte7 : KU8_MAX                        */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_07;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = u8TemperatureMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8TemperatureLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = u8HBSAVoltageRawMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = u8HBSAVoltageRawLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = u8HBSBVoltageRawMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = u8HBSBVoltageRawLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = KU8_MAX;
}


/**
* \brief
*     This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 08.
* \param
*     none
* \exception
*     none
* \pre
*     none
* \post
*     none
* \return
*     void
**/
/* [COVERS: DSG_CIL_0086] */
LOCAL void cil_Update_07Cx_Block08_InfosToSend(void)
{
   /* Received data before multiplexing */
   uint8 u8BeltProfile;
   uint8 u8CurrentCycle;
   uint8 u8CurrentStep;
   sint16 s16PWMDutyCycle;
   uint8 u8PWMDutyCycle;

   /******************************************/
   /* Read infos from application components */
   /******************************************/
   /* [COVERS: DSG_CIL_0111] */
   Rte_Call_pclMotor_P_GetPowerOrder(&s16PWMDutyCycle);
   /* value recovered is within range [-6400;6400] */
   /* -> Divise by 64 to get range [-100;100]  */
   if (s16PWMDutyCycle<0)
   {
      /* QAC_WARNING S 4394 1 */ /* A composite expression of 'essentially unsigned' type (unsigned short) is being cast to a different type category, 'signed'. */
      s16PWMDutyCycle = -((sint16)(((uint16)(-s16PWMDutyCycle))>>KU8_DIVIDE_BY_64_RIGHT_SHIFT ));
   }
   else
   {
      /* QAC_WARNING S 4394 1 */ /* A composite expression of 'essentially unsigned' type (unsigned short) is being cast to a different type category, 'signed'. */
      s16PWMDutyCycle = (sint16)(((uint16)s16PWMDutyCycle)>>KU8_DIVIDE_BY_64_RIGHT_SHIFT);
   }
   /* Ensure there is no overflow before casting to 8bit format */
   if (s16PWMDutyCycle > KS16_MAX_S8)
   {
      s16PWMDutyCycle = KS16_MAX_S8;
   }
   else if (s16PWMDutyCycle < KS16_MIN_S8)
   {
      s16PWMDutyCycle = KS16_MIN_S8;
   }
   else
   {
      /* Do nothing: s16PWMOrder shall be unchanged. */
   }
   u8PWMDutyCycle = (uint8) s16PWMDutyCycle;

   Rte_Read_prrSelectedCycle_u8CycleNumber(&u8BeltProfile);

   Rte_Read_prrCycleNumber_u8CycleNumber(&u8CurrentCycle);

   Rte_Read_prrStepNumber_u8StepNumber(&u8CurrentStep);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID                       */
   /* Byte1 : KU8_MAX                        */
   /* Byte2 : KU8_MAX                        */
   /* Byte3 : SelectedBeltProfile            */
   /* Byte4 : Current cycle                  */
   /* Byte5 : Current step                   */
   /* Byte6 : PWM duty cycle                 */
   /* Byte7 : KU8_MAX                        */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_08;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = u8BeltProfile;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = u8CurrentCycle;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = u8CurrentStep;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = u8PWMDutyCycle;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = KU8_MAX;
}


/**
* \brief
*     This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 09.
* \param
*     none
* \exception
*     none
* \pre
*     none
* \post
*     none
* \return
*     void
**/
/* [COVERS: DSG_CIL_0087] */
LOCAL void cil_Update_07Cx_Block09_InfosToSend(void)
{
   /* Received data before multiplexing */
   uint16 u16MotorCurrentTensRaw;
   uint16 u16MotorCurrentRelRaw;
   uint16 u16KL30_V_raw;

   /* Adaptation of separated variables */
   uint8 u8MotorCurrentTensRawMSB;
   uint8 u8MotorCurrentTensRawLSB;
   uint8 u8MotorCurrentRelRawMSB;
   uint8 u8MotorCurrentRelRawLSB;
   uint8 u8KL30_V_rawMSB;
   uint8 u8KL30_V_rawLSB;

   Rte_Call_pclMotor_Ip_raw_raw_Get(&u16MotorCurrentTensRaw);
   /* ADC signals are coded on 10 bits, expected right-handed */
   u8MotorCurrentTensRawMSB = (uint8)U16_GET_HIGH_BYTE(u16MotorCurrentTensRaw);
   u8MotorCurrentTensRawLSB = (uint8)U16_GET_LOW_BYTE(u16MotorCurrentTensRaw);

   Rte_Call_pclMotor_In_raw_raw_Get(&u16MotorCurrentRelRaw);
   /* ADC signals are coded on 10 bits, expected right-handed */
   u8MotorCurrentRelRawMSB = (uint8)U16_GET_HIGH_BYTE(u16MotorCurrentRelRaw);
   u8MotorCurrentRelRawLSB = (uint8)U16_GET_LOW_BYTE(u16MotorCurrentRelRaw);

   /* [COVERS: DSG_CIL_0100] */
   Rte_Call_pclKL30_V_raw_Get(&u16KL30_V_raw);
   /* ADC signals are coded on 10 bits, expected right-handed */
   u8KL30_V_rawMSB = (uint8)U16_GET_HIGH_BYTE(u16KL30_V_raw);
   u8KL30_V_rawLSB = (uint8)U16_GET_LOW_BYTE(u16KL30_V_raw);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID                */
   /* Byte1 : KU8_MAX                 */
   /* Byte2 : IMotorRelRaw MSB        */
   /* Byte3 : IMotorRelRaw LSB        */
   /* Byte4 : IMotorTensRaw MSB       */
   /* Byte5 : IMotorTensRaw LSB       */
   /* Byte6 : VbattPower_filtered MSB */
   /* Byte7 : VbattPower_filtered LSB */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_09;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8MotorCurrentRelRawMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = u8MotorCurrentRelRawLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = u8MotorCurrentTensRawMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = u8MotorCurrentTensRawLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = u8KL30_V_rawMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = u8KL30_V_rawLSB;
}


/**
* \brief
*     This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 10.
* \param
*     none
* \exception
*     none
* \pre
*     none
* \post
*     none
* \return
*     void
**/
/* [COVERS: DSG_CIL_0088] */
LOCAL void cil_Update_07Cx_Block10_InfosToSend(void)
{
   /* Received data before multiplexing */
   uint16 u16HBSAVoltageRaw;
   uint16 u16HBSBVoltageRaw;
   uint16 u16HS1_V_raw;

   /* Adaptation of separated variables */
   uint8 u8HBSAVoltageRawMSB;
   uint8 u8HBSAVoltageRawLSB;
   uint8 u8HBSBVoltageRawMSB;
   uint8 u8HBSBVoltageRawLSB;
   uint8 u8HS1_V_rawMSB;
   uint8 u8HS1_V_rawLSB;

   /* [COVERS: DSG_CIL_0101] */
   Rte_Call_pclHBS_A_V_raw_Get(&u16HBSAVoltageRaw);
   /* ADC signals are coded on 10 bits, expected right-handed */
   u8HBSAVoltageRawMSB = (uint8)U16_GET_HIGH_BYTE(u16HBSAVoltageRaw);
   u8HBSAVoltageRawLSB = (uint8)U16_GET_LOW_BYTE(u16HBSAVoltageRaw);

   /* [COVERS: DSG_CIL_0102] */
   Rte_Call_pclHBS_B_V_raw_Get(&u16HBSBVoltageRaw);
   /* ADC signals are coded on 10 bits, expected right-handed */
   u8HBSBVoltageRawMSB = (uint8)U16_GET_HIGH_BYTE(u16HBSBVoltageRaw);
   u8HBSBVoltageRawLSB = (uint8)U16_GET_LOW_BYTE(u16HBSBVoltageRaw);

   /* [COVERS: DSG_CIL_0103] */
   Rte_Call_pclHS1_V_raw_Get(&u16HS1_V_raw);
   /* ADC signals are coded on 10 bits, expected right-handed */
   u8HS1_V_rawMSB = (uint8)U16_GET_HIGH_BYTE(u16HS1_V_raw);
   u8HS1_V_rawLSB = (uint8)U16_GET_LOW_BYTE(u16HS1_V_raw);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID                     */
   /* Byte1 : KU8_MAX                      */
   /* Byte2 : HES_A_LEVEL_INTERMEDIATE MSB */
   /* Byte3 : HES_A_LEVEL_INTERMEDIATE LSB */
   /* Byte4 : HES_B_LEVEL_INTERMEDIATE MSB */
   /* Byte5 : HES_B_LEVEL_INTERMEDIATE LSB */
   /* Byte6 : HighSide Switch Voltage MSB  */
   /* Byte7 : HighSide Switch Voltage LSB  */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_10;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8HBSAVoltageRawMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = u8HBSAVoltageRawLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = u8HBSBVoltageRawMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = u8HBSBVoltageRawLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = u8HS1_V_rawMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = u8HS1_V_rawLSB;
}


/**
* \brief
*     This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 11.
* \param
*     none
* \exception
*     none
* \pre
*     none
* \post
*     none
* \return
*     void
**/
/* [COVERS: DSG_CIL_0089] */
LOCAL void cil_Update_07Cx_Block11_InfosToSend(void)
{
   /* Received data before multiplexing */
   uint16 u16MotorCurrentTensRaw;
   uint16 u16MotorCurrentRelRaw;
   uint8 u8CurrentStep;
   sint32 s32ScaledMotorCurrent;

   /* Adaptation of separated variables */
   uint8 u8MotorCurrentTensRawMSB;
   uint8 u8MotorCurrentTensRawLSB;
   uint8 u8MotorCurrentRelRawMSB;
   uint8 u8MotorCurrentRelRawLSB;
   uint8 u8ScaledMotorCurrentMSB;
   uint8 u8ScaledMotorCurrentLSB;

   /******************************************/
   /* Read infos from application components */
   /******************************************/
   Rte_Call_pclMotor_In_raw_raw_Get(&u16MotorCurrentRelRaw);
   /* ADC signals are coded on 10 bits, expected right-handed */
   u8MotorCurrentRelRawMSB = (uint8)U16_GET_HIGH_BYTE(u16MotorCurrentRelRaw);
   u8MotorCurrentRelRawLSB = (uint8)U16_GET_LOW_BYTE(u16MotorCurrentRelRaw);

   Rte_Call_pclMotor_Ip_raw_raw_Get(&u16MotorCurrentTensRaw);
   /* ADC signals are coded on 10 bits, expected right-handed */
   u8MotorCurrentTensRawMSB = (uint8)U16_GET_HIGH_BYTE(u16MotorCurrentTensRaw);
   u8MotorCurrentTensRawLSB = (uint8)U16_GET_LOW_BYTE(u16MotorCurrentTensRaw);

   Rte_Read_prrStepNumber_u8StepNumber(&u8CurrentStep);

   /* [COVERS: DSG_CIL_0110] */
   Rte_Call_pclMotor_I_Get_mA(&s32ScaledMotorCurrent);
   u8ScaledMotorCurrentMSB = (uint8)U32_GET_LOW_MIDDLE_BYTE( ((uint32)s32ScaledMotorCurrent) );
   u8ScaledMotorCurrentLSB = (uint8)U32_GET_LOW_BYTE( ((uint32)s32ScaledMotorCurrent) );

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID          */
   /* Byte1 : IMotorRelRaw MSB  */
   /* Byte2 : IMotorRelRaw LSB  */
   /* Byte3 : IMotorTensRaw MSB */
   /* Byte4 : IMotorTensRaw LSB */
   /* Byte5 : u8CurrentStep     */
   /* Byte6 : PALIMotor MSB     */
   /* Byte7 : PALIMotor LSB     */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_11;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = u8MotorCurrentRelRawMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8MotorCurrentRelRawLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = u8MotorCurrentTensRawMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = u8MotorCurrentTensRawLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = u8CurrentStep;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = u8ScaledMotorCurrentMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = u8ScaledMotorCurrentLSB;
}


/**
* \brief
*     This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 12.
* \param
*     none
* \exception
*     none
* \pre
*     none
* \post
*     none
* \return
*     void
**/
/* [COVERS: DSG_CIL_0090] */
LOCAL void cil_Update_07Cx_Block12_InfosToSend(void)
{
   /* FOR loop index */
   uint32 u32StartAddress;

   /* EEPROM snapshot data in case of interruption by a diagnostic request */
   uint32 u32RamAddress;

   /* Received data before multiplexing */
   uint8 au8Byte[KU8_BLOCK12_MAX_SIZE];
   uint8  u8Size;
   uint8  u8Index;

   /* Capture EEPROM shadow data content */
   /* Endianess is wrong when we reach this point, so we fix it */
   ((uint8 *)&u32StartAddress)[3] = NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData.NVP_u32MeasFrame12RAMAddress;
   ((uint8 *)&u32StartAddress)[2] = NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData.NVP_u32MeasFrame12RAMAddress >> 8;
   ((uint8 *)&u32StartAddress)[1] = NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData.NVP_u32MeasFrame12RAMAddress >> 16;
   ((uint8 *)&u32StartAddress)[0] = NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData.NVP_u32MeasFrame12RAMAddress >> 24;
   u8Size = NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData.NVP_u8BlockSize;

   /* Initialize CAN message content with dummy values */
   for (u8Index = 0u ; u8Index < KU8_BLOCK12_MAX_SIZE ; u8Index++)
   {
      au8Byte[u8Index] = KU8_MAX;
   }

   /* Check EEPROM parameters validity and consistency */
   if ( (KU8_BLOCK12_MIN_SIZE <= u8Size)                       &&
        (KU8_BLOCK12_MAX_SIZE >= u8Size)                       &&
        (((KU32_NVFLEX_RAM_START_ADDR <= u32StartAddress)      &&
        (KU32_NVFLEX_RAM_END_ADDR >= (u32StartAddress + u8Size))) ||
        ((KU32_RAM_START_ADDR <= u32StartAddress)      &&
        (KU32_RAM_END_ADDR >= (u32StartAddress + u8Size))))
   )
   {
      /* Fill data with RAM content according to EEPROM parameters */
      for ( u32RamAddress=u32StartAddress ; u32RamAddress < (u32StartAddress+u8Size) ; u32RamAddress ++ )
      {
         /* QAC_WARNING S 0306 3 */ /* Cast between a pointer to object and an integral type. */
         au8Byte[u32RamAddress-u32StartAddress] = *((uint8 *)u32RamAddress);
      }
   }
   else
   {
      /* Parameters stored in EEP are invalid
       * In this case : nothing to do
       * the CAN MFT content has already been filled with dummy values
       * */
   }
   /************************/
   /* CAN frame formatting */
   /************************/
   /* Provide data to RTE for CAN driver processing */
   /* Byte0 : Block_ID */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_12;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = au8Byte[KU8_ZERO];
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = au8Byte[KU8_ONE];
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = au8Byte[KU8_TWO];
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = au8Byte[KU8_THREE];
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = au8Byte[KU8_FOUR];
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = au8Byte[KU8_FIVE];
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = au8Byte[KU8_SIX];
}


/**
 * \brief
 *		 This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 13.
 * \param
 * 		void
 * \return
 * 		void
 */
/* [COVERS: DSG_CIL_0091] */
LOCAL void cil_Update_07Cx_Block13_InfosToSend(void)
{
   /* Received data before multiplexing */
   uint8 u8CurrentStep;
   uint8 u8CurrentCycle;
   uint8 u8CycleStep;
   sint8 s8MotorCurrentInA;
   uint8 u8absMotorCurrentInA;
   const sint32 s32BeltSpeedInmm = KS32_ZERO;
   sint16 s16BeltPayoutInmm;

   /* Adaptation of separated variables */
   uint8 u8BeltSpeedInmmMSB;
   uint8 u8BeltSpeedInmmLSB;
   uint8 u8BeltPayoutInmmMSB;
   uint8 u8BeltPayoutInmmLSB;

   /******************************************/
   /* Read infos from application components */
   /******************************************/
   Rte_Read_prrStepNumber_u8StepNumber(&u8CurrentStep);
   Rte_Read_prrCycleNumber_u8CycleNumber(&u8CurrentCycle);
   if (KU8_NO_CYCLE==u8CurrentCycle)
   {
      /* Set 0 to step value if no cycle running */
      u8CurrentStep = KU8_ZERO;
   }
   else
   {
      /* Nothing to do */
   }
   u8CycleStep = ((uint8)( (uint16)u8CurrentCycle <<CIL_CYCLE_POSITION_IN_STEPCYCLE_0))|u8CurrentStep;

   /* [COVERS: DSG_CIL_0109] */
   Rte_Call_pclMotor_I_Get_A(&s8MotorCurrentInA);
   u8absMotorCurrentInA = U8_GET_ABSOLUTE_VALUE_FROM_S8(s8MotorCurrentInA); /* QAC_WARNING S 3491 */ /* Macro with operator */

   /* [COVERS: DSG_CIL_0107] */
   // Rte_Call_pclBelt_S_GetSpeed_mm_s(&s32BeltSpeedInmm);
   u8BeltSpeedInmmMSB = U32_GET_LOW_MIDDLE_BYTE((uint32)s32BeltSpeedInmm);
   u8BeltSpeedInmmLSB = U32_GET_LOW_BYTE((uint32)s32BeltSpeedInmm);

   /* [COVERS: DSG_CIL_0106] */
   Rte_Call_pclBelt_D_GetFromMinPos_mm(&s16BeltPayoutInmm);
   u8BeltPayoutInmmMSB = U16_GET_HIGH_BYTE((uint16)s16BeltPayoutInmm);
   u8BeltPayoutInmmLSB = U16_GET_LOW_BYTE((uint16)s16BeltPayoutInmm);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID          */
   /* Byte1 : (u8CurrentCycle<<3) | u8CurrentStep  */
   /* Byte2 : abs(IMotor_u8) in A                  */
   /* Byte3 : BeltSpeed_mm_s_s16 MSB               */
   /* Byte4 : BeltSpeed_mm_s_s16 LSB               */
   /* Byte5 : abs Payout_mm_filtered MSB           */
   /* Byte6 : abs Payout_mm_filtered LSB           */
   /* Byte7 : KU8_MAX                              */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_13;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = u8CycleStep;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8absMotorCurrentInA;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = u8BeltSpeedInmmMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = u8BeltSpeedInmmLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = u8BeltPayoutInmmMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = u8BeltPayoutInmmLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = KU8_MAX;
}


/**
 * \brief
 *		 This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 14.
 * \param
 * 		void
 * \return
 * 		void
 */
/* [COVERS: DSG_CIL_0092] */
LOCAL void cil_Update_07Cx_Block14_InfosToSend(void)
{
   /* Received data before multiplexing */
   uint8 u8CurrentStep;
   uint8 u8CurrentCycle;
   uint8 u8CycleStep;
   sint16 s16OriginPosition;
   sint16 s16MaxPosition;
   sint16 s16BeltPayoutInmm;

   /* Adaptation of separated variables */
   uint8 u8OriginPositionInmmMSB;
   uint8 u8OriginPositionInmmLSB;
   uint8 u8BeltPayoutInmmMSB;
   uint8 u8BeltPayoutInmmLSB;

   /******************************************/
   /* Read infos from application components */
   /******************************************/
   Rte_Read_prrStepNumber_u8StepNumber(&u8CurrentStep);
   Rte_Read_prrCycleNumber_u8CycleNumber(&u8CurrentCycle);
   if (KU8_NO_CYCLE==u8CurrentCycle)
   {
      /* Set 0 to step value if no cycle running */
      u8CurrentStep = KU8_ZERO;
   }
   else
   {
      /* Nothing to do */
   }
   u8CycleStep = ((uint8)( (uint16)u8CurrentCycle<<CIL_CYCLE_POSITION_IN_STEPCYCLE_0))|u8CurrentStep;

   /* [COVERS: DSG_CIL_0105] */
   Rte_Call_pclBelt_D_GetRange_mm(&s16OriginPosition, &s16MaxPosition);
   u8OriginPositionInmmMSB = U16_GET_HIGH_BYTE((uint16)s16OriginPosition);
   u8OriginPositionInmmLSB = U16_GET_LOW_BYTE((uint16)s16OriginPosition);

   /* [COVERS: DSG_CIL_0108] */
   Rte_Call_pclBelt_D_GetFromT0_mm(&s16BeltPayoutInmm);
   u8BeltPayoutInmmMSB = U16_GET_HIGH_BYTE((uint16)s16BeltPayoutInmm);
   u8BeltPayoutInmmLSB = U16_GET_LOW_BYTE((uint16)s16BeltPayoutInmm);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID                            */
   /* Byte1 : (u8CurrentCycle<<3) | u8CurrentStep */
   /* Byte2 : Origin position MSB                 */
   /* Byte3 : Origin position LSB                 */
   /* Byte4 : PayoutRaw_mm MSB                    */
   /* Byte5 : PayoutRaw_mm LSB                    */
   /* Byte6 : KU8_MAX                             */
   /* Byte7 : KU8_MAX                             */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_14;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = u8CycleStep;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8OriginPositionInmmMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = u8OriginPositionInmmLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = u8BeltPayoutInmmMSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = u8BeltPayoutInmmLSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = KU8_MAX;
}


/**
 * \brief
 *		 This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 15.
 * \param
 * 		void
 * \return
 * 		void
 */
/* [COVERS: DSG_CIL_0093] */
LOCAL void cil_Update_07Cx_Block15_InfosToSend(void)
{
   /* Received data before multiplexing */
   uint8 u8CurrentStep;
   uint8 u8CurrentCycle;

   /******************************************/
   /* Read infos from application components */
   /******************************************/
   Rte_Read_prrStepNumber_u8StepNumber(&u8CurrentStep);
   Rte_Read_prrCycleNumber_u8CycleNumber(&u8CurrentCycle);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID                    */
   /* Byte1 : u8CurrentCycle              */
   /* Byte2 : u8CurrentStep               */
   /* Byte3 : KU8_MAX                     */
   /* Byte4 : KU8_MAX                     */
   /* Byte5 : KU8_MAX                     */
   /* Byte6 : KU8_MAX                     */
   /* Byte7 : KU8_MAX                     */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_15;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = u8CurrentCycle;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8CurrentStep;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = KU8_MAX;
}


/**
 * \brief
 *		 This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 16.
 * \param
 * 		void
 * \return
 * 		void
 */
/* [COVERS: DSG_CIL_0094] */
LOCAL void cil_Update_07Cx_Block16_InfosToSend(void)
{
   /******************************************/
   /* Read infos from application components */
   /******************************************/

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID  */
   /* Byte1 : KU8_MAX   */
   /* Byte2 : KU8_MAX   */
   /* Byte3 : KU8_MAX   */
   /* Byte4 : KU8_MAX   */
   /* Byte5 : KU8_MAX   */
   /* Byte6 : KU8_MAX   */
   /* Byte7 : KU8_MAX   */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_16;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = KU8_MAX;
}


/**
 * \brief
 *		 This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 17.
 * \param
 * 		void
 * \return
 * 		void
 */
/* [COVERS: DSG_CIL_0095] */
LOCAL void cil_Update_07Cx_Block17_InfosToSend(void)
{
   /* Received data before multiplexing */
   uint16 u16VHs1;
   
   /* Adaptation of separated variables */
   uint8 u8VHs1MSB;
   uint8 u8VHs1LSB;

   /******************************************/
   /* Read infos from application components */
   /******************************************/
   /* To be modified: Generate the corresponding RTE macros to call the VSA service */
   /* HS switch voltage */
   /* [COVERS: DSG_CIL_0117] */
   Rte_Call_pclHS1_V_Get(&u16VHs1);
   u8VHs1MSB = (uint8)U16_GET_HIGH_BYTE(u16VHs1);
   u8VHs1LSB = (uint8)U16_GET_LOW_BYTE(u16VHs1);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID          */
   /* Byte1 : HS Switch voltage filtered MSB    */
   /* Byte2 : HS SWitch voltage filtered LSB    */
   /* Byte3 : KU8_MAX  */
   /* Byte4 : KU8_MAX  */
   /* Byte5 : KU8_MAX  */
   /* Byte6 : KU8_MAX  */
   /* Byte7 : KU8_MAX  */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_17;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = u8VHs1MSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = u8VHs1LSB;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = KU8_MAX;
}

/**
 * \brief
 *		 This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 18.
 * \param
 * 		void
 * \return
 * 		void
 */
/* [COVERS: DSG_CIL_0096] */
LOCAL void cil_Update_07Cx_Block18_InfosToSend(void)
{
   /******************************************/
   /* Read infos from application components */
   /******************************************/

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID          */
   /* Byte1 :  */
   /* Byte2 :  */
   /* Byte3 :  */
   /* Byte4 :  */
   /* Byte5 :  */
   /* Byte6 :  */
   /* Byte7 :  */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_18;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = KU8_MAX;
}

/**
 * \brief
 *		 This function fill the CAN buffer for measurement frame sent
        (7C4 and 7C6 identifiers), when the block number to send is 20.
 * \param
 * 		void
 * \return
 * 		void
 */
/* [COVERS: DSG_CIL_0097] */
LOCAL void cil_Update_07Cx_Block20_InfosToSend(void)
{
   uint32 u32DeficiencyLevel;

   /******************************************/
   /* Read infos from application components */
   /******************************************/
   /* [COVERS: DSG_CIL_0118] */
   (void)Rte_Call_pclMotor_T_GetDeficiencyLevel(&u32DeficiencyLevel);

   /************************/
   /* CAN frame formatting */
   /************************/
   /* Byte0 : Block_ID          */
   /* Byte1 :  Deficiency Level */
   /* Byte2 :  Deficiency Level */
   /* Byte3 :  Deficiency Level */
   /* Byte4 :  Deficiency Level */
   /* Byte5 :  */
   /* Byte6 :  */
   /* Byte7 :  */
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = CU8_BLOCK_ID_20;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = U32_GET_HIGH_BYTE(u32DeficiencyLevel);
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = U32_GET_HIGH_MIDDLE_BYTE(u32DeficiencyLevel);
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = U32_GET_LOW_MIDDLE_BYTE(u32DeficiencyLevel);
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = U32_GET_LOW_BYTE(u32DeficiencyLevel);
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = KU8_MAX;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = KU8_MAX;
}

/**
 * \brief
 *		 This function fill the CAN buffer with 0 in case incorrect measurement
         frame block is requested.
         The function is called If the block in not correct or undefined.
 * \param
 * 		void
 * \return
 * 		void
 */
LOCAL void cil_Update_07Cx_IncorrectBlock_InfosToSend(void)
{
   cil_stMeasurementFrameContent.Meas_RBTM_FL_01 = KU8_ZERO;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_02 = KU8_ZERO;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_03 = KU8_ZERO;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_04 = KU8_ZERO;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_05 = KU8_ZERO;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_06 = KU8_ZERO;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_07 = KU8_ZERO;
   cil_stMeasurementFrameContent.Meas_RBTM_FL_08 = KU8_ZERO;
}


/**
 * \brief
 *		 The called function reads Measurement frames parameters and call the function that has to
 *		 fill RTE with desired data. Find the next enabled block, and call the corresponding sub-function
 *		 in charge to fill the measurement frame content for this specific block.
 * \param
 * 		void
 * \return
 * 		B_TRUE if it's updated or B_FALSE if it's not updated.
 */
 /* [COVERS: DSG_CIL_0127] */
LOCAL boolean cil_Update_07Cx_InfosToSend(void)
{
   uint32  u32CILMFSelectedBlocks;
   boolean bIsUpdated;

    /* [COVERS: DSG_CIL_0120] */
   u32CILMFSelectedBlocks = (uint32) (
                                      ((uint32)(NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_RamBlockData.NVP_au8MeasFrameBlockConfig[KU8_INDEX_0_IN_SELECTED_BLOCKS_ARRAY]) << KU8_POS_L_HIGH_MIDDLE_BYTE)
                                    | ((uint32)(NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_RamBlockData.NVP_au8MeasFrameBlockConfig[KU8_INDEX_1_IN_SELECTED_BLOCKS_ARRAY]) << KU8_POS_L_LOW_MIDDLE_BYTE)
                                    | ((uint32)(NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_RamBlockData.NVP_au8MeasFrameBlockConfig[KU8_INDEX_2_IN_SELECTED_BLOCKS_ARRAY]))
                                    );


   /* Check if there are activated blocks */
   /* [COVERS: DSG_CIL_0078] */
   if (KU32_ZERO != u32CILMFSelectedBlocks)
   {
      do
      {
         /* Update the block to send for next frame transmission */
         /* Set the next bit position to check if the associated block is activated */
         if (cil_u32MeasureNextBlockToSendMask >= U32_BLOCK_MASK(CU8_BLOCK_ID_20))
         {
            /* Previous tested bit was the last implemented block, go back to bit 0 (corresponding to block 01) */
            cil_u32MeasureNextBlockToSendMask = U32_BLOCK_MASK(CU8_BLOCK_ID_01);
            cil_u8MeasureNextBlockToSend = CU8_BLOCK_ID_01;
         }
         else
         {
            /* Increment the bit position to test (right to left bit search) */
            cil_u32MeasureNextBlockToSendMask = NEXT_BLOCK(cil_u32MeasureNextBlockToSendMask);
            cil_u8MeasureNextBlockToSend++;
         }
      } while ((cil_u32MeasureNextBlockToSendMask & u32CILMFSelectedBlocks) == (uint32)0);

      /* Check if block encoding function is implemented */
      if (KU8_CIL_MF_NB_OF_BLOCKS >= cil_u8MeasureNextBlockToSend)
      {
         /* Call function corresponding to requested block */
         /* Block index starts at index 1, function pointer starts at index 0 */
         (*(cil_capfCILBlocksEncodFunc[cil_u8MeasureNextBlockToSend-KU8_ONE]))();
         bIsUpdated = B_TRUE;
      }
      else
      {
         cil_Update_07Cx_IncorrectBlock_InfosToSend();
         bIsUpdated = B_TRUE;
      }
   }
   else
   {
      /* Nothing to do : no block activated */
      bIsUpdated = B_FALSE;
   }

   return bIsUpdated;
}
/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_START_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/**
 * \brief
 *		 This service is in charge of selecting which block will be displayed and it is in charge of writing data that should be send.
 * \param
 * 		void
 * \return
 * 		void
 */
void CIL_runManageMeasurementFrame(void)
{
   boolean bInfoUpdated;

   if (KU8_ZERO != NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_RamBlockData.NVP_u8MeasFrameTiming)
   {
      /* Is it time for a new block ? */
      if (KU8_ZERO == cil_u8MFPeriodCounter)
      {
         bInfoUpdated = cil_Update_07Cx_InfosToSend();

         if (B_TRUE == bInfoUpdated)
         {
            /* Write data to be sent */
            if (KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION)
            {
                /* [COVERS: DSG_CIL_0125] */
               (void)Rte_Write_P_Meas_RBTM_FL_ST3_Meas8_RBTM_FL_ST3(&cil_stMeasurementFrameContent);
            }
            else if (KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)
            {
                /* [COVERS: DSG_CIL_0126] */
               (void)Rte_Write_P_Meas_RBTM_FR_ST3_Meas8_RBTM_FR_ST3(&cil_stMeasurementFrameContent);
            }
            else
            {
               (void)Rte_Write_P_Meas_RBTM_FL_ST3_Meas8_RBTM_FL_ST3(&cil_stMeasurementFrameContent);
            }
         }
         else
         {
            /* Suspend measurement frame sending since there are no blocks activated */
         }

         /* Reload period counter */
          /* [COVERS: DSG_CIL_0120] */
         cil_u8MFPeriodCounter = NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_RamBlockData.NVP_u8MeasFrameTiming;
      }
      else
      {
         /* Nothing to do */
      }

      cil_u8MFPeriodCounter--;
   }
   else
   {
      /* MF Disabled */
   }
}

/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/

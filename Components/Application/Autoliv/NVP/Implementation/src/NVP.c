
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
$Revision: 1.3.1.14 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/NVP/Implementation/src/project.pj $
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
#include "NVP_Generated.h"
#include "NVP_Stubs.h"
#include "NVP_Cfg.h"
#include "common.h"

#include "NvM_PrivateCfg.h"
#include "NvM_Cfg.h"
#include "Fee.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 * 		Vehicle equipment ID
 */
#define KU8_NVP_READ_DATA_VEHICLE_EQUIPMENT ((uint8)0x0000)
/**
 * \brief
 * 		Vehicle development ID
 */
#define KU8_NVP_READ_DATA_DEVELOPMENT       ((uint8)0x0001)
/**
 * \brief
 * 		Undervoltage minim value
 */
#define KU16_NVP_UV_MIN_VALUE                ((uint16)1531)
/**
 * \brief
 * 		Undervoltage max value
 */
#define KU16_NVP_UV_MAX_VALUE                ((uint16)2041)
/**
 * \brief
 * 		Overvoltage minim value
 */
#define KU16_NVP_OV_MIN_VALUE                ((uint16)3266)
/**
 * \brief
 * 		Overvoltage max value
 */
#define KU16_NVP_OV_MAX_VALUE                ((uint16)3674)
/**
 * \brief
 * 		Voltage multiply factor
 */
#define KU32_NVP_VOLTAGE_MUL_FACTOR         ((uint32)49)
/**
 * \brief
 * 		Voltage divide factor
 */
#define KU32_NVP_VOLTAGE_DIV_FACTOR         ((uint32)10)
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
/**
 * \brief
 *		Variable that holdes the vehicle equipment data
 * \remarks
 *		NA
 */
 nvp_stVehicleEquipmentData NVP_stVehicleEquipmentData;

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
 *     Function that checks if a bit is set
 * \param
 *     value - value to be checked
 *     bitNumber - bit number to be checked
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *     ONE - if bit is set and ZERO - bit not set
 **/
/*[COVERS: DSG_NVP_0006] */
LOCAL uint8 nvp_CheckIfBitSet(uint8 value, uint8 bitNumber)
{
   uint8 retVal = KU8_ZERO;

   if (value & (uint8)(KU8_ONE << bitNumber))
   {
      retVal = KU8_ONE;
   }
   else
   {
      retVal = KU8_ZERO;
   }

   return retVal;
}

/**
 * \brief
 *     Function that computes the raw voltage values into physical values
 * \param
 *     u16VoltageValue - raw voltage value
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *     Computed voltage value
 **/
/*[COVERS: DSG_NVP_0005] */
LOCAL uint16 nvp_ComputeRawVoltageValues(uint16 u16VoltageValue)
{
   uint16 u16computedVolage = u16VoltageValue;

   u16computedVolage = (uint16)( (uint32)(u16computedVolage * KU32_NVP_VOLTAGE_MUL_FACTOR) / KU32_NVP_VOLTAGE_DIV_FACTOR );
   
   return u16computedVolage;
}

/**
 * \brief
 *     Function that checks if the SSA vehicle equipment block was written before
 * \param
 *     None
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *     ONE - if block was written ZERO - block was not written
 **/
/*[COVERS: DSG_NVP_0004] */
LOCAL uint8 nvp_CheckVehicleEquipmentStatus(void)
{
   uint8 u8retVal = KU8_ONE;
   uint16 u16calculatedVoltageUV, u16calculatedVoltageUVAbort, u16calculatedVoltageOV, u16calculatedVoltageOVAbort  = KU16_ZERO;
   VehicleEquipment_StorageType *VehicleEquipmentData;

   VehicleEquipmentData = NvM_BlockDescriptorTable_at[NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_CurrentVehicleEquipment].RamBlockDataAddr_t;

   u16calculatedVoltageUV = (uint16)(VehicleEquipmentData->Unterspannungsbereichsschwelle[KU8_ONE] +
                                                     (uint16)(VehicleEquipmentData->Unterspannungsbereichsschwelle[KU8_ZERO] << KU8_EIGHT));
   if((u16calculatedVoltageUV < KU16_NVP_UV_MIN_VALUE) || (u16calculatedVoltageUV > KU16_NVP_UV_MAX_VALUE))
   {
      u8retVal = KU8_ZERO;
   }

   u16calculatedVoltageUVAbort = (uint16)(VehicleEquipmentData->Unterspannungsabbruchschwelle[KU8_ONE] +
                                                (uint16)(VehicleEquipmentData->Unterspannungsabbruchschwelle[KU8_ZERO] << KU8_EIGHT));
   if((u16calculatedVoltageUVAbort < KU16_NVP_UV_MIN_VALUE) || (u16calculatedVoltageUVAbort > KU16_NVP_UV_MAX_VALUE))
   {
      u8retVal = KU8_ZERO;
   }

   u16calculatedVoltageOV = (uint16)(VehicleEquipmentData->Uberspannungsbereichsschwelle[KU8_ONE] +
                                                    ((uint16)VehicleEquipmentData->Uberspannungsbereichsschwelle[KU8_ZERO] << KU8_EIGHT));
   if((u16calculatedVoltageOV < KU16_NVP_OV_MIN_VALUE) || (u16calculatedVoltageOV > KU16_NVP_OV_MAX_VALUE))
   {
      u8retVal = KU8_ZERO;
   }

   u16calculatedVoltageOVAbort = (uint16)(VehicleEquipmentData->Uberspannungsabbruchschwelle[KU8_ONE] +
                                               (uint16)(VehicleEquipmentData->Uberspannungsabbruchschwelle[KU8_ZERO] << KU8_EIGHT));
   if((u16calculatedVoltageOVAbort < KU16_NVP_OV_MIN_VALUE) || (u16calculatedVoltageOVAbort > KU16_NVP_OV_MAX_VALUE))
   {
      u8retVal = KU8_ZERO;
   }

   if(KU8_ZERO != u8retVal)
   {
      NVP_stVehicleEquipmentData.UndervoltageAbort = nvp_ComputeRawVoltageValues(u16calculatedVoltageUVAbort);
      NVP_stVehicleEquipmentData.Undervoltage = nvp_ComputeRawVoltageValues(u16calculatedVoltageUV);
      NVP_stVehicleEquipmentData.OvervoltageAbort = nvp_ComputeRawVoltageValues(u16calculatedVoltageOVAbort);
      NVP_stVehicleEquipmentData.Overvoltage = nvp_ComputeRawVoltageValues(u16calculatedVoltageOV);
   }

   return u8retVal;
}

/**
 * \brief
 *     Function will handle the CALIB Vehicle equipment data to local structure
 * \param
 *     u8ReadDataTarget - target to read data from Vehicle equipment or Development
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *     None
 **/
/*[COVERS: DSG_NVP_0001] */
LOCAL void nvp_CopyVehicleEquipmentDefaultData(uint8 u8ReadDataTarget)
{
   uint8 nvp_u8TransferData = KU8_ZERO;

   switch (u8ReadDataTarget)
   {
   case KU8_NVP_READ_DATA_VEHICLE_EQUIPMENT:
      nvp_u8TransferData = CALIB_BLOCK_ID_VEHICLE_EQUIPMENT_RomBlockData.NVP_u8VehEquipFirstByte;
      NVP_stVehicleEquipmentData.VehicleSteeringConfig = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_ZERO);
      NVP_stVehicleEquipmentData.BSRActivation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_ONE);
      NVP_stVehicleEquipmentData.BltHandOverAvailabiliy = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_TWO);
      NVP_stVehicleEquipmentData.HWALeftActivation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_FOUR);
      NVP_stVehicleEquipmentData.HWARightActivation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_FIVE);
      NVP_stVehicleEquipmentData.APIActivation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_SIX);

      NVP_stVehicleEquipmentData.PreSafeCycleActivation = CALIB_BLOCK_ID_VEHICLE_EQUIPMENT_RomBlockData.NVP_u32VehEquipPreSafeCycleAct;

      nvp_u8TransferData = CALIB_BLOCK_ID_VEHICLE_EQUIPMENT_RomBlockData.NVP_u8VehEquipSecondByte;
      NVP_stVehicleEquipmentData.ORCPreSafe8Activation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_ZERO);
      NVP_stVehicleEquipmentData.Reserved3 = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_ONE);
      NVP_stVehicleEquipmentData.ReleaseOutOfMemory = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_FIVE);
      NVP_stVehicleEquipmentData.BSROutOfMemory = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_SIX);
      NVP_stVehicleEquipmentData.PreSafeOutOfMemory = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_SEVEN);

      NVP_stVehicleEquipmentData.UndervoltageAbort = CALIB_BLOCK_ID_VEHICLE_EQUIPMENT_RomBlockData.NVP_u16VehEquipmentUVAbort;
      NVP_stVehicleEquipmentData.Undervoltage = CALIB_BLOCK_ID_VEHICLE_EQUIPMENT_RomBlockData.NVP_u16VehEquipmentUV;
      NVP_stVehicleEquipmentData.OvervoltageAbort = CALIB_BLOCK_ID_VEHICLE_EQUIPMENT_RomBlockData.NVP_u16VehEquipmentOVAbort;
      NVP_stVehicleEquipmentData.Overvoltage = CALIB_BLOCK_ID_VEHICLE_EQUIPMENT_RomBlockData.NVP_u16VehEquipmentOV;
      break;

   default:
      break;
   }
}

/**
 * \brief
 *     Function will handle the Ssa Coding Vehicle equipment data to local structure
 * \param
 *     u8ReadDataTarget - target to read data from Vehicle equipment or Development
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *     None
 **/
/*[COVERS: DSG_NVP_0003] */
LOCAL void nvp_CopyVehicleEquipmentEOLData(uint8 u8ReadDataTarget)
{
   uint8 nvp_u8TransferData = KU8_ZERO;
   VehicleEquipment_StorageType *VehicleEquipmentData;
   ZZZ_VehicleEquipment_Development_StorageType *ZZZVehicleEquipmentData;

   switch (u8ReadDataTarget)
   {
   case KU8_NVP_READ_DATA_VEHICLE_EQUIPMENT:
      VehicleEquipmentData = NvM_BlockDescriptorTable_at[NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_CurrentVehicleEquipment].RamBlockDataAddr_t;

      nvp_u8TransferData = VehicleEquipmentData->Equipment1[KU8_ZERO];
      NVP_stVehicleEquipmentData.VehicleSteeringConfig = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_ZERO);
      NVP_stVehicleEquipmentData.BSRActivation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_ONE);
      NVP_stVehicleEquipmentData.BltHandOverAvailabiliy = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_TWO);
      NVP_stVehicleEquipmentData.HWALeftActivation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_FOUR);
      NVP_stVehicleEquipmentData.HWARightActivation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_FIVE);
      NVP_stVehicleEquipmentData.APIActivation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_SIX);

      NVP_stVehicleEquipmentData.PreSafeCycleActivation = (uint32)(VehicleEquipmentData->Equipment2[KU8_ZERO] + (uint32)(VehicleEquipmentData->Equipment3[KU8_ZERO] << KU8_EIGHT) +
                                                          (uint32)(VehicleEquipmentData->Equipment4[KU8_ZERO] << KU8_SIXTEEN) + (uint32)(VehicleEquipmentData->Equipment5[KU8_ZERO] << KU8_TWENTY_FOUR));

      nvp_u8TransferData = VehicleEquipmentData->Equipment6[KU8_ZERO];
      NVP_stVehicleEquipmentData.ORCPreSafe8Activation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_ZERO);
      NVP_stVehicleEquipmentData.Reserved3 = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_ONE);
      NVP_stVehicleEquipmentData.ReleaseOutOfMemory = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_FIVE);
      NVP_stVehicleEquipmentData.BSROutOfMemory = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_SIX);
      NVP_stVehicleEquipmentData.PreSafeOutOfMemory = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_SEVEN);
      break;

  /*[COVERS: DSG_NVP_0002] */
   case KU8_NVP_READ_DATA_DEVELOPMENT:
      ZZZVehicleEquipmentData = NvM_BlockDescriptorTable_at[NvMConf_NvMBlockDescriptor_Ct_MBBL_SsaAppl_CodingNvmCoding_ZZZVehicleEquipmentDevelopment].RamBlockDataAddr_t;

      /* Byte 0*/
      nvp_u8TransferData = ZZZVehicleEquipmentData->Bitfield[KU8_ZERO];
      NVP_stVehicleEquipmentData.MeasFrame1Activation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_ZERO);
      NVP_stVehicleEquipmentData.MeasFrame2Activation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_ONE);
      NVP_stVehicleEquipmentData.MeasFrame3Activation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_TWO);
      NVP_stVehicleEquipmentData.MeasFrame4Activation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_THREE);
      NVP_stVehicleEquipmentData.MeasFrame5Activation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_FOUR);
      NVP_stVehicleEquipmentData.MeasFrame6Activation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_FIVE);
      NVP_stVehicleEquipmentData.MeasFrame7Activation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_SIX);
      NVP_stVehicleEquipmentData.MeasFrame8Activation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_SEVEN);

      /* Byte 1*/
      nvp_u8TransferData = ZZZVehicleEquipmentData->Bitfield[KU8_ONE];
      NVP_stVehicleEquipmentData.PreSafeFuncActivation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_ZERO);
      NVP_stVehicleEquipmentData.DisplayMsgActivation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_ONE);
      NVP_stVehicleEquipmentData.CounterLimitActivation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_TWO);
      NVP_stVehicleEquipmentData.CRCFaultActivation = nvp_CheckIfBitSet(nvp_u8TransferData, KU8_THREE);
      break;
   default:
      break;
   }
}

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/**
 * \brief
 *     NVP init function will be called periodicaly to check if vehicle equipment configuration data was written
 * \param
 *     None
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 *     None
 **/
void NVP_Init(void)
{
   /* Check if the block was written before by checking voltage thresholds */
   if (KU8_ZERO != nvp_CheckVehicleEquipmentStatus())
   {
      nvp_CopyVehicleEquipmentEOLData(KU8_NVP_READ_DATA_VEHICLE_EQUIPMENT);
   }
   else
   {
      nvp_CopyVehicleEquipmentDefaultData(KU8_NVP_READ_DATA_VEHICLE_EQUIPMENT);
   }

   nvp_CopyVehicleEquipmentEOLData(KU8_NVP_READ_DATA_DEVELOPMENT);
}

/******************************************************************************
End Of File
*****************************************************************************/

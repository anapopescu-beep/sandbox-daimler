
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  Dcm_Callout_Stubs.c
      Project:  Vector Basic Runtime System for MICROSAR4
       Module:  BrsMain

  \brief Description:  File for implementation of DCM callouts.
                       This file is a template only - please implement the callouts according to your needs.

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
 ----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
  ----------------------------  ------------  -------------------------------------------------------------------------
  Benjamin Walter               visbwa        Vector Informatik GmbH
  Sascha Mauser                 vismaa        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
 ----------------------------------------------------------------------------------------------------------------------
  01.00.00  2015-07-14  visbwa  Initial creation for usage with StartApplication
  01.00.01  2016-06-22  visbwa  Added sample code information block
  01.00.02  2016-08-29  visbwa  Added Dcm_DiagnosticService_0x38()
  01.00.03  2017-08-31  visbwa  Added callouts for Dcm_DiagnosticService 0x00, 0xB2, 0xB6 and 0xB7
  01.00.04  2017-12-06  visbwa  Reworked sample/example code disclaimer
  01.00.05  2019-02-01  visbwa  Added support for DCM ASR Version 4.2.2
  01.00.06  2019-03-11  vismaa  Changed DYNAMIC PART for Dcm_DiagnosticServiceXX
**********************************************************************************************************************/

/**********************************************************************************************************************
*  EXAMPLE CODE ONLY
*  -------------------------------------------------------------------------------------------------------------------
*  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
*  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
*  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
*  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
*  according to the state of the art before their use.
*********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Dcm.h"
#include "Dcm_Cfg.h"
#include "Mcu.h"
#include "vstdlib.h"
#include "DIA.h"
#include "Nvp_Generated.h"
#include "NvM_Cfg.h"
#include "NvM.h"

/* Magic pattern for boot manager. This pattern can be found in the file bm_shared.h: */
#  define kFblBmFblStartMagicByte0        0x50u /* 'P' */
#  define kFblBmFblStartMagicByte1        0x72u /* 'r' */
#  define kFblBmFblStartMagicByte2        0x6Fu /* 'o' */
#  define kFblBmFblStartMagicByte3        0x67u /* 'g' */
#  define kFblBmFblStartMagicByte4        0x53u /* 'S' */
#  define kFblBmFblStartMagicByte5        0x69u /* 'i' */
#  define kFblBmFblStartMagicByte6        0x67u /* 'g' */
#  define kFblBmFblStartMagicByte7        0x6Eu /* 'n' */

#  define BM_NO_OF_MAGIC_BYTES            0x08u

#define DCM_RAM_ADDRESS_END               0x70017F00u
#define DCM_RAM_ADDRESS_MAX_SIZE          300u

#define DCM_RAM_EEPROM_ALIAS_ADDRESS_BEGIN 0xEE000000u
#define DCM_RAM_EEPROM_ALIAS_BLOCK_NRS     29u

/**********************************************************************************************************************
  BLOCK ADDRESSES FOR EEPROM ALIAS & NVM BLOCK IDS
**********************************************************************************************************************/
#define BLOCKADDRESS_RAM_ECULOCATION                           0xEE030000u
#define NVMBLOCKID_ECULOCATION                                 34u

#define BLOCKADDRESS_RAM_ASSEMBLYMANUFDATEANDSN                0xEE040000u
#define NVMBLOCKID_ASSEMBLYMANUFDATEANDSN                      35u

#define BLOCKADDRESS_RAM_HBCALIBRATION                         0xEE050000u
#define NVMBLOCKID_HBCALIBRATION                               36u

#define BLOCKADDRESS_RAM_AEETRACEABILITY                       0xEE060000u
#define NVMBLOCKID_AEETRACEABILITY                             38u

#define BLOCKADDRESS_RAM_EXECUTIONCOUNTERS                     0xEE070000u
#define NVMBLOCKID_EXECUTIONCOUNTERS                           39u

#define BLOCKADDRESS_RAM_MEASUREMENTFRAME12CONFIG              0xEE080000u
#define NVMBLOCKID_MEASUREMENTFRAME12CONFIG                    41u

#define BLOCKADDRESS_RAM_MEASUREMENTFRAMECONFIG                0xEE090000u
#define NVMBLOCKID_MEASUREMENTFRAMECONFIG                      42u

#define BLOCKADDRESS_RAM_WARMRESET                             0xEE0A0000u
#define NVMBLOCKID_WARMRESET                                   70u

#define BLOCKADDRESS_RAM_HWAREPETITION                         0xEE0B0000u
#define NVMBLOCKID_HWAREPETITION                               75u

#define BLOCKADDRESS_RAM_TESTSPARAM                            0xEE0C0000u
#define NVMBLOCKID_TESTSPARAM                                  40u

#define BLOCKADDRESS_RAM_TEMP_SENSOR_TABLE                     0xEE0D0000u
#define NVMBLOCKID_TEMP_SENSOR_TABLE                           76u

#define BLOCKADDRESS_RAM_VELOCITYPID                           0xEE0E0000u
#define NVMBLOCKID_VELOCITYPID                                 80u

#define BLOCKADDRESS_RAM_AECSTATUS                             0xEE0F0000u
#define NVMBLOCKID_AECSTATUS                                   81u

#define BLOCKADDRESS_RAM_ATMENABLEPARAM                        0xEE100000u
#define NVMBLOCKID_ATMENABLEPARAM                              82u

#define BLOCKADDRESS_RAM_PRE_SAFE_RECORDER_1                   0xEE110000u
#define NVMBLOCKID_PRE_SAFE_RECORDER_1                         71u

#define BLOCKADDRESS_RAM_PRE_SAFE_RECORDER_2                   0xEE120000u
#define NVMBLOCKID_PRE_SAFE_RECORDER_2                         74u

#define BLOCKADDRESS_RAM_PRE_SAFE_RECORDER_ID                  0xEE130000u
#define NVMBLOCKID_PRE_SAFE_RECORDER_ID                        72u

#define BLOCKADDRESS_RAM_CYCLE0                                0xEE140000u
#define NVMBLOCKID_CYCLE_0                                     43u

#define BLOCKADDRESS_RAM_STEP0                                 0xEE370000u
#define NVMBLOCKID_STEP_0                                      47u

#define BLOCKADDRESS_RAM_SYSTEM_CONTEXT_0                      0xEEC80000u
#define NVMBLOCKID_SYSTEM_CONTEXT_0                            77u

#define BLOCKADDRESS_RAM_SYSTEM_CONTEXT_1                      0xEEC90000u
#define NVMBLOCKID_SYSTEM_CONTEXT_1                            78u

#define BLOCKADDRESS_RAM_SYSTEM_CONTEXT_2                      0xEECA0000u
#define NVMBLOCKID_SYSTEM_CONTEXT_2                            79u

#define BLOCKADDRESS_RAM_CYCLE_DELAYS_MB                       0xEECB0000u
#define NVMBLOCKID_CYCLE_DELAYS_MB                             44u

#define BLOCKADDRESS_RAM_HAPTIC_CONFIG_MB                      0xEECC0000u
#define NVMBLOCKID_HAPTIC_CONFIG_MB                            45u

#define BLOCKADDRESS_RAM_EOL_MAPPING_MB                        0xEECD0000u
#define NVMBLOCKID_EOL_MAPPING_MB                              46u

#define BLOCKADDRESS_RAM_CAN_INPUT_SIGNALS                     0xEECE0000u
#define NVMBLOCKID_CAN_INPUT_SIGNALS                           73u

#define BLOCKADDRESS_RAM_HW_VERSION                            0xEECF0000u
#define NVMBLOCKID_HW_VERSION                                  37u

#define BLOCKADDRESS_RAM_PCBA_PPN                              0xEED00000u
#define NVMBLOCKID_PCBA_PPN                                    100u

#define BLOCKADDRESS_RAM_HW_PARTNUMBER                         0xEED10000u
#define NVMBLOCKID_HW_PARTNUMBER                               102u

/* This section must be mapped to no-clear RAM! */
#define FBLBM_MAIN_MAGICFLAG_START_SEC_VAR_NOINIT
#include "MemMap.h"
volatile uint8 FblBmMagicFlag[BM_NO_OF_MAGIC_BYTES];
#define FBLBM_MAIN_MAGICFLAG_STOP_SEC_VAR_NOINIT
#include "MemMap.h"
#define FBLBM_MAIN_PROGCONDITIONS_START_SEC_VAR_NOINIT
#include "MemMap.h"
Dcm_ProgConditionsType   DcmProgConditions;
#define FBLBM_MAIN_PROGCONDITIONS_STOP_SEC_VAR_NOINIT
#include "MemMap.h"

/**********************************************************************************************************************
  LOOKUP TABLE FOR EEPROM ALIAS - BLOCK ADDRESS RAM ALIAS / NVM BLOCK ID / NVP RAMBLOCKDATA
**********************************************************************************************************************/
typedef struct
{
   uint32 EEPROM_Alias;
   uint8 NVM_Block_Id;
   uint8 *RAM_Mirror_Block_Address;

} EEPROMLUTType;

EEPROMLUTType EEPROM_Alias_LookUpTable[DCM_RAM_EEPROM_ALIAS_BLOCK_NRS] =
    {
        {BLOCKADDRESS_RAM_ECULOCATION, NVMBLOCKID_ECULOCATION, &NVP_BLOCK_ID_ECU_LOCATION_RamBlockData},
        {BLOCKADDRESS_RAM_ASSEMBLYMANUFDATEANDSN, NVMBLOCKID_ASSEMBLYMANUFDATEANDSN, &NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_RamBlockData},
        {BLOCKADDRESS_RAM_HBCALIBRATION, NVMBLOCKID_HBCALIBRATION, &NVP_BLOCK_ID_HB_CALIBRATION_RamBlockData},
        {BLOCKADDRESS_RAM_AEETRACEABILITY, NVMBLOCKID_AEETRACEABILITY, &NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData},
        {BLOCKADDRESS_RAM_EXECUTIONCOUNTERS, NVMBLOCKID_EXECUTIONCOUNTERS, &NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData},
        {BLOCKADDRESS_RAM_MEASUREMENTFRAME12CONFIG, NVMBLOCKID_MEASUREMENTFRAME12CONFIG, &NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData},
        {BLOCKADDRESS_RAM_MEASUREMENTFRAMECONFIG, NVMBLOCKID_MEASUREMENTFRAMECONFIG, &NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_RamBlockData},
        {BLOCKADDRESS_RAM_WARMRESET, NVMBLOCKID_WARMRESET, &NVP_BLOCK_ID_WARM_RESET_RamBlockData},
        {BLOCKADDRESS_RAM_HWAREPETITION, NVMBLOCKID_HWAREPETITION, &NVP_BLOCK_ID_HWA_REPETITION_RamBlockData},
        {BLOCKADDRESS_RAM_TESTSPARAM, NVMBLOCKID_TESTSPARAM, &NVP_BLOCK_ID_TESTS_PARAM_RamBlockData},
        {BLOCKADDRESS_RAM_TEMP_SENSOR_TABLE, NVMBLOCKID_TEMP_SENSOR_TABLE, &NVP_BLOCK_TEMP_SENSOR_TABLE_RamBlockData},
        {BLOCKADDRESS_RAM_VELOCITYPID, NVMBLOCKID_VELOCITYPID, &NVP_BLOCK_ID_VELOCITY_PID_PARAM_RamBlockData},
        {BLOCKADDRESS_RAM_AECSTATUS, NVMBLOCKID_AECSTATUS, &NVP_BLOCK_ID_AEC_STATUS_RamBlockData},
        {BLOCKADDRESS_RAM_ATMENABLEPARAM, NVMBLOCKID_ATMENABLEPARAM, &NVP_BLOCK_ID_ATM_ENABLE_PARAM_RamBlockData},
        {BLOCKADDRESS_RAM_PRE_SAFE_RECORDER_1, NVMBLOCKID_PRE_SAFE_RECORDER_1, &NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData},
        {BLOCKADDRESS_RAM_PRE_SAFE_RECORDER_2, NVMBLOCKID_PRE_SAFE_RECORDER_2, &NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData},
        {BLOCKADDRESS_RAM_PRE_SAFE_RECORDER_ID, NVMBLOCKID_PRE_SAFE_RECORDER_ID, &NVP_BLOCK_ID_PRE_SAFE_RECORDER_ID_RamBlockData},
        {BLOCKADDRESS_RAM_CYCLE0, NVMBLOCKID_CYCLE_0, &NVP_BLOCK_ID_CYCLE_0_RamBlockData},
        {BLOCKADDRESS_RAM_STEP0, NVMBLOCKID_STEP_0, &NVP_BLOCK_ID_STEP_0_RamBlockData},
        {BLOCKADDRESS_RAM_SYSTEM_CONTEXT_0, NVMBLOCKID_SYSTEM_CONTEXT_0, &NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData},
        {BLOCKADDRESS_RAM_SYSTEM_CONTEXT_1, NVMBLOCKID_SYSTEM_CONTEXT_1, &NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData},
        {BLOCKADDRESS_RAM_SYSTEM_CONTEXT_2, NVMBLOCKID_SYSTEM_CONTEXT_2, &NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData},
        {BLOCKADDRESS_RAM_CYCLE_DELAYS_MB, NVMBLOCKID_CYCLE_DELAYS_MB, &NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData},
        {BLOCKADDRESS_RAM_HAPTIC_CONFIG_MB, NVMBLOCKID_HAPTIC_CONFIG_MB, &NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData},
        {BLOCKADDRESS_RAM_EOL_MAPPING_MB, NVMBLOCKID_EOL_MAPPING_MB, &NVP_BLOCK_ID_EOL_MAPPING_MB_RamBlockData},
        {BLOCKADDRESS_RAM_CAN_INPUT_SIGNALS, NVMBLOCKID_CAN_INPUT_SIGNALS, &NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData},
        {BLOCKADDRESS_RAM_HW_VERSION, NVMBLOCKID_HW_VERSION, &NVP_BLOCK_ID_HW_VERSION_RamBlockData},
        {BLOCKADDRESS_RAM_PCBA_PPN, NVMBLOCKID_PCBA_PPN, &NVP_BLOCK_ID_PCBA_PPN_RamBlockData},
        {BLOCKADDRESS_RAM_HW_PARTNUMBER, NVMBLOCKID_HW_PARTNUMBER, &NVP_BLOCK_ID_HW_PARTNUMBER_RamBlockData}
        };

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/
#define DCM_START_SEC_CALLOUT_CODE
#include "MemMap.h"

/**********************************************************************************************************************
  PART 1 - STATIC PART
   These Callouts are announced within Dcm_Core.h.
   The existence is configuration specific
**********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Confirmation(Dcm_IdContextType idContext
                                             ,PduIdType dcmRxPduId
                                             ,Dcm_ConfirmationStatusType status)
{
}

FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestTransferExit(
  Dcm_OpStatusType OpStatus,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) transferRequestParameterRecord,
  uint32 transferRequestParameterRecordSize,
  P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) transferResponseParameterRecord,
  P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) transferResponseParameterRecordSize,
  Dcm_NegativeResponseCodePtrType ErrorCode
  )
{
    return DCM_E_OK;
}

FUNC(Dcm_ReturnWriteMemoryType, DCM_CALLOUT_CODE) Dcm_ProcessTransferDataWrite(
  Dcm_OpStatusType OpStatus,
  uint8  MemoryIdentifier,
  uint32 MemoryAddress,
  uint32 MemorySize,
  P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) MemoryData,
  Dcm_NegativeResponseCodePtrType ErrorCode
  )
{
    return DCM_E_OK;
}

FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ProcessRequestDownload(
  Dcm_OpStatusType OpStatus,
  uint8  DataFormatIdentifier,
  uint8  MemoryIdentifier,
  uint32 MemoryAddress,
  uint32 MemorySize,
  P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) BlockLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  )
{
    return DCM_E_OK;
}

FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DiagnosticService_0x29_0x04(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode)
{
  return E_NOT_OK;
}

#if (DCM_DIAG_JUMPTOFBL_ENABLED   == STD_ON) || \
    (DCM_DIAG_JUMPFROMFBL_ENABLED == STD_ON)
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SetProgConditions(Dcm_ProgConditionsPtrType progConditions)
{
  Std_ReturnType u8ProgrammingOK;
  /* This Callout is called during first call of Dcm_Mainfunction().
     If it returns DCM_E_NOT_OK, a Det-Error would be hit (0x35,0x00,0xf0,0x06) */
  /* Write magic flag for boot manager */

  /*Check for programming preconditions*/
  u8ProgrammingOK = DIA_runCheckProgrammingPreconditions();

  if( (DCM_E_OK == u8ProgrammingOK) && (progConditions->ReprogrammingRequest == TRUE))
  {
    FblBmMagicFlag[0] = 0x50u;
    FblBmMagicFlag[1] = 0x72u;
    FblBmMagicFlag[2] = 0x6Fu;
    FblBmMagicFlag[3] = 0x67u;
    FblBmMagicFlag[4] = 0x53u;
    FblBmMagicFlag[5] = 0x69u;
    FblBmMagicFlag[6] = 0x67u;
    FblBmMagicFlag[7] = 0x6Eu;

    VStdMemCpy(&DcmProgConditions, progConditions,sizeof(progConditions));
  }

  return u8ProgrammingOK;
}
#endif

#if (DCM_DIAG_JUMPFROMFBL_ENABLED == STD_ON)
FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions(Dcm_ProgConditionsPtrType progConditions)
{
  return DCM_E_NOT_OK;
}
#endif

#if (DCM_DCM_AR_VERSION >= DCM_DCM_AR_VERSION_422)
# if (DCM_SVC_23_SUPPORT_ENABLED == STD_ON)
FUNC(Dcm_ReturnReadMemoryType, DCM_CALLOUT_CODE) Dcm_ReadMemory(Dcm_OpStatusType OpStatus
                                                               ,uint8  MemoryIdentifier
                                                               ,uint32 MemoryAddress
                                                               ,uint32 MemorySize
                                                               ,Dcm_MsgType MemoryData
                                                               ,Dcm_NegativeResponseCodePtrType ErrorCode)
{
  Std_ReturnType ret = E_NOT_OK;
  uint32 *u32AddressToCopyFrom;
  u32AddressToCopyFrom = MemoryAddress;

  if (DCM_RAM_ADDRESS_MAX_SIZE >= MemorySize)
  {
    if (DCM_RAM_ADDRESS_END >= MemoryAddress + MemorySize)
    {
      VStdMemCpy(MemoryData, u32AddressToCopyFrom, MemorySize);

      ret = E_OK;
    }
    else
    {
      ret = DCM_READ_WRITE_RSLT_FAILED;
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
  }
  else
  {
    ret = DCM_READ_WRITE_RSLT_FAILED;
    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }

  return ret;
}
#endif

# if (DCM_SVC_3D_SUPPORT_ENABLED == STD_ON)
FUNC(Dcm_ReturnWriteMemoryType, DCM_CALLOUT_CODE) Dcm_WriteMemory(Dcm_OpStatusType OpStatus
                                                                 ,uint8  MemoryIdentifier
                                                                 ,uint32 MemoryAddress
                                                                 ,uint32 MemorySize
                                                                 ,Dcm_MsgType MemoryData
                                                                 ,Dcm_NegativeResponseCodePtrType ErrorCode)
{
   Std_ReturnType ret = E_NOT_OK;
   uint32 *u32AddressToCopyFrom;
   u32AddressToCopyFrom = MemoryAddress;

   if (DCM_RAM_EEPROM_ALIAS_ADDRESS_BEGIN <= MemoryAddress)
   {
      for (int i = 0; i < DCM_RAM_EEPROM_ALIAS_BLOCK_NRS; i++)
      {
         if (EEPROM_Alias_LookUpTable[i].EEPROM_Alias == MemoryAddress)
         {
            NvM_WriteBlock(EEPROM_Alias_LookUpTable[i].NVM_Block_Id, EEPROM_Alias_LookUpTable[i].RAM_Mirror_Block_Address);

            ret = E_OK;

            break;
         }
         else
         {
            ret = DCM_READ_WRITE_RSLT_FAILED;
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
         }
      }
   }
   else if (DCM_RAM_ADDRESS_MAX_SIZE >= MemorySize)
   {
      if (DCM_RAM_ADDRESS_END >= MemoryAddress + MemorySize)
      {
         VStdMemCpy(u32AddressToCopyFrom, MemoryData, MemorySize);

         ret = E_OK;
      }
      else
      {
         ret = DCM_READ_WRITE_RSLT_FAILED;
         *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
   }
   else
   {
      ret = DCM_READ_WRITE_RSLT_FAILED;
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
   }

   return ret;
}
# endif

#else
# if (DCM_SVC_23_SUPPORT_ENABLED == STD_ON)
FUNC(Dcm_ReturnReadMemoryType, DCM_CALLOUT_CODE) Dcm_ReadMemory(Dcm_OpStatusType OpStatus
                                                               ,uint8  MemoryIdentifier
                                                               ,uint32 MemoryAddress
                                                               ,uint32 MemorySize
                                                               ,Dcm_MsgType MemoryData)
{
  return DCM_E_NOT_OK;
}
# endif

# if (DCM_SVC_3D_SUPPORT_ENABLED == STD_ON)
FUNC(Dcm_ReturnWriteMemoryType, DCM_CALLOUT_CODE) Dcm_WriteMemory(Dcm_OpStatusType OpStatus
                                                                 ,uint8  MemoryIdentifier
                                                                 ,uint32 MemoryAddress
                                                                 ,uint32 MemorySize
                                                                 ,Dcm_MsgType MemoryData)
{
  return DCM_E_NOT_OK;
}
# endif
#endif /*DCM_DCM_AR_VERSION_422*/


/* Dcm Dummy Services */
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmDummyServices_RequestDownload(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext)
{
  return E_OK;	
}

FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmDummyServices_TransferData(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext)
{
  return E_OK;	
}

FUNC(Std_ReturnType, DCM_CALLOUT_CODE) DcmDummyServices_TransferExit(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext)
{
  return E_OK;	
}

/**********************************************************************************************************************
  PART 2 - DYNAMIC PART
   These Callouts are announced within Dcm_Lcfg.h.
   The existence is configuration specific
**********************************************************************************************************************/
#if(1)
FUNC(Std_ReturnType, DCM_CALLOUT_CODE)Dcm_DiagnosticService_0x37(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode)
{
  return E_OK;
}

FUNC(Std_ReturnType, DCM_CALLOUT_CODE)Dcm_DiagnosticService_0x36(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode)
{
  return E_OK;
}

FUNC(Std_ReturnType, DCM_CALLOUT_CODE)Dcm_DiagnosticService_0x34(Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode)
{
  return E_OK;
}
#endif

/**********************************************************************************************************************
  END of User implementation area
**********************************************************************************************************************/
#define DCM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

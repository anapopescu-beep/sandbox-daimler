/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: NvM
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: NvM_Cfg.c
 *   Generation Time: 2023-08-16 13:53:47
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/


/* PRQA S 5087 MemMap */ /* MD_MSR_MemMap */
    
/**********************************************************************************************************************
 *  MODULE SWITCH
 *********************************************************************************************************************/
/* this switch enables the header file(s) to hide some parts. */
#define NVM_CFG_SOURCE

/* multiple inclusion protection */
#define NVM_H_

/* Required for RTE ROM block definitions */
#define RTE_MICROSAR_PIM_EXPORT

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/* This tag will only be replaced, if one or more callbacks via Service Ports had been configured */


/**********************************************************************************************************************
 *  MODULE HEADER INCLUDES
 *********************************************************************************************************************/
/* only includes the public part of config */
#include "NvM_Cfg.h"
#include "NvM_PrivateCfg.h"



/**********************************************************************************************************************
 *  VERSION CHECKS
 *********************************************************************************************************************/
#if ((NVM_CFG_MAJOR_VERSION != (9u)) \
        || (NVM_CFG_MINOR_VERSION != (0u)))
# error "Version numbers of NvM_Cfg.c and NvM_Cfg.h are inconsistent!"
#endif

/* include list of the callback definitions */
#include "Crypto_30_LibCv.h" 
#include "vHsm_Cfg.h" 


/* include configured file declaring or defining resource (un)locking service(s) */
#include "SchM_NvM.h"

/**********************************************************************************************************************
 *  PUBLIC CONSTANTS
 *********************************************************************************************************************/
#define NVM_START_SEC_CONST_16
#include "NvM_MemMap.h"

/* maximum number of bytes to be processed in one crc calculation step */
CONST(uint16, NVM_CONFIG_CONST) NvM_NoOfCrcBytes_u16 = 64u;

/* constant holding Crc queue size value */
CONST(uint16, NVM_PRIVATE_CONST) NvM_CrcQueueSize_u16 = NVM_TOTAL_NUM_OF_NVRAM_BLOCKS;

#define NVM_STOP_SEC_CONST_16
#include "NvM_MemMap.h"

/* 8Bit Data section containing the data integrity buffers, as well as the internal buffer */
#define NVM_START_SEC_VAR_NO_INIT_8
#include "NvM_MemMap.h"

static VAR(uint8, NVM_PRIVATE_DATA) NvMConfigBlock_RamBlock_au8[4u];

#if ((NVM_DATA_INTEGRITY_INT_BUFFER == STD_ON) || (NVM_REPAIR_REDUNDANT_BLOCKS_API == STD_ON))
static VAR(uint8, NVM_PRIVATE_DATA) Keys_Immediate_Crc[4u]; 
static VAR(uint8, NVM_PRIVATE_DATA) Keys_Immediate_RootCert_Crc[4u]; 
static VAR(uint8, NVM_PRIVATE_DATA) Keys_Deferred_Crc[4u]; 
static VAR(uint8, NVM_PRIVATE_DATA) Keys_Immediate_BackendCert_Crc[4u]; 
static VAR(uint8, NVM_PRIVATE_DATA) Keys_Deferred_SecOC_Crc[4u]; 
static VAR(uint8, NVM_PRIVATE_DATA) Keys_Deferred_SharedSecretHash_Crc[4u]; 
static VAR(uint8, NVM_PRIVATE_DATA) Keys_Deferred_TrustModel_NoRoot_Crc[4u]; 
static VAR(uint8, NVM_PRIVATE_DATA) Keys_Deferred_TrustModel_Root_Crc[4u]; 



/* create the internal buffer of size NVM_INTERNAL_BUFFER_LENGTH */
VAR(uint8, NVM_PRIVATE_DATA) NvM_InternalBuffer_au8[NVM_INTERNAL_BUFFER_LENGTH]; /* PRQA S 1533 */ /* MD_NvM_Cfg_8.9_InternalBuffer */
#endif





#define NVM_STOP_SEC_VAR_NO_INIT_8
#include "NvM_MemMap.h"

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

CONST(NvM_BlockIdType, NVM_PUBLIC_CONST) NvM_NoOfBlockIds_t = NVM_TOTAL_NUM_OF_NVRAM_BLOCKS;

CONST(NvM_CompiledConfigIdType, NVM_PUBLIC_CONST) NvM_CompiledConfigId_t = {(uint16)NVM_COMPILED_CONFIG_ID}; /* PRQA S 0759 */ /* MD_MSR_Union */
 

 
/* block descriptor table that holds the static configuration parameters of the RAM, ROM and NVBlocks.
* This table has to be adjusted according to the configuration of the NVManager.
*/

CONST(NvM_BlockDescriptorType, NVM_CONFIG_CONST) NvM_BlockDescriptorTable_at[NVM_TOTAL_NUM_OF_NVRAM_BLOCKS] =
    {
      { /*  MultiBlockRequest  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
        { 0u } /*  Flags  */ , 
        0x0001u /*  NV block Base number (defined by FEE/EA)  */ , 
        0U /*  NvMNvBlockLength  */ , 
        0U /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        0u /*  NvBlockCount  */ , 
        255u /*  NvMBlockJobPriority  */ , 
        0u /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_NATIVE /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_DATA_INTEGRITY_OFF /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  NvMConfigBlock  */ 
        (NvM_RamAddressType)NvMConfigBlock_RamBlock_au8 /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        NULL_PTR /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        NULL_PTR /*  NvMReadRamBlockFromNvCallback  */ , 
        NULL_PTR /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        NULL_PTR /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_OFF, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0040u /*  NV block Base number (defined by FEE/EA)  */ , 
        2u /*  NvMNvBlockLength  */ , 
        2u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_16_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  Keys_Immediate  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Immediate /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Immediate /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Immediate /*  NvMReadRamBlockFromNvCallback  */ , 
        Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Immediate /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Keys_Immediate_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0020u /*  NV block Base number (defined by FEE/EA)  */ , 
        280u /*  NvMNvBlockLength  */ , 
        280u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_32_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  Keys_Immediate_RootCert  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Immediate_RootCert /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Immediate_RootCert /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Immediate_RootCert /*  NvMReadRamBlockFromNvCallback  */ , 
        Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Immediate_RootCert /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Keys_Immediate_RootCert_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00E0u /*  NV block Base number (defined by FEE/EA)  */ , 
        922u /*  NvMNvBlockLength  */ , 
        922u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_32_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  Keys_Deferred  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred /*  NvMReadRamBlockFromNvCallback  */ , 
        Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Keys_Deferred_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0010u /*  NV block Base number (defined by FEE/EA)  */ , 
        70u /*  NvMNvBlockLength  */ , 
        70u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_32_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  Keys_Immediate_BackendCert  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Immediate_BackendCert /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Immediate_BackendCert /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Immediate_BackendCert /*  NvMReadRamBlockFromNvCallback  */ , 
        Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Immediate_BackendCert /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Keys_Immediate_BackendCert_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_OFF, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_OFF, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00F0u /*  NV block Base number (defined by FEE/EA)  */ , 
        922u /*  NvMNvBlockLength  */ , 
        922u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_32_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  Keys_Deferred_SecOC  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred_SecOC /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred_SecOC /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred_SecOC /*  NvMReadRamBlockFromNvCallback  */ , 
        Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred_SecOC /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Keys_Deferred_SecOC_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00C0u /*  NV block Base number (defined by FEE/EA)  */ , 
        400u /*  NvMNvBlockLength  */ , 
        400u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_32_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  Keys_Deferred_SharedSecretHash  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred_SharedSecretHash /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred_SharedSecretHash /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred_SharedSecretHash /*  NvMReadRamBlockFromNvCallback  */ , 
        Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred_SharedSecretHash /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Keys_Deferred_SharedSecretHash_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x00D0u /*  NV block Base number (defined by FEE/EA)  */ , 
        16u /*  NvMNvBlockLength  */ , 
        16u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_32_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  Keys_Deferred_TrustModel_NoRoot  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred_TrustModel_NoRoot /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred_TrustModel_NoRoot /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred_TrustModel_NoRoot /*  NvMReadRamBlockFromNvCallback  */ , 
        Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred_TrustModel_NoRoot /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Keys_Deferred_TrustModel_NoRoot_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0100u /*  NV block Base number (defined by FEE/EA)  */ , 
        3018u /*  NvMNvBlockLength  */ , 
        3018u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_32_ON /*  NvMBlockDataIntegrityType  */ 
      }, 
      { /*  Keys_Deferred_TrustModel_Root  */ 
        NULL_PTR /*  NvMRamBlockDataAddress  */ , 
        NULL_PTR /*  NvMRomBlockDataAddress  */ , 
        Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred_TrustModel_Root /*  NvMInitBlockCallback  */ , 
        NULL_PTR /*  NvMInitBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred_TrustModel_Root /*  NvMSingleBlockCallback  */ , 
        NULL_PTR /*  NvMSingleBlockCallback (extended)  */ , 
        Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred_TrustModel_Root /*  NvMReadRamBlockFromNvCallback  */ , 
        Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred_TrustModel_Root /*  NvMWriteRamBlockToNvCallback  */ , 
        NULL_PTR /*  NvMBlockPreWriteTransformCallback  */ , 
        NULL_PTR /*  NvMBlockPostReadTransformCallback  */ , 
        Keys_Deferred_TrustModel_Root_Crc /*  RamBlockDataIntegrity data buffer (defined by NvM)  */ , 
        NULL_PTR /*  CRCCompMechanism CRC data (defined by NvM)  */ , 
                {
          NVM_CALC_RAM_BLOCK_CRC_OFF, 
          NVM_BLOCK_WRITE_PROT_OFF, 
          NVM_BLOCK_WRITE_BLOCK_ONCE_OFF, 
          NVM_RESISTANT_TO_CHANGED_SW_ON, 
          NVM_SELECT_BLOCK_FOR_READALL_ON, 
          NVM_SELECT_BLOCK_FOR_WRITEALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_READALL_ON, 
          NVM_INVOKE_CALLBACKS_FOR_WRITEALL_ON, 
          NVM_BLOCK_USE_SET_RAM_BLOCK_STATUS_ON, 
          NVM_BLOCK_CHECK_LOSS_OF_REDUNDANCY_OFF, 
          NVM_BLOCK_NOTIFY_BSWM_OFF
        } /*  Flags  */ , 
        0x0110u /*  NV block Base number (defined by FEE/EA)  */ , 
        1010u /*  NvMNvBlockLength  */ , 
        1010u /*  NvMNvBlockNVRAMDataLength  */ , 
        0u /*  NvCryptoReference  */ , 
        0u /*  NvMacSize  */ , 
        0u /*  NvMacReference  */ , 
        2u /*  NvBlockCount  */ , 
        127u /*  NvMBlockJobPriority  */ , 
        MEMIF_Fee /*  Device Id (defined by MemIf)  */ , 
        NVM_BLOCK_REDUNDANT /*  NvMBlockManagementType  */ , 
        NVM_BLOCK_CRC_32_ON /*  NvMBlockDataIntegrityType  */ 
      }
    };

/* Permanent RAM and ROM block length checks - compile time (only available for blocks with enabled length check */

/* PRQA S 3494, 3213, 1755 BlockLengthChecks */ /* MD_NvM_Cfg_14.3, MD_NvM_Cfg_2.4 */

/* How does it work:
 * data length = sizeof(ramBlock - CrcLength 
 *     - CRC internal buffer enabled: CRC length == 0, RAM blocks store only data, CRC is handles internally
 *     - CRC internal buffer disabled: CRC length is the number of CRC bytes, for blocks without CRC the length == 0
 *     - for ROM blocks the CRC does not matter
 * Data length has to be > or < or == to configured NvM block length, depending on configuration (see above). 
 * In case the lengths do not match a bitfield with length -1 will be created and shall cause a compiler error.
 * The compiler error shall mark the line with invalid bitfield (bitfield length == -1) - the line includes all required information:
 *     - Block_ + NvM block name
 *     - length error description
 *     - RAM block name, CRC length and configured NvM block length
 */

typedef unsigned int NvM_LengthCheck;
 
/* Block Length Check and Automatic Block Length enabled: error if sizeof RAM block is greater than the configured block length */
#define SizeOfRamBlockGreaterThanConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) > (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check and Strict Length Check enabled: error if the sizeof RAM block does not match the configured block length */
#define SizeOfRamBlockDoesNotMatchConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) != (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check enabled and Strict Length Check disabled: error if the sizeof RAM block is less than the configured block length */
#define SizeOfRamBlockLessThanConfiguredLength(ramBlock, crcLength, blockLength) (((sizeof(ramBlock) - (crcLength)) < (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* RAM block length checks */



/* Block Length Check and Automatic Block Length enabled: error if sizeof ROM block is less than sizeof RAM block */
#define SizeOfRomBlockLessThanSizeOfRamBlock(romBlock, ramBlock) ((sizeof(romBlock) < sizeof(ramBlock)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check and Strict Length Check enabled: error if the sizeof ROM block does not match the configured block length */
#define SizeOfRomBlockDoesNotMatchConfiguredLength(romBlock, blockLength) ((sizeof(romBlock) != (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Block Length Check enabled, Strict Length disabled: error if the sizeof ROM block is less than the configured block length */
#define SizeOfRomBlockLessThanConfiguredLength(romBlock, blockLength) ((sizeof(romBlock) < (blockLength)) ? -1 : 1) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* ROM block length checks */



/* PRQA L:BlockLengthChecks */

/* Permanent RAM and ROM block length checks - END */

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h"

#if(NVM_API_CONFIG_CLASS != NVM_API_CONFIG_CLASS_1)
/* Job Queue used for normal and high prio jobs */
VAR(NvM_QueueEntryType, NVM_PRIVATE_DATA) NvM_JobQueue_at[NVM_SIZE_STANDARD_JOB_QUEUE + NVM_SIZE_IMMEDIATE_JOB_QUEUE];
#endif

#define NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

/**********************************************************************************************************************
*  NvM_EnterCriticalSection
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 enter SchM exclusive area for NvM 
 * \endinternal
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_EnterCriticalSection(void)
{
  /* do what ever was defined to do for locking the resources */
  SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
}

/**********************************************************************************************************************
*  NvM_ExitCriticalSection
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 exit SchM exclusive area for NvM 
 * \endinternal
 */
FUNC(void, NVM_PRIVATE_CODE) NvM_ExitCriticalSection(void)
{
  /* do what ever was defined to do for unlocking the resources */
  SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
}

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeMultiBlockMode(serv, res)  /*  if NvMBswMMultiBlockJobStatusInformation is TRUE  */

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeMultiCbk(serv, res)   /*  if Multi Block Callback is configured  */

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define NvM_invokeDetectedLossOfRedundancyCallback(blockId) NVM_DUMMY_STATEMENT((blockId))

/**********************************************************************************************************************
*  NvM_MultiBlockCbk
**********************************************************************************************************************/
/*!
 * \internal
 *  - #10 invoke the BSWM notification if any is configured
 *  - #20 in case the given job result isn't set to pending, invoke the multi block job end notification
 * \endinternal
 */
/* PRQA S 3206 1 */ /* MD_NvM_Cfg_2.7 */
FUNC(void, NVM_PRIVATE_CODE) NvM_MultiBlockCbk(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
  /* The complete function body is designed to be optimized away by the compiler, if it is not needed    *
   * If the used macro is empty, the compiler may decide to remove code because it would contain         *
   * empty execution blocks (it does not matter whether conditions were TRUE or FALSE                    */
  NvM_invokeMultiBlockMode(ServiceId, JobResult);

  if(JobResult != NVM_REQ_PENDING)
  {
    NvM_invokeMultiCbk(ServiceId, JobResult);
  }   
}

/**********************************************************************************************************************
*  NvM_NotifyLossOfRedundancy
**********************************************************************************************************************/
/*!
 * \internal
 *  - invoke the notification callback if any is configured
 * \endinternal
 */
/* PRQA S 3206 1 */ /* MD_NvM_Cfg_2.7 */
FUNC(void, NVM_PRIVATE_CODE) NvM_NotifyLossOfRedundancy(NvM_BlockIdType BlockId)
{
  NvM_invokeDetectedLossOfRedundancyCallback(BlockId);
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/* PRQA L:MemMap */

/* Justification for module specific MISRA deviations:

MD_NvM_Cfg_2.4
Reason: NvM provides compile time block length checks via structures with bitfields with positive or negative length -
        the negative length lead to compiler errors. It is possible to use == or even >= check, if only one is used,
        the other one will never be used. The macros are always available. The created structures will never be used by NvM.
Risk: No risk.
Prevention: No prevention.

MD_NvM_Cfg_2.7:
Reason: The function NvM_MultiBlockCbk gets all needed parameters to invoke the BSWM and multi block job end callback.
        If both are disabled, the function is empty and does nothing - the passed parameters remain unused.
Risk: No risk.
Prevention: No prevention.

MD_NvM_Cfg_8.9_InternalBuffer:
Reason: NvM uses an internal buffer for explicit synchronization, in internal CRC buffer use case and for repair redundant blocks.
        Depending on configuration all, one or even none of the uses is enabled - therefore sometimes the internal buffer is
        used only once.
Risk: No risk.
Prevention: No prevention.

MD_NvM_Cfg_8.11:
Reason: Array of unknown size is used in order to reduce dependencies.
Risk: In case the array size shall be determined it would be incorrect.
Prevention: No prevention.

MD_NvM_Cfg_14.3:
Reason: NvM provides compile time block length checks via bitfields with positive or negative length - the negative length
        lead to compiler errors. With valid configuration (all block length are configured correctly), all checks are false.
Risk: No risk.
Prevention: No prevention. If needed the compile time checks can be disabled via configuration.

 */

/**********************************************************************************************************************
 *  END OF FILE: NvM_Cfg.c
 *********************************************************************************************************************/



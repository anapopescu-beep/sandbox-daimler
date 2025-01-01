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
 *            Module: WrapNv
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WrapNv_Cfg.c
 *   Generation Time: 2024-03-21 19:05:42
 *           Project: CBD2000614_fblbm_Upd - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define WRAPNV_CFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "WrapNv_Cfg.h"
# include "Fls_17_Dmu.h"
# include "Fee.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

# define WRAPNV_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define kEepSizeNVP_BLOCK_ID_HW_PARTNUMBER   0x14u
#define kEepSizeNVP_BLOCK_ID_HW_VERSION      0x03u
#define kEepSizeNvMBlockDescriptor_FblMetaData 0x91u
#define kEepSizeNvMBlockDescriptor_IDEcuLocation 0x03u
#define kEepSizeNvMBlockDescriptor_SecAccessDelayFlag 0x01u
#define kEepSizeNvMBlockDescriptor_VerificationKey 0x21u

/** Default value arrays ****************************************************** */
static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NVP_BLOCK_ID_HW_PARTNUMBER[kEepSizeNVP_BLOCK_ID_HW_PARTNUMBER] =
         {
             /* NVP_BLOCK_ID_HW_PARTNUMBER */ 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NVP_BLOCK_ID_HW_VERSION[kEepSizeNVP_BLOCK_ID_HW_VERSION] =
         {
             /* NVP_BLOCK_ID_HW_VERSION */ 0x17, 0x11, 0x00
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_FblMetaData[kEepSizeNvMBlockDescriptor_FblMetaData] =
         {
             /* FpStatusInfo */ 0xFF,
             /* Fingerprint */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
             /* ProgAttempts */ 0xFF, 0xFF,
             /* CRCTotal */ 0xFF, 0xFF, 0xFF, 0xFF,
             /* SwVersion */ 0xFF, 0xFF, 0xFF,
             /* SwPartNumber */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
             /* SwSupplierInformation */ 0xFF, 0xFF,
             /* MinimumSoftwareVersion */ 0xFF, 0xFF, 0xFF,
             /* Cmac */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
             /* CRCWritten */ 0xFF, 0xFF, 0xFF, 0xFF,
             /* SegmentCount */ 0xFF,
             /* SegmentAddrList */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
             /* SegmentLengthList */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_IDEcuLocation[kEepSizeNvMBlockDescriptor_IDEcuLocation] =
         {
             /* IdEcuLocation */ 0x9C, 0xFF, 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_SecAccessDelayFlag[kEepSizeNvMBlockDescriptor_SecAccessDelayFlag] =
         {
             /* SecAccessDelayFlag */ 0xFF
         };

static CONST(uint8, WRAPNV_CONST) kWrapNvDefaultValue_NvMBlockDescriptor_VerificationKey[kEepSizeNvMBlockDescriptor_VerificationKey] =
         {
             /* VerificationKeyState */ 0xFF,
             /* VerificationKeyValue */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
         };


/** Block table *************************************************************** */
static CONST(tWrapNvBlockTbl, WRAPNV_CONST) kWrapNvBlockTbl[kWrapNvNrOfBlock] =
{
   /** NVP_BLOCK_ID_HW_PARTNUMBER */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      FeeConf_FeeBlockConfiguration_FeeNVP_BLOCK_ID_HW_PARTNUMBER,
      kEepSizeNVP_BLOCK_ID_HW_PARTNUMBER,
      WRAPNV_DATASET_NVP_BLOCK_ID_HW_PARTNUMBER,
      kWrapNvDefaultValue_NVP_BLOCK_ID_HW_PARTNUMBER
   },

   /** NVP_BLOCK_ID_HW_VERSION */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      FeeConf_FeeBlockConfiguration_FeeNVP_BLOCK_ID_HW_VERSION,
      kEepSizeNVP_BLOCK_ID_HW_VERSION,
      WRAPNV_DATASET_NVP_BLOCK_ID_HW_VERSION,
      kWrapNvDefaultValue_NVP_BLOCK_ID_HW_VERSION
   },

   /** NvMBlockDescriptor_FblMetaData */
   {
      WRAPNV_RECORDACCESS_STRUCTURED,
      FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_FblMetaData,
      kEepSizeNvMBlockDescriptor_FblMetaData,
      WRAPNV_DATASET_FBLMETADATA,
      kWrapNvDefaultValue_NvMBlockDescriptor_FblMetaData
   },

   /** NvMBlockDescriptor_IDEcuLocation */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      FeeConf_FeeBlockConfiguration_Fee_NVP_BLOCK_ID_ECU_LOCATION,
      kEepSizeNvMBlockDescriptor_IDEcuLocation,
      WRAPNV_DATASET_IDECULOCATION,
      kWrapNvDefaultValue_NvMBlockDescriptor_IDEcuLocation
   },

   /** NvMBlockDescriptor_SecAccessDelayFlag */
   {
      WRAPNV_RECORDACCESS_SINGLE,
      FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_SecAccessDelayFlag,
      kEepSizeNvMBlockDescriptor_SecAccessDelayFlag,
      WRAPNV_DATASET_SECACCESSDELAYFLAG,
      kWrapNvDefaultValue_NvMBlockDescriptor_SecAccessDelayFlag
   },

   /** NvMBlockDescriptor_VerificationKey */
   {
      WRAPNV_RECORDACCESS_STRUCTURED,
      FeeConf_FeeBlockConfiguration_FeeBlockDescriptor_VerificationKey,
      kEepSizeNvMBlockDescriptor_VerificationKey,
      WRAPNV_DATASET_VERIFICATIONKEY,
      kWrapNvDefaultValue_NvMBlockDescriptor_VerificationKey
   }
};

/** Record table ************************************************************** */
CONST(tWrapNvRecordTbl, WRAPNV_CONST) kWrapNvRecordTbl[kWrapNvNrOfRecord] =
{
   /** NVP_BLOCK_ID_HW_PARTNUMBER */

   /** NVP_BLOCK_ID_HW_PARTNUMBER */
   {  /*  */
      0x00u,
      kEepSizeNVP_BLOCK_ID_HW_PARTNUMBER,
      &kWrapNvBlockTbl[0]
   },

   /** SecAccessDelayFlag */

   /** SecAccessDelayFlag */
   {  /* Security access delay flag */
      0x00u,
      kEepSizeSecAccessDelayFlag,
      &kWrapNvBlockTbl[4]
   },

   /** VerificationKey */

   /** VerificationKeyState */
   {  /* Memory status of verification key value */
      0x00u,
      kEepSizeVerificationKeyState,
      &kWrapNvBlockTbl[5]
   },

   /** VerificationKeyValue */
   {  /* Key value for signature verification */
      0x01u,
      kEepSizeVerificationKeyValue,
      &kWrapNvBlockTbl[5]
   },

   /** FblMetaData */

   /** FpStatusInfo */
   {  /* Fingerprint status information */
      0x00u,
      kEepSizeFpStatusInfo,
      &kWrapNvBlockTbl[2]
   },

   /** Fingerprint */
   {  /* Diagnostic Authentication Certificate ID, programming date */
      0x01u,
      kEepSizeFingerprint,
      &kWrapNvBlockTbl[2]
   },

   /** ProgAttempts */
   {  /* Programming attempt counter */
      0x14u,
      kEepSizeProgAttempts,
      &kWrapNvBlockTbl[2]
   },

   /** CRCTotal */
   {  /* CRC total of logical block */
      0x16u,
      kEepSizeCRCTotal,
      &kWrapNvBlockTbl[2]
   },

   /** SwVersion */
   {  /* Software version */
      0x1Au,
      kEepSizeSwVersion,
      &kWrapNvBlockTbl[2]
   },

   /** SwPartNumber */
   {  /* Software part number */
      0x1Du,
      kEepSizeSwPartNumber,
      &kWrapNvBlockTbl[2]
   },

   /** SwSupplierInformation */
   {  /* Software supplier information */
      0x27u,
      kEepSizeSwSupplierInformation,
      &kWrapNvBlockTbl[2]
   },

   /** MinimumSoftwareVersion */
   {  /* The minimum software version is used to prevent the downgrade to an older version */
      0x29u,
      kEepSizeMinimumSoftwareVersion,
      &kWrapNvBlockTbl[2]
   },

   /** Cmac */
   {  /* Avoid manipulation of download software in case of OFR-Light */
      0x2Cu,
      kEepSizeCmac,
      &kWrapNvBlockTbl[2]
   },

   /** CRCWritten */
   {  /* CRC32 value over written data in current logical block */
      0x3Cu,
      kEepSizeCRCWritten,
      &kWrapNvBlockTbl[2]
   },

   /** SegmentCount */
   {  /* Number of entries in segment list */
      0x40u,
      kEepSizeSegmentCount,
      &kWrapNvBlockTbl[2]
   },

   /** SegmentAddrList */
   {  /* List of segment start addresses */
      0x41u,
      kEepSizeSegmentAddrList,
      &kWrapNvBlockTbl[2]
   },

   /** SegmentLengthList */
   {  /* List of segment lengths */
      0x69u,
      kEepSizeSegmentLengthList,
      &kWrapNvBlockTbl[2]
   },

   /** IdEcuLocation */

   /** IdEcuLocation */
   {  /*  */
      0x00u,
      kEepSizeIdEcuLocation,
      &kWrapNvBlockTbl[3]
   },

   /** NVP_BLOCK_ID_HW_VERSION */

   /** NVP_BLOCK_ID_HW_VERSION */
   {  /*  */
      0x00u,
      kEepSizeNVP_BLOCK_ID_HW_VERSION,
      &kWrapNvBlockTbl[1]
   }
};


# define WRAPNV_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

static VAR(uint8_least, WRAPNV_VAR_NOINIT) callCounter_5_ms;


# define WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
# define WRAPNV_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/** MemDriver function abstraction functions ********************************** */
FUNC(MemIf_StatusType, WRAPNV_CODE) WrapNv_MemDrvGetStatus( void ) {

    return Fee_GetStatus();

}

FUNC(MemIf_JobResultType, WRAPNV_CODE) WrapNv_MemDrvGetJobResult( void ) {

    return Fee_GetJobResult();

}

FUNC(Std_ReturnType, WRAPNV_CODE) WrapNv_MemDrvRead( uint16 BlockNumber, uint16 BlockOffset, uint8 *DataBufferPtr, uint16 Length ) {

    return Fee_Read(BlockNumber, BlockOffset, DataBufferPtr, Length);

}

FUNC(Std_ReturnType, WRAPNV_CODE) WrapNv_MemDrvWrite( uint16 BlockNumber, uint8 *DataBufferPtr ) {

    return Fee_Write(BlockNumber, DataBufferPtr);

}

FUNC(Std_ReturnType, WRAPNV_CODE) WrapNv_MemDrvInvalidateBlock( uint16 BlockNumber ) {

    return Fee_InvalidateBlock(BlockNumber);

}

FUNC(void, WRAPNV_CODE) WrapNv_MemDrvCancel( void ) {

    Fee_Cancel();

}

/** Internal MainFunction polling idle function ******************************* */
FUNC(void, WRAPNV_CODE) WrapNv_PollMainFunctionsInternalIdle( void ) {

   /** Empty method stub */

}

/** Internal MainFunction polling timer function ****************************** */
FUNC(void, WRAPNV_CODE) WrapNv_PollMainFunctionsInternalTimer( void ) {

   /** Increment call counter */
   callCounter_5_ms++;

   /** Call resp. MainFunctions if counter expired */
   if (callCounter_5_ms >= 5u) {
      Fls_17_Dmu_MainFunction();
      Fee_MainFunction();
      callCounter_5_ms = 0u;
   }

}

/** Init config function ****************************************************** */
FUNC(void, WRAPNV_CODE) WrapNv_InitConfig( void ) {

   /** Initialize call counter for polling main functions */
   callCounter_5_ms = 0u;

}

# define WRAPNV_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
  END OF FILE: WrapNv_Cfg.c
**********************************************************************************************************************/



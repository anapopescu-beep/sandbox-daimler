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
 *              File: WrapNv_Cfg.h
 *   Generation Time: 2024-03-21 18:53:13
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (WRAPNV_CFG_H)
# define WRAPNV_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Std_Types.h"
# include "MemIf_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/*******************************************************************************************
 *                                    NvMBlock              Offset              DESCRIPTION
 *   
 *   Memory Layout
 *   |
 *   +-- NVP_BLOCK_ID_HW_PARTNUMBER   NVP_BLOCK_ID_HW_PARTNUMBER 0x00000000
 *   |
 *   +-- SecAccessDelayFlag           NvMBlockDescriptor_SecAccessDelayFlag 0x00000000 Security access delay flag
 *   |
 *   +-- VerificationKey                                                        Key for signature verification
 *   |   |
 *   |   +-- VerificationKeyState     NvMBlockDescriptor_VerificationKey 0x00000000 Memory status of verification key value
 *   |   |
 *   |   +-- VerificationKeyValue     NvMBlockDescriptor_VerificationKey 0x00000001 Key value for signature verification
 *   |
 *   +-- 3 x FblMetaData                                                        FBL meta data - 2 needed per logical block
 *   |   |
 *   |   +-- FpStatusInfo             NvMBlockDescriptor_FblMetaData 0x00000000 Fingerprint status information
 *   |   |
 *   |   +-- Fingerprint              NvMBlockDescriptor_FblMetaData 0x00000001 Diagnostic Authentication Certificate ID, programming date
 *   |   |
 *   |   +-- ProgAttempts             NvMBlockDescriptor_FblMetaData 0x00000014 Programming attempt counter
 *   |   |
 *   |   +-- CRCTotal                 NvMBlockDescriptor_FblMetaData 0x00000016 CRC total of logical block
 *   |   |
 *   |   +-- SwVersion                NvMBlockDescriptor_FblMetaData 0x0000001A Software version
 *   |   |
 *   |   +-- SwPartNumber             NvMBlockDescriptor_FblMetaData 0x0000001D Software part number
 *   |   |
 *   |   +-- SwSupplierInformation    NvMBlockDescriptor_FblMetaData 0x00000027 Software supplier information
 *   |   |
 *   |   +-- MinimumSoftwareVersion   NvMBlockDescriptor_FblMetaData 0x00000029 The minimum software version is used to prevent the downgrade to an older version
 *   |   |
 *   |   +-- Cmac                     NvMBlockDescriptor_FblMetaData 0x0000002C Avoid manipulation of download software in case of OFR-Light
 *   |   |
 *   |   +-- CRCWritten               NvMBlockDescriptor_FblMetaData 0x0000003C CRC32 value over written data in current logical block
 *   |   |
 *   |   +-- SegmentCount             NvMBlockDescriptor_FblMetaData 0x00000040 Number of entries in segment list
 *   |   |
 *   |   +-- SegmentAddrList          NvMBlockDescriptor_FblMetaData 0x00000041 List of segment start addresses
 *   |   |
 *   |   +-- SegmentLengthList        NvMBlockDescriptor_FblMetaData 0x00000069 List of segment lengths
 *   |
 *   +-- IdEcuLocation                NvMBlockDescriptor_IDEcuLocation 0x00000000
 *   |
 *   +-- NVP_BLOCK_ID_HW_VERSION      NVP_BLOCK_ID_HW_VERSION 0x00000000
 ******************************************************************************************/

/** General defines *********************************************************** */
#define WRAPNV_USECASE_FEE
#define WRAPNV_MAINFUNCTION_POLLING          STD_ON
#define WRAPNV_DEV_ERROR_REPORT              STD_ON

/** ID defines **************************************************************** */
/** NVP_BLOCK_ID_HW_PARTNUMBER */
#define WRAPNV_DATASET_NVP_BLOCK_ID_HW_PARTNUMBER 0x01u
#define WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_PARTNUMBER 0x00u

/** SecAccessDelayFlag */
#define WRAPNV_DATASET_SECACCESSDELAYFLAG    0x01u
#define WRAPNV_RECORD_ID_SECACCESSDELAYFLAG  0x01u

/** VerificationKey */
#define WRAPNV_DATASET_VERIFICATIONKEY       0x01u
#define WRAPNV_RECORD_ID_VERIFICATIONKEYSTATE 0x02u
#define WRAPNV_RECORD_ID_VERIFICATIONKEYVALUE 0x03u

/** FblMetaData */
#define WRAPNV_DATASET_FBLMETADATA           0x03u
#define WRAPNV_RECORD_ID_FPSTATUSINFO        0x04u
#define WRAPNV_RECORD_ID_FINGERPRINT         0x05u
#define WRAPNV_RECORD_ID_PROGATTEMPTS        0x06u
#define WRAPNV_RECORD_ID_CRCTOTAL            0x07u
#define WRAPNV_RECORD_ID_SWVERSION           0x08u
#define WRAPNV_RECORD_ID_SWPARTNUMBER        0x09u
#define WRAPNV_RECORD_ID_SWSUPPLIERINFORMATION 0x0Au
#define WRAPNV_RECORD_ID_MINIMUMSOFTWAREVERSION 0x0Bu
#define WRAPNV_RECORD_ID_CMAC                0x0Cu
#define WRAPNV_RECORD_ID_CRCWRITTEN          0x0Du
#define WRAPNV_RECORD_ID_SEGMENTCOUNT        0x0Eu
#define WRAPNV_RECORD_ID_SEGMENTADDRLIST     0x0Fu
#define WRAPNV_RECORD_ID_SEGMENTLENGTHLIST   0x10u

/** IdEcuLocation */
#define WRAPNV_DATASET_IDECULOCATION         0x01u
#define WRAPNV_RECORD_ID_IDECULOCATION       0x11u

/** NVP_BLOCK_ID_HW_VERSION */
#define WRAPNV_DATASET_NVP_BLOCK_ID_HW_VERSION 0x01u
#define WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_VERSION 0x12u

/** Maximum ID of a DataElement */
#define WRAPNV_RECORD_ID_MAX                 0x12u

/** Maximum NvM Block size */
#define WRAPNV_MAX_BLOCK_LENGTH              0x91u


/** Fee function abstraction prototypes *************************************** */
FUNC(MemIf_StatusType, WRAPNV_CODE) WrapNv_MemDrvGetStatus( void );
FUNC(MemIf_JobResultType, WRAPNV_CODE) WrapNv_MemDrvGetJobResult( void );
FUNC(Std_ReturnType, WRAPNV_CODE) WrapNv_MemDrvRead( uint16 BlockNumber, uint16 BlockOffset, uint8 *DataBufferPtr, uint16 Length );
FUNC(Std_ReturnType, WRAPNV_CODE) WrapNv_MemDrvWrite( uint16 BlockNumber, uint8 *DataBufferPtr );
FUNC(Std_ReturnType, WRAPNV_CODE) WrapNv_MemDrvInvalidateBlock( uint16 BlockNumber );
FUNC(void, WRAPNV_CODE) WrapNv_MemDrvCancel( void );

/** Size defines ************************************************************** */
#define kEepSizeNVP_BLOCK_ID_HW_PARTNUMBER   0x14u
#define kEepSizeSecAccessDelayFlag           0x01u
#define kEepSizeVerificationKeyState         0x01u
#define kEepSizeVerificationKeyValue         0x20u
#define kEepSizeFpStatusInfo                 0x01u
#define kEepSizeFingerprint                  0x13u
#define kEepSizeProgAttempts                 0x02u
#define kEepSizeCRCTotal                     0x04u
#define kEepSizeSwVersion                    0x03u
#define kEepSizeSwPartNumber                 0x0Au
#define kEepSizeSwSupplierInformation        0x02u
#define kEepSizeMinimumSoftwareVersion       0x03u
#define kEepSizeCmac                         0x10u
#define kEepSizeCRCWritten                   0x04u
#define kEepSizeSegmentCount                 0x01u
#define kEepSizeSegmentAddrList              0x28u
#define kEepSizeSegmentLengthList            0x28u
#define kEepSizeIdEcuLocation                0x03u
#define kEepSizeNVP_BLOCK_ID_HW_VERSION      0x03u

#define kWrapNvNrOfBlock                     0x06u
#define kWrapNvNrOfRecord                    0x13u

/** Access macros ************************************************************* */

/* PRQA S 3453 FctLikeMacroLabel */ /* MD_MSR_FctLikeMacro */

#define ApplFblNvReadNVP_BLOCK_ID_HW_PARTNUMBER(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_PARTNUMBER, 0u, (buf))
#define ApplFblNvReadPartialNVP_BLOCK_ID_HW_PARTNUMBER(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_PARTNUMBER, 0u, (buf), (offset), (length))
#define ApplFblNvWriteNVP_BLOCK_ID_HW_PARTNUMBER(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_PARTNUMBER, 0u, (buf))
#define ApplFblNvReadAsyncNVP_BLOCK_ID_HW_PARTNUMBER(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_PARTNUMBER, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncNVP_BLOCK_ID_HW_PARTNUMBER(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_PARTNUMBER, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncNVP_BLOCK_ID_HW_PARTNUMBER(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_PARTNUMBER, 0u, (buf), (op))

#define ApplFblNvReadSecAccessDelayFlag(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf))
#define ApplFblNvReadPartialSecAccessDelayFlag(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf), (offset), (length))
#define ApplFblNvWriteSecAccessDelayFlag(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf))
#define ApplFblNvReadAsyncSecAccessDelayFlag(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncSecAccessDelayFlag(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSecAccessDelayFlag(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf), (op))

#define ApplFblNvReadVerificationKeyState(idx, buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_VERIFICATIONKEYSTATE, (uint16)(idx), (buf))
#define ApplFblNvReadPartialVerificationKeyState(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_VERIFICATIONKEYSTATE, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteVerificationKeyState(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_VERIFICATIONKEYSTATE, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncVerificationKeyState(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_VERIFICATIONKEYSTATE, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncVerificationKeyState(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_VERIFICATIONKEYSTATE, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncVerificationKeyState(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_VERIFICATIONKEYSTATE, (uint16)(idx), (buf), (op))

#define ApplFblNvReadVerificationKeyValue(idx, buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_VERIFICATIONKEYVALUE, (uint16)(idx), (buf))
#define ApplFblNvReadPartialVerificationKeyValue(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_VERIFICATIONKEYVALUE, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteVerificationKeyValue(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_VERIFICATIONKEYVALUE, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncVerificationKeyValue(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_VERIFICATIONKEYVALUE, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncVerificationKeyValue(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_VERIFICATIONKEYVALUE, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncVerificationKeyValue(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_VERIFICATIONKEYVALUE, (uint16)(idx), (buf), (op))

#define ApplFblNvReadFpStatusInfo(idx, buf)  WrapNv_ReadSync(WRAPNV_RECORD_ID_FPSTATUSINFO, (uint16)(idx), (buf))
#define ApplFblNvReadPartialFpStatusInfo(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_FPSTATUSINFO, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteFpStatusInfo(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_FPSTATUSINFO, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncFpStatusInfo(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_FPSTATUSINFO, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncFpStatusInfo(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_FPSTATUSINFO, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncFpStatusInfo(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_FPSTATUSINFO, (uint16)(idx), (buf), (op))

#define ApplFblNvReadFingerprint(idx, buf)   WrapNv_ReadSync(WRAPNV_RECORD_ID_FINGERPRINT, (uint16)(idx), (buf))
#define ApplFblNvReadPartialFingerprint(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_FINGERPRINT, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteFingerprint(idx, buf)  WrapNv_WriteSync(WRAPNV_RECORD_ID_FINGERPRINT, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncFingerprint(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_FINGERPRINT, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncFingerprint(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_FINGERPRINT, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncFingerprint(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_FINGERPRINT, (uint16)(idx), (buf), (op))

#define ApplFblNvReadProgAttempts(idx, buf)  WrapNv_ReadSync(WRAPNV_RECORD_ID_PROGATTEMPTS, (uint16)(idx), (buf))
#define ApplFblNvReadPartialProgAttempts(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_PROGATTEMPTS, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteProgAttempts(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_PROGATTEMPTS, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncProgAttempts(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_PROGATTEMPTS, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncProgAttempts(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_PROGATTEMPTS, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncProgAttempts(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_PROGATTEMPTS, (uint16)(idx), (buf), (op))

#define ApplFblNvReadCRCTotal(idx, buf)      WrapNv_ReadSync(WRAPNV_RECORD_ID_CRCTOTAL, (uint16)(idx), (buf))
#define ApplFblNvReadPartialCRCTotal(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CRCTOTAL, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteCRCTotal(idx, buf)     WrapNv_WriteSync(WRAPNV_RECORD_ID_CRCTOTAL, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncCRCTotal(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_CRCTOTAL, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncCRCTotal(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CRCTOTAL, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncCRCTotal(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_CRCTOTAL, (uint16)(idx), (buf), (op))

#define ApplFblNvReadSwVersion(idx, buf)     WrapNv_ReadSync(WRAPNV_RECORD_ID_SWVERSION, (uint16)(idx), (buf))
#define ApplFblNvReadPartialSwVersion(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SWVERSION, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteSwVersion(idx, buf)    WrapNv_WriteSync(WRAPNV_RECORD_ID_SWVERSION, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncSwVersion(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SWVERSION, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncSwVersion(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SWVERSION, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSwVersion(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SWVERSION, (uint16)(idx), (buf), (op))

#define ApplFblNvReadSwPartNumber(idx, buf)  WrapNv_ReadSync(WRAPNV_RECORD_ID_SWPARTNUMBER, (uint16)(idx), (buf))
#define ApplFblNvReadPartialSwPartNumber(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SWPARTNUMBER, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteSwPartNumber(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SWPARTNUMBER, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncSwPartNumber(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SWPARTNUMBER, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncSwPartNumber(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SWPARTNUMBER, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSwPartNumber(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SWPARTNUMBER, (uint16)(idx), (buf), (op))

#define ApplFblNvReadSwSupplierInformation(idx, buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_SWSUPPLIERINFORMATION, (uint16)(idx), (buf))
#define ApplFblNvReadPartialSwSupplierInformation(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SWSUPPLIERINFORMATION, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteSwSupplierInformation(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SWSUPPLIERINFORMATION, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncSwSupplierInformation(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SWSUPPLIERINFORMATION, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncSwSupplierInformation(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SWSUPPLIERINFORMATION, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSwSupplierInformation(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SWSUPPLIERINFORMATION, (uint16)(idx), (buf), (op))

#define ApplFblNvReadMinimumSoftwareVersion(idx, buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_MINIMUMSOFTWAREVERSION, (uint16)(idx), (buf))
#define ApplFblNvReadPartialMinimumSoftwareVersion(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_MINIMUMSOFTWAREVERSION, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteMinimumSoftwareVersion(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_MINIMUMSOFTWAREVERSION, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncMinimumSoftwareVersion(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_MINIMUMSOFTWAREVERSION, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncMinimumSoftwareVersion(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_MINIMUMSOFTWAREVERSION, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncMinimumSoftwareVersion(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_MINIMUMSOFTWAREVERSION, (uint16)(idx), (buf), (op))

#define ApplFblNvReadCmac(idx, buf)          WrapNv_ReadSync(WRAPNV_RECORD_ID_CMAC, (uint16)(idx), (buf))
#define ApplFblNvReadPartialCmac(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CMAC, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteCmac(idx, buf)         WrapNv_WriteSync(WRAPNV_RECORD_ID_CMAC, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncCmac(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_CMAC, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncCmac(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CMAC, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncCmac(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_CMAC, (uint16)(idx), (buf), (op))

#define ApplFblNvReadCRCWritten(idx, buf)    WrapNv_ReadSync(WRAPNV_RECORD_ID_CRCWRITTEN, (uint16)(idx), (buf))
#define ApplFblNvReadPartialCRCWritten(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CRCWRITTEN, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteCRCWritten(idx, buf)   WrapNv_WriteSync(WRAPNV_RECORD_ID_CRCWRITTEN, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncCRCWritten(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_CRCWRITTEN, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncCRCWritten(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_CRCWRITTEN, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncCRCWritten(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_CRCWRITTEN, (uint16)(idx), (buf), (op))

#define ApplFblNvReadSegmentCount(idx, buf)  WrapNv_ReadSync(WRAPNV_RECORD_ID_SEGMENTCOUNT, (uint16)(idx), (buf))
#define ApplFblNvReadPartialSegmentCount(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SEGMENTCOUNT, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteSegmentCount(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SEGMENTCOUNT, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncSegmentCount(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SEGMENTCOUNT, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncSegmentCount(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SEGMENTCOUNT, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSegmentCount(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SEGMENTCOUNT, (uint16)(idx), (buf), (op))

#define ApplFblNvReadSegmentAddrList(idx, buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_SEGMENTADDRLIST, (uint16)(idx), (buf))
#define ApplFblNvReadPartialSegmentAddrList(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SEGMENTADDRLIST, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteSegmentAddrList(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SEGMENTADDRLIST, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncSegmentAddrList(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SEGMENTADDRLIST, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncSegmentAddrList(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SEGMENTADDRLIST, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSegmentAddrList(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SEGMENTADDRLIST, (uint16)(idx), (buf), (op))

#define ApplFblNvReadSegmentLengthList(idx, buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_SEGMENTLENGTHLIST, (uint16)(idx), (buf))
#define ApplFblNvReadPartialSegmentLengthList(idx, buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SEGMENTLENGTHLIST, (uint16)(idx), (buf), (offset), (length))
#define ApplFblNvWriteSegmentLengthList(idx, buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_SEGMENTLENGTHLIST, (uint16)(idx), (buf))
#define ApplFblNvReadAsyncSegmentLengthList(idx, buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_SEGMENTLENGTHLIST, (uint16)(idx), (buf), (op))
#define ApplFblNvReadPartialAsyncSegmentLengthList(idx, buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_SEGMENTLENGTHLIST, (uint16)(idx), (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncSegmentLengthList(idx, buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_SEGMENTLENGTHLIST, (uint16)(idx), (buf), (op))

#define ApplFblNvReadIdEcuLocation(buf)      WrapNv_ReadSync(WRAPNV_RECORD_ID_IDECULOCATION, 0u, (buf))
#define ApplFblNvReadPartialIdEcuLocation(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_IDECULOCATION, 0u, (buf), (offset), (length))
#define ApplFblNvWriteIdEcuLocation(buf)     WrapNv_WriteSync(WRAPNV_RECORD_ID_IDECULOCATION, 0u, (buf))
#define ApplFblNvReadAsyncIdEcuLocation(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_IDECULOCATION, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncIdEcuLocation(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_IDECULOCATION, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncIdEcuLocation(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_IDECULOCATION, 0u, (buf), (op))

#define ApplFblNvReadNVP_BLOCK_ID_HW_VERSION(buf) WrapNv_ReadSync(WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_VERSION, 0u, (buf))
#define ApplFblNvReadPartialNVP_BLOCK_ID_HW_VERSION(buf, offset, length) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_VERSION, 0u, (buf), (offset), (length))
#define ApplFblNvWriteNVP_BLOCK_ID_HW_VERSION(buf) WrapNv_WriteSync(WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_VERSION, 0u, (buf))
#define ApplFblNvReadAsyncNVP_BLOCK_ID_HW_VERSION(buf, op) WrapNv_ReadAsync(WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_VERSION, 0u, (buf), (op))
#define ApplFblNvReadPartialAsyncNVP_BLOCK_ID_HW_VERSION(buf, offset, length, op) WrapNv_ReadPartialSync(WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_VERSION, 0u, (buf), (offset), (length), (op))
#define ApplFblNvWriteAsyncNVP_BLOCK_ID_HW_VERSION(buf, op) WrapNv_WriteAsync(WRAPNV_RECORD_ID_NVP_BLOCK_ID_HW_VERSION, 0u, (buf), (op))

/* PRQA L:FctLikeMacroLabel */


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/** Specifies how the NV block is configured */
typedef enum
{
   WRAPNV_RECORDACCESS_STRUCTURED = 0u,  /**< NV block consists of several elements */
   WRAPNV_RECORDACCESS_SINGLE            /**< NV block consists of a single element */
} tWrapNvRecordAccess;

/** NV block configuration structure */
typedef struct
{
   tWrapNvRecordAccess blockDataAccess;                        /**< Access variant to the NV block */
   uint16 blockNumber;                                         /**< Number of NV block */
   uint16 blockLength;                                         /**< Length of NV block */
   uint16 blockMaxDatasets;                                    /**< Maximum datasets alloweed for the NV block */
   P2CONST(uint8, AUTOMATIC, WRAPNV_CONST) blockDefaultValue;  /**< Default value for NV block */
} tWrapNvBlockTbl;

/** NV record configuration structure */
typedef struct
{
   uint16 recordDataOffset;                                           /**< Offset in NV block to the data */
   uint16 recordDataLength;                                           /**< Length of data inside the NV block */
   P2CONST(tWrapNvBlockTbl, AUTOMATIC, WRAPNV_CONST) recordBlockPtr;  /**< Pointer to the NV block */
} tWrapNvRecordTbl;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define WRAPNV_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(tWrapNvRecordTbl, WRAPNV_CONST) kWrapNvRecordTbl[kWrapNvNrOfRecord];

# define WRAPNV_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define WRAPNV_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, WRAPNV_CODE) WrapNv_InitConfig( void );

FUNC(void, WRAPNV_CODE) WrapNv_PollMainFunctionsInternalIdle( void );
FUNC(void, WRAPNV_CODE) WrapNv_PollMainFunctionsInternalTimer( void );

# define WRAPNV_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */
/* Hardware specific **********************************************************/

/* ToDo: add hardware specific settings */

/* Project specific (currently not supported by generator) ********************/

#include "fbl_inc.h"

extern void Test_FeeJobErrorNotification(void);

extern void Test_FeeJobEndNotification(void);

extern void NvM_JobEndNotification (void);

extern void NvM_JobErrorNotification (void);
/* User Config File End */


#endif  /* WRAPNV_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: WrapNv_Cfg.h
 *********************************************************************************************************************/


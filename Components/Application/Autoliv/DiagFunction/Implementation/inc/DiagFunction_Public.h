/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

Current revision: $Revision: 1.10 $
Checked in:       $Date: 2024/03/22 11:27:49CET $

*************************************************************************/

#ifndef DIAGFUNCTION_PRIVATE_H
#define DIAGFUNCTION_PRIVATE_H

#include "Platform_Types.h"

/*************************************************************************
Declaration of constants
*************************************************************************/


/*************************************************************************
Declaration of the macros
*************************************************************************/


/*************************************************************************
Declaration of typdefs
*************************************************************************/
typedef struct
{
    uint8 FpStatusInfo;
    uint8 Fingeprint[19];
    uint16 ProgAttempts;
    uint8 CRC[4];
    uint8 SwVersion[3];
    uint8 SwPartNumber[10];
    uint8 SwSupplierInfomartion[2];
    uint8 MinimumSoftwareVersion[3];
    uint8 Cmac[16];
    uint8 CRCWritten[4];
    uint8 SegmentCount;
    uint8 SegmentAddrList[40];
    uint8 SegmentLengthList[40];

}tFblMetadata;

/* Type definition for process information values */
typedef uint8 tAppHardwareSupplierInformation[2];
typedef uint8 tAppSoftwareSupplierInformation[2];
typedef uint8 tBootSoftwareSupplierInformation[2];
typedef uint8 tAppHardwarePartNumber[10];
typedef uint8 tAppBootSoftwarePartNumber[10];
typedef uint8 tAppAppSoftwarePartNumber[10];
typedef uint8 tAppActiveDiagnosticInformation[3];
typedef uint8 tDDSVersion[2];
typedef uint8 tAppHardwareSupplierIdentification[4];

typedef struct
{
    uint8 Major;
    uint8 Minor;
    uint8 Patch;

}tGeneralVersion;

typedef struct
{
    tGeneralVersion Version;
    uint8           XDISVersion[10];
    uint8           ExportDate[10];
    uint8           ECUName[30];

} tEcuExtractInformation ;

typedef struct
{
    uint8           CandelaVersion[10];
    uint8           DiagnosticExtractDDMVersion[10];
    tGeneralVersion DiagnosticExtractVersion;
    uint8           ExportedDiagnosticVersion[30];
} tDiagnosticExtractInformation;

typedef struct
{
    tGeneralVersion StandardApplicationSWPackageVersion;
    uint8           StandardApplicationuCIdentification[20];
    uint8           StandardApplicationSWPackageBuildVersion;
    uint8           StandardApplicationAutosarPlatform;

} tStandardApplicationSWPackageInformation;

typedef struct CommonData
{
    /* F150 - Hardware Version Information */
    tGeneralVersion                              EcuHardwareVersion;

    /* F154 - Hardware Supplier Identification */
    tAppHardwareSupplierInformation              EcuHardwareSupplierInformation;

    /* F155 - Software Supplier Identification*/
    tBootSoftwareSupplierInformation             EcuBootSoftwareSupplierInformation;

    /* F155 - Software Supplier Identification*/
    tAppSoftwareSupplierInformation              EcuAppSoftwareSupplierInformation;

    /* F155 - Software Supplier Identification*/
    tAppSoftwareSupplierInformation              EcuHsmSoftwareSupplierInformation;

    /* F111 - Hardware Part Number */
    tAppHardwarePartNumber                       EcuHardwarePartNumber;

    /* F121 Application Software Part Numbers*/
    tAppAppSoftwarePartNumber                    EcuAppSoftwarePartNumber;

    /* F121 Boot Software Part Numbers*/
    tAppBootSoftwarePartNumber                   EcuBootSoftwarePartNumber;

    /* F151 Application Software Version Information*/
    tGeneralVersion                              EcuAppSoftwareVersion;

    /* F153 Boot Software Version Information*/
    tGeneralVersion                              EcuBootSoftwareVersion;

    /* F100 - Active Diagnostic Information*/
    tAppActiveDiagnosticInformation              ActiveDiagnosticInformation;

    /* F18C - ECU serial number*/
    uint8 *                                      EcuSerialNumber;

    /* 0xF10D App DDS version*/
    tDDSVersion                                  AppDDSVersion;

    /* 0xF10D Boot DDS version*/
    tDDSVersion                                  BootDDSVersion;

    /* EF00 Ecu Extract Information*/
    tEcuExtractInformation                       EcuExtractInformation;

    /* EF01 Diagnostic Extract Information */
    tDiagnosticExtractInformation                DiagnosticExtractInformation;

    /* 0xEF03 Standard Application SW Package Version */
    tStandardApplicationSWPackageInformation     StandardApplicationSWPackageInformation;

    /* 0xEF05 Minimum software version */
    tGeneralVersion                              MinimumSoftwareVersion;

    /* 0xF103 Hardware supplier information */
    tAppHardwareSupplierIdentification           HardwareSupplierIdentification;

    /* 0x0340 Unique seatbelt serialnubmer */
    uint8 *                                      UniqueSeatbeltSerialNumber;

    /* F104 - ECU Name */
    uint8 *                                      EcuName;

} tAppCommonData;

typedef struct {
uint8   NVP_au8CSRSupplierPublicKey[129];
uint8   NVP_au8CSRSupplierSignature[129];
}NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_StorageType;
/*************************************************************************
Exported variables/constants
*************************************************************************/

extern const tFblMetadata NvMBlock_FblMetaData_DefaultValue;
extern NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_StorageType NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_RamBlockData;
extern const NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_StorageType NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_DefaultData;

#ifndef DIAGFUNCTION_DUMMY_STATEMENT
#define DIAGFUNCTION_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif

#define DIAGFUNCTION_ROUTINE_COMPLETED_SUCCESSFULLY  0x00u
#define DIAGFUNCTION_ROUTINE_IN_PROGRESS             0x01u
#define DIAGFUNCTION_ROUTINE_STOPPED_WITHOUT_RESULTS 0x02u

/*! DiagFunction NVM Write states. */
#define DIAGFUNCTION_NVM_WRITEALL_STATE_IDLE                                        (0u)
#define DIAGFUNCTION_NVM_WRITEALL_STATE_START                                       (1u)
#define DIAGFUNCTION_NVM_WRITEALL_STATE_PENDING                                     (2u)

#define DIAGFUNCTION_NVMWRITEALL_FLAG_IDLE 0x00u
#define DIAGFUNCTION_NVMWRITEALL_FLAG_TRIGGERED 0x01u
#define DIAGFUNCTION_NVMWRITEALL_FLAG_COMPLETED 0x02u
#define DIAGFUNCTION_NVMWRITEALL_FLAG_STOPPED_WITHOUT_RESULTS 0x03u

#endif   /* DIAGFUNCTION_PRIVATE_H */ 


/*************************************************************************
Evolution of the component

Created by :

$Log: DiagFunction_Public.h  $
Revision 1.10 2024/03/22 11:27:49CET Tudor Gligor (tudor.gligor) 
Modify 01A2 Trust Model CSR Supplier Signature:
Delete NVP Dependencies
Create RamData & DefaultData inside DiagFunction_Public
Link them inside the NvM Block (#101)
Fix the ReadDataLength memcpy
Revision 1.9 2023/12/15 08:41:39EET Tudor Gligor (tudor.gligor) 
Update CDD 06.09.04 (090) Versioning for DIDs EF01 & F100 + small typo fix
Revision 1.8 2023/12/15 07:54:53EET Roberto Cristoi (roberto.cristoi) 
Synchronize_to_Non_volatile_Memory changed from SYNC to ASYNC
Revision 1.7 2023/11/22 13:30:39EET Tudor Gligor (tudor.gligor) 
Add the 3rd Logical Block for HSM Part No.
Revision 1.6 2023/11/21 10:31:08EET Tudor Gligor (tudor.gligor) 
Update EF03 with the newer CDD modifications regarding StandardApplicationuCIdentification
Revision 1.5 2023/11/02 12:36:55EET Roberto Cristoi (roberto.cristoi) 
Added hsm versioning for F151,f155,f15b
Revision 1.4 2022/11/09 17:04:51EET Emanuel Jivan (emanuel.jivan) 
Synchronized new FblMetadData blocks to application.
Revision 1.3 2022/07/26 10:37:52EEST Roberto Cristoi (roberto.cristoi) 
Ecu individual acl active diag version fix
Revision 1.2 2022/04/29 16:55:42EEST Emanuel Jivan (emanuel.jivan) 
Fixed fingerprint calculation, reprogramming counter and added 2 block reading for diagnostic identification DIDs on app and fbl.
Revision 1.1 2022/03/17 09:25:05EET Emanuel Jivan (emanuel.jivan) 
Initial revision
Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DiagFunction/Implementation/inc/project.pj

*************************************************************************/

/* end of file */

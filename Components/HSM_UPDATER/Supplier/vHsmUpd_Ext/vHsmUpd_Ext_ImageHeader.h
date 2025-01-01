/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsmUpd_Ext_ImageHeader.h
 *        \brief  vHsmUpd_Ext_ImageHeader header file
 *
 *      \details  Header file for ImageHeader structures of the vHsmUpd.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef VHSMUPD_EXT_IMAGEHEADER_H
#define VHSMUPD_EXT_IMAGEHEADER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd_Ext_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Header sizes */
# define VHSMUPD_EXT_HEADER_TAG_SIZE                  (16u)   /*!< Size of the header tag */
# define VHSMUPD_EXT_SIGNATURE_SIZE                   (16u)   /*!< Size of the cryptographic signature */
# define VHSMUPD_EXT_CRC32_SIZE                       (4u)    /*!< Size of Crc32 value */
# define VHSMUPD_EXT_MODULARHEADER_SIZE               (32u)   /* Size of Header in update image (2* AES_BLOCK_SIZE) */
# define VHSMUPD_EXT_FW_OFFSET_SIZE                   (4u)    /* Size of the FwOffset value in update image */
# define VHSMUPD_EXT_CRC_OFFSET_SIZE                  (4u)    /* Size of the CrCOffset value in update image */

# define VHSMUPD_EXT_UPDATEHEADER_VERSIONINFO_SIZE    (4u)
# define VHSMUPD_EXT_UPDATEHEADER_IMAGEADDRESS_SIZE   (4u)
# define VHSMUPD_EXT_UPDATEHEADER_IMAGELENGTH_SIZE    (4u)
# define VHSMUPD_EXT_UPDATEHEADER_COMPLETEHEADER_SIZE (44u)   /* See TechRef */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
  uint8 HeaderTag[VHSMUPD_EXT_HEADER_TAG_SIZE];                             /*!< Update header tag information */
  uint8 VersionInfo[VHSMUPD_EXT_UPDATEHEADER_VERSIONINFO_SIZE];             /*!< The version info within the update header */
  uint8 UpdateFWImageAddress[VHSMUPD_EXT_UPDATEHEADER_IMAGEADDRESS_SIZE];   /*!< The address to the image in the update header */
  uint8 UpdateFWImageLength[VHSMUPD_EXT_UPDATEHEADER_IMAGELENGTH_SIZE];     /*!< The length of the image in the update header */
  uint8 Signature[VHSMUPD_EXT_SIGNATURE_SIZE];                              /*!< The MAC value of the update image */
} vHsmUpd_Ext_UpdateHeaderType;                                             /*!< Type definition of the update header */

typedef struct
{
  vHsmUpd_Ext_IndexType             IndexOfTargetRegion;
  vHsmUpd_Ext_IndexType             IndexOfTargetPartition;
} vHsmUpd_Ext_TargetInformationType;

typedef struct
{
  vHsmUpd_Ext_PartitionPatternType  UpdPartition;
  vHsmUpd_Ext_AddressType           VirtualRegionAddress;
  vHsmUpd_Ext_OffsetType            ModuleUpdateImageOffset;
  vHsmUpd_Ext_LengthType            ModuleUpdateImageLength;
  vHsmUpd_Ext_Crc32Type             ModuleCrcValue;
  vHsmUpd_Ext_TargetInformationType TargetInformations;
} vHsmUpd_Ext_ModuleUpdateHeaderType;

typedef struct
{
  vHsmUpd_Ext_OffsetType FwOffset;                  /*!< Is the Offset information within the update image to find the firmware */
  vHsmUpd_Ext_OffsetType CrcOffset;                 /*!< Is the Offset information within the update image to find the crc value */
  vHsmUpd_Ext_AddressType CalculatedFwAddress;      /*!< Holds the calculated address to the firmware within the update image, given by the offset information */
  vHsmUpd_Ext_AddressType CalculatedCrcAddress;     /*!< Holds the calculated address to the crc within the update image, given by the offset information */
} vHsmUpd_Ext_UpdateImageType;                      /*!< Type definition of the static update image part */

typedef P2VAR(vHsmUpd_Ext_ModuleUpdateHeaderType, AUTOMATIC, VHSMUPD_EXT_APPL_VAR) vHsmUpd_Ext_ModuleUpdateHeaderPtrType;
typedef P2CONST(vHsmUpd_Ext_ModuleUpdateHeaderType, AUTOMATIC, VHSMUPD_EXT_APPL_VAR) vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* VHSMUPD_EXT_IMAGEHEADER_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_ImageHeader.h
 *********************************************************************************************************************/

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
/*!        \file  vHsmUpd_Ext_Types.h
 *        \brief  vHsmUpd header file
 *
 *      \details  Header file for the vHsmUpd. Defines the public API.
 *
 *********************************************************************************************************************/

#if !defined (VHSMUPD_EXT_TYPES_H)
# define VHSMUPD_EXT_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd_Ext_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* Vendor and module identification */
# define VHSMUPD_EXT_VENDOR_ID                                (30u)
# define VHSMUPD_EXT_MODULE_ID                                (0xFFu)

/* Update State Types */
# define VHSMUPD_EXT_UPDATE_NOT_STARTED                       (0x1u)
# define VHSMUPD_EXT_UPDATE_IN_PROGRESS                       (0x2u)
# define VHSMUPD_EXT_UPDATE_COMPLETED                         (0x3u)

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
typedef uint32  vHsmUpd_Ext_FirmwareVersionType; /*!< Type used for the firmware of the vHsm */
typedef uint8   vHsmUpd_Ext_IpcUpdateStateType; /*!< Type used for the current state of the vHsmUpd which is communicated to the Host */

typedef uint32  vHsmUpd_Ext_OffsetType;
typedef uint32  vHsmUpd_Ext_AddressType;
typedef uint32  vHsmUpd_Ext_LengthType;

typedef uint32  vHsmUpd_Ext_PartitionPatternType;
typedef uint32  vHsmUpd_Ext_VersionType;
typedef uint32  vHsmUpd_Ext_Crc32Type;
typedef uint32  vHsmUpd_Ext_IndexType;

typedef P2VAR(uint8, AUTOMATIC, VHSMUPD_EXT_APPL_VAR) vHsmUpd_Ext_DataPtrType;
typedef P2CONST(uint8, AUTOMATIC, VHSMUPD_EXT_APPL_CONST) vHsmUpd_Ext_ConstDataPtrType;
typedef CONSTP2VAR(vHsmUpd_Ext_ConstDataPtrType, AUTOMATIC, VHSMUPD_EXT_APPL_CONST) vHsmUpd_Ext_PtrToConstDataPtrType;
typedef P2VAR(vHsmUpd_Ext_LengthType, AUTOMATIC, VHSMUPD_EXT_APPL_VAR) vHsmUpd_Ext_LengthPtrType;
typedef P2VAR(vHsmUpd_Ext_AddressType, AUTOMATIC, VHSMUPD_EXT_APPL_VAR) vHsmUpd_Ext_AddressPtrType;
typedef P2VAR(vHsmUpd_Ext_VersionType, AUTOMATIC, VHSMUPD_EXT_APPL_VAR) vHsmUpd_Ext_VersionPtrType;
typedef P2VAR(boolean, AUTOMATIC, VHSMUPD_EXT_APPL_VAR) vHsmUpd_Ext_BooleanPtrType;
typedef P2VAR(vHsmUpd_Ext_PartitionIdOfPartitionsType, AUTOMATIC, VHSMUPD_EXT_APPL_VAR) vHsmUpd_Ext_PartitionIndexPtrType;

/* Redefine AddressAreaRef to a shorter name */
typedef vHsmUpd_Ext_AddressAreaRefOfPartitionsType  vHsmUpd_Ext_AreaIdType;

typedef struct
{
  vHsmUpd_Ext_LengthType    BlockLength;                      /*!< Information about the current block length within the update process */
  vHsmUpd_Ext_AddressType   CurrentUpdateFwImageAddress;      /*!< Is the current address within  the update image */
  uint32                    NumberOfModulesToUpdate;          /*!< The number of module headers in the header array */
  uint32                    CurrentUpdateModule;              /*!< The currently processed update header */
} vHsmUpd_Ext_ProcInfoType;                                   /*!< Type used for update handling */

typedef struct
{
  boolean isRecoveryMode;                                   /*!< Indicates whether update process is entered within recovery mode */
  boolean validFirmwareAvailable;                           /*!< Indicates the state of the firmware */
} vHsmUpd_Ext_StateInfoType;                                /*!< Type used for saving the current image/update availability */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPE
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPE
 *********************************************************************************************************************/

#endif /* VHSMUPD_EXT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_Types.h
 *********************************************************************************************************************/

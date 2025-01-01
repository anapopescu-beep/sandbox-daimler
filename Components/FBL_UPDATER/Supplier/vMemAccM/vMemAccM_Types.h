/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMemAccM_Types.h
 *        \brief  vMemAccM types header file
 *
 *      \details  Defines vMemAccM types.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEMACCM_TYPES_H)
# define VMEMACCM_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "vMemAccM_vMemCfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef P2CONST(void, AUTOMATIC, VMEMACCM_APPL_VAR) vMemAccM_ConstDataPtrType;
typedef P2VAR(void, AUTOMATIC, VMEMACCM_APPL_VAR) vMemAccM_DataPtrType;

typedef uint16 vMemAccM_AddressAreaIdType;
typedef uint32 vMemAccM_AddressType;
typedef uint32 vMemAccM_LengthType;
typedef P2VAR(uint32, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_LengthPtrType;
typedef unsigned int vMemAccM_BitfieldType;
typedef uint32 vMemAccM_IndexType;
typedef uint32 vMemAccM_vMemHwSpecificFuncIndexType;
typedef uint8 vMemAccM_MultiPartitionPartitionIdType;
typedef uint8 vMemAccM_VariantIdType; /*!< Specifies the type of the address area variant identifier. */

typedef enum
{
  VMEMACCM_JOB_OK = 0,                /*!< Everything is fine, last job finished successfully. */
  VMEMACCM_JOB_PENDING,               /*!< Job is currently pending, i.e. queued or in processing. */
  VMEMACCM_JOB_CANCELED,              /*!< Job canceled by user. */
  VMEMACCM_JOB_FAILED,                /*!< Job failure without specific reason information. */
  VMEMACCM_READ_CORRECTED_ERRORS,     /*!< HW reported that ECC errors were corrected. */
  VMEMACCM_READ_UNCORRECTABLE_ERRORS, /*!< Uncorrectable ECC errors occurred during read. */
  VMEMACCM_MEM_NOT_BLANK,             /*!< The passed address area is not blank. */
  VMEMACCM_MEM_NOT_EQUAL              /*!< The passed data does not match the NV RAM content within the passed address space. */
} vMemAccM_JobResultType;             /*!< Stores all possible vMemAccM results. */

typedef enum
{
  VMEMACCM_ERRORNOTIF_READ_CORRECTED_ERRORS = VMEMACCM_READ_CORRECTED_ERRORS,        /*!< HW reported that ECC errors were corrected. */
  VMEMACCM_ERRORNOTIF_READ_UNCORRECTABLE_ERRORS = VMEMACCM_READ_UNCORRECTABLE_ERRORS /*!< Uncorrectable ECC errors occurred during read. */
} vMemAccM_ErrorNotifResultType;                                                     /*!< Stores all possible results for vMemAccM_ErrorNotification. */

typedef enum
{
  VMEMACCM_NO_JOB,          /*!< Nothing to do, no job requested. */
  VMEMACCM_WRITEJOB,        /*!< Write job requested. */
  VMEMACCM_READJOB,         /*!< Read job requested. */
  VMEMACCM_READBLANKJOB,    /*!< Read blank job requested. */
  VMEMACCM_COMPAREJOB,      /*!< Compare job requested. */
  VMEMACCM_ERASEJOB,        /*!< Erase job requested. */
  VMEMACCM_VMEMJOB,         /*!< vMem HW specific job requested. */
  VMEMACCM_ISBLANKJOB       /*!< IsBlank job requested. */
} vMemAccM_JobType;         /*!< Stores all possible vMemAccM job types. */

typedef struct
{
  vMemAccM_AddressType Address;             /*!< Current vMemAccM request address. This is either the virtual address,
                                                 or in case of HwSpecificRequest the HwId. */
  vMemAccM_LengthType Length;               /*!< Current vMemAccM request length. */
  uint32 vMemInstanceId;                    /*!< Current vMem instance. */
  vMemAccM_AddressType vMemAddress;         /*!< Current vMem job address. */
  vMemAccM_LengthType vMemLength;           /*!< Current vMem job length. */
  vMemAccM_JobType CurrentJob;              /*!< Current vMemAccM job type. */
  vMemAccM_JobResultType vMemResult;        /*!< Current vMem job result. */
} vMemAccM_StateType;                       /*!< Structure containing all available information vMemAccM can provide via vMemAccM_GetState. */

typedef P2VAR(vMemAccM_StateType, AUTOMATIC, VMEMACCM_APPL_VAR) vMemAccM_StatePtrType;


typedef struct
{
  vMemAccM_AddressType VirtualStartAddress;   /*!< Virtual start address of sub address area. */
  vMemAccM_AddressType PhysicalStartAddress;  /*!< Physical start address of sub address area. */
  vMemAccM_LengthType MaxOffset;              /*!< The maximum offset from both start addresses - virtual and physical.
                                               *   (== sub address area length - 1)
                                               */
  vMemAccM_LengthType NumberOfSectors;        /*!< Number of sectors of sub address area. */
  vMemAccM_LengthType SectorSize;             /*!< Size of a sector in bytes. */
  vMemAccM_LengthType SectorBurstSize;        /*!< Size of sector burst in bytes, sector size if burst is disabled. */
  vMemAccM_LengthType PageSize;               /*!< Size of a page in bytes. */
  vMemAccM_LengthType PageBurstSize;          /*!< Size of page burst in bytes, page size if burst is disabled. */
  vMemAccM_LengthType PageBurstRamAlignment;  /*!< Alignment for page burst ram, 1 if disabled. */
  vMemAccM_HwIdType HwId;                     /*!< Referenced vMem hardware identifier. */
} vMemAccM_MemoryInfoType;

typedef P2VAR(vMemAccM_MemoryInfoType, AUTOMATIC, VMEMACCM_APPL_VAR) vMemAccM_MemoryInfoPtrType;

# define VMEMACCM_BITSET 1u
# define VMEMACCM_BITUNSET 0u

#ifndef VMEMACCM_ERASEVALUE /* COV_VMEMACCM_ERASEVALUE */
# define VMEMACCM_ERASEVALUE 0xFFu
#endif

#endif /* VMEMACCM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_Types.h
 *********************************************************************************************************************/

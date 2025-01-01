/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the HIS security module - CRC calculation
 *
 *  \description  Offers CRC calculation (CRC-16 / CRC-32 / CRC-64)
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#ifndef SEC_CRC_H
#define SEC_CRC_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Sec_Inc.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
#if defined ( SEC_ENABLE_CRC )
/* Defines from SecM214 (V1.1) */
/** Initialize CRC calculation */
# define kCRCInit                       0x01u
/** Update CRC value */
# define kCRCCompute                    0x02u
/** Finalize CRC calculation */
# define kCRCFinalize                   0x03u

/* Remap internal states */
# define SEC_CRC_NONE                   0x00u
# define SEC_CRC_INIT                   kCRCInit
# define SEC_CRC_COMPUTE                kCRCCompute
# define SEC_CRC_FINALIZE               kCRCFinalize
# define SEC_CRC_VERIFY                 0x04u
# define SEC_CRC_GET                    0x05u

/* Size definitions for checksum values */
/** Size of CRC-16 checksum */
# define SEC_SIZE_CHECKSUM_CRC_16       2u
/** Size of CRC-32 checksum */
# define SEC_SIZE_CHECKSUM_CRC_32       4u
/** Size of CRC-64 checksum */
# define SEC_SIZE_CHECKSUM_CRC_64       8u


/**********************************************************************************************************************/

/** Helper macro to set initial CRC value */ /* PRQA S 3453 3 */ /* MD_MSR_FctLikeMacro */
# define SEC_INITIAL_VAL_CRC16(val) (val)
# define SEC_INITIAL_VAL_CRC32(val) (val)
# define SEC_INITIAL_VAL_CRC64(high, low) { (high), (low) }

/** Helper macro to set zero CRC value */
# if (SEC_CRC_TYPE == SEC_CRC16 )
#  define SEC_ZERO_VALUE       SEC_INITIAL_VAL_CRC16(0x00u)
# elif ( SEC_CRC_TYPE == SEC_CRC32 )
#  define SEC_ZERO_VALUE       SEC_INITIAL_VAL_CRC32(0x00u)
# elif ( SEC_CRC_TYPE == SEC_CRC64 )
#  define SEC_ZERO_VALUE       SEC_INITIAL_VAL_CRC64(0x00u, 0x00u)
# endif

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/** Parameter structure for CRC computation */
typedef struct
{
   SecM_Crc16Type          currentCRC;       /**< Current CRC-value */
   SecM_ByteType           crcState;         /**< Operation state to be carried out */
   SecM_ConstRamDataType   crcSourceBuffer;  /**< Pointer to source data */
   SecM_RamDataType        crcOutputBuffer;  /**< Pointer to output buffer for serialized CRC value */
   SecM_LengthType         crcByteCount;     /**< Number of bytes in source buffer */
   FL_WDTriggerFctType     wdTriggerFct;     /**< Watchdog trigger function */
} SecM_CRC16ParamType;
typedef struct
{
   SecM_Crc32Type          currentCRC;       /**< Current CRC-value */
   SecM_ByteType           crcState;         /**< Operation state to be carried out */
   SecM_ConstRamDataType   crcSourceBuffer;  /**< Pointer to source data */
   SecM_RamDataType        crcOutputBuffer;  /**< Pointer to output buffer for serialized CRC value */
   SecM_LengthType         crcByteCount;     /**< Number of bytes in source buffer */
   FL_WDTriggerFctType     wdTriggerFct;     /**< Watchdog trigger function */
} SecM_CRC32ParamType;
typedef struct
{
   SecM_Crc64Type          currentCRC;       /**< Current CRC-value */
   SecM_ByteType           crcState;         /**< Operation state to be carried out */
   SecM_ConstRamDataType   crcSourceBuffer;  /**< Pointer to source data */
   SecM_RamDataType        crcOutputBuffer;  /**< Pointer to output buffer for serialized CRC value */
   SecM_LengthType         crcByteCount;     /**< Number of bytes in source buffer */
   FL_WDTriggerFctType     wdTriggerFct;     /**< Watchdog trigger function */
} SecM_CRC64ParamType;

# if (SEC_CRC_TYPE == SEC_CRC16 )
typedef SecM_CRC16ParamType   SecM_CRCParamType;
# elif ( SEC_CRC_TYPE == SEC_CRC32 )
typedef SecM_CRC32ParamType   SecM_CRCParamType;
# elif ( SEC_CRC_TYPE == SEC_CRC64 )
typedef SecM_CRC64ParamType   SecM_CRCParamType;
# endif

/** Pointer type for API functions */
typedef SecM_StatusType SEC_CALL_TYPE (* pSecComputeCRCFct)( V_MEMRAM1 SecM_CRCParamType V_MEMRAM2 V_MEMRAM3 * crcParam );
#endif /* SEC_ENABLE_CRC */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define SECM_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_ENABLE_SAVE_RESTORE_CRC)
V_MEMRAM0 extern V_MEMRAM1 SecM_CrcWorkspaceInfoType V_MEMRAM2 SecM_CrcWorkspaceInfo[SEC_CRC_WORKSPACE_SIZE];
#endif /* SEC_ENABLE_SAVE_RESTORE_CRC */

#define SECM_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( __cplusplus )
extern "C" {
#endif

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

void SecM_InitPowerOnCRC( void );
#if defined( SEC_ENABLE_CRC )
SecM_StatusType SecM_ComputeCRC( V_MEMRAM1 SecM_CRCParamType V_MEMRAM2 V_MEMRAM3 * crcParam );
#endif /* SEC_ENABLE_CRC */
/**********************************************************************************************************************/

/* Access individual CRC primitives */

#if defined( SEC_ENABLE_CRC_TYPE_CRC16 )
SecM_StatusType SecM_ComputeCrc16(V_MEMRAM1 SecM_CRC16ParamType V_MEMRAM2 V_MEMRAM3 * crcParam);
#endif /* SEC_ENABLE_CRC_TYPE_CRC16 */
#if defined( SEC_ENABLE_CRC_TYPE_CRC32 )
SecM_StatusType SecM_ComputeCrc32(V_MEMRAM1 SecM_CRC32ParamType V_MEMRAM2 V_MEMRAM3 * crcParam);
#endif /* SEC_ENABLE_CRC_TYPE_CRC32 */
#if defined( SEC_ENABLE_CRC_TYPE_CRC64 )
SecM_StatusType SecM_ComputeCrc64(V_MEMRAM1 SecM_CRC64ParamType V_MEMRAM2 V_MEMRAM3 * crcParam);
#endif /* SEC_ENABLE_CRC_TYPE_CRC64 */

#if defined( SEC_ENABLE_SAVE_RESTORE_CRC )
SecM_StatusType SecM_SaveContextCrc(SecM_WordType workspaceIdx, SecM_RamDataType contextBuffer, SecM_RamWordType contextBufferLengthPtr);
#endif /* SEC_ENABLE_SAVE_RESTORE_CRC */

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( __cplusplus )
} /* extern "C" */
#endif

#endif /* SEC_CRC_H */

/***********************************************************************************************************************
 *  END OF FILE: SEC_CRC.H
 **********************************************************************************************************************/

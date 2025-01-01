/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file   vOtaM_Types.h
 *         \brief  vOtaM_Types header file
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef VOTAM_TYPES_H
#define VOTAM_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Compiler.h"
#include "ComStack_Types.h"
#include "vOtaM_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#ifndef INLINE
# define INLINE inline
#endif

#ifndef STATIC
# define STATIC static
#endif

#ifndef VOTAM_LOCAL
# define VOTAM_LOCAL STATIC
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Partition specific types */
typedef uint32  vOtaM_PartitionIdType;
typedef uint8   vOtaM_PartitionStateType;
typedef uint32  vOtaM_PartitionRevisionType;

/* Module specific types */
typedef uint32  vOtaM_ModuleIdType;
typedef uint32  vOtaM_ModuleRevisionType;

/* Validity Type, VOTAM_VALIDITY_NA is used if module is not part of a partition */
typedef enum
{
   VOTAM_VALIDITY_NA,
   VOTAM_VALIDITY_INVALID,
   VOTAM_VALIDITY_VALID
} vOtaM_ValidityType;

/* Module Info Type */
typedef struct svOtaM_ModuleInfoType
{
   vOtaM_ModuleIdType            Id;
   vOtaM_ValidityType            Validity;
   vOtaM_PartitionRevisionType   Revision;
} vOtaM_ModuleInfoType;

/* Partition Info Type */
typedef struct svOtaM_PartitionInfoType
{
   vOtaM_PartitionIdType         Id;
   vMemAccM_VariantIdType        Variant;
   vOtaM_PartitionStateType      State;
   vOtaM_ValidityType            Validity;
   vOtaM_PartitionRevisionType   Revision;
   vOtaM_ModuleInfoType          Modules[VOTAM_MODULE_COUNT];
} vOtaM_PartitionInfoType;

typedef Std_ReturnType (*vOtaM_PreSwapCheckFctPtrType)(vOtaM_PartitionIdType srcPartitionId, vOtaM_PartitionIdType destPartitionId);
typedef Std_ReturnType (*vOtaM_InvalidatePartitionFctPtrType)(vOtaM_PartitionIdType partitionId);
typedef Std_ReturnType (*vOtaM_VerifyPartitionFctPtrType)(vOtaM_PartitionIdType partitionId);
typedef Std_ReturnType (*vOtaM_ValidatePartitionFctPtrType)(vOtaM_PartitionIdType partitionId);
typedef Std_ReturnType (*vOtaM_InvalidateModuleFctPtrType)(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId);
typedef Std_ReturnType (*vOtaM_VerifyModuleFctPtrType)(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId);
typedef Std_ReturnType (*vOtaM_ValidateModuleFctPtrType)(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId);

#if defined( VOTAM_USECASE_EXTENDED )
# if defined( VOTAM_ENABLE_READ_PROCESSING )
typedef struct
{
   V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * dataBuffer;
   vuint16        dataLength;
   V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * dataOutBuffer;
   vuint16        dataOutLength;
   vuint16        dataOutMaxLength;
   vuint8(*wdTriggerFct)(void);
   vuint8         mode;
   V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * key;
} vOtaM_ProcParam;
# endif /* VOTAM_ENABLE_READ_PROCESSING */
#endif /* VOTAM_USECASE_EXTENDED */

#if defined( VOTAM_ENABLE_PROG_ATTEMPTS )
typedef uint32 vOtaM_ProgAttemptsType;
#endif /* VOTAM_ENABLE_PROG_ATTEMPTS */

#endif /* VOTAM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: vOtaM_Types.h
 *********************************************************************************************************************/

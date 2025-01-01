/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Interface layer for accessing the logical block table (LBT)
 *
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
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2018-05-24  visci   -                Initial version
 *  01.01.00   2018-11-27  visshs  ESCAN00101459    Add Support for Secure Boot
 *  01.02.00   2019-02-26  visrie  ESCAN00102278    Added additional getter functions
 *  01.02.01   2019-09-05  visrcn  ESCAN00103604    Modified memory qualifiers
 *  01.03.00   2022-03-31  visstn  FBL-4366         Perform MISRA 2012 migration
 *  01.04.00   2022-10-17  visjns  FBL-4925         No changes
 **********************************************************************************************************************/

#ifndef FBL_LBT_ACCESS_H
#define FBL_LBT_ACCESS_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblLib_Lbt CQComponent : Implementation */
#define FBLLIB_LBT_VERSION           0x0104u
#define FBLLIB_LBT_RELEASE_VERSION   0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Required due to usage of "boolean" type */
#include "Platform_Types.h"

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/** Settings for mandatoryType sub-filter */
typedef struct
{
   tFblLbtMandatoryType    value;
   boolean                 enabled;
} tFblLbtMandatoryFilter;

#if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
/** Settings for blockType sub-filter */
typedef struct
{
   tFblLbtBlockType        value;
   boolean                 enabled;
} tFblLbtTypeFilter;
#endif /* FBL_LBT_ENABLE_BLOCK_TYPE */

/** Global filter settings */
typedef struct
{
   tFblLbtMandatoryFilter  mandatoryType;
#if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
   tFblLbtTypeFilter       blockType;
#endif
} tFblLbtBlockFilter;

#define FBLLBT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

void FblLbtInitPowerOn(void);

/* Setter */
void FblLbtBlockFilterInit(V_MEMRAM1 tFblLbtBlockFilter V_MEMRAM2 V_MEMRAM3 * blockFilter);
void FblLbtBlockFilterSetMandatoryType(V_MEMRAM1 tFblLbtBlockFilter V_MEMRAM2 V_MEMRAM3 * blockFilter, tFblLbtMandatoryType mandatoryType);
#if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
void FblLbtBlockFilterSetBlockType(V_MEMRAM1 tFblLbtBlockFilter V_MEMRAM2 V_MEMRAM3 * blockFilter, tFblLbtBlockType blockType);
#endif

/* Getter */
tFblLbtBlockCount FblLbtGetBlockCount(void);
tFblLbtMagicFlag FblLbtGetMagicFlag(void);
tFblResult FblLbtGetBlockNrByAddressLength(tFblAddress address, tFblLength length, V_MEMRAM1 tFblLbtBlockNr V_MEMRAM2 V_MEMRAM3 * blockNr);

tFblResult FblLbtGetBlockDescriptorByNr(tFblLbtBlockNr blockNr, V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor);
tFblResult FblLbtGetBlockDescriptorByAddressLength(tFblAddress address, tFblLength length, V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor);
#if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
tFblResult FblLbtGetBlockDescriptorByType(tFblLbtBlockType blockType, V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor);
#endif
#if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
tFblResult FblLbtGetBlockTypeByNr(tFblLbtBlockNr blockNr, V_MEMRAM1 tFblLbtBlockType V_MEMRAM2 V_MEMRAM3 * blockType);
#endif
#if defined( FBL_LBT_ENABLE_BLOCK_INDEX )
tFblResult FblLbtGetBlockIndexByNr(tFblLbtBlockNr blockNr, V_MEMRAM1 tFblLbtBlockIndex V_MEMRAM2 V_MEMRAM3 * blockIndex);
#endif
#if defined( FBL_LBT_ENABLE_HEADER_ADDRESS )
tFblResult FblLbtGetBlockHeaderAddressByNr(tFblLbtBlockNr blockNr, V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * blockHeaderAddress);
#endif
#if defined( FBL_LBT_ENABLE_BM_HEADER_ADDRESS )
tFblResult FblLbtGetBlockBmHeaderAddressByNr(tFblLbtBlockNr blockNr, V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * bmHeaderAddress);
#endif
#if defined( FBL_LBT_ENABLE_MAX_PROG_ATTEMPTS )
tFblResult FblLbtGetBlockMaxProgAttemptsByNr(tFblLbtBlockNr blockNr, V_MEMRAM1 tFblLbtMaxProgAttempts V_MEMRAM2 V_MEMRAM3 * maxProgAttempts);
#endif
#if defined( FBL_LBT_ENABLE_VERIFY_INPUT )
tFblResult FblLbtGetBlockVerifyInputFuncByNr(tFblLbtBlockNr blockNr, V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc);
#endif
#if defined( FBL_LBT_ENABLE_VERIFY_PROCESSED )
tFblResult FblLbtGetBlockVerifyProcessedFuncByNr(tFblLbtBlockNr blockNr, V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc);
#endif
#if defined( FBL_LBT_ENABLE_VERIFY_PIPELINED )
tFblResult FblLbtGetBlockVerifyPipelinedFuncByNr(tFblLbtBlockNr blockNr, V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc);
#endif
#if defined( FBL_LBT_ENABLE_VERIFY_OUTPUT )
tFblResult FblLbtGetBlockVerifyOutputFuncByNr(tFblLbtBlockNr blockNr, V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc);
#endif

#if defined( FBL_LBT_ENABLE_BLOCK_INDEX )
tFblResult FblLbtGetBlockDescriptorByIndex(tFblLbtBlockIndex blockIndex, V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * blockDescriptor);
tFblResult FblLbtGetBlockNrByIndex(tFblLbtBlockIndex blockIndex, V_MEMRAM1 tFblLbtBlockNr V_MEMRAM2 V_MEMRAM3 * blockNr);
# if defined( FBL_LBT_ENABLE_BLOCK_TYPE )
tFblResult FblLbtGetBlockTypeByIndex(tFblLbtBlockIndex blockIndex, V_MEMRAM1 tFblLbtBlockType V_MEMRAM2 V_MEMRAM3 * blockType);
# endif
# if defined( FBL_LBT_ENABLE_HEADER_ADDRESS )
tFblResult FblLbtGetBlockHeaderAddressByIndex(tFblLbtBlockIndex blockIndex, V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * blockHeaderAddress);
# endif
# if defined( FBL_LBT_ENABLE_BM_HEADER_ADDRESS )
tFblResult FblLbtGetBlockBmHeaderAddressByIndex(tFblLbtBlockIndex blockIndex, V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * bmHeaderAddress);
# endif
# if defined( FBL_LBT_ENABLE_MAX_PROG_ATTEMPTS )
tFblResult FblLbtGetBlockMaxProgAttemptsByIndex(tFblLbtBlockIndex blockIndex, V_MEMRAM1 tFblLbtMaxProgAttempts V_MEMRAM2 V_MEMRAM3 * maxProgAttempts);
# endif
# if defined( FBL_LBT_ENABLE_VERIFY_INPUT )
tFblResult FblLbtGetBlockVerifyInputFuncByIndex(tFblLbtBlockIndex blockIndex, V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc);
# endif
# if defined( FBL_LBT_ENABLE_VERIFY_PROCESSED )
tFblResult FblLbtGetBlockVerifyProcessedFuncByIndex(tFblLbtBlockIndex blockIndex, V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc);
# endif
# if defined( FBL_LBT_ENABLE_VERIFY_PIPELINED )
tFblResult FblLbtGetBlockVerifyPipelinedFuncByIndex(tFblLbtBlockIndex blockIndex, V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc);
# endif
# if defined( FBL_LBT_ENABLE_VERIFY_OUTPUT )
tFblResult FblLbtGetBlockVerifyOutputFuncByIndex(tFblLbtBlockIndex blockIndex, V_MEMRAM1 tExportFct V_MEMRAM2 V_MEMRAM3 * blockVerifyFunc);
# endif
#endif /* FBL_LBT_ENABLE_BLOCK_INDEX */

/* Iterator */
tBlockDescriptor FblLbtBlockFirst(const V_MEMRAM1 tFblLbtBlockFilter V_MEMRAM2 V_MEMRAM3 * blockFilter);
tBlockDescriptor FblLbtBlockNext(void);
boolean FblLbtBlockDone(void);

/* Checker */
tFblResult FblLbtCheckAddressRange(tFblAddress address, tFblAddress rangeStart, tFblLength rangeLength);
tFblResult FblLbtCheckRangeContained(tFblAddress address, tFblLength length, tFblAddress rangeStart, tFblLength rangeLength);

#if defined( FBL_LBT_ENABLE_REPROGRAMMABLE_LBT )
tFblResult FblLbtCheckConsistency(void);
void FblLbtActivateLbtBlock(void);
#endif /* FBL_LBT_ENABLE_REPROGRAMMABLE_LBT */
void FblLbtActivateLbtBlockByAddress(tFblAddress address);

#define FBLLBT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBLLIB_LBT_ACCESS_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_LBT_ACCESS.H
 **********************************************************************************************************************/

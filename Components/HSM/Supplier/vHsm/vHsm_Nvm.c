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
/*!        \file  vHsm_Nvm.c
 *        \brief  Source file for the Nvm
 *
 *      \details  The Nvm stores the key elements which are marked as persisted
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSM_NVM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm_Nvm.h"
#include "vHsm.h"
#include "vHsm_Trace.h"
#include "vHsm_Hal.h"

#include "vstdlib.h"
#include "MemIf.h"
#include "vHsm_ApiInternal.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (VHSM_LOCAL) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL                                                   static
#endif

#if !defined (VHSM_LOCAL_INLINE) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VHSM_NVM_SUPPORT == STD_ON)
VHSM_LOCAL NvM_RequestResultType vHsm_NvM_ProcessBlock(NvM_BlockIdType bockId);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

VHSM_LOCAL NvM_RequestResultType vHsm_NvM_ProcessBlock(NvM_BlockIdType bockId)
{
  NvM_RequestResultType Int_NvMultiBlockStatus;

  if (vHsm_State.vHsm_DataflashPeLock == FALSE)
  {
    do
    {
      vHsm_NvM_ProcessBlock_Callout();
      vHsm_NvMainFunctions_Callout();
      (void)NvM_GetErrorStatus(bockId, &Int_NvMultiBlockStatus);
    } while (Int_NvMultiBlockStatus == NVM_REQ_PENDING);
  }
  else
  {
    Int_NvMultiBlockStatus = NVM_REQ_NOT_OK;
  }

  return Int_NvMultiBlockStatus;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vHsm_NvM_WriteBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_NvM_WriteBlock(
  NvM_BlockIdType BlockId,
  P2CONST(void, AUTOMATIC, VHSM_APPL_VAR) NvM_SrcPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Trigger writing of block in Nvm */
  if (NvM_WriteBlock(BlockId, NvM_SrcPtr) == E_OK)
  {
    /* #20 Process the async Nvm until the request is finished */
    if (vHsm_NvM_ProcessBlock(BlockId) == NVM_REQ_OK)
    {
      retVal = E_OK;
    }
  }
  /* #30 Return result */
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_NvM_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_NvM_Init(void)
{
  Std_ReturnType retVal;
  NvM_RequestResultType nvBlockStatus;
  NvM_BlockIdType blockIdx;

  /* #20 Perform Nvm readall */
  NvM_ReadAll();

  /* #30 Get nvBlockStatus state of all blocks */
  nvBlockStatus = vHsm_NvM_ProcessBlock(NvMConf___MultiBlockRequest);

  /* #40 Check if reading all blocks was not successful */
  if (nvBlockStatus != NVM_REQ_OK)
  {
# if (VHSM_INVALID_NV_MBLOCK_BEHAVIOUR == VHSM_PERSIST_NVMCONFIGBLOCK)
    retVal = E_NOT_OK;
# endif

    vHsm_NvM_InvalidBlockDetected_Callout();

    vHsm_Trace(VHSM_TRACETYPE_ERROR, "NvM_ReadAll() not finished with NVM_REQ_OK but %d!", nvBlockStatus);

    blockIdx = NvMConf_NvMBlockDescriptor_NvMConfigBlock;
    /* #41 Check config block */
    (void)NvM_GetErrorStatus(blockIdx, &nvBlockStatus);
    if (nvBlockStatus != NVM_REQ_OK)
    {
      /* #42 Config block not ok, persits it */
      if (vHsm_NvM_WriteBlock(blockIdx, NULL_PTR) == E_OK)
      {
        vHsm_FirstStartup_Callout();

# if (VHSM_INVALID_NV_MBLOCK_BEHAVIOUR == VHSM_PERSIST_NVMCONFIGBLOCK)
        retVal = E_OK;
# endif
      }
    }

# if (VHSM_INVALID_NV_MBLOCK_BEHAVIOUR == VHSM_PERSIST_INVALID_BLOCKS)
    retVal = E_OK;

    /* #50 For each NvmBlock: */
    for (blockIdx = 2u; blockIdx <= VHSM_TOTAL_NV_BLOCKS; blockIdx++)
    {
      /* #51 Check block */
      (void)NvM_GetErrorStatus(blockIdx, &nvBlockStatus);
      if (nvBlockStatus != NVM_REQ_OK)
      {
        /* #52 Config not ok, persits it */
        if (vHsm_NvM_WriteBlock(blockIdx, NULL_PTR) != E_OK)
        {
          retVal |= E_NOT_OK;
        }
      }
    }
# endif

# if (VHSM_INVALID_NV_MBLOCK_BEHAVIOUR == VHSM_IGNORE_INVALID_BLOCKS)
    /* #60 Ignore invalid blocks */
    retVal = E_OK;
# endif

  }
  else
  {
    retVal = E_OK;
  }
  return retVal;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (VHSM_NVM_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_NvM_PerformWriteAll()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_NvM_PerformWriteAll(void)
{
  Std_ReturnType retVal = E_NOT_OK;

  /*  #10 Trigger write all of Nvm */
  NvM_WriteAll();

  /* #20 Process the async Nvm until the request is finished */
  if (vHsm_NvM_ProcessBlock(NvMConf___MultiBlockRequest) == NVM_REQ_OK)
  {
    retVal = E_OK;
  }
   /* #30 Return result */
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_NvM_Repersist()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_NvM_Repersist(void)
{
  Std_ReturnType retVal = E_OK;
  NvM_BlockIdType blockIdx;

  /* #10 For each NvmBlock: */
  for (blockIdx = 1u; blockIdx <= VHSM_TOTAL_NV_BLOCKS; blockIdx++)
  {
    /* #20 Set ram block status for all blocks to changed */
    retVal |= NvM_SetRamBlockStatus(blockIdx, TRUE);

    /* #30 Perform immediate write all */
    retVal |= vHsm_NvM_WriteBlock(blockIdx, NULL_PTR);
  }

  /* #40 Return result */
  return retVal;
}
#endif

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Nvm.c
 *********************************************************************************************************************/

/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2020)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : Fls_17_Dmu_ac.c                                             **
**                                                                           **
**  VERSION :  3.0.0                                                         **
**                                                                           **
**  DATE       :  2020-05-29                                                 **
**                                                                           **
**  VARIANT   : Variant PB                                                   **
**                                                                           **
**  PLATFORM  : Infineon AURIX2G                                             **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains command sequences of Flash driver      **
**                                                                           **
**  SPECIFICATION(S) : Specification of FLS Driver, AUTOSAR Release 4.2.2    **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* [cover parentID={4D611C8D-52AA-42d4-92A1-B4280952EE29}][/cover] */

/* Inclusion of flash sfr file */
#include "IfxDmu_reg.h"

/* Inclusion of Flash header file */
#include "Fls_17_Dmu.h"

/* Include Flash Module access code File */
#include "Fls_17_Dmu_ac.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* size of data loaded into page buffer at a time - 8bytes */
#define FLS_LOAD_PAGE_SIZE   (8U)

/* number of words per FLS_LOAD_PAGE_SIZE */
#define FLS_17_TWO_WORDS     (2U)

/* Hardare Timeout for Command cycle*/
#define FLS_17_DMU_CMDCYCLE_TIMEOUT            (25U)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define FLS_17_DMU_START_SEC_CODE_QM_LOCAL
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safeguard. It complies to Autosar guidelines. */
#include "Fls_17_Dmu_MemMap.h"

static void Fls_lWriteCmdCycles(const uint32 StartAddress,
                        const uint32 PageAddress,
                        const Fls_17_Dmu_AddressType* const ProgramDataPtr,
                        const uint8 WriteMode);

/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safeguard. It complies to Autosar guidelines. */

/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
static void Fls_lEraseCmdCycles(const uint32 EraseAddress);
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
#define FLS_17_DMU_STOP_SEC_CODE_QM_LOCAL
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline.*/
#include "Fls_17_Dmu_MemMap.h"

LOCAL_INLINE boolean Fls_lCmdCycleTimeout(const uint32 InnerCount);

LOCAL_INLINE void Fls_lCycle5554(const uint32 Address, const uint32 Data);

LOCAL_INLINE void Fls_lCycleAAA8(const uint32 Address, const uint32 Data);

LOCAL_INLINE void Fls_lCycleAA50(const uint32 Address, const uint32 Data);

LOCAL_INLINE void Fls_lCycleAA58(const uint32 Address, const uint32 Data);

LOCAL_INLINE void Fls_lEnterPageMode(const uint32 Address, const uint32 Data);

LOCAL_INLINE void Fls_lLoadPage(const uint32 Address,
                                     const Fls_17_Dmu_AddressType* DataPtr);

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
#define FLS_17_DMU_START_SEC_VAR_CLEARED_QM_LOCAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safeguard. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
#include "Fls_17_Dmu_MemMap.h"
extern const Fls_17_Dmu_ConfigType *Fls_ConfigPtr;

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
#define FLS_17_DMU_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safeguard. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
 #include "Fls_17_Dmu_MemMap.h"
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
** Traceability      : [cover parentID={E28AA64E-CA28-4cb9-9619-03B489318E98}]**
** Syntax : static void Fls_lWriteCmdCycles( const uint32 StartAddress,       **
**                             const uint32 PageAddress,                      **
**                       const Fls_17_Dmu_AddressType* const ProgramDataPtr   **
**                             const uint8 WriteMode                          **
**                                )                                           **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StartAddress,PageAddress, ProgramDataPtr and WriteMode   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine contains flash write command cycles             **
*******************************************************************************/
#define FLS_17_DMU_START_SEC_CODE_QM_LOCAL
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
/* CYCLOMATIC_Fls_lWriteCmdCycles_JUSTIFICATION: This Function is the command
 sequence for WRITE operation and has to check for many error conditions(as
per HW manual) which is leading to many conditional blocks. Breaking it into
local function will break the continuity of the command sequence*/
#include "Fls_17_Dmu_MemMap.h"

static void Fls_lWriteCmdCycles(const uint32 StartAddress,
                         const uint32 PageAddress,
                         const Fls_17_Dmu_AddressType* const ProgramDataPtr,
                         const uint8 WriteMode
                       )
{
  uint32 InnerCount;
  const Fls_17_Dmu_AddressType* pdata;
  Fls_17_Dmu_StateType* StatePtr;
  uint8 FlsSqerErr;
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  StatePtr->FlsTimeoutErr = 0U;
  FlsSqerErr = 0U;
  pdata = ProgramDataPtr;
  uint16 TimeOutCount;
  uint16 TimeOutCountInitial;
  uint16 TimeOutResolution;
  uint16 MeasuredTicks;

  /* Enter the Page Mode */
  Fls_lEnterPageMode(StartAddress, VALUE_5D);

  InnerCount = 0U;

  /* Is the sequence error not detected or timeout has
  not happened or the status of DFPAGE bit is still not set? */
  /*MISRA2012_RULE_11_4_JUSTIFICATION: Conversion between pointer to
    object and integer type is done for special function registers.
    No side affect foreseen by this violation.*/
  /*MISRA2012_RULE_13_5_JUSTIFICATION: This warning is due to the volatile
   qualifier in the SFRs and no side-affect foreseen by violation.*/
  while((DMU_SF_STATUS.B.DFPAGE != 1U) && \
        (InnerCount < FLS_17_DMU_CMDCYCLE_TIMEOUT) && \
        ((DMU_SF_ERRSR.B.SQER != 1U)))
  {
    InnerCount++;
  }

  /*MISRA2012_RULE_13_5_JUSTIFICATION: This warning is due to the volatile
   qualifier in the SFRs and no side-affect foreseen by violation.*/
  if((DMU_SF_ERRSR.B.SQER != 0U))
  {

    FlsSqerErr = (uint8)1;
  }
  /* Check for command cycle Timeout */

  if ((boolean)TRUE == Fls_lCmdCycleTimeout(InnerCount))
  {
    StatePtr->FlsTimeoutErr = FLS_17_DMU_WRITE;
  }

  else if (FlsSqerErr == (uint8)0)
  /* Check DFPAGE bit was SET */
  {

    if(WriteMode == FLS_17_DMU_BURST_WRITE)
    {
      InnerCount = (FLS_17_DMU_BURST_PAGE_SIZE / FLS_LOAD_PAGE_SIZE);
    }
    else
    {
      InnerCount = (FLS_17_DMU_PAGE_SIZE / FLS_LOAD_PAGE_SIZE);
    }

    while(InnerCount != 0U)
    {
      /* Load the data */
      Fls_lLoadPage(StartAddress, pdata);

      /* Page assembly buffer pointer gets incremented automatically */
      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
      array indexing used for buffer address calculation and for subsequent
      traversal.The access range is within the valid range.*/
      pdata += FLS_17_TWO_WORDS;
      InnerCount--;
    }

    /* cycle 1 */
    Fls_lCycleAA50(StartAddress, PageAddress);
    /* cycle 2 */
    Fls_lCycleAA58(StartAddress, VALUE_00);

    /* cycle 3 */
    Fls_lCycleAAA8(StartAddress, VALUE_A0);


    /* cycle 4 */
    if(WriteMode == FLS_17_DMU_BURST_WRITE)
    {
      Fls_lCycleAAA8(StartAddress, VALUE_A6);
    }
    else
    {
      Fls_lCycleAAA8(StartAddress, VALUE_AA);
    }

    InnerCount = 0U;


    /*MISRA2012_RULE_11_4_JUSTIFICATION: Conversion between pointer to
      object and integer type is permitted for special function registers*/
    /*MISRA2012_RULE_13_5_JUSTIFICATION: This warning is due to the volatile
   qualifier in the SFRs and no side-affect foreseen by violation.*/
    while((DMU_SF_OPERATION.B.PROG != 1U) &&    \
          (InnerCount < FLS_17_DMU_CMDCYCLE_TIMEOUT) && \
          (DMU_SF_ERRSR.B.SQER != 1U))
    {
      InnerCount++;
    }

    if ((boolean)TRUE == Fls_lCmdCycleTimeout(InnerCount))
    {
      StatePtr->FlsTimeoutErr = FLS_17_DMU_WRITE;
    }

    /*MISRA2012_RULE_13_5_JUSTIFICATION: Volatile qualifier is needed for
    the device registers.*/
    else if(DMU_SF_ERRSR.B.SQER != 1U)
    {
      /* Get the Tick resolution */
      TimeOutResolution = Timer_DelayTickResolution();
      /* Calculate the Delay count */
      TimeOutCount = (uint16)FLS_17_DMU_HWBUSY_DELAY / TimeOutResolution;
      /* Get the Initial count */
      TimeOutCountInitial = Timer_DelayGetTick();

      do
      {
        /* Calculate the elapsed Tick  */
        MeasuredTicks = Timer_DelayGetTick() -  TimeOutCountInitial;

        } while (TimeOutCount > MeasuredTicks);

    }
    else
    {
      /*Dummy else for MISRA*/
    }
  }

  else
  {
    /*dummy else*/
  }
}
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */


/*******************************************************************************
** Traceability : [cover parentID={D05B71FA-3BD8-4082-A5D0-96C88DFE1B88}]     **
** Syntax : static void Fls_lEraseCmdCycles(const uint32 EraseAddress)        **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StartAddress                                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine contains flash Erase command cycles             **
*******************************************************************************/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
static void Fls_lEraseCmdCycles(const uint32 EraseAddress)
{
  uint32 InnerCount;
  uint32 StartAddress;
  uint8 EraseNumSec;
  uint16 TimeOutCount;
  uint16 TimeOutCountInitial;
  uint16 TimeOutResolution;
  uint16 MeasuredTicks;
  Fls_17_Dmu_StateType* StatePtr;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  StatePtr->FlsTimeoutErr = 0U;
  EraseNumSec  = StatePtr->FlsEraseNumSecPerCmd;

  StartAddress = FLS_17_DMU_BASE_ADDRESS;
  /* cycle 1 */
  Fls_lCycleAA50(StartAddress, EraseAddress);
  /* cycle 2 */
  Fls_lCycleAA58(StartAddress, EraseNumSec);
  /* cycle 3 */
  Fls_lCycleAAA8(StartAddress, VALUE_80);
  /* cycle 4 */
  Fls_lCycleAAA8(StartAddress, VALUE_50);

  InnerCount = 0U;

  /*MISRA2012_RULE_11_4_JUSTIFICATION: Conversion between pointer to
  object and integer type is permitted for special function registers*/
  /*MISRA2012_RULE_13_5_JUSTIFICATION: This warning is due to the volatile
   qualifier in the SFRs and no side-affect foreseen by violation.*/
  while((DMU_SF_OPERATION.B.ERASE != 1U) &&   \
        (InnerCount < FLS_17_DMU_CMDCYCLE_TIMEOUT) && \
        (DMU_SF_ERRSR.B.SQER != 1U))
  {
    InnerCount++;
  }

  /*return Error there is a Timeout has happened */
  if ((boolean)TRUE == Fls_lCmdCycleTimeout(InnerCount))
  {
    StatePtr->FlsTimeoutErr = FLS_17_DMU_ERASE;
  }
  /*No sequence error delay*/

  /*MISRA2012_RULE_13_5_JUSTIFICATION: Volatile qualifier is needed for
  the device registers.*/
  else if(DMU_SF_ERRSR.B.SQER != 1U)
  {
    /*Wait for 100ns*/
    /* Get the Tick resolution */
    TimeOutResolution = Timer_DelayTickResolution();
    /* Calculate the Delay count */
    TimeOutCount = (uint16)FLS_17_DMU_HWBUSY_DELAY / TimeOutResolution;
    /* Get the Initial count */
    TimeOutCountInitial = Timer_DelayGetTick();

    do
    {
      /* Calculate the elapsed Tick  */
      MeasuredTicks = Timer_DelayGetTick() -  TimeOutCountInitial;

    } while (TimeOutCount > MeasuredTicks);

  }
  else
  {
      /*Dummy else for MISRA*/
  }
}
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */

/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
/*******************************************************************************
** Traceability      : [cover parentID={3EDE5110-6FEA-4a76-AF6E-0D82B833FAD1}]**
** Syntax : void Fls_lCallEraseCommand(const uint32 PhysicalAddress)          **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : PhysicalAddress                                          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine calls flash Erase command cycles                **
*******************************************************************************/
void Fls_lCallEraseCommand(const uint32 PhysicalAddress)
{

  Fls_lEraseCmdCycles(PhysicalAddress);

}

/*******************************************************************************
** Traceability   : [cover parentID={979BD858-458C-48e1-850D-E5F3DB61140D}]   **
** Syntax : void Fls_lCallWriteCommand(const uint32 PhysicalAddress,          **
**                       const Fls_17_Dmu_StateType *const StatePtr,          **
**                       const uint8 WriteMode)                               **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : PhysicalAddress, StatePtr, WriteMode                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine calls flash write command cycles                **
*******************************************************************************/
void Fls_lCallWriteCommand(const uint32 PhysicalAddress,
                          const Fls_17_Dmu_StateType *const StatePtr,
                          const uint8 WriteMode)
{
    Fls_lWriteCmdCycles(PhysicalAddress,
                StatePtr->FlsWriteAddress,
    /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast
      is required to interface with the Dflash as it supports burst operations
       as well.The access range would already be checked for validity
       is within the flash address range */
                (const Fls_17_Dmu_AddressType*)StatePtr->FlsWriteBufferPtr,
                WriteMode);
}

/*******************************************************************************
** Traceability     : [cover parentID={6F8BADF8-9CC5-4f39-B3CA-943359E4BB7A}] **
** Syntax : void Fls_lResetReadCmdCycle(void)                                 **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine contains flash Reset command cycles             **
*******************************************************************************/
void Fls_lResetReadCmdCycle(void)
{
  Fls_lCycle5554(FLS_17_DMU_BASE_ADDRESS, VALUE_F0);
}

/*******************************************************************************
** Traceability     : [cover parentID={03F78078-A11D-4d0e-907E-85646DED0A77}] **
** Syntax : void Fls_ClearStatusCmdCycle(void)                                **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine contains flash clear status command cycles      **
*******************************************************************************/
void Fls_lClearStatusCmdCycle(void)
{

  Fls_lCycle5554(FLS_17_DMU_BASE_ADDRESS, VALUE_FA);

}
#if (FLS_17_DMU_USE_ERASESUSPEND == STD_ON)
/*******************************************************************************
** Traceability   : [cover parentID={BC5F8267-E635-4f4b-93CD-BB9373DD3024}]   **
** Syntax : void Fls_ResumeEraseCmdCycle(const uint32 StartAddress)           **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StartAddress                                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine contains flash resume erase command cycles      **
*******************************************************************************/
void Fls_lResumeEraseCmdCycle(const uint32 EraseAddress)
{

  uint32 StartAddress;
  uint8 EraseNumSec;
  const Fls_17_Dmu_StateType* StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  EraseNumSec  = StatePtr->FlsEraseNumSecPerCmd;
  StartAddress = FLS_17_DMU_BASE_ADDRESS;

  /* cycle 1 */
  Fls_lCycleAA50(StartAddress, EraseAddress);
  /* cycle 2 */
  Fls_lCycleAA58(StartAddress, EraseNumSec);
  /* cycle 3 */
  Fls_lCycleAAA8(StartAddress, VALUE_70);
  /* cycle 4 */
  Fls_lCycleAAA8(StartAddress, VALUE_CC);
}
#endif /* FLS_17_DMU_USE_ERASESUSPEND == STD_ON */

/*******************************************************************************
** Traceability     : [cover parentID={05A73B74-EB36-4d6b-ACD6-BE0365197CE9}] **
** Syntax : void Fls_lUserContentCountCmdCycle(const uint32 WordLineAddress)  **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : WordLineAddress                                          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine contains user content count command cycles      **
*******************************************************************************/
void Fls_lUserContentCountCmdCycle(const uint32 WordLineAddress)
{
  uint16 TimeOutCount;
  uint16 TimeOutCountInitial;
  uint16 TimeOutResolution;
  uint16 MeasuredTicks;

  uint32 StartAddress;
  StartAddress = FLS_17_DMU_BASE_ADDRESS;
  /* cycle 1 */
  Fls_lCycleAA50(StartAddress, WordLineAddress);
  /* cycle 2 */
  Fls_lCycleAA58(StartAddress, VALUE_00);
  /* cycle 3 */
  Fls_lCycleAAA8(StartAddress, VALUE_60);
  /* cycle 4 */
  Fls_lCycleAAA8(StartAddress, VALUE_14);

  /*Wait for 100ns*/
  /* Get the Tick resolution */
  TimeOutResolution = Timer_DelayTickResolution();
  /* Calculate the Delay count */
  TimeOutCount = (uint16)FLS_17_DMU_HWBUSY_DELAY / TimeOutResolution;
  /* Get the Initial count */
  TimeOutCountInitial = Timer_DelayGetTick();

  do
  {
    /* Calculate the elapsed Tick  */
    MeasuredTicks = Timer_DelayGetTick() -  TimeOutCountInitial;

  } while (TimeOutCount > MeasuredTicks);

}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
** Traceability     : [cover parentID={5D6E9D51-CF9C-473e-A04B-49B186086D16}] **
**                                                                            **
** Syntax: LOCAL_INLINE boolean Fls_lCmdCycleTimeout(const uint32 InnerCount) **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : InnerCount - Delay count                                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : boolean                                                  **
**                                                                            **
** Description : This routine checks if command cycle timeout occured         **
*******************************************************************************/
LOCAL_INLINE boolean Fls_lCmdCycleTimeout(const uint32 InnerCount)
{
  boolean RetVal;

  if (InnerCount >= (uint32)FLS_17_DMU_CMDCYCLE_TIMEOUT)
  {
    RetVal = (boolean)TRUE;
  }
  else
  {
    RetVal = (boolean)FALSE;
  }
  return (RetVal);
}

/*******************************************************************************
** Traceability   : [cover parentID={2544FA01-8FBB-44f8-AA6B-23192E0792BF}]   **
** Syntax: LOCAL_INLINE void Fls_lCycle5554(const uint32 Address,             **
**                                                     const uint32 Data)     **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : Address, Data                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
** Description : cmd cycle formation                                          **
*******************************************************************************/
LOCAL_INLINE void Fls_lCycle5554(const uint32 Address, const uint32 Data)
{
  uint32 StartAddress;
  StartAddress = ((Address) & MASK_HIGHER4_NIBBLES) + CYCLE_5554;
  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
     is required to store the FLASH address/target address in state var
     structure to perform easy arithmethic operations. */
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
     type is required to access the FLASH address/target address which
     is defined as unsigned long. */
  *((volatile uint32*)StartAddress) = Data;
  DSYNC();
  return;
}

/*******************************************************************************
** Traceability     : [cover parentID={4B0DFE26-2619-48df-A703-CF8F905D71CF}] **
** Syntax: LOCAL_INLINE void CycleAAA8(const uint32 Address,                  **
**                                          const uint32 Data)                **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : Address, Data                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
** Description : cmd cycle formation                                          **
*******************************************************************************/
LOCAL_INLINE void Fls_lCycleAAA8(const uint32 Address, const uint32 Data)
{
  uint32 StartAddress;
  StartAddress = ((Address) & MASK_HIGHER4_NIBBLES) + CYCLE_AAA8;
  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
     is required to store the FLASH address/target address in state var
     structure to perform easy arithmethic operations. */
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
     type is required to access the FLASH address/target address which
     is defined as unsigned long. */
  *((volatile uint32*)StartAddress) = Data;
  DSYNC();
  return;
}

/*******************************************************************************
** Traceability     : [cover parentID={5E552EA7-13F9-4118-AF05-1CD567C573A9}] **
** Syntax: LOCAL_INLINE void CycleAA50(const uint32 Address,                  **
**                                          const uint32 Data)                **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : Address, Data                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
** Description : cmd cycle formation                                          **
*******************************************************************************/
LOCAL_INLINE void Fls_lCycleAA50(const uint32 Address, const uint32 Data)
{

  uint32 StartAddress;
  StartAddress = ((Address) & MASK_HIGHER4_NIBBLES) + CYCLE_AA50;
  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
     is required to store the FLASH address/target address in state var
     structure to perform easy arithmethic operations. */
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
     type is required to access the FLASH address/target address which
     is defined as unsigned long. */
  *((volatile uint32*)StartAddress) = Data;
  DSYNC();
  return;
}

/*******************************************************************************
**Traceability: [cover parentID={29FAE174-CA94-40b6-BA64-B2054A79A258}]       **
**Syntax: LOCAL_INLINE void CycleAA58(const uint32 Address, const uint32 Data)**
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : Address, Data                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
** Description : cmd cycle formation                                          **
*******************************************************************************/
LOCAL_INLINE void Fls_lCycleAA58(const uint32 Address, const uint32 Data)
{
  uint32 StartAddress;
  StartAddress = ((Address) & MASK_HIGHER4_NIBBLES) + CYCLE_AA58;
  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
     is required to store the FLASH address/target address in state var
     structure to perform easy arithmethic operations. */
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
     type is required to access the FLASH address/target address which
     is defined as unsigned long. */
  *((volatile uint32*)StartAddress) = Data;
  DSYNC();
  return;
}


/*******************************************************************************
** Traceability     : [cover parentID={D945F34C-7B95-428b-B9DF-AB23B2DF29CD}] **
** Syntax: LOCAL_INLINE void Fls_lEnterPageMode(const uint32 address,         **
**                                              const uint32 Data)            **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : address , Data                                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
** Description : cmd cycle formation                                          **
*******************************************************************************/
LOCAL_INLINE void Fls_lEnterPageMode(const uint32 Address, const uint32 Data)
{
  uint32 StartAddress;

  StartAddress = ((Address) & MASK_HIGHER4_NIBBLES) + CYCLE_5554;
  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
     is required to store the FLASH address/target address in state var
     structure to perform easy arithmethic operations. */
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
     type is required to access the FLASH address/target address which
     is defined as unsigned long. */
  *((volatile uint32*)StartAddress) = Data;
  DSYNC();

  return;
}

/*******************************************************************************
** Traceability   : [cover parentID={475D10EA-2B17-43ea-8CF5-F58EC1B1DBA9}] **
** Syntax: LOCAL_INLINE void Fls_lLoadPage(const uint32 Address,              **
**                                    const Fls_17_Dmu_AddressType* DataPtr)  **
**                                                                            **
** Service ID:                                                                **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : address                                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
** Description : cmd cycle formation                                          **
*******************************************************************************/
LOCAL_INLINE void Fls_lLoadPage(const uint32 Address,
                                const Fls_17_Dmu_AddressType* DataPtr)
{
  volatile Fls_17_Dmu_AddressType* StartAddress;
  StartAddress = (volatile Fls_17_Dmu_AddressType *)
    /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
       is required to store the FLASH address/target address in state var
       structure to perform easy arithmethic operations. */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
       type is required to access the FLASH address/target address which
       is defined as unsigned long. */
   /* MISRA2012_RULE_10_8_JUSTIFICATION: conversion between pointer and integer
       type is required to access the FLASH address/target address which
       is defined as unsigned long. */
               (((Address) & MASK_HIGHER4_NIBBLES) + CYCLE_55F0);

  *StartAddress = *DataPtr;
  DSYNC();
  /* Page assembly buffer pointer gets incremented automatically */
  /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
  array indexing used for page assembly buffer and for subsequent
  traversal.The access range is within the valid range.*/
  *(StartAddress + 1) = *(DataPtr + 1U);
  DSYNC();
  return;
}




/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
#define FLS_17_DMU_STOP_SEC_CODE_QM_LOCAL
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
   guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Fls_17_Dmu_MemMap.h"


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
/*!        \file  vMemAccM_AltvMem.c
 *        \brief  vMemAccM memory abstraction submodule source file
 *
 *      \details  See vMemAccM_AltvMem.h.
 *
 *********************************************************************************************************************/

#define VMEMACCM_ALTVMEM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMemAccM.h"
#include "vMemAccM_AltvMem.h"
#include "vMemAccM_Sched.h"
#include "vMemAccM_CfgAb.h"
#include "vMemAccM_MemAb.h"
#include "vMemAccM_IntCfg.h"

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

#if (VMEMACCM_USE_DOWNLOADABLE_VMEM == STD_ON)

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! Combined length of the header, header pointer and footer pointer within a vMem function pointer table in bytes */
#define VMEMACCM_LENGTH_OF_VMEM_INFO  (sizeof(vMemAccM_vMemHeaderType) + sizeof(vMemAccM_vMemHeaderPtrType) + sizeof(vMemAccM_vMemFooterPtrType))

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (VMEMACCM_LOCAL) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL static
#endif

#if !defined (VMEMACCM_LOCAL_INLINE) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* It is necessary that the first three members of the following structure (Header, HeaderPtr, FooterPtr) match with
   the first three members of the vMem Function pointer table (vMemAccM_vMemApiType) */
typedef struct
{
  vMemAccM_vMemHeaderType           Header;            /*!< Alternate vMem header. */ 
  vMemAccM_vMemHeaderPtrType        HeaderPtr;         /*!< Pointer to alternate vMem header. */ 
  vMemAccM_vMemFooterPtrType        FooterPtr;         /*!< Pointer to alternate vMem footer. */ 
  vMemAccM_AddressType              Address;           /*!< Forwarded Address at which alternate vMem shall be located. */ 
  vMemAccM_LengthType               Length;            /*!< Forwarded Length of alternate vMem. */ 
  vMemAccM_AddressAreaIdType        SubAddressAreaId;  /*!< Forwarded SubAddressAreaID at which alternate vMem shall be located. */ 
  vMemAccM_vMemPointerTableIterType vMemPtrTableIdx;   /*!< Index at which alternate related pre-configured vMem is located. */ 
} vMemAccM_AltvMemType;                                /*!< Stores information about the alternate vMem */
/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Holds information about the alternate vMem */
VMEMACCM_LOCAL VAR(vMemAccM_AltvMemType, VMEMACCM_VAR_NOINIT) vMemAccM_AltvMem;

#define VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VMEMACCM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMemAccM_AltvMemActivation
 *********************************************************************************************************************/
/*!
 * \brief       Activate an alternate vMem.
 * \details     -
 * \return      E_OK activation was successfull;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_AltvMemActivation(void);

/**********************************************************************************************************************
 *  vMemAccM_AltvMemDeactivation
 *********************************************************************************************************************/
/*!
 * \brief       Deactivate an alternate vMem.
 * \details     -
 * \return      E_OK deactivation was successfull;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_AltvMemDeactivation(void);

/**********************************************************************************************************************
 *  vMemAccM_AltvMemReadHdrAndFtrPtr
 *********************************************************************************************************************/
/*!
 * \brief       Read out the alternate vMem header,header pointer and footer pointer.
 * \details     Set up and process the corresponding read request.
 * \return      E_OK header, header pointer and footer pointer were successfully read out and set within internal structure;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_AltvMemReadHdrAndFtrPtr(void);

/**********************************************************************************************************************
 *  vMemAccM_AltvMemVerify
 *********************************************************************************************************************/
/*!
 * \brief       Execute several checks to verify the alternate vMem.
 * \details     -
 * \return      E_OK verification was successfull;
 *              E_NOT_OK otherwise.
 * \pre         Header and Trailer information of alternate vMem was read out and set.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_AltvMemVerify(void);

/**********************************************************************************************************************
 *  vMemAccM_AltvMemFindConfiguredvMem
 *********************************************************************************************************************/
/*!
 * \brief       Find the pre-configured vMem corresponding to the alternate vMem.
 * \details     -
 * \return      E_OK activation was successfull;
 *              E_NOT_OK otherwise.
 * \pre         Header and Trailer information of alternate vMem was read out and set.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_AltvMemFindConfiguredvMem(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_AltvMemActivation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_AltvMemActivation(void)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (vMemAccM_AltvMemReadHdrAndFtrPtr() == E_OK)
  {
    if (vMemAccM_AltvMemFindConfiguredvMem() == E_OK)
    {
      if (vMemAccM_AltvMemVerify() == E_OK)
      {
        /* PRQA S 0310 2 */  /* MD_vMemAccM_Uint32PtrToConstvMemApiPtrTypeCast */
        vMemAccM_MemAbSetAlternatevMemPtrTable(vMemAccM_AltvMem.vMemPtrTableIdx, /* SBSW_vMemAccM_AlternatevMemPointerTable */
                                              (vMemAccM_ConstvMemApiPtrType) vMemAccM_AltvMem.HeaderPtr);
        vMemAccM_MemAbInit(vMemAccM_AltvMem.vMemPtrTableIdx);

        retVal = E_OK; 
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vMemAccM_AltvMemDeactivation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_AltvMemDeactivation(void)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* Read also footer pointer for code reusability. Shall not have any impact on performance. 
     Reading the header is necessary to ensure the correct alternate vMem is deactivated. 
     Different vMems are stored within a RAM buffer, so checking which one is active
     is necessary. */
  if (vMemAccM_AltvMemReadHdrAndFtrPtr() == E_OK)
  {
    if (vMemAccM_AltvMemFindConfiguredvMem() == E_OK)
    {
      vMemAccM_MemAbResetAlternatevMemPtrTable(vMemAccM_AltvMem.vMemPtrTableIdx);
      vMemAccM_MemAbInit(vMemAccM_AltvMem.vMemPtrTableIdx); /* Pre-configured vMem is implicitly initialized */

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vMemAccM_AltvMemReadHdrAndFtrPtr
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_AltvMemReadHdrAndFtrPtr(void)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* Calculate the offset within the sub address area (= virtual job start address - virtual sub address area start address).
   * No need to adjust the calculated length to the configured maximum read length as job is part of a synchronous request.
   * No need to check against SubAddressArea border as self-contained function pointer table shall be placed in one SubAddressArea */
  vMemAccM_AddressType addressOffset = vMemAccM_AltvMem.Address 
                                       - vMemAccM_GetVirtualStartAddressOfSubAddressArea(vMemAccM_AltvMem.SubAddressAreaId);
  vMemAccM_LengthType expectedLength = VMEMACCM_LENGTH_OF_VMEM_INFO;
  vMemAccM_LengthType readLength = 0u;
  vMemAccM_MemAbRead( /* SBSW_vMemAccM_LocalDataPointer */
      vMemAccM_AltvMem.SubAddressAreaId,
      addressOffset,
      &vMemAccM_AltvMem,    /* PRQA S 0315 */ /* MD_vMemAccM_VoidPtrTypedPtrAltvMem */
      expectedLength,
      &readLength, 
      VMEMACCM_LENGTH_OF_VMEM_INFO);
  if(readLength == expectedLength)
  {
    vMemAccM_JobResultType jobResult = VMEMACCM_JOB_PENDING;

    while(jobResult == VMEMACCM_JOB_PENDING)
    {
      jobResult = vMemAccM_MemAbProcessing(vMemAccM_AltvMem.SubAddressAreaId);
    }

    if((jobResult == VMEMACCM_JOB_OK) || (jobResult == VMEMACCM_READ_CORRECTED_ERRORS))
    {
      /* The read out header and footer information will be only used later if read request is also successfull */
      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vMemAccM_AltvMemVerify
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_AltvMemVerify(void)
{
  Std_ReturnType retVal = E_NOT_OK;

  if(vMemAccM_AltvMem.FooterPtr > vMemAccM_AltvMem.HeaderPtr)
  {
    /* PRQA S 0488 3 */ /* MD_vMemAccM_AltvMemPointerArithmetic */
    const vMemAccM_LengthType vMemLength =  
        /* Pointer arithmetic: To get the difference in bytes it must be multiplied by its structural length */
        (((vMemAccM_LengthType) (vMemAccM_AltvMem.FooterPtr - vMemAccM_AltvMem.HeaderPtr)) * sizeof(vMemAccM_vMemHeaderType)) 
        + sizeof(vMemAccM_vMemFooterType);
    
    if(vMemAccM_AltvMem.Length >= vMemLength)
    {
      if(*vMemAccM_AltvMem.HeaderPtr == vMemAccM_AltvMem.Header)
      {
        if(*vMemAccM_AltvMem.FooterPtr == vMemAccM_AltvMem.Header)
        {
          retVal = E_OK;
        }
      }
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vMemAccM_AltvMemFindConfiguredvMem
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_AltvMemFindConfiguredvMem(void)
{
  vMemAccM_vMemPointerTableIterType vMemIndex;
  Std_ReturnType retVal = E_NOT_OK;

  for(vMemIndex = 0u; vMemIndex < vMemAccM_GetSizeOfvMemPointerTable(); vMemIndex++)
  {
    if(vMemAccM_GetvMemPointerTable(vMemIndex)->Header == vMemAccM_AltvMem.Header)
    {
      vMemAccM_AltvMem.vMemPtrTableIdx = vMemIndex;
      retVal = E_OK;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_ActivatevMem
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
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_ActivatevMem
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_LengthType Length
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else if (vMemAccM_CfgAbAddressAndLengthValid(AddressAreaId, Address, Length) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_LENGTH;
  }
  else
#endif
  {
    if(vMemAccM_SchedIsAnyAddressAreaPending() == FALSE)
    {
      vMemAccM_AltvMem.SubAddressAreaId = vMemAccM_CfgAbGetSubAddrAreaId(AddressAreaId, Address);
      vMemAccM_AltvMem.Address = Address;
      vMemAccM_AltvMem.Length = Length;

      if(vMemAccM_CfgAbIsAddressRangeInSubAddressArea(
          vMemAccM_AltvMem.SubAddressAreaId, 
          Address, 
          Length))
      {
        retVal = vMemAccM_AltvMemActivation();
      }
    }
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_ACTIVATE_VMEM, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL , MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vMemAccM_DeactivatevMem
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
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_DeactivatevMem
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_LengthType Length
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else if (vMemAccM_CfgAbAddressAndLengthValid(AddressAreaId, Address, Length) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_LENGTH;
  }
  else
#endif
  {
    if(vMemAccM_SchedIsAnyAddressAreaPending() == FALSE)
    {
      vMemAccM_AltvMem.SubAddressAreaId = vMemAccM_CfgAbGetSubAddrAreaId(AddressAreaId, Address);
      vMemAccM_AltvMem.Address = Address;
      vMemAccM_AltvMem.Length = Length;

      retVal = vMemAccM_AltvMemDeactivation();
    }
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_DEACTIVATE_VMEM, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL , MD_MSR_STMIF */


#define VMEMACCM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VMEMACCM_USE_DOWNLOADABLE_VMEM == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_AltvMem.c
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file
 *        \brief  Wrapper between vMem and His Interface
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define FBL_MEM2HIS

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "fbl_inc.h"
#include "fbl_mem2His.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of fbl_mem2His header file */
#if (  (FBL_MEM2HIS_MAJOR_VERSION != (4u)) \
    || (FBL_MEM2HIS_MINOR_VERSION != (1u)) \
    || (FBL_MEM2HIS_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of fbl_mem2His.c and fbl_mem2His.h are inconsistent"
#endif

/* Check the version of vMemAccM_vMemApi file */
#if (  (VMEMACCM_VMEMAPI_MAJOR_VERSION != (4u)) \
    || (VMEMACCM_VMEMAPI_MINOR_VERSION != (0u)) )
# error "Version numbers of fbl_mem2His.c and vMemAccM_vMemApi.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! The lower 20-bits of the generated identifier is the used as the unique driver identifier. */
#define VMEM_30_MEM2HIS_ID_MASK_VALUE  0x000FFFFFuL

/*! Unique identifier of the vMem based on the below identifiers.
 * VMEMACCM_VMEMAPI_MAJOR_VERSION -> vMemAccM to vMem interface version.
 * VMEM_30_MEM2HIS_DRIVER_ID -> Unique vMem driver identifier.
 */
#define VMEM_30_MEM2HIS_UNIQUEID    ((uint32)((VMEMACCM_VMEMAPI_MAJOR_VERSION << 24u) | (VMEM_30_MEM2HIS_DRIVER_ID & VMEM_30_MEM2HIS_ID_MASK_VALUE)))

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#define vMem2His_HisReadFct(buf, len, addr)        (*memDrvLst[InstanceId].read)((buf), (len), (addr))
#define vMem2His_HisWriteFct(buf, len, addr)       (*memDrvLst[InstanceId].write)((buf), (len), (addr))
#define vMem2His_HisEraseFct(len, addr)            (*memDrvLst[InstanceId].erase)((len), (addr))

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (FBL_MEM2HIS_LOCAL)
# define FBL_MEM2HIS_LOCAL static
#endif

#if !defined (FBL_MEM2HIS_LOCAL_INLINE)
# define FBL_MEM2HIS_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define FBL_MEM2HIS_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FBL_MEM2HIS_LOCAL VAR(vMemAccM_vMemJobResultType, FBL_MEM2HIS_VAR_NOINIT)  mem2His_currentJobResult;
FBL_MEM2HIS_LOCAL VAR(IO_ErrorType, FBL_MEM2HIS_VAR_NOINIT)                mem2His_lastMemDriverResult;

#define FBL_MEM2HIS_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define FBL_MEM2HIS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(vMemAccM_vMemApiType, AUTOMATIC) vMem_30_Fbl_FunctionPointerTable = {
   VMEM_30_MEM2HIS_UNIQUEID,  /* PRQA S 0499 */ /* MD_FblMio_FalseFinding */
   &vMem_30_Fbl_FunctionPointerTable.Header,
   &vMem_30_Fbl_FunctionPointerTable.Header,
  {
    0,
    NULL_PTR
  },
  &vMem2His_Init,
  &vMem2His_Read,
  &vMem2His_Write,
  &vMem2His_Erase,
  &vMem2His_IsBlank,
  &vMem2His_GetJobResult,
  &vMem2His_MainFunction
};

#define FBL_MEM2HIS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FBL_MEM2HIS_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  vMem2His_Init
 **********************************************************************************************************************/
void vMem2His_Init(vMemAccM_vMemConfigPtrType cfg)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)cfg;
#endif
   /* Do nothing, initialization is handled from flash block table */
}

/***********************************************************************************************************************
 *  vMem2His_Read
 **********************************************************************************************************************/
Std_ReturnType vMem2His_Read(vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemAddressType SourceAddress, vMemAccM_vMemDataPtrType TargetAddressPtr, vMemAccM_vMemLengthType Length)
{
   IO_ErrorType currentMemDriverResult;

   mem2His_currentJobResult = VMEM_JOB_PENDING;
   /* PRQA S 0316 1 */ /* MD_FblMio_Dir1.1_0316_VoidPtrTypedPtr */
   currentMemDriverResult   = vMem2His_HisReadFct((IO_MemPtrType)(TargetAddressPtr), (IO_SizeType)(Length), (IO_PositionType)(SourceAddress));

   if (IO_E_OK == currentMemDriverResult)
   {
      /* At least one page was successfully read, set global variable to OK */
      mem2His_lastMemDriverResult = currentMemDriverResult;
      mem2His_currentJobResult = VMEM_JOB_OK;
   }
   else if (IO_E_ERASED == currentMemDriverResult)
   {
      /* Global variable already contains ERASED */
      mem2His_currentJobResult = VMEM_JOB_OK;
   }
   else
   {
      /* At least one page was not successfully read, set global variable to NOT_OK */
      mem2His_lastMemDriverResult = currentMemDriverResult;
      mem2His_currentJobResult = VMEM_JOB_FAILED;
   }

   return E_OK;
}

/***********************************************************************************************************************
 *  vMem2His_Write
 **********************************************************************************************************************/
Std_ReturnType vMem2His_Write(vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemAddressType TargetAddress, vMemAccM_vMemConstDataPtrType SourceAddressPtr, vMemAccM_vMemLengthType Length)
{
   mem2His_currentJobResult      = VMEM_JOB_PENDING;
   /* PRQA S 0316, 0311 1 */ /* MD_FblMio_Dir1.1_0316_VoidPtrTypedPtr, MD_FblMio_0311_LossOfConst */
   mem2His_lastMemDriverResult   = vMem2His_HisWriteFct((IO_MemPtrType)(SourceAddressPtr), (IO_SizeType)(Length), (IO_PositionType)(TargetAddress));

   if (IO_E_OK == mem2His_lastMemDriverResult)
   {
      mem2His_currentJobResult = VMEM_JOB_OK;
   }
   else
   {
      mem2His_currentJobResult = VMEM_JOB_FAILED;
   }

   return E_OK;
}

/***********************************************************************************************************************
 *  vMem2His_Erase
 **********************************************************************************************************************/
Std_ReturnType vMem2His_Erase(vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemAddressType TargetAddress, vMemAccM_vMemLengthType Length)
{
   mem2His_currentJobResult      = VMEM_JOB_PENDING;
   mem2His_lastMemDriverResult   = vMem2His_HisEraseFct((IO_SizeType)(Length), (IO_PositionType)(TargetAddress));

   if (IO_E_OK == mem2His_lastMemDriverResult)
   {
      mem2His_currentJobResult = VMEM_JOB_OK;
   }
   else
   {
      mem2His_currentJobResult = VMEM_JOB_FAILED;
   }

   return E_OK;
}

/***********************************************************************************************************************
 *  vMem2His_IsBlank
 **********************************************************************************************************************/
Std_ReturnType vMem2His_IsBlank(vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemAddressType TargetAddress, vMemAccM_vMemLengthType Length)
{
   (void)InstanceId;
   (void)TargetAddress;
   (void)Length;

   /* Return always "not blank" as HIS flash drivers don't support blank check */
   mem2His_currentJobResult      = VMEM_MEM_NOT_BLANK;
   mem2His_lastMemDriverResult   = IO_E_NOT_OK;

   return E_OK;
}

/***********************************************************************************************************************
 *  vMem2His_GetJobResult
 **********************************************************************************************************************/
vMemAccM_vMemJobResultType vMem2His_GetJobResult(vMemAccM_vMemInstanceIdType InstanceId)
{
   (void)InstanceId;

   return mem2His_currentJobResult;
}

/***********************************************************************************************************************
 *  vMem2His_MainFunction
 **********************************************************************************************************************/
void vMem2His_MainFunction(void)
{
   /* Do nothing, main function is needed by vMemAccM but HIS driver does not execute in main function */
}

/***********************************************************************************************************************
 *  vMem2His_ClrLastMemDriverResult
 **********************************************************************************************************************/
void vMem2His_ClrLastMemDriverResult( void )
{
   /* Reset variable to ERASED, will be overwritten to OK if one page is not erased or NOT_OK if one page could not
    * be read successfully */
   mem2His_lastMemDriverResult = IO_E_ERASED;
}

/***********************************************************************************************************************
 *  vMem2His_GetLastMemDriverResult
 **********************************************************************************************************************/
IO_ErrorType vMem2His_GetLastMemDriverResult( void )
{
   return mem2His_lastMemDriverResult;
}

#define FBL_MEM2HIS_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:

   MD_FblMio_Dir1.1_0316_VoidPtrTypedPtr:
      Reason:     vMemAccM use untyped void pointers for user buffers.
      Risk:       No risk. Underlying uint8 pointer type is known.
      Prevention: Component tests ensures that the accesses to RAM buffers are done correctly.

   MD_FblMio_0311_LossOfConst:
      Reason:     vMem driver API and HIS driver API differs in usage of const for data buffer.
      Risk:       No risk. API is fix and cannot be changed, but the source buffer for write is not allowed to be modified in HIS API, too.
      Prevention: Component tests and reviews ensures that the accesses to RAM buffers are done correctly.

   MD_FblMio_FalseFinding:
      Reason:     Finding by QAC was evaluated manually and identified as false finding.
      Risk:       No risk.
      Prevention: None.
*/

/**********************************************************************************************************************
 *  END OF FILE: Msn.c
 *********************************************************************************************************************/

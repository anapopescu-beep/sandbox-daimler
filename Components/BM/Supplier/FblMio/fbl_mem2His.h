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
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2018-06-21  visrr   -             Initial version
 *  01.00.01  2019-02-06  viskjs  ESCAN00102006 Compiler error: Function prototype is missing void type
 *  01.00.02  2019-03-07  visrr   ESCAN00102175 Add AUTOSAR encapsulation to the variables in the fbl_mem2His component
 *                                              Add version defines and version check
 *                                              Add MISRA deviations
 *  01.01.00   2019-06-04 visrr   ESCAN00103325 Add support for single memory device configurations
 *  02.00.00   2019-08-13 visrie  ESCAN00103195 Fixed flash erase detection handling
 *  03.00.00   2020-05-25 visrie  FBL-1883      Added support for blank check (new vMemAccM API)
 *                                              Removed single memory driver handling
 *  04.00.00   2021-08-03 vishor  FBL-2475      Add support for downloadable vMem driver
 *  04.01.00   2021-10-29 visrie  FBL-3983      Update to new unique ID format
 *********************************************************************************************************************/

#if !defined (FBL_MEM2HIS_H)
#define FBL_MEM2HIS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMemAccM_vMemApi.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ----- Component version information (decimal version of ALM implementation package) ----- */
#define FBL_MEM2HIS_MAJOR_VERSION                    (4u)
#define FBL_MEM2HIS_MINOR_VERSION                    (1u)
#define FBL_MEM2HIS_PATCH_VERSION                    (0u)

#if !defined( VMEM_30_MEM2HIS_DRIVER_ID )
# define VMEM_30_MEM2HIS_DRIVER_ID                   (0x00031013uL)    /*!< Unique identifier for vMem_30_mem2His. */
#endif /* !VMEM_30_MEM2HIS_DRIVER_ID */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define FBL_MEM2HIS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(vMemAccM_vMemApiType, AUTOMATIC) vMem_30_Fbl_FunctionPointerTable;

#define FBL_MEM2HIS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define FBL_MEM2HIS_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Common vMemApi functions
 *********************************************************************************************************************/
/*!
 * \details     The following functions represent the implementation of the vMemApi API described in vMemAccM_vMemApi.h
 *              Please check the mentioned header for a detailed description of the API, its functionality as well as
 *              pre and post conditions.
 */
void vMem2His_Init(vMemAccM_vMemConfigPtrType cfg);
Std_ReturnType vMem2His_Read(vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemAddressType SourceAddress, vMemAccM_vMemDataPtrType TargetAddressPtr, vMemAccM_vMemLengthType Length);
Std_ReturnType vMem2His_Write(vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemAddressType TargetAddress, vMemAccM_vMemConstDataPtrType SourceAddressPtr, vMemAccM_vMemLengthType Length);
Std_ReturnType vMem2His_Erase(vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemAddressType TargetAddress, vMemAccM_vMemLengthType Length);
Std_ReturnType vMem2His_IsBlank(vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemAddressType TargetAddress, vMemAccM_vMemLengthType Length);
vMemAccM_vMemJobResultType vMem2His_GetJobResult(vMemAccM_vMemInstanceIdType InstanceId);
void vMem2His_MainFunction(void);

/**********************************************************************************************************************
 *  vMem2His_ClrLastMemDriverResult
 *********************************************************************************************************************/
/*!
 * \brief       Helper function to reset the global result variable.
 * \details     The variable is initialized to IO_E_ERASED and gets overwritten with the value IO_E_OK or IO_E_NOT_OK.
 */
void vMem2His_ClrLastMemDriverResult(void);

/**********************************************************************************************************************
 *  vMem2His_GetLastMemDriverResult
 *********************************************************************************************************************/
/*!
 * \brief       Helper function to transport IO_E_ERASED return value to upper layer.
 * \details     vMemAccM only knows AUTOSAR standard return values E_OK and E_NOT_OK. The HIS read function returns
 *              OK, NOT_OK and ERASED (which is simply OK, but the memory seems to erased). The last state is important
 *              for presence pattern mechanism and shall not got lost. So if an upper layer see the OK it request
 *              last result with this function.
 * \pre         vMem2His_ClrLastMemDriverResult was called.
 * \return      Last read return value
 */
IO_ErrorType vMem2His_GetLastMemDriverResult(void);

#define FBL_MEM2HIS_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FBL_MEM2HIS_H */

/**********************************************************************************************************************
 *  END OF FILE: fbl_mem2His.h
 *********************************************************************************************************************/

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
/*!        \file  vMem_30_Tc3xxInf01_Extended_Func.h
 *        \brief  vMem_30_Tc3xxInf01 public header file containing types and declarations of the hardware specific functionality.
 *
 *      \details  This file contains the types and declarations of the hardware specific functionality of vMem_30_Tc3xxInf01.
 *                It should be included by every user, that wants to call a hardware specific API.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_TC3XXINF01_EXTENDED_FUNC_H)
# define VMEM_30_TC3XXINF01_EXTENDED_FUNC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vMem_30_Tc3xxInf01_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*!< Service ID: vMem_30_Tc3xxInf01_GetActiveAddressRegion() */
# define VMEM_30_TC3XXINF01_SID_GET_ACTIVE_ADDRESS_REGION          (0xF0u)
/*!< Service ID: vMem_30_Tc3xxInf01_ReplaceLogicalSector() */
# define VMEM_30_TC3XXINF01_SID_REPLACE_LOGICAL_SECTOR             (0xF2u)
/*!< Service ID: vMem_30_Tc3xxInf01_GetLastErrorState() */
# define VMEM_30_TC3XXINF01_SID_GET_LAST_ERROR_STATE               (0xF3u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  VMEM_30_TC3XXINF01_ADDRESS_REGION_A = 0,   /*!< Address region A is active (B is inactive). */
  VMEM_30_TC3XXINF01_ADDRESS_REGION_B        /*!< Address region B is active (A is inactive). */
} vMem_30_Tc3xxInf01_AddressRegionType;      /*!< Indicates which group of banks is currently active. */

typedef enum
{
  VMEM_30_TC3XXINF01_ACTIVE_ADDRESS_REGION = 0,  /*!< Id for vMem_30_Tc3xxInf01_GetActiveAddressRegion. */
  VMEM_30_TC3XXINF01_REPLACE_LOGICAL_SECTOR,     /*!< Id for vMem_30_Tc3xxInf01_ReplaceLogicalSector. */
  VMEM_30_TC3XXINF01_GET_LAST_ERROR_STATE        /*!< Id for vMem_30_Tc3xxInf01_GetLastErrorState. */
} vMem_30_Tc3xxInf01_HWSpecificFuncID;           /*!< Numeric identifier for HW specific functionality:
                                                      index in function pointer table. */

typedef enum
{
  VMEM_30_TC3XXINF01_NO_REDUNDANT_SECTOR_AVAILABLE = 0,   /*!< No redundant sector is available. */
  VMEM_30_TC3XXINF01_SECTOR_IS_REPLACEMENT_SECTOR,        /*!< Sector is replacement sector. */
  VMEM_30_TC3XXINF01_SECTOR_REPLACEABLE                   /*!< Sector can be replaced. */
} vMem_30_Tc3xxInf01_RedundantSectorInfoType;             /*!< Indicates if sector is replaceable or why not. */

typedef enum
{
  VMEM_30_TC3XXINF01_NO_JOB,
  VMEM_30_TC3XXINF01_WRITE_JOB,
  VMEM_30_TC3XXINF01_READ_JOB,
  VMEM_30_TC3XXINF01_ERASE_JOB,
  VMEM_30_TC3XXINF01_ISBLANK_JOB,
  VMEM_30_TC3XXINF01_REPLACE_JOB
} vMem_30_Tc3xxInf01_JobType;  /*!< Indicates which asynchronous job shall be performed next. */

typedef struct
{
  vMem_30_Tc3xxInf01_AddressType TargetAddress;   /*!< Start address of the sector that shall be replaced. */
  vMem_30_Tc3xxInf01_RedundantSectorInfoType RedundantSectorInfo; /*!< Indicates if sector is replaceable or why not. */
} vMem_30_Tc3xxInf01_ReplaceSectorType;           /*!< Hardware specific structure for
                                                        vMem_30_Tc3xxInf01_ReplaceLogicalSector. */

typedef struct 
{
  vMem_30_Tc3xxInf01_JobType currentJob;              /*!< Indicated the last job, which was executed */
  vMem_30_Tc3xxInf01_AddressType currentErrorState;   /*!< Indicated the current error states */
} vMem_30_Tc3xxInf01_ErrorStateType;                  /*!< Hardware specific structure for vMem_30_Tc3xxInf01_GetLastErrorState */

typedef P2VAR(vMem_30_Tc3xxInf01_ReplaceSectorType, AUTOMATIC, VMEM_30_TC3XXINF01_APPL_VAR) vMem_30_Tc3xxInf01_ReplaceSectorPtrType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VMEM_30_TC3XXINF01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetActiveAddressRegion()
 *********************************************************************************************************************/
/*! \brief       Returns the currently active address region. NOTE: this service should be called via the HwSpecificReq API
 *               of the vMemAccM. The corresponding function index is VMEM_30_TC3XXINF01_ACTIVE_ADDRESS_REGION.
 *  \details     Via this service the user can obtain the information which address region is currently active. An address
 *               region is a group of PFLASH banks. An active PFLASH bank is currently used for code execution by the running application.
 *               In case of AURIXTC39x address region A consists of PFLASH0, PFLASH1 and PFLASH4.
 *               Address region B consists of the remaining banks PFLASH2, PFLASH3 and PFLASH5.
 *  \param[in]   InstanceId          ID of the related vMem instance.
 *  \param[in,out]   ReqSpecificData     Pointer to a variable of type vMem_30_Tc3xxInf01_AddressRegionType.
 *                                       Contains the information about active address region on return.
 *  \param[in]   SizeOfData          Not needed for this request.
 *  \return      E_OK request accepted, E_NOT_OK otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-159272
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetActiveAddressRegion(
    vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
    vMem_30_Tc3xxInf01_DataPtrType ReqSpecificData,
    uint32 SizeOfData
    );

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_ReplaceLogicalSector()
 *********************************************************************************************************************/
/*!
 * \brief      This service replaces a logical sector. NOTE: this service should be called via the HwSpecificReq
 *             API of the vMemAccM. The corresponding function index is VMEM_30_TC3XXINF01_REPLACE_LOGICAL_SECTOR.
 * \details    Via this service the user can replace a (failing) logical sector. It is up to the user to decide, if and
 *             when a sector should be replaced. The vMem_30_Tc3xxInf01 first checks, whether the requested sector
 *             is replaceable (a sector can only be replaced, if it is not already a replacement sector, and if
 *             there is still a redundant sector available). If this is not the case the job result is JOB_FAILED.
 * \param[in]       InstanceId          ID of the related vMem instance.
 * \param[in, out]  ReqSpecificData     Pointer to a variable of type vMem_30_Tc3xxInf01_ReplaceSectorType.
 *                                 Contains the address of the sector which shall be replaced.
 *                                 After job is processed contains information, if sector is replaceable, or why not.
 * \param[in]  SizeOfData          Size of ReqSpecificData in this case size of vMem_30_Tc3xxInf01_ReplaceSectorType.
 * \return     E_OK request accepted, E_NOT_OK otherwise.
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous FALSE
 * \trace       CREQ-203234
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_ReplaceLogicalSector(
    vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
    vMem_30_Tc3xxInf01_DataPtrType ReqSpecificData,
    uint32 SizeOfData
    );

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetLastErrorState()
 *********************************************************************************************************************/
/*!
 * \brief      This service gets the content of the flash peripheral error register. NOTE: this service should be called
 *             via the HwSpecificReq API of the vMemAccM. The corresponding function index is 
 *             VMEM_30_TC3XXINF01_GET_LAST_ERROR_STATE.
 * \details    Via this service the user can check for detailed errors when the vMem reported the generic error state 
 *             VMEM_JOB_FAILED to the user. This service reports always the latest error state of the last job. A possible 
 *             use case is to check for different error condition when implementing the replace logical sectior feature.
 * \param[in]   InstanceId          ID of the related vMem instance.
 * \param[out]  ReqSpecificData     Pointer to a variable of type vMem_30_Tc3xxInf01_ErrorStateType.
 *                                  After job is processed contains information which job was processed and which error 
 *                                  occurred.
 * \param[in]  SizeOfData           Size of ReqSpecificData in this case size of vMem_30_Tc3xxInf01_ErrorStateType.
 * \return     E_OK request accepted, E_NOT_OK otherwise.
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 * \trace       CREQ-227131
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetLastErrorState(
    vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
    vMem_30_Tc3xxInf01_DataPtrType ReqSpecificData,
    uint32 SizeOfData
    );

# define VMEM_30_TC3XXINF01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VMEM_30_TC3XXINF01_EXTENDED_FUNC_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Tc3xxInf01_Extended_Func.h
 *********************************************************************************************************************/

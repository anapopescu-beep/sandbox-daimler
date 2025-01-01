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
/*!        \file  vMemAccM.h
 *        \brief  vMemAccM header file
 *
 *      \details  Vector Memory Access Manager synchronizes access NV RAM between several users. It allows to configure
 *                virtual address areas and to map these areas to different NV devices (multiple per address are
 *                possible), so the user does not have to care about data spreading and storage, but just work on
 *                virtual addresses.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author          Change Id                Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2018-02-21  viroto          FEAT-3242/ STORY-3379    Implement basic functionality of Memory Access Manager.
 *  02.00.00  2018-04-03  viroto          FEAT-3242/ STORY-3380    Support hardware specific features.
 *                                        -                        Added exclusive areas to critical sections.
 *  02.00.01  2018-05-07  viroto          ESCAN00099323            Missing MemMap section specifications.
 *  02.00.02  2018-06-11  viroto          ESCAN00099233            BETA version - the vMemAccM module is in BETA state
 *  02.01.00  2018-09-24  virchl          STORY-7825/ STORYC-4408  Support write and erase burst in vMemAccM
 *            2018-10-25  vircre          ESCAN00100969            vMemAccM executes a hardware specific request multiple times.
 *  02.02.00  2019-01-15  viroto          STORY-9128/ STORYC-7262  vMemAccM shall provide information about currently processed job.
 *                                                                 Internal improvements (CDD, naming, MISRA, SilentBSW, Queue).
 *  02.03.00  2019-01-22  viroto vircre   STORY-9427/ STORYC-7272  Support address area mapping variants.
 *  02.04.00  2019-02-01  viroto vircre   STORY-8665/ STORYC-6915  vMemAccM shall retry a failed write job.
 *                                        STORY-9253/ STORYC-7266  vMemAccM shall retry a failed erase job.
 *  02.05.00  2019-02-28  viroto          STORY-9456/ STORYC-7286  vMemAccM shall evaluate ECC error results returned by vMem.
 *  02.06.00  2019-07-02  viroto          STORY-12777/ STORYC-8551 vMemAccM shall provide a service to get notified about ECC errors
 *                                        ESCAN00103374            Compiler error: Undefined symbols of Compiler abstraction in
 *                                                                 vMemAccM_Types.h (included in vMemAccM.h)
 *  03.00.00  2019-07-25  viroto          MWDG-120                 vMemAccM shall provide a service to check a specific NV RAM
 *                                                                 address space to be blank/ erased.
 *  03.00.01  2019-10-29  viroto          ESCAN00102322            vMemAccM_HwSpecificReq accepts data size 0 but does not accept data pointer == NULL_PTR
 *  03.01.00  2020-04-02  viroto virljs   MWDG-2643                Introduce a job scheduler sub module
 *                                        MWDG-2917                Implement the access synchronization in a multi core system
 *  03.01.01  2020-04-17  viroto          ESCAN00106113            Compiler error/ Linker error: unresolved external symbol _vMemAccM_CfgAbHwFuncIndexValid/
 *                                                                 _vMemAccM_CfgAbHwIdValid referenced in function _vMemAccM_HwSpecificReq
 *  04.00.00  2020-05-19  viroto          MWDG-3139                vMemAccM shall cancel an ongoing job according to AUTOSAR
 *  05.00.00  2020-08-31  virljs          MWDG-3510                vMemAccM shall provide an ECC safe read service
 *  05.01.00  2020-10-06  viroto          MWDG-3291                vMemAccM shall distinguish between failed compare request and unequal data
 *  05.01.01  2020-12-21  viroto          ESCAN00108029            Compiler warning: declaration may not appear after executable statement in block/ ISO C90 forbids mixed declarations and code
 *  05.02.00  2021-01-26  viroto          MWDG-4753                vMemAccM shall synchronize NV RAM access on multi core system via satellites
 *            2021-02-19  virljs          MWDG-4751                vMemAccM shall prevent access to NV RAM via API
 *  05.02.01  2021-03-19  virljs          MWDG-5006                vMemAccM shall use one single way how to access shared RAM variables for all multi partition use cases.
 *  05.02.01  2021-03-23  virljs          ESCAN00108754            vMemAccM multi core synchronization is stuck in RESYNC
 *  05.02.02  2021-06-11  virljs          ESCAN00109371            vMemAccM does not synchronize data between satellite and master
 *********************************************************************************************************************/

#if !defined (VMEMACCM_H)
# define VMEMACCM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vMemAccM_Types.h"
# include "vMemAccM_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define VMEMACCM_VENDOR_ID                           (30u)
# define VMEMACCM_MODULE_ID                           (255u)
# define VMEMACCM_INSTANCE_ID                         (0u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define VMEMACCM_SW_MAJOR_VERSION                    (5u)
# define VMEMACCM_SW_MINOR_VERSION                    (2u)
# define VMEMACCM_SW_PATCH_VERSION                    (2u)

/* ----- Error codes ----- */
# define VMEMACCM_E_NO_ERROR                          (0x00u) /*!< Used to check if no error occurred - use a value unequal to any error code. */
# define VMEMACCM_E_UNINIT                            (0x01u) /*!< Module is not initialized. */
# define VMEMACCM_E_PARAM_POINTER                     (0x02u) /*!< The passed pointer == NULL_PTR. */
# define VMEMACCM_E_PARAM_ADDRESS_AREA_ID             (0x03u) /*!< The passed address area ID is not valid/ not configured. */
# define VMEMACCM_E_PARAM_ADDRESS_LENGTH              (0x04u) /*!< The passed address and length does not belong to the passed address area ID. */
# define VMEMACCM_E_PENDING                           (0x05u) /*!< The passed address area ID is already pending. */
# define VMEMACCM_E_PARAM_HW_SPECIFIC_FUNC_INDEX      (0x06u) /*!< The passed HW specific function index does not belong to passed address area ID. */
# define VMEMACCM_E_PARAM_HW_ID                       (0x07u) /*!< The passed vMem identifier does not exist. */
# define VMEMACCM_E_PARAM_VARIANT_ID                  (0x08u) /*!< The passed memory mapping variant identifier does not exist. */
# define VMEMACCM_E_ADDRESS_AREA_NOT_ACTIVE           (0x09u) /*!< The passed address area ID is not active in processing sub module. */

/* ----- Public API identifier ----- */
# define VMEMACCM_SID_INIT_MEMORY           (0x00u) /*!< Service ID of the API vMemAccM_InitMemory */
# define VMEMACCM_SID_INIT                  (0x01u) /*!< Service ID of the API vMemAccM_Init */
# define VMEMACCM_SID_READ                  (0x02u) /*!< Service ID of the API vMemAccM_Read */
# define VMEMACCM_SID_WRITE                 (0x03u) /*!< Service ID of the API vMemAccM_Write */
# define VMEMACCM_SID_ERASE                 (0x04u) /*!< Service ID of the API vMemAccM_Erase */
# define VMEMACCM_SID_COMPARE               (0x05u) /*!< Service ID of the API vMemAccM_Compare */
# define VMEMACCM_SID_HW_SPECIFIC_REQ       (0x06u) /*!< Service ID of the API vMemAccM_HwSpecificReq */
# define VMEMACCM_SID_MAINFUNCTION          (0x07u) /*!< Service ID of the API vMemAccM_MainFunction */
# define VMEMACCM_SID_CANCEL                (0x08u) /*!< Service ID of the API vMemAccM_Cancel */
# define VMEMACCM_SID_GET_JOB_RESULT        (0x09u) /*!< Service ID of the API vMemAccM_GetJobResult */
# define VMEMACCM_SID_GET_MEMORY_INFO       (0x0Au) /*!< Service ID of the API vMemAccM_GetMemoryInfo */
# define VMEMACCM_SID_SET_READ_ONLY_MODE    (0x0Bu) /*!< Service ID of the API vMemAccM_SetReadOnlyMode */
# define VMEMACCM_SID_GET_PROCESSED_LENGTH  (0x0Cu) /*!< Service ID of the API vMemAccM_GetProcessedLength */
# define VMEMACCM_SID_GET_VERSION_INFO      (0x0Du) /*!< Service ID of the API vMemAccM_GetVersionInfo */
# define VMEMACCM_SID_GET_STATE             (0x0Eu) /*!< Service ID of the API vMemAccM_GetState */
# define VMEMACCM_SID_SET_ACTIVE_VARIANT    (0x0Fu) /*!< Service ID of the API vMemAccM_SetActiveVariant */
# define VMEMACCM_SID_ERROR_NOTIFICATION    (0x10u) /*!< Service ID of the API vMemAccM_ErrorNotification */
# define VMEMACCM_SID_IS_BLANK              (0x11u) /*!< Service ID of the API vMemAccM_IsBlank */
# define VMEMACCM_SID_READ_BLANK            (0x12u) /*!< Service ID of the API vMemAccM_ReadBlank */
# define VMEMACCM_SID_REJECT_NVRAM_REQUESTS (0x13u) /*!< Service ID of the API vMemAccM_RejectNvRamRequests */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VMEMACCM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMemAccM_InitMemory
 *********************************************************************************************************************/
/*! \brief       Function for *_INIT_*-variable initialization.
 *  \details     Service to initialize module global variables at power up. This function initializes the
 *               variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VMEMACCM_CODE) vMemAccM_InitMemory(void);

/**********************************************************************************************************************
 * vMemAccM_Init
 *********************************************************************************************************************/
/*! \brief       Initialization function.
 *  \details     This function initializes the module vMemAccM. It initializes all variables and sets the module state
 *               to initialized.
 *  \pre         vMemAccM_InitMemory has been called unless vMemAccM_ModuleInitialized is initialized by start-up code.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-147815
 *********************************************************************************************************************/
FUNC(void, VMEMACCM_CODE) vMemAccM_Init(void);

/**********************************************************************************************************************
 * vMemAccM_Read
 *********************************************************************************************************************/
/*!
 * \brief       Reads NV memory content of the related address area to passed buffer - from address with length number
 *              of bytes.
 * \details     Creates a read job, which will be processed during MainFunction. Its status can be polled via
 *              vMemAccM_GetJobResult.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   SourceAddress pointing to the first byte of the request (virtual address space).
 * \param[out]  DestinationPtr pointing to the job buffer. Parameter must not be NULL_PTR. Must stay valid until the
 *              AddresAreaId is idle.
 * \param[in]   Length of the data in bytes.
 * \return      E_OK job accepted and queued;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous FALSE
 * \trace       CREQ-147822
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_Read
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType SourceAddress,
  vMemAccM_DataPtrType DestinationPtr,
  vMemAccM_LengthType Length
);

/**********************************************************************************************************************
 * vMemAccM_ReadBlank
 *********************************************************************************************************************/
/*!
 * \brief       Reads NV memory content of the related address area to passed buffer - from address with length number
 *              of bytes. This service will always perform a blank check before reading data.
 * \details     Creates a read job, which will be processed during MainFunction. Its status can be polled via
 *              vMemAccM_GetJobResult. If a page is blank, the buffer will be filled with the erase value.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   SourceAddress pointing to the first byte of the request (virtual address space).
 * \param[out]  DestinationPtr pointing to the job buffer. Parameter must not be NULL_PTR. Must stay valid until the
 *              AddresAreaId is idle.
 * \param[in]   Length of the data in bytes.
 * \return      E_OK job accepted and queued;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous FALSE
 * \trace       CREQ-258758
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_ReadBlank
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType SourceAddress,
  vMemAccM_DataPtrType DestinationPtr,
  vMemAccM_LengthType Length
);

/**********************************************************************************************************************
 * vMemAccM_Write
 *********************************************************************************************************************/
/*!
 * \brief       Writes the passed data to NV memory of the related address area - from address with length number
 *              of bytes.
 * \details     Creates a write job, which will be processed during MainFunction. Its status can be polled via
 *              vMemAccM_GetJobResult.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   TargetAddress pointing to the first byte of the request (virtual address space).
 * \param[in]   SourcePtr pointing to the job buffer. Parameter must not be NULL_PTR. Must stay valid until the
 *              AddresAreaId is idle.
 * \param[in]   Length of the data in bytes. Value is hardware dependent and must be aligned to the smallest writable
 *              size, usually a page size.
 * \return      E_OK job accepted and queued;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous FALSE
 * \trace       CREQ-147823
 * \note        vMemAccM does not check the length to be aligned correctly, vMem shall do. In case the length
 *              is not aligned, the vMem shall reject the request or fail and therefore the vMemAccM job will fail.
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_Write
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType TargetAddress,
  vMemAccM_ConstDataPtrType SourcePtr,
  vMemAccM_LengthType Length
);

/**********************************************************************************************************************
 * vMemAccM_Erase
 *********************************************************************************************************************/
/*!
 * \brief       Erases NV memory content of the related address area - from address with length number of bytes.
 * \details     Creates an erase job, which will be processed during MainFunction. Its status can be polled via
 *              vMemAccM_GetJobResult.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   TargetAddress pointing to the first byte of the request (virtual address space).
 * \param[in]   Length of the data in bytes. Value is hardware dependent and must be aligned to the smallest erasable
 *              size, usually a sector size.
 * \return      E_OK job accepted and queued;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous FALSE
 * \trace       CREQ-147824
 * \note        vMemAccM does not check the length to be aligned correctly, vMem shall do. In case the length
 *              is not aligned, the vMem shall reject the request or fail and therefore the vMemAccM job will fail.
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_Erase
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType TargetAddress,
  vMemAccM_LengthType Length
);

#if (VMEMACCM_COMPARE_API == STD_ON)
/**********************************************************************************************************************
 * vMemAccM_Compare
 *********************************************************************************************************************/
/*!
 * \brief       Compares the passed data to NV memory content of related address area - from address with length
 *              number of bytes.
 * \details     Creates a compare job, which will be processed during MainFunction. Its status can be polled via
 *              vMemAccM_GetJobResult.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   SourceAddress pointing to the first byte of the request (virtual address space).
 * \param[in]   DataPtr pointing to the job buffer. Parameter must not be NULL_PTR. Must stay valid until the
 *              AddresAreaId is idle.
 * \param[in]   Length of the data in bytes.
 * \return      E_OK job accepted and queued;
 *              E_NOT_OK otherwise.
 * \pre         VMEMACCM_COMPARE_API == STD_ON
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous FALSE
 * \trace       CREQ-147825
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_Compare
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType SourceAddress,
  vMemAccM_ConstDataPtrType DataPtr,
  vMemAccM_LengthType Length
);
#endif /* (VMEMACCM_COMPARE_API == STD_ON) */

/**********************************************************************************************************************
 * vMemAccM_IsBlank
 *********************************************************************************************************************/
/*!
 * \brief       Checks the passed address space to be blank, i.e. erased and writable.
 * \details     Creates a blank check job, which will be processed during MainFunction. Its status can be polled via
 *              vMemAccM_GetJobResult.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   TargetAddress pointing to the first byte of the request (virtual address space).
 * \param[in]   Length to be checked in bytes. Value is hardware dependent and must be aligned to the smallest checkable
 *              size, usually a page size.
 * \return      E_OK job accepted and queued;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous FALSE
 * \trace       CREQ-209374
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_IsBlank
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType TargetAddress,
  vMemAccM_LengthType Length
);

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
/**********************************************************************************************************************
 * vMemAccM_HwSpecificReq
 *********************************************************************************************************************/
/*!
 * \brief       Sets up a hardware specific request.
 * \details     vMemAccM handles the requests in the same ways as any other request, except it does not know anything
 *              about the invoked vMem function - vMemAccM just invokes one vMem specific function indexed by the passed
 *              vMemFuncIndex from provided function pointer table.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   HwId pointing to the hardware driver the job shall be forwarded to.
 * \param[in]   vMemHwSpecificFuncIndex as an array index pointing to the hardware specific function pointer.
 * \param[in,out]  DataPtr pointing to the job buffer. Value can be NULL_PTR, if not needed (DataSize == 0).
 *              If != NULL_PTR, it must stay valid until the AddresAreaId is idle (interface between vMem and upper layer,
 *              vMemAccM does not use this pointer).
 * \param[in]   DataSize of the data in bytes. Value can be 0, if DataPtr is NULL_PTR.
 * \return      E_OK job accepted and queued;
 *              E_NOT_OK otherwise.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous FALSE
 * \note        See vMemAccM_vMemApi.h for more information how to implement and use vMem specific requests.
 * \trace       CREQ-147826
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_HwSpecificReq
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_HwIdType HwId,
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType DataSize
);
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */

/**********************************************************************************************************************
 * vMemAccM_MainFunction
 *********************************************************************************************************************/
/*!
 * \brief       Takes care about job processing.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_MainFunction(void);

/**********************************************************************************************************************
 * vMemAccM_Cancel
 *********************************************************************************************************************/
/*!
 * \brief       Cancels the pending job for the address area related to passed address area ID.
 * \details     Canceling effects only address areas in pending state, otherwise the request will be ignored.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \trace       CREQ-147820
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_Cancel(vMemAccM_AddressAreaIdType AddressAreaId);

/**********************************************************************************************************************
 * vMemAccM_GetJobResult
 *********************************************************************************************************************/
/*!
 * \brief       Returns the job result of the address area related to passed address area ID.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \return      Most recent job result of the passed AddressAreaId.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       CREQ-147818
 */
FUNC(vMemAccM_JobResultType, VMEMACCM_CODE) vMemAccM_GetJobResult(vMemAccM_AddressAreaIdType AddressAreaId);

/**********************************************************************************************************************
 * vMemAccM_GetMemoryInfo
 *********************************************************************************************************************/
/*!
 * \brief       Writes memory device information related to passed address area ID and address range to the passed
 *              pointer. GetMemoryInfo checks the passed address and length to cover a continuous memory, otherwise the
 *              request will be rejected.
 * \details     If the address range/ space covers more than one sub address area, vMemAccM will write the memory
 *              information of the first sub address area. The user has to increase his address to get the memory
 *              information of the next sub address area and so on.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   Address pointing to the first byte of the request (virtual address space).
 * \param[in]   Length of the address space, to get the information for, in bytes.
 * \param[out]  MemoryInfoPtr used to store the related memory information. Parameter must not be NULL_PTR.
 * \return      E_OK job accepted, structure filled with memory information;
 *              E_NOT_OK job not accepted, or the passed address space is not continuous.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       CREQ-147821
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_GetMemoryInfo
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_LengthType Length,
  vMemAccM_MemoryInfoPtrType MemoryInfoPtr
);

/**********************************************************************************************************************
 * vMemAccM_SetReadOnlyMode
 *********************************************************************************************************************/
/*!
 * \brief       Sets the address area related to passed address area ID to read only or writable
 * \details     ReadOnly TRUE: vMemAccM will only accept read jobs for the related address area, other jobs will be
 *              rejected.
 *              ReadOnly FALSE: vMemAccM will accept all jobs. This is the default value after initialization.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   ReadOnly value to set the read only status to.
 * \return      E_OK request accepted, address area is read only;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       CREQ-147819
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_SetReadOnlyMode
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  boolean ReadOnly
);

/**********************************************************************************************************************
 * vMemAccM_GetProcessedLength
 *********************************************************************************************************************/
/*!
 * \brief       Returns the number of bytes processed during the most recent job for passed address area ID.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[out]  LengthPtr used to store the processed length in. Parameter must not be NULL_PTR.
 * \return      E_OK request accepted;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       CREQ-147914
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_GetProcessedLength
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_LengthPtrType LengthPtr
);

/**********************************************************************************************************************
 * vMemAccM_GetState
 *********************************************************************************************************************/
/*!
 * \brief       Writes the information about the current state to the structure.
 * \details     vMemAccM can be internally idle, can prepare or finalize job and also can wait for the underlying
 *              vMem to finish the requested job. Depending on the internal state vMemAccM provides different
 *              information, fills the provided structure with different values.
 * \param[out]  StatePtr Pointer to a structure of type vMemAccM_StateType. Has to be provided by caller.
 * \return      E_OK request accepted, structure filled with state information;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       CREQ-177528
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_GetState(vMemAccM_StatePtrType StatePtr);

/**********************************************************************************************************************
 * vMemAccM_SetActiveVariant
 *********************************************************************************************************************/
/*!
 * \brief       Sets the current active variant to the passed variant identifier.
 * \details     Setting the variant identifier affects all address areas with variants, that means all will be switched
 *              to the passed variant. Address areas without variants will not be affected by calling this function.
 * \param[in]   VariantId Holds the ID to be set as the active variant. For address areas with variants the value
 *              can be [0,1], for all other [0].
 * \return      E_OK request processed, variant was set;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       CREQ-178492
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_SetActiveVariant(vMemAccM_VariantIdType VariantId);

# if (VMEMACCM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_GetVersionInfo
 *********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     Returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  VersionInfo Pointer to the structure to store the version information in. Parameter must not be NULL.
 *  \pre         VMEMACCM_VERSION_INFO_API == STD_ON
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-147816
 *********************************************************************************************************************/
FUNC(void, VMEMACCM_CODE) vMemAccM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VMEMACCM_APPL_VAR) VersionInfo);
# endif /* (VMEMACCM_VERSION_INFO_API == STD_ON) */

/**********************************************************************************************************************
 *  vMemAccM_RejectNvRamRequests
 *********************************************************************************************************************/
/*! \brief       Controls whether the NV RAM may be accessed or not by services.
 *  \details     RejectRequests TRUE: vMemAccM will reject future service calls, which access the NV RAM.
 *               RejectRequests FALSE: vMemAccM will no longer reject future service calls, which access the NV RAM.
 *  \param[in]   RejectRequests Value which decides whether requests will be rejected or not.
 *  \return      E_OK request processed, services will behave according to parameter
 *               E_NOT_OK request processed, services' behavior will not change
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-277449
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_RejectNvRamRequests(boolean RejectRequests);

# define VMEMACCM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/*!
 * \exclusivearea VMEMACCM_EXCLUSIVE_AREA_0
 * Ensures consistency while modifying internal variables.
 * \protects Internal variables (vMemAccM_MngmtAreas, vMemAccM_Queue, vMemAccM_QueueNextJobIndex).
 * \usedin   vMemAccM_SchedQueueJobInternal, vMemAccM_SchedQueueGetNextJob, vMemAccM_SchedCancelJob,
 *           vMemAccM_SMFinalizeJobViaOffset, vMemAccM_SMFinalizeJob, vMemAccM_SetReadOnlyMode.
 * \exclude  vMemAccM_MainFunction
 * \length   SHORT Only a few statements.
 * \endexclusivearea
 */

#endif /* VMEMACCM_H */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM.h
 *********************************************************************************************************************/

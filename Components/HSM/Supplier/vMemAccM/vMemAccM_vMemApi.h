/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMemAccM_vMemApi.h
 *        \brief  Defines the API, all vMem instances shall implement.
 *
 *      \details  This header file defines the signatures of all functions that shall be implemented by a vMem.
 *                (Supplementing types and defining includes are given here.)
 *                The API itself is defined using function pointers, gathered in a structure
 *                and, for device specific functions, in an array.
 *                Each vMem shall provide an object of this structure (in ROM, with external linkage), initialized with
 *                the addresses of respective functions.
 *                Currently, all named functions are mandatory, null pointer shall not be used.
 *                Unnamed functions, i.e. HW specific are optional, see below.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id              Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2018-01-26  virck   FEAT-3242/ STORY-3379  Implement basic functionality of Memory Access Manager.
 *  02.00.00  2018-04-03  viroto  FEAT-3242/ STORY-3380  Support hardware specific features.
 *  02.00.01  2019-01-16  viroto  -                      Documentation updated; no functionality changes.
 *  03.00.00  2019-07-24  viroto  MWDG-120               vMemAccM shall provide a service to check a specific NV RAM address space to be blank/ erased.
 *  03.00.01  2019-11-26  viroto  -                      Improvements; no functionality changes.
 *  04.00.00  2021-04-15  virljs  MWDG-4642              vMemAccM shall initialize and call the MainFunctions of the underlying vMems
 *********************************************************************************************************************/

#ifndef VMEMACCM_VMEMAPI_H
#define VMEMACCM_VMEMAPI_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMemAccM_Types.h"

/**********************************************************************************************************************
 *  COMPATIBILITY VERSION
 *********************************************************************************************************************/
/* Use this version to ensure compatibility between vMemAccM and vMem (vMem includes the vMemAccM_vMemApi.h and
 * is responsible for the compatibility check.)
 * Please note: this is the vMemAccM_vMemApi.h version, not the vMemAccM implementation version! */
# define VMEMACCM_VMEMAPI_MAJOR_VERSION                    (4u)
# define VMEMACCM_VMEMAPI_MINOR_VERSION                    (0u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*
 job Results; probably actually #include'd. Drivers may rely on definition of this type and these
 enumerators
*/
typedef enum
{
  VMEM_JOB_OK,                    /*!< Everything is fine, last job finished successfully. */
  VMEM_JOB_PENDING,               /*!< Job is currently pending, i.e. in processing. */
  VMEM_READ_CORRECTED_ERRORS,     /*!< HW reported that ECC errors were corrected during read. */
  VMEM_READ_UNCORRECTABLE_ERRORS, /*!< Uncorrectable ECC errors occurred during read. */
  VMEM_JOB_FAILED,                /*!< Job failed for some unspecific reason. */
  VMEM_MEM_NOT_BLANK              /*!< The passed address area is not blank. */
} vMemAccM_vMemJobResultType;     /*!< Stores all known vMem job results. */


typedef vMemAccM_ConstDataPtrType   vMemAccM_vMemConstDataPtrType;
typedef vMemAccM_DataPtrType        vMemAccM_vMemDataPtrType;
typedef uint32                      vMemAccM_vMemInstanceIdType;
typedef vMemAccM_AddressType        vMemAccM_vMemAddressType;
typedef vMemAccM_LengthType         vMemAccM_vMemLengthType;
typedef uint32                      vMemAccM_vMemConfigType;

typedef P2CONST(vMemAccM_vMemConfigType, AUTOMATIC, VMEMACCM_VMEM_CONST) vMemAccM_vMemConfigPtrType;

/**********************************************************************************************************************
 *  vMem_Init function pointer type
 *********************************************************************************************************************/
/*!
 * \brief       Initialize the vMem.
 * \details     The vMemAccM is responsible for initializing all underlying vMems. 
 *              Since new vMems can be added at runtime, it is necessary to know all their initialize functions.
 * \param[in]   CfgPtr       - Pointer to the vMem config. Can be a NULL_PTR. The pointer value will not be used.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
typedef P2FUNC(void, VMEMACCM_VMEM_CODE, vMemAccM_vMemInitFuncPtr)(vMemAccM_vMemConfigPtrType CfgPtr);

/**********************************************************************************************************************
 *  vMem_MainFunction function pointer type
 *********************************************************************************************************************/
/*!
 * \brief       Trigger the vMem MainFunction.
 * \details     The vMemAccM is responsible for processing all underlying vMems. 
 *              Since new vMems can be added at runtime, it is necessary to know all their MainFunctions, so their
 *              processing can be handled.
 * \pre         Underlying device is initialized.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
typedef P2FUNC(void, VMEMACCM_VMEM_CODE, vMemAccM_vMemMainFunctionFuncPtr)(void);

/**********************************************************************************************************************
 *  vMem_Read function pointer type
 *********************************************************************************************************************/
/*!
 * \brief       Request a read job.
 * \details     An implementation should start a read job synchronously.
 *              If possible it may process it synchronously (e.g. memcpy).
 *              When job completes (VMEM_JOB_OK,VMEM_READ_CORRECTED_ERRORS) all requested bytes shall have been read;
 *              driver shall terminate early in case of failure.
 *              If supported by underlying HW, the driver shall indicate whether correctable or uncorrectable errors occurred.
 * \param[in]   InstanceId       - Id of the instance the job shall be executed for.
 * \param[in]   SourceAddress    - Physical device address where read starts.
 * \param[out]  TargetAddressPtr - Buffer to read into. Content shall contain the read data, if reading completes
 *                                 with VMEM_JOB_OK or VMEM_READ_CORRECTED_ERRORS. Parameter must not be NULL_PTR and
 *                                 must stay valid until the vMem is idle.
 * \param[in]   Length           - Number of bytes to read.
 * \return      E_OK      - Request was accepted (and started); independent of actual read result (if synchronously processed).
 * \return      E_NOT_OK  - Request was rejected (NOT: synchronous read failure).
 * \pre         Underlying device is IDLE (i.e. if different devices block each other, no other vMem is currently working).
 * \pre         (SourceAddress, SourceAddress + Length - 1) is in underlying device's range.
 * \pre         TargetAddressPtr's size is greater than or equal to Length.
 * \pre         If required by hardware the owner of TargetAddressPtr must ensure correct RAM alignment.
 * \post        (return == E_OK) => GetJobResult() == VMEM_JOB_PENDING (job accepted, but not completed).
 * \post        (return == E_OK) => GetJobResult() != VMEM_JOB_PENDING (instead: read's result, job synchronously completed).
 * \post        (return == E_NOT_OK) => DestBuffer unchanged.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \note        Though a read job may be processed synchronously it shall be handled (by vMemAccM) as being asynchronous,
 *              i.e. it shall not expect synchronous processing. However it also shall not expect the driver to become PENDING after
 *              a request was accepted. The driver, in turn shall update the job result, even in case of synchronous handling.
 *              Read shall allow reading any number of bytes form any byte-address.
 */
typedef P2FUNC(Std_ReturnType, VMEMACCM_VMEM_CODE, vMemAccM_vMemReadFuncPtr)
  (vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemAddressType SourceAddress, vMemAccM_vMemDataPtrType TargetAddressPtr, vMemAccM_vMemLengthType Length);

/**********************************************************************************************************************
 *  vMem_Write function pointer type
 *********************************************************************************************************************/
/*!
 * \brief       Request a write job.
 * \details     An implementation should start a write job synchronously, i.e. it should setup the HW.
 *              It shall not block until the HW completed.
 *              Driver shall terminate job processing early in case of any failure.
 * \param[in]   InstanceId       - Id of the instance the job shall be executed for.
 * \param[in]   TargetAddress    - Physical device address where write starts.
 * \param[in]   SourceAddressPtr - Data to be written. Parameter must not be NULL_PTR and must stay valid until the vMem is idle.
 * \param[in]   Length           - Number of bytes to be programmed into underlying device.
 * \return      E_OK      - Request was accepted (and started);
 * \return      E_NOT_OK  - Request was rejected (due to failed pre-conditions).
 * \pre         Underlying device is IDLE (i.e. if different devices block each other, no other vMem is currently working).
 * \pre         Device is write-able.
 * \pre         (TargetAddress, TargetAddress + Length - 1) is in underlying device's range.
 * \pre         TargetAddress and Length are aligned to device's page-size (as published in configuration).
 * \pre         Length is exactly one page or one page burst size as published by this implementation at configuration time.
 * \pre         SourceAddressPtr's size is greater than or equal to Length.
 * \pre         If required by hardware the owner of SourceAddressPtr must ensure correct RAM alignment.
 * \post        (return == E_OK) => GetJobResult() == VMEM_JOB_PENDING (job accepted).
 * \post        (return == E_OK) => GetJobResult() != VMEM_JOB_PENDING (instead: write's result, job synchronously completed).
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \note        Page-wise writes are the smallest possible write requests.
 */
typedef P2FUNC(Std_ReturnType, VMEMACCM_VMEM_CODE, vMemAccM_vMemWriteFuncPtr)
  (vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemAddressType TargetAddress, vMemAccM_vMemConstDataPtrType SourceAddressPtr, vMemAccM_vMemLengthType Length);

/**********************************************************************************************************************
 *  vMem_Erase function pointer type
 *********************************************************************************************************************/
/*!
 * \brief       Request an erase job.
 * \details     An implementation should start an erase job synchronously, i.e. it should setup the HW.
 *              It shall not block until the HW completed.
 *              Driver shall terminate job processing early in case of any failure.
 * \param[in]   InstanceId     - Id of the instance the job shall be executed for.
 * \param[in]   TargetAddress  - Physical device address where erase starts.
 * \param[in]   Length         - Number of bytes to be erased.
 * \return      E_OK      - Request was accepted (and started);
 * \return      E_NOT_OK  - Request was rejected (due to failed pre-conditions).
 * \pre         Underlying device is IDLE (i.e. if different devices block each other, no other vMem is currently working).
 * \pre         Device is write-able.
 * \pre         (TargetAddress, TargetAddress + Length - 1) is in underlying device's range.
 * \pre         TargetAddress and Length are aligned to device's sector boundaries (as published in configuration).
 * \pre         (TargetAddress, Length) denote exactly one single erasable unit (sector or sector burst) as published
 *              by this implementation at configuration time.
 * \post        (result == E_OK) => GetJobResult() == VMEM_JOB_PENDING (job accepted).
 * \post        (return == E_OK) => GetJobResult() != VMEM_JOB_PENDING (instead: erase's result, job synchronously completed).
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \note        Sector-wise erases are the smallest possible erase requests.
 */
typedef P2FUNC(Std_ReturnType, VMEMACCM_VMEM_CODE, vMemAccM_vMemEraseFuncPtr)
  (vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemAddressType TargetAddress, vMemAccM_vMemLengthType Length);

/**********************************************************************************************************************
 *  vMem_IsBlank function pointer type
 *********************************************************************************************************************/
/*!
 * \brief       Request an blank check job.
 * \details     An implementation should start an blank check job synchronously, i.e. it should setup the HW.
 *              It shall not block until the HW completed.
 *              Driver shall terminate job processing early in case of any failure.
 * \param[in]   InstanceId     - Id of the instance the job shall be executed for.
 * \param[in]   TargetAddress  - Physical device address where the blank check starts.
 * \param[in]   Length         - Number of bytes to be checked (page aligned).
 * \return      E_OK      - Request was accepted (and started);
 * \return      E_NOT_OK  - Request was rejected (due to failed pre-conditions).
 * \pre         Underlying device is IDLE (i.e. if different devices block each other, no other vMem is currently working).
 * \pre         (TargetAddress, TargetAddress + Length - 1) is in underlying device's range.
 * \pre         TargetAddress and Length are aligned to device's page-size (as published in configuration).
 * \pre         Length is exactly one page (as the smallest checkable size).
 * \post        (result == E_OK) => GetJobResult() == VMEM_JOB_PENDING (job accepted).
 * \post        (return == E_OK) => GetJobResult() != VMEM_JOB_PENDING (instead: blank's result, job synchronously completed).
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \note        Page is the smallest possible IsBlank requests.
 */
typedef P2FUNC(Std_ReturnType, VMEMACCM_VMEM_CODE, vMemAccM_vMemIsBlankFuncPtr)
  (vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemAddressType TargetAddress, vMemAccM_vMemLengthType Length);

/**********************************************************************************************************************
 *  vMem_GetJobResult function pointer type
 *********************************************************************************************************************/
/*!
 * \brief       Get driver's status/job result.
 * \details     Provide information about most recently accepted job. Either it's pending, or provide its result.
 *              It shall not block until the HW completed.
 *              Driver shall terminate job processing early in case of any failure.
 * \param[in]   InstanceId         - Id of the instance the job shall be executed for.
 * \return      VMEM_JOB_OK        - Request completed successfully: data written, read or erased, address space is blank,
 *                                   HwSpecifcRequest processed successfully.
 * \return      VMEM_JOB_PENDING   - Request is still pending (HW is busy)
 * \return      VMEM_READ_CORRECTED_ERRORS     - During read, HW reported that ECC errors were corrected.
 *                                               This is some kind of "restricted" ok, it will be propagated to upper layer SW.
 * \return      VMEM_READ_UNCORRECTABLE_ERRORS - One or more Uncorrectable ECC errors occurred during read; indicates a failure.
 * \return      VMEM_JOB_FAILED    - Job failed for some unspecific reason, e.g. bus error.
 * \return      VMEM_MEM_NOT_BLANK - At least a part of or the complete address space is not blank.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        An implementation may use this function to trigger job processing/continuation internally.
 *              However this is not recommended, as this function is expected to just deliver the current result.
 *              Thus it is also expected to have very short run-time.
 *              If necessary, a MainFunction shall be implemented.
 */
typedef P2FUNC(vMemAccM_vMemJobResultType, VMEMACCM_VMEM_CODE, vMemAccM_vMemGetJobResultFuncPtr)
  (vMemAccM_vMemInstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_ HW specific function pointer type
 *********************************************************************************************************************/
/*!
 * \brief       Request a hardware specific job.
 * \details     The implementation depends on hardware and upper layer needs. Since the function gets the needed
 *              parameters/ pointers via the structure ReqSpecificData, the function can implement nearly everything.
 *              It is up to the user to know how to use the hardware specific function correctly.
 * \param[in]   InstanceId      - Id of the instance the job shall be executed for.
 * \param[in]   ReqSpecificData - Hardware specific request data, e.g. a structure to read device information to.
 *                                Parameter must stay valid until the vMem is idle.
 * \param[in]   SizeOfData      - Size of the passed ReqSpecificData in bytes.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \note        Note that the function itself is request specific, and it belongs to a specific device (driver instance).
 *
 *              Possible parameters, as well as current processing context are contained in the structure
 *              passed as ReqSpecificData.
 *
 *              It is advisable for implementations to define a zero-filled structure being "initial".
 *              A user has only to fill out the "parameters part".
 *
 *              An implementation is encouraged to provide a supplementary function(s) to initialize such hardware
 *              specific data structures/ prepare the structures for the request.
 *              Such a function must operate synchronously, independent of driver's current state, it shall be
 *              re-entrant and concurrently callable and it shall not affect the HW itself.
 *              It should not have any other side-effect than filling the passed structure.
 *
 *              Clients needing to use HW specific services, must know about the structure itself, as about the availability
 *              of an initialization function.
 *              Such a client directly depends on a specific driver. The driver shall provide information (e.g. via header),
 *              about implemented specific functions, how to used them, and which function ID corresponds to which function.
 *              Of course, the drive also has to ensure that this mapping is correct.
 */
typedef P2FUNC(Std_ReturnType, VMEMACCM_VMEM_CODE, vMemAccM_vMemHwSpecificFuncPtr)
    (vMemAccM_vMemInstanceIdType InstanceId, vMemAccM_vMemDataPtrType ReqSpecificData, uint32 SizeOfData);

/**********************************************************************************************************************
 *  vMem function pointer table types
 *********************************************************************************************************************/
typedef P2CONST(vMemAccM_vMemHwSpecificFuncPtr, AUTOMATIC, VMEMACCM_VMEM_CONST) vMemAccM_vMemHwFuncTable;
typedef uint32 vMemAccM_vMemHeaderType;
typedef P2CONST(vMemAccM_vMemHeaderType, AUTOMATIC, VMEMACCM_VMEM_CONST) vMemAccM_vMemHeaderPtrType;
typedef uint32 vMemAccM_vMemFooterType;
typedef P2CONST(vMemAccM_vMemFooterType, AUTOMATIC, VMEMACCM_VMEM_CONST) vMemAccM_vMemFooterPtrType;

typedef struct
{
  vMemAccM_vMemHwSpecificFuncIndexType FunctionCount; /*!< Number of entries in FuncTable (Array). FunctionCount != 0 <=> Table != NULL. */
  vMemAccM_vMemHwFuncTable Table;                     /*!< Pointer to an array of P2FUNCs. */
} vMemAccM_vMemHwSpecificFunctionsType;               /*!< Holds the hardware specific function table. */

typedef struct
{
  vMemAccM_vMemHeaderType Header;                         /*!< vMem header providing information about the vMem driver. */ 
  vMemAccM_vMemHeaderPtrType HeaderPtr;                   /*!< Pointer to the vMem header. */
  vMemAccM_vMemFooterPtrType FooterPtr;                   /*!< Pointer to the vMem footer. */
  const vMemAccM_vMemHwSpecificFunctionsType HwFunctions; /*!< Hardware specific function pointer table. */
  vMemAccM_vMemInitFuncPtr Init;                          /*!< Function pointer to vMem_Init. */
  vMemAccM_vMemReadFuncPtr Read;                          /*!< Function pointer to vMem_Read. */
  vMemAccM_vMemWriteFuncPtr Write;                        /*!< Function pointer to vMem_Write. */
  vMemAccM_vMemEraseFuncPtr Erase;                        /*!< Function pointer to vMem_Erase. */
  vMemAccM_vMemIsBlankFuncPtr IsBlank;                    /*!< Function pointer to vMem_IsBlank. */
  vMemAccM_vMemGetJobResultFuncPtr GetJobResult;          /*!< Function pointer to vMem_GetJobResult. */
  vMemAccM_vMemMainFunctionFuncPtr MainFunction;          /*!< Function pointer to vMem_MainFunction. */
} vMemAccM_vMemApiType;                                   /*!< Holds the vMem API function pointer table. */

typedef P2CONST(vMemAccM_vMemApiType, AUTOMATIC, VMEMACCM_CONST) vMemAccM_ConstvMemApiPtrType;

/**********************************************************************************************************************
 *  Additional information
 *********************************************************************************************************************/
/* 
 * vMemAccM constructs an array of pointers to this structure, or stores each single pointer along with other
 * device (instance) specific information gathered during config (that is the "If part").
 * vMemAccM might even store the table internally along with job data, avoiding one indirection.
 *
 * Additional indirections when vMemAccM calls a service should be neglectable.
 * Same should hold for hardware specific functions. vMemAccM could also "cache" the P2FUNC for later use
 * (if several calls are necessary to process one single job).
*/

#endif /* VMEMACCM_VMEMAPI_H */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_vMemApi.h
 *********************************************************************************************************************/

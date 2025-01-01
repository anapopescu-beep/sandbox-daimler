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
/*!        \file  vHsm_Ipc.c
 *        \brief  Vector Hardware Security Module Firmware (vHsm)
 *
 *      \details  Inter-processor communication between Host and Vector Hardware Security Module Firmware.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSM_IPC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm.h"
#include "vHsm_Ipc.h"
#include "vHsm_KeyM.h"
#include "CryIf_Cfg.h"
#include "vHsm_JobProcessor.h"
#include "vHsm_ApiInternal.h"
#include "SchM_vHsm.h"
#include "vHsm_Hal.h"

#include "vstdlib.h"
#if (VHSM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (VHSM_LOCAL) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL                                                   static
#endif

#if !defined (VHSM_LOCAL_INLINE) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

#define VHSM_IPC_CHANNEL_ENTRY_HEADER_SIZE                            (4U)

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
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define VHSM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(uint8, VHSM_VAR_NOINIT) vHsm_Ipc_Idx;

#define VHSM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSM_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) vHsm_Ipc_MemoryPtr;

#define VHSM_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VHSM_REDIRECTION == STD_ON)
# define VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VHSM_LOCAL VAR(Crypto_JobRedirectionInfoType, VHSM_VAR_NOINIT) vHsm_Ipc_Crypto_JobRedirectionInfo; /* PRQA S 3218 */ /* MD_VHSM_3218_WORKSPACE_VAR */

# define VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VHSM_IPC_PROTOCOL_VERSION == 3u)

/**********************************************************************************************************************
 *  vHsm_Ipc3_Job_Deserialize_Parser()
 *********************************************************************************************************************/
/*!
 * \brief         Deserializes job data from the IPC.
 * \details       -
 * \param[in]     ptrBuf          Pointer to the IPC buffer.
 * \param[in,out] parsedContent   Data structure containing pointer and data information from the IPC.
 * \param[in]     checkPtrFunc    Pointer to function that will check amount of pointers.
 * \param[in]     jobObjectId     Id of the job object.
 * \return        E_OK            IPC data can be processed with a crypto job.
 *                E_NOT_OK        IPC data can not be processed with a crypto job.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc3_Job_Deserialize_Parser(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf,
  P2VAR(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedContent,
  vHsm_Ipc3_CalloutCheckPtrMask_Type checkPtrFunc,
  vHsm_JobObjectIdType jobObjectId);

/**********************************************************************************************************************
 *  vHsm_Ipc3_CryptoJob_CheckPtrMask()
 *********************************************************************************************************************/
/*!
 * \brief         Checks the amount of pointers of a crypto job.
 * \details       Read amount of pointers from the IPC and compare it against max pointer values of a crypto job.
 * \param[in]     parsedData   Data structure containing pointer and data information from the IPC.
 * \return        E_OK         IPC data can be processed with a crypto job.
 *                E_NOT_OK     IPC data can not be processed with a crypto job.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc3_CryptoJob_CheckPtrMask(
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData);

/**********************************************************************************************************************
 *  vHsm_Ipc3_KeyMJob_CheckPtrMask()
 *********************************************************************************************************************/
/*!
 * \brief         Checks the amount of pointers of a KeyM job.
 * \details       Read amount of pointers from the IPC and compare it against max pointer values of a KeyM job.
 * \param[in]     parsedData   Data structure containing pointer and data information from the IPC.
 * \return        E_OK         IPC data can be processed with a KeyM job.
 *                E_NOT_OK     IPC data can not be processed with a KeyM job.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc3_KeyMJob_CheckPtrMask(
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData);

/**********************************************************************************************************************
 *  vHsm_Ipc3_ParseInputPtr()
 *********************************************************************************************************************/
/*!
 * \brief         Parses input pointers from IPC job buffer into data structure.
 * \details       Parses IPC input pointers and checks for validity.
 * \param[in,out] parsedContent   Data structure containing pointer and data information from the IPC.
 * \param[in]     ptrBuf          Pointer to the IPC buffer.
 * \param[out]    offset          Offset in the buffer to read data.
 * \return        E_OK            Input pointer are valid.
 *                E_NOT_OK        Input pointer are not in whitelist and are invalid.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc3_ParseInputPtr(
  P2VAR(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedContent,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset);

/**********************************************************************************************************************
 *  vHsm_Ipc3_ParseOutputPtr()
 *********************************************************************************************************************/
/*!
 * \brief         Parses output pointers from IPC job buffer into data structure.
 * \details       Parses IPC output pointers and checks for validity.
 * \param[in,out] parsedContent   Data structure containing pointer and data information from the IPC.
 * \param[in]     ptrBuf          Pointer to the IPC buffer.
 * \param[out]    offset          Offset in the buffer to read data.
 * \return        E_OK            Output pointers are valid.
 *                E_NOT_OK        Output pointers are invalid.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc3_ParseOutputPtr(
  P2VAR(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedContent,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset);

/**********************************************************************************************************************
 *  vHsm_Ipc3_ParseCryptoKeyIds()
 *********************************************************************************************************************/
/*!
 * \brief         Parses key ids from IPC job buffer into data structure.
 * \details       Parses IPC key ids and checks for validity.
 * \param[in,out] parsedContent   Data structure containing pointer and data information from the IPC.
 * \param[in]     ptrBuf          Pointer to the IPC buffer.
 * \param[out]    offset          Offset in the buffer to read data.
 * \param[out]    errorIdPtr      Pointer to store the errorId.
 * \return        E_OK            Keys can be used.
 *                E_NOT_OK        Keys can not be used.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc3_ParseCryptoKeyIds(
  P2VAR(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedContent,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) errorIdPtr);

/**********************************************************************************************************************
 *  vHsm_Ipc3_ParseConstData()
 *********************************************************************************************************************/
/*!
 * \brief         Parses constant job data from IPC job buffer into data structure.
 * \details       -
 * \param[in,out] parsedContent   Data structure containing pointer and data information from the IPC.
 * \param[in]     ptrBuf          Pointer to the IPC buffer.
 * \param[in,out] offset      Offset in the buffer to read data.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc3_ParseConstData(
  P2VAR(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedContent,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset);

/**********************************************************************************************************************
 *  vHsm_Ipc_CryptoJob_Factory()
 *********************************************************************************************************************/
/*!
 * \brief         Creates a crypto job from parsed data.
 * \details       -
 * \param[in]     parsedData      Data structure containing pointer and data information from the IPC.
 * \param[in]     jobObjectId     Id of the job object.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_CryptoJob_Factory(
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData,
  vHsm_JobObjectIdType jobObjectId);

/**********************************************************************************************************************
 *  vHsm_Ipc_SetCryptoJobData()
 *********************************************************************************************************************/
/*!
 * \brief         Set crypto job data from parsed data.
 * \details       -
 * \param[in,out] ptrVal          Pointer to the crypto job.
 * \param[in]     parsedData      Data structure containing pointer and data information from the IPC.
 * \param[in]     jobObjectId     Id of the job object.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_SetCryptoJobData(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) ptrVal,
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData,
  vHsm_JobObjectIdType jobObjectId);

# if (VHSM_REDIRECTION == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Ipc3_CryptoJob_Redirection()
 *********************************************************************************************************************/
/*!
 * \brief         Performs redirection of crypto job.
 * \details       -
 * \param[in]     jobObjectId     Id of the job object.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc3_CryptoJob_Redirection(
  vHsm_JobObjectIdType jobObjectId);
# endif

/**********************************************************************************************************************
 *  vHsm_Ipc_KeyM_Factory()
 *********************************************************************************************************************/
/*!
 * \brief         Creates KeyM job from parsed data.
 * \details       -
 * \param[in]     parsedData      Data structure containing pointer and data information from the IPC.
 * \param[in]     jobObjectId     Id of the job object.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_KeyM_Factory(
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData,
  vHsm_JobObjectIdType jobObjectId);

/**********************************************************************************************************************
 *  vHsm_Ipc_SetKeyMJobData()
 *********************************************************************************************************************/
/*!
 * \brief         Set KeyM job data from parsed data.
 * \details       -
 * \param[in,out] ptrVal          Pointer to the KeyM job.
 * \param[in]     parsedData      Data structure containing pointer and data information from the IPC.
 * \param[in]     jobObjectId     Id of the job object.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_SetKeyMJobData(
  P2VAR(vHsm_KeyM_JobType, AUTOMATIC, VHSM_APPL_VAR) ptrVal,
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData,
  vHsm_JobObjectIdType jobObjectId);
#endif

/**********************************************************************************************************************
 *  vHsm_Ipc_ReceiveJobRequest()
 *********************************************************************************************************************/
 /*!
 * \brief         De-serializes the jobrequest
 * \details       Read request from IPC and de-serializes it to an job object.
 * \param[in]     rxChannelId  Channel where the job request has been received
 * \param[out]    jobObject    Id of the Object in which request has been de-serialized
 * \return        E_OK         Request has been successful de-serialized
 *                E_NOT_OK     Request was not successful/no job available
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc_ReceiveJobRequest(
  vHsm_ChannelIdType rxChannelId, P2VAR(vHsm_JobObjectIdType, AUTOMATIC, AUTOMATIC) jobObject);

/**********************************************************************************************************************
 *  vHsm_Ipc_ProcessJobRequest()
 *********************************************************************************************************************/
/*! \brief        Processes the job request.
 *  \details      -
 *  \param[in]    jobObjectId    Id of the jobRequest
 *  \param[in]    callContext    Call context from where the function has been called
 *  \pre          -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_ProcessJobRequest(
  vHsm_JobObjectIdType jobObjectId, vHsm_CallContextType callContext);

/**********************************************************************************************************************
 *  vHsm_Ipc_SendImmediateResponse()
 *********************************************************************************************************************/
/*! \brief        Send a respone with a specified return value
 *  \details      This can happen if the vHsm_JobObject is already locked/busy from another IPC instance
 *                or if parsing the request could not be done.
 *                In either case a response will be sent instead of silently ignoring the request.
 *  \param[in]    rxChannelId      Channel where the job request has been received
 *  \param[in]    jobRequestId     Id of the jobRequest
 *  \param[in]    jobRequestKind   Kind of the jobRequest
 *  \param[in]    retVal           RetVal of the response
 *  \pre          -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Ipc_SendImmediateResponse(
  vHsm_ChannelIdType rxChannelId,
  vHsm_JobRequestIdType jobRequestId,
  vHsm_JobRequestKindType jobRequestKind,
  Std_ReturnType retVal);

#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
/**********************************************************************************************************************
 *  vHsm_Ipc_Receive_CryptoJobRequest()
 *********************************************************************************************************************/
/*! \brief       Receive crypto job request
 *  \details     De-serializes a crypto job from IPC.
 *  \param[in]   jobObjectId     Id of the object
 *  \param[in]   jobRequestBuffer       Job request buffer
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Called by job dispatching through function pointer. Do not inline.
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Ipc_Receive_CryptoJobRequest(
  vHsm_JobObjectIdType jobObjectId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) jobRequestBuffer);

/**********************************************************************************************************************
 *  vHsm_Ipc_Receive_KeyMJobRequest()
 *********************************************************************************************************************/
/*! \brief       Receive key management job request
 *  \details     De-serializes a key management job from IPC.
 *  \param[in]   jobObjectId     Id of the object
 *  \param[in]   jobRequestBuffer       Job request buffer
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Called by job dispatching through function pointer. Do not inline.
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Ipc_Receive_KeyMJobRequest(
  vHsm_JobObjectIdType jobObjectId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) jobRequestBuffer);
#endif

/**********************************************************************************************************************
 *  vHsm_Ipc_Transmit_CryptoJobResponse()
 *********************************************************************************************************************/
/*! \brief       Transmits crypto job response.
 *  \details     Serializes the response (12 Bytes: jobId, jobState, retVal) of a crypto job to IPC.
 *  \param[in]   jobObjectId              Job object id
 *  \param[out]  jobResponseBuffer        Job response buffer where 12 bytes will be written
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Called by job dispatching through function pointer. Do not inline.
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Ipc_Transmit_CryptoJobResponse(
  vHsm_JobObjectIdType jobObjectId,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) jobResponseBuffer);

/**********************************************************************************************************************
 *  vHsm_Ipc_Transmit_KeyMJobResponse()
 *********************************************************************************************************************/
/*! \brief       Transmits key management job.
 *  \details     Serializes the response (4 bytes: retVal)of a key management job to IPC.
 *  \param[in]   jobObjectId              Job object id
 *  \param[out]  jobResponseBuffer        Job response buffer where 4 bytes will be written
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Called by job dispatching through function pointer. Do not inline.
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Ipc_Transmit_KeyMJobResponse(
  vHsm_JobObjectIdType jobObjectId,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) jobResponseBuffer);

/**********************************************************************************************************************
 *  vHsm_Ipc_IsPtrValid()
 *********************************************************************************************************************/
/*!
 * \brief         Check if ptr is valid.
 * \details       -
 * \param[in]     ptr                  Pointer which shall be checked
 * \param[in]     length               Length which is requested
 * \param[in]     accessParameters     Type of the access request (read or readwrite)
 * \return        TRUE if ptr is valid, FALSE otherwise
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc_IsPtrValid(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptr,
  uint32 length,
  uint8 accessParameters);

#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
/**********************************************************************************************************************
 *  vHsm_Ipc_IsCryptoJobBuffersValid()
 *********************************************************************************************************************/
/*!
 * \brief         Check if crypto job contains valid buffers.
 * \details       -
 * \param[in,out] jobPtr       Pointer to the job
 * \param[in]     jobObjectId  Id of the object
 * \return        TRUE if buffers are valid, FALSE otherwise.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Ipc_IsCryptoJobBuffersValid(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr,
  vHsm_JobObjectIdType jobObjectId);

/**********************************************************************************************************************
 *  vHsm_Ipc_IsCryptoKeyDeriveJobBuffersValid()
 *********************************************************************************************************************/
/*!
 * \brief         Check if crypto key derive job contains valid keys.
 * \details       -
 * \param[in,out] jobPtr       Pointer to the job
 * \param[in]     jobObjectId  Id of the object
 * \return        TRUE if buffers are valid, FALSE otherwise.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Ipc_IsCryptoKeyDeriveJobBuffersValid(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr,
  vHsm_JobObjectIdType jobObjectId);

/**********************************************************************************************************************
 *  vHsm_Ipc_IsCryptoMacGenJobBuffersValid()
 *********************************************************************************************************************/
/*!
 * \brief         Check if crypto cmac generate job contains valid buffers.
 * \details       -
 * \param[in,out] jobPtr   Pointer to the job
 * \param[in]     jobObjectId     Id of the object
 * \return        TRUE if buffers are valid, FALSE otherwise.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Ipc_IsCryptoMacGenJobBuffersValid(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr,
  vHsm_JobObjectIdType jobObjectId);

/**********************************************************************************************************************
 *  vHsm_Ipc_IsCryptoMacVerJobBuffersValid()
 *********************************************************************************************************************/
/*!
 * \brief         Check if crypto cmac verify job contains valid buffers.
 * \details       -
 * \param[in,out] jobPtr   Pointer to the job
 * \param[in]     jobObjectId     Id of the object
 * \return        TRUE if buffers are valid, FALSE otherwise.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Ipc_IsCryptoMacVerJobBuffersValid(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr,
  vHsm_JobObjectIdType jobObjectId);

/**********************************************************************************************************************
 *  vHsm_Ipc_IsKeyMJobBuffersValid()
 *********************************************************************************************************************/
/*!
 * \brief         Check if key management job contains valid buffers.
 * \details       -
 * \param[in,out] jobPtr   Pointer to the job
 * \param[in]     jobObjectId     Id of the object
 * \return        TRUE if buffers are valid, FALSE otherwise.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Ipc_IsKeyMJobBuffersValid(
  P2VAR(vHsm_KeyM_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr,
  vHsm_JobObjectIdType jobObjectId);

/**********************************************************************************************************************
 *  vHsm_Ipc_IsKeyMJobCopyPartialBuffersValid()
 *********************************************************************************************************************/
/*!
 * \brief         Check if key management job contains valid buffers.
 * \details       -
 * \param[in,out] jobPtr   Pointer to the job
 * \param[in]     jobObjectId     Id of the object
 * \return        TRUE if buffers are valid, FALSE otherwise.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Ipc_IsKeyMJobCopyPartialBuffersValid(
  P2VAR(vHsm_KeyM_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr,
  vHsm_JobObjectIdType jobObjectId);
#endif

#if (VHSM_REDIRECTION == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Ipc_CryptoJob_Redirection()
 *********************************************************************************************************************/
/*!
 * \brief         Process the input output redirection
 * \details       -
 * \param[in,out] job                Job where some input or output data shall be redirected
 * \param[in]     redirectionFlags   Flags which contain the information which data shall be redirected
 * \return        TRUE redirection could be performed, otherwise FALSE.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
VHSM_LOCAL_INLINE FUNC(boolean, VHSM_CODE) vHsm_Ipc_CryptoJob_Redirection(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job,
  uint8 redirectionFlags);

/**********************************************************************************************************************
 *  vHsm_Ipc_CryptoJob_RedirectionDeserialization()
 *********************************************************************************************************************/
/*!
 * \brief          Process the input output redirection deserialization
 * \details        -
 * \param[in,out]  dataPtrPtr         Pointer to the data pointer
 * \param[in,out]  lengthPtr          Pointer to the length
 * \param[in,out]  cryptokeyIdPtr     Pointer to the cryptoKeyId
 * \param[in,out]  keyElementIdPtr    Pointer to the keyElementId
 * \param[in]      redirectionFlags   Flags which contain the information which data shall be redirected
 * \param[in]      redirectionFlag    Which of the pointers shall be processed
 * \param[in,out]  retVal             Pointer to the retVal. This value will be set to FALSE when an error happens
 * \pre            -
 * \context        ANY
 * \reentrant      TRUE
 * \synchronous    TRUE
 */
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Ipc_CryptoJob_RedirectionDeserialization(
  P2VAR(const uint8*, AUTOMATIC, VHSM_APPL_VAR) dataPtrPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) lengthPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) cryptokeyIdPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) keyElementIdPtr,
  uint8 redirectionFlags,
  uint8 redirectionFlag,
  P2VAR(boolean, AUTOMATIC, VHSM_APPL_VAR) retVal);

#endif

#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
/**********************************************************************************************************************
 *  vHsm_Ipc_CryptoJob_Deserialize()
 *********************************************************************************************************************/
 /*!
 * \brief         Deserialization of a crypt job
 * \details       -
 * \param[in]     jobObjectId           Id of jobObject
 * \param[in]     ptrBuf                Pointer to buffer
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_CryptoJob_Deserialize(
  vHsm_JobObjectIdType jobObjectId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf);

/**********************************************************************************************************************
 *  vHsm_Ipc_KeyMJob_Deserialize()
 *********************************************************************************************************************/
/*!
 * \brief       Deserialization of key management job
 * \details     -
 * \param[in]   jobObjectId           Id of jobObject
 * \param[in]   ptrBuf                Pointer to buffer
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
  *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_KeyMJob_Deserialize(
  vHsm_JobObjectIdType jobObjectId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf);
#endif

/**********************************************************************************************************************
 *  vHsm_Ipc_Allocate()
 *********************************************************************************************************************/
/*!
 * \brief       Allocate a job request in the Ipc
 * \details     -
 * \param[in]   txChannelId             Channel where the request shall be allocated
 * \param[in]   jobResponseBufferSize   Size of the buffer which shall be allocated
 * \param[out]  jobResponseBufferPtr    Pointer to the allocated buffer
 * \return      E_OK if the allocation was successful, otherwise E_NOT_OK
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc_Allocate(
  vHsm_ChannelIdType txChannelId,
  uint32 jobResponseBufferSize,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) * jobResponseBufferPtr);

/**********************************************************************************************************************
 *  vHsm_Ipc_CommitTransmission()
 *********************************************************************************************************************/
/*!
 * \brief      Indicate that a new job request is available
 * \details    -
 * \param[in]  txChannelId    Channel which is used for the request
 * \pre        -
 * \context    ANY
 * \reentrant  TRUE
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_CommitTransmission(
  vHsm_ChannelIdType txChannelId);
#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
/**********************************************************************************************************************
 *  vHsm_Ipc_IsOutputValid()
 *********************************************************************************************************************/
/*!
 * \brief         Check the output pointer and length for validity
 * \details       -
 * \param[in]     outputPtr           outputPtr which shall be checked
 * \param[in,out]     localOutputInfoPtr  Pointer to the localOutputInfo
 * \param[out]    errorIdPtr          Pointer to the errorIdPtr which will be written, when something is invalid.
 * \return        E_OK if the verification was successful, otherwise E_NOT_OK
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc_IsOutputValid(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) outputPtr,
  P2VAR(vHsm_LocalOutputInfoType, AUTOMATIC, VHSM_APPL_VAR) localOutputInfoPtr,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) errorIdPtr);
#endif
#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(vHsm_Ipc_JobKindInfoType, VHSM_CONST) vHsm_Ipc_JobKindInfo[VHSM_NR_OF_JOBREQUESTKINDS] =
{ /* Job request kind                                        tx fct                                buffer size */
  /* VHSM_CRYPTO_JOBKIND            */{ VHSM_CRYPTO_JOBKIND, vHsm_Ipc_Transmit_CryptoJobResponse,  VHSM_CRYPTO_JOBTYPE_DESERIALIZED_BUF_SIZE, VHSM_CRYPTO_JOBRESULTTYPE_SERIALIZED_BUF_SIZE },
  /* VHSM_KEYM_JOBKIND              */{ VHSM_KEYM_JOBKIND,   vHsm_Ipc_Transmit_KeyMJobResponse,    VHSM_KEYM_JOBTYPE_DESERIALIZED_BUF_SIZE,   VHSM_KEYM_JOBRESULTTYPE_SERIALIZED_BUF_SIZE },
  /* VHSM_KEYM_COPY_PARTIAL_JOBKIND */{ VHSM_KEYM_JOBKIND,   vHsm_Ipc_Transmit_KeyMJobResponse,    VHSM_KEYM_JOBTYPE_DESERIALIZED_BUF_SIZE,   VHSM_KEYM_JOBRESULTTYPE_SERIALIZED_BUF_SIZE },
  /* VHSM_CRYPTO_MACGEN_JOBKIND     */{ VHSM_CRYPTO_JOBKIND, vHsm_Ipc_Transmit_CryptoJobResponse,  VHSM_CRYPTO_JOBTYPE_DESERIALIZED_BUF_SIZE, VHSM_CRYPTO_JOBRESULTTYPE_SERIALIZED_BUF_SIZE },
  /* VHSM_CRYPTO_MACVER_JOBKIND     */{ VHSM_CRYPTO_JOBKIND, vHsm_Ipc_Transmit_CryptoJobResponse,  VHSM_CRYPTO_JOBTYPE_DESERIALIZED_BUF_SIZE, VHSM_CRYPTO_JOBRESULTTYPE_SERIALIZED_BUF_SIZE },
  /* VHSM_CRYPTO_KEYDERIVE_JOBKIND  */{ VHSM_CRYPTO_JOBKIND, vHsm_Ipc_Transmit_CryptoJobResponse,  VHSM_CRYPTO_JOBTYPE_DESERIALIZED_BUF_SIZE, VHSM_CRYPTO_JOBRESULTTYPE_SERIALIZED_BUF_SIZE },
};

#if (VHSM_IPC_PROTOCOL_VERSION == 3u)
VHSM_LOCAL CONST(vHsm_Ipc3_GenericFunctionsType, VHSM_CONST) vHsm_Ipc3_GenericFunctions[VHSM_NR_OF_JOBREQUESTKINDS] = /* PRQA S 3218 */ /* MD_VHSM_3218_WORKSPACE_VAR */
{ /* Job request kind                  CalloutGetPtrs                             Factory               */
  /* VHSM_CRYPTO_JOBKIND            */ {vHsm_Ipc3_CryptoJob_CheckPtrMask,  vHsm_Ipc_CryptoJob_Factory },
  /* VHSM_KEYM_JOBKIND              */ {vHsm_Ipc3_KeyMJob_CheckPtrMask,    vHsm_Ipc_KeyM_Factory },
  /* VHSM_KEYM_COPY_PARTIAL_JOBKIND */ {vHsm_Ipc3_KeyMJob_CheckPtrMask,    vHsm_Ipc_KeyM_Factory },
  /* VHSM_CRYPTO_MACGEN_JOBKIND     */ {vHsm_Ipc3_CryptoJob_CheckPtrMask,  vHsm_Ipc_CryptoJob_Factory },
  /* VHSM_CRYPTO_MACVER_JOBKIND     */ {vHsm_Ipc3_CryptoJob_CheckPtrMask,  vHsm_Ipc_CryptoJob_Factory },
  /* VHSM_CRYPTO_KEYDERIVE_JOBKIND  */ {vHsm_Ipc3_CryptoJob_CheckPtrMask,  vHsm_Ipc_CryptoJob_Factory },
};
#else /* (VHSM_IPC_PROTOCOL_VERSION == 2u) */
VHSM_LOCAL CONST(vHsm_Ipc2_GenericFunctionsType, VHSM_CONST) vHsm_Ipc2_GenericFunctions[VHSM_NR_OF_JOBREQUESTKINDS] =
{ /* Job request kind                  rx fct                                 check fct for Crypto job                   check fct for KeyM job  */
  /* VHSM_CRYPTO_JOBKIND            */{ vHsm_Ipc_Receive_CryptoJobRequest,    vHsm_Ipc_IsCryptoJobBuffersValid,          NULL_PTR                                 },
  /* VHSM_KEYM_JOBKIND              */{ vHsm_Ipc_Receive_KeyMJobRequest,      NULL_PTR,                                  vHsm_Ipc_IsKeyMJobBuffersValid           },
  /* VHSM_KEYM_COPY_PARTIAL_JOBKIND */{ vHsm_Ipc_Receive_KeyMJobRequest,      NULL_PTR,                                  vHsm_Ipc_IsKeyMJobCopyPartialBuffersValid},
  /* VHSM_CRYPTO_MACGEN_JOBKIND     */{ vHsm_Ipc_Receive_CryptoJobRequest,    vHsm_Ipc_IsCryptoMacGenJobBuffersValid,    NULL_PTR                                 },
  /* VHSM_CRYPTO_MACVER_JOBKIND     */{ vHsm_Ipc_Receive_CryptoJobRequest,    vHsm_Ipc_IsCryptoMacVerJobBuffersValid,    NULL_PTR                                 },
  /* VHSM_CRYPTO_KEYDERIVE_JOBKIND  */{ vHsm_Ipc_Receive_CryptoJobRequest,    vHsm_Ipc_IsCryptoKeyDeriveJobBuffersValid, NULL_PTR                                 },
};
#endif

#define VHSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_Ipc_Allocate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc_Allocate(
  vHsm_ChannelIdType txChannelId,
  uint32 jobResponseBufferSize,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) * jobResponseBufferPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  uint32 readIdx;
  uint32 writeIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if requested job response buffer including header information does fit into a Tx channel entry.*/
  if ((jobResponseBufferSize + VHSM_IPC_CHANNEL_ENTRY_HEADER_SIZE) > VHSM_IPC_TX_CHANNEL_ENTRY_MEMORY_SIZE)
  {
    /* Error: Requested job response buffer including header information does not fit into a Tx channel entry. */
    retVal = E_NOT_OK;
  }
  else
  {
    /* #20 Use local copy of read index to prevent concurrency issues. */
    readIdx = vHsm_Ipc_GetTxChannelReadIdx(txChannelId); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
    writeIdx = vHsm_Ipc_GetTxChannelWriteIdx(txChannelId); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */

    /* #21 Is Tx channel already full? */
    if (writeIdx != readIdx)
    {
      /* Error: Tx Channel is full. */
      retVal = CRYPTO_E_QUEUE_FULL;
    }
    else  /* (writeIdx - readIdx) < VHSM_IPC_CHANNEL_SIZE */
    {
      /* #22 Get next available channel entry for transmission. */
      *jobResponseBufferPtr = (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Ipc_GetTxChannelBuffer(txChannelId); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Ipc_CommitTransmission()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_CommitTransmission(
  vHsm_ChannelIdType txChannelId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Increment the writeIdx to indicate that the response has been written */
  vHsm_Ipc_GetTxChannelWriteIdx(txChannelId) += 1u; /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
}

/**********************************************************************************************************************
 *  vHsm_Ipc_ProcessJobRequest()
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
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_ProcessJobRequest(
  vHsm_JobObjectIdType jobObjectId, vHsm_CallContextType callContext)
{
#if (VHSM_INTERRUPT_MODE == STD_ON)
  /* #10 Check if interrupt processing shall be performed and if the context is correct */
  if ((vHsm_IsIsrProcessingOfJobObjectInfo(jobObjectId) == TRUE)
    && (callContext >= vHsm_GetIsrForProcessingOfScheduling()))
  {
    /* fetching was done from ISR and this is an ISR job. */
    vHsm_SetStateOfJobObjects(jobObjectId, VHSM_JOB_STATE_PROCESSING);

    /* #20 Process the job directly */
    vHsm_JobProcessor_Execute(jobObjectId);
  }
  else
  {
    /* #30 Set the job to pending */
    vHsm_SetStateOfJobObjects(jobObjectId, VHSM_JOB_STATE_PENDING);

# if (VHSM_OS_SUPPORT == STD_ON)
    /* #35 If OS support is enabled, check if a context switch to Cat2 interrupt is needed */
    if (callContext == VHSM_CALL_CONTEXT_ISR1)
    {
      vHsm_Hal_TriggerInternalIrq();
    }
    else if (callContext == VHSM_CALL_CONTEXT_ISR2)
    {
      /* #36 Instruct the OS to start the corresponding task */
      vHsm_SetStateOfJobObjects(jobObjectId, VHSM_JOB_STATE_ACTIVATED);
      vHsm_Ipc_StartJobObjectTask(jobObjectId);
    }
    else
    {
      /* Do nothing in VHSM_CALL_CONTEXT_TASK */
    }
# endif
  }
#else
  /* #40 If interrupt mode is disabled, the job can be processed directly */
  vHsm_SetStateOfJobObjects(jobObjectId, VHSM_JOB_STATE_PROCESSING);
  vHsm_JobProcessor_Execute(jobObjectId);

  VHSM_DUMMY_STATEMENT(callContext); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
#endif
}

/**********************************************************************************************************************
 *  vHsm_Ipc_SendImmediateResponse()
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
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Ipc_SendImmediateResponse(
  vHsm_ChannelIdType rxChannelId,
  vHsm_JobRequestIdType jobRequestId,
  vHsm_JobRequestKindType jobRequestKind,
  Std_ReturnType retVal)
{
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) jobResponseBuffer;
  uint32 jobResponseBufferSize;
  uint8 ipcIdxTmp;

  if (vHsm_Ipc_JobKindInfo[jobRequestKind].processKind == VHSM_KEYM_JOBKIND)
  {
    jobResponseBufferSize = VHSM_KEYM_JOBRESULTTYPE_SERIALIZED_BUF_SIZE + VHSM_JOBRESPONSE_HEADER_SIZE;
  }
  else
  {
    jobResponseBufferSize = VHSM_CRYPTO_JOBRESULTTYPE_SERIALIZED_BUF_SIZE + VHSM_JOBRESPONSE_HEADER_SIZE;
  }

  /* #20 Allocate the response buffer */
  if (vHsm_Ipc_Allocate(rxChannelId, jobResponseBufferSize, &jobResponseBuffer) == E_OK)
  {
    /* #30 Add channel entry header */
#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
    vHsm_Serialize_Uint32(jobResponseBufferSize, jobResponseBuffer, 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    vHsm_Serialize_Uint32(jobRequestId, &jobResponseBuffer[4], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    vHsm_Serialize_Uint32(jobRequestKind, &jobResponseBuffer[8], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
#endif

    /* #31 Serialize CRYPTO_E_BUSY as retval */
    if (vHsm_Ipc_JobKindInfo[jobRequestKind].processKind == VHSM_KEYM_JOBKIND)
    {
#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
      vHsm_Serialize_Uint32(retVal, &jobResponseBuffer[12], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
      /* serialize zero as outputlength */
      vHsm_Serialize_Uint32(0, &jobResponseBuffer[16], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
#else
      vHsm_Serialize_Uint32( (jobRequestId & 0xFF0000FFu) | (((uint32)retVal) << 16u), jobResponseBuffer, 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
      /* serialize zero as outputlength */
      vHsm_Serialize_Uint32(0, &jobResponseBuffer[4], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
#endif
    }
    else
    {
#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
      /* JobId is ignored on driver side */
      vHsm_Serialize_Uint32(0u, &jobResponseBuffer[12], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */ /* JobId */
      vHsm_Serialize_Uint32(CRYPTO_JOBSTATE_IDLE, &jobResponseBuffer[16], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */ /* Jobstate */
      vHsm_Serialize_Uint32(retVal, &jobResponseBuffer[20], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */ /* retVal */

      /* serialize outputlength, secondary output length and verifypointer */
      vHsm_Serialize_Uint32(0, &jobResponseBuffer[24], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
      vHsm_Serialize_Uint32(0, &jobResponseBuffer[28], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
      vHsm_Serialize_Uint32(0xFE, &jobResponseBuffer[32], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
#else
      /* CRYPTO_JOBSTATE_IDLE is 0, therefore it is not necessary or-ing it behind retVal */
      vHsm_Serialize_Uint32((jobRequestId & 0xFF0000FFu) | (((uint32)retVal) << 16u), jobResponseBuffer, 0u);/* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
      vHsm_Serialize_Uint32(0, &jobResponseBuffer[4], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
      vHsm_Serialize_Uint32(0, &jobResponseBuffer[8], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
      vHsm_Serialize_Uint32(0, &jobResponseBuffer[12], 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
#endif
    }

    /* #32 Indicate that a response is available */
    vHsm_Ipc_GetTxChannelWriteIdx(rxChannelId) += 1u; /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */

    /* #33 Notify Host about transmission of the new job response */
    ipcIdxTmp = vHsm_Ipc_Idx;
    vHsm_TriggerResponseInterrupt(ipcIdxTmp); /* PRQA S 0306 */ /* MD_VHSM_0306_REGISTER_ACCESS */
  }
}

/**********************************************************************************************************************
 *  vHsm_Ipc_ReceiveJobRequest()
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
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc_ReceiveJobRequest(
  vHsm_ChannelIdType rxChannelId,
  P2VAR(vHsm_JobObjectIdType, AUTOMATIC, AUTOMATIC) jobObject)
{
  /* ----- Local Variables ---------------------------------------------- */
  vHsm_JobRequestIdType jobRequestIdTmp;
  vHsm_JobRequestKindType jobRequestKindTmp;
#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
  uint32 cancel;
#endif
  uint8 redirectionFlags;
  vHsm_JobObjectIdType jobObjectId;
  uint32 readIdx;
  uint32 writeIdx;
  Std_ReturnType retVal = E_NOT_OK;
#if (VHSM_IPC_PROTOCOL_VERSION == 3u)
  vHsm_Ipc3_Content vHsm_Ipc3_ParsedData;
#endif
  /* ----- Implementation ----------------------------------------------- */
  readIdx = vHsm_Ipc_GetRxChannelReadIdx(rxChannelId); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
  writeIdx = vHsm_Ipc_GetRxChannelWriteIdx(rxChannelId); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */

  /* #10 Receive a job request if Rx channel is not empty */
  if (readIdx != writeIdx)
  {
    /* VHSM_DEBUG_BREAKPOINT_5:
     * Set a breakpoint here to check if a job request is found in the IPC. No fetching of the job from the IPC is done yet.
     */

    P2CONST(uint8, AUTOMATIC, AUTOMATIC) jobRequestBuffer = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Ipc_GetRxChannelBuffer(rxChannelId); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */

    /* #20 Parse and remove job request header */
#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
    jobRequestIdTmp = vHsm_Deserialize_Uint32(jobRequestBuffer, 4u);/* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    jobRequestKindTmp = (vHsm_JobRequestKindType)vHsm_Deserialize_Uint32(jobRequestBuffer, 8u);/* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    cancel = vHsm_Deserialize_Uint32(jobRequestBuffer, 12u);/* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
#else
    jobRequestIdTmp = vHsm_Deserialize_Uint32(jobRequestBuffer, 0u);/* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    jobRequestKindTmp = (vHsm_JobRequestKindType)vHsm_Deserialize_Uint32(jobRequestBuffer, 4u);/* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
#endif
    /* #30 Check if jobRequestKind is valid */
    if (jobRequestKindTmp < VHSM_NR_OF_JOBREQUESTKINDS)
    {
      jobObjectId = (uint8)((jobRequestIdTmp & 0x0000FF00u) >> 8u);
#if (VHSM_REDIRECTION == STD_ON)
      redirectionFlags = (uint8)((jobRequestIdTmp & 0x00FF0000u) >> 16u);
#else
      redirectionFlags = 0u;
#endif
      SchM_Enter_vHsm_VHSM_EXCLUSIVE_AREA_0();
      if (jobObjectId >= vHsm_GetSizeOfJobObjects())
      {
        SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0();
      }
      /* check if job object is blocked */
      else if (vHsm_GetUsageRestrictionOfJobObjects(jobObjectId) != 0u)
      {
        /* Acknowledge the reception of the request */
        vHsm_Ipc_GetRxChannelReadIdx(rxChannelId) = writeIdx; /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */

        /* If locked, accept the job and directly send busy as response */
        vHsm_Ipc_SendImmediateResponse(rxChannelId, jobRequestIdTmp, jobRequestKindTmp, CRYPTO_E_BUSY);
        SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0();
      }
      /* check if jobobject is allowed in current IPC */
      else if ((vHsm_GetIpcMappingOfJobObjects(jobObjectId) & (1u << vHsm_Ipc_Idx)) == 0u)
      {
        /* Acknowledge the reception of the request */
        vHsm_Ipc_GetRxChannelReadIdx(rxChannelId) = writeIdx; /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */

        /* If locked, accept the job and directly send busy as response */
        vHsm_Ipc_SendImmediateResponse(rxChannelId, jobRequestIdTmp, jobRequestKindTmp, CRYPTO_E_BUSY);
        SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0();
      }
      /* #31 Check if object is busy */
      else if (vHsm_GetStateOfJobObjects(jobObjectId) != VHSM_JOB_STATE_IDLE)
      {
        /* #32 Acknowledge the reception of the request */
        vHsm_Ipc_GetRxChannelReadIdx(rxChannelId) = writeIdx; /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */

        /* #33 If locked, accept the job and directly send busy as response */
        vHsm_Ipc_SendImmediateResponse(rxChannelId, jobRequestIdTmp, jobRequestKindTmp, CRYPTO_E_BUSY);
        SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0();
      }
      else
      {
        vHsm_SetStateOfJobObjects(jobObjectId, VHSM_JOB_STATE_WAITING);
        SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0();

        *jobObject = jobObjectId;

#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
        vHsm_SetCancelFlagOfJobObjects(jobObjectId, (cancel == 1u));
        vHsm_SetJobRequestIdOfJobObjects(jobObjectId, (jobRequestIdTmp & 0x000000FFu));
#else
        vHsm_SetJobRequestIdOfJobObjects(jobObjectId, (jobRequestIdTmp & 0xFF0000FFu));
#endif
        vHsm_SetJobRequestKindOfJobObjects(jobObjectId, jobRequestKindTmp);
        vHsm_SetRedirectionFlagsOfJobObjects(jobObjectId, redirectionFlags);
        vHsm_SetIpcChannelOfJobObjects(jobObjectId, rxChannelId);
        vHsm_SetIpcInstanceOfJobObjects(jobObjectId, vHsm_Ipc_Idx);

        retVal = E_OK;

#if (VHSM_IPC_PROTOCOL_VERSION == 3u)
        /* #40 Call job request receive function */

        vHsm_SetProcessKindOfJobObjects(jobObjectId, jobRequestKindTmp);

        if (E_OK == vHsm_Ipc3_Job_Deserialize_Parser(&jobRequestBuffer[8], &vHsm_Ipc3_ParsedData, vHsm_Ipc3_GenericFunctions[jobRequestKindTmp].ptrCallout, jobObjectId))
        {
          vHsm_Ipc3_GenericFunctions[jobRequestKindTmp].factoryCallout(&vHsm_Ipc3_ParsedData, jobObjectId);
          /* #50 Commit the reception of the job request */
          vHsm_Ipc_GetRxChannelReadIdx(rxChannelId) = writeIdx; /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
        }
        else
        {
          /* #50 Commit the reception of the job request */
          vHsm_Ipc_GetRxChannelReadIdx(rxChannelId) = writeIdx; /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
          vHsm_Ipc_SendImmediateResponse(rxChannelId, jobRequestIdTmp, jobRequestKindTmp, E_NOT_OK);
          vHsm_SetStateOfJobObjects(jobObjectId, VHSM_JOB_STATE_IDLE);
          retVal = E_NOT_OK;
        }

#else /* (VHSM_IPC_PROTOCOL_VERSION == 2u) */
        vHsm_Ipc2_GenericFunctions[jobRequestKindTmp].rxFct(jobObjectId, &jobRequestBuffer[16]);
        /* #50 Commit the reception of the job request */
        vHsm_Ipc_GetRxChannelReadIdx(rxChannelId) = writeIdx; /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
#endif
      }
    }
  }
  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Ipc_IsPtrValid()
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
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc_IsPtrValid(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptr,
  uint32 length,
  uint8 accessParameters)
{
  Std_ReturnType retVal = E_NOT_OK;
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) startAddress;
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) stopAddress;
  vHsm_MemoryAreaIterType memAreaIdx;

  /* #10 Check for length 0 */
  if (length == 0u)
  {
    /* any pointer with length = 0 is allowed as it will not be read or written */
    retVal = E_OK;
  }
  else
  {
    /* #20 Check for overflow */
    if (&ptr[length] < ptr)
    {
      retVal = E_NOT_OK;
    }
    else
    {
      /* #30 Interate over memory areas */
      for (memAreaIdx = 0u; memAreaIdx < vHsm_GetSizeOfMemoryArea(); memAreaIdx++)
      {
        startAddress = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))(uint32)vHsm_GetStartOfMemoryArea(memAreaIdx); /* PRQA S 0306 */ /* MD_VHSM_0306_CHECK_MEMORY_LAYOUT */
        stopAddress = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))(uint32)vHsm_GetStopOfMemoryArea(memAreaIdx); /* PRQA S 0306 */ /* MD_VHSM_0306_CHECK_MEMORY_LAYOUT */

        /* #50 Check if the pointer is in the range */
        if ( (&ptr[0] >= startAddress)
          && (&ptr[length - 1u] <= stopAddress))
        {
          /* #60 Check for valid access rights */

          /* Check if pointer is in READWRITE which means it will be valid not depending on the requested access rights */
          if ( (vHsm_GetTypeOfMemoryArea(memAreaIdx) == VHSM_MEMORY_AREA_READWRITE)
            /* Pointer is in READ area (because HSM does not have something other than READ and READWRITE). This means the requested access MUST not contain the WRITE access. */
            || ((accessParameters & VHSM_MEM_ALLOW_READWRITE) != VHSM_MEM_ALLOW_READWRITE))
          {
            retVal = E_OK;
            break;
          } /* ELSE: Area was READ and READWRITE has been requested which is not valid. */
        }
      }
    }
  }

  /* #70 Return the result */
  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
/**********************************************************************************************************************
 *  vHsm_Ipc_IsOutputValid()
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
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc_IsOutputValid(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) outputPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(vHsm_LocalOutputInfoType, AUTOMATIC, VHSM_APPL_VAR) localOutputInfoPtr,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) errorIdPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  /* #50 Check the outputLengthPtr for NULL_PTR */
  if (localOutputInfoPtr->lengthPtr == NULL_PTR)
  {
    *errorIdPtr = VHSM_IPC_E_PARAM_POINTER;
  }
# if (VHSM_SETTING_ENABLE_UNALIGNED_ACCESS == STD_OFF)
  /* #51 Check the outputLengthPtr for alignment */
  else if (VHSM_IS_PTR_NOT_32BIT_ALIGNED(localOutputInfoPtr->lengthPtr) == TRUE) /* PRQA S 0306 */ /*  MD_VHSM_0306_POINTERCAST */
  {
    *errorIdPtr = VHSM_IPC_E_PARAM_POINTER;
  }
# endif
  /* #52 Check the outputLengthPtr for validity */
  else if (vHsm_Ipc_IsPtrValid(
    (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))localOutputInfoPtr->lengthPtr,
    sizeof(uint32),
    VHSM_MEM_ALLOW_READWRITE) == E_NOT_OK)
  {
    *errorIdPtr = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
  }
  else
  {
    /* Change the job to use a local copy of the ouputLengthPtr */
    localOutputInfoPtr->length = *localOutputInfoPtr->lengthPtr;

    /* #55 Check the outputPtr for validity */
    if (vHsm_Ipc_IsPtrValid(
      outputPtr,
      localOutputInfoPtr->length,
      VHSM_MEM_ALLOW_READWRITE) == E_NOT_OK)
    {
      *errorIdPtr = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
    }
    else
    {
      /* #100 Return E_OK if no invalid pointer has been found */
      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Ipc_IsCryptoJobBuffersValid()
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
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Ipc_IsCryptoJobBuffersValid(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  vHsm_JobObjectIdType jobObjectId)
{
  boolean retVal = FALSE;
  uint8 errorId = CRYPTO_E_NO_ERROR;
  uint32 secondaryInputLengthInBytes = jobPtr->jobPrimitiveInputOutput.secondaryInputLength;
  P2VAR(vHsm_LocalOutputType, AUTOMATIC, VHSM_APPL_VAR) localOutput = &vHsm_GetLocalOutputOfJobObjects(jobObjectId);

  localOutput->output.lengthPtr = jobPtr->jobPrimitiveInputOutput.outputLengthPtr;
  jobPtr->jobPrimitiveInputOutput.outputLengthPtr = &localOutput->output.length;

  localOutput->secondaryOutput.lengthPtr = jobPtr->jobPrimitiveInputOutput.secondaryOutputLengthPtr;
  jobPtr->jobPrimitiveInputOutput.secondaryOutputLengthPtr = &localOutput->secondaryOutput.length;

  /* #10 Check if the service is MacVerify and interpret the length accordingly as number of bits */
  if (jobPtr->jobPrimitiveInfo->primitiveInfo->service == CRYPTO_MACVERIFY)
  {
    secondaryInputLengthInBytes /= 8u;
    if ((jobPtr->jobPrimitiveInputOutput.secondaryInputLength % 8u) != 0u)
    {
      secondaryInputLengthInBytes += 1u;
    }
  }
  /* #15 Check key for validity */
  if (jobPtr->jobPrimitiveInfo->cryIfKeyId >= vHsm_GetSizeOfKeyInfo())
  {
    errorId = VHSM_IPC_E_PARAM_HANDLE;
  }
  /* #17 Check key if usage is allowed */
  else if (vHsm_IsKeyUsageDisallowed(jobPtr->jobPrimitiveInfo->cryIfKeyId) == TRUE)
  {
    /* RetVal already set */
  }
  /* #20 Check the inputPtr for validity */
  else if (vHsm_Ipc_IsPtrValid(
    jobPtr->jobPrimitiveInputOutput.inputPtr,
    jobPtr->jobPrimitiveInputOutput.inputLength,
    VHSM_MEM_ALLOW_READ) == E_NOT_OK)
  {
    errorId = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
  }
  /* #30 Check the secondaryInputPtr for validity */
  else if (vHsm_Ipc_IsPtrValid(
    jobPtr->jobPrimitiveInputOutput.secondaryInputPtr,
    secondaryInputLengthInBytes,
    VHSM_MEM_ALLOW_READ) == E_NOT_OK)
  {
    errorId = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
  }
  /* #40 Check the tertiaryInputPtr for validity */
  else if (vHsm_Ipc_IsPtrValid(
    jobPtr->jobPrimitiveInputOutput.tertiaryInputPtr,
    jobPtr->jobPrimitiveInputOutput.tertiaryInputLength,
    VHSM_MEM_ALLOW_READ) == E_NOT_OK)
  {
    errorId = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
  }
  /* #50 Check the output validity */
  else if (vHsm_Ipc_IsOutputValid(
    jobPtr->jobPrimitiveInputOutput.outputPtr,
    &localOutput->output,
    &errorId) == E_NOT_OK)
  {
    localOutput->output.lengthPtr = NULL_PTR;
    localOutput->secondaryOutput.lengthPtr = NULL_PTR;
    /* ErrorId is set in subfunction */
  }
  /* #60 Check the secondaryOutput validity */
  else if (vHsm_Ipc_IsOutputValid(
    jobPtr->jobPrimitiveInputOutput.secondaryOutputPtr,
    &localOutput->secondaryOutput,
    &errorId) == E_NOT_OK)
  {
    localOutput->output.lengthPtr = NULL_PTR;
    localOutput->secondaryOutput.lengthPtr = NULL_PTR;
    /* ErrorId is set in subfunction */
  }
  /* #70 Check the verifyPtr for NULL_PTR */
  else if (jobPtr->jobPrimitiveInputOutput.verifyPtr == NULL_PTR)
  {
    errorId = VHSM_IPC_E_PARAM_POINTER;
  }
  /* #71 Check the verifyPtr for validity */
  else if (vHsm_Ipc_IsPtrValid(
    (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))jobPtr->jobPrimitiveInputOutput.verifyPtr,
    sizeof(Crypto_VerifyResultType),
    VHSM_MEM_ALLOW_READWRITE) == E_NOT_OK)
  {
    errorId = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
  }
  else
  {
    /* #90 Translate KeyId */
    jobPtr->cryptoKeyId = vHsm_GetCryptoKeyIdOfKeyInfo(jobPtr->jobPrimitiveInfo->cryIfKeyId);

    /* #100 Return E_OK if no invalid pointer has been found */
    retVal = TRUE;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* Call Det if error occurred */
    (void)Det_ReportError(VHSM_MODULE_ID, VHSM_INSTANCE_ID, VHSM_IPC_SID_ISBUFFERVALID, errorId);
  }
# else
  VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6010,6030,6080 */ /* MD_MSR_STPTH */ /* MD_MSR_STCYC */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Ipc_IsCryptoKeyDeriveJobBuffersValid()
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
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Ipc_IsCryptoKeyDeriveJobBuffersValid(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  vHsm_JobObjectIdType jobObjectId)
{
  boolean retVal = FALSE;
  uint8 errorId = CRYPTO_E_NO_ERROR;
  P2VAR(vHsm_LocalOutputType, AUTOMATIC, VHSM_APPL_VAR) localOutput = &vHsm_GetLocalOutputOfJobObjects(jobObjectId);

  localOutput->output.lengthPtr = NULL_PTR;
  localOutput->secondaryOutput.lengthPtr = NULL_PTR;

  /* #15 Check key for validity */
  if (jobPtr->jobPrimitiveInputOutput.cryIfKeyId >= vHsm_GetSizeOfKeyInfo())
  {
    errorId = VHSM_IPC_E_PARAM_HANDLE;
  }
  /* #17 Check key if usage is allowed */
  else if (vHsm_IsKeyUsageDisallowed(jobPtr->jobPrimitiveInputOutput.cryIfKeyId) == TRUE)
  {
    /* RetVal already set */
  }
  /* #18 Check target key for validity */
  else if (jobPtr->jobPrimitiveInputOutput.targetCryIfKeyId >= vHsm_GetSizeOfKeyInfo())
  {
    errorId = VHSM_IPC_E_PARAM_HANDLE;
  }
  /* #19 Check target key if usage is allowed */
  else if (vHsm_IsKeyUsageDisallowed(jobPtr->jobPrimitiveInputOutput.targetCryIfKeyId) == TRUE)
  {
    /* RetVal already set */
  }
  else
  {
    /* #90 Translate KeyId */
    jobPtr->cryptoKeyId = vHsm_GetCryptoKeyIdOfKeyInfo(jobPtr->jobPrimitiveInputOutput.cryIfKeyId);

    /* #91 Translate target KeyId */
    jobPtr->targetCryptoKeyId = vHsm_GetCryptoKeyIdOfKeyInfo(jobPtr->jobPrimitiveInputOutput.targetCryIfKeyId);

    /* #100 Return E_OK if no invalid pointer has been found */
    retVal = TRUE;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* Call Det if error occurred */
    (void)Det_ReportError(VHSM_MODULE_ID, VHSM_INSTANCE_ID, VHSM_IPC_SID_ISBUFFERVALID, errorId);
  }
# else
  VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Ipc_IsCryptoMacVerJobBuffersValid()
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
 *
 *
 *
 *
 *
 *
 */
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Ipc_IsCryptoMacVerJobBuffersValid(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  vHsm_JobObjectIdType jobObjectId)
{
  boolean retVal = FALSE;
  uint8 errorId = CRYPTO_E_NO_ERROR;
  uint32 secondaryInputLengthInBytes = jobPtr->jobPrimitiveInputOutput.secondaryInputLength;
  P2VAR(vHsm_LocalOutputType, AUTOMATIC, VHSM_APPL_VAR) localOutput = &vHsm_GetLocalOutputOfJobObjects(jobObjectId);

  localOutput->output.lengthPtr = NULL_PTR;
  localOutput->secondaryOutput.lengthPtr = NULL_PTR;

  /* #10 Interpret the length accordingly as number of bits */
  secondaryInputLengthInBytes /= 8u;
  if ((jobPtr->jobPrimitiveInputOutput.secondaryInputLength % 8u) != 0u)
  {
    secondaryInputLengthInBytes += 1u;
  }

  /* #15 Check key for validity */
  if (jobPtr->jobPrimitiveInfo->cryIfKeyId >= vHsm_GetSizeOfKeyInfo())
  {
    errorId = VHSM_IPC_E_PARAM_HANDLE;
  }
  /* #17 Check key if usage is allowed */
  else if (vHsm_IsKeyUsageDisallowed(jobPtr->jobPrimitiveInfo->cryIfKeyId) == TRUE)
  {
    /* RetVal already set */
  }
  /* #20 Check the inputPtr for validity */
  else if (vHsm_Ipc_IsPtrValid(
    jobPtr->jobPrimitiveInputOutput.inputPtr,
    jobPtr->jobPrimitiveInputOutput.inputLength,
    VHSM_MEM_ALLOW_READ) == E_NOT_OK)
  {
    errorId = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
  }
  /* #30 Check the secondaryInputPtr for validity */
  else if (vHsm_Ipc_IsPtrValid(
    jobPtr->jobPrimitiveInputOutput.secondaryInputPtr,
    secondaryInputLengthInBytes,
    VHSM_MEM_ALLOW_READ) == E_NOT_OK)
  {
    errorId = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
  }
  /* #70 Check the verifyPtr for NULL_PTR */
  else if (jobPtr->jobPrimitiveInputOutput.verifyPtr == NULL_PTR)
  {
    errorId = VHSM_IPC_E_PARAM_POINTER;
  }
  /* #71 Check the verifyPtr for validity */
  else if (vHsm_Ipc_IsPtrValid(
    (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))jobPtr->jobPrimitiveInputOutput.verifyPtr,
    sizeof(Crypto_VerifyResultType),
    VHSM_MEM_ALLOW_READWRITE) == E_NOT_OK)
  {
    errorId = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
  }
  else
  {
    /* #90 Translate KeyId */
    jobPtr->cryptoKeyId = vHsm_GetCryptoKeyIdOfKeyInfo(jobPtr->jobPrimitiveInfo->cryIfKeyId);

    /* #100 Return E_OK if no invalid pointer has been found */
    retVal = TRUE;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* Call Det if error occurred */
    (void)Det_ReportError(VHSM_MODULE_ID, VHSM_INSTANCE_ID, VHSM_IPC_SID_ISBUFFERVALID, errorId);
  }
# else
  VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Ipc_IsCryptoMacGenJobBuffersValid()
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
 *
 */
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Ipc_IsCryptoMacGenJobBuffersValid(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  vHsm_JobObjectIdType jobObjectId)
{
  boolean retVal = FALSE;
  uint8 errorId = CRYPTO_E_NO_ERROR;
  P2VAR(vHsm_LocalOutputType, AUTOMATIC, VHSM_APPL_VAR) localOutput = &vHsm_GetLocalOutputOfJobObjects(jobObjectId);

  localOutput->output.lengthPtr = jobPtr->jobPrimitiveInputOutput.outputLengthPtr;
  jobPtr->jobPrimitiveInputOutput.outputLengthPtr = &localOutput->output.length;

  localOutput->secondaryOutput.lengthPtr = NULL_PTR;

  /* #15 Check key for validity */
  if (jobPtr->jobPrimitiveInfo->cryIfKeyId >= vHsm_GetSizeOfKeyInfo())
  {
    errorId = VHSM_IPC_E_PARAM_HANDLE;
  }
  /* #17 Check key if usage is allowed */
  else if (vHsm_IsKeyUsageDisallowed(jobPtr->jobPrimitiveInfo->cryIfKeyId) == TRUE)
  {
    /* RetVal already set */
  }
  /* #20 Check the inputPtr for validity */
  else if (vHsm_Ipc_IsPtrValid(
    jobPtr->jobPrimitiveInputOutput.inputPtr,
    jobPtr->jobPrimitiveInputOutput.inputLength,
    VHSM_MEM_ALLOW_READ) == E_NOT_OK)
  {
    errorId = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
  }
  /* #30 Check the output validity */
  else if (vHsm_Ipc_IsOutputValid(
    jobPtr->jobPrimitiveInputOutput.outputPtr,
    &localOutput->output,
    &errorId) == E_NOT_OK)
  {
    localOutput->output.lengthPtr = NULL_PTR;
    /* ErrorId is set in subfunction */
  }
  else
  {
    /* #90 Translate KeyId */
    jobPtr->cryptoKeyId = vHsm_GetCryptoKeyIdOfKeyInfo(jobPtr->jobPrimitiveInfo->cryIfKeyId);

    /* #100 Return E_OK if no invalid pointer has been found */
    retVal = TRUE;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* Call Det if error occurred */
    (void)Det_ReportError(VHSM_MODULE_ID, VHSM_INSTANCE_ID, VHSM_IPC_SID_ISBUFFERVALID, errorId);
  }
# else
  VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Ipc_IsKeyMJobBuffersValid()
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
 *
 *
 */
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Ipc_IsKeyMJobBuffersValid(
  P2VAR(vHsm_KeyM_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  vHsm_JobObjectIdType jobObjectId)
{
  boolean retVal = FALSE;
  uint8 errorId = CRYPTO_E_NO_ERROR;
  P2VAR(vHsm_LocalOutputType, AUTOMATIC, VHSM_APPL_VAR) localOutput = &vHsm_GetLocalOutputOfJobObjects(jobObjectId);

  localOutput->output.lengthPtr = jobPtr->inputOutput.outputLengthPtr;
  jobPtr->inputOutput.outputLengthPtr = &localOutput->output.length;

  localOutput->secondaryOutput.lengthPtr = NULL_PTR;

  if (jobPtr->action >= VHSM_KEYM_ACTION_SIZE)
  {
    /* RetVal already set */
  }
  /* #05 Check key for validity */
  else if (jobPtr->cryIfKeyId >= vHsm_GetSizeOfKeyInfo())
  {
    errorId = VHSM_IPC_E_PARAM_HANDLE;
  }
  /* #06 Check secondary key for validity */
  else if (jobPtr->secondaryCryIfKeyId >= vHsm_GetSizeOfKeyInfo())
  {
    errorId = VHSM_IPC_E_PARAM_HANDLE;
  }
  /* #07 Check key if usage is allowed */
  else if (vHsm_IsKeyUsageDisallowed(jobPtr->cryIfKeyId) == TRUE)
  {
    /* RetVal already set */
  }
  /* #08 Check secondary key for allowed usage only when secondary key is used by the action */
  else if ((vHsm_KeyM_SecondaryKeyUsage[jobPtr->action] == TRUE)
    && (vHsm_IsKeyUsageDisallowed(jobPtr->secondaryCryIfKeyId)))
  {
    /* RetVal already set */
  }
  /* #10 Check the inputPtr for validity */
  else if ( vHsm_Ipc_IsPtrValid(
    jobPtr->inputOutput.inputPtr,
    jobPtr->inputOutput.inputLength,
    VHSM_MEM_ALLOW_READ) == E_NOT_OK)
  {
    errorId = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
  }
  /* #20 Check the output validity */
  else if (vHsm_Ipc_IsOutputValid(
    jobPtr->inputOutput.outputPtr,
    &localOutput->output,
    &errorId) == E_NOT_OK)
  {
    localOutput->output.lengthPtr = NULL_PTR;
    /* ErrorId is set in subfunction */
  }
  else
  {
    /* #100 Return E_OK if no invalid pointer has been found */
    retVal = TRUE;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* Call Det if error occurred */
    (void)Det_ReportError(VHSM_MODULE_ID, VHSM_INSTANCE_ID, VHSM_IPC_SID_ISBUFFERVALID, errorId);
  }
# else
  VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6030,6080 */ /* MD_MSR_STCYC */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Ipc_IsKeyMJobCopyPartialBuffersValid()
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
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Ipc_IsKeyMJobCopyPartialBuffersValid(
  P2VAR(vHsm_KeyM_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  vHsm_JobObjectIdType jobObjectId)
{
  boolean retVal = FALSE;
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #05 Check key for validity */
  if (jobPtr->cryIfKeyId >= vHsm_GetSizeOfKeyInfo())
  {
    errorId = VHSM_IPC_E_PARAM_HANDLE;
  }
  /* #06 Check secondary key for validity */
  else if (jobPtr->secondaryCryIfKeyId >= vHsm_GetSizeOfKeyInfo())
  {
    errorId = VHSM_IPC_E_PARAM_HANDLE;
  }
  /* #07 Check key if usage is allowed */
  else if (vHsm_IsKeyUsageDisallowed(jobPtr->cryIfKeyId) == TRUE)
  {
    /* RetVal already set */
  }
  /* #08 Check secondary key if usage is allowed */
  else if (vHsm_IsKeyUsageDisallowed(jobPtr->secondaryCryIfKeyId) == TRUE)
  {
    /* RetVal already set */
  }
  else
  {
    /* #100 Return E_OK if no invalid pointer has been found */
    retVal = TRUE;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* Call Det if error occurred */
    (void)Det_ReportError(VHSM_MODULE_ID, VHSM_INSTANCE_ID, VHSM_IPC_SID_ISBUFFERVALID, errorId);
  }
# else
  VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
# endif

  VHSM_DUMMY_STATEMENT(jobObjectId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */

  return retVal;
}
#endif

#if (VHSM_IPC_PROTOCOL_VERSION == 3u)

/**********************************************************************************************************************
 *  vHsm_Ipc3_Job_Deserialize_Parser()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc3_Job_Deserialize_Parser(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf,
  P2VAR(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedContent,
  vHsm_Ipc3_CalloutCheckPtrMask_Type checkPtrFunc,
  vHsm_JobObjectIdType jobObjectId)
{
  Std_ReturnType retVal;
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #10 Read amount of input pointer, output pointer, key ids and constant data */
  uint32 offset = 8u;
  uint32 numOfPtrMask = vHsm_Deserialize_Uint32(ptrBuf, 0u); /* PRQA S 0310, 0306, 3305 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */

  /* save ptrMask into parsed data structure */
  parsedContent->numOfInputs = (uint8)(numOfPtrMask >> 24u);
  parsedContent->numOfOutputs = (uint8)(numOfPtrMask >> 16u);
  parsedContent->numOfKeys = (uint8)(numOfPtrMask >> 8u);
  parsedContent->numOfConst = (uint8)numOfPtrMask;

  parsedContent->ptrMask = (((1uL << parsedContent->numOfInputs) - 1uL) << 24u) | (((1uL << parsedContent->numOfOutputs) - 1uL) << 16u)| (((1uL << parsedContent->numOfKeys) - 1uL) << 8u);

  parsedContent->service = (Crypto_ServiceInfoType)vHsm_Deserialize_Uint32(ptrBuf, 4u); /* PRQA S 0310, 0306, 3305 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */

  /* #20 Check if amount of pointer is valid for job */
  if (checkPtrFunc(parsedContent) != E_OK)
  {
    retVal = E_NOT_OK;
    vHsm_SetValidRequestFlagOfJobObjects(jobObjectId, FALSE);
  }/* #30 Parse IPC buffer to data structure */
  else if (vHsm_Ipc3_ParseInputPtr(parsedContent, ptrBuf, &offset) != E_OK)
  {
    retVal = E_NOT_OK;
    vHsm_SetValidRequestFlagOfJobObjects(jobObjectId, FALSE);
    errorId = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
  }
  else if (vHsm_Ipc3_ParseOutputPtr(parsedContent, ptrBuf, &offset) != E_OK)
  {
    retVal = E_NOT_OK;
    vHsm_SetValidRequestFlagOfJobObjects(jobObjectId, FALSE);
    errorId = VHSM_IPC_E_POINTER_NOT_IN_WHITELIST;
  }
  else if (vHsm_Ipc3_ParseCryptoKeyIds(parsedContent, ptrBuf, &offset, &errorId) != E_OK)
  {
    retVal = E_NOT_OK;
    vHsm_SetValidRequestFlagOfJobObjects(jobObjectId, FALSE);
    /* nothing to do we have to differ between key>sizeofkeyinfo and keyusagedisallowed which will not result in DET */
  }
  else
  {
    vHsm_Ipc3_ParseConstData(parsedContent, ptrBuf, &offset);

    /* #40 Set job request valid/invalid */
    vHsm_SetValidRequestFlagOfJobObjects(jobObjectId, TRUE);
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* Call Det if error occurred */
    (void)Det_ReportError(VHSM_MODULE_ID, VHSM_INSTANCE_ID, VHSM_IPC_SID_ISBUFFERVALID, errorId);
  }
# else
  VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
# endif
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Ipc3_CryptoJob_CheckPtrMask()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc3_CryptoJob_CheckPtrMask(
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Check pointer mask for validity */
  if ( (parsedData->ptrMask & (~VHSM_IPC3_CRYPTOJOB_MAXPTRMASK) ) != 0u)
  {
    /* do nothing */
  }
  /* #20 Check amount of const data */
  else if(parsedData->numOfConst > VHSM_IPC3_JOB_CONSTDATA_MAX)
  {
    /* do nothing */
  }
  else
  {
    retVal = E_OK;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Ipc3_KeyMJob_CheckPtrMask()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc3_KeyMJob_CheckPtrMask(
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Check pointer mask for validity */
  if ((parsedData->ptrMask & (~VHSM_IPC3_KEYMJOB_MAXPTRMASK)) != 0u)
  {
    /* do nothing */
  }
  /* #20 Check amount of const data */
  else if (parsedData->numOfConst > VHSM_IPC3_JOB_CONSTDATA_MAX)
  {
    /* do nothing */
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Ipc3_ParseInputPtr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc3_ParseInputPtr(
  P2VAR(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedContent,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset)
{
  uint32 i;
  Std_ReturnType retVal = E_OK;
  uint32 tmp;
  for (i = 0u; i < parsedContent->numOfInputs; i++)
  {
    /* #10 Read input pointer from IPC buffer */
    /* PRQA S 0310, 0306, 3305 2 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */
    parsedContent->inputPtr[i] = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, *offset);
    parsedContent->inputLength[i] = vHsm_Deserialize_Uint32(ptrBuf, *offset + 4u);
    tmp = parsedContent->inputLength[i];

    /* #20 Check if the service is MacVerify and interpret the length accordingly as number of bits */
    if (parsedContent->service == CRYPTO_MACVERIFY)
    {
      tmp /= 8u;
      if ((parsedContent->inputLength[i] % 8u) != 0u)
      {
        tmp += 1u;
      }
    }

    /* #30 Check if input pointer is valid */
    if (vHsm_Ipc_IsPtrValid(
      parsedContent->inputPtr[i],
      tmp,
      VHSM_MEM_ALLOW_READ) == E_NOT_OK)
    {
      retVal |= E_NOT_OK;
    }

    /* #40 Increment offset */
    *offset += 8u;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Ipc3_ParseOutputPtr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc3_ParseOutputPtr(
  P2VAR(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedContent,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset)
{
  uint32 i;
  Std_ReturnType retVal = E_OK;
  for (i = 0u; i < parsedContent->numOfOutputs; i++)
  {
    /* #10 Read output pointer from IPC buffer */
    /* PRQA S 0310, 0306, 3305 2 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */
    parsedContent->outputPtr[i] = (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, *offset);
    parsedContent->outputLength[i] = vHsm_Deserialize_Uint32(ptrBuf, *offset + 4u);

    /* #20 Check if output pointer is valid */
    if (vHsm_Ipc_IsPtrValid(
      parsedContent->outputPtr[i],
      parsedContent->outputLength[i],
      VHSM_MEM_ALLOW_READWRITE) == E_NOT_OK)
    {
      retVal = E_NOT_OK;
      break;
    }
    else
    {
      /* do nothing */
    }

    /* #30 Increment offset */
    *offset += 8u;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Ipc3_ParseCryptoKeyIds()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc3_ParseCryptoKeyIds(
  P2VAR(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedContent,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) errorIdPtr)
{
  uint32 i;
  Std_ReturnType retVal = E_OK;
  for (i = 0u; i < parsedContent->numOfKeys; i++)
  {
    /* #10 Read key id from IPC buffer */
    parsedContent->keyIds[i] = vHsm_Deserialize_Uint32(ptrBuf, *offset);  /* PRQA S 0310, 0306, 3305 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */

    /* #20 Check if key is valid */
    if (parsedContent->keyIds[i] >= vHsm_GetSizeOfKeyInfo())
    {
      *errorIdPtr = VHSM_IPC_E_PARAM_HANDLE;
      retVal |= E_NOT_OK;
    }
    /* Check if key can be used */
    else if (vHsm_IsKeyUsageDisallowed(parsedContent->keyIds[i]) == TRUE)
    {
      /* RetVal already set */
      retVal |= E_NOT_OK;
    }
    else
    {
      /* do nothing */
    }

    /* #30 Increment offset */
    *offset += 4u;

  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Ipc3_ParseConstData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc3_ParseConstData(
  P2VAR(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedContent,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset)
{
  uint32 i;

  for (i = 0u; i < parsedContent->numOfConst; i++)
  {
    /* #10 Read constant data from IPC buffer */
    parsedContent->constData[i] = vHsm_Deserialize_Uint32(ptrBuf, *offset);  /* PRQA S 0310, 0306, 3305 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */
    /* #15 Increment offset */
    *offset += 4u;
  }
}

/**********************************************************************************************************************
 *  vHsm_Ipc_CryptoJob_Factory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_CryptoJob_Factory(
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData,
  vHsm_JobObjectIdType jobObjectId
)
{
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) ptrVal = &vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job;

  vHsm_SetProcessKindOfJobObjects(jobObjectId, VHSM_CRYPTO_JOBKIND);

  /* #10 Set job data */
  vHsm_Ipc_SetCryptoJobData(ptrVal, parsedData, jobObjectId);

# if(VHSM_SETTING_ENABLE_API_PREPARE_JOB_DATA == STD_ON)
  /* #20 Prepare job data */
  /* Let the HAL prepare input and output pointers */
  vHsm_Hal_PrepareCryptoJobDataWithoutLengths(&ptrVal->job.jobPrimitiveInputOutput);
# endif

# if (VHSM_REDIRECTION == STD_ON)
  /* #30 Perform redirection */
  vHsm_Ipc3_CryptoJob_Redirection(jobObjectId);
# endif
}

/**********************************************************************************************************************
 *  vHsm_Ipc_SetCryptoJobData()
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
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_SetCryptoJobData(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) ptrVal,
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData,
  vHsm_JobObjectIdType jobObjectId
)
{
  uint32 tmp;
  P2VAR(vHsm_LocalOutputType, AUTOMATIC, VHSM_APPL_VAR) localOutput = &vHsm_GetLocalOutputOfJobObjects(jobObjectId);

  /* #10 Set job inputs */
  switch (parsedData->numOfInputs)
  {
  case 3u:
    ptrVal->job.jobPrimitiveInputOutput.tertiaryInputPtr = parsedData->inputPtr[2u];
    ptrVal->job.jobPrimitiveInputOutput.tertiaryInputLength = parsedData->inputLength[2u];
    /* Falls through. */
  case 2u: /* PRQA S 2003 */ /* MD_VHSM_NO_BREAK_IN_SWITCH */
    ptrVal->job.jobPrimitiveInputOutput.secondaryInputPtr = parsedData->inputPtr[1u];
    ptrVal->job.jobPrimitiveInputOutput.secondaryInputLength = parsedData->inputLength[1u];
    /* Falls through. */
  case 1u: /* PRQA S 2003 */ /* MD_VHSM_NO_BREAK_IN_SWITCH */
    ptrVal->job.jobPrimitiveInputOutput.inputPtr = parsedData->inputPtr[0u];
    ptrVal->job.jobPrimitiveInputOutput.inputLength = parsedData->inputLength[0u];
    break;
  default:
    /* intentionally left empty */
    break;
  }

  /* #20 Set job outputs */
  switch (parsedData->numOfOutputs)
  {
  case 2u:
    ptrVal->job.jobPrimitiveInputOutput.secondaryOutputPtr = parsedData->outputPtr[1u];
    localOutput->secondaryOutputLength = parsedData->outputLength[1u];
    ptrVal->job.jobPrimitiveInputOutput.secondaryOutputLengthPtr = &localOutput->secondaryOutputLength;
    /* if two outputs are available there is a first output */
    /* Falls through. */
  case 1u: /* PRQA S 2003 */ /* MD_VHSM_NO_BREAK_IN_SWITCH */
    ptrVal->job.jobPrimitiveInputOutput.outputPtr = parsedData->outputPtr[0u];
    localOutput->outputLength = parsedData->outputLength[0u];
    ptrVal->job.jobPrimitiveInputOutput.outputLengthPtr = &localOutput->outputLength;
    break;
  default:
    /* intentionally left empty */
    break;
  }

  /* #30 Set job keyids */
  switch (parsedData->numOfKeys)
  {
  case 2u:
    ptrVal->job.jobPrimitiveInputOutput.targetCryIfKeyId = parsedData->keyIds[1u];
    /* if two outputs are available there is a first output */
    /* Falls through. */
  case 1: /* PRQA S 2003 */ /* MD_VHSM_NO_BREAK_IN_SWITCH */
    ptrVal->job.jobPrimitiveInputOutput.cryIfKeyId = parsedData->keyIds[0u];
    break;
  default: /* COV_VHSM_CASE_DEFAULT */
    /* intentionally left empty */
    break;
  }

  /* #40 Set job const data */
  /* get shifted values */
  tmp = parsedData->constData[0u];
  vHsm_Api_TempJob_SetFamily(ptrVal, (Crypto_AlgorithmFamilyType)(tmp & 0xFFu));
  vHsm_Api_TempJob_SetMode(ptrVal, (Crypto_AlgorithmModeType)((tmp >> 8u) & 0xFFu));
  vHsm_Api_TempJob_SetSecondaryFamily(ptrVal, (Crypto_AlgorithmSecondaryFamilyType)((tmp >> 16u) & 0xFFu));
  vHsm_Api_TempJob_SetProcessing(ptrVal, CRYPTO_PROCESSING_SYNC);
  vHsm_SetProcessingTypeOfJobObjects(jobObjectId, (Crypto_ProcessingType)((tmp >> 24u) & 0x01u));
  ptrVal->job.jobState = (Crypto_JobStateType)((tmp >> 25u) & 0x07u); /* PRQA S 4342, 4394 */ /* MD_VHSM_IPC3_SHIFTVALUES_SIGNEDTYPECONVERSION */
  vHsm_SetCancelFlagOfJobObjects(jobObjectId, (vHsm_CancelFlagOfJobObjectsType)((tmp >> 28u) & 0x01u)); /* PRQA S 4340, 4394 */ /* MD_VHSM_IPC3_SHIFTVALUES_SIGNEDTYPECONVERSION */
# if (VHSM_SUPPORT_SAVE_RESTORE_CONTEXT == STD_ON)
  ptrVal->job.jobPrimitiveInputOutput.mode = (Crypto_OperationModeType)(parsedData->constData[3u] & 0xFFu);
# else
  ptrVal->job.jobPrimitiveInputOutput.mode = (Crypto_OperationModeType)((tmp >> 29u));
# endif

  vHsm_Api_TempJob_SetKeyLength(ptrVal, parsedData->constData[1u]);
  vHsm_Api_TempJob_SetJobId(ptrVal, vHsm_Ipc_MaskIpcChannelToJobId((Crypto_ProcessingType)parsedData->constData[2u]));

  vHsm_Api_TempJob_SetService(ptrVal, parsedData->service);
  /* Set verify value to unused value which will prevent the driver on host core to write the verify value to the provided verifyPtr */
  localOutput->verifyResult = 0xFEu;
  /* Set the verifyPtr to the local copy */
  ptrVal->job.jobPrimitiveInputOutput.verifyPtr = &localOutput->verifyResult;

  vHsm_Api_TempJob_SetCryIfKeyId(ptrVal, ptrVal->job.jobPrimitiveInputOutput.cryIfKeyId);

  /* #60 Translate KeyId */
  ptrVal->job.cryptoKeyId = vHsm_GetCryptoKeyIdOfKeyInfo(ptrVal->job.jobPrimitiveInputOutput.cryIfKeyId);

  /* #70 Translate target KeyId */
  ptrVal->job.targetCryptoKeyId = vHsm_GetCryptoKeyIdOfKeyInfo(ptrVal->job.jobPrimitiveInputOutput.targetCryIfKeyId);
}/* PRQA S 6050 */ /* MD_MSR_STCAL */

# if (VHSM_REDIRECTION == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Ipc3_CryptoJob_Redirection()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc3_CryptoJob_Redirection(
  vHsm_JobObjectIdType jobObjectId
)
{
  if (vHsm_GetRedirectionFlagsOfJobObjects(jobObjectId) == 0u)
  {
    /* No redirection */
    vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobRedirectionInfoRef = NULL_PTR;
  }
  else if (vHsm_GetProcessJobOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfChannelInfo(jobObjectId)) != Crypto_30_LibCv_ProcessJob)
  {
    /* Only LibCv supports redirection */
    vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobRedirectionInfoRef = NULL_PTR;
    vHsm_SetValidRequestFlagOfJobObjects(jobObjectId, FALSE);
  }
  else
  {
    /* #10 Perform redirection */
    vHsm_SetValidRequestFlagOfJobObjects(jobObjectId, vHsm_Ipc_CryptoJob_Redirection(&vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job, vHsm_GetRedirectionFlagsOfJobObjects(jobObjectId)));
  }
}
# endif

/**********************************************************************************************************************
 *  vHsm_Ipc_KeyM_Factory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_KeyM_Factory(
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData,
  vHsm_JobObjectIdType jobObjectId
)
{
  P2VAR(vHsm_KeyM_JobType, AUTOMATIC, VHSM_APPL_VAR) ptrVal = &vHsm_GetJobDataOfJobObjects(jobObjectId).keyM_Job;

  /* #10 Set job inputs */
  vHsm_Ipc_SetKeyMJobData(ptrVal, parsedData, jobObjectId);

# if(VHSM_SETTING_ENABLE_API_PREPARE_JOB_DATA == STD_ON)
  /* #20 Prepare job data */
  /* Let the HAL prepare input and output pointers */
  vHsm_Hal_PrepareKeyMJobDataWithoutLengths(&ptrVal->inputOutput);
# endif
}

/**********************************************************************************************************************
 *  vHsm_Ipc_SetKeyMJobData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_SetKeyMJobData(
  P2VAR(vHsm_KeyM_JobType, AUTOMATIC, VHSM_APPL_VAR) ptrVal,
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData,
  vHsm_JobObjectIdType jobObjectId
)
{
  P2VAR(vHsm_LocalOutputType, AUTOMATIC, VHSM_APPL_VAR) localOutput = &vHsm_GetLocalOutputOfJobObjects(jobObjectId);
  vHsm_SetProcessingTypeOfJobObjects(jobObjectId, CRYPTO_PROCESSING_SYNC);

  /* #10 Set job inputs */
  if (parsedData->numOfInputs > 0u)
  {
    ptrVal->inputOutput.inputPtr = parsedData->inputPtr[0u];
    ptrVal->inputOutput.inputLength = parsedData->inputLength[0u];
  }
  /* #20 Set job outputs */
  if (parsedData->numOfOutputs > 0u)
  {
    ptrVal->inputOutput.outputPtr = parsedData->outputPtr[0u];
    localOutput->outputLength = parsedData->outputLength[0u];
    ptrVal->inputOutput.outputLengthPtr = &localOutput->outputLength;
  }
  /* #30 Set job key ids */
  ptrVal->cryIfKeyId = parsedData->keyIds[0u];
  if (parsedData->numOfKeys > 1u)
  {
    ptrVal->secondaryCryIfKeyId = parsedData->keyIds[1u];
  }

  /* #40 Set job const data */
  ptrVal->action = parsedData->constData[0u];
  ptrVal->keyElementId = parsedData->constData[1u];
  ptrVal->secondaryKeyElementId = parsedData->constData[2u];

  /* key copy partial jobkind */
  if (parsedData->numOfConst > 3u)
  {
    ptrVal->inputOutput.keyElementSourceOffset = parsedData->constData[3u];
    ptrVal->inputOutput.keyElementTargetOffset = parsedData->constData[4u];
    ptrVal->inputOutput.keyElementCopyLength = parsedData->constData[5u];
  }
}

#endif

#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
/**********************************************************************************************************************
 *  vHsm_Ipc_CryptoJob_Deserialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_CryptoJob_Deserialize(
  vHsm_JobObjectIdType jobObjectId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) ptrVal = &vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Deserialize the crypto job from the IPC buffer */
  switch (vHsm_GetJobRequestKindOfJobObjects(jobObjectId))
  {
    case VHSM_CRYPTO_MACVER_JOBKIND:
      /* PRQA S 0310, 0306, 3305 15 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */
      ptrVal->job.jobState = (Crypto_JobStateType)vHsm_Deserialize_Uint32(ptrBuf, 0u);
      ptrVal->job.jobPrimitiveInputOutput.inputPtr = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 4u);
      ptrVal->job.jobPrimitiveInputOutput.inputLength = vHsm_Deserialize_Uint32(ptrBuf, 8u);
      ptrVal->job.jobPrimitiveInputOutput.secondaryInputPtr = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 12u);
      ptrVal->job.jobPrimitiveInputOutput.secondaryInputLength = vHsm_Deserialize_Uint32(ptrBuf, 16u);
      ptrVal->job.jobPrimitiveInputOutput.verifyPtr = (P2VAR(Crypto_VerifyResultType, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 20u);
      ptrVal->job.jobPrimitiveInputOutput.mode = (Crypto_OperationModeType)vHsm_Deserialize_Uint32(ptrBuf, 24u);
      vHsm_Api_TempJob_SetService(ptrVal, CRYPTO_MACVERIFY);
      vHsm_Api_TempJob_SetFamily(ptrVal, (Crypto_AlgorithmFamilyType)vHsm_Deserialize_Uint32(ptrBuf, 28u));
      vHsm_Api_TempJob_SetMode(ptrVal, (Crypto_AlgorithmModeType)vHsm_Deserialize_Uint32(ptrBuf, 32u));
      vHsm_Api_TempJob_SetSecondaryFamily(ptrVal, CRYPTO_ALGOFAM_NOT_SET);
      vHsm_Api_TempJob_SetProcessing(ptrVal, CRYPTO_PROCESSING_SYNC);
      vHsm_SetProcessingTypeOfJobObjects(jobObjectId, (Crypto_ProcessingType)vHsm_Deserialize_Uint32(ptrBuf, 36u));
      vHsm_Api_TempJob_SetJobId(ptrVal, vHsm_Ipc_MaskIpcChannelToJobId((Crypto_ProcessingType)vHsm_Deserialize_Uint32(ptrBuf, 40u)));
      vHsm_Api_TempJob_SetCryIfKeyId(ptrVal, vHsm_Deserialize_Uint32(ptrBuf, 44u));

      break;
    case VHSM_CRYPTO_MACGEN_JOBKIND:
      /* PRQA S 0310, 0306, 3305 14 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */
      ptrVal->job.jobState = (Crypto_JobStateType)vHsm_Deserialize_Uint32(ptrBuf, 0u);
      ptrVal->job.jobPrimitiveInputOutput.inputPtr = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 4u);
      ptrVal->job.jobPrimitiveInputOutput.inputLength = vHsm_Deserialize_Uint32(ptrBuf, 8u);
      ptrVal->job.jobPrimitiveInputOutput.outputPtr = (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 12u);
      ptrVal->job.jobPrimitiveInputOutput.outputLengthPtr = (P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 16u);
      ptrVal->job.jobPrimitiveInputOutput.mode = (Crypto_OperationModeType)vHsm_Deserialize_Uint32(ptrBuf, 20u);
      vHsm_Api_TempJob_SetService(ptrVal, CRYPTO_MACGENERATE);
      vHsm_Api_TempJob_SetFamily(ptrVal, (Crypto_AlgorithmFamilyType)vHsm_Deserialize_Uint32(ptrBuf, 24u));
      vHsm_Api_TempJob_SetMode(ptrVal, (Crypto_AlgorithmModeType)vHsm_Deserialize_Uint32(ptrBuf, 28u));
      vHsm_Api_TempJob_SetSecondaryFamily(ptrVal, CRYPTO_ALGOFAM_NOT_SET);
      vHsm_Api_TempJob_SetProcessing(ptrVal, CRYPTO_PROCESSING_SYNC);
      vHsm_SetProcessingTypeOfJobObjects(jobObjectId, (Crypto_ProcessingType)vHsm_Deserialize_Uint32(ptrBuf, 32u));
      vHsm_Api_TempJob_SetJobId(ptrVal, vHsm_Ipc_MaskIpcChannelToJobId((Crypto_ProcessingType)vHsm_Deserialize_Uint32(ptrBuf, 36u)));
      vHsm_Api_TempJob_SetCryIfKeyId(ptrVal, vHsm_Deserialize_Uint32(ptrBuf, 40u));
      break;

    case VHSM_CRYPTO_KEYDERIVE_JOBKIND:
      /* PRQA S 0310, 0306, 3305 11 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */
      ptrVal->job.jobState = (Crypto_JobStateType)vHsm_Deserialize_Uint32(ptrBuf, 0u);
      ptrVal->job.jobPrimitiveInputOutput.mode = (Crypto_OperationModeType)vHsm_Deserialize_Uint32(ptrBuf, 4u);
      vHsm_Api_TempJob_SetService(ptrVal, CRYPTO_KEYDERIVE);
      vHsm_Api_TempJob_SetFamily(ptrVal, (Crypto_AlgorithmFamilyType)vHsm_Deserialize_Uint32(ptrBuf, 8u));
      vHsm_Api_TempJob_SetMode(ptrVal, (Crypto_AlgorithmModeType)vHsm_Deserialize_Uint32(ptrBuf, 12u));
      vHsm_Api_TempJob_SetSecondaryFamily(ptrVal, (Crypto_AlgorithmFamilyType)vHsm_Deserialize_Uint32(ptrBuf, 16u));
      vHsm_Api_TempJob_SetProcessing(ptrVal, CRYPTO_PROCESSING_SYNC);
      vHsm_SetProcessingTypeOfJobObjects(jobObjectId, (Crypto_ProcessingType)vHsm_Deserialize_Uint32(ptrBuf, 20u));
      vHsm_Api_TempJob_SetJobId(ptrVal, vHsm_Ipc_MaskIpcChannelToJobId((Crypto_ProcessingType)vHsm_Deserialize_Uint32(ptrBuf, 24u)));
      ptrVal->job.jobPrimitiveInputOutput.targetCryIfKeyId= vHsm_Deserialize_Uint32(ptrBuf, 28u);
      ptrVal->job.jobPrimitiveInputOutput.cryIfKeyId = vHsm_Deserialize_Uint32(ptrBuf, 32u);
      break;

    default:
      /* PRQA S 0310, 0306, 3305 21 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */
      ptrVal->job.jobState = (Crypto_JobStateType)vHsm_Deserialize_Uint32(ptrBuf, 0u);
      ptrVal->job.jobPrimitiveInputOutput.inputPtr = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 4u);
      ptrVal->job.jobPrimitiveInputOutput.inputLength = vHsm_Deserialize_Uint32(ptrBuf, 8u);
      ptrVal->job.jobPrimitiveInputOutput.secondaryInputPtr = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 12u);
      ptrVal->job.jobPrimitiveInputOutput.secondaryInputLength = vHsm_Deserialize_Uint32(ptrBuf, 16u);
      ptrVal->job.jobPrimitiveInputOutput.tertiaryInputPtr = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 20u);
      ptrVal->job.jobPrimitiveInputOutput.tertiaryInputLength = vHsm_Deserialize_Uint32(ptrBuf, 24u);
      ptrVal->job.jobPrimitiveInputOutput.outputPtr = (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 28u);
      ptrVal->job.jobPrimitiveInputOutput.outputLengthPtr = (P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 32u);
      ptrVal->job.jobPrimitiveInputOutput.secondaryOutputPtr = (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 36u);
      ptrVal->job.jobPrimitiveInputOutput.secondaryOutputLengthPtr = (P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 40u);
      ptrVal->job.jobPrimitiveInputOutput.verifyPtr = (P2VAR(Crypto_VerifyResultType, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 44u);
      ptrVal->job.jobPrimitiveInputOutput.mode = (Crypto_OperationModeType)vHsm_Deserialize_Uint32(ptrBuf, 48u);
      vHsm_Api_TempJob_SetService(ptrVal, (Crypto_ServiceInfoType)vHsm_Deserialize_Uint32(ptrBuf, 52u));
      vHsm_Api_TempJob_SetFamily(ptrVal, (Crypto_AlgorithmFamilyType)vHsm_Deserialize_Uint32(ptrBuf, 56u));
      vHsm_Api_TempJob_SetMode(ptrVal, (Crypto_AlgorithmModeType)vHsm_Deserialize_Uint32(ptrBuf, 60u));
      vHsm_Api_TempJob_SetSecondaryFamily(ptrVal, (Crypto_AlgorithmSecondaryFamilyType)vHsm_Deserialize_Uint32(ptrBuf, 64u));
      vHsm_Api_TempJob_SetProcessing(ptrVal, CRYPTO_PROCESSING_SYNC);
      vHsm_SetProcessingTypeOfJobObjects(jobObjectId, (Crypto_ProcessingType)vHsm_Deserialize_Uint32(ptrBuf, 68u));
      vHsm_Api_TempJob_SetJobId(ptrVal, vHsm_Ipc_MaskIpcChannelToJobId((Crypto_ProcessingType)vHsm_Deserialize_Uint32(ptrBuf, 72u)));
      vHsm_Api_TempJob_SetCryIfKeyId(ptrVal, vHsm_Deserialize_Uint32(ptrBuf, 76u));
      break;
  }
}

/**********************************************************************************************************************
 *  vHsm_Ipc_KeyMJob_Deserialize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Ipc_KeyMJob_Deserialize(
  vHsm_JobObjectIdType jobObjectId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrBuf)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(vHsm_KeyM_JobType, AUTOMATIC, VHSM_APPL_VAR) ptrVal = &vHsm_GetJobDataOfJobObjects(jobObjectId).keyM_Job;

  /* ----- Implementation ----------------------------------------------- */
  vHsm_SetProcessingTypeOfJobObjects(jobObjectId, CRYPTO_PROCESSING_SYNC);

  /* #10 Deserialize a KeyM job from the IPC buffer */
  switch (vHsm_GetJobRequestKindOfJobObjects(jobObjectId))
  {
  case VHSM_KEYM_JOBKIND:
    ptrVal->action = vHsm_Deserialize_Uint32(ptrBuf, 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->cryIfKeyId = vHsm_Deserialize_Uint32(ptrBuf, 4u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->secondaryCryIfKeyId = vHsm_Deserialize_Uint32(ptrBuf, 8u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->keyElementId = vHsm_Deserialize_Uint32(ptrBuf, 12u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->secondaryKeyElementId = vHsm_Deserialize_Uint32(ptrBuf, 16u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->inputOutput.inputPtr = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 20u);   /* PRQA S 0310, 0306, 3305 5 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */
    ptrVal->inputOutput.inputLength = vHsm_Deserialize_Uint32(ptrBuf, 24u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->inputOutput.outputPtr = (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 28u);   /* PRQA S 0310, 0306, 3305 5 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */
    ptrVal->inputOutput.outputLengthPtr = (P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR))vHsm_Deserialize_Ptr32(ptrBuf, 32u);   /* PRQA S 0310, 0306, 3305 5 */ /* MD_VHSM_SERIALIZATION_PTR_MACRO */
    break;
  case VHSM_KEYM_COPY_PARTIAL_JOBKIND:
    ptrVal->action = vHsm_Deserialize_Uint32(ptrBuf, 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->cryIfKeyId = vHsm_Deserialize_Uint32(ptrBuf, 4u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->secondaryCryIfKeyId = vHsm_Deserialize_Uint32(ptrBuf, 8u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->keyElementId = vHsm_Deserialize_Uint32(ptrBuf, 12u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->secondaryKeyElementId = vHsm_Deserialize_Uint32(ptrBuf, 16u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->inputOutput.keyElementSourceOffset = vHsm_Deserialize_Uint32(ptrBuf, 20u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->inputOutput.keyElementTargetOffset = vHsm_Deserialize_Uint32(ptrBuf, 24u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    ptrVal->inputOutput.keyElementCopyLength = vHsm_Deserialize_Uint32(ptrBuf, 28u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    break;
  default: /* COV_VHSM_CASE_DEFAULT */ /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
    break;
  }
}
#endif
/**********************************************************************************************************************
 *  vHsm_Ipc_Transmit_CryptoJobResponse()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Ipc_Transmit_CryptoJobResponse(
  vHsm_JobObjectIdType jobObjectId, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) jobResponseBuffer)
{
  /* Add job response header */
#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
  /* PRQA S 0310, 3305 2 */ /* MD_VHSM_SERIALIZATION_MACRO */
  vHsm_Serialize_Uint32(vHsm_GetJobRequestIdOfJobObjects(jobObjectId), jobResponseBuffer, 0u);
  vHsm_Serialize_Uint32(vHsm_GetJobRequestKindOfJobObjects(jobObjectId), jobResponseBuffer, 4u);
  /* #10 Serialize the result of a crypto job to the IPC buffer */
  /* PRQA S 0310, 3305 2 */ /* MD_VHSM_SERIALIZATION_MACRO */
  vHsm_Serialize_Uint32(vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobState, jobResponseBuffer, 12u);
  vHsm_Serialize_Uint32(vHsm_GetJobRetValOfJobObjects(jobObjectId), jobResponseBuffer, 16u);
#else
  /* PRQA S 0310, 3305 4 */ /* MD_VHSM_SERIALIZATION_MACRO */
  vHsm_Serialize_Uint32(vHsm_GetJobRequestIdOfJobObjects(jobObjectId) | (((uint32)vHsm_GetJobRetValOfJobObjects(jobObjectId))<<16u) |(((uint32)vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobState)<<8u), jobResponseBuffer, 0u);
  vHsm_Serialize_Uint32(vHsm_GetLocalOutputOfJobObjects(jobObjectId).outputLength, jobResponseBuffer, 4u);
  vHsm_Serialize_Uint32(vHsm_GetLocalOutputOfJobObjects(jobObjectId).secondaryOutputLength, jobResponseBuffer, 8u);
  vHsm_Serialize_Uint32(vHsm_GetLocalOutputOfJobObjects(jobObjectId).verifyResult, jobResponseBuffer, 12u);
#endif
}

/**********************************************************************************************************************
 *  vHsm_Ipc_Transmit_KeyMJobResponse()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Ipc_Transmit_KeyMJobResponse(
  vHsm_JobObjectIdType jobObjectId, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) jobResponseBuffer)
{

  /* Add job response header */

#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
  /* PRQA S 0310, 3305 2 */ /* MD_VHSM_SERIALIZATION_MACRO */
  vHsm_Serialize_Uint32(vHsm_GetJobRequestIdOfJobObjects(jobObjectId), jobResponseBuffer, 0u);
  vHsm_Serialize_Uint32(vHsm_GetJobRequestKindOfJobObjects(jobObjectId), jobResponseBuffer, 4u);
  /* #10 Serialize the result of a KeyM job to the IPC buffer */
  vHsm_Serialize_Uint32(vHsm_GetJobRetValOfJobObjects(jobObjectId), jobResponseBuffer, 8u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
#else
  /* PRQA S 0310, 3305 2 */ /* MD_VHSM_SERIALIZATION_MACRO */
  vHsm_Serialize_Uint32(vHsm_GetJobRequestIdOfJobObjects(jobObjectId) | (((uint32)vHsm_GetJobRetValOfJobObjects(jobObjectId))<<16u), jobResponseBuffer, 0u);
  vHsm_Serialize_Uint32(vHsm_GetLocalOutputOfJobObjects(jobObjectId).outputLength, jobResponseBuffer, 4u);
#endif
}

#if (VHSM_REDIRECTION == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Ipc_CryptoJob_RedirectionDeserialization()
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
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Ipc_CryptoJob_RedirectionDeserialization(
  P2VAR(const uint8*, AUTOMATIC, VHSM_APPL_VAR) dataPtrPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) lengthPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) cryptokeyIdPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) keyElementIdPtr,
  uint8 redirectionFlags,
  uint8 redirectionFlag,
  P2VAR(boolean, AUTOMATIC, VHSM_APPL_VAR) retVal)
{
  const uint8 *ptrBuf;
  uint32 cryIfKeyId;

  /* #10 Check if redirection shall be performed */
  if ((redirectionFlags & redirectionFlag) != redirectionFlag)
  {
    /* Do nothing */
  }
  /* #11 Check if length ptr is valid */
  else if (lengthPtr == NULL_PTR)
  {
    *retVal = FALSE;
  }
  /* #12 Check if length is correct */
  else if (*lengthPtr != 8u)
  {
    *retVal = FALSE;
  }
  else
  {
    /* #13 Deserialize the information */
    ptrBuf = *dataPtrPtr;
    cryIfKeyId = vHsm_Deserialize_Uint32(ptrBuf, 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    *keyElementIdPtr = vHsm_Deserialize_Uint32(ptrBuf, 4u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    *dataPtrPtr = NULL_PTR;
    *lengthPtr = 0u;

    /* #14 Check if the key is in a valid range */
    if (cryIfKeyId >= vHsm_GetSizeOfKeyInfo())
    {
      *retVal = FALSE;
    }
    /* #15 Check key if usage is allowed */
    else if (vHsm_IsKeyUsageDisallowed(cryIfKeyId) == TRUE)
    {
      *retVal = FALSE;
    }
    /* Only allow LibCv keys for redirection */
    else if (vHsm_GetProcessJobOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfKeyInfo(cryIfKeyId)) != Crypto_30_LibCv_ProcessJob)
    {
      *retVal = FALSE;
    }
    else
    {
      /* Store the cryptoKeyId */
      *cryptokeyIdPtr = vHsm_GetCryptoKeyIdOfKeyInfo(cryIfKeyId);
    }
  }
} /* PRQA S 6060, 6080 */ /* MD_VHSM_6060_STPAR */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Ipc_CryptoJob_Redirection()
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
VHSM_LOCAL_INLINE FUNC(boolean, VHSM_CODE) vHsm_Ipc_CryptoJob_Redirection(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job,
  uint8 redirectionFlags)
{
  boolean retVal = TRUE;

  job->jobRedirectionInfoRef = &vHsm_Ipc_Crypto_JobRedirectionInfo;
  job->jobRedirectionInfoRef->redirectionConfig = redirectionFlags;

  /* #10 Redirect primary input */
  vHsm_Ipc_CryptoJob_RedirectionDeserialization(
    (P2VAR(const uint8*, AUTOMATIC, VHSM_APPL_VAR))&job->jobPrimitiveInputOutput.inputPtr,
    &job->jobPrimitiveInputOutput.inputLength,
    &job->jobRedirectionInfoRef->inputKeyId,
    &job->jobRedirectionInfoRef->inputKeyElementId,
    redirectionFlags,
    CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT,
    &retVal);

  /* #20 Redirect secondary input */
  vHsm_Ipc_CryptoJob_RedirectionDeserialization(
    (P2VAR(const uint8*, AUTOMATIC, VHSM_APPL_VAR))&job->jobPrimitiveInputOutput.secondaryInputPtr,
    &job->jobPrimitiveInputOutput.secondaryInputLength,
    &job->jobRedirectionInfoRef->secondaryInputKeyId,
    &job->jobRedirectionInfoRef->secondaryInputKeyElementId,
    redirectionFlags,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT,
    &retVal);

  /* #30 Redirect tertiary input */
  vHsm_Ipc_CryptoJob_RedirectionDeserialization(
    (P2VAR(const uint8*, AUTOMATIC, VHSM_APPL_VAR))&job->jobPrimitiveInputOutput.tertiaryInputPtr,
    &job->jobPrimitiveInputOutput.tertiaryInputLength,
    &job->jobRedirectionInfoRef->tertiaryInputKeyId,
    &job->jobRedirectionInfoRef->tertiaryInputKeyElementId,
    redirectionFlags,
    CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT,
    &retVal);

  /* #40 Redirect primary output */
  vHsm_Ipc_CryptoJob_RedirectionDeserialization(
    (P2VAR(const uint8*, AUTOMATIC, VHSM_APPL_VAR))&job->jobPrimitiveInputOutput.outputPtr, /* PRQA S 0310 */ /* MD_VHSM_0310_API_SPECIFIC_CAST */
    job->jobPrimitiveInputOutput.outputLengthPtr,
    &job->jobRedirectionInfoRef->outputKeyId,
    &job->jobRedirectionInfoRef->outputKeyElementId,
    redirectionFlags,
    CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT,
    &retVal);

  /* #50 Redirect secondary output */
  vHsm_Ipc_CryptoJob_RedirectionDeserialization(
    (P2VAR(const uint8*, AUTOMATIC, VHSM_APPL_VAR))&job->jobPrimitiveInputOutput.secondaryOutputPtr, /* PRQA S 0310 */ /* MD_VHSM_0310_API_SPECIFIC_CAST */
    job->jobPrimitiveInputOutput.secondaryOutputLengthPtr,
    &job->jobRedirectionInfoRef->secondaryOutputKeyId,
    &job->jobRedirectionInfoRef->secondaryOutputKeyElementId,
    redirectionFlags,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT,
    &retVal);

  return retVal;
}
#endif

#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
/**********************************************************************************************************************
 *  vHsm_Ipc_Receive_CryptoJobRequest()
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
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Ipc_Receive_CryptoJobRequest(
  vHsm_JobObjectIdType jobObjectId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) jobRequestBuffer)
{
  /* ----- Implementation ----------------------------------------------- */
  vHsm_SetProcessKindOfJobObjects(jobObjectId, VHSM_CRYPTO_JOBKIND);

  /* #10 Deserialize the job from the IPC */
  vHsm_Ipc_CryptoJob_Deserialize(jobObjectId, jobRequestBuffer);

# if(VHSM_SETTING_ENABLE_API_PREPARE_JOB_DATA == STD_ON)
  /* Let the HAL prepare input and output pointers */
  vHsm_Hal_PrepareCryptoJobData(&vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobPrimitiveInputOutput);
# endif

  vHsm_SetValidRequestFlagOfJobObjects(jobObjectId, vHsm_Ipc2_GenericFunctions[vHsm_GetJobRequestKindOfJobObjects(jobObjectId)].checkFctCrypto(&vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job, jobObjectId));

# if (VHSM_REDIRECTION == STD_ON)
  if (vHsm_GetRedirectionFlagsOfJobObjects(jobObjectId) == 0u)
  {
    /* No redirection */
    vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobRedirectionInfoRef = NULL_PTR;
  }
  else if (vHsm_IsValidRequestFlagOfJobObjects(jobObjectId) == FALSE)
  {
    /* Do nothing as the request is already invalid */
  }
  else if (vHsm_GetProcessJobOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfChannelInfo(jobObjectId)) != Crypto_30_LibCv_ProcessJob)
  {
    /* Only LibCv supports redirection */
    vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobRedirectionInfoRef = NULL_PTR;
    vHsm_SetValidRequestFlagOfJobObjects(jobObjectId, FALSE);
  }
  else
  {
    vHsm_SetValidRequestFlagOfJobObjects(jobObjectId, vHsm_Ipc_CryptoJob_Redirection(&vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job, vHsm_GetRedirectionFlagsOfJobObjects(jobObjectId)));
  }
# endif
}

/**********************************************************************************************************************
 *  vHsm_Ipc_Receive_KeyMJobRequest()
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
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Ipc_Receive_KeyMJobRequest(
  vHsm_JobObjectIdType jobObjectId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) jobRequestBuffer)
{
  /* ----- Implementation ----------------------------------------------- */
  vHsm_SetProcessKindOfJobObjects(jobObjectId, VHSM_KEYM_JOBKIND);

  /* #10 Deserialize the job from the IPC */
  vHsm_Ipc_KeyMJob_Deserialize(jobObjectId, jobRequestBuffer);

# if(VHSM_SETTING_ENABLE_API_PREPARE_JOB_DATA == STD_ON)
  /* Let the HAL prepare input and output pointers */
  vHsm_Hal_PrepareKeyMJobData(&vHsm_GetJobDataOfJobObjects(jobObjectId).keyM_Job.inputOutput);
# endif

  /* #20 Check if the buffers are valid */
  vHsm_SetValidRequestFlagOfJobObjects(jobObjectId, vHsm_Ipc2_GenericFunctions[vHsm_GetJobRequestKindOfJobObjects(jobObjectId)].checkFctKeyM(&vHsm_GetJobDataOfJobObjects(jobObjectId).keyM_Job, jobObjectId));
}
#endif
#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_Ipc_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Ipc_Init(void)
{
  vHsm_JobObjectIdType jobObjectId;
  vHsm_IpcInstanceIterType ipcIdx;
  vHsm_DriverObjectMappingIterType objIdx;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the job processor */
  for (jobObjectId = 0u; jobObjectId < vHsm_GetSizeOfJobObjects(); jobObjectId++)
  {
    VStdLib_MemClr(&vHsm_GetJobDataOfJobObjects(jobObjectId), sizeof(vHsm_JobDataUnionType));  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.jobPrimitiveInfo.primitiveInfo = &vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.primitiveInfo;
    vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobPrimitiveInfo = &vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.jobPrimitiveInfo;
    vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobInfo = &vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.jobInfo;
    vHsm_SetStateOfJobObjects(jobObjectId, VHSM_JOB_STATE_IDLE);
    VStdLib_MemClr(&vHsm_GetLocalOutputOfJobObjects(jobObjectId), sizeof(vHsm_LocalOutputType)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
#if (VHSM_IPC_PROTOCOL_VERSION == 3u)
    vHsm_GetLocalOutputOfJobObjects(jobObjectId).verifyResult = CRYPTO_E_VER_OK;
#endif
    /* Init JobObjectsActivation array */

    vHsm_GetUsageRestrictionOfJobObjects(jobObjectId) = 0u;
    vHsm_GetIpcMappingOfJobObjects(jobObjectId) = 0u;
  }

  /* Set ipc flags for all driver objects. One driver object might be available in e.g. two IPC instances */
  for (ipcIdx = 0u; ipcIdx < vHsm_GetSizeOfIpcInstance(); ipcIdx++)
  {
    for (objIdx = vHsm_GetDriverObjectMappingIndStartIdxOfIpcInstance(ipcIdx); objIdx < vHsm_GetDriverObjectMappingIndEndIdxOfIpcInstance(ipcIdx); objIdx++)
    {
      vHsm_GetIpcMappingOfJobObjects(vHsm_GetDriverObjectMapping(objIdx)) |= (uint8)(1u << ipcIdx);
    }
  }
}

/**********************************************************************************************************************
 *  vHsm_Ipc_TransmitJobResponse()
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
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc_TransmitJobResponse(
  vHsm_JobObjectIdType jobObjectId,
  uint32 jobResponseBufferSize)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = VHSM_IPC_E_NO_ERROR;
  uint8 local_vHsm_Ipc_Idx;
  vHsm_IpcChannelOfJobObjectsType local_vHsm_Ipc_Channel;
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) jobResponseBuffer;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Allocate a transmission buffer for the job response data. */
  SchM_Enter_vHsm_VHSM_EXCLUSIVE_AREA_0();
  vHsm_Ipc_Idx = vHsm_GetIpcInstanceOfJobObjects(jobObjectId);
  local_vHsm_Ipc_Idx = vHsm_GetIpcInstanceOfJobObjects(jobObjectId);
  local_vHsm_Ipc_Channel = vHsm_GetIpcChannelOfJobObjects(jobObjectId);
  vHsm_Ipc_ChangeInstance(local_vHsm_Ipc_Idx);
  retVal = vHsm_Ipc_Allocate(local_vHsm_Ipc_Channel, jobResponseBufferSize, &jobResponseBuffer);
  if (retVal == E_OK)
  {
    /* #20 Add channel entry header. */
#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
    vHsm_Serialize_Uint32(jobResponseBufferSize, jobResponseBuffer, 0u); /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
    jobResponseBuffer = &jobResponseBuffer[4];
#endif

    /* #25 Copy job response data from job processor into Tx channel for transmission to Host. */
    vHsm_Ipc_JobKindInfo[vHsm_GetJobRequestKindOfJobObjects(jobObjectId)].txFct(jobObjectId, jobResponseBuffer);

    /* #30 Commit the transmission of new job response to Host. */
    /* Note: This will make the new job response immediately visible from Host. */
    vHsm_Ipc_CommitTransmission(local_vHsm_Ipc_Channel);

#if (VHSM_FORCE_INTERRUPT_TRIGGERING == STD_OFF)
    /* Trigger interrupt only for async jobs */
    if (vHsm_GetProcessingTypeOfJobObjects(jobObjectId) == CRYPTO_PROCESSING_ASYNC)
#endif
    {
      /* #35 Notify Host about transmission of the new job response. */
      vHsm_TriggerResponseInterrupt(local_vHsm_Ipc_Idx); /* PRQA S 0306 */ /* MD_VHSM_0306_REGISTER_ACCESS */
    }

    /* Clear inputs and outputs */
    if (vHsm_GetProcessKindOfJobObjects(jobObjectId) == VHSM_CRYPTO_JOBKIND)
    {
      vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobPrimitiveInputOutput.inputLength = 0u;
      vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobPrimitiveInputOutput.secondaryInputLength = 0u;
      vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobPrimitiveInputOutput.tertiaryInputLength = 0u;
      vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobPrimitiveInputOutput.outputLengthPtr = NULL_PTR;
      vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobPrimitiveInputOutput.secondaryOutputLengthPtr = NULL_PTR;
      vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobPrimitiveInputOutput.verifyPtr = NULL_PTR;
    }
    else
    {
      vHsm_GetJobDataOfJobObjects(jobObjectId).keyM_Job.inputOutput.inputLength = 0u;
      vHsm_GetJobDataOfJobObjects(jobObjectId).keyM_Job.inputOutput.outputLengthPtr = NULL_PTR;
    }

    /* Store the pointers because they could have been overwritten by a KeyM job */
    vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.jobPrimitiveInfo.primitiveInfo = &vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.primitiveInfo;
    vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobPrimitiveInfo = &vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.jobPrimitiveInfo;
    vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.job.jobInfo = &vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job.jobInfo;

#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
    /* Reset keyLength because it is only set when IPCv3  is used */
    vHsm_Api_TempJob_SetKeyLength(&vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job, 0u);
#endif

    vHsm_SetStateOfJobObjects(jobObjectId, VHSM_JOB_STATE_IDLE);
  }
  else
  {
#if (VHSM_DEV_ERROR_DETECT == STD_ON)
    /* Error: Cannot allocate enough space for job response in Tx channel. */
    errorId = VHSM_IPC_E_CANNOT_ALLOCATE_JOBRESPONSE_BUFFER;
#endif /* (VHSM_DEV_ERROR_DETECT == STD_ON) */
  }

  SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0();

  /* ----- Development Error Report --------------------------------------- */
#if (VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VHSM_IPC_E_NO_ERROR)
  {
    (void)Det_ReportError(VHSM_MODULE_ID, VHSM_INSTANCE_ID, VHSM_IPC_SID_TRANSMITJOBRESPONSE, errorId);
  }
#else /* (VHSM_DEV_ERROR_DETECT == STD_ON) */
  VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* (VHSM_DEV_ERROR_DETECT == STD_ON) */

  return retVal;
}/* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  vHsm_Ipc_FetchJobs()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Ipc_FetchJobs(vHsm_CallContextType callContext)
{
  /* ----- Local Variables ---------------------------------------------- */
  vHsm_ChannelIdType rxChannel;
  vHsm_JobObjectIdType jobObjectId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if job request is available in the IPC and read it */
  for (rxChannel = 0u; rxChannel< vHsm_GetChannelsOfIpc(); rxChannel++)
  {
    if (vHsm_Ipc_ReceiveJobRequest(rxChannel, &jobObjectId) == E_OK)
    {
      vHsm_Ipc_ProcessJobRequest(jobObjectId, callContext);
    }
  }
}

/**********************************************************************************************************************
 *  vHsm_Ipc_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Ipc_MainFunction(void)
{
  /* ----- Implementation ----------------------------------------------- */
#if (VHSM_INTERRUPT_MODE == STD_OFF)
  /* #10 Fetch the jobs from the IPC and process them immediately */
  vHsm_Ipc_FetchJobs(VHSM_CALL_CONTEXT_TASK);
#elif (VHSM_OS_SUPPORT == STD_OFF) /* Do not process jobs in TASK context, as all jobs are processed by OS tasks */
  /* #20 Process pending jobs which have been fetched by the ISR */
  vHsm_SchedulableEntitiesIterType schedulableEntities;
  for (schedulableEntities = 0u; schedulableEntities < vHsm_GetSizeOfSchedulableEntities(); schedulableEntities++)
  {
    vHsm_JobProcessor_MainFunction(schedulableEntities);
  }
#endif
}

/**********************************************************************************************************************
 *  vHsm_Ipc_DetReportError()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Ipc_DetReportError(
  uint16 moduleId,
  uint8 instanceId,
  uint8 apiId,
  uint8 errorId)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Write the parameters of the Det call to the IPC if initialized */
  if (vHsm_State.vHsm_IpcInitialized[vHsm_Ipc_Idx] == TRUE)
  {
    SchM_Enter_vHsm_VHSM_EXCLUSIVE_AREA_0();

    /* PRQA S 0310, 3305 4 */ /* MD_VHSM_IPC_MACRO */
    vHsm_Ipc_SetDetModuleId(moduleId);
    vHsm_Ipc_SetDetInstanceId(instanceId);
    vHsm_Ipc_SetDetApiId(apiId);
    vHsm_Ipc_SetDetErrorId(errorId);

    /* #20 Set a flag in the IPC that a DET error occurred */
    vHsm_Ipc_SetDetReportFlag(1u); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */

    SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0();
  }
}

#if (VHSM_OS_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Ipc_StartJobObjectTask()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Ipc_StartJobObjectTask(vHsm_JobObjectIdType jobObjectId)
{
  if (vHsm_IsEventTriggeredOfJobObjectInfo(jobObjectId) == TRUE)
  {
    SetEvent(vHsm_GetSchedTaskRefOfJobObjectInfo(jobObjectId), vHsm_GetSchedEventRefOfJobObjectInfo(jobObjectId));
  }
  else
  {
    ActivateTask(vHsm_GetSchedTaskRefOfJobObjectInfo(jobObjectId));
  }
}
#endif

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Ipc.c
 *********************************************************************************************************************/

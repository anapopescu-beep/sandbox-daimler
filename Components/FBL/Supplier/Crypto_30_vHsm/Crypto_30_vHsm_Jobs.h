/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*      \file  Crypto_30_vHsm_Jobs.h
 *      \brief  Vector Hardware Security Module Firmware Jobs
 *
 *      \details  Implementation of the Vector Hardware Security Module Firmware Jobs
 *
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_VHSM_JOBS_H)
# define CRYPTO_30_VHSM_JOBS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Crypto_30_vHsm.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
# define Crypto_30_vHsm_GetAddrSharedDataBufferOfDriverObject(objectId, usedBuffer) (&((P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA))Crypto_30_vHsm_GetAddrSharedDataBuffer(Crypto_30_vHsm_GetSharedDataBufferStartIdxOfObjectInfo(objectId)))[(usedBuffer)]) /* PRQA S 3453 */  /* MD_MSR_FctLikeMacro */
# define Crypto_30_vHsm_GetSharedDataBufferSizeOfDriverObject(objectId) ((uint32)(((uint32)Crypto_30_vHsm_GetSharedDataBufferEndIdxOfObjectInfo(objectId) - (uint32)Crypto_30_vHsm_GetSharedDataBufferStartIdxOfObjectInfo(objectId))*(uint32)4uL)) /* PRQA S 3453 */  /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define CRYPTO_30_VHSM_START_SEC_CODE
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_ReceiveResponse_CryptoJob()
 *********************************************************************************************************************/
/*!
 * \brief       Receive crypto job response.
 * \details     -
 * \param[in]   jobRequestId        Valid job request Id
 * \param[in]   jobResponseData     Data containing concatenated information of the job response like the retval and state
 * \param[in]   jobResponseBuffer   Valid job response buffer with at least CRYPTO_30_VHSM_CRYPTO_JOBRESULTTYPE_DESERIALIZED_BUF_SIZE bytes of storage
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_ReceiveResponse_CryptoJob(
  Crypto_30_vHsm_JobRequestIterType jobRequestId,
# if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  uint32 jobResponseData,
# endif
  Crypto_30_vHsm_JobResponseBufferPtrType jobResponseBuffer);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_ReceiveResponse_KeyMJob()
 *********************************************************************************************************************/
/*!
 * \brief       Receive key management job response.
 * \details     -
 * \param[in]   jobRequestId        Valid job request Id
 * \param[in]   jobResponseData     Data containing concatenated information of the job response like the retval
 * \param[in]   jobResponseBuffer   Valid job response buffer with at least CRYPTO_30_VHSM_KEYM_JOBRESULTTYPE_DESERIALIZED_BUF_SIZE bytes of storage
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_ReceiveResponse_KeyMJob(
  Crypto_30_vHsm_JobRequestIterType jobRequestId,
# if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  uint32 jobResponseData,
# endif
  Crypto_30_vHsm_JobResponseBufferPtrType jobResponseBuffer);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a crypto job
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to job object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the crypto job will be serialized.
 *                                      Must be at least of size 80.
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
# if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
# endif
  );

# if (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_MacGen()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a crypto job
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to job object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the crypto job will be serialized.
 *                                      Must be at least of size 44.
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_MacGen(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#  if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
#  endif
  );
# endif /* (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION == STD_ON) */

# if (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_MacVer()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a crypto job
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to job object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the crypto job will be serialized.
 *                                      Must be at least of size 48.
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_MacVer(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#  if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
#  endif
  );
# endif /* (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION == STD_ON) */

# if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_KeyMJob_CopyPartial()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a key management job for key element copy partial
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     keyMJobPtr            Valid pointer to job result object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the key job will be serialized.
 *                                      Must be at least of size 32.
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_KeyMJob_CopyPartial(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_30_vHsm_KeyM_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) keyMJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf);

#  if (CRYPTO_30_VHSM_KEY_DERIVE_JOB_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_KeyDerive()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a key derive job
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to job object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the crypto job will be serialized.
 *                                      Must be at least of size 36.
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_KeyDerive(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf);
#  endif /* (CRYPTO_30_VHSM_KEY_DERIVE_JOB_SUPPORT == STD_ON) */
# endif

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_KeyMJob()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a key management job
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     keyMJobPtr            Valid pointer to job result object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the key job will be serialized.
 *                                      Must be at least of size 36.
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_KeyMJob(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_30_vHsm_KeyM_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) keyMJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf);

# define CRYPTO_30_VHSM_STOP_SEC_CODE
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* CRYPTO_30_VHSM_JOBS_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Jobs.h
 *********************************************************************************************************************/

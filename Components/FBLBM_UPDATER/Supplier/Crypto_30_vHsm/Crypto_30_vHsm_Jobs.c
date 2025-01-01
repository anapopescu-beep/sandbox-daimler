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
/*      \file  Crypto_30_vHsm_Jobs.c
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

#define CRYPTO_30_VHSM_JOBS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_vHsm_Jobs.h"
#include "Crypto_30_vHsm_Ipc.h"

#include "vstdlib.h"
#if ( CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON )
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
# define CRYPTO_30_VHSM_CRYPTO_JOBRESULTTYPE_DESERIALIZED_BUF_SIZE    (8u)
# define CRYPTO_30_VHSM_KEYM_JOBRESULTTYPE_DESERIALIZED_BUF_SIZE      (4u)
#else
# define CRYPTO_30_VHSM_CRYPTO_JOBRESULTTYPE_DESERIALIZED_BUF_SIZE    (12u)
# define CRYPTO_30_VHSM_KEYM_JOBRESULTTYPE_DESERIALIZED_BUF_SIZE      (4u)
#endif

#define CRYPTO_30_VHSM_OUTPUT_BUFFER_NOT_USED                         (0xFFFFFFFFuL)

#define CRYPTO_30_VHSM_IO_NONE                                        (0u)
#define CRYPTO_30_VHSM_IO_INPUT                                       (1u)
#define CRYPTO_30_VHSM_IO_SECONDARYINPUT                              (2u)
#define CRYPTO_30_VHSM_IO_TERTIARYINPUT                               (4u)
#define CRYPTO_30_VHSM_IO_OUTPUT                                      (8u)
#define CRYPTO_30_VHSM_IO_SECONDARYOUTPUT                             (16u)
#define CRYPTO_30_VHSM_IO_VERIFYRESULT                                (32u)
#define CRYPTO_30_VHSM_IO_SECONDARYKEY                                (64u)
#define CRYPTO_30_VHSM_IO_COPYPARTIAL                                 (128u)

#define CRYPTO_30_VHSM_INVALID_SERVICES                               (0x14u) /* CRYPTO_KEYSETVALID + 1u */

#define CRYPTO_30_VHSM_PTRMSK_INPUTS                                  (24u)
#define CRYPTO_30_VHSM_PTRMSK_OUTPUTS                                 (16u)
#define CRYPTO_30_VHSM_PTRMSK_KEYS                                    ( 8u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (CRYPTO_30_VHSM_LOCAL) /* COV_CRYPTO_30_VHSM_LOCAL_DEFINE */
# define CRYPTO_30_VHSM_LOCAL                                         static
#endif

#if !defined (CRYPTO_30_VHSM_LOCAL_INLINE) /* COV_CRYPTO_30_VHSM_LOCAL_DEFINE */
# define CRYPTO_30_VHSM_LOCAL_INLINE                                  LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CRYPTO_30_VHSM_LOCAL CONST(uint8, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_JobIOAvailable[CRYPTO_30_VHSM_INVALID_SERVICES] =
{
  /* CRYPTO_HASH                  */ CRYPTO_30_VHSM_IO_INPUT | CRYPTO_30_VHSM_IO_OUTPUT,
  /* CRYPTO_MACGENERATE           */ CRYPTO_30_VHSM_IO_INPUT | CRYPTO_30_VHSM_IO_OUTPUT,
  /* CRYPTO_MACVERIFY             */ CRYPTO_30_VHSM_IO_INPUT | CRYPTO_30_VHSM_IO_SECONDARYINPUT | CRYPTO_30_VHSM_IO_VERIFYRESULT,
  /* CRYPTO_ENCRYPT               */ CRYPTO_30_VHSM_IO_INPUT | CRYPTO_30_VHSM_IO_OUTPUT,
  /* CRYPTO_DECRYPT               */ CRYPTO_30_VHSM_IO_INPUT | CRYPTO_30_VHSM_IO_OUTPUT,
  /* CRYPTO_AEADENCRYPT           */ CRYPTO_30_VHSM_IO_INPUT | CRYPTO_30_VHSM_IO_SECONDARYINPUT | CRYPTO_30_VHSM_IO_OUTPUT | CRYPTO_30_VHSM_IO_SECONDARYOUTPUT,
  /* CRYPTO_AEADDECRYPT           */ CRYPTO_30_VHSM_IO_INPUT | CRYPTO_30_VHSM_IO_SECONDARYINPUT | CRYPTO_30_VHSM_IO_TERTIARYINPUT | CRYPTO_30_VHSM_IO_OUTPUT | CRYPTO_30_VHSM_IO_VERIFYRESULT,
  /* CRYPTO_SIGNATUREGENERATE     */ CRYPTO_30_VHSM_IO_INPUT | CRYPTO_30_VHSM_IO_OUTPUT,
  /* CRYPTO_SIGNATUREVERIFY       */ CRYPTO_30_VHSM_IO_INPUT | CRYPTO_30_VHSM_IO_SECONDARYINPUT | CRYPTO_30_VHSM_IO_VERIFYRESULT,
  /* CRYPTO_SECCOUNTERINCREMENT   */ CRYPTO_30_VHSM_IO_NONE,
  /* CRYPTO_SECCOUNTERREAD        */ CRYPTO_30_VHSM_IO_NONE,
  /* CRYPTO_RANDOMGENERATE        */ CRYPTO_30_VHSM_IO_OUTPUT,
  /* CRYPTO_RANDOMSEED            */ CRYPTO_30_VHSM_IO_INPUT,
  /* CRYPTO_KEYGENERATE           */ CRYPTO_30_VHSM_IO_NONE,
  /* CRYPTO_KEYDERIVE             */ CRYPTO_30_VHSM_IO_NONE | CRYPTO_30_VHSM_IO_SECONDARYKEY,
  /* CRYPTO_KEYEXCHANGECALCPUBVAL */ CRYPTO_30_VHSM_IO_OUTPUT,
  /* CRYPTO_KEYEXCHANGECALCSECRET */ CRYPTO_30_VHSM_IO_INPUT,
  /* CRYPTO_CERTIFICATEPARSE      */ CRYPTO_30_VHSM_IO_NONE, /* Not supported by stack */
  /* CRYPTO_CERTIFICATEVERIFY     */ CRYPTO_30_VHSM_IO_NONE, /* Not supported by stack */
  /* CRYPTO_KEYSETVALID           */ CRYPTO_30_VHSM_IO_NONE
};

#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
CRYPTO_30_VHSM_LOCAL CONST(uint8, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_KeyMIOAvailable[CRYPTO_30_VHSM_NR_OF_KEYM_ACTION] =
{
  /* CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTSET         */ CRYPTO_30_VHSM_IO_INPUT,
  /* CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTGET         */ CRYPTO_30_VHSM_IO_OUTPUT,
  /* CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTCOPY        */ CRYPTO_30_VHSM_IO_NONE | CRYPTO_30_VHSM_IO_SECONDARYKEY ,
  /* CRYPTO_30_VHSM_KEYM_ACTION_KEYCOPY               */ CRYPTO_30_VHSM_IO_NONE | CRYPTO_30_VHSM_IO_SECONDARYKEY,
  /* CRYPTO_30_VHSM_KEYM_ACTION_KEYDERIVE             */ CRYPTO_30_VHSM_IO_NONE | CRYPTO_30_VHSM_IO_SECONDARYKEY,
  /* CRYPTO_30_VHSM_KEYM_ACTION_KEYGENERATE           */ CRYPTO_30_VHSM_IO_NONE,
  /* CRYPTO_30_VHSM_KEYM_ACTION_KEYVALIDSET           */ CRYPTO_30_VHSM_IO_NONE,
  /* CRYPTO_30_VHSM_KEYM_ACTION_RANDOMSEED            */ CRYPTO_30_VHSM_IO_INPUT,
  /* CRYPTO_30_VHSM_KEYM_ACTION_CERTIFICATEPARSE      */ CRYPTO_30_VHSM_IO_NONE,
  /* CRYPTO_30_VHSM_KEYM_ACTION_CERTIFICATEVERIFY     */ CRYPTO_30_VHSM_IO_OUTPUT,
  /* CRYPTO_30_VHSM_KEYM_ACTION_KEYEXCHANGECALCPUBVAL */ CRYPTO_30_VHSM_IO_OUTPUT,
  /* CRYPTO_30_VHSM_KEYM_ACTION_KEYEXCHANGECALCSECRET */ CRYPTO_30_VHSM_IO_INPUT,
  /* CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTIDSGET      */ CRYPTO_30_VHSM_IO_OUTPUT,
  /* CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTCOPYPARTIAL */ CRYPTO_30_VHSM_IO_NONE | CRYPTO_30_VHSM_IO_SECONDARYKEY | CRYPTO_30_VHSM_IO_COPYPARTIAL
};
#endif

#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_START_SEC_CODE
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_IsMemoryValid()
 *********************************************************************************************************************/
/*!
 * \brief       Check if a pointer points to valid memory.
 * \details     -
 * \param[in]   ptr            Pointer to memory
 * \param[in]   length         Length of memory region in byte
 * \param[in]   isInput        ptr is input or output
 * \return      TRUE if memory is valid, otherwise FALSE.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
CRYPTO_30_VHSM_LOCAL FUNC(boolean, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_IsMemoryValid(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) ptr,
  uint32 length,
  boolean isInput);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeOutputPtr()
 *********************************************************************************************************************/
/*!
 * \brief         Serialize an output to the Ipc buffer
 * \details       -
 * \param[in]     jobRequestId          Valid JobRequestId
 * \param[in]     outputPtr             Output pointer which shall be serialized
 * \param[in]     outputLengthPtr       Size of the data which shall be serialized
 * \param[in,out] dataBufferLengthPtr   Valid size of the dataBufferPtr
 * \param[in,out] ptrBuf                Valid pointer to the memory where the pointer shall be serialized.
 *                                      Must at least provide 8 byte of storage after the offset.
 * \param[out]    outputOffset          Offset of the output inside the shared buffer
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeOutputPtr(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA)  outputPtr,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) outputLengthPtr,
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) dataBufferLengthPtr,
#endif
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR)  ptrBuf,
  P2VAR(volatile uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) outputOffset);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeInputPtr()
 *********************************************************************************************************************/
/*!
 * \brief         Serialize an input to the Ipc buffer
 * \details       If possible and needed, the input data located at an invalid memory area (e.g. local application
 *                core RAM) will be automatically copied to a valid buffer.
 * \param[in]     jobRequestId          Valid JobRequestId
 * \param[in]     inputPtr              Input pointer which shall be serialized
 * \param[in]     inputLength           Size of the data which shall be serialized
 * \param[in,out] ptrBuf                Valid pointer to the memory where the pointer shall be serialized.
 *                                      Must at least provide 8 byte of storage after the offset.
 * \param[in]     interpretlengthInBits If TRUE the input size shall be interpreted as bits, otherwise as bytes.
 * \return        E_OK if the input has been correctly serialized, otherwise E_NOT_OK.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeInputPtr(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf,
  boolean interpretlengthInBits);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeInput()
 *********************************************************************************************************************/
/*!
 * \brief         Serialize the input or a redirection to the Ipc buffer
 * \details       The function decides if the input shall be serialized or a redirection is made.
 * \param[in]     jobRequestId          Valid JobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to the job which shall be serialized
 * \param[in,out] ptrBuf                Valid pointer to the memory where the pointer shall be serialized.
 *                                      Must at least provide 8 byte of storage after the offset.
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if the input has been correctly serialized, otherwise E_NOT_OK.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeInput(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
#endif
);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeSecondaryInput()
 *********************************************************************************************************************/
/*!
 * \brief         Serialize the secondary input or a redirection to the Ipc buffer
 * \details       The function decides if the input shall be serialized or a redirection is made.
 * \param[in]     jobRequestId          Valid JobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to the job which shall be serialized
 * \param[in,out] ptrBuf                Valid pointer to the memory where the pointer shall be serialized.
 *                                      Must at least provide 8 byte of storage after the offset.
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if the input has been correctly serialized, otherwise E_NOT_OK.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeSecondaryInput(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
#endif
);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeTertiaryInput()
 *********************************************************************************************************************/
/*!
 * \brief         Serialize the tertiary input or a redirection to the Ipc buffer
 * \details       The function decides if the input shall be serialized or a redirection is made.
 * \param[in]     jobRequestId          Valid JobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to the job which shall be serialized
 * \param[in,out] ptrBuf                Valid pointer to the memory where the pointer shall be serialized.
 *                                      Must at least provide 8 byte of storage after the offset.
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if the input has been correctly serialized, otherwise E_NOT_OK.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeTertiaryInput(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
#endif
);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeOutput()
 *********************************************************************************************************************/
/*!
 * \brief         Serialize the output or a redirection to the Ipc buffer
 * \details       The function decides if the input shall be serialized or a redirection is made.
 * \param[in]     jobRequestId          Valid JobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to the job which shall be serialized
 * \param[in,out] ptrBuf                Valid pointer to the memory where the pointer shall be serialized.
 *                                      Must at least provide 8 byte of storage after the offset.
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if the input has been correctly serialized, otherwise E_NOT_OK.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeOutput(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
#endif
);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeSecondaryOutput()
 *********************************************************************************************************************/
/*!
 * \brief         Serialize the secondary output or a redirection to the Ipc buffer
 * \details       The function decides if the input shall be serialized or a redirection is made.
 * \param[in]     jobRequestId          Valid JobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to the job which shall be serialized
 * \param[in,out] ptrBuf                Valid pointer to the memory where the pointer shall be serialized.
 *                                      Must at least provide 8 byte of storage after the offset.
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if the input has been correctly serialized, otherwise E_NOT_OK.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeSecondaryOutput(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
#endif
  );

#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeInputRedirection()
 *********************************************************************************************************************/
/*!
 * \brief         Serialize an input redirection to the Ipc buffer
 * \details       -
 * \param[in]     jobRequestId         Valid JobRequestId
 * \param[in]     keyId                Valid key which shall be used as destination for the redirection
 * \param[in]     keyElementId         Valid keyElement which shall be used as destination for the redirection
 * \param[in,out] ptrBuf               Valid pointer to the memory where the pointer shall be serialized.
 *                                     Must at least provide 8 byte of storage after the offset.
 * \return        E_OK if the input redirection has been correctly serialized, otherwise E_NOT_OK.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeInputRedirection(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  uint32 keyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeOutputRedirection()
 *********************************************************************************************************************/
/*!
 * \brief         Serialize an output redirection to the Ipc buffer
 * \details       -
 * \param[in]     jobRequestId         Valid JobRequestId
 * \param[in]     keyId                Valid key which shall be used source for the redirection
 * \param[in]     keyElementId         Valid keyElement which shall be used as source for the redirection
 * \param[in,out] dataBufferLengthPtr  Valid pointer to length of the dataBufferPtr
 * \param[in,out] ptrBuf               Valid pointer to the memory where the pointer shall be serialized.
 *                                     Must at least provide 8 byte of storage after the offset.
 * \return        E_OK if the output redirection has been correctly serialized, otherwise E_NOT_OK.
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeOutputRedirection(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  uint32 keyId,
  uint32 keyElementId,
# if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) dataBufferLengthPtr,
# endif
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf);
#endif /* (CRYPTO_30_VHSM_REDIRECTION == STD_ON) */

#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_CheckBufferReplacementError()
 *********************************************************************************************************************/
/*!
 * \brief         Check if an error occurred due to a previously performed buffer replacement
 * \details       -
 * \param[in]     jobRequestId            Valid jobRequestId
 * \param[in]     jobResult               result of the job
 * \param[in]     notAllowedJobResult     Result which will generate a DET if replacement has been performed before
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_CheckBufferReplacementError(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  Std_ReturnType jobResult,
  Std_ReturnType notAllowedJobResult);
#endif

/**********************************************************************************************************************
 *  Crypto_30_vHsm_AddUsedBuffer()
 *********************************************************************************************************************/
 /*!
 * \brief         Increment the used buffer size in at least 4 byte steps
 * \details       This function ensures that following buffers start at an aligned address to have better performance because uint32 memory access can be used.
 * \param[in]     jobRequestId            Valid jobRequest
 * \param[in]     value                   Value which shall be added to the usedBuffer
 * \pre           -
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_AddUsedBuffer(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  uint32 value);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_Inputs()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a crypto job inputs
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to job object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the crypto job will be serialized.
 *                                      Must be at least of size 24.
 * \param[in,out] offsetPtr             Offset where the data shall be serialized. Contains the offset which needs to be used to serialize the rest of the data.
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_Inputs(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
, P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) offsetPtr
#endif
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
#endif
  );

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_Outputs()
 *********************************************************************************************************************/
/*!
 * \brief         Serialization of a crypto job outputs
 * \details       -
 * \param[in]     jobRequestId          Valid jobRequestId
 * \param[in]     cryptoJobPtr          Valid pointer to job object
 * \param[in,out] ptrBuf                Valid pointer to buffer where the crypto job will be serialized.
 *                                      Must be at least of size 16.
 * \param[in,out] offsetPtr             Offset where the data shall be serialized. Contains the offset which needs to be used to serialize the rest of the data.
 * \param[in,out] jobRedirectionInfoPtr Valid pointer to the redirection info.
 *                                      The availability of this parameter depends on the configuration.
 * \return        E_OK if no errors occurred, otherwise E_NOT_OK.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_Outputs(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
, P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) offsetPtr
#endif
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr
#endif
  );

#define CRYPTO_30_VHSM_STOP_SEC_CODE
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_START_SEC_CODE
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_CheckBufferReplacementError()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_CheckBufferReplacementError(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  Std_ReturnType jobResult,
  Std_ReturnType notAllowedJobResult)
{
  /* #10 Check if the buffer size has been replaced by the driver prior to sending the request to the vHsm */
  if (Crypto_30_vHsm_IsTrimmedOutputBufferOfJobRequest(jobRequestId) == FALSE)
  {
    /* Do nothing. */
  }
  /* #11 Check if the error indicating a too small buffer has been issued */
  else if (jobResult != notAllowedJobResult)
  {
    /* Do nothing */
  }
  else
  {
# if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
    /* #12 Issue DET because the buffer provided by the driver was too small */
    /* If a buffer provided to the driver is not in a valid memory area, the driver provides an own buffer to the vHsm.
    This buffer may be smaller than the buffer originally provided by the application.
    Upon receiving the response, the driver checks if a buffer replacement has taken place an will issue a DET if the vHsm complains about a too small buffer, because a bigger configured buffer will solve the issue.
    If the following DET is triggered, either increase the buffer size of of the driver object with /MICROSAR/Crypto_30_vHsm/Crypto/CryptoDriverObjects/CryptoDriverObject/CryptovHsmBuffer
    or directly provide a buffer which is located in a usable memory area so that buffering by the driver is not needed. */
    (void)Det_ReportError(CRYPTO_30_VHSM_MODULE_ID, CRYPTO_30_VHSM_INSTANCE_ID, CRYPTO_30_VHSM_SID_PROCESS_JOB, CRYPTO_E_GLOBAL_BUFFER_TOO_SMALL);
# endif
  }
}
#endif

/**********************************************************************************************************************
 *  Crypto_30_vHsm_IsMemoryValid()
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
CRYPTO_30_VHSM_LOCAL FUNC( boolean, CRYPTO_30_VHSM_CODE ) Crypto_30_vHsm_IsMemoryValid(
  P2CONST( uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) ptr,
  uint32 length,
  boolean isInput )
{
  boolean retVal = FALSE;

  if ( (NULL_PTR == ptr)
    && (0u == length) ) /* COV_CRYPTO_30_VHSM_ROBUST_POINTER_CHECK */
  {
    retVal = TRUE;
  }
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_OFF)
  else if (length == 0u)
  {
    retVal = FALSE;
  }
#endif
  /* Check for overflow */
  else if (&ptr[length] < ptr) /*lint !e613 */ /* PRQA S 2822 */ /* MD_CRYPTO_30_VHSM_2822_DEREFERENCING_NULLPTR */
  {
    retVal = FALSE;
  }
  else
  {
#if (CRYPTO_30_VHSM_MEMORYAREA == STD_ON)
    Crypto_30_vHsm_MemoryAreaIterType memAreaIdx;
    P2CONST( uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) startAddress;
    P2CONST( uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) stopAddress;
    /* #10 For all memory areas: */
    for (memAreaIdx = 0u; memAreaIdx < Crypto_30_vHsm_GetSizeOfMemoryArea(); memAreaIdx++)
    {
      /* #20 Check if this is the area we are looking for */
      if ( (isInput == TRUE)
# if (CRYPTO_30_VHSM_READWRITE_AVAILABLE == STD_ON)
        || (Crypto_30_vHsm_GetAreaTypeOfMemoryArea( memAreaIdx ) == CRYPTO_30_VHSM_AREA_HSM_READWRITE_ACCESS)
# endif
        )
      {
        /* #30 Get the start and stop address */
        startAddress = (P2CONST( uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA))(uint32)Crypto_30_vHsm_GetAreaStartOfMemoryArea( memAreaIdx ); /* PRQA S 0306 */ /* MD_CRYPTO_30_VHSM_0306_CHECK_MEMORY_LAYOUT */
        stopAddress = (P2CONST( uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA))(uint32)Crypto_30_vHsm_GetAreaStopOfMemoryArea( memAreaIdx ); /* PRQA S 0306 */ /* MD_CRYPTO_30_VHSM_0306_CHECK_MEMORY_LAYOUT */

        /* #40 Check if the pointer and its length are inside the current memory area */
        if ( (&ptr[0] >= startAddress) /*lint !e613 */ /* PRQA S 2822 */ /* MD_CRYPTO_30_VHSM_2822_DEREFERENCING_NULLPTR */
          && (&ptr[length - 1u] <= stopAddress) ) /*lint !e613 */ /* PRQA S 2822 */ /* MD_CRYPTO_30_VHSM_2822_DEREFERENCING_NULLPTR */
        {
          retVal = TRUE;
          break;
        }
      }
    }
#else
    CRYPTO_30_VHSM_DUMMY_STATEMENT(isInput); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_AddUsedBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_AddUsedBuffer(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  uint32 value)
{
  /* #10 Check if new value is not a multiple of 4 bytes */
  if ((value & 0x3uL) != 0u)
  {
    /* #11 Set the value to the next value which is a multiple of 4 */
    Crypto_30_vHsm_SetUsedBufferOfJobRequest(jobRequestId, Crypto_30_vHsm_GetUsedBufferOfJobRequest(jobRequestId) + (value & 0xFFFFFFFCuL) + 4u); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
  }
  else
  {
    /* #12 Set the value because it is a multiple of 4 bytes */
    Crypto_30_vHsm_SetUsedBufferOfJobRequest(jobRequestId, Crypto_30_vHsm_GetUsedBufferOfJobRequest(jobRequestId) + value); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
  }
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeOutputPtr()
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
 */
CRYPTO_30_VHSM_LOCAL FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeOutputPtr(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) outputPtr,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) outputLengthPtr,
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) dataBufferLengthPtr,
#endif
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf,
  P2VAR(volatile uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) outputOffset) /* PRQA S 3673 */ /* MD_CRYPTO_30_VHSM_3673_API_SPECIFIC */
{
  /* Get information from the jobRequest */
  uint32 usedBuffer = Crypto_30_vHsm_GetUsedBufferOfJobRequest(jobRequestId);
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  uint32 dataBufferLength;
#endif

  /* #10 Check if outputLengthPtr is not a NULL_PTR */
  if (outputLengthPtr != NULL_PTR)
  {
    /* #20 Check if NoBuffering shall be applied */
#if (CRYPTO_30_VHSM_NOBUFFERING_ENABLED == STD_ON)
    if (Crypto_30_vHsm_IsBufferUsedOfObjectInfo(jobRequestId) == FALSE)
    {
      /* Set the length to the given value */
# if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
      dataBufferLength = *outputLengthPtr;
# else
      *dataBufferLengthPtr = *outputLengthPtr; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL */
# endif

      /* Provide the original pointer to the vHsm */
      Crypto_30_vHsm_Serialize_Ptr32(outputPtr, ptrBuf); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */

      /* Indicate that the shared output buffer was not used for this output */
      *outputOffset = CRYPTO_30_VHSM_OUTPUT_BUFFER_NOT_USED; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL */
    }
    else
#endif
    /* #30 ELSE Check if it is shared ram: */
    if (Crypto_30_vHsm_IsMemoryValid(outputPtr, *outputLengthPtr, FALSE) == TRUE) /* SBSW_CRYPTO_30_VHSM_MEMORY_VALID_CHECK */
    {
      /* Set the length to the given value */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
      dataBufferLength = *outputLengthPtr;
#else
      *dataBufferLengthPtr = *outputLengthPtr; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL */
#endif

      /* Provide the original pointer to the vHsm */
      Crypto_30_vHsm_Serialize_Ptr32(outputPtr, ptrBuf); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */

      /* Indicate that the shared output buffer was not used for this output */
      *outputOffset = CRYPTO_30_VHSM_OUTPUT_BUFFER_NOT_USED; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL */
    }
    else
    {
      P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) dataBufferPtr = Crypto_30_vHsm_GetAddrSharedDataBufferOfDriverObject(jobRequestId, usedBuffer);
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
      dataBufferLength = Crypto_30_vHsm_GetSharedDataBufferSizeOfDriverObject(jobRequestId) - usedBuffer;
#else
      *dataBufferLengthPtr = Crypto_30_vHsm_GetSharedDataBufferSizeOfDriverObject(jobRequestId) - usedBuffer; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL */
#endif

      /* Make sure that the provided buffer size is the maximum, if the global buffer is smaller, use it's size instead. */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
      if (*outputLengthPtr < dataBufferLength)
      {
        dataBufferLength = *outputLengthPtr;
      }
#else
      if (*outputLengthPtr < *dataBufferLengthPtr)
      {
        *dataBufferLengthPtr = *outputLengthPtr; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL */
      }
#endif
      else
      {
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
        /* Store the information, that the buffer has been trimmed */
        /* The provided buffer to the vHsm will be smaller than the buffer provided by the application. This may lead to CRYPTO_E_SMALL_BUFFER or CRYPTO_E_KEY_SIZE_MISMATCH although the application has provided a big enough buffer to the driver.
           In this case a DET will be triggered and the buffer needs to be incread in the configuration */
        Crypto_30_vHsm_SetTrimmedOutputBufferOfJobRequest(jobRequestId, TRUE); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
#endif
      }

      /* Store the offset to the memory where the output will be redirected */
      *outputOffset = usedBuffer; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL */

      /* Add the size of the current output buffer to the fill level of the shared buffer of this driver object */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
      Crypto_30_vHsm_AddUsedBuffer(jobRequestId, dataBufferLength);
#else
      Crypto_30_vHsm_AddUsedBuffer(jobRequestId, *dataBufferLengthPtr);
#endif

      /* Provide the pointer to a shared buffer to the vHsm */
      Crypto_30_vHsm_Serialize_Ptr32(dataBufferPtr, ptrBuf); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
    }
  }
  else
  {
    /* set the value to default 0 */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
    dataBufferLength = 0u;
#else
    *dataBufferLengthPtr = 0u; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL */
#endif

    *outputOffset = usedBuffer; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL */

    /* #70 Provide NULL_PTR to the vHsm */
    Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, ptrBuf); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
  }

  /* #80 Serialize the outputLengthPtr */
  /* #90 Serialize the value */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  Crypto_30_vHsm_Serialize_Uint32(dataBufferLength, &ptrBuf[4]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
#else
  Crypto_30_vHsm_Serialize_Ptr32(dataBufferLengthPtr, &ptrBuf[4]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
#endif

#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_OFF)
  CRYPTO_30_VHSM_DUMMY_STATEMENT(jobRequestId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeInputPtr()
 *********************************************************************************************************************/
/*!
 *
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
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeInputPtr(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf,
  boolean interpretlengthInBits) /* PRQA S 3673 */ /* MD_CRYPTO_30_VHSM_3673_API_SPECIFIC */
{
  Std_ReturnType retVal = E_OK;

  /* Get information from the jobRequest */
  uint32 usedBuffer = Crypto_30_vHsm_GetUsedBufferOfJobRequest(jobRequestId);

  uint32 inputLengthInBytes = inputLength;

  if (interpretlengthInBits == TRUE)
  {
    inputLengthInBytes /= 8u;
    if ((inputLength % 8u) != 0u)
    {
      inputLengthInBytes += 1u;
    }
  }

  /* #10 Serialization of inputPtr */
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_OFF)
  if ((inputLength != 0u)
    && (inputPtr == NULL_PTR))
  {
    /* #20 Serialize the inputPtr */
    Crypto_30_vHsm_Serialize_Ptr32(inputPtr, ptrBuf); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */

    /* #30 NULL_PTR as input is not allowed when length is not zero */
    retVal = E_NOT_OK;
  }
  else
#endif
  {
    /* #40 Check if NoBuffering shall be applied */
#if (CRYPTO_30_VHSM_NOBUFFERING_ENABLED == STD_ON)
    if (Crypto_30_vHsm_IsBufferUsedOfObjectInfo(jobRequestId) == FALSE)
    {
      /* Serialize the inputPtr */
      Crypto_30_vHsm_Serialize_Ptr32(inputPtr, ptrBuf); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
    }
    else
#endif
    /* #41 ELSE Check if it is accessible memory */
    if (Crypto_30_vHsm_IsMemoryValid(inputPtr, inputLengthInBytes, TRUE) == TRUE) /* SBSW_CRYPTO_30_VHSM_MEMORY_VALID_CHECK */
    {
      /* Serialize the inputPtr */
      Crypto_30_vHsm_Serialize_Ptr32(inputPtr, ptrBuf); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
    }
    else
    {
      P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) dataBufferPtr = Crypto_30_vHsm_GetAddrSharedDataBufferOfDriverObject(jobRequestId, usedBuffer);
      uint32 dataBufferLength = Crypto_30_vHsm_GetSharedDataBufferSizeOfDriverObject(jobRequestId) - usedBuffer;

      /* Check if the provided input data can be buffered to the global RAM buffer. */
      if (dataBufferLength >= inputLengthInBytes)
      {
        /* Copy the input data to a memory location which can be read by the vHsm */
        VStdLib_MemCpy(dataBufferPtr, inputPtr, inputLengthInBytes); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_VHSM_COPY_TO_GLOBAL_BUFFER_FROM_SOURCE */

        /* Serialize the pointer to the buffer. */
        Crypto_30_vHsm_Serialize_Ptr32(dataBufferPtr, ptrBuf); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
        Crypto_30_vHsm_AddUsedBuffer(jobRequestId, inputLengthInBytes);
      }
      else
      {
        /* There is not enough space in the buffer to store the input data. */
        Crypto_30_vHsm_Serialize_Ptr32(dataBufferPtr, ptrBuf); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
        (void)Det_ReportError(CRYPTO_30_VHSM_MODULE_ID, CRYPTO_30_VHSM_INSTANCE_ID, CRYPTO_30_VHSM_SID_PROCESS_JOB, CRYPTO_E_GLOBAL_BUFFER_TOO_SMALL);
#endif
        retVal = E_NOT_OK;
      }
    }
  }

  /* #100 Serialization of inputLength */
  Crypto_30_vHsm_Serialize_Uint32(inputLength, &ptrBuf[4]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

  return retVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeInputRedirection()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeInputRedirection(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  uint32 keyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf) /* PRQA S 3673 */ /* MD_CRYPTO_30_VHSM_3673_API_SPECIFIC */
{
  Std_ReturnType retVal = E_OK;

  /* Get information from the jobRequest */
  uint32 usedBuffer = Crypto_30_vHsm_GetUsedBufferOfJobRequest(jobRequestId);
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) dataBufferPtr = Crypto_30_vHsm_GetAddrSharedDataBufferOfDriverObject(jobRequestId, usedBuffer);
  uint32 dataBufferLength = Crypto_30_vHsm_GetSharedDataBufferSizeOfDriverObject(jobRequestId) - usedBuffer;

  /* #10 Check if provided buffer is big enough */
  if (dataBufferLength < 8u)
  {
    /* The provided buffer is not big enough */
    Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, ptrBuf); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
    Crypto_30_vHsm_Serialize_Uint32(0u, &ptrBuf[4]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    retVal = E_NOT_OK;
  }
  else
  {
    /* #20 Store keyId and keyElementId to the global RAM buffer */
    Crypto_30_vHsm_Serialize_Uint32(keyId, dataBufferPtr); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(keyElementId, &dataBufferPtr[4]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

    /* #30 Serialize the data Buffer to the IPC */
    Crypto_30_vHsm_Serialize_Ptr32(dataBufferPtr, ptrBuf); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */

    /* #40 Serialize length to the IPC */
    Crypto_30_vHsm_Serialize_Uint32(8u, &ptrBuf[4]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_SetUsedBufferOfJobRequest(jobRequestId, usedBuffer + 8u); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */
#endif

#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeOutputRedirection()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeOutputRedirection(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  uint32 keyId,
  uint32 keyElementId,
# if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) dataBufferLengthPtr,
# endif
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf) /* PRQA S 3673 */ /* MD_CRYPTO_30_VHSM_3673_API_SPECIFIC */
{
  Std_ReturnType retVal = E_OK;

  /* Get information from the jobRequest */
  uint32 usedBuffer = Crypto_30_vHsm_GetUsedBufferOfJobRequest(jobRequestId);
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) dataBufferPtr = Crypto_30_vHsm_GetAddrSharedDataBufferOfDriverObject(jobRequestId, usedBuffer);
# if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
  *dataBufferLengthPtr = (Crypto_30_vHsm_GetSharedDataBufferSizeOfDriverObject(jobRequestId) - usedBuffer); /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL */
# else
  uint32 dataBufferLength = Crypto_30_vHsm_GetSharedDataBufferSizeOfDriverObject(jobRequestId) - usedBuffer;
# endif
  /* #10 Check if provided buffer is big enough */
# if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
  if (*dataBufferLengthPtr < 8u)
  {
    /* The provided buffer is not big enough */
    Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, ptrBuf); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
    *dataBufferLengthPtr = 0u; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL */
    Crypto_30_vHsm_Serialize_Uint32(dataBufferLengthPtr, &ptrBuf[4]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    retVal = E_NOT_OK;
  }
# else
  if (dataBufferLength < 8u)
  {
    /* The provided buffer is not big enough */
    Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, ptrBuf); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
    Crypto_30_vHsm_Serialize_Uint32(0u, &ptrBuf[4]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    retVal = E_NOT_OK;
  }
# endif
  else
  {
    /* #20 Store keyId and keyElementId to the global RAM buffer */
    Crypto_30_vHsm_Serialize_Uint32(keyId, dataBufferPtr); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(keyElementId, &dataBufferPtr[4]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

    /* #30 Serialize the data Buffer to the IPC */
    Crypto_30_vHsm_Serialize_Ptr32(dataBufferPtr, ptrBuf); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */

    /* #40 Serialize length to the IPC */
# if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
    *dataBufferLengthPtr = 8u; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_CSL */
    Crypto_30_vHsm_Serialize_Ptr32(dataBufferLengthPtr, &ptrBuf[4]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
# else
    Crypto_30_vHsm_Serialize_Ptr32(8u, &ptrBuf[4]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
# endif
    Crypto_30_vHsm_SetUsedBufferOfJobRequest(jobRequestId, usedBuffer + 8u); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */
#endif

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeInput()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeInput(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
#endif
  )
{
  Std_ReturnType retVal;

#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
  if ((jobRedirectionInfoPtr->redirectionConfig & CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT) == CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT)
  {
    /* #10 Serialization of redirection for inputPtr */
    retVal = Crypto_30_vHsm_SerializeInputRedirection( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE_REDIRECTION_WITH_GLOBAL_BUFFERS */
      jobRequestId,
      jobRedirectionInfoPtr->inputKeyId,
      jobRedirectionInfoPtr->inputKeyElementId,
      ptrBuf);
  }
  else
#endif
  {
    /* #20 Serialization of inputPtr */
    retVal = Crypto_30_vHsm_SerializeInputPtr( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE_PTR_WITH_GLOBAL_BUFFERS */
      jobRequestId,
      cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr,
      cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
      ptrBuf,
      FALSE);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeSecondaryInput()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeSecondaryInput(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
#endif
  )
{
  Std_ReturnType retVal;

#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
  if ((jobRedirectionInfoPtr->redirectionConfig & CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT) == CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT)
  {
    /* #10 Serialization of redirection for secondaryInputPtr */
    retVal = Crypto_30_vHsm_SerializeInputRedirection( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE_REDIRECTION_WITH_GLOBAL_BUFFERS */
      jobRequestId,
      jobRedirectionInfoPtr->secondaryInputKeyId,
      jobRedirectionInfoPtr->secondaryInputKeyElementId,
      ptrBuf);
  }
  else
#endif
  {
    /* #20 Serialization of secondaryInputPtr */
    retVal = Crypto_30_vHsm_SerializeInputPtr( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE_PTR_WITH_GLOBAL_BUFFERS */
      jobRequestId,
      cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputPtr,
      cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryInputLength,
      ptrBuf,
      (cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->service == CRYPTO_MACVERIFY));
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeTertiaryInput()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeTertiaryInput(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
#endif
  )
{
  Std_ReturnType retVal;

#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
  if ((jobRedirectionInfoPtr->redirectionConfig & CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT) == CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT)
  {
    /* #10 Serialization of redirection for tertiaryInputPtr */
    retVal = Crypto_30_vHsm_SerializeInputRedirection( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE_REDIRECTION_WITH_GLOBAL_BUFFERS */
      jobRequestId,
      jobRedirectionInfoPtr->tertiaryInputKeyId,
      jobRedirectionInfoPtr->tertiaryInputKeyElementId,
      ptrBuf);
  }
  else
#endif
  {
    /* #20 Serialization of tertiaryInputPtr */
    retVal = Crypto_30_vHsm_SerializeInputPtr( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE_PTR_WITH_GLOBAL_BUFFERS */
      jobRequestId,
      cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.tertiaryInputPtr,
      cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.tertiaryInputLength,
      ptrBuf,
      FALSE);
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeOutput()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeOutput(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
#endif
  )
{
  Std_ReturnType retVal = E_OK;

#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
  if ((jobRedirectionInfoPtr->redirectionConfig & CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT) == CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT)
  {
    /* #10 Serialization of redirection for outputPtr */
    retVal = Crypto_30_vHsm_SerializeOutputRedirection( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE_REDIRECTION_WITH_GLOBAL_BUFFERS */
      jobRequestId,
      jobRedirectionInfoPtr->outputKeyId,
      jobRedirectionInfoPtr->outputKeyElementId,
# if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
      Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId),
# endif
      ptrBuf);
  }
  else
#endif
  {
    /* #20 Serialization of outputPtr */
    Crypto_30_vHsm_SerializeOutputPtr( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE_PTR_WITH_GLOBAL_BUFFERS */
      jobRequestId,
      cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr,
      cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr,
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
      Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId),
#endif
      ptrBuf,
      &Crypto_30_vHsm_GetOutputOffsetOfJobRequest(jobRequestId));
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeSecondaryOutput()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeSecondaryOutput(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
#endif
  )
{
  Std_ReturnType retVal = E_OK;

#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
  if ((jobRedirectionInfoPtr->redirectionConfig & CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT) == CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT)
  {
    /* #10 Serialization of redirection for secondaryOutputPtr */
    retVal = Crypto_30_vHsm_SerializeOutputRedirection( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE_REDIRECTION_WITH_GLOBAL_BUFFERS */
      jobRequestId,
      jobRedirectionInfoPtr->secondaryOutputKeyId,
      jobRedirectionInfoPtr->secondaryOutputKeyElementId,
# if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
      Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(jobRequestId),
# endif
      ptrBuf);
  }
  else
#endif
  {
    /* #20 Serialization of secondaryOutputPtr */
    Crypto_30_vHsm_SerializeOutputPtr( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE_PTR_WITH_GLOBAL_BUFFERS */
      jobRequestId,
      cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryOutputPtr,
      cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryOutputLengthPtr,
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
      Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(jobRequestId),
#endif
      ptrBuf,
      &Crypto_30_vHsm_GetSecondaryOutputOffsetOfJobRequest(jobRequestId));
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_Inputs()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_Inputs(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  , P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) offsetPtr
#endif
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
  , P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
#endif
  )
{
  Std_ReturnType retVal;
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  uint32 offset = *offsetPtr;
#else
  uint32 offset = 4;
#endif

  /* #10 Serialization of Input */
  if ((Crypto_30_vHsm_JobIOAvailable[cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->service] & CRYPTO_30_VHSM_IO_INPUT) == CRYPTO_30_VHSM_IO_INPUT)
  {
    retVal = Crypto_30_vHsm_SerializeInput( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE */
      jobRequestId,
      cryptoJobPtr,
      &ptrBuf[offset]
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
      , jobRedirectionInfoPtr
#endif
    );
    offset += 8u;
    /* #20 Serialization of Secondary Input */
    if ((Crypto_30_vHsm_JobIOAvailable[cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->service] & CRYPTO_30_VHSM_IO_SECONDARYINPUT) == CRYPTO_30_VHSM_IO_SECONDARYINPUT)
    {
      retVal |= Crypto_30_vHsm_SerializeSecondaryInput( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE */
        jobRequestId,
        cryptoJobPtr,
        &ptrBuf[offset]
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
        , jobRedirectionInfoPtr
#endif
      );
      offset += 8u;
      /* #30 Serialization of Tertiary Input */
      if ((Crypto_30_vHsm_JobIOAvailable[cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->service] & CRYPTO_30_VHSM_IO_TERTIARYINPUT) == CRYPTO_30_VHSM_IO_TERTIARYINPUT)
      {
        retVal |= Crypto_30_vHsm_SerializeTertiaryInput( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE */
          jobRequestId,
          cryptoJobPtr,
          &ptrBuf[offset]
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
          , jobRedirectionInfoPtr
#endif
        );
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
        offset += 8u;
#endif
      }
      else
      {
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
        Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, &ptrBuf[20]); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
        Crypto_30_vHsm_Serialize_Uint32(0u, &ptrBuf[24]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
#endif
      }
    }
    else
    {
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
      Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, &ptrBuf[12]); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
      Crypto_30_vHsm_Serialize_Uint32(0u, &ptrBuf[16]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

      Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, &ptrBuf[20]); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
      Crypto_30_vHsm_Serialize_Uint32(0u, &ptrBuf[24]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
#endif
    }
  }
  else
  {
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
    Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, &ptrBuf[4]); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
    Crypto_30_vHsm_Serialize_Uint32(0u, &ptrBuf[8]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

    Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, &ptrBuf[12]); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
    Crypto_30_vHsm_Serialize_Uint32(0u, &ptrBuf[16]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

    Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, &ptrBuf[20]); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
    Crypto_30_vHsm_Serialize_Uint32(0u, &ptrBuf[24]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
#endif

    retVal = E_OK;
  }

#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  *offsetPtr = offset; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_STACK */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_Outputs()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_VHSM_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_Outputs(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  , P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) offsetPtr
#endif
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
  , P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
#endif
  )
{
  Std_ReturnType retVal;
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  uint32 offset = *offsetPtr;
#else
  uint32 offset = 28u;
#endif
  /* #40 Serialization of Output */
  if ((Crypto_30_vHsm_JobIOAvailable[cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->service] & CRYPTO_30_VHSM_IO_OUTPUT) == CRYPTO_30_VHSM_IO_OUTPUT)
  {
    retVal = Crypto_30_vHsm_SerializeOutput( /* PRQA S 2985 */ /* MD_CRYPTO_30_VHSM_2985_REDUNDANT_OP_WHEN_NO_REDIRECTION */ /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE */
      jobRequestId,
      cryptoJobPtr,
      &ptrBuf[offset]
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
      , jobRedirectionInfoPtr
#endif
      );
    offset += 8u;
    /* #50 Serialization of Secondary Output */
    if ((Crypto_30_vHsm_JobIOAvailable[cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->service] & CRYPTO_30_VHSM_IO_SECONDARYOUTPUT) == CRYPTO_30_VHSM_IO_SECONDARYOUTPUT)
    {
      retVal |= Crypto_30_vHsm_SerializeSecondaryOutput( /* PRQA S 2985 */ /* MD_CRYPTO_30_VHSM_2985_REDUNDANT_OP_WHEN_NO_REDIRECTION */ /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE */
        jobRequestId,
        cryptoJobPtr,
        &ptrBuf[offset]
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
        , jobRedirectionInfoPtr
#endif
        );
      /* this addition to the offset is only needed if we are IPCv3 */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
      offset+=8u;
#endif
    }
    else
    {
      *Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(jobRequestId) = 0u; /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
      Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, &ptrBuf[36]); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
      Crypto_30_vHsm_Serialize_Ptr32(Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(jobRequestId), &ptrBuf[40]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
#endif
    }
  }
  else
  {
    *Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId) = 0u; /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
    Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, &ptrBuf[28]); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
    Crypto_30_vHsm_Serialize_Ptr32(Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId), &ptrBuf[32]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
#endif

    *Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(jobRequestId) = 0u; /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
    Crypto_30_vHsm_Serialize_Ptr32(NULL_PTR, &ptrBuf[36]); /* PRQA S 0306, 0310, 0326, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
    Crypto_30_vHsm_Serialize_Ptr32(Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(jobRequestId), &ptrBuf[40]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */
#endif

    retVal = E_OK;
  }

#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  *offsetPtr = offset; /* SBSW_CRYPTO_30_VHSM_VARIABLE_ACCESS_PTR_FROM_STACK */
#endif

  return retVal;
}

#define CRYPTO_30_VHSM_STOP_SEC_CODE
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_START_SEC_CODE
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
, P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
#endif
  )
{
  Std_ReturnType retVal;
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  uint32 offset = 8u;
  uint8 numOfInputs;
  uint32 inputOffset;
  uint8 numOfOutputs;
  uint8 numOfConstData = 3u;
  uint8 numOfCryptoKeyIds = 0u;
  uint32 numOfInOutKeyConst;
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #05 Check if the request can be serialized to the provided buffer */
  if (cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->service < CRYPTO_30_VHSM_INVALID_SERVICES)
  {
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
    Crypto_30_vHsm_Serialize_Uint32(Crypto_30_vHsm_GetJobStateOfJobRequest(jobRequestId), ptrBuf); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
#endif

    /* #10 Serialization of Inputs */
    retVal = Crypto_30_vHsm_SerializeRequest_CryptoJob_Inputs( /* SBSW_CRYPTO_30_VHSM_ForwardingIpcBufferAsPtr_SerializeRequest_CryptoJob_Inputs */
      jobRequestId,
      cryptoJobPtr,
      ptrBuf
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
      , &offset
#endif
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
      , jobRedirectionInfoPtr
#endif
    );

#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
    inputOffset = offset;
#endif
    /* #40 Serialization of Outputs */
    retVal |= Crypto_30_vHsm_SerializeRequest_CryptoJob_Outputs( /* PRQA S 2985 */ /* MD_CRYPTO_30_VHSM_2985_REDUNDANT_OP_WHEN_NO_REDIRECTION */ /* SBSW_CRYPTO_30_VHSM_ForwardingIpcBufferAsPtr_SerializeRequest_CryptoJob_Outputs */
      jobRequestId,
      cryptoJobPtr,
      ptrBuf
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
      , &offset
#endif
#if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
      , jobRedirectionInfoPtr
#endif
    );
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
    /* Calculate num of input and outputs properly */

    numOfOutputs = (uint8)(offset-inputOffset) / 8u;
    numOfInputs = (uint8)(inputOffset - 4u) / 8u;

    /* Serialize all keyIds, since we have only one here it does not need to be refactored to subfunction */
    Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->cryptoKeyId, &ptrBuf[offset]);/* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    offset += 4u;
    numOfCryptoKeyIds++;
# if (CRYPTO_30_VHSM_KEY_DERIVE_JOB_SUPPORT == STD_ON)
    if ((Crypto_30_vHsm_JobIOAvailable[cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->service] & CRYPTO_30_VHSM_IO_SECONDARYKEY) == CRYPTO_30_VHSM_IO_SECONDARYKEY)
    {
      Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->targetCryptoKeyId, &ptrBuf[offset]);/* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
      offset += 4u;
      numOfCryptoKeyIds++;
    }
# endif

    /* Serialize constData */
    /* SHIFT multiple values into one uint32 in IPC to improve performance */
    Crypto_30_vHsm_Serialize_Uint32( /* PRQA S 0310, 3305, 4304 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
      ( ((uint32)cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.family)
      | ((uint32)cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.mode << 8u)
      | ((uint32)cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily << 16u)
      | ((uint32)Crypto_30_vHsm_GetProcessingTypeOfJobRequest(jobRequestId) << 24u)
      | ((uint32)Crypto_30_vHsm_GetJobStateOfJobRequest(jobRequestId) << 25u)
      | ((uint32)Crypto_30_vHsm_IsCancelOfJobRequest(jobRequestId) << 28u)
      | ((uint32)cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.mode << 29u)),
      &ptrBuf[offset]);

    Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.keyLength, &ptrBuf[offset + 4u]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobInfo->jobId, &ptrBuf[offset + 8u]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
# if (CRYPTO_30_VHSM_SUPPORT_SAVE_RESTORE_CONTEXT == STD_ON)
    Crypto_30_vHsm_Serialize_Uint32(((uint32)cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.mode), &ptrBuf[offset + 12u]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    numOfConstData++;
# endif
    numOfInOutKeyConst = ((uint32)numOfInputs << 24u) | ((uint32)numOfOutputs << 16u) | ((uint32)numOfCryptoKeyIds << 8u) | ((uint32)numOfConstData);
    Crypto_30_vHsm_Serialize_Uint32(numOfInOutKeyConst, ptrBuf); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->service, &ptrBuf[4u]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
#else
    /* #60 Prepare verifyPtr  */
    *Crypto_30_vHsm_GetAddrVerifyPtrDataBuffer(jobRequestId) = 0xFEu; /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
    /* #62 Serialize verifyPtr */
    Crypto_30_vHsm_Serialize_Ptr32(Crypto_30_vHsm_GetAddrVerifyPtrDataBuffer(jobRequestId), &ptrBuf[44]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */

    /* #70 Serialization of everything else */
    /* PRQA S 0310, 3305 8 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */
    Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.mode, &ptrBuf[48]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->service, &ptrBuf[52]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.family, &ptrBuf[56]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.mode, &ptrBuf[60]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily, &ptrBuf[64]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(Crypto_30_vHsm_GetProcessingTypeOfJobRequest(jobRequestId), &ptrBuf[68]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobInfo->jobId, &ptrBuf[72]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->cryptoKeyId, &ptrBuf[76]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
#endif
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}

#if (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_MacGen()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_MacGen(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
# if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
  , P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
# endif
)
{
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  Crypto_30_vHsm_Serialize_Uint32(Crypto_30_vHsm_GetJobStateOfJobRequest(jobRequestId), ptrBuf); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

  /* #10 Serialization of Input */
  retVal = Crypto_30_vHsm_SerializeInput( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE */
    jobRequestId,
    cryptoJobPtr,
    &ptrBuf[4]
# if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
    , jobRedirectionInfoPtr
# endif
  );

  /* #40 Serialization of Output */
  retVal |= Crypto_30_vHsm_SerializeOutput( /* PRQA S 2985 */ /* MD_CRYPTO_30_VHSM_2985_REDUNDANT_OP_WHEN_NO_REDIRECTION */  /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE */
    jobRequestId,
    cryptoJobPtr,
    &ptrBuf[12]
# if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
    , jobRedirectionInfoPtr
# endif
  );

  /* #60 Prepare verifyPtr */
  *Crypto_30_vHsm_GetAddrVerifyPtrDataBuffer(jobRequestId) = 0xFEu; /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */

  /* #70 Serialization of everything else */
  /* PRQA S 0310, 3305 6 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.mode, &ptrBuf[20]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.family, &ptrBuf[24]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.mode, &ptrBuf[28]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(Crypto_30_vHsm_GetProcessingTypeOfJobRequest(jobRequestId), &ptrBuf[32]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobInfo->jobId, &ptrBuf[36]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->cryptoKeyId, &ptrBuf[40]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

  return retVal;
}
#endif

#if (CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION== STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_MacVer()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_MacVer(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf
# if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
  , P2VAR(Crypto_JobRedirectionInfoType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) jobRedirectionInfoPtr /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
# endif
)
{
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  Crypto_30_vHsm_Serialize_Uint32(Crypto_30_vHsm_GetJobStateOfJobRequest(jobRequestId), ptrBuf); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

  /* #10 Serialization of Input */
  retVal = Crypto_30_vHsm_SerializeInput( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE */
    jobRequestId,
    cryptoJobPtr,
    &ptrBuf[4]
# if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
    , jobRedirectionInfoPtr
# endif
  );

  /* #20 Serialization of Secondary Input */
  retVal |= Crypto_30_vHsm_SerializeSecondaryInput( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE */
    jobRequestId,
    cryptoJobPtr,
    &ptrBuf[12]
# if (CRYPTO_30_VHSM_REDIRECTION == STD_ON)
    , jobRedirectionInfoPtr
# endif
  );

  /* #60 Prepare verifyPtr */
  *Crypto_30_vHsm_GetAddrVerifyPtrDataBuffer(jobRequestId) = 0xFEu; /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */

  /* #62 Serialize verifyPtr */
  Crypto_30_vHsm_Serialize_Ptr32(Crypto_30_vHsm_GetAddrVerifyPtrDataBuffer(jobRequestId), &ptrBuf[20]); /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_PTR_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_PTR */

  /* #70 Serialization of everything else */
  /* PRQA S 0310, 3305 6 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.mode, &ptrBuf[24]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.family, &ptrBuf[28]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.mode, &ptrBuf[32]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(Crypto_30_vHsm_GetProcessingTypeOfJobRequest(jobRequestId), &ptrBuf[36]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobInfo->jobId, &ptrBuf[40]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->cryptoKeyId, &ptrBuf[44]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

  return retVal;
}
#endif

/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_KeyMJob()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_KeyMJob(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId,
  P2CONST(Crypto_30_vHsm_KeyM_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) keyMJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf)
{
  Std_ReturnType retVal;
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  uint32 ptrMask = 0u;
  uint8 numOfKeys = 1u;
  uint8 numOfConst;
  uint32 offset = 8u;
#else
  uint32 offset = 20u;
#endif

  /* ----- Implementation ----------------------------------------------- */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  retVal = E_OK;
#else
    /* PRQA S 0310, 3305 5 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->action, ptrBuf); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->cryptoKeyId, &ptrBuf[4]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->secondaryCryptoKeyId, &ptrBuf[8]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->keyElementId, &ptrBuf[12]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->secondaryKeyElementId, &ptrBuf[16]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
#endif

#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
    /* PRQA S 0310, 3305 5 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */
  if ((Crypto_30_vHsm_KeyMIOAvailable[keyMJobPtr->action] & CRYPTO_30_VHSM_IO_INPUT) == CRYPTO_30_VHSM_IO_INPUT)
  {
    ptrMask = ((uint32)1u << CRYPTO_30_VHSM_PTRMSK_INPUTS);
#endif

    /* #10 Serialization of inputPtr */
    retVal = Crypto_30_vHsm_SerializeInputPtr( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE */
      jobRequestId,
      keyMJobPtr->inputOutput.inputPtr,
      keyMJobPtr->inputOutput.inputLength,
      &ptrBuf[offset],
      FALSE);
    offset += 8u;

#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  }

  if ((Crypto_30_vHsm_KeyMIOAvailable[keyMJobPtr->action] & CRYPTO_30_VHSM_IO_OUTPUT) == CRYPTO_30_VHSM_IO_OUTPUT)
  {
    ptrMask |= ((uint32)1u << CRYPTO_30_VHSM_PTRMSK_OUTPUTS);
#endif
    /* #20 Serialization of outputPtr */
    Crypto_30_vHsm_SerializeOutputPtr( /* SBSW_CRYPTO_30_VHSM_CALL_SERIALIZE */
      jobRequestId,
      keyMJobPtr->inputOutput.outputPtr,
      keyMJobPtr->inputOutput.outputLengthPtr,
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
      Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId),
#endif
      &ptrBuf[offset],
      &Crypto_30_vHsm_GetOutputOffsetOfJobRequest(jobRequestId));
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
    offset += 8u;
  }
#endif

#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->cryptoKeyId, &ptrBuf[offset]);/* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  offset += 4u;
  if ((Crypto_30_vHsm_KeyMIOAvailable[keyMJobPtr->action] & CRYPTO_30_VHSM_IO_SECONDARYKEY) == CRYPTO_30_VHSM_IO_SECONDARYKEY)
  {
    Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->secondaryCryptoKeyId, &ptrBuf[offset]);/* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    offset += 4u;
    numOfKeys++;
  }

  /* PRQA S 0310, 3305 2 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->action, &ptrBuf[offset]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->keyElementId, &ptrBuf[offset + 4u]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->secondaryKeyElementId, &ptrBuf[offset + 8u]);/* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  numOfConst = 3;
  if ((Crypto_30_vHsm_KeyMIOAvailable[keyMJobPtr->action] & CRYPTO_30_VHSM_IO_COPYPARTIAL) == CRYPTO_30_VHSM_IO_COPYPARTIAL)
  {
    /* PRQA S 0310, 3305 3 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */
    Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->inputOutput.keyElementSourceOffset, &ptrBuf[offset + 12u]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->inputOutput.keyElementTargetOffset, &ptrBuf[offset + 16u]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->inputOutput.keyElementCopyLength, &ptrBuf[offset + 20u]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
    numOfConst = 6;
  }

  ptrMask |= ((uint32)numOfKeys << CRYPTO_30_VHSM_PTRMSK_KEYS) | numOfConst;

  Crypto_30_vHsm_Serialize_Uint32(ptrMask, &ptrBuf[0]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  /* Serialize invalid service pattern */
  Crypto_30_vHsm_Serialize_Uint32(0xFFFFFFFFuL, &ptrBuf[4u]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
#endif

  /*
   * Hint: If one of the above functions return E_NOT_OK, it is presumably the case that the provided key data is to big to be buffered.
   *       Try increasing the buffer size of CryptoDriverObjects/Crypto_30_vHsm_KeyM/CryptovHsmBuffer/CryptoInputBufferSize
   */
  return retVal;
}

#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_KeyMJob_CopyPartial()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_KeyMJob_CopyPartial(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId, /* PRQA S 3206 */ /* MD_CRYPTO_30_VHSM_UNUSED_PARAMETER */
  P2CONST(Crypto_30_vHsm_KeyM_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) keyMJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf)
{
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
    /* PRQA S 0310, 3305 8 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->action, ptrBuf); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->cryptoKeyId, &ptrBuf[4]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->secondaryCryptoKeyId, &ptrBuf[8]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->keyElementId, &ptrBuf[12]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->secondaryKeyElementId, &ptrBuf[16]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->inputOutput.keyElementSourceOffset, &ptrBuf[20]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->inputOutput.keyElementTargetOffset, &ptrBuf[24]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(keyMJobPtr->inputOutput.keyElementCopyLength, &ptrBuf[28]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

  retVal = E_OK;

  CRYPTO_30_VHSM_DUMMY_STATEMENT(jobRequestId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}

# if (CRYPTO_30_VHSM_KEY_DERIVE_JOB_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_SerializeRequest_CryptoJob_KeyDerive()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_SerializeRequest_CryptoJob_KeyDerive(
  Crypto_30_vHsm_JobRequestIterType  jobRequestId, /* PRQA S 3206 */ /* MD_CRYPTO_30_VHSM_UNUSED_PARAMETER */
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) cryptoJobPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) ptrBuf)
{
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  Crypto_30_vHsm_Serialize_Uint32(Crypto_30_vHsm_GetJobStateOfJobRequest(jobRequestId), ptrBuf); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

  /* #10 Serialization of key derive job */
  /* PRQA S 0310, 3305 8 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.mode, &ptrBuf[4]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.family, &ptrBuf[8]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.mode, &ptrBuf[12]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily, &ptrBuf[16]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(Crypto_30_vHsm_GetProcessingTypeOfJobRequest(jobRequestId), &ptrBuf[20]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->jobInfo->jobId, &ptrBuf[24]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->targetCryptoKeyId, &ptrBuf[28]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */
  Crypto_30_vHsm_Serialize_Uint32(cryptoJobPtr->cryptoKeyId, &ptrBuf[32]); /* SBSW_CRYPTO_30_VHSM_IPC_SERIALIZE_UINT32 */

  retVal = E_OK;

  return retVal;
}
# endif
#endif

/**********************************************************************************************************************
 *  Crypto_30_vHsm_ReceiveResponse_CryptoJob()
 *********************************************************************************************************************/
/*!
 *
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
FUNC( void, CRYPTO_30_VHSM_CODE ) Crypto_30_vHsm_ReceiveResponse_CryptoJob(
  Crypto_30_vHsm_JobRequestIterType jobRequestId,
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  uint32 jobResponseData,
#endif
  Crypto_30_vHsm_JobResponseBufferPtrType jobResponseBuffer) /* PRQA S 3673 */ /* MD_CRYPTO_30_VHSM_3673_API_SPECIFIC */
{
  /* ----- Local Variables ---------------------------------------------- */
  Crypto_30_vHsm_CryptoJobPtr jobTmp; /* PRQA S 3679 */ /* MD_CRYPTO_30_VHSM_3679_JOB_POINTER_AS_VAR */
  Std_ReturnType jobResult;

  /* ----- Implementation ----------------------------------------------- */
  jobTmp = Crypto_30_vHsm_GetCryptoJobOfJobRequest(jobRequestId);

  /* #20 Deserialize job request */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
  Crypto_30_vHsm_GetJobStateOfJobRequest(jobRequestId) = (Crypto_JobStateType)Crypto_30_vHsm_Deserialize_Uint32(&jobResponseBuffer[4]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */ /* SBSW_CRYPTO_30_VHSM_STACK_VARIABLE_AS_PTR_WITH_BUFFER */
  jobResult = (uint8)Crypto_30_vHsm_Deserialize_Uint32(&jobResponseBuffer[8]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */
  Crypto_30_vHsm_SetResultOfJobRequest(jobRequestId, jobResult); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
#else
  *Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId) = Crypto_30_vHsm_Deserialize_Uint32(jobResponseBuffer); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
  *Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(jobRequestId) = Crypto_30_vHsm_Deserialize_Uint32(&jobResponseBuffer[4]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
  *Crypto_30_vHsm_GetAddrVerifyPtrDataBuffer(jobRequestId) = (Crypto_VerifyResultType)Crypto_30_vHsm_Deserialize_Uint32(&jobResponseBuffer[8]); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
  Crypto_30_vHsm_SetJobStateOfJobRequest(jobRequestId, (uint8)(jobResponseData >> CRYPTO_30_VHSM_JOBRESPONSE_STATE_BITPOSITION)); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
  jobResult = (uint8)(jobResponseData >> CRYPTO_30_VHSM_JOBRESPONSE_RESULT_BITPOSITION);
  Crypto_30_vHsm_SetResultOfJobRequest(jobRequestId, jobResult); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
#endif

  /* #30 Get result of job request */
  /* Info: If the job result was CRYPTO_E_SMALL_BUFFER although a big enough buffer has been provided by the application, make sure that the shared buffer of the driver object is configured big enough.
   * It may have been the case that the application provided a buffer not readable by the vHsm. The CRYPTO driver then provides a valid buffer which may be smaller than the original one to the vHsm.
   */
  if (E_OK == jobResult)
  {
    /* Check if the job contains an output */
    if ((Crypto_30_vHsm_JobIOAvailable[jobTmp->jobPrimitiveInfo->primitiveInfo->service] & CRYPTO_30_VHSM_IO_OUTPUT) == CRYPTO_30_VHSM_IO_OUTPUT)
    {
      if ((jobTmp->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr != NULL_PTR)
        && (jobTmp->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr != NULL_PTR))
      {
#if (CRYPTO_30_VHSM_READWRITE_AVAILABLE == STD_ON)
        /* Check if the vHsm has written the output to the buffer instead of the original pointer provided within the job */
        if (Crypto_30_vHsm_GetOutputOffsetOfJobRequest(jobRequestId) != CRYPTO_30_VHSM_OUTPUT_BUFFER_NOT_USED)
#else
# if (CRYPTO_30_VHSM_NOBUFFERING_ENABLED == STD_ON)
        if (Crypto_30_vHsm_IsBufferUsedOfObjectInfo(jobRequestId) == TRUE)
# endif
#endif
        {
          /* Check if the vHsm produced a bigger result than the buffer provided by the application */
          if (*Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId) > *jobTmp->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr)
          {
            /* Set the length to a safe value to avoid memory corruptions. This should never happen and indicates a wrong behaviour of the vHsm Firmware. */
            *Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId) = 0u; /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
            Crypto_30_vHsm_SetResultOfJobRequest(jobRequestId, E_NOT_OK); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
          }
          else
          {
            /* #40 Copy output to local job object */
            VStdLib_MemCpy(jobTmp->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, Crypto_30_vHsm_GetAddrSharedDataBufferOfDriverObject(jobRequestId, Crypto_30_vHsm_GetOutputOffsetOfJobRequest(jobRequestId)), *Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_VHSM_COPY_TO_DESTINATION_FROM_GLOBAL_BUFFER */
          }
        }
        /* Copy the length value to the original destination provided within the job */
        *jobTmp->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = *Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId); /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
      }

      /* Check if the job contains a secondary output */
      /* This will only be the case when a primary output is available. There are no jobs with a secondary output but no primary output. */
      if (((Crypto_30_vHsm_JobIOAvailable[jobTmp->jobPrimitiveInfo->primitiveInfo->service] & CRYPTO_30_VHSM_IO_SECONDARYOUTPUT) == CRYPTO_30_VHSM_IO_SECONDARYOUTPUT)
        && (jobTmp->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryOutputLengthPtr != NULL_PTR)
        && (jobTmp->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryOutputPtr != NULL_PTR))
      {
#if (CRYPTO_30_VHSM_READWRITE_AVAILABLE == STD_ON)
        /* Check if the vHsm has written the output to the buffer instead of the original pointer provided within the job */
        if (Crypto_30_vHsm_GetSecondaryOutputOffsetOfJobRequest(jobRequestId) != CRYPTO_30_VHSM_OUTPUT_BUFFER_NOT_USED)
#else
# if (CRYPTO_30_VHSM_NOBUFFERING_ENABLED == STD_ON)
        if (Crypto_30_vHsm_IsBufferUsedOfObjectInfo(jobRequestId) == TRUE)
# endif
#endif
        {
          /* Check if the vHsm produced a bigger result than the buffer provided by the application */
          if (*Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(jobRequestId) > *jobTmp->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryOutputLengthPtr)
          {
            /* Set the length to a safe value to avoid memory corruptions. This should never happen and indicates a wrong behaviour of the vHsm Firmware. */
            *Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(jobRequestId) = 0u; /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
            Crypto_30_vHsm_SetResultOfJobRequest(jobRequestId, E_NOT_OK); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
          }
          else
          {
            /* #50 Copy secondary output to local job object */
            VStdLib_MemCpy(jobTmp->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryOutputPtr, Crypto_30_vHsm_GetAddrSharedDataBufferOfDriverObject(jobRequestId, Crypto_30_vHsm_GetSecondaryOutputOffsetOfJobRequest(jobRequestId)), *Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(jobRequestId)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_VHSM_COPY_TO_DESTINATION_FROM_GLOBAL_BUFFER */
          }
        }
        /* Copy the length value to the original destination provided within the job */
        *jobTmp->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.secondaryOutputLengthPtr = *Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(jobRequestId); /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
      }
    }

    /* Check if the default value has been overwritten which would indicate that the received value must be written to the provided verifyPtr */
    if (*Crypto_30_vHsm_GetAddrVerifyPtrDataBuffer(jobRequestId) != 0xFEu)
    {
      if (jobTmp->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.verifyPtr != NULL_PTR)
      {
        /* #60 Copy verification pointer to local job object */
        *jobTmp->CRYPTO_30_VHSM_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.verifyPtr = *Crypto_30_vHsm_GetAddrVerifyPtrDataBuffer(jobRequestId); /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
      }
      else
      {
        Crypto_30_vHsm_SetResultOfJobRequest(jobRequestId, E_NOT_OK); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
#if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
        (void)Det_ReportError(CRYPTO_30_VHSM_MODULE_ID, CRYPTO_30_VHSM_INSTANCE_ID, CRYPTO_30_VHSM_SID_PROCESS_JOB, CRYPTO_E_PARAM_POINTER);
#endif
      }
    }
  }
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* #70 Check for buffer replacement error */
    Crypto_30_vHsm_CheckBufferReplacementError(jobRequestId, jobResult, CRYPTO_E_SMALL_BUFFER);
  }
#endif
} /* PRQA S 6030, 6080 */ /* MD_MSR_STMIF */ /* MD_MSR_STCYC */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_ReceiveResponse_KeyMJob()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC( void, CRYPTO_30_VHSM_CODE ) Crypto_30_vHsm_ReceiveResponse_KeyMJob(
  Crypto_30_vHsm_JobRequestIterType jobRequestId,
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
  uint32 jobResponseData,
#endif
  Crypto_30_vHsm_JobResponseBufferPtrType jobResponseBuffer) /* PRQA S 3673 */ /* MD_CRYPTO_30_VHSM_3673_API_SPECIFIC */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType jobResult;
  Crypto_30_vHsm_KeyMJobPtr jobTmp; /* PRQA S 3679 */ /* MD_CRYPTO_30_VHSM_3679_JOB_POINTER_AS_VAR */

  /* ----- Implementation ----------------------------------------------- */

  /* #20 Deserialize job request */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 2u)
  jobResult = (uint8)Crypto_30_vHsm_Deserialize_Uint32(jobResponseBuffer); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */
  Crypto_30_vHsm_SetResultOfJobRequest(jobRequestId, jobResult);/* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
#else
  *Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId) = Crypto_30_vHsm_Deserialize_Uint32(jobResponseBuffer); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_VHSM_SERIALIZATION_MACRO */ /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
  jobResult = (uint8)(jobResponseData >> CRYPTO_30_VHSM_JOBRESPONSE_RESULT_BITPOSITION);
  Crypto_30_vHsm_SetResultOfJobRequest(jobRequestId, jobResult); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
#endif

  /* Copy the data only from the buffer to the destination if the job was successful */
  if (E_OK == jobResult)
  {
    jobTmp = Crypto_30_vHsm_GetKeyMJobOfJobRequest(jobRequestId);

    /* Check if the job contains an output */
#if (CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3u)
    if (((Crypto_30_vHsm_KeyMIOAvailable[jobTmp->action] & CRYPTO_30_VHSM_IO_OUTPUT) == CRYPTO_30_VHSM_IO_OUTPUT) &&
#else
    if(
#endif
      (jobTmp->inputOutput.outputLengthPtr != NULL_PTR)
      && (jobTmp->inputOutput.outputPtr != NULL_PTR))
    {
#if (CRYPTO_30_VHSM_READWRITE_AVAILABLE == STD_ON)
      /* Check if the vHsm has written the output to the buffer instead of the original pointer provided within the job */
      if (Crypto_30_vHsm_GetOutputOffsetOfJobRequest(jobRequestId) != CRYPTO_30_VHSM_OUTPUT_BUFFER_NOT_USED)
#endif
      {
        /* Check if the vHsm produced a bigger result than the buffer provided by the application */
        if (*Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId) > *jobTmp->inputOutput.outputLengthPtr)
        {
          /* Set the length to a safe value to avoid memory corruptions. This should never happen and indicates a wrong behaviour of the vHsm Firmware. */
          *Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId) = 0u; /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
          Crypto_30_vHsm_SetResultOfJobRequest(jobRequestId, E_NOT_OK); /* SBSW_CRYPTO_30_VHSM_CSL02_OBJECTINFO */
        }
        else
        {
          /* #30 Copy output to local job object */
          VStdLib_MemCpy(jobTmp->inputOutput.outputPtr, Crypto_30_vHsm_GetAddrSharedDataBufferOfDriverObject(jobRequestId, Crypto_30_vHsm_GetOutputOffsetOfJobRequest(jobRequestId)), *Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId));  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_VHSM_COPY_TO_DESTINATION_FROM_GLOBAL_BUFFER */
        }
      }
      /* Copy the length value to the original destination provided within the job */
      *jobTmp->inputOutput.outputLengthPtr = *Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(jobRequestId); /* SBSW_CRYPTO_30_VHSM_PTR_ACCESS_WITH_DET_CHECK */
    }
  }
#if (CRYPTO_30_VHSM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* #70 Check for buffer replacement error */
    Crypto_30_vHsm_CheckBufferReplacementError(jobRequestId, jobResult, CRYPTO_E_KEY_SIZE_MISMATCH);
  }
#endif
}

#define CRYPTO_30_VHSM_STOP_SEC_CODE
#include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Jobs.c
 *********************************************************************************************************************/

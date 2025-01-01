/**********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Ssa_Utils.h
 *        \brief  Defines common elements used in multiple software components of the SSA.
 *      \details  Everything defined here should never be used outside of the SSA component.
 **********************************************************************************************************************/

/*********************************************************************************************************************
 *  REVISION HISTORY
 *  ------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (SSA_UTILS_H)
# define SSA_UTILS_H

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Compiler.h"
# include "Compiler_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/* ----- States for asynchronous CSM call handling ----- */
# define SSA_ASYNC_STATE_IDLE                                         ( 0u)
# define SSA_ASYNC_STATE_WAIT                                         ( 1u)
# define SSA_ASYNC_STATE_READY                                        ( 2u)
# define SSA_ASYNC_STATE_FAILED                                       ( 3u)

/* ----- Return codes used for asynchronous CSM handling ----- */
# define SSA_E_PENDING                                                ( 2u)
# define SSA_E_INVALID                                                ( 3u)

/* ----- CSM error codes ----- */
# define SSA_CRYPTO_E_BUSY                                            ( 2u)
# define SSA_CRYPTO_E_QUEUE_FULL                                      ( 5u)
# define SSA_CRYPTO_E_JOB_CANCELED                                    (12u)

/* ----- Chain of trust related key pairs ----- */
# define SSA_DIAGNOSTIC_KEY_PAIR                                      ( 0u)
# define SSA_TRUST_MODEL_LIVE_KEY_PAIR                                ( 1u)
# define SSA_TRUST_MODEL_CSR_KEY_PAIR                                 ( 2u)
# define SSA_TRUST_MODEL_LIVE_PUBLIC_KEY_AND_CSR_PRIVATE_KEY          ( 3u)
# define SSA_TRUST_MODEL_LIVE_BACKEND_PUBLIC_KEY                      ( 4u)

/*! Tasks and configuration for diagnostic routine control service Authenticate Diagnostic User or Tester */
# define SSA_AUTHENTICATE_INITIATE_AUTH_TASK                          (0x00u)
# define SSA_AUTHENTICATE_PROOF_OF_OWNERSHIP_TASK                     (0x01u)
# define SSA_AUTHENTICATE_DEAUTH_TASK                                 (0x02u)

# define SSA_AUTHENTICATE_UNIDIRECTIONAL_AUTHETICATION_CONFIGURATION  (0x00u)
# define SSA_AUTHENTICATE_S29_SUB_PROCESSING_ACTIVE_CONFIGURATION     (0x80u) /**< Indicating from ProcCtrl to RightsM that S29 sub-processing is active for memory usage optimization */

/*! Successful diagnostic service execution events UIDs */
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_REPLACE_CERTIFICATES                                                   (0x00u)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_ACTIVATE_DEBUGGING_INTERFACES                                          (0x01u)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_ERASE_MEMORY                                                           (0x02u)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_CLEAR_SAR_MEMORY                                                       (0x03u)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_RESERVERD_0X04                                                         (0x04u)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_SECOC_VEHICLE_SHARED_SECRET_DISTRIBUTION                               (0x05u)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_SECOC_ECU_SHARED_SECRET_ENCRYPTION                                     (0x06u)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_SECOC_ECU_SHARED_SECRET_DISTRIBUTION                                   (0x07u)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_SECOC_VSM_RENEW_SHARED_SECRET                                          (0x08u)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_SECOC_VSM_DERIVE_SYMMETRIC_KEYS                                        (0x09u)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_REPLACE_TRUST_MODEL_CERTIFICATES                                       (0x0Au)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_REPLACE_TRUST_MODEL_ROOT_CERTIFICATE                                   (0x0Bu)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_TRUST_MODEL_SECOC_ECU_SHARED_SECRET_ENCRYPTION                         (0x0Cu)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_TRUST_MODEL_SECOC_ECU_SHARED_SECRET_DISTRIBUTION                       (0x0Du)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_RESERVERD_0X0E                                                         (0x0Eu)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_TRUST_MODEL_SECOC_ECU_TICKCOUNT_SYNCHRONIZATION                        (0x0Fu)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_TRUST_MODEL_GENERATE_KEY_PAIR                                          (0x10u)
# define SSA_SECLOG_SUCDIAGEXECEVENT_UID_INJECT_SEED                                                            (0x11u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/* Clear data */
# define Ssa_Utils_MemClr(Data, DataSize)                             Ssa_Utils_MemSet((Data), 0x00u, (DataSize)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Builds an uint16 value from two bytes. */
# define Ssa_GetUint16(hiByte, loByte)                                ((uint16)((((uint16)(hiByte)) << 8u) | ((uint16)(loByte))))  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Ssa_GetUint16HiByte( value )                                 ((uint8)(((uint16)(value)) >> 8u))                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Ssa_GetUint16LoByte( value )                                 ((uint8)(((uint16)(value)) & 0xFFu))                 /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Writes an uint16 value to two bytes. */
# define Ssa_SetUint16(addr, value)                                   do { \
                                                                      addr[0] = Ssa_GetUint16HiByte((uint16)(value)); \
                                                                      addr[1] = Ssa_GetUint16LoByte((uint16)(value)); \
                                                                      } while (0)

/* compile time assertions */
#if !defined (Ssa_CompileTimeAssert)             /* COV_SSA_LOCAL_INLINE */
# define Ssa_CompileTimeAssert(cond, desc)                       typedef uint8 desc[(cond) ? 1 : 0] /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# define Ssa_Cdd_START_SEC_CODE
# include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Ssa_AsyncPreAction()
 **********************************************************************************************************************/
/*! \brief         Decides whether or not an asynchronous service call should be performed.
 *  \details       -
 *  \param[in,out] state         pointer to the state variable for the asynchronous call. Must be a valid pointer.
 *  \param[in]     isAsync       flag indicating whether the call is asynchronous or not
 *  \return        E_OK          if the action should be performed
 *                 SSA_E_PENDING if the action should not be performed - Ssa_AsyncFinalize() should be called
 *                               immediately afterwards
 *  \pre           To be called in combination with Ssa_AsyncPostAction() and Ssa_AsyncFinalize()
 *  \context       ANY
 *  \reentrant     TRUE for different pointees "state"
 *  \synchronous   TRUE
 *  \spec          requires state != NULL_PTR;                                                                  \endspec
 **********************************************************************************************************************/
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_AsyncPreAction(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) state,
  boolean isAsync);

/**********************************************************************************************************************
 *  Ssa_AsyncPostAction()
 **********************************************************************************************************************/
/*! \brief         Evaluates the asynchronous action's return code and manipulates the state according to it.
 *  \details       Call this function immediately after performing the asynchronous service call.
 *  \param[out]    state              pointer to the state variable for the asynchronous call. Must be a valid pointer.
 *  \param[in]     previouslyReturned return value of the previous step of the asynchronous call
 *  \param[in]     isAsync            flag indicating whether the call is asynchronous or not
 *  \pre           To be called in combination with Ssa_AsyncPreAction() and Ssa_AsyncFinalize()
 *  \context       ANY
 *  \reentrant     TRUE for different pointees "state"
 *  \synchronous   TRUE
 *  \spec          requires state != NULL_PTR;                                                                  \endspec
 **********************************************************************************************************************/
FUNC(void, Ssa_Cdd_CODE) Ssa_AsyncPostAction(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) state,
  Std_ReturnType previouslyReturned,
  boolean isAsync);

/**********************************************************************************************************************
 *  Ssa_AsyncFinalize()
 **********************************************************************************************************************/
/*! \brief         Checks whether asynchronous callbacks have occurred and manipulates the state accordingly.
 *  \details       Call this any time you want to check on the status of an ongoing asynchronous operation.
 *  \param[in,out] state    pointer to the state variable for the asynchronous call. Must be a valid pointer.
 *  \param[in]     isAsync  flag indicating whether the call is asynchronous or not
 *  \return        E_OK     if the asynchronous operation has finished successfully
 *                 E_NOT_OK if the asynchronous operation has failed
 *                 previouslyReturned else
 *  \pre           To be called in combination with Ssa_AsyncPreAction() and Ssa_AsyncPostAction()
 *  \context       ANY
 *  \reentrant     TRUE for different pointees "state"
 *  \synchronous   TRUE
 *  \spec          requires state != NULL_PTR;                                                                  \endspec
 **********************************************************************************************************************/
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_AsyncFinalize(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) state,
  boolean isAsync);

/**********************************************************************************************************************
 *  Ssa_Utils_ConvertSerialNumber()
 **********************************************************************************************************************/
/*!
 * \brief       Convert serial number.
 * \details     Convert serial number with leading zeros. This function allows inplace conversion.
 * \param[in]   serialNumber_in         Raw serial number.
 * \param[in]   serialNumberLength_in   Length of the raw serial number.
 * \param[out]  serialNumber_out        Buffer to store the serial number.
 * \param[in]   serialNumberLength_out  Length of buffer to store the serial number.
 * \return      E_OK      Serial number successfully extracted.
 *              E_NOT_OK  Serial number could not get since to long for provided buffer.
 * \pre         Pointers must be valid.
 *              The buffer referenced by serialNumber_out must provide at least serialNumberLength_out many bytes.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 * \spec        requires serialNumber_out != NULL_PTR;
 *              requires $lengthOf(serialNumber_out) >= serialNumberLength_out;                                 \endspec
 **********************************************************************************************************************/
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Utils_ConvertSerialNumber(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) serialNumber_in,
  uint16 serialNumberLength_in,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) serialNumber_out,
  uint16 serialNumberLength_out);

/**********************************************************************************************************************
 * Ssa_Utils_MemSet()
 *********************************************************************************************************************/
/*!
 * \brief       Sets each byte of the target data buffer to the given data value.
 * \details     -
 * \param[out]  targetDataBuf  Memory address of the target data buffer.
 * \param[in]   data           The value that shall be set.
 * \param[in]   dataLength     The number of bytes of the target buffer that shall be set.
 * \pre         targetDataBuf must be a valid pointer.
 *              The buffer referenced by targetDataBuf must provide at least dataLength many bytes.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 * \spec        requires targetDataBuf != NULL_PTR;
 *              requires $lengthOf(targetDataBuf) >= dataLength;                                                \endspec
 **********************************************************************************************************************/
FUNC(void, Ssa_Cdd_CODE) Ssa_Utils_MemSet(
  P2VAR(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_VAR) targetDataBuf,
  uint8 data,
  uint16_least dataLength);

/**********************************************************************************************************************
 * Ssa_Utils_MemCpy()
 *********************************************************************************************************************/
/*!
 * \brief       Copies data from one memory location to another memory location.
 * \details     -
 * \param[out]  targetBuf  Memory location where the data shall be copied to.
 * \param[in]   dataBuf    Memory location where the data shall be copied from.
 * \param[in]   dataLength Number of bytes to be copied.
 * \pre         Pointers must be valid.
 *              The buffer referenced by targetBuf must provide at least dataLength many bytes.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 * \spec        requires targetBuf != NULL_PTR;
 *              requires $lengthOf(targetBuf) >= dataLength;                                                    \endspec
 **********************************************************************************************************************/
FUNC(void, Ssa_Cdd_CODE) Ssa_Utils_MemCpy(
  P2VAR(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_VAR) targetBuf,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) dataBuf,
  uint32_least dataLength);

/**********************************************************************************************************************
 *  Ssa_Utils_MemCpy32()
 *********************************************************************************************************************/
/*!
 * \brief       Copies data.
 * \details     -
 * \param[out]  destination A pointer to the memory location where the data shall be copied to.
 * \param[in]   source      A pointer to the memory location where the data shall be read from.
 * \param[in]   num         Number of bytes that shall be copied.
 * \pre         Pointers must be valid.
 *              The destination pointer must point to a data buffer of size given by parameter num.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 * \spec        requires destination != NULL_PTR;
 *              requires $lengthOf(destination) >= num;                                                         \endspec
 **********************************************************************************************************************/
FUNC(void, Ssa_Cdd_CODE) Ssa_Utils_MemCpy32(
  P2VAR(void, AUTOMATIC, RTE_SSA_CDD_APPL_VAR) destination,
  P2CONST(void, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) source,
  uint32_least num);

/**********************************************************************************************************************
 *  Ssa_Utils_MemCmp()
 **********************************************************************************************************************/
/*!
 * \brief       Compares two data buffers byte-by-byte.
 * \details     -
 * \param[in]   data1       First data buffer.
 * \param[in]   data2       Second data buffer.
 * \param[in]   dataLength  Number bytes to be compared.
 * \return      TRUE   The data buffers are of same contents.
 *              FALSE  The data buffers are of different contents.
 * \pre         Pointers must be valid.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 **********************************************************************************************************************/
FUNC(boolean, Ssa_Cdd_CODE) Ssa_Utils_MemCmp(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) data1,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) data2,
  uint16 dataLength);

/**********************************************************************************************************************
*  Ssa_Utils_MemCmp_WithLengths()
**********************************************************************************************************************/
/*!
* \brief       Compares two data buffers byte-by-byte.
* \details     -
* \param[in]   data1       First data buffer.
* \param[in]   data2       Second data buffer.
* \param[in]   dataLength1  Length of first data buffer.
* \param[in]   dataLength2  Length of second data buffer.
* \return      TRUE   The data buffers are of same length and have the same contents.
*              FALSE  The data buffers are of different lengths or have different contents.
* \pre         Pointers must be valid.
* \context     ANY
* \reentrant   TRUE
* \synchronous TRUE
**********************************************************************************************************************/
FUNC(boolean, Ssa_Cdd_CODE) Ssa_Utils_MemCmp_WithLengths(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) data1,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) data2,
  uint16 dataLength1,
  uint32 dataLength2);

# define Ssa_Cdd_STOP_SEC_CODE
# include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SSA_UTILS_H */

/**********************************************************************************************************************
 *  END OF FILE: Ssa_Utils.h
 **********************************************************************************************************************/

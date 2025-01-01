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
/*!        \file  KeyM_Utils.h
 *         \unit  *
 *        \brief  Source header file for common utility functions
 *      \details  Implementation AUTOSAR Key Manager
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined KEYM_UTILS_H
# define KEYM_UTILS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "KeyM_Cfg.h"
# include "vstdlib.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
# ifndef KEYM_UTILS_LOCAL_INLINE                        /* COV_KEYM_LOCAL_DEFINE */
#  ifndef KEYM_NOUNIT_UTILS                             /* COV_KEYM_UNITTEST_DEFINE */
#   define KEYM_UTILS_LOCAL_INLINE                                    static INLINE        /* "static" cannot legally be disabled here */
#  else
#   define KEYM_UTILS_LOCAL_INLINE                                    /* make sure that util functions can be mocked */
#  endif
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
# define KeyM_SizeOfArray(arr)                                        (sizeof(arr) / sizeof((arr)[0]))

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define KEYM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * KeyM_Utils_MemCmp()
 *********************************************************************************************************************/
/*! \brief         Compares two buffers of equal length.
 *  \details       Returns TRUE if the buffers have the same contents.
 *  \param[in]     buffer1         Pointer to the first buffer.
 *  \param[in]     buffer2         Pointer to the second buffer.
 *  \param[in]     length          Length of the buffers.
 *  \return        TRUE            Buffers have the same contents.
 *                 FALSE           Buffers have different contents.
 *  \pre           buffer1 must point to an uint8 buffer with length length.
 *                 buffer2 must point to an uint8 buffer with length length.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_UTILS_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Utils_MemCmp(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) buffer1,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) buffer2,
  uint32 length);

/**********************************************************************************************************************
 * KeyM_Utils_BufferCmp()
 *********************************************************************************************************************/
/*! \brief         Compares two buffers.
 *  \details       Returns TRUE if the buffers are equal in length and contents.
 *  \param[in]     buffer1                              Pointer to the first buffer.
 *  \param[in]     buffer1Length                        Length of buffer1.
 *  \param[in]     buffer2                              Pointer to the second buffer.
 *  \param[in]     buffer2Length                        Length of buffer2.
 *  \return        TRUE                                 Buffers are of equal length and have the same contents.
 *                 FALSE                                Buffers differ in length and/or contents.
 *  \pre           buffer1 must point to an uint8 buffer with length buffer1Length.
 *                 buffer2 must point to an uint8 buffer with length buffer2Length.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_UTILS_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Utils_BufferCmp(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) buffer1,
  uint32 buffer1Length,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) buffer2,
  uint32 buffer2Length);

/**********************************************************************************************************************
 *  KeyM_Utils_ConvertUint8ArrayToUint16BigEndian()
 *********************************************************************************************************************/
/*! \brief       Converts the specified unsigned 8-bit array to a signed 16-bit value according to big endian format.
 *  \details     -
 *  \param[in]   src   Pointer to an unsigned 8-bit array, which shall be converted.
 *  \return      The conversion result (the converted uint16 value)
 *  \pre         The parameter 'src' has to point to an unsigned 8-bit array of at least two elements.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \spec        requires $lengthOf(src) >= 2;                                                                 \endspec
 *********************************************************************************************************************/
KEYM_UTILS_LOCAL_INLINE FUNC(uint16, KEYM_CODE) KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) src);

/**********************************************************************************************************************
 *  KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian()
 *********************************************************************************************************************/
/*! \brief       Converts the specified unsigned 16-bit value to an unsigned 8-bit array according to big endian format.
 *  \details     -
 *  \param[in]   src   The unsigned 16-bit value which shall be converted.
 *  \param[out]  dst   Pointer to an unsigned 8-bit array, where the conversion result will be stored.
 *  \pre         The parameter 'dst' has to point to an unsigned 8-bit array of at least two elements.
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \spec        requires $lengthOf(dst) >= 2;                                                                 \endspec
 *********************************************************************************************************************/
KEYM_UTILS_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(
  uint16 src,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) dst);

# if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Utils_IsLess()
 **********************************************************************************************************************/
/*! \brief       Checks if a given value is less than another.
 *  \details     -
 *  \param[in]   left   left hand side of the comparison.
 *  \param[in]   right  right hand side of the comparison.
 *  \return      TRUE   if left < right.
 *  \return      FALSE  else.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \note        This function was added for testability reasons. It can be stubbed in the test suite in order to enter
 *               control paths that would otherwise be unreachable in a correct configuration.
 *********************************************************************************************************************/
KEYM_UTILS_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Utils_IsLess(
    uint32 left,
    uint32 right);
# endif /* (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON) */

/**********************************************************************************************************************
 * KeyM_Utils_MemCpyWithSizeCheck()
 **********************************************************************************************************************/
/*! \brief         Copy data and check if provided output buffer is sufficiently large.
 *  \details       -
 *  \param[out]    pDst          Pointer to the memory location to copy to, must not be NULL.
 *  \param[in,out] pDstLen       In: Pointer to a value that contains the maximum data
 *                               length of the pDst buffer.
 *                               Out: The data length will be overwritten with the actual
 *                               length of data placed to the buffer if the function returns
 *                               E_OK.
 *  \param[in]     pSrc          Pointer to the memory location to copy from, must not be NULL.
 *  \param[in]     srcLen        Holds the input data length.
 *  \return        E_OK                                 Data is copied successfully.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided output buffer too small.
 *  \pre           All provided pointers must be valid.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_UTILS_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Utils_MemCpyWithSizeCheck(
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) pDst,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) pDstLen,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) pSrc,
  uint32 srcLen);

/* Declarations of VCA Stubs for customer-defined callouts */
# ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
FUNC(Std_ReturnType, KEYM_APPL_CODE) Vcastub_Appl_CertificateElementVerificationCallout(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertElementData, uint32 CertElementDataLength);
FUNC(void, KEYM_APPL_CODE) Vcastub_Appl_CertificateInitCallout(KeyM_CertificateIdType CertId, P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr);
FUNC(Std_ReturnType, KEYM_APPL_CODE) Vcastub_Appl_CertificateGetCurrentTimeCallout(KeyM_CertificateIdType CertId, P2VAR(uint64, AUTOMATIC, KEYM_APPL_VAR) timeStamp);
FUNC(Std_ReturnType, KEYM_RTE_CODE) Vcastub_Appl_ServiceCertificateRteCallbackNotification(KeyM_CertificateStatusType Result, uint16 ResultDataLength, P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) ResultDataPtr);
FUNC(Std_ReturnType, KEYM_RTE_CODE) Vcastub_Appl_CertificateVerifyRteCallbackNotification(KeyM_CertificateStatusType Result);
FUNC(void, KEYM_APPL_CODE) Vcastub_Appl_ServiceCertificateCallbackNotification(KeyM_CertificateIdType CertId, KeyM_CertificateStatusType Result, uint16 ResultDataLength, P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResultDataPtr);
FUNC(Std_ReturnType, KEYM_APPL_CODE) Vcastub_Appl_CertificateSetKeyCallout(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, uint32 csmKeyId, P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertElementData, uint32 CertElementDataLength);
FUNC(Std_ReturnType, KEYM_APPL_CODE) Vcastub_Appl_CertificateVerifyCallbackNotification(KeyM_CertificateIdType CertId, KeyM_CertificateStatusType Result);
FUNC(Std_ReturnType, KEYM_APPL_CODE) Vcastub_Appl_CertificateGroupVerifyCallbackNotification(KeyM_CertificateGroupIdType GroupId, KeyM_CertificateGroupStatusType Result);
# endif

# define KEYM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
# define KEYM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifndef KEYM_NOUNIT_UTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Utils_MemCmp()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_UTILS_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Utils_MemCmp(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) buffer1,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) buffer2,
  uint32 length)
{
  return VStdLib_MemCmp(buffer1, buffer2, (VStdLib_CntType)length) == 0; /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
}
# endif /* ifndef KEYM_NOUNIT_UTILS */

# ifndef KEYM_NOUNIT_UTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Utils_BufferCmp()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 3219 1 */  /* MD_MSR_Unreachable */
KEYM_UTILS_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Utils_BufferCmp(
    P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) buffer1,
    uint32 buffer1Length,
    P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) buffer2,
    uint32 buffer2Length)
{
  boolean isBufferEqual = buffer1Length == buffer2Length;

  if (isBufferEqual)
  {
    isBufferEqual = KeyM_Utils_MemCmp(buffer1, buffer2, buffer1Length);
  }

  return isBufferEqual;
}
# endif /* ifndef KEYM_NOUNIT_UTILS */

# ifndef KEYM_NOUNIT_UTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Utils_ConvertUint8ArrayToUint16BigEndian()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 3219 1 */  /* MD_MSR_Unreachable */
KEYM_UTILS_LOCAL_INLINE FUNC(uint16, KEYM_CODE) KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(
    P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) src)
{
  uint16 result;

  VStdLib_ConvertUint8ArrayToUint16BigEndian(src, &result);

  return result;
}
# endif /* ifndef KEYM_NOUNIT_UTILS */

# ifndef KEYM_NOUNIT_UTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */  /* MD_MSR_Unreachable */
KEYM_UTILS_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian(
    uint16 src,
    P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) dst)
{
  VStdLib_ConvertUint16ToUint8ArrayBigEndian(src, dst);
}
# endif /* ifndef KEYM_NOUNIT_UTILS */

# if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
#  ifndef KEYM_NOUNIT_UTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Utils_IsLess()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */  /* MD_MSR_Unreachable */
KEYM_UTILS_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_Utils_IsLess(
    uint32 left,
    uint32 right)
{
  return left < right;
}
#  endif /* ifndef KEYM_NOUNIT_UTILS */
# endif /* (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON) */

# ifndef KEYM_NOUNIT_UTILS /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Utils_MemCpyWithSizeCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 3219 1 */  /* MD_MSR_Unreachable */
KEYM_UTILS_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Utils_MemCpyWithSizeCheck(
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) pDst,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) pDstLen,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) pSrc,
  uint32 srcLen)
{
  Std_ReturnType retVal = E_OK;

  if(*pDstLen < srcLen)
  {
    retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
  }
  else
  {
    VStdLib_MemCpy(pDst, pSrc, srcLen); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    *pDstLen = srcLen;
  }

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_UTILS */

# define KEYM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* KEYM_UTILS_H */
/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/

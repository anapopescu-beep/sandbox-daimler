/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Ssa_CertP.c
 *        \brief  Certificate Parser of the Standard Security Architecture (Ssa).
 *
 *      \details  The Certificate Parser provides services to parse and verify certificates.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * CertP_PkiRoleType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * CertP_VerificationResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Crypto_OperationModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Crypto_VerifyResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Csm_KeyDataType_Ssa_SignatureRamKey
 *   Used as Buffer for service.
 *
 * Csm_ResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RightsM_DiagnosticUserRoleType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_KeyElementType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TimeM_CompareOperatorType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *
 * Port Prototypes:
 * ================
 * CallbackNotification_SignatureVerify
 *   Callback notification from the CSM signature verification job used for verifying the signature of certificates.
 *      Configuration Variant(s): Asynchronous job processing.
 *
 * Key_SignatureRamKey
 *   Sets a key just before the verification of a signature.
 *      Connect to a Csm Key which is able to store a signature key and is used in job of port CsmSignatureVerify.
 *      
 *
 *
 * Operation Prototypes:
 * =====================
 * KeyElementSet of Port Interface CsmKeyManagement_Ssa_SignatureRamKey
 *   Sets the given key element bytes to the key.
 *
 * KeySetValid of Port Interface CsmKeyManagement_Ssa_SignatureRamKey
 *   Sets the given key element bytes to the key.
 *
 *
 * Mode Declaration Groups:
 * ========================
 * Coding_MemoryStatus
 *   Notifies the Ssa of memory status changes while storing or restoring the Variant Coding Data to or from non-volatile memory.
 *
 * Coding_Mode
 *   Notifies application about an ongoing, successful or failed coding attempt.
 *
 * RightsM_AuthenticationMode
 *   RIGHTSM_AUTHENTICATED - A Tester was successfully authenticated
 *      RIGHTSM_UNAUTHENTICATED - No tester was authenticated
 *
 * Ssa_MacKeyGeneration_State
 *   Notifies application of whether the generation of the symmetric MAC keys is OFF or ON.
 *
 *
 * Runnable Entities:
 * ==================
 * Ssa_CertP_Certificate_Verify
 *   Verifies the certificate against issuer.
 *
 * Ssa_CertP_Certificate_Verify_Extended
 *   Verifies the certificate against issuer. Do additional checks, e.g. against ECU certificate.
 *
 * Ssa_CertP_CsmCallbackNotification_SignatureVerify
 *   Configuration Variant(s): Asynchronous job processing.
 *
 *********************************************************************************************************************/

#include "Rte_Ssa_CertP.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Ssa_Cfg.h"
#include "Ssa_Utils.h"

#ifdef __VCA__  /* COV_SSA_VECTOR_CODE_ANALYZER_STUB_REDIRECTION */
# include "Ssa_CertP_Redirection.vcaspecs.h"
#endif

/* After this comment only memory mapping files may be included. Due to this turn off lint rule requesting a standard
include guard. */
/*lint -e451 */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#if !defined (SSA_CERTP_LOCAL)                  /* COV_SSA_LOCAL */
# define SSA_CERTP_LOCAL                                              static
#endif

#if !defined (SSA_CERTP_LOCAL_INLINE)           /* COV_SSA_LOCAL_INLINE */
# define SSA_CERTP_LOCAL_INLINE                                       LOCAL_INLINE
#endif

/*! CertP BER parser error codes- */
#define CERTP_BER_E_PENDING                                           (0x82u)
#define CERTP_BER_E_MEM                                               (0x83u)
#define CERTP_BER_E_BER_PARAM                                         (0x84u)

/*! ASN1 TAG definitions. */
#define CERTP_ASN1_TAG_INTEGER                                        (0x02u)
#define CERTP_ASN1_TAG_BIT_STRING                                     (0x03u)
#define CERTP_ASN1_TAG_OCTET_STRING                                   (0x04u)
#define CERTP_ASN1_TAG_OBJECT_IDENTIFIER                              (0x06u)
#define CERTP_ASN1_TAG_UTF8_STRING                                    (0x0Cu)
#define CERTP_ASN1_TAG_UTC_TIME                                       (0x17u)
#define CERTP_ASN1_TAG_GENERALIZED_TIME                               (0x18u)
#define CERTP_ASN1_TAG_SEQUENCE                                       (0x30u)
#define CERTP_ASN1_TAG_CONTEXT_STRUCT_3                               (0xA3u)

/*! ASN1 length values */
#define CERTP_ASN1_UTC_TIME_LENGTH                                    (13u)
#define CERTP_ASN1_GENERALIZED_TIME_LENGTH                            (15u)

/*! CertP_Certificate_Verify_Runnable_State states. */
#define CERTP_ASYNC_STATE_IDLE                                        (0u)
#define CERTP_ASYNC_STATE_VERIFY                                      (1u)

/*! CertP_ParseExtension_UpdateRole expected difference between element end index and element content index */
#define CERTP_EXPECTED_ELEMENT_LENGTH                                 (1u)

/*! Maximal depth of one element. */
#define CERTP_MAX_DEPTH_OF_ONE_ELEMENT                                (5u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#define CertP_BerIsPrimitive(tag)                                     (0x00u == (0x20u & (tag)))             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CertP_BerIsOctetString(tag)                                   ((tag) == CERTP_ASN1_TAG_OCTET_STRING) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CERTP_BER_IS_EXTENDED_LEN(len)                                (0x80u & (len))                        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* The following compile time assertions ensure the sizes of data types used within the CertP submodule
 * when calling RTE APIs expecting these data types. 
 * The assertions ensure that the size of these data types is consistent with respective buffer lengths defined in the Ssa.
 * For ASIL-D, the vector code analyzer checks the same conditions within the CertP_Init() function. */
/* PRQA S 3205, 3493 1 */ /* MD_SSA_COMPILE_TIME_ASSERTION */
Ssa_CompileTimeAssert(sizeof(Coding_VINDataType) == 17u, InvalidSizeOf_Coding_VINDataType); /*lint !e506 */

/*! BER parser block structure. */
typedef struct
{
  uint32 Idx;
  uint32 EndIdx;
} CertP_BerBlockType;

/*! BER parser base element structure. */
typedef struct
{
  uint32 ContentIdx;
  uint32 EndIdx;
  uint32 Idx;
  uint8 Type;
} CertP_BaseBerElementType;

/*! BER parser stack element structure. */
typedef struct
{
  uint32 CurrentIdx;
  CertP_BerBlockType CurrentBlock;
  CertP_BaseBerElementType CurrentElement;
  uint8 CurrentElementNr;
} CertP_BerStackElementType;

/*! BER parser workspace structure. */
typedef struct
{
  uint32 LastDataSize;
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) LastData;
  P2VAR(CertP_BerStackElementType, AUTOMATIC, AUTOMATIC) Stack;
  uint8 CurrentDepth;
  uint8 MaxDepth;
} CertP_BerWorkspaceType;

/**********************************************************************************************************************
 *  LOCAL DATA DEFINITIONS
 *********************************************************************************************************************/
#define Ssa_CertP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_CertP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Variable for asynchronous state handling in function Ssa_CertP_Certificate_Verify(). */
SSA_CERTP_LOCAL VAR(uint8, Ssa_CertP_VAR_NOINIT) CertP_Certificate_Verify_Runnable_State;

/*! Variable for asynchronous state handling in function CertP_CsmSignatureVerify(). */
SSA_CERTP_LOCAL VAR(uint8, Ssa_CertP_VAR_NOINIT) CertP_CsmSignatureVerifyState;

/*! Storage for the CSM verification result used for asynchronous CSM call. */
SSA_CERTP_LOCAL VAR(Crypto_VerifyResultType, Ssa_CertP_VAR_NOINIT) CertP_CsmVerificationResult;   /* PRQA S 3218 */ /* MD_SSA_OBJECT_AT_FILE_SCOPE */

#define Ssa_CertP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_CertP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define Ssa_CertP_START_SEC_CODE
#include "Ssa_CertP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* BER Parser functions. */

/**********************************************************************************************************************
 * CertP_BerInitWorkspace()
 *********************************************************************************************************************/
/*!
 * \brief         Initializes the ASN.1/BER parser workspace
 * \details       -
 * \param[out]    WorkspacePtr   The workspace to initialize.
 * \param[in,out] StackPtr       The stack to use.
 * \param[in]     Depth          The depth of the stack
 * \pre           All provided pointers must be valid.
 *                Depth <= CERTP_MAX_DEPTH_OF_ONE_ELEMENT
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(void, Ssa_CertP_CODE) CertP_BerInitWorkspace(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  CONSTP2VAR(CertP_BerStackElementType, AUTOMATIC, AUTOMATIC) StackPtr,
  const uint8 Depth);

/**********************************************************************************************************************
 * CertP_BerGetElement_ValidityChecks()
 *********************************************************************************************************************/
/*!
 * \brief         Checks validity of parameters before getting an ASN.1/BER element.
 * \details       This function is called by CertP_BerGetElement().
 * \param[in]     WorkspacePtr       The internally used workspace.
 * \param[in]     ElementNrPtr       The element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth       The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \return        E_OK               if element was found
 *                E_NOT_OK           if element was not found
 *                CERTP_BER_E_MEM    if memory limit was exceeded
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(uint8, Ssa_CertP_CODE) CertP_BerGetElement_ValidityChecks(
  CONSTP2CONST(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth);

/**********************************************************************************************************************
 * CertP_BerGetElement_Core()
 *********************************************************************************************************************/
/*!
 * \brief         Gets an ASN.1/BER element with a given number out of ASN.1/BER encoded data.
 * \details       No validity check of input data; input data is expected to be valid.
 * \param[in,out] WorkspacePtr       The internally used workspace.
 * \param[out]    ElementPtr         The found element.
 * \param[in]     ElementNrPtr       The element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth       The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     DataPtr            The data.
 * \param[in]     DataSize           The size of the data.
 * \return        E_OK               if element was found
 *                E_NOT_OK           if element was not found
 *                CERTP_BER_E_MEM    if memory limit was exceeded
 * \pre           All provided pointers must be valid.
 *                The buffer referenced by ElementNrPtr must provide at least ElementDepth many bytes.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 *                CertP_BerGetElement_ValidityChecks() must be called before.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(uint8, Ssa_CertP_CODE) CertP_BerGetElement_Core(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) ElementPtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  const uint32 DataSize);

/**********************************************************************************************************************
 * CertP_BerGetElement()
 *********************************************************************************************************************/
/*!
 * \brief         Gets an ASN.1/BER element with a given number out of ASN.1/BER encoded data.
 * \details       This function calls CertP_BerGetElement_ValidityChecks() and CertP_BerGetElement_Core().
 * \param[in,out] WorkspacePtr       The internally used workspace.
 * \param[out]    ElementPtr         The found element.
 * \param[in]     ElementNrPtr       The element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth       The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     DataPtr            The data.
 * \param[in]     DataSize           The size of the data.
 * \return        E_OK               if element was found
 *                E_NOT_OK           if element was not found
 *                CERTP_BER_E_MEM    if memory limit was exceeded
 * \pre           All provided pointers must be valid.
 *                The buffer referenced by ElementNrPtr must provide at least ElementDepth many bytes.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(uint8, Ssa_CertP_CODE) CertP_BerGetElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) ElementPtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  const uint32 DataSize);

/**********************************************************************************************************************
 * CertP_BerGetNextElement()
 *********************************************************************************************************************/
/*!
 * \brief      Gets next ASN.1/BER element out of ASN.1/BER encoded data.
 * \details     -
 * \param[out] Element                The found element.
 * \param[in]  ElementIdx             The index
 * \param[in]  Block                  The current block.
 * \param[in]  Data                   The data.
 * \return     E_OK                   if element was found
 *             CERTP_BER_E_BER_PARAM  if element crosses block boundary or length exceeds block
 * \pre         All pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \spec        requires Element != NULL_PTR;                                                                  \endspec
 */
SSA_CERTP_LOCAL_INLINE FUNC(uint8, Ssa_CertP_CODE) CertP_BerGetNextElement(
  CONSTP2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) Element,
  uint32 ElementIdx,
  CONSTP2CONST(CertP_BerBlockType, AUTOMATIC, AUTOMATIC) Block,
  CONSTP2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) Data);

/* Helper functions. */

/**********************************************************************************************************************
 * CertP_CompareBerElement()
 *********************************************************************************************************************/
/*!
 * \brief       Compares the data of two BER elements.
 * \details     -
 * \param[in]   rawCertBufferElem1  The raw data containing BER element 1.
 * \param[in]   elem1               The data structure describing the BER element 1.
 * \param[in]   rawCertBufferElem2  The raw data containing BER element 2.
 * \param[in]   elem2               The data structure describing the BER element 2.
 * \return      TRUE  Both elements are equal.
 *              FALSE Both elements are not equal.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CERTP_LOCAL FUNC(boolean, Ssa_CertP_CODE) CertP_CompareBerElement(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBufferElem1,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem1,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBufferElem2,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem2);

/**********************************************************************************************************************
 * CertP_CheckBerElementsForDifference_Cond()
 *********************************************************************************************************************/
/*!
 * \brief       Checks if the data of two BER elements are different only if passed condition is fulfilled.
 * \details      -
 * \param[in]   rawCertBufferElem1  The raw data containing BER element 1.
 * \param[in]   elem1               The data structure describing the BER element 1.
 * \param[in]   rawCertBufferElem2  The raw data containing BER element 2.
 * \param[in]   elem2               The data structure describing the BER element 2.
 * \param[in]   cond                Condition that must be fulfilled before comparison.
 * \return      TRUE                Only if condition is TRUE and the elements are different.
 *              FALSE               Else
 * \pre         All provided pointers must be valid, if cond == TRUE.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CERTP_LOCAL FUNC(boolean, Ssa_CertP_CODE) CertP_CheckBerElementsForDifference_Cond(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBufferElem1,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem1,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBufferElem2,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem2,
  boolean cond);

/**********************************************************************************************************************
 * CertP_FindStringInSetOfUTF8Strings()
 *********************************************************************************************************************/
/*!
 * \brief       Finds a string in a set of UTF8 strings.
 * \details     -
 * \param[in]   stringToFind      The string to find.
 * \param[in]   lengthStrToFind   Length of the string to find.
 * \param[in]   rawCertBuffer     The raw data containing the set of UTF8 strings.
 * \param[in]   setOfUTF8Strings  The data structure describing the BER element set of UTF8stings.
 * \return      TRUE              The searched string has been found.
 *              FALSE             The searched string has not been found.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CERTP_LOCAL FUNC(boolean, Ssa_CertP_CODE) CertP_FindStringInSetOfUTF8Strings(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) stringToFind,
  uint8 lengthStrToFind,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBuffer,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) setOfUTF8Strings);

/**********************************************************************************************************************
 * CertP_CheckSetOfUTF8StringsAgainstUniqueEcuIds()
 *********************************************************************************************************************/
/*!
 * \brief       Checks a SetOfUTF8Strings against UniqueEcuIds.
 * \details     -
 * \param[in]   rawCertBuffer     The raw data containing the set of UTF8 strings.
 * \param[in]   setOfUTF8Strings  The data structure describing the BER element set of UTF8stings.
 * \return      TRUE              At least configured UniqueEcuId is listed in setOfUTF8Strings.
 *              FALSE             Else.
 * \pre         All provided pointers must be valid.
 *              setOfUTF8Strings->validContent = TRUE
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CERTP_LOCAL FUNC(boolean, Ssa_CertP_CODE) CertP_CheckSetOfUTF8StringsAgainstUniqueEcuIds(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBuffer,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) setOfUTF8Strings);

/**********************************************************************************************************************
 * CertP_CompareManyBerElementSetOfUTF8Strings()
 *********************************************************************************************************************/
/*!
 * \brief       Compares two sets of UTF8 strings in a special way.
 * \details     This function compares two sets of UTF8 strings. The comparison result is true if at least one string
 *              of set 1 is also listed in set 2.
 * \param[in]   rawCertBufferElem1  The raw data containing the first set of UTF8 strings.
 * \param[in]   elem1               The data structure describing the BER element set 1 of UTF8stings.
 * \param[in]   rawCertBufferElem2  The raw data containing the second set of UTF8 strings.
 * \param[in]   elem2               The data structure describing the BER element set 2 of UTF8stings.
 * \return      TRUE                At least one string of set 1 is listed in set 2.
 *              FALSE               Else.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CERTP_LOCAL FUNC(boolean, Ssa_CertP_CODE) CertP_CompareManyBerElementSetOfUTF8Strings(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBufferElem1,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem1,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBufferElem2,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem2);

/**********************************************************************************************************************
 * CertP_IsEqual()
 *********************************************************************************************************************/
/*!
 * \brief       Compares two buffers byte-by-byte.
 * \details     -
 * \param[in]   data1      Buffer 1
 * \param[in]   data2      Buffer 2
 * \param[in]   dataLength Number of bytes that shall be compared.
 * \return      TRUE       If both buffers contain the same data.
 *              FALSE      Else.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CERTP_LOCAL FUNC(boolean, Ssa_CertP_CODE) CertP_IsEqual(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) data1,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) data2,
  uint16 dataLength);

/* CertP parser functions. */

/**********************************************************************************************************************
 * CertP_ParseVersionElement()
 *********************************************************************************************************************/
/*!
 * \brief         Parses the version element of a certificate.
 * \details       -
 * \param[in,out] WorkspacePtr Pointer to the workspace used during parsing.
 * \param[in]     ElementNrPtr Pointer to the element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     DataPtr      Pointer to the raw data.
 * \param[in]     superElement Pointer to the super element describing the passed raw data.
 * \param[out]    versionPtr   Pointer to the buffer where the version shall be written.
 * \return        E_OK         Success, element information could be extracted.
 *                E_NOT_OK     Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                The buffer referenced by ElementNrPtr must provide at least ElementDepth many bytes.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseVersionElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) versionPtr);

/**********************************************************************************************************************
 * CertP_ParseStandardElement()
 *********************************************************************************************************************/
/*!
 * \brief         Parses a standard element of a certificate.
 * \details       -
 * \param[in,out] WorkspacePtr Pointer to the workspace used during parsing.
 * \param[in]     ElementNrPtr Pointer to the element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     ElementTag   The tag of the element that shall be parsed.
 * \param[in]     DataPtr      Pointer to the raw data.
 * \param[in]     superElement Pointer to the super element describing the passed raw data.
 * \param[out]    subElement   Pointer to the parsed element where the extracted data shall be written to.
 * \return        E_OK         Success, element information could be extracted.
 *                E_NOT_OK     Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                The buffer referenced by ElementNrPtr must provide at least ElementDepth many bytes.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseStandardElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  const uint8 ElementTag,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) subElement);

/**********************************************************************************************************************
 * CertP_ParsePublicKeyElement()
 *********************************************************************************************************************/
/*!
 * \brief         Parses the public key element of a certificate.
 * \details       -
 * \param[in,out] WorkspacePtr      Pointer to the workspace used during parsing.
 * \param[in]     ElementNrPtr      Pointer to the element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth      The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     DataPtr           Pointer to the raw data.
 * \param[in]     superElement      Pointer to the super element describing the passed raw data.
 * \param[out]    publicKeyElement  Pointer to the parsed public key element where the extracted data shall be
 *                                  written to.
 * \return        E_OK              Success, element information could be extracted.
 *                E_NOT_OK          Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                The buffer referenced by ElementNrPtr must provide at least ElementDepth many bytes.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParsePublicKeyElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) publicKeyElement);

/**********************************************************************************************************************
 * CertP_ParseTimeElement()
 *********************************************************************************************************************/
/*!
 * \brief       Parses a time element of a certificate.
 * \details     -
 * \param[in,out] WorkspacePtr      Pointer to the workspace used during parsing.
 * \param[in]     ElementNrPtr      Pointer to the element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth      The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     DataPtr           Pointer to the raw data.
 * \param[in]     superElement      Pointer to the super element describing the passed raw data.
 * \param[out]    parsedTimeElement Pointer to the parsed time element where the extracted data shall be written to.
 * \return        E_OK              Success, element information could be extracted.
 *                E_NOT_OK          Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                The buffer referenced by ElementNrPtr must provide at least ElementDepth many bytes.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseTimeElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_TimeType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedTimeElement);

/**********************************************************************************************************************
 * CertP_ParseIssuerOrSubjectElement()
 *********************************************************************************************************************/
/*!
 * \brief         Parses an issuer or subject element of a certificate.
 * \details       -
 * \param[in,out] WorkspacePtr Pointer to the workspace used during parsing.
 * \param[in]     ElementNrPtr Pointer to the element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     DataPtr      Pointer to the raw data.
 * \param[in]     superElement Pointer to the super element describing the passed raw data.
 * \param[out]    parsedIssuerOrSubjectElement Pointer to the parsed issuer or subject element where the extracted
 *                                             data shall be written to.
 * \return        E_OK         Success, element information could be extracted.
 *                E_NOT_OK     Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                The buffer referenced by ElementNrPtr must provide at least ElementDepth many bytes.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseIssuerOrSubjectElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedIssuerOrSubjectElement);

/**********************************************************************************************************************
 * CertP_ParseAttributesElement()
 *********************************************************************************************************************/
/*!
 * \brief         Parses the attribute elements of a certificate.
 * \details       -
 * \param[in,out] WorkspacePtr Pointer to the workspace used during parsing.
 * \param[in]     ElementNrPtr Pointer to the element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     DataPtr      Pointer to the raw data.
 * \param[in]     superElement Pointer to the super element describing the passed raw data.
 * \param[out]    parsedCert   Pointer to the parsed certificate where the extracted attribute data
 *                             shall be written to.
 * \return        E_OK         Success, element information could be extracted.
 *                E_NOT_OK     Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                The buffer referenced by ElementNrPtr must provide at least ElementDepth many bytes.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseAttributesElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert);

/**********************************************************************************************************************
 * CertP_ParseExtensionsElement_Tbs()
 *********************************************************************************************************************/
/*!
 * \brief         Parses the extensions element of a non-attribute certificate.
 * \details       -
 * \param[in,out] WorkspacePtr Pointer to the workspace used during parsing.
 * \param[in]     ElementNrPtr Pointer to the element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     DataPtr      Pointer to the raw data.
 * \param[in]     superElement Pointer to the super element describing the passed raw data.
 * \param[out]    parsedCert   Pointer to the parsed certificate where the extracted extensions data
 *                             shall be written to.
 * \return        E_OK         Success, element information could be extracted.
 *                E_NOT_OK     Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                The buffer referenced by ElementNrPtr must provide at least ElementDepth many bytes.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseExtensionsElement_Tbs(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert);

/**********************************************************************************************************************
 * CertP_ParseExtensionsElement_AttributeCert()
 *********************************************************************************************************************/
/*!
 * \brief         Parses the extensions elements of an attribute certificate.
 * \details       -
 * \param[in,out] WorkspacePtr  Pointer to the workspace used during parsing.
 * \param[in]     ElementNrPtr1 Pointer to the element number (chapter.section.subsection. ...) which is optional
 *                              an might not exist in the certificate data.
 * \param[in]     ElementNrPtr2 Pointer to the element number (chapter.section.subsection. ...) which is used if
 *                              the previous optional does not exist.
 * \param[in]     ElementDepth  The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     DataPtr       Pointer to the raw data.
 * \param[in]     superElement  Pointer to the super element describing the passed raw data.
 * \param[out]    parsedCert    Pointer to the parsed certificate where the extracted extensions data
 *                              shall be written to.
 * \return        E_OK          Success, element information could be extracted.
 *                E_NOT_OK      Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                The buffer referenced by ElementNrPtr must provide at least ElementDepth many bytes.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseExtensionsElement_AttributeCert(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr1,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr2,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert);

/**********************************************************************************************************************
 * CertP_ParseExtensionsElement()
 *********************************************************************************************************************/
/*!
 * \brief         Parses the extensions element of certificate.
 * \details       -
 * \param[in,out] WorkspacePtr Pointer to the workspace used during parsing.
 * \param[in]     ElementNrPtr Pointer to the element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     DataPtr      Pointer to the raw data.
 * \param[in]     superElement Pointer to the super element describing the passed raw data.
 * \param[out]    parsedCert   Pointer to the parsed certificate where the extracted extensions data
 *                             shall be written to.
 * \return        E_OK         Success, element information could be extracted.
 *                E_NOT_OK     Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                The buffer referenced by ElementNrPtr must provide at least ElementDepth many bytes.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseExtensionsElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert);

/**********************************************************************************************************************
 * CertP_ParseInitializeCertificate()
 *********************************************************************************************************************/
/*!
 * \brief       Initializes the parsed certificate data structure.
 * \details     -
 * \param[out]  cert  Pointer to the parsed certificate whose data are initialized.
 * \pre         cert must be a valid pointer.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CERTP_LOCAL FUNC(void, Ssa_CertP_CODE) CertP_ParseInitializeCertificate(
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) cert);

/**********************************************************************************************************************
 * CertP_ParseBaseStructure_ProcessRootElem()
 *********************************************************************************************************************/
/*!
  * \brief        Parses and checks the root element of a base structure a certificate.
 * \details       This function retrieves the root element, checks it for being a sequence and checks whether the
 *                maximum size is exceeded.
 * \param[in,out] WorkspacePtr      Pointer to the workspace used during parsing.
 * \param[out]    ElementPtr        The found element.
 * \param[in]     rawCertData       Pointer to the certificate raw data.
 * \param[in]     rawCertLength     The length of the complete certificate data.
 * \param[out]    parsedCert        Pointer to the parsed certificate where the extracted data shall be written to.
 * \return        E_OK              Success, element information could be extracted.
 *                E_NOT_OK          Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseBaseStructure_ProcessRootElem(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) ElementPtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  uint16 rawCertLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert);

/**********************************************************************************************************************
 * CertP_ParseBaseStructure_ProcessFirstSubElem()
 *********************************************************************************************************************/
/*!
  * \brief        Parses and checks the first subelement of the base structure of a certificate.
 * \details       This function retrieves the subelement, checks it for being a sequence and stores the element
 *                data index and length.
 * \param[in,out] WorkspacePtr      Pointer to the workspace used during parsing.
 * \param[out]    ElementPtr        The found element.
 * \param[in]     rawCertData       Pointer to the certificate raw data.
 * \param[in]     rawCertLength     The length of the complete certificate data.
 * \param[out]    parsedCert        Pointer to the parsed certificate where the extracted data shall be written to.
 * \param[out]    signedCertElement Pointer to the signed sub element written when parsing the base structure.
 * \return        E_OK              Success, element information could be extracted.
 *                E_NOT_OK          Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseBaseStructure_ProcessFirstSubElem(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) ElementPtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  uint16 rawCertLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2VAR(CertP_BerElementType, AUTOMATIC, AUTOMATIC) signedCertElement);

/**********************************************************************************************************************
 * CertP_ParseBaseStructure()
 *********************************************************************************************************************/
/*!
  * \brief        Parses the base structure a certificate.
 * \details       This function parses the base structure of both an non-attribute certificate and an attribute certificate
 * \param[in,out] WorkspacePtr      Pointer to the workspace used during parsing.
 * \param[in]     rawCertData       Pointer to the certificate raw data.
 * \param[in]     rawCertLength     The length of the complete certificate data.
 * \param[out]    parsedCert        Pointer to the parsed certificate where the extracted data shall be written to.
 * \param[out]    signedCertElement Pointer to the signed sub element written when parsing the base structure.
 * \return        E_OK              Success, element information could be extracted.
 *                E_NOT_OK          Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseBaseStructure(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  uint16 rawCertLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2VAR(CertP_BerElementType, AUTOMATIC, AUTOMATIC) signedCertElement);

/**********************************************************************************************************************
 * CertP_ParseTbsCertificate()
 *********************************************************************************************************************/
/*!
 * \brief        Parses a TBS certificate.
 * \details       This function parses a TBS certificate which is the first element of a non-attribute certificate.
 * \param[in,out] WorkspacePtr      Pointer to the workspace used during parsing.
 * \param[in]     DataPtr           Pointer to the data that shall be parsed.
 * \param[out]    parsedCert        Pointer to the parsed certificate where the extracted data shall be written to.
 * \param[in]     signedCertElement Pointer to the signed sub element.
 * \return        E_OK              Success, element information could be extracted.
 *                E_NOT_OK          Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseTbsCertificate(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) signedCertElement);

/**********************************************************************************************************************
 * CertP_ParseAttributeCertificateInfo()
 *********************************************************************************************************************/
/*!
 * \brief         Parses the attribute info part of an attribute certificate.
 * \details       -
 * \param[in,out] WorkspacePtr      Pointer to the workspace used during parsing.
 * \param[in]     DataPtr           Pointer to the data that shall be parsed.
 * \param[out]    parsedCert        Pointer to the parsed certificate where the extracted data shall be written to.
 * \param[in]     signedCertElement Pointer to the signed sub element.
 * \return        E_OK         Success, element information could be extracted.
 *                E_NOT_OK     Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseAttributeCertificateInfo(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) signedCertElement);

/**********************************************************************************************************************
 * CertP_ParseTime()
 *********************************************************************************************************************/
/*!
 * \brief       Parses the time of a time element.
 * \details     -
 * \param[in]   DataPtr       Pointer to the certificate raw data.
 * \param[out]  parsedTimePtr Pointer to the parsed time where the extracted data shall be written to.
 * \param[in]   timeElement   Pointer to the time element.
 * \return      E_OK          Success, element information could be extracted.
 *              E_NOT_OK      Failure, element information could not be extracted.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseTime(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2VAR(CertP_TimeType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedTimePtr,
  CertP_BerElementType timeElement);

/**********************************************************************************************************************
 * CertP_ParseIssuerOrSubject()
 *********************************************************************************************************************/
/*!
 * \brief         Parses the issuer or subject of an issuer or subject element.
 * \details       -
 * \param[in,out] WorkspacePtr          Pointer to the workspace used during parsing.
 * \param[in]     DataPtr               Pointer to the data that shall be parsed.
 * \param[out]    parsedIssuerOrSubject Pointer to the parsed issuer or subject where the extracted data shall be written to.
 * \param[in]     issuerSubjectElement  Pointer to the issuer or subject element.
 * \return        E_OK                  Success, element information could be extracted.
 *                E_NOT_OK              Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseIssuerOrSubject(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2VAR(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedIssuerOrSubject,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) issuerSubjectElement);

/**********************************************************************************************************************
 * CertP_ParseExtension_OIDLength3()
 *********************************************************************************************************************/
/*!
 * \brief         Parses one extension of an extensions element, where the parsed OID length is 3.
 * \details       -
 * \param[in,out] WorkspacePtr     Pointer to the workspace used during parsing.
 * \param[in,out] Elem             The found element.
 * \param[in]     DataPtr          Pointer to the data that shall be parsed.
 * \param[in]     extensionElement Pointer to the extension element.
 * \param[in,out] parsedCert       Pointer to the parsed certificate where the extracted data shall be written to.
 * \return        E_OK             Success, element information could be extracted.
 *                E_NOT_OK         Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
                  CertP_ParseExtension must be called before.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseExtension_OIDLength3(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) Elem,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) extensionElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert);

/**********************************************************************************************************************
 * CertP_ParseExtension_UpdateRole()
 *********************************************************************************************************************/
/*!
 * \brief         Gets an ASN.1/BER element with a given number out of ASN.1/BER encoded data and checks
 *                the difference between the element's end index and content index.
 * \details       -
 * \param[in,out] WorkspacePtr       The internally used workspace.
 * \param[out]    ElementPtr         The found element.
 * \param[in]     ElementNrPtr       The element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth       The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     DataPtr            The data.
 * \param[in]     DataSize           The size of the data.
 * \param[out]    Role               The role to be updated.
 * \return        E_OK               if element was found
 *                E_NOT_OK           if element was not found
 *                CERTP_BER_E_MEM    if memory limit was exceeded
 * \pre           All provided pointers must be valid.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 *                CertP_ParseExtension_OIDLength13 must be called before.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(uint8, Ssa_CertP_CODE) CertP_ParseExtension_UpdateRole(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) ElementPtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  const uint32 DataSize,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) Role);

/**********************************************************************************************************************
 * CertP_ParseExtension_UpdateElement()
 *********************************************************************************************************************/
/*!
 * \brief         Gets an ASN.1/BER element with a given number out of ASN.1/BER encoded data and checks
 *                the difference between the element's end index and content index.
 * \details       -
 * \param[in,out] WorkspacePtr       The internally used workspace.
 * \param[out]    ElementPtr         The found element.
 * \param[in]     ElementNrPtr       The element number (chapter.section.subsection. ...).
 * \param[in]     ElementDepth       The depth of the element (chapter = 1, chapter.section = 2, ...).
 * \param[in]     DataPtr            The data.
 * \param[in]     extensionElement   Pointer to the extension element.
 * \param[out]    Element            The target element to be updated.
 * \return        E_OK               if element was found
 *                E_NOT_OK           if element was not found
 *                CERTP_BER_E_MEM    if memory limit was exceeded
 * \pre           All provided pointers must be valid.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 *                CertP_ParseExtension_OIDLength13 must be called before.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL FUNC(uint8, Ssa_CertP_CODE) CertP_ParseExtension_UpdateElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) ElementPtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) extensionElement,
  P2VAR(CertP_BerElementType, AUTOMATIC, AUTOMATIC) Element);

/**********************************************************************************************************************
 * CertP_ParseExtension_OIDLength13()
 *********************************************************************************************************************/
/*!
 * \brief         Parses one extension of an extensions element, where the parsed OID length is 13.
 * \details       -
 * \param[in,out] WorkspacePtr     Pointer to the workspace used during parsing.
 * \param[in,out] Elem             The found element.
 * \param[in]     DataPtr          Pointer to the data that shall be parsed.
 * \param[in]     extensionElement Pointer to the extension element.
 * \param[in,out] parsedCert       Pointer to the parsed certificate where the extracted data shall be written to.
 * \return        E_OK             Success, element information could be extracted.
 *                E_NOT_OK         Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 *                CertP_ParseExtension must be called before.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseExtension_OIDLength13(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) Elem,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) extensionElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert);

/**********************************************************************************************************************
 * CertP_ParseExtension()
 *********************************************************************************************************************/
/*!
 * \brief         Parses one extension of an extensions element.
 * \details       -
 * \param[in,out] WorkspacePtr     Pointer to the workspace used during parsing.
 * \param[in]     DataPtr          Pointer to the data that shall be parsed.
 * \param[in]     extensionElement Pointer to the extension element.
 * \param[in,out] parsedCert       Pointer to the parsed certificate where the extracted data shall be written to.
 * \return        E_OK             Success, element information could be extracted.
 *                E_NOT_OK         Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseExtension(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) extensionElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert);

/**********************************************************************************************************************
 * CertP_ParseAttribute()
 *********************************************************************************************************************/
/*!
 * \brief         Parses one attribute of an attributes element.
 * \details       -
 * \param[in,out] WorkspacePtr     Pointer to the workspace used during parsing.
 * \param[in]     DataPtr          Pointer to the data that shall be parsed.
 * \param[in]     attributeElement Pointer to the attribute element.
 * \param[in,out] parsedCert       Pointer to the parsed certificate where the extracted data shall be written to.
 * \return        E_OK             Success, element information could be extracted.
 *                E_NOT_OK         Failure, element information could not be extracted.
 * \pre           All provided pointers must be valid.
 *                WorkspacePtr->Stack must reference an array of at least CERTP_MAX_DEPTH_OF_ONE_ELEMENT many elements.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseAttribute(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC)  attributeElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert);

/* CertP verify functions. */

/**********************************************************************************************************************
 * CertP_Certificate_Verify_SigAlgoIdentifier()
 *********************************************************************************************************************/
/*!
 * \brief         Verifies the signature algorithm identifiers.
 * \details       -
 * \param[in]     rawCertData Pointer to the certificate.
 * \param[in,out] parsedCert  Pointer to the parsed certificate data.
 *                            Its verification result is set to INVALID_FORMAT when the verification fails.
 * \return        E_OK        Verification succeeded.
 *                E_NOT_OK    Verification failed.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_Certificate_Verify_SigAlgoIdentifier(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert);

/**********************************************************************************************************************
 * CertP_Certificate_Verify_Vin()
 *********************************************************************************************************************/
/*!
 * \brief         Verifies the target VIN of the certificate to be verified only if a target VIN is contained in it.
 * \details       -
 * \param[in]     rawCertData Pointer to the certificate whose VIN shall be verified.
 * \param[in,out] parsedCert  Pointer to the parsed certificate data whose VIN shall be verified.
 *                            Its verification result is set to INVALID_SCOPE when the verification fails.
 * \param[out]    errCode     Always E_OK.
 * \return        TRUE        Verification is finished.
 *                FALSE       Verification succeeded so far.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(boolean, Ssa_CertP_CODE) CertP_Certificate_Verify_Vin(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) errCode);

/**********************************************************************************************************************
 * CertP_Certificate_Verify_TargetEcu()
 *********************************************************************************************************************/
/*!
 * \brief         Verifies the target ECU of the certificate to be verified only if a target ECU is contained in it.
 * \details       -
 * \param[in]     rawCertData   Pointer to the certificate whose target ECU shall be verified.
 * \param[in,out] parsedCert    Pointer to the certificate whose target ECU shall be verified.
 *                              Its verification result is set to INVALID_SCOPE when the verification fails.
 * \param[out]    errCode       Always E_OK.
 * \return        TRUE          Verification is finished.
 *                FALSE         Verification succeeded so far.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(boolean, Ssa_CertP_CODE) CertP_Certificate_Verify_TargetEcu(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) errCode);

/**********************************************************************************************************************
 * CertP_Certificate_Verify_Nonce()
 *********************************************************************************************************************/
/*!
 * \brief         Verifies the nonce if there is one, else verifies the validNotAfter date and time.
 * \details       This function verifies the nonce of the certificate to be verified only if a nonce is contained in it.
 *                If no nonce shall or can be verified the validNotAfter date-and-time values (of both certificates) are verified.
 * \param[in]     rawCertData       Pointer to the certificate whose nonce resp. validNotAfter date and time shall be verified.
 * \param[in,out] parsedCert        Pointer to the parsed certificate data whose nonce resp. validNotAfter date and time be verified.
 *                                  Its verification result is set to SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED
 *                                  resp. to INVALID_TIME_PERIOD when the verification fails.
 * \param[in]     parsedCertIssuer  Pointer to the parsed certificate data of the issuer.
 * \param[in]     expectedNonce     Pointer to the nonce that is expected to be contained in the certificate.
 * \param[out]    errCode           E_OK when the date and time could be checked.
 *                                  E_NOT_OK when getting the current real-time failed.
 * \return        TRUE              Verification is finished.
 *                FALSE             Verification succeeded so far.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(boolean, Ssa_CertP_CODE) CertP_Certificate_Verify_Nonce(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer,
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) expectedNonce,
  P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) errCode);

/**********************************************************************************************************************
 * CertP_Certificate_Verify_IsFormatValid()
 *********************************************************************************************************************/
/*!
 * \brief       Verifies the format of the certificate.
 * \details     -
 * \param[in]   parsedCert       Pointer to the parsed certificate data.
 * \param[in]   expectedPkiRole  The expected PKI role of the certificate.
 * \return      TRUE              Verification is finished due verification failure.
 *              FALSE             Verification succeeded.
 * \pre         parsedCert must be a valid pointer.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(boolean, Ssa_CertP_CODE) CertP_Certificate_Verify_IsFormatValid(
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCert,
  CertP_PkiRoleType expectedPkiRole);

/**********************************************************************************************************************
 * CertP_Certificate_Verify_PreCsmCall()
 *********************************************************************************************************************/
/*!
 * \brief         Verifies certificate elements that have to be verified before signature verification.
 * \details       -
 * \param[in]     rawCertData       Pointer to the raw certificate data to be verified.
 * \param[in,out] parsedCert        Pointer to the memory location where the parsed information are stored.
 * \param[in]     rawCertIssuer     Pointer to the raw certificate data to be verified.
 * \param[in]     parsedCertIssuer  Pointer to the memory location where the parsed information of issuer certificate are stored.
 * \param[in]     expectedPkiRole   Expected role of the certificate to be verified.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(void, Ssa_CertP_CODE) CertP_Certificate_Verify_PreCsmCall(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertIssuer,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer,
  CertP_PkiRoleType expectedPkiRole);

/**********************************************************************************************************************
 * CertP_Certificate_Verify_PostCsmCall()
 *********************************************************************************************************************/
/*!
 * \brief         Verifies certificate elements that have to be verified after signature verification.
 * \details       -
 * \param[in]     rawCertData       Pointer to the raw certificate data to be verified.
 * \param[in,out] parsedCert        Pointer to the memory location where the parsed information are stored.
 * \param[in]     parsedCertIssuer  Pointer to the memory location where the parsed information of issuer certificate are stored.
 * \param[in]     expectedNonce     Pointer to a memory location where the expected nonce is stored.
 * \return        E_OK     Verification succeeded.
 *                E_NOT_OK Verification failed.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_Certificate_Verify_PostCsmCall(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer,
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) expectedNonce);

/**********************************************************************************************************************
 * CertP_CsmSignatureVerify()
 *********************************************************************************************************************/
/*!
 * \brief       Calls asynchronously the Csm signature verify job.
 * \details     This function calls asynchronously the Csm signature verify job.
 * \param[in]   dataIn          Data to be verified
 * \param[in]   dataInLength    Length of data to be verified.
 * \param[in]   dataKey         Key data.
 * \param[in]   dataKeyLength   Length of key data.
 * \param[in]   dataSignature   The signature the data shall be verified against.
 * \param[out]  csmVerifyResult Csm verification result
 * \return      E_OK           Request successful.
 *              E_NOT_OK       Request failed.
 *              SSA_E_PENDING  Request is pending.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \note        The VCA specification is required to ensure that no null pointer is passed to the RTE.
 * \spec        requires dataIn != NULL_PTR;
 *              requires dataKey != NULL_PTR;
 *              requires dataSignature != NULL_PTR;
 *              requires csmVerifyResult != NULL_PTR;                                                          \endspec
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_CsmSignatureVerify(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) dataIn,
  uint16 dataInLength,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) dataKey,
  uint16 dataKeyLength,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) dataSignature,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, AUTOMATIC) csmVerifyResult);

/**********************************************************************************************************************
 * CertP_Certificate_Verify()
 *********************************************************************************************************************/
/*!
 * \brief       Verifies passed certificate against passed issuer certificate. Furthermore, expected role, nonce and target vin / unique ECU id are verified if needed.
 * \details     -
 * \param[in]   rawCertData      Holds a pointer to the raw certificate data to be verified.
 * \param[in,out] parsedCert     Holds the pointer to the memory location where the parsed information are stored.
 * \param[in]   rawCertIssuer    Holds a pointer to the raw certificate issuer data to be verified.
 * \param[in]   parsedCertIssuer Holds the pointer to the memory location where the parsed information of issuer certificate are stored.
 * \param[in]   expectedPkiRole  Expected role of the certificate to be verified.
 * \param[in]   expectedNonce    Holds a pointer to a memory location where the expected nonce is stored.
 * \return      RTE_E_OK Certificate could be verified.
 *              RTE_E_CertP_Functions_E_NOT_OK An error occurred.
 *              RTE_E_CertP_Functions_E_PENDING Requested service is pending. Try again with operation status Pending.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 * \spec        requires $lengthOf(rawCertData) >= sizeof(CertP_RawCertBufferType);
 *              requires $lengthOf(rawCertIssuer) >= sizeof(CertP_RawCertBufferType);                          \endspec
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_Certificate_Verify(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertIssuer,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer,
  CertP_PkiRoleType expectedPkiRole,
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) expectedNonce);

/**********************************************************************************************************************
 * CertP_Certificate_Verify_HandleResult()
 *********************************************************************************************************************/
/*!
 * \brief       Processes return value and verification result of certificate verification.
 * \details     This function is called from CertP_Certificate_Verify, after the verification states are handled.
 * \param[in]   retVal           Return value of CertP_Certificate_Verify to be processed.
 * \param[in]   rawCertData      Holds a pointer to the raw certificate data to be verified.
 * \param[in]   parsedCert       Holds the pointer to the memory location where the parsed information are stored.
 * \param[in]   expectedPkiRole  Expected role of the certificate to be verified.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE|FALSE
 */
SSA_CERTP_LOCAL_INLINE FUNC(void, Ssa_CertP_CODE) CertP_Certificate_Verify_HandleResult(
  Std_ReturnType retVal,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  CertP_PkiRoleType expectedPkiRole);

#define Ssa_CertP_STOP_SEC_CODE
#include "Ssa_CertP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Ssa_ConstDataPtr: DataReference
 * Ssa_VerifyResultPtr: DataReference
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * CertP_PkiRoleType: Enumeration of integer in interval [0...255] with enumerators
 *   CERTP_PKI_ROLE_ROOT (1U)
 *   CERTP_PKI_ROLE_BACKEND (2U)
 *   CERTP_PKI_ROLE_TESTER (3U)
 *   CERTP_PKI_ROLE_ECU (4U)
 *   CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS (5U)
 *   CERTP_PKI_ROLE_VARIANT_CODING (7U)
 *   CERTP_PKI_ROLE_USER_CERT_FOR_CODING (9U)
 *   CERTP_PKI_ROLE_ROOT_CA_LINK_CERT (10U)
 *   CERTP_PKI_ROLE_BACKEND_CA_LINK_CERT (11U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA (12U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA (13U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA (14U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_ECU (15U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA_LINK (16U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA_LINK (17U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA_LINK (18U)
 *   CERTP_PKI_ROLE_PQC_ROOT_CA (19U)
 *   CERTP_PKI_ROLE_PQC_BACKEND_CA (20U)
 *   CERTP_PKI_ROLE_PQC_TESTER (21U)
 *   CERTP_PKI_ROLE_PQC_ECU (22U)
 *   CERTP_PKI_ROLE_INVALID (0U)
 * CertP_VerificationResultType: Enumeration of integer in interval [0...255] with enumerators
 *   CERTP_VER_OK (0U)
 *   CERTP_VER_INVALID_TIME_PERIOD (16U)
 *   CERTP_VER_INVALID_SIGNATURE (17U)
 *   CERTP_VER_INVALID_CHAIN_OF_TRUST (18U)
 *   CERTP_VER_INVALID_TYPE (19U)
 *   CERTP_VER_INVALID_FORMAT (20U)
 *   CERTP_VER_INVALID_CONTENT (21U)
 *   CERTP_VER_INVALID_SCOPE (22U)
 *   CERTP_VER_SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED (64U)
 *   CERTP_VER_PARSE_OK (253U)
 *   CERTP_VER_PARSE_FAILED (254U)
 *   CERTP_VER_NOT_PARSED (255U)
 * Crypto_OperationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   CRYPTO_OPERATIONMODE_START (1U)
 *   CRYPTO_OPERATIONMODE_UPDATE (2U)
 *   CRYPTO_OPERATIONMODE_STREAMSTART (3U)
 *   CRYPTO_OPERATIONMODE_FINISH (4U)
 *   CRYPTO_OPERATIONMODE_SINGLECALL (7U)
 * Crypto_VerifyResultType: Enumeration of integer in interval [0...1] with enumerators
 *   CRYPTO_E_VER_OK (0U)
 *   CRYPTO_E_VER_NOT_OK (1U)
 * Csm_ResultType: Enumeration of integer in interval [0...8] with enumerators
 *   E_NOT_OK (1U)
 *   E_SMALL_BUFFER (2U)
 *   E_ENTROPY_EXHAUSTION (3U)
 *   E_KEY_READ_FAIL (4U)
 *   E_KEY_NOT_AVAILABLE (4U)
 *   E_KEY_NOT_VALID (6U)
 *   E_JOB_CANCELED (7U)
 *   E_KEY_EMPTY (8U)
 * RightsM_DiagnosticUserRoleType: Enumeration of integer in interval [0...255] with enumerators
 *   RIGHTSM_USERROLE_ANYBODY (0U)
 *   RIGHTSM_USERROLE_SUPPLIER (1U)
 *   RIGHTSM_USERROLE_DEV_ENHANCED (2U)
 *   RIGHTSM_USERROLE_PRODUCTION (3U)
 *   RIGHTSM_USERROLE_AS_ENHANCED (4U)
 *   RIGHTSM_USERROLE_AS_STANDARD (5U)
 *   RIGHTSM_USERROLE_AS_BASIC (6U)
 *   RIGHTSM_USERROLE_INT_DIAG_TEST_TOOL (7U)
 *   RIGHTSM_USERROLE_EPTI_TEST_TOOL (8U)
 * Ssa_KeyElementType: Enumeration of integer in interval [0...4294967295] with enumerators
 *   SSA_KE_MAC_KEY (1U)
 *   SSA_KE_MAC_PROOF (2U)
 *   SSA_KE_SIGNATURE_KEY (1U)
 *   SSA_KE_RANDOM_SEED_STATE (3U)
 *   SSA_KE_RANDOM_ALGORITHM (4U)
 *   SSA_KE_CIPHER_KEY (1U)
 *   SSA_KE_CIPHER_IV (5U)
 *   SSA_KE_CIPHER_PROOF (6U)
 *   SSA_KE_CIPHER_2NDKEY (7U)
 *   SSA_KE_KEYEXCHANGE_BASE (8U)
 *   SSA_KE_KEYEXCHANGE_PRIVKEY (9U)
 *   SSA_KE_KEYEXCHANGE_OWNPUBKEY (10U)
 *   SSA_KE_KEYEXCHANGE_SHAREDVALUE (1U)
 *   SSA_KE_KEYEXCHANGE_ALGORITHM (12U)
 *   SSA_KE_KEYDERIVATION_PASSWORD (1U)
 *   SSA_KE_KEYDERIVATION_SALT (13U)
 *   SSA_KE_KEYDERIVATION_ITERATIONS (14U)
 *   SSA_KE_KEYDERIVATION_ALGORITHM (15U)
 *   SSA_KE_KEYGENERATE_KEY (1U)
 *   SSA_KE_KEYGENERATE_SEED (16U)
 *   SSA_KE_KEYGENERATE_ALGORITHM (17U)
 *   SSA_KE_CERTIFICATE_DATA (0U)
 * TimeM_CompareOperatorType: Enumeration of integer in interval [0...255] with enumerators
 *   TIMEM_IS_GREATER (0U)
 *   TIMEM_IS_LESS (1U)
 *
 * Array Types:
 * ============
 * CertP_RawCertBufferType: Array with 910 element(s) of type uint8
 * Coding_VINDataType: Array with 17 element(s) of type uint8
 * Csm_KeyDataType_Ssa_SignatureRamKey: Array with 32 element(s) of type uint8
 * RightsM_SerialNumberType: Array with 16 element(s) of type uint8
 * Ssa_Data15ByteType: Array with 15 element(s) of type uint8
 * Ssa_Data32ByteType: Array with 32 element(s) of type uint8
 *
 * Record Types:
 * =============
 * CertP_BerElementType: Record with elements
 *   validContent of type boolean
 *   elemDataIdx of type uint16
 *   elemDataLength of type uint16
 * CertP_ParsedCertStructureType: Record with elements
 *   verificationResult of type CertP_VerificationResultType
 *   parsedCertLength of type uint16
 *   signedCertData of type CertP_BerElementType
 *   version of type uint8
 *   serialNumber of type CertP_BerElementType
 *   certSignatureAlgOID of type CertP_BerElementType
 *   issuer of type CertP_BerElementType
 *   validNotBefore of type CertP_TimeType
 *   validNotAfter of type CertP_TimeType
 *   subject of type CertP_BerElementType
 *   publicKey of type CertP_BerElementType
 *   subjectKeyIdentifier of type CertP_BerElementType
 *   authorityKeyIdentifier of type CertP_BerElementType
 *   keyUsage of type uint16
 *   basicConstraints of type uint8
 *   pkiRole of type CertP_PkiRoleType
 *   userRole of type RightsM_DiagnosticUserRoleType
 *   targetECU of type CertP_BerElementType
 *   targetVIN of type CertP_BerElementType
 *   nonce of type CertP_BerElementType
 *   prodQualifier of type uint8
 *   uniqueEcuId of type CertP_BerElementType
 *   service of type CertP_BerElementType
 *   holderIssuer of type CertP_BerElementType
 *   holderSerialNumber of type CertP_BerElementType
 *   signatureAlgorithmOID of type CertP_BerElementType
 *   signature of type CertP_BerElementType
 *   specialECU of type uint8
 *   targetSubjectKeyIdentifier of type CertP_BerElementType
 * CertP_TimeType: Record with elements
 *   validContent of type boolean
 *   dateTime of type TimeM_DateTimeType
 * RightsM_AuthNonceType: Record with elements
 *   data of type Ssa_Data32ByteType
 *   validated of type boolean
 * TimeM_DateTimeType: Record with elements
 *   year of type uint16
 *   month of type uint8
 *   day of type uint8
 *   hour of type uint8
 *   minute of type uint8
 *   second of type uint8
 *
 *********************************************************************************************************************/


#define Ssa_CertP_START_SEC_CODE
#include "Ssa_CertP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_CertP_AttributeCertificate_Parse
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <AttributeCertificate_Parse> of PortPrototype <CertP_Functions>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_CertP_AttributeCertificate_Parse(const uint8 *rawCertData, uint16 rawCertLength, CertP_ParsedCertStructureType *parsedCert)
 *     Argument rawCertData: uint8* is of type CertP_RawCertBufferType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CertP_Functions_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_AttributeCertificate_Parse_doc
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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_CertP_CODE) Ssa_CertP_AttributeCertificate_Parse(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  uint16 rawCertLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_AttributeCertificate_Parse (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_CertP_Functions_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((rawCertData == NULL_PTR) || (parsedCert == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    const uint8 MaxEleDepth = CERTP_MAX_DEPTH_OF_ONE_ELEMENT;
    CertP_BerWorkspaceType      Workspace;
    CertP_BerStackElementType  BerStack[CERTP_MAX_DEPTH_OF_ONE_ELEMENT];  /* 5 = max depth of one element */
    CertP_BerElementType signedCertDataContent;

    retVal = E_OK;

    /* #10 Initialize the workspace for the DER decoder. */
    CertP_BerInitWorkspace(&Workspace, &BerStack[0], MaxEleDepth); /* only needed once */

    /* #20 Initialize the content for the parsed certificate data. */
    CertP_ParseInitializeCertificate(parsedCert);

    /* #30 Check that the length of the certificate data does not exceed the maximum size. */
    if (rawCertLength > sizeof(CertP_RawCertBufferType))
    {
      retVal = E_NOT_OK;
    }
    /* #40 Parse the base structure of the certificate. */
    else if (CertP_ParseBaseStructure(&Workspace, rawCertData, rawCertLength, parsedCert, &signedCertDataContent) != E_OK)
    {
      retVal = E_NOT_OK;
    }
    /* #50 Parse as first sub-element the attribute certificate information. */
    else
    {
      if (CertP_ParseAttributeCertificateInfo(&Workspace, &(rawCertData[signedCertDataContent.elemDataIdx]), parsedCert, &signedCertDataContent) != E_OK)
      {
        retVal = E_NOT_OK;
      }
    }

    /* #60 If no error occurred return the as positive return code "parse ok" else "parse failed. */
    if (retVal == E_OK)
    {
      /* The certificate has been successfully parsed. */
      parsedCert->verificationResult = CERTP_VER_PARSE_OK;
    }
    else
    {
      parsedCert->verificationResult = CERTP_VER_PARSE_FAILED;
      retVal = E_OK;
    }
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_CertP_Certificate_Compare
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Certificate_Compare> of PortPrototype <CertP_Functions>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_CertP_Certificate_Compare(const uint8 *rawCertData1, const CertP_ParsedCertStructureType *parsedCert1, CertP_PkiRoleType pkiRole1, const uint8 *rawCertData2, const CertP_ParsedCertStructureType *parsedCert2, CertP_PkiRoleType pkiRole2, boolean *isEqual)
 *     Argument rawCertData1: uint8* is of type CertP_RawCertBufferType
 *     Argument rawCertData2: uint8* is of type CertP_RawCertBufferType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CertP_Functions_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_Certificate_Compare_doc
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
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_CertP_CODE) Ssa_CertP_Certificate_Compare(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData1,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCert1,
  CertP_PkiRoleType pkiRole1,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData2,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCert2,
  CertP_PkiRoleType pkiRole2,
  P2VAR(boolean, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) isEqual) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_Certificate_Compare (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_CertP_Functions_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((rawCertData1 == NULL_PTR) || (parsedCert1 == NULL_PTR) ||
      (rawCertData2 == NULL_PTR) || (parsedCert2 == NULL_PTR) ||
      (isEqual == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    retVal = RTE_E_OK;

    /* #10 Compare the relevant fields depending on the PKI roles. */

    /* #20 Check if a Backend CA Link certificate shall be compared with a Backend CA certificate or
     * if a Root CA Link certificate shall be compared with a Root CA certificate. */
    if (((pkiRole1 == CERTP_PKI_ROLE_BACKEND_CA_LINK_CERT) && (pkiRole2 == CERTP_PKI_ROLE_BACKEND))
      || ((pkiRole1 == CERTP_PKI_ROLE_ROOT_CA_LINK_CERT) && (pkiRole2 == CERTP_PKI_ROLE_ROOT)))
    {
      /* #30 Compare the version. */
      if (parsedCert1->version != parsedCert2->version)
      {
        *isEqual = FALSE;
      }
      /* #31 Compare Algorithm Id. */
      else if (!CertP_CompareBerElement(rawCertData1, &(parsedCert1->certSignatureAlgOID), rawCertData2, &(parsedCert2->certSignatureAlgOID)))
      {
        *isEqual = FALSE;
      }
      /* #32 Compare 'Validity - not before'. */
      else if (
        (parsedCert1->validNotBefore.dateTime.year != parsedCert2->validNotBefore.dateTime.year)
        || (parsedCert1->validNotBefore.dateTime.month != parsedCert2->validNotBefore.dateTime.month)
        || (parsedCert1->validNotBefore.dateTime.day != parsedCert2->validNotBefore.dateTime.day)
        || (parsedCert1->validNotBefore.dateTime.hour != parsedCert2->validNotBefore.dateTime.hour)
        || (parsedCert1->validNotBefore.dateTime.minute != parsedCert2->validNotBefore.dateTime.minute)
        || (parsedCert1->validNotBefore.dateTime.second != parsedCert2->validNotBefore.dateTime.second))
      {
        *isEqual = FALSE;
      }
      /* 'Validity - not after' might be changed according to 'Specification for Certificate Structure MSS-10824'. */
      /* #34 Compare the subject. */
      else if (!CertP_CompareBerElement(rawCertData1, &(parsedCert1->subject),
        rawCertData2, &(parsedCert2->subject)))
      {
        *isEqual = FALSE;
      }
      /* #36 Compare the prod. qualifier. */
      else if (parsedCert1->prodQualifier != parsedCert2->prodQualifier)
      {
        *isEqual = FALSE;
      }
      /* #38 Compare the subject key identifier. */
      else if (!CertP_CompareBerElement(rawCertData1, &(parsedCert1->subjectKeyIdentifier),
        rawCertData2, &(parsedCert2->subjectKeyIdentifier)))
      {
        *isEqual = FALSE;
      }
      /* #40 Compare the key usage. */
      else if (parsedCert1->keyUsage != parsedCert2->keyUsage)
      {
        *isEqual = FALSE;
      }
      /* #42 Compare the Basic constraints. */
      else if (parsedCert1->basicConstraints != parsedCert2->basicConstraints)
      {
        *isEqual = FALSE;
      }
      /* #44 Compare the signature algorithm identifier. */
      else if (!CertP_CompareBerElement(rawCertData1, &(parsedCert1->signatureAlgorithmOID),
        rawCertData2, &(parsedCert2->signatureAlgorithmOID)))
      {
        *isEqual = FALSE;
      }
      /* #46 Compare the public key. */
      else if (!CertP_CompareBerElement(rawCertData1, &(parsedCert1->publicKey),
        rawCertData2, &(parsedCert2->publicKey)))
      {
        *isEqual = FALSE;
      }
      /* #50 Return TRUE as comparison result only if all comparisons indicated equality. */
      else
      {
        *isEqual = TRUE;
      }
    }
    /* #60 Check that ECU certificate shall be compared with an ECU certificate. */
    else if ((pkiRole1 == CERTP_PKI_ROLE_ECU) && (pkiRole2 == CERTP_PKI_ROLE_ECU))
    {
      /* #70 Compare the uniqueECUIDs. Both certificate must have a common uniqueECUID. */
      if (!CertP_CompareManyBerElementSetOfUTF8Strings(rawCertData1, &(parsedCert1->uniqueEcuId), rawCertData2, &(parsedCert2->uniqueEcuId)))
      {
        *isEqual = FALSE;
      }
      /* #72 Compare the special ECU. */
      else if (parsedCert1->specialECU != parsedCert2->specialECU)
      {
        *isEqual = FALSE;
      }
      /* #80 Return TRUE as comparison result only if all comparisons indicated equality. */
      else
      {
        *isEqual = TRUE;
      }
    }
    /* #90 Other PKI roles for comparison are not supported. Return FALSE as comparison result. */
    else
    {
      /* Not supported PKI roles. */
      *isEqual = FALSE;
    }
  }

  return retVal;
  /* PRQA S 6030, 6060, 6080 4 */ /* MD_MSR_STCYC, MD_SSA_STPAR, MD_SSA_MIF_CHECK_CONDITIONS */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_CertP_Certificate_Parse
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Certificate_Parse> of PortPrototype <CertP_Functions>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_CertP_Certificate_Parse(const uint8 *rawCertData, uint16 rawCertLength, CertP_ParsedCertStructureType *parsedCert)
 *     Argument rawCertData: uint8* is of type CertP_RawCertBufferType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CertP_Functions_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_Certificate_Parse_doc
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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_CertP_CODE) Ssa_CertP_Certificate_Parse(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  uint16 rawCertLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_Certificate_Parse (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_CertP_Functions_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((rawCertData == NULL_PTR) || (parsedCert == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    const uint8 MaxEleDepth = CERTP_MAX_DEPTH_OF_ONE_ELEMENT;
    CertP_BerWorkspaceType Workspace;
    CertP_BerStackElementType BerStack[CERTP_MAX_DEPTH_OF_ONE_ELEMENT]; /* 5 = max depth of one element */
    CertP_BerElementType signedCertDataContent;

    retVal = E_OK;

    /* #10 Initialize the workspace for the DER decoder. */
    CertP_BerInitWorkspace(&Workspace, &BerStack[0], MaxEleDepth); /* only needed once */

    /* #20 Initialize the content for the parsed certificate data. */
    CertP_ParseInitializeCertificate(parsedCert);

    /* #30 Check that the length of the certificate data does not exceed the maximum size. */
    if (rawCertLength > sizeof(CertP_RawCertBufferType))
    {
      retVal = E_NOT_OK;
    }
    /* #40 Parse the base structure of the certificate. */
    else if (CertP_ParseBaseStructure(&Workspace, rawCertData, rawCertLength, parsedCert, &signedCertDataContent) != E_OK)
    {
      retVal = E_NOT_OK;
    }
    /* #50 Parse the as first sub-element the TBS certificate. */
    else
    {
      if (CertP_ParseTbsCertificate(&Workspace, &(rawCertData[signedCertDataContent.elemDataIdx]), parsedCert, &signedCertDataContent) != E_OK)
      {
        retVal = E_NOT_OK;
      }
    }

    /* #60 If no error occurred return the as positive return code "parse ok" else "parse failed". */
    if (retVal == E_OK)
    {
      /* The certificate has been successfully parsed. */
      parsedCert->verificationResult = CERTP_VER_PARSE_OK;
    }
    else
    {
      parsedCert->verificationResult = CERTP_VER_PARSE_FAILED;
      retVal = E_OK;
    }
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_CertP_Certificate_Verify
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Certificate_Verify> of PortPrototype <CertP_Functions>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Coding_VIN_Get(uint8 *vin)
 *     Argument vin: uint8* is of type Coding_VINDataType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Coding_VIN_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecLog_FailedCertVerificationEvent_FailedCertificateVerification(CertP_PkiRoleType pkiRole, CertP_VerificationResultType validationResult)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_FailedCertVerificationEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecLog_SuccessfulCertVerificationEvent_SuccessfulCertificateVerification(const uint8 *certId, CertP_PkiRoleType pkiRole)
 *     Argument certId: uint8* is of type RightsM_SerialNumberType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_SuccessfulCertVerificationEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_RealTime_Compare(const TimeM_DateTimeType *t1, TimeM_CompareOperatorType compareOp, const TimeM_DateTimeType *t2, boolean *result)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_RealTime_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_RealTime_Get(TimeM_DateTimeType *realTime)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_RealTime_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Key_SignatureRamKey_KeyElementSet(uint32 keyElementId, const uint8 *keyPtr, uint32 keyLength)
 *     Argument keyPtr: uint8* is of type Csm_KeyDataType_Ssa_SignatureRamKey
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_BUSY, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_NOT_AVAILABLE, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_WRITE_FAIL, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_SMALL_BUFFER, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_E_NOT_OK
 *   Std_ReturnType Rte_Call_Key_SignatureRamKey_KeySetValid(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_BUSY, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_CertP_Certificate_Verify(const uint8 *rawCertData, CertP_ParsedCertStructureType *parsedCert, const uint8 *rawCertIssuer, const CertP_ParsedCertStructureType *parsedCertIssuer, CertP_PkiRoleType expectedPkiRole)
 *     Argument rawCertData: uint8* is of type CertP_RawCertBufferType
 *     Argument rawCertIssuer: uint8* is of type CertP_RawCertBufferType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CertP_Functions_E_NOT_OK
 *   RTE_E_CertP_Functions_E_PENDING
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_Certificate_Verify_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(rawCertData) >= sizeof(CertP_RawCertBufferType);
 *    requires $lengthOf(rawCertIssuer) >= sizeof(CertP_RawCertBufferType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_CertP_CODE) Ssa_CertP_Certificate_Verify(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertIssuer,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer,
  CertP_PkiRoleType expectedPkiRole) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_Certificate_Verify (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_CertP_Functions_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((rawCertData == NULL_PTR) || (parsedCert == NULL_PTR) ||
      (rawCertIssuer == NULL_PTR) || (parsedCertIssuer == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    RightsM_AuthNonceType CertP_NoNonce = { { 0 }, FALSE };

    /* #10 Pass arguments to local function for certificate verification. */
    retVal = CertP_Certificate_Verify( /* VCA_SSA_CERTP_RAW_CERT_LENGTH */
      rawCertData,
      parsedCert,
      rawCertIssuer,
      parsedCertIssuer,
      expectedPkiRole,
      &CertP_NoNonce);
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_CertP_Certificate_Verify_Extended
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Certificate_Verify_Extended> of PortPrototype <CertP_Functions>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_Coding_VIN_Get(uint8 *vin)
 *     Argument vin: uint8* is of type Coding_VINDataType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Coding_VIN_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecLog_FailedCertVerificationEvent_FailedCertificateVerification(CertP_PkiRoleType pkiRole, CertP_VerificationResultType validationResult)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_FailedCertVerificationEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecLog_SuccessfulCertVerificationEvent_SuccessfulCertificateVerification(const uint8 *certId, CertP_PkiRoleType pkiRole)
 *     Argument certId: uint8* is of type RightsM_SerialNumberType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_SuccessfulCertVerificationEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_RealTime_Compare(const TimeM_DateTimeType *t1, TimeM_CompareOperatorType compareOp, const TimeM_DateTimeType *t2, boolean *result)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_RealTime_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_RealTime_Get(TimeM_DateTimeType *realTime)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_RealTime_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_Key_SignatureRamKey_KeyElementSet(uint32 keyElementId, const uint8 *keyPtr, uint32 keyLength)
 *     Argument keyPtr: uint8* is of type Csm_KeyDataType_Ssa_SignatureRamKey
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_BUSY, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_NOT_AVAILABLE, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_WRITE_FAIL, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_SMALL_BUFFER, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_E_NOT_OK
 *   Std_ReturnType Rte_Call_Key_SignatureRamKey_KeySetValid(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_BUSY, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_CertP_Certificate_Verify_Extended(const uint8 *rawCertData, CertP_ParsedCertStructureType *parsedCert, const uint8 *rawCertIssuer, const CertP_ParsedCertStructureType *parsedCertIssuer, CertP_PkiRoleType expectedPkiRole, const RightsM_AuthNonceType *expectedNonce)
 *     Argument rawCertData: uint8* is of type CertP_RawCertBufferType
 *     Argument rawCertIssuer: uint8* is of type CertP_RawCertBufferType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CertP_Functions_E_NOT_OK
 *   RTE_E_CertP_Functions_E_PENDING
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_Certificate_Verify_Extended_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(rawCertData) >= sizeof(CertP_RawCertBufferType);
 *    requires $lengthOf(rawCertIssuer) >= sizeof(CertP_RawCertBufferType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_CertP_CODE) Ssa_CertP_Certificate_Verify_Extended(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertIssuer,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer,
  CertP_PkiRoleType expectedPkiRole,
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) expectedNonce) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_Certificate_Verify_Extended (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_CertP_Functions_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((rawCertData == NULL_PTR) || (parsedCert == NULL_PTR) ||
      (rawCertIssuer == NULL_PTR) || (parsedCertIssuer == NULL_PTR) ||
      (expectedNonce == NULL_PTR))
  {
  /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Pass arguments to local function for certificate verification. */
    retVal = CertP_Certificate_Verify( /* VCA_SSA_CERTP_RAW_CERT_LENGTH */
      rawCertData,
      parsedCert,
      rawCertIssuer,
      parsedCertIssuer,
      expectedPkiRole,
      expectedNonce);
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_CertP_CsmCallbackNotification_SignatureVerify
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CallbackNotification> of PortPrototype <CallbackNotification_SignatureVerify>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Ssa_CertP_CsmCallbackNotification_SignatureVerify(Csm_ResultType result)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_CsmCallbackNotification_SignatureVerify_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_CertP_CODE) Ssa_CertP_CsmCallbackNotification_SignatureVerify(Csm_ResultType result) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_CsmCallbackNotification_SignatureVerify
 *********************************************************************************************************************/
  /* #10 Handle the Csm signature verify state dependent on the callback's result only if a callback is awaited. */
  if (CertP_CsmSignatureVerifyState == SSA_ASYNC_STATE_WAIT)
  {
    if (result == E_OK)
    {
      CertP_CsmSignatureVerifyState = SSA_ASYNC_STATE_READY;
    }
    else
    {
      CertP_CsmSignatureVerifyState = SSA_ASYNC_STATE_FAILED;
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_CertP_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_Init_doc
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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_CertP_CODE) Ssa_CertP_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_Init
 *********************************************************************************************************************/

  /* #10 Initialize static variables for asynchronous state handling. */
  CertP_CsmSignatureVerifyState = SSA_ASYNC_STATE_IDLE;
  CertP_Certificate_Verify_Runnable_State = CERTP_ASYNC_STATE_IDLE;

  /* Ensure type sizes once for the CertP submodule which calls RTE APIs expecting these data types:
   * Coding_VINDataType must be an array with 17 element(s) of type uint8 */
  /*@ assert sizeof(Coding_VINDataType) == 17; */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_CertP_ParseTime
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ParseTime> of PortPrototype <CertP_Functions>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_CertP_ParseTime(const uint8 *data, uint16 dataLength, TimeM_DateTimeType *dateTime)
 *     Argument data: uint8* is of type Ssa_Data15ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CertP_Functions_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_ParseTime_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_CertP_CODE) Ssa_CertP_ParseTime(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) data,
  uint16 dataLength,
  P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) dateTime) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_CertP_ParseTime (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_CertP_Functions_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((data == NULL_PTR) || (dateTime == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    CertP_TimeType parsedTime;
    CertP_BerElementType elementToParse;

    /* set element */
    elementToParse.validContent = TRUE;
    elementToParse.elemDataIdx = 0u;
    elementToParse.elemDataLength = dataLength;

    /* parse */
    if (CertP_ParseTime(data, (P2VAR(CertP_TimeType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR))&parsedTime, elementToParse) == E_OK)
    {
      *dateTime = parsedTime.dateTime;
      retVal = RTE_E_OK;
    }
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Ssa_CertP_STOP_SEC_CODE
#include "Ssa_CertP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define Ssa_CertP_START_SEC_CODE
#include "Ssa_CertP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CertP_BerInitWorkspace
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_CERTP_LOCAL FUNC(void, Ssa_CertP_CODE) CertP_BerInitWorkspace(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  CONSTP2VAR(CertP_BerStackElementType, AUTOMATIC, AUTOMATIC) StackPtr,
  const uint8 Depth)
{
  /* #10 Initialize the workspace data elements. */
  WorkspacePtr->LastData = NULL_PTR;
  WorkspacePtr->LastDataSize = 0u;
  WorkspacePtr->Stack = StackPtr;
  WorkspacePtr->CurrentDepth = 0u;
  WorkspacePtr->MaxDepth = Depth;
}

/**********************************************************************************************************************
 *  CertP_BerGetElement_ValidityChecks
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
 *
 *
  */
SSA_CERTP_LOCAL FUNC(uint8, Ssa_CertP_CODE) CertP_BerGetElement_ValidityChecks(
  CONSTP2CONST(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth)
{
  uint8 Res = E_OK;

  /* #10 Check that workspace stack is available. */
  if (0u == WorkspacePtr->MaxDepth)
  {
    /* no stack */
    Res = CERTP_BER_E_MEM;
  }
  /* #20 Check that an element to get is specified. */
  else if (0u == ElementDepth)
  {
    /* no element specified */
    Res = E_NOT_OK;
  }
  /* #30 Check that the remaining workspace stack is sufficient for the element that shall be get. */
  else if (WorkspacePtr->MaxDepth < ElementDepth)
  {
    /* stack depth insufficient */
    Res = CERTP_BER_E_MEM;
  }
  /* #40 Check for a valid element number. */
  else if (0u == ElementNrPtr[0])
  {
    /* invalid ElementNr */
    Res = E_NOT_OK;
  }
  else
  {
    /* do nothing */
  }

  return Res;
}

/**********************************************************************************************************************
 *  CertP_BerGetElement_Core
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
SSA_CERTP_LOCAL FUNC(uint8, Ssa_CertP_CODE) CertP_BerGetElement_Core(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) ElementPtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  const uint32 DataSize)
{
  /*@ assert $lengthOf(ElementNrPtr) >= ElementDepth; */
  /*@ assert ElementDepth <= CERTP_MAX_DEPTH_OF_ONE_ELEMENT; */

  uint8 Res = E_OK;
  P2VAR(CertP_BerStackElementType, AUTOMATIC, AUTOMATIC) StackElementPtr;
  uint8 Level;
  uint8 currentDepthLocalCounter = 0u;

  /* #10 Reset the workspace. */
  WorkspacePtr->LastData = DataPtr;
  WorkspacePtr->LastDataSize = DataSize;
  WorkspacePtr->CurrentDepth = 1u;
  WorkspacePtr->Stack[0].CurrentBlock.Idx = 0u;
  WorkspacePtr->Stack[0].CurrentBlock.EndIdx = DataSize;
  WorkspacePtr->Stack[0].CurrentIdx = 0u;
  WorkspacePtr->Stack[0].CurrentElementNr = 0u;
  Level = (uint8)(WorkspacePtr->CurrentDepth - 1u);
  /*@ assert WorkspacePtr->CurrentDepth == 1u; */
  /*@ assert Level == 0u; */

  /*@ assert $lengthOf(WorkspacePtr->Stack) >= CERTP_MAX_DEPTH_OF_ONE_ELEMENT; */
  StackElementPtr = &WorkspacePtr->Stack[Level];
  /*@ assert StackElementPtr == &WorkspacePtr->Stack[0]; */

  /* #20 Search chapter-by-chapter through the data as long as
   * no error occurred,
   * the searched element has not been found,
   * the element number is valid. */
  for (currentDepthLocalCounter = 0u; currentDepthLocalCounter < ElementDepth; currentDepthLocalCounter++) /* FETA_SSA_CERTP_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
  {
    /* Checks were removed from loop conditions and checked separately to facilitate FETA. */
    if (((Res == E_OK) && (ElementNrPtr[Level] > 0u)))
    {
      /*@ assert Level < CERTP_MAX_DEPTH_OF_ONE_ELEMENT; */
      /*@ assert StackElementPtr == &WorkspacePtr->Stack[Level]; */ /* VCA_SSA_CERTP_LEVEL_OF_CERT_ELEMENT */
      /* #30 Read within the chapter element-by-element until the searched chapter is found.*/
      for (StackElementPtr->CurrentElementNr = 0u; StackElementPtr->CurrentElementNr < ElementNrPtr[Level]; StackElementPtr->CurrentElementNr++) /* PRQA S 0771 */ /* MD_SSA_ADDITIONAL_BREAK */ /* FETA_SSA_CERTP_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
      {
        /* #35 Throw an error if end of block is reached. */
        if (StackElementPtr->CurrentBlock.EndIdx <= StackElementPtr->CurrentIdx)
        {
          /* reached end of Block */
          Res = E_NOT_OK;
          break;
        }
        else
        {
          /* read next element */
          Res = CertP_BerGetNextElement(&StackElementPtr->CurrentElement,
            StackElementPtr->CurrentIdx,
            &StackElementPtr->CurrentBlock, DataPtr);
          if (E_OK != Res)
          {
            break; /* PRQA S 0771 */ /* MD_SSA_ADDITIONAL_BREAK */
          }
          /* update index, the element counter is incremented in the for-loop */
          StackElementPtr->CurrentIdx = StackElementPtr->CurrentElement.EndIdx;
        }
      }

      /* #40 Proceed to the next chapter if the searched element is not yet found.  */
      if (Res == E_OK)
      {
        /* #50 Check the current depth of the workspace. Is it below the element depth the element is not yet found. */
        if (ElementDepth > WorkspacePtr->CurrentDepth)
        {
          /*@ assert WorkspacePtr->CurrentDepth <= 4; */
          /*@ assert Level == (WorkspacePtr->CurrentDepth - 1u); */ /* VCA_SSA_CERTP_LEVEL_OF_CERT_ELEMENT */

          /* #60 Before proceeding to next chapter check that the current element is not a primitive element. */
          if ((CertP_BerIsPrimitive(StackElementPtr->CurrentElement.Type)) &&
            (!CertP_BerIsOctetString(StackElementPtr->CurrentElement.Type)))
          {
            /* primitive element, cannot increase level */
            Res = E_NOT_OK;
          }
          else
          {
            /* increase level */
            Level++;
            WorkspacePtr->Stack[Level].CurrentBlock.Idx = StackElementPtr->CurrentElement.ContentIdx;
            WorkspacePtr->Stack[Level].CurrentBlock.EndIdx = StackElementPtr->CurrentElement.EndIdx;
            WorkspacePtr->Stack[Level].CurrentIdx = StackElementPtr->CurrentElement.ContentIdx;
            WorkspacePtr->Stack[Level].CurrentElementNr = 0u;
            StackElementPtr = &WorkspacePtr->Stack[Level];
            WorkspacePtr->CurrentDepth++;
          }
        }
        else
        {
          /* element found */
          *ElementPtr = StackElementPtr->CurrentElement;

          /* In this branch it holds that WorkspacePtr->CurrentDepth = ElementDepth.
           * Currently, i.e., right here, it still holds that
           * currentDepthLocalCounter = ((WorkspacePtr->CurrentDepth) - 1).
           * At the end of the for-loop's body, currentDepthLocalCounter is incremented, i.e., then it holds that
           * currentDepthLocalCounter = (WorkspacePtr->CurrentDepth) = ElementDepth. 
           * Thus, the for-loop will not be entered again. */
        }
      }
    }
    else
    {
      break;
    }
  }

  return Res;
} /* PRQA S 6060, 6080 */ /* MD_SSA_STPAR, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  CertP_BerGetElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_CERTP_LOCAL FUNC(uint8, Ssa_CertP_CODE) CertP_BerGetElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) ElementPtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  const uint32 DataSize)
{
  /* #10 Check validity of input parameters. */
  uint8 Res = CertP_BerGetElement_ValidityChecks(WorkspacePtr, ElementNrPtr, ElementDepth);

  /* #20 Continue only if all checks passed. */
  if (Res == E_OK)
  {
    /* #30 Call CertP_BerGetElement_Core to extract the element data. */
    Res = CertP_BerGetElement_Core(WorkspacePtr, ElementPtr, ElementNrPtr, ElementDepth, DataPtr, DataSize);
  }

  return Res;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_BerGetNextElement
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
SSA_CERTP_LOCAL_INLINE FUNC(uint8, Ssa_CertP_CODE) CertP_BerGetNextElement(
  CONSTP2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) Element,
  uint32 ElementIdx,
  CONSTP2CONST(CertP_BerBlockType, AUTOMATIC, AUTOMATIC) Block,
  CONSTP2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) Data)
{
  uint8 Res = E_OK;
  uint32 ContentSize;
  uint8 SizeOfLen;
  uint32 elemIdx = ElementIdx;

  /* #10 Check that the next element to be gotten is not outside the block or crosses its boundary. */
  if (Block->EndIdx < (elemIdx + 2u))
  {
    /* Element outside Block or crosses boundary */
    Res = CERTP_BER_E_BER_PARAM;
  }
  else
  {
    Element->Idx = elemIdx;
    Element->Type = Data[elemIdx];
    elemIdx++;
    SizeOfLen = Data[elemIdx];
    elemIdx++;

    /* #20 Check if the element for extended length. */
    if (0u == CERTP_BER_IS_EXTENDED_LEN(SizeOfLen))
    {
      /* #30 Set the element index increased by element length as end index. */
      Element->EndIdx = elemIdx + SizeOfLen;
    }
    else
    {
      /* #40 In case of extended length calculate the content length and with the content length the end index.
       * If the content length is encoded using more than 4 bytes throw an error.  */
      SizeOfLen &= 0x7Fu;

      if (Block->EndIdx < (elemIdx + SizeOfLen))
      {
        /* Length field exceeds block */
        Res = CERTP_BER_E_BER_PARAM;
      }
      else
      {
        ContentSize = 0u;
        switch (SizeOfLen)
        {
        case 3:
          /* Initially content size is 0. */
          ContentSize = Data[elemIdx];
          elemIdx++;
          ContentSize <<= 8;
          /* Fall through. */
          /* PRQA S 2003 1 */ /* MD_SSA_SWITCH_FALLTHROUGH */
        case 2:
          ContentSize |= Data[elemIdx];
          elemIdx++;
          ContentSize <<= 8;
          /* Fall through. */
          /* PRQA S 2003 1 */ /* MD_SSA_SWITCH_FALLTHROUGH */
        case 1:
          ContentSize |= Data[elemIdx];
          elemIdx++;
          Element->EndIdx = elemIdx + ContentSize;
          if (Block->EndIdx < Element->EndIdx)
          {
            /* Element crosses block boundary */
            Res = CERTP_BER_E_BER_PARAM;
          }
          break;

        default:
          /* 0: indefinite length, not implemented */
          /* >=4: length of content larger than or equal to uint32 */
          Res = CERTP_BER_E_BER_PARAM;
          break;
        }
      }
    } /* end of if (0 == CERTP_BER_IS_EXTENDED_LEN(SizeOfLen))*/

    if (Res == E_OK)
    {
      Element->ContentIdx = elemIdx;
    }
  }

  return Res;
} /* PRQA S 6010, 6080 */ /* MD_MSR_STPTH, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  CertP_CompareBerElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_CERTP_LOCAL FUNC(boolean, Ssa_CertP_CODE) CertP_CompareBerElement(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBufferElem1,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem1,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBufferElem2,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem2)
{
  boolean ret = TRUE;
  uint16 i;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem1Ptr = &(rawCertBufferElem1[elem1->elemDataIdx]);
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem2Ptr = &(rawCertBufferElem2[elem2->elemDataIdx]);

  /* #10 Check that both elements have a valid content.*/
  if ((elem1->validContent == FALSE) || (elem2->validContent == FALSE))
  {
    ret = FALSE;
  }
  else if (elem1->elemDataLength == elem2->elemDataLength)
  {
    /* #20 Compare the elements' content byte-by-byte. Return false once a difference is detected. */
    for (i = 0u; i < elem1->elemDataLength; i++) /* FETA_SSA_CERTP_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
    {
      if (elem1Ptr[i] != elem2Ptr[i])
      {
        ret =  FALSE;
        break;
      }
    }
  }
  else
  {
    ret = FALSE;
  }

  return ret;
}

/**********************************************************************************************************************
 *  CertP_CheckBerElementsForDifference_Cond
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_CERTP_LOCAL FUNC(boolean, Ssa_CertP_CODE) CertP_CheckBerElementsForDifference_Cond(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBufferElem1,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem1,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBufferElem2,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem2,
  boolean cond)
{
  boolean ret = FALSE;
  /* #10 Check that passed condition is fulfilled. */
  if (cond == TRUE)
  {
    /* #20 Compare both elements and return the inverted boolean result. */
    ret = (boolean)((CertP_CompareBerElement(rawCertBufferElem1, elem1, rawCertBufferElem2, elem2) == TRUE) ? FALSE : TRUE);
  }
  return ret;
}

/**********************************************************************************************************************
 *  CertP_FindStringInSetOfUTF8Strings
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
SSA_CERTP_LOCAL FUNC(boolean, Ssa_CertP_CODE) CertP_FindStringInSetOfUTF8Strings(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) stringToFind,
  uint8 lengthStrToFind,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBuffer,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) setOfUTF8Strings)
{
  boolean isEqual = FALSE;
  uint16 startIdxOfCurrentUTF8String = setOfUTF8Strings->elemDataIdx;
  uint32 retrievedLengthOfCurrentUTF8String = 0u;

  /* #10 Iterate through the set of UTF8 strings element-by-element as long as
    * the searched string is not found,
    * the iteration's element tag is UTF8_STRING and
    * the iteration's element size is less than 128. */
  /* Hint: The second condition asserts that the rawCertBuffer is accessed at valid
   * indices in the last two conditions. */
  while ((!isEqual) && ((retrievedLengthOfCurrentUTF8String + 2u) < setOfUTF8Strings->elemDataLength)) /* PRQA S 0771 */ /* MD_SSA_ADDITIONAL_BREAK */ /* FETA_SSA_CERTP_WHILE_LOOP_WITH_UNCHANGED_UPPER_BOUND_AND_ADDITIONAL_BREAKS */
  {
    /* Checks were removed from while-conditions and checked separately to facilitate FETA. */
    if ((rawCertBuffer[startIdxOfCurrentUTF8String] == CERTP_ASN1_TAG_UTF8_STRING) && ((rawCertBuffer[startIdxOfCurrentUTF8String + 1u] & 0x80u) == 0x00u))
    {
      uint8 sizeEntry = rawCertBuffer[startIdxOfCurrentUTF8String + 1u];

      /* Ensure that the current UTF8 string is completely contained in the element,
       * i.e., that the read length value is reasonable. */
      retrievedLengthOfCurrentUTF8String = (startIdxOfCurrentUTF8String + 2uL + sizeEntry - setOfUTF8Strings->elemDataIdx);

      if (retrievedLengthOfCurrentUTF8String <= setOfUTF8Strings->elemDataLength)
      {
        /* #20 First check for the correct string length than for the correct string. */
        if (lengthStrToFind == sizeEntry)
        {
          uint16 i;
          /* #30 Return only true if the complete string is found. */
          for (i = 0u; i < sizeEntry; i++) /* FETA_SSA_CERTP_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
          {
            if (rawCertBuffer[startIdxOfCurrentUTF8String + 2u + i] != stringToFind[i])
            {
              /* Not equal! */
              break;
            }
          }
          /* If the loop has not been quit early the strings must be equal. */
          if (i == sizeEntry)
          {
            isEqual = TRUE;
          }
        }

        /* Go to next entry.
         * Addition is safe / the index is still inside element boundaries due to the previous check. */
        startIdxOfCurrentUTF8String += (uint16)(2u + (uint16)sizeEntry);
      }
      else
      {
        break; /* PRQA S 0771 */ /* MD_SSA_ADDITIONAL_BREAK */
      }
    }
    else
    {
      break; /* PRQA S 0771 */ /* MD_SSA_ADDITIONAL_BREAK */
    }
  }

  return isEqual;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
*  CertP_CheckSetOfUTF8StringsAgainstUniqueEcuIds
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
*/
SSA_CERTP_LOCAL FUNC(boolean, Ssa_CertP_CODE) CertP_CheckSetOfUTF8StringsAgainstUniqueEcuIds(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBuffer,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) setOfUTF8Strings)
{
  boolean isEqual = FALSE;

  Ssa_UniqueEcuIdIterType i;

  /* #10 Iterate through the configured UniqueEcuIDs and search in the targetECU field of the certificate. */
  for (i = 0; i < Ssa_GetSizeOfUniqueEcuId(); ++i)
  {
    if (CertP_FindStringInSetOfUTF8Strings(
      Ssa_GetAddrUniqueEcuIds(Ssa_GetUniqueEcuIdsUniqueEcuIdsStartIdxOfUniqueEcuId(i)),
      (uint8)(Ssa_GetUniqueEcuIdsUniqueEcuIdsEndIdxOfUniqueEcuId(i) - Ssa_GetUniqueEcuIdsUniqueEcuIdsStartIdxOfUniqueEcuId(i)),
      rawCertBuffer,
      setOfUTF8Strings) == TRUE)
    {
      /* #20 Return true once an accordance is found. */
      isEqual = TRUE;
      break;
    }
  }

  return isEqual;
}

/**********************************************************************************************************************
 *  CertP_CompareManyBerElementSetOfUTF8Strings
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
SSA_CERTP_LOCAL FUNC(boolean, Ssa_CertP_CODE) CertP_CompareManyBerElementSetOfUTF8Strings(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBufferElem1,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem1,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertBufferElem2,
  P2CONST(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) elem2)
{
  boolean isEqual = FALSE;
  uint16 startIdxOfCurrentUTF8String = elem1->elemDataIdx;
  uint32 retrievedLengthOfCurrentUTF8String = 0u;

  /* #10 Check that both sets of UTF8 strings have valid contents. */
  if ((elem1->validContent == TRUE) && (elem2->validContent == TRUE))
  {
    /* #20 Iterate through the first set of UTF8 strings element-by-element as long as
     * the string of the iteration's element is not found in the second set of UT8 strings,
     * the iteration's element tag is UTF8_STRING and
     * the iteration's element size is less than 128. */
    /* Hint: The first condition asserts that the rawCertBufferElem1 is accessed at valid
     * indices in the second two conditions. */
    while ((retrievedLengthOfCurrentUTF8String + 2u) < elem1->elemDataLength) /* PRQA S 0771 */ /* MD_SSA_ADDITIONAL_BREAK */ /* FETA_SSA_CERTP_WHILE_LOOP_WITH_UNCHANGED_UPPER_BOUND_AND_ADDITIONAL_BREAKS */
    {
      /* Checks were removed from while-conditions and checked separately to facilitate FETA. */
      if ((rawCertBufferElem1[startIdxOfCurrentUTF8String] == CERTP_ASN1_TAG_UTF8_STRING) && ((rawCertBufferElem1[startIdxOfCurrentUTF8String + 1u] & 0x80u) == 0x00u))
      {
        uint8 sizeEntry = rawCertBufferElem1[startIdxOfCurrentUTF8String + 1u];
        /* Ensure that the current subelement/UTF8 string is completely contained in the element,
         * i.e., that the read length value is reasonable. */
        retrievedLengthOfCurrentUTF8String = (startIdxOfCurrentUTF8String + 2uL + sizeEntry - elem1->elemDataIdx);
        if (retrievedLengthOfCurrentUTF8String <= elem1->elemDataLength)
        {
          /* #30 Get each UTF8String of set 1 and search for it in set 2. */
          if (CertP_FindStringInSetOfUTF8Strings(&rawCertBufferElem1[startIdxOfCurrentUTF8String + 2u], sizeEntry, rawCertBufferElem2, elem2) == TRUE)
          {
            /* #40 Return true once a string has been found. */
            isEqual = TRUE;
            break;
          }
          /* Go to next entry.
           * Addition is safe / the index is still inside element boundaries due to the previous check. */
          startIdxOfCurrentUTF8String += 2u + (uint16)sizeEntry;
        }
        else
        {
          break; /* PRQA S 0771 */ /* MD_SSA_ADDITIONAL_BREAK */
        }
      }
      else
      {
        break;  /* PRQA S 0771 */ /* MD_SSA_ADDITIONAL_BREAK */
      }
    }
  }
  return isEqual;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  CertP_ParseTime
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
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseTime(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2VAR(CertP_TimeType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedTimePtr,
  CertP_BerElementType timeElement)
{
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) timeElementPtr = &(DataPtr[timeElement.elemDataIdx]);
  Std_ReturnType retVal = E_OK;

  /* Generally:
   * UTC Formats:
   *    YYMMDDhhmm[ss]Z
   *    YYMMDDhhmm[ss](+|-)hhmm
   *  Generalized Time Formats:
   *    YYYYMMDDHH[MM[SS[.fff]]]
   *    YYYYMMDDHH[MM[SS[.fff]]]Z
   *    YYYYMMDDHH[MM[SS[.fff]]](+|-)HHMM
   */

  /* #10 Only UTC or Generalized Time with non-optional minutes and seconds are supported,
   *  milliseconds [.fff] and difference to local time (+|-)HHMM is not supported. */

  /* #20 Check that last sign is a 'Z' 0x5A. */
  if (timeElementPtr[timeElement.elemDataLength - 1u] != 0x5Au)
  {
    retVal = E_NOT_OK;
  }

  if (retVal == E_OK)
  {
    /* #30 If the element data length is 13, extract the year according to the UTC format. */
    if (timeElement.elemDataLength == 13u)
    {
      /* UTC time with 2 digits Year */
      parsedTimePtr->dateTime.year = (uint16)(((uint16)timeElementPtr[0] - 0x30u) * 10u);
      parsedTimePtr->dateTime.year += (uint16)((uint16)timeElementPtr[1] - 0x30u);

      if (parsedTimePtr->dateTime.year >= 50u)
      {
        parsedTimePtr->dateTime.year += 1900u;
      }
      else
      {
        parsedTimePtr->dateTime.year += 2000u;
      }
      timeElementPtr = &(timeElementPtr[2]);
    }
    /* #40 If the element data length is 15, extract the year according to the Generalized Time format. */
    else if (timeElement.elemDataLength == 15u)
    {
      /* Generalized time with 4 digits Year */
      parsedTimePtr->dateTime.year = (uint16)(((uint16)timeElementPtr[0] - 0x30u) * 1000u);
      parsedTimePtr->dateTime.year += (uint16)(((uint16)timeElementPtr[1] - 0x30u) * 100u);
      parsedTimePtr->dateTime.year += (uint16)(((uint16)timeElementPtr[2] - 0x30u) * 10u);
      parsedTimePtr->dateTime.year += (uint16)((uint16)timeElementPtr[3] - 0x30u);
      timeElementPtr = &(timeElementPtr[4]);
    }
    else
    {
      /* invalid time format */
      retVal = E_NOT_OK;
    }
  }

  if (retVal == E_OK)
  {
    /* #50 Extract the remaining date and time information without differentiating between UTC and
     * Generalized Time format. */
    parsedTimePtr->dateTime.month = (uint8)((timeElementPtr[0] - 0x30u) * 10u);
    parsedTimePtr->dateTime.month += ((uint8)(timeElementPtr[1] - 0x30u));
    parsedTimePtr->dateTime.day = (uint8)((timeElementPtr[2] - 0x30u) * 10u);
    parsedTimePtr->dateTime.day += ((uint8)(timeElementPtr[3] - 0x30u));
    parsedTimePtr->dateTime.hour = (uint8)((timeElementPtr[4] - 0x30u) * 10u);
    parsedTimePtr->dateTime.hour += ((uint8)(timeElementPtr[5] - 0x30u));
    parsedTimePtr->dateTime.minute = (uint8)((timeElementPtr[6] - 0x30u) * 10u);
    parsedTimePtr->dateTime.minute += ((uint8)(timeElementPtr[7] - 0x30u));
    parsedTimePtr->dateTime.second = (uint8)((timeElementPtr[8] - 0x30u) * 10u);
    parsedTimePtr->dateTime.second += ((uint8)(timeElementPtr[9] - 0x30u));
  }

  return retVal;
}

/**********************************************************************************************************************
 *  CertP_ParseIssuerOrSubject
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
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseIssuerOrSubject(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2VAR(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedIssuerOrSubject,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) issuerSubjectElement)
{
  const uint8 subEleNrCommonNameOID[3] = { 1u, 1u, 1u };     /* chapter 1.1.x.1.1.1: issuer/subject commonName OID */
  const uint8 subEleNrValue[3] = { 1u, 1u, 2u };             /* chapter 1.1.x.1.1.2: issuer/subject value */
  const uint8 oidCommonName[3] = { 0x55u, 0x04u, 0x03u };
  Std_ReturnType retVal = E_NOT_OK;
  CertP_BaseBerElementType EleDesc;

  /* #10 Get the common name OID. */
  if (CertP_BerGetElement(WorkspacePtr, &EleDesc, subEleNrCommonNameOID, 3u, DataPtr, issuerSubjectElement->elemDataLength) != E_OK)
  {
    /* Error */
  }
  /* #20 Check the tag and the length of the common OID. */
  else if ((EleDesc.Type != CERTP_ASN1_TAG_OBJECT_IDENTIFIER) || ((EleDesc.EndIdx - EleDesc.ContentIdx) != 3u))
  {
    /* Error */
  }
  /* #30 Check common name OID. OID must have the value 2.5.4.3 */
  else if (CertP_IsEqual(&DataPtr[EleDesc.ContentIdx], oidCommonName, 3u) == FALSE)
  {
    /* Error */
  }
  else
  {
    retVal = E_OK;
  }

  /* common name value */
  if (retVal == E_OK)
  {
    /* #40 Get the common name value. */
    if (CertP_BerGetElement(WorkspacePtr, &EleDesc, subEleNrValue, 3u, DataPtr, issuerSubjectElement->elemDataLength) != E_OK)
    {
      retVal = E_NOT_OK;
    }
    /* #50 Check the tag. */
    else if (EleDesc.Type != CERTP_ASN1_TAG_UTF8_STRING)
    {
      retVal = E_NOT_OK;
    }
    else
    {
      /* #60 Extract the data index of the common name its length. */
      parsedIssuerOrSubject->elemDataIdx = (uint16)(issuerSubjectElement->elemDataIdx + (uint16)EleDesc.ContentIdx);
      parsedIssuerOrSubject->elemDataLength = (uint16)(EleDesc.EndIdx - EleDesc.ContentIdx);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  CertP_ParseExtension_OIDLength3
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
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseExtension_OIDLength3(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) Elem,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) extensionElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert)
{
  Std_ReturnType retVal = E_OK;

  const uint8 EleNr_2_1[2] = { 2u, 1u };
  const uint8 EleNr_3_1[2] = { 3u, 1u };
  const uint8 EleNr_3_1_2[3] = { 3u, 1u, 2u };

  /* 85.29.X */
  const uint8 oidBase[2u] = { 0x55, 0x1D };
  /* #10 Filter using the OID value for and extract the corresponding information: */
  if (CertP_IsEqual(&DataPtr[Elem->ContentIdx], oidBase, 2u) == TRUE)
  {
    switch (DataPtr[Elem->ContentIdx + 2u])
    {
      /* #20 Subject Key Identifier. */
    case 0x0Eu:
      /* Subject Key Identifier (X509 verify)
      * OID: id-ce 14 -> 2.5.29.14 -> 85.29.14 -> 0x55.0x1D.0x0E */
      if (CertP_BerGetElement(WorkspacePtr, Elem, EleNr_2_1, 2u, DataPtr, extensionElement->elemDataLength) != E_OK)
      {
        retVal = E_NOT_OK;
      }
      else
      {
        parsedCert->subjectKeyIdentifier.elemDataIdx = (uint16)(extensionElement->elemDataIdx + (uint16)Elem->ContentIdx);
        parsedCert->subjectKeyIdentifier.elemDataLength = (uint16)(Elem->EndIdx - Elem->ContentIdx);
        parsedCert->subjectKeyIdentifier.validContent = TRUE;
      }
      break;

      /* #30 Authority Key Identifier. */
    case 0x23u:
      /* Authority Key Identifier (X509 verify)
      * OID: id-ce 35 -> 2.5.29.35 -> 85.29.35 -> 0x55.0x1D.0x23 */
      if (CertP_BerGetElement(WorkspacePtr, Elem, EleNr_2_1, 2u, DataPtr, extensionElement->elemDataLength) != E_OK)
      {
        retVal = E_NOT_OK;
      }
      else
      {
        /* Content is not a sequence of content specific values. */
        parsedCert->authorityKeyIdentifier.elemDataIdx = (uint16)(extensionElement->elemDataIdx + (uint16)Elem->ContentIdx);
        parsedCert->authorityKeyIdentifier.elemDataLength = (uint16)(Elem->EndIdx - Elem->ContentIdx);
        /* Parse Content specific values. [0] is key Identifier of length 20 */
        if ((DataPtr[(uint16)Elem->ContentIdx] == 0x80u) &&
          (DataPtr[(uint16)Elem->ContentIdx + 1u] == 20u))
        {
          parsedCert->authorityKeyIdentifier.elemDataIdx = (uint16)(extensionElement->elemDataIdx + (uint16)Elem->ContentIdx + 2u);
          parsedCert->authorityKeyIdentifier.elemDataLength = 20u;
          parsedCert->authorityKeyIdentifier.validContent = TRUE;
        }
      }
      break;

      /* #40 Key Usage. */
    case 0x0Fu:
      /* Key Usage (Only for Root and Backend CA Certificate; must have the keyCertSign bit set)
      * OID: id-ce 15 -> 2.5.29.15 -> 85.29.15 -> 0x55.0x1D.0x0F */
      if (CertP_BerGetElement(WorkspacePtr, Elem, EleNr_3_1, 2u, DataPtr, extensionElement->elemDataLength) != E_OK)
      {
        retVal = E_NOT_OK;
      }
      else if ((Elem->EndIdx - Elem->ContentIdx) < 2uL)
      {
        retVal = E_NOT_OK;
      }
      else
      {
        /* First byte of a BIT String contains the padding bits at the end of the bit string. Content starts at byte 1 */
        parsedCert->keyUsage = (uint16)((uint16)DataPtr[Elem->ContentIdx + 1u] << 8u);
        if ((Elem->EndIdx - Elem->ContentIdx) > 2uL)
        {
          parsedCert->keyUsage |= (uint16)DataPtr[Elem->ContentIdx + 2u];
        }
      }
      break;

      /* #50 Basic constraints. */
    case 0x13u:
      /* Basic Constraints (Only for Root (pathLengthConstraint = 1) and Backend (pathLengthConstraint=0))
      * OID: id-ce 19 -> 2.5.29.19 -> 85.29.19 -> 0x55.0x1D.0x13 */
      if (CertP_BerGetElement(WorkspacePtr, Elem, EleNr_3_1_2, 3u, DataPtr, extensionElement->elemDataLength) != E_OK)
      {
        retVal = E_NOT_OK;
      }
      else if ((Elem->EndIdx - Elem->ContentIdx) != 1u)
      {
        retVal = E_NOT_OK;
      }
      else
      {
        parsedCert->basicConstraints = DataPtr[Elem->ContentIdx];
      }
      break;

    default:
      /* Ignore unknown OID (due to unknown OID byte 2) */
      break;
    }
  }
  else
  {
    /* Ignore unknown OID (due to unknown OID byte 0 - 1) */
  }

  return retVal;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  CertP_ParseExtension_UpdateRole
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
SSA_CERTP_LOCAL FUNC(uint8, Ssa_CertP_CODE) CertP_ParseExtension_UpdateRole(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) ElementPtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  const uint32 DataSize,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) Role)
{
  /* #10 Extract element information by calling CertP_BerGetElement. */
  Std_ReturnType retVal = CertP_BerGetElement(WorkspacePtr, ElementPtr, ElementNrPtr, ElementDepth, DataPtr, DataSize);

  /* #20 If call was successful, verify the retrieved length. */
  if (retVal == E_OK)
  {
    if ((ElementPtr->EndIdx - ElementPtr->ContentIdx) != CERTP_EXPECTED_ELEMENT_LENGTH)
    {
      retVal = E_NOT_OK;
    }
    /* #30 Update role with passed data. */
    else
    {
      *Role = DataPtr[ElementPtr->ContentIdx];
    }
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_ParseExtension_UpdateElement
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
SSA_CERTP_LOCAL FUNC(uint8, Ssa_CertP_CODE) CertP_ParseExtension_UpdateElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) ElementPtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) extensionElement,
  P2VAR(CertP_BerElementType, AUTOMATIC, AUTOMATIC) Element)
{
  /* #10 Extract element information by calling CertP_BerGetElement. */
  Std_ReturnType retVal = CertP_BerGetElement(WorkspacePtr, ElementPtr, ElementNrPtr, ElementDepth, DataPtr, extensionElement->elemDataLength);

  /* #20 If call was successful, verify that the length of the retrieved element is not 0. */
  if (retVal == E_OK)
  {
    if ((ElementPtr->EndIdx - ElementPtr->ContentIdx) == 0u)
    {
      retVal = E_NOT_OK;
    }
    /* #30 Update target element 'Element' with passed and retrieved length data. */
    else
    {
      Element->elemDataIdx = (uint16)(extensionElement->elemDataIdx + (uint16)ElementPtr->ContentIdx);
      Element->elemDataLength = (uint16)(ElementPtr->EndIdx - ElementPtr->ContentIdx);
      Element->validContent = TRUE;
    }
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_ParseExtension_OIDLength13
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
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseExtension_OIDLength13(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) Elem,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) extensionElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert)
{
  Std_ReturnType retVal = E_OK;

  const uint8 EleNr_2_1[2] = { 2u, 1u };
  const uint8 EleNr_3_1[2] = { 3u, 1u };

  /* 2B.06.01.04.01.96.64.03.06.83.7D.05.X */
  const uint8 oidBase[12u] = { 0x2B, 0x06, 0x01, 0x04, 0x01, 0x96, 0x64, 0x03, 0x06, 0x83, 0x7D, 0x05 };
  /* #10 Filter using the OID value for and extract the corresponding information: */
  if (CertP_IsEqual(&DataPtr[Elem->ContentIdx], oidBase, 12u) == TRUE)
  {
    switch (DataPtr[Elem->ContentIdx + 12u])
    {
      /* #20 PKI role. */
    case 0x65u:
      /* PKIRole (All Certs)
      * OID: 1.3.6.1.4.1.2916.3.6.509.5.101 -> 2B 06 01 04 01 96 64 03 06 83 7D 05 65 */
      retVal = CertP_ParseExtension_UpdateRole(WorkspacePtr, Elem, EleNr_3_1, 2u, DataPtr, extensionElement->elemDataLength, &(parsedCert->pkiRole));
      break;

      /* #30 User role. */
    case 0x66u:
      /* UserRole (Diag only)
      * OID 1.3.6.1.4.1.2916.3.6.509.5.102 -> 2B 06 01 04 01 96 64 03 06 83 7D 05 66 */
      /* User Role is specified to be exactly 1 byte */
      retVal = CertP_ParseExtension_UpdateRole(WorkspacePtr, Elem, EleNr_3_1, 2u, DataPtr, extensionElement->elemDataLength, &(parsedCert->userRole));
      break;

      /* #40 Target ECU. */
    case 0x68u:
      /* TargetECU (Diag and EnhanceRights only)
      * OID 1.3.6.1.4.1.2916.3.6.509.5.104 -> 2B 06 01 04 01 96 64 03 06 83 7D 05 68 */
      retVal = CertP_ParseExtension_UpdateElement(WorkspacePtr, Elem, EleNr_3_1, 2u, DataPtr, extensionElement, &(parsedCert->targetECU));
      break;

      /* #50 Target VIN. */
    case 0x69u:
      /* TargetVIN (Diag and EnhanceRights only)
      * OID 1.3.6.1.4.1.2916.3.6.509.5.105 -> 2B 06 01 04 01 96 64 03 06 83 7D 05 69 */
      retVal = CertP_ParseExtension_UpdateElement(WorkspacePtr, Elem, EleNr_3_1, 2u, DataPtr, extensionElement, &(parsedCert->targetVIN));
      break;

      /* #60 Nonce. */
    case 0x6Au:
      /* Nonce (Diag only)
      * OID 1.3.6.1.4.1.2916.3.6.509.5.106 -> 2B 06 01 04 01 96 64 03 06 83 7D 05 6A */
      retVal = CertP_ParseExtension_UpdateElement(WorkspacePtr, Elem, EleNr_3_1, 2u, DataPtr, extensionElement, &(parsedCert->nonce));
      break;

      /* #70 ProdQualifier. */
    case 0x6Bu:
      /* ProdQualifier (All Certs)
      * OID 1.3.6.1.4.1.2916.3.6.509.5.107 -> 2B 06 01 04 01 96 64 03 06 83 7D 05 6B */
      retVal = CertP_ParseExtension_UpdateRole(WorkspacePtr, Elem, EleNr_3_1, 2u, DataPtr, extensionElement->elemDataLength, &(parsedCert->prodQualifier));
      break;

      /* #80 uniqueECUID. */
    case 0x6Cu:
      /* uniqueECUID (ECU Cert Only)
      * OID 1.3.6.1.4.1.2916.3.6.509.5.108 -> 2B 06 01 04 01 96 64 03 06 83 7D 05 6C */
      retVal = CertP_ParseExtension_UpdateElement(WorkspacePtr, Elem, EleNr_3_1, 2u, DataPtr, extensionElement, &(parsedCert->uniqueEcuId));
      break;

      /* #90 SpecialECU. */
    case 0x6Du:
      /* SpecialECU (ECU Cert Only; critical)
      * OID 1.3.6.1.4.1.2916.3.6.509.5.109 -> 2B 06 01 04 01 96 64 03 06 83 7D 05 6D */
      retVal = CertP_ParseExtension_UpdateRole(WorkspacePtr, Elem, EleNr_3_1, 2u, DataPtr, extensionElement->elemDataLength, &(parsedCert->specialECU));
      break;

      /* #100 Target Subject Key Identifier. */
    case 0x6Fu:
      /* Target Subject Key Identifier
      * OID 1.3.6.1.4.1.2916.3.6.509.5.111 -> 2B 06 01 04 01 96 64 03 06 83 7D 05 6F */
      retVal = CertP_ParseExtension_UpdateElement(WorkspacePtr, Elem, EleNr_2_1, 2u, DataPtr, extensionElement, &(parsedCert->targetSubjectKeyIdentifier));
      break;

    default:
      /* Ignore unknown OID byte (due to unknown byte 12) */
      break;
    }
  }
  else
  {
    /* Ignore unknown OID (due to unknown OID byte 0 - 11) */
  }

  return retVal;
} /* PRQA S 6030 */ /* MD_MSR_STCYC */

/**********************************************************************************************************************
 *  CertP_ParseExtension
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
 *
 *
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseExtension(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) extensionElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert)
{
  const uint8 EleNrExtOid[1] = { 1u };
  Std_ReturnType retVal = E_OK;
  CertP_BaseBerElementType Elem;

  /* #10 Get the extension OID */
  if (CertP_BerGetElement(WorkspacePtr, &Elem, EleNrExtOid, 1u, DataPtr, extensionElement->elemDataLength) != E_OK)
  {
    retVal = E_NOT_OK;
  }
    /* #20 Check tag of the element for OID. */
  else if (DataPtr[Elem.Idx] != CERTP_ASN1_TAG_OBJECT_IDENTIFIER)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* Continue. */
  }

  if (retVal == E_OK)
  {
    /* #30 If the OID length is 3. */
    if (DataPtr[Elem.Idx + 1u] == 3u)
    {
      retVal = CertP_ParseExtension_OIDLength3(WorkspacePtr, &Elem, DataPtr, extensionElement, parsedCert);
    }
    /* #100 Else if the OID length is 13. */
    else if (DataPtr[Elem.Idx + 1u] == 13u)
    {
      retVal = CertP_ParseExtension_OIDLength13(WorkspacePtr, &Elem, DataPtr, extensionElement, parsedCert);
    }
    /* #210 Else ignore the element due to unknown OID length. */
    else
    {
      /* Ignore unknown OID (due to unknown length) */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  CertP_ParseAttribute
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
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseAttribute(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC)  attributeElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert)
{
  const uint8 EleNrAttributeOid[1] = { 1 };
  Std_ReturnType retVal = E_OK;
  CertP_BaseBerElementType Elem;

  /* #10 Get attribute OID. */
  if (CertP_BerGetElement(WorkspacePtr, &Elem, EleNrAttributeOid, 1u, DataPtr, attributeElement->elemDataLength) != E_OK)
  {
    retVal = E_NOT_OK;
  }
  /* #20 Check tag if the element is an OID. */
  else if (DataPtr[Elem.Idx] != CERTP_ASN1_TAG_OBJECT_IDENTIFIER)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* Continue. */
  }

  if (retVal == E_OK)
  {
    /* #30 Check OID for length 13, ignore other lengths. */
    if (DataPtr[Elem.Idx + 1u] == 13u)
    {
      /* OID:  1.3.6.1.4.1.2916.3.6.509.5.103 -> 2B 06 01 04 01 96 64 03  06 83 7D 05 67 */
      const uint8 oidServices[13u] = { 0x2B, 0x06, 0x01, 0x04, 0x01, 0x96, 0x64, 0x03, 0x06, 0x83, 0x7D, 0x05, 0x67 };
      /* #40 Check the OID value for the Services OID, ignore other OIDs. */
      if (CertP_IsEqual(&DataPtr[Elem.ContentIdx], oidServices, 13u) == TRUE)
      {
        const uint8 EleNrValue[1] = { 2 };
        /* #50 Extract the element data index and the length. */
        if (CertP_BerGetElement(WorkspacePtr, &Elem, EleNrValue, 1u, DataPtr, attributeElement->elemDataLength) == E_OK)
        {
          parsedCert->service.elemDataIdx = (uint16)(attributeElement->elemDataIdx + (uint16)Elem.ContentIdx);
          parsedCert->service.elemDataLength = (uint16)(Elem.EndIdx - Elem.ContentIdx);
          parsedCert->service.validContent = TRUE;
        }
        else
        {
          retVal = E_NOT_OK;
        }
      }
      else
      {
        /* Ignore unknown OID */
      }
    }
    else
    {
      /* Ignore unknown OID */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  CertP_ParseVersionElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseVersionElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) versionPtr)
{
  CertP_BaseBerElementType    EleDesc;
  Std_ReturnType retVal = E_OK;

  /* #10 Get the version element. */
  if (CertP_BerGetElement(WorkspacePtr, &EleDesc, ElementNrPtr, ElementDepth, DataPtr, superElement->elemDataLength) != E_OK)
  {
    retVal = E_NOT_OK;
  }
  /* #20 Check for tag INTEGER. */
  else if (EleDesc.Type != CERTP_ASN1_TAG_INTEGER)
  {
    retVal = E_NOT_OK;
  }
  /* #30 Check the length for 1. */
  else if ((EleDesc.EndIdx - EleDesc.ContentIdx) != 1u)
  {
    retVal = E_NOT_OK;
  }
  /* #40 Extract the version. */
  else
  {
    *versionPtr = DataPtr[EleDesc.ContentIdx];
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_ParseStandardElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseStandardElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  const uint8 ElementTag,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) subElement)
{
  CertP_BaseBerElementType    EleDesc;
  Std_ReturnType retVal = E_OK;

  /* #10 Get the requested element. */
  if (CertP_BerGetElement(WorkspacePtr, &EleDesc, ElementNrPtr, ElementDepth, DataPtr, superElement->elemDataLength) != E_OK)
  {
    retVal = E_NOT_OK;
  }
  /* #20 Check for correct tag. */
  else if (EleDesc.Type != ElementTag)
  {
    retVal = E_NOT_OK;
  }
  /* #30 Extract the data index and length of the element and validate the content flag. */
  else
  {
    subElement->elemDataIdx = (uint16)(superElement->elemDataIdx + (uint16)EleDesc.ContentIdx);
    subElement->elemDataLength = (uint16)(EleDesc.EndIdx - EleDesc.ContentIdx);
    subElement->validContent = TRUE;
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_ParsePublicKeyElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParsePublicKeyElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) publicKeyElement)
{
  Std_ReturnType retVal = E_OK;

  /* #10 Parse the passed element as BIT_STRING element. */
  if (CertP_ParseStandardElement(WorkspacePtr, ElementNrPtr, ElementDepth, CERTP_ASN1_TAG_BIT_STRING, DataPtr, superElement, publicKeyElement) == E_OK)
  {
    /* #20 Remove leading 0x00 from public key and check its length. */
    if ((DataPtr[publicKeyElement->elemDataIdx - superElement->elemDataIdx] == 0x00u) && (publicKeyElement->elemDataLength == (SSA_SIZEOF_PUBLICKEY + 1u)))
    {
      publicKeyElement->elemDataIdx++;
      publicKeyElement->elemDataLength = SSA_SIZEOF_PUBLICKEY;
    }
    else
    {
      /* The public key is expected to start with a leading zero, where the 0-byte indicates that no bits in the last
       * byte of the key are unused/do not belong to the public key. The public key is expected to be 32 bytes long,
       * no 'partial bytes' are used. Thus, if this condition is violated, the validContent flag is set back to FALSE. */
      publicKeyElement->validContent = FALSE;
      retVal = E_NOT_OK;
    }
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_ParseTimeElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseTimeElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_TimeType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedTimeElement)
{
  CertP_BaseBerElementType    EleDesc;
  Std_ReturnType retVal = E_OK;

  /* #10 Get the requested element. */
  if (CertP_BerGetElement(WorkspacePtr, &EleDesc, ElementNrPtr, ElementDepth, DataPtr, superElement->elemDataLength) == E_OK)
  {
    uint16 elemDataLength = (uint16)(EleDesc.EndIdx - EleDesc.ContentIdx);

    /* #20 Check that the tag is either UTC_TIME or GENERALIZED_TIME and that the corresponding data length is correct. */
    if (((EleDesc.Type == CERTP_ASN1_TAG_UTC_TIME) && (elemDataLength == CERTP_ASN1_UTC_TIME_LENGTH)) || ((EleDesc.Type == CERTP_ASN1_TAG_GENERALIZED_TIME) && (elemDataLength == CERTP_ASN1_GENERALIZED_TIME_LENGTH)))
    {
      /* #30 Extract the date time information. */
      CertP_BerElementType timeElement;
      timeElement.elemDataIdx = (uint16)EleDesc.ContentIdx;
      timeElement.elemDataLength = elemDataLength;
      if (CertP_ParseTime(DataPtr, parsedTimeElement, timeElement) == E_OK)
      {
        parsedTimeElement->validContent = TRUE;
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_ParseIssuerOrSubjectElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseIssuerOrSubjectElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_BerElementType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedIssuerOrSubjectElement)
{
  CertP_BaseBerElementType    EleDesc;
  Std_ReturnType retVal = E_OK;

  /* #10 Get the requested element. */
  if (CertP_BerGetElement(WorkspacePtr, &EleDesc, ElementNrPtr, ElementDepth, DataPtr, superElement->elemDataLength) == E_OK)
  {
    CertP_BerElementType issuerElement;

    /* #20 Extract the issuer or subject. */
    issuerElement.elemDataIdx = (uint16)superElement->elemDataIdx + (uint16)EleDesc.ContentIdx;
    issuerElement.elemDataLength = (uint16)(EleDesc.EndIdx - EleDesc.ContentIdx);
    if (CertP_ParseIssuerOrSubject(WorkspacePtr, &DataPtr[EleDesc.ContentIdx], parsedIssuerOrSubjectElement, &issuerElement) == E_OK)
    {
      parsedIssuerOrSubjectElement->validContent = TRUE;
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_ParseAttributesElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseAttributesElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert)
{
  Std_ReturnType retVal = E_OK;
  CertP_BaseBerElementType    EleDesc;

  /* #10 Get the requested element. */
  if (CertP_BerGetElement(WorkspacePtr, &EleDesc, ElementNrPtr, ElementDepth, DataPtr, superElement->elemDataLength) != E_OK)
  {
    retVal = E_NOT_OK;
  }
  /* #20 Check the element tag for SEQUENCE. */
  else if (EleDesc.Type != CERTP_ASN1_TAG_SEQUENCE)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    const uint8 EleNrAttribute[1] = { 1 };
    CertP_BerElementType attributeSequence;
    P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) attributeSequencePtr;
    attributeSequence.elemDataIdx = superElement->elemDataIdx + (uint16)EleDesc.ContentIdx;
    attributeSequencePtr = &(DataPtr[(uint16)EleDesc.ContentIdx]);
    attributeSequence.elemDataLength = (uint16)(EleDesc.EndIdx - EleDesc.ContentIdx);

    /* #30 Iterate through all sequence elements as long as no error occurs. */
    while ((attributeSequence.elemDataLength > 0u) && (retVal == E_OK)) /* FETA_SSA_CERTP_PARSING_MANY_SUBELEMENTS_OF_A_SUPERELEMENT */
    {
      if (CertP_BerGetElement(WorkspacePtr, &EleDesc, EleNrAttribute, 1u, attributeSequencePtr, attributeSequence.elemDataLength) == E_OK)
      {
        CertP_BerElementType attribute;
        attribute.elemDataIdx = attributeSequence.elemDataIdx + (uint16)EleDesc.ContentIdx;
        attribute.elemDataLength = (uint16)(EleDesc.EndIdx - EleDesc.ContentIdx);
        /* #40 Parse the iteration's element as attribute element. */
        if (CertP_ParseAttribute(WorkspacePtr, &attributeSequencePtr[EleDesc.ContentIdx], &attribute, parsedCert) == E_OK)
        {
          uint16 parsedAttributeBytes = (uint16)(EleDesc.EndIdx - EleDesc.Idx);
          attributeSequence.elemDataIdx += parsedAttributeBytes;
          attributeSequencePtr = &(attributeSequencePtr[parsedAttributeBytes]);
          if (attributeSequence.elemDataLength > parsedAttributeBytes)
          {
            attributeSequence.elemDataLength -= parsedAttributeBytes;
          }
          else
          {
            attributeSequence.elemDataLength = 0u;
          }
        }
        else
        {
          retVal = E_NOT_OK;
        }
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
  }

  return retVal;
} /* PRQA S 6060, 6080 */ /* MD_SSA_STPAR, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  CertP_ParseExtensionsElement_Tbs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseExtensionsElement_Tbs(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert)
{
  Std_ReturnType retVal = E_NOT_OK;
  CertP_BaseBerElementType    EleDesc;

  /* #10 Get the requested element. */
  if (CertP_BerGetElement(WorkspacePtr, &EleDesc, ElementNrPtr, 1u, DataPtr, superElement->elemDataLength) == E_OK)
  {
    /* #20 Check that the element has tag 0xA3. */
    if (EleDesc.Type == CERTP_ASN1_TAG_CONTEXT_STRUCT_3)
    {
      /* #30 Parse the extensions element. */
      retVal = CertP_ParseExtensionsElement(WorkspacePtr, ElementNrPtr, ElementDepth, DataPtr, superElement, parsedCert);
    }
  }
  else
  {
    /* There is no extensions element. */
    retVal = E_OK;
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_ParseExtensionsElement_AttributeCert
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
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseExtensionsElement_AttributeCert(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr1,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr2,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert)
{
  Std_ReturnType retVal;
  CertP_BaseBerElementType    EleDesc;
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr = ElementNrPtr1;
  boolean extElementSet = FALSE;

  /* #10 Get the first requested element, which is an optional element.*/
  if (CertP_BerGetElement(WorkspacePtr, &EleDesc, ElementNrPtr1, 1u, DataPtr, superElement->elemDataLength) == E_OK)
  {
    /* #20 If the element has tag SEQUENCE it is the extensions element. */
    if (EleDesc.Type == CERTP_ASN1_TAG_SEQUENCE)
    {
      extElementSet = TRUE;
    }
  }

  /* #30 Continue only if the extensions element is not yet found. */
  if (!extElementSet)
  {
    /* #40 Get the second requested element, which is an optional element.*/
    if (CertP_BerGetElement(WorkspacePtr, &EleDesc, ElementNrPtr2, 1u, DataPtr, superElement->elemDataLength) == E_OK)
    {
      /* #50 If the element has tag SEQUENCE it is the extensions element. */
      if (EleDesc.Type == CERTP_ASN1_TAG_SEQUENCE)
      {
        ElementNrPtr = ElementNrPtr2;
        extElementSet = TRUE;
      }
    }
  }

  /* #60 If an extensions element has been found, parse it. */
  if (extElementSet == TRUE)
  {
    retVal = CertP_ParseExtensionsElement(WorkspacePtr, ElementNrPtr, ElementDepth, DataPtr, superElement, parsedCert);
  }
  else
  {
    /* There is no extensions element. */
    retVal = E_OK;
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_ParseExtensionsElement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseExtensionsElement(
  CONSTP2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) ElementNrPtr,
  const uint8 ElementDepth,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) superElement,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert)
{
  Std_ReturnType retVal = E_OK;
  CertP_BaseBerElementType    EleDesc;

  /* #10 Get the requested element. */
  if (CertP_BerGetElement(WorkspacePtr, &EleDesc, ElementNrPtr, ElementDepth, DataPtr, superElement->elemDataLength) != E_OK)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    const uint8 EleNrFirstExtension[1] = { 1 };
    CertP_BerElementType extensionsSequence;
    P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) extensionsSequencePtr;
    extensionsSequence.elemDataIdx = superElement->elemDataIdx + (uint16)EleDesc.ContentIdx;
    extensionsSequencePtr = &DataPtr[(uint16)EleDesc.ContentIdx];
    extensionsSequence.elemDataLength = (uint16)(EleDesc.EndIdx - EleDesc.ContentIdx);

    /* #20 Iterate through all extension elements as long as no error occurs. */
    while ((retVal == E_OK) && (extensionsSequence.elemDataLength > 0u)) /* FETA_SSA_CERTP_PARSING_MANY_SUBELEMENTS_OF_A_SUPERELEMENT */
    {
      if (CertP_BerGetElement(WorkspacePtr, &EleDesc, EleNrFirstExtension, 1u, extensionsSequencePtr, extensionsSequence.elemDataLength) == E_OK)
      {
        CertP_BerElementType extension;
        extension.elemDataIdx = extensionsSequence.elemDataIdx + (uint16)EleDesc.ContentIdx;
        extension.elemDataLength = (uint16)(EleDesc.EndIdx - EleDesc.ContentIdx);

        /* #30 Parse the iteration's element as extension element. */
        if (CertP_ParseExtension(WorkspacePtr, &extensionsSequencePtr[EleDesc.ContentIdx], &extension, parsedCert) == E_OK)
        {
          uint16 parsedExtensionBytes = (uint16)(EleDesc.EndIdx - EleDesc.Idx);
          extensionsSequence.elemDataIdx += parsedExtensionBytes;
          extensionsSequencePtr = &(extensionsSequencePtr[parsedExtensionBytes]);
          if (extensionsSequence.elemDataLength > parsedExtensionBytes)
          {
            extensionsSequence.elemDataLength -= parsedExtensionBytes;
          }
          else
          {
            extensionsSequence.elemDataLength = 0u;
          }
        }
        else
        {
          retVal = E_NOT_OK;
        }
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
  }

  return retVal;
} /* PRQA S 6060, 6080 */ /* MD_SSA_STPAR, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  CertP_ParseInitializeCertificate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_CERTP_LOCAL FUNC(void, Ssa_CertP_CODE) CertP_ParseInitializeCertificate(
    P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) cert)
{
  /* #10 Initialize the parsed certificate data structure. Set verification result to "failed",
   * all elements valid flags to false and numeric values to 0xFF. */
  cert->verificationResult = CERTP_VER_PARSE_FAILED;
  cert->parsedCertLength = 0u;
  cert->signedCertData.validContent = FALSE;
  cert->version = 0xFFu;
  cert->serialNumber.validContent = FALSE;
  cert->certSignatureAlgOID.validContent = FALSE;
  cert->issuer.validContent = FALSE;
  cert->validNotBefore.validContent = FALSE;
  cert->validNotAfter.validContent = FALSE;
  cert->subject.validContent = FALSE;
  cert->publicKey.validContent = FALSE;

  cert->holderIssuer.validContent = FALSE;
  cert->holderSerialNumber.validContent = FALSE;
  cert->service.validContent = FALSE;

  /* Extensions */
  cert->pkiRole = 0xFFu;
  cert->subjectKeyIdentifier.validContent = FALSE;
  cert->authorityKeyIdentifier.validContent = FALSE;
  cert->targetSubjectKeyIdentifier.validContent = FALSE;
  cert->keyUsage = 0xFFFFu;
  cert->basicConstraints = 0xFF;
  cert->userRole = 0xFFu;
  cert->targetECU.validContent = FALSE;
  cert->targetVIN.validContent = FALSE;
  cert->nonce.validContent = FALSE;
  cert->prodQualifier = 0xFFu;
  cert->uniqueEcuId.validContent = FALSE;
  cert->specialECU = 0xFFu;

  cert->signatureAlgorithmOID.validContent = FALSE;
  cert->signature.validContent = FALSE;
}

/**********************************************************************************************************************
 *  CertP_ParseBaseStructure_ProcessRootElem
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
  */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseBaseStructure_ProcessRootElem(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) ElementPtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  uint16 rawCertLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert
)
{
  const uint8 EleNrRoot[1] = { 1u };
  Std_ReturnType retVal = E_OK;

  /* #10 Get the root element, check it for being a sequence and check that the maximum size is not exceeded. */
  if (CertP_BerGetElement(WorkspacePtr, ElementPtr, EleNrRoot, 1u, rawCertData, rawCertLength) != E_OK)
  {
    retVal = E_NOT_OK;
  }
  else if (ElementPtr->Type != CERTP_ASN1_TAG_SEQUENCE)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    parsedCert->parsedCertLength = (uint16)(ElementPtr->EndIdx - ElementPtr->Idx);
    /* In CertP_BerGetElement it was already checked that (parsedCert->parsedCertLength <= rawCertLength),
     * thus it is not necessary to repeat the check here. */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  CertP_ParseBaseStructure_ProcessFirstSubElem
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
 *
  */
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseBaseStructure_ProcessFirstSubElem(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2VAR(CertP_BaseBerElementType, AUTOMATIC, AUTOMATIC) ElementPtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  uint16 rawCertLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2VAR(CertP_BerElementType, AUTOMATIC, AUTOMATIC) signedCertElement
)
{
  Std_ReturnType retVal = E_OK;
  const uint8 EleNrSignedCert[2] = { 1u, 1u };     /* chapter 1.1  : signed cert */

  /* #10 Get the first sub element that contains the signed certificate data and check it for being a sequence. */
  if (CertP_BerGetElement(WorkspacePtr, ElementPtr, EleNrSignedCert, 2u, rawCertData, rawCertLength) != E_OK)
  {
    retVal = E_NOT_OK;
  }
  else if (ElementPtr->Type != CERTP_ASN1_TAG_SEQUENCE)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* #20 Store the data index and the length of the element used for signature calculation in the corresponding
     * element of the parsed certificate.  */

     /* The complete DER element including identifier and length octets are used for signature calculation */
    parsedCert->signedCertData.elemDataIdx = (uint16)ElementPtr->Idx;
    parsedCert->signedCertData.elemDataLength = (uint16)(ElementPtr->EndIdx - ElementPtr->Idx);

    signedCertElement->elemDataIdx = (uint16)ElementPtr->ContentIdx;
    signedCertElement->elemDataLength = (uint16)(ElementPtr->EndIdx - ElementPtr->ContentIdx);
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_ParseBaseStructure
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
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseBaseStructure(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  uint16 rawCertLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2VAR(CertP_BerElementType, AUTOMATIC, AUTOMATIC) signedCertElement
  )
{
  const uint8 EleNrSignatureAlg[3]  = { 1u, 2u, 1u };  /* chapter 1.2.1: Signature Algorithm OID */
  const uint8 EleNrSignature[2]     = { 1u, 3u };     /* chapter 1.3  : cert signature */
  Std_ReturnType retVal;
  CertP_BaseBerElementType    EleDesc;

  /* #10 Get the root element. */
  retVal = CertP_ParseBaseStructure_ProcessRootElem(WorkspacePtr, &EleDesc, rawCertData, rawCertLength, parsedCert);

  if (retVal == E_OK)
  {
    /* Get the first sub element that contains the signed certificate data. */
    retVal = CertP_ParseBaseStructure_ProcessFirstSubElem(WorkspacePtr, &EleDesc, rawCertData, rawCertLength, parsedCert, signedCertElement);
  }

  if (retVal == E_OK)
  {
    /* #30 Get the signature algorithm OID */
    if (CertP_BerGetElement(WorkspacePtr, &EleDesc, EleNrSignatureAlg, 3u, rawCertData, rawCertLength) != E_OK)
    {
      retVal = E_NOT_OK;
    }
    /* #40 Check the tag for OID. */
    else if (EleDesc.Type != CERTP_ASN1_TAG_OBJECT_IDENTIFIER)
    {
      retVal = E_NOT_OK;
    }
    else
    {
      parsedCert->signatureAlgorithmOID.elemDataIdx = (uint16)EleDesc.ContentIdx;
      parsedCert->signatureAlgorithmOID.elemDataLength = (uint16)(EleDesc.EndIdx - EleDesc.ContentIdx);
      parsedCert->signatureAlgorithmOID.validContent = TRUE;

      /* #50 Get the certificate's signature element. */
      if (CertP_BerGetElement(WorkspacePtr, &EleDesc, EleNrSignature, 2u, rawCertData, rawCertLength) == E_OK)
      {
        /* #60 Check for BIT STRING tag and for length 0x40 + 1 byte encoding the number of bits. */
        if (rawCertData[EleDesc.Idx] != CERTP_ASN1_TAG_BIT_STRING)
        {
          retVal = E_NOT_OK;
        }
        /* #70 Check the expected signature length. */
        else if ((uint16)(EleDesc.EndIdx - EleDesc.ContentIdx) != (SSA_SIZEOF_SIGNATURE + 1u))
        {
          retVal = E_NOT_OK;
        }
        /* #80 Assign the data index and length of the certificate's signature. Remove byte encoding the
         * number of unused bits. */
        else
        {
          /* Remove byte encoding the number of unused bits. */
          parsedCert->signature.elemDataIdx = (uint16)EleDesc.ContentIdx + 1u;
          parsedCert->signature.elemDataLength = (uint16)SSA_SIZEOF_SIGNATURE;
          parsedCert->signature.validContent = TRUE;
          retVal = E_OK;
        }
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  CertP_ParseTbsCertificate
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
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseTbsCertificate(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) signedCertElement
  )
{
  const uint8 EleNrVersion[2]           = { 1u, 1u };       /* chapter 1.1.1.1: Version */
  const uint8 EleNrSerialNumber[1]      = { 2u };          /* chapter 1.1.2.1: SerialNumber */
  const uint8 EleNrCertSignatureAlg[2]  = { 3u, 1u };       /* chapter 1.1.3.1: Signature Algorithm OID */
  const uint8 EleNrIssuer[1]            = { 4u };          /* chapter 1.1.4: Issuer */
  const uint8 EleNrValidNotBefore[2]    = { 5u, 1u };       /* chapter 1.1.5.1: valid not before */
  const uint8 EleNrValidNotAfter[2]     = { 5u, 2u };       /* chapter 1.1.5.2: valid not after */
  const uint8 EleNrSubject[1]           = { 6u };          /* chapter 1.1.6.: Subject */
  const uint8 EleNrPublicKey[2]         = { 7u, 2u };       /* chapter 1.1.7.2: Cert public key */
  const uint8 EleNrExtensions[2]        = { 8u, 1u };       /* chapter 1.1.8.1: Extensions */
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Parse the version. */
  if (CertP_ParseVersionElement(WorkspacePtr, EleNrVersion, 2u, DataPtr, signedCertElement, &parsedCert->version) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #20 Parse the serial number. */
  else if (CertP_ParseStandardElement(WorkspacePtr, EleNrSerialNumber, 1u, CERTP_ASN1_TAG_INTEGER, DataPtr, signedCertElement, &parsedCert->serialNumber) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #30 Parse the signature algorithm OID. */
  else if (CertP_ParseStandardElement(WorkspacePtr, EleNrCertSignatureAlg, 2u, CERTP_ASN1_TAG_OBJECT_IDENTIFIER, DataPtr, signedCertElement, &parsedCert->certSignatureAlgOID) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #40 Parse the issuer. */
  else if (CertP_ParseIssuerOrSubjectElement(WorkspacePtr, EleNrIssuer, 1u, DataPtr, signedCertElement, &parsedCert->issuer) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #50 Parse the date and time 'valid not before'. */
  else if (CertP_ParseTimeElement(WorkspacePtr, EleNrValidNotBefore, 2u, DataPtr, signedCertElement, &parsedCert->validNotBefore) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #60 Parse the date and time 'valid not after'. */
  else if (CertP_ParseTimeElement(WorkspacePtr, EleNrValidNotAfter, 2u, DataPtr, signedCertElement, &parsedCert->validNotAfter) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #70 Parse the subject. */
  else if (CertP_ParseIssuerOrSubjectElement(WorkspacePtr, EleNrSubject, 1u, DataPtr, signedCertElement, &parsedCert->subject) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #80 Parse the public key. */
  else if (CertP_ParsePublicKeyElement(WorkspacePtr, EleNrPublicKey, 2u, DataPtr, signedCertElement, &parsedCert->publicKey) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #90 Parse the extensions */
  else if (CertP_ParseExtensionsElement_Tbs(WorkspacePtr, EleNrExtensions, 2u, DataPtr, signedCertElement, parsedCert) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #100 Return E_OK only if parsing fully succeeded. */
  else
  {
    retVal = E_OK;
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_SSA_MIF_CHECK_CONDITIONS */

/**********************************************************************************************************************
 *  CertP_ParseAttributeCertificateInfo
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
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_ParseAttributeCertificateInfo(
  P2VAR(CertP_BerWorkspaceType, AUTOMATIC, AUTOMATIC) WorkspacePtr,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) DataPtr,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) signedCertElement
  )
{
  const uint8 EleNrAttCertVersion[1]    = { 1u };              /* chapter 1.1.1: AttCertVersion */
  const uint8 EleNrHolderIssuer[5]      = { 2u, 1u, 1u, 1u, 1u };  /* chapter 1.1.2.1.1.1.1: Holder */
  const uint8 EleNrHolderSerialNum[3]   = { 2u, 1u, 2u };        /* chapter 1.1.2.1.2: Holder SerialNumber */
  const uint8 EleNrIssuer[4]            = { 3u, 1u, 1u, 1u };     /* chapter 1.1.3.1.1.1: Issuer */
  const uint8 EleNrCertSignatureAlg[2]  = { 4u, 1u };           /* chapter 1.1.4.1: Signature Algorithm OID - Must be 1.3.6.1.4.1.2916.3.6.509.5.100 and equal to signature OID below */
  const uint8 EleNrSerialNumber[1]      = { 5u };              /* chapter 1.1.5: SerialNumber */
  const uint8 EleNrValidNotBefore[2]    = { 6u, 1u };           /* chapter 1.1.6.1: valid not before */
  const uint8 EleNrValidNotAfter[2]     = { 6u, 2u };           /* chapter 1.1.6.2: valid not after */
  const uint8 EleNrAttributes[1]        = { 7u };              /* chapter 1.1.7: Attributes */
  const uint8 EleNrExtensionsOpt1[1]    = { 8u };              /* chapter 1.1.8: Issuer Unique Id or Extensions OPTIONAL */
  const uint8 EleNrExtensionsOpt2[1]    = { 9u };              /* chapter 1.1.9: Issuer Unique Id or Extensions OPTIONAL */
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Parse the version. */
  if (CertP_ParseVersionElement(WorkspacePtr, EleNrAttCertVersion, 1u, DataPtr, signedCertElement, &parsedCert->version) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #20 Parse the holder issuer. */
  else if (CertP_ParseIssuerOrSubjectElement(WorkspacePtr, EleNrHolderIssuer, 5u, DataPtr, signedCertElement, &parsedCert->holderIssuer) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #30 Parse the holder's serial number. */
  else if (CertP_ParseStandardElement(WorkspacePtr, EleNrHolderSerialNum, 3u, CERTP_ASN1_TAG_INTEGER, DataPtr, signedCertElement, &parsedCert->holderSerialNumber) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #40 Parse the issuer. */
  else if (CertP_ParseIssuerOrSubjectElement(WorkspacePtr, EleNrIssuer, 4u, DataPtr, signedCertElement, &parsedCert->issuer) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #50 Parse the signature algorithm OID. */
  else if (CertP_ParseStandardElement(WorkspacePtr, EleNrCertSignatureAlg, 2u, CERTP_ASN1_TAG_OBJECT_IDENTIFIER, DataPtr, signedCertElement, &parsedCert->certSignatureAlgOID) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #60 Parse the serial number. */
  else if (CertP_ParseStandardElement(WorkspacePtr, EleNrSerialNumber, 1u, CERTP_ASN1_TAG_INTEGER, DataPtr, signedCertElement, &parsedCert->serialNumber) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #70 Parse the date and time 'valid not before'. */
  else if (CertP_ParseTimeElement(WorkspacePtr, EleNrValidNotBefore, 2u, DataPtr, signedCertElement, &parsedCert->validNotBefore) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #80 Parse the date and time 'valid not after'. */
  else if (CertP_ParseTimeElement(WorkspacePtr, EleNrValidNotAfter, 2u, DataPtr, signedCertElement, &parsedCert->validNotAfter) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #90 Parse the attributes. */
  else if (CertP_ParseAttributesElement(WorkspacePtr, EleNrAttributes, 1u, DataPtr, signedCertElement, parsedCert) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #100 Parse the extensions. */
  else if (CertP_ParseExtensionsElement_AttributeCert(WorkspacePtr, EleNrExtensionsOpt1, EleNrExtensionsOpt2, 1u, DataPtr, signedCertElement, parsedCert) != E_OK)
  {
    /* Stop parsing. */
  }
  /* #110 Return E_OK only if parsing fully succeeded. */
  else
  {
    retVal = E_OK;
  }

  return retVal;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_SSA_MIF_CHECK_CONDITIONS */

/**********************************************************************************************************************
 *  CertP_IsEqual()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_CERTP_LOCAL FUNC(boolean, Ssa_CertP_CODE) CertP_IsEqual(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) data1,
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) data2,
  uint16 dataLength)
{
  uint16 byteIdx;
  boolean isEqual = TRUE;
  /* #10 Compare both data buffers byte-by-byte. */
  for (byteIdx = 0u; byteIdx < dataLength; byteIdx++) /* FETA_SSA_CERTP_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
  {
    /* #20 Once there is a difference leave the function with negative result. */
    if (data1[byteIdx] != data2[byteIdx])
    {
      isEqual = FALSE;
      break;
    }
  }
  return isEqual;
}

/**********************************************************************************************************************
 *  CertP_Certificate_Verify_SigAlgoIdentifier()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_Certificate_Verify_SigAlgoIdentifier(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert)
{
  Std_ReturnType retVal = E_OK;

  /* #10 Check that the length both the signature algorithm OID and the certificate signature algorithm OID is 13. */
  if ((parsedCert->signatureAlgorithmOID.elemDataLength != 13u) ||
    (parsedCert->certSignatureAlgOID.elemDataLength != 13u))
  {
    parsedCert->verificationResult = CERTP_VER_INVALID_FORMAT;
    retVal = E_NOT_OK;
  }
  else
  {
    /* #20 Check that the Signature OID is according to RFC8032:
     *       1.3.  6.  1.  4.  1.  2916.  3.  6.   509.  5. 110
     * ASN1   2B  06  01  04  01  96 64  03  06  83 7D  05   6E */
    const uint8 expectedAlgoId[13] = { 0x2B, 0x06, 0x01, 0x04, 0x01, 0x96, 0x64, 0x03, 0x06, 0x83, 0x7D, 0x05, 0x6E };
    uint16 byteIdx;
    for (byteIdx = 0u; byteIdx < parsedCert->certSignatureAlgOID.elemDataLength; byteIdx++) /* FETA_SSA_CERTP_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
    {
      /* #30 Set the verification result to "invalid format" if the OID is not as expected. */
      if ((rawCertData[parsedCert->certSignatureAlgOID.elemDataIdx + byteIdx] != expectedAlgoId[byteIdx]) ||
        (rawCertData[parsedCert->signatureAlgorithmOID.elemDataIdx + byteIdx] != expectedAlgoId[byteIdx]))
      {
        parsedCert->verificationResult = CERTP_VER_INVALID_FORMAT;
        retVal = E_NOT_OK;
        break;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  CertP_Certificate_Verify_Vin()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_CERTP_LOCAL_INLINE FUNC(boolean, Ssa_CertP_CODE) CertP_Certificate_Verify_Vin(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) errCode)
{
  boolean verificationFinished = FALSE;

  /* #10 If the certificate contains the "TargetVIN" field, verify that the certificate is applicable to the vehicle
   * the ECU belongs to. */
  if (parsedCert->targetVIN.validContent == TRUE)
  {
    uint8 vin[SSA_SIZEOF_VIN] = { 0u };
    /* #20 For that get VIN form the Coding module and check that it is contained in the certificate to be verified.
     * Set the verification result to "invalid scope" when verification fails. */
    if (Rte_Call_Coding_VIN_Get(vin) != RTE_E_OK)
    {
      parsedCert->verificationResult = CERTP_VER_INVALID_SCOPE;
      verificationFinished = TRUE;
    }
    else if (!CertP_FindStringInSetOfUTF8Strings((P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA))vin, SSA_SIZEOF_VIN, rawCertData, &(parsedCert->targetVIN)))
    {
      parsedCert->verificationResult = CERTP_VER_INVALID_SCOPE;
      verificationFinished = TRUE;
    }
    else
    {
      /* No action. */
    }
  }
  *errCode = E_OK;
  return verificationFinished;
}

/**********************************************************************************************************************
 *  CertP_Certificate_Verify_TargetEcu()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_CERTP_LOCAL_INLINE FUNC(boolean, Ssa_CertP_CODE) CertP_Certificate_Verify_TargetEcu(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) errCode)
{
  boolean verificationFinished = FALSE;
  /* #10 If the certificate contains the "TargetECU" field, verify that the certificate is applicable to the ECU this
   * module is running on. Set the verification result to "invalid scope" when verification fails. */
  if (parsedCert->targetECU.validContent == TRUE)
  {
    if (!CertP_CheckSetOfUTF8StringsAgainstUniqueEcuIds(rawCertData, &(parsedCert->targetECU)))
    {
      parsedCert->verificationResult = CERTP_VER_INVALID_SCOPE;
      verificationFinished = TRUE;
    }
    else
    {
      /* No action. */
    }
  }
  *errCode = E_OK;

  return verificationFinished;
}

/**********************************************************************************************************************
 *  CertP_Certificate_Verify_Nonce()
 **********************************************************************************************************************/
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
 */
SSA_CERTP_LOCAL_INLINE FUNC(boolean, Ssa_CertP_CODE) CertP_Certificate_Verify_Nonce(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer,
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) expectedNonce,
  P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) errCode)
{
  boolean verificationFinished = FALSE;
  *errCode = E_OK;

  /* #10 Check if the certificate contains a nonce. */
  if ((parsedCert->nonce.validContent) && (expectedNonce->validated))
  {
    /* #20 Verify the nonce is as expected, else set the verification result
     * "synchronize time failed nonce not accepted". */
    if (parsedCert->nonce.elemDataLength != SSA_SIZEOF_NONCE)
    {
      parsedCert->verificationResult = CERTP_VER_SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED;
      verificationFinished = TRUE;
    }
    else
    {
      uint16 byteIdx;
      for (byteIdx = 0u; byteIdx < SSA_SIZEOF_NONCE; byteIdx++)
      {
        /* Since the nonce is supposed to be used only once it is not necessary to be 
         * resistant to timing attacks. Leave loop by break. */
        if (rawCertData[parsedCert->nonce.elemDataIdx + byteIdx] != expectedNonce->data[byteIdx])
        {
          parsedCert->verificationResult = CERTP_VER_SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED;
          verificationFinished = TRUE;
          break;
        }
      }
    }
  }
  /* #30 Else, no nonce is contained, verify the notValidAfter date and time.
   * Set verification result to "invalid time period" if verification fails. */
  else
  {
    TimeM_DateTimeType realTime;
    boolean realTimeIsGreater = FALSE;
    verificationFinished = TRUE;

    /* Assertions for calling Rte_Call_TimeM_RealTime_Compare */
    /*@ assert &realTime != NULL_PTR; */
    /*@ assert parsedCertIssuer != NULL_PTR; */
    /*@ assert &realTimeIsGreater != NULL_PTR; */

    /* #40 Get the current real-time from the time manager. */
    if (Rte_Call_TimeM_RealTime_Get(&realTime) != E_OK)
    {
      *errCode = E_NOT_OK;
      parsedCert->verificationResult = CERTP_VER_INVALID_TIME_PERIOD;
    }
    /* #42 Check that the certificate has not yet expired. */
    else if (Rte_Call_TimeM_RealTime_Compare(&realTime, TIMEM_IS_GREATER, &(parsedCert->validNotAfter.dateTime), &realTimeIsGreater) != E_OK)
    {
      *errCode = E_NOT_OK;
      parsedCert->verificationResult = CERTP_VER_INVALID_TIME_PERIOD;
    }
    else if (realTimeIsGreater == TRUE)
    {
      parsedCert->verificationResult = CERTP_VER_INVALID_TIME_PERIOD;
    }
    /* #44 Check that the issuer certificate has not yet expired. */
    else if (Rte_Call_TimeM_RealTime_Compare(&realTime, TIMEM_IS_GREATER, &(parsedCertIssuer->validNotAfter.dateTime), &realTimeIsGreater) != E_OK) /* VCA_SSA_CERTP_NULL_PTR_REQUIREMENTS_VIOLATED */
    {
      *errCode = E_NOT_OK;
      parsedCert->verificationResult = CERTP_VER_INVALID_TIME_PERIOD;
    }
    else if (realTimeIsGreater == TRUE)
    {
      parsedCert->verificationResult = CERTP_VER_INVALID_TIME_PERIOD;
    }
    else
    {
      /* No action. */
      verificationFinished = FALSE;
    }
  }
  return verificationFinished;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  CertP_Certificate_Verify_IsFormatValid()
 **********************************************************************************************************************/
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
 */
SSA_CERTP_LOCAL_INLINE FUNC(boolean, Ssa_CertP_CODE) CertP_Certificate_Verify_IsFormatValid(
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCert,
  CertP_PkiRoleType expectedPkiRole)
{
  boolean formatIsValid = FALSE;

  /* #10 Verify Version Field. Version must 1 for the enhanced access rights certificate and 2 for all others. */
  if ((expectedPkiRole == CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS) && (parsedCert->version != 1u))
  {
    /* invalid format */
  }
  else if ((expectedPkiRole != CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS) && (parsedCert->version != 2u))
  {
    /* invalid format */
  }
  /* #20 Verify that mandatory fields (serial number, certSignatureAlgOID, issuer, validNotBefore and validNotAfter)
   * are available. */
  else if ((parsedCert->serialNumber.validContent == FALSE) ||
           (parsedCert->certSignatureAlgOID.validContent == FALSE) ||
           (parsedCert->issuer.validContent == FALSE) ||
           (parsedCert->validNotBefore.validContent == FALSE) ||
           (parsedCert->validNotAfter.validContent == FALSE))
  {
    /* invalid format */
  }
  /* #30 Verify that all certificate except for the enhanced rights certificate have a subject and a public key. */
  else if ((expectedPkiRole != CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS) &&
          ((parsedCert->subject.validContent == FALSE) || (parsedCert->publicKey.validContent == FALSE)))
  {
    /* invalid format */
  }
  /* #40 Verify that the enhanced rights certificate has a holderIssuer, a holderSerialNumber and service data
   * (the enhanced access rights). */
  else if ((expectedPkiRole == CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS) &&
          ((parsedCert->holderIssuer.validContent == FALSE) || (parsedCert->holderSerialNumber.validContent == FALSE) || (parsedCert->service.validContent == FALSE)))
  {
    /* invalid format */
  }
  /* #50 Check that the ProdQualifier is contained. */
  /* The expected prodQualifier is 0. */
  else if (parsedCert->prodQualifier == 0xFFu)
  {
    /* invalid format */
  }
  /* #60 Verify that all certificate except for the enhanced rights certificate have a Subject Key Identifier. */
  else if ((expectedPkiRole != CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS) && (parsedCert->subjectKeyIdentifier.validContent == FALSE))
  {
    /* invalid format */
  }
  /* #65 Verify that all certificate except for Root Ca certificate have an Authority Key Identifier. */
  else if ((expectedPkiRole != CERTP_PKI_ROLE_ROOT) && (parsedCert->authorityKeyIdentifier.validContent == FALSE))
  {
    /* invalid format */
  }
  /* #70 Verify that the Root Ca and Backend Ca certificates contains the Basic Constraints. */
  else if (((parsedCert->pkiRole == CERTP_PKI_ROLE_ROOT) || (parsedCert->pkiRole == CERTP_PKI_ROLE_BACKEND))
       && (parsedCert->basicConstraints == 0xFFu))
  {
    /* invalid format */
  }
  /* #80 Check only for the diagnostic authentication certificate that the UserRole is contained. */
  else if ((parsedCert->pkiRole == CERTP_PKI_ROLE_TESTER) && (parsedCert->userRole == 0xFFu))
  {
    /* invalid format */
  }
  /* #90 Check only for the ECU certificate that the uniqueECUID is contained. */
  else if ((parsedCert->pkiRole == CERTP_PKI_ROLE_ECU) && (parsedCert->uniqueEcuId.validContent == FALSE))
  {
    /* invalid format */
  }
  /* #100 Check (for all certificates) that there is a signature. */
  else if ((parsedCert->signatureAlgorithmOID.validContent == FALSE) || (parsedCert->signature.validContent == FALSE))
  {
    /* invalid format */
  }
  else
  {

    /* valid format */
    formatIsValid = TRUE;
  }

  /* #110 Return only TRUE if all checks passed. */
  return formatIsValid;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_SSA_MIF_CHECK_CONDITIONS */

/**********************************************************************************************************************
 *  CertP_Certificate_Verify_PreCsmCall()
 **********************************************************************************************************************/
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
SSA_CERTP_LOCAL_INLINE FUNC(void, Ssa_CertP_CODE) CertP_Certificate_Verify_PreCsmCall(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertIssuer,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer,
  CertP_PkiRoleType expectedPkiRole)
{
  /* #10 Verify that the type of the certificate matches the requested use case by evaluating the certificate's
   *     PKI-Role field. Set verification result "Invalid Type" if not. */
  if (parsedCert->pkiRole != expectedPkiRole)
  {
    parsedCert->verificationResult = CERTP_VER_INVALID_TYPE;
  }
  /* #20 Verify that the format is valid. Set verification result "Invalid Format" if not. */
  else if (!CertP_Certificate_Verify_IsFormatValid(parsedCert, expectedPkiRole))
  {
    parsedCert->verificationResult = CERTP_VER_INVALID_FORMAT;
  }
  /* #30 Verify Issuer against Subject of issuer. Set verification result "Invalid Chain of Trust" if verification fails. */
  else if (CertP_CompareBerElement(rawCertData, &(parsedCert->issuer), rawCertIssuer, &(parsedCertIssuer->subject)) == FALSE)
  {
    parsedCert->verificationResult = CERTP_VER_INVALID_CHAIN_OF_TRUST;
  }
  /* #40 Verify the HolderIssuer  against the Subject  of the issuer if the certificate to be verified is
   *     an enhanced access right certificate. Set verification result "Invalid Chain of Trust" if verification fails. */
  else if (CertP_CheckBerElementsForDifference_Cond(rawCertData, &(parsedCert->holderIssuer), rawCertIssuer, &(parsedCertIssuer->subject), (boolean)(expectedPkiRole == CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS)) == TRUE)
  {
    parsedCert->verificationResult = CERTP_VER_INVALID_CHAIN_OF_TRUST;
  }
  /* #50 Verify the Authority Key Identifier (i.e compare it with the Subject Key Identifier of the issuer) if the certificate to
   *     be verified is not a Root Ca certificate. Set verification result "Invalid Chain of Trust" if verification fails. */
  else if (CertP_CheckBerElementsForDifference_Cond(rawCertData, &(parsedCert->authorityKeyIdentifier), rawCertIssuer, &(parsedCertIssuer->subjectKeyIdentifier), (boolean)(parsedCert->pkiRole != CERTP_PKI_ROLE_ROOT)) == TRUE)
  {
    parsedCert->verificationResult = CERTP_VER_INVALID_CHAIN_OF_TRUST;
  }
  /* #60 Verify the Diagnostic User. Role Set verification result "Invalid Content" if verification fails. */
  else if ((parsedCert->pkiRole == CERTP_PKI_ROLE_TESTER) && ((parsedCert->userRole == RIGHTSM_USERROLE_ANYBODY) || (parsedCert->userRole > RIGHTSM_USERROLE_EPTI_TEST_TOOL)))
  {
    parsedCert->verificationResult = CERTP_VER_INVALID_CONTENT;
  }
  /* #70 Verify the Signature Algorithm Identifier. */
  else if (CertP_Certificate_Verify_SigAlgoIdentifier(rawCertData, parsedCert) != E_OK)
  {
    /* Verification is set with the previous function. */
  }
  else
  {
    /* #120 Only if all verification succeeded return the positive response code "verification ok". */
    parsedCert->verificationResult = CERTP_VER_OK;
  }
} /* PRQA S 6080 */ /* MD_SSA_MIF_CHECK_CONDITIONS */

/**********************************************************************************************************************
 *  CertP_Certificate_Verify_PostCsmCall()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_Certificate_Verify_PostCsmCall(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer,
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) expectedNonce)
{
  Std_ReturnType retVal = E_OK;

  /* #90 Verify the target VIN. */
  if (CertP_Certificate_Verify_Vin(rawCertData, parsedCert, &retVal) == TRUE)
  {
    /* Verification failed. Leave function. */
  }
  /* #100 Verify the target ECU. */
  else if (CertP_Certificate_Verify_TargetEcu(rawCertData, parsedCert, &retVal) == TRUE)
  {
    /* Verification failed. Leave function. */
  }
  /* #110 Verify the nonce. */
  else if (CertP_Certificate_Verify_Nonce(rawCertData, parsedCert, parsedCertIssuer, expectedNonce, &retVal) == TRUE)
  {
    /* Verification failed. Leave function. */
  }
  else
  {
    /* #120 Only if all verification succeeded return the positive response code "verification ok". */
    parsedCert->verificationResult = CERTP_VER_OK;
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_CsmSignatureVerify()
 **********************************************************************************************************************/
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
 */
SSA_CERTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_CsmSignatureVerify(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) dataIn,
  uint16 dataInLength,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) dataKey,
  uint16 dataKeyLength,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) dataSignature,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, AUTOMATIC) csmVerifyResult)
{
  Std_ReturnType retVal = SSA_E_PENDING;

  /* #10 Handle the states for asynchronously calling the Csm signature verify job. */

  /* #20 Continue if not waiting for callback, i.e. check that state is not "wait", else return E_PENDING. */
#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
  /* If asynchronous processing is disabled, CertP_CsmSignatureVerifyState is never WAIT. */
  if (CertP_CsmSignatureVerifyState != SSA_ASYNC_STATE_WAIT)
#endif
  {
    /* #30 Check that state is "idle". */

#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
    /* If asynchronous processing is disabled, CertP_CsmSignatureVerifyState is always IDLE,
     * if this function is called. */
    if (CertP_CsmSignatureVerifyState == SSA_ASYNC_STATE_IDLE)
#endif
    {
      /* #40 Set asynchronous state to "wait" as callback could occur inside of Csm_SignatureVerify(). */
      CertP_CsmSignatureVerifyState = SSA_ASYNC_STATE_WAIT;

      /* #50 Set the Csm verification key. */
      retVal = Rte_Call_Key_SignatureRamKey_KeyElementSet(SSA_KE_SIGNATURE_KEY, dataKey, (uint32)dataKeyLength);
      retVal |= Rte_Call_Key_SignatureRamKey_KeySetValid();
      if (retVal != RTE_E_OK)
      {
        /* Set asynchronous state to "idle" */
        CertP_CsmSignatureVerifyState = SSA_ASYNC_STATE_IDLE;
        retVal = E_NOT_OK;
      }
      else
      {
        CertP_CsmVerificationResult = CRYPTO_E_VER_NOT_OK;

        /* #60 Call the CSM signature verify function. */
        retVal = Rte_Call_SsaCdd_Csm_SignatureVerify(SSA_CERTP_SIGNATURE_VERIFY_JOB_ID, CRYPTO_OPERATIONMODE_SINGLECALL, dataIn, (uint32)dataInLength, dataSignature, (uint32)SSA_SIZEOF_SIGNATURE, &CertP_CsmVerificationResult);
        /* #100 Process the return value. */
#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
        if ((retVal == SSA_CRYPTO_E_QUEUE_FULL) || (retVal == SSA_CRYPTO_E_BUSY))
        {
          /* #110 Change to "idle" state and return "pending" if error code "queue full" or "busy" are returned. */
          CertP_CsmSignatureVerifyState = SSA_ASYNC_STATE_IDLE;
          retVal = SSA_E_PENDING;
        }
        else if (retVal == E_OK)
        {
          /* #114 Remain in state "wait" and return "pending" if no error occurred. */
          retVal = SSA_E_PENDING;
        }
#else
        if (retVal == E_OK)
        {
          CertP_CsmSignatureVerifyState = SSA_ASYNC_STATE_READY;
        }
#endif
        else
        {
          retVal = E_NOT_OK;
          /* #112 Change to "idle" state if any other error occurred. */
          CertP_CsmSignatureVerifyState = SSA_ASYNC_STATE_IDLE;
        }
      }
    }

    /* #120 Check again the asynchronous state. */
    if (CertP_CsmSignatureVerifyState == SSA_ASYNC_STATE_READY)
    {
      /* #130 If state is "ready" pass the verification result to the caller and change to state  "idle". */
      *csmVerifyResult = CertP_CsmVerificationResult;
      retVal = RTE_E_OK;
      /* Set asynchronous state "idle" */
      CertP_CsmSignatureVerifyState = SSA_ASYNC_STATE_IDLE;
    }
#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
    /* If asynchronous processing is disabled, CertP_CsmSignatureVerifyState is never FAILED.
     * (State FAILED can only be reached via the Csm callback, which is never called, if
     * asynchronous processing is disabled. */
    else if (CertP_CsmSignatureVerifyState == SSA_ASYNC_STATE_FAILED)
    {
      /* #132 Else if state is "failed" return with error. */
      CertP_CsmSignatureVerifyState = SSA_ASYNC_STATE_IDLE;
      retVal = E_NOT_OK;
    }
#endif
    else
    {
      /* #134 In all other cases go on waiting for the callback. */
    }
  }

  return retVal;
} /* PRQA S 6060, 6080 */ /* MD_SSA_STPAR, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  CertP_Certificate_Verify()
 **********************************************************************************************************************/
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
SSA_CERTP_LOCAL FUNC(Std_ReturnType, Ssa_CertP_CODE) CertP_Certificate_Verify(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertIssuer,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer,
  CertP_PkiRoleType expectedPkiRole,
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) expectedNonce)
{
  Std_ReturnType retVal = E_OK;

  /* #10 If function is in IDLE state do the initial verification. */
#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
  /* If asynchronous processing is disabled, CertP_Certificate_Verify_Runnable_State is always
   * IDLE if this function is called. */
  if (CertP_Certificate_Verify_Runnable_State == CERTP_ASYNC_STATE_IDLE)
#endif
  {
    /* #20 Change to state VERIFY if initial verification succeeded. */
    CertP_Certificate_Verify_PreCsmCall(rawCertData, parsedCert, rawCertIssuer, parsedCertIssuer, expectedPkiRole);
    if (parsedCert->verificationResult == CERTP_VER_OK)
    {
      CertP_Certificate_Verify_Runnable_State = CERTP_ASYNC_STATE_VERIFY;
    }
  }

  /* #30 If in state VERIFY call Csm. */
  if (CertP_Certificate_Verify_Runnable_State == CERTP_ASYNC_STATE_VERIFY)
  {
    Crypto_VerifyResultType csmVerifyResult = CRYPTO_E_VER_NOT_OK;

    /*@ assert $lengthOf(rawCertData) >= sizeof(CertP_RawCertBufferType); */ /* VCA_SSA_CERTP_RAW_CERT_LENGTH */
    /*@ assert $lengthOf(rawCertIssuer) >= sizeof(CertP_RawCertBufferType); */ /* VCA_SSA_CERTP_RAW_CERT_LENGTH */
    if ((parsedCert->signedCertData.elemDataIdx < sizeof(CertP_RawCertBufferType)) &&
        (parsedCertIssuer->publicKey.elemDataIdx < sizeof(CertP_RawCertBufferType)) &&
        (parsedCert->signature.elemDataIdx < sizeof(CertP_RawCertBufferType)))
    {
      /* #40 Call the Csm signature verify state handler.  */
      retVal = CertP_CsmSignatureVerify( /* VCA_SSA_CERTP_INDEXED_ACCESS_TO_RAW_CERT */
        &rawCertData[parsedCert->signedCertData.elemDataIdx],
        parsedCert->signedCertData.elemDataLength,
        &rawCertIssuer[parsedCertIssuer->publicKey.elemDataIdx],
        parsedCertIssuer->publicKey.elemDataLength,
        &rawCertData[parsedCert->signature.elemDataIdx],
        &csmVerifyResult);
    }
    else
    {
      retVal = E_NOT_OK;
    }

#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
    /* If asynchronous processing is disabled, PENDING is never returned by Csm. */
    if (retVal == SSA_E_PENDING)
    {
      /* #50 If request is pending also return pending and stay in current state. */
      retVal = RTE_E_CertP_Functions_E_PENDING;
    }
    else if (retVal != E_OK)
#else
    if (retVal != E_OK)
#endif
    {
      /* #60 If an error occurred fall back to state IDLE and return E_NOT_OK. */
      retVal = RTE_E_CertP_Functions_E_NOT_OK;
      parsedCert->verificationResult = CERTP_VER_INVALID_SIGNATURE;
      CertP_Certificate_Verify_Runnable_State = CERTP_ASYNC_STATE_IDLE;
    }
    else if (csmVerifyResult != CRYPTO_E_VER_OK)
    {
      /* #70 If the verification failed fall back to runnable state IDLE. */
      parsedCert->verificationResult = CERTP_VER_INVALID_SIGNATURE;
      CertP_Certificate_Verify_Runnable_State = CERTP_ASYNC_STATE_IDLE;
    }
    else
    {
      /* #80 If no error occurred and the verification succeeded process the remaining verification steps and return to state IDLE. */
      retVal = CertP_Certificate_Verify_PostCsmCall(rawCertData, parsedCert, parsedCertIssuer, expectedNonce);
      CertP_Certificate_Verify_Runnable_State = CERTP_ASYNC_STATE_IDLE;
    }
  }

  /* #90 Process return value and verification result. */
  CertP_Certificate_Verify_HandleResult(retVal, rawCertData, parsedCert, expectedPkiRole);

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  CertP_Certificate_Verify_HandleResult()
 **********************************************************************************************************************/
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
SSA_CERTP_LOCAL_INLINE FUNC(void, Ssa_CertP_CODE) CertP_Certificate_Verify_HandleResult(
  Std_ReturnType retVal,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert,
  CertP_PkiRoleType expectedPkiRole)
{
#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_OFF)
  SSA_DUMMY_STATEMENT_CONST(retVal); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#else
  /* If asynchronous processing is disabled, the retVal is never PENDING. */
  if (retVal != RTE_E_CertP_Functions_E_PENDING)
#endif
  {
    /* #10 For any successful certificate verification but diagnostic authentication write a log entry for
    *    the event "Successful Certificate Verification". */
    if (parsedCert->verificationResult == CERTP_VER_OK)
    {
      /* #20 Do not create a log entry when verifying the following types of certificates:
      *      Diagnostic Authentication Certificate or
      *      Enhanced Rights Certificate. */
      if ((expectedPkiRole != CERTP_PKI_ROLE_TESTER) && (expectedPkiRole != CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS))
      {
        /* invalid SN by setting last 3 byte representing the Registration Authority to prohibited value 00-00-00 */
        uint8 serial[SSA_SIZEOF_SERIALNUMBER] = { 0u };
        (void)Ssa_Utils_ConvertSerialNumber(&rawCertData[parsedCert->serialNumber.elemDataIdx], parsedCert->serialNumber.elemDataLength, serial, SSA_SIZEOF_SERIALNUMBER);
        (void)Rte_Call_SecLog_SuccessfulCertVerificationEvent_SuccessfulCertificateVerification(serial, parsedCert->pkiRole);
      }
    }
    /* #30 Always write a log entry for the event "Failed Certificate Verification". */
    else
    {
      (void)Rte_Call_SecLog_FailedCertVerificationEvent_FailedCertificateVerification(parsedCert->pkiRole, parsedCert->verificationResult);
    }
  }
}

#define Ssa_CertP_STOP_SEC_CODE
#include "Ssa_CertP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SAFEBSW JUSTIFICATIONS
 *********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

  \ID  VCA_SSA_CERTP_LEVEL_OF_CERT_ELEMENT
    \DESCRIPTION      According to VCA, the following assertions may be violated:
                        - StackElementPtr == &WorkspacePtr->Stack[Level] and
                        - Level == (WorkspacePtr->CurrentDepth - 1u)
                      in function CertP_BerGetElement_Core(), which takes WorkspacePtr as a parameter of type
                      CertP_BerWorkspaceType *.
    \COUNTERMEASURE   \N The root of each call tree leading to CertP_BerGetElement_Core() is either 
                      - Ssa_CertP_Certificate_Parse() or
                      - Ssa_CertP_AttributeCertificate_Parse().
                      This is ensured by review.
                      Both functions act similar as they initialize a local variable as workspace before calling
                      any other function. When the workspace is initialized, the workspace member Stack of type
                      CertP_BerStackElementType is set to point to another local variable, namely an array of length 
                      CERTP_MAX_DEPTH_OF_ONE_ELEMENT of type CertP_BerStackElementType. This is ensured by
                      an inline assertion within CertP_BerGetElement_Core() and by review.
                      Within CertP_BerGetElement_Core(), the local variable StackElementPtr is set to 
                      StackElementPtr = &WorkspacePtr->Stack[Level], where the workspace member Stack was
                      initialized as described above.
                      - Throughout CertP_BerGetElement_Core() it always holds that 
                        Level = WorkspacePtr->CurrentDepth - 1u. This is ensured by review.
                      - Initially, WorkspacePtr->CurrentDepth = 1. This is ensured by an inline assertion.
                      - This implies that initially, Level = 0, thus the first access to
                        &WorkspacePtr->Stack[Level] is valid. This is ensured by an inline assertion.
                      - The value of Level may be increased within CertP_BerGetElement_Core(); however, the
                        following bounds hold:
                        - Level = CurrentDepth -1 (see above).
                        - ElementDepth <= CERTP_MAX_DEPTH_OF_ONE_ELEMENT. This is ensured by an inline assertion.
                        - The values of Level and CurrentDepth are only incremented, if ElementDepth > CurrentDepth.
                          This is ensured by a runtime check.
                          Thus, in this case it holds that Level = CurrentDepth - 1 <= ElementDepth - 2.
                          Hence, if the value of Level is increased by 1, it still holds that Level <= CERTP_MAX_DEPTH_OF_ONE_ELEMENT - 1
                          and thus StackElementPtr == &WorkspacePtr->Stack[Level] is a valid access.

  \ID  VCA_SSA_CERTP_RAW_CERT_LENGTH
    \DESCRIPTION      According to VCA, the following assertions may be violated:
                        - $lengthOf(rawCertData) >= sizeof(CertP_RawCertBufferType) and
                        - $lengthOf(rawCertIssuer) >= sizeof(CertP_RawCertBufferType)
                      in functions
                      - Ssa_CertP_Certificate_Verify() and
                      - Ssa_CertP_Certificate_Verify_Extended(),
                      when function CertP_Certificate_Verify() is called.
    \COUNTERMEASURE   \N The length values are asserted by specification when Ssa_CertP_Certificate_Verify()
                      and Ssa_CertP_Certificate_Verify_Extended() are called. The parameters rawCertData and
                      rawCertIssuer are passed on without being modified.
                      In particular, in function CertP_Certificate_Verify() a state machine is processed
                      before the justification is used. Throughout this state machine, the pointers point
                      to the same addresses all the time. This is ensured by review.
                      Thus, the assertions still hold within function CertP_Certificate_Verify().

  \ID  VCA_SSA_CERTP_INDEXED_ACCESS_TO_RAW_CERT
    \DESCRIPTION      According to VCA, the following assertions may be violated:
                        - &rawCertData[parsedCert->signedCertData.elemDataIdx] != NULL_PTR, 
                        - &rawCertIssuer[parsedCert->publicKey.elemDataIdx] != NULL_PTR and
                        - &rawCertData[parsedCert->signature.elemDataIdx] != NULL_PTR;
                      in function CertP_Certificate_Verify().
    \COUNTERMEASURE   \R It is asserted by specification when CertP_Certificate_Verify() is called, that
                      - $lengthOf(rawCertData) >= sizeof(CertP_RawCertBufferType) and
                      - $lengthOf(rawCertIssuer) >= sizeof(CertP_RawCertBufferType).
                      A runtime check asserts that the indices used to access rawCertData and rawCertIssuer
                      do not exceed sizeof(CertP_RawCertBufferType).

   \ID  VCA_SSA_CERTP_NULL_PTR_REQUIREMENTS_VIOLATED
    \DESCRIPTION      According to VCA, the following function might be called outside its specification:
                      - Rte_Call_TimeM_RealTime_Compare
    \COUNTERMEASURE   \R Before calling the function, all function requirements (specified in Rte.vcaspecs.c) are checked by assertions:
                          - t1 != NULL_PTR;
                          - t2 != NULL_PTR;
                          - result != NULL_PTR;
                         If all assertions are okay, no specifications are violated.

   VCA_JUSTIFICATION_END */

/* FETA_JUSTIFICATION_BEGIN

  \ID FETA_SSA_CERTP_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND
    \DESCRIPTION  According to FETA loop may not terminate
                  in functions
                  - CertP_CompareBerElement(),
                  - CertP_FindStringInSetOfUTF8Strings(),
                  - CertP_IsEqual(),
                  - CertP_Certificate_Verify_SigAlgoIdentifier() and
                  - CertP_BerGetElement_Core().
    \COUNTERMEASURE \N The here applied for loop uses a variable as upper bound that remains unchanged during loop execution 
                       resp. that can never be of a value that is not reachable by the counter variable.
                       The loop's type of the counter variable is appropriate for the loop's type of upper bound variable and is incremented once
                       within each single loop (strictly monotonically increasing).
                       The loops in CertP_BerGetElement_Core() additionally contain break statements, so that the loops can terminate even sooner.

  \ID FETA_SSA_CERTP_PARSING_MANY_SUBELEMENTS_OF_A_SUPERELEMENT
    \DESCRIPTION  According to FETA loop may not terminate
                  in functions
                  - CertP_ParseExtensionsElement() and
                  - CertP_ParseAttributesElement().
    \COUNTERMEASURE \N Both functions successively parse
                       - several extension elements which are part of the certificate extension in CertP_ParseExtensionsElement() or
                       - several attributes which are part of the attribute element of the certificate in CertP_ParseAttributesElement(), respectively.
                       The while loops under consideration have two termination conditions:
                         retVal != E_OK and <lengthValue> == 0,
                       where
                       - <lengthValue> = extensionsSequence.elemDataLength or
                       - <lengthValue> = attributeSequence.elemDataLength, respectively.
                       The loops terminate, if parsing one of the subelements fails, because then retVal != E_OK.
                       If parsing the subelements is successful, in each iteration
                       - extensionsSequence.elemDataLength or
                       - attributeSequence.elemDataLength, respectively,
                       is decreased by a positive value or set to 0, if decreasing would lead to an underflow.
                       The positive value (parsedAttributeBytes or parsedExtensionBytes, respectively) is at least 2,
                       since CertP_BerElementGet sets the difference between the start and the end index of an element
                       to at least 2 (to accomodate for tag and length byte of the element).
                       Thus, in this case, the termination condition <lengthValue> == 0 will be reached after finitely many iterations.

  \ID FETA_SSA_CERTP_WHILE_LOOP_WITH_UNCHANGED_UPPER_BOUND_AND_ADDITIONAL_BREAKS
    \DESCRIPTION  According to FETA the following loops may not terminate:
                    - In function CertP_CompareManyBerElementSetOfUTF8Strings()
                        while ((retrievedLengthOfCurrentUTF8String + 2u) < elem1->elemDataLength) {...}
                    - In function CertP_FindStringInSetOfUTF8Strings():
                         while ((!isEqual) && ((retrievedLengthOfCurrentUTF8String + 2u) < setOfUTF8Strings->elemDataLength))
    \COUNTERMEASURE \N The upper bound elem1->elemDataLength (or setOfUTF8Strings->elemDataLength, respectively)
                       remains unchanged during loop execution.
                       The loop contains several 'validity of data' checks. If one of them is not fulfilled,
                       the loop is terminated via a break statement.
                       If all processed data is valid (i.e., if no break statement is reached),
                       retrievedLengthOfCurrentUTF8String is increased in each single iteration of the loop,
                       i.e., the value of this variable is strictly monotonically increasing.
                       In both loop, the type of the counter variable is appropriate for the type of upper bound variable.
                       Thus, the loop terminates after finitely many iterations.

FETA_JUSTIFICATION_END */

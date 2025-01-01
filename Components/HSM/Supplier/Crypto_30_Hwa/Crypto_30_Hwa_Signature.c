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
/*!        \file  Crypto_30_Hwa_Signature.c
 *        \brief  vHsm Hwa Signature implementation
 *
 *      \details  This file implements the algorithm to generate and verify signatures.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_SIGNATURE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Crypto_30_Hwa.h"
#include "Crypto_30_Hwa_Private.h"
#include "Crypto_30_Hwa_Hw.h"
#include "Crypto_30_Hwa_Custom.h"

#include "vHsm_Api.h"

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
# include "vSecPrim.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (CRYPTO_30_HWA_LOCAL) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL                                               static
#endif

#if !defined (CRYPTO_30_HWA_LOCAL_INLINE) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL_INLINE                                        LOCAL_INLINE
#endif

#ifndef CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL /* COV_CRYPTO_30_HWA_VSECPRIM_HASH_ALGORITHM */
# define CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL                   (1u)
#endif

#ifndef CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL_OR_GREATER /* COV_CRYPTO_30_HWA_VSECPRIM_HASH_ALGORITHM */
# define CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL_OR_GREATER        (2u)
#endif

#ifndef CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_TRUNCATION_ALLOWED /* COV_CRYPTO_30_HWA_VSECPRIM_HASH_ALGORITHM */
# define CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_TRUNCATION_ALLOWED             (4u)
#endif

#define CRYPTO_30_HWA_VSECPRIM_HASH_ALGO_INVALID                           (0xFFu)
#define CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES                        (32u)
#define CRYPTO_30_HWA_ECDSA_SIGNATURE_SIZE_BYTES                           (64u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_ESL_RETVAL(x)                                        (uint8)((x == ESL_ERC_NO_ERROR) ? E_OK : E_NOT_OK)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#if (CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
# define CRYPTO_30_HWA_START_SEC_CONST_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CRYPTO_30_HWA_LOCAL CONST(uint8, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter[CRYPTO_30_HWA_ECDSA_CURVE_P2561_PARAMETER_ARRAY_SIZE_BYTES] =
{
  /*      a   (coefficient A of the curve equation) */
  0xffu, 0xffu, 0xffu, 0xffu, 0x00u, 0x00u, 0x00u, 0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
  0x00u, 0x00u, 0x00u, 0x00u, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xfcu,
  /*      b   (coefficient B of the curve equation) */
  0x5au, 0xc6u, 0x35u, 0xd8u, 0xaau, 0x3au, 0x93u, 0xe7u, 0xb3u, 0xebu, 0xbdu, 0x55u, 0x76u, 0x98u, 0x86u, 0xbcu,
  0x65u, 0x1du, 0x06u, 0xb0u, 0xccu, 0x53u, 0xb0u, 0xf6u, 0x3bu, 0xceu, 0x3cu, 0x3eu, 0x27u, 0xd2u, 0x60u, 0x4bu,
  /*      p   (field prime) */
  0xffu, 0xffu, 0xffu, 0xffu, 0x00u, 0x00u, 0x00u, 0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
  0x00u, 0x00u, 0x00u, 0x00u, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
  /*    Gx - x coordinate   (basepoint of the curve) */
  0x6bu, 0x17u, 0xd1u, 0xf2u, 0xe1u, 0x2cu, 0x42u, 0x47u, 0xf8u, 0xbcu, 0xe6u, 0xe5u, 0x63u, 0xa4u, 0x40u, 0xf2u,
  0x77u, 0x03u, 0x7du, 0x81u, 0x2du, 0xebu, 0x33u, 0xa0u, 0xf4u, 0xa1u, 0x39u, 0x45u, 0xd8u, 0x98u, 0xc2u, 0x96u,
  /*    Gy - y coordinate   (basepoint of the curve) */
  0x4fu, 0xe3u, 0x42u, 0xe2u, 0xfeu, 0x1au, 0x7fu, 0x9bu, 0x8eu, 0xe7u, 0xebu, 0x4au, 0x7cu, 0x0fu, 0x9eu, 0x16u,
  0x2bu, 0xceu, 0x33u, 0x57u, 0x6bu, 0x31u, 0x5eu, 0xceu, 0xcbu, 0xb6u, 0x40u, 0x68u, 0x37u, 0xbfu, 0x51u, 0xf5u,
  /*    n   (order of G) */
  0xffu, 0xffu, 0xffu, 0xffu, 0x00u, 0x00u, 0x00u, 0x00u, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
  0xbcu, 0xe6u, 0xfau, 0xadu, 0xa7u, 0x17u, 0x9eu, 0x84u, 0xf3u, 0xb9u, 0xcau, 0xc2u, 0xfcu, 0x63u, 0x25u, 0x51u
};

# define CRYPTO_30_HWA_STOP_SEC_CONST_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_InitVSecPrimPrehash()
 *********************************************************************************************************************/
/*! \brief          Initiates the calculation of the hash by the vSecPrim.
 *  \details        -
 *  \param[in]      workspace      Workspace of the current job.
 *  \param[in]      hashAlgorithm  Identifier of hash algorithm to be used.
 *  \param[in]      truncation     Identifier how hash truncation should be handled
 *  \return         E_OK           Initialisation of vSecPrim was successful
 *                  E_NOT_OK       Initialisation of vSecPrim was not successful
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_InitVSecPrimPrehash(
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  Crypto_AlgorithmSecondaryFamilyType hashAlgorithm,
  uint8 truncation);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_StartPreHash()
 *********************************************************************************************************************/
/*! \brief          Starts the pre hashing of the input for the generation and verification of a signature.
 *  \details        Prehashing is either calculated by vSecPrim or hardware accelerator. If no prehashing is desired,
 *                  then nothing is done here.
 *  \param[in]      objectId    Object ID.
 *  \param[in]      job         Job pointer.
 *  \param[in]      workspace   Workspace of the current job.
 *  \param[in]      truncation  Type of truncation which is applied to the digest
 *  \return         E_OK        Initialization of hash was successful.
 *                  E_NOT_OK    Initialization of hash failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_StartPreHash(
  uint32 objectId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  uint8 truncation);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_UpdatePreHash()
 *********************************************************************************************************************/
/*! \brief          Updates the pre hashing of the input for the generation and verification of a signature.
 *  \details        Prehashing is either calculated by vSecPrim or hardware accelerator. If no prehashing is desired,
 *                  then nothing is done here.
 *  \param[in]      objectId     Object ID
 *  \param[in]      job          Job pointer.
 *  \param[in]      workspace    Workspace of the current job.
 *  \param[in]      inputPtr     Input data buffer.
 *  \param[in]      inputLength  Input data length.
 *  \return         E_OK         Update of hash was successful.
 *                  E_NOT_OK     Update of hash failed.
 *  \pre            Crypto_30_Hwa_StartPreHash() is called
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_UpdatePreHash(
  uint32 objectId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_FinalizePreHash()
 *********************************************************************************************************************/
/*! \brief          Finalizes the pre hashing of the input for the generation and verification of an ECDSA signature.
 *                  and returns the message digest.
 *  \details        Prehashing is either calculated by vSecPrim or hardware accelerator. If no prehashing is desired,
 *                  then nothing is done here.
 *  \param[in]      objectId             Object ID.
 *  \param[in]      job                  Job pointer.
 *  \param[in]      workspace            Workspace of the current job.
 *  \param[in]      inputPtr             Input data buffer.
 *  \param[in]      inputLength          Input data length.
 *  \param[out]     messageDigest        Digest data buffer.
 *  \param[out]     messageDigestLength  Digest data length.
 *  \return         E_OK                 Finalization of hash was successful.
 *                  E_NOT_OK             Finalization of hash failed.
 *  \pre            Crypto_30_Hwa_UpdatePreHash() is called
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_FinalizePreHash(
  uint32 objectId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) messageDigest,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) messageDigestLength);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CheckGenerateInputParameters()
 *********************************************************************************************************************/
/*! \brief        Checks the validity of the input values for signature generation.
 *  \details      -
 *  \param[in]    privateKeyPtr    Signature data buffer.
 *  \param[in]    outputLengthPtr  Signature data length.
 *  \return       E_OK             Input values are valid.
 *                E_NOT_OK         Input values are not valid
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckGenerateInputParameters(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) privateKeyPtr,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputLengthPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_EcdsaGenerateFinish()
 *********************************************************************************************************************/
/*! \brief          Finalizes the pre hashing of the input and performs the generation of an ECDSA signature.
 *  \details        Prehashing is either calculated by vSecPrim or hardware accelerator. If no prehashing is desired,
 *                  then nothing is done here.
 *  \param[in]      objectId             Object ID.
 *  \param[in]      job                  Job pointer.
 *  \param[in]      workspace            Workspace of the current job.
 *  \param[in]      inputDataPtr         Buffer for the data for which the signature is calculated
 *  \param[in]      inputDataLength      Length of the input data
 *  \param[out]     outputDataPtr        Buffer for the calculated signature.
 *  \param[in,out]  outputLengthPtr      Buffer for the length of the calculated signature.
 *  \return         E_OK                 Signature generate finish step was successful.
 *                  E_NOT_OK             Signature generate finish step failed.
 *  \pre            Crypto_30_Hwa_EcdsaUpdate() is called
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_EcdsaGenerateFinish(
  uint32 objectId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputDataPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputLengthPtr);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CheckVerifyInputParameters()
 *********************************************************************************************************************/
/*! \brief        Checks the validity of the input values.
 *  \details      -
 *  \param[in]    secondaryInputPtr     Signature data buffer.
 *  \param[in]    secondaryInputLength  Signature data length.
 *  \return       E_OK                  Input values are valid.
 *                E_NOT_OK              Input values are not valid
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckVerifyInputParameters(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) secondaryInputPtr,
  uint32 secondaryInputLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_EcdsaVerifyFinish()
 *********************************************************************************************************************/
/*! \brief        Finalizes the pre hashing of the input and performs the verification of an ECDSA signature.
 *  \details      Prehashing is either calculated by vSecPrim or hardware accelerator. If no prehashing is desired,
 *                the ECDSA signature is verified over the input.
 *  \param[in]    objectId              Object ID.
 *  \param[in]    job                   Job pointer.
 *  \param[in]    workspace             Workspace of the current job.
 *  \param[in]    cryptoKeyId           Id of the used key.
 *  \param[in]    inputDataPtr          Buffer of the input for which the signature is verified
 *  \param[in]    inputDataLength       Length of the input data
 *  \param[in]    signatureDataPtr      Buffer for the signature to be verified against
 *  \param[in]    signatureDataLength   Length of the signature
 *  \param[out]   verifyPtr             Verify result data buffer.
 *  \return       E_OK                  Signature verify finish step was successful.
 *                E_NOT_OK              Signature verify finish step failed.
 *  \pre          Crypto_30_Hwa_EcdsaUpdate() called before.
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_EcdsaVerifyFinish(
  uint32 objectId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) signatureDataPtr,
  uint32 signatureDataLength,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) verifyPtr);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CheckEd25519GenerateInputParameters()
 *********************************************************************************************************************/
/*! \brief        Checks the validity of the input values for signature generation.
 *  \details      -
 *  \param[in]    outputLengthPtr  Signature data length.
 *  \return       E_OK             Input values are valid.
 *                E_NOT_OK         Input values are not valid
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckEd25519GenerateInputParameters(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputLengthPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Ed25519GenerateStart()
 *********************************************************************************************************************/
/*! \brief          Initiates the generation of an EDDSA signature.
 *  \details        If prehashing is desired, it is calculated by vSecPrim.
 *  \param[in]      objectId     Object ID.
 *  \param[out]     errorIdPtr   Error ID
 *  \param[in]      job          Job pointer.
 *  \param[in]      workspace    Workspace of the current job.
 *  \return         E_OK         Signature generate start step was successful.
 *                  E_NOT_OK     Signature generate start step failed.
 *  \pre            - is called
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Ed25519GenerateStart(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Ed25519GenerateUpdate()
 *********************************************************************************************************************/
/*! \brief          Updates the generation of an EDDSA signature.
 *  \details        If prehashing is desired, it is calculated by vSecPrim.
 *  \param[in]      objectId         Object ID.
 *  \param[out]     errorIdPtr       Error ID
 *  \param[in]      job              Job pointer.
 *  \param[in]      workspace        Workspace of the current job.
 *  \param[in]      inputDataPtr     Input data buffer.
 *  \param[in]      inputDataLength  Input data length.
 *  \return         E_OK             Signature generate update step was successful.
 *                  E_NOT_OK         Signature generate update step failed.
 *  \pre            Crypto_30_Hwa_Ed25519GenerateStart() is called
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Ed25519GenerateUpdate(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Ed25519GenerateFinish()
 *********************************************************************************************************************/
/*! \brief          Finalizes the pre hashing of the input and performs the generation of an EDDSA signature.
 *  \details        If prehashing is desired, it is calculated by vSecPrim.
 *  \param[in]      objectId               Object ID.
 *  \param[out]     errorIdPtr             Error ID
 *  \param[in]      job                    Job pointer.
 *  \param[in]      workspace              Workspace of the current job.
 *  \param[in]      cryptoKeyId            Id of the used key.
 *  \param[in]      inputDataPtr           Input data buffer.
 *  \param[in]      inputDataLength        Input data length.
 *  \param[in]      contextDataPtr         Context data buffer.
 *  \param[in]      contextDataLength      Context data length.
 *  \param[out]     outputBufferPtr        Output data buffer.
 *  \param[in,out]  outputBufferLengthPtr  Output data length.
 *  \return         E_OK                   Signature generate finish step was successful.
 *                  E_NOT_OK               Signature generate finish step failed.
 *  \pre            Crypto_30_Hwa_Ed25519GenerateUpdate() is called
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Ed25519GenerateFinish(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) contextDataPtr,
  uint32 contextDataLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputBufferPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputBufferLengthPtr);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CheckContext()
 *********************************************************************************************************************/
/*! \brief        Checks if a valid context is provided and copies the pointer and length to the workspace.
 *  \details      -
 *  \param[in]    workspace            Workspace of the current job.
 *  \param[in]    tertiaryInputPtr     context data buffer.
 *  \param[in]    tertiaryInputLength  context data length.
 *  \return       E_OK                 Signature verify finish step was successful.
 *                E_NOT_OK             Signature verify finish step failed.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckContext(
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) tertiaryInputPtr,
  uint32 tertiaryInputLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessSigRPartAndKeyUpdate()
 *********************************************************************************************************************/
/*! \brief        Updates the signature part during the hashing phase of the Ed25519 signature verification.
 *  \details      -
 *  \param[in]    workspace             Workspace of the current job.
 *  \param[in]    secondaryInputPtr     Signature data buffer.
 *  \param[in]    secondaryInputLength  Signature data length.
 *  \return       E_OK                  Input values are valid.
 *                E_NOT_OK              Input values are not valid
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessSigRPartAndKeyUpdate(
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) secondaryInputPtr,
  uint32 secondaryInputLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CheckEd25519VerifyInputParameters()
 *********************************************************************************************************************/
/*! \brief        Checks the validity of the input values.
 *  \details      -
 *  \param[in]    secondaryInputLength  Signature data length.
 *  \return       E_OK                  Input values are valid.
 *                E_NOT_OK              Input values are not valid
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckEd25519VerifyInputParameters(
  uint32 secondaryInputLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Ed25519VerifyStart()
 *********************************************************************************************************************/
/*! \brief        Initiates the verification of an Ed25519 signature.
 *  \details      If prehashing is desired, it is calculated by vSecPrim.
 *  \param[in]    objectId             Object ID.
 *  \param[out]   errorIdPtr           Error ID
 *  \param[in]    job                  Job pointer.
 *  \param[in]    workspace            Workspace of the current job.
 *  \param[in]    cryptoKeyId          Crypto Key ID.
 *  \param[in]    signatureDataPtr     Signature data buffer.
 *  \param[in]    signatureDataLength  Signature data length.
 *  \param[in]    contextDataPtr       Context data buffer.
 *  \param[in]    contextDataLength    Context data length.
 *  \return       E_OK                 Signature verify start step was successful.
 *                E_NOT_OK             Signature verify start step failed.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Ed25519VerifyStart(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) signatureDataPtr,
  uint32 signatureDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) contextDataPtr,
  uint32 contextDataLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Ed25519VerifyUpdate()
 *********************************************************************************************************************/
/*! \brief        Updates the verification of an Ed25519 signature.
 *  \details      If prehashing is desired, it is calculated by vSecPrim.
 *  \param[in]    objectId             Object ID.
 *  \param[out]   errorIdPtr           Error ID
 *  \param[in]    job                  Job pointer.
 *  \param[in]    workspace            Workspace of the current job.
 *  \param[in]    inputDataPtr         Input data buffer.
 *  \param[in]    inputDataLength      Input data length.
 *  \param[in]    signatureDataPtr     Signature data buffer.
 *  \param[in]    signatureDataLength  Signature data length.
 *  \param[in]    contextDataPtr       Context data buffer.
 *  \param[in]    contextDataLength    Context data length.
 *  \return       E_OK                 Signature verify update step was successful.
 *                E_NOT_OK             Signature verify update step failed.
 *  \pre          Crypto_30_Hwa_Ed25519VerifyStart() is called
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Ed25519VerifyUpdate(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) signatureDataPtr,
  uint32 signatureDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) contextDataPtr,
  uint32 contextDataLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Ed25519VerifyFinish()
 *********************************************************************************************************************/
/*! \brief        Finalizes the pre hashing of the input and performs the verification of an Ed25519 signature.
 *  \details      If prehashing is desired, it is calculated by vSecPrim.
 *  \param[in]    objectId              Object ID.
 *  \param[out]   errorIdPtr            Error ID
 *  \param[in]    job                   Job pointer.
 *  \param[in]    workspace             Workspace of the current job.
 *  \param[in]    inputPtr              Input data buffer.
 *  \param[in]    inputLength           Input data length.
 *  \param[in]    secondaryInputPtr     Signature data buffer.
 *  \param[in]    secondaryInputLength  Signature data length.
 *  \param[out]   verifyPtr             Verify result data buffer.
 *  \return       E_OK                  Signature verify finish step was successful.
 *                E_NOT_OK              Signature verify finish step failed.
 *  \pre          Crypto_30_Hwa_Ed25519VerifyUpdate() called before.
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Ed25519VerifyFinish(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) secondaryInputPtr,
  uint32 secondaryInputLength,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) verifyPtr);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/*********************************************************************************************************************
 *  Crypto_30_Hwa_StartPreHash()
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
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_StartPreHash(
  uint32 objectId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  uint8 truncation)
{
  Std_ReturnType retVal;

  /* #10 Check how prehash should be calculated */
  switch (job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily)
  {
    /* #11 No prehashing required, nothing to do */
  case CRYPTO_ALGOFAM_NOT_SET:
    retVal = E_OK;
    break;

# if(CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON)
  case CRYPTO_ALGOFAM_SHA2_256:
    /* #20 Check if hash algorithm can be calculated in hardware */
    if (Crypto_30_Hwa_IsSHA256UsedOfObjectInfo(objectId) == TRUE)
    {
      /* #21 Prepare and start SHA256 hash job to calculate prehash in hardware */
      retVal = Crypto_30_Hwa_Sha256Start(&workspace->sha256Workspace);
    }
    else /* #22 Hash algorithm is supported in hardware but not available. Calculate SHA256 prehash by vSecPrim */
    {
      /* #23 Initialize hash calculation by vSecPrim */
      retVal = Crypto_30_Hwa_InitVSecPrimPrehash(workspace, job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily, truncation);
    }
    break;
# endif
    /* #30 Hash algorithm is not supported in hardware and needs to be calculated by vSecPrim */
  default:

    /* #31 Initialize hash calculation by vSecPrim */
    retVal = Crypto_30_Hwa_InitVSecPrimPrehash(workspace, job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily, truncation);
    break;
  }

# if(CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_OFF)
  CRYPTO_30_HWA_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}

/*********************************************************************************************************************
 *  Crypto_30_Hwa_InitVSecPrimPrehash()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_InitVSecPrimPrehash(
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  Crypto_AlgorithmSecondaryFamilyType hashAlgorithm,
  uint8 truncation)
{
  Std_ReturnType retVal;
  uint8 esLibHashAlgoIdentifier = CRYPTO_30_HWA_VSECPRIM_HASH_ALGO_INVALID;

  /* #10 Get hash algorithm identifier for vSecPrim */
  if (hashAlgorithm < Crypto_30_Hwa_GetSizeOfFamilyToHashMapping())
  {
    esLibHashAlgoIdentifier = Crypto_30_Hwa_GetFamilyToHashMapping(hashAlgorithm);
  }

  /* #20 Initialize hash calculation of vSecPrim */
  retVal = CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_initHash(&workspace->vSecPrim_HashWorkSpace, esLibHashAlgoIdentifier, truncation));

  return retVal;
}

/*********************************************************************************************************************
 *  Crypto_30_Hwa_UpdatePreHash()
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
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_UpdatePreHash(
  uint32 objectId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength)
{
  Std_ReturnType retVal;

  /* #10 Check how prehash can be calculated */
  switch (job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily)
  {
    /* #11 No prehashing required, nothing to do */
  case CRYPTO_ALGOFAM_NOT_SET:
    retVal = E_OK;
    break;

# if(CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON)
  case CRYPTO_ALGOFAM_SHA2_256:
    /* #20 Check if hash algorithm can be calculated in hardware */
    if (Crypto_30_Hwa_IsSHA256UsedOfObjectInfo(objectId) == TRUE)
    {
      /* #21 Update SHA256 hash job to calculate prehash in hardware */
      retVal = Crypto_30_Hwa_Sha256Update(&workspace->sha256Workspace, inputPtr, inputLength);
    }
    else /* #22 Hash algorithm is supported in hardware but not available. Calculate SHA256 prehash by vSecPrim */
    {
      /* #23 Update hash calculation of vSecPrim */
      retVal = CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, inputLength, inputPtr));
    }
    break;
# endif
    /* #30 Hash algorithm is not supported in hardware and needs to be calculated by vSecPrim */
  default:
    /* #31 Update hash calculation of vSecPrim */
    retVal = CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, inputLength, inputPtr));
    break;
  }

# if(CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_OFF)
  CRYPTO_30_HWA_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}

/*********************************************************************************************************************
 *  Crypto_30_Hwa_FinalizePreHash()
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
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_FinalizePreHash(
  uint32 objectId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) messageDigest,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) messageDigestLength)
{
  Std_ReturnType retVal = E_OK;

  /* #10 Check how prehash can be calculated */
  switch (job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily)
  {
    /* #11 No prehashing required, nothing to do */
    case CRYPTO_ALGOFAM_NOT_SET:
      retVal = E_OK;
      break;

#  if(CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON)
    /* #20 Check if hash algorithm can be calculated in hardware */
    case CRYPTO_ALGOFAM_SHA2_256:
      if (Crypto_30_Hwa_IsSHA256UsedOfObjectInfo(objectId) == TRUE)
      {
        /* #21 Finish SHA256 hash job to calculate prehash in hardware */
        if ((job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_FINISH) && (inputLength > 0u))
        {
          retVal = Crypto_30_Hwa_Sha256Update(&workspace->sha256Workspace, inputPtr, inputLength);
        }

        retVal |= Crypto_30_Hwa_Sha256Finish(&workspace->sha256Workspace, messageDigest, messageDigestLength);
      }
      else /* #22 Hash algorithm is supported in hardware but not available. Calculate SHA256 prehash by vSecPrim */
      {
        /*  #24 Finish hash calculation of vSecPrim */
        if ((job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_FINISH) && (inputLength > 0u))
        {
          retVal = CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, inputLength, inputPtr));
        }

        retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_finalizeHash(&workspace->vSecPrim_HashWorkSpace,  messageDigestLength, messageDigest));
      }
      break;
#  endif
    /* #30 Hash algorithm is not supported in hardware and needs to be calculated by vSecPrim */
    default:

      if ((job->jobPrimitiveInputOutput.mode == CRYPTO_OPERATIONMODE_FINISH) && (inputLength > 0u))
      {
        retVal = CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, inputLength, inputPtr));
      }

      retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_finalizeHash(&workspace->vSecPrim_HashWorkSpace,  messageDigestLength, messageDigest));
      break;
  }

# if(CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_OFF)
  CRYPTO_30_HWA_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/*********************************************************************************************************************
 *  Crypto_30_Hwa_CheckGenerateInputParameters()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckGenerateInputParameters(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) privateKeyPtr,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputLengthPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* Check if output length is sufficient to store signature */
  if (*outputLengthPtr < CRYPTO_30_HWA_SIGNATURE_SIZE_BYTES)
  {
    /* Output buffer size is not sufficient; Do nothing, return value is already set. */
  }
  /* Check if private key is greater than zero */
  else if (Crypto_30_Hwa_IsBignumZeroBe(privateKeyPtr, CRYPTO_30_HWA_ECDSA_PRIVATE_KEY_SIZE_BYTES) == TRUE)
  {
    /* Private key is zero; Do nothing, return value is already set. */
  }
  /* Check if private key is smaller than order of cyclic group */
  else if (Crypto_30_Hwa_CompareBignumsBe(privateKeyPtr,
    &Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_ORDER_BASEPOINT_N_OFFSET],
    CRYPTO_30_HWA_ECDSA_PRIVATE_KEY_SIZE_BYTES) != CRYPTO_30_HWA_ECDSA_BIGNUM_SMALLER)
  {
    /* Private key is equal or greater than n; Do nothing, return value is already set. */
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
}

/*********************************************************************************************************************
 *  Crypto_30_Hwa_EcdsaGenerateFinish()
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
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_EcdsaGenerateFinish(
  uint32 objectId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputDataPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputLengthPtr)
{
  Std_ReturnType retVal;

  vHsm_Api_KeyStorageIndexType index = 0u;
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key;

  uint8 inputPadded[CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES] = { 0u };
  uint8 messageDigest[CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES] = { 0u };
  uint8 ephemeralKey[CRYPTO_30_HWA_ECDSA_EPHEMERAL_KEY_SIZE_BYTES] = { 0u };

  boolean signatureFound = FALSE;

  uint32 trngSize = CRYPTO_30_HWA_ECDSA_EPHEMERAL_KEY_SIZE_BYTES;
  uint32 messageDigestLength = sizeof(messageDigest);

  /* #10 Finalize prehashing if required and return message digest */
  retVal = Crypto_30_Hwa_FinalizePreHash(objectId, job, workspace,
                                         inputDataPtr, inputDataLength,
                                         messageDigest, &messageDigestLength);

  /* #11 Get key index */
  retVal |= vHsm_Api_KeyElementGetForCryptoJobs(job->cryptoKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                                &index, CRYPTO_30_HWA_ECDSA_PRIVATE_KEY_SIZE_BYTES, VHSM_API_SHE_SERVICE_OTHER);

  if (retVal != E_OK)
  {
    /* Do nothing. Return value is already set. */
  }
  else
  {
    /* #12 Get key */
    key = vHsm_Api_GetAddrKeyStorage(index);

    /* #13 Check if input parameters are valid */
    retVal = Crypto_30_Hwa_CheckGenerateInputParameters(key, outputLengthPtr);

    if (retVal == E_OK)
    {
      /* Normally, one execution should be enough but specification requires to choose new random ephemeral key
         and repeat signature generation if R or S have the value zero with the current ephemeral key. */
      while (signatureFound == FALSE)
      {
        /* #20 Randomly select ephemeral key. If ephemeral key is not within valid boundaries, select new ephemeral key. */
        do
        {
          retVal = Crypto_30_Hwa_TrngFinish(ephemeralKey, &trngSize);

          /* #21 Check if ephemeral key is valid */
          if (Crypto_30_Hwa_IsBignumZeroBe(ephemeralKey,
            CRYPTO_30_HWA_ECDSA_EPHEMERAL_KEY_SIZE_BYTES) == TRUE)
          {
            retVal |= E_NOT_OK;
          }
          else if (Crypto_30_Hwa_CompareBignumsBe(ephemeralKey, &Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_ORDER_BASEPOINT_N_OFFSET],
            CRYPTO_30_HWA_ECDSA_EPHEMERAL_KEY_SIZE_BYTES) != CRYPTO_30_HWA_ECDSA_BIGNUM_SMALLER)
          {
            retVal |= E_NOT_OK;
          }
          else
          {
            /* Do nothing. Ephemeral key is within boundaries and return value is already set. */
          }
        } while (retVal != E_OK);

        /* #30 Process signature verification */
        if (job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily == CRYPTO_ALGOFAM_NOT_SET)
        {
          /* #31 Check if input needs to be padded if no prehashing is set */
          if (inputDataLength < CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES)
          {
            VStdMemCpy(&inputPadded[CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES - inputDataLength], inputDataPtr, inputDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

            retVal = Crypto_30_Hwa_Hw_EcdsaGenerateFinish(job, workspace, Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter, key, ephemeralKey,
                                                          inputPadded, CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES,
                                                          outputDataPtr, outputLengthPtr);
          }
          else if (inputDataLength == CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES)
          {
            retVal = Crypto_30_Hwa_Hw_EcdsaGenerateFinish(job, workspace, Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter, key, ephemeralKey,
                                                          inputDataPtr, inputDataLength,
                                                          outputDataPtr, outputLengthPtr);
          }
          else
          {
            /* #32 Message is too long to be processed */
            retVal = E_NOT_OK;
          }
        }
        else
        {
          /* #40 Check if hash digest needs to be padded */
          if (messageDigestLength < CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES)
          {
            VStdMemCpy(&inputPadded[CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES - messageDigestLength], messageDigest, messageDigestLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

            retVal = Crypto_30_Hwa_Hw_EcdsaGenerateFinish(job, workspace, Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter, key, ephemeralKey,
                                                          inputPadded, CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES,
                                                          outputDataPtr, outputLengthPtr);
          }
          else
          {
            retVal = Crypto_30_Hwa_Hw_EcdsaGenerateFinish(job, workspace, Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter, key, ephemeralKey,
                                                          messageDigest, messageDigestLength,
                                                          outputDataPtr, outputLengthPtr);
          }
        }

        /* #50 Check if error occurred in previous calculation step. */
        if (retVal == E_OK)
        {
          /* #51 Check if R or S has value zero. If this is the case, select new ephemeral key and repeat signature generation. */
          if (Crypto_30_Hwa_IsBignumZeroBe(outputDataPtr, CRYPTO_30_HWA_ECDSA_SIGNATURE_R_SIZE_BYTES) == TRUE)
          {
            /* Do nothing. Loop will restart, select new ephemeral key and repeat signature calculation. */
          }
          else if (Crypto_30_Hwa_IsBignumZeroBe(&outputDataPtr[CRYPTO_30_HWA_ECDSA_SIGNATURE_S_OFFSET], CRYPTO_30_HWA_ECDSA_SIGNATURE_S_SIZE_BYTES) == TRUE)
          {
            /* Do nothing. Loop will restart, select new ephemeral key and repeat signature calculation. */
          }
          else
          {
            /* #52 R and S are valid. Exit loop and return signature. */
            signatureFound = TRUE;
          }
        }
        else
        {
          signatureFound = TRUE; /* Error has occurred. Exit loop and return error. */
        }
      }
    }
  }

  return retVal;
} /* PRQA S 6010, 6030, 6050, 6060, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/*********************************************************************************************************************
 *  Crypto_30_Hwa_CheckVerifyInputParameters()
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
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckVerifyInputParameters(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) secondaryInputPtr,
  uint32 secondaryInputLength)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* Check if size of signature is correct */
  if (secondaryInputLength != CRYPTO_30_HWA_SIGNATURE_SIZE_BYTES)
  {
    /* Signature length is not sufficient; Do nothing, return value is already set. */
  }
  /* Check if signature part r is greater than zero */
  else if (Crypto_30_Hwa_IsBignumZeroBe(secondaryInputPtr, CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES) == TRUE)
  {
    /* r is equal to zero; Do nothing, return value is already set. */
  }
  /* Check if signature part s is greater than zero */
  else if (Crypto_30_Hwa_IsBignumZeroBe(&secondaryInputPtr[CRYPTO_30_HWA_ECDSA_SIGNATURE_S_OFFSET], CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES) == TRUE)
  {
    /* s is equal to zero; Do nothing, return value is already set. */
  }
  /* Check if signature part r is smaller than order of cyclic group */
  else if (Crypto_30_Hwa_CompareBignumsBe(secondaryInputPtr,
    &Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_ORDER_BASEPOINT_N_OFFSET],
    CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES) != CRYPTO_30_HWA_ECDSA_BIGNUM_SMALLER)
  {
    /* r is equal to or greater than order of cyclic group; Do nothing, return value is already set. */
  }
  /* Check if signature part s is smaller than order of cyclic group */
  else if (Crypto_30_Hwa_CompareBignumsBe(&secondaryInputPtr[CRYPTO_30_HWA_ECDSA_SIGNATURE_S_OFFSET],
    &Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_ORDER_BASEPOINT_N_OFFSET],
    CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES) != CRYPTO_30_HWA_ECDSA_BIGNUM_SMALLER)
  {
    /* s is equal to or greater than order of cyclic group; Do nothing, return value is already set. */
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/*********************************************************************************************************************
 *  Crypto_30_Hwa_EcdsaVerifyFinish()
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
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_EcdsaVerifyFinish(
  uint32 objectId,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) signatureDataPtr,
  uint32 signatureDataLength,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) verifyPtr)
{
  Std_ReturnType retVal;

  vHsm_Api_KeyStorageIndexType index = 0u;
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key;

  uint8 inputPadded[CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES] = { 0u };
  uint8 messageDigest[CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES] = { 0u };
  uint32 messageDigestLength = sizeof(messageDigest);

  /* #10 Finalize prehashing if required and return message digest */
  retVal = Crypto_30_Hwa_FinalizePreHash(objectId, job, workspace,
                                         inputDataPtr, inputDataLength,
                                         messageDigest, &messageDigestLength);

  /* #20 Get key index */
  retVal |= vHsm_Api_KeyElementGetForCryptoJobs(cryptoKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                                &index, CRYPTO_30_HWA_ECDSA_PUBLIC_KEY_SIZE_BYTES, VHSM_API_SHE_SERVICE_OTHER);

  if (retVal != E_OK)
  {
    /* Do nothing. Return value already set. */
  }
  else
  {
    /* #30 Get key */
    key = vHsm_Api_GetAddrKeyStorage(index);

    /* #32 Check if input parameters are valid */
    retVal = Crypto_30_Hwa_CheckVerifyInputParameters(signatureDataPtr, signatureDataLength);

    /* #33 Process signature verification */
    if (retVal != E_OK)
    {
      /* Do nothing. Return value already set. */
    }
    else if (job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily == CRYPTO_ALGOFAM_NOT_SET)
    {
      /* #40 Check if input needs to be padded if no prehashing is set */
      if (inputDataLength < CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES)
      {
        VStdMemCpy(&inputPadded[CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES - inputDataLength], inputDataPtr, inputDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

        retVal = Crypto_30_Hwa_Hw_EcdsaVerifyFinish(job, workspace, Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter, key,
                                                    inputPadded, CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES,
                                                    signatureDataPtr, signatureDataLength,
                                                    verifyPtr);
      }
      else if (inputDataLength == CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES)
      {
        retVal = Crypto_30_Hwa_Hw_EcdsaVerifyFinish(job, workspace, Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter, key,
                                                    inputDataPtr, inputDataLength,
                                                    signatureDataPtr, signatureDataLength,
                                                    verifyPtr);
      }
      else
      {
        /* #41 Message is too long to be processed */
        retVal = E_NOT_OK;
      }
    }
    else
    {
      /* #50 Check if hash digest needs to be padded */
      if (messageDigestLength < CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES)
      {
        VStdMemCpy(&inputPadded[CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES - messageDigestLength], messageDigest, messageDigestLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

        retVal = Crypto_30_Hwa_Hw_EcdsaVerifyFinish(job, workspace, Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter, key,
                                                    inputPadded, CRYPTO_30_HWA_ECDSA_SIGINPUT_MAX_SIZE_BYTES,
                                                    signatureDataPtr, signatureDataLength,
                                                    verifyPtr);
      }
      else
      {
        retVal = Crypto_30_Hwa_Hw_EcdsaVerifyFinish(job, workspace, Crypto_30_Hwa_EccCurveNistAnsiSecP256R1_CurveParameter, key,
                                                    messageDigest, messageDigestLength,
                                                    signatureDataPtr, signatureDataLength,
                                                    verifyPtr);
      }
    }
  }

  return retVal;
} /* PRQA S 6060, 6080 */ /* MD_MSR_STPAR, MD_MSR_STMIF */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/*********************************************************************************************************************
 *  Crypto_30_Hwa_Ed25519GenerateStart()
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
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Ed25519GenerateStart(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace)
{
  Std_ReturnType retVal;

  /* #10 Check which mode is used */
  switch (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
  {
    case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PURE:
    case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_CTX:

      /* #20 Call hardware specific start function */
      retVal = Crypto_30_Hwa_Hw_Ed25519GenerateStart(job, workspace);
      *errorIdPtr = CRYPTO_E_NO_ERROR;
      break;

    case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PH:

      /* #30 Initialize calculation of prehash */
      retVal = Crypto_30_Hwa_StartPreHash(objectId, job, workspace, CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL);

      /* #31 Call hardware specific start function */
      retVal |= Crypto_30_Hwa_Hw_Ed25519GenerateStart(job, workspace);
      *errorIdPtr = CRYPTO_E_NO_ERROR;

      break;

    default: /* COV_CRYPTO_30_HWA_CASE_DEFAULT */
      retVal = E_NOT_OK;  /* Unsupported mode. */
      break;
  }

  return retVal;
}

/*********************************************************************************************************************
 *  Crypto_30_Hwa_Ed25519GenerateUpdate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Ed25519GenerateUpdate(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength)
{
  Std_ReturnType retVal;

  /* #10 Check which mode is used */
  switch (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
  {
    case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PURE:
    case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_CTX:

      /* #20 Call hardware specific update function */
      retVal = Crypto_30_Hwa_Hw_Ed25519GenerateUpdate(job, workspace, inputDataPtr, inputDataLength);
      *errorIdPtr = CRYPTO_E_NO_ERROR;
      break;

    case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PH:

      /* #30 Update calculation of prehash */
      retVal = Crypto_30_Hwa_UpdatePreHash(objectId, job, workspace, inputDataPtr, inputDataLength);

      /* #31 Call hardware specific update function */
      retVal |= Crypto_30_Hwa_Hw_Ed25519GenerateUpdate(job, workspace, inputDataPtr, inputDataLength);
      *errorIdPtr = CRYPTO_E_NO_ERROR;
      break;

    default: /* COV_CRYPTO_30_HWA_CASE_DEFAULT */
      retVal = E_NOT_OK; /* Unsupported mode. */
        break;
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/*********************************************************************************************************************
 *  Crypto_30_Hwa_CheckEd25519GenerateInputParameters()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckEd25519GenerateInputParameters(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputLengthPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* Check if size of output buffer is big enough to store signature */
  if (*outputLengthPtr >= (CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_R_SIZE_BYTES + CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_S_SIZE_BYTES))
  {
    retVal = E_OK;
  }

  return retVal;
}

/*********************************************************************************************************************
 *  Crypto_30_Hwa_Ed25519GenerateFinish()
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
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Ed25519GenerateFinish(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) contextDataPtr,
  uint32 contextDataLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputBufferPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputBufferLengthPtr)
{
  Std_ReturnType retVal;

  uint8 preHash[64u] = { 0u };
  uint32 preHashLength = sizeof(preHash);

  vHsm_Api_KeyStorageIndexType index = 0u;
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key;

  /* #10 Check input parameters */
  retVal = Crypto_30_Hwa_CheckEd25519GenerateInputParameters(outputBufferLengthPtr);

  /* #11 Get key index */
  retVal |= vHsm_Api_KeyElementGetForCryptoJobs(cryptoKeyId, CRYPTO_KE_SIGNATURE_KEY,
    &index, CRYPTO_30_HWA_EDDSA_ED25519_PRIVATE_KEY_SIZE_BYTES, VHSM_API_SHE_SERVICE_OTHER);

  if (retVal != E_OK)
  {
    *errorIdPtr = CRYPTO_E_NO_ERROR;
  }
  else
  {
    /* #20 Get key */
    key = vHsm_Api_GetAddrKeyStorage(index);

    /* #30 Check which mode is used */
    switch (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
    {
      case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PURE:
      case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_CTX:

        /* #40 Call hardware specific finish function */
        retVal = Crypto_30_Hwa_Hw_Ed25519GenerateFinish(job, workspace, key, inputDataPtr, inputDataLength, contextDataPtr, contextDataLength, outputBufferPtr, outputBufferLengthPtr);
        *errorIdPtr = CRYPTO_E_NO_ERROR;
        break;

      case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PH:

        /* #50 Finalize prehash of message */
        retVal = Crypto_30_Hwa_FinalizePreHash(objectId, job, workspace, inputDataPtr, inputDataLength, preHash, &preHashLength);

        /* #51 Call hardware specific finish function */
        retVal |= Crypto_30_Hwa_Hw_Ed25519GenerateFinish(job, workspace, key, preHash, preHashLength, contextDataPtr, contextDataLength, outputBufferPtr, outputBufferLengthPtr);
        *errorIdPtr = CRYPTO_E_NO_ERROR;
        break;

      default: /* COV_CRYPTO_30_HWA_CASE_DEFAULT */
        retVal = E_NOT_OK;  /* Unsupported mode. */
        break;
    }
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/*********************************************************************************************************************
 *  Crypto_30_Hwa_CheckContext()
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
 *
 *
  */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckContext(
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) tertiaryInputPtr,
  uint32 tertiaryInputLength)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Check if context is provided */
  if (tertiaryInputPtr != NULL_PTR)
  {
    /* #11 Check if context fulfills length constraints */
    if ((tertiaryInputLength > 0u) && (tertiaryInputLength < CRYPTO_30_HWA_EDDSA_CONTEXT_MAX_SIZE_BYTE))
    {
      /* #12 Store pointers to context */
      VStdMemCpy(workspace->context, tertiaryInputPtr, tertiaryInputLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      workspace->contextLength = tertiaryInputLength;
      workspace->contextSet = TRUE;

      retVal = E_OK;
    }
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
}

/*********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessSigRPartAndKeyUpdate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessSigRPartAndKeyUpdate(
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) secondaryInputPtr,
  uint32 secondaryInputLength)
{
  Std_ReturnType retVal;

  /* #10 Check if signature has already been processed */
  if (workspace->signatureProcessed == FALSE)
  {
    if (workspace->signatureSet == TRUE)
    {
      /* #11 If signature was provided in START step of streaming, update hash calculation signature */
      retVal = CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_R_SIZE_BYTES, workspace->signature));
      workspace->signatureProcessed = TRUE;
    }
    else if ((secondaryInputPtr != NULL_PTR) && (secondaryInputLength == CRYPTO_30_HWA_SIGNATURE_SIZE_BYTES))
    {
      /* #12 If signature was provided in first UPDATE step of streaming, update hash calculation signature */
      retVal = CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_R_SIZE_BYTES, secondaryInputPtr));
      workspace->signatureProcessed = TRUE;
    }
    else
    {
      retVal = E_NOT_OK;
    }

    /* #13 Update hash calculation with public key */
    retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_ED25519_PUBLIC_KEY_SIZE_BYTES, workspace->ed25519key));
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
}

/*********************************************************************************************************************
 *  Crypto_30_Hwa_Ed25519VerifyStart()
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
Std_ReturnType retVal_verifyStart;

CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Ed25519VerifyStart(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) signatureDataPtr,
  uint32 signatureDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) contextDataPtr,
  uint32 contextDataLength)
{
  vHsm_Api_KeyStorageIndexType index = 0u;
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key;

  /* #10 Initialize workspace */
  workspace->signatureSet = FALSE;
  workspace->signatureProcessed = FALSE;
  workspace->contextSet = FALSE;
  workspace->contextProcessed = FALSE;

  /* #11 Get key index */
  retVal_verifyStart = vHsm_Api_KeyElementGetForCryptoJobs(cryptoKeyId, CRYPTO_KE_SIGNATURE_KEY,
    &index, CRYPTO_30_HWA_EDDSA_ED25519_PUBLIC_KEY_SIZE_BYTES, VHSM_API_SHE_SERVICE_OTHER);

  if (retVal_verifyStart != E_OK)
  {
    *errorIdPtr = CRYPTO_E_NO_ERROR;
  }
  else
  {
    /* #12 Get key */
    key = vHsm_Api_GetAddrKeyStorage(index);

    /* #13 Check if signature is provided in START step for streaming usecase */
    if ((signatureDataPtr != NULL_PTR) && (signatureDataLength == CRYPTO_30_HWA_SIGNATURE_SIZE_BYTES))
    {
      VStdMemCpy(workspace->signature, signatureDataPtr, signatureDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      workspace->signatureSet = TRUE;
    }

    /* #14 Check which mode is used */
    switch (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
    {
      case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PURE:
        /* #20 Initialize SHA-512 calculation for Ed25519 mode PURE */
        retVal_verifyStart = CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_initHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_VSECPRIM_SHA_2_512, CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL));
        *errorIdPtr = CRYPTO_E_NO_ERROR;
        break;

      case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_CTX:
        /* #30 Initialize SHA-512 calculation for Ed25519 mode CTX */
        retVal_verifyStart = CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_initHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_VSECPRIM_SHA_2_512, CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL));

        /* #31 Check if context is provided in START step */
        retVal_verifyStart |= Crypto_30_Hwa_CheckContext(workspace, contextDataPtr, contextDataLength);
        *errorIdPtr = CRYPTO_E_NO_ERROR;
        break;

      case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PH:

        retVal_verifyStart = Crypto_30_Hwa_CheckContext(workspace, contextDataPtr, contextDataLength);

        /* #40 Initialize calculation of prehash */
        retVal_verifyStart |= Crypto_30_Hwa_StartPreHash(objectId, job, workspace, CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL);
        *errorIdPtr = CRYPTO_E_NO_ERROR;
        break;

      default: /* COV_CRYPTO_30_HWA_CASE_DEFAULT */
        retVal_verifyStart = E_NOT_OK; /* Unsupported mode. */
        break;
    }

    /* #50 Copy key to workspace for later use */
    VStdMemCpy(workspace->ed25519key, key, CRYPTO_30_HWA_EDDSA_ED25519_PUBLIC_KEY_SIZE_BYTES); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

    /* #51 Call hardware specific start function */
    retVal_verifyStart |= Crypto_30_Hwa_Hw_Ed25519VerifyStart(job, workspace);
  }

  return retVal_verifyStart;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/*********************************************************************************************************************
 *  Crypto_30_Hwa_Ed25519VerifyUpdate()
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
 */
  Std_ReturnType retVal_verifyUpdate;

CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Ed25519VerifyUpdate(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) signatureDataPtr,
  uint32 signatureDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) contextDataPtr,
  uint32 contextDataLength)
{

  /* #10 Check which mode is used */
  switch (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
  {
    case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PURE:

      /* #20 Check if signature is provided in first UPDATE step */
      retVal_verifyUpdate = Crypto_30_Hwa_ProcessSigRPartAndKeyUpdate(workspace, signatureDataPtr, signatureDataLength);

      retVal_verifyUpdate |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, inputDataLength, inputDataPtr));

      /* #21 Update input for SHA-512 calculation for Ed25519 mode PURE */
      retVal_verifyUpdate |= Crypto_30_Hwa_Hw_Ed25519VerifyUpdate(job, workspace, inputDataPtr, inputDataLength);
      *errorIdPtr = CRYPTO_E_NO_ERROR;
      break;

    case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_CTX:

      /* #30 Check if context has already been processed */
      if (workspace->contextProcessed == FALSE)
      {
        if (workspace->contextSet == TRUE)
        {
          /* #31 Check if context was provided in START step */
          retVal_verifyUpdate = Crypto_30_Hwa_ProcessDom2Data(job, workspace, workspace->context, workspace->contextLength);
          workspace->contextProcessed = TRUE;
        }
        else if ((contextDataPtr != NULL_PTR) && (contextDataLength > 0u) && (contextDataLength <= CRYPTO_30_HWA_EDDSA_CONTEXT_MAX_SIZE_BYTE))
        {
          /* #32 Check if context is provided in first UPDATE step */
          retVal_verifyUpdate = Crypto_30_Hwa_ProcessDom2Data(job, workspace, contextDataPtr, contextDataLength);
          workspace->contextProcessed = TRUE;
        }
        else
        {
          retVal_verifyUpdate = E_NOT_OK;
        }
      }
      else
      {
        retVal_verifyUpdate = E_OK;
      }

      /* #33 Check if signature is provided in first UPDATE step */
      retVal_verifyUpdate |= Crypto_30_Hwa_ProcessSigRPartAndKeyUpdate(workspace, signatureDataPtr, signatureDataLength);

      retVal_verifyUpdate |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, inputDataLength, inputDataPtr));

      /* #34 Update input for SHA-512 calculation for Ed25519 mode CTX */
      retVal_verifyUpdate |= Crypto_30_Hwa_Hw_Ed25519VerifyUpdate(job, workspace, inputDataPtr, inputDataLength);
      *errorIdPtr = CRYPTO_E_NO_ERROR;
      break;

    case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PH:

      /* #40 Check if context has already been processed */
      if (workspace->contextProcessed == FALSE)
      {
        if (workspace->contextSet == FALSE)
        {
          retVal_verifyUpdate = Crypto_30_Hwa_CheckContext(workspace, contextDataPtr, contextDataLength);

          workspace->contextProcessed = TRUE;
        }
        else
        {
          /* #41 Context has been provided in START step */
          retVal_verifyUpdate = E_OK;
          workspace->contextProcessed = TRUE;
        }
      }
      else
      {
        retVal_verifyUpdate = E_OK;
      }

      /* #42 Update calculation of prehash */
      retVal_verifyUpdate |= Crypto_30_Hwa_UpdatePreHash(objectId, job, workspace, inputDataPtr, inputDataLength);

      /* #43 Call hardware specific UPDATE function */
      retVal_verifyUpdate |= Crypto_30_Hwa_Hw_Ed25519VerifyUpdate(job, workspace, inputDataPtr, inputDataLength);
      *errorIdPtr = CRYPTO_E_NO_ERROR;
      break;

    default: /* COV_CRYPTO_30_HWA_CASE_DEFAULT */
      retVal_verifyUpdate = E_NOT_OK; /* Unsupported mode. */
      break;
  }

  return retVal_verifyUpdate;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/*********************************************************************************************************************
 *  Crypto_30_Hwa_CheckEd25519VerifyInputParameters()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckEd25519VerifyInputParameters(
  uint32 secondaryInputLength)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (secondaryInputLength == CRYPTO_30_HWA_SIGNATURE_SIZE_BYTES)
  {
    retVal = E_OK;
  }

  return retVal;
}

/*********************************************************************************************************************
 *  Crypto_30_Hwa_Ed25519VerifyFinish()
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
 */

  Std_ReturnType retVal_verifyFinish;
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Ed25519VerifyFinish(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) secondaryInputPtr,
  uint32 secondaryInputLength,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) verifyPtr)
{

  uint8 messageDigest[64u] = { 0u };
  uint32 messageDigestLength = sizeof(messageDigest);

  /* #10 Check if input parameters for FINISH step are valid */
  retVal_verifyFinish = Crypto_30_Hwa_CheckEd25519VerifyInputParameters(secondaryInputLength);

  if (retVal_verifyFinish != E_OK)
  {
    /* Do nothing. Return value already set. */
  }
  else
  {
    /* #20 Check which mode is used */
    switch (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
    {
      case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PURE:
      case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_CTX:

        /* #30 Check if input is provided in FINISH step and update calculation */
        if ((job->jobPrimitiveInputOutput.mode != CRYPTO_OPERATIONMODE_SINGLECALL) && (inputPtr != NULL_PTR))
        {
          if (inputLength > 0u)
          {
            retVal_verifyFinish = CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, inputLength, inputPtr));
          }
          else
          {
            retVal_verifyFinish = E_NOT_OK;
          }
        }

        /* #31 Finalize SHA-512 hash for Ed25519 mode PURE and CTX */
        retVal_verifyFinish |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_finalizeHash(&workspace->vSecPrim_HashWorkSpace, &messageDigestLength, messageDigest));

        /* #32 Call hardware specific FINISH function */
        retVal_verifyFinish |= Crypto_30_Hwa_Hw_Ed25519VerifyFinish(job, workspace, workspace->ed25519key, messageDigest, messageDigestLength, secondaryInputPtr, secondaryInputLength, verifyPtr);
        *errorIdPtr = CRYPTO_E_NO_ERROR;
        break;

      case CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PH:

        /* #40 Finalize prehash calculation */
        retVal_verifyFinish = Crypto_30_Hwa_FinalizePreHash(objectId, job, workspace, inputPtr, inputLength, messageDigest, &messageDigestLength);

        /* #41 Initialize SHA-512 hash for Ed25519 mode PH */
        retVal_verifyFinish |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_initHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_VSECPRIM_SHA_2_512, CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL));

        /* #42 Update SHA-512 hash for Ed25519 mode PH with Dom2 data and context */
        if (workspace->contextSet == TRUE)
        {
          retVal_verifyFinish |= Crypto_30_Hwa_ProcessDom2Data(job, workspace, workspace->context, workspace->contextLength);
        }
        else
        {
          retVal_verifyFinish |= Crypto_30_Hwa_ProcessDom2Data(job, workspace, NULL_PTR, 0u);
        }

        /* #43 Update SHA-512 hash for Ed25519 mode PH with R-part of signature */
        retVal_verifyFinish |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_R_SIZE_BYTES, secondaryInputPtr));

        /* #44 Update SHA-512 hash for Ed25519 mode PH with public key */
        retVal_verifyFinish |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_ED25519_PUBLIC_KEY_SIZE_BYTES, workspace->ed25519key));

        /* #45 Update SHA-512 hash for Ed25519 mode PH with prehash */
        retVal_verifyFinish |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, messageDigestLength, messageDigest));

        /* #46 Finalize SHA-512 hash for Ed25519 mode PH */
        retVal_verifyFinish |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_finalizeHash(&workspace->vSecPrim_HashWorkSpace, &messageDigestLength, messageDigest));

        if (retVal_verifyFinish == E_OK)
        {
          /* #47 Call hardware specific FINISH function */
          retVal_verifyFinish = Crypto_30_Hwa_Hw_Ed25519VerifyFinish(job, workspace, workspace->ed25519key, messageDigest, messageDigestLength, secondaryInputPtr, secondaryInputLength, verifyPtr);
        }

        *errorIdPtr = CRYPTO_E_NO_ERROR;
        break;

      default: /* COV_CRYPTO_30_HWA_CASE_DEFAULT */
        retVal_verifyFinish = E_NOT_OK; /* Unsupported mode. */
        break;
    }
  }

  return retVal_verifyFinish;
} /* PRQA S 6050, 6060 */ /* MD_MSR_STCAL, MD_MSR_STPAR */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/*********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessEcdsaSignatureGenerateJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessEcdsaSignatureGenerateJob(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Verify if algorithm mode is correct */
  if(job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOFAM_NOT_SET)
  {
    /* [SWS_Crypto_00017] [SWS_Crypto_00020] START while IDLE or ACTIVE */
    if (((job->state == CRYPTO_JOBSTATE_IDLE) || (job->state == CRYPTO_JOBSTATE_ACTIVE))
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_START))
    {
      /* #20 Initialize prehashing if required */
      retVal = Crypto_30_Hwa_StartPreHash(objectId, job, workspace, CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_TRUNCATION_ALLOWED);
      Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    }

    /* UPDATE while ACTIVE */
    if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) /* [SWS_Crypto_00024] */
    {
      /* #30 Update prehashing if required */
      retVal = Crypto_30_Hwa_UpdatePreHash(objectId, job, workspace,
                                           job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength);
      Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    }

    /* [SWS_Crypto_00023] FINISH while ACTIVE */
    if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)) /* [SWS_Crypto_00024] */
    {
      /* #40 Finalize prehashing if required and generate signature in finish step */
      retVal = Crypto_30_Hwa_EcdsaGenerateFinish(objectId, job, workspace,
                                                 job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength,
                                                 job->jobPrimitiveInputOutput.outputPtr, job->jobPrimitiveInputOutput.outputLengthPtr);

      job->state = CRYPTO_JOBSTATE_IDLE; /* SBSW_CRYPTO_30_HWA_DIRECT_ACCESS_TO_JOB_STATE */
    }

    *errorIdPtr = CRYPTO_E_NO_ERROR;
  }

  return retVal;
} /* Crypto_30_Hwa_ProcessSignatureGenerateJob() */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/*********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessEddsaSignatureGenerateJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessEddsaSignatureGenerateJob(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* [SWS_Crypto_00017] [SWS_Crypto_00020] START while IDLE or ACTIVE */
  if (((job->state == CRYPTO_JOBSTATE_IDLE) || (job->state == CRYPTO_JOBSTATE_ACTIVE))
    && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_START))
  {
    /* #10 Call start operation */
    retVal = Crypto_30_Hwa_Ed25519GenerateStart(objectId, errorIdPtr, job, workspace);

    Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
  }

  /* UPDATE while ACTIVE */
  if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
    && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) /* [SWS_Crypto_00024] */
  {
    /* #20 Call update operation */
    retVal = Crypto_30_Hwa_Ed25519GenerateUpdate(objectId, errorIdPtr, job, workspace, job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength);

    Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
  }

  /* [SWS_Crypto_00023] FINISH while ACTIVE */
  if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
    && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)) /* [SWS_Crypto_00024] */
  {
    /* #30 Call finish operation */
    retVal = Crypto_30_Hwa_Ed25519GenerateFinish(objectId, errorIdPtr, job, workspace, job->cryptoKeyId,
      job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength,
      job->jobPrimitiveInputOutput.tertiaryInputPtr, job->jobPrimitiveInputOutput.tertiaryInputLength,
      job->jobPrimitiveInputOutput.outputPtr, job->jobPrimitiveInputOutput.outputLengthPtr);

    job->state = CRYPTO_JOBSTATE_IDLE; /* SBSW_CRYPTO_30_HWA_DIRECT_ACCESS_TO_JOB_STATE */
  }

  return retVal;
} /* Crypto_30_Hwa_ProcessSignatureGenerateJob() */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/*********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessEcdsaSignatureVerifyJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessEcdsaSignatureVerifyJob(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Verify if algorithm mode is correct */
  if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOFAM_NOT_SET)
  {
    /* [SWS_Crypto_00017] [SWS_Crypto_00020] START while IDLE or ACTIVE */
    if (((job->state == CRYPTO_JOBSTATE_IDLE) || (job->state == CRYPTO_JOBSTATE_ACTIVE))
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_START))
    {
      /* #20 Initialize prehashing if required */
      retVal = Crypto_30_Hwa_StartPreHash(objectId, job, workspace, CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_TRUNCATION_ALLOWED);

      Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    }

    /* UPDATE while ACTIVE */
    if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) /* [SWS_Crypto_00024] */
    {
      /* #30 Update prehashing if required */
      retVal = Crypto_30_Hwa_UpdatePreHash(objectId, job, workspace,
                                           job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength);

      Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    }

    /* [SWS_Crypto_00023] FINISH while ACTIVE */
    if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)) /* [SWS_Crypto_00024] */
    {
      /* #40 Finalize prehashing if required and verify signature in finish step */
      retVal = Crypto_30_Hwa_EcdsaVerifyFinish(objectId, job, workspace, job->cryptoKeyId,
                                               job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength,
                                               job->jobPrimitiveInputOutput.secondaryInputPtr, job->jobPrimitiveInputOutput.secondaryInputLength,
                                               job->jobPrimitiveInputOutput.verifyPtr);

      job->state = CRYPTO_JOBSTATE_IDLE; /* SBSW_CRYPTO_30_HWA_DIRECT_ACCESS_TO_JOB_STATE */
    }

    *errorIdPtr = CRYPTO_E_NO_ERROR;
  }

  return retVal;
} /* Crypto_30_Hwa_ProcessSignatureVerifyJob() */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON)  && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/*********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessEddsaSignatureVerifyJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessEddsaSignatureVerifyJob(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* [SWS_Crypto_00017] [SWS_Crypto_00020] START while IDLE or ACTIVE */
  if (((job->state == CRYPTO_JOBSTATE_IDLE) || (job->state == CRYPTO_JOBSTATE_ACTIVE))
    && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_START))
  {
    /* #10 Call start operation */
    retVal = Crypto_30_Hwa_Ed25519VerifyStart(objectId, errorIdPtr, job, workspace, job->cryptoKeyId,
                                              job->jobPrimitiveInputOutput.secondaryInputPtr, job->jobPrimitiveInputOutput.secondaryInputLength,
                                              job->jobPrimitiveInputOutput.tertiaryInputPtr, job->jobPrimitiveInputOutput.tertiaryInputLength);

    Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
  }

  /* UPDATE while ACTIVE */
  if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
    && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) /* [SWS_Crypto_00024] */
  {

    /* #20 Call update operation */
    retVal =  Crypto_30_Hwa_Ed25519VerifyUpdate(objectId, errorIdPtr, job, workspace, job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength,
                                                                            job->jobPrimitiveInputOutput.secondaryInputPtr, job->jobPrimitiveInputOutput.secondaryInputLength,
                                                                            job->jobPrimitiveInputOutput.tertiaryInputPtr, job->jobPrimitiveInputOutput.tertiaryInputLength);

    Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
  }

  /* [SWS_Crypto_00023] FINISH while ACTIVE */
  if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
    && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)) /* [SWS_Crypto_00024] */
  {
    /* #30 Call finish operation */
    retVal = Crypto_30_Hwa_Ed25519VerifyFinish(objectId, errorIdPtr, job, workspace,
      job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength,
      job->jobPrimitiveInputOutput.secondaryInputPtr, job->jobPrimitiveInputOutput.secondaryInputLength,
      job->jobPrimitiveInputOutput.verifyPtr);

    job->state = CRYPTO_JOBSTATE_IDLE; /* SBSW_CRYPTO_30_HWA_DIRECT_ACCESS_TO_JOB_STATE */
  }

  return retVal;
} /* Crypto_30_Hwa_ProcessSignatureVerifyJob() */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON)  && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Signature.c
 *********************************************************************************************************************/

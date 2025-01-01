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
/*      \file  Crypto_30_LibCv_Hash.c
 *      \brief  MICROSAR Crypto Driver (Crypto)
 *
 *      \details  Implementation for HASH Services
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_LIBCV_HASH_SOURCE
/* PRQA S 0777, 0779 EOF */ /* MD_MSR_IdentifierLength, MD_MSR_IdentifierLength */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_LibCv.h"
#include "Crypto_30_LibCv_Services.h"
#include "Crypto_30_LibCv_Hash.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CRYPTO_30_LIBCV_HASH_SHA3_224_BITLENGTH                       (224u)
#define CRYPTO_30_LIBCV_HASH_SHA3_256_BITLENGTH                       (256u)
#define CRYPTO_30_LIBCV_HASH_SHA3_384_BITLENGTH                       (384u)
#define CRYPTO_30_LIBCV_HASH_SHA3_512_BITLENGTH                       (512u)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CRYPTO_30_LIBCV_START_SEC_CODE
#include "Crypto_30_LibCv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_LIBCV_SHA1 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashSha1ModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace     Pointer to the esl workspace.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha1ModeStart(
  P2VAR(eslt_WorkSpaceSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashSha1ModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha1ModeUpdate(
  P2VAR(eslt_WorkSpaceSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashSha1ModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the hash value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha1ModeFinish(
  P2VAR(eslt_WorkSpaceSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_SHA1 == STD_ON) */

#if (CRYPTO_30_LIBCV_SHA256 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashSha256ModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha256ModeStart(
  P2VAR(eslt_WorkSpaceSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashSha256ModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha256ModeUpdate(
  P2VAR(eslt_WorkSpaceSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashSha256ModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the hash value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha256ModeFinish(
  P2VAR(eslt_WorkSpaceSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job); /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
#endif /* (CRYPTO_30_LIBCV_SHA256 == STD_ON) */

#if (CRYPTO_30_LIBCV_SHA384 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashSha384ModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha384ModeStart(
  P2VAR(eslt_WorkSpaceSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashSha384ModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha384ModeUpdate(
  P2VAR(eslt_WorkSpaceSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashSha384ModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the hash value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha384ModeFinish(
  P2VAR(eslt_WorkSpaceSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job); /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
#endif /* (CRYPTO_30_LIBCV_SHA384 == STD_ON) */

#if (CRYPTO_30_LIBCV_SHA512 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashSha512ModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha512ModeStart(
  P2VAR(eslt_WorkSpaceSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashSha512ModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha512ModeUpdate(
  P2VAR(eslt_WorkSpaceSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashSha512ModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the hash value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha512ModeFinish(
  P2VAR(eslt_WorkSpaceSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job); /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
#endif /* (CRYPTO_30_LIBCV_SHA512 == STD_ON) */

#if (CRYPTO_30_LIBCV_SHA3_256 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchSha3ModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in]      bitLength          Bit length of hash mode.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *                  bitLength has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchSha3ModeStart(
  P2VAR(eslt_WorkSpaceSHA3, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  eslt_Length bitLength);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchSha3ModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchSha3ModeUpdate(
  P2VAR(eslt_WorkSpaceSHA3, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchSha3ModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the hash value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace     Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchSha3ModeFinish(
  P2VAR(eslt_WorkSpaceSHA3, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_SHA3_256 == STD_ON) */

#if (CRYPTO_30_LIBCV_RIPEMD160 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchRipeMd160ModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace     Pointer to the esl workspace.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchRipeMd160ModeStart(
  P2VAR(eslt_WorkSpaceRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchRipeMd160ModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace     Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchRipeMd160ModeUpdate(
  P2VAR(eslt_WorkSpaceRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchRipeMd160ModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the hash value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace     Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchRipeMd160ModeFinish(
  P2VAR(eslt_WorkSpaceRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_RIPEMD160 == STD_ON) */

#if (CRYPTO_30_LIBCV_MD5 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashMD5ModeStart()
 *********************************************************************************************************************/
/*!\brief           Handles hash md5 operation mode START.
 *  \details        This function initializes both the workspace header and algorithm.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \return         E_OK               Start operation was successful.
 *                  E_NOT_OK           Start operation failed.
 *  \pre            workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashMD5ModeStart(
  P2VAR(eslt_WorkSpaceMD5, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashMD5ModeUpdate()
 *********************************************************************************************************************/
/*!\brief           Handles hash md5 operation mode UPDATE.
 *  \details        This function processes the input data.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Update operation was successful.
 *                  E_NOT_OK           Update operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashMD5ModeUpdate(
  P2VAR(eslt_WorkSpaceMD5, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);

/**********************************************************************************************************************
 *  Crypto_30_LibCv_DispatchHashMD5ModeFinish()
 *********************************************************************************************************************/
/*!\brief           Handles hash md5 operation mode FINISH.
 *  \details        This function writes the results in output buffers, adapts the output size of the hash value and
 *                  copies the data to the output location.
 *  \param[in]      workSpace          Pointer to the esl workspace.
 *  \param[in,out]  job                Pointer to the job which shall be dispatched.
 *  \return         E_OK               Finish operation was successful.
 *                  E_NOT_OK           Finish operation failed.
 *  \pre            job has to be a job object handle.
 *                  workSpace has to be valid.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashMD5ModeFinish(
  P2VAR(eslt_WorkSpaceMD5, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job);
#endif /* (CRYPTO_30_LIBCV_MD5 == STD_ON) */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#if (CRYPTO_30_LIBCV_SHA1 == STD_ON)
/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashSha1ModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha1ModeStart(
  P2VAR(eslt_WorkSpaceSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Initialize workspace header. */
  retValCv = esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_SHA1, CRYPTO_30_LIBCV_WATCHDOG_PTR); /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Initialize algorithm. */
    retValCv = esl_initSHA1(workSpace); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE */
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashSha1ModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha1ModeUpdate(
  P2VAR(eslt_WorkSpaceSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Process input data. */
  retValCv = esl_updateSHA1(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
    (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
    (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashSha1ModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha1ModeFinish(
  P2VAR(eslt_WorkSpaceSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv;
  uint8 tempHashBuf[ESL_SIZEOF_SHA1_DIGEST];
  Std_ReturnType retVal = E_NOT_OK;

  /* # Write results in output buffers. */
  retValCv = esl_finalizeSHA1(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))tempHashBuf); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Adapt output size of hash value. */
    if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > ESL_SIZEOF_SHA1_DIGEST)
    {
      *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = ESL_SIZEOF_SHA1_DIGEST; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
    }
    /* Copy data to output location */
    Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, tempHashBuf, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

    retVal = E_OK;
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_SHA1 == STD_ON) */

#if (CRYPTO_30_LIBCV_SHA256 == STD_ON)
/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashSha256ModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha256ModeStart(
  P2VAR(eslt_WorkSpaceSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Initialize workspace header. */
  retValCv = esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_SHA256, CRYPTO_30_LIBCV_WATCHDOG_PTR); /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Initialize algorithm. */
    retValCv = esl_initSHA256(workSpace); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE */
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashSha256ModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha256ModeUpdate(
  P2VAR(eslt_WorkSpaceSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Process input data. */
  retValCv = esl_updateSHA256(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
    (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
    (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashSha256ModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha256ModeFinish(
  P2VAR(eslt_WorkSpaceSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv;
  uint8 tempHashBuf[ESL_SIZEOF_SHA256_DIGEST];
  Std_ReturnType retVal = E_NOT_OK;

  /* # Write results in output buffers. */
  retValCv = esl_finalizeSHA256(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))tempHashBuf); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Adapt output size of hash value. */
    if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > ESL_SIZEOF_SHA256_DIGEST)
    {
      *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = ESL_SIZEOF_SHA256_DIGEST; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
    }
    /* Copy data to output location */
    Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, tempHashBuf, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

    retVal = E_OK;
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_SHA256 == STD_ON) */

#if (CRYPTO_30_LIBCV_SHA384 == STD_ON)
/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashSha384ModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha384ModeStart(
  P2VAR(eslt_WorkSpaceSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Initialize workspace header. */
  retValCv = esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_SHA384, CRYPTO_30_LIBCV_WATCHDOG_PTR); /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Initialize algorithm. */
    retValCv = esl_initSHA384(workSpace); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE */
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashSha384ModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha384ModeUpdate(
  P2VAR(eslt_WorkSpaceSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Process input data. */
  retValCv = esl_updateSHA384(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
    (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
    (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashSha384ModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha384ModeFinish(
  P2VAR(eslt_WorkSpaceSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv;
  uint8 tempHashBuf[ESL_SIZEOF_SHA384_DIGEST];
  Std_ReturnType retVal = E_NOT_OK;

  /* # Write results in output buffers. */
  retValCv = esl_finalizeSHA384(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))tempHashBuf); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Adapt output size of hash value. */
    if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > ESL_SIZEOF_SHA384_DIGEST)
    {
      *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = ESL_SIZEOF_SHA384_DIGEST; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
    }
    /* Copy data to output location */
    Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, tempHashBuf, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

    retVal = E_OK;
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_SHA384 == STD_ON) */

#if (CRYPTO_30_LIBCV_SHA512 == STD_ON)
/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashSha512ModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha512ModeStart(
  P2VAR(eslt_WorkSpaceSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Initialize workspace header. */
  retValCv = esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_SHA512, CRYPTO_30_LIBCV_WATCHDOG_PTR); /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Initialize algorithm. */
    retValCv = esl_initSHA512(workSpace); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE */
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashSha512ModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha512ModeUpdate(
  P2VAR(eslt_WorkSpaceSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Process input data. */
  retValCv = esl_updateSHA512(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
    (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
    (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashSha512ModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashSha512ModeFinish(
  P2VAR(eslt_WorkSpaceSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv;
  uint8 tempHashBuf[ESL_SIZEOF_SHA512_DIGEST];
  Std_ReturnType retVal = E_NOT_OK;

  /* # Write results in output buffers. */
  retValCv = esl_finalizeSHA512(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))tempHashBuf); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Adapt output size of hash value. */
    if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > ESL_SIZEOF_SHA512_DIGEST)
    {
      *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = ESL_SIZEOF_SHA512_DIGEST; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
    }
    /* Copy data to output location */
    Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, tempHashBuf, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

    retVal = E_OK;
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_SHA512 == STD_ON) */

#if (CRYPTO_30_LIBCV_SHA3_256 == STD_ON)
/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchSha3ModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchSha3ModeStart(
  P2VAR(eslt_WorkSpaceSHA3, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  eslt_Length bitLength)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Initialize workspace header. */
  retValCv = esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_SHA3, CRYPTO_30_LIBCV_WATCHDOG_PTR); /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Initialize algorithm. */
    retValCv = esl_initSHA3(workSpace, bitLength); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE */
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchSha3ModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchSha3ModeUpdate(
  P2VAR(eslt_WorkSpaceSHA3, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Process input data. */
  retValCv = esl_updateSHA3(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
    (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
    (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchSha3ModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchSha3ModeFinish(
  P2VAR(eslt_WorkSpaceSHA3, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;
  eslt_Length tempHashLength = (eslt_Length)*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr;

  /* # Write results in output buffers. */
  retValCv = esl_finalizeSHA3(workSpace,
    (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr,
    (P2VAR(eslt_Length, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))&tempHashLength); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */

  /* # Adapt output size of hash value. */
  *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = tempHashLength; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_SHA3_256 == STD_ON) */

#if (CRYPTO_30_LIBCV_RIPEMD160 == STD_ON)
/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchRipeMd160ModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchRipeMd160ModeStart(
  P2VAR(eslt_WorkSpaceRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Initialize workspace header. */
  retValCv = esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_RIPEMD160, CRYPTO_30_LIBCV_WATCHDOG_PTR); /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Initialize algorithm. */
    retValCv = esl_initRIPEMD160(workSpace); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE */
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchRipeMd160ModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchRipeMd160ModeUpdate(
  P2VAR(eslt_WorkSpaceRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Process input data. */
  retValCv = esl_updateRIPEMD160(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
                            (eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
                            (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchRipeMd160ModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchRipeMd160ModeFinish(
  P2VAR(eslt_WorkSpaceRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv;
  uint8 tempHashBuf[ESL_SIZEOF_RIPEMD160_DIGEST];
  Std_ReturnType retVal = E_NOT_OK;

  /* # Write results in output buffers. */
  retValCv = esl_finalizeRIPEMD160(workSpace, tempHashBuf); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Adapt output size of hash value. */
    if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > ESL_SIZEOF_RIPEMD160_DIGEST)
    {
      *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = ESL_SIZEOF_RIPEMD160_DIGEST; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
    }
    /* Copy data to output location */
    Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, tempHashBuf, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

    retVal = E_OK;
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_RIPEMD160 == STD_ON) */

#if (CRYPTO_30_LIBCV_MD5 == STD_ON)
/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashMD5ModeStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashMD5ModeStart(
  P2VAR(eslt_WorkSpaceMD5, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Initialize workspace header. */
  retValCv = esl_initWorkSpaceHeader(&(workSpace->header), ESL_MAXSIZEOF_WS_MD5, CRYPTO_30_LIBCV_WATCHDOG_PTR); /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Initialize algorithm. */
    retValCv = esl_initMD5(workSpace); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE */
  }

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashMD5ModeUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashMD5ModeUpdate(
  P2VAR(eslt_WorkSpaceMD5, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job)
{
  eslt_ErrorCode retValCv;
  Std_ReturnType retVal = E_NOT_OK;

  /* # Process input data. */
  retValCv = esl_updateMD5(workSpace, /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
    (const eslt_Length)job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputLength,
    (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.inputPtr);

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * Crypto_30_LibCv_DispatchHashMD5ModeFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

CRYPTO_30_LIBCV_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_DispatchHashMD5ModeFinish(
  P2VAR(eslt_WorkSpaceMD5, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpace,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job) /* PRQA S 3673 */ /* MD_CRYPTO_30_LIBCV_3673_3 */
{
  eslt_ErrorCode retValCv;
  uint8 tempHashBuf[ESL_SIZEOF_MD5_DIGEST];
  Std_ReturnType retVal = E_NOT_OK;

  /* # Write results in output buffers. */
  retValCv = esl_finalizeMD5(workSpace, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))tempHashBuf); /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_STACK_BUFFER_NOLENGTHGIVEN */

  if (retValCv == ESL_ERC_NO_ERROR)
  {
    /* # Adapt output size of hash value. */
    if (*job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr > ESL_SIZEOF_MD5_DIGEST)
    {
      *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr = ESL_SIZEOF_MD5_DIGEST; /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
    }
    /* Copy data to output location */
    Crypto_30_LibCv_CopyData(job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputPtr, tempHashBuf, *job->CRYPTO_30_LIBCV_JOB_PRIMITIVE_INPUT_OUTPUT_MEMBER.outputLengthPtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */

    retVal = E_OK;
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_MD5 == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#if (CRYPTO_30_LIBCV_SHA1 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_SHA1()
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
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_SHA1(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceSHA1, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpaceSha1 = Crypto_30_LibCv_GetWorkspaceOfSHA1(Crypto_30_LibCv_GetSHA1IdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceSHA1)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHashSha1ModeStart(workSpaceSha1); /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */
      break;
    }
    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retVal = Crypto_30_LibCv_DispatchHashSha1ModeUpdate(workSpaceSha1, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retVal = Crypto_30_LibCv_DispatchHashSha1ModeFinish(workSpaceSha1, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    default: /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      break;
    }
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_SHA1 == STD_ON) */

#if (CRYPTO_30_LIBCV_SHA256 == STD_ON)
/**********************************************************************************************************************
 * Crypto_30_LibCv_Dispatch_SHA256()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_SHA256(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceSHA256, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpaceSha256 = Crypto_30_LibCv_GetWorkspaceOfSHA256(Crypto_30_LibCv_GetSHA256IdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceSHA256)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHashSha256ModeStart(workSpaceSha256); /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */
      break;
    }
    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retVal = Crypto_30_LibCv_DispatchHashSha256ModeUpdate(workSpaceSha256, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retVal = Crypto_30_LibCv_DispatchHashSha256ModeFinish(workSpaceSha256, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    default: /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      break;
    }
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_SHA256 == STD_ON) */

#if (CRYPTO_30_LIBCV_SHA384 == STD_ON)
/**********************************************************************************************************************
 * Crypto_30_LibCv_Dispatch_SHA384()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_SHA384(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceSHA384, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpaceSha384 = Crypto_30_LibCv_GetWorkspaceOfSHA384(Crypto_30_LibCv_GetSHA384IdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceSHA384)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHashSha384ModeStart(workSpaceSha384);  /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */
      break;
    }
    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retVal = Crypto_30_LibCv_DispatchHashSha384ModeUpdate(workSpaceSha384, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retVal = Crypto_30_LibCv_DispatchHashSha384ModeFinish(workSpaceSha384, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    default:   /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      break;
    }
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_SHA384 == STD_ON) */

#if (CRYPTO_30_LIBCV_SHA512 == STD_ON)
/**********************************************************************************************************************
 * Crypto_30_LibCv_Dispatch_SHA512()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_SHA512(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceSHA512, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpaceSha512 = Crypto_30_LibCv_GetWorkspaceOfSHA512(Crypto_30_LibCv_GetSHA512IdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceSHA512)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHashSha512ModeStart(workSpaceSha512);  /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */
      break;
    }
    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retVal = Crypto_30_LibCv_DispatchHashSha512ModeUpdate(workSpaceSha512, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retVal = Crypto_30_LibCv_DispatchHashSha512ModeFinish(workSpaceSha512, job);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    default:   /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      break;
    }
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_SHA512 == STD_ON) */

#if (CRYPTO_30_LIBCV_SHA3_256 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_SHA3_256()
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
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_SHA3_256(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceSHA3, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpaceSha3 = Crypto_30_LibCv_GetWorkspaceOfSHA3_256(Crypto_30_LibCv_GetSHA3_256IdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceSHA3)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchSha3ModeStart(workSpaceSha3, CRYPTO_30_LIBCV_HASH_SHA3_256_BITLENGTH); /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */
      break;
    }
    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retVal = Crypto_30_LibCv_DispatchSha3ModeUpdate(workSpaceSha3, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retVal = Crypto_30_LibCv_DispatchSha3ModeFinish(workSpaceSha3, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    default: /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      break;
    }
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_SHA3_256 == STD_ON) */

#if (CRYPTO_30_LIBCV_RIPEMD160 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_RipeMd160()
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
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_RipeMd160(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceRIPEMD160, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpaceRipeMd160 = Crypto_30_LibCv_GetWorkspaceOfRipeMd160(Crypto_30_LibCv_GetRipeMd160IdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceRIPEMD160)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchRipeMd160ModeStart(workSpaceRipeMd160); /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */
      break;
    }
    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retVal = Crypto_30_LibCv_DispatchRipeMd160ModeUpdate(workSpaceRipeMd160, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retVal = Crypto_30_LibCv_DispatchRipeMd160ModeFinish(workSpaceRipeMd160, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    default: /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      break;
    }
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_RIPEMD160 == STD_ON) */

#if (CRYPTO_30_LIBCV_MD5 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_LibCv_Dispatch_MD5()
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
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_Dispatch_MD5(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------- */
  P2VAR(eslt_WorkSpaceMD5, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR) workSpaceMd5 = Crypto_30_LibCv_GetWorkspaceOfMD5(Crypto_30_LibCv_GetMD5IdxOfObjectInfo(objectId));
  Crypto_30_LibCv_SetLengthOfSaveAndRestoreWorkspace(objectId, sizeof(eslt_WorkSpaceMD5)); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_SIZEOFWORKSPACELENGTH */

  /* # Distinguish modes. */
  switch (mode)
  {
    /* # Handle operationmode START. */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = Crypto_30_LibCv_DispatchHashMD5ModeStart(workSpaceMd5); /* SBSW_CRYPTO_30_LIBCV_CALL_WITH_WORKSPACE */
      break;
    }
    /* # Handle operationmode UPDATE. */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retVal = Crypto_30_LibCv_DispatchHashMD5ModeUpdate(workSpaceMd5, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    /* # Handle operationmode FINISH. */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retVal = Crypto_30_LibCv_DispatchHashMD5ModeFinish(workSpaceMd5, job); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_OF_WORKSPACE_AND_JOB_PTR */
      break;
    }
    default: /* COV_CRYPTO_30_LIBCV_MISRA_ADDITIONAL_STATEMENT */
    {
      break;
    }
  }

  return retVal;
}
#endif /* (CRYPTO_30_LIBCV_MD5 == STD_ON) */

#define CRYPTO_30_LIBCV_STOP_SEC_CODE
#include "Crypto_30_LibCv_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_LibCv_Hash.c
 *********************************************************************************************************************/

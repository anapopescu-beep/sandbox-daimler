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
/*!        \file  actHashMACWrappers_int.h
 *        \brief  Provides wrapper function for init, update and finalize routines of HMAC-SHA.
 *
 *      \details  This file provides wrapper functions for init, update and finalize routines for HMAC with different
 *                underlying SHA versions which unify those functions so tables of function pointers for init, update
 *                and finalize functions can be set up. Also, default wrappers which return an error code are provided.
 *                This file is part of the embedded systems library cvActLib/ES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to module's header file.
 *********************************************************************************************************************/

#ifndef ACTHASHMACWRAPPERS_INT_H
# define ACTHASHMACWRAPPERS_INT_H

# include "vSecPrim_Cfg.h"
# include "actPlatformTypes.h"
# include "actITypes.h"

# include "actIHashMAC.h"
# include "actIHashMACSHA256.h"

# ifndef VSECPRIM_WRAPPER_HMAC_SHA1 /* COV_VSECPRIM_NO_SAFE_CONFIG TX */
/*!
 * Internal comment removed.
 *
 *
 */
#  define actHashMACInitWrapper                                       actHashMACInitNoneWrapper
#  define actHashMACUpdateWrapper                                     actHashMACUpdateNoneWrapper
#  define actHashMACFinalizeWrapper                                   actHashMACFinalizeNoneWrapper
# endif

# ifndef VSECPRIM_WRAPPER_HMAC_SHA256 /* COV_VSECPRIM_NO_SAFE_CONFIG TX */
/*!
 * Internal comment removed.
 *
 *
 */
#  define actHashMACSHA256InitWrapper                                 actHashMACInitNoneWrapper
#  define actHashMACSHA256UpdateWrapper                               actHashMACUpdateNoneWrapper
#  define actHashMACSHA256FinalizeWrapper                             actHashMACFinalizeNoneWrapper
# endif

 /**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 /* Define HashMACInit, HashMACUpdate and HashMACFinalize function pointer types */
typedef P2FUNC(actRETURNCODE, VSECPRIM_CODE, actHashMACType_Init)(VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

typedef P2FUNC(actRETURNCODE, VSECPRIM_CODE, actHashMACType_Update)(VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

typedef P2FUNC(actRETURNCODE, VSECPRIM_CODE, actHashMACType_Finalize)(VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  actHashMACInitNoneWrapper()
 *********************************************************************************************************************/
/*! \brief          This function is used when a HMACInit function for an undefined SHA version is called
 *                  and returns actEXCEPTION_UNKNOWN.
 *  \details        -
 *  \param[in]      info         pointer to HashMACUnion
 *  \param[in]      key          MAC key
 *  \param[in]      key_length   length of key in bytes
 *  \param[in]      watchdog     pointer to watchdog reset function
 *  \return         actEXCEPTION_UNKNOWN always
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACInitNoneWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actHashMACUpdateNoneWrapper()
 *********************************************************************************************************************/
/*! \brief          This function is used when a HMACUpdated function for an undefined SHA version is called
 *                  and returns actEXCEPTION_UNKNOWN.
 *  \details        -
 *  \param[in]      info         pointer to HashMACUnion
 *  \param[in]      dataIN       pointer to data to be hashed
 *  \param[in]      length       length of data in bytes
 *  \param[in]      watchdog     pointer to watchdog reset function
 *  \return         actEXCEPTION_UNKNOWN always
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACUpdateNoneWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actHashMACFinalizeNoneWrapper()
 *********************************************************************************************************************/
/*! \brief          This function is used when a HMACFinalize function for an undefined SHA version is called
 *                  and returns actEXCEPTION_UNKNOWN.
 *  \details        -
 *  \param[in]      info         pointer to HashMACUnion
 *  \param[in]      hash         byte array to contain the hash value
 *  \param[in]      watchdog     pointer to watchdog reset function
 *  \return         actEXCEPTION_UNKNOWN always
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACFinalizeNoneWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef VSECPRIM_WRAPPER_HMAC_SHA1 /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/**********************************************************************************************************************
 *  actHashMACInitWrapper()
 *********************************************************************************************************************/
/*! \brief          This function wraps the function actHashMACInit by using the actHASHMACSTRUCT
 *                  from actHASHMACUNION as input parameter.
 *  \details        -
 *  \param[in,out]  info         (in) pointer to HashMACUnion
 *                               (out) initialized context structure
 *  \param[in]      key          MAC key
 *  \param[in]      key_length   length of key in bytes
 *  \param[in]      watchdog     pointer to watchdog reset function
 *  \return         actEXCEPTION_LENGTH    if key_len < 1
 *                  actOK                  else
 *  \pre            All pointers need to be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACInitWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actHashMACUpdateWrapper()
 *********************************************************************************************************************/
/*! \brief          This function wraps the function actHashMACUpdate by using the actHASHMACSTRUCT
 *                  from actHASHMACUNION as input parameter.
 *  \details        -
 *  \param[in,out]  info         (in) pointer to HashMACUnion
 *                               (out) actualized context structure
 *  \param[in]      dataIN       pointer to data to be hashed
 *  \param[in]      length       length of data in bytes
 *  \param[in]      watchdog     pointer to watchdog reset function
 *  \return         actEXCEPTION_LENGTH   total input more than 2^64 - 1 bit
 *                  actOK                 else
 *  \pre            actHashMACInit() is called once before calling this function
 *                  All pointers need to be valid.
 *                  length >= 0
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACUpdateWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actHashMACFinalizeWrapper()
 *********************************************************************************************************************/
/*! \brief          This function wraps the function actHashMACFinalize by using the actHASHMACSTRUCT
 *                  from actHASHMACUNION as input parameter.
 *  \details        -
 *  \param[in,out]  info         (in) pointer to HashMACUnion
 *                               (out) finalized context structure
 *  \param[in,out]  hash         (in) byte array to contain the hash value
 *                               (out) the final hash value, (big endian of length actHASH_SIZE_SHA)
 *  \param[in]      watchdog     pointer to watchdog reset function
 *  \return         actOK always
 *  \pre            actHashMACInitWrapper() is called once before calling this function
 *                  All pointers need to be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACFinalizeWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# endif /* VSECPRIM_WRAPPER_HMAC_SHA1 */

# ifdef VSECPRIM_WRAPPER_HMAC_SHA256 /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/**********************************************************************************************************************
 *  actHashMACInitSHA256Wrapper()
 *********************************************************************************************************************/
/*! \brief          This function wraps the function actHashMACSHA256Init by using the actHASHMACSHA256STRUCT
 *                  from actHASHMACUNION as input parameter.
 *  \details        -
 *  \param[in,out]  info         (in) pointer to HashMACUnion
 *                               (out) initialized context structure
 *  \param[in]      key           MAC key
 *  \param[in]      key_length   length of key in bytes
 *  \param[in]      watchdog     pointer to watchdog reset function
 *  \return         actEXCEPTION_LENGTH    if key_len < 1
 *                  actOK                  else
 *  \pre            All pointers need to be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACSHA256InitWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actHashMACSHA256UpdateWrapper()
 *********************************************************************************************************************/
/*! \brief          This function wraps the function actHashMACSHA256Update by using the actHASHMACSTRUCT
 *                  from actHASHMACUNION as input parameter.
 *  \details        -
 *  \param[in,out]  info         (in) pointer to HashMACUnion
 *                               (out) actualized context structure
 *  \param[in]      dataIN       pointer to data to be hashed
 *  \param[in]      length       length of data in bytes
 *  \param[in]      watchdog     pointer to watchdog reset function
 *  \return         actEXCEPTION_LENGTH   total input more than 2^64 - 1 bit
 *                  actOK                 else
 *  \pre            actHashMACSHA256InitWrapper() is called once before calling this function
 *                  All pointers need to be valid.
 *                  length >= 0
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACSHA256UpdateWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actHashMACSHA256FinalizeWrapper()
 *********************************************************************************************************************/
/*! \brief          This function wraps the function actHashMACSHA256Finalize by using the actHASHMACSHA256STRUCT
 *                  from actHASHMACUNION as input parameter.
 *  \details        -
 *  \param[in,out]  info         (in) pointer to HashMACUnion
 *                               (out) finalized context structure
 *  \param[in,out]  hash         (in) byte array to contain the hash value
 *                               (out) the final hash value, (big endian of length actHASH_SIZE_SHA256)
 *  \param[in]      watchdog     pointer to watchdog reset function
 *  \return         actOK always
 *  \pre            actHashMACInitWrapper() is called once before calling this function
 *                  All pointers need to be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACSHA256FinalizeWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# endif /* VSECPRIM_WRAPPER_HMAC_SHA256 */

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

# define VSECPRIM_START_SEC_CONST_UNSPECIFIED
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Set up an array of function pointers for HashMACInit, HashMACUpdate and HashMACFinalize functions respectively. */
VSECPRIM_ROM(VSECPRIM_LOCAL, actHashMACType_Init) actHashMACInitTable[2] = { /* PRQA S 1514, 3218 */ /* MD_MSR_Rule8.7 */
  actHashMACInitWrapper, actHashMACSHA256InitWrapper
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actHashMACType_Update) actHashMACUpdateTable[2] = { /* PRQA S 1514, 3218 */ /* MD_MSR_Rule8.7 */
  actHashMACUpdateWrapper, actHashMACSHA256UpdateWrapper
};

VSECPRIM_ROM(VSECPRIM_LOCAL, actHashMACType_Finalize) actHashMACFinalizeTable[2] = { /* PRQA S 1514, 3218 */ /* MD_MSR_Rule8.7 */
  actHashMACFinalizeWrapper, actHashMACSHA256FinalizeWrapper
};

# define VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

# define VSECPRIM_START_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  actHashMACInitNoneWrapper
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACInitNoneWrapper( /* PRQA S 3219 */ /* MD_VSECPRIM_QM_ONLY_UNUSED_FUNCTION */
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, /* PRQA S 3673 */ /* MD_VSECPRIM_QM_ONLY_P2CONST_PARAMETER */
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_DUMMY_STATEMENT(info); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  VSECPRIM_DUMMY_STATEMENT(key); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  VSECPRIM_DUMMY_STATEMENT(key_length); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  VSECPRIM_DUMMY_STATEMENT(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  return actEXCEPTION_UNKNOWN;
}

/**********************************************************************************************************************
 *  actHashMACUpdateNoneWrapper
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACUpdateNoneWrapper( /* PRQA S 3219 */ /* MD_VSECPRIM_QM_ONLY_UNUSED_FUNCTION */
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, /* PRQA S 3673 */ /* MD_VSECPRIM_QM_ONLY_P2CONST_PARAMETER */
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_DUMMY_STATEMENT(info); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  VSECPRIM_DUMMY_STATEMENT(dataIN); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  VSECPRIM_DUMMY_STATEMENT(length); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  VSECPRIM_DUMMY_STATEMENT(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  return actEXCEPTION_UNKNOWN;
}

/**********************************************************************************************************************
 *  actHashMACFinalizeNoneWrapper
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACFinalizeNoneWrapper( /* PRQA S 3219 */ /* MD_VSECPRIM_QM_ONLY_UNUSED_FUNCTION */
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, VSECPRIM_P2VAR_PARA(actU8) hash, /* PRQA S 3673 */ /* MD_VSECPRIM_QM_ONLY_P2CONST_PARAMETER */
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_DUMMY_STATEMENT(info); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  VSECPRIM_DUMMY_STATEMENT(hash); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  VSECPRIM_DUMMY_STATEMENT(watchdog); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  return actEXCEPTION_UNKNOWN;
}

# ifdef VSECPRIM_WRAPPER_HMAC_SHA1 /* COV_VSECPRIM_NO_SAFE_CONFIG XF */
/**********************************************************************************************************************
 *  actHashMACInitWrapper
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACInitWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  return actHashMACInit(&(info->hmac_sha1), key, key_length, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
}

/**********************************************************************************************************************
 *  actHashMACUpdateWrapper
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACUpdateWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  return actHashMACUpdate(&(info->hmac_sha1), dataIN, length, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
}

/**********************************************************************************************************************
 *  actHashMACFinalizeWrapper
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACFinalizeWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  return actHashMACFinalize(&(info->hmac_sha1), hash, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
}

# endif /* VSECPRIM_WRAPPER_HMAC_SHA1 */

# ifdef VSECPRIM_WRAPPER_HMAC_SHA256 /* COV_VSECPRIM_NO_SAFE_CONFIG XF */

/**********************************************************************************************************************
 *  actHashMACSHA256InitWrapper
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACSHA256InitWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  return actHashMACSHA256Init(&(info->hmac_sha256), key, key_length, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
}

/**********************************************************************************************************************
 *  actHashMACSHA256UpdateWrapper
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACSHA256UpdateWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  return actHashMACSHA256Update(&(info->hmac_sha256), dataIN, length, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
}

/**********************************************************************************************************************
 *  actHashMACSHA256FinalizeWrapper
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_LOCAL_FUNC(actRETURNCODE) actHashMACSHA256FinalizeWrapper(
  VSECPRIM_P2VAR_PARA(actHASHMACUNION) info, VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  return actHashMACSHA256Finalize(&(info->hmac_sha256), hash, watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
}

# endif /* VSECPRIM_WRAPPER_HMAC_SHA256 */

# define VSECPRIM_STOP_SEC_CODE
# include "vSecPrim_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* ACTHASHMACWRAPPERS_INT_H */


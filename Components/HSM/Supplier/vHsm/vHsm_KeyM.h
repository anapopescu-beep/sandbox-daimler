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
/*!        \file  vHsm_KeyM.h
 *        \brief  Key manager header file
 *
 *      \details  Defines the public interface of the key manager.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_KEYM_H)
# define VHSM_KEYM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vHsm_Types.h"
# include "vHsm_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define VHSM_KEY_USAGE_SECURE_BOOT_PROTECTED_BITPOS                  (0u)
# define VHSM_KEY_USAGE_INTERNAL_ONLY_BITPOS                          (1u)

# define VHSM_KEY_USAGE_ALLOWED                                       ((uint8)(0u))
# define VHSM_KEY_USAGE_SECURE_BOOT_PROTECTED                         ((uint8)(1u))
# define VHSM_KEY_USAGE_INTERNAL_ONLY                                 ((uint8)(2u))
# define VHSM_KEY_USAGE_API_RESTRICTION                               ((uint8)(4u))

# define vHsm_IsKeyUsageDisallowed(keyId)                             (vHsm_State.vHsm_KeyUsageRestriction[(keyId)] != VHSM_KEY_USAGE_ALLOWED)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define VHSM_START_SEC_CONST_8BIT
# include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

extern CONST(boolean, VHSM_CONST) vHsm_KeyM_SecondaryKeyUsage[VHSM_KEYM_ACTION_SIZE];

# define VHSM_STOP_SEC_CONST_8BIT
# include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VHSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_KeyM_Init()
 *********************************************************************************************************************/
/*! \brief         Init the Key Management processor
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_KeyM_Init(void);

/**********************************************************************************************************************
 *  vHsm_KeyM_ProcessJob()
 *********************************************************************************************************************/
/*! \brief         Process a Key management job
 *  \details       This function is the main entry point to dispatch all key related functions like KeyValidSet, KeyElementGet etc.
 *  \param[in,out] job    The key management job which shall be executed
 *  \return        Result of the executed key management job
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_KeyM_ProcessJob(
  P2VAR(vHsm_KeyM_JobType, AUTOMATIC, VHSM_APPL_VAR) job);

/**********************************************************************************************************************
 *  vHsm_KeyM_PrepareSecureProtectedKeyStates()
 *********************************************************************************************************************/
/*! \brief         Invalidates the keys marked as secure boot protected
 *  \details       The keys can be later restored to the old state because the old sates are buffered
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_KeyM_PrepareSecureProtectedKeyStates(void);

# if (VHSM_SECURE_BOOT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_KeyM_RestoreSecureProtectedKeyStates()
 *********************************************************************************************************************/
/*! \brief         Restore the valid flags for the keys marked as secure boot protected
 *  \details       This function restored the valid flags to the state stored inside the Nvm.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_KeyM_RestoreSecureProtectedKeyStates(void);
# endif

# define VHSM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSM_KEYM_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_KeyM.h
 *********************************************************************************************************************/

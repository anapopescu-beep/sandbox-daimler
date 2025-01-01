/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the HIS security module - Seed/key authentication
 *
 *  \note         Please note, that this file contains an implementation/configuration example for the security
 *                access service used by the respective vehicle manufacturer.
 *                This code may influence the behavior of the diagnostic security access in principle. Therefore,
 *                great care must be taken to verify the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. implementation proposals.
 *                With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                admissible by law or statute.
 *  -------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/*********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  03.00.00   2020-10-14  viscb   FBL-2521         Usage of generated Smh job interface
 *  03.00.01   2022-02-16  vishor  FBL-3957         Add template information in file header
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Security module interfaces */
#include "Sec.h"

/***********************************************************************************************************************
 *   VERSION
 **********************************************************************************************************************/

#if ( SECACCESS_HIS_DAIMLER_VERSION != 0x0300u ) || \
    ( SECACCESS_HIS_DAIMLER_RELEASE_VERSION != 0x01u )
# error "Error in SEC_SEEDKEYVENDOR.C: Source and header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION )
/* No constants needed for this variant*/
#else
 /* Cryptographic constants for seed/key calculation */
#define kA           3040238857uL
#define kB           4126034881uL
#define kC           2094854071uL
#define kD           3555108353uL

#define SecComputeSeedPartX(x)   (((kA) * (x)) + (kC))
#define SecComputeSeedPartY(y)   (((kB) * (y)) + (kD))
#endif /* SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#if defined( SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION )
/***********************************************************************************************************************
 *  SecM_CompareKeyVendor
 **********************************************************************************************************************/
/*! \brief       Compare received key against computed one
 *  \details     Runs the key calculation and compares the calculated key against the received key
 *  \param[in]   key Key for the authorisation
 *  \param[in]   seed The random seed the key calculation shall be based on
 *  \param[in]   constant A fixed constant used by the key calculation algorithm
 *                        Contains additional parameters (workspace, secret key) in case of extended API
 *  \return      SECM_OK if key calculation and comparison was successful
 *               SECM_NOT_OK if key calculation failed or key mismatch
 **********************************************************************************************************************/
/* PRQA S 3677 1 */ /* MD_SecSeedKeyVendor_3673_3677 */
SecM_StatusType SecM_CompareKeyVendor( SecM_KeyStorageType key, SecM_SeedStorageType seed, SecM_ConstType constant ) 
{
   SecM_StatusType   result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Avoid compiler warnings */
   (void)constant; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   result = SmhKeyJob_VerifyKey(SECM_OPERATIONMODE_SINGLECALL, V_NULL, seed, SEC_SEED_LENGTH, key, SEC_KEY_LENGTH);

   return result;
}
#else
/***********************************************************************************************************************
 *  SecM_ComputeKeyVendor
 **********************************************************************************************************************/
/*! \brief       Calculates a key value based on the provided seed and constant value
 *  \param[in]   inputSeed The random seed the key calculation shall be based on
 *  \param[in]   constant A fixed constant used by the key calculation algorithm
 *  \param[out]  computedKey Pointer to resulting key data as a formula of key = f(seed,k)
 *  \return      SECM_OK     if calculation was successful
 *               SECM_NOT_OK if calculation has failed (e.g. wrong parameters)
 **********************************************************************************************************************/
/* PRQA S 3677 2 */ /* MD_SecSeedKeyVendor_3673_3677 */
SecM_StatusType SecM_ComputeKeyVendor( SecM_SeedStorageType inputSeed, SecM_ConstType constant,
   V_MEMRAM1 SecM_KeyStorageType V_MEMRAM2 V_MEMRAM3 * computedKey )
{
   SecM_StatusType   result;

   result = SECM_OK;
   
   /* OEM dependent key calculation */
   inputSeed.seedX = SecComputeSeedPartX(inputSeed.seedX);
   inputSeed.seedY = SecComputeSeedPartY(inputSeed.seedY);

   *computedKey = inputSeed.seedX ^ inputSeed.seedY ^ constant;

   return result;
}
#endif /* SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/

/* Module specific MISRA deviations:

  MD_SecSeedKeyVendor_3673_3677:
     Reason: API defined by HIS specification.
     Risk: No identifiable risk.
     Prevention: No prevention required.

*/

/***********************************************************************************************************************
 *  END OF FILE: SEC_SEEDKEYVENDOR.C
 **********************************************************************************************************************/

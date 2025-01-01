/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Ssa_BcTp_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <Ssa_BcTp>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_BCTP_TYPE_H
# define RTE_SSA_BCTP_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef CRYPTO_E_VER_OK
#   define CRYPTO_E_VER_OK (0U)
#  endif

#  ifndef CRYPTO_E_VER_NOT_OK
#   define CRYPTO_E_VER_NOT_OK (1U)
#  endif

#  ifndef SECOC_VERIFICATIONSUCCESS
#   define SECOC_VERIFICATIONSUCCESS (0U)
#  endif

#  ifndef SECOC_VERIFICATIONFAILURE
#   define SECOC_VERIFICATIONFAILURE (1U)
#  endif

#  ifndef SECOC_FRESHNESSFAILURE
#   define SECOC_FRESHNESSFAILURE (2U)
#  endif

#  ifndef SECOC_AUTHENTICATIONBUILDFAILURE
#   define SECOC_AUTHENTICATIONBUILDFAILURE (3U)
#  endif

#  ifndef SECOC_NO_VERIFICATION
#   define SECOC_NO_VERIFICATION (4U)
#  endif

#  ifndef SECOC_VERIFICATIONFAILURE_OVERWRITTEN
#   define SECOC_VERIFICATIONFAILURE_OVERWRITTEN (5U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_BCTP_TYPE_H */

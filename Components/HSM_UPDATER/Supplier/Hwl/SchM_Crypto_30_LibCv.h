/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: vBRS
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to -
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ..\Include\SchM_Crypto_30_LibCv.h
 *   Generation Time: 2020-04-24 07:47:28
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: -
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

#ifndef SCHM_CRYPTO_30_LIBCV_H
# define SCHM_CRYPTO_30_LIBCV_H

# include "Os.h"

void Crypto_30_LibCv_MainFunction(void);

# define SchM_Enter_Crypto_30_LibCv_CRYPTO_30_LIBCV_EXCLUSIVE_AREA_0() SuspendAllInterrupts()
# define SchM_Exit_Crypto_30_LibCv_CRYPTO_30_LIBCV_EXCLUSIVE_AREA_0() ResumeAllInterrupts()

# define SchM_Enter_Crypto_30_LibCv_CRYPTO_30_LIBCV_EXCLUSIVE_AREA_1() SuspendAllInterrupts()
# define SchM_Exit_Crypto_30_LibCv_CRYPTO_30_LIBCV_EXCLUSIVE_AREA_1() ResumeAllInterrupts()

#endif /* SCHM_CRYPTO_30_LIBCV_H */

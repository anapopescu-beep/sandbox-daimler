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
 *             File:  Rte_Hook.h
 *           Config:  vHsmConfig.dpa
 *      ECU-Project:  vHsmConfig
 *
 *        Generator:  MICROSAR RTE Generator Version 4.28.0
 *                    RTE Core Version 1.28.0
 *          License:  CBD2200336
 *
 *      Description:  Header file containing definitions for VFB tracing
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Names of available VFB-Trace-Hooks
 **********************************************************************************************************************
 *
 * Not configured:
 *
 *  Rte_Runnable_Csm_Csm_MainFunction_Return
 *  Rte_Runnable_Csm_Csm_MainFunction_Start
 *  Rte_Runnable_KeyM_KeyM_MainFunction_Return
 *  Rte_Runnable_KeyM_KeyM_MainFunction_Start
 *  Rte_Runnable_NvM_NvM_MainFunction_Return
 *  Rte_Runnable_NvM_NvM_MainFunction_Start
 *  Rte_Runnable_Os_OsCore0_swc_GetCounterValue_Return
 *  Rte_Runnable_Os_OsCore0_swc_GetCounterValue_Start
 *  Rte_Runnable_Os_OsCore0_swc_GetElapsedValue_Return
 *  Rte_Runnable_Os_OsCore0_swc_GetElapsedValue_Start
 *  Rte_Task_Activate
 *  Rte_Task_Dispatch
 *  Rte_Task_Terminate
 *  Rte_Task_WaitEvent
 *  Rte_Task_WaitEventRet
 *  SchM_EnterHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_Crypto_30_LibCv_CRYPTO_30_LIBCV_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Crypto_30_LibCv_CRYPTO_30_LIBCV_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Crypto_30_LibCv_CRYPTO_30_LIBCV_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_Crypto_30_LibCv_CRYPTO_30_LIBCV_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_Csm_CSM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Csm_CSM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_KeyM_KEYM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_KeyM_KEYM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_KeyM_KEYM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_KeyM_KEYM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_NvM_NVM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_NvM_NVM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_vHsm_VHSM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_vHsm_VHSM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_vHsm_VHSM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_vHsm_VHSM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_Crypto_30_LibCv_CRYPTO_30_LIBCV_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Crypto_30_LibCv_CRYPTO_30_LIBCV_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Crypto_30_LibCv_CRYPTO_30_LIBCV_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_Crypto_30_LibCv_CRYPTO_30_LIBCV_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_Csm_CSM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Csm_CSM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_KeyM_KEYM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_KeyM_KEYM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_KeyM_KEYM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_KeyM_KEYM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_NvM_NVM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_NvM_NVM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_vHsm_VHSM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_vHsm_VHSM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_vHsm_VHSM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_vHsm_VHSM_EXCLUSIVE_AREA_1_Start
 *  SchM_Schedulable_Crypto_30_Hwa_Crypto_30_Hwa_MainFunction_Return
 *  SchM_Schedulable_Crypto_30_Hwa_Crypto_30_Hwa_MainFunction_Start
 *  SchM_Schedulable_Crypto_30_LibCv_Crypto_30_LibCv_MainFunction_Return
 *  SchM_Schedulable_Crypto_30_LibCv_Crypto_30_LibCv_MainFunction_Start
 *  SchM_Schedulable_Csm_Csm_MainFunction_Return
 *  SchM_Schedulable_Csm_Csm_MainFunction_Start
 *  SchM_Schedulable_Fee_Fee_MainFunction_Return
 *  SchM_Schedulable_Fee_Fee_MainFunction_Start
 *  SchM_Schedulable_Fls_17_Dmu_Fls_17_Dmu_MainFunction_Return
 *  SchM_Schedulable_Fls_17_Dmu_Fls_17_Dmu_MainFunction_Start
 *  SchM_Schedulable_KeyM_KeyM_MainBackgroundFunction_Return
 *  SchM_Schedulable_KeyM_KeyM_MainBackgroundFunction_Start
 *  SchM_Schedulable_KeyM_KeyM_MainFunction_Return
 *  SchM_Schedulable_KeyM_KeyM_MainFunction_Start
 *  SchM_Schedulable_NvM_NvM_MainFunction_Return
 *  SchM_Schedulable_NvM_NvM_MainFunction_Start
 *  SchM_Schedulable_vHsm_vHsm_MainFunction_Return
 *  SchM_Schedulable_vHsm_vHsm_MainFunction_Start
 *  SchM_Schedulable_vHsm_vHsm_MainFunction_vHsmSchedulableEntities_HighPrio_Return
 *  SchM_Schedulable_vHsm_vHsm_MainFunction_vHsmSchedulableEntities_HighPrio_Start
 *  SchM_Schedulable_vHsm_vHsm_MainFunction_vHsmSchedulableEntities_Unmapped_Return
 *  SchM_Schedulable_vHsm_vHsm_MainFunction_vHsmSchedulableEntities_Unmapped_Start
 *
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_HOOK_H
# define RTE_HOOK_H

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */

# include "Rte_Type.h"
# include "Rte_Cfg.h"

# ifndef RTE_VFB_TRACE
#  define RTE_VFB_TRACE (0)
# endif

#endif /* RTE_HOOK_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/

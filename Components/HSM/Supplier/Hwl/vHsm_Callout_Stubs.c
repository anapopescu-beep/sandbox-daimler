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
 *            Module: vHsm
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vHsm_Callout_Stubs.c
 *   Generation Time: 2022-08-05 10:59:07
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/********************************************************************************************************************** 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  EXAMPLE CODE ONLY 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW 
 *  configuration. The Example Code has not passed any quality control measures and may be incomplete. The 
 *  Example Code is neither intended nor qualified for use in series production. The Example Code as well 
 *  as any of its modifications and/or implementations must be tested with diligent care and must comply 
 *  with all quality requirements which are necessary according to the state of the art before their use.   
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#define VHSM_CALLOUT_STUBS_SOURCE
#include "Csm_Types.h"
#include "vHsm_Api.h"
#include "vHsm_Cfg.h"
#include "vHsm_Hal.h"


/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK UserIncludes>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if defined(_TASKING_C_TRICORE_) || defined(_TASKING_C_TRICORE_)
#include "IFX_HSM.h"
#endif

#ifdef _MICROSOFT_C_VTT_
#include "CANoeAPI.h"
#endif

#include "Crypto_30_LibCv_Cfg.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* Includes for module initialization */
#include "CryIf.h"
#include "Crypto_30_Hwa.h"
#include "Crypto_30_KeyM.h"
#include "Crypto_30_LibCv.h"
#include "Csm.h"
#include "KeyM.h"
#include "Rte_Main.h"
#include "vHsm_Hal.h"
#include "Fee.h"
#include "Fls_17_Dmu.h"
#include "NvM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK UserDeclarations>                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
 
extern void vHsm_StartupCallout(void);
extern void VHSM_FIRMWARE_UPDATER(void);

#define VHSM_THREASHOLD_PATTERN   (8u)
#define VHSM_THREASHOLD_ZERO      (8u)
#define VHSM_THREASHOLD_MAX       (8u)
#define VHSM_PATTERN              (0xA5u)

FUNC(void, VHSM_CODE) vHsm_generateKeyPairEd25519(void)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8 TrustModelEcuPublicKey[32] = { 0 };
    uint32 resultLength = 32;

     /* Check if public key is available */
    retVal = Csm_KeyElementGet(CsmConf_CsmKey_CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey, CryptoConf_CryptoKeyElement_Ssa_TrustModelEcuPublicCsr_StagingKey, TrustModelEcuPublicKey, &resultLength);
    
    if ((retVal == CRYPTO_E_KEY_NOT_AVAILABLE) || (retVal == CRYPTO_E_KEY_READ_FAIL) || (retVal == CRYPTO_E_KEY_EMPTY))
    {

        /* Generate Ed25519 Key-Pair */
        retVal = Csm_JobKeyGenerate(CsmConf_CsmJob_SSA_KeyPairGenerationEd25519, CsmConf_CsmKey_CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey);

        if (retVal == E_OK)
        {
            /* Set the generated Key-Pair Valid */
            retVal = Csm_KeySetValid(CsmConf_CsmKey_CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey);

            if (retVal == E_OK)
            {
                /* Copy the generated Public-Key to the respective TrustModel Public Key */
                retVal |= Csm_KeyElementCopy(CsmConf_CsmKey_CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey, CryptoConf_CryptoKeyElement_Crypto_30_LibCv_KeyExchange_OwnPubKey_ED25519, CsmConf_CsmKey_CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey, CryptoConf_CryptoKeyElement_Ssa_TrustModelEcuPublicCsr_StagingKey);

                if (retVal == E_OK)
                {
                    /* Set the respective TrustModel Keys Valid */
                    retVal |= Csm_KeySetValid(CsmConf_CsmKey_CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey);
#ifdef _MICROSOFT_C_VTT_
                    CANoeAPI_WriteString("Trust Model Private-Public ED25519 Key Pair generated.");
#endif

                }

            }

        }
    }

}

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CRYPTO_30_VHSM_HSM2_HOST_ADDRESS                                                            0xF0040034uL 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
 /* Mainfunction declarations */
#define FEE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern FUNC(void, FEE_CODE) Fee_MainFunction(void);

#define FEE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define FLS_17_DMU_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern FUNC(void, FLS_17_DMU_CODE) Fls_17_Dmu_MainFunction(void);

#define FLS_17_DMU_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK UserVariables>                         DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, VHSM_CODE) vHsm_SystemInit_Callout(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SystemInit>                             DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_SystemInit_Callout() */
  vHsm_StartupCallout();
  
#if (VHSM_OS_SUPPORT == STD_OFF)
  /* Set interrupt priorities to enable the interrupts */
  NVIC_SetPriority(BridgeErr_IRQn, 0u); 
  NVIC_SetPriority(TRNG_IRQn     , 0u);
  NVIC_SetPriority(Bridge_IRQn   , 0u);
  NVIC_SetPriority(TIM1_IRQn     , 0u);
  NVIC_SetPriority(TIM0_IRQn     , 0u);
#endif
  
#if defined(_TASKING_C_TRICORE_) || defined(_TASKING_C_TRICORE_)
  /* Set HSM to maximum clock speed */
  HSM_BRIDGE->CLKCTRL = (uint32)CLKCTRL_CLKDIV_DIV1 << CLKCTRL_CLKDIV_Pos; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */

  /* Enable parallel cache access */
  HSM_CACHE->CACHE_CTRL = (uint32)CACHE_CTRL_DAPCA_EN << CACHE_CTRL_DAPCA_Pos; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

FUNC(void, VHSM_CODE) vHsm_FirstStartup_Callout(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK FirstStartup>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_FirstStartup_Callout() */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

FUNC(void, VHSM_CODE) vHsm_NvM_InvalidBlockDetected_Callout(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK InvalidBlock>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_NvM_InvalidBlockDetected_Callout() */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

FUNC(void, VHSM_CODE) vHsm_InitOne_Callout(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK InitOne>                               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_InitOne_Callout() */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Call automatically detected initialization functions. */
  /* Calls can be avoided by encapsulate them with a preprocessor opened in pre and closed in post user block. */

  /* Initialization phase INIT_MEMORY */
  CryIf_InitMemory();
  Crypto_30_Hwa_InitMemory();
  Crypto_30_KeyM_InitMemory();
  Crypto_30_LibCv_InitMemory();
  Csm_InitMemory();
  KeyM_InitMemory();
  Rte_InitMemory();
  vHsm_Hal_InitMemory();

  /* Initialization phase INIT_ONE */
  Fee_Init(&Fee_Config);
  Fls_17_Dmu_Init(&Fls_17_Dmu_Config);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK InitOne_Post>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_InitOne_Callout() */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

FUNC(void, VHSM_CODE) vHsm_InitTwo_Callout(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK InitTwo>                                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_InitTwo_Callout() */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Call automatically detected initialization functions. */
  /* Calls can be avoided by encapsulate them with a preprocessor opened in pre and closed in post user block. */
  Crypto_30_Hwa_Init();
  Crypto_30_LibCv_Init();
  CryIf_Init();
  Crypto_30_KeyM_Init();
  Csm_Init();
  KeyM_Init(NULL_PTR);
  NvM_Init();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK InitTwo_Post>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_InitTwo_Callout() */
#ifdef  FLS_17_PMU_H
  /* Disable Timeout DET as described in TechRef. Timeout does not work on vHsm without OS. */
  Fls_17_Pmu_ControlTimeoutDet(0u);
#endif
#ifdef  FLS_17_DMU_H
  /* Disable Timeout DET as described in TechRef. Timeout does not work on vHsm without OS. */
  Fls_17_Dmu_ControlTimeoutDet(0u);
#endif
#ifdef  FEE_H
  /* Ensure the Fee initialization is done before continuing */
  while (Fee_GetStatus() != MEMIF_IDLE)
  {
    Fee_MainFunction();
#ifdef  FLS_17_PMU_H
    Fls_17_Pmu_MainFunction();
#endif
#ifdef  FLS_17_DMU_H
    Fls_17_Dmu_MainFunction();
#endif
  }
#endif

#ifdef _MICROSOFT_C_VTT_
  CANoeEmuProcessor_UnmaskInterrupt(OS_IRQ_vHsm_Hal_ExternalRequestIsr);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

FUNC(void, VHSM_CODE) vHsm_InitThree_Callout(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK InitThree>                             DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_InitThree_Callout() */
#if defined KEYM_H
  /* Ensure Startup Handling of KeyM is finished, task state is busy during startup */
  do
  {
    KeyM_MainFunction();
  } while(KeyM_Cert_IsBusy());
#endif /* KEYM_H */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Call automatically detected initialization functions. */
  /* Calls can be avoided by encapsulate them with a preprocessor opened in pre and closed in post user block. */
  Rte_Start();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK InitThree_Post>                         DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_InitThree_Callout() */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

FUNC(void, VHSM_CODE) vHsm_StartApplicationCores_Callout(void)
{
  /* The application cores shall be started in this callout */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK PreApplStart>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_PreApplicationStart_Callout() */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ApplStart>                              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 vHsm_Hal_StartApplicationCores();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK PostApplStart>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_PostApplicationStart_Callout() */

#if defined(_TASKING_C_TRICORE_) || defined(_TASKING_C_TRICORE_)
  while ((HSM_BRIDGE->HT2HSMS & 0xFFFFFF00u) != 0u)
  {
    /* HT2HSMS init value might not be zero after reset */
    /* Wait until application started and initialized HT2HSMS register */
  }
#endif

  /* Generate TrustModel ECU key-pair */
  vHsm_generateKeyPairEd25519();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

}

#if (VHSM_SECURE_BOOT == STD_ON)
FUNC(boolean, VHSM_CODE) vHsm_Custom_IsSecureBootAllowAutostart_Callout(
  vHsm_SecureBootGroupIterType secureBootGroupIndex,
  uint32 secureBootGroupId)
{
  /* Decide if the autostart shall be performed for this group or not.
   *  E.g. Use the current reset vectors to make a decision. */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SecureBootAllowAutostart>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_Custom_IsSecureBootAllowAutostart_Callout() */


   return TRUE;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

FUNC(boolean, VHSM_CODE) vHsm_Custom_IsSecureBootAllowCyclicVerification_Callout(
  vHsm_SecureBootGroupIterType secureBootGroupIndex,
  uint32 secureBootGroupId)
{
  /* Decide if the cycclic verification shall be performed for this group or not. */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SecureBootAllowCyclicVerification>      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_Custom_IsSecureBootAllowCyclicVerification_Callout() */


   return TRUE;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
#endif

FUNC(Std_ReturnType, VHSM_CODE) vHsm_Custom_SecureBootSanction_Callout(uint32 cryptoKeyId,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) vHsm_SecureBootInfoPtr)
{
  /* The secure boot failed for this segment.
     Perform a measure, e.g. write something to the error log or perform a reset. */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SecureBootSanction>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_Custom_SecureBootSanction_Callout() */

  return E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if(VHSM_SECURE_BOOT_SEGMENT_SUCCESS_CALLOUT == STD_ON)
FUNC(void, VHSM_CODE) vHsm_SecureBoot_SegmentSuccess_Callout(
  uint32 cryptoKeyId,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) vHsm_SecureBootInfoPtr)
{
  /* The secure boot was successful this segment. */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SecureBootSuccess>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_SecureBoot_SegmentSuccess_Callout() */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
#endif

# if (VHSM_SECURE_BOOT_UPDATE == STD_ON) || (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_Revision_Callout(
  uint32 secureBootGroupId,
  uint32 versionOfCurrentSegmentTable,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) segmentTableStartPtr,
  uint32 segmentListLength,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) newRevisionPtr)
{

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SecureBoot_Revision>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  Std_ReturnType retVal = E_OK;
  *newRevisionPtr = 0u;
  /* e.g. Check that revision is bigger than the old one and reject the update.
  if (versionOfCurrentSegmentTable >= *newRevisionPtr)
  {
	retVal = E_NOT_OK;
  }
   */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
#endif

# if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
FUNC(void, VHSM_CODE) vHsm_SecureBoot_CacheClearing_Callout(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) address,
  uint32 length)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SecureBoot_CacheClearing>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

FUNC(boolean, VHSM_CODE) vHsm_SecureBoot_PerformRecovery_Callout(
  uint32 groupIdx,
  vHsm_SecureBootSanctionReasonType recoveryReason)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK SecureBoot_PerformRecovery>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  return TRUE;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
# endif

FUNC(void, VHSM_CODE) vHsm_TriggerSoftwareReset_Callout(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK TriggerSoftwareReset>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_TriggerSoftwareReset_Callout() */
  vHsm_Hal_TriggerSoftwareReset();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


FUNC(void, VHSM_CODE) vHsm_NvM_ProcessBlock_Callout(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ProcessBlock>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_NvM_ProcessBlock_Callout() */
    NvM_MainFunction();
    Fee_MainFunction();
    Fls_17_Dmu_MainFunction();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

FUNC(void, VHSM_CODE) vHsm_NvMainFunctions_Callout(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK NvMainFunctions>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_NvMainFunctions_Callout() */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Call automatically detected memory functions. */
  /* Calls can be avoided by encapsulate them with a preprocessor opened in pre and closed in post user block. */
  NvM_MainFunction();
  Fee_MainFunction();
  Fls_17_Dmu_MainFunction();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK NvMainFunctions_Post>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

FUNC(void, VHSM_CODE) vHsm_MainFunctionCyclic_Callout(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK MainFunctionCyclic>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_MainFunctionCyclic_Callout() */
#ifdef _MICROSOFT_C_VTT_
  CANoeAPI_ConsumeTicks(100);
#endif

 *(volatile uint32*)CRYPTO_30_VHSM_HSM2_HOST_ADDRESS |=  (1u << 5);

  vHsm_NvMainFunctions_Callout();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Call automatically detected cyclic functions. */
  /* Calls can be avoided by encapsulate them with a preprocessor opened in pre and closed in post user block. */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK MainFunctionCyclic_Post>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if(VHSM_LOG_EVENT_CALLOUT_ENABLED == STD_ON)
FUNC(void, VHSM_CODE) vHsm_Log_Event_Callout(uint32 logEventId)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EventCallout>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_Log_Event_Callout() */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
#endif

#if(VHSM_LOG_THRESHOLD_CALLOUT_ENABLED == STD_ON)
FUNC(void, VHSM_CODE) vHsm_Log_FillLevelThreshold_Callout(uint32 logEventId)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK FillLevelThresholdCallout>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_Log_FillLevelThreshold_Callout() */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
#endif

#if (VHSM_LOG_TIMESTAMP_CALLOUT_ENABLED == STD_ON)
FUNC(void, VHSM_CODE) vHsm_Log_GetTimestamp_Callout(
  uint32 LogEventId,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) timestampPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) timestampLengthPtr)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK GetTimetsampCallout>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_Log_GetTimestamp_Callout() */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
#endif

FUNC(Std_ReturnType, VHSM_CODE) vHsm_PreRamLoop_Callout(void)
{
  Std_ReturnType retVal = E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK PreRamLoop>                                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_PreRamLoop_Callout() */
  /* If Ramloop shall not be entered, set retVal to E_NOT_OK. */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 return retVal;
}

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#if(VHSM_ENABLE_RAM_LOOP_CALLOUT == STD_ON)

# define VHSM_START_SEC_RAMCODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, VHSM_CODE) vHsm_RamLoop_Callout(void)
{
  Std_ReturnType retVal = E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK RamLoop>                                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_RamLoop_Callout() */

#ifdef _MICROSOFT_C_VTT_
  CANoeAPI_ConsumeTicks(1000);
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 return retVal;
}

# define VHSM_STOP_SEC_RAMCODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

#if (VHSM_FIRMWARE_UPDATE == STD_ON)

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, VHSM_CODE) vHsm_FirmwareUpdate_PreJmpToUpdater_Callout(void)
{
  /* Jump to updater will be performed after this callout */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK PreJmpToUpdaterStart>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_FirmwareUpdate_PreJmpToUpdater_Callout()
     e.g. disable Systick interrupt when OS is used. */

  *(volatile uint32*)0xE000E010=0;
  NVIC_DisableIRQ(BridgeErr_IRQn);
  NVIC_DisableIRQ(TRNG_IRQn);
  NVIC_DisableIRQ(Bridge_IRQn);
  NVIC_DisableIRQ(TIM0_IRQn);
  NVIC_DisableIRQ(TIM1_IRQn);
  
  NVIC_ClearPendingIRQ(BridgeErr_IRQn);
  NVIC_ClearPendingIRQ(TRNG_IRQn);
  NVIC_ClearPendingIRQ(Bridge_IRQn);
  NVIC_ClearPendingIRQ(TIM0_IRQn);
  NVIC_ClearPendingIRQ(TIM1_IRQn);

  DisableAllInterrupts();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define VHSM_START_SEC_CODE_MAC_CALLOUT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

const uint8 key[] = {0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u, 0x09u, 0x0Au, 0x0Bu, 0x0Cu, 0x0Du, 0x0Eu, 0x0Fu};

FUNC(Std_ReturnType, VHSM_CODE) vHsm_FirmwareUpdate_GetMacKey_Callout(
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) length)
{
  /* Get the secret mac key shared with vHsm Bootloader. */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK FirmwareUpdate_GetMacKey>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_FirmwareUpdate_GetMacKey_Callout() */
  /* The following lines needs to be replaced with code getting a secret key shared with the vHsm Bootloader. */
  uint8 i;
  for(i=0u; i < *length; i++)
  {
    keyPtr[i] = key[i];
  }

  return E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

# define VHSM_STOP_SEC_CODE_MAC_CALLOUT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)

#  define VHSM_START_SEC_CODE_CIPHER_CALLOUT
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, VHSM_CODE) vHsm_FirmwareUpdate_GetCipherKey_Callout(
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) length)
{
  /* Get the secret key cipher shared with vHsm Bootloader. */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK FirmwareUpdate_GetCipherKey>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of vHsm_FirmwareUpdate_GetCipherKey_Callout() */
  /* The following lines needs to be replaced with code getting a secret key shared with the vHsm Bootloader. */
  uint8 i;
  for(i=0u; i < *length; i++)
  {
    keyPtr[i] = key[i];
  }

  return E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#  define VHSM_STOP_SEC_CODE_CIPHER_CALLOUT
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON) */

#endif /* (VHSM_FIRMWARE_UPDATE == STD_ON) */

#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: VHSM_CALLOUT_STUBS.C
 *********************************************************************************************************************/



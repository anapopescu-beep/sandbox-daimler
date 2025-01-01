/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2020)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Fee_Cfg.h                                                     **
**                                                                            **
**  VERSION   : 1.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2023-08-16, 13:53:45    !!!IGNORE-LINE !!!                **
**                                                                            **
**  GENERATOR : Build b191017-0938                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Fee.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Fee configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Fee Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

#ifndef  FEE_CFG_H
#define  FEE_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Typedefs Imported from Memory Abstract Interface */ 
#include "MemIf_Types.h"

/* Callback functions imported from NvM Module */
#include "NvM_Cbk.h"


/* Functions imported from Fls Module */
#include "Fls_17_Dmu.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* FEE AS version information */
#define FEE_AS_VERSION (422)



#define FEE_AR_RELEASE_MAJOR_VERSION  (4U)
#define FEE_AR_RELEASE_MINOR_VERSION  (2U)
#define FEE_AR_RELEASE_REVISION_VERSION  (2U)
/* Vendor specific implementation version information */



#define FEE_SW_MAJOR_VERSION  (2U)
#define FEE_SW_MINOR_VERSION  (0U)
#define FEE_SW_PATCH_VERSION  (0U)

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                    Static configuration parameters                         **
*******************************************************************************/

/* Development error detection enabled/disabled */
#define FEE_DEV_ERROR_DETECT       (STD_ON)


/* Enable/Disable Safety error detection and reporting*/
#define FEE_SAFETY_ENABLE         (STD_OFF)

/* Enable/Disable FEE Init Check API*/
#define FEE_INITCHECK_API         (STD_OFF)
/* Fee_GetVersionInfo API enabled/disabled */
#define FEE_VERSION_INFO_API       (STD_OFF)

/* Fee_GetCycleCount API enabled/disabled */
#define FEE_GET_CYCLE_COUNT_API    (STD_OFF)
/* Fee_SetMode API enabled/disabled */

#define FEE_SET_MODE_SUPPORTED     (STD_ON)



/* Block type configured */

#define FEE_DATA_BLOCK_SUPPORTED FEE_DOUBLE_SECTOR_DATA_ONLY


/* Fee_17_GetPrevData API enabled/disabled */
#define FEE_GET_PREV_DATA_API      (STD_OFF)

#define FEE_CANCELL_ALL_API      (STD_OFF)


#define FEE_MAX_BYTES_PER_CYCLE      (512U)

/* FEE reaches illegal state upon detection virgin flash */
#define FEE_VIRGIN_FLASH_ILLEGAL_STATE      (STD_ON)

/* Enable/Disable Debug support  */
#define FEE_DEBUG_SUPPORT     (STD_OFF)


/*FeeMainFunctionPeriod value in micro seconds(us)*/
#define FEE_MAIN_FUNCTION_PERIOD       10000


/* Erase suspend/resume feature supported in FLS */
#define FEE_FLS_SUPPORTS_ERASE_SUSPEND  (STD_OFF)


/* DFlash WordLine size */
#define FEE_DFLASH_WORDLINE_SIZE     (512U)

#define FEE_CONTINUE          (0U)
#define FEE_STOP_AT_GC        (1U)


#define FEE_UNCFG_BLK_OVERFLOW_HANDLE    (FEE_CONTINUE)

/* Virtual page size, i.e., DF_EEPROM page size */
#define FEE_VIRTUAL_PAGE_SIZE      (8U)


/* Logical block's overhead in bytes */
#define FEE_BLOCK_OVERHEAD         (17U)


/* Logical block's data page overhead in bytes */
#define FEE_PAGE_OVERHEAD          (1U)

/* Maximum number of configured blocks to be handled */

#define FEE_MAX_BLOCK_COUNT        (18U)

/* Symbolic names of logical blocks */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Keys_Deferred_cons0 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Keys_Deferred_cons0 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Keys_Deferred_cons0 ((uint16)17)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Keys_Deferred_cons0 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Keys_Deferred 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Keys_Deferred already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Keys_Deferred ((uint16)16)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Keys_Deferred */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Keys_Immediate 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Keys_Immediate already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Keys_Immediate ((uint16)32)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Keys_Immediate */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Keys_Immediate_cons0 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Keys_Immediate_cons0 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Keys_Immediate_cons0 ((uint16)33)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Keys_Immediate_cons0 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_NvMConfigBlock 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_NvMConfigBlock already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_NvMConfigBlock ((uint16)64)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_NvMConfigBlock */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_NvMConfigBlock_cons0 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_NvMConfigBlock_cons0 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_NvMConfigBlock_cons0 ((uint16)65)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_NvMConfigBlock_cons0 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_NoRoot 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_NoRoot already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_NoRoot ((uint16)256)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_NoRoot */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_NoRoot_cons0 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_NoRoot_cons0 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_NoRoot_cons0 ((uint16)257)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_NoRoot_cons0 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_Root 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_Root already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_Root ((uint16)272)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_Root */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_Root_cons0 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_Root_cons0 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_Root_cons0 ((uint16)273)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_FeeKeys_Deferred_TrustModel_Root_cons0 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Keys_Deferred_SecOC 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Keys_Deferred_SecOC already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Keys_Deferred_SecOC ((uint16)192)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Keys_Deferred_SecOC */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Keys_Deferred_SecOC_cons0 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Keys_Deferred_SecOC_cons0 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Keys_Deferred_SecOC_cons0 ((uint16)193)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Keys_Deferred_SecOC_cons0 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Keys_Deferred_SharedSecretHash 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Keys_Deferred_SharedSecretHash already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Keys_Deferred_SharedSecretHash ((uint16)208)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Keys_Deferred_SharedSecretHash */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Keys_Deferred_SharedSecretHash_cons0 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Keys_Deferred_SharedSecretHash_cons0 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Keys_Deferred_SharedSecretHash_cons0 ((uint16)209)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Keys_Deferred_SharedSecretHash_cons0 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Keys_Immediate_BackendCert 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Keys_Immediate_BackendCert already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Keys_Immediate_BackendCert ((uint16)240)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Keys_Immediate_BackendCert */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Keys_Immediate_BackendCert_cons0 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Keys_Immediate_BackendCert_cons0 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Keys_Immediate_BackendCert_cons0 ((uint16)241)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Keys_Immediate_BackendCert_cons0 */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Keys_Immediate_RootCert 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Keys_Immediate_RootCert already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Keys_Immediate_RootCert ((uint16)224)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Keys_Immediate_RootCert */

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#ifdef FeeConf_FeeBlockConfiguration_Keys_Immediate_RootCert_cons0 
/* to prevent double declaration */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#error FeeConf_FeeBlockConfiguration_Keys_Immediate_RootCert_cons0 already defined
#else 
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FeeConf_FeeBlockConfiguration_Keys_Immediate_RootCert_cons0 ((uint16)225)
#endif /* #ifdef FeeConf_FeeBlockConfiguration_Keys_Immediate_RootCert_cons0 */


#define FEE_DISABLE_DEM_REPORT   (0U)
#define FEE_ENABLE_DEM_REPORT    (1U)

/* DEM Configurations */
#define FEE_GC_INIT_DEM_REPORT       (FEE_DISABLE_DEM_REPORT)
#define FEE_WRITE_DEM_REPORT         (FEE_DISABLE_DEM_REPORT)
#define FEE_READ_DEM_REPORT          (FEE_DISABLE_DEM_REPORT)
#define FEE_GC_WRITE_DEM_REPORT      (FEE_DISABLE_DEM_REPORT)
#define FEE_GC_READ_DEM_REPORT       (FEE_DISABLE_DEM_REPORT)
#define FEE_GC_ERASE_DEM_REPORT      (FEE_DISABLE_DEM_REPORT)
#define FEE_INVALIDATE_DEM_REPORT    (FEE_DISABLE_DEM_REPORT)
#define FEE_WRITE_CYCLES_DEM_REPORT  (FEE_DISABLE_DEM_REPORT)
#define FEE_GC_TRIG_DEM_REPORT       (FEE_DISABLE_DEM_REPORT)

#define FEE_UNCFG_BLK_DEM_REPORT     (FEE_DISABLE_DEM_REPORT)


#define FEE_DEM_ENABLED              (STD_OFF)
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#endif /* #ifndef FEE_CFG_H */

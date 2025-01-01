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
 *            Module: Fbl
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fbl_Cfg.h
 *   Generation Time: 2023-08-17 10:08:12
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined(__FBL_CFG_H__)
#define __FBL_CFG_H__

/* Global Constant Macros ********************************************************************************************/
#ifndef FBL_USE_DUMMY_STATEMENT
#define FBL_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FBL_DUMMY_STATEMENT
#define FBL_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FBL_DUMMY_STATEMENT_CONST
#define FBL_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef FBL_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define FBL_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef FBL_ATOMIC_VARIABLE_ACCESS
#define FBL_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef FBL_PROCESSOR_TC322L
#define FBL_PROCESSOR_TC322L
#endif
#ifndef FBL_COMP_TASKING
#define FBL_COMP_TASKING
#endif
#ifndef FBL_GEN_GENERATOR_MSR
#define FBL_GEN_GENERATOR_MSR
#endif
#ifndef FBL_CPUTYPE_BITORDER_LSB2MSB
#define FBL_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef FBL_CONFIGURATION_VARIANT_PRECOMPILE
#define FBL_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef FBL_CONFIGURATION_VARIANT_LINKTIME
#define FBL_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef FBL_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define FBL_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef FBL_CONFIGURATION_VARIANT
#define FBL_CONFIGURATION_VARIANT FBL_CONFIGURATION_VARIANT_LINKTIME
#endif
#ifndef FBL_POSTBUILD_VARIANT_SUPPORT
#define FBL_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

/* FblOem__base ******************************************************************************************************/
#define FBL_DISABLE_STAY_IN_BOOT 
#define FBL_USE_OWN_MEMCPY 
#define FBL_WATCHDOG_ON 
#define FBL_WATCHDOG_TIME                        (1u / FBL_REPEAT_CALL_CYCLE) 
#define FBL_HEADER_ADDRESS                       0xA0048320u 
#define FBL_ENABLE_APPL_TIMER_TASK 
#define FBL_ENABLE_APPL_TASK 
#define FBL_DISABLE_APPL_STATE_TASK 
#define SWM_DATA_MAX_NOAR                        10u 
#define FBL_DIAG_BUFFER_LENGTH                   4097u 
#define FBL_DIAG_TIME_P2MAX                      (20u / FBL_REPEAT_CALL_CYCLE) 
#define FBL_DIAG_TIME_P3MAX                      (2000u / FBL_REPEAT_CALL_CYCLE) 
#define FBL_ENABLE_SLEEPMODE 
#define FBL_SLEEP_TIME                           300000u 
#define FBL_ENABLE_GAP_FILL 
#define kFillChar                                0xAAu 
#define FBL_DISABLE_GATEWAY_SUPPORT 
#define FBL_ENABLE_PRESENCE_PATTERN 
#define FBL_ENABLE_FBL_START 
#define FBL_ENABLE_COMMON_DATA 
#define FBL_DISABLE_RESPONSE_AFTER_RESET 
#define FBL_DISABLE_USERSUBFUNCTION 
#define FBL_DISABLE_USERSERVICE 
#define FBL_DISABLE_USERROUTINE 
#define FBL_DIAG_TIME_S3EXT                      (5000u / FBL_REPEAT_CALL_CYCLE) 
#define FBL_DIAG_TIME_S3PRG                      (5000u / FBL_REPEAT_CALL_CYCLE) 
#define FBL_DISABLE_HARDWARE_SWAP 
#define FBL_DISABLE_XCP 
#define FBL_DIAG_DISABLE_FLASHDRV_DOWNLOAD 
#define FBL_DIAG_ENABLE_FLASHDRV_ROM 
#define FBL_ENABLE_DATA_PROCESSING 
#define FBL_ENABLE_ENCRYPTION_MODE 
#define FBL_ENABLE_COMPRESSION_MODE 
#define FBL_INTEGRATION                          2u 
#define FBL_PRODUCTION                           1u 
#define FBL_PROJECT_STATE                        FBL_INTEGRATION 
#define FBL_ENABLE_SYSTEM_CHECK 
#define FBL_ENABLE_DEBUG_STATUS 
#define FBL_ENABLE_ASSERTION 
#define FBL_MEM_PROC_BUFFER_SIZE                 256u 
#define FBL_MEM_ENABLE_VERIFY_INPUT 
#define FBL_MEM_DISABLE_VERIFY_PROCESSED 
#define FBL_MEM_ENABLE_VERIFY_PIPELINED 
#define FBL_MEM_DISABLE_VERIFY_OUTPUT 
#define FBL_MEM_VERIFY_SEGMENTATION              256u 
#define FBL_DISABLE_ADAPTIVE_DATA_TRANSFER_RCRRP 
#define FBL_ENABLE_PIPELINED_PROGRAMMING 
#define FBL_DISABLE_SUSPEND_PROGRAMMING 
#define FBL_MEM_WRITE_SEGMENTATION               256u 
#define FBL_ENABLE_UNALIGNED_DATA_TRANSFER 
#define FBL_BLOCK_START_ADDRESS                  0xA0048000u 
#define FBL_BLOCK_LENGTH                         147456u 
#define FBL_DISABLE_OTA 
#define FBL_DISABLE_ONE_STEP_UPDATER 

/* FblHal ************************************************************************************************************/
#include "FblHal_Cfg.h"
/* FblOem_Daimler ****************************************************************************************************/
#define FBL_ENABLE_FLASH_ERASED_DETECTION 
#define FBL_MEM_DISABLE_RESUMABLE_PROGRAMMING 
#define FBL_DIAG_DDS_R01_01_2016_06           0x00u 
#define FBL_DIAG_DDS_R01_01_2020_01           0x01u 
#define FBL_DIAG_DDS_VERSION                  FBL_DIAG_DDS_R01_01_2020_01 

/* User Config File **************************************************************************************************/
/* User Config File Start */
/* User Section Part************************************************************** */

/* Multiple Platforms Settings */
#define FBL_DISABLE_MULTIPLE_PLATFORMS

#if defined( FBL_ENABLE_MULTIPLE_PLATFORMS )
/* Platform Message Window in ms */
# define FBL_START_DELAY                500u
#endif

#define EEP_BUFFER_SIZE 0x200u

#define FBL_APPL_DISABLE_DOIP
#define FBL_APPL_ENABLE_BUSTYPE_CAN
#define FBL_APPL_DISABLE_BUSTYPE_FR

# define FBL_APPL_ENABLE_DECOMPRESSION_LZMA
# define FBL_APPL_DISABLE_DECOMPRESSION_VECTOR

#ifdef FBL_DIAG_TIME_S3EXT                      
#undef FBL_DIAG_TIME_S3EXT
#define FBL_DIAG_TIME_S3EXT						(19000u / FBL_REPEAT_CALL_CYCLE)
#endif

#ifdef FBL_DIAG_TIME_S3PRG                      
#undef FBL_DIAG_TIME_S3PRG
#define FBL_DIAG_TIME_S3PRG						(19000u / FBL_REPEAT_CALL_CYCLE)
#endif
/* User Config File End */


/* User Section ******************************************************************************************************/

#endif /* __FBL_CFG_H__ */


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
 *            Module: FblHal
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FblHal_Cfg.h
 *   Generation Time: 2023-07-17 14:11:51
 *           Project: CBD2000614_Bm - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined(__FBL_HAL_H__)
#define __FBL_HAL_H__

/* FblHal__base ******************************************************************************************************/
#define FBL_FLASH_ENABLE_ECC_SAFE_READ 
#define FLASH_SIZE                     2048 
#define FBL_TIMER_RELOAD_VALUE         79999 
#define FBL_TIMER_PRESCALER_VALUE      1 

/* Derivative Specific Defines */
#define FBL_SFR_BASE_ADRESSES_PRECONFIGURED
#define FBL_PORT_BASE      0xF003A000u       /**< Port handling base address */
#define FBL_PFI_BASE       0xA8080000u       /**< PFI base address */
#define FBL_SCU_BASE       0xF0036000u       /**< System control unit base address */
#define FBL_DMU_BASE       0xF8040000u       /**< Data memory unit base address */
#define FBL_GPT12_BASE     0xF0001800u       /**< GPT12 base address */
#define FBL_CPUSFR_BASE    0xF8800000u       /**< CPU SFR base address */
#define FBL_STM_BASE       0xF0001000u       /**< System timer module base address */
#define C_COMP_TASKING_TRICORE_MULTICAN
#define V_COMP_TASKING_TRICORE
#define V_CPU_TRICORE
#define C_CPUTYPE_32BIT
#define VGEN_ENABLE_CANFBL
#define V_SUPPRESS_EXTENDED_VERSION_CHECK
#define V_ENABLE_VSTDLIB_ASR_ABSTRACTION
#define C_CPUTYPE_BITORDER_LSB2MSB
#if defined( FBL_ENABLE_OTA )
# if defined( FBL_ENABLE_HARDWARE_SWAP )
#  define FLASH_ENABLE_TRICORE_SWAP
#  define FLASH_ENABLE_TRICORE_SWAP_ROUTINE
#  define FLASH_ENABLE_TRICORE_UCB_ERASE
#  define FLASH_ENABLE_TRICORE_UCB_WRITE
#  define FLASH_ENABLE_TRICORE_UCB_READ
# endif
#endif

/* FblHal_Tricore ****************************************************************************************************/
#define FBL_PF0_SIZE 3072 
#define FBL_PF1_SIZE 3072 
#define FBL_PF2_SIZE 3072 
#define FBL_PF3_SIZE 3072 
#define FBL_PF4_SIZE 3072 
#define FBL_PF5_SIZE 1024 


#endif /* __FBL_HAL_H__ */


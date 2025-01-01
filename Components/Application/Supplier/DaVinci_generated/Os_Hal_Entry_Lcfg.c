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
 *            Module: Os
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Entry_Lcfg.c
 *   Generation Time: 2023-10-05 14:21:23
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_ENTRY_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Entry_Cfg.h"
#include "Os_Hal_Entry_Lcfg.h"
#include "Os_Hal_Entry.h"

/* Os kernel module dependencies */
#include "Os_Isr_Lcfg.h"
#include "Os.h"

/* Os hal dependencies */
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Interrupt_Cfg.h"
#include "Os_Hal_Trap.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXCEPTION VECTOR TABLE CORE 0
 *********************************************************************************************************************/


#define OS_START_SEC_EXCVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

Os_Hal_ExceptionSectionDeclaration(0)
Os_Hal_UnhandledTrapEntry(0, 0)
Os_Hal_UnhandledTrapEntry(0, 1)
Os_Hal_UnhandledTrapEntry(0, 2)
Os_Hal_UnhandledTrapEntry(0, 3)
Os_Hal_UnhandledTrapEntry(0, 4)
Os_Hal_UnhandledTrapEntry(0, 5)
Os_Hal_UnhandledTrapEntry(0, 6)
Os_Hal_UnhandledTrapEntry(0, 7)

#define OS_STOP_SEC_EXCVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 *  INTERRUPT VECTOR TABLE CORE 0
 *********************************************************************************************************************/


#define OS_START_SEC_INTVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

Os_Hal_InterruptSectionDeclaration(0)
Os_Hal_UnhandledInterruptEntry(0, 0) 
Os_Hal_Cat2InterruptEntry(0, 1, OS_CFG_HAL_ISR2_DISABLE_LEVEL, OsCfg_Isr_vHsmResponseIsr)
Os_Hal_UnhandledInterruptEntry(0, 2) 
Os_Hal_UnhandledInterruptEntry(0, 3) 
Os_Hal_UnhandledInterruptEntry(0, 4) 
Os_Hal_UnhandledInterruptEntry(0, 5) 
Os_Hal_UnhandledInterruptEntry(0, 6) 
Os_Hal_UnhandledInterruptEntry(0, 7) 
Os_Hal_UnhandledInterruptEntry(0, 8) 
Os_Hal_UnhandledInterruptEntry(0, 9) 
Os_Hal_UnhandledInterruptEntry(0, 10) 
Os_Hal_UnhandledInterruptEntry(0, 11) 
Os_Hal_UnhandledInterruptEntry(0, 12) 
Os_Hal_UnhandledInterruptEntry(0, 13) 
Os_Hal_UnhandledInterruptEntry(0, 14) 
Os_Hal_UnhandledInterruptEntry(0, 15) 
Os_Hal_UnhandledInterruptEntry(0, 16) 
Os_Hal_UnhandledInterruptEntry(0, 17) 
Os_Hal_UnhandledInterruptEntry(0, 18) 
Os_Hal_UnhandledInterruptEntry(0, 19) 
Os_Hal_UnhandledInterruptEntry(0, 20) 
Os_Hal_UnhandledInterruptEntry(0, 21) 
Os_Hal_UnhandledInterruptEntry(0, 22) 
Os_Hal_UnhandledInterruptEntry(0, 23) 
Os_Hal_UnhandledInterruptEntry(0, 24) 
Os_Hal_UnhandledInterruptEntry(0, 25) 
Os_Hal_UnhandledInterruptEntry(0, 26) 
Os_Hal_UnhandledInterruptEntry(0, 27) 
Os_Hal_UnhandledInterruptEntry(0, 28) 
Os_Hal_UnhandledInterruptEntry(0, 29) 
Os_Hal_UnhandledInterruptEntry(0, 30) 
Os_Hal_UnhandledInterruptEntry(0, 31) 
Os_Hal_UnhandledInterruptEntry(0, 32) 
Os_Hal_UnhandledInterruptEntry(0, 33) 
Os_Hal_UnhandledInterruptEntry(0, 34) 
Os_Hal_UnhandledInterruptEntry(0, 35) 
Os_Hal_UnhandledInterruptEntry(0, 36) 
Os_Hal_UnhandledInterruptEntry(0, 37) 
Os_Hal_UnhandledInterruptEntry(0, 38) 
Os_Hal_UnhandledInterruptEntry(0, 39) 
Os_Hal_UnhandledInterruptEntry(0, 40) 
Os_Hal_UnhandledInterruptEntry(0, 41) 
Os_Hal_UnhandledInterruptEntry(0, 42) 
Os_Hal_UnhandledInterruptEntry(0, 43) 
Os_Hal_UnhandledInterruptEntry(0, 44) 
Os_Hal_UnhandledInterruptEntry(0, 45) 
Os_Hal_UnhandledInterruptEntry(0, 46) 
Os_Hal_UnhandledInterruptEntry(0, 47) 
Os_Hal_UnhandledInterruptEntry(0, 48) 
Os_Hal_UnhandledInterruptEntry(0, 49) 
Os_Hal_Cat2InterruptEntry(0, 50, OS_CFG_HAL_ISR2_DISABLE_LEVEL, OsCfg_Isr_CounterIsr_SystemTimer)
Os_Hal_UnhandledInterruptEntry(0, 51) 
Os_Hal_UnhandledInterruptEntry(0, 52) 
Os_Hal_UnhandledInterruptEntry(0, 53) 
Os_Hal_UnhandledInterruptEntry(0, 54) 
Os_Hal_UnhandledInterruptEntry(0, 55) 
Os_Hal_UnhandledInterruptEntry(0, 56) 
Os_Hal_UnhandledInterruptEntry(0, 57) 
Os_Hal_UnhandledInterruptEntry(0, 58) 
Os_Hal_UnhandledInterruptEntry(0, 59) 
Os_Hal_Cat2InterruptEntry(0, 60, OS_CFG_HAL_ISR2_DISABLE_LEVEL, OsCfg_Isr_CanIsr_1)
Os_Hal_Cat2InterruptEntry(0, 61, OS_CFG_HAL_ISR2_DISABLE_LEVEL, OsCfg_Isr_RCM_SRamEccFailure_Notification)
Os_Hal_Cat2InterruptEntry(0, 62, OS_CFG_HAL_ISR2_DISABLE_LEVEL, OsCfg_Isr_RCM_PFlashEccFailure_Notification)
Os_Hal_Cat1InterruptEntry(0, 63, OS_ISR_BMM_HES_IT)
Os_Hal_Cat1InterruptEntry(0, 64, OS_ISR_BMM_HES_TOUT)
Os_Hal_UnhandledInterruptEntry(0, 65) 
Os_Hal_UnhandledInterruptEntry(0, 66) 
Os_Hal_UnhandledInterruptEntry(0, 67) 
Os_Hal_UnhandledInterruptEntry(0, 68) 
Os_Hal_UnhandledInterruptEntry(0, 69) 
Os_Hal_UnhandledInterruptEntry(0, 70) 
Os_Hal_UnhandledInterruptEntry(0, 71) 
Os_Hal_UnhandledInterruptEntry(0, 72) 
Os_Hal_UnhandledInterruptEntry(0, 73) 
Os_Hal_UnhandledInterruptEntry(0, 74) 
Os_Hal_UnhandledInterruptEntry(0, 75) 
Os_Hal_UnhandledInterruptEntry(0, 76) 
Os_Hal_UnhandledInterruptEntry(0, 77) 
Os_Hal_UnhandledInterruptEntry(0, 78) 
Os_Hal_UnhandledInterruptEntry(0, 79) 
Os_Hal_UnhandledInterruptEntry(0, 80) 
Os_Hal_UnhandledInterruptEntry(0, 81) 
Os_Hal_UnhandledInterruptEntry(0, 82) 
Os_Hal_UnhandledInterruptEntry(0, 83) 
Os_Hal_UnhandledInterruptEntry(0, 84) 
Os_Hal_UnhandledInterruptEntry(0, 85) 
Os_Hal_UnhandledInterruptEntry(0, 86) 
Os_Hal_UnhandledInterruptEntry(0, 87) 
Os_Hal_UnhandledInterruptEntry(0, 88) 
Os_Hal_UnhandledInterruptEntry(0, 89) 
Os_Hal_UnhandledInterruptEntry(0, 90) 
Os_Hal_UnhandledInterruptEntry(0, 91) 
Os_Hal_UnhandledInterruptEntry(0, 92) 
Os_Hal_UnhandledInterruptEntry(0, 93) 
Os_Hal_UnhandledInterruptEntry(0, 94) 
Os_Hal_UnhandledInterruptEntry(0, 95) 
Os_Hal_UnhandledInterruptEntry(0, 96) 
Os_Hal_UnhandledInterruptEntry(0, 97) 
Os_Hal_UnhandledInterruptEntry(0, 98) 
Os_Hal_UnhandledInterruptEntry(0, 99) 
Os_Hal_UnhandledInterruptEntry(0, 100) 
Os_Hal_UnhandledInterruptEntry(0, 101) 
Os_Hal_UnhandledInterruptEntry(0, 102) 
Os_Hal_UnhandledInterruptEntry(0, 103) 
Os_Hal_UnhandledInterruptEntry(0, 104) 
Os_Hal_UnhandledInterruptEntry(0, 105) 
Os_Hal_UnhandledInterruptEntry(0, 106) 
Os_Hal_UnhandledInterruptEntry(0, 107) 
Os_Hal_UnhandledInterruptEntry(0, 108) 
Os_Hal_UnhandledInterruptEntry(0, 109) 
Os_Hal_UnhandledInterruptEntry(0, 110) 
Os_Hal_UnhandledInterruptEntry(0, 111) 
Os_Hal_UnhandledInterruptEntry(0, 112) 
Os_Hal_UnhandledInterruptEntry(0, 113) 
Os_Hal_UnhandledInterruptEntry(0, 114) 
Os_Hal_UnhandledInterruptEntry(0, 115) 
Os_Hal_UnhandledInterruptEntry(0, 116) 
Os_Hal_UnhandledInterruptEntry(0, 117) 
Os_Hal_UnhandledInterruptEntry(0, 118) 
Os_Hal_UnhandledInterruptEntry(0, 119) 
Os_Hal_UnhandledInterruptEntry(0, 120) 
Os_Hal_UnhandledInterruptEntry(0, 121) 
Os_Hal_UnhandledInterruptEntry(0, 122) 
Os_Hal_UnhandledInterruptEntry(0, 123) 
Os_Hal_UnhandledInterruptEntry(0, 124) 
Os_Hal_UnhandledInterruptEntry(0, 125) 
Os_Hal_UnhandledInterruptEntry(0, 126) 
Os_Hal_UnhandledInterruptEntry(0, 127) 
Os_Hal_UnhandledInterruptEntry(0, 128) 
Os_Hal_UnhandledInterruptEntry(0, 129) 
Os_Hal_UnhandledInterruptEntry(0, 130) 
Os_Hal_UnhandledInterruptEntry(0, 131) 
Os_Hal_UnhandledInterruptEntry(0, 132) 
Os_Hal_UnhandledInterruptEntry(0, 133) 
Os_Hal_UnhandledInterruptEntry(0, 134) 
Os_Hal_UnhandledInterruptEntry(0, 135) 
Os_Hal_UnhandledInterruptEntry(0, 136) 
Os_Hal_UnhandledInterruptEntry(0, 137) 
Os_Hal_UnhandledInterruptEntry(0, 138) 
Os_Hal_UnhandledInterruptEntry(0, 139) 
Os_Hal_UnhandledInterruptEntry(0, 140) 
Os_Hal_UnhandledInterruptEntry(0, 141) 
Os_Hal_UnhandledInterruptEntry(0, 142) 
Os_Hal_UnhandledInterruptEntry(0, 143) 
Os_Hal_UnhandledInterruptEntry(0, 144) 
Os_Hal_UnhandledInterruptEntry(0, 145) 
Os_Hal_UnhandledInterruptEntry(0, 146) 
Os_Hal_UnhandledInterruptEntry(0, 147) 
Os_Hal_UnhandledInterruptEntry(0, 148) 
Os_Hal_UnhandledInterruptEntry(0, 149) 
Os_Hal_UnhandledInterruptEntry(0, 150) 
Os_Hal_UnhandledInterruptEntry(0, 151) 
Os_Hal_UnhandledInterruptEntry(0, 152) 
Os_Hal_UnhandledInterruptEntry(0, 153) 
Os_Hal_UnhandledInterruptEntry(0, 154) 
Os_Hal_UnhandledInterruptEntry(0, 155) 
Os_Hal_UnhandledInterruptEntry(0, 156) 
Os_Hal_UnhandledInterruptEntry(0, 157) 
Os_Hal_UnhandledInterruptEntry(0, 158) 
Os_Hal_UnhandledInterruptEntry(0, 159) 
Os_Hal_UnhandledInterruptEntry(0, 160) 
Os_Hal_UnhandledInterruptEntry(0, 161) 
Os_Hal_UnhandledInterruptEntry(0, 162) 
Os_Hal_UnhandledInterruptEntry(0, 163) 
Os_Hal_UnhandledInterruptEntry(0, 164) 
Os_Hal_UnhandledInterruptEntry(0, 165) 
Os_Hal_UnhandledInterruptEntry(0, 166) 
Os_Hal_UnhandledInterruptEntry(0, 167) 
Os_Hal_UnhandledInterruptEntry(0, 168) 
Os_Hal_UnhandledInterruptEntry(0, 169) 
Os_Hal_UnhandledInterruptEntry(0, 170) 
Os_Hal_UnhandledInterruptEntry(0, 171) 
Os_Hal_UnhandledInterruptEntry(0, 172) 
Os_Hal_UnhandledInterruptEntry(0, 173) 
Os_Hal_UnhandledInterruptEntry(0, 174) 
Os_Hal_UnhandledInterruptEntry(0, 175) 
Os_Hal_UnhandledInterruptEntry(0, 176) 
Os_Hal_UnhandledInterruptEntry(0, 177) 
Os_Hal_UnhandledInterruptEntry(0, 178) 
Os_Hal_UnhandledInterruptEntry(0, 179) 
Os_Hal_UnhandledInterruptEntry(0, 180) 
Os_Hal_UnhandledInterruptEntry(0, 181) 
Os_Hal_UnhandledInterruptEntry(0, 182) 
Os_Hal_UnhandledInterruptEntry(0, 183) 
Os_Hal_UnhandledInterruptEntry(0, 184) 
Os_Hal_UnhandledInterruptEntry(0, 185) 
Os_Hal_UnhandledInterruptEntry(0, 186) 
Os_Hal_UnhandledInterruptEntry(0, 187) 
Os_Hal_UnhandledInterruptEntry(0, 188) 
Os_Hal_UnhandledInterruptEntry(0, 189) 
Os_Hal_UnhandledInterruptEntry(0, 190) 
Os_Hal_UnhandledInterruptEntry(0, 191) 
Os_Hal_UnhandledInterruptEntry(0, 192) 
Os_Hal_UnhandledInterruptEntry(0, 193) 
Os_Hal_UnhandledInterruptEntry(0, 194) 
Os_Hal_UnhandledInterruptEntry(0, 195) 
Os_Hal_UnhandledInterruptEntry(0, 196) 
Os_Hal_UnhandledInterruptEntry(0, 197) 
Os_Hal_UnhandledInterruptEntry(0, 198) 
Os_Hal_UnhandledInterruptEntry(0, 199) 
Os_Hal_UnhandledInterruptEntry(0, 200) 
Os_Hal_UnhandledInterruptEntry(0, 201) 
Os_Hal_UnhandledInterruptEntry(0, 202) 
Os_Hal_UnhandledInterruptEntry(0, 203) 
Os_Hal_UnhandledInterruptEntry(0, 204) 
Os_Hal_UnhandledInterruptEntry(0, 205) 
Os_Hal_UnhandledInterruptEntry(0, 206) 
Os_Hal_UnhandledInterruptEntry(0, 207) 
Os_Hal_UnhandledInterruptEntry(0, 208) 
Os_Hal_UnhandledInterruptEntry(0, 209) 
Os_Hal_UnhandledInterruptEntry(0, 210) 
Os_Hal_UnhandledInterruptEntry(0, 211) 
Os_Hal_UnhandledInterruptEntry(0, 212) 
Os_Hal_UnhandledInterruptEntry(0, 213) 
Os_Hal_UnhandledInterruptEntry(0, 214) 
Os_Hal_UnhandledInterruptEntry(0, 215) 
Os_Hal_UnhandledInterruptEntry(0, 216) 
Os_Hal_UnhandledInterruptEntry(0, 217) 
Os_Hal_UnhandledInterruptEntry(0, 218) 
Os_Hal_UnhandledInterruptEntry(0, 219) 
Os_Hal_UnhandledInterruptEntry(0, 220) 
Os_Hal_UnhandledInterruptEntry(0, 221) 
Os_Hal_UnhandledInterruptEntry(0, 222) 
Os_Hal_UnhandledInterruptEntry(0, 223) 
Os_Hal_UnhandledInterruptEntry(0, 224) 
Os_Hal_UnhandledInterruptEntry(0, 225) 
Os_Hal_UnhandledInterruptEntry(0, 226) 
Os_Hal_UnhandledInterruptEntry(0, 227) 
Os_Hal_UnhandledInterruptEntry(0, 228) 
Os_Hal_UnhandledInterruptEntry(0, 229) 
Os_Hal_UnhandledInterruptEntry(0, 230) 
Os_Hal_UnhandledInterruptEntry(0, 231) 
Os_Hal_UnhandledInterruptEntry(0, 232) 
Os_Hal_UnhandledInterruptEntry(0, 233) 
Os_Hal_UnhandledInterruptEntry(0, 234) 
Os_Hal_UnhandledInterruptEntry(0, 235) 
Os_Hal_UnhandledInterruptEntry(0, 236) 
Os_Hal_UnhandledInterruptEntry(0, 237) 
Os_Hal_UnhandledInterruptEntry(0, 238) 
Os_Hal_UnhandledInterruptEntry(0, 239) 
Os_Hal_UnhandledInterruptEntry(0, 240) 
Os_Hal_UnhandledInterruptEntry(0, 241) 
Os_Hal_UnhandledInterruptEntry(0, 242) 
Os_Hal_UnhandledInterruptEntry(0, 243) 
Os_Hal_UnhandledInterruptEntry(0, 244) 
Os_Hal_UnhandledInterruptEntry(0, 245) 
Os_Hal_UnhandledInterruptEntry(0, 246) 
Os_Hal_UnhandledInterruptEntry(0, 247) 
Os_Hal_UnhandledInterruptEntry(0, 248) 
Os_Hal_UnhandledInterruptEntry(0, 249) 
Os_Hal_UnhandledInterruptEntry(0, 250) 
Os_Hal_UnhandledInterruptEntry(0, 251) 
Os_Hal_UnhandledInterruptEntry(0, 252) 
Os_Hal_UnhandledInterruptEntry(0, 253) 
Os_Hal_UnhandledInterruptEntry(0, 254) 
Os_Hal_UnhandledInterruptEntry(0, 255) 

#define OS_STOP_SEC_INTVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Lcfg.c
 *********************************************************************************************************************/

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
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000612_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Entry_Lcfg.c
 *   Generation Time: 2022-04-13 13:52:50
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2000612_D04
 *      Tool Version: DaVinci Configurator (beta) 5.24.30 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

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




/**********************************************************************************************************************
 *  INTERRUPT VECTOR TABLE CORE 0
 *********************************************************************************************************************/

#define OS_START_SEC_INTVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Extern declarations of the ISR wrappers. */
extern void Os_Isr_Core0_Interrupt_19(void);

#define OS_STOP_SEC_INTVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_INTVEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

OS_HAL_CONST_ATTRIBUTE_DEFINITION
(
  Os_Hal_VectorTableEntryType,
  OS_CONST,
  OS_HAL_SECTION_ATTRIBUTE(".OS_INTVEC_CORE0_CONST"),
  OsCfg_Hal_Core_OsCore0_VectorTable[513]
) =
{
  /* Reset stack value: Init stack OsCore0 */
  (Os_Hal_VectorTableEntryType)((uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn)+1)), /* PRQA S 0305, 0306 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* Reset: Core entry symbol OsCore0 */
  (Os_Hal_VectorTableEntryType)((uint32)&(_start)), /* PRQA S 0305, 0306, 0324 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* User configured exceptions and interrupts: */
  Os_Hal_UnhandledEXC, /* Exception: 2 */
  Os_Hal_UnhandledEXC, /* Exception: 3 */
  Os_Hal_UnhandledEXC, /* Exception: 4 */
  Os_Hal_UnhandledEXC, /* Exception: 5 */
  Os_Hal_UnhandledEXC, /* Exception: 6 */
  Os_Hal_UnhandledEXC, /* Exception: 7 */
  Os_Hal_UnhandledEXC, /* Exception: 8 */
  Os_Hal_UnhandledEXC, /* Exception: 9 */
  Os_Hal_UnhandledEXC, /* Exception: 10 */
  Os_Hal_SysCallHandler, /* OS internal SVCall (Number 11) exception handler */
  Os_Hal_UnhandledEXC, /* Exception: 12 */
  Os_Hal_UnhandledEXC, /* Exception: 13 */
  Os_Hal_UnhandledEXC, /* Exception: 14 */
  Os_Hal_UnhandledEXC, /* Exception: 15 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 16 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 17 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 18 */
  Os_Isr_Core0_Interrupt_19, /* External interrupt: 19 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 20 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 21 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 22 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 23 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 24 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 25 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 26 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 27 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 28 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 29 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 30 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 31 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 32 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 33 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 34 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 35 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 36 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 37 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 38 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 39 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 40 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 41 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 42 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 43 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 44 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 45 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 46 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 47 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 48 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 49 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 50 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 51 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 52 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 53 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 54 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 55 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 56 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 57 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 58 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 59 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 60 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 61 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 62 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 63 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 64 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 65 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 66 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 67 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 68 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 69 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 70 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 71 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 72 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 73 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 74 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 75 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 76 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 77 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 78 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 79 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 80 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 81 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 82 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 83 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 84 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 85 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 86 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 87 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 88 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 89 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 90 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 91 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 92 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 93 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 94 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 95 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 96 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 97 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 98 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 99 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 100 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 101 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 102 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 103 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 104 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 105 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 106 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 107 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 108 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 109 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 110 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 111 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 112 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 113 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 114 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 115 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 116 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 117 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 118 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 119 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 120 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 121 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 122 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 123 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 124 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 125 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 126 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 127 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 128 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 129 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 130 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 131 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 132 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 133 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 134 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 135 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 136 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 137 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 138 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 139 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 140 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 141 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 142 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 143 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 144 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 145 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 146 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 147 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 148 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 149 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 150 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 151 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 152 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 153 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 154 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 155 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 156 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 157 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 158 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 159 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 160 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 161 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 162 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 163 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 164 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 165 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 166 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 167 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 168 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 169 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 170 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 171 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 172 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 173 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 174 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 175 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 176 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 177 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 178 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 179 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 180 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 181 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 182 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 183 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 184 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 185 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 186 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 187 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 188 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 189 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 190 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 191 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 192 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 193 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 194 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 195 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 196 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 197 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 198 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 199 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 200 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 201 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 202 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 203 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 204 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 205 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 206 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 207 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 208 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 209 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 210 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 211 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 212 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 213 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 214 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 215 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 216 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 217 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 218 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 219 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 220 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 221 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 222 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 223 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 224 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 225 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 226 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 227 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 228 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 229 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 230 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 231 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 232 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 233 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 234 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 235 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 236 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 237 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 238 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 239 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 240 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 241 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 242 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 243 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 244 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 245 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 246 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 247 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 248 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 249 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 250 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 251 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 252 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 253 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 254 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 255 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 256 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 257 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 258 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 259 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 260 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 261 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 262 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 263 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 264 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 265 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 266 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 267 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 268 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 269 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 270 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 271 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 272 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 273 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 274 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 275 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 276 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 277 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 278 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 279 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 280 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 281 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 282 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 283 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 284 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 285 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 286 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 287 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 288 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 289 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 290 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 291 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 292 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 293 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 294 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 295 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 296 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 297 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 298 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 299 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 300 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 301 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 302 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 303 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 304 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 305 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 306 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 307 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 308 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 309 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 310 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 311 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 312 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 313 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 314 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 315 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 316 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 317 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 318 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 319 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 320 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 321 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 322 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 323 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 324 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 325 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 326 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 327 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 328 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 329 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 330 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 331 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 332 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 333 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 334 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 335 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 336 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 337 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 338 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 339 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 340 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 341 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 342 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 343 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 344 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 345 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 346 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 347 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 348 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 349 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 350 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 351 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 352 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 353 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 354 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 355 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 356 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 357 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 358 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 359 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 360 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 361 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 362 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 363 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 364 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 365 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 366 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 367 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 368 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 369 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 370 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 371 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 372 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 373 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 374 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 375 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 376 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 377 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 378 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 379 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 380 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 381 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 382 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 383 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 384 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 385 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 386 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 387 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 388 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 389 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 390 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 391 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 392 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 393 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 394 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 395 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 396 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 397 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 398 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 399 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 400 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 401 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 402 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 403 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 404 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 405 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 406 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 407 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 408 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 409 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 410 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 411 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 412 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 413 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 414 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 415 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 416 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 417 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 418 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 419 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 420 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 421 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 422 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 423 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 424 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 425 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 426 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 427 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 428 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 429 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 430 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 431 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 432 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 433 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 434 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 435 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 436 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 437 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 438 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 439 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 440 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 441 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 442 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 443 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 444 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 445 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 446 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 447 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 448 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 449 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 450 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 451 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 452 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 453 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 454 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 455 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 456 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 457 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 458 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 459 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 460 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 461 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 462 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 463 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 464 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 465 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 466 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 467 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 468 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 469 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 470 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 471 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 472 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 473 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 474 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 475 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 476 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 477 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 478 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 479 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 480 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 481 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 482 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 483 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 484 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 485 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 486 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 487 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 488 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 489 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 490 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 491 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 492 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 493 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 494 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 495 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 496 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 497 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 498 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 499 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 500 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 501 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 502 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 503 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 504 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 505 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 506 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 507 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 508 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 509 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 510 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 511 */
  Os_Hal_UnhandledIRQ, /* External interrupt: 512 */
};

#define OS_STOP_SEC_INTVEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */




/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Lcfg.c
 *********************************************************************************************************************/

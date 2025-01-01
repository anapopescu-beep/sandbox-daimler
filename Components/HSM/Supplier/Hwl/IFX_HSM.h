// =============================================================================
// @file:    IFX_HSM.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
// @purpose: Register Definition File for Infineon HSM Device Series
//
// THE SOURCE CODE AND ITS RELATED DOCUMENTATION IS PROVIDED "AS IS". INFINEON
// TECHNOLOGIES MAKES NO OTHER WARRANTY OF ANY KIND,WHETHER EXPRESS,IMPLIED OR,
// STATUTORY AND DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
// SATISFACTORY QUALITY, NON INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
//
// THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. INFINEON TECHNOLOGIES
// RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER
// REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR
// THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.
//
// INFINEON TECHNOLOGIES SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
// CONSEQUENTIAL DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR
// ANY DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR
// PROFITS, DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE
// DAMAGES, LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION
// WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR
// PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON
// WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.
//
// (C)Copyright INFINEON TECHNOLOGIES All rights reserved
// =============================================================================

/*
 * Changes by Vector Informatik GmbH visjhi:
 * Change Cache and Bridge names to upper case labels (to be compatible with TC2)
 */

#ifndef __IFX_HSM_H__
#define __IFX_HSM_H__

#ifdef __cplusplus
extern "C" {
#endif

#define __HSM_PERIPHERAL_VERSION_MAIN   (0x2) /*!< [31:16] HSMxx Peripheral Library main version */
#define __HSM_PERIPHERAL_VERSION_SUB1   (0x0) /*!< [15:8]  HSMxx Peripheral Library sub1 version */
#define __HSM_PERIPHERAL_VERSION_SUB2   (0x0) /*!< [7:0]  HSMxx  Peripheral Library sub2 version */
#define __HSM_PERIPHERAL_VERSION       ((__HSM_PERIPHERAL_VERSION_MAIN << 16)\
                                                    | (__HSM_PERIPHERAL_VERSION_SUB1 << 8)\
                                                    | __HSM_PERIPHERAL_VERSION_SUB2)

/*
  * ==========================================================================
  * ---------- Interrupt Number Definition -----------------------------------
  * ==========================================================================
  */
typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn           = -14,      /*!< 2 Non Maskable Interrupt                         */
  HardFault_IRQn                = -13,      /*!< 3 Cortex-M3 Hard Fault Interrupt                 */
  MemoryManagement_IRQn         = -12,      /*!< 4 Cortex-M3 Memory Management Interrupt          */
  BusFault_IRQn                 = -11,      /*!< 5 Cortex-M3 Bus Fault Interrupt                  */
  UsageFault_IRQn               = -10,      /*!< 6 Cortex-M3 Usage Fault Interrupt                */
  SVCall_IRQn                   = -5,       /*!< 11 Cortex-M3 SV Call Interrupt                   */
  DebugMonitor_IRQn             = -4,       /*!< 12 Cortex-M3 Debug Monitor Interrupt             */
  PendSV_IRQn                   = -2,       /*!< 14 Cortex-M3 Pend SV Interrupt                   */
  SysTick_IRQn                  = -1,       /*!< 15 Cortex-M3 System Tick Interrupt               */

/******  HSM Specific Interrupt Numbers   *********************************************************/
  TIM0_IRQn                     = 0,        /*!< Timer 0 Interrupt                                */
  TIM1_IRQn                     = 1,        /*!< Timer 1 Interrupt                                */
  TRNG_IRQn                     = 2,        /*!< True Random Number Generator                     */
  Bridge_IRQn                   = 3,        /*!< HSM Bridge Service interrupt                     */
  BridgeErr_IRQn                = 4,        /*!< HSM Bridge Error interrupt                       */
  SensInt_IRQn                  = 5,        /*!< Sensor interrupt                                 */
  ExtInt_IRQn                   = 6,        /*!< External Peripheral interrupt                    */
  PKCRdy_IRQn                   = 8,        /*!< PKC Ready interrupt                              */
  PKCErr_IRQn                   = 9,        /*!< PKC Error interrupt                              */
} IRQn_Type;

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */



/* Configuration of the Cortex-M3 Processor and Core Peripherals */
#define __MPU_PRESENT             1         /*!< MPU present or not                                */
#define __CM3_REV                 0x0200    /*!< core revision                                     */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels           */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used      */

#include "core_cm3.h"                       /* Cortex-M3 processor and core peripherals            */
#include "system_hsm.h"                     /* HSM System                                          */


#include "peripherals/aes_hsm.h"
#include "peripherals/bridge_hsm.h"
#include "peripherals/cache_hsm.h"
#include "peripherals/debugextension_hsm.h"
#include "peripherals/hash_hsm.h"
#include "peripherals/pkc_hsm.h"
#include "peripherals/tim_hsm.h"
#include "peripherals/trng_hsm.h"
#include "peripherals/wdt_hsm.h"

// include of static data

/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
#define HSM_DebugExtension_BASE        (0xE0002000UL)
#define HSM_CACHE_BASE                 (0xE008A000UL)
#define HSM_AES_BASE                   (0xE8000000UL)
#define HSM_HASH_BASE                  (0xE8000400UL)
#define HSM_PKC_BASE                   (0xE8003C00UL)
#define HSM_TIM_BASE                   (0xEC000000UL)
#define HSM_WDT_BASE                   (0xEC000100UL)
#define HSM_TRNG_BASE                  (0xEC000200UL)
#define HSM_BRIDGE_BASE                (0xF0040000UL)

/*****************************************************************************/
/*                         Peripheral declaration                            */
/*****************************************************************************/
#define HSM_DebugExtension             ((HSM_DEBUGEXTENSION_TypeDef *) HSM_DebugExtension_BASE)
#define HSM_CACHE                      ((HSM_CACHE_TypeDef *) HSM_CACHE_BASE)
#define HSM_AES                        ((HSM_AES_TypeDef *) HSM_AES_BASE)
#define HSM_HASH                       ((HSM_HASH_TypeDef *) HSM_HASH_BASE)
#define HSM_PKC                        ((HSM_PKC_TypeDef *) HSM_PKC_BASE)
#define HSM_TIM                        ((HSM_TIM_TypeDef *) HSM_TIM_BASE)
#define HSM_WDT                        ((HSM_WDT_TypeDef *) HSM_WDT_BASE)
#define HSM_TRNG                       ((HSM_TRNG_TypeDef *) HSM_TRNG_BASE)
#define HSM_BRIDGE                     ((HSM_BRIDGE_TypeDef *) HSM_BRIDGE_BASE)

#ifdef __cplusplus
} // extern "C"
#endif

#endif  /* __IFX_HSM_H__ */

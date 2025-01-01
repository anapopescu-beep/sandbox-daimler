// =============================================================================
// @file:    wdt_hsm.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __WDT_HSM_H__
#define __WDT_HSM_H__

#define __IFX_WDT_VERSION_MAIN          (0x0)                               /* [31:24] MODULE main version   */
#define __IFX_WDT_VERSION_SUB           (0x0)                               /* [23:16] MODULE sub version    */
#define __IFX_WDT_VERSION_CONFIG        (0x0)                               /* [15:0]  MODULE config version */
#define __IFX_WDT_VERSION               ((__IFX_WDT_VERSION_MAIN << 24) | \
                                         (__IFX_WDT_VERSION_SUB << 16)  | \
                                          __IFX_WDT_VERSION_CONFIG)                  /* MODULE version number        */

/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/



/*------------- WDT Module      ----------------------------------------------*/
typedef struct
{
  __IO uint16_t WDT_CTRL                 ; // Watchdog Timer Control Register
       uint16_t RESERVED0[7]             ;
  __I  uint16_t WDT_VAL                  ; // Watchdog Timer Value Register
       uint16_t RESERVED1                ;
  __IO uint16_t WDT_RELOAD               ; // Watchdog Timer Reload Register
       uint16_t RESERVED2                ;
  __IO uint16_t WDT_SRV                  ; // Watchdog Service Register
       uint16_t RESERVED3                ;
  __IO uint16_t WDT_SRV_INI              ; // Watchdog Service Initialization Register
       uint16_t RESERVED4[17]            ;
  __IO uint16_t WDT_ACC_CTRL             ; // Watchdog Timer Access Control Register
} HSM_WDT_TypeDef;




/******************************************************************************/
/*                    Peripheral Registers_Bits_Definition                    */
/******************************************************************************/

/* Watchdog Timer Control Register Definitions */
#define WDT_CTRL_ACT_WDT_Pos           0                                        /* WDT_CTRL: ACT_WDT Position */
#define WDT_CTRL_ACT_WDT_Msk           (0x1ul << WDT_CTRL_ACT_WDT_Pos)          /* WDT_CTRL: ACT_WDT Mask */
#define WDT_CTRL_CLK_SEL_Pos           4                                        /* WDT_CTRL: CLK_SEL Position */
#define WDT_CTRL_CLK_SEL_Msk           (0x1ul << WDT_CTRL_CLK_SEL_Pos)          /* WDT_CTRL: CLK_SEL Mask */
#define WDT_CTRL_INC_SRV_Pos           8                                        /* WDT_CTRL: INC_SRV Position */
#define WDT_CTRL_INC_SRV_Msk           (0x1ul << WDT_CTRL_INC_SRV_Pos)          /* WDT_CTRL: INC_SRV Mask */
#define WDT_CTRL_PERIOD_Pos            12                                       /* WDT_CTRL: PERIOD Position */
#define WDT_CTRL_PERIOD_Msk            (0xful << WDT_CTRL_PERIOD_Pos)           /* WDT_CTRL: PERIOD Mask */
/* Watchdog Service Register Definitions */
#define WDT_SRV_SRV_CNT_Pos            0                                        /* WDT_SRV: SRV_CNT Position */
#define WDT_SRV_SRV_CNT_Msk            (0xffful << WDT_SRV_SRV_CNT_Pos)         /* WDT_SRV: SRV_CNT Mask */
/* Watchdog Service Initialization Register Definitions */
#define WDT_SRV_INI_SRV_CNT_INI_Pos    0                                        /* WDT_SRV_INI: SRV_CNT_INI Position */
#define WDT_SRV_INI_SRV_CNT_INI_Msk    (0xffful << WDT_SRV_INI_SRV_CNT_INI_Pos) /* WDT_SRV_INI: SRV_CNT_INI Mask */
/* Watchdog Timer Access Control Register Definitions */
#define WDT_ACC_CTRL_CTRL_ACC_Pos      0                                        /* WDT_ACC_CTRL: CTRL_ACC Position */
#define WDT_ACC_CTRL_CTRL_ACC_Msk      (0x1ul << WDT_ACC_CTRL_CTRL_ACC_Pos)     /* WDT_ACC_CTRL: CTRL_ACC Mask */
#define WDT_ACC_CTRL_DATA_ACC_Pos      1                                        /* WDT_ACC_CTRL: DATA_ACC Position */
#define WDT_ACC_CTRL_DATA_ACC_Msk      (0x1ul << WDT_ACC_CTRL_DATA_ACC_Pos)     /* WDT_ACC_CTRL: DATA_ACC Mask */

/******************************************************************************/
/*                     Peripheral Registers_Bits_Constant                     */
/******************************************************************************/

#define WDT_CTRL_ACT_WDT_WTS                     0x00                           /* Active Watchdog Timer */
#define WDT_CTRL_ACT_WDT_WTR                     0x01                           /* Active Watchdog Timer */
#define WDT_CTRL_CLK_SEL_WDTCLK0                 0x00                           /* Clock Select */
#define WDT_CTRL_CLK_SEL_WDTCLK1                 0x01                           /* Clock Select */
#define WDT_CTRL_INC_SRV_ISN                     0x00                           /* Increment Service */
#define WDT_CTRL_INC_SRV_IS1                     0x01                           /* Increment Service */
#define WDT_ACC_CTRL_CTRL_ACC_PRIV               0x00                           /* Control Access */
#define WDT_ACC_CTRL_CTRL_ACC_USER               0x01                           /* Control Access */
#define WDT_ACC_CTRL_DATA_ACC_PRIV               0x00                           /* Data Access */
#define WDT_ACC_CTRL_DATA_ACC_USER               0x01                           /* Data Access */


#endif  /* __WDT_HSM_H__ */

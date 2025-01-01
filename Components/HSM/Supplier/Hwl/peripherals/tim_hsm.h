// =============================================================================
// @file:    tim_hsm.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __TIM_HSM_H__
#define __TIM_HSM_H__

#define __IFX_TIM_VERSION_MAIN          (0x0)                               /* [31:24] MODULE main version   */
#define __IFX_TIM_VERSION_SUB           (0x0)                               /* [23:16] MODULE sub version    */
#define __IFX_TIM_VERSION_CONFIG        (0x0)                               /* [15:0]  MODULE config version */
#define __IFX_TIM_VERSION               ((__IFX_TIM_VERSION_MAIN << 24) | \
                                         (__IFX_TIM_VERSION_SUB << 16)  | \
                                          __IFX_TIM_VERSION_CONFIG)                  /* MODULE version number        */

/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/



/*------------- TIM Module      ----------------------------------------------*/
typedef struct
{
  __IO uint16_t TIM_CTRL                 ; // Timer Control Register
       uint16_t RESERVED0                ;
  __IO uint16_t TIM_CFG                  ; // Timer Configuration Register
       uint16_t RESERVED1[5]             ;
  __I  uint16_t TIM_CNT0                 ; // Timer Counter 0 Register
       uint16_t RESERVED2                ;
  __I  uint16_t TIM_CNT1                 ; // Timer Counter 1 Register
       uint16_t RESERVED3[5]             ;
  __IO uint16_t TIM_RLD0                 ; // Timer Reload 0 Register
       uint16_t RESERVED4                ;
  __IO uint16_t TIM_RLD1                 ; // Timer Reload 1 Register
} HSM_TIM_TypeDef;




/******************************************************************************/
/*                    Peripheral Registers_Bits_Definition                    */
/******************************************************************************/

/* Timer Control Register Definitions */
#define TIM_CTRL_TR0_Pos               0                                        /* TIM_CTRL: TR0 Position */
#define TIM_CTRL_TR0_Msk               (0x1ul << TIM_CTRL_TR0_Pos)              /* TIM_CTRL: TR0 Mask */
#define TIM_CTRL_TF0_Pos               1                                        /* TIM_CTRL: TF0 Position */
#define TIM_CTRL_TF0_Msk               (0x1ul << TIM_CTRL_TF0_Pos)              /* TIM_CTRL: TF0 Mask */
#define TIM_CTRL_UNLOCK_TF0_Pos        2                                        /* TIM_CTRL: UNLOCK_TF0 Position */
#define TIM_CTRL_UNLOCK_TF0_Msk        (0x1ul << TIM_CTRL_UNLOCK_TF0_Pos)       /* TIM_CTRL: UNLOCK_TF0 Mask */
#define TIM_CTRL_TSRC0_Pos             3                                        /* TIM_CTRL: TSRC0 Position */
#define TIM_CTRL_TSRC0_Msk             (0x3ul << TIM_CTRL_TSRC0_Pos)            /* TIM_CTRL: TSRC0 Mask */
#define TIM_CTRL_TR1_Pos               8                                        /* TIM_CTRL: TR1 Position */
#define TIM_CTRL_TR1_Msk               (0x1ul << TIM_CTRL_TR1_Pos)              /* TIM_CTRL: TR1 Mask */
#define TIM_CTRL_TF1_Pos               9                                        /* TIM_CTRL: TF1 Position */
#define TIM_CTRL_TF1_Msk               (0x1ul << TIM_CTRL_TF1_Pos)              /* TIM_CTRL: TF1 Mask */
#define TIM_CTRL_UNLOCK_TF1_Pos        10                                       /* TIM_CTRL: UNLOCK_TF1 Position */
#define TIM_CTRL_UNLOCK_TF1_Msk        (0x1ul << TIM_CTRL_UNLOCK_TF1_Pos)       /* TIM_CTRL: UNLOCK_TF1 Mask */
#define TIM_CTRL_TSRC1_Pos             11                                       /* TIM_CTRL: TSRC1 Position */
#define TIM_CTRL_TSRC1_Msk             (0x3ul << TIM_CTRL_TSRC1_Pos)            /* TIM_CTRL: TSRC1 Mask */
/* Timer Configuration Register Definitions */
#define TIM_CFG_TPR0_Pos               0                                        /* TIM_CFG: TPR0 Position */
#define TIM_CFG_TPR0_Msk               (0x3ul << TIM_CFG_TPR0_Pos)              /* TIM_CFG: TPR0 Mask */
#define TIM_CFG_TPR_DIS0_Pos           3                                        /* TIM_CFG: TPR_DIS0 Position */
#define TIM_CFG_TPR_DIS0_Msk           (0x1ul << TIM_CFG_TPR_DIS0_Pos)          /* TIM_CFG: TPR_DIS0 Mask */
#define TIM_CFG_TPR1_Pos               8                                        /* TIM_CFG: TPR1 Position */
#define TIM_CFG_TPR1_Msk               (0x3ul << TIM_CFG_TPR1_Pos)              /* TIM_CFG: TPR1 Mask */
#define TIM_CFG_TPR_DIS1_Pos           11                                       /* TIM_CFG: TPR_DIS1 Position */
#define TIM_CFG_TPR_DIS1_Msk           (0x1ul << TIM_CFG_TPR_DIS1_Pos)          /* TIM_CFG: TPR_DIS1 Mask */

/******************************************************************************/
/*                     Peripheral Registers_Bits_Constant                     */
/******************************************************************************/

#define TIM_CTRL_TR0_T0S                         0x00                           /* Timer 0 Run */
#define TIM_CTRL_TR0_T0R                         0x01                           /* Timer 0 Run */
#define TIM_CTRL_TF0_T0NO                        0x00                           /* Timer 0 Overflow Flag */
#define TIM_CTRL_TF0_T0OV                        0x01                           /* Timer 0 Overflow Flag */
#define TIM_CTRL_UNLOCK_TF0_T0NC                 0x00                           /* Unlock TF0 */
#define TIM_CTRL_UNLOCK_TF0_T0WE                 0x01                           /* Unlock TF0 */
#define TIM_CTRL_TSRC0_T0CLK0                    0x00                           /* Timer 0 Clock Source */
#define TIM_CTRL_TSRC0_T0CLK1                    0x01                           /* Timer 0 Clock Source */
#define TIM_CTRL_TSRC0_T0CLK2                    0x02                           /* Timer 0 Clock Source */
#define TIM_CTRL_TSRC0_T0CLK3                    0x03                           /* Timer 0 Clock Source */
#define TIM_CTRL_TR1_T1S                         0x00                           /* Timer 1 Run */
#define TIM_CTRL_TR1_T1R                         0x01                           /* Timer 1 Run */
#define TIM_CTRL_TF1_T1NO                        0x00                           /* Timer 1 Overflow Flag */
#define TIM_CTRL_TF1_T1OV                        0x01                           /* Timer 1 Overflow Flag */
#define TIM_CTRL_UNLOCK_TF1_T1NC                 0x00                           /* Unlock TF1 */
#define TIM_CTRL_UNLOCK_TF1_T1WE                 0x01                           /* Unlock TF1 */
#define TIM_CTRL_TSRC1_T1CLK0                    0x00                           /* Timer 1 Clock Source */
#define TIM_CTRL_TSRC1_T1CLK1                    0x01                           /* Timer 1 Clock Source */
#define TIM_CTRL_TSRC1_T1CLK2                    0x02                           /* Timer 1 Clock Source */
#define TIM_CTRL_TSRC1_T1CLK3                    0x03                           /* Timer 1 Clock Source */
#define TIM_CFG_TPR_DIS0_T0PENB                  0x00                           /* Timer 0 Prescaler Disable */
#define TIM_CFG_TPR_DIS0_T0PDIS                  0x01                           /* Timer 0 Prescaler Disable */
#define TIM_CFG_TPR_DIS1_T1PENB                  0x00                           /* Timer 1 Prescaler Disable */
#define TIM_CFG_TPR_DIS1_T1PDIS                  0x01                           /* Timer 1 Prescaler Disable */

/******************************************************************************/
/*                         Additional Definitions                      */
/******************************************************************************/

#define TIM_CTRL_TSRC0_INT_CLK                   (0x0ul << TIM_CTRL_TSRC0_Pos)  // 0x0000
#define TIM_CTRL_TSRC0_EXT_CLK                   (0x1ul << TIM_CTRL_TSRC0_Pos)  // 0x0008
#define TIM_CTRL_TSRC0_1MHZ                      (0x2ul << TIM_CTRL_TSRC0_Pos)  // 0x0010

#define TIM_CTRL_TSRC1_INT_CLK                   (0x0ul << TIM_CTRL_TSRC1_Pos)  // 0x0000
#define TIM_CTRL_TSRC1_EXT_CLK                   (0x1ul << TIM_CTRL_TSRC1_Pos)  // 0x0800
#define TIM_CTRL_TSRC1_1MHZ                      (0x2ul << TIM_CTRL_TSRC1_Pos)  // 0x1000

#define TIM_CFG_TPR0_4                           (0x0ul << TIM_CFG_TPR0_Pos)    // 0x0000
#define TIM_CFG_TPR0_16                          (0x1ul << TIM_CFG_TPR0_Pos)    // 0x0001
#define TIM_CFG_TPR0_64                          (0x2ul << TIM_CFG_TPR0_Pos)    // 0x0002
#define TIM_CFG_TPR0_512                         (0x3ul << TIM_CFG_TPR0_Pos)    // 0x0003

#define TIM_CFG_TRX0_OV                          (0x0ul << TIM_CFG_TRX0_Pos)    // 0x0000
#define TIM_CFG_TRX0_OV_UART                     (0x1ul << TIM_CFG_TRX0_Pos)    // 0x0004

#define TIM_CFG_TPR1_4                           (0x0ul << TIM_CFG_TPR1_Pos)    // 0x0000
#define TIM_CFG_TPR1_16                          (0x1ul << TIM_CFG_TPR1_Pos)    // 0x0100
#define TIM_CFG_TPR1_64                          (0x2ul << TIM_CFG_TPR1_Pos)    // 0x0200
#define TIM_CFG_TPR1_512                         (0x3ul << TIM_CFG_TPR1_Pos)    // 0x0300

#define TIM_CFG_TRX1_OV                          (0x0ul << TIM_CFG_TRX1_Pos)    // 0x0000
#define TIM_CFG_TRX1_OV_UART                     (0x1ul << TIM_CFG_TRX1_Pos)    // 0x0400


#endif  /* __TIM_HSM_H__ */

// =============================================================================
// @file:    pkc_hsm.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __PKC_HSM_H__
#define __PKC_HSM_H__

#define __IFX_PKC_VERSION_MAIN          (0x0)                               /* [31:24] MODULE main version   */
#define __IFX_PKC_VERSION_SUB           (0x0)                               /* [23:16] MODULE sub version    */
#define __IFX_PKC_VERSION_CONFIG        (0x0)                               /* [15:0]  MODULE config version */
#define __IFX_PKC_VERSION               ((__IFX_PKC_VERSION_MAIN << 24) | \
                                         (__IFX_PKC_VERSION_SUB << 16)  | \
                                          __IFX_PKC_VERSION_CONFIG)                  /* MODULE version number        */

/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/



/*------------- PKC Module      ----------------------------------------------*/
typedef struct
{
  __IO uint32_t PKC_CONFIG               ; // PKC Configuration Register
  __IO uint32_t PKC_CMD                  ; // PKC Command Register
  __IO uint32_t PKC_CTRL                 ; // PKC Control Register
  __I  uint32_t PKC_STATUS               ; // PKC Status Register
       uint32_t RESERVED0[252]           ;
  __IO uint32_t PKC_SCM_R0[8]            ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R1[8]            ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R2[8]            ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R3[8]            ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R4[8]            ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R5[8]            ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R6[8]            ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R7[8]            ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R8[8]            ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R9[8]            ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R10[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R11[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R12[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R13[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R14[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R15[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R16[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R17[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R18[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R19[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R20[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R21[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R22[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R23[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R24[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R25[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R26[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R27[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R28[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R29[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R30[8]           ; // Shared Crypto Memory Register 0
  __IO uint32_t PKC_SCM_R31[8]           ; // Shared Crypto Memory Register 0
} HSM_PKC_TypeDef;




/******************************************************************************/
/*                    Peripheral Registers_Bits_Definition                    */
/******************************************************************************/

/* PKC Configuration Register Definitions */
#define PKC_CONFIG_OPPTRA_Pos          0                                        /* PKC_CONFIG: OPPTRA Position */
#define PKC_CONFIG_OPPTRA_Msk          (0x1ful << PKC_CONFIG_OPPTRA_Pos)        /* PKC_CONFIG: OPPTRA Mask */
#define PKC_CONFIG_OPPTRB_Pos          8                                        /* PKC_CONFIG: OPPTRB Position */
#define PKC_CONFIG_OPPTRB_Msk          (0x1ful << PKC_CONFIG_OPPTRB_Pos)        /* PKC_CONFIG: OPPTRB Mask */
#define PKC_CONFIG_OPPTRC_Pos          16                                       /* PKC_CONFIG: OPPTRC Position */
#define PKC_CONFIG_OPPTRC_Msk          (0x1ful << PKC_CONFIG_OPPTRC_Pos)        /* PKC_CONFIG: OPPTRC Mask */
/* PKC Command Register Definitions */
#define PKC_CMD_TYPE_Pos               0                                        /* PKC_CMD: TYPE Position */
#define PKC_CMD_TYPE_Msk               (0x7ful << PKC_CMD_TYPE_Pos)             /* PKC_CMD: TYPE Mask */
#define PKC_CMD_FIELD_Pos              7                                        /* PKC_CMD: FIELD Position */
#define PKC_CMD_FIELD_Msk              (0x1ul << PKC_CMD_FIELD_Pos)             /* PKC_CMD: FIELD Mask */
#define PKC_CMD_SIZE_Pos               8                                        /* PKC_CMD: SIZE Position */
#define PKC_CMD_SIZE_Msk               (0xfful << PKC_CMD_SIZE_Pos)             /* PKC_CMD: SIZE Mask */
#define PKC_CMD_SIGNA_Pos              29                                       /* PKC_CMD: SIGNA Position */
#define PKC_CMD_SIGNA_Msk              (0x1ul << PKC_CMD_SIGNA_Pos)             /* PKC_CMD: SIGNA Mask */
#define PKC_CMD_SIGNB_Pos              30                                       /* PKC_CMD: SIGNB Position */
#define PKC_CMD_SIGNB_Msk              (0x1ul << PKC_CMD_SIGNB_Pos)             /* PKC_CMD: SIGNB Mask */
#define PKC_CMD_CALCR2_Pos             31                                       /* PKC_CMD: CALCR2 Position */
#define PKC_CMD_CALCR2_Msk             (0x1ul << PKC_CMD_CALCR2_Pos)            /* PKC_CMD: CALCR2 Mask */
/* PKC Control Register Definitions */
#define PKC_CTRL_START_Pos             0                                        /* PKC_CTRL: START Position */
#define PKC_CTRL_START_Msk             (0x1ul << PKC_CTRL_START_Pos)            /* PKC_CTRL: START Mask */
/* PKC Status Register Definitions */
#define PKC_STATUS_FLADD_Pos           0                                        /* PKC_STATUS: FLADD Position */
#define PKC_STATUS_FLADD_Msk           (0xful << PKC_STATUS_FLADD_Pos)          /* PKC_STATUS: FLADD Mask */
#define PKC_STATUS_INFTY_Pos           5                                        /* PKC_STATUS: INFTY Position */
#define PKC_STATUS_INFTY_Msk           (0x1ul << PKC_STATUS_INFTY_Pos)          /* PKC_STATUS: INFTY Mask */
#define PKC_STATUS_XYNV_Pos            6                                        /* PKC_STATUS: XYNV Position */
#define PKC_STATUS_XYNV_Msk            (0x1ul << PKC_STATUS_XYNV_Pos)           /* PKC_STATUS: XYNV Mask */
#define PKC_STATUS_NNV_Pos             7                                        /* PKC_STATUS: NNV Position */
#define PKC_STATUS_NNV_Msk             (0x1ul << PKC_STATUS_NNV_Pos)            /* PKC_STATUS: NNV Mask */
#define PKC_STATUS_SIGNV_Pos           9                                        /* PKC_STATUS: SIGNV Position */
#define PKC_STATUS_SIGNV_Msk           (0x1ul << PKC_STATUS_SIGNV_Pos)          /* PKC_STATUS: SIGNV Mask */
#define PKC_STATUS_ABNV_Pos            10                                       /* PKC_STATUS: ABNV Position */
#define PKC_STATUS_ABNV_Msk            (0x1ul << PKC_STATUS_ABNV_Pos)           /* PKC_STATUS: ABNV Mask */
#define PKC_STATUS_NOTINV_Pos          11                                       /* PKC_STATUS: NOTINV Position */
#define PKC_STATUS_NOTINV_Msk          (0x1ul << PKC_STATUS_NOTINV_Pos)         /* PKC_STATUS: NOTINV Mask */
#define PKC_STATUS_BUSY_Pos            16                                       /* PKC_STATUS: BUSY Position */
#define PKC_STATUS_BUSY_Msk            (0x1ul << PKC_STATUS_BUSY_Pos)           /* PKC_STATUS: BUSY Mask */

/******************************************************************************/
/*                     Peripheral Registers_Bits_Constant                     */
/******************************************************************************/

#define PKC_CMD_TYPE_ADDN                        0x01                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_SUBN                        0x02                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_MULTN                       0x03                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_RED                         0x04                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_DIVN                        0x05                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_INV                         0x06                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_MULT                        0x08                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_INV2                        0x09                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_RED2                        0x0A                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_EXP                         0x10                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_PDBL                        0x20                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_PADD                        0x21                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_SMULT                       0x22                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_CHECKAB                     0x23                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_CHECKN                      0x24                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_CHECKPXY                    0x25                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_SMULT25519                  0x28                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_XRECOVER                    0x29                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_SMULTED25519                0x2A                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_CHECKVALID                  0x2B                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_ECDSASIG                    0x30                           /* Elliptic Curve Operations: */
#define PKC_CMD_TYPE_ECDSAVER                    0x31                           /* Elliptic Curve Operations: */


#endif  /* __PKC_HSM_H__ */

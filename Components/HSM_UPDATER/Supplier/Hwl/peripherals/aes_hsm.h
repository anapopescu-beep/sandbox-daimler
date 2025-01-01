// =============================================================================
// @file:    aes_hsm.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __AES_HSM_H__
#define __AES_HSM_H__

#define __IFX_AES_VERSION_MAIN          (0x0)                               /* [31:24] MODULE main version   */
#define __IFX_AES_VERSION_SUB           (0x0)                               /* [23:16] MODULE sub version    */
#define __IFX_AES_VERSION_CONFIG        (0x0)                               /* [15:0]  MODULE config version */
#define __IFX_AES_VERSION               ((__IFX_AES_VERSION_MAIN << 24) | \
                                         (__IFX_AES_VERSION_SUB << 16)  | \
                                          __IFX_AES_VERSION_CONFIG)                  /* MODULE version number        */

/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/



/*------------- AES Module      ----------------------------------------------*/
typedef struct
{

  __IO uint32_t AESIN0                   ; // AES INPUT register 0
  __IO uint32_t AESIN1                   ; // AES INPUT register 1
  __IO uint32_t AESIN2                   ; // AES INPUT register 2
  __IO uint32_t AESIN3                   ; // AES INPUT register 3
  __IO uint32_t AESCTRL                  ; // AES Control Register
  __I  uint32_t AESSTAT                  ; // AES Status Register
       uint32_t RESERVED0[2]             ;
  __I  uint32_t AESOUT0                  ; // AES OUTPUT register 0
  __I  uint32_t AESOUT1                  ; // AES OUTPUT register 1
  __I  uint32_t AESOUT2                  ; // AES OUTPUT register 2
  __I  uint32_t AESOUT3                  ; // AES OUTPUT register 3
  __I  uint32_t AESOUTSAVE0              ; // AES OUTPUT save register 0
  __I  uint32_t AESOUTSAVE1              ; // AES OUTPUT save register 1
  __I  uint32_t AESOUTSAVE2              ; // AES OUTPUT save register 2
  __I  uint32_t AESOUTSAVE3              ; // AES OUTPUT save register 3
} HSM_AES_TypeDef;




/******************************************************************************/
/*                    Peripheral Registers_Bits_Definition                    */
/******************************************************************************/

/* AES INPUT register 0 Definitions */
#define AESIN0_IN0_Pos                 0                                        /* AESIN0: IN0 Position */
#define AESIN0_IN0_Msk                 (0xfful << AESIN0_IN0_Pos)               /* AESIN0: IN0 Mask */
#define AESIN0_IN1_Pos                 8                                        /* AESIN0: IN1 Position */
#define AESIN0_IN1_Msk                 (0xfful << AESIN0_IN1_Pos)               /* AESIN0: IN1 Mask */
#define AESIN0_IN2_Pos                 16                                       /* AESIN0: IN2 Position */
#define AESIN0_IN2_Msk                 (0xfful << AESIN0_IN2_Pos)               /* AESIN0: IN2 Mask */
#define AESIN0_IN3_Pos                 24                                       /* AESIN0: IN3 Position */
#define AESIN0_IN3_Msk                 (0xfful << AESIN0_IN3_Pos)               /* AESIN0: IN3 Mask */
/* AES INPUT register 1 Definitions */
#define AESIN1_IN4_Pos                 0                                        /* AESIN1: IN4 Position */
#define AESIN1_IN4_Msk                 (0xfful << AESIN1_IN4_Pos)               /* AESIN1: IN4 Mask */
#define AESIN1_IN5_Pos                 8                                        /* AESIN1: IN5 Position */
#define AESIN1_IN5_Msk                 (0xfful << AESIN1_IN5_Pos)               /* AESIN1: IN5 Mask */
#define AESIN1_IN6_Pos                 16                                       /* AESIN1: IN6 Position */
#define AESIN1_IN6_Msk                 (0xfful << AESIN1_IN6_Pos)               /* AESIN1: IN6 Mask */
#define AESIN1_IN7_Pos                 24                                       /* AESIN1: IN7 Position */
#define AESIN1_IN7_Msk                 (0xfful << AESIN1_IN7_Pos)               /* AESIN1: IN7 Mask */
/* AES INPUT register 2 Definitions */
#define AESIN2_IN8_Pos                 0                                        /* AESIN2: IN8 Position */
#define AESIN2_IN8_Msk                 (0xfful << AESIN2_IN8_Pos)               /* AESIN2: IN8 Mask */
#define AESIN2_IN9_Pos                 8                                        /* AESIN2: IN9 Position */
#define AESIN2_IN9_Msk                 (0xfful << AESIN2_IN9_Pos)               /* AESIN2: IN9 Mask */
#define AESIN2_IN10_Pos                16                                       /* AESIN2: IN10 Position */
#define AESIN2_IN10_Msk                (0xfful << AESIN2_IN10_Pos)              /* AESIN2: IN10 Mask */
#define AESIN2_IN11_Pos                24                                       /* AESIN2: IN11 Position */
#define AESIN2_IN11_Msk                (0xfful << AESIN2_IN11_Pos)              /* AESIN2: IN11 Mask */
/* AES INPUT register 3 Definitions */
#define AESIN3_IN12_Pos                0                                        /* AESIN3: IN12 Position */
#define AESIN3_IN12_Msk                (0xfful << AESIN3_IN12_Pos)              /* AESIN3: IN12 Mask */
#define AESIN3_IN13_Pos                8                                        /* AESIN3: IN13 Position */
#define AESIN3_IN13_Msk                (0xfful << AESIN3_IN13_Pos)              /* AESIN3: IN13 Mask */
#define AESIN3_IN14_Pos                16                                       /* AESIN3: IN14 Position */
#define AESIN3_IN14_Msk                (0xfful << AESIN3_IN14_Pos)              /* AESIN3: IN14 Mask */
#define AESIN3_IN15_Pos                24                                       /* AESIN3: IN15 Position */
#define AESIN3_IN15_Msk                (0xfful << AESIN3_IN15_Pos)              /* AESIN3: IN15 Mask */
/* AES Control Register Definitions */
#define AESCTRL_CVNR_Pos               0                                        /* AESCTRL: CVNR Position */
#define AESCTRL_CVNR_Msk               (0x7ul << AESCTRL_CVNR_Pos)              /* AESCTRL: CVNR Mask */
#define AESCTRL_KEYNR_Pos              4                                        /* AESCTRL: KEYNR Position */
#define AESCTRL_KEYNR_Msk              (0x1ful << AESCTRL_KEYNR_Pos)            /* AESCTRL: KEYNR Mask */
#define AESCTRL_OPC_Pos                12                                       /* AESCTRL: OPC Position */
#define AESCTRL_OPC_Msk                (0x1ful << AESCTRL_OPC_Pos)              /* AESCTRL: OPC Mask */
/* AES Status Register Definitions */
#define AESSTAT_BSY_Pos                0                                        /* AESSTAT: BSY Position */
#define AESSTAT_BSY_Msk                (0x1ul << AESSTAT_BSY_Pos)               /* AESSTAT: BSY Mask */
#define AESSTAT_LOCK0_Pos              1                                        /* AESSTAT: LOCK0 Position */
#define AESSTAT_LOCK0_Msk              (0x1ul << AESSTAT_LOCK0_Pos)             /* AESSTAT: LOCK0 Mask */
#define AESSTAT_LOCK1_Pos              2                                        /* AESSTAT: LOCK1 Position */
#define AESSTAT_LOCK1_Msk              (0x1ul << AESSTAT_LOCK1_Pos)             /* AESSTAT: LOCK1 Mask */
/* AES OUTPUT register 0 Definitions */
#define AESOUT0_OUT0_Pos               0                                        /* AESOUT0: OUT0 Position */
#define AESOUT0_OUT0_Msk               (0xfful << AESOUT0_OUT0_Pos)             /* AESOUT0: OUT0 Mask */
#define AESOUT0_OUT1_Pos               8                                        /* AESOUT0: OUT1 Position */
#define AESOUT0_OUT1_Msk               (0xfful << AESOUT0_OUT1_Pos)             /* AESOUT0: OUT1 Mask */
#define AESOUT0_OUT2_Pos               16                                       /* AESOUT0: OUT2 Position */
#define AESOUT0_OUT2_Msk               (0xfful << AESOUT0_OUT2_Pos)             /* AESOUT0: OUT2 Mask */
#define AESOUT0_OUT3_Pos               24                                       /* AESOUT0: OUT3 Position */
#define AESOUT0_OUT3_Msk               (0xfful << AESOUT0_OUT3_Pos)             /* AESOUT0: OUT3 Mask */
/* AES OUTPUT register 1 Definitions */
#define AESOUT1_OUT4_Pos               0                                        /* AESOUT1: OUT4 Position */
#define AESOUT1_OUT4_Msk               (0xfful << AESOUT1_OUT4_Pos)             /* AESOUT1: OUT4 Mask */
#define AESOUT1_OUT5_Pos               8                                        /* AESOUT1: OUT5 Position */
#define AESOUT1_OUT5_Msk               (0xfful << AESOUT1_OUT5_Pos)             /* AESOUT1: OUT5 Mask */
#define AESOUT1_OUT6_Pos               16                                       /* AESOUT1: OUT6 Position */
#define AESOUT1_OUT6_Msk               (0xfful << AESOUT1_OUT6_Pos)             /* AESOUT1: OUT6 Mask */
#define AESOUT1_OUT7_Pos               24                                       /* AESOUT1: OUT7 Position */
#define AESOUT1_OUT7_Msk               (0xfful << AESOUT1_OUT7_Pos)             /* AESOUT1: OUT7 Mask */
/* AES OUTPUT register 2 Definitions */
#define AESOUT2_OUT8_Pos               0                                        /* AESOUT2: OUT8 Position */
#define AESOUT2_OUT8_Msk               (0xfful << AESOUT2_OUT8_Pos)             /* AESOUT2: OUT8 Mask */
#define AESOUT2_OUT9_Pos               8                                        /* AESOUT2: OUT9 Position */
#define AESOUT2_OUT9_Msk               (0xfful << AESOUT2_OUT9_Pos)             /* AESOUT2: OUT9 Mask */
#define AESOUT2_OUT10_Pos              16                                       /* AESOUT2: OUT10 Position */
#define AESOUT2_OUT10_Msk              (0xfful << AESOUT2_OUT10_Pos)            /* AESOUT2: OUT10 Mask */
#define AESOUT2_OUT11_Pos              24                                       /* AESOUT2: OUT11 Position */
#define AESOUT2_OUT11_Msk              (0xfful << AESOUT2_OUT11_Pos)            /* AESOUT2: OUT11 Mask */
/* AES OUTPUT register 3 Definitions */
#define AESOUT3_OUT12_Pos              0                                        /* AESOUT3: OUT12 Position */
#define AESOUT3_OUT12_Msk              (0xfful << AESOUT3_OUT12_Pos)            /* AESOUT3: OUT12 Mask */
#define AESOUT3_OUT13_Pos              8                                        /* AESOUT3: OUT13 Position */
#define AESOUT3_OUT13_Msk              (0xfful << AESOUT3_OUT13_Pos)            /* AESOUT3: OUT13 Mask */
#define AESOUT3_OUT14_Pos              16                                       /* AESOUT3: OUT14 Position */
#define AESOUT3_OUT14_Msk              (0xfful << AESOUT3_OUT14_Pos)            /* AESOUT3: OUT14 Mask */
#define AESOUT3_OUT15_Pos              24                                       /* AESOUT3: OUT15 Position */
#define AESOUT3_OUT15_Msk              (0xfful << AESOUT3_OUT15_Pos)            /* AESOUT3: OUT15 Mask */
/* AES OUTPUT save register 0 Definitions */
#define AESOUTSAVE0_OUTSAVE0_Pos       0                                        /* AESOUTSAVE0: OUTSAVE0 Position */
#define AESOUTSAVE0_OUTSAVE0_Msk       (0xfful << AESOUTSAVE0_OUTSAVE0_Pos)     /* AESOUTSAVE0: OUTSAVE0 Mask */
#define AESOUTSAVE0_OUTSAVE1_Pos       8                                        /* AESOUTSAVE0: OUTSAVE1 Position */
#define AESOUTSAVE0_OUTSAVE1_Msk       (0xfful << AESOUTSAVE0_OUTSAVE1_Pos)     /* AESOUTSAVE0: OUTSAVE1 Mask */
#define AESOUTSAVE0_OUTSAVE2_Pos       16                                       /* AESOUTSAVE0: OUTSAVE2 Position */
#define AESOUTSAVE0_OUTSAVE2_Msk       (0xfful << AESOUTSAVE0_OUTSAVE2_Pos)     /* AESOUTSAVE0: OUTSAVE2 Mask */
#define AESOUTSAVE0_OUTSAVE3_Pos       24                                       /* AESOUTSAVE0: OUTSAVE3 Position */
#define AESOUTSAVE0_OUTSAVE3_Msk       (0xfful << AESOUTSAVE0_OUTSAVE3_Pos)     /* AESOUTSAVE0: OUTSAVE3 Mask */
/* AES OUTPUT save register 1 Definitions */
#define AESOUTSAVE1_OUTSAVE4_Pos       0                                        /* AESOUTSAVE1: OUTSAVE4 Position */
#define AESOUTSAVE1_OUTSAVE4_Msk       (0xfful << AESOUTSAVE1_OUTSAVE4_Pos)     /* AESOUTSAVE1: OUTSAVE4 Mask */
#define AESOUTSAVE1_OUTSAVE5_Pos       8                                        /* AESOUTSAVE1: OUTSAVE5 Position */
#define AESOUTSAVE1_OUTSAVE5_Msk       (0xfful << AESOUTSAVE1_OUTSAVE5_Pos)     /* AESOUTSAVE1: OUTSAVE5 Mask */
#define AESOUTSAVE1_OUTSAVE6_Pos       16                                       /* AESOUTSAVE1: OUTSAVE6 Position */
#define AESOUTSAVE1_OUTSAVE6_Msk       (0xfful << AESOUTSAVE1_OUTSAVE6_Pos)     /* AESOUTSAVE1: OUTSAVE6 Mask */
#define AESOUTSAVE1_OUTSAVE7_Pos       24                                       /* AESOUTSAVE1: OUTSAVE7 Position */
#define AESOUTSAVE1_OUTSAVE7_Msk       (0xfful << AESOUTSAVE1_OUTSAVE7_Pos)     /* AESOUTSAVE1: OUTSAVE7 Mask */
/* AES OUTPUT save register 2 Definitions */
#define AESOUTSAVE2_OUTSAVE8_Pos       0                                        /* AESOUTSAVE2: OUTSAVE8 Position */
#define AESOUTSAVE2_OUTSAVE8_Msk       (0xfful << AESOUTSAVE2_OUTSAVE8_Pos)     /* AESOUTSAVE2: OUTSAVE8 Mask */
#define AESOUTSAVE2_OUTSAVE9_Pos       8                                        /* AESOUTSAVE2: OUTSAVE9 Position */
#define AESOUTSAVE2_OUTSAVE9_Msk       (0xfful << AESOUTSAVE2_OUTSAVE9_Pos)     /* AESOUTSAVE2: OUTSAVE9 Mask */
#define AESOUTSAVE2_OUTSAVE10_Pos      16                                       /* AESOUTSAVE2: OUTSAVE10 Position */
#define AESOUTSAVE2_OUTSAVE10_Msk      (0xfful << AESOUTSAVE2_OUTSAVE10_Pos)    /* AESOUTSAVE2: OUTSAVE10 Mask */
#define AESOUTSAVE2_OUTSAVE11_Pos      24                                       /* AESOUTSAVE2: OUTSAVE11 Position */
#define AESOUTSAVE2_OUTSAVE11_Msk      (0xfful << AESOUTSAVE2_OUTSAVE11_Pos)    /* AESOUTSAVE2: OUTSAVE11 Mask */
/* AES OUTPUT save register 3 Definitions */
#define AESOUTSAVE3_OUTSAVE12_Pos      0                                        /* AESOUTSAVE3: OUTSAVE12 Position */
#define AESOUTSAVE3_OUTSAVE12_Msk      (0xfful << AESOUTSAVE3_OUTSAVE12_Pos)    /* AESOUTSAVE3: OUTSAVE12 Mask */
#define AESOUTSAVE3_OUTSAVE13_Pos      8                                        /* AESOUTSAVE3: OUTSAVE13 Position */
#define AESOUTSAVE3_OUTSAVE13_Msk      (0xfful << AESOUTSAVE3_OUTSAVE13_Pos)    /* AESOUTSAVE3: OUTSAVE13 Mask */
#define AESOUTSAVE3_OUTSAVE14_Pos      16                                       /* AESOUTSAVE3: OUTSAVE14 Position */
#define AESOUTSAVE3_OUTSAVE14_Msk      (0xfful << AESOUTSAVE3_OUTSAVE14_Pos)    /* AESOUTSAVE3: OUTSAVE14 Mask */
#define AESOUTSAVE3_OUTSAVE15_Pos      24                                       /* AESOUTSAVE3: OUTSAVE15 Position */
#define AESOUTSAVE3_OUTSAVE15_Msk      (0xfful << AESOUTSAVE3_OUTSAVE15_Pos)    /* AESOUTSAVE3: OUTSAVE15 Mask */

/******************************************************************************/
/*                     Peripheral Registers_Bits_Constant                     */
/******************************************************************************/

#define AESCTRL_CVNR_CVNR0                       0x00                           /* Chaining Variable Number */
#define AESCTRL_CVNR_CVNR1                       0x01                           /* Chaining Variable Number */
#define AESCTRL_CVNR_CVNR2                       0x02                           /* Chaining Variable Number */
#define AESCTRL_CVNR_CVNR3                       0x03                           /* Chaining Variable Number */
#define AESCTRL_CVNR_CVNR4                       0x04                           /* Chaining Variable Number */
#define AESCTRL_KEYNR_OLDKEY                     0x1F                           /* Key Number */
#define AESCTRL_OPC_ECBENC                       0x00                           /* Operation Code */
#define AESCTRL_OPC_ECBDEC                       0x01                           /* Operation Code */
#define AESCTRL_OPC_CBCENC                       0x02                           /* Operation Code */
#define AESCTRL_OPC_CBCDEC                       0x03                           /* Operation Code */
#define AESCTRL_OPC_CTR                          0x04                           /* Operation Code */
#define AESCTRL_OPC_OFB                          0x05                           /* Operation Code */
#define AESCTRL_OPC_CFBENC                       0x06                           /* Operation Code */
#define AESCTRL_OPC_CFBDEC                       0x07                           /* Operation Code */
#define AESCTRL_OPC_GCMENC                       0x08                           /* Operation Code */
#define AESCTRL_OPC_GCMDEC                       0x09                           /* Operation Code */
#define AESCTRL_OPC_GCMMAC                       0x0A                           /* Operation Code */
#define AESCTRL_OPC_XTSENC                       0x0B                           /* Operation Code */
#define AESCTRL_OPC_XTSDEC                       0x0C                           /* Operation Code */
#define AESCTRL_OPC_WK                           0x10                           /* Operation Code */
#define AESCTRL_OPC_LK                           0x11                           /* Operation Code */
#define AESCTRL_OPC_WCV                          0x12                           /* Operation Code */
#define AESCTRL_OPC_RCV                          0x13                           /* Operation Code */
#define AESSTAT_BSY_idle                         0x00                           /* Busy flag */
#define AESSTAT_BSY_busy                         0x01                           /* Busy flag */
#define AESSTAT_LOCK0_K0WENABLED                 0x00                           /* Lock Key0 */
#define AESSTAT_LOCK0_K0LOCKED                   0x01                           /* Lock Key0 */
#define AESSTAT_LOCK1_K1WENABLED                 0x00                           /* Lock Key1 */
#define AESSTAT_LOCK1_K1LOCKED                   0x01                           /* Lock Key1 */


#endif  /* __AES_HSM_H__ */

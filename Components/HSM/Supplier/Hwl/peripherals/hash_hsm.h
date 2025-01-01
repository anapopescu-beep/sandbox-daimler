// =============================================================================
// @file:    hash_hsm.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __HASH_HSM_H__
#define __HASH_HSM_H__

#define __IFX_HASH_VERSION_MAIN         (0x0)                               /* [31:24] MODULE main version   */
#define __IFX_HASH_VERSION_SUB          (0x0)                               /* [23:16] MODULE sub version    */
#define __IFX_HASH_VERSION_CONFIG       (0x0)                               /* [15:0]  MODULE config version */
#define __IFX_HASH_VERSION              ((__IFX_HASH_VERSION_MAIN << 24) | \
                                         (__IFX_HASH_VERSION_SUB << 16)  | \
                                          __IFX_HASH_VERSION_CONFIG)                  /* MODULE version number        */

/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/



/*------------- HASH Module     ----------------------------------------------*/
typedef struct
{
  __IO uint32_t HASH_CFG                 ; // HASH Configuration Register
  __I  uint32_t HASH_STAT                ; // HASH Status Register
  __IO uint32_t HASH_IVIN                ; // Hash Initialization Value Register
  __I  uint32_t HASH_VAL                 ; // Hash Output Value Register
  __IO uint32_t HASH_DATA                ; // Hash Data Input Register
} HSM_HASH_TypeDef;




/******************************************************************************/
/*                    Peripheral Registers_Bits_Definition                    */
/******************************************************************************/

/* HASH Configuration Register Definitions */
#define HASH_CFG_ALGO_Pos              0                                        /* HASH_CFG: ALGO Position */
#define HASH_CFG_ALGO_Msk              (0x3ul << HASH_CFG_ALGO_Pos)             /* HASH_CFG: ALGO Mask */
#define HASH_CFG_IV_MODE_Pos           3                                        /* HASH_CFG: IV_MODE Position */
#define HASH_CFG_IV_MODE_Msk           (0x1ul << HASH_CFG_IV_MODE_Pos)          /* HASH_CFG: IV_MODE Mask */
#define HASH_CFG_ORDER_OUT_Pos         4                                        /* HASH_CFG: ORDER_OUT Position */
#define HASH_CFG_ORDER_OUT_Msk         (0x1ul << HASH_CFG_ORDER_OUT_Pos)        /* HASH_CFG: ORDER_OUT Mask */
#define HASH_CFG_BEND_OUT_Pos          6                                        /* HASH_CFG: BEND_OUT Position */
#define HASH_CFG_BEND_OUT_Msk          (0x1ul << HASH_CFG_BEND_OUT_Pos)         /* HASH_CFG: BEND_OUT Mask */
#define HASH_CFG_BEND_IN_Pos           7                                        /* HASH_CFG: BEND_IN Position */
#define HASH_CFG_BEND_IN_Msk           (0x1ul << HASH_CFG_BEND_IN_Pos)          /* HASH_CFG: BEND_IN Mask */
/* HASH Status Register Definitions */
#define HASH_STAT_BSY_Pos              0                                        /* HASH_STAT: BSY Position */
#define HASH_STAT_BSY_Msk              (0x1ul << HASH_STAT_BSY_Pos)             /* HASH_STAT: BSY Mask */
#define HASH_STAT_IV_OK_Pos            1                                        /* HASH_STAT: IV_OK Position */
#define HASH_STAT_IV_OK_Msk            (0x1ul << HASH_STAT_IV_OK_Pos)           /* HASH_STAT: IV_OK Mask */
#define HASH_STAT_DF_NF_Pos            2                                        /* HASH_STAT: DF_NF Position */
#define HASH_STAT_DF_NF_Msk            (0x1ul << HASH_STAT_DF_NF_Pos)           /* HASH_STAT: DF_NF Mask */
#define HASH_STAT_CNT_Pos              8                                        /* HASH_STAT: CNT Position */
#define HASH_STAT_CNT_Msk              (0xful << HASH_STAT_CNT_Pos)             /* HASH_STAT: CNT Mask */

/******************************************************************************/
/*                     Peripheral Registers_Bits_Constant                     */
/******************************************************************************/

#define HASH_CFG_ALGO_NONE                       0x00                           /* Hash Algorithm */
#define HASH_CFG_ALGO_MD5                        0x01                           /* Hash Algorithm */
#define HASH_CFG_ALGO_SHA1                       0x02                           /* Hash Algorithm */
#define HASH_CFG_ALGO_SHA256                     0x03                           /* Hash Algorithm */
#define HASH_CFG_IV_MODE_NO_IV                   0x00                           /* Initialization Value Mode */
#define HASH_CFG_IV_MODE_USE_IV                  0x01                           /* Initialization Value Mode */
#define HASH_CFG_ORDER_OUT_LSW_FIRST             0x00                           /* Output Word Sequence Order */
#define HASH_CFG_ORDER_OUT_MSW_FIRST             0x01                           /* Output Word Sequence Order */
#define HASH_CFG_BEND_OUT_BIG                    0x00                           /* Output Byte Endianness */
#define HASH_CFG_BEND_OUT_LIT                    0x01                           /* Output Byte Endianness */
#define HASH_CFG_BEND_IN_BIG                     0x00                           /* Input Byte Endianness */
#define HASH_CFG_BEND_IN_LIT                     0x01                           /* Input Byte Endianness */
#define HASH_STAT_BSY_HASH_IDLE                  0x00                           /* Busy Flag */
#define HASH_STAT_BSY_HASH_BUSY                  0x01                           /* Busy Flag */
#define HASH_STAT_IV_OK_IV_INVALID               0x00                           /* Initialization Vector OK */
#define HASH_STAT_IV_OK_IV_VALID                 0x01                           /* Initialization Vector OK */
#define HASH_STAT_DF_NF_FIFO_FULL                0x00                           /* Data FIFO Not Full */
#define HASH_STAT_DF_NF_FIFO_NOTFULL             0x01                           /* Data FIFO Not Full */


#endif  /* __HASH_HSM_H__ */

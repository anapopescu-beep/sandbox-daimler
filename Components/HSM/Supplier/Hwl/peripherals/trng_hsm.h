// =============================================================================
// @file:    trng_hsm.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __TRNG_HSM_H__
#define __TRNG_HSM_H__

#define __IFX_TRNG_VERSION_MAIN         (0x0)                               /* [31:24] MODULE main version   */
#define __IFX_TRNG_VERSION_SUB          (0x0)                               /* [23:16] MODULE sub version    */
#define __IFX_TRNG_VERSION_CONFIG       (0x0)                               /* [15:0]  MODULE config version */
#define __IFX_TRNG_VERSION              ((__IFX_TRNG_VERSION_MAIN << 24) | \
                                         (__IFX_TRNG_VERSION_SUB << 16)  | \
                                          __IFX_TRNG_VERSION_CONFIG)                  /* MODULE version number        */

/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/



/*------------- TRNG Module     ----------------------------------------------*/
typedef struct
{
  __I  uint32_t TRNG_DATA32              ; // True RNG Data Register
       uint32_t RESERVED0[2]             ;
  __IO uint16_t TRNG_STAT                ; // TRNG status register
       uint16_t RESERVED1                ;
  __IO uint16_t TRNG_CTRL                ; // TRNG control register
} HSM_TRNG_TypeDef;




/******************************************************************************/
/*                    Peripheral Registers_Bits_Definition                    */
/******************************************************************************/

/* TRNG status register Definitions */
#define TRNG_STAT_DTA_RDY_Pos          0                                        /* TRNG_STAT: DTA_RDY Position */
#define TRNG_STAT_DTA_RDY_Msk          (0x1ul << TRNG_STAT_DTA_RDY_Pos)         /* TRNG_STAT: DTA_RDY Mask */
#define TRNG_STAT_FIPS_ERR_Pos         2                                        /* TRNG_STAT: FIPS_ERR Position */
#define TRNG_STAT_FIPS_ERR_Msk         (0x1ul << TRNG_STAT_FIPS_ERR_Pos)        /* TRNG_STAT: FIPS_ERR Mask */
#define TRNG_STAT_UNLOCK_FIPS_ERR_Pos  3                                        /* TRNG_STAT: UNLOCK_FIPS_ERR Position */
#define TRNG_STAT_UNLOCK_FIPS_ERR_Msk  (0x1ul << TRNG_STAT_UNLOCK_FIPS_ERR_Pos) /* TRNG_STAT: UNLOCK_FIPS_ERR Mask */
#define TRNG_STAT_WARN_Pos             9                                        /* TRNG_STAT: WARN Position */
#define TRNG_STAT_WARN_Msk             (0x1ul << TRNG_STAT_WARN_Pos)            /* TRNG_STAT: WARN Mask */
#define TRNG_STAT_UNLOCK_WARN_Pos      10                                       /* TRNG_STAT: UNLOCK_WARN Position */
#define TRNG_STAT_UNLOCK_WARN_Msk      (0x1ul << TRNG_STAT_UNLOCK_WARN_Pos)     /* TRNG_STAT: UNLOCK_WARN Mask */
/* TRNG control register Definitions */
#define TRNG_CTRL_DBS_Pos              0                                        /* TRNG_CTRL: DBS Position */
#define TRNG_CTRL_DBS_Msk              (0x3ul << TRNG_CTRL_DBS_Pos)             /* TRNG_CTRL: DBS Mask */
#define TRNG_CTRL_DIS_Pos              2                                        /* TRNG_CTRL: DIS Position */
#define TRNG_CTRL_DIS_Msk              (0x1ul << TRNG_CTRL_DIS_Pos)             /* TRNG_CTRL: DIS Mask */

/******************************************************************************/
/*                     Peripheral Registers_Bits_Constant                     */
/******************************************************************************/

#define TRNG_STAT_DTA_RDY_BUSY                   0x00                           /* Random Data Ready */
#define TRNG_STAT_DTA_RDY_RDY                    0x01                           /* Random Data Ready */
#define TRNG_STAT_FIPS_ERR_OK                    0x00                           /* FIPS Error */
#define TRNG_STAT_FIPS_ERR_ERROR                 0x01                           /* FIPS Error */
#define TRNG_STAT_UNLOCK_FIPS_ERR_LOCK           0x00                           /* Unlock Bit for FIPS_ERR */
#define TRNG_STAT_UNLOCK_FIPS_ERR_WE             0x01                           /* Unlock Bit for FIPS_ERR */
#define TRNG_STAT_WARN_GOOD                      0x00                           /* Quality Warning */
#define TRNG_STAT_WARN_LOW                       0x01                           /* Quality Warning */
#define TRNG_STAT_UNLOCK_WARN_LOCK               0x00                           /* Unlock Bit for WARN */
#define TRNG_STAT_UNLOCK_WARN_WE                 0x01                           /* Unlock Bit for WARN */
#define TRNG_CTRL_DBS_BYTE                       0x00                           /* Data Block Size */
#define TRNG_CTRL_DBS_HW                         0x01                           /* Data Block Size */
#define TRNG_CTRL_DBS_WORD                       0x02                           /* Data Block Size */
#define TRNG_CTRL_DIS_EN                         0x00                           /* Disable */
#define TRNG_CTRL_DIS_DIS                        0x01                           /* Disable */


#endif  /* __TRNG_HSM_H__ */

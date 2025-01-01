// =============================================================================
// @file:    cache_hsm.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __CACHE_HSM_H__
#define __CACHE_HSM_H__

#define __IFX_CACHE_VERSION_MAIN        (0x0)                               /* [31:24] MODULE main version   */
#define __IFX_CACHE_VERSION_SUB         (0x0)                               /* [23:16] MODULE sub version    */
#define __IFX_CACHE_VERSION_CONFIG      (0x0)                               /* [15:0]  MODULE config version */
#define __IFX_CACHE_VERSION             ((__IFX_CACHE_VERSION_MAIN << 24) | \
                                         (__IFX_CACHE_VERSION_SUB << 16)  | \
                                          __IFX_CACHE_VERSION_CONFIG)                  /* MODULE version number        */

/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/



/*------------- CACHE Module    ----------------------------------------------*/
typedef struct
{
  __I  uint32_t CACHE_CONFIG             ; // Cache Configuration Register
  __IO uint32_t CACHE_CTRL               ; // Cache Control Register
       uint32_t RESERVED0[62]            ;
  __IO uint32_t CACHE_AC                 ; // Cache All Clean Register
  __IO uint32_t CACHE_SC                 ; // Cache Set Clean Register
       uint32_t RESERVED1[2]             ;
  __IO uint32_t CACHE_BC                 ; // Cache Block Clean Register
  __IO uint32_t CACHE_BT                 ; // Cache Block Touch Register
  __IO uint32_t CACHE_BL                 ; // Cache Block Lock Register
  __IO uint32_t CACHE_BU                 ; // Cache Block Unlock Register
} HSM_CACHE_TypeDef;




/******************************************************************************/
/*                    Peripheral Registers_Bits_Definition                    */
/******************************************************************************/

/* Cache Configuration Register Definitions */
#define CACHE_CONFIG_BLKBITS_Pos       0                                        /* CACHE_CONFIG: BLKBITS Position */
#define CACHE_CONFIG_BLKBITS_Msk       (0xfful << CACHE_CONFIG_BLKBITS_Pos)     /* CACHE_CONFIG: BLKBITS Mask */
#define CACHE_CONFIG_WAYS_Pos          8                                        /* CACHE_CONFIG: WAYS Position */
#define CACHE_CONFIG_WAYS_Msk          (0xfful << CACHE_CONFIG_WAYS_Pos)        /* CACHE_CONFIG: WAYS Mask */
#define CACHE_CONFIG_SETBITS_Pos       16                                       /* CACHE_CONFIG: SETBITS Position */
#define CACHE_CONFIG_SETBITS_Msk       (0xfful << CACHE_CONFIG_SETBITS_Pos)     /* CACHE_CONFIG: SETBITS Mask */
/* Cache Control Register Definitions */
#define CACHE_CTRL_DAPCA_Pos           0                                        /* CACHE_CTRL: DAPCA Position */
#define CACHE_CTRL_DAPCA_Msk           (0x1ul << CACHE_CTRL_DAPCA_Pos)          /* CACHE_CTRL: DAPCA Mask */

/******************************************************************************/
/*                     Peripheral Registers_Bits_Constant                     */
/******************************************************************************/

#define CACHE_CONFIG_BLKBITS_BW4                 0x04                           /* Number of Block Bits */
#define CACHE_CTRL_DAPCA_EN                      0x00                           /* Disable Parallel Cache Accesses */
#define CACHE_CTRL_DAPCA_DIS                     0x01                           /* Disable Parallel Cache Accesses */


#endif  /* __CACHE_HSM_H__ */

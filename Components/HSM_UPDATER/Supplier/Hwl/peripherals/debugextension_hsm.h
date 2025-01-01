// =============================================================================
// @file:    debugextension_hsm.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __DEBUGEXTENSION_HSM_H__
#define __DEBUGEXTENSION_HSM_H__

#define __IFX_DEBUGEXTENSION_VERSION_MAIN (0x0)                               /* [31:24] MODULE main version   */
#define __IFX_DEBUGEXTENSION_VERSION_SUB (0x0)                               /* [23:16] MODULE sub version    */
#define __IFX_DEBUGEXTENSION_VERSION_CONFIG (0x0)                               /* [15:0]  MODULE config version */
#define __IFX_DEBUGEXTENSION_VERSION    ((__IFX_DEBUGEXTENSION_VERSION_MAIN << 24) | \
                                         (__IFX_DEBUGEXTENSION_VERSION_SUB << 16)  | \
                                          __IFX_DEBUGEXTENSION_VERSION_CONFIG)                  /* MODULE version number        */

/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/



/*------------- DEBUGEXTENSION Module----------------------------------------------*/
typedef struct
{
       uint32_t RESERVED0[10]            ;
  __IO uint32_t FP_COMPH0                ; // Flash Patch Comparator High Register 0
  __IO uint32_t FP_COMPH1                ; // Flash Patch Comparator High Register 0
  __IO uint32_t FP_COMPH2                ; // Flash Patch Comparator High Register 0
  __IO uint32_t FP_COMPH3                ; // Flash Patch Comparator High Register 0
  __IO uint32_t FP_COMPH4                ; // Flash Patch Comparator High Register 0
  __IO uint32_t FP_COMPH5                ; // Flash Patch Comparator High Register 0
  __IO uint32_t FP_COMPH6                ; // Flash Patch Comparator High Register 0
  __IO uint32_t FP_COMPH7                ; // Flash Patch Comparator High Register 0
       uint32_t RESERVED1[994]           ;
  __I  uint32_t PID4                     ; // Peripheral IDentification Register 4
       uint32_t RESERVED2[3]             ;
  __I  uint32_t PID0                     ; // Peripheral IDentification register 0
  __I  uint32_t PID1                     ; // Peripheral IDentification Register 1
  __I  uint32_t PID2                     ; // Peripheral IDentification Register 2
  __I  uint32_t PID3                     ; // Peripheral IDentification Register 3
       uint32_t RESERVED3[12160]         ;
  __IO uint32_t DHCSR                    ; // Debug Halting Control and Status Register
} HSM_DEBUGEXTENSION_TypeDef;




/******************************************************************************/
/*                    Peripheral Registers_Bits_Definition                    */
/******************************************************************************/

/* Flash Patch Comparator High Register 0 Definitions */
#define FP_COMPH0_COMPH_Pos            0                                        /* FP_COMPH0: COMPH Position */
#define FP_COMPH0_COMPH_Msk            (0x7ul << FP_COMPH0_COMPH_Pos)           /* FP_COMPH0: COMPH Mask */
/* Flash Patch Comparator High Register 0 Definitions */
#define FP_COMPH1_COMPH_Pos            0                                        /* FP_COMPH1: COMPH Position */
#define FP_COMPH1_COMPH_Msk            (0x7ul << FP_COMPH1_COMPH_Pos)           /* FP_COMPH1: COMPH Mask */
/* Flash Patch Comparator High Register 0 Definitions */
#define FP_COMPH2_COMPH_Pos            0                                        /* FP_COMPH2: COMPH Position */
#define FP_COMPH2_COMPH_Msk            (0x7ul << FP_COMPH2_COMPH_Pos)           /* FP_COMPH2: COMPH Mask */
/* Flash Patch Comparator High Register 0 Definitions */
#define FP_COMPH3_COMPH_Pos            0                                        /* FP_COMPH3: COMPH Position */
#define FP_COMPH3_COMPH_Msk            (0x7ul << FP_COMPH3_COMPH_Pos)           /* FP_COMPH3: COMPH Mask */
/* Flash Patch Comparator High Register 0 Definitions */
#define FP_COMPH4_COMPH_Pos            0                                        /* FP_COMPH4: COMPH Position */
#define FP_COMPH4_COMPH_Msk            (0x7ul << FP_COMPH4_COMPH_Pos)           /* FP_COMPH4: COMPH Mask */
/* Flash Patch Comparator High Register 0 Definitions */
#define FP_COMPH5_COMPH_Pos            0                                        /* FP_COMPH5: COMPH Position */
#define FP_COMPH5_COMPH_Msk            (0x7ul << FP_COMPH5_COMPH_Pos)           /* FP_COMPH5: COMPH Mask */
/* Flash Patch Comparator High Register 0 Definitions */
#define FP_COMPH6_COMPH_Pos            0                                        /* FP_COMPH6: COMPH Position */
#define FP_COMPH6_COMPH_Msk            (0x7ul << FP_COMPH6_COMPH_Pos)           /* FP_COMPH6: COMPH Mask */
/* Flash Patch Comparator High Register 0 Definitions */
#define FP_COMPH7_COMPH_Pos            0                                        /* FP_COMPH7: COMPH Position */
#define FP_COMPH7_COMPH_Msk            (0x7ul << FP_COMPH7_COMPH_Pos)           /* FP_COMPH7: COMPH Mask */
/* Debug Halting Control and Status Register Definitions */
#define DHCSR_C_DEBUGEN_Pos            0                                        /* DHCSR: C_DEBUGEN Position */
#define DHCSR_C_DEBUGEN_Msk            (0x1ul << DHCSR_C_DEBUGEN_Pos)           /* DHCSR: C_DEBUGEN Mask */
#define DHCSR_C_HALT_Pos               1                                        /* DHCSR: C_HALT Position */
#define DHCSR_C_HALT_Msk               (0x1ul << DHCSR_C_HALT_Pos)              /* DHCSR: C_HALT Mask */
#define DHCSR_C_STEP_Pos               2                                        /* DHCSR: C_STEP Position */
#define DHCSR_C_STEP_Msk               (0x1ul << DHCSR_C_STEP_Pos)              /* DHCSR: C_STEP Mask */
#define DHCSR_C_MASKINTS_Pos           3                                        /* DHCSR: C_MASKINTS Position */
#define DHCSR_C_MASKINTS_Msk           (0x1ul << DHCSR_C_MASKINTS_Pos)          /* DHCSR: C_MASKINTS Mask */
#define DHCSR_C_SNAPSTALL_Pos          5                                        /* DHCSR: C_SNAPSTALL Position */
#define DHCSR_C_SNAPSTALL_Msk          (0x1ul << DHCSR_C_SNAPSTALL_Pos)         /* DHCSR: C_SNAPSTALL Mask */
#define DHCSR_DBGKEY_Pos               16                                       /* DHCSR: DBGKEY Position */
#define DHCSR_DBGKEY_Msk               (0xfffful << DHCSR_DBGKEY_Pos)           /* DHCSR: DBGKEY Mask */

/******************************************************************************/
/*                     Peripheral Registers_Bits_Constant                     */
/******************************************************************************/



#endif  /* __DEBUGEXTENSION_HSM_H__ */

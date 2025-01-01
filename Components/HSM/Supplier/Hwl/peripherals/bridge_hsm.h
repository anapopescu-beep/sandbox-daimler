// =============================================================================
// @file:    bridge_hsm.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __BRIDGE_HSM_H__
#define __BRIDGE_HSM_H__

#define __IFX_BRIDGE_VERSION_MAIN       (0x0)                               /* [31:24] MODULE main version   */
#define __IFX_BRIDGE_VERSION_SUB        (0x0)                               /* [23:16] MODULE sub version    */
#define __IFX_BRIDGE_VERSION_CONFIG     (0x0)                               /* [15:0]  MODULE config version */
#define __IFX_BRIDGE_VERSION            ((__IFX_BRIDGE_VERSION_MAIN << 24) | \
                                         (__IFX_BRIDGE_VERSION_SUB << 16)  | \
                                          __IFX_BRIDGE_VERSION_CONFIG)                  /* MODULE version number        */

/******************************************************************************/
/*              Device Specific Peripheral registers structures               */
/******************************************************************************/



/*------------- BRIDGE Module   ----------------------------------------------*/
typedef struct
{
       uint32_t RESERVED0[2]             ;
  __IO uint32_t HSM_ID                   ; // Module Identifier Register
       uint32_t RESERVED1[5]             ;
  __IO uint32_t HT2HSMF                  ; // Host to HSM Flag Register
  __IO uint32_t HT2HSMIE                 ; // Host to HSM Interrupt Enable
  __IO uint32_t HSM2HTF                  ; // HSM to Host Flag Register
  __IO uint32_t HSM2HTIE                 ; // HSM to Host Interrupt Enable
  __IO uint32_t HSM2HTIS                 ; // HSM to Host Interrupt Select
  __IO uint32_t HSM2HTS                  ; // HSM to Host Status
  __IO uint32_t HT2HSMS                  ; // Host to HSM Status
       uint32_t RESERVED2                ;
  __IO uint32_t CLKCTRL                  ; // Clock Control Register
       uint32_t RESERVED3[7]             ;
  __IO uint32_t DBGCTRL                  ; // Debug Control Register
  __IO uint32_t PINCTRL                  ; // Pin Control Register
       uint32_t RESERVED4[6]             ;
  __IO uint32_t ERRCTRL                  ; // Error Control Register
  __IO uint32_t ERRIE                    ; // Error Interrupt Enable Register
  __IO uint32_t ERRADDR                  ; // Error Address Register
       uint32_t RESERVED5[5]             ;
  __IO uint32_t EXTIF                    ; // External Interrupt Flag Register
  __IO uint32_t EXTIE                    ; // External Interrupt Enable
       uint32_t RESERVED6[6]             ;
  __IO uint32_t SAHBASE                  ; // Single Access to Host Base Address Register
       uint32_t RESERVED7[7]             ;
  __IO uint32_t RSTCTRL                  ; // Reset Control Register
  __IO uint32_t RSTPWD                   ; // Reset Password Register
       uint32_t RESERVED8[2]             ;
  __IO uint32_t SENSIF                   ; // Sensor Interrupt Flag Register
  __IO uint32_t SENSIE                   ; // Sensor Interrupt Enable Register
  __IO uint32_t SENSAPPRST               ; // Sensor Application Reset Enable Register
  __IO uint32_t SENSSYSRST               ; // Sensor System Reset Enable Register
       uint32_t RESERVED9[16320]         ;
  __IO uint32_t SAHMEM[16384]            ; // Single Access to Host Memory Window
} HSM_BRIDGE_TypeDef;




/******************************************************************************/
/*                    Peripheral Registers_Bits_Definition                    */
/******************************************************************************/

/* Module Identifier Register Definitions */
#define HSM_ID_MOD_REV_Pos             0                                        /* HSM_ID: MOD_REV Position */
#define HSM_ID_MOD_REV_Msk             (0xfful << HSM_ID_MOD_REV_Pos)           /* HSM_ID: MOD_REV Mask */
#define HSM_ID_MOD_TYPE_Pos            8                                        /* HSM_ID: MOD_TYPE Position */
#define HSM_ID_MOD_TYPE_Msk            (0xfful << HSM_ID_MOD_TYPE_Pos)          /* HSM_ID: MOD_TYPE Mask */
#define HSM_ID_MOD_NUMBER_Pos          16                                       /* HSM_ID: MOD_NUMBER Position */
#define HSM_ID_MOD_NUMBER_Msk          (0xfffful << HSM_ID_MOD_NUMBER_Pos)      /* HSM_ID: MOD_NUMBER Mask */
/* Clock Control Register Definitions */
#define CLKCTRL_CLKDIV_Pos             0                                        /* CLKCTRL: CLKDIV Position */
#define CLKCTRL_CLKDIV_Msk             (0x3ul << CLKCTRL_CLKDIV_Pos)            /* CLKCTRL: CLKDIV Mask */
/* Debug Control Register Definitions */
#define DBGCTRL_HSM_Pos                0                                        /* DBGCTRL: HSM Position */
#define DBGCTRL_HSM_Msk                (0x3ul << DBGCTRL_HSM_Pos)               /* DBGCTRL: HSM Mask */
#define DBGCTRL_HOST_Pos               4                                        /* DBGCTRL: HOST Position */
#define DBGCTRL_HOST_Msk               (0x3ul << DBGCTRL_HOST_Pos)              /* DBGCTRL: HOST Mask */
#define DBGCTRL_TREN_Pos               8                                        /* DBGCTRL: TREN Position */
#define DBGCTRL_TREN_Msk               (0x3ul << DBGCTRL_TREN_Pos)              /* DBGCTRL: TREN Mask */
#define DBGCTRL_TRDATA_Pos             10                                       /* DBGCTRL: TRDATA Position */
#define DBGCTRL_TRDATA_Msk             (0x1ul << DBGCTRL_TRDATA_Pos)            /* DBGCTRL: TRDATA Mask */
/* Pin Control Register Definitions */
#define PINCTRL_VAL0_Pos               0                                        /* PINCTRL: VAL0 Position */
#define PINCTRL_VAL0_Msk               (0x1ul << PINCTRL_VAL0_Pos)              /* PINCTRL: VAL0 Mask */
#define PINCTRL_OEN0_Pos               1                                        /* PINCTRL: OEN0 Position */
#define PINCTRL_OEN0_Msk               (0x1ul << PINCTRL_OEN0_Pos)              /* PINCTRL: OEN0 Mask */
#define PINCTRL_VAL1_Pos               2                                        /* PINCTRL: VAL1 Position */
#define PINCTRL_VAL1_Msk               (0x1ul << PINCTRL_VAL1_Pos)              /* PINCTRL: VAL1 Mask */
#define PINCTRL_OEN1_Pos               3                                        /* PINCTRL: OEN1 Position */
#define PINCTRL_OEN1_Msk               (0x1ul << PINCTRL_OEN1_Pos)              /* PINCTRL: OEN1 Mask */
#define PINCTRL_LOCK_Pos               31                                       /* PINCTRL: LOCK Position */
#define PINCTRL_LOCK_Msk               (0x1ul << PINCTRL_LOCK_Pos)              /* PINCTRL: LOCK Mask */
/* Error Control Register Definitions */
#define ERRCTRL_BERR_Pos               0                                        /* ERRCTRL: BERR Position */
#define ERRCTRL_BERR_Msk               (0x1ul << ERRCTRL_BERR_Pos)              /* ERRCTRL: BERR Mask */
#define ERRCTRL_ECCROM_Pos             2                                        /* ERRCTRL: ECCROM Position */
#define ERRCTRL_ECCROM_Msk             (0x3ul << ERRCTRL_ECCROM_Pos)            /* ERRCTRL: ECCROM Mask */
#define ERRCTRL_ECCRAM_Pos             4                                        /* ERRCTRL: ECCRAM Position */
#define ERRCTRL_ECCRAM_Msk             (0x3ul << ERRCTRL_ECCRAM_Pos)            /* ERRCTRL: ECCRAM Mask */
#define ERRCTRL_ADRAM_Pos              6                                        /* ERRCTRL: ADRAM Position */
#define ERRCTRL_ADRAM_Msk              (0x1ul << ERRCTRL_ADRAM_Pos)             /* ERRCTRL: ADRAM Mask */
#define ERRCTRL_ECCCD_Pos              7                                        /* ERRCTRL: ECCCD Position */
#define ERRCTRL_ECCCD_Msk              (0x3ul << ERRCTRL_ECCCD_Pos)             /* ERRCTRL: ECCCD Mask */
#define ERRCTRL_ADCD_Pos               9                                        /* ERRCTRL: ADCD Position */
#define ERRCTRL_ADCD_Msk               (0x1ul << ERRCTRL_ADCD_Pos)              /* ERRCTRL: ADCD Mask */
#define ERRCTRL_ECCCT_Pos              10                                       /* ERRCTRL: ECCCT Position */
#define ERRCTRL_ECCCT_Msk              (0x3ul << ERRCTRL_ECCCT_Pos)             /* ERRCTRL: ECCCT Mask */
#define ERRCTRL_ADCT_Pos               12                                       /* ERRCTRL: ADCT Position */
#define ERRCTRL_ADCT_Msk               (0x1ul << ERRCTRL_ADCT_Pos)              /* ERRCTRL: ADCT Mask */
#define ERRCTRL_ECCPKCTCM_Pos          13                                       /* ERRCTRL: ECCPKCTCM Position */
#define ERRCTRL_ECCPKCTCM_Msk          (0x3ul << ERRCTRL_ECCPKCTCM_Pos)         /* ERRCTRL: ECCPKCTCM Mask */
#define ERRCTRL_ADPKCTCM_Pos           15                                       /* ERRCTRL: ADPKCTCM Position */
#define ERRCTRL_ADPKCTCM_Msk           (0x1ul << ERRCTRL_ADPKCTCM_Pos)          /* ERRCTRL: ADPKCTCM Mask */
#define ERRCTRL_ECCPKCSCM_Pos          16                                       /* ERRCTRL: ECCPKCSCM Position */
#define ERRCTRL_ECCPKCSCM_Msk          (0x3ul << ERRCTRL_ECCPKCSCM_Pos)         /* ERRCTRL: ECCPKCSCM Mask */
#define ERRCTRL_ADPKCSCM_Pos           18                                       /* ERRCTRL: ADPKCSCM Position */
#define ERRCTRL_ADPKCSCM_Msk           (0x1ul << ERRCTRL_ADPKCSCM_Pos)          /* ERRCTRL: ADPKCSCM Mask */
#define ERRCTRL_ECCPKCROM_Pos          19                                       /* ERRCTRL: ECCPKCROM Position */
#define ERRCTRL_ECCPKCROM_Msk          (0x3ul << ERRCTRL_ECCPKCROM_Pos)         /* ERRCTRL: ECCPKCROM Mask */
#define ERRCTRL_ROMON_Pos              28                                       /* ERRCTRL: ROMON Position */
#define ERRCTRL_ROMON_Msk              (0x3ul << ERRCTRL_ROMON_Pos)             /* ERRCTRL: ROMON Mask */
#define ERRCTRL_XDBG_Pos               31                                       /* ERRCTRL: XDBG Position */
#define ERRCTRL_XDBG_Msk               (0x1ul << ERRCTRL_XDBG_Pos)              /* ERRCTRL: XDBG Mask */
/* Error Interrupt Enable Register Definitions */
#define ERRIE_BERRIE_Pos               0                                        /* ERRIE: BERRIE Position */
#define ERRIE_BERRIE_Msk               (0x1ul << ERRIE_BERRIE_Pos)              /* ERRIE: BERRIE Mask */
#define ERRIE_ECCROMIE_Pos             2                                        /* ERRIE: ECCROMIE Position */
#define ERRIE_ECCROMIE_Msk             (0x3ul << ERRIE_ECCROMIE_Pos)            /* ERRIE: ECCROMIE Mask */
#define ERRIE_ECCRAMIE_Pos             4                                        /* ERRIE: ECCRAMIE Position */
#define ERRIE_ECCRAMIE_Msk             (0x3ul << ERRIE_ECCRAMIE_Pos)            /* ERRIE: ECCRAMIE Mask */
#define ERRIE_ADRAMIE_Pos              6                                        /* ERRIE: ADRAMIE Position */
#define ERRIE_ADRAMIE_Msk              (0x1ul << ERRIE_ADRAMIE_Pos)             /* ERRIE: ADRAMIE Mask */
#define ERRIE_ECCCDIE_Pos              7                                        /* ERRIE: ECCCDIE Position */
#define ERRIE_ECCCDIE_Msk              (0x3ul << ERRIE_ECCCDIE_Pos)             /* ERRIE: ECCCDIE Mask */
#define ERRIE_ADCDIE_Pos               9                                        /* ERRIE: ADCDIE Position */
#define ERRIE_ADCDIE_Msk               (0x1ul << ERRIE_ADCDIE_Pos)              /* ERRIE: ADCDIE Mask */
#define ERRIE_ECCCTIE_Pos              10                                       /* ERRIE: ECCCTIE Position */
#define ERRIE_ECCCTIE_Msk              (0x3ul << ERRIE_ECCCTIE_Pos)             /* ERRIE: ECCCTIE Mask */
#define ERRIE_ADCTIE_Pos               12                                       /* ERRIE: ADCTIE Position */
#define ERRIE_ADCTIE_Msk               (0x1ul << ERRIE_ADCTIE_Pos)              /* ERRIE: ADCTIE Mask */
#define ERRIE_ECCPKCTCMIE_Pos          13                                       /* ERRIE: ECCPKCTCMIE Position */
#define ERRIE_ECCPKCTCMIE_Msk          (0x3ul << ERRIE_ECCPKCTCMIE_Pos)         /* ERRIE: ECCPKCTCMIE Mask */
#define ERRIE_ADPKCTCMIE_Pos           15                                       /* ERRIE: ADPKCTCMIE Position */
#define ERRIE_ADPKCTCMIE_Msk           (0x1ul << ERRIE_ADPKCTCMIE_Pos)          /* ERRIE: ADPKCTCMIE Mask */
#define ERRIE_ECCPKCSCMIE_Pos          16                                       /* ERRIE: ECCPKCSCMIE Position */
#define ERRIE_ECCPKCSCMIE_Msk          (0x3ul << ERRIE_ECCPKCSCMIE_Pos)         /* ERRIE: ECCPKCSCMIE Mask */
#define ERRIE_ADPKCSCMIE_Pos           18                                       /* ERRIE: ADPKCSCMIE Position */
#define ERRIE_ADPKCSCMIE_Msk           (0x1ul << ERRIE_ADPKCSCMIE_Pos)          /* ERRIE: ADPKCSCMIE Mask */
#define ERRIE_ECCPKCROMIE_Pos          19                                       /* ERRIE: ECCPKCROMIE Position */
#define ERRIE_ECCPKCROMIE_Msk          (0x3ul << ERRIE_ECCPKCROMIE_Pos)         /* ERRIE: ECCPKCROMIE Mask */
/* Single Access to Host Base Address Register Definitions */
#define SAHBASE_BASE_Pos               16                                       /* SAHBASE: BASE Position */
#define SAHBASE_BASE_Msk               (0xfffful << SAHBASE_BASE_Pos)           /* SAHBASE: BASE Mask */
/* Reset Control Register Definitions */
#define RSTCTRL_APPRST_Pos             0                                        /* RSTCTRL: APPRST Position */
#define RSTCTRL_APPRST_Msk             (0x1ul << RSTCTRL_APPRST_Pos)            /* RSTCTRL: APPRST Mask */
#define RSTCTRL_SYSRST_Pos             1                                        /* RSTCTRL: SYSRST Position */
#define RSTCTRL_SYSRST_Msk             (0x1ul << RSTCTRL_SYSRST_Pos)            /* RSTCTRL: SYSRST Mask */
/* Sensor Interrupt Flag Register Definitions */
#define SENSIF_SENSIF_Pos              0                                        /* SENSIF: SENSIF Position */
#define SENSIF_SENSIF_Msk              (0x3fful << SENSIF_SENSIF_Pos)           /* SENSIF: SENSIF Mask */
/* Sensor Interrupt Enable Register Definitions */
#define SENSIE_SENSIE_Pos              0                                        /* SENSIE: SENSIE Position */
#define SENSIE_SENSIE_Msk              (0x3fful << SENSIE_SENSIE_Pos)           /* SENSIE: SENSIE Mask */
/* Sensor Application Reset Enable Register Definitions */
#define SENSAPPRST_AREN_Pos            0                                        /* SENSAPPRST: AREN Position */
#define SENSAPPRST_AREN_Msk            (0x3fful << SENSAPPRST_AREN_Pos)         /* SENSAPPRST: AREN Mask */
/* Sensor System Reset Enable Register Definitions */
#define SENSSYSRST_SREN_Pos            0                                        /* SENSSYSRST: SREN Position */
#define SENSSYSRST_SREN_Msk            (0x3fful << SENSSYSRST_SREN_Pos)         /* SENSSYSRST: SREN Mask */

/******************************************************************************/
/*                     Peripheral Registers_Bits_Constant                     */
/******************************************************************************/

#define CLKCTRL_CLKDIV_DIV1                      0x00                           /* Clock Divider */
#define CLKCTRL_CLKDIV_DIV2                      0x01                           /* Clock Divider */
#define CLKCTRL_CLKDIV_DIV4                      0x02                           /* Clock Divider */
#define DBGCTRL_HSM_HSMDDIS0                     0x00                           /* Debug control for HSM subsystem and debug memory window */
#define DBGCTRL_HSM_HSMDDIS1                     0x01                           /* Debug control for HSM subsystem and debug memory window */
#define DBGCTRL_HSM_HSMDDIS2                     0x02                           /* Debug control for HSM subsystem and debug memory window */
#define DBGCTRL_HSM_HSMDEN                       0x03                           /* Debug control for HSM subsystem and debug memory window */
#define DBGCTRL_HOST_HTDDIS0                     0x00                           /* Debug control for host system */
#define DBGCTRL_HOST_HTDDIS1                     0x01                           /* Debug control for host system */
#define DBGCTRL_HOST_HTDDIS2                     0x02                           /* Debug control for host system */
#define DBGCTRL_HOST_HTDEN                       0x03                           /* Debug control for host system */
#define DBGCTRL_TREN_TRACEDIS0                   0x00                           /* Enables host side tracing of HSM accesses on SPB bus */
#define DBGCTRL_TREN_TRACEDIS1                   0x01                           /* Enables host side tracing of HSM accesses on SPB bus */
#define DBGCTRL_TREN_TRACEDIS2                   0x02                           /* Enables host side tracing of HSM accesses on SPB bus */
#define DBGCTRL_TREN_TRACEEN                     0x03                           /* Enables host side tracing of HSM accesses on SPB bus */
#define DBGCTRL_TRDATA_TRADDR                    0x00                           /* Type of trace information */
#define DBGCTRL_TRDATA_TRDATA                    0x01                           /* Type of trace information */
#define PINCTRL_VAL0_P0L                         0x00                           /* Pin 0 output value */
#define PINCTRL_VAL0_P0H                         0x01                           /* Pin 0 output value */
#define PINCTRL_OEN0_P0DIS                       0x00                           /* Pin 0 output enable */
#define PINCTRL_OEN0_P0EN                        0x01                           /* Pin 0 output enable */
#define PINCTRL_VAL1_P1L                         0x00                           /* Pin 1 output value */
#define PINCTRL_VAL1_P1H                         0x01                           /* Pin 1 output value */
#define PINCTRL_OEN1_P1DIS                       0x00                           /* Pin 1 output enable */
#define PINCTRL_OEN1_P1EN                        0x01                           /* Pin 1 output enable */
#define PINCTRL_LOCK_UNLOCKED                    0x00                           /* Pin control register lock */
#define PINCTRL_LOCK_LOCKED                      0x01                           /* Pin control register lock */
#define ERRCTRL_ECCROM_ROMNE                     0x00                           /* ECC errors of HSM boot ROM */
#define ERRCTRL_ECCROM_ROMCE                     0x01                           /* ECC errors of HSM boot ROM */
#define ERRCTRL_ECCROM_ROMUE                     0x02                           /* ECC errors of HSM boot ROM */
#define ERRCTRL_ECCROM_ROMCU                     0x03                           /* ECC errors of HSM boot ROM */
#define ERRCTRL_ECCRAM_RAMNE                     0x00                           /* ECC errors of Local RAM */
#define ERRCTRL_ECCRAM_RAMCE                     0x01                           /* ECC errors of Local RAM */
#define ERRCTRL_ECCRAM_RAMUE                     0x02                           /* ECC errors of Local RAM */
#define ERRCTRL_ECCRAM_RAMCU                     0x03                           /* ECC errors of Local RAM */
#define ERRCTRL_ECCCD_CDNE                       0x00                           /* ECC errors of cache data */
#define ERRCTRL_ECCCD_CDCE                       0x01                           /* ECC errors of cache data */
#define ERRCTRL_ECCCD_CDUE                       0x02                           /* ECC errors of cache data */
#define ERRCTRL_ECCCD_CDCU                       0x03                           /* ECC errors of cache data */
#define ERRCTRL_ECCCT_CTNE                       0x00                           /* ECC errors of cache tag field */
#define ERRCTRL_ECCCT_CTCE                       0x01                           /* ECC errors of cache tag field */
#define ERRCTRL_ECCCT_CTUE                       0x02                           /* ECC errors of cache tag field */
#define ERRCTRL_ECCCT_CTCU                       0x03                           /* ECC errors of cache tag field */
#define ERRCTRL_ECCPKCTCM_PKCTCMNE               0x00                           /* ECC errors of PKC TCM */
#define ERRCTRL_ECCPKCTCM_PKCTCMCE               0x01                           /* ECC errors of PKC TCM */
#define ERRCTRL_ECCPKCTCM_PKCTCMUE               0x02                           /* ECC errors of PKC TCM */
#define ERRCTRL_ECCPKCTCM_PKCTCMCU               0x03                           /* ECC errors of PKC TCM */
#define ERRCTRL_ECCPKCSCM_PKCSCMNE               0x00                           /* ECC errors of PKC SCM */
#define ERRCTRL_ECCPKCSCM_PKCSCMCE               0x01                           /* ECC errors of PKC SCM */
#define ERRCTRL_ECCPKCSCM_PKCSCMUE               0x02                           /* ECC errors of PKC SCM */
#define ERRCTRL_ECCPKCSCM_PKCSCMCU               0x03                           /* ECC errors of PKC SCM */
#define ERRCTRL_ECCPKCROM_PKCROMNE               0x00                           /* ECC errors of PKC ROM */
#define ERRCTRL_ECCPKCROM_PKCROMCE               0x01                           /* ECC errors of PKC ROM */
#define ERRCTRL_ECCPKCROM_PKCROMUE               0x02                           /* ECC errors of PKC ROM */
#define ERRCTRL_ECCPKCROM_PKCROMCU               0x03                           /* ECC errors of PKC ROM */
#define ERRCTRL_ROMON_ROFF                       0x00                           /* ROM switch */
#define ERRCTRL_ROMON_RON1                       0x01                           /* ROM switch */
#define ERRCTRL_ROMON_RON2                       0x02                           /* ROM switch */
#define ERRCTRL_ROMON_RON3                       0x03                           /* ROM switch */
#define ERRCTRL_XDBG_XDDIS                       0x00                           /* External Debugger */
#define ERRCTRL_XDBG_XDEN                        0x01                           /* External Debugger */
#define ERRIE_BERRIE_BERRID                      0x00                           /* Bus Error Interrupt Enable */
#define ERRIE_BERRIE_BERRIE                      0x01                           /* Bus Error Interrupt Enable */
#define ERRIE_ECCROMIE_ROMECCID                  0x00                           /* ECC errors of HSM boot ROM Interrupt Enable */
#define ERRIE_ECCROMIE_ROMCEIE                   0x01                           /* ECC errors of HSM boot ROM Interrupt Enable */
#define ERRIE_ECCROMIE_ROMUEIE                   0x02                           /* ECC errors of HSM boot ROM Interrupt Enable */
#define ERRIE_ECCROMIE_ROMCUIE                   0x03                           /* ECC errors of HSM boot ROM Interrupt Enable */
#define ERRIE_ECCRAMIE_RAMECCID                  0x00                           /* ECC errors of Local RAM Interrupt Enable */
#define ERRIE_ECCRAMIE_RAMCEIE                   0x01                           /* ECC errors of Local RAM Interrupt Enable */
#define ERRIE_ECCRAMIE_RAMUEIE                   0x02                           /* ECC errors of Local RAM Interrupt Enable */
#define ERRIE_ECCRAMIE_RAMCUIE                   0x03                           /* ECC errors of Local RAM Interrupt Enable */
#define ERRIE_ADRAMIE_RAMADID                    0x00                           /* Address Error of Local RAM Interrupt Enable */
#define ERRIE_ADRAMIE_RAMADIE                    0x01                           /* Address Error of Local RAM Interrupt Enable */
#define ERRIE_ECCCDIE_CDEDDID                    0x00                           /* ECC errors of cache data Interrupt Enable */
#define ERRIE_ECCCDIE_CDCEIE                     0x01                           /* ECC errors of cache data Interrupt Enable */
#define ERRIE_ECCCDIE_CDUEIE                     0x02                           /* ECC errors of cache data Interrupt Enable */
#define ERRIE_ECCCDIE_CDCUIE                     0x03                           /* ECC errors of cache data Interrupt Enable */
#define ERRIE_ADCDIE_CDADID                      0x00                           /* Address Error of cache data Interrupt Enable */
#define ERRIE_ADCDIE_CDADIE                      0x01                           /* Address Error of cache data Interrupt Enable */
#define ERRIE_ECCCTIE_CTEDDID                    0x00                           /* ECC errors of cache tag field Interrupt Enable */
#define ERRIE_ECCCTIE_CTCEIE                     0x01                           /* ECC errors of cache tag field Interrupt Enable */
#define ERRIE_ECCCTIE_CTUEIE                     0x02                           /* ECC errors of cache tag field Interrupt Enable */
#define ERRIE_ECCCTIE_CTCUIE                     0x03                           /* ECC errors of cache tag field Interrupt Enable */
#define ERRIE_ADCTIE_CTADID                      0x00                           /* Address Error of cache tag field Interrupt Enable */
#define ERRIE_ADCTIE_CTADIE                      0x01                           /* Address Error of cache tag field Interrupt Enable */
#define ERRIE_ECCPKCTCMIE_PKCTCMECCID            0x00                           /* ECC errors of PKC TCM Interrupt Enable */
#define ERRIE_ECCPKCTCMIE_PKCTCMCEIE             0x01                           /* ECC errors of PKC TCM Interrupt Enable */
#define ERRIE_ECCPKCTCMIE_PKCTCMUEIE             0x02                           /* ECC errors of PKC TCM Interrupt Enable */
#define ERRIE_ECCPKCTCMIE_PKCTCMCUIE             0x03                           /* ECC errors of PKC TCM Interrupt Enable */
#define ERRIE_ADPKCTCMIE_PKCTCMADID              0x00                           /* Address Error of PKC TCM Interrupt Enable */
#define ERRIE_ADPKCTCMIE_PKCTCMADIE              0x01                           /* Address Error of PKC TCM Interrupt Enable */
#define ERRIE_ECCPKCSCMIE_PKCSCMECCID            0x00                           /* ECC errors of PKC SCM Interrupt Enable */
#define ERRIE_ECCPKCSCMIE_PKCSCMCEIE             0x01                           /* ECC errors of PKC SCM Interrupt Enable */
#define ERRIE_ECCPKCSCMIE_PKCSCMUEIE             0x02                           /* ECC errors of PKC SCM Interrupt Enable */
#define ERRIE_ECCPKCSCMIE_PKCSCMCUIE             0x03                           /* ECC errors of PKC SCM Interrupt Enable */
#define ERRIE_ADPKCSCMIE_PKCSCMADID              0x00                           /* Address Error of PKC SCM Interrupt Enable */
#define ERRIE_ADPKCSCMIE_PKCSCMADIE              0x01                           /* Address Error of PKC SCM Interrupt Enable */
#define ERRIE_ECCPKCROMIE_PKCROMECCID            0x00                           /* ECC errors of PKC ROM Interrupt Enable */
#define ERRIE_ECCPKCROMIE_PKCROMCEIE             0x01                           /* ECC errors of PKC ROM Interrupt Enable */
#define ERRIE_ECCPKCROMIE_PKCROMUEIE             0x02                           /* ECC errors of PKC ROM Interrupt Enable */
#define ERRIE_ECCPKCROMIE_PKCROMCUIE             0x03                           /* ECC errors of PKC ROM Interrupt Enable */
#define SAHBASE_BASE_SAHOFF                      0x00                           /* Base Address. */


#endif  /* __BRIDGE_HSM_H__ */

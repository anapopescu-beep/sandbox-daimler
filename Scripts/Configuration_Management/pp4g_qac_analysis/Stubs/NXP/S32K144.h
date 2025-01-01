/*
** ###################################################################
**     Processor:           S32K144_100
**     Reference manual:    S32K14XRM Rev. 2, 02/2017
**     Version:             rev. 2.8, 2017-03-27
**     Build:               b170328
**
**     Abstract:
**         Peripheral Access Layer for S32K144
**
**     Copyright (c) 1997 - 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2017 NXP
**     All rights reserved.
**
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-04-09) - Iulian Talpiga
**         Initial version.
**     - rev. 1.1 (2015-05-19) - Bogdan Nitu
**         Updated interrupts table
**         Removed SIM_CHIPCTL_DAC2CMP
**         Compacted PORT_PCR registers
**         Compacted PCC registers
**     - rev. 1.2 (2015-06-02) - Bogdan Nitu
**         Added 'U' suffix to all integer constants
**         Use "" instead of <> for Platform type inclusion
**         CNT register from WDOG module is RW
**     - rev. 1.3 (2015-08-05) - Iulian Talpiga
**         Synchronized with latest RDP
**         Removed OSC32 module
**         Removed reserved registers
**         Incorporated bit band acces macros
**         Switched to standard C99 data types
**         Added 'u' to constants
**         Added size defines for register arrays
**         Define peripheral instance count
**     - rev. 1.4 (2015-08-10) - Iulian Talpiga
**         Compacted TRGMUX registers
**         Defined array index offsets for PCC and TRGMUX
**         Added FPU registers
**         Group FTM channel registers
**         Added interrupt information to peripherals
**         Renamed CAN interrupts according  to the reference manual
**         Added author information to revisions
**     - rev. 1.5 (2015-09-16) - Iulian Talpiga
**         Renamed NVIC and SCB to avoid conflict
**         Compacted CAN Wake-up Message buffers
**         Added CAN embedded RAM
**         Updated interrupts: LPIT, FTFE, LPUART,ACMP
**         Corrected ADC_SC1_ADCH_WIDTH
**         Compacted PDB registers
**         Corrected CAN, FTM, and PDB count defines
**         Guarding register acces macro against redefintion
**     - rev. 1.6 (2015-09-29) - Iulian Talpiga
**         Added WATER and FIFO registers to LPUART.
**     - rev. 1.7 (2015-10-21) - Iulian Talpiga
**         Updated ADC, AIPS, CMP, LMEM, LPTMR, PMC, PORT, RCM, RTC, SCG, SIM
**         Compacted MPU and LPIT
**         Added FSL_SysTick
**         Updated doxygen documentation grouping
**         Updated interrupts: RCM
**     - rev. 1.8 (2016-01-06) - Iulian Talpiga
**         Updated DMA, compacted TCD registers
**         Updated SCG, removed SC2P - SC16P
**         Added 8 and 16 bit access to DATA register, CRC module
**     - rev. 1.9 (2016-02-15) - Iulian Talpiga
**         Updated CRC, renamed DATA union
**         Updated PMC, added CLKBIASDIS bitfield
**         Added FSL_NVIC registers to SVD
**     - rev. 2.0 (2016-04-07) - Iulian Talpiga
**         Updated support for Rev2.0 silicon (0N47T)
**         Updated ADC, AIPS, DMA, FlexIO, FTM, GPIO, LPI2C, LPIT, LPSPI, MCM, MPU, MSCM, PMC, RTC, RCM, PCC, RTC, SCG, SIM, TRGMUX and WDOG  module
**         Updated interrupts
**         Added EIM and ERM modules
**         Added EIM and ERM modules
**     - rev. 2.1 (2016-06-10) - Iulian Talpiga
**         Updated to latest RM
**         Minor changes to: CAN, EIM, LPI2C, MPU, PCC, PMC, RTC, SIM and TRGMUX
**     - rev. 2.2 (2016-08-02) - Iulian Talpiga
**         Updated to latest RM
**         Minor changes to: ADC, CAN, CRC, FTFC, LMEM, LPI2C, MCM, MSCM, PCC, RTC, SIM
**         Added CSE_PRAM
**     - rev. 2.3 (2016-09-09) - Iulian Talpiga
**         Updated to latest RM
**         Minor changes to: PCC, FSL_NVIC and FTM
**     - rev. 2.4 (2016-09-28) - Iulian Talpiga
**         Fix RAMn array size in FlexCAN
**         Fix FCSESTAT bit order
**         Added CP0CFG0, CP0CFG1,CP0CFG2 and CP0CFG3 in MSCM
**         Fixed STIR register in FSL_NVIC
**         Fixed SHPR3 and ACTLR registers in FSL_SCB
**     - rev. 2.5 (2016-11-25) - Iulian Talpiga
**         Fix FRAC bit-field in PCC module
**         Removed BITBAND_ACCESS macros
**         Added MISRA declarations
**         Updated copyright
**         Changed prefix of NVIC, SCB and SysTick to S32_
**     - rev. 2.6 (2017-01-09) - Iulian Talpiga
**         Fix interrupts for CAN, LPUART, FTFC
**     - rev. 2.7 (2017-02-22) - Iulian Talpiga
**         Update header as per rev S32K14XRM Rev. 2, 02/2017
**         Updated modules AIPS, CAN, LPI2C, LPSPI, MCM, MPU, SCG and SIM
**     - rev. 2.8 (2017-03-27) - Iulian Talpiga
**         Synchronized PCC_FlexIO on S32K Family
**
** ###################################################################
*/

/*!
 * @file S32K144.h
 * @version 2.8
 * @date 2017-03-27
 * @brief Peripheral Access Layer for S32K144
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Prevention from multiple including the same memory map */
#if !defined(S32K144_H_)  /* Check if memory map has not been already included */
#define S32K144_H_

#include "Std_Types.h"

/* ----------------------------------------------------------------------------
   -- Generic macros
   ---------------------------------------------------------------------------- */
   
/* IO definitions (access restrictions to peripheral registers) */
/**
*   IO Type Qualifiers are used
*   \li to specify the access to peripheral variables.
*   \li for automatic generation of peripheral register debug information.
*/
#ifndef __IO
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */
#endif

/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers for S32K144
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer for S32K144
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- AIPS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- AIPS Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- CAN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- CAN Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- CMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- CMP Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- CRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */
   
/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- CSE_PRAM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- CSE_PRAM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- DMAMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- EIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- EIM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- ERM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- ERM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- EWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- EWM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- FLEXIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- FLEXIO Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- FTFC Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/*!
 * @addtogroup FTFC_Peripheral_Access_Layer FTFC Peripheral Access Layer
 * @{
 */


/** FTFC - Size of Registers Arrays */
#define FTFC_FCCOB_COUNT                         12u
#define FTFC_FPROT_COUNT                         4u

/** FTFC - Register Layout Typedef */
typedef struct {
  __IO uint8 FSTAT;                              /**< Flash Status Register, offset: 0x0 */
  __IO uint8 FCNFG;                              /**< Flash Configuration Register, offset: 0x1 */
  __I  uint8 FSEC;                               /**< Flash Security Register, offset: 0x2 */
  __I  uint8 FOPT;                               /**< Flash Option Register, offset: 0x3 */
  __IO uint8 FCCOB[FTFC_FCCOB_COUNT];            /**< Flash Common Command Object Registers, array offset: 0x4, array step: 0x1 */
  __IO uint8 FPROT[FTFC_FPROT_COUNT];            /**< Program Flash Protection Registers, array offset: 0x10, array step: 0x1 */
       uint8 RESERVED_0[2];
  __IO uint8 FEPROT;                             /**< EEPROM Protection Register, offset: 0x16 */
  __IO uint8 FDPROT;                             /**< Data Flash Protection Register, offset: 0x17 */
       uint8 RESERVED_1[20];
  __I  uint8 FCSESTAT;                           /**< Flash CSEc Status Register, offset: 0x2C */
       uint8 RESERVED_2[1];
  __IO uint8 FERSTAT;                            /**< Flash Error Status Register, offset: 0x2E */
  __IO uint8 FERCNFG;                            /**< Flash Error Configuration Register, offset: 0x2F */
} FTFC_Type, *FTFC_MemMapPtr;

 /** Number of instances of the FTFC module. */
#define FTFC_INSTANCE_COUNT                      (1u)


/* FTFC - Peripheral instance base addresses */
/** Peripheral FTFC base address */
#define FTFC_BASE                                (0x40020000u)
/** Peripheral FTFC base pointer */
#define FTFC                                     ((FTFC_Type *)FTFC_BASE)
/** Array initializer of FTFC peripheral base addresses */
#define FTFC_BASE_ADDRS                          { FTFC_BASE }
/** Array initializer of FTFC peripheral base pointers */
#define FTFC_BASE_PTRS                           { FTFC }
 /** Number of interrupt vector arrays for the FTFC module. */
#define FTFC_IRQS_ARR_COUNT                      (2u)
 /** Number of interrupt channels for the COMMAND_COMPLETE type of FTFC module. */
#define FTFC_COMMAND_COMPLETE_IRQS_CH_COUNT      (1u)
 /** Number of interrupt channels for the READ_COLLISION type of FTFC module. */
#define FTFC_READ_COLLISION_IRQS_CH_COUNT        (1u)
/** Interrupt vectors for the FTFC peripheral type */
#define FTFC_COMMAND_COMPLETE_IRQS               { FTFC_IRQn }
#define FTFC_READ_COLLISION_IRQS                 { Read_Collision_IRQn }
   
/* ----------------------------------------------------------------------------
   -- FTFC Register Masks
   ---------------------------------------------------------------------------- */

   
/*!
 * @addtogroup FTFC_Register_Masks FTFC Register Masks
 * @{
 */

/* FSTAT Bit Fields */
#define FTFC_FSTAT_MGSTAT0_MASK                  0x1u
#define FTFC_FSTAT_MGSTAT0_SHIFT                 0u
#define FTFC_FSTAT_MGSTAT0_WIDTH                 1u
#define FTFC_FSTAT_MGSTAT0(x)                    (((uint8)(((uint8)(x))<<FTFC_FSTAT_MGSTAT0_SHIFT))&FTFC_FSTAT_MGSTAT0_MASK)
#define FTFC_FSTAT_FPVIOL_MASK                   0x10u
#define FTFC_FSTAT_FPVIOL_SHIFT                  4u
#define FTFC_FSTAT_FPVIOL_WIDTH                  1u
#define FTFC_FSTAT_FPVIOL(x)                     (((uint8)(((uint8)(x))<<FTFC_FSTAT_FPVIOL_SHIFT))&FTFC_FSTAT_FPVIOL_MASK)
#define FTFC_FSTAT_ACCERR_MASK                   0x20u
#define FTFC_FSTAT_ACCERR_SHIFT                  5u
#define FTFC_FSTAT_ACCERR_WIDTH                  1u
#define FTFC_FSTAT_ACCERR(x)                     (((uint8)(((uint8)(x))<<FTFC_FSTAT_ACCERR_SHIFT))&FTFC_FSTAT_ACCERR_MASK)
#define FTFC_FSTAT_RDCOLERR_MASK                 0x40u
#define FTFC_FSTAT_RDCOLERR_SHIFT                6u
#define FTFC_FSTAT_RDCOLERR_WIDTH                1u
#define FTFC_FSTAT_RDCOLERR(x)                   (((uint8)(((uint8)(x))<<FTFC_FSTAT_RDCOLERR_SHIFT))&FTFC_FSTAT_RDCOLERR_MASK)
#define FTFC_FSTAT_CCIF_MASK                     0x80u
#define FTFC_FSTAT_CCIF_SHIFT                    7u
#define FTFC_FSTAT_CCIF_WIDTH                    1u
#define FTFC_FSTAT_CCIF(x)                       (((uint8)(((uint8)(x))<<FTFC_FSTAT_CCIF_SHIFT))&FTFC_FSTAT_CCIF_MASK)
/* FCNFG Bit Fields */
#define FTFC_FCNFG_EEERDY_MASK                   0x1u
#define FTFC_FCNFG_EEERDY_SHIFT                  0u
#define FTFC_FCNFG_EEERDY_WIDTH                  1u
#define FTFC_FCNFG_EEERDY(x)                     (((uint8)(((uint8)(x))<<FTFC_FCNFG_EEERDY_SHIFT))&FTFC_FCNFG_EEERDY_MASK)
#define FTFC_FCNFG_RAMRDY_MASK                   0x2u
#define FTFC_FCNFG_RAMRDY_SHIFT                  1u
#define FTFC_FCNFG_RAMRDY_WIDTH                  1u
#define FTFC_FCNFG_RAMRDY(x)                     (((uint8)(((uint8)(x))<<FTFC_FCNFG_RAMRDY_SHIFT))&FTFC_FCNFG_RAMRDY_MASK)
#define FTFC_FCNFG_ERSSUSP_MASK                  0x10u
#define FTFC_FCNFG_ERSSUSP_SHIFT                 4u
#define FTFC_FCNFG_ERSSUSP_WIDTH                 1u
#define FTFC_FCNFG_ERSSUSP(x)                    (((uint8)(((uint8)(x))<<FTFC_FCNFG_ERSSUSP_SHIFT))&FTFC_FCNFG_ERSSUSP_MASK)
#define FTFC_FCNFG_ERSAREQ_MASK                  0x20u
#define FTFC_FCNFG_ERSAREQ_SHIFT                 5u
#define FTFC_FCNFG_ERSAREQ_WIDTH                 1u
#define FTFC_FCNFG_ERSAREQ(x)                    (((uint8)(((uint8)(x))<<FTFC_FCNFG_ERSAREQ_SHIFT))&FTFC_FCNFG_ERSAREQ_MASK)
#define FTFC_FCNFG_RDCOLLIE_MASK                 0x40u
#define FTFC_FCNFG_RDCOLLIE_SHIFT                6u
#define FTFC_FCNFG_RDCOLLIE_WIDTH                1u
#define FTFC_FCNFG_RDCOLLIE(x)                   (((uint8)(((uint8)(x))<<FTFC_FCNFG_RDCOLLIE_SHIFT))&FTFC_FCNFG_RDCOLLIE_MASK)
#define FTFC_FCNFG_CCIE_MASK                     0x80u
#define FTFC_FCNFG_CCIE_SHIFT                    7u
#define FTFC_FCNFG_CCIE_WIDTH                    1u
#define FTFC_FCNFG_CCIE(x)                       (((uint8)(((uint8)(x))<<FTFC_FCNFG_CCIE_SHIFT))&FTFC_FCNFG_CCIE_MASK)
/* FSEC Bit Fields */
#define FTFC_FSEC_SEC_MASK                       0x3u
#define FTFC_FSEC_SEC_SHIFT                      0u
#define FTFC_FSEC_SEC_WIDTH                      2u
#define FTFC_FSEC_SEC(x)                         (((uint8)(((uint8)(x))<<FTFC_FSEC_SEC_SHIFT))&FTFC_FSEC_SEC_MASK)
#define FTFC_FSEC_FSLACC_MASK                    0xCu
#define FTFC_FSEC_FSLACC_SHIFT                   2u
#define FTFC_FSEC_FSLACC_WIDTH                   2u
#define FTFC_FSEC_FSLACC(x)                      (((uint8)(((uint8)(x))<<FTFC_FSEC_FSLACC_SHIFT))&FTFC_FSEC_FSLACC_MASK)
#define FTFC_FSEC_MEEN_MASK                      0x30u
#define FTFC_FSEC_MEEN_SHIFT                     4u
#define FTFC_FSEC_MEEN_WIDTH                     2u
#define FTFC_FSEC_MEEN(x)                        (((uint8)(((uint8)(x))<<FTFC_FSEC_MEEN_SHIFT))&FTFC_FSEC_MEEN_MASK)
#define FTFC_FSEC_KEYEN_MASK                     0xC0u
#define FTFC_FSEC_KEYEN_SHIFT                    6u
#define FTFC_FSEC_KEYEN_WIDTH                    2u
#define FTFC_FSEC_KEYEN(x)                       (((uint8)(((uint8)(x))<<FTFC_FSEC_KEYEN_SHIFT))&FTFC_FSEC_KEYEN_MASK)
/* FOPT Bit Fields */
#define FTFC_FOPT_OPT_MASK                       0xFFu
#define FTFC_FOPT_OPT_SHIFT                      0u
#define FTFC_FOPT_OPT_WIDTH                      8u
#define FTFC_FOPT_OPT(x)                         (((uint8)(((uint8)(x))<<FTFC_FOPT_OPT_SHIFT))&FTFC_FOPT_OPT_MASK)
/* FCCOB Bit Fields */
#define FTFC_FCCOB_CCOBn_MASK                    0xFFu
#define FTFC_FCCOB_CCOBn_SHIFT                   0u
#define FTFC_FCCOB_CCOBn_WIDTH                   8u
#define FTFC_FCCOB_CCOBn(x)                      (((uint8)(((uint8)(x))<<FTFC_FCCOB_CCOBn_SHIFT))&FTFC_FCCOB_CCOBn_MASK)
/* FPROT Bit Fields */
#define FTFC_FPROT_PROT_MASK                     0xFFu
#define FTFC_FPROT_PROT_SHIFT                    0u
#define FTFC_FPROT_PROT_WIDTH                    8u
#define FTFC_FPROT_PROT(x)                       (((uint8)(((uint8)(x))<<FTFC_FPROT_PROT_SHIFT))&FTFC_FPROT_PROT_MASK)
/* FEPROT Bit Fields */
#define FTFC_FEPROT_EPROT_MASK                   0xFFu
#define FTFC_FEPROT_EPROT_SHIFT                  0u
#define FTFC_FEPROT_EPROT_WIDTH                  8u
#define FTFC_FEPROT_EPROT(x)                     (((uint8)(((uint8)(x))<<FTFC_FEPROT_EPROT_SHIFT))&FTFC_FEPROT_EPROT_MASK)
/* FDPROT Bit Fields */
#define FTFC_FDPROT_DPROT_MASK                   0xFFu
#define FTFC_FDPROT_DPROT_SHIFT                  0u
#define FTFC_FDPROT_DPROT_WIDTH                  8u
#define FTFC_FDPROT_DPROT(x)                     (((uint8)(((uint8)(x))<<FTFC_FDPROT_DPROT_SHIFT))&FTFC_FDPROT_DPROT_MASK)
/* FCSESTAT Bit Fields */
#define FTFC_FCSESTAT_BSY_MASK                   0x1u
#define FTFC_FCSESTAT_BSY_SHIFT                  0u
#define FTFC_FCSESTAT_BSY_WIDTH                  1u
#define FTFC_FCSESTAT_BSY(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_BSY_SHIFT))&FTFC_FCSESTAT_BSY_MASK)
#define FTFC_FCSESTAT_SB_MASK                    0x2u
#define FTFC_FCSESTAT_SB_SHIFT                   1u
#define FTFC_FCSESTAT_SB_WIDTH                   1u
#define FTFC_FCSESTAT_SB(x)                      (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_SB_SHIFT))&FTFC_FCSESTAT_SB_MASK)
#define FTFC_FCSESTAT_BIN_MASK                   0x4u
#define FTFC_FCSESTAT_BIN_SHIFT                  2u
#define FTFC_FCSESTAT_BIN_WIDTH                  1u
#define FTFC_FCSESTAT_BIN(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_BIN_SHIFT))&FTFC_FCSESTAT_BIN_MASK)
#define FTFC_FCSESTAT_BFN_MASK                   0x8u
#define FTFC_FCSESTAT_BFN_SHIFT                  3u
#define FTFC_FCSESTAT_BFN_WIDTH                  1u
#define FTFC_FCSESTAT_BFN(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_BFN_SHIFT))&FTFC_FCSESTAT_BFN_MASK)
#define FTFC_FCSESTAT_BOK_MASK                   0x10u
#define FTFC_FCSESTAT_BOK_SHIFT                  4u
#define FTFC_FCSESTAT_BOK_WIDTH                  1u
#define FTFC_FCSESTAT_BOK(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_BOK_SHIFT))&FTFC_FCSESTAT_BOK_MASK)
#define FTFC_FCSESTAT_RIN_MASK                   0x20u
#define FTFC_FCSESTAT_RIN_SHIFT                  5u
#define FTFC_FCSESTAT_RIN_WIDTH                  1u
#define FTFC_FCSESTAT_RIN(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_RIN_SHIFT))&FTFC_FCSESTAT_RIN_MASK)
#define FTFC_FCSESTAT_EDB_MASK                   0x40u
#define FTFC_FCSESTAT_EDB_SHIFT                  6u
#define FTFC_FCSESTAT_EDB_WIDTH                  1u
#define FTFC_FCSESTAT_EDB(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_EDB_SHIFT))&FTFC_FCSESTAT_EDB_MASK)
#define FTFC_FCSESTAT_IDB_MASK                   0x80u
#define FTFC_FCSESTAT_IDB_SHIFT                  7u
#define FTFC_FCSESTAT_IDB_WIDTH                  1u
#define FTFC_FCSESTAT_IDB(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_IDB_SHIFT))&FTFC_FCSESTAT_IDB_MASK)
/* FERSTAT Bit Fields */
#define FTFC_FERSTAT_DFDIF_MASK                  0x2u
#define FTFC_FERSTAT_DFDIF_SHIFT                 1u
#define FTFC_FERSTAT_DFDIF_WIDTH                 1u
#define FTFC_FERSTAT_DFDIF(x)                    (((uint8)(((uint8)(x))<<FTFC_FERSTAT_DFDIF_SHIFT))&FTFC_FERSTAT_DFDIF_MASK)
/* FERCNFG Bit Fields */
#define FTFC_FERCNFG_DFDIE_MASK                  0x2u
#define FTFC_FERCNFG_DFDIE_SHIFT                 1u
#define FTFC_FERCNFG_DFDIE_WIDTH                 1u
#define FTFC_FERCNFG_DFDIE(x)                    (((uint8)(((uint8)(x))<<FTFC_FERCNFG_DFDIE_SHIFT))&FTFC_FERCNFG_DFDIE_MASK)
#define FTFC_FERCNFG_FDFD_MASK                   0x20u
#define FTFC_FERCNFG_FDFD_SHIFT                  5u
#define FTFC_FERCNFG_FDFD_WIDTH                  1u
#define FTFC_FERCNFG_FDFD(x)                     (((uint8)(((uint8)(x))<<FTFC_FERCNFG_FDFD_SHIFT))&FTFC_FERCNFG_FDFD_MASK)

/*!
 * @}
 */ /* end of group FTFC_Register_Masks */


/*!
 * @}
 */ /* end of group FTFC_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- FTM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- FTM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LMEM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LMEM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LPI2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */


/* ----------------------------------------------------------------------------
   -- LPI2C Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LPIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */
   
/*!
 * @addtogroup LPIT_Peripheral_Access_Layer LPIT Peripheral Access Layer
 * @{
 */


/** LPIT - Size of Registers Arrays */
#define LPIT_TMR_COUNT                           4u

/** LPIT - Register Layout Typedef */
typedef struct {
  __I  uint32 VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32 PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32 MCR;                               /**< Module Control Register, offset: 0x8 */
  __IO uint32 MSR;                               /**< Module Status Register, offset: 0xC */
  __IO uint32 MIER;                              /**< Module Interrupt Enable Register, offset: 0x10 */
  __IO uint32 SETTEN;                            /**< Set Timer Enable Register, offset: 0x14 */
  __IO uint32 CLRTEN;                            /**< Clear Timer Enable Register, offset: 0x18 */
       uint8 RESERVED_0[4];
  struct {                                         /* offset: 0x20, array step: 0x10 */
    __IO uint32 TVAL;                              /**< Timer Value Register, array offset: 0x20, array step: 0x10 */
    __I  uint32 CVAL;                              /**< Current Timer Value, array offset: 0x24, array step: 0x10 */
    __IO uint32 TCTRL;                             /**< Timer Control Register, array offset: 0x28, array step: 0x10 */
         uint8 RESERVED_0[4];
  } TMR[LPIT_TMR_COUNT];
} LPIT_Type, *LPIT_MemMapPtr;

 /** Number of instances of the LPIT module. */
#define LPIT_INSTANCE_COUNT                      (1u)


/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT0 base address */
#define LPIT0_BASE                               (0x40037000u)
/** Peripheral LPIT0 base pointer */
#define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { LPIT0_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { LPIT0 }
 /** Number of interrupt vector arrays for the LPIT module. */
#define LPIT_IRQS_ARR_COUNT                      (1u)
 /** Number of interrupt channels for the LPIT module. */
#define LPIT_IRQS_CH_COUNT                       (4u)
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { LPIT0_Ch0_IRQn, LPIT0_Ch1_IRQn, LPIT0_Ch2_IRQn, LPIT0_Ch3_IRQn }

   
/* ----------------------------------------------------------------------------
   -- LPIT Register Masks
   ---------------------------------------------------------------------------- */

   
/*!
 * @addtogroup LPIT_Register_Masks LPIT Register Masks
 * @{
 */

/* VERID Bit Fields */
#define LPIT_VERID_FEATURE_MASK                  0xFFFFu
#define LPIT_VERID_FEATURE_SHIFT                 0u
#define LPIT_VERID_FEATURE_WIDTH                 16u
#define LPIT_VERID_FEATURE(x)                    (((uint32)(((uint32)(x))<<LPIT_VERID_FEATURE_SHIFT))&LPIT_VERID_FEATURE_MASK)
#define LPIT_VERID_MINOR_MASK                    0xFF0000u
#define LPIT_VERID_MINOR_SHIFT                   16u
#define LPIT_VERID_MINOR_WIDTH                   8u
#define LPIT_VERID_MINOR(x)                      (((uint32)(((uint32)(x))<<LPIT_VERID_MINOR_SHIFT))&LPIT_VERID_MINOR_MASK)
#define LPIT_VERID_MAJOR_MASK                    0xFF000000u
#define LPIT_VERID_MAJOR_SHIFT                   24u
#define LPIT_VERID_MAJOR_WIDTH                   8u
#define LPIT_VERID_MAJOR(x)                      (((uint32)(((uint32)(x))<<LPIT_VERID_MAJOR_SHIFT))&LPIT_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define LPIT_PARAM_CHANNEL_MASK                  0xFFu
#define LPIT_PARAM_CHANNEL_SHIFT                 0u
#define LPIT_PARAM_CHANNEL_WIDTH                 8u
#define LPIT_PARAM_CHANNEL(x)                    (((uint32)(((uint32)(x))<<LPIT_PARAM_CHANNEL_SHIFT))&LPIT_PARAM_CHANNEL_MASK)
#define LPIT_PARAM_EXT_TRIG_MASK                 0xFF00u
#define LPIT_PARAM_EXT_TRIG_SHIFT                8u
#define LPIT_PARAM_EXT_TRIG_WIDTH                8u
#define LPIT_PARAM_EXT_TRIG(x)                   (((uint32)(((uint32)(x))<<LPIT_PARAM_EXT_TRIG_SHIFT))&LPIT_PARAM_EXT_TRIG_MASK)
/* MCR Bit Fields */
#define LPIT_MCR_M_CEN_MASK                      0x1u
#define LPIT_MCR_M_CEN_SHIFT                     0u
#define LPIT_MCR_M_CEN_WIDTH                     1u
#define LPIT_MCR_M_CEN(x)                        (((uint32)(((uint32)(x))<<LPIT_MCR_M_CEN_SHIFT))&LPIT_MCR_M_CEN_MASK)
#define LPIT_MCR_SW_RST_MASK                     0x2u
#define LPIT_MCR_SW_RST_SHIFT                    1u
#define LPIT_MCR_SW_RST_WIDTH                    1u
#define LPIT_MCR_SW_RST(x)                       (((uint32)(((uint32)(x))<<LPIT_MCR_SW_RST_SHIFT))&LPIT_MCR_SW_RST_MASK)
#define LPIT_MCR_DOZE_EN_MASK                    0x4u
#define LPIT_MCR_DOZE_EN_SHIFT                   2u
#define LPIT_MCR_DOZE_EN_WIDTH                   1u
#define LPIT_MCR_DOZE_EN(x)                      (((uint32)(((uint32)(x))<<LPIT_MCR_DOZE_EN_SHIFT))&LPIT_MCR_DOZE_EN_MASK)
#define LPIT_MCR_DBG_EN_MASK                     0x8u
#define LPIT_MCR_DBG_EN_SHIFT                    3u
#define LPIT_MCR_DBG_EN_WIDTH                    1u
#define LPIT_MCR_DBG_EN(x)                       (((uint32)(((uint32)(x))<<LPIT_MCR_DBG_EN_SHIFT))&LPIT_MCR_DBG_EN_MASK)
/* MSR Bit Fields */
#define LPIT_MSR_TIF0_MASK                       0x1u
#define LPIT_MSR_TIF0_SHIFT                      0u
#define LPIT_MSR_TIF0_WIDTH                      1u
#define LPIT_MSR_TIF0(x)                         (((uint32)(((uint32)(x))<<LPIT_MSR_TIF0_SHIFT))&LPIT_MSR_TIF0_MASK)
#define LPIT_MSR_TIF1_MASK                       0x2u
#define LPIT_MSR_TIF1_SHIFT                      1u
#define LPIT_MSR_TIF1_WIDTH                      1u
#define LPIT_MSR_TIF1(x)                         (((uint32)(((uint32)(x))<<LPIT_MSR_TIF1_SHIFT))&LPIT_MSR_TIF1_MASK)
#define LPIT_MSR_TIF2_MASK                       0x4u
#define LPIT_MSR_TIF2_SHIFT                      2u
#define LPIT_MSR_TIF2_WIDTH                      1u
#define LPIT_MSR_TIF2(x)                         (((uint32)(((uint32)(x))<<LPIT_MSR_TIF2_SHIFT))&LPIT_MSR_TIF2_MASK)
#define LPIT_MSR_TIF3_MASK                       0x8u
#define LPIT_MSR_TIF3_SHIFT                      3u
#define LPIT_MSR_TIF3_WIDTH                      1u
#define LPIT_MSR_TIF3(x)                         (((uint32)(((uint32)(x))<<LPIT_MSR_TIF3_SHIFT))&LPIT_MSR_TIF3_MASK)
/* MIER Bit Fields */
#define LPIT_MIER_TIE0_MASK                      0x1u
#define LPIT_MIER_TIE0_SHIFT                     0u
#define LPIT_MIER_TIE0_WIDTH                     1u
#define LPIT_MIER_TIE0(x)                        (((uint32)(((uint32)(x))<<LPIT_MIER_TIE0_SHIFT))&LPIT_MIER_TIE0_MASK)
#define LPIT_MIER_TIE1_MASK                      0x2u
#define LPIT_MIER_TIE1_SHIFT                     1u
#define LPIT_MIER_TIE1_WIDTH                     1u
#define LPIT_MIER_TIE1(x)                        (((uint32)(((uint32)(x))<<LPIT_MIER_TIE1_SHIFT))&LPIT_MIER_TIE1_MASK)
#define LPIT_MIER_TIE2_MASK                      0x4u
#define LPIT_MIER_TIE2_SHIFT                     2u
#define LPIT_MIER_TIE2_WIDTH                     1u
#define LPIT_MIER_TIE2(x)                        (((uint32)(((uint32)(x))<<LPIT_MIER_TIE2_SHIFT))&LPIT_MIER_TIE2_MASK)
#define LPIT_MIER_TIE3_MASK                      0x8u
#define LPIT_MIER_TIE3_SHIFT                     3u
#define LPIT_MIER_TIE3_WIDTH                     1u
#define LPIT_MIER_TIE3(x)                        (((uint32)(((uint32)(x))<<LPIT_MIER_TIE3_SHIFT))&LPIT_MIER_TIE3_MASK)
/* SETTEN Bit Fields */
#define LPIT_SETTEN_SET_T_EN_0_MASK              0x1u
#define LPIT_SETTEN_SET_T_EN_0_SHIFT             0u
#define LPIT_SETTEN_SET_T_EN_0_WIDTH             1u
#define LPIT_SETTEN_SET_T_EN_0(x)                (((uint32)(((uint32)(x))<<LPIT_SETTEN_SET_T_EN_0_SHIFT))&LPIT_SETTEN_SET_T_EN_0_MASK)
#define LPIT_SETTEN_SET_T_EN_1_MASK              0x2u
#define LPIT_SETTEN_SET_T_EN_1_SHIFT             1u
#define LPIT_SETTEN_SET_T_EN_1_WIDTH             1u
#define LPIT_SETTEN_SET_T_EN_1(x)                (((uint32)(((uint32)(x))<<LPIT_SETTEN_SET_T_EN_1_SHIFT))&LPIT_SETTEN_SET_T_EN_1_MASK)
#define LPIT_SETTEN_SET_T_EN_2_MASK              0x4u
#define LPIT_SETTEN_SET_T_EN_2_SHIFT             2u
#define LPIT_SETTEN_SET_T_EN_2_WIDTH             1u
#define LPIT_SETTEN_SET_T_EN_2(x)                (((uint32)(((uint32)(x))<<LPIT_SETTEN_SET_T_EN_2_SHIFT))&LPIT_SETTEN_SET_T_EN_2_MASK)
#define LPIT_SETTEN_SET_T_EN_3_MASK              0x8u
#define LPIT_SETTEN_SET_T_EN_3_SHIFT             3u
#define LPIT_SETTEN_SET_T_EN_3_WIDTH             1u
#define LPIT_SETTEN_SET_T_EN_3(x)                (((uint32)(((uint32)(x))<<LPIT_SETTEN_SET_T_EN_3_SHIFT))&LPIT_SETTEN_SET_T_EN_3_MASK)
/* CLRTEN Bit Fields */
#define LPIT_CLRTEN_CLR_T_EN_0_MASK              0x1u
#define LPIT_CLRTEN_CLR_T_EN_0_SHIFT             0u
#define LPIT_CLRTEN_CLR_T_EN_0_WIDTH             1u
#define LPIT_CLRTEN_CLR_T_EN_0(x)                (((uint32)(((uint32)(x))<<LPIT_CLRTEN_CLR_T_EN_0_SHIFT))&LPIT_CLRTEN_CLR_T_EN_0_MASK)
#define LPIT_CLRTEN_CLR_T_EN_1_MASK              0x2u
#define LPIT_CLRTEN_CLR_T_EN_1_SHIFT             1u
#define LPIT_CLRTEN_CLR_T_EN_1_WIDTH             1u
#define LPIT_CLRTEN_CLR_T_EN_1(x)                (((uint32)(((uint32)(x))<<LPIT_CLRTEN_CLR_T_EN_1_SHIFT))&LPIT_CLRTEN_CLR_T_EN_1_MASK)
#define LPIT_CLRTEN_CLR_T_EN_2_MASK              0x4u
#define LPIT_CLRTEN_CLR_T_EN_2_SHIFT             2u
#define LPIT_CLRTEN_CLR_T_EN_2_WIDTH             1u
#define LPIT_CLRTEN_CLR_T_EN_2(x)                (((uint32)(((uint32)(x))<<LPIT_CLRTEN_CLR_T_EN_2_SHIFT))&LPIT_CLRTEN_CLR_T_EN_2_MASK)
#define LPIT_CLRTEN_CLR_T_EN_3_MASK              0x8u
#define LPIT_CLRTEN_CLR_T_EN_3_SHIFT             3u
#define LPIT_CLRTEN_CLR_T_EN_3_WIDTH             1u
#define LPIT_CLRTEN_CLR_T_EN_3(x)                (((uint32)(((uint32)(x))<<LPIT_CLRTEN_CLR_T_EN_3_SHIFT))&LPIT_CLRTEN_CLR_T_EN_3_MASK)
/* TMR_TVAL Bit Fields */
#define LPIT_TMR_TVAL_TMR_VAL_MASK               0xFFFFFFFFu
#define LPIT_TMR_TVAL_TMR_VAL_SHIFT              0u
#define LPIT_TMR_TVAL_TMR_VAL_WIDTH              32u
#define LPIT_TMR_TVAL_TMR_VAL(x)                 (((uint32)(((uint32)(x))<<LPIT_TMR_TVAL_TMR_VAL_SHIFT))&LPIT_TMR_TVAL_TMR_VAL_MASK)
/* TMR_CVAL Bit Fields */
#define LPIT_TMR_CVAL_TMR_CUR_VAL_MASK           0xFFFFFFFFu
#define LPIT_TMR_CVAL_TMR_CUR_VAL_SHIFT          0u
#define LPIT_TMR_CVAL_TMR_CUR_VAL_WIDTH          32u
#define LPIT_TMR_CVAL_TMR_CUR_VAL(x)             (((uint32)(((uint32)(x))<<LPIT_TMR_CVAL_TMR_CUR_VAL_SHIFT))&LPIT_TMR_CVAL_TMR_CUR_VAL_MASK)
/* TMR_TCTRL Bit Fields */
#define LPIT_TMR_TCTRL_T_EN_MASK                 0x1u
#define LPIT_TMR_TCTRL_T_EN_SHIFT                0u
#define LPIT_TMR_TCTRL_T_EN_WIDTH                1u
#define LPIT_TMR_TCTRL_T_EN(x)                   (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_T_EN_SHIFT))&LPIT_TMR_TCTRL_T_EN_MASK)
#define LPIT_TMR_TCTRL_CHAIN_MASK                0x2u
#define LPIT_TMR_TCTRL_CHAIN_SHIFT               1u
#define LPIT_TMR_TCTRL_CHAIN_WIDTH               1u
#define LPIT_TMR_TCTRL_CHAIN(x)                  (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_CHAIN_SHIFT))&LPIT_TMR_TCTRL_CHAIN_MASK)
#define LPIT_TMR_TCTRL_MODE_MASK                 0xCu
#define LPIT_TMR_TCTRL_MODE_SHIFT                2u
#define LPIT_TMR_TCTRL_MODE_WIDTH                2u
#define LPIT_TMR_TCTRL_MODE(x)                   (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_MODE_SHIFT))&LPIT_TMR_TCTRL_MODE_MASK)
#define LPIT_TMR_TCTRL_TSOT_MASK                 0x10000u
#define LPIT_TMR_TCTRL_TSOT_SHIFT                16u
#define LPIT_TMR_TCTRL_TSOT_WIDTH                1u
#define LPIT_TMR_TCTRL_TSOT(x)                   (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_TSOT_SHIFT))&LPIT_TMR_TCTRL_TSOT_MASK)
#define LPIT_TMR_TCTRL_TSOI_MASK                 0x20000u
#define LPIT_TMR_TCTRL_TSOI_SHIFT                17u
#define LPIT_TMR_TCTRL_TSOI_WIDTH                1u
#define LPIT_TMR_TCTRL_TSOI(x)                   (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_TSOI_SHIFT))&LPIT_TMR_TCTRL_TSOI_MASK)
#define LPIT_TMR_TCTRL_TROT_MASK                 0x40000u
#define LPIT_TMR_TCTRL_TROT_SHIFT                18u
#define LPIT_TMR_TCTRL_TROT_WIDTH                1u
#define LPIT_TMR_TCTRL_TROT(x)                   (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_TROT_SHIFT))&LPIT_TMR_TCTRL_TROT_MASK)
#define LPIT_TMR_TCTRL_TRG_SRC_MASK              0x800000u
#define LPIT_TMR_TCTRL_TRG_SRC_SHIFT             23u
#define LPIT_TMR_TCTRL_TRG_SRC_WIDTH             1u
#define LPIT_TMR_TCTRL_TRG_SRC(x)                (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_TRG_SRC_SHIFT))&LPIT_TMR_TCTRL_TRG_SRC_MASK)
#define LPIT_TMR_TCTRL_TRG_SEL_MASK              0xF000000u
#define LPIT_TMR_TCTRL_TRG_SEL_SHIFT             24u
#define LPIT_TMR_TCTRL_TRG_SEL_WIDTH             4u
#define LPIT_TMR_TCTRL_TRG_SEL(x)                (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_TRG_SEL_SHIFT))&LPIT_TMR_TCTRL_TRG_SEL_MASK)

/*!
 * @}
 */ /* end of group LPIT_Register_Masks */


/*!
 * @}
 */ /* end of group LPIT_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- LPSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LPSPI Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LPTMR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

   /*!
 * @addtogroup LPTMR_Peripheral_Access_Layer LPTMR Peripheral Access Layer
 * @{
 */


/** LPTMR - Size of Registers Arrays */

/** LPTMR - Register Layout Typedef */
typedef struct {
  __IO uint32 CSR;                               /**< Low Power Timer Control Status Register, offset: 0x0 */
  __IO uint32 PSR;                               /**< Low Power Timer Prescale Register, offset: 0x4 */
  __IO uint32 CMR;                               /**< Low Power Timer Compare Register, offset: 0x8 */
  __IO uint32 CNR;                               /**< Low Power Timer Counter Register, offset: 0xC */
} LPTMR_Type, *LPTMR_MemMapPtr;

 /** Number of instances of the LPTMR module. */
#define LPTMR_INSTANCE_COUNT                     (1u)


/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base address */
#define LPTMR0_BASE                              (0x40040000u)
/** Peripheral LPTMR0 base pointer */
#define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { LPTMR0_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR0 }
 /** Number of interrupt vector arrays for the LPTMR module. */
#define LPTMR_IRQS_ARR_COUNT                     (1u)
 /** Number of interrupt channels for the LPTMR module. */
#define LPTMR_IRQS_CH_COUNT                      (1u)
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_IRQn }

   
/* ----------------------------------------------------------------------------
   -- LPTMR Register Masks
   ---------------------------------------------------------------------------- */

   
/*!
 * @addtogroup LPTMR_Register_Masks LPTMR Register Masks
 * @{
 */

/* CSR Bit Fields */
#define LPTMR_CSR_TEN_MASK                       0x1u
#define LPTMR_CSR_TEN_SHIFT                      0u
#define LPTMR_CSR_TEN_WIDTH                      1u
#define LPTMR_CSR_TEN(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TEN_SHIFT))&LPTMR_CSR_TEN_MASK)
#define LPTMR_CSR_TMS_MASK                       0x2u
#define LPTMR_CSR_TMS_SHIFT                      1u
#define LPTMR_CSR_TMS_WIDTH                      1u
#define LPTMR_CSR_TMS(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TMS_SHIFT))&LPTMR_CSR_TMS_MASK)
#define LPTMR_CSR_TFC_MASK                       0x4u
#define LPTMR_CSR_TFC_SHIFT                      2u
#define LPTMR_CSR_TFC_WIDTH                      1u
#define LPTMR_CSR_TFC(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TFC_SHIFT))&LPTMR_CSR_TFC_MASK)
#define LPTMR_CSR_TPP_MASK                       0x8u
#define LPTMR_CSR_TPP_SHIFT                      3u
#define LPTMR_CSR_TPP_WIDTH                      1u
#define LPTMR_CSR_TPP(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TPP_SHIFT))&LPTMR_CSR_TPP_MASK)
#define LPTMR_CSR_TPS_MASK                       0x30u
#define LPTMR_CSR_TPS_SHIFT                      4u
#define LPTMR_CSR_TPS_WIDTH                      2u
#define LPTMR_CSR_TPS(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK)
#define LPTMR_CSR_TIE_MASK                       0x40u
#define LPTMR_CSR_TIE_SHIFT                      6u
#define LPTMR_CSR_TIE_WIDTH                      1u
#define LPTMR_CSR_TIE(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TIE_SHIFT))&LPTMR_CSR_TIE_MASK)
#define LPTMR_CSR_TCF_MASK                       0x80u
#define LPTMR_CSR_TCF_SHIFT                      7u
#define LPTMR_CSR_TCF_WIDTH                      1u
#define LPTMR_CSR_TCF(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TCF_SHIFT))&LPTMR_CSR_TCF_MASK)
#define LPTMR_CSR_TDRE_MASK                      0x100u
#define LPTMR_CSR_TDRE_SHIFT                     8u
#define LPTMR_CSR_TDRE_WIDTH                     1u
#define LPTMR_CSR_TDRE(x)                        (((uint32)(((uint32)(x))<<LPTMR_CSR_TDRE_SHIFT))&LPTMR_CSR_TDRE_MASK)
/* PSR Bit Fields */
#define LPTMR_PSR_PCS_MASK                       0x3u
#define LPTMR_PSR_PCS_SHIFT                      0u
#define LPTMR_PSR_PCS_WIDTH                      2u
#define LPTMR_PSR_PCS(x)                         (((uint32)(((uint32)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK)
#define LPTMR_PSR_PBYP_MASK                      0x4u
#define LPTMR_PSR_PBYP_SHIFT                     2u
#define LPTMR_PSR_PBYP_WIDTH                     1u
#define LPTMR_PSR_PBYP(x)                        (((uint32)(((uint32)(x))<<LPTMR_PSR_PBYP_SHIFT))&LPTMR_PSR_PBYP_MASK)
#define LPTMR_PSR_PRESCALE_MASK                  0x78u
#define LPTMR_PSR_PRESCALE_SHIFT                 3u
#define LPTMR_PSR_PRESCALE_WIDTH                 4u
#define LPTMR_PSR_PRESCALE(x)                    (((uint32)(((uint32)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK)
/* CMR Bit Fields */
#define LPTMR_CMR_COMPARE_MASK                   0xFFFFu
#define LPTMR_CMR_COMPARE_SHIFT                  0u
#define LPTMR_CMR_COMPARE_WIDTH                  16u
#define LPTMR_CMR_COMPARE(x)                     (((uint32)(((uint32)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK)
/* CNR Bit Fields */
#define LPTMR_CNR_COUNTER_MASK                   0xFFFFu
#define LPTMR_CNR_COUNTER_SHIFT                  0u
#define LPTMR_CNR_COUNTER_WIDTH                  16u
#define LPTMR_CNR_COUNTER(x)                     (((uint32)(((uint32)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK)

/*!
 * @}
 */ /* end of group LPTMR_Register_Masks */


/*!
 * @}
 */ /* end of group LPTMR_Peripheral_Access_Layer */

    
/* ----------------------------------------------------------------------------
   -- LPUART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- LPUART Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- MPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- MPU Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- MSCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- MSCM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- PCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- PCC Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- PDB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- PDB Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

   /*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */


/** PORT - Size of Registers Arrays */
#define PORT_PCR_COUNT                           32u

/** PORT - Register Layout Typedef */
typedef struct {
  __IO uint32 PCR[PORT_PCR_COUNT];               /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
  __O  uint32 GPCLR;                             /**< Global Pin Control Low Register, offset: 0x80 */
  __O  uint32 GPCHR;                             /**< Global Pin Control High Register, offset: 0x84 */
       uint8 RESERVED_0[24];
  __IO uint32 ISFR;                              /**< Interrupt Status Flag Register, offset: 0xA0 */
       uint8 RESERVED_1[28];
  __IO uint32 DFER;                              /**< Digital Filter Enable Register, offset: 0xC0 */
  __IO uint32 DFCR;                              /**< Digital Filter Clock Register, offset: 0xC4 */
  __IO uint32 DFWR;                              /**< Digital Filter Width Register, offset: 0xC8 */
} PORT_Type, *PORT_MemMapPtr;

 /** Number of instances of the PORT module. */
#define PORT_INSTANCE_COUNT                      (5u)


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0x40049000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x4004A000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x4004B000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
/** Peripheral PORTD base address */
#define PORTD_BASE                               (0x4004C000u)
/** Peripheral PORTD base pointer */
#define PORTD                                    ((PORT_Type *)PORTD_BASE)
/** Peripheral PORTE base address */
#define PORTE_BASE                               (0x4004D000u)
/** Peripheral PORTE base pointer */
#define PORTE                                    ((PORT_Type *)PORTE_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD, PORTE }
 /** Number of interrupt vector arrays for the PORT module. */
#define PORT_IRQS_ARR_COUNT                      (1u)
 /** Number of interrupt channels for the PORT module. */
#define PORT_IRQS_CH_COUNT                       (1u)
/** Interrupt vectors for the PORT peripheral type */
#define PORT_IRQS                                { PORTA_IRQn, PORTB_IRQn, PORTC_IRQn, PORTD_IRQn, PORTE_IRQn }

   
/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */


/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/* PCR Bit Fields */
#define PORT_PCR_PS_MASK                         0x1u
#define PORT_PCR_PS_SHIFT                        0u
#define PORT_PCR_PS_WIDTH                        1u
#define PORT_PCR_PS(x)                           (((uint32)(((uint32)(x))<<PORT_PCR_PS_SHIFT))&PORT_PCR_PS_MASK)
#define PORT_PCR_PE_MASK                         0x2u
#define PORT_PCR_PE_SHIFT                        1u
#define PORT_PCR_PE_WIDTH                        1u
#define PORT_PCR_PE(x)                           (((uint32)(((uint32)(x))<<PORT_PCR_PE_SHIFT))&PORT_PCR_PE_MASK)
#define PORT_PCR_PFE_MASK                        0x10u
#define PORT_PCR_PFE_SHIFT                       4u
#define PORT_PCR_PFE_WIDTH                       1u
#define PORT_PCR_PFE(x)                          (((uint32)(((uint32)(x))<<PORT_PCR_PFE_SHIFT))&PORT_PCR_PFE_MASK)
#define PORT_PCR_DSE_MASK                        0x40u
#define PORT_PCR_DSE_SHIFT                       6u
#define PORT_PCR_DSE_WIDTH                       1u
#define PORT_PCR_DSE(x)                          (((uint32)(((uint32)(x))<<PORT_PCR_DSE_SHIFT))&PORT_PCR_DSE_MASK)
#define PORT_PCR_MUX_MASK                        0x700u
#define PORT_PCR_MUX_SHIFT                       8u
#define PORT_PCR_MUX_WIDTH                       3u
#define PORT_PCR_MUX(x)                          (((uint32)(((uint32)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK)
#define PORT_PCR_LK_MASK                         0x8000u
#define PORT_PCR_LK_SHIFT                        15u
#define PORT_PCR_LK_WIDTH                        1u
#define PORT_PCR_LK(x)                           (((uint32)(((uint32)(x))<<PORT_PCR_LK_SHIFT))&PORT_PCR_LK_MASK)
#define PORT_PCR_IRQC_MASK                       0xF0000u
#define PORT_PCR_IRQC_SHIFT                      16u
#define PORT_PCR_IRQC_WIDTH                      4u
#define PORT_PCR_IRQC(x)                         (((uint32)(((uint32)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK)
#define PORT_PCR_ISF_MASK                        0x1000000u
#define PORT_PCR_ISF_SHIFT                       24u
#define PORT_PCR_ISF_WIDTH                       1u
#define PORT_PCR_ISF(x)                          (((uint32)(((uint32)(x))<<PORT_PCR_ISF_SHIFT))&PORT_PCR_ISF_MASK)
/* GPCLR Bit Fields */
#define PORT_GPCLR_GPWD_MASK                     0xFFFFu
#define PORT_GPCLR_GPWD_SHIFT                    0u
#define PORT_GPCLR_GPWD_WIDTH                    16u
#define PORT_GPCLR_GPWD(x)                       (((uint32)(((uint32)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK)
#define PORT_GPCLR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCLR_GPWE_SHIFT                    16u
#define PORT_GPCLR_GPWE_WIDTH                    16u
#define PORT_GPCLR_GPWE(x)                       (((uint32)(((uint32)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK)
/* GPCHR Bit Fields */
#define PORT_GPCHR_GPWD_MASK                     0xFFFFu
#define PORT_GPCHR_GPWD_SHIFT                    0u
#define PORT_GPCHR_GPWD_WIDTH                    16u
#define PORT_GPCHR_GPWD(x)                       (((uint32)(((uint32)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK)
#define PORT_GPCHR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCHR_GPWE_SHIFT                    16u
#define PORT_GPCHR_GPWE_WIDTH                    16u
#define PORT_GPCHR_GPWE(x)                       (((uint32)(((uint32)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK)
/* ISFR Bit Fields */
#define PORT_ISFR_ISF_MASK                       0xFFFFFFFFu
#define PORT_ISFR_ISF_SHIFT                      0u
#define PORT_ISFR_ISF_WIDTH                      32u
#define PORT_ISFR_ISF(x)                         (((uint32)(((uint32)(x))<<PORT_ISFR_ISF_SHIFT))&PORT_ISFR_ISF_MASK)
/* DFER Bit Fields */
#define PORT_DFER_DFE_MASK                       0xFFFFFFFFu
#define PORT_DFER_DFE_SHIFT                      0u
#define PORT_DFER_DFE_WIDTH                      32u
#define PORT_DFER_DFE(x)                         (((uint32)(((uint32)(x))<<PORT_DFER_DFE_SHIFT))&PORT_DFER_DFE_MASK)
/* DFCR Bit Fields */
#define PORT_DFCR_CS_MASK                        0x1u
#define PORT_DFCR_CS_SHIFT                       0u
#define PORT_DFCR_CS_WIDTH                       1u
#define PORT_DFCR_CS(x)                          (((uint32)(((uint32)(x))<<PORT_DFCR_CS_SHIFT))&PORT_DFCR_CS_MASK)
/* DFWR Bit Fields */
#define PORT_DFWR_FILT_MASK                      0x1Fu
#define PORT_DFWR_FILT_SHIFT                     0u
#define PORT_DFWR_FILT_WIDTH                     5u
#define PORT_DFWR_FILT(x)                        (((uint32)(((uint32)(x))<<PORT_DFWR_FILT_SHIFT))&PORT_DFWR_FILT_MASK)

/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/*!
 * @}
 */ /* end of group PORT_Peripheral_Access_Layer */

    
/* ----------------------------------------------------------------------------
   -- RCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- S32_NVIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- S32_NVIC Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- S32_SCB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- S32_SCB Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- S32_SysTick Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- S32_SysTick Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- SCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- SCG Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- SMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- TRGMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- Backward Compatibility for S32K144
   ---------------------------------------------------------------------------- */

#endif  /* #if !defined(S32K144_H_) */

/* S32K144.h, eof. */

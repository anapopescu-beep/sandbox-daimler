/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Crypto_30_Hwa_Hw.c
 *        \brief  vHsm platform hardware abstractions
 *
 *      \details  This implements the hardware access functions which are used by the platform code.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_HW_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Crypto_30_Hwa.h"
#include "Crypto_30_Hwa_Hw.h"
#include "Crypto_30_Hwa_Hw_Cfg.h"
#include "Crypto_30_Hwa_Custom.h"

#include "vHsm.h"
#include "vHsm_Ipc.h"

#include "vstdlib.h"

#include "IFX_HSM.h"
#include "core_cm3.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_HWA_LOCAL) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL                                               static
#endif

#if !defined (CRYPTO_30_HWA_LOCAL_INLINE) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL_INLINE                                        LOCAL_INLINE
#endif

 /* Defines for the AESCTRL register */
#define CRYPTO_30_HWA_AESCTRL_MODE_MASK                               (0xFFFFFFF0u)
#define CRYPTO_30_HWA_AESCTRL_ECB_ENC                                 (0x00000000u)
#define CRYPTO_30_HWA_AESCTRL_CBC_ENC                                 (0x00002000u)
#define CRYPTO_30_HWA_AESCTRL_GCM_ENC                                 (0x00008000u)
#define CRYPTO_30_HWA_AESCTRL_ECB_DEC                                 (0x00001001u)
#define CRYPTO_30_HWA_AESCTRL_CBC_DEC                                 (0x00003001u)
#define CRYPTO_30_HWA_AESCTRL_GCM_DEC                                 (0x00009001u)
#define CRYPTO_30_HWA_AESCTRL_GCM_MAC                                 (0x0000A000u)
#define CRYPTO_30_HWA_AESCTRL_CTR                                     (0x00004000u)
#define CRYPTO_30_HWA_AESCTRL_WK                                      (0x00010000u)
#define CRYPTO_30_HWA_AESCTRL_LK                                      (0x00011000u)
#define CRYPTO_30_HWA_AESCTRL_WCV                                     (0x00012000u)
#define CRYPTO_30_HWA_AESCTRL_RCV                                     (0x00013000u)
#define CRYPTO_30_HWA_AESCTRL_KEY0                                    (0x00000000u)
#define CRYPTO_30_HWA_AESCTRL_KEY1                                    (0x00000010u)
#define CRYPTO_30_HWA_AESCTRL_KEY2                                    (0x00000020u)
#define CRYPTO_30_HWA_AESCTRL_KEY3                                    (0x00000030u)
#define CRYPTO_30_HWA_AESCTRL_KEY4                                    (0x00000040u)
#define CRYPTO_30_HWA_AESCTRL_KEY5                                    (0x00000050u)
#define CRYPTO_30_HWA_AESCTRL_KEY6                                    (0x00000060u)
#define CRYPTO_30_HWA_AESCTRL_KEY7                                    (0x00000070u)
#define CRYPTO_30_HWA_AESCTRL_KEYOLD                                  (0x000001F0u)
#define CRYPTO_30_HWA_AESCTRL_CV0                                     (0x00000000u)
#define CRYPTO_30_HWA_AESCTRL_CV1                                     (0x00000001u)
#define CRYPTO_30_HWA_AESCTRL_CV2                                     (0x00000002u)
#define CRYPTO_30_HWA_AESCTRL_CV3                                     (0x00000003u)
#define CRYPTO_30_HWA_AESCTRL_CV4                                     (0x00000004u)

 /* Defines for the AESSTAT register */
#define CRYPTO_30_HWA_AESSTAT_BIT2                                    (0x00000004u)
#define CRYPTO_30_HWA_AESSTAT_BIT1                                    (0x00000002u)
#define CRYPTO_30_HWA_AESSTAT_BIT0                                    (0x00000001u)
#define CRYPTO_30_HWA_AESSTAT_LOCK1_MASK                              (CRYPTO_30_HWA_AESSTAT_BIT2)
#define CRYPTO_30_HWA_AESSTAT_LOCK1                                   (CRYPTO_30_HWA_AESSTAT_BIT2)
#define CRYPTO_30_HWA_AESSTAT_LOCK0_MASK                              (CRYPTO_30_HWA_AESSTAT_BIT1)
#define CRYPTO_30_HWA_AESSTAT_LOCK0                                   (CRYPTO_30_HWA_AESSTAT_BIT1)
#define CRYPTO_30_HWA_AESSTAT_LOCK_MASK                               (CRYPTO_30_HWA_AESSTAT_BIT2 | CRYPTO_30_HWA_AESSTAT_BIT1)
#define CRYPTO_30_HWA_AESSTAT_LOCK                                    (CRYPTO_30_HWA_AESSTAT_BIT2 | CRYPTO_30_HWA_AESSTAT_BIT1)
#define CRYPTO_30_HWA_AESSTAT_BSY_MASK                                (CRYPTO_30_HWA_AESSTAT_BIT0)
#define CRYPTO_30_HWA_AESSTAT_BSY                                     (CRYPTO_30_HWA_AESSTAT_BIT0)

 /* TRNG status register Definitions */
#define CRYPTO_30_HWA_TRNG_STAT_DTA_RDY_POS                           0u                                                /* TRNG_STAT: DTA_RDY Position */
#define CRYPTO_30_HWA_TRNG_STAT_DTA_RDY_MSK                           (0x1uL << CRYPTO_30_HWA_TRNG_STAT_DTA_RDY_POS)         /* TRNG_STAT: DTA_RDY Mask */
#define CRYPTO_30_HWA_TRNG_STAT_FIPS_ERR_POS                          2u                                                /* TRNG_STAT: FIPS_ERR Position */
#define CRYPTO_30_HWA_TRNG_STAT_FIPS_ERR_MSK                          (0x1uL << CRYPTO_30_HWA_TRNG_STAT_FIPS_ERR_POS)        /* TRNG_STAT: FIPS_ERR Mask */
#define CRYPTO_30_HWA_TRNG_STAT_UNLOCK_FIPS_ERR_POS                   3u                                                /* TRNG_STAT: UNLOCK_FIPS_ERR Position */
#define CRYPTO_30_HWA_TRNG_STAT_UNLOCK_FIPS_ERR_MSK                   (0x1uL << CRYPTO_30_HWA_TRNG_STAT_UNLOCK_FIPS_ERR_POS) /* TRNG_STAT: UNLOCK_FIPS_ERR Mask */
#define CRYPTO_30_HWA_TRNG_STAT_WARN_POS                              9u                                                /* TRNG_STAT: WARN Position */
#define CRYPTO_30_HWA_TRNG_STAT_WARN_MSK                              (0x1uL << CRYPTO_30_HWA_TRNG_STAT_WARN_POS)            /* TRNG_STAT: WARN Mask */
#define CRYPTO_30_HWA_TRNG_STAT_UNLOCK_WARN_POS                       10u                                               /* TRNG_STAT: UNLOCK_WARN Position */
#define CRYPTO_30_HWA_TRNG_STAT_UNLOCK_WARN_MSK                       (0x1uL << CRYPTO_30_HWA_TRNG_STAT_UNLOCK_WARN_POS)     /* TRNG_STAT: UNLOCK_WARN Mask */
 /* TRNG control register Definitions */
#define CRYPTO_30_HWA_TRNG_CTRL_DBS_POS                               0u                                                /* TRNG_CTRL: DBS Position */
#define CRYPTO_30_HWA_TRNG_CTRL_DBS_MSK                               (0x3uL << CRYPTO_30_HWA_TRNG_CTRL_DBS_POS)             /* TRNG_CTRL: DBS Mask */
#define CRYPTO_30_HWA_TRNG_CTRL_DIS_POS                               2u                                                /* TRNG_CTRL: DIS Position */
#define CRYPTO_30_HWA_TRNG_CTRL_DIS_MSK                               (0x1uL << CRYPTO_30_HWA_TRNG_CTRL_DIS_POS)             /* TRNG_CTRL: DIS Mask */
#define CRYPTO_30_HWA_TRNG_CTRL_DIS_DIS                               0x01 /* Disable */

 /* Defines for the PKCCONFIG register */
#define CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET                         (0u)
#define CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET                         (8u)
#define CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET                         (16u)

 /* Defines for the PKCCMD register */
#define CRYPTO_30_HWA_PKCCMD_ADDN                                     (0x00000001u)
#define CRYPTO_30_HWA_PKCCMD_SUBN                                     (0x00000002u)
#define CRYPTO_30_HWA_PKCCMD_MULTN                                    (0x00000003u)
#define CRYPTO_30_HWA_PKCCMD_RED                                      (0x00000004u)
#define CRYPTO_30_HWA_PKCCMD_DIVN                                     (0x00000005u)
#define CRYPTO_30_HWA_PKCCMD_INV                                      (0x00000006u)
#define CRYPTO_30_HWA_PKCCMD_MULT                                     (0x00000008u)
#define CRYPTO_30_HWA_PKCCMD_INV2                                     (0x00000009u)
#define CRYPTO_30_HWA_PKCCMD_RED2                                     (0x0000000Au)
#define CRYPTO_30_HWA_PKCCMD_EXP                                      (0x00000010u)

#define CRYPTO_30_HWA_PKCCMD_PDBL                                     (0x00000020u)
#define CRYPTO_30_HWA_PKCCMD_PADD                                     (0x00000021u)
#define CRYPTO_30_HWA_PKCCMD_SMULT                                    (0x00000022u)
#define CRYPTO_30_HWA_PKCCMD_CHECKAB                                  (0x00000023u)
#define CRYPTO_30_HWA_PKCCMD_CHECKN                                   (0x00000024u)
#define CRYPTO_30_HWA_PKCCMD_CHECKPXY                                 (0x00000025u)
#define CRYPTO_30_HWA_PKCCMD_SMULT25519                               (0x00000028u)
#define CRYPTO_30_HWA_PKCCMD_XRECOVER                                 (0x00000029u)
#define CRYPTO_30_HWA_PKCCMD_SMULTED25519                             (0x0000002Au)
#define CRYPTO_30_HWA_PKCCMD_CHECKVALID                               (0x0000002Bu)

#define CRYPTO_30_HWA_PKCCMD_FIELD_IN_Z                               (0x00000000u)
#define CRYPTO_30_HWA_PKCCMD_FIELD_BINARY_POLYNOM                     (0x00000080u)

#define CRYPTO_30_HWA_PKCCMD_SIZE_64BIT                               (0x00000100u)
#define CRYPTO_30_HWA_PKCCMD_SIZE_128BIT                              (0x00000200u)
#define CRYPTO_30_HWA_PKCCMD_SIZE_192BIT                              (0x00000300u)
#define CRYPTO_30_HWA_PKCCMD_SIZE_256BIT                              (0x00000400u)

#define CRYPTO_30_HWA_PKCCMD_SIGNA_POSITIVE                           (0x00000000u)
#define CRYPTO_30_HWA_PKCCMD_SIGNA_NEGATIVE                           (0x20000000u)

#define CRYPTO_30_HWA_PKCCMD_SIGNB_POSITIVE                           (0x00000000u)
#define CRYPTO_30_HWA_PKCCMD_SIGNB_NEGATIVE                           (0x40000000u)

#define CRYPTO_30_HWA_PKCCMD_CALCR2_NOCALCOP                          (0x00000000u)
#define CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP                            (0x80000000u)

#define CRYPTO_30_HWA_PKCCMD_TYPE_OFFSET                              (0x00u)
#define CRYPTO_30_HWA_PKCCMD_FIELD_OFFSET                             (0x07u)
#define CRYPTO_30_HWA_PKCCMD_SIZE_OFFSET                              (0x08u)
#define CRYPTO_30_HWA_PKCCMD_SIGNA_OFFSET                             (0x1Du)
#define CRYPTO_30_HWA_PKCCMD_SIGNB_OFFSET                             (0x1Eu)
#define CRYPTO_30_HWA_PKCCMD_CALCR2_OFFSET                            (0x1Fu)

 /* Defines for the PKCCTRL register */
#define CRYPTO_30_HWA_PKCCTRL_STARTSIGNAL                             (0x01u)

 /* Defines for the PKCSCM register */
#define CRYPTO_30_HWA_PKCSCM_R0                                       (0x00u)
#define CRYPTO_30_HWA_PKCSCM_R1                                       (0x01u)
#define CRYPTO_30_HWA_PKCSCM_R2                                       (0x02u)
#define CRYPTO_30_HWA_PKCSCM_R3                                       (0x03u)
#define CRYPTO_30_HWA_PKCSCM_R4                                       (0x04u)
#define CRYPTO_30_HWA_PKCSCM_R5                                       (0x05u)
#define CRYPTO_30_HWA_PKCSCM_R6                                       (0x06u)
#define CRYPTO_30_HWA_PKCSCM_R7                                       (0x07u)
#define CRYPTO_30_HWA_PKCSCM_R8                                       (0x08u)
#define CRYPTO_30_HWA_PKCSCM_R9                                       (0x09u)
#define CRYPTO_30_HWA_PKCSCM_R10                                      (0x0Au)
#define CRYPTO_30_HWA_PKCSCM_R11                                      (0x0Bu)
#define CRYPTO_30_HWA_PKCSCM_R12                                      (0x0Cu)
#define CRYPTO_30_HWA_PKCSCM_R13                                      (0x0Du)
#define CRYPTO_30_HWA_PKCSCM_R14                                      (0x0Eu)
#define CRYPTO_30_HWA_PKCSCM_R15                                      (0x0Fu)

#define CRYPTO_30_HWA_PKC_STATUS_BIT0                                 (0u)
#define CRYPTO_30_HWA_PKC_STATUS_BIT1                                 (1u)

#define CRYPTO_30_HWA_PKC_STATUS_FLADD                                (1u)
#define CRYPTO_30_HWA_PKC_STATUS_INFTY                                (32u)
#define CRYPTO_30_HWA_PKC_STATUS_XYNV                                 (64u)
#define CRYPTO_30_HWA_PKC_STATUS_NNV                                  (128u)
#define CRYPTO_30_HWA_PKC_STATUS_SIGNV                                (512u)
#define CRYPTO_30_HWA_PKC_STATUS_ABNV                                 (1024u)
#define CRYPTO_30_HWA_PKC_STATUS_NOTINV                               (2048u)
#define CRYPTO_30_HWA_PKC_STATUS_BUSY                                 (65536u)

#define CRYPTO_30_HWA_PKC_STATUS_FLADD_OFFSET                         (0u)
#define CRYPTO_30_HWA_PKC_STATUS_INFTY_OFFSET                         (5u)
#define CRYPTO_30_HWA_PKC_STATUS_XYNV_OFFSET                          (6u)
#define CRYPTO_30_HWA_PKC_STATUS_NNV_OFFSET                           (7u)
#define CRYPTO_30_HWA_PKC_STATUS_SIGNV_OFFSET                         (9u)
#define CRYPTO_30_HWA_PKC_STATUS_ABNV_OFFSET                          (10u)
#define CRYPTO_30_HWA_PKC_STATUS_NOTINV_OFFSET                        (11u)
#define CRYPTO_30_HWA_PKC_STATUS_BUSY_OFFSET                          (16u)
#define CRYPTO_30_HWA_PKC_STATUS_BSY_MASK                             (CRYPTO_30_HWA_PKC_STATUS_BUSY)
#define CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK                  (0u)
#define CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_INV_INV2                  (2048u)
#define CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_PBDL_PADD_SMULT           (32u)
#define CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_CHECKAB                   (1024u)
#define CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_CHECKN                    (128u)
#define CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_CHECKPXY                  (64u)
#define CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_CHECKVALID                (512u)
#define CRYPTO_30_HWA_PKC_STATUS_NO_ERROR                             (0u)
#define CRYPTO_30_HWA_PKC_STATUS_BSY                                  (CRYPTO_30_HWA_PKC_STATUS_BIT0)

#define CRYPTO_30_HWA_PKC_CTRL_START                                  (1u)

#define CRYPTO_30_HWA_VSECPRIM_HASH_ALGO_INVALID                      (0xFFu)

#ifndef CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL /* COV_CRYPTO_30_HWA_VSECPRIM_HASH_ALGORITHM */
# define CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL              (1u)
#endif

#ifndef CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL_OR_GREATER /* COV_CRYPTO_30_HWA_VSECPRIM_HASH_ALGORITHM */
# define CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL_OR_GREATER   (2u)
#endif

#ifndef CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_TRUNCATION_ALLOWED /* COV_CRYPTO_30_HWA_VSECPRIM_HASH_ALGORITHM */
# define CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_TRUNCATION_ALLOWED        (4u)
#endif

 /* Defines for CMACAES */
#define CRYPTO_30_HWA_AES_CMAC_CONST_RB                               (0x87u)
#define CRYPTO_30_HWA_AES_CMAC_MSB_BITMASK                            (0x80u)
#define CRYPTO_30_HWA_AES_LAST_ELEMENT                                (CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - 1u)
#define CRYPTO_30_HWA_CMAC_TAG_SIZE_BIT                               (128u)

 /* the polynomial is 1+a+a^2+a^7+a^128 => 111000010...01 in little endian representation. */
# define Crypto_30_HWA_GF128POLY                                      (0xE1000000u)
# define Crypto_30_HWA_GHASH_BLOCK_SIZE                               (16u)
# define CRYPTO_30_HWA_CTR_COUNTER_MAX_VALUE                          (0xFFFFFFFFu)

/* Crypto Hwa flash token key element */
#ifndef CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION /* COV_CRYPTO_30_HWA_CUSTOM_KEY_ELEMENTS */
# define CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION                        (3032u)
#endif

/* Crypto Hwa flash token key element values */
#ifndef CRYPTO_30_VHSM_DATAFLASH_START /* COV_CRYPTO_30_HWA_CUSTOM_KEY_ELEMENTS */
#define CRYPTO_30_VHSM_DATAFLASH_START                                (0u)
#endif
#ifndef CRYPTO_30_VHSM_DATAFLASH_STOP /* COV_CRYPTO_30_HWA_CUSTOM_KEY_ELEMENTS */
#define CRYPTO_30_VHSM_DATAFLASH_STOP                                 (1u)
#endif
#ifndef CRYPTO_30_VHSM_CODEFLASH_START /* COV_CRYPTO_30_HWA_CUSTOM_KEY_ELEMENTS */
#define CRYPTO_30_VHSM_CODEFLASH_START                                (2u)
#endif
#ifndef CRYPTO_30_VHSM_CODEFLASH_STOP /* COV_CRYPTO_30_HWA_CUSTOM_KEY_ELEMENTS */
#define CRYPTO_30_VHSM_CODEFLASH_STOP                                 (3u)
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#define MOD_4(x)                                                      ((x) & (4u - 1u)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define DIV_4(x)                                                      ((x) >> 2u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define REG32(x)                                                      (*((volatile uint32 *)(x)))

#define CRYPTO_30_HWA_ESL_RETVAL(x)                                   (uint8)((x == ESL_ERC_NO_ERROR) ? E_OK : E_NOT_OK)

 /* Get the lower word of a ddigit */
# define CRYPTO_30_HWA_BN_LO_WORD(ddigit)                             ((uint32)(ddigit))

 /* Get the higher word of a dword */
# define CRYPTO_30_HWA_BN_HI_WORD(ddigit)                             ((uint32)((ddigit) >> CRYPTO_30_HWA_EDDSA_BN_BITS_PER_DIGIT))

# define CRYPTO_30_HWA_BN_BASE                                        ((uint64)(1) << CRYPTO_30_HWA_EDDSA_BN_BITS_PER_DIGIT)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
# define CRYPTO_30_HWA_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(uint8, CRYPTO_30_HWA_VAR_NOINIT) contextMapping[Crypto_30_Hwa_GetSizeOfObjectInfo()];

VAR(uint8, CRYPTO_30_HWA_VAR_NOINIT) contextMapping[Crypto_30_Hwa_GetSizeOfObjectInfo()];

# define CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON))  /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
#  define CRYPTO_30_HWA_START_SEC_CONST_8BIT
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  if (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)  /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
CRYPTO_30_HWA_LOCAL CONST(uint8, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_Hw_Ed25519CurveParameter[CRYPTO_30_HWA_EDDSA_CURVE_PARAMETER_SIZE_BYTE] = {
  /* curvePrime p*/
  0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xED,

  /* prime38 (p-5)/8 */
  0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD,

  /* curveConst d */
  0x52, 0x03, 0x6C, 0xEE, 0x2B, 0x6F, 0xFE, 0x73, 0x8C, 0xC7, 0x40, 0x79, 0x77, 0x79, 0xE8, 0x98,
  0x00, 0x70, 0x0A, 0x4D, 0x41, 0x41, 0xD8, 0xAB, 0x75, 0xEB, 0x4D, 0xCA, 0x13, 0x59, 0x78, 0xA3,

  /* sqrtM1 J */
  0x2B, 0x83, 0x24, 0x80, 0x4F, 0xC1, 0xDF, 0x0B, 0x2B, 0x4D, 0x00, 0x99, 0x3D, 0xFB, 0xD7, 0xA7,
  0x2F, 0x43, 0x18, 0x06, 0xAD, 0x2F, 0xE4, 0x78, 0xC4, 0xEE, 0x1B, 0x27, 0x4A, 0x0E, 0xA0, 0xB0,

  /* D2 */
  0x59, 0x04, 0x56, 0xB4, 0xE5, 0x3F, 0x8A, 0x4D, 0xCB, 0x27, 0x24, 0x0F, 0x78, 0x31, 0x0D, 0x20,
  0x21, 0x43, 0x0E, 0xEF, 0x5F, 0x8C, 0x52, 0xE7, 0x01, 0xDB, 0x17, 0xFD, 0xBE, 0x8F, 0xD3, 0xF4,

  /* Bx */
  0x21, 0x69, 0x36, 0xD3, 0xCD, 0x6E, 0x53, 0xFE, 0xC0, 0xA4, 0xE2, 0x31, 0xFD, 0xD6, 0xDC, 0x5C,
  0x69, 0x2C, 0xC7, 0x60, 0x95, 0x25, 0xA7, 0xB2, 0xC9, 0x56, 0x2D, 0x60, 0x8F, 0x25, 0xD5, 0x1A,

  /* By */
  0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
  0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x58
};

CRYPTO_30_HWA_LOCAL CONST(uint8, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_Hw_ConstantOne[CRYPTO_30_HWA_EDDSA_BN_BYTES] = {  /* PRQA S 3218 */ /* MD_CRYPTO_30_HWA_3218_ONE_USAGE */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
};
#  endif /* (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) */

#  if (CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON)  /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
CRYPTO_30_HWA_LOCAL CONST(uint8, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_Hw_ConstantThree[CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES] = {  /* PRQA S 3218 */ /* MD_CRYPTO_30_HWA_3218_ONE_USAGE */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03
};
#  endif /* (CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) */

#  if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON))  /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
CRYPTO_30_HWA_LOCAL CONST(uint8, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_Hw_ConstantTwo[CRYPTO_30_HWA_EDDSA_BN_BYTES] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02
};
# endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) */

#  define CRYPTO_30_HWA_STOP_SEC_CONST_8BIT
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) */

# if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON))  /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
#  define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  if (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)  /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/* 2^512 / q       (used in reduction) */
CRYPTO_30_HWA_LOCAL CONST(uint32, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_Hw_GOBarrett[CRYPTO_30_HWA_EDDSA_ED25519_GO_BARRET_SIZE_DIGITS] =  /* PRQA S 3218 */ /* MD_CRYPTO_30_HWA_3218_ECC_REDUCTION_PARAMETER */
{
  0x0A2C131BuL, 0xED9CE5A3uL, 0x086329A7uL, 0x2106215DuL,
  0xFFFFFFEBuL, 0xFFFFFFFFuL, 0xFFFFFFFFuL, 0xFFFFFFFFuL,
  0x0000000FuL
};

CRYPTO_30_HWA_LOCAL CONST(uint32, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_Hw_GroupOrder[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT] =
{
  0x5CF5D3EDuL, 0x5812631AuL, 0xA2F79CD6uL, 0x14DEF9DEuL,
  0x00000000uL, 0x00000000uL, 0x00000000uL, 0x10000000uL
};
#  endif /* (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) */

#  if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON))  /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/* Setup the input registers as const array. The public key cryptography register contains 16 multi purpose registers. Each multi purpose register contains 8 sections which can hold a uint32 integer. To ease the access of this register,
   each define of the const array holds the address of one section. */
CRYPTO_30_HWA_LOCAL CONST(uint32, CRYPTO_30_HWA_CONST)  Crypto_30_Hwa_Hw_Pkc_Address[CRYPTO_30_HWA_PKC_NUMBER_OF_REGISTERS] = {
  CRYPTO_30_HWA_PKC_0_0_ADDRESS, CRYPTO_30_HWA_PKC_0_1_ADDRESS, CRYPTO_30_HWA_PKC_0_2_ADDRESS, CRYPTO_30_HWA_PKC_0_3_ADDRESS, CRYPTO_30_HWA_PKC_0_4_ADDRESS, CRYPTO_30_HWA_PKC_0_5_ADDRESS, CRYPTO_30_HWA_PKC_0_6_ADDRESS, CRYPTO_30_HWA_PKC_0_7_ADDRESS,
  CRYPTO_30_HWA_PKC_1_0_ADDRESS, CRYPTO_30_HWA_PKC_1_1_ADDRESS, CRYPTO_30_HWA_PKC_1_2_ADDRESS, CRYPTO_30_HWA_PKC_1_3_ADDRESS, CRYPTO_30_HWA_PKC_1_4_ADDRESS, CRYPTO_30_HWA_PKC_1_5_ADDRESS, CRYPTO_30_HWA_PKC_1_6_ADDRESS, CRYPTO_30_HWA_PKC_1_7_ADDRESS,
  CRYPTO_30_HWA_PKC_2_0_ADDRESS, CRYPTO_30_HWA_PKC_2_1_ADDRESS, CRYPTO_30_HWA_PKC_2_2_ADDRESS, CRYPTO_30_HWA_PKC_2_3_ADDRESS, CRYPTO_30_HWA_PKC_2_4_ADDRESS, CRYPTO_30_HWA_PKC_2_5_ADDRESS, CRYPTO_30_HWA_PKC_2_6_ADDRESS, CRYPTO_30_HWA_PKC_2_7_ADDRESS,
  CRYPTO_30_HWA_PKC_3_0_ADDRESS, CRYPTO_30_HWA_PKC_3_1_ADDRESS, CRYPTO_30_HWA_PKC_3_2_ADDRESS, CRYPTO_30_HWA_PKC_3_3_ADDRESS, CRYPTO_30_HWA_PKC_3_4_ADDRESS, CRYPTO_30_HWA_PKC_3_5_ADDRESS, CRYPTO_30_HWA_PKC_3_6_ADDRESS, CRYPTO_30_HWA_PKC_3_7_ADDRESS,
  CRYPTO_30_HWA_PKC_4_0_ADDRESS, CRYPTO_30_HWA_PKC_4_1_ADDRESS, CRYPTO_30_HWA_PKC_4_2_ADDRESS, CRYPTO_30_HWA_PKC_4_3_ADDRESS, CRYPTO_30_HWA_PKC_4_4_ADDRESS, CRYPTO_30_HWA_PKC_4_5_ADDRESS, CRYPTO_30_HWA_PKC_4_6_ADDRESS, CRYPTO_30_HWA_PKC_4_7_ADDRESS,
  CRYPTO_30_HWA_PKC_5_0_ADDRESS, CRYPTO_30_HWA_PKC_5_1_ADDRESS, CRYPTO_30_HWA_PKC_5_2_ADDRESS, CRYPTO_30_HWA_PKC_5_3_ADDRESS, CRYPTO_30_HWA_PKC_5_4_ADDRESS, CRYPTO_30_HWA_PKC_5_5_ADDRESS, CRYPTO_30_HWA_PKC_5_6_ADDRESS, CRYPTO_30_HWA_PKC_5_7_ADDRESS,
  CRYPTO_30_HWA_PKC_6_0_ADDRESS, CRYPTO_30_HWA_PKC_6_1_ADDRESS, CRYPTO_30_HWA_PKC_6_2_ADDRESS, CRYPTO_30_HWA_PKC_6_3_ADDRESS, CRYPTO_30_HWA_PKC_6_4_ADDRESS, CRYPTO_30_HWA_PKC_6_5_ADDRESS, CRYPTO_30_HWA_PKC_6_6_ADDRESS, CRYPTO_30_HWA_PKC_6_7_ADDRESS,
  CRYPTO_30_HWA_PKC_7_0_ADDRESS, CRYPTO_30_HWA_PKC_7_1_ADDRESS, CRYPTO_30_HWA_PKC_7_2_ADDRESS, CRYPTO_30_HWA_PKC_7_3_ADDRESS, CRYPTO_30_HWA_PKC_7_4_ADDRESS, CRYPTO_30_HWA_PKC_7_5_ADDRESS, CRYPTO_30_HWA_PKC_7_6_ADDRESS, CRYPTO_30_HWA_PKC_7_7_ADDRESS,
  CRYPTO_30_HWA_PKC_8_0_ADDRESS, CRYPTO_30_HWA_PKC_8_1_ADDRESS, CRYPTO_30_HWA_PKC_8_2_ADDRESS, CRYPTO_30_HWA_PKC_8_3_ADDRESS, CRYPTO_30_HWA_PKC_8_4_ADDRESS, CRYPTO_30_HWA_PKC_8_5_ADDRESS, CRYPTO_30_HWA_PKC_8_6_ADDRESS, CRYPTO_30_HWA_PKC_8_7_ADDRESS,
  CRYPTO_30_HWA_PKC_9_0_ADDRESS, CRYPTO_30_HWA_PKC_9_1_ADDRESS, CRYPTO_30_HWA_PKC_9_2_ADDRESS, CRYPTO_30_HWA_PKC_9_3_ADDRESS, CRYPTO_30_HWA_PKC_9_4_ADDRESS, CRYPTO_30_HWA_PKC_9_5_ADDRESS, CRYPTO_30_HWA_PKC_9_6_ADDRESS, CRYPTO_30_HWA_PKC_9_7_ADDRESS,
  CRYPTO_30_HWA_PKC_10_0_ADDRESS, CRYPTO_30_HWA_PKC_10_1_ADDRESS, CRYPTO_30_HWA_PKC_10_2_ADDRESS, CRYPTO_30_HWA_PKC_10_3_ADDRESS, CRYPTO_30_HWA_PKC_10_4_ADDRESS, CRYPTO_30_HWA_PKC_10_5_ADDRESS, CRYPTO_30_HWA_PKC_10_6_ADDRESS, CRYPTO_30_HWA_PKC_10_7_ADDRESS,
  CRYPTO_30_HWA_PKC_11_0_ADDRESS, CRYPTO_30_HWA_PKC_11_1_ADDRESS, CRYPTO_30_HWA_PKC_11_2_ADDRESS, CRYPTO_30_HWA_PKC_11_3_ADDRESS, CRYPTO_30_HWA_PKC_11_4_ADDRESS, CRYPTO_30_HWA_PKC_11_5_ADDRESS, CRYPTO_30_HWA_PKC_11_6_ADDRESS, CRYPTO_30_HWA_PKC_11_7_ADDRESS,
  CRYPTO_30_HWA_PKC_12_0_ADDRESS, CRYPTO_30_HWA_PKC_12_1_ADDRESS, CRYPTO_30_HWA_PKC_12_2_ADDRESS, CRYPTO_30_HWA_PKC_12_3_ADDRESS, CRYPTO_30_HWA_PKC_12_4_ADDRESS, CRYPTO_30_HWA_PKC_12_5_ADDRESS, CRYPTO_30_HWA_PKC_12_6_ADDRESS, CRYPTO_30_HWA_PKC_12_7_ADDRESS,
  CRYPTO_30_HWA_PKC_13_0_ADDRESS, CRYPTO_30_HWA_PKC_13_1_ADDRESS, CRYPTO_30_HWA_PKC_13_2_ADDRESS, CRYPTO_30_HWA_PKC_13_3_ADDRESS, CRYPTO_30_HWA_PKC_13_4_ADDRESS, CRYPTO_30_HWA_PKC_13_5_ADDRESS, CRYPTO_30_HWA_PKC_13_6_ADDRESS, CRYPTO_30_HWA_PKC_13_7_ADDRESS,
  CRYPTO_30_HWA_PKC_14_0_ADDRESS, CRYPTO_30_HWA_PKC_14_1_ADDRESS, CRYPTO_30_HWA_PKC_14_2_ADDRESS, CRYPTO_30_HWA_PKC_14_3_ADDRESS, CRYPTO_30_HWA_PKC_14_4_ADDRESS, CRYPTO_30_HWA_PKC_14_5_ADDRESS, CRYPTO_30_HWA_PKC_14_6_ADDRESS, CRYPTO_30_HWA_PKC_14_7_ADDRESS,
  CRYPTO_30_HWA_PKC_15_0_ADDRESS, CRYPTO_30_HWA_PKC_15_1_ADDRESS, CRYPTO_30_HWA_PKC_15_2_ADDRESS, CRYPTO_30_HWA_PKC_15_3_ADDRESS, CRYPTO_30_HWA_PKC_15_4_ADDRESS, CRYPTO_30_HWA_PKC_15_5_ADDRESS, CRYPTO_30_HWA_PKC_15_6_ADDRESS, CRYPTO_30_HWA_PKC_15_7_ADDRESS
};
#  endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) */
#  define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) */
#endif /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON)
# define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CRYPTO_30_HWA_LOCAL CONST(uint8, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_EmptyBlock[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES] = {0u}; /* PRQA S 3218 */ /* MD_CRYPTO_30_HWA_3218_ONE_USAGE */

# define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) */
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON))
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesLoad()
 *********************************************************************************************************************/
/*! \brief         Load one block into AES engine. 16 byte is read from the input.
 *  \details       -
 *  \param[in]     in                 Valid pointer to buffer with at least 16 bytes data.
 *  \pre           AES module enabled.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesLoad(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesSave()
 *********************************************************************************************************************/
/*! \brief         Save one block from AES engine. 16 bytes is stored at destination.
 *  \details       -
 *  \param[out]    out                Valid pointer to buffer with at least 16 bytes data.
 *  \pre           AES module enabled.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesSave(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesWaitBusy()
 *********************************************************************************************************************/
/*! \brief         Wait while the AES engine is busy.
 *  \details       -
 *  \pre           AES module enabled.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesWaitBusy(void);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON)) */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesSaveBackupRegister()
 *********************************************************************************************************************/
/*! \brief         Save one block from AES engine. 16 bytes is stored at destination.
 *  \details       This is the same as Crypto_30_Hwa_Hw_AesSave() but saves the backup registers
 *                 which are used with pipelining.
 *  \param[out]    out                Valid pointer to buffer with at least 16 bytes data.
 *  \pre           AES module enabled.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesSaveBackupRegister(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out);
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) */

#if (CRYPTO_30_HWA_SHA256 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_ByteSwap32()
 **********************************************************************************************************************/
/*! \brief         Swap the bytes in a 32 bit value for little endian.
 *  \details       -
 *  \param[in]     value              32 bit value to swap.
 *  \return        Byte-swapped 32 bit value.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint32, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_ByteSwap32(
  uint32 value);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Sha256WaitFifo()
 **********************************************************************************************************************/
/*! \brief         Wait while HASH engines FIFO is busy.
 *  \details       -
 *  \pre           HASH module enabled.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Sha256WaitFifo(void);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Sha256_GetHashsum()
 **********************************************************************************************************************/
/*! \brief         Get the hashsum from the HASH engine. The hashsum will be truncated to the length maxLength.
 *  \details       -
 *  \param[in,out] outputPtr          Valid pointer to output buffer to store the hashsum.
 *  \param[in]     maxLength          Max available storage in buffer outputPtr.
 *  \return        The length that was written to the output in bytes.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint32, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Sha256_GetHashsum(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  uint32 maxLength);
#endif /* (CRYPTO_30_HWA_SHA256 == STD_ON) */

#if ((CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON) || (CRYPTO_30_HWA_AESGCMDECRYPT == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON))
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Uint32ToArrayByteSwap()
 *********************************************************************************************************************/
 /*! \brief       Convert word to byte array and reverse byte order of input.
  *  \details     This is the same as Crypto_30_Hwa_Hw_WordToByte() but outputs the array in reverse byte order.
  *  \param[in]   source          32 bit word
  *  \param[in]   destination     byte array
  *  \pre         -
  *  \context     TASK
  *  \reentrant   FALSE
  *  \synchronous TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Uint32ToArrayByteSwap(
  uint32 source,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) destination);
#endif /* ((CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON) || (CRYPTO_30_HWA_AESGCMDECRYPT == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) */

#if ((CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON) || (CRYPTO_30_HWA_AESGCMDECRYPT == STD_ON))
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmProcessBlock()
 **********************************************************************************************************************/
/*! \brief          Process one AES GCM block.
 *  \details        -
 *  \param[in,out]  workspace          AES GCM workspace.
 *  \param[in]      inputPtr           Pointer to input data.
 *  \param[in]      inputLength        Length of input in bytes.
 *  \param[out]     outputPtr          Pointer to output data bytes.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmProcessBlock(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr);

#endif /* ((CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON) || (CRYPTO_30_HWA_AESGCMDECRYPT == STD_ON)) */

#if (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngDiscardBadData()
 *********************************************************************************************************************/
/*! \brief         Discards bad data.
 *  \details        If there are problems with the generated random data restart the generation proccess.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_TrngDiscardBadData(void);
#endif /* (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON))
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_ArrayToUint32ByteSwap()
 *********************************************************************************************************************/
/*! \brief        Converts 4 byte from input data to Uint32 and swaps the byte order.
 *  \details      -
 *  \param[in]    source       Input data
 *  \return                    Uint32 data
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(uint32, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_ArrayToUint32ByteSwap(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) source);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_PkcLoadFromBE()
 *********************************************************************************************************************/
/*! \brief         Loads a 32 byte long big endian array into the shared public key crypto memory.
 *  \details       -
 *  \param[in]     pkcRegisterIndex   Index of the register of the shared crypto memory.
 *  \param[in]     in                 Valid pointer to buffer which holds the data.
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_PkcLoadFromBE(
  uint8 pkcRegisterIndex,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_PkcSaveToBE()
 *********************************************************************************************************************/
/*! \brief         Reads 32 bytes of one register of the shared public key crypto memory and stores it into a
 *                 big endian array.
 *  \details       -
 *  \param[in]     pkcRegisterIndex   Index of the register of the shared crypto memory.
 *  \param[out]    out                Valid pointer to a buffer where the data is stored.
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_PkcSaveToBE(
  uint8 pkcRegisterIndex,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_PkcExecuteCommand()
 *********************************************************************************************************************/
/*! \brief         Executes a PKC command and waits while the PKC engine is busy.
 *  \details       -
 *  \param[in]     pkcConfigValue  Value which is written in the PKC-config register.
 *  \param[in]     pkcCmdValue     Value which is written in the PKC-command register
 *  \param[in]     errorMask       Bitmask to check for errors of the PKC status register
 *  \return        E_OK            Command was processed without error
 *                 E_NOT_OK        Error occurred during procession
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_PkcExecuteCommand(
  register uint32 pkcConfigValue,
  register uint32 pkcCmdValue,
  uint32 errorMask);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CheckPointOnCurveEcdsa()
 *********************************************************************************************************************/
/*! \brief         Evaluates the validity of a point by checking if the coordinates of the point are on the curve.
 *  \details       To speed up the calculation, the point coordinates are expected to be stored
 *                 in PKC registers 8 and 9.
 *  \param[in]     curveParameters  Pointer to the curve parameters
 *  \return        E_OK         Point is valid.
 *                 E_NOT_OK     Point is not valid.
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CheckPointOnCurveEcdsa(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) curveParameters);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) */

#if (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_ArrayToUint32()
 *********************************************************************************************************************/
/*! \brief        Converts 4 byte from input data to Uint32.
 *  \details      -
 *  \param[in]    source       Input data
 *  \return                    Uint32 data
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(uint32, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_ArrayToUint32(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) source);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CheckPointOnCurveEd25519()
 *********************************************************************************************************************/
/*! \brief         Evaluates the validity of a point by checking if the coordinates of the point are on the curve.
 *  \details       The coordinates are expected as bignums.
 *  \param[in]     coordX    Bignum with the X coordinate of the point
 *  \param[in]     coordY    Bignum with the Y coordinate of the point
 *  \return        E_OK      Point is valid.
 *                 E_NOT_OK  Point is not valid.
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CheckPointOnCurveEd25519(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) coordX,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) coordY);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_LoadBNFromLE()
 *********************************************************************************************************************/
/*! \brief         Converst a little endian array into a bignum in digit form.
 *  \details       Array must be in little endian format.
 *  \param[in]     input           Buffer for input array
 *  \param[out]    output          Buffer for output bignum
 *  \param[in]     numberOfDigits  Number of digits the output bignum is going to have
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_LoadBNFromLE(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) input,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) output,
  uint32 numberOfDigits);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_SubtractTwoBignums()
 *********************************************************************************************************************/
/*! \brief         Subtracts two bignums
 *  \details       -
 *  \param[in]     a  Buffer for minuend
 *  \param[in]     b  Buffer for subtrahend
 *  \param[out]    result  buffer for result
 *  \param[in]     length  length of the result buffer
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_SubtractTwoBignums(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) a,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) b,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) result,
  const uint32 length);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_MultiplyBignumsDigits()
 *********************************************************************************************************************/
/*! \brief         Multiplies two bignums.
 *  \details       The bignums need to be converted to digit format. Parameter c must be big enough to hold the result
 *                 of the multiplication.
 *  \param[in]     a         Buffer for the first bignum.
 *  \param[in]     a_length  Length of the first bignum.
 *  \param[in]     b         Buffer for the second bignum.
 *  \param[in]     b_length  Length of the second bignum.
 *  \param[out]    c         Buffer for result.
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_MultiplyBignumsDigits(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) a,
  const uint32 a_length,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) b,
  const uint32 b_length,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) c);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_ReducePrimeOrder()
 *********************************************************************************************************************/
/*! \brief         Reduces a bignum by the prime order of the curve Ed25519. The result is in bignum format as well.
 *  \details       The bignum need to be converted to digit format.
 *  \param[in]     a          Buffer for the input bignum.
 *  \param[out]    r          Buffer for the output bignum.
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_ReducePrimeOrder(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) a,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) r);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Reduce()
 *********************************************************************************************************************/
/*! \brief         Subfunction for Crypto_30_Hwa_Hw_ReducePrimeOrder().
 *  \details       -
 *  \param[out]    r          Buffer for the output bignum.
 *  \param[in]     a          Pointer to dividend.
 *  \param[in]     q          Pointer to constant expression q = ((a * m) / 2^512)
 *  \param[in]     n          Pointer to divisor.
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Reduce(
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) r,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) a,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) q,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) n);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_PkcSaveToBignum()
 *********************************************************************************************************************/
 /*! \brief         Reads 32 byte from a PKC register and stores the content in a big num.
  *  \details       -
  *  \param[in]     pkcRegisterIndex  Index of the PKC register to read
  *  \param[out]    out               Buffer of the array
  *  \pre           PKC module enabled.
  *  \context       TASK
  *  \reentrant     FALSE
  *  \synchronous   TRUE
  *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_PkcSaveToBignum(
  uint8 pkcRegisterIndex,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_PkcLoadFromBignum()
 *********************************************************************************************************************/
 /*! \brief         Stores the content of a 8 digit bignum in a PKC register.
  *  \details       -
  *  \param[in]     pkcRegisterIndex  Index of the PKC register to write to
  *  \param[in]     in                Buffer of the array
  *  \pre           PKC module enabled.
  *  \context       TASK
  *  \reentrant     FALSE
  *  \synchronous   TRUE
  *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_PkcLoadFromBignum(
  uint8 pkcRegisterIndex,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CompareBignumsDigits()
 *********************************************************************************************************************/
/*! \brief        Compares two bignums in octet format with each other.
 *  \details      Returns whether both numbers are equal or one number is bigger than the other. It is expected that
 *                both numbers are in digit format.
 *  \param[in]    a       Bignum one
 *  \param[in]    b       Bignum two
 *  \param[in]    length  Length of both bignums
 *  \return               uint8 0x10u - Bignum a is smaller than bignum b
 *                        uint8 0x11u - Bignum a is greater than bignum b
 *                        uint8 0x12u - Both bignums are equal
 *  \pre          a, b must be valid pointers
 *                a, b must be at least of size length
 *  \context      TASK
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CompareBignumsDigits(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) a,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) b,
  const uint32 length);
#endif /* (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON))
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_StoreBNToLE()
 *********************************************************************************************************************/
/*! \brief         Converts a bignum in digits format to a little endian array.
 *  \details       -
 *  \param[in]     input           Buffer to the bignum.
 *  \param[out]    output          Buffer of the array
 *  \param[in]     numberOfDigits  Number of digits to be converted
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_StoreBNToLE(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) input,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) output,
  uint32 numberOfDigits);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_PkcSaveToLE()
 *********************************************************************************************************************/
 /*! \brief         Reads 32 byte from a PKC register and stores the content in a little endian array.
  *  \details       -
  *  \param[in]     pkcRegisterIndex  Index of the PKC register to read
  *  \param[out]    out               Buffer of the array
  *  \pre           PKC module enabled.
  *  \context       TASK
  *  \reentrant     FALSE
  *  \synchronous   TRUE
  *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_PkcSaveToLE(
  uint8 pkcRegisterIndex,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_MultiplyWithBP()
 *********************************************************************************************************************/
/*! \brief         Multiplies the base point of the curve Ed25519 with a skalar and checks if the resulted
 *                 coordinates are valid.
 *  \details       -
 *  \param[in]     skalar     Skalar to multiply the base point with
 *  \param[out]    pointXout  Buffer for the X coordinate
 *  \param[out]    pointYout  Buffer for the Y coordinate
 *  \return        E_OK       Result point is valid.
 *                 E_NOT_OK   Result point is not valid.
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_MultiplyWithBP(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) skalar,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) pointXout,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) pointYout);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_EncodePoint()
 *********************************************************************************************************************/
/*! \brief           Encodes the X and Y coordinates of a point according to Ed25519 specification.
 *  \details         -
 *  \param[in]       pointXcoord  Buffer for the X coordinate
 *  \param[in,out]   pointYcoord  Buffer for the Y coordinate
 *  \pre             PKC module enabled.
 *  \context         TASK
 *  \reentrant       FALSE
 *  \synchronous     TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_EncodePoint(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) pointXcoord,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) pointYcoord);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CheckPointUpperBoundary()
 *********************************************************************************************************************/
/*! \brief         Checks if the coordinates of a point are smaller than the prime number of the curve.
 *  \details       The input only requires the PKC register holding the x coordinate. The y coordinate automatically
 *                 is assumed to be stored in the following register. The prime number is assumed to be stored in the
 *                 register with the index 0.
 *  \param[in]     pkcScmIndex  Index of PKC register where the x coordinate is stored
 *  \return        E_OK         Points are smaller than prime number of curve and valid
 *                 E_NOT_OK     Points are greater than prime number of curve and not valid
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CheckPointUpperBoundary(
  uint8 pkcScmIndex);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON))
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_LoadBNFromBE()
 *********************************************************************************************************************/
/*! \brief         Converts a big endian array into a bignum in digit form.
 *  \details       Array must be in big endian format.
 *  \param[in]     input           Buffer for input array
 *  \param[out]    output          Buffer for output bignum
 *  \param[in]     numberOfDigits  Number of digits the output bignum is going to have
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_LoadBNFromBE(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) input,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) output,
  uint32 numberOfDigits);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_SubtractTwoBignumsModulo()
 *********************************************************************************************************************/
/*! \brief         Performs the calculation a - b mod p for a < b. For a > b the following calculation is performed:
 *                 (p - a) - b mod p. The values are expected as bignums.
 *  \details       -
 *  \param[in]     a  Bignum with the minuend
 *  \param[in]     b  Bignum with the subtrahend
 *  \param[in]     p  Bignum with the modulus
 *  \param[out]    result   Undecoded y coordinate.
 *  \return        E_OK            Subtraction was successful
 *                 E_NOT_OK        Subtraction was not successful
 *  \pre           PKC module enabled.
 *                 a, b < p
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_SubtractTwoBignumsModulo(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) a,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) b,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) p,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) result);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_DecodePoint()
 *********************************************************************************************************************/
/*! \brief         Decodes the X and Y coordinate of a point that lies on curve Ed25519.
 *  \details       -
 *  \param[out]    pointXcoordOut  Buffer for the x coordinate.
 *  \param[out]    pointYcoordOut  Buffer for the y coordinate.
 *  \param[in]     pointYcoordIn   Undecoded y coordinate.
 *  \return        E_OK            Decoding was successful
 *                 E_NOT_OK        Decoding was not successful
 *  \pre           PKC module enabled.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_DecodePoint(
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) pointXcoordOut,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) pointYcoordOut,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) pointYcoordIn);
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC   == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_GCM) || \
     (CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV))
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesLoad()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesLoad(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in)
{
  /* PRQA S 0306, 0310, 3305 4 */ /* MD_CRYPTO_30_HWA_0306_0310_3305_REGISTER_ACCESS_PERFORMANCE */
  HSM_AES->AESIN0 = ((P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))in)[0];
  HSM_AES->AESIN1 = ((P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))in)[1];
  HSM_AES->AESIN2 = ((P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))in)[2];
  HSM_AES->AESIN3 = ((P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))in)[3];
} /* Crypto_30_Hwa_Hw_AesLoad() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesSave()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesSave(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out)
{
  /* PRQA S 0306, 0310, 3305 4 */ /* MD_CRYPTO_30_HWA_0306_0310_3305_REGISTER_ACCESS_PERFORMANCE */
  ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))out)[0] = HSM_AES->AESOUT0;
  ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))out)[1] = HSM_AES->AESOUT1;
  ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))out)[2] = HSM_AES->AESOUT2;
  ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))out)[3] = HSM_AES->AESOUT3;
} /* Crypto_30_Hwa_Hw_AesSave() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesWaitBusy()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesWaitBusy(void)
{
  while ((HSM_AES->AESSTAT & (uint32)CRYPTO_30_HWA_AESSTAT_BSY_MASK) != 0u) /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */ /* COV_CRYPTO_30_HWA_WAITLOOP_HARDWARE */
  {
    continue;
  }
} /* Crypto_30_Hwa_Hw_AesWaitBusy() */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC   == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_AES_GCM) ||
           (CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV)) */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesSaveBackupRegister()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesSaveBackupRegister(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out)
{
  /* PRQA S 0306, 0310, 3305 4 */ /* MD_CRYPTO_30_HWA_0306_0310_3305_REGISTER_ACCESS_PERFORMANCE */
  ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))out)[0] = HSM_AES->AESOUTSAVE0;
  ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))out)[1] = HSM_AES->AESOUTSAVE1;
  ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))out)[2] = HSM_AES->AESOUTSAVE2;
  ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))out)[3] = HSM_AES->AESOUTSAVE3;
} /* Crypto_30_Hwa_Hw_AesSaveBackupRegister() */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) */

#if (CRYPTO_30_HWA_SHA256 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_ByteSwap32()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint32, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_ByteSwap32(
  uint32 value)
{
  volatile uint32 tmp;
  tmp = (
    /* move byte 3 to byte 0 */
    ((value >> 24u)) |
    /* move byte 2 to byte 1 */
    ((value >> 8u) & 0x0000FF00U) |
    /* move byte 1 to byte 2 */
    ((value << 8u) & 0x00FF0000U) |
    /* move byte 0 to byte 3 */
    ((value << 24u))
    );
  return tmp;
} /* Crypto_30_Hwa_Hw_ByteSwap32() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Sha256WaitFifo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Sha256WaitFifo(void)
{
  while (0u == (HSM_HASH->HASH_STAT & HASH_STAT_DF_NF_Msk)) /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */ /* COV_CRYPTO_30_HWA_WAITLOOP_HARDWARE */
  {
    continue;
  }
} /* Crypto_30_Hwa_Hw_Sha256WaitFifo() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Sha256_GetHashsum()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint32, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Sha256_GetHashsum(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  uint32 maxLength)
{
  uint32 retLength = 0u;
  uint8_least words = 0u;
  uint8 remainingData;
  volatile uint32 tmp;

  /* Run while result is available */
  while (0u != (HSM_HASH->HASH_STAT & HASH_STAT_CNT_Msk)) /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  {
    if (words < DIV_4(maxLength))
    {
      /* Copy complete 32 bit packages to destination if enough space */
      ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))outputPtr)[words] = HSM_HASH->HASH_VAL; /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_HWA_0306_0310_3305_REGISTER_ACCESS_PERFORMANCE */
      retLength += sizeof(uint32);
    }
    else
    {
      /* All complete words copied, copy remaining data smaller than 32 bit */
      if (MOD_4(maxLength) != 0u)
      {
        remainingData = (uint8)MOD_4(maxLength);
        tmp = HSM_HASH->HASH_VAL; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
        VStdLib_MemCpy(&outputPtr[sizeof(uint32) * words], (P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))(&tmp), remainingData); /* PRQA S 0315, 0312 */ /* MD_MSR_VStdLibCopy, MD_CRYPTO_30_HWA_0312_VOLATILE_LOSS */
        retLength += remainingData;
      }
      break;
    }
    words += 1u;
  }

  /* Read and drop the rest of result data */
  while (0u != (HSM_HASH->HASH_STAT & HASH_STAT_CNT_Msk)) /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  {
    tmp = HSM_HASH->HASH_VAL; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  }

  return retLength;
} /* Crypto_30_Hwa_Hw_Sha256_GetHashsum() */
#endif /* (CRYPTO_30_HWA_SHA256 == STD_ON) */

#if ((CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON) || (CRYPTO_30_HWA_AESGCMDECRYPT == STD_ON))
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmProcessBlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmProcessBlock(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr)
{
  register uint32 AESCTRL_Value = (workspace->custom.cipherMode & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext;
  CRYPTO_30_HWA_DUMMY_STATEMENT(inputLength);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /* #10 Process one block of input data */
  Crypto_30_Hwa_Hw_AesLoad(inputPtr);

  HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

  Crypto_30_Hwa_Hw_AesSave(outputPtr);
} /* Crypto_30_Hwa_Hw_AesGcmProcessBlock */
#endif /* ((CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON) || (CRYPTO_30_HWA_AESGCMDECRYPT == STD_ON)) */

#if ((CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON) || (CRYPTO_30_HWA_AESGCMDECRYPT == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON))
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Uint32ToArrayByteSwap()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Uint32ToArrayByteSwap(
  uint32 source,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) destination)
{
  /* #10 Copy word to byte array and reverse byte order of input */
  destination[0] = (uint8)((source >> 24u));
  destination[1] = (uint8)((source >> 16u) & 0xFFu);
  destination[2] = (uint8)((source >> 8u) & 0xFFu);
  destination[3] = (uint8)(source & 0xFFu);
} /* Crypto_30_Hwa_Uint32ToArrayByteSwap() */
#endif /* ((CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON) || (CRYPTO_30_HWA_AESGCMDECRYPT == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON))
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_ArrayToUint32ByteSwap()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(uint32, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_ArrayToUint32ByteSwap(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) source)
{
  /* Copy 4 byte uint8 array to uint32 and swaps the byte order */
  return ((uint32)source[3] | (((uint32)source[2]) << 8u) | (((uint32)source[1]) << 16u) | (((uint32)source[0]) << 24u));
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_PkcLoadFromBE()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_PkcLoadFromBE(
  uint8 pkcRegisterIndex,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in)
{
  uint32_least index;

  /* Load a big endian array with 4 byte chunks into a PKC register */
  for (index = 0u; index < CRYPTO_30_HWA_PKC_REGISTER_SIZE_WORD; index++)
  {
    REG32(Crypto_30_Hwa_Hw_Pkc_Address[((uint32)pkcRegisterIndex * CRYPTO_30_HWA_PKC_REGISTER_SIZE_WORD) + index]) = /* PRQA S 0303 */ /* MD_CRYPTO_30_HWA_0303_REGISTER_ACCESS */
    Crypto_30_Hwa_Hw_ArrayToUint32ByteSwap(&in[CRYPTO_30_HWA_PKC_ARRAY_INPUT_START_INDEX - (index * CRYPTO_30_HWA_PKC_ARRAY_CHUNK_SIZE_BYTES)]);
  }
}
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_PkcSaveToBE()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_PkcSaveToBE(
  uint8 pkcRegisterIndex,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out)
{
  uint32_least index;

  /* Store 32 byte of a PKC register in a big endian array */
  for (index = 0u; index < CRYPTO_30_HWA_PKC_REGISTER_SIZE_WORD; index++)
  {
    Crypto_30_Hwa_Uint32ToArrayByteSwap(REG32(Crypto_30_Hwa_Hw_Pkc_Address[((uint32)pkcRegisterIndex * CRYPTO_30_HWA_PKC_REGISTER_SIZE_WORD) + (CRYPTO_30_HWA_PKC_ARRAY_OUTPUT_START_INDEX - index)]),  /* PRQA S 0303 */ /* MD_CRYPTO_30_HWA_0303_REGISTER_ACCESS */
                                        &out[index * CRYPTO_30_HWA_PKC_ARRAY_CHUNK_SIZE_BYTES]);
  }
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_PkcExecuteCommand()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_PkcExecuteCommand(
  register uint32 pkcConfigValue,
  register uint32 pkcCmdValue,
  uint32 errorMask)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Prepare PKC-Config and PKC-Command register and start execution */
  /* PRQA S 0306 3 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  HSM_PKC->PKC_CONFIG = pkcConfigValue;
  HSM_PKC->PKC_CMD =    pkcCmdValue;
  HSM_PKC->PKC_CTRL = CRYPTO_30_HWA_PKCCTRL_STARTSIGNAL;

  /* #20 Wait while PKC is busy */
  while ((HSM_PKC->PKC_STATUS & (uint32)CRYPTO_30_HWA_PKC_STATUS_BSY_MASK) != CRYPTO_30_HWA_PKC_STATUS_BSY)   /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  {
    continue;
  }

  /* #30 Check if any error occurred during processing */
  if ((HSM_PKC->PKC_STATUS & (uint32)errorMask) == CRYPTO_30_HWA_PKC_STATUS_NO_ERROR)  /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  {
    retVal = E_OK;
  }

  return retVal;

}
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CheckPointOnCurveEcdsa()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CheckPointOnCurveEcdsa(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) curveParameters)
{
  Std_ReturnType retVal;

  register uint32 pkcConfigValue;
  register uint32 pkcCommandValue;

  uint8 result[CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES] = { 0u };

  /* #10 Load values for calculation into PKC registers */
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R0, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_PRIME_FIELD_P_OFFSET]);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R1, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_COEFF_A_OFFSET]);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R13, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_COEFF_B_OFFSET]);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R3, Crypto_30_Hwa_Hw_ConstantTwo);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R4, Crypto_30_Hwa_Hw_ConstantThree);

  /* #11 Calculate x^3 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R7 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R4 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R8 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP | CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_EXP);

  retVal = Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #12 Calculate y^2 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R14 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R3 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R9 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_EXP);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #13 Calculate z1 = a * x */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R15 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R8 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R1 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_MULTN);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #14 Calculate z2 = z1 + x^3 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R10 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R7 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R15 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_ADDN);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #15 Calculate z3 = z2 + b */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R11 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R13 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R10 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_ADDN);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #16 Calculate result = z3 - y^2 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R12 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R14 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R11 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_SUBN);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #17 Read result from register */
  Crypto_30_Hwa_Hw_PkcSaveToBE(CRYPTO_30_HWA_PKCSCM_R12, result);

  /* #18 Check if result equals to zero. If this is the case, the point lies on the curve */
  if (Crypto_30_Hwa_IsBignumZeroBe(result, CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES) == FALSE)
  {
    retVal |= E_NOT_OK;
  }

  return retVal;
}
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) */

#if (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_ArrayToUint32()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(uint32, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_ArrayToUint32(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) source)
{
  /* Copy 4 byte uint8 array to uint32 */
  return ((uint32)source[0] | (((uint32)source[1]) << 8u) | (((uint32)source[2]) << 16u) | (((uint32)source[3]) << 24u));
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_LoadBNFromLE()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_LoadBNFromLE(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) input,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) output,
  uint32 numberOfDigits)
{
  uint32_least index;
  uint8 inputIndex = 0u;

  /* Converts a little endian array to a bignum with a variable number of digits */
  for (index = 0u; index < numberOfDigits; index++)
  {
    output[index] = Crypto_30_Hwa_Hw_ArrayToUint32(&input[inputIndex]);
    inputIndex += 4u;
  }
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_PkcLoadFromBignum()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_PkcLoadFromBignum(
  uint8 pkcRegisterIndex,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in)
{
  uint32_least index;

  /* Loads a bignum with 8 digits into a register of the PKC register */
  for (index = 0u; index < CRYPTO_30_HWA_PKC_REGISTER_SIZE_WORD; index++)
  {
    REG32(Crypto_30_Hwa_Hw_Pkc_Address[((uint32)pkcRegisterIndex * CRYPTO_30_HWA_PKC_REGISTER_SIZE_WORD) + index]) = in[index];  /* PRQA S 0303 */ /* MD_CRYPTO_30_HWA_0303_REGISTER_ACCESS */
  }
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_PkcSaveToBignum()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_PkcSaveToBignum(
  uint8 pkcRegisterIndex,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out)
{
  uint32_least index;

  /* Stores 32 byte from a PKC register into a bignum with 8 digits */
  for (index = 0u; index < CRYPTO_30_HWA_PKC_REGISTER_SIZE_WORD; index++)
  {
    out[index] = REG32(Crypto_30_Hwa_Hw_Pkc_Address[((uint32)pkcRegisterIndex * CRYPTO_30_HWA_PKC_REGISTER_SIZE_WORD) + index]);  /* PRQA S 0303 */ /* MD_CRYPTO_30_HWA_0303_REGISTER_ACCESS */
  }
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_MultiplyBignumsDigits()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_MultiplyBignumsDigits(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) a,
  const uint32 a_length,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) b,
  const uint32 b_length,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) c)
{
  uint32 i, j, c_length = a_length + b_length;
  uint64 tmp;
  uint32 carry;

  VStdMemClr(c, c_length);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  /* School method, start with the least significant digit (little endian array order) */
  for (i = 0u; i < b_length; ++i)
  {
    carry = 0u;
    for (j = 0u; j < a_length; ++j)
    {
      tmp = (((uint64) a[j]) * b[i]) + c[(i + j)] + carry;
      c[(i + j)] = CRYPTO_30_HWA_BN_LO_WORD(tmp);
      carry = CRYPTO_30_HWA_BN_HI_WORD(tmp);
    }
    c[(i + a_length)] = carry;
  }
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Reduce()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Reduce(
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) r,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) a,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) q,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) n)
{
  uint32 d;
  uint64 tempBuffer;

  /* (2)   r = q * n = ((a * m) / 2^512) * n
  *
  *    we just calculate the BNDIGITS_256 LSdigits:
  *    * the MSdigits will NOT influence the final result
  *      (which is just BNDIGITS_256 "long")
  *
  */
  VStdMemClr(r, CRYPTO_30_HWA_EDDSA_BN_BYTES);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  for (d = 0u; d < CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT; d++)
  {
    uint32 j;
    uint64 digit;

    digit = n[d];
    tempBuffer = 0u;
    for (j = 0u; j < ((uint32)CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT - d); j++)
    {
      tempBuffer += ((uint64) q[j]) * digit;
      tempBuffer += r[d + j];
      r[d + j] = CRYPTO_30_HWA_BN_LO_WORD(tempBuffer);
      tempBuffer = CRYPTO_30_HWA_BN_HI_WORD(tempBuffer);
    }
  }

  /* (3)   r = a - r = a - (((a * m) / 2^512) * n)
  *
  *    we just calculate the BNDIGITS_256 LSdigits:
  *    * the MSdigits will turn to ZERO anyway!
  */
  Crypto_30_Hwa_Hw_SubtractTwoBignums(a, r, r, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT);

  /* (4)   r -= n    (while still too large)
  *
  *    ONE subtraction should be enough:
  *    * just in case we'll repeat this...
  */
  while (Crypto_30_Hwa_Hw_CompareBignumsDigits(r, n, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT) == CRYPTO_30_HWA_ECDSA_BIGNUM_LARGER)
  {
    Crypto_30_Hwa_Hw_SubtractTwoBignums(r, n, r, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT);
  }
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_ReducePrimeOrder()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_ReducePrimeOrder(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) a,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) r)
{
  uint32 q[32] = { 0u };

  /* (1)   q = (a * m) / 2^512, m = mQ   (the division is implicit)
  *
  *    just a plain multiplication (not used that often!)
  *
  *    in addition we only use the MSdigits for further calculation:
  *    -> this implicitly divides the result into 2^512
  *
  *    (memory) optimization potential:
  *    * multiply in three chunks at 256 bits result each
  *      and store just the last one (like: reduceP)
  */
  Crypto_30_Hwa_Hw_MultiplyBignumsDigits(a, CRYPTO_30_HWA_EDDSA_BN_DIGITS_512_BIT, Crypto_30_Hwa_Hw_GOBarrett, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT + 1u, q);

  /* Call Crypto_30_Hwa_Hw_Reduce() to perform step 2 - 4 of Barrett reduction */
  Crypto_30_Hwa_Hw_Reduce(r, a, &q[CRYPTO_30_HWA_EDDSA_BN_DIGITS_512_BIT], Crypto_30_Hwa_Hw_GroupOrder);
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_SubtractTwoBignums()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_SubtractTwoBignums(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) a,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) b,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) result,
  const uint32 length)
{
  uint32 i;
  uint64 tmp = CRYPTO_30_HWA_BN_BASE;

  for (i = 0; i < length; ++i)
  {
    /* tmp = a[i] - b[i] - carry */
    tmp = (uint64)(CRYPTO_30_HWA_BN_BASE | a[i]) - b[i] - (1u - (uint64)CRYPTO_30_HWA_BN_HI_WORD(tmp));
    result[i] = CRYPTO_30_HWA_BN_LO_WORD(tmp);
  }
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CheckPointOnCurveEd25519()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CheckPointOnCurveEd25519(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) coordX,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) coordY)
{
  Std_ReturnType retVal;

  register uint32 pkcConfigValue;
  register uint32 pkcCommandValue;

  uint8 result[CRYPTO_30_HWA_EDDSA_BN_BYTES] = { 0u };

  /* #10 Load values for calculation into PKC registers */
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R0, Crypto_30_Hwa_Hw_Ed25519CurveParameter);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R2, &Crypto_30_Hwa_Hw_Ed25519CurveParameter[CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_CONST_D_OFFSET]);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R3, Crypto_30_Hwa_Hw_ConstantOne);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R4, Crypto_30_Hwa_Hw_ConstantTwo);
  Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R5, coordX);
  Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R6, coordY);

  /*#11 Calculate p - 1 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R1 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R3 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R0 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP | CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_SUBN);

  retVal = Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #12 Calculate x^2 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R7 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R4 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R5 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_EXP);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #13 Calculate y^2 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R8 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R4 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R6 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_EXP);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #14 Calculate z1 = a * x^2 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R9 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R7 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R1 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_MULTN);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #15 Calculate z2 = d * x^2 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R10 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R7 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R2 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_MULTN);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #16 Calculate z3 = z2 * y^2 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R11 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R8 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R10 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_MULTN);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #17 Calculate z4 = z1 + y^2 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R12 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R8 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R9 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_ADDN);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #18 Calculate z5 = z4 - 1 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R13 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R3 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R12 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_SUBN);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #19 Calculate result = z5 - z3 */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R14 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R11 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R13 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_SUBN);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #20 Read result from PKC register */
  Crypto_30_Hwa_Hw_PkcSaveToBE(CRYPTO_30_HWA_PKCSCM_R14, result);

  /* #21 Check if result equals to zero. If this is the case, the point lies on the curve */
  if (Crypto_30_Hwa_IsBignumZeroBe(result, CRYPTO_30_HWA_EDDSA_BN_BYTES) == FALSE)
  {
    retVal |= E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CompareBignumsDigits()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CompareBignumsDigits(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) a,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) b,
  const uint32 length)
{
  Std_ReturnType compareReturnValue = CRYPTO_30_HWA_ECDSA_BIGNUM_EQUAL;
  uint32 i;

  for (i = 0u; i < length; i++) /* PRQA S 0771 */ /* MD_CRYPTO_30_HWA_0771_MULTIPLE_BREAK */
  {
    if (a[((length - 1u) - i)] < b[((length - 1u) - i)])
    {
      compareReturnValue = CRYPTO_30_HWA_ECDSA_BIGNUM_SMALLER;
      break;
    }
    else if (a[((length - 1u) - i)] > b[((length - 1u) - i)])
    {
      compareReturnValue = CRYPTO_30_HWA_ECDSA_BIGNUM_LARGER;
      break;
    }
    else
    {
      /* Do nothing. Return value already set. */
    }
  }

  return compareReturnValue;
}
#endif /* (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_LoadBNFromBE()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_LoadBNFromBE(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) input,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) output,
  uint32 numberOfDigits)
{
  uint32_least index;
  uint32 inputIndex = (numberOfDigits * 4u) - 4u;

  /* Converts a big endian array to a bignum with a variable number of digits */
  for (index = 0u; index < numberOfDigits; index++)
  {
    output[index] = Crypto_30_Hwa_Hw_ArrayToUint32ByteSwap(&input[inputIndex]);
    inputIndex -= 4u;
  }
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_SubtractTwoBignumsModulo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_SubtractTwoBignumsModulo(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) a,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) b,
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) p,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) result)
{
  Std_ReturnType retVal;

  register uint32 pkcConfigValue;
  register uint32 pkcCommandValue;

  /* #10 Load a as minuend */
  Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R10, a);

  /* #11 Load b as subtrahend */
  Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R2, b);

  /* #12 Load p as modulus */
  Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R0, p);

  /* #13 Configure PKC input and output registers */
  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R1 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R2 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R10 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  /* #14 Perform operation a - b mod p */
  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP | CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_SUBN);

  retVal = Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #15 Store result */
  Crypto_30_Hwa_Hw_PkcSaveToBignum(CRYPTO_30_HWA_PKCSCM_R1, result);

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_DecodePoint()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_DecodePoint(
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) pointXcoordOut,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) pointYcoordOut,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) pointYcoordIn)
{
  Std_ReturnType retVal = E_OK;

  uint8 x_0;
  const uint32 zeroValue[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT] = { 0u };
  uint32 curvePrime[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT] = { 0u };

  register uint32 pkcConfigValue;
  register uint32 pkcCommandValue;

  /* #10 Convert Y-coordinate from little endian array to bignum */
  Crypto_30_Hwa_Hw_LoadBNFromLE(pointYcoordIn, pointYcoordOut, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT);

  /* #11 Save value of MS bit in x_0 */
  x_0 = (uint8)((pointYcoordOut[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT - 1u] >> (CRYPTO_30_HWA_EDDSA_BN_BITS_PER_DIGIT - 1u)) & 0xFFu); /* PRQA S 2985 */ /* MD_CRYPTO_30_HWA_2985_REDUNDANT_OP */

  /* #12 Clear MS bit to decode Y-coordinate */
  pointYcoordOut[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT - 1u] &= (uint32)CRYPTO_30_HWA_EDDSA_ED25519MASK_MSBIT;

  /* #13 Check if the decoded Y-coordinate is greater than the curve prime */
  Crypto_30_Hwa_Hw_LoadBNFromBE(Crypto_30_Hwa_Hw_Ed25519CurveParameter, curvePrime, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT);

  if(Crypto_30_Hwa_Hw_CompareBignumsDigits(pointYcoordOut, curvePrime, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT) == CRYPTO_30_HWA_ECDSA_BIGNUM_LARGER)
  {
    retVal |= E_NOT_OK;
  }

  /* #14 Load curve parameters into PKC-registers */
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R0, Crypto_30_Hwa_Hw_Ed25519CurveParameter);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R4, &Crypto_30_Hwa_Hw_Ed25519CurveParameter[CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_PRIME38_OFFSET]);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R10, &Crypto_30_Hwa_Hw_Ed25519CurveParameter[CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_CONST_D_OFFSET]);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R11, &Crypto_30_Hwa_Hw_Ed25519CurveParameter[CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_SQRTM1_OFFSET]);

  /* #15 Load decoded Y-coordinate into PKC register */
  Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R8, pointYcoordOut);

  pkcConfigValue = 0;

  /* #16 Execute command to recover X-coordinate */
  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP | CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_XRECOVER);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #17 Store X-coordinate */
  Crypto_30_Hwa_Hw_PkcSaveToBignum(CRYPTO_30_HWA_PKCSCM_R6, pointXcoordOut);

  /* #18 Check if the recovered X-coordinate is valid */
  if (x_0 == 0x1u)
  {
    if(Crypto_30_Hwa_Hw_CompareBignumsDigits(pointXcoordOut, zeroValue, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT) == CRYPTO_30_HWA_ECDSA_BIGNUM_EQUAL)
    {
      retVal |= E_NOT_OK;
    }
  }

  /* #19 Check if value of x_0 is not equal to last byte of decoded X-coordinate */
  if (x_0 != (pointXcoordOut[0u] & 1u))
  {
    /* #20 Perform operation  X = 0 - X mod P */
    retVal |= Crypto_30_Hwa_Hw_SubtractTwoBignumsModulo(zeroValue, pointXcoordOut, curvePrime, pointXcoordOut);
  }

  return retVal;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON))
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_PkcSaveToLE()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_PkcSaveToLE(
  uint8 pkcRegisterIndex,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out)
{
  uint32_least index;
  uint8 outputIndex = 0u;

  /* Stores 32 byte from a PKC register into a bignum with 8 digits */
  for (index = 0u; index < CRYPTO_30_HWA_PKC_REGISTER_SIZE_WORD; index++)
  {
    Crypto_30_Hwa_Uint32ToArray(REG32(Crypto_30_Hwa_Hw_Pkc_Address[((uint32)pkcRegisterIndex * CRYPTO_30_HWA_PKC_REGISTER_SIZE_WORD) + index]),  /* PRQA S 0303 */ /* MD_CRYPTO_30_HWA_0303_REGISTER_ACCESS */
                                &out[outputIndex]);
    outputIndex += 4u;
  }
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_StoreBNToLE()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_StoreBNToLE(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) input,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) output,
  uint32 numberOfDigits)
{
  uint32_least index;
  uint8 outputIndex = 0u;

  /* Converts a bignum to a little endian array with a variable number of digits */
  for (index = 0u; index < numberOfDigits; index++)
  {
    Crypto_30_Hwa_Uint32ToArray(input[index], &output[outputIndex]);
    outputIndex += 4u;
  }
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_MultiplyWithBP()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_MultiplyWithBP(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) skalar,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) pointXout,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) pointYout)
{
  Std_ReturnType retVal;

  register uint32 pkcConfigValue;
  register uint32 pkcCommandValue;

  /* Load the curve parameters, the base point and the skalar to the PKC register */
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R0, Crypto_30_Hwa_Hw_Ed25519CurveParameter);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R1, &Crypto_30_Hwa_Hw_Ed25519CurveParameter[CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_D2_OFFSET]);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R2, &Crypto_30_Hwa_Hw_Ed25519CurveParameter[CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_BASE_POINT_X_OFFSET]);
  Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R3, &Crypto_30_Hwa_Hw_Ed25519CurveParameter[CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_BASE_POINT_Y_OFFSET]);
  Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R4, skalar);

  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R6 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
    ((uint32)CRYPTO_30_HWA_PKCSCM_R4 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
    (CRYPTO_30_HWA_PKCSCM_R2 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP | CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_SMULTED25519);

  /* Execute the command to perform the scalar multiplication */
  retVal = Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* Checks if the result coordinates are smaller than the base prime */
  retVal |= Crypto_30_Hwa_Hw_CheckPointUpperBoundary(CRYPTO_30_HWA_PKCSCM_R6);

  /* Store the output */
  Crypto_30_Hwa_Hw_PkcSaveToBignum(CRYPTO_30_HWA_PKCSCM_R6, pointXout);
  Crypto_30_Hwa_Hw_PkcSaveToBignum(CRYPTO_30_HWA_PKCSCM_R7, pointYout);

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_EncodePoint()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_EncodePoint(
  P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) pointXcoord,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) pointYcoord)
{
  /* To encode a point, the MSB of the x coordinate is copied to the LSB of the y coordinate */
  pointYcoord[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT - 1u] |= pointXcoord[0u] << (CRYPTO_30_HWA_EDDSA_BN_BITS_PER_DIGIT - 1u);
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CheckPointUpperBoundary()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CheckPointUpperBoundary(
  uint8 pkcScmIndex)
{
  Std_ReturnType retVal;

  /* Prepare PKC-Config and PKC-Command register */
  register uint32 pkcConfigValue = ((uint32)pkcScmIndex);
  register uint32 pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_CHECKPXY);

  /* Execute the command to perform the coordinate check */
  retVal = Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_CHECKPXY);

  return retVal;
}
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_InitMemory(void)
{
#if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
  VStdLib_MemClr(contextMapping, sizeof(uint8)* Crypto_30_Hwa_GetSizeOfObjectInfo()); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
#endif
  /* Nothing to do here */
} /* Crypto_30_Hwa_Hw_InitMemory() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Init(void)
{
  /* indicate that there is no gcm service in any object found. */
#if ((CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON) || (CRYPTO_30_HWA_OBJECTINFO == STD_ON))
  uint8 i;
#endif

#if (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON)
  uint8 contextId;
  uint8 hasGcm = 0xFFu;
#endif

  SuspendAllInterrupts();

#if(CRYPTO_30_HWA_TRNG_PREFETCHING == STD_OFF)
  /* Disable TRNG after boot if prefetching is disabled */
  HSM_TRNG->TRNG_CTRL = (TRNG_CTRL_DIS_DIS << CRYPTO_30_HWA_TRNG_CTRL_DIS_POS); /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  NVIC_ClearPendingIRQ(TRNG_IRQn);
# endif

#if (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_ON)
  Crypto_30_Hwa_Hw_TrngEnableIrq();
#else /* (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_OFF) */
  NVIC_DisableIRQ(TRNG_IRQn);
#endif /* (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_ON) */

  ResumeAllInterrupts();

  /* Step 1: Loop over all driver objects to detect GCM Services. */
#if (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON)
  for (i = 0; i < Crypto_30_Hwa_GetSizeOfObjectInfo(); i++)
  {
    /* check if aead decrypt service is used by driver object */
#if ((CRYPTO_30_HWA_SERVICE_AEADENCRYPT == STD_ON) && (CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON))
    if(Crypto_30_Hwa_IsAesGcmEncryptUsedOfObjectInfo(i) == TRUE)
    {
      contextMapping[i] = CRYPTO_30_HWA_HW_GCM_CONTEXT;
      hasGcm = i;
    }
#endif /* ((CRYPTO_30_HWA_SERVICE_AEADENCRYPT == STD_ON) && (CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON)) */
#if ((CRYPTO_30_HWA_SERVICE_AEADDECRYPT == STD_ON) && (CRYPTO_30_HWA_AESGCMDECRYPT == STD_ON))
    if (Crypto_30_Hwa_IsAesGcmDecryptUsedOfObjectInfo(i) == TRUE)
    {
      contextMapping[i] = CRYPTO_30_HWA_HW_GCM_CONTEXT;
      hasGcm = i;
    }
#endif /* ((CRYPTO_30_HWA_SERVICE_AEADDECRYPT == STD_ON) && (CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON)) */

    if (hasGcm != 0xFFu)
    {
      break;
    }

  }
  /* if no GCM service is configured each driver object is assigned a separate context. */
  contextId = 2;
  for (i = 0; i < Crypto_30_Hwa_GetSizeOfObjectInfo(); i++)
  {
    if (hasGcm == i)
    {
      continue;
    }
    else
    {
      /* increase contextId (e.g. to 3 for the first non gcm driver object)*/
      contextId++;
      contextMapping[i] = contextId;
    }
  }
#else
 #if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
  for (i = 0; i < Crypto_30_Hwa_GetSizeOfObjectInfo(); i++)
  {
    contextMapping[i] = i;
  }
 #endif
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON) */
} /* Crypto_30_Hwa_Hw_Init() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_MainFunction(void)
{

} /* Crypto_30_Hwa_Hw_MainFunction() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CancelJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CancelJob(
  uint32 objectId,
  Crypto_30_Hwa_JobPtrType job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  CRYPTO_30_HWA_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
} /* Crypto_30_Hwa_Hw_CancelJob */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesStart(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) iv,
  uint8 ivLength,
  Crypto_AlgorithmModeType mode,
  Crypto_ServiceInfoType service)
{
  Std_ReturnType retVal = E_OK;

  /* get hardware context from driver object mapping */
  uint8 mappedDriverId = contextMapping[workspace->driverObjectId];
  workspace->custom.hwContext = mappedDriverId;

#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  if(workspace->romKeyMapIndex != CRYPTO_30_HWA_ROMKEY_USE_IMPORTED_KEY)
  {
    workspace->custom.hwKeyslot = workspace->romKeyMapIndex << 4u;
  }
  else
#endif /*(CRYPTO_30_HWA_ROMKEY == STD_ON) */
  {
    /* add 2 to the keyid since key 0 and key 1 are locked */
    workspace->custom.hwKeyslot = ((uint32)mappedDriverId + 2u) << 4u;

    /* Set key in AES accelerator */
    Crypto_30_Hwa_Hw_AesLoad(key);
    HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WK | workspace->custom.hwKeyslot; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  }
  HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WCV | workspace->custom.hwContext; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */

  /* Check if ECB, CTR or CBC, other modes are not passed to HW part */
  if (mode == CRYPTO_ALGOMODE_ECB)
  {
    /* Check if ENCRYPT or DECRYPT, other services are not passed to HW part */
    if (service == CRYPTO_ENCRYPT)
    {
      workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_ECB_ENC;
    }
    else
    {
      workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_ECB_DEC;
    }
  }
  else if(mode == CRYPTO_ALGOMODE_CTR)
  {
    /* CTR only has one cipherMode */
    workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_CTR;
  }
  else
  {
    /* CRYPTO_ALGOMODE_CBC */
    /* Check if ENCRYPT or DECRYPT, other services are not passed to HW part */
    if (service == CRYPTO_ENCRYPT)
    {
      workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_CBC_ENC;
    }
    else
    {
      workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_CBC_DEC;
    }
  }

  /* Set IV if required */
  if (ivLength == CRYPTO_30_HWA_AES_KEY_SIZE)
  {
    Crypto_30_Hwa_Hw_AesLoad(iv);
    HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WCV | workspace->custom.hwContext; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */
/* Crypto_30_Hwa_Hw_AesStart() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesProcessBlocks()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesProcessBlocks(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in,
  uint32 blockCount,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  uint32 index = 0u;
  uint32 blockCountInt = blockCount;
  register uint32 AESCTRL_Value = (workspace->custom.cipherMode & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext;

  /* Load first block */
  Crypto_30_Hwa_Hw_AesLoad(in);

  HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  blockCountInt--;

  while (blockCountInt > 0u)
  {
    index += CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
    /* Load next block */
    Crypto_30_Hwa_Hw_AesLoad(&in[index]);
    /* Wait while AES engine is busy */
    Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */
    /* Start operation */
    HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
    /* Save last block from backup register */
    Crypto_30_Hwa_Hw_AesSaveBackupRegister(&out[index - CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES]);
    blockCountInt--;
  }

  /* Wait while AES engine is busy */
  Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */
  /* Save final block */
  Crypto_30_Hwa_Hw_AesSave(&out[index]);

  return E_OK;
} /* Crypto_30_Hwa_Hw_AesProcessBlocks() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesFinish()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesFinish(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  CRYPTO_30_HWA_DUMMY_STATEMENT(workspace); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmStart(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key,
  uint8 keyLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) iv, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  uint32 ivLength)
{
  uint8 hValue[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES] = { 0u };

  register uint32 AESCTRL_Value;

  CRYPTO_30_HWA_DUMMY_STATEMENT(keyLength);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(ivLength);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  if (workspace->romKeyMapIndex != CRYPTO_30_HWA_ROMKEY_USE_IMPORTED_KEY)
  {
    workspace->custom.hwKeyslot = workspace->romKeyMapIndex << 4u;
  }
  else
#endif /*(CRYPTO_30_HWA_ROMKEY == STD_ON) */
  {
    /* #10 Set hardware keyslot and load key for CTR Encryption */
    workspace->custom.hwKeyslot = CRYPTO_30_HWA_AESCTRL_KEY2;

    /* Set key in AES accelerator */

    VStdMemCpy(workspace->custom.key, key, CRYPTO_30_HWA_AES_KEY_SIZE);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

    Crypto_30_Hwa_Hw_AesLoad(key);
    HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WK | workspace->custom.hwKeyslot; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  }

  /* #20 Calculate and set key for GHASH function */
   /* Load Zeros to input register */
  workspace->custom.hwContext = CRYPTO_30_HWA_AESCTRL_CV2;
  Crypto_30_Hwa_Hw_AesLoad(hValue);
  HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WCV | workspace->custom.hwContext;  /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

  /* Perform ECB encryption over input and store it */
  AESCTRL_Value = (CRYPTO_30_HWA_AESCTRL_ECB_ENC & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext; /* PRQA S 2986 */ /* MD_CRYPTO_30_HWA_2986_REDUNDANT_OP_AESCTRL */
  HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */
  Crypto_30_Hwa_Hw_AesSave(hValue);

  /* Load calculated value to CV1 */
  workspace->custom.hwContext = CRYPTO_30_HWA_AESCTRL_CV1;
  Crypto_30_Hwa_Hw_AesLoad(hValue);
  HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WCV | workspace->custom.hwContext;  /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  Crypto_30_Hwa_Hw_AesWaitBusy();/* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

  /* #40 Process IV */

  /* Set IV for CTR Encryption */
  workspace->custom.hwContext = CRYPTO_30_HWA_AESCTRL_CV0;
  Crypto_30_Hwa_Hw_AesLoad(iv);
  HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WCV | workspace->custom.hwContext;  /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

  /* #50 Perform dummy encryption to increase IV by 1 */
  workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_CTR;
  AESCTRL_Value = (workspace->custom.cipherMode & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext; /* PRQA S 2985 */ /* MD_CRYPTO_30_HWA_2985_REDUNDANT_OP */
  HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  Crypto_30_Hwa_Hw_AesWaitBusy();/* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

  if (workspace->primitiveInfo->service == CRYPTO_AEADENCRYPT)
  {
    workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_GCM_ENC;
  }
  else
  {
    workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_GCM_DEC;
  }

  return E_OK;
} /* Crypto_30_Hwa_Hw_AesGcmStart() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmProcessBlocksAad()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmProcessBlocksAad(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  uint32 blockCount,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr)
{
  uint32 block;
  uint8 tempDataBuffer[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES] = { 0u };

  uint32 cipherModeBackup = workspace->custom.cipherMode;

  workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_GCM_MAC;
  for (block = 0; block < blockCount; block++)
  {
    Crypto_30_Hwa_Hw_AesGcmProcessBlock(workspace, &inputPtr[block*CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES], CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES, tempDataBuffer);
  }

  workspace->custom.cipherMode = cipherModeBackup;

  return E_OK;
} /* Crypto_30_Hwa_Hw_AesGcmProcessBlocksAad() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmProcessLastBlockAad()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmProcessLastBlockAad(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength)
{
  uint8 tempOutputBuffer[16] = { 0u };

  uint32 cipherModeBackup = workspace->custom.cipherMode;
  workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_GCM_MAC;

  /* Process the last block of the AAD */
  Crypto_30_Hwa_Hw_AesGcmProcessBlock(workspace, inputPtr, inputLength, tempOutputBuffer);

  workspace->custom.cipherMode = cipherModeBackup;

  return E_OK;
} /* Crypto_30_Hwa_Hw_AesGcmProcessLastBlockAad() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmProcessBlocksInput()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmProcessBlocksInput(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  uint32 blockCount,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  uint32 block;

  for (block = 0; block < blockCount; block++)
  {
     Crypto_30_Hwa_Hw_AesGcmProcessBlock(workspace, &inputPtr[block*CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES],
      CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES, &outputPtr[block*CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES]);
  }

  return E_OK;
} /* Crypto_30_Hwa_Hw_AesGcmProcessBlocksInput() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmProcessLastBlockInput()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmProcessLastBlockInput(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  uint8 tmpCounter[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES] = { 0u };
  uint8 tmpInput[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES] = { 0u };

  /* #10 Check if service encrypt or decrypt */
  if (workspace->primitiveInfo->service == CRYPTO_AEADENCRYPT)
  {
    /* #20 Check if last plaintext block is smaller or equal to AES block size */
    if (inputLength < CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES)
    {
      /* #30 Store current counter value in temporary variable */
      register uint32 AESCTRL_Value = (CRYPTO_30_HWA_AESCTRL_RCV & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | CRYPTO_30_HWA_AESCTRL_CV0; /* PRQA S 2985 */ /* MD_CRYPTO_30_HWA_2985_REDUNDANT_OP */
      HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
      Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */
      Crypto_30_Hwa_Hw_AesSave(tmpCounter);

      /* #31 Write current counter to AES input */
      Crypto_30_Hwa_Hw_AesLoad(tmpCounter);

      /* #32 Encrypt the counter with the current key and AES ECB */
      AESCTRL_Value = (CRYPTO_30_HWA_AESCTRL_ECB_ENC & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext;  /* PRQA S 2986 */ /* MD_CRYPTO_30_HWA_2986_REDUNDANT_OP_AESCTRL */
      HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
      Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

      Crypto_30_Hwa_Hw_AesSave(tmpCounter);

      /* #33 Copy the content of the last block to a temporary buffer */
      VStdMemCpy(tmpInput, inputPtr, inputLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

      /* #34 Fill the remaining bytes  of the temporary buffer with the least significant bytes  of the encrypted counter */
      VStdMemCpy(&tmpInput[inputLength], &tmpCounter[inputLength], CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - inputLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

      /* #35 Process last block of the input */
      Crypto_30_Hwa_Hw_AesGcmProcessBlock(workspace, tmpInput, CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES, outputPtr);
    }
    else
    {
      /* #40 Last block is equal to AES block size. No padding necessary. */
      Crypto_30_Hwa_Hw_AesGcmProcessBlock(workspace, inputPtr, inputLength, outputPtr);
    }
  }
  else
  {
    /* #50 Check if last ciphertext block is smaller or equal to AES block size */
    if (inputLength < CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES)
    {
      /* #60 For service decrypt, clear unused bytes of input buffer and process the last block of the input */
      VStdMemClr(&inputPtr[inputLength], CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - inputLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    }

    Crypto_30_Hwa_Hw_AesGcmProcessBlock(workspace, inputPtr, inputLength, outputPtr);
  }

  return E_OK;
}/* Crypto_30_Hwa_Hw_AesGcmProcessLastBlockInput */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmFinish()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmFinish(
  Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace, /* PRQA S 3673 5 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputLengthPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) secondaryOutputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) secondaryOutputLengthPtr,
  uint32 aadProcessedLength,
  uint32 inputProcessedLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) ivPadded)
{

  Std_ReturnType retVal = E_OK;
  uint8 temp[16] = { 0u };

  register uint32 AESCTRL_Value;
  CRYPTO_30_HWA_DUMMY_STATEMENT(outputPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(outputLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /* #20 Concat length of processed AAD and processed input in reverse byte order */
  Crypto_30_Hwa_Uint32ToArrayByteSwap((aadProcessedLength << 3u), &temp[4]);
  Crypto_30_Hwa_Uint32ToArrayByteSwap((inputProcessedLength << 3u), &temp[12]);
  Crypto_30_Hwa_Hw_AesLoad(temp);

  /* #21 Load concatenated length into GHASH operation */
  workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_GCM_MAC;
  AESCTRL_Value = (workspace->custom.cipherMode & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext;
  HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

  /* #30 Load padded IV to GHASH function */
  Crypto_30_Hwa_Hw_AesLoad(ivPadded);
  workspace->custom.hwContext = CRYPTO_30_HWA_AESCTRL_CV0;
  workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_WCV;
  AESCTRL_Value = (workspace->custom.cipherMode & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext; /* PRQA S 2985 */ /* MD_CRYPTO_30_HWA_2985_REDUNDANT_OP */
  HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

  /* #31 Read intermediate value from GHASH calculation */
  workspace->custom.hwContext = CRYPTO_30_HWA_AESCTRL_CV2;
  workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_RCV;
  AESCTRL_Value = (workspace->custom.cipherMode & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext;
  HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */
  Crypto_30_Hwa_Hw_AesSave(temp);

  /* #32 Use intermediate value as input and perfrom CTR encryption */
  Crypto_30_Hwa_Hw_AesLoad(temp);

  workspace->custom.hwContext = CRYPTO_30_HWA_AESCTRL_CV0;
  workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_CTR;
  AESCTRL_Value = (workspace->custom.cipherMode & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext; /* PRQA S 2985 */ /* MD_CRYPTO_30_HWA_2985_REDUNDANT_OP */
  HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

  /* #40 Store final value as tag to secondary output */
  if (*secondaryOutputLengthPtr >= CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES)
  {
    if (*secondaryOutputLengthPtr > CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES)
    {
      *secondaryOutputLengthPtr = CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
    }

    Crypto_30_Hwa_Hw_AesSave(secondaryOutputPtr);
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */
/* Crypto_30_Hwa_Hw_AesGcmFinish() */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_GCM == STD_ON) */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmSivStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmSivStart(
  Crypto_30_Hwa_WorkSpaceGCMSIV_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key,
  uint8 keyLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) iv, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  uint32 ivLength)
{
  uint8 tmp[16u] = { 0u };
  uint8 tmpKeyData[16u] = { 0u };
  uint8_least index;

  /* #10 Get hardware context from driver object mapping */
  uint8 mappedDriverId = contextMapping[workspace->driverObjectId];
  workspace->custom.hwContext = mappedDriverId;

  /* #11 Set key */
#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  if(workspace->romKeyMapIndex != CRYPTO_30_HWA_ROMKEY_USE_IMPORTED_KEY)
  {
    workspace->custom.hwKeyslot = workspace->romKeyMapIndex << 4u;
  }
  else
#endif /*(CRYPTO_30_HWA_ROMKEY == STD_ON) */
  {
    /* add 2 to the keyid since key 0 and key 1 are locked */
    workspace->custom.hwKeyslot = ((uint32)mappedDriverId + 2u) << 4u;

    /* Set key in AES accelerator */
    Crypto_30_Hwa_Hw_AesLoad(key);
    HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WK | workspace->custom.hwKeyslot; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  }

  /* #12 Prepare input for key deviation */
  VStdLib_MemCpy(&tmp[4u], iv, ivLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  /* #13 Calculate subkey for authentication and cipher */
  for (index = 0u; index < 4u; index++)
  {
    Crypto_30_Hwa_Uint32ToArray(index, tmp);

    Crypto_30_Hwa_Hw_AesLoad(tmp);

    /* #14 Set ciphermode to AES ECB encryption */
    HSM_AES->AESCTRL = (CRYPTO_30_HWA_AESCTRL_ECB_ENC & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext; /* PRQA S 0306, 2986 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS, MD_CRYPTO_30_HWA_2986_REDUNDANT_OP_AESCTRL */

    /* Wait while AES engine is busy */
    Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

    Crypto_30_Hwa_Hw_AesSave(tmpKeyData);

    if (index < 2u)
    {
      /* #15 Calculate authentication key */
      VStdLib_MemCpy(&workspace->keyAuth[index * 8u], tmpKeyData, 8u);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    }
    else
    {
      /* #16 Calculate encrption key */
      VStdLib_MemCpy(&workspace->keyCipher[(index - 2u) * 8u], tmpKeyData, 8u);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    }
  }

  CRYPTO_30_HWA_DUMMY_STATEMENT( keyLength ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return E_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmSivTagFinalize()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmSivTagFinalize(
  Crypto_30_Hwa_WorkSpaceGCMSIV_PtrType workspace) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  uint8_least index;

  /* #10 Get hardware context from driver object mapping */
  uint8 mappedDriverId = contextMapping[workspace->driverObjectId];
  workspace->custom.hwContext = mappedDriverId;

  /* #11 XOR tag with nonce */
  for (index = 0u; index < 12u; index++)
  {
    workspace->tag[index] ^= workspace->nonce[index];
  }

  /* #12 Apply nonce mask */
  workspace->tag[CRYPTO_30_HWA_GHASH_BLOCK_SIZE - 1u] &= CRYPTO_30_HWA_TAG_MASK;

  /* #13 Set encryption key in AES accelerator */
  /* add 2 to the keyid since key 0 and key 1 are locked */
  workspace->custom.hwKeyslot = ((uint32)mappedDriverId + 2u) << 4u;

  Crypto_30_Hwa_Hw_AesLoad(workspace->keyCipher);
  HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WK | workspace->custom.hwKeyslot; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */

  /* #14 Load tag as AES input and encrypt with encryption key */
  Crypto_30_Hwa_Hw_AesLoad(workspace->tag);

  /* #15 Set ciphermode to AES ECB encryption */
  HSM_AES->AESCTRL = (CRYPTO_30_HWA_AESCTRL_ECB_ENC & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext;; /* PRQA S 0306, 2986 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS, MD_CRYPTO_30_HWA_2986_REDUNDANT_OP_AESCTRL */

  /* Wait while AES engine is busy */
  Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

  /* #16 Store encrypted tag */
  Crypto_30_Hwa_Hw_AesSave(workspace->tag);

  return E_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmSivAesCtrCryptionInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmSivAesCtrCryptionInit(
  Crypto_30_Hwa_WorkSpaceGCMSIV_PtrType workspace) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* #10 Get hardware context from driver object mapping */
  uint8 mappedDriverId = contextMapping[workspace->driverObjectId];
  workspace->custom.hwContext = mappedDriverId;

  /* #11 Set encryption key in AES accelerator */
  /* add 2 to the keyid since key 0 and key 1 are locked */
  workspace->custom.hwKeyslot = ((uint32)mappedDriverId + 2u) << 4u;

  Crypto_30_Hwa_Hw_AesLoad(workspace->keyCipher);
  HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WK | workspace->custom.hwKeyslot; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */

  return E_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_AesGcmSivAesCtrCryptionUpdate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_AesGcmSivAesCtrCryptionUpdate(
  Crypto_30_Hwa_WorkSpaceGCMSIV_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputLengthPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  uint8 tmp[16u] = { 0u };
  uint8_least xorIndex;
  uint32 counterValue;
  register uint32 AESCTRL_Value;

  /* #10 Get hardware context from driver object mapping */
  uint8 mappedDriverId = contextMapping[workspace->driverObjectId];
  workspace->custom.hwContext = mappedDriverId;

  AESCTRL_Value = (CRYPTO_30_HWA_AESCTRL_ECB_ENC & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext; /* PRQA S 2986 */ /* MD_CRYPTO_30_HWA_2986_REDUNDANT_OP_AESCTRL */

  /* #11 Encrypt current counter value with encryption key */
  Crypto_30_Hwa_Hw_AesLoad(workspace->counterCtr);

  HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */

  /* Wait while AES engine is busy */
  Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

  Crypto_30_Hwa_Hw_AesSave(tmp);

  /* #12 XOR counter with plain-/Ciphertext */
  for (xorIndex = 0; xorIndex < inputLength; xorIndex++)
  {
    outputPtr[xorIndex] = inputPtr[xorIndex] ^ tmp[xorIndex];
  }

  /* #13 Increment counter. If counter has reached 0xFFFFFFFF, set counter to 0 */
  counterValue = (((uint32)workspace->counterCtr[3u]) << 24u)
    | (((uint32)workspace->counterCtr[2u]) << 16u)
    | (((uint32)workspace->counterCtr[1u]) << 8u)
    | ((uint32)workspace->counterCtr[0u]);

  if (counterValue < CRYPTO_30_HWA_CTR_COUNTER_MAX_VALUE)
  {
    counterValue++;
  }
  else
  {
    counterValue = 0u;
  }

  workspace->counterCtr[3u] = (uint8)(counterValue >> 24u);
  workspace->counterCtr[2u] = (uint8)((counterValue >> 16u) & 0xFFu);
  workspace->counterCtr[1u] = (uint8)((counterValue >> 8u) & 0xFFu);
  workspace->counterCtr[0u] = (uint8)((counterValue) & 0xFFu);

  /* #14 Increase length pointer */
  *outputLengthPtr += inputLength;

  return E_OK;
}
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_GCMSIV == STD_ON) */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CmacStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CmacStart(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key)
{
  /* Configure hardware keyslot and context */
  uint8 mappedDriverId = contextMapping[workspace->driverObjectId];
  workspace->custom.hwContext = mappedDriverId;

  workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_CBC_ENC;

  /* Load empty IV */
  Crypto_30_Hwa_Hw_AesLoad(Crypto_30_Hwa_EmptyBlock);
  HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WCV | workspace->custom.hwContext; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */

#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  if (workspace->romKeyMapIndex != CRYPTO_30_HWA_ROMKEY_USE_IMPORTED_KEY)
  {
    workspace->custom.hwKeyslot = workspace->romKeyMapIndex << 4u;
  }
  else
#endif /* (CRYPTO_30_HWA_ROMKEY == STD_ON) */
  {
    /* add 2 to the keyid since key 0 and key 1 are locked */
    workspace->custom.hwKeyslot = ((uint32)mappedDriverId + 2u) << 4u;
    /* Set key in AES accelerator */
    Crypto_30_Hwa_Hw_AesLoad(key);
    HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WK | workspace->custom.hwKeyslot; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  }

  return E_OK;
} /* Crypto_30_Hwa_Hw_CmacStart() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CmacProcessBlocks()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CmacProcessBlocks(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in,
  uint32 blockCount)
{
  uint32 index = 0;
  uint32 blockCountInt = blockCount;
  uint32 AESCTRL_Value = (workspace->custom.cipherMode & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext;

  while (blockCountInt > 0u)
  {
    /* Load block into AES engine */
    Crypto_30_Hwa_Hw_AesLoad(&in[index]);
    /* Wait while AES engine is busy */
    Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */
    /* Start operation */
    HSM_AES->AESCTRL = AESCTRL_Value; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
    index += CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
    blockCountInt--;
  }

  return E_OK;
} /* Crypto_30_Hwa_Hw_CmacProcessBlocks() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CmacFinish()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CmacFinish(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outPtr,
  uint32 outLength)
{
  /* Save output from AES */
  Crypto_30_Hwa_Hw_AesSave(outPtr);
  CRYPTO_30_HWA_DUMMY_STATEMENT(workspace); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(outLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
} /* Crypto_30_Hwa_Hw_CmacFinish() */

# if (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_CmacSubkeys()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_CmacSubkeys(
  Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key)
{
  /* get hardware context from driver object mapping */
  uint8 mappedDriverId = contextMapping[workspace->driverObjectId];

  /* Configure hardware keyslot and context */
  workspace->custom.hwContext = mappedDriverId;
  workspace->custom.cipherMode = CRYPTO_30_HWA_AESCTRL_CBC_ENC;

#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  if (workspace->romKeyMapIndex != CRYPTO_30_HWA_ROMKEY_USE_IMPORTED_KEY)
  {
    workspace->custom.hwKeyslot = workspace->romKeyMapIndex << 4u;
  }
  else
#endif /* (CRYPTO_30_HWA_ROMKEY == STD_ON) */
  {

    /* add 2 to the keyid since key 0 and key 1 are locked */
    workspace->custom.hwKeyslot = ((uint32)mappedDriverId + 2u) << 4u;
    /* Set key in AES accelerator */
    Crypto_30_Hwa_Hw_AesLoad(key);
    HSM_AES->AESCTRL = CRYPTO_30_HWA_AESCTRL_WK | workspace->custom.hwKeyslot; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  }

  /* L := AES-128(K, const_Zero); */
  Crypto_30_Hwa_Hw_AesLoad(workspace->k1);
  HSM_AES->AESCTRL = (CRYPTO_30_HWA_AESCTRL_ECB_ENC & CRYPTO_30_HWA_AESCTRL_MODE_MASK) | workspace->custom.hwKeyslot | workspace->custom.hwContext; /* PRQA S 0306, 2986  */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS, MD_CRYPTO_30_HWA_2986_REDUNDANT_OP_AESCTRL */
  Crypto_30_Hwa_Hw_AesWaitBusy(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */
  Crypto_30_Hwa_Hw_AesSave(workspace->k1);

  return E_OK;
} /* Crypto_30_Hwa_Hw_CmacSubkeys() */
# endif /* (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) */

#if (CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Sha256Start()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Sha256Start(
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* Setup Hash accelerator for SHA256 computation, this also resets the hash engine */
  HSM_HASH->HASH_CFG = ( /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
    /* Set SHA256 mode */
    ((uint32)HASH_CFG_ALGO_SHA256 << HASH_CFG_ALGO_Pos) |
    /* Set input register to little endian mode */
    ((uint32)HASH_CFG_BEND_IN_LIT << HASH_CFG_BEND_IN_Pos) |
    /* Set output register to little endian mode */
    ((uint32)HASH_CFG_BEND_OUT_LIT << HASH_CFG_BEND_OUT_Pos) |
    /* Set output word sequence to most significant word first */
    ((uint32)HASH_CFG_ORDER_OUT_MSW_FIRST << HASH_CFG_ORDER_OUT_Pos) |
    /* Use no initialization vector, start from scratch */
    ((uint32)HASH_CFG_IV_MODE_NO_IV << HASH_CFG_IV_MODE_Pos));

  CRYPTO_30_HWA_DUMMY_STATEMENT(workspace); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
} /* Crypto_30_Hwa_Hw_Sha256Start() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Sha256ProcessBlocks()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Sha256ProcessBlocks(
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength)
{
  uint8_least i;

  /* Load the data in 32 bit packages into hardware */
  for (i = 0u; i < (inputLength/sizeof(uint32)); i++)
  {
    HSM_HASH->HASH_DATA = ((P2CONST(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))inputPtr)[i]; /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_HWA_0306_0310_3305_REGISTER_ACCESS_PERFORMANCE */
  }
  /* Wait till FIFO is empty again */
  Crypto_30_Hwa_Hw_Sha256WaitFifo(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

  CRYPTO_30_HWA_DUMMY_STATEMENT(workspace); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
} /* Crypto_30_Hwa_Hw_Sha256ProcessBlocks() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Sha256Finish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Sha256Finish(
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace, /* PRQA S 3673 3 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) hashsum,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) hashsumLength)
{
  uint64 length;
  boolean needExtraBlock;
  uint8_least word;

  /* Total size in bits */
  length = (uint64)8u * workspace->totalLength;

  /* Append high bit and zeros for padding */
  workspace->buffer[workspace->bufferFillLevel] = 0x80u;
  workspace->bufferFillLevel += 1u;
  VStdMemClr(&(workspace->buffer[workspace->bufferFillLevel]), (CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES - workspace->bufferFillLevel)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  /* Check if padding fits into this block (padding is 64 bit length information)  */
  needExtraBlock = (boolean)(workspace->bufferFillLevel > (CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES - 8u)); /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */

  if (needExtraBlock == FALSE)
  {
    /* No extra block required, add length information to finish padding */
    /* PRQA S 0310, 3305 2 */ /* MD_CRYPTO_30_HWA_0310_3305_PERFORMANCE */
    ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))workspace->buffer)[CRYPTO_30_HWA_HASH_BLOCK_SIZE_WORDS - 2u] = Crypto_30_Hwa_Hw_ByteSwap32((uint32)(length >> 32u));
    ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))workspace->buffer)[CRYPTO_30_HWA_HASH_BLOCK_SIZE_WORDS - 1u] = Crypto_30_Hwa_Hw_ByteSwap32((uint32)length);
  }

  /* Push block to hardware */
  for (word = 0u; word < CRYPTO_30_HWA_HASH_BLOCK_SIZE_WORDS; word++)
  {
    HSM_HASH->HASH_DATA = ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))workspace->buffer)[word]; /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_HWA_0306_0310_3305_REGISTER_ACCESS_PERFORMANCE */
  }
  workspace->bufferFillLevel = 0u;

  /* Wait till FIFO is empty again */
  Crypto_30_Hwa_Hw_Sha256WaitFifo(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */

  if (needExtraBlock == TRUE)
  {
    /* Extra block required for padding, push zeroes except last 64 bits */
    for (word = 0u; word < (CRYPTO_30_HWA_HASH_BLOCK_SIZE_WORDS - 2u); word++)
    {
      HSM_HASH->HASH_DATA = 0x00000000u; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
    }
    /* Add length information to finish padding */
    HSM_HASH->HASH_DATA = Crypto_30_Hwa_Hw_ByteSwap32((uint32)(length >> 32u)); /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
    HSM_HASH->HASH_DATA = Crypto_30_Hwa_Hw_ByteSwap32((uint32)length); /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */

    /* Wait till FIFO is empty again */
    Crypto_30_Hwa_Hw_Sha256WaitFifo(); /* PRQA S 2987 */ /* MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS */ /*lint !e522 */
  }

  /* Wait till hash engine finishes calculation */
  while ((HSM_HASH->HASH_STAT & HASH_STAT_BSY_Msk) != 0u) /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */ /* COV_CRYPTO_30_HWA_WAITLOOP_HARDWARE */
  {
    continue;
  }

  /* Read the hash result to output */
  (*hashsumLength) = Crypto_30_Hwa_Hw_Sha256_GetHashsum(hashsum, (*hashsumLength));

  return E_OK;
} /* Crypto_30_Hwa_Hw_Sha256Finish() */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_EcdsaGenerateFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_EcdsaGenerateFinish(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) curveParameters,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) privateKeyPtr,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) ephemeralKeyPtr,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputDataPtr, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputDataLengthPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  register uint32 pkcConfigValue;
  register uint32 pkcCommandValue;

  /* #10 Check if value of input parameter is valid */
  if (Crypto_30_Hwa_CompareBignumsBe(inputDataPtr,
                                     &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_ORDER_BASEPOINT_N_OFFSET],
                                     CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES) != CRYPTO_30_HWA_ECDSA_BIGNUM_SMALLER)
  {
    /* Message is equal or greater than n; Do nothing, return value is already set. */
  }
  else
  {
    /* #20 Load input parameters and curve parameters */
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R0, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_PRIME_FIELD_P_OFFSET]);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R2, inputDataPtr);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R3, privateKeyPtr);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R4, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_COEFF_A_OFFSET]);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R5, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_COEFF_B_OFFSET]);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R6, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_BASE_POINT_G_X_OFFSET]);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R7, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_BASE_POINT_G_Y_OFFSET]);

    /* #21 Load ephemeralKey */
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R8, ephemeralKeyPtr);

    /* #22 Calculate ek * P */
    pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R12 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
      ((uint32)CRYPTO_30_HWA_PKCSCM_R8 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
      ((uint32)CRYPTO_30_HWA_PKCSCM_R6 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

    pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP | CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_SMULT);

    retVal = Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_PBDL_PADD_SMULT);

    /* #23 Calculate d = xP mod n */
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R0, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_ORDER_BASEPOINT_N_OFFSET]);

    pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R9 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
      ((uint32)CRYPTO_30_HWA_PKCSCM_R12 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET));

    pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP | CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_RED);

    retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

    /* #24 Calculate z1 = (d * r) mod n */
    pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R11 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
      ((uint32)CRYPTO_30_HWA_PKCSCM_R9 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
      ((uint32)CRYPTO_30_HWA_PKCSCM_R3 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

    pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_MULTN);

    retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

    /* #25 Calculate z2 = (h + z1) mod n */
    pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R14 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
      ((uint32)CRYPTO_30_HWA_PKCSCM_R11 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
      ((uint32)CRYPTO_30_HWA_PKCSCM_R2 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

    pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_ADDN);

    retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

    /* #26 Calculate ek_inv */
    pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R1 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
      ((uint32)CRYPTO_30_HWA_PKCSCM_R8 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET));

    pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_INV);

    retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_INV_INV2);

    /* #27 Calculate s = (z2 * ek_inv) mod n */
    pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R10 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
      ((uint32)CRYPTO_30_HWA_PKCSCM_R14 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
      ((uint32)CRYPTO_30_HWA_PKCSCM_R1 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

    pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_MULTN);

    retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

    /* #28 Write signature to output and output length to output pointers */
    Crypto_30_Hwa_Hw_PkcSaveToBE(CRYPTO_30_HWA_PKCSCM_R9, &outputDataPtr[CRYPTO_30_HWA_ECDSA_SIGNATURE_R_OFFSET]);
    Crypto_30_Hwa_Hw_PkcSaveToBE(CRYPTO_30_HWA_PKCSCM_R10, &outputDataPtr[CRYPTO_30_HWA_ECDSA_SIGNATURE_S_OFFSET]);

    *outputDataLengthPtr = CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES * 2u;
  }

  CRYPTO_30_HWA_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(workspace); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(inputDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
} /* Crypto_30_Hwa_Hw_EcdsaGenerateFinish */ /* PRQA S 6060 */ /* MD_MSR_STPAR */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_EcdsaVerifyFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_EcdsaVerifyFinish(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) curveParameters,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) publicKeyPtr,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) signatureDataPtr,
  uint32 signatureDataLength,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) verifyPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal = E_NOT_OK;

  register uint32 pkcConfigValue;
  register uint32 pkcCommandValue;

  uint8 pkcTmpValue[CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES] = { 0u };

  *verifyPtr = CRYPTO_E_VER_NOT_OK;

  if (Crypto_30_Hwa_CompareBignumsBe(inputDataPtr,
                                     &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_ORDER_BASEPOINT_N_OFFSET],
                                     CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES) != CRYPTO_30_HWA_ECDSA_BIGNUM_SMALLER)
  {
    /* Message is equal or greater than n; Do nothing, return value is already set.*/
  }
  else
  {

    /* #20 Load signature */
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R2, signatureDataPtr);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R3, &signatureDataPtr[CRYPTO_30_HWA_ECDSA_SIGNATURE_S_OFFSET]);

    /* #21 Load initial curve parameters */
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R0, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_ORDER_BASEPOINT_N_OFFSET]);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R4, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_COEFF_A_OFFSET]);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R5, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_COEFF_B_OFFSET]);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R6, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_BASE_POINT_G_X_OFFSET]);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R7, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_BASE_POINT_G_Y_OFFSET]);

    /* #22 Load public key */
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R8, publicKeyPtr);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R9, &publicKeyPtr[CRYPTO_30_HWA_ECDSA_PUBLIC_KEY_COORD_Y_OFFSET]);

    /* #23 Load input */
    {
      Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R10, inputDataPtr);
    }

    /* #30 Calculate w */
    pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R1 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
                      ((uint32)CRYPTO_30_HWA_PKCSCM_R3 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET));

    pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP | CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_INV);

    retVal = Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_INV_INV2);

    /* #31 Calculate u1 */
    pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R12 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
                      ((uint32)CRYPTO_30_HWA_PKCSCM_R10 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
                      (CRYPTO_30_HWA_PKCSCM_R1 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

    pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_MULTN);

    retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

    /* #32 Calculate u2 */
    pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R13 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
                      ((uint32)CRYPTO_30_HWA_PKCSCM_R2 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
                      (CRYPTO_30_HWA_PKCSCM_R1 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

    /* Command value is already set from previous command */
    retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

    /* #40 Load prime field p */
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R0, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_PRIME_FIELD_P_OFFSET]);

    /* #50 Calculate P2 = u1 * P */
    pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R14 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
                      ((uint32)CRYPTO_30_HWA_PKCSCM_R12 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
                      (CRYPTO_30_HWA_PKCSCM_R6 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

    pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP | CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_SMULT);

    retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

    /* #51 Move u2 into R12 */
    Crypto_30_Hwa_Hw_PkcSaveToBE(CRYPTO_30_HWA_PKCSCM_R13, pkcTmpValue);
    Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R12, pkcTmpValue);

    /* #52 Calculate P3 = u2 * Q */
    pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R6 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
                      ((uint32)CRYPTO_30_HWA_PKCSCM_R12 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
                      (CRYPTO_30_HWA_PKCSCM_R8 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

    pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_SMULT);

    retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

    /* #53 Add P1 = P2 + P3 */
    pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R8 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
                      ((uint32)CRYPTO_30_HWA_PKCSCM_R14 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
                      (CRYPTO_30_HWA_PKCSCM_R6 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

    pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_PADD);

    retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_PBDL_PADD_SMULT);

    /* #54 Check if P1 lies on curve */
    retVal |= Crypto_30_Hwa_Hw_CheckPointOnCurveEcdsa(curveParameters);

    /* #55 Check if error occurred during previous operation */
    if (retVal == E_OK)
    {
      /* #60 Load n into R0 */
      Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R0, &curveParameters[CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_ORDER_BASEPOINT_N_OFFSET]);

      /* #61 Reduce x1 - v := x1 mod n */
      pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R10 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
        ((uint32)CRYPTO_30_HWA_PKCSCM_R8 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET));

      pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP | CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_RED);

      retVal = Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

      /* #62 Check if v - r mod n == 0 */
      Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R2, signatureDataPtr);

      pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R1 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
        ((uint32)CRYPTO_30_HWA_PKCSCM_R2 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
        (CRYPTO_30_HWA_PKCSCM_R10 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

      pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_SUBN);

      retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

      Crypto_30_Hwa_Hw_PkcSaveToBE(CRYPTO_30_HWA_PKCSCM_R1, pkcTmpValue);

      /* #63 Signature is valid if v - r mod n == 0 */
      if(Crypto_30_Hwa_IsBignumZeroBe(pkcTmpValue, CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES) == TRUE)
      {
        *verifyPtr = CRYPTO_E_VER_OK;
      }
    }
  }

  CRYPTO_30_HWA_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(workspace); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(inputDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(signatureDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
} /* Crypto_30_Hwa_Hw_EcdsaVerifyFinish */ /* PRQA S 6060, 6080 */ /* MD_MSR_STPAR, MD_MSR_STMIF */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Ed25519GenerateStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Ed25519GenerateStart(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace)
{
  CRYPTO_30_HWA_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(workspace); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return E_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Ed25519GenerateUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Ed25519GenerateUpdate(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength)
{
  CRYPTO_30_HWA_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(workspace); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(inputDataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(inputDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return E_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Ed25519GenerateFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Ed25519GenerateFinish(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) privateKeyPtr,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) contextDataPtr,
  uint32 contextDataLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputBufferPtr, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputBufferLengthPtr)
{
  Std_ReturnType retVal;

  register uint32 pkcConfigValue;
  register uint32 pkcCommandValue;

  uint8 pubKeyY[CRYPTO_30_HWA_EDDSA_ED25519_PUBLIC_KEY_SIZE_BYTES] = { 0u };
  uint8 digestK[CRYPTO_30_HWA_EDDSA_ED25519_SHA_2_512_SIZE_BYTES] = { 0u };
  uint32 digestKLength = sizeof(digestK);

  uint32 sigRXBn[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];
  uint32 sigRYBn[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];

  uint32 pubKeyXBn[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];
  uint32 pubKeyYBn[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];

  uint32 temp[CRYPTO_30_HWA_EDDSA_BN_DIGITS_512_BIT];
  uint32 r[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];
  uint32 a[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];

  uint32 kBigNum[CRYPTO_30_HWA_EDDSA_BN_DIGITS_512_BIT];
  uint32 kBigNumReduced[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];

  uint8 nonce[64u] = { 0u };
  uint32 nonceLength = sizeof(nonce);

  uint8 privKeyHash[64u] = { 0u };
  uint32 privKeyHashLength = sizeof(privKeyHash);

  /* #10 Calculate SHA512 over private key */
  retVal = CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_initHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_VSECPRIM_SHA_2_512, CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL));
  retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_ED25519_PRIVATE_KEY_SIZE_BYTES, privateKeyPtr));
  retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_finalizeHash(&workspace->vSecPrim_HashWorkSpace, &privKeyHashLength, privKeyHash));

  /* #11 Prune bytes 0 and 31 according to Ed25519 algorithm */
  privKeyHash[0u] &= 0xF8u;
  privKeyHash[31u] &= 0x7Fu;
  privKeyHash[31u] |= 0x40u;

  retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_initHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_VSECPRIM_SHA_2_512, CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL));

  if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_CTX) || (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PH))
  {
    retVal |= Crypto_30_Hwa_ProcessDom2Data(job, workspace, contextDataPtr, contextDataLength);
  }

  retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, 32, &privKeyHash[32]));
  retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, inputDataLength, inputDataPtr));
  retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_finalizeHash(&workspace->vSecPrim_HashWorkSpace, &nonceLength, nonce));

  /* #12 Convert private key from LE to bignum */
  Crypto_30_Hwa_Hw_LoadBNFromLE(privKeyHash, a, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT);

  /* #13 Multiply private key with base point and encode coordinates */
  retVal |= Crypto_30_Hwa_Hw_MultiplyWithBP(a, pubKeyXBn, pubKeyYBn);

  retVal |= Crypto_30_Hwa_Hw_CheckPointOnCurveEd25519(pubKeyXBn, pubKeyYBn);

  Crypto_30_Hwa_Hw_EncodePoint(pubKeyXBn, pubKeyYBn);

  /* #14 Reduce nonce from 64 byte SHA2-512 hash to 32 byte bignum */
  Crypto_30_Hwa_Hw_LoadBNFromLE(nonce, temp, CRYPTO_30_HWA_EDDSA_BN_DIGITS_512_BIT);
  Crypto_30_Hwa_Hw_ReducePrimeOrder(temp, r);

  Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R0, r);

  /* #15 Multiply reduced nonce with base point of curve Ed25519 */
  retVal |= Crypto_30_Hwa_Hw_MultiplyWithBP(r, sigRXBn, sigRYBn);

  retVal |= Crypto_30_Hwa_Hw_CheckPointOnCurveEd25519(sigRXBn, sigRYBn);

  Crypto_30_Hwa_Hw_EncodePoint(sigRXBn, sigRYBn);

  /* #16 Store Y coordinate of signature R point in output pointer */
  Crypto_30_Hwa_Hw_StoreBNToLE(sigRYBn, outputBufferPtr, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT);

  /* #17 Convert public key to little endian array */
  Crypto_30_Hwa_Hw_StoreBNToLE(pubKeyYBn, pubKeyY, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT);

  /* #18 Initialize SHA2-512 hash */
  retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_initHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_VSECPRIM_SHA_2_512, CRYPTO_30_HWA_VSECPRIM_HASH_OUTPUT_BUFFER_EQUAL));

  /* #19 Depending on mode, process context */
  if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_CTX) || (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519_PH))
  {
    retVal |= Crypto_30_Hwa_ProcessDom2Data(job, workspace, contextDataPtr, contextDataLength);
  }

  /* #20 Add signature R part, public key and message to SHA2-512 hash. In case of mode ph, the prehash is used instead of the original message */
  retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_R_SIZE_BYTES, outputBufferPtr));
  retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, CRYPTO_30_HWA_EDDSA_ED25519_PUBLIC_KEY_SIZE_BYTES, pubKeyY));
  retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_updateHash(&workspace->vSecPrim_HashWorkSpace, inputDataLength, inputDataPtr));

  /* #21 Retrieve hash digest as k */
  retVal |= CRYPTO_30_HWA_ESL_RETVAL(vSecPrim_finalizeHash(&workspace->vSecPrim_HashWorkSpace, &digestKLength, digestK));

  /* #22 Reduce k from 64 byte hash to 32 byte bignum */
  Crypto_30_Hwa_Hw_LoadBNFromLE(digestK, kBigNum, CRYPTO_30_HWA_EDDSA_BN_DIGITS_512_BIT);
  Crypto_30_Hwa_Hw_ReducePrimeOrder(kBigNum, kBigNumReduced);

  /* #23 Calculate intermediate = k * a mod n */
  Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R0, Crypto_30_Hwa_Hw_GroupOrder);
  Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R1, a);
  Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R2, kBigNumReduced);

  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R3 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
                    ((uint32)CRYPTO_30_HWA_PKCSCM_R2 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
                    (CRYPTO_30_HWA_PKCSCM_R1 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP | CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_MULTN);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #24 Calculate s = intermediate + r  mod n */
  Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R1, r);

  pkcConfigValue = (((uint32)CRYPTO_30_HWA_PKCSCM_R4 << CRYPTO_30_HWA_PKCCONFIG_OPPTRC_OFFSET) |
                    ((uint32)CRYPTO_30_HWA_PKCSCM_R3 << CRYPTO_30_HWA_PKCCONFIG_OPPTRB_OFFSET) |
                    (CRYPTO_30_HWA_PKCSCM_R1 << CRYPTO_30_HWA_PKCCONFIG_OPPTRA_OFFSET));

  pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_ADDN);

  retVal |= Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_NO_CHECK);

  /* #25 Store s in output pointer and set value of output length pointer */
  Crypto_30_Hwa_Hw_PkcSaveToLE(CRYPTO_30_HWA_PKCSCM_R4, &outputBufferPtr[CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_S_OFFSET]);

  *outputBufferLengthPtr = CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_R_SIZE_BYTES + CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_S_SIZE_BYTES;

  CRYPTO_30_HWA_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(workspace); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
} /* Crypto_30_Hwa_Hw_Ed25519GenerateFinish */ /* PRQA S 6050, 6060 */ /* MD_MSR_STCAL, MD_MSR_STPAR */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON)) */

#if ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Ed25519VerifyStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Ed25519VerifyStart(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace)
{
  CRYPTO_30_HWA_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(workspace); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return E_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Ed25519VerifyUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Ed25519VerifyUpdate(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength)
{
  CRYPTO_30_HWA_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(workspace); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(inputDataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(inputDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return E_OK;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_Ed25519VerifyFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_Ed25519VerifyFinish(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) publicKeyPtr,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputDataLength,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) signatureDataPtr,
  uint32 signatureDataLength,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) verifyPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal;

  uint32 pointRx[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];
  uint32 pointRy[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];
  uint32 pointAx[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];
  uint32 pointAy[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];
  uint32 h[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];
  uint32 tmp[CRYPTO_30_HWA_EDDSA_BN_DIGITS_512_BIT];
  uint32 s[CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT];

  register uint32 pkcConfigValue;
  register uint32 pkcCommandValue;

  *verifyPtr = CRYPTO_E_VER_NOT_OK;

  /* #10 Decode X- and Y-coordinate for signature part R */
  retVal = Crypto_30_Hwa_Hw_DecodePoint(pointRx, pointRy, signatureDataPtr);

  /* #11 Decode X- and Y-coordinate for public key */
  retVal |= Crypto_30_Hwa_Hw_DecodePoint(pointAx, pointAy, publicKeyPtr);

  /* #12 Check of decoded point for R is on curve */
  retVal |= Crypto_30_Hwa_Hw_CheckPointOnCurveEd25519(pointRx, pointRy);

  /* #13 Check of decoded point for public key is on curve */
  retVal |= Crypto_30_Hwa_Hw_CheckPointOnCurveEd25519(pointAx, pointAy);

  /* #14 Check if there were errors during decoding or point check */
  if(retVal == E_OK)
  {
    /* #20 Convert SHA512-hash to bignum */
    Crypto_30_Hwa_Hw_LoadBNFromLE(inputDataPtr, tmp, CRYPTO_30_HWA_EDDSA_BN_DIGITS_512_BIT);

    /* #21 Reduce SHA512-hash by prime order */
    Crypto_30_Hwa_Hw_ReducePrimeOrder(tmp, h);

    /* #22 Convert signature part S to bignum */
    Crypto_30_Hwa_Hw_LoadBNFromLE(&signatureDataPtr[CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_S_OFFSET], s, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT);

    if (Crypto_30_Hwa_Hw_CompareBignumsDigits(s, Crypto_30_Hwa_Hw_GroupOrder, CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT) != CRYPTO_30_HWA_ECDSA_BIGNUM_SMALLER)
    {
      retVal = E_NOT_OK;
    }
    else
    {
      /* #23 Load curve parameters, signature part S, h and point coordinates for public key and signature part R into PKC registers */
      Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R0, Crypto_30_Hwa_Hw_Ed25519CurveParameter);
      Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R1, &Crypto_30_Hwa_Hw_Ed25519CurveParameter[CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_D2_OFFSET]);
      Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R2, &Crypto_30_Hwa_Hw_Ed25519CurveParameter[CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_BASE_POINT_X_OFFSET]);
      Crypto_30_Hwa_Hw_PkcLoadFromBE(CRYPTO_30_HWA_PKCSCM_R3, &Crypto_30_Hwa_Hw_Ed25519CurveParameter[CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_BASE_POINT_Y_OFFSET]);
      Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R4, s);
      Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R5, h);
      Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R6, pointAx);
      Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R7, pointAy);
      Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R8, pointRx);
      Crypto_30_Hwa_Hw_PkcLoadFromBignum(CRYPTO_30_HWA_PKCSCM_R9, pointRy);

      pkcConfigValue = 0u;

      /* #24 Calculate equation s * B = R + k * A */
      pkcCommandValue = (CRYPTO_30_HWA_PKCCMD_CALCR2_CALCOP | CRYPTO_30_HWA_PKCCMD_SIZE_256BIT | CRYPTO_30_HWA_PKCCMD_CHECKVALID);

      /* #25 Check if signature is valid */
      if(Crypto_30_Hwa_Hw_PkcExecuteCommand(pkcConfigValue, pkcCommandValue, CRYPTO_30_HWA_PKC_STATUS_ERROR_MASK_CHECKVALID) != E_OK)
      {
        /* Calculation was executed correctly, but values were wrong. Return values are already set. */
      }
      else
      {
        *verifyPtr = CRYPTO_E_VER_OK; /* Signature was correctly verified. */
      }
    }
  }

  CRYPTO_30_HWA_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(workspace); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(inputDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(signatureDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
} /* Crypto_30_Hwa_Hw_Ed25519VerifyFinish */ /* PRQA S 6050, 6060 */ /* MD_MSR_STCAL, MD_MSR_STPAR */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON) && (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON)) */

#if (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_MemRand()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_MemRand(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) dstPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  uint32 length)
{
  uint32 currentPos = 0u;
  volatile uint32 tmp;

  while ((length - currentPos) > 0u)
  {
    /* Wait til random data is available */
    while ((HSM_TRNG->TRNG_STAT & CRYPTO_30_HWA_TRNG_STAT_DTA_RDY_MSK) != TRNG_STAT_DTA_RDY_RDY) /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
    {
      /* Check for FIPS error or low quality */
      if (((HSM_TRNG->TRNG_STAT & CRYPTO_30_HWA_TRNG_STAT_FIPS_ERR_MSK) == (TRNG_STAT_FIPS_ERR_ERROR << CRYPTO_30_HWA_TRNG_STAT_FIPS_ERR_POS)) || /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */ /* COV_CRYPTO_30_HWA_TRNG_POORDATA */
        ((HSM_TRNG->TRNG_STAT & CRYPTO_30_HWA_TRNG_STAT_WARN_MSK) == (TRNG_STAT_WARN_LOW << CRYPTO_30_HWA_TRNG_STAT_WARN_POS))) /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */ /* COV_CRYPTO_30_HWA_TRNG_POORDATA */
      {
        Crypto_30_Hwa_Hw_TrngDiscardBadData();
      }
    }
    if ((length - currentPos) >= sizeof(uint32))
    {
      /* Store complete words */
      ((P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR))dstPtr)[(currentPos / sizeof(uint32))] = HSM_TRNG->TRNG_DATA32; /* PRQA S 0306, 0310, 3305 */ /* MD_CRYPTO_30_HWA_0306_0310_3305_REGISTER_ACCESS_PERFORMANCE */
      currentPos += sizeof(uint32);
    }
    else
    {
      /* Store less than a word */
      tmp = HSM_TRNG->TRNG_DATA32; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
      VStdLib_MemCpy(&dstPtr[currentPos], (void*)&tmp, (length - currentPos)); /* PRQA S 0315, 0312, 0314 */ /* MD_MSR_VStdLibCopy, MD_CRYPTO_30_HWA_0312_VOLATILE_LOSS, MD_CRYPTO_30_HWA_0314_VOIDCAST */
      break;
    }
  }

  return E_OK;
} /* Crypto_30_Hwa_Hw_MemRand() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngRestart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_TrngRestart(void)
{
  volatile uint32 tmp;
  /* Disable the generator */
  HSM_TRNG->TRNG_CTRL = ((uint16)TRNG_CTRL_DIS_DIS << CRYPTO_30_HWA_TRNG_CTRL_DIS_POS); /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */

  /* Reset warning and error locks */
  HSM_TRNG->TRNG_STAT = (uint16)( /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
    /* The bit FIPS_ERR may be changed by writing to the SFR */
    ((uint16)TRNG_STAT_UNLOCK_FIPS_ERR_LOCK << CRYPTO_30_HWA_TRNG_STAT_UNLOCK_FIPS_ERR_POS) |
    /* The bit WARN may be changed by writing to the SFR */
    ((uint16)TRNG_STAT_UNLOCK_WARN_LOCK << CRYPTO_30_HWA_TRNG_STAT_UNLOCK_WARN_POS)
    );

  /* Enable it again */
  HSM_TRNG->TRNG_CTRL = (uint16)( /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
    /* Enable word width operation mode */
    ((uint16)TRNG_CTRL_DBS_WORD << CRYPTO_30_HWA_TRNG_CTRL_DBS_POS) |
    /* Enable the generator */
    ((uint16)TRNG_CTRL_DIS_EN << CRYPTO_30_HWA_TRNG_CTRL_DIS_POS)
    );
  /* Do a dummy read */
  tmp = HSM_TRNG->TRNG_DATA32; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  CRYPTO_30_HWA_DUMMY_STATEMENT(tmp);/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
} /* Crypto_30_Hwa_Hw_TrngRestart() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngDisableGenerator()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_TrngDisableGenerator(void)
{
  HSM_TRNG->TRNG_CTRL = (TRNG_CTRL_DIS_DIS << CRYPTO_30_HWA_TRNG_CTRL_DIS_POS); /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  NVIC_ClearPendingIRQ(TRNG_IRQn);
} /* Crypto_30_Hwa_Hw_TrngDisableGenerator() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngDiscardBadData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_TrngDiscardBadData(void) /* COV_CRYPTO_30_HWA_TRNG_POORDATA */
{
  volatile uint32 tmp;
  /* Discard bad random data */
  HSM_TRNG->TRNG_STAT = (uint16)( /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
                                                    /* The bit FIPS_ERR may be changed by writing to the SFR */
    ((uint16)TRNG_STAT_UNLOCK_FIPS_ERR_WE << CRYPTO_30_HWA_TRNG_STAT_UNLOCK_FIPS_ERR_POS) |
    /* The bit WARN may be changed by writing to the SFR */
    ((uint16)TRNG_STAT_UNLOCK_WARN_WE << CRYPTO_30_HWA_TRNG_STAT_UNLOCK_WARN_POS) |
    /* Clear FIPS error */
    ((uint16)TRNG_STAT_FIPS_ERR_OK << CRYPTO_30_HWA_TRNG_STAT_FIPS_ERR_POS) |
    /* Set status to not ready */
    ((uint16)TRNG_STAT_DTA_RDY_BUSY << CRYPTO_30_HWA_TRNG_STAT_DTA_RDY_POS)
    );

  /* Do a dummy read */
  tmp = HSM_TRNG->TRNG_DATA32; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */

  CRYPTO_30_HWA_DUMMY_STATEMENT(tmp);
}
#endif /* (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) */

#if (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_IsTrngOn()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_IsTrngOn(void)
{
  return ((HSM_TRNG->TRNG_CTRL & (TRNG_CTRL_DIS_DIS << CRYPTO_30_HWA_TRNG_CTRL_DIS_POS)) == 0u); /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
} /* Crypto_30_Hwa_Hw_IsTrngOn() */

#if (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngEnableIrq()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_TrngEnableIrq(void)
{
  uint32 tmp;
  NVIC_ClearPendingIRQ(TRNG_IRQn);
  /* Do a dummy read */
  tmp = HSM_TRNG->TRNG_DATA32; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
  NVIC_EnableIRQ(TRNG_IRQn);

  CRYPTO_30_HWA_DUMMY_STATEMENT(tmp); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngDisableIrq()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_TrngDisableIrq(void)
{
  NVIC_DisableIRQ(TRNG_IRQn);
}
#endif /* (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_ON) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngGetData()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_TrngGetData(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) dstPtr, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) lengthPtr)
{
  Std_ReturnType retval = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint32 data;
  /* in interrupt mode ready flag is always set trng produces random numbers */
  if ((HSM_TRNG->TRNG_STAT & CRYPTO_30_HWA_TRNG_STAT_DTA_RDY_MSK) != TRNG_STAT_DTA_RDY_RDY) /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */ /* COV_CRYPTO_30_HWA_TRNG_IRQ_DATARDY */
  {
    /* Check for FIPS error or low quality */
    if (((HSM_TRNG->TRNG_STAT & CRYPTO_30_HWA_TRNG_STAT_FIPS_ERR_MSK) == (TRNG_STAT_FIPS_ERR_ERROR << CRYPTO_30_HWA_TRNG_STAT_FIPS_ERR_POS)) || /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */ /* COV_CRYPTO_30_HWA_TRNG_POORDATA */
       ((HSM_TRNG->TRNG_STAT & CRYPTO_30_HWA_TRNG_STAT_WARN_MSK) == (TRNG_STAT_WARN_LOW << CRYPTO_30_HWA_TRNG_STAT_WARN_POS)))/* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */ /* COV_CRYPTO_30_HWA_TRNG_POORDATA */
    {
      Crypto_30_Hwa_Hw_TrngDiscardBadData();
    }
  }
  else
  {
    data = HSM_TRNG->TRNG_DATA32; /* PRQA S 0306 */ /* MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS */
    *lengthPtr = sizeof(data);
    VStdLib_MemCpy(dstPtr, &data, (*lengthPtr)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    retval = E_OK;
  }

  return retval;
}
#endif /* (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_KeyElementSet()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_KeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) keyPtr,
  uint32 keyLength)
{
  Std_ReturnType retVal = CRYPTO_E_NOT_HANDLED; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  CRYPTO_30_HWA_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  switch (keyElementId)
  {
    /* Check if a flash operation shall be performed */
  case CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION:
    if (keyLength == 1u)
    {
      switch (keyPtr[0])
      {
        /* Check if the Application core wants to write data flash */
      case CRYPTO_30_VHSM_DATAFLASH_START:
        vHsm_State.vHsm_DataflashPeLock = TRUE;
        retVal = E_OK;
        break;
        /* Check if the Application core finished writing data flash */
      case CRYPTO_30_VHSM_DATAFLASH_STOP:
        vHsm_State.vHsm_DataflashPeLock = FALSE;
        retVal = E_OK;
        break;
        /* Check if the Application core wants to write code flash */
      case CRYPTO_30_VHSM_CODEFLASH_START:
        /* Go in RAM loop in next main function cycle */
        vHsm_State.vHsm_StayInRamFlag = TRUE;
        /* Tell driver that we are not in RAM yet */
        vHsm_Ipc_LeaveRamExec(); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_HWA_0310_3305_PERFORMANCE */
        /* Delete flag from driver that RAM loop shall be exited */
        vHsm_Ipc_EndRamExec(); /* PRQA S 0310, 3305 */ /* MD_CRYPTO_30_HWA_0310_3305_PERFORMANCE */
        retVal = E_OK;
        break;
        /* Check if the Application core finished writing code flash */
      case CRYPTO_30_VHSM_CODEFLASH_STOP:
        retVal = E_OK;
        break;
      default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */ /* COV_CRYPTO_30_HWA_CASE_DEFAULT */
        break;
      }
    }
    break;
  default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */ /* COV_CRYPTO_30_HWA_CASE_DEFAULT */
    break;
  }

  return retVal;
} /* Crypto_30_Hwa_Hw_KeyElementSet() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_KeyElementGet()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Hw_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) resultPtr, /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) resultLengthPtr)
{
  CRYPTO_30_HWA_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(keyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(resultPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(resultLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return CRYPTO_E_NOT_HANDLED;
} /* Crypto_30_Hwa_Hw_KeyElementGet() */
#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define CRYPTO_30_HWA_START_SEC_CODE_ISR
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Hw_TrngIRQHandler()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_ISR1(Crypto_30_Hwa_Hw_TrngIRQHandler)
{
#if (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
# if (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  Crypto_30_Hwa_TrngProcessDataReady();
# endif
#endif
}

# define CRYPTO_30_HWA_STOP_SEC_CODE_ISR
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Module specific MISRA deviations
 *********************************************************************************************************************/
/* Module specific MISRA deviations:

MD_CRYPTO_30_HWA_0303_REGISTER_ACCESS:
Reason:     Access to registers of the hardware using an address.
Risk:       Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
Prevention: vHsm for specific hardware (pointer size type can not differ). Valid memory access with correct address covered by code review.

MD_CRYPTO_30_HWA_0306_REGISTER_ACCESS:
Reason:     Access to registers of the hardware using an address.
Risk:       Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
Prevention: vHsm for specific hardware (pointer size type can not differ). Valid memory access with correct address covered by code review.

MD_CRYPTO_30_HWA_0310_3305_PERFORMANCE:
Reason:     Atomic register access or performance improvement. Cast to 32 bit required to generate machine native 32 bit wide instructions.
Risk:       Casting to different object pointer type can result in runtime errors.
Example:    uint8* to uint32*. Can result in unaligned access or exceed array boundaries.
Prevention: Code review, tests. Access boundaries and alignment are checked before cast.

MD_CRYPTO_30_HWA_0306_0310_3305_REGISTER_ACCESS_PERFORMANCE
Reason:     Access to registers of the hardware using an address. The value is also cast to native data size.
Risk:       Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
Prevention: vHsm for specific hardware (pointer size type can not differ). Valid memory access with correct address covered by code review.

MD_CRYPTO_30_HWA_0312_VOLATILE_LOSS:
Reason:     Loss of volatile qualification on cast.
Risk:       May result in runtime errors due to compiler optimization.
Prevention: Code review, tests.

MD_CRYPTO_30_HWA_0314_VOIDCAST:
Reason:     Remove volatile qualifier to not get compiler warnings. Indicate that this happens on purpose.
Risk:       Qualifiers are lost
Prevention: Code review, tests.

MD_CRYPTO_30_HWA_0771_MULTIPLE_BREAK:
Reason:     Two break statements are implemented to provide simple yet efficient code.
Risk:       None
Prevention: N/A

MD_CRYPTO_30_HWA_2987_HARDWARE_ACCESS:
Reason:     Function call produces no side effects and is redundant. This is because QAC does not identify sideeffects for a register access.
Risk:       No risk.
Prevention: Code review, tests.

MD_CRYPTO_30_HWA_2985_REDUNDANT_OP:
Reason:       Value is ORed with value 0. The result is always the left hand operand.
Risk:         None
Prevention:   None

MD_CRYPTO_30_HWA_2986_REDUNDANT_OP_AESCTRL:
Reason:       Configuration value is stored in AES controll register. The result is always the right hand operand.
Risk:         None
Prevention:   None

MD_CRYPTO_30_HWA_3218_ECC_REDUCTION_PARAMETER
Reason:           Reduction parameter needs to be static, although it is only accessed in one function.
Risk:             None
Prevention:       Tests on hardware and review

MD_CRYPTO_30_HWA_3218_ONE_USAGE:
Reason:     Variable might be used only in one function but is declared on file level to ease up reading and ensure memory mapping and compiler abstraction.
Risk:       Could be accidentally used by another function
Prevention: Covered by code review and tests.
 */

/* COV_JUSTIFICATION_BEGIN

\ID COV_CRYPTO_30_HWA_NOTESTING
\ACCEPT     X
\REASON     Function is not covered because it is an interrupt handler or would trigger an reset.
\PREVENTION Covered by code review and manual tests.

\ID COV_CRYPTO_30_HWA_WAITLOOP_HARDWARE
\ACCEPT     XF
\REASON     This code is usually not executed because the hardware is too fast to trigger the wait.
\PREVENTION Covered by code review and tests

\ID COV_CRYPTO_30_HWA_TRNG_POORDATA
\ACCEPT     XF xf xf
\ACCEPT     TF tf xf
\ACCEPT     X
\REASON     This code is usually not executed because the hardware TRNG does not produce poor random data in testsuite.
\PREVENTION Covered by code review and tests

\ID COV_CRYPTO_30_HWA_TRNG_IRQ_DATARDY
\ACCEPT     XF
\REASON     This code is in configurations where prefetching is done with interrupts not executed because usually the interrupt is triggered by data ready event.
\PREVENTION Covered by code review and tests

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Hw.c
 *********************************************************************************************************************/


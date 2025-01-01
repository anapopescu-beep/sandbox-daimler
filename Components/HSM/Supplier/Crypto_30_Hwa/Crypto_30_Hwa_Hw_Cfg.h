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
/*!        \file  Crypto_30_Hwa_Hw_Cfg.h
 *        \brief  vHsm hardware abstraction platform configuration
 *
 *      \details  This files defines the configuration of the hardware specific implementation.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_HWA_HW_CFG_H)
# define CRYPTO_30_HWA_HW_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Size of data the hardware wants for hashing, in bytes */
# define CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES                               (64u)

/*! Size of data the hardware wants for hashing, in words */
# define CRYPTO_30_HWA_HASH_BLOCK_SIZE_WORDS                               (CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES / sizeof(uint32))

/*! Size of a SHA256 hash sum, in bytes */
# define CRYPTO_30_HWA_HASH_SHA256_SIZE_BYTES                              (256u / 8u)
# define CRYPTO_30_HWA_HASH_SHA256_SIZE_WORDS                              (CRYPTO_30_HWA_HASH_SHA256_SIZE_BYTES / sizeof(uint32))

/*! AES/CMAC/GCM defines */
# define CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES                                (16u)
# define CRYPTO_30_HWA_AES_BLOCK_SIZE_BITS                                 (128u)
# define CRYPTO_30_HWA_AES_BLOCK_SIZE_WORDS                                (CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES / sizeof(uint32))
# define CRYPTO_30_HWA_AES_BYTES_TO_BLOCKS(x)                              ((x) >> 4u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define CRYPTO_30_HWA_AES_BLOCKS_TO_BYTES(x)                              ((x) << 4u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define CRYPTO_30_HWA_AES_KEY_SIZE                                        (CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES)
# define CRYPTO_30_HWA_AESGCM_IV_LENGTH_BYTES                              (12u)
# define CRYPTO_30_HWA_AESGCMSIV_CTR_SIZE_BYTES                            (16u)
# define CRYPTO_30_HWA_AES256_KEY_SIZE_BYTES                               (32u)
# define CRYPTO_30_HWA_AES192_KEY_SIZE_BYTES                               (24u)

/*! GHASH defines */
# define CRYPTO_30_HWA_GHASH_BLOCK_SIZE                                    (16u)
# define CRYPTO_30_HWA_GHASH_WORD_SIZE                                     (4u)
# define CRYPTO_30_HWA_GHASH_WORDS_PER_BLOCK                               (CRYPTO_30_HWA_GHASH_BLOCK_SIZE/CRYPTO_30_HWA_GHASH_WORD_SIZE)
# define CRYPTO_30_HWA_GHASH_SPEED_UP                                      (1u)
# define CRYPTO_30_HWA_TAG_MASK                                            (0x7Fu)

/*! PKC Address defines */
#define CRYPTO_30_HWA_PKC_NUMBER_OF_REGISTERS                              (128u)
#define CRYPTO_30_HWA_PKC_ARRAY_INPUT_START_INDEX                          (28u)
#define CRYPTO_30_HWA_PKC_ARRAY_OUTPUT_START_INDEX                         (7u)
#define CRYPTO_30_HWA_PKC_ARRAY_CHUNK_SIZE_BYTES                           (4u)
#define CRYPTO_30_HWA_PKC_REGISTER_SIZE_WORD                               (8u)

#define CRYPTO_30_HWA_PKC_BASE_ADDRESS                                     (0xE8003C00uL)
#define CRYPTO_30_HWA_PKC_0_0_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0400u)
#define CRYPTO_30_HWA_PKC_0_1_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0404u)
#define CRYPTO_30_HWA_PKC_0_2_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0408u)
#define CRYPTO_30_HWA_PKC_0_3_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x040Cu)
#define CRYPTO_30_HWA_PKC_0_4_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0410u)
#define CRYPTO_30_HWA_PKC_0_5_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0414u)
#define CRYPTO_30_HWA_PKC_0_6_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0418u)
#define CRYPTO_30_HWA_PKC_0_7_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x041Cu)

#define CRYPTO_30_HWA_PKC_1_0_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0420u)
#define CRYPTO_30_HWA_PKC_1_1_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0424u)
#define CRYPTO_30_HWA_PKC_1_2_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0428u)
#define CRYPTO_30_HWA_PKC_1_3_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x042Cu)
#define CRYPTO_30_HWA_PKC_1_4_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0430u)
#define CRYPTO_30_HWA_PKC_1_5_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0434u)
#define CRYPTO_30_HWA_PKC_1_6_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0438u)
#define CRYPTO_30_HWA_PKC_1_7_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x043Cu)

#define CRYPTO_30_HWA_PKC_2_0_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0440u)
#define CRYPTO_30_HWA_PKC_2_1_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0444u)
#define CRYPTO_30_HWA_PKC_2_2_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0448u)
#define CRYPTO_30_HWA_PKC_2_3_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x044Cu)
#define CRYPTO_30_HWA_PKC_2_4_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0450u)
#define CRYPTO_30_HWA_PKC_2_5_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0454u)
#define CRYPTO_30_HWA_PKC_2_6_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0458u)
#define CRYPTO_30_HWA_PKC_2_7_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x045Cu)

#define CRYPTO_30_HWA_PKC_3_0_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0460u)
#define CRYPTO_30_HWA_PKC_3_1_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0464u)
#define CRYPTO_30_HWA_PKC_3_2_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0468u)
#define CRYPTO_30_HWA_PKC_3_3_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x046Cu)
#define CRYPTO_30_HWA_PKC_3_4_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0470u)
#define CRYPTO_30_HWA_PKC_3_5_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0474u)
#define CRYPTO_30_HWA_PKC_3_6_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0478u)
#define CRYPTO_30_HWA_PKC_3_7_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x047Cu)

#define CRYPTO_30_HWA_PKC_4_0_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0480u)
#define CRYPTO_30_HWA_PKC_4_1_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0484u)
#define CRYPTO_30_HWA_PKC_4_2_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0488u)
#define CRYPTO_30_HWA_PKC_4_3_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x048Cu)
#define CRYPTO_30_HWA_PKC_4_4_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0490u)
#define CRYPTO_30_HWA_PKC_4_5_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0494u)
#define CRYPTO_30_HWA_PKC_4_6_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0498u)
#define CRYPTO_30_HWA_PKC_4_7_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x049Cu)

#define CRYPTO_30_HWA_PKC_5_0_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04A0u)
#define CRYPTO_30_HWA_PKC_5_1_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04A4u)
#define CRYPTO_30_HWA_PKC_5_2_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04A8u)
#define CRYPTO_30_HWA_PKC_5_3_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04ACu)
#define CRYPTO_30_HWA_PKC_5_4_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04B0u)
#define CRYPTO_30_HWA_PKC_5_5_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04B4u)
#define CRYPTO_30_HWA_PKC_5_6_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04B8u)
#define CRYPTO_30_HWA_PKC_5_7_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04BCu)

#define CRYPTO_30_HWA_PKC_6_0_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04C0u)
#define CRYPTO_30_HWA_PKC_6_1_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04C4u)
#define CRYPTO_30_HWA_PKC_6_2_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04C8u)
#define CRYPTO_30_HWA_PKC_6_3_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04CCu)
#define CRYPTO_30_HWA_PKC_6_4_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04D0u)
#define CRYPTO_30_HWA_PKC_6_5_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04D4u)
#define CRYPTO_30_HWA_PKC_6_6_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04D8u)
#define CRYPTO_30_HWA_PKC_6_7_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04DCu)

#define CRYPTO_30_HWA_PKC_7_0_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04E0u)
#define CRYPTO_30_HWA_PKC_7_1_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04E4u)
#define CRYPTO_30_HWA_PKC_7_2_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04E8u)
#define CRYPTO_30_HWA_PKC_7_3_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04ECu)
#define CRYPTO_30_HWA_PKC_7_4_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04F0u)
#define CRYPTO_30_HWA_PKC_7_5_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04F4u)
#define CRYPTO_30_HWA_PKC_7_6_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04F8u)
#define CRYPTO_30_HWA_PKC_7_7_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x04FCu)

#define CRYPTO_30_HWA_PKC_8_0_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0500u)
#define CRYPTO_30_HWA_PKC_8_1_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0504u)
#define CRYPTO_30_HWA_PKC_8_2_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0508u)
#define CRYPTO_30_HWA_PKC_8_3_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x050Cu)
#define CRYPTO_30_HWA_PKC_8_4_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0510u)
#define CRYPTO_30_HWA_PKC_8_5_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0514u)
#define CRYPTO_30_HWA_PKC_8_6_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0518u)
#define CRYPTO_30_HWA_PKC_8_7_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x051Cu)

#define CRYPTO_30_HWA_PKC_9_0_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0520u)
#define CRYPTO_30_HWA_PKC_9_1_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0524u)
#define CRYPTO_30_HWA_PKC_9_2_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0528u)
#define CRYPTO_30_HWA_PKC_9_3_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x052Cu)
#define CRYPTO_30_HWA_PKC_9_4_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0530u)
#define CRYPTO_30_HWA_PKC_9_5_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0534u)
#define CRYPTO_30_HWA_PKC_9_6_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0538u)
#define CRYPTO_30_HWA_PKC_9_7_ADDRESS                                      (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x053Cu)

#define CRYPTO_30_HWA_PKC_10_0_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0540u)
#define CRYPTO_30_HWA_PKC_10_1_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0544u)
#define CRYPTO_30_HWA_PKC_10_2_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0548u)
#define CRYPTO_30_HWA_PKC_10_3_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x054Cu)
#define CRYPTO_30_HWA_PKC_10_4_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0550u)
#define CRYPTO_30_HWA_PKC_10_5_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0554u)
#define CRYPTO_30_HWA_PKC_10_6_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0558u)
#define CRYPTO_30_HWA_PKC_10_7_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x055Cu)

#define CRYPTO_30_HWA_PKC_11_0_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0560u)
#define CRYPTO_30_HWA_PKC_11_1_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0564u)
#define CRYPTO_30_HWA_PKC_11_2_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0568u)
#define CRYPTO_30_HWA_PKC_11_3_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x056Cu)
#define CRYPTO_30_HWA_PKC_11_4_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0570u)
#define CRYPTO_30_HWA_PKC_11_5_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0574u)
#define CRYPTO_30_HWA_PKC_11_6_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0578u)
#define CRYPTO_30_HWA_PKC_11_7_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x057Cu)

#define CRYPTO_30_HWA_PKC_12_0_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0580u)
#define CRYPTO_30_HWA_PKC_12_1_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0584u)
#define CRYPTO_30_HWA_PKC_12_2_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0588u)
#define CRYPTO_30_HWA_PKC_12_3_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x058Cu)
#define CRYPTO_30_HWA_PKC_12_4_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0590u)
#define CRYPTO_30_HWA_PKC_12_5_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0594u)
#define CRYPTO_30_HWA_PKC_12_6_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x0598u)
#define CRYPTO_30_HWA_PKC_12_7_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x059Cu)

#define CRYPTO_30_HWA_PKC_13_0_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05A0u)
#define CRYPTO_30_HWA_PKC_13_1_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05A4u)
#define CRYPTO_30_HWA_PKC_13_2_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05A8u)
#define CRYPTO_30_HWA_PKC_13_3_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05ACu)
#define CRYPTO_30_HWA_PKC_13_4_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05B0u)
#define CRYPTO_30_HWA_PKC_13_5_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05B4u)
#define CRYPTO_30_HWA_PKC_13_6_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05B8u)
#define CRYPTO_30_HWA_PKC_13_7_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05BCu)

#define CRYPTO_30_HWA_PKC_14_0_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05C0u)
#define CRYPTO_30_HWA_PKC_14_1_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05C4u)
#define CRYPTO_30_HWA_PKC_14_2_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05C8u)
#define CRYPTO_30_HWA_PKC_14_3_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05CCu)
#define CRYPTO_30_HWA_PKC_14_4_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05D0u)
#define CRYPTO_30_HWA_PKC_14_5_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05D4u)
#define CRYPTO_30_HWA_PKC_14_6_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05D8u)
#define CRYPTO_30_HWA_PKC_14_7_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05DCu)

#define CRYPTO_30_HWA_PKC_15_0_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05E0u)
#define CRYPTO_30_HWA_PKC_15_1_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05E4u)
#define CRYPTO_30_HWA_PKC_15_2_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05E8u)
#define CRYPTO_30_HWA_PKC_15_3_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05ECu)
#define CRYPTO_30_HWA_PKC_15_4_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05F0u)
#define CRYPTO_30_HWA_PKC_15_5_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05F4u)
#define CRYPTO_30_HWA_PKC_15_6_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05F8u)
#define CRYPTO_30_HWA_PKC_15_7_ADDRESS                                     (CRYPTO_30_HWA_PKC_BASE_ADDRESS + 0x05FCu)

/* ECDSA defines */
# define CRYPTO_30_HWA_ECDSA_PUBLIC_KEY_SIZE_BYTES                         (64u)
# define CRYPTO_30_HWA_ECDSA_PRIVATE_KEY_SIZE_BYTES                        (32u)
# define CRYPTO_30_HWA_ECDSA_EPHEMERAL_KEY_SIZE_BYTES                      (32u)
# define CRYPTO_30_HWA_ECDSA_BLOCK_SIZE_BYTES                              (32u)
# define CRYPTO_30_HWA_ECDSA_BIGNUM_SMALLER                                (0x10u)
# define CRYPTO_30_HWA_ECDSA_BIGNUM_EQUAL                                  (0x11u)
# define CRYPTO_30_HWA_ECDSA_BIGNUM_LARGER                                 (0x12u)
# define CRYPTO_30_HWA_ECDSA_CURVE_P2561_PARAMETER_ARRAY_SIZE_BYTES        (192u)
# define CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_COEFF_A_OFFSET                (0u)
# define CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_COEFF_B_OFFSET                (32u)
# define CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_PRIME_FIELD_P_OFFSET          (64u)
# define CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_BASE_POINT_G_X_OFFSET         (96u)
# define CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_BASE_POINT_G_Y_OFFSET         (128u)
# define CRYPTO_30_HWA_ECDSA_CURVE_PARAMETER_ORDER_BASEPOINT_N_OFFSET      (160u)
# define CRYPTO_30_HWA_ECDSA_SIGNATURE_R_OFFSET                            (0u)
# define CRYPTO_30_HWA_ECDSA_SIGNATURE_S_OFFSET                            (32u)
# define CRYPTO_30_HWA_ECDSA_SIGNATURE_R_SIZE_BYTES                        (32u)
# define CRYPTO_30_HWA_ECDSA_SIGNATURE_S_SIZE_BYTES                        (32u)
# define CRYPTO_30_HWA_ECDSA_PUBLIC_KEY_COORD_X_OFFSET                     (0u)
# define CRYPTO_30_HWA_ECDSA_PUBLIC_KEY_COORD_Y_OFFSET                     (32u)

/*! EDDSA defines */
# define CRYPTO_30_HWA_EDDSA_ED25519_PUBLIC_KEY_SIZE_BYTES                 (32u)
# define CRYPTO_30_HWA_EDDSA_ED25519_PRIVATE_KEY_SIZE_BYTES                (32u)
# define CRYPTO_30_HWA_EDDSA_ED25519_SHA_2_512_SIZE_BYTES                  (64u)
# define CRYPTO_30_HWA_EDDSA_ED25519MASK_MSBIT                             (0x7FFFFFFFu)
# define CRYPTO_30_HWA_EDDSA_VSECPRIM_SHA_2_512                            (0x04u)
# define CRYPTO_30_HWA_EDDSA_BN_DIGITS_256_BIT                             (8u)
# define CRYPTO_30_HWA_EDDSA_BN_DIGITS_512_BIT                             (16u)
# define CRYPTO_30_HWA_EDDSA_BN_BYTES                                      (32u)
# define CRYPTO_30_HWA_EDDSA_BN_BITS_PER_DIGIT                             (32u)
# define CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_R_SIZE_BYTES           (32u)
# define CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_S_SIZE_BYTES           (32u)
# define CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_R_OFFSET               (0u)
# define CRYPTO_30_HWA_EDDSA_ED25519_SIGNATURE_PART_S_OFFSET               (32u)
# define CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_PRIME_OFFSET              (0u)
# define CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_PRIME38_OFFSET            (32u)
# define CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_CONST_D_OFFSET            (64u)
# define CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_SQRTM1_OFFSET             (96u)
# define CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_D2_OFFSET                 (128u)
# define CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_BASE_POINT_X_OFFSET       (160u)
# define CRYPTO_30_HWA_EDDSA_ED25519_CURVE_PARAM_BASE_POINT_Y_OFFSET       (192u)
# define CRYPTO_30_HWA_EDDSA_ED25519_DOM2_LENGTH                           (32u)
# define CRYPTO_30_HWA_SIGNATURE_SIZE_BYTES                                (64u)
# define CRYPTO_30_HWA_EDDSA_ED25519_GO_BARRET_SIZE_DIGITS                 (9u)
# define CRYPTO_30_HWA_EDDSA_CURVE_PARAMETER_SIZE_BYTE                     (224u)
# define CRYPTO_30_HWA_EDDSA_CONTEXT_MAX_SIZE_BYTE                         (255u)

/*! Size of data the hardware can output in one call */
# define CRYPTO_30_HWA_TRNG_BLOCK_LENGTH_BYTES                             (4u)

/*! Platforms native alignment mask */
# define CRYPTO_30_HWA_ALIGNMENT_MASK                                      (3u)

/*! Hardware ROM_KEY support */
# define CRYPTO_30_HWA_ROMKEY                                              CRYPTO_30_HWA_KEYMAP
# define CRYPTO_30_HWA_ROMKEY_MASK                                         (30000u)
# define CRYPTO_30_HWA_ROMKEY_USE_IMPORTED_KEY                             (255u)

/*! Hardware specific primitives */
# define CRYPTO_30_HWA_HARDWARE_CMAC                                       STD_OFF
# define CRYPTO_30_HWA_HARDWARE_AES_CTR                                    STD_ON
# define CRYPTO_30_HWA_HARDWARE_AES256                                     STD_OFF
# define CRYPTO_30_HWA_HARDWARE_AES192                                     STD_OFF
# define CRYPTO_30_HWA_HARDWARE_PKC                                        STD_ON

/* Context for GCM driver object. */
# define CRYPTO_30_HWA_HW_GCM_CONTEXT                                      2u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* do not use this section */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* do not use this section */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/* do not use this section */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* CRYPTO_30_HWA_HW_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Hw_Cfg.h
 *********************************************************************************************************************/

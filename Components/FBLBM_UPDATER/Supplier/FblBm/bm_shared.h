/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Main module of BM
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  04.00.00   2019-10-10  vistmo  FBL-390          No changes
 *  04.00.01   2019-11-05  visrie  ESCAN00104616    No changes
 *                                 ESCAN00104790    No changes
 *  05.00.00   2019-12-04  visrie  FBL-456          No changes
 *                                 ESCAN00104644    No changes
 *                                 ESCAN00105176    No changes
 *  05.01.00   2020-01-13  visrie  ESCAN00104481    No changes
 *                                 FBL-953          No changes
 *  05.02.00   2020-02-28  vistbe  FBL-949          No changes
 *  06.00.00   2020-04-08  visrie  FBL-1016         No changes
 *  06.00.01   2020-04-08  visrie  ESCAN00106837    No changes
 *  06.00.02   2020-10-28  visrcn  ESCAN00107189    No changes
 *  06.01.00   2021-08-11  visrie  FBL-3394         No changes
 *  06.02.00   2022-02-04  visrie  FBL-4602         No changes
 *  06.02.01   2022-04-06  vismix  ESCAN00111029    No changes
 *  06.03.00   2022-04-08  visrie  FBL-4126         No changes
 *  06.04.00   2022-04-11  vishor  FBL-4822         Add support for new MagicFlag value and Swap API
 *  06.04.01   2022-04-28  vismix  ESCAN00111741    No changes
 *  06.05.00   2022-05-06  vishor  FBL-5148         Encapsulate call of FblInterruptDisable
 *  06.06.00   2022-07-13  vismix  FBL-5391         No changes
 *  06.06.01   2022-08-04  visjns  ESCAN00112070    No changes
 *  06.07.00   2022-11-07  vishor  FBL-4932         No changes
 *  06.08.00   2022-11-30  visrie  FBL-6065         No changes
 **********************************************************************************************************************/

#ifndef BM_SHARED_H
#define BM_SHARED_H

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Remap of FBL specific switch to BM switch */
#if !defined( FBLBM_MAIN_ENABLE_FBL_START ) && \
    !defined( FBLBM_MAIN_DISABLE_FBL_START )
# if defined( FBL_ENABLE_FBL_START )
#  define FBLBM_MAIN_ENABLE_FBL_START
# endif
#endif

#if !defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT ) && \
    !defined( FBLBM_MAIN_DISABLE_STAY_IN_BOOT )
# if defined( FBL_ENABLE_STAY_IN_BOOT )
#  define FBLBM_MAIN_ENABLE_STAY_IN_BOOT
# endif
#endif

#if !defined( FBLBM_MAIN_ENABLE_HARDWARE_SWAP ) && \
    !defined( FBLBM_MAIN_DISABLE_HARDWARE_SWAP )
# if defined( FBL_ENABLE_HARDWARE_SWAP )
#  define FBLBM_MAIN_ENABLE_HARDWARE_SWAP
# endif
#endif

#if !defined( FBLBM_MAIN_ENABLE_INTERRUPT_DISABLE_AT_POWER_ON ) && \
    !defined( FBLBM_MAIN_DISABLE_INTERRUPT_DISABLE_AT_POWER_ON )
# if defined( FBL_ENABLE_INTERRUPT_DISABLE_AT_POWER_ON )
#  define FBLBM_MAIN_ENABLE_INTERRUPT_DISABLE_AT_POWER_ON
# endif
#endif

#if !defined( FBLBM_MAIN_ENABLE_MAGICFLAG ) && \
    !defined( FBLBM_MAIN_DISABLE_MAGICFLAG )
# if defined( FBLBM_MAIN_ENABLE_FBL_START )        || \
     defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT )     || \
     (defined( FBLBM_ENABLE_SECURE_BOOT )       && \
         (defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY ) || \
          defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC ) || \
          defined( FBLBM_MAIN_ENABLE_HARDWARE_SWAP ))     \
     )
/** Enable magic flag in case of known magic flag configuration */
#  define FBLBM_MAIN_ENABLE_MAGICFLAG
# endif
#endif

/***********************************************************************************************************************
 *  DEFINES (MAGIC FLAG)
 **********************************************************************************************************************/

#if defined( FBLBM_MAIN_ENABLE_MAGICFLAG )
# define kFblBmNoOfMagicBytes          8u
# define kFblBmClearMagicByte          0x00u
# define FblBmClrMagicFlag()                    \
{                                               \
   fblBmMagicFlag[0u] = kFblBmClearMagicByte;   \
   fblBmMagicFlag[1u] = kFblBmClearMagicByte;   \
   fblBmMagicFlag[2u] = kFblBmClearMagicByte;   \
   fblBmMagicFlag[3u] = kFblBmClearMagicByte;   \
   fblBmMagicFlag[4u] = kFblBmClearMagicByte;   \
   fblBmMagicFlag[5u] = kFblBmClearMagicByte;   \
   fblBmMagicFlag[6u] = kFblBmClearMagicByte;   \
   fblBmMagicFlag[7u] = kFblBmClearMagicByte;   \
}
/* PRQA S 0342 11 */ /* MD_MSR_Rule20.10_0342 */
# define FblBmSetMagicFlag(infix)                        \
{                                                        \
   fblBmMagicFlag[0u] = kFblBm ## infix ## MagicByte0;   \
   fblBmMagicFlag[1u] = kFblBm ## infix ## MagicByte1;   \
   fblBmMagicFlag[2u] = kFblBm ## infix ## MagicByte2;   \
   fblBmMagicFlag[3u] = kFblBm ## infix ## MagicByte3;   \
   fblBmMagicFlag[4u] = kFblBm ## infix ## MagicByte4;   \
   fblBmMagicFlag[5u] = kFblBm ## infix ## MagicByte5;   \
   fblBmMagicFlag[6u] = kFblBm ## infix ## MagicByte6;   \
   fblBmMagicFlag[7u] = kFblBm ## infix ## MagicByte7;   \
}
/* PRQA S 0342 9 */ /* MD_MSR_Rule20.10_0342 */
# define FblBmChkMagicFlag(infix)                              \
   ((    (fblBmMagicFlag[0u] == kFblBm ## infix ## MagicByte0) \
      && (fblBmMagicFlag[1u] == kFblBm ## infix ## MagicByte1) \
      && (fblBmMagicFlag[2u] == kFblBm ## infix ## MagicByte2) \
      && (fblBmMagicFlag[3u] == kFblBm ## infix ## MagicByte3) \
      && (fblBmMagicFlag[4u] == kFblBm ## infix ## MagicByte4) \
      && (fblBmMagicFlag[5u] == kFblBm ## infix ## MagicByte5) \
      && (fblBmMagicFlag[6u] == kFblBm ## infix ## MagicByte6) \
      && (fblBmMagicFlag[7u] == kFblBm ## infix ## MagicByte7)) ? 1u : 0u)

# if defined( FBLBM_MAIN_ENABLE_FBL_START )
/* Define pattern for magic flags used for UDS reprogramming indication */
#  define kFblBmFblStartMagicByte0        0x50u /* 'P' */
#  define kFblBmFblStartMagicByte1        0x72u /* 'r' */
#  define kFblBmFblStartMagicByte2        0x6Fu /* 'o' */
#  define kFblBmFblStartMagicByte3        0x67u /* 'g' */
#  define kFblBmFblStartMagicByte4        0x53u /* 'S' */
#  define kFblBmFblStartMagicByte5        0x69u /* 'i' */
#  define kFblBmFblStartMagicByte6        0x67u /* 'g' */
#  define kFblBmFblStartMagicByte7        0x6Eu /* 'n' */
#  define FblBmSetFblStartMagicFlag()     FblBmSetMagicFlag(FblStart)
#  define FblBmChkFblStartMagicFlag()     FblBmChkMagicFlag(FblStart)
# endif /* FBLBM_MAIN_ENABLE_FBL_START */

# if defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT )
/* Define pattern for magic flags used for application start */
#  define kFblBmApplStartMagicByte0       0x41u /* 'A' */
#  define kFblBmApplStartMagicByte1       0x70u /* 'p' */
#  define kFblBmApplStartMagicByte2       0x70u /* 'p' */
#  define kFblBmApplStartMagicByte3       0x6Cu /* 'l' */
#  define kFblBmApplStartMagicByte4       0x53u /* 'S' */
#  define kFblBmApplStartMagicByte5       0x69u /* 'i' */
#  define kFblBmApplStartMagicByte6       0x67u /* 'g' */
#  define kFblBmApplStartMagicByte7       0x6Eu /* 'n' */
#  define FblBmSetApplStartMagicFlag()    FblBmSetMagicFlag(ApplStart)
#  define FblBmChkApplStartMagicFlag()    FblBmChkMagicFlag(ApplStart)

/* Define pattern for magic flags used if Bootloader should check for stay in boot message */
#  define kFblBmStayInBootMagicByte0      0x53u /* 'S' */
#  define kFblBmStayInBootMagicByte1      0x74u /* 't' */
#  define kFblBmStayInBootMagicByte2      0x61u /* 'a' */
#  define kFblBmStayInBootMagicByte3      0x79u /* 'y' */
#  define kFblBmStayInBootMagicByte4      0x42u /* 'B' */
#  define kFblBmStayInBootMagicByte5      0x6Fu /* 'o' */
#  define kFblBmStayInBootMagicByte6      0x6Fu /* 'o' */
#  define kFblBmStayInBootMagicByte7      0x74u /* 't' */
#  define FblBmSetStayInBootMagicFlag()   FblBmSetMagicFlag(StayInBoot)
#  define FblBmChkStayInBootMagicFlag()   FblBmChkMagicFlag(StayInBoot)
# endif /* FBLBM_MAIN_ENABLE_STAY_IN_BOOT */

# if defined( FBLBM_ENABLE_SECURE_BOOT )
#  if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY )
/* Define pattern for magic flags used if Bootloader should initialize the keys and generate/write CMAC */
#   define kFblBmInitKeysMagicByte0       0x49u /* 'I' */
#   define kFblBmInitKeysMagicByte1       0x6Eu /* 'n' */
#   define kFblBmInitKeysMagicByte2       0x69u /* 'i' */
#   define kFblBmInitKeysMagicByte3       0x74u /* 't' */
#   define kFblBmInitKeysMagicByte4       0x4Bu /* 'K' */
#   define kFblBmInitKeysMagicByte5       0x65u /* 'e' */
#   define kFblBmInitKeysMagicByte6       0x79u /* 'y' */
#   define kFblBmInitKeysMagicByte7       0x73u /* 's' */
#   define FblBmSetInitKeysMagicFlag()    FblBmSetMagicFlag(InitKeys)
#   define FblBmChkInitKeysMagicFlag()    FblBmChkMagicFlag(InitKeys)
#  endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY */

#  if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY ) || \
      defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
/* Define pattern for magic flags used if Bootloader should initialize the keys and generate/write CMAC */
#   define kFblBmInitCmacMagicByte0       0x49u /* 'I' */
#   define kFblBmInitCmacMagicByte1       0x6Eu /* 'n' */
#   define kFblBmInitCmacMagicByte2       0x69u /* 'i' */
#   define kFblBmInitCmacMagicByte3       0x74u /* 't' */
#   define kFblBmInitCmacMagicByte4       0x43u /* 'C' */
#   define kFblBmInitCmacMagicByte5       0x6Du /* 'm' */
#   define kFblBmInitCmacMagicByte6       0x61u /* 'a' */
#   define kFblBmInitCmacMagicByte7       0x63u /* 'c' */
#   define FblBmSetInitCmacMagicFlag()    FblBmSetMagicFlag(InitCmac)
#   define FblBmChkInitCmacMagicFlag()    FblBmChkMagicFlag(InitCmac)
#  endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY || FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */

#  if defined( FBLBM_MAIN_ENABLE_HARDWARE_SWAP )
/* Define pattern for magic flags used if Bootloader should perform a secure boot update */
#   define kFblBmSBUpdateMagicByte0       0x53u /* 'S' */
#   define kFblBmSBUpdateMagicByte1       0x42u /* 'B' */
#   define kFblBmSBUpdateMagicByte2       0x55u /* 'U' */
#   define kFblBmSBUpdateMagicByte3       0x70u /* 'p' */
#   define kFblBmSBUpdateMagicByte4       0x64u /* 'd' */
#   define kFblBmSBUpdateMagicByte5       0x61u /* 'a' */
#   define kFblBmSBUpdateMagicByte6       0x74u /* 't' */
#   define kFblBmSBUpdateMagicByte7       0x65u /* 'e' */
#   define FblBmSetSBUpdateMagicFlag()    FblBmSetMagicFlag(SBUpdate)
#   define FblBmChkSBUpdateMagicFlag()    FblBmChkMagicFlag(SBUpdate)
#  endif /* FBLBM_MAIN_ENABLE_HARDWARE_SWAP */
# endif /* FBLBM_ENABLE_SECURE_BOOT */
#endif /* FBLBM_MAIN_ENABLE_MAGICFLAG */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#if defined( FBLBM_MAIN_ENABLE_MAGICFLAG )
# define FBLBM_MAIN_MAGICFLAG_START_SEC_VAR_NOINIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 extern volatile V_MEMRAM1 vuint8                     V_MEMRAM2 fblBmMagicFlag[kFblBmNoOfMagicBytes];
# if defined( FBLBM_MAIN_ENABLE_FBLSTART_CHANNEL )
V_MEMRAM0 extern volatile V_MEMRAM1 vuint8                     V_MEMRAM2 fblBmFblStartChannel;
# endif /* FBLBM_MAIN_ENABLE_FBLSTART_PARAM */
# if defined( FBLBM_MAIN_ENABLE_FBLSTART_PARAM )
V_MEMRAM0 extern volatile V_MEMRAM1 tFblBmFblStartParameter    V_MEMRAM2 fblBmFblStartParameter;
# endif /* FBLBM_MAIN_ENABLE_FBLSTART_PARAM */
# if defined( FBLBM_MAIN_ENABLE_APPLSTART_PARAM )
V_MEMRAM0 extern volatile V_MEMRAM1 tFblBmApplStartParameter   V_MEMRAM2 fblBmApplStartParameter;
# endif /* FBLBM_MAIN_ENABLE_APPLSTART_PARAM */
# define FBLBM_MAIN_MAGICFLAG_STOP_SEC_VAR_NOINIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBLBM_MAIN_ENABLE_MAGICFLAG */

#endif /* BM_SHARED_H */

/***********************************************************************************************************************
 *  END OF FILE: BM_SHARED.H
 **********************************************************************************************************************/

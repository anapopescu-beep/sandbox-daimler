/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Hardware-specific module for:
 *                  NXP MPC57xx / ST SPC57x / NXP Vybrid
 *                  ST SPC58xx
 *                  Spansion Traveo
 *                  Renesas Rh850/P1x-C
 *                  Infineon TC3xx/TC4xx
 *                  Microchip SAML1x/SAMC21/SAMD21/SAME5X/SAMV70/SAMV71/SAMHAx/PIC32CM
 *                  Broadcom BCM8910x
 *                  Cypress Traveo 2
 *                  Toshiba TMPV770
 *                  ST STM32H7XX, STM32L5XX
 *                  TI TDA4/Jacinto7
 *                 Provides the CAN-Interface and timer operations
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
 *  01.00.00   2014-07-18  visach  -                Initial version
 *  01.01.00   2015-04-30  visach  ESCAN00082734    Synchronized file with FlexCAN3 1.09.00
 *  01.02.00   2015-06-12  visawh  ESCAN00083227    Add Spansion Traveo
 *  01.02.01   2015-09-25  visawh  ESCAN00085490    No changes
 *  01.03.00   2016-01-28  vaddod  ESCAN00085772    Added support for Renesas Rh850/P1x-C
 *                         visawh  ESCAN00086117    No changes
 *                         visach  ESCAN00086967    No changes
 *                                 ESCAN00087164    Reworked CAN memory handling
 *  01.04.00   2016-02-01  vistns  ESCAN00087576    Replacement of unlock sequence for Traveo pin configuration
 *  01.05.00   2016-03-01  visqpc  ESCAN00088688    Added support for Atmel SAMC21x
 *  01.06.00   2016-03-23  visthm  ESCAN00089063    Added context restore macros for use with FblMain 3.xx
 *                                 ESCAN00088816    No changes
 *  01.07.00   2016-04-15  viskjs  ESCAN00089376    No changes
 *  01.08.00   2016-04-27  visqpc  ESCAN00089758    Added support for SPC58ECx
 *  01.09.00   2016-10-26  visawh  ESCAN00090796    No changes
 *                                 ESCAN00091228    Add Implementation of FblHwRestoreFblContext() for Traveo
 *  01.09.01   2016-11-24  visthm  ESCAN00093004    No changes
 *  01.10.00   2016-12-30  visdkl  ESCAN00093431    No changes
 *  01.11.00   2017-10-19  visach  ESCAN00093985    Synchronize with FlexCAN implementation
 *                                 ESCAN00094027    Support Aurix+
 *                         viskjs  ESCAN00096812    Support ATSAMV70/71
 *  01.11.01   2017-11-15  visach  ESCAN00097217    No changes
 *  01.12.00   2017-12-01  visach  ESCAN00097588    Adaptions to keep evaluation of switch FBL_ENABLE_BUSTYPE_CAN
 *  01.12.01   2018-05-04  visrie  ESCAN00099314    No changes
 *  01.13.00   2018-05-02  vaddod  ESCAN00099284    Added support for BCM8910x
 *             2018-06-14  visshs  ESCAN00099682    No changes
 *                                 ESCAN00099686    Add compiler intrinsics macro abstraction
 *  01.14.00   2018-07-03  visach  ESCAN00099883    No changes
 *  01.15.00   2018-08-10  vistmo  ESCAN00100358    Add Cypress Traveo 2
 *  01.15.01   2018-10-05  visach  ESCAN00100708    SWCP processing for Traveo1 fails
 *  01.15.02   2018-10-17  vistmo  ESCAN00101054    Adapted ApplIntJmpTable for Traveo 2
 *  01.16.00   2019-01-31  vistmo  ESCAN00101956    Add ATSAME5x support
 *                                 ESCAN00101982    Adapting to MISRA 2012
 *  01.17.00   2019-04-01  vistmo  ESCAN00102706    Add ATSAML1x support
 *                                 ESCAN00102853    Add TMPV770 support
 *  01.18.00   2019-06-25  vistmo  ESCAN00103504    No changes
 *  01.19.00   2019-08-22  vistmo  FBL-383          Added support for Tricore Green Hills compiler
 *  01.19.01   2019-10-22  vistmo  ESCAN00103561    No changes
 *  01.20.00   2019-12-13  vistmo  FBL-777          Add STM32H7xx and STM32L5xx support
 *  01.21.00   2020-04-28  vistmo  FBL-1734         No changes
 *  01.22.00   2020-05-29  vistmo  FBL-1869         Add ATSAMHAx support
 *  01.23.00   2020-08-12  visjdn  FBL-1947         Add Jacinto7/TDA4 support
 *  01.23.01   2020-09-01  visjdn  ESCAN00107257    No changes
 *  01.24.00   2020-09-01  visrcn  FBL-2511         Add SAMD21 support
 *  01.25.00   2020-11-05  vistmo  FBL-2336         No changes
 *  01.26.00   2020-11-10  visjdn  FBL-2311         No changes
 *                                 FBL-2665         Compiler error: "Illegal mnemonic specified cpsid if"
 *  01.26.01   2021-03-22  visjdn  ESCAN00108454    Compiler error: Missing definition for FblHwRestoreFblContext
 *  01.27.00   2021-07-22  visrie  FBL-3688         Add support for Arm6 compiler for ARM platforms
 *  01.28.00   2021-09-21  visjdn  FBL-3844         Added support for the LLVMTI compiler for Jacinto7
 *  01.29.00   2022-03-04  vishor  FBL-4692         Added support for Microchip compiler for ATSAMC2x
 *                                 ESCAN00110852    Compiler error: Missing definition for FblInterruptDisable() and
 *                                                   FblInterruptEnable()
 *                                 ESCAN00111409    Compiler error: Unknown symbols "FBL_ISYNC", "FBL_DSYNC",
 *                                                   "FBL_NOP", "FBL_MFCR", "FBL_MTCR"
 *  01.30.00   2022-05-10  vishor  FBL-4246         Add support for Tricore TC4xx
 *  01.31.00   2022-05-17  visjdn  FBL-5159         No changes
 *  01.32.00   2022-05-31  visjdn  FBL-4938         Add support of PIC32CM
 *  01.32.01   2022-08-04  visrie  ESCAN00112517    The bootloader waits infinite for the HW to be finished
 *  01.32.02   2022-08-05  visjdn  ESCAN00112523    Compiler error: Missing semicolon
 *  01.33.00   2022-08-09  visjdn  FBL-4709         Add support for Sitara AM62xxA
 **********************************************************************************************************************/

#ifndef FBL_HW_H
#define FBL_HW_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#if defined( FBL_USE_OWN_MEMCPY )
#else
# include <string.h>
#endif
#include "fbl_sfr.h"    /* Special function register definition */
/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblDrvCan_Mpc5700McanCrx CQComponent : Implementation */
#define FBLDRVCAN_MPC5700MCANCRX_VERSION          0x0133u
#define FBLDRVCAN_MPC5700MCANCRX_RELEASE_VERSION  0x00u

/* RI1.1: Reference implementation version */
#define FBLDRVCAN_REFERENCE_IMPLEMENTATION        0x0101u

/***********************************************************************************************************************
 *  DEFINES
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
 */


/* PRQA S 0883 1 */ /* MD_FblHwMpc57xx_0883 */
/* Check validity of the application vector table */
# define APPLSTART       (*((vuint32 *)&ApplIntJmpTable[0]))    /**< Startup code of application */
# define RESETVECT       _start
# define FblCheckBootVectTableIsValid()      (ApplIntJmpTable[1] == APPLVECT_FROM_BOOT)
# define FblCheckApplVectTableIsValid()      (ApplIntJmpTable[1] == APPLVECT_FROM_APPL)

# if !defined( FBL_STM_MODULE )
/* Use timer 0 as default for TC3xx */
#   define FBL_STM_MODULE 0u
# endif
# if !defined( FBL_TIMER_CALC_BUFFER )
/** Timer calculation buffer time */
#  define FBL_TIMER_CALC_BUFFER 50u
# endif

# if !defined( FBL_TIMER_RELOAD_VALUE )
/** Compatibility define for GENy based bootloaders */
#  define FBL_TIMER_RELOAD_VALUE FBL_COMPARE_REG_VAL
# endif

/***********************************************************************************************************************
 *  REGISTER UNLOCK SPECIFIC DEFINES
 **********************************************************************************************************************/
#  define FBL_POS_WDT_CON0_ENDINIT           0u    /**< Offset of ENDINIT in WDTxCON0 */
#  define FBL_POS_WDT_CON0_LCK               1u    /**< Offset of LCK in WDTxCON0 */
#  define FBL_POS_WDT_CON0_PW                2u    /**< Offset of PW in WDTxCON0 */
#  define FBL_POS_WDT_CON0_REL               16u   /**< Offset of REL in WDTxCON0 */

/** Mask for all bits in 32 bit register */
#  define FBL_MASK_WDT_ALL                   0xFFFFFFFFuL
/** Mask for ENDINIT in WDTxCON0 */
#  define FBL_MASK_WDT_CON0_ENDINIT          (0x1uL << FBL_POS_WDT_CON0_ENDINIT)
/** Mask for LCK in WDTxCON0 */
#  define FBL_MASK_WDT_CON0_LCK              (0x1uL << FBL_POS_WDT_CON0_LCK)
/** Inverted mask for LCK / ENDINIT in WDTxCON0 */
#  define FBL_INV_MASK_WDT_CON0_LCK_ENDINIT  ((FBL_MASK_WDT_CON0_LCK | FBL_MASK_WDT_CON0_ENDINIT) ^ FBL_MASK_WDT_ALL)
/** Mask for PW in WDTxCON0 */
#  define FBL_MASK_WDT_CON0_PW               (0x3FFFuL << FBL_POS_WDT_CON0_PW)
/** Mask for LSB of PW in WDTxCON0 */
#  define FBL_MASK_WDT_CON0_PW_2             (0x1uL << FBL_POS_WDT_CON0_PW)
/** Inverted mask for PW in WDTxCON0 */
#  define FBL_INV_MASK_WDT_CON0_PW           (FBL_MASK_WDT_CON0_PW ^ FBL_MASK_WDT_ALL)
/** Mask for inverting bits [7:2] of PW in WDTxCON0 */
#  define FBL_XOR_MASK_WDT_CON0_PW           (0x003FuL << FBL_POS_WDT_CON0_PW)
/** Mask for REL in WDTxCON0 */
#  define FBL_MASK_WDT_CON0_REL              (0xFFFFuL << FBL_POS_WDT_CON0_REL)
/** Inverted mask for REL in WDTxCON0 */
#  define FBL_INV_MASK_WDT_CON0_REL          (FBL_MASK_WDT_CON0_REL ^ FBL_MASK_WDT_ALL)

#  define FBL_POS_WDT_SR_PAS                 7u    /**< Offset of PAS in WDTxSR */
#  define FBL_POS_WDT_SR_TCS                 8u    /**< Offset of TCS in WDTxCON0 */
#  define FBL_POS_WDT_SR_TIM                 16u   /**< Offset of TIM in WDTxCON0 */

/** Mask for PAS in WDTxSR */
#  define FBL_MASK_WDT_SR_PAS                (0x1uL << FBL_POS_WDT_SR_PAS)
/** Mask for TCS in WDTxSR */
#  define FBL_MASK_WDT_SR_TCS                (0x1uL << FBL_POS_WDT_SR_TCS)
/** Mask for TIM in WDTxSR */
#  define FBL_MASK_WDT_SR_TIM                (0xFFFFuL << FBL_POS_WDT_SR_TIM)

/** Unlocked state of ENDINIT in WDTxCON0 */
#  define FBL_VAL_WDT_CON0_ENDINIT_UNLOCK    (0x0uL << FBL_POS_WDT_CON0_ENDINIT)
/** Locked state of ENDINIT in WDTxCON0 */
#  define FBL_VAL_WDT_CON0_ENDINIT_LOCK      (0x1uL << FBL_POS_WDT_CON0_ENDINIT)
/** Unlocked state of LCK in WDTxCON0 */
#  define FBL_VAL_WDT_CON0_LCK_UNLOCK        (0x0uL << FBL_POS_WDT_CON0_LCK)
/** Locked state of LCK in WDTxCON0 */
#  define FBL_VAL_WDT_CON0_LCK_LOCK          (0x1uL << FBL_POS_WDT_CON0_LCK)

/** Number of watchdog register sets */
#  define FBL_WDT_REGISTER_COUNT             (sizeof(fblWdtRegisters) / sizeof(fblWdtRegisters[0]))


/* Compiler intrinsic abstraction */ /* PRQA S 3453 TAG_CompilerIntrinsicMacros */ /* MD_MSR_19.7 */
#  define FBL_ISYNC()               __isync()
#  define FBL_DSYNC()               __dsync()
#  define FBL_NOP()                 __nop()
#  define FBL_MFCR(regaddr)         __mfcr(regaddr)
#  define FBL_MTCR(regaddr, val)    __mtcr((regaddr), (val))
/* PRQA L:TAG_CompilerIntrinsicMacros */

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

#if defined( FBL_USE_OWN_MEMCPY )
/* PRQA S 3453, 5013 1 */ /* MD_MSR_19.7, MD_FblHwMpc57xx_5013 */
# define MEMCPY(dst, src, len) FblOwnMemcpy( (void *)(dst), (const void  *)(src), (unsigned int)(len))      /* PRQA S 5209 */ /* MD_FblHwMpc57xx_5209 */
#else /* FBL_USE_OWN_MEMCPY */
# define MEMCPY(dst, src, len) memcpy((void *)(dst), (const void *)(src), (size_t)(len))
#endif /* FBL_USE_OWN_MEMCPY */

#  define FblInterruptDisable()            __disable()      /**< Disable global interrupt operation */
#  define FblInterruptEnable()             __enable()       /**< Enable global interrupt operation  */


# define FblHwRestoreFblContext()

/* FblFlashXXXGetXBytes macros could not be implemented as typecast to 32 Bit
   pointer because of possible misalignment of diag buffer.
   diagPtr must always be 8 Bit pointer
*/
/* Diag buffer access macros */
/* PRQA S 3453 TAG_AddressHandlingMacros */ /* MD_MSR_19.7 */
#define FblArrayTo3Bytes(a)              (((a)[0] << 16u) | ((a)[1] << 8u) | (a)[2])
#define FblFlashAddressGet3Bytes(a)      (tFblAddress)FblArrayTo3Bytes(a)
#define FblDownloadLengthGet3Bytes(a)    (tFblLength)FblArrayTo3Bytes(a)
#define FblArrayTo4Bytes(a)              (((a)[0] << 24u) | ((a)[1] << 16u) | ((a)[2] << 8u) | (a)[3])
#define FblFlashAddressGet4Bytes(a)      (tFblAddress)FblArrayTo4Bytes(a)
#define FblDownloadLengthGet4Bytes(a)    (tFblLength)FblArrayTo4Bytes(a)
/* PRQA L:TAG_AddressHandlingMacros */

/* Timer access macros */

/* Function macros for hardware abstraction */
#  define FblTimerReset()                                                                                      \
   {                                                                                                           \
      fblCurrentTimer = FBL_STM_TIM(FBL_STM_MODULE, 0);                                                        \
      fblCurrentCmpValue = FBL_STM_CMP(FBL_STM_MODULE, 0);                                                     \
      /* Check if timer lies within correct range */                                                           \
      /* 1 - No overflow, timer smaller than next compare value */                                             \
      if (    ((fblCurrentTimer > fblCurrentCmpValue) &&                                                       \
               (fblCurrentTimer <= (fblCurrentCmpValue + (FBL_TIMER_RELOAD_VALUE - FBL_TIMER_CALC_BUFFER))))   \
      /* 2 - Overflow expected, timer not yet overflowed */                                                    \
           || ((fblCurrentCmpValue > (0xFFFFFFFFu - (FBL_TIMER_RELOAD_VALUE + FBL_TIMER_CALC_BUFFER))) &&      \
               (fblCurrentTimer > fblCurrentCmpValue))                                                         \
      /* 3 - Overflow expected, timer overflowed but smaller than next compare value */                        \
           || ((fblCurrentCmpValue > (0xFFFFFFFFu - (FBL_TIMER_RELOAD_VALUE + FBL_TIMER_CALC_BUFFER))) &&      \
               (fblCurrentTimer <= (fblCurrentCmpValue + (FBL_TIMER_RELOAD_VALUE - FBL_TIMER_CALC_BUFFER))))   \
           )                                                                                                   \
      {                                                                                                        \
         /* Calculate compare value for next millisecond */                                                    \
         FBL_STM_CMP(FBL_STM_MODULE, 0) += FBL_TIMER_RELOAD_VALUE;                                             \
      }                                                                                                        \
      else                                                                                                     \
      {                                                                                                        \
         /* Timer overflowed - set one millisecond compare value compared to current timer value */            \
         FBL_STM_CMP(FBL_STM_MODULE, 0) = FBL_STM_TIM(FBL_STM_MODULE, 0) + FBL_TIMER_RELOAD_VALUE;             \
      }                                                                                                        \
      FBL_STM_ISCR(FBL_STM_MODULE) |= FBL_STM_ISCR_CMP0IRR; /* CMP0IRR = 1 */                                  \
   }

#  define FblTimerGet()    ((vuint8)((FBL_STM_ICR(FBL_STM_MODULE) & FBL_STM_ICR_CMP0IR) & 0xFFu))
#  define FblTimerStopp()                             \
   {                                                  \
      FBL_STM_CMP(FBL_STM_MODULE, 0) = 0x00000000uL;  \
   }

/*****************************************************************************/
/* Macros for jumps                                                          */
/*****************************************************************************/

/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#define JSR(x)          (((void(*)(void))(x))())   /**< Jump to subroutine */

#define JSR_APPL()      JSR(APPLSTART)             /**< Application start */
#define JSR_RESET()     JSR(RESETVECT)             /**< Reset entry */

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/** Control handling of different protection levels */
typedef enum
{
   FBL_WDT_SYSTEM,   /**< Lock/unlock system/safety level */
   FBL_WDT_CPU       /**< Lock/unlock CPU specific level */
} tFblWdtType;

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


#define FBLHW_RAMCODE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
vuint16 FblGetTimerValue(void);
#define FBLHW_RAMCODE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLHW_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
void FblTimerInit( void );

extern void FblHwRegisterUnlock( tFblWdtType wdtType );
extern void FblHwRegisterLock( tFblWdtType wdtType );
extern void FblHwRegisterModify( tFblWdtType wdtType, vuint16 password, vuint16 reload );
#define FBLHW_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTAYPE_CAN */

#define FBLHW_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* Memory access functions */
extern tFblLength FblReadBlock(tFblAddress address, vuint8 *buffer, tFblLength length);
extern vuint8 FblReadByte(tFblAddress address);
#define FBLHW_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if defined( FBL_USE_OWN_MEMCPY )
#   define MEMCPY_START_SEC_CODE
#   include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* PRQA S 5013 1 */ /* MD_FblHwMpc57xx_5013 */
void* FblOwnMemcpy(void *dest, const void *source, unsigned int count);    /* PRQA S 5209 */ /* MD_FblHwMpc57xx_5209 */
#   define MEMCPY_STOP_SEC_CODE
#   include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif  /* FBL_USE_OWN_MEMCPY */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES (PLATFORM SPECIFIC)
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define FBLHW_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 extern V_MEMRAM1 vuint32 V_MEMRAM2 fblCurrentTimer;
V_MEMRAM0 extern V_MEMRAM1 vuint32 V_MEMRAM2 fblCurrentCmpValue;
#define FBLHW_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

#endif /* FBL_HW_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_HW.H
 **********************************************************************************************************************/

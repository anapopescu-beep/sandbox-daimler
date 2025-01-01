/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         FBL updater callout routines - Platform specific for Tricore Aurix Plus TC3xx
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
 *                 FBL Updater. These functions may influence the behavior of the updater in principle.
 *                 Therefore, great care must be taken to verify the correctness of the implementation.
 *                 The contents of the originally delivered files are only examples resp. implementation proposals.
 *                 With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                 Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                 admissible by law or statute.
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Sebastian Loos                Shs           Vector Informatik GmbH
 *  Dan Jiga                      JDn           Vector Informatik GmnH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2018-06-11  Shs     -                Initial release
 *  02.00.00   2020-04-27  JDn     FBL-1016         Support of vBaseEnv and Bootmanager
 **********************************************************************************************************************/

#define UPD_HW_AP_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "upd_hw_ap.h"
#include "upd_ap.h"
#include "fbl_inc.h"
#include "flash_sfr.h"
#include "Csm.h"
#if defined( FBLUPDAPHW_ENABLE_RESET_SAFETY )
# include "BMHD_ToFbl.h"
# include "BMHD_ToUpdater.h"
#include "debug_password.h"
#include "IfxDmu_reg.h"
#endif /* FBLUPDAPHW_ENABLE_RESET_SAFETY */

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLUPD_AP_TC3XX_VERSION != 0x0200u ) || \
    ( FBLUPD_AP_TC3XX_RELEASE_VERSION != 0x00u )
# error "Error in upd_ap_hw.c: Source and Header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
#if defined( FBLBM_ENABLE_STANDALONE_MODE )
#else
# define CRCBMHD_OFFSET           8u /**< Offset of field CRCMHD in BMHD */
# define CRCBMHD_N_OFFSET        12u /**< Offset of field CRCMHD_N in BMHD */
#endif /* FBLBM_ENABLE_STANDALONE_MODE */
#define PROCONRAM_ADDR (0xAF402208U)
#define UCB_DFLASH_ORIG 17u
#define UCB_DFLASH_COPY 25u

#define UCB_DBG_ORIG 18u
#define UCB_DBG_COPY 26u
#define DBG_ORIG_CONFIRMED_REG_VALUE 2u
#define DMU_ADDRESS 0xF8040000u

#define UCB_DBG_ORIG_ADDRESS 0xAF402400
#define UCB_DBG_ORIG_CONFIRMATION_ADDRESS 0xAF402400 + 0x1F0
#define UCB_DBG_ORIG_CONFIRMATION_VALUE   0x57B5327Fu
/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
#if defined( FBLBM_ENABLE_STANDALONE_MODE )
#else
static tFblResult ApplFblUpdHwBmhdErase(tFblWrapperFlash_UcbBlock ucbBlock);
static tFblResult ApplFblUpdHwBmhdWrite(tFblWrapperFlash_UcbBlock ucbBlock, const IO_MemPtrType bmhdValue);
static tFblResult ApplFblUpdHwBmhdSet(tFblWrapperFlash_UcbBlock ucbBlock, const IO_MemPtrType bmhdValue);
static tFblResult ApplFblUpdHwBmhdWriteSeq(tFblWrapperFlash_UcbBlock activeBmhd, const IO_MemPtrType value);
static tFblResult ApplFblUpdHwFindActiveBmhd(tFblWrapperFlash_UcbBlock * ucbBlock, tFblWrapperFlash_UcbConfirmation * conf);
static tFblResult ApplFblUpdHwCompareBmhd(tFblWrapperFlash_UcbBlock ucbBlock, const vuint8 * buffer, vuintx length);
static vuint32 ApplFblUpdHwGetIntegerLittleEndian(vuintx count, tFblMemConstRamData buffer);
#if defined( FLASH_ENABLE_TRICORE_UCB_DISABLE_PROTECTION )
static tFblResult ApplFblUpdHwGetPassword(tFblWrapperFlash_UcbBlock activeBmhd, vuint32 password[FLASH_DISABLE_PROTECTION_PW_LENGHT]);
#endif
static tFblResult ApplFblUpdHwDisableProtection(tFblWrapperFlash_UcbBlock activeBmhd);
#endif /* FBLBM_ENABLE_STANDALONE_MODE */

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
#else
/***********************************************************************************************************************
 *  ApplFblUpdHwBmhdErase
 **********************************************************************************************************************/
/*! \brief       Erase BMHD UCB
 *  \param[in]   ucbBlock Handle describing which UCB block to erase.
 *  \details     Will erase the particular UCB, addressed by ucbBlock.
 *  \return      kFblOk if erase was successful, else kFblFailed.
 **********************************************************************************************************************/
static tFblResult ApplFblUpdHwBmhdErase(tFblWrapperFlash_UcbBlock ucbBlock)
{
   tFblResult result;
   IO_ErrorType memResult;

   /* Erase UCB */
   MemDriver_REraseBegin(kMioDeviceInternalFlash);
   memResult = FlashDriver_UcbEraseSync(ucbBlock);
   MemDriver_REraseEnd(kMioDeviceInternalFlash);

   if (IO_E_OK == memResult)
   {
      result = kFblOk;
   }
   else
   {
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblUpdHwBmhdWrite
 **********************************************************************************************************************/
/*! \brief       Write BMHD ucbBlock with content from <bmhdValue>. Will write "CONFIRMED" after succesfull write.
 *  \param[in]   ucbBlock specifies the ucbBlock to write
 *  \param[in]   bmhdValue
 *  \details     Will  write the particular UCB, addressed by ucbBlock.
 *  \pre         UCB must be in erased state.
 *  \return      kFblOk if successful, else kFblFailed.
 **********************************************************************************************************************/
static tFblResult ApplFblUpdHwBmhdWrite(tFblWrapperFlash_UcbBlock ucbBlock, const IO_MemPtrType bmhdValue)
{
   tFblResult result;
   IO_ErrorType memResult;

   /* Write BMHD value. */
   MemDriver_RWriteBegin(kMioDeviceInternalFlash);
   memResult = FlashDriver_UcbWriteSync(bmhdValue, (IO_SizeType) FLASH_UCB_BLOCK_LENGTH, ucbBlock, 0u);
   MemDriver_RWriteEnd(kMioDeviceInternalFlash);

# if defined( FBLUPDAPHW_ENABLE_CONFIRME_BMHD )
   if (IO_E_OK == memResult)
   {
      /* Transition UNLOCKED -> CONFIRMED */

      MemDriver_RWriteBegin(kMioDeviceInternalFlash);
      memResult = FlashDriver_UcbWriteConfirmed(ucbBlock, FBLFLIO_UCB_CONFIRMATION_CONFIRMED);
      MemDriver_RWriteEnd(kMioDeviceInternalFlash);
   }
# endif /* FBLUPDAPHW_ENABLE_CONFIRME_BMHD */

   if (IO_E_OK == memResult)
   {
      result = kFblOk;
   }
   else
   {
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblUpdHwBmhdSet
 **********************************************************************************************************************/
/*! \brief       Erase, Write BMHD at ucbBlock with content from <bmhdValue>
 *  \param[in]   ucbBlock
 *  \param[in]   bmhdValue
 *  \details     Will  write the particular UCB, addressed by ucbBlock.
 *  \pre         UCB must be in erased state.
 *  \return      kFblOk if successful, else kFblFailed.
 **********************************************************************************************************************/
static tFblResult ApplFblUpdHwBmhdSet(tFblWrapperFlash_UcbBlock ucbBlock, const IO_MemPtrType bmhdValue)
{
   tFblResult result;

# if defined( FBL_ENABLE_ASSERTION )
   vuint8 const ucbUnlockedPattern[FLASH_UCB_CONFIRMATION_WRITE_LENGTH] = {FLASH_UCB_CONFIRMATION_UNLOCKED_VALUE_UINT8, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u};
   vuintx i;

   if (    (bmhdValue[CRCBMHD_OFFSET + 0u] != FblInvert8Bit(bmhdValue[CRCBMHD_N_OFFSET + 0u]))
        || (bmhdValue[CRCBMHD_OFFSET + 1u] != FblInvert8Bit(bmhdValue[CRCBMHD_N_OFFSET + 1u]))
        || (bmhdValue[CRCBMHD_OFFSET + 2u] != FblInvert8Bit(bmhdValue[CRCBMHD_N_OFFSET + 2u]))
        || (bmhdValue[CRCBMHD_OFFSET + 3u] != FblInvert8Bit(bmhdValue[CRCBMHD_N_OFFSET + 3u]))
      )
   {
      /* CRCBMHD must be ~CRCBMHD_N */
      ApplFblFatalError(0u);
   }

   if ((FBLFLIO_UCB00_BMHD0_ORIG != ucbBlock) &&
       (FBLFLIO_UCB01_BMHD1_ORIG != ucbBlock) &&
       (FBLFLIO_UCB02_BMHD2_ORIG != ucbBlock) &&
       (FBLFLIO_UCB03_BMHD3_ORIG != ucbBlock) &&
       (FBLFLIO_UCB08_BMHD0_COPY != ucbBlock) &&
       (FBLFLIO_UCB09_BMHD1_COPY != ucbBlock) &&
       (FBLFLIO_UCB10_BMHD2_COPY != ucbBlock) &&
       (FBLFLIO_UCB11_BMHD3_COPY != ucbBlock)
      )
   {
      /* Wrong UCB selected */
      ApplFblFatalError(0u);
   }

   /* It is expected that the image of the BMHD to write is 'UNLOCKED'. The transition UNLOCKED -> CONFIRMED is done as a separate step */
   for(i = 0u; i < FLASH_UCB_CONFIRMATION_WRITE_LENGTH; i++)
   {
      if (ucbUnlockedPattern[i] != bmhdValue[i + FLASH_UCB_CONFIRMATION_OFFSET])
      {
         ApplFblFatalError(0u);
      }
   }
# endif /* FBL_ENABLE_ASSERTION */

   result = ApplFblUpdHwBmhdErase(ucbBlock);
   if (kFblOk == result)
   {
      result = ApplFblUpdHwBmhdWrite(ucbBlock, bmhdValue);
   }

   return result;
}
/***********************************************************************************************************************
 *  ApplFblUpdHwDFlashSet
 **********************************************************************************************************************/
/*! \brief       Erase, Write BMHD at ucbBlock with content from <bmhdValue>
 *  \param[in]   ucbBlock
 *  \param[in]   bmhdValue
 *  \details     Will  write the particular UCB, addressed by ucbBlock.
 *  \pre         UCB must be in erased state.
 *  \return      kFblOk if successful, else kFblFailed.
 **********************************************************************************************************************/
static tFblResult ApplFblUpdHwDFlashSet(tFblWrapperFlash_UcbBlock ucbBlock, const IO_MemPtrType bmhdValue)
{
   tFblResult result;

# if defined( FBL_ENABLE_ASSERTION )
   vuint8 const ucbUnlockedPattern[FLASH_UCB_CONFIRMATION_WRITE_LENGTH] = {FLASH_UCB_CONFIRMATION_UNLOCKED_VALUE_UINT8, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u};
   vuintx i;

   /* It is expected that the image of the BMHD to write is 'UNLOCKED'. The transition UNLOCKED -> CONFIRMED is done as a separate step */
   for(i = 0u; i < FLASH_UCB_CONFIRMATION_WRITE_LENGTH; i++)
   {
      if (ucbUnlockedPattern[i] != bmhdValue[i + FLASH_UCB_CONFIRMATION_OFFSET])
      {
         ApplFblFatalError(0u);
      }
   }
# endif /* FBL_ENABLE_ASSERTION */

   result = ApplFblUpdHwBmhdErase(ucbBlock);
   if (kFblOk == result)
   {
      result = ApplFblUpdHwBmhdWrite(ucbBlock, bmhdValue);
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblUpdHwDBGSet
 **********************************************************************************************************************/
/*! \brief       Erase, Write DBG at ucbBlock with content from <bmhdValue>
 *  \param[in]   ucbBlock
 *  \param[in]   dbgValue
 *  \details     Will  write the particular UCB, addressed by ucbBlock.
 *  \pre         UCB must be in erased state.
 *  \return      kFblOk if successful, else kFblFailed.
 **********************************************************************************************************************/
static tFblResult ApplFblUpdHwDBGSet(tFblWrapperFlash_UcbBlock ucbBlock, const IO_MemPtrType dbgValue)
{
   tFblResult result;

# if defined( FBL_ENABLE_ASSERTION )
   vuint8 const ucbUnlockedPattern[FLASH_UCB_CONFIRMATION_WRITE_LENGTH] = {FLASH_UCB_CONFIRMATION_UNLOCKED_VALUE_UINT8, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u};
   vuintx i;

   /* It is expected that the image of the BMHD to write is 'UNLOCKED'. The transition UNLOCKED -> CONFIRMED is done as a separate step */
   for(i = 0u; i < FLASH_UCB_CONFIRMATION_WRITE_LENGTH; i++)
   {
      if (ucbUnlockedPattern[i] != dbgValue[i + FLASH_UCB_CONFIRMATION_OFFSET])
      {
         ApplFblFatalError(0u);
      }
   }
# endif /* FBL_ENABLE_ASSERTION */

   result = ApplFblUpdHwBmhdErase(ucbBlock);
   if (kFblOk == result)
   {
      result = ApplFblUpdHwBmhdWrite(ucbBlock, dbgValue);
   }

   MemDriver_RWriteBegin(kMioDeviceInternalFlash);
   FlashDriver_UcbWriteConfirmed(ucbBlock, FBLFLIO_UCB_CONFIRMATION_CONFIRMED);
   MemDriver_RWriteEnd(kMioDeviceInternalFlash);
   

   return result;
}
/***********************************************************************************************************************
 *  ApplFblUpdHwBmhdWriteSeq
 **********************************************************************************************************************/
/*! \brief       Write _ORIG and _COPY in appropriate manner
 *  \details     If _ORIG is valid, write _COPY first, then _ORIG. Otherwise vice versa. By this always at least one of
                 both, _ORIG or _COPY remains in a valid state until the writing of the other block is done.
 *  \param[in]   activeBmhd BMHD wihch was active on startup
 *  \param[in]   value data which need to be written to UCB
 *  \return      kFblOk if writing was sucessful, kFblFailed else.
 **********************************************************************************************************************/
static tFblResult ApplFblUpdHwBmhdWriteSeq(tFblWrapperFlash_UcbBlock activeBmhd, const IO_MemPtrType value)
{
   tFblResult result;

  if (FBLUPDAPHW_BMHD_ORIG == activeBmhd)
   {
      /* Write _COPY */
      result = ApplFblUpdHwBmhdSet(FBLUPDAPHW_BMHD_COPY, value);

      /* Write _ORIG */
      if (kFblOk == result)
      {
         result = ApplFblUpdHwBmhdSet(FBLUPDAPHW_BMHD_ORIG, value);
      }
   }
   else if (FBLUPDAPHW_BMHD_COPY == activeBmhd)
   {
      /* Write _ORIG */
      result = ApplFblUpdHwBmhdSet(FBLUPDAPHW_BMHD_ORIG, value);

      /* Write _COPY */
      if (kFblOk == result)
      {
         result = ApplFblUpdHwBmhdSet(FBLUPDAPHW_BMHD_COPY, value);
      }
   }
   else
   {
      result = kFblFailed;
   }

   return result;
}
/***********************************************************************************************************************
 *  ApplFblUpdHwDFlashWriteSeq
 **********************************************************************************************************************/
/*! \brief       Write _ORIG and _COPY in appropriate manner
 *  \details     If _ORIG is valid, write _COPY first, then _ORIG. Otherwise vice versa. By this always at least one of
                 both, _ORIG or _COPY remains in a valid state until the writing of the other block is done.
 *  \param[in]   value data which need to be written to UCB
 *  \return      kFblOk if writing was sucessful, kFblFailed else.
 **********************************************************************************************************************/
static tFblResult ApplFblUpdHwDFlashWriteSeq(const IO_MemPtrType value)
{
   tFblResult result;

   /* Write _ORIG */
   result = ApplFblUpdHwDFlashSet(UCB_DFLASH_ORIG, value);

   /* Write _COPY */
   if (kFblOk == result)
   {
	  result = ApplFblUpdHwDFlashSet(UCB_DFLASH_COPY, value);
   }

   return result;
}
/***********************************************************************************************************************
 *  ApplFblUpdHwDBGWriteSeq
 **********************************************************************************************************************/
/*! \brief       Write _ORIG and _COPY in appropriate manner
 *  \details     If _ORIG is valid, write _COPY first, then _ORIG. Otherwise vice versa. By this always at least one of
                 both, _ORIG or _COPY remains in a valid state until the writing of the other block is done.
 *  \param[in]   value data which need to be written to UCB
 *  \return      kFblOk if writing was sucessful, kFblFailed else.
 **********************************************************************************************************************/
static tFblResult ApplFblUpdHwDBGWriteSeq(const IO_MemPtrType value)
{
   tFblResult result;

   /* Write _ORIG */
   result = ApplFblUpdHwDBGSet(UCB_DBG_ORIG, value);

   /* Write _COPY */
   if (kFblOk == result)
   {
	  result = ApplFblUpdHwDBGSet(UCB_DBG_COPY, value);
   }

   return result;
}
/***********************************************************************************************************************
 *  ApplFblUpdHwFindActiveBmhd
 **********************************************************************************************************************/
/*! \brief       Evaluate SFR HF_CONFIRM0 to determine which BMHD is the active one
 *  \details     The active BMHD is the one which was the first valid one on last reset. It is the first BMHD which
 *               is considered to be valid by the firmware of the TC3xx and determines therefore
 *               - Startup Address, startup configuration
 *               - Password
 *               - CONFIRMED / UNLOCKED state
 *  \param[out]  ucbBlock Active BMHD
 *  \param[out]  conf     Confirmation state of active BMHD
 *  \return      kFblOk if successful, else kFblFailed.
 **********************************************************************************************************************/
static tFblResult ApplFblUpdHwFindActiveBmhd(tFblWrapperFlash_UcbBlock * ucbBlock, tFblWrapperFlash_UcbConfirmation * conf)
{
   volatile vuint32 hf_confirm0, proinbmhdio, proinbmhdic;
   vuintx i;
   tFblResult result;
   const tFblWrapperFlash_UcbBlock origList[4u] ={FBLFLIO_UCB00_BMHD0_ORIG, FBLFLIO_UCB01_BMHD1_ORIG, FBLFLIO_UCB02_BMHD2_ORIG, FBLFLIO_UCB03_BMHD3_ORIG};
   const tFblWrapperFlash_UcbBlock copyList[4u] ={FBLFLIO_UCB08_BMHD0_COPY, FBLFLIO_UCB09_BMHD1_COPY, FBLFLIO_UCB10_BMHD2_COPY, FBLFLIO_UCB11_BMHD3_COPY};

   result = kFblFailed; /* PRQA S 2982 1 */ /* MD_FblUpd_2982_CompilerWarning */
   hf_confirm0 = FLASH_DMU_HF_CONFIRM0; /* PRQA S 0303 1 */ /* MD_FblUpd_Ap_Tc3xx_0303_SFR */

   /* iterate over all 4 BMHDs */
   for (i = 0u; i < 4u; i++)
   {
      /* Check for BMHDi_ORIG */

      proinbmhdio = hf_confirm0 >> (i * 2u);
      proinbmhdio &= 3u;

      switch(proinbmhdio)
      {
         default:
         case 0u: /* UNREAD */
         case 3u: /* ERRORED */
         {
            result = kFblFailed;
            (* conf) = FBLFLIO_UCB_CONFIRMATION_ERRORED;
            break;
         }
         case 1u: /* UNLOCKED */
         {
            result = kFblOk;
            (* conf) = FBLFLIO_UCB_CONFIRMATION_UNLOCKED;
            (*ucbBlock) = origList[i];
            break;
         }
         case 2u: /* CONFIRMED */
         {
            result = kFblOk;
            (* conf) = FBLFLIO_UCB_CONFIRMATION_CONFIRMED;
            (*ucbBlock) = origList[i];
            break;
         }
      }

      if (kFblOk != result)
      {
         /* Check for BMHDi_COPY */
         proinbmhdic = hf_confirm0 >> ((i * 2u) + 16u);
         proinbmhdic &= 3u;

         switch(proinbmhdic)
         {
            default:
            case 0u: /* UNREAD */
            case 3u: /* ERRORED */
            {
               result = kFblFailed;
               (* conf) = FBLFLIO_UCB_CONFIRMATION_ERRORED;
               break;
            }
            case 1u: /* UNLOCKED */
            {
               result = kFblOk;
               (* conf) = FBLFLIO_UCB_CONFIRMATION_UNLOCKED;
               (*ucbBlock) = copyList[i];
               break;
            }
            case 2u: /* CONFIRMED */
            {
               result = kFblOk;
               (* conf) = FBLFLIO_UCB_CONFIRMATION_CONFIRMED;
               (*ucbBlock) = copyList[i];
               break;
            }
         }
      }

      if (kFblOk == result)
      {
         /* First valid BMHD found */
         break;
      }
   } /* End for */

   return result;
}

/***********************************************************************************************************************
 *  ApplFblUpdHwCompareBmhd
 **********************************************************************************************************************/
/*! \brief       Compares the content of a BMHD with a buffer
 *  \param[in]   ucbBlock Handle to BMHD which shall be compared
 *  \param[in]   buffer   Buffer containing data for comparison
 *  \param[in]   length   length of buffer / comparison
 *  \return      kFblOk if buffer matches the content of ucbBlock
 **********************************************************************************************************************/
static tFblResult ApplFblUpdHwCompareBmhd(tFblWrapperFlash_UcbBlock ucbBlock, const vuint8 * buffer, vuintx length)
{
   tFblResult result;
   IO_ErrorType memResult;
   vuint8 readBuffer[FLASH_UCB_BLOCK_LENGTH];
   vuintx i;

   memResult = FlashDriver_UcbReadSync((IO_MemPtrType) readBuffer, (IO_SizeType) length, ucbBlock, 0u);

   result = kFblOk;
   if (IO_E_OK == memResult)
   {
      for (i = 0u; i < length; i++)
      {
         if (buffer[i] != readBuffer[i])
         {
            result = kFblFailed;
            break;
         }
      }
   }
   else
   {
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblUpdHwGetIntegerLittleEndian
 **********************************************************************************************************************/
/*! \brief      Convert given byte array to little-endian integer value
 *  \param[in]  count Number of relevant bytes
 *  \param[in]  buffer Pointer to input buffer
 *  \return     Integer value
 **********************************************************************************************************************/
static vuint32 ApplFblUpdHwGetIntegerLittleEndian( vuintx count, tFblMemConstRamData buffer )
{
   vuint32 output;
   vuintx idx;

   output = 0u;
   idx    = count;

   /* Loop relevant bytes */
   while (idx > 0u)
   {
      idx--;
      /* Least significant byte first */
      output <<= 8u;
      /* Add current byte */
      output |= (vuint32)buffer[idx];
   }

   return output;
}

# if defined( FLASH_ENABLE_TRICORE_UCB_DISABLE_PROTECTION )
/***********************************************************************************************************************
 *  ApplFblUpdHwGetPassword
 **********************************************************************************************************************/
/*! \brief       Returns the password for the Disable Protection sequence
 *  \param[in]   activeBmhd Handle to BMHD which was active on startup
 *  \param[out]  pasword
 *  \return      kFblOk if password could be found
 **********************************************************************************************************************/
static tFblResult ApplFblUpdHwGetPassword(tFblWrapperFlash_UcbBlock activeBmhd, vuint32 password[FLASH_DISABLE_PROTECTION_PW_LENGHT])
{
   vuintx i;

   /*
    * CUSTOMER TODO: Implement appropriate password selection here
    */

   if (kFblOk == ApplFblUpdHwCompareBmhd(activeBmhd, FBLUPDAPHW_BMHD_TO_UPDATER, 0x10u))
   {
      /* Active BMHD is already "TO UPDATER"
       * Use Password from configured BMHD content
       */

      for(i = 0u; i < FLASH_DISABLE_PROTECTION_PW_LENGHT; i++)
      {
         password[i] = ApplFblUpdHwGetIntegerLittleEndian( sizeof(vuint32), &FBLUPDAPHW_BMHD_TO_UPDATER[FLASH_UCB_BLOCK_PW_OFFSET(i)]);
      }

   }
   else if (kFblOk == ApplFblUpdHwCompareBmhd(activeBmhd, FBLUPDAPHW_BMHD_TO_FBL, 0x10u))
   {
      /* Active BMHD is "TO FBL"
       * Use Password from configured BMHD content
       */

      for(i = 0u; i < FLASH_DISABLE_PROTECTION_PW_LENGHT; i++)
      {
         password[i] = ApplFblUpdHwGetIntegerLittleEndian( sizeof(vuint32), &FBLUPDAPHW_BMHD_TO_FBL[FLASH_UCB_BLOCK_PW_OFFSET(i)]);
      }
   }
   else
   {
      /* No password */
      password[0u] = 0u;
      password[1u] = 0u;
      password[2u] = 0u;
      password[3u] = 0u;
      password[4u] = 0u;
      password[5u] = 0u;
      password[6u] = 0u;
      password[7u] = 0u;
   }

   return kFblOk;
}
#endif /* FLASH_ENABLE_TRICORE_UCB_DISABLE_PROTECTION */

# if defined (FBLUPDAPHW_ENABLE_DISABLE_PROTECTION)
/***********************************************************************************************************************
 *  ApplFblUpdHwDisableProtection
 **********************************************************************************************************************/
/*! \brief       Get password and call Flash Driver to execute Disable Protection sequence
 *  \param[in]   activeBmhd BMHD which was active on startup
 *  \return      kFblOk if sequence was sucessfull (= Protection is disabled)
 **********************************************************************************************************************/
static tFblResult ApplFblUpdHwDisableProtection(tFblWrapperFlash_UcbBlock activeBmhd)
{
   vuint32 password[FLASH_DISABLE_PROTECTION_PW_LENGHT];
   tFblResult result;

   /* Select password for Disable Protection */
   (void)ApplFblUpdHwGetPassword(activeBmhd, password);

   /* Disable Protection Sequence required */
   if (IO_E_OK == FlashDriver_UcbDisableProtection(FBLUPDAPHW_BMHD_ORIG, password))
   {
      result = kFblOk;
   }
   else
   {
      result = kFblFailed;
   }

   return result;
}
# endif /* FBLUPDAPHW_ENABLE_DISABLE_PROTECTION */
#endif /* FBLBM_ENABLE_STANDALONE_MODE */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
#else
/***********************************************************************************************************************
 *  ApplFblUpdHwSetBmhdToUpdater
 **********************************************************************************************************************/
/*! \brief       Set the BMHD STAD (Start Address) to the Updater's starting point.
 *  \details     Default Implementation: Erase and Write the chosen BMHD to make it point to the FBL
 **********************************************************************************************************************/
tFblResult ApplFblUpdHwSetBmhdToUpdater(void)
{
   tFblResult result;
# if defined ( FBLUPDAPHW_ENABLE_RESET_SAFETY )
   tFblWrapperFlash_UcbBlock activeBmhd;
   tFblWrapperFlash_UcbConfirmation activeBmhdConf;

#  if defined( FBL_ENABLE_ASSERTION )
   /* Check configuration */
   /* PRQA S 2742, 2880 TAG_FblUpd_ConfigurationCheck_1 */ /* MD_FblUpd_ConfigurationCheck */
   if ((((vuintx)FBLUPDAPHW_BMHD_ORIG) + 8u) != ((vuintx)FBLUPDAPHW_BMHD_COPY))
   {
      ApplFblFatalError(0u);
   }
   /* PRQA L:TAG_FblUpd_ConfigurationCheck_1 */
#  endif /* FBL_ENABLE_ASSERTION */

   /* Find active BMHD */
   result = ApplFblUpdHwFindActiveBmhd(&activeBmhd, &activeBmhdConf);

   if (kFblOk == result)
   {
      if ((FBLUPDAPHW_BMHD_ORIG != activeBmhd) && (FBLUPDAPHW_BMHD_COPY != activeBmhd))
      {
         /* configured BMHD != active BMHD */
         result = kFblFailed;
      }
   }
   if (kFblOk == result)
   {
      if (FBLFLIO_UCB_CONFIRMATION_ERRORED == activeBmhdConf) /* PRQA S 2992, 2996 */ /* MD_FblUpd_Ap_Tc3xx_2992_2996_AlwaysFalse */
      {
         /* Should never happen because device will not start without at least one active BMHD */
         result = kFblFailed;
      }
#  if defined (FBLUPDAPHW_ENABLE_DISABLE_PROTECTION)
      /* Disable Protection if neccessary */
      if (FBLFLIO_UCB_CONFIRMATION_CONFIRMED == activeBmhdConf)
      {
         result = ApplFblUpdHwDisableProtection(activeBmhd);
      }
#  endif /* FBLUPDAPHW_ENABLE_DISABLE_PROTECTION */
   }

   if (kFblOk == result)
   {
      /* Execute write sequence for BMHD */
       result = ApplFblUpdHwBmhdWriteSeq(activeBmhd, (const IO_MemPtrType) FBLUPDAPHW_BMHD_TO_UPDATER); /* PRQA S 0311 */ /* MD_FblUpd_Ap_Tc3xx_0311_ConstCast */
   }

   /* update UCB */
   vuint32* reg = (vuint32*)PROCONRAM_ADDR;
   if(0x00000002 != (*reg))
   {
	   ApplFblUpdHwDFlashWriteSeq((const IO_MemPtrType) FblUpdDFlashField_ToUpdaterBlk0Blk0);
   }

# else /* FBLUPDAPHW_ENABLE_RESET_SAFETY */
   result = kFblOk;
# endif /* FBLUPDAPHW_ENABLE_RESET_SAFETY */
   return result;
}

/***********************************************************************************************************************
 *  ApplFblUpdHwSetBmhdToFbl
 **********************************************************************************************************************/
/*! \brief       Set the BMHD STAD (Start Address) to the Bootloader's starting point.
 *  \details     Default Implementation: Erase and Write the chosen BMHD to make it point to the FBL.
 *               If a reset has happened since the BMHDs were changed, the Protection is engaged again and therefore
 *               a new "Disable Protection" might be necessary. If it is not needed, it does no harm.
 *  \pre         BMHDi_ORIG and BMHDi_COPY are written valid and set to "TO_UPDATER" and CONFIRMED
 **********************************************************************************************************************/
#pragma optimize 0 
tFblResult ApplFblUpdHwSetBmhdToFbl(void)
{
   tFblResult result;
   Ifx_DMU * dbgUCBRegister = DMU_ADDRESS;

# if defined ( FBLUPDAPHW_ENABLE_RESET_SAFETY )

#  if defined( FBLUPDAPHW_ENABLE_DISABLE_PROTECTION )
   result =  ApplFblUpdHwDisableProtection(FBLUPDAPHW_BMHD_ORIG);
   if (kFblOk == result)
#  endif /* FBLUPDAPHW_ENABLE_DISABLE_PROTECTION */
   {
      result =  ApplFblUpdHwBmhdWriteSeq(FBLUPDAPHW_BMHD_ORIG, (const IO_MemPtrType) FBLUPDAPHW_BMHD_TO_FBL); /* PRQA S 0311 */ /* MD_FblUpd_Ap_Tc3xx_0311_ConstCast */
   }
# else /* FBLUPDAPHW_ENABLE_RESET_SAFETY */
   result = kFblOk;
# endif /* FBLUPDAPHW_ENABLE_RESET_SAFETY */

   ApplFblUpdSwapMetadata();

   /*Check for DBG UCB confirmation value*/
   // if(FBLFLIO_UCB_CONFIRMATION_CONFIRMED != FlashDriver_UcbReadConfirmation(UCB_DBG_ORIG))
   if (DBG_ORIG_CONFIRMED_REG_VALUE != dbgUCBRegister->HF_CONFIRM1.B.PROINDBGO)
   {
      ApplFblUpdHwDBGWriteSeq((const IO_MemPtrType) dbg_passBlk0);
   }

   return result;
}
#endif /* FBLBM_ENABLE_STANDALONE_MODE */
#pragma optimize restore

/***********************************************************************************************************************
 *  ApplFblUpdHwInit
 **********************************************************************************************************************/
/*! \brief       Callback function to initialize hardware specifics
 **********************************************************************************************************************/
void ApplFblUpdHwInit( void )
{
   /* TODO:
    * Initialize the hardware, e.g. PLL, communication port pins, watchdog, timer, ...
    */
   /* Initializations are done by BRS */
}

/***********************************************************************************************************************
 *  ApplFblUpdHwReset
 **********************************************************************************************************************/
/*! \brief       This function performs a reset.
 *  \details     The function will wait until the reset is performed. Please note: This function will
 *               never return to the calling code.
 *               This sequence should be kept the same than in ApplFblReset().
 **********************************************************************************************************************/
void ApplFblUpdHwReset( void )
{
   /* Reset is done via BRS */
}

#if defined FBL_APPL_ENABLE_BUSTYPE_CAN
void Appl_LockEndinit(void)
{
}
void Appl_UnlockEndinit(void)
{
}
#endif

#if defined( FBL_MIO_ENABLE_HOOKS )
/***********************************************************************************************************************
 *  ApplFblPreMemDriver
 **********************************************************************************************************************/
/*! \brief         This function is called before accessing a flash driver as configured in the memory device table.
 *  \param[in]     currentDevice Accessed flash driver
 *  \param[in]     currentFunction Accessed API ID of the flash driver
 **********************************************************************************************************************/
void ApplFblPreMemDriver(vuint8 currentDevice, vuint8 currentFunction)
{
   uint8 opMode;
   Std_ReturnType retVal = E_OK;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)currentDevice;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
   (void)currentFunction;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif
   /* Suspend vHSM operations in data flash */
   opMode = CRYPTO_30_VHSM_DATAFLASH_START;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);
   /* Suspend vHSM operations in code flash -> send it to RAM loop */
   opMode = CRYPTO_30_VHSM_CODEFLASH_START;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);

   /* Simulate DET functionality in case of any error */
   assertFblUser(retVal == E_OK, kFblSysAssertDet);
}
#endif /* FBL_MIO_ENABLE_HOOKS */

#if defined( FBL_MIO_ENABLE_HOOKS )
/***********************************************************************************************************************
 *  ApplFblPostMemDriver
 **********************************************************************************************************************/
/*! \brief         This function is called after accessing a flash driver as configured in the memory device table.
 *  \param[in]     currentDevice Accessed flash driver
 *  \param[in]     currentFunction Accessed API ID of the flash driver
 **********************************************************************************************************************/
void ApplFblPostMemDriver(vuint8 currentDevice, vuint8 currentFunction)
{
   uint8 opMode;
   Std_ReturnType retVal = E_OK;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)currentDevice;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
   (void)currentFunction;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

   /* Get vHSM back from RAM loop */
   opMode = CRYPTO_30_VHSM_CODEFLASH_STOP;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);
   /* Give vHSM access to data flash operations */
   opMode = CRYPTO_30_VHSM_DATAFLASH_STOP;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);

   /* Simulate DET functionality in case of any error */
   assertFblUser(retVal == E_OK, kFblSysAssertDet);
}
#endif /* FBL_MIO_ENABLE_HOOKS */

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/
/* module specific MISRA deviations:

   MD_FblUpd_Ap_Tc3xx_0303_SFR:
      Reason:     Casting of integer to pointer type is required due to memory mapped registers.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation defined.
      Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                  specific basis.

   MD_FblUpd_Ap_Tc3xx_0311_ConstCast:
      Reason:     Cast from configurated (const) data to buffer pointer
      Risk:       No risk, Write functions do not alter the buffer content
      Prevention: No prevention necessary

   MD_FblUpd_Ap_Tc3xx_0602_Endinit:
      Reason:     The identifier _endinit is used for a callback function of the startupcode
      Risk:       Risk of overwriting a library function of the same name
      Prevention: Has to be checked by the integrator carefully

   MD_FblUpd_Ap_Tc3xx_2992_2996_AlwaysFalse
      Reason:     This is just a redundant check in case the implementation will be modified, for extra added safety
      Risk:       No identifiable risk
      Prevention: No prevention necessary

   MD_FblUpd_2982_CompilerWarning:
      Reason:     The assignemt is redundant  and could be omited. But some compilers do not detect this and warn for a uninitialized variable.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblUpd_ConfigurationCheck:
      Reason:     Configuration Check. The condition can be false if the configuration is wrong.
      Risk:       No Risk
      Prevention: No Prevention necessary.
*/

/***********************************************************************************************************************
 *  END OF FILE: UPD_HW_AP.C
 **********************************************************************************************************************/

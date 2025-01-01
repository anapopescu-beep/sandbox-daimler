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
 *  06.03.00   2022-04-08  visrie  FBL-4126         Improve usage for application
 *  06.04.00   2022-04-11  vishor  FBL-4822         No changes
 *  06.04.01   2022-04-28  vismix  ESCAN00111741    No changes
 *  06.05.00   2022-05-06  vishor  FBL-5148         No changes
 *  06.06.00   2022-07-13  vismix  FBL-5391         No changes
 *  06.06.01   2022-08-04  visjns  ESCAN00112070    No changes
 *  06.07.00   2022-11-07  vishor  FBL-4932         No changes
 *  06.08.00   2022-11-30  visrie  FBL-6065         No changes
 **********************************************************************************************************************/

#ifndef BM_TYPES_HEADER_H
#define BM_TYPES_HEADER_H

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if !defined( FBLBM_HEADER_ADDRESS )
# error "Set the define FBLBM_HEADER_ADDRESS to the address of the BmHeader."
#endif
#if !defined( FBL_CALL_TYPE )
# define FBL_CALL_TYPE
#endif

#if defined( FBLBM_MAIN_ENABLE_FBLSTART_CHANNEL )
# define FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE_TYPE_ONLY     uint8 channel
# define FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE_TYPE_FIRST    uint8 channel,
# define FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE               channel
#else
# define FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE_TYPE_ONLY     void
# define FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE_TYPE_FIRST    /* Not used */
# define FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE               0u
#endif /* FBLBM_MAIN_ENABLE_FBLSTART_CHANNEL */

/***********************************************************************************************************************
 *  BmHeader access
 **********************************************************************************************************************/


/* Define to access the FBL header structure */
#if defined( V_MEMROM1_FAR )
/* File is included in FBL context */
# define FblBmHeaderTable  ((V_MEMROM1_FAR tFblBmHeader V_MEMROM2_FAR V_MEMROM3 *)(FBLBM_HEADER_ADDRESS))
# define FblBmHeaderLocal  ((V_MEMROM1_FAR tFblBmHeader V_MEMROM2_FAR V_MEMROM3 *)(&FblBmHeader))
#else
/* File is included in Application context */
# define FblBmHeaderTable  ((P2CONST(tFblBmHeader, AUTOMATIC, FBLBM_HEADER_CONST))(FBLBM_HEADER_ADDRESS))
# define FblBmHeaderLocal  ((P2CONST(tFblBmHeader, AUTOMATIC, FBLBM_HEADER_CONST))(&FblBmHeader))
#endif

/* PRQA S 3453 19 */ /* MD_MSR_FctLikeMacro */
#if defined( FBL_ENABLE_FBL_START )
# if defined( FBLBM_MAIN_ENABLE_FBLSTART_CHANNEL )
#  if defined( FBLBM_MAIN_ENABLE_FBLSTART_PARAM )
#   define CallFblStart(channel, pParam, length)   (FblBmHeaderTable->pFblStartFct)((channel), (pParam), (length))
#  else
#   define CallFblStart(channel)                   (FblBmHeaderTable->pFblStartFct)(channel)
#  endif /* FBLBM_MAIN_ENABLE_FBLSTART_PARAM */
# else
#  if defined( FBLBM_MAIN_ENABLE_FBLSTART_PARAM )
#   define CallFblStart(pParam, length)            (FblBmHeaderTable->pFblStartFct)((pParam), (length))
#  else
#   define CallFblStart()                          (FblBmHeaderTable->pFblStartFct)()
#  endif /* FBLBM_MAIN_ENABLE_FBLSTART_PARAM */
# endif /* FBLBM_MAIN_ENABLE_FBLSTART_CHANNEL */
#endif /* FBL_ENABLE_FBL_START */

#if defined( FBL_ENABLE_STAY_IN_BOOT )
# if defined( FBLBM_MAIN_ENABLE_APPLSTART_PARAM )
#  define CallApplStart(pParam, length)   (FblBmHeaderTable->pApplStartFct)((pParam), (length))
# else
#  define CallApplStart()                 (FblBmHeaderTable->pApplStartFct)()
# endif
#endif /* FBL_ENABLE_STAY_IN_BOOT */

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

# if defined( FBLBM_MAIN_ENABLE_FBLSTART_PARAM )
/** Pointer to call FblStart() function */
typedef FBL_CALL_TYPE void (*tFblStrtFct)(FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE_TYPE_FIRST void* pParam, uint8 length);
# else
/** Pointer to call FblStart() function */
typedef FBL_CALL_TYPE void (*tFblStrtFct)(FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE_TYPE_ONLY);
# endif /* FBL_MAIN_ENABLE_FBLSTART_PARAM */

# if defined( FBLBM_MAIN_ENABLE_APPLSTART_PARAM )
/** Pointer to call FblStart() function */
typedef FBL_CALL_TYPE void (*tApplStrtFct)(void* pParam, uint8 length);
# else
/** Pointer to call FblStart() function */
typedef FBL_CALL_TYPE void (*tApplStrtFct)(void);
# endif /* FBL_MAIN_ENABLE_FBLSTART_PARAM */

/** BM header structure */
typedef struct
{
   uint32 magic;                       /**< Magic Word */
   uint16 majorVersion;                /**< Major version of BmHeader format */
   uint16 minorVersion;                /**< Minor version of BmHeader format */
   uint32 fblHeaderAddress;            /**< Pointer to Fbl Header */
   tFblStrtFct pFblStartFct;           /**< Pointer to FblStart-function */
   tApplStrtFct pApplStartFct;         /**< Pointer to ApplStart-function */
   uint32 checksum;                    /**< Checksum on BmHeader */
   uint32 end_magic;                   /**< End of structure in memory */
} tFblBmHeader;

#endif /* BM_TYPES_HEADER_H */

/***********************************************************************************************************************
 *  END OF FILE: BM_TYPES_HEADER.H
 **********************************************************************************************************************/

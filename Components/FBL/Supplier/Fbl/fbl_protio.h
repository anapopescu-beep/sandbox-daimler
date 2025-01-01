/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Protected Driver functions
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
 *  Christian Baeuerle            CB            Vector Informatik GmbH
 *  Dan Jiga                      JDn           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2019-01-29  CB                       Initial release
 *  01.00.01   2019-02-13  CB      ESCAN00102085    Incorrect prefix of GetVersionOfDriver function
 *  01.01.00   2020-07-20  JDn     FBL-2121         No changes
 **********************************************************************************************************************/

#ifndef FBLWRAPPERFLASH_PROTIO_H
#define FBLWRAPPERFLASH_PROTIO_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblWrapperFlash_XProtectedHis CQComponent : Implementation */
#define FBLWRAPPERFLASH_XPROTECTEDHIS_VERSION            0x0101u
#define FBLWRAPPERFLASH_XPROTECTEDHIS_RELEASE_VERSION    0x00u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define IO_DRIVERMODUS  SYNCRON
#define IO_DEVICETYPE   RANDOM

#ifndef V_API_NEAR
# define V_API_NEAR
#endif

#define PROTECTED_DRIVER_VERSION_MAJOR       ((FBLWRAPPERFLASH_XPROTECTEDHIS_VERSION >> 8u) & 0xFFu)
#define PROTECTED_DRIVER_VERSION_MINOR       ((FBLWRAPPERFLASH_XPROTECTEDHIS_VERSION >> 0u) & 0xFFu)
#define PROTECTED_DRIVER_VERSION_PATCH         FBLWRAPPERFLASH_XPROTECTEDHIS_RELEASE_VERSION

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

IO_ErrorType V_API_NEAR ProtectedDriver_InitSync( void * address );
IO_ErrorType V_API_NEAR ProtectedDriver_DeinitSync( void * address );
IO_ErrorType V_API_NEAR ProtectedDriver_RWriteSync( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress );
IO_ErrorType V_API_NEAR ProtectedDriver_REraseSync( IO_SizeType eraseLength, IO_PositionType eraseAddress );
#if defined( FBL_ENABLE_USR_RREAD_SYNC )
#else
IO_ErrorType V_API_NEAR ProtectedDriver_RReadSync( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress);
#endif /* FBL_ENABLE_USR_RREAD_SYNC */
IO_U32 ProtectedDriver_GetVersionOfDriver( void );

#endif /* FBLWRAPPERFLASH_PROTIO_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_PROTIO.H
 **********************************************************************************************************************/

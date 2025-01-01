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
 *  01.00.01   2019-02-13  CB      ESCAN00102085    No changes
 *  01.01.00   2020-07-20  JDn     FBL-2121         Add support for read-only use case
 **********************************************************************************************************************/

#define FBL_PROTIO_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLWRAPPERFLASH_XPROTECTEDHIS_VERSION != 0x0101u ) || \
    ( FBLWRAPPERFLASH_XPROTECTEDHIS_RELEASE_VERSION != 0x00u )
# error "Error in fbl_flio_protected.c: Source and header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if !defined (FblProtectedFlashRead)
# define FblProtectedFlashRead(readBuffer, readLength, readAddress) FlashDriver_RReadSync((readBuffer), (readLength), (readAddress))
#endif

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ProtectedDriver_InitSync
 **********************************************************************************************************************/
/*! \brief       Initializes the flash driver
 *  \details     Actually this function just returns ok to permit successful initialization by MIO.
 *  \pre         None
 *  \param[in]   address Unused parameter to implement HIS interface.
 *  \return      Reports if initialization was successful or not.
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR ProtectedDriver_InitSync( void * address ) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)address;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

   return IO_E_OK;
}

/***********************************************************************************************************************
 *  ProtectedDriver_DeinitSync
 **********************************************************************************************************************/
/*! \brief       Deinitializes the flash driver
 *  \details     Actually this function just returns ok to permit successful de-initialization by MIO.
 *  \pre         None
 *  \param[in]   address Unused parameter to implement HIS interface.
 *  \return      Reports if deinitialization was successful or not.
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR ProtectedDriver_DeinitSync( void * address ) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)address;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

   return IO_E_OK;
}

/***********************************************************************************************************************
 *  ProtectedDriver_RWriteSync
 **********************************************************************************************************************/
/*! \brief       Writes data to flash memory.
 *  \details     Actually this function just returns NOT ok to indicate that a protected flash block
 *               cannot be programmed.
 *  \pre         None
 *  \param[in]   writeBuffer Pointer to input data buffer.
 *  \param[in]   writeLength Data length.
 *  \param[in]   writeAddress Write target address ( in flash memory ).
 *  \return      Reports write success or error code.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
IO_ErrorType V_API_NEAR ProtectedDriver_RWriteSync( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)writeBuffer;  /* PRQA S 3112 2 */ /* MD_MSR_DummyStmt */
   (void)writeLength;
   (void)writeAddress;
#endif

   return IO_E_NOT_OK;
}

/***********************************************************************************************************************
 *  ProtectedDriver_REraseSync
 **********************************************************************************************************************/
/*! \brief       Erases area in flash memory.
 *  \details     Actually this function just returns NOT ok to indicate that a protected flash block
 *               cannot be erased.
 *  \pre         None
 *  \param[in]   eraseLength Length of memory to be erased. The length has to be aligned to the length
 *               of one or more flash sectors. The flash area has to be contiguous - gaps in must not
 *               be included.
 *  \param[in]   eraseAddress Start address of erase area. The start address has to be the start
 *               address of a logical flash sector.
 *  \return      Reports erase success or error code.
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR ProtectedDriver_REraseSync( IO_SizeType eraseLength, IO_PositionType eraseAddress )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)eraseLength;  /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)eraseAddress;
#endif

   return IO_E_NOT_OK;
}

#if defined( FBL_ENABLE_USR_RREAD_SYNC )
#else
/***********************************************************************************************************************
 *  ProtectedDriver_RReadSync
 **********************************************************************************************************************/
/*! \brief       Reads data from flash memory.
 *  \details     This function calls the flash memory reading function.
 *  \pre         None
 *  \param[out]  readBuffer Pointer to read target buffer. The buffer size must be at least readLength Bytes.
 *  \param[in]   readLength Size of data to be read.
 *  \param[in]   readAddress Start address of data to be read.
 *  \return      Reports read success or error code.
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR ProtectedDriver_RReadSync( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)readBuffer;  /* PRQA S 3112 2 */ /* MD_MSR_DummyStmt */
   (void)readLength;
   (void)readAddress;
# endif

   return FblProtectedFlashRead(readBuffer, readLength, readAddress);
}
#endif /* FBL_ENABLE_USR_RREAD_SYNC */

/***********************************************************************************************************************
 *  ProtectedDriver_GetVersionOfDriver
 **********************************************************************************************************************/
/*! \brief       Reports the flash driver version.
 *  \details     This function reads the flash driver version and reports it to the application. Depending on the
 *               initialization state of the driver, the following data is reported:
 *               - Flash driver version which was used to build the Bootloader if no driver has been downloaded yet.
 *               - Actual flash driver version if the flash driver has been downloaded.
 *  \return      BCD coded version of flash driver.
 **********************************************************************************************************************/
IO_U32 ProtectedDriver_GetVersionOfDriver( void )
{
   return (((IO_U32)PROTECTED_DRIVER_VERSION_MAJOR << 16u) | \
           ((IO_U32)PROTECTED_DRIVER_VERSION_MINOR <<  8u) | \
            (IO_U32)PROTECTED_DRIVER_VERSION_PATCH);
}

/***********************************************************************************************************************
 *  END OF FILE: FBL_PROTIO.C
 **********************************************************************************************************************/

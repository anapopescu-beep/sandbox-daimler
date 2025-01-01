/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         EEPROM driver wrapper functions
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *  Achim Strobelt                Ach           Vector Informatik GmbH
 *  Marco Riedl                   Rie           Vector Informatik GmbH
 *  Daniel Moessner               DlM           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2017-05-09  Ach     ESCAN00094745    Removed hardware dependent variants
 *  02.01.00   2018-07-16  Rie     ESCAN00100045    Use generated size for Eeprom size
 *  02.01.01   2018-11-20  DlM     ESCAN00101396    Fixed compiler error due to unresolved funtion FblInver8Bit
 **********************************************************************************************************************/

#define EEPIO_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "EepInc.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( DRVEEP_DUMMY_VERSION != 0x0201u ) || \
    ( DRVEEP_DUMMY_RELEASE_VERSION != 0x01u )
# error "Error in EepIO.c: Source and header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Macro to get an aligned length */
#define EEP_ALIGN_LENGTH(len, alignment)     ((((len) + ((alignment) - 1u)) / (alignment)) * (alignment))

#define EEP_INIT_FLAG               0x55u
#define EEP_INIT_FLAG_SIZE          0x01u

#if !defined( EEP_BUFFER_SIZE )
# if defined( kEepSizeOfEeprom )
/* Align length to 4 bytes */
#  define EEP_BUFFER_SIZE           EEP_ALIGN_LENGTH(kEepSizeOfEeprom + EEP_INIT_FLAG_SIZE, 4u)
# else
#  define EEP_BUFFER_SIZE           0x100u
# endif /* kEepSizeOfEeprom */
#endif /* EEP_BUFFER_SIZE */

#define EEP_BUFFER_SIZE_WRITEABLE   (EEP_BUFFER_SIZE - EEP_INIT_FLAG_SIZE)

# define EEP_BASE_ADDRESS           ((vuint32)eepData)


/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define EEPDUMMY_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
V_MEMRAM0 static V_MEMRAM1 IO_U8 V_MEMRAM2 eepData[EEP_BUFFER_SIZE];
#define EEPDUMMY_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define EEPDUMMY_FULL_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

static IO_ErrorType EepromDriver_CheckRangeContained( IO_SizeType length, IO_PositionType address );

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  EepromDriver_CheckRangeContained
 **********************************************************************************************************************/
/*! \brief       Check whether an address range lies within the EEPROM (i.e. eepData)
 *  \param[in]   length Length of range to be checked
 *  \param[in]   address Start address of range to be checked
 *  \return      Possible return values:
 *               - IO_E_OK if range lies within EEPROM
 *               - IO_E_NOT_OK otherwise
 **********************************************************************************************************************/
static IO_ErrorType EepromDriver_CheckRangeContained( IO_SizeType length, IO_PositionType address )
{
   IO_ErrorType result;

   if (   (address >= EEP_BASE_ADDRESS)                                            /* PRQA S 0306 */ /* MD_EepIO_0306 */
       && ((address - EEP_BASE_ADDRESS) < EEP_BUFFER_SIZE_WRITEABLE)  /* PRQA S 0306 */ /* MD_EepIO_0306 */
       && (length <= EEP_BUFFER_SIZE_WRITEABLE)
       && ((address - EEP_BASE_ADDRESS) <= (EEP_BUFFER_SIZE_WRITEABLE - length)))  /* PRQA S 0306 */ /* MD_EepIO_0306 */
   {
      result = IO_E_OK;
   }
   else
   {
      assertFblUser(0u, kFblSysAssertParameterOutOfRange);
      result = IO_E_NOT_OK;
   }

   return result;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  EepromDriver_InitSync
 **********************************************************************************************************************/
/*! \brief       Initialize the EEPROM algorithm
 *  \param[in]   address Unused parameter for HIS interface compliance
 *  \return      The return code shows the success of the initialization
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR EepromDriver_InitSync( void * address )                    /* PRQA S 3673 */ /* MD_EepIO_3673 */
{
   IO_SizeType i;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)address;                                                                  /* PRQA S 3112 */ /* MD_EepIO_3112 */
#endif

   /* Check if buffer already initialized */
   if (EEP_INIT_FLAG != eepData[EEP_BUFFER_SIZE_WRITEABLE])
   {
      /* Initialize buffer */
      for (i = 0u; i < EEP_BUFFER_SIZE_WRITEABLE; i++)
      {
         eepData[i] = 0xFFu;
      }

      /* Set initialized flag */
      eepData[EEP_BUFFER_SIZE_WRITEABLE] = EEP_INIT_FLAG;
   }

   return IO_E_OK;
}

/***********************************************************************************************************************
 *  EepromDriver_DeinitSync
 **********************************************************************************************************************/
/*! \brief       De-initialize the EEPROM algorithm, is called on ReturnToNormalMode
 *  \param[in]   address Unused parameter for HIS interface compliance
 *  \return      The return code shows the success of the de-initialization
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR EepromDriver_DeinitSync( void * address )                  /* PRQA S 3673 */ /* MD_EepIO_3673 */
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)address;                                                                  /* PRQA S 3112 */ /* MD_EepIO_3112 */
#endif


   return IO_E_OK;
}

/***********************************************************************************************************************
 *  EepromDriver_RWriteSync
 **********************************************************************************************************************/
/*! \brief       Program EEPROM by calling EEPROM driver routine stored in RAM memory.
 *  \pre         EEPROM driver has to be initialized
 *  \param[in]   writeBuffer Write data buffer
 *  \param[in]   writeLength Number of bytes to be written
 *  \param[in]   writeAddress The write address
 *  \return      Status of EEPROM programming
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR EepromDriver_RWriteSync( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress ) /* PRQA S 3673 */ /* MD_EepIO_3673 */
{
   IO_ErrorType result;

   result = EepromDriver_CheckRangeContained(writeLength, writeAddress);

   if (IO_E_OK == result)
   {

      (void)MEMCPY((IO_MemPtrType)writeAddress, writeBuffer, writeLength); /* PRQA S 0306 */ /* MD_EepIO_0306 */
   }

   return result;
}

/***********************************************************************************************************************
 *  EepromDriver_REraseSync
 **********************************************************************************************************************/
/*! \brief       Erase EEPROM memory
 *  \pre         EEPROM driver has to be initialized
 *  \param[in]   eraseLength Number of bytes to be erased
 *  \param[in]   eraseAddress The erase address
 *  \return      Status of EEPROM erase
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR EepromDriver_REraseSync( IO_SizeType eraseLength, IO_PositionType eraseAddress )
{
   IO_ErrorType result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)eraseLength;                                                              /* PRQA S 3112 */ /* MD_EepIO_3112 */
   (void)eraseAddress;                                                             /* PRQA S 3112 */ /* MD_EepIO_3112 */
#endif

   result = EepromDriver_CheckRangeContained(eraseLength, eraseAddress);

   return result;
}

/***********************************************************************************************************************
 *  EepromDriver_RReadSync
 **********************************************************************************************************************/
/*! \brief          Read EEPROM memory
 *  \pre            EEPROM driver has to be initialized
 *  \param[out]     readBuffer Read data buffer
 *  \param[in]      readLength Number of bytes to be read
 *  \param[in]      readAddress The read address
 *  \return         Status of EEPROM read
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR EepromDriver_RReadSync( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress )
{
   IO_ErrorType result;

   result = EepromDriver_CheckRangeContained(readLength, readAddress);

   if (IO_E_OK == result)
   {
      (void)MEMCPY(readBuffer, (IO_MemPtrType)readAddress, readLength); /* PRQA S 0306 */ /* MD_EepIO_0306 */
   }

   return result;
}

/***********************************************************************************************************************
 *  EepromDriver_VerifySync
 **********************************************************************************************************************/
/*! \brief       Verify EEPROM memory
 *  \pre         EEPROM driver has to be initialized
 *  \param[in]   address Unused parameter for HIS interface compliance
 *  \return      Status of EEPROM verification
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR EepromDriver_VerifySync( void * address )                  /* PRQA S 3673 */ /* MD_EepIO_3673 */
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)address;                                                                  /* PRQA S 3112 */ /* MD_EepIO_3112 */
#endif

   return IO_E_OK;
}

#define EEPDUMMY_FULL_STOP_SEC_CODE
#include "MemMap.h"

/* Module specific MISRA deviations:

   MD_EepIO_0306:
     Reason: Address conversion between integer values and pointers is required to allow for hardware independent
             configuration and address range checks.
     Risk: The size of integer required to hold the result of a pointer cast is implementation-defined.
     Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                 specific basis.

   MD_EepIO_3112:
     Reason: Prevent compiler warnings through unused variables. Variables are unused because of interface design, which requires a parameter.
     Risk: No risk.
     Prevention: No prevention defined.

   MD_EepIO_3673:
      Reason: This interface is required by the HIS flash driver standard.
      Risk: No identifiable risk.
      Prevention: No prevention required.

*/

/***********************************************************************************************************************
 *  END OF FILE: EEPIO.C
 **********************************************************************************************************************/

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
 *  02.01.00   2018-07-16  Rie     ESCAN00100045    No changes
 *  02.01.01   2018-11-20  DlM     ESCAN00101396    No changes
 **********************************************************************************************************************/

#ifndef __EEP_IO_H__
#define __EEP_IO_H__

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : DrvEep_Dummy CQComponent : Implementation */
#define DRVEEP_DUMMY_VERSION           0x0201u
#define DRVEEP_DUMMY_RELEASE_VERSION   0x01u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define IO_DRIVERMODUS    SYNCRON
#define IO_DEVICETYPE     RANDOM

#ifndef V_API_NEAR
# define V_API_NEAR
#endif


#define EEPROM_DRIVER_VERSION_MAJOR (EEP_IO_VERSION >> 8u)
#define EEPROM_DRIVER_VERSION_MINOR (EEP_IO_VERSION & 0xFFu)
#define EEPROM_DRIVER_VERSION_PATCH 0x00u

#define EepromDriver_GetVersionOfDriver()  ((IO_U32)(EEPROM_DRIVER_VERSION_MAJOR << 16u) | \
                                            (IO_U32)(EEPROM_DRIVER_VERSION_MINOR << 8u)  | \
                                                     EEPROM_DRIVER_VERSION_PATCH)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define EEPDUMMY_FULL_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */


IO_ErrorType V_API_NEAR EepromDriver_InitSync( void * );
IO_ErrorType V_API_NEAR EepromDriver_DeinitSync( void * );
IO_ErrorType V_API_NEAR EepromDriver_VerifySync( void * );
IO_ErrorType V_API_NEAR EepromDriver_RReadSync( IO_MemPtrType, IO_SizeType, IO_PositionType );
IO_ErrorType V_API_NEAR EepromDriver_RWriteSync( IO_MemPtrType, IO_SizeType, IO_PositionType );
IO_ErrorType V_API_NEAR EepromDriver_REraseSync( IO_SizeType, IO_PositionType );

#define EEPDUMMY_FULL_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* __EEP_IO_H__ */

/***********************************************************************************************************************
 *  END OF FILE: EEPIO.H
 **********************************************************************************************************************/

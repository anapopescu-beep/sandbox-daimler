/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         FlexRay transceiver driver implementation
 *                 This file contains an example implementation for the TJA1080 transceiver
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *
 *  \par Note
 *  \verbatim
 *  Please note, that this file contains a collection of callback functions to be used with the Flash Bootloader.
 *  These functions may influence the behavior of the bootloader in principle.
 *  Therefore, great care must be taken to verify the correctness of the implementation.
 *
 *  The contents of the originally delivered files are only examples resp. implementation proposals.
 *  With regard to the fact that these functions are meant for demonstration purposes only, Vector Informatiks
 *  liability shall be expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *  \endverbatim
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Achim Strobelt                Ach           Vector Informatik GmbH
 *  Marco Riedl                   Rie           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  03.00.00   2015-05-28  Ach     -                Migrated component to ALM
 *  04.00.01   2016-11-22  Rie     -                Updated version number
 **********************************************************************************************************************/

#ifndef FRTRCV_CBK_H
#define FRTRCV_CBK_H

#include "FrTrcv.h"

#if ( FRTRCV_MEM_MAPPING == STD_ON )
# define FRTRCV_START_SEC_CODE
# include "MemMap.h"
#endif

/* wakeup notification */
extern FUNC(void, FRTRCV_CODE) FrTrcv_Cbk_WakeupByTransceiver(FRTRCV_CHANNEL_SYSTEMTYPE_ONLY);

#if ( FRTRCV_MEM_MAPPING == STD_ON )
# define FRTRCV_STOP_SEC_CODE
# include "MemMap.h"
  /* MISRA-C:2004 Rule 19.1 VIOLATION: #include statements in a file should only be preceded
     by other preprocessor directives or comments. */
#endif

#if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u )
/* PRQA S 3453 1 *//* MISRA-C:2004 Rule 19.7 VIOLATION: A function could probably be used instead of this function-like macro. */
# define FrTrcv_Cbk_WakeupByTransceiver(TrcvIdx)   FrTrcv_Cbk_WakeupByTransceiver()
#endif /* #if ( FRTRCV_API_OPTIMIZATION == STD_ON ) && ( MAX_NUM_OF_BTR_BUSSES == 1u ) */

#endif  /* FRTRCV_CBK_H */

/***********************************************************************************************************************
 *  END OF FILE: FRTRCV_CBK.H
 **********************************************************************************************************************/

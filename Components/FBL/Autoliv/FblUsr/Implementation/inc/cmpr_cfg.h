/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Configuration file for compression / decompression
 *
 *  \note         Please note, that this file contains an implementation/configuration example for the Vector
 *                compression module. This code may influence the behavior of the compression in principle. Therefore,
 *                great care must be taken to verify the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. implementation proposals.
 *                With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                admissible by law or statute.
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
 *  01.00.00   2006-03-15  visfhe                   Initial version
 *  01.01.00   2008-10-06  visfhe                   Added new define to avoid multiple inclusion
 *  01.03.00   2010-02-09  visjhg                   No changes
 *  01.04.00   2010-12-09  visjhg  ESCAN00047587    Configurable elemental data types
 *  01.05.00   2012-11-13  visach  ESCAN00062975    Adapted comments to use Doxygen
 *  02.00.00   2019-07-01  visdkl  ESCAN00103551    No changes
 *  02.01.00   2021-01-12  visjdn  FBL-2322         No changes
 *  02.01.01   2022-08-18  visjdn  FBL-5647         No changes
 *                                 ESCAN00111905    Configurable watchdog call frequency
 **********************************************************************************************************************/

#ifndef CMPR_CFG_H
#define CMPR_CFG_H

/** Define watchdog function for compression module */
# define CMPR_WATCHDOG_FCT()              FblLookForWatchdogVoid()

/** Define watchdog call frequency parameter with following formula: (2^x)-1 */
# define CMPR_WATCHDOG_FREQ               0x00uL

/* Configure elemental data types */
# define CMPR_TYPE_UINT8   vuint8
# define CMPR_TYPE_SINT8   vsint8

# define CMPR_TYPE_UINT16  vuint16
# define CMPR_TYPE_SINT16  vsint16

# define CMPR_TYPE_UINT32  vuint32
# define CMPR_TYPE_SINT32  vsint32

#endif  /* CMPR_CFG_H */

/***********************************************************************************************************************
 *  END OF FILE: CMPR_CFG.H
 **********************************************************************************************************************/

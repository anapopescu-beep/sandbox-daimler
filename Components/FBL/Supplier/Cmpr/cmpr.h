/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Routines for compression / decompression
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
 *  01.00.00   2006-03-15  visfhe                   First implementation based on version 0.48 of LZVECTOR
 *                                                  Added support for new decompression with variable output length
 *  01.01.00   2008-10-06  visjhg                   Added return code to DecompressBlockVL
 *                         visfhe                   No changes
 *  01.02.00   2009-07-13  visfhe                   New handling of output buffer size for VL decompression
 *  01.03.00   2010-02-09  visjhg  ESCAN00040756    Renamed package from SysService_Cmpr to SysService_Cmpr1_Vector
 *                                 ESCAN00040758    Improved compression ratio by adding new matches to search buffer
 *                                                  Code refactoring, split window search and output
 *                                 ESCAN00040784    Added maximum output size to CompressBlock
 *  01.04.00   2010-12-09  visjhg  ESCAN00047587    Configurable elemental data types
 *  01.05.00   2012-11-13  visach  ESCAN00062975    Adapted comments to use Doxygen
 *  02.00.00   2019-07-01  visdkl  ESCAN00103551    No changes
 *  02.01.00   2021-01-12  visjdn  FBL-2322         MISRA 2012 analysis and rework
 *  02.01.01   2022-08-18  visjdn  FBL-5647         Added/adapted MemMap sections
 *                                 ESCAN00111905    No changes
 **********************************************************************************************************************/

#ifndef CMPR_H
#define CMPR_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : SysService_Cmpr1_Vector CQComponent : Implementation */
#define SYSSERVICE_CMPR1_VECTOR_VERSION               0x0201u
#define SYSSERVICE_CMPR1_VECTOR_RELEASE_VERSION       0x01u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define kCmprOk      0u
#define kCmprFailed  1u

/* Default elemental data types to Vector definition */
#if defined( CMPR_TYPE_UINT8 )
#else
# define CMPR_TYPE_UINT8   vuint8
#endif
#if defined( CMPR_TYPE_SINT8 )
#else
# define CMPR_TYPE_SINT8   vsint8
#endif
#if defined( CMPR_TYPE_UINT16 )
#else
# define CMPR_TYPE_UINT16  vuint16
#endif
#if defined( CMPR_TYPE_SINT16 )
#else
# define CMPR_TYPE_SINT16  vsint16
#endif
#if defined( CMPR_TYPE_UINT32 )
#else
# define CMPR_TYPE_UINT32  vuint32
#endif
#if defined( CMPR_TYPE_SINT32 )
#else
# define CMPR_TYPE_SINT32  vsint32
#endif

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

typedef CMPR_TYPE_UINT8    cmprUint8;
typedef CMPR_TYPE_SINT8    cmprSint8;

typedef CMPR_TYPE_UINT16   cmprUint16;
typedef CMPR_TYPE_SINT16   cmprSint16;

typedef CMPR_TYPE_UINT32   cmprUint32;
typedef CMPR_TYPE_SINT32   cmprSint32;

typedef struct sCmprParam
{
   cmprUint8 * inputBuffer;
   cmprUint32  inputLength;
   cmprUint8 * outputBuffer;
   cmprUint32  outputLength;
} tCmprParam;

/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/

#define CMPR_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
void InitDecompressionVL(void);
cmprUint8  DecompressBlockVL(tCmprParam * cmprParam);
#define CMPR_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#endif  /* CMPR_H */

/***********************************************************************************************************************
 *  END OF FILE: CMPR.H
 **********************************************************************************************************************/

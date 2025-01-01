
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  MemIf_Types.h
      Project:  Vector Basic Runtime System
       Module:  BRS@Impl_Stubs

  \brief Description:  Stub of static MemIf file, to allow usage of 3rdparty Fee w/o Mem-Stack.
                       This file is taken from Vector MemIf 03.00.00

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

#ifndef _MEMIF_TYPES_H_
#define _MEMIF_TYPES_H_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/*---- Version identification ---------------*/
#define MEMIF_TYPES_MAJOR_VERSION      (3U)
#define MEMIF_TYPES_MINOR_VERSION      (0U)
#define MEMIF_TYPES_PATCH_VERSION      (0U)

#define MEMIF_TYPES_AR_RELEASE_MAJOR_VERSION      (4U)
#define MEMIF_TYPES_AR_RELEASE_MINOR_VERSION      (0U)
#define MEMIF_TYPES_AR_RELEASE_PATCH_VERSION      (3U)

/*---- API Defines ---------------------------------------------------------*/
/* error value for calling MemIf's API with an invalid device index */
#define MEMIF_E_PARAM_DEVICE (0x01u)
/* error value for calling MemIf_GetVersionInfo with NULL_PTR as parameter */
#define MEMIF_E_PARAM_POINTER  (0x02u)

/*---- API Type definitions ------------------------------------------------*/

typedef enum
{
    MEMIF_UNINIT = 0,
    MEMIF_IDLE,
    MEMIF_BUSY,
    MEMIF_BUSY_INTERNAL
} MemIf_StatusType;

typedef enum
{
    MEMIF_JOB_OK = 0,
    MEMIF_JOB_FAILED,
    MEMIF_JOB_PENDING,
    MEMIF_JOB_CANCELED,
    MEMIF_BLOCK_INCONSISTENT,
    MEMIF_BLOCK_INVALID
} MemIf_JobResultType;

typedef enum
{
    MEMIF_MODE_SLOW = 0,
    MEMIF_MODE_FAST
} MemIf_ModeType;

typedef uint8 * MemIf_DataPtr_pu8;

typedef uint32 MemIf_AddressType;
typedef uint32 MemIf_LengthType;

#define MEMIF_JOB_CANCELLED     MEMIF_JOB_CANCELED

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

#endif /*_MEMIF_TYPES_H_*/

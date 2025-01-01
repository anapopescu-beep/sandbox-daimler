
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
  \file  File:  WdgIf_Types.h
      Project:  Vector Basic Runtime System
       Module:  BRS@Impl_Stubs

  \brief Description:  Stub of static WdgIf file, to allow usage of DrvWd w/o Wdg-Stack.
                         This file is taken from Vector WdgIf 04.00.02

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

#ifndef _WDGIF_TYPES_H_
#define _WDGIF_TYPES_H_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/*---- Version identification - --------------------------------------------*/
#define WDGIF_TYPES_MAJOR_VERSION                   (0x04u)
#define WDGIF_TYPES_MINOR_VERSION                   (0x00u)
#define WDGIF_TYPES_PATCH_VERSION                   (0x02u)

#define WDGIF_TYPES_AR_RELEASE_MAJOR_VERSION        (0x04U)
#define WDGIF_TYPES_AR_RELEASE_MINOR_VERSION        (0x00U)
#define WDGIF_TYPES_AR_RELEASE_REVISION_VERSION     (0x03U)

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/*! \brief Type for the abstraction of the watchdog modes. */
typedef enum
{
    WDGIF_OFF_MODE = 0,
    WDGIF_SLOW_MODE,
    WDGIF_FAST_MODE
} WdgIf_ModeType;

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

#endif /*_WDGIF_TYPES_H_*/

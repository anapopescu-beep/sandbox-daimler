
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
  \file  File:  MemIf.h
      Project:  Vector Basic Runtime System
       Module:  BRS@Impl_Stubs

  \brief Description:  Stub of static MemIf file, to allow usage of 3rdparty Fls w/o Mem-Stack.
                         This file is taken from Vector MemIf 03.00.01

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

#ifndef _MEMIF_H_
#define _MEMIF_H_

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "MemIf_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/*---- Version identification ---------------*/
#define IF_ASRIFMEM_VERSION          (0x0300u)
#define IF_ASRIFMEM_RELEASE_VERSION  (0x01u)

#define MEMIF_MODULE_ID         (22U)
#define MEMIF_VENDOR_ID         (30U)

#define MEMIF_AR_RELEASE_MAJOR_VERSION     ( 4u)
#define MEMIF_AR_RELEASE_MINOR_VERSION     ( 0u)
#define MEMIF_AR_RELEASE_REVISION_VERSION  ( 3u)

#define MEMIF_SW_MAJOR_VERSION  (IF_ASRIFMEM_VERSION >> 8)
#define MEMIF_SW_MINOR_VERSION  (IF_ASRIFMEM_VERSION & 0x00FFu)
#define MEMIF_SW_PATCH_VERSION  (IF_ASRIFMEM_RELEASE_VERSION)

/*---- Perform version checking ------------*/
#if    (  (MEMIF_TYPES_MAJOR_VERSION != (3U)) \
       || (MEMIF_TYPES_MINOR_VERSION != (0U)) )
  #error "Version numbers of MemIf.h and MemIf_Types.h are inconsistent!"
#endif

#define MEMIF_BROADCAST_ID (0xFFu) /* MemIf036, the identifier is not specified */

/*---------MEMIF Service Identification-------------------------------------*/
#define MEMIF_SID_SETMODE         (0x01U)
#define MEMIF_SID_READ            (0x02U)
#define MEMIF_SID_WRITE           (0x03U)
#define MEMIF_SID_CANCEL          (0x04U)
#define MEMIF_SID_GET_STATUS      (0x05U)
#define MEMIF_SID_GET_JOB_RESULT  (0x06U)
#define MEMIF_SID_INVALIDATE      (0x07U)
#define MEMIF_SID_VERSION_INFO    (0x08u)
#define MEMIF_SID_ERASE           (0x09u)

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

#endif /*_MEMIF_H_*/

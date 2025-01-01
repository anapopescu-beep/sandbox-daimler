
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  Brs_MemMap.h
      Project:  Vector Basic Runtime System
       Module:  BrsMain

  \brief Description:  Module specific MemMap Header to allow linking of specific parts of BRS code in RAM.
                       This is just a template and has to be adapted platform/compiler specific within every project.

  \attention Please note:
    The demo and example programs only show special aspects of the software. With regard to the fact
    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
 ----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
  ----------------------------  ------------  -------------------------------------------------------------------------
  Benjamin Walter               visbwa        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Description
  --------  ----------  ------  ---------------------------------------------------------------------------------------
  01.00.00  2019-07-01  visbwa  Initial creation for FBL @ vBaseEnv
  01.01.00  2020-08-04  visbwa  Added support for vBaseEnv Testenvironment of vBaseEnv 2.05.00 (no error directive)
**********************************************************************************************************************/

#ifndef BRS_MEMMAP_ERROR
  #define BRS_MEMMAP_ERROR
#endif

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/
#if (BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u)
# if defined (BRS_COMP_TASKING)    

# else
  #error "Unknown compiler specified! Pragmas for mapping into specific sections not yet implemented for your compiler."
# endif
#endif /*BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u*/

#if defined (BRS_ENABLE_FBL_SUPPORT)
//#error "Add your compiler-specific pragma to allocate code in a section that will later be configured in the linker script to run from RAM"
#endif

/*******  CODE sections **********************************************************************************************/
#ifdef BRS_START_SEC_RAM_CODE
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
  #undef BRS_START_SEC_RAM_CODE
  #undef BRS_MEMMAP_ERROR 
#endif

#ifdef BRS_STOP_SEC_RAM_CODE
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
  #undef BRS_STOP_SEC_RAM_CODE 
  #undef BRS_MEMMAP_ERROR
#endif

#if (BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u)
# ifdef BRS_START_SEC_STARTUP_CODE
#  if defined (BRS_COMP_TASKING)
#   if defined (BRS_PLATFORM_ARM)
  #pragma section "brsMainStartup"
#   else
  #pragma section code "brsMainStartup"
#   endif

#  endif

  #undef BRS_START_SEC_STARTUP_CODE
  #undef BRS_MEMMAP_ERROR
# endif

# ifdef BRS_STOP_SEC_STARTUP_CODE
#  if defined (BRS_COMP_TASKING)
#   if defined (BRS_PLATFORM_ARM)
  #pragma section restore
#   else
  #pragma section code restore
#   endif

#  endif

  #undef BRS_STOP_SEC_STARTUP_CODE
  #undef BRS_MEMMAP_ERROR
# endif
#endif /*BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u*/

/*******  CONST sections  ********************************************************************************************/
#ifdef BRS_START_SEC_RAM_CONST
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
  #undef BRS_START_SEC_RAM_CONST
  #undef BRS_MEMMAP_ERROR 
#endif

#ifdef BRS_STOP_SEC_RAM_CONST
# pragma section nearrom restore
# pragma section farrom restore
  #undef BRS_STOP_SEC_RAM_CONST
  #undef BRS_MEMMAP_ERROR
#endif

#if (BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u)
# ifdef BRS_START_SEC_SHARED_CONST
#  if defined (BRS_COMP_TASKING)
#   if defined (BRS_PLATFORM_ARM)
  #pragma section "brsSharedConst"
#   else
  #pragma section farrom "brsSharedConst"
#   endif

#  endif

  #undef BRS_START_SEC_SHARED_CONST
  #undef BRS_MEMMAP_ERROR
# endif

# ifdef BRS_STOP_SEC_SHARED_CONST
#  if defined (BRS_COMP_TASKING)
#   if defined (BRS_PLATFORM_ARM)
  #pragma section restore
#   else
  #pragma section farrom restore
#   endif

#  endif

  #undef BRS_STOP_SEC_SHARED_CONST
  #undef BRS_MEMMAP_ERROR
# endif
#endif /*BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u*/

/*******  VAR sections  **********************************************************************************************/
#if (BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u)
# ifdef BRS_START_SEC_SHARED_VAR
#  if defined (BRS_COMP_TASKING)
#   if defined (BRS_PLATFORM_ARM)
  #pragma section "brsSharedVar"
#   else
  #pragma section farbss "brsSharedVar"
#   endif

#  endif

  #undef BRS_START_SEC_SHARED_VAR
  #undef BRS_MEMMAP_ERROR
# endif

# ifdef BRS_STOP_SEC_SHARED_VAR
#  if defined (BRS_COMP_TASKING)
#   if defined (BRS_PLATFORM_ARM)
  #pragma section restore
#   else
  #pragma section farbss restore
#   endif

#  endif

  #undef BRS_STOP_SEC_SHARED_VAR
  #undef BRS_MEMMAP_ERROR
# endif
#endif /*BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u*/

#if defined (BRS_MEMMAP_ERROR)
  #error "Error in Brs_MemMap.h: MemMap section is not included!"
#endif

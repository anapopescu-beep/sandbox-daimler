/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        MemMap section definition to locate (link) data or code in memory
 *  \details      This file contains compiler specific section definition for every segment that can be mapped
 *                within the Flash Bootloader to a specific location.
 *
 *  \note
 *                Please note, that this file contains a collection of definitions to be used with the Flash Bootloader.
 *                This code may influence the behavior of the Bootloader in principle. Therefore, great care
 *                must be taken to verify the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. implementation proposals.
 *                With regard to the fact that these definitions are meant for demonstration purposes only,
 *                Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the
 *                extent admissible by law or statute.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  THIS IS A GENERATED FILE
 *  Generator version : 01.10.01
 *********************************************************************************************************************/

/* PRQA S 0841 EOF */ /* MD_MSR_Undef */
/* PRQA S 0883 EOF */ /* MD_MemMap_0883 */
/* PRQA S 3116 EOF */ /* MD_MSR_Pragma */

//#define FBL_MEMMAP_ERROR

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_SW_VERSIONS_START_SEC_CONST )
# pragma section nearrom "FblSW_Versions"
# pragma section farrom "FblSW_Versions"
# undef FBL_SW_VERSIONS_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_SW_VERSIONS_STOP_SEC_CONST )
# pragma section nearrom restore
# pragma section farrom restore
# undef FBL_SW_VERSIONS_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_CONST_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_CONST_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_CONST_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_CONST_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ADC_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ADC_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( APPL_FBL_INFO_HEADER_START_SEC_CONST )
# pragma protect
# pragma section nearrom "ApplInfoHeaderSection"
# pragma section farrom "ApplInfoHeaderSection"
# undef APPL_FBL_INFO_HEADER_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( APPL_FBL_INFO_HEADER_STOP_SEC_CONST )
# pragma endprotect
# pragma section nearrom restore
# pragma section farrom restore
# undef APPL_FBL_INFO_HEADER_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BFX_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef BFX_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BFX_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef BFX_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BRS_START_SEC_RAM_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef BRS_START_SEC_RAM_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BRS_STOP_SEC_RAM_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef BRS_STOP_SEC_RAM_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( BRS_START_SEC_RAM_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef BRS_START_SEC_RAM_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( BRS_STOP_SEC_RAM_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef BRS_STOP_SEC_RAM_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANIF_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CANIF_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANIF_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANIF_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANIF_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANIF_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANIF_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANIF_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_FAST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANIF_START_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_FAST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANIF_STOP_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_FAST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANIF_START_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_FAST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANIF_STOP_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_FAST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANIF_START_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_FAST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANIF_STOP_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_FAST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANIF_START_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANIF_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANIF_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANIF_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANNM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANNM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANNM_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANNM_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANNM_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANNM_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANNM_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANNM_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANNM_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANNM_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANNM_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANNM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANNM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANNM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANNM_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANNM_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANNM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANNM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANSM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CANSM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANSM_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANSM_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANSM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANSM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_CONST_FAST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANSM_START_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_CONST_FAST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANSM_STOP_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_CONST_FAST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANSM_START_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_CONST_FAST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANSM_STOP_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_CONST_FAST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANSM_START_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_CONST_FAST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANSM_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANSM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANSM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_START_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANSM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANTP_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CANTP_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANTP_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANTP_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANTP_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANTP_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CANTP_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef CANTP_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTP_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTP_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTP_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_V9251_START_SEC_CODE_QM_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_V9251_START_SEC_CODE_QM_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_V9251_STOP_SEC_CODE_QM_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_V9251_STOP_SEC_CODE_QM_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_V9251_START_SEC_CONFIG_DATA_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_V9251_START_SEC_CONFIG_DATA_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_V9251_STOP_SEC_CONFIG_DATA_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_V9251_STOP_SEC_CONFIG_DATA_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_V9251_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_V9251_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_V9251_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_V9251_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_V9251_START_SEC_VAR_CLEARED_QM_LOCAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_V9251_START_SEC_VAR_CLEARED_QM_LOCAL_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_V9251_STOP_SEC_VAR_CLEARED_QM_LOCAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_V9251_STOP_SEC_VAR_CLEARED_QM_LOCAL_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_V9251_START_SEC_VAR_CLEARED_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_V9251_START_SEC_VAR_CLEARED_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_V9251_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_V9251_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_V9251_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_V9251_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_V9251_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_V9251_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_W9255_START_SEC_CODE_QM_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_START_SEC_CODE_QM_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_W9255_STOP_SEC_CODE_QM_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_STOP_SEC_CODE_QM_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_W9255_START_SEC_CONFIG_DATA_QM_LOCAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_START_SEC_CONFIG_DATA_QM_LOCAL_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_W9255_STOP_SEC_CONFIG_DATA_QM_LOCAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_STOP_SEC_CONFIG_DATA_QM_LOCAL_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_W9255_START_SEC_CONFIG_DATA_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_START_SEC_CONFIG_DATA_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_W9255_STOP_SEC_CONFIG_DATA_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_STOP_SEC_CONFIG_DATA_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_W9255_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_W9255_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_W9255_START_SEC_VAR_CLEARED_QM_LOCAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_START_SEC_VAR_CLEARED_QM_LOCAL_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_W9255_STOP_SEC_VAR_CLEARED_QM_LOCAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_STOP_SEC_VAR_CLEARED_QM_LOCAL_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_W9255_START_SEC_VAR_CLEARED_QM_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_START_SEC_VAR_CLEARED_QM_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_W9255_STOP_SEC_VAR_CLEARED_QM_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_17_W9255_START_SEC_VAR_CLEARED_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_START_SEC_VAR_CLEARED_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_17_W9255_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_17_W9255_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_CODE_ISR )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_CODE_ISR )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_CONST_FAST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_CONST_FAST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_CONST_FAST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_CONST_FAST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CODE_ISR )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CODE_ISR )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_FAST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_FAST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_FAST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_FAST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_CODE_QM_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_CODE_QM_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_CODE_QM_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_CODE_QM_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_CONST_QM_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_CONST_QM_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_CONST_QM_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_CONST_QM_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_CONST_QM_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_CONST_QM_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_CONST_QM_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_CONST_QM_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_CONST_QM_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_CONST_QM_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_CONST_QM_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_CONST_QM_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_CONST_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_CONST_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_CONST_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_CONST_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CAN_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CAN_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CODE_APPL )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CAN_START_SEC_CODE_APPL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CODE_APPL )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CAN_STOP_SEC_CODE_APPL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CAN_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CAN_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CAN_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CAN_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CAN_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CAN_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CAN_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef CAN_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_STATIC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CAN_START_SEC_STATIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_STATIC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CAN_STOP_SEC_STATIC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CAN_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CAN_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef CAN_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef COMM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef COMM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef COMM_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef COMM_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef COMM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef COMM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef COMM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef COMM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_CONST_ASIL_B_GLOBAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_CONST_ASIL_B_GLOBAL_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_CONST_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_CONST_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_CONST_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_CONST_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_CONST_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef CRC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYIF_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYIF_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYIF_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYIF_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYIF_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYIF_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYIF_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYIF_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYIF_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_APPL_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYPTO_30_LIBCV_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_APPL_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYPTO_30_LIBCV_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYPTO_30_LIBCV_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYPTO_30_LIBCV_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYPTO_30_LIBCV_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYPTO_30_LIBCV_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_APPL_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYPTO_30_VHSM_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_APPL_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYPTO_30_VHSM_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYPTO_30_VHSM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYPTO_30_VHSM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_CODE_ISR )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYPTO_30_VHSM_START_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_CODE_ISR )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYPTO_30_VHSM_STOP_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYPTO_30_VHSM_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYPTO_30_VHSM_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYPTO_30_VHSM_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYPTO_30_VHSM_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYPTO_30_VHSM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYPTO_30_VHSM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT )

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
#  pragma ghs section sbss=".svHsmGlobalRamBuffer"
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmGlobalRamBuffer"
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmGlobalRamBuffer" aw 4
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = "vHsmGlobalRamBuffer"
# endif
# undef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT )

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
#  pragma ghs section sbss=default
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all restore
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ""
# endif
# undef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_64BIT )

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
#  pragma ghs section sbss=".svHsmGlobalRamBuffer"
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmGlobalRamBuffer"
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmGlobalRamBuffer" aw 4
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = "vHsmGlobalRamBuffer"
# endif
# undef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_64BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_64BIT )

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
#  pragma ghs section sbss=default
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all restore
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ""
# endif
# undef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_64BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED )

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
#  pragma ghs section sbss=".svHsmGlobalRamBuffer"
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmGlobalRamBuffer"
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmGlobalRamBuffer" aw 4
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = "vHsmGlobalRamBuffer"
# endif
# undef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED )

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
#  pragma ghs section sbss=default
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all restore
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ""
# endif
# undef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT )

  /* Move section to the same memory which is used by the vHsm as IPC memory */
# if defined(__DCC__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section VHSMIPCMEMORY ".bss" ".vHsmIpcMemory" far-absolute
#  if defined( VHSMIPCMEMORY_USESECTION ) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  else
#   pragma use_section VHSMIPCMEMORY Crypto_30_vHsm_Ipc_Memory
#  endif
# endif
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmIpcMemory"
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmIpcMemory"
#  pragma ghs section sbss=".svHsmIpcMemory"
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmIpcMemory"
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmIpcMemory" aw 4
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg(".vHsmIpcMemory") /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg(".vHsmIpcMemory") /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = "vHsmIpcMemory"
# endif
# undef CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT )

  /* Move section to the same memory which is used by the vHsm as IPC memory */
# if defined(__DCC__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section BSS
# endif
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
#  pragma ghs section sbss=default
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all restore
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ""
# endif
# undef CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_RAMCODE )

  /* Move section to RAM on platforms which need this. */
# if defined(__ghs__) && defined (__RH850__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section text=".vHsmRamCode"
# endif
# undef CRYPTO_30_VHSM_START_SEC_RAMCODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_RAMCODE )

  /* Move section to RAM on platforms which need this. */
# if defined(__ghs__) && defined (__RH850__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section text=default
# endif
# undef CRYPTO_30_VHSM_STOP_SEC_RAMCODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CRYPTO_30_VHSM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_APPL_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CSM_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_APPL_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CSM_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CSM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef CSM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CSM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef CSM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef CSM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef CSM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( CSM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( CSM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef DET_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef DET_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef DET_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef DET_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DET_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_START_SEC_CONST_ASIL_B_GLOBAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_START_SEC_CONST_ASIL_B_GLOBAL_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DIO_START_SEC_CONST_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_START_SEC_CONST_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_CONST_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_CONST_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_CONST_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_CONST_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE0_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE0_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE1_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE1_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE2_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE2_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE3_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE3_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE4_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE4_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE5_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_VAR_CLEARED_ASIL_B_CORE5_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DMA_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_CODE )
# pragma section code "RamCodeSectionEth"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef DOIP_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef DOIP_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef DOIP_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef DOIP_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef DOIP_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef DOIP_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef DOIP_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef DOIP_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef DOIP_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef DOIP_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DOIP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DOIP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DOIP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DSADC_START_SEC_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef DSADC_START_SEC_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DSADC_STOP_SEC_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef DSADC_STOP_SEC_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DSADC_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DSADC_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DSADC_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef DSADC_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DSADC_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef DSADC_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EEPDUMMY_FULL_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef EEPDUMMY_FULL_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EEPDUMMY_FULL_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef EEPDUMMY_FULL_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( EEPDUMMY_START_SEC_VAR )
# pragma section nearbss "EepDummySection"
# pragma section farbss "EepDummySection"
# undef EEPDUMMY_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( EEPDUMMY_STOP_SEC_VAR )
# pragma section nearbss restore
# pragma section farbss restore
# undef EEPDUMMY_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_CODE )
# pragma section code "RamCodeSectionEth"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHIF_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHIF_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_CODE_ISR )
# pragma section code "RamCodeSectionEth"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHIF_START_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_CODE_ISR )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHIF_STOP_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHIF_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHIF_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHIF_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHIF_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHIF_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHIF_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHIF_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHIF_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_CODE )
# pragma section code "RamCodeSectionEth"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHSM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHSM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHSM_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHSM_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHSM_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHSM_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHSM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHSM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHSM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHSM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q1010_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q1010_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q1010_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_CODE )
# pragma section code "RamCodeSectionEth"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHTRCV_30_88Q2112_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef ETHTRCV_30_88Q2112_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHTRCV_30_88Q2112_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore

# undef ETHTRCV_30_88Q2112_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHTRCV_30_88Q2112_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore

# undef ETHTRCV_30_88Q2112_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHTRCV_30_88Q2112_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore

# undef ETHTRCV_30_88Q2112_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHTRCV_30_88Q2112_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore

# undef ETHTRCV_30_88Q2112_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_88Q2112_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_88Q2112_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_88Q2112_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_CODE )
# pragma section code "RamCodeSectionEth"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHTRCV_30_ETHMII_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHTRCV_30_ETHMII_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHTRCV_30_ETHMII_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHTRCV_30_ETHMII_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHTRCV_30_ETHMII_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHTRCV_30_ETHMII_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHTRCV_30_ETHMII_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHTRCV_30_ETHMII_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETHTRCV_30_ETHMII_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETHTRCV_30_ETHMII_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETHTRCV_30_ETHMII_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETHTRCV_30_ETHMII_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETHTRCV_30_ETHMII_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_CODE_QM_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_CODE_QM_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_CODE_QM_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_CODE_QM_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_CONST_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_CONST_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_CONST_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_CONST_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_CODE )
# pragma section code "RamCodeSectionEth"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETH_30_TC3XX_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef ETH_30_TC3XX_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_CODE_ISR )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETH_30_TC3XX_START_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_CODE_ISR )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef ETH_30_TC3XX_STOP_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETH_30_TC3XX_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETH_30_TC3XX_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETH_30_TC3XX_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETH_30_TC3XX_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETH_30_TC3XX_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETH_30_TC3XX_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef ETH_30_TC3XX_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef ETH_30_TC3XX_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_DESCRIPTOR_BASE_ADDRESS_TABLE_VAR_NOINIT_UNSPECIFIED )

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  pragma align 64
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=".EthDesc"
   */
# endif

# undef ETH_30_TC3XX_START_SEC_DESCRIPTOR_BASE_ADDRESS_TABLE_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_DESCRIPTOR_BASE_ADDRESS_TABLE_VAR_NOINIT_UNSPECIFIED )

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  pragma align restore
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=default
   */
# endif

# undef ETH_30_TC3XX_STOP_SEC_DESCRIPTOR_BASE_ADDRESS_TABLE_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_RX_BUFFER_VAR_NOINIT_8BIT )

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  pragma align 64
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=".EthBuffers"
   */
# endif

# undef ETH_30_TC3XX_START_SEC_RX_BUFFER_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_RX_BUFFER_VAR_NOINIT_8BIT )

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  pragma align restore
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=default
   */
# endif

# undef ETH_30_TC3XX_STOP_SEC_RX_BUFFER_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_RX_DESCRIPTOR_VAR_NOINIT_UNSPECIFIED )

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  pragma align 64
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=".EthDesc"
   */
# endif

# undef ETH_30_TC3XX_START_SEC_RX_DESCRIPTOR_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_RX_DESCRIPTOR_VAR_NOINIT_UNSPECIFIED )

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  pragma align restore
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=default
   */
# endif

# undef ETH_30_TC3XX_STOP_SEC_RX_DESCRIPTOR_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_TX_BUFFER_VAR_NOINIT_8BIT )

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  pragma align 64
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=".EthBuffers"
   */
# endif

# undef ETH_30_TC3XX_START_SEC_TX_BUFFER_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_TX_BUFFER_VAR_NOINIT_8BIT )

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  pragma align restore
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=default
   */
# endif

# undef ETH_30_TC3XX_STOP_SEC_TX_BUFFER_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_TX_DESCRIPTOR_VAR_NOINIT_UNSPECIFIED )

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  pragma align 64
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=".EthDesc"
   */
# endif

# undef ETH_30_TC3XX_START_SEC_TX_DESCRIPTOR_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_TX_DESCRIPTOR_VAR_NOINIT_UNSPECIFIED )

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  pragma align restore
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=default
   */
# endif

# undef ETH_30_TC3XX_STOP_SEC_TX_DESCRIPTOR_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_VAR_NOINIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_START_SEC_VAR_NOINIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_VAR_NOINIT_BUFFER )
# pragma align 64
# undef ETH_30_TC3XX_START_SEC_VAR_NOINIT_BUFFER
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_BUFFER )
# pragma align restore
# undef ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_BUFFER
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_VAR_NOINIT_DESCRIPTOR )
# pragma align 64
# undef ETH_30_TC3XX_START_SEC_VAR_NOINIT_DESCRIPTOR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_DESCRIPTOR )
# pragma align restore
# undef ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_DESCRIPTOR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ETH_30_TC3XX_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ETH_30_TC3XX_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ETH_30_TC3XX_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLAP_PROGCONDITION_START_SEC_VAR_NOINIT )
# pragma section nearbss "ProgConditionSection"
# pragma section farbss "ProgConditionSection"
# undef FBLAP_PROGCONDITION_START_SEC_VAR_NOINIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLAP_PROGCONDITION_STOP_SEC_VAR_NOINIT )
# pragma section nearbss restore
# pragma section farbss restore
# undef FBLAP_PROGCONDITION_STOP_SEC_VAR_NOINIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLAP_RAMCODE_START_SEC_CODE ) || \
    defined( FBLAP_RAMCODE_START_SEC_CODE_EXPORT )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLAP_RAMCODE_START_SEC_CODE
# undef FBLAP_RAMCODE_START_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLAP_RAMCODE_STOP_SEC_CODE ) || \
    defined( FBLAP_RAMCODE_STOP_SEC_CODE_EXPORT )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLAP_RAMCODE_STOP_SEC_CODE
# undef FBLAP_RAMCODE_STOP_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBMAP_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLBMAP_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBMAP_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLBMAP_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBMAP_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMAP_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBMAP_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMAP_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBMHDR_BMHEADER_START_SEC_CONST )
# pragma protect
# pragma section nearrom "BmHdrHeaderSection"
# pragma section farrom "BmHdrHeaderSection"
# undef FBLBMHDR_BMHEADER_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBMHDR_BMHEADER_STOP_SEC_CONST )
# pragma endprotect
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLBMHDR_BMHEADER_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBMHDR_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMHDR_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBMHDR_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMHDR_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBMHDR_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMHDR_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBMHDR_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBMHDR_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_HEADER_START_SEC_CONST )
# pragma protect
# pragma section nearrom "BmHeaderSection"
# pragma section farrom "BmHeaderSection"
# undef FBLBM_HEADER_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_HEADER_STOP_SEC_CONST )
# pragma endprotect
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLBM_HEADER_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_MAIN_APPLSTART_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_MAIN_APPLSTART_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_MAIN_APPLSTART_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_MAIN_APPLSTART_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_MAIN_FBLSTART_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_MAIN_FBLSTART_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_MAIN_FBLSTART_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_MAIN_FBLSTART_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_MAIN_MAGICFLAG_START_SEC_VAR_NOINIT )
# pragma section nearbss "MagicFlagSection"
# pragma section farbss "MagicFlagSection"
# undef FBLBM_MAIN_MAGICFLAG_START_SEC_VAR_NOINIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_MAIN_MAGICFLAG_STOP_SEC_VAR_NOINIT )
# pragma section nearbss restore
# pragma section farbss restore
# undef FBLBM_MAIN_MAGICFLAG_STOP_SEC_VAR_NOINIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLBM_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLBM_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLBM_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLCW_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLCW_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLCW_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLCW_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLCW_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLCW_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_64BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLCW_START_SEC_CONST_64BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_64BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLCW_STOP_SEC_CONST_64BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLCW_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLCW_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLCW_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLCW_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_64BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_64BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_BOOLEAN )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLDIAG_RAMCODE_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLDIAG_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLDIAG_RAMCODE_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLDIAG_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLDIAG_RAM_START_SEC_VAR_NOINIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDIAG_RAM_START_SEC_VAR_NOINIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLDIAG_RAM_STOP_SEC_VAR_NOINIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDIAG_RAM_STOP_SEC_VAR_NOINIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLDRVLIN_RAMCODE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDRVLIN_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLDRVLIN_RAMCODE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDRVLIN_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLDTLLIN_RAMCODE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDTLLIN_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLDTLLIN_RAMCODE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLDTLLIN_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLFLIO_FLASHCODE_START_SEC_VAR )
# pragma section nearbss "FblFlashDrvSection"
# pragma section farbss "FblFlashDrvSection"
# undef FBLFLIO_FLASHCODE_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLFLIO_FLASHCODE_STOP_SEC_VAR )
# pragma section nearbss restore
# pragma section farbss restore
# undef FBLFLIO_FLASHCODE_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLFLIO_RAMCODE_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLFLIO_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLFLIO_RAMCODE_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLFLIO_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLHEADER_START_SEC_CONST )
# pragma protect
# pragma section nearrom "FblHeaderSection"
# pragma section farrom "FblHeaderSection"
# undef FBLHEADER_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLHEADER_STOP_SEC_CONST )
# pragma endprotect
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLHEADER_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLHW_RAMCODE_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLHW_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLHW_RAMCODE_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLHW_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLLIB_MEM_RAMCODE_START_SEC_CODE ) || \
    defined( FBLLIB_MEM_RAMCODE_START_SEC_CODE_EXPORT )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLLIB_MEM_RAMCODE_START_SEC_CODE
# undef FBLLIB_MEM_RAMCODE_START_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLLIB_MEM_RAMCODE_STOP_SEC_CODE ) || \
    defined( FBLLIB_MEM_RAMCODE_STOP_SEC_CODE_EXPORT )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLLIB_MEM_RAMCODE_STOP_SEC_CODE
# undef FBLLIB_MEM_RAMCODE_STOP_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLLIB_MEM_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLLIB_MEM_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLLIB_MEM_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLLIB_MEM_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLLIB_MEM_START_SEC_VAR ) || \
    defined( FBLLIB_MEM_START_SEC_VAR_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLLIB_MEM_START_SEC_VAR
# undef FBLLIB_MEM_START_SEC_VAR_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLLIB_MEM_STOP_SEC_VAR ) || \
    defined( FBLLIB_MEM_STOP_SEC_VAR_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLLIB_MEM_STOP_SEC_VAR
# undef FBLLIB_MEM_STOP_SEC_VAR_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLMIO_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLMIO_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLMIO_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLMIO_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLMIO_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLMIO_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLMIO_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLMIO_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLPLATFORMMESSAGE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLPLATFORMMESSAGE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLPLATFORMMESSAGE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLPLATFORMMESSAGE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLSB_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLSB_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLSB_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLSB_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLSB_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLSB_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLSB_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLSB_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLUPDATE_START_SEC_CONST ) || \
    defined( FBLUPDATE_START_SEC_CONST_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLUPDATE_START_SEC_CONST
# undef FBLUPDATE_START_SEC_CONST_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLUPDATE_STOP_SEC_CONST ) || \
    defined( FBLUPDATE_STOP_SEC_CONST_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLUPDATE_STOP_SEC_CONST
# undef FBLUPDATE_STOP_SEC_CONST_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLUPDBMHDFIELD_TOFBL_START_SEC_CONST ) || \
    defined( FBLUPDBMHDFIELD_TOFBL_START_SEC_CONST_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLUPDBMHDFIELD_TOFBL_START_SEC_CONST
# undef FBLUPDBMHDFIELD_TOFBL_START_SEC_CONST_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLUPDBMHDFIELD_TOFBL_STOP_SEC_CONST ) || \
    defined( FBLUPDBMHDFIELD_TOFBL_STOP_SEC_CONST_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLUPDBMHDFIELD_TOFBL_STOP_SEC_CONST
# undef FBLUPDBMHDFIELD_TOFBL_STOP_SEC_CONST_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLUPDBMHDFIELD_TOUPDATER_START_SEC_CONST ) || \
    defined( FBLUPDBMHDFIELD_TOUPDATER_START_SEC_CONST_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLUPDBMHDFIELD_TOUPDATER_START_SEC_CONST
# undef FBLUPDBMHDFIELD_TOUPDATER_START_SEC_CONST_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLUPDBMHDFIELD_TOUPDATER_STOP_SEC_CONST ) || \
    defined( FBLUPDBMHDFIELD_TOUPDATER_STOP_SEC_CONST_EXPORT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLUPDBMHDFIELD_TOUPDATER_STOP_SEC_CONST
# undef FBLUPDBMHDFIELD_TOUPDATER_STOP_SEC_CONST_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLWD_INIT_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLWD_INIT_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLWD_INIT_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBLWD_INIT_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBLWD_RAMCODE_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FBLWD_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBLWD_RAMCODE_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FBLWD_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_APPLVECT_START_SEC_CONST )
# pragma section nearrom "APPLVECT"
# pragma section farrom "APPLVECT"
# undef FBL_APPLVECT_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_APPLVECT_STOP_SEC_CONST )
# pragma section nearrom restore
# pragma section farrom restore
# undef FBL_APPLVECT_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_MEM2HIS_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_MEM2HIS_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_MEM2HIS_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_MEM2HIS_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_MEM2HIS_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_MEM2HIS_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_MEM2HIS_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_MEM2HIS_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_MEM2HIS_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_MEM2HIS_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_MEM2HIS_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_MEM2HIS_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_UPD_AP_RAMCODE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_UPD_AP_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_UPD_AP_RAMCODE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_UPD_AP_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_UPD_MAIN_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_UPD_MAIN_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_UPD_MAIN_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_UPD_MAIN_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_UPD_RAMCODE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_UPD_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_UPD_RAMCODE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_UPD_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_UPD_START_SEC_BUFFER_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_UPD_START_SEC_BUFFER_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FBL_UPD_STOP_SEC_BUFFER_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef FBL_UPD_STOP_SEC_BUFFER_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CODE_ASIL_B_ILLEGALNOTIF )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CODE_ASIL_B_ILLEGALNOTIF
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CODE_ASIL_B_ILLEGALNOTIF )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CODE_ASIL_B_ILLEGALNOTIF
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CODE_ASIL_B_JOBENDNOTIF )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CODE_ASIL_B_JOBENDNOTIF
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CODE_ASIL_B_JOBENDNOTIF )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CODE_ASIL_B_JOBENDNOTIF
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CODE_ASIL_B_JOBERRNOTIF )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CODE_ASIL_B_JOBERRNOTIF
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CODE_ASIL_B_JOBERRNOTIF )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CODE_ASIL_B_JOBERRNOTIF
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CONFIG_DATA_ASIL_B_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CONST_ASIL_B_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CONST_ASIL_B_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CONST_ASIL_B_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CONST_ASIL_B_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CONST_ASIL_B_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CONST_ASIL_B_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CONST_ASIL_B_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CONST_ASIL_B_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_CONST_ASIL_B_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_CONST_ASIL_B_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_ERASEERRORNOTI_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_ERASEERRORNOTI_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_ERASEERRORNOTI_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_ERASEERRORNOTI_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_ILLEGALNOTIF_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_ILLEGALNOTIF_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_ILLEGALNOTIF_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_ILLEGALNOTIF_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_JOBENDNOTIF_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_JOBENDNOTIF_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_JOBENDNOTIF_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_JOBENDNOTIF_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_JOBERRNOTIF_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_JOBERRNOTIF_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_JOBERRNOTIF_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_JOBERRNOTIF_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_PROGERRORNOTI_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_PROGERRORNOTI_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_PROGERRORNOTI_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_PROGERRORNOTI_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FEE_START_SEC_VAR_INIT_ASIL_B_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FEE_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef FEE_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLASH_START_SEC_FLASH_DRIVER_HEADER )
# pragma section nearrom "FlashHeader"
# pragma section farrom "FlashHeader"
# pragma protect
# undef FLASH_START_SEC_FLASH_DRIVER_HEADER
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLASH_STOP_SEC_FLASH_DRIVER_HEADER )
# pragma section nearrom restore
# pragma section farrom restore
# undef FLASH_STOP_SEC_FLASH_DRIVER_HEADER
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLSLOADER_START_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_START_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLSLOADER_STOP_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_STOP_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLSLOADER_START_SEC_CODE_QM_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_START_SEC_CODE_QM_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLSLOADER_STOP_SEC_CODE_QM_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_STOP_SEC_CODE_QM_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLSLOADER_START_SEC_CONST_QM_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_START_SEC_CONST_QM_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLSLOADER_STOP_SEC_CONST_QM_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_STOP_SEC_CONST_QM_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLSLOADER_START_SEC_CONST_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_START_SEC_CONST_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLSLOADER_STOP_SEC_CONST_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_STOP_SEC_CONST_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLSLOADER_START_SEC_WRITEERASE_CODE_QM_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_START_SEC_WRITEERASE_CODE_QM_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLSLOADER_STOP_SEC_WRITEERASE_CODE_QM_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FLSLOADER_STOP_SEC_WRITEERASE_CODE_QM_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_17_DMU_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_17_DMU_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_17_DMU_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_17_DMU_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_17_DMU_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_17_DMU_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRIF_START_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_START_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRIF_STOP_SEC_APPL_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_STOP_SEC_APPL_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRIF_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRIF_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRIF_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FRIF_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRIF_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRIF_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRIF_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRIF_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRIF_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRIF_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRIF_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRIF_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRIF_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRIF_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRIF_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRIF_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRIF_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRIF_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRIF_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRIF_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRNM_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRNM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRNM_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FRNM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRNM_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRNM_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRNM_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRNM_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRNM_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRNM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRNM_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRNM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRNM_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRNM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRNM_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRNM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRNM_START_SEC_PBCFG )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRNM_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRNM_STOP_SEC_PBCFG )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRNM_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRNM_START_SEC_VAR_NOINIT_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRNM_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRNM_STOP_SEC_VAR_NOINIT_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRNM_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRNM_START_SEC_VAR_NOINIT_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRNM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRNM_STOP_SEC_VAR_NOINIT_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRNM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRNM_START_SEC_VAR_NOINIT_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRNM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRNM_START_SEC_VAR_PBCFG )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRNM_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRNM_STOP_SEC_VAR_PBCFG )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRNM_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRNM_START_SEC_VAR_ZERO_INIT_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRNM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRNM_STOP_SEC_VAR_ZERO_INIT_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRNM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRSM_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRSM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRSM_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FRSM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRSM_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRSM_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRSM_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRSM_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRSM_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRSM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRSM_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRSM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRSM_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRSM_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRSM_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRSM_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRSM_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRSM_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRSM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRSM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRSM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRSM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_PBCFG )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_PBCFG )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_PBCFG_ROOT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_PBCFG_ROOT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_VAR_NOINIT_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_VAR_NOINIT_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_VAR_NOINIT_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_VAR_NOINIT_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_VAR_NOINIT_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_VAR_NOINIT_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_VAR_NOINIT_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_VAR_PBCFG )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_VAR_PBCFG )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_VAR_ZERO_INIT_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_VAR_ZERO_INIT_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_VAR_ZERO_INIT_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_VAR_ZERO_INIT_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_VAR_ZERO_INIT_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_VAR_ZERO_INIT_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1080_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1080_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1080_START_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1080_STOP_SEC_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1080_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1080_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1080_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1080_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1080_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1080_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1080_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1080_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1080_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1080_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1080_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1080_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1080_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1082_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1082_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1082_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1082_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1082_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1082_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1082_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1082_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1082_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1082_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1082_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1082_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_30_TJA1085_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1085_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_30_TJA1085_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_30_TJA1085_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FRTRCV_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef FRTRCV_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FRTRCV_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FRTRCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FRTRCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FR_APPL_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FR_APPL_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FR_APPL_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef FR_APPL_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FR_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FR_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FR_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FR_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FR_START_SEC_CODE_ISR )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FR_START_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FR_STOP_SEC_CODE_ISR )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef FR_STOP_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FR_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FR_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FR_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FR_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FR_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FR_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FR_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FR_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FR_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FR_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FR_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef FR_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FR_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef FR_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FR_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef FR_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FR_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FR_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FR_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef FR_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FR_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef FR_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FR_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef FR_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FR_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( FR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef FR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CODE_FAST_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CODE_FAST_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CONST_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CONST_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CONST_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CONST_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CONST_ASIL_B_CORE0_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CONST_ASIL_B_CORE0_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CONST_ASIL_B_CORE0_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CONST_ASIL_B_CORE0_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CONST_ASIL_B_CORE1_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CONST_ASIL_B_CORE1_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CONST_ASIL_B_CORE1_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CONST_ASIL_B_CORE1_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CONST_ASIL_B_CORE2_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CONST_ASIL_B_CORE2_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CONST_ASIL_B_CORE2_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CONST_ASIL_B_CORE2_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CONST_ASIL_B_CORE3_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CONST_ASIL_B_CORE3_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CONST_ASIL_B_CORE3_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CONST_ASIL_B_CORE3_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE0_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE0_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_INIT_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_INIT_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_INIT_ASIL_B_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_INIT_ASIL_B_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_INIT_ASIL_B_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_INIT_ASIL_B_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_INIT_ASIL_B_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_INIT_ASIL_B_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_INIT_ASIL_B_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_INIT_ASIL_B_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_INIT_ASIL_B_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_INIT_ASIL_B_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( GPT_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( GPT_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef GPT_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( IPBASE_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef IPBASE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( IPBASE_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef IPBASE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( IPBASE_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef IPBASE_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( IPBASE_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef IPBASE_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( IPBASE_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef IPBASE_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( IPBASE_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef IPBASE_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( IPBASE_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef IPBASE_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( IPBASE_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef IPBASE_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( IPBASE_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef IPBASE_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( IPBASE_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef IPBASE_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( IPBASE_START_SEC_VAR_NOINIT_16BIT )
/* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef IPBASE_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( IPBASE_STOP_SEC_VAR_NOINIT_16BIT )
/* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef IPBASE_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( IPBASE_START_SEC_VAR_NOINIT_32BIT )
/* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef IPBASE_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( IPBASE_STOP_SEC_VAR_NOINIT_32BIT )
/* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef IPBASE_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( IPBASE_START_SEC_VAR_NOINIT_8BIT )
/* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef IPBASE_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( IPBASE_STOP_SEC_VAR_NOINIT_8BIT )
/* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef IPBASE_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( IPBASE_START_SEC_VAR_NOINIT_UNSPECIFIED )
/* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef IPBASE_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( IPBASE_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
/* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef IPBASE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( IRQ_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef IRQ_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( IRQ_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef IRQ_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( IRQ_START_SEC_CODE_QM_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef IRQ_START_SEC_CODE_QM_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( IRQ_STOP_SEC_CODE_QM_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef IRQ_STOP_SEC_CODE_QM_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINIF_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINIF_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINIF_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef LINIF_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINIF_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINIF_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINIF_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef LINIF_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINIF_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINIF_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINIF_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef LINIF_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINIF_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINIF_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINIF_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef LINIF_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINIF_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINIF_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINIF_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef LINIF_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINIF_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LINIF_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINIF_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LINIF_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINIF_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINIF_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINIF_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINIF_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINIF_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINIF_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LINIF_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINIF_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LINIF_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINIF_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINIF_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINSM_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINSM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINSM_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef LINSM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINSM_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINSM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINSM_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef LINSM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINSM_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINSM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINSM_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef LINSM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINSM_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINSM_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINSM_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINSM_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINSM_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINSM_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINSM_START_SEC_VAR_NOINIT_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_START_SEC_VAR_NOINIT_64BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINSM_STOP_SEC_VAR_NOINIT_64BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_STOP_SEC_VAR_NOINIT_64BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINSM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINSM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINSM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINSM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINSM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTP_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINTP_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTP_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef LINTP_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTP_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINTP_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTP_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef LINTP_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTP_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINTP_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTP_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef LINTP_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTP_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINTP_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTP_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef LINTP_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTP_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LINTP_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTP_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef LINTP_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTP_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTP_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTP_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTP_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTP_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTP_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTP_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTP_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTP_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTP_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTP_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTP_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTP_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTP_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTP_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTP_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTP_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTRCV_30_TLE7259_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTRCV_30_TLE7259_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTRCV_30_TLE7259_START_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTRCV_30_TLE7259_STOP_SEC_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTRCV_30_TLE7259_START_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTRCV_30_TLE7259_STOP_SEC_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTRCV_30_TLE7259_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTRCV_30_TLE7259_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTRCV_30_TLE7259_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTRCV_30_TLE7259_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTRCV_30_TLE7259_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTRCV_30_TLE7259_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LINTRCV_30_TLE7259_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LINTRCV_30_TLE7259_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LINTRCV_30_TLE7259_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_CODE_QM_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_CODE_QM_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_CODE_QM_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_CODE_QM_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_CODE_QM_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_CODE_QM_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_CODE_QM_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_CODE_QM_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_CONFIG_DATA_QM_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_CONFIG_DATA_QM_CORE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_CONFIG_DATA_QM_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_CONFIG_DATA_QM_CORE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_CONST_QM_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_CONST_QM_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_CONST_QM_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_CONST_QM_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_CONST_QM_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_CONST_QM_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_CONST_QM_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_CONST_QM_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_CONST_QM_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_CONST_QM_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_CONST_QM_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_CONST_QM_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_CONST_QM_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_CONST_QM_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_CONST_QM_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_CONST_QM_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_CONST_QM_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_CONST_QM_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_CONST_QM_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_CONST_QM_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_CONST_QM_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_CONST_QM_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_CONST_QM_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_CONST_QM_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_CONST_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_CONST_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_CONST_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_CONST_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_CONST_QM_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_CONST_QM_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_CONST_QM_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_CONST_QM_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_17_ASCLIN_START_SEC_VAR_INIT_QM_GLOBAL_U8 )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_START_SEC_VAR_INIT_QM_GLOBAL_U8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_17_ASCLIN_STOP_SEC_VAR_INIT_QM_GLOBAL_U8 )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_17_ASCLIN_STOP_SEC_VAR_INIT_QM_GLOBAL_U8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LIN_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef LIN_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_CODE_APPL )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LIN_START_SEC_CODE_APPL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_CODE_APPL )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef LIN_STOP_SEC_CODE_APPL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_CODE_FAST )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_CODE_FAST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_CODE_ISR )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LIN_START_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_CODE_ISR )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef LIN_STOP_SEC_CODE_ISR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LIN_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef LIN_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LIN_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef LIN_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LIN_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef LIN_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef LIN_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef LIN_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_FAST_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_FAST_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_FAST_CONST_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_FAST_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_FAST_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_FAST_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_FAST_CONST_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_FAST_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_FAST_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_FAST_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_FAST_CONST_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_FAST_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_FAST_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_FAST_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_FAST_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_PBCFG_GLOBALROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_PBCFG_GLOBALROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_PBCFG_GLOBALROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_PBCFG_GLOBALROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_PBCFG_ROOT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_PBCFG_ROOT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_FAST_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_FAST_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_FAST_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_FAST_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_FAST_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_FAST_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_FAST_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_FAST_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_FAST_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOCACHE_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOCACHE_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOCACHE_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( LIN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( LIN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef LIN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCALLIB_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef MCALLIB_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCALLIB_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef MCALLIB_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCALLIB_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
	   /* Pragma must be placed here. */
	   /* Example for Tasking compiler:  
		# pragma align 4
	   */
# undef MCALLIB_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCALLIB_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
	   /* Pragma must be restored here. */
	   /* Example for Tasking compiler:  
		# pragma align restore
	   */
# undef MCALLIB_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCAL_WDGLIB_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCAL_WDGLIB_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCAL_WDGLIB_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef MCAL_WDGLIB_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_17_TIMERIP_START_SEC_CODE_FAST_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_START_SEC_CODE_FAST_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_17_TIMERIP_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef MCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( MEMCPY_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef MEMCPY_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( MEMCPY_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef MEMCPY_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NM_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef NM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NM_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef NM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NM_START_SEC_CONST_16 )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef NM_START_SEC_CONST_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NM_STOP_SEC_CONST_16 )
# pragma section nearrom restore
# pragma section farrom restore
# undef NM_STOP_SEC_CONST_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NM_START_SEC_CONST_8 )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef NM_START_SEC_CONST_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NM_STOP_SEC_CONST_8 )
# pragma section nearrom restore
# pragma section farrom restore
# undef NM_STOP_SEC_CONST_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NM_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef NM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NM_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef NM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NM_START_SEC_VAR_INIT_8 )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef NM_START_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NM_STOP_SEC_VAR_INIT_8 )
# pragma section nearrom restore
# pragma section farrom restore
# undef NM_STOP_SEC_VAR_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NM_START_SEC_VAR_INIT_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef NM_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NM_STOP_SEC_VAR_INIT_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef NM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NM_START_SEC_VAR_NO_INIT_16 )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef NM_START_SEC_VAR_NO_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NM_STOP_SEC_VAR_NO_INIT_16 )
# pragma section nearrom restore
# pragma section farrom restore
# undef NM_STOP_SEC_VAR_NO_INIT_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NM_START_SEC_VAR_NO_INIT_32 )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef NM_START_SEC_VAR_NO_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NM_STOP_SEC_VAR_NO_INIT_32 )
# pragma section nearrom restore
# pragma section farrom restore
# undef NM_STOP_SEC_VAR_NO_INIT_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NM_START_SEC_VAR_NO_INIT_8 )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef NM_START_SEC_VAR_NO_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NM_STOP_SEC_VAR_NO_INIT_8 )
# pragma section nearrom restore
# pragma section farrom restore
# undef NM_STOP_SEC_VAR_NO_INIT_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( NM_START_SEC_VAR_NO_INIT_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef NM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( OCU_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( OCU_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( OCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( OCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( OCU_START_SEC_CONST_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_START_SEC_CONST_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( OCU_STOP_SEC_CONST_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_STOP_SEC_CONST_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( OCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( OCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_BUFFER_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_BUFFER_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_BUFFER_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_BUFFER_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef PDUR_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef PDUR_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef PDUR_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef PDUR_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PORT_START_SEC_CODE_ASIL_B_GLOBAL )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef PORT_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PORT_STOP_SEC_CODE_ASIL_B_GLOBAL )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef PORT_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PORT_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PORT_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PORT_START_SEC_CONST_ASIL_B_GLOBAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_START_SEC_CONST_ASIL_B_GLOBAL_16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PORT_STOP_SEC_CONST_ASIL_B_GLOBAL_16 )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_STOP_SEC_CONST_ASIL_B_GLOBAL_16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PORT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PORT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PORT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PORT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef PORT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_CODE_FAST_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_CODE_FAST_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( PWM_17_GTMCCU6_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( PWM_17_GTMCCU6_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef PWM_17_GTMCCU6_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SECMPAR_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMPAR_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SECMPAR_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMPAR_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SECMPAR_START_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMPAR_START_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SECMPAR_STOP_SEC_CONST )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMPAR_STOP_SEC_CONST
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SECMPAR_START_SEC_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMPAR_START_SEC_DATA
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SECMPAR_STOP_SEC_DATA )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMPAR_STOP_SEC_DATA
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SECMPAR_START_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMPAR_START_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SECMPAR_STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMPAR_STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SECMSK_RAMCODE_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMSK_RAMCODE_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SECMSK_RAMCODE_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SECMSK_RAMCODE_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SENT_START_SEC_CODE_QM_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef SENT_START_SEC_CODE_QM_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SENT_STOP_SEC_CODE_QM_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef SENT_STOP_SEC_CODE_QM_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SENT_START_SEC_VAR_CLEARED_QM_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SENT_START_SEC_VAR_CLEARED_QM_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SENT_STOP_SEC_VAR_CLEARED_QM_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SENT_STOP_SEC_VAR_CLEARED_QM_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SENT_START_SEC_VAR_CLEARED_QM_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef SENT_START_SEC_VAR_CLEARED_QM_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SENT_STOP_SEC_VAR_CLEARED_QM_GLOBAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef SENT_STOP_SEC_VAR_CLEARED_QM_GLOBAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SMU_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef SMU_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SMU_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef SMU_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SMU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SMU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SMU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SMU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SMU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SMU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SMU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SMU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_CODE )
# pragma section code "RamCodeSectionEth"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef SOAD_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef SOAD_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef SOAD_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef SOAD_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef SOAD_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef SOAD_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef SOAD_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef SOAD_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef SOAD_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef SOAD_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_ZERO_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SOAD_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SOAD_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SOAD_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32 )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32 )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32 )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32 )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_256
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_256
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_256
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_256
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_256
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_256
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_256
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_256
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_256
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_256
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_256
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_256 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_256
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( START_SEC_VAR_ZERO_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef START_SEC_VAR_ZERO_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( STOP_SEC_VAR )
   /* #pragma <enter your compiler specific pragma> */
# undef STOP_SEC_VAR
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( TCPIP_START_SEC_CODE )
# pragma section code "RamCodeSectionEth"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef TCPIP_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( TCPIP_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef TCPIP_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( TCPIP_START_SEC_CONST_16BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef TCPIP_START_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( TCPIP_STOP_SEC_CONST_16BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef TCPIP_STOP_SEC_CONST_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( TCPIP_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef TCPIP_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( TCPIP_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef TCPIP_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( TCPIP_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef TCPIP_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( TCPIP_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef TCPIP_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( TCPIP_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef TCPIP_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( TCPIP_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef TCPIP_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( TCPIP_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef TCPIP_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( TCPIP_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef TCPIP_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( TCPIP_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef TCPIP_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( TCPIP_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef TCPIP_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( TCPIP_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef TCPIP_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( TCPIP_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef TCPIP_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( TCPIP_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef TCPIP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( TCPIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef TCPIP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( TCPIP_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef TCPIP_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( TCPIP_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef TCPIP_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( TCPIP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef TCPIP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( TCPIP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef TCPIP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UART_START_SEC_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef UART_START_SEC_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UART_STOP_SEC_CODE_ASIL_B_LOCAL )
   /* #pragma <enter your compiler specific pragma> */
# undef UART_STOP_SEC_CODE_ASIL_B_LOCAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UART_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef UART_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UART_START_SEC_CONST_ASIL_B_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef UART_START_SEC_CONST_ASIL_B_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UART_STOP_SEC_CONST_ASIL_B_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef UART_STOP_SEC_CONST_ASIL_B_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8 )
   /* #pragma <enter your compiler specific pragma> */
# undef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UDPNM_START_SEC_CODE )
# pragma section code "RamCodeSectionEth"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef UDPNM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UDPNM_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef UDPNM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UDPNM_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef UDPNM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UDPNM_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef UDPNM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UDPNM_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef UDPNM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UDPNM_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef UDPNM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UDPNM_START_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_START_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UDPNM_STOP_SEC_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_STOP_SEC_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UDPNM_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UDPNM_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UDPNM_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UDPNM_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UDPNM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UDPNM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UDPNM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UDPNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UDPNM_START_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_START_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UDPNM_STOP_SEC_VAR_PBCFG )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_STOP_SEC_VAR_PBCFG
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UDPNM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UDPNM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( UDPNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( UDPNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef UDPNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_CODE )

# pragma section code "RamCodeSectionEth"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef VMEMACCM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_CODE )

# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore

# undef VMEMACCM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_CONST_UNSPECIFIED )

# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"

# undef VMEMACCM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_CONST_UNSPECIFIED )

# pragma section nearrom restore
# pragma section farrom restore

# undef VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition0"
#   pragma ghs section sdata=".svMemAccMPartition0"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition1"
#   pragma ghs section sdata=".svMemAccMPartition1"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID10 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition10"
#   pragma ghs section sdata=".svMemAccMPartition10"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID10
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID10 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID10
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID11 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition11"
#   pragma ghs section sdata=".svMemAccMPartition11"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID11
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID11 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID11
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID12 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition12"
#   pragma ghs section sdata=".svMemAccMPartition12"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID12
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID12 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID12
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID13 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition13"
#   pragma ghs section sdata=".svMemAccMPartition13"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID13
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID13 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID13
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID14 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition14"
#   pragma ghs section sdata=".svMemAccMPartition14"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID14
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID14 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID14
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID15 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition15"
#   pragma ghs section sdata=".svMemAccMPartition15"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID15
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID15 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID15
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID16 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition16"
#   pragma ghs section sdata=".svMemAccMPartition16"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID16
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID16 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID16
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID2 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition2"
#   pragma ghs section sdata=".svMemAccMPartition2"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID2
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID2 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID2
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID3 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition3"
#   pragma ghs section sdata=".svMemAccMPartition3"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID3
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID3 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID3
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID4 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition4"
#   pragma ghs section sdata=".svMemAccMPartition4"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID4
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID4 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID4
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID5 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition5"
#   pragma ghs section sdata=".svMemAccMPartition5"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID5
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID5 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID5
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID6 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition6"
#   pragma ghs section sdata=".svMemAccMPartition6"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID6
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID6 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID6
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID7 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition7"
#   pragma ghs section sdata=".svMemAccMPartition7"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID7
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID7 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID7
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID8 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition8"
#   pragma ghs section sdata=".svMemAccMPartition8"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID8
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID8 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID8
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID9 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition9"
#   pragma ghs section sdata=".svMemAccMPartition9"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID9
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID9 )
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID9
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_START_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_VAR_INIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_STOP_SEC_VAR_INIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_START_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_VAR_INIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_STOP_SEC_VAR_INIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_START_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_VAR_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_STOP_SEC_VAR_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_START_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_VAR_NOINIT_16BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_16BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_START_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_START_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VOTAM_APPL_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef VOTAM_APPL_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VOTAM_APPL_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef VOTAM_APPL_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VOTAM_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef VOTAM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VOTAM_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef VOTAM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VOTAM_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef VOTAM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VOTAM_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef VOTAM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VOTAM_START_SEC_COPY_BUFFER_VAR_NOINIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VOTAM_START_SEC_COPY_BUFFER_VAR_NOINIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VOTAM_STOP_SEC_COPY_BUFFER_VAR_NOINIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VOTAM_STOP_SEC_COPY_BUFFER_VAR_NOINIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VOTAM_START_SEC_PROC_BUFFER_VAR_NOINIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VOTAM_START_SEC_PROC_BUFFER_VAR_NOINIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VOTAM_STOP_SEC_PROC_BUFFER_VAR_NOINIT )
   /* #pragma <enter your compiler specific pragma> */
# undef VOTAM_STOP_SEC_PROC_BUFFER_VAR_NOINIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VOTAM_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef VOTAM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VOTAM_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef VOTAM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSECPRIM_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef VSECPRIM_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSECPRIM_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef VSECPRIM_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSECPRIM_START_SEC_CONST_32BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef VSECPRIM_START_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSECPRIM_STOP_SEC_CONST_32BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef VSECPRIM_STOP_SEC_CONST_32BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSECPRIM_START_SEC_CONST_64BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef VSECPRIM_START_SEC_CONST_64BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSECPRIM_STOP_SEC_CONST_64BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef VSECPRIM_STOP_SEC_CONST_64BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSECPRIM_START_SEC_CONST_8BIT )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef VSECPRIM_START_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSECPRIM_STOP_SEC_CONST_8BIT )
# pragma section nearrom restore
# pragma section farrom restore
# undef VSECPRIM_STOP_SEC_CONST_8BIT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSECPRIM_START_SEC_CONST_UNSPECIFIED )
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef VSECPRIM_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSECPRIM_STOP_SEC_CONST_UNSPECIFIED )
# pragma section nearrom restore
# pragma section farrom restore
# undef VSECPRIM_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( VSTDLIB_START_SEC_CODE )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef VSTDLIB_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( VSTDLIB_STOP_SEC_CODE )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef VSTDLIB_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_CODE_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_CODE_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_CODE_FAST_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_CODE_FAST_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32 )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDG_17_SCU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDG_17_SCU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WDG_17_SCU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WDTRIGGER_START_SEC_CODE ) || \
    defined( WDTRIGGER_START_SEC_CODE_EXPORT )
# pragma section code "RamCodeSection"
# pragma section nearrom "RamConstSection"
# pragma section farrom "RamConstSection"
# undef WDTRIGGER_START_SEC_CODE
# undef WDTRIGGER_START_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WDTRIGGER_STOP_SEC_CODE ) || \
    defined( WDTRIGGER_STOP_SEC_CODE_EXPORT )
# pragma section code restore
# pragma section nearrom restore
# pragma section farrom restore
# undef WDTRIGGER_STOP_SEC_CODE
# undef WDTRIGGER_STOP_SEC_CODE_EXPORT
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WRAPNV_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WRAPNV_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WRAPNV_START_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_START_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WRAPNV_STOP_SEC_CONST_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_STOP_SEC_CONST_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

#if defined( WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED )
   /* #pragma <enter your compiler specific pragma> */
# undef WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( _CDD_START_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef _CDD_START_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

#if defined( _CDD_STOP_SEC_CODE )
   /* #pragma <enter your compiler specific pragma> */
# undef _CDD_STOP_SEC_CODE
# undef FBL_MEMMAP_ERROR
#endif

/* ----------------------------------------------------------------------------------------------------------------- */

#if defined( FBL_MEMMAP_ERROR )
# error "Error in MemMap.h: MemMap section is not included!"
#endif

/* Module specific MISRA deviations:

   MD_MemMap_0883:
      Reason:     This file has to be included multiple times explicitly, due to the memory mapping mechanism.
      Risk:       No risk due to the undef pragmas and error pragma.
      Prevention: No prevention.

*/

/**********************************************************************************************************************
 *  END OF FILE: MEMMAP.H
 *********************************************************************************************************************/

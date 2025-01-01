/********************************************************************************************************************** 
 *  COPYRIGHT 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  Copyright (c) 2020 by Mercedes Benz AG - Alle Rechte vorbehalten -  All rights reserved. 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  EXAMPLE CODE ONLY 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW 
 *  configuration. The Example Code has not passed any quality control measures and may be incomplete. The 
 *  Example Code is neither intended nor qualified for use in series production. The Example Code as well 
 *  as any of its modifications and/or implementations must be tested with diligent care and must comply 
 *  with all quality requirements which are necessary according to the state of the art before their use. 
 * 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  FILE DESCRIPTION 
 *  ------------------------------------------------------------------------------------------------------------------- 
 *  File: MemMap.h
 *  Description: This is the sample implementation of the FBL memory map header file. It contains the FBL sections
 *               which are also required by the application.
 *                 
 *********************************************************************************************************************/

#if defined( APPL_SWVERSIONS_START_SEC_CONST )
# pragma protect
# pragma section nearrom "SW_Versions"
# pragma section farrom "SW_Versions"
# undef APPL_SWVERSIONS_START_SEC_CONST
# undef MEMMAP_ERROR
#endif

#if defined( APPL_SWVERSIONS_STOP_SEC_CONST )
# pragma endprotect
# pragma section nearrom restore
# pragma section farrom restore
# undef APPL_SWVERSIONS_STOP_SEC_CONST
# undef MEMMAP_ERROR
#endif
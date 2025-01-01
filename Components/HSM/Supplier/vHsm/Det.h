/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Det.h
 *        \brief  Header file for Det module
 *
 *      \details  Redirects the Det to the vHsm_Det
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef DET_H
# define DET_H
# include "vHsm_Det.h"

/* Redirect the Det API call to the vHsm_Det */
# define Det_ReportError                                              vHsm_Det_ReportError
# define Det_ReportRuntimeError                                       Det_ReportError

# define DET_AR_RELEASE_MAJOR_VERSION                                 4U

#endif

/**********************************************************************************************************************
 *  END OF FILE: Det.h
 *********************************************************************************************************************/

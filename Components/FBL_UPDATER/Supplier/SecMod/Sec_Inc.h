/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the HIS security module - Common includes
 *
 *  \description  Contains all includes used by all security module sources
 *                Not to be included in other sources directly, include Sec.h instead
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
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#ifndef SEC_INC_H
#define SEC_INC_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Global configuration */
#include "v_cfg.h"
#include "Fbl_Cfg.h"
/* Global definitions */
#include "v_def.h"

/* Security module configuration */
#include "SecM_cfg.h"

/* Additional header files */
#include "Std_Types.h"
#if defined( SEC_ENABLE_CSM )
# include "Csm_Types.h"
#endif
#if defined( SEC_ENABLE_CERTIFICATE_OPERATION_ACCESS )
# include "KeyM.h"
#endif /* SEC_ENABLE_CERTIFICATE_OPERATION_ACCESS */
#include "Sec_Types.h"

/* Security module parameters */
#include "SecMPar.h"

#endif /* SEC_INC_H */

/***********************************************************************************************************************
 *  END OF FILE: SEC_INC.H
 **********************************************************************************************************************/

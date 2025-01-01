/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file         WrapNv_inc.h
 *  \brief        Compacts the include files for the NV-Wrapper
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef WRAPNV_INC_H
#define WRAPNV_INC_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "WrapNv.h"
#if defined( WRAPNV_USECASE_EEPM ) || \
    defined( WRAPNV_USECASE_DRVEEP )
/* Include Vector standard includes first */
# include "fbl_def.h"

# include "fbl_inc.h"

# include "iotypes.h"
# if defined( WRAPNV_USECASE_EEPM )
#  include "fbl_flio_xd1.h"
#  include "EepMgr_inc.h"
# else
#  include "EepInc.h"
#  include "EepIO.h"
# endif
#endif /* WRAPNV_USECASE_EEPM || WRAPNV_USECASE_DRVEEP */

#endif   /* WRAPNV_INC_H */

/***********************************************************************************************************************
 *  END OF FILE: WRAPNV_INC.H
 **********************************************************************************************************************/

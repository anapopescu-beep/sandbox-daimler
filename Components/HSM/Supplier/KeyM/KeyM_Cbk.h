/***********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  KeyM_Cbk.h
 *         \unit  *
 *        \brief  KeyM callback header file
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (KEYM_CBK_H)
# define KEYM_CBK_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
# include "KeyM_Cfg.h"

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# if (KEYM_CSM_ASYNC_SIGNATURE_VERIFY == STD_ON)
/***********************************************************************************************************************
 *  KeyM_CallbackNotificationSignature()
 **********************************************************************************************************************/
/*! \brief        Callback Notification for finished signature verify CSM job
 *  \details      Notifies the KeyM that the signature verify job has finished. This function is used by the CSM.
 *  \param[in]    job                     Contains the CSM job.
 *  \param[in]    result                  Contains the result of the cryptographic operation.
 *  \pre          job has to be a job object handle and a valid pointer.
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \config       KEYM_CSM_ASYNC_SIGNATURE_VERIFY == STD_ON
 **********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_CallbackNotificationSignature(P2VAR(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job, Std_ReturnType result);
# endif /* KEYM_CSM_ASYNC_SIGNATURE_VERIFY */

#endif /* KEYM_CBK_H */

/***********************************************************************************************************************
 *  END OF FILE: KeyM_Cbk.h
 **********************************************************************************************************************/

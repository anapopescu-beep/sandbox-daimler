/***********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
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

# if ((KEYM_CRE == STD_ON) && (KEYM_REMOTE_CREENABLED == STD_OFF)) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 *  KeyM_NvBlock_ReadFrom_CRE()
 **********************************************************************************************************************/
/*!\brief       Block specific callback routine which is called by NvM in order to let the KeyM copy data from NvM RAM
 *              mirror to KeyM RAM block.
 * \details     -
 * \param[in]   NvMBuffer   RAM mirror where Ram block data can be read from.
 * \return      E_OK        Data was copied from buffer.
 * \return      E_NOT_OK    Data was not copied.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFrom_CRE(
  P2CONST(void, AUTOMATIC, KEYM_APPL_DATA) NvMBuffer);

/**********************************************************************************************************************
 *  KeyM_NvBlock_WriteTo_CRE()
 **********************************************************************************************************************/
/*!\brief       Block specific callback routine which is called by NvM in order to let the KeyM copy data from RAM block
 *              to NvM RAM mirror.
 * \details     -
 * \param[out]  NvMBuffer  RAM mirror where Ram block data shall be written to.
 * \return      E_OK       Data was copied to buffer.
 * \return      E_NOT_OK   No data was copied.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteTo_CRE(
  P2VAR(void, AUTOMATIC, KEYM_APPL_VAR) NvMBuffer);

/**********************************************************************************************************************
 *  KeyM_NvBlock_Init_CRE()
 **********************************************************************************************************************/
/*!\brief       Block specific callback routine which is called by NvM in order to let the KeyM copy default data to a
 *              RAM block.
 * \details     -
 * \return      E_OK      Data initialized.
 * \return      E_NOT_OK  Any error occurred.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Init_CRE(void);

/**********************************************************************************************************************
 *  KeyM_NvBlock_Callback_CRE()
 **********************************************************************************************************************/
/*!\brief       Block specific callback routine which is called by NvM in order to notify the KeyM that an asynchronous
 *              single block request has been finished.
 * \details     -
 * \param[in]   ServiceId              The service identifier of the completed request.
 * \param[in]   JobResult              Result of the single block job.
 * \return      E_OK                   Callback function has been processed successfully.
 * \return      E_NOT_OK               Callback function has not been processed successfully.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Callback_CRE(uint8 ServiceId, NvM_RequestResultType JobResult);
# endif

#endif /* KEYM_CBK_H */

/***********************************************************************************************************************
 *  END OF FILE: KeyM_Cbk.h
 **********************************************************************************************************************/

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
/*!        \file  vHsm_Nvm.h
 *        \brief  Header file for the Nvm
 *
 *      \details  Header file for the persistent storage of key material
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_NVM_H)
# define VHSM_NVM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "vHsm_Cfg.h"
# include "NvM.h"
# include "vHsm_ApiInternal.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define VHSM_NVM_USED                                                VHSM_API_NVM_USED

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VHSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (VHSM_NVM_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_NvM_ProcessBlock_Callout()
 *********************************************************************************************************************/
/*! \brief       Callout which is called while the NvM is processing
 *  \details     This callout can be used for triggering a watchdog.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_NvM_ProcessBlock_Callout(void);

/**********************************************************************************************************************
 *  vHsm_NvM_InvalidBlockDetected_Callout()
 *********************************************************************************************************************/
/*! \brief       Callout which is called when a not readable block is detected at startup while performing ReadAll().
 *  \details     This will happen on first startup and should not occur during runtime except when data flash gets corrupted.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_NvM_InvalidBlockDetected_Callout(void);

/**********************************************************************************************************************
 *  vHsm_NvM_WriteBlock()
 *********************************************************************************************************************/
/*! \brief       Setups a write job for given NvM block and processes it directly afterwards (synchronous).
 *  \details     Request to copy the data of the RAM block to its corresponding NV block. If the block to be written is
 *               permanent a NULL_PTR shall be given as parameter, otherwise a pointer to the ram block shall be given.
 *  \param[in]   BlockId in range [1, (number of blocks - 1)].
 *  \param[in]   NvM_SrcPtr as a pointer to the RAM buffer NvM shall write. The length of the buffer depends on passed
 *               BlockId (block configuration). May be NULL_PTR for specific blocks.
 *  \return      E_OK job was setup and processed
 *  \return      E_NOT_OK otherwise
 *  \pre -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE

 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_NvM_WriteBlock(
  NvM_BlockIdType BlockId,
  P2CONST(void, AUTOMATIC, VHSM_APPL_VAR) NvM_SrcPtr);

/**********************************************************************************************************************
 *  vHsm_NvM_Init()
 *********************************************************************************************************************/
/*! \brief       Process the data flash content.
 *  \details     This function is called at startup and will handle the key storage in the data flash.
 *               If the key storage has not been initialized, it will compute an initial state and store it.
 *  \return      E_OK                Request successful.
 *  \return      E_NOT_OK            Request failed.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_NvM_Init(void);

/**********************************************************************************************************************
 *  vHsm_NvM_Repersist()
 *********************************************************************************************************************/
/*! \brief       Trigger a write on all Nvm blocks
 *  \details     -
 *  \return      E_OK                Request successful.
 *  \return      E_NOT_OK            Request failed.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_NvM_Repersist(void);

/**********************************************************************************************************************
 *  vHsm_NvM_PerformWriteAll()
 *********************************************************************************************************************/
/*! \brief       Perform a write all and process the request completely (synchronous).
 *  \details     -
 *  \return      E_OK                Request successful.
 *  \return      E_NOT_OK            Request failed.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_NvM_PerformWriteAll(void);
# endif

# define VHSM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSM_NVM_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Nvm.h
 *********************************************************************************************************************/

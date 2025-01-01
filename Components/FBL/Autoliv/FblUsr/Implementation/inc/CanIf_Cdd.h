/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  CanIf_Cdd.h
 *      Project:  FblWrapperCom_PduR
 *       Module:  Implementation
 *    Generator:  CFG5
 *
 *  Description:  Interface declarations for Fbl Communication wrapper layer for MICROSAR ASR4
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#ifndef CANIF_CDD_H
# define CANIF_CDD_H

# define FBLCW_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *   GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FblCw_ControllerBusOff
 *********************************************************************************************************************/
/*! \brief      This API function is used to notify FblCw about a bus-off event on a certain CAN controller
 *  \param[in]  controllerId  CAN controller, which detected a bus-off event
 *  \pre        CW is initialized and active
 *  \note       Currently no controller dependent handling is implemented. The default bus-off callback is used all the time.
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_ControllerBusOff(uint8 controllerId);

/**********************************************************************************************************************
 *  FblCw_ControllerModeIndication
 *********************************************************************************************************************/
/*! \brief      This API function is used to notify FblCw about the change of the controller mode
 *  \param[in]  controllerId  ID of the CAN controller
 *  \param[in]  controllerMode   Current CAN controller mode
 *  \pre        CW is initialized and active
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_ControllerModeIndication(uint8 controllerId, CanIf_ControllerModeType controllerMode);

/**********************************************************************************************************************
 *  FblCw_CheckTransceiverWakeFlagIndication
 *********************************************************************************************************************/
/*! \brief      Handles the indication of a checked transceiver wake up flag
 *  \param[in]  transceiverId  Transceiver, which was checked for PN availability
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_CheckTransceiverWakeFlagIndication(uint8 transceiverId);

/**********************************************************************************************************************
 *  FblCw_ClearTrcvWufFlagIndication
 *********************************************************************************************************************/
/*! \brief      Handles the indication of a cleared transceiver wake up flag
 *  \param[in]  transceiverId  Transceiver, which was checked for PN availability
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_ClearTrcvWufFlagIndication(uint8 transceiverId);

/**********************************************************************************************************************
 *  FblCw_ConfirmPnAvailability
 *********************************************************************************************************************/
/*! \brief      This API function is used to indicate that the transceiver is running in PN communication mode
 *  \param[in]  transceiverId  Transceiver, which was checked for PN availability
 *  \pre        CW is initialized and active
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_ConfirmPnAvailability(uint8 transceiverId);

/**********************************************************************************************************************
 *  FblCw_TransceiverModeIndication
 *********************************************************************************************************************/
/*! \brief      This API function is used to notify FblCw about the change of the transceiver mode
 *  \param[in]  transceiverId  Transceiver where the mode transition happened
 *  \param[in]  controllerMode  Transceiver mode to which the transceiver transitioned
 *  \pre        CW is initialized and active
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_TransceiverModeIndication(uint8 transceiverId, CanTrcv_TrcvModeType transceiverMode);

# define FBLCW_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* CANIF_CDD_H */

/**********************************************************************************************************************
 *  END OF FILE: CANIF_CDD.H
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsmUpd_Ext_Crypto.h
 *        \brief  Extension header file. Functions must be implemented in extension implementation.
 *
 *      \details  Header file for the crypto extension callouts.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef VHSMUPD_EXT_CRYPTO_H
#define VHSMUPD_EXT_CRYPTO_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd_Ext_ImageHeader.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define VHSMUPD_EXT_AES_BLOCKSIZE                       (16u)
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

# define VHSMUPD_EXT_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_DecryptLastBlock()
 *********************************************************************************************************************/
/*!
 * \brief       Finalizes the decryption and stores the last bytes to the buffer provided by the user.
 * \details     -
 * \param[out]  dataOut     where the decrypted data will be stored.
 * \return      E_OK        if the decryption was successful, E_NOT_OK otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_DecryptLastBlock(vHsmUpd_Ext_DataPtrType dataOut);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_VerifyUpdateImage()
 *********************************************************************************************************************/
/*!
 * \brief       Check whether the image, which lies in the Host Code Flash is valid. Valid means, that the MAC is correct.
 * \details     -
 * \return      E_OK, if the update image is valid; E_NOT_OK otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_VerifyUpdateImage(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_DecryptImageBlock()
 *********************************************************************************************************************/
/*!
 * \brief       Decrypt the block within the update image defined in the parameters.
 * \details     -
 * \param[out]  dataOut        is the buffer where the decrypted data will be stored.
 * \param[in]   dataLength     is the length of the buffer, that can be read.
 * \param[in]   imageAddress   is the start address for the decryption.
 * \return      E_OK, if the decryption was successful, E_NOT_OK otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_DecryptImageBlock(
  vHsmUpd_Ext_DataPtrType dataOut,
  vHsmUpd_Ext_LengthType  dataLength,
  vHsmUpd_Ext_AddressType imageAddress);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_VerifyWrittenRegionImage()
 *********************************************************************************************************************/
/*!
 * \brief       Check whether the image, which was installed by the vHsmUpd is valid.
 * \details     -
 * \param[in]   regionHeader  The region header of the installed region which has to be verified.
 * \return      E_OK, if the Hsm Fw image is valid (CRC); E_NOT_OK otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_VerifyWrittenRegionImage(vHsmUpd_Ext_ModuleUpdateHeaderPtrType regionHeader);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_DecryptSBL()
 *********************************************************************************************************************/
/*!
 * \brief       Decrypt the SBL and discards all results. Needed when the SBL part is not empty, but this part currently
 *              cannot be processed/used by the vHsmUpd.
 * \details     -
 * \return      E_OK, if the decryption was successful, E_NOT_OK otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_DecryptSBL(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_InitDecryption()
 *********************************************************************************************************************/
/*!
 * \brief       Sets up the decryption by getting the cipher key.
 * \details     -
 * \return      E_OK, if decryption was successfully started, E_NOT_OK otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_InitDecryption(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckCurrentDecryptionPoint()
 *********************************************************************************************************************/
/*!
 * \brief       Checks if the current address inside of the update image matches the current read point.
 * \details     -
 * \param[in]   imageSourceAddress        Address to read from.
 * \return      E_OK, if decryption was successfully started, E_NOT_OK otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckCurrentDecryptionPoint(vHsmUpd_Ext_AddressType imageSourceAddress);

# define VHSMUPD_EXT_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VHSMUPD_EXT_CRYPTO_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_Crypto.h
 *********************************************************************************************************************/

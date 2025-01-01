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
/*!        \file  vHsmUpd.h
 *        \brief  vHsmUpd header file
 *
 *      \details  Header file for the vHsmUpd. Defines the public API.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id                 Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2020-08-10  visfnn  -                         Create vHSM Updater Core
 *  01.00.02  2020-11-20  visfnn  HSM-1278                  Move vHsmUpd_InitializeMemDriver before first Blank check.
 *  02.00.00  2021-01-12  visfnn  HSM-1185                  Restructure the vHsmUpd_Core
 *  02.01.00  2021-02-15  visfpt  HSM-1507                  Prepare for multi module updates
 *********************************************************************************************************************/

#if !defined (VHSMUPD_H)
# define VHSMUPD_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "vHsmUpd_Types.h"
#include "vHsmUpd_Callout.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define VHSMUPD_SW_MAJOR_VERSION                    (2u)
# define VHSMUPD_SW_MINOR_VERSION                    (1u)
# define VHSMUPD_SW_PATCH_VERSION                    (0u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPE
 *********************************************************************************************************************/
#define VHSMUPD_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Init()
 *********************************************************************************************************************/
/*!
 * \brief       The main function of the vHsmUpd.
 * \details     This function is the start function of the vHsmUpd. It checks whether to start the vHsm fw or perform an
 *              update if available.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_CODE) vHsmUpd_Init( void );

/**********************************************************************************************************************
 *  vHsmUpd_CompareBuffers()
 *********************************************************************************************************************/
/*!
 * \brief       Checks two given buffers and it's values.
 * \details     -
 * \return      TRUE if both buffers match in content, FALSE otherwise.
 * \param[in]   ptr1     is the first buffer
 * \param[in]   ptr2     is the second buffer
 * \param[in]   length   of the comparison
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VHSMUPD_CODE) vHsmUpd_CompareBuffers(
  vHsmUpd_ConstDataPtrType ptr1,
  vHsmUpd_ConstDataPtrType ptr2,
  uint32 length);

/**********************************************************************************************************************
 *  vHsmUpd_ReadPresencePattern()
 *********************************************************************************************************************/
/*!
 * \brief       Read a presence pattern at the given location.
 * \details     -
 * \return      E_OK if the presence pattern could be read and has valid state, E_NOT_OK otherwise.
 * \param[in]   addressAreaId  area id of the used vMemAccM Area Configuration.
 * \param[in]   ppAddress      is the address where to search for a presence pattern.
 * \param[in]   target         defines if host or hsm memory is read
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_ReadPresencePattern(
  vHsmUpd_MemoryAreaIdType  addressAreaId,
  vHsmUpd_AddressType       ppAddress,
  vHsmUpd_TargetCoreType    target);

/**********************************************************************************************************************
 *  vHsmUpd_MemRead()
 *********************************************************************************************************************/
/*!
 * \brief       Performs a memory mapped bytewise read on the given address and stores the amount of data in the
 *              Buffer provided.
 * \details     -
 * \param[out]  readBuffer     where the read data will be stored.
 * \param[in]   readLength     is the number of bytes that shall be read.
 * \param[in]   readAddress    is the address where to read from.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_CODE) vHsmUpd_MemRead(
  vHsmUpd_DataPtrType readBuffer,
  vHsmUpd_LengthType  readLength,
  vHsmUpd_AddressType readAddress);

/**********************************************************************************************************************
 *  vHsmUpd_WriteData()
 *********************************************************************************************************************/
/*!
 * \brief       Writes the data buffer into code flash of Hsm.
 * \details     -
 * \param[in]   addressAreaId  area id of the used vMemAccM Area Configuration.
 * \param[in]   writeBuffer    where the data is stored that will be written to code flash.
 * \param[in]   length         of the data to be written.
 * \param[in]   address        to write to.
 * \return      E_OK if the write was successful, E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_WriteData(
  vHsmUpd_MemoryAreaIdType  addressAreaId,
  vHsmUpd_ConstDataPtrType  writeBuffer,
  vHsmUpd_LengthType        length,
  vHsmUpd_AddressType       address);

/**********************************************************************************************************************
 *  vHsmUpd_EraseData()
 *********************************************************************************************************************/
/*!
 * \brief       Erase the given position in the codeflash.
 * \details     -
 * \param[in]   addressAreaId  area id of the used vMemAccM Area Configuration.
 * \param[in]   length         of the area to be erased.
 * \param[in]   address        start address of the area to be erased
 * \return      E_OK if the Erase was successful, E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_EraseData(
  vHsmUpd_MemoryAreaIdType  addressAreaId,
  vHsmUpd_LengthType        length,
  vHsmUpd_AddressType       address);

/**********************************************************************************************************************
 *  vHsmUpd_ReadData()
 *********************************************************************************************************************/
/*!
 * \brief       Reads the specified data from the codeflash.
 * \details     Uses the vMem to read from the codeflash.
 * \param[in]   addressAreaId   of the area to read from.
 * \param[out]  readBuffer      buffer where the read data is written.
 * \param[in]   length          of the read data.
 * \param[in]   address         in the codeflash, where to read.
 * \return      E_OK if the Erase was successful, E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_ReadData(
  vHsmUpd_MemoryAreaIdType  addressAreaId,
  vHsmUpd_DataPtrType       readBuffer,
  vHsmUpd_LengthType        length,
  vHsmUpd_AddressType       address);

/**********************************************************************************************************************
 *  vHsmUpd_IsBlank()
 *********************************************************************************************************************/
/*!
 * \brief       Reads the specified data from the codeflash.
 * \details     Uses the vMem to read from the codeflash.
 * \param[in]   addressAreaId   of the area to read from.
 * \param[in]   length          of the read data.
 * \param[in]   address         in the codeflash, where to read.
 * \param[out]  isBlank         pointer to blank check result.
 * \return      TRUE, if the given address and length is blank
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_IsBlank(
  vHsmUpd_MemoryAreaIdType        addressAreaId,
  vHsmUpd_LengthType              length,
  vHsmUpd_AddressType             address,
  vHsmUpdBooleanResultPtrType     isBlank);

/**********************************************************************************************************************
 *  vHsmUpd_BigEndianByteArrayToUint32()
 *********************************************************************************************************************/
/*!
 * \brief         Concatenates the given array to a uint32 number. Interprets the array as Big Endian.
 * \details       -
 * \param[in]     array   Array to concatenate.
 * \return        The concatenated number. If uint16, the lower 2 Bytes are used.
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
FUNC(uint32, VHSMUPD_CODE) vHsmUpd_BigEndianByteArrayToUint32(
  vHsmUpd_ConstDataPtrType array);

/**********************************************************************************************************************
 *  vHsmUpd_BigEndianByteArrayToUint16()
 *********************************************************************************************************************/
/*!
 * \brief         Concatenates the given array to a uint16 number. Interprets the array as Big Endian.
 * \details       -
 * \param[in]     array   Array to concatenate.
 * \return        The concatenated number.
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
FUNC(uint16, VHSMUPD_CODE) vHsmUpd_BigEndianByteArrayToUint16(
  vHsmUpd_ConstDataPtrType array);

#define VHSMUPD_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSMUPD_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd.h
 *********************************************************************************************************************/

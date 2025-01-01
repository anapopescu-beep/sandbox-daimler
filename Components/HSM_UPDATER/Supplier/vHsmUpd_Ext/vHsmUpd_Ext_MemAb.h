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
/*!        \file  vHsmUpd_Ext_MemAb.h
 *        \brief  Extension header file. Functions must be implemented in extension implementation.
 *
 *      \details  Header file for the Extension callouts.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef VHSMUPD_EXT_MEMAB_H
#define VHSMUPD_EXT_MEMAB_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd_Ext_ImageHeader.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define VHSMUPD_EXT_UPDHEADER_INVALID                    0xFFFFFFFFuL

#define VHSMUPD_EXT_SIZE_OF_PP                            (4u)  /*!< Size of the presence pattern for validity checks */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
# define VHSMUPD_EXT_SIZE_OF_IMAGE_INFO         (16u)  /*!< Size of the first block within the update image */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define VHSMUPD_EXT_START_SEC_CONST_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*!< Indicates how many pages are used within the header (without pp) */
extern CONST(vHsmUpd_Ext_LengthType, AUTOMATIC) vHsmUpd_Ext_HeaderLengthInPages;

#define VHSMUPD_EXT_STOP_SEC_CONST_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSMUPD_EXT_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(vHsmUpd_Ext_UpdateHeaderType, VHSMUPD_EXT_VAR_NOINIT) vHsmUpd_Ext_CurrentUpdHdr; /*!< Structure used for storing the update header */

/* Structure to hold the maximum number of module headers */
extern VAR(vHsmUpd_Ext_ModuleUpdateHeaderType, VHSMUPD_EXT_VAR_NOINIT) vHsmUpd_Ext_ModularUpdateHeader[vHsmUpd_Ext_GetSizeOfRegion() * vHsmUpd_Ext_GetSizeOfPartitions()];

#define VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VHSMUPD_EXT_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetRawVersionValueInUpdHdr()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the pointer to the firmware version of the update header.
 * \details     -
 * \param[out]  valuePtr        which will show the location to the raw, i.e. byte stream value for the firmware
 *                              version within the update header.
 * \param[out]  length          of the raw value in bytes.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetRawVersionValueInUpdHdr(
  vHsmUpd_Ext_PtrToConstDataPtrType valuePtr,
  vHsmUpd_Ext_LengthPtrType         length);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetSizeOfImage()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the size of the encrypted update image.
 * \details     -
 * \return      Size of the update image.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vHsmUpd_Ext_LengthType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetSizeOfImage(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetRawAddressValueInUpdHdr()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the pointer to the firmware address of the update header.
 * \details     -
 * \param[out]  valuePtr    which will show the location to the raw, i.e. byte stream value for the address
 *                          of the update image within the update header.
 * \param[out]  length      of the raw value in bytes.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetRawAddressValueInUpdHdr(
  vHsmUpd_Ext_PtrToConstDataPtrType valuePtr,
  vHsmUpd_Ext_LengthPtrType         length);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetRawLengthValueInUpdHdr()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the pointer to the firmware length of the update header.
 * \details     -
 * \param[out]  valuePtr    which will show the location to the raw, i.e. byte stream value for the length of
 *                          the update image within the update header.
 * \param[out]  length      of the raw value in bytes.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetRawLengthValueInUpdHdr(
  vHsmUpd_Ext_PtrToConstDataPtrType valuePtr,
  vHsmUpd_Ext_LengthPtrType         length);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetUpdateSignature()
 *********************************************************************************************************************/
/*!
 * \brief       Reads the update signature and stores it to the given buffer.
 * \details     -
 * \param[out]  cmac        where the cmac will be stored.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetUpdateSignature(vHsmUpd_Ext_DataPtrType cmac);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ParseUpdateImageInformation()
 *********************************************************************************************************************/
/*!
 * \brief       Uses the given input buffer and processes it to determine and get information about the given update
 *              image.
 * \details     -
 * \param[in]   dataIn          is the buffer on which the data processing will be done.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ParseUpdateImageInformation(vHsmUpd_Ext_ConstDataPtrType dataIn);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetAddressOfFwDataInUpdateImage()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the start address of the firmware within the update image.
 * \details     -
 * \return      Returns the start address of the firmware within the update image.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vHsmUpd_Ext_AddressType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetAddressOfFwDataInUpdateImage(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetAddressOfCrcInUpdateImage()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the start address of the Crc value within the update image.
 * \details     -
 * \return      Returns the start address of the Crc value within the update image.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vHsmUpd_Ext_AddressType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetAddressOfCrcInUpdateImage(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ReadUpdateHeader()
 *********************************************************************************************************************/
/*!
 * \brief       Reads the update header from NV memory.
 * \details     -
 * \param[in]   headerAddress    which will be searched for an valid update header.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ReadUpdateHeader(
  vHsmUpd_Ext_AddressType headerAddress);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckUpdateHeader()
 *********************************************************************************************************************/
/*!
 * \brief       Check whether the update header tag is valid.
 * \details     -
 * \return      TRUE, if the update header tag is valid; FALSE otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckUpdateHeader(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_EraseRegion()
 *********************************************************************************************************************/
/*!
 * \brief       Erases the complete region.
 * \details     -
 * \return      E_OK if the flash was erased successfully, E_NOT_OK otherwise.
 * \param[in]   regionHeader    The region which should become erased.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_EraseRegion(vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetImageStartAddress()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the start address of the update image.
 * \details     -
 * \return      Address of the update image.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vHsmUpd_Ext_AddressType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetImageStartAddress(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckForModularUpdatePattern()
 *********************************************************************************************************************/
/*!
 * \brief       compares the first 4 byte in the given array with the modular update pattern.
 * \details     -
 * \param[in]   data    Array with the data read from the update image
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckForModularUpdatePattern(vHsmUpd_Ext_ConstDataPtrType data);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ParseModularUpdateHeader()
 *********************************************************************************************************************/
/*!
 * \brief       Parses the date given in the array to the module update header.
 * \details     -
 * \return      E_OK if the header is parsed ant the target region is found.
 * \param[in]   updateHeaderBinary    Array with the data read from the update image
 * \param[in]   index                 The index of the currently read header.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ParseModularUpdateHeader(
  vHsmUpd_Ext_ConstDataPtrType updateHeaderBinary,
  uint8 index);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ParseStandardHeaderToModule()
 *********************************************************************************************************************/
/*!
 * \brief       If no modular header is used. The standard header is parsed to the modular update structure.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ParseStandardHeaderToModule(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_SizeOfRegionUpdate()
 *********************************************************************************************************************/
/*!
 * \brief       Checks, the module version is higher and the update image fits into the codeflash.
 * \details     -
 * \return      E_OK if the version of all module updates is higher and all region updates fits into the codeflash.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_SizeOfRegionUpdate(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_InvalidatePresencePatternOfModule()
 *********************************************************************************************************************/
/*!
 * \brief       Invalidates the presence pattern of the given region.
 * \details     -
 * \return      E_OK if the invalidation was successfull.
 * \param[in]   regionHeader    The current region. The presence pattern of this region will become invalidated.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_InvalidatePresencePatternOfModule(vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ValidatePresencePatternOfRegion()
 *********************************************************************************************************************/
/*!
 * \brief       Validates the presence pattern and writes the version information for the given module
 * \details     -
 * \return      E_OK The decryption and write process was successfull.
 * \param[in]   regionHeader    The current region.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ValidatePresencePatternOfRegion(vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetActivePartitionId()
 *********************************************************************************************************************/
/*!
 * \brief       Returns the index of the currently active partition
 * \details     -
 * \param[in]   id    index of currently active partition.
 * \return      The index of the currently active partition.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetActivePartitionId(vHsmUpd_Ext_PartitionIndexPtrType id);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckPagesizeAlignmentAndPad()
 *********************************************************************************************************************/
/*!
 * \brief       Checks the alignment and adds necessary padding bytes.
 * \details     -
 * \return      The padded length in the processing buffer.
 * \param[in]   processingDataBuffer    Buffer with decrypted data.
 * \param[in]   dataLength              Length of payload in processing buffer.
 * \param[in]   paddedLength            Length of aes padded data in processing buffer.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
FUNC(vHsmUpd_Ext_LengthType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckPagesizeAlignmentAndPad(
  vHsmUpd_Ext_DataPtrType processingDataBuffer,
  vHsmUpd_Ext_LengthType  dataLength,
  vHsmUpd_Ext_LengthType  paddedLength);

# define VHSMUPD_EXT_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VHSMUPD_EXT_MEMAB_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_MemAb.h
 *********************************************************************************************************************/

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
/*!        \file  vMemAccM_MemAb.h
 *        \brief  vMemAccM memory abstraction submodule header file
 *
 *      \details  The vMemAccM memory abstraction sub module takes care about the "physical part" of a job. That means
 *                it calculates the physical address and other relevant values and forwards the job to sub address
 *                area specific vMem.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEMACCM_MEMAB_H)
# define VMEMACCM_MEMAB_H

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VMEMACCM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)

/**********************************************************************************************************************
 *  vMemAccM_MemAbWrite
 *********************************************************************************************************************/
/*!
 * \brief       Forwards the write request to the sub address area specific vMem.
 * \details     Calculates the actual physical address from passed offset and the sub address area physical start
 *              address. The length is the remaining job length. The function calculates the possible job length, which
 *              may be either a burst size (if configured) or a normal page size and returns the actually requested
 *              length.
 *              The function forwards the data pointer as it is, it has to point to the data to be written.
 * \param[in]   SubAddressAreaId as array index, used to access the physical information.
 * \param[in]   Offset from start address of the sub address area.
 * \param[in]   DataPtr holding the data to be forwarded to the lower layer. Parameter must not be NULL_PTR.
 * \param[in]   Length requested by upper sub module in bytes.
 * \return      Returns the number of written bytes. 0 if vMem rejects the request.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_LengthType, VMEMACCM_CODE) vMemAccM_MemAbWrite
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Offset,
  vMemAccM_ConstDataPtrType DataPtr,
  vMemAccM_LengthType Length
);

/**********************************************************************************************************************
 *  vMemAccM_MemAbRead
 *********************************************************************************************************************/
/*!
 * \brief       Forwards the read request to the sub address area specific vMem.
 * \details     Calculates the actual physical address from passed offset and the sub address area physical start
 *              address.
 *              The function forwards the data pointer as it is, it has to point to the next free byte.
 * \param[in]   SubAddressAreaId as array index, used to access the physical information.
 * \param[in]   Offset from start address of the sub address area.
 * \param[out]  DataPtr ready to be filled by the lower layer. Parameter must not be NULL_PTR.
 * \param[in]   Length requested by upper sub module in bytes.
 * \return      Returns the number of read bytes. 0 if vMem rejects the request.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_LengthType, VMEMACCM_CODE) vMemAccM_MemAbRead
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Offset,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType Length
);

/**********************************************************************************************************************
 *  vMemAccM_MemAbErase
 *********************************************************************************************************************/
/*!
 * \brief       Forwards the erase request to the sub address area specific vMem.
 * \details     Calculates the actual physical address from passed offset and the sub address area physical start 
 *              address. The length is the remaining job length. The function calculates the possible job length, which
 *              which may be either a burst size (if configured) or a normal sector size and returns the actually
 *              requested length. 
 * \param[in]   SubAddressAreaId as array index, used to access the physical information.
 * \param[in]   Offset from start address of the sub address area.
 * \param[in]   Length requested by upper sub module in bytes.
 * \return      Returns the number of erases bytes. 0 if vMem rejects the request.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_LengthType, VMEMACCM_CODE) vMemAccM_MemAbErase
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Offset,
  vMemAccM_LengthType Length
);

/**********************************************************************************************************************
 *  vMemAccM_MemAbIsBlank
 *********************************************************************************************************************/
/*!
 * \brief       Forwards the IsBlank request to the sub address area specific vMem.
 * \details     Calculates the actual physical address from passed offset and the sub address area physical start
 *              address. The length is the remaining job length. The function sets the possible job length and returns
 *              the actually requested length.
 * \param[in]   SubAddressAreaId as array index, used to access the physical information.
 * \param[in]   Offset from start address of the sub address area.
 * \param[in]   Length requested by upper sub module in bytes.
 * \return      Returns the number of checked bytes. 0 if vMem rejects the request.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_LengthType, VMEMACCM_CODE) vMemAccM_MemAbIsBlank
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Offset,
  vMemAccM_LengthType Length
);

/**********************************************************************************************************************
 *  vMemAccM_MemAbHWSpecificReq
 *********************************************************************************************************************/
/*!
 * \brief           Forwards the passed DataPtr and Length to the HW specific function of the sub address area.
 * \details         HW specific function index is used to select the specific function from function pointer table.
 * \param[in]       SubAddressAreaId as array index, used to access the physical information.
 * \param[in]       vMemHwSpecificFuncIndex as an function pointer array index. The parameter will be used to call the
 *                  right vMem function.
 * \param[in,out]   DataPtr holding the data to be forwarded to the lower layer.
 * \param[in]       DataSize holding the size of the data in bytes.
 * \return          Returns the return value of the called function.
 * \pre             vMemAccM is not the satellite within a multi partition configuration.
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_MemAbHWSpecificReq
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType DataSize
);

/**********************************************************************************************************************
 *  vMemAccM_MemAbIsBusy
 *********************************************************************************************************************/
/*!
 * \brief       Returns the current vMem job result mapped to vMemAccM job result type.
 * \details     -
 * \param[in]   SubAddressAreaId as array index, used to access the physical information.
 * \return      Current vMem job result. Returns VMEMACCM_JOB_FAILED in case of an unknown vMem job result.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_JobResultType, VMEMACCM_CODE) vMemAccM_MemAbGetJobResult(vMemAccM_AddressAreaIdType SubAddressAreaId);

# endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */

# define VMEMACCM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VMEMACCM_MEMAB_H */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_MemAb.h
 *********************************************************************************************************************/

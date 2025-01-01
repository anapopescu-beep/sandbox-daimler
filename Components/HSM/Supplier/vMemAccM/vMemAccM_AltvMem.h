/**********************************************************************************************************************
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
/*!        \file  vMemAccM_AltvMem.h
 *        \brief  vMemAccM alternate vMem submodule header file
 *
 *      \details  The alternate vMem sub module provide functionality to exchange pre-configured vMems with alternate 
 *                vMems via activation and deactivation services. A successful activation is assured by internal 
 *                validation of the alternate vMem and searching of the corresponding pre-configured vMem.
 *                
 *                ATTENTION: 
 *                The respective activate and deactivate services within this header file are public services of the
 *                vMemAccM module.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEMACCM_ALTVMEM_H)
# define VMEMACCM_ALTVMEM_H

# include "vMemAccM_Types.h"
# include "vMemAccM_Cfg.h"

# if (VMEMACCM_USE_DOWNLOADABLE_VMEM == STD_ON)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VMEMACCM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMemAccM_ActivatevMem
 *********************************************************************************************************************/
/*!
 * \brief       Activate an alternate vMem. Therefore a pre-configured vMem is exchanged with an alternate,
                e.g downloadable, vMem. Memory requests originally targeting the pre-configured vMem are then redirected
                to the alternate vMem.
 * \details     A successfull activation implies:
                The alternate vMem was validated successfully by checking the alternate vMem header and footer.
                A corresponding pre-configured vMem was found.
                The alternate vMem was initialized.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   Address pointing to the first byte of the alternate vMem. Will be validated within function.
 * \param[in]   Length address range holding the vMem.
 * \return      E_OK activation was successfull;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       CREQ-286387
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_ActivatevMem
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_LengthType Length
);

/**********************************************************************************************************************
 *  vMemAccM_DeactivatevMem
 *********************************************************************************************************************/
/*!
 * \brief       Deactivate an alternate vMem. Therefore an alternate, e.g. downloadable, vMem is exchanged with the 
                pre-configured vMem. Memory requests target the pre-configured vMem.
 * \details     The vMem at the forwarded address will be deactivated. The pre-configured vMem will be re-initialized.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   Address pointing to the first byte of the alternate vMem, which shall be deactivated.
 * \param[in]   Length address range holding the vMem.
 * \return      E_OK deactivation was successfull;
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       CREQ-286388
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_DeactivatevMem
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_LengthType Length
);

# define VMEMACCM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

# endif /* (VMEMACCM_USE_DOWNLOADABLE_VMEM == STD_ON) */

#endif /* VMEMACCM_ALTVMEM_H */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_AltvMem.h
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: vMem_30_Tc3xxInf01
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000612_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vMem_30_Tc3xxInf01_Callout.h
 *   Generation Time: 2022-04-13 13:37:46
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2000612_D04
 *      Tool Version: DaVinci Configurator (beta) 5.24.30 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#if !defined (VMEM_30_TC3XXINF01_CALLOUT_H)
# define VMEM_30_TC3XXINF01_CALLOUT_H

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
typedef enum
{
   VMEM_30_TC3XXINF01_SYSTEM,   /*!< Lock/unlock system/safety level. */
   VMEM_30_TC3XXINF01_CPU       /*!< Lock/unlock CPU specific level. */
} vMem_30_Tc3xxInf01_LockLevelType; /*!< Type specifying lock/ unlock level. */

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

# define VMEM_30_TC3XXINF01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_Unlock()
 *********************************************************************************************************************/
/*!
 * \brief       Unlock registers/ HW belonging to other components than the PFlash driver vMem_30_Tc3xxInf01.
 * \details     vMem_30_Tc3xxInf01 is a PFlash driver. For e.g. the endinit protection, access to registers/ HW
 *              belonging to another components may be necessary - this access has to be implemented outside of the
 *              vMem_30_Tc3xxInf01 component.
 *              If no unlocking is needed, the function shall be empty.
 * \param[in]   Level: the requested lock level.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
void vMem_30_Tc3xxInf01_Unlock(vMem_30_Tc3xxInf01_LockLevelType Level);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_Lock()
 *********************************************************************************************************************/
/*!
 * \brief       Lock registers/ HW belonging to other components than the PFlash driver vMem_30_Tc3xxInf01.
 * \details     vMem_30_Tc3xxInf01 is a PFlash driver. For e.g. the endinit protection, access to registers/ HW
 *              belonging to another components may be necessary - this access has to be implemented outside of the
 *              vMem_30_Tc3xxInf01 component.
 *              If no locking is needed, the function shall be empty.
 * \param[in]   Level: the requested lock level.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
void vMem_30_Tc3xxInf01_Lock(vMem_30_Tc3xxInf01_LockLevelType Level);

# define VMEM_30_TC3XXINF01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VMEM_30_TC3XXINF01_CALLOUT_H */


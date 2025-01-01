
/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version:
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.6 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/MMG/Implementation/src/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup MMG_EnableCondition.c MMG
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_MMG_AC_ModeManagement.h"
#include "common.h"
#include "MMG_Private.h"

#include "Nvp_Cfg.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 * 		Macro used for bit clearing inhibition status
 */
#define MMG_SET_ENABLE_CONDITION_MASK_OFF(mask)           U8_BIT_CLEAR(MMG_u16EnableCondition_Status, (mask))
/**
 * \brief
 * 		Macro used for bit setting inhibition status
 */
#define MMG_SET_ENABLE_CONDITION_MASK_ON(mask)            U8_BIT_SET(MMG_u16EnableCondition_Status, (mask))


#define BOOL_MMG_SET_ENABLE_CONDITION       (1u)

#define BOOL_MMG_CLEAR_ENABLE_CONDITION     (0u)
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
/**
 * \brief
 *		This variable holds the status of the profile inhibition causes
 * \remarks
 *		None.
 */
uint8 MMG_u16EnableCondition_Status = KU8_ZERO;
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define MMG_AC_ModeManagement_START_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"

/**
 * \brief
 *
 *
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void mmg_CheckIgnitionON(void)
{
	uint8 u8IgnitionStatus = KU8_FALSE;

	/* Read status of Ignition signal */
	(void)Rte_Read_pclIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition(&u8IgnitionStatus);

	if(KU8_TRUE == u8IgnitionStatus)
	{
		M_SET_MODE_MASK_OFF(MMG_KU32_MASK_ENABLE_IGNITION_ON);
		(void)Rte_Call_pclEnableCondition1_SetEnableCondition(BOOL_MMG_SET_ENABLE_CONDITION);
	}
	else
	{
		M_SET_MODE_MASK_ON(MMG_KU32_MASK_ENABLE_IGNITION_ON);
		(void)Rte_Call_pclEnableCondition1_SetEnableCondition(BOOL_MMG_CLEAR_ENABLE_CONDITION);
	}

}
/**
 * \brief
 *
 *
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void mmg_CheckCodingOfAPI(void)
{
	if(NVP_stVehicleEquipmentData.APIActivation != 0x00)
	{
		M_SET_MODE_MASK_ON(MMG_KU32_MASK_ENABLE_CODING_API);
		(void)Rte_Call_pclEnableCondition4_SetEnableCondition(BOOL_MMG_CLEAR_ENABLE_CONDITION);
	}

	else
	{
		M_SET_MODE_MASK_OFF(MMG_KU32_MASK_ENABLE_CODING_API);
		(void)Rte_Call_pclEnableCondition4_SetEnableCondition(BOOL_MMG_SET_ENABLE_CONDITION);
	}
}
/**
 * \brief
 *
 *
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void mmg_CheckBeltHandover(void)
{

	if(NVP_stVehicleEquipmentData.BltHandOverAvailabiliy != 0x00)
	{
		M_SET_MODE_MASK_ON(MMG_KU32_MASK_ENABLE_CODING_BLT);
		(void)Rte_Call_pclEnableCondition2_SetEnableCondition(BOOL_MMG_CLEAR_ENABLE_CONDITION);
	}

	else
	{
		M_SET_MODE_MASK_OFF(MMG_KU32_MASK_ENABLE_CODING_BLT);
		(void)Rte_Call_pclEnableCondition2_SetEnableCondition(BOOL_MMG_SET_ENABLE_CONDITION);
	}
}



/**
 * \brief
 *		Defined macro from C file.
 */
#define MMG_AC_ModeManagement_STOP_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"


/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/

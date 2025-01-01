
#ifndef SCM_CFG_H_
#define SCM_CFG_H_ 1

/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version: 
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
*******************************************************************************

Overview of the interfaces:
   <Describes details of this header file>

******************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.1.5.2.4 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/SCM/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/

/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *       System context size
 */
#define SCM_KU8_SYSTEM_CONTEXT_SIZE                    ((uint8) sizeof(SCM_stSystemContextType))

/**
 * \brief
 * 		Number of System Context blocks configured in NVM
 */
#define SCM_KU8_MAX_SYSTEM_CONTEXT_SUBBLOCKS           ((uint8) 3)
/**
 * \brief
 * 		Value to indicate system context reallocation is needed
 */
#define SCM_KU8_REALLOCATION_NEEDED                    ((uint8) 0)
/**
 * \brief
 * 		Value to indicate system context reallocation is finished
 */
#define SCM_KU8_REALLOCATION_FINISHED                  ((uint8) 2)
/**
 * \brief
 * 		Number of belt function for release
 */
#define SCM_KU8_NUMBER_OF_RELEASE                  ((uint8) 4)
/**
 * \brief
 * 		Number of production cycle
 */
#define SCM_KU8_NUMBER_OF_PRODUCTION_CYCLE         ((uint8) 2)
/**
 * \brief
 * 		Mask used to access the MSB  of the deficiency level
 */
#define SCM_KU32_SW_PROTECTION_BIT_MASK                ((uint32) 0xAA000000)
/**
 * \brief
 * 		Mask used to store SW protection qualified status
 */
#define SCM_KU8_SW_PROTECTION_QUALIFIED_MASK           ((uint8)  0xAA)

/******************************************************************************
DEFINITION OF MACROS
******************************************************************************/

/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/*!
 *  \brief structure containing system context
 *
 */
typedef struct
{
	/**
 	* \brief
 	*		System Time
 	*/
   uint32    u32StoreSystemTime;
	/**
	* \brief
	*		Deficiency level
	*/
   uint32    u32StoreDeficiencyLevel;
	/**
	* \brief
	*		KL30 battery loss
	*/
   uint8     b8StoreKL30Lost;
	/**
	* \brief
	*		Executed Cycle
	*/
   uint8     u8StoreExecutedCycle;
	/**
	* \brief
	*		CPL Status
	*/
   uint8     u8CPLstatus;
	/**
	* \brief
	*		System Context Chesksum
	*/
   uint8     u8StoreSystemContextChecksum;
} SCM_stSystemContextType;

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/
#define SCM_AC_SystemContextManagement_START_SEC_VAR_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

extern uint8 SCM_au8AbortionFlagsArray[SCM_KU8_NUMBER_OF_RELEASE];

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

#define SCM_AC_SystemContextManagement_START_SEC_VAR_INIT_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

extern uint8 SCM_u8SystemContextReallocationStatus;
extern uint8 SCM_b8ReleaseHasToBeTriggered;
extern boolean SCM_bIsSystemContextStorageRequested;

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_INIT_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

#define SCM_AC_SystemContextManagement_START_SEC_VAR_UNSPECIFIED
#include "SCM_AC_SystemContextManagement_MemMap.h"

extern SCM_stSystemContextType SCM_stCurrentSystemContextContent;

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_UNSPECIFIED
#include "SCM_AC_SystemContextManagement_MemMap.h"

#define SCM_AC_SystemContextManagement_START_SEC_VAR_INIT_32
#include "SCM_AC_SystemContextManagement_MemMap.h"

extern uint32 SCM_u32OldSystemTime;

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_INIT_32
#include "SCM_AC_SystemContextManagement_MemMap.h"


#define SCM_AC_SystemContextManagement_START_SEC_VAR_NO_INIT_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

extern uint8 SCM_u8LastInterruptedCycleNumber;
extern uint8 SCM_u8LastInterruptedCycleNumber_Mirror;

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_NO_INIT_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/
#define SCM_AC_SystemContextManagement_START_SEC_CONST_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

extern const u8CycleNumberType scm_kau8ReleaseIdList[SCM_KU8_NUMBER_OF_RELEASE];
extern const u8CycleNumberType scm_kau8ProductionCycleIdList[SCM_KU8_NUMBER_OF_PRODUCTION_CYCLE];

#define SCM_AC_SystemContextManagement_STOP_SEC_CONST_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

#define SCM_AC_SystemContextManagement_START_SEC_CONST_UNSPECIFIED
#include "SCM_AC_SystemContextManagement_MemMap.h"

extern const SCM_stSystemContextType scm_kstDefautSystemContextValue;

#define SCM_AC_SystemContextManagement_STOP_SEC_CONST_UNSPECIFIED
#include "SCM_AC_SystemContextManagement_MemMap.h"

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
#define SCM_AC_SystemContextManagement_START_SEC_CODE
#include "SCM_AC_SystemContextManagement_MemMap.h"

extern void    SCM_GetReleaseInterruptionFlags        ( void );
extern void    SCM_PrepareSystemContextStorage        ( void );
extern void    SCM_RecoverSystemContext               ( void );
extern uint8   SCM_ComputeSystemContextChecksum       ( const SCM_stSystemContextType * const pstSystemContext);
extern void    SCM_StoreSystemContext                 ( void );
extern boolean SCM_CompareSystemContext               ( uint8 );

#define SCM_AC_SystemContextManagement_STOP_SEC_CODE
#include "SCM_AC_SystemContextManagement_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/

#endif /* _SCM_CFG_H_ */

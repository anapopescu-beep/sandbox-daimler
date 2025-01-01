/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_PBCfg.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  RTE Post Build Data Set Configuration Header
 *********************************************************************************************************************/
/* double include prevention */
#ifndef RTE_PBCFG_H
# define RTE_PBCFG_H

typedef struct {
  uint8 variant;
} SchM_ConfigType;

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(SchM_ConfigType, RTE_CONST) Rte_Config_Left;

extern CONST(SchM_ConfigType, RTE_CONST) Rte_Config_Right;


# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* RTE_PBCFG_H */

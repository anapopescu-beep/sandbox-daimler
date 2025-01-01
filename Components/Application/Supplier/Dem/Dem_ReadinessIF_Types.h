/* ********************************************************************************************************************
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
 */
/*! \addtogroup Dem_ReadinessIF
 *  \{
 *  \file       Dem_ReadinessIF_Types.h
 *  \brief      Diagnostic Event Manager (Dem) header file
 *  \details    
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_READINESSIF_TYPES_H)
#define DEM_READINESSIF_TYPES_H

/* ********************************************************************************************************************
 *  GLOBAL MISRA JUSTIFICATIONS
 *********************************************************************************************************************/
/* PRQA S 2880 EOF */ /* MD_DEM_2.1_UNREACHABLE_STATEMENT */
/* PRQA S 2982 EOF */ /* MD_DEM_2982 */
/* PRQA S 2983 EOF */ /* MD_DEM_2983 */
/* PRQA S 2985 EOF */ /* MD_DEM_2985 */
/* PRQA S 2986 EOF */ /* MD_DEM_2986 */
/* PRQA S 2987 EOF */ /* MD_DEM_2987 */
/* PRQA S 2991 EOF */ /* MD_DEM_2991 */
/* PRQA S 2992 EOF */ /* MD_DEM_2992 */
/* PRQA S 2995 EOF */ /* MD_DEM_2995 */
/* PRQA S 2996 EOF */ /* MD_DEM_2996 */
/* PRQA S 3415 EOF */ /* MD_DEM_13.5_cf */

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own unit header */
/* ------------------------------------------------------------------------- */
#include "Dem_Int.h"

/* ********************************************************************************************************************
 *  UNIT CONSTANT MACROS
 *********************************************************************************************************************/
 
 
                                             /* PID01 PID41 PIDF501 Readiness */
 /* ------------------------------------------------------------------------- */

 /*!
 * \defgroup  Dem_Readiness_Initialize  Macros encoding initial values
 * Macros encoding initial values depending on engine type
 * \{
 */
 /*!< Readiness initialization for spark engines */
#define DEM_READINESS_INITIALIZE_UPDATE_SPARK                  ( ((uint32)1 << DEM_CFG_READINESS_CAT ) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_HTCAT) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_EVAP)  \
                                                               | ((uint32)1 << DEM_CFG_READINESS_SECAIR) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_O2SENS) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_O2SENSHT) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_CMPRCMPT) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_EGR) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_FLSYS_NONCONT) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_MISF) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_ECS) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_PMFLT) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_PCV) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_VVT) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_DOR) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_CSER) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_OTHER) )

 /*!< Readiness initialization for compression engines */
#define DEM_READINESS_INITIALIZE_UPDATE_COMPRESSION            ( ((uint32)1 << DEM_CFG_READINESS_HCCAT ) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_NOXCAT) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_BOOSTPR) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_PMFLT) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_EGSENS) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_CMPRCMPT) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_EGR) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_FLSYS_NONCONT) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_MISF) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_ECS) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_PCV) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_VVT) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_DOR) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_CSER) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_NOXADSORB) \
                                                               | ((uint32)1 << DEM_CFG_READINESS_OTHER) )

#define DEM_READINESS_INITIALIZE_PID41COMPLETED_SPARK          (0xFFFFFFEFUL)  /*!< Readiness initialization for spark engines */
#define DEM_READINESS_INITIALIZE_PID41COMPLETED_COMPRESSION    (0xFFFFFFEBUL)  /*!< Readiness initialization for compression engines */
 /*!
 * \}
 */

 /*!
 * \defgroup  Dem_Readiness_Support_State  Macros encoding assignment of readiness group supported state
 * Macros encoding assignment of readiness group supported state to 32-bit mask
 * \{
 */
#define DEM_READINESS_SUPPORT_NONE_MASK               (0x00000000UL)             /*!< Used to initialze local variables */
#define DEM_READINESS_SUPPORT_MISF_MASK               (0x00010000UL)             /*!< Bit encoding for DEM_OBD_RDY_MISF supported state */
#define DEM_READINESS_SUPPORT_FLSYS_MASK              (0x00020000UL)             /*!< Bit encoding for DEM_OBD_RDY_FLSYS and DEM_OBD_RDY_FLSYS_NONCONT supported state */
#define DEM_READINESS_SUPPORT_CMPRCMPT_MASK           (0x00040000UL)             /*!< Bit encoding for DEM_OBD_RDY_CMPRCMPT supported state */
#define DEM_READINESS_SUPPORT_CAT_MASK                (0x00000100UL)             /*!< Bit encoding for DEM_OBD_RDY_CAT supported state */
#define DEM_READINESS_SUPPORT_HCCAT_MASK              (0x00000100UL)             /*!< Bit encoding for DEM_OBD_RDY_HCCAT supported state */
#define DEM_READINESS_SUPPORT_HTCAT_MASK              (0x00000200UL)             /*!< Bit encoding for DEM_OBD_RDY_HTCAT supported state */
#define DEM_READINESS_SUPPORT_NOXCAT_MASK             (0x00000200UL)             /*!< Bit encoding for DEM_OBD_RDY_NOXCAT supported state */
#define DEM_READINESS_SUPPORT_EVAP_MASK               (0x00000400UL)             /*!< Bit encoding for DEM_OBD_RDY_EVAP supported state */
#define DEM_READINESS_SUPPORT_SECAIR_MASK             (0x00000800UL)             /*!< Bit encoding for DEM_OBD_RDY_SECAIR supported state */
#define DEM_READINESS_SUPPORT_BOOSTPR_MASK            (0x00000800UL)             /*!< Bit encoding for DEM_OBD_RDY_BOOSTPR supported state */
#define DEM_READINESS_SUPPORT_O2SENS_MASK             (0x00002000UL)             /*!< Bit encoding for DEM_OBD_RDY_O2SENS supported state */
#define DEM_READINESS_SUPPORT_EGSENS_MASK             (0x00002000UL)             /*!< Bit encoding for DEM_OBD_RDY_EGSENS supported state */
#define DEM_READINESS_SUPPORT_O2SENSHT_MASK           (0x00004000UL)             /*!< Bit encoding for DEM_OBD_RDY_O2SENSHT supported state */
#define DEM_READINESS_SUPPORT_PMFLT_MASK              (0x00004000UL)             /*!< Bit encoding for DEM_OBD_RDY_PMFLT supported state */
#define DEM_READINESS_SUPPORT_EGR_MASK                (0x00008000UL)             /*!< Bit encoding for DEM_OBD_RDY_ERG supported state */
#define DEM_READINESS_SUPPORT_COMPRESSION             (0x00080000UL)             /*!< Bit encoding for engine type compression ignition supported state */
 /*!
 * \}
 */

 /*! Supported Bit Mask for PID41 Byte B */
#define DEM_READINESS_SUPPORT_PID41_BYTE_B_MASK      (DEM_READINESS_SUPPORT_MISF_MASK | DEM_READINESS_SUPPORT_FLSYS_MASK | DEM_READINESS_SUPPORT_CMPRCMPT_MASK)



 /*!
 * \defgroup  Dem_Readiness_Completed_State  Macros encoding assignment of readiness group completed state
 * Macros encoding assignment of readiness group completed state to 32-bit mask
 * \{
 */
#define DEM_READINESS_COMPLETE_MISF_MASK              (0x00100000UL)             /*!< Bit encoding for DEM_OBD_RDY_MISF completed state */
#define DEM_READINESS_COMPLETE_FLSYS_MASK             (0x00200000UL)             /*!< Bit encoding for DEM_OBD_RDY_FLSYS and DEM_OBD_RDY_FLSYS_NONCONT completed state */
#define DEM_READINESS_COMPLETE_CMPRCMPT               (0x00400000UL)             /*!< Bit encoding for DEM_OBD_RDY_CMPRCMPT completed state */
#define DEM_READINESS_COMPLETE_CAT_MASK               (0x00000001UL)             /*!< Bit encoding for DEM_OBD_RDY_CAT completed state */
#define DEM_READINESS_COMPLETE_HCCAT_MASK             (0x00000001UL)             /*!< Bit encoding for DEM_OBD_RDY_HCCAT completed state */
#define DEM_READINESS_COMPLETE_HTCAT_MASK             (0x00000002UL)             /*!< Bit encoding for DEM_OBD_RDY_HTCAT completed state */
#define DEM_READINESS_COMPLETE_NOXCAT_MASK            (0x00000002UL)             /*!< Bit encoding for DEM_OBD_RDY_NOXCAT completed state */
#define DEM_READINESS_COMPLETE_EVAP_MASK              (0x00000004UL)             /*!< Bit encoding for DEM_OBD_RDY_EVAP completed state */
#define DEM_READINESS_COMPLETE_SECAIR_MASK            (0x00000008UL)             /*!< Bit encoding for DEM_OBD_RDY_SECAIR completed state */
#define DEM_READINESS_COMPLETE_BOOSTPR_MASK           (0x00000008UL)             /*!< Bit encoding for DEM_OBD_RDY_BOOSTPR completed state */
#define DEM_READINESS_COMPLETE_O2SENS_MASK            (0x00000020UL)             /*!< Bit encoding for DEM_OBD_RDY_O2SENS completed state */
#define DEM_READINESS_COMPLETE_EGSENS_MASK            (0x00000020UL)             /*!< Bit encoding for DEM_OBD_RDY_EGSENS completed state */
#define DEM_READINESS_COMPLETE_O2SENSHT_MASK          (0x00000040UL)             /*!< Bit encoding for DEM_OBD_RDY_O2SENSHT completed state */
#define DEM_READINESS_COMPLETE_PMFLT_MASK             (0x00000040UL)             /*!< Bit encoding for DEM_OBD_RDY_PMFLT completed state */
#define DEM_READINESS_COMPLETE_EGR_MASK               (0x00000080UL)             /*!< Bit encoding for DEM_OBD_RDY_ERG completed state */
 /*!
 * \}
 */

 /*!
 * \defgroup  Dem_Readiness_DIDF501_Support_State  Macros encoding assignment of readiness group supported state
 * Macros encoding assignment of readiness group supported state to 8-bit mask
 * \{
 */
 /* Byte B */
#define DEM_READINESS_DIDF501_SUPPORT_MISF_MASK               (0x01U)             /*!< Bit encoding for DEM_OBD_RDY_MISF supported state */
#define DEM_READINESS_DIDF501_SUPPORT_FLSYS_MASK              (0x02U)             /*!< Bit encoding for DEM_OBD_RDY_FLSYS and DEM_OBD_RDY_FLSYS_NONCONT supported state */
#define DEM_READINESS_DIDF501_SUPPORT_CMPRCMPT_MASK           (0x04U)             /*!< Bit encoding for DEM_OBD_RDY_CMPRCMPT supported state */
#define DEM_READINESS_DIDF501_SUPPORT_ECS_MASK                (0x08U)             /*!< Bit encoding for DEM_OBD_RDY_ECS supported state */
 /* Byte C */
#define DEM_READINESS_DIDF501_SUPPORT_CAT_MASK                (0x01U)             /*!< Bit encoding for DEM_OBD_RDY_CAT supported state */
#define DEM_READINESS_DIDF501_SUPPORT_HCCAT_MASK              (0x02U)             /*!< Bit encoding for DEM_OBD_RDY_HCCAT supported state */
#define DEM_READINESS_DIDF501_SUPPORT_HTCAT_MASK              (0x04U)             /*!< Bit encoding for DEM_OBD_RDY_HTCAT supported state */
#define DEM_READINESS_DIDF501_SUPPORT_NOXCAT_MASK             (0x08U)             /*!< Bit encoding for DEM_OBD_RDY_NOXCAT supported state */
 /* Byte D */
#define DEM_READINESS_DIDF501_SUPPORT_EVAP_MASK               (0x01U)             /*!< Bit encoding for DEM_OBD_RDY_EVAP supported state */
#define DEM_READINESS_DIDF501_SUPPORT_SECAIR_MASK             (0x02U)             /*!< Bit encoding for DEM_OBD_RDY_SECAIR supported state */
#define DEM_READINESS_DIDF501_SUPPORT_BOOSTPR_MASK            (0x04U)             /*!< Bit encoding for DEM_OBD_RDY_BOOSTPR supported state */
#define DEM_READINESS_DIDF501_SUPPORT_PMFLT_MASK              (0x08U)             /*!< Bit encoding for DEM_OBD_RDY_PMFLT supported state */
 /* Byte E */
#define DEM_READINESS_DIDF501_SUPPORT_EGSENS_MASK             (0x01U)             /*!< Bit encoding for DEM_OBD_RDY_EGSENS supported state */
#define DEM_READINESS_DIDF501_SUPPORT_PCV_MASK                (0x02U)             /*!< Bit encoding for DEM_OBD_RDY_PCV supported state */
#define DEM_READINESS_DIDF501_SUPPORT_EGR_MASK                (0x04U)             /*!< Bit encoding for DEM_OBD_RDY_EGR supported state */
#define DEM_READINESS_DIDF501_SUPPORT_VVT_MASK                (0x08U)             /*!< Bit encoding for DEM_OBD_RDY_VVT supported state */
 /* Byte F */
#define DEM_READINESS_DIDF501_SUPPORT_DOR_MASK                (0x01U)             /*!< Bit encoding for DEM_OBD_RDY_DOR supported state */
#define DEM_READINESS_DIDF501_SUPPORT_CSER_MASK               (0x02U)             /*!< Bit encoding for DEM_OBD_RDY_CSER supported state */
#define DEM_READINESS_DIDF501_SUPPORT_NOXADSORB_MASK          (0x04U)             /*!< Bit encoding for DEM_OBD_RDY_NOXADSORB supported state */
#define DEM_READINESS_DIDF501_SUPPORT_OTHER_MASK              (0x08U)             /*!< Bit encoding for DEM_OBD_RDY_OTHER supported state */
 /*!
 * \}
 */

 /*!
 * \defgroup  Dem_Readiness_Support_State Macros map readiness group to DIDF501 byte
 * Macros encoding mapping of readiness group to DIDF501 byte
 * \{
 */
 /* Byte B */
#define DEM_READINESS_DIDF501_MISF_BYTE               (0x01U)             /*!< Bit encoding for DEM_OBD_RDY_MISF supported state */
#define DEM_READINESS_DIDF501_FLSYS_BYTE              (0x01U)             /*!< Bit encoding for DEM_OBD_RDY_FLSYS and DEM_OBD_RDY_FLSYS_NONCONT supported state */
#define DEM_READINESS_DIDF501_CMPRCMPT_BYTE           (0x01U)             /*!< Bit encoding for DEM_OBD_RDY_CMPRCMPT supported state */
#define DEM_READINESS_DIDF501_ECS_BYTE                (0x01U)             /*!< Bit encoding for DEM_OBD_RDY_ECS supported state */
 /* Byte C */
#define DEM_READINESS_DIDF501_CAT_BYTE                (0x02U)             /*!< Bit encoding for DEM_OBD_RDY_CAT supported state */
#define DEM_READINESS_DIDF501_HCCAT_BYTE              (0x02U)             /*!< Bit encoding for DEM_OBD_RDY_HCCAT supported state */
#define DEM_READINESS_DIDF501_HTCAT_BYTE              (0x02U)             /*!< Bit encoding for DEM_OBD_RDY_HTCAT supported state */
#define DEM_READINESS_DIDF501_NOXCAT_BYTE             (0x02U)             /*!< Bit encoding for DEM_OBD_RDY_NOXCAT supported state */
 /* Byte D */
#define DEM_READINESS_DIDF501_EVAP_BYTE               (0x03U)             /*!< Bit encoding for DEM_OBD_RDY_EVAP supported state */
#define DEM_READINESS_DIDF501_SECAIR_BYTE             (0x03U)             /*!< Bit encoding for DEM_OBD_RDY_SECAIR supported state */
#define DEM_READINESS_DIDF501_BOOSTPR_BYTE            (0x03U)             /*!< Bit encoding for DEM_OBD_RDY_BOOSTPR supported state */
#define DEM_READINESS_DIDF501_PMFLT_BYTE              (0x03U)             /*!< Bit encoding for DEM_OBD_RDY_PMFLT supported state */
 /* Byte E */
#define DEM_READINESS_DIDF501_EGSENS_BYTE             (0x04U)             /*!< Bit encoding for DEM_OBD_RDY_EGSENS supported state */
#define DEM_READINESS_DIDF501_PCV_BYTE                (0x04U)             /*!< Bit encoding for DEM_OBD_RDY_PCV supported state */
#define DEM_READINESS_DIDF501_EGR_BYTE                (0x04U)             /*!< Bit encoding for DEM_OBD_RDY_EGR supported state */
#define DEM_READINESS_DIDF501_VVT_BYTE                (0x04U)             /*!< Bit encoding for DEM_OBD_RDY_VVT supported state */
 /* Byte F */
#define DEM_READINESS_DIDF501_DOR_BYTE                (0x05U)             /*!< Bit encoding for DEM_OBD_RDY_DOR supported state */
#define DEM_READINESS_DIDF501_CSER_BYTE               (0x05U)             /*!< Bit encoding for DEM_OBD_RDY_CSER supported state */
#define DEM_READINESS_DIDF501_NOXADSORB_BYTE          (0x05U)             /*!< Bit encoding for DEM_OBD_RDY_NOXADSORB supported state */
#define DEM_READINESS_DIDF501_OTHER_BYTE              (0x05U)             /*!< Bit encoding for DEM_OBD_RDY_OTHER supported state */
 /*!
 * \}
 */

 /*!
 * \defgroup  Dem_Readiness_Disabled_State  Macros encoding assignment of readiness group disabled state
 * Macros encoding assignment of readiness group disabled state to 16-bit mask
 * \{
 */
#define DEM_READINESS_DISABLED_NONE_MASK               (0x0000U)             /*!< Used to initialze local variables */
#define DEM_READINESS_DISABLED_MISF_MASK               (0x0001U)             /*!< Bit encoding for DEM_OBD_RDY_MISF disabled state */
#define DEM_READINESS_DISABLED_FLSYS_MASK              (0x0002U)             /*!< Bit encoding for DEM_OBD_RDY_FLSYS and DEM_OBD_RDY_FLSYS_NONCONT disabled state */
#define DEM_READINESS_DISABLED_CMPRCMPT                (0x0004U)             /*!< Bit encoding for DEM_OBD_RDY_CMPRCMPT disabled state */
#define DEM_READINESS_DISABLED_CAT_MASK                (0x0008U)             /*!< Bit encoding for DEM_OBD_RDY_CAT disabled state */
#define DEM_READINESS_DISABLED_HCCAT_MASK              (0x0010U)             /*!< Bit encoding for DEM_OBD_RDY_HCCAT disabled state */
#define DEM_READINESS_DISABLED_HTCAT_MASK              (0x0020U)             /*!< Bit encoding for DEM_OBD_RDY_HTCAT disabled state */
#define DEM_READINESS_DISABLED_NOXCAT_MASK             (0x0040U)             /*!< Bit encoding for DEM_OBD_RDY_NOXCAT disabled state */
#define DEM_READINESS_DISABLED_EVAP_MASK               (0x0080U)             /*!< Bit encoding for DEM_OBD_RDY_EVAP disabled state */
#define DEM_READINESS_DISABLED_SECAIR_MASK             (0x0100U)             /*!< Bit encoding for DEM_OBD_RDY_SECAIR disabled state */
#define DEM_READINESS_DISABLED_BOOSTPR_MASK            (0x0200U)             /*!< Bit encoding for DEM_OBD_RDY_BOOSTPR disabled state */
#define DEM_READINESS_DISABLED_O2SENS_MASK             (0x0400U)             /*!< Bit encoding for DEM_OBD_RDY_O2SENS disabled state */
#define DEM_READINESS_DISABLED_EGSENS_MASK             (0x0800U)             /*!< Bit encoding for DEM_OBD_RDY_EGSENS disabled state */
#define DEM_READINESS_DISABLED_O2SENSHT_MASK           (0x1000U)             /*!< Bit encoding for DEM_OBD_RDY_O2SENSHT disabled state */
#define DEM_READINESS_DISABLED_PMFLT_MASK              (0x2000U)             /*!< Bit encoding for DEM_OBD_RDY_PMFLT disabled state */
#define DEM_READINESS_DISABLED_EGR_MASK                (0x4000U)             /*!< Bit encoding for DEM_OBD_RDY_ERG disabled state */
#define DEM_READINESS_DISABLED_COMPRESSION             (0x8000U)             /*!< Bit encoding for engine type compression ignition disabled state */
 /*!
 * \}
 */

 
 /*! Array Size of a PID F501 Data Block */
#define DEM_READINESS_PIDF501_SIZE              (6u)   

 /*! Word size for SetBitInBitfield operations. Calculated by ceil(DEM_CFG_READINESS_GROUP_SIZE/32u)*/
#define DEM_CFG_READINESS_GROUP_WORDSIZE        (1u)   

 /* ********************************************************************************************************************
 *  UNIT FUNCTION MACROS
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  UNIT DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#endif /* DEM_READINESSIF_TYPES_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_ReadinessIF_Types.h
 *********************************************************************************************************************/

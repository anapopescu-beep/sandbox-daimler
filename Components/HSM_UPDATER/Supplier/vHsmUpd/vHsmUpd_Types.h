/***********************************************************************************************************************
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
/*!        \file  vHsmUpd_Types.h
 *        \brief  vHsmUpd types header file
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 **********************************************************************************************************************/

#if !defined (VHSMUPD_TYPES_H)
# define VHSMUPD_TYPES_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
# include "Std_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
#ifndef VHSMUPD_ADDRESS_AREA_OF_HOST                        /* COV_VHSMUPD_COMPATIBILITY */
# define VHSMUPD_ADDRESS_AREA_OF_HOST                 (0u)  /* Fixed value for address area of host since we always access through direct pointer */
#endif /* VHSMUPD_ADDRESS_AREA_OF_HOST */

# define VHSMUPD_SIZE_OF_PP                           (4u)  /*!< Size of the presence pattern for validity checks */

/* Vendor and module identification */
# define VHSMUPD_VENDOR_ID                            (30u)
# define VHSMUPD_MODULE_ID                            (0xFFu)

# define VHSMUPD_UPDATE_NOT_STARTED                   (0x1u)
# define VHSMUPD_UPDATE_IN_PROGRESS                   (0x2u)
# define VHSMUPD_UPDATE_COMPLETED                     (0x3u)

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
typedef P2VAR(uint8, AUTOMATIC, VHSMUPD_APPL_VAR) vHsmUpd_DataPtrType;
typedef P2CONST(uint8, AUTOMATIC, VHSMUPD_APPL_CONST) vHsmUpd_ConstDataPtrType;
typedef P2VAR(uint32, AUTOMATIC, VHSMUPD_APPL_VAR) vHsmUpd_LengthPtrType;
typedef P2VAR(uint32, AUTOMATIC, VHSMUPD_APPL_VAR) vHsmUpd_AddressPtrType;
typedef P2VAR(boolean, AUTOMATIC, VHSMUPD_APPL_VAR) vHsmUpdBooleanResultPtrType;

typedef uint32 vHsmUpd_OffsetType;
typedef uint32 vHsmUpd_AddressType;
typedef uint32 vHsmUpd_LengthType;
typedef uint32 vHsmUpd_MemoryAreaIdType;

/* Some function calls need to differentiate between HSM or Application core via this enum */
typedef enum {
  TARGET_HSM,
  TARGET_HOST
} vHsmUpd_TargetCoreType;

#endif  /* VHSMUPD_TYPES_H */

/***********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Types.h
 **********************************************************************************************************************/

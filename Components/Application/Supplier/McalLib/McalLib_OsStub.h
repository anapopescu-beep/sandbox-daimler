/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  McalLib_OsStub.h
 *        \brief  Example for callouts required by the Infineon 3rd party MCAL.
 *
 *      \details  It uses BRS/OS APIs to write special registers (e.g. protected registers).
 *
 *  \attention    Please note:
 *                The demo and example programs only show special aspects of the software. With regard to the fact
 *                that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *                expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  TODO                          virrro        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2020-01-01  virrro n/a            Initial version
 *  01.01.00  2022-07-11  virrro n/a            Added implementation of MCAL_LIB_WRITEPERIPENDINITPROTREG
 *********************************************************************************************************************/
#ifndef APPL_INCLUDEHW_MCALLIB_OSSTUB_H_
#define APPL_INCLUDEHW_MCALLIB_OSSTUB_H_

#include "Os.h"

extern void Appl_UnlockEndinit(void);
extern void Appl_LockEndinit(void);

/*
 * This call requires a peripheral region "OsPeripheralRegion_MCAL" in the OS configuration.
 */
#define MCAL_SFR_OS_WRITE32(Area, Address, Data) \
  Os_WritePeripheral32(OsPeripheralRegion_MCAL, (uint32*)Address, Data)

#define MCAL_LIB_WRITECPUENDINITPROTREG(Address, SetMask) \
  Appl_UnlockEndinit()

/*
 * This call requires a peripheral region "OsPeripheralRegion_MCAL" in the OS configuration.
 */
#define MCAL_LIB_WRITEPERIPENDINITPROTREG(RegAddress, DataValue) \
  Appl_UnlockEndinit(); \
  Os_WritePeripheral32(OsPeripheralRegion_MCAL, (uint32*)RegAddress, DataValue); \
  Appl_LockEndinit();

#endif /* APPL_INCLUDEHW_MCALLIB_OSSTUB_H_ */
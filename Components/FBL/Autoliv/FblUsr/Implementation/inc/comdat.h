/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Definition of common data structures which are shared between
 *                 bootloader and application software
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *
 *  \par Note
 *  \verbatim
 *  Please note, that this file contains a collection of callback functions to be used with the Flash Bootloader. 
 *  These functions may influence the behaviour of the bootloader in principle. 
 *  Therefore, great care must be taken to verify the correctness of the implementation.
 * 
 *  The contents of the originally delivered files are only examples resp. implementation proposals. 
 *  With regard to the fact that these functions are meant for demonstration purposes only, Vector Informatik´s 
 *  liability shall be expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute. 
 *  \endverbatim  
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Christian Baeuerle            CB            Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2017-06-13  viscb                    Initial Version for Daimler SLP11 
 *  02.00.01   2022-06-15  viscb   ESCAN00112002    Standard bootloader software information (0xEF02) with 16 bytes
 **********************************************************************************************************************/

#ifndef __COMDAT_H__
#define __COMDAT_H__

/*
   The following typedefs avoid the usage of Vector types (e.g. vuint8) so
   they can be easily re-used in the application software.
 */

/* Type definition for process information values */
typedef unsigned char tFblHardwareVersion[3];
typedef unsigned char tFblHardwareSupplierInformation[2];
typedef unsigned char tFblSoftwareSupplierInformation[2];
typedef unsigned char tFblBootSoftwareSupplierInformation[2];
typedef unsigned char tFblHardwarePartNumber[10];
typedef unsigned char tFblBootSoftwareVersion[3];
typedef unsigned char tFblAppSoftwareVersion[3];
typedef unsigned char tFblBootSoftwarePartNumber[10];
typedef unsigned char tFblAppSoftwarePartNumber[10];
typedef unsigned char tFblActiveDiagnosticInformation[3];
typedef unsigned char tMinSoftwareVersion[3];

typedef struct
{
   unsigned char  ApplicationSoftware[2];
   unsigned char  BootSoftware[2];

}tDDSPackageReleaseInformation;

typedef struct
{
   unsigned char  Version[3];
   unsigned char  Build;
   unsigned char  uCIdentification[10];

}tFblStandardBootloaderSoftwareInformation;


typedef struct tagFblCommonData
{
   /* F150 - Hardware Version Information */
   tFblHardwareVersion                          EcuHardwareVersion;

   /* F154 - Hardware Supplier Identification */
   tFblHardwareSupplierInformation              EcuHardwareSupplierInformation;

      /* F155 - Boot Software Supplier Identification*/
   tFblBootSoftwareSupplierInformation          EcuBootSoftwareSupplierInformation;

   /* F155 - Software Supplier Identification*/
   tFblSoftwareSupplierInformation              EcuAppSoftwareSupplierInformation;


   /* F111 - Hardware Part Number */
   tFblHardwarePartNumber                       EcuHardwarePartNumber;

   /* F121 Application Software Part Numbers*/
   tFblAppSoftwarePartNumber                    EcuAppSoftwarePartNumber;

   /* F121 Boot Software Part Numbers*/
   tFblBootSoftwarePartNumber                   EcuBootSoftwarePartNumber;

   /* F151 Application Software Version Information*/
   tFblAppSoftwareVersion                       EcuAppSoftwareVersion;

   /* F153 Boot Software Version Information*/
   tFblBootSoftwareVersion                      EcuBootSoftwareVersion;

   /* EF02 - Bootloader Software Information */
   tFblStandardBootloaderSoftwareInformation    StandardBootloaderSoftwareInformation;

   /* EF05 - Minimum Software Version   */
   tMinSoftwareVersion                          MinimumSoftwareVersion;

   /* F10D - DDS Package Release Information*/
   tDDSPackageReleaseInformation                DDSPackageReleaseInformation;

   /* F100 - Active Diagnostic Information*/
   tFblActiveDiagnosticInformation              ActiveDiagnosticInformation;

   /* F104 - ECU Name */
   V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3 *       EcuName;
} tFblCommonData;

#if defined( VGEN_ENABLE_CANFBL )
#else
/** Common data access macro for usage in the application software */
# define fblCommonData   (*((V_MEMROM1_FAR tFblCommonData V_MEMROM2_FAR *)GetFblCommonDataPtr()))
#endif

#endif /* __COMDAT_H__ */

/***********************************************************************************************************************
 *  END OF FILE: _COMDAT.H
 **********************************************************************************************************************/

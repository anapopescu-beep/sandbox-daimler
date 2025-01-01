/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 - 2017 by Vector Informatik GmbH.                                           All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples respectively
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, the liability of Vector Informatik
 *                shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defined for all BSW modules
 *                which are used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik GmbH
 *  Heike Honert                  Ht            Vector Informatik GmbH
 *  Eugen Stripling               Seu           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component specific defines filtering added
 *  01.01.02  2008-11-04  Jk                    Component specific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all OEMs
 *                                              rename internal variables and filter methods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-15  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-20  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-11-22  Ht                    add If_AsrIfFeeTiSub, 
 *                                              ESCAN00054718: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                    add If_AsrIfFeeMb9df126Fuji01Sub, 
 *                                              Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                    add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                              Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                    add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                    ESCAN00059365: [AUTOSAR4, compiler warning]: Wrong define name in #undef statement causes re-definition warning
 *                                              add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                  Ccl_Asr4SmLin 
 *            2012-09-04  Ht                    add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                   add SysService_XmlSecurity
 *  01.07.02  2013-01-10  Seu                   MISRA deviation comments added
 *  01.08.00  2013-03-01  Seu    ESCAN00065501  AR4-325: Add support for Post-build RAM memory section
 *            2013-04-12  Seu    ESCAN00066614  Add the deviation for violation of MISRA rule 19.6
 *  01.09.00  2013-12-10  Seu    ESCAN00072537  Add *_NOCACHE_* memory sections for variables
 *            2013-12-16  Seu                   MISRA compliance: usage of character "'" removed, typos corrected
 *  01.10.00  2016-09-27  Seu                   FEATC-317: FEAT-2002: CommonAsr__Common: Support 64 Bit Signal Types for COM according to ASR 4.2.2
 *  01.11.00  2017-07-05  Seu    ESCAN00095756  FEAT-2455: Support ASR4.2 compatible MemMap for MCALs
 *            2017-08-01  Seu    ESCAN00096129  MEMMAP_SW_MINOR_VERSION / MEM_SW_MINOR_VERSION is not correct
 *********************************************************************************************************************/

/* PRQA S 0841 MEMMAP_0841_TAG */ /* MD_MSR_19.6 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 /* PRQA S 0883 1 */ /* MD_MemMap_19.15 */
#undef MEMMAP_VENDOR_ID /* PRQA S 0841 */ /* MD_MSR_19.6 */

#define MEMMAP_VENDOR_ID        (30u)

/* AUTOSAR Software Specification Version Information */


# undef MEMMAP_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_REVISION_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

/* AUTOSAR release 4.0 R3 */
# define MEMMAP_AR_RELEASE_MAJOR_VERSION       (4u)
# define MEMMAP_AR_RELEASE_MINOR_VERSION       (0u)
# define MEMMAP_AR_RELEASE_REVISION_VERSION    (3u)

/* compatiblity to older versions */
# undef MEM_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_AR_RELEASE_MAJOR_VERSION          MEMMAP_AR_RELEASE_MAJOR_VERSION
# define MEM_AR_RELEASE_MINOR_VERSION          MEMMAP_AR_RELEASE_MINOR_VERSION
# define MEM_AR_RELEASE_PATCH_VERSION          MEMMAP_AR_RELEASE_REVISION_VERSION


# undef MEMMAP_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEMMAP_SW_MAJOR_VERSION     (1u)
# define MEMMAP_SW_MINOR_VERSION     (11u)
# define MEMMAP_SW_PATCH_VERSION     (0u)

/* compatiblity to older versions */
# undef MEM_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_SW_MAJOR_VERSION        MEMMAP_SW_MAJOR_VERSION 
# define MEM_SW_MINOR_VERSION        MEMMAP_SW_MINOR_VERSION 
# define MEM_SW_PATCH_VERSION        MEMMAP_SW_PATCH_VERSION 
  
#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */




/**********************************************************************************************************************
 *  DrvAdc_VttCanoe01Asr START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

/*******  CONST sections  ********************************************************************************************/

/*******  VAR sections  **********************************************************************************************/


/**********************************************************************************************************************
 *  DrvAdc_VttCanoe01Asr END
 *********************************************************************************************************************/

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/*        STARTSINGLE_OF_MULTIPLE_COMMENT      */


/**********************************************************************************************************************
 *  Can START  DRVCAN_CANOEEMUCANOEASR
 *********************************************************************************************************************/

#if defined (CAN_REMAP_PB_SECTIONS)        /* PRQA S 0883 */ /* Appears only while testing */
/* for none PB variants the code will be mapped to standard sections, so the generated and static code can ignore the variant handling */
# if defined (CAN_START_SEC_PBCFG)
#  undef CAN_START_SEC_PBCFG                /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_START_SEC_CONST_UNSPECIFIED
# endif
# if defined (CAN_STOP_SEC_PBCFG)
#  undef CAN_STOP_SEC_PBCFG                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_STOP_SEC_CONST_UNSPECIFIED
# endif

# if defined (CAN_START_SEC_VAR_PBCFG)
#  undef CAN_START_SEC_VAR_PBCFG            /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
# endif
# if defined (CAN_STOP_SEC_VAR_PBCFG)
#  undef CAN_STOP_SEC_VAR_PBCFG             /* PRQA S 0841 */ /* MD_MSR_19.6 */
#  define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# endif
#endif

/*******  CODE sections **********************************************************************************************/

#ifdef CAN_START_SEC_CODE                             /* CAN code */
# undef CAN_START_SEC_CODE                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                               /* mapped to default code section */
#endif
#ifdef CAN_STOP_SEC_CODE
# undef CAN_STOP_SEC_CODE                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

#ifdef CAN_START_SEC_STATIC_CODE                      /* CAN static code */
# undef CAN_START_SEC_STATIC_CODE                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                               /* mapped to default code section */
#endif
#ifdef CAN_STOP_SEC_STATIC_CODE
# undef CAN_STOP_SEC_STATIC_CODE                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

#ifdef CAN_START_SEC_CODE_APPL                        /* Appl code (generic precopy)*/
# undef CAN_START_SEC_CODE_APPL                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                               /* mapped to default code section */
#endif
#ifdef CAN_STOP_SEC_CODE_APPL
# undef CAN_STOP_SEC_CODE_APPL                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CAN_START_SEC_CONST_8BIT                       /* Const 8bit */
# undef CAN_START_SEC_CONST_8BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                         /* mapped to default const 8bit section */
#endif
#ifdef CAN_STOP_SEC_CONST_8BIT
# undef CAN_STOP_SEC_CONST_8BIT                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_CONST_16BIT                      /* Const 16bit */
# undef CAN_START_SEC_CONST_16BIT                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT                        /* mapped to default const 16bit section */
#endif
#ifdef CAN_STOP_SEC_CONST_16BIT
# undef CAN_STOP_SEC_CONST_16BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_CONST_32BIT                      /* Const 32bit */
# undef CAN_START_SEC_CONST_32BIT                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT                        /* mapped to default const 32bit section */
#endif
#ifdef CAN_STOP_SEC_CONST_32BIT
# undef CAN_STOP_SEC_CONST_32BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_CONST_UNSPECIFIED                /* Const unspecified */
# undef CAN_START_SEC_CONST_UNSPECIFIED                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                  /* mapped to default const unspec section */
#endif
#ifdef CAN_STOP_SEC_CONST_UNSPECIFIED
# undef CAN_STOP_SEC_CONST_UNSPECIFIED                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */
/* unused */

/* Postbuild CFG CONST sections */

/* Root table for postbuild data (not relevant for CFG5 AutoSar4.0.3) */
#ifdef CAN_START_SEC_PBCFG_ROOT                       /* Generated Postbuild Root Table */
# undef CAN_START_SEC_PBCFG_ROOT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                        /* mapped to default const postbuild section */
#endif
#ifdef CAN_STOP_SEC_PBCFG_ROOT
# undef CAN_STOP_SEC_PBCFG_ROOT                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef CAN_START_SEC_PBCFG                            /* Generated Postbuild */
# undef CAN_START_SEC_PBCFG                             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                        /* mapped to default const postbuild section */
#endif
#ifdef CAN_STOP_SEC_PBCFG
# undef CAN_STOP_SEC_PBCFG                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef CAN_START_SEC_VAR_INIT_UNSPECIFIED             /* init RAM*/
# undef CAN_START_SEC_VAR_INIT_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED               /* mapped to default init var section */
#endif
#ifdef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef CAN_STOP_SEC_VAR_INIT_UNSPECIFIED               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef CAN_START_SEC_VAR_NOINIT_UNSPECIFIED           /* uninit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_START_SEC_VAR_NOINIT_8BIT                  /* uninit 8bit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_8BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_8BIT
# undef CAN_STOP_SEC_VAR_NOINIT_8BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_START_SEC_VAR_NOINIT_16BIT                  /* uninit 16bit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_16BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_16BIT
# undef CAN_STOP_SEC_VAR_NOINIT_16BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef CAN_START_SEC_VAR_NOINIT_32BIT                  /* uninit 32bit RAM*/
# undef CAN_START_SEC_VAR_NOINIT_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_NOINIT_32BIT
# undef CAN_STOP_SEC_VAR_NOINIT_32BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR PBCFG sections */

#ifdef CAN_START_SEC_VAR_PBCFG           /* Generated Postbuild RAM*/
# undef CAN_START_SEC_VAR_PBCFG            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG             /* mapped to default uninit var section */
#endif
#ifdef CAN_STOP_SEC_VAR_PBCFG
# undef CAN_STOP_SEC_VAR_PBCFG             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
/* unused */

/* VAR FAST INIT sections */
/* unused */

/* VAR FAST NOINIT sections */
/* unused */

/* VAR FAST ZERO INIT sections */
/* unused */

/**********************************************************************************************************************
 *  Can END    DRVCAN_CANOEEMUCANOEASR
 *********************************************************************************************************************/

/*  STOPSINGLE_OF_MULTIPLE_COMMENT  */
/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */

/* Kernbauer Version: 1.14 Konfiguration: DrvCAN Erzeugungsgangnummer: 955 */


/**********************************************************************************************************************
 *  CRYPTO_30_VTT START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CRYPTO_30_VTT_START_SEC_CODE
# undef CRYPTO_30_VTT_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef CRYPTO_30_VTT_STOP_SEC_CODE
# undef CRYPTO_30_VTT_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef CRYPTO_30_VTT_START_SEC_APPL_CODE
# undef CRYPTO_30_VTT_START_SEC_APPL_CODE                    /* mapped to default code section */
# define START_SEC_CODE
#endif
#ifdef CRYPTO_30_VTT_STOP_SEC_APPL_CODE
# undef CRYPTO_30_VTT_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CRYPTO_30_VTT_START_SEC_CONST_UNSPECIFIED
# undef CRYPTO_30_VTT_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYPTO_30_VTT_STOP_SEC_CONST_UNSPECIFIED
# undef CRYPTO_30_VTT_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_30_VTT_START_SEC_CONST_8BIT
# undef CRYPTO_30_VTT_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif

#ifdef CRYPTO_30_VTT_STOP_SEC_CONST_8BIT
# undef CRYPTO_30_VTT_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef CRYPTO_30_VTT_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_30_VTT_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef CRYPTO_30_VTT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_30_VTT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


#ifdef CRYPTO_30_VTT_START_SEC_VAR_NOINIT_8BIT
# undef CRYPTO_30_VTT_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef CRYPTO_30_VTT_STOP_SEC_VAR_NOINIT_8BIT
# undef CRYPTO_30_VTT_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef CRYPTO_30_VTT_START_SEC_VAR_NOINIT_16BIT
# undef CRYPTO_30_VTT_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef CRYPTO_30_VTT_STOP_SEC_VAR_NOINIT_16BIT
# undef CRYPTO_30_VTT_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef CRYPTO_30_VTT_START_SEC_VAR_NOINIT_32BIT
# undef CRYPTO_30_VTT_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef CRYPTO_30_VTT_STOP_SEC_VAR_NOINIT_32BIT
# undef CRYPTO_30_VTT_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef CRYPTO_30_VTT_START_SEC_VAR_ZERO_INIT_8BIT
# undef CRYPTO_30_VTT_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CRYPTO_30_VTT_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CRYPTO_30_VTT_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  CRYPTO_30_VTT END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  DrvDio_VttCanoe01Asr START 
 **********************************************************************************************************************/

/*******  CODE sections ***********************************************************************************************/

/*******  CONST sections  *********************************************************************************************/

/*******  VAR sections  ***********************************************************************************************/


/**********************************************************************************************************************
 *  DrvDio_VttCanoe01Asr END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  DrvEep_VttCanoe01Asr START 
 **********************************************************************************************************************/

/*******  CODE sections ***********************************************************************************************/
#ifdef EEP_START_SEC_CODE
# undef EEP_START_SEC_CODE
# define START_SEC_CODE
#endif

#ifdef EEP_STOP_SEC_CODE
# undef EEP_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/*******  CONST sections  *********************************************************************************************/

/*******  VAR sections  ***********************************************************************************************/


/**********************************************************************************************************************
 *  DrvEep_VttCanoe01Asr END
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETH_30_VTT START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined ETH_30_VTT_START_SEC_CODE
  #undef ETH_30_VTT_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#if defined ETH_30_VTT_STOP_SEC_CODE
  #undef ETH_30_VTT_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#if defined ETH_30_VTT_START_SEC_CODE_ISR
  #undef ETH_30_VTT_START_SEC_CODE_ISR
  #define START_SEC_CODE_ISR                        /* mapped to default ISR code section */
#endif
#if defined ETH_30_VTT_STOP_SEC_CODE_ISR
  #undef ETH_30_VTT_STOP_SEC_CODE_ISR
  #define STOP_SEC_CODE_ISR                             /* default code stop section */
#endif

#if defined ETH_30_VTT_START_SEC_APPL_CODE
  #undef ETH_30_VTT_START_SEC_APPL_CODE
  #define START_SEC_APPL_CODE                        /* mapped to default APPL code section */
#endif
#if defined ETH_30_VTT_STOP_SEC_APPL_CODE
  #undef ETH_30_VTT_STOP_SEC_APPL_CODE
  #define STOP_SEC_APPL_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#if defined ETH_30_VTT_START_SEC_CONST_8BIT
# undef ETH_30_VTT_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#if defined ETH_30_VTT_STOP_SEC_CONST_8BIT
# undef ETH_30_VTT_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#if defined ETH_30_VTT_START_SEC_CONST_16BIT
# undef ETH_30_VTT_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#if defined ETH_30_VTT_STOP_SEC_CONST_16BIT
# undef ETH_30_VTT_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#if defined ETH_30_VTT_START_SEC_CONST_32BIT
# undef ETH_30_VTT_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#if defined ETH_30_VTT_STOP_SEC_CONST_32BIT
# undef ETH_30_VTT_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#if defined ETH_30_VTT_START_SEC_CONST_UNSPECIFIED
# undef ETH_30_VTT_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined ETH_30_VTT_STOP_SEC_CONST_UNSPECIFIED
# undef ETH_30_VTT_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#if defined ETH_30_VTT_START_SEC_PBCFG
# undef ETH_30_VTT_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#if defined ETH_30_VTT_STOP_SEC_PBCFG
# undef ETH_30_VTT_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#if defined ETH_30_VTT_START_SEC_PBCFG_ROOT
# undef ETH_30_VTT_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#if defined ETH_30_VTT_STOP_SEC_PBCFG_ROOT
# undef ETH_30_VTT_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#if defined ETH_30_VTT_START_SEC_VAR_NOINIT_BOOLEAN
# undef ETH_30_VTT_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_BOOLEAN
#endif
#if defined ETH_30_VTT_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef ETH_30_VTT_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#if defined ETH_30_VTT_START_SEC_VAR_NOINIT_8BIT
# undef ETH_30_VTT_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined ETH_30_VTT_STOP_SEC_VAR_NOINIT_8BIT
# undef ETH_30_VTT_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_VTT_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETH_30_VTT_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETH_30_VTT_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETH_30_VTT_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#if defined ETH_30_VTT_START_SEC_VAR_NOINIT_16BIT
# undef ETH_30_VTT_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined ETH_30_VTT_STOP_SEC_VAR_NOINIT_16BIT
# undef ETH_30_VTT_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined ETH_30_VTT_START_SEC_VAR_NOINIT_32BIT
# undef ETH_30_VTT_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined ETH_30_VTT_STOP_SEC_VAR_NOINIT_32BIT
# undef ETH_30_VTT_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined ETH_30_VTT_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETH_30_VTT_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined ETH_30_VTT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETH_30_VTT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_VTT_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETH_30_VTT_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETH_30_VTT_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETH_30_VTT_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#if defined ETH_30_VTT_START_SEC_VAR_NOINIT_DESCRIPTOR
# undef ETH_30_VTT_START_SEC_VAR_NOINIT_DESCRIPTOR

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  error "For Integrator: This section must be aligned to a 64 BYTES border!"
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=".EthDesc"
   */
# endif

# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined ETH_30_VTT_STOP_SEC_VAR_NOINIT_DESCRIPTOR
# undef ETH_30_VTT_STOP_SEC_VAR_NOINIT_DESCRIPTOR

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  error "For Integrator: This section must be aligned to a 64 BYTES border!"
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=default
   */
# endif

# define STOP_SEC_VAR
# endif

#if defined ETH_30_VTT_START_SEC_VAR_NOINIT_BUFFER
# undef ETH_30_VTT_START_SEC_VAR_NOINIT_BUFFER

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  error "For Integrator: This section must be aligned to a 64 BYTES border!"
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=".EthBuffers"
   */
# endif

# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined ETH_30_VTT_STOP_SEC_VAR_NOINIT_BUFFER
# undef ETH_30_VTT_STOP_SEC_VAR_NOINIT_BUFFER

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  error "For Integrator: This section must be aligned to a 64 BYTES border!"
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=default
   */
# endif

# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  ETH_30_VTT END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  ETH START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETH_START_SEC_CODE
  #undef ETH_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ETH_STOP_SEC_CODE
  #undef ETH_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef ETH_START_SEC_CODE_ISR
  #undef ETH_START_SEC_CODE_ISR                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE_ISR                        /* mapped to default ISR code section */
#endif
#ifdef ETH_STOP_SEC_CODE_ISR
  #undef ETH_STOP_SEC_CODE_ISR                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#if defined ETH_START_SEC_CONST_8BIT
# undef ETH_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#if defined ETH_STOP_SEC_CONST_8BIT
# undef ETH_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#if defined ETH_START_SEC_CONST_16BIT
# undef ETH_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#if defined ETH_STOP_SEC_CONST_16BIT
# undef ETH_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#if defined ETH_START_SEC_CONST_32BIT
# undef ETH_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#if defined ETH_STOP_SEC_CONST_32BIT
# undef ETH_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#if defined ETH_START_SEC_CONST_UNSPECIFIED
# undef ETH_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined ETH_STOP_SEC_CONST_UNSPECIFIED
# undef ETH_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#if defined ETH_START_SEC_PBCFG
# undef ETH_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#if defined ETH_STOP_SEC_PBCFG
# undef ETH_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#if defined ETH_START_SEC_PBCFG_ROOT
# undef ETH_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#if defined ETH_STOP_SEC_PBCFG_ROOT
# undef ETH_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#if defined ETH_START_SEC_VAR_NOINIT_8BIT
# undef ETH_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined ETH_STOP_SEC_VAR_NOINIT_8BIT
# undef ETH_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETH_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETH_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETH_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETH_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#if defined ETH_START_SEC_VAR_NOINIT_16BIT
# undef ETH_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined ETH_STOP_SEC_VAR_NOINIT_16BIT
# undef ETH_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined ETH_START_SEC_VAR_NOINIT_32BIT
# undef ETH_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined ETH_STOP_SEC_VAR_NOINIT_32BIT
# undef ETH_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined ETH_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETH_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETH_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETH_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETH_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETH_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETH_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


#ifdef ETH_START_SEC_VAR_NOINIT_BUFFER
# undef ETH_START_SEC_VAR_NOINIT_BUFFER             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined ETH_STOP_SEC_VAR_NOINIT_BUFFER
# undef ETH_STOP_SEC_VAR_NOINIT_BUFFER
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  ETH END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DrvFls_VttCanoe01Asr START 
 **********************************************************************************************************************/

/*******  CODE sections ***********************************************************************************************/
#ifdef FLS_START_SEC_CODE
# undef FLS_START_SEC_CODE
# define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_CODE
# undef FLS_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/*******  CONST sections  *********************************************************************************************/

/*******  VAR sections  ***********************************************************************************************/


/**********************************************************************************************************************
 *  DrvFls_VttCanoe01Asr END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  FR START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FR_START_SEC_CODE
# undef FR_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef FR_STOP_SEC_CODE
# undef FR_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif


#ifdef FR_START_SEC_CODE_ISR
# undef FR_START_SEC_CODE_ISR
# define START_SEC_CODE_ISR                                           /* mapped to default ISR code section */
#endif
#ifdef FR_STOP_SEC_CODE_ISR
# undef FR_STOP_SEC_CODE_ISR
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef FR_APPL_START_SEC_CODE
# undef FR_APPL_START_SEC_CODE
# define START_SEC_CODE
#endif

#ifdef FR_APPL_STOP_SEC_CODE
# undef FR_APPL_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FR_START_SEC_CONST_32BIT
# undef FR_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef FR_STOP_SEC_CONST_32BIT
# undef FR_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef FR_START_SEC_CONST_16BIT
# undef FR_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef FR_STOP_SEC_CONST_16BIT
# undef FR_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef FR_START_SEC_CONST_8BIT
# undef FR_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef FR_STOP_SEC_CONST_8BIT
# undef FR_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif


#ifdef FR_START_SEC_CONST_UNSPECIFIED
# undef FR_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_CONST_UNSPECIFIED
# undef FR_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#ifdef FR_START_SEC_PBCFG_ROOT
# undef FR_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef FR_STOP_SEC_PBCFG_ROOT
# undef FR_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

#ifdef FR_START_SEC_PBCFG
# undef FR_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef FR_STOP_SEC_PBCFG
# undef FR_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef FR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FR_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR FAST NOINIT sections */

#ifdef FR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef FR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef FR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef FR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FR END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DrvGpt_VttCanoe01Asr START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

/*******  CONST sections  ********************************************************************************************/

/*******  VAR sections  **********************************************************************************************/


/**********************************************************************************************************************
 *  DrvGpt_VttCanoe01Asr END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DrvIcu_VttCanoe01Asr START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

/*******  CONST sections  ********************************************************************************************/

/*******  VAR sections  **********************************************************************************************/


/**********************************************************************************************************************
 *  DrvIcu_VttCanoe01Asr END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Lin_MemMap.inc
 *        \brief  AUTOSAR LIN Driver
 *
 *      \details  AUTOSAR LIN Driver for all target systems
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LIN START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(LIN_30_GENERIC_START_SEC_CODE)
# undef LIN_30_GENERIC_START_SEC_CODE
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_CODE)
# undef LIN_30_GENERIC_STOP_SEC_CODE
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(LIN_30_GENERIC_START_SEC_CODE_FAST)
# undef LIN_30_GENERIC_START_SEC_CODE_FAST
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_CODE_FAST)
# undef LIN_30_GENERIC_STOP_SEC_CODE_FAST
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(LIN_30_GENERIC_START_SEC_CODE_ISR)
# undef LIN_30_GENERIC_START_SEC_CODE_ISR
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_CODE_ISR)
# undef LIN_30_GENERIC_STOP_SEC_CODE_ISR
# define STOP_SEC_CODE          /* default code stop section */
#endif

#ifdef LIN_30_GENERIC_START_SEC_CODE_APPL
  #undef LIN_30_GENERIC_START_SEC_CODE_APPL
  #define START_SEC_CODE         /* mapped to default code section */
#endif
#ifdef LIN_30_GENERIC_STOP_SEC_CODE_APPL
  #undef LIN_30_GENERIC_STOP_SEC_CODE_APPL
  #define STOP_SEC_CODE         /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(LIN_30_GENERIC_START_SEC_CONST_8BIT)
# undef LIN_30_GENERIC_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_CONST_8BIT)
# undef LIN_30_GENERIC_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(LIN_30_GENERIC_START_SEC_CONST_16BIT)
# undef LIN_30_GENERIC_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_CONST_16BIT)
# undef LIN_30_GENERIC_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#if defined(LIN_30_GENERIC_START_SEC_CONST_32BIT)
# undef LIN_30_GENERIC_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_CONST_32BIT)
# undef LIN_30_GENERIC_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#if defined(LIN_30_GENERIC_START_SEC_CONST_UNSPECIFIED)
# undef LIN_30_GENERIC_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_CONST_UNSPECIFIED)
# undef LIN_30_GENERIC_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(LIN_30_GENERIC_START_SEC_FAST_CONST_8BIT)
# undef LIN_30_GENERIC_START_SEC_FAST_CONST_8BIT
# define START_SEC_FAST_CONST_8BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_FAST_CONST_8BIT)
# undef LIN_30_GENERIC_STOP_SEC_FAST_CONST_8BIT
# define STOP_SEC_CONST
#endif

#if defined(LIN_30_GENERIC_START_SEC_FAST_CONST_16BIT)
# undef LIN_30_GENERIC_START_SEC_FAST_CONST_16BIT
# define START_SEC_FAST_CONST_16BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_FAST_CONST_16BIT)
# undef LIN_30_GENERIC_STOP_SEC_FAST_CONST_16BIT
# define STOP_SEC_CONST
#endif

#if defined(LIN_30_GENERIC_START_SEC_FAST_CONST_32BIT)
# undef LIN_30_GENERIC_START_SEC_FAST_CONST_32BIT
# define START_SEC_FAST_CONST_32BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_FAST_CONST_32BIT)
# undef LIN_30_GENERIC_STOP_SEC_FAST_CONST_32BIT
# define STOP_SEC_CONST
#endif

#if defined(LIN_30_GENERIC_START_SEC_FAST_CONST_UNSPECIFIED)
# undef LIN_30_GENERIC_START_SEC_FAST_CONST_UNSPECIFIED
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_FAST_CONST_UNSPECIFIED)
# undef LIN_30_GENERIC_STOP_SEC_FAST_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#if defined(LIN_30_GENERIC_START_SEC_PBCFG_ROOT)
# undef LIN_30_GENERIC_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_PBCFG_ROOT)
# undef LIN_30_GENERIC_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#if defined(LIN_30_GENERIC_START_SEC_PBCFG_GLOBALROOT)
# undef LIN_30_GENERIC_START_SEC_PBCFG_GLOBALROOT
# define START_SEC_PBCFG_GLOBALROOT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_PBCFG_GLOBALROOT)
# undef LIN_30_GENERIC_STOP_SEC_PBCFG_GLOBALROOT
# define STOP_SEC_CONST
#endif

#if defined(LIN_30_GENERIC_START_SEC_PBCFG)
# undef LIN_30_GENERIC_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_PBCFG)
# undef LIN_30_GENERIC_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(LIN_30_GENERIC_START_SEC_VAR_INIT_8BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_INIT_8BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_INIT_16BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_INIT_16BIT
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_INIT_16BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_INIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_INIT_32BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_INIT_32BIT
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_INIT_32BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_INIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_INIT_UNSPECIFIED)
# undef LIN_30_GENERIC_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef LIN_30_GENERIC_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOINIT_8BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOINIT_8BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOINIT_16BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOINIT_16BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOINIT_32BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOINIT_32BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LIN_30_GENERIC_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(LIN_30_GENERIC_START_SEC_VAR_PBCFG)
# undef LIN_30_GENERIC_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_PBCFG)
# undef LIN_30_GENERIC_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(LIN_30_GENERIC_START_SEC_VAR_ZERO_INIT_8BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_ZERO_INIT_16BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_ZERO_INIT_16BIT
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_ZERO_INIT_32BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_ZERO_INIT_32BIT
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LIN_30_GENERIC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LIN_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(LIN_30_GENERIC_START_SEC_VAR_FAST_INIT_8BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_FAST_INIT_8BIT
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_FAST_INIT_8BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_FAST_INIT_16BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_FAST_INIT_16BIT
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_FAST_INIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_FAST_INIT_32BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_FAST_INIT_32BIT
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_FAST_INIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef LIN_30_GENERIC_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef LIN_30_GENERIC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(LIN_30_GENERIC_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_FAST_NOINIT_8BIT
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_FAST_NOINIT_16BIT
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_FAST_NOINIT_32BIT
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef LIN_30_GENERIC_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef LIN_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(LIN_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef LIN_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef LIN_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_8BIT
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_16BIT
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_32BIT
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef LIN_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef LIN_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef LIN_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef LIN_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef LIN_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  LIN END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  LIN START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(LIN_START_SEC_CODE)
# undef LIN_START_SEC_CODE         /* PRQA S 0841 */    /* MD_MSR_Undef */
# define START_SEC_CODE /* mapped to default code section */
#endif
#if defined(LIN_STOP_SEC_CODE)
# undef LIN_STOP_SEC_CODE          /* PRQA S 0841 */    /* MD_MSR_Undef */
# define STOP_SEC_CODE  /* default code stop section */
#endif

#if defined(LIN_START_SEC_CODE_FAST)
# undef LIN_START_SEC_CODE_FAST    /* PRQA S 0841 */    /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(LIN_STOP_SEC_CODE_FAST)
# undef LIN_STOP_SEC_CODE_FAST     /* PRQA S 0841 */    /* MD_MSR_Undef */
# define STOP_SEC_CODE  /* default code stop section */
#endif

#if defined(LIN_START_SEC_CODE_ISR)
# undef LIN_START_SEC_CODE_ISR     /* PRQA S 0841 */    /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(LIN_STOP_SEC_CODE_ISR)
# undef LIN_STOP_SEC_CODE_ISR      /* PRQA S 0841 */    /* MD_MSR_Undef */
# define STOP_SEC_CODE  /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(LIN_START_SEC_CONST_8BIT)
# undef LIN_START_SEC_CONST_8BIT     /* PRQA S 0841 */  /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT   /* mapped to default const 8bit section */
#endif
#if defined(LIN_STOP_SEC_CONST_8BIT)
# undef LIN_STOP_SEC_CONST_8BIT      /* PRQA S 0841 */  /* MD_MSR_Undef */
# define STOP_SEC_CONST /* default const stop section */
#endif

#if defined(LIN_START_SEC_CONST_16BIT)
# undef LIN_START_SEC_CONST_16BIT    /* PRQA S 0841 */  /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(LIN_STOP_SEC_CONST_16BIT)
# undef LIN_STOP_SEC_CONST_16BIT    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_START_SEC_CONST_32BIT)
# undef LIN_START_SEC_CONST_32BIT    /* PRQA S 0841 */  /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(LIN_STOP_SEC_CONST_32BIT)
# undef LIN_STOP_SEC_CONST_32BIT    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_START_SEC_CONST_UNSPECIFIED)
# undef LIN_START_SEC_CONST_UNSPECIFIED    /* PRQA S 0841 */    /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_CONST_UNSPECIFIED)
# undef LIN_STOP_SEC_CONST_UNSPECIFIED    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(LIN_START_SEC_FAST_CONST_8BIT)
# undef LIN_START_SEC_FAST_CONST_8BIT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#if defined(LIN_STOP_SEC_FAST_CONST_8BIT)
# undef LIN_STOP_SEC_FAST_CONST_8BIT    /* PRQA S 0841 */       /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_START_SEC_FAST_CONST_16BIT)
# undef LIN_START_SEC_FAST_CONST_16BIT    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#if defined(LIN_STOP_SEC_FAST_CONST_16BIT)
# undef LIN_STOP_SEC_FAST_CONST_16BIT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_START_SEC_FAST_CONST_32BIT)
# undef LIN_START_SEC_FAST_CONST_32BIT    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#if defined(LIN_STOP_SEC_FAST_CONST_32BIT)
# undef LIN_STOP_SEC_FAST_CONST_32BIT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_START_SEC_FAST_CONST_UNSPECIFIED)
# undef LIN_START_SEC_FAST_CONST_UNSPECIFIED    /* PRQA S 0841 */       /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_FAST_CONST_UNSPECIFIED)
# undef LIN_STOP_SEC_FAST_CONST_UNSPECIFIED    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#if defined(LIN_START_SEC_PBCFG_ROOT)
# undef LIN_START_SEC_PBCFG_ROOT    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(LIN_STOP_SEC_PBCFG_ROOT)
# undef LIN_STOP_SEC_PBCFG_ROOT    /* PRQA S 0841 */    /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#if defined(LIN_START_SEC_PBCFG_GLOBALROOT)
# undef LIN_START_SEC_PBCFG_GLOBALROOT    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#if defined(LIN_STOP_SEC_PBCFG_GLOBALROOT)
# undef LIN_STOP_SEC_PBCFG_GLOBALROOT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_START_SEC_PBCFG)
# undef LIN_START_SEC_PBCFG    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(LIN_STOP_SEC_PBCFG)
# undef LIN_STOP_SEC_PBCFG    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(LIN_START_SEC_VAR_INIT_8BIT)
# undef LIN_START_SEC_VAR_INIT_8BIT    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT        /* mapped to default var init 8bit section */
#endif
#if defined(LIN_STOP_SEC_VAR_INIT_8BIT)
# undef LIN_STOP_SEC_VAR_INIT_8BIT    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR   /* default var stop section */
#endif

#if defined(LIN_START_SEC_VAR_INIT_16BIT)
# undef LIN_START_SEC_VAR_INIT_16BIT    /* PRQA S 0841 */       /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_INIT_16BIT)
# undef LIN_STOP_SEC_VAR_INIT_16BIT    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_INIT_32BIT)
# undef LIN_START_SEC_VAR_INIT_32BIT    /* PRQA S 0841 */       /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_INIT_32BIT)
# undef LIN_STOP_SEC_VAR_INIT_32BIT    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_INIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_INIT_UNSPECIFIED    /* PRQA S 0841 */  /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(LIN_START_SEC_VAR_NOINIT_8BIT)
# undef LIN_START_SEC_VAR_NOINIT_8BIT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOINIT_8BIT)
# undef LIN_STOP_SEC_VAR_NOINIT_8BIT    /* PRQA S 0841 */       /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOINIT_16BIT)
# undef LIN_START_SEC_VAR_NOINIT_16BIT    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOINIT_16BIT)
# undef LIN_STOP_SEC_VAR_NOINIT_16BIT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOINIT_32BIT)
# undef LIN_START_SEC_VAR_NOINIT_32BIT    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOINIT_32BIT)
# undef LIN_STOP_SEC_VAR_NOINIT_32BIT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_NOINIT_UNSPECIFIED    /* PRQA S 0841 */       /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(LIN_START_SEC_VAR_PBCFG)
# undef LIN_START_SEC_VAR_PBCFG    /* PRQA S 0841 */    /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(LIN_STOP_SEC_VAR_PBCFG)
# undef LIN_STOP_SEC_VAR_PBCFG    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(LIN_START_SEC_VAR_ZERO_INIT_8BIT)
# undef LIN_START_SEC_VAR_ZERO_INIT_8BIT    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef LIN_STOP_SEC_VAR_ZERO_INIT_8BIT    /* PRQA S 0841 */    /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_ZERO_INIT_16BIT)
# undef LIN_START_SEC_VAR_ZERO_INIT_16BIT    /* PRQA S 0841 */  /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef LIN_STOP_SEC_VAR_ZERO_INIT_16BIT    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_ZERO_INIT_32BIT)
# undef LIN_START_SEC_VAR_ZERO_INIT_32BIT    /* PRQA S 0841 */  /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef LIN_STOP_SEC_VAR_ZERO_INIT_32BIT    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */    /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(LIN_START_SEC_VAR_FAST_INIT_8BIT)
# undef LIN_START_SEC_VAR_FAST_INIT_8BIT    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef LIN_STOP_SEC_VAR_FAST_INIT_8BIT    /* PRQA S 0841 */    /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_INIT_16BIT)
# undef LIN_START_SEC_VAR_FAST_INIT_16BIT    /* PRQA S 0841 */  /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef LIN_STOP_SEC_VAR_FAST_INIT_16BIT    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_INIT_32BIT)
# undef LIN_START_SEC_VAR_FAST_INIT_32BIT    /* PRQA S 0841 */  /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef LIN_STOP_SEC_VAR_FAST_INIT_32BIT    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_FAST_INIT_UNSPECIFIED    /* PRQA S 0841 */    /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(LIN_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef LIN_START_SEC_VAR_FAST_NOINIT_8BIT    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_8BIT    /* PRQA S 0841 */  /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef LIN_START_SEC_VAR_FAST_NOINIT_16BIT    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_16BIT    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef LIN_START_SEC_VAR_FAST_NOINIT_32BIT    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_32BIT    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED    /* PRQA S 0841 */  /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(LIN_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef LIN_START_SEC_VAR_FAST_ZERO_INIT_8BIT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef LIN_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT    /* PRQA S 0841 */       /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef LIN_START_SEC_VAR_FAST_ZERO_INIT_16BIT    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef LIN_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef LIN_START_SEC_VAR_FAST_ZERO_INIT_32BIT    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef LIN_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */       /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(LIN_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef LIN_START_SEC_VAR_NOCACHE_INIT_8BIT    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_INIT_8BIT    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef LIN_START_SEC_VAR_NOCACHE_INIT_16BIT    /* PRQA S 0841 */       /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_INIT_16BIT    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef LIN_START_SEC_VAR_NOCACHE_INIT_32BIT    /* PRQA S 0841 */       /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_INIT_32BIT    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED    /* PRQA S 0841 */  /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(LIN_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef LIN_START_SEC_VAR_NOCACHE_NOINIT_8BIT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT    /* PRQA S 0841 */       /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef LIN_START_SEC_VAR_NOCACHE_NOINIT_16BIT    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef LIN_START_SEC_VAR_NOCACHE_NOINIT_32BIT    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT    /* PRQA S 0841 */      /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED    /* PRQA S 0841 */       /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED    /* PRQA S 0841 */        /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT    /* PRQA S 0841 */    /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT    /* PRQA S 0841 */  /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT    /* PRQA S 0841 */  /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT    /* PRQA S 0841 */   /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef LIN_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */    /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef LIN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */     /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  LIN END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DrvMcu_VttCanoe01Asr START 
 **********************************************************************************************************************/

/*******  CODE sections ***********************************************************************************************/

/*******  CONST sections  *********************************************************************************************/

/*******  VAR sections  ***********************************************************************************************/



/**********************************************************************************************************************
 *  DrvMcu_VttCanoe01Asr END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM_30_VTT START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_VTT_START_SEC_CODE)
# undef VMEM_30_VTT_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_VTT_STOP_SEC_CODE)
# undef VMEM_30_VTT_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_VTT_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_VTT_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_VTT_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_VTT_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

/* VAR ZERO INIT sections */
#if defined VMEM_30_VTT_START_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_VTT_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined VMEM_30_VTT_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_VTT_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VMEM_30_VTT_START_SEC_VAR_NO_INIT_32
# undef VMEM_30_VTT_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef VMEM_30_VTT_STOP_SEC_VAR_NO_INIT_32
# undef VMEM_30_VTT_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VMEM_30_VTT_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef VMEM_30_VTT_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef VMEM_30_VTT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef VMEM_30_VTT_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */

/**********************************************************************************************************************
 *  VMEM_30_VTT END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DrvPort_VttCanoe01Asr START 
 **********************************************************************************************************************/

/*******  CODE sections ***********************************************************************************************/

/*******  CONST sections  *********************************************************************************************/

/*******  VAR sections  ***********************************************************************************************/



/**********************************************************************************************************************
 *  DrvPort_VttCanoe01Asr END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  DrvPwm_VttCanoe01Asr START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

/*******  CONST sections  ********************************************************************************************/

/*******  VAR sections  **********************************************************************************************/


/**********************************************************************************************************************
 *  DrvPwm_VttCanoe01Asr END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DrvSpi_VttCanoe01Asr START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef SPI_START_SEC_CODE
# undef SPI_START_SEC_CODE
# define START_SEC_CODE
#endif

#ifdef SPI_STOP_SEC_CODE
# undef SPI_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/*******  VAR sections  **********************************************************************************************/


/**********************************************************************************************************************
 *  DrvSpi_VttCanoe01Asr END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV 30 VTT START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_VTT_START_SEC_CODE
  #undef ETHTRCV_30_VTT_START_SEC_CODE                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE                                    /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_CODE
  #undef ETHTRCV_30_VTT_STOP_SEC_CODE                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE                                     /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_VTT_START_SEC_CONST_8BIT
# undef ETHTRCV_30_VTT_START_SEC_CONST_8BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_VTT_STOP_SEC_CONST_8BIT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_VTT_START_SEC_CONST_16BIT
# undef ETHTRCV_30_VTT_START_SEC_CONST_16BIT                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_VTT_STOP_SEC_CONST_16BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_VTT_START_SEC_CONST_32BIT
# undef ETHTRCV_30_VTT_START_SEC_CONST_32BIT                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_VTT_STOP_SEC_CONST_32BIT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_VTT_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_VTT_START_SEC_CONST_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_VTT_STOP_SEC_CONST_UNSPECIFIED           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_VTT_START_SEC_PBCFG
# undef ETHTRCV_30_VTT_START_SEC_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_PBCFG
# undef ETHTRCV_30_VTT_STOP_SEC_PBCFG                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_VTT_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_VTT_START_SEC_PBCFG_ROOT                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_VTT_STOP_SEC_PBCFG_ROOT                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_VTT_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_VTT_START_SEC_VAR_NOINIT_8BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_VTT_STOP_SEC_VAR_NOINIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_VTT_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_VTT_START_SEC_VAR_ZERO_INIT_8BIT         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_VTT_STOP_SEC_VAR_ZERO_INIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_VTT_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_VTT_START_SEC_VAR_NOINIT_16BIT           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_VTT_STOP_SEC_VAR_NOINIT_16BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_VTT_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_VTT_START_SEC_VAR_NOINIT_32BIT           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_VTT_STOP_SEC_VAR_NOINIT_32BIT            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_VTT_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_VTT_START_SEC_VAR_NOINIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_VTT_STOP_SEC_VAR_NOINIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_VTT_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_VTT_START_SEC_VAR_ZERO_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_VTT_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_VTT_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV 30 VTT END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DrvWd_VttCanoe01Asr START 
 **********************************************************************************************************************/

/*******  CODE sections ***********************************************************************************************/

/*******  CONST sections  *********************************************************************************************/

/*******  VAR sections  ***********************************************************************************************/


/**********************************************************************************************************************
 *  DrvWd_VttCanoe01Asr END
 **********************************************************************************************************************/


/* PRQA L:MEMMAP_0841_TAG */

#include "MemMap_Common.h"

/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/


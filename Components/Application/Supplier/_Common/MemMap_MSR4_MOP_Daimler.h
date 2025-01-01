/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *  01.12.00  2018-10-17  visdfe ESCAN00095695  Add support for Os_CoreGen7 within _MemMap.h (Include of Os_MemMap.h)
 *                               TASK-78775     Change MemMap_Common.h to Template
 *  01.13.00  2021-05-06  virmfr HALBE-3985     CommonAsr_MemMap shall include Common_MemMap generated compatibility header
 *  02.00.00  2021-06-09  visto  HALBE-4594     Create a branch for >=R27 Features
 *  02.01.00  2021-08-25  virmfr HALBE-4526     MemMap_Common.h removed
 *  02.01.01  2021-09-07  virmfr HALBE-5304     MemMapIncludesList removed
 *********************************************************************************************************************/

/* PRQA S 0841 MEMMAP_0841_TAG */ /* MD_MSR_19.6 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Package Merger: Start Section MemMapModuleList */



/** DEM **********************************************************************/
/*---------------------START-MODULE-SPECIFIC-START-SECTIONS------------------*/

                                                            /* code sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_CODE)
# undef DEM_START_SEC_CODE                                                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif

#if defined (DEM_START_SEC_CALLOUT_CODE)
# undef DEM_START_SEC_CALLOUT_CODE                                             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif

#if defined (DEM_START_SEC_CODE_LIB)
# undef DEM_START_SEC_CODE_LIB                                                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif

                                               /* uninitialized RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_VAR_NOINIT_8BIT)
# undef DEM_START_SEC_VAR_NOINIT_8BIT                                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_16BIT)
# undef DEM_START_SEC_VAR_NOINIT_16BIT                                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_32BIT)
# undef DEM_START_SEC_VAR_NOINIT_32BIT                                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED                                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_VAR_UNCACHED_UNSPECIFIED)
# undef DEM_START_SEC_VAR_UNCACHED_UNSPECIFIED                                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED_SAT0)
# undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED_SAT0                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED_SAT1)
# undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED_SAT1                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_VAR_NOINIT_UNSPECIFIED_RESTRICTED)
# undef DEM_START_SEC_VAR_NOINIT_UNSPECIFIED_RESTRICTED                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
                                                 /* initialized RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_VAR_INIT_8BIT)
# undef DEM_START_SEC_VAR_INIT_8BIT                                            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT
#endif
#if defined (DEM_START_SEC_VAR_INIT_32BIT)
# undef DEM_START_SEC_VAR_INIT_32BIT                                           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined (DEM_START_SEC_VAR_INIT_8BIT_RESTRICTED)
# undef DEM_START_SEC_VAR_INIT_8BIT_RESTRICTED                                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT
#endif

                                              /* post-buildable RAM sections */
/*---------------------------------------------------------------------------*/
#if defined (DEM_START_SEC_VAR_PBCFG)
# undef DEM_START_SEC_VAR_PBCFG                                                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif


                                                          /* NV RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_VAR_SAVED_ZONE0_8BIT)
# undef DEM_START_SEC_VAR_SAVED_ZONE0_8BIT                                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif

#if defined (DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
# undef DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_CONST_SAVED_RECOVERY_ZONE0)
# undef DEM_START_SEC_CONST_SAVED_RECOVERY_ZONE0                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif

                                                             /* ROM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_START_SEC_CONST_8BIT)
# undef DEM_START_SEC_CONST_8BIT                                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined (DEM_START_SEC_CONST_16BIT)
# undef DEM_START_SEC_CONST_16BIT                                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined (DEM_START_SEC_CONST_32BIT)
# undef DEM_START_SEC_CONST_32BIT                                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined (DEM_START_SEC_CONST_UNSPECIFIED)
# undef DEM_START_SEC_CONST_UNSPECIFIED                                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_CONFIG_DATA_UNSPECIFIED)
# undef DEM_START_SEC_CONFIG_DATA_UNSPECIFIED                                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_PBCFG_ROOT)
# undef DEM_START_SEC_PBCFG_ROOT                                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif

#if defined (DEM_START_SEC_CALIB_UNSPECIFIED)
# undef DEM_START_SEC_CALIB_UNSPECIFIED                                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif

#if defined (DEM_START_SEC_CALIB_8BIT)
# undef DEM_START_SEC_CALIB_8BIT                                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif

#if defined (DEM_START_SEC_PBCFG)
# undef DEM_START_SEC_PBCFG                                                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif



/*---------------------STOP-MODULE-SPECIFIC-START-SECTIONS-------------------*/

/*---------------------START-MODULE-SPECIFIC-STOP-SECTIONS-------------------*/


                                                            /* code sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_CODE)
# undef DEM_STOP_SEC_CODE                                                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#if defined (DEM_STOP_SEC_CALLOUT_CODE)
# undef DEM_STOP_SEC_CALLOUT_CODE                                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#if defined (DEM_STOP_SEC_CODE_LIB)
# undef DEM_STOP_SEC_CODE_LIB                                                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

                                               /* uninitialized RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_VAR_NOINIT_8BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_8BIT                                           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_16BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_16BIT                                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_32BIT)
# undef DEM_STOP_SEC_VAR_NOINIT_32BIT                                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED                                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_UNCACHED_UNSPECIFIED)
# undef DEM_STOP_SEC_VAR_UNCACHED_UNSPECIFIED                                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SAT0)
# undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SAT0                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SAT1)
# undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SAT1                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED_RESTRICTED)
# undef DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED_RESTRICTED                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

                                                 /* initialized RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_VAR_INIT_8BIT)
# undef DEM_STOP_SEC_VAR_INIT_8BIT                                             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif
#if defined (DEM_STOP_SEC_VAR_INIT_32BIT)
# undef DEM_STOP_SEC_VAR_INIT_32BIT                                            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_INIT_8BIT_RESTRICTED)
# undef DEM_STOP_SEC_VAR_INIT_8BIT_RESTRICTED                                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif
                                              /* post-buildable RAM sections */
/*---------------------------------------------------------------------------*/
#if defined (DEM_STOP_SEC_VAR_PBCFG)
# undef DEM_STOP_SEC_VAR_PBCFG                                                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

                                                          /* NV RAM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED)
# undef DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_VAR_SAVED_ZONE0_8BIT)
# undef DEM_STOP_SEC_VAR_SAVED_ZONE0_8BIT                                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined (DEM_STOP_SEC_CONST_SAVED_RECOVERY_ZONE0)
# undef DEM_STOP_SEC_CONST_SAVED_RECOVERY_ZONE0                                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

                                                             /* ROM sections */
/*---------------------------------------------------------------------------*/

#if defined (DEM_STOP_SEC_CONST_8BIT)
# undef DEM_STOP_SEC_CONST_8BIT                                                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_16BIT)
# undef DEM_STOP_SEC_CONST_16BIT                                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_32BIT)
# undef DEM_STOP_SEC_CONST_32BIT                                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CONST_UNSPECIFIED)
# undef DEM_STOP_SEC_CONST_UNSPECIFIED                                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_PBCFG_ROOT)
# undef DEM_STOP_SEC_PBCFG_ROOT                                                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_CALIB_UNSPECIFIED)
# undef DEM_STOP_SEC_CALIB_UNSPECIFIED                                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif
#if defined (DEM_STOP_SEC_CALIB_8BIT)
# undef DEM_STOP_SEC_CALIB_8BIT                                                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined (DEM_STOP_SEC_PBCFG)
# undef DEM_STOP_SEC_PBCFG                                                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#include "Dem_MemMap.h"

/*---------------------STOP-MODULE-SPECIFIC-STOP-SECTIONS--------------------*/
/** End of DEM ***************************************************************/


/***********************************************************************************************************************
 *  SWCDIAG START
 **********************************************************************************************************************/


/******* CODE sections ************************************************************************************************/

#if defined(SWCDIAG_START_SEC_CODE)
# undef SWCDIAG_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif /* SWCDIAG_START_SEC_CODE */
#if defined(SWCDIAG_STOP_SEC_CODE)
# undef SWCDIAG_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif /* SWCDIAG_START_SEC_CODE */


/******* CONST sections ***********************************************************************************************/

#if defined(SWCDIAG_START_SEC_CONST_UNSPECIFIED)
# undef SWCDIAG_START_SEC_CONST_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                                  /* mapped to default code section */
#endif /* SWCDIAG_START_SEC_CONST_UNSPECIFIED */
#if defined(SWCDIAG_STOP_SEC_CONST_UNSPECIFIED)
# undef SWCDIAG_STOP_SEC_CONST_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                               /* default code stop section */
#endif /* SWCDIAG_START_SEC_CONST_UNSPECIFIED */


/******* VAR sections *************************************************************************************************/

#if defined(SWCDIAG_START_SEC_VAR_INIT_8)
# undef SWCDIAG_START_SEC_VAR_INIT_8      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8                                         /* mapped to default code section */
#endif /* SWCDIAG_START_SEC_VAR_INIT_8 */
#if defined(SWCDIAG_STOP_SEC_VAR_INIT_8)
# undef SWCDIAG_STOP_SEC_VAR_INIT_8       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                 /* default code stop section */
#endif /* SWCDIAG_START_SEC_VAR_INIT_8 */

#if defined(SWCDIAG_START_SEC_VAR_NO_INIT_8)
# undef SWCDIAG_START_SEC_VAR_NO_INIT_8      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_8                                      /* mapped to default code section */
#endif /* SWCDIAG_START_SEC_VAR_NO_INIT_8 */
#if defined(SWCDIAG_STOP_SEC_VAR_NO_INIT_8)
# undef SWCDIAG_STOP_SEC_VAR_NO_INIT_8       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                 /* default code stop section */
#endif /* SWCDIAG_START_SEC_VAR_NO_INIT_8 */

#if defined(SWCDIAG_START_SEC_VAR_NO_INIT_16)
# undef SWCDIAG_START_SEC_VAR_NO_INIT_16      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_16                                     /* mapped to default code section */
#endif /* SWCDIAG_START_SEC_VAR_NO_INIT_16 */
#if defined(SWCDIAG_STOP_SEC_VAR_NO_INIT_16)
# undef SWCDIAG_STOP_SEC_VAR_NO_INIT_16       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                 /* default code stop section */
#endif /* SWCDIAG_START_SEC_VAR_NO_INIT_16 */

#if defined(SWCDIAG_START_SEC_VAR_NO_INIT_32)
# undef SWCDIAG_START_SEC_VAR_NO_INIT_32      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_32                                     /* mapped to default code section */
#endif /* SWCDIAG_START_SEC_VAR_NO_INIT_32 */
#if defined(SWCDIAG_STOP_SEC_VAR_NO_INIT_32)
# undef SWCDIAG_STOP_SEC_VAR_NO_INIT_32       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                 /* default code stop section */
#endif /* SWCDIAG_START_SEC_VAR_NO_INIT_32 */

/***********************************************************************************************************************
 *  SWCDIAG STOP
 **********************************************************************************************************************/



/***********************************************************************************************************************
 *  VSTREAMPROC START
 **********************************************************************************************************************/
 
/*******  CODE sections **********************************************************************************************/
#ifdef VSTREAMPROC_START_SEC_CODE
# undef VSTREAMPROC_START_SEC_CODE                                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif

#ifdef VSTREAMPROC_STOP_SEC_CODE
# undef VSTREAMPROC_STOP_SEC_CODE                                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef VSTREAMPROC_START_SEC_CONST_8BIT
# undef VSTREAMPROC_START_SEC_CONST_8BIT                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif

#ifdef VSTREAMPROC_STOP_SEC_CONST_8BIT
# undef VSTREAMPROC_STOP_SEC_CONST_8BIT                                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VSTREAMPROC_START_SEC_CONST_16BIT
# undef VSTREAMPROC_START_SEC_CONST_16BIT                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif

#ifdef VSTREAMPROC_STOP_SEC_CONST_16BIT
# undef VSTREAMPROC_STOP_SEC_CONST_16BIT                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VSTREAMPROC_START_SEC_CONST_32BIT
# undef VSTREAMPROC_START_SEC_CONST_32BIT                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif

#ifdef VSTREAMPROC_STOP_SEC_CONST_32BIT
# undef VSTREAMPROC_STOP_SEC_CONST_32BIT                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VSTREAMPROC_START_SEC_CONST_UNSPECIFIED
# undef VSTREAMPROC_START_SEC_CONST_UNSPECIFIED                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef VSTREAMPROC_STOP_SEC_CONST_UNSPECIFIED
# undef VSTREAMPROC_STOP_SEC_CONST_UNSPECIFIED                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif



/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */
#ifdef VSTREAMPROC_START_SEC_VAR_NOINIT_8BIT
# undef VSTREAMPROC_START_SEC_VAR_NOINIT_8BIT                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef VSTREAMPROC_STOP_SEC_VAR_NOINIT_8BIT
# undef VSTREAMPROC_STOP_SEC_VAR_NOINIT_8BIT                           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VSTREAMPROC_START_SEC_STORAGENODE_VAR_NOINIT_8BIT
# undef VSTREAMPROC_START_SEC_STORAGENODE_VAR_NOINIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef VSTREAMPROC_STOP_SEC_STORAGENODE_VAR_NOINIT_8BIT
# undef VSTREAMPROC_STOP_SEC_STORAGENODE_VAR_NOINIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VSTREAMPROC_START_SEC_VAR_NOINIT_32BIT
# undef VSTREAMPROC_START_SEC_VAR_NOINIT_32BIT                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef VSTREAMPROC_STOP_SEC_VAR_NOINIT_32BIT
# undef VSTREAMPROC_STOP_SEC_VAR_NOINIT_32BIT                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VSTREAMPROC_START_SEC_VAR_NOINIT_64BIT
# undef VSTREAMPROC_START_SEC_VAR_NOINIT_64BIT                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_64BIT
#endif

#ifdef VSTREAMPROC_STOP_SEC_VAR_NOINIT_64BIT
# undef VSTREAMPROC_STOP_SEC_VAR_NOINIT_64BIT                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VSTREAMPROC_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VSTREAMPROC_START_SEC_VAR_NOINIT_UNSPECIFIED                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef VSTREAMPROC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VSTREAMPROC_STOP_SEC_VAR_NOINIT_UNSPECIFIED                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VSTREAMPROC_START_SEC_STORAGENODEBUFFER_VAR_NOINIT_UNSPECIFIED
# undef VSTREAMPROC_START_SEC_STORAGENODEBUFFER_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef VSTREAMPROC_STOP_SEC_STORAGENODEBUFFER_VAR_NOINIT_UNSPECIFIED
# undef VSTREAMPROC_STOP_SEC_STORAGENODEBUFFER_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef VSTREAMPROC_START_SEC_VAR_ZERO_INIT_8BIT
# undef VSTREAMPROC_START_SEC_VAR_ZERO_INIT_8BIT                       /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef VSTREAMPROC_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VSTREAMPROC_STOP_SEC_VAR_ZERO_INIT_8BIT                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VSTREAMPROC_START_SEC_PBCFG
# undef VSTREAMPROC_START_SEC_PBCFG                                    /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_PBCFG
#endif
#ifdef VSTREAMPROC_STOP_SEC_PBCFG
# undef VSTREAMPROC_STOP_SEC_PBCFG                                     /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_CONST
#endif


/***********************************************************************************************************************
 *  VSTREAMPROC END
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  VSTREAMPROCCMPRLZ77 START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef VSTREAMPROCCMPRLZ77_START_SEC_CODE
# undef VSTREAMPROCCMPRLZ77_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef VSTREAMPROCCMPRLZ77_STOP_SEC_CODE
# undef VSTREAMPROCCMPRLZ77_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */


/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */

/***********************************************************************************************************************
 *  VSTREAMPROCCMPRLZ77 END
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  VSWUPDM START
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef VSWUPDM_START_SEC_CODE
#undef VSWUPDM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CODE
#endif
#ifdef VSWUPDM_STOP_SEC_CODE
#undef VSWUPDM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CODE
#endif

#ifdef VSWUPDM_START_SEC_APPL_CODE
#undef VSWUPDM_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CODE
#endif
#ifdef VSWUPDM_STOP_SEC_APPL_CODE
#undef VSWUPDM_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CODE
#endif

#ifdef VSWUPDM_START_SEC_USER_CODE
#undef VSWUPDM_START_SEC_USER_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CODE
#endif
#ifdef VSWUPDM_STOP_SEC_USER_CODE
#undef VSWUPDM_STOP_SEC_USER_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef VSWUPDM_START_SEC_CONST_8BIT
#undef VSWUPDM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CONST_8BIT
#endif
#ifdef VSWUPDM_STOP_SEC_CONST_8BIT
#undef VSWUPDM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CONST
#endif

#ifdef VSWUPDM_START_SEC_CONST_16BIT
#undef VSWUPDM_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CONST_16BIT
#endif
#ifdef VSWUPDM_STOP_SEC_CONST_16BIT
#undef VSWUPDM_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CONST
#endif

#ifdef VSWUPDM_START_SEC_CONST_32BIT
#undef VSWUPDM_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CONST_32BIT
#endif
#ifdef VSWUPDM_STOP_SEC_CONST_32BIT
#undef VSWUPDM_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef VSWUPDM_START_SEC_VAR_NOINIT_8BIT
#undef VSWUPDM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef VSWUPDM_STOP_SEC_VAR_NOINIT_8BIT
#undef VSWUPDM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

#ifdef VSWUPDM_START_SEC_VAR_NOINIT_32BIT
#undef VSWUPDM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef VSWUPDM_STOP_SEC_VAR_NOINIT_32BIT
#undef VSWUPDM_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

#ifdef VSWUPDM_START_SEC_VAR_NOINIT_UNSPECIFIED
#undef VSWUPDM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VSWUPDM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#undef VSWUPDM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

#ifdef VSWUPDM_START_SEC_APPL_VAR_NOINIT_UNSPECIFIED
#undef VSWUPDM_START_SEC_APPL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VSWUPDM_STOP_SEC_APPL_VAR_NOINIT_UNSPECIFIED
#undef VSWUPDM_STOP_SEC_APPL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef VSWUPDM_START_SEC_VAR_ZERO_INIT_8BIT
#undef VSWUPDM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef VSWUPDM_STOP_SEC_VAR_ZERO_INIT_8BIT
#undef VSWUPDM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

#ifdef VSWUPDM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#undef VSWUPDM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef VSWUPDM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#undef VSWUPDM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

/* VAR INIT sections */
#ifdef VSWUPDM_START_SEC_VAR_INIT_UNSPECIFIED
#undef VSWUPDM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef VSWUPDM_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef VSWUPDM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

/* CONST INIT sections */
#ifdef VSWUPDM_START_SEC_CONST_UNSPECIFIED
#undef VSWUPDM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VSWUPDM_STOP_SEC_CONST_UNSPECIFIED
#undef VSWUPDM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CONST
#endif

#ifdef VSWUPDM_START_SEC_CONST_8BIT
#undef VSWUPDM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CONST_8BIT
#endif
#ifdef VSWUPDM_STOP_SEC_CONST_8BIT
#undef VSWUPDM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CONST
#endif

#ifdef VSWUPDM_START_SEC_APPL_CONST_UNSPECIFIED
#undef VSWUPDM_START_SEC_APPL_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VSWUPDM_STOP_SEC_APPL_CONST_UNSPECIFIED
#undef VSWUPDM_STOP_SEC_APPL_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CONST
#endif

#ifdef VSWUPDM_START_SEC_PBCFG
#undef VSWUPDM_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CONST_PBCFG
#endif
#ifdef VSWUPDM_STOP_SEC_PBCFG
#undef VSWUPDM_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CONST
#endif

/***********************************************************************************************************************
 *  VSWUPDM END
 **********************************************************************************************************************/



/***********************************************************************************************************************
 *  VFOTAH START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef VFOTAH_START_SEC_CODE
  #undef VFOTAH_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE
#endif
#ifdef VFOTAH_STOP_SEC_CODE
  #undef VFOTAH_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef VFOTAH_START_SEC_CONST_32BIT
# undef VFOTAH_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_32BIT
#endif
#ifdef VFOTAH_STOP_SEC_CONST_32BIT
# undef VFOTAH_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef   VFOTAH_START_SEC_CONST_UNSPECIFIED
# undef  VFOTAH_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef   VFOTAH_STOP_SEC_CONST_UNSPECIFIED
# undef  VFOTAH_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef VFOTAH_START_SEC_VAR_NOINIT_8BIT
# undef VFOTAH_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef VFOTAH_STOP_SEC_VAR_NOINIT_8BIT
# undef VFOTAH_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFOTAH_START_SEC_VAR_NOINIT_32BIT
# undef VFOTAH_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef VFOTAH_STOP_SEC_VAR_NOINIT_32BIT
# undef VFOTAH_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef   VFOTAH_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef  VFOTAH_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef   VFOTAH_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef  VFOTAH_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef VFOTAH_START_SEC_VAR_ZERO_INIT_8BIT
# undef VFOTAH_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef VFOTAH_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VFOTAH_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFOTAH_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VFOTAH_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef VFOTAH_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VFOTAH_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR INIT SECTIONS */
#ifdef VFOTAH_START_SEC_VAR_INIT_8BIT
# undef VFOTAH_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT
#endif
#ifdef VFOTAH_STOP_SEC_VAR_INIT_8BIT
# undef VFOTAH_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFOTAH_START_SEC_VAR_INIT_UNSPECIFIED
# undef VFOTAH_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef VFOTAH_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef VFOTAH_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFOTAH_START_SEC_PBCFG
# undef VFOTAH_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef VFOTAH_STOP_SEC_PBCFG
# undef VFOTAH_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/***********************************************************************************************************************
 *  VFOTAH END
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  SSA START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SSA_START_SEC_CODE
# undef SSA_START_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                             /* mapped to default code section */
#endif
#ifdef SSA_STOP_SEC_CODE
# undef SSA_STOP_SEC_CODE                           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                              /* default code stop section */
#endif

#ifdef SSA_START_SEC_APPL_CODE
# undef SSA_START_SEC_APPL_CODE                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                             /* mapped to default code section */
#endif
#ifdef SSA_STOP_SEC_APPL_CODE
# undef SSA_STOP_SEC_APPL_CODE                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                              /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SSA_START_SEC_CONST_8BIT
# undef SSA_START_SEC_CONST_8BIT                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#ifdef SSA_STOP_SEC_CONST_8BIT
# undef SSA_STOP_SEC_CONST_8BIT                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SSA_START_SEC_CONST_16BIT
# undef SSA_START_SEC_CONST_16BIT                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SSA_STOP_SEC_CONST_16BIT
# undef SSA_STOP_SEC_CONST_16BIT                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SSA_START_SEC_CONST_32BIT
# undef SSA_START_SEC_CONST_32BIT                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SSA_STOP_SEC_CONST_32BIT
# undef SSA_STOP_SEC_CONST_32BIT                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SSA_START_SEC_CONST_UNSPECIFIED
# undef SSA_START_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SSA_STOP_SEC_CONST_UNSPECIFIED
# undef SSA_STOP_SEC_CONST_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef SSA_START_SEC_VAR_NOINIT_8BIT
# undef SSA_START_SEC_VAR_NOINIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SSA_STOP_SEC_VAR_NOINIT_8BIT
# undef SSA_STOP_SEC_VAR_NOINIT_8BIT                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SSA_START_SEC_VAR_NOINIT_16BIT
# undef SSA_START_SEC_VAR_NOINIT_16BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SSA_STOP_SEC_VAR_NOINIT_16BIT
# undef SSA_STOP_SEC_VAR_NOINIT_16BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SSA_START_SEC_VAR_NOINIT_32BIT
# undef SSA_START_SEC_VAR_NOINIT_32BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SSA_STOP_SEC_VAR_NOINIT_32BIT
# undef SSA_STOP_SEC_VAR_NOINIT_32BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef SSA_START_SEC_VAR_ZERO_INIT_8BIT
# undef SSA_START_SEC_VAR_ZERO_INIT_8BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SSA_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SSA_STOP_SEC_VAR_ZERO_INIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SSA_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SSA_START_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SSA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SSA_STOP_SEC_VAR_NOINIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SSA END
 *********************************************************************************************************************/



/* PRQA L:MEMMAP_0841_TAG */


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/


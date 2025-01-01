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



/**********************************************************************************************************************
 *  CanSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CANSM_START_SEC_CODE
# undef CANSM_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif

#ifdef CANSM_STOP_SEC_CODE
# undef CANSM_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif


#ifdef CANSM_START_SEC_APPL_CODE
# undef CANSM_START_SEC_APPL_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif

#ifdef CANSM_STOP_SEC_APPL_CODE
# undef CANSM_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif
 


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */


#ifdef CANSM_START_SEC_CONST_8BIT
# undef CANSM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif

#ifdef CANSM_STOP_SEC_CONST_8BIT
# undef CANSM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#ifdef CANSM_START_SEC_CONST_32BIT
# undef CANSM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif

#ifdef CANSM_STOP_SEC_CONST_32BIT
# undef CANSM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif


#ifdef CANSM_START_SEC_CONST_UNSPECIFIED
# undef CANSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CANSM_STOP_SEC_CONST_UNSPECIFIED
# undef CANSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */
#ifdef CANSM_START_SEC_CONST_FAST_8BIT
# undef CANSM_START_SEC_CONST_FAST_8BIT
# define START_SEC_CONST_FAST_8BIT
#endif

#ifdef CANSM_STOP_SEC_CONST_FAST_8BIT
# undef CANSM_STOP_SEC_CONST_FAST_8BIT
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#ifdef CANSM_START_SEC_CONST_FAST_32BIT
# undef CANSM_START_SEC_CONST_FAST_32BIT
# define START_SEC_CONST_FAST_32BIT
#endif

#ifdef CANSM_STOP_SEC_CONST_FAST_32BIT
# undef CANSM_STOP_SEC_CONST_FAST_32BIT
# define STOP_SEC_CONST
#endif


#ifdef CANSM_START_SEC_CONST_FAST_UNSPECIFIED
# undef CANSM_START_SEC_CONST_FAST_UNSPECIFIED
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif

#ifdef CANSM_STOP_SEC_CONST_FAST_UNSPECIFIED
# undef CANSM_STOP_SEC_CONST_FAST_UNSPECIFIED
# define STOP_SEC_CONST
#endif



/* Postbuild CFG CONST sections */



/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */


/* VAR NOINIT sections */

#ifdef CANSM_START_SEC_VAR_NOINIT_8BIT
# undef CANSM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef CANSM_STOP_SEC_VAR_NOINIT_8BIT
# undef CANSM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif


#ifdef CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef CANSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef CANSM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR FAST INIT sections */

/* VAR FAST NOINIT sections */

#ifdef CANSM_START_SEC_VAR_FAST_NOINIT_8BIT
# undef CANSM_START_SEC_VAR_FAST_NOINIT_8BIT
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif

#ifdef CANSM_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef CANSM_STOP_SEC_VAR_FAST_NOINIT_8BIT
# define STOP_SEC_VAR
#endif


#ifdef CANSM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef CANSM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif

#ifdef CANSM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef CANSM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR FAST ZERO INIT sections */

#ifdef CANSM_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef CANSM_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif

#ifdef CANSM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef CANSM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif







/**********************************************************************************************************************
 *  CanSM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FrSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRSM_START_SEC_CODE
  #undef FRSM_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef FRSM_STOP_SEC_CODE
  #undef FRSM_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */



#ifdef FRSM_START_SEC_CONST_32BIT
# undef FRSM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef FRSM_STOP_SEC_CONST_32BIT
# undef FRSM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif


#ifdef FRSM_START_SEC_CONST_UNSPECIFIED
# undef FRSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FRSM_STOP_SEC_CONST_UNSPECIFIED
# undef FRSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */



/* Postbuild CFG CONST sections */

/* Root pointer to postbuild data */
#ifdef FRSM_START_SEC_PBCFG_ROOT
# undef FRSM_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRSM_STOP_SEC_PBCFG_ROOT
# undef FRSM_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/* Tables for postbuild data */
#ifdef FRSM_START_SEC_PBCFG
# undef FRSM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRSM_STOP_SEC_PBCFG
# undef FRSM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */


/* VAR NOINIT sections */

#ifdef FRSM_START_SEC_VAR_NOINIT_8BIT
# undef FRSM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef FRSM_STOP_SEC_VAR_NOINIT_8BIT
# undef FRSM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef FRSM_START_SEC_VAR_NOINIT_16BIT
# undef FRSM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef FRSM_STOP_SEC_VAR_NOINIT_16BIT
# undef FRSM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif


#ifdef FRSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FRSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef FRSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FRSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


#ifdef FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef FRSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef FRSM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef FRSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef FRSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/* VAR FAST INIT sections */


/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  FrSM END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  LINSM START
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef LINSM_START_SEC_CODE
# undef LINSM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef LINSM_STOP_SEC_CODE
# undef LINSM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef LINSM_START_SEC_CONST_8BIT
# undef LINSM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef LINSM_STOP_SEC_CONST_8BIT
# undef LINSM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef LINSM_START_SEC_CONST_UNSPECIFIED
# undef LINSM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef LINSM_STOP_SEC_CONST_UNSPECIFIED
# undef LINSM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#ifdef LINSM_START_SEC_PBCFG
# undef LINSM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef LINSM_STOP_SEC_PBCFG
# undef LINSM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef LINSM_START_SEC_VAR_NOINIT_8BIT
# undef LINSM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef LINSM_STOP_SEC_VAR_NOINIT_8BIT
# undef LINSM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef LINSM_START_SEC_VAR_NOINIT_16BIT
# undef LINSM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef LINSM_STOP_SEC_VAR_NOINIT_16BIT
# undef LINSM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef LINSM_START_SEC_VAR_NOINIT_32BIT
# undef LINSM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef LINSM_STOP_SEC_VAR_NOINIT_32BIT
# undef LINSM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef LINSM_START_SEC_VAR_NOINIT_64BIT
# undef LINSM_START_SEC_VAR_NOINIT_64BIT
# define START_SEC_VAR_NOINIT_64BIT
#endif
#ifdef LINSM_STOP_SEC_VAR_NOINIT_64BIT
# undef LINSM_STOP_SEC_VAR_NOINIT_64BIT
# define STOP_SEC_VAR
#endif

#ifdef LINSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef LINSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef LINSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef LINSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef LINSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef LINSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef LINSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef LINSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef LINSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef LINSM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef LINSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef LINSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  LINSM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHSM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined ETHSM_START_SEC_CODE
  #undef ETHSM_START_SEC_CODE                       /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#if defined ETHSM_STOP_SEC_CODE
  #undef ETHSM_STOP_SEC_CODE                        /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#if defined ETHSM_START_SEC_CONST_8BIT
# undef ETHSM_START_SEC_CONST_8BIT                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined ETHSM_STOP_SEC_CONST_8BIT
# undef ETHSM_STOP_SEC_CONST_8BIT                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined ETHSM_START_SEC_CONST_16BIT
# undef ETHSM_START_SEC_CONST_16BIT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined ETHSM_STOP_SEC_CONST_16BIT
# undef ETHSM_STOP_SEC_CONST_16BIT                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined ETHSM_START_SEC_CONST_32BIT
# undef ETHSM_START_SEC_CONST_32BIT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined ETHSM_STOP_SEC_CONST_32BIT
# undef ETHSM_STOP_SEC_CONST_32BIT                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined ETHSM_START_SEC_CONST_UNSPECIFIED
# undef ETHSM_START_SEC_CONST_UNSPECIFIED           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined ETHSM_STOP_SEC_CONST_UNSPECIFIED
# undef ETHSM_STOP_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined ETHSM_START_SEC_PBCFG
# undef ETHSM_START_SEC_PBCFG                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined ETHSM_STOP_SEC_PBCFG
# undef ETHSM_STOP_SEC_PBCFG                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined ETHSM_START_SEC_PBCFG_ROOT
# undef ETHSM_START_SEC_PBCFG_ROOT                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined ETHSM_STOP_SEC_PBCFG_ROOT
# undef ETHSM_STOP_SEC_PBCFG_ROOT                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#if defined ETHSM_START_SEC_VAR_NOINIT_8BIT
# undef ETHSM_START_SEC_VAR_NOINIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHSM_STOP_SEC_VAR_NOINIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_NOINIT_16BIT
# undef ETHSM_START_SEC_VAR_NOINIT_16BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHSM_STOP_SEC_VAR_NOINIT_16BIT             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_NOINIT_32BIT
# undef ETHSM_START_SEC_VAR_NOINIT_32BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHSM_STOP_SEC_VAR_NOINIT_32BIT             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHSM_START_SEC_VAR_NOINIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined ETHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_INIT_8BIT
# undef ETHSM_START_SEC_VAR_INIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_INIT_8BIT
# undef ETHSM_STOP_SEC_VAR_INIT_8BIT                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_INIT_16BIT
# undef ETHSM_START_SEC_VAR_INIT_16BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_INIT_16BIT
# undef ETHSM_STOP_SEC_VAR_INIT_16BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_INIT_32BIT
# undef ETHSM_START_SEC_VAR_INIT_32BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_INIT_32BIT
# undef ETHSM_STOP_SEC_VAR_INIT_32BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_INIT_UNSPECIFIED
# undef ETHSM_START_SEC_VAR_INIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined ETHSM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef ETHSM_STOP_SEC_VAR_INIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHSM_START_SEC_VAR_ZERO_INIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHSM_STOP_SEC_VAR_ZERO_INIT_8BIT           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_ZERO_INIT_16BIT
# undef ETHSM_START_SEC_VAR_ZERO_INIT_16BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef ETHSM_STOP_SEC_VAR_ZERO_INIT_16BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_ZERO_INIT_32BIT
# undef ETHSM_START_SEC_VAR_ZERO_INIT_32BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined ETHSM_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef ETHSM_STOP_SEC_VAR_ZERO_INIT_32BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined ETHSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined ETHSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHSM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CDDDES START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CDDDES_START_SEC_CODE)
# undef CDDDES_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CDDDES_STOP_SEC_CODE)
# undef CDDDES_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CDDDES_START_SEC_CONST_UNSPECIFIED)
# undef CDDDES_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CDDDES_STOP_SEC_CONST_UNSPECIFIED)
# undef CDDDES_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CDDDES_START_SEC_CONST_8BIT)
# undef CDDDES_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined(CDDDES_STOP_SEC_CONST_8BIT)
# undef CDDDES_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CDDDES_START_SEC_VAR_INIT_8BIT)
# undef CDDDES_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CDDDES_STOP_SEC_VAR_INIT_8BIT)
# undef CDDDES_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

/* VAR NOINIT sections */

#if defined(CDDDES_START_SEC_VAR_NOINIT_8BIT)
# undef CDDDES_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CDDDES_STOP_SEC_VAR_NOINIT_8BIT)
# undef CDDDES_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CDDDES_START_SEC_VAR_NOINIT_16BIT)
# undef CDDDES_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CDDDES_STOP_SEC_VAR_NOINIT_16BIT)
# undef CDDDES_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CDDDES_START_SEC_VAR_NOINIT_32BIT)
# undef CDDDES_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CDDDES_STOP_SEC_VAR_NOINIT_32BIT)
# undef CDDDES_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CDDDES_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CDDDES_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CDDDES_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CDDDES_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CDDDES END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VX1000HOOKIF START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VX1000HOOKIF_START_SEC_CODE)
# undef VX1000HOOKIF_START_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                   /* mapped to default code section */
#endif
#if defined(VX1000HOOKIF_STOP_SEC_CODE)
# undef VX1000HOOKIF_STOP_SEC_CODE        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                    /* default code stop section */
#endif

/* VAR ZERO INIT sections */

#if defined(VX1000HOOKIF_START_SEC_VAR_ZERO_INIT_8BIT)
# undef VX1000HOOKIF_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(VX1000HOOKIF_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef VX1000HOOKIF_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VX1000HOOKIF END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VX1000IF START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VX1000IF_START_SEC_CODE)
# undef VX1000IF_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         	                      /* mapped to default code section */
#endif
#if defined(VX1000IF_STOP_SEC_CODE)
# undef VX1000IF_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          	                      /* default code stop section */
#endif

/* VAR ZERO INIT sections */

#if defined(VX1000IF_START_SEC_VAR_ZERO_INIT_8BIT)
# undef VX1000IF_START_SEC_VAR_ZERO_INIT_8BIT           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(VX1000IF_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef VX1000IF_STOP_SEC_VAR_ZERO_INIT_8BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VX1000IF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VX1000IF_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VX1000IF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VX1000IF_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VX1000IF_START_SEC_CONST_UNSPECIFIED
# undef VX1000IF_START_SEC_CONST_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VX1000IF_STOP_SEC_CONST_UNSPECIFIED
# undef VX1000IF_STOP_SEC_CONST_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  VX1000IF END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VX1000TLIF START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VX1000TLIF_START_SEC_CODE)
# undef VX1000TLIF_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         	                        /* mapped to default code section */
#endif
#if defined(VX1000TLIF_STOP_SEC_CODE)
# undef VX1000TLIF_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          	                        /* default code stop section */
#endif

/* VAR ZERO INIT sections */

#if defined(VX1000TLIF_START_SEC_VAR_ZERO_INIT_8BIT)
# undef VX1000TLIF_START_SEC_VAR_ZERO_INIT_8BIT           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(VX1000TLIF_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef VX1000TLIF_STOP_SEC_VAR_ZERO_INIT_8BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VX1000TLIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VX1000TLIF_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VX1000TLIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VX1000TLIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VX1000TLIF_START_SEC_CONST_UNSPECIFIED
# undef VX1000TLIF_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VX1000TLIF_STOP_SEC_CONST_UNSPECIFIED
# undef VX1000TLIF_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  VX1000TLIF END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  VFSMLIB START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef VFSMLIB_START_SEC_CODE
# undef VFSMLIB_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef VFSMLIB_STOP_SEC_CODE
# undef VFSMLIB_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef VFSMLIB_START_SEC_CONST_8BIT
# undef VFSMLIB_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_8BIT
#endif
#ifdef VFSMLIB_STOP_SEC_CONST_8BIT
# undef VFSMLIB_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VFSMLIB_START_SEC_CONST_16BIT
# undef VFSMLIB_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_16BIT
#endif
#ifdef VFSMLIB_STOP_SEC_CONST_16BIT
# undef VFSMLIB_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VFSMLIB_START_SEC_CONST_32BIT
# undef VFSMLIB_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_32BIT
#endif
#ifdef VFSMLIB_STOP_SEC_CONST_32BIT
# undef VFSMLIB_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VFSMLIB_START_SEC_CONST_UNSPECIFIED
# undef VFSMLIB_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VFSMLIB_STOP_SEC_CONST_UNSPECIFIED
# undef VFSMLIB_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef VFSMLIB_START_SEC_VAR_NOINIT_8BIT
# undef VFSMLIB_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef VFSMLIB_STOP_SEC_VAR_NOINIT_8BIT
# undef VFSMLIB_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_VAR
#endif

#ifdef VFSMLIB_START_SEC_VAR_NOINIT_16BIT
# undef VFSMLIB_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef VFSMLIB_STOP_SEC_VAR_NOINIT_16BIT
# undef VFSMLIB_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFSMLIB_START_SEC_VAR_NOINIT_32BIT
# undef VFSMLIB_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef VFSMLIB_STOP_SEC_VAR_NOINIT_32BIT
# undef VFSMLIB_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFSMLIB_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VFSMLIB_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VFSMLIB_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VFSMLIB_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef VFSMLIB_START_SEC_VAR_ZERO_INIT_8BIT
# undef VFSMLIB_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef VFSMLIB_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VFSMLIB_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFSMLIB_START_SEC_VAR_ZERO_INIT_16BIT
# undef VFSMLIB_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef VFSMLIB_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef VFSMLIB_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFSMLIB_START_SEC_VAR_ZERO_INIT_32BIT
# undef VFSMLIB_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef VFSMLIB_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef VFSMLIB_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFSMLIB_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VFSMLIB_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef VFSMLIB_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VFSMLIB_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFSMLIB_START_SEC_PBCFG
# undef VFSMLIB_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_PBCFG
#endif
#ifdef VFSMLIB_STOP_SEC_PBCFG
# undef VFSMLIB_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_CONST
#endif

/* VAR INIT sections */
#ifdef VFSMLIB_START_SEC_VAR_INIT_8BIT
# undef VFSMLIB_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_INIT_8BIT
#endif
#ifdef VFSMLIB_STOP_SEC_VAR_INIT_8BIT
# undef VFSMLIB_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFSMLIB_START_SEC_VAR_INIT_16BIT
# undef VFSMLIB_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef VFSMLIB_STOP_SEC_VAR_INIT_16BIT
# undef VFSMLIB_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFSMLIB_START_SEC_VAR_INIT_32BIT
# undef VFSMLIB_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef VFSMLIB_STOP_SEC_VAR_INIT_32BIT
# undef VFSMLIB_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VFSMLIB_START_SEC_VAR_INIT_UNSPECIFIED
# undef VFSMLIB_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef VFSMLIB_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef VFSMLIB_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  VFSMLIB END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  CCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CCP_START_SEC_CODE 
    #undef CCP_START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef CCP_STOP_SEC_CODE 
    #undef CCP_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CCP_START_SEC_PBCFG
    #undef CCP_START_SEC_PBCFG
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CCP_STOP_SEC_PBCFG
    #undef CCP_STOP_SEC_PBCFG
    #define STOP_SEC_CONST
#endif

#ifdef CCP_START_SEC_CONST_UNSPECIFIED
    #undef CCP_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef CCP_STOP_SEC_CONST_UNSPECIFIED
    #undef CCP_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif

#ifdef CCP_START_SEC_CONST_8BIT 
    #undef CCP_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef CCP_STOP_SEC_CONST_8BIT 
    #undef CCP_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef CCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef CCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef CCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef CCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef CCP_START_SEC_VAR_ZERO_INIT_8BIT 
    #undef CCP_START_SEC_VAR_ZERO_INIT_8BIT 
    #define START_SEC_VAR_ZERO_INIT_8BIT
#endif

#ifdef CCP_STOP_SEC_VAR_ZERO_INIT_8BIT 
    #undef CCP_STOP_SEC_VAR_ZERO_INIT_8BIT 
    #define STOP_SEC_VAR
#endif

#ifdef CCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE
    #undef CCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef CCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #undef CCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  CCP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  XCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(XCP_START_SEC_CODE)
# undef XCP_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(XCP_STOP_SEC_CODE)
# undef XCP_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(XCP_START_SEC_CONST_8BIT)
# undef XCP_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(XCP_STOP_SEC_CONST_8BIT)
# undef XCP_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(XCP_START_SEC_CONST_16BIT)
# undef XCP_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(XCP_STOP_SEC_CONST_16BIT)
# undef XCP_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(XCP_START_SEC_CONST_32BIT)
# undef XCP_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(XCP_STOP_SEC_CONST_32BIT)
# undef XCP_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(XCP_START_SEC_CONST_UNSPECIFIED)
# undef XCP_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_CONST_UNSPECIFIED)
# undef XCP_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(XCP_START_SEC_PBCFG)
# undef XCP_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(XCP_STOP_SEC_PBCFG)
# undef XCP_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(XCP_START_SEC_VAR_INIT_8BIT)
# undef XCP_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(XCP_STOP_SEC_VAR_INIT_8BIT)
# undef XCP_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(XCP_START_SEC_VAR_INIT_16BIT)
# undef XCP_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_INIT_16BIT)
# undef XCP_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_INIT_32BIT)
# undef XCP_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_INIT_32BIT)
# undef XCP_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_INIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(XCP_START_SEC_VAR_NOINIT_8BIT)
# undef XCP_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOINIT_8BIT)
# undef XCP_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOINIT_16BIT)
# undef XCP_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOINIT_16BIT)
# undef XCP_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOINIT_32BIT)
# undef XCP_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOINIT_32BIT)
# undef XCP_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(XCP_START_SEC_VAR_PBCFG)
# undef XCP_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(XCP_STOP_SEC_VAR_PBCFG)
# undef XCP_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(XCP_START_SEC_VAR_ZERO_INIT_8BIT)
# undef XCP_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef XCP_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_ZERO_INIT_16BIT)
# undef XCP_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef XCP_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_ZERO_INIT_32BIT)
# undef XCP_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef XCP_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOCACHE INIT sections */

#if defined(XCP_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef XCP_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef XCP_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef XCP_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(XCP_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef XCP_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef XCP_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef XCP_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef XCP_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef XCP_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR Safe sections */
#if defined (XCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE)
# undef XCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined (XCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE)
# undef XCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  XCP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANXCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CANXCP_START_SEC_CODE
  #undef CANXCP_START_SEC_CODE                      /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif

#ifdef CANXCP_STOP_SEC_CODE
  #undef CANXCP_STOP_SEC_CODE                       /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CANXCP_START_SEC_CONST_8BIT
  #undef CANXCP_START_SEC_CONST_8BIT                /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_8BIT                      /* mapped to const 8 bit section */
#endif

#ifdef CANXCP_STOP_SEC_CONST_8BIT
  #undef CANXCP_STOP_SEC_CONST_8BIT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST                            /* default const stop section */
#endif

#ifdef CANXCP_START_SEC_CONST_UNSPECIFIED
  #undef CANXCP_START_SEC_CONST_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_UNSPECIFIED               /* mapped to const unspecified bit section */
#endif

#ifdef CANXCP_STOP_SEC_CONST_UNSPECIFIED
  #undef CANXCP_STOP_SEC_CONST_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST                            /* default const stop section */
#endif


/* Post build config unspecified */

#ifdef CANXCP_START_SEC_PBCFG_ROOT
  #undef CANXCP_START_SEC_PBCFG_ROOT                /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_PBCFG                     /* mapped to const unspecified section */
#endif

#ifdef CANXCP_STOP_SEC_PBCFG_ROOT
  #undef CANXCP_STOP_SEC_PBCFG_ROOT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST                            /* default const stop section */
#endif


#ifdef CANXCP_START_SEC_PBCFG
  #undef CANXCP_START_SEC_PBCFG                     /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_PBCFG                     /* mapped to const unspecified section */
#endif

#ifdef CANXCP_STOP_SEC_PBCFG
  #undef CANXCP_STOP_SEC_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST                            /* default const stop section */
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef CANXCP_START_SEC_VAR_INIT_8BIT
  #undef CANXCP_START_SEC_VAR_INIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_VAR_INIT_8BIT                   /* mapped to uninitialized RAM 8bit section */
#endif

#ifdef CANXCP_STOP_SEC_VAR_INIT_8BIT
  #undef CANXCP_STOP_SEC_VAR_INIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_VAR                              /* default RAM stop section */
#endif


#ifdef CANXCP_START_SEC_VAR_NOINIT_8BIT
  #undef CANXCP_START_SEC_VAR_NOINIT_8BIT           /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_VAR_NOINIT_8BIT                 /* mapped to uninitialized RAM 8bit section */
#endif

#ifdef CANXCP_STOP_SEC_VAR_NOINIT_8BIT
  #undef CANXCP_STOP_SEC_VAR_NOINIT_8BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_VAR                              /* default RAM stop section */
#endif


#ifdef CANXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef CANXCP_START_SEC_VAR_NOINIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_VAR_NOINIT_UNSPECIFIED          /* mapped to uninitialized RAM unspecified section */
#endif

#ifdef CANXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef CANXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_VAR                              /* default RAM stop section */
#endif


#ifdef CANXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #undef CANXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef CANXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #undef CANXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANXCP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FRXCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRXCP_START_SEC_CODE 
    #undef FRXCP_START_SEC_CODE                 /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CODE
#endif

#ifdef FRXCP_STOP_SEC_CODE 
    #undef FRXCP_STOP_SEC_CODE                  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRXCP_START_SEC_CONST_UNSPECIFIED 
    #undef FRXCP_START_SEC_CONST_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FRXCP_STOP_SEC_CONST_UNSPECIFIED 
    #undef FRXCP_STOP_SEC_CONST_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST
#endif

#ifdef FRXCP_START_SEC_CONST_16BIT 
    #undef FRXCP_START_SEC_CONST_16BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_16BIT
#endif

#ifdef FRXCP_STOP_SEC_CONST_16BIT 
    #undef FRXCP_STOP_SEC_CONST_16BIT           /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST
#endif

#ifdef FRXCP_START_SEC_CONST_8BIT 
    #undef FRXCP_START_SEC_CONST_8BIT           /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_8BIT
#endif

#ifdef FRXCP_STOP_SEC_CONST_8BIT 
    #undef FRXCP_STOP_SEC_CONST_8BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST
#endif

#ifdef FRXCP_START_SEC_PBCFG
    #undef FRXCP_START_SEC_PBCFG                /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_PBCFG
#endif

#ifdef FRXCP_STOP_SEC_PBCFG
    #undef FRXCP_STOP_SEC_PBCFG                 /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRXCP_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef FRXCP_START_SEC_VAR_NOINIT_8BIT 
    #undef FRXCP_START_SEC_VAR_NOINIT_8BIT      /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef FRXCP_STOP_SEC_VAR_NOINIT_8BIT 
    #undef FRXCP_STOP_SEC_VAR_NOINIT_8BIT       /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef FRXCP_START_SEC_VAR_PBCFG
    #undef FRXCP_START_SEC_VAR_PBCFG            /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_PBCFG
#endif

#ifdef FRXCP_STOP_SEC_VAR_PBCFG
    #undef FRXCP_STOP_SEC_VAR_PBCFG             /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef FRXCP_START_SEC_VAR_INIT_8BIT 
    #undef FRXCP_START_SEC_VAR_INIT_8BIT        /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_INIT_8BIT
#endif

#ifdef FRXCP_STOP_SEC_VAR_INIT_8BIT 
    #undef FRXCP_STOP_SEC_VAR_INIT_8BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef FRXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #undef FRXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef FRXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #undef FRXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FRXCP END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  TCPIPXCP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef TCPIPXCP_START_SEC_CODE
  #undef TCPIPXCP_START_SEC_CODE                    /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif

#ifdef TCPIPXCP_STOP_SEC_CODE
  #undef TCPIPXCP_STOP_SEC_CODE                     /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef TCPIPXCP_START_SEC_CONST_8BIT
  #undef TCPIPXCP_START_SEC_CONST_8BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_8BIT                      /* mapped to const 8 bit section */
#endif

#ifdef TCPIPXCP_STOP_SEC_CONST_8BIT
  #undef TCPIPXCP_STOP_SEC_CONST_8BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST                            /* default const stop section */
#endif

#ifdef TCPIPXCP_START_SEC_CONST_UNSPECIFIED
  #undef TCPIPXCP_START_SEC_CONST_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_UNSPECIFIED               /* mapped to const unspecified bit section */
#endif

#ifdef TCPIPXCP_STOP_SEC_CONST_UNSPECIFIED
  #undef TCPIPXCP_STOP_SEC_CONST_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST                            /* default const stop section */
#endif


/* Post build config unspecified */

#ifdef TCPIPXCP_START_SEC_PBCFG_ROOT
  #undef TCPIPXCP_START_SEC_PBCFG_ROOT              /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_PBCFG                     /* mapped to const unspecified section */
#endif

#ifdef TCPIPXCP_STOP_SEC_PBCFG_ROOT
  #undef TCPIPXCP_STOP_SEC_PBCFG_ROOT               /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST                            /* default const stop section */
#endif


#ifdef TCPIPXCP_START_SEC_PBCFG
  #undef TCPIPXCP_START_SEC_PBCFG                   /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_PBCFG                     /* mapped to const unspecified section */
#endif

#ifdef TCPIPXCP_STOP_SEC_PBCFG
  #undef TCPIPXCP_STOP_SEC_PBCFG                    /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST                            /* default const stop section */
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */
#ifdef TCPIPXCP_START_SEC_VAR_NOINIT_8BIT
  #undef TCPIPXCP_START_SEC_VAR_NOINIT_8BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_VAR_NOINIT_8BIT                 /* mapped to uninitialized RAM 8bit section */
#endif

#ifdef TCPIPXCP_STOP_SEC_VAR_NOINIT_8BIT
  #undef TCPIPXCP_STOP_SEC_VAR_NOINIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_VAR                              /* default RAM stop section */
#endif

#ifdef TCPIPXCP_START_SEC_VAR_NOINIT_16BIT
  #undef TCPIPXCP_START_SEC_VAR_NOINIT_16BIT        /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_VAR_NOINIT_16BIT                /* mapped to uninitialized RAM 8bit section */
#endif

#ifdef TCPIPXCP_STOP_SEC_VAR_NOINIT_16BIT
  #undef TCPIPXCP_STOP_SEC_VAR_NOINIT_16BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_VAR                              /* default RAM stop section */
#endif

/* Var noinit unspecified */
#ifdef TCPIPXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
  #undef TCPIPXCP_START_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_VAR_NOINIT_UNSPECIFIED          /* mapped to uninitialized RAM unspecified section */
#endif

#ifdef TCPIPXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #undef TCPIPXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_VAR                              /* default RAM stop section */
#endif

/* VAR INIT sections */
#ifdef TCPIPXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #undef TCPIPXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef TCPIPXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE 
    #undef TCPIPXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef TCPIPXCP_START_SEC_VAR_INIT_8BIT
  #undef TCPIPXCP_START_SEC_VAR_INIT_8BIT           /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_VAR_INIT_8BIT                   /* mapped to initialized RAM 8bit section */
#endif

#ifdef TCPIPXCP_STOP_SEC_VAR_INIT_8BIT
  #undef TCPIPXCP_STOP_SEC_VAR_INIT_8BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_VAR                              /* default RAM stop section */
#endif

/**********************************************************************************************************************
 *  TCPIPXCP END
 *********************************************************************************************************************/

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



/**********************************************************************************************************************
 *  J1939DCM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef J1939DCM_START_SEC_CODE
# undef J1939DCM_START_SEC_CODE                                                                                                                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef J1939DCM_STOP_SEC_CODE
# undef J1939DCM_STOP_SEC_CODE                                                                                                                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE      /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/*! CONST sections */

#ifdef J1939DCM_START_SEC_CONST_8BIT
# undef J1939DCM_START_SEC_CONST_8BIT                                                                                                                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef J1939DCM_STOP_SEC_CONST_8BIT
# undef J1939DCM_STOP_SEC_CONST_8BIT                                                                                                                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef J1939DCM_START_SEC_CONST_16BIT
# undef J1939DCM_START_SEC_CONST_16BIT                                                                                                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef J1939DCM_STOP_SEC_CONST_16BIT
# undef J1939DCM_STOP_SEC_CONST_16BIT                                                                                                                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef J1939DCM_START_SEC_CONST_32BIT
# undef J1939DCM_START_SEC_CONST_32BIT                                                                                                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef J1939DCM_STOP_SEC_CONST_32BIT
# undef J1939DCM_STOP_SEC_CONST_32BIT                                                                                                                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef J1939DCM_START_SEC_CONST_UNSPECIFIED
# undef J1939DCM_START_SEC_CONST_UNSPECIFIED                                                                                                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef J1939DCM_STOP_SEC_CONST_UNSPECIFIED
# undef J1939DCM_STOP_SEC_CONST_UNSPECIFIED                                                                                                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*! Postbuild CFG CONST sections */

#ifdef J1939DCM_START_SEC_PBCFG
# undef J1939DCM_START_SEC_PBCFG                                                                                                                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef J1939DCM_STOP_SEC_PBCFG
# undef J1939DCM_STOP_SEC_PBCFG                                                                                                                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef J1939DCM_START_SEC_PBCFG_ROOT
# undef J1939DCM_START_SEC_PBCFG_ROOT                                                                                                                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef J1939DCM_STOP_SEC_PBCFG_ROOT
# undef J1939DCM_STOP_SEC_PBCFG_ROOT                                                                                                                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/*! VAR INIT sections */

#ifdef J1939DCM_START_SEC_VAR_INIT_8BIT
# undef J1939DCM_START_SEC_VAR_INIT_8BIT                                                                                                             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef J1939DCM_STOP_SEC_VAR_INIT_8BIT
# undef J1939DCM_STOP_SEC_VAR_INIT_8BIT                                                                                                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef J1939DCM_START_SEC_VAR_INIT_16BIT
# undef J1939DCM_START_SEC_VAR_INIT_16BIT                                                                                                            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef J1939DCM_STOP_SEC_VAR_INIT_16BIT
# undef J1939DCM_STOP_SEC_VAR_INIT_16BIT                                                                                                             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef J1939DCM_START_SEC_VAR_INIT_32BIT
# undef J1939DCM_START_SEC_VAR_INIT_32BIT                                                                                                            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef J1939DCM_STOP_SEC_VAR_INIT_32BIT
# undef J1939DCM_STOP_SEC_VAR_INIT_32BIT                                                                                                             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef J1939DCM_START_SEC_VAR_INIT_UNSPECIFIED
# undef J1939DCM_START_SEC_VAR_INIT_UNSPECIFIED                                                                                                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef J1939DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef J1939DCM_STOP_SEC_VAR_INIT_UNSPECIFIED                                                                                                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/*! VAR NOINIT sections */

#ifdef J1939DCM_START_SEC_VAR_NOINIT_8BIT
# undef J1939DCM_START_SEC_VAR_NOINIT_8BIT                                                                                                           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef J1939DCM_STOP_SEC_VAR_NOINIT_8BIT
# undef J1939DCM_STOP_SEC_VAR_NOINIT_8BIT                                                                                                            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef J1939DCM_START_SEC_VAR_NOINIT_16BIT
# undef J1939DCM_START_SEC_VAR_NOINIT_16BIT                                                                                                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef J1939DCM_STOP_SEC_VAR_NOINIT_16BIT
# undef J1939DCM_STOP_SEC_VAR_NOINIT_16BIT                                                                                                           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef J1939DCM_START_SEC_VAR_NOINIT_32BIT
# undef J1939DCM_START_SEC_VAR_NOINIT_32BIT                                                                                                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef J1939DCM_STOP_SEC_VAR_NOINIT_32BIT
# undef J1939DCM_STOP_SEC_VAR_NOINIT_32BIT                                                                                                           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef J1939DCM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef J1939DCM_START_SEC_VAR_NOINIT_UNSPECIFIED                                                                                                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef J1939DCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef J1939DCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED                                                                                                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/*! ESCAN00065501 */
#ifdef J1939DCM_START_SEC_VAR_PBCFG
# undef J1939DCM_START_SEC_VAR_PBCFG                                                                                                                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef J1939DCM_STOP_SEC_VAR_PBCFG
# undef J1939DCM_STOP_SEC_VAR_PBCFG                                                                                                                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  J1939DCM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CRYPTO_30_VHSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CRYPTO_30_VHSM_START_SEC_CODE
# undef CRYPTO_30_VHSM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_CODE
# undef CRYPTO_30_VHSM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef CRYPTO_30_VHSM_START_SEC_APPL_CODE
# undef CRYPTO_30_VHSM_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_APPL_CODE
# undef CRYPTO_30_VHSM_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef CRYPTO_30_VHSM_START_SEC_CODE_ISR
# undef CRYPTO_30_VHSM_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR                                           /* mapped to default code section */
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_CODE_ISR
# undef CRYPTO_30_VHSM_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef CRYPTO_30_VHSM_START_SEC_RAMCODE
# undef CRYPTO_30_VHSM_START_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define CODE_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

  /* Move section to RAM on platforms which need this. */
# if defined(__ghs__) && defined (__RH850__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section text=".vHsmRamCode"
# endif
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_RAMCODE
# undef CRYPTO_30_VHSM_STOP_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef CODE_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

  /* Move section to RAM on platforms which need this. */
# if defined(__ghs__) && defined (__RH850__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section text=default
# endif
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CRYPTO_30_VHSM_START_SEC_CONST_8BIT /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
# undef CRYPTO_30_VHSM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_CONST_8BIT
# undef CRYPTO_30_VHSM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_30_VHSM_START_SEC_CONST_16BIT /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
# undef CRYPTO_30_VHSM_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_CONST_16BIT
# undef CRYPTO_30_VHSM_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_30_VHSM_START_SEC_CONST_32BIT /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
# undef CRYPTO_30_VHSM_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_CONST_32BIT
# undef CRYPTO_30_VHSM_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
# undef CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
# undef CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */
#ifdef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
# undef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define VAR_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
#  pragma ghs section sbss=".svHsmGlobalRamBuffer"
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmGlobalRamBuffer"
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmGlobalRamBuffer" aw 4
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ".vHsmGlobalRamBuffer"
# elif defined(__TI_COMPILER_VERSION__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma SET_DATA_SECTION(".vHsmGlobalRamBuffer")
# endif
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
# undef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef VAR_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
#  pragma ghs section sbss=default
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all restore
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ""
# elif defined(__TI_COMPILER_VERSION__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma SET_DATA_SECTION()
# endif
#endif

#ifdef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_64BIT
# undef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define VAR_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
#  pragma ghs section sbss=".svHsmGlobalRamBuffer"
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmGlobalRamBuffer"
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmGlobalRamBuffer" aw 4
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ".vHsmGlobalRamBuffer"
# elif defined(__TI_COMPILER_VERSION__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma SET_DATA_SECTION(".vHsmGlobalRamBuffer")
# endif
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_64BIT
# undef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef VAR_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
#  pragma ghs section sbss=default
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all restore
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ""
# elif defined(__TI_COMPILER_VERSION__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma SET_DATA_SECTION()
# endif
#endif

#ifdef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define VAR_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmGlobalRamBuffer"
#  pragma ghs section sbss=".svHsmGlobalRamBuffer"
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmGlobalRamBuffer"
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmGlobalRamBuffer" aw 4
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg(".vHsmGlobalRamBuffer") /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ".vHsmGlobalRamBuffer"
# elif defined(__TI_COMPILER_VERSION__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma SET_DATA_SECTION(".vHsmGlobalRamBuffer")
# endif
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
# undef CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef VAR_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

  /* Move section to global RAM on platforms which need this. */
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
#  pragma ghs section sbss=default
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all restore
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ""
# elif defined(__TI_COMPILER_VERSION__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma SET_DATA_SECTION()
# endif
#endif

#ifdef CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# undef CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define VAR_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

  /* Move section to the same memory which is used by the vHsm as IPC memory */
# if defined(__DCC__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section VHSMIPCMEMORY ".bss" ".vHsmIpcMemory" far-absolute
#  if defined( VHSMIPCMEMORY_USESECTION ) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  else
#   pragma use_section VHSMIPCMEMORY Crypto_30_vHsm_Ipc_Memory
#   define VHSMIPCMEMORY_USESECTION
#  endif
# endif
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmIpcMemory"
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmIpcMemory"
#  pragma ghs section sbss=".svHsmIpcMemory"
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmIpcMemory"
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmIpcMemory" aw 4
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg(".vHsmIpcMemory") /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg(".vHsmIpcMemory") /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ".vHsmIpcMemory"
# elif defined(__TI_COMPILER_VERSION__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma SET_DATA_SECTION(".vHsmIpcMemory")
# endif
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# undef CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef VAR_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef  */

  /* Move section to the same memory which is used by the vHsm as IPC memory */
# if defined(__DCC__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section BSS
# endif
# if defined(__ghs__) && (defined(__CORE_CORTEXM4__) || defined(__CORE_CORTEXM4F__) || defined(__CORE_CORTEXM7__)) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# elif defined(__ghs__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
#  pragma ghs section sbss=default
# elif defined(__TASKING__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section all restore
# elif defined(_GNU_C_TRICORE_) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# elif defined(_MSC_VER) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma data_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
#  pragma bss_seg() /* PRQA S 3116 */ /* MD_MSR_Pragma */
# elif defined(__arm__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma clang section bss = ""
# elif defined(__TI_COMPILER_VERSION__) /* COV_CRYPTO_30_VHSM_MEMMAP_EXAMPLE */
#  pragma SET_DATA_SECTION()
# endif
#endif

#ifdef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT
# undef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT
# undef CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef CRYPTO_30_VHSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef CRYPTO_30_VHSM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CRYPTO_30_VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CRYPTO_30_VHSM END
 *********************************************************************************************************************/



/***********************************************************************************************************************
 *  EEP_30_VMEMACCM START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef EEP_30_VMEMACCM_START_SEC_CODE
# undef EEP_30_VMEMACCM_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef EEP_30_VMEMACCM_STOP_SEC_CODE
# undef EEP_30_VMEMACCM_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */


/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */

#ifdef EEP_30_VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED
# undef EEP_30_VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef EEP_30_VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef EEP_30_VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  EEP_30_VMEMACCM END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  FLS_30_VMEMACCM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(FLS_30_VMEMACCM_START_SEC_CODE)
# undef FLS_30_VMEMACCM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(FLS_30_VMEMACCM_STOP_SEC_CODE)
# undef FLS_30_VMEMACCM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#ifdef FLS_30_VMEMACCM_START_SEC_CONST_UNSPECIFIED
# undef FLS_30_VMEMACCM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FLS_30_VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
# undef FLS_30_VMEMACCM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/


#ifdef FLS_30_VMEMACCM_START_SEC_VAR_NO_INIT_RAM_BUFFER
/* Non-standard MemMap section for internal write buffer, which will be forwarded to the vMemAccM if RAM alignment
 * feature is enabled. Depending on hardware restrictions, this buffer might have to be aligned to prevent unaligned
 * memory access exceptions. */
# undef FLS_30_VMEMACCM_START_SEC_VAR_NO_INIT_RAM_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_64 
#endif
#ifdef FLS_30_VMEMACCM_STOP_SEC_VAR_NO_INIT_RAM_BUFFER
# undef FLS_30_VMEMACCM_STOP_SEC_VAR_NO_INIT_RAM_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef FLS_30_VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED
# undef FLS_30_VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FLS_30_VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FLS_30_VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(FLS_30_VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef FLS_30_VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED        /* mapped to default variable section */
#endif
#if defined(FLS_30_VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef FLS_30_VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR          /* default variable stop section */
#endif
/**********************************************************************************************************************
 *  FLS_30_VMEMACCM END
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
 *  VMEM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_BLOCKING_START_SEC_CODE)
# undef VMEM_30_BLOCKING_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef  */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_BLOCKING_STOP_SEC_CODE)
# undef VMEM_30_BLOCKING_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef  */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_BLOCKING_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_BLOCKING_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef  */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_BLOCKING_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_BLOCKING_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef  */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_BLOCKING_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_BLOCKING_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_BLOCKING_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_BLOCKING_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_BLOCKING_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_BLOCKING_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_BLOCKING_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_BLOCKING_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */
/* ... none ... */

/* VAR ZERO INIT sections */
#ifdef VMEM_30_BLOCKING_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VMEM_30_BLOCKING_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef  */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef VMEM_30_BLOCKING_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VMEM_30_BLOCKING_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef  */
# define STOP_SEC_VAR
#endif


/* VAR INIT sections */
/* ... none ... */

/**********************************************************************************************************************
 *  VMEM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM_30_EEP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_EEP_START_SEC_CODE)
# undef VMEM_30_EEP_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_EEP_STOP_SEC_CODE)
# undef VMEM_30_EEP_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_EEP_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_EEP_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_EEP_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_EEP_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_EEP_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_EEP_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_EEP_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_EEP_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_EEP_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_EEP_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_EEP_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_EEP_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

/* VAR ZERO INIT sections */
#if defined VMEM_30_EEP_START_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_EEP_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined VMEM_30_EEP_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_EEP_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */

/**********************************************************************************************************************
 *  VMEM_30_EEP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM_30_FLS START
 *********************************************************************************************************************/


/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_FLS_START_SEC_CODE)
# undef VMEM_30_FLS_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_FLS_STOP_SEC_CODE)
# undef VMEM_30_FLS_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#ifdef VMEM_30_FLS_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_FLS_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VMEM_30_FLS_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_FLS_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_FLS_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_FLS_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_FLS_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_FLS_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_FLS_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_FLS_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_FLS_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_FLS_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

/* VAR ZERO INIT sections */
#ifdef VMEM_30_FLS_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VMEM_30_FLS_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef VMEM_30_FLS_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VMEM_30_FLS_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  VMEM_30_FLS END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM_30_MMFLASHRO START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_MMFLASHRO_START_SEC_CODE)
# undef VMEM_30_MMFLASHRO_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_MMFLASHRO_STOP_SEC_CODE)
# undef VMEM_30_MMFLASHRO_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_MMFLASHRO_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_MMFLASHRO_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_MMFLASHRO_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_MMFLASHRO_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_MMFLASHRO_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_MMFLASHRO_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_MMFLASHRO_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_MMFLASHRO_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_MMFLASHRO_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_MMFLASHRO_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_MMFLASHRO_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_MMFLASHRO_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

/* VAR ZERO INIT sections  */

/* VAR INIT sections */
#if defined VMEM_30_MMFLASHRO_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_MMFLASHRO_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined VMEM_30_MMFLASHRO_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_MMFLASHRO_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VMEM_30_MMFLASHRO END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM_30_XXRAM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_XXRAM_START_SEC_CODE)
# undef VMEM_30_XXRAM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_XXRAM_STOP_SEC_CODE)
# undef VMEM_30_XXRAM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_XXRAM_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_XXRAM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_XXRAM_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_XXRAM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_XXRAM_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_XXRAM_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_XXRAM_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_XXRAM_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_XXRAM_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_XXRAM_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_XXRAM_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_XXRAM_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

/* VAR ZERO INIT sections */
#if defined VMEM_30_XXRAM_START_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_XXRAM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined VMEM_30_XXRAM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_XXRAM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */
#if defined VMEM_30_XXRAM_START_SEC_VAR_INIT_32
# undef VMEM_30_XXRAM_START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32
#endif
#if defined VMEM_30_XXRAM_STOP_SEC_VAR_INIT_32
# undef VMEM_30_XXRAM_STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* #include "vMem_30_XXRam_CfgMemMap.h" */
/**********************************************************************************************************************
 *  VMEM_30_XXRAM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef IOHWAB_START_SEC_CODE
    #undef IOHWAB_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef IOHWAB_STOP_SEC_CODE
    #undef IOHWAB_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef IOHWAB_START_SEC_CONST_32
    #undef IOHWAB_START_SEC_CONST_32
    #define START_SEC_CONST_32
#endif
#ifdef IOHWAB_STOP_SEC_CONST_32
    #undef IOHWAB_STOP_SEC_CONST_32
    #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef IOHWAB_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef IOHWAB_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef IOHWAB_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef IOHWAB_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  EcuAb_AsrIoHwAb END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  MIRROR START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef MIRROR_START_SEC_CODE
  #undef MIRROR_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE
#endif
#ifdef MIRROR_STOP_SEC_CODE
  #undef MIRROR_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */ 
  #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef MIRROR_START_SEC_CONST_8BIT
# undef MIRROR_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_8BIT
#endif
#ifdef MIRROR_STOP_SEC_CONST_8BIT
# undef MIRROR_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_CONST
#endif

#ifdef MIRROR_START_SEC_CONST_32BIT
# undef MIRROR_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_32BIT
#endif
#ifdef MIRROR_STOP_SEC_CONST_32
# undef MIRROR_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef MIRROR_START_SEC_CONST_UNSPECIFIED
# undef MIRROR_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef MIRROR_STOP_SEC_CONST_UNSPECIFIED
# undef MIRROR_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef MIRROR_START_SEC_VAR_NOINIT_8BIT
# undef MIRROR_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef MIRROR_STOP_SEC_VAR_NOINIT_8BIT
# undef MIRROR_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_VAR
#endif

#ifdef MIRROR_START_SEC_VAR_NOINIT_16BIT
# undef MIRROR_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef MIRROR_STOP_SEC_VAR_NOINIT_16BIT
# undef MIRROR_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_VAR
#endif

#ifdef MIRROR_START_SEC_VAR_NOINIT_32BIT
# undef MIRROR_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef MIRROR_STOP_SEC_VAR_NOINIT_32BIT
# undef MIRROR_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_VAR
#endif

#ifdef MIRROR_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef MIRROR_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef MIRROR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef MIRROR_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef MIRROR_START_SEC_VAR_ZERO_INIT_8BIT
# undef MIRROR_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef MIRROR_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef MIRROR_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef MIRROR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef MIRROR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef MIRROR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef MIRROR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* Postbuild CFG VAR sections */
#ifdef MIRROR_START_SEC_VAR_PBCFG
# undef MIRROR_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef MIRROR_STOP_SEC_VAR_PBCFG
# undef MIRROR_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef MIRROR_START_SEC_PBCFG
# undef MIRROR_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define START_SEC_CONST_PBCFG
#endif
#ifdef MIRROR_STOP_SEC_PBCFG
# undef MIRROR_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_CONST
#endif

/***********************************************************************************************************************
 *  MIRROR END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  LINIF START
 *********************************************************************************************************************/

/* Code */
#ifdef LINIF_START_SEC_CODE
# undef LINIF_START_SEC_CODE                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef LINIF_STOP_SEC_CODE
# undef LINIF_STOP_SEC_CODE                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/* Const 8 bit */
#ifdef LINIF_START_SEC_CONST_8BIT
# undef LINIF_START_SEC_CONST_8BIT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT                      /* mapped to const 8 bit section */
#endif
#ifdef LINIF_STOP_SEC_CONST_8BIT
# undef LINIF_STOP_SEC_CONST_8BIT                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                            /* default const stop section */
#endif

/* Const 16 bit */
#ifdef LINIF_START_SEC_CONST_16BIT
# undef LINIF_START_SEC_CONST_16BIT                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT                     /* mapped to const 16 bit section */
#endif
#ifdef LINIF_STOP_SEC_CONST_16BIT
# undef LINIF_STOP_SEC_CONST_16BIT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                            /* default const stop section */
#endif

/* Const 32 bit */
#ifdef LINIF_START_SEC_CONST_32BIT
# undef LINIF_START_SEC_CONST_32BIT                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT                     /* mapped to const 32 bit section */
#endif
#ifdef LINIF_STOP_SEC_CONST_32BIT
# undef LINIF_STOP_SEC_CONST_32BIT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                            /* default const stop section */
#endif

/* Const unspecified */
#ifdef LINIF_START_SEC_CONST_UNSPECIFIED
# undef LINIF_START_SEC_CONST_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED               /* mapped to const unspecified section */
#endif
#ifdef LINIF_STOP_SEC_CONST_UNSPECIFIED
# undef LINIF_STOP_SEC_CONST_UNSPECIFIED           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                            /* default const stop section */
#endif

/* Post build config unspecified */
#ifdef LINIF_START_SEC_PBCFG
# undef LINIF_START_SEC_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG                     /* mapped to post build section */
#endif
#ifdef LINIF_STOP_SEC_PBCFG
# undef LINIF_STOP_SEC_PBCFG                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                            /* default post build stop section */
#endif

/* Var noinit unspecified */
#ifdef LINIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef LINIF_START_SEC_VAR_NOINIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED          /* mapped to uninitialized var unspecified section */
#endif
#ifdef LINIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef LINIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                              /* default var stop section */
#endif

/* Var noinit 8 bit */
#ifdef LINIF_START_SEC_VAR_NOINIT_8BIT
# undef LINIF_START_SEC_VAR_NOINIT_8BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT                 /* mapped to uninitialized var 8 bit section */
#endif
#ifdef LINIF_STOP_SEC_VAR_NOINIT_8BIT
# undef LINIF_STOP_SEC_VAR_NOINIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                              /* default var stop section */
#endif

/* Var zero init 8 bit */
#ifdef LINIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef LINIF_START_SEC_VAR_ZERO_INIT_8BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT              /* mapped to zero initialized var unspecified section */
#endif
#ifdef LINIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef LINIF_STOP_SEC_VAR_ZERO_INIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                              /* default var stop section */
#endif

/* Post build config unspecified */
#ifdef LINIF_START_SEC_VAR_PBCFG
# undef LINIF_START_SEC_VAR_PBCFG                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG                       /* mapped to post build section */
#endif
#ifdef LINIF_STOP_SEC_VAR_PBCFG
# undef LINIF_STOP_SEC_VAR_PBCFG                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                              /* default post build stop section */
#endif

/**********************************************************************************************************************
 *  LINIF END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LINTP START
 *********************************************************************************************************************/

/* Code */
#ifdef LINTP_START_SEC_CODE
# undef LINTP_START_SEC_CODE                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef LINTP_STOP_SEC_CODE
# undef LINTP_STOP_SEC_CODE                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/* Const 8 bit */
#ifdef LINTP_START_SEC_CONST_8BIT
# undef LINTP_START_SEC_CONST_8BIT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT                      /* mapped to const 8 bit section */
#endif
#ifdef LINTP_STOP_SEC_CONST_8BIT
# undef LINTP_STOP_SEC_CONST_8BIT                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                            /* default const stop section */
#endif

/* Const 16 bit */
#ifdef LINTP_START_SEC_CONST_16BIT
# undef LINTP_START_SEC_CONST_16BIT                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT                     /* mapped to const 16 bit section */
#endif
#ifdef LINTP_STOP_SEC_CONST_16BIT
# undef LINTP_STOP_SEC_CONST_16BIT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                            /* default const stop section */
#endif

/* Const 32 bit */
#ifdef LINTP_START_SEC_CONST_32BIT
# undef LINTP_START_SEC_CONST_32BIT                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT                     /* mapped to const 32 bit section */
#endif
#ifdef LINTP_STOP_SEC_CONST_32BIT
# undef LINTP_STOP_SEC_CONST_32BIT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                            /* default const stop section */
#endif

/* Const unspecified */
#ifdef LINTP_START_SEC_CONST_UNSPECIFIED
# undef LINTP_START_SEC_CONST_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED               /* mapped to const unspecified section */
#endif
#ifdef LINTP_STOP_SEC_CONST_UNSPECIFIED
# undef LINTP_STOP_SEC_CONST_UNSPECIFIED           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                            /* default const stop section */
#endif

/* Post build config unspecified */
#ifdef LINTP_START_SEC_PBCFG
# undef LINTP_START_SEC_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG                     /* mapped to post build section */
#endif
#ifdef LINTP_STOP_SEC_PBCFG
# undef LINTP_STOP_SEC_PBCFG                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                            /* default post build stop section */
#endif

/* Var noinit unspecified */
#ifdef LINTP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef LINTP_START_SEC_VAR_NOINIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED          /* mapped to uninitialized var unspecified section */
#endif
#ifdef LINTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef LINTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                              /* default var stop section */
#endif

/* Var noinit 8 bit */
#ifdef LINTP_START_SEC_VAR_NOINIT_8BIT
# undef LINTP_START_SEC_VAR_NOINIT_8BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT                 /* mapped to uninitialized var 8 bit section */
#endif
#ifdef LINTP_STOP_SEC_VAR_NOINIT_8BIT
# undef LINTP_STOP_SEC_VAR_NOINIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                              /* default var stop section */
#endif

/* Var zero init 8 bit */
#ifdef LINTP_START_SEC_VAR_ZERO_INIT_8BIT
# undef LINTP_START_SEC_VAR_ZERO_INIT_8BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT              /* mapped to zero initialized var unspecified section */
#endif
#ifdef LINTP_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef LINTP_STOP_SEC_VAR_ZERO_INIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                              /* default var stop section */
#endif

#ifdef LINTP_START_SEC_VAR_PBCFG
# undef LINTP_START_SEC_VAR_PBCFG                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG                       /* mapped to post build section */
#endif
#ifdef LINTP_STOP_SEC_VAR_PBCFG
# undef LINTP_STOP_SEC_VAR_PBCFG                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                              /* default post build stop section */
#endif
/**********************************************************************************************************************
 *  LINTP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  WDGIF START
 *********************************************************************************************************************/

#include "WdgIf_MemMap.h"

/*******  CODE sections **********************************************************************************************/

#if defined WDGIF_START_SEC_CODE
# undef WDGIF_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#if defined WDGIF_STOP_SEC_CODE
# undef WDGIF_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#if defined WDGIF_START_SEC_CONST_UNSPECIFIED
# undef WDGIF_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined WDGIF_STOP_SEC_CONST_UNSPECIFIED
# undef WDGIF_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined WDGIF_START_SEC_VAR_INIT_8BIT
# undef WDGIF_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_INIT_8BIT
# undef WDGIF_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined WDGIF_START_SEC_VAR_INIT_16BIT
# undef WDGIF_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined WDGIF_STOP_SEC_VAR_INIT_16BIT
# undef WDGIF_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  WDGIF END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CRYIF START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CRYIF_START_SEC_CODE
# undef CRYIF_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef CRYIF_STOP_SEC_CODE
# undef CRYIF_STOP_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CRYIF_START_SEC_CONST_UNSPECIFIED
# undef CRYIF_START_SEC_CONST_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYIF_STOP_SEC_CONST_UNSPECIFIED
# undef CRYIF_STOP_SEC_CONST_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */


/* VAR ZERO INIT sections */

#ifdef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CRYIF END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  If_AsrIfEa START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef EA_START_SEC_CODE
    #undef EA_START_SEC_CODE                 /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CODE
#endif
#ifdef EA_STOP_SEC_CODE
    #undef EA_STOP_SEC_CODE                 /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef EA_START_SEC_CONST_8BIT
    #undef EA_START_SEC_CONST_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_8BIT
#endif
#ifdef EA_STOP_SEC_CONST_8BIT
    #undef EA_STOP_SEC_CONST_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST
#endif

#ifdef EA_START_SEC_CONST_UNSPECIFIED
    #undef EA_START_SEC_CONST_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef EA_STOP_SEC_CONST_UNSPECIFIED
    #undef EA_STOP_SEC_CONST_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  ********************************************************************************************/

/* VAR NOINIT sections */

#ifdef EA_START_SEC_VAR_NOINIT_INTERNAL_READ_BUFFER
/* Non-standard MemMap section for internal read buffer, which will be forwarded to the EEPROM driver.
 * Depending on restrictions, this buffer might have to be aligned to prevent unaligned memory access exceptions. */
# undef EA_START_SEC_VAR_NOINIT_INTERNAL_READ_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef EA_STOP_SEC_VAR_NOINIT_INTERNAL_READ_BUFFER
# undef EA_STOP_SEC_VAR_NOINIT_INTERNAL_READ_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef EA_START_SEC_VAR_NOINIT_INTERNAL_WRITE_BUFFER
/* Non-standard MemMap section for internal write buffer, which will be forwarded to the EEPROM driver.
 * Depending on restrictions, this buffer might have to be aligned to prevent unaligned memory access exceptions. */
# undef EA_START_SEC_VAR_NOINIT_INTERNAL_WRITE_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef EA_STOP_SEC_VAR_NOINIT_INTERNAL_WRITE_BUFFER
# undef EA_STOP_SEC_VAR_NOINIT_INTERNAL_WRITE_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef EA_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef EA_START_SEC_VAR_NOINIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef EA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef EA_STOP_SEC_VAR_NOINIT_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

/* VAR FAST sections */

#ifdef EA_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef EA_START_SEC_VAR_FAST_INIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef EA_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef EA_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  If_AsrIfEa END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FEE START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FEE_START_SEC_CODE
# undef FEE_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef FEE_STOP_SEC_CODE
# undef FEE_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FEE_START_SEC_CONST_UNSPECIFIED
# undef FEE_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_STOP_SEC_CONST_UNSPECIFIED
# undef FEE_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef FEE_START_SEC_APPL_CONFIG_UNSPECIFIED
# undef FEE_START_SEC_APPL_CONFIG_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_STOP_SEC_APPL_CONFIG_UNSPECIFIED
# undef FEE_STOP_SEC_APPL_CONFIG_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef FEE_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FEE_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef FEE_START_SEC_VAR_INIT_UNSPECIFIED
# undef FEE_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  FEE END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  If_AsrIfFeeSmallSector START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FEE_30_SMALLSECTOR_START_SEC_CODE
    #undef FEE_30_SMALLSECTOR_START_SEC_CODE
    #define START_SEC_CODE
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CODE
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CODE
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
    #define START_SEC_CONST_8BIT
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
    #define STOP_SEC_CONST
#endif

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_16BIT
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_16BIT
    #define START_SEC_CONST_16BIT
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_16BIT
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_16BIT
    #define STOP_SEC_CONST
#endif

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_32BIT
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_32BIT
    #define START_SEC_CONST_32BIT
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_32BIT
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_32BIT
    #define STOP_SEC_CONST
#endif

#ifdef FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  ********************************************************************************************/

/* VAR NOINIT sections */

#ifdef FEE_30_SMALLSECTOR_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_START_SEC_VAR_NOINIT_UNSPECIFIED
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/* VAR FAST sections */

#ifdef FEE_30_SMALLSECTOR_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef FEE_30_SMALLSECTOR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #undef FEE_30_SMALLSECTOR_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  If_AsrIfFeeSmallSector END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FRIF START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRIF_START_SEC_CODE
  #undef FRIF_START_SEC_CODE                        /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef FRIF_STOP_SEC_CODE
  #undef FRIF_STOP_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef FRIF_START_SEC_APPL_CODE
  #undef FRIF_START_SEC_APPL_CODE                   /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE                            /* mapped to default appl code section */
#endif
#ifdef FRIF_STOP_SEC_APPL_CODE
  #undef FRIF_STOP_SEC_APPL_CODE                    /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRIF_START_SEC_CONST_32
# undef FRIF_START_SEC_CONST_32                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef FRIF_STOP_SEC_CONST_32
# undef FRIF_STOP_SEC_CONST_32                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef FRIF_START_SEC_CONST_UNSPECIFIED
# undef FRIF_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_CONST_UNSPECIFIED  
# undef FRIF_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#ifdef FRIF_START_SEC_PBCFG
# undef FRIF_START_SEC_PBCFG                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRIF_STOP_SEC_PBCFG
# undef FRIF_STOP_SEC_PBCFG                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef FRIF_START_SEC_PBCFG_GLOBALROOT
# undef FRIF_START_SEC_PBCFG_GLOBALROOT                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef FRIF_STOP_SEC_PBCFG_GLOBALROOT
# undef FRIF_STOP_SEC_PBCFG_GLOBALROOT                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef FRIF_START_SEC_VAR_INIT_UNSPECIFIED
# undef FRIF_START_SEC_VAR_INIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FRIF_STOP_SEC_VAR_INIT_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRIF_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef FRIF_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef FRIF_START_SEC_VAR_CLEARED_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef FRIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef FRIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* PBCFG section for flexible RAM management */

#ifdef FRIF_START_SEC_VAR_PBCFG
# undef FRIF_START_SEC_VAR_PBCFG       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef FRIF_STOP_SEC_VAR_PBCFG
# undef FRIF_STOP_SEC_VAR_PBCFG        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FRIF END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  FEE_30_FLEXNOR START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef FEE_30_FLEXNOR_START_SEC_CODE
# undef FEE_30_FLEXNOR_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_CODE
# undef FEE_30_FLEXNOR_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FEE_30_FLEXNOR_START_SEC_CONST_32
# undef FEE_30_FLEXNOR_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_CONST_32
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_CONST_32
# undef FEE_30_FLEXNOR_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */
#ifdef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_8
# undef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_8
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32
# undef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_32
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_8
# undef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_CLEARED_8
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_8
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_PBCFG
# undef FEE_30_FLEXNOR_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_CONST_PBCFG
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_PBCFG
# undef FEE_30_FLEXNOR_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define STOP_SEC_CONST
#endif

/* VAR INIT section */
#ifdef FEE_30_FLEXNOR_START_SEC_VAR_INIT_32
# undef FEE_30_FLEXNOR_START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_INIT_32
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_32
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  FEE_30_FLEXNOR END
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  FEE_30_FLEXNOR START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef FEE_30_FLEXNOR_START_SEC_CODE
# undef FEE_30_FLEXNOR_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_CODE
# undef FEE_30_FLEXNOR_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FEE_30_FLEXNOR_START_SEC_CONST_32
# undef FEE_30_FLEXNOR_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_CONST_32
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_CONST_32
# undef FEE_30_FLEXNOR_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */
#ifdef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_8
# undef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_8
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32
# undef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_32
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_8
# undef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_CLEARED_8
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_8
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_PBCFG
# undef FEE_30_FLEXNOR_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_CONST_PBCFG
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_PBCFG
# undef FEE_30_FLEXNOR_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define STOP_SEC_CONST
#endif

/* VAR INIT section */
#ifdef FEE_30_FLEXNOR_START_SEC_VAR_INIT_32
# undef FEE_30_FLEXNOR_START_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_INIT_32
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_32
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_32 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef FEE_30_FLEXNOR_START_SEC_VAR_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */ 
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef FEE_30_FLEXNOR_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  FEE_30_FLEXNOR END
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  VFEEACC START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef VFEEACC_START_SEC_CODE
#  undef VFEEACC_START_SEC_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define START_SEC_CODE /* mapped to default code section */
#endif
#ifdef VFEEACC_STOP_SEC_CODE
#  undef VFEEACC_STOP_SEC_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define STOP_SEC_CODE /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef VFEEACC_START_SEC_CONST_UNSPECIFIED
#  undef VFEEACC_START_SEC_CONST_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VFEEACC_STOP_SEC_CONST_UNSPECIFIED
#  undef VFEEACC_STOP_SEC_CONST_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef VFEEACC_START_SEC_VAR_NOINIT_UNSPECIFIED
#  undef VFEEACC_START_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VFEEACC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  undef VFEEACC_STOP_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define STOP_SEC_VAR
#endif

/* VAR INIT sections */

#ifdef VFEEACC_START_SEC_VAR_INIT_UNSPECIFIED
#  undef VFEEACC_START_SEC_VAR_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef VFEEACC_STOP_SEC_VAR_INIT_UNSPECIFIED
#  undef VFEEACC_STOP_SEC_VAR_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
#  define STOP_SEC_VAR
#endif


/***********************************************************************************************************************
 *  VFEEACC END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEMACCM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEMACCM_START_SEC_CODE)
# undef VMEMACCM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEMACCM_STOP_SEC_CODE)
# undef VMEMACCM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(VMEMACCM_START_SEC_VAR_INIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT          /* mapped to default var init 8bit section */
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                     /* default var stop section */
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_16BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_16BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_16BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_32BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_32BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR CONST sections */

#if defined(VMEMACCM_START_SEC_CONST_UNSPECIFIED)
# undef VMEMACCM_START_SEC_CONST_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_CONST_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_CONST_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* VAR NOINIT sections */

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_16BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_16BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_16BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_32BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* Multi partition sections. */

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition0"
#   pragma ghs section sdata=".svMemAccMPartition0"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif


#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition1"
#   pragma ghs section sdata=".svMemAccMPartition1"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID2
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID2
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition2"
#   pragma ghs section sdata=".svMemAccMPartition2"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID2
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID2
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID3
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID3
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition3"
#   pragma ghs section sdata=".svMemAccMPartition3"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID3
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID3
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID4
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID4
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition4"
#   pragma ghs section sdata=".svMemAccMPartition4"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID4
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID4
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID5
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID5
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition5"
#   pragma ghs section sdata=".svMemAccMPartition5"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID5
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID5
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID6
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID6
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition6"
#   pragma ghs section sdata=".svMemAccMPartition6"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID6
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID6
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID7
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID7
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition7"
#   pragma ghs section sdata=".svMemAccMPartition7"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID7
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID7
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID8
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID8
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition8"
#   pragma ghs section sdata=".svMemAccMPartition8"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID8
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID8
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID9
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID9
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition9"
#   pragma ghs section sdata=".svMemAccMPartition9"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID9
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID9
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID10
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID10
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition10"
#   pragma ghs section sdata=".svMemAccMPartition10"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID10
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID10
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID11
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID11
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition11"
#   pragma ghs section sdata=".svMemAccMPartition11"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID11
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID11
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID12
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID12
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition12"
#   pragma ghs section sdata=".svMemAccMPartition12"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID12
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID12
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID13
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID13
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition13"
#   pragma ghs section sdata=".svMemAccMPartition13"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID13
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID13
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID14
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID14
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition14"
#   pragma ghs section sdata=".svMemAccMPartition14"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID14
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID14
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID15
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID15
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition15"
#   pragma ghs section sdata=".svMemAccMPartition15"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID15
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID15
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID16
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID16
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition16"
#   pragma ghs section sdata=".svMemAccMPartition16"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID16
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID16
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VMEMACCM END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  VSYNCMEM START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef VSYNCMEM_START_SEC_CODE
# undef VSYNCMEM_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef VSYNCMEM_STOP_SEC_CODE
# undef VSYNCMEM_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define STOP_SEC_CODE
#endif

/* VAR ZERO INIT sections */
#ifdef VSYNCMEM_START_SEC_VAR_CLEARED_8
# undef VSYNCMEM_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_8
#endif
#ifdef VSYNCMEM_STOP_SEC_VAR_CLEARED_8
# undef VSYNCMEM_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/******  CALLOUT sections *********************************************************************************************/
#ifdef VSYNCMEM_START_SEC_CODE_CALLOUT
# undef VSYNCMEM_START_SEC_CODE_CALLOUT                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef VSYNCMEM_STOP_SEC_CODE_CALLOUT
# undef VSYNCMEM_STOP_SEC_CODE_CALLOUT                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif


/***********************************************************************************************************************
 *  VSYNCMEM END
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  Com START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef COM_START_SEC_CODE
# undef COM_START_SEC_CODE
# define START_SEC_CODE
#endif
#ifdef COM_STOP_SEC_CODE
# undef COM_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif
/* COM application callback code section (Rte_Cbk.h)*/
#ifdef COM_START_SEC_APPL_CODE
# undef COM_START_SEC_APPL_CODE
# define START_SEC_CODE
#endif
#ifdef COM_STOP_SEC_APPL_CODE
# undef COM_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef COM_START_SEC_CONST_8
# undef COM_START_SEC_CONST_8
# define START_SEC_CONST_8
#endif
#ifdef COM_STOP_SEC_CONST_8
# undef COM_STOP_SEC_CONST_8
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_16
# undef COM_START_SEC_CONST_16
# define START_SEC_CONST_16
#endif
#ifdef COM_STOP_SEC_CONST_16
# undef COM_STOP_SEC_CONST_16
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_32
# undef COM_START_SEC_CONST_32
# define START_SEC_CONST_32
#endif
#ifdef COM_STOP_SEC_CONST_32
# undef COM_STOP_SEC_CONST_32
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_64
# undef COM_START_SEC_CONST_64
# define START_SEC_CONST_64
#endif
#ifdef COM_STOP_SEC_CONST_64
# undef COM_STOP_SEC_CONST_64
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_CONST_UNSPECIFIED
# undef COM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_CONST_UNSPECIFIED
# undef COM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_PBCFG
# undef COM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef COM_STOP_SEC_PBCFG
# undef COM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef COM_START_SEC_VAR_PBCFG
# undef COM_START_SEC_VAR_PBCFG
# define START_SEC_VAR_PBCFG
#endif
#ifdef COM_STOP_SEC_VAR_PBCFG
# undef COM_STOP_SEC_VAR_PBCFG
# define STOP_SEC_VAR
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef COM_START_SEC_VAR_INIT_UNSPECIFIED
# undef COM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef COM_START_SEC_VAR_CLEARED_UNSPECIFIED
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_CLEARED_8
# undef COM_START_SEC_VAR_CLEARED_8
# define START_SEC_VAR_CLEARED_8
#endif
#ifdef COM_STOP_SEC_VAR_CLEARED_8
# undef COM_STOP_SEC_VAR_CLEARED_8
# define STOP_SEC_VAR
#endif

/* VAR NO_INIT sections */

#ifdef COM_START_SEC_VAR_NO_INIT_BOOLEAN
# undef COM_START_SEC_VAR_NO_INIT_BOOLEAN
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
# undef COM_STOP_SEC_VAR_NO_INIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NO_INIT_8
# undef COM_START_SEC_VAR_NO_INIT_8
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef COM_STOP_SEC_VAR_NO_INIT_8
# undef COM_STOP_SEC_VAR_NO_INIT_8
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NO_INIT_16
# undef COM_START_SEC_VAR_NO_INIT_16
# define START_SEC_VAR_NO_INIT_16
#endif
#ifdef COM_STOP_SEC_VAR_NO_INIT_16
# undef COM_STOP_SEC_VAR_NO_INIT_16
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NO_INIT_32
# undef COM_START_SEC_VAR_NO_INIT_32
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef COM_STOP_SEC_VAR_NO_INIT_32
# undef COM_STOP_SEC_VAR_NO_INIT_32
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NO_INIT_64
# undef COM_START_SEC_VAR_NO_INIT_64
# define START_SEC_VAR_NO_INIT_64
#endif
#ifdef COM_STOP_SEC_VAR_NO_INIT_64
# undef COM_STOP_SEC_VAR_NO_INIT_64
# define STOP_SEC_VAR
#endif

#ifdef COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */



/* VAR FAST INIT sections */



/* VAR FAST NO_INIT sections */


/* VAR FAST ZERO INIT sections */



/**********************************************************************************************************************
 *  Com END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LDCOM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef LDCOM_START_SEC_CODE
# undef LDCOM_START_SEC_CODE
# define START_SEC_CODE /* mapped to default code section */
#endif
#ifdef LDCOM_STOP_SEC_CODE
# undef LDCOM_STOP_SEC_CODE
# define STOP_SEC_CODE  /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef LDCOM_START_SEC_CONST_8BIT
# undef LDCOM_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT   /* mapped to default const 8bit section */
#endif
#ifdef LDCOM_STOP_SEC_CONST_8BIT
# undef LDCOM_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST /* default const stop section */
#endif

#ifdef LDCOM_START_SEC_CONST_16BIT
# undef LDCOM_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef LDCOM_STOP_SEC_CONST_16BIT
# undef LDCOM_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef LDCOM_START_SEC_CONST_32BIT
# undef LDCOM_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef LDCOM_STOP_SEC_CONST_32BIT
# undef LDCOM_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef LDCOM_START_SEC_CONST_UNSPECIFIED
# undef LDCOM_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef LDCOM_STOP_SEC_CONST_UNSPECIFIED
# undef LDCOM_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#ifdef LDCOM_START_SEC_PBCFG
# undef LDCOM_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef LDCOM_STOP_SEC_PBCFG
# undef LDCOM_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef LDCOM_START_SEC_VAR_INIT_8BIT
# undef LDCOM_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT        /* mapped to default var init 8bit section */
#endif
#ifdef LDCOM_STOP_SEC_VAR_INIT_8BIT
# undef LDCOM_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR   /* default var stop section */
#endif

#ifdef LDCOM_START_SEC_VAR_INIT_16BIT
# undef LDCOM_START_SEC_VAR_INIT_16BIT
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_INIT_16BIT
# undef LDCOM_STOP_SEC_VAR_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_INIT_32BIT
# undef LDCOM_START_SEC_VAR_INIT_32BIT
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_INIT_32BIT
# undef LDCOM_STOP_SEC_VAR_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_INIT_UNSPECIFIED
# undef LDCOM_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef LDCOM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef LDCOM_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef LDCOM_START_SEC_VAR_NOINIT_BOOLEAN
# undef LDCOM_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef LDCOM_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_NOINIT_8BIT
# undef LDCOM_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_NOINIT_8BIT
# undef LDCOM_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_NOINIT_16BIT
# undef LDCOM_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_NOINIT_16BIT
# undef LDCOM_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_NOINIT_32BIT
# undef LDCOM_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_NOINIT_32BIT
# undef LDCOM_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef LDCOM_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef LDCOM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef LDCOM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef LDCOM_START_SEC_VAR_ZERO_INIT_8BIT
# undef LDCOM_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT
#endif
#ifdef LDCOM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef LDCOM_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef LDCOM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef LDCOM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef LDCOM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef LDCOM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR FAST INIT sections */

/* VAR FAST NOINIT sections */

/* VAR FAST ZERO INIT sections */


/**********************************************************************************************************************
 *  LDCOM END
 *********************************************************************************************************************/


/* PRQA S 0841 MEMMAP_0841_TAG */ /* MD_MSR_Undef */

/***********************************************************************************************************************
 *  VIPC START 
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef VIPC_START_SEC_CODE
#undef VIPC_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CODE
#endif
#ifdef VIPC_STOP_SEC_CODE
#undef VIPC_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef VIPC_START_SEC_CONST_32BIT
#undef VIPC_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CONST_32BIT
#endif
#ifdef VIPC_STOP_SEC_CONST_32BIT
#undef VIPC_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef VIPC_START_SEC_VAR_NOINIT_8BIT
#undef VIPC_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef VIPC_STOP_SEC_VAR_NOINIT_8BIT
#undef VIPC_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

#ifdef VIPC_START_SEC_VAR_NOINIT_32BIT
#undef VIPC_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef VIPC_STOP_SEC_VAR_NOINIT_32BIT
#undef VIPC_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

#ifdef VIPC_START_SEC_VAR_NOINIT_UNSPECIFIED
#undef VIPC_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VIPC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#undef VIPC_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef VIPC_START_SEC_VAR_ZERO_INIT_8BIT
#undef VIPC_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef VIPC_STOP_SEC_VAR_ZERO_INIT_8BIT
#undef VIPC_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

#ifdef VIPC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#undef VIPC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef VIPC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#undef VIPC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

/* VAR INIT sections */
#ifdef VIPC_START_SEC_VAR_INIT_UNSPECIFIED
#undef VIPC_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef VIPC_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef VIPC_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_VAR
#endif

/* CONST INIT sections */
#ifdef VIPC_START_SEC_CONST_UNSPECIFIED
#undef VIPC_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VIPC_STOP_SEC_CONST_UNSPECIFIED
#undef VIPC_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CONST
#endif

#ifdef VIPC_START_SEC_PBCFG
#undef VIPC_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
#define START_SEC_CONST_PBCFG
#endif
#ifdef VIPC_STOP_SEC_PBCFG
#undef VIPC_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
#define STOP_SEC_CONST
#endif

/***********************************************************************************************************************
 *  VIPC END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  VIPCMEMCP START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VIPCMEMCP_START_SEC_CODE)
# undef VIPCMEMCP_START_SEC_CODE                                                                                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#if defined(VIPCMEMCP_STOP_SEC_CODE)
# undef VIPCMEMCP_STOP_SEC_CODE                                                                                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(VIPCMEMCP_START_SEC_CONST_UNSPECIFIED)
# undef VIPCMEMCP_START_SEC_CONST_UNSPECIFIED                                                                           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VIPCMEMCP_STOP_SEC_CONST_UNSPECIFIED)
# undef VIPCMEMCP_STOP_SEC_CONST_UNSPECIFIED                                                                            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* Post-Build CONST sections */

#if defined(VIPCMEMCP_START_SEC_PBCFG)
# undef VIPCMEMCP_START_SEC_PBCFG                                                                                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(VIPCMEMCP_STOP_SEC_PBCFG)
# undef VIPCMEMCP_STOP_SEC_PBCFG                                                                                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(VIPCMEMCP_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VIPCMEMCP_START_SEC_VAR_NOINIT_UNSPECIFIED                                                                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VIPCMEMCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VIPCMEMCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED                                                                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(VIPCMEMCP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VIPCMEMCP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED                                                                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(VIPCMEMCP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VIPCMEMCP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED                                                                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VIPCMEMCP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VIPCMEMIF START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VIPCMEMIF_START_SEC_CODE)
# undef VIPCMEMIF_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#if defined(VIPCMEMIF_STOP_SEC_CODE)
# undef VIPCMEMIF_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(VIPCMEMIF_START_SEC_CONST_UNSPECIFIED)
# undef VIPCMEMIF_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VIPCMEMIF_STOP_SEC_CONST_UNSPECIFIED)
# undef VIPCMEMIF_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(VIPCMEMIF_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VIPCMEMIF_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VIPCMEMIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VIPCMEMIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(VIPCMEMIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VIPCMEMIF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(VIPCMEMIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VIPCMEMIF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VIPCMEMIF END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VIPCMEMIFLINUX START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VIPCMEMIFLINUX_START_SEC_CODE)
# undef VIPCMEMIFLINUX_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#if defined(VIPCMEMIFLINUX_STOP_SEC_CODE)
# undef VIPCMEMIFLINUX_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(VIPCMEMIFLINUX_START_SEC_CONST_UNSPECIFIED)
# undef VIPCMEMIFLINUX_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VIPCMEMIFLINUX_STOP_SEC_CONST_UNSPECIFIED)
# undef VIPCMEMIFLINUX_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(VIPCMEMIFLINUX_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VIPCMEMIFLINUX_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VIPCMEMIFLINUX_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VIPCMEMIFLINUX_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(VIPCMEMIFLINUX_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VIPCMEMIFLINUX_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(VIPCMEMIFLINUX_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VIPCMEMIFLINUX_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VIPCMEMIFLINUX END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VIPCMEMLINUX START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VIPCMEMLINUX_START_SEC_CODE)
# undef VIPCMEMLINUX_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE
#endif
#if defined(VIPCMEMLINUX_STOP_SEC_CODE)
# undef VIPCMEMLINUX_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(VIPCMEMLINUX_START_SEC_CONST_8BIT)
# undef VIPCMEMLINUX_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif
#if defined(VIPCMEMLINUX_STOP_SEC_CONST_8BIT)
# undef VIPCMEMLINUX_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(VIPCMEMLINUX_START_SEC_CONST_16BIT)
# undef VIPCMEMLINUX_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(VIPCMEMLINUX_STOP_SEC_CONST_16BIT)
# undef VIPCMEMLINUX_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(VIPCMEMLINUX_START_SEC_CONST_32BIT)
# undef VIPCMEMLINUX_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(VIPCMEMLINUX_STOP_SEC_CONST_32BIT)
# undef VIPCMEMLINUX_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(VIPCMEMLINUX_START_SEC_CONST_64BIT)
# undef VIPCMEMLINUX_START_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_64BIT
#endif
#if defined(VIPCMEMLINUX_STOP_SEC_CONST_64BIT)
# undef VIPCMEMLINUX_STOP_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(VIPCMEMLINUX_START_SEC_CONST_UNSPECIFIED)
# undef VIPCMEMLINUX_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VIPCMEMLINUX_STOP_SEC_CONST_UNSPECIFIED)
# undef VIPCMEMLINUX_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(VIPCMEMLINUX_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VIPCMEMLINUX_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VIPCMEMLINUX_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VIPCMEMLINUX_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(VIPCMEMLINUX_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VIPCMEMLINUX_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(VIPCMEMLINUX_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VIPCMEMLINUX_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VIPCMEMLINUX END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vRpcProxy START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VRPCPROXY_START_SEC_CODE)
# undef VRPCPROXY_START_SEC_CODE      
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VRPCPROXY_STOP_SEC_CODE)
# undef VRPCPROXY_STOP_SEC_CODE       
# define STOP_SEC_CODE          /* default code stop section */
#endif

/* COM application callback code section */
#ifdef COM_START_SEC_APPL_CODE
# undef COM_START_SEC_APPL_CODE
# define START_SEC_CODE
#endif
#ifdef COM_STOP_SEC_APPL_CODE
# undef COM_STOP_SEC_APPL_CODE
# define STOP_SEC_CODE
#endif
/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(VRPCPROXY_START_SEC_CONST_8BIT)
# undef VRPCPROXY_START_SEC_CONST_8BIT  
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(VRPCPROXY_STOP_SEC_CONST_8BIT)
# undef VRPCPROXY_STOP_SEC_CONST_8BIT   
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(VRPCPROXY_START_SEC_CONST_16BIT)
# undef VRPCPROXY_START_SEC_CONST_16BIT 
# define START_SEC_CONST_16BIT
#endif
#if defined(VRPCPROXY_STOP_SEC_CONST_16BIT)
# undef VRPCPROXY_STOP_SEC_CONST_16BIT 
# define STOP_SEC_CONST
#endif

#if defined(VRPCPROXY_START_SEC_CONST_32BIT)
# undef VRPCPROXY_START_SEC_CONST_32BIT 
# define START_SEC_CONST_32BIT
#endif
#if defined(VRPCPROXY_STOP_SEC_CONST_32BIT)
# undef VRPCPROXY_STOP_SEC_CONST_32BIT 
# define STOP_SEC_CONST
#endif

#if defined(VRPCPROXY_START_SEC_CONST_UNSPECIFIED)
# undef VRPCPROXY_START_SEC_CONST_UNSPECIFIED 
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VRPCPROXY_STOP_SEC_CONST_UNSPECIFIED)
# undef VRPCPROXY_STOP_SEC_CONST_UNSPECIFIED 
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/
/* VAR NOINIT sections */

#if defined(VRPCPROXY_START_SEC_VAR_NOINIT_8BIT)
# undef VRPCPROXY_START_SEC_VAR_NOINIT_8BIT 
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(VRPCPROXY_STOP_SEC_VAR_NOINIT_8BIT)
# undef VRPCPROXY_STOP_SEC_VAR_NOINIT_8BIT 
# define STOP_SEC_VAR
#endif

#if defined(VRPCPROXY_START_SEC_VAR_NOINIT_16BIT)
# undef VRPCPROXY_START_SEC_VAR_NOINIT_16BIT 
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(VRPCPROXY_STOP_SEC_VAR_NOINIT_16BIT)
# undef VRPCPROXY_STOP_SEC_VAR_NOINIT_16BIT 
# define STOP_SEC_VAR
#endif

#if defined(VRPCPROXY_START_SEC_VAR_NOINIT_32BIT)
# undef VRPCPROXY_START_SEC_VAR_NOINIT_32BIT 
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(VRPCPROXY_STOP_SEC_VAR_NOINIT_32BIT)
# undef VRPCPROXY_STOP_SEC_VAR_NOINIT_32BIT 
# define STOP_SEC_VAR
#endif

#if defined(VRPCPROXY_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VRPCPROXY_START_SEC_VAR_NOINIT_UNSPECIFIED 
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VRPCPROXY_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VRPCPROXY_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(VRPCPROXY_START_SEC_VAR_ZERO_INIT_8BIT)
# undef VRPCPROXY_START_SEC_VAR_ZERO_INIT_8BIT 
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(VRPCPROXY_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef VRPCPROXY_STOP_SEC_VAR_ZERO_INIT_8BIT 
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  vRpcProxy END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  VMEM_30_VRPCPROXY START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_VRPCPROXY_START_SEC_CODE)
# undef VMEM_30_VRPCPROXY_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_VRPCPROXY_STOP_SEC_CODE)
# undef VMEM_30_VRPCPROXY_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_VRPCPROXY_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_VRPCPROXY_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_VRPCPROXY_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_VRPCPROXY_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */
#if defined VMEM_30_VRPCPROXY_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_VRPCPROXY_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined VMEM_30_VRPCPROXY_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_VRPCPROXY_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#if defined VMEM_30_VRPCPROXY_START_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_VRPCPROXY_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined VMEM_30_VRPCPROXY_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_VRPCPROXY_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */

/**********************************************************************************************************************
 *  VMEM_30_VRPCPROXY END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DBG START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef DBG_START_SEC_CODE
  #undef DBG_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef DBG_STOP_SEC_CODE
  #undef DBG_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef DBG_START_SEC_CODE_FAST
  #undef DBG_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST                       /* mapped to default fast code section */
#endif
#ifdef DBG_STOP_SEC_CODE_FAST
  #undef DBG_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef DBG_START_SEC_CONST_8BIT
# undef DBG_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef DBG_STOP_SEC_CONST_8BIT
# undef DBG_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef DBG_START_SEC_CONST_16BIT
# undef DBG_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef DBG_STOP_SEC_CONST_16BIT
# undef DBG_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef DBG_START_SEC_CONST_32BIT
# undef DBG_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef DBG_STOP_SEC_CONST_32BIT
# undef DBG_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef DBG_START_SEC_CONST_UNSPECIFIED
# undef DBG_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DBG_STOP_SEC_CONST_UNSPECIFIED
# undef DBG_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef DBG_START_SEC_VAR_INIT_8BIT
# undef DBG_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT                    /* mapped to default var init 8bit section */
#endif
#ifdef DBG_STOP_SEC_VAR_INIT_8BIT
# undef DBG_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                               /* default var stop section */
#endif

#ifdef DBG_START_SEC_VAR_INIT_16BIT
# undef DBG_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef DBG_STOP_SEC_VAR_INIT_16BIT
# undef DBG_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_INIT_32BIT
# undef DBG_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef DBG_STOP_SEC_VAR_INIT_32BIT
# undef DBG_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_INIT_UNSPECIFIED
# undef DBG_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef DBG_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DBG_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef DBG_START_SEC_VAR_NOINIT_8BIT
# undef DBG_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef DBG_STOP_SEC_VAR_NOINIT_8BIT
# undef DBG_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_NOINIT_16BIT
# undef DBG_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef DBG_STOP_SEC_VAR_NOINIT_16BIT
# undef DBG_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_NOINIT_32BIT
# undef DBG_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef DBG_STOP_SEC_VAR_NOINIT_32BIT
# undef DBG_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DBG_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef DBG_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DBG_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef DBG_START_SEC_VAR_ZERO_INIT_8BIT
# undef DBG_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef DBG_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef DBG_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_ZERO_INIT_16BIT
# undef DBG_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef DBG_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef DBG_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_ZERO_INIT_32BIT
# undef DBG_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef DBG_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef DBG_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DBG_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef DBG_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef DBG_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef DBG_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  DBG END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DLT START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef DLT_START_SEC_CODE
  #undef DLT_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef DLT_STOP_SEC_CODE
  #undef DLT_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef DLT_START_SEC_CODE_FAST
  #undef DLT_START_SEC_CODE_FAST                    /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST                       /* mapped to default fast code section */
#endif
#ifdef DLT_STOP_SEC_CODE_FAST
  #undef DLT_STOP_SEC_CODE_FAST                     /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif


#ifdef DLTCOM_START_SEC_CODE
  #undef DLTCOM_START_SEC_CODE                      /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef DLTCOM_STOP_SEC_CODE
  #undef DLTCOM_STOP_SEC_CODE                       /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef DLTCOM_START_SEC_CODE_FAST
  #undef DLTCOM_START_SEC_CODE_FAST                 /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST                       /* mapped to default fast code section */
#endif
#ifdef DLTCOM_STOP_SEC_CODE_FAST
  #undef DLTCOM_STOP_SEC_CODE_FAST                  /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef DLT_START_SEC_CONST_8BIT
# undef DLT_START_SEC_CONST_8BIT                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef DLT_STOP_SEC_CONST_8BIT
# undef DLT_STOP_SEC_CONST_8BIT                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef DLT_START_SEC_CONST_16BIT
# undef DLT_START_SEC_CONST_16BIT                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef DLT_STOP_SEC_CONST_16BIT
# undef DLT_STOP_SEC_CONST_16BIT                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef DLT_START_SEC_CONST_32BIT
# undef DLT_START_SEC_CONST_32BIT                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef DLT_STOP_SEC_CONST_32BIT
# undef DLT_STOP_SEC_CONST_32BIT                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef DLT_START_SEC_CONST_UNSPECIFIED
# undef DLT_START_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DLT_STOP_SEC_CONST_UNSPECIFIED
# undef DLT_STOP_SEC_CONST_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif



/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef DLT_START_SEC_VAR_INIT_8BIT
# undef DLT_START_SEC_VAR_INIT_8BIT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT                    /* mapped to default var init 8bit section */
#endif
#ifdef DLT_STOP_SEC_VAR_INIT_8BIT
# undef DLT_STOP_SEC_VAR_INIT_8BIT                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                               /* default var stop section */
#endif

#ifdef DLT_START_SEC_VAR_INIT_16BIT
# undef DLT_START_SEC_VAR_INIT_16BIT                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef DLT_STOP_SEC_VAR_INIT_16BIT
# undef DLT_STOP_SEC_VAR_INIT_16BIT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_INIT_32BIT
# undef DLT_START_SEC_VAR_INIT_32BIT                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef DLT_STOP_SEC_VAR_INIT_32BIT
# undef DLT_STOP_SEC_VAR_INIT_32BIT                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_INIT_UNSPECIFIED
# undef DLT_START_SEC_VAR_INIT_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef DLT_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DLT_STOP_SEC_VAR_INIT_UNSPECIFIED           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef DLT_START_SEC_VAR_NOINIT_8BIT
# undef DLT_START_SEC_VAR_NOINIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef DLT_STOP_SEC_VAR_NOINIT_8BIT
# undef DLT_STOP_SEC_VAR_NOINIT_8BIT                /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_NOINIT_16BIT
# undef DLT_START_SEC_VAR_NOINIT_16BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef DLT_STOP_SEC_VAR_NOINIT_16BIT
# undef DLT_STOP_SEC_VAR_NOINIT_16BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_NOINIT_32BIT
# undef DLT_START_SEC_VAR_NOINIT_32BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef DLT_STOP_SEC_VAR_NOINIT_32BIT
# undef DLT_STOP_SEC_VAR_NOINIT_32BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DLT_START_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef DLT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DLT_STOP_SEC_VAR_NOINIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef DLT_START_SEC_VAR_ZERO_INIT_8BIT
# undef DLT_START_SEC_VAR_ZERO_INIT_8BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef DLT_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef DLT_STOP_SEC_VAR_ZERO_INIT_8BIT             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_ZERO_INIT_16BIT
# undef DLT_START_SEC_VAR_ZERO_INIT_16BIT           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef DLT_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef DLT_STOP_SEC_VAR_ZERO_INIT_16BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_ZERO_INIT_32BIT
# undef DLT_START_SEC_VAR_ZERO_INIT_32BIT           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef DLT_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef DLT_STOP_SEC_VAR_ZERO_INIT_32BIT            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DLT_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef DLT_START_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef DLT_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef DLT_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  DLT END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  J1939NM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef J1939NM_START_SEC_CODE
# undef J1939NM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE /* mapped to default code section */
#endif
#ifdef J1939NM_STOP_SEC_CODE
# undef J1939NM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef J1939NM_START_SEC_CONST_8BIT
# undef J1939NM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT /* mapped to default const 8bit section */
#endif
#ifdef J1939NM_STOP_SEC_CONST_8BIT
# undef J1939NM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST /* default const stop section */
#endif

#ifdef J1939NM_START_SEC_CONST_16BIT
# undef J1939NM_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef J1939NM_STOP_SEC_CONST_16BIT
# undef J1939NM_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef J1939NM_START_SEC_CONST_32BIT
# undef J1939NM_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef J1939NM_STOP_SEC_CONST_32BIT
# undef J1939NM_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef J1939NM_START_SEC_CONST_UNSPECIFIED
# undef J1939NM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef J1939NM_STOP_SEC_CONST_UNSPECIFIED
# undef J1939NM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */


/* Postbuild CFG CONST sections */

#ifdef J1939NM_START_SEC_PBCFG
# undef J1939NM_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef J1939NM_STOP_SEC_PBCFG
# undef J1939NM_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef J1939NM_START_SEC_VAR_ZERO_INIT_8BIT
# undef J1939NM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef J1939NM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef J1939NM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef J1939NM_START_SEC_VAR_NOINIT_8BIT
# undef J1939NM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef J1939NM_STOP_SEC_VAR_NOINIT_8BIT
# undef J1939NM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef J1939NM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef J1939NM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef J1939NM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef J1939NM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef J1939NM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef J1939NM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef J1939NM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef J1939NM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */


/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */


/* Postbuild CFG VAR sections */

#ifdef J1939NM_START_SEC_VAR_PBCFG
# undef J1939NM_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef J1939NM_STOP_SEC_VAR_PBCFG
# undef J1939NM_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  J1939NM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANNM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CANNM_START_SEC_CODE
    #undef CANNM_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_CODE                              /* mapped to default code section */
#endif
#ifdef CANNM_STOP_SEC_CODE
    #undef CANNM_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_CODE                               /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CANNM_START_SEC_CONST_8BIT
    #undef CANNM_START_SEC_CONST_8BIT                   /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_CONST_8BIT                        /* mapped to default const section */
#endif
#ifdef CANNM_STOP_SEC_CONST_8BIT
    #undef CANNM_STOP_SEC_CONST_8BIT                    /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

#ifdef CANNM_START_SEC_CONST_UNSPECIFIED
    #undef CANNM_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_CONST_UNSPECIFIED                 /* mapped to default const section */
#endif
#ifdef CANNM_STOP_SEC_CONST_UNSPECIFIED
    #undef CANNM_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

/* Postbuild CFG CONST sections */

#ifdef CANNM_START_SEC_PBCFG
    #undef CANNM_START_SEC_PBCFG                        /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_CONST_PBCFG                       /* mapped to default postbuild section */
#endif
#ifdef CANNM_STOP_SEC_PBCFG
    #undef CANNM_STOP_SEC_PBCFG                         /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef CANNM_START_SEC_VAR_NOINIT_8BIT
    #undef CANNM_START_SEC_VAR_NOINIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_NOINIT_8BIT                   /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_NOINIT_8BIT
    #undef CANNM_STOP_SEC_VAR_NOINIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef CANNM_START_SEC_VAR_NOINIT_16BIT
    #undef CANNM_START_SEC_VAR_NOINIT_16BIT              /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_NOINIT_16BIT                   /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_NOINIT_16BIT
    #undef CANNM_STOP_SEC_VAR_NOINIT_16BIT               /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef CANNM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef CANNM_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_NOINIT_UNSPECIFIED            /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef CANNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

/* VAR INIT sections */
#ifdef CANNM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef CANNM_START_SEC_VAR_INIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_INIT_UNSPECIFIED              /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef CANNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef CANNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED         /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef CANNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif


#ifdef CANNM_START_SEC_VAR_ZERO_INIT_8BIT
    #undef CANNM_START_SEC_VAR_ZERO_INIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_ZERO_INIT_8BIT                   /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef CANNM_STOP_SEC_VAR_ZERO_INIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

/* VAR PBCFG sections */

#ifdef CANNM_START_SEC_VAR_PBCFG
    #undef CANNM_START_SEC_VAR_PBCFG                    /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_PBCFG                         /* mapped to default var section */
#endif
#ifdef CANNM_STOP_SEC_VAR_PBCFG
    #undef CANNM_STOP_SEC_VAR_PBCFG                     /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

/**********************************************************************************************************************
 *  CANNM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FRNM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRNM_START_SEC_CODE
# undef FRNM_START_SEC_CODE                           /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define START_SEC_CODE                               /* mapped to default code section */
#endif
#ifdef FRNM_STOP_SEC_CODE
# undef FRNM_STOP_SEC_CODE                            /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define STOP_SEC_CODE                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRNM_START_SEC_CONST_8BIT
# undef FRNM_START_SEC_CONST_8BIT                     /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define START_SEC_CONST_8BIT                         /* mapped to default const 8bit section */
#endif
#ifdef FRNM_STOP_SEC_CONST_8BIT
# undef FRNM_STOP_SEC_CONST_8BIT                      /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define STOP_SEC_CONST                               /* default const stop section*/
#endif

#ifdef FRNM_START_SEC_CONST_16BIT
# undef FRNM_START_SEC_CONST_16BIT                    /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define START_SEC_CONST_16BIT                        /* mapped to default const 16bit section */
#endif
#ifdef FRNM_STOP_SEC_CONST_16BIT
# undef FRNM_STOP_SEC_CONST_16BIT                     /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define STOP_SEC_CONST                               /* default const stop section*/
#endif

#ifdef FRNM_START_SEC_CONST_UNSPECIFIED
# undef FRNM_START_SEC_CONST_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define START_SEC_CONST_UNSPECIFIED                  /* mapped to default const unspecified section */
#endif
#ifdef FRNM_STOP_SEC_CONST_UNSPECIFIED
# undef FRNM_STOP_SEC_CONST_UNSPECIFIED               /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define STOP_SEC_CONST                               /* default const stop section */
#endif

/* Postbuild CFG CONST sections */

#ifdef FRNM_START_SEC_PBCFG
# undef FRNM_START_SEC_PBCFG                          /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define START_SEC_CONST_PBCFG                        /* mapped to default pbcfg section */
#endif
#ifdef FRNM_STOP_SEC_PBCFG
# undef FRNM_STOP_SEC_PBCFG                           /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define STOP_SEC_CONST                               /* default const stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef FRNM_START_SEC_VAR_NOINIT_8BIT
# undef FRNM_START_SEC_VAR_NOINIT_8BIT                /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define START_SEC_VAR_NOINIT_8BIT                    /* mapped to default var noinit 8bit section */
#endif
#ifdef FRNM_STOP_SEC_VAR_NOINIT_8BIT
# undef FRNM_STOP_SEC_VAR_NOINIT_8BIT                 /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define STOP_SEC_VAR                                 /* default var stop section */
#endif

#ifdef FRNM_START_SEC_VAR_NOINIT_16BIT
# undef FRNM_START_SEC_VAR_NOINIT_16BIT               /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define START_SEC_VAR_NOINIT_16BIT                   /* mapped to default var noinit 16bit section */
#endif
#ifdef FRNM_STOP_SEC_VAR_NOINIT_16BIT
# undef FRNM_STOP_SEC_VAR_NOINIT_16BIT                /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define STOP_SEC_VAR                                 /* default var stop section */
#endif

#ifdef FRNM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRNM_START_SEC_VAR_NOINIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED             /* mapped to default var noinit unspecified section */
#endif
#ifdef FRNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FRNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define STOP_SEC_VAR                                 /* default var stop section */
#endif

/* VAR ZERO INIT section */
#ifdef FRNM_START_SEC_VAR_ZERO_INIT_8BIT
    #undef FRNM_START_SEC_VAR_ZERO_INIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_ZERO_INIT_8BIT              /* mapped to default var section */
#endif
#ifdef FRNM_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef FRNM_STOP_SEC_VAR_ZERO_INIT_8BIT           /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                              /* default var stop section */
#endif

#ifdef FRNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FRNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED          /* mapped to zero init var section */
#endif
#ifdef FRNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef FRNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define STOP_SEC_VAR                                 /* default var stop section */
#endif

/* VAR PBCFG sections */

#ifdef FRNM_START_SEC_VAR_PBCFG
# undef FRNM_START_SEC_VAR_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define START_SEC_VAR_PBCFG                          /* mapped to default var pbcfg section */
#endif
#ifdef FRNM_STOP_SEC_VAR_PBCFG
# undef FRNM_STOP_SEC_VAR_PBCFG                       /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
# define STOP_SEC_VAR                                 /* default var stop section */
#endif

/**********************************************************************************************************************
 *  FRNM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  NMOSEK START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(NMOSEK_START_SEC_CODE)
# undef NMOSEK_START_SEC_CODE                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                 /* mapped to default code section */
#endif
#if defined(NMOSEK_STOP_SEC_CODE)
# undef NMOSEK_STOP_SEC_CODE                            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                  /* default code stop section */
#endif

#if defined(NMOSEK_START_SEC_APPL_CODE)
# undef NMOSEK_START_SEC_APPL_CODE                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                 /* mapped to default code section */
#endif
#if defined(NMOSEK_STOP_SEC_APPL_CODE)
# undef NMOSEK_STOP_SEC_APPL_CODE                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                  /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(NMOSEK_START_SEC_CONST_8)
# undef NMOSEK_START_SEC_CONST_8                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8                              /* mapped to default const section */
#endif
#if defined(NMOSEK_STOP_SEC_CONST_8)
# undef NMOSEK_STOP_SEC_CONST_8                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#if defined(NMOSEK_START_SEC_CONST_32)
# undef NMOSEK_START_SEC_CONST_32                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32                             /* mapped to default const section */
#endif
#if defined(NMOSEK_STOP_SEC_CONST_32)
# undef NMOSEK_STOP_SEC_CONST_32                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

#if defined(NMOSEK_START_SEC_CONST_UNSPECIFIED)
# undef NMOSEK_START_SEC_CONST_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                    /* mapped to default const section */
#endif
#if defined(NMOSEK_STOP_SEC_CONST_UNSPECIFIED)
# undef NMOSEK_STOP_SEC_CONST_UNSPECIFIED               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

/* Postbuild CFG CONST sections */

#if defined(NMOSEK_START_SEC_PBCFG)
# undef NMOSEK_START_SEC_PBCFG                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                          /* mapped to default postbuild section */
#endif
#if defined(NMOSEK_STOP_SEC_PBCFG)
# undef NMOSEK_STOP_SEC_PBCFG                           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

/* Application CONST sections */
#if defined(NMOSEK_START_SEC_APPL_CONST_UNSPECIFIED)
# undef NMOSEK_START_SEC_APPL_CONST_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                    /* mapped to default const section */
#endif
#if defined(NMOSEK_STOP_SEC_APPL_CONST_UNSPECIFIED)
# undef NMOSEK_STOP_SEC_APPL_CONST_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                 /* default const stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(NMOSEK_START_SEC_VAR_NO_INIT_8)
# undef NMOSEK_START_SEC_VAR_NO_INIT_8                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_8                        /* mapped to default var section */
#endif
#if defined(NMOSEK_STOP_SEC_VAR_NO_INIT_8)
# undef NMOSEK_STOP_SEC_VAR_NO_INIT_8                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#if defined(NMOSEK_START_SEC_VAR_NO_INIT_16)
# undef NMOSEK_START_SEC_VAR_NO_INIT_16                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_16                       /* mapped to default var section */
#endif
#if defined(NMOSEK_STOP_SEC_VAR_NO_INIT_16)
# undef NMOSEK_STOP_SEC_VAR_NO_INIT_16                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#if defined(NMOSEK_START_SEC_VAR_NO_INIT_UNSPECIFIED)
# undef NMOSEK_START_SEC_VAR_NO_INIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_UNSPECIFIED              /* mapped to default var section */
#endif
#if defined(NMOSEK_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
# undef NMOSEK_STOP_SEC_VAR_NO_INIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

/* VAR ZERO_INIT sections */
#if defined(NMOSEK_START_SEC_VAR_CLEARED_8)
# undef NMOSEK_START_SEC_VAR_CLEARED_8                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_CLEARED_8                        /* mapped to default var section */
#endif
#if defined(NMOSEK_STOP_SEC_VAR_CLEARED_8)
# undef NMOSEK_STOP_SEC_VAR_CLEARED_8                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

#if defined(NMOSEK_START_SEC_VAR_CLEARED_UNSPECIFIED)
# undef NMOSEK_START_SEC_VAR_CLEARED_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_CLEARED_UNSPECIFIED              /* mapped to default var section */
#endif
#if defined(NMOSEK_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
# undef NMOSEK_STOP_SEC_VAR_CLEARED_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

/* VAR PBCFG sections */

#ifdef NMOSEK_START_SEC_VAR_PBCFG
# undef NMOSEK_START_SEC_VAR_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG                            /* mapped to default var pbcfg section */
#endif
#ifdef NMOSEK_STOP_SEC_VAR_PBCFG
# undef NMOSEK_STOP_SEC_VAR_PBCFG                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* default var stop section */
#endif

/**********************************************************************************************************************
 *  NMOSEK END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LINNM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef LINNM_START_SEC_CODE
    #undef LINNM_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CODE                              /* mapped to default code section */
#endif
#ifdef LINNM_STOP_SEC_CODE
    #undef LINNM_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CODE                               /*default code stop section*/
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef LINNM_START_SEC_CONST_8BIT
    #undef LINNM_START_SEC_CONST_8BIT                   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_8BIT                        /* mapped to default const section */
#endif
#ifdef LINNM_STOP_SEC_CONST_8BIT
    #undef LINNM_STOP_SEC_CONST_8BIT                    /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

#ifdef LINNM_START_SEC_CONST_32BIT
    #undef LINNM_START_SEC_CONST_32BIT                  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_32BIT                       /* mapped to default const section */
#endif
#ifdef LINNM_STOP_SEC_CONST_32BIT
    #undef LINNM_STOP_SEC_CONST_32BIT                   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

#ifdef LINNM_START_SEC_CONST_UNSPECIFIED
    #undef LINNM_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_UNSPECIFIED                 /* mapped to default const section */
#endif
#ifdef LINNM_STOP_SEC_CONST_UNSPECIFIED
    #undef LINNM_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

/* Postbuild CFG CONST sections */

#ifdef LINNM_START_SEC_PBCFG
    #undef LINNM_START_SEC_PBCFG                        /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_PBCFG                       /* mapped to default postbuild section */
#endif
#ifdef LINNM_STOP_SEC_PBCFG
    #undef LINNM_STOP_SEC_PBCFG                         /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

#ifdef LINNM_START_SEC_PBCFG_ROOT
    #undef LINNM_START_SEC_PBCFG_ROOT                   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_PBCFG                       /* mapped to default postbuild section */
#endif
#ifdef LINNM_STOP_SEC_PBCFG_ROOT
    #undef LINNM_STOP_SEC_PBCFG_ROOT                    /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef LINNM_START_SEC_VAR_NOINIT_8BIT
    #undef LINNM_START_SEC_VAR_NOINIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_8BIT                   /* mapped to default var section */
#endif
#ifdef LINNM_STOP_SEC_VAR_NOINIT_8BIT
    #undef LINNM_STOP_SEC_VAR_NOINIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef LINNM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef LINNM_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_UNSPECIFIED            /* mapped to default var section */
#endif
#ifdef LINNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef LINNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

/* VAR FAST NOINIT sections */

#ifdef LINNM_START_SEC_VAR_FAST_NOINIT_8BIT
    #undef LINNM_START_SEC_VAR_FAST_NOINIT_8BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_FAST_NOINIT_8BIT              /* mapped to default var section */
#endif
#ifdef LINNM_STOP_SEC_VAR_FAST_NOINIT_8BIT
    #undef LINNM_STOP_SEC_VAR_FAST_NOINIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef LINNM_START_SEC_VAR_FAST_NOINIT_16BIT
    #undef LINNM_START_SEC_VAR_FAST_NOINIT_16BIT        /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_FAST_NOINIT_16BIT             /* mapped to default var section */
#endif
#ifdef LINNM_STOP_SEC_VAR_FAST_NOINIT_16BIT
    #undef LINNM_STOP_SEC_VAR_FAST_NOINIT_16BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef LINNM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef LINNM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED       /* mapped to default var section */
#endif
#ifdef LINNM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef LINNM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

/* VAR FAST ZERO INIT sections */

#ifdef LINNM_START_SEC_VAR_FAST_ZERO_INIT_8BIT
    #undef LINNM_START_SEC_VAR_FAST_ZERO_INIT_8BIT      /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_FAST_ZERO_INIT_8BIT           /* mapped to default var section */
#endif
#ifdef LINNM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
    #undef LINNM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT       /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef LINNM_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #undef LINNM_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED       /* mapped to default var section */
#endif
#ifdef LINNM_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
    #undef LINNM_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR                                   /* default var stop section */
#endif

/**********************************************************************************************************************
 *  LINNM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  UDPNM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef UDPNM_START_SEC_CODE
    #undef UDPNM_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_CODE                              /* mapped to default code section */
#endif
#ifdef UDPNM_STOP_SEC_CODE
    #undef UDPNM_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_CODE                               /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef UDPNM_START_SEC_CONST_8BIT
    #undef UDPNM_START_SEC_CONST_8BIT                   /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_CONST_8BIT                        /* mapped to default const section */
#endif
#ifdef UDPNM_STOP_SEC_CONST_8BIT
    #undef UDPNM_STOP_SEC_CONST_8BIT                    /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

#ifdef UDPNM_START_SEC_CONST_UNSPECIFIED
    #undef UDPNM_START_SEC_CONST_UNSPECIFIED            /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_CONST_UNSPECIFIED                 /* mapped to default const section */
#endif
#ifdef UDPNM_STOP_SEC_CONST_UNSPECIFIED
    #undef UDPNM_STOP_SEC_CONST_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

/* Postbuild CFG CONST sections */

#ifdef UDPNM_START_SEC_PBCFG
    #undef UDPNM_START_SEC_PBCFG                        /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_CONST_PBCFG                       /* mapped to default postbuild section */
#endif
#ifdef UDPNM_STOP_SEC_PBCFG
    #undef UDPNM_STOP_SEC_PBCFG                         /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_CONST                              /* default const stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef UDPNM_START_SEC_VAR_NOINIT_8BIT
    #undef UDPNM_START_SEC_VAR_NOINIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_NOINIT_8BIT                   /* mapped to default var section */
#endif
#ifdef UDPNM_STOP_SEC_VAR_NOINIT_8BIT
    #undef UDPNM_STOP_SEC_VAR_NOINIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef UDPNM_START_SEC_VAR_NOINIT_16BIT
    #undef UDPNM_START_SEC_VAR_NOINIT_16BIT              /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_NOINIT_16BIT                   /* mapped to default var section */
#endif
#ifdef UDPNM_STOP_SEC_VAR_NOINIT_16BIT
    #undef UDPNM_STOP_SEC_VAR_NOINIT_16BIT               /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef UDPNM_START_SEC_VAR_NOINIT_32BIT
    #undef UDPNM_START_SEC_VAR_NOINIT_32BIT              /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_NOINIT_32BIT                   /* mapped to default var section */
#endif
#ifdef UDPNM_STOP_SEC_VAR_NOINIT_32BIT
    #undef UDPNM_STOP_SEC_VAR_NOINIT_32BIT               /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef UDPNM_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef UDPNM_START_SEC_VAR_NOINIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_NOINIT_UNSPECIFIED            /* mapped to default var section */
#endif
#ifdef UDPNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef UDPNM_STOP_SEC_VAR_NOINIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

/* VAR INIT sections */
#ifdef UDPNM_START_SEC_VAR_INIT_UNSPECIFIED
    #undef UDPNM_START_SEC_VAR_INIT_UNSPECIFIED         /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_INIT_UNSPECIFIED              /* mapped to default var section */
#endif
#ifdef UDPNM_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef UDPNM_STOP_SEC_VAR_INIT_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

#ifdef UDPNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef UDPNM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED         /* mapped to default var section */
#endif
#ifdef UDPNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef UDPNM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif


#ifdef UDPNM_START_SEC_VAR_ZERO_INIT_8BIT
    #undef UDPNM_START_SEC_VAR_ZERO_INIT_8BIT              /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_ZERO_INIT_8BIT                   /* mapped to default var section */
#endif
#ifdef UDPNM_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef UDPNM_STOP_SEC_VAR_ZERO_INIT_8BIT               /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

/* VAR PBCFG sections */

#ifdef UDPNM_START_SEC_VAR_PBCFG
    #undef UDPNM_START_SEC_VAR_PBCFG                    /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define START_SEC_VAR_PBCFG                         /* mapped to default var section */
#endif
#ifdef UDPNM_STOP_SEC_VAR_PBCFG
    #undef UDPNM_STOP_SEC_VAR_PBCFG                     /* PRQA S 0841 */ /* MD_MSR_Rule20.5 */
    #define STOP_SEC_VAR                                /* default var stop section */
#endif

/**********************************************************************************************************************
 *  UDPNM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CSM_START_SEC_CODE
# undef CSM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef CSM_STOP_SEC_CODE
# undef CSM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef CSM_START_SEC_APPL_CODE
# undef CSM_START_SEC_APPL_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef CSM_STOP_SEC_APPL_CODE
# undef CSM_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CSM_START_SEC_CONST_8BIT
# undef CSM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif

#ifdef CSM_STOP_SEC_CONST_8BIT
# undef CSM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef CSM_START_SEC_CONST_UNSPECIFIED
# undef CSM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CSM_STOP_SEC_CONST_UNSPECIFIED
# undef CSM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef CSM_START_SEC_VAR_NOINIT_8BIT
# undef CSM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_8BIT
# undef CSM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef CSM_START_SEC_VAR_NOINIT_16BIT
# undef CSM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_16BIT
# undef CSM_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef CSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef CSM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CSM END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  KEYM START
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef KEYM_START_SEC_CODE
# undef KEYM_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef KEYM_STOP_SEC_CODE
# undef KEYM_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#ifdef KEYM_START_SEC_APPL_CODE
# undef KEYM_START_SEC_APPL_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef KEYM_STOP_SEC_APPL_CODE
# undef KEYM_STOP_SEC_APPL_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef KEYM_START_SEC_CONST_8
# undef KEYM_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8
#endif
#ifdef KEYM_STOP_SEC_CONST_8
# undef KEYM_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef KEYM_START_SEC_CONST_16
# undef KEYM_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16
#endif
#ifdef KEYM_STOP_SEC_CONST_16
# undef KEYM_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef KEYM_START_SEC_CONST_32
# undef KEYM_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32
#endif
#ifdef KEYM_STOP_SEC_CONST_32
# undef KEYM_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef KEYM_START_SEC_CONST_UNSPECIFIED
# undef KEYM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef KEYM_STOP_SEC_CONST_UNSPECIFIED
# undef KEYM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */

#ifdef KEYM_START_SEC_VAR_NO_INIT_8
# undef KEYM_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_8
# undef KEYM_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_NO_INIT_16
# undef KEYM_START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_16
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_16
# undef KEYM_STOP_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_NO_INIT_32
# undef KEYM_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_32
# undef KEYM_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef KEYM_START_SEC_VAR_CLEARED_8
# undef KEYM_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_8
#endif
#ifdef KEYM_STOP_SEC_VAR_CLEARED_8
# undef KEYM_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  KEYM END
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  FVM START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(FVM_START_SEC_CODE)
# undef FVM_START_SEC_CODE      /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define START_SEC_CODE /* mapped to default code section */
#endif
#if defined(FVM_STOP_SEC_CODE)
# undef FVM_STOP_SEC_CODE       /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define STOP_SEC_CODE  /* default code stop section */
#endif

#if defined(FVM_START_SEC_CODE_FAST)
# undef FVM_START_SEC_CODE_FAST /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(FVM_STOP_SEC_CODE_FAST)
# undef FVM_STOP_SEC_CODE_FAST  /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define STOP_SEC_CODE  /* default code stop section */
#endif

#if defined(FVM_START_SEC_CODE_ISR)
# undef FVM_START_SEC_CODE_ISR  /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(FVM_STOP_SEC_CODE_ISR)
# undef FVM_STOP_SEC_CODE_ISR   /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define STOP_SEC_CODE  /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(FVM_START_SEC_CONST_8BIT)
# undef FVM_START_SEC_CONST_8BIT  /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT   /* mapped to default const 8bit section */
#endif
#if defined(FVM_STOP_SEC_CONST_8BIT)
# undef FVM_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define STOP_SEC_CONST /* default const stop section */
#endif

#if defined(FVM_START_SEC_CONST_16BIT)
# undef FVM_START_SEC_CONST_16BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(FVM_STOP_SEC_CONST_16BIT)
# undef FVM_STOP_SEC_CONST_16BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(FVM_START_SEC_CONST_32BIT)
# undef FVM_START_SEC_CONST_32BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(FVM_STOP_SEC_CONST_32BIT)
# undef FVM_STOP_SEC_CONST_32BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


#if defined(FVM_START_SEC_CONST_64BIT)
# undef FVM_START_SEC_CONST_64BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_CONST_64BIT
#endif
#if defined(FVM_STOP_SEC_CONST_64BIT)
# undef FVM_STOP_SEC_CONST_64BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


#if defined(FVM_START_SEC_CONST_UNSPECIFIED)
# undef FVM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(FVM_STOP_SEC_CONST_UNSPECIFIED)
# undef FVM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(FVM_START_SEC_FAST_CONST_8BIT)
# undef FVM_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_8BIT
#endif
#if defined(FVM_STOP_SEC_FAST_CONST_8BIT)
# undef FVM_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(FVM_START_SEC_FAST_CONST_16BIT)
# undef FVM_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_16BIT
#endif
#if defined(FVM_STOP_SEC_FAST_CONST_16BIT)
# undef FVM_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(FVM_START_SEC_FAST_CONST_32BIT)
# undef FVM_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_32BIT
#endif
#if defined(FVM_STOP_SEC_FAST_CONST_32BIT)
# undef FVM_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(FVM_START_SEC_FAST_CONST_64BIT)
# undef FVM_START_SEC_FAST_CONST_64BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_64BIT
#endif
#if defined(FVM_STOP_SEC_FAST_CONST_64BIT)
# undef FVM_STOP_SEC_FAST_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(FVM_START_SEC_FAST_CONST_UNSPECIFIED)
# undef FVM_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#if defined(FVM_STOP_SEC_FAST_CONST_UNSPECIFIED)
# undef FVM_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#if defined(FVM_START_SEC_PBCFG_ROOT)
# undef FVM_START_SEC_PBCFG_ROOT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(FVM_STOP_SEC_PBCFG_ROOT)
# undef FVM_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#if defined(FVM_START_SEC_PBCFG_GLOBALROOT)
# undef FVM_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#if defined(FVM_STOP_SEC_PBCFG_GLOBALROOT)
# undef FVM_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(FVM_START_SEC_PBCFG)
# undef FVM_START_SEC_PBCFG /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(FVM_STOP_SEC_PBCFG)
# undef FVM_STOP_SEC_PBCFG /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(FVM_START_SEC_VAR_INIT_8BIT)
# undef FVM_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT        /* mapped to default var init 8bit section */
#endif
#if defined(FVM_STOP_SEC_VAR_INIT_8BIT)
# undef FVM_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_VAR   /* default var stop section */
#endif

#if defined(FVM_START_SEC_VAR_INIT_16BIT)
# undef FVM_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(FVM_STOP_SEC_VAR_INIT_16BIT)
# undef FVM_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_INIT_32BIT)
# undef FVM_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(FVM_STOP_SEC_VAR_INIT_32BIT)
# undef FVM_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_INIT_64BIT)
# undef FVM_START_SEC_VAR_INIT_64BIT /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_64BIT
#endif
#if defined(FVM_STOP_SEC_VAR_INIT_64BIT)
# undef FVM_STOP_SEC_VAR_INIT_64BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_INIT_UNSPECIFIED)
# undef FVM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(FVM_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef FVM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(FVM_START_SEC_VAR_NOINIT_8BIT)
# undef FVM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOINIT_8BIT)
# undef FVM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOINIT_16BIT)
# undef FVM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOINIT_16BIT)
# undef FVM_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOINIT_32BIT)
# undef FVM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOINIT_32BIT)
# undef FVM_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOINIT_64BIT)
# undef FVM_START_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_64BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOINIT_64BIT)
# undef FVM_STOP_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef FVM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(FVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef FVM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(FVM_START_SEC_VAR_PBCFG)
# undef FVM_START_SEC_VAR_PBCFG /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(FVM_STOP_SEC_VAR_PBCFG)
# undef FVM_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(FVM_START_SEC_VAR_ZERO_INIT_8BIT)
# undef FVM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(FVM_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef FVM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_ZERO_INIT_16BIT)
# undef FVM_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(FVM_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef FVM_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_ZERO_INIT_32BIT)
# undef FVM_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(FVM_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef FVM_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_ZERO_INIT_64BIT)
# undef FVM_START_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_64BIT
#endif
#if defined(FVM_STOP_SEC_VAR_ZERO_INIT_64BIT)
# undef FVM_STOP_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef FVM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(FVM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef FVM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(FVM_START_SEC_VAR_FAST_INIT_8BIT)
# undef FVM_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef FVM_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_FAST_INIT_16BIT)
# undef FVM_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef FVM_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_FAST_INIT_32BIT)
# undef FVM_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef FVM_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_FAST_INIT_64BIT)
# undef FVM_START_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_64BIT
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_INIT_64BIT)
# undef FVM_STOP_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef FVM_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef FVM_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(FVM_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef FVM_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef FVM_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef FVM_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef FVM_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef FVM_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef FVM_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_FAST_NOINIT_64BIT)
# undef FVM_START_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_64BIT
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_NOINIT_64BIT)
# undef FVM_STOP_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef FVM_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef FVM_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(FVM_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef FVM_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef FVM_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef FVM_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef FVM_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef FVM_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef FVM_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_FAST_ZERO_INIT_64BIT)
# undef FVM_START_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_64BIT
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_ZERO_INIT_64BIT)
# undef FVM_STOP_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef FVM_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(FVM_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef FVM_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(FVM_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef FVM_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef FVM_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef FVM_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef FVM_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef FVM_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef FVM_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOCACHE_INIT_64BIT)
# undef FVM_START_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_64BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_INIT_64BIT)
# undef FVM_STOP_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef FVM_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */    /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef FVM_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(FVM_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef FVM_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef FVM_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef FVM_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef FVM_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef FVM_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef FVM_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOCACHE_NOINIT_64BIT)
# undef FVM_START_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_64BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_NOINIT_64BIT)
# undef FVM_STOP_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef FVM_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */  /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef FVM_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */   /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(FVM_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef FVM_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef FVM_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef FVM_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef FVM_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef FVM_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef FVM_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT)
# undef FVM_START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */     /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT)
# undef FVM_STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */      /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(FVM_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef FVM_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */       /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(FVM_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef FVM_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */        /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FVM END
 *********************************************************************************************************************/

/** FiM **********************************************************************/

/*---------------------START-MODULE-SPECIFIC-START-SECTIONS------------------*/

/* Memory Section Group 'Constant' */

#ifdef FIM_START_SEC_CODE
# undef FIM_START_SEC_CODE                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                 /* mapped to default code section */
#endif

#ifdef FIM_START_SEC_CONST_8BIT
# undef FIM_START_SEC_CONST_8BIT                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                          /* mapped to default const section */
#endif

#ifdef FIM_START_SEC_CONST_16BIT
# undef FIM_START_SEC_CONST_16BIT                        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                          /* mapped to default const section */
#endif

#ifdef FIM_START_SEC_CONST_UNSPECIFIED
# undef FIM_START_SEC_CONST_UNSPECIFIED                  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED                   /* mapped to default const section */
#endif

#ifdef FIM_START_SEC_PBCFG
# undef FIM_START_SEC_PBCFG                              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                         /* mapped to default const section */
#endif

#ifdef FIM_START_SEC_PBCFG_ROOT
# undef FIM_START_SEC_PBCFG_ROOT                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG                         /* mapped to default const section */
#endif


/* Memory Section Group 'Master' */

#ifdef FIM_START_SEC_VAR_NOINIT_16BIT
# undef FIM_START_SEC_VAR_NOINIT_16BIT                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT                      /* mapped to default var section */
#endif

#ifdef FIM_START_SEC_VAR_NOINIT_32BIT
# undef FIM_START_SEC_VAR_NOINIT_32BIT                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT                      /* mapped to default var section */
#endif

#ifdef FIM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef FIM_START_SEC_VAR_NOINIT_UNSPECIFIED             /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED                /* mapped to default var section */
#endif

#ifdef FIM_START_SEC_VAR_INIT_8BIT
# undef FIM_START_SEC_VAR_INIT_8BIT                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT                         /* mapped to default var section */
#endif


/* Memory Section Group 'MasterSatAll' */

#ifdef FIM_START_SEC_MASTERSAT_ALL_VAR_NOINIT_32BIT
# undef FIM_START_SEC_MASTERSAT_ALL_VAR_NOINIT_32BIT     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT                      /* mapped to default var section */
#endif


/* Memory Section Group 'Restricted' */

#ifdef FIM_START_SEC_VAR_NOINIT_16BIT_RESTRICTED
# undef FIM_START_SEC_VAR_NOINIT_16BIT_RESTRICTED        /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT                      /* mapped to default var section */
#endif

#ifdef FIM_START_SEC_VAR_NOINIT_UNSPECIFIED_RESTRICTED
# undef FIM_START_SEC_VAR_NOINIT_UNSPECIFIED_RESTRICTED  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED                /* mapped to default var section */
#endif

#ifdef FIM_START_SEC_VAR_INIT_8BIT_RESTRICTED
# undef FIM_START_SEC_VAR_INIT_8BIT_RESTRICTED           /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT                         /* mapped to default var section */
#endif



/*---------------------STOP-MODULE-SPECIFIC-START-SECTIONS-------------------*/

/*---------------------START-MODULE-SPECIFIC-STOP-SECTIONS-------------------*/

/* Memory Section Group 'Constant' */

#ifdef FIM_STOP_SEC_CODE
# undef FIM_STOP_SEC_CODE                                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                  /* mapped to default code section */
#endif

#ifdef FIM_STOP_SEC_CONST_8BIT
# undef FIM_STOP_SEC_CONST_8BIT                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                /* mapped to default const section */
#endif

#ifdef FIM_STOP_SEC_CONST_16BIT
# undef FIM_STOP_SEC_CONST_16BIT                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                /* mapped to default const section */
#endif

#ifdef FIM_STOP_SEC_CONST_UNSPECIFIED
# undef FIM_STOP_SEC_CONST_UNSPECIFIED                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                /* mapped to default const section */
#endif

#ifdef FIM_STOP_SEC_PBCFG
# undef FIM_STOP_SEC_PBCFG                               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                  /* mapped to default const section */
#endif

#ifdef FIM_STOP_SEC_PBCFG_ROOT
# undef FIM_STOP_SEC_PBCFG_ROOT                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                  /* mapped to default const section */
#endif


/* Memory Section Group 'Master' */

#ifdef FIM_STOP_SEC_VAR_NOINIT_16BIT
# undef FIM_STOP_SEC_VAR_NOINIT_16BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                    /* mapped to default var section */
#endif

#ifdef FIM_STOP_SEC_VAR_NOINIT_32BIT
# undef FIM_STOP_SEC_VAR_NOINIT_32BIT                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                    /* mapped to default var section */
#endif

#ifdef FIM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef FIM_STOP_SEC_VAR_NOINIT_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                    /* mapped to default var section */
#endif

#ifdef FIM_STOP_SEC_VAR_INIT_8BIT
# undef FIM_STOP_SEC_VAR_INIT_8BIT                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                    /* mapped to default var section */
#endif


/* Memory Section Group 'MasterSatAll' */

#ifdef FIM_STOP_SEC_MASTERSAT_ALL_VAR_NOINIT_32BIT
# undef FIM_STOP_SEC_MASTERSAT_ALL_VAR_NOINIT_32BIT     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                   /* mapped to default var section */
#endif


/* Memory Section Group 'Restricted' */

#ifdef FIM_STOP_SEC_VAR_NOINIT_16BIT_RESTRICTED
# undef FIM_STOP_SEC_VAR_NOINIT_16BIT_RESTRICTED         /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                    /* mapped to default var section */
#endif

#ifdef FIM_STOP_SEC_VAR_NOINIT_UNSPECIFIED_RESTRICTED
# undef FIM_STOP_SEC_VAR_NOINIT_UNSPECIFIED_RESTRICTED   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                    /* mapped to default var section */
#endif

#ifdef FIM_STOP_SEC_VAR_INIT_8BIT_RESTRICTED
# undef FIM_STOP_SEC_VAR_INIT_8BIT_RESTRICTED            /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                    /* mapped to default var section */
#endif


#include "FiM_MemMap.h"

/*---------------------STOP-MODULE-SPECIFIC-STOP-SECTIONS--------------------*/

/** End of FiM ***************************************************************/



/**********************************************************************************************************************
 *  WDGM START
 *********************************************************************************************************************/

#include "WdgM_OsMemMap.h" 

/*******  CODE sections **********************************************************************************************/

#if defined WDGM_START_SEC_CODE
# undef WDGM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#if defined WDGM_STOP_SEC_CODE
# undef WDGM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#if defined(WDGM_START_SEC_APPL_CODE)
# undef WDGM_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#if defined(WDGM_STOP_SEC_APPL_CODE)
# undef WDGM_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#if defined WDGM_START_SEC_CONST_8BIT
# undef WDGM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined WDGM_STOP_SEC_CONST_8BIT
# undef WDGM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined WDGM_START_SEC_CONST_16BIT
# undef WDGM_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined WDGM_STOP_SEC_CONST_16BIT
# undef WDGM_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined WDGM_START_SEC_CONST_32BIT
# undef WDGM_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined WDGM_STOP_SEC_CONST_32BIT
# undef WDGM_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined WDGM_START_SEC_CONST_UNSPECIFIED
# undef WDGM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined WDGM_STOP_SEC_CONST_UNSPECIFIED
# undef WDGM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined WDGM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef WDGM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined WDGM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef WDGM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_NOINIT_8BIT
# undef WDGM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined WDGM_STOP_SEC_VAR_NOINIT_8BIT
# undef WDGM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_NOINIT_16BIT
# undef WDGM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined WDGM_STOP_SEC_VAR_NOINIT_16BIT
# undef WDGM_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined WDGM_START_SEC_VAR_NOINIT_32BIT
# undef WDGM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined WDGM_STOP_SEC_VAR_NOINIT_32BIT
# undef WDGM_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(WDGM_START_SEC_VAR_CLEARED_32BIT)
# undef WDGM_START_SEC_VAR_CLEARED_32BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(WDGM_STOP_SEC_VAR_CLEARED_32BIT)
# undef WDGM_STOP_SEC_VAR_CLEARED_32BIT    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR INIT sections */

#if defined WDGM_START_SEC_VAR_32BIT
# undef WDGM_START_SEC_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined WDGM_STOP_SEC_VAR_32BIT
# undef WDGM_STOP_SEC_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* Global Shared Variables of the WdgM.
 * If a SafeContext OS is used this section will be defined by the OS.
 * If no SafeContext OS is used this section has to be mapped to a memory area where all SWCs has access
 */
/*#if defined GlobalShared_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef GlobalShared_START_SEC_VAR_NOINIT_UNSPECIFIED*/ /* PRQA S 0841 */ /* MD_MSR_Undef */
/*# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined GlobalShared_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef GlobalShared_STOP_SEC_VAR_NOINIT_UNSPECIFIED*/ /* PRQA S 0841 */ /* MD_MSR_Undef */
/*# define STOP_SEC_VAR
#endif*/
/* or the following section (depending on which OS version is used) */
/*#if defined OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
# undef OS_START_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED*/ /* PRQA S 0841 */ /* MD_MSR_Undef */
/*# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED
# undef OS_STOP_SEC_GLOBALSHARED_VAR_NOINIT_UNSPECIFIED*/ /* PRQA S 0841 */ /* MD_MSR_Undef */
/*# define STOP_SEC_VAR
#endif*/
 
/**********************************************************************************************************************
 *  WDGM END
 *********************************************************************************************************************/

#ifdef DET_START_SEC_CODE
# undef DET_START_SEC_CODE                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef DET_STOP_SEC_CODE
# undef DET_STOP_SEC_CODE                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#ifdef DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef DET_START_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_VAR_NOINIT_8BIT
# undef DET_START_SEC_VAR_NOINIT_8BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef DET_STOP_SEC_VAR_NOINIT_8BIT
# undef DET_STOP_SEC_VAR_NOINIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_VAR_INIT_UNSPECIFIED
# undef DET_START_SEC_VAR_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DET_STOP_SEC_VAR_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DET_START_SEC_CONST_UNSPECIFIED
# undef DET_START_SEC_CONST_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DET_STOP_SEC_CONST_UNSPECIFIED
# undef DET_STOP_SEC_CONST_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif



/**********************************************************************************************************************
 *  SysService_AsrRamTst START
 *********************************************************************************************************************/

#ifdef RAMTST_START_SEC_CODE
  #undef RAMTST_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE
#endif

#ifdef RAMTST_STOP_SEC_CODE
  #undef RAMTST_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE
#endif

#ifdef RAMTST_START_SEC_VAR_INIT_UNSPECIFIED
  #undef RAMTST_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_VAR_INIT_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED
  #undef RAMTST_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_NO_INIT_8
  #undef RAMTST_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_VAR_NO_INIT_8
#endif

#ifdef RAMTST_STOP_SEC_VAR_NO_INIT_8
  #undef RAMTST_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_NO_INIT_32
  #undef RAMTST_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_VAR_NO_INIT_32
#endif

#ifdef RAMTST_STOP_SEC_VAR_NO_INIT_32
  #undef RAMTST_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef RAMTST_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #undef RAMTST_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_VAR
#endif

#ifdef RAMTST_START_SEC_CONST_32
  #undef RAMTST_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_32
#endif

#ifdef RAMTST_STOP_SEC_CONST_32
  #undef RAMTST_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST
#endif

#ifdef RAMTST_START_SEC_CONST_UNSPECIFIED
  #undef RAMTST_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_CONST_UNSPECIFIED
  #undef RAMTST_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST
#endif

#ifdef RAMTST_START_SEC_CONST_PBCFG
  #undef RAMTST_START_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_CONST_PBCFG
  #undef RAMTST_STOP_SEC_CONST_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST
#endif

#ifdef RAMTST_START_SEC_CONST_PBCFG_ROOT
  #undef RAMTST_START_SEC_CONST_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef RAMTST_STOP_SEC_CONST_PBCFG_ROOT
  #undef RAMTST_STOP_SEC_CONST_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  SysService_AsrRamTst END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  STBM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(STBM_START_SEC_CODE)
# undef STBM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE /* mapped to default code section */
#endif
#if defined(STBM_STOP_SEC_CODE)
# undef STBM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE  /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(STBM_START_SEC_CONST_UNSPECIFIED)
# undef STBM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(STBM_STOP_SEC_CONST_UNSPECIFIED)
# undef STBM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(STBM_START_SEC_CONST_8BIT)
# undef STBM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined(STBM_STOP_SEC_CONST_8BIT)
# undef STBM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(STBM_START_SEC_VAR_NOINIT_8BIT)
# undef STBM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(STBM_STOP_SEC_VAR_NOINIT_8BIT)
# undef STBM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(STBM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef STBM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(STBM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef STBM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(STBM_START_SEC_VAR_ZERO_INIT_8BIT)
# undef STBM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(STBM_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef STBM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(STBM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef STBM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(STBM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef STBM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  STBM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTSYN START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTSYN_START_SEC_CODE)
# undef CANTSYN_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE          /* mapped to default code section */
#endif
#if defined(CANTSYN_STOP_SEC_CODE)
# undef CANTSYN_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE           /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTSYN_START_SEC_CONST_UNSPECIFIED)
# undef CANTSYN_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTSYN_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTSYN_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTSYN_START_SEC_CONST_8BIT)
# undef CANTSYN_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined(CANTSYN_STOP_SEC_CONST_8BIT)
# undef CANTSYN_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(CANTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTSYN_START_SEC_VAR_NOINIT_8BIT)
# undef CANTSYN_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTSYN_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTSYN_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(CANTSYN_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTSYN_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTSYN_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTSYN_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTSYN END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FRTSYN START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(FRTSYN_START_SEC_CODE)
# undef FRTSYN_START_SEC_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE          /* mapped to default code section */
#endif
#if defined(FRTSYN_STOP_SEC_CODE)
# undef FRTSYN_STOP_SEC_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE           /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(FRTSYN_START_SEC_CONST_UNSPECIFIED)
# undef FRTSYN_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(FRTSYN_STOP_SEC_CONST_UNSPECIFIED)
# undef FRTSYN_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(FRTSYN_START_SEC_CONST_8BIT)
# undef FRTSYN_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined(FRTSYN_STOP_SEC_CONST_8BIT)
# undef FRTSYN_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(FRTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef FRTSYN_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(FRTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef FRTSYN_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(FRTSYN_START_SEC_VAR_NOINIT_8BIT)
# undef FRTSYN_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(FRTSYN_STOP_SEC_VAR_NOINIT_8BIT)
# undef FRTSYN_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(FRTSYN_START_SEC_VAR_ZERO_INIT_8BIT)
# undef FRTSYN_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(FRTSYN_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef FRTSYN_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  FRTSYN END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DNS START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef DNS_START_SEC_CODE
# undef DNS_START_SEC_CODE                                                                                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                        /* mapped to default code section */
#endif
#ifdef DNS_STOP_SEC_CODE
# undef DNS_STOP_SEC_CODE                                                                                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                         /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef DNS_START_SEC_CONST_8
# undef DNS_START_SEC_CONST_8                                                                                           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8                                   /* mapped to default const 8bit section */
#endif
#ifdef DNS_STOP_SEC_CONST_8
# undef DNS_STOP_SEC_CONST_8                                                                                            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                                         /* default const stop section */
#endif

#ifdef DNS_START_SEC_CONST_16
# undef DNS_START_SEC_CONST_16                                                                                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16
#endif
#ifdef DNS_STOP_SEC_CONST_16
# undef DNS_STOP_SEC_CONST_16                                                                                           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef DNS_START_SEC_CONST_32
# undef DNS_START_SEC_CONST_32                                                                                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32
#endif
#ifdef DNS_STOP_SEC_CONST_32
# undef DNS_STOP_SEC_CONST_32                                                                                           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef DNS_START_SEC_CONST_UNSPECIFIED
# undef DNS_START_SEC_CONST_UNSPECIFIED                                                                                 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef DNS_STOP_SEC_CONST_UNSPECIFIED
# undef DNS_STOP_SEC_CONST_UNSPECIFIED                                                                                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */


#ifdef DNS_START_SEC_VAR_INIT_UNSPECIFIED
# undef DNS_START_SEC_VAR_INIT_UNSPECIFIED                                                                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef DNS_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef DNS_STOP_SEC_VAR_INIT_UNSPECIFIED                                                                               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef DNS_START_SEC_VAR_NO_INIT_8
# undef DNS_START_SEC_VAR_NO_INIT_8                                                                                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef DNS_STOP_SEC_VAR_NO_INIT_8
# undef DNS_STOP_SEC_VAR_NO_INIT_8                                                                                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DNS_START_SEC_VAR_NO_INIT_16
# undef DNS_START_SEC_VAR_NO_INIT_16                                                                                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_16
#endif
#ifdef DNS_STOP_SEC_VAR_NO_INIT_16
# undef DNS_STOP_SEC_VAR_NO_INIT_16                                                                                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DNS_START_SEC_VAR_NO_INIT_32
# undef DNS_START_SEC_VAR_NO_INIT_32                                                                                    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef DNS_STOP_SEC_VAR_NO_INIT_32
# undef DNS_STOP_SEC_VAR_NO_INIT_32                                                                                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef DNS_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef DNS_START_SEC_VAR_NO_INIT_UNSPECIFIED                                                                           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef DNS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef DNS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED                                                                            /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef DNS_START_SEC_VAR_CLEARED_8
# undef DNS_START_SEC_VAR_CLEARED_8                                                                                     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_8
#endif
#ifdef DNS_STOP_SEC_VAR_CLEARED_8
# undef DNS_STOP_SEC_VAR_CLEARED_8                                                                                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  DNS END
 *********************************************************************************************************************/

/* E2EPW_MemMap.inc: End-To-End Protection Wrapper Memory Mapping: */


/* Code */
/* To be used for mapping code to application block, boot block, external flash etc. */
#if defined   E2EPW_START_SEC_CODE
#undef        E2EPW_START_SEC_CODE
#define           START_SEC_CODE

#elif defined E2EPW_STOP_SEC_CODE
#undef        E2EPW_STOP_SEC_CODE
#define             STOP_SEC_CODE


/* Constants */
/* To be used for global or static constants.  */
#elif defined E2EPW_START_SEC_CONST_UNSPECIFIED
#undef        E2EPW_START_SEC_CONST_UNSPECIFIED
#define             START_SEC_CONST_UNSPECIFIED

#elif defined E2EPW_STOP_SEC_CONST_UNSPECIFIED
#undef        E2EPW_STOP_SEC_CONST_UNSPECIFIED
#define             STOP_SEC_CONST


/* Var init unspecified */
#elif defined E2EPW_START_SEC_VAR_INIT_UNSPECIFIED
#undef        E2EPW_START_SEC_VAR_INIT_UNSPECIFIED
#define             START_SEC_VAR_INIT_UNSPECIFIED

#elif defined E2EPW_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef        E2EPW_STOP_SEC_VAR_INIT_UNSPECIFIED
#define             STOP_SEC_VAR


/* Var uninitialized unspecified */
/* To be used for all global or static variables that are never initialized */
#elif defined E2EPW_START_SEC_VAR_NOINIT_UNSPECIFIED
#undef        E2EPW_START_SEC_VAR_NOINIT_UNSPECIFIED
#define             START_SEC_VAR_NOINIT_UNSPECIFIED

#elif defined E2EPW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#undef        E2EPW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#define             STOP_SEC_VAR


/* Var zero init unspecified */
#elif defined E2EPW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#undef        E2EPW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#define             START_SEC_VAR_ZERO_INIT_UNSPECIFIED

#elif defined E2EPW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#undef        E2EPW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#define             STOP_SEC_VAR


/* Library code     */
/* To be used for code that shall go into library segments for <MSN> module. */
#elif defined E2EPW_START_SEC_CODE_LIB
#undef        E2EPW_START_SEC_CODE_LIB
#define             START_SEC_CODE

#elif defined E2EPW_STOP_SEC_CODE_LIB
#undef        E2EPW_STOP_SEC_CODE_LIB
#define             STOP_SEC_CODE

#endif

/* End of file E2EPW_MemMap.inc */

/**********************************************************************************************************************
 *  EXI START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef EXI_START_SEC_CODE
  #undef EXI_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef EXI_STOP_SEC_CODE
  #undef EXI_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/
#ifdef EXI_START_SEC_CONST_UNSPECIFIED
# undef EXI_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef EXI_STOP_SEC_CONST_UNSPECIFIED
# undef EXI_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  EXI END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHFW START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHFW_START_SEC_CODE
# undef ETHFW_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ETHFW_STOP_SEC_CODE
# undef ETHFW_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef ETHFW_START_SEC_CONST_8BIT
# undef ETHFW_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef ETHFW_STOP_SEC_CONST_8BIT
# undef ETHFW_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef ETHFW_START_SEC_CONST_16BIT
# undef ETHFW_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef ETHFW_STOP_SEC_CONST_16BIT
# undef ETHFW_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHFW_START_SEC_CONST_32BIT
# undef ETHFW_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHFW_STOP_SEC_CONST_32BIT
# undef ETHFW_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHFW_START_SEC_CONST_UNSPECIFIED
# undef ETHFW_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHFW_STOP_SEC_CONST_UNSPECIFIED
# undef ETHFW_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef ETHFW_START_SEC_VAR_INIT_8BIT
# undef ETHFW_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT                    /* mapped to default var init 8bit section */
#endif
#ifdef ETHFW_STOP_SEC_VAR_INIT_8BIT
# undef ETHFW_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR                               /* default var stop section */
#endif

#ifdef ETHFW_START_SEC_VAR_INIT_16BIT
# undef ETHFW_START_SEC_VAR_INIT_16BIT
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef ETHFW_STOP_SEC_VAR_INIT_16BIT
# undef ETHFW_STOP_SEC_VAR_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHFW_START_SEC_VAR_INIT_32BIT
# undef ETHFW_START_SEC_VAR_INIT_32BIT
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef ETHFW_STOP_SEC_VAR_INIT_32BIT
# undef ETHFW_STOP_SEC_VAR_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHFW_START_SEC_VAR_INIT_UNSPECIFIED
# undef ETHFW_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef ETHFW_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef ETHFW_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef ETHFW_START_SEC_VAR_NOINIT_8BIT
# undef ETHFW_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHFW_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHFW_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHFW_START_SEC_VAR_NOINIT_16BIT
# undef ETHFW_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHFW_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHFW_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHFW_START_SEC_VAR_NOINIT_32BIT
# undef ETHFW_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHFW_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHFW_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHFW_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHFW_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHFW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHFW_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef ETHFW_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHFW_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHFW_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHFW_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHFW_START_SEC_VAR_ZERO_INIT_16BIT
# undef ETHFW_START_SEC_VAR_ZERO_INIT_16BIT
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef ETHFW_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef ETHFW_STOP_SEC_VAR_ZERO_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHFW_START_SEC_VAR_ZERO_INIT_32BIT
# undef ETHFW_START_SEC_VAR_ZERO_INIT_32BIT
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef ETHFW_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef ETHFW_STOP_SEC_VAR_ZERO_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHFW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHFW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHFW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHFW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHFW END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  SRP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#if defined(SRP_START_SEC_CODE)
# undef SRP_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(SRP_STOP_SEC_CODE)
# undef SRP_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/
/* CONST sections */
#if defined(SRP_START_SEC_CONST_UNSPECIFIED)
# undef SRP_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(SRP_STOP_SEC_CONST_UNSPECIFIED)
# undef SRP_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/
/* VAR NOINIT sections */
#if defined(SRP_START_SEC_VAR_NOINIT_8BIT)
# undef SRP_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(SRP_STOP_SEC_VAR_NOINIT_8BIT)
# undef SRP_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(SRP_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef SRP_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(SRP_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef SRP_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#if defined(SRP_START_SEC_VAR_ZERO_INIT_8BIT)
# undef SRP_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(SRP_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef SRP_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(SRP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef SRP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(SRP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef SRP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SRP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VCANCCGBT START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef VCANCCGBT_START_SEC_CODE
# undef VCANCCGBT_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE /* mapped to default code section */
#endif
#ifdef VCANCCGBT_STOP_SEC_CODE
# undef VCANCCGBT_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE /* default code stop section */
#endif

#ifdef VCANCCGBT_START_SEC_APPL_CODE
# undef VCANCCGBT_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE /* mapped to default code section */
#endif
#ifdef VCANCCGBT_STOP_SEC_APPL_CODE
# undef VCANCCGBT_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef VCANCCGBT_START_SEC_CONST_UNSPECIFIED
# undef VCANCCGBT_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VCANCCGBT_STOP_SEC_CONST_UNSPECIFIED
# undef VCANCCGBT_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef VCANCCGBT_START_SEC_CONST_8BIT
# undef VCANCCGBT_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT
#endif

#ifdef VCANCCGBT_STOP_SEC_CONST_8BIT
# undef VCANCCGBT_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef VCANCCGBT_START_SEC_CONST_16BIT
# undef VCANCCGBT_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif

#ifdef VCANCCGBT_STOP_SEC_CONST_16BIT
# undef VCANCCGBT_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* FAST CONST sections */


/* Postbuild CFG CONST sections */

#ifdef VCANCCGBT_START_SEC_PBCFG
# undef VCANCCGBT_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#ifdef VCANCCGBT_STOP_SEC_PBCFG
# undef VCANCCGBT_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */


/* VAR NOINIT sections */

#ifdef VCANCCGBT_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VCANCCGBT_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VCANCCGBT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VCANCCGBT_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef VCANCCGBT_START_SEC_VAR_ZERO_INIT_8BIT
# undef VCANCCGBT_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef VCANCCGBT_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VCANCCGBT_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef VCANCCGBT_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VCANCCGBT_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef VCANCCGBT_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VCANCCGBT_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */


/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */


/* Postbuild CFG VAR sections */

#ifdef VCANCCGBT_START_SEC_VAR_PBCFG
# undef VCANCCGBT_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#ifdef VCANCCGBT_STOP_SEC_VAR_PBCFG
# undef VCANCCGBT_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VCANCCGBT END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  J1939TP START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef J1939TP_START_SEC_CODE
# undef J1939TP_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE /* mapped to default code section */
#endif
#ifdef J1939TP_STOP_SEC_CODE
# undef J1939TP_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef J1939TP_START_SEC_CONST_8BIT
# undef J1939TP_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT /* mapped to default const 8bit section */
#endif
#ifdef J1939TP_STOP_SEC_CONST_8BIT
# undef J1939TP_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST /* default const stop section */
#endif

#ifdef J1939TP_START_SEC_CONST_16BIT
# undef J1939TP_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef J1939TP_STOP_SEC_CONST_16BIT
# undef J1939TP_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef J1939TP_START_SEC_CONST_32BIT
# undef J1939TP_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef J1939TP_STOP_SEC_CONST_32BIT
# undef J1939TP_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef J1939TP_START_SEC_CONST_UNSPECIFIED
# undef J1939TP_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef J1939TP_STOP_SEC_CONST_UNSPECIFIED
# undef J1939TP_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */


/* Postbuild CFG CONST sections */

#ifdef J1939TP_START_SEC_PBCFG
# undef J1939TP_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef J1939TP_STOP_SEC_PBCFG
# undef J1939TP_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef J1939TP_START_SEC_VAR_ZERO_INIT_8BIT
# undef J1939TP_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef J1939TP_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef J1939TP_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef J1939TP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef J1939TP_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef J1939TP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef J1939TP_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef J1939TP_START_SEC_VAR_NOINIT_8BIT
# undef J1939TP_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef J1939TP_STOP_SEC_VAR_NOINIT_8BIT
# undef J1939TP_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef J1939TP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef J1939TP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef J1939TP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef J1939TP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */


/* VAR FAST NOINIT sections */


/* VAR FAST ZERO INIT sections */


/* Postbuild CFG VAR sections */

#ifdef J1939TP_START_SEC_VAR_PBCFG
# undef J1939TP_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef J1939TP_STOP_SEC_VAR_PBCFG
# undef J1939TP_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  J1939TP END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANTP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef   CANTP_START_SEC_CODE
# undef  CANTP_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef   CANTP_STOP_SEC_CODE
# undef  CANTP_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE      /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef   CANTP_START_SEC_CONST_UNSPECIFIED
# undef  CANTP_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef   CANTP_STOP_SEC_CONST_UNSPECIFIED
# undef  CANTP_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef   CANTP_START_SEC_CONST_8BIT
# undef  CANTP_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#ifdef   CANTP_STOP_SEC_CONST_8BIT
# undef  CANTP_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef   CANTP_START_SEC_CONST_16BIT
# undef  CANTP_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef   CANTP_STOP_SEC_CONST_16BIT
# undef  CANTP_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* Postbuild CFG CONST sections */

#ifdef   CANTP_START_SEC_PBCFG
# undef  CANTP_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef   CANTP_STOP_SEC_PBCFG
# undef  CANTP_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif



/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef   CANTP_START_SEC_VAR_INIT_8BIT
# undef  CANTP_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT
#endif
#ifdef   CANTP_STOP_SEC_VAR_INIT_8BIT
# undef  CANTP_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef   CANTP_START_SEC_VAR_INIT_16BIT
# undef  CANTP_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef   CANTP_STOP_SEC_VAR_INIT_16BIT
# undef  CANTP_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef   CANTP_START_SEC_VAR_NOINIT_8BIT
# undef  CANTP_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef   CANTP_STOP_SEC_VAR_NOINIT_8BIT
# undef  CANTP_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef   CANTP_START_SEC_VAR_NOINIT_16BIT
# undef  CANTP_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef   CANTP_STOP_SEC_VAR_NOINIT_16BIT
# undef  CANTP_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef   CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef  CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef   CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef  CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef   CANTP_START_SEC_VAR_PBCFG
# undef  CANTP_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef   CANTP_STOP_SEC_VAR_PBCFG
# undef  CANTP_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif



/**********************************************************************************************************************
 *  CANTP END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  HTTP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef HTTP_START_SEC_CODE
  #undef HTTP_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE                             /* mapped to default code section */
#endif
#ifdef HTTP_STOP_SEC_CODE
  #undef HTTP_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE                              /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/


#ifdef HTTP_START_SEC_CONST_8
# undef HTTP_START_SEC_CONST_8                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8
#endif
#ifdef HTTP_STOP_SEC_CONST_8
# undef HTTP_STOP_SEC_CONST_8                       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef HTTP_START_SEC_CONST_16
# undef HTTP_START_SEC_CONST_16                     /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16
#endif
#ifdef HTTP_STOP_SEC_CONST_16
# undef HTTP_STOP_SEC_CONST_16                      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef HTTP_START_SEC_VAR_INIT_8
# undef HTTP_START_SEC_VAR_INIT_8                   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8
#endif
#ifdef HTTP_STOP_SEC_VAR_INIT_8
# undef HTTP_STOP_SEC_VAR_INIT_8                    /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef HTTP_START_SEC_VAR_NO_INIT_8
# undef HTTP_START_SEC_VAR_NO_INIT_8                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef HTTP_STOP_SEC_VAR_NO_INIT_8
# undef HTTP_STOP_SEC_VAR_NO_INIT_8                 /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef HTTP_START_SEC_VAR_NO_INIT_16
# undef HTTP_START_SEC_VAR_NO_INIT_16               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_16
#endif
#ifdef HTTP_STOP_SEC_VAR_NO_INIT_16
# undef HTTP_STOP_SEC_VAR_NO_INIT_16                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef HTTP_START_SEC_VAR_NO_INIT_32
# undef HTTP_START_SEC_VAR_NO_INIT_32               /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef HTTP_STOP_SEC_VAR_NO_INIT_32
# undef HTTP_STOP_SEC_VAR_NO_INIT_32                /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef HTTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef HTTP_START_SEC_VAR_NO_INIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef HTTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef HTTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef HTTP_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef HTTP_START_SEC_VAR_CLEARED_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef HTTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef HTTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  HTTP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  RTP START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef RTP_START_SEC_CODE
# undef RTP_START_SEC_CODE
# define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef RTP_STOP_SEC_CODE
# undef RTP_STOP_SEC_CODE
# define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef RTP_START_SEC_CONST_8BIT
# undef RTP_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT                       /* mapped to default const 8bit section */
#endif
#ifdef RTP_STOP_SEC_CONST_8BIT
# undef RTP_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST                             /* default const stop section */
#endif

#ifdef RTP_START_SEC_CONST_16BIT
# undef RTP_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef RTP_STOP_SEC_CONST_16BIT
# undef RTP_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef RTP_START_SEC_CONST_32BIT
# undef RTP_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef RTP_STOP_SEC_CONST_32BIT
# undef RTP_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef RTP_START_SEC_CONST_UNSPECIFIED
# undef RTP_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef RTP_STOP_SEC_CONST_UNSPECIFIED
# undef RTP_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef RTP_START_SEC_VAR_INIT_8BIT
# undef RTP_START_SEC_VAR_INIT_8BIT
# define START_SEC_VAR_INIT_8BIT                    /* mapped to default var init 8bit section */
#endif
#ifdef RTP_STOP_SEC_VAR_INIT_8BIT
# undef RTP_STOP_SEC_VAR_INIT_8BIT
# define STOP_SEC_VAR                               /* default var stop section */
#endif

#ifdef RTP_START_SEC_VAR_INIT_16BIT
# undef RTP_START_SEC_VAR_INIT_16BIT
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef RTP_STOP_SEC_VAR_INIT_16BIT
# undef RTP_STOP_SEC_VAR_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef RTP_START_SEC_VAR_INIT_32BIT
# undef RTP_START_SEC_VAR_INIT_32BIT
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef RTP_STOP_SEC_VAR_INIT_32BIT
# undef RTP_STOP_SEC_VAR_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef RTP_START_SEC_VAR_INIT_UNSPECIFIED
# undef RTP_START_SEC_VAR_INIT_UNSPECIFIED
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef RTP_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef RTP_STOP_SEC_VAR_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */

#ifdef RTP_START_SEC_VAR_NOINIT_8BIT
# undef RTP_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef RTP_STOP_SEC_VAR_NOINIT_8BIT
# undef RTP_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef RTP_START_SEC_VAR_NOINIT_16BIT
# undef RTP_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef RTP_STOP_SEC_VAR_NOINIT_16BIT
# undef RTP_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef RTP_START_SEC_VAR_NOINIT_32BIT
# undef RTP_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef RTP_STOP_SEC_VAR_NOINIT_32BIT
# undef RTP_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef RTP_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef RTP_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef RTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef RTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef RTP_START_SEC_VAR_ZERO_INIT_8BIT
# undef RTP_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef RTP_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef RTP_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef RTP_START_SEC_VAR_ZERO_INIT_16BIT
# undef RTP_START_SEC_VAR_ZERO_INIT_16BIT
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef RTP_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef RTP_STOP_SEC_VAR_ZERO_INIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef RTP_START_SEC_VAR_ZERO_INIT_32BIT
# undef RTP_START_SEC_VAR_ZERO_INIT_32BIT
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef RTP_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef RTP_STOP_SEC_VAR_ZERO_INIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef RTP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef RTP_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef RTP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef RTP_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  RTP END
 *********************************************************************************************************************/


/* PRQA L:MEMMAP_0841_TAG */


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/


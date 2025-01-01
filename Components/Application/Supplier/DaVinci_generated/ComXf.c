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
 *             File:  ComXf.c
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR ComXf Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  MICROSAR ComXf implementation file
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0715, 0857 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1, MD_MSR_Dir1.1 */

#include "ComXf.h" /* PRQA S 0828, 0810 */ /* MD_MSR_Dir1.1, MD_MSR_Dir1.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#if !defined(COMXF_LOCAL_INLINE)
# define COMXF_LOCAL_INLINE LOCAL_INLINE
#endif

#ifndef COMXF_DUMMY_STATEMENT
# define COMXF_DUMMY_STATEMENT(v)
#endif
#ifndef COMXF_DUMMY_STATEMENT_CONST
# define COMXF_DUMMY_STATEMENT_CONST(v)
#endif

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*!
 * \spec
 *    requires $lengthOf(dst) >= 2;
 * \endspec
 */
COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy16Bit(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src);

/*!
 * \spec
 *    requires $lengthOf(dst) >= 4;
 * \endspec
 */
COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy32Bit(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src);

/*!
 * \spec
 *    requires $lengthOf(dst) >= 8;
 * \endspec
 */
COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy64Bit(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src);

/*!
 * \spec
 *    requires $lengthOf(dst) >= 2;
 * \endspec
 */
COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy16BitEndConv(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src);

/*!
 * \spec
 *    requires $lengthOf(dst) >= 4;
 * \endspec
 */
COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy32BitEndConv(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src);

/*!
 * \spec
 *    requires $lengthOf(dst) >= 8;
 * \endspec
 */
COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy64BitEndConv(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src);

/**********************************************************************************************************************
 * ComXf copy functions
 *********************************************************************************************************************/

COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy16Bit(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src) /* PRQA S 3219 */ /* MD_MSR_Unreachable */
{
  dst[0] = src[0];
  dst[1] = src[1];
}

COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy32Bit(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src) /* PRQA S 3219 */ /* MD_MSR_Unreachable */
{
  dst[0] = src[0];
  dst[1] = src[1];
  dst[2] = src[2];
  dst[3] = src[3];
}

COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy64Bit(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src) /* PRQA S 3219 */ /* MD_MSR_Unreachable */
{
  dst[0] = src[0];
  dst[1] = src[1];
  dst[2] = src[2];
  dst[3] = src[3];
  dst[4] = src[4];
  dst[5] = src[5];
  dst[6] = src[6];
  dst[7] = src[7];
}

COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy16BitEndConv(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src) /* PRQA S 3219 */ /* MD_MSR_Unreachable */
{
  dst[0] = src[1];
  dst[1] = src[0];
}

COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy32BitEndConv(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src) /* PRQA S 3219 */ /* MD_MSR_Unreachable */
{
  dst[0] = src[3];
  dst[1] = src[2];
  dst[2] = src[1];
  dst[3] = src[0];
}

COMXF_LOCAL_INLINE FUNC(void, COMXF_CODE) ComXf_Copy64BitEndConv(P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) src) /* PRQA S 3219 */ /* MD_MSR_Unreachable */
{
  dst[0] = src[7];
  dst[1] = src[6];
  dst[2] = src[5];
  dst[3] = src[4];
  dst[4] = src[3];
  dst[5] = src[2];
  dst[6] = src[1];
  dst[7] = src[0];
}

/**********************************************************************************************************************
 * ComXf retransformers
 *********************************************************************************************************************/

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal Bckl_Sw_D_Stat_ST3_cb403d1d_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Bckl_Sw_D_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x03U;

  /* process signal Bckl_Sw_FP_Stat_ST3_0736b261_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Bckl_Sw_FP_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 2) & 0x03U;

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal Rsrv1_Bckl_Sw_Fx_Stat_ST3_8584783a_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Rsrv1_Bckl_Sw_Fx_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 4);

  /* process signal Bckl_Sw_D_Stat_ST3_cb403d1d_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Bckl_Sw_D_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x03U;

  /* process signal Bckl_Sw_FP_Stat_ST3_0736b261_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Bckl_Sw_FP_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 2) & 0x03U;

  /* process signal CRC_Bckl_Sw_Fx_Stat_Pr5_ST3_e761a2ea_Rx */
  ComXf_Copy16Bit((P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR)) &(*(dataElement)).CRC_Bckl_Sw_Fx_Stat_Pr5_ST3, (P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA)) &buffer[0]); /* PRQA S 2985 */ /* MD_ComXf_2985 */

  /* process signal SQC_Bckl_Sw_Fx_Stat_Pr5_ST3_4b42e447_Rx */
  (*(dataElement)).SQC_Bckl_Sw_Fx_Stat_Pr5_ST3 = buffer[2]; /* PRQA S 2985 */ /* MD_ComXf_2985 */

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_CLkS_DrRltch_Stat_Pr5_ST3_7at68qvnk0r9npofyykyfq82v_10e0cb0e_Rx_REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal DrRLtch_FL_Stat_ST3_ce64a199_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).DrRLtch_FL_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x03U;

  /* process signal DrRLtch_FR_Stat_ST3_f70310c2_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).DrRLtch_FR_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 2) & 0x03U;

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_DI_Odo_Pr5_ST3_e68xmtlkywxgxsdwekdjjhw3t_eb760b63_Rx_REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal Odo_ST3_657046b6_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Odo_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3];
  applDataPtr[1]  = buffer[4];
  applDataPtr[2]  = buffer[5];
  /* set unwritten bytes */
  applDataPtr[3] = 0x00U;

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_DI_Odo_Pr5_ST3_e68xmtlkywxgxsdwekdjjhw3t_eb760b63_Rx_Ssa_OdometerRecordType(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(Ssa_OdometerRecordType, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal Odo_ST3_657046b6_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Odo_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3];
  applDataPtr[1]  = buffer[4];
  applDataPtr[2]  = buffer[5];
  /* set unwritten bytes */
  applDataPtr[3] = 0x00U;

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal EVC_List03_StStyle_ST3_0f0d9336_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).EVC_List03_StStyle_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[4] >> 6);

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal EVC_CfgList_01_08_Stat_ST3_93476784_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).EVC_CfgList_01_08_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x03U;

  /* process signal EVC_List03_StStyle_ST3_0f0d9336_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).EVC_List03_StStyle_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[4] >> 6);

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_REC_Ign_Stat_Pr5_ST3(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_Ign_Stat_Pr5_ST3, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal ISw_Stat_ST3_20c6e8e0_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).ISw_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x07U;

  /* process signal Veh_Op_Mode_ST3_e0acb0c9_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Veh_Op_Mode_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 3) & 0x0FU;

  /* process signal CRC_Ign_Stat_Pr5_ST3_ef30f764_Rx */
  ComXf_Copy16Bit((P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR)) &(*(dataElement)).CRC_Ign_Stat_Pr5_ST3, (P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA)) &buffer[0]); /* PRQA S 2985 */ /* MD_ComXf_2985 */

  /* process signal SQC_Ign_Stat_Pr5_ST3_aca0dae8_Rx */
  (*(dataElement)).SQC_Ign_Stat_Pr5_ST3 = buffer[2]; /* PRQA S 2985 */ /* MD_ComXf_2985 */

  /* process signal KG_StartSw_Psd_ST3_b1980089_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).KG_StartSw_Psd_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 7);

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal ISw_Stat_ST3_20c6e8e0_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).ISw_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x07U;

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal ISw_Stat_ST3_20c6e8e0_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).ISw_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x07U;

  /* process signal Veh_Op_Mode_ST3_e0acb0c9_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Veh_Op_Mode_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 3) & 0x0FU;

  /* process signal CRC_Ign_Stat_Pr5_ST3_ef30f764_Rx */
  ComXf_Copy16Bit((P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR)) &(*(dataElement)).CRC_Ign_Stat_Pr5_ST3, (P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA)) &buffer[0]); /* PRQA S 2985 */ /* MD_ComXf_2985 */

  /* process signal SQC_Ign_Stat_Pr5_ST3_aca0dae8_Rx */
  (*(dataElement)).SQC_Ign_Stat_Pr5_ST3 = buffer[2]; /* PRQA S 2985 */ /* MD_ComXf_2985 */

  /* process signal KG_StartSw_Psd_ST3_b1980089_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).KG_StartSw_Psd_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 7);

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_Ssa_IgnitionStatusType(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(Ssa_IgnitionStatusType, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal ISw_Stat_ST3_20c6e8e0_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).ISw_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x07U;

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_ORC_Impact2_Pr5_ST3_b9l09rrslyv7vj3o92j69irnd_2f5ae8ac_Rx_REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal Impact_Y_ST3_8edd3644_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Impact_Y_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x01U;

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx_REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal Impact_F1_ST3_7aa87b43_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Impact_F1_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x01U;

  /* process signal Impact_F3_ST3_00682823_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Impact_F3_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 2) & 0x01U;

  /* process signal Impact_RO_type1_ST3_6d14f528_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Impact_RO_type1_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 5) & 0x01U;

  /* process signal Impact_RO_type2_ST3_2ab48ff8_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Impact_RO_type2_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 6) & 0x01U;

  /* process signal CRC_ORC_Impact3_Pr5_ST3_20961dce_Rx */
  ComXf_Copy16Bit((P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR)) &(*(dataElement)).CRC_ORC_Impact3_Pr5_ST3, (P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA)) &buffer[0]); /* PRQA S 2985 */ /* MD_ComXf_2985 */

  /* process signal SQC_ORC_Impact3_Pr5_ST3_189c36c2_Rx */
  (*(dataElement)).SQC_ORC_Impact3_Pr5_ST3 = buffer[2]; /* PRQA S 2985 */ /* MD_ComXf_2985 */

  /* process signal Impact_F2_ST3_3d080193_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Impact_F2_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 1) & 0x01U;

  /* process signal Impact_S1_ST3_29b3e86b_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Impact_S1_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 3) & 0x01U;

  /* process signal Impact_S2_ST3_6e1392bb_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Impact_S2_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 4) & 0x01U;

  /* process signal Impact_X_ST3_5cefa915_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Impact_X_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 7);

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx_REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal Impact_X_ST3_5cefa915_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Impact_X_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 7);

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal PT4_PTCoor_EngStartPN14_Stat_ST3_b3436bd4_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).PT4_PTCoor_EngStartPN14_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 4) & 0x07U;

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal PT4_PTCoor_PT_Rdy_ST3_3039cfe2_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).PT4_PTCoor_PT_Rdy_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x03U;

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal PT4_PTCoor_PT_Rdy_ST3_3039cfe2_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).PT4_PTCoor_PT_Rdy_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x03U;

  /* process signal PT4_PTCoor_EngStartPN14_Stat_ST3_b3436bd4_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).PT4_PTCoor_EngStartPN14_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 4) & 0x07U;

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_5p8cvrni3ypvuac33rj2asfy9_2f73a7b3_Rx_REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106x(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal PT4_PTCoor_DrvPosn_Stat_ST3_af5d60f3_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).PT4_PTCoor_DrvPosn_Stat_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x0FU;

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx_REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal PresfAct_Adj_Rq_ST3_e5b37ffb_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).PresfAct_Adj_Rq_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[4];
  applDataPtr[1]  = buffer[5] & 0x1FU;
  /* set unwritten bytes */
  applDataPtr[2] = 0x00U;
  applDataPtr[3] = 0x00U;

  /* process signal Rsrv6_Presf_Adj_ST3_f21bcfa6_Rx */
  (*(dataElement)).Rsrv6_Presf_Adj_ST3 = buffer[7]; /* PRQA S 2985 */ /* MD_ComXf_2985 */

  /* process signal Presf_Lvl_ST3_dc8c82ac_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Presf_Lvl_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 4);

  /* process signal Presf_Snd_Rq_ST3_6cb03b74_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Presf_Snd_Rq_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 2) & 0x03U;

  /* process signal PresfAccelReset_NotExcd_ST3_c7c4d546_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).PresfAccelReset_NotExcd_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x03U;

  /* process signal Presf_Enbl_ST3_40bed323_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Presf_Enbl_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[5] >> 5) & 0x03U;

  /* process signal Presf_Fric_Fctr_Lo_ST3_9b2a29ac_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Presf_Fric_Fctr_Lo_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[5] >> 7);
  applDataPtr[0] |= (buffer[6] << 1) & 0x02U;

  /* process signal PresfAct_TensSupp_Rq_ST3_62b93d7a_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).PresfAct_TensSupp_Rq_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[6] >> 1) & 0x07U;

  /* process signal CRC_PresfAct_Adj_Pr5_ST3_901db976_Rx */
  ComXf_Copy16Bit((P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR)) &(*(dataElement)).CRC_PresfAct_Adj_Pr5_ST3, (P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA)) &buffer[0]); /* PRQA S 2985 */ /* MD_ComXf_2985 */

  /* process signal SQC_PresfAct_Adj_Pr5_ST3_9993ff76_Rx */
  (*(dataElement)).SQC_PresfAct_Adj_Pr5_ST3 = buffer[2]; /* PRQA S 2985 */ /* MD_ComXf_2985 */

  /* process signal Presf_FricCoeff_Estim_ST3_b142a105_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Presf_FricCoeff_Estim_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[6] >> 4);

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx_REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal Presf_Lvl_ST3_dc8c82ac_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Presf_Lvl_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 4);

  /* process signal PresfAccelReset_NotExcd_ST3_c7c4d546_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).PresfAccelReset_NotExcd_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x03U;

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx_REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, COMXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_ComXf_Qac, MD_ComXf_3206 */
{
  Std_ReturnType ret = E_OK;

  P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR) applDataPtr;

  /* process signal CRC_SBeltTens_SP_Lvl_Pr5_ST3_ef88391d_Rx */
  ComXf_Copy16Bit((P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR)) &(*(dataElement)).CRC_SBeltTens_SP_Lvl_Pr5_ST3, (P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA)) &buffer[0]); /* PRQA S 2985 */ /* MD_ComXf_2985 */

  /* process signal RBTMFL_SP_Lvl_Rq_ST35_1b9e7376_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).RBTMFL_SP_Lvl_Rq_ST35; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = buffer[3] & 0x3FU;

  /* process signal RBTMFR_SP_Lvl_Rq_ST35_dd3bbb43_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).RBTMFR_SP_Lvl_Rq_ST35; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[3] >> 6);
  applDataPtr[0] |= (buffer[4] << 2) & 0x3CU;

  /* process signal Rsrv0_SBeltTens_SP_Lvl_Pr5_ST3_aa2f8d25_Rx */
  applDataPtr = (P2VAR(uint8, AUTOMATIC, COMXF_APPL_VAR))&(*(dataElement)).Rsrv0_SBeltTens_SP_Lvl_Pr5_ST3; /* PRQA S 0314 */ /* MD_ComXf_0314 */
  applDataPtr[0]  = (buffer[4] >> 4);

  /* process signal SQC_SBeltTens_SP_Lvl_Pr5_ST3_4743c50e_Rx */
  (*(dataElement)).SQC_SBeltTens_SP_Lvl_Pr5_ST3 = buffer[2]; /* PRQA S 2985 */ /* MD_ComXf_2985 */

  COMXF_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 * ComXf Init/DeInit API
 *********************************************************************************************************************/

FUNC(void, COMXF_CODE) ComXf_Init(P2CONST(ComXf_ConfigType, AUTOMATIC, COMXF_APPL_DATA) config) /* PRQA S 3206 */ /* MD_ComXf_3206 */
{
  COMXF_DUMMY_STATEMENT(config); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
}

FUNC(void, COMXF_CODE) ComXf_DeInit(void)
{
}

#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_ComXf_0314:  MISRA rule: Dir1.1
     Reason:       Pointer cast to void because a direct byte access is necessary.
     Risk:         No functional risk. Only a cast to void is performed.
     Prevention:   Not required.

   MD_ComXf_2985:  MISRA rule: Rule2.2
     Reason:       For loops produce 0 in additions or 1 in multiplications.
     Risk:         No functional risk. There is no side effect.
     Prevention:   Not required.

   MD_ComXf_3206:  MISRA rule: Rule2.7
     Reason:       The parameters are not used by the code in all possible code variants.
     Risk:         No functional risk.
     Prevention:   Not required.

   MD_ComXf_Qac:
     Reason:       This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                   The used analysis tool QAC 9.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:         No functional risk.
     Prevention:   Not required.

*/

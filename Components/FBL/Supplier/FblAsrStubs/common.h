/*************************************************************************

  AUTOLIV Electronic document.
  -------------------------------------

  DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

               COMPONENT COMMON.GEN
               ----------------

 This file must be included in every component which includes macros,
 types and functions defined by the component COMMON.GEN.

**************************************************************************

 Documentation reference :

 ------------------------------------------------------------------------

 Overview of the component :
    This component contains general definitions of types and macros
    which can be needed by the developper.

 ------------------------------------------------------------------------

 Evolution of the component COMMON.GEN
  (initials, date, modification)

   created by  :  SLY  2012/01/11

   modified by :

         $Log: common.h  $
         Revision 1.1.1.2 2021/12/15 15:50:50CET Jenkins Server 01 (Jenkins01) 
         Initial revision
         Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/FBL/Supplier/FblAsrStubs/project.pj
         Revision 1.2 2021/11/03 11:55:00EET Roberto Cristoi (roberto.cristoi) 
         Removed useless EXPORTED define
         Revision 1.1 2021/09/27 16:44:01EEST Emanuel Jivan (emanuel.jivan) 
         Initial revision
         Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_01/View_Development/Components/FBL/Bsw/FblAsrStubs/project.pj
         Revision 1.2 2017/03/27 16:40:22EEST Charlene Dibourg (charlene.dibourg) 
         Update Common.h with TL_Lib content
         Revision 1.2 2016/05/18 08:22:07CEST Maxime Bourdon (mbourdon)
         Add KU32_ONE define for EOL
         Revision 1.1 2015/10/13 15:53:02CEST Cedric Sauvage (csauvage)
         Initial revision
         Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/OPT_GENERIC/inc/project.pj
         Revision 1.9 2015/09/24 11:02:40CEST Pierre-Olivier Pilot (ppilot)
         QAC analysis
         Revision 1.8 2015/08/19 14:32:17CEST Sabine Flechelle (sflechelle)
         Issue 215817 - Motor current in block 5
         Extract correct low bytes to send motor current.
         Rename common macro.
         Revision 1.7 2015/03/12 15:19:19CET Cedric Sauvage (csauvage)
         Implementation of measurement block 12 in CIL + QAC correction
         Revision 1.6 2014/12/10 16:58:46CET Sebastien Claveau (sclaveau)
         Clean common.gen/h and update macro names
         Revision 1.5 2014/10/29 16:09:06CET Sabine Flechelle (sflechelle)
         Issue_167292 - Archi updates for new MMG
         New macros for uint32
         Revision 1.4 2014/06/12 16:58:31CEST Francois.Gilbert (fgilbert)
         New macros for CIL measurement frames
         Revision 1.3 2014/05/05 16:36:13CEST Cedric Sauvage (csauvage)
         Integration of E2P stack
         Revision 1.2 2014/04/15 10:00:41CEST Sabine Flechelle (sflechelle)
         Issue_142496 - MMG and BFE needs
         Add some common define needed by MMG
         Revision 1.1 2014/01/22 07:23:54CET Cedric Sauvage (csauvage)
         Initial revision
         Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/OPT_GENERIC/inc/project.pj


**************************************************************************/
/****** definition for mono-inclusion ******/
#ifndef COMMON_GEN_H
#define COMMON_GEN_H

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!            Remaining specific use cases  (to be cleaned)             !!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
#define KB_ZERO                       ((boolean) 0)
#define KU8_MASK_BITS_2_7             ((uint8) 0xFC)

/*************************************************************************
**                  Code's declarations scope macros                    **
**************************************************************************/
#define LOCAL                         static

/*************************************************************************
**                        Build template macros                         **
**   (shall not be modified without updating build tools accordingly)   **
**************************************************************************/
#define KAC_SOFT_VERSION              "ER_001CO.000"
#define KUC_SOFT_VERSION_NB           ((uint8) 0)
#define KUC_SOFT_MINOR_VERSION_NB     ((uint8) 0)
#define KUC_SIZE_STRING_SOFT_VERSION  ((uint8) 12)

#define KAC_YEAR_VERSION              "14"
#define KAC_MONTH_VERSION             "1"
#define KAC_DAY_VERSION               "22"

/*************************************************************************
**                        Addressing space macros                       **
**   (shall not be modified without considering application linkage)    **
**************************************************************************/
#define KU16_RAM_MEMORY_START         ((uint16)0x1000)
#define KU16_RAM_MEMORY_END           ((uint16)0x3FFF)

/**************************************************************************
**          Types limits and other remarkables values                    **
**************************************************************************/

/*************************** Boolean constants ***************************/

#define B_TRUE                        ((boolean)0xAA)
#define B_FALSE                       ((boolean)0x55)

/*********************** Unsigned 8 bits constants ***********************/

#define KU8_MIN                       ((uint8)  0)
#define KU8_MAX                       ((uint8)  255)

#define KU8_ZERO                      ((uint8)  0x00)
#define KU8_ONE                       ((uint8)  0x01)
#define KU8_TWO                       ((uint8)  0x02)
#define KU8_THREE                     ((uint8)  0x03)
#define KU8_FOUR                      ((uint8)  0x04)
#define KU8_FIVE                      ((uint8)  0x05)
#define KU8_SIX                       ((uint8)  0x06)
#define KU8_SEVEN                     ((uint8)  0x07)
#define KU8_EIGHT                     ((uint8)  0x08)
#define KU8_NINE                      ((uint8)  0x09)
#define KU8_TEN                       ((uint8)  0x0A)
#define KU8_SIXTEEN                   ((uint8)  0x10)
#define KU8_ONE_HUNDRED               ((uint8)  100)

/************************ Signed 8 bits constants ************************/

#define KS8_MIN                       ((sint8)  (-127))
#define KS8_MAX                       ((uint8)  127)

#define KS8_ZERO                      ((sint8)  0x00)

/*********************** Unsigned 16 bits constants **********************/

#define KU16_MIN                      ((uint16) 0)
#define KU16_MAX                      ((uint16) 65535)

#define KU16_MAX_U8                   ((uint16) 0xFF)

#define KU16_ZERO                     ((uint16) 0)
#define KU16_ONE                      ((uint16) 0x0001)

/************************ Signed 16 bits constants ***********************/

#define KS16_MIN                      ((sint16) (-32767))
#define KS16_MAX                      ((sint16) 32767)

#define KS16_MAX_S8                   ((sint16) 127)        /* 0x007F */
#define KS16_MIN_S8                   ((sint16) -128)       /* 0xFF80 */

#define KS16_ZERO                     ((sint16) 0)

/*********************** Unsigned 32 bits constants **********************/

#define KU32_MIN                      ((uint32) 0)
#define KU32_MAX                      ((uint32) 4294967295uL)

#define KU32_MAX_U8                   ((uint32) 0x000000FF)

#define KU32_MAX_U16                  ((uint32) 0xFFFFuL)

#define KU32_ZERO                     ((uint32) 0)
#define KU32_ONE                      ((uint32) 0x00000001)

/************************ Signed 32 bits constants ***********************/

#define KS32_MIN                      ((sint32) (-2147483647))
#define KS32_MAX                      ((sint32) 2147483647)

#define KS32_MAX_U8                   ((sint32) 0xFF)

#define KS32_MAX_U16                  ((sint32) 0xFFFF)

#define KS32_MIN_S16                  ((sint32) -32768)
#define KS32_MAX_S16                  ((sint32) 32767)

#define KS32_ZERO                     ((sint32) 0)

/*************************** pointers constants **************************/

#define KPU8_NULL                     ((uint8*) 0)
#define KPF_NULL                      ((void *) 0)

/**************************************************************************
**          Frequent bit masks and bit-field manipulation macros         **
**************************************************************************/

/************************* Unsigned 8 bits masks *************************/

#define KU8_MASK_HALF_BYTE_LOW        ((uint8) 0x0F)
#define KU8_MASK_HALF_BYTE_HIGH       ((uint8) 0xF0)

#define KU8_MASK_BIT_0                ((uint8) 0x01)
#define KU8_MASK_BIT_1                ((uint8) 0x02)
#define KU8_MASK_BIT_2                ((uint8) 0x04)
#define KU8_MASK_BIT_3                ((uint8) 0x08)
#define KU8_MASK_BIT_4                ((uint8) 0x10)
#define KU8_MASK_BIT_5                ((uint8) 0x20)
#define KU8_MASK_BIT_6                ((uint8) 0x40)
#define KU8_MASK_BIT_7                ((uint8) 0x80)

/************************ Unsigned 16 bits masks *************************/

#define KU16_MASK_BYTE_LOW            ((uint16) 0x00FF)
#define KU16_MASK_BYTE_HIGH           ((uint16) 0xFF00)

/************************ Unsigned 32 bits masks *************************/

#define KU32_MASK_WORD_LOW            ((uint32) 0x0000FFFFuL)
#define KU32_MASK_WORD_HIGH           ((uint32) 0xFFFF0000uL)

#define KU32_MASK_BYTE_LOW            ((uint32) 0x000000FFuL)
#define KU32_MASK_BYTE_LOW_MIDDLE     ((uint32) 0x0000FF00uL)
#define KU32_MASK_BYTE_HIGH_MIDDLE    ((uint32) 0x00FF0000uL)
#define KU32_MASK_BYTE_HIGH           ((uint32) 0xFF000000uL)

/****************************** Bit positions ****************************/

#define KU8_BIT_0                     ((uint8) 0)
#define KU8_BIT_1                     ((uint8) 1)
#define KU8_BIT_2                     ((uint8) 2)
#define KU8_BIT_3                     ((uint8) 3)
#define KU8_BIT_4                     ((uint8) 4)
#define KU8_BIT_5                     ((uint8) 5)
#define KU8_BIT_6                     ((uint8) 6)
#define KU8_BIT_7                     ((uint8) 7)
#define KU8_BIT_8                     ((uint8) 8)
#define KU8_BIT_9                     ((uint8) 9)
#define KU8_BIT_10                    ((uint8) 10)
#define KU8_BIT_11                    ((uint8) 11)
#define KU8_BIT_12                    ((uint8) 12)
#define KU8_BIT_13                    ((uint8) 13)
#define KU8_BIT_14                    ((uint8) 14)
#define KU8_BIT_15                    ((uint8) 15)
#define KU8_BIT_16                    ((uint8) 16)
#define KU8_BIT_17                    ((uint8) 17)
#define KU8_BIT_18                    ((uint8) 18)
#define KU8_BIT_19                    ((uint8) 19)
#define KU8_BIT_20                    ((uint8) 20)
#define KU8_BIT_21                    ((uint8) 21)
#define KU8_BIT_22                    ((uint8) 22)
#define KU8_BIT_23                    ((uint8) 23)
#define KU8_BIT_24                    ((uint8) 24)
#define KU8_BIT_25                    ((uint8) 25)
#define KU8_BIT_26                    ((uint8) 26)
#define KU8_BIT_27                    ((uint8) 27)
#define KU8_BIT_28                    ((uint8) 28)
#define KU8_BIT_29                    ((uint8) 29)
#define KU8_BIT_30                    ((uint8) 30)
#define KU8_BIT_31                    ((uint8) 31)

#define KU8_SHIFT_HALF_BYTE           ((uint8) 4)

#define KU8_POS_LOW_BYTE              ((uint8) 0)
#define KU8_POS_HIGH_BYTE             ((uint8) 8)

#define KU8_POS_L_LOW_BYTE            ((uint8) 0)
#define KU8_POS_L_LOW_MIDDLE_BYTE     ((uint8) 8)
#define KU8_POS_L_HIGH_MIDDLE_BYTE    ((uint8) 16)
#define KU8_POS_L_HIGH_BYTE           ((uint8) 24)

/**************************************************************************
**                       Data manipulation macros                        **
**************************************************************************/

/************************** 8 bit results macros *************************/

#define U8_BIT_SET(reg, mask)                   ((reg) |= (mask))
#define U8_BIT_CLEAR(reg, mask)                 ((reg) &= ((mask)^((uint8)0xFF)))

#define U8_GET_ABSOLUTE_VALUE_FROM_S8(value)    (((value)<((sint8)(0)))?((uint8)-(value)):((uint8)(value)) /* PRQA S 3491 */)

/************************* 16 bit results macros *************************/

#define U16_BIT_SET(reg, mask)                  ((reg) |= (mask))
#define U16_BIT_CLEAR(reg, mask)                ((reg) &= ((mask)^((uint16)0xFFFF)))

#define U16_COMPLEMENT(val)                     ((val) ^ ((uint16)0xFFFF))

#define U16_GET_LOW_BYTE(_word)                 ((uint8)(((_word) & KU16_MASK_BYTE_LOW ) >> KU8_POS_LOW_BYTE ))
#define U16_GET_HIGH_BYTE(_word)                ((uint8)(((_word) & KU16_MASK_BYTE_HIGH) >> KU8_POS_HIGH_BYTE))

#define U16_GET_ABSOLUTE_VALUE_FROM_S16(value)  (((value)<((sint16)(0)))?((uint16)-(value)):((uint16)(value)) /* PRQA S 3491 */)
#define U16_GET_SATURATED_VALUE_FROM_U32(value) (((value)>((uint32)(KU16_MAX)))?((uint16)KU16_MAX):((uint16)(value)) /* PRQA S 3491 */)

/************************* 32 bit results macros *************************/

#define U32_BIT_SET(reg, mask)                  ((reg) |= (mask))
#define U32_BIT_CLEAR(reg, mask)                ((reg) &= ((mask)^((uint32)0xFFFFFFFFuL)))
#define U32_COMPLEMENT(val)                     ((val)^((uint32)0xFFFFFFFFuL))

#define U32_GET_LOW_BYTE(_long)                 ((uint8)(  (_long) & KU32_MASK_BYTE_LOW))
#define U32_GET_LOW_MIDDLE_BYTE(_long)          ((uint8)(( (_long) & KU32_MASK_BYTE_LOW_MIDDLE) >> KU8_POS_L_LOW_MIDDLE_BYTE))
#define U32_GET_HIGH_MIDDLE_BYTE(_long)         ((uint8)(( (_long) & KU32_MASK_BYTE_HIGH_MIDDLE) >> KU8_POS_L_HIGH_MIDDLE_BYTE))
#define U32_GET_HIGH_BYTE(_long)                ((uint8)(( (_long) & KU32_MASK_BYTE_HIGH)        >> KU8_POS_L_HIGH_BYTE))

#define U32_GET_ABSOLUTE_VALUE_FROM_S32(value)  (((value)<((sint32)(0)))?((uint32)-(value)):((uint32)(value)) /* PRQA S 3491 */)

#define U32_SWAP_BYTE_ORDER(u32ToSwap) \
   ( \
      (((u32ToSwap) & 0x000000FFUL) << 24) | \
      (((u32ToSwap) & 0x0000FF00UL) << 8 ) | \
      (((u32ToSwap) & 0x00FF0000UL) >> 8 ) | \
      (((u32ToSwap) & 0xFF000000UL) >> 24) \
   )

/* end of conditional inclusion of COMMON.GEN.h */

#endif   /* COMMON.GEN_H */









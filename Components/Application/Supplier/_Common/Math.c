/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

COMPONENT TL_Lib

Current revision: $Revision: 1.1 $
Checked in:       $Date: 2021/12/14 10:18:24CET $

**************************************************************************

Overview of the component:
Provide generic mathematics services, which are typically useful in
PP4G development.

*************************************************************************/

/*************************************************************************
Packages inclusion 
*************************************************************************/
// #include "NVP_Param.h"

/*************************************************************************
Intra-package inclusions 
*************************************************************************/
#include "Math.h"

/*************************************************************************
Private inclusion 
*************************************************************************/

/*************************************************************************
Declaration of constants
*************************************************************************/

/*************************************************************************
Declaration of macros
*************************************************************************/
#define GET_VALUE(index)        ((*pfGet)(pu8Table,index))

#define KU8_U16_SIZE            ((uint8)2)
#define KU8_U32_SIZE            ((uint8)4)

#define KU8_FIRST_BYTE_ORDER    ((uint8)0)
#define KU8_SECOND_BYTE_ORDER   ((uint8)1)
#define KU8_THIRD_BYTE_ORDER    ((uint8)2)
#define KU8_FOURTH_BYTE_ORDER   ((uint8)3)

#define KU8_HALF_DIVISOR        ((uint8)2)

/*************************************************************************
Declaration of types
*************************************************************************/
typedef uint32 (*pfu32GetFromTable_Type)(const uint8 *pu8Table, const uint8 u8Index);

/*************************************************************************
LOCAL functions prototypes
*************************************************************************/
static uint32 u32GetFromU8Table(const uint8 * const pu8Table, const uint8 u8Index);
static uint32 u32GetFromU16BITable(const uint8 * const pu8Table, const uint8 u8Index);
static uint32 u32GetFromU16LITable(const uint8 * const pu8Table, const uint8 u8Index);
static uint32 u32GetFromU32BITable(const uint8 * const pu8Table, const uint8 u8Index);
static uint32 u32GetFromU32LITable(const uint8 * const pu8Table, const uint8 u8Index);
static uint32 u32SaturateResult(const sint32 s32YI, const stInterpolationParam_Type * const pstParam);

/*************************************************************************
LOCAL variables declaration
*************************************************************************/

/*************************************************************************
LOCAL constant data declaration
**************************************************************************/

/* "Get from look-up table" indirection table regarding the different
 * size of element in the look up table.
 * Applicable for both X and Y look-up tables.
 * Match with types respectively coded in first and second quartet of u8Flags
 * member of the stInterpolationParam_Type structure. */
static const pfu32GetFromTable_Type capfu32GetFromTable[KU8_XY_TYPE_MASK_NB_VAL] =
{
   &u32GetFromU8Table,       /* 00 : unsigned 8 bits get function */
   &u32GetFromU16BITable,    /* 01 : unsigned 16 bits Big Indian get function */
   &u32GetFromU16LITable,    /* 02 : unsigned 16 bits Little Indian get function */
   &u32GetFromU32BITable,    /* 03 : unsigned 32 bits Big Indian get function */
   &u32GetFromU32LITable,    /* 04 : unsigned 32 bits Little Indian get function */
   &u32GetFromU16BITable,    /* Default function in case of invalid 5 parameter value */
   &u32GetFromU16BITable,    /* Default function in case of invalid 6 parameter value */
   &u32GetFromU16BITable     /* Default function in case of invalid 7 parameter value */
};

/*************************************************************************
EXPORTED variables declaration
*************************************************************************/

/*************************************************************************
EXPORTED constant data declaration
**************************************************************************/

/**************************************************************************
Private Functions
**************************************************************************/

/**************************************************************************
Label:
Name : u32GetFromU8Table
Object: Generic sub-function to get a value from a 8 bits look-up table.
Parameters:
   - const uint8 *pu8Table : The look-up table
   - const uint8 u8Index : The index of element to be returned
Return: The get value
[COVERS: ]
**************************************************************************/
static uint32 u32GetFromU8Table(const uint8 * const pu8Table, const uint8 u8Index)
{
   /* 8 bits value */
   /* QAC_WARNING S 0506 1 */ /* Assumes that look-up table address is not null in configuration */
   return (uint32)(*(pu8Table + u8Index));
}

/**************************************************************************
Label:
Name : u32GetFromU16BITable
Object: Generic sub-function to get a value from a 16 bits Big Indian
        look-up table.
Parameters:
   - const uint8 *pu8Table : The look-up table
   - const uint8 u8Index : The index of element to be returned
Return: The get value
[COVERS: ]
**************************************************************************/
static uint32 u32GetFromU16BITable(const uint8 * const pu8Table, const uint8 u8Index)
{
   /* 16 bits Big Indian (Note = This code intentionally takes advantage of
    *                            the corresponding S12Z Big Indian native
    *                            encoding, but it's not portable) */
   /* QAC_WARNING S 0310 3 */ /* Intentional casting to different object pointer type to fit with generic function prototype */
   /* QAC_WARNING S 3305 2 */ /* Pointer cast to stricter alignment, but matching to target table real size and alignment */
   /* QAC_WARNING S 0506 1 */ /* Assumes that look-up table address is not null in configuration */
   return (uint32)(*((const uint16*)pu8Table + u8Index));
}

/**************************************************************************
Label:
Name : u32GetFromU16LITable
Object: Generic sub-function to get a value from a 16 bits Little Indian
        look-up table.
Parameters:
   - const uint8 *pu8Table : The look-up table
   - const uint8 u8Index : The index of element to be returned
Return: The get value
[COVERS: ]
**************************************************************************/
static uint32 u32GetFromU16LITable(const uint8 * const pu8Table, const uint8 u8Index)
{
   /* Points the indexed element beginning */
   /* QAC_WARNING S 0510 10 */ /* Possible arithmetic operation on NULL pointer. */
   /* QAC_WARNING S 0506 9 */ /* Assumes that look-up table address is not null in configuration */
   const uint8 * const pu8Value = pu8Table + (u8Index * KU8_U16_SIZE);

   return (
             (
                ((uint32)(*(pu8Value + KU8_SECOND_BYTE_ORDER))) << KU8_POS_HIGH_BYTE
             )
             +
             (
                *(pu8Value + KU8_FIRST_BYTE_ORDER)
             )
          );
}

/**************************************************************************
Label:
Name : u32GetFromU32BITable
Object: Generic sub-function to get a value from a 32 bits Big Indian
        look-up table.
Parameters:
   - const uint8 *pu8Table : The look-up table
   - const uint8 u8Index : The index of element to be returned
Return: The get value
[COVERS: ]
**************************************************************************/
static uint32 u32GetFromU32BITable(const uint8 * const pu8Table, const uint8 u8Index)
{
   /* 32 bits Big Indian (Note = This code intentionally takes advantage of
    *                            the corresponding S12Z Big Indian native
    *                            encoding, but it's not portable) */
   /* QAC_WARNING S 0310 3 */ /* Intentional casting to different object pointer type to fit with generic function prototype */
   /* QAC_WARNING S 3305 2 */ /* Pointer cast to stricter alignment, but matching to target table real size and alignment */
   /* QAC_WARNING S 0506 1 */ /* Assumes that look-up table address is not null in configuration */
   return (uint32)(*((const uint32*)pu8Table + u8Index));
}

/**************************************************************************
Label:
Name : u32GetFromU32LITable
Object: Generic sub-function to get a value from a 32 bits Little Indian
        look-up table.
Parameters:
   - const uint8 *pu8Table : The look-up table
   - const uint8 u8Index : The index of element to be returned
Return: The get value
[COVERS: ]
**************************************************************************/
static uint32 u32GetFromU32LITable(const uint8 * const pu8Table, const uint8 u8Index)
{
   /* Points the indexed element beginning */
   /* QAC_WARNING S 0510 18 */ /* Possible arithmetic operation on NULL pointer. */
   /* QAC_WARNING S 0506 17 */ /* Assumes that look-up table address is not null in configuration */
   const uint8 * const pu8Value = pu8Table + (u8Index * KU8_U32_SIZE);

   return (
              (
                ((uint32)(*(pu8Value + KU8_FOURTH_BYTE_ORDER))) << KU8_POS_L_HIGH_BYTE
              )
              +
              (
                ((uint32)(*(pu8Value + KU8_THIRD_BYTE_ORDER))) << KU8_POS_L_HIGH_MIDDLE_BYTE
              )
              +
              (
                ((uint32)(*(pu8Value + KU8_SECOND_BYTE_ORDER))) << KU8_POS_L_LOW_MIDDLE_BYTE
              )
              +
              (
                *(pu8Value + KU8_FIRST_BYTE_ORDER)
              )
         );
}

static uint32 u32SaturateResult(const sint32 s32YI, const stInterpolationParam_Type * const pstParam)
{
   uint32 u32Result;

   if (s32YI < 0)
   {
      u32Result = 0u;
   }
   /* and check overflow and saturate the result is necessary */
   else if (((pstParam->u8TableTypes & KU8_Y_TYPE_MSK) == KU8_Y8) && (s32YI > (sint32)KU8_MAX))
   {
      u32Result = KU8_MAX;
   }
   else if (((pstParam->u8TableTypes & KU8_Y_TYPE_MSK) <= KU8_Y16_LIndian) && (s32YI > (sint32)KU16_MAX))
   {
      u32Result = KU16_MAX;
   }
   /* If the result is not out of target range, use it without modification */
   else
   {
      u32Result = (uint32)s32YI;
   }
   /* Return the result */
   return u32Result;
}

/**************************************************************************
Exported Functions
**************************************************************************/

/**************************************************************************
Label:
Name : u16InterpolateFromTable
Object: Perform an interpolation regarding several parameters:
        - 8, 16, 32 bits Big Indian or Little Indian look-up tables
        - Linear/lower/higher interpolation set-up separately for
          below/in/over look-up table range.
Parameters:
   - uint32 u32XI : The input value for interpolation
   - const stInterpolationParam_Type *pstParam : Constant structure containing
          look-up tables addresses and interpolation parameters.
Resolution:
Return: The interpolation result
[COVERS: ]
**************************************************************************/
uint32 u32InterpolateFromTable(const uint32 u32XI, const stInterpolationParam_Type * const pstParam)
{
   pfu32GetFromTable_Type pfGet;
   const uint8 * pu8Table;
   uint8 u8RelevantFlags;
   uint8 u8IndexA;
   uint32 u32XA;
   uint32 u32YA;
   uint8 u8IndexB;
   uint32 u32XB;
   uint32 u32YB;
   uint8 u8IndexM;
   uint32 u32XM;
   sint32 s32YI;
   uint32 u32Result;

   /* Prepare access the X look-up table using the GET_VALUE macro */
   /* QAC_WARNING S 0506 2 */ /* Assumes that interpolation configuration structure address is not null */
   pfGet = capfu32GetFromTable[pstParam->u8TableTypes & KU8_X_TYPE_MSK];
   pu8Table = pstParam->pu8X;
   /* Test if the input value is bellow the range of the look-up table */
   u8IndexA = 0u;
   u32XA = GET_VALUE(u8IndexA);
   if (u32XI <= u32XA)
   {
      /* The value is bellow the range of the look-up table */
      /* Isolate the option flag to take into account, which concerns who to manage
       * interpolation bellow the range */
      u8RelevantFlags = KU8_BELOW_RANGE_UPPER_INTER;
      /* In the case it were needed for interpolation, select the second point
       * of the table as the upper bound */
      u8IndexB = 1u;
      u32XB = GET_VALUE(u8IndexB);
   }
   else
   {
      /* Now test if the input value is over the range of the look-up table */
      u8IndexB = pstParam->u8NbPos - 1u;
      u32XB = GET_VALUE(u8IndexB);
      if (u32XI >= u32XB)
      {
         /* The value is over the range of the look-up table */
         /* Isolate the option flag to take into account, which concerns who to manage
          * interpolation over the range */
         u8RelevantFlags = KU8_OVER_RANGE_LOWER_INTER;
         /* In the case it were needed for interpolation, select the point
          * before last of the table as the lower bound */
         u8IndexA = u8IndexB - 1u;
         u32XA = GET_VALUE(u8IndexA);
      }
      else
      {
         /* The value is inside the range of the look-up table */
         /* Isolate the option flag to take into account, which concerns who to manage
          * interpolation inside the range */
         u8RelevantFlags = KU8_IN_RANGE_MNGT_MSK;
         /* Quick search (log(n) complexity) of input value's boundaries
          * (lower and upper) At this point, A and B points have been previously
          * initialized to identify the full look-up table range.
          * The following loop is going to progressively identify the narrowest
          * range around the input value, by dichotomy. */
         while (u8IndexA < (u8IndexB - 1u))      /* exit condition should be "==" */
         {
            /* Take the middle point of the current range */
            u8IndexM = (u8IndexA + u8IndexB) / KU8_HALF_DIVISOR;
            u32XM = GET_VALUE(u8IndexM);
            /* Update either the lower bound or the upper bound with the middle point */
            if (u32XI == u32XM)
            {
               /* Stop directly the search. */
               /* Note : Making A point equal B point (and not tolerate 1 position
                * difference) avoid to take into account the wrong bound in case of
                * below or over range parameter:
                * eg. : For XI = XA = XB - 1 with KU8_OVER_RANGE_LOWER_INTER mode,
                *       this avoid to use XB upper bound, but XA lower bound. */
               u8IndexA = u8IndexM;
               u8IndexB = u8IndexM;
               u32XA = u32XM;
               /* Note: no need to update u32XB which will not be use. */
            }
            else if (u32XI > u32XM)
            {
               u8IndexA = u8IndexM;
               u32XA = u32XM;
            }
            else /* (u32XI < u32XM) */
            {
               u8IndexB = u8IndexM;
               u32XB = u32XM;
            }
         }
      }
   }
   /* Prepare access the Y look-up table using the GET_VALUE macro */
   /* (note: From now, the GET_VALUE macro will dedicated to the Y look-up
    *        table and no longer to the X look-up table. */
   pfGet = capfu32GetFromTable[(pstParam->u8TableTypes & KU8_Y_TYPE_MSK) >> KU8_Y32_TypeRShift];
   pu8Table = pstParam->pu8Y;
   if (u8IndexB == u8IndexA)
   {
      /* Consider the target of the point independently to the interpolation method */
      u32Result = GET_VALUE(u8IndexA);
   }
   else
   {
      /* Retrieve target values associated to previously identity lower and upper bounds */
      u32YA = GET_VALUE(u8IndexA);
      u32YB = GET_VALUE(u8IndexB);
      /* Identify the interpolation principle which is applicable */
      switch ((uint8)(pstParam->u8Flags & u8RelevantFlags))
      {
         case KU8_IN_RANGE_LOWER_INTER:
         case KU8_BELOW_RANGE_UPPER_INTER:
         /* Consider the target of the lower bound */
         u32Result = u32YA;
         break;
         case KU8_IN_RANGE_UPPER_INTER:
         case KU8_OVER_RANGE_LOWER_INTER:
         /* Consider the target of the upper bound */
         u32Result = u32YB;
         break;
         default:
         /* Performs a linear interpolation using targets of the lower and upper bounds */
         /* QAC_WARNING S 0584 10 */ /* Assumes that the constant X look-up table contains ordered distinct values preventing division by zero */
         /* QAC_WARNING S 3103 9 */ /* Result of signed division operation may be implementation defined. But round operation type is assumed by look-up tables */
         /* QAC_WARNING S 4394 8 */ /* Using a signed result is required to easily detect underflow (negative result) */
#ifndef LINEAR_COMPUTATION_VARIANT

         /* First linear interpolation computation variant: (see note below) */
         s32YI = (sint32)u32YA + (((sint32)(u32XI - u32XA) * (sint32)(u32YB - u32YA)) / (sint32)(u32XB - u32XA));

#else
         /* Second linear interpolation computation variant: (see note below) */
         s32YI = (((sint32)(u32XI - u32XA) * (sint32)(u32YB)) + ((sint32)(u32XB - u32XI) * (sint32)(u32YA))) / (sint32)(u32XB - u32XA);

#endif
         /* Note: Both computation variant try to minimize rounding error during intermediate computation.
          * However, in some limited situations, compared to the real final result (computation with decimals),
          * the first variant result could correspond to a rounded up result when the second variant correspond
          * to a rounded down (difference of 1 lsb!).
          * Using 32 bits values tables for X or Y, the first variant is less likely to
          * overflow during the intermediate multiplication (since neighboring X and Y differences are used for
          * this multiplication).
          * In all cases, the possible overflow during intermediate computation shall be mastered by the user
          * especially if using a 16 and a 32 bits tables, or 32 bits tables for both X and Y tables) */

         /* In case of out range interpolation (extrapolation), the final result can
          * also be potentially out of the target format range (same format as table Y).
          * Checks underflow and saturate the result is necessary */
         u32Result = u32SaturateResult(s32YI, pstParam);
         break;
      }
   }
   /* Return the result */
   return u32Result;
}

/* end of file */

/******************************************************************************
*
* FILE:
*   hyp.h         
*
* RELATED FILES:
*   math.h
*
* DESCRIPTION:
*   Definines prototype of hypot function.
*
*   Calculates the hypotenuse.
*   C__HYPOT(x, y);

*
*  AUTHOR(S):
*    S. Hillebrand
*
*  Copyright (c) 2003 dSPACE GmbH, GERMANY
*
*  $Workfile: tl_math.h $ $Revision: 1.1.2.2 $ $Date: 2018/09/20 09:19:50CEST $ $Author: Andreea Negrea (andreea.negrea) $
******************************************************************************/

#ifndef __tl_math_h__
#define __tl_math_h__

#include <math.h>

/* hypot */
#define C__HYPOT(x, y)\
    sqrt((x)*(x) + (y)*(y))

#endif /* #ifndef __tl_math_h__ */

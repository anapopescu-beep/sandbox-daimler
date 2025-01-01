// =============================================================================
// @file:    wdt_hsm_internal.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
// @purpose: Register Definition File for Infineon HSM Device Series
//
// THE SOURCE CODE AND ITS RELATED DOCUMENTATION IS PROVIDED "AS IS". INFINEON
// TECHNOLOGIES MAKES NO OTHER WARRANTY OF ANY KIND,WHETHER EXPRESS,IMPLIED OR,
// STATUTORY AND DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
// SATISFACTORY QUALITY, NON INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
//
// THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. INFINEON TECHNOLOGIES
// RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER
// REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR
// THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.
//
// INFINEON TECHNOLOGIES SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
// CONSEQUENTIAL DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR
// ANY DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR
// PROFITS, DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE
// DAMAGES, LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION
// WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR
// PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON
// WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.
//
// (C)Copyright INFINEON TECHNOLOGIES All rights reserved
// =============================================================================

#ifndef __WDT_HSM_INTERNAL_H__
#define __WDT_HSM_INTERNAL_H__
 
#include "wdt_hsm.h"



/******************************************************************************************/
/*  Additional register mask definitions                                                  */
/******************************************************************************************/

#define WDT_CTRL_wr_msk                  0xf111
#define WDT_CTRL_rd_msk                  0xf111
#define WDT_CTRL_res                     0xc000
#define WDT_CTRL_res_msk                 0xffff
#define WDT_VAL_wr_msk                   0x0
#define WDT_VAL_rd_msk                   0xffff
#define WDT_VAL_res                      0x0
#define WDT_VAL_res_msk                  0x0
#define WDT_RELOAD_wr_msk                0xffff
#define WDT_RELOAD_rd_msk                0xffff
#define WDT_RELOAD_res                   0x0
#define WDT_RELOAD_res_msk               0x0
#define WDT_SRV_wr_msk                   0xfff
#define WDT_SRV_rd_msk                   0xfff
#define WDT_SRV_res                      0xa
#define WDT_SRV_res_msk                  0xffff
#define WDT_SRV_INI_wr_msk               0xfff
#define WDT_SRV_INI_rd_msk               0x0
#define WDT_SRV_INI_res                  0x0
#define WDT_SRV_INI_res_msk              0x0
#define WDT_ACC_CTRL_wr_msk              0x3
#define WDT_ACC_CTRL_rd_msk              0x3
#define WDT_ACC_CTRL_res                 0x3
#define WDT_ACC_CTRL_res_msk             0xffff


#endif  /* __WDT_HSM_INTERNAL_H__ */

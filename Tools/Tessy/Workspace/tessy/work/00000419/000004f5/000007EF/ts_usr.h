/*
 * TESSY User code template file
 *
 * User code declarations are inserted at the marker $Declarations.
 */
#if !defined (__TESSY_USR_H)
   #define __TESSY_USR_H

#ifndef TESSY_USERCODE
   #define TESSY_USERCODE
#endif

/*
 * Return values
 */
#define TS_RC_USER_OK            0  /* Normal succesfull completion      */
#define TS_RC_USER_ERROR        -1  /* An error occured during execution */

#ifndef TESSY_USER_DECLARATION
#define TESSY_USER_DECLARATION

#endif


#ifdef __cplusplus
extern "C" {
#endif
/*
 * Prolog/Epilog functions
 */
void ts_tobj_prolog (void);
void ts_tobj_epilog (void);
void ts_tc_prolog (void);
void ts_tc_epilog (void);

#ifdef __cplusplus
}
#endif

#endif // !defined (__TESSY_USR_H)

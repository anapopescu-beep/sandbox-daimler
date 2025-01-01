/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Event-driven hierarchical finite state machine interface
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/*********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joern Herwig                  JHg           Vector Informatik GmbH
 *  Alexander Starke              ASe           Vector Informatik GmbH
 *  Marco Riedl                   Rie           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id          Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2012-10-30  JHg     -                  First implementation
 *  01.00.01  2012-12-10  JHg     -                  Added "none" trigger
 *  01.01.00  2013-12-11  JHg     ESCAN00071901      Renamed package to FblLib_Fsm
 *                        ASe     -                  Performed MISRA checks
 *  01.01.01  2019-01-24  Rie     ESCAN00101864      No changes
 *********************************************************************************************************************/

#ifndef __FBL_FSM_H__
#define __FBL_FSM_H__

/**********************************************************************************************************************
 *  VERSION
 *********************************************************************************************************************/

/* --- Version --- */
/* ##V_CFG_MANAGEMENT ##CQProject : FblLib_Fsm CQComponent : Implementation */
#define FBLLIB_FSM_VERSION           0x0101u
#define FBLLIB_FSM_RELEASE_VERSION   0x01u

/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/

/** Default (invalid) state value */
#define FBL_FSM_DEFAULT_STATE          ((tFblFsmState)-1)

/**********************************************************************************************************************
 *  MACROS
 *********************************************************************************************************************/

/** Dummy entry */
#define FBL_FSM_TRIGGER_NONE()                                    { FblFsmEventHandlerDefault, kFblFsmDefaultEvent_None,  FBL_FSM_DEFAULT_STATE }
/** State entry handler */
#define FBL_FSM_TRIGGER_ENTRY(action)                             { (action),                  kFblFsmDefaultEvent_Entry, FBL_FSM_DEFAULT_STATE }
/** State exit handler */
#define FBL_FSM_TRIGGER_EXIT(action)                              { (action),                  kFblFsmDefaultEvent_Exit,  FBL_FSM_DEFAULT_STATE }
/** Event handler for "any" event */
#define FBL_FSM_TRIGGER_ANY(action, state)                        { (action),                  kFblFsmDefaultEvent_Any,   (state)               }
/** Internal event handler, no state transition */
#define FBL_FSM_TRIGGER_INTERNAL(event, action)                   { (action),                  (event),                   FBL_FSM_DEFAULT_STATE }
/** State transition on event */
#define FBL_FSM_TRIGGER_TRANSITION(event, state)                  { FblFsmEventHandlerDefault, (event),                   (state)               }
/** State transition on event with additional action */
#define FBL_FSM_TRIGGER_TRANSITION_ACTION(event, action, state)   { (action),                  (event),                   (state)               }
/** Switch state when guard condition is true */
#define FBL_FSM_TRIGGER_CHOICE(guard, state)                      { (guard),                   kFblFsmDefaultEvent_Entry, (state)               }
/** Else case of choice */
#define FBL_FSM_TRIGGER_CHOICE_ELSE(state)                        { FblFsmEventHandlerDefault, kFblFsmDefaultEvent_Entry, (state)               }
/** Unconditional state transition (any entry handler has to return negative guard result) */
#define FBL_FSM_TRIGGER_UNCONDITIONAL(state)                      { FblFsmEventHandlerDefault, kFblFsmDefaultEvent_Entry, (state)               }
/** Unconditional state transition with additional action (any entry handler has to return negative guard result) */
#define FBL_FSM_TRIGGER_UNCONDITIONAL_ACTION(action, state)       { (action),                  kFblFsmDefaultEvent_Entry, (state)               }

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/** State type for state machine (the real states need to be defined by the component(s) using this module) */
typedef vuint16 tFblFsmState;

/** Event type for state machine (the real events need to be defined by the component(s) using this module) */
typedef vuint16 tFblFsmEvent;

#if defined( FBL_FSM_ENABLE_DEBUGGING )
/** Instance number */
typedef vuint8 tFblFsmInstance;
#endif /* FBL_FSM_ENABLE_DEBUGGING */

/** Event type (components using this module shall start to enumerate their events with kFblFsmDefaultEvent_Count) */
typedef enum
{
   kFblFsmDefaultEvent_None,           /**< No event */
   kFblFsmDefaultEvent_Entry,          /**< State entry event */
   kFblFsmDefaultEvent_Exit,           /**< State exit event */
   kFblFsmDefaultEvent_Any,            /**< Don't care event */

   kFblFsmDefaultEvent_Count           /**< Decimal number of default events */
} tFblFsmDefaultEvents;

/** Guard type */
typedef enum
{
   kFblFsmGuard_True,                  /**< True: State transition is allowed */
   kFblFsmGuard_False,                 /**< False: State transition is prohibited */
   kFblFsmGuard_Overwrite              /**< Allow pending state to set next state (override state table configuration), defaults to no transition */
} tFblFsmGuard;

/** Forward declaration of context structure */
typedef struct sFblFsmContext tFblFsmContext;

/** Pointer to context structure */
typedef V_MEMRAM1 tFblFsmContext V_MEMRAM2 V_MEMRAM3 * tFblFsmContextPtr;

/** Event handler function pointer */
typedef tFblFsmGuard (* tFblFsmEventHandler)( tFblFsmContextPtr const pFsmContext, tFblFsmEvent event );

typedef struct
{
   tFblFsmEventHandler  handler;       /**< Event handler */
   tFblFsmEvent         trigger;       /**< Event that triggers execution of handler */
   tFblFsmState         nextState;     /**< Next state if event handler returns kFblFsmGuard_True */
} tFblFsmEventEntry;

/** State definition */
typedef struct
{
   tFblFsmState   superState;          /**< Super state (encapsulating state) */
   vuint16        triggerCount;        /**< Size of array structure element 'triggers' points to */
   /** Array containing triggers (events) and the corresponding actions for state */
   V_MEMROM1 tFblFsmEventEntry V_MEMROM2 V_MEMROM3 * triggers;
} tFblFsmStateDefinition;

/** Context structure */
struct sFblFsmContext
{
   /** Pointer to array containing state definitions (set by component(s) using this module) */
   V_MEMROM1 tFblFsmStateDefinition V_MEMROM2 V_MEMROM3 * stateDefinitions;
   vuint16           stateCount;       /**< Number of elements in stateDefinitions (set by component(s) using this module) */
   tFblFsmState      state;            /**< Current state (intended for internal usage) */
   tFblFsmState      pendingState;     /**< Pending state (intended for internal usage) */
   tFblFsmEvent      pendingEvent;     /**< Pending event (intended for internal usage) */
#if defined( FBL_FSM_ENABLE_DEBUGGING )
   tFblFsmInstance   instance;         /**< State machine instance number */
#endif
};

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#if defined( __cplusplus )
extern "C" {
#endif

void FblFsmInitPowerOn( void );
void FblFsmInit( tFblFsmContextPtr const pFsmContext, tFblFsmState initialState );
void FblFsmDeinit( tFblFsmContextPtr const pFsmContext );
void FblFsmStateTask( tFblFsmContextPtr const pFsmContext );
void FblFsmTriggerEvent( tFblFsmContextPtr const pFsmContext, tFblFsmEvent event );
tFblFsmGuard FblFsmEventHandlerDefault( tFblFsmContextPtr const pFsmContext, tFblFsmEvent event );

#if defined( __cplusplus )
} /* extern "C" */
#endif

#endif /* __FBL_FSM_H__ */

/**********************************************************************************************************************
 *  END OF FILE: FBL_FSM.H
 *********************************************************************************************************************/

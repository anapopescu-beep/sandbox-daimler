/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Event-driven hierarchical finite state machine implementation
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
 *  01.00.01  2012-12-10  JHg     -                  No changes
 *  01.01.00  2013-12-11  JHg     ESCAN00071901      Renamed package to FblLib_Fsm
 *                        ASe     -                  Performed MISRA checks
 *  01.01.01  2019-01-24  Rie     ESCAN00101864      No changes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "fbl_fsm_inc.h"

/**********************************************************************************************************************
 *  VERSION
 *********************************************************************************************************************/

/* --- Version check --- */
#if ( FBLLIB_FSM_VERSION != 0x0101u ) || \
    ( FBLLIB_FSM_RELEASE_VERSION != 0x01u )
# error "Error in FBL_FSM.C: Source and header file are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/** Type to select whether super-states should be iterated in case no matching event handler was found */
typedef enum
{
   kFsmIterateHierarchy_Disabled,   /**< Do not iterate super-states */
   kFsmIterateHierarchy_Enabled     /**< Iterate super-states until matching event handler was found */
} tFsmIterateHierarchy;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

static void FblFsmHandleEvent( tFblFsmContextPtr const pFsmContext, tFblFsmEvent event, tFsmIterateHierarchy iterate);
static vuint8 FblFsmGetStateHierachy( const V_MEMRAM1 tFblFsmContext V_MEMRAM2 V_MEMRAM3 * const pFsmContext, tFblFsmState state,
                                      V_MEMRAM1 tFblFsmState V_MEMRAM2 V_MEMRAM3 * hierarchy );

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#if defined( FBL_FSM_ENABLE_DEBUGGING )
/** Global state machine instance counter */
static tFblFsmInstance g_Instance;
#endif

/* PRQA S 0277 FblFsm_0277 */ /* MD_FblFsm_0277 */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  FblFsmGetStateHierachy
 *********************************************************************************************************************/
/*! \brief        Provides the state hierarchy starting with the given state
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    state The current state
 *  \param[out]   hierarchy The returned state hierarchy
 *********************************************************************************************************************/
static vuint8 FblFsmGetStateHierachy( const V_MEMRAM1 tFblFsmContext V_MEMRAM2 V_MEMRAM3 * const pFsmContext,
                                      tFblFsmState state,
                                      V_MEMRAM1 tFblFsmState V_MEMRAM2 V_MEMRAM3 * hierarchy )
{
   vuint8 index;

   index = 0u;

   while (FBL_FSM_DEFAULT_STATE != state)
   {
      /* Check for hierarchy depth and stateCount to prevent buffer overrun(s) */
      if ( (index >= FBL_FSM_MAX_HIERARCHY_DEPTH)
        || (state >= pFsmContext->stateCount))
      {
         FBL_FSM_DEBUG_ERROR_PRINT(pFsmContext->instance);

         index = 0u;
         state = FBL_FSM_DEFAULT_STATE;
      }
      else
      {
         hierarchy[index] = state;
         index++;

         state = pFsmContext->stateDefinitions[state].superState;
      }
   }

   return index;
}

/**********************************************************************************************************************
 *  FblFsmHandleEvent
 *********************************************************************************************************************/
/*! \brief        Handles the given event
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event The event to be handled
 *  \param[out]   iterate Indicates whether state hierarchy iteration is allowed
 *********************************************************************************************************************/
static void FblFsmHandleEvent( tFblFsmContextPtr const pFsmContext, tFblFsmEvent event, tFsmIterateHierarchy iterate )
{
   vuint16 index;
   vuint16 hierarchy;
   tFblFsmState state;                                                           /* PRQA S 0781 */ /* MD_FblFsm_0781 */
   tFblFsmGuard guard;
   V_MEMROM1 tFblFsmStateDefinition V_MEMROM2 V_MEMROM3 * stateDef;
   V_MEMROM1 tFblFsmEventEntry V_MEMROM2 V_MEMROM3 * triggers;                   /* PRQA S 0781 */ /* MD_FblFsm_0781 */

   state = pFsmContext->state;
   hierarchy = 0u;

   FBL_FSM_DEBUG_PRINT2(pFsmContext->instance, event, state);

   while ( (FBL_FSM_DEFAULT_STATE != state)
        && (state < pFsmContext->stateCount))
   {
      stateDef = &pFsmContext->stateDefinitions[state];
      triggers = stateDef->triggers;

      /* Search for matching event handler */
      for (index = 0u; index < stateDef->triggerCount; index++)
      {
         if ( (triggers[index].trigger == event)
           || (triggers[index].trigger == kFblFsmDefaultEvent_Any) )
         {
            /* Handler matching event found, now execute handler */
            guard = triggers[index].handler(pFsmContext, event);

            FBL_FSM_DEBUG_PRINT3(pFsmContext->instance, guard);

            if (kFblFsmGuard_False != guard)
            {
               if (kFblFsmGuard_True == guard)
               {
                  /* Pending state may be "none" */
                  pFsmContext->pendingState = triggers[index].nextState;
               }
               else /* kFblFsmGuard_Overwrite */
               {
                  /* Do not set pendingState, this is (has to be) done by the event handler */
               }

               /* Stop searching for event handlers as event was handled */
               state = FBL_FSM_DEFAULT_STATE;
               break;
            }
            else /* kFblFsmGuard_False */
            {
               /* State shall not be left, continue to search for other matching event handlers */
            }
         }
      }

      /* Check if event has been already handled */
      if (FBL_FSM_DEFAULT_STATE != state)
      {
         /* No matching event handler returning kFblFsmGuard_True could be found for current state,
          * continue search in (encapsulating) super state, if possible */
         if (kFsmIterateHierarchy_Enabled == iterate)
         {
            hierarchy++;

            if (hierarchy < FBL_FSM_MAX_HIERARCHY_DEPTH)
            {
               state = stateDef->superState;
            }
            else
            {
               /* Abort search to avoid (potential) infinite loop */
               FBL_FSM_DEBUG_ERROR_PRINT(pFsmContext->instance);

               state = FBL_FSM_DEFAULT_STATE;
            }
         }
         else
         {
            /* State traversing not allowed, abort search at this point */
            state = FBL_FSM_DEFAULT_STATE;
         }
      }
   }

#if defined( FBL_FSM_ENABLE_DEBUGGING )
   if ( (state >= pFsmContext->stateCount)
     && (FBL_FSM_DEFAULT_STATE != state) )
   {
      FBL_FSM_DEBUG_ERROR_PRINT(pFsmContext->instance);
   }
#endif /* FBL_FSM_ENABLE_DEBUGGING */
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  FblFsmInitPowerOn
 *********************************************************************************************************************/
/*! \brief        Module initialization
 *********************************************************************************************************************/
void FblFsmInitPowerOn( void )
{
#if defined( FBL_FSM_ENABLE_DEBUGGING )
   g_Instance = 0u;
#endif
}

/**********************************************************************************************************************
 *  FblFsmInit
 *********************************************************************************************************************/
/*! \brief        State machine initialization
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    initialState The initial state of the state machine
 *********************************************************************************************************************/
void FblFsmInit( tFblFsmContextPtr const pFsmContext, tFblFsmState initialState )
{
#if defined( FBL_FSM_ENABLE_DEBUGGING )
   pFsmContext->instance = g_Instance;
   g_Instance++;
#endif

   /* Start with internal default state */
   pFsmContext->state = FBL_FSM_DEFAULT_STATE;
   pFsmContext->pendingState = initialState;
   pFsmContext->pendingEvent = kFblFsmDefaultEvent_None;

   /* Enter provided initial state */
   FblFsmStateTask(pFsmContext);
}

/**********************************************************************************************************************
 *  FblFsmDeinit
 *********************************************************************************************************************/
/*! \brief        State machine deinitialization
 *  \param[in]    pFsmContext Pointer to context of state machine
 *********************************************************************************************************************/
void FblFsmDeinit( tFblFsmContextPtr const pFsmContext )
{
   /* Switch to internal default state to avoid further processing */
   pFsmContext->state = FBL_FSM_DEFAULT_STATE;
   pFsmContext->pendingState = FBL_FSM_DEFAULT_STATE;
   pFsmContext->pendingEvent = kFblFsmDefaultEvent_None;
}

/**********************************************************************************************************************
 *  FblFsmStateTask
 *********************************************************************************************************************/
/*! \brief        State machine handling
 *  \details      This function checks for pending events / state transitions and handles them appropriately.
 *  \param[in]    pFsmContext Pointer to context of state machine
 *********************************************************************************************************************/
void FblFsmStateTask( tFblFsmContextPtr const pFsmContext )
{
   tFblFsmEvent   event;

   tFblFsmState   stateHierarchyExit[FBL_FSM_MAX_HIERARCHY_DEPTH];
   tFblFsmState   stateHierarchyEntry[FBL_FSM_MAX_HIERARCHY_DEPTH];

   tFblFsmState   currentState;
   tFblFsmState   pendingState;                                                  /* PRQA S 0781 */ /* MD_FblFsm_0781 */

   vsint8         index;
   vuint8         exitCount;
   vuint8         entryCount;
   vsint8         exitIndex;
   vsint8         entryIndex;

   /* Check for pending event, which could cause state change */
   event = pFsmContext->pendingEvent;

   if (kFblFsmDefaultEvent_None != event)
   {
      /* Reset event */
      pFsmContext->pendingEvent = kFblFsmDefaultEvent_None;

      /* Process event and trigger state change if necessary */
      FblFsmHandleEvent(pFsmContext, event, kFsmIterateHierarchy_Enabled);
   }

   /* Check whether state has to be changed */
   while (FBL_FSM_DEFAULT_STATE != pFsmContext->pendingState)
   {
      currentState = pFsmContext->state;
      pendingState = pFsmContext->pendingState;

      FBL_FSM_DEBUG_PRINT1(pFsmContext->instance, currentState, pendingState);

      /* Reset event which triggered state change */
      pFsmContext->pendingState = FBL_FSM_DEFAULT_STATE;

      /* Get state hierarchy of current state and pending state */
      exitCount = FblFsmGetStateHierachy(pFsmContext, currentState, stateHierarchyExit);
      entryCount = FblFsmGetStateHierachy(pFsmContext, pendingState, stateHierarchyEntry);

      /* Check for re-entry of current state */
      if (currentState == pendingState)
      {
         exitIndex = 0;
         entryIndex = 0;
      }
      else
      {
         exitIndex = (vsint8)(exitCount - 1);
         entryIndex = (vsint8)(entryCount - 1);

         /* Search for common super state of current state and pending state */
         while ( (exitIndex >= 0)
               && (stateHierarchyExit[exitIndex] == stateHierarchyEntry[entryIndex]) )
         {
            exitIndex--;
            entryIndex--;
         }

         /* An exitIndex / entryIndex larger than 0 indicates that both state have a common super state */
      }

      /* Leave all super-states
       * A state is always left, even if the pending state is the same (re-entry),
       * but not if the target state is a sub-state of the current state.
       * An exit handler is executed after the transition action has been executed */
      for (index = 0; index <= exitIndex; index++)
      {
         pFsmContext->state = stateHierarchyExit[index];

         /* Leave previous state by calling exit handler */
         FblFsmHandleEvent(pFsmContext, kFblFsmDefaultEvent_Exit, kFsmIterateHierarchy_Disabled);
      }

      /* Enter all super-states
       * A pending state is only entered if it is not a previous super-state */
      for (index = entryIndex; index >= 0; index--)
      {
         pFsmContext->state = stateHierarchyEntry[index];

         /* Now enter new state by calling entry handler */
         FblFsmHandleEvent(pFsmContext, kFblFsmDefaultEvent_Entry, kFsmIterateHierarchy_Disabled);
      }

      /* Set final state, necessary if new state is super-state of previous state (no re-entry) */
      pFsmContext->state = pendingState;
   }
}

/**********************************************************************************************************************
 *  FblFsmTriggerEvent
 *********************************************************************************************************************/
/*! \brief        Triggers event for given state machine
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event The event to be triggered
 *********************************************************************************************************************/
void FblFsmTriggerEvent( tFblFsmContextPtr const pFsmContext, tFblFsmEvent event )
{
   pFsmContext->pendingEvent = event;
}

/**********************************************************************************************************************
 *  FblFsmEventHandlerDefault
 *********************************************************************************************************************/
/*! \brief        Default event handler
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event The event that triggered the handler execution
 *********************************************************************************************************************/
tFblFsmGuard FblFsmEventHandlerDefault( tFblFsmContextPtr const pFsmContext, tFblFsmEvent event ) /* PRQA S 3673 */ /* MD_FblFsm_3673 */
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)pFsmContext;                                                            /* PRQA S 3112 */ /* MD_FblFsm_3112 */
   (void)event;                                                                  /* PRQA S 3112 */ /* MD_FblFsm_3112 */
#endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   /* Do nothing, but allow state transition */

   return kFblFsmGuard_True;
}

/* PRQA L:FblFsm_0277 */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_FblFsm_0277:
      Reason: An integer constant expression with negative value is being converted to an unsigned type.
      Risk: No identifiable risk. The conversion is defined by the C standard.
      Prevention: The code has to be reviewed carefully (justification only valid for usage of FBL_FSM_DEFAULT_STATE).

   MD_FblFsm_0781:
      Reason: The variable is being used as a structure/union member as well as being a label, tag or ordinary
              identifier. This way it is more clear to the reader which purpose the variable has.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_FblFsm_3112:
      Reason: Dummy statements have been added to avoid compiler warnings because of unused variables.
      Risk: Unused statements add to program complexity just by being there - adding lines to the program and causing
            readers to puzzle over its presence.
      Prevention: Dummy statements can be turned off externally (V_DISABLE_USE_DUMMY_STATEMENT).

   MD_FblFsm_3673:
      Reason: This interface is standardized for event handlers. Event handlers are provided from the calling
              application and usually modify the state machines context.
      Risk: No identifiable risk.
      Prevention: No prevention required.

*/

/**********************************************************************************************************************
 *  END OF FILE: FBL_FSM.C
 *********************************************************************************************************************/

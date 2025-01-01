/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \ingroup     Os_Kernel
 *  \defgroup    Os_Trace Trace
 *  \brief       Definition of OS tracing hooks.
 *  \details
 *  OS Tracing
 *  ===========
 *  OS Tracing is used for different purposes:
 *    - OSEK Runtime Interface (ORTI):
 *       - ORTI Service tracing
 *       - ORTI Thread tracing
 *    - Vector Timing Hooks (VTH):
 *       - VTH for thread switching
 *       - VTH for thread activation
 *       - VTH for locks
 *       - VTH for forcible termination
 *    - AUTOSAR Runtime Interface (ARTI):
 *       - ARTI Service tracing
 *       - ARTI Thread tracing
 *       - ARTI Application tracing
 *       - ARTI Lock tracing
 *
 *  OSEK Runtime Interface
 *  ----------------------
 *  ORTI is a quite general interface description language which covers not only tracing aspects. However, this design
 *  only covers tracing and therefore only the tracing aspects of ORTI. ORTI tracing is performed by the debugger
 *  tracing the values of a specified set of global variables via the hardware debugging interface.
 *
 *  ### ORTI Service tracing
 *  ORTI service tracing is performed by means of the following two functions:
 *  - Os_TraceApiEntry()
 *  - Os_TraceApiExit()
 *
 *  Whenever an OS API function is entered, the function Os_TraceApiEntry is called while the function
 *  Os_TraceApiExit is called on any return from an OS API function to the application. These functions simply
 *  set the variable Os_CfgTraceCoreXDyn.OrtiCurrentServiceId (where X is the core-ID). As described in the ORTI
 *  standard, the least significant bit of the variable is set to 1 on API entry and to 0 on exit. The other bits
 *  of the variable contain the number of the API service.
 *
 *  ### ORTI Thread tracing
 *  The ORTI standard defines that threads are traced independently for tasks and ISRs. Unfortunately, this OS
 *  implementation has no such variables if no ORTI tracing is enabled. Therefore, two global variables per core
 *  exist if ORTI tracing is enabled to trace the currently running thread: The members CurrentTask and CurrentIsr
 *  of struct type Os_CfgTraceCore0Dyn.
 *  These variables are set by the functions:
 *  - Os_TraceThreadSuspendAndStart()
 *  - Os_TraceThreadCleanupAndResume()
 *  - Os_TraceThreadResetAndResume()
 *  - Os_TraceThreadSwitch()
 *
 *  These are exactly the same functions as used to call the scheduling hook in case timing hooks are enabled.
 *
 *  Vector timing hooks
 *  -------------------
 *  The MICROSAR OS timing hooks shall provide all timing relevant information at runtime to an external
 *  tracing tool. As timing relevant information, we consider:
 *  - Thread activation: A task or ISR gets activated but needs not necessarily start to run.
 *  - Thread switch: Task switch or interrupt entry/exit.
 *  - Locks: A lock (spinlock, semaphore, interrupt lock) is acquired or released.
 *  - Forcible termination: A task, ISR or OS application is terminated as a result of a detected problem.
 *
 *  The subchapters below define, how this information is provided to the external tracing tool.
 *
 *  ### VTH for thread activation
 *  Information about thread activation is useful to retrieve the minimum time between activations. This
 *  information can only be retrieved from the start times of threads with additional jitter. The information
 *  about thread activation is also helpful to visualize the time between activation and start of a thread.
 *  The different kinds of thread activation which have been identified are
 *  - Task activation
 *  - Event setting
 *
 *  Interrupt request would generally also be some sort of thread activation. However, this kind of thread
 *  activation is performed completely in the hardware and is therefore out of scope of the OS.
 *
 *  #### VTH for task activation
 *  Task activation may happen as a result of an API (ActivateTask(), ChainTask()) call or by alarm action or
 *  schedule table expiry point. If the called API is successful then it is signaled to the external tracing tool
 *  by calling the  macro OS_VTH_ACTIVATION(). If the called API is not successful because the number of activations
 *  has reached the limit then it is signaled to the external tracing tool by calling macro OS_VTH_ACTIVATION_LIMIT().
 *
 *  #### VTH for event setting
 *  Event setting may be seen as an activation of a task in case the task is typically waiting for events
 *  which trigger the activity of the task. However, if any event setting is considered to be an activation,
 *  the minimum time between task activations may be underestimated heavily. Therefore, the Autosar OS standard
 *  considers event setting only as an activation if it results in a state change from WAITING to READY.
 *  However, even that may not result in a suitable minimum time between activations. Therefore, also the events
 *  which shall be set are given to the external tracing tool.
 *  Examples where information about the events is necessary to make better assumptions on the timing behavior are:
 *  - A task which waits for two events (gets active if any of these events is set). Events occur with cycle times
 *    2ms and 3ms. Knowing the events could result in the intuition that at most two events per millisecond can occur
 *    while the minimum time between event occurrences may be measured infinitely small.
 *  - A task which waits until two events have occurred (first calling WaitEvent for the first event, afterwards
 *    waiting for the second one on a second call of WaitEvent). If the first event occurs first, this could be seen
 *    as an activation of the small task part until the second WaitEvent, the second event would be seen as the
 *    activation of the bigger task part. If the second event occurred first, this would not be seen as an activation
 *    but the occurrence of the first event would then be seen as an activation of both task parts.
 *
 *  Event setting can occur by means of the API call to SetEvent() or by means of alarm action or schedule table
 *  expiry point. Event setting is signaled to the external tracing tool by a call of the macro OS_VTH_SETEVENT().
 *
 *  ### VTH for thread switching
 *  Thread switches are the most important information to be traced by an external tool as they represent a change
 *  of the thread of control. Such thread switches occur at interrupt entry and exit as well as at a task switch.
 *  Each thread switch occurs between a task or ISR which was executed before the thread switch and another task
 *  or ISR which becomes executing as a result of the thread switch. In any case, there is a reason for the thread
 *  switch which often depends on the relation between the two threads. That reason can easily be divided into a
 *  reason why the last thread is no longer executed and a reason why the new thread becomes executing. That reason
 *  is important to the external tracing tool as it has to separate between interruption/preemption and the end of
 *  a task or ISR. The macro OS_VTH_SCHEDULE() is called by the OS to signal thread switches. Mind, that there is
 *  no tracing for hook threads. However, as all threads shall have tracing objects, hooks share one tracing object
 *  per core.
 *
 *  ###VTH for locks
 *  Information about locks (resources, spinlocks and interrupt locks) is interesting as threads which
 *  hold locks may prevent other threads from being executed. Dependent on the type of lock, a thread may wait
 *  (inactively or busy) until the lock is free and can be taken. Information about that is also interesting.
 *  The subchapters provide the measures for tracing of the different locks.
 *
 *  ####VTH for resources
 *  Resources are a lock type which never requires a thread to wait for it. So only the information about
 *  getting and releasing the lock is worth tracing. The OS signals the respective events to the external
 *  tracing tool by means of the macros: OS_VTH_GOT_RES() and OS_VTH_REL_RES().
 *
 *  ####VTH for spinlocks
 *  Spinlocks are a type of lock, where a thread may perform busy waiting. Therefore, the waiting time is
 *  unavailable to any thread with lower priority on the core where the spinlock shall be acquired. Once
 *  the spinlock has been taken, all other threads on other cores need to wait until the spinlock is released.
 *  This has been considered when stating the following requirements.
 *
 *  Mind that although spinlocks are used to coordinate cross core resource accesses, all spinlock operations
 *  are performed core locally.
 *
 *  The OS signals spinlock events to an external tracing tool by means of the macros OS_VTH_REQ_SPINLOCK(),
 *  OS_VTH_GOT_SPINLOCK() and OS_VTH_REL_SPINLOCK().
 *
 *  The OS uses spinlocks also internally. Usually one would assume that internal spinlocks are locked for
 *  much shorter time than those, used by the application. However, this may not be true for applications
 *  with extremely strict realtime requirements. Therefore, timing hooks are also provided for internally
 *  #used spinlocks. In order to keep the overhead small, the OS uses different hook macros. So these macros
 *  may be empty in case no information about internal locking is necessary.
 *
 *  The OS signals internal spinlock events to an external tracing tool by means of the macros
 *  OS_VTH_REQ_ISPINLOCK(), OS_VTH_GOT_ISPINLOCK() and OS_VTH_REL_ISPINLOCK().
 *
 *  ####VTH for interrupt locks
 *  The time of holding an interrupt lock is interesting as the processing core is unavailable to any other
 *  thread as long as a thread holds an interrupt lock. The OS signals interrupt lock events to the external
 *  tracing tool by means of the macros OS_VTH_DISABLEDINT() and OS_VTH_ENABLEDINT(). Either of these macros
 *  has a parameter to signal whether all interrupts are disabled or only just interrupts of category 2.
 *
 *  ###VTH for forcible termination
 *  Tasks and ISRs may be forcibly terminated as a result of a call to the API service TerminateApplication()
 *  or a a result of a detected protection error. This is important to an external tracing tool as the
 *  respective task of ISR will usually not finish its job on time. The OS signals forcible termination by
 *  a call of the macro OS_VTH_FORCED_TERMINATION().
 *
 *  AUTOSAR Runtime Interface
 *  -------------------------
 *  The ARTI standard extends the ORTI standard by a couple of features, especially hook callouts at the major timing
 *  points in the OS, e.g. thread switches or locks. Thus, the ARTI standard could be seen as a combination of ORTI and
 *  the Vector timing hooks. In addition, the ARTI standard extends the traced variables by the currently running
 *  application. To achieve this, a new member was added to the struct type Os_CfgTraceCore0Dyn: CurrentThread.
 *  CurrentThread is always set, when CurrentTask or CurrentIsr is set.
 *
 *
 *  ### ARTI Service tracing
 *  Equal to ORTI service tracing, ARTI service tracing is performed by means of the following two functions:
 *  - Os_TraceApiEntry()
 *  - Os_TraceApiExit()
 *
 *  On the contrary to ORTI Service tracing, ARTI Service tracing is not done by monitoring a single variable, but by
 *  providing ARTI hooks for each OS Service. The ARTI hooks are described in detail in the following chapter.
 *
 *  ### ARTI (timing) Hooks
 *  Similar to the Vector timing hooks, the ARTI hooks provide timing relevant information at runtime to an external
 *  tracing tool. See {Vector timing hooks} for information on what is considered timing relevant information.
 *  Additionally, the ARTI standard extends the Vector timing hooks by defining additional tracing hooks for Protection
 *  hook calls and application switches.
 *
 *  To call an ARTI hook, MICROSAR OS defines the following macro:
 *  # define OS_CALL_ARTI_TRACE(_className, osCoreId, _eventName, eventParameter)
 *               ARTI_TRACE(NOSUSP, AR_CP_ ## _className, Os, (osCoreId), _eventName, (eventParameter))
 *
 *  The macro ARTI_TRACE is defined by the ARTI component, which provides the final implementation of the hooks.
 *  The macro arguments are described as follows:
 *  - _className     : ARTI hook class.
 *  - osCoreId       : The Core ID.
 *  - _eventName     : ARTI hook (short)name.
 *  - eventParameter : Parameter passed to the hook.
 *
 *  Note, that MICROSAR OS does not provide information about eventParameter.
 *  Instead 0 is used as argument in the macro.
 *  Design decision, as the information does not offer added value.
 *
 *  Below subchapters list the defined ARTI hooks, grouped by the respective ARTI hook class. Each class can be switched
 *  on and off independently from the others in the generator.
 *
 *  # OS_SERVICECALLS
 *  For each OS Service, below ARTI hooks are defined:
 *  - OsServiceCall_<ServiceName>_Start  : Begin of the Service call.
 *  - OsServiceCall_<ServiceName>_Return : End of the Service call.
 *
 *  # OSARTI_TASK
 *  - OsTask_Activate  : The given task is activated.
 *  - OsTask_Start     : The given task starts execution.
 *  - OsTask_Wait      : The given task enters the WAITING state.
 *  - OsTask_Preempt   : The given task got preempted and enters the READY state.
 *  - OsTask_Resume    : The given task is resumed.
 *  - OsTask_Release   : An event is set for the given task.
 *  - OsTask_Continue  : The given task continues execution due to a SetEvent().
 *  - OsTask_Terminate : The given task terminates or is forcibly terminated.
 *
 *  # OS_CAT2ISR
 *  - OsCat2Isr_Start : The given Cat2Isr starts or resumes execution.
 *  - OsCat2Isr_Stop  : The given Cat2Isr suspends or finishes execution.
 *
 *  Note, that MICROSAR OS only implements the class OS_CAT2ISR and not the class OSARTI_CAT2ISR.
 *
 *  # OS_SPINLOCK
 *  - OsSpinlock_Locked   : The given spinlock is locked.
 *  - OsSpinlock_Released : The given spinlock is released.
 *
 *  # OS_APPLICATION
 *  - OsApplication_Start       : The given application is started.
 *  - OsApplication_Restart     : The given application is restarted.
 *  - OsApplication_AllowAccess : Access is granted for the given application. Usually, this happens after an
 *                                application is restarted.
 *  - OsApplication_Terminate   : The given application is terminated (killed).
 *
 *  # OS_PROTECTIONHOOK
 *  - ProtectionHookStart  : The ProtectionHook is entered with the given error status.
 *  - ProtectionHookReturn : The ProtectionHook is left with the given return value.
 *
 *  \{
 *
 *  \file
 *  \brief       This file decides which tracing hooks shall be used.
 *  \details
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_TRACEINT_H
# define OS_TRACEINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Trace_Types.h"
# include "Os_Trace_Cfg.h"
# include "Os_Trace_Lcfg.h"


/* Os kernel module dependencies */
# include "Os_Cfg.h"
# include "OsInt.h"
# include "Os_Common_Types.h"
# include "Os_CoreInt.h"
# include "Os_Thread_Types.h"

/* Os Hal dependencies */
# include "Os_Hal_CompilerInt.h"


# if(OS_CFG_ORTI == STD_ON)
#  include "Os_Orti.h"
# endif

# if !defined(OS_TRACE)                                                                                                 /* COV_OS_TRACEOSTRACE */
#  define OS_TRACE       OS_CFG_ORTI
# endif


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/* The OS_IS_DEFINED_ macros below are necessary as Doxygen cannot handle the following sequence correctly:
 * #ifndef   SOME_MACRO
 * DOXYGEN-comment for SOME_MACRO
 * #define SOME_MACRO
 * #endif
  *
  */
# ifdef OS_VTH_SCHEDULE
#  define OS_IS_DEFINED_OS_VTH_SCHEDULE            STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_SCHEDULE            STD_OFF
# endif

# ifdef OS_VTH_FORCED_TERMINATION
#  define OS_IS_DEFINED_OS_VTH_FORCED_TERMINATION  STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_FORCED_TERMINATION  STD_OFF
# endif

# ifdef OS_VTH_ACTIVATION
#  define OS_IS_DEFINED_OS_VTH_ACTIVATION          STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_ACTIVATION          STD_OFF
# endif

# ifdef OS_VTH_ACTIVATION_LIMIT
#  define OS_IS_DEFINED_OS_VTH_ACTIVATION_LIMIT    STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_ACTIVATION_LIMIT    STD_OFF
# endif

# ifdef OS_VTH_SETEVENT
#  define OS_IS_DEFINED_OS_VTH_SETEVENT            STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_SETEVENT            STD_OFF
# endif

# ifdef OS_VTH_WAITEVENT_NOWAIT
#  define OS_IS_DEFINED_OS_VTH_WAITEVENT_NOWAIT    STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_WAITEVENT_NOWAIT    STD_OFF
# endif

# ifdef OS_VTH_GOT_RES
#  define OS_IS_DEFINED_OS_VTH_GOT_RES             STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_GOT_RES             STD_OFF
# endif

# ifdef OS_VTH_REL_RES
#  define OS_IS_DEFINED_OS_VTH_REL_RES             STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_REL_RES             STD_OFF
# endif

# ifdef OS_VTH_REQ_SPINLOCK
#  define OS_IS_DEFINED_OS_VTH_REQ_SPINLOCK        STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_REQ_SPINLOCK        STD_OFF
# endif

# ifdef OS_VTH_GOT_SPINLOCK
#  define OS_IS_DEFINED_OS_VTH_GOT_SPINLOCK        STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_GOT_SPINLOCK        STD_OFF
# endif

# ifdef OS_VTH_REL_SPINLOCK
#  define OS_IS_DEFINED_OS_VTH_REL_SPINLOCK        STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_REL_SPINLOCK        STD_OFF
# endif

# ifdef OS_VTH_DISABLEDINT
#  define OS_IS_DEFINED_OS_VTH_DISABLEDINT         STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_DISABLEDINT         STD_OFF
# endif

# ifdef OS_VTH_ENABLEDINT
#  define OS_IS_DEFINED_OS_VTH_ENABLEDINT          STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_ENABLEDINT          STD_OFF
# endif

# ifdef OS_VTH_REQ_ISPINLOCK
#  define OS_IS_DEFINED_OS_VTH_REQ_ISPINLOCK       STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_REQ_ISPINLOCK       STD_OFF
# endif

# ifdef OS_VTH_GOT_ISPINLOCK
#  define OS_IS_DEFINED_OS_VTH_GOT_ISPINLOCK       STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_GOT_ISPINLOCK       STD_OFF
# endif

# ifdef OS_VTH_REL_ISPINLOCK
#  define OS_IS_DEFINED_OS_VTH_REL_ISPINLOCK       STD_ON
# else
#  define OS_IS_DEFINED_OS_VTH_REL_ISPINLOCK       STD_OFF
# endif



/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Defines the reason why the OS starts to execute a thread. */
typedef enum
{
  /*! The task is started as it was activated. */
  OS_TRACE_TASK_ACTIVATION = OS_VTHP_TASK_ACTIVATION,
  /*! The ISR is started as the interrupt was requested. */
  OS_TRACE_ISR_START = OS_VTHP_ISR_START,
  /*! The task is executed as an event has occurred, the task was waiting for. */
  OS_TRACE_TASK_SETEVENT = OS_VTHP_TASK_SETEVENT,
  /*! The task is executed as it got the semaphore it was waiting for. */
  OS_TRACE_TASK_GOTSEMA = OS_VTHP_TASK_GOTSEMA,
  /*! The task or ISR is executed as the preempting/interrupting task/ISR has finished execution. */
  OS_TRACE_THREAD_RESUME = OS_VTHP_THREAD_RESUME,
  /*! The thread has been forcibly terminated, logical entry for cleanup only. */
  OS_TRACE_THREAD_CLEANUP = OS_VTHP_THREAD_CLEANUP,
  /*! The thread shall not be traced (e.g. hook thread).*/
  OS_TRACE_THREAD_MISC
}Os_TraceThreadRunReason;

#if (OS_VTHP_TASK_TERMINATION != OS_VTHP_TASK_ACTIVATION)
# error "The implementation assumes a direct mapping between values for FromThreadReason and ToThreadReason"
#endif
#if (OS_VTHP_ISR_END != OS_VTHP_ISR_START)
# error "The implementation assumes a direct mapping between values for FromThreadReason and ToThreadReason"
#endif
#if (OS_VTHP_TASK_WAITEVENT != OS_VTHP_TASK_SETEVENT)
# error "The implementation assumes a direct mapping between values for FromThreadReason and ToThreadReason"
#endif
#if (OS_VTHP_TASK_WAITSEMA != OS_VTHP_TASK_GOTSEMA)
# error "The implementation assumes a direct mapping between values for FromThreadReason and ToThreadReason"
#endif
#if (OS_VTHP_THREAD_PREEMPT != OS_VTHP_THREAD_RESUME)
# error "The implementation assumes a direct mapping between values for FromThreadReason and ToThreadReason"
#endif

/*! Defines the thread type. */
typedef enum
{
  /*! The tracing object belongs to a task.*/
  OS_TRACE_THREAD_TYPE_TASK = 0,
  /*! The tracing object belongs to an ISR. */
  OS_TRACE_THREAD_TYPE_ISR  = 1,
  /*! The tracing object belongs to another thread (than task or ISR).*/
  OS_TRACE_THREAD_TYPE_MISC = 2
}Os_TraceThreadTypeType;


/*! Defines the next reason to run the thread
 *  \details
 *      - Available per task and ISR
 *      - The next run reason is always determined by the last leave reason
 */
struct Os_TraceThreadType_Tag
{
  /*! The next run reason of this thread. */
  Os_TraceThreadRunReason NextRunReason;
};

/*! Trace configuration data of a thread.
 *  \details
 *     - Available per task and ISR
 *     - Provides the thread/task/ISR-ID to be used as parameter for Vector Timing Hooks. */
struct Os_TraceThreadConfigType_Tag
{
  /*! The dynamic trace data of this thread. */
  P2VAR(Os_TraceThreadType, TYPEDEF, OS_VAR_NOINIT) Dyn;
  /*! The thread ID to be reported to the timing hooks */
  Os_TraceThreadIdType Id;
  /*! The type of traced thread (task/ISR/MISC) */
  Os_TraceThreadTypeType Type;
};

/*! Defines the currently running task, ISR and API service per core. */
struct Os_TraceCoreType_Tag
{
    /*! The currently traced task (for ORTI only tasks and ISRs are relevant) */
    P2CONST(Os_TraceThreadConfigType, TYPEDEF, OS_CONST) CurrentTask;
    /*! The currently traced ISR (for ORTI only tasks and ISRs are relevant) */
    P2CONST(Os_TraceThreadConfigType, TYPEDEF, OS_CONST) CurrentIsr;
    /*! The currently traced thread (for ARTI some attributes of the current thread are relevant) */
    P2CONST(Os_TraceThreadConfigType, TYPEDEF, OS_CONST) CurrentThread;
    /*! the currently traced API service */
    uint8 OrtiCurrentServiceId;
};

/*! Defines the ID of spinlocks and internal spinlocks for tracing */
struct Os_TraceSpinlockConfigType_Tag
{
    Os_TraceSpinlockIdType SpinlockId;
};


/*! Trace configuration data of an application.
 *  \details
 *     - Available per application
 *     - Provides the application-ID to be used as parameter for ARTI Hooks. */
struct Os_TraceAppConfigType_Tag
{
  /*! The application ID to be reported to the ARTI hooks */
  Os_TraceAppIdType Id;
};


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_TraceIsTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether timing hooks are enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    Vector timing hooks are enabled.
 *  \retval       0     Vector timing hooks are disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsScheduleTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsScheduleTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsForcedTerminationTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsForcedTerminationTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsActivationTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsActivationTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsActivationLimitTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsActivationLimitTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsSetEventTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsSetEventTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsWaitEventTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsWaitEventTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsGotResourceTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsGotResourceTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsRelResourceTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsRelResourceTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsReqSpinlockTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsReqSpinlockTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsGotSpinlockTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsGotSpinlockTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsRelSpinlockTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsRelSpinlockTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsDisabledIntTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsDisabledIntTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsEnabledIntTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the according timing hook is enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The timing hook is enabled.
 *  \retval       0     The timing hook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsEnabledIntTimingHookEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsArtiTaskHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the ARTI hooks for Task state changes are enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The ARTI hooks are enabled.
 *  \retval       0     The ARTI hooks are disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TraceIsArtiTaskHookEnabled,
( void ));

/***********************************************************************************************************************
 *  Os_TraceIsArtiCat2IsrHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the ARTI hooks for Cat2 ISR state changes are enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The ARTI hooks are enabled.
 *  \retval       0     The ARTI hooks are disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TraceIsArtiCat2IsrHookEnabled,
( void ));

/***********************************************************************************************************************
 *  Os_TraceIsArtiApplHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the ARTI hooks for OS application state changes are enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The ARTI hooks are enabled.
 *  \retval       0     The ARTI hooks are disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TraceIsArtiApplHookEnabled,
( void ));


/***********************************************************************************************************************
 *  Os_TraceIsArtiSpinlockHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the ARTI hooks for OS spinlocks are enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The ARTI hooks are enabled.
 *  \retval       0     The ARTI hooks are disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TraceIsArtiSpinlockHookEnabled,
( void ));


/***********************************************************************************************************************
 *  Os_TraceIsArtiProtHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the ARTI hooks for the OS protection hook are enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The ARTI hooks are enabled.
 *  \retval       0     The ARTI hooks are disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TraceIsArtiProtHookEnabled,
( void ));


/***********************************************************************************************************************
 *  Os_TraceIsArtiServiceHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the ARTI hooks for OS service tracing are enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    The ARTI hooks are enabled.
 *  \retval       0     The ARTI hooks are disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TraceIsArtiServiceHookEnabled,
( void ));


/***********************************************************************************************************************
 *  Os_TraceIsOrtiServiceTracingEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether ORTI service tracing is enabled or not.
 *  \details      This allows the ORTI debugger to trace the information about the currently performed OS API Service.
 *
 *  \retval       !0    Service tracing is enabled.
 *  \retval       0     Service tracing is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsOrtiServiceTracingEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceIsOrtiTaskIsrTracingEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether ORTI Task/ISR tracing is enabled or not.
 *  \details      This allows the ORTI debugger to trace which task or ISR is currently performed.
 *
 *  \retval       !0    Task/ISR tracing is enabled.
 *  \retval       0     Task/ISR tracing is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsOrtiTaskIsrTracingEnabled, ( void ));

/***********************************************************************************************************************
 *  Os_TraceThreadInit()
 **********************************************************************************************************************/
/*! \brief          Initialize a threads trace data.
 *  \details        The function is called for the idle task in Init-Step3 and for all threads in Init-Step4.
 *
 *  \param[in]      Thread           The thread which shall be initialized
 *                                   Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given objects is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceThreadInit,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Thread
));

/***********************************************************************************************************************
 *  Os_TraceThreadInitAndStart()
 **********************************************************************************************************************/
/*! \brief          Initialize a threads trace data and trace a switch to that thread.
 *  \details        --no details--
 *
 *  \param[in]      Task             The task which shall be initialized and entered.
 *                                   Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given objects is prevented by caller.
 *  \pre            This function is called exactly once per core for the task which shall be traced first.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceThreadInitAndStart,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Task
));

/***********************************************************************************************************************
 *  Os_TraceThreadSwitch()
 **********************************************************************************************************************/
/*! \brief          Trace a thread switch.
 *  \details        Call Vector timing hook for scheduling, ARTI hooks for tasks and store curent task for ORTI if
 *                  configured.
 *
 *  \param[in]      CurrentTaskState The state of the task which is provided by parameter 'Current'
 *  \param[in,out]  Current          The thread which is left.
 *                                   Parameter must not be NULL if tracing is enabled.
 *  \param[in]      Next             The thread which shall be entered.
 *                                   Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given objects is prevented by caller.
 *  \pre            Either Os_TraceThreadInitAndStart() or Os_TraceThreadInit() has been called before for both thread
 *                  parameters.
 *
 *  \trace          CREQ-115029
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceThreadSwitch,
(
  TaskStateType CurrentTaskState,
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Next
));

/***********************************************************************************************************************
 *  Os_TraceThreadResetAndResume()
 **********************************************************************************************************************/
/*! \brief          Trace a thread switch.
 *  \details        Call Vector timing hook for scheduling, ARTI hooks for tasks and store curent task for ORTI if
 *                  configured.
 *
 *  \param[in,out]  Current The thread which is left.
 *                          Parameter must not be NULL if tracing is enabled.
 *  \param[in]      Next    The thread which shall be entered.
 *                          Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given objects is prevented by caller.
 *  \pre            Either Os_TraceThreadInitAndStart() or Os_TraceThreadInit() has been called before for both thread
 *                  parameters.
 *
 *  \trace          CREQ-115029
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceThreadResetAndResume,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Next
));

/***********************************************************************************************************************
 *  Os_TraceThreadCleanupAndResume()
 **********************************************************************************************************************/
/*! \brief          Trace a thread switch.
 *  \details        Call Vector timing hook for scheduling, ARTI hooks for tasks and ISRs and store curent task/ISR for
 *                  ORTI if configured.
 *
 *  \param[in,out]  Current The thread which is left.
 *                          Parameter must not be NULL if tracing is enabled.
 *  \param[in]      Next    The thread which shall be entered.
 *                          Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given objects is prevented by caller.
 *  \pre            Either Os_TraceThreadInitAndStart() or Os_TraceThreadInit() has been called before for both thread
 *                  parameters.
 *
 *  \trace          CREQ-115029
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceThreadCleanupAndResume,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Next
));

/***********************************************************************************************************************
 *  Os_TraceThreadSuspendAndStart()
 **********************************************************************************************************************/
/*! \brief          Trace a thread switch.
 *  \details        Call Vector timing hook for scheduling and store curent task/ISR for ORTI if configured.
 *
 *  \param[in,out]  Current The thread which is left.
 *                          Parameter must not be NULL if tracing is enabled.
 *  \param[in]      Next    The thread which shall be entered.
 *                          Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given objects is prevented by caller.
 *  \pre            Either Os_TraceThreadInitAndStart() or Os_TraceThreadInit() has been called before for both thread
 *                  parameters.
 *
 *  \trace          CREQ-115029
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceThreadSuspendAndStart,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Next
));

/***********************************************************************************************************************
 *  Os_TraceIsrKill()
 **********************************************************************************************************************/
/*! \brief          Trace the forcible termination of an ISR.
 *  \details        Call the Vector timing hook which signals forcible termination.
 *
 *  \param[in,out]  KilledIsr The Isr which is forcibly terminated.
 *                            Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Os_TraceThreadInit() has been called before for KilledIsr.
 *
 *  \trace          CREQ-115030
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsrKill,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) KilledIsr
));

/***********************************************************************************************************************
 *  Os_TraceTaskKill()
 **********************************************************************************************************************/
/*! \brief          Trace the forcible termination of a task.
 *  \details        Call the Vector timing hook which signals forcible termination.
 *
 *  \param[in,out]  KilledTask      The task which is forcibly terminated.
 *                                  Parameter must not be NULL if tracing is enabled.
 *  \param[in]      IsTaskSuspended Reflects the task state before the killing takes place:
 *                   - !0: The task is in state SUSPENDED
 *                   -  0: The task is not in state SUSPENDED
 *
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Either Os_TraceThreadInitAndStart() or Os_TraceThreadInit() has been called before for KilledTask.
 *
 *  \trace          CREQ-115030
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceTaskKill,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) KilledTask,
  Os_StdReturnType IsTaskSuspended
));

/***********************************************************************************************************************
 *  Os_TraceTaskActivate()
 **********************************************************************************************************************/
/*! \brief          Trace the activation of a task.
 *  \details        Call the Vector timing hook and the ARTI task hook which signal task activation.
 *
 *  \param[in]      Task            The task which is activated.
 *                                  Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \trace          CREQ-115010
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceTaskActivate,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TraceTaskActivateLimit()
 **********************************************************************************************************************/
/*! \brief          Trace the failed activation of a task.
 *  \details        Call the Vector timing hook which signals failed task activation.
 *
 *  \param[in]      Task            The task which failed to be activated because the number of activations has reached
 *                                  the limit. Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \trace          CREQ-140268
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceTaskActivateLimit,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TraceTaskSetEvent()
 **********************************************************************************************************************/
/*! \brief          Trace the event setting for a task.
 *  \details        Call the vector timing hook and the ARTI task hook which signal the setting of an event.
 *
 *  \param[in]      Task         The task for which an event is set.
 *                               Parameter must not be NULL if tracing is enabled.
 *  \param[in]      EventMask    The event mask which was used in the service call.
 *  \param[in]      StateChanged
 *                   - !0: The task state has changed from WAITING to READY
 *                   -  0: The task state has not changed
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *
 *  \trace          CREQ-115028
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceTaskSetEvent,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Task,
  EventMaskType EventMask,
  boolean StateChanged
));


/***********************************************************************************************************************
 *  Os_TraceTaskWaitEventNoWait()
 **********************************************************************************************************************/
/*! \brief          Trace the waiting for event when event is already set.
 *  \details        Call the Vector timing hook which signals a call of WaitEvent() while the event has already
 *                  been set.
 *
 *  \param[in]      Task         The task which is waiting for the event.
 *                               Parameter must not be NULL if tracing is enabled.
 *  \param[in]      EventMask    The event mask which was used in the service call.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *
 *  \trace          CREQ-140269
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceTaskWaitEventNoWait,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Task,
  EventMaskType EventMask
));


/***********************************************************************************************************************
 * Os_TraceResourceTaken()
 **********************************************************************************************************************/
/*! \brief          Trace resource occupation (get)
 *  \details        Call the Vector timing hook which signals that a resource has been taken.
 *
 *  \param[in]      ResId The ID of the resource which has been taken
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *
 *  \trace          CREQ-115031
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceResourceTaken,
(
    ResourceType ResId
));

/***********************************************************************************************************************
 * Os_TraceResourceReleased()
 **********************************************************************************************************************/
/*! \brief          Trace resource occupation (release)
 *  \details        Call the Vector timing hook which signals that a resource has been released.
 *
 *  \param[in]      ResId The ID of the resource which has been released
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *
 *  \trace          CREQ-115032
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceResourceReleased,
(
    ResourceType ResId
));

/***********************************************************************************************************************
 * Os_TraceSpinlockRequested()
 **********************************************************************************************************************/
/*! \brief          Trace spinlock occupation (start spinning)
 *  \details        Call the Vector timing hooks which signal that a spinlock or an internal spinlock has been
 *                  requested.
 *
 *  \param[in]      Spinlock        The trace object for the spinlock.
 *                                  Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            -
 *
 *  \trace          CREQ-115033, CREQ-115036
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceSpinlockRequested,
(
    P2CONST(Os_TraceSpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));

/***********************************************************************************************************************
 * Os_TraceSpinlockTaken
 **********************************************************************************************************************/
/*! \brief          Trace spinlock occupation (taken -- immediately or after spinning)
 *  \details        Call the Vector timing hooks and the ARTI spinlock hook which signal that a spinlock or an internal
 *                  spinlock has been taken.
 *
 *  \param[in]      Spinlock        The trace object for the spinlock.
 *                                  Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            -
 *
 *  \trace          CREQ-115034, CREQ-115037
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceSpinlockTaken,
(
    P2CONST(Os_TraceSpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));

/***********************************************************************************************************************
 * Os_TraceSpinlockReleased
 **********************************************************************************************************************/
/*! \brief          Trace spinlock occupation (release)
 *  \details        Call the Vector timing hooks and the ARTI spinlock hook which signal that a spinlock or an internal
 *                  spinlock has been released.
 *
 *  \param[in]      Spinlock        The trace object for the spinlock.
 *                                  Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            -
 *
 *  \trace          CREQ-115035, CREQ-115038
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceSpinlockReleased,
(
    P2CONST(Os_TraceSpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));

/***********************************************************************************************************************
 * Os_TraceInterruptsGlobalDisabled
 **********************************************************************************************************************/
/*! \brief          Trace interrupt locks (global disable)
 *  \details        Call the Vector timing hook which signals that interrupts have been disabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *
 *  \trace          CREQ-115039
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceInterruptsGlobalDisabled,
(
    void
));

/***********************************************************************************************************************
 * Os_TraceInterruptsLevelDisabled
 **********************************************************************************************************************/
/*! \brief          Trace interrupt locks (level disabled)
 *  \details        Call the Vector timing hook which signals that interrupts have been disabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *
 *  \trace          CREQ-115039
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceInterruptsLevelDisabled,
(
    void
));

/***********************************************************************************************************************
 * Os_TraceInterruptsGlobalEnabled
 **********************************************************************************************************************/
/*! \brief          Trace interrupt locks (global enabled)
 *  \details        Call the Vector timing hook which signals that interrupts have been enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *
 *  \trace          CREQ-115040
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceInterruptsGlobalEnabled,
(
    void
));

/***********************************************************************************************************************
 * Os_TraceInterruptsLevelEnabled
 **********************************************************************************************************************/
/*! \brief          Trace interrupt locks (level enabled)
 *  \details        Call the Vector timing hook which signals that interrupts have been enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *
 *  \trace          CREQ-115040
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceInterruptsLevelEnabled,
(
    void
));


/***********************************************************************************************************************
 * Os_TraceOrtiApiEntry
 **********************************************************************************************************************/
/*! \brief          Trace the entry to an API function with an ORTI debugger
 *
 *  \param[in]      ServiceId The ID of the API service which is entered.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceOrtiApiEntry,
(
    OsOrtiApiIdType ServiceId
));

/***********************************************************************************************************************
 * Os_TraceOrtiApiExit
 **********************************************************************************************************************/
/*! \brief          Trace the exit from an API function with an ORTI debugger
 *
 *  \param[in]      ServiceId The ID of the API service which is left.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceOrtiApiExit,
(
    OsOrtiApiIdType ServiceId
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetApplicationID
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetApplicationID() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetApplicationID,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetApplicationID
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetApplicationID() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetApplicationID,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetISRID
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetISRID() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetISRID,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetISRID
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetISRID() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetISRID,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryCallTrustedFunction
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function CallTrustedFunction() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryCallTrustedFunction,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitCallTrustedFunction
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function CallTrustedFunction() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitCallTrustedFunction,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryCheckISRMemoryAccess
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function CheckISRMemoryAccess() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryCheckISRMemoryAccess,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitCheckISRMemoryAccess
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function CheckISRMemoryAccess() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitCheckISRMemoryAccess,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryCheckTaskMemoryAccess
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function CheckTaskMemoryAccess() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryCheckTaskMemoryAccess,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitCheckTaskMemoryAccess
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function CheckTaskMemoryAccess() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitCheckTaskMemoryAccess,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryCheckObjectAccess
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function CheckObjectAccess() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryCheckObjectAccess,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitCheckObjectAccess
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function CheckObjectAccess() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitCheckObjectAccess,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryCheckObjectOwnership
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function CheckObjectOwnership() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryCheckObjectOwnership,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitCheckObjectOwnership
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function CheckObjectOwnership() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitCheckObjectOwnership,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryStartScheduleTableRel
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function StartScheduleTableRel() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryStartScheduleTableRel,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitStartScheduleTableRel
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function StartScheduleTableRel() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitStartScheduleTableRel,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryStartScheduleTableAbs
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function StartScheduleTableAbs() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryStartScheduleTableAbs,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitStartScheduleTableAbs
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function StartScheduleTableAbs() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitStartScheduleTableAbs,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryStopScheduleTable
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function StopScheduleTable() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryStopScheduleTable,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitStopScheduleTable
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function StopScheduleTable() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitStopScheduleTable,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryNextScheduleTable
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function NextScheduleTable() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryNextScheduleTable,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitNextScheduleTable
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function NextScheduleTable() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitNextScheduleTable,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryStartScheduleTableSynchron
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function StartScheduleTableSynchron() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryStartScheduleTableSynchron,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitStartScheduleTableSynchron
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function StartScheduleTableSynchron() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitStartScheduleTableSynchron,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntrySyncScheduleTable
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function SyncScheduleTable() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntrySyncScheduleTable,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitSyncScheduleTable
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function SyncScheduleTable() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitSyncScheduleTable,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntrySetScheduleTableAsync
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function SetScheduleTableAsync() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntrySetScheduleTableAsync,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitSetScheduleTableAsync
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function SetScheduleTableAsync() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitSetScheduleTableAsync,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetScheduleTableStatus
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetScheduleTableStatus() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetScheduleTableStatus,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetScheduleTableStatus
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetScheduleTableStatus() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetScheduleTableStatus,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryIncrementCounter
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function IncrementCounter() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryIncrementCounter,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitIncrementCounter
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function IncrementCounter() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitIncrementCounter,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetCounterValue
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetCounterValue() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetCounterValue,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetCounterValue
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetCounterValue() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetCounterValue,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetElapsedValue
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetElapsedValue() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetElapsedValue,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetElapsedValue
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetElapsedValue() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetElapsedValue,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryTerminateApplication
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function TerminateApplication() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryTerminateApplication,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitTerminateApplication
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function TerminateApplication() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitTerminateApplication,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryAllowAccess
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function AllowAccess() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryAllowAccess,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitAllowAccess
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function AllowAccess() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitAllowAccess,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetApplicationState
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetApplicationState() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetApplicationState,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetApplicationState
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetApplicationState() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetApplicationState,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetNumberOfActivatedCores
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetNumberOfActivatedCores() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetNumberOfActivatedCores,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetNumberOfActivatedCores
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetNumberOfActivatedCores() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetNumberOfActivatedCores,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetCoreID
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetCoreID() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetCoreID,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetCoreID
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetCoreID() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetCoreID,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryStartCore
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function StartCore() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryStartCore,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitStartCore
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function StartCore() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitStartCore,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryStartNonAutosarCore
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function StartNonAutosarCore() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryStartNonAutosarCore,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitStartNonAutosarCore
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function StartNonAutosarCore() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitStartNonAutosarCore,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetSpinlock
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetSpinlock() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetSpinlock,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetSpinlock
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetSpinlock() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetSpinlock,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryReleaseSpinlock
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ReleaseSpinlock() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryReleaseSpinlock,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitReleaseSpinlock
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ReleaseSpinlock() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitReleaseSpinlock,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryTryToGetSpinlock
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function TryToGetSpinlock() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryTryToGetSpinlock,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitTryToGetSpinlock
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function TryToGetSpinlock() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitTryToGetSpinlock,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryShutdownAllCores
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ShutdownAllCores() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryShutdownAllCores,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitShutdownAllCores
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ShutdownAllCores() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitShutdownAllCores,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryControlIdle
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ControlIdle() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryControlIdle,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitControlIdle
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ControlIdle() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitControlIdle,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetCurrentApplicationID
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetCurrentApplicationID() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetCurrentApplicationID,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetCurrentApplicationID
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetCurrentApplicationID() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetCurrentApplicationID,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryCallNonTrustedFunction
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function CallNonTrustedFunction() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryCallNonTrustedFunction,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitCallNonTrustedFunction
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function CallNonTrustedFunction() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitCallNonTrustedFunction,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetTaskStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetTaskStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetTaskStackUsage,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetTaskStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetTaskStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetTaskStackUsage,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetISRStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetISRStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetISRStackUsage,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetISRStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetISRStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetISRStackUsage,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetKernelStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetKernelStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetKernelStackUsage,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetKernelStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetKernelStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetKernelStackUsage,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetStartupHookStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetStartupHookStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetStartupHookStackUsage,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetStartupHookStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetStartupHookStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetStartupHookStackUsage,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetErrorHookStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetErrorHookStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetErrorHookStackUsage,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetErrorHookStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetErrorHookStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetErrorHookStackUsage,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetShutdownHookStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetShutdownHookStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetShutdownHookStackUsage,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetShutdownHookStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetShutdownHookStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetShutdownHookStackUsage,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetProtectionHookStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetProtectionHookStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetProtectionHookStackUsage,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetProtectionHookStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetProtectionHookStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetProtectionHookStackUsage,
(
  void
));



/***********************************************************************************************************************
 * Os_TraceApiEntryStartOS
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function StartOS() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryStartOS,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetActiveApplicationMode
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetActiveApplicationMode() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetActiveApplicationMode,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetActiveApplicationMode
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetActiveApplicationMode() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetActiveApplicationMode,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryDisableAllInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function DisableAllInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryDisableAllInterrupts,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitDisableAllInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function DisableAllInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitDisableAllInterrupts,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryEnableAllInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function EnableAllInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryEnableAllInterrupts,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitEnableAllInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function EnableAllInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitEnableAllInterrupts,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntrySuspendAllInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function SuspendAllInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntrySuspendAllInterrupts,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitSuspendAllInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function SuspendAllInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitSuspendAllInterrupts,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryResumeAllInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ResumeAllInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryResumeAllInterrupts,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitResumeAllInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ResumeAllInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitResumeAllInterrupts,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntrySuspendOSInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function SuspendOSInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntrySuspendOSInterrupts,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitSuspendOSInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function SuspendOSInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitSuspendOSInterrupts,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryResumeOSInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ResumeOSInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryResumeOSInterrupts,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitResumeOSInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ResumeOSInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitResumeOSInterrupts,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryActivateTask
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ActivateTask() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryActivateTask,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitActivateTask
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ActivateTask() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitActivateTask,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryTerminateTask
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function TerminateTask() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryTerminateTask,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitTerminateTask
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function TerminateTask() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitTerminateTask,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryChainTask
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ChainTask() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryChainTask,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitChainTask
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ChainTask() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitChainTask,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetTaskID
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetTaskID() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetTaskID,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetTaskID
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetTaskID() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetTaskID,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetTaskState
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetTaskState() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetTaskState,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetTaskState
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetTaskState() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetTaskState,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntrySchedule
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function Schedule() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntrySchedule,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitSchedule
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function Schedule() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitSchedule,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntrySetEvent
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function SetEvent() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntrySetEvent,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitSetEvent
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function SetEvent() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitSetEvent,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryClearEvent
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ClearEvent() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryClearEvent,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitClearEvent
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ClearEvent() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitClearEvent,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetEvent
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetEvent() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetEvent,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetEvent
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetEvent() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetEvent,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryWaitEvent
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function WaitEvent() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryWaitEvent,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitWaitEvent
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function WaitEvent() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitWaitEvent,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetAlarmBase
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetAlarmBase() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetAlarmBase,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetAlarmBase
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetAlarmBase() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetAlarmBase,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetAlarm
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetAlarm() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetAlarm,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetAlarm
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetAlarm() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetAlarm,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntrySetRelAlarm
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function SetRelAlarm() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntrySetRelAlarm,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitSetRelAlarm
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function SetRelAlarm() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitSetRelAlarm,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntrySetAbsAlarm
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function SetAbsAlarm() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntrySetAbsAlarm,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitSetAbsAlarm
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function SetAbsAlarm() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitSetAbsAlarm,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryCancelAlarm
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function CancelAlarm() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryCancelAlarm,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitCancelAlarm
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function CancelAlarm() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitCancelAlarm,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetResource
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetResource() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetResource,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetResource
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetResource() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetResource,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryReleaseResource
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ReleaseResource() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryReleaseResource,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitReleaseResource
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ReleaseResource() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitReleaseResource,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryEnterPreStartTask
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function EnterPreStartTask() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryEnterPreStartTask,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryShutdownOS
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ShutdownOS() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryShutdownOS,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitShutdownOS
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ShutdownOS() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitShutdownOS,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetUnhandledIrq
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetUnhandledIrq() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetUnhandledIrq,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetUnhandledIrq
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetUnhandledIrq() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetUnhandledIrq,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetUnhandledExc
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetUnhandledExc() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetUnhandledExc,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetUnhandledExc
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetUnhandledExc() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetUnhandledExc,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryDisableOSInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function DisableOSInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryDisableOSInterrupts,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitDisableOSInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function DisableOSInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitDisableOSInterrupts,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryEnableOSInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function EnableOSInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryEnableOSInterrupts,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitEnableOSInterrupts
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function EnableOSInterrupts() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitEnableOSInterrupts,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryReadPeripheral8
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ReadPeripheral8() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryReadPeripheral8,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitReadPeripheral8
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ReadPeripheral8() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitReadPeripheral8,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryReadPeripheral16
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ReadPeripheral16() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryReadPeripheral16,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitReadPeripheral16
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ReadPeripheral16() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitReadPeripheral16,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryReadPeripheral32
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ReadPeripheral32() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryReadPeripheral32,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitReadPeripheral32
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ReadPeripheral32() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitReadPeripheral32,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryWritePeripheral8
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function WritePeripheral8() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryWritePeripheral8,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitWritePeripheral8
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function WritePeripheral8() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitWritePeripheral8,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryWritePeripheral16
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function WritePeripheral16() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryWritePeripheral16,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitWritePeripheral16
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function WritePeripheral16() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitWritePeripheral16,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryWritePeripheral32
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function WritePeripheral32() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryWritePeripheral32,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitWritePeripheral32
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function WritePeripheral32() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitWritePeripheral32,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryModifyPeripheral8
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ModifyPeripheral8() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryModifyPeripheral8,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitModifyPeripheral8
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ModifyPeripheral8() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitModifyPeripheral8,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryModifyPeripheral16
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ModifyPeripheral16() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryModifyPeripheral16,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitModifyPeripheral16
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ModifyPeripheral16() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitModifyPeripheral16,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryModifyPeripheral32
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ModifyPeripheral32() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryModifyPeripheral32,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitModifyPeripheral32
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ModifyPeripheral32() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitModifyPeripheral32,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetDetailedError
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetDetailedError() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetDetailedError,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetDetailedError
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetDetailedError() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetDetailedError,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryOSErrorGetServiceId
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function OSErrorGetServiceId() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryOSErrorGetServiceId,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitOSErrorGetServiceId
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function OSErrorGetServiceId() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitOSErrorGetServiceId,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryDisableInterruptSource
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function DisableInterruptSource() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryDisableInterruptSource,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitDisableInterruptSource
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function DisableInterruptSource() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitDisableInterruptSource,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryEnableInterruptSource
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function EnableInterruptSource() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryEnableInterruptSource,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitEnableInterruptSource
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function EnableInterruptSource() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitEnableInterruptSource,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryClearPendingInterrupt
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function ClearPendingInterrupt() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryClearPendingInterrupt,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitClearPendingInterrupt
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function ClearPendingInterrupt() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitClearPendingInterrupt,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryIsInterruptSourceEnabled
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function IsInterruptSourceEnabled() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryIsInterruptSourceEnabled,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitIsInterruptSourceEnabled
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function IsInterruptSourceEnabled() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitIsInterruptSourceEnabled,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryIsInterruptPending
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function IsInterruptPending() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryIsInterruptPending,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitIsInterruptPending
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function IsInterruptPending() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitIsInterruptPending,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryCallFastTrustedFunction
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function CallFastTrustedFunction() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryCallFastTrustedFunction,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitCallFastTrustedFunction
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function CallFastTrustedFunction() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitCallFastTrustedFunction,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryBarrierSynchronize
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function BarrierSynchronize() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryBarrierSynchronize,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitBarrierSynchronize
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function BarrierSynchronize() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitBarrierSynchronize,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetExceptionContext
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetExceptionContext() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetExceptionContext,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetExceptionContext
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetExceptionContext() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetExceptionContext,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntrySetExceptionContext
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function SetExceptionContext() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntrySetExceptionContext,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitSetExceptionContext
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function SetExceptionContext() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitSetExceptionContext,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryInitialEnableInterruptSources
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function InitialEnableInterruptSources() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryInitialEnableInterruptSources,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitInitialEnableInterruptSources
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function InitialEnableInterruptSources() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitInitialEnableInterruptSources,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetCoreStartState
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetCoreStartState() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetCoreStartState,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetCoreStartState
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetCoreStartState() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetCoreStartState,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetExceptionAddress
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetExceptionAddress() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetExceptionAddress,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetExceptionAddress
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetExceptionAddress() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetExceptionAddress,
(
  void
));


/***********************************************************************************************************************
 * Os_TraceApiEntryGetNonTrustedFunctionStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the entry to the API function GetNonTrustedFunctionStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiEntryGetNonTrustedFunctionStackUsage,
(
  void
));

/***********************************************************************************************************************
 * Os_TraceApiExitGetNonTrustedFunctionStackUsage
 **********************************************************************************************************************/
/*! \brief          Trace the exit from the API function GetNonTrustedFunctionStackUsage() with an ORTI/ARTI debugger
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceApiExitGetNonTrustedFunctionStackUsage,
(
  void
));



/***********************************************************************************************************************
 *  Os_TraceGetNumberOfConfiguredSpinlocks()
 **********************************************************************************************************************/
/*! \brief        Returns the number of configured spinlocks.
 *  \details      --no details--
 *
 *  \return       Number of configured spinlocks.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TraceSpinlockIdType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceGetNumberOfConfiguredSpinlocks, ( void ));

/***********************************************************************************************************************
 * Os_TraceAppStart
 **********************************************************************************************************************/
/*! \brief          Trace OS application start.
 *  \details        Call the ARTI hooks which signal that an OS application has been started.
 *
 *  \param[in]      Appl        The trace object for the OS application.
 *                              Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different Apps.
 *  \synchronous    TRUE
 *
 *  \pre            -
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceAppStart,
(
    P2CONST(Os_TraceAppConfigType, AUTOMATIC, OS_CONST) App
));

/***********************************************************************************************************************
 * Os_TraceAppAllowAccess
 **********************************************************************************************************************/
/*! \brief          Trace OS application allow access.
 *  \details        Call the ARTI hooks which signal that access to an OS application has been allowed.
 *
 *  \param[in]      Appl        The trace object for the OS application.
 *                              Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different Apps.
 *  \synchronous    TRUE
 *
 *  \pre            -
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceAppAllowAccess,
(
    P2CONST(Os_TraceAppConfigType, AUTOMATIC, OS_CONST) App
));

/***********************************************************************************************************************
 * Os_TraceAppKill
 **********************************************************************************************************************/
/*! \brief          Trace OS application killing.
 *  \details        Call the ARTI hooks which signal that an OS application has been killed.
 *
 *  \param[in]      Appl        The trace object for the OS application.
 *                              Parameter must not be NULL if tracing is enabled.
 *  \param[in]      Restarting  Tells the trace module that the application is killed with restart (if set to true).
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different Apps.
 *  \synchronous    TRUE
 *
 *  \pre            -
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceAppKill,
(
    P2CONST(Os_TraceAppConfigType, AUTOMATIC, OS_CONST) App,
    CONST(boolean,AUTOMATIC) Restarting
));

/***********************************************************************************************************************
 * Os_TraceProtHookEntry
 **********************************************************************************************************************/
/*! \brief          Trace entry to ProtectionHook.
 *  \details        Call the ARTI hooks which signal that the ProtectionHook entry is beeing processed.
 *
 *  \param[in]      Status      Reflects the parameter value of the ProtectionHook.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            -
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceProtHookEntry,
(
    CONST(StatusType, AUTOMATIC) Status
));

/***********************************************************************************************************************
 * Os_TraceProtHookExit
 **********************************************************************************************************************/
/*! \brief          Trace exit from ProtectionHook.
 *  \details        Call the ARTI hooks which signal that the ProtectionHook exit is beeing processed.
 *
 *  \param[in]      ProtRet     Reflects the return value of the ProtectionHook after the OS has checked its validity.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            -
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceProtHookExit,
(
    CONST(ProtectionReturnType, AUTOMATIC) ProtRet
));

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_TRACEINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_TraceInt.h
 **********************************************************************************************************************/

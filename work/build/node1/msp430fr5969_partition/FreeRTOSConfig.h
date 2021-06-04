#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configAPPLICATION_ALLOCATED_HEAP        0
#define configSUPPORT_DYNAMIC_ALLOCATION        0
#define configSUPPORT_STATIC_ALLOCATION         1

#define configUSE_PREEMPTION                    1
#define configMAX_PRIORITIES                    ( 5 )
#define configCPU_CLOCK_HZ                      ( 8000000 )
#define configTICK_RATE_HZ                      ( 1000 )

#define configMAX_TASK_NAME_LEN                 ( 2 )
#define configUSE_TRACE_FACILITY                0
#define configUSE_16_BIT_TICKS                  0
#define configIDLE_SHOULD_YIELD                 1
#define configUSE_CO_ROUTINES                   0
#define configUSE_MUTEXES                       1
#define configUSE_RECURSIVE_MUTEXES             0
#define configQUEUE_REGISTRY_SIZE               0
#define configUSE_APPLICATION_TASK_TAG          0
#define configUSE_COUNTING_SEMAPHORES           0
#define configUSE_ALTERNATIVE_API               0
#define configNUMTHREAD_LOCAL_STORAGE_POINTERS  0
#define configENABLE_BACKWARD_COMPATIBILITY     0
#define configUSE_TASK_NOTIFICATIONS            0

/* Hook function related definitions. */
#define configUSE_TICK_HOOK             0
#define configUSE_IDLE_HOOK             0
#define configUSE_MALLOC_FAILED_HOOK    0
#define configCHECK_FOR_STACK_OVERFLOW  2

/* Software timer related definitions. */
#define configUSE_TIMERS                1
#define configTIMER_TASK_PRIORITY       ( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH        1
#define configTIMER_TASK_STACK_DEPTH    ( configMINIMAL_STACK_SIZE )

/* Event group related definitions. */
#define configUSE_EVENT_GROUPS          0

/* Run time stats gathering definitions. */
#define configGENERATE_RUN_TIME_STATS   0

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES           0

#define INCLUDE_vTaskPrioritySet                0
#define INCLUDE_uxTaskPriorityGet               0
#define INCLUDE_vTaskDelete                     0
#define INCLUDE_vTaskSuspend                    0
#define INCLUDE_xResumeFromISR                  0
#define INCLUDE_vTaskDelayUntil                 0
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_xTaskGetSchedulerState          0
#define INCLUDE_xTaskGetCurrentTaskHandle       0
#define INCLUDE_uxTaskGetStackHighWaterMark     0
#define INCLUDE_xTaskGetIdleTaskHandle          0
#define INCLUDE_eTaskGetState                   0
#define INCLUDE_xEventGroupSetBitFromISR        0
#define INCLUDE_xTimerPendFunctionCall          0
#define INCLUDE_xTaskAbortDelay                 0
#define INCLUDE_xTaskGetHandle                  0
#define INCLUDE_xTaskResumeFromISR              0

#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

#define configTICK_VECTOR               TIMER0_A0_VECTOR

#ifdef __LARGE_DATA_MODEL__
        #define configMINIMAL_STACK_SIZE        ( ( unsigned short ) 85 )
#else
        #define configMINIMAL_STACK_SIZE        ( ( unsigned short ) 140 )
#endif

#endif /* FREERTOS_CONFIG_H */

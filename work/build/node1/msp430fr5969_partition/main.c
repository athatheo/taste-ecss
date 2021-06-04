/* File generated by kazoo for TASTE - do not edit */
#include <msp430.h>

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "msp430fr5969_partition_interface.h"
#include "transport.h"


#include "thread_st05eventreport_eventactiontc05.h"
#include "thread_st05eventreport_tc05.h"
#include "thread_st08functionmanagement_eventactiontc08.h"
#include "thread_st08functionmanagement_tc08.h"
#include "thread_st11timebasedscheduling_eventactiontc11.h"
#include "thread_st11timebasedscheduling_tc11.h"
#include "thread_st19eventaction_tc19.h"
#include "thread_st20parameterservice_eventactiontc20.h"
#include "thread_st20parameterservice_tc20.h"
#include "thread_tc_handler_tc.h"

extern void init_st05eventreport(void);
extern void init_st08functionmanagement(void);
extern void init_st11timebasedscheduling(void);
extern void init_st19eventaction(void);
extern void init_st20parameterservice(void);
extern void init_tc_handler(void);

// function to setup hardware
static void prvSetupHardware()
{
    // stop watchdog timer
    WDTCTL = WDTPW | WDTHOLD;

    PM5CTL0 &= ~LOCKLPM5;

    // Unlock clock registers
    CSCTL0_H = CSKEY >> 8;

    // Set DCO to 8MHz
    CSCTL1 = DCOFSEL_3 | DCORSEL;

    // select LFXTCLK for ACLK
    // select DCO for SMCLK
    // select DCO for MCLK
    CSCTL2 = SELA__LFXTCLK | SELS__DCOCLK | SELM__DCOCLK;

    // Set all dividers
    CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1;

    // Lock clock registers
    CSCTL0_H = 0;

    // initialize devices
}

// stack overflow handler
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    (void) pcTaskName;
    (void) pxTask;

    /* Run time stack overflow checking is performed if
     configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
     function is called if a stack overflow is detected.
     See http://www.freertos.org/Stacks-and-stack-overflow-checking.html */

    /* Force an assert. */
    configASSERT(( volatile void * ) NULL);
}

// MSP-430 timers setup
void vApplicationSetupTimerInterrupt(void)
{
    const unsigned short usACLK_Frequency_Hz = 32768;

    /* Ensure the timer is stopped. */
    TA0CTL = 0;

    /* Run the timer from the ACLK. */
    TA0CTL = TASSEL_1;

    /* Clear everything to start with. */
    TA0CTL |= TACLR;

    /* Set the compare match value according to the tick rate we want. */
    TA0CCR0 = usACLK_Frequency_Hz / configTICK_RATE_HZ;

    /* Enable the interrupts. */
    TA0CCTL0 = CCIE;

    /* Start up clean. */
    TA0CTL |= TACLR;

    /* Up mode. */
    TA0CTL |= MC_1;
}

__attribute__ ((persistent)) StaticTask_t xIdleTaskTCB = {0};
__attribute__ ((persistent)) StackType_t xIdleTaskStack[configMINIMAL_STACK_SIZE] = {0};

void vApplicationGetIdleTaskMemory(StaticTask_t** ppxIdleTaskPCBBuffer,
                                   StackType_t** ppxIdleTaskStackBuffer,
                                   uint32_t* pulIdleTaskStackSize)
{

    *ppxIdleTaskPCBBuffer = &xIdleTaskTCB;
    *ppxIdleTaskStackBuffer = xIdleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

__attribute__ ((persistent)) StaticTask_t xTimerTaskTCB = {0};
__attribute__ ((persistent)) StackType_t xTimerTaskStack[configMINIMAL_STACK_SIZE] = {0};

void vApplicationGetTimerTaskMemory(StaticTask_t** ppxTimerTaskPCBBuffer,
                                   StackType_t** ppxTimerTaskStackBuffer,
                                   uint32_t* pulTimerTaskStackSize)
{

    *ppxTimerTaskPCBBuffer = &xTimerTaskTCB;
    *ppxTimerTaskStackBuffer = xTimerTaskStack;
    *pulTimerTaskStackSize = configMINIMAL_STACK_SIZE;
}

__attribute__ ((persistent)) SemaphoreHandle_t st05eventreport_Semaphore = {0};
__attribute__ ((persistent)) StaticSemaphore_t prv_st05eventreport_Semaphore_Buffer = {0};
__attribute__ ((persistent)) SemaphoreHandle_t st08functionmanagement_Semaphore = {0};
__attribute__ ((persistent)) StaticSemaphore_t prv_st08functionmanagement_Semaphore_Buffer = {0};
__attribute__ ((persistent)) SemaphoreHandle_t st11timebasedscheduling_Semaphore = {0};
__attribute__ ((persistent)) StaticSemaphore_t prv_st11timebasedscheduling_Semaphore_Buffer = {0};
__attribute__ ((persistent)) SemaphoreHandle_t st19eventaction_Semaphore = {0};
__attribute__ ((persistent)) StaticSemaphore_t prv_st19eventaction_Semaphore_Buffer = {0};
__attribute__ ((persistent)) SemaphoreHandle_t st20parameterservice_Semaphore = {0};
__attribute__ ((persistent)) StaticSemaphore_t prv_st20parameterservice_Semaphore_Buffer = {0};
__attribute__ ((persistent)) SemaphoreHandle_t tc_handler_Semaphore = {0};
__attribute__ ((persistent)) StaticSemaphore_t prv_tc_handler_Semaphore_Buffer = {0};



__attribute__ ((persistent)) QueueHandle_t st05eventreport_EventActionTC05_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_st05eventreport_eventactiontc05_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_st05eventreport_eventactiontc05_Queue_Buffer[ 4 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_st05eventreport_eventactiontc05_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_st05eventreport_eventactiontc05_Stack[50000 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_st05eventreport_eventactiontc05()
{
    st05eventreport_EventActionTC05_Global_Queue = xQueueCreateStatic( 4,
                                                      sizeof(struct Request),
                                                      prv_st05eventreport_eventactiontc05_Queue_Buffer,
                                                      &prv_st05eventreport_eventactiontc05_Static_Queue);

    xTaskCreateStatic(prv_st05eventreport_EventActionTC05_Task,
                "st05eventreport_EventActionTC05",
                50000 / sizeof(StackType_t),
                NULL,
                1,
                prv_st05eventreport_eventactiontc05_Stack,
                &prv_st05eventreport_eventactiontc05_TCB);
}

__attribute__ ((persistent)) QueueHandle_t st05eventreport_TC05_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_st05eventreport_tc05_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_st05eventreport_tc05_Queue_Buffer[ 3 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_st05eventreport_tc05_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_st05eventreport_tc05_Stack[50000 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_st05eventreport_tc05()
{
    st05eventreport_TC05_Global_Queue = xQueueCreateStatic( 3,
                                                      sizeof(struct Request),
                                                      prv_st05eventreport_tc05_Queue_Buffer,
                                                      &prv_st05eventreport_tc05_Static_Queue);

    xTaskCreateStatic(prv_st05eventreport_TC05_Task,
                "st05eventreport_TC05",
                50000 / sizeof(StackType_t),
                NULL,
                2,
                prv_st05eventreport_tc05_Stack,
                &prv_st05eventreport_tc05_TCB);
}

__attribute__ ((persistent)) QueueHandle_t st08functionmanagement_EventActionTC08_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_st08functionmanagement_eventactiontc08_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_st08functionmanagement_eventactiontc08_Queue_Buffer[ 4 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_st08functionmanagement_eventactiontc08_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_st08functionmanagement_eventactiontc08_Stack[50000 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_st08functionmanagement_eventactiontc08()
{
    st08functionmanagement_EventActionTC08_Global_Queue = xQueueCreateStatic( 4,
                                                      sizeof(struct Request),
                                                      prv_st08functionmanagement_eventactiontc08_Queue_Buffer,
                                                      &prv_st08functionmanagement_eventactiontc08_Static_Queue);

    xTaskCreateStatic(prv_st08functionmanagement_EventActionTC08_Task,
                "st08functionmanagement_EventActionTC08",
                50000 / sizeof(StackType_t),
                NULL,
                3,
                prv_st08functionmanagement_eventactiontc08_Stack,
                &prv_st08functionmanagement_eventactiontc08_TCB);
}

__attribute__ ((persistent)) QueueHandle_t st08functionmanagement_TC08_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_st08functionmanagement_tc08_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_st08functionmanagement_tc08_Queue_Buffer[ 3 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_st08functionmanagement_tc08_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_st08functionmanagement_tc08_Stack[50000 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_st08functionmanagement_tc08()
{
    st08functionmanagement_TC08_Global_Queue = xQueueCreateStatic( 3,
                                                      sizeof(struct Request),
                                                      prv_st08functionmanagement_tc08_Queue_Buffer,
                                                      &prv_st08functionmanagement_tc08_Static_Queue);

    xTaskCreateStatic(prv_st08functionmanagement_TC08_Task,
                "st08functionmanagement_TC08",
                50000 / sizeof(StackType_t),
                NULL,
                4,
                prv_st08functionmanagement_tc08_Stack,
                &prv_st08functionmanagement_tc08_TCB);
}

__attribute__ ((persistent)) QueueHandle_t st11timebasedscheduling_EventActionTC11_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_st11timebasedscheduling_eventactiontc11_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_st11timebasedscheduling_eventactiontc11_Queue_Buffer[ 5 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_st11timebasedscheduling_eventactiontc11_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_st11timebasedscheduling_eventactiontc11_Stack[50000 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_st11timebasedscheduling_eventactiontc11()
{
    st11timebasedscheduling_EventActionTC11_Global_Queue = xQueueCreateStatic( 5,
                                                      sizeof(struct Request),
                                                      prv_st11timebasedscheduling_eventactiontc11_Queue_Buffer,
                                                      &prv_st11timebasedscheduling_eventactiontc11_Static_Queue);

    xTaskCreateStatic(prv_st11timebasedscheduling_EventActionTC11_Task,
                "st11timebasedscheduling_EventActionTC11",
                50000 / sizeof(StackType_t),
                NULL,
                4,
                prv_st11timebasedscheduling_eventactiontc11_Stack,
                &prv_st11timebasedscheduling_eventactiontc11_TCB);
}

__attribute__ ((persistent)) QueueHandle_t st11timebasedscheduling_TC11_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_st11timebasedscheduling_tc11_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_st11timebasedscheduling_tc11_Queue_Buffer[ 1 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_st11timebasedscheduling_tc11_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_st11timebasedscheduling_tc11_Stack[50000 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_st11timebasedscheduling_tc11()
{
    st11timebasedscheduling_TC11_Global_Queue = xQueueCreateStatic( 1,
                                                      sizeof(struct Request),
                                                      prv_st11timebasedscheduling_tc11_Queue_Buffer,
                                                      &prv_st11timebasedscheduling_tc11_Static_Queue);

    xTaskCreateStatic(prv_st11timebasedscheduling_TC11_Task,
                "st11timebasedscheduling_TC11",
                50000 / sizeof(StackType_t),
                NULL,
                4,
                prv_st11timebasedscheduling_tc11_Stack,
                &prv_st11timebasedscheduling_tc11_TCB);
}

__attribute__ ((persistent)) QueueHandle_t st19eventaction_TC19_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_st19eventaction_tc19_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_st19eventaction_tc19_Queue_Buffer[ 3 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_st19eventaction_tc19_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_st19eventaction_tc19_Stack[50000 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_st19eventaction_tc19()
{
    st19eventaction_TC19_Global_Queue = xQueueCreateStatic( 3,
                                                      sizeof(struct Request),
                                                      prv_st19eventaction_tc19_Queue_Buffer,
                                                      &prv_st19eventaction_tc19_Static_Queue);

    xTaskCreateStatic(prv_st19eventaction_TC19_Task,
                "st19eventaction_TC19",
                50000 / sizeof(StackType_t),
                NULL,
                4,
                prv_st19eventaction_tc19_Stack,
                &prv_st19eventaction_tc19_TCB);
}

__attribute__ ((persistent)) QueueHandle_t st20parameterservice_EventActionTC20_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_st20parameterservice_eventactiontc20_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_st20parameterservice_eventactiontc20_Queue_Buffer[ 4 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_st20parameterservice_eventactiontc20_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_st20parameterservice_eventactiontc20_Stack[50000 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_st20parameterservice_eventactiontc20()
{
    st20parameterservice_EventActionTC20_Global_Queue = xQueueCreateStatic( 4,
                                                      sizeof(struct Request),
                                                      prv_st20parameterservice_eventactiontc20_Queue_Buffer,
                                                      &prv_st20parameterservice_eventactiontc20_Static_Queue);

    xTaskCreateStatic(prv_st20parameterservice_EventActionTC20_Task,
                "st20parameterservice_EventActionTC20",
                50000 / sizeof(StackType_t),
                NULL,
                4,
                prv_st20parameterservice_eventactiontc20_Stack,
                &prv_st20parameterservice_eventactiontc20_TCB);
}

__attribute__ ((persistent)) QueueHandle_t st20parameterservice_TC20_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_st20parameterservice_tc20_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_st20parameterservice_tc20_Queue_Buffer[ 5 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_st20parameterservice_tc20_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_st20parameterservice_tc20_Stack[50000 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_st20parameterservice_tc20()
{
    st20parameterservice_TC20_Global_Queue = xQueueCreateStatic( 5,
                                                      sizeof(struct Request),
                                                      prv_st20parameterservice_tc20_Queue_Buffer,
                                                      &prv_st20parameterservice_tc20_Static_Queue);

    xTaskCreateStatic(prv_st20parameterservice_TC20_Task,
                "st20parameterservice_TC20",
                50000 / sizeof(StackType_t),
                NULL,
                4,
                prv_st20parameterservice_tc20_Stack,
                &prv_st20parameterservice_tc20_TCB);
}

__attribute__ ((persistent)) QueueHandle_t tc_handler_tc_Global_Queue = NULL;
__attribute__ ((persistent)) static StaticQueue_t prv_tc_handler_tc_Static_Queue = {0};
__attribute__ ((persistent)) static uint8_t prv_tc_handler_tc_Queue_Buffer[ 1 * sizeof(struct Request)] = {0};

__attribute__ ((persistent)) static StaticTask_t prv_tc_handler_tc_TCB = {0};
__attribute__ ((persistent)) static StackType_t prv_tc_handler_tc_Stack[50000 / sizeof(StackType_t)] = {0};

static void Initialize_Thread_tc_handler_tc()
{
    tc_handler_tc_Global_Queue = xQueueCreateStatic( 1,
                                                      sizeof(struct Request),
                                                      prv_tc_handler_tc_Queue_Buffer,
                                                      &prv_tc_handler_tc_Static_Queue);

    xTaskCreateStatic(prv_tc_handler_tc_Task,
                "tc_handler_tc",
                50000 / sizeof(StackType_t),
                NULL,
                4,
                prv_tc_handler_tc_Stack,
                &prv_tc_handler_tc_TCB);
}

// the main function
int main(void)
{
    prvSetupHardware();

    st05eventreport_Semaphore = xSemaphoreCreateMutexStatic(&prv_st05eventreport_Semaphore_Buffer);
    init_st05eventreport();
    st08functionmanagement_Semaphore = xSemaphoreCreateMutexStatic(&prv_st08functionmanagement_Semaphore_Buffer);
    init_st08functionmanagement();
    st11timebasedscheduling_Semaphore = xSemaphoreCreateMutexStatic(&prv_st11timebasedscheduling_Semaphore_Buffer);
    init_st11timebasedscheduling();
    st19eventaction_Semaphore = xSemaphoreCreateMutexStatic(&prv_st19eventaction_Semaphore_Buffer);
    init_st19eventaction();
    st20parameterservice_Semaphore = xSemaphoreCreateMutexStatic(&prv_st20parameterservice_Semaphore_Buffer);
    init_st20parameterservice();
    tc_handler_Semaphore = xSemaphoreCreateMutexStatic(&prv_tc_handler_Semaphore_Buffer);
    init_tc_handler();

    Initialize_Thread_st05eventreport_eventactiontc05();
    Initialize_Thread_st05eventreport_tc05();
    Initialize_Thread_st08functionmanagement_eventactiontc08();
    Initialize_Thread_st08functionmanagement_tc08();
    Initialize_Thread_st11timebasedscheduling_eventactiontc11();
    Initialize_Thread_st11timebasedscheduling_tc11();
    Initialize_Thread_st19eventaction_tc19();
    Initialize_Thread_st20parameterservice_eventactiontc20();
    Initialize_Thread_st20parameterservice_tc20();
    Initialize_Thread_tc_handler_tc();

    vTaskStartScheduler();

    for(;;);
}


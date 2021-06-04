#include "thread_tc_handler_tc.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "transport.h"
#include "msp430fr5969_partition_interface.h"

extern QueueHandle_t tc_handler_tc_Global_Queue;

void prv_tc_handler_tc_Timer_Callback(TimerHandle_t timer)
{
    struct Request request;
    request.m_length = 0;
    xQueueSend(tc_handler_tc_Global_Queue, &request, 0);
}

__attribute__ ((persistent)) StaticTimer_t prv_tc_handler_tc_Timer_Buffer = {0};
__attribute__ ((persistent)) TimerHandle_t prv_tc_handler_tc_Timer = {0};

void prv_tc_handler_tc_Task(void* prParameters)
{
    extern QueueHandle_t tc_handler_tc_Global_Queue;
    TickType_t period = pdMS_TO_TICKS( 150);
    prv_tc_handler_tc_Timer = xTimerCreateStatic("tc_handler_tc_Timer",
                                                         period,
                                                         pdTRUE,
                                                         NULL,
                                                         &prv_tc_handler_tc_Timer_Callback,
                                                         &prv_tc_handler_tc_Timer_Buffer);
    xTimerStart(prv_tc_handler_tc_Timer, portMAX_DELAY);

    while(1)
    {
        struct Request request;
        BaseType_t result = xQueueReceive(tc_handler_tc_Global_Queue, &request, portMAX_DELAY);
        if(result == pdTRUE)
        {
            call_tc_handler_tc((const char*)request.m_data, request.m_length);
        }
    }
}

#include "thread_st05eventreport_tc05.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "transport.h"
#include "msp430fr5969_partition_interface.h"

extern QueueHandle_t st05eventreport_TC05_Global_Queue;

void prv_st05eventreport_TC05_Task(void* prParameters)
{
    extern QueueHandle_t st05eventreport_TC05_Global_Queue;

    while(1)
    {
        struct Request request;
        BaseType_t result = xQueueReceive(st05eventreport_TC05_Global_Queue, &request, portMAX_DELAY);
        if(result == pdTRUE)
        {
            call_st05eventreport_tc05((const char*)request.m_data, request.m_length);
        }
    }
}

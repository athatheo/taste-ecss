#include "thread_st19eventaction_tc19.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "transport.h"
#include "msp430fr5969_partition_interface.h"

extern QueueHandle_t st19eventaction_TC19_Global_Queue;

void prv_st19eventaction_TC19_Task(void* prParameters)
{
    extern QueueHandle_t st19eventaction_TC19_Global_Queue;

    while(1)
    {
        struct Request request;
        BaseType_t result = xQueueReceive(st19eventaction_TC19_Global_Queue, &request, portMAX_DELAY);
        if(result == pdTRUE)
        {
            call_st19eventaction_tc19((const char*)request.m_data, request.m_length);
        }
    }
}

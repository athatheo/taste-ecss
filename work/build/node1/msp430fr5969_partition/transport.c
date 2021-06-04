#include "transport.h"

#include <msp430.h>
#include <string.h>

// use header genrated by ocarina for port identyfication
#include <deployment.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"



void deliver_to_st05eventreport_EventActionTC05(struct Request* task)
{
    extern QueueHandle_t st05eventreport_EventActionTC05_Global_Queue;
	xQueueSend(st05eventreport_EventActionTC05_Global_Queue,
	           task,
			   0);

}
void deliver_to_st05eventreport_TC05(struct Request* task)
{
    extern QueueHandle_t st05eventreport_TC05_Global_Queue;
	xQueueSend(st05eventreport_TC05_Global_Queue,
	           task,
			   0);

}
void deliver_to_st08functionmanagement_EventActionTC08(struct Request* task)
{
    extern QueueHandle_t st08functionmanagement_EventActionTC08_Global_Queue;
	xQueueSend(st08functionmanagement_EventActionTC08_Global_Queue,
	           task,
			   0);

}
void deliver_to_st08functionmanagement_TC08(struct Request* task)
{
    extern QueueHandle_t st08functionmanagement_TC08_Global_Queue;
	xQueueSend(st08functionmanagement_TC08_Global_Queue,
	           task,
			   0);

}
void deliver_to_st11timebasedscheduling_EventActionTC11(struct Request* task)
{
    extern QueueHandle_t st11timebasedscheduling_EventActionTC11_Global_Queue;
	xQueueSend(st11timebasedscheduling_EventActionTC11_Global_Queue,
	           task,
			   0);

}
void deliver_to_st11timebasedscheduling_TC11(struct Request* task)
{
    extern QueueHandle_t st11timebasedscheduling_TC11_Global_Queue;
	xQueueSend(st11timebasedscheduling_TC11_Global_Queue,
	           task,
			   0);

}
void deliver_to_st19eventaction_TC19(struct Request* task)
{
    extern QueueHandle_t st19eventaction_TC19_Global_Queue;
	xQueueSend(st19eventaction_TC19_Global_Queue,
	           task,
			   0);

}
void deliver_to_st20parameterservice_EventActionTC20(struct Request* task)
{
    extern QueueHandle_t st20parameterservice_EventActionTC20_Global_Queue;
	xQueueSend(st20parameterservice_EventActionTC20_Global_Queue,
	           task,
			   0);

}
void deliver_to_st20parameterservice_TC20(struct Request* task)
{
    extern QueueHandle_t st20parameterservice_TC20_Global_Queue;
	xQueueSend(st20parameterservice_TC20_Global_Queue,
	           task,
			   0);

}
void deliver_to_tc_handler_tc(struct Request* task)
{
    extern QueueHandle_t tc_handler_tc_Global_Queue;
	xQueueSend(tc_handler_tc_Global_Queue,
	           task,
			   0);

}


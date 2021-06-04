#ifndef TRANSPORT_H_INCLUDED
#define TRANSPORT_H_INCLUDED

#include <stdint.h>

#include "dataview-uniq.h"

// struct used to calculate request size
struct MSPAllParameters
{
    union
    {
        // for all provided sporadic and cyclic interfaces
        
        char ST05EventReport_EventActionTC05_message[sizeof (asn1SccMessage)];

        char ST05EventReport_TC05_message[sizeof (asn1SccMessage)];

        char ST08FunctionManagement_EventActionTC08_message[sizeof (asn1SccMessage)];

        char ST08FunctionManagement_TC08_message[sizeof (asn1SccMessage)];

        char ST11TimeBasedScheduling_EventActionTC11_message[sizeof (asn1SccMessage)];

        char ST11TimeBasedScheduling_TC11_message[sizeof (asn1SccMessage)];

        char ST19EventAction_TC19_message[sizeof (asn1SccMessage)];

        char ST20ParameterService_EventActionTC20_message[sizeof (asn1SccMessage)];

        char ST20ParameterService_TC20_message[sizeof (asn1SccMessage)];



        // for all required sporadic interfaces
        




        char ST19EventAction_EventActionTC05_message[sizeof (asn1SccMessage)];

        char ST19EventAction_EventActionTC08_message[sizeof (asn1SccMessage)];

        char ST19EventAction_EventActionTC11_message[sizeof (asn1SccMessage)];

        char ST19EventAction_EventActionTC20_message[sizeof (asn1SccMessage)];



        char tc_handler_TC05_message[sizeof (asn1SccMessage)];

        char tc_handler_TC08_message[sizeof (asn1SccMessage)];

        char tc_handler_TC11_message[sizeof (asn1SccMessage)];

        char tc_handler_TC19_message[sizeof (asn1SccMessage)];

        char tc_handler_TC20_message[sizeof (asn1SccMessage)];

        char dummy_union_field;
    } all_types;
};

// MSP430_BUFFER_SIZE should be even number
#define MSP430_BUFFER_SIZE (((sizeof(struct MSPAllParameters) + 1) / 2) * 2)

struct Request
{
	uint32_t m_length;
    uint8_t m_data[MSP430_BUFFER_SIZE];

};


void deliver_to_st05eventreport_EventActionTC05(struct Request* task);
void deliver_to_st05eventreport_TC05(struct Request* task);
void deliver_to_st08functionmanagement_EventActionTC08(struct Request* task);
void deliver_to_st08functionmanagement_TC08(struct Request* task);
void deliver_to_st11timebasedscheduling_EventActionTC11(struct Request* task);
void deliver_to_st11timebasedscheduling_TC11(struct Request* task);
void deliver_to_st19eventaction_TC19(struct Request* task);
void deliver_to_st20parameterservice_EventActionTC20(struct Request* task);
void deliver_to_st20parameterservice_TC20(struct Request* task);
void deliver_to_tc_handler_tc(struct Request* task);

#endif

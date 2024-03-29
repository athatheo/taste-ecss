#ifndef __OCARINA_GENERATED_REQUEST_H_
#define __OCARINA_GENERATED_REQUEST_H_ 
#include <types.h>
#include <deployment.h>
/*****************************************************/

/*  This file was automatically generated by Ocarina */

/*  Working Copy from r4095871d*/

/*  Do NOT hand-modify this file, as your            */

/*  changes will be lost when you re-run Ocarina     */

/*****************************************************/

/*  Enumeration type for all the operations in the distributed application.*/

typedef struct
{
  __po_hi_port_t port;

  union
  {
    struct
    {
      dataview__message_buffer_impl st05eventreport_eventactiontc05_global_inport_eventactiontc05;

    } st05eventreport_eventactiontc05_global_inport_eventactiontc05;

    struct
    {
      dataview__message_buffer_impl st05eventreport_tc05_global_inport_tc05;

    } st05eventreport_tc05_global_inport_tc05;

    struct
    {
      dataview__message_buffer_impl st08functionmanagement_eventactiontc08_global_inport_eventactiontc08;

    } st08functionmanagement_eventactiontc08_global_inport_eventactiontc08;

    struct
    {
      dataview__message_buffer_impl st08functionmanagement_tc08_global_inport_tc08;

    } st08functionmanagement_tc08_global_inport_tc08;

    struct
    {
      dataview__message_buffer_impl st11timebasedscheduling_eventactiontc11_global_inport_eventactiontc11;

    } st11timebasedscheduling_eventactiontc11_global_inport_eventactiontc11;

    struct
    {
      dataview__message_buffer_impl st11timebasedscheduling_tc11_global_inport_tc11;

    } st11timebasedscheduling_tc11_global_inport_tc11;

    struct
    {
      dataview__message_buffer_impl st19eventaction_tc19_global_inport_tc19;

    } st19eventaction_tc19_global_inport_tc19;

    struct
    {
      dataview__message_buffer_impl st19eventaction_tc19_global_outport_st05eventreport_eventactiontc05;

    } st19eventaction_tc19_global_outport_st05eventreport_eventactiontc05;

    struct
    {
      dataview__message_buffer_impl st19eventaction_tc19_global_outport_st08functionmanagement_eventactiontc08;

    } st19eventaction_tc19_global_outport_st08functionmanagement_eventactiontc08;

    struct
    {
      dataview__message_buffer_impl st19eventaction_tc19_global_outport_st11timebasedscheduling_eventactiontc11;

    } st19eventaction_tc19_global_outport_st11timebasedscheduling_eventactiontc11;

    struct
    {
      dataview__message_buffer_impl st19eventaction_tc19_global_outport_st20parameterservice_eventactiontc20;

    } st19eventaction_tc19_global_outport_st20parameterservice_eventactiontc20;

    struct
    {
      dataview__message_buffer_impl st20parameterservice_eventactiontc20_global_inport_eventactiontc20;

    } st20parameterservice_eventactiontc20_global_inport_eventactiontc20;

    struct
    {
      dataview__message_buffer_impl st20parameterservice_tc20_global_inport_tc20;

    } st20parameterservice_tc20_global_inport_tc20;

    struct
    {
      dataview__message_buffer_impl tc_handler_tc_global_outport_st05eventreport_tc05;

    } tc_handler_tc_global_outport_st05eventreport_tc05;

    struct
    {
      dataview__message_buffer_impl tc_handler_tc_global_outport_st08functionmanagement_tc08;

    } tc_handler_tc_global_outport_st08functionmanagement_tc08;

    struct
    {
      dataview__message_buffer_impl tc_handler_tc_global_outport_st11timebasedscheduling_tc11;

    } tc_handler_tc_global_outport_st11timebasedscheduling_tc11;

    struct
    {
      dataview__message_buffer_impl tc_handler_tc_global_outport_st19eventaction_tc19;

    } tc_handler_tc_global_outport_st19eventaction_tc19;

    struct
    {
      dataview__message_buffer_impl tc_handler_tc_global_outport_st20parameterservice_tc20;

    } tc_handler_tc_global_outport_st20parameterservice_tc20;

  } vars;

} __po_hi_request_t;

#define __PO_HI_NB_OPERATIONS 0

#endif

/* Header file for function ST20ParameterService in CPP language
 * Generated by TASTE on 2021-06-03 18:45:33
 * Context Parameters present : NO
 * Provided interfaces : EventActionTC20, TC20
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 151502 117062 190680 129859
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

/* The purpose of this file is to provide a wrapper around the user code,
 * with a single interface that is independent of the implementation language
 * of the function. The parameters of each PI are blackboxes encoded
 * in the form specified in the interface view (Native, uPER, or ACN)
*/

#pragma once
#if defined(__unix__) || defined (__MSP430__)
   #include <stdlib.h>
   #include <stdio.h>
#else
   typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "st20parameterservice.h"

// Function initialization - calls user startup code of all dependent functions
void init_st20parameterservice(void);


/* Provided interfaces */
void st20parameterservice_EventActionTC20
      (const char *IN_message, size_t IN_message_len);

void st20parameterservice_TC20
      (const char *IN_message, size_t IN_message_len);


#ifdef __cplusplus
}
#endif


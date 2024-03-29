/* Header file for function tc_handler in CPP language
 * Generated by TASTE on 2021-06-03 18:45:34
 * Context Parameters present : NO
 * Provided interfaces : tc
 * Required interfaces : TC05, TC08, TC11, TC19, TC20
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 82735 50536 117490 72180
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

#include "tc_handler.h"

// Function initialization - calls user startup code of all dependent functions
void init_tc_handler(void);


/* Provided interfaces */
void tc_handler_tc(void);


#ifdef __cplusplus
}
#endif


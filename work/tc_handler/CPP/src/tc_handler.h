
/* Header file for function tc_handler in CPP language
 * Generated by TASTE on 2021-06-03 18:45:33
 * Context Parameters present : NO
 * Provided interfaces : tc
 * Required interfaces : TC05, TC08, TC11, TC19, TC20
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 82735 50536 117490 72180
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __unix__
   #include <stdlib.h>
   #include <stdio.h>
#endif

void tc_handler_startup(void);

/* Provided interfaces */
void tc_handler_PI_tc( );

/* Required interfaces */
extern void tc_handler_RI_TC05( const asn1SccMessage * );
extern void tc_handler_RI_TC08( const asn1SccMessage * );
extern void tc_handler_RI_TC11( const asn1SccMessage * );
extern void tc_handler_RI_TC19( const asn1SccMessage * );
extern void tc_handler_RI_TC20( const asn1SccMessage * );


#ifdef __cplusplus
}
#endif

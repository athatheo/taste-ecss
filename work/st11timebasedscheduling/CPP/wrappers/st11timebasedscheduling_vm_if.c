/* Body file for function ST11TimeBasedScheduling
 * Generated by TASTE on 2021-06-03 18:45:33
 * Provided interfaces : EventActionTC11, TC11
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 151502 84993 191312 98105
 * Timers              : 
 */
#include "st11timebasedscheduling_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned st11timebasedscheduling_initialized = 0;
void init_st11timebasedscheduling(void)
{
   if (0 == st11timebasedscheduling_initialized) {
      st11timebasedscheduling_initialized = 1;
      // Call user code startup function
      extern void st11timebasedscheduling_startup(void);
      st11timebasedscheduling_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function ST11TimeBasedScheduling");
#endif
      st11timebasedscheduling_initialized = 2;
   }
}
void st11timebasedscheduling_EventActionTC11
      (const char *IN_message, size_t IN_message_len)

{

   static asn1SccMessage IN_MESSAGE;
#ifdef __unix__
   asn1SccMessage_Initialize(&IN_MESSAGE);
#endif
   if (0 != Decode_NATIVE_Message (&IN_MESSAGE, (void *)IN_message, IN_message_len)) {
      #ifdef __unix__
         puts("Error decoding Message in function ST11TimeBasedScheduling_EventActionTC11");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void st11timebasedscheduling_PI_EventActionTC11
      (const asn1SccMessage *);




   // Call user code
   st11timebasedscheduling_PI_EventActionTC11 (&IN_MESSAGE);

}
void st11timebasedscheduling_TC11
      (const char *IN_message, size_t IN_message_len)

{

   static asn1SccMessage IN_MESSAGE;
#ifdef __unix__
   asn1SccMessage_Initialize(&IN_MESSAGE);
#endif
   if (0 != Decode_NATIVE_Message (&IN_MESSAGE, (void *)IN_message, IN_message_len)) {
      #ifdef __unix__
         puts("Error decoding Message in function ST11TimeBasedScheduling_TC11");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void st11timebasedscheduling_PI_TC11
      (const asn1SccMessage *);




   // Call user code
   st11timebasedscheduling_PI_TC11 (&IN_MESSAGE);

}


/* Body file for function ST08FunctionManagement
 * Generated by TASTE on 2021-06-03 18:45:33
 * Provided interfaces : EventActionTC08, TC08
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 151344 68405 191312 81201
 * Timers              : 
 */
#include "st08functionmanagement_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned st08functionmanagement_initialized = 0;
void init_st08functionmanagement(void)
{
   if (0 == st08functionmanagement_initialized) {
      st08functionmanagement_initialized = 1;
      // Call user code startup function
      extern void st08functionmanagement_startup(void);
      st08functionmanagement_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function ST08FunctionManagement");
#endif
      st08functionmanagement_initialized = 2;
   }
}
void st08functionmanagement_EventActionTC08
      (const char *IN_message, size_t IN_message_len)

{

   static asn1SccMessage IN_MESSAGE;
#ifdef __unix__
   asn1SccMessage_Initialize(&IN_MESSAGE);
#endif
   if (0 != Decode_NATIVE_Message (&IN_MESSAGE, (void *)IN_message, IN_message_len)) {
      #ifdef __unix__
         puts("Error decoding Message in function ST08FunctionManagement_EventActionTC08");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void st08functionmanagement_PI_EventActionTC08
      (const asn1SccMessage *);




   // Call user code
   st08functionmanagement_PI_EventActionTC08 (&IN_MESSAGE);

}
void st08functionmanagement_TC08
      (const char *IN_message, size_t IN_message_len)

{

   static asn1SccMessage IN_MESSAGE;
#ifdef __unix__
   asn1SccMessage_Initialize(&IN_MESSAGE);
#endif
   if (0 != Decode_NATIVE_Message (&IN_MESSAGE, (void *)IN_message, IN_message_len)) {
      #ifdef __unix__
         puts("Error decoding Message in function ST08FunctionManagement_TC08");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void st08functionmanagement_PI_TC08
      (const asn1SccMessage *);




   // Call user code
   st08functionmanagement_PI_TC08 (&IN_MESSAGE);

}


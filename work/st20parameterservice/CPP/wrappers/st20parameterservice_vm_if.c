/* Body file for function ST20ParameterService
 * Generated by TASTE on 2021-06-03 18:45:33
 * Provided interfaces : EventActionTC20, TC20
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 151502 117062 190680 129859
 * Timers              : 
 */
#include "st20parameterservice_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned st20parameterservice_initialized = 0;
void init_st20parameterservice(void)
{
   if (0 == st20parameterservice_initialized) {
      st20parameterservice_initialized = 1;
      // Call user code startup function
      extern void st20parameterservice_startup(void);
      st20parameterservice_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function ST20ParameterService");
#endif
      st20parameterservice_initialized = 2;
   }
}
void st20parameterservice_EventActionTC20
      (const char *IN_message, size_t IN_message_len)

{

   static asn1SccMessage IN_MESSAGE;
#ifdef __unix__
   asn1SccMessage_Initialize(&IN_MESSAGE);
#endif
   if (0 != Decode_NATIVE_Message (&IN_MESSAGE, (void *)IN_message, IN_message_len)) {
      #ifdef __unix__
         puts("Error decoding Message in function ST20ParameterService_EventActionTC20");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void st20parameterservice_PI_EventActionTC20
      (const asn1SccMessage *);




   // Call user code
   st20parameterservice_PI_EventActionTC20 (&IN_MESSAGE);

}
void st20parameterservice_TC20
      (const char *IN_message, size_t IN_message_len)

{

   static asn1SccMessage IN_MESSAGE;
#ifdef __unix__
   asn1SccMessage_Initialize(&IN_MESSAGE);
#endif
   if (0 != Decode_NATIVE_Message (&IN_MESSAGE, (void *)IN_message, IN_message_len)) {
      #ifdef __unix__
         puts("Error decoding Message in function ST20ParameterService_TC20");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void st20parameterservice_PI_TC20
      (const asn1SccMessage *);




   // Call user code
   st20parameterservice_PI_TC20 (&IN_MESSAGE);

}

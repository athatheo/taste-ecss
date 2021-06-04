// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned st19eventaction_initialized;

void st19eventaction_RI_EventActionTC05
      (const asn1SccMessage *IN_message);
void st19eventaction_RI_EventActionTC05
      (const asn1SccMessage *IN_message)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1Message ("INNERDATA: eventactiontc05::Message::message", IN_message);
         puts(""); // add newline
         // Log message to ST05EventReport (corresponding PI: EventActionTC05)
         printf ("INNER: st19eventaction,st05eventreport,eventactiontc05,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter message
   static asn1SccMessage IN_buf_message;
   int size_IN_buf_message =
      Encode_NATIVE_Message
        ((void *)&IN_buf_message,
          sizeof(asn1SccMessage),
          (asn1SccMessage *)IN_message);
   if (-1 == size_IN_buf_message) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in st19eventaction_RI_EventActionTC05, parameter message");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_st19eventaction_eventactiontc05
     (void *, size_t);

   vm_st19eventaction_eventactiontc05
     ((void *)&IN_buf_message, (size_t)size_IN_buf_message);


}
void st19eventaction_RI_EventActionTC08
      (const asn1SccMessage *IN_message);
void st19eventaction_RI_EventActionTC08
      (const asn1SccMessage *IN_message)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1Message ("INNERDATA: eventactiontc08::Message::message", IN_message);
         puts(""); // add newline
         // Log message to ST08FunctionManagement (corresponding PI: EventActionTC08)
         printf ("INNER: st19eventaction,st08functionmanagement,eventactiontc08,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter message
   static asn1SccMessage IN_buf_message;
   int size_IN_buf_message =
      Encode_NATIVE_Message
        ((void *)&IN_buf_message,
          sizeof(asn1SccMessage),
          (asn1SccMessage *)IN_message);
   if (-1 == size_IN_buf_message) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in st19eventaction_RI_EventActionTC08, parameter message");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_st19eventaction_eventactiontc08
     (void *, size_t);

   vm_st19eventaction_eventactiontc08
     ((void *)&IN_buf_message, (size_t)size_IN_buf_message);


}
void st19eventaction_RI_EventActionTC11
      (const asn1SccMessage *IN_message);
void st19eventaction_RI_EventActionTC11
      (const asn1SccMessage *IN_message)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1Message ("INNERDATA: eventactiontc11::Message::message", IN_message);
         puts(""); // add newline
         // Log message to ST11TimeBasedScheduling (corresponding PI: EventActionTC11)
         printf ("INNER: st19eventaction,st11timebasedscheduling,eventactiontc11,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter message
   static asn1SccMessage IN_buf_message;
   int size_IN_buf_message =
      Encode_NATIVE_Message
        ((void *)&IN_buf_message,
          sizeof(asn1SccMessage),
          (asn1SccMessage *)IN_message);
   if (-1 == size_IN_buf_message) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in st19eventaction_RI_EventActionTC11, parameter message");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_st19eventaction_eventactiontc11
     (void *, size_t);

   vm_st19eventaction_eventactiontc11
     ((void *)&IN_buf_message, (size_t)size_IN_buf_message);


}
void st19eventaction_RI_EventActionTC20
      (const asn1SccMessage *IN_message);
void st19eventaction_RI_EventActionTC20
      (const asn1SccMessage *IN_message)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1Message ("INNERDATA: eventactiontc20::Message::message", IN_message);
         puts(""); // add newline
         // Log message to ST20ParameterService (corresponding PI: EventActionTC20)
         printf ("INNER: st19eventaction,st20parameterservice,eventactiontc20,%lld\n", msc_time);
         fflush(stdout);
      }
   #endif
   // Encode parameter message
   static asn1SccMessage IN_buf_message;
   int size_IN_buf_message =
      Encode_NATIVE_Message
        ((void *)&IN_buf_message,
          sizeof(asn1SccMessage),
          (asn1SccMessage *)IN_message);
   if (-1 == size_IN_buf_message) {
      #ifdef __unix__
         puts ("[ERROR] ASN.1 Encoding failed in st19eventaction_RI_EventActionTC20, parameter message");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_st19eventaction_eventactiontc20
     (void *, size_t);

   vm_st19eventaction_eventactiontc20
     ((void *)&IN_buf_message, (size_t)size_IN_buf_message);


}


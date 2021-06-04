// Implementation of the glue code in C handling required interfaces

#include <stdlib.h>
#ifdef __unix__
   #include <stdio.h>
   #include "PrintTypesAsASN1.h"
   #include "timeInMS.h"
#endif
#include "C_ASN1_Types.h"
#include "dataview-uniq.h"

extern unsigned tc_handler_initialized;

void tc_handler_RI_TC05
      (const asn1SccMessage *IN_message);
void tc_handler_RI_TC05
      (const asn1SccMessage *IN_message)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1Message ("INNERDATA: tc05::Message::message", IN_message);
         puts(""); // add newline
         // Log message to ST05EventReport (corresponding PI: TC05)
         printf ("INNER: tc_handler,st05eventreport,tc05,%lld\n", msc_time);
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
         puts ("[ERROR] ASN.1 Encoding failed in tc_handler_RI_TC05, parameter message");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_tc_handler_tc05
     (void *, size_t);

   vm_tc_handler_tc05
     ((void *)&IN_buf_message, (size_t)size_IN_buf_message);


}
void tc_handler_RI_TC08
      (const asn1SccMessage *IN_message);
void tc_handler_RI_TC08
      (const asn1SccMessage *IN_message)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1Message ("INNERDATA: tc08::Message::message", IN_message);
         puts(""); // add newline
         // Log message to ST08FunctionManagement (corresponding PI: TC08)
         printf ("INNER: tc_handler,st08functionmanagement,tc08,%lld\n", msc_time);
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
         puts ("[ERROR] ASN.1 Encoding failed in tc_handler_RI_TC08, parameter message");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_tc_handler_tc08
     (void *, size_t);

   vm_tc_handler_tc08
     ((void *)&IN_buf_message, (size_t)size_IN_buf_message);


}
void tc_handler_RI_TC11
      (const asn1SccMessage *IN_message);
void tc_handler_RI_TC11
      (const asn1SccMessage *IN_message)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1Message ("INNERDATA: tc11::Message::message", IN_message);
         puts(""); // add newline
         // Log message to ST11TimeBasedScheduling (corresponding PI: TC11)
         printf ("INNER: tc_handler,st11timebasedscheduling,tc11,%lld\n", msc_time);
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
         puts ("[ERROR] ASN.1 Encoding failed in tc_handler_RI_TC11, parameter message");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_tc_handler_tc11
     (void *, size_t);

   vm_tc_handler_tc11
     ((void *)&IN_buf_message, (size_t)size_IN_buf_message);


}
void tc_handler_RI_TC19
      (const asn1SccMessage *IN_message);
void tc_handler_RI_TC19
      (const asn1SccMessage *IN_message)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1Message ("INNERDATA: tc19::Message::message", IN_message);
         puts(""); // add newline
         // Log message to ST19EventAction (corresponding PI: TC19)
         printf ("INNER: tc_handler,st19eventaction,tc19,%lld\n", msc_time);
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
         puts ("[ERROR] ASN.1 Encoding failed in tc_handler_RI_TC19, parameter message");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_tc_handler_tc19
     (void *, size_t);

   vm_tc_handler_tc19
     ((void *)&IN_buf_message, (size_t)size_IN_buf_message);


}
void tc_handler_RI_TC20
      (const asn1SccMessage *IN_message);
void tc_handler_RI_TC20
      (const asn1SccMessage *IN_message)
{
   #ifdef __unix__
      // Log MSC data on Linux when environment variable is set
      static int innerMsc = -1;
      if (-1 == innerMsc)
         innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
      if (1 == innerMsc) {
         long long msc_time = getTimeInMilliseconds();
         PrintASN1Message ("INNERDATA: tc20::Message::message", IN_message);
         puts(""); // add newline
         // Log message to ST20ParameterService (corresponding PI: TC20)
         printf ("INNER: tc_handler,st20parameterservice,tc20,%lld\n", msc_time);
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
         puts ("[ERROR] ASN.1 Encoding failed in tc_handler_RI_TC20, parameter message");
      #endif
        /* Crash the application due to message loss */
        abort();
   }


   // Call Middleware interface
   extern void vm_tc_handler_tc20
     (void *, size_t);

   vm_tc_handler_tc20
     ((void *)&IN_buf_message, (size_t)size_IN_buf_message);


}


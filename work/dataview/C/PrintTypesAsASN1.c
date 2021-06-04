#ifdef __unix__
#include <stdio.h>
#endif

#include "PrintTypesAsASN1.h"

#ifdef __linux__
#include <pthread.h>

static pthread_mutex_t g_printing_mutex = PTHREAD_MUTEX_INITIALIZER;

#endif

void PrintASN1MyInteger(const char *paramName, const asn1SccMyInteger *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s MyInteger ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1UInt8(const char *paramName, const asn1SccUInt8 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s UInt8 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1UInt16(const char *paramName, const asn1SccUInt16 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s UInt16 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1Packet(const char *paramName, const asn1SccPacket *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s Packet ::= ", paramName);
    printf("%s ", paramName);
    {
        int i1;
        printf("{");
        for(i1=0; i1<100; i1++) {
            if (i1) 
                printf(",");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).arr[i1]);
            #else
            printf("%d", (*pData).arr[i1]);
            #endif
        }
        printf("}");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1Message(const char *paramName, const asn1SccMessage *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s Message ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("packetType ");
    switch((*pData).packetType) {
    case 0:
        printf("tm");
        break;
    case 1:
        printf("tc");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData).packetType)");
    }
    printf(", ");
    printf("serviceType ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).serviceType);
    #else
    printf("%d", (*pData).serviceType);
    #endif
    printf(", ");
    printf("messageType ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).messageType);
    #else
    printf("%d", (*pData).messageType);
    #endif
    printf(", ");
    printf("applicationId ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).applicationId);
    #else
    printf("%d", (*pData).applicationId);
    #endif
    printf(", ");
    printf("messageTypeCounter ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).messageTypeCounter);
    #else
    printf("%d", (*pData).messageTypeCounter);
    #endif
    printf(", ");
    printf("packetSequenceCount ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).packetSequenceCount);
    #else
    printf("%d", (*pData).packetSequenceCount);
    #endif
    printf(", ");
    printf("dataSize ");
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData).dataSize);
    #else
    printf("%d", (*pData).dataSize);
    #endif
    printf(", ");
    printf("data ");
    {
        int i2;
        printf("{");
        for(i2=0; i2<1024; i2++) {
            if (i2) 
                printf(",");
            #if WORD_SIZE==8
            printf("%"PRId64, (*pData).data.arr[i2]);
            #else
            printf("%d", (*pData).data.arr[i2]);
            #endif
        }
        printf("}");
    }
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1EventOccured(const char *paramName, const asn1SccEventOccured *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s EventOccured ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("informativeUnknownEvent");
        break;
    case 1:
        printf("wwdgReset");
        break;
    case 2:
        printf("assertionFail");
        break;
    case 3:
        printf("mCUStart");
        break;
    case 4:
        printf("lowSeverityUnknownEvent");
        break;
    case 5:
        printf("mediumSeverityUnknownEvent");
        break;
    case 6:
        printf("highSeverityUnknownEvent");
        break;
    case 7:
        printf("failedStartOfExecution");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1AcceptanceErrorOccured(const char *paramName, const asn1SccAcceptanceErrorOccured *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s AcceptanceErrorOccured ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("unknownAcceptanceError");
        break;
    case 1:
        printf("messageTooShort");
        break;
    case 2:
        printf("tooManyBitsRead");
        break;
    case 4:
        printf("stringTooShort");
        break;
    case 5:
        printf("unacceptableMessage");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1RoutingErrorType(const char *paramName, const asn1SccRoutingErrorType *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s RoutingErrorType ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("unknownRoutingError");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1ExecutionStartErrorType(const char *paramName, const asn1SccExecutionStartErrorType *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s ExecutionStartErrorType ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("unknownExecutionStartError");
        break;
    case 1:
        printf("eventActionDefinitionIDExistsError");
        break;
    case 2:
        printf("eventActionDeleteEnabledDefinitionError");
        break;
    case 3:
        printf("eventActionUnknownEventDefinitionError");
        break;
    case 4:
        printf("eventActionUnknownEventActionDefinitionIDError");
        break;
    case 5:
        printf("subServiceExecutionStartError");
        break;
    case 6:
        printf("instructionExecutionStartError");
        break;
    case 7:
        printf("setNonExistingParameter");
        break;
    case 8:
        printf("getNonExistingParameter");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1ExecutionProgressErrorType(const char *paramName, const asn1SccExecutionProgressErrorType *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s ExecutionProgressErrorType ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("unknownExecutionProgressError");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1ExecutionCompletionErrorType(const char *paramName, const asn1SccExecutionCompletionErrorType *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s ExecutionCompletionErrorType ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("unknownExecutionCompletionError");
        break;
    case 1:
        printf("checksumFailed");
        break;
    case 2:
        printf("addressOutOfRange");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Int32(const char *paramName, const asn1SccT_Int32 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Int32 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_UInt32(const char *paramName, const asn1SccT_UInt32 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-UInt32 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Int8(const char *paramName, const asn1SccT_Int8 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Int8 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_UInt8(const char *paramName, const asn1SccT_UInt8 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-UInt8 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Boolean(const char *paramName, const asn1SccT_Boolean *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Boolean ::= ", paramName);
    printf("%s ", paramName);
    printf("%s", (int)(*pData)?"TRUE":"FALSE");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Null_Record(const char *paramName, const asn1SccT_Null_Record *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Null-Record ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}


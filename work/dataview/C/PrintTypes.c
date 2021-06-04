#ifdef __unix__
#include <stdio.h>
#endif
#include "PrintTypes.h"

#ifdef __linux__
#include <pthread.h>

static pthread_mutex_t g_printing_mutex = PTHREAD_MUTEX_INITIALIZER;

#endif

void PrintMyInteger(const char *paramName, const asn1SccMyInteger *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintUInt8(const char *paramName, const asn1SccUInt8 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintUInt16(const char *paramName, const asn1SccUInt16 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintPacket(const char *paramName, const asn1SccPacket *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    {
        int i1;
        for(i1=0; i1<100; i1++) {
            #if WORD_SIZE==8
            printf("%s::Elem %"PRId64"\n", paramName, (*pData).arr[i1]);
            #else
            printf("%s::Elem %d\n", paramName, (*pData).arr[i1]);
            #endif
        }
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintMessage(const char *paramName, const asn1SccMessage *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s::packetType %d\n", paramName, (int)(*pData).packetType);
    #if WORD_SIZE==8
    printf("%s::serviceType %"PRId64"\n", paramName, (*pData).serviceType);
    #else
    printf("%s::serviceType %d\n", paramName, (*pData).serviceType);
    #endif
    #if WORD_SIZE==8
    printf("%s::messageType %"PRId64"\n", paramName, (*pData).messageType);
    #else
    printf("%s::messageType %d\n", paramName, (*pData).messageType);
    #endif
    #if WORD_SIZE==8
    printf("%s::applicationId %"PRId64"\n", paramName, (*pData).applicationId);
    #else
    printf("%s::applicationId %d\n", paramName, (*pData).applicationId);
    #endif
    #if WORD_SIZE==8
    printf("%s::messageTypeCounter %"PRId64"\n", paramName, (*pData).messageTypeCounter);
    #else
    printf("%s::messageTypeCounter %d\n", paramName, (*pData).messageTypeCounter);
    #endif
    #if WORD_SIZE==8
    printf("%s::packetSequenceCount %"PRId64"\n", paramName, (*pData).packetSequenceCount);
    #else
    printf("%s::packetSequenceCount %d\n", paramName, (*pData).packetSequenceCount);
    #endif
    #if WORD_SIZE==8
    printf("%s::dataSize %"PRId64"\n", paramName, (*pData).dataSize);
    #else
    printf("%s::dataSize %d\n", paramName, (*pData).dataSize);
    #endif
    {
        int i2;
        for(i2=0; i2<1024; i2++) {
            #if WORD_SIZE==8
            printf("%s::data::Elem %"PRId64"\n", paramName, (*pData).data.arr[i2]);
            #else
            printf("%s::data::Elem %d\n", paramName, (*pData).data.arr[i2]);
            #endif
        }
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintEventOccured(const char *paramName, const asn1SccEventOccured *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %d\n", paramName, (int)(*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintAcceptanceErrorOccured(const char *paramName, const asn1SccAcceptanceErrorOccured *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %d\n", paramName, (int)(*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintRoutingErrorType(const char *paramName, const asn1SccRoutingErrorType *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %d\n", paramName, (int)(*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintExecutionStartErrorType(const char *paramName, const asn1SccExecutionStartErrorType *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %d\n", paramName, (int)(*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintExecutionProgressErrorType(const char *paramName, const asn1SccExecutionProgressErrorType *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %d\n", paramName, (int)(*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintExecutionCompletionErrorType(const char *paramName, const asn1SccExecutionCompletionErrorType *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %d\n", paramName, (int)(*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Int32(const char *paramName, const asn1SccT_Int32 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_UInt32(const char *paramName, const asn1SccT_UInt32 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Int8(const char *paramName, const asn1SccT_Int8 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_UInt8(const char *paramName, const asn1SccT_UInt8 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    #if WORD_SIZE==8
    printf("%s %"PRId64"\n", paramName, (*pData));
    #else
    printf("%s %d\n", paramName, (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Boolean(const char *paramName, const asn1SccT_Boolean *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    printf("%s %d\n", paramName, (int)(*pData));
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintT_Null_Record(const char *paramName, const asn1SccT_Null_Record *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__

#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}


#ifdef __unix__
#include <stdio.h>
#include <assert.h>
#endif

#include <string.h>

#include "C_ASN1_Types.h"

#ifdef __NEED_MyInteger_UPER
int Encode_UPER_MyInteger(void *pBuffer, size_t iMaxBufferSize, const asn1SccMyInteger *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMyInteger_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode MyInteger (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_MyInteger_ACN
int Encode_ACN_MyInteger(void *pBuffer, size_t iMaxBufferSize, asn1SccMyInteger *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMyInteger_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode MyInteger (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_MyInteger_NATIVE
int Encode_NATIVE_MyInteger(void *pBuffer, size_t iMaxBufferSize, const asn1SccMyInteger *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccMyInteger) );
    return sizeof(asn1SccMyInteger);
}
#endif

#ifdef __NEED_MyInteger_UPER
int Decode_UPER_MyInteger(asn1SccMyInteger *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMyInteger_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode MyInteger (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_MyInteger_ACN
int Decode_ACN_MyInteger(asn1SccMyInteger *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMyInteger_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode MyInteger (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_MyInteger_NATIVE
int Decode_NATIVE_MyInteger(asn1SccMyInteger *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccMyInteger *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_UInt8_UPER
int Encode_UPER_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccUInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccUInt8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_UInt8_ACN
int Encode_ACN_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccUInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccUInt8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_UInt8_NATIVE
int Encode_NATIVE_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccUInt8 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccUInt8) );
    return sizeof(asn1SccUInt8);
}
#endif

#ifdef __NEED_UInt8_UPER
int Decode_UPER_UInt8(asn1SccUInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccUInt8_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_UInt8_ACN
int Decode_ACN_UInt8(asn1SccUInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccUInt8_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_UInt8_NATIVE
int Decode_NATIVE_UInt8(asn1SccUInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccUInt8 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_UInt16_UPER
int Encode_UPER_UInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccUInt16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccUInt16_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode UInt16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_UInt16_ACN
int Encode_ACN_UInt16(void *pBuffer, size_t iMaxBufferSize, asn1SccUInt16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccUInt16_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode UInt16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_UInt16_NATIVE
int Encode_NATIVE_UInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccUInt16 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccUInt16) );
    return sizeof(asn1SccUInt16);
}
#endif

#ifdef __NEED_UInt16_UPER
int Decode_UPER_UInt16(asn1SccUInt16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccUInt16_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode UInt16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_UInt16_ACN
int Decode_ACN_UInt16(asn1SccUInt16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccUInt16_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode UInt16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_UInt16_NATIVE
int Decode_NATIVE_UInt16(asn1SccUInt16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccUInt16 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Packet_UPER
int Encode_UPER_Packet(void *pBuffer, size_t iMaxBufferSize, const asn1SccPacket *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPacket_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Packet (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Packet_ACN
int Encode_ACN_Packet(void *pBuffer, size_t iMaxBufferSize, asn1SccPacket *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPacket_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Packet (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Packet_NATIVE
int Encode_NATIVE_Packet(void *pBuffer, size_t iMaxBufferSize, const asn1SccPacket *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPacket) );
    return sizeof(asn1SccPacket);
}
#endif

#ifdef __NEED_Packet_UPER
int Decode_UPER_Packet(asn1SccPacket *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPacket_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Packet (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Packet_ACN
int Decode_ACN_Packet(asn1SccPacket *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPacket_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Packet (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Packet_NATIVE
int Decode_NATIVE_Packet(asn1SccPacket *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPacket *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Message_UPER
int Encode_UPER_Message(void *pBuffer, size_t iMaxBufferSize, const asn1SccMessage *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMessage_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Message (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Message_ACN
int Encode_ACN_Message(void *pBuffer, size_t iMaxBufferSize, asn1SccMessage *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMessage_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Message (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Message_NATIVE
int Encode_NATIVE_Message(void *pBuffer, size_t iMaxBufferSize, const asn1SccMessage *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccMessage) );
    return sizeof(asn1SccMessage);
}
#endif

#ifdef __NEED_Message_UPER
int Decode_UPER_Message(asn1SccMessage *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMessage_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Message (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Message_ACN
int Decode_ACN_Message(asn1SccMessage *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMessage_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Message (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Message_NATIVE
int Decode_NATIVE_Message(asn1SccMessage *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccMessage *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_EventOccured_UPER
int Encode_UPER_EventOccured(void *pBuffer, size_t iMaxBufferSize, const asn1SccEventOccured *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccEventOccured_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode EventOccured (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_EventOccured_ACN
int Encode_ACN_EventOccured(void *pBuffer, size_t iMaxBufferSize, asn1SccEventOccured *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccEventOccured_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode EventOccured (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_EventOccured_NATIVE
int Encode_NATIVE_EventOccured(void *pBuffer, size_t iMaxBufferSize, const asn1SccEventOccured *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccEventOccured) );
    return sizeof(asn1SccEventOccured);
}
#endif

#ifdef __NEED_EventOccured_UPER
int Decode_UPER_EventOccured(asn1SccEventOccured *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccEventOccured_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode EventOccured (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_EventOccured_ACN
int Decode_ACN_EventOccured(asn1SccEventOccured *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccEventOccured_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode EventOccured (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_EventOccured_NATIVE
int Decode_NATIVE_EventOccured(asn1SccEventOccured *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccEventOccured *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_AcceptanceErrorOccured_UPER
int Encode_UPER_AcceptanceErrorOccured(void *pBuffer, size_t iMaxBufferSize, const asn1SccAcceptanceErrorOccured *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAcceptanceErrorOccured_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AcceptanceErrorOccured (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AcceptanceErrorOccured_ACN
int Encode_ACN_AcceptanceErrorOccured(void *pBuffer, size_t iMaxBufferSize, asn1SccAcceptanceErrorOccured *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAcceptanceErrorOccured_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AcceptanceErrorOccured (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AcceptanceErrorOccured_NATIVE
int Encode_NATIVE_AcceptanceErrorOccured(void *pBuffer, size_t iMaxBufferSize, const asn1SccAcceptanceErrorOccured *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAcceptanceErrorOccured) );
    return sizeof(asn1SccAcceptanceErrorOccured);
}
#endif

#ifdef __NEED_AcceptanceErrorOccured_UPER
int Decode_UPER_AcceptanceErrorOccured(asn1SccAcceptanceErrorOccured *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAcceptanceErrorOccured_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AcceptanceErrorOccured (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AcceptanceErrorOccured_ACN
int Decode_ACN_AcceptanceErrorOccured(asn1SccAcceptanceErrorOccured *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAcceptanceErrorOccured_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AcceptanceErrorOccured (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AcceptanceErrorOccured_NATIVE
int Decode_NATIVE_AcceptanceErrorOccured(asn1SccAcceptanceErrorOccured *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAcceptanceErrorOccured *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_RoutingErrorType_UPER
int Encode_UPER_RoutingErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccRoutingErrorType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccRoutingErrorType_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode RoutingErrorType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_RoutingErrorType_ACN
int Encode_ACN_RoutingErrorType(void *pBuffer, size_t iMaxBufferSize, asn1SccRoutingErrorType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccRoutingErrorType_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode RoutingErrorType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_RoutingErrorType_NATIVE
int Encode_NATIVE_RoutingErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccRoutingErrorType *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccRoutingErrorType) );
    return sizeof(asn1SccRoutingErrorType);
}
#endif

#ifdef __NEED_RoutingErrorType_UPER
int Decode_UPER_RoutingErrorType(asn1SccRoutingErrorType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccRoutingErrorType_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode RoutingErrorType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_RoutingErrorType_ACN
int Decode_ACN_RoutingErrorType(asn1SccRoutingErrorType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccRoutingErrorType_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode RoutingErrorType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_RoutingErrorType_NATIVE
int Decode_NATIVE_RoutingErrorType(asn1SccRoutingErrorType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccRoutingErrorType *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_ExecutionStartErrorType_UPER
int Encode_UPER_ExecutionStartErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccExecutionStartErrorType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccExecutionStartErrorType_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode ExecutionStartErrorType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_ExecutionStartErrorType_ACN
int Encode_ACN_ExecutionStartErrorType(void *pBuffer, size_t iMaxBufferSize, asn1SccExecutionStartErrorType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccExecutionStartErrorType_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode ExecutionStartErrorType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_ExecutionStartErrorType_NATIVE
int Encode_NATIVE_ExecutionStartErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccExecutionStartErrorType *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccExecutionStartErrorType) );
    return sizeof(asn1SccExecutionStartErrorType);
}
#endif

#ifdef __NEED_ExecutionStartErrorType_UPER
int Decode_UPER_ExecutionStartErrorType(asn1SccExecutionStartErrorType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccExecutionStartErrorType_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode ExecutionStartErrorType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_ExecutionStartErrorType_ACN
int Decode_ACN_ExecutionStartErrorType(asn1SccExecutionStartErrorType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccExecutionStartErrorType_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode ExecutionStartErrorType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_ExecutionStartErrorType_NATIVE
int Decode_NATIVE_ExecutionStartErrorType(asn1SccExecutionStartErrorType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccExecutionStartErrorType *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_ExecutionProgressErrorType_UPER
int Encode_UPER_ExecutionProgressErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccExecutionProgressErrorType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccExecutionProgressErrorType_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode ExecutionProgressErrorType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_ExecutionProgressErrorType_ACN
int Encode_ACN_ExecutionProgressErrorType(void *pBuffer, size_t iMaxBufferSize, asn1SccExecutionProgressErrorType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccExecutionProgressErrorType_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode ExecutionProgressErrorType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_ExecutionProgressErrorType_NATIVE
int Encode_NATIVE_ExecutionProgressErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccExecutionProgressErrorType *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccExecutionProgressErrorType) );
    return sizeof(asn1SccExecutionProgressErrorType);
}
#endif

#ifdef __NEED_ExecutionProgressErrorType_UPER
int Decode_UPER_ExecutionProgressErrorType(asn1SccExecutionProgressErrorType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccExecutionProgressErrorType_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode ExecutionProgressErrorType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_ExecutionProgressErrorType_ACN
int Decode_ACN_ExecutionProgressErrorType(asn1SccExecutionProgressErrorType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccExecutionProgressErrorType_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode ExecutionProgressErrorType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_ExecutionProgressErrorType_NATIVE
int Decode_NATIVE_ExecutionProgressErrorType(asn1SccExecutionProgressErrorType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccExecutionProgressErrorType *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_ExecutionCompletionErrorType_UPER
int Encode_UPER_ExecutionCompletionErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccExecutionCompletionErrorType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccExecutionCompletionErrorType_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode ExecutionCompletionErrorType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_ExecutionCompletionErrorType_ACN
int Encode_ACN_ExecutionCompletionErrorType(void *pBuffer, size_t iMaxBufferSize, asn1SccExecutionCompletionErrorType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccExecutionCompletionErrorType_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode ExecutionCompletionErrorType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_ExecutionCompletionErrorType_NATIVE
int Encode_NATIVE_ExecutionCompletionErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccExecutionCompletionErrorType *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccExecutionCompletionErrorType) );
    return sizeof(asn1SccExecutionCompletionErrorType);
}
#endif

#ifdef __NEED_ExecutionCompletionErrorType_UPER
int Decode_UPER_ExecutionCompletionErrorType(asn1SccExecutionCompletionErrorType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccExecutionCompletionErrorType_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode ExecutionCompletionErrorType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_ExecutionCompletionErrorType_ACN
int Decode_ACN_ExecutionCompletionErrorType(asn1SccExecutionCompletionErrorType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccExecutionCompletionErrorType_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode ExecutionCompletionErrorType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_ExecutionCompletionErrorType_NATIVE
int Decode_NATIVE_ExecutionCompletionErrorType(asn1SccExecutionCompletionErrorType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccExecutionCompletionErrorType *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Int32_UPER
int Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int32_ACN
int Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int32_NATIVE
int Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int32) );
    return sizeof(asn1SccT_Int32);
}
#endif

#ifdef __NEED_T_Int32_UPER
int Decode_UPER_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int32_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int32_ACN
int Decode_ACN_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int32_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int32_NATIVE
int Decode_NATIVE_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int32 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt32_UPER
int Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt32_ACN
int Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt32) );
    return sizeof(asn1SccT_UInt32);
}
#endif

#ifdef __NEED_T_UInt32_UPER
int Decode_UPER_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt32_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt32_ACN
int Decode_ACN_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt32_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Decode_NATIVE_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt32 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Int8_UPER
int Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int8_ACN
int Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int8_NATIVE
int Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int8) );
    return sizeof(asn1SccT_Int8);
}
#endif

#ifdef __NEED_T_Int8_UPER
int Decode_UPER_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int8_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int8_ACN
int Decode_ACN_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int8_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int8_NATIVE
int Decode_NATIVE_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int8 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt8_UPER
int Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt8_ACN
int Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt8) );
    return sizeof(asn1SccT_UInt8);
}
#endif

#ifdef __NEED_T_UInt8_UPER
int Decode_UPER_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt8_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt8_ACN
int Decode_ACN_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt8_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Decode_NATIVE_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt8 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Boolean_UPER
int Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Boolean_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Boolean_ACN
int Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Boolean_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Boolean) );
    return sizeof(asn1SccT_Boolean);
}
#endif

#ifdef __NEED_T_Boolean_UPER
int Decode_UPER_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Boolean_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Boolean_ACN
int Decode_ACN_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Boolean_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Decode_NATIVE_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Boolean *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Null_Record_UPER
int Encode_UPER_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Null_Record_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Null-Record (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Null_Record_ACN
int Encode_ACN_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Null_Record *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Null_Record_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Null-Record (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Encode_NATIVE_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Null_Record) );
    return sizeof(asn1SccT_Null_Record);
}
#endif

#ifdef __NEED_T_Null_Record_UPER
int Decode_UPER_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Null_Record_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Null-Record (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Null_Record_ACN
int Decode_ACN_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Null_Record_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Null-Record (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Decode_NATIVE_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Null_Record *) pBuffer;
    {
        return 0;
    }
}
#endif


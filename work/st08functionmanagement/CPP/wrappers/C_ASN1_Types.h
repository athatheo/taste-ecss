#ifndef __C_DATAVIEW_UNIQ_H__
#define __C_DATAVIEW_UNIQ_H__

#if defined( __unix__ ) || defined( __MSP430__ )
#include <stdlib.h> /* for size_t */
#else
typedef unsigned size_t;
#endif

#ifndef STATIC
#define STATIC
#endif


#include "dataview-uniq.h" // Space certified compiler generated

#include "../../system_config.h" // Choose ASN.1 Types to use

#ifdef __NEED_MyInteger_UPER
int Encode_UPER_MyInteger(void *pBuffer, size_t iMaxBufferSize, const asn1SccMyInteger *pSrc);
#endif

#ifdef __NEED_MyInteger_ACN
int Encode_ACN_MyInteger(void *pBuffer, size_t iMaxBufferSize, asn1SccMyInteger *pSrc);
#endif

#ifdef __NEED_MyInteger_NATIVE
int Encode_NATIVE_MyInteger(void *pBuffer, size_t iMaxBufferSize, const asn1SccMyInteger *pSrc);
#endif

#ifdef __NEED_MyInteger_UPER
int Decode_UPER_MyInteger(asn1SccMyInteger *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MyInteger_ACN
int Decode_ACN_MyInteger(asn1SccMyInteger *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MyInteger_NATIVE
int Decode_NATIVE_MyInteger(asn1SccMyInteger *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_UInt8_UPER
int Encode_UPER_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccUInt8 *pSrc);
#endif

#ifdef __NEED_UInt8_ACN
int Encode_ACN_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccUInt8 *pSrc);
#endif

#ifdef __NEED_UInt8_NATIVE
int Encode_NATIVE_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccUInt8 *pSrc);
#endif

#ifdef __NEED_UInt8_UPER
int Decode_UPER_UInt8(asn1SccUInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_UInt8_ACN
int Decode_ACN_UInt8(asn1SccUInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_UInt8_NATIVE
int Decode_NATIVE_UInt8(asn1SccUInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_UInt16_UPER
int Encode_UPER_UInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccUInt16 *pSrc);
#endif

#ifdef __NEED_UInt16_ACN
int Encode_ACN_UInt16(void *pBuffer, size_t iMaxBufferSize, asn1SccUInt16 *pSrc);
#endif

#ifdef __NEED_UInt16_NATIVE
int Encode_NATIVE_UInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccUInt16 *pSrc);
#endif

#ifdef __NEED_UInt16_UPER
int Decode_UPER_UInt16(asn1SccUInt16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_UInt16_ACN
int Decode_ACN_UInt16(asn1SccUInt16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_UInt16_NATIVE
int Decode_NATIVE_UInt16(asn1SccUInt16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Packet_UPER
int Encode_UPER_Packet(void *pBuffer, size_t iMaxBufferSize, const asn1SccPacket *pSrc);
#endif

#ifdef __NEED_Packet_ACN
int Encode_ACN_Packet(void *pBuffer, size_t iMaxBufferSize, asn1SccPacket *pSrc);
#endif

#ifdef __NEED_Packet_NATIVE
int Encode_NATIVE_Packet(void *pBuffer, size_t iMaxBufferSize, const asn1SccPacket *pSrc);
#endif

#ifdef __NEED_Packet_UPER
int Decode_UPER_Packet(asn1SccPacket *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Packet_ACN
int Decode_ACN_Packet(asn1SccPacket *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Packet_NATIVE
int Decode_NATIVE_Packet(asn1SccPacket *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Message_UPER
int Encode_UPER_Message(void *pBuffer, size_t iMaxBufferSize, const asn1SccMessage *pSrc);
#endif

#ifdef __NEED_Message_ACN
int Encode_ACN_Message(void *pBuffer, size_t iMaxBufferSize, asn1SccMessage *pSrc);
#endif

#ifdef __NEED_Message_NATIVE
int Encode_NATIVE_Message(void *pBuffer, size_t iMaxBufferSize, const asn1SccMessage *pSrc);
#endif

#ifdef __NEED_Message_UPER
int Decode_UPER_Message(asn1SccMessage *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Message_ACN
int Decode_ACN_Message(asn1SccMessage *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Message_NATIVE
int Decode_NATIVE_Message(asn1SccMessage *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_EventOccured_UPER
int Encode_UPER_EventOccured(void *pBuffer, size_t iMaxBufferSize, const asn1SccEventOccured *pSrc);
#endif

#ifdef __NEED_EventOccured_ACN
int Encode_ACN_EventOccured(void *pBuffer, size_t iMaxBufferSize, asn1SccEventOccured *pSrc);
#endif

#ifdef __NEED_EventOccured_NATIVE
int Encode_NATIVE_EventOccured(void *pBuffer, size_t iMaxBufferSize, const asn1SccEventOccured *pSrc);
#endif

#ifdef __NEED_EventOccured_UPER
int Decode_UPER_EventOccured(asn1SccEventOccured *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_EventOccured_ACN
int Decode_ACN_EventOccured(asn1SccEventOccured *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_EventOccured_NATIVE
int Decode_NATIVE_EventOccured(asn1SccEventOccured *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AcceptanceErrorOccured_UPER
int Encode_UPER_AcceptanceErrorOccured(void *pBuffer, size_t iMaxBufferSize, const asn1SccAcceptanceErrorOccured *pSrc);
#endif

#ifdef __NEED_AcceptanceErrorOccured_ACN
int Encode_ACN_AcceptanceErrorOccured(void *pBuffer, size_t iMaxBufferSize, asn1SccAcceptanceErrorOccured *pSrc);
#endif

#ifdef __NEED_AcceptanceErrorOccured_NATIVE
int Encode_NATIVE_AcceptanceErrorOccured(void *pBuffer, size_t iMaxBufferSize, const asn1SccAcceptanceErrorOccured *pSrc);
#endif

#ifdef __NEED_AcceptanceErrorOccured_UPER
int Decode_UPER_AcceptanceErrorOccured(asn1SccAcceptanceErrorOccured *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AcceptanceErrorOccured_ACN
int Decode_ACN_AcceptanceErrorOccured(asn1SccAcceptanceErrorOccured *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AcceptanceErrorOccured_NATIVE
int Decode_NATIVE_AcceptanceErrorOccured(asn1SccAcceptanceErrorOccured *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_RoutingErrorType_UPER
int Encode_UPER_RoutingErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccRoutingErrorType *pSrc);
#endif

#ifdef __NEED_RoutingErrorType_ACN
int Encode_ACN_RoutingErrorType(void *pBuffer, size_t iMaxBufferSize, asn1SccRoutingErrorType *pSrc);
#endif

#ifdef __NEED_RoutingErrorType_NATIVE
int Encode_NATIVE_RoutingErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccRoutingErrorType *pSrc);
#endif

#ifdef __NEED_RoutingErrorType_UPER
int Decode_UPER_RoutingErrorType(asn1SccRoutingErrorType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_RoutingErrorType_ACN
int Decode_ACN_RoutingErrorType(asn1SccRoutingErrorType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_RoutingErrorType_NATIVE
int Decode_NATIVE_RoutingErrorType(asn1SccRoutingErrorType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ExecutionStartErrorType_UPER
int Encode_UPER_ExecutionStartErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccExecutionStartErrorType *pSrc);
#endif

#ifdef __NEED_ExecutionStartErrorType_ACN
int Encode_ACN_ExecutionStartErrorType(void *pBuffer, size_t iMaxBufferSize, asn1SccExecutionStartErrorType *pSrc);
#endif

#ifdef __NEED_ExecutionStartErrorType_NATIVE
int Encode_NATIVE_ExecutionStartErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccExecutionStartErrorType *pSrc);
#endif

#ifdef __NEED_ExecutionStartErrorType_UPER
int Decode_UPER_ExecutionStartErrorType(asn1SccExecutionStartErrorType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ExecutionStartErrorType_ACN
int Decode_ACN_ExecutionStartErrorType(asn1SccExecutionStartErrorType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ExecutionStartErrorType_NATIVE
int Decode_NATIVE_ExecutionStartErrorType(asn1SccExecutionStartErrorType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ExecutionProgressErrorType_UPER
int Encode_UPER_ExecutionProgressErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccExecutionProgressErrorType *pSrc);
#endif

#ifdef __NEED_ExecutionProgressErrorType_ACN
int Encode_ACN_ExecutionProgressErrorType(void *pBuffer, size_t iMaxBufferSize, asn1SccExecutionProgressErrorType *pSrc);
#endif

#ifdef __NEED_ExecutionProgressErrorType_NATIVE
int Encode_NATIVE_ExecutionProgressErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccExecutionProgressErrorType *pSrc);
#endif

#ifdef __NEED_ExecutionProgressErrorType_UPER
int Decode_UPER_ExecutionProgressErrorType(asn1SccExecutionProgressErrorType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ExecutionProgressErrorType_ACN
int Decode_ACN_ExecutionProgressErrorType(asn1SccExecutionProgressErrorType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ExecutionProgressErrorType_NATIVE
int Decode_NATIVE_ExecutionProgressErrorType(asn1SccExecutionProgressErrorType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ExecutionCompletionErrorType_UPER
int Encode_UPER_ExecutionCompletionErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccExecutionCompletionErrorType *pSrc);
#endif

#ifdef __NEED_ExecutionCompletionErrorType_ACN
int Encode_ACN_ExecutionCompletionErrorType(void *pBuffer, size_t iMaxBufferSize, asn1SccExecutionCompletionErrorType *pSrc);
#endif

#ifdef __NEED_ExecutionCompletionErrorType_NATIVE
int Encode_NATIVE_ExecutionCompletionErrorType(void *pBuffer, size_t iMaxBufferSize, const asn1SccExecutionCompletionErrorType *pSrc);
#endif

#ifdef __NEED_ExecutionCompletionErrorType_UPER
int Decode_UPER_ExecutionCompletionErrorType(asn1SccExecutionCompletionErrorType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ExecutionCompletionErrorType_ACN
int Decode_ACN_ExecutionCompletionErrorType(asn1SccExecutionCompletionErrorType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_ExecutionCompletionErrorType_NATIVE
int Decode_NATIVE_ExecutionCompletionErrorType(asn1SccExecutionCompletionErrorType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_UPER
int Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_ACN
int Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_NATIVE
int Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_UPER
int Decode_UPER_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_ACN
int Decode_ACN_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_NATIVE
int Decode_NATIVE_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_UPER
int Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_ACN
int Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_UPER
int Decode_UPER_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_ACN
int Decode_ACN_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Decode_NATIVE_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_UPER
int Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_ACN
int Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_NATIVE
int Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_UPER
int Decode_UPER_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_ACN
int Decode_ACN_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_NATIVE
int Decode_NATIVE_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_UPER
int Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_ACN
int Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_UPER
int Decode_UPER_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_ACN
int Decode_ACN_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Decode_NATIVE_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_UPER
int Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_ACN
int Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_UPER
int Decode_UPER_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_ACN
int Decode_ACN_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Decode_NATIVE_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_UPER
int Encode_UPER_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_ACN
int Encode_ACN_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Encode_NATIVE_T_Null_Record(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Null_Record *pSrc);
#endif

#ifdef __NEED_T_Null_Record_UPER
int Decode_UPER_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_ACN
int Decode_ACN_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Null_Record_NATIVE
int Decode_NATIVE_T_Null_Record(asn1SccT_Null_Record *pDst, void *pBuffer, size_t iBufferSize);
#endif


#endif

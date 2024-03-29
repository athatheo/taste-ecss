#ifndef __PRINTTYPES_H__
#define __PRINTTYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "dataview-uniq.h" // Generated by ASN1SCC

void PrintMyInteger(const char *paramName, const asn1SccMyInteger *pData);
void PrintUInt8(const char *paramName, const asn1SccUInt8 *pData);
void PrintUInt16(const char *paramName, const asn1SccUInt16 *pData);
void PrintPacket(const char *paramName, const asn1SccPacket *pData);
void PrintMessage(const char *paramName, const asn1SccMessage *pData);
void PrintEventOccured(const char *paramName, const asn1SccEventOccured *pData);
void PrintAcceptanceErrorOccured(const char *paramName, const asn1SccAcceptanceErrorOccured *pData);
void PrintRoutingErrorType(const char *paramName, const asn1SccRoutingErrorType *pData);
void PrintExecutionStartErrorType(const char *paramName, const asn1SccExecutionStartErrorType *pData);
void PrintExecutionProgressErrorType(const char *paramName, const asn1SccExecutionProgressErrorType *pData);
void PrintExecutionCompletionErrorType(const char *paramName, const asn1SccExecutionCompletionErrorType *pData);
void PrintT_Int32(const char *paramName, const asn1SccT_Int32 *pData);
void PrintT_UInt32(const char *paramName, const asn1SccT_UInt32 *pData);
void PrintT_Int8(const char *paramName, const asn1SccT_Int8 *pData);
void PrintT_UInt8(const char *paramName, const asn1SccT_UInt8 *pData);
void PrintT_Boolean(const char *paramName, const asn1SccT_Boolean *pData);
void PrintT_Null_Record(const char *paramName, const asn1SccT_Null_Record *pData);

#ifdef __cplusplus
}
#endif

#endif

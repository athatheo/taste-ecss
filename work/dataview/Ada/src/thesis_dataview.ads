pragma Style_Checks (Off);
--  Code automatically generated by asn1scc tool
with adaasn1rtl;


pragma Warnings (Off, "unit ""System"" is not referenced");
with System;
pragma Warnings (On, "unit ""System"" is not referenced");

pragma Warnings (Off, "use clause for package ""adaasn1rtl"" has no effect");
use adaasn1rtl;
pragma Warnings (On, "use clause for package ""adaasn1rtl"" has no effect");

pragma Warnings (Off, "use clause for type");
pragma Warnings (Off, "is already use-visible through package use clause at line");
use type adaasn1rtl.OctetBuffer;
use type adaasn1rtl.BitArray;
use type adaasn1rtl.Asn1UInt;
use type adaasn1rtl.Asn1Int;
use type adaasn1rtl.BIT;
pragma Warnings (On, "use clause for type");
pragma Warnings (On, "is already use-visible through package use clause at line");



package THESIS_DATAVIEW with SPARK_Mode
is


subtype asn1SccMyInteger is adaasn1rtl.Asn1UInt range 0 .. 10000;


function asn1SccMyInteger_Equal(val1, val2 : asn1SccMyInteger) return Boolean;

function asn1SccMyInteger_Init return asn1SccMyInteger;

ERR_MYINTEGER:constant Integer := 1; 
function asn1SccMyInteger_IsConstraintValid(val : asn1SccMyInteger) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccUInt8 is adaasn1rtl.Asn1UInt range 0 .. 255;


function asn1SccUInt8_Equal(val1, val2 : asn1SccUInt8) return Boolean;

function asn1SccUInt8_Init return asn1SccUInt8;

ERR_UINT8:constant Integer := 8; 
function asn1SccUInt8_IsConstraintValid(val : asn1SccUInt8) return adaasn1rtl.ASN1_RESULT;
-- asn1SccPacket --------------------------------------------


subtype asn1SccPacket_index is Integer range 1..100;
type asn1SccPacket_array is array (asn1SccPacket_index) of asn1SccUInt8;
type asn1SccPacket is  record
    Data  : asn1SccPacket_array;
end record;

function asn1SccPacket_Equal(val1, val2 : asn1SccPacket) return Boolean;

function asn1SccPacket_Init return asn1SccPacket;

ERR_PACKET:constant Integer := 36; 
ERR_PACKET_ELM_2:constant Integer := 29; 
function asn1SccPacket_IsConstraintValid(val : asn1SccPacket) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccUInt16 is adaasn1rtl.Asn1UInt range 0 .. 65535;


function asn1SccUInt16_Equal(val1, val2 : asn1SccUInt16) return Boolean;

function asn1SccUInt16_Init return asn1SccUInt16;

ERR_UINT16:constant Integer := 15; 
function asn1SccUInt16_IsConstraintValid(val : asn1SccUInt16) return adaasn1rtl.ASN1_RESULT;
-- asn1SccMessage --------------------------------------------
subtype asn1SccMessage_packetType_index_range is Integer range 0..1;
type asn1SccMessage_packetType is (asn1Scctm, asn1Scctc) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccMessage_packetType use
    (asn1Scctm => 0, asn1Scctc => 1);
-- asn1SccMessage_data --------------------------------------------


subtype asn1SccMessage_data_index is Integer range 1..1024;
type asn1SccMessage_data_array is array (asn1SccMessage_data_index) of asn1SccUInt16;
type asn1SccMessage_data is  record
    Data  : asn1SccMessage_data_array;
end record;

type asn1SccMessage is record 
    packetType : asn1SccMessage_packetType;
    serviceType : asn1SccUInt8;
    messageType : asn1SccUInt8;
    applicationId : asn1SccUInt16;
    messageTypeCounter : asn1SccUInt16;
    packetSequenceCount : asn1SccUInt16;
    dataSize : asn1SccUInt16;
    data : asn1SccMessage_data;
end record;


function asn1SccMessage_packetType_Equal(val1, val2 : asn1SccMessage_packetType) return Boolean;

function asn1SccMessage_data_Equal(val1, val2 : asn1SccMessage_data) return Boolean;

function asn1SccMessage_Equal(val1, val2 : asn1SccMessage) return Boolean;

function asn1SccMessage_packetType_Init return asn1SccMessage_packetType;
function asn1SccMessage_data_Init return asn1SccMessage_data;
function asn1SccMessage_Init return asn1SccMessage;

ERR_MESSAGE:constant Integer := 155; 
ERR_MESSAGE_PACKETTYPE:constant Integer := 43; 
ERR_MESSAGE_SERVICETYPE_2:constant Integer := 57; 
ERR_MESSAGE_MESSAGETYPE_2:constant Integer := 71; 
ERR_MESSAGE_APPLICATIONID_2:constant Integer := 85; 
ERR_MESSAGE_MESSAGETYPECOUNTER_2:constant Integer := 99; 
ERR_MESSAGE_PACKETSEQUENCECOUNT_2:constant Integer := 113; 
ERR_MESSAGE_DATASIZE_2:constant Integer := 127; 
ERR_MESSAGE_DATA:constant Integer := 148; 
ERR_MESSAGE_DATA_ELM_2:constant Integer := 141; 
function asn1SccMessage_IsConstraintValid(val : asn1SccMessage) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccEventOccured_index_range is Integer range 0..7;
type asn1SccEventOccured is (asn1SccinformativeUnknownEvent, asn1SccwwdgReset, asn1SccassertionFail, asn1SccmCUStart, asn1ScclowSeverityUnknownEvent, asn1SccmediumSeverityUnknownEvent, asn1ScchighSeverityUnknownEvent, asn1SccfailedStartOfExecution) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccEventOccured use
    (asn1SccinformativeUnknownEvent => 0, asn1SccwwdgReset => 1, asn1SccassertionFail => 2, asn1SccmCUStart => 3, asn1ScclowSeverityUnknownEvent => 4, asn1SccmediumSeverityUnknownEvent => 5, asn1ScchighSeverityUnknownEvent => 6, asn1SccfailedStartOfExecution => 7);

function asn1SccEventOccured_Equal(val1, val2 : asn1SccEventOccured) return Boolean;

function asn1SccEventOccured_Init return asn1SccEventOccured;

ERR_EVENTOCCURED:constant Integer := 162; 
function asn1SccEventOccured_IsConstraintValid(val : asn1SccEventOccured) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccAcceptanceErrorOccured_index_range is Integer range 0..4;
type asn1SccAcceptanceErrorOccured is (asn1SccunknownAcceptanceError, asn1SccmessageTooShort, asn1ScctooManyBitsRead, asn1SccstringTooShort, asn1SccunacceptableMessage) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccAcceptanceErrorOccured use
    (asn1SccunknownAcceptanceError => 0, asn1SccmessageTooShort => 1, asn1ScctooManyBitsRead => 2, asn1SccstringTooShort => 4, asn1SccunacceptableMessage => 5);

function asn1SccAcceptanceErrorOccured_Equal(val1, val2 : asn1SccAcceptanceErrorOccured) return Boolean;

function asn1SccAcceptanceErrorOccured_Init return asn1SccAcceptanceErrorOccured;

ERR_ACCEPTANCEERROROCCURED:constant Integer := 169; 
function asn1SccAcceptanceErrorOccured_IsConstraintValid(val : asn1SccAcceptanceErrorOccured) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccRoutingErrorType_index_range is Integer range 0..0;
type asn1SccRoutingErrorType is (asn1SccunknownRoutingError) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccRoutingErrorType use
    (asn1SccunknownRoutingError => 0);

function asn1SccRoutingErrorType_Equal(val1, val2 : asn1SccRoutingErrorType) return Boolean;

function asn1SccRoutingErrorType_Init return asn1SccRoutingErrorType;

ERR_ROUTINGERRORTYPE:constant Integer := 176; 
function asn1SccRoutingErrorType_IsConstraintValid(val : asn1SccRoutingErrorType) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccExecutionStartErrorType_index_range is Integer range 0..8;
type asn1SccExecutionStartErrorType is (asn1SccunknownExecutionStartError, asn1ScceventActionDefinitionIDExistsError, asn1ScceventActionDeleteEnabledDefinitionError, asn1ScceventActionUnknownEventDefinitionError, asn1ScceventActionUnknownEventActionDefinitionIDError, asn1SccsubServiceExecutionStartError, asn1SccinstructionExecutionStartError, asn1SccsetNonExistingParameter, asn1SccgetNonExistingParameter) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccExecutionStartErrorType use
    (asn1SccunknownExecutionStartError => 0, asn1ScceventActionDefinitionIDExistsError => 1, asn1ScceventActionDeleteEnabledDefinitionError => 2, asn1ScceventActionUnknownEventDefinitionError => 3, asn1ScceventActionUnknownEventActionDefinitionIDError => 4, asn1SccsubServiceExecutionStartError => 5, asn1SccinstructionExecutionStartError => 6, asn1SccsetNonExistingParameter => 7, asn1SccgetNonExistingParameter => 8);

function asn1SccExecutionStartErrorType_Equal(val1, val2 : asn1SccExecutionStartErrorType) return Boolean;

function asn1SccExecutionStartErrorType_Init return asn1SccExecutionStartErrorType;

ERR_EXECUTIONSTARTERRORTYPE:constant Integer := 183; 
function asn1SccExecutionStartErrorType_IsConstraintValid(val : asn1SccExecutionStartErrorType) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccExecutionProgressErrorType_index_range is Integer range 0..0;
type asn1SccExecutionProgressErrorType is (asn1SccunknownExecutionProgressError) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccExecutionProgressErrorType use
    (asn1SccunknownExecutionProgressError => 0);

function asn1SccExecutionProgressErrorType_Equal(val1, val2 : asn1SccExecutionProgressErrorType) return Boolean;

function asn1SccExecutionProgressErrorType_Init return asn1SccExecutionProgressErrorType;

ERR_EXECUTIONPROGRESSERRORTYPE:constant Integer := 190; 
function asn1SccExecutionProgressErrorType_IsConstraintValid(val : asn1SccExecutionProgressErrorType) return adaasn1rtl.ASN1_RESULT;
subtype asn1SccExecutionCompletionErrorType_index_range is Integer range 0..2;
type asn1SccExecutionCompletionErrorType is (asn1SccunknownExecutionCompletionError, asn1SccchecksumFailed, asn1SccaddressOutOfRange) with Size => adaasn1rtl.Enumerated_Size;
for asn1SccExecutionCompletionErrorType use
    (asn1SccunknownExecutionCompletionError => 0, asn1SccchecksumFailed => 1, asn1SccaddressOutOfRange => 2);

function asn1SccExecutionCompletionErrorType_Equal(val1, val2 : asn1SccExecutionCompletionErrorType) return Boolean;

function asn1SccExecutionCompletionErrorType_Init return asn1SccExecutionCompletionErrorType;

ERR_EXECUTIONCOMPLETIONERRORTYPE:constant Integer := 197; 
function asn1SccExecutionCompletionErrorType_IsConstraintValid(val : asn1SccExecutionCompletionErrorType) return adaasn1rtl.ASN1_RESULT;
pragma Warnings (Off, "there are no others");
 
pragma Warnings (On, "there are no others");
private
   --# hide THESIS_DATAVIEW;


end THESIS_DATAVIEW;
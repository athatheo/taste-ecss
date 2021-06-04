// Body file for function ST20ParameterService
// Generated by TASTE on 2021-05-18 21:17:22
// You can edit this file, it will not be overwritten
// Provided interfaces : TC20
// Required interfaces : 
// User-defined properties for this function:
//   |_ Taste::Active_Interfaces = any
//   |_ Taste::coordinates = 151502 117062 190680 129859
// Timers              : 

#include "st20parameterservice.h"
#include "st20parameterservice_state.h"
//#include <iostream>

// Define and use function state inside this context structure
// avoid defining global/static variable elsewhere
/* User code: This file will not be overwritten by TASTE. */

#include <stdint.h>
#include <array>
#include "iostream"
#define ECSS_PARAMETER_COUNT 20
st20parameterservice_state ctxt_st20parameterservice;


class Parameter {
private:
	uint16_t currentValue;

public:
	void setValue(uint16_t value) {
		currentValue = value;
	}

	uint16_t getValue() {
		return currentValue;
	}

};

std::array<Parameter, ECSS_PARAMETER_COUNT> parametersArray;

void reportParameters(const asn1SccMessage*);
void setParameters(const asn1SccMessage*);

void st20parameterservice_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void st20parameterservice_PI_TC20(const asn1SccMessage *IN_message)
{
	switch (IN_message->messageType) {
		case 1:
			reportParameters(IN_message); // TC[20,1]
			break;
		case 3:
			setParameters(IN_message ); // TC[20,3]
			break;
	}
}

void st20parameterservice_PI_EventActionTC20(const asn1SccMessage *IN_message)
{
	switch (IN_message->messageType) {
		case 1:
			reportParameters(IN_message); // TC[20,1]
			break;
		case 3:
			setParameters(IN_message ); // TC[20,3]
			break;
	}
}


void reportParameters(const asn1SccMessage* paramIds) {
	// TM[20,2]
	asn1SccMessage report;
	int reportDataCounter = 0;
	report.packetType = asn1SccMessage_packetType(0);
    	report.serviceType = 20;
    	report.messageType = 2;
	int counter = 0;
	uint16_t numOfIds = paramIds->data.arr[0];
	counter++;
	uint16_t numberOfValidIds = 0;
	for (uint16_t i = 0; i < numOfIds; i++) {
		if (paramIds->data.arr[counter] < parametersArray.size()) {
			numberOfValidIds++;
		}
		counter++;
	}
	
	report.data.arr[reportDataCounter] = (numberOfValidIds);
	reportDataCounter++;

	for (uint16_t i = 0; i < numOfIds; i++) {
		uint16_t currId = paramIds->data.arr[counter];
		if (currId < parametersArray.size()) {
			report.data.arr[reportDataCounter] = currId;
			reportDataCounter++;
			report.data.arr[reportDataCounter] = parametersArray.at(currId).getValue();
			reportDataCounter++;
		}
		counter++;
	}
    std::cout << "TC[20,01]" << std::endl;
	//storeMessage(parameterReport);
}

void setParameters(const asn1SccMessage* newParamValues) {
	int current = 0;
	uint16_t numOfIds = newParamValues->data.arr[current];
	current++;
	for (uint16_t i = 0; i < numOfIds; i++) {
		uint16_t currId = newParamValues->data.arr[current];
		current++;
		if (currId < parametersArray.size()) {
			parametersArray.at(currId).setValue(newParamValues->data.arr[current]);
			current++;
		} else {
			break; // Setting next parameters is impossible, since the size of value to be read is unknown
		}
	}
    std::cout << "TC[20,03]" << std::endl;
}

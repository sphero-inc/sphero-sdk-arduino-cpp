// ************************************************************
// This file was automatically generated!
// Device ID (DID):         0x1A
// Device Name:             io
// Device Description:      
// Command Count:           2
// Source File:             0x1A-user_io.json
// ************************************************************

#include "io.h"
#include "sphero_api.h"

// ************************************************************
// Private Response Function Prototypes
// ************************************************************


// ************************************************************
// Private Data
// ************************************************************


// ************************************************************
// Public Function Implementations
// ************************************************************

IoDevice::IoDevice(void)
{
}

void IoDevice::configUART(HardwareSerial *port)
{
	initUartApi(port);
}

void IoDevice::setAllLeds(uint32_t ledGroup, uint8_t ledBrightnessValues[], int ledBrightnessValuesArraySize)
{
	apiPacket_t command;
	uint8_t params[4 + ledBrightnessValuesArraySize] = {0};
	setupApiCommand(&command, 0x1A, 0x1A, true, params);
	
	packUint32(&command, ledGroup);
	for (byte i = 0; i < ledBrightnessValuesArraySize; i++)
	{
		packUint8(&command, ledBrightnessValues[i]);
	}
	
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, NULL);
}

void IoDevice::releaseLedRequests()
{
	apiPacket_t command;
	setupApiCommand(&command, 0x1A, 0x4E, true, NULL);
	
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, NULL);
}

// ************************************************************
// Private Response Function Implementations
// ************************************************************


// ************************************************************
// This file was automatically generated!
// Device ID (DID):         0x19
// Device Name:             connection
// Device Description:      
// Command Count:           1
// Source File:             0x19-peer_connection.json
// ************************************************************

#include "connection.h"
#include "sphero_api.h"

// ************************************************************
// Private Response Function Prototypes
// ************************************************************

extern "C" void arhGetBluetoothAdvertisingNameCallback(apiPacket_t *response);

// ************************************************************
// Private Data
// ************************************************************

static GetBluetoothAdvertisingNameCallback_t getBluetoothAdvertisingNameCallback;

// ************************************************************
// Public Function Implementations
// ************************************************************

ConnectionDevice::ConnectionDevice(void)
{
}

void ConnectionDevice::configUART(HardwareSerial *port)
{
	initUartApi(port);
}

void ConnectionDevice::getBluetoothAdvertisingName(GetBluetoothAdvertisingNameCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x19, 0x05, true, NULL);
	
	getBluetoothAdvertisingNameCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetBluetoothAdvertisingNameCallback : NULL);
}

// ************************************************************
// Private Response Function Implementations
// ************************************************************

extern "C" void arhGetBluetoothAdvertisingNameCallback(apiPacket_t *response)
{
	if (getBluetoothAdvertisingNameCallback == NULL)
	{
		return;
	}
	
	GetBluetoothAdvertisingNameReturn_t getBluetoothAdvertisingNameReturn;
	
	getBluetoothAdvertisingNameReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		unpackNullTerminatedString(response, getBluetoothAdvertisingNameReturn.aName, sizeof(getBluetoothAdvertisingNameReturn.aName)/sizeof(*getBluetoothAdvertisingNameReturn.aName) - 1);
	}
	
	getBluetoothAdvertisingNameCallback(&getBluetoothAdvertisingNameReturn);
}


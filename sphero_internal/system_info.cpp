// ************************************************************
// This file was automatically generated!
// Device ID (DID):         0x11
// Device Name:             system_info
// Device Description:      
// Command Count:           8
// Source File:             0x11-system_info.json
// ************************************************************

#include "system_info.h"
#include "sphero_api.h"

// ************************************************************
// Private Response Function Prototypes
// ************************************************************

extern "C" void arhGetMainApplicationVersionCallback(apiPacket_t *response);
extern "C" void arhGetBootloaderVersionCallback(apiPacket_t *response);
extern "C" void arhGetBoardRevisionCallback(apiPacket_t *response);
extern "C" void arhGetMacAddressCallback(apiPacket_t *response);
extern "C" void arhGetStatsIdCallback(apiPacket_t *response);
extern "C" void arhGetProcessorNameCallback(apiPacket_t *response);
extern "C" void arhGetSkuCallback(apiPacket_t *response);
extern "C" void arhGetCoreUpTimeInMillisecondsCallback(apiPacket_t *response);

// ************************************************************
// Private Data
// ************************************************************

static GetMainApplicationVersionCallback_t getMainApplicationVersionCallback;
static GetBootloaderVersionCallback_t getBootloaderVersionCallback;
static GetBoardRevisionCallback_t getBoardRevisionCallback;
static GetMacAddressCallback_t getMacAddressCallback;
static GetStatsIdCallback_t getStatsIdCallback;
static GetProcessorNameCallback_t getProcessorNameCallback;
static GetSkuCallback_t getSkuCallback;
static GetCoreUpTimeInMillisecondsCallback_t getCoreUpTimeInMillisecondsCallback;

// ************************************************************
// Public Function Implementations
// ************************************************************

SystemInfoDevice::SystemInfoDevice(void)
{
}

void SystemInfoDevice::configUART(HardwareSerial *port)
{
	initUartApi(port);
}

void SystemInfoDevice::getMainApplicationVersion(uint8_t target, GetMainApplicationVersionCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x11, 0x00, true, NULL);
	
	getMainApplicationVersionCallback = callback;
	sendApiCommandToNode(target, &command, callback ? arhGetMainApplicationVersionCallback : NULL);
}

void SystemInfoDevice::getBootloaderVersion(uint8_t target, GetBootloaderVersionCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x11, 0x01, true, NULL);
	
	getBootloaderVersionCallback = callback;
	sendApiCommandToNode(target, &command, callback ? arhGetBootloaderVersionCallback : NULL);
}

void SystemInfoDevice::getBoardRevision(GetBoardRevisionCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x11, 0x03, true, NULL);
	
	getBoardRevisionCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetBoardRevisionCallback : NULL);
}

void SystemInfoDevice::getMacAddress(GetMacAddressCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x11, 0x06, true, NULL);
	
	getMacAddressCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetMacAddressCallback : NULL);
}

void SystemInfoDevice::getStatsId(GetStatsIdCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x11, 0x13, true, NULL);
	
	getStatsIdCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetStatsIdCallback : NULL);
}

void SystemInfoDevice::getProcessorName(uint8_t target, GetProcessorNameCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x11, 0x1F, true, NULL);
	
	getProcessorNameCallback = callback;
	sendApiCommandToNode(target, &command, callback ? arhGetProcessorNameCallback : NULL);
}

void SystemInfoDevice::getSku(GetSkuCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x11, 0x38, true, NULL);
	
	getSkuCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetSkuCallback : NULL);
}

void SystemInfoDevice::getCoreUpTimeInMilliseconds(GetCoreUpTimeInMillisecondsCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x11, 0x39, true, NULL);
	
	getCoreUpTimeInMillisecondsCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetCoreUpTimeInMillisecondsCallback : NULL);
}

// ************************************************************
// Private Response Function Implementations
// ************************************************************

extern "C" void arhGetMainApplicationVersionCallback(apiPacket_t *response)
{
	if (getMainApplicationVersionCallback == NULL)
	{
		return;
	}
	
	GetMainApplicationVersionReturn_t getMainApplicationVersionReturn;
	
	getMainApplicationVersionReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getMainApplicationVersionReturn.major = unpackUint16(response);
		getMainApplicationVersionReturn.minor = unpackUint16(response);
		getMainApplicationVersionReturn.revision = unpackUint16(response);
	}
	
	getMainApplicationVersionCallback(&getMainApplicationVersionReturn);
}

extern "C" void arhGetBootloaderVersionCallback(apiPacket_t *response)
{
	if (getBootloaderVersionCallback == NULL)
	{
		return;
	}
	
	GetBootloaderVersionReturn_t getBootloaderVersionReturn;
	
	getBootloaderVersionReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getBootloaderVersionReturn.major = unpackUint16(response);
		getBootloaderVersionReturn.minor = unpackUint16(response);
		getBootloaderVersionReturn.revision = unpackUint16(response);
	}
	
	getBootloaderVersionCallback(&getBootloaderVersionReturn);
}

extern "C" void arhGetBoardRevisionCallback(apiPacket_t *response)
{
	if (getBoardRevisionCallback == NULL)
	{
		return;
	}
	
	GetBoardRevisionReturn_t getBoardRevisionReturn;
	
	getBoardRevisionReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getBoardRevisionReturn.revision = unpackUint8(response);
	}
	
	getBoardRevisionCallback(&getBoardRevisionReturn);
}

extern "C" void arhGetMacAddressCallback(apiPacket_t *response)
{
	if (getMacAddressCallback == NULL)
	{
		return;
	}
	
	GetMacAddressReturn_t getMacAddressReturn;
	
	getMacAddressReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		unpackNullTerminatedString(response, getMacAddressReturn.macAddress, sizeof(getMacAddressReturn.macAddress)/sizeof(*getMacAddressReturn.macAddress) - 1);
	}
	
	getMacAddressCallback(&getMacAddressReturn);
}

extern "C" void arhGetStatsIdCallback(apiPacket_t *response)
{
	if (getStatsIdCallback == NULL)
	{
		return;
	}
	
	GetStatsIdReturn_t getStatsIdReturn;
	
	getStatsIdReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getStatsIdReturn.statsId = unpackUint16(response);
	}
	
	getStatsIdCallback(&getStatsIdReturn);
}

extern "C" void arhGetProcessorNameCallback(apiPacket_t *response)
{
	if (getProcessorNameCallback == NULL)
	{
		return;
	}
	
	GetProcessorNameReturn_t getProcessorNameReturn;
	
	getProcessorNameReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		unpackNullTerminatedString(response, getProcessorNameReturn.aName, sizeof(getProcessorNameReturn.aName)/sizeof(*getProcessorNameReturn.aName) - 1);
	}
	
	getProcessorNameCallback(&getProcessorNameReturn);
}

extern "C" void arhGetSkuCallback(apiPacket_t *response)
{
	if (getSkuCallback == NULL)
	{
		return;
	}
	
	GetSkuReturn_t getSkuReturn;
	
	getSkuReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		unpackNullTerminatedString(response, getSkuReturn.sku, sizeof(getSkuReturn.sku)/sizeof(*getSkuReturn.sku) - 1);
	}
	
	getSkuCallback(&getSkuReturn);
}

extern "C" void arhGetCoreUpTimeInMillisecondsCallback(apiPacket_t *response)
{
	if (getCoreUpTimeInMillisecondsCallback == NULL)
	{
		return;
	}
	
	GetCoreUpTimeInMillisecondsReturn_t getCoreUpTimeInMillisecondsReturn;
	
	getCoreUpTimeInMillisecondsReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getCoreUpTimeInMillisecondsReturn.upTime = unpackUint64(response);
	}
	
	getCoreUpTimeInMillisecondsCallback(&getCoreUpTimeInMillisecondsReturn);
}


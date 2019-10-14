// ************************************************************
// This file was automatically generated!
// Device ID (DID):         0x13
// Device Name:             power
// Device Description:      
// Command Count:           12
// Source File:             0x13-power.json
// ************************************************************

#include "power.h"
#include "sphero_api.h"

// ************************************************************
// Private Response Function Prototypes
// ************************************************************

extern "C" void arhGetBatteryPercentageCallback(apiPacket_t *response);
extern "C" void arhGetBatteryVoltageStateCallback(apiPacket_t *response);
extern "C" void arhGetBatteryVoltageInVoltsCallback(apiPacket_t *response);
extern "C" void arhGetBatteryVoltageStateThresholdsCallback(apiPacket_t *response);
extern "C" void arhGetCurrentSenseAmplifierCurrentCallback(apiPacket_t *response);

// ************************************************************
// Private Async Function Prototypes
// ************************************************************

extern "C" void achWillSleepNotify(apiPacket_t *command, apiPacket_t *response);
extern "C" void achDidSleepNotify(apiPacket_t *command, apiPacket_t *response);
extern "C" void achBatteryVoltageStateChangeNotify(apiPacket_t *command, apiPacket_t *response);

// ************************************************************
// Private Data
// ************************************************************

static GetBatteryPercentageCallback_t getBatteryPercentageCallback;
static GetBatteryVoltageStateCallback_t getBatteryVoltageStateCallback;
static WillSleepNotifyCallback_t willSleepNotifyCallback;
static DidSleepNotifyCallback_t didSleepNotifyCallback;
static BatteryVoltageStateChangeNotifyCallback_t batteryVoltageStateChangeNotifyCallback;
static GetBatteryVoltageInVoltsCallback_t getBatteryVoltageInVoltsCallback;
static GetBatteryVoltageStateThresholdsCallback_t getBatteryVoltageStateThresholdsCallback;
static GetCurrentSenseAmplifierCurrentCallback_t getCurrentSenseAmplifierCurrentCallback;

static apiCommandDefinition_t apiCommands[] =
{
	{0x19, 0, achWillSleepNotify, API_COMMAND_DEFINITION_FLAG_NONE},
	{0x1A, 0, achDidSleepNotify, API_COMMAND_DEFINITION_FLAG_NONE},
	{0x1C, 1, achBatteryVoltageStateChangeNotify, API_COMMAND_DEFINITION_FLAG_NONE}	
};

// ************************************************************
// Public Function Implementations
// ************************************************************

PowerDevice::PowerDevice(void)
{
}

void PowerDevice::configUART(HardwareSerial *port)
{
	initUartApi(port);
	ADD_API_COMMANDS(0x13, apiCommands);
}

void PowerDevice::enterDeepSleep(uint8_t secondsUntilDeepSleep)
{
	apiPacket_t command;
	uint8_t param = 0;
	setupApiCommand(&command, 0x13, 0x00, true, &param);
	
	packUint8(&command, secondsUntilDeepSleep);
	
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, NULL);
}

void PowerDevice::sleep()
{
	apiPacket_t command;
	setupApiCommand(&command, 0x13, 0x01, true, NULL);
	
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, NULL);
}

void PowerDevice::wake()
{
	apiPacket_t command;
	setupApiCommand(&command, 0x13, 0x0D, true, NULL);
	
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, NULL);
}

void PowerDevice::getBatteryPercentage(GetBatteryPercentageCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x13, 0x10, true, NULL);
	
	getBatteryPercentageCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetBatteryPercentageCallback : NULL);
}

void PowerDevice::getBatteryVoltageState(GetBatteryVoltageStateCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x13, 0x17, true, NULL);
	
	getBatteryVoltageStateCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetBatteryVoltageStateCallback : NULL);
}

void PowerDevice::setWillSleepNotifyCallback(WillSleepNotifyCallback_t callback)
{
	willSleepNotifyCallback = callback;
}

void PowerDevice::setDidSleepNotifyCallback(DidSleepNotifyCallback_t callback)
{
	didSleepNotifyCallback = callback;
}

void PowerDevice::enableBatteryVoltageStateChangeNotify(bool isEnabled, BatteryVoltageStateChangeNotifyCallback_t callback)
{
	batteryVoltageStateChangeNotifyCallback = NULL;
	
	if(isEnabled)
	{
		batteryVoltageStateChangeNotifyCallback = callback;
	}
	
	apiPacket_t command;
	uint8_t param = 0;
	setupApiCommand(&command, 0x13, 0x1B, true, &param);
	
	packBool(&command, isEnabled);
	
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, NULL);
}

void PowerDevice::getBatteryVoltageInVolts(BatteryVoltageReadingTypes readingType, GetBatteryVoltageInVoltsCallback_t callback)
{
	apiPacket_t command;
	uint8_t param = 0;
	setupApiCommand(&command, 0x13, 0x25, true, &param);
	
	packUint8(&command, static_cast<uint8_t>(readingType));
	
	getBatteryVoltageInVoltsCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetBatteryVoltageInVoltsCallback : NULL);
}

void PowerDevice::getBatteryVoltageStateThresholds(GetBatteryVoltageStateThresholdsCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x13, 0x26, true, NULL);
	
	getBatteryVoltageStateThresholdsCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetBatteryVoltageStateThresholdsCallback : NULL);
}

void PowerDevice::getCurrentSenseAmplifierCurrent(AmplifierIds amplifierId, GetCurrentSenseAmplifierCurrentCallback_t callback)
{
	apiPacket_t command;
	uint8_t param = 0;
	setupApiCommand(&command, 0x13, 0x27, true, &param);
	
	packUint8(&command, static_cast<uint8_t>(amplifierId));
	
	getCurrentSenseAmplifierCurrentCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetCurrentSenseAmplifierCurrentCallback : NULL);
}

// ************************************************************
// Private Response Function Implementations
// ************************************************************

extern "C" void arhGetBatteryPercentageCallback(apiPacket_t *response)
{
	if (getBatteryPercentageCallback == NULL)
	{
		return;
	}
	
	GetBatteryPercentageReturn_t getBatteryPercentageReturn;
	
	getBatteryPercentageReturn.rc = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getBatteryPercentageReturn.percentage = unpackUint8(response);
	}
	
	getBatteryPercentageCallback(&getBatteryPercentageReturn);
}

extern "C" void arhGetBatteryVoltageStateCallback(apiPacket_t *response)
{
	if (getBatteryVoltageStateCallback == NULL)
	{
		return;
	}
	
	GetBatteryVoltageStateReturn_t getBatteryVoltageStateReturn;
	
	getBatteryVoltageStateReturn.rc = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getBatteryVoltageStateReturn.state = static_cast<BatteryVoltageStates>(unpackUint8(response));
	}
	
	getBatteryVoltageStateCallback(&getBatteryVoltageStateReturn);
}

extern "C" void arhGetBatteryVoltageInVoltsCallback(apiPacket_t *response)
{
	if (getBatteryVoltageInVoltsCallback == NULL)
	{
		return;
	}
	
	GetBatteryVoltageInVoltsReturn_t getBatteryVoltageInVoltsReturn;
	
	getBatteryVoltageInVoltsReturn.rc = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getBatteryVoltageInVoltsReturn.voltage = unpackFloat(response);
	}
	
	getBatteryVoltageInVoltsCallback(&getBatteryVoltageInVoltsReturn);
}

extern "C" void arhGetBatteryVoltageStateThresholdsCallback(apiPacket_t *response)
{
	if (getBatteryVoltageStateThresholdsCallback == NULL)
	{
		return;
	}
	
	GetBatteryVoltageStateThresholdsReturn_t getBatteryVoltageStateThresholdsReturn;
	
	getBatteryVoltageStateThresholdsReturn.rc = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getBatteryVoltageStateThresholdsReturn.criticalThreshold = unpackFloat(response);
		getBatteryVoltageStateThresholdsReturn.lowThreshold = unpackFloat(response);
		getBatteryVoltageStateThresholdsReturn.hysteresis = unpackFloat(response);
	}
	
	getBatteryVoltageStateThresholdsCallback(&getBatteryVoltageStateThresholdsReturn);
}

extern "C" void arhGetCurrentSenseAmplifierCurrentCallback(apiPacket_t *response)
{
	if (getCurrentSenseAmplifierCurrentCallback == NULL)
	{
		return;
	}
	
	GetCurrentSenseAmplifierCurrentReturn_t getCurrentSenseAmplifierCurrentReturn;
	
	getCurrentSenseAmplifierCurrentReturn.rc = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getCurrentSenseAmplifierCurrentReturn.amplifierCurrent = unpackFloat(response);
	}
	
	getCurrentSenseAmplifierCurrentCallback(&getCurrentSenseAmplifierCurrentReturn);
}

// ************************************************************
// Private Async Function Implementations
// ************************************************************

extern "C" void achWillSleepNotify(apiPacket_t *command, apiPacket_t *response)
{
	if (willSleepNotifyCallback == NULL)
	{
		return;
	}
	
	bool rc = true;
	
	willSleepNotifyCallback(rc);
}

extern "C" void achDidSleepNotify(apiPacket_t *command, apiPacket_t *response)
{
	if (didSleepNotifyCallback == NULL)
	{
		return;
	}
	
	bool rc = true;
	
	didSleepNotifyCallback(rc);
}

extern "C" void achBatteryVoltageStateChangeNotify(apiPacket_t *command, apiPacket_t *response)
{
	if (batteryVoltageStateChangeNotifyCallback == NULL)
	{
		return;
	}
	
	BatteryVoltageStateChangeNotifyReturn_t batteryVoltageStateChangeNotifyReturn;
	
	batteryVoltageStateChangeNotifyReturn.rc = true;
	
	batteryVoltageStateChangeNotifyReturn.state = static_cast<BatteryVoltageStates>(unpackUint8(command));
	batteryVoltageStateChangeNotifyCallback(&batteryVoltageStateChangeNotifyReturn);
}


// ************************************************************
// This file was automatically generated!
// Device ID (DID):         0x16
// Device Name:             drive
// Device Description:      
// Command Count:           8
// Source File:             0x16-driving.json
// ************************************************************

#include "drive.h"
#include "sphero_api.h"

// ************************************************************
// Private Response Function Prototypes
// ************************************************************

extern "C" void arhGetMotorFaultStateCallback(apiPacket_t *response);

// ************************************************************
// Private Async Function Prototypes
// ************************************************************

extern "C" void achMotorStallNotify(apiPacket_t *command, apiPacket_t *response);
extern "C" void achMotorFaultNotify(apiPacket_t *command, apiPacket_t *response);

// ************************************************************
// Private Data
// ************************************************************

static MotorStallNotifyCallback_t motorStallNotifyCallback;
static MotorFaultNotifyCallback_t motorFaultNotifyCallback;
static GetMotorFaultStateCallback_t getMotorFaultStateCallback;

static apiCommandDefinition_t apiCommands[] =
{
	{0x26, 2, achMotorStallNotify, API_COMMAND_DEFINITION_FLAG_NONE},
	{0x28, 1, achMotorFaultNotify, API_COMMAND_DEFINITION_FLAG_NONE}	
};

// ************************************************************
// Public Function Implementations
// ************************************************************

DriveDevice::DriveDevice(void)
{
}

void DriveDevice::configUART(HardwareSerial *port)
{
	initUartApi(port);
	ADD_API_COMMANDS(0x16, apiCommands);
}

void DriveDevice::rawMotors(RawMotorModes leftMode, uint8_t leftSpeed, RawMotorModes rightMode, uint8_t rightSpeed)
{
	apiPacket_t command;
	uint8_t params[4] = {0};
	setupApiCommand(&command, 0x16, 0x01, true, params);
	
	packUint8(&command, static_cast<uint8_t>(leftMode));
	packUint8(&command, leftSpeed);
	packUint8(&command, static_cast<uint8_t>(rightMode));
	packUint8(&command, rightSpeed);
	
	sendApiCommandToNode(RVR_API_NODE_ST, &command, NULL);
}

void DriveDevice::resetYaw()
{
	apiPacket_t command;
	setupApiCommand(&command, 0x16, 0x06, true, NULL);
	
	sendApiCommandToNode(RVR_API_NODE_ST, &command, NULL);
}

void DriveDevice::driveWithHeading(uint8_t speed, int16_t heading, uint8_t flags)
{
	apiPacket_t command;
	uint8_t params[4] = {0};
	setupApiCommand(&command, 0x16, 0x07, true, params);
	
	packUint8(&command, speed);
	packInt16(&command, heading);
	packUint8(&command, flags);
	
	sendApiCommandToNode(RVR_API_NODE_ST, &command, NULL);
}

void DriveDevice::enableMotorStallNotify(bool isEnabled, MotorStallNotifyCallback_t callback)
{
	motorStallNotifyCallback = NULL;
	
	if(isEnabled)
	{
		motorStallNotifyCallback = callback;
	}
	
	apiPacket_t command;
	uint8_t param = 0;
	setupApiCommand(&command, 0x16, 0x25, true, &param);
	
	packBool(&command, isEnabled);
	
	sendApiCommandToNode(RVR_API_NODE_ST, &command, NULL);
}

void DriveDevice::enableMotorFaultNotify(bool isEnabled, MotorFaultNotifyCallback_t callback)
{
	motorFaultNotifyCallback = NULL;
	
	if(isEnabled)
	{
		motorFaultNotifyCallback = callback;
	}
	
	apiPacket_t command;
	uint8_t param = 0;
	setupApiCommand(&command, 0x16, 0x27, true, &param);
	
	packBool(&command, isEnabled);
	
	sendApiCommandToNode(RVR_API_NODE_ST, &command, NULL);
}

void DriveDevice::getMotorFaultState(GetMotorFaultStateCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x16, 0x29, true, NULL);
	
	getMotorFaultStateCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_ST, &command, callback ? arhGetMotorFaultStateCallback : NULL);
}

// ************************************************************
// Private Response Function Implementations
// ************************************************************

extern "C" void arhGetMotorFaultStateCallback(apiPacket_t *response)
{
	if (getMotorFaultStateCallback == NULL)
	{
		return;
	}
	
	GetMotorFaultStateReturn_t getMotorFaultStateReturn;
	
	getMotorFaultStateReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getMotorFaultStateReturn.isFault = unpackBool(response);
	}
	
	getMotorFaultStateCallback(&getMotorFaultStateReturn);
}

// ************************************************************
// Private Async Function Implementations
// ************************************************************

extern "C" void achMotorStallNotify(apiPacket_t *command, apiPacket_t *response)
{
	if (motorStallNotifyCallback == NULL)
	{
		return;
	}
	
	MotorStallNotifyReturn_t motorStallNotifyReturn;
	
	motorStallNotifyReturn.isSuccessful = true;
	
	motorStallNotifyReturn.motorIndex = static_cast<MotorIndexes>(unpackUint8(command));
	motorStallNotifyReturn.isTriggered = unpackBool(command);
	motorStallNotifyCallback(&motorStallNotifyReturn);
}

extern "C" void achMotorFaultNotify(apiPacket_t *command, apiPacket_t *response)
{
	if (motorFaultNotifyCallback == NULL)
	{
		return;
	}
	
	MotorFaultNotifyReturn_t motorFaultNotifyReturn;
	
	motorFaultNotifyReturn.isSuccessful = true;
	
	motorFaultNotifyReturn.isFault = unpackBool(command);
	motorFaultNotifyCallback(&motorFaultNotifyReturn);
}


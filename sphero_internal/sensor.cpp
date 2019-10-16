// ************************************************************
// This file was automatically generated!
// Device ID (DID):         0x18
// Device Name:             sensor
// Device Description:      
// Command Count:           14
// Source File:             0x18-sensors.json
// ************************************************************

#include "sensor.h"
#include "sphero_api.h"

// ************************************************************
// Private Response Function Prototypes
// ************************************************************

extern "C" void arhGetRgbcSensorValuesCallback(apiPacket_t *response);
extern "C" void arhGetAmbientLightSensorValueCallback(apiPacket_t *response);
extern "C" void arhGetMotorTemperatureCallback(apiPacket_t *response);
extern "C" void arhGetMotorThermalProtectionStatusCallback(apiPacket_t *response);

// ************************************************************
// Private Async Function Prototypes
// ************************************************************

extern "C" void achGyroMaxNotify(apiPacket_t *command, apiPacket_t *response);
extern "C" void achColorDetectionNotify(apiPacket_t *command, apiPacket_t *response);
extern "C" void achMotorThermalProtectionStatusNotify(apiPacket_t *command, apiPacket_t *response);

// ************************************************************
// Private Data
// ************************************************************

static GyroMaxNotifyCallback_t gyroMaxNotifyCallback;
static GetRgbcSensorValuesCallback_t getRgbcSensorValuesCallback;
static GetAmbientLightSensorValueCallback_t getAmbientLightSensorValueCallback;
static ColorDetectionNotifyCallback_t colorDetectionNotifyCallback;
static GetMotorTemperatureCallback_t getMotorTemperatureCallback;
static GetMotorThermalProtectionStatusCallback_t getMotorThermalProtectionStatusCallback;
static MotorThermalProtectionStatusNotifyCallback_t motorThermalProtectionStatusNotifyCallback;

static apiCommandDefinition_t apiCommands[] =
{
	{0x10, 1, achGyroMaxNotify, API_COMMAND_DEFINITION_FLAG_NONE},
	{0x36, 5, achColorDetectionNotify, API_COMMAND_DEFINITION_FLAG_NONE},
	{0x4D, 2, achMotorThermalProtectionStatusNotify, API_COMMAND_DEFINITION_FLAG_NONE}	
};

// ************************************************************
// Public Function Implementations
// ************************************************************

SensorDevice::SensorDevice(void)
{
}

void SensorDevice::configUART(HardwareSerial *port)
{
	initUartApi(port);
	ADD_API_COMMANDS(0x18, apiCommands);
}

void SensorDevice::enableGyroMaxNotify(bool isEnabled, GyroMaxNotifyCallback_t callback)
{
	gyroMaxNotifyCallback = NULL;
	
	if(isEnabled)
	{
		gyroMaxNotifyCallback = callback;
	}
	
	apiPacket_t command;
	uint8_t param = 0;
	setupApiCommand(&command, 0x18, 0x0F, true, &param);
	
	packBool(&command, isEnabled);
	
	sendApiCommandToNode(RVR_API_NODE_ST, &command, NULL);
}

void SensorDevice::resetLocatorXAndY()
{
	apiPacket_t command;
	setupApiCommand(&command, 0x18, 0x13, true, NULL);
	
	sendApiCommandToNode(RVR_API_NODE_ST, &command, NULL);
}

void SensorDevice::setLocatorFlags(uint8_t flags)
{
	apiPacket_t command;
	uint8_t param = 0;
	setupApiCommand(&command, 0x18, 0x17, true, &param);
	
	packUint8(&command, flags);
	
	sendApiCommandToNode(RVR_API_NODE_ST, &command, NULL);
}

void SensorDevice::getRgbcSensorValues(GetRgbcSensorValuesCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x18, 0x23, true, NULL);
	
	getRgbcSensorValuesCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetRgbcSensorValuesCallback : NULL);
}

void SensorDevice::getAmbientLightSensorValue(GetAmbientLightSensorValueCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x18, 0x30, true, NULL);
	
	getAmbientLightSensorValueCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, callback ? arhGetAmbientLightSensorValueCallback : NULL);
}

void SensorDevice::enableColorDetectionNotify(bool isEnabled, uint16_t interval, uint8_t minimumConfidenceThreshold, ColorDetectionNotifyCallback_t callback)
{
	colorDetectionNotifyCallback = NULL;
	
	if(isEnabled)
	{
		colorDetectionNotifyCallback = callback;
	}
	
	apiPacket_t command;
	uint8_t params[4] = {0};
	setupApiCommand(&command, 0x18, 0x35, true, params);
	
	packBool(&command, isEnabled);
	packUint16(&command, interval);
	packUint8(&command, minimumConfidenceThreshold);
	
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, NULL);
}

void SensorDevice::getCurrentDetectedColorReading()
{
	apiPacket_t command;
	setupApiCommand(&command, 0x18, 0x37, true, NULL);
	
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, NULL);
}

void SensorDevice::enableColorDetection(bool isEnabled)
{
	apiPacket_t command;
	uint8_t param = 0;
	setupApiCommand(&command, 0x18, 0x38, true, &param);
	
	packBool(&command, isEnabled);
	
	sendApiCommandToNode(RVR_API_NODE_NORDIC, &command, NULL);
}

void SensorDevice::getMotorTemperature(MotorIndexes motorIndex, GetMotorTemperatureCallback_t callback)
{
	apiPacket_t command;
	uint8_t param = 0;
	setupApiCommand(&command, 0x18, 0x42, true, &param);
	
	packUint8(&command, static_cast<uint8_t>(motorIndex));
	
	getMotorTemperatureCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_ST, &command, callback ? arhGetMotorTemperatureCallback : NULL);
}

void SensorDevice::getMotorThermalProtectionStatus(GetMotorThermalProtectionStatusCallback_t callback)
{
	apiPacket_t command;
	setupApiCommand(&command, 0x18, 0x4B, true, NULL);
	
	getMotorThermalProtectionStatusCallback = callback;
	sendApiCommandToNode(RVR_API_NODE_ST, &command, callback ? arhGetMotorThermalProtectionStatusCallback : NULL);
}

void SensorDevice::enableMotorThermalProtectionStatusNotify(bool isEnabled, MotorThermalProtectionStatusNotifyCallback_t callback)
{
	motorThermalProtectionStatusNotifyCallback = NULL;
	
	if(isEnabled)
	{
		motorThermalProtectionStatusNotifyCallback = callback;
	}
	
	apiPacket_t command;
	uint8_t param = 0;
	setupApiCommand(&command, 0x18, 0x4C, true, &param);
	
	packBool(&command, isEnabled);
	
	sendApiCommandToNode(RVR_API_NODE_ST, &command, NULL);
}

// ************************************************************
// Private Response Function Implementations
// ************************************************************

extern "C" void arhGetRgbcSensorValuesCallback(apiPacket_t *response)
{
	if (getRgbcSensorValuesCallback == NULL)
	{
		return;
	}
	
	GetRgbcSensorValuesReturn_t getRgbcSensorValuesReturn;
	
	getRgbcSensorValuesReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getRgbcSensorValuesReturn.redChannelValue = unpackUint16(response);
		getRgbcSensorValuesReturn.greenChannelValue = unpackUint16(response);
		getRgbcSensorValuesReturn.blueChannelValue = unpackUint16(response);
		getRgbcSensorValuesReturn.clearChannelValue = unpackUint16(response);
	}
	
	getRgbcSensorValuesCallback(&getRgbcSensorValuesReturn);
}

extern "C" void arhGetAmbientLightSensorValueCallback(apiPacket_t *response)
{
	if (getAmbientLightSensorValueCallback == NULL)
	{
		return;
	}
	
	GetAmbientLightSensorValueReturn_t getAmbientLightSensorValueReturn;
	
	getAmbientLightSensorValueReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getAmbientLightSensorValueReturn.ambientLightValue = unpackFloat(response);
	}
	
	getAmbientLightSensorValueCallback(&getAmbientLightSensorValueReturn);
}

extern "C" void arhGetMotorTemperatureCallback(apiPacket_t *response)
{
	if (getMotorTemperatureCallback == NULL)
	{
		return;
	}
	
	GetMotorTemperatureReturn_t getMotorTemperatureReturn;
	
	getMotorTemperatureReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getMotorTemperatureReturn.windingCoilTemperature = unpackFloat(response);
		getMotorTemperatureReturn.caseTemperature = unpackFloat(response);
	}
	
	getMotorTemperatureCallback(&getMotorTemperatureReturn);
}

extern "C" void arhGetMotorThermalProtectionStatusCallback(apiPacket_t *response)
{
	if (getMotorThermalProtectionStatusCallback == NULL)
	{
		return;
	}
	
	GetMotorThermalProtectionStatusReturn_t getMotorThermalProtectionStatusReturn;
	
	getMotorThermalProtectionStatusReturn.isSuccessful = (response->errorCode == API_SUCCESS);
	
	if (response->errorCode == API_SUCCESS)
	{
		getMotorThermalProtectionStatusReturn.leftMotorTemperature = unpackFloat(response);
		getMotorThermalProtectionStatusReturn.leftMotorStatus = static_cast<ThermalProtectionStatus>(unpackUint8(response));
		getMotorThermalProtectionStatusReturn.rightMotorTemperature = unpackFloat(response);
		getMotorThermalProtectionStatusReturn.rightMotorStatus = static_cast<ThermalProtectionStatus>(unpackUint8(response));
	}
	
	getMotorThermalProtectionStatusCallback(&getMotorThermalProtectionStatusReturn);
}

// ************************************************************
// Private Async Function Implementations
// ************************************************************

extern "C" void achGyroMaxNotify(apiPacket_t *command, apiPacket_t *response)
{
	if (gyroMaxNotifyCallback == NULL)
	{
		return;
	}
	
	GyroMaxNotifyReturn_t gyroMaxNotifyReturn;
	
	gyroMaxNotifyReturn.isSuccessful = true;
	
	gyroMaxNotifyReturn.flags = unpackUint8(command);
	gyroMaxNotifyCallback(&gyroMaxNotifyReturn);
}

extern "C" void achColorDetectionNotify(apiPacket_t *command, apiPacket_t *response)
{
	if (colorDetectionNotifyCallback == NULL)
	{
		return;
	}
	
	ColorDetectionNotifyReturn_t colorDetectionNotifyReturn;
	
	colorDetectionNotifyReturn.isSuccessful = true;
	
	colorDetectionNotifyReturn.red = unpackUint8(command);
	colorDetectionNotifyReturn.green = unpackUint8(command);
	colorDetectionNotifyReturn.blue = unpackUint8(command);
	colorDetectionNotifyReturn.confidence = unpackUint8(command);
	colorDetectionNotifyReturn.colorClassificationId = unpackUint8(command);
	colorDetectionNotifyCallback(&colorDetectionNotifyReturn);
}

extern "C" void achMotorThermalProtectionStatusNotify(apiPacket_t *command, apiPacket_t *response)
{
	if (motorThermalProtectionStatusNotifyCallback == NULL)
	{
		return;
	}
	
	MotorThermalProtectionStatusNotifyReturn_t motorThermalProtectionStatusNotifyReturn;
	
	motorThermalProtectionStatusNotifyReturn.isSuccessful = true;
	
	motorThermalProtectionStatusNotifyReturn.leftMotorTemperature = unpackFloat(command);
	motorThermalProtectionStatusNotifyReturn.leftMotorStatus = static_cast<ThermalProtectionStatus>(unpackUint8(command));
	motorThermalProtectionStatusNotifyReturn.rightMotorTemperature = unpackFloat(command);
	motorThermalProtectionStatusNotifyReturn.rightMotorStatus = static_cast<ThermalProtectionStatus>(unpackUint8(command));
	motorThermalProtectionStatusNotifyCallback(&motorThermalProtectionStatusNotifyReturn);
}


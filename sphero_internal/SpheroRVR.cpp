// ************************************************************
// This file was automatically generated!
// ID:                      16
// Name:                    Sphero RVR
// Prefix:                  RV
// Command Count:           45
// ************************************************************

#include "io.h"
#include "drive.h"
#include "sensor.h"
#include "power.h"
#include "connection.h"
#include "system_info.h"
#include "SpheroRVR.h"
#include "sphero_api.h"

IoDevice _io;
DriveDevice _drive;
SensorDevice _sensor;
PowerDevice _power;
ConnectionDevice _connection;
SystemInfoDevice _systemInfo;

DriveControl _driveControl;
LedControl _ledControl;

SpheroRVR::SpheroRVR(void)
{
}

DriveControl SpheroRVR::getDriveControl()
{
	return _driveControl;
}

LedControl SpheroRVR::getLedControl()
{
	return _ledControl;
}

void SpheroRVR::configUART(HardwareSerial *port)
{
	_io.configUART(port);
	_drive.configUART(port);
	_sensor.configUART(port);
	_power.configUART(port);
	_connection.configUART(port);
	_systemInfo.configUART(port);
}

void SpheroRVR::poll(void)
{
	serviceUartApi();
}

void SpheroRVR::setAllLeds(uint32_t ledGroup, uint8_t ledBrightnessValues[], int ledBrightnessValuesArraySize)
{
	_io.setAllLeds(ledGroup, ledBrightnessValues, ledBrightnessValuesArraySize);
}

void SpheroRVR::releaseLedRequests()
{
	_io.releaseLedRequests();
}

void SpheroRVR::rawMotors(RawMotorModes leftMode, uint8_t leftSpeed, RawMotorModes rightMode, uint8_t rightSpeed)
{
	_drive.rawMotors(leftMode, leftSpeed, rightMode, rightSpeed);
}

void SpheroRVR::resetYaw()
{
	_drive.resetYaw();
}

void SpheroRVR::driveWithHeading(uint8_t speed, int16_t heading, uint8_t flags)
{
	_drive.driveWithHeading(speed, heading, flags);
}

void SpheroRVR::enableMotorStallNotify(bool isEnabled, MotorStallNotifyCallback_t callback)
{
	_drive.enableMotorStallNotify(isEnabled, callback);
}

void SpheroRVR::enableMotorFaultNotify(bool isEnabled, MotorFaultNotifyCallback_t callback)
{
	_drive.enableMotorFaultNotify(isEnabled, callback);
}

void SpheroRVR::getMotorFaultState(GetMotorFaultStateCallback_t callback)
{
	_drive.getMotorFaultState(callback);
}

void SpheroRVR::enableGyroMaxNotify(bool isEnabled, GyroMaxNotifyCallback_t callback)
{
	_sensor.enableGyroMaxNotify(isEnabled, callback);
}

void SpheroRVR::resetLocatorXAndY()
{
	_sensor.resetLocatorXAndY();
}

void SpheroRVR::setLocatorFlags(uint8_t flags)
{
	_sensor.setLocatorFlags(flags);
}

void SpheroRVR::getRgbcSensorValues(GetRgbcSensorValuesCallback_t callback)
{
	_sensor.getRgbcSensorValues(callback);
}

void SpheroRVR::getAmbientLightSensorValue(GetAmbientLightSensorValueCallback_t callback)
{
	_sensor.getAmbientLightSensorValue(callback);
}

void SpheroRVR::enableColorDetectionNotify(bool isEnabled, uint16_t interval, uint8_t minimumConfidenceThreshold, ColorDetectionNotifyCallback_t callback)
{
	_sensor.enableColorDetectionNotify(isEnabled, interval, minimumConfidenceThreshold, callback);
}

void SpheroRVR::getCurrentDetectedColorReading()
{
	_sensor.getCurrentDetectedColorReading();
}

void SpheroRVR::enableColorDetection(bool isEnabled)
{
	_sensor.enableColorDetection(isEnabled);
}

void SpheroRVR::getMotorTemperature(MotorIndexes motorIndex, GetMotorTemperatureCallback_t callback)
{
	_sensor.getMotorTemperature(motorIndex, callback);
}

void SpheroRVR::getMotorThermalProtectionStatus(GetMotorThermalProtectionStatusCallback_t callback)
{
	_sensor.getMotorThermalProtectionStatus(callback);
}

void SpheroRVR::enableMotorThermalProtectionStatusNotify(bool isEnabled, MotorThermalProtectionStatusNotifyCallback_t callback)
{
	_sensor.enableMotorThermalProtectionStatusNotify(isEnabled, callback);
}

void SpheroRVR::enterDeepSleep(uint8_t secondsUntilDeepSleep)
{
	_power.enterDeepSleep(secondsUntilDeepSleep);
}

void SpheroRVR::sleep()
{
	_power.sleep();
}

void SpheroRVR::wake()
{
	_power.wake();
}

void SpheroRVR::getBatteryPercentage(GetBatteryPercentageCallback_t callback)
{
	_power.getBatteryPercentage(callback);
}

void SpheroRVR::getBatteryVoltageState(GetBatteryVoltageStateCallback_t callback)
{
	_power.getBatteryVoltageState(callback);
}

void SpheroRVR::setWillSleepNotifyCallback(WillSleepNotifyCallback_t callback)
{
	_power.setWillSleepNotifyCallback(callback);
}

void SpheroRVR::setDidSleepNotifyCallback(DidSleepNotifyCallback_t callback)
{
	_power.setDidSleepNotifyCallback(callback);
}

void SpheroRVR::enableBatteryVoltageStateChangeNotify(bool isEnabled, BatteryVoltageStateChangeNotifyCallback_t callback)
{
	_power.enableBatteryVoltageStateChangeNotify(isEnabled, callback);
}

void SpheroRVR::getBatteryVoltageInVolts(BatteryVoltageReadingTypes readingType, GetBatteryVoltageInVoltsCallback_t callback)
{
	_power.getBatteryVoltageInVolts(readingType, callback);
}

void SpheroRVR::getBatteryVoltageStateThresholds(GetBatteryVoltageStateThresholdsCallback_t callback)
{
	_power.getBatteryVoltageStateThresholds(callback);
}

void SpheroRVR::getCurrentSenseAmplifierCurrent(AmplifierIds amplifierId, GetCurrentSenseAmplifierCurrentCallback_t callback)
{
	_power.getCurrentSenseAmplifierCurrent(amplifierId, callback);
}

void SpheroRVR::getBluetoothAdvertisingName(GetBluetoothAdvertisingNameCallback_t callback)
{
	_connection.getBluetoothAdvertisingName(callback);
}

void SpheroRVR::getMainApplicationVersion(uint8_t target, GetMainApplicationVersionCallback_t callback)
{
	_systemInfo.getMainApplicationVersion(target, callback);
}

void SpheroRVR::getBootloaderVersion(uint8_t target, GetBootloaderVersionCallback_t callback)
{
	_systemInfo.getBootloaderVersion(target, callback);
}

void SpheroRVR::getBoardRevision(GetBoardRevisionCallback_t callback)
{
	_systemInfo.getBoardRevision(callback);
}

void SpheroRVR::getMacAddress(GetMacAddressCallback_t callback)
{
	_systemInfo.getMacAddress(callback);
}

void SpheroRVR::getStatsId(GetStatsIdCallback_t callback)
{
	_systemInfo.getStatsId(callback);
}

void SpheroRVR::getProcessorName(uint8_t target, GetProcessorNameCallback_t callback)
{
	_systemInfo.getProcessorName(target, callback);
}

void SpheroRVR::getSku(GetSkuCallback_t callback)
{
	_systemInfo.getSku(callback);
}

void SpheroRVR::getCoreUpTimeInMilliseconds(GetCoreUpTimeInMillisecondsCallback_t callback)
{
	_systemInfo.getCoreUpTimeInMilliseconds(callback);
}

SpheroRVR rvr;

// ************************************************************
// This file was automatically generated!
// Device ID (DID):         0x18
// Device Name:             sensor
// Device Description:      
// Command Count:           14
// Source File:             0x18-sensors.json
// ************************************************************

#ifndef SENSOR_H
#define SENSOR_H

#include "Arduino.h"
#include "structs.h"

class SensorDevice
{
	public:
		SensorDevice(void);
		
		void configUART(HardwareSerial *port);
		
		void enableGyroMaxNotify(bool isEnabled, GyroMaxNotifyCallback_t callback);
		
		void resetLocatorXAndY();
		
		void setLocatorFlags(uint8_t flags);
		
		void getRgbcSensorValues(GetRgbcSensorValuesCallback_t callback);
		
		void getAmbientLightSensorValue(GetAmbientLightSensorValueCallback_t callback);
		
		void enableColorDetectionNotify(bool isEnabled, uint16_t interval, uint8_t minimumConfidenceThreshold, ColorDetectionNotifyCallback_t callback);
		
		void getCurrentDetectedColorReading();
		
		void enableColorDetection(bool isEnabled);
		
		void getMotorTemperature(MotorIndexes motorIndex, GetMotorTemperatureCallback_t callback);
		
		void getMotorThermalProtectionStatus(GetMotorThermalProtectionStatusCallback_t callback);
		
		void enableMotorThermalProtectionStatusNotify(bool isEnabled, MotorThermalProtectionStatusNotifyCallback_t callback);
		
	private:
};

#endif

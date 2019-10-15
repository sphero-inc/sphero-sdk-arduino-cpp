#ifndef RVR_H
#define RVR_H

#include "Arduino.h"
#include "structs.h"
#include "DriveControl.h"
#include "LedControl.h"

class SpheroRVR
{
	public:
		SpheroRVR(void);
		
		DriveControl getDriveControl();
		
		LedControl getLedControl();
		
		void configUART(HardwareSerial *port);
		
		void poll();
		
		void setAllLeds(uint32_t ledGroup, uint8_t ledBrightnessValues[], int ledBrightnessValuesArraySize);
		
		void releaseLedRequests();
		
		void rawMotors(RawMotorModes leftMode, uint8_t leftSpeed, RawMotorModes rightMode, uint8_t rightSpeed);
		
		void resetYaw();
		
		void driveWithHeading(uint8_t speed, int16_t heading, uint8_t flags);
		
		void enableMotorStallNotify(bool isEnabled, MotorStallNotifyCallback_t callback);
		
		void enableMotorFaultNotify(bool isEnabled, MotorFaultNotifyCallback_t callback);
		
		void getMotorFaultState(GetMotorFaultStateCallback_t callback);
		
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
		
		void enterDeepSleep(uint8_t secondsUntilDeepSleep);
		
		void sleep();
		
		void wake();
		
		void getBatteryPercentage(GetBatteryPercentageCallback_t callback);
		
		void getBatteryVoltageState(GetBatteryVoltageStateCallback_t callback);
		
		void setWillSleepNotifyCallback(WillSleepNotifyCallback_t callback);
		
		void setDidSleepNotifyCallback(DidSleepNotifyCallback_t callback);
		
		void enableBatteryVoltageStateChangeNotify(bool isEnabled, BatteryVoltageStateChangeNotifyCallback_t callback);
		
		void getBatteryVoltageInVolts(BatteryVoltageReadingTypes readingType, GetBatteryVoltageInVoltsCallback_t callback);
		
		void getBatteryVoltageStateThresholds(GetBatteryVoltageStateThresholdsCallback_t callback);
		
		void getCurrentSenseAmplifierCurrent(AmplifierIds amplifierId, GetCurrentSenseAmplifierCurrentCallback_t callback);
		
		void getBluetoothAdvertisingName(GetBluetoothAdvertisingNameCallback_t callback);
		
		void getMainApplicationVersion(uint8_t target, GetMainApplicationVersionCallback_t callback);
		
		void getBootloaderVersion(uint8_t target, GetBootloaderVersionCallback_t callback);
		
		void getBoardRevision(GetBoardRevisionCallback_t callback);
		
		void getMacAddress(GetMacAddressCallback_t callback);
		
		void getStatsId(GetStatsIdCallback_t callback);
		
		void getProcessorName(uint8_t target, GetProcessorNameCallback_t callback);
		
		void getSku(GetSkuCallback_t callback);
		
		void getCoreUpTimeInMilliseconds(GetCoreUpTimeInMillisecondsCallback_t callback);
		
	private:
};

extern SpheroRVR rvr;

#endif

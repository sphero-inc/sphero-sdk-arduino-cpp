// ************************************************************
// This file was automatically generated!
// Device ID (DID):         0x13
// Device Name:             power
// Device Description:      
// Command Count:           12
// Source File:             0x13-power.json
// ************************************************************

#ifndef POWER_H
#define POWER_H

#include "Arduino.h"
#include "structs.h"

class PowerDevice
{
	public:
		PowerDevice(void);
		
		void configUART(HardwareSerial *port);
		
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
		
	private:
};

#endif

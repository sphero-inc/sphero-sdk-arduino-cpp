// ************************************************************
// This file was automatically generated!
// Device ID (DID):         0x16
// Device Name:             drive
// Device Description:      
// Command Count:           8
// Source File:             0x16-driving.json
// ************************************************************

#ifndef DRIVE_H
#define DRIVE_H

#include "Arduino.h"
#include "structs.h"

class DriveDevice
{
	public:
		DriveDevice(void);
		
		void configUART(HardwareSerial *port);
		
		void rawMotors(RawMotorModes leftMode, uint8_t leftSpeed, RawMotorModes rightMode, uint8_t rightSpeed);
		
		void resetYaw();
		
		void driveWithHeading(uint8_t speed, int16_t heading, uint8_t flags);
		
		void enableMotorStallNotify(bool isEnabled, MotorStallNotifyCallback_t callback);
		
		void enableMotorFaultNotify(bool isEnabled, MotorFaultNotifyCallback_t callback);
		
		void getMotorFaultState(GetMotorFaultStateCallback_t callback);
		
	private:
};

#endif

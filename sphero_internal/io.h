// ************************************************************
// This file was automatically generated!
// Device ID (DID):         0x1A
// Device Name:             io
// Device Description:      
// Command Count:           2
// Source File:             0x1A-user_io.json
// ************************************************************

#ifndef IO_H
#define IO_H

#include "Arduino.h"
#include "structs.h"

class IoDevice
{
	public:
		IoDevice(void);
		
		void configUART(HardwareSerial *port);
		
		void setAllLeds(uint32_t ledGroup, uint8_t ledBrightnessValues[], int ledBrightnessValuesArraySize);
		
		void releaseLedRequests();
		
	private:
};

#endif

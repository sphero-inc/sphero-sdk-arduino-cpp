// ************************************************************
// This file was automatically generated!
// Device ID (DID):         0x11
// Device Name:             system_info
// Device Description:      
// Command Count:           8
// Source File:             0x11-system_info.json
// ************************************************************

#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

#include "Arduino.h"
#include "structs.h"

class SystemInfoDevice
{
	public:
		SystemInfoDevice(void);
		
		void configUART(HardwareSerial *port);
		
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

#endif

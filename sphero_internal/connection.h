// ************************************************************
// This file was automatically generated!
// Device ID (DID):         0x19
// Device Name:             connection
// Device Description:      
// Command Count:           1
// Source File:             0x19-peer_connection.json
// ************************************************************

#ifndef CONNECTION_H
#define CONNECTION_H

#include "Arduino.h"
#include "structs.h"

class ConnectionDevice
{
	public:
		ConnectionDevice(void);
		
		void configUART(HardwareSerial *port);
		
		void getBluetoothAdvertisingName(GetBluetoothAdvertisingNameCallback_t callback);
		
	private:
};

#endif

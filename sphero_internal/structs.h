#ifndef STRUCTS
#define STRUCTS

// ************************************************************
// Enums
// ************************************************************

enum struct RawMotorModes : uint8_t
{
	off, 
	forward, 
	reverse, 
};

enum struct MotorIndexes : uint8_t
{
	leftMotorIndex, 
	rightMotorIndex, 
};

enum struct ThermalProtectionStatus : uint8_t
{
	ok, 
	warn, 
	critical, 
};

enum struct BatteryVoltageReadingTypes : uint8_t
{
	calibratedAndFiltered, 
	calibratedAndUnfiltered, 
	uncalibratedAndUnfiltered, 
};

enum struct AmplifierIds : uint8_t
{
	leftMotor, 
	rightMotor, 
};

enum struct BatteryVoltageStates : uint8_t
{
	unknown, 
	ok, 
	low, 
	critical, 
};

enum struct LEDs : uint8_t
{
	rightHeadlightRed = 0, 
	rightHeadlightGreen = 1, 
	rightHeadlightBlue = 2, 
	leftHeadlightRed = 3, 
	leftHeadlightGreen = 4, 
	leftHeadlightBlue = 5, 
	leftStatusIndicationRed = 6, 
	leftStatusIndicationGreen = 7, 
	leftStatusIndicationBlue = 8, 
	rightStatusIndicationRed = 9, 
	rightStatusIndicationGreen = 10, 
	rightStatusIndicationBlue = 11, 
	batteryDoorRearRed = 12, 
	batteryDoorRearGreen = 13, 
	batteryDoorRearBlue = 14, 
	batteryDoorFrontRed = 15, 
	batteryDoorFrontGreen = 16, 
	batteryDoorFrontBlue = 17, 
	powerButtonFrontRed = 18, 
	powerButtonFrontGreen = 19, 
	powerButtonFrontBlue = 20, 
	powerButtonRearRed = 21, 
	powerButtonRearGreen = 22, 
	powerButtonRearBlue = 23, 
	leftBrakelightRed = 24, 
	leftBrakelightGreen = 25, 
	leftBrakelightBlue = 26, 
	rightBrakelightRed = 27, 
	rightBrakelightGreen = 28, 
	rightBrakelightBlue = 29, 
	undercarriageWhite = 30, 
};

enum struct Processors : uint8_t
{
	nordic = 0x1, 
	st = 0x2, 
};

// ************************************************************
// Bitmasks
// ************************************************************

enum struct DriveFlags : uint8_t
{
	none = 0,
	driveReverse = 1 << 0,
	boost = 1 << 1,
	fastTurn = 1 << 2,
	leftDirection = 1 << 3,
	rightDirection = 1 << 4,
	enableDrift = 1 << 5,
};

enum struct GyroMaxFlags : uint8_t
{
	none = 0,
	maxPlusX = 1 << 0,
	maxMinusX = 1 << 1,
	maxPlusY = 1 << 2,
	maxMinusY = 1 << 3,
	maxPlusZ = 1 << 4,
	maxMinusZ = 1 << 5,
};

enum struct LocatorFlags : uint8_t
{
	none = 0,
	autoCalibrate = 1 << 0,
};

// ************************************************************
// Type Structs
// ************************************************************

typedef struct
{
	bool isSuccessful;
	MotorIndexes motorIndex;
	bool isTriggered;
} MotorStallNotifyReturn_t;

typedef struct
{
	bool isSuccessful;
	bool isFault;
} MotorFaultNotifyReturn_t;

typedef struct
{
	bool isSuccessful;
	bool isFault;
} GetMotorFaultStateReturn_t;

typedef struct
{
	bool isSuccessful;
	uint8_t flags;
} GyroMaxNotifyReturn_t;

typedef struct
{
	bool isSuccessful;
	uint16_t redChannelValue;
	uint16_t greenChannelValue;
	uint16_t blueChannelValue;
	uint16_t clearChannelValue;
} GetRgbcSensorValuesReturn_t;

typedef struct
{
	bool isSuccessful;
	float ambientLightValue;
} GetAmbientLightSensorValueReturn_t;

typedef struct
{
	bool isSuccessful;
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t confidence;
	uint8_t colorClassificationId;
} ColorDetectionNotifyReturn_t;

typedef struct
{
	bool isSuccessful;
	float windingCoilTemperature;
	float caseTemperature;
} GetMotorTemperatureReturn_t;

typedef struct
{
	bool isSuccessful;
	float leftMotorTemperature;
	ThermalProtectionStatus leftMotorStatus;
	float rightMotorTemperature;
	ThermalProtectionStatus rightMotorStatus;
} GetMotorThermalProtectionStatusReturn_t;

typedef struct
{
	bool isSuccessful;
	float leftMotorTemperature;
	ThermalProtectionStatus leftMotorStatus;
	float rightMotorTemperature;
	ThermalProtectionStatus rightMotorStatus;
} MotorThermalProtectionStatusNotifyReturn_t;

typedef struct
{
	bool isSuccessful;
	uint8_t percentage;
} GetBatteryPercentageReturn_t;

typedef struct
{
	bool isSuccessful;
	BatteryVoltageStates state;
} GetBatteryVoltageStateReturn_t;

typedef struct
{
	bool isSuccessful;
	BatteryVoltageStates state;
} BatteryVoltageStateChangeNotifyReturn_t;

typedef struct
{
	bool isSuccessful;
	float voltage;
} GetBatteryVoltageInVoltsReturn_t;

typedef struct
{
	bool isSuccessful;
	float criticalThreshold;
	float lowThreshold;
	float hysteresis;
} GetBatteryVoltageStateThresholdsReturn_t;

typedef struct
{
	bool isSuccessful;
	float amplifierCurrent;
} GetCurrentSenseAmplifierCurrentReturn_t;

typedef struct
{
	bool isSuccessful;
	char aName[50];
} GetBluetoothAdvertisingNameReturn_t;

typedef struct
{
	bool isSuccessful;
	uint16_t major;
	uint16_t minor;
	uint16_t revision;
} GetMainApplicationVersionReturn_t;

typedef struct
{
	bool isSuccessful;
	uint16_t major;
	uint16_t minor;
	uint16_t revision;
} GetBootloaderVersionReturn_t;

typedef struct
{
	bool isSuccessful;
	uint8_t revision;
} GetBoardRevisionReturn_t;

typedef struct
{
	bool isSuccessful;
	char macAddress[50];
} GetMacAddressReturn_t;

typedef struct
{
	bool isSuccessful;
	uint16_t statsId;
} GetStatsIdReturn_t;

typedef struct
{
	bool isSuccessful;
	char aName[50];
} GetProcessorNameReturn_t;

typedef struct
{
	bool isSuccessful;
	char sku[50];
} GetSkuReturn_t;

typedef struct
{
	bool isSuccessful;
	uint64_t upTime;
} GetCoreUpTimeInMillisecondsReturn_t;

// ************************************************************
// Callbacks
// ************************************************************

typedef void (*MotorStallNotifyCallback_t)(MotorStallNotifyReturn_t *motorStallNotify);

typedef void (*MotorFaultNotifyCallback_t)(MotorFaultNotifyReturn_t *motorFaultNotify);

typedef void (*GetMotorFaultStateCallback_t)(GetMotorFaultStateReturn_t *getMotorFaultState);

typedef void (*GyroMaxNotifyCallback_t)(GyroMaxNotifyReturn_t *gyroMaxNotify);

typedef void (*GetRgbcSensorValuesCallback_t)(GetRgbcSensorValuesReturn_t *getRgbcSensorValues);

typedef void (*GetAmbientLightSensorValueCallback_t)(GetAmbientLightSensorValueReturn_t *getAmbientLightSensorValue);

typedef void (*ColorDetectionNotifyCallback_t)(ColorDetectionNotifyReturn_t *colorDetectionNotify);

typedef void (*GetMotorTemperatureCallback_t)(GetMotorTemperatureReturn_t *getMotorTemperature);

typedef void (*GetMotorThermalProtectionStatusCallback_t)(GetMotorThermalProtectionStatusReturn_t *getMotorThermalProtectionStatus);

typedef void (*MotorThermalProtectionStatusNotifyCallback_t)(MotorThermalProtectionStatusNotifyReturn_t *motorThermalProtectionStatusNotify);

typedef void (*GetBatteryPercentageCallback_t)(GetBatteryPercentageReturn_t *getBatteryPercentage);

typedef void (*GetBatteryVoltageStateCallback_t)(GetBatteryVoltageStateReturn_t *getBatteryVoltageState);

typedef void (*WillSleepNotifyCallback_t)(bool isSuccessful);

typedef void (*DidSleepNotifyCallback_t)(bool isSuccessful);

typedef void (*BatteryVoltageStateChangeNotifyCallback_t)(BatteryVoltageStateChangeNotifyReturn_t *batteryVoltageStateChangeNotify);

typedef void (*GetBatteryVoltageInVoltsCallback_t)(GetBatteryVoltageInVoltsReturn_t *getBatteryVoltageInVolts);

typedef void (*GetBatteryVoltageStateThresholdsCallback_t)(GetBatteryVoltageStateThresholdsReturn_t *getBatteryVoltageStateThresholds);

typedef void (*GetCurrentSenseAmplifierCurrentCallback_t)(GetCurrentSenseAmplifierCurrentReturn_t *getCurrentSenseAmplifierCurrent);

typedef void (*GetBluetoothAdvertisingNameCallback_t)(GetBluetoothAdvertisingNameReturn_t *getBluetoothAdvertisingName);

typedef void (*GetMainApplicationVersionCallback_t)(GetMainApplicationVersionReturn_t *getMainApplicationVersion);

typedef void (*GetBootloaderVersionCallback_t)(GetBootloaderVersionReturn_t *getBootloaderVersion);

typedef void (*GetBoardRevisionCallback_t)(GetBoardRevisionReturn_t *getBoardRevision);

typedef void (*GetMacAddressCallback_t)(GetMacAddressReturn_t *getMacAddress);

typedef void (*GetStatsIdCallback_t)(GetStatsIdReturn_t *getStatsId);

typedef void (*GetProcessorNameCallback_t)(GetProcessorNameReturn_t *getProcessorName);

typedef void (*GetSkuCallback_t)(GetSkuReturn_t *getSku);

typedef void (*GetCoreUpTimeInMillisecondsCallback_t)(GetCoreUpTimeInMillisecondsReturn_t *getCoreUpTimeInMilliseconds);

#endif

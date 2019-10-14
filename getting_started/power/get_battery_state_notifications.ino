#include <SpheroRVR.h>

static void batteryVoltageStateChangeNotifyCallback(BatteryVoltageStateChangeNotifyReturn_t *batteryVoltageStateChangeReturn);

void setup() {
    // set up communication with the RVR
    rvr.configUART(&Serial);
    
    // enable notifications for battery voltage state changes
    rvr.enableBatteryVoltageStateChangeNotify(true, batteryVoltageStateChangeNotifyCallback);
}

void loop() {
    // must include this line if expecting a response from the RVR
    rvr.poll();
}

static void batteryVoltageStateChangeNotifyCallback(BatteryVoltageStateChangeNotifyReturn_t *batteryVoltageStateChangeReturn)
{
    // put your code here to run when you get a battery voltage state change notification
}
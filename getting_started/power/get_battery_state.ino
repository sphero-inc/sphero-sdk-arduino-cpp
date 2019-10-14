#include <SpheroRVR.h>

static void getBatteryVoltageStateCallback(GetBatteryVoltageStateReturn_t *batteryVoltageStateReturn);

void setup() {
    // set up communication with the RVR
    rvr.configUART(&Serial);
    
    // give RVR time to wake up
    delay(2000);
    
    // get the battery voltage state
    rvr.getBatteryVoltageState(getBatteryVoltageStateCallback);
}

void loop() {
    // must include this line if expecting a response from the RVR
    rvr.poll();
}

static void getBatteryVoltageStateCallback(GetBatteryVoltageStateReturn_t *batteryVoltageStateReturn)
{
    // put your code here to run when you get the battery voltage state
}
#include <SpheroRVR.h>

void setup() {
    // set up communication with the RVR
    rvr.configUART(&Serial);
}

void loop() {
    // reset the heading to zero
    rvr.resetYaw();
    
    // drive forward with speed 64 on both motors
    rvr.rawMotors(RawMotorModes::forward, 64, RawMotorModes::forward, 64);
    delay(1000);
    
    // drive backward with speed 32 on both motors
    rvr.rawMotors(RawMotorModes::reverse, 32, RawMotorModes::reverse, 32);
    delay(1000);
    
    // drive backward with speed 64 on the left motor and forward with speed 64 on the right motor
    rvr.rawMotors(RawMotorModes::reverse, 64, RawMotorModes::forward, 64);
    delay(1000);
    
    // drive forward with speed 64 on both motors
    rvr.rawMotors(RawMotorModes::forward, 64, RawMotorModes::forward, 64);
    delay(1000);
    
    // turn both motors off
    rvr.rawMotors(RawMotorModes::off, 0, RawMotorModes::off, 0);
    delay(1000);
}
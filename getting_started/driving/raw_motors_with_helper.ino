#include <SpheroRVR.h>

static DriveControl driveControl;

void setup() {
    // set up communication with the RVR
    rvr.configUART(&Serial);

    // get the RVR's DriveControl
    driveControl = rvr.getDriveControl();
}

void loop() {
    // reset the heading to zero
    driveControl.setHeading(0);
    
    // drive forward with speed 64 on both motors
    driveControl.setRawMotors(rawMotorModes::forward, 64, rawMotorModes::forward, 64);
    delay(1000);
    
    // drive backward with speed 32 on both motors
    driveControl.setRawMotors(rawMotorModes::reverse, 32, rawMotorModes::reverse, 32);
    delay(1000);
    
    // drive backward with speed 64 on the left motor and forward with speed 64 on the right motor
    driveControl.setRawMotors(rawMotorModes::reverse, 64, rawMotorModes::forward, 64);
    delay(1000);
    
    // drive forward with speed 64 on both motors
    driveControl.setRawMotors(rawMotorModes::forward, 64, rawMotorModes::forward, 64);
    delay(1000);
    
    // turn both motors off
    driveControl.setRawMotors(rawMotorModes::off, 0, rawMotorModes::off, 0);
    delay(1000);
}
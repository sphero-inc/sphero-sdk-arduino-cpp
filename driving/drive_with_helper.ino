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
    
    // drive forward with speed 64
    driveControl.rollStart(0, 64);
    delay(1000);
    
    // drive forward with speed 64
    driveControl.rollStart(0, 64);
    delay(1000);
    
    // drive to the right with speed 64
    driveControl.rollStart(90, 64);
    delay(1000);
    
    // drive to the left with speed 64
    driveControl.rollStart(270, 64);
    delay(1000);
    
    // stop driving
    driveControl.rollStop(270);
    delay(1000);
}

#include <SpheroRVR.h>

void setup() {
    // set up communication with the RVR
    rvr.configUART(&Serial);
}

void loop() {
    // reset the heading to zero
    rvr.resetYaw();
    
    // drive forward with speed 64
    rvr.driveWithHeading(64, 0, static_cast<uint8_t>(DriveFlags.none));
    delay(1000);
    
    // drive forward with speed 64
    rvr.driveWithHeading(64, 0, static_cast<uint8_t>(DriveFlags.none));
    delay(1000);

    // drive backward with speed 32
    rvr.driveWithHeading(32, 0, static_cast<uint8_t>(DriveFlags.driveReverse));
    delay(1000);
    
    // drive to the right with speed 64
    rvr.driveWithHeading(64, 90, static_cast<uint8_t>(DriveFlags.none));
    delay(1000);
    
    // drive to the left with speed 64
    rvr.driveWithHeading(64, 270, static_cast<uint8_t>(DriveFlags.none));
    delay(1000);
    
    // stop driving
    rvr.driveWithHeading(0, 270, static_cast<uint8_t>(DriveFlags.none));
    delay(1000);
}

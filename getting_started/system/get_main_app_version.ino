#include <SpheroRVR.h>

static void getMainApplicationVersionCallback(GetMainApplicationVersionReturn_t *getMainApplicationVersionReturn);

void setup() {
    // set up communication with the RVR
    rvr.configUART(&Serial);
    
    // give RVR time to wake up
    delay(2000);
    
    // get the main application version for the Nordic processor
    rvr.getMainApplicationVersion(static_cast<uint8_t>(Processors::nordic), getMainApplicationVersionCallback);
}

void loop() {
    // must include this line if expecting a response from the RVR
    rvr.poll();
}

static void getMainApplicationVersionCallback(GetMainApplicationVersionReturn_t *getMainApplicationVersionReturn)
{
    // setting up the led group for both headlights
    uint32_t ledGroup = 0;
    ledGroup |= (1 << static_cast<uint8_t>(LEDs::rightHeadlightRed));
    ledGroup |= (1 << static_cast<uint8_t>(LEDs::rightHeadlightGreen));
    ledGroup |= (1 << static_cast<uint8_t>(LEDs::rightHeadlightBlue));
    ledGroup |= (1 << static_cast<uint8_t>(LEDs::leftHeadlightRed));
    ledGroup |= (1 << static_cast<uint8_t>(LEDs::leftHeadlightGreen));
    ledGroup |= (1 << static_cast<uint8_t>(LEDs::leftHeadlightBlue));
    
    if (getMainApplicationVersionReturn->minor >= 1)
    {
        // set headlights to yellow if the y value in version x.y.z is 1 or greater
        uint8_t rgbArray[] = {0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0x00};
        rvr.setAllLeds(ledGroup, rgbArray, sizeof(rgbArray) / sizeof(rgbArray[0]));
    }
    else
    {
        // set headlights to pink if the y value in version x.y.z is less than 1
        uint8_t rgbArray[] = {0xFF, 0x00, 0xFF, 0xFF, 0x00, 0xFF};
        rvr.setAllLeds(ledGroup, rgbArray, sizeof(rgbArray) / sizeof(rgbArray[0]));
    }
}
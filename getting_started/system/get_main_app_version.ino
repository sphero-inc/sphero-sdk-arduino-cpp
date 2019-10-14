#include <SpheroRVR.h>

static void getMainApplicationVersionCallback(GetMainApplicationVersionReturn_t *getMainApplicationVersionReturn);

void setup() {
    // set up communication with the RVR
    rvr.configUART(&Serial);
    
    // give RVR time to wake up
    delay(2000);
    
    // get the main application version for the Nordic processor (0x1)
    rvr.getMainApplicationVersion(0x1, getMainApplicationVersionCallback);
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
    
    if (getMainApplicationVersionReturn->major >= 6)
    {
        // set headlights to yellow if the version is 6.x.y or greater
        uint8_t rgbArray[] = {0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0x00};
        rvr.setAllLeds(ledGroup, rgbArray, sizeof(rgbArray) / sizeof(rgbArray[0]));
    }
    else
    {
        // set headlights to pink if the version is less than 6.x.y
        uint8_t rgbArray[] = {0xFF, 0x00, 0xFF, 0xFF, 0x00, 0xFF};
        rvr.setAllLeds(ledGroup, rgbArray, sizeof(rgbArray) / sizeof(rgbArray[0]));
    }
}
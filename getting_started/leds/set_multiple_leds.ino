#include <SpheroRVR.h>

static uint32_t ledGroup;

void setup() {
    // set up communication with the RVR
    rvr.configUART(&Serial);
    
    // setting up the led group for both headlights
    ledGroup = 0;
    ledGroup |= (1 << static_cast<uint8_t>(LEDs::rightHeadlightRed));
    ledGroup |= (1 << static_cast<uint8_t>(LEDs::rightHeadlightGreen));
    ledGroup |= (1 << static_cast<uint8_t>(LEDs::rightHeadlightBlue));
    ledGroup |= (1 << static_cast<uint8_t>(LEDs::leftHeadlightRed));
    ledGroup |= (1 << static_cast<uint8_t>(LEDs::leftHeadlightGreen));
    ledGroup |= (1 << static_cast<uint8_t>(LEDs::leftHeadlightBlue));
}

void loop() {
    // set headlights to red and wait 1 second
    uint8_t redArray[] = {0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00};
    rvr.setAllLeds(ledGroup, redArray, sizeof(redArray) / sizeof(redArray[0]));
    delay(1000);
    
    // set headlights to blue and wait 1 second
    uint8_t blueArray[] = {0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF};
    rvr.setAllLeds(ledGroup, blueArray, sizeof(blueArray) / sizeof(blueArray[0]));
    delay(1000);
    
    // set headlights to green and wait 1 second
    uint8_t greenArray[] = {0x00, 0xFF, 0x00, 0x00, 0xFF, 0x00};
    rvr.setAllLeds(ledGroup, greenArray, sizeof(greenArray) / sizeof(greenArray[0]));
    delay(1000);
    
    // set headlights to yellow and wait 1 second
    uint8_t yellowArray[] = {0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0x00};
    rvr.setAllLeds(ledGroup, yellowArray, sizeof(yellowArray) / sizeof(yellowArray[0]));
    delay(1000);
}
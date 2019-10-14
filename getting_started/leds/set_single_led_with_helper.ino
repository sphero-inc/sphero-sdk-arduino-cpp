#include <SpheroRVR.h>

static LedControl ledControl;

void setup() {
    // set up communication with the RVR
    rvr.configUART(&Serial);
    
    // get the RVR's LedControl
    ledControl = rvr.getLedControl();
}

void loop() {
    // set up the array of led indexes for the right headlight
    uint8_t ledIndexes[] = {static_cast<uint8_t>(LEDs::rightHeadlightRed),
                            static_cast<uint8_t>(LEDs::rightHeadlightGreen),
                            static_cast<uint8_t>(LEDs::rightHeadlightBlue)};
  
    // set right headlight to red and wait 1 second
    uint8_t redBrightnessValues[] = {0xFF, 0x00, 0x00};
    ledControl.setLeds(ledIndexes, redBrightnessValues, sizeof(ledIndexes) / sizeof(ledIndexes[0]));
    delay(1000);
    
    // set right headlight to blue and wait 1 second
    uint8_t blueBrightnessValues[] = {0x00, 0x00, 0xFF};
    ledControl.setLeds(ledIndexes, blueBrightnessValues, sizeof(ledIndexes) / sizeof(ledIndexes[0]));
    delay(1000);
    
    // set right headlight to green and wait 1 second
    uint8_t greenBrightnessValues[] = {0x00, 0xFF, 0x00};
    ledControl.setLeds(ledIndexes, greenBrightnessValues, sizeof(ledIndexes) / sizeof(ledIndexes[0]));
    delay(1000);
    
    // set right headlight to yellow and wait 1 second
    uint8_t yellowBrightnessValues[] = {0xFF, 0xFF, 0x00};
    ledControl.setLeds(ledIndexes, yellowBrightnessValues, sizeof(ledIndexes) / sizeof(ledIndexes[0]));
    delay(1000);
}
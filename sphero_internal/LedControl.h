#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "Arduino.h"

class LedControl
{
    public:
        LedControl();
        
        void setLeds(uint8_t ledIndexes[], uint8_t ledBrightnessValues[], int ledCount);
        
    private:
};

#endif
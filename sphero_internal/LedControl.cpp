#include "LedControl.h"
#include "io.h"

IoDevice _ledControlIo;

LedControl::LedControl()
{
}

void LedControl::setLeds(uint8_t ledIndexes[], uint8_t ledBrightnessValues[], int ledCount)
{
    uint32_t ledGroup = 0;
    
    for (int i = 0; i < ledCount; i++)
    {
        ledGroup |= (1 << ledIndexes[i]);
    }
    
    _ledControlIo.setAllLeds(ledGroup, ledBrightnessValues, ledCount);
}

#ifndef DRIVE_CONTROL_H
#define DRIVE_CONTROL_H

#include "Arduino.h"

enum struct rawMotorModes : uint8_t
{
    off, 
    forward, 
    reverse,
    brake,
    ignore 
};

class DriveControl
{
    public:
        DriveControl();
        
        void aimStart();
        
        void aimStop();
        
        bool isAiming();
        
        void resetHeading();
        
        void rollStart(uint16_t heading, int16_t speed);
        
        void rollStop(uint16_t heading);
        
        void setHeading(uint16_t heading);
        
        void setRawMotors(rawMotorModes leftMode, uint8_t leftSpeed, rawMotorModes rightMode, uint8_t rightSpeed);
        
    private:
        bool _isAiming;
};

#endif

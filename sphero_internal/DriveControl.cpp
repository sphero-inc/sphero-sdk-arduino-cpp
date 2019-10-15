#include "DriveControl.h"
#include "drive.h"
#include "io.h"

IoDevice _driveControlIo;
DriveDevice _driveControlDrive;

DriveControl::DriveControl()
{
    _isAiming = false;
    _isBoosting = false;
}

void DriveControl::aimStart()
{
    _isAiming = true;
    
    uint32_t leds = 0x3FFFFFFF;
    
    uint8_t values[30] = {0};
    values[26] = 255;
    values[29] = 255;
    
    _driveControlIo.setAllLeds(leds, values, sizeof(values) / sizeof(values[0]));
}

void DriveControl::aimStop()
{
    _isAiming = false;
    
    uint32_t leds = 0x3FFFFFFF;
    
    uint8_t values[30] = {0};
    
    _driveControlIo.setAllLeds(leds, values, sizeof(values) / sizeof(values[0]));
}

bool DriveControl::isAiming()
{
    return _isAiming;
}

void DriveControl::resetHeading()
{
    _driveControlDrive.resetYaw();
}

void DriveControl::rollStart(uint16_t heading, int16_t speed)
{
    uint8_t flags = 0;
    
    if (speed < 0)
    {
        flags |= static_cast<uint8_t>(DriveFlags::driveReverse);
    }
    
    if (_isBoosting)
    {
        flags |= static_cast<uint8_t>(DriveFlags::boost);
    }
    
    uint8_t velocity = speed < 0 ? static_cast<uint8_t>(speed * -1) : static_cast<uint8_t>(speed);
    velocity = velocity > 255 ? 255 : velocity;
    
    heading = speed < 0 ? heading + 180 : heading;
    heading %= 360;
    
    _driveControlDrive.driveWithHeading(velocity, heading, flags);
}

void DriveControl::rollStop(uint16_t heading)
{
    rollStart(heading, 0);
}

void DriveControl::setHeading(uint16_t heading)
{
    rollStart(heading, 0);
}

void DriveControl::setRawMotors(rawMotorModes leftMode, uint8_t leftSpeed, rawMotorModes rightMode, uint8_t rightSpeed)
{    
    if (leftMode == rawMotorModes::brake || leftMode == rawMotorModes::ignore)
    {
        leftMode = rawMotorModes::off;
    }
    
    if (rightMode == rawMotorModes::brake || rightMode == rawMotorModes::ignore)
    {
        rightMode = rawMotorModes::off;
    }
    
    RawMotorModes sendLeftMode;
    RawMotorModes sendRightMode;
    
    switch (leftMode)
    {
        case rawMotorModes::forward:
            sendLeftMode = RawMotorModes::forward;
            break;
        case rawMotorModes::reverse:
            sendLeftMode = RawMotorModes::reverse;
            break;
        default:
            sendLeftMode = RawMotorModes::off;
            break;
    }
    
    switch (rightMode)
    {
        case rawMotorModes::forward:
            sendRightMode = RawMotorModes::forward;
            break;
        case rawMotorModes::reverse:
            sendRightMode = RawMotorModes::reverse;
            break;
        default:
            sendRightMode = RawMotorModes::off;
            break;
    }
    
    _driveControlDrive.rawMotors(sendLeftMode, leftSpeed, sendRightMode, rightSpeed);
}

void DriveControl::setBoost(bool isEnabled)
{
    _isBoosting = isEnabled;
}

bool DriveControl::isBoosting()
{
    return _isBoosting;
}

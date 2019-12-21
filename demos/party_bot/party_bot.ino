#include <SpheroRVR.h>

// this is the pin connected to the data pin of the PIR sensor
#define PIRPIN 4

// this is a bitmask that indicates to the RVR that we want to set all the LEDs
#define ALL_LEDS 0x3FFFFFFF

// these are arrays that define the RGB values of the colors we'll be cycling through
const uint8_t RED[] = {255, 0, 0};
const uint8_t ORANGE[] = {255, 100, 0};
const uint8_t YELLOW[] = {255, 255, 0};
const uint8_t GREEN[] = {0, 255, 0};
const uint8_t BLUE[] = {0, 0, 255};
const uint8_t PURPLE[] = {100, 0, 255};
const uint8_t WHITE[] = {255, 255, 255};
const uint8_t OFF[] = {0, 0, 0};

// this is the index of the current color
byte colorIndex = 0;
// this is the RGB array for the current color
uint8_t currentColor[3] = {0};

void setup() {
  // configure the Arduino pin to read from the PIR sensor
  pinMode(PIRPIN, INPUT);

  // set up communication with the RVR
  rvr.configUART(&Serial);

  // give RVR time to wake up
  delay(2000);
}

void loop() {
  // if motion is detected, increment the color index and set the current color
  if (digitalRead(PIRPIN) == HIGH)
  {
    colorIndex += 1;
    colorIndex = colorIndex % 7;
    setCurrentColor();
  }
  // if no motion is detected, set the current color to OFF
  else
  {
    memcpy(currentColor, OFF, 3);
  }

  // we're setting 10 LEDs that each need 3 values (red, green, blue), so we need an array of size 30
  uint8_t ledValues[30] = {0};

  // populate ledValues array so that every LED will be the same color: (currentColor[0], currentColor[1], currentColor[2])
  for (int i = 0; i < 28; i = i + 3)
  {
    ledValues[i] = currentColor[0];
    ledValues[i + 1] = currentColor[1];
    ledValues[i + 2] = currentColor[2];
  }

  // tell RVR to update the LED colors
  rvr.setAllLeds(ALL_LEDS, ledValues, 30);

  // loop every 1 second
  delay(1000);
}

// update the currentColor array based on the current colorIndex value
void setCurrentColor()
{
  switch (colorIndex) {
    case 0:
      memcpy(currentColor, RED, 3);
      break;
    case 1:
      memcpy(currentColor, ORANGE, 3);
      break;
    case 2:
      memcpy(currentColor, YELLOW, 3);
      break;
    case 3:
      memcpy(currentColor, GREEN, 3);
      break;
    case 4:
      memcpy(currentColor, BLUE, 3);
      break;
    case 5:
      memcpy(currentColor, PURPLE, 3);
      break;
    case 6:
      memcpy(currentColor, WHITE, 3);
      break;
    default:
      break;
  }
}

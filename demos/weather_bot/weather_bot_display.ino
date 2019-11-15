#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include "DHT.h"


// this is the pin connected to the data pin of the sensor
#define DHTPIN  12

// this is the type of sensor (you'll need to change this if you're using a different sensor!)
#define DHTTYPE DHT22

// these are bitmasks that tell the display which segments need to be turned on for each character
#define ZERO    0x0C3F
#define ONE     0x0006
#define TWO     0x00DB
#define THREE   0x008F
#define FOUR    0x00E6
#define FIVE    0x2069
#define SIX     0x00FD
#define SEVEN   0x0007
#define EIGHT   0x00FF
#define NINE    0x00EF
#define DECIMAL 0x4000
#define OFF     0x0000


// instantiate alphanumeric display object
Adafruit_AlphaNum4 output = Adafruit_AlphaNum4();

// instantiate temperature-humidity sensor object
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // turn alphanumeric display on
  output.begin(0x70);
  // turn temperature-humidity sensor on
  dht.begin();

  // turn all segments of the display off
  output.writeDigitRaw(0, OFF);
  output.writeDigitRaw(1, OFF);
  output.writeDigitRaw(2, OFF);
  output.writeDigitRaw(3, OFF);
  output.writeDisplay();

  // give RVR time to wake up
  delay(2000);
}

void loop() {
  // loop every 2 seconds
  delay(2000);

  // read the temperature from the sensor in Fahrenheit
  float temperature = dht.readTemperature(true);

  // if we get a bad reading, continue to next loop iteration
  if (isnan(temperature)) {
    return;
  }

  // convert the temperature float to a char array
  char temperatureBuffer[5];
  dtostrf(temperature, 5, 2, temperatureBuffer);

  // loop through temperature char array
  for (int i = 0; i < 5; i++)
  {
    // skip the decimal point
    if (i == 2)
    {
      continue;
    }

    // set the display index
    int index = i;

    // offset the display index by 1 if we're past the decimal point in the char array
    if (i > 2)
    {
      index = i - 1;
    }

    // get the bitmask for the current digit
    int digit = getDigit(temperatureBuffer[i]);

    // add a decimal point after the second digit
    if (i == 1)
    {
      digit |= DECIMAL;
    }

    // write digit to the given index of the display
    output.writeDigitRaw(index, digit);
  }

  // update display
  output.writeDisplay();
}

// convert a char to its corresponding digit bitmask
int getDigit(char digit) {
  switch (digit) {
    case '0':
      return ZERO;
    case '1':
      return ONE;
    case '2':
      return TWO;
    case '3':
      return THREE;
    case '4':
      return FOUR;
    case '5':
      return FIVE;
    case '6':
      return SIX;
    case '7':
      return SEVEN;
    case '8':
      return EIGHT;
    case '9':
      return NINE;
    default:
      return OFF;
  }
}

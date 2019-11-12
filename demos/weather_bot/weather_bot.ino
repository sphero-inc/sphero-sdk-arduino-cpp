#include "DHT.h"
#include <SpheroRVR.h>


// this is the pin connected to the data pin of the sensor
#define DHTPIN 4

// this is the type of sensor (you'll need to change this if you're using a different sensor!)
#define DHTTYPE DHT22

// this is a bitmask that indicates to the RVR that we want to set all the LEDs
#define ALL_LEDS 0x3FFFFFFF


// instantiate temperature-humidity sensor object
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // turn temperature-humidity sensor on
  dht.begin();

  // set up communication with the RVR
  rvr.configUART(&Serial);

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

  // translate a temperature ranging from 0F-100F to a red or blue value ranging from 0-255
  // note: you'll need to adjust the math if you're exposing your RVR to temperatures below 0F or above 100F
  uint8_t redValue = static_cast<uint8_t>(temperature / 100 * 255);
  uint8_t blueValue = static_cast<uint8_t>((100 - temperature) / 100 * 255);

  // we're setting 10 LEDs that each need 3 values (red, green, blue), so we need an array of size 30
  uint8_t ledValues[30] = {0};

  // populate ledValues array so that every LED will be the same color: (redValue, 0, blueValue)
  for (int i = 0; i < 28; i = i + 3)
  {
    ledValues[i] = redValue;
    ledValues[i + 1] = 0;
    ledValues[i + 2] = blueValue;
  }

  // tell RVR to update the LED colors
  rvr.setAllLeds(ALL_LEDS, ledValues, 30);
}

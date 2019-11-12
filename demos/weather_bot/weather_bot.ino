#include "DHT.h"
#include <SpheroRVR.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define ALL_LEDS 0x3FFFFFFF

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();

  rvr.configUART(&Serial);

  delay(2000);
}

void loop() {
  delay(2000);
  
  float temperature = dht.readTemperature(true);

  if (isnan(temperature)) {
    return;
  }
  
  uint8_t redValue = static_cast<uint8_t>(temperature / 100 * 255);
  uint8_t blueValue = static_cast<uint8_t>((100 - temperature) / 100 * 255);

  uint8_t ledValues[30] = {0};

  for (int i = 0; i < 28; i = i + 3)
  {
    ledValues[i] = redValue;
    ledValues[i + 1] = 0;
    ledValues[i + 2] = blueValue;
  }

  rvr.setAllLeds(ALL_LEDS, ledValues, 30);
}

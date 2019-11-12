#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include "DHT.h"

#define DHTPIN  12
#define DHTTYPE DHT22

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

Adafruit_AlphaNum4 output = Adafruit_AlphaNum4();

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  output.begin(0x70);
  dht.begin();

  output.writeDigitRaw(0, OFF);
  output.writeDigitRaw(1, OFF);
  output.writeDigitRaw(2, OFF);
  output.writeDigitRaw(3, OFF);
  output.writeDisplay();

  delay(2000);
}

void loop() {
  delay(2000);

  float temperature = dht.readTemperature(true);

  if (isnan(temperature)) {
    return;
  }

  char temperatureBuffer[5];
  dtostrf(temperature, 5, 2, temperatureBuffer);

  for (int i = 0; i < 5; i++)
  {
    if (i == 2)
    {
      continue;
    }

    int index = i;

    if (i > 2)
    {
      index = i - 1;
    }

    int digit = getDigit(temperatureBuffer[i]);

    if (i == 1)
    {
      digit |= DECIMAL;
    }

    output.writeDigitRaw(index, digit);
  }

  output.writeDisplay();
}

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

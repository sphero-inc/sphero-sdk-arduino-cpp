#include <SpheroRVR.h>
#include <SoftwareSerial.h>

static void getMainApplicationVersionCallback(GetMainApplicationVersionReturn_t *getMainApplicationVersionReturn);

SoftwareSerial serial(2, 3);

void setup() {
  // begin software serial connection
  serial.begin(115200);

  // set up communication with the RVR
  rvr.configUART(&Serial);

  // give RVR time to wake up
  delay(2000);

  // send "get main application version" command to the RVR
  serial.println("Getting NORDIC main application version...");
  rvr.getMainApplicationVersion(static_cast<uint8_t>(Processors::nordic), getMainApplicationVersionCallback);
}

void loop() {
  // must include this line if expecting a response from the RVR
  rvr.poll();
}

static void getMainApplicationVersionCallback(GetMainApplicationVersionReturn_t *getMainApplicationVersionReturn)
{
  if(getMainApplicationVersionReturn->isSuccessful == true)
  {
    // format and print the result of the call to getMainApplicationVersion
    serial.print("Version: ");
    serial.print(getMainApplicationVersionReturn->major);
    serial.print(".");
    serial.print(getMainApplicationVersionReturn->minor);
    serial.print(".");
    serial.println(getMainApplicationVersionReturn->revision);
  }
}

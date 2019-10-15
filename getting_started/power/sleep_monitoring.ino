#include <SpheroRVR.h>

static void willSleepNotifyCallback(bool isSuccessful);
static void didSleepNotifyCallback(bool isSuccessful);

void setup() {
    // set up communication with the RVR
    rvr.configUART(&Serial);

    // set up the callback function for "will sleep" notifications
    rvr.setWillSleepNotifyCallback(willSleepNotifyCallback);
    
    // set up the callback function for "did sleep" notifications
    rvr.setDidSleepNotifyCallback(didSleepNotifyCallback);
}

void loop() {
    // must include this line if expecting a response from the RVR
    rvr.poll();
}

static void willSleepNotifyCallback(bool isSuccessful)
{
    // put your code here to run when you get a "will sleep" notification
}

static void didSleepNotifyCallback(bool isSuccessful)
{
    // put your code here to run when you get a "did sleep" notification
}
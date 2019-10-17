# Software Serial
This demo will walk you through how to set up a Software Serial connection using Arduino's `SoftwareSerial` library.

## Required Hardware
* Sphero RVR
* Arduino Uno
* 5V FTDI Cable (like [this one])
* [USB 2.0 Cable Type A/B]
* [Jumper wires]

## Instructions
If you want your Arduino program to print some output while also talking to RVR, you may find that using the Arduino's built-in hardware for serial communication gives you messy results:
```
Getting NORDIC main application version...
ç:.....ìÿç8....ˇ...?.ˇ..ˇ.Eÿç8....ˇ...?ˇ..ˇ..EÿVersion: 7.1.422
```
This is where Arduino's `SoftwareSerial` library comes in. The `SoftwareSerial` library can configure other digital pins on your Arduino so that they can be used for serial communication.

#### Using the `SoftwareSerial` Library
A complete example of using the `SoftwareSerial` library can be found in `software_serial_demo.ino`. This tutorial will walk you through the lines of code that set up and use this library.


```
#include <SoftwareSerial.h>
```
The first thing you have to do to use any library is include it!

```
SoftwareSerial serial(2, 3);
```
You'll need to declare an instance of SoftwareSerial to use in your code. In this declaration, we're using pin 2 as the RX pin and pin 3 as the TX pin. This will be important to note for when we're hooking everything up.

```
serial.begin(115200);
```
Inside the `setup()` function of your Arduino file, be sure to include this line to begin the serial connection. `115200` is the baud rate RVR uses for serial communication.

That's all there is to it! Now you can use your Software Serial connection to print output from your program, like this:
```
serial.println("Getting NORDIC main application version...");
```

#### Setting Up a Serial Port Terminal Application
Now that your code is all set up, you'll need a way to actually see the output that you're printing. For this we use a serial port terminal application. It's up to you which application you use, but we used [CoolTerm]. There are two main things you'll need to do to get the terminal set up to print your output.

First, you'll need to make sure the application is reading from the correct USB port. You can usually figure this out with trial and error (because it won't work if it's not reading from the right port!)
<br>Second, make sure the baudrate matches the one you used in your `serial.begin()` call. For us, that's `115200`.

That should be all you need to do! If things don't seem to be working later, try playing around with the different options (like the USB port).

#### Bringing It All Together
The last thing to do is connect all your hardware! Once you've flashed your program to the Arduino, disconnect it from your computer. Next we want to get the 5V FTDI Cable hooked up to your Arduino. You'll need to connect jumper wires to the RX and TX pins of the FTDI cable. Then, hook them up to the Arduino as follows:
* connect the RX pin to pin 3 (the TX pin) on the Arduino
* connect the TX pin to pin 2 (the RX pin) on the Arduino

That's it! Now you can plug the USB side of the cable in to your computer.

Next, use your A/B USB cable to connect the Arduino to the RVR (don't turn the RVR on just yet!). Move over to your terminal application and tell it to start reading from the serial port (in CoolTerm this is the **Connect** button). Finally, it's time to turn on your RVR and see what happens! If you used the provided `software_serial_demo.ino` file, you should see something like this:
```
Getting NORDIC main application version...
Version: 7.1.422
```

[this one]: https://www.sparkfun.com/products/9718
[USB 2.0 Cable Type A/B]: https://store.arduino.cc/usa/usb-2-0-cable-type-a-b
[Jumper wires]: https://www.sparkfun.com/products/11026
[CoolTerm]: https://freeware.the-meiers.org
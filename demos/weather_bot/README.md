# WeatherBot
Turn your RVR into your very own WeatherBot! While it can't control the weather, it can measure and show the current temperature on an alphanumeric display, and also sets the LEDs on your RVR to a color that corresponds to the temperature. This example will show you how to incorporate several different technologies into a single project. Consequently, it requires lots of assembly! Take your time and follow the instructions carefully, especially if you haven't put together a circuit before!

**Note:** The battery in your RVR may fail if exposed to temperatures below -20C (-4F) or above 60C (140F), so don't go crazy when you're testing out your WeatherBot! Also, if you decide to test the humidity as well, keep in mind that your RVR shouldn't be in an environment more humid than driving through wet grass.

## Parts List
Here's a list of everything you'll need to make your own WeatherBot:
* [RVR]
* [Arduino Uno]
* Adafruit Feather (any type will do, we used a [HUZZAH])\*
* [Adafruit 14-Segment Alphanumeric LED FeatherWing]
* [A/B USB Cable]
* Micro B USB Cable
* [DHT22] temperature-humidity sensor (comes with a resistor)\*\*
* [Dual Alphanumeric Display] (pick your favorite color!)
* Breadboard
* 29 Jumper wires\*\*\*
* Solder and soldering iron

\* There are three different versions of the HUZZAH. We used the Assembled Headers version (just because that's what we had on hand), but any of the three versions will do. In fact, the Stacking Headers version would eliminate the need for a lot of jumper wires and give you a much cleaner final product!
<br>\*\* You could also use a [DHT11] instead.
<br>\*\*\* You'll notice from the picture of our circuit that we didn't actually use jumper wires, but cut and stripped wire to fit more nicely in the circuit. Jumper wires will work just fine, but if you want to do what we did you'll need some [hook-up wire], [wire strippers], and [wire cutters]. Also, depending on the version of Feather board that you use, you may need fewer than 29 wires.

## Hardware Assembly
As you can see from all the asterisks in the **Parts List** above, there's a lot of wiggle room in how exactly you want to build your circuit. The remainder of this tutorial will walk you through the way *we* did things; if you don't have much experience with this type of project we recommend following along exactly, but if you know your way around a breadboard then feel free to make whatever changes you see fit!

First things first, we need to assemble our alphanumeric display. [Here's the tutorial] we followed to accomplish this task, and we recommend you do the same! There is, however, one note we'd like to add: once you're done soldering, be sure to hold on to the wires (with tweezers if you have them) when you clip them short to keep them from flying all over the place! It would also be a good idea to wear safety goggles during this step.

Once you have your alphanumeric display assembled, you can start putting together your circuit! Follow this wiring diagram:

![wiring diagram]

It looks like a lot! If you're cutting and stripping your own wires, this is the most time-consuming part of the project. So take your time, follow the diagram carefully, and be patient! When you're done you should have something like this (except it won't be lighting up just yet!):

![finished circuit]

## Software
Phew! Take a deep breath, the hard part is over.

If you haven't done so already, download the [Arduino IDE]. We'll use this IDE for both the Arduino and the Feather.

Since we're working with two different development boards (Arduino Uno and Adafruit Feather), there are two separate files you'll need to download. `weather_bot.ino` will go on the Arduino, and `weather_bot_display.ino` will go on the Feather. Let's start with the Arduino.

Download the `weather_bot.ino` file and open it in the Arduino IDE. You can find explanations of the code in the comments inside the file, so here we'll just focus on uploading it to your Arduino. Under the **Tools** tab, be sure your **Board** is set to "Arduino/Genuino Uno". Also make sure your **Port** is set to the USB port you're going to plug your Arduino into. Connect your Arduino to your computer using the A/B USB Cable, then click the **Upload** button in the top left corner of the IDE. Wait a few seconds until the IDE tells you it's done uploading, and then you're good to go!

Using the Feather with the Arduino IDE is a little more complicated. Follow [this tutorial] to get everything set up the way it needs to be. Once that's done, the upload process is exactly the same! Just use the Micro B USB cable this time instead of the A/B cable.

## Bringing It All Together
Now that our circuit is built and our dev boards are flashed with code, we can finally use our WeatherBot! All you need to do is plug the Arduino into RVR's USB port using your A/B cable, and turn on the RVR! It'll take a few seconds before the RVR's LEDs change colors, so be patient. It may also take several seconds before you see the alphanumeric display light up. If it's been a while and you still don't see anything, try hitting the reset button on the Feather and wait another several seconds. Hitting the reset button on the Arduino can also help if that didn't work.

Congratulations on a job well done!

![final_product]

## Now What?
See if you can build a better bot! Here are some ideas we had for ways you could improve your WeatherBot:
* The DHT22 has a humidity sensor that we didn't use, find a way to incorporate that!
* We mentioned several different options for building your circuit. Now that you've done it one way, see if you can do it a different way!
* Try combining this tutorial with our Software Serial tutorial to output the temperature to your computer instead of the alphanumeric display. (This could be useful if you don't have access to all the parts needed to make the alphanumeric display work)
* Change up the code to have the LEDs turn every color of the rainbow instead of just ranging from red to blue!


[RVR]: https://www.sphero.com/rvr
[Arduino Uno]: https://store.arduino.cc/usa/arduino-uno-rev3
[HUZZAH]: https://www.adafruit.com/product/3046
[Adafruit 14-Segment Alphanumeric LED FeatherWing]: https://www.adafruit.com/product/3089
[A/B USB Cable]: https://store.arduino.cc/usa/usb-2-0-cable-type-a-b
[DHT22]: https://www.adafruit.com/product/385
[Dual Alphanumeric Display]: https://www.adafruit.com/product/2155
[DHT11]: https://learn.adafruit.com/dht/overview
[hook-up wire]: https://www.sparkfun.com/products/11375
[wire strippers]: https://www.sparkfun.com/products/14762
[wire cutters]: https://www.sparkfun.com/products/8794
[Here's the tutorial]: https://learn.adafruit.com/14-segment-alpha-numeric-led-featherwing/assembly
[wiring diagram]: weather_bot_wire_diagram.png
[finished circuit]: circuit_close_up.jpg
[Arduino IDE]: https://www.arduino.cc/en/main/software
[this tutorial]: https://learn.adafruit.com/adafruit-feather-huzzah-esp8266/using-arduino-ide
[final_product]: rvr.jpg
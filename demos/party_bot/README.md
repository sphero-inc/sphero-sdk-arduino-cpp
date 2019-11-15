# PartyBot
Get the party started! Turn your RVR into a motion-activated disco ball with this fun and easy project. Only requiring a few extra parts, this example is great for beginners, but also has plenty of room for expansion for more experienced inventors!

## Parts List
* [RVR]
* [Arduino Uno]
* [A/B USB Cable]
* [PIR Motion Sensor]
* Breadboard \*
* 3 Jumper Wires \*
* 10KΩ Resistor \*\*

\* You could also just connect the wires from the sensor directly to your Arduino, but note that the wires on this particular sensor fit very loosely in the headers on the Arduino, which is why we recommend using a breadboard to ensure more reliable connections.
<br>\*\* Your circuit may work just fine without the resistor. However, if you notice that your output isn't changing as expected, you'll need to add the resistor as a pullup between the data and power pins. More info on that [here].

## Instructions
The first thing you'll need to do is get your circuit set up. Here's the wiring diagram:

![wiring diagram]

Basically, there are three connections we're making:
* connect the black wire (**GND** pin) of the PIR sensor to **GND** on the Arduino
* connect the red wire (**+5V** pin) of the PIR sensor to **5V** on the Arduino
* connect the yellow wire (**OUT** pin) of the PIR sensor to digital **pin 4** on the Arduino (you can use a different pin if you'd like but you'll need to make sure you change the code to match!)

As we mentioned above, the resistor may not be necessary. However, if your output isn't doing what it's supposed to, put the resistor between the output and power pins.

Next you'll need to flash the code to your Arduino. If you don't already have it installed, [download the Arduino IDE here]. Then, download the `party_bot.ino` file from our GitHub repo. There are comments in the code to help you understand how it works, but here we'll just focus on getting it uploaded to your Arduino.

If you haven't used the Arduino IDE before, you'll need to get it configured for your board. Plug your Arduino in to your computer using your A/B USB cable. Go to the **Tools** tab and make sure **Board** is set to "Arduino/Genuino Uno" and set your **Port** to the USB port you'll be using (you can usually figure this out through trial and error). Once everything's configured, click the **Upload** button (the one with an arrow) in the top left corner of the IDE. Wait a few seconds until it tells you it's done uploading, and then you're all set!

With your circuit built and your Arduino flashed with code, all that's left to do is plug it in and turn it on! Just connect the Arduino to the USB port of the RVR and power on the RVR. Make sure you mount your circuit so that the PIR sensor is facing up and not blocked by anything. Also note that the PIR sensor can take up to 30-60 seconds to stabilize after you turn it on, so don't panic if things seem a little wonky at first! If you wait a minute and things are still a little off, read [this guide] about changes you can make to improve the PIR sensor's performance.

Congratulations! You just built your very own PartyBot!

## Now What?
The party's just getting started! Here are some ideas for things you can do to make an even cooler party bot:
* Parties need music! See if you can add a speaker into the mix.
* Try making your disco ball spin! Keep in mind that when it's spinning, the sensor will read it as motion even if nothing around the RVR is moving. Try designing a mount that holds the sensor stationary while the RVR spins!
* Swap out the motion sensor for a microphone to make the PartyBot voice-activated instead!


[RVR]: https://www.sphero.com/rvr
[Arduino Uno]: https://store.arduino.cc/usa/arduino-uno-rev3
[A/B USB Cable]: https://store.arduino.cc/usa/usb-2-0-cable-type-a-b
[PIR Motion Sensor]: https://www.adafruit.com/product/189
[here]: https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/connecting-to-a-pir
[wiring diagram]: party_bot_wire_diagram.png
[download the Arduino IDE here]: https://www.arduino.cc/en/main/software
[this guide]: https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/testing-a-pir
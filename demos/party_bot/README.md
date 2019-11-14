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

## Now What?


[RVR]: https://www.sphero.com/rvr
[Arduino Uno]: https://store.arduino.cc/usa/arduino-uno-rev3
[A/B USB Cable]: https://store.arduino.cc/usa/usb-2-0-cable-type-a-b
[PIR Motion Sensor]: https://www.adafruit.com/product/189
[here]: https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/connecting-to-a-pir
[wiring diagram]: party_bot_wire_diagram.png
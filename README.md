# Simple Robot Test Sketch #

This sketch is for an Arduino with the Adafruit Motor Shield v2.3 ([https://www.adafruit.com/products/1438](https://www.adafruit.com/products/1438)) on a four wheel chassis robot running DC motors. It is meant to test the motors on a chassis.

To use, you must download the Adafruit Motor Shield V2 Library through the Arduino IDE or online. It is easier to add through the IDE but you can also download through this [link](https://github.com/ladyada/Adafruit_Motor_Shield_V2_Library/archive/master.zip).

The sketch is based off the example code that comes with the library and modified to run tests with four motors. First, in the `setup()` function, each motor is tested by accelerating then decelerating the motor using for loops. With this test, you can check to make sure the motors are running in the direction you expect them to. If they are running backwards, switch the positive and negative leads into the motor shield. In the `loop()` function, the chassis will accelerate then decelerate forward about a foot (depending on the power of your motors) then do the same backwards. The chassis will continue to do this until the power is removed.

Once the sketch starts running, messages are sent to the Serial Monitor to let the user know what function is running at the moment.

When the motors are tested in the `setup()` function, lift the chassis tires off the ground so it does not run in weird curves. For the `loop()` function, the chassis can be on a surface.

![Robot Chassis](https://camo.githubusercontent.com/685d345e08116c15a5b8b1fc31327acf303c6c97/68747470733a2f2f613234382e652e616b616d61692e6e65742f7365637572652e6d65657475707374617469632e636f6d2f70686f746f732f6576656e742f622f612f342f382f3630305f3435363238373638382e6a706567)
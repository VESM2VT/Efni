#### Floating pin.
- With no connection, digital inputs “float” between 0 & 5 volts (LOW & HIGH)
- Myndband (10:00) og kóðasýnidæmi: [Floating pins](https://www.programmingelectronics.com/floating-pins-pull-up-resistors-and-arduino/) (_floating pin, takki, innbyggt led, pullup viðnám_)

#### Pull Up resistors. 
- [Pull Up Resistor (myndband 3:50)](https://www.youtube.com/watch?v=wxjerCHCEMg)
- [Picking Pull-Up Resistor Values (myndband)](https://www.youtube.com/watch?v=u3Xiy2DVnI4&list=PLRIGIzu0Z7KlfGFD6gd0eMX0ozfJyrQL-&index=12)
   - Afhverju að nota viðnám með hnapp en ekki bara vír (short-circuit) og hve mikið viðnám þarf?

#### INPUT_PULLUP
- Kóðasýnidæmi [`pinMode(pin, INPUT_PULLUP);` 20K](https://www.arduino.cc/en/Tutorial/DigitalInputPullup)  
- Ekki nota INPUT_PULLUP með pinna 13 þar hann er tengdur við innbyggt LED á Arduino, [sjá nánari skýringar í Digital Pins](https://www.arduino.cc/en/Tutorial/Foundations/DigitalPins). 

#### Pull Down resistors.
- Með að nota viðnám (10k) í jörð: Resistor “pulls” input to ground (0 volts). 
- Pressing switch “pushes” input to 5 volts. Press is HIGH, Not pressed is LOW. 
- Kóðasýnidæmi [Pulldown resistor](https://www.arduino.cc/en/Tutorial/BuiltInExamples/DigitalReadSerial) 

<!-- - Ekki hafa “pull-down” of lítið, annars tekur það of mikinn straum. -->


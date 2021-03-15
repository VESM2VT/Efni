# Tímasetningar
_Í vinnslu_

---

## [delay()](https://www.arduino.cc/reference/en/language/functions/time/delay/)
Pauses the program for the amount of time (in milliseconds). Allowed data types: `unsigned long`.

You will want to use delay() to slow down the processor e.g. to see an LED flashing or to slow it down between sending commands to devices e.g.Hitach HD44780 LCD - the initialisation sequence needs rest periods between some commands.

Sjá myndband [Tight Loops and Blocking Code](https://www.youtube.com/watch?v=IyxY1uQyY9U)

```C
// Blink

int ledPin = 13;              // LED connected to digital pin 13

void setup() {
  pinMode(ledPin, OUTPUT);    // sets the digital pin as output
}

void loop() {
  digitalWrite(ledPin, HIGH); // sets the LED on
  delay(1000);                // waits for a second
  digitalWrite(ledPin, LOW);  // sets the LED off
  delay(1000);                // waits for a second
}
```

### Issues with delay()
Avoid the use of `delay()` for timing of events longer than 10’s of milliseconds unless the Arduino sketch is very simple. If your application requires that you constantly read/save data from inputs, you should avoid using the delay() function. 

No other reading of sensors, mathematical calculations, or pin manipulation can go on during the delay function, so in effect, it brings most other activity to a halt. Dæmi (myndband):  [Timed events and input](https://www.youtube.com/watch?v=V27nRZO2-Bk)

<!-- [Overlap events](https://www.youtube.com/watch?v=ib3PGI3Zrmc) -->

_Certain things do go on while the delay() function is controlling the Atmega chip, however, because the delay function does not disable interrupts. Serial communication that appears at the RX pin is recorded, PWM (analogWrite) values and pin states are maintained, and interrupts will work as they should._


---

## [millis()](https://www.arduino.cc/reference/en/language/functions/time/millis/)

Returns the number of milliseconds (`unsigned long`) passed since the Arduino board began running the current program. By using some math, you can easily verify how much time has passed without blocking your code. 
Note that millis() will overflow (go back to zero), after approximately 50 days. <br>

Sjá nánar um myndband (11mín): [Arduino millis() function and things to consider](https://www.youtube.com/watch?v=qn8SP93L3iQ)


### Why Use millis() Instead of delay()?
*Accurate timing*. <br>
With millis() we can ensure that the loop runs as often as we want, regardless of the execution time. With delay() this is not possible since we do not know how long the loop execution time is.
<br>

*Non-blocking*. <br>
It won’t prevent us from running code while “waiting”. Sometimes you need to do two things at once, blink an LED while reading a button press. If the button is pressed while Arduino is paused waiting for the `delay()` to pass, your program will miss the button press. 

```C
// Non-Blocking example 
// print “Hello” over serial once each second while doing other stuff in the meantime. 
// This is not possible with delay() since it pauses the entire code.

int period = 1000;
unsigned long time_now = 0;
 
void setup() {
    Serial.begin(115200);
}
 
void loop() {
    if(millis() >= time_now + period){
        time_now += period;
        Serial.println("Hello");
    }
   
    // Run other code
}
```

<br>

### [Blink without delay()](https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay)

```C
const int ledPin =  LED_BUILTIN; // the number of the LED pin, onboard led, pin 13 
int ledState = LOW;              // ledState used to set the LED, LOW is off

// Generally, you should use "unsigned long" (32 bits) for variables that hold time
// The value will quickly become too large for an int  (16 bits) to store

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  pinMode(ledPin, OUTPUT);   // set the digital pin as output:
}

void loop() {

  unsigned long currentMillis = millis();  // return the count of millis since program started to run.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;     // save the last time you blinked the LED

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);    // set the LED with the ledState of the variable:

  }
}

```
Her er myndband sem skýrir þetta einnig [Arduino Sketch with millis() instead of delay()](https://www.youtube.com/watch?v=BYKQ9rk0FEQ)


If you need better resolution than millis(), [micros()](https://www.arduino.cc/reference/en/language/functions/time/micros/) may be the way to go. Be aware that micros() will overflow after approximately 70 minutes.

---

### Kóðasýnidæmi með millis()
1. [Myndband: Understanding Blink without Delay 3xleds (millis)](https://wokwi.com/playground/blink-without-delay-3-leds)
1. [Ekkert delay með takka](https://github.com/VESM2VT/Efni/blob/main/Kodi/no_delay.ino)
1. [Debounce](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce)
1. [Ekkert delay með takka og debounce](https://github.com/VESM2VT/Efni/blob/main/Kodi/no_delay_debounce.ino)
1. [Myndband: Doing multiple timed things (sensors) with Arduino](https://www.youtube.com/watch?v=hD3cR25MbW8)

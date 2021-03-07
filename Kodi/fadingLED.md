### Fading LED
- [For lykkjan](https://www.arduino.cc/reference/en/language/structure/control-structure/for/)

```C
// Dim an LED using a PWM pin
int PWMpin = 10;  // LED in series with 470 ohm resistor on pin 10

void setup() {
  // no setup needed
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(PWMpin, i);
    delay(10);
  }
}
```

### Fading LED 
```C
int value = 0;                            // variable to keep the actual value 
int ledpin = 9;                           // light connected to digital pin 9
 
void setup() 
{ 
  // nothing for setup 
} 
 
void loop() 
{ 
  for(value = 0 ; value <= 255; value+=5) // fade in (from min to max) 
  { 
    analogWrite(ledpin, value);           // sets the value (range from 0 to 255) 
    delay(30);                            // waits for 30 milli seconds to see the dimming effect 
  } 
  for(value = 255; value >=0; value-=5)   // fade out (from max to min) 
  { 
    analogWrite(ledpin, value); 
    delay(30); 
  }  
} 
```

## Unnið með stafræn gildi

Stafrænt (e. digital) gildi getur annaðhvort verið 0 eða 1 (eða á/af, kveikt/slökkt). Í Arduino er búið að skilgreina [fastana (e. constant)](https://www.arduino.cc/reference/en/language/variables/constants/constants/) ```HIGH``` sem 1 (einn) og ```LOW``` sem 0 (núll). Í raun virkar þetta samt þannig að ```HIGH``` getur verið hvaða **8 bita** heiltala sem er fyrir utan 0. Þannig verður t.d. -42 túlkað sem ```HIGH```.

---

### Helstu aðgerðir
[Digital Pins](https://www.arduino.cc/en/Tutorial/Foundations/DigitalPins)

- ```pinMode(PINNI, STADA)``` – stillir pinna sem inntaks eða úttakspinna. Dæmi: ```pinMode(4, OUTPUT);``` setur pinna 4 sem úttakspinna.
- ```digitalWrite(PINNI, GILDI)``` – skrifar annaðhvort ```HIGH``` eða ```LOW``` á pinna. Dæmi: ```digitalWrite(4, LOW);``` skrifar ```LOW``` út á pinna 4.
- ```digitalRead(PINNI)``` – les stöðuna á pinna, staðan á pinnanum getur verið annaðhvort ```HIGH``` eða ```LOW```. 
   - Dæmi: ```int k = digitalRead(4);``` les stöðuna á pinna 4 og geymir í breytunni ```k```.

---

### Digtial Output 

1. [Blink (Halló heimur) með innbyggðu led](https://learn.adafruit.com/ladyadas-learn-arduino-lesson-number-1)
1. [Blink á brauðbretti](https://learn.adafruit.com/adafruit-arduino-lesson-2-leds/overview)

---

### Digital Input 

1. [Pull Up/Down Resistors](https://github.com/VESM2VT/Efni/blob/main/Kennsluefni/PullUp_PullDown_Resistors.md)
1. [Push Button Switch with LED and Pull Down Resistor](https://unciarobotics.com/robotics/interfacing-arduino-push-button-switch-with-led-digitalread/)

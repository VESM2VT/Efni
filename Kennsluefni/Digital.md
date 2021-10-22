## Unnið með stafræn gildi

Stafrænt (e. digital) gildi getur annaðhvort verið 0 eða 1 (eða á/af, kveikt/slökkt). Í Arduino er búið að skilgreina [fastana (e. constant)](https://www.arduino.cc/reference/en/language/variables/constants/constants/) ```HIGH``` sem 1 (einn) og ```LOW``` sem 0 (núll). Í raun virkar þetta samt þannig að ```HIGH``` getur verið hvaða **8 bita** heiltala sem er fyrir utan 0. Þannig verður t.d. -42 túlkað sem ```HIGH```.
- `HIGH` spenna meira en 3.0V á pinna og `LOW` spenna minni en 1.5V á pinna.
- ```pinMode(PINNI, STADA)``` – stillir pinna sem inntaks eða úttakspinna. 
- Dæmi: ```pinMode(4, OUTPUT);``` setur pinna 4 sem úttakspinna. 
- Sjá nánar [Digital Pins](https://www.arduino.cc/en/Tutorial/Foundations/DigitalPins)

---

### Digtial Output 
- ```digitalWrite(PINNI, GILDI)```  skrifar annaðhvort ```HIGH``` eða ```LOW``` á pinna. 
- Dæmi: ```digitalWrite(4, LOW);``` skrifar ```LOW``` út á pinna 4. 
- Pins configured as outputs can be damaged or destroyed if they are connected to either the ground or positive power rails.
- Nánar um [digitalWrite()](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/)

**Tilraun**: Fylgdu verklega eftifarandi tutorials:
1. [Blink (Halló heimur) með innbyggðu led](https://learn.adafruit.com/ladyadas-learn-arduino-lesson-number-1/upload-your-first-sketch)
1. [Blink á brauðbretti](https://learn.adafruit.com/adafruit-arduino-lesson-2-leds/blinking-the-led)

---

### Digital Input 
- ```digitalRead(PINNI)``` – les stöðuna á pinna, staðan á pinnanum getur verið annaðhvort ```HIGH``` eða ```LOW```. 
- Dæmi: ```int k = digitalRead(4);``` les stöðuna á pinna 4 og geymir í breytunni ```k```.
- If the pin isn’t connected to anything, `digitalRead()` can return either HIGH or LOW (and this can change randomly).
- Nánar um [digitalRead() og kóðasýnidæmi (takki + LED)](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/)

**Tilraun:** Settu upp á brauðbretti LED og takka. Skrifaðu Arduino kóða þannig að takkinn virki með LED.

---

### Floating pin.
- With no connection, digital inputs “float” between 0 & 5 volts (LOW & HIGH)
- Myndband (10:00) og kóðasýnidæmi: [Floating pins](https://www.programmingelectronics.com/floating-pins-pull-up-resistors-and-arduino/) (_floating pin, takki, innbyggt led, pullup viðnám_)

**Tilraun:** Fylgdu eftir sýnidæminu í myndbandinu og settu það upp á brauðbretti, notaðu 10K viðnám.

---

### Pull Up resistors og rétt viðnám.
<!--  [Pull Up Resistor (myndband 3:50)](https://www.youtube.com/watch?v=wxjerCHCEMg) -->
<!-- örvarnar í myndbandi þegar smellt er á hnapp er villandi  gefur til kynna að flæði frá 5V í GND sé í lagi, en er short -->

- [Picking Pull-Up Resistor Values (myndband)](https://www.youtube.com/watch?v=u3Xiy2DVnI4&list=PLRIGIzu0Z7KlfGFD6gd0eMX0ozfJyrQL-&index=12)

**Hugleiðingar** Afhverju að nota viðnám en ekki bara vír í 5V fyrir **Pull up**?  En ef ég nota viðnám hverstu stórt þarf ég?

---

### INPUT_PULLUP
- Kóðasýnidæmi [`pinMode(pin, INPUT_PULLUP);` 20K](https://www.arduino.cc/en/Tutorial/DigitalInputPullup)  
- Ekki nota INPUT_PULLUP með pinna 13 þar hann er tengdur við innbyggt LED á Arduino, [sjá nánari skýringar í Digital Pins](https://www.arduino.cc/en/Tutorial/Foundations/DigitalPins). 

---

### Pull Down resistors.
- Með að nota viðnám (10k) í jörð: Resistor “pulls” input to ground (0 volts). 
- Pressing switch “pushes” input to 5 volts. Press is HIGH, Not pressed is LOW. 
- Kóðasýnidæmi 
   1. [Pulldown resistor](https://www.arduino.cc/en/Tutorial/BuiltInExamples/DigitalReadSerial) 
   1. [Push Button Switch with LED and Pull Down Resistor](https://unciarobotics.com/robotics/interfacing-arduino-push-button-switch-with-led-digitalread/)

---


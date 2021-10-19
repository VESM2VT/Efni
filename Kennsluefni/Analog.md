## Að vinna með hliðræn gildi (analog)

---
Stafrænt merki bera upplýsingar eða gögn á tvíundarformi í formi bita (0 og 1). Stafrænt merki hefur endanlegt gildissvið og er ónæmara fyrir truflunum (noise). 

Hliðrænt merki (analog signal) er eins konar samfellt bylgjuform sem breytist með tímanum. Hliðrænu merki er lýst með; sveifluhæð, tíðni og bylgjulengd. Dæmi um einfalt hliðrænt merki er sinusbylgjan. Hliðrænt merki er næmara fyrir truflunum og getur haft óendanlegt gildissvið. 

Hér er [myndband](https://youtu.be/WxJKXGugfh8?t=29) sem skýrir muninn á analog og digital merki.


![AnalogSignal](https://github.com/VESM2VT/Efni/blob/main/Myndir/AnalogSignal.png)  ![DigitalSignal](https://github.com/VESM2VT/Efni/blob/main/Myndir/DigitalSignal.png)

---

### Skynjarar

Hliðræn vinnsla merkja byggist á eðlisfræðilegum eiginleikum íhlutanna í tækinu, sér í lagi samhengi spennu og straums. Með þeim hætti þróuðust tækjaeiningar eins og; síur, magnarar, skynjarar og mótarar.

Hliðrænt merki er fólgið í breytilegri spennu og straumi, er sveiflast sem eftirmynd þess sem kemur frá uppsprettunni. Spennusveifla frá hljóðnema hermir eftir loftsveiflum hljóðsins, svo dæmi sé tekið. <br>

Hér er grein sem fjallar nánar um [analog og digital skynjara](https://iot4beginners.com/analog-sensors-vs-digital-sensors/)

---

### Stafræn- og hliðræn merkjavinnsla (ADC og DAC)

Hliðrænt merki sem tekur samfelldum breytingum rennir sér í gegn um óendanlega mörg mæligildi. Augljóslega er ekki vinnandi vegur að skrá þau öll. Því hraðari sem breytingarnar á hliðræna merkinu eru, því styttra þarf að líða á milli þess að sýni séu tekin. Sýnataka et gerð með jöfnu millibili, öllum gildum merkisins þar á milli er fleygt. <br>

![Merkjavinnsla](https://github.com/VESM2VT/Efni/blob/main/Myndir/DSPmerkjavinnsla.png)

**ADC** (analog digital converter) breytir hliðrænu merki í stafrænt. Stafræna merkið
er talnaruna, skrá yfir hæfilega þétt tekin gildi hliðræna merkisins. 

**DAC** (digital analog converter) breytir stafrænu merki í hliðrænt. Merkið verður þá
aftur hliðrun í spennu og straumi. 

---

## Arduino og analog

---

### Analog inntak
- [analogRead(pin)](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/) 
   - _les gildi frá analog pinna, skilar heiltölu á bilinu 0-1024._

Arduino Uno (og Nano) inniheldur 10-bita ADC sem breytir hliðrænu gildi (spennu) í heiltölu frá 0 til 1023. Hægt er að fá hliðrænt gildi á pinnum A0 til A5. Þá er hægt að nota innbyggðan sveiflusjá (serial plotter) í Arduino IDE til að fylgjast með hliðrænum gildum. Dæmi um inntak með hliðrænu gildum er stilliviðnám, ljósviðnám og stýripinni. 


#### Kóðasýnidæmi með analogRead()
1. [Read Analog Voltage with potentiometer (float)](https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage)
1. [Joystick + serial monitor](https://github.com/VESM2VT/Efni/blob/main/Kodi/styripinni.ino)

<!--
- [`analogReadResolution()`](https://www.arduino.cc/reference/en/language/functions/zero-due-mkr-family/analogreadresolution/)
T il að breyta gildum frá 0-1024 í spennu frá  0.0 og 5.0V, þá 5V / 1024 eða 0.0049V (4.9 mV) pr. unit. 
-->

---

### Analog úttak (PWM) 
- [analogWrite(pin, value)](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/) 
   - _skrifar "analog" gildi á bilinu 0 - 255._

Arduino hefur ekki innbyggðan DAC. Arduino þess í stað vinnur með _pulse-width modulation_ (PWM) bylgju sem er stafrænt merki og er notað til að líkja hliðrænu úttaki.
PWM ("analog") pinnar í Arduino (Uno og Nano) eru; 3, 5, 6, 9, 10 og 11. Úttaksgildi er á bilinu 0-255. 
<br>Hægt er að nota fallið  `map(value, fromLow, fromHigh, toLow, toHigh)` frá hliðrænu inntaki (0-1023) yfir í PMW úttak (0-255).

<!--
![PWM](https://github.com/VESM2VT/Efni/blob/main/Myndir/pwm.gif)
-->

Nánar um PWM; [Theory (PWM)](https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/theory-pwm), [PWM (myndband)](https://www.youtube.com/watch?v=B_Ysdv1xRbA) og [PWM](https://www.arduino.cc/en/Tutorial/Foundations/PWM/).

<!--
_Nano 33 IoT, and Zero boards have true analog output when using analogWrite() on the DAC0 (A0) pin._

Build a simple DAC for your Arduino:
https://create.arduino.cc/projecthub/Arduino_Scuola/build-a-simple-dac-for-your-arduino-4c00bd
-->
#### Kóðasýnidæmi með analogWrite()
1. [Fading LED (for loop)](https://github.com/VESM2VT/Efni/blob/main/Kodi/fadingLED.md)
1. [CandleLight (random)](https://github.com/VESM2VT/Efni/blob/main/Kodi/CandleLight.ino) 
1. [FadeOrBlink with a button](https://github.com/VESM2VT/Efni/blob/main/Kodi/fadeorblink.ino)
1. [RGB LEDs (HEX)](https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/overview)

---

<!--
Tímaverkefni án þess að hafa sýnidæmi eða lausn:
1. [Experiment 1: Controlling the Brightness of an LED](https://www.allaboutcircuits.com/projects/using-the-arduinos-analog-io/)
1. [Experiment 2: Brightness Control Using a Potentiometer](https://www.allaboutcircuits.com/projects/using-the-arduinos-analog-io/)
-->


<!--
### Spurningar
- Hver er meginn munurinn á digital og analog skynjara? 
- Hvað er verkhlutfall (e. duty cycle) og hvernig tengist það tíðni (e. frequency)?
- Tíðni (e. frequnzy) er mæld í Hertz (Hz). Útskýrðu hvernig það er gert.
- Afhverju þarf úttakið í analogWrite að vera á bilinu 0-255?
- Útskýrðu færibreyturnar og gildin í map fallinu. 
   - `analogWrite(9, map(sensorValue, 0, 1023, 0, 255));`
- Hvað gerist ef við tengjum digital skynjara við analog pinna?
-->

### 5.1 Interrupts 
1. Kynntu þér hvernig interrupts virkar og svaraðu eftirfarandi spurningum:
   1. Hvernig notar þú interrupts?
   1. Hvenær er heppilegt að nota interrupts. komdu með dæmi?
   1. Hvað eru volatile breytur?
1. Settu upp verklega kóða sem notar takka og led með notkun interrupts.

**Bjargir:**
- [Myndband; Arduino Interrupts](https://www.youtube.com/watch?v=QtyOiTw0oQc) 
- [Vefgrein: Interrupt Service Routines (ISR)](http://gammon.com.au/interrupts)
- [attachinterrupt()](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)
- Adafruit - Multi-tasking the Arduino (notar class); [Part 1: millis](https://learn.adafruit.com/multi-tasking-the-arduino-part-1) og [Part 2: interrupts](https://learn.adafruit.com/multi-tasking-the-arduino-part-2/overview)

---

### 5.2 SPI samskiptastaðallinn. 
Lestu [BASICS OF THE SPI COMMUNICATION PROTOCOL](https://www.circuitbasics.com/basics-of-the-spi-communication-protocol), sjá einnig [myndband um SPI](https://www.youtube.com/watch?v=ldRkXTBw9_o) og svaraðu eftirfarandi spurningum:
   
   1. Hvað er átt við með samstilltum (e. synchronous) samskiptastaðli?
   1. Útskýrðu master-slave samskipti í SPI útfrá; MISO, MOSI, SCLK og CS/SS.
   1. Hverjir eru helstu kostir og ókostir við SPI?

---

### 5.3 SPI samskipti milli tveggja Arduino. 
Settu upp á Breadboard með Arduino Uno og [Nano](https://www.arduino.cc/en/pmwiki.php?n=Main/ArduinoBoardNano) þannig að þeir geti notað SPI samskipti með [SPI safninu](https://www.arduino.cc/en/reference/SPI) til að tala saman.
1. Arduino Uno á að geta sent streng (nafnið þitt) til Arduino Nano sem birtir svo nafn á Serial Monitor. Sjá t.d. [How do you use SPI on an Arduino?](https://arduino.stackexchange.com/questions/16348/how-do-you-use-spi-on-an-arduino).
1. Bættu takka við Arduino Uno. Þegar ýtt er á hann þá á led sem er tengt við Arduino Nano að lýsa. 
1. Bættu við öðrum takka og led, sjá [uppsetningu](https://raw.githubusercontent.com/VESM3/V21/master/Myndir/SPI.png)  þannig að hægt sé að eiga samskipti í báðar áttir með tökkum. Sjá [kóða](https://gist.github.com/gestskoli/d2069beb5c4d0cf7c9351d75dfc3e2b0) og [Communication between two Arduino Boards](https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial)  

---

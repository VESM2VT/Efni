## Forritað með Serial Monitor

Bjargir:
- [Skrifað í Serial Monitor](https://github.com/VESM2VT/Efni/blob/main/Kennsluefni/ArduinoForritun.md#skrifað-%C3%AD-serial-monitor)
- [Lesið frá Serial Monitor](https://github.com/VESM2VT/Efni/blob/main/Kennsluefni/ArduinoForritun.md#lesið-inn-frá-serial-monitor)

Munum að alltaf þegar nota á Serial Monitor þarf að setja ```Serial.begin(9600);``` í ```setup``` fallið.

---

### Serial Monitor "Hello World!"

Opnaðu Arduino IDE forritið og búðu til nýtt Sketch (File -> New). Það ætti að opnast í nýjum glugga með ```setup``` og ```loop``` föllum.

Skrifaðu svo viðeigandi línu í ```setup``` fallið til að virkja Serial samskiptin.

Skrifaðu svo í ```loop``` fallið viðeigandi línu þannig að þegar forritið keyrir að þá birtist á Serial Monitor "Hello from Arduino".

**Til umhugsunar**, hvernig breytist úttakið í Serial Monitor eftir því hvort þú notar ```print``` eða ```println```.

---

### Halló og bless

Aukabjargir: [Skilyrðissetningar](https://github.com/VESM2VT/Efni/blob/main/Kennsluefni/ArduinoForritun.md#skilyrðissetningar)

Skrifaðu forrit sem les inn einn staf frá Serial Monitor. Ef stafurinn er ```h``` á að skrifa til Serial Monitor **"halló"** en ef stafurinn er ```b``` á að skrifa **"bless"**.

---

### Í hástafi

Aukabjargir: [Strengir í Arduino (sjá sérstaklega ```toUpperCase()```)](https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/)

Skrifaðu forrit sem les inn textastreng frá Serial Monitor og skilar sama streng aftur til Serial Monitor nema að búið er að setja alla stafina í strengnum í hástafi.

**Til umhugsunar**, birtist strengurinn aftur og aftur í Serial Monitor? Ef svo er, hvernig getur þú látið hann birtast bara einu sinni. Ef ekki, hvernig getur þú látið hann birtast aftur og aftur.

### Þín eigin mínustala

Aukabjargir:

- [Strengir í Arduino (sjá sérstakelga ```toInt()```)](https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/)
- Til að snúa bitum er notaður **ekki** (e. not) bitavirkinn (e. bitwise operator) og er táknið fyrir hann ```~``` (tildamerkið).

Skrifaðu forrit sem les inn talnastreng og breytir þeirri tölu svo í mínustölu með því að nota þína eigin útfærslu á [tvíundafyllingu](https://github.com/VESM2VT/Efni/blob/main/Kennsluefni/ArduinoForritun.md#unsinged-hvernig-geyma-tölvur-m%C3%ADnustölur).

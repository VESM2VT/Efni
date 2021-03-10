# Forritun Arduino

Arduino er forritað með Arduino málinu sem er mjög líkt og [C](https://en.wikipedia.org/wiki/C_(programming_language)) og [C++](https://en.wikipedia.org/wiki/C%2B%2B) málin.

* [Arduino forritunarmálið (reference á ensku)](https://www.arduino.cc/reference/en/)
* [Samanburður á Python og Arduino C/C++ (pdf)](https://github.com/VESM2VT/Efni/blob/master/Skjol/CogPython.pdf)

---

## Efnisyfirlit

- [Breytur](#breytur)
- [Reyknivirkjar](#reiknivirkjar)
- [Athugasemdir í kóða](#athugasemdir-í-kóða)
- [Föll](#föll)
- [Skrifað í Serial Monitor](#skrifað-í-serial-monitor)
- [Lesið frá Serial Monitor](#lesið-inn-frá-serial-monitor)
- [Rökvirkjar](#rökvirkjar)
- [Skilyrðissetningar](#skilyrðissetningar)
- [Lykkjur](#lykkjur)

## Breytur

Ólíkt python þá þarf alltaf að taka fram af hvaða tagi breytur eru í Arduino. Með taginu er ákveðið hvað breytan á að geyma (t.d. heiltölu, kommutölu eða bókstaf).

### Dæmi

```c++
int heiltala = 42;
float kommutala = 3.14;
char bokstafur = 'a';
String texti = "VESM2VT og Arduino";
bool satt = true;
```

Um leið og ákveðið er af hvaða tagi breytan er þá er ákveðið hversu mikið pláss breytan tekur í minni Arduino tölvunnar. Það hversu mikið pláss í minni breytan tekur stjórnar svo t.d. hversu stóra tölu er hægt að láta breytuna geyma.

### Helstu tög og stærðir þeirra

- [```int```](https://www.arduino.cc/reference/en/language/variables/data-types/int/) tekur 16 bita í minni og getur geymt heiltölur á bilinu -32768 til 32767.
  - [```unsigned int```](https://www.arduino.cc/reference/en/language/variables/data-types/unsignedint/) ef ekki er gert ráð fyrir að breyta geymi mínustölu má setja orðið ```unsigned``` fyrir framan tagið og getur þá ```int``` breyta geymt heiltölur á bilinu 0 til 65535.
- [```long```]() tekur 32 bita í minni og getur geymt heiltölur á bilinu -2147483648 til 2147483647. Hægt að nota með ```unsigned```.
- [```float```](https://www.arduino.cc/reference/en/language/variables/data-types/float/) tekur 32 bita í minni og geymir kommutölur með nákvæmni upp á 6 aukastafi.
- [```char```](https://www.arduino.cc/reference/en/language/variables/data-types/char/) tekur 8 bita í minni og getur geymt einn bókstaf í [ASCII](https://www.arduino.cc/en/Reference/ASCIIchart) stafakerfinu eða heiltölu á bilinu -128 til 127. Hægt að nota með ```unsigned```.
- [```String```](https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/) tekur eins mikið minni og þarf. Geymir textastrengi.
- [```bool```](https://www.arduino.cc/reference/en/language/variables/data-types/bool/) tekur 8 bita í minni. Getur geymt annaðhvort ```false``` (jafngildir 0) eða ```true``` (**öll önnur gildi** en 0).

### ```unsigned```, hvernig geyma tölvur mínustölur?

Eins og allt annað sem tölvur vinna með þá eru tölur geymdar í tvíundakerfinu í minni. Talan 42 er því geymd sem 101010. Eins og kemur fram í umfjölluninni hér fyrir ofan þá taka breytur mismikið pláss í minni eftir því hvernig þær eru skilgreindar. Ef talan 42 er geymd í ```char``` breytu þá tekur hún 8 bita pláss í minninu og geymd sem 00101010 en ef hún er geymd í ```int``` breytu (sem tekur 16 bita) þá er hún geymd sem 0000000000101010.

En hvað með -42, hvernig er hægt að geyma þá tölu t.d. í ```char``` breytu? Aðferðin sem notuð er heitir tvíundafylling (e. [2's complement](https://en.wikipedia.org/wiki/Two's_complement)) og virkar þannig að til að finna mínus tölu af annarri tölu tökum við bitana og snúm þeim við (1 verður 0 og 0 verður 1) síðan leggjum við einn við nýju tölun.

#### Dæmi

Hvernig er -42 í ```char``` (8 bita tala) breytu:

```
Tökum 42        00101010

Snúum bitunum   11010101
Leggjum 1 við  +       1
               ---------
Útkoman verður  11010110  túlkað af tölvum sem -42
```

En ef breytan væri ```int``` (16 bita tala)?:

```
Tökum 42        0000000000101010

Snúum bitunum   1111111111010101
Leggjum 1 við  +               1
               -----------------
Útkoman verður  1111111111010110  túlkað af tölvum sem -42
```

Þegar tölvur geyma mínustölur þá er í raun einn biti tekinn og notaður til að segja til um hvort þetta er mínus eða plús tala. Þannig hefur t.d. ```char``` breyta í raun aðeins 7 bita til að geyma töluna og svo 1 bita til að segja merkið (plús eða mínus). Þetta merki er í ensku kallað **sign** og þegar við notum breytur með ```unsigned``` þá erum við að segja að við ætlum að nota alla 8 bitana fyrir töluna og ætlum ekki að nota einn af bitunum til að setgja til um hvort þetta er plús eða mínus tala. Þessvegna getur ```char``` breyta geymt -128 til 127 en ```unsigned char``` breyta geymt 0 til 255.

## Reiknivirkjar

Reiknivirkjarnir virka eins í Arduino og Python. Þó eru til tveir reiknivirkjar í Arduino sem ekki eru til í Python:

- ```++``` virkinn sem er notaður til að hækka gildi breytu um 1.
- ```--``` virkinn sem er notaður til að lækka gildi breytu um 1.

### Dæmi

```c++
int k = 7;
k++; // Eftir keyrslu línunnar er innihald k 8
k--; // Eftir keyrslu línunnar er innihald k 7
```

## Athugasemdir í kóða

```c++
// athugasemd í einni línu

/* 
  athugasemd í 
  mörgum línum
*/
```

## Föll

Svipað og með breyturnar þá þarf að taka fram í Arduino hvaða tagi fallið skilar og af hvaða tagi færibreyturnar eru.

**Python**

```python
def leggjaSaman(a , b)
  return a + b
```

Ólíkt python þar sem inndráttur markar gildissvið fallsins þá eru notaðir slaufusvigar ```{``` og ```}``` til að marka gildissvið falla í Arduino.

**Arduino**

```c++
int leggjaSaman(int a, int b) {
  return a + b;
}
```

### ```void``` lykilorðið

Ef fall á ekki að skila neinu, inniheldur semsagt ekki ```return``` skipun, þarf að skilgreina það sem ```void```:

```c++
void fallSemSkilarEngu() {
  // föll sem ekki skila neinu þarf að skilgreina með void
}
```

### Setup og loop

Arduino forrit þurfa að innihalda tvö ákveðin föll. Það eru föllin ```setup``` og ```loop```. ```setup``` fallið keyrir einu sinni en ```loop``` fallið keyrir aftur og aftur eins lengi og kveikt er á Arduino tölvunni. Þessi tvö föll skila engu og eru því skilgreind sem ```void```.

Í python væri loop fallið því útfært svona:

```python
def loop():
  while True:
    # kóðinn sem á að keyra
```

Í Arduino þarf ekki að útfæra lykkjuna í fallinu, hún gerist sjálfkrafa:

```c++
void loop() {
  // kóðinn sem á að keyra
}
```

## Skrifað í Serial Monitor

Arduino er ekki með skjá en notaður er Serial Monitor sem hægt er að skrifa út á.

Til að opna Serial Monitor er hægt að smella á stækkunarglerið ef í hægra horninu á Arduino IDE forritinu.

![Velja Serial Monitor](https://raw.githubusercontent.com/VESM2VT/Efni/main/Myndir/SerialMonitorIcon.png)

Einnig er hægt að nota flýtilyklana Ctrl+Shift+M í Windows og Linux eða Shift-Cmd-M í MacOS.

![Serial Monitor](https://raw.githubusercontent.com/VESM2VT/Efni/main/Myndir/SerialMonitorGluggi.png)

Virkja þarf ```Serial``` samskiptin í setup fallinu og velja á hvaða hraða þau eiga fara fram Eftir það er hægt að nota ```Serial``` skipanirnar.

Helstu skipanir sem notaðar eru til að skrifa til Serial Monitor:

```Serial.begin(HRAÐI)``` þarf að vera í ```setup``` fallinu hér er samskiptahraðinn ákveðinn. Hann þarf að vera sá sami og í Serial Monitor glugganum.

```Serial.print(TEXTI/TALA/BREYTA)``` notað til að skrifa til Serial Monitor án þess að færa bendilinn í nýja línu.

```Serial.println(TEXTI/TALA/BREYTA)``` notað til að skrifa til Serial Monitor færir bendilinn í nýja línu.

_Taktu einnig eftir því að TX LED blikkar þegar send eru skilaboð/kóði í tölvu._<br>
_RX LED blikkar þegar skilaboð eru móttekin frá tölvu_

### Dæmi

```c++
void setup() {
  Serial.begin(9600); 
}

void loop() {
  Serial.println("Arduino");
}
```

## Lesið inn frá Serial Monitor

Þó að yfirleitt sé verið að lesa frá pinnum með Arduino má einnig lesa frá tölvunni sem er tengd við Arduino með því að nota Serial Monitor.

Helstu aðferðir sem notaðar eru til að lesa frá Serial Monitor.

```Serial.begin(HRAÐI)``` þarf að vera í ```setup``` fallinu eins og þegar skrifað er til Serial Monitor.

```Serial.available()``` er notað til að athuga hvort verið er að senda eitthvað til okkar með Serial.

```Seria.read()``` er notað til að lesa **einn** staf frá Serial Monitor.

```Serial.readString()``` er notað þegar lesa á marga stafi eða streng frá Serial Monitor.

### Dæmi

Lesa einn staf frá Serial Monitor

```c++
char stafur = 0; // skilgreina breytu til að geyma það sem á að lesa og frumstilla hana með núll

void setup() {
  Serial.begin(9600); // byrja á að stilla hraðann á serial tengingunni
}

void loop() {
  if(Serial.available() > 0) { // Athuga hvort eitthvað er að koma frá Serial Monitor
    stafur = Serial.read(); // lesa frá Serial Monitor
  }
  if(stafur == 'k') {
    // Gera eitthvað ef stafurinn k var lesinn frá Serial Monitor
  }
}
```

## Rökvirkjar

Rökvirkjarnir er almennt skrifaðir eins og rökvirkjarnir í Python fyrir utan:

Python | Arduino
--- | ---
and | &&
or | \|\|
not | !

## Skilyrðissetningar

### ```if``` setningin

Virkar eins og í Python en notar meira af svigum og slaufusvigar stjórna gildissviði en ekki inndráttur.

#### Dæmi

```c++
if(k < 10) {
  // Það sem á að gerast ef k er minna en 10
} else if(k > 10) {
  // Það sem á að gerast ef k er stærra en 10
} else {
  // Það sem á að gerast ef k er sama sem 10
}
```

### ```switch-case``` setningin

Þetta er notað til að bera gildi breytu við mörg önnur mismunandi gildi. **ATH.** ```switch-case``` getur eingöngu unnið með heiltölugildi.

#### Dæmi

Munum að bókstafir eru talnagildi ([ASCII](https://www.arduino.cc/en/Reference/ASCIIchart)) þannig er t.d. bókstafurinn *a* jafngildur tölunni 97.

```c++
char k = 'a';  

switch (k) { // könnum innihald breytunnar k
  case 'a':
    // það sem á að gerast ef k er a
    break; // verður að vera til að hoppa úr skilyrðissetningunni þegar rétt gildi er fundið
  case 'b':
    // það sem á að gerast ef k er b
    break;
  case 'u':
    // það sem á að gerast ef k er u
    break;
  default:
    // það sem á að gerast ef k er eitthvað annað
    break;
}
```

### Þríundavirkinn

Þríundavirkinn (e. ternary operator) er bara ```if``` setning í einni línu. Fyrir ```if``` er notað ```?``` og fyrir ```else``` er notað ```:```.

#### Dæmi

Ef að x er mynna en 10 viljum við að y verði 20 annars á y að verða 30.

```c++
y = (x < 10) ? 20 : 30;
```

## Lykkjur

**ATH.** Gott er að muna að ```loop``` fallið er lykkja og oft er hægt að nýta sér það í stað þess að setja lykkju inn í ```loop``` fallið.

Í Arduino eru annars til þrjár mismunandi lykkur.

### ```while``` lykkjan

```while``` lykkjan í Arduino er alveg eins og ```while``` lykkjam í Python nema með fleiri svigum og slaufusvigar en ekki inndráttur marka gildissvið.

#### Dæmi

```c++
while (k < 10) {
  // gera það sem á að gera meðan k er minna en 10;
  k++;
}
```

### ```do-while``` lykkjan

Þessi lykkja virkar eins og ```while``` lykkjan fyrir utan að hún keyrir alltaf að minnsta kosti einu sinni. Skilyrðisathugunin fer fram í lok lykkjunnar.

#### Dæmi

```c++
do {
  // gera það sem á að gera meðan k er minna en 10;
  k++;
} while (k < 10); // ATH. semikomma í lokin
```

### ```for``` lykkjan

Í Arduino er ```for``` lykkjan talsvert ólík ```for``` lykkjunni í Python. ```for``` lykkjan er í raun bara ```while``` lykkja með öllu inniföldu.

![while og for](https://raw.githubusercontent.com/VESM2VT/Efni/main/Myndir/whilefor.png)


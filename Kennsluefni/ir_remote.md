# IR Remote


![IR](https://github.com/VESM2VT/Efni/blob/main/Myndir/ir_remote_merking_sm.png)

### Kóðar frá fjarstýringu

Tákn | HEX | Tákn í kóða
---: | :--- | ---
CH- | FFA25D | a
CH | FF629D | b
CH+ | FFE21D | c
PREV | FF22DD | d
NEXT | FF02FD | e
PLAY/PAUSE | FFC23D | f
VOL- | FFE01F | g
VOL+ | FFA857 | h
EQ | FF906F | i
100+ | FF9867 | j
200+ | FFB04F | k
0 | FF6897 | 0
1 | FF30CF | 1
2 | FF18E7 | 2
3 | FF7A85 | 3
4 | FF10EF | 4
5 | FF38C7 | 5
6 | FF5AA5 | 6
7 | FF42BD | 7
8 | FF4AB5 | 8
9 | FF52AD | 9
Takka haldið inni | FFFFFFFF | Ekki notað hér

### Kóðar í fylki

```c++
const unsigned long kodar[] = { 0xFFA25D,
                                0xFF629D,
                                0xFFE21D,
                                0xFF22DD,
                                0xFF02FD,
                                0xFFC23D,
                                0xFFE01F,
                                0xFFA857,
                                0xFF906F,
                                0xFF9867,
                                0xFFB04F,
                                0XFF6897,
                                0xFF30CF,
                                0xFF18E7,
                                0xFF7A85,
                                0xFF10EF,
                                0xFF38C7,
                                0xFF5AA5,
                                0xFF42BD,
                                0xFF4AB5,
                                0xFF52AD };

const char takn[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                     'h', 'i', 'j', 'k', '0', '1', '2',
                     '3', '4', '5', '6', '7', '8', '9' };
```

### Einfalt "lookup" fall

Notar fylkin hér að ofan.

```c++
char finnaTakn(unsigned long kodiFraRemote) {
    for(int i = 0; i < 21; i++)
        if(kodar[i] == kodiFraRemote)
            return takn[i];
    return 'x'; // kóði finnst ekki
}
```

### Dæmi um útfærslu á lykilorði

Lykilorð slegið inn og svo ýtt á **a** til að staðfesta.

```c++
#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

String lesaLykilord = ""; // innsláttur skrifast í þetta
String lykilord = "1234";
char stadfestaTakn = 'a'; // ýtt á 'a' til að kanna lykilorð

const unsigned long kodar[] = {  0xFFA25D,
                                 0xFF629D,
                                 0xFFE21D,
                                 0xFF22DD,
                                 0xFF02FD,
                                 0xFFC23D,
                                 0xFFE01F,
                                 0xFFA857,
                                 0xFF906F,
                                 0xFF9867,
                                 0xFFB04F,
                                 0XFF6897,
                                 0xFF30CF,
                                 0xFF18E7,
                                 0xFF7A85,
                                 0xFF10EF,
                                 0xFF38C7,
                                 0xFF5AA5,
                                 0xFF42BD,
                                 0xFF4AB5,
                                 0xFF52AD
                              };

const char takn[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                     'h', 'i', 'j', 'k', '0', '1', '2',
                     '3', '4', '5', '6', '7', '8', '9'
                    };

char finnaTakn(unsigned long kodiFraRemote) {
  for (int i = 0; i < 21; i++)
    if (kodar[i] == kodiFraRemote)
      return takn[i];
  return 'x';
}

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    char innslegidTakn = finnaTakn(results.value);
    if (innslegidTakn != 'x') {
      lesaLykilord += innslegidTakn;
    }
    irrecv.resume(); // Receive the next value
  }
  if (lesaLykilord.endsWith(lykilord + 'a')) {
    Serial.println("------Rett Lykilord------");
    lesaLykilord = "";
  }
  if (lesaLykilord.length() > 20) { // til að minnið fyllist ekki af strengnum
    lesaLykilord = lesaLykilord.substring(10);
  }
}
```


## Að tengja LED Matrix (með 8x220R viðnám)
1. [horfðu á myndband sem útskýrir nánar 8x8 LED Matrix](https://www.youtube.com/watch?v=G4lIo-MRSiY)
   * ath. við erum með aðra Matrix tegund, dálkur verður HIGH til að fá ljós en það er LOW í myndbandi (öfugt)
1. [finndu pinna 1 og 16 með prófun (mundu að nota viðnám fyrir báða pinna)](
https://www.circuitspecialists.com/blog/getting-started-with-an-led-matrix-tutorial/)
1. prófaðu að kveikja á völdu LED peru í Matrix.
1. tengdu heila röð og einn dálk (munda að tengja 8 x raðir með viðnám í GND)
1. tengdu alla 8 x dálkana og fáðu ljós í allar 64 LED perur.
1. tengdu datapinna úr Arduino við LED Matrix [skv töflu og mynd](https://www.arduino.cc/en/Tutorial/RowColumnScanning)

<br>

## Kóðun
1. Kveiktu á einni LED peru í Matrix (geturu látið hana líka blikka?) 
1. birtu eina röð eða dálk (notaðu fylki og lykkju) 
1. prófaðu [Row-columm Scanning aðferð til að stýra LED peru með 2 x breytiviðnámi](https://www.arduino.cc/en/Tutorial/RowColumnScanning)
      * ath. þú verður að víxla LOW og HIGH í kóðanum til að virki fyrir okkar MATRIX íhlut
      * [MatrixRow-columm scanning útskýrt frá 3:20 - 6:45 mín](https://www.youtube.com/watch?v=G4lIo-MRSiY)
      * prófaðu að skipta út breytiviðnámi fyrir stýripinna (joystick) til að stýra ljósi
<!--   
* Að birta bókstaf eða broskall með e. row-columm scanning.
   * [how to send bytes to an 8x8 LED matrix](https://www.hackster.io/SAnwandter1/programming-8x8-led-matrix-23475a) 
   * [how to create a letter](https://www.youtube.com/watch?v=xQZ_rrt7hF4)
 
1. [birtu orð (scrolling message)](https://playground.arduino.cc/Main/DirectDriveLEDMatrix/)
   * [Library: FrequencyTimer2](https://playground.arduino.cc/Code/FrequencyTimer2/)

<br>
 * [Dot Matrix online genarator](http://dotmatrixtool.com/#)

**LED Matrix með shift register** (í vinnslu)

* [LED Matrix + shift register (myndband)](https://www.youtube.com/watch?v=NM7wXta8crM&list=PLJse9iV6Reqgy8sdjBwKDwihQdbSxbcNg) 
* [Interfacing 8×8 LED Matrix with Arduino](http://www.circuitstoday.com/interfacing-8x8-led-matrix-with-arduino)
* [Controlling an LED Matrix](https://www.instructables.com/id/Controlling-An-LED-Matrix/)
* [Multiplexing With Arduino and the 74HC595](https://www.instructables.com/id/Multiplexing-with-Arduino-and-the-74HC595/)

-->
<br>

## Layout á 8x8 LED matrix
* [tafla og schematics](https://www.arduino.cc/en/Tutorial/RowColumnScanning)
* [Datasheet: 1088AS 8x8 LED matrix](http://www.datasheetcafe.com/1088as-datasheet-matrix-led-display/)
   * Ath. það eru til tvær tegundir til af 8x8 LED Matrix

#### matrix pinnar
* pin 1 =  fyrsti stafur 1 í model nr.
* pin 16 = beint á móti pin 1 (þvert yfir LED Matrix)

#### raðir
* röð nr 8 er samliða model nr. og er næst því.
* röð nr 1 er fjærst model nr, samliða

#### dálkar
* dálkur er útfrá model númeri 90 gráður.
* dálkur 1 = útfrá pin 1
* dálkur 8 = útfrá pin 8 

#### tengingar á virum
* dálkur 1 = pin nr. 13
* dálkur 2 = pin nr. 3
* dálkur 3 = pin nr. 4
* dálkur 4 = pin nr. 10
* dálkur 5 = pin nr. 6
* dálkur 6 = pin nr. 11
* dálkur 7 = pin nr. 15
* dálkur 8 = pin nr. 16

* röð 1 = pin nr. 9
* röð 2 = pin nr. 14
* röð 3 = pin nr. 8
* röð 4 = pin nr. 12
* röð 5 = pin nr. 1
* röð 6 = pin nr. 7
* röð 7 = pin nr. 2
* röð 8 = pin nr. 5

#### viðnám
* 8 x 220 viðnám, eru tengd í GND og í e. pins fyrir raðir á LED Matrix

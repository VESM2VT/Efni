### Bíll
1. Samsetning og lóðun: Grind og dc motorar, sjá [(myndband)](https://youtu.be/oCacTJyINAM) 
1. Prófað Að samhliða tengja báða 2 dc mótora við L298N DC Motor Driver. Væri kannski betra að raðtengja þau?
1. Kynntu þér [L298N Motor Driver IC](https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/#l298n-motor-driver-ic), sjá einnig hér [myndband](https://www.youtube.com/watch?v=Ey4xoG970Go)
1. Fylgdu tutorial [Dual Channel H-Bridge Motor Driver Board L298N](https://dronebotworkshop.com/dc-motors-l298n-h-bridge/), fyrst með tvö stilliviðnám og svo [stýripinna](https://lastminuteengineers.com/joystick-interfacing-arduino-processing/).
1. Gerðu bílinn sjálfkeyrandi, áfram, aftur, beygja til vinstri/hægri, stoppa, random.
1. Bættu við árekstrarvarnarbúnaði með Ultrasonic. Sjá t.d [Workshoo: Ultrasonic+servo](https://dronebotworkshop.com/elegoo-robot-car-part-3/) 

---

### L298N DC Motor Driver og batterý
- L298N er með 2V drop
- dc motórar eru 3-6V  

**Jumper ON** 
- 5V regulator enabled og logic on. Batterí útvegar rafmagn til mótora og L298N logic
- Það er einnig hægt að nota 5V sem output pin með 0.5A til að knýja Arduino, ef það er tengdur vír í 5V á Arduino (ekki gera samt)
- Max 12V
- Má alls ekki nota bæði batterí og 5V sem input frá Arduino.

**Jumper OFF**
- Arduino útvegar L298N rafmagn fyrir logic með 5V pinna frá Arduino
- batterí útvager dc móturum rafmagn.
- MAX 35V


<!-- 
sjá [mynd](https://youtu.be/WlQ-E6P1jkY) (sleppa IR hlutanum í lokin, nota AA batterý) og [grein](https://www.instructables.com/Simple-CAR-Arduino-IR-Controlled/)
-->

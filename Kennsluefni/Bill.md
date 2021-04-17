### Bíll
1. Samsetning og lóðun: Grind og dc motorar, sjá [(myndband)](https://youtu.be/oCacTJyINAM) 
1. Samsetning: L298N DC Motor Driver með 4 x dc móturum. sjá [myndband](https://youtu.be/WlQ-E6P1jkY) (sleppa IR hlutanum í lokin, nota AA batterý) og [grein](https://www.instructables.com/Simple-CAR-Arduino-IR-Controlled/)
1. Kynntu þér [L298N Motor Driver IC](https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/#l298n-motor-driver-ic) 
1. Fylgdu tutorial [Dual Channel H-Bridge Motor Driver Board L298N](https://dronebotworkshop.com/dc-motors-l298n-h-bridge/), fyrst með tvö stilliviðnám og svo [stýripinna](https://lastminuteengineers.com/joystick-interfacing-arduino-processing/).
1. Gerðu bílinn sjálfkeyrandi, áfram, aftur, beygja til vinstri/hægri, stoppa, random.
1. Bættu við árekstrarvarnarbúnaði með Ultrasonic.

---

### L298N DC Motor Driver og batterý
L298N er með 2V drop, t.d. 6V mótor fær þá mest 4V

**Jumer ON**
- 5V regulator enabled og logic on.
- 5V input verður output pin með 0.5A til að knýja Arduino (notat vin pinna sem input).
- Max 12V
- Má alls ekki nota bæði batterí og 5V sem input.

**Jumper OFF**
- Arduino útvegar L298N rafmagn fyrir logic með 5V pinna á Arduino
- MAX 35V



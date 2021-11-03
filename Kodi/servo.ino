/* Servo mótor.
 * Brúnn tengist í GND, rauður tengist í 5V og 
 * appelsínugulur í pinnann sem stjórnar snúningnum
 */

#include <Servo.h> // Sambærilegt og import í python

Servo motor; // bý til tilvik af Servo klasanum
int motor_pinni = 9; // pinninn sem ég nota til að stjórna mótornum

void setup() {
  motor.attach(motor_pinni); // segi servo tilvikinu hvaða pinna á að nota
}

void loop() {
  // Servo mótorinn getur snúist 90° til vinstri og 90° til hægri, samtals 180°.
  // write fallið tekur á móti gráðunum
  motor.write(0); // mótorinn fer lengst til vinstri
  delay(1000);
  motor.write(90); // mótorinn fer í miðjuna
  delay(1000);
  motor.write(180); // mótorinn fer lengst til hægri
  delay(1000);
}

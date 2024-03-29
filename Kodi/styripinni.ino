/*
  Hvernig á að tengja: 
  G tengist í GND
  V tengist í +5V
  X tengist í A0
  Y tengist í A1
  B tengist í digital pinna
*/

const int x = A0;
const int y = A1;
const int takki = 2;

int x_hreyfing = 0;
int y_hreyfing = 0;
int takki_stada = 0;

void setup() {
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(takki, INPUT_PULLUP); 

  Serial.begin(9600); 
}

void loop() {
  x_hreyfing = analogRead(x);
  y_hreyfing = analogRead(y);
  takki_stada = digitalRead(takki);
  
  Serial.print("X: ");
  Serial.print(x_hreyfing);
  Serial.print(" | Y: ");
  Serial.print(y_hreyfing);
  Serial.print(" | Takki: ");
  Serial.println(takki_stada);

  delay(100);
}

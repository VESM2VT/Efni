const int LED = 2;
const int LED2 = 10;
const int TAKKI = 8;
const int TAKKI2 = 9;

unsigned long lidinn_timi = 0;
unsigned long timi_nuna;
int bidtimi = 1000;
bool ljos_on = true;

bool LED_on = true; // false er 0, true er 1
                    // LOW er 0, HIGH er 1
int takkastada_adur = HIGH; // sama 1



void setup() {
    pinMode(LED, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(TAKKI, INPUT_PULLUP);
    pinMode(TAKKI2, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop() {
    int takkastada = digitalRead(TAKKI);
 
    if(takkastada == LOW && takkastada_adur == HIGH) {
        LED_on = !LED_on;
    }
    takkastada_adur = takkastada;
    
    digitalWrite(LED, LED_on);

    timi_nuna = millis();
    if(timi_nuna - lidinn_timi > bidtimi) {
        ljos_on = !ljos_on;
        lidinn_timi = timi_nuna;
    }
    digitalWrite(LED2, ljos_on);
   /* if(ljos_on == true) {
        digitalWrite(LED2, HIGH);
    } else {
        digitalWrite(LED2, LOW);
    } */
}

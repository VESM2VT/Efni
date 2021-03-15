int takki = 10; // tengdur sem almennt HIGH
int takkaljos = 9;
int blikkljos = 2;

int takki_stada = HIGH; 
int blikktimi = 1000; 
unsigned long lidinn_blikk_timi = 0; // int er bara 16 bita, long er 32 bita
int blikkljos_stada = HIGH; // viljum við byrja með blikkljósið kveikt eða slökt?


void setup() {
	pinMode(takki, INPUT);
  pinMode(takkaljos, OUTPUT);
  pinMode(blikkljos, OUTPUT);
}

void loop() {
  unsigned long timi_nuna = millis(); // millis() skilar fjölda millisekúndna síðan forritið byrjaði að keyra
  
  if((timi_nuna - lidinn_blikk_timi) >= blikktimi) { 
  	
    lidinn_blikk_timi = timi_nuna; // geymum núverandi tímatalningu
    
    if(blikkljos_stada == LOW) { // víxlum stöðunni á ljósunum
    	blikkljos_stada = HIGH;
    } else {
    	blikkljos_stada = LOW;
    }
  }
  digitalWrite(blikkljos, blikkljos_stada);
  
  takki_stada = digitalRead(takki);  
  if(takki_stada == LOW) {
  	digitalWrite(takkaljos, HIGH);
  }
}

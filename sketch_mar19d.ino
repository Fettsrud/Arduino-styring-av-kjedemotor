int pinUt = 3; //Trykknapp for kjøring av motor ut
int pinInn = 2; //Trykknapp for kjøring av motor inn
int pinStopp = 4; //Trykknapp for stopp
int pinRelUt = 5; //Rele for kjøring av motor ut
int pinRelInn = 6; //Rele for kjøring av motor inn
int pinUtStatus = 0;
int pinInnStatus = 0;
int pinStoppStatus = 0;
int pinRelUtStatus = 0;
int pinRelInnStatus = 0;
const int pinSpenning = A0; //Måling av spenning over motstand i serie med motor(klemmsikring)
int spenning = 0;


void setup() {
pinMode(pinUt, INPUT_PULLUP);
pinMode(pinInn, INPUT_PULLUP);
pinMode(pinStopp, INPUT_PULLUP);
pinMode(pinRelUt, OUTPUT);
pinMode(pinRelInn, OUTPUT);
Serial.begin(9600);
}

void loop() {
pinUtStatus = digitalRead(pinUt);
pinInnStatus = digitalRead(pinInn);
pinStoppStatus = digitalRead(pinStopp);
pinRelUtStatus = digitalRead(pinRelUt);
pinRelInnStatus = digitalRead(pinRelInn);

//Holdefunksjon og sikring mot at man kan starte motor motsatt vei uten å stoppe
if (pinUtStatus == HIGH && pinInnStatus == LOW && pinStoppStatus == LOW && pinRelInnStatus == LOW) {
  digitalWrite(pinRelUt, HIGH);
}
if (pinUtStatus == LOW && pinInnStatus == HIGH && pinStoppStatus == LOW && pinRelUtStatus == LOW) {
  digitalWrite(pinRelInn, HIGH);
}
if (pinStoppStatus == HIGH) {
  digitalWrite(pinRelUt, LOW);
  digitalWrite(pinRelInn, LOW);
}

{//Klemmsikring
  if (analogRead(spenning)> 250)
  digitalWrite(pinRelUt, LOW);
  if (analogRead(spenning)> 250)
  digitalWrite(pinRelInn, LOW);
}

{

int spenning = analogRead(A0);
float voltage = spenning * (5/1023.0);
Serial.print("Målt spenning: ");
Serial.print(voltage);
Serial.println("V");
delay(100);
}
}

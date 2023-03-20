// Motorstyring

const int UtPin = 3; //nummeret på inngang
int releUtPin = 5; //nummeret på utgang
int InnPin = 2;
int releInnPin = 6;
int motstand = 0;

void setup()
{
  pinMode(UtPin, INPUT_PULLUP); //valgt modus for pin
  pinMode(releUtPin, OUTPUT); //valgt modus for pin
  pinMode(InnPin, INPUT_PULLUP);
  pinMode(releInnPin, OUTPUT);
  
Serial.begin(9600);
}

void loop()

{
  int Ut = digitalRead(UtPin);
  int Inn = digitalRead(InnPin);
  int motstand = analogRead(A0);
float voltage = motstand * (5.0 / 1023.0);

//digitalWrite(releInnPin, LOW);
//digitalWrite(releUtPin, LOW);

if(voltage >= 1.5){
digitalWrite(releInnPin, HIGH);}
 else if (motstand <= 200);{

digitalWrite(releInnPin, Inn);
}
{digitalWrite(releUtPin, Ut);}

if (analogRead(motstand)> 450)
digitalWrite(releUtPin, LOW);
if(analogRead(motstand)> 450)
digitalWrite(releInnPin, LOW);

Serial.print("Spenning over motstand: ");
Serial.print(voltage);
Serial.println("V");


}

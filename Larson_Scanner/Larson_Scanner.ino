
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;
const int potmeter = A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  Serial.begin(9600);      // open the serial port at 9600 bps:   
}

void loop() {
  // put your main code here, to run repeatedly:
  int snelheidsRegelaat = analogRead(potmeter);
  int snelheid = map(snelheidsRegelaat, 0, 1024, 50, 500);

// print labels 
  Serial.print(snelheid);       // prints a label
  Serial.print("\n");

  digitalWrite(led1, HIGH);
    delay(snelheid);
  digitalWrite(led1, LOW);

  digitalWrite(led2, HIGH);
    delay(snelheid);
  digitalWrite(led2, LOW);

  digitalWrite(led3, HIGH);
    delay(snelheid);
  digitalWrite(led3, LOW);

  digitalWrite(led4, HIGH);
    delay(snelheid);
  digitalWrite(led4, LOW);

  digitalWrite(led5, HIGH);
    delay(snelheid);
  digitalWrite(led5, LOW);
}

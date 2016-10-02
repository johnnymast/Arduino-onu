const int led = 2;
const int sensor = A0;
const int potmeter = A1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor, OUTPUT);
  pinMode(potmeter, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int drempelWaarde = analogRead(potmeter);
  Serial.print("Dempelwaarde: ");
  Serial.print(drempelWaarde);
  Serial.print("  | " );
  

  int sensorWaarde = analogRead(sensor);
  Serial.print("(");
  Serial.print(sensorWaarde);
  Serial.print(")");
  Serial.print("\n");
  if (sensorWaarde <= drempelWaarde) {
    digitalWrite(led, HIGH);
    Serial.print("Nacht lampje aan");
  } else {
    digitalWrite(led, LOW);
    Serial.print("Nacht lampje uit");
  }
  delay(1000);
}

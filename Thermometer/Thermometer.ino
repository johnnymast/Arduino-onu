const int rodeLed =2;
const int groeneLed = 3;
const int blauweLed = 4;
const int sensor = A0;
const float basisTemperatuur = 26.0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorWaarde = analogRead(sensor);
  Serial.print("Sensorwaarde: ");
  Serial.print(sensorWaarde);
  Serial.print(" | ");

  float voltage = (sensorWaarde/1024.0) * 5.0;
  Serial.print("Volt: ");
  Serial.print(voltage);
  Serial.print(" | ");

  float temperatuur = voltage * 100;
  Serial.print("graden Celcius: ");
  Serial.print(temperatuur);
  Serial.print("\n");
 
  if (temperatuur < basisTemperatuur -2) {
    digitalWrite(blauweLed, HIGH);
    delay(500);
    
    digitalWrite(blauweLed, LOW);
    digitalWrite(groeneLed, LOW);
    digitalWrite(rodeLed, LOW); 
  } else if (temperatuur >= basisTemperatuur-2 && temperatuur < basisTemperatuur) {
    digitalWrite(blauweLed, HIGH);
    digitalWrite(groeneLed, LOW);
    digitalWrite(rodeLed, LOW); 
  } else if (temperatuur >= basisTemperatuur && temperatuur < basisTemperatuur+2) {
    digitalWrite(rodeLed, LOW);
    digitalWrite(groeneLed, HIGH);
    digitalWrite(blauweLed, LOW);
  } else if (temperatuur >= basisTemperatuur+2 && temperatuur < basisTemperatuur+4) {
    digitalWrite(rodeLed, HIGH);
    digitalWrite(groeneLed, LOW);
    digitalWrite(blauweLed, LOW);
    
  } else if (temperatuur > basisTemperatuur+4) {
    digitalWrite(blauweLed, LOW);
    digitalWrite(groeneLed, LOW);
    digitalWrite(rodeLed, HIGH);
    delay(500);
    digitalWrite(rodeLed, LOW);
  }
  delay(500);
}

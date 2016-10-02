const int led = 3;
const int toets = 2;

 
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(toets, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int toetsWaarde = digitalRead(toets);

  if (toetsWaarde == HIGH) {
   digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

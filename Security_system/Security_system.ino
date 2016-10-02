
const int zoemer = 3;
const int reed = 2;
const int redled = 4;
const int greenled = 5;

int zoomWaarde = LOW;

unsigned long vorigeTijd = 0;

const long interval = 1000;


void setup() {
  // put your setup code here, to run once:
  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(zoemer, OUTPUT);
  pinMode(reed, INPUT);
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long huidigeTijd = millis();
  int reedWaarde = digitalRead(reed);
  int zoemerWaarde = digitalRead(zoemer);
  
 
  if (reedWaarde == HIGH) {
    digitalWrite(zoemer, LOW);
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
    
  } else if (huidigeTijd - vorigeTijd >= interval) {
    if (zoemerWaarde == LOW) {
      zoemerWaarde = HIGH;
    } else {
      zoemerWaarde = LOW;
    }
    digitalWrite(zoemer, zoemerWaarde);
    digitalWrite(redled, zoemerWaarde);
    digitalWrite(greenled, LOW);
  }


  
}

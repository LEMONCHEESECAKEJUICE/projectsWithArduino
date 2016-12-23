const int led = 13;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  for (int i=0; i<3; i++) {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(300);
  }

  for (int i=0; i<3; i++) {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(300);
  }
  
}


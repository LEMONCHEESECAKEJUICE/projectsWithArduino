const int sensor = 8;
const int buzzer = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(sensor)) {
    tone(buzzer, 200, 500);
    delay(500);
    noTone(buzzer);
    delay(500);

    digitalWrite(sensor, LOW);
    delay(5000);
  }

}

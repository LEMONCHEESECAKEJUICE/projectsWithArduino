/*
 * motionDetectorTest4
 * 
 * This is a program that uses a PIR detector, an LED light and a Piezo buzzer. 
 * When the PIR detector finds any motion around it, the LED lignt will be set HIGH and the buzzer will be played once.
 * 
 */
 
const int led = 13;   // LED light
const int sensor = 8; // PIR detector
const int buzzer = 5; // Piezo buzzer

const long interval = 500;  // term between each blink and beep
const long waiting = 5000;  // term between loop() functions

void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT); 

}

void loop() {

  // when a motion is detected
  if (digitalRead(sensor)) {
    
    // set LED light HIGH and play the connected buzzer
    digitalWrite(led, HIGH);
    tone(buzzer, 200, interval);
    delay(interval);

    // turn off the buzzer and LED light
    noTone(buzzer);
    delay(interval); 
    digitalWrite(led, LOW);
    digitalWrite(sensor, LOW);

    // wait for seconds until next detection
    delay(waiting);
    
  }

}

/*
 * motionDetectorTest5 (final)
 * 
 * This is a program that uses a PIR detector, an LED light and a Piezo buzzer. 
 * When the PIR detector finds any motion around it, the LED lignt will be set HIGH and the buzzer will be played for given duration.
 * 
 */
 
const int led = 13;   // LED light
const int sensor = 8; // PIR detector
const int buzzer = 5; // Piezo buzzer

const long interval = 500;  // term between each blink and beep
const long waiting = 5000;  // term between loop() functions

const int frequency = 100;

void beepWithBlink(int buzzer, int led, int frequency, long interval, long duration);

void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT); 

}

void loop() {

  // when a motion is detected
  if (digitalRead(sensor)) {
    
    // make buzzer beep and LED blink for given duration (in this program, for 10 sec)
    beepWithBlink(buzzer, led, frequency, interval, 10 * 1000);

    // wait for seconds until next detection
    delay(waiting);    
  }

}

// beepWithBlink function makes buzzer beep and LED blink, per given interval, for given duration
void beepWithBlink(int buzzer, int led, int frequency, long interval, long duration) {

  // get start time, this will be used to measure duration later
  long initialMillis = millis();
  // set previous time as start time, this will be used to measure interval later
  long previousMillis = initialMillis;
  // get current LED state
  int ledState = digitalRead(led);

  do {
    // get current time, this will be used to measure interval
    long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {

      // if the LED is LOW, turn the LED on and play the buzzer
      if (ledState == LOW) {
        ledState = HIGH;
        tone(buzzer, frequency, interval);
        delay(interval);
      }
      // if the LED is HIGH, turn the LED and the buzzer off
      else {
        ledState = LOW;
        noTone(buzzer);
        delay(interval);
      }
    }
    
    // repeat these for the given duration
  } while (millis() - initialMillis < duration);
}


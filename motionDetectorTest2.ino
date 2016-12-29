/*
 * motionDetectorTest2
 * 
 * This program was written for a test where a PIR detector works with a Piezo buzzer.
 * In this program, a connected buzzer beeps as any motion is detected from a connected PIR detector.
 * When a motion is detected, the buzzer will beep for given duration.
 * After the beep, PIR detector will be set as LOW.
 * And the program will wait for seconds until the next detection.
 * 
 */

const int motion_pin = 8;
const int buzzer_pin = 5;
const int frequency = 100;

void beep(int buzzer, int frequency, long duration, long interval);

void reset(int pin);

void setup() {
  pinMode(buzzer_pin, OUTPUT);

}

void loop() {

  reset(motion_pin);
  
  // when any motion is detected, make buzzer beep 
  if (digitalRead(motion_pin)) {
    beep(buzzer_pin, frequency, 10 * 1000, 500);

    // set motion_pin as LOW
    reset(motion_pin);
    
    // wait for seconds before next detection
    delay(3000);
  }
  
}

// beep function makes a given buzzer beep at given frequency, per given interval, for given duration
void beep(int buzzer, int frequency, long duration, long interval) {
  long initialMillis = millis();

  do {
    
    // play buzzer for the given interval
    noTone(buzzer);
    delay(interval);
    tone(buzzer, frequency, interval);
    delay(interval);
    
    // repeat for given duration (in these codes, for 10 sec)
  } while (millis() - initialMillis < duration);

}

// reset function sets given pin as original state (LOW)
void reset(int pin) {
  digitalWrite(pin, LOW);
}


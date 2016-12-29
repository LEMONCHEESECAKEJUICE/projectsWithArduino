/*
 * motionDetectorTest
 * 
 * This program was written for a test where a PIR detector works with a LED light.
 * In this program, a connected LED blinks as any motion is detected from a connected PIR detector.
 * When a motion is detected, the LED will blink for given duration.
 * After the blink, both LED and PIR detector will be set as LOW.
 * And the program will wait for seconds until the next detection.
 * 
 */

const int motion_pin = 8;
const int led_pin = 5;

void blink(int led, long interval, long duration);

void reset(int pin);

void setup() {
  pinMode(led_pin, OUTPUT);

}

void loop() {

  // when any motion is detected, blink LED 
  if (digitalRead(motion_pin)) {
    blink(led_pin, 100, 10 * 1000);

    // set both led_pin and motion_pin as LOW
    reset(led_pin);
    reset(motion_pin);
    
    // wait for 3 sec before next detection
    delay(3000);
  }

}

// blink function sets given LED as HIGH or LOW, per given interval, for given duration
void blink(int led, long interval, long duration) {
  long initialMillis = millis();
  long previousMillis = initialMillis;
  int ledState = digitalRead(led);

  do {
    // get new current time as milliseconds
    long currentMillis = millis();

    // change ledState per given interval (in these codes, for 0.1 sec)
    if (currentMillis - previousMillis >= interval) {
      // set previousMillis as new currentMillis
      previousMillis = currentMillis;

      // if ledState is HIGH, replace it with LOW, same as reversed.
      digitalWrite(led, ledState = ledState ? LOW : HIGH);
    }
    
    // repeat for given duration (in these codes, for 10 sec)
  } while (millis() - initialMillis < duration);

}

// reset function sets given pin as original state (LOW)
void reset(int pin) {
  digitalWrite(pin, LOW);
}


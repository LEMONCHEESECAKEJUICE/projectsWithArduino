const int led = 5;  // you can change this as any value
const int highShort = 100;
const int highLong = 1000;
const int lowInterval = 300;

void blink(int led, int length);

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  // set message you want to make blink
  char message[] = "MERRYCHRISTMAS";

  // blink differently per each character
  for (int i=0; i< (sizeof message); i++) {
    char character = message[i];

    // switch blink pattern A-Z(a-z) and 0-9 in Morse
    switch (character) {
    case 'A':
    case 'a':
      blink(led, 1, highShort, lowInterval);
      blink(led, 1, highLong, lowInterval);
      break;
    case 'B':
    case 'b':
      blink(led, 1, highLong, lowInterval);
      blink(led, 3, highShort, lowInterval);
      break;
    case 'C':
    case 'c':
      blink(led, 1, highLong, lowInterval);
      blink(led, 1, highShort, lowInterval);
      blink(led, 1, highLong, lowInterval);
      blink(led, 1, highShort, lowInterval);
      break;
    case 'D':
    case 'd':
      blink(led, 1, highLong, lowInterval);
      blink(led, 2, highShort, lowInterval);
      break;
    case 'E':
    case 'e':
      blink(led, 1, highShort, lowInterval);
      break;
    case 'F':
    case 'f':
      blink(led, 2, highShort, lowInterval);
      blink(led, 1, highLong, lowInterval);
      blink(led, 1, highShort, lowInterval);
      break;
    case 'G':
    case 'g':
      blink(led, 2, highLong, lowInterval);
      blink(led, 1, highShort, lowInterval);
      break;
    case 'H':
    case 'h':
      blink(led, 4, highShort, lowInterval);
      break;
    case 'I':
    case 'i':
      blink(led, 2, highShort, lowInterval);
      break;
    case 'J':
    case 'j':
      blink(led, 1, highShort, lowInterval);
      blink(led, 3, highLong, lowInterval);
      break;
    case 'K':
    case 'k':
      blink(led, 1, highLong, lowInterval);
      blink(led, 1, highShort, lowInterval);
      blink(led, 1, highLong, lowInterval);
      break;
    case 'L':
    case 'l':
      blink(led, 1, highShort, lowInterval);
      blink(led, 1, highLong, lowInterval);
      blink(led, 2, highShort, lowInterval);
      break;
    case 'M':
    case 'm':
      blink(led, 2, highLong, lowInterval);
      break;
    case 'N':
    case 'n':
      blink(led, 1, highLong, lowInterval);
      blink(led, 1, highShort, lowInterval);
      break;
    case 'O':
    case 'o':
      blink(led, 3, highLong, lowInterval);
      break;
    case 'P':
    case 'p':
      blink(led, 1, highShort, lowInterval);
      blink(led, 2, highLong, lowInterval);
      blink(led, 1, highShort, lowInterval);
      break;
    case 'Q':
    case 'q':
      blink(led, 2, highLong, lowInterval);
      blink(led, 1, highShort, lowInterval);
      blink(led, 1, highLong, lowInterval);
      break;
    case 'R':
    case 'r':
      blink(led, 1, highShort, lowInterval);
      blink(led, 1, highLong, lowInterval);
      blink(led, 1, highShort, lowInterval);
      break;
    case 'S':
    case 's':
      blink(led, 3, highShort, lowInterval);
      break;
    case 'T':
    case 't':
      blink(led, 1, highLong, lowInterval);
      break;
    case 'U':
    case 'u':
      blink(led, 2, highShort, lowInterval);
      blink(led, 1, highLong, lowInterval);
      break;
    case 'V':
    case 'v':
      blink(led, 3, highShort, lowInterval);
      blink(led, 1, highLong, lowInterval);
      break;
    case 'W':
    case 'w':
      blink(led, 1, highShort, lowInterval);
      blink(led, 2, highLong, lowInterval);
      break;
    case 'X':
    case 'x':
      blink(led, 1, highLong, lowInterval);
      blink(led, 2, highShort, lowInterval);
      blink(led, 1, highLong, lowInterval);
      break;
    case 'Y':
    case 'y':
      blink(led, 1, highLong, lowInterval);
      blink(led, 1, highShort, lowInterval);
      blink(led, 2, highLong, lowInterval);
      break;
    case 'Z':
    case 'z':
      blink(led, 2, highLong, lowInterval);
      blink(led, 2, highShort, lowInterval);
      break;
    case '1':
      blink(led, 1, highShort, lowInterval);
      blink(led, 4, highLong, lowInterval);
      break;
    case '2':
      blink(led, 2, highShort, lowInterval);
      blink(led, 3, highLong, lowInterval);
      break;
    case '3':
      blink(led, 3, highShort, lowInterval);
      blink(led, 2, highLong, lowInterval);
      break;
    case '4':
      blink(led, 4, highShort, lowInterval);
      blink(led, 1, highLong, lowInterval);
      break;
    case '5':
      blink(led, 5, highShort, lowInterval);
      break;
    case '6':
      blink(led, 1, highLong, lowInterval);
      blink(led, 4, highShort, lowInterval);
      break;
    case '7':
      blink(led, 2, highLong, lowInterval);
      blink(led, 3, highShort, lowInterval);
      break;
    case '8':
      blink(led, 3, highLong, lowInterval);
      blink(led, 2, highShort, lowInterval);
      break;
    case '9':
      blink(led, 4, highLong, lowInterval);
      blink(led, 1, highShort, lowInterval);
      break;
    case '0':
      blink(led, 5, highLong, lowInterval);
      break;
    default:
      break;
  }
    
  }
  
}

// blink function sets led on and off for defined times and intervals
void blink(int led, int count, long highInterval, long lowInterval) {
  int ledState = LOW;
  long previousMillis = 0;

  while (count > -1) {
    /*
     * codes below are from https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
     * created and modified by David A. Mellis and Scott Fitzgerald
     */
    long currentMillis = millis();

    if (ledState == LOW) {
      if (currentMillis - previousMillis >= lowInterval) {  // set LED off for lowInterval
        previousMillis = currentMillis;
        ledState = HIGH;
        digitalWrite(led, ledState);
        count--;
      }
    }
    else {
      if (currentMillis - previousMillis >= highInterval) { // set LED on for highinterval
        previousMillis = currentMillis;
        ledState = LOW;
        digitalWrite(led, ledState);
      }
    }
  }
}


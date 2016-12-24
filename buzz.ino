const int buzzer = 8;
const int frequency = 300;
const int beepShort = 100;
const int beepLong = 300;
const long interval = 200;

void beep(int buzzer, int count, int frequency, int duration, int interval);

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // set message you want to make it beep!
  char message[] = "MERRYCHRISTMAS";

  // beep differently per each character
  for (int i=0; i< (sizeof message); i++) {
    char character = message[i];

    // switch beep pattern A-Z(a-z) and 0-9 in Morse
    switch (character) {
    case 'A':
    case 'a':
      beep(buzzer, 1, frequency, beepShort, interval);
      beep(buzzer, 1, frequency, beepLong, interval);
      break;
    case 'B':
    case 'b':
      beep(buzzer, 1, frequency, beepLong, interval);
      beep(buzzer, 3, frequency, beepShort, interval);
      break;
    case 'C':
    case 'c':
      beep(buzzer, 1, frequency, beepLong, interval);
      beep(buzzer, 1, frequency, beepShort, interval);
      beep(buzzer, 1, frequency, beepLong, interval);
      beep(buzzer, 1, frequency, beepShort, interval);
      break;
    case 'D':
    case 'd':
      beep(buzzer, 1, frequency, beepLong, interval);
      beep(buzzer, 2, frequency, beepShort, interval);
      break;
    case 'E':
    case 'e':
      beep(buzzer, 1, frequency, beepShort, interval);
      break;
    case 'F':
    case 'f':
      beep(buzzer, 2, frequency, beepShort, interval);
      beep(buzzer, 1, frequency, beepLong, interval);
      beep(buzzer, 1, frequency, beepShort, interval);
      break;
    case 'G':
    case 'g':
      beep(buzzer, 2, frequency, beepLong, interval);
      beep(buzzer, 1, frequency, beepShort, interval);
      break;
    case 'H':
    case 'h':
      beep(buzzer, 4, frequency, beepShort, interval);
      break;
    case 'I':
    case 'i':
      beep(buzzer, 2, frequency, beepShort, interval);
      break;
    case 'J':
    case 'j':
      beep(buzzer, 1, frequency, beepShort, interval);
      beep(buzzer, 3, frequency, beepLong, interval);
      break;
    case 'K':
    case 'k':
      beep(buzzer, 1, frequency, beepLong, interval);
      beep(buzzer, 1, frequency, beepShort, interval);
      beep(buzzer, 1, frequency, beepLong, interval);
      break;
    case 'L':
    case 'l':
      beep(buzzer, 1, frequency, beepShort, interval);
      beep(buzzer, 1, frequency, beepLong, interval);
      beep(buzzer, 2, frequency, beepShort, interval);
      break;
    case 'M':
    case 'm':
      beep(buzzer, 2, frequency, beepLong, interval);
      break;
    case 'N':
    case 'n':
      beep(buzzer, 1, frequency, beepLong, interval);
      beep(buzzer, 1, frequency, beepShort, interval);
      break;
    case 'O':
    case 'o':
      beep(buzzer, 3, frequency, beepLong, interval);
      break;
    case 'P':
    case 'p':
      beep(buzzer, 1, frequency, beepShort, interval);
      beep(buzzer, 2, frequency, beepLong, interval);
      beep(buzzer, 1, frequency, beepShort, interval);
      break;
    case 'Q':
    case 'q':
      beep(buzzer, 2, frequency, beepLong, interval);
      beep(buzzer, 1, frequency, beepShort, interval);
      beep(buzzer, 1, frequency, beepLong, interval);
      break;
    case 'R':
    case 'r':
      beep(buzzer, 1, frequency, beepShort, interval);
      beep(buzzer, 1, frequency, beepLong, interval);
      beep(buzzer, 1, frequency, beepShort, interval);
      break;
    case 'S':
    case 's':
      beep(buzzer, 3, frequency, beepShort, interval);
      break;
    case 'T':
    case 't':
      beep(buzzer, 1, frequency, beepLong, interval);
      break;
    case 'U':
    case 'u':
      beep(buzzer, 2, frequency, beepShort, interval);
      beep(buzzer, 1, frequency, beepLong, interval);
      break;
    case 'V':
    case 'v':
      beep(buzzer, 3, frequency, beepShort, interval);
      beep(buzzer, 1, frequency, beepLong, interval);
      break;
    case 'W':
    case 'w':
      beep(buzzer, 1, frequency, beepShort, interval);
      beep(buzzer, 2, frequency, beepLong, interval);
      break;
    case 'X':
    case 'x':
      beep(buzzer, 1, frequency, beepLong, interval);
      beep(buzzer, 2, frequency, beepShort, interval);
      beep(buzzer, 1, frequency, beepLong, interval);
      break;
    case 'Y':
    case 'y':
      beep(buzzer, 1, frequency, beepLong, interval);
      beep(buzzer, 1, frequency, beepShort, interval);
      beep(buzzer, 2, frequency, beepLong, interval);
      break;
    case 'Z':
    case 'z':
      beep(buzzer, 2, frequency, beepLong, interval);
      beep(buzzer, 2, frequency, beepShort, interval);
      break;
    case '1':
      beep(buzzer, 1, frequency, beepShort, interval);
      beep(buzzer, 4, frequency, beepLong, interval);
      break;
    case '2':
      beep(buzzer, 2, frequency, beepShort, interval);
      beep(buzzer, 3, frequency, beepLong, interval);
      break;
    case '3':
      beep(buzzer, 3, frequency, beepShort, interval);
      beep(buzzer, 2, frequency, beepLong, interval);
      break;
    case '4':
      beep(buzzer, 4, frequency, beepShort, interval);
      beep(buzzer, 1, frequency, beepLong, interval);
      break;
    case '5':
      beep(buzzer, 5, frequency, beepShort, interval);
      break;
    case '6':
      beep(buzzer, 1, frequency, beepLong, interval);
      beep(buzzer, 4, frequency, beepShort, interval);
      break;
    case '7':
      beep(buzzer, 2, frequency, beepLong, interval);
      beep(buzzer, 3, frequency, beepShort, interval);
      break;
    case '8':
      beep(buzzer, 3, frequency, beepLong, interval);
      beep(buzzer, 2, frequency, beepShort, interval);
      break;
    case '9':
      beep(buzzer, 4, frequency, beepLong, interval);
      beep(buzzer, 1, frequency, beepShort, interval);
      break;
    case '0':
      beep(buzzer, 5, frequency, beepLong, interval);
      break;
    default:
      break;
  }
    
  }
  
}

void beep(int buzzer, int count, int frequency, int duration, int interval) {
  while (count > 0) {
    tone(buzzer, frequency);
    delay(duration);
    noTone(buzzer);
    delay(interval);
    count--;
  }
  
}

}


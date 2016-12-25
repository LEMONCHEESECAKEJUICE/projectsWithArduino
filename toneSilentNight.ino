/*
 * Silent Night
 * 
 * melody: 
 *  G A G E G A G E (Silent night, holy night.)
 *  D D B C C G (All is calm, All is bright.)
 *  A A C B A G A G E (Round yon virgin mother and child.)
 *  A A C B A G A G E (Holy infant so tender and mild.)
 *  D D F D B C E C G E G F D C (Sleep in heavenly peace! Sleep in heavenly peace!)
 *  
 *  Codes below are from https://www.arduino.cc/en/Tutorial/toneMelody
 *  created and modified by Tom Igoe
 */
#include "pitches.h"

const int buzzer = 8;

// notes in the melody (ordered in the same way as the melody)
int melody[] = {
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D5, NOTE_D5, NOTE_F5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_E5, NOTE_C5, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_C4
};

// duration of each note in the melody (ordered in the same way as the melody)
int noteDurations[] = {
  3, 8, 4, 3, 3, 8, 4, 3, 2, 4, 3, 2, 4, 3, 2, 4, 3, 8, 4, 3, 8, 4, 3, 2, 4, 3, 8, 4, 3, 8, 4, 3, 2, 4, 3, 8, 4, 2, 2, 4, 4, 4, 3, 8, 4, 1
};

void playNote(int buzzer, int note, int noteDuration);

void setup() {
  pinMode(buzzer, OUTPUT);

}

// play melody infinitely. (with 5-second-interval)
void loop() {
  // play all notes in melody array
  for (int i=0; i<(sizeof melody / sizeof melody[0]); i++) {
    
    // use playNote function to play each note
    playNote(buzzer, melody[i], noteDurations[i]);
  }

  // delay 2 sec before play the same melody again
  delay(5000);
    
}

// playNote functions plays given note in given duration
// Codes (including comments) in this function are from https://www.arduino.cc/en/Tutorial/toneMelody
// created and modified by Tom Igoe
void playNote(int buzzer, int note, int noteDuration) {

  // to calculate the note duration, take one second
  // divided by the note type.
  // e.g. quarter note = 1000 / 4, eighth note = 1000 / 8, etc.
  int duration = 1000 / noteDuration;
  tone(buzzer, note, duration);
  
  // to distinguish the notes, set a minimun time between them.
  // the note's nuration + 30% seems to work well:
  delay(duration * 1.30);
  
  // stop the tone playing:
  noTone(buzzer);
}


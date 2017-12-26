/*
 * Project play-tunes
 * Description: Sample code to compose a tune for the internet button
 * Author: Nish Kumar
 * Date: December 2017
 */

 #include "InternetButton/InternetButton.h"

////////////////////////////////////////////////////////////////////////////////
/* How  to compose tunes? */
 // playNote just plays a single note, and takes
 // a note name as a string and a note type as an int
 // Note types define duration like in scored music, so
 // 8 is a 1/8th note and 4 is a 1/4 note
 // b.playNote("G3",8);

// playSong takes a string in the format
// "NOTE,TYPE,NOTE,TYPE..."
// Types are note types that define duration so
// 8 is a 1/8th note and 4 is a 1/4 note
// b.playSong("C4,8,E4,8,G4,8,C5,8,G5,4");
////////////////////////////////////////////////////////////////////////////////


/* Compose your tune here */
const char tune_intro[] = "A6,1,B6,1,C6,1,D6,1,E6,1,F6,1,G6,1";
const char tune_melody[] = "A6,2,B6,2,C6,2,D6,2,E6,2,F6,2,G6,2,\
                            A6,4,B6,4,C6,4,D6,4,E6,4,F6,4,G6,4,\
                            A4,4,B4,4,C4,4,D4,4,E4,4,F4,4,G4,4,\
                            A4,8,B4,8,C4,8,D4,8,E4,8,F4,8,G4,8,\
                            A6,8,B6,8,C6,8,D6,8,E6,8,F6,8,G6,8,\
                            A4,8,B4,16,C4,16,D4,8,E4,16,F4,16,G4,8,\
                            A6,8,B6,16,C6,16,D6,8,E6,16,F6,16,G6,8,\
                            A6,16,B6,16,C6,16,D6,16,E6,16,F6,16,G6,16,\
                            A4,16,B4,16,C4,16,D4,16,E4,16,F4,16,G4,16,\
                            A5,16,B5,16,C5,16,D5,16,E5,16,F5,16,G5,16";

 /* This SparkButton library has some useful functions.
 Here we blink ALL the LEDs instead of just one.*/
 InternetButton b = InternetButton();

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  b.begin();
}


// loop() runs over and over again, as quickly as it can execute.
void loop() {

  if (b.buttonOn(1) || b.buttonOn(2) || b.buttonOn(3) || b.buttonOn(4)) {
      b.allLedsOn(0, 0, 255);
      b.playSong(tune_intro);
      delay(500);
      b.playSong(tune_melody);
  }else{
      b.allLedsOff();
  }

}

 /*
 * Project: coffee-station
 * Description: Internet enabled coffee station
 * Author: Nish Kumar
 * Date: December 2017
 */

 #include "InternetButton/InternetButton.h"

 /* This SparkButton library has some useful functions.
 Here we blink ALL the LEDs instead of just one.*/

 InternetButton b = InternetButton();
 int arrayLength = 0;
 int colorIndex = 0;

 int colorArray[][3] = {{0, 0, 250}, {0, 25, 225}, {0, 50, 200}, {0, 75, 175},
                        {0, 100, 150}, {0, 125, 125}, {0, 150, 100}, {0, 175, 75},
                        {0, 200, 50}, {0, 225, 25}, {0, 250, 0}, {25, 225, 0},
                        {50, 200, 0}, {75, 175, 0}, {100, 150, 0}, {125, 125, 0},
                        {150, 100, 0}, {175, 75, 0}, {200, 50, 0}, {225, 25, 0},
                        {250, 0, 0}, {225, 0, 25}, {200, 0, 50}, {175, 0, 75},
                        {150, 0, 100}, {125, 0, 125}, {100, 0, 150}, {75, 0, 175},
                        {50, 0, 200}, {25, 0, 225}};

 void setup() {
     // Tell b to get everything ready to go
     // Use b.begin(1); if you have the original SparkButton, which does not have a buzzer or a plastic enclosure
     // to use, just add a '1' between the parentheses in the code below.
     b.begin();

     // All LEDs off
     allOff();
     arrayLength = sizeof(colorArray)/sizeof(colorArray[0]);
 }


 /*
 * Description: Function to turn-off all LEDs
 */
 void allOff(){
   b.ledOff(1);
   b.ledOff(2);
   b.ledOff(3);
   b.ledOff(4);
   b.ledOff(5);
   b.ledOff(6);
   b.ledOff(7);
   b.ledOff(8);
   b.ledOff(9);
   b.ledOff(10);
   b.ledOff(11);
 }


 /*
 * Description: Function to turn-on LEDS
 */
 void showLedPulse(int colorIndex){
       b.ledOn(1, colorArray[colorIndex][0], colorArray[colorIndex][1], colorArray[colorIndex][2]);
       b.ledOn(2, colorArray[colorIndex][0], colorArray[colorIndex][1], colorArray[colorIndex][2]);
       b.ledOn(3, colorArray[colorIndex][0], colorArray[colorIndex][1], colorArray[colorIndex][2]);
       b.ledOn(4, colorArray[colorIndex][0], colorArray[colorIndex][1], colorArray[colorIndex][2]);
       b.ledOn(5, colorArray[colorIndex][0], colorArray[colorIndex][1], colorArray[colorIndex][2]);
       b.ledOn(6, colorArray[colorIndex][0], colorArray[colorIndex][1], colorArray[colorIndex][2]);
       b.ledOn(7, colorArray[colorIndex][0], colorArray[colorIndex][1], colorArray[colorIndex][2]);
       b.ledOn(8, colorArray[colorIndex][0], colorArray[colorIndex][1], colorArray[colorIndex][2]);
       b.ledOn(9, colorArray[colorIndex][0], colorArray[colorIndex][1], colorArray[colorIndex][2]);
       b.ledOn(10, colorArray[colorIndex][0], colorArray[colorIndex][1], colorArray[colorIndex][2]);
 }


 void loop(){
     // Pulse LEDs if a button is pressed
      if (b.buttonOn(1) || b.buttonOn(2) || b.buttonOn(3) || b.buttonOn(4)) {
        colorIndex = (colorIndex + 1) % arrayLength;
        showLedPulse(colorIndex);
        delay(300);
      }else{
        allOff();
      }
 }

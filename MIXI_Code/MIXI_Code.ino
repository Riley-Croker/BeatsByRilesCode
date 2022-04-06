// MIXI Code
// Set Up Arduino IDE for Arduino Pro Mini: https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide
// Install MIDIUSB Library

/*
 * CONTROL MAP
 * 
 * 0 - first[0]; 1 - first[1]; 2 - first[2]; 3 - first[3]; 4 - first[4]; 5 - first[5];
 * 10 - second[0]; 11 - second[1]; 12 - second[2]; 13 - second[3]; 14 - second[4]; 15 - second[5];
 * 20 - third[0]; 21 - third[1]; 22 - third[2]; 23 - third[3]; 24 - third[4]; 25 - third[5];
 * 30 - slidePotent; 31 - topPotent; 32 - middlePotent; 33 - bottomPotent;
 * 
 */

// Buttons
#include <Bounce2.h>
int numButtons = 8;
int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
Bounce * buttons = new Bounce[8];
//boolean buttonStates[8] = {false, false, false, false, false, false, false, false};
boolean firstStates[6] = {false,false,false,false,false,false};
boolean secondStates[6] = {false,false,false,false,false,false};
boolean thirdStates[6] = {false,false,false,false,false,false};


// Potentiometers
int numPots = 4;
int potPins[4] = {0, 1, 2, 3};
int curPotStates[4] = {0, 0, 0, 0};
int prevPotStates[4] = {0, 0, 0, 0};
int thresholds[4] = {25,25,25,25};

// LEDs
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(8, 10, NEO_GRB + NEO_KHZ800);
int numLED = 8;

// MIDI
#include "MIDIUSB.h"

//Switch
int mode = 0;

void setup() {
  Serial.begin(9600);
  initButtons();
  initLED();
  initPotents();
  beginAnimation();
}

void loop() {
  fillLEDs();
  checkButtons();
  checkPots();
  //testAll();
}

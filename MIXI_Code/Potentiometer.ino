// Potentiometer Functions

// Initialize Potentiometers
void initPotents() {
  for(int i = 0; i < numPots; i++) {
    curPotStates[i] = analogRead(potPins[i]);
    prevPotStates[i] = curPotStates[i];
  }
}


// Check Pots
void checkPots(){
  for (int i = 0; i < numPots; i++){
    curPotStates[i] = analogRead(potPins[i]);

    if(abs(curPotStates[i] - prevPotStates[i]) > thresholds[i]) {
      if(i == 0)
        Serial.println("Slide potentiometer is changing to " + String(curPotStates[i]));
      else
        Serial.println("Potentiometer " + String(i) + " is changing to " + String(curPotStates[i]));
      int mapVal = map(curPotStates[i], 0, 1023, 0, 127);
      controlChange(0,i+30,mapVal);
      prevPotStates[i] = curPotStates[i];
    }
  }
}

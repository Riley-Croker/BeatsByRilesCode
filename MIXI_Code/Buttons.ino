// Button Functions

// Initialize Buttons
void initButtons(){
  for (int i = 0; i < numButtons; i++) {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(25);
  }
}

// Check Buttons
void checkButtons(){
  for (int i = 0; i < numButtons; i++)  {
    buttons[i].update();
  }

  switch(mode){
    case 0:
      if(buttons[0].rose()){
        Serial.println("Button 0 pressed! Changing to state 1.");
        mode=1;
      }
      else if(buttons[4].rose()) {
        Serial.println("Button 4 pressed! Changing to state 2.");
        mode=2;
      }
    break;
    case 1:
      if(buttons[0].rose()){
        Serial.println("Button 0 pressed! Changing to state 2.");
        mode=2;
      }
      else if(buttons[4].rose()) {
        Serial.println("Button 4 pressed! Changing to state 0.");
        mode=0;
      }
    break;
    case 2:
      if(buttons[0].rose()){
        Serial.println("Button 0 pressed! Changing to state 0.");
        mode=0;
      }
      else if(buttons[4].rose()) {
        Serial.println("Button 4 pressed! Changing to state 1.");
        mode=1;
      }
    break;
  }
  int j = 0;
  for (int i = 1; i < 8; i++)  {
    if (buttons[i].rose() && i != 4) {
      Serial.println("Button " + String(i) + " pressed in state " + String(mode));
      if(mode == 0) {
        firstStates[j] = !firstStates[j];
        if(firstStates[j]) controlChange(0, (j + (mode*10)), 127); else controlChange(0, (j + (mode*10)), 0);
      }
      else if(mode == 1) {
        secondStates[j] = !secondStates[j];
        if(secondStates[j]) controlChange(0, (j + (mode*10)), 127); else controlChange(0, (j + (mode*10)), 0);        
      }
      else {
        thirdStates[j] = !thirdStates[j];
        if(thirdStates[j]) controlChange(0, (j + (mode*10)), 127); else controlChange(0, (j + (mode*10)), 0);        
      }
    }
    if(i != 4)
      j++;
  }
}

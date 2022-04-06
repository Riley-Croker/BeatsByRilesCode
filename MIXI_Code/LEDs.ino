// LED Functions

void initLED(){
  strip.begin();
  strip.clear();
  strip.show();
}

void beginAnimation() {
  for(int i = 0; i < strip.numPixels()*2; i++) {
    strip.clear();
    strip.setPixelColor(i % strip.numPixels(),Wheel(0));
    if( i > 0 ) 
      strip.setPixelColor((i-1) % strip.numPixels(),Wheel(50));
    if( i < strip.numPixels()*2-1 )
      strip.setPixelColor((i+1) % strip.numPixels(), Wheel(80));
    strip.show();
    delay(100);
  }
  strip.clear();
  strip.show();
}

void fillLEDs(){
  strip.clear();
  uint32_t mainColor;
  uint32_t but0Col;
  uint32_t but4Col;
  switch(mode){
    case 0:
      mainColor = Wheel(80);
      but0Col = Wheel(50);
      but4Col = Wheel(0);
    break;
    case 1:
      mainColor = Wheel(50);
      but0Col = Wheel(0);
      but4Col = Wheel(80);
    break;
    case 2:
      mainColor = Wheel(0);
      but0Col = Wheel(80);
      but4Col = Wheel(50);
    break;
  }
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i,mainColor);
  }
  strip.setPixelColor(0,but0Col);
  strip.setPixelColor(4,but4Col);
  strip.show();
}

// LED Wheel Function
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

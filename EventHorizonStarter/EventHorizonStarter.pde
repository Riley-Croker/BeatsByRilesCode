// Event Horizon Starter
// Zane Cochran
// 27 March 2022

boolean isBroadcast = false;       // Toggles Visualization On/Off
String ipAddress = "10.40.4.115";  // Event Horizon IP Address

float randVar;
float mapVal;

void setup(){
  size(480,480);
  initBroadcast();
  initAudio();
}
float whichColor = 0;

void draw(){
  background(0);
  getLoud();
  if(soundSize > 50) 
    whichColor = (whichColor + 5) % 255;
  colorMode(HSB, 255);
  fill(whichColor,255,255);
  
  //ellipse(width/2,height/2,soundSize, soundSize);
  for(int i = 0; i < 480; i+=40) { 
    mapVal = map(soundSize,0,350,0,480);
    randVar = random(0,mapVal);
    rect(i,480-randVar,40,randVar); // bottom
    rect(i,0,40,randVar); // top
    rect(0,i,randVar,40); // left
    rect(480-randVar,i,randVar,40); // right
  }
  
  if(isBroadcast){broadcast();}
}

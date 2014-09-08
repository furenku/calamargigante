int currLed = 0;
int currLed2 = 0;
int pos = 0;

int p = 0;

void showLeds() {
  
  if(clock%3==0) 
    p++;
  p %= 80;
  
  //p = 255;
  for (uint16_t i = 0; i < NUMLEDS; i++ ) {
    strip.setPixelColor(i, 20 + (leds[i] * p/255));    
  }
  strip.show();
}



void setLed( int i, uint32_t c ) {
  leds[i] = c;  
}

void setLeds( uint32_t c ) {
  for(int i = 0; i < NUMLEDS; i++) {
    setLed(i, c);
  }    
}


void setLeds( int c ) {
  for(int i = 0; i < NUMLEDS; i++) {
    setLed(i, strip.Color(c,c,c));
  }    
}    

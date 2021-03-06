

/**** TIRAS ****/


void setLed( int i, uint32_t c ) {
  leds[i] = c;  
}


void setLeds( uint32_t c ) {
  for(int i = 0; i < NUMLEDS; i++) {
    setLed(i, c);
  }    
}


void setLeds( int startLED, int endLED, uint32_t c ) {
  for(int i = startLED; i < endLED; i++) {
    setLed(i, c);
    tmpLeds[i]=c;
  }    
}


void setTmpLed( int i, uint32_t c ) {
  tmpLeds[i] = c;  
  updated[i] = false;
}
void setTmpLeds( uint32_t c ) {
  for(int i = 0; i < NUMLEDS; i++) {
    setTmpLed(i, c);
  }    
}

void setLeds( int c ) {
  for(int i = 0; i < NUMLEDS; i++) {
    setLed(i, strip.Color(c,c,c));
  }    
}    



void setOjo( uint32_t c  ) {
  setLeds(stripStart[2],stripEnd[3],c);
}


/**** RGB ****/


void setRGB( uint32_t c ) {
  rgb = c;
}


void showRGB() {
if(trigger(5)) {
      analogWrite(RED, getR( rgb ) );
      analogWrite(GREEN, getG( rgb ) );
      analogWrite(BLUE, getB( rgb ) );
}

}




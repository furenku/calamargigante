int currLed = 0;
int currLed2 = 0;
int pos = 0;

/*
int p = 0;

void showLeds() {
  
  if(clock%3==0) 
    p+=3;
  p %= 80;
  
  //p = 255;
  for (uint16_t i = 0; i < NUMLEDS; i++ ) {
    strip.setPixelColor(i, 20 + ( (leds[i] * p/255) * generalBrightness/255) );    
  }
  strip.show();
}
*/




/**** TIRAS ****/


void setLed( int i, uint32_t c ) {
  leds[i] = c;  
}


void setLeds( uint32_t c ) {
  for(int i = 0; i < NUMLEDS; i++) {
    setLed(i, c);
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




/**** RGB ****/


void setRGB( uint32_t c ) {
  rgb = c;
}


void showRGB( byte pulseType ) {
  switch( pulseType ) {
    case 0:
      analogWrite(RED, max( min( getR( rgb ) - bpulseVal[0] , 255 ), 0 ) );
      analogWrite(GREEN, max( min( getG( rgb ) - bpulseVal[0] , 255 ), 0 ) );
      analogWrite(BLUE, max( min( getB( rgb ) - bpulseVal[0] , 255 ), 0 ) );
    break;

    case 1:
      analogWrite(RED, ( getR( rgb ) / bpulseVal[0] ) % 255);
      analogWrite(GREEN, ( getG( rgb ) / bpulseVal[0] ) % 255);
      analogWrite(BLUE, ( getB( rgb ) / bpulseVal[0]) % 255);
    break;

  }
}




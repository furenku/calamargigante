void setLed( int i, uint32_t c ) {
  leds[i] = c;  
  //tmpleds[i] = c;
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

void setRgb( uint32_t c ) {
  rgb = c;
}


void showRGB( byte pulseType ) {
  switch( pulseType ) {
    case 0:
      analogWrite(RED, max( min( getR( rgb ) - bpulseVal , 255 ), 0 ) );
      analogWrite(GREEN, max( min( getG( rgb ) - bpulseVal , 255 ), 0 ) );
      analogWrite(BLUE, max( min( getB( rgb ) - bpulseVal , 255 ), 0 ) );
    break;

    case 1:
      analogWrite(RED, ( getR( rgb ) / bpulseVal ) % 255);
      analogWrite(GREEN, ( getG( rgb ) / bpulseVal ) % 255);
      analogWrite(BLUE, ( getB( rgb ) / bpulseVal) % 255);
    break;

  }
}



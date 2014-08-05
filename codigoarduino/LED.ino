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

void setRgb( uint32_t c ) {
  rgb = c;
}


void showRGB() {
  analogWrite(RED, getR( rgb ) - bpulseVal );
  analogWrite(GREEN, getG( rgb ) - bpulseVal );
  analogWrite(BLUE, getB( rgb ) - bpulseVal );

}


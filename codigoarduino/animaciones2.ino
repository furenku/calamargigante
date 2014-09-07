void drawStatic( byte probability ) {
  for (uint16_t i = 0; i < NUMLEDS; i++ ) {
    
    if( random(0,255) > probability ) {
      strip.setPixelColor(i,White);
    }
    else {
      strip.setPixelColor(i,
          strip.Color( getR(leds[i]) - bpulseVal,
          getG(leds[i]) - bpulseVal,
          getB(leds[i]) - bpulseVal          
        ));      

}
  }     
  
  strip.show();
}


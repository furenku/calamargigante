
void fwd() {
  fwdClock();
  fwdFade();
  fwdPulse();
}




int fadeStart[NUMFADES], fadeEnd[NUMFADES];
byte fadeMod[NUMFADES], fadeAmount[NUMFADES];
byte fadeR[NUMFADES], fadeG[NUMFADES], fadeB[NUMFADES];
byte nextFade = 0, numFades = 0;


void clearFades() {
  numFades = 0;
  nextFade = 0;
}


void addFade( int startLED, int endLED, byte mod, byte amount, byte r, byte g, byte b ) {
  fadeStart[numFades] = startLED;
  fadeEnd[numFades] = endLED;
  fadeMod[numFades] = mod;
  fadeAmount[numFades] = amount;
  fadeR[numFades] = r;
  fadeG[numFades] = g;
  fadeB[numFades] = b; 
  numFades++;
  nextFade++;
  nextFade %= NUMFADES;
  if(numFades>NUMFADES) numFades = NUMFADES;
}


void addFade( int startLED, int endLED, byte mod, byte amount, uint32_t c ) {
  fadeStart[numFades] = startLED;
  fadeEnd[numFades] = endLED;
  fadeMod[numFades] = mod;
  fadeAmount[numFades] = amount;
  fadeR[numFades] = getR(c);
  fadeG[numFades] = getG(c);
  fadeB[numFades] = getB(c);
  numFades++;
  nextFade++;
  nextFade %= NUMFADES;
  if(numFades>NUMFADES) numFades = NUMFADES;
}

void fwdFade() {
  int bb = 0;
  for(int i = 0; i < numFades; i++) {
      if( trigger( fadeMod[i] ) ) {
       for(int j = fadeStart[i]; j <= fadeEnd[i]; j++ ) {
         byte r,g,b;
         byte currentR, currentG, currentB;
         
        if( j < NUMLEDS ) {
          r = currentR = getR( leds[j] );
          g = currentG = getG( leds[j] );
          b = currentB = getB( leds[j] );

        }
        else {
          r = currentR = getR( rgb );
          g = currentG = getG( rgb );
          b = currentB = getB( rgb );
        }  

        if( currentG < fadeG[i] ) {
          r =  currentR + fadeAmount[i];
          
        } else if ( currentR > fadeR[i] ) {
          r =  currentR - fadeAmount[i];
        } 
        if( currentG < fadeG[i] ) {
          g =  currentG + fadeAmount[i];
          
        } else if ( currentG > fadeG[i] ) {
          g =  currentG - fadeAmount[i];
        } 
        if( currentB < fadeB[i] ) {
          b =  currentB + fadeAmount[i];
          
        } else if ( currentB > fadeB[i] ) {
          b =  currentB - fadeAmount[i];
        } 


        if( j == NUMLEDS ) {
          setRGB(strip.Color( r, g, b ));
        }
       bb = r;
        setLed(j, strip.Color( r, g, b ) );
      } 
    }
    


  }    
  
}


void setGradient( int startLED, int endLED, byte startR, byte startG, byte startB, byte endR, byte endG, byte endB, boolean wait=false) {
  
  int steps = endLED - startLED;
  
  int deltaR = int(startR) - int(endR);
  int deltaG = int(startG) - int(endG);
  int deltaB = int(startB) - int(endB);
  float stepR = (deltaR/(float)steps);
  float stepG = (deltaG/(float)steps);
  float stepB = (deltaB/(float)steps);

  for(int i = 0; i<endLED-startLED; i++) {
    int index = startLED+i;
    if(!wait) {
      setLed(index, strip.Color(
        startR - (i*stepR), 
        startG - (i*stepG),
        startB - (i*stepB)
      ));
    }  else {
      setTmpLed(index, strip.Color(
        startR - (i*stepR), 
        startG - (i*stepG),
        startB - (i*stepB)
      ));
    }
    
  }

}



void addGradientFade( int startLED, int endLED, byte mod, byte amount, byte startR, byte startG, byte startB, byte endR, byte endG, byte endB ) {
}



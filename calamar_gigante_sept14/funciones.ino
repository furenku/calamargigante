
void fwd() {
  fwdClock();
  fwdFade();
  fwdPulse();
}



#define NUMFADES 3

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
  nextFade %= 3;
  if(numFades>3) numFades = 3;
}

void fwdFade() {
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
        setLed(j, strip.Color( r, g, b ) );
      } 
    }

  }    
}





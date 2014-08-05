

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
          r =  min( currentR + fadeAmount[i], fadeR[i] );
          
        } else if ( currentR > fadeR[i] ) {
          r =  max( currentR - fadeAmount[i], fadeR[i] );
        } 
        if( currentG < fadeG[i] ) {
          g =  min( currentG + fadeAmount[i], fadeG[i] );
          
        } else if ( currentG > fadeG[i] ) {
          g =  max( currentG - fadeAmount[i], fadeG[i] );
        } 
        if( currentB < fadeB[i] ) {
          b =  min( currentB + fadeAmount[i], fadeB[i] );
          
        } else if ( currentB > fadeB[i] ) {
          b =  max( currentB - fadeAmount[i], fadeB[i] );
        } 


        if( j == NUMLEDS ) {
          setRgb(strip.Color( r, g, b ));
        }
        setLed(j, strip.Color( r, g, b ) );
      } 
    }

  }    
}


void setPulse(byte pmin, byte pmax, byte pspeed, byte paccmin, byte paccmax, byte pacc) {
  pulseSpeed = pspeed;
  pulseMin = pmin;
  pulseMax = pmax;
  pulseAcc = pacc;  
}


void fwdPulse(){
  
  pulseVal+=(pulseSpeed/(float)255);
  bpulseVal+=pulseSpeed;
  pulseSpeed += pulseAcc;
  pulseSpeed *= pong(pulseSpeed,pulseMin,pulseMax);
  pulseAcc *= pong(pulseAcc,pulseAccMin,pulseAccMax);
  
}






byte spread = 1;

void spreadAround() {
  spread++;
  
  // hacer un loop que crece de acuerdo al spread
  // aquellos contenidos, mas lejanos al centro, van gradualmente acercandose al centro
}






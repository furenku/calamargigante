

#define NUMFADES 3

int fadeStart[NUMFADES], fadeEnd[NUMFADES];
byte fadeMod[NUMFADES], fadeAmount[NUMFADES];
byte fadeR[NUMFADES], fadeG[NUMFADES], fadeB[NUMFADES];
byte nextFade = 0, numFades = 0;


void clearFades() {
  numFades = 0;
  nextFade = 0;
}

void clearPulse() {
  setPulse(255,255,1,0,0,0,0,0);
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
          setRgb(strip.Color( r, g, b ));
        }
        setLed(j, strip.Color( r, g, b ) );
      } 
    }

  }    
}


void setPulse(byte pmin, byte pmax, byte pmod,  byte pspeed, byte paccmin, byte paccmax, byte pacc, byte ptype) {
  pulseSpeed = pspeed;
  pulseMin = pmin;
  pulseMax = pmax;
  pulseAcc = pacc;
  pulseMod = pmod;
  pulseAccMin = paccmin;
    pulseAccMax = paccmax;
  pulseType = ptype;  
}


void fwdPulse(){
  if( trigger (pulseMod) ) {
  //pulseVal+=(pulseSpeed/(float)255);
    bpulseVal+=pulseSpeed;
    pulseSpeed *= pong(pulseSpeed,pulseMin,pulseMax);
    if(pulseAcc > 0 ) {
      pulseSpeed += pulseAcc;
      pulseAcc *= pong(pulseAcc,pulseAccMin,pulseAccMax);
    }
  }
}






byte spread = 1;
//byte around
void setSpread( int spr ) {
  spread = spr;
}


void fwdSpread( byte spreadSpeed, boolean positive ) {
  if(positive) {
      spread+=spreadSpeed;
    } else {
      spread-=spreadSpeed;
    }
}

void spreadColor( int focus, byte spreadSpeed, boolean positive ) {
  if( trigger(3) ) {
    fwdSpread( spreadSpeed, positive );

    byte midSpread = byte(focus - spread/float(2));

    byte rd = getR( leds[max(focus-midSpread,0)] );
    byte gd = getG( leds[max(focus-midSpread,0)] );
    byte bd = getB( leds[max(focus-midSpread,0)] );
    byte rf = getR( leds[focus] );
    byte gf = getG( leds[focus] );
    byte bf = getB( leds[focus] );
    byte ru = getR( leds[min(focus+midSpread,NUMLEDS)] );
    byte gu = getG( leds[min(focus+midSpread,NUMLEDS)] );
    byte bu = getB( leds[min(focus+midSpread,NUMLEDS)] );
    byte diffRdown = rf - rd;
    byte diffGdown = gf - gd;
    byte diffBdown = bf - bd;
    byte diffRup = rf - ru;
    byte diffGup = gf - gu;
    byte diffBup = bf - bu;
    

    byte stepDownR = byte( diffRdown / (float)midSpread );
    byte stepDownG = byte( diffGdown / (float)midSpread );
    byte stepDownB = byte( diffBdown / (float)midSpread );
    byte stepUpR = byte( diffRup / (float)midSpread );
    byte stepUpG = byte( diffGup / (float)midSpread );
    byte stepUpB = byte( diffBup / (float)midSpread );


    for( int i = focus-midSpread; i < focus; i++ ) {
      leds[i] =  strip.Color(
        rd + ( stepDownR * i ),
        gd + ( stepDownG * i ),
        bd + ( stepDownB * i )
      );
    }
  
    for( int i = focus; i < focus+midSpread; i++ ) {
      leds[i] =  strip.Color(
        ru + ( stepUpR * (midSpread - i) ),
        gu + ( stepUpG * (midSpread - i) ),
        bu + ( stepUpB * (midSpread - i) )
      );
    }

  }

  // hacer un loop que crece de acuerdo al spread
  // aquellos contenidos, mas lejanos al centro, van gradualmente acercandose al centro
}



void staticAround() {
  
  



}









// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    if(trigger(wait)) {
      strip.setPixelColor(i, c);
      strip.show();
    }
    //delayMicroseconds(wait*2);

  }
}




void rainbow(int wait, int rainbowStart, int rainbowEnd ) {
  
  if( clock%wait == 0 )  {
      for (int i = 0; i < NUMLEDS; i++) {
        setLed(i, Wheel((rainbowStart + i + clock%rainbowEnd) & 255));
      }
  }
}



int ojosInicio = 136;
int ojosFinal = 142;

void ojosSet(  byte r, byte g, byte b  ) {
  for(int i = ojosInicio; i<ojosFinal; i++ ) {
    setLed( i, strip.Color(r,g,b) );
  }
}

void ojosFade( byte mod, byte amount, byte r, byte g, byte b  ) {
  addFade( ojosInicio, ojosFinal, mod, amount, r, g, b );
  
}





void ondular(){
  
}
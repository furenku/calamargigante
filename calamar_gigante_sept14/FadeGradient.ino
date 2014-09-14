



int fadeStart[NUMFADES], fadeEnd[NUMFADES];
//float fadeAmountR[NUMFADES], fadeAmountG[NUMFADES], fadeAmountB[NUMFADES];

byte fadeMod[NUMFADES], fadeAmount[NUMFADES], fadeSteps[NUMFADES];
byte fadeR[NUMFADES], fadeG[NUMFADES], fadeB[NUMFADES];
byte nextFade = 0, numFades = 0;
bool fadeDone[NUMFADES];

void clearFades() {
  numFades = 0;
  nextFade = 0;
}


void addFade( int startLED, int endLED, byte mod, byte amount, byte r, byte g, byte b, int steps = 30 ) {
  fadeStart[numFades] = startLED;
  fadeEnd[numFades] = endLED;
  fadeMod[numFades] = mod;
  fadeAmount[numFades] = amount;
  fadeSteps[numFades] = steps;
  fadeDone[numFades] = false;

  fadeR[numFades] = r;
  fadeG[numFades] = g;
  fadeB[numFades] = b; 
  numFades++;
  nextFade++;
  nextFade %= NUMFADES;
  if(numFades>NUMFADES) numFades = NUMFADES;
  
  for(int i = startLED; i < endLED; i++) {
    tmpLeds[i] = strip.Color(r,g,b);
  }
  
}


void addFade( int startLED, int endLED, byte mod, byte amount, uint32_t c, int steps = 30 ) {
  addFade( startLED, endLED, mod, amount, getR(c),getG(c), getB(c), steps ); 
}


void addFadeOjo( byte mod, byte amount, byte r, byte g, byte b ) {
  addFade(stripStart[2],stripEnd[3],mod, amount, r, g, b );
}

void addFadeOjo( byte mod, byte amount, uint32_t c ) {
  addFade(stripStart[2],stripEnd[3],mod, amount, getR(c), getB(c), getG(c) );
}


void fwdFade() {
  for(int i = 0; i < numFades; i++) {
      if(!fadeDone[i])           
      if( trigger( fadeMod[i] ) ) {
        //Serial.println("fd!");
         byte r,g,b;
         byte currentR, currentG, currentB;
         
         boolean isDone = true;
         byte newC;
         for(int j = fadeStart[i]; j <= fadeEnd[i]; j++ ) {

         
         if( leds[j] != tmpLeds[j] ) {
           isDone = false;
                     
//          if( j < NUMLEDS ) {
            currentR = getR( leds[j] );
            currentG = getG( leds[j] );
            currentB = getB( leds[j] );
          

          if( currentR == fadeR[i] ) {
            r=currentR;
          } else if( currentR < fadeR[i] ) {
/*            newC = currentR + fadeAmount[i];
            if( newC > fadeR[i] )  r = fadeR[i];
            else r =  newC; */
            r =  min( currentR + fadeAmount[i], fadeR[i] );

          } else if ( currentR > fadeR[i] ) {
            r =  max( currentR - fadeAmount[i], fadeR[i] );
          } 
          if( currentG == fadeG[i] ) {
            g=currentG;
          } else if( currentG < fadeG[i] ) {
            g =  min( currentG + fadeAmount[i], fadeG[i] );          
          } else if ( currentG > fadeG[i] ) {
            g =  max( currentG - fadeAmount[i], fadeG[i] );
          } 
          if( currentB == fadeB[i] ) {
            b=currentB;
          } else if( currentB < fadeB[i] ) {
            b =  min( currentB + fadeAmount[i], fadeB[i] );          
          } else if ( currentB > fadeB[i] ) {
            b =  max( currentB - fadeAmount[i], fadeB[i] );
          }          
         
         
            
         /*
Serial.println( j );
       Serial.print( " : " ); 
         Serial.print( r ); 
        Serial.print( " - " ); 
        Serial.print( g );
        Serial.print( " - " ); 
        
        Serial.print( b );   
*/
        if( j == NUMLEDS ) {
          setRGB(strip.Color( r, g, b ));
        }
        setLed(j, strip.Color( r, g, b ) );
           
           
        } //(tmpled comparison)
        else {
          setLed(j, tmpLeds[j] );
        }
      } 
      if( isDone) {
        fadeDone[i] = true;
        Serial.println( "FADE DONE!");        
      }


  }    
  
}

}


void setGradient( int startLED, int endLED, byte startR, byte startG, byte startB, byte endR, byte endG, byte endB, bool wait=false) {
  
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





/*
// usage:
// colorCrossFade(0,250,0,128,50,0,100,20); // fade from green to orange in 20 steps with delay of 100 between steps

void colorCrossFade(uint8_t r, uint8_t g, uint8_t b, uint8_t r2, uint8_t g2, uint8_t b2, uint8_t wait, uint8_t steps)
{
  int currentColorR = 0;
  int currentColorG = 0;
  int currentColorB = 0;
 
  for (int j = 0; j <= steps; j++) {
    currentColorR = ((r * (steps - j)) + (r2 * j)) / (steps*2);
    currentColorG = ((g * (steps - j)) + (g2 * j)) / (steps*2);
    currentColorB = ((b * (steps - j)) + (b2 * j)) / (steps*2);
 
    for (int i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, currentColorR, currentColorG, currentColorB);
      }
    strip.show();
    delay(wait);
  }
}*/


/******* DANCE *********/

int danceStart, danceEnd,fwdSpeed;
int currentLed=0;

void setDance( int startRange, int endRange, int dspeed ) {
danceStart = startRange;
danceEnd = endRange;
fwdSpeed = dspeed;
}

void danceAround() {
  black();
  showLeds();
  if(  currentLed < danceStart ) currentLed = danceStart;// = min(currentLed,startRange);
  currentLed+=fwdSpeed;
  fwdSpeed *= pong( fwdSpeed, danceStart, danceEnd );
  
  dotFade( currentLed, 255,255,255 );


}






/******* STATIC *********/



void drawStatic( byte probability ) {
//black();
  for (uint16_t i = 0; i < NUMLEDS; i++ ) {
    if( random(0,255) < probability ) {
      setLed(i, strip.Color(255,255,255) );
    } else {
      setLed(i, strip.Color(0,0,0) );
    }

  }     
  
}




void staticAround(int numled, int spread, byte probability) {
  
  for (uint16_t i = max( numled- spread, 0); i < (numled + spread); i++ ) {
    if( random(0,255) < probability - (((spread-i)%(spread))*5)) {
      setLed( (numled + i)%NUMLEDS, strip.Color(255,255,255) );
    } else {
      setLed((numled + i)%NUMLEDS, strip.Color(0,0,0) );
    }

  }     



}






/**** SPREAD ****/



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




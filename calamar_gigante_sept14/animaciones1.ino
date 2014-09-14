
/******* DANCE *********/

int danceStart, danceEnd,fwdSpeed;
int currentLed=0;

float stepR = 0;
float stepG = 0;
float stepB = 0;
  


void setDance( int startRange, int endRange, int dspeed ) {
  setDance( startRange, endRange, dspeed, 255, 255, 255 );  
}  
void setDance( int startRange, int endRange, int dspeed, byte r, byte g, byte b ) {
  danceStart = startRange;
  danceEnd = endRange;
  fwdSpeed = dspeed;
  for( int i = startRange; i < endRange; i++ ) {
    tmpLeds[i] = leds[i];
  }
  

  stepR = ( r - getR(tmpLeds[startRange]) ) / (float) 5;
  stepG = ( g - getG(tmpLeds[startRange]) ) / (float) 5;
  stepB = ( b - getB(tmpLeds[startRange]) ) / (float) 5;

  Serial.println(stepR);
}

void danceAround( uint32_t c) {
  //black();
  currentLed+=fwdSpeed;
  fwdSpeed *= pong( currentLed, danceStart, danceEnd );
  currentLed = min( max(  currentLed, danceStart ), danceEnd);
  
  dotFade( currentLed, getR(c),getG(c),getB(c) );
  dotFade( min( max(  currentLed + ((danceEnd-danceStart)/2), danceStart ), danceEnd), getR(c),getG(c),getB(c) );
  dotFade( min( max(  danceEnd - currentLed, danceStart ), danceEnd), getR(c),getG(c),getB(c) );


}



void dotFade( int i, byte r, byte g, byte b ) {

  setLed( max(0,i-5), tmpLeds[max(0,i-5)]);
  for( int h = 4; h > 0; h-- ) {
    uint32_t tmpc = tmpLeds[max(0,i-h)];
    uint32_t cr = getR(tmpc);
    uint32_t cg = getG(tmpc);   
    uint32_t cb = getB(tmpc);    
    setLed( max(0,i-h), strip.Color( cr + stepR * (4-h), cg + stepG * (4-h), cb - stepB * (4-h) ));
  }
  setLed( i, strip.Color( r, g, b ) );
  
  for( int h = 1; h < 5; h++ ) {
    uint32_t tmpc = tmpLeds[min(NUMLEDS-1,i+h)];
    uint32_t cr = getR(tmpc);
    uint32_t cg = getG(tmpc);   
    uint32_t cb = getB(tmpc);   
    setLed(min(NUMLEDS-1,i+h), strip.Color( r - stepR * h, g + stepG * h, b - stepB * h ));
  }
  
  setLed( min(NUMLEDS-1,i+5), tmpLeds[min(NUMLEDS-1,i+5)]);

  
/*
  int prev = max(i-1, 0);
  int pprev = max(i-2, 0);
  int ppprev = max(i-3, 0);
  int pppprev = max(i-4, 0);

  int next = (i+1)%NUMLEDS;
  int nnext = (i+2)%NUMLEDS;
  int nnnext = (i+3)%NUMLEDS;
  int nnnnext = (i+4)%NUMLEDS;

  uint32_t c = strip.Color( r, g, b );
  uint32_t cc = strip.Color( r/8, g/8, b/8 );
  uint32_t ccc = strip.Color( r/12, g/12, b/12 );
  uint32_t cccc = strip.Color( r/14, g/14, b/14 );
  uint32_t ccccc = strip.Color( r/16, g/16, b/16 );
  
  setLed(i, c);
  setLed(prev, cc);
  setLed(next, cc);
  setLed(pprev, ccc);
  setLed(nnext, ccc);
  setLed(ppprev, cccc);
  setLed(nnnext, cccc);
  setLed(pppprev, ccccc);
  setLed(nnnnext, ccccc);
  */
}







/******* STATIC *********/



void drawStatic( byte probability, byte r,byte g,byte b ) {
  for (uint16_t i = 0; i < NUMLEDS/4; i++ ) {
    if( random(0,255) < probability ) {
      for (int j = 0; j < 4; j++ ) { setLed(i + (j*(NUMLEDS/4)), strip.Color(r,g,b) ); }
    } else {
      for (int j = 0; j < 4; j++ ) { setLed(i + (j*(NUMLEDS/4)), tmpLeds[i + (j*(NUMLEDS/4))] ); }      
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

byte spreadSpeed = 1;
boolean spreadPositive = true;

void fwdSpread() {
  if(spreadPositive) {
      spread+=spreadSpeed;
    } else {
      spread-=spreadSpeed;
    }
}

void spreadColor( int focus, byte Speed, boolean positive ) {
  spreadSpeed = Speed;
  spreadPositive = positive;
  if( trigger(3) ) {
    fwdSpread();

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




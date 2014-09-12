
void randomUpdate(int startLED, int endLED) {
  
  for(int i = startLED; i<endLED; i++) {
  
  }

}

#define NUMUPDATES 13

int updateStart[NUMUPDATES];
int updateEnd[NUMUPDATES];
byte updateMod[NUMUPDATES];
int updateSteps[NUMUPDATES];
int updateStep[NUMUPDATES];

int numUpdates=0;
void clearUpdates() {
  numUpdates=0;
}



void addSeqUpdate(int startLED, int endLED, byte mod) {
  updateStart[numUpdates]=startLED;
  updateEnd[numUpdates]=endLED;
  updateMod[numUpdates]=mod;
  updateSteps[numUpdates]=0;

  numUpdates++;
  numUpdates = min( numUpdates, NUMUPDATES );
}

void seqUpdate() {
  for(int i = 0; i<numUpdates; i++) {
    if( trigger(updateMod[i]) ) {      
      if( updateSteps[i] <= updateEnd[i]-updateStart[i] ){
        int index =  updateStart[i] + updateSteps[i] ;
        leds[ index ] = tmpLeds[ index ];
        updated[ index ] = true;
        updateSteps[i]++;
      }
    }
  }
}

void dotFade( int i, byte r, byte g, byte b ) {

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
  
}




int pos=0;
int currLed=0;
void doubleHelix() {
	if(clock%1 == 0 ) {
		pos++;
		pos%=255;

		currLed++; currLed%=NUMLEDS;

	    black();
	    dotFade(currLed, 255,255,255);
	    dotFade( ( currLed+(NUMLEDS / 2) ) % NUMLEDS, 200,200,200);

	}
}


void quadHelix() {
	if(clock%1 == 0 ) {
		pos++;
		pos%=255;

		currLed++; currLed%=NUMLEDS;

	    black();
	    dotFade(currLed, 255,255,255);
	    dotFade( ( currLed+(NUMLEDS / 2) ) % NUMLEDS, 200,200,200);
	    dotFade( ( currLed+(3*(NUMLEDS / 4)) ) % NUMLEDS, 200,200,155);
	    dotFade( max( currLed - (NUMLEDS / 3), 0 ) , 125,125,200);

	}
}




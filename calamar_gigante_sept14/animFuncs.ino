
void randomUpdate(int startLED, int endLED) {
  
  for(int i = startLED; i<endLED; i++) {
  
  }

}

#define NUMUPDATES 13

int updateStart[NUMUPDATES];
int updateEnd[NUMUPDATES];
byte updateMod[NUMUPDATES];
byte updateSpeed[NUMUPDATES];

int updateSteps[NUMUPDATES];
int updateStep[NUMUPDATES];

int numUpdates=0;
void clearUpdates() {
  numUpdates=0;
}



void addSeqUpdate(int startLED, int endLED, byte mod, byte spd=1 ) {
  updateStart[numUpdates]=startLED;
  updateEnd[numUpdates]=endLED;
  updateMod[numUpdates]=mod;
  updateSpeed[numUpdates]=spd;
  updateSteps[numUpdates]=0;


  numUpdates++;
  numUpdates = min( numUpdates, NUMUPDATES );
}

void seqUpdate() {
  for(int i = 0; i<numUpdates; i++) {
    if( trigger(updateMod[i]) ) {      
      if( updateSteps[i] <= updateEnd[i]-updateStart[i] ){
        for( int j = 0; j < updateSpeed[i]; j++ ) { 
          int index =  updateStart[i] + updateSteps[i] + j;
          leds[ index ] = tmpLeds[ index ];
          updated[ index ] = true;
        }
        
        updateSteps[i]+= updateSpeed[i];
      }
    }
  }
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


void quadHelix(byte r,byte g,byte b) {
	if(clock%1 == 0 ) {
		pos++;
		pos%=255;

		currLed++; currLed%=NUMLEDS;

	    black();
	    dotFade(currLed, 255,255,255);
	    dotFade( ( currLed+(NUMLEDS / 2) ) % NUMLEDS, r/3,g/3,b/3);
	    dotFade( ( currLed+(3*(NUMLEDS / 4)) ) % NUMLEDS, r/2,g/2,b/2);
	    dotFade( max( currLed - (NUMLEDS / 3), 0 ) , r/2,g/2,b/2);

	}
}




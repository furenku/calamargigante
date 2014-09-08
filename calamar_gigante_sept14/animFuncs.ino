

void dotFade( int i, byte r, byte g, byte b ) {

  int prev = (i-1)%NUMLEDS;
  int pprev = (i-2)%NUMLEDS;
  int ppprev = (i-3)%NUMLEDS;
  int pppprev = (i-4)%NUMLEDS;

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





void doubleHelix() {
	if(clock%1 == 0 ) {
		pos++;
		pos%=255;

		 currLed++; currLed%=(NUMLEDS / 2);

	    black();
	    dotFade(currLed, 255,255,255);
	    dotFade(currLed+(NUMLEDS / 2), 255, 255, 255);
	}

}




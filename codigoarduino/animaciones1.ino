
byte pos;

int currentLed=0;

void count() {
  
  if(clock%5 == 0 ) {
    pos++;
    pos%=255;
    //setLeds(pos);
//    currLed%=NUMLEDS;
    currentLed%=67; currentLed++;
    currentLed%=67; currentLed++;
    uint32_t c, cc;
    /*if((currLed+1)%10==0) {
      setLeds(strip.Color(255,0,0));
    } else {*/
      c = strip.Color(255,255,255);
      cc = strip.Color(5,5,5);
      //black();
      setLed(currentLed, c);
      setLed(currentLed+68, c);
          /*}
    */
  

}
  
}


void doubleHelix() {
if(clock%4 == 0 ) {
    pos++;
    pos%=255;
    currentLed%=67; currentLed++;
    uint32_t c;

    c = strip.Color(255,255,255);
    black();

    dotFade(currentLed, 255,255,255);
    dotFade(currentLed+71, 255,255,255);

  

}
  
}


void dotFade( int i, byte r, byte g, byte b ) {

  int prev = (i-1)%NUMLEDS;
  int pprev = (i-2)%NUMLEDS;
  int ppprev = (i-3)%NUMLEDS;
  int next = (i+1)%NUMLEDS;
  int nnext = (i+2)%NUMLEDS;
  int nnnext = (i+2)%NUMLEDS;
  int c = strip.Color( r, g, b );
  int cc = strip.Color( r/4, g/4, b/4 );
  int ccc = strip.Color( r/6, g/6, b/6 );
  int cccc = strip.Color( r/8, g/8, b/8 );

  setLed(i, c);
  setLed(prev, cc);
  setLed(next, cc);
  setLed(pprev, ccc);
  setLed(nnext, ccc);
  setLed(ppprev, cccc);
  setLed(nnnext, cccc);

}


int danceStart, danceEnd,fwdSpeed;

void setDance( int startRange, int endRange, int dspeed ) {
danceStart = startRange;
danceEnd = endRange;
fwdSpeed = dspeed;
}

void danceAround() {
  black();
  showLeds(0);
  if(  currentLed < danceStart ) currentLed = danceStart;// = min(currentLed,startRange);
  currentLed+=fwdSpeed;
  fwdSpeed *= pong( fwdSpeed, danceStart, danceEnd );
  
  dotFade( currentLed, 255,255,255 );


}

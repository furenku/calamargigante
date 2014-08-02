


void test() {

  for( int i = 0; i < NUMLEDS; i++ ) {
      if( i < NUMLEDS / 2 ) fade(i,1,30,125,255);
      else fade(i,2,230,125,155);
  }



  addPulse(0,100,0,255,5,3,18, 1 );
  addPulse(101,200,200,255,15,3,18, 3);
}

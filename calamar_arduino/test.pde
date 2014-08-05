

void test() {

  //println("-tests-");
/*
  for( int i = 0; i < NUMLEDS; i++ ) {
      if( i < NUMLEDS / 2 ) fade(i,1,30,125,255);
      else fade(i,2,230,125,155);
  }

  */

  //setPulse( 1, 50, 190 );

/*
  addPulse(0,50,0,60,5,3,18, 1 );
  addPulse(51,100,200,255,25,15,35, 2);
  addPulse(101,200,60,155,15,3,18, 3);
  */

  //addFill( 0, 50, 1, 255, 255, 255, 0, 0, 0 );
  //addFill( 399, 0, 1, 255, 0, 0, 0, 255, 255 );

  //fillWhole( 2, 255, 0, 0, 0, 0,  255, false );
  fillWhole( 2, 255, 0, 0, 0, 0,  255, false );
  
  fadeEyes(2, 22, 0,255,0);

  addPulse( stripStart[2],stripEnd[3],0,255,2,1,10, 0 );

 // println("--");


}



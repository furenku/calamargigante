

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

 fillWhole( 2, 255, 0, 0, 0, 0,  0, true );
  //fillWhole( 1, 0,0,0, 255, 125, 0, false );

//  fadeEyes(2, 22, 0,255,0);
  addPulse( stripStart[0],stripEnd[1],80,245,10,1,10, 0 );
  addPulse( 134,135,80,245,20,1,10, 1 );



  /*
  

*/
/*
  addPulse( 60,60,80,245,10,1,10, 0 );

  fade(0, 2, 10, 255,255,0);
  fade(60, 2, 10, 255,0,0);
  fade(134, 2, 10, 0,255,0);
  fade(136, 2, 10, 0,255,0);
*/
 // println("--");
   /* fade(0, 12, 10, 255,0,255);
   
*/
/*
for (int i = 0; i < 5; ++i) {
fade(i,10,2,255,0,0);
  
}

for (int i = 0; i < 5; ++i) {
fade(i+5,10,2,0,0,255);
  
}


for (int i = 0; i < 5; ++i) {
fade(i+15,10,2,255,255,0);
  
}

*/


}





void loopTest() {

/*

if( !holdFwd() ) {
switch( holdCnt ) {
  case 0:
    fade(0, 2, 10, 0,255,0);
    hold(10000);
  break;
}

}

*/
}
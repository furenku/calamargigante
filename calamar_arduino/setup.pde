


void setBrightness( float b ) {
  generalBrightness = b;
}

void setupArduino(){

}


void setupLEDs(){

  setupStrips();


  setLEDs(0,0,0);
  

}



void setupFades() {
  for( int i = 0; i < NUMLEDS; i++ ) {
    b_fadeMod[i] = 10;
  }
}

/* SOLO PROCESSING */




void setupStrips() {

// pulseVar en 1



  // 1 cola1
  // 69 cola2
  // 136 ojo1
  // 139 ojo2
  // 142 cabeza1
  // 166 cabeza2
  // 193 cabeza3
  // 201 pata1
  // 227 pata2
  // 257 pata3
  // 308 pata4
  // ? pata5
  // ? pata6

    // cola 1

  
  stripStart[0] = 0;
  stripEnd[0]   = 67;

  stripStart[1] = 68;
  stripEnd[1]   = 134;
     
  stripStart[2] = 135;
  stripEnd[2]   = 137;     

  stripStart[3] = 138;
  stripEnd[3]   = 140;     

  stripStart[4] = 141;
  stripEnd[4]   = 164;     

  stripStart[5] = 165;
  stripEnd[5]   = 191;     

  stripStart[6] = 192;
  stripEnd[6]   = 199;  

  stripStart[7] = 200;
  stripEnd[7] = 225;

  stripStart[8] = 226;
  stripEnd[8] = 255;

  stripStart[9] = 256;
  stripEnd[9] = 306;

  stripStart[10] = 307;
  stripEnd[10] = 326;

  stripStart[11] = 327;
  stripEnd[11] = 350;

  stripStart[12] = 351;
  stripEnd[12] = 399;




}






/* TERMINA SOLO PROCESSING */



void setupRangos() {

  b_rangoPos[0] = 0;
  b_rangoPct[0] = 100;
  b_rangoPos[1] = 0;
  b_rangoPct[1] = 100;


  b_rangoPos[2] = 110;
  b_rangoPct[2] = 25;
  b_rangoPos[3] = 110;
  b_rangoPct[3] = 25;

  b_rangoPos[4] = 100;
  b_rangoPct[5] = 32;
  b_rangoPos[5] = 100;
  b_rangoPct[5] = 32;

  b_rangoPos[6] = 167;
  b_rangoPct[6] = 12;


  b_rangoPos[7] = 150;
  b_rangoPct[7] = 100;

  b_rangoPos[8] = 150;
  b_rangoPct[8] = 75;
  b_rangoPos[9] = 150;
  b_rangoPct[9] = 87;


  b_rangoPos[10] = 150;
  b_rangoPct[10] = 100;

  b_rangoPos[11] = 150;
  b_rangoPct[11] = 75;
  b_rangoPos[12] = 150;
  b_rangoPct[12] = 87;


}




/*
void setupRangosF() {

  b_rangoPos[0] = 0;
  b_rangoPct[0] = 0.40;
  b_rangoPos[1] = 0;
  b_rangoPct[1] = 0.40;


  b_rangoPos[2] = 0.45;
  b_rangoPct[2] = 0.1;
  b_rangoPos[3] = 0.45;
  b_rangoPct[3] = 0.1;

  b_rangoPos[4] = 0.40;
  b_rangoPct[5] = 0.15;
  b_rangoPos[5] = 0.40;
  b_rangoPct[5] = 0.15;

  b_rangoPos[6] = 0.55;
  b_rangoPct[6] = 0.05;


  b_rangoPos[7] = 0.60;
  b_rangoPct[7] = 0.40;

  b_rangoPos[8] = 0.60;
  b_rangoPct[8] = 0.30;
  b_rangoPos[9] = 0.60;
  b_rangoPct[9] = 0.35;


  b_rangoPos[10] = 0.60;
  b_rangoPct[10] = 0.40;

  b_rangoPos[11] = 0.60;
  b_rangoPct[11] = 0.30;
  b_rangoPos[12] = 0.60;
  b_rangoPct[12] = 0.35;


}
*/
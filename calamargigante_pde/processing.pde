
void setupProcessing() {
  size(800,800);
  background(30,30,30);
  setupStripViews();
}




void setupStripView( int i, int offsetX, int offsetY, int numLeds, int offsetI, int addX, int addY ) {
  /*
  stripOffsetX[i] = offsetX; 
  stripOffsetY[i] = offsetY;
  */
  for( int j = 0; j < numLeds; j++ ) {
    LEDx[j+offsetI] = offsetX + j*addX;
    LEDy[j+offsetI] = offsetY + j*addY;
  }
}




void setupStripViews() {
  setupStripView( 0, 250, 50, stripEnd[0] - stripStart[0], stripStart[0], -1, 3);
  // cola 2
  setupStripView( 1, 400, 50, stripEnd[1] - stripStart[1], stripStart[1], 1, 3);

    // ojo 1
  setupStripView( 2, 290, 250, stripEnd[2] - stripStart[2], stripStart[2], -10, 0);
  // ojo 2
  setupStripView( 3, 360, 250, stripEnd[3] - stripStart[3], stripStart[3], 10, 0);

  // cabeza 1
  setupStripView( 4, 225, 200, stripEnd[4] - stripStart[4], stripStart[4], 2, 5);
  // cabeza 2
  setupStripView( 5, 425, 200, stripEnd[5] - stripStart[5], stripStart[5], -2, 5);
  // cabeza 3
  setupStripView( 6, 290, 320, stripEnd[6] - stripStart[6], stripStart[6], 10, 0);
  
  // tentaculo 1
  setupStripView( 7, 200, 350, stripEnd[7] - stripStart[7], stripStart[7], 0, 6);
  
  //brazo 1
  setupStripView( 8, 230, 350, stripEnd[8] - stripStart[8], stripStart[8], 0, 6);
  
  //brazo 2
  setupStripView( 9, 260, 350, stripEnd[9] - stripStart[9], stripStart[9], 0, 6);

  // tentaculo 2
  setupStripView( 7, 350, 350, stripEnd[10] - stripStart[10], stripStart[10], 0, 6);
  
  //brazo 3
  setupStripView( 8, 380, 350, stripEnd[11] - stripStart[11], stripStart[11], 0, 6);
  
  //brazo 4
  setupStripView( 9, 410, 350, stripEnd[12] - stripStart[12], stripStart[12], 0, 6);



/*
  


  // brazo 1
  setupStripView( x, x, 10, 0);
  // brazo 2
  setupStripView( x, x, 10, 0);

  // tentaculo largo 2
  setupStripView( x, x, 10, 0);
  // brazo 3
  setupStripView( x, x, 10, 0);
  // brazo 4
  setupStripView( x, x, 10, 0);

  */





}

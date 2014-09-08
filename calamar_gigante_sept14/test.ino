void test(){
//  setLed(136,strip.Color(0,255,0));
  //setPulse(20,50,4,3,1,1,0,0);

  //setPulse(50,150,1,15, 0,0,0,0);
  /*
  setPulse2(50,150,1,5, 0,0,0,0,180,200);
  // setPulse(10,150,1,5, 1,5,-1,0);
   setPulse(30,150,1,5, 1,1,0,0);

 //setLed( 100, strip.Color(255,0,255));

  //spreadColor( 100, 3, true );

//  green();
  

  
  */
//  setDance( 80, 140, 1 );
      /*setPulse(10,30,2,1, 0,0,0,0);
      // rojo
      setPulse2(5,60,1,4, 0,0,0,0,20,60);
      
      */
      addPulse(0,155,1,3, 0,0,0,0,stripStart[0],stripEnd[1]);
      addPulse(0,155,1,3, 0,0,0,0,stripStart[4],stripEnd[12]);
      addPulse(228,255,1,34, 22,34,-1,0,stripStart[2],stripEnd[3]);
      setLeds(blanco);
      addFade( stripStart[4], stripEnd[5], 1, 3, 0, 255, 255 );
      addFade( stripStart[0], stripEnd[1], 1, 5, 255, 255, 0  );
      addFade( stripStart[6], stripEnd[12], 1, 30, 0, 240, 0  );

}


// intensidad de color
// tempo
// duracion


// poder programar eventos de cierta duracion


void seq() {

  switch( cue ) {
    case 0:
      rainbow(1,0,85);
      //chaser();
      break;
      
    case 2: 
      spreadColor(75,1,true);
      break;
    case 6:
      clearPulse();
      danceAround();

      break;    
      
      case 8:
        rainbow(8,100,156);
      //chaser();
      break;

    case 18:
      drawStatic(probability);
      if(trigger(3) ) { 
        probability--;
        if( probability<155) { probability = 255; }
      }  
    break;

    case 23:
      spreadColor(50,3,true);
    break;


    case 24:
      danceAround();
    break;

    case 32:
      spreadColor(50,3,true);
    break;
  }

}


void changeCue( byte cue ) {
  
  mainSeq(cue);

  /*
  inStatic = false;
  
	switch( cue ) {
		case 0:
                  //white();
                  rainbow(1,0,85);
		// mostrar que está jalando bien
		break;
		case 1:
                white();
                clearFades();
		//setLeds( 150,150,150);
		addFade( 400,400,2,5,255,255,255);
                setPulse(20,67,4,2,2,1,1,0);
		break;

                case 11:
                white();
                clearFades();
		//setLeds( 150,150,150);
		addFade( 400,400,2,5,155,155,255);
                setPulse(10,47,3,2,2,4,1,0);
		break;

		case 2:
                clearFades();
		setLeds( strip.Color(255,0,0));
		addFade( 400,400,5,5,125,0,255);
                setPulse(100,160,2,1,1,2,1,1);
                
		break;

		case 3:
                clearFades();
		addFade( 0,399,5,5,0,0,0);
		addFade( 400,400,5,5,0,0,255);
                setPulse(100,155,2,6,6,12,3,2);

		break;
                case 4:
                clearFades();
		addFade( 0,399,1,10,200,0,0);
		addFade( 400,400,1,10,0,255,0);
                setPulse(80,120,3,2,3,3,0,0);
                break;
                
                
                case 6:
                  clearFades();
                  setPulse(255,255,1,1,1,1,0,0);
                  black();
                  setDance(100,150,2);
                  break;
                
                case 18:
                  inStatic = true;
                  break;

	}	

  */

}

void seq() {
/*
  switch( cue ) {
    case 0:
      //chaser();
      break;
  }
*/
}


void changeCue( byte cue ) {

	switch( cue ) {
		case 0:

		// mostrar que está jalando bien
		break;
		case 1:
                clearFades();
		addFade( 0,399,5,5,255,0,0);
		addFade( 400,400,5,5,0,255,0);
		break;

		case 2:
                clearFades();
		addFade( 0,399,5,5,255,125,255);
		addFade( 400,400,5,5,125,0,255);
		break;

		case 3:
                clearFades();
		addFade( 0,399,5,5,0,0,0);
		addFade( 400,400,5,5,0,0,255);
		break;

	}	

}

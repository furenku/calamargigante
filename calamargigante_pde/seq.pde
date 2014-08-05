void seq() {

	


}


int holdMs = 0;
int holdCnt = 0;


void hold( int ms ) {
    holdMs = ms;
}

boolean holdFwd() {
  if( holdMs > 0 ) {
    holdMs--;
    return true;
  }
  else {
    holdMs = 0;
    return false;
  }
}



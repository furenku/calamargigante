int pong( int val, int pongMin, int pongMax ) {
	int dir = 1;
	if( val < pongMin || val > pongMax ) {
		dir = -1;
	}
	return dir;
}


void fwdClock() {
  
  clock++;
  clock%=30000;
  
}




byte getR(uint32_t pixel){
  byte c = (pixel >> 16) & 0xFF;
  return c;
}

byte getG(uint32_t pixel){
  byte c = (pixel >> 8) & 0xFF;
  return c;
}

byte getB(uint32_t pixel){
  byte c = (pixel >> 0) & 0xFF;
  return c;
}



boolean trigger( byte mod ) {
    if( clock % mod == 0 )
    	return true;
    else
    	return false;
}
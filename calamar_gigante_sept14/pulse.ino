
void clearPulse(int i) {
  //setPulse(255,255,1,0,0,0,0,0);
}


byte currentPulse = 0;

void addPulse(byte pmin, byte pmax, byte pmod,  byte pspeed, byte paccmin, byte paccmax, int pacc, byte ptype, int rangeMin, int rangeMax) {

  pulseSpeed[currentPulse] = pspeed;
  pulseMin[currentPulse] = pmin;
  pulseMax[currentPulse] = pmax;
  pulseAcc[currentPulse] = pacc;
  pulseMod[currentPulse] = pmod;
  pulseAccMin[currentPulse] = paccmin;
  pulseAccMax[currentPulse] = paccmax;
  pulseType[currentPulse] = ptype;
  pulseRangeStart[currentPulse] = rangeMin;
  pulseRangeEnd[currentPulse] = rangeMax;  
  pulseSet[currentPulse] = true;

  currentPulse++; currentPulse %= NUMPULSES;
  
}




byte tmpPulse=0, tmpPulse2 = 0;
bool didPong = false;
void fwdPulse(){
  for( int i = 0; i < NUMPULSES; i++) {
    if( pulseSet[i] )
    if( trigger (pulseMod[i]) ) {
  
      int bPong = pong(int(bpulseVal[i])+pulseSpeed[i],int(pulseMin[i]),int(pulseMax[i]));
      pulseSpeed[i] *= bPong;
      if(bPong == -1 && ! didPong ){
        didPong = true;
        pulseSpeed[i] = abs( pulseSpeed[i] ) + pulseAcc[i];
        

      } 
     
      if(bPong == 1) {
        didPong = false;
      }
      
  
        bpulseVal[i] += pulseSpeed[i];
                        
                        Serial.print("bpulseVal ");
                        Serial.print(i);
                        Serial.print(": ");
                        Serial.println(bpulseVal[i]);

      if( pulseAcc[i] != 0 ) {
  
        if( bpulseVal[i] < pulseMin[i] || bpulseVal[i] > pulseMax[i] ) {
          //
  
          if( pulseSpeed[i] < pulseAccMin[i] || pulseSpeed[i] > pulseAccMax[i] ) {
            pulseAcc[i] = 0;
          }
        }
      }
      
    }
  }
}



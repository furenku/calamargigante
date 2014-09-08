


byte numPulses = 0;


void clearPulses() {
  numPulses = 0;
}

void addPulse(byte pmin=100, byte pmax=150, byte pmod=1,  byte pspeed=2, byte paccmin=1, byte paccmax=1, int pacc=0, byte ptype=0, int rangeMin=0, int rangeMax=400) {

  pulseSpeed[numPulses] = pspeed;
  pulseMin[numPulses] = pmin;
  pulseMax[numPulses] = pmax;
  pulseAcc[numPulses] = pacc;
  pulseMod[numPulses] = pmod;
  pulseAccMin[numPulses] = paccmin;
  pulseAccMax[numPulses] = paccmax;
  pulseType[numPulses] = ptype;
  pulseRangeStart[numPulses] = rangeMin;
  pulseRangeEnd[numPulses] = rangeMax;  
  pulseSet[numPulses] = true;

  numPulses++; numPulses %= NUMPULSES;
}




byte tmpPulse=0, tmpPulse2 = 0;
bool didPong = false;
void fwdPulse(){
  for( int i = 0; i < numPulses; i++) {
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
                        
                        /*Serial.print("bpulseVal ");
                        Serial.print(i);
                        Serial.print(": ");
                        Serial.println(bpulseVal[i]);
*/
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



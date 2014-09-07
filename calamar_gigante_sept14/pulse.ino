
void clearPulse() {
  setPulse(255,255,1,0,0,0,0,0);
}

void setPulse(byte pmin, byte pmax, byte pmod,  byte pspeed, byte paccmin, byte paccmax, byte pacc, byte ptype) {
  pulseSpeed = pspeed;
  pulseMin = pmin;
  pulseMax = pmax;
  pulseAcc = pacc;
  pulseMod = pmod;
  pulseAccMin = paccmin;
    pulseAccMax = paccmax;
  pulseType = ptype;  
}


void fwdPulse(){
  if( trigger (pulseMod) ) {
  //pulseVal+=(pulseSpeed/(float)255);
    bpulseVal+=pulseSpeed;
    pulseSpeed *= pong(pulseSpeed,pulseMin,pulseMax);
    if(pulseAcc > 0 ) {
      pulseSpeed += pulseAcc;
      pulseAcc *= pong(pulseAcc,pulseAccMin,pulseAccMax);
    }
  }
}



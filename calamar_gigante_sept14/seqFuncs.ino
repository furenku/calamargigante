void calma() {
if(cueInit &&  cueMs<10) {
        clearSeq();
        setLeds(aquamarina);   
           cueInit = false;
     
      }
      
      if( cueMs>10 && cueMs<200 && !cueInit ) {
        cueInit = true;
        

        addPulse(0,60,1,3,1,1,0,0,stripStart[0],stripEnd[1]);
        addPulse(20,120,1,10,1,15,-1,0,stripStart[2],stripEnd[3]);  
      }
      if( cueMs>200 && cueInit ) {
        cueInit = false;      
        addPulse(0,125,1,15,1,1,0,0,stripStart[4],stripEnd[6]);
        addPulse(30,60,1,25,1,1,0,0,stripStart[7],stripEnd[9]);
        addPulse(30,60,1,15,1,1,0,0,stripStart[10],stripEnd[11]);
        
      }  
}




void fadeOut() {
  
  
      if(cueMs>100 && cueMs<200 && !cueInit ) {
        cueInit = true;
        clearFades();
        addFade(0,100,1,10,0,0,0);
        addFade(101,200,1,10,0,0,0);
      }
      if(cueMs>200 && cueInit ) {
        cueInit = false;
        addFade(201,300,1,10,0,0,0);
        addFade(300,380,1,10,0,0,0);       
      }
      
}


void multiPulsi( byte pmin, byte pmax, byte pmod,  byte pspeed, byte paccmin, byte paccmax, int pacc ) {
  clearPulses();
  addPulse(stripStart[0],stripEnd[1],pmin,pmax,pmod,pspeed,paccmin,paccmax,pacc);
  addPulse(stripStart[2],stripEnd[3],pmin,pmax,pmod,pspeed,paccmin,paccmax,pacc);
  addPulse(stripStart[4],stripEnd[4],pmin,pmax,pmod,pspeed,paccmin,paccmax,pacc);
  addPulse(stripStart[5],stripEnd[5],pmin,pmax,pmod,pspeed,paccmin,paccmax,pacc);
  addPulse(stripStart[6],stripEnd[7],pmin,pmax,pmod,pspeed,paccmin,paccmax,pacc);
  addPulse(stripStart[8],stripEnd[9],pmin,pmax,pmod,pspeed,paccmin,paccmax,pacc);
  addPulse(stripStart[10],stripEnd[11],pmin,pmax,pmod,pspeed,paccmin,paccmax,pacc);
  addPulse(stripStart[11],stripEnd[12],pmin,pmax,pmod,pspeed,paccmin,paccmax,pacc);
}

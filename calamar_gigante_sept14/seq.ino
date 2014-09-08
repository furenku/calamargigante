bool cueInit = false;
long cueMs,cueMsStart;

void changeCue( int c ) {
   cue = c;
   resetCue();
}

void initCue() {
  cueInit = false;
}

void resetCue() {
  cueMs=0;
  cueMsStart=millis();
  cueInit = true;
}
uint32_t rojosuave = strip.Color(86,0,0);
uint32_t blancoclaro = strip.Color(55,58,59);
void clearSeq() {
  clearPulses();
  clearFades();
  clearUpdates();
}

void seq() {
  cueMs = millis() - cueMsStart;
  switch(cue) {
    case 0:

      if(cueInit && cueMs<1000) {
        setRGB(aquamarina);

        initCue();
        setLeds( azulrey );
      }
      
      if(cueMs>1000 && cueMs<2000 && !cueInit) {
        setLeds( blanco );
        cueInit=true;
      }
      
      if(cueMs>2000 && cueInit ) {
        cueInit = false;
              clearFades();

        addFade(0,100,1,10,0,0,0);
        addFade(101,200,1,10,0,0,0);
      }
      if(cueMs>2300 && !cueInit ) {
        cueInit = true;
        addFade(201,300,1,10,0,0,0);
        addFade(300,380,1,10,0,0,0);       
        
      }
      if(cueMs>2600 && cueInit ) {
         cueInit = false;
      }     
      break;
      
      
    case 1:
      
      if(cueInit &&  cueMs<10) {

        clearSeq();

        setLeds(blancoclaro);  
        cueInit = false;      
      }
      
      if( cueMs>10 && cueMs<200 && !cueInit ) {
        cueInit = true;
        setLeds(20,30,rojosuave);
        setLeds(40,60,rojosuave);
        setLeds(300,340,rojosuave);
        setLeds(stripStart[2],stripEnd[3],aquamarina);
        addPulse(0,100,1,2,1,1,0,0,stripStart[0],stripEnd[2]);
        addPulse(20,stripEnd[11],1,10,1,10,-1,0,stripStart[2],stripEnd[3]);  
        addFade( stripStart[2],stripEnd[3], 1, 10, 0, 155,155);
      }
      if( cueMs>200 && cueInit ) {
        cueInit = false;      
        addPulse(0,255,1,7,1,1,0,0,stripStart[4],stripEnd[6]);
        addPulse(0,100,1,10,1,1,0,0,stripStart[7],stripEnd[9]);        
      }

/*
      if(cueInit &&  cueMs<100) {
        clearPulses();
        clearFades();

        setLeds(blanco);   


      }
      
      if( cueMs>200 && cueMs<350 && !cueInit ) {
        cueInit = true;
        //addPulse(0,100,1,3,1,1,0,0,stripStart[0],stripEnd[1]);
        //addPulse(20,250,1,5,1,15,-1,0,stripStart[2],stripEnd[3]);  
        //setLeds(20,30,rojosuave);
        
      }
      if( cueMs>350 && cueMs<400 && cueInit ) {
        cueInit = false;      
        //setLeds(20,30,rojosuave);
      }
      if( cueMs>400 && !cueInit ) {
        //setLeds(200,350,rojosuave);
        cueInit = true;      
        addPulse(0,255,1,8,1,1,0,0,stripStart[4],stripEnd[6]);
        addPulse(0,100,1,12,1,1,0,0,stripStart[7],stripEnd[9]);
        addPulse(0,100,1,7,1,1,0,0,stripStart[10],stripEnd[11]);
        //setLeds(300,340,rojosuave);
        //addFade(stripStart[2],stripEnd[3],1,2,0,155,200);

      }
      
*/      
/*

         addFade(110, 140,1,2,86,0,0);     
        addFade(stripStart[2],stripEnd[3],2,10,0,150,250);        
*/


        /*
        }        
        
        
        for(int i = 20; i<30; i++){
            setLed( i, strip.Color(86,0,0) );
        }        
        for(int i = 40; i<60; i++){
            setLed( i, strip.Color(86,0,0) );
        }
        for(int i = 300; i<340; i++){
            setLed( i, strip.Color(255,0,0) );
        }
        for(int i = stripStart[2]; i<stripEnd[3]; i++){
            setLed( i, strip.Color(0,255,255) );
        }      */


      break;
    case 2:
       
      if(cueInit && cueMs<10) {
        //clearSeq();
        setOjo(rojosuave);   
           cueInit = false;
       setDance( 0, 300, 2 );
      }
      
      if( cueMs>10 && !cueInit && cueMs < 200) {
        cueInit = true;      
        addFade( stripStart[2], stripStart[3], 1,3,150,30,180 );
        clearSeq();

        addPulse(0,100,1,3,1,1,0,0,stripStart[0],stripEnd[1]);
        addPulse(20,250,1,15,1,15,-1,0,stripStart[2],stripEnd[3]);  
      }
      if( cueMs>200 && cueInit ) {
        cueInit = false;      
        addPulse(0,255,1,15,1,1,0,0,stripStart[4],stripEnd[6]);
        addPulse(0,100,1,25,1,1,0,0,stripStart[7],stripEnd[9]);
        addPulse(0,100,1,15,1,1,0,0,stripStart[10],stripEnd[11]);
        
      }
      danceAround( blancoclaro );

      break;
    case 3:
    
     if( cueInit && cueMs<10) {
        clearSeq();
// setLeds(0,stripEnd[3],aquamarina);   
         addFade(0,stripEnd[11],1,30,0,240,240);   
           cueInit = false;
     
      }
      
      if( cueMs>10 && cueMs<200 && !cueInit ) {
        cueInit = true;
        

        addPulse(0,100,1,2,1,1,0,0,stripStart[0],stripEnd[1]);
        addPulse(20,250,1,15,5,15,-1,0,stripStart[2],stripEnd[3]);  
      }
      if( cueMs>200 && cueInit ) {
        cueInit = false;      
        addPulse(0,255,1,15,7,15,-1,0,stripStart[4],stripEnd[6]);
        addPulse(0,100,1,15,6,15,-1,0,stripStart[7],stripEnd[9]);
        addPulse(0,100,1,15,5,15,-1,0,stripStart[10],stripEnd[11]);
        
      }

      break;
          case 4:
      blue();
      break;
    case 5:
      black();
      break;
    case 6:
      rainbow(1);
      break;
  }
 
  }
  
  

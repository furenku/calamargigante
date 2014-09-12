/*



//prueba inicial:



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
      
      
      
      
      
      

    if(cueMs>10 && cueInit ) {
        cueInit=false;
        clearSeq();
        
          //addPulse(30,180,1,3,1,1,0,0,0,400);
        setGradient(0,100,0,111,255,0,255,0,true);
        setGradient(1,200,0,111,255,255,255,25,true);
        setGradient(200,300,255,0,33,233,3,111,true);
        setGradient(300,400,0,111,33,33,255,0,true);
        addSeqUpdate(0, 100, 1);
        addSeqUpdate(100, 200, 1);
        addSeqUpdate(200, 300, 1);
        addSeqUpdate(300, 400, 1);
    }     
     if(cueMs>10 && cueMs<6000){
        seqUpdate();
      } 
      
      
      
      
      
      
      
if(cueInit &&  cueMs<10) {
        clearSeq();
        setLeds(rojo);   
           cueInit = false;
     
      }
      
      if( cueMs>10 && cueMs<200 && !cueInit ) {
        cueInit = true;
        

        addPulse(0,100,1,3,1,1,0,0,stripStart[0],stripEnd[1]);
        addPulse(20,250,1,15,1,15,-1,0,stripStart[2],stripEnd[3]);  
      }
      if( cueMs>200 && cueInit ) {
        cueInit = false;      
        addPulse(0,255,1,15,1,1,0,0,stripStart[4],stripEnd[6]);
        addPulse(0,100,1,25,1,1,0,0,stripStart[7],stripEnd[9]);
        addPulse(0,100,1,15,1,1,0,0,stripStart[10],stripEnd[11]);
        
      }

      if(cueMs>2000 && cueInit ) {
        cueInit=false;
        
        
        //addPulse(30,180,1,3,1,1,0,0,0,400);
      setGradient(0,100,0,111,255,0,255,0,true);
      setGradient(1,200,0,111,255,255,255,25,true);
      setGradient(200,300,255,0,33,233,3,111,true);
      setGradient(300,400,0,111,33,33,255,0,true);
      addSeqUpdate(0, 100, 1);
      addSeqUpdate(100, 200, 1);
      addSeqUpdate(200, 300, 1);
      addSeqUpdate(300, 400, 1);
      }     
     if(cueMs>2000 && cueMs<4000){
        seqUpdate();
      } 
      
      */
      
      /*
      clearFades();
      
      if(cueMs>2000 && cueInit ) {
        cueInit = false;
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
     */
      
      /*
      setLeds( strip.Color(255,255,255) );
      
      for(int i = 110; i<140; i++){
          setLed( i, strip.Color(86,0,0) );
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
      for(int i = 136; i<141; i++){
          setLed( i, strip.Color(0,255,255) );
      }
      */

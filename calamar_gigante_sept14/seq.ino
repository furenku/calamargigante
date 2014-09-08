  int mano1Start = 300;
  int mano2End = 350;

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
uint32_t amarillofeo = strip.Color(150,230,50);

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
      
      
    case 2:
      
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
    case 3:
       
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
    case 4:
    
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
          case 5:
          
       if( cueInit && cueMs<10) {
        clearSeq();
        // setLeds(0,stripEnd[3],aquamarina);   
           cueInit = false;
     
      }
      
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
      
      
      if( cueMs>200 && !cueInit ) {
        cueInit = true;
        clearSeq();
        addFade(0,stripEnd[11],1,20,80,80,80);   


        addPulse(0,100,1,2,1,1,0,0,stripStart[0],stripEnd[1]);
        addPulse(20,250,1,10,1,1,1,0,stripStart[2],stripEnd[3]);  
      }
      

      break;
    case 6:
       if( cueInit && cueMs<10) {
        clearSeq();
        // setLeds(0,stripEnd[3],aquamarina);   
           cueInit = false;
     
      }
      fadeOut();
      
      
       if( cueMs>200 && !cueInit ) {
        cueInit = true;
        clearSeq();
        addFade(0,stripEnd[11],1,20,80,80,80);   
        addPulse(0,100,1,2,1,1,0,0,stripStart[0],stripEnd[1]);
        addPulse(20,250,1,10,1,1,1,0,stripStart[2],stripEnd[3]);

      }
      
      
      break;
      case 7:
      if( cueInit && cueMs<10) {
        clearSeq();
        addFade(0,stripEnd[1],1,20,130,0,180);
        addFade(stripStart[4],stripEnd[11],1,20,130,0,180);
        addPulse(50,250,1,12,1,1,15,1,stripStart[0],stripEnd[1]);
        addPulse(50,250,1,20,1,1,10,1,stripStart[4],stripEnd[11]);
           cueInit = false;
     
      }
      break;
    case 8:
      if( cueInit && cueMs<10) {
        clearSeq();
        addFade(0,stripEnd[1],1,20,130,0,180);
        addFade(stripStart[4],stripEnd[11],1,20,130,0,180);
        addFade(stripStart[2],stripEnd[3],1,10,0,200,200);
        addPulse(50,250,1,6,1,15,1,-1,stripStart[0],stripEnd[1]);
        addPulse(50,250,1,8,1,15,3,-1,stripStart[4],stripEnd[11]);
           cueInit = false;
     
      }
      break;
      
    case 9:
      if( cueInit && cueMs<10) {
        clearSeq();
        cueInit = false;
        addFade(0,stripEnd[1],1,5,0,20,180);
        addFade(stripStart[4],stripEnd[11],1,5,0,20,180);
        addFade(stripStart[2],stripEnd[3],1,10,0,200,180);
      }
      break;

    case 10:
      if( cueInit && cueMs<10) {
        clearSeq();
        addFade(stripStart[0],stripEnd[11],1,15,0,180,180);
           cueInit = false;
     
      }
      /*
      if(cueMs>2000 && cueMs<20000 && !cueInit ) {
        cueInit = true;
        clearFades();
        
      }*/
      
      if(cueMs>2000 ) {
        rainbow(1);       
      }
      
      break;


case 11:
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
      break;
case 12:
      if( cueInit && cueMs<10) {
        clearSeq();
        addFade(stripStart[0],stripEnd[11],1,10,0,180,180);
           cueInit = false;
     
      }
      
     
      break;
case 13:
      if( cueInit && cueMs<10) {
        addFade(stripStart[2],stripEnd[3],1,10,180,180,180);
           cueInit = false;     
      }

case 14:
      calma();
      break;    


case 15:


    if(cueMs>10 && cueInit ) {
        cueInit=false;
        clearSeq();
        
          //addPulse(30,180,1,3,1,1,0,0,0,400);
        setGradient(0,150,0,200,255,0,0,0,true);
        setGradient(1,150,0,200,155,0,40,25,true);
        setGradient(200,300,150,0,200,255,0,0,true);
        setGradient(300,400,0,111,33,33,255,0,true);
        addSeqUpdate(0, 100, 1);
        addSeqUpdate(100, 200, 1);
        addSeqUpdate(200, 300, 1);
        addSeqUpdate(300, 400, 1);
    }     
     if(cueMs>10 && cueMs<6000){
        seqUpdate();
      } 
      
break;


case 16:
  calma();
      
break;


case 17: 

    if(cueInit ) {
        cueInit=false;
        setDance( mano1Start, mano2End, 1 );
    }
    if(cueMs> 10) {
      byte color = min(cueMs / 10, 150);
      danceAround( strip.Color( color, color, color  ) );
    }
break;

case 18:

    if( cueInit && cueMs<10) {
        clearSeq();
        // setLeds(0,stripEnd[3],aquamarina);   
           cueInit = false;
     
      }
      fadeOut();
      
      if(cueMs> 200 && !cueInit) {
        setLeds( 90, 140, blancoclaro );
        addPulse( 10,30,1,3,1,1,0,0,90,140 );
      }
      
break;

case 19:



    if(cueMs>10 && cueInit ) {
        cueInit=false;
        clearSeq();
        
          //addPulse(30,180,1,3,1,1,0,0,0,400);
        setGradient(0,150,80,80,255,255,0,50,true);
        setGradient(1,150,80,80,155,255,40,25,true);
        setGradient(200,300,80,80,200,255,0,30,true);
        setGradient(300,400,80,111,33,233,155,0,true);
        addSeqUpdate(0, 100, 1);
        addSeqUpdate(100, 200, 1);
        addSeqUpdate(200, 300, 1);
        addSeqUpdate(300, 400, 1);
    }    
   if(cueMs> 2000 && !cueInit) {
        setGradient(0,150,150,30,125,0,100,155,true);
        setGradient(1,150,100,20,125,0,100,185,true);
        setGradient(200,300,150,0,80,255,120,155,true);
        setGradient(300,400,110,11,133,33,100,155,true);
        addSeqUpdate(0, 100, 1);
        addSeqUpdate(100, 200, 1);
        addSeqUpdate(200, 300, 1);
        addSeqUpdate(300, 400, 1);
        cueInit = true;
      } 
     if(cueMs>2010 && cueInit ){
        seqUpdate();
      } 
      
      
break;


case 20:


if( cueInit && cueMs<10) {
        clearSeq();
       clearSeq();
       addFade(stripStart[0],stripEnd[11],1,10,50,180,50);
        addPulse(0,50,1,5,1,5,1,0,stripStart[0],stripEnd[11]);

           cueInit = false;
     
      }
      
      
break;

case 21:


if( cueInit && cueMs<10) {
        clearSeq();
        clearSeq();

        addFade(stripStart[0],stripEnd[1],1,10,150,230,50);
        addFade(stripStart[4],stripEnd[11],1,10,150,230,50);
        addFade(stripStart[2],stripEnd[3],1,10,255,150,0);
        addPulse(0,50,2,1,1,15,1,0,stripStart[0],stripEnd[11]);

           cueInit = false;
     
      }
break;

case 22:
      if( cueInit && cueMs<10) {
        setLeds(amarillofeo);
        clearSeq();
        cueInit = false;
        addPulse(30,80,1,2,1,1,0,0,0,350);

        addFade(stripStart[4],stripEnd[7],1,2,0,60,130);
        addFade(stripStart[8],stripEnd[11],1,3,0,200,180);
      }
      break;


case 23:
      if( cueInit && cueMs<10) {
        cueInit = false;
        addPulse(30,80,1,2,1,6,1,0,0,350);
        setDance(50,100,1);
      }
      if( cueMs > 20 ) {
        danceAround(blancoclaro);
      }


break;


case 24:


      if( cueInit && cueMs<10) {
        cueInit = false;
        setDance(300,350,1);
      }
      if( cueMs > 20 ) {
        danceAround(blancoclaro);
      }

break;



case 26:


      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
//        setLeds( azulrey );
        addPulse(30,150,1,2,1,1,15,1,0,350);

        addFade(0,100,1,10,150,0,80);
      }
      
      if(cueMs>1000 && cueMs<2000 && !cueInit) {
        addFade(101,200,1,10,0,0,0);
        
        cueInit=true;
      }
      
      if(cueMs>2000 && cueInit ) {
        cueInit = false;
        addFade(200,300,1,10,210,0,240);       

        clearFades();        
      }
      if(cueMs>2500 && !cueInit ) {
        cueInit = true;
        addFade(300,380,1,10,180,0,210);       
        
      }

break;


case 27:
if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
//        setLeds( azulrey );
        addPulse(30,150,1,2,1,1,15,1,0,350);

        setGradient(0,380,80,80,80,100,200,50,true);
      }
      if(cueMs>10) {
        seqUpdate();       
      }
break;

case 28:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setLeds(rojo);
      }
break;






case 29:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setLeds(azulrey);
      }
break;





case 30:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setLeds(rosado);
      }
break;





case 31:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setLeds(rosado);
      }
      
      drawStatic( min( cueMs / float(50) , 255 ) );
break;



case 32:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setLeds(azulrey);
      }
break;


//enffermedad
case 33:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setLeds(amarillofeo);
      }
      
      
      
      
case 34:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setLeds(rojo);
      }
break;


// navidad
case 35:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setLeds(strip.Color(0,200,0));
      }
break;


case 36:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setLeds(blancoclaro);
        addPulse(0,200,2,2,1,1,0,0,0,stripEnd[11]);
      }
break;


case 37:
      if( cueInit && cueMs<10) {
        cueInit = false;
        addFade(0,stripEnd[11],1,10,0,0,100);
        addPulse(50,100,2,3,1,1,0,0,0,stripEnd[11]);

      }
break;


case 38:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setLeds(blancoclaro);
        addFade(0,stripEnd[11],1,10,0,0,100);
        addPulse(00,250,2,10,1,1,0,0,0,stripEnd[11]);

      }
break;


case 39:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        addFade(0,stripEnd[11],1,10,80,80,100);
        addPulse(00,250,2,10,1,1,0,0,0,stripEnd[11]);

      }
break;


case 40:
     if( cueInit && cueMs<10) {
        clearSeq();
        // setLeds(0,stripEnd[3],aquamarina);   
           cueInit = false;
     
      }
      fadeOut();
      
      
break;
case 111:
      rainbow(1);
      break;
      
  }
 
  }
  
  

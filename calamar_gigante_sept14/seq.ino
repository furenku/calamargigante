  int mano1Start = 300;
  int mano2End = 360;

bool cueInit = false;
long cueMs,cueMsStart;

      int LEDoffset;
long cueCnt = 0;


void fwd() {
  fwdClock();
  fwdFade();
  fwdGeneralBrightnessFade();
  fwdPulse();
}


void changeCue( int c ) {
   cue = c;
   resetCue();
}

void initCue() {
  cueInit = false;
}

void resetCue() {
  cueMs=0;
  cueCnt = 0;
  cueMsStart=millis();
  cueInit = true;
}

uint32_t rojosuave = strip.Color(36,0,0);
uint32_t blancoclaro = strip.Color(55,58,59);
uint32_t amarillofeo = strip.Color(150,230,50);

void clearSeq() {
  clearPulses();
  clearFades();
  clearGeneralBrightnessFade();
  clearUpdates();
}

void c0() {
  cueInit = false;
}
void c1() {
  cueInit = true;
}




bool cueStep( long startMs, long endMs, bool check ) {
  if( cueInit == check && cueMs >= startMs && cueMs < endMs )
    return true;
  else
    return false;
}  


bool checker = true;
int lastSet = -1;

void seq() {
  cueMs = millis() - cueMsStart;
  cueCnt++;
  switch(cue) {
    
    case 0:
      if( cueInit && cueMs<10) {
        clearSeq();
        for( int i = 0 ; i < 12; i ++ ) {
          addFade(stripStart[i],stripEnd[i+1],1,5,random(0,50),random(0,105)*2 ,random(0,125)*2);
        }
        addFade( stripStart[2],stripEnd[3], 1, 10, 0, 255,155);
        ////addPulse(1,160,1,3,3,3,0,0,0,stripEnd[1]);
        ////addPulse(1,160,1,3,3,3,0,0,stripStart[3],stripEnd[12]);
        addPulse(100,160,1,5,3,3,0,0,stripStart[2],stripEnd[3]);
        setGeneralBrightness(0);
        fadeGeneralBrightness(1,5,50);
        //
        cueInit = false;
      } else if ( cueMs>20 && !cueInit ) {
        
        c1();
      
        
        if(cueCnt%10==0) {
          clearSeq();
          for( int i = 0 ; i < 12; i ++ ) {
            addFade(stripStart[i],stripEnd[i+1],1,5,50+random(0,25),75+random(0,25) ,random(0,25));
          }
        }
      }
           
      break;
      
    
    case 1111:
if( cueInit && cueMs<10) {
        clearSeq();
        /*addFade(0,stripEnd[12],1,5,azulrey);
        //addPulse(1,160,2,3,3,3,0,0,0,stripEnd[12]);
        */
        startBodySeq(15);
        cueInit = false;
      } else if ( cueMs>10 ) {
        bodySeq();
      }
           
      break;
      
      case 1:
      if( cueInit && cueMs<10) {
        clearSeq();
        setGeneralBrightness(1);
        setLeds(negro);
      }
           
      break;
            
    case 2:
      
      if( cueStep(10,30,true) ) {
        clearSeq();
        setLeds(negro);

        addFade(stripStart[0],stripEnd[1],1,1,80,80,80);  
        addFade(stripStart[4],stripEnd[12],1,1,80,80,80);  
       
        setGeneralBrightness(0);
        fadeGeneralBrightness(1,3,100);
        addPulse(0,30,2,3,1,1,0,0,stripStart[0],stripEnd[12]);
        c0();         
      }
      
      if( cueStep(30,200,false) ) {

        c1();
        setLeds(20,30,rojosuave);
        setLeds(40,60,rojosuave);        
      }


      break;
    // mugido tras : "solo es un calalamr gigante"
    case 3:       
      if( cueStep(10,500,true) ) {
        clearSeq();
        cueInit = false;
        addFade(0,stripEnd[12],1,30,1,1,1);   
      }            
      if( cueStep(500,1000,false) ) {
        c1();
        clearSeq();
        setGeneralBrightness(1);
        addFade(0,stripEnd[12],1,20,250,250,250);   
        addPulse(stripStart[0],stripEnd[12],60,90,2,3);
       }
       if( cueStep(1500,2000, true) ) {
        c0();
        clearFades();
        addFade(0,stripEnd[12],1,20,80,80,80);  
        fadeGeneralBrightness(0.5,1,100);

      } 
      break;
    // mugido breve tras "como"?  
    case 4:    
      if( cueStep(10,500,true) ) {
        clearSeq();
        cueInit = false;
        addFade(0,stripEnd[12],1,30,1,1,1);   
      }            
      if( cueStep(500,1000,false) ) {
        c1();
        clearSeq();
        setGeneralBrightness(1);
        addFade(0,stripEnd[12],1,20,250,250,250);   
        addPulse(stripStart[0],stripEnd[12],80,110,2,3);
       }
       if( cueStep(750,1000, true) ) {
        c0();
        clearFades();
        addFade(0,stripEnd[12],1,20,80,80,80);  
        fadeGeneralBrightness(0.5,1,100);

      } 
      break;
    // discurso largo
     case 5:    
     
      if( cueStep(10,500,true) ) {
        lastSet = -1;
        clearSeq();
        cueInit = false;
                setGeneralBrightness(1);

        addFade(0,stripEnd[12],1,30,1,1,1);   
      }            
      if( cueStep(500,1000,false) ) {
        c1();
        clearSeq();
        setGeneralBrightness(0.3);
        addFade(0,stripEnd[12],1,4,250,250,250);   
        
        fadeGeneralBrightness(1,1,5000);

        
       }
       
      if( cueStep(5000,8000,true) ) {
        c0();
        clearSeq();
        addFade(0,stripEnd[12],1,1,25,60,90);   
        
        fadeGeneralBrightness(0.3,10,5000);

        
       }
             
             
             
             
             

if( cueStep( 10000, 47000, false) ) {
  c0();
bool looptrigger=false;

for(int h = 0; h < 17; h++ ) {


      if( cueMs>10000 +(h*5000) && cueMs < 10000 +((h+1)*5000)+100 && lastSet != h ) {
        lastSet = h;
      Serial.println("turns: ");
      Serial.print(h);
      Serial.print(" --- b: ");
      Serial.print(lastSet);

      fadeGeneralBrightness(((h%2)*0.7)+0.3,2,100);

       clearSeq();  
       for( int i = 0 ; i < 12; i ++ ) {
        addFade(stripStart[i],stripEnd[i+1],1,1,random(0,250),random(0,250) ,random(0,250));
        if( h % 2 == 0 ) {
          multiPulsi(50+(h*15),110+(h*13),1,1,1,15+(h*2),1+h);
        }
        else {
          multiPulsi(50+(h*15),110+(h*13),1,1,15+(h*2),1,6-h);
        }
      }

      
      
      looptrigger != looptrigger;




  }
  

}    

}                 
    
      

       
       if( cueStep(47000,47100, false) ) {
         Serial.println("done");
        c1();
        clearSeq();
        setGeneralBrightness(0.5);
        addFade(0,stripEnd[1],1,4,255,255,255); 
        addFade(stripStart[4],stripEnd[12],1,4,80,80,80); 
        
        addFade(stripStart[2],stripEnd[3],1,4,aquamarina); 

        addPulse(0,30,2,3,1,1,0,0,stripStart[0],stripEnd[12]);
/*clearFades();
        addFade(0,stripEnd[12],1,20,80,80,80);  
        fadeGeneralBrightness(0.5,1,100);
*/
      } 
      break;






    // se estaban suicidando
    case 6:
       if( cueStep( 0,10,true ) ) {
        clearSeq();
        setGeneralBrightness(1);
        addFade(0,stripEnd[1],1,1,60,80,70); 
        addFade(stripStart[4],stripEnd[12],1,1,60,80,70); 
        
        addFade(stripStart[2],stripEnd[3],1,5,strip.Color(0,250,200)); 

        addPulse(0,30,2,2,1,1,0,0,stripStart[0],stripEnd[12]);
        c0();
      }
      

      break;
      
      // podemos verlo de cerca?
      case 7:
       if( cueStep( 0,10,true ) ) {
        clearSeq();
        setGeneralBrightness(1);
        setLeds(0,stripEnd[1],strip.Color(60,80,70)); 
        setLeds(stripStart[4],stripEnd[12],strip.Color(60,80,70));
        
        addFade(stripStart[2],stripEnd[3],1,5,strip.Color(0,250,200)); 

        addPulse(100,130,1,3,1,1,0,0,stripStart[0],stripEnd[12]);
        setDance(stripStart[6],stripStart[12],1,90,110,100);
        c0();
      }
      if( cueMs > 10 ) {
        byte f1 = cueMs%55;
        byte f2 = cueMs%25;
        byte f3 = cueMs%155;

        danceAround( strip.Color( 90,110,100 ));
      }

      break;
      
    //"tienes razon, ... trampa" - papa suelta sus hombros -  calamar se decepciona, baja su actividad y regresa a la debilidad inicial
      
    case 8:
      
      if( cueStep(10,30,true) ) {
        clearSeq();
        setLeds(negro);

        addFade(stripStart[0],stripEnd[1],1,1,80,80,80);  
        addFade(stripStart[4],stripEnd[12],1,1,80,80,80);  
       
        fadeGeneralBrightness(1/2,3,20);
        addPulse(10,40,2,3,1,1,0,0,stripStart[0],stripEnd[12]);
        c0();         
      }
      
      if( cueStep(30,200,false) ) {

        c1();
        setLeds(20,30,aquamarina);
        setLeds(40,60,aquamarina);        
      }
      
      break;
      
    case 9:
      if( cueInit && cueMs<10) {
        clearSeq();
        cueInit = false;
        addFade(0,stripEnd[1],1,5,0,20,180);
                
        addFade(stripStart[4],stripEnd[11],1,5,0,20,180);
        addFadeOjo(1,10,0,200,180);
        //addPulse(50,150,1,8,3,15,-1,0,stripStart[2],stripEnd[3]);

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
        //addPulse(0,100,1,2,1,1,0,0,stripStart[0],stripEnd[2]);
        //addPulse(20,stripEnd[11],1,10,1,10,-1,0,stripStart[2],stripEnd[3]);  
        addFade( stripStart[2],stripEnd[3], 1, 10, 0, 155,155);
      }
      if( cueMs>200 && cueInit ) {
        cueInit = false;      
        //addPulse(0,255,1,7,1,1,0,0,stripStart[4],stripEnd[6]);
        //addPulse(0,100,1,10,1,1,0,0,stripStart[7],stripEnd[9]);        
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
        addFade(stripStart[2],stripEnd[3],1,30,180,180,180);
           cueInit = false;     
      }

case 14:
      calma();
      break;    


case 15:


    if(cueMs>10 && cueInit ) {
        cueInit=false;
        clearSeq();
        
          ////addPulse(30,180,1,3,1,1,0,0,0,400);
        setGradient(0,150,0,200,255,0,0,0,true);
        setGradient(1,150,0,200,155,0,40,25,true);
        setGradient(200,300,150,0,200,255,0,0,true);
        setGradient(300,400,0,111,33,33,255,0,true);
        addSeqUpdate(0, 100, 1,5);
        addSeqUpdate(100, 200, 1,5);
        addSeqUpdate(200, 300, 1,5);
        addSeqUpdate(300, 380, 1,5);
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
        //addPulse( 10,30,1,3,1,1,0,0,90,140 );
      }
      
break;

case 19:



    if(cueMs<10 && cueInit ) {
        cueInit=false;
        clearSeq();
        
          ////addPulse(30,180,1,3,1,1,0,0,0,400);
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
        //addPulse(0,50,1,5,1,5,1,0,stripStart[0],stripEnd[11]);

           cueInit = false;
     
      }
      
      
break;

case 21:


if( cueInit && cueMs<10) {
        clearSeq();

        addFade(stripStart[0],stripEnd[1],1,10,150,230,50);
        addFade(stripStart[4],stripEnd[11],1,10,150,230,50);
        addFade(stripStart[2],stripEnd[3],1,10,255,150,0);
        //addPulse(0,50,1,5,1,15,1,0,stripStart[0],stripEnd[11]);

           cueInit = false;
     
      }
break;

case 22:
      if( cueInit && cueMs<10) {
        setLeds(amarillofeo);
        clearSeq();
        cueInit = false;
        //addPulse(30,80,1,2,1,1,0,0,0,350);
        setOjo(blancoclaro);
        addFade(stripStart[4],stripEnd[7],1,2,0,60,130);
        addFade(stripStart[8],stripEnd[11],1,3,0,200,180);
      }
      break;


case 23:
      if( cueInit && cueMs<10) {
        cueInit = false;
        //addPulse(30,80,1,2,1,6,1,0,0,350);
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
        //addPulse(30,150,1,2,1,1,15,1,0,350);

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
        //addPulse(30,150,1,2,1,1,15,1,0,300);
clearUpdates();
        setGradient(180,380,80,80,80,100,200,50,true);
        addSeqUpdate(180,380,1);
      }
      if(cueMs>10) {
        seqUpdate();       
      }
break;

case 28:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        addFade(stripStart[0], stripEnd[12],1,5,255,0,0);
      }
break;






case 29:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        addFade(0,stripEnd[11],1,10,0,0,180);
      }
break;





case 30:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setLeds( strip.Color(150,0,80));
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
      setGradient(stripStart[0],stripEnd[12],50,0,50,0,150,210);
      /*
      setGradient(stripStart[3],stripEnd[6],30,60,200,0,150,210);
      setGradient(stripStart[7],stripEnd[9],30,0,200,0,150,210);
      setGradient(stripStart[10],stripEnd[12],0,30,200,0,150,210);
      */
/*      addSeqUpdate(stripStart[0], stripEnd[1], 1);
      addSeqUpdate(stripStart[3], stripEnd[6], 1);
      addSeqUpdate(stripStart[7], stripEnd[9], 1);
      addSeqUpdate(stripStart[10], stripEnd[9], 1);
*/      }
      if( cueMs>10) {
        seqUpdate();
      }
break;


//enffermedad
case 33:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        addFade(0,stripEnd[11],1,10,100,250,50);
        setDance(0,stripEnd[11],4);
      }
      danceAround(blanco);
      
      
      
case 34:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
                addFade(0,stripEnd[11],1,10,60,0,0);
                
      }
break;


// navidad
case 35:
      if( cueInit && cueMs<10) {
              LEDoffset=0;

        cueInit = false;
        clearSeq();
        
      }
      if(cueMs>10) {
        for(int i = 0; i< NUMLEDS; i++) {
          if( (i+LEDoffset)%3 == 0 )
            setLed(i,strip.Color(0,255,0));
          if( (i+LEDoffset)%3 == 1 )
            setLed(i,rojo);
          if( (i+LEDoffset)%3 == 2 )
            setLed(i,blancoclaro);
        }
        if(trigger(4)){
          LEDoffset++;
          LEDoffset%=20;
        }
      }
break;


case 36:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        addFade(0,stripEnd[11],1,10,80,80,80);
        //addPulse(0,200,2,2,1,1,0,0,0,stripEnd[12]);
      }
break;


case 37:
      if( cueInit && cueMs<10) {
        cueInit = false;
        addFade(0,stripEnd[11],1,10,0,0,100);
        //addPulse(50,100,2,3,1,1,0,0,0,stripEnd[12]);

      }
break;


case 38:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setLeds(blancoclaro);
        addFade(0,stripEnd[6],1,10,0,0,100);
        addFade(stripStart[7],stripEnd[11],1,10,30,150,100);        
        //addPulse(0,stripEnd[11],2,10,1,1,0,0,0,stripEnd[11]);

      }
break;


case 39:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        addFade(0,stripEnd[11],1,10,80,80,100);
        //addPulse(00,250,2,10,1,1,0,0,0,stripEnd[11]);

      }
break;


case 40:
     if( cueInit && cueMs<10) {
        clearSeq();
        // setLeds(0,stripEnd[3],aquamarina);   
           cueInit = false;
           addFade(0,380,1,10,3,3,3);

      }
      
      
break;


case 41:
if( cueInit && cueMs<10) {
        clearSeq();
        setLeds(negro);   
           cueInit = false;
      }
           
      break;
      
      
      
case 42:
if( cueInit && cueMs<10) {
        clearSeq();
        setLeds(blanco);   
        addFade(0,stripEnd[12],1,1,240,0,240);
           cueInit = false;
      }
           
      break;
    
    
    
    
case 111:
      rainbow(1);
      break;
      
  }
 
  }
  
  

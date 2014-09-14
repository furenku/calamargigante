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
uint32_t naranja = strip.Color(255,170,0);
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
    // quitar el de prueba
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
        setLeds(negro);
      }
           
      break;
            
    case 2:
      // bajarle velocidad sin que flicker
      // que viajen tentaculos
      if( cueStep(0,10,true) ) {
        setGeneralBrightness(1);
        clearSeq();
        addFade(stripStart[0],stripEnd[1],1,1,80,80,80);  
        addFade(stripStart[4],stripEnd[12],1,1,80,80,80);  
       
        //fadeGeneralBrightness(1,3,30);
        addPulse(stripStart[0],stripEnd[12],20,40,1,1);
        c0();         
      }
      
      if( cueStep(30,200,false) ) {

        c1();
        setLeds(20,30,rojosuave);
        setLeds(40,60,rojosuave);        
      }


      break;
    // mugido tras : "solo es un calalamr gigante"
    // que no pulse
    // mas movimiento hacia afuera
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
        //addPulse(stripStart[0],stripEnd[12],80,110,2,3);
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

        addFade(0,stripEnd[12],1,10,1,1,1);   
      }            
      if( cueStep(500,1000,false) ) {
        c1();
        clearSeq();
        //setGeneralBrightness(0.3);
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
        /*
        Serial.println("turns: ");
        Serial.print(h);
        Serial.print(" --- b: ");
        Serial.print(lastSet);
        */
        clearSeq();  
        fadeGeneralBrightness(((h%2)*0.7)+0.3,2,100);

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

        addPulse(stripStart[0],stripEnd[12],0,30,2,3,1,1,0);
/*clearFades();
        addFade(0,stripEnd[12],1,20,80,80,80);  
        fadeGeneralBrightness(0.5,1,100);
*/
      } 
      break;






    // se estaban suicidando
    // que no llegue a 0
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
        fadeGeneralBrightness(1,0,20);
        setLeds(0,stripEnd[1],strip.Color(60,80,70)); 
        setLeds(stripStart[4],stripEnd[12],strip.Color(60,80,70));
        
        addFade(stripStart[2],stripEnd[3],1,5,strip.Color(0,250,200)); 

        //addPulse(stripStart[0],stripEnd[12],100,130,1,3);
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
      //quitar
    case 8:
      
      if( cueStep(0,10,true) ) {
        clearSeq();
        setLeds(negro);

        addFade(stripStart[0],stripEnd[1],1,1,80,80,80);  
        addFade(stripStart[4],stripEnd[12],1,1,80,80,80);  
       
        fadeGeneralBrightness(0.5,3,20);
        addPulse(stripStart[0],stripEnd[12],10,40,1,1);
        c0();         
      }
      
      if( cueStep(30,200,false) ) {

        c1();
        setLeds(20,30,aquamarina);
        setLeds(40,60,aquamarina);        
      }
      
      break;
    
    
    // niño cuenta sueño  -  niño menciona ojo que brilla como luna
    case 9:
      if( cueInit && cueMs<10) {
        clearFades();
        fadeGeneralBrightness(1,3,100);
        
        cueInit = false;
        addFade(0,stripEnd[1],3,2,aquamarina);
                
        addFade(stripStart[4],stripEnd[12],3,2,aquamarina);
        addFadeOjo(1,1,255,255,255);
        //addPulse(50,150,1,8,3,15,-1,0,stripStart[2],stripEnd[3]);

      }
      break;
    // "asi son ellos" - calamar no debe robar foco - ojo regresa a color anterior (cual color anterior?) - se queda pulsando liso hacia aquamarina sutil con variacion
    
    // mas mov.  en tentaculos  
    case 10:
      if( cueInit && cueMs<10) {
        clearFades();
        //fadeGeneralBrightness(0.5,3,30);
        
        cueInit = false;
        addFade(0,stripEnd[1],3,2,blancoclaro);                
        addFade(stripStart[4],stripEnd[12],3,2,blancoclaro);
        addFadeOjo(1,1,255,255,255);
        addPulse(stripStart[2],stripEnd[3],30,80,1,1);

      }
      break;
//"cada vez que lo decia me sentia mas tonta " calamar se emputa un poco . calamar se llena de abajo arriba rapido color casi rojo morado, y luego retrocede pq no la abraza
    case 11:
      if( cueInit && cueMs<10) {
        clearSeq();
        startBodyFill(25,80,20,40);
        addPulse(stripStart[0],stripEnd[12],110,240,2,5,5,1,-1);
        addPulse(stripStart[2],stripEnd[3],50,240,2,25,5,1,-1);

        cueInit = false;
      } else if ( cueMs>10 && cueMs < 1000) {
        bodyFill();
        setOjo(rojo);
      } else if ( cueStep(1000 ,1100,false) ) {
        c1();
        addFade(  stripStart[0],stripEnd[12],2,1, 255,255,255 );
        fadeGeneralBrightness(0.3,3,100);

      }
      
      break;

/*
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
*/      

// "estuvieron ahi ayer" - inicia un crescendo que dura hasta que gary apaga la tele
// que no lloegue a 0
// cuidar crescendo
    case 12:
      if( cueInit && cueMs<10) {
        fadeGeneralBrightness(0.5,3,100);

           cueInit = false;
           lastSet = -1;
      }



      
      if( cueStep( 6000, 30000, false) ) {
        c0();
        for(int h = 0; h < 5; h++ ) {
              if( cueMs>6000 +(h*6000) && cueMs < 6000 +((h+1)*6000)+100 && lastSet != h ) {
                lastSet = h;        
                clearSeq();           
                fadeGeneralBrightness( 0.5 + (0.125 * h) ,2,100);  
                addPulse(stripStart[0],stripEnd[12],10+(h*1),60+(h*2),1,2);
                addPulse(stripStart[2],stripEnd[3],10+(h*1),60+(h*2),1,2);              
          }     
        }    
      }                 
          
     
    break;


// garyu apaga la tele, calamar se enfada

case 13:
      if( cueInit && cueMs<10) {
        clearSeq();
        startBodyFill(45,255,0,0);
        addPulse(stripStart[0],stripEnd[12],100,240,1,25,25,5,-2);
        addPulse(stripStart[2],stripEnd[3],100,240,1,35,35,5,-2);

        cueInit = false;
      } else if ( cueMs>10 && cueMs < 2000) {
        bodyFill();
        setOjo(blanco);
      } else if ( cueStep(2000 ,2100,false) ) {
        c1();
        fadeGeneralBrightness( 0.3,2,100);  
        addFade(  stripStart[0],stripEnd[12],2,1, 100,0,80 );
        clearPulses();

      }
      
      break;


// padres pelean, se pone verdegris: ala vida seria perfect

// ALENTAR TRANSICION
case 14:
      if( cueInit && cueMs<10) {
        clearSeq();
        //addFade(  stripStart[0],stripEnd[12],2,1, 80,80,80 );
        addPulse(stripStart[0],stripEnd[12],100,240,2,1,1,5,1);

        c0();
      }
      else if ( cueStep(10,2000,false)) {
        c1();
        fadeGeneralBrightness( 1,2,300);  

        clearFades();
        addFade(  stripStart[0],stripEnd[12],2,5, 50,80,50 );

      } 

    
      break;    

//si lo analizas, no tiene sentido..." 
case 15:
//QUITAR PULSO
    // q siga el vol  de garysale.wav

    if(cueMs>10 && cueInit ) {
        cueInit=false;
        clearSeq();
        
        addPulse( stripStart[0],stripEnd[12] , 100 ,150 , 1,3,1,6,1);
        setGradient(stripStart[0],stripEnd[1],50,80,50,60,100,60,true);
        addSeqUpdate(stripStart[0],stripEnd[1], 1,5);
        setGradient(stripStart[4],stripEnd[5],60,100,60,90,140,40,true);
        addSeqUpdate(stripStart[4],stripEnd[5], 1,5);
        setGradient(stripStart[6],stripEnd[8],100,130,80,120,170,50,true);
        addSeqUpdate(stripStart[6],stripEnd[8], 1,5);
        setGradient(stripStart[9],stripEnd[12],100,130,80,150,230,50,true);
        addSeqUpdate(stripStart[9],stripEnd[12], 1,5);
  
    }     
     if(cueMs>10 && cueMs<6000){
        seqUpdate();
      } 
break;


//la gente necesita tener ilusiones, verdad' - la tele reacciona al calamar. el calamar tiene una animacion suavecita ondulante y lenta hacia los tentaculos .. estos tienen ms luz que en el resto (un abrazo)
case 16:
  if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();

        setGradient(stripStart[6],stripEnd[8],100,130,80,120,150,70,true);
        addSeqUpdate(stripStart[6],stripEnd[8], 3,1);
        setGradient(stripStart[9],stripEnd[12],100,130,80,150,150,90,true);
        addSeqUpdate(stripStart[9],stripEnd[12], 3,1);
        //addPulse(stripStart[0],stripEnd[12] , 30,80,1,2);
        setDance(stripStart[6],stripEnd[12],1,120,150,70);
      }
      if( cueMs > 20 ) {
        seqUpdate();
        danceAround(strip.Color(60,180,130));
      }
      
break;
//ella choca, inicia animacion en la MANO -  reaccion expansiva blanca - luego ilumina donde ella esta - mientras pulsa "respira" muy lento (descendiendo)
case 17:
  if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        addPulse(stripStart[0],stripEnd[12] , 30,80,1,2,1,1,0);
        setDance(50,100,1);
      }
      if( cueMs > 20 ) {
        danceAround(blancoclaro);
      }
      
break;

//agarran 1er tentaculo - animacion a partir de ese punto 
case 18: 
// MAS EN LAS MANOS
    if(cueInit ) {
        cueInit=false;
        setDance( mano1Start, mano2End, 1,70,120,120);

    }
    if(cueMs> 10) {
      danceAround(strip.Color(170,200,120));
    }
break;

//"soy una niña diminuta" - el calamar emocionandose - trancesoso - se pone mas violeta de la cola, se va intensificando desde ahi todo el cuerpo y rellenandose
case 19:

// QUE ENTRE DE INMEDIATO
// SIN TINTILEO

    if(cueMs<10 && cueInit ) {
//        clearSeq();
        //setGeneralBrightness(1);
          ////addPulse(30,180,1,3,1,1,0,0,0,400);
               
        clearUpdates();

        setGradient(stripStart[0],stripEnd[0],80,80,255,255,0,50,true);
        setGradient(stripStart[1],stripEnd[1],80,80,255,255,0,50,true);

        setGradient(stripStart[4],stripEnd[4],80,80,155,255,40,25,true);
        setGradient(stripStart[5],stripEnd[5],80,80,155,255,40,25,true);

        setGradient(stripStart[6],stripEnd[7],150,0,80,255,120,155,true);
        setGradient(stripStart[8],stripEnd[9],150,0,80,255,120,155,true);

        setGradient(stripStart[10],stripEnd[10],80,80,200,255,0,30,true);
        setGradient(stripStart[11],stripEnd[12],80,111,33,233,155,0,true);

        addSeqUpdate(stripStart[0],stripEnd[0], 1);
        addSeqUpdate(stripStart[1],stripEnd[1], 1);
        addSeqUpdate(stripStart[4],stripEnd[4], 1);
        addSeqUpdate(stripStart[5],stripEnd[5], 1);
        addSeqUpdate(stripStart[6],stripEnd[8], 1);
        addSeqUpdate(stripStart[9],stripEnd[12], 1);
        
        cueInit=false;

      }    
   if(cueMs> 4000 && !cueInit) {
        clearUpdates();
        setGradient(stripStart[0],stripEnd[0],150,30,125,0,100,155,true);
        setGradient(stripStart[1],stripEnd[1],150,30,125,0,100,155,true);

        setGradient(stripStart[4],stripEnd[4],100,20,125,0,100,185,true);
        setGradient(stripStart[5],stripEnd[5],100,20,125,0,100,185,true);

        setGradient(stripStart[6],stripEnd[7],150,0,80,255,120,155,true);
        setGradient(stripStart[8],stripEnd[9],150,0,80,255,120,155,true);

        setGradient(stripStart[10],stripEnd[10],110,11,133,33,100,155,true);
        setGradient(stripStart[11],stripEnd[12],110,11,133,33,100,155,true);

        addSeqUpdate(stripStart[0],stripEnd[0], 1);
        addSeqUpdate(stripStart[1],stripEnd[1], 1);
        addSeqUpdate(stripStart[4],stripEnd[4], 1);
        addSeqUpdate(stripStart[5],stripEnd[5], 1);
        addSeqUpdate(stripStart[6],stripEnd[8], 1);
        addSeqUpdate(stripStart[9],stripEnd[12], 1);    
        
        cueInit = true;
      } 
     if(cueMs>2010 && cueInit ){
        seqUpdate();
      } 
      
      
break;

//se desmaya - se retira el color intenso, y luego se pone de un color chafa liso rellenandose en sentido contrario
case 20:


if( cueInit && cueMs<10) {
       clearPulses();
       addFade(stripStart[0],stripEnd[12],1,10,150,230,50);
       addPulse(stripStart[0],stripEnd[12],100,240,1,1);

           cueInit = false;
     
      }
      
      
break;

// el calamar se emputa y muje - se rellena de rojo y pulsa muy rapido y pulsa mas intenso en las extremidades. ojo naranja
//accidente increible:!!!

// REDUCIR NEGRO!!
//Y EL PULSO ESTA RARO
case 21:

        if( cueStep(0,10,true) ) {
          clearSeq();
          setGeneralBrightness(1);  
          c0();
          addFade(stripStart[0],stripEnd[12],1,40,1,1,1);   
        }            
        if( cueStep(1000,1500,false) ) {
          c1();
          
          clearSeq();
          addFade(stripStart[0],stripEnd[1],1,10,150,0,0);
          addFade(stripStart[4],stripEnd[12],1,10,150,0,0);
          addFade(stripStart[2],stripEnd[3],1,10,150,100,0);
          addPulse(stripStart[0],stripEnd[12],150,200,1,7,7,1,-1);
          //fadeGeneralBrightness(0.5,10,1000);
                 
        }
       if( cueStep(2000,5000,true) ) {
        // setLeds(rojo);
        clearSeq();
        addFade(0,stripEnd[12],1,5,azulindigo);             

         setDance( 0,stripEnd[12], 1, 250,50,0 ); 
         c0();
       }
       if( cueStep(2000,5000,false) ) {
         danceAround( strip.Color( 250,50,0 ) );
       }
       
      if( cueStep(5001,8000,true) ) {
        c0();
        //clearSeq();
        //addFade(0,stripEnd[12],1,10,150,230,20);             

        //addPulse(stripStart[0],stripEnd[12],70,120,1,1,1,1,1);
        //fadeGeneralBrightness(0.3,10,500);
       }
             
break;
// a la iglesia - niños salen
case 22:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        //setGeneralBrightness(0.15);

        addFade(stripStart[0],stripEnd[1],1,3,azulindigo);
        addFade(stripStart[4],stripEnd[12],1,3,azulindigo);
       /* addFade(stripStart[6],stripEnd[7],1,2,0,60,130);
        addFade(stripStart[9],stripEnd[10],1,3,0,200,180);
*/
        addPulse(stripStart[0],stripEnd[12],30,80,3,5,5,1,-1);
        setOjo(blancoclaro);
      }
      break;

//"DONDE ESTA MI MAMI" - 5 segudnos - cambian a rosado pixeles al azar, uno por uno y luego sus contiguos, aprecen mas encendiddos al azar hasta que se completa .

//70 segundos -> transiciona hacia estatica TV utilizando tetris y a ver que pasa


case 23:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setGeneralBrightness(0.15);
        fadeGeneralBrightness(1,10,1000);

        addPulse(130,160,1,2);
       
        addFade(stripStart[0],stripEnd[12],1,3,rosado);
      }        
      if( cueStep(5000,5100,false )) {
        for(int i = 0; i < stripEnd[12]; i++ ) {
          tmpLeds[i] = rosado;
        }
        c1();
      }
      if( cueStep(5100,70000,true )) {
        drawStatic( min( (cueMs / float(70000) )* 255 , 255 ), 180,180,180 );
      }


break;

// "la TV para presidente!" - al calamar le da verguenza ser TV y se pasa a azul indigo 

case 24:


      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        setGeneralBrightness(1);

        addFade(stripStart[0],stripEnd[1],1,30,azuloscuro);
        addFade(stripStart[4],stripEnd[12],1,30,azuloscuro);
       /* addFade(stripStart[6],stripEnd[7],1,2,0,60,130);
        addFade(stripStart[9],stripEnd[10],1,3,0,200,180);
*/
        addPulse(stripStart[0],stripEnd[12],30,80,3,5,5,1,-1);
        setOjo(aquamarina);
      }
      break;

break;

// el calamar ilustra la enfermedad del niño, inflamacion que crece, pudredumbre verde en el pulmon

// QUE NO SE APAGUE
case 26:

// color enfermo recorre tentaculos
      if( cueInit && cueMs<10) {
        clearSeq();
        addFade(stripStart[0]+30,stripEnd[0]+25,2,3,150,230,80);
        addPulse(stripStart[0]+30,stripEnd[0]+25,30,180,1,2,1,5,1);

        addFade(stripStart[1]+22,stripEnd[1]+45,2,1,50,230,180);
        addPulse(stripStart[0]+30,stripEnd[1]+25,30,180,1,2,1,5,1);
        
c0;
      }
      
      
break;

// el niño toca la caja, y de ahi empieza a irradiar la navidad. la navidad va intensificandose hasta ser incontenible durante 20 segundos

case 27:
      if( cueInit && cueMs<10) {
              LEDoffset=0;

        cueInit = false;
        clearSeq();
                setGeneralBrightness(1);

      }
      if(trigger(4)){
          LEDoffset++;
          LEDoffset%=20;
        }
        
      if(cueStep(10,3000,false)) {
        for(int i = 0; i< NUMLEDS; i++) {
          if( (i+LEDoffset)%3 == 0 )
            setLed(i,strip.Color(0,255,0));
          if( (i+LEDoffset)%3 == 1 )
            setLed(i,rojo);
          if( (i+LEDoffset)%3 == 2 )
            setLed(i,white());
        }
        
      }
     if(cueStep(3001,6000,false)) {
        for(int i = 0; i< NUMLEDS; i++) {
          if( (i+LEDoffset)%3 == 0 )
            setLed(i,strip.Color(50,150,30));
          if( (i+LEDoffset)%3 == 1 )
            setLed(i,rojo);
          if( (i+LEDoffset)%3 == 2 )
            setLed(i,strip.Color(50,50,50));
        }

      }      
      
     if(cueStep(6001,9000,false)) {
        for(int i = 0; i< NUMLEDS; i++) {
          if( (i+LEDoffset)%3 == 0 )
            setLed(i,strip.Color(80,0,40));
          if( (i+LEDoffset)%3 == 1 )
            setLed(i,strip.Color(250,50,130));
          if( (i+LEDoffset)%3 == 2 )
            setLed(i,strip.Color(150,0,100));
        }

      }         
      
     if(cueStep(9001,10001,false)) {
        for(int i = 0; i< NUMLEDS; i++) {
          if( (i+LEDoffset)%3 == 0 )
            setLed(i,strip.Color(180,0,100));
          if( (i+LEDoffset)%3 == 1 )
            setLed(i,strip.Color(250,20,130));
          if( (i+LEDoffset)%3 == 2 )
            setLed(i,strip.Color(230,0,90));
        }

      }       
break;


//35. susan empieza a hacer el sonido de las olas con la TV (5 segundos de periodo) (pulso de intensidad y "oleaje en la animacion
// QUE NO SE PRENDA MAS
case 28:
if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        
        setGeneralBrightness(1);

        addFade(stripStart[0],stripEnd[1],1,3,blancoclaro);
        addFade(stripStart[4],stripEnd[12],1,3,blancoclaro);
       /* addFade(stripStart[6],stripEnd[7],1,2,0,60,130);
        addFade(stripStart[9],stripEnd[10],1,3,0,200,180);
*/
        addPulse(stripStart[0],stripEnd[12],20,180,2,7,1,5,0);
        setOjo(blancoclaro);
      }
break;


// "tengo sueño" - empieza a transicionar  hacia azul oscuro en 10 s, se mantiene el oleaje


// SUBIR UN POQUITO EL PULSO
case 29:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearFades();
        addFade(0,stripEnd[12],1,1,azuloscuro);
      }
break;



// el calamar hace un gesto breve , parecido a escupir. se acumula mdio lento (5 segs) luz en el centro, y de ahi luego se proyecta rapido hacia afuera ( 0.5 seg )




case 30:
      if( cueStep(0,10,true) ) {
        cueInit = false;
        clearSeq();
      } else if ( cueStep(10,150,false) ) {
        c1();
        addFade(stripStart[6],stripEnd[7],1,10,blanco);
      }
      else if ( cueStep(150,300,true) ) {
        c0();
        addFade(stripStart[8],stripEnd[9],1,10,blanco);        
      }
      else if ( cueStep(450,600,false) ) {
        c1();
        addFade(stripStart[1],stripEnd[1],1,10,blanco);
        addFade(stripStart[10],stripEnd[11],1,10,blanco);
      }
      else if ( cueStep(600,750,true) ) {
        c0();
        addFade(stripStart[0],stripEnd[0],1,10,blanco);

        addFade(stripStart[11],stripEnd[12],1,10,blanco);        
      }  
  
      else if ( cueStep(750,900,false) ) {
        c1();
        clearSeq();
        addFade(stripStart[0],stripEnd[12],1,10,azuloscuro);        
      }      
      
break;

//"ES COMO SI YA ME HUBIERA IDO"
//38. jed cierra los ojos - calamar abre los ojos - bajar intensidad cuerpo y prender los ojos en verde 
// TRES SEGUNDOS Y LUEGO YA A NEGROS

case 31:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearFades();
        addFade(stripStart[0],stripEnd[1],1,2,negro);
        addFade(stripStart[4],stripEnd[12],1,2,negro);
        addFade(stripStart[2],stripEnd[3],1,3,0,255,0);
      }
      
//      drawStatic( min( cueMs / float(50) , 255 ) );
break;

// todo se apaga


case 32:
      if( cueInit && cueMs<10) {
        cueInit = false;
        clearSeq();
        addFade(stripStart[0],stripEnd[12],1,10,negro);

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

/*
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















//accidente increible:!!!
case 221:

        if( cueStep(0,10,true) ) {
          clearSeq();
          c0();
          addFade(stripStart[0],stripEnd[12],1,30,1,1,1);   
        }            
        if( cueStep(600,700,false) ) {
          c1();
          setGeneralBrightness(1);  
          clearSeq();
          addFade(stripStart[0],stripEnd[12],1,5,250,0,0);
          addPulse(stripStart[0],stripEnd[12],200,250,1,7,7,1,-1);
          fadeGeneralBrightness(0.5,10,1000);
          setDance( 0,stripEnd[12], 1, 250,50,0 );        
        }
         
       if( cueStep(600,5000,true) ) {
         danceAround( strip.Color( 250,50,0 ) );
       }
       
      if( cueStep(5000,8000,true) ) {
        c0();
        clearSeq();
        addPulse(stripStart[0],stripEnd[12],70,120,1,1,1,1,1);
        addFade(0,stripEnd[12],1,5,1,1,1);             
        fadeGeneralBrightness(0.3,10,5000);
       }
             
break;


*/
      
  }
 
  }
  
  

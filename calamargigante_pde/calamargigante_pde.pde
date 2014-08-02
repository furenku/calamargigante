// variables

int NUMLEDS = 400;
int NUMSTRIPS = 13;
int ELLIPSESIZE  = 10;

int[] b_rangoPos = new int[NUMSTRIPS];
//int b_rangoPos[NUMSTRIPS];
int[] b_rangoPct = new int[NUMSTRIPS];
//int b_rangoPct[NUMSTRIPS];




//int LED[NUMLEDS];
int clock = 0;

int[][] LED = new int[NUMLEDS][3];
//int LED[NUMLEDS][3];

int[] b_pulseVar = new int[NUMLEDS];
//int b_pulseVar[NUMLEDS];


//int LEDx[NUMLEDS];
//int LEDy[NUMLEDS];


// solo en processing:
int[] LEDx = new int [NUMLEDS];
int[] LEDy = new int [NUMLEDS];


// establecer posiciones


/*
int b_pulseValue = 122;
int b_pulseSpeed = 10;
int b_pulseMin = 0;
int b_pulseMax = 255;

*/

int b_pulseValue = 122;
int b_pulseSpeed = 10;
int b_pulseMin = 0;
int b_pulseMax = 255;




boolean[] fading = new boolean[NUMLEDS];
//boolean fading[NUMLEDS];



int[] b_fadeMod = new int[NUMLEDS];
//int b_fadeMod[NUMLEDS];


int[] b_fadeSteps = new int[NUMLEDS];
//int b_fadeSteps[NUMLEDS];

/*

long[] fadeMs = new long[NUMLEDS];
//long fadeMs[NUMLEDS];

*/

// menos prioritario
int[][] increase = new int[NUMLEDS][3];
//int increase[NUMLEDS][3];



int[][] b_target = new int[NUMLEDS][3];
//byte b_target[NUMLEDS][3];


long lastMillis;
int ellapsed = 0;
/*
int b(int ubyte) {
  if(ubyte>255) { ubyte = 255; }
  return int(ubyte);
}
*/
void setup() {
  setupRangos();
  setupLEDs();
  setPulse( 1, 50, 190 );
  setupProcessing();
  setupArduino();
  setupFades();
  
  test();

}


void draw() {
  fwd();
  showLEDs();
}



void setRango(int i, int pos, int pct ) {

}





void fwd() {
  
  pulse();
  pulses();
  fwdClock();
  fwdFade();
  //setLEDarray();

}


void fwdClock() {
  clock++;
  clock%=32000;  
}  




void setLEDarray() {
  /*for( int i = 0; i < LED.length; i++ ) {
    int r,  g, b;

   

    LED[i][0] = int(r);
    LED[i][1] = int(g);
    LED[i][2] = int(b);
    
  }  
  */
}











// convertir int a int para cambiar arduino x processing!




void showLEDs() {
  for( int i = 0; i < NUMLEDS; i++ ) {

    
    boolean inRange = false;
    float rangePulse = 1;

    for( int j = 0; j < pulseRangeNum; j++ ) {
      if( pong( i,  pulseRangeMin[ j ],  pulseRangeMax[ j ] ) == 1 ) {
        inRange = true;       
        rangePulse = pulseRangeValue[ j ] / float( 255 );
        break;
      }
    }

    float pulse = b_pulseValue / float ( 255 );

    float totalPulse = rangePulse * pulse;

    fill( 
      int( LED[i][0] * totalPulse ) ,
      int( LED[i][1] * totalPulse ), 
      int( LED[i][2] * totalPulse )
    );
    
    noStroke();
    ellipse( LEDx[i], LEDy[i], ELLIPSESIZE, ELLIPSESIZE );
  }  
}



boolean trigger(int mod) {  

  if( clock % mod == 0 ) {
    return true;
  }
  else {
    return false;
  }
}



// funciones para setear valores LED

// individualmente
void setLED( int i, int r, int g, int b ) {

  b_target[i][0] = r;
  b_target[i][1] = g;
  b_target[i][2] = b;

  LED[i][0] = r;
  LED[i][1] = g;
  LED[i][2] = b;
}

// todos los LEDs
void setLEDs( int r, int g, int b ) {
  for( int i = 0; i < NUMLEDS; i++ ) {
    setLED(i,r,g,b);
  }
}




void setPulse(int speed, int min, int max) {
  b_pulseSpeed = speed;
  b_pulseMin = min;
  b_pulseMax = max;
  if( b_pulseValue < min ) b_pulseValue = min;
  if( b_pulseValue < max ) b_pulseValue = max;
}



void pulse() {
  b_pulseValue += b_pulseSpeed;
  b_pulseSpeed *= pong( b_pulseValue, b_pulseMin, b_pulseMax );  
  //println( b_pulseSpeed );
}



void fade( int i, int fadeMod, int r, int g, int b ) {

  fading[i] = true;
  
  b_target[i][0] = r;
  b_target[i][1] = g;
  b_target[i][2] = b;

  if( fadeMod <= 0 ) fadeMod = 1;

  b_fadeMod[i] = fadeMod;
  // Arduino
  /*

  */

/*
  increase[i][0] = ( r - LED[i][0] ) / steps;   
  // println( int( ( LED[i][1] - r )  ) / ms );
  // println(incG);
  increase[i][1] = incG;   
  increase[i][2] = incB;   

  b_fadeSteps[i] = steps;
*/
}





int fadeCounter;
//byte fadeCounter;

int fadeNum = 1;
//byte fadeNum;

void fwdFade() {
  for( int i = 0; i < NUMLEDS; i++ ) {
    if( trigger( b_fadeMod[i] ) ) {
      boolean fadeEnded = true;
      for( int j = 0; j < 3; j++ ) {
        if( b_target[i][j] != LED[i][j] ) {
          fadeEnded = false;

          print("LED" + j + ": ");
          println( LED[i][j] );

          /*
          print("LED:");
          println( LED[i][j] );
          */
          // posible optimizacino metiendo checktarget boolean        
          
          if( b_target[i][j] > LED[i][j] ) {
            LED[i][j] = LED[i][j] + 1;//++;          

          } else {
            LED[i][j]--;
          } 

        }

      }
      if( fadeEnded ) {
        fading[i] = false;

        fadeCounter++;

        fadeCounter %= fadeNum;

      }
    }  


  }
}




/**/


// variables

/*
#define NUMLEDS 3
#define NUMSTRIPS 13

int LED[NUMLEDS][3];


int stripStart[NUMSTRIPS];
int stripEnd[NUMSTRIPS];


int b_rangoPos[NUMSTRIPS];
int b_rangoPct[NUMSTRIPS];

int b_pulseVar[NUMLEDS];


boolean fading[NUMLEDS];
int b_fadeMod[NUMLEDS];
int b_fadeSteps[NUMLEDS];
int increase[NUMLEDS][3];

byte b_target[NUMLEDS][3];

*/

int NUMLEDS = 400;
int NUMSTRIPS = 13;
int ELLIPSESIZE  = 10;






int clock = 0;




//int LEDx[NUMLEDS];
//int LEDy[NUMLEDS];


// solo en processing:
int[][] LED = new int[NUMLEDS][3];


int[] stripStart = new int[NUMSTRIPS];
int[] stripEnd = new int[NUMSTRIPS];


int[] b_rangoPos = new int[NUMSTRIPS];
int[] b_rangoPct = new int[NUMSTRIPS];

int[] b_pulseVar = new int[NUMLEDS];

boolean[] fading = new boolean[NUMLEDS];
int[] b_fadeMod = new int[NUMLEDS];
int[] b_fadeSteps = new int[NUMLEDS];
int[][] increase = new int[NUMLEDS][3];
int[][] b_target = new int[NUMLEDS][3];

int[] LEDx = new int [NUMLEDS];
int[] LEDy = new int [NUMLEDS];


// establecer posiciones



int b_pulseValue = 122;
int b_pulseSpeed = 10;
int b_pulseMin = 0;
int b_pulseMax = 255;

long lastMillis;
int ellapsed = 0;


void setup() {
  setupRangos();
  setupLEDs();
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


  // animaciones
  if( filling ) {
    fill();
  }

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
      int( LED[i][0] * totalPulse * generalBrightness ) ,
      int( LED[i][1] * totalPulse * generalBrightness ), 
      int( LED[i][2] * totalPulse * generalBrightness )
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


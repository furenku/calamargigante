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


int[] LEDx = new int [NUMLEDS];
int[] LEDy = new int [NUMLEDS];


// establecer posiciones



int b_pulseValue = 255;
int b_pulseSpeed = 0;
int b_pulseMin = 255;
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
  if( b_pulseSpeed > 0) {
    b_pulseValue += b_pulseSpeed;
    b_pulseSpeed *= pong( b_pulseValue, b_pulseMin, b_pulseMax );  
  }
}




/**/


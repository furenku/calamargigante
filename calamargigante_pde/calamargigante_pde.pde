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




boolean filling = false;


int clock = 0;

float generalBrightness = 1;


// solo en processing:

int NUMLEDS = 400;
int NUMSTRIPS = 13;
int ELLIPSESIZE  = 10;







//int LEDx[NUMLEDS];
//int LEDy[NUMLEDS];


int[][] LED = new int[NUMLEDS][3];
int[][] drawLED = new int[NUMLEDS][3];


int[] stripStart = new int[NUMSTRIPS];
int[] stripEnd = new int[NUMSTRIPS];


int[] b_rangoPos = new int[NUMSTRIPS];
int[] b_rangoPct = new int[NUMSTRIPS];



int[] LEDx = new int [NUMLEDS];
int[] LEDy = new int [NUMLEDS];


// establecer posiciones



//long lastMillis;
//int ellapsed = 0;


void setup() {
  setupRangos();
  setupLEDs();
  setupProcessing();
  setupArduino();
  setupFades();
  

  setupSerial();


  test();

  serial.start();

}

void loop() {
  fwd();
  showLEDs();

  //writeSerial();
}
void draw() {
  fwd();


  thread("setLEDdraw");
  //writeSerial();

  //randomRGBarray();
  //thread( "drawLEDs" );
  thread("drawLEDs");
  //writeSerial();
  /*
  writeSerial();
  
*/
//thread( "writeSerial" );
  //println(frameRate);

  
readSerial();

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

  holdFwd();

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



void setLEDdraw() {
  for( int i = 0; i < NUMLEDS; i++ ) {

    float rangePulse = getRangePulse(i);
    
    float pulse = b_pulseValue / float ( 255 );

    float totalPulse = rangePulse * pulse;
        
    drawLED[i][0] = int( LED[i][0] * totalPulse * generalBrightness );
    drawLED[i][1] = int( LED[i][1] * totalPulse * generalBrightness );
    drawLED[i][2] = int( LED[i][2] * totalPulse * generalBrightness );
    if( drawLED[i][0] == 65 ) drawLED[i][0] = 66;
    if( drawLED[i][1] == 65 ) drawLED[i][1] = 66;
    if( drawLED[i][2] == 65 ) drawLED[i][2] = 66;
          
  }

}



void drawLEDs() {
  for( int i = 0; i < NUMLEDS; i++ ) {
          
    fill( 
      drawLED[i][0],
      drawLED[i][1],
      drawLED[i][2]
    );
    
    noStroke();
    ellipse( LEDx[i], LEDy[i], ELLIPSESIZE, ELLIPSESIZE );
  }  
}



void showLEDs() {
  for( int i = 0; i < NUMLEDS; i++ ) {

    float rangePulse = getRangePulse(i);
    
    float pulse = b_pulseValue / float ( 255 );

    float totalPulse = rangePulse * pulse;
    /*
    fill( 
      int( LED[i][0] * totalPulse * generalBrightness ) ,
      int( LED[i][1] * totalPulse * generalBrightness ), 
      int( LED[i][2] * totalPulse * generalBrightness )
    );
    
    noStroke();
    ellipse( LEDx[i], LEDy[i], ELLIPSESIZE, ELLIPSESIZE );
    */
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







/**/


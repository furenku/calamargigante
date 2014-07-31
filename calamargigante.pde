// variables

int NUMLEDS = 400;
int NUMSTRIPS = 13;
int ELLIPSESIZE  = 10;

float[] rangoPos = new float[NUMSTRIPS];
//float rangoPos[NUMSTRIPS];
float[] rangoPct = new float[NUMSTRIPS];
//float rangoPct[NUMSTRIPS];




//int LED[NUMLEDS];
int clock = 0;

int[][] LED = new int[NUMLEDS][3];

//float pulseVar[NUMLEDS];
float[] pulseVar = new float[NUMLEDS];


//int LEDx[NUMLEDS];
//int LEDy[NUMLEDS];

int[] LEDx = new int [NUMLEDS];
int[] LEDy = new int [NUMLEDS];


// establecer posiciones


float pulseValue = 0.5;
float pulseSpeed = 0.1;
float pulseMin = 0;
float pulseMax = 1;




boolean[] fading = new boolean[NUMLEDS];
//boolean fading[NUMLEDS];

long[] fadeMs = new long[NUMLEDS];
//long fadeMs[NUMLEDS];

float[][] increase = new float[NUMLEDS][3];
//float increase[NUMLEDS][3];


long lastMillis;
int ellapsed = 0;


void setup() {
  size(800,800);
  setupRangos();
  setupLEDs();
  setPulse( 0.01, 0.1,0.6 );
}


void setRango(int i, float pos, float pct ) {

}


void setupRangos() {

  rangoPos[0] = 0;
  rangoPct[0] = 0.40;
  rangoPos[1] = 0;
  rangoPct[1] = 0.40;


  rangoPos[2] = 0.45;
  rangoPct[2] = 0.1;
  rangoPos[3] = 0.45;
  rangoPct[3] = 0.1;

  rangoPos[4] = 0.40;
  rangoPct[5] = 0.15;
  rangoPos[5] = 0.40;
  rangoPct[5] = 0.15;

  rangoPos[6] = 0.55;
  rangoPct[6] = 0.05;


  rangoPos[7] = 0.60;
  rangoPct[7] = 0.40;

  rangoPos[8] = 0.60;
  rangoPct[8] = 0.30;
  rangoPos[9] = 0.60;
  rangoPct[9] = 0.35;


  rangoPos[10] = 0.60;
  rangoPct[10] = 0.40;

  rangoPos[11] = 0.60;
  rangoPct[11] = 0.30;
  rangoPos[12] = 0.60;
  rangoPct[12] = 0.35;

 
}


void setupLEDs(){

// pulseVar en 1



  // 1 cola1
  // 69 cola2
  // 136 ojo1
  // 139 ojo2
  // 142 cabeza1
  // 166 cabeza2
  // 193 cabeza3
  // 201 pata1
  // 227 pata2
  // 257 pata3
  // 308 pata4
  // ? pata5
  // ? pata6

    // cola 1
  setupStrip( 0, 250, 50, 68, 0, -1, 3);
  // cola 2
  setupStrip( 1, 400, 50, 67, 68, 1, 3);

    // ojo 1
  setupStrip( 2, 290, 250, 3, 135, -10, 0);
  // ojo 2
  setupStrip( 3, 360, 250, 3, 138, 10, 0);

  // cabeza 1
  setupStrip( 4, 225, 200, 24, 141, 2, 5);
  // cabeza 2
  setupStrip( 5, 425, 200, 27, 165, -2, 5);
  // cabeza 3
  setupStrip( 6, 290, 320, 8, 192, 10, 0);
  
  // tentaculo 1
  setupStrip( 7, 200, 350, 26, 200, 0, 6);
  
  //brazo 1
  setupStrip( 8, 230, 350, 30, 226, 0, 6);
  
  //brazo 2
  setupStrip( 9, 260, 350, 51, 256, 0, 6);

  // tentaculo 2
  setupStrip( 7, 350, 350, 20, 307, 0, 6);
  
  //brazo 3
  setupStrip( 8, 380, 350, 24, 327, 0, 6);
  
  //brazo 4
  setupStrip( 9, 410, 350, 47, 351, 0, 6);

/*
  


  // brazo 1
  setupStrip( x, x, 10, 0);
  // brazo 2
  setupStrip( x, x, 10, 0);

  // tentaculo largo 2
  setupStrip( x, x, 10, 0);
  // brazo 3
  setupStrip( x, x, 10, 0);
  // brazo 4
  setupStrip( x, x, 10, 0);

  */

  setLEDs(0,0,0);

}


// funciones para setear valores LED

// individualmente
void setLED( int i, int r, int g, int b ) {
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




void setupStrip( int i, int offsetX, int offsetY, int numLeds, int offsetI, int addX, int addY ) {
  /*
  stripOffsetX[i] = offsetX; 
  stripOffsetY[i] = offsetY;
  */
  for( int j = 0; j < numLeds; j++ ) {
    LEDx[j+offsetI] = offsetX + j*addX;
    LEDy[j+offsetI] = offsetY + j*addY;
  }
}



boolean disparar(int mod) {  
  if( clock % mod == 0 ) {
    return true;
  }
  else {
    return false;
  }
}

void fwd() {
  ellapsed = int( millis() - lastMillis );
  lastMillis = millis();
  pulse();
  fwdclock();
  fwdFade();
  setLEDarray();

}


void fwdclock() {
  clock++;
  clock%=32000;  
}  


void draw() {
  fwd();
  showLEDs();
}


void setLEDarray() {
  for( int i = 0; i < LED.length; i++ ) {
    int r, g, b;

    r = 255;
    g = 0;
    b = 55;

    LED[i][0] = int(r * pulseValue);
    LED[i][1] = int(g * pulseValue);
    LED[i][2] = int(b * pulseValue);
    
  }  
}


void setPulse(float speed, float min, float max) {
  pulseSpeed = speed;
  pulseMin = min;
  pulseMax = max;
  if( pulseValue < min ) pulseValue = min;
  if( pulseValue < max ) pulseValue = max;
}


void pulse() {
  pulseValue += pulseSpeed;
  if( pulseValue > pulseMax || pulseValue <= pulseMin  ) pulseSpeed *= -1;
  
  println( pulseSpeed );
}

void showLEDs() {
  for( int i = 0; i < NUMLEDS; i++ ) {
    fill( LED[i][0],LED[i][1],LED[i][2] );
    noStroke();
    ellipse( LEDx[i], LEDy[i], ELLIPSESIZE, ELLIPSESIZE );
  }  
}





void fade( int i, long ms, int r, int g, int b ) {
  
  float incR = 0.01;
  float incG = 0.05;
  float incB = 0.02;

  increase[i][0] = incR;   
  increase[i][1] = incG;   
  increase[i][2] = incB;   

}

void fwdFade() {

  for( int i = 0; i < NUMLEDS; i++ ) {
    fadeMs[i] -= ellapsed;
    if( fadeMs[i] <= 0 ) {

    } else {

        LED[i][0] += ellapsed * ( 255 * increase[i][0] );
        LED[i][1] += ellapsed * ( 255 * increase[i][1] );
        LED[i][2] += ellapsed * ( 255 * increase[i][2] );

    }
  }  
}

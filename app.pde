// variables 
int NUMLEDS = 400;

//byte LED[NUMLEDS];

byte[] LED = new byte[NUMLEDS];

//float pulseVar[NUMLEDS];
float[] pulseVar = new float[NUMLEDS];

float pulseValue = 1;

//int LEDx[NUMLEDS];
//int LEDy[NUMLEDS];

int[] LEDx = new int [NUMLEDS];
int[] LEDy = new int [NUMLEDS];


// establecer posiciones

int ELLIPSESIZE  = 10;

int NUMSTRIPS = 12;
/*
int stripOffsetX[NUMSTRIPS];
int stripOffsetY[NUMSTRIPS];
*/

void setup() {
	size(800,800);
	setupLEDs();

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
/*

// medidas (cantidades de led)

// trazar lineas

// calcular sitios de puntos




int leds[400] {


}


setupPulse( numLeds, addX, addY ) {



}




// funciones para setear valores LED

// individualmente
setLED( int i, byte r, byte g, byte b ) {
	LED[i][0] = r;
	LED[i][1] = g;
	LED[i][2] = b;
}

// todos los LEDs
setLEDs( byte r, byte g, byte b ) {
	for( int i = 0; i < NUMLEDS; i++ ) {
		LED[i][0] = r;
		LED[i][0] = g;
		LED[i][2] = b;
	}	
}


// transicionar

// obtener valor de transicion 

startTransition( startVal, endVal, time )

startTransition( startValArr, endValArr, time )

getTransitionValue()


// funciona para animar

animate() {

fwd()

setPulseValue



showLEDs() {


	LED[i] * ( pulsevalue * pulseVar[i] )


}


// funcion para calcular transiciones 


fwd(){

}


// funcion para mostrar elds

showLEDs() {}


// setPulseValue () {
	
	// get pulse moment
	// set general brightness

}




// secuencia

// 1 

startFade(){}




*/

void draw() {

	elipses();


}



void elipses() {

	for( int i = 0; i < LEDx.length; i++ ) {
		ellipse( LEDx[i], LEDy[i], ELLIPSESIZE, ELLIPSESIZE );
	}	
}
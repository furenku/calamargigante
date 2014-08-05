// LEDS:
#include <Adafruit_NeoPixel.h>

#define PIN 8
#define NUMLEDS 400
#define NUMSTRIPS 13


Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMLEDS, PIN, NEO_RGB + NEO_KHZ400);


int stripStart[NUMSTRIPS];
int stripEnd[NUMSTRIPS];
int b_rangoPos[NUMSTRIPS];
int b_rangoPct[NUMSTRIPS];


uint32_t leds[NUMLEDS+1];
uint32_t rgb;


//RGB:

#define RED       5// pin for red LED
#define GREEN    6 // pin for green - never explicitly referenced
#define BLUE     7 // pin for blue - never explicitly referenced
#define SIZE    255
#define DELAY    20
#define HUE_MAX  6.0
#define HUE_DELTA 0.01





/*
chosen LED SparkFun sku: COM-09264
 has Max Luminosity (RGB): (2800, 6500, 1200)mcd
 so we normalize them all to 1200 mcd -
 R  250/600  =  107/256
 G  250/950  =   67/256
 B  250/250  =  256/256
 */
//long bright[3] = { 256, 256, 256};
//long bright[3] = { 256, 256, 256};

long k, temp_value;



// state logic:
#define NUMCUES 7
int cue = 0;
int digits[3];
int incomingByte = 0;


// secuencia

int counter = 0;
int clock = 0;

// logica animaciones

bool pulsating = true;
int r, g, b;
bool fading = false;

float pulseVal=1;
byte bpulseVal, pulseSpeed,pulseMin,pulseMax,pulseAccMin, pulseAccMax, pulseAcc;





void setup() {
  setupSerial();  
  setupStrip();
  
  test();
  
}

void loop() {
  readSerial();
  fwd();
  showLeds();
  showRGB();
}

void fwd() {
  fwdClock();
  fwdFade();
  fwdPulse();
}

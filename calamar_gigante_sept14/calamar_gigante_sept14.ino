#include <Adafruit_NeoPixel.h>

#define STARTCUE 2

#define PIN 8
#define NUMLEDS 400
#define NUMSTRIPS 13

#define NUMFADES 13
#define NUMPULSES 13

#define NUMCUES 42

// HSV fade/bounce for Arduino - scruss.com - 2010/09/12
// Note that there's some legacy code left in here which seems to do nothing
// but should do no harm ...

// don't futz with these, illicit sums later
#define RED       5// pin for red LED
#define GREEN    6 // pin for green - never explicitly referenced
#define BLUE     7 // pin for blue - never explicitly referenced
#define SIZE    255
#define DELAY    20
#define HUE_MAX  6.0
#define HUE_DELTA 0.01


#define NUMBER_OF_SHIFT_CHIPS   1
#define DATA_WIDTH   NUMBER_OF_SHIFT_CHIPS * 8
#define PULSE_WIDTH_USEC   1
#define POLL_DELAY_MSEC   1
#define BYTES_VAL_T unsigned int


//byte generalBrightness = 255;

int cue = STARTCUE;

int digits[3];
int incomingByte = 0;


// secuencia

int counter = 0;
int clock = 0;

// logica animaciones

bool pulsating = true;
int r, g, b;
bool fading = false;
boolean inStatic = false;


float pulseVal[NUMPULSES];
byte bpulseVal[NUMPULSES], pulseMod[NUMPULSES], pulseMin[NUMPULSES], pulseMax[NUMPULSES], pulseAccMin[NUMPULSES], pulseAccMax[NUMPULSES], pulseType[NUMPULSES];
int pulseAcc[NUMPULSES], pulseSpeed[NUMPULSES];
int pulseRangeStart[NUMPULSES], pulseRangeEnd[NUMPULSES];
boolean pulseSet[NUMPULSES];


//long deltas[3] = { 5, 6, 7 };
uint32_t rgb;

// for reasons unknown, if value !=0, the LED doesn't light. Hmm ...
// and saturation seems to be inverted
float hue=0.0, saturation=1, value=1;


uint32_t leds[NUMLEDS];
uint32_t tmpLeds[NUMLEDS];
boolean updated[NUMLEDS];



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


Adafruit_NeoPixel strip = Adafruit_NeoPixel(400, PIN, NEO_RGB + NEO_KHZ400);

int rgbcnt[3];

#define NUMCHOSEN 40
int chosen[ NUMCHOSEN ];



int stripStart[NUMSTRIPS];
int stripEnd[NUMSTRIPS];
int b_rangoPos[NUMSTRIPS];
int b_rangoPct[NUMSTRIPS];






// colores

float brightness = 1;


uint32_t negro = strip.Color( 0,0,0);
uint32_t blanco = strip.Color( 50,50,50);
uint32_t fiuscha = strip.Color(255,0,255);
uint32_t aquamarina = strip.Color(0,185,185);  
uint32_t rosado = strip.Color(255,0,128);  
uint32_t azulrey = strip.Color(0,0,204);
uint32_t azuloscuro = strip.Color(0,0,80);
uint32_t azulindigo = strip.Color(50,0,255);
uint32_t rojo = strip.Color(255,0,0);
uint32_t violeta = strip.Color(115,0,230);
uint32_t azulcielo = strip.Color(0,128,255);





void setup() {
  strip.begin();
  strip.show(); 
  
  
  //setupShiftRegisters();
  pinMode(4, OUTPUT);

  setupSerial();
  /*
  for(int i=0; i< 40; i++ ) {
   int newval = random(NUMLEDS);
   bool rand_exists = false;
   
    for(int j = 0; j<i; j++) {
      if( newval == chosen[j] ) {
        rand_exists = true;
        break;
      }
    }
    chosen[i]

  }
  */
  /*

  
  rgbcnt[0] = rgbcnt[1] = rgbcnt[2] = 0;
  
  randomSeed(analogRead(4));
  for (k=0; k<3; k++) {
    pinMode(RED + k, OUTPUT);
    rgb[k]=0;
    analogWrite(RED + k, rgb[k] * bright[k]/256);
  }
  
  
  for(int i = 0; i < NUMLEDS; i++) {
    for(int j = 0; j < 3; j++) {
      leds[i][j] = rgbcnt[j];
    }
  }
  */
  
  
  //count();
  setupStrips();
  setupBodySeqStrips();

  changeCue(STARTCUE);
}


bool pulse = true;

int tstcounter=0;




int cntt=0;
void loop() {
  if(trigger( 5 )){
 cntt++;
 cntt%=255;
  }
  readSerial();
  //seq();
//drawStatic( cntt);
//  white();
//  setLeds( negro );
    
  fwd();
/*
  for(int i=stripStart[2]; i< stripEnd[3]; i++) {
      setLed( i, aquamarina );
      Serial.println(i);
  }
  */
  //white();
  //danceAround( strip.Color(255,255,255) ) ;
//seqUpdate();
seq();
showLeds();
        setRGB(aquamarina);

//showRGB();
}

/*
// color fijo
// pulsando entre colores
// segmentos
// fragmentos
// vectores
// centro afuera
// gradientes
// bandas
// expandir contraer bandas
// lluvia
// llamas
// cambio random
// scatter
*/


int numSteps = 0;
long fadeStartMs = 0;


byte sourceRGB[NUMLEDS][3];
byte deltaRGB[NUMLEDS][3];

void fade( int rango[], uint32_t targetColor, float tiempo ) {
  
// calcular numero de ms

  fadeStartMs = millis();
// obtener valores rgb para cada nuevo color

byte targetR, targetG, targetB;

targetR = getR( targetColor ); 
targetG = getG( targetColor ); 
targetB = getB( targetColor ); 

// iterar x todos los leds
 for (uint16_t i = 0; i < NUMLEDS; i++ ) {
   uint32_t c = leds[i];
   // obtener valores rgb para cada led
   byte lR = getR(c);
   byte lG = getG(c);
   byte lB = getB(c);

   sourceRGB[i][0] = lR;
   sourceRGB[i][1] = lG;
   sourceRGB[i][2] = lB;
   
   // calcular diferencia en r g y b para cada led
   deltaRGB[i][0] = targetR - lR;
   deltaRGB[i][1] = targetG - lG;
   deltaRGB[i][2] = targetB - lB;
   
 }
// almacenar dicha diferencia

// indicar que debe iniciar la animacion
fading = true;

// iterar

// - almacenar nuevo valor

// get step from rgb



}

void doFade() {
  /*
  // obtener tiempo transcurrido desde que inicio el fade
  // establecer porcentaje de cambio para este momento
  // calcualr nuevos valores r g b
  msLeft--;
  if(msLeft==0) { 
    // concluir animacion fading = false;
  } else {
    // iterar por todos los leds
    // aplicar diferencia cuantizada
  }
  */
}


void fadeColor( int rango[], uint32_t color, float tiempo ) {}

/*
void pulsar( led, val1, time1, val2, time2 ) {

  fade(led,val1,time1);
  fade(led,val2,time2);

}
*/


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delayMicroseconds(wait*2);

  }
}


void rainbow(int wait) {
  
  if( clock%wait == 0 )  {
      for (int i = 0; i < NUMLEDS; i++) {
        setLed(i, Wheel((i + clock%256) & 255));
      }
  }
}

void oldRrainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
/*
//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}
*/
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return strip.Color(WheelPos * 3, 125 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 125 - WheelPos * 3);
  }
}






uint32_t fiuscha = strip.Color(255,0,255);
uint32_t aquamarina = strip.Color(0,255,255);  
uint32_t rosado = strip.Color(0,255,128);  
uint32_t azulrey = strip.Color(0,0,204);
uint32_t verdeamarillo = strip.Color(120,200,0);

uint32_t rojo = strip.Color(255,0,0);
uint32_t violeta = strip.Color(115,0,230);
uint32_t azulcielo = strip.Color(0,128,255);
uint32_t morado = strip.Color(170,0,190);
uint32_t lila = strip.Color(210,50,190);



void white() {  
  uint32_t c = strip.Color(150,150,150);
  setLeds(c); 
}



void black() {  
  uint32_t c = strip.Color(0,0,0);
  setLeds(c); 
}


void red() {  
  uint32_t c = strip.Color(255,0,0);
  setLeds(c); 
}


void green() {  
  uint32_t c = strip.Color(0,255,0);
  setLeds(c); 
}


void blue() {  
  uint32_t c = strip.Color(0,0,255);
  setLeds(c); 
}



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




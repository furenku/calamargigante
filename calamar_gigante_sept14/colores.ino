
uint32_t blanco = strip.Color(255,255,255);
uint32_t fiuscha = strip.Color(255,0,255);
uint32_t aquamarina = strip.Color(0,255,255);  
uint32_t rosado = strip.Color(0,255,128);  
uint32_t azulrey = strip.Color(0,0,204);
uint32_t rojo = strip.Color(255,0,0);
uint32_t violeta = strip.Color(115,0,230);
uint32_t azulcielo = strip.Color(0,128,255);

uint32_t white() {  
  uint32_t c = strip.Color(255,255,255);
  return c;
}


uint32_t black() {  
  uint32_t c = strip.Color(0,0,0);
  return c; 
}


uint32_t red() {  
  uint32_t c = strip.Color(255,0,0);
  return c; 
}


uint32_t green() {  
  uint32_t c = strip.Color(0,255,0);
  return c; 
}

uint32_t blue() {  
  uint32_t c = strip.Color(0,0,255);
  return c; 
}



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

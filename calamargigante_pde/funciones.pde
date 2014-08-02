/*
uint32_t Color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

byte getR(uint32_t pixel){
  byte c = (pixel >> 16) & 0xFF;
  return c;
}

byte getG(uint32_t pixel){
  byte c = (pixel >> 8) & 0xFF;
  return c;
}

byte getB(uint32_t pixel){
  byte c = (pixel >> 0) & 0xFF;
  return c;
}

*/
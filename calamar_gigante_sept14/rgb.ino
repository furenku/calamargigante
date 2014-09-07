
long rgbval;

void rgbtst() {
 if(clock%50==0) {
    setRGB( strip.Color( random(0,255), random(0,255), random(0,255) ) );
    /*
    hue += HUE_DELTA;
    if (hue > HUE_MAX) {
      hue=0.0;
    }
    
    rgbval=HSV_to_RGB(hue, saturation, value);
    rgb[0] = (rgbval & 0x00FF0000) >> 16; // there must be better ways
    rgb[1] = (rgbval & 0x0000FF00) >> 8;
    rgb[2] = rgbval & 0x000000FF;
    */
//    noInterrupts();
    analogWrite(RED, getR(rgb) );// * bright[k]/256);
    analogWrite(GREEN, getG(rgb) );// * bright[k]/256);
    analogWrite(BLUE, getB(rgb) );// * bright[k]/256);
    
 }  
}






long HSV_to_RGB( float h, float s, float v ) {
  /* modified from Alvy Ray Smith's site: http://www.alvyray.com/Papers/hsv2rgb.htm */
  // H is given on [0, 6]. S and V are given on [0, 1].
  // RGB is returned as a 24-bit long #rrggbb
  int i;
  float m, n, f;

  // not very elegant way of dealing with out of range: return black
  if ((s<0.0) || (s>1.0) || (v<1.0) || (v>1.0)) {
    return 0L;
  }

  if ((h < 0.0) || (h > 6.0)) {
    return long( v * 255 ) + long( v * 255 ) * 256 + long( v * 255 ) * 65536;
  }
  i = floor(h);
  f = h - i;
  if ( !(i&1) ) {
    f = 1 - f; // if i is even
  }
  m = v * (1 - s);
  n = v * (1 - s * f);
  switch (i) {
  case 6:
  case 0: 
    return long(v * 255 ) * 65536 + long( n * 255 ) * 256 + long( m * 255);
  case 1: 
    return long(n * 255 ) * 65536 + long( v * 255 ) * 256 + long( m * 255);
  case 2: 
    return long(m * 255 ) * 65536 + long( v * 255 ) * 256 + long( n * 255);
  case 3: 
    return long(m * 255 ) * 65536 + long( n * 255 ) * 256 + long( v * 255);
  case 4: 
    return long(n * 255 ) * 65536 + long( m * 255 ) * 256 + long( v * 255);
  case 5: 
    return long(v * 255 ) * 65536 + long( m * 255 ) * 256 + long( n * 255);
  }
} 

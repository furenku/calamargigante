int digits[3];
int lastDigit = -1;
int lastEllapsed = 0;

bool useDigit = true;


void digit ( int i ) {
  
  useDigit = false;

  //if( i == lastDigit ) {
    int ellapsed = millis() - lastEllapsed;
      //Serial.print( "ellapsed: ");
      //Serial.println( ellapsed);
      if( ellapsed > 300 ) {
        useDigit = true;
      }

      lastEllapsed = millis();        
  /*} else {
    useDigit = true;
  }

  lastDigit = i;
  */
  if( useDigit ) {
 // Serial.print("DIGIT:");
 // Serial.println( i );

       if( !settingDigits ) {
        digits[0] = 0;
        digits[1] = 0;
        digits[2] = i;
        useDigit = false;
        
       } else {
        digits[0] = digits[1];
        digits[1] = digits[2];
        digits[2] = i;
       
       }
        settingDigits = true;

  }
        
}

void previous() { /*Serial.println("PREV!");*/ cue--; roundCue(); }

void next() {  /*Serial.println("next!"); */ cue++; roundCue(); }

void roundCue() {
  if( cue < 0 ) { cue = NUMCUES - 1; }
  if( cue >= NUMCUES ) { cue = 0; }
  
  Serial.print( cue );
  Serial.print( "." );
}

void limitCue() {
  if( cue < 0 ) { cue = 0; }
  if( cue >= NUMCUES ) { cue = NUMCUES - 1; }
}

void go() {  
  
      settingDigits = false;
  /*
      int ellapsed = millis() - lastEllapsed;
      lastEllapsed = millis();
*/
      //Serial.print( "ellapsed: ");
      //Serial.println( ellapsed);
      //if( ellapsed > 200 ) {
      int result = ( digits[0] * 100 ) + ( digits[1] * 10 ) + digits[2];
      
      cue = max( result - 1, 0 );
      
      // Serial.print("go: ");
      Serial.print( cue );
      Serial.print( "." );
      
      limitCue();
      
      digits[0] = digits[1] = digits[2] = 0;
      
      //}
      
   // lastEllapsed = millis();
}

/*
i == 9 
& 1
digit( 1 );

i == 8 
& 1
digit( 2 );

i == 10 
& 1
digit( 3 );

i == 13 
& 1
digit( 4 );

i == 12 
& 1
digit( 5 );

i == 11 
& 1
digit( 6 );

i == 14 
& 1
digit( 7 );

i == 15 
& 1
digit( 8 );


i == 0 
& 1
digit( 9 );

i == 1 
& 1
digit( 0 );

i == 6 
& 0
go();

i == 7 
& 0
previous();

i == 8 
& 0
next();

*/

void setupSerial() {

        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        for(int i; i<3; i++ ) {
          digits[i] = 0;
        }
      
}


void readSerial() {

// send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                // say what you got:
                int digit = incomingByte-48;
                
                if( digit >= 0 && digit < 9 ) {
                  digits[0] = digits[1];
                  digits[1] = digits[2];
                  digits[2] = digit;                  
                } 

                if( incomingByte - 46 == 0 ) {

                  int result =
                    digits[0] * 100 +
                    digits[1] * 10 +
                    digits[2];
                    
                  cue = result;
                  changeCue( cue );
                  Serial.print( "CUE: " );
                  Serial.println( cue );  
                  //changeCue( cue );
                  digits[0] = digits[1] = digits[2] = 0;
                }
       
              
                
                

                
        }
        
        
}


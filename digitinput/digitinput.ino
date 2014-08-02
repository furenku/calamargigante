
int incomingByte = 0;   // for incoming serial data

int digits[3];
void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        for(int i; i<3; i++ ) {
          digits[i] = 0;
        }
}

int state = 0;

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
Serial.println(incomingByte, DEC);
                // say what you got:
                int digit = incomingByte-48;
                
                if( digit >= 0 && digit < 9 ) {
                  digits[0] = digits[1];
                  digits[1] = digits[2];
                  digits[2] = digit;
                  
                  Serial.print("digit");
                  Serial.println( digit );

                } 

                if( incomingByte - 46 == 0 ) {
                  Serial.println(incomingByte - 46);

                  int result =
                    digits[0] * 100 +
                    digits[1] * 10 +
                    digits[2];
                    
                  state = result;

                  digits[0] = digits[1] = digits[2] = 0;
                }
       
              
                
                

                
        }
        
        
        Serial.print( "state: " );
        Serial.println( state );
        
}


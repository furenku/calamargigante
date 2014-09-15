/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;


int digits[3];

int incomingByte = 0;

int num = 10;

byte bytesRead=0;
void readSerial() {

  if (Serial.available() > 0) {
      Serial.print( "in: " );

    incomingByte = Serial.read();

    int digit = incomingByte-48;
    bytesRead++;
    
    if( digit >= 0 && digit <= 9 ) {
      digits[0] = digits[1];
      digits[1] = digits[2];
      digits[2] = digit;                  
    } 

    if( incomingByte - 46 == 0 ) {

      int result =
        digits[0] * 100 +
        digits[1] * 10 +
        digits[2];
      num = result;  
      Serial.print( "CUE: " );
      Serial.println( result );  
      //changeCue( cue );
      digits[0] = digits[1] = digits[2] = 0;
    }
 

  
    

          
  } 
        
        
}



// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  
  digits[0] = digits[1] = digits[2] = 0;
            
  bytesRead = 0;
          
          
}
int cnt=0,cnt2=0;
// the loop routine runs over and over again forever:
void loop() {
  readSerial();
  cnt++;
  cnt%=255;
  if(cnt%num==0) cnt2++;
  cnt2%=255;
  if(cnt2<125)
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  else 
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  //delay(1);
}

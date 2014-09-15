/* How many shift register chips are daisy-chained.
*/
#define NUMCUES 40
#define NUMBER_OF_SHIFT_CHIPS   2

/* Width of data (how many ext lines).
*/

#define DATA_WIDTH   NUMBER_OF_SHIFT_CHIPS * 8

/* Width of pulse to trigger the shift register to read and latch.
*/
#define PULSE_WIDTH_USEC   5

/* Optional delay between shift register reads.
*/
#define POLL_DELAY_MSEC   1

/* You will need to change the "int" to "long" If the
 * NUMBER_OF_SHIFT_CHIPS is higher than 2.
*/
#define BYTES_VAL_T unsigned int

int ploadPin        = 8;  // Connects to Parallel load pin the 165
int clockEnablePin  = 9;  // Connects to Clock Enable pin the 165
int dataPin         = 11; // Connects to the Q7 pin the 165
int clockPin        = 12; // Connects to the Clock pin the 165



    const int  g_pinCommLatch = 6;
    const int  g_pinClock     = 7;
    const int  g_pinData    = 5;

byte g_digits [11] = 
    {
      B10000001, //0
      B10110111, //1
      B11000010, //2
      B10010010, //3
      B10110100, //4
      B10011000, //5
      B10001000, //6
      B10110011, //7
      B10000000, //8
      B10110000, //9
      B11111111  // vacio
    };
    
    int g_numberToDisplay = 888;

    // Number of shift registers in use
    const int g_registers = 3;

    // Array of numbers to pass to shift registers
    byte g_registerArray [g_registers];

    int cc;

int cue = 0;


BYTES_VAL_T pinValues;
BYTES_VAL_T oldPinValues;

/* This function is essentially a "shift-in" routine reading the
 * serial Data from the shift register chips and representing
 * the state of those pins in an unsigned integer (or long).
*/
BYTES_VAL_T read_shift_regs()
{
    long bitVal;
    BYTES_VAL_T bytesVal = 0;

    /* Trigger a parallel Load to latch the state of the data lines,
    */
    digitalWrite(clockEnablePin, HIGH);
    digitalWrite(ploadPin, LOW);
    delayMicroseconds(PULSE_WIDTH_USEC);
    digitalWrite(ploadPin, HIGH);
    digitalWrite(clockEnablePin, LOW);

    /* Loop to read each bit value from the serial out line
     * of the SN74HC165N.
    */
    for(int i = 0; i < DATA_WIDTH; i++)
    {
        bitVal = digitalRead(dataPin);

        /* Set the corresponding bit in bytesVal.
        */
        bytesVal |= (bitVal << ((DATA_WIDTH-1) - i));

        /* Pulse the Clock (rising edge shifts the next bit).
        */
        digitalWrite(clockPin, HIGH);
        delayMicroseconds(PULSE_WIDTH_USEC);
        digitalWrite(clockPin, LOW);
    }

    return(bytesVal);
}







void display_pin_values()
{
//    Serial.println(" Pins: ");

    for(int i = 0; i < DATA_WIDTH; i++)
    {
if( ( pinValues >> i ) & HIGH ) {
  
  
    if( i == 9 )
    digit( 1 );
    
    if( i == 8 )
    digit( 2 );
    
    if( i == 10 )
    digit( 3 );
    
    if( i == 13 )
    digit( 4 );
    
    if( i == 12 )
    digit( 5 );
    
    if( i == 11 )
    digit( 6 );
    
    if( i == 14 )
    digit( 7 );
    
    if( i == 15 )
    digit( 8 );
       
    if( i == 0 )
    digit( 9 );
    
    if( i == 1 )
    digit( 0 );

} else {
	
    if( i == 2 )
        go();
        
    if( i == 7 )
        previous();
        
    if( i == 3 )
        next();

}
    }

}

bool settingDigits = false;
void setup()
{
    Serial.begin(9600);

    /* Initialize our digital pins...
    */
    pinMode(ploadPin, OUTPUT);
    pinMode(clockEnablePin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT);


      pinMode (g_pinCommLatch, OUTPUT);
      pinMode (g_pinClock, OUTPUT);
      pinMode (g_pinData, OUTPUT);
      cc = 0;
      
      
    digitalWrite(clockPin, LOW);
    digitalWrite(ploadPin, HIGH);

    /* Read in and display the pin states at startup.
    */
    pinValues = read_shift_regs();
    display_pin_values();
    oldPinValues = pinValues;
    
    
    //Serial.println( "REINIT" );
}

byte counter = 0;
void loop()
{
  counter++;
  counter%=255;
  
    /* Read the state of all zones.
    */
    pinValues = read_shift_regs();

    /* If there was a chage in state, display which ones changed.
    */
    if(pinValues != oldPinValues)
    {
        display_pin_values();
        oldPinValues = pinValues;
    }
    

    delay(POLL_DELAY_MSEC);
   
      sendNumber( cue + 1 );
      
   
}


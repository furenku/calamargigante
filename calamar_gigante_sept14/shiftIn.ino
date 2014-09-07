//48 49 50 51
int ploadPin        = 9;  // Connects to Parallel load pin the 165
int clockEnablePin  = 10;  // Connects to Clock Enable pin the 165
int dataPin         = 12; // Connects to the Q7 pin the 165
int clockPin        = 11; // Connects to the Clock pin the 165

BYTES_VAL_T pinValues;
BYTES_VAL_T oldPinValues;

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

/* Dump the list of zones along with their current status.
*/

void display_pin_values()
{
    //Serial.print("Pin States:\r\n");

    for(int i = 0; i < DATA_WIDTH; i++)
    {
        
        if((pinValues >> i) & 1) {

          
        } else {
          if(i==0) {
            previous();
            digitalWrite(4,HIGH);
          }
          if(i==1) {
            next();
            digitalWrite(4,LOW);
          }
            Serial.print("Pin-");
          Serial.print(i);
          Serial.println("!");
        }
    }
}

void setupShiftRegisters() {

  /* Initialize our digital pins...
    */
    pinMode(ploadPin, OUTPUT);
    pinMode(clockEnablePin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT);

    digitalWrite(clockPin, LOW);
    digitalWrite(ploadPin, HIGH);

    /* Read in and display the pin states at startup.
    */
    pinValues = read_shift_regs();
    //display_pin_values();
    oldPinValues = pinValues;
    
    
}


void readShift() {
/* Read the state of all zones.
    */
    pinValues = read_shift_regs();

    /* If there was a chage in state, display which ones changed.
    */
    if(pinValues != oldPinValues)
    {
        display_pin_values();
        oldPinValues = pinValues;
        
    } else {

       
    }

    delay(POLL_DELAY_MSEC);  
}


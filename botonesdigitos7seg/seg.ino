void sendSerialData (
      byte registerCount,  // How many shift registers?
      byte *pValueArray)   // Array of bytes with LSByte in array [0]
    {
      // Signal to the 595s to listen for data
      digitalWrite (g_pinCommLatch, LOW);
     
      for (byte reg = registerCount; reg > 0; reg--)
      {
        byte value = pValueArray [reg - 1];
       
        for (byte bitMask = 128; bitMask > 0; bitMask >>= 1)
        {
          digitalWrite (g_pinClock, LOW);
       
          digitalWrite (g_pinData, value & bitMask ? HIGH : LOW);
           
          digitalWrite (g_pinClock, HIGH);
        }
      }
      // Signal to the 595s that I'm done sending
      digitalWrite (g_pinCommLatch, HIGH);
    }  // sendSerialData

    // Print a message specifying valid inputs, given the number of registers defined and then consume all current input.
    void badNumber ()
    {
      int dummy;
     
//      Serial.print ("Please enter a number from 0 to ");
      for (int loop = 0; loop < g_registers; loop++)
      {
       // Serial.print ("9");
      }
//      Serial.println (" inclusive.");
     
      while (Serial.available () > 0)
      {
        dummy = Serial.read ();
       
        // Necessary to get all input in one go.
        delay (10);
      }
    } //badNumber

    // Read a number from the PC with no more digits than the defined number of registers.
    // Returns: number to display. If an invalid number was read, the number returned is the current number being displayed
    //
    int readNumberFromPC ()
    {
      byte incomingByte;
      int  numberRead;
      byte incomingCount;
     
      if (Serial.available () > 0)
      {
        numberRead = 0;
        incomingCount = 0;
         
        while (Serial.available () > 0)
        {
          incomingByte = Serial.read () - 48;
          incomingCount++;
         
          if (incomingByte < 0 || incomingByte > 9 || incomingCount > g_registers)
          {
            badNumber ();
            return g_numberToDisplay;
          }
         
          numberRead = 10 * numberRead + incomingByte;
         
          // Necessary to get all input in one go.
          delay (10);
        }

        
//        Serial.print (numberRead, DEC);
  //      Serial.print('.'); 
        return numberRead;
      }
     
      return g_numberToDisplay;
    } // readNumberFromPC
    
    
    
    
    void sendNumber( int num ) {
      g_numberToDisplay = num;

      if (g_numberToDisplay < 10)
      {
        g_registerArray [0] = g_digits [0];
        g_registerArray [1] = g_digits [0];
        g_registerArray [2] = g_digits [g_numberToDisplay];
      }
      else if (g_numberToDisplay < 100)
      {
        g_registerArray [0] = g_digits [0];
        g_registerArray [1] = g_digits [g_numberToDisplay / 10];
        g_registerArray [2] = g_digits [g_numberToDisplay % 10];
      }
      else if (g_numberToDisplay < 1000)
      {
        g_registerArray [0] = g_digits [g_numberToDisplay / 100];
        g_registerArray [1] = g_digits [(g_numberToDisplay % 100) / 10];
        g_registerArray [2] = g_digits [g_numberToDisplay % 10];
      }
      else
      {
        g_registerArray [0] = g_digits [g_numberToDisplay / 1000];
        g_registerArray [1] = g_digits [(g_numberToDisplay % 1000) / 100];
        g_registerArray [2] = g_digits [(g_numberToDisplay % 100) / 10];
      }

       if( settingDigits ) {
          if( counter < 125 )  {
            g_registerArray [0] = g_digits [10];
            g_registerArray [1] = g_digits [10];
            g_registerArray [2] = g_digits [10];
         } else {
            g_registerArray [0] = g_digits[ digits [0] ];
            g_registerArray [1] = g_digits[ digits [1] ];
            g_registerArray [2] = g_digits[ digits [2] ];         
         }
       
       }
      sendSerialData (g_registers, g_registerArray);
      
    }

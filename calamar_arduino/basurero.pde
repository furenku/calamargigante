/*


FWDFADE

      b_fadeSteps[i]--;
      if( b_fadeSteps[i] <= 0 ) {
        b_fadeSteps[i] = 0;
      } 
      else {
        // ARDUINO :
        
        //LED[i][0] += byte( int( LED[i][0] ) + increase[i][0] );
        //LED[i][1] += byte( int( LED[i][1] ) + increase[i][1] );
        //LED[i][2] += byte( int( LED[i][2] ) + increase[i][2] );
        


        LED[i][0] += LED[i][0] + increase[i][0];
        LED[i][1] += LED[i][1] + increase[i][1];
        LED[i][2] += LED[i][2] + increase[i][2];
        
        setLED(i,
         LED[i][0],
         LED[i][1],
         LED[i][2]
        ); 

      }
    
*/

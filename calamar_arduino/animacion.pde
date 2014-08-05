// PROCESSING

int NUMFILLS = 13;




int[] fillCurrent = new int [NUMFILLS];
int[] fillStart = new int [NUMFILLS];
int[] fillEnd = new int [NUMFILLS];
int[] fillR1 = new int [NUMFILLS];
int[] fillG1 = new int [NUMFILLS];
int[] fillB1 = new int [NUMFILLS];
int[] fillR2 = new int [NUMFILLS];
int[] fillG2 = new int [NUMFILLS];
int[] fillB2 = new int [NUMFILLS];
int[] fillWait = new int [NUMFILLS];
boolean[] fillActive = new boolean [NUMFILLS];





boolean[] fading = new boolean[NUMLEDS];
int[] b_fadeMod = new int[NUMLEDS];
int[] b_fadeAmount = new int[NUMLEDS];
int[] b_fadeSteps = new int[NUMLEDS];
int[][] increase = new int[NUMLEDS][3];
int[][] b_target = new int[NUMLEDS][3];





// ARDUINO
/*
#define NUMFILLS 13

int fillCurrent[NUMFILLS];
int fillStart[NUMFILLS];
int fillEnd[NUMFILLS];
int fillR1[NUMFILLS];
int fillG1[NUMFILLS];
int fillB1[NUMFILLS];
int fillR2[NUMFILLS];
int fillG2[NUMFILLS];
int fillB2[NUMFILLS];
int fillWait[NUMFILLS];
boolean fillActive[NUMFILLS];

boolean fading[NUMLEDS];
int b_fadeMod[NUMLEDS];
int b_fadeAmount[NUMLEDS];
int b_fadeSteps[NUMLEDS];
int increase[NUMLEDS][3];
int b_target[NUMLEDS][3];

*/


void fade( int i, int fadeMod, int fadeAmount, int r, int g, int b ) {

  fading[i] = true;
  b_fadeAmount[i] = fadeAmount;

  b_target[i][0] = r;
  b_target[i][1] = g;
  b_target[i][2] = b;

  if( fadeMod <= 0 ) fadeMod = 1;

  b_fadeMod[i] = fadeMod;
  // Arduino
  /*

  */

/*
  increase[i][0] = ( r - LED[i][0] ) / steps;   
  // println( int( ( LED[i][1] - r )  ) / ms );
  // println(incG);
  increase[i][1] = incG;   
  increase[i][2] = incB;   

  b_fadeSteps[i] = steps;
*/

}




int fadeCounter;
//byte fadeCounter;

int fadeNum = 1;
//byte fadeNum;

void fwdFade() {
  for( int i = 0; i < NUMLEDS; i++ ) {
    if( trigger( b_fadeMod[i] ) ) {
      boolean fadeEnded = true;
      for( int j = 0; j < 3; j++ ) {
        if( b_target[i][j] != LED[i][j] ) {
          fadeEnded = false;

          // posible optimizacino metiendo checktarget boolean        
          
          if( b_target[i][j] > LED[i][j] ) {
            LED[i][j] += b_fadeAmount[i];

          } else {
            LED[i][j] -= b_fadeAmount[i];;
          } 

        }

      }
      if( fadeEnded ) {
        fading[i] = false;

        fadeCounter++;

        fadeCounter %= fadeNum;

      }
    }  


  }
}







void fadeStrip(int i, int fadeMod, int fadeAmount, int r, int g, int b) {
	for(int j = stripStart[i]; j < stripEnd[i]; j++ ){
		fade(j, fadeMod, fadeAmount, r,g,b);
	}
}




void fadeEyes( int fadeMod, int fadeAmount, int r, int g, int b ){


  fadeStrip(2,fadeMod, fadeAmount, r,g,b);
  fadeStrip(3,fadeMod, fadeAmount, r,g,b);
}








/**************** FILL ***************************/
int fillNum = 0;


void clearFills() {
	fillNum=0;
}

void addFill( int start, int end, int wait, int r1, int g1, int b1, int r2, int g2, int b2 ) {
	fillCurrent[fillNum] = start;
	fillStart[fillNum] = start;
	if( fillEnd[fillNum] > NUMLEDS - 1 ) fillEnd[fillNum] = NUMLEDS - 1 ;
	fillEnd[fillNum] = end;
	fillWait[fillNum] = wait;
	
	fillR1[fillNum] = r1;
	fillG1[fillNum] = g1;
	fillB1[fillNum] = b1;
	fillR2[fillNum] = r2;
	fillG2[fillNum] = g2;
	fillB2[fillNum] = b2;

	fillActive[fillNum] = true;
	
	fillNum %= NUMFILLS;
	fillNum++;

	filling = true;
}


void fill() {
	

	boolean stopFill = true;

	for( int i = 0; i < fillNum; i++) {
		if( trigger( fillWait[i] ) ) {

			int stepsNum = abs( fillEnd[i] - fillStart[i] );
			int currentStep = abs( fillCurrent[i] - fillStart[i] );
			float currentPct = currentStep / float( stepsNum );

			int currentR = fillR1[i] + int( ( fillR2[i] - fillR1[i] ) * currentPct );
			int currentG = fillG1[i] + int( ( fillG2[i] - fillG1[i] ) * currentPct );
			int currentB = fillB1[i] + int( ( fillB2[i] - fillB1[i] ) * currentPct );

		
			setLED(
				fillCurrent[i],
				currentR,
				currentG,
				currentB
			);

			if( fillStart[i] < fillEnd[i]) {
				if( fillCurrent[i] >= fillEnd[i] ) {
					fillActive[i] = false;
				}

				fillCurrent[i]++;

				if( fillCurrent[i] > fillEnd[i] ) {
					fillCurrent[i] = fillEnd[i];
				}
			}
			else {
				if( fillCurrent[i] < fillEnd[i] ) {
					fillActive[i] = false;
				}
				fillCurrent[i]--;		

				if( fillCurrent[i] < fillEnd[i] ) {
					fillCurrent[i] = fillEnd[i];
				}		
			}

		}

		if( fillActive[i] ) stopFill = false;	

	} 

	if( stopFill ) {
		filling = false;
	}
	
}


void bodyFill( int i, int wait, int r1, int g1, int b1, int r2, int g2, int b2, boolean directionDown ) {
	if( i != 2 && i != 3 ) {

		float pos = (b_rangoPos[i]/float(255));
		float pct = (b_rangoPct[i]/float(255));

		if( directionDown ) {	
			addFill( stripStart[i], stripEnd[i], wait, //r1,g1,b1, r2,g2,b2		
			r1+int((r2-r1)*pos),
			g1+int((g2-g1)*pos),
			b1+int((b2-b1)*pos),
			r1+ int( ((r2-r1 )* (pos+pct) ) ),
			g1 + int( ((g2-g1 )* (pos+pct) ) ),
			b1 + int( ((b2-b1 )* (pos+pct) ) )
		);
		}
		else {
			addFill( stripEnd[i], stripStart[i], wait, //r1,g1,b1, r2,g2,b2		
			r2 - int( ((r2-r1 )* (pos+pct) ) ),
			g2 - int( ((g2-g1 )* (pos+pct) ) ),
			b2 - int( ((b2-b1 )* (pos+pct) ) ),
			r2-int((r2-r1)*pos),
			g2-int((g2-g1)*pos),
			b2-int((b2-b1)*pos)
		);
		}

	}
}

void fillWhole( int wait, int r1, int g1, int b1, int r2, int g2, int b2, boolean directionDown) {

/*
  addFill( stripStart[0], stripEnd[0], 1, 255, 0, 0, 0, 255, 255 );
  addFill( stripStart[1], stripEnd[1], 1, 255, 0, 0, 0, 255, 255 );
*/

//		bodyFill(0, 1, r1,g1,b1, r2,g2,b2 );

	for(int j = 0; j < NUMSTRIPS; j++ ) {
		bodyFill(j, 1, r1,g1,b1, r2,g2,b2, directionDown );			
	} 
}




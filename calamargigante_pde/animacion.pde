int NUMFILLS = 13;
//#define NUMFILLS 13


boolean filling = false;


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

// ARDUINO
/*

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

*/

int fillNum = 0;


void clearFills() {
	fillNum=0;
}

void addFill( int start, int end, int wait, int r1, int g1, int b1, int r2, int g2, int b2 ) {
	fillCurrent[fillNum] = start;
	fillStart[fillNum] = start;
	fillEnd[fillNum] = end;
	fillWait[fillNum] = wait;
	
	fillR1[fillNum] = r1;
	fillG1[fillNum] = g1;
	fillB1[fillNum] = b1;
	fillR2[fillNum] = r2;
	fillG2[fillNum] = g2;
	fillB2[fillNum] = b2;

	fillActive[fillNum] = true;
	
	fillNum++;
	fillNum %= NUMFILLS;

	filling = true;
}


void fill() {
	

	boolean stopFill = true;

	for( int i = 0; i < fillNum; i++) {
		if( trigger( fillWait[i] ) ) {

			int stepsNum = abs( fillEnd[i] - fillStart[i] );
			int currentStep = abs( fillEnd[i] - fillCurrent[i] );
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




void fillWhole( int wait, int r1, int g1, int b1, int r2, int g2, int b2 ) {


	addFill( stripStart[0], stripEnd[0], wait, r1,g1,b1,r2,g2,b2 );
	addFill( stripStart[1], stripEnd[1], wait, r1,g1,b1,r2,g2,b2  );


}
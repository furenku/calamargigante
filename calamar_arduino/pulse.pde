
int[] b_pulseVar = new int[NUMLEDS];

int b_pulseValue = 255;
int b_pulseSpeed = 0;
int b_pulseMin = 255;
int b_pulseMax = 255;


// PROCESSING

int pulseRangeNum = 0;

int[] pulseRangeValue = new int [4];
int[] pulseRangeStart = new int [4];
int[] pulseRangeEnd = new int [4];
int[] pulseRangeMin = new int [4];
int[] pulseRangeMax = new int [4];
int[] pulseRangeSpeed = new int [4];
int[] pulseRangeSpeedMin = new int [4];
int[] pulseRangeSpeedMax = new int [4];
int[] pulseRangeAcceleration = new int [4];



/* ARDUINO

int b_pulseVar[NUMLEDS];

int b_pulseValue = 255;
int b_pulseSpeed = 0;
int b_pulseMin = 255;
int b_pulseMax = 255;

int pulseRangeNum = 0;
int pulseRangeValue[4];
int pulseRangeStart[4];
int pulseRangeEnd[4];
int pulseRangeMin[4];
int pulseRangeMax[4];
int pulseRangeSpeed[4];
int pulseRangeSpeedMin[4];
int pulseRangeSpeedMax[4];
int pulseRangeAcceleration[4];
*/

void setPulse(int speed, int min, int max) {
	b_pulseSpeed = speed;
	b_pulseMin = min;
	b_pulseMax = max;
	if( b_pulseValue < min ) b_pulseValue = min;
	if( b_pulseValue < max ) b_pulseValue = max;
}



void pulse() {
	if( b_pulseSpeed > 0) {
		b_pulseValue += b_pulseSpeed;
		b_pulseSpeed *= pong( b_pulseValue, b_pulseMin, b_pulseMax );  
	}
}

void clearPulses() {
	pulseRangeNum=0;
}

void addPulse( int start, int end, int minPulse, int maxPulse, int speed, int speedMin, int speedMax, int acceleration ) {
	
	pulseRangeStart[ pulseRangeNum ] = start;
	pulseRangeEnd[ pulseRangeNum ] = end;
	
	pulseRangeValue[ pulseRangeNum ] = ( maxPulse - minPulse ) / 2;
	pulseRangeMin[ pulseRangeNum ] = minPulse;
	pulseRangeMax[ pulseRangeNum ] = maxPulse;
	pulseRangeSpeed[ pulseRangeNum ] = speed;
	pulseRangeSpeedMin[ pulseRangeNum ] = speedMin;
	pulseRangeSpeedMax[ pulseRangeNum ] = speedMax;
	pulseRangeAcceleration[ pulseRangeNum ] = acceleration;
	pulseRangeNum++;

}

void pulses() {

	for(int i=0; i<pulseRangeNum; i++){

		pulseRangeValue[ i ]  += pulseRangeSpeed[ i ];

		pulseRangeSpeed[ i ] += pulseRangeAcceleration[ i ];

		pulseRangeSpeed[ i ] *= pong(
			pulseRangeValue[ i ],
			pulseRangeMin[ i ],
			pulseRangeMax[ i ]
		);

		pulseRangeAcceleration[ i ] *= pong(
			pulseRangeSpeed[ i ],
			pulseRangeSpeedMin[ i ],
			pulseRangeSpeedMax[ i ]
		); 
		

	}

}


float getRangePulse( int i ) {
	float rangePulse = 1;
	for( int j = 0; j < pulseRangeNum; j++ ) {
		if( pong( i,  pulseRangeStart[ j ],  pulseRangeEnd[ j ] ) == 1 ) {
			rangePulse = pulseRangeValue[ j ] / float( 255 );
			break;
		}		
	}
	return rangePulse;
} 
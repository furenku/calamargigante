


int[] pulseRangeValue = new int [4];
int[] pulseRangeStart = new int [4];
int[] pulseRangeEnd = new int [4];
int[] pulseRangeMin = new int [4];
int[] pulseRangeMax = new int [4];
int[] pulseRangeSpeed = new int [4];
int[] pulseRangeSpeedMin = new int [4];
int[] pulseRangeSpeedMax = new int [4];
//byte pulseRangeSpeed = new int [4];
int[] pulseRangeAcceleration = new int [4];
//byte pulseRangeAcceleration = new int [4];



/* ARDUINO
int pulseRangeValue[4];
int pulseRangeStart[4];
int pulseRangeEnd[4];
int pulseRangeMax[4];
int pulseRangeMin[4];
int pulseRangeMax[4];
int pulseRangeSpeed[4];
int pulseRangeSpeedMin[4];
int pulseRangeSpeedMax[4];
//byte pulseRangeSpeed[4];
int pulseRangeAcceleration[4];
//byte pulseRangeAcceleration[4];
*/
int pulseRangeNum = 0;

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

		pulseRangeValue[ pulseRangeNum ]  += pulseRangeSpeed[ pulseRangeNum ];
		pulseRangeSpeed[ pulseRangeNum ] += pulseRangeAcceleration[ pulseRangeNum ];

		pulseRangeSpeed[ pulseRangeNum ] *= pong(
			pulseRangeValue[ pulseRangeNum ],
			pulseRangeMin[ pulseRangeNum ],
			pulseRangeMax[ pulseRangeNum ]
		);

		pulseRangeAcceleration[ pulseRangeNum ] *= pong(
			pulseRangeSpeed[ pulseRangeNum ],
			pulseRangeSpeedMin[ pulseRangeNum ],
			pulseRangeSpeedMax[ pulseRangeNum ]
		); 
		

	}

}
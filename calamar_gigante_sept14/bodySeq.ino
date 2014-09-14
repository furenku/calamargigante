int numBodyParts = 3;
int numSubBodyParts = 2;

int bodySeqCnt;

int bodyPartStart[6];
int bodyPartEnd[6];
byte bodyPart = 0;

bool bodySequencing = false;
bool bodySeqLooping = false;


byte bodySeqSpeed = 1;

void setupBodySeqStrips() {

  bodyPartStart[0] = stripStart[0];
  bodyPartStart[1] = stripStart[1];

  bodyPartStart[2] = stripStart[4];
  bodyPartStart[3] = stripStart[5];

  bodyPartStart[4] = stripStart[6];
  bodyPartStart[5] = stripStart[9];



  bodyPartEnd[0] = stripEnd[0];
  bodyPartEnd[1] = stripEnd[1];

  bodyPartEnd[2] = stripEnd[4];
  bodyPartEnd[3] = stripEnd[5];

  bodyPartEnd[4] = stripEnd[8];
  bodyPartEnd[5] = stripEnd[12];


}

void startBodySeq( byte spd = 1 ) {
  bodyPart = 0;
  bodySeqCnt=0;
  bodySequencing = true;
  bodySeqSpeed = spd;
}

void bodySeq() {

  if( bodySequencing ) {

    bool nextBodyPart = true;

    for( int i = 0; i < numSubBodyParts; i++ ) {
      if( bodySeqCnt < bodyPartEnd[ (bodyPart*numSubBodyParts) + i ] ) {
        for( int j = bodySeqCnt; j < bodySeqCnt + bodySeqSpeed; j++ ) { 
          int index = bodyPartStart[ (bodyPart*numSubBodyParts) + i ] + bodySeqCnt + j;
          
          if(index> stripEnd[12]) bodySequencing = false;
          else bodySeqLed( index ); 
        }

        nextBodyPart = false;     
      }
    }
    if( nextBodyPart ) {
      bodySeqCnt=0;
      bodyPart++;
      if(bodyPart >= numBodyParts )
        bodySequencing = false;
      if( bodySeqLooping) {
        bodyPart %= numBodyParts;
      }
    }

    bodySeqCnt += bodySeqSpeed;

  }

}

void bodySeqLed( int i ) {
  setLed(i,azulrey);

}

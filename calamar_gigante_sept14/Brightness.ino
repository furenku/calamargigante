
float generalBrightness = 1;

int generalBrightnessSteps = 1;
byte generalBrightnessMod = 1;
float generalBrightnessAmount = 0, generalBrightnessTarget = 1;

bool generalBrightnessFading = false;

void setGeneralBrightness( float b ) {
  generalBrightness = b;
}


void fadeGeneralBrightness( float generalBrightnessTarget, int mod, int numSteps) {
  generalBrightnessMod = mod;
  generalBrightnessSteps = numSteps;    
  generalBrightnessAmount = ( generalBrightnessTarget - generalBrightness ) / numSteps;
  Serial.println(generalBrightnessAmount);
  generalBrightnessFading = true;
}


void clearGeneralBrightnessFade() {
  generalBrightnessFading = false;
  generalBrightnessSteps = 0;
}


void fwdGeneralBrightnessFade() {
  if( generalBrightnessSteps > 0 ) {
    generalBrightness += generalBrightnessAmount;
    generalBrightnessSteps--;
  } else {
    clearGeneralBrightnessFade();
  }
}


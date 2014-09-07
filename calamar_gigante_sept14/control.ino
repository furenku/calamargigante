

void previous() { cue--; cue%=NUMCUES; if(cue<0) { cue = NUMCUES - 1; } }

void next() { cue++; cue%=NUMCUES; }

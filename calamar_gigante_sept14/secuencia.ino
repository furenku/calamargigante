/*
int probability = 255;


void mainSeq( int cue ) {
	clearPulse();
	clearFades();
// TO DO: brightness

int ojosInicio = 136;
int ojosFinal = 142;

switch( cue ) {
	case 0:
	black();
	break;

	case 1:
	// pulsnado centro afuera
	// 0,150,175
	setRgb( strip.Color( 0,255,255 ) );
    setPulse(10,47,3,2,2,4,1,0);

	//intendidad subiendo
	break;

	case 2:
	// ojos ambar
	setRgb(strip.Color(255,255,50));

	break;


	case 3:

	ojosSet( 125,0,125 );
	ojosFade( 2,2, 255,0,125 );

	colorWipe( strip.Color(150,0,40) , 2 );

	setPulse( 30, 220, 2, 2, 2, 5, 1, 0 );
	// pulso intenso


	break;


	case 4:
	// se calma
	for(int i = 0; i < NUMLEDS-1; i ++ ) {
		addFade(i,i,2,2,0,125 + ( i / float(6) ),200);	
	}


	break;





case 5:

black();

for(int i = 0; i < NUMLEDS-1; i ++ ) {
	addFade(i,i,2,2,0,( i / float(6) ),250-( i / float(6) ));	
	setPulse(50,200,2,3,3,6,1,1);
}

break;



case 6:


black();

for(int i = 0; i < NUMLEDS-1; i ++ ) {
	addFade(i,i,2,2,50,( i / float(3) ),200-( i / float(6) ));	
	setPulse(50,200,2,4,5,7,1,1);
}



break;



case 7:


	setPulse(50,200,1,5,4,12,2,2);


break;


case 8:



for(int i = 0; i < NUMLEDS-1; i ++ ) {
	addFade(i,i,2,2,50,( i / float(3) ),200-( i / float(6) ));	
	setPulse(50,200,2,4,5,7,1,1);
}


break;


case 9:
// PULSO OJO

ojosFade( 2, 4, 0, 155,255 );
    setPulse(10,147,2,4,3,6,1,0);

break;


case 10:
rainbow(1,0,256);
break;


case 11:
	addFade(0,NUMLEDS,2,3,150,150,150);

    setPulse(10,47,3,2,2,4,1,0);

break;


case 12:

	addFade(0,NUMLEDS-1,2,3,getR(aquamarina),getG(aquamarina),getB(aquamarina));


break;


case 13:
	ojosFade(2,3,255,255,255);
	
	break;


case 14:

	addFade(0,NUMLEDS-1,2,3,getR(aquamarina),getG(aquamarina),getB(aquamarina));
    setPulse(110,147,6,2,2,4,1,0);

break;




case 15:

	colorWipe( morado, 3 );
	delay(800);
	colorWipe( aquamarina, 3 );
	
break;


case 16:

break;


case 17:

break;


case 18:

setRgb( aquamarina );
setPulse(60,160,3,2,2,3,1,0);

break;


case 19:

colorWipe( rojo, 3 );
delay(800);
colorWipe( lila, 3 );

break;


case 20:

	addFade(0,NUMLEDS-1,3,2,130,255,170);

break;


case 21:


// AUMENTA 10 SEGS. LUEGO SE CALMA
break;



case 22:

ondular();
break;


case 23:
	addPulse(20,120,5,2,2,2,1,0);
	spreadColor(50,2,true);
break;


case 24:
	setDance(300,330,2);
break;


case 25:
setDance(300,330,2);
break;

case 26:
	setLed(350,violeta);
	spreadColor(350,3,true);
break;


case 27:

break;


case 28:

colorWipe( rojo, 3 );
delay(800);
colorWipe( lila, 3 );
break;

case 29:

	colorWipe( azulrey, 3 );
	ojosFade(3,4,255,255,255);
	setPulse(80,140,3,2,2,60,1,0);
break;


case 30:
	addFade(0,NUMLEDS-1,2,3, rosado );

	drawStatic(probability);
    if(trigger(10) ) { 
		probability--;
    	if( probability<155) { probability = 255; }
    }
break;

case 31:
	colorWipe( azulrey, 3 );

break;

case 32:
	setLed(50,verdeamarillo);

	spreadColor(50,3,true);

break;


case 33:
// niño toca cabeza
// navidad 20 s
break;


case 34:

break;


case 35:
	// oleaje
break;

case 36:

break;


case 37:

break;


case 38:
	black();
	ojosFade(4,3,0,250,0);	
break;


case 39:
	black();
break;

}


}



*/

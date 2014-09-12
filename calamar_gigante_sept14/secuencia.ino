/*





/* NUEVA SEQ */

// progresion dramatica - ir aumentando capacidades del calamar

/*

siempre pulsa! la diferencial y velocidad indican intensidad

asi tmb como el contraste entrte 2 circuitos 



// cue 0 que indica que est listo
// cue 1 oscuro

// 2. 2.5 minutos
// pulsando centro afuera - algo vivo al borde de la muerte
// corazon pulsando leve
// bajando de tiempo, luego retomar - se esfuerza x mantenerse vivo
// circuito central- rojo rosa pulsando
// tiene una intensidad global que va subiendfo muy gradualmente

// 3. "esta cosa del calamar" - el calamar se emputa
// ojo se prende 100% probar ambar o magenta
// del centro del pulso se esparce un color a todo el calamar
// nivel de irritacion 30%
// pierde su fragilidad
// mantiene pulsacion, un poco mas rapida
// ojo se va hacia el magenta, luego baja su nivel de rojo suavemente



4. solo es un calalamr gigante

este se calma


5. calamar habla. tomar aire -  cuerpo se apaga rapido, toma aire y luego sube de intensidad

6."como?" tomar aire y hablar

7. "supuren" - padres ignroarn y el calamar se enchila - se impacienta  y hay un crescendo que dura 1:16

8. termina discurso - calamar desciende de intensidad poco a poco - transicion despacio hacia blanco y ojo  hacia aquamarina 
anco
9. "se estaba suicidando" - el ojo reacciona - calamar se entristece - ojo remi, cerrar y abrirlo variias veces lento

10. "¿Podemos verlo de cerca? " - se activa porque se le estn acercando, cuerpo hacia acuamarina y actividad seductora (ver ej. rainbow(1) )


11. "tienes razon, ... trampa" - papa suelta sus hombros -  calamar se decepciona, baja su actividad y regresa a la debilidad inicial

12. niño cuenta sueño - calamar regresa suave a aquamarina

13. "--- se me acerco mucho" -  niño menciona ojo que brilla como luna

14. "asi son ellos" - calamar no debe robar foco - ojo regresa a color anterior (cual color anterior?) - se queda pulsando liso hacia aquamarina sutil con variacion

15. "cada vez que lo decia me sentia mas tonta " calamar se emputa un poco . calamar se llena de abajo arriba rapido color casi rojo morado, y luego retrocede pq no la abraza

16. "estuvieron ahi ayer" - regresa a la calma - no roba foco

17. "no me mientan" - empieza a tener mayor actividad en las manos, crescendo durante 30 s

18. "no les sorprende?" - le da un bajon rapido - quizas solo un circuito. poca actividad

19. gary intenta apagar la tele - calamar se empuyta un poco. del centro hacia los extremos - una sacudida de color. aspaviento rojo despues regresa hacia lila 

20.   padres empiezan a pelear - se va nefasteando y poniendo verdeegrislilaclarito horrible

21. "si lo analizas, no tiene sentido..." - el calamar aumenta de intensidad conforme se aleja gary - verdeambar estrobo aumentando 10 segundos, despues se calma

22. la gente necesita tener ilusiones, verdad' - la tele reacciona al calamar. el calamar tiene una animacion suavecita ondulante y lenta hacia los tentaculos .. estos tienen ms luz que en el resto (un abrazo)

23. ella choca, inicia animacion en la caja -  reaccion expansiva blanca - luego ilumina donde ella esta - mientras pulsa "respira" muy lento (descendiendo)

24. agarran 1er tentaculo - animacion a partir de ese punto 

25. la niña agarra el otro

26. "soy una niña diminuta" - el calamar emocionandose - trancesoso - se pone mas violeta de la cola, se va intensificando desde ahi todo el cuerpo y rellenandose

27. se desmaya - se retira el color intenso, y luego se pone de un color chafa liso rellenandose en sentido contrario

28. el calamar se emputa y muje - se rellena de rojo y pulsa muy rapido y pulsa mas intenso en las extremidades. ojo naranja

29. se pinta de color azul indigo y ojo blanco y con un pulso que incrementa de intensidad durante 1:15 y acelerarse 200%

30. "vas a repetir el año" - 5 segudnos - cambian a rosado pixeles al azar, uno por uno y luego sus contiguos, aprecen mas encendiddos al azar hasta que se completa .

70 segundos -> transiciona hacia estatica TV utilizando tetris y a ver que pasa

31. "la TV para presidente!" - al calamar le da verguenza ser TV y se pasa a azul indigo 

32. el calamar ilustra la enfermedad del niño, inflamacion que crece, pudredumbre verde en el pulmon

34. el niño toca la caja, y de ahi empieza a irradiar la navidad. la navidad va intensificandose hasta ser incontenible durante 20 segundos

35.  "he pensado" - utilizar la misma animacion de navidad para regresar al rosa inicialesta debil ,  paerecido  al inicio

35. susan empieza a hacer el sonido de las olas con la TV (5 segundos de periodo) (pulso de intensidad y "oleaje en la animacion

36. "tengo sueño" - empieza a transicionar  hacia azul oscuro en 10 s, se mantiene el oleaje

37. el calamar hace un gesto breve , parecido a escupir. se acumula mdio lento (5 segs) luz en el centro, y de ahi luego se proyecta rapido hacia afuera ( 0.5 seg )

38. jed cierra los ojos - calamar abre los ojos - bajar intensidad cuerpo y prender los ojos en verde 

39. todo se apaga








TODO: 

- transicion en pulsos ( intensidad, colroes, ritmos )













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

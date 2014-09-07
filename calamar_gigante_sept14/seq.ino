void seq() {
  switch(cue) {
    case 0:
      doubleHelix();
      break;
    case 1:
      setLeds( white() );
      break;
    case 2:
      setLeds( red() );
      break;
    case 3:
      setLeds( green() );
      break;
          case 4:
      blue();
      break;
    case 5:
      black();
      break;
    case 6:
      rainbow(1);
      break;
  }
 
  }
  
  
//fadeLeds(rango,min,max)




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

8. termina discurso - calamar desciende de intensidad poco a poco - transicion despacio hacia violeta y ojo  hacia aquamarina 

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

33. el niño toca la caja, y de ahi empieza a irradiar la navidad. la navidad va intensificandose hasta ser incontenible durante 20 segundos

34.  "he pensado" - utilizar la misma animacion de navidad para regresar al rosa inicialesta debil ,  paerecido  al inicio

35. susan empieza a hacer el sonido de las olas con la TV (5 segundos de periodo) (pulso de intensidad y "oleaje en la animacion

36. "tengo sueño" - empieza a transicionar  hacia azul oscuro en 10 s, se mantiene el oleaje

37. el calamar hace un gesto breve , parecido a escupir. se acumula mdio lento (5 segs) luz en el centro, y de ahi luego se proyecta rapido hacia afuera ( 0.5 seg )

38. jed cierra los ojos - calamar abre los ojos - bajar intensidad cuerpo y prender los ojos en verde 

39. todo se apaga








TODO: 

- transicion en pulsos ( intensidad, colroes, ritmos )












*/




/* VIEJA */
// fadeColor( todas, fiuscha, 30 );

// pulsar(secc246, 0, 0, 100, 0 ) 
// pulsar(secc135, 0, 2, 100, 2 ) 


// fade(todas,0,2)
// fade(secc13456, 80, 15)

 
// aquamarina  
// fadeColor(secc13456, aquamarina, 30)


// fade(secc2, 0, 0)
// fadeColor(secc2, rosado, 0)
// fade(secc2, 50, 5)
// fade(secc2, 0, 5)

// fadeColor( secc13456, azulrey, 2 )


// fadeColor( secc2, rojo, 60 )

// fade( secc2, 100, 60 )

// fadeColor( todas, violeta, 5 )
// 115,0,230

// fadeColor( secc2, aquamarina, 0 )

// sec2 pulsar( secc2, 40, 30, 20, 10)
// seccs 1,3,4,5,6 pulsar(50, 10, 70, 10)

// fade( secc2, 50, 5 )
// fade( secc2, 30,2)
// fade( secc2, 70,2)
// fade( secc2, 40,2)


// fade(secc13456, 60, 5);

// fade(secc2,70,60)

// fade(todas,20,2)

// fade( todas, 60, 2)

// fade( secc2, 30, 10 )

// fadeColor( secc13456, azulcielo, 60)
// 


// fadeColor( violeta, 65 );
// 


// fade(todas,100,5)

// fade(todas,40,20)



// fadeColor( secc2, fiuscha, 5 )



// fade( secc2, 70, 5 )

// fadeColor( secc13456, azulrey, 2 )

// fadeColor( secc13456, rojo, 5 )


// fade( secc13456, 70, 5 )

// fadeColor( secc13456, azulrey, 2 )

// fadeColor( secc2, aquamarina, 0 )

// fadeColor( secc2, aquamarina, 2 )

// fadeColor( secc13456, rosado, 5 )

// fade( secc13456, 100, 60 )

// fadeColor( secc13456, azulrey, 5 )

// fade( secc13456, 60, 10 )

// fadeColor( secc2, aquamarina, 5 )

// fadeColor( secc2, verde, 10 )
// uint32_t verde = strip.Color(0,255,0)

// fade( secc2, 100, 5 )

// fade( secc135, 0, 10 )
// fade( secc46, 0, 5 )
// fade( secc135, 100, 5 )
// fade( secc46, 100, 10 )

// fade( secc135, 0, 10 )
// fade( secc46, 0, 5 )
// fade( secc135, 100, 5 )
// fade( secc46, 100, 10 )

// fade( secc135, 0, 10 )
// fade( secc46, 0, 5 )
// fade( secc135, 100, 5 )
// fade( secc46, 100, 10 )

// fade( secc135, 0, 10 )
// fade( secc46, 0, 5 )

// fade(todas,40,20)

// fade(todas,80,20)

// fadeColor( secc13456, rosado, 2 )

// fadeColor( secc13456, azulrey, 5 )

// fade( secc2, 100, 5 )

// fade( secc13456, 10, 0 )

// fade( todas, 0, 0 )

import processing.serial.*; 

Serial port;
byte[] array = new byte[1200];
byte[] tmp = new byte[63]; 



int val = 0;
byte serialCounter = 0;

void setupSerial() {
	
	port = new Serial(this, Serial.list()[0], 115200);

	delay(2000) ;

}



void writeSerial() {
	
	serialCounter++;

	serialCounter %= 100;

if(serialCounter == 0) {
/*
	val+=30;
    val%=255;
    */
    port.write(byte('A'));


    //byte[] tmpArr = new byte[30];


    for ( int i = 0; i < 100; i++) {

    	array[ (i*3) + 0 ] = byte( drawLED[i][0] );
    	array[ ( i*3 ) + 1 ] = byte( drawLED[i][1] );
    	array[ ( i*3 ) + 2 ] = byte( drawLED[i][2] );


/*	    port.write(byte( drawLED[i][0] ));
	    port.write(byte( drawLED[i][1]));
	    port.write(byte( drawLED[i][1]));
	    */
/*
	    if( i % 30 == 29 ) {

	    	port.write('B');
	    	port.write(tmpArr);
	    	port.write('C');

	    }	  
	    */  
	}


    /*for ( int i = 0; i < 1200; i++) {
    	port.write( array[i] );
    }
    */
   port.write(array);

	//delay(80);

}


}

void randomRGBarray() {
	val+=31;
	val%=255;
	port.write(byte('A'));

	
	for(int i = 0; i<1200; i++ ) {
		if(i%3==0) 
			array[i] = byte( val / ((i % 3 )+1) );
		else  if(i%3==1) 
			array[i] = byte( (val * 5 % 255 ));
		else
			array[i] = byte( (val *2 % 255 ) );

	}

port.write(array); 

delay(30);

}






SerialSend serial = new SerialSend();


class SerialSend extends Thread {
	boolean running;
	int count;
	int prevTime = millis();
  float fr = 1000;    //Framerate of the separate thread, the higher, the more artifacts
  boolean limitedFramerate = true; //Disables the frame limiting, go as fast as it can!

  SerialSend(){
  	running = false;
  	count = 0;
  }

  void start()
  {
  	running = true;
  	super.start();
  }

  void run()
  {
  	while (running)
  	{
      //boolean runIt = false;
      //randomRGBarray();
      writeSerial();
  }
}

void quit()
{
	running = false;
	interrupt();
}
}



void readSerial() {
while (port.available() > 0) {
    String inBuffer = port.readString();   
    if (inBuffer != null) {
      println(inBuffer);
    }
  }

}
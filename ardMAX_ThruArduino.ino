// ardMAX_ThruArduino.ino
// by Christopher Konopka

// The purpose of this patch is to provide a basic 
// example of how to send data from MaxMSP, thru an
// Arduino and back out via the [serial] object in
// MaxMSP

//-----Globals---------------------------------------
int fromMax;

//-----Setup-----------------------------------------    
void setup() 
{
  Serial.begin(9600);    // create serial monitor
}

//-----Loop-----------------------------------------
void loop() 
{
  fromMAXthruARDUINO(20);
}

//-----Functions/Methods----------------------------
int fromMAXthruARDUINO(int dataRATE)
{
	// read data from MaxMSP
	fromMAX = Serial.read();	

  	if(Serial.available())
  	{ 
  		// Send data back to MaxMSP
  		Serial.println(fromMAX);
  	}
  	
	// data flow rate to MaxMSP
	delay(dataRATE);    
}



// ardMAX_ThruArduinoOSC.ino
// by Christopher Konopka

// The purpose of this patch is to provide a basic 
// example of how to send data from MaxMSP, thru an
// Arduino and back out via the [serial] object in
// MaxMSP. The associated patch uses the output data
// and uses it to connect to Csound via OSC

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
  fromARDUINOtoMAX4osc(20);
}

//-----Functions/Methods----------------------------
int fromARDUINOtoMAX4osc(int dataRATE)
{
  	// create random ints
  	fromMaxf = random(0, 255);

  	// print random ints in MaxMSP
  	Serial.println(toMAX);

  	// data flow rate to MaxMSP
    delay(dataRATE);    
}



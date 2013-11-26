// ardMAX_ThruArduinoOSC2csound.ino
// by Christopher Konopka

// The purpose of this patch is to provide a basic 
// example of how to send data from MaxMSP, thru an
// Arduino and back out via the [serial] object in
// MaxMSP. This data is then forwarded to Csound via
// OSC to control an oscillator (oscil opcode)

//-----Globals---------------------------------------
int fromMax2Csound;

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
  	fromMax2Csound = random(0, 255);

  	// print random ints in MaxMSP
  	Serial.println(fromMax2Csound);

  	// data flow rate to MaxMSP
    delay(dataRATE);    
}



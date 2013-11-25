// ardMAX_FromArduino.ino
// by Christopher Konopka

// The purpose of this patch is to provide a basic 
// example of how to send data to MaxMSP via an 
// Arduino using simple print messages

//-----Globals---------------------------------------
int toMAX;

//-----Setup-----------------------------------------    
void setup() 
{
  Serial.begin(9600);    // create serial monitor
}

//-----Loop-----------------------------------------
void loop() 
{
  fromARDUINOtoMAX(20);
}

//-----Functions/Methods----------------------------
int fromARDUINOtoMAX(int dataRATE)
{
	// create random ints
	toMAX = random(0, 255);

	// print random ints in MaxMSP
	Serial.println(toMAX);

	// data flow rate to MaxMSP
  	delay(dataRATE);    
}



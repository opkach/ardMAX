// ardMAX_SensorFromArduino.ino
// by Christopher Konopka

// The purpose of this patch is to provide a basic 
// example of how to send sensor data from an Arduino 
// to MaxMSP via the [serial] object. 

//-----Globals---------------------------------------
int sensorSource;

//-----Setup-----------------------------------------    
void setup() 
{
  Serial.begin(9600);    // create serial monitor
}

//-----Loop-----------------------------------------
void loop() 
{
  fromSENSORtoMAX(20);
}

//-----Functions/Methods----------------------------
int fromSENSORtoMAX(int dataRATE)
{
  	// acquire sensor data stream
    sensorSource = analogRead(0);

    // scale sensor output
    sensorSource = map(sensorSource, 0, 1024, 0, 255); 

  	// print random ints in MaxMSP
  	Serial.println(toMAX);

  	// data flow rate to MaxMSP
    delay(dataRATE);    
}



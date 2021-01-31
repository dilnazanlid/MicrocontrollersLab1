int pin = 8; // store pin for LED
int timeShort = 500; // store the time for short signal
int timeLong = 2000; // store the time for long signal
int timeBetween = 500; // store the time interval between signals

void setup()
{
  pinMode(pin, OUTPUT);   // set the LED pin for output mode
}

void loop()
{	
  	digitalWrite(pin, HIGH); // start of first three short signals
  	delay(timeShort); 
  	digitalWrite(pin, LOW);
  	delay(timeBetween); 
 	digitalWrite(pin, HIGH);
  	delay(timeShort); 
  	digitalWrite(pin, LOW);
  	delay(timeBetween);
  	digitalWrite(pin, HIGH);
  	delay(timeShort);
  	digitalWrite(pin, LOW);
  	delay(timeBetween); // end of first three short signals
  	digitalWrite(pin, HIGH); // start of three long signals
  	delay(timeLong);
  	digitalWrite(pin, LOW);
  	delay(timeBetween); 
 	digitalWrite(pin, HIGH);
  	delay(timeLong); 
  	digitalWrite(pin, LOW);
  	delay(timeBetween); 
 	digitalWrite(pin, HIGH);
  	delay(timeLong); 
  	digitalWrite(pin, LOW);
  	delay(timeBetween);    // end of three long signals
  	digitalWrite(pin, HIGH); // start of second three short signals
  	delay(timeShort);
  	digitalWrite(pin, LOW);
  	delay(timeBetween); 
 	digitalWrite(pin, HIGH);
  	delay(timeShort); 
  	digitalWrite(pin, LOW);
  	delay(timeBetween); 
  	digitalWrite(pin, HIGH);
  	delay(timeShort);     
  	digitalWrite(pin, LOW);  // end of second three short signals
  	delay(5000); 	// longer delay after SOS signal before starting the cycle again
}

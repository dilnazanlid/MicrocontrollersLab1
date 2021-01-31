int cm = 0;  // variable to store the distance in cm
int triggerPin = 3; // variable for trigger output pin
int echoPin = 2; // variable for echo input pin

long readUltrasonicDistance(){
  	// reset the trigger
	pinMode(triggerPin, OUTPUT); 
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);
  
  	// sets the trigger pin to HIGH state for 10 microseconds
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);
  
  	// read the input from echo pin
	pinMode(echoPin, INPUT);
  
  	// return the wave travel time in microseconds
	return pulseIn(echoPin, HIGH);
}

void setup(){
	Serial.begin(9600); // set the 9600 bits per second for serial data transmission
}

void loop(){
  
  	// get the distance from separate function and store in variable converting to centimeters
	cm = 0.01723 * readUltrasonicDistance();
  
  	// print the distance into the serial monitor
	Serial.print(cm);
	Serial.println("cm"); 
  
	delay(100); // Wait for 0.1 seconds
}
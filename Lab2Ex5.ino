int ledPin = 13; // variable for LED pin
int pirPin = 7; // variable for PIR pin
int pirStat = 0; // variable for PIR status

void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(pirPin, INPUT);
	Serial.begin(9600); // set the 9600 bits per second for serial data transmission
}

void loop(){
  	// read the current status of PIR
 	pirStat = digitalRead(pirPin);
  	// if motion is detected
	if (pirStat == HIGH) { 
 		digitalWrite(ledPin, HIGH); // turn the LED on and print the message to the serial monitor
 		Serial.println("It's me! Turn on the ligths!");
 	} else { // if no motion is detected
 		digitalWrite(ledPin, LOW); // turn LED OFF if we have no motion
 	}
}
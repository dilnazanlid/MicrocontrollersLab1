const int ledPin = 13; // variable for LED output pin
const int potPin = A5; // variable for potentiometer analog input pin
int val = 0; // variable to store value of potentiometer

void setup() {
	pinMode(ledPin, OUTPUT);
 	Serial.begin(9600); // set the 9600 bits per second for serial data transmission
}

void loop() {
 	val = analogRead(potPin); // read the voltage on the potentiometer
  
  	// turn on and off the LED for the blink rate in milliseconds of potentiometer value
	digitalWrite(ledPin, HIGH);	
	delay(val);  
	digitalWrite(ledPin, LOW);
	delay(val); 
  	// print the readind of potentiometer to the serial window
	Serial.println(val);
}
const int sensorPin = A0; // variable for photoresistor analog input pin
const int ledPin = 13; // variable for LED output pin
int lightInitial; // variables to store photoresistor value
int lightVal;

void setup() {
	pinMode(ledPin, OUTPUT);
	lightInitial = analogRead(sensorPin); // set the initial value of photoresistor (in simulator it is always dark - smallest resistance value)
}

void loop() {
	lightVal = analogRead(sensorPin); // read the value of photoresistor 
  
  	// if the value of photoresistor is over below 50 ohm, the LED is turning on
 	// otherwise it turns off
	if (lightVal < lightInitial + 50) {
 		digitalWrite(ledPin, HIGH);
 	}else {
 		digitalWrite (ledPin, LOW);
 	}
}
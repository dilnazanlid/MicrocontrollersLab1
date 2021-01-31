int sensorPin = A0; //select the input pin for the light sensor
int sensorValue = 0; //variable to store the value coming from the sensor
int ledpin = 11;

void setup() {
	// declare the ledPin as an OUTPUT:
	Serial.begin(9600);
	pinMode(ledpin, OUTPUT);
}

void loop() {
	// read the value from light sensor and display on serial display
  	sensorValue = analogRead(sensorPin); 
	
  	Serial.print("Light = ");
	Serial.println(sensorValue);
  	// light up the LED according to the value of sensor light
	analogWrite(ledpin, 255-sensorValue*3);
	delay(1000);
}
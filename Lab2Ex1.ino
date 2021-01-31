const int buttonPin = 7; // variablefor button pin
const int ledPin = 13; // variable for LED pin
int ledState = LOW; // variable for current LED state
int buttonState; // variable for current button reading
int lastButtonState = LOW; // variable for last button reading
unsigned long lastDebounceTime = 0; // last time the pin was toggled
unsigned long debounceDelay = 100; // the debounce delay, user can set prior

void setup() {
 	pinMode(buttonPin, INPUT); // set button pin to INPUT mode
 	pinMode(ledPin, OUTPUT);   // set LED pin to OUTPUT mode
 	digitalWrite(ledPin, ledState); // set the initial state of LED 
}

void loop() {
 	int reading = digitalRead(buttonPin);  // read the state of button: pressed(HIGH)/not pressed(LOW)
  	// if the last state of button is not equal to current state re-write the last debounce time to current millis
 	if (reading != lastButtonState) {    
 		lastDebounceTime = millis();
 	}
  	// if the difference between current millis time and last debounce time is more than debounce delay time set above
  	// it means enough time have passed after last button press and it is not bounce
 	if ((millis()-lastDebounceTime) > debounceDelay) {
 		if (reading != buttonState) {	
 			buttonState = reading;
 			if (buttonState == HIGH) {
 				ledState = !ledState;
 			}
 		}
 	}
  	// set the LED to the new state if it was changed
 	digitalWrite(ledPin, ledState);
  	// store current reading of button to the next loop
 	lastButtonState = reading;
}
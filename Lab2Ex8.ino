int triggerPin = 3, echoPin = 2;  // pins for proximity sensor
int cm = 0; // to store distance
int potentiometer = A0; // analog input pin for potentiometer
int potVal = 0; // to store potentiometer value
int lightSensor = A1; // analog input pin for light sensor
int lightSensorVal = 0; // to store light sensor value
int brightnessButtonPin = 7; // pin for brightness button
int lastBrightnessState = LOW;
int brightnessState;
int callButtonPin = 8; // pin for call button
int lastCallState = LOW;
int callState;
int ledPin = 11; // pin for LED
unsigned long callLastDebounceTime = 0; // last time the CALL pin was toggled
unsigned long callDebounceDelay = 10; // the CALL debounce delay, user can set prior
unsigned long brightnessLastDebounceTime = 0; // last time the BRIGHTNESS pin was toggled
unsigned long brightnessDebounceDelay = 10; // the BRIGHTNESS debounce delay, user can set prior
int ledVal = 0; // variable for current LED analog value

int onCall = 0; // 0 - not calling, 1 - calling
int onBrightness = 0; // 0 - manually, 1 - auto

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

void setup()
{
  	pinMode(brightnessButtonPin, INPUT); // set button pin to INPUT mode
  	pinMode(callButtonPin, INPUT); // set button pin to INPUT mode
 	pinMode(ledPin, OUTPUT);   // set LED pin to OUTPUT mode
 	Serial.begin(9600);
  	analogWrite(ledPin, ledVal); // set the initial state of LED to 0
  
}

void loop()
{	  
  	// CALL BUTTON CLICKING
  	int readingCall = digitalRead(callButtonPin);
  	// checking the last debounce time and changing the value of "onCall"
  	// if it is greater than debounce delay
  	if (readingCall != lastCallState) {
 		callLastDebounceTime = millis();
 	}
  	
  	if ((millis()-callLastDebounceTime) > callDebounceDelay) {
 		if (readingCall != callState) {	
 			callState = readingCall;
 			if (callState == HIGH) {
              	Serial.println("Call changed");
 				onCall = !onCall;
 			}
 		}
 	}
  	// BRIGHTNESS BUTTON CLICKING 
  	int readingBrightness = digitalRead(brightnessButtonPin);
 	// checking the last debounce time and changing the value of "onBrightness"
  	// if it is greater than debounce delay
  	if (readingBrightness != lastBrightnessState) {    
 		brightnessLastDebounceTime = millis();
 	}
  
  	if ((millis()-brightnessLastDebounceTime) > brightnessDebounceDelay) {
 		if (readingBrightness != brightnessState) {	
 			brightnessState = readingBrightness;
 			if (brightnessState == HIGH) {
              	Serial.println("Brightness changed");
 				onBrightness = !onBrightness;
 			}
 		}
 	}
  	
  	// POTENTIOMETER reading
  	
  	potVal = analogRead(potentiometer); 
  
  	// PROXIMITY SENSOR reading
  	
  	cm = 0.01723 * readUltrasonicDistance();
  
  	// LIGHT SENSOR reading
  	
  	lightSensorVal = analogRead(lightSensor);
  
  
  	// UPDATING VALUE OF LED
  
 	if(onCall == 1){
      	if(cm < 30){
      		ledVal = 0; // OFF - when on call and close to the ear
          	Serial.println("Call on and Close");
      	}else{
          	if(onBrightness == 1){ 
              	// VALUE - when ON call and far from ear and auto adjusting
              	Serial.println("Call on and Far and auto");
            	ledVal = 255 - lightSensorVal * 3;
            }else{
              	// VALUE - when ON call and far from ear and manually adjusting
              	Serial.println("Call on and Far and manually");
            	ledVal = 255 - potVal/4;
            }
      	}
    }else{
      	if(cm < 30){
      		if(onBrightness == 1){
              	// VALUE - when OFF call and close to hand and auto adjusting
              	Serial.println("Call off and Close and auto");
            	ledVal = 255 - lightSensorVal * 3;
            }else{	
              	// VALUE - when OFF call and close to hand and manually adjusting
              	Serial.println("Call off and Close and manually");
            	ledVal = 255 - potVal/4;
            }
      	}else{
          	Serial.println("Call off and Far");
      		ledVal = 0; // OFF - when NOT on call and far away from hand
      	}	
    }
  
  	// UPDATING VALUES
  	analogWrite(ledPin, ledVal);
  	lastCallState = readingCall;
  	lastBrightnessState = readingBrightness;
}
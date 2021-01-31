int pin = 13; // variable for LED output pin
int button1 = 7; // variable for first button input pin
int button2 = 6; // variable for second button input pin

int ledState = LOW; // variable for current LED state, can be set prior to run
int buttonState1, buttonState2; // variables for current button reading
int lastButtonState1 = LOW; // variables for last know button reading, can be set prior to run
int lastButtonState2 = LOW; 

unsigned long lastDebounceTime = 0; //last time the pin was toggled
unsigned long debounceDelay = 10; //the debounce time, can be set prior to run

void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(pin, OUTPUT);
  digitalWrite(pin, ledState);
}

void loop()
{
  // take the reading of buttons and store to local variables
  int reading1 = digitalRead(button1);
  int reading2 = digitalRead(button2);
  
  // check either first or second button readings are not equal to the last, if not equal - set the 
  // last debounce time to current millis time
  if(lastButtonState1 != reading1 || lastButtonState2 != reading2){
  	lastDebounceTime = millis();
  }
  
  // if the difference between current millis time and last debounce time is more than debounce delay time set above
  // it means enough time have passed after last button press and it is not bounce
  if(millis() - lastDebounceTime > debounceDelay){
    // if either first or second button are no equal to the current button reading => set them to the readings 
    // and if it is in HIGH state - change current LED state variable
    if(reading1 != buttonState1){
    	buttonState1 = reading1;
      	if(buttonState1 == HIGH){
      		ledState = !ledState;
        }
    }else if(reading2 != buttonState2){
    	buttonState2 = reading2;
      	if(buttonState2 == HIGH){
      		ledState = !ledState;
        }
    }
  }
  // set new LED state
  digitalWrite(pin, ledState);
  // store current readings to the last button state variable to use in the next loop
  lastButtonState1 = reading1;
  lastButtonState2 = reading2;
  
}
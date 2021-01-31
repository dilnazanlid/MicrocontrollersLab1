int red = 13; // store pin for red LED
int yellow = 12; // store pin for yellow LED
int green = 11; // store pin for green LED


void setup()
{
  pinMode(red, OUTPUT);   // set LED pins to output mode
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  digitalWrite(red, HIGH);  
  delay(4000); 
  digitalWrite(red, LOW); // turning on the red LED for 4 seconds and then turning off
  digitalWrite(yellow, HIGH);
  delay(1500);
  digitalWrite(yellow, LOW); // turning on the yellow LED for 1.5 seconds and then turning off
  digitalWrite(green, HIGH);
  delay(5000);
  digitalWrite(green, LOW); // turning on the green LED for 5 seconds and then turning off
  digitalWrite(yellow, HIGH);
  delay(1500);
  digitalWrite(yellow, LOW); // turning on the yelloe LED for 1.5 seconds and then turning off
}
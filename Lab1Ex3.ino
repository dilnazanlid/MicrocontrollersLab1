int r1 = 13, y1 = 12, g1 = 11, r2 = 10, y2 = 9, g2 = 8; //storing the pins of red, yellow and green LEDs into variables
int yellowTime = 1500, redgreenTime = 4000; // storing the time for each LED being turned on

void setup()
{
  pinMode(r1, OUTPUT); // set all LED pins for output mode
  pinMode(y1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(g2, OUTPUT);
}

void loop()
{
  // at first all LEDs are off
  digitalWrite(r1, HIGH); //  turning on the RED light for west-east side
  digitalWrite(g2, HIGH); //  and green for south-north side
  delay(greenTime);       
  digitalWrite(g2, LOW);  // turning off green for south-north
  digitalWrite(y2, HIGH); 
  delay(yellowTime);
  digitalWrite(r1, LOW); 
  digitalWrite(y2, LOW); 
  digitalWrite(g1, HIGH); // switching on red for south-north and green for west-east 
  digitalWrite(r2, HIGH); // while all other LEDs are off
  delay(greenTime);
  digitalWrite(g1, LOW); // turning off green for west-east
  digitalWrite(y1, HIGH); // and turning on yellow
  delay(yellowTime);
  digitalWrite(r2, LOW); // turning everything off
  digitalWrite(y1, LOW);
	// start again
}
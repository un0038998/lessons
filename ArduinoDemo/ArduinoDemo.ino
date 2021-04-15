// the setup function runs once when you press reset or power the board
void setup() 
{
  // initialize digital pin D2 as an output.
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() 
{
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);             // wait for a second
  digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);             // wait for a second
  
  Serial.println("Please subscribe to 'hash include electronics'");  
}

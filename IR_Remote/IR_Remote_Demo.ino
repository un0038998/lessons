#include <IRremote.h>

#define RECV_PIN 2
#define OUT_PIN 3

IRrecv irrecv(RECV_PIN);

int outputValue = HIGH;
decode_results results;

void setup()
{
  pinMode(OUT_PIN,OUTPUT);
  digitalWrite(OUT_PIN, outputValue);
  irrecv.enableIRIn(); // Start the receiver
}


void loop() 
{
  if (irrecv.decode(&results)) 
  {
    if (results.value == 0xFF38C7) //0xFF38C7 //0x57E3E817
    {
      outputValue = !outputValue;
      digitalWrite(OUT_PIN, outputValue);
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

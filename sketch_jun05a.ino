//arduino code for touch controlled light based on capacitive sensing library

#include <CapacitiveSensor.h>

CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4); // 1M resistor between pins 2 & 4, pin 4 is sensor pin, add a wire and or foil

int in = 2; 
int out = 13;  
int state = HIGH;  
int r;           
int p = LOW;
long time = 0;       
long debounce = 200;
void setup()
{
  pinMode(13, INPUT);
  pinMode(8, OUTPUT);
}
void loop()                    
{
 
  r = digitalRead(13);
  if (r == HIGH && p == LOW && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else 
      state = HIGH;
    time = millis();    
  }
  digitalWrite(8, state);
  p = r;
}

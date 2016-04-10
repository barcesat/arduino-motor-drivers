#include <Potentiometer.h>
 
Potentiometer potentiometer = Potentiometer(2); //a Potentiometer at analog in 2
 
#define stepPin 4
#define dirPin 5
 
const int buttonPin = 9;
int buttonState = 0;
 
void setup()
{
  pinMode(buttonPin, INPUT); // Switch
 
  pinMode(stepPin, OUTPUT); //stepper pin
  pinMode(dirPin, OUTPUT);  //direction pin
 
  digitalWrite(dirPin, HIGH); //sets the direction one way
  digitalWrite(stepPin, LOW); //starts the steppin'
}
 
void loop()
{
  //this is the simplest version, just steps high to low
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(10 + potentiometer.getValue());
  digitalWrite(stepPin, LOW);
  delayMicroseconds(10 + potentiometer.getValue());
 
  //then checks to see if there is a change in the button
  //if the button in pressed, then the electricity is now going through the resistor
  //and the LED, which changes the digital read.
  //try out different resistors if the one listed doesn't function properly
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {    
    digitalWrite(dirPin, HIGH);
  }else{
    digitalWrite(dirPin, LOW);
  }
}

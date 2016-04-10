
#include <Stepper.h>

// change this to the number of steps on your motor

const int stepsPerRevolution = 400;//225;  
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(stepsPerRevolution, 8, 9, 10, 11);
const int en1 = 12;     // sensor minimum
const int en2 = 7;     // sensor minimum
// the previous reading from the analog input
//int previous = 0;
int inByte = 0;         // incoming serial byte

void setup(){
 pinMode(en1, OUTPUT);
 pinMode(en2, OUTPUT); 
  digitalWrite(en1, LOW);
  digitalWrite(en2, LOW);  
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(80);
  Serial.begin(9600); // initialize serial communication @ 9600 baud:
}

void loop()
{
  // get the sensor value
 // int val = analogRead(0);
if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
  // move a number of steps equal to the change in the
  // sensor reading
  if (inByte == 108){ // l
  digitalWrite(en1, HIGH);
  digitalWrite(en2, HIGH);
  Serial.println("clockwise");
  stepper.step(stepsPerRevolution*5);
  }
  else if (inByte == 114){ // r
  digitalWrite(en1, HIGH);
  digitalWrite(en2, HIGH);
  Serial.println("c-clockwise");
  stepper.step(-stepsPerRevolution*5);
  }
  //stepper.step(val - previous);
}
  // remember the previous value of the sensor
  //previous = val;
}

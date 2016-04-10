#include <AccelStepper.h>

// Defaults to AccelStepper::DRIVER (2 pins) on DIR=pin 8 STEP=pin 9
AccelStepper stepper(1,9,8); 

int speedset;
int accelset;
boolean dir;

void setup()
{ 
  Serial.begin(9600);
  // Change these to suit your stepper if you want
  stepper.setCurrentPosition(1400); //start position
  
speedset = analogRead(A0);
      accelset = map(speedset, 1000, 6000, 500, 6000);
      speedset = map(speedset, 0, 1023, 1000, 10000);
      
      stepper.setAcceleration(accelset);
      stepper.setMaxSpeed(speedset);
  stepper.moveTo(-stepper.currentPosition());
  dir = 1;
  stepper.run();
}

void loop()
{
    /*speedset = analogRead(A0);
    if (speedset != speedset_old) speedset_old = speedset;
    
    speed = map(speedset_old, 0, 1023, 1000, 6000);
    accelset = map(speedset_old, 1000, 6000, 500, 2000);
*/
    Serial.print(dir);
    Serial.print(" ");
    Serial.print(speedset);
    Serial.print(" ");
    Serial.print(accelset);
    Serial.print(" ");
    Serial.print(stepper.currentPosition());
    Serial.print(" ");
    Serial.println(stepper.speed());
    // If at the end of travel go to the other end

    /*if (dir){
      Serial.println("fast");
      stepper.setMaxSpeed(speedset);
      stepper.setAcceleration(2000);
      }
      else //if (0 > stepper.currentPosition() > -1200){
      {
        Serial.println("slow");
        stepper.setMaxSpeed(1000);
      //stepper.setAcceleration(500);
      }
      */

      
    // Serial.println(stepper.distanceToGo());
    if (stepper.distanceToGo() == 0){
      stepper.stop();
      speedset = analogRead(A0);
      accelset = map(speedset, 0, 1023, 500, 6000);
      speedset = map(speedset, 0, 1023, 1000, 10000);
      
      stepper.setMaxSpeed(speedset);
      stepper.setAcceleration(accelset);
      stepper.moveTo(-stepper.currentPosition());
      dir = !dir;
    }
    stepper.run();
}

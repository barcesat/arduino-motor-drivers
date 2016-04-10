#include <AccelStepper.h>

// Defaults to AccelStepper::DRIVER (2 pins) on DIR=pin 8 STEP=pin 9
AccelStepper stepper(1,9,8); 

void setup()
{ 
  Serial.begin(9600);
  // Change these to suit your stepper if you want
  stepper.setCurrentPosition(1200); //start position
  
  stepper.setMaxSpeed(2000);
  stepper.setAcceleration(500);
  stepper.moveTo(-1200);
  
  
}

void loop()
{
  
    Serial.print(stepper.currentPosition());
    Serial.print(" ");
    Serial.println(stepper.speed());
    // If at the end of travel go to the other end

    if (0 < stepper.currentPosition() &&  stepper.currentPosition() < 1200){
      Serial.println("fast");
      stepper.setMaxSpeed(6000);
      stepper.setAcceleration(2000);
      }
      else //if (0 > stepper.currentPosition() > -1200){
      {
        Serial.println("slow");
        stepper.setMaxSpeed(1000);
      //stepper.setAcceleration(500);
      }
      
    if (stepper.distanceToGo() == 0){
      
      
      
      stepper.moveTo(-stepper.currentPosition());
      
    }
    stepper.run();
}

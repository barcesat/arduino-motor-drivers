// Bounce.pde
// -*- mode: C++ -*-
//
// Make a single stepper bounce from one limit to another
//
// Copyright (C) 2012 Mike McCauley
// $Id: Random.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>
/*
// The main purpose of this class is to override setOutputPins to work with BigEasy Driver
class AFMotorShield : public AccelStepper
{
  public:
  AFMotorShield(uint8_t interface = AccelStepper::DRIVER, uint8_t pin1 = 9, uint8_t pin2 = 8); 
  virtual void   setOutputPins(uint8_t mask);
};
*/
// Define a stepper and the pins it will use
AccelStepper stepper(1,9,8); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

void setup()
{  
  // Change these to suit your stepper if you want
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  stepper.moveTo(1200);
}

void loop()
{
    // If at the end of travel go to the other end
    if (stepper.distanceToGo() == 0)
      stepper.moveTo(-stepper.currentPosition());

    stepper.run();
}

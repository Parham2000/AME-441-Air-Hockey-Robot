// Include the AccelStepper library:

#include <AccelStepper.h>

// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin1 10
#define stepPin1 9
#define dirPin2 10
#define stepPin2 9
#define motorInterfaceType 1

// Create a new instance of the AccelStepper class:
AccelStepper stepper1 = AccelStepper(motorInterfaceType, stepPin1, dirPin1);
AccelStepper stepper2 = AccelStepper(motorInterfaceType, stepPin2, dirPin2);

void setup() {
  // Set the maximum speed and acceleration:
  stepper1.setMaxSpeed(5000);
  stepper1.setAcceleration(500);
  //stepper1.setSpeed(200);
  //stepper1.setSpeed(1500);

}

void loop() {
  //stepper1.runSpeed();
  stepper1.moveTo(50000);
  while (stepper1.distanceToGo() != 0) 
  {  
    stepper1.run();
  }
}

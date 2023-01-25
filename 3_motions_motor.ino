
 #include <AccelStepper.h>
 
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 36
#define stepPin 38
#define motorInterfaceType 1
#define pin 48
#define pin1 46
 
// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
 
void setup() {
  // Set the maximum speed in steps per second:
  stepper.setMaxSpeed(2000);
  pinMode(pin,INPUT);
   pinMode(pin1,INPUT);
}
 
void loop() 
{ 
  int buttonstate4=digitalRead(pin);
  int buttonstate5=digitalRead(pin1);
  
  if(buttonstate4==HIGH)
  {
  // Set the current position to 0:
  stepper.setCurrentPosition(0);
 
  // Run the motor forward at 200 steps/second until the motor reaches 400 steps (2 revolutions):
  while(stepper.currentPosition() != 7000)
  {
    stepper.setSpeed(1000);
    stepper.runSpeed();
  }
 
  delay(1000);
  }
  else if(buttonstate5==HIGH)
  {
  // Reset the position to 0:
  stepper.setCurrentPosition(0);
 
  // Run the motor backwards at 600 steps/second until the motor reaches -200 steps (1 revolution):
  while(stepper.currentPosition() != -5000) 
  {
    stepper.setSpeed(-1000);
    stepper.runSpeed();
  }
 
  delay(1000);
  }
 
  
}

/*
 This a program for 28BYJ-48 Stepper's shaft alignment.
 It was used in such situation:
 You have fixed the Stepper in your project and operated it, while 
 there is a power-down unintended or a wrong operation, the Stepper's
 shaft stopped in an unintended position, and when power on again, it 
 runs from the new but unwanted origin.

 The program used in this way: 
 Download it into UNO board, and press the
 "RESET" button each time for 10 degree, or click the "Upload" button in
 Arduino IDE each for 10 degree.
 If the direction is reverted, comment the line with "::Backward", uncomment
 the line with "::Forward".

 Author:MQ
 E-mail:mian.qi@hotmail.com
 May.6, 2021 
 */

#include <StepperControl.h>

StepperControl control(StepperControl::DefaultStepCount, 4,5,6,7);

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  //control.SetDirection(StepperControl::Forward);
  control.SetDirection(StepperControl::Backward);
  control.SetRotationSpeed(2);
  control.SetStepType(StepperControl::FullStep);

  const uint32_t steps = control.GetStepsFromDegrees(10);
  control.Step(steps);
}

void loop() {
  ;
}

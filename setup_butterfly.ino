#include <TinyStepper_28BYJ_48.h>

// Stepper motor pins
const int MOTOR1_IN1_PIN = 11;
const int MOTOR1_IN2_PIN = 10;
const int MOTOR1_IN3_PIN = 9;
const int MOTOR1_IN4_PIN = 8;

const int MOTOR2_IN1_PIN = 5;
const int MOTOR2_IN2_PIN = 4;
const int MOTOR2_IN3_PIN = 3;
const int MOTOR2_IN4_PIN = 2;


// Create objects for the stepper and ultrasonic sensor
TinyStepper_28BYJ_48 stepper1;
TinyStepper_28BYJ_48 stepper2;

const int STEPS_PER_REVOLUTION = 2048;
int speed = 1000; 

void setup() {
  Serial.begin(115200);
  stepper1.connectToPins(MOTOR1_IN1_PIN, MOTOR1_IN2_PIN, MOTOR1_IN3_PIN, MOTOR1_IN4_PIN);
  stepper2.connectToPins(MOTOR2_IN1_PIN, MOTOR2_IN2_PIN, MOTOR2_IN3_PIN, MOTOR2_IN4_PIN);
}

void loop() {
  // Measure distance from the ultrasonic sensor
  
  stepper1.setSpeedInStepsPerSecond(speed);
  stepper1.setAccelerationInStepsPerSecondPerSecond(512);
  stepper2.setSpeedInStepsPerSecond(speed);
  stepper2.setAccelerationInStepsPerSecondPerSecond(512);


  stepper1.moveRelativeInSteps(2048);
  stepper2.moveRelativeInSteps(2048);
  delay(1000);
  


}

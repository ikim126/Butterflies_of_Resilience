#include <TinyStepper_28BYJ_48.h>
#include <NewPing.h>

// Stepper motor pins
const int MOTOR1_IN1_PIN = 11;
const int MOTOR1_IN2_PIN = 10;
const int MOTOR1_IN3_PIN = 9;
const int MOTOR1_IN4_PIN = 8;

const int MOTOR2_IN1_PIN = 5;
const int MOTOR2_IN2_PIN = 4;
const int MOTOR2_IN3_PIN = 3;
const int MOTOR2_IN4_PIN = 2;


// Ultrasonic sensor pins
const int TRIG_PIN = 6;
const int ECHO_PIN = 7;
const int MAX_DISTANCE = 300; // Maximum distance we want to ping for (in centimeters).

// Create objects for the stepper and ultrasonic sensor
TinyStepper_28BYJ_48 stepper1;
TinyStepper_28BYJ_48 stepper2;

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

const int STEPS_PER_REVOLUTION = 2048;
int speed = 1000; 

void setup() {
  Serial.begin(115200);
  stepper1.connectToPins(MOTOR1_IN1_PIN, MOTOR1_IN2_PIN, MOTOR1_IN3_PIN, MOTOR1_IN4_PIN);
  stepper2.connectToPins(MOTOR2_IN1_PIN, MOTOR2_IN2_PIN, MOTOR2_IN3_PIN, MOTOR2_IN4_PIN);
}

void loop() {
  // Measure distance from the ultrasonic sensor
  unsigned int distance = sonar.ping_cm(); // Send ping, get distance in cm (0 = outside set distance range)

  delay(50); 

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  // // Map the distance to motor speed
  // long speed = map(distance, 0, MAX_DISTANCE, 3000, 300); // Closer objects give higher speed
  // speed = constrain(speed, 300, 3000);  // Constrain the speed to avoid too slow or too fast

  // Move motor based on distance from sensor 
  if (distance <= 50 && distance != 0) {
    speed = 3000;
    Serial.println("fast mode");
  }
  else if (distance <= 100 && distance != 0) {
    speed = 1000;
    Serial.println("medium mode");
  }
  else {
    speed = 300;
    Serial.println("slow mode");
  }
  
  stepper1.setSpeedInStepsPerSecond(speed);
  stepper1.setAccelerationInStepsPerSecondPerSecond(512);
  stepper2.setSpeedInStepsPerSecond(speed);
  stepper2.setAccelerationInStepsPerSecondPerSecond(512);


  stepper1.moveRelativeInSteps(-2048);
  stepper2.moveRelativeInSteps(-2048);
  delay(250);

  stepper1.moveRelativeInSteps(2048);
  stepper2.moveRelativeInSteps(2048);
  delay(250);


}

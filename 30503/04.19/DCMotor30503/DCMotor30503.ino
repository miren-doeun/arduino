#include <AFMotor.h>

#include <SoftwareSerial.h>
AF_DCMotor motor_1(1);
AF_DCMotor motor_4(4);
void setup() {
  // put your setup code here, to run once:
  motor_1.setSpeed(200);
  motor_1.run(RELEASE);
  motor_4.setSpeed(200);
  motor_4.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor_1.run(FORWARD);
  motor_4.run(FORWARD);
  delay(2000);
  motor_1.run(RELEASE);
  motor_4.run(RELEASE);
  delay(1000);
  motor_1.run(BACKWARD);
  motor_4.run(BACKWARD);
  delay(2000);
  motor_1.run(RELEASE);
  motor_4.run(RELEASE);
  delay(1000);
}

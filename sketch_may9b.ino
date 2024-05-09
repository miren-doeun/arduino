#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor_1(1);
AF_DCMotor motor_4(4);
#define BT_RXD A5
#define BT_TXD A4

SoftwareSerial btSerial(BT_TXD, BT_RXD);
int ledR = 6;
int trigPin = A0;

void setup() {
  motor_1.setSpeed(0);
  motor_1.run(RELEASE);
  motor_4.setSpeed(0);
  motor_4.run(RELEASE);
  btSerial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  if (btSerial.available()) {
    char val = btSerial.read();
    if (val == 'f') go_motor(170);
    else if (val == 'b') back_motor(170);
    else if (val == 'r') right_motor(150);
    else if (val == 'l') left_motor(150);
    else if (val == 's') stop_motor();
    else stop_motor();
  }
  
  if (obstacleDetected()) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

void go_motor(uint8_t speedSet) {
  motor_1.setSpeed(speedSet);
  motor_4.setSpeed(speedSet);
  motor_1.run(FORWARD);
  motor_4.run(FORWARD);
}

void back_motor(uint8_t speedSet) {
  motor_1.setSpeed(speedSet);
  motor_4.setSpeed(speedSet);
  motor_1.run(BACKWARD);
  motor_4.run(BACKWARD);
}

void left_motor(uint8_t speedSet) {
  motor_1.setSpeed(speedSet);
  motor_4.setSpeed(speedSet);
  motor_1.run(BACKWARD);
  motor_4.run(FORWARD);
}

void right_motor(uint8_t speedSet) {
  motor_1.setSpeed(speedSet);
  motor_4.setSpeed(speedSet);
  motor_1.run(FORWARD);
  motor_4.run(BACKWARD);
}

void stop_motor() {
  motor_1.run(RELEASE);
  motor_4.run(RELEASE);
}

bool obstacleDetected() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(trigPin, HIGH);
  float distance = ((float)(340 * duration) / 1000) / 2;
  return distance < 300;
}
#include "functions.h"
#include <Arduino.h>

Servo myServo;

int rightDistance;
int leftDistance;

void stop() {
  analogWrite(ena1, 0);
  analogWrite(ena2, 0);
}

void forward() {
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  analogWrite(ena1, 255);

  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
  analogWrite(ena2, 255);
}

void reverse() {
  stop();
  delay(400);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  analogWrite(ena1, 255);

  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
  analogWrite(ena2, 255);
  delay(cm * 60); 
}

int dist() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  return duration * 0.034 / 2;

}

void turnLeft() {
  analogWrite(ena1, 0);

  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
  analogWrite(ena2, 255);

  delay(500);
  stop();
}

void turnRight() {
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  analogWrite(ena1, 255);

  analogWrite(ena2, 0);

  delay(500);
  stop();
}

int servoLeft() {
  myServo.write(180);
  delay(500);
  int ldist = dist();
  delay(100);
  return ldist;
}

int servoRight() {
  myServo.write(10);
  delay(500);
  int rdist = dist();
  delay(100);
  return rdist;
}

void checkDist() {
  int leftDistance = servoLeft();
  delay(900);
  int rightDistance = servoRight();

}


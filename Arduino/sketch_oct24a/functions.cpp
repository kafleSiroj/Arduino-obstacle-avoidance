#include "functions.h"
#include <Arduino.h>

Servo myServo;

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
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  analogWrite(ena1, 255);

  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
  analogWrite(ena2, 255);
  delay(15 * 60); 
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

void servoLeft() {
  myServo.write(180);
}

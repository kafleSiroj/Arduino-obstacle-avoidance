#include "functions.h"
#include <Arduino.h>

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
}

int dist() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  return duration * 0.034 / 2;
}
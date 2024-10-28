#include <Servo.h>
#include "functions.h"

int m1p1 = 2;
int m1p2 = 3;
int ena1 = 1; 
int m2p1 = 5;
int m2p2 = 6;
int ena2 = 4;
int echo = 12;
int trig = 13;
long duration;

Servo myServo;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  myServo.attach(11);
  myServo.write(90);
}



void loop() {
  int distance = dist();
  forward();

  if (distance<20) {
    reverse();
  }
  delay(100);
}


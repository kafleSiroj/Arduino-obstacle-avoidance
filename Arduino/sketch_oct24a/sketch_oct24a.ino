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
int cm = 10;
long duration;
int stopedDist = 0;



void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myServo.attach(11);
}


void loop() {
  int distance = dist();

  if (distance < 10) {

    stopedDist = distance;
    reverse();

  }

  else if (distance>=(stopedDist+10) && distance<=(stopedDist+15)) {
    stop();
    checkDist();  
    delay(400);
  } 
  
  else {
    myServo.write(90);
    forward();
  
  }

  Serial.println(distance);
  delay(100);
}


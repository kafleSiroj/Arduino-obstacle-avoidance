#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <Servo.h>

extern int m1p1;
extern int m1p2;
extern int ena1;
extern int m2p1;
extern int m2p2;
extern int ena2;
extern int echo;
extern int trig;
extern long duration;

extern Servo myServo;

int dist(); 
void stop();
void forward();
void reverse();
void turnRight();
void turnLeft();
void servoRight();
void servoLeft();
#endif

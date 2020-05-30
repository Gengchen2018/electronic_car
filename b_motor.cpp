
#include <Arduino.h>
#include <TimerOne.h>
#include "a_car.h"

double x=0;

void Motor_Init()
{
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
}

void motor(double left , double right)
{
  x=left;
  left=right;
  right=x;
  ////////////////////////左轮方向控制////////////////////////////
  if (left > 0)
  {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  }
  else if (left < 0)
  {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    left = -left;
  }
  else
  {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  }
  ////////////////////////右轮方向控制////////////////////////////
  if (right > 0)
  {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  }
  else if (right < 0)
  {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    right = -right;
  }
  else
  {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  }
  ////////////////////////速度控制////////////////////////////
  analogWrite(PWMA, left*2.55);
  analogWrite(PWMB, right*2.55);
}


#include <Arduino.h>
#include "a_car.h"

void setup()
{
  Serial.begin(9600);
  Motor_Init();
  Servo_Init();
  Track_Sensor_Init();
  Locate_Sensor_Init();
  TSC_Init();
  Servo_Locate_Init();
}

void loop()
{
  leave_home();
  first_assignment();
  second_assignment();
  back_home();
}

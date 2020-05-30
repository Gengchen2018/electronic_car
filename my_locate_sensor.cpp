
#include <Arduino.h>
#include "a_car.h"

int a = 0;
int count = 0;
int zhan[100] = {0};

void become_shenxian()
{
  for(int i=0;i<100;i++)
  {
    zhan[i]=0;
  }
}

void Locate_Sensor_Init()
{
  pinMode(head_sensor, INPUT);
  pinMode(center_sensor, INPUT);
  pinMode(back_sensor, INPUT);
  pinMode(hair_sensor, INPUT);
}

bool locate(int b, int sensor)
{
  if (count == b)
  {
    count = 0;
    return false;
  }
  zhan[a] = digitalRead(sensor);
  a++;
  if (a == 100)a = 0;
  int sm = 0;
  for (int i = 0; i < 100; i++)
  {
    sm += zhan[i];
  }
  if (sm == 50)
  {
    count++;
    if(count%2==0)
    {
      become_shenxian();
    }
  }
  return true;
}



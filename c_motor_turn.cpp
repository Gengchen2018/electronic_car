
#include <Arduino.h>
#include "a_car.h"

void turn_around(int start_direction , int end_direction)
{
  become_shenxian();
  int line = start_direction - end_direction;
  if (line > 4)
  {
    line -= 8;
  }
  if (line < -4)
  {
    line += 8;
  }
  if (line > 0)
  {
    if (line == 1 )
    {
      while (locate( 2, head_sensor))
      {
        motor(-81, 80);
      }
      motor(90, -94);
      delay(30);
      motor(0, 0);
      delay(200);
    }
    else if (line == 3)
    {
      while (locate( 6, head_sensor))
      {
        motor(-78, 65);
      }
      motor(95, -97);
      delay(50);
      motor(0, 0);
      delay(200);
    }
    else if (line == 4)
    {
      while (locate( 4, head_sensor))
      {
        motor(-85, 68);
      }
      become_shenxian();
      while (locate( 4, head_sensor))
      {
        motor(-83, 80);
      }
      motor(85, -88);
      delay(70);
      motor(0, 0);
      delay(200);
    }
    else if (line == 2)
    {
      while (locate( 4, head_sensor))
      {
        motor(-79, 73);
      }
      delay(20);
      motor(90, -94);
      delay(50);
      motor(0, 0);
      delay(200);
    }
  }
  else
  {
    line = -line;
    if (line == 1)
    {
      while (locate( 2, head_sensor))
      {
        motor(79, -75);
      }
      delay(40);
      motor(-90, 90);
      delay(20);
      motor(0, 0);
      delay(200);
    }
    else if (line == 4)
    {
      while (locate( 4, head_sensor))
      {
        motor(79, -77);
      }
      become_shenxian();
      while (locate( 4, head_sensor))
      {
        motor(79, -82);
      }
      delay(15);
      motor(-90, 90);
      delay(50);
      motor(0, 0);
      delay(200);
    }
    else if (line == 2)
    {
      while (locate( 4, head_sensor))
      {
        motor(89, -94);
      }
      delay(3);
      motor(-90, 95);
      delay(74);
      motor(0, 0);
      delay(200);
    }
    else if (line == 3)
    {
      while (locate( 6, head_sensor))
      {
        motor(79, -80);
      }
      motor(-90, 90);
      delay(33);
      motor(0, 0);
      delay(200);
    }
  }
  motor(0, 0);
  delay(200);
}
